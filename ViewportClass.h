#pragma once

#include <Arduino.h>
#include <vector>

#include "DisplayInterface.h"

class ButtonClass;

class ViewportClass {
  private:

    uint16_t text_foreground_color;
    uint16_t text_background_color;

    inline void resolveCoords(int32_t& x, int32_t& y) {
          ViewportClass* v = this;
          while (!v->is_root_viewport) {
              x += v->offset_x;
              y += v->offset_y;
              v = v->parent_viewport;
          }
      }

    ViewportClass* parent_viewport = nullptr;
    std::vector<ViewportClass*> child_viewports;

    std::vector<ButtonClass*> child_buttons;

  public:
    bool is_root_viewport = true;

    void setParentViewport(ViewportClass* new_parent_viewport);
    ViewportClass* getParentViewport();

    void registerChildViewport(ViewportClass*);
    void deregisterChildViewport(ViewportClass*);

    void registerButton(ButtonClass*);
    void deregisterButton(ButtonClass*);

    inline void drawString(const String& string, int32_t x, int32_t y, uint8_t font) {
        if (x < -10 || x > this->size_x || y < -10 || y > this->size_y) {
          //Serial.println("cull string");
          return;
        }

        resolveCoords(x, y);
        Display.setTextColor(this->text_foreground_color, this->text_background_color);
        Display.drawString(string, x, y, font);
    }

    inline void drawFastHLine(int32_t x, int32_t y, int32_t w, uint32_t color) {
      resolveCoords(x, y);
      Display.drawFastHLine(x, y, w, color);
    }

    inline void drawRect(int32_t x, int32_t y, int32_t w, int32_t h, uint32_t color) {
      resolveCoords(x, y);
      Display.drawRect(x, y, w, h, color);
    }

    inline void setTextColor(uint16_t fgcolor, uint16_t bgcolor) {
      this->text_foreground_color = fgcolor;
      this->text_background_color = bgcolor;
    }

    int getHeight();
    int getWidth();
    int getOffsetX();
    int getOffsetY();

    bool isGlobalPointWithin(int32_t x, int32_t y, uint r);

    // Offsets are relative to parent viewport. If this Viewport is a root Viewport, offsets will have no effect.
    int offset_y = 0;
    int offset_x = 0;
    
    int size_x = 10;
    int size_y = 10;

    void fingerDown(int32_t x, int32_t y, uint pressure);
    void fingerUp();

    friend class ButtonClass;
};

extern ViewportClass MainViewport;