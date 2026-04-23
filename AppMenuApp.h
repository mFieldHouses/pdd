#pragma once

#include "AppClass.h"

class ButtonClass;

class AppMenuApp : public AppClass {
  public:
    AppMenuApp();

    void loop() override;
    void setup() override;
    void quit() override;
    void draw() override;

    ButtonClass* terminal_button;
    ButtonClass* tracker_button;


};

extern AppMenuApp MainMenuApp;