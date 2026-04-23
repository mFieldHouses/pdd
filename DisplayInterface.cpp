#include "DisplayInterface.h"

#include "System.h"

TFT_eSPI Display = TFT_eSPI();

void DisplayInterface::init() {
  Display.init();
  Display.setRotation(1);
  Display.fillScreen(TFT_BLACK);
  Display.setTextColor(TFT_WHITE, TFT_BLACK);
}

void DisplayInterface::loop() {
  // System.println(String("rotation is ") + String(Display.getRotation()));
}

int DisplayInterface::getDisplayHeight() {
  System.println(String("rotation is ") + String(Display.getRotation()));
  if (Display.getRotation() % 2 == 1) {
    return TFT_WIDTH;
  }
  else {
    return TFT_HEIGHT;
  }
}

int DisplayInterface::getDisplayWidth() {
  if (Display.getRotation() % 2 == 1) {
    return TFT_HEIGHT;
  }
  else {
    return TFT_WIDTH;
  }
}