#pragma once

#include <HardwareSerial.h>

class GPSClass {
  public:
    void init();
};

namespace GPSInterface {
  extern GPSClass GPS;
  extern HardwareSerial gpsSerial;

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
}