#ifndef __ADC_APP_H
#define __ADC_APP_H

#include "asdk_app.h"
#include "asdk_adc.h"

/* Macro: MCU PINs */

/* MCU INPUT PINs */
#define ADC_LDR_SWITCH               62

/* MCU OUTPUT PINs */
#define USER_LED4_EN                 18

/* Enums */

/* GPIO Inputs */
typedef enum
{
    GPIO_INPUT_HB = 0,
    GPIO_INPUT_MAX,
} gpio_input_pin_e;

/* Function declation for GPIO App */
void adc_input_init(void);
void adc_output_init(void);
void adc_app_iteration(void);

#endif