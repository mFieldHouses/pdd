#pragma once

#include <Arduino.h>
#include <vector>

#include "AppClass.h"
#include "Terminal.h"

class SystemTerminalAppClass : public AppClass, public Terminal {
  public:
    SystemTerminalAppClass();

    void println(const String& line) override;

  protected:
    virtual void loop() override;
    virtual void setup() override;

  private:
    void draw();

    std::vector<String> log_lines;
    const int MAX_LOG_LINES = 30;
};

extern SystemTerminalAppClass SystemTerminalApp;