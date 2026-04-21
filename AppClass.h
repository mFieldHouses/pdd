#pragma once

#include "ViewportClass.h"

// Base class for other apps. Has no .cpp file.

class AppClass {
  protected:
    virtual void loop();
    virtual void setup();

    ViewportClass* viewport = nullptr;
  
  friend class SystemClass;
  friend class AppContainerApp;
};