#include "DisplayInterface.h"

TFT_eSPI Display = TFT_eSPI();

void DisplayInterface::init() {
  Display.init();
  Display.setRotation(1);
  Display.fillScreen(TFT_BLACK);
  Display.setTextColor(TFT_WHITE, TFT_BLACK);
}

void DisplayInterface::loop() {
  
}