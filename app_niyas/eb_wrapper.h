#ifndef __EB_WRAPPER_H
#define __EB_WRAPPER_H

#include <stdint.h>
#include <string.h>

// #define TS_AtomicSetBit_8(a, bi) OS_AtomicTSSetBit_8((os_uint8_t volatile *)(a), (os_uint32_t)(bi))

#define CANIF_INVALID_DLC                   0xFFU
#define E_NOT_OK 1U
#define E_OK 0U

typedef uint16_t PduIdType;
typedef uint32_t Can_IdType;
typedef uint16_t Com_SignalIdType;
typedef uint8_t ComM_ASR40_ModeType;
typedef void  CanIf_ConfigType;

typedef struct /* CanIf_TxLPduConfigType */ {
    Can_IdType canId; /* CAN ID */
    uint8_t hth; /* HTH */
    PduIdType sourcePduId_UL; /* source PDU ID of upper layer */
    uint8_t userType; /* type of callback function */
    uint8_t intCtrlIdx; /* CanIf internal controller index */
    uint32_t PduLength; /* PDU length in EcuC */
    uint8_t truncateOptions; /* PDU options regarding its truncation */
} CanIf_TxLPduConfigType;

/** \brief struct Can_PduType
 **
 ** This type is used to provide ID, DLC and SDU from CAN interface to CAN driver.
 */
typedef struct can_pdutype_struct
{
  /** Pointer to the message buffer in RAM */
  uint8_t *sdu;
  /** ID of the CAN message */
  Can_IdType id;
  /** Pdu Handle */
  PduIdType swPduHandle;
  /** Length of the message in bytes */
  uint8_t length;
} Can_PduType;


/** \brief enum Can_ReturnType
 **
 ** Return values of CAN driver API .
 */
typedef enum can_returntype_enum
{
  CAN_OK,                 /**< Operation done */
  CAN_NOT_OK,             /**< Error occurred or wakeup event occurred during
                               sleep transition */
  CAN_BUSY                /**< Transmission already in progress */
} Can_ReturnType;

/** \brief enum Can_StateTransitionType
 **
 ** State transitions that are used by the function CAN_SetControllerMode
 */
typedef enum can_statetransitiontype_enum
{
  CAN_T_START,            /**< Start controller */
  CAN_T_STOP,             /**< Stop controller */
  CAN_T_SLEEP,            /**< Put controller in sleep mode */
  CAN_T_WAKEUP            /**< Wake up controller from sleep mode */
} Can_StateTransitionType;

/** \brief Type for PDU channel mode requests
 **
 ** This type defines the possible mode requests that can be stated for a
 ** PDU channel.
 */
typedef enum
{
  CANIF_OFFLINE = 0U,      /**<Transmit and receive path of the corresponding channel are disabled => no communication mode */
  CANIF_TX_OFFLINE,        /**<Transmit path of the corresponding channel is disabled. The receive path is enabled. */
  CANIF_TX_OFFLINE_ACTIVE, /**<Transmit path of the corresponding channel is in offline active mode. The receive path is disabled. */
  CANIF_ONLINE             /**<Transmit and receive path of the corresponding channel are enabled => full operation mode */
}CanIf_PduModeType;

/** \brief type for storage of basic information about a PDU
 *
 * This type shall be used to store the basic information about a PDU of
 * any type, namely a pointer variable pointing to it's SDU (payload) and
 * the corresponding length of the SDU in bytes.
 */
/* !LINKSTO Base.ASR403.COMTYPE011,1 */
typedef struct
{
   /** \brief pointer to the SDU of the PDU  */
   uint8_t *SduDataPtr;
   /** \brief length of SDU in bytes */
   uint32_t SduLength;
} PduInfoType;

typedef struct can_hwtype_struct
{
  /** Standard/Extended CAN ID of CAN L-PDU */
  Can_IdType CanId;
  /** Length of the message in bytes */
  uint8_t ControllerId;
  /** ID of the corresponding hardware object Range */
  uint8_t Hoh;
} Can_HwType;

typedef struct /* ComM_ConfigType */ {
    uint32_t PlatformSignature; /* Used to validate the platform */
    uint32_t LcfgSignature; /* Used to validate the post build configuration against the link time configuration */
    uint32_t CfgSignature; /* Used to validate the post build configuration against the precompile time configuration */
    uint32_t PublicInfoSignature; /* Used to validate Public information */
    uint8_t  pUsersOfAllChannel; /* Reference to COMM_ConfigLayoutType.aUsersOfAllChannel */
    uint16_t NumUsersOfAllChannel[2]; /* Index of first user of a channel in COMM_ConfigLayoutType.aUsersOfAllChannel */
    uint8_t  pChannelsOfAllUser; /* Reference to COMM_ConfigLayoutType.aChannelsOfAllUser */
    uint16_t NumChannelsOfAllUser[2]; /* Index of first channel of a user in COMM_ConfigLayoutType.aChannelsOfAllUser */
    uint16_t DirectNumChannelsOfAllUser[2]; /* Index of first channel of a user in COMM_ConfigLayoutType.aChannelsOfAllUser */
} ComM_ConfigType;

/* External variables and buffers */
extern const CanIf_TxLPduConfigType CanIf_TxPduConfigPtr[];
extern CanIf_PduModeType CanIf_PduMode[];
extern uint8_t Com_InitStatus;
extern const uint32_t Com_config_init;
extern const uint32_t Pdur_config_init;
extern uint8_t CanIf_CanControllerMode[];

/* External APIs */
extern uint8_t Com_SendSignal (Com_SignalIdType SignalId, const void *SignalDataPtr);
extern uint8_t Com_ReceiveSignal (Com_SignalIdType SignalId, void *SignalDataPtr);
extern void OS_UserResumeInterrupts(os_intlocktype_t);
extern void OS_UserSuspendInterrupts(os_intlocktype_t);
extern void CanIf_Init (const CanIf_ConfigType *ConfigPtr);
extern void Com_MainFunctionRouteSignals (void);
extern void Com_MainFunctionTx (void);
extern void Com_MainFunctionRx (void);

/* Empty Stubs */
void ComM_Init (const ComM_ConfigType *ConfigPtr);
void SchM_Enter_Com_SCHM_COM_EXCLUSIVE_AREA_0 (void);
void SchM_Exit_Com_SCHM_COM_EXCLUSIVE_AREA_0 (void);
void SchM_Enter_Com_SCHM_COM_EXCLUSIVE_AREA_1 (void);
void SchM_Exit_Com_SCHM_COM_EXCLUSIVE_AREA_1 (void);
void SchM_Enter_CanIf_SCHM_CANIF_EXCLUSIVE_AREA_0 (void);
void SchM_Exit_CanIf_SCHM_CANIF_EXCLUSIVE_AREA_0 (void);
uint8_t Det_ASR40_ReportError (uint16_t ModuleId, uint8_t InstanceId, uint8_t ApiId, uint8_t ErrorId);
uint8_t Det_ASR43_ReportRuntimeError(uint16_t ModuleId, uint8_t InstanceId, uint8_t ApiId, uint8_t ErrorId);
Can_ReturnType Can_SetControllerMode(uint8_t Controller, Can_StateTransitionType Transition);

/* Stubs */
void TS_MemCpy32 (void *dst, const void *src, const uint32_t len);
uint8_t TS_PlatformSigIsValid (uint32_t signature);
Can_ReturnType Can_Write(uint8_t Hth, const Can_PduType *PduInfo);

#endif