#pragma once

#include "AppClass.h"
#include "ViewportClass.h"
#include "SystemTerminalApp.h"
#include "StatusBarApp.h"

#define STATUS_BAR_HEIGHT 20

class AppContainerApp : public AppClass {

  public:
    AppContainerApp() {
      subViewport = new ViewportClass();
      subViewport->size_x = DisplayInterface::getDisplayWidth();
      subViewport->size_y = DisplayInterface::getDisplayHeight() - STATUS_BAR_HEIGHT;
      subViewport->offset_y = STATUS_BAR_HEIGHT;
      subViewport->is_root_viewport = false;
      subViewport->parent_viewport = &MainViewport;

      statusBarViewport = new ViewportClass();
      statusBarViewport->size_x = DisplayInterface::getDisplayWidth();;
      statusBarViewport->size_y = STATUS_BAR_HEIGHT;
      statusBarViewport->offset_y = 0;
      StatusBarApp.viewport = statusBarViewport;
      statusBarViewport->is_root_viewport = false;
      statusBarViewport->parent_viewport = &MainViewport;
    }

    AppClass* containedApp = nullptr;
    
    ViewportClass* subViewport = nullptr;
    ViewportClass* statusBarViewport = nullptr;

    void setup() override;
    void loop() override;

    void setContainedApp(AppClass* app);

};

extern AppContainerApp MainAppContainer;