#pragma once

#include <vector>
#include "DisplayInterface.h"
using namespace DisplayInterface;

class SystemTerminalClass {
  private:
    void drawLog();

    std::vector<String> log_lines;
    const int MAX_LOG_LINES = 10;
  
  public:
    void printLine(const String& line);
};

class SystemClass {
  public:
    void init();
};

extern SystemClass System;
extern SystemTerminalClass SystemTerminal;