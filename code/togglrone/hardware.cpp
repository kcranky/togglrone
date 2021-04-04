#include "hardware.h"

// Pulled from "secrets.h"
const char* ssid     = STASSID;
const char* password = STAPSK;

// define global objects
Button2 b = Button2(BUTTON_PIN);
ESPRotary r = ESPRotary(ROTARY_PIN1, ROTARY_PIN2, CLICKS_PER_STEP);
Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);
Toggl toggl;


void setupHardware(){
  setupButton();
  setupEncoder();
  setupScreen();
  setupToggl();
}


/////////////////////
//     BUTTONS     //
/////////////////////
void setupButton(){
  b.setTapHandler(click);
  b.setLongClickHandler(resetPosition);
}

// single click
void click(Button2& btn) {
  Serial.println("Click!");
}

// long click
void resetPosition(Button2& btn) {
  r.resetPosition();
  Serial.println("Reset from long click!");
}

/////////////////////
//     ENCODER     //
/////////////////////
void setupEncoder(){
  r.setChangedHandler(rotate);
  r.setLeftRotationHandler(showDirection);
  r.setRightRotationHandler(showDirection);
}

// on change
void rotate(ESPRotary& r) {
   Serial.println(r.getPosition());
}

// on left or right rotation
void showDirection(ESPRotary& r) {
  Serial.println(r.directionToString(r.getDirection()));
}

/////////////////////
//      SCREEN     //
/////////////////////
void setupScreen(){
  // screen setup
  tft.init(240, 240, SPI_MODE2);    // Init ST7789 display 240x240 pixel
  tft.setRotation(2);
  tft.fillScreen(ST77XX_BLACK);
  tft.setCursor(0, 0);
  tft.setTextColor(ST77XX_RED, ST77XX_BLACK);
  tft.setTextSize(2);
  tft.println("Screen initialized!");
}

/////////////////////
//      TOGGL      //
/////////////////////
void setupToggl(){
  // currently includes wifi
  toggl.init(ssid, password);
  toggl.setAuth(TOKEN);
}
