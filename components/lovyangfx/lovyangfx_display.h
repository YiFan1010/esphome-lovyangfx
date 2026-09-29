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

  display::DisplayType get_display_type() override {
    return display::DisplayType::DISPLAY_TYPE_COLOR;
  }

 protected:
  void draw_absolute_pixel_internal(int x, int y, display::Color color) override;

  int get_width_internal() override {
    return 320;
  }

  int get_height_internal() override {
    return 480;
  }

 private:
  LGFX lcd_;
};

}  // namespace lovyangfx
}  // namespace esphome
