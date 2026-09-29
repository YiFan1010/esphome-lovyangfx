import esphome.codegen as cg
import esphome.config_validation as cv

from esphome.components import display
from esphome.const import CONF_ID

lovyangfx_ns = cg.esphome_ns.namespace("lovyangfx")

LovyanGFXDisplay = lovyangfx_ns.class_(
    "LovyanGFXDisplay",
    display.DisplayBuffer,
)

CONFIG_SCHEMA = (
    display.FULL_DISPLAY_SCHEMA
    .extend(
        {
            cv.GenerateID(): cv.declare_id(LovyanGFXDisplay),
        }
    )
)


async def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])

    await display.register_display(var, config)
