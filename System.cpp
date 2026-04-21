#include "System.h"
#include "AppContainerApp.h"

SystemClass System = SystemClass();
//SystemTerminalClass SystemTerminal = SystemTerminalClass();

void SystemClass::init() {
  Serial.println("system init");
  MainViewport.size_x = DISPLAY_WIDTH;
  MainViewport.size_y = DISPLAY_HEIGHT;
  MainViewport.is_root_viewport = true;

  StatusBarApp.setup();

  launchApp(&SystemTerminalApp, false);
}

void SystemClass::loop() {
  StatusBarApp.loop();

  if (currentApp != nullptr) {
    currentApp->loop();
  }
}

void SystemClass::launchApp(AppClass* app, bool standalone = false) {
  if (app == nullptr) {
    return;
  }

  if (standalone) {
    SystemClass::currentApp = app;
  }
  
  else {
    SystemClass::currentApp = &MainAppContainer;
    MainAppContainer.setContainedApp(app);
  }

  app->setup();
}

void SystemClass::closeApp() {
  SystemClass::launchApp(&MainMenuApp);
}
