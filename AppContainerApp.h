#pragma once

#include "AppClass.h"
#include "ViewportClass.h"
#include "SystemTerminalApp.h"
#include "StatusBarApp.h"

#define STATUS_BAR_HEIGHT 25

class AppContainerApp : public AppClass {

  public:
    // AppContainerApp();

    AppClass* containedApp = nullptr;
    
    ViewportClass* subViewport = nullptr;
    ViewportClass* statusBarViewport = nullptr;

    void setup() override;
    void loop() override;
    void quit() override;
    void draw() override;

    void setContainedApp(AppClass* app);

};

extern AppContainerApp MainAppContainer;