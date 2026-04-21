#pragma once

#include <XPT2046_Touchscreen.h>
#include "SPI.h"

namespace TouchScreenInterface {
  void init();
  void loop();

  extern SPIClass mySpi;
}

extern XPT2046_Touchscreen Touchscreen;