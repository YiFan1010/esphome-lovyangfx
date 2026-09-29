#define LGFX_USE_V1

#include "LGFX.h"

LGFX::LGFX()
{
}

void LGFX::configure(
    int width,
    int height,
    uint32_t frequency,
    int pin_cs,
    int pin_dc,
    int pin_wr,
    int pin_d0,
    int pin_d1,
    int pin_d2,
    int pin_d3,
    int pin_d4,
    int pin_d5,
    int pin_d6,
    int pin_d7,
    int pin_d8,
    int pin_d9,
    int pin_d10,
    int pin_d11,
    int pin_d12,
    int pin_d13,
    int pin_d14,
    int pin_d15,
    bool invert,
    bool rgb_order)
{
  // ------------------------------------------------------------
  // 16-bit Parallel Bus
  // ------------------------------------------------------------

  {
    auto cfg = bus_.config();

    cfg.freq_write = frequency;
    cfg.freq_read = 0;

    cfg.pin_wr = pin_wr;
    cfg.pin_rd = -1;
    cfg.pin_rs = pin_dc;

    cfg.pin_d0 = pin_d0;
    cfg.pin_d1 = pin_d1;
    cfg.pin_d2 = pin_d2;
    cfg.pin_d3 = pin_d3;
    cfg.pin_d4 = pin_d4;
    cfg.pin_d5 = pin_d5;
    cfg.pin_d6 = pin_d6;
    cfg.pin_d7 = pin_d7;

    cfg.pin_d8 = pin_d8;
    cfg.pin_d9 = pin_d9;
    cfg.pin_d10 = pin_d10;
    cfg.pin_d11 = pin_d11;
    cfg.pin_d12 = pin_d12;
    cfg.pin_d13 = pin_d13;
    cfg.pin_d14 = pin_d14;
    cfg.pin_d15 = pin_d15;

    bus_.config(cfg);
    panel_.setBus(&bus_);
  }

  // ------------------------------------------------------------
  // ST7796
  // ------------------------------------------------------------

  {
    auto cfg = panel_.config();

    cfg.pin_cs = pin_cs;

    // RESET is controlled externally by XL9555.
    cfg.pin_rst = -1;

    cfg.pin_busy = -1;

    cfg.panel_width = width;
    cfg.panel_height = height;

    cfg.memory_width = width;
    cfg.memory_height = height;

    cfg.offset_x = 0;
    cfg.offset_y = 0;

    cfg.readable = false;

    cfg.invert = invert;
    cfg.rgb_order = rgb_order;

    panel_.config(cfg);
  }

  setPanel(&panel_);
}
