#pragma once

#include "ViewportClass.h"
#include <Arduino.h>

class AppClass {
  public:
    AppClass();

    void close();

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