#include "AppClass.h"

#include "ViewportClass.h"
#include "System.h"

#include <algorithm>

AppClass::AppClass() {
  // System.println("New app created, viewport assigned");
  // ViewportClass* newViewport_ptr = new ViewportClass(-1);
  // viewport = newViewport_ptr;
}

void AppClass::registerButton(ButtonClass* child_button) {
  auto it = std::ranges::find(child_buttons.begin(), child_buttons.end(), child_button);

  if (it != child_buttons.end()) {
    System.println("Could not register child button because it is\nalready a child of the specified app.");
    return;
  }

  if(viewport != nullptr) {
    viewport->registerButton(child_button);
  }

  child_buttons.push_back(child_button);
}

void AppClass::deregisterButton(ButtonClass* child_button) {
  auto it = std::ranges::find(child_buttons.begin(), child_buttons.end(), child_button);

  if (it == child_buttons.end()) {
    System.println("Could not deregister child button because it was\nnever a child of the specified app.");
    return;
  }

  if(viewport != nullptr) {
    viewport->deregisterButton(child_button);
  }

  child_buttons.erase(it);
}

void AppClass::setViewport(ViewportClass* new_viewport) {
  System.println("set viewport of app");
  for (ButtonClass* btn : child_buttons) {
    Serial.println("registering button to new viewport");
    
    if (viewport != nullptr) {
      viewport->deregisterButton(btn);
    }
    
    if (new_viewport != nullptr) {
      new_viewport->registerButton(btn);
    }
  }
  
  viewport = new_viewport;
}