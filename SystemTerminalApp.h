#pragma once

#include <Arduino.h>
#include <vector>

class SystemTerminalAppClass {
  public:
    void loop();
    void printLine(const String& line);

  private:
    void draw();

    std::vector<String> log_lines;
    const int MAX_LOG_LINES = 10;
};

extern SystemTerminalAppClass SystemTerminalApp;