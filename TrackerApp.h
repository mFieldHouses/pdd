#pragma once

#include <Arduino.h>
#include <vector>

#include "AppClass.h"

class TrackerAppClass : public AppClass {
  public:
    TrackerAppClass();

  protected:
    void loop() override;
    void setup() override;
    void draw() override;
    void quit() override;

};

extern TrackerAppClass TrackerApp;