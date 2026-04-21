#include "SDCardInterface.h"

SDCardClass SDCard = SDCardClass();

bool SDCardInterface::SD_card_mounted = false;

void SDCardInterface::init() {
  // SD card
  if (!SD.begin()) {
    Serial.println("Card Mount Failed");
    SystemTerminalApp.printLine("Card Mount Failed");
    SD_card_mounted = false;
    return;
  }
  SystemTerminalApp.printLine("Card Mount Successful");
  uint8_t cardType = SD.cardType();
  
  SD_card_mounted = true;

  Serial.print("SD Card Type: ");
  if (cardType == CARD_MMC) {
    Serial.println("MMC");
  } else if (cardType == CARD_SD) {
    Serial.println("SDSC");
  } else if (cardType == CARD_SDHC) {
    Serial.println("SDHC");
  } else {
    Serial.println("UNKNOWN");
  }
  
  if (!SD.exists("/positions.csv")) { 
    SDCard.writeFile("/positions.csv", "count, timestamp, latitude, longitude, altitude, tags\n"); 
  }
}

void SDCardInterface::loop() {
  
}

void SDCardClass::listDir(const char *dirname, uint8_t levels) {
  Serial.printf("Listing directory: %s\n", dirname);

  File root = SD.open(dirname);
  if (!root) {
    Serial.println("Failed to open directory");
    return;
  }
  if (!root.isDirectory()) {
    Serial.println("Not a directory");
    return;
  }

  File file = root.openNextFile();
  while (file) {
    if (file.isDirectory()) {
      Serial.print("  DIR : ");
      Serial.println(file.name());
      if (levels) {
        listDir(file.path(), levels - 1);
      }
    } else {
      Serial.print("  FILE: ");
      Serial.print(file.name());
      Serial.print("  SIZE: ");
      Serial.println(file.size());
    }
    file = root.openNextFile();
  }
}

void SDCardClass::createDir(const char *path) {
  Serial.printf("Creating Dir: %s\n", path);
  if (SD.mkdir(path)) {
    Serial.println("Dir created");
  } else {
    Serial.println("mkdir failed");
  }
}

void SDCardClass::removeDir(const char *path) {
  Serial.printf("Removing Dir: %s\n", path);
  if (SD.rmdir(path)) {
    Serial.println("Dir removed");
  } else {
    Serial.println("rmdir failed");
  }
}

void SDCardClass::readFile(const char *path) {
  Serial.printf("Reading file: %s\n", path);

  File file = SD.open(path);
  if (!file) {
    Serial.println("Failed to open file for reading");
    return;
  }

  Serial.print("Read from file: ");
  while (file.available()) {
    Serial.write(file.read());
  }
  file.close();
}

void SDCardClass::writeFile(const char *path, const char *message) {
  Serial.printf("Writing file: %s\n", path);

  File file = SD.open(path, FILE_WRITE);
  if (!file) {
    Serial.println("Failed to open file for writing");
    return;
  }
  if (file.print(message)) {
    Serial.println("File written");
  } else {
    Serial.println("Write failed");
  }
  file.close();
}

bool SDCardClass::appendFile(const char *path, const char *message) {
  Serial.printf("Appending to file: %s\n", path);

  File file = SD.open(path, FILE_APPEND);
  if (!file) {
    Serial.println("Failed to open file for appending");
    return false;
  }
  if (file.print(message)) {
    Serial.println("Message appended");
  } else {
    Serial.println("Append failed");
  }
  file.close();

  return true;
}

void SDCardClass::renameFile(const char *path1, const char *path2) {
  Serial.printf("Renaming file %s to %s\n", path1, path2);
  if (SD.rename(path1, path2)) {
    Serial.println("File renamed");
  } else {
    Serial.println("Rename failed");
  }
}

void SDCardClass::deleteFile(const char *path) {
  Serial.printf("Deleting file: %s\n", path);
  if (SD.remove(path)) {
    Serial.println("File deleted");
  } else {
    Serial.println("Delete failed");
  }
}