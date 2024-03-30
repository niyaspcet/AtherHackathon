#ifndef __PWM_APP_H
#define __PWM_APP_H

#include "asdk_app.h"
#include "asdk_platform.h"
#include "asdk_system.h"
#include "asdk_clock.h"
#include "asdk_pwm.h"

#define MAX_DUTY_CYCLE 100
#define MIN_DUTY_CYCLE 0
#define DELAY_MS 10

/* Macro: MCU PINs */

/* MCU INPUT PINs */         
/* MCU OUTPUT PINs */
#define PWM_CH_LED4  ASDK_PWM_MODULE_CH_38
#define PWM_CH_TLAMP  ASDK_PWM_MODULE_CH_41

/* Variables */

/* GPIO Inputs */

asdk_pwm_config_t pwm_config_tlamp = {
    .mcu_pin = PWM_PIN,                              // Pin for PWM 
    .pwm_mode = ASDK_PWM_MODE_PWM,                   // Use PWM mode only
    .pwm_run_mode = ASDK_PWM_RUN_MODE_CONTINUOUS,    // Output continuously
    .direction = ASDK_PWM_COUNT_DIRECTION_UP,        // Use up counter
    .interrupt = {.enable = false},                  // Disable PWM callbacks
    .pwm_output_align = ASDK_PWM_OUTPUT_LEFT_ALIGN,  // Left aligned
    .pwm_clock = {                                   // Use 1 Mhz clock for PWM module
        .clock_frequency = 1000000,
        .prescaler = ASDK_PWM_PRESCALER_DIVBY_1,
    },
    .pwm_frequency_in_Hz = 1000,                     // Desired PWM frequency
};

asdk_pwm_config_t pwm_config_led4 = {
    .mcu_pin = PWM_PIN,                              // Pin for PWM 
    .pwm_mode = ASDK_PWM_MODE_PWM,                   // Use PWM mode only
    .pwm_run_mode = ASDK_PWM_RUN_MODE_CONTINUOUS,    // Output continuously
    .direction = ASDK_PWM_COUNT_DIRECTION_UP,        // Use up counter
    .interrupt = {.enable = false},                  // Disable PWM callbacks
    .pwm_output_align = ASDK_PWM_OUTPUT_LEFT_ALIGN,  // Left aligned
    .pwm_clock = {                                   // Use 1 Mhz clock for PWM module
        .clock_frequency = 1000000,
        .prescaler = ASDK_PWM_PRESCALER_DIVBY_1,
    },
    .pwm_frequency_in_Hz = 1500,                     // Desired PWM frequency
};

/* Function declation for GPIO App */

void pwm_init(asdk_pwm_channel_t pwm_ch, asdk_pwm_config_t *pwm_config);
void pwm_start(asdk_pwm_channel_t pwm_ch);
void pwm_set_duty(uint8_t duty_cycle_in_percent);
void nibbleninja4(void);
void pwm_increment_duty(void);
void pwm_decrement_duty(void);

#endif