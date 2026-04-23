#include <TrackerApp.h>

#include "DisplayInterface.h"
#include "System.h"
#include "ViewportClass.h"

TrackerAppClass TrackerApp = TrackerAppClass();

TrackerAppClass::TrackerAppClass() {}

void TrackerAppClass::setup() {
  System.println("tracker app setup");
  draw();
}

void TrackerAppClass::loop() {}

void TrackerAppClass::quit() {}

void TrackerAppClass::draw() {
  viewport->fill(TFT_RED);
}