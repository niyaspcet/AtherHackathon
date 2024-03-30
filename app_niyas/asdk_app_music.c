#include "asdk_app.h"

#include "gpio_app.h"

void app_init(void)
{
    /* system init, do not modify*/
    system_init();

    /* add application init calls */
    gpio_input_init();
    pwm_init(PWM_CH_LED4, pwm_config_led4);
    pwm_init(PWM_CH_TLAMP, pwm_config_tlamp);
    gpio_output_init();
}

void app_loop(void)
{
    for (;;)
    {
        /* system loop, do not modify */
        system_loop();

        /* add application iteration calls */
        gpio_app_iteration();
        adc_app_iteration();
        kilocoder1();
        kilocoder2();
    }
}
