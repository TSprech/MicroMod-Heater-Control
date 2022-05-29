#ifndef MICROMOD_PINS_TEENSY_PROCESSOR_HPP
#define MICROMOD_PINS_TEENSY_PROCESSOR_HPP

#include <cstdint>

using pin_t = uint8_t;

enum Function_Pins : pin_t {
  // SCL = 19, // SCL
  // SDA = 18, // SDA
  INT = 29, // I2C INT
  SCLK = 13, // SCK
  COPI = 11, // SDO
  CIPO = 12, // SDI
  SD_CS = 44, // G4
  F0_A0 = 14, // A0
  F1_A1 = 15, // 1
  F0_G0 = 4, // D0
  F1_G0 = 5, // D1
  F0_G1 = 10, // CS0
  F1_G1 = 38, // CS1
  F0_G2 = 3, // PWM0
  F1_G2 = 2, // PWM1
  F0_G3 = 40, // G0
  F1_G3 = 45, // G5
  F0_G4 = 41, // G1
  F1_G4 = 6, // G6
  F0_G5 = 42, // G2
  F1_G5 = 9, // G7
  F0_G6 = 43, // G3
  F1_G6 = 6, // G8
  F0_G7 = 44, // G4
  F1_G7 = 32, // G9
};

// enum Named_Pins : pin_t
// {
//   // cipo = 12,
//   // copi = 11,
//   // sck = 13,
//   // cs = 10,
//   // aud_out = 7,
//   // aud_in = 8,
//   // aud_lrclk = 20,
//   // aud_bclk = 21,
//   // a_0 = 14,
//   // a_1 = 15,
//   // d_0 = 4,
//   // d_1 = 5,
//   // pwm_0 = 3,
//   // pwm_1 = 2,
//   // g_0 = 15,
//   // g_1 = 25,
//   // g_2 = 26,
//   // g_3 = 17,
//   // g_4 = 16,
//   // g_5 = 32,
//   // g_6 = 33,
//   // a_2 = 16,
//   // a_3 = 17,
//   // a_4 = 18,
//   // a_5 = 19,
//   // a_6 = 20,
//   // a_7 = 21,
//   // a_8 = 22,
//   // a_9 = 23,
//   // a_10 = 24,
//   // a_11 = 25,
//   // a_12 = 26,
//   // a_13 = 27

//   // Bottom pins
//   sdio_data_3 = 39,
//   sdio_data_2 = 38,
//   sdio_data_1 = 34,
//   sdio_data_0 = 35,
//   sdio_cmd = 37,
//   sdio_sck = 36,
//   aud_mclk = 23,
//   aud_out = 7,
//   aud_in = 8,
//   aud_lrclk = 20,
//   aud_bclk = 21,
//   g_4 = 44,
//   g_3 = 43,
//   g_2 = 42,
//   g_1 = 41,
//   g_0 = 40,
//   a_1 = 15,
//   a_0 = 14,
//   pwm_0 = 3,
//   uart_tx_2 = 17,
//   uart_rx_2 = 16,
//   d_1 = 5,
//   i2c_int = 29,
//   i2c_scl = 19,
//   i2c_sda = 18,
//   d_0 = 4,
//   g_11 = 27,
//   en_3v3 = 28,

//   // Top pins
//   g_5 = 45,
//   g_6 = 6,
//   g_7 = 9,
//   g_8 = 26,
//   g_9 = 32,
//   g_10 = 33,
//   spi_cipo = 12,
//   spi_copi = 11,
//   spi_sck = 13,
//   spi_cs = 10,
//   i2c_scl_1 = 24,
//   i2c_sda_1 = 25,
//   batt_vin_div_3 = 22,
//   pwm_1 = 2,
//   can_tx = 31,
//   can_rx = 30,
//   uart_rx_1 = 0,
//   uart_tx_1 = 1
// };

// enum Pad_Pins : pin_t
// {
//   // pad_61 = 12,
//   // pad_59 = 11,
//   // pad_57 = 13,
//   // pad_55 = 10,
//   // pad_56 = 7,
//   // pad_54 = 8,
//   // pad_52 = 20,
//   // pad_50 = 21,
//   // pad_34 = 14,
//   // pad_38 = 15,
//   // pad_10 = 4,
//   // pad_18 = 5,
//   // pad_32 = 3,
//   // pad_47 = 2,
//   // pad_40 = 15,
//   // pad_42 = 25,
//   // pad_44 = 26,
//   // pad_46 = 17,
//   // pad_48 = 16,
//   // pad_73 = 32,
//   // pad_71 = 33,
//   // pad_20 = 16,
//   // pad_22 = 17,
//   // pad_12 = 18,
//   // pad_14 = 19,
//   // pad_52 = 20,
//   // pad_50 = 21,
//   // pad_49 = 22,
//   // pad_58 = 23,
//   // pad_53 = 24,
//   // pad_51 = 25,
//   // pad_67 = 26,
//   // pad_8 = 27

//   // Bottom pins
//   pad_70 = 39,
//   pad_68 = 38,
//   pad_66 = 34,
//   pad_64 = 35,
//   pad_62 = 37,
//   pad_60 = 36,
//   pad_58 = 23,
//   pad_56 = 7,
//   pad_54 = 8,
//   pad_52 = 20,
//   pad_50 = 21,
//   pad_48 = 44,
//   pad_46 = 43,
//   pad_44 = 42,
//   pad_42 = 41,
//   pad_40 = 40,
//   pad_38 = 15,
//   pad_34 = 14,
//   pad_32 = 3,
//   pad_22 = 17,
//   pad_20 = 16,
//   pad_18 = 5,
//   pad_16 = 29,
//   pad_14 = 19,
//   pad_12 = 18,
//   pad_10 = 4,
//   pad_8 = 27,
//   pad_4 = 28,

//   // Top pins
//   pad_73 = 45,
//   pad_71 = 6,
//   pad_69 = 9,
//   pad_67 = 26,
//   pad_65 = 32,
//   pad_63 = 33,
//   pad_61 = 12,
//   pad_59 = 11,
//   pad_57 = 13,
//   pad_55 = 10,
//   pad_53 = 24,
//   pad_51 = 25,
//   pad_49 = 22,
//   pad_47 = 2,
//   pad_43 = 31,
//   pad_41 = 30,
//   pad_19 = 0,
//   pad_17 = 1
// };

#endif // MICROMOD_PINS_TEENSY_PROCESSOR_HPP