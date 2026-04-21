#pragma once

#include <TFT_eSPI.h>

#define DISPLAY_WIDTH TFT_HEIGHT // These have been switched around because the display views the current orientation as turned by 90 degrees. So the width becomes the height and vice versa.
#define DISPLAY_HEIGHT TFT_WIDTH

namespace DisplayInterface {
  void init();
  void loop();

  int getDisplayWidth();
  int getDisplayHeight();
}

extern TFT_eSPI Display;