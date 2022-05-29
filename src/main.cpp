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

#include "Menus.hpp"

#define SERIALOUT Serial

const pin_t heater_drive_en = F1_G3;
const pin_t heater_drive_pwm = F1_G2;

void setup() {
  pinMode(heater_drive_en, OUTPUT);
  pinMode(heater_drive_pwm, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  
  Serial.begin(115200);
  // while(!Serial);
  nav.idleTask=idle;//point a function to be used when menu is suspended

  keys.begin();

  SPI.begin();
  gfx.begin();
  gfx.clearDisplay();
  gfx.println(F("Menu 4.x test on GFX"));
  gfx.setContrast(50);
  gfx.clearDisplay();
  gfx.display(); // show splashscreen
}

void loop() {
  //or on a need to draw basis:
  nav.doInput();
  if (nav.changed(0)) {//only draw if changed
    nav.doOutput();
    gfx.display();
  }

  // digitalWrite(LED_BUILTIN, heaters_enabled ? HIGH : LOW); // When using built in it messes up the menu display after selecting on off a couple times?

  delay(100);//simulate a delay when other tasks are done
}