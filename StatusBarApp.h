#pragma once

#include "AppClass.h"
#include "ButtonClass.h"
#include <Arduino.h>

#define FLAG_GPS_OK 0b0000000000000001
#define FLAG_SD_CARD_OK 0b0000000000000010
#define FLAG_ALLOW_QUIT 0b0000000000000100

class StatusBarAppClass : public AppClass {
  private:
    String message; // Usually to tell the time, can be used to display notification or other things.
    float battery_percentage = 1.0; // Factor from 1.0 to 0.0.

    uint16_t flags = 0;

    bool allowQuit = false;
  
  protected:
    virtual void loop() override;
    virtual void setup() override;
    virtual void quit() override;
    virtual void draw() override;

    void quitCurrentApp(); // Closes the app that's running contained in the MainAppContainer, not the StatusBarApp itself
  
  public:
    void setMessage(const String& message);
    void setMesssageFromNMEATime(int time);

    void button_pressed(int);
    void test(int);

    inline void setAllowQuit(bool state) {
      allowQuit = state;
      test_button->visible = state;
      draw();
    }

    inline bool getAllowQuit() {
      return allowQuit;
    }

    ButtonClass* test_button;
  
  friend class SystemClass;
  friend class AppContainerApp;
};

extern StatusBarAppClass StatusBarApp;