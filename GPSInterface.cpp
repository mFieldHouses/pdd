#include "GPSInterface.h"

//GPSClass GPSInterface::GPS = GPSClass();
HardwareSerial GPS = HardwareSerial(2);

void GPSInterface::init() {
  GPS.begin(9600, SERIAL_8N1, 22, 23);
}

void GPSInterface::loop() {
  while (GPS.available()) {
    String line = GPS.readStringUntil('\n');

    if (line.startsWith("$GNGGA")) {
      GPSInterface::GPSPoint new_point;
      GPSInterface::nmeaGGAToGPSPoint(line, new_point);

      System.println(GPSInterface::GPSPointToString(new_point));

      if (new_point.valid) {
        //SDCard.appendFile("/positions.csv", GPSPointToCSV(new_point).c_str());
        //appendLogLine("appended line to SD");
      }
    }
  }
}

void GPSInterface::nmeaGGAToGPSPoint(String gga_string, GPSPoint& output_point) {
  int index = 0;
  int next_comma_pos = gga_string.indexOf(",");
  while (next_comma_pos >= 0) {

    if (next_comma_pos == 0) {
      output_point.valid = false;
      return;
    }

    String substr = gga_string.substring(0, next_comma_pos);

    // Following the structure described on https://aprs.gids.nl/nmea/#gga
    switch (index) {
      case 0: // &GNGGA
        break;
      case 1: // Timestamp
        {
        int hour = substr.substring(0,2).toInt();
        int minute = substr.substring(2,4).toInt();
        int second = substr.substring(4,6).toInt();
        output_point.time_h = (int8_t)hour;
        output_point.time_m = (int8_t)minute;
        output_point.time_s = (int8_t)second;

        if (hour == 0 && minute == 0 && second == 0) {
          output_point.valid = false;
        }
        }
        break;
      case 2: // Latitude
        output_point.latitude = substr.toFloat();
        break;
      case 3: // N/S
        break;
      case 4: // Longitude
        output_point.longitude = substr.toFloat();
        break;
      case 5: // E/W
        break;
      case 6: // Quality
        {
          int quality = substr.toInt();
          output_point.quality = quality;

          if (quality == 0) {
            output_point.valid = false;
            return;
          }
          else {
            output_point.valid = true;
          }

          break;
        }
      case 7: // Number of visible sattelites
        output_point.visible_sattelites = substr.toInt();
        break;
      case 8: // Error
        output_point.error = (int8_t)(substr.toFloat() / 100.0) * 255;
        break;
      case 9: // Altitude
        output_point.altitude = substr.toFloat();
        break;
      default:
        break;
    }

    gga_string = gga_string.substring(next_comma_pos + 1, gga_string.length() - 1);
    next_comma_pos = gga_string.indexOf(",");

    index++;
  }
}

String GPSInterface::GPSPointTimeString(GPSPoint &point) {
  String time_h_str = String(point.time_h);
  String time_m_str = String(point.time_m);
  String time_s_str = String(point.time_s);

  // Padding
  if (time_h_str.length() == 1) {
    time_h_str = "0" + time_h_str;
  }

  if (time_m_str.length() == 1) {
    time_m_str = "0" + time_m_str;
  }

  if (time_s_str.length() == 1) {
    time_s_str = "0" + time_s_str;
  }

  return time_h_str + ":" + time_m_str + ":" + time_s_str;
}

String GPSInterface::GPSPointToString(GPSPoint& point) {
  String result_string;

  if (point.valid) {
    String lat_str = String(point.latitude, 6);
    String lon_str = String(point.longitude, 6);

    // Padding of strings
    if (lat_str.length() < 11) {
      for (int i = 0; i < 11 - lat_str.length(); i++) {
        lat_str = "0" + lat_str;
      }
    }

    if (lon_str.length() < 11) {
      for (int i = 0; i < 11 - lon_str.length(); i++) {
        lon_str = "0" + lon_str;
      }
    }

    result_string = "V) " + 
    GPSPointTimeString(point) +
    " - " +
    lat_str + 
    "/" + 
    lon_str
    ;
  }
  else {
    result_string = "NV) " +
    GPSPointTimeString(point) +
    " - Could not resolve position";
  }
  return result_string;
}

String GPSInterface::GPSPointToCSV(GPSPoint& point) {
  String result_string = 
  "1," +
  String(point.time_h) + 
  ":" + 
  String(point.time_m) +
  ":" +
  String(point.time_s) +
  "," +
  String(point.latitude, 6) + 
  "," + 
  String(point.longitude, 6) +
  "," + 
  String(point.altitude) +
  ",0\n"
  ;
  
  return result_string;
}

String GPSInterface::formatNMEA(const String& nmea_string) {
  
  GPSPoint new_point;
  nmeaGGAToGPSPoint(nmea_string, new_point);
  
  return GPSPointToString(new_point);
}

// void storeGPSPoint(GPSPoint& point_to_store) {

// }

// void parseGPSPointLine(const String& line, GPSPoint& output_point) {

// }