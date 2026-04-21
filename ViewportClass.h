#pragma once

#include "DisplayInterface.h"

class ViewportClass {
  protected:
    bool is_root_viewport = true;
    ViewportClass* parent_viewport = nullptr;

    int offset_y = 0;
    int offset_x = 0;
    
    int size_x = 10;
    int size_y = 10;
  
  public:
    void setPixel();

    int getHeight();
    int getWidth();
    int getOffsetX();
    int getOffsetY();

};

extern ViewportClass MainViewport;