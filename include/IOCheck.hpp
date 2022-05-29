#ifndef IOCHECK
#define IOCHECK

#include "MicroMod_Pins_Teensy_Processor.hpp"
#include <SPI.h>
#include <Wire.h>
#include "Adafruit_NeoPixel.h"
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>

// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait, Adafruit_NeoPixel& pixels) {
  for(uint16_t i=0; i<pixels.numPixels(); i++) {
    pixels.setPixelColor(i, c);
    pixels.show();
    delay(wait);
  }
}

void NeopixelCheck(Adafruit_NeoPixel& pixels) {
  pixels.begin();
  pixels.setBrightness(50);
  pixels.show(); // Initialize all pixels to 'off'

  colorWipe(pixels.Color(255, 0, 0), 500, pixels); // Red
  colorWipe(pixels.Color(0, 255, 0), 500, pixels); // Green
  colorWipe(pixels.Color(0, 0, 255), 500, pixels); // Blue
  pixels.clear();
  pixels.show();
}

void DisplayCheck(Adafruit_SH1106G& display) {
  display.begin(0, true);
  // Show image buffer on the display hardware.
  // Since the buffer is intialized with an Adafruit splashscreen
  // internally, this will display the splashscreen.
  display.display();
  delay(2000);

  // Clear the buffer.
  display.clearDisplay();

  display.setTextSize(1);
  display.setTextColor(SH110X_WHITE);
  display.setCursor(0, 0);

  for (uint8_t i = 0; i < 168; i++) {
    if (i == '\n') continue;
    display.write(i);
    if ((i > 0) && (i % 21 == 0))
      display.println();
  }
  display.display();
  delay(3000);

  display.clearDisplay();
  display.display();
}

#endif // IOCHECK