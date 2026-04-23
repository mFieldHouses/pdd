#include "StatusBarApp.h"

#include "DisplayInterface.h"
#include "ViewportClass.h"
#include "ButtonClass.h"
#include "System.h"

StatusBarAppClass StatusBarApp = StatusBarAppClass();
ButtonClass test_button = ButtonClass();

void StatusBarAppClass::setup() {
  System.println("statusbar setup");

  viewport->size_x = DisplayInterface::getDisplayWidth();

  test_button.offset_x = 200;
  test_button.offset_y = 2;
  test_button.size_x = 30;
  test_button.size_y = 15;
  test_button.setParentViewport(viewport);
}

void StatusBarAppClass::loop() {
  viewport->setTextColor(TFT_GREEN, TFT_BLACK);
  viewport->drawString("statusbar is working!", 0, 0, 1);

  test_button.draw();

  viewport->drawFastHLine(0, 19, DisplayInterface::getDisplayWidth(), TFT_DARKGREY);
}