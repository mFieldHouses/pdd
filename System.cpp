#include "System.h"

SystemClass System = SystemClass();
SystemTerminalClass SystemTerminal = SystemTerminalClass();

void SystemTerminalClass::printLine(const String& line) {
  log_lines.insert(log_lines.begin(), line);
  
  if (log_lines.size() > MAX_LOG_LINES) {
    log_lines.pop_back();
  }
  
  drawLog();
}

void SystemTerminalClass::drawLog() {
  for (int i = 0; i < log_lines.size(); i++) {
    
    if (i == log_lines.size() - 1) {
      Display.setTextColor(TFT_DARKGREY, TFT_BLACK);
    }
    else {
      Display.setTextColor(TFT_WHITE, TFT_BLACK);
    }

    int y = i * 10;
    String line = log_lines[i];
    Display.drawString(line, 5, y, 1);
  }

    int x = 5;
    int y = 10;
}

void SystemClass::init() {

}