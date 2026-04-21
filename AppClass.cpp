#include "AppClass.h"

AppClass::AppClass() {
  Serial.println("New app created, viewport assigned");
  ViewportClass* newViewport_ptr = new ViewportClass();
  viewport = newViewport_ptr;
}

void AppClass::loop() {}

void AppClass::setup() {}

void AppClass::close() {
  
}