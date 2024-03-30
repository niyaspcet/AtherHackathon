#include "asdk_app.h"

#include "gpio_app.h"

void app_init(void)
{
    /* system init, do not modify*/
    system_init();

    /* add application init calls */
    gpio_input_init();
    pwm_init();
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
    }
}
