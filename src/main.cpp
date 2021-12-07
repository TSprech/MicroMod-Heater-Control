#include <algorithm>
#include <array>
#include <cstdint>
#include <vector>

#include "HeaterSettings_generated.h"
#include "MicroMod_Pins_Teensy_Processor.hpp"
#include "SdFat.h"
#include "flatbuffers/flatbuffers.h"
#include "sdios.h"  // Using fstream for ease of use as well as the vast space of the Teensy processor
// Seperator for Arduino header
#include <Arduino.h>

#define SERIALOUT Serial

const auto sd_cs_pin = g_4;  // d_1 for single, g_4 for double

const uint32_t buffer_size = 200;  // 200B buffer
std::array<char, buffer_size> sd_buffer = {0};

SdFat sd_card;

void setup() {
  SERIALOUT.begin(9600);
  while (!SERIALOUT)
    ;
  if (!sd_card.begin(sd_cs_pin, SD_SCK_MHZ(50))) // Start the SD card and increase communication speed to 50MHz (decrease if errors)
    SERIALOUT.print("Error setting up card\n");

  flatbuffers::FlatBufferBuilder builder(40);
  auto output_buffer = HeaterSettings::CreateHeaterSettings(builder, 130, true); // Create a new heater settings with the builder
  builder.Finish(output_buffer);
  auto buff_ptr = builder.GetBufferPointer(); // Get a pointer to access the Flatbuffer data

  ofstream output_data("HeaterSettings.txt"); // Open or create a new file
  if (output_data.is_open()) { // Check that it is open
    for (size_t offset = 0; offset < builder.GetSize(); ++offset) { // Go through each byte of the builder's buffer that has relevent data
      auto current_value = *(buff_ptr + offset); // Offset the point appropriately to access the next byte
      SERIALOUT.print(current_value, HEX); // Display the new byte
      SERIALOUT.print(' ');
      output_data << current_value; // Write the byte to the file
    }
  }
  output_data << '\n'; // TODO: Use EOF?
  output_data.close(); // Finish writing
  SERIALOUT.print("\n");

  ifstream input_buffer("HeaterSettings.txt"); // Open the created file
  // TODO: Related to EOF, see if that can be used to avoid having to insert newline
  input_buffer.getline(sd_buffer.data(), sd_buffer.size(), '\n'); // Pull the Flatbuffer raw data from the file
  auto input_data = HeaterSettings::GetHeaterSettings(sd_buffer.data()); // Take the raw data and make it accessible as heater setting data
  SERIALOUT.printf("\nSet point: %i", input_data->set_point()); // Print the setpoint (should be 130)
  SERIALOUT.printf("\nLights: %s", input_data->lights() ? "True" : "False"); // Print the boolean lights (should be true)
}

void loop() {
}