#include "StatusBarApp.h"

#include "DisplayInterface.h"
#include "ViewportClass.h"
#include "System.h"

StatusBarAppClass StatusBarApp = StatusBarAppClass();

void StatusBarAppClass::setup() {
  test_button = new ButtonClass(this);
  test_button->size_x = 60;
  test_button->size_y = 24;
  test_button->offset_x = DisplayInterface::getDisplayWidth() - test_button->size_x;

  test_button->setPressedCallback(
    [this](int x){
      this->quitCurrentApp();
    }
  );

  System.println("statusbar setup");

  draw();

  // test_button.pressed_callback = this->button_pressed;
}

void StatusBarAppClass::loop() {}

void StatusBarAppClass::quit() {}

void StatusBarAppClass::draw() {
  viewport->fill(TFT_BLACK);
  viewport->setTextColor(TFT_GREEN, TFT_BLACK);
  viewport->drawString("statusbar is working!", 0, 0, 1);

  viewport->drawFastHLine(0, viewport->size_y - 1, DisplayInterface::getDisplayWidth(), TFT_DARKGREY);

  test_button->draw();
}

void StatusBarAppClass::quitCurrentApp() {
  if (allowQuit) {
    // System.println("quitting current app");
    System.closeApp();
  }
}