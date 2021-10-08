# MSE Core for nRF52 Boards

[![Build Status](https://github.com/stefandz/MSE_nRF52_Arduino/workflows/Build/badge.svg)](https://github.com/stefandz/MSE_nRF52_Arduino/actions)

This repository contains the Arduino BSP for MSE nRF52 series:

- MSE Rewards Board A

## BSP Installation

1. [Download and install the Arduino IDE](https://www.arduino.cc/en/Main/Software) (At least v1.6.12)
2. Start the Arduino IDE
3. Go into Preferences
4. Add https://www.adafruit.com/package_adafruit_index.json as an 'Additional Board Manager URL'
5. Restart the Arduino IDE
6. Open the Boards Manager from the Tools > Board menu and install 'Adafruit nRF52 by Adafruit'
7. `cd <SKETCHBOOK>`, where `<SKETCHBOOK>` is your Arduino Sketch folder:
   * macOS  : `~/Documents/Arduino`
   * Linux  : `~/Arduino`
   * Windows: `~/Documents/Arduino`
8. Create a folder named `hardware/MSE`, if it does not exist, and change directories to it
9. Clone this repo & its submodules: `git clone --recurse-submodules https://github.com/stefandz/MSE_nRF52_Arduino`
10. Restart the Arduino IDE
11. Once the BSP is installed, select 'MSE NRF52840 Rewards Board A from the Tools > Board > MSE nRF52 boards menu, which will update your system config to use the right compiler and settings for the nRF52.

### Adafruit's nrfutil tools

[adafruit-nrfutil](https://github.com/adafruit/Adafruit_nRF52_nrfutil) (derived from Nordic [pc-nrfutil](https://github.com/NordicSemiconductor/pc-nrfutil)) is needed to upload sketch via serial port.

- For Windows and macOS, pre-built executable binaries are included in the BSP at `tools/adafruit-nrfutil/`. It should work out of the box.
- Linux user need to run follow command to install it from PyPi

```
$ pip3 install adafruit-nrfutil --user
```

### Drivers

- none required

## Bootloader

Bootloader can be updated via UF2 file or DFU if already existed. Or flash on new blank chip using following guide.

### Burning new Bootloader (recommended)

To burn the bootloader from within the Arduino IDE, you will need the following tools installed on your system and available in the system path:

- Segger [JLink Software and Documentation Pack](https://www.segger.com/downloads/jlink)
- Nordic [nRF5x Command Line Tools](https://www.nordicsemi.com/Software-and-Tools/Development-Tools/nRF-Command-Line-Tools)

Check to make sure you can run `nrfjprog` from your terminal/command prompt

**macOS Note** At present, you will need to create a symlink in `/usr/local/bin` to the
`nrfjprog` tool wherever you have added it. You can run the following command, for example:

```
$ ln -s $HOME/prog/nordic/nrfjprog/nrfjprog /usr/local/bin/nrfjprog
```

Once the tools above have been installed and added to your system path, from the Arduino IDE:

- Select `Tools > Board > MSE nRF52 Boards > MSE nRF52840 Rewards Board A`
- Select `Tools > Programmer > J-Link for Bluefruit nRF52`
- Select `Tools > Burn Bootloader` with the board and J-Link connected

#### Manually Burning the Bootloader via nrfjprog

The bootloader hex file can be found in the `bootloader/$BOARD_NAME`  folder. Run the command as follows:

```
$ nrfjprog -e -f nrf52
$ nrfjprog --program bootloader_file_name.hex -f nrf52
$ nrfjprog --reset -f nrf52
```

## ### Update Bootloader with UF2 ( nRF52840-based boards only and require 0.4.0+ )

This only works with nRF52840-based boards and require existing bootloader version is at least 0.4.0:

- Quickly double tap reset button to put your board in to bootloader mode. A mass storage device i.e `MSE_REWARDS_A` will appear
- Drap and drop the new UF2 file into `MSE_REWARDS_A` drive to perform update then wait until the board resets.

### Update Bootloader with DFU

To upgrade to the latest Bootloader + Softdevice using the serial port within Arduino IDE.

- Select `Tools > Board > MSE nRF52 Boards > MSE nRF52840 Rewards Board A`
- Select `Tools > Programmer > Bootloader DFU for Bluefruit nRF52`
- Select `Tools > Burn Bootloader`
- **WAIT** until the process complete ~30 seconds

**Note: close the Serial Monitor before you click "Burn Bootloader". Afterwards, you shouldn't close the Arduino IDE, unplug the board, launch Serial Monitor etc ... to abort the process. There is a high chance it will brick your device! Do this with care and caution.**

## Credits

This core is based on the [Adafruit nRF52 core]([GitHub - adafruit/Adafruit_nRF52_Arduino: Adafruit code for the Nordic nRF52 BLE SoC on Arduino](https://github.com/adafruit/Adafruit_nRF52_Arduino)), which is based on [Arduino-nRF5](https://github.com/sandeepmistry/arduino-nRF5) by Sandeep Mistry, which in turn is based on the [Arduino SAMD Core](https://github.com/arduino/ArduinoCore-samd).

The following libraries are used:

- [FreeRTOS](https://www.freertos.org/) as operating system
- [LittleFS](https://github.com/ARMmbed/littlefs) for internal file system
- [nrfx](https://github.com/NordicSemiconductor/nrfx) for peripherals driver
- [TinyUSB](https://github.com/hathach/tinyusb) as usb stack
