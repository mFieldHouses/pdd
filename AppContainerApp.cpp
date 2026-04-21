#include "AppContainerApp.h"

AppContainerApp MainAppContainer = AppContainerApp();

void AppContainerApp::setContainedApp(AppClass* app) {
  Serial.println("set contained app");
  this->containedApp = app;

  app->viewport = subViewport;
}

void AppContainerApp::setup() {
}

void AppContainerApp::loop() {
  if (containedApp != nullptr) {
    containedApp->loop();
  }
}