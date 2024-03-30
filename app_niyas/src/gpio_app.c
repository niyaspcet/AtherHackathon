#include "system.h"
#include "gpio_app.h"

/* global variables */
volatile bool high_beam_sw_en = false;

volatile bool high_horn_sw_en = false;

static bool gpio_interrupt_flag[GPIO_INPUT_MAX];

/* GPIO Input Instances */
static asdk_gpio_config_t hb_input = GET_DEFAULT_CFG_GPIO_INPUT(HB_SWITCH);

/* GPIO Output Instances */
static asdk_gpio_config_t hb_output = GET_DEFAULT_CFG_GPIO_OUTPUT(HIGH_BEAM_EN);

/* GPIO Input Instances */
static asdk_gpio_config_t hr_input = GET_DEFAULT_CFG_GPIO_INPUT(HR_SWITCH);

/* GPIO Output Instances */
static asdk_gpio_config_t hr_output = GET_DEFAULT_CFG_GPIO_OUTPUT(HIGH_HORN_EN);

/* GPIO Input Instances */
static asdk_gpio_config_t idrl_input = GET_DEFAULT_CFG_GPIO_INPUT(IDRL_SWITCH);

/* GPIO Input Instances */
static asdk_gpio_config_t idrr_input = GET_DEFAULT_CFG_GPIO_INPUT(IDRR_SWITCH);

/* GPIO Input Instances */
static asdk_gpio_config_t idrc_input = GET_DEFAULT_CFG_GPIO_INPUT(IDRC_SWITCH);

/* GPIO Output Instances */
static asdk_gpio_config_t idrr_output = GET_DEFAULT_CFG_GPIO_OUTPUT(LDRR_LIGHT);

/* GPIO Output Instances */
static asdk_gpio_config_t idrl_output = GET_DEFAULT_CFG_GPIO_OUTPUT(LDRL_LIGHT);

/* GPIO common input callback */
static void __app_gpio_input_callback(asdk_mcu_pin_t mcu_pin, uint32_t param);

void gpio_input_init(void)
{
    asdk_errorcode_t ret_val;

    ret_val = asdk_gpio_init(&hb_input);
    ASDK_DEV_ERROR_ASSERT(ret_val, ASDK_GPIO_SUCCESS);

    ret_val = asdk_gpio_init(&idrr_input);
    ASDK_DEV_ERROR_ASSERT(ret_val, ASDK_GPIO_SUCCESS);

    ret_val = asdk_gpio_init(&idrc_input);
    ASDK_DEV_ERROR_ASSERT(ret_val, ASDK_GPIO_SUCCESS);

    ret_val = asdk_gpio_init(&idrl_input);
    ASDK_DEV_ERROR_ASSERT(ret_val, ASDK_GPIO_SUCCESS);


    ret_val = asdk_gpio_install_callback(&__app_gpio_input_callback);
    ASDK_DEV_ERROR_ASSERT(ret_val, ASDK_GPIO_SUCCESS);
}

void gpio_input_hr_init(void)
{
    asdk_errorcode_t ret_val;

    ret_val = asdk_gpio_init(&hr_input);
    ASDK_DEV_ERROR_ASSERT(ret_val, ASDK_GPIO_SUCCESS);

/*     ret_val = asdk_gpio_install_callback(&__app_gpio_input_callback);
    ASDK_DEV_ERROR_ASSERT(ret_val, ASDK_GPIO_SUCCESS); */
}

void gpio_output_init(void)
{
    asdk_errorcode_t ret_val;

    ret_val = asdk_gpio_init(&hb_output);
    ASDK_DEV_ERROR_ASSERT(ret_val, ASDK_GPIO_SUCCESS);

    ret_val = asdk_gpio_init(&idrl_output);
    ASDK_DEV_ERROR_ASSERT(ret_val, ASDK_GPIO_SUCCESS);

    ret_val = asdk_gpio_init(&idrr_output);
    ASDK_DEV_ERROR_ASSERT(ret_val, ASDK_GPIO_SUCCESS);
}

void gpio_output_hr_init(void)
{
    asdk_errorcode_t ret_val;

    ret_val = asdk_gpio_init(&hr_output);
    ASDK_DEV_ERROR_ASSERT(ret_val, ASDK_GPIO_SUCCESS);

    asdk_gpio_output_clear(HIGH_HORN_EN);
}

void gpio_app_iteration(void)
{
    asdk_gpio_state_t pin_state = ASDK_GPIO_STATE_INVALID;
    asdk_gpio_state_t pin_state1 = ASDK_GPIO_STATE_INVALID;
    asdk_gpio_state_t pin_state2= ASDK_GPIO_STATE_INVALID;
    asdk_gpio_state_t pin_state3 = ASDK_GPIO_STATE_INVALID;

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
    asdk_gpio_get_input_state(IDRL_SWITCH, &pin_state1);
    asdk_gpio_get_input_state(IDRR_SWITCH, &pin_state2);
    asdk_gpio_get_input_state(IDRC_SWITCH, &pin_state3);
    if(pin_state1 == false)
    {
        asdk_gpio_output_set(LDRL_LIGHT);
        asdk_gpio_output_clear(LDRR_LIGHT);
    }
    if(pin_state2 == false)
    {
        asdk_gpio_output_set(LDRR_LIGHT);
        asdk_gpio_output_clear(LDRL_LIGHT);
    }
    if(pin_state3 == false)
    {
        asdk_gpio_output_clear(LDRL_LIGHT);
        asdk_gpio_output_clear(LDRR_LIGHT);
    }

}

void gpio_app_iteration_horn(void)
{
    asdk_gpio_state_t pin_state = ASDK_GPIO_STATE_INVALID;

    if (true == gpio_interrupt_flag[GPIO_INPUT_HR])
    {
        gpio_interrupt_flag[GPIO_INPUT_HR] = false;

        asdk_gpio_get_input_state(HR_SWITCH, &pin_state);
        if (ASDK_GPIO_STATE_LOW == pin_state)
        {
           high_horn_sw_en = true;
           asdk_gpio_output_set(HIGH_HORN_EN);
           system_printf("Horn ON\n\r");
        }
    }
    if(high_horn_sw_en)
    {
        asdk_gpio_get_input_state(HR_SWITCH, &pin_state);
        if (ASDK_GPIO_STATE_HIGH == pin_state)
        {
           high_horn_sw_en = false;
           asdk_gpio_output_clear(HIGH_HORN_EN);
           system_printf("Horn OFF\n\r");
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
    case HR_SWITCH:
        gpio_interrupt_flag[GPIO_INPUT_HR] = true;
        break;
    default:
        break;
    }
}