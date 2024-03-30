#ifndef __GPIO_APP_H
#define __GPIO_APP_H

#include "asdk_app.h"
#include "asdk_gpio.h"

/* Macro: MCU PINs */

/* MCU INPUT PINs */
#define HB_SWITCH               62

/* MCU OUTPUT PINs */
#define HIGH_BEAM_EN            18

/* Enums */

/* GPIO Inputs */
typedef enum
{
    GPIO_INPUT_HB = 0,
    GPIO_INPUT_MAX,
} gpio_input_pin_e;

/* Function declation for GPIO App */
void gpio_input_init(void);
void gpio_output_init(void);
void gpio_app_iteration(void);

#endif