#pragma once

#include <TFT_eSPI.h>

namespace DisplayInterface {
  void init();
  void loop();
}

extern TFT_eSPI Display;