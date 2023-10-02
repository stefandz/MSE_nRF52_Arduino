 /*
  Copyright (c) 2014-2015 Arduino LLC.  All right reserved.
  Copyright (c) 2016 Sandeep Mistry All right reserved.
  Copyright (c) 2018, Adafruit Industries (adafruit.com)

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.
  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.
  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef _VARIANT_MSE_Bluetooth_Controller_
#define _VARIANT_MSE_Bluetooth_Controller_

/** Master clock frequency */
#define VARIANT_MCK       (64000000ul)

#define USE_LFXO      // Board uses 32khz crystal for LF
// define USE_LFRC    // Board uses RC for LF

/*----------------------------------------------------------------------------
 *        Headers
 *----------------------------------------------------------------------------*/

#include "WVariant.h"

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

// Number of pins defined in PinDescription array
#define PINS_COUNT           (48)
#define NUM_DIGITAL_PINS     (48)
#define NUM_ANALOG_INPUTS    (6)
#define NUM_ANALOG_OUTPUTS   (0)

// LEDs (names defined as per schematic)
#define PIN_LED2_R           (43) // P1.11
#define PIN_LED2_B           (45) // P1.13

#define LED_BUILTIN          PIN_LED2_R
#define LED_CONN             PIN_LED2_B

#define LED_RED              PIN_LED2_R
#define LED_BLUE             PIN_LED2_B

#define LED_STATE_ON         0    // state when LED is illuminated

/*
 * Buttons
 */


/*
 * Analog pins
 */
#define PIN_A0               ( 3) // EN
#define PIN_A1               (28) // EXT_VR1
#define PIN_A2               (31) // EXT_VR2
#define PIN_A3               (30) // EXT_VR3
#define PIN_A4               ( 2) // EXT_VR4
#define PIN_A5               (29) // VIN_DIV_2
#define PIN_A6               (0xff)
#define PIN_A7               (0xff)

static const uint8_t A0  = PIN_A0 ;
static const uint8_t A1  = PIN_A1 ;
static const uint8_t A2  = PIN_A2 ;
static const uint8_t A3  = PIN_A3 ;
static const uint8_t A4  = PIN_A4 ;
static const uint8_t A5  = PIN_A5 ;
static const uint8_t A6  = PIN_A6 ;
static const uint8_t A7  = PIN_A7 ;
#define ADC_RESOLUTION    12

// Other pins

/*
 * Serial interfaces
 */

// Arduino Header D0, D1
#define PIN_SERIAL1_RX       (24) // P0.24
#define PIN_SERIAL1_TX       (25) // P0.25

/*
 * SPI Interfaces
 */
#define SPI_INTERFACES_COUNT 1

#define PIN_SPI_MISO         (15) // P0.15
#define PIN_SPI_MOSI         (13) // P0.13
#define PIN_SPI_SCK          (14) // P0.14

static const uint8_t SS   = 17 ; // P0.17
static const uint8_t MOSI = PIN_SPI_MOSI ;
static const uint8_t MISO = PIN_SPI_MISO ;
static const uint8_t SCK  = PIN_SPI_SCK ;

/*
 * Wire Interfaces
 */
#define WIRE_INTERFACES_COUNT 0

// QSPI Pins

// On-board QSPI Flash

#ifdef __cplusplus
}
#endif

/*----------------------------------------------------------------------------
 *        Arduino objects - C++ only
 *----------------------------------------------------------------------------*/

#endif
