#pragma once

#define LGFX_USE_V1

#include <LovyanGFX.hpp>

class LGFX : public lgfx::LGFX_Device
{
 public:
  LGFX();

  void configure(
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
      bool rgb_order);

 private:
  lgfx::Panel_ST7796 panel_;
  lgfx::Bus_Parallel16 bus_;
};
