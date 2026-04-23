#include "DisplayInterface.h"
#include "System.h"

#include "AppClass.h"
#include "AppMenuApp.h"
#include "AppContainerApp.h"
#include "StatusBarApp.h"

SystemClass System = SystemClass();
//SystemTerminalClass SystemTerminal = SystemTerminalClass();

void SystemClass::init() {
  System.println("System init");
  MainViewport.size_x = DisplayInterface::getDisplayWidth();
  MainViewport.size_y = DisplayInterface::getDisplayHeight();
  MainViewport.is_root_viewport = true;

  MainAppContainer.setup();
  StatusBarApp.setup();

  println("launch main menu");
  launchApp(&SystemTerminalApp, false);

  //println("Display dimensions: " + String(DisplayInterface::getDisplayWidth()) + ", " + String(DisplayInterface::getDisplayHeight()));
}

void SystemClass::loop() {
  // System.println("System loop");
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
  Serial.println("launch app");
  if (app == nullptr) {
    return;
  }

  if (MainAppContainer.containedApp) {
    MainAppContainer.containedApp->setViewport(nullptr);
  }
  
  MainAppContainer.subViewport->fill(TFT_BLACK);
  StatusBarApp.draw();

  if (standalone) {
    SystemClass::currentApp = app;
  }
  
  else {
    SystemClass::currentApp = &MainAppContainer;
    MainAppContainer.setContainedApp(app);
  }

  // StatusBarApp.draw();
  app->setup();

  StatusBarApp.setAllowQuit(true);
}

void SystemClass::closeApp() {
  //println("close app");
  SystemClass::launchApp(&MainMenuApp);
  StatusBarApp.setAllowQuit(false);
}
