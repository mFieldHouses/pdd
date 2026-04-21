#pragma once

#include <Arduino.h>

#include <HardwareSerial.h>
#include "SystemTerminalApp.h"
#include "SDCardInterface.h"

// class GPSClass {
  // double getCurrentLongitude();
  // double getCurrentLatitude();
// };

namespace GPSInterface {
  // extern GPSClass GPS;

  struct GPSPoint {
    bool valid = false;
    int8_t time_h = 0;
    int8_t time_m = 0;
    int8_t time_s = 0;
    int8_t quality = 0;
    int8_t error = 99.99;
    double longitude = 0.0;
    double latitude = 0.0;
    float altitude = 0.0;
    int8_t velocity = 0.0;
    int8_t visible_sattelites = 0;
  };

  void nmeaGGAToGPSPoint(String gga_string, GPSPoint& output_point);
  String GPSPointToString(GPSPoint& point);
  String GPSPointToCSV(GPSPoint& point);
  String formatNMEA(const String& nmea_string);

  void init();
  void loop();
}

extern HardwareSerial GPS;