#pragma once

#include <XPT2046_Touchscreen.h>
#include "SPI.h"

namespace TouchScreenInterface {
  extern SPIClass mySpi;
  extern XPT2046_Touchscreen ts;

  void touchscreen_init();
}