#include "ViewportClass.h"

class ButtonClass {
  private:
    ViewportClass* parent_viewport = nullptr;
  public:
    ButtonClass();

    void (*pressed_callback)(int) = 0;

    void press(uint);

    bool isGlobalPointWithin(int32_t x, int32_t y, uint r); // Probably want to take this out of some base class that buttons would share with viewports. Rect-something?

    void draw();
    void setParentViewport(ViewportClass*);

    uint size_x = 10;
    uint size_y = 10;

    uint offset_x = 0;
    uint offset_y = 0;
};