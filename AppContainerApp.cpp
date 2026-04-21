#include "AppContainerApp.h"

AppContainerApp MainAppContainer = AppContainerApp();

void AppContainerApp::setup() {

}

void AppContainerApp::loop() {
  if (containedApp != nullptr) {
    containedApp->loop();
  }
}