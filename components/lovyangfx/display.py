import esphome.codegen as cg
import esphome.config_validation as cv

from esphome.components import display
from esphome.const import CONF_ID

DEPENDENCIES = []

lovyangfx_ns = cg.esphome_ns.namespace("lovyangfx")

LovyanGFXDisplay = lovyangfx_ns.class_(
    "LovyanGFXDisplay",
    display.DisplayBuffer,
)

CONFIG_SCHEMA = display.BASIC_DISPLAY_SCHEMA.extend({
    cv.GenerateID(): cv.declare_id(LovyanGFXDisplay),
}).extend(cv.polling_component_schema("1s"))


async def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    await cg.register_component(var, config)
    await display.register_display(var, config)
