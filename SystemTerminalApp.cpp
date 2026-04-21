#include "SystemTerminalApp.h"
#include "ViewportClass.h"

SystemTerminalAppClass SystemTerminalApp = SystemTerminalAppClass();

SystemTerminalAppClass::SystemTerminalAppClass() {
  // ViewportClass* newViewport_ptr = new ViewportClass();
  // this->viewport = newViewport_ptr;
}

void SystemTerminalAppClass::setup() {
  printLine("SETUP TERMINAL APP");
}

void SystemTerminalAppClass::loop() {
  //Serial.println("terminal loop func");
  //printLine("terminal app loop");
}

void SystemTerminalAppClass::printLine(const String& line) {
  log_lines.insert(log_lines.begin(), line);
    
    if (log_lines.size() > MAX_LOG_LINES) {
      log_lines.pop_back();
    }
    
  draw();
}

void SystemTerminalAppClass::draw() {
  for (int i = 0; i < log_lines.size(); i++) {
    
    if (i == log_lines.size() - 1) {
      viewport->setTextColor(TFT_DARKGREY, TFT_BLACK);
    }
    else {
      viewport->setTextColor(TFT_WHITE, TFT_BLACK);
    }

    int y = i * 10;
    String line = log_lines[i];
    viewport->drawString(line, 5, y + 5, 1);
  }

    int x = 5;
    int y = 10;
}