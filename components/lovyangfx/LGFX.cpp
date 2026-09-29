#define LGFX_USE_V1

#include "LGFX.h"

LGFX::LGFX()
{
  // ============================================================
  // 16-bit Parallel Bus
  // ============================================================
  {
    auto cfg = _bus_instance.config();

    cfg.freq_write = 10000000;
    cfg.freq_read = 0;

    cfg.pin_wr = 45;
    cfg.pin_rd = -1;
    cfg.pin_rs = 38;

    cfg.pin_d0  = 13;
    cfg.pin_d1  = 12;
    cfg.pin_d2  = 11;
    cfg.pin_d3  = 10;
    cfg.pin_d4  = 9;
    cfg.pin_d5  = 46;
    cfg.pin_d6  = 3;
    cfg.pin_d7  = 8;

    cfg.pin_d8  = 18;
    cfg.pin_d9  = 17;
    cfg.pin_d10 = 16;
    cfg.pin_d11 = 15;
    cfg.pin_d12 = 7;
    cfg.pin_d13 = 6;
    cfg.pin_d14 = 5;
    cfg.pin_d15 = 4;

    _bus_instance.config(cfg);
    _panel_instance.setBus(&_bus_instance);
  }

  // ============================================================
  // ST7796 Panel
  // ============================================================
  {
    auto cfg = _panel_instance.config();

    cfg.pin_cs = 39;

    // LCD RESET is physically connected to XL9555 IO0_1.
    // It is NOT connected to an ESP32 GPIO.
    cfg.pin_rst = -1;

    cfg.pin_busy = -1;

    cfg.panel_width = 320;
    cfg.panel_height = 480;

    cfg.memory_width = 320;
    cfg.memory_height = 480;

    cfg.offset_x = 0;
    cfg.offset_y = 0;

    cfg.readable = false;

    cfg.invert = true;
    cfg.rgb_order = false;

    _panel_instance.config(cfg);
  }

  setPanel(&_panel_instance);
}
