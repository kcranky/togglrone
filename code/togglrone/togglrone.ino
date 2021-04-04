#include "hardware.h"

void setup(void) {
  // add debug serial
  Serial.begin(115200);

  setupHardware();

  // do the single setup
  delay(250);
  tft.setCursor(0,0);
  tft.setTextColor(ST77XX_RED, ST77XX_BLACK);
  tft.setTextSize(2);
  tft.println(toggl.getFullName());
}


void loop() {
  r.loop();
  b.loop();
}
 
