#include "ButtonClass.h"
#include "DisplayInterface.h"
#include "System.h"

ButtonClass::ButtonClass() {
  
}

void ButtonClass::draw() {
  //System.println("draw button");
  parent_viewport->drawRect(offset_x, offset_y, size_x, size_y, TFT_WHITE);
}

bool ButtonClass::isGlobalPointWithin(int32_t px, int32_t py, uint pr) {
  int32_t global_offset_x = offset_x;
  int32_t global_offset_y = offset_y;

  parent_viewport->resolveCoords(global_offset_x, global_offset_y);

  

  return !(
    (px + pr < global_offset_x || px - pr > global_offset_x + size_x) && (py + pr < global_offset_y || py - pr > global_offset_y + size_y) // This doesn't yet work entirely as I want it to work
  );
}

void ButtonClass::press(uint pressure) {
  System.println("Button got pressed!");
}

void ButtonClass::setParentViewport(ViewportClass* new_parent_viewport) {
  if (!new_parent_viewport) {
    return;
  }
  
  if (parent_viewport) {
    parent_viewport->deregisterButton(this);
  }

  new_parent_viewport->registerButton(this);
  
  parent_viewport = new_parent_viewport;
}