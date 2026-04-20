#pragma once

#include <TFT_eSPI.h>

class DisplayInterfaceClass {

  public:
    void init();

};

namespace DisplayInterface {
  //void display_init();

  extern DisplayInterfaceClass DisplayInterfaceObj;
  extern TFT_eSPI Display;
}