#include "ViewportClass.h"

#include <algorithm>

#include "TouchScreenInterface.h"
#include "System.h"
#include "ButtonClass.h"

ViewportClass MainViewport = ViewportClass();

bool ViewportClass::isGlobalPointWithin(int32_t x, int32_t y, uint r) {
  int32_t global_offset_x = 0;
  int32_t global_offset_y = 0;

  resolveCoords(global_offset_x, global_offset_y);

  return (x + r > global_offset_x && y + r > global_offset_y && x - r < global_offset_x + size_x && y - r < global_offset_y + size_y);
}

void ViewportClass::registerChildViewport(ViewportClass* child_viewport) {
  if (std::ranges::find(child_viewports.begin(), child_viewports.end(), child_viewport) != child_viewports.end()) { // contains
    System.println("Could not register child viewport because it is\nalready a child of the specified viewport.");
    return;
  }

  child_viewports.push_back(child_viewport);
}

void ViewportClass::deregisterChildViewport(ViewportClass* child_viewport) {
  auto it = std::ranges::find(child_viewports.begin(), child_viewports.end(), child_viewport);

  if (it == child_viewports.end()) { // !contains
    System.println("Could not deregister child viewport because it was\nnever a child of the specified viewport.");
    return;
  }

  child_viewports.erase(it);
}

void ViewportClass::registerButton(ButtonClass* child_button) {
  auto it = std::ranges::find(child_buttons.begin(), child_buttons.end(), child_button);

  if (it != child_buttons.end()) {
    System.println("Could not register child button because it is\nalready a child of the specified viewport.");
    return;
  }

  child_buttons.push_back(child_button);
}

void ViewportClass::deregisterButton(ButtonClass* child_button) {
  auto it = std::ranges::find(child_buttons.begin(), child_buttons.end(), child_button);

  if (it == child_buttons.end()) {
    System.println("Could not deregister child button because it was\nnever a child of the specified viewport.");
    return;
  }

  child_buttons.erase(it);
}

void ViewportClass::setParentViewport(ViewportClass* new_parent_viewport) {
  if (!new_parent_viewport) {
    // System.println("WARNING: Parent viewport set to nullptr.\nThis will make the viewport a root viewport.");
    is_root_viewport = true;
  }
  else {
    if (parent_viewport) {
      parent_viewport->deregisterChildViewport(this);
    }

    is_root_viewport = false;

    new_parent_viewport->registerChildViewport(this);
  }
  
  parent_viewport = new_parent_viewport;
}

ViewportClass* ViewportClass::getParentViewport() {
  return parent_viewport;
}

void ViewportClass::fingerDown(int32_t x, int32_t y, uint pressure) {
  //System.println("finger down in viewport: " + String(x) + ", " + String(y));

  for (ViewportClass* vp : child_viewports) {
    if (vp->isGlobalPointWithin(x, y, 0)) {
      //System.println("propagating fingerDown to viewport");
      vp->fingerDown(x - vp->offset_x, y - vp->offset_y, pressure);
    }
  }

  for (ButtonClass* bt : child_buttons) {
    if (bt->isGlobalPointWithin(x, y, TOUCH_RADIUS)) {
      //System.println("propagating fingerDown to button");
      bt->press(pressure);
    }
  }

  // Display.drawSpot(x, y, 7, TFT_RED);
}

void ViewportClass::fingerUp() {
}