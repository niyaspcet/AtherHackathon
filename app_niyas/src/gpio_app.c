#include "system.h"
#include "gpio_app.h"

/* global variables */
volatile bool high_beam_sw_en = false;

static bool gpio_interrupt_flag[GPIO_INPUT_MAX];

/* GPIO Input Instances */
static asdk_gpio_config_t hb_input = GET_DEFAULT_CFG_GPIO_INPUT(HB_SWITCH);

/* GPIO Output Instances */
static asdk_gpio_config_t hb_output = GET_DEFAULT_CFG_GPIO_OUTPUT(HIGH_BEAM_EN);

/* GPIO common input callback */
static void __app_gpio_input_callback(asdk_mcu_pin_t mcu_pin, uint32_t param);

void gpio_input_init(void)
{
    asdk_errorcode_t ret_val;

    ret_val = asdk_gpio_init(&hb_input);
    ASDK_DEV_ERROR_ASSERT(ret_val, ASDK_GPIO_SUCCESS);

    ret_val = asdk_gpio_install_callback(&__app_gpio_input_callback);
    ASDK_DEV_ERROR_ASSERT(ret_val, ASDK_GPIO_SUCCESS);
}

void gpio_output_init(void)
{
    asdk_errorcode_t ret_val;

    ret_val = asdk_gpio_init(&hb_output);
    ASDK_DEV_ERROR_ASSERT(ret_val, ASDK_GPIO_SUCCESS);
}

void gpio_app_iteration(void)
{
    asdk_gpio_state_t pin_state = ASDK_GPIO_STATE_INVALID;

    if (true == gpio_interrupt_flag[GPIO_INPUT_HB])
    {
        gpio_interrupt_flag[GPIO_INPUT_HB] = false;

        asdk_gpio_get_input_state(HB_SWITCH, &pin_state);
        if (ASDK_GPIO_STATE_HIGH == pin_state)
        {
            high_beam_sw_en = false;
            asdk_gpio_output_set(HIGH_BEAM_EN);
        }
        else if (ASDK_GPIO_STATE_LOW == pin_state)
        {
            high_beam_sw_en = true;
            asdk_gpio_output_clear(HIGH_BEAM_EN);
        }
    }
}

void __app_gpio_input_callback(asdk_mcu_pin_t mcu_pin, uint32_t param)
{
    switch (mcu_pin)
    {
    case HB_SWITCH:
        gpio_interrupt_flag[GPIO_INPUT_HB] = true;
        break;

    default:
        break;
    }
}