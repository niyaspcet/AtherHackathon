#include "system.h"
#include "pwm_app.h"

asdk_errorcode_t pwm_init(asdk_pwm_channel_t pwm_ch, asdk_pwm_config_t *pwm_config)
{
    asdk_errorcode_t error = asdk_pwm_init(ASDK_PWM_MODULE_CH_38, pwn_config);
    if (error != ASDK_PWM_SUCCESS)
    {
            system_printf("PWM Init Failed \n");
    }
    ASDK_DEV_ERROR_ASSERT(error, ASDK_PWM_SUCCESS);
    (void)pwm_start(pwm_ch)
}
void pwm_start(asdk_pwm_channel_t pwm_ch)
{
   asdk_errorcode_t error = asdk_pwm_start(pwm_ch);
    if (error != ASDK_PWM_SUCCESS)
    {
            system_printf("PWM Start Failed \n");
    }
    ASDK_DEV_ERROR_ASSERT(error, ASDK_PWM_SUCCESS);
}
void pwm_set_duty(uint8_t duty_cycle_in_percent)
{
    asdk_errorcode_t error = asdk_pwm_set_duty(duty_cycle_in_percent);
    if (error != ASDK_PWM_SUCCESS)
    {
            system_printf("PWM Duty Cycle Set Failed \n");
    }
    ASDK_DEV_ERROR_ASSERT(error, ASDK_PWM_SUCCESS);
}

void nibbleninja4(void)
{
    
}

void pwm_increment_duty()
{

}

void pwm_decrement_duty()
{

}

