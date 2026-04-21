#pragma once

#include <Arduino.h>

#include "FS.h"
#include "SD.h"

#include "SystemTerminalApp.h"

class SDCardClass {
  public:
    void listDir(const char *dirname, uint8_t levels);
    void createDir(const char *path);
    void removeDir(const char *path);
    void readFile(const char *path);
    void writeFile(const char *path, const char *message);
    bool appendFile(const char *path, const char *message);
    void renameFile(const char *path1, const char *path2);
    void deleteFile(const char *path);
};

namespace SDCardInterface {
  extern bool SD_card_mounted;
  
  void init();
  void loop();
}

extern SDCardClass SDCard;
