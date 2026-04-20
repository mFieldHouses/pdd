#include "TouchScreenInterface.h"

#define XPT2046_IRQ 36
#define XPT2046_MOSI 32
#define XPT2046_MISO 39
#define XPT2046_CLK 25
#define XPT2046_CS 33

SPIClass TouchScreenInterface::mySpi = SPIClass(VSPI);
XPT2046_Touchscreen TouchScreenInterface::ts(XPT2046_CS, XPT2046_IRQ);

void TouchScreenInterface::touchscreen_init() {
  mySpi.begin(XPT2046_CLK, XPT2046_MISO, XPT2046_MOSI, XPT2046_CS);
  ts.begin(mySpi);
  ts.setRotation(1);
}