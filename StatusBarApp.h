#pragma once

#include "AppClass.h"
#include <Arduino.h>

#define FLAG_GPS_OK 0b00000001
#define FLAG_SD_CARD_OK 0b00000010

class ButtonClass;

class StatusBarAppClass : public AppClass {
  private:
    String message; // Usually to tell the time, can be used to display notification or other things.
    float battery_percentage = 1.0; // Factor from 1.0 to 0.0.

    uint8_t flags = 0;
  
  protected:
    virtual void loop() override;
    virtual void setup() override;
  
  public:
    void setMessage(const String& message);
    void setMesssageFromNMEATime(int time);
  
  friend class SystemClass;
  friend class AppContainerApp;
};

extern StatusBarAppClass StatusBarApp;
extern ButtonClass test_button;