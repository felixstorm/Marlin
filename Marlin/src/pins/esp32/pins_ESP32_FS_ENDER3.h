/**
 * Marlin 3D Printer Firmware
 * Copyright (C) 2019 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (C) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

/**
 * Espressif ESP32 (Tensilica Xtensa LX6) pin assignments
 */

#ifndef ARDUINO_ARCH_ESP32
  #error "Oops! Select an ESP32 board in 'Tools > Board.'"
#endif

#define BOARD_INFO_NAME "ESP32 FS Ender 3 r3"

//
// I2S (steppers & other output-only pins)
//
#define I2S_STEPPER_STREAM
#define I2S_WS              17
#define I2S_BCK             22
#define I2S_DATA            21

//
// Limit Switches
//
#define X_MIN_PIN           34
#define Y_MIN_PIN           35
#define Z_MIN_PIN           32

//
// Steppers
//
#define X_STEP_PIN         137
#define X_DIR_PIN          135
#define X_ENABLE_PIN       138

#define Y_STEP_PIN         130
#define Y_DIR_PIN          129
#define Y_ENABLE_PIN       131

#define Z_STEP_PIN         133
#define Z_DIR_PIN          132
#define Z_ENABLE_PIN       134

#define E0_STEP_PIN        140
#define E0_DIR_PIN         141
#define E0_ENABLE_PIN      139

//
// Temperature Sensors
//
#define TEMP_0_PIN          39  // Analog Input
#define TEMP_BED_PIN        36  // Analog Input

//
// Heaters / Fans
//
#define HEATER_0_PIN         2
#define FAN_PIN             13  // "FAN1"
#define HEATER_BED_PIN       4
#define CONTROLLER_FAN_PIN 142  // "FAN2"
#undef E0_AUTO_FAN_PIN
#define E0_AUTO_FAN_PIN    143  // "FAN3"

//
// SPI
//
#define SDSS                 5

//
// LC Display
//
#if ENABLED(CR10_STOCKDISPLAY)
  #define LCD_PINS_RS       33
  #define LCD_PINS_ENABLE   12
  #define LCD_PINS_D4       14
#endif

//
// Rotary Encoder
//
#if ENABLED(REPRAP_DISCOUNT_SMART_CONTROLLER)
  #define BTN_EN1           26
  #define BTN_EN2           25
  #define BTN_ENC           27
#endif

//
// Servo / BLTouch
//
#define SERVO0_PIN          15
