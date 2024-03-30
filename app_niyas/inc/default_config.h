/*This file includes the default config to be used by peripherals*/
#include "asdk_gpio.h"
#include "asdk_timer.h"
#include "asdk_can.h"
#include "asdk_pwm.h"
#include "asdk_adc.h"

#include "asdk_platform.h"

#define ASDK_DELAY_MS(VALUE_IN_MS) Cy_SysTick_DelayInUs(VALUE_IN_MS * 1000)
#define ASDK_DELAY_US(VALUE_IN_US) Cy_SysTick_DelayInUs(VALUE_IN_US)

#define GET_DEFAULT_CFG_GPIO_OUTPUT(MCU_PIN_OUTPUT) \
    {                                               \
        .mcu_pin = MCU_PIN_OUTPUT,                  \
        .gpio_mode = ASDK_GPIO_MODE_OUTPUT,         \
        .gpio_init_state = ASDK_GPIO_STATE_HIGH,    \
        .gpio_pull = ASDK_GPIO_PUSH_PULL,           \
    }

#define GET_DEFAULT_CFG_GPIO_INPUT(MCU_PIN_INPUT)   \
    {                                               \
        .mcu_pin = MCU_PIN_INPUT,                   \
        .gpio_mode = ASDK_GPIO_MODE_INPUT,          \
        .gpio_pull = ASDK_GPIO_HIGH_Z,              \
        .interrupt_config = {                       \
            .type = ASDK_GPIO_INTERRUPT_BOTH_EDGES, \
            .priority = 3,                          \
        },                                          \
    }

#define GET_DEFAULT_CFG_CAN(MCU_PIN_TX, MCU_PIN_RX) \
    {                                               \
        .mcu_pins = {                               \       
            MCU_PIN_TX,                             \
            MCU_PIN_RX,                             \           
        },                                          \
        .hw_filter = {0},                           \
        .controller_settings = {                    \       
        .mode = ASDK_CAN_MODE_STANDARD,             \               
        .max_dlc = ASDK_CAN_DLC_8,                  \           
        .can_id_type = ASDK_CAN_ID_STANDARD,        \                       
        .bitrate_config.can = {                     \       
            .baudrate = ASDK_CAN_BAUDRATE_500K,     \
            .bit_time = {                           \    
                .prop_segment = 29,                 \           
                .phase_segment1 = 5,                \               
                .phase_segment2 = 5,                \               
                .sync_jump_width = 5,               \               
            },                                      \   
        },                                          \
        .interrupt_config = {                       \       
            .use_interrupt = true,                  \            
            .priority = 3,                          \    
        },                                          \
        },                                          \
    }

#define GET_DEFAULT_CFG_TIMER(TIMER_CH, TIMER_CALLBACK) \
    {                                                   \
        .type = ASDK_TIMER_TYPE_PERIODIC,               \
        .mode = {                                       \
            .type = ASDK_TIMER_MODE_TIMER,              \
            .config = {                                 \
                .timer.timer_period = 1000,             \
                .timer.callback = TIMER_CALLBACK,       \
            },                                          \
        },                                              \
        .direction = ASDK_TIMER_COUNT_DIRECTION_UP,     \
        .counter_clock = {                              \
            .frequency = 1000000,                       \
            .prescaler = ASDK_CLOCK_PRESCALER_1,        \
        },                                              \
        .interrupt = {                                  \
            .enable = true,                             \
            .priority = 3,                              \
        },                                              \
    }

#define GET_DEFAULT_CFG_PWM(MCU_PIN_PWM)                \
    {                                                   \
        .mcu_pin = MCU_PIN_PWM,                         \
        .pwm_mode = ASDK_PWM_MODE_PWM,                  \
        .pwm_run_mode = ASDK_PWM_RUN_MODE_CONTINUOUS,   \
        .direction = ASDK_PWM_COUNT_DIRECTION_UP,       \
        .interrupt = {.enable = false},                 \
        .pwm_output_align = ASDK_PWM_OUTPUT_LEFT_ALIGN, \
        .pwm_clock = {                                  \
            .clock_frequency = 1000000,                 \
            .prescaler = ASDK_PWM_PRESCALER_DIVBY_1,    \
        },                                              \
        .pwm_frequency_in_Hz = 1000,                    \
        .pwm_duty_cycle_in_percent = 30,                \
    };

#define GET_DEFAULT_CFG_ADC(MCU_PIN_ADC_ARRAY)         \
    {                                                  \
        .pin_nums = MCU_PIN_ADC_ARRAY,                 \
        .pin_count = 1,                                \
        .adc_resolution = ASDK_ADC_RESOLUTION_12_BITS, \
        .enable_interrupt = true,                      \
    };
