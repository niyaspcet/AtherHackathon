#include "system.h"

// global variables
uint8_t g_uart_out_data[256]; // TX Buffer for Terminal Print
volatile bool wr_flag = false;
ComM_ConfigType ComMConfigSet;
ComM_ASR40_ModeType ComM_UserRequestedComMode[1U];
uint8_t CanIf_ConfigLayout;

// local function declarations
static void __system_timer_callback(asdk_timer_event_t timer_event);
static void __app_uart_callback(asdk_uart_num_t uart_no, uint8_t *data, uint32_t data_len, asdk_uart_status_t status);

// local variables
static bool timer_1s_flag = false;
static asdk_timer_t sys_timer_1s_config = {
    .type = ASDK_TIMER_TYPE_PERIODIC,
    .mode = {
        .type = ASDK_TIMER_MODE_TIMER,
        .config = {
            .timer.timer_period = 1000000,
            .timer.callback = &__system_timer_callback,
        },
    },
    .direction = ASDK_TIMER_COUNT_DIRECTION_UP,
    .counter_clock = {.frequency = 1000000, .prescaler = ASDK_CLOCK_PRESCALER_1},
    .interrupt = {.enable = true, .priority = 3},
};

static asdk_uart_config_t uart_cfg = {
    .uart_no = UART_NO,
    .uart_rx_mcu_pin_no = MCU_PIN_2,
    .uart_tx_mcu_pin_no = MCU_PIN_3,
    .op_mode = ASDK_UART_MODE_STANDARD,
    .baud_rate = ASDK_UART_BAUD_RATE_9600,
    .data_bits = ASDK_UART_DATA_BITS_8,
    .parity_mode = ASDK_UART_PARITY_NONE,
    .stop_bits = ASDK_UART_STOP_BITS_1,
    .interrupt_config = {.use_interrupt = true, .priority = 3},
};

// Function to initialize the system
void system_init()
{
    asdk_errorcode_t retVal;
    asdk_clock_config_t clk_cfg = {
        .clk_source = ASDK_CLOCK_SRC_INT,
        .pll = {
            .input_frequency = 8000000,
            .output_frequency = 160000000,
        },
        .xtal_trim = {0}
    };

    /* Init board hardware */
    asdk_clock_init(&clk_cfg);

    // uart init for debugging
    retVal = asdk_uart_init(&uart_cfg);
    ASDK_DEV_ERROR_ASSERT(retVal, ASDK_UART_STATUS_SUCCESS);

    retVal = asdk_uart_install_callback(UART_NO, __app_uart_callback);
    ASDK_DEV_ERROR_ASSERT(retVal, ASDK_UART_STATUS_SUCCESS);

    system_printf("Welcome to Hackathon! All the best! \n");
    memset(g_uart_out_data, 0, sizeof(g_uart_out_data));

    // eb stack init
    ComM_UserRequestedComMode[0] = 2U;

    PduR_Init(Pdur_config_init);

    Com_Init(Com_config_init);
    Com_InitStatus = 1U;
    
    CanIf_Init(&CanIf_ConfigLayout);
    CanIf_PduMode[0] = CANIF_ONLINE;
    CanIf_CanControllerMode[0] = 1;

    // system timer use ch 78: for 1s timer 
    retVal = asdk_timer_init(SYS_TIMER_CH, &sys_timer_1s_config);
    ASDK_DEV_ERROR_ASSERT(retVal, ASDK_TIMER_SUCCESS);

    retVal = asdk_timer_start(SYS_TIMER_CH);
    ASDK_DEV_ERROR_ASSERT(retVal, ASDK_TIMER_SUCCESS);

}

// Function to run the system loop
void system_loop()
{
    if (timer_1s_flag)
    {
        /* 0x402 & 0x403 via EB stack */
        Com_MainFunctionRouteSignals();
        Com_MainFunctionTx();
        Com_MainFunctionRx();

        timer_1s_flag = false;
    }
}

// System Timer Callback
static void __system_timer_callback(asdk_timer_event_t timer_event)
{
    if (ASDK_TIMER_TERMINAL_COUNT_EVENT == timer_event)
    {
        timer_1s_flag = true;
    }
}

// UART Callback
void __app_uart_callback(asdk_uart_num_t uart_no, uint8_t *data, uint32_t data_len, asdk_uart_status_t status)
{
    (void)(uart_no);

    if (ASDK_UART_STATUS_TRANSMIT_COMPLETE == status)
        wr_flag = true;
}
