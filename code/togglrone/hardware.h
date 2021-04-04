#ifndef HARDWARE_H
#define HARDWARE_H
  
  #include <Adafruit_ST7789.h> // Hardware-specific library for ST7789
  #include <ESPRotary.h>;
  #include <Button2.h>;
  #include "PinDefinitions.h"
  #include "Toggl.h"
  #include "secrets.h"

  // global objects
  extern Adafruit_ST7789 tft;
  extern Toggl toggl;
  extern ESPRotary r;
  extern Button2 b;

  // setup functions
  void setupHardware();
  
  // button functions
  void setupButton();
  void click(Button2& btn);
  void resetPosition(Button2& btn);

  // rotary encoder functions
  void setupEncoder();
  void rotate(ESPRotary& r);
  void showDirection(ESPRotary& r);

  //screen functions
  void setupScreen();

  // toggl functions
  void setupToggl();
  
#endif
