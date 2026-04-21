#include "SystemTerminalApp.h"
#include "ViewportClass.h"

SystemTerminalAppClass SystemTerminalApp = SystemTerminalAppClass();

void SystemTerminalAppClass::printLine(const String &line) {

}

void SystemTerminalAppClass::draw() {
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