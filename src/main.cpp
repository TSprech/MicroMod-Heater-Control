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

const uint32_t buffer_size = 1000;  // 200B buffer
std::array<uint8_t, buffer_size> sd_buffer = {0};

SdFat sd_card;

auto WriteHeaterSettings(flatbuffers::FlatBufferBuilder& builder) -> void {
  auto buff_ptr = builder.GetBufferPointer();  // Get a pointer to access the Flatbuffer data

  ofstream output_data("HeaterSettings.bin");                        // Open or create a new file
  if (output_data.is_open()) {                                       // Check that it is open
    for (size_t offset = 0; offset < builder.GetSize(); ++offset) {  // Go through each byte of the builder's buffer that has relevent data
      auto current_value = *(buff_ptr + offset);                     // Offset the point appropriately to access the next byte
      output_data << current_value;                                  // Write the byte to the file
    }
  }
  output_data.close();  // Finish writing
}

auto WriteHeaterSettings(const uint8_t* buffer) -> void {
  ofstream output_data("HeaterSettings.bin");  // Open or create a new file
  if (output_data.is_open()) {                 // Check that it is open
    // flatbuffers::GetPrefixedSize(buffer) + 30
    for (size_t offset = 0; offset < 80; ++offset) {  // Go through each byte of the builder's buffer that has relevent data
      auto current_value = *(buffer + offset);        // Offset the point appropriately to access the next byte
      output_data << current_value;                   // Write the byte to the file
    }
  }
  output_data.close();  // Finish writing
}

auto ReadHeaterSettings(const HeaterSettings::HeaterSettings* settings) -> void {
  SERIALOUT.printf("\nSet point: %i", settings->set_point());               // Print the setpoint
  SERIALOUT.printf("\nLights: %s", settings->lights() ? "True" : "False");  // Print the boolean lights
  // SERIALOUT.printf("\nLights: %i", settings->lights());  // Print the boolean lights
  SERIALOUT.printf("\nFloat: %f", settings->p_value());  // Print the boolean lights
}

auto PrintRawBytes(const uint8_t* buffer) -> void {
  for (size_t offset = 0; offset < 80; ++offset) {  // Go through each byte of the builder's buffer that has relevent data
    auto current_value = *(buffer + offset);                                               // Offset the point appropriately to access the next byte
    SERIALOUT.print(current_value, HEX);                                                   // Write the byte to the file
    SERIALOUT.print(' ');
  }
  SERIALOUT.print('\n');
}

