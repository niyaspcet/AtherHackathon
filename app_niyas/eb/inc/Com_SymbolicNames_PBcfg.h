#ifndef COM_SYMBOLIC_NAMES_PB_CFG_H
#define COM_SYMBOLIC_NAMES_PB_CFG_H

/**
 * \file
 *
 * \brief AUTOSAR Com
 *
 * This file contains the implementation of the AUTOSAR
 * module Com.
 *
 * \version 6.3.54
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2022 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

/*==================[includes]==============================================*/

/*==================[macros]================================================*/

/* IPDU group ID defines */
#if (defined ComConf_ComIPduGroup_RGCanNetwork) /* To prevent double declaration */
#error ComConf_ComIPduGroup_RGCanNetwork already defined
#endif /* #if (defined ComConf_ComIPduGroup_RGCanNetwork) */

#define ComConf_ComIPduGroup_RGCanNetwork 0U


#if (defined ComConf_ComIPduGroup_RXPDUS_GLOBAL) /* To prevent double declaration */
#error ComConf_ComIPduGroup_RXPDUS_GLOBAL already defined
#endif /* #if (defined ComConf_ComIPduGroup_RXPDUS_GLOBAL) */

#define ComConf_ComIPduGroup_RXPDUS_GLOBAL 1U


#if (defined ComConf_ComIPduGroup_TGCanNetwork) /* To prevent double declaration */
#error ComConf_ComIPduGroup_TGCanNetwork already defined
#endif /* #if (defined ComConf_ComIPduGroup_TGCanNetwork) */

#define ComConf_ComIPduGroup_TGCanNetwork 2U


#if (defined ComConf_ComIPduGroup_TXPDUS_GLOBAL) /* To prevent double declaration */
#error ComConf_ComIPduGroup_TXPDUS_GLOBAL already defined
#endif /* #if (defined ComConf_ComIPduGroup_TXPDUS_GLOBAL) */

#define ComConf_ComIPduGroup_TXPDUS_GLOBAL 3U


/* External Rx IPdus defines */
#if (defined ComConf_ComIPdu_PDPdu_INP_1_1281R) /* To prevent double declaration */
#error ComConf_ComIPdu_PDPdu_INP_1_1281R already defined
#endif /* #if (defined ComConf_ComIPdu_PDPdu_INP_1_1281R) */

#define ComConf_ComIPdu_PDPdu_INP_1_1281R 0U


/* External Tx IPdu defines */
#if (defined ComConf_ComIPdu_PDPdu_BroadCast_1026T) /* To prevent double declaration */
#error ComConf_ComIPdu_PDPdu_BroadCast_1026T already defined
#endif /* #if (defined ComConf_ComIPdu_PDPdu_BroadCast_1026T) */

#define ComConf_ComIPdu_PDPdu_BroadCast_1026T 0U


#if (defined ComConf_ComIPdu_PDPdu_MCU_1_1027T) /* To prevent double declaration */
#error ComConf_ComIPdu_PDPdu_MCU_1_1027T already defined
#endif /* #if (defined ComConf_ComIPdu_PDPdu_MCU_1_1027T) */

#define ComConf_ComIPdu_PDPdu_MCU_1_1027T 1U


/* External Rx Signal IDs (no group signals) defines */
#if (defined ComConf_ComSignal_SGKeyStatus_1281R) /* To prevent double declaration */
#error ComConf_ComSignal_SGKeyStatus_1281R already defined
#endif /* #if (defined ComConf_ComSignal_SGKeyStatus_1281R) */

#define ComConf_ComSignal_SGKeyStatus_1281R 0U


#if (defined ComConf_ComSignal_SGKillSwitchStatus_1281R) /* To prevent double declaration */
#error ComConf_ComSignal_SGKillSwitchStatus_1281R already defined
#endif /* #if (defined ComConf_ComSignal_SGKillSwitchStatus_1281R) */

#define ComConf_ComSignal_SGKillSwitchStatus_1281R 1U


