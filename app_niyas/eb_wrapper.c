#include "eb_wrapper.h"
#include "Com_SymbolicNames_PBcfg.h"
#include "asdk_platform.h"
#include "asdk_system.h"
#include "asdk_can.h"

uint8_t key_status = 0;
uint8_t kill_switch_status = 0;
uint8_t side_stand_status = 0;
uint8_t soc = 0;
uint8_t motor_temp = 0;
uint8_t motor_mode = 0;
uint8_t charger_connected = 0;

void Rte_COMCbk_SGKeyStatus_1281R(void)
{
  Com_ReceiveSignal(ComConf_ComSignal_SGKeyStatus_1281R, &key_status);
}

void Rte_COMCbk_SGKillSwitchStatus_1281R(void)
{
  Com_ReceiveSignal(ComConf_ComSignal_SGKillSwitchStatus_1281R, &kill_switch_status);
}

void Rte_COMCbk_SGSideStandStatus_1281R(void)
{
  Com_ReceiveSignal(ComConf_ComSignal_SGSideStandStatus_1281R, &side_stand_status);
}

void Rte_COMCbk_SGSoC_1281R(void)
{
  Com_ReceiveSignal(ComConf_ComSignal_SGSoC_1281R, &soc);
}

void Rte_COMCbk_SGMotorTemp_1281R(void)
{
  Com_ReceiveSignal(ComConf_ComSignal_SGMotorTemp_1281R, &motor_temp);
}

void Rte_COMCbk_SGMotorMode_1281R(void)
{
  Com_ReceiveSignal(ComConf_ComSignal_SGMotorMode_1281R, &motor_mode);
}

void Rte_COMCbk_SGChargerConnected_1281R(void)
{
  Com_ReceiveSignal(ComConf_ComSignal_SGChargerConnected_1281R, &charger_connected);
}

void ComM_Init(const ComM_ConfigType *ConfigPtr)
{
  /* empty stub */
}

uint8_t Det_ASR40_ReportError(uint16_t ModuleId, uint8_t InstanceId, uint8_t ApiId, uint8_t ErrorId)
{
  return E_OK;
}

uint8_t Det_ASR43_ReportRuntimeError(uint16_t ModuleId, uint8_t InstanceId, uint8_t ApiId, uint8_t ErrorId)
{
  return E_OK;
}

void SchM_Enter_Com_SCHM_COM_EXCLUSIVE_AREA_0(void)
{
  // SuspendAllInterrupts();
  asdk_sys_disable_interrupts();

} /* FUNC(void, RTE_CODE) SchM_Enter_Com_SCHM_COM_EXCLUSIVE_AREA_0 (void) */

void SchM_Exit_Com_SCHM_COM_EXCLUSIVE_AREA_0(void)
{
  // ResumeAllInterrupts();
  asdk_sys_enable_interrupts();

} /* FUNC(void, RTE_CODE) SchM_Exit_Com_SCHM_COM_EXCLUSIVE_AREA_0 (void) */

void SchM_Enter_Com_SCHM_COM_EXCLUSIVE_AREA_1(void)
{
  //   SuspendAllInterrupts();
  asdk_sys_disable_interrupts();

} /* FUNC(void, RTE_CODE) SchM_Enter_Com_SCHM_COM_EXCLUSIVE_AREA_1 (void) */

void SchM_Exit_Com_SCHM_COM_EXCLUSIVE_AREA_1(void)
{
  //   ResumeAllInterrupts();
  asdk_sys_enable_interrupts();

} /* FUNC(void, RTE_CODE) SchM_Exit_Com_SCHM_COM_EXCLUSIVE_AREA_1 (void) */

void SchM_Enter_CanIf_SCHM_CANIF_EXCLUSIVE_AREA_0(void)
{
  // SuspendAllInterrupts();
  asdk_sys_disable_interrupts();

} /* FUNC(void, RTE_CODE) SchM_Enter_CanIf_SCHM_CANIF_EXCLUSIVE_AREA_0 (void) */

void SchM_Exit_CanIf_SCHM_CANIF_EXCLUSIVE_AREA_0(void)
{
  // ResumeAllInterrupts();
  asdk_sys_enable_interrupts();

} /* FUNC(void, RTE_CODE) SchM_Exit_CanIf_SCHM_CANIF_EXCLUSIVE_AREA_0 (void) */

void TS_MemCpy32(void *dst, const void *src, const uint32_t len)
{
  memcpy(dst, src, (size_t)len);
}

uint8_t TS_PlatformSigIsValid(uint32_t signature)
{
  return true;
}

void OS_UserResumeInterrupts(os_intlocktype_t)
{
  asdk_sys_enable_interrupts();
}

void OS_UserSuspendInterrupts(os_intlocktype_t)
{
  asdk_sys_disable_interrupts();
}

Can_ReturnType Can_SetControllerMode(uint8_t Controller, Can_StateTransitionType Transition)
{
  return CAN_OK;
}

Can_ReturnType Can_Write(uint8_t Hth, const Can_PduType *PduInfo)
{
  asdk_errorcode_t ret;
  asdk_can_message_t can_msg;

  /* Call asdk_can_write() to transmit the Can message */
  can_msg.can_id = PduInfo->id;
  can_msg.dlc = PduInfo->length;
  can_msg.message = PduInfo->sdu;

  if (0x402 == can_msg.can_id)
    ret = asdk_can_write(1, 0, &can_msg);
  else if (0x403 == can_msg.can_id)
    ret = asdk_can_write(1, 1, &can_msg);
  else
    return CAN_NOT_OK;

  if (ASDK_CAN_SUCCESS != ret)
  {
    /* message transmission failed ... */
    return CAN_NOT_OK;
  }
  else
  {
    /* message transmission successful */
    return CAN_OK;
  }
}