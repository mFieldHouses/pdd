#include "System.h"

#include "AppClass.h"
#include "AppMenuApp.h"
#include "AppContainerApp.h"
#include "StatusBarApp.h"

SystemClass System = SystemClass();
//SystemTerminalClass SystemTerminal = SystemTerminalClass();

void SystemClass::init() {
  System.println("System init");
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

void SystemClass::setTerminal(Terminal* terminal) {
  this->terminal = terminal;
}

void SystemClass::println(const String& message) {
  Serial.print("[Terminal] - ");
  Serial.println(message);
  
  if (terminal) {
    terminal->println(message);
  }
}

void SystemClass::println(const char message[]) {
  Serial.print("[Terminal] - ");
  Serial.println(message);
  
  if (terminal) {
    terminal->println(String(message));
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
