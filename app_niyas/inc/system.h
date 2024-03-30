// system.h

#ifndef SYSTEM_H
#define SYSTEM_H

#include "asdk_app.h"
#include "asdk_timer.h"
#include "asdk_uart.h"

// macro definitions
#define SYS_TIMER_CH 78
#define UART_NO (ASDK_UART_0)

// extern variables, expose signal variables of 0x501
extern uint8_t key_status;
extern uint8_t kill_switch_status;
extern uint8_t side_stand_status;
extern uint8_t soc;
extern uint8_t motor_temp;
extern uint8_t motor_mode;
extern uint8_t charger_connected;

extern uint8_t g_uart_out_data[256];
extern volatile bool wr_flag;

#define system_printf(...)                                                           \
    snprintf((char *)g_uart_out_data, sizeof(g_uart_out_data), ##__VA_ARGS__);       \
    asdk_uart_write_non_blocking(UART_NO, g_uart_out_data, sizeof(g_uart_out_data)); \
    while (!wr_flag)                                                                 \
        ;                                                                            \
    wr_flag = false;

// Function to initialize the system
void system_init();

// Function to run the system loop
void system_loop();

#endif