#if (defined ComConf_ComSignal_SGSideStandStatus_1281R) /* To prevent double declaration */
#error ComConf_ComSignal_SGSideStandStatus_1281R already defined
#endif /* #if (defined ComConf_ComSignal_SGSideStandStatus_1281R) */

#define ComConf_ComSignal_SGSideStandStatus_1281R 2U


#if (defined ComConf_ComSignal_SGSoC_1281R) /* To prevent double declaration */
#error ComConf_ComSignal_SGSoC_1281R already defined
#endif /* #if (defined ComConf_ComSignal_SGSoC_1281R) */

#define ComConf_ComSignal_SGSoC_1281R 3U


#if (defined ComConf_ComSignal_SGMotorTemp_1281R) /* To prevent double declaration */
#error ComConf_ComSignal_SGMotorTemp_1281R already defined
#endif /* #if (defined ComConf_ComSignal_SGMotorTemp_1281R) */

#define ComConf_ComSignal_SGMotorTemp_1281R 4U


#if (defined ComConf_ComSignal_SGMotorMode_1281R) /* To prevent double declaration */
#error ComConf_ComSignal_SGMotorMode_1281R already defined
#endif /* #if (defined ComConf_ComSignal_SGMotorMode_1281R) */

#define ComConf_ComSignal_SGMotorMode_1281R 5U


#if (defined ComConf_ComSignal_SGChargerConnected_1281R) /* To prevent double declaration */
#error ComConf_ComSignal_SGChargerConnected_1281R already defined
#endif /* #if (defined ComConf_ComSignal_SGChargerConnected_1281R) */

#define ComConf_ComSignal_SGChargerConnected_1281R 6U


/* External Tx Signal IDs (no group signals) defines */
#if (defined ComConf_ComSignal_SGModeChangeRequest_1027T) /* To prevent double declaration */
#error ComConf_ComSignal_SGModeChangeRequest_1027T already defined
#endif /* #if (defined ComConf_ComSignal_SGModeChangeRequest_1027T) */

#define MODE_CHANGE_REQUEST 0U


#if (defined ComConf_ComSignal_SGMotorOnOffRequest_1027T) /* To prevent double declaration */
#error ComConf_ComSignal_SGMotorOnOffRequest_1027T already defined
#endif /* #if (defined ComConf_ComSignal_SGMotorOnOffRequest_1027T) */

#define MOTOR_ON_OFF_REQUEST 1U


#if (defined ComConf_ComSignal_SGHornOutput_1026T) /* To prevent double declaration */
#error ComConf_ComSignal_SGHornOutput_1026T already defined
#endif /* #if (defined ComConf_ComSignal_SGHornOutput_1026T) */

#define HORN_OUTPUT_STATUS 2U


#if (defined ComConf_ComSignal_SGHighBeamOutput_1026T) /* To prevent double declaration */
#error ComConf_ComSignal_SGHighBeamOutput_1026T already defined
#endif /* #if (defined ComConf_ComSignal_SGHighBeamOutput_1026T) */

#define HB_OUTPUT_DUTY_CYCLE 3U


#if (defined ComConf_ComSignal_SGLeftIndicatorOutput_1026T) /* To prevent double declaration */
#error ComConf_ComSignal_SGLeftIndicatorOutput_1026T already defined
#endif /* #if (defined ComConf_ComSignal_SGLeftIndicatorOutput_1026T) */

#define LEFT_IND_OUTPUT_STATUS 4U


#if (defined ComConf_ComSignal_SGRightIndicatorOutput_1026T) /* To prevent double declaration */
#error ComConf_ComSignal_SGRightIndicatorOutput_1026T already defined
#endif /* #if (defined ComConf_ComSignal_SGRightIndicatorOutput_1026T) */

#define RIGHT_IND_OUTPUT_STATUS 5U


#if (defined ComConf_ComSignal_SGTailLampDutyCycle_1026T) /* To prevent double declaration */
#error ComConf_ComSignal_SGTailLampDutyCycle_1026T already defined
#endif /* #if (defined ComConf_ComSignal_SGTailLampDutyCycle_1026T) */

