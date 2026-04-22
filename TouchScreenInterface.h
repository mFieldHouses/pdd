#pragma once

#include <XPT2046_Touchscreen.h>
#include "SPI.h"

#define TOUCH_RADIUS 10

// Values used for calibration/correction.
#define TS_TOP 350
#define TS_BOTTOM 3700
#define TS_LEFT 300
#define TS_RIGHT 3700

#define TS_WIDTH (TS_RIGHT - TS_LEFT)
#define TS_HEIGHT (TS_BOTTOM - TS_TOP)

namespace TouchScreenInterface {
  void init();
  void loop();

  void calibrateTSPoint(TS_Point& point);

  extern SPIClass mySpi;

  extern bool _previouslyTouched;
}

extern XPT2046_Touchscreen Touchscreen;