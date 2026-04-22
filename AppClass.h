#pragma once

#include <Arduino.h>

class ViewportClass;

class AppClass {
  public:
    AppClass();

    virtual void quit();

  protected:
    virtual void loop();
    virtual void setup();

    ViewportClass* viewport = nullptr;

  // private:
  //   String app_id;
  //   inline const String& getAppId() {return this->app_id;};

  friend class SystemClass;
  friend class AppContainerApp;
};