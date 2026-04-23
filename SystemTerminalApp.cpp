#include "SystemTerminalApp.h"

#include "ViewportClass.h"
#include "System.h"

SystemTerminalAppClass SystemTerminalApp = SystemTerminalAppClass();

SystemTerminalAppClass::SystemTerminalAppClass() {
  System.setTerminal(this);
}

void SystemTerminalAppClass::setup() {
  System.println("terminal app setup");
}

void SystemTerminalAppClass::loop() {
  //System.println("terminal app loop");
}

void SystemTerminalAppClass::quit() {}

void SystemTerminalAppClass::println(const String& line) {
  String _line = line + "                                                ";

  log_lines.insert(log_lines.begin(), _line);
    
    if (log_lines.size() > MAX_LOG_LINES) {
      log_lines.pop_back();
    }
    
  draw();
}

void SystemTerminalAppClass::draw() {
  // Serial.println("draw() terminal");
  // Serial.println(String(viewport == nullptr));
  
  if (viewport == nullptr) {
    return;
  }

  //Serial.println("draw terminal app");

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
}