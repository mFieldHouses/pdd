#include "AppMenuApp.h"

#include "System.h"
#include "ViewportClass.h"
#include "ButtonClass.h"
#include "SystemTerminalApp.h"
#include "TrackerApp.h"

AppMenuApp MainMenuApp = AppMenuApp();

AppMenuApp::AppMenuApp() {}

void AppMenuApp::loop() {}

void AppMenuApp::quit() {}

void AppMenuApp::draw() {
  viewport->fill(TFT_BLACK);
  viewport->drawString("main menu app", 20, 20, 1);
  terminal_button->draw();
  tracker_button->draw();
}

void AppMenuApp::setup() {
  System.println("Opening main menu");

  if (!this->terminal_button) {
    System.println("Setting up main menu buttons");
    this->terminal_button = new ButtonClass(this);
    this->terminal_button->offset_x = 50;
    this->terminal_button->offset_y = 50;

    this->terminal_button->size_x = 70;
    this->terminal_button->size_y = 70;

    this->terminal_button->setPressedCallback(
      [&System, &SystemTerminalApp](int _x){
        System.launchApp(&SystemTerminalApp, false);
      }
    );

    this->tracker_button = new ButtonClass(this);
    this->tracker_button->offset_x = 130;
    this->tracker_button->offset_y = 50;

    this->tracker_button->size_x = 70;
    this->tracker_button->size_y = 70;

    this->tracker_button->setPressedCallback(
      [&System, &SystemTerminalApp](int _x){
        System.launchApp(&TrackerApp, false);
      }
    );
  }

  draw();
}