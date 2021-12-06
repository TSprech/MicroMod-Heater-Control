#include <array>
#include <cstdint>

#include "MicroMod_Pins_Teensy_Processor.hpp"
#include "SdFat.h"
#include "sdios.h"  // Using fstream for ease of use as well as the vast space of the Teensy processor
// Seperator for Arduino header
#include <Arduino.h>

// // void setup() {
// //   pinMode(spi_sck, OUTPUT);
// // }

// // void loop() {
// //   digitalWrite(spi_sck, HIGH);
// //   delay(250);
// //   digitalWrite(spi_sck, LOW);
// //   delay(250);
// // }

#define SERIALOUT Serial

const auto sd_cs_pin = g_4;  // d_1 for single, g_4 for double

const uint32_t buffer_size = 100;  // 32 KB buffer
std::array<char, buffer_size> sd_buffer = {0};

SdFat sd_card;

void setup() {
  SERIALOUT.begin(9600);
  while (!SERIALOUT)
    ;
  if (!sd_card.begin(sd_cs_pin, SD_SCK_MHZ(50)))
    SERIALOUT.print("Error setting up card\n");

  ifstream input_data("/DIR/TEST.TXT");
  SERIALOUT.printf("File open successfully\n");

  input_data.getline(sd_buffer.data(), sd_buffer.size(), '\n');
  SERIALOUT.write(sd_buffer.data(), 20);

  ofstream output_data("NEW.TXT");
  if (output_data.is_open()) {
    output_data << "Arduino wrote this!\n";
    output_data.close();
    SERIALOUT.print("Write success!\n");
  }
}

void loop() {
}