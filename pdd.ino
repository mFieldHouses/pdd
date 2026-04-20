#include "DisplayInterface.h"
using namespace DisplayInterface;

#include "TouchScreenInterface.h"
using namespace TouchScreenInterface;

#include "SDCardInterface.h"
using namespace SDCardInterface;

#include "System.h"

#include "GPSInterface.h"
using namespace GPSInterface;

void setup() {
  Serial.begin(115200);

  DisplayInterfaceObj.init();
  touchscreen_init();
  SDCard.init();
  System.init();
  GPS.init();

}

int16_t rgbToInt(float r, float b, float g) {
  return 0;
}

void loop() {
  // if (ts.tirqTouched() && ts.touched()) {
  //   TS_Point point = ts.getPoint();
  //   appendLogLine(String(point.x));
  //   delay(100);
  // }

  while (gpsSerial.available()) {
    String line = gpsSerial.readStringUntil('\n');

    if (line.startsWith("$GNGGA")) {
      GPSPoint new_point;
      nmeaGGAToGPSPoint(line, new_point);

      SystemTerminal.printLine(GPSPointToString(new_point));

      if (new_point.valid) {
      SDCard.appendFile("/positions.csv", GPSPointToCSV(new_point).c_str());
      //appendLogLine("appended line to SD");
    }
    }
  }

}