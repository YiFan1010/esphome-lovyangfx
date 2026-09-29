import esphome.codegen as cg
import esphome.config_validation as cv

from esphome.components import display
from esphome.const import (
    CONF_ID,
    CONF_HEIGHT,
    CONF_WIDTH,
)

lovyangfx_ns = cg.esphome_ns.namespace("lovyangfx")

LovyanGFXDisplay = lovyangfx_ns.class_(
    "LovyanGFXDisplay",
    display.DisplayBuffer,
)

CONF_FREQUENCY = "frequency"
CONF_PIN_CS = "pin_cs"
CONF_PIN_DC = "pin_dc"
CONF_PIN_WR = "pin_wr"

CONF_PIN_D0 = "pin_d0"
CONF_PIN_D1 = "pin_d1"
CONF_PIN_D2 = "pin_d2"
CONF_PIN_D3 = "pin_d3"
CONF_PIN_D4 = "pin_d4"
CONF_PIN_D5 = "pin_d5"
CONF_PIN_D6 = "pin_d6"
CONF_PIN_D7 = "pin_d7"
CONF_PIN_D8 = "pin_d8"
CONF_PIN_D9 = "pin_d9"
CONF_PIN_D10 = "pin_d10"
CONF_PIN_D11 = "pin_d11"
CONF_PIN_D12 = "pin_d12"
CONF_PIN_D13 = "pin_d13"
CONF_PIN_D14 = "pin_d14"
CONF_PIN_D15 = "pin_d15"

CONF_ROTATION = "rotation"
CONF_INVERT = "invert"
CONF_RGB_ORDER = "rgb_order"

CONFIG_SCHEMA = (
    display.FULL_DISPLAY_SCHEMA
    .extend(
        {
            cv.GenerateID(): cv.declare_id(LovyanGFXDisplay),

            cv.Required(CONF_WIDTH): cv.int_range(min=1, max=2000),
            cv.Required(CONF_HEIGHT): cv.int_range(min=1, max=2000),

            cv.Optional(CONF_FREQUENCY, default="10MHz"): cv.frequency,

            cv.Required(CONF_PIN_CS): cv.int_,
            cv.Required(CONF_PIN_DC): cv.int_,
            cv.Required(CONF_PIN_WR): cv.int_,

            cv.Required(CONF_PIN_D0): cv.int_,
            cv.Required(CONF_PIN_D1): cv.int_,
            cv.Required(CONF_PIN_D2): cv.int_,
            cv.Required(CONF_PIN_D3): cv.int_,
            cv.Required(CONF_PIN_D4): cv.int_,
            cv.Required(CONF_PIN_D5): cv.int_,
            cv.Required(CONF_PIN_D6): cv.int_,
            cv.Required(CONF_PIN_D7): cv.int_,
            cv.Required(CONF_PIN_D8): cv.int_,
            cv.Required(CONF_PIN_D9): cv.int_,
            cv.Required(CONF_PIN_D10): cv.int_,
            cv.Required(CONF_PIN_D11): cv.int_,
            cv.Required(CONF_PIN_D12): cv.int_,
            cv.Required(CONF_PIN_D13): cv.int_,
            cv.Required(CONF_PIN_D14): cv.int_,
            cv.Required(CONF_PIN_D15): cv.int_,

            cv.Optional(CONF_ROTATION, default=0): cv.one_of(
                0, 1, 2, 3, int=True
            ),

            cv.Optional(CONF_INVERT, default=True): cv.boolean,
            cv.Optional(CONF_RGB_ORDER, default=False): cv.boolean,
        }
    )
)


async def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])

    cg.add(var.set_width(config[CONF_WIDTH]))
    cg.add(var.set_height(config[CONF_HEIGHT]))

    cg.add(var.set_frequency(config[CONF_FREQUENCY]))

    cg.add(var.set_pin_cs(config[CONF_PIN_CS]))
    cg.add(var.set_pin_dc(config[CONF_PIN_DC]))
    cg.add(var.set_pin_wr(config[CONF_PIN_WR]))

    cg.add(var.set_pin_d0(config[CONF_PIN_D0]))
    cg.add(var.set_pin_d1(config[CONF_PIN_D1]))
    cg.add(var.set_pin_d2(config[CONF_PIN_D2]))
    cg.add(var.set_pin_d3(config[CONF_PIN_D3]))
    cg.add(var.set_pin_d4(config[CONF_PIN_D4]))
    cg.add(var.set_pin_d5(config[CONF_PIN_D5]))
    cg.add(var.set_pin_d6(config[CONF_PIN_D6]))
    cg.add(var.set_pin_d7(config[CONF_PIN_D7]))
    cg.add(var.set_pin_d8(config[CONF_PIN_D8]))
    cg.add(var.set_pin_d9(config[CONF_PIN_D9]))
    cg.add(var.set_pin_d10(config[CONF_PIN_D10]))
    cg.add(var.set_pin_d11(config[CONF_PIN_D11]))
    cg.add(var.set_pin_d12(config[CONF_PIN_D12]))
    cg.add(var.set_pin_d13(config[CONF_PIN_D13]))
    cg.add(var.set_pin_d14(config[CONF_PIN_D14]))
    cg.add(var.set_pin_d15(config[CONF_PIN_D15]))

    cg.add(var.set_rotation(config[CONF_ROTATION]))
    cg.add(var.set_invert(config[CONF_INVERT]))
    cg.add(var.set_rgb_order(config[CONF_RGB_ORDER]))

    await display.register_display(var, config)