#define TAIL_LAMP_DUTY_CYCLE 6U


/* External Rx Group Signal IDs defines */
/* External Tx Group Signal IDs defines */
/* External Rx Signal Group IDs defines */
/* External Tx Signal Group IDs defines */

/*------------------[symbols without prefix for backward compatibility]-----*/
#if (defined COM_PROVIDE_LEGACY_SYMBOLIC_NAMES)

/* IPDU group ID defines */

#if (defined Com_RGCanNetwork) /* To prevent double declaration */
#error Com_RGCanNetwork already defined
#endif /* #if (defined Com_RGCanNetwork) */

#define Com_RGCanNetwork ComConf_ComIPduGroup_RGCanNetwork



#if (defined Com_RXPDUS_GLOBAL) /* To prevent double declaration */
#error Com_RXPDUS_GLOBAL already defined
#endif /* #if (defined Com_RXPDUS_GLOBAL) */

#define Com_RXPDUS_GLOBAL ComConf_ComIPduGroup_RXPDUS_GLOBAL



#if (defined Com_TGCanNetwork) /* To prevent double declaration */
#error Com_TGCanNetwork already defined
#endif /* #if (defined Com_TGCanNetwork) */

#define Com_TGCanNetwork ComConf_ComIPduGroup_TGCanNetwork



#if (defined Com_TXPDUS_GLOBAL) /* To prevent double declaration */
#error Com_TXPDUS_GLOBAL already defined
#endif /* #if (defined Com_TXPDUS_GLOBAL) */

#define Com_TXPDUS_GLOBAL ComConf_ComIPduGroup_TXPDUS_GLOBAL


/* External Rx IPdus defines */
#if (defined Com_PDPdu_INP_1_1281R) /* To prevent double declaration */
#error Com_PDPdu_INP_1_1281R already defined
#endif /* #if (defined Com_PDPdu_INP_1_1281R) */

#define Com_PDPdu_INP_1_1281R ComConf_ComIPdu_PDPdu_INP_1_1281R


/* External Tx IPdu defines */
#if (defined Com_PDPdu_BroadCast_1026T) /* To prevent double declaration */
#error Com_PDPdu_BroadCast_1026T already defined
#endif /* #if (defined Com_PDPdu_BroadCast_1026T) */

#define Com_PDPdu_BroadCast_1026T ComConf_ComIPdu_PDPdu_BroadCast_1026T


#if (defined Com_PDPdu_MCU_1_1027T) /* To prevent double declaration */
#error Com_PDPdu_MCU_1_1027T already defined
#endif /* #if (defined Com_PDPdu_MCU_1_1027T) */

#define Com_PDPdu_MCU_1_1027T ComConf_ComIPdu_PDPdu_MCU_1_1027T


/* External Rx Signal IDs (no group signals) defines */
#if (defined Com_SGKeyStatus_1281R) /* To prevent double declaration */
#error Com_SGKeyStatus_1281R already defined
#endif /* #if (defined Com_SGKeyStatus_1281R) */

#define Com_SGKeyStatus_1281R ComConf_ComSignal_SGKeyStatus_1281R


#if (defined Com_SGKillSwitchStatus_1281R) /* To prevent double declaration */
#error Com_SGKillSwitchStatus_1281R already defined
#endif /* #if (defined Com_SGKillSwitchStatus_1281R) */

#define Com_SGKillSwitchStatus_1281R ComConf_ComSignal_SGKillSwitchStatus_1281R


#if (defined Com_SGSideStandStatus_1281R) /* To prevent double declaration */
#error Com_SGSideStandStatus_1281R already defined
#endif /* #if (defined Com_SGSideStandStatus_1281R) */

#define Com_SGSideStandStatus_1281R ComConf_ComSignal_SGSideStandStatus_1281R


#if (defined Com_SGSoC_1281R) /* To prevent double declaration */
#error Com_SGSoC_1281R already defined
#endif /* #if (defined Com_SGSoC_1281R) */

