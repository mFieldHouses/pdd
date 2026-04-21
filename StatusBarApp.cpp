#include "StatusBarApp.h"

StatusBarAppClass StatusBarApp = StatusBarAppClass();

void StatusBarAppClass::setup() {

}

void StatusBarAppClass::loop() {
  viewport->setTextColor(TFT_WHITE, TFT_BLACK);
  viewport->drawString("statusbar is working!", 0, 0, 1);

  viewport->drawFastHLine(0, 19, DisplayInterface::getDisplayWidth(), TFT_DARKGREY);
}