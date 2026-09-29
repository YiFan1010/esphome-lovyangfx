#pragma once

#include "esphome/components/display/display_buffer.h"

namespace esphome {
namespace lovyangfx {

class LovyanGFXDisplay : public display::DisplayBuffer {
 public:
  void setup() override;
  void update() override;

 protected:
  int get_width_internal() override { return 320; }
  int get_height_internal() override { return 480; }

  void draw_absolute_pixel_internal(int x, int y, Color color) override;
};

}  // namespace lovyangfx
}  // namespace esphome
