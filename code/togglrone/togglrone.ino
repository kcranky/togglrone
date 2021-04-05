#include "hardware.h"
#include "states.h"

void setup(void) {
  // add debug serial
  Serial.begin(115200);

  setupHardware();

  // do the single setup
  tft.fillScreen(ST77XX_BLACK);
  tft.setCursor(0,0);
  tft.setTextColor(ST77XX_RED, ST77XX_BLACK);
  tft.println(toggl.getFullName());

  enterProjects();
}


void loop() {
  r.loop();
  b.loop();
}
 
