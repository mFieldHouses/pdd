#pragma once

#include <Arduino.h>
#include <vector>

class ViewportClass;

class ButtonClass;

class AppClass {
  public:
    AppClass();

    virtual void quit() = 0;
    virtual void draw() = 0; // Called when the whole app ought to redraw. Should draw the complete state of this app. You usually want to call this at the end of setup(), too.

    void registerButton(ButtonClass*);
    void deregisterButton(ButtonClass*);

    void setViewport(ViewportClass*);
    inline ViewportClass* getViewport() {
      return viewport;
    }

  protected:
    virtual void loop() = 0;
    virtual void setup() = 0;

    ViewportClass* viewport = nullptr;

  private:
    std::vector<ButtonClass*> child_buttons;

  friend class SystemClass;
  friend class AppContainerApp;
};