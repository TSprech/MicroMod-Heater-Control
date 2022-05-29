#include <algorithm>
#include <array>
#include <cstdint>
#include <vector>

#include "HeaterSettings_generated.h"
#include "IOCheck.hpp"
#include "MicroMod_Pins_Teensy_Processor.hpp"
#include "SdFat.h"
#include "flatbuffers/flatbuffers.h"
#include "sdios.h"  // Using fstream for ease of use as well as the vast space of the Teensy processor
// Seperator for Arduino header
#include <Arduino.h>

#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>

#define SERIALOUT Serial

#include <menu.h>
#include <menuIO/keyIn.h>
#include <menuIO/chainStream.h>
#include <menuIO/serialOut.h>
#include <menuIO/adafruitGfxOut.h>
#include <menuIO/serialIn.h>

using namespace Menu;

#define LEDPIN LED_BUILTIN

Adafruit_SH1106G gfx(128, 64, COPI, SCLK, F0_G2, F0_G0, F0_G1);

//Navigate buttons
#define BTN_SEL     F0_G5                 // Select button
#define BTN_UP      F0_G4                 // Up Button
#define BTN_DOWN    F0_G3                 // Down Button
#define BTN_ESC     F0_G6                 // Exit Button

#define TOTAL_NAV_BUTTONS 4       // Total Navigation Button used

keyMap joystickBtn_map[] = {
  { -BTN_SEL, defaultNavCodes[enterCmd].ch} ,
  { -BTN_UP, defaultNavCodes[upCmd].ch} ,
  { -BTN_DOWN, defaultNavCodes[downCmd].ch}  ,
  { -BTN_ESC, defaultNavCodes[escCmd].ch}  ,
};
keyIn<TOTAL_NAV_BUTTONS> keys(joystickBtn_map);//the input driver

result showEvent(eventMask e,navNode& nav,prompt& item) {
  Serial.print(F("event:"));
  Serial.print(e);
  return proceed;
}

int temperature=10;
int ledCtrl=LOW;

result alert(menuOut& o,idleEvent e);
result doAlert(eventMask e, prompt &item);

bool heaters_enabled = false;

TOGGLE(heaters_enabled, SetHeaters, "Heaters: ", doNothing, noEvent, noStyle,
  VALUE("Enabled",true,doNothing,noEvent),
  VALUE("Disabled",false,doNothing,noEvent)
);

const char* constMEM hexDigit MEMMODE="0123456789ABCDEF";
const char* constMEM hexNr[] MEMMODE={"0","x",hexDigit,hexDigit};
char buf1[]="0x11";

MENU(mainMenu,"Main menu",doNothing,noEvent,wrapStyle
  ,FIELD(temperature, "Set:", "C", 0, 200, 10, 1, doNothing, noEvent, wrapStyle)
  ,SUBMENU(SetHeaters)
  ,EXIT("<Back")
);

// define menu colors --------------------------------------------------------
//  {{disabled normal,disabled selected},{enabled normal,enabled selected, enabled editing}}
//monochromatic color table
const colorDef<uint16_t> colors[6] MEMMODE={
  {{SH110X_BLACK,SH110X_WHITE},{SH110X_BLACK,SH110X_WHITE,SH110X_WHITE}},//bgColor
  {{SH110X_WHITE,SH110X_BLACK},{SH110X_WHITE,SH110X_BLACK,SH110X_BLACK}},//fgColor
  {{SH110X_WHITE,SH110X_BLACK},{SH110X_WHITE,SH110X_BLACK,SH110X_BLACK}},//valColor
  {{SH110X_WHITE,SH110X_BLACK},{SH110X_WHITE,SH110X_BLACK,SH110X_BLACK}},//unitColor
  {{SH110X_WHITE,SH110X_BLACK},{SH110X_BLACK,SH110X_BLACK,SH110X_BLACK}},//cursorColor
  {{SH110X_WHITE,SH110X_BLACK},{SH110X_BLACK,SH110X_WHITE,SH110X_WHITE}},//titleColor
};

#define gfxWidth 128
#define gfxHeight 64
#define fontX 6
//5
#define fontY 9
#define MAX_DEPTH 2

serialIn serial(Serial);
MENU_INPUTS(in,&keys,&serial);

#define MAX_DEPTH 2
#define textScale 1
MENU_OUTPUTS(out,MAX_DEPTH
  ,ADAGFX_OUT(gfx,colors,fontX,fontY,{0,0,gfxWidth/fontX,gfxHeight/fontY})
  ,SERIAL_OUT(Serial)
);

NAVROOT(nav,mainMenu,MAX_DEPTH,in,out);

result alert(menuOut& o,idleEvent e) {
  if (e==idling) {
    o.setCursor(0,0);
    o.print(F("alert test"));
    o.setCursor(0,1);
    o.print(F("press [select]"));
    o.setCursor(0,2);
    o.print(F("to continue..."));
  }
  return proceed;
}

result doAlert(eventMask e, prompt &item) {
  nav.idleOn(alert);
  return proceed;
}

//when menu is suspended
result idle(menuOut& o,idleEvent e) {
  o.setCursor(0,0);
  o.print(F("suspended..."));
  o.setCursor(0,1);
  o.print(F("press [select]"));
  o.setCursor(0,2);
  o.print(F("to continue"));
  return proceed;
}

void setup() {
  pinMode(LEDPIN,OUTPUT);
  Serial.begin(9600);
  // while(!Serial);
  Serial.println(F("menu 4.x test"));
  Serial.flush();
  nav.idleTask=idle;//point a function to be used when menu is suspended

  keys.begin();

  SPI.begin();
  gfx.begin();
  gfx.clearDisplay();
  gfx.println(F("Menu 4.x test on GFX"));
  gfx.setContrast(50);
  gfx.display(); // show splashscreen
  delay(2000);
  gfx.clearDisplay();
  gfx.display(); // show splashscreen
  // gfx.drawRect(0, 0, 84, 48, 1);
}

void loop() {
  //or on a need to draw basis:
  nav.doInput();
  if (nav.changed(0)) {//only draw if changed
    nav.doOutput();
    gfx.display();
  }

  delay(100);//simulate a delay when other tasks are done
}