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
#define PT100_PIN                           PD15 // Analog Input "PT100" (INA826)

//
// Heaters / Fans
//
#define HEATER_BED_PIN                      PA0   // "HB"
#define HEATER_0_PIN                        PA5   // "HE0"

#define FAN0_PIN                            PA6   // "FAN0"

#define FAN1_PIN                            PA7   // "FAN1"

#define FAN2_PIN                            PB6   // "FAN1"

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

/**
 *              BTT E3 RRF
 *                ------
 * (BEEPER)  PE8 | 1  2 | PE9  (BTN_ENC)
 * (BTN_EN1) PE7 | 3  4 | RESET
 * (BTN_EN2) PB2   5  6 | PE10 (LCD_D4)
 * (LCD_RS)  PB1 | 7  8 | PE11 (LCD_EN)
 *           GND | 9 10 | 5V
 *                ------
 *                 EXP1
 */

#if HAS_WIRED_LCD

  #if EITHER(CR10_STOCKDISPLAY, LCD_FOR_MELZI)

    #define BEEPER_PIN                      PE11

    #define BTN_ENC                         PE12
    #define BTN_EN1                         PA14
    #define BTN_EN2                         PE9

    #define LCD_PINS_RS                     PE7
    #define LCD_PINS_ENABLE                 PE8
    #define LCD_PINS_D4                     PE10

    #if ENABLED(LCD_FOR_MELZI)

      #ifndef NO_CONTROLLER_CUSTOM_WIRING_WARNING
        #error "CAUTION! LCD_FOR_MELZI requires wiring modifications. See 'pins_BTT_E3_RRF.h' for details. (Define NO_CONTROLLER_CUSTOM_WIRING_WARNING to suppress this warning.)"
      #endif

     /** LCD_FOR_MELZI display pinout
      *
      *               BTT E3 RRF                                   Display Ribbon
      *                ------                                         ------
      * (BEEPER)  PE8 | 1  2 | PE9  (BTN_ENC)                    GND |10  9 | 5V
      * (BTN_EN1) PE7 | 3  4 | RESET                          BEEPER | 8  7 | ESTOP    (RESET)
      * (BTN_EN2) PB2   5  6 | PE10 (LCD_D4)       (BTN_ENC) ENC_BTN | 6  5 | LCD_SCLK (LCD_D4)
      * (LCD_RS)  PB1 | 7  8 | PE11 (LCD_EN)       (BTN_EN2) ENC_A   | 4  3 | LCD_DATA (LCD_EN)
      *           GND | 9 10 | 5V                  (BTN_EN1) ENC_B   | 2  1 | LCD_CS   (LCD_RS)
      *                ------                                         ------
      *                 EXP1                                           LCD
      *
      * Needs custom cable:
      *
      *    Board   Adapter   Display Ribbon (coming from display)
      *  ----------------------------------
      *  EXP1-10 ---------- LCD-9   5V
      *  EXP1-9 ----------- LCD-10  GND
      *  EXP1-8 ----------- LCD-3   LCD_EN
      *  EXP1-7 ----------- LCD-1   LCD_RS
      *  EXP1-6 ----------- LCD-5   LCD_D4
      *  EXP1-5 ----------- LCD-4   EN2
      *  EXP1-4 ----------- LCD-7   RESET
      *  EXP1-3 ----------- LCD-2   EN1
      *  EXP1-2 ----------- LCD-6   BTN
      *  EXP1-1 ----------- LCD-8   BEEPER
      */

    #endif

  #elif ENABLED(ZONESTAR_LCD)                     // ANET A8 LCD Controller - Must convert to 3.3V - CONNECTING TO 5V WILL DAMAGE THE BOARD!

    #ifndef NO_CONTROLLER_CUSTOM_WIRING_WARNING
      #error "CAUTION! ZONESTAR_LCD requires wiring modifications. See 'pins_BTT_E3_RRF.h' for details. (Define NO_CONTROLLER_CUSTOM_WIRING_WARNING to suppress this warning.)"
    #endif

    #define LCD_PINS_RS                     PE10
    #define LCD_PINS_ENABLE                 PE9
    #define LCD_PINS_D4                     PB1
    #define LCD_PINS_D5                     PB2
    #define LCD_PINS_D6                     PE7
    #define LCD_PINS_D7                     PE8
    #define ADC_KEYPAD_PIN                  PB0   // Repurpose servo pin for ADC - CONNECTING TO 5V WILL DAMAGE THE BOARD!

  #elif EITHER(MKS_MINI_12864, ENDER2_STOCKDISPLAY)

    #define BTN_ENC                         PE9
    #define BTN_EN1                         PE7
    #define BTN_EN2                         PB2

    #define DOGLCD_CS                       PB1
    #define DOGLCD_A0                       PE10
    #define DOGLCD_SCK                      PE8
    #define DOGLCD_MOSI                     PE11

    #define FORCE_SOFT_SPI
    #define LCD_BACKLIGHT_PIN               -1

  #elif IS_TFTGLCD_PANEL

    #if ENABLED(TFTGLCD_PANEL_SPI)

      #ifndef NO_CONTROLLER_CUSTOM_WIRING_WARNING
        #error "CAUTION! TFTGLCD_PANEL_SPI requires wiring modifications. See 'pins_BTT_E3_RRF.h' for details. (Define NO_CONTROLLER_CUSTOM_WIRING_WARNING to suppress this warning.)"
      #endif

      /**
       * TFTGLCD_PANEL_SPI display pinout
       *
       *                  Board                       Display
       *                  ------                       ------
       * (SD_DET)    PE8 | 1  2 | PE9 (BEEPER)     5V |10  9 | GND
       * (MOD_RESET) PE7 | 3  4 | RESET            -- | 8  7 | (SD_DET)
       * (SD_CS)     PB2   5  6 | PE10        (MOSI)    6  5 | --
       * (LCD_CS)    PB1 | 7  8 | PE11        (SD_CS) | 4  3 | (LCD_CS)
       *             GND | 9 10 | 5V          (SCK)   | 2  1 | (MISO)
       *                  ------                       ------
       *                   EXP1                         EXP1
       *
       * Needs custom cable:
       *
       *    Board   Adapter   Display
       *   ----------------------------------
       *   EXP1-10 ---------- EXP1-10  5V
       *   EXP1-9 ----------- EXP1-9   GND
       *   SPI1-4 ----------- EXP1-6   MOSI
       *   EXP1-7 ----------- n/c
       *   SPI1-3 ----------- EXP1-2   SCK
       *   EXP1-5 ----------- EXP1-4   SD_CS
       *   EXP1-4 ----------- n/c
       *   EXP1-3 ----------- EXP1-3   LCD_CS
       *   SPI1-1 ----------- EXP1-1   MISO
       *   EXP1-1 ----------- EXP1-7   SD_DET
       */

      #define TFTGLCD_CS                    PE7

    #endif

  #else
    #error "Only CR10_STOCKDISPLAY, ZONESTAR_LCD, ENDER2_STOCKDISPLAY, MKS_MINI_12864, LCD_FOR_MELZI, and TFTGLCD_PANEL_(SPI|I2C) are currently supported on the BTT_E3_RRF."
  #endif

  // Alter timing for graphical display
  #if ENABLED(LCD_FOR_MELZI)                      // LCD_FOR_MELZI default timing is too fast. This works but may be reduced.
    #define BOARD_ST7920_DELAY_1             200
    #define BOARD_ST7920_DELAY_2             400
    #define BOARD_ST7920_DELAY_3            1200
  #elif IS_U8GLIB_ST7920
    #define BOARD_ST7920_DELAY_1              96
    #define BOARD_ST7920_DELAY_2              48
    #define BOARD_ST7920_DELAY_3             600
  #endif

