#include "DisplayInterface.h"

TFT_eSPI DisplayInterface::Display = TFT_eSPI();
DisplayInterfaceClass DisplayInterface::DisplayInterfaceObj = DisplayInterfaceClass();

void DisplayInterfaceClass::init() {
  DisplayInterface::Display.init();
  DisplayInterface::Display.setRotation(1);
  DisplayInterface::Display.fillScreen(TFT_BLACK);
  DisplayInterface::Display.setTextColor(TFT_WHITE, TFT_BLACK);
}