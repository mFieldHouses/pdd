#include "ButtonClass.h"

#include <functional>
#include "DisplayInterface.h"
#include "System.h"
#include "ViewportClass.h"
#include "AppClass.h"

ButtonClass::ButtonClass(AppClass* parent_app) {
  setParentApp(parent_app);
}

void ButtonClass::draw() {
  // Serial.println("draw button");
  if (visible && parent_app->getViewport()) {
    parent_app->getViewport()->drawRect(offset_x, offset_y, size_x, size_y, TFT_WHITE);
  }
}

void ButtonClass::drawFilled() {
  //System.println("draw button");
  if (visible && parent_app->getViewport()) {
    parent_app->getViewport()->drawRect(offset_x, offset_y, size_x, size_y, TFT_RED);
  }
}

bool ButtonClass::isPointWithin(int32_t px, int32_t py, uint pr) {
  return !(
    (px + pr < offset_x || px - pr > offset_x + size_x) || (py + pr < offset_y || py - pr > offset_y + size_y) // This doesn't yet work entirely as I want it to work
  );
}

void ButtonClass::setPressedCallback(std::function<void(int)> func) {
  pressed_callback = func;
}

void ButtonClass::press(uint pressure) {
  // System.println("Button got pressed!");

  if (pressed_callback && visible) {
    pressed_callback(pressure);
  }
}

void ButtonClass::setParentApp(AppClass* new_parent_app) {
  if (parent_app) {
    parent_app->deregisterButton(this);
  }

  if (new_parent_app) {
    new_parent_app->registerButton(this);
  }
  
  parent_app = new_parent_app;
}