void setup() {
  /*  SERIALOUT.begin(9600);
  while (!SERIALOUT)
    ;
  if (!sd_card.begin(sd_cs_pin, SD_SCK_MHZ(50)))  // Start the SD card and increase communication speed to 50MHz (decrease if errors)
    SERIALOUT.print("Error setting up card\n");

  flatbuffers::FlatBufferBuilder builder(40);
  auto output_buffer = HeaterSettings::CreateHeaterSettings(builder, true, 20);  // Create a new heater settings with the builder
  builder.FinishSizePrefixed(output_buffer);

  WriteHeaterSettings(builder);

  ifstream input_buffer("HeaterSettings.bin");                                             // Open the created file
  input_buffer.getline(reinterpret_cast<char*>(sd_buffer.data()), sd_buffer.size(), '\n');  // Pull the Flatbuffer raw data from the file
  auto input_data = HeaterSettings::GetSizePrefixedHeaterSettings(sd_buffer.data());       // Take the raw data and make it accessible as heater setting data
  ReadHeaterSettings(input_data);
  SERIALOUT.print("\n1: ");
  PrintRawBytes(sd_buffer.data());

  auto mutable_data = HeaterSettings::GetMutableSizePrefixedHeaterSettings(sd_buffer.data());
  mutable_data->mutate_set_point(64);
  mutable_data->mutate_lights(true);
  mutable_data->mutate_p_value(3.856F);
  SERIALOUT.print("\n2: ");
  PrintRawBytes(sd_buffer.data());
  ReadHeaterSettings(mutable_data);
  WriteHeaterSettings(sd_buffer.data());
  SERIALOUT.print("\n3: ");
  PrintRawBytes(sd_buffer.data());

  // mutable_data->mutate_set_point(128);
  // mutable_data->mutate_lights(false);

  // input_buffer = ifstream("HeaterSettings.bin");                                           // Open the created file
  // input_buffer.getline(reinterpret_cast<char*>(sd_buffer.data()), sd_buffer.size(), '\n');  // Pull the Flatbuffer raw data from the file
  // input_data = HeaterSettings::GetSizePrefixedHeaterSettings(sd_buffer.data());            // Take the raw data and make it accessible as heater setting data
  // ReadHeaterSettings(input_data);

  mutable_data->mutate_set_point(128);
  mutable_data->mutate_lights(false);
  mutable_data->mutate_p_value(8452354.2);

  WriteHeaterSettings(sd_buffer.data());
  input_buffer = ifstream("HeaterSettings.bin");                                           // Open the created file
  input_buffer.getline(reinterpret_cast<char*>(sd_buffer.data()), sd_buffer.size(), '\n');  // Pull the Flatbuffer raw data from the file
  input_data = HeaterSettings::GetSizePrefixedHeaterSettings(sd_buffer.data());            // Take the raw data and make it accessible as heater setting data
  SERIALOUT.print("\n4: ");
  PrintRawBytes(sd_buffer.data());
  ReadHeaterSettings(input_data);*/

  // SERIALOUT.begin(9600);
  // while (!SERIALOUT)
  //   ;
  // if (!sd_card.begin(sd_cs_pin, SD_SCK_MHZ(50)))  // Start the SD card and increase communication speed to 50MHz (decrease if errors)
  //   SERIALOUT.print("Error setting up card\n");

  // flatbuffers::FlatBufferBuilder builder(40);
  // auto output_buffer = HeaterSettings::CreateHeaterSettings(builder, false, 20, 80.225);  // Create a new heater settings with the builder
  // builder.Finish(output_buffer);

  // ofstream output_data("HeaterSettings.bin");                       // Open or create a new file
  // if (output_data.is_open()) {                                      // Check that it is open
  //   for (size_t offset = 0; offset < 80; ++offset) {                // Go through each byte of the builder's buffer that has relevent data
  //     auto current_value = *(builder.GetBufferPointer() + offset);  // Offset the point appropriately to access the next byte
  //     output_data << current_value;                                 // Write the byte to the file
  //   }
  // }
  // output_data.close();  // Finish writing

  // ifstream input_buffer("HeaterSettings.bin");                                             // Open the created file
  // input_buffer.getline(reinterpret_cast<char*>(sd_buffer.data()), sd_buffer.size(), EOF);  // Pull the Flatbuffer raw data from the file
  // auto input_data = HeaterSettings::GetHeaterSettings(sd_buffer.data());       // Take the raw data and make it accessible as heater setting data
  // ReadHeaterSettings(input_data);
  // SERIALOUT.print("\n1: ");
  // PrintRawBytes(sd_buffer.data());



  // std::array<uint8_t, buffer_size> new_sd_buffer = {0};
  // ifstream input_buffer_2("HeaterSettings.bin");                                             // Open the created file
  // input_buffer_2.getline(reinterpret_cast<char*>(new_sd_buffer.data()), new_sd_buffer.size(), EOF);  // Pull the Flatbuffer raw data from the file
  // auto input_data_2 = HeaterSettings::GetMutableHeaterSettings(new_sd_buffer.data());       // Take the raw data and make it accessible as heater setting data
  // ReadHeaterSettings(input_data_2);
  // PrintRawBytes(new_sd_buffer.data());
  // input_data_2->mutate_lights(true);
  // input_data_2->mutate_set_point(128);
  // input_data_2->mutate_p_value(32.3684);

  // ofstream output_data_2("HeaterSettings.bin");                       // Open or create a new file
  // if (output_data_2.is_open()) {                                      // Check that it is open
  //   for (size_t offset = 0; offset < 80; ++offset) {                // Go through each byte of the builder's buffer that has relevent data
  //     auto current_value = *(new_sd_buffer.data() + offset);  // Offset the point appropriately to access the next byte
  //     output_data_2 << current_value;                                 // Write the byte to the file
  //   }
  // }
  // output_data_2.close();  // Finish writing

  // std::array<uint8_t, buffer_size> sd_buffer_3 = {0};
  // ifstream input_buffer_3("HeaterSettings.bin");                                             // Open the created file
  // input_buffer_3.getline(reinterpret_cast<char*>(sd_buffer_3.data()), sd_buffer_3.size(), EOF);  // Pull the Flatbuffer raw data from the file
  // auto input_data_3 = HeaterSettings::GetHeaterSettings(sd_buffer_3.data());       // Take the raw data and make it accessible as heater setting data
  // ReadHeaterSettings(input_data_3);
  // PrintRawBytes(sd_buffer.data());




  SERIALOUT.begin(9600);
  while (!SERIALOUT)
    ;
  if (!sd_card.begin(sd_cs_pin, SD_SCK_MHZ(50)))  // Start the SD card and increase communication speed to 50MHz (decrease if errors)
    SERIALOUT.print("Error setting up card\n");

  flatbuffers::FlatBufferBuilder builder(40);
  builder.ForceDefaults(true);
  auto output_buffer = HeaterSettings::CreateHeaterSettings(builder, false, 20, 80.225);  // Create a new heater settings with the builder
  builder.Finish(output_buffer);

  ofstream output_data("HeaterSettings.bin");                       // Open or create a new file
  if (output_data.is_open()) {                                      // Check that it is open
    for (size_t offset = 0; offset < 80; ++offset) {                // Go through each byte of the builder's buffer that has relevent data
      auto current_value = *(builder.GetBufferPointer() + offset);  // Offset the point appropriately to access the next byte
      output_data << current_value;                                 // Write the byte to the file
    }
  }
  output_data.close();  // Finish writing

  ifstream input_buffer("HeaterSettings.bin");                                             // Open the created file
  input_buffer.getline(reinterpret_cast<char*>(sd_buffer.data()), sd_buffer.size(), EOF);  // Pull the Flatbuffer raw data from the file
  auto input_data = HeaterSettings::GetHeaterSettings(sd_buffer.data());       // Take the raw data and make it accessible as heater setting data
  ReadHeaterSettings(input_data);
  SERIALOUT.print("\n1: ");
  PrintRawBytes(sd_buffer.data());



  std::array<uint8_t, buffer_size> new_sd_buffer = {0};
  ifstream input_buffer_2("HeaterSettings.bin");                                             // Open the created file
  input_buffer_2.getline(reinterpret_cast<char*>(new_sd_buffer.data()), new_sd_buffer.size(), EOF);  // Pull the Flatbuffer raw data from the file
  auto input_data_2 = HeaterSettings::GetMutableHeaterSettings(new_sd_buffer.data());       // Take the raw data and make it accessible as heater setting data
  ReadHeaterSettings(input_data_2);
  PrintRawBytes(new_sd_buffer.data());
  input_data_2->mutate_lights(true);
  input_data_2->mutate_set_point(128);
  input_data_2->mutate_p_value(32.3684);

  ofstream output_data_2("HeaterSettings.bin");                       // Open or create a new file
  if (output_data_2.is_open()) {                                      // Check that it is open
    for (size_t offset = 0; offset < 80; ++offset) {                // Go through each byte of the builder's buffer that has relevent data
      auto current_value = *(new_sd_buffer.data() + offset);  // Offset the point appropriately to access the next byte
      output_data_2 << current_value;                                 // Write the byte to the file
    }
  }
  output_data_2.close();  // Finish writing

  std::array<uint8_t, buffer_size> sd_buffer_3 = {0};
  ifstream input_buffer_3("HeaterSettings.bin");                                             // Open the created file
  input_buffer_3.getline(reinterpret_cast<char*>(sd_buffer_3.data()), sd_buffer_3.size(), EOF);  // Pull the Flatbuffer raw data from the file
  auto input_data_3 = HeaterSettings::GetHeaterSettings(sd_buffer_3.data());       // Take the raw data and make it accessible as heater setting data
  ReadHeaterSettings(input_data_3);
  PrintRawBytes(sd_buffer.data());
}

void loop() {
}