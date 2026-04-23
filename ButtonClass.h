#include <functional>
#include <Arduino.h>


class AppClass;
class ViewportClass;

class ButtonClass {
  private:
    AppClass* parent_app = nullptr;
  public:
    ButtonClass(AppClass*);

    std::function<void(int)> pressed_callback;
    void setPressedCallback(std::function<void(int)> func);

    void press(uint);

    bool isPointWithin(int32_t x, int32_t y, uint r); // Probably want to take this out of some base class that buttons would share with viewports. Rect-something?

    void draw();
    void drawFilled();
    void setParentApp(AppClass*);

    uint size_x = 10;
    uint size_y = 10;

    uint offset_x = 0;
    uint offset_y = 0;

    bool visible = true;

    bool outline_enabled = true;
    uint32_t outline_color = 0xFFFF;
};