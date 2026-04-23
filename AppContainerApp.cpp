#include "AppContainerApp.h"

AppContainerApp MainAppContainer = AppContainerApp();

void AppContainerApp::setContainedApp(AppClass* app) {
  Serial.println("set contained app");
  this->containedApp = app;

  app->viewport = subViewport;
}

void AppContainerApp::setup() {
  subViewport = new ViewportClass(1);
  subViewport->size_x = DisplayInterface::getDisplayWidth();
  subViewport->size_y = DisplayInterface::getDisplayHeight() - STATUS_BAR_HEIGHT;
  subViewport->offset_y = STATUS_BAR_HEIGHT;
  subViewport->setParentViewport(&MainViewport);

  statusBarViewport = new ViewportClass(2);
  statusBarViewport->size_y = STATUS_BAR_HEIGHT;
  StatusBarApp.viewport = statusBarViewport;
  statusBarViewport->setParentViewport(&MainViewport);
}

void AppContainerApp::loop() {
  if (containedApp != nullptr) {
    containedApp->loop();
  }
}