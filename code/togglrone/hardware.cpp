#include "hardware.h"
#include "states.h"

// define global objects
Button2 b = Button2(BUTTON_PIN);
ESPRotary r = ESPRotary(ROTARY_PIN1, ROTARY_PIN2, CLICKS_PER_STEP);
Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);
Toggl toggl;

const char* ssid = STASSID;
const char* password = STAPSK;

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
  // r.getPosition() auto updates

  // nothing should happen when the index is 0 and it decreases
  if (r.getPosition() == -1) {
    r.resetPosition();
    return;
  }
    
  switch(currentState){
    case ST_PROJECTS :
      // if we need to readjust the screen if it goes over
      if (r.getPosition() >= LINES_ON_SCREEN) {
        // we'll get there
      }
      else {
        generateSelected(r.getPosition());
        Serial.println(r.getPosition());
      }
      break;
      
    case ST_ITEMS :
      break;
      
    default :
      break;
  }
  
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

void showError(String const& error){
  tft.fillScreen(ST77XX_BLACK);
  tft.setCursor(0, 0);
  tft.println(error);
}

void clearScreen(){
  tft.fillScreen(ST77XX_BLACK);
  tft.setCursor(0,0);
}

void generateSelected(int const& index){
  tft.setCursor(0, 0);
  tft.println();
  for (int i=0; i < LINES_ON_SCREEN-1; i++){
    if (i == index) {
      tft.println("+");
    }
    else {
      tft.println("-");
    }
  }
}

/////////////////////
//      TOGGL      //
/////////////////////
void setupToggl(){
  // currently includes wifi
  toggl.init(ssid, password);
  toggl.setAuth(TOKEN);
}
