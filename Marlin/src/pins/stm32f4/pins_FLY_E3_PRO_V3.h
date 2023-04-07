/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2021 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
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
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */
#pragma once

#if NOT_TARGET(STM32F4)
  #error "Oops! Select an STM32F4 board in 'Tools > Board.'"
#endif

#ifndef BOARD_INFO_NAME
  #define BOARD_INFO_NAME "Fly E3 Pro v3"
#endif

#define USES_DIAG_JUMPERS

// Onboard I2C EEPROM
#define I2C_EEPROM
#define MARLIN_EEPROM_SIZE 0x1000                 // 4K

//
// Servos
//
#define SERVO0_PIN                          PB0   // SERVOS

//
// Limit Switches
//
#define X_STOP_PIN                          PA2   // X-STOP
#define Y_STOP_PIN                          PB10   // Y-STOP
#define Z_STOP_PIN                          PC4   // Z-STOP

//
// Z Probe must be this pin
//
#define Z_MIN_PROBE_PIN                     PC5   // PROBE

//
// Filament Runout Sensor
//
#ifndef FIL_RUNOUT_PIN
  #define FIL_RUNOUT_PIN                    PD0   // E0-STOP
#endif

#ifndef FIL_RUNOUT2_PIN
  #define FIL_RUNOUT2_PIN                   PD1  // E1-STOP
#endif

//
// Power-loss Detection
//
#ifndef POWER_LOSS_PIN
  #define POWER_LOSS_PIN                    PD10   // Power Loss Detection: PWR-DET
#endif

//
// Steppers
//
#define X_ENABLE_PIN                        PE5
#define X_STEP_PIN                          PE3
#define X_DIR_PIN                           PE2

#define Y_ENABLE_PIN                        PE1
#define Y_STEP_PIN                          PB9
#define Y_DIR_PIN                           PB8

#define Z0_ENABLE_PIN                       PC2
#define Z0_STEP_PIN                         PA15
#define Z0_DIR_PIN                          PD7

#define Z1_ENABLE_PIN                       PD6
#define Z1_STEP_PIN                         PD4
#define Z1_DIR_PIN                          PD3

#define E0_ENABLE_PIN                       PC15
#define E0_STEP_PIN                         PC13
#define E0_DIR_PIN                          PC0

/**
 * TMC2208/TMC2209 stepper drivers
 */
#if HAS_TMC_UART
  #define X_SERIAL_TX_PIN                   PE4
  #define X_SERIAL_RX_PIN        X_SERIAL_TX_PIN

  #define Y_SERIAL_TX_PIN                   PE0
  #define Y_SERIAL_RX_PIN        Y_SERIAL_TX_PIN

  #define Z0_SERIAL_TX_PIN                  PA8
  #define Z0_SERIAL_RX_PIN       Z0_SERIAL_TX_PIN

  #define Z1_SERIAL_TX_PIN                  PD5
  #define Z1_SERIAL_RX_PIN       Z1_SERIAL_TX_PIN

  #define E0_SERIAL_TX_PIN                  PC14
  #define EO_SERIAL_RX_PIN       E0_SERIAL_TX_PIN

  // Reduce baud rate to improve software serial reliability
  #define TMC_BAUD_RATE 19200
#endif

//
// Temperature Sensors
//
#define TEMP_BED_PIN                        PA3   // Analog Input "TB"
#define TEMP_0_PIN                          PA4   // Analog Input "TH0"
#define TEMP_1_PIN                          PA1  // Analog Input "TH1"

//
// Heaters / Fans
//
#define HEATER_BED_PIN                      PA0   // "HB"
#define HEATER_0_PIN                        PA5   // "HE0"
#define HEATER_1_PIN                        PC6   // "HE1"

#define FAN0_PIN                            PA7   // "FAN0"
#define FAN1_PIN                            PA6   // "FAN1"
#define FAN2_PIN                            PB6   // "FAN2"

#ifndef CONTROLLER_FAN_PIN
  #define CONTROLLER_FAN_PIN                PB7   // "FAN3"
#endif

//
// Misc. Functions
//
#ifndef NEOPIXEL_PIN
  #define NEOPIXEL_PIN                      PB11   // LED driving pin
#endif

#ifndef PS_ON_PIN
  #define PS_ON_PIN                         PD11   // Power Supply Control
#endif

/**               ------                                      ------
 * (BEEPER) PE11 | 1  2 | PE12  (BTN_ENC)         (MISO) PB4  | 1  2 | PB3 (SCK)
 * (LCD_EN) PA14 | 3  4 | PE6 (LCD_RS)         (BTN_EN1) PA10 | 3  4 | PB2 (SD_SS)
 * (LCD_D4) PE9    5  6 | PE10  (LCD_D5)       (BTN_EN2) PA9    5  6 | PB5 (MOSI)
 * (LCD_D6) PE7  | 7  8 | PE8  (LCD_D7)      (SD_DETECT) PA13 | 7  8 | RESET
 *           GND | 9 10 | 5V                              GND | 9 10 | --
 *                ------                                      ------
 *                 EXP1                                        EXP2
 */
#define EXP1_01_PIN                         PE11
#define EXP1_02_PIN                         PE12
#define EXP1_03_PIN                         PA14
#define EXP1_04_PIN                         PE6
#define EXP1_05_PIN                         PE9
#define EXP1_06_PIN                         PE10
#define EXP1_07_PIN                         PE7
#define EXP1_08_PIN                         PE8

#define EXP2_01_PIN                         PB4
#define EXP2_02_PIN                         PB3
#define EXP2_03_PIN                         PA10
#define EXP2_04_PIN                         PB2
#define EXP2_05_PIN                         PA9
#define EXP2_06_PIN                         PB5
#define EXP2_07_PIN                         PA13
#define EXP2_08_PIN                         -1

//
// SD Support
//

#ifndef SDCARD_CONNECTION
  #define SDCARD_CONNECTION              ONBOARD
#endif

#if SD_CONNECTION_IS(ONBOARD)
  #define SDIO_SUPPORT                            // Use SDIO for onboard SD
  //#define SDIO_CLOCK                  48000000
  #define SD_DETECT_PIN                     PC4

#if ENABLED(WIFISUPPORT)
  //
  // WIFI
  //
  #define ESP_WIFI_MODULE_COM                  3  // Must also set either SERIAL_PORT or SERIAL_PORT_2 to this
  #define ESP_WIFI_MODULE_BAUDRATE      BAUDRATE  // Must use same BAUDRATE as SERIAL_PORT & SERIAL_PORT_2
  #define ESP_WIFI_MODULE_RESET_PIN         PA4
  #define ESP_WIFI_MODULE_ENABLE_PIN        PA5
  #define ESP_WIFI_MODULE_GPIO0_PIN         PA6
#endif

