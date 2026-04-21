#include "TouchScreenInterface.h"

#define XPT2046_IRQ 36
#define XPT2046_MOSI 32
#define XPT2046_MISO 39
#define XPT2046_CLK 25
#define XPT2046_CS 33

SPIClass TouchScreenInterface::mySpi = SPIClass(VSPI);
XPT2046_Touchscreen Touchscreen(XPT2046_CS, XPT2046_IRQ);

void TouchScreenInterface::init() {
  TouchScreenInterface::mySpi.begin(XPT2046_CLK, XPT2046_MISO, XPT2046_MOSI, XPT2046_CS);
  Touchscreen.begin(TouchScreenInterface::mySpi);
  Touchscreen.setRotation(1);
}

void TouchScreenInterface::loop() {
  
}