#pragma once

#include <Arduino.h>
#include "Terminal.h"

class AppClass;

enum MessageType {MESSAGE, WARNING, ERROR};

class SystemClass {
  private:
    Terminal* terminal = nullptr;

  public:
    void init();
    void loop();

    void launchApp(AppClass* app, bool standalone);
    void closeApp();

    void setTerminal();

    void println(const String& message);
    void println(const char message[]);

    void setTerminal(Terminal*);

    AppClass* currentApp = nullptr; // Should only really be an AppContainerApp, but can be standalone apps as well.
};

extern SystemClass System;
// extern SystemTerminalClass SystemTerminal;