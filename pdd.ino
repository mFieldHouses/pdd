#include "AppClass.h"
#include "ViewportClass.h"

#include "System.h"

#include "DisplayInterface.h"
#include "TouchScreenInterface.h"
#include "SDCardInterface.h"
#include "GPSInterface.h"

#include "AppContainerApp.h" // This app always runs and provides a viewport for other apps and the statusbar on top.

#include "AppMenuApp.h" // This is the "home screen" of the device.

#include "SystemTerminalApp.h"

void setup() {
  Serial.begin(115200);
  Serial.println("main setup");
  System.init();

  DisplayInterface::init();
  TouchScreenInterface::init();
  SDCardInterface::init();
  GPSInterface::init();
}

// int16_t rgbToInt(float r, float b, float g) {
//   return 0;
// }

void loop() {
  Serial.println("main loop");
  System.loop();

  DisplayInterface::loop();
  TouchScreenInterface::loop();
  SDCardInterface::loop();
  GPSInterface::loop();
  // if (ts.tirqTouched() && ts.touched()) {
  //   TS_Point point = ts.getPoint();
  //   appendLogLine(String(point.x));
  //   delay(100);
  // }

}