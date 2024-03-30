#ifndef __GPIO_APP_H
#define __GPIO_APP_H

#include "asdk_app.h"
#include "asdk_gpio.h"

/* Macro: MCU PINs */

/* MCU INPUT PINs */
#define HB_SWITCH               62

/* MCU INPUT PINs */
#define HR_SWITCH               63

/* MCU OUTPUT PINs */
#define HIGH_BEAM_EN            18

/* MCU OUTPUT PINs */
#define HIGH_HORN_EN            66



/* MCU INPUT PINs */
#define IDRL_SWITCH               14

/* MCU INPUT PINs */
#define IDRR_SWITCH               15

/* MCU INPUT PINs */
#define IDRC_SWITCH               23



/* MCU OUTPUT PINs */
#define LDRL_LIGHT               30

/* MCU OUTPUT PINs */
#define LDRR_LIGHT               29

/* Enums */

/* GPIO Inputs */
typedef enum
{
    GPIO_INPUT_HB = 0,
    GPIO_INPUT_HR = 1,
    GPIO_INPUT_MAX,
} gpio_input_pin_e;

/* Function declation for GPIO App */
void gpio_input_init(void);
void gpio_output_init(void);
void gpio_input_hr_init(void);
void gpio_output_hr_init(void);
void gpio_app_iteration(void);
void gpio_app_iteration_horn(void);

#endif