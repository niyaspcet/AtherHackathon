#include "system.h"
#include "adc_app.h"
#include "pwm_app.h"

/* global variables */
volatile bool adc_user_led_sw_en = false;

static bool adc_interrupt_flag[ADC_INPUT_MAX];

/* GPIO Input Instances */
static asdk_adc_config_t adc_ldr_input = GET_DEFAULT_CFG_ADC_INPUT(ADC_LDR_SWITCH);

/* ADC Output Instances */
static asdk_adc_config_t user_led_output = GET_DEFAULT_CFG_ADC_OUTPUT(USER_LED4_EN);

/* ADC common input callback */
static void __app_adc_input_callback(asdk_mcu_pin_t mcu_pin, uint32_t param);

void adc_input_init(void)
{
    asdk_errorcode_t ret_val;

    ret_val = asdk_adc_init(&adc_ldr_input);
    ASDK_DEV_ERROR_ASSERT(ret_val, ASDK_ADC_SUCCESS);

    ret_val = asdk_adc_install_callback(&__app_adc_input_callback);
    ASDK_DEV_ERROR_ASSERT(ret_val, ASDK_ADC_SUCCESS);
}

void adc_output_init(void)
{
    asdk_errorcode_t ret_val;

    ret_val = asdk_adc_init(&user_led_output);
    ASDK_DEV_ERROR_ASSERT(ret_val, ASDK_ADC_SUCCESS);
}

void adc_app_iteration(void)
{
    asdk_adc_state_t pin_state = ASDK_ADC_STATE_INVALID;
    int8 AdcValue=0;
    if (true == adc_interrupt_flag[ADC_LDR_SWITCH])
    {
        adc_interrupt_flag[ADC_LDR_SWITCH] = false;

        asdk_adc_get_input_state(ADC_USERLED_SWITCH, &pin_state);
        
        if (ASDK_ADC_STATE_HIGH == pin_state)
        {
            adc_user_led_sw_en = false;
            AdcValue = 5.0 * ADC_LDR_SWITCH / 4096.0;
            pwm_set_duty(AdcValue);   
        }
    }
}

void __app_adc_input_callback(asdk_mcu_pin_t mcu_pin, uint32_t param)
{
    switch (mcu_pin)
    {
    case ADC_USERLED_SWITCH:
        adc_interrupt_flag[ADC_LDR_SWITCH] = true;
        break;

    default:
        break;
    }
}