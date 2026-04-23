#include "AppClass.h"

#include "ViewportClass.h"
#include "System.h"

AppClass::AppClass() {
  // System.println("New app created, viewport assigned");
  ViewportClass* newViewport_ptr = new ViewportClass(-1);
  viewport = newViewport_ptr;
}

void AppClass::loop() {}

void AppClass::setup() {}

void AppClass::quit() {}