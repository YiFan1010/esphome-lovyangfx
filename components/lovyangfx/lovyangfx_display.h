#pragma once

#include "esphome/components/display/display_buffer.h"

#include "LGFX.h"

namespace esphome {
namespace lovyangfx {

class LovyanGFXDisplay : public display::DisplayBuffer
{
 public:
  LovyanGFXDisplay() = default;

  void setup() override;
  void update() override;
  void dump_config() override;

  void set_width(int value) { width_ = value; }
  void set_height(int value) { height_ = value; }

  void set_frequency(uint32_t value) { frequency_ = value; }

  void set_pin_cs(int value) { pin_cs_ = value; }
  void set_pin_dc(int value) { pin_dc_ = value; }
  void set_pin_wr(int value) { pin_wr_ = value; }

  void set_pin_d0(int value) { pin_d0_ = value; }
  void set_pin_d1(int value) { pin_d1_ = value; }
  void set_pin_d2(int value) { pin_d2_ = value; }
  void set_pin_d3(int value) { pin_d3_ = value; }
  void set_pin_d4(int value) { pin_d4_ = value; }
  void set_pin_d5(int value) { pin_d5_ = value; }
  void set_pin_d6(int value) { pin_d6_ = value; }
  void set_pin_d7(int value) { pin_d7_ = value; }
  void set_pin_d8(int value) { pin_d8_ = value; }
  void set_pin_d9(int value) { pin_d9_ = value; }
  void set_pin_d10(int value) { pin_d10_ = value; }
  void set_pin_d11(int value) { pin_d11_ = value; }
  void set_pin_d12(int value) { pin_d12_ = value; }
  void set_pin_d13(int value) { pin_d13_ = value; }
  void set_pin_d14(int value) { pin_d14_ = value; }
  void set_pin_d15(int value) { pin_d15_ = value; }

  void set_rotation(int value) { rotation_ = value; }
  void set_invert(bool value) { invert_ = value; }
  void set_rgb_order(bool value) { rgb_order_ = value; }

  display::DisplayType get_display_type() override {
    return display::DisplayType::DISPLAY_TYPE_COLOR;
  }

 protected:
  void draw_absolute_pixel_internal(
      int x,
      int y,
      display::Color color) override;

  int get_width_internal() override {
    return width_;
  }

  int get_height_internal() override {
    return height_;
  }

 private:
  LGFX lcd_;

  int width_{320};
  int height_{480};

  uint32_t frequency_{10000000};

  int pin_cs_{-1};
  int pin_dc_{-1};
  int pin_wr_{-1};

  int pin_d0_{-1};
  int pin_d1_{-1};
  int pin_d2_{-1};
  int pin_d3_{-1};
  int pin_d4_{-1};
  int pin_d5_{-1};
  int pin_d6_{-1};
  int pin_d7_{-1};
  int pin_d8_{-1};
  int pin_d9_{-1};
  int pin_d10_{-1};
  int pin_d11_{-1};
  int pin_d12_{-1};
  int pin_d13_{-1};
  int pin_d14_{-1};
  int pin_d15_{-1};

  int rotation_{0};

  bool invert_{true};
  bool rgb_order_{false};
};

}  // namespace lovyangfx
}  // namespace esphome
