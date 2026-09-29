#include "lovyangfx_display.h"

#include "esphome/core/log.h"
#include "esphome/components/display/display_color_utils.h"

namespace esphome {
namespace lovyangfx {

static const char *const TAG = "lovyangfx.display";

void LovyanGFXDisplay::setup()
{
  ESP_LOGCONFIG(TAG, "Setting up LovyanGFX ST7796...");

  // Initialize LovyanGFX / ST7796.
  this->lcd_.init();

  // ESPHome framebuffer:
  //
  // 320 * 480 pixels
  // RGB565 = 2 bytes / pixel
  //
  // Total = 307200 bytes.
  this->init_internal_(320 * 480 * 2);

  // ESPHome stores RGB565 bytes in big-endian order.
  //
  // LovyanGFX normally receives RGB565 through uint16_t.
  // setSwapBytes(true) makes LovyanGFX swap the byte order
  // when sending the framebuffer.
  this->lcd_.setSwapBytes(true);

  this->lcd_.setColorDepth(16);

  // Start with portrait orientation.
  this->lcd_.setRotation(0);

  ESP_LOGCONFIG(TAG, "LovyanGFX ST7796 initialized.");
}

void LovyanGFXDisplay::update()
{
  // Render ESPHome lambda/pages into DisplayBuffer.
  this->do_update_();

  // Send the complete framebuffer to ST7796.
  this->lcd_.pushImage(
      0,
      0,
      320,
      480,
      reinterpret_cast<const uint16_t *>(this->buffer_));
}

void LovyanGFXDisplay::draw_absolute_pixel_internal(
    int x,
    int y,
    display::Color color)
{
  if (x < 0 || x >= 320 || y < 0 || y >= 480) {
    return;
  }

  uint16_t color565 =
      display::ColorUtil::color_to_565(color);

  const uint32_t pos =
      (static_cast<uint32_t>(y) * 320U +
       static_cast<uint32_t>(x)) * 2U;

  this->buffer_[pos] =
      static_cast<uint8_t>(color565 >> 8);

  this->buffer_[pos + 1] =
      static_cast<uint8_t>(color565 & 0xFF);
}

void LovyanGFXDisplay::dump_config()
{
  ESP_LOGCONFIG(TAG, "LovyanGFX Display:");
  ESP_LOGCONFIG(TAG, "  Model: ST7796");
  ESP_LOGCONFIG(TAG, "  Resolution: 320x480");
  ESP_LOGCONFIG(TAG, "  Bus: 16-bit Parallel");
  ESP_LOGCONFIG(TAG, "  CS: GPIO39");
  ESP_LOGCONFIG(TAG, "  RS/DC: GPIO38");
  ESP_LOGCONFIG(TAG, "  WR: GPIO45");
  ESP_LOGCONFIG(TAG, "  RESET: XL9555 IO0_1");
}

}  // namespace lovyangfx
}  // namespace esphome