#endif // HAS_WIRED_LCD

#if BOTH(TOUCH_UI_FTDI_EVE, LCD_FYSETC_TFT81050)

  #ifndef NO_CONTROLLER_CUSTOM_WIRING_WARNING
    #error "CAUTION! LCD_FYSETC_TFT81050 requires wiring modifications. See 'pins_BTT_E3_RRF.h' for details. (Define NO_CONTROLLER_CUSTOM_WIRING_WARNING to suppress this warning.)"
  #endif

  /** FYSETC TFT TFT81050 display pinout
   *
   *                  Board                          Display
   *                  ------                          ------
   * (SD_DET)    PE8 | 1  2 | PE9 (BEEPER)        5V |10  9 | GND
   * (MOD_RESET) PE7 | 3  4 | RESET            RESET | 8  7 | (SD_DET)
   * (SD_CS)     PB2   5  6 | PE10           (MOSI)  | 6  5 | (LCD_CS)
   * (LCD_CS)    PB1 | 7  8 | PE11           (SD_CS) | 4  3 | (MOD_RESET)
   *             GND | 9 10 | 5V             (SCK)   | 2  1 | (MISO)
   *                  ------                          ------
   *                   EXP1                            EXP1
   *
   * Needs custom cable:
   *
   *    Board   Adapter   Display
   *   ----------------------------------
   *   EXP1-10 ---------- EXP1-10  5V
   *   EXP1-9 ----------- EXP1-9   GND
   *   SPI1-4 ----------- EXP1-6   MOSI
   *   EXP1-7 ----------- EXP1-5   LCD_CS
   *   SPI1-3 ----------- EXP1-2   SCK
   *   EXP1-5 ----------- EXP1-4   SD_CS
   *   EXP1-4 ----------- EXP1-8   RESET
   *   EXP1-3 ----------- EXP1-3   MOD_RST
   *   SPI1-1 ----------- EXP1-1   MISO
   *   EXP1-1 ----------- EXP1-7   SD_DET
   */

  #define CLCD_SPI_BUS                         1  // SPI1 connector

  #define BEEPER_PIN                        PE9

  #define CLCD_MOD_RESET                    PE7
  #define CLCD_SPI_CS                       PB1

#endif // TOUCH_UI_FTDI_EVE && LCD_FYSETC_TFT81050

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
#elif SD_CONNECTION_IS(CUSTOM_CABLE)
  #error "SD CUSTOM_CABLE is not compatible with BTT E3 RRF."
#endif

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
