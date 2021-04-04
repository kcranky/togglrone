# togglrone

Implementing Toggl functionality with an ESP8266.
Any naming similarities to a particular Swiss chocolate bar is purely intentional.

## Hardware
This project makes use of the following hardware components:
- ESP8266 (NodeMCU)
- Rotary Encoder
- ST7789 IPS Display

## Code

This project is created using the Arduino IDE. 

### Libraries
The libraries listed below are required. There may be more which are referenced indirectly, but these are required as seperate installs:
- ESP8226 Board Libraries
- Adafruit ST7735 and ST7789 Library
- Adafruit-GFX-Library
- Button2
- ESP Rotary
- Toggl API (Note: Currently this project uses a custom implementation, available [here](https://github.com/kcranky/Arduino-Toggl-API/tree/RemoveStrings). Work is being done to integrate these and some other changes into the primary API library.)

### Structure
In order to get this code to work, you must create a "secrets.h" file, and in it include:
```cpp
#ifndef SECRETS_H
#define SECRETS_H

#define TOKEN "<your-toggl-api-token>"
#define STASSID "<your-wifi-SSID>"
#define STAPSK  "<your-wifi-password>"
  
#endif
```
The other files are as follows:
- togglrone.ino
  - Arduino project top level file.
- pinDefinitions.h
  - Abstracts away pin definitions for easy reconfigurability.
- hardware.h and hardware.cpp
  - Includes setup and configuration functionality for included hardware.


## References 
The following references proved useful in creating this project:
- [Interfacing ESP8266 NodeMCU with ST7789 TFT Display](https://simple-circuit.com/esp8266-nodemcu-st7789-tft-ips-display/)
