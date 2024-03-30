#include "asdk_platform.h"
#include <asdk_can.h>

#define CAN_TX 4
#define CAN_RX 5

asdk_can_config_t can_cfg = {
    .mcu_pins = {
        .tx_pin = CAN_TX,
        .rx_pin = CAN_RX
    },
    .controller_settings = {
        .mode = ASDK_CAN_MODE_STANDARD,
        .can_id_type = ASDK_CAN_ID_STANDARD,
        .max_dlc = ASDK_CAN_DLC_8,
        .bitrate_config.can = {
            .baudrate = ASDK_CAN_BAUDRATE_500K,
            // total tq = 40, sampling point = 77.5%
            .bit_time = {
                .sync_jump_width = 1,
                .phase_segment1 = 7,
                .phase_segment2 = 4,
                .prop_segment = 6,
            },
        },
        .interrupt_config = {
            .use_interrupt = true,
            .priority = 3,
        },
    },
};

/* rx section */
uint8_t rx_data[8];            // buffer to hold the received payload
bool message_received = false; // flag to indicate if new message is received

asdk_can_message_t rx_msg = {  // assign the buffer to store the received message
    .message = rx_data;
};

/* trx section */
asdk_can_message_t tx_msg;
uint8_t tx_data[8];

// Set the message parameters
tx_msg.can_id = 0x401;        // CAN ID
tx_msg.dlc = 8;               // length of payload
tx_msg.message = tx_data;     // payload



void can_app_callback(uint8_t can_ch, asdk_can_event_t event, asdk_can_message_t *can_message)
{
   if (event == ASDK_CAN_TX_COMPLETE_EVENT)
   {
      system_printf("CAN transmission is success\n");
   }
   else if (event == ASDK_CAN_RX_EVENT)
   {
       system_printf("CAN message received\n");
       message_received = true;

       switch (can_message->can_id)
       {
           case 0x501:
               system_printf("CAN message received from 0x501\n");
               Can_HwType mailbox;
               PduInfoType PduInfo;

               mailbox.CanId = can_message->can_id;
               mailbox.ControllerId = 0;
               mailbox.Hoh = 0;

               PduInfo.SduLength = can_message->dlc;
               PduInfo.SduDataPtr = can_message->message;
               CanIf_RxIndication(&mailbox, &PduInfo);
               break;

           case 0x502:
              system_printf("CAN message received from 0x502\n");
                /* user code */
               break;

           default:
               break;
         }
   }
   else if(event == ASDK_CAN_RX_ERROR_EVENT)
   {
      system_printf("CAN message receive error\n");
   }
   else if(event == ASDK_CAN_ERROR_EVENT)
   {
      system_printf("CAN error event\n");
   }
   else if(event == ASDK_CAN_BUS_OFF_EVENT)
   {
      system_printf("CAN error event\n");
   }

}

void can_init(void)
{
    asdk_errorcode_t ret_val;

    ret_val = asdk_can_init(ASDK_CAN_MODULE_CAN_CH_1, &can_cfg);
    ASDK_DEV_ERROR_ASSERT(ret_val, ASDK_CAN_SUCCESS);

    ret_val = asdk_can_install_callback(&can_app_callback);
    ASDK_DEV_ERROR_ASSERT(ret_val, ASDK_CAN_TX_COMPLETE_EVENT);
}


void can_app_iteration(void)
{
   tx_data[0] = 1; /* Horn Switch Status */
   tx_data[1] = 2; /* High Beam Switch Status */
   tx_data[2] = 3; /* Potentiometer ADC value  (0 to 100) */
   tx_data[3] = 4; /* Start Switch Status */
   tx_data[4] = 5; /* Mode Switch Status (0 → No mode; 1 → Left Mode pressed; 2 → Right Mode pressed) */
   tx_data[5] = 6; /* Indicator Switch Status (0 → No; 1 → Left Indicator; 2 → Right Indicator; 3 → Center Indicator Pressed) */
   tx_data[6] = 7; /* Brake1 Switch Status (0 → Not pressed; 1 → Pressed) */
   tx_data[7] = 8; /* Brake2 Switch Status (0 → Not pressed; 1 → Pressed) */

   // Transmit the message
   if (asdk_can_write(ASDK_CAN_CHANNEL_0, 2, &message) != ASDK_CAN_OK) {
       system_printf("CAN Transmission error\n");
   }

   Com_SendSignal(HORN_OUTPUT_STATUS, &tx_data);
}
