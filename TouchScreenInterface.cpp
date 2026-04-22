#include "TouchScreenInterface.h"

#include "ViewportClass.h"
#include "DisplayInterface.h"
#include "System.h"

#define XPT2046_IRQ 36
#define XPT2046_MOSI 32
#define XPT2046_MISO 39
#define XPT2046_CLK 25
#define XPT2046_CS 33

SPIClass TouchScreenInterface::mySpi = SPIClass(VSPI);
XPT2046_Touchscreen Touchscreen(XPT2046_CS, XPT2046_IRQ);

bool TouchScreenInterface::_previouslyTouched = false;

void TouchScreenInterface::calibrateTSPoint(TS_Point& point) {
  point.x = int((float(point.x - TS_LEFT) / float(TS_WIDTH)) * float(DISPLAY_WIDTH));
  point.y = int((float(point.y - TS_TOP) / float(TS_HEIGHT)) * float(DISPLAY_HEIGHT));
}

void TouchScreenInterface::init() {
  TouchScreenInterface::mySpi.begin(XPT2046_CLK, XPT2046_MISO, XPT2046_MOSI, XPT2046_CS);
  Touchscreen.begin(TouchScreenInterface::mySpi);
  Touchscreen.setRotation(1);
}

void TouchScreenInterface::loop() {
  //System.println("touchscreen loop");
  bool touched = Touchscreen.tirqTouched() && Touchscreen.touched();
  
  if (touched && !_previouslyTouched) {
    TS_Point point = Touchscreen.getPoint();
    calibrateTSPoint(point);

    MainViewport.fingerDown((int32_t)point.x, (int32_t)point.y, (int32_t)point.z);
  }

  if (!touched && _previouslyTouched) {
    MainViewport.fingerUp();
  }

  _previouslyTouched = touched;
}