#pragma once

#include <Arduino.h>

#include "AppClass.h"
#include "AppMenuApp.h"
#include "AppContainerApp.h"
#include "StatusBarApp.h"

// class SystemTerminalClass {
//   private:
//     void drawLog();

//     std::vector<String> log_lines;
//     const int MAX_LOG_LINES = 10;
  
//   public:
//     void printLine(const String& line);
// };

class SystemClass {
  public:
    void init();
    void loop();

    void launchApp(AppClass* app, bool standalone);
    void closeApp();

    AppClass* currentApp = nullptr; // Should only really be an AppContainerApp, but can be standalone apps as well.
};

extern SystemClass System;
// extern SystemTerminalClass SystemTerminal;