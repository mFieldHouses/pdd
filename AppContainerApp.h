#pragma once

#include "AppClass.h"

class AppContainerApp : public AppClass {
  public:
    AppClass* containedApp = nullptr;

    void setup() override;
    void loop() override;
};

extern AppContainerApp MainAppContainer;