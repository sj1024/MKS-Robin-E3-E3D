/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2019 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
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
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */
#pragma once

/**
 * MKS Robin E3D (STM32F103RCT6) board pin assignments
 */

#ifndef __STM32F1__
  #error "Oops! Select an STM32F1 board in 'Tools > Board.'"
#elif HOTENDS > 1 || E_STEPPERS > 1
  #error "MKS Robin E3D supports up to 1 hotends / E-steppers. Comment out this line to continue."
#endif

#ifndef BOARD_INFO_NAME
  #define BOARD_INFO_NAME "MKS Robin E3D"
#endif
#define BOARD_WEBSITE_URL "github.com/makerbase-mks"

//#define DISABLE_DEBUG
#define DISABLE_JTAG
#define ENABLE_SPI2

//
// Servos
//
#define SERVO0_PIN         PA3

//
// Limit Switches
//
#define X_STOP_PIN         PA12
#define Y_STOP_PIN         PA11
#define Z_MIN_PIN          PC6
#define Z_MAX_PIN          PB1

//
// Steppers
//
#define X_STEP_PIN         PC0
#define X_DIR_PIN          PB2
#define X_ENABLE_PIN       PC13
#ifndef X_CS_PIN
  #define X_CS_PIN         PD5
#endif

#define Y_STEP_PIN         PC2
#define Y_DIR_PIN          PB9
#define Y_ENABLE_PIN       PB12
#ifndef Y_CS_PIN
  #define Y_CS_PIN         PD7
#endif

#define Z_STEP_PIN         PB7
#define Z_DIR_PIN          PB6
#define Z_ENABLE_PIN       PB8
#ifndef Z_CS_PIN
  #define Z_CS_PIN         PD4
#endif

#define E0_STEP_PIN        PB4
#define E0_DIR_PIN         PB3
#define E0_ENABLE_PIN      PB5
#ifndef E0_CS_PIN
  #define E0_CS_PIN        PD9
#endif

//
// Software SPI pins for TMC2130 stepper drivers
//
#if ENABLED(TMC_USE_SW_SPI)
  #ifndef TMC_SW_MOSI
    #define TMC_SW_MOSI    PB15
  #endif
  #ifndef TMC_SW_MISO
    #define TMC_SW_MISO    PB14
  #endif
  #ifndef TMC_SW_SCK
    #define TMC_SW_SCK     PB13
  #endif
#endif


#if HAS_TMC220x
  /**
   * TMC2208/TMC2209 stepper drivers
   *
   * Hardware serial communication ports.
   * If undefined software serial is used according to the pins below
   */
  //#define X_HARDWARE_SERIAL  Serial1
  //#define Y_HARDWARE_SERIAL  Serial1
  //#define Z_HARDWARE_SERIAL  Serial1
  //#define E0_HARDWARE_SERIAL Serial1

  //
  // Software serial
  //
  #define X_SERIAL_TX_PIN  PC7
  #define X_SERIAL_RX_PIN  PC7

  #define Y_SERIAL_TX_PIN  PD2
  #define Y_SERIAL_RX_PIN  PD2

  #define Z_SERIAL_TX_PIN  PC12
  #define Z_SERIAL_RX_PIN  PC12

  #define E0_SERIAL_TX_PIN PC11
  #define E0_SERIAL_RX_PIN PC11

  // Reduce baud rate to improve software serial reliability
  #define TMC_BAUD_RATE 19200
#endif


//
// Heaters 0,1 / Fans / Bed
//
#define HEATER_0_PIN       PC9
#define FAN_PIN            PA8
#define HEATER_BED_PIN     PC8

//
// Temperature Sensors
//
#define TEMP_BED_PIN       PA1  //TB
#define TEMP_0_PIN         PA0  //TH1

#define FIL_RUNOUT_PIN     PB10 // MT_DET

//
// LCD Pins
//
#if HAS_SPI_LCD

  #define BEEPER_PIN       PC1
  #define BTN_ENC          PC3
  #define LCD_PINS_ENABLE  PA4
  #define LCD_PINS_RS      PA5
  #define BTN_EN1          PB11
  #define BTN_EN2          PB0

  // MKS MINI12864 and MKS LCD12864B; If using MKS LCD12864A (Need to remove RPK2 resistor)
  #if ENABLED(MKS_MINI_12864)

    #define LCD_BACKLIGHT_PIN -1
    #define LCD_RESET_PIN  -1
    #define DOGLCD_A0      PC4
    #define DOGLCD_CS      PA7
    #define DOGLCD_SCK     PB13
    #define DOGLCD_MOSI    PB15

    // Required for MKS_MINI_12864 with this board
    #define MKS_LCD12864B
    #undef SHOW_BOOTSCREEN

  #else // !MKS_MINI_12864

    #define LCD_PINS_D4    PA6
    #if ENABLED(ULTIPANEL)
      #define LCD_PINS_D5  PA7
      #define LCD_PINS_D6  PC4
      #define LCD_PINS_D7  PC5
    #endif

  #endif // !MKS_MINI_12864

#endif // HAS_SPI_LCD

//
// SD Card
//
#define ENABLE_SPI2
#define SD_DETECT_PIN      PC10
#define SCK_PIN            PB13
#define MISO_PIN           PB14
#define MOSI_PIN           PB15
#define SS_PIN             PA15

#ifndef ST7920_DELAY_1
  #define ST7920_DELAY_1 DELAY_NS(125)
#endif
#ifndef ST7920_DELAY_2
  #define ST7920_DELAY_2 DELAY_NS(125)
#endif
#ifndef ST7920_DELAY_3
  #define ST7920_DELAY_3 DELAY_NS(125)
#endif
