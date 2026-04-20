#pragma once

#include "FS.h"
#include "SD.h"

class SDCardClass {
  public:
    void init();

    void listDir(const char *dirname, uint8_t levels);
    void createDir(const char *path);
    void removeDir(const char *path);
    void readFile(const char *path);
    void writeFile(const char *path, const char *message);
    bool appendFile(const char *path, const char *message);
    void renameFile(const char *path1, const char *path2);
    void deleteFile(const char *path);

    bool has_SD_card = false;
};

namespace SDCardInterface {
  extern SDCardClass SDCard;
}
