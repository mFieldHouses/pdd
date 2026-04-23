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

// #include "driver/gptimer.h"

uint8_t loop_counter = 0;

// timer_config_t target_config;

void setup() {
  Serial.begin(115200);
  Serial.println("main setup");

  DisplayInterface::init();
  TouchScreenInterface::init();
  SDCardInterface::init();
  GPSInterface::init();

  System.init();

  // Serial.println(target_config.alarm_en);
  // Serial.println(target_config.auto_reload);
  // Serial.println(target_config.clk_src);
  // Serial.println(target_config.counter_dir);
}

// int16_t rgbToInt(float r, float b, float g) {
//   return 0;
// }

void deferred_loop(int loop_counter) {
  if (loop_counter % 2 == 0) {}
  if (loop_counter % 3 == 0) {}
  if (loop_counter % 4 == 0) {}
  if (loop_counter % 5 == 0) {}
  if (loop_counter % 6 == 0) {}
  if (loop_counter % 10 == 0) {}
  if (loop_counter % 12 == 0) {}
  if (loop_counter % 15 == 0) {
    TouchScreenInterface::loop();
  }
  if (loop_counter % 20 == 0) {}
  if (loop_counter % 30 == 0) {
  
  }
  if (loop_counter % 60 == 0) {
    GPSInterface::loop();
  }
}

void loop() {
  //Serial.println("main loop");
  System.loop();

  DisplayInterface::loop();
  // TouchScreenInterface::loop();
  SDCardInterface::loop();
  //GPSInterface::loop();

  // System.println("Deferred loop: " + String(loop_counter));
  deferred_loop(loop_counter);

  loop_counter = (loop_counter + 1) % 60; // 60 is a number that can be divided by 2, 3, 4, 5, 6, 10, 12, 15, 20, 30 and 60 and thus has a nice set of perfectly fit loops

}