#define Com_SGSoC_1281R ComConf_ComSignal_SGSoC_1281R


#if (defined Com_SGMotorTemp_1281R) /* To prevent double declaration */
#error Com_SGMotorTemp_1281R already defined
#endif /* #if (defined Com_SGMotorTemp_1281R) */

#define Com_SGMotorTemp_1281R ComConf_ComSignal_SGMotorTemp_1281R


#if (defined Com_SGMotorMode_1281R) /* To prevent double declaration */
#error Com_SGMotorMode_1281R already defined
#endif /* #if (defined Com_SGMotorMode_1281R) */

#define Com_SGMotorMode_1281R ComConf_ComSignal_SGMotorMode_1281R


#if (defined Com_SGChargerConnected_1281R) /* To prevent double declaration */
#error Com_SGChargerConnected_1281R already defined
#endif /* #if (defined Com_SGChargerConnected_1281R) */

#define Com_SGChargerConnected_1281R ComConf_ComSignal_SGChargerConnected_1281R


/* External Tx Signal IDs (no group signals) defines */
#if (defined Com_SGModeChangeRequest_1027T) /* To prevent double declaration */
#error Com_SGModeChangeRequest_1027T already defined
#endif /* #if (defined Com_SGModeChangeRequest_1027T) */

#define Com_SGModeChangeRequest_1027T ComConf_ComSignal_SGModeChangeRequest_1027T


#if (defined Com_SGMotorOnOffRequest_1027T) /* To prevent double declaration */
#error Com_SGMotorOnOffRequest_1027T already defined
#endif /* #if (defined Com_SGMotorOnOffRequest_1027T) */

#define Com_SGMotorOnOffRequest_1027T ComConf_ComSignal_SGMotorOnOffRequest_1027T


#if (defined Com_SGHornOutput_1026T) /* To prevent double declaration */
#error Com_SGHornOutput_1026T already defined
#endif /* #if (defined Com_SGHornOutput_1026T) */

#define Com_SGHornOutput_1026T ComConf_ComSignal_SGHornOutput_1026T


#if (defined Com_SGHighBeamOutput_1026T) /* To prevent double declaration */
#error Com_SGHighBeamOutput_1026T already defined
#endif /* #if (defined Com_SGHighBeamOutput_1026T) */

#define Com_SGHighBeamOutput_1026T ComConf_ComSignal_SGHighBeamOutput_1026T


#if (defined Com_SGLeftIndicatorOutput_1026T) /* To prevent double declaration */
#error Com_SGLeftIndicatorOutput_1026T already defined
#endif /* #if (defined Com_SGLeftIndicatorOutput_1026T) */

#define Com_SGLeftIndicatorOutput_1026T ComConf_ComSignal_SGLeftIndicatorOutput_1026T


#if (defined Com_SGRightIndicatorOutput_1026T) /* To prevent double declaration */
#error Com_SGRightIndicatorOutput_1026T already defined
#endif /* #if (defined Com_SGRightIndicatorOutput_1026T) */

#define Com_SGRightIndicatorOutput_1026T ComConf_ComSignal_SGRightIndicatorOutput_1026T


#if (defined Com_SGTailLampDutyCycle_1026T) /* To prevent double declaration */
#error Com_SGTailLampDutyCycle_1026T already defined
#endif /* #if (defined Com_SGTailLampDutyCycle_1026T) */

#define Com_SGTailLampDutyCycle_1026T ComConf_ComSignal_SGTailLampDutyCycle_1026T


/* External Rx Group Signal IDs defines */
/* External Tx Group Signal IDs defines */
/* External Rx Signal Group IDs defines */
/* External Tx Signal Group IDs defines */
#endif /* (defined COM_PROVIDE_LEGACY_SYMBOLIC_NAMES) */

/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/

/*==================[internal function definitions]=========================*/

/** @} doxygen end group definition */
#endif /* ifndef COM_SYMBOLIC_NAMES_PB_CFG_H  */
/*==================[end of file]===========================================*/
