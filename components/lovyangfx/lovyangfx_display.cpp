#include "lovyangfx_display.h"

#include "esphome/core/log.h"
#include "esphome/components/display/display_color_utils.h"

namespace esphome {
namespace lovyangfx {

static const char *const TAG = "lovyangfx.display";

void LovyanGFXDisplay::setup()
{
  ESP_LOGCONFIG(TAG, "Setting up LovyanGFX ST7796...");

  // ------------------------------------------------------------
  // Configure LovyanGFX from ESPHome YAML
  // ------------------------------------------------------------

  this->lcd_.configure(
      this->width_,
      this->height_,
      this->frequency_,
      this->pin_cs_,
      this->pin_dc_,
      this->pin_wr_,
      this->pin_d0_,
      this->pin_d1_,
      this->pin_d2_,
      this->pin_d3_,
      this->pin_d4_,
      this->pin_d5_,
      this->pin_d6_,
      this->pin_d7_,
      this->pin_d8_,
      this->pin_d9_,
      this->pin_d10_,
      this->pin_d11_,
      this->pin_d12_,
      this->pin_d13_,
      this->pin_d14_,
      this->pin_d15_,
      this->invert_,
      this->rgb_order_);

  // ------------------------------------------------------------
  // Initialize LCD
  // ------------------------------------------------------------

  this->lcd_.init();

  this->lcd_.setColorDepth(16);

  this->lcd_.setRotation(this->rotation_);

  // ------------------------------------------------------------
  // Allocate ESPHome framebuffer
  // ------------------------------------------------------------

  const uint32_t buffer_size =
      static_cast<uint32_t>(this->width_) *
      static_cast<uint32_t>(this->height_) *
      2U;

  this->init_internal_(buffer_size);

  // ESPHome framebuffer is RGB565.
  this->lcd_.setSwapBytes(true);

  ESP_LOGCONFIG(TAG, "LovyanGFX ST7796 initialized.");
}

void LovyanGFXDisplay::update()
{
  // Render ESPHome lambda/pages into framebuffer.
  this->do_update_();

  // Push framebuffer to LCD.
  this->lcd_.pushImage(
      0,
      0,
      this->width_,
      this->height_,
      reinterpret_cast<const uint16_t *>(this->buffer_));
}

void LovyanGFXDisplay::draw_absolute_pixel_internal(
    int x,
    int y,
    display::Color color)
{
  if (x < 0 || x >= this->width_ ||
      y < 0 || y >= this->height_) {
    return;
  }

  const uint16_t color565 =
      display::ColorUtil::color_to_565(color);

  const uint32_t pos =
      (static_cast<uint32_t>(y) *
           static_cast<uint32_t>(this->width_) +
       static_cast<uint32_t>(x)) *
      2U;

  this->buffer_[pos] =
      static_cast<uint8_t>(color565 >> 8);

  this->buffer_[pos + 1] =
      static_cast<uint8_t>(color565 & 0xFF);
}

void LovyanGFXDisplay::dump_config()
{
  ESP_LOGCONFIG(TAG, "LovyanGFX Display:");
  ESP_LOGCONFIG(TAG, "  Model: ST7796");
  ESP_LOGCONFIG(
      TAG,
      "  Resolution: %dx%d",
      this->width_,
      this->height_);

  ESP_LOGCONFIG(TAG, "  Bus: 16-bit Parallel");
  ESP_LOGCONFIG(TAG, "  CS: GPIO%d", this->pin_cs_);
  ESP_LOGCONFIG(TAG, "  DC: GPIO%d", this->pin_dc_);
  ESP_LOGCONFIG(TAG, "  WR: GPIO%d", this->pin_wr_);
  ESP_LOGCONFIG(
      TAG,
      "  Write frequency: %u Hz",
      this->frequency_);

  ESP_LOGCONFIG(TAG, "  RESET: external / XL9555");
}

}  // namespace lovyangfx
}  // namespace esphome
