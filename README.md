# ATARI ST Sidecart Test suite for the ROM Emulator

This repository contains a test program designed to validate the functionality and performance of the Sidecartridge Multidevice. 

## Introduction

The SidecarTridge Multidevice emulates the behavior of Atari ST cartridges and the ROM memory contained. To ensure its flawless operation and accurate timing, this test suite offers several read tests, presenting the results visually on-screen.

For those new to the Sidecart ROM Emulator, we recommend visiting the official [SidecarTridge Multidevice website](https://sidecartridge.com) for a comprehensive overview.

## Getting Started

### Atari ST / MegaST / STE / MegaSTE / TT / Falcon 

To get started with the testing process, you'll need two main files, both of which can be located in the [Release page](https://github.com/sidecartridge/atarist-sidecart-test-rom/releases) of this repository:

- **`TESTSCRT.TOS`**: The primary test program, which should be transferred to your Atari ST machine.
  
- **`TESTROM.BIN`**: A binary file containing randomized data across two ROM banks. This file needs to be copied to your Atari ST computer and should be placed in the same directory as `TESTSCRT.TOS`. It is essential for the test program to function correctly.

### SidecarTridge Multidevice Setup with a functional computer

This version of the test suite is designed to run on the SidecarTridge Multidevice with the new firmware v2.0 or later. Once you are in the management web interface of the SidecarTridge Multidevice also called the `Booster Configurator`, you have to find the `Multidevice Test` microfirmware, download it, and launch it. This microfirmware is designed to work with the programs located in the Atari computer.

![SidecarTridge Multidevice Test](/apps.png)

After launching the Multidevice Test, your computer should start as if nothing happened. You can now run the `TESTSCRT.TOS` program from your Atari ST computer.

### SidecarTridge Multidevice Setup with a failed computer <-> device connection

One of the reasons for running this test suite is to verify the connection between the SidecarTridge Multidevice and your Atari ST computer. So, if your computer is not running correctly with the device connected, you can still run the test suite.

The SidecarTridge Multidevice with the new firmware v2.0 can start and can be configured without the Atari ST computer. In ths *blind mode*, the user must follow these steps:

1. Power on the SidecarTridge Multidevice with a USB cable connected to a power source or a computer.
2. If your device did work and you were able to access the management web interface, you can jump to step 8.
3. If you are not able to access the management web interface, you can reset the device by pressing the SELECT button for MORE than 10 seconds. Then, the device will reset to factory settings.
4. Power off and power on the SidecarTridge Multidevice again. Now, it should start in the factory or FABRIC mode.
5. Connect to the `SIDECART` Wi-Fi network using your computer or smartphone. Use the password `sidecart`.
6. Open a web browser and go to the address `http://192.168.4.1`. This will take you to the management web interface of the SidecarTridge Multidevice. Select the WiFi network you want to connect to and enter the password for that network. The device will reboot and connect to the selected WiFi network.
7. The device will now be accessible via the WiFi network you selected as `http://sidecart.local` or `http://<IP_ADDRESS_OF_THE_DEVICE>`. If the DNS of your network cannot be configured to resolve `sidecart.local`, you should find the IP address of the device in your router's DHCP client list.
8. Once you have access to the management web interface, you have to download the `Multidevice Test` microfirmware and launch it. This microfirmware is designed to work with the programs located in the Atari computer.
9. Power off the SidecarTridge Multidevice and connect it to your Atari ST computer. Remove the USB cable to guarantee that the device is powered by the Atari ST computer.
10. Power on the Atari ST computer. The SidecarTridge Multidevice should start automatically, and you can run the `TESTSCRT.TOS` program from your Atari ST computer.


## Requirements for developers

- An Atari ST/MegaST/STE/MegaSTE computer. There are several emulators available for Windows, Linux, and Mac. I recommend [Hatari](http://hatari.tuxfamily.org/), and I'm also a big fan of [MiSTer](https://misterfpga.org/). It should work on any Atari STe with at least 1MB of RAM.

- A SidecarTridge Multi-device with a Raspberry Pi Pico WH.

- The [atarist-toolkit-docker](https://github.com/sidecartridge/atarist-toolkit-docker): You should read first how to install it and how to use it. It's very easy.

- A `git` client. You can use the command line or a GUI client.

- A Makefile compatible with GNU Make.

## Building

Once you have your real Atari ST computer, Hatari emulator or MiSTer Atari ST up and running, you can build the program using the following steps:

1. Clone this repository:

```
$ git clone https://github.com/sidecartridge/md-testrom.git
```

2. Export the `ST_WORKING_FOLDER` environment variable with the absolute path of the folder where you cloned the repository:

```
export ST_WORKING_FOLDER=<ABSOLUTE_PATH_TO_THE_FOLDER_WHERE_YOU_CLONED_THE_REPO>
```

3. Build the test program. Enter the `md-testrom` folder and run the `make` script:

```
cd md-testrom
make
```

4. Copy the `dist/TESTSCRT.TOS` file to your Atari ST computer, Hatari emulator or MiSTer Atari ST.

5. Run it!

## Resources 


## License
This project is licenses under the GNU General Public License v3.0. See the [LICENSE](LICENSE) file for details.
