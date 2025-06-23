/*************************************************************************************************/
/*!
 *  \file
 *
 *  \brief      802.15.4 radio driver interface file.
 *
 *  Copyright (c) 2019-2024 Packetcraft, Inc.  All rights reserved.
 *  Packetcraft, Inc. confidential and proprietary.
 *  
 *  IMPORTANT.  Your use of this file is governed by a Software License Agreement
 *  ("Agreement") that must be accepted in order to download or otherwise receive a
 *  copy of this file.  You may not use or copy this file for any purpose other than
 *  as described in the Agreement.  If you do not agree to all of the terms of the
 *  Agreement do not use this file and delete all copies in your possession or control;
 *  if you do not have a copy of the Agreement, you must contact Packetcraft, Inc. prior
 *  to any use, copying or further distribution of this software.
 */
/*************************************************************************************************/

#ifndef PAL_RADIO154_H
#define PAL_RADIO154_H

#include "pal_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/* \brief     Special addresses. */
#define PAL_RADIO_154_BROADCAST_PANID     0xffff   /*!< TBD */
#define PAL_RADIO_154_BROADCAST_ADDR      0xffff   /*!< TBD */
#define PAL_RADIO_154_UNASSIGNED_ADDR     0xffff   /*!< TBD */
#define PAL_RADIO_154_NO_SHT_ADDR         0xfffe   /*!< TBD */
#define PAL_RADIO_154_UNASSIGNED_PAN_ID   0xffff   /*!< TBD */

/* \brief     PAN Id length. */
#define PAL_RADIO_154_PAN_ID_LEN          2    /*!< TBD */

/* \brief     Address lengths. */
#define PAL_RADIO_154_SHORT_ADDR_LEN      2    /*!< TBD */
#define PAL_RADIO_154_EXTENDED_ADDR_LEN   8    /*!< TBD */

/* \brief     Symbols to microseconds for 802.15.4-2006 2.4GHz PHY. */
#define PAL_RADIO_154_SYMB_TO_US(x)       ((x) * 16)            /*!< PAL_RADIO_154_SYMB_TO_US. */
#define PAL_RADIO_154_SYMB_TO_MS(x)       (((x) * 16) / 1000)   /*!< PAL_RADIO_154_SYMB_TO_MS. */
#define PAL_RADIO_154_US_TO_SYMB(x)       ((x) / 16)            /*!< PAL_RADIO_154_US_TO_SYMB. */

/* \brief     Transaction persistence time factor. */
#define PAL_RADIO_154_TPT_TO_MS(x)        (((x) * 15723) >> 10) /*!< 15723/1024 approximates to 15.36. */

/**************************************************************************************************
  MAC frame format
  802.15.4-2006 Section 7.2
**************************************************************************************************/

/*! \brief    Size of frame control in octets. */
#define PAL_RADIO_154_FRAME_CONTROL_LEN   2

/*! \brief    Size of sequence number in octets. */
#define PAL_RADIO_154_SEQ_NUMBER_LEN      1

/*! \brief    Size of command frame identifier in octets. */
#define PAL_RADIO_154_CMD_FRM_ID_LEN      1

/*! \brief    Size of FCS in octets. */
#define PAL_RADIO_154_FCS_LEN             2

/*! \brief    FCS initialization value. */
#define PAL_RADIO_154_FCS_INIT_VALUE      0x0000

/*! \brief    CRC polynomial value. */
#define PAL_RADIO_154_CRC_POLYNOMIAL      0x011021  /*!< G(x) = x^16 + x^12 + x^5 + 1 */

/*! \brief    Frame control bits and fields. */
#define PAL_RADIO_154_FC_FRAME_TYPE_SHIFT       0
#define PAL_RADIO_154_FC_FRAME_TYPE_MASK        0x0007  /*!< Bitmask. */
#define PAL_RADIO_154_FC_FRAME_TYPE_CD_MASK     0x0001  /*!< Convenient way of checking if MAC command or data. */
#define PAL_RADIO_154_FC_FRAME_TYPE_CMD_MASK    0x0003  /*!< Convenient way of checking if MAC command. */
#define PAL_RADIO_154_FC_FRAME_TYPE(x)          (((x) & PAL_RADIO_154_FC_FRAME_TYPE_MASK)/*>> PAL_RADIO_154_FC_FRAME_TYPE_SHIFT*/)  /*!< Optimized bit 0. */

#define PAL_RADIO_154_FC_SECURITY_ENABLED_SHIFT 3       /*!< TBD */
#define PAL_RADIO_154_FC_SECURITY_ENABLED_MASK  0x0008  /*!< TBD */
#define PAL_RADIO_154_FC_SECURITY_ENABLED(x)    (((x) & PAL_RADIO_154_FC_SECURITY_ENABLED_MASK) >> PAL_RADIO_154_FC_SECURITY_ENABLED_SHIFT) /*!< TBD */

#define PAL_RADIO_154_FC_FRAME_PENDING_SHIFT    4       /*!< TBD */
#define PAL_RADIO_154_FC_FRAME_PENDING_MASK     0x0010  /*!< TBD */
#define PAL_RADIO_154_FC_FRAME_PENDING(x)       (((x) & PAL_RADIO_154_FC_FRAME_PENDING_MASK) >> PAL_RADIO_154_FC_FRAME_PENDING_SHIFT) /*!< TBD */

#define PAL_RADIO_154_FC_ACK_REQUEST_SHIFT      5       /*!< TBD */
#define PAL_RADIO_154_FC_ACK_REQUEST_MASK       0x0020  /*!< TBD */
#define PAL_RADIO_154_FC_ACK_REQUEST(x)         (((x) & PAL_RADIO_154_FC_ACK_REQUEST_MASK) >> PAL_RADIO_154_FC_ACK_REQUEST_SHIFT) /*!< TBD */

#define PAL_RADIO_154_FC_PAN_ID_COMP_SHIFT      6       /*!< TBD */
#define PAL_RADIO_154_FC_PAN_ID_COMP_MASK       0x0040  /*!< TBD */
#define PAL_RADIO_154_FC_PAN_ID_COMP(x)         (((x) & PAL_RADIO_154_FC_PAN_ID_COMP_MASK) >> PAL_RADIO_154_FC_PAN_ID_COMP_SHIFT) /*!< TBD */

#define PAL_RADIO_154_FC_DST_ADDR_MODE_SHIFT    10      /*!< TBD */
#define PAL_RADIO_154_FC_DST_ADDR_MODE_MASK     0x0C00  /*!< TBD */
#define PAL_RADIO_154_FC_DST_ADDR_MODE(x)       (((x) & PAL_RADIO_154_FC_DST_ADDR_MODE_MASK) >> PAL_RADIO_154_FC_DST_ADDR_MODE_SHIFT) /*!< TBD */

#define PAL_RADIO_154_FC_FRAME_VERSION_SHIFT    12      /*!< TBD */
#define PAL_RADIO_154_FC_FRAME_VERSION_MASK     0x3000  /*!< TBD */
#define PAL_RADIO_154_FC_FRAME_VERSION(x)       (((x) & PAL_RADIO_154_FC_FRAME_VERSION_MASK) >> PAL_RADIO_154_FC_FRAME_VERSION_SHIFT) /*!< TBD */

#define PAL_RADIO_154_FC_SRC_ADDR_MODE_SHIFT    14      /*!< TBD */
#define PAL_RADIO_154_FC_SRC_ADDR_MODE_MASK     0xC000  /*!< TBD */
#define PAL_RADIO_154_FC_SRC_ADDR_MODE(x)       (((x) & PAL_RADIO_154_FC_SRC_ADDR_MODE_MASK) >> PAL_RADIO_154_FC_SRC_ADDR_MODE_SHIFT) /*!< TBD */

/*! \brief    Mask for checking legacy security. */
#define PAL_RADIO_154_FC_LEGACY_SEC_TEST(x)     (((x) & (PAL_RADIO_154_FC_SECURITY_ENABLED_MASK | PAL_RADIO_154_FC_FRAME_VERSION_MASK)) == PAL_RADIO_154_FC_SECURITY_ENABLED_MASK) /*!< TBD */

/*! \brief    Mask for checking frame pending processing based on ack. requested and being a MAC command frame. */
#define PAL_RADIO_154_FC_FRAME_TYPE_FP_TEST     (PAL_RADIO_154_FC_ACK_REQUEST_MASK | PAL_RADIO_154_FC_FRAME_TYPE_CMD_MASK)

/*! \brief    Mask for checking ack. sending based on ack. requested and being a MAC command or data frame. */
#define PAL_RADIO_154_FC_FRAME_TYPE_ACK_TEST    (PAL_RADIO_154_FC_ACK_REQUEST_MASK | PAL_RADIO_154_FC_FRAME_TYPE_CD_MASK)

#define PAL_RADIO_154_SCAN_MAX_PD_ENTRIES       16  /*!< Note - arbitrary number and could make it easy by sending all beacons using beacon notify indication. */
#define PAL_RADIO_154_SCAN_MAX_ED_ENTRIES       16  /*!< Note - can't have more than 16 for 2.4GHz. */

/**************************************************************************************************
  PHY definitions
**************************************************************************************************/

/*! \brief    Symbol duration in microseconds (2450 MHz O-QPSK). */
#define PAL_RADIO_154_SYMBOL_DURATION         16

/*! \brief    The number of symbols per octet (2450 MHz O-QPSK). */
#define PAL_RADIO_154_SYMBOLS_PER_OCTET       2

/*! \brief    ED duration in symbols (802.15.4-2006 6.9.7). */
#define PAL_RADIO_154_ED_DURATION             8

/*! \brief    ED sensitivity offset in dBm (802.15.4-2006 6.9.9). */
#define PAL_RADIO_154_ED_OFFSET               10

/**************************************************************************************************
  Preamble field length
  802.15.4-2006 Table 19
**************************************************************************************************/

/*! \brief    Preamble field length in symbols (2450 MHz O-QPSK). */
#define PAL_RADIO_154_PREAMBLE_FIELD_LENGTH   8

/*! \brief    SFD field length in symbols (2450 MHz O-QPSK). */
#define PAL_RADIO_154_SFD_FIELD_LENGTH        2

/**************************************************************************************************
  PHY constants
  802.15.4-2006 Table 22
**************************************************************************************************/

/*! \brief    The maximum PSDU size (in octets) the PHY shall be able to receive. */
#define PAL_RADIO_154_MAX_PHY_PKT_SIZE        127

/*! \brief    RX-to-TX or TX-to-RX maximum turnaround time (in symbol periods). */
#define PAL_RADIO_154_TURNAROUND_TIME         12

/**************************************************************************************************
  MAC sublayer constants
  802.15.4-2006 Table 85
**************************************************************************************************/

/*! \brief    SHR duration for 802.15.4-2006 (2.4GHz PHY). */
#define PAL_RADIO_154_SHR_DURATION            10

/*! \brief    Symbols per octet for 802.15.4-2006 (2.4GHz PHY). */
#define PAL_RADIO_154_SYMB_PER_OCTET          2

/*! \brief    The number of symbols forming a superframe slot when the superframe order is equal to 0. */
#define PAL_RADIO_154_BASE_SLOT_DURN          60

/*! \brief    The number of symbols forming a superframe when the superframe order is equal to 0. */
#define PAL_RADIO_154_BASE_SFRM_DURN   (PAL_RADIO_154_BASE_SLOT_DURN * PAL_RADIO_154_NUM_SFRM_SLOTS)

/*! \brief    The number of symbols for energy detect scan. */
#define PAL_RADIO_154_ED_SCAN_DURATION        (PAL_RADIO_154_BASE_SFRM_DURN / 2)

/* PAL_RADIO_154_EXTENDED_ADDRESS             Now a vendor-specific PIB attribute. */

/*! \brief    The maximum number of octets added by the MAC sublayer to the MAC payload of a beacon frame. */
#define PAL_RADIO_154_MAX_BCN_OVERHEAD        75

/*! \brief    The maximum beacon payload length. */
#define PAL_RADIO_154_MAX_BCN_PYD_LEN   (PAL_RADIO_154_MAX_PHY_PKT_SIZE - PAL_RADIO_154_MAX_BCN_OVERHEAD)

/*! \brief    The number of slots contained in any superframe. */
#define PAL_RADIO_154_NUM_SFRM_SLOTS          16

/*! \brief    The number of symbols forming the basic time period used by the CSMA-CA algorithm. */
#define PAL_RADIO_154_UNIT_BACKOFF_PERIOD     20

/*! \brief    The number of symbols for receive ack. timeout. */
#define PAL_RADIO_154_RX_ACK_TIMEOUT_SYMB     PAL_RADIO_154_UNIT_BACKOFF_PERIOD + \
                                              PAL_RADIO_154_TURNAROUND_TIME + \
                                              PAL_RADIO_154_SHR_DURATION + \
                                              (6 * PAL_RADIO_154_SYMB_PER_OCTET)

/**************************************************************************************************
  MAC addressing modes
  802.15.4-2006 Table 80
**************************************************************************************************/

/*! \brief      Addressing mode. */
typedef enum
{
  PAL_RADIO_154_ADDR_MODE_NONE     = 0,
  PAL_RADIO_154_ADDR_MODE_SHORT    = 2,
  PAL_RADIO_154_ADDR_MODE_EXTENDED = 3
} PalRadio154AddrMode_t;

/**************************************************************************************************
  MAC frame types
  802.15.4-2006 Table 79
**************************************************************************************************/

/*! \brief      Values of frame type in Frame Control. */
typedef enum
{
  PAL_RADIO_154_FRAME_TYPE_BEACON         = 0,
  PAL_RADIO_154_FRAME_TYPE_DATA           = 1,
  PAL_RADIO_154_FRAME_TYPE_ACKNOWLEDGMENT = 2,
  PAL_RADIO_154_FRAME_TYPE_MAC_COMMAND    = 3,
  PAL_RADIO_154_FRAME_TYPE_ILLEGAL4       = 4,
  PAL_RADIO_154_FRAME_TYPE_ILLEGAL5       = 5,
  PAL_RADIO_154_FRAME_TYPE_ILLEGAL6       = 6,
  PAL_RADIO_154_FRAME_TYPE_ILLEGAL7       = 7
} PalRadio154FrameType_t;

/**************************************************************************************************
  MAC command types
  802.15.4-2006 Table 82
**************************************************************************************************/

/*! \brief    Values of MAC command type. */
typedef enum
{
  PAL_RADIO_154_CMD_FRAME_TYPE_ASSOC_REQ      = 1,
  PAL_RADIO_154_CMD_FRAME_TYPE_ASSOC_RSP      = 2,
  PAL_RADIO_154_CMD_FRAME_TYPE_DISASSOC_NTF   = 3,
  PAL_RADIO_154_CMD_FRAME_TYPE_DATA_REQ       = 4,
  PAL_RADIO_154_CMD_FRAME_TYPE_PANID_CNFL_NTF = 5,
  PAL_RADIO_154_CMD_FRAME_TYPE_ORPHAN_NTF     = 6,
  PAL_RADIO_154_CMD_FRAME_TYPE_BEACON_REQ     = 7,
  PAL_RADIO_154_CMD_FRAME_TYPE_COORD_REALIGN  = 8,
  PAL_RADIO_154_CMD_FRAME_TYPE_GTS_REQ        = 9
} PalRadio154CmdType_t;

/*! \brief    MAC device type (vendor specific). */
typedef enum
{
  PAL_RADIO_154_DEV_TYPE_DEVICE,      /*!< Device is not a coordinator. */
  PAL_RADIO_154_DEV_TYPE_COORD,       /*!< Device is a coordinator but not a PAN coordinator. */
  PAL_RADIO_154_DEV_TYPE_PAN_COORD,   /*!< Device is a PAN coordinator. */
} PalRadio154DevType_t;

/**************************************************************************************************
  Data Types
**************************************************************************************************/

/*! \brief      Radio state. */
typedef enum
{
  PAL_RADIO_154_STATE_ERROR         = 0,  /* (error state) */
  PAL_RADIO_154_STATE_UNINITIALIZED = 0,  /* Unin */
  PAL_RADIO_154_STATE_INITIALIZED   = 1,  /* Init */
  PAL_RADIO_154_STATE_ENABLED       = 2,  /* Enbl */
  PAL_RADIO_154_STATE_OFF           = 3,  /* ROff */
  PAL_RADIO_154_STATE_RX_HDR        = 4,  /* RxHd */
  PAL_RADIO_154_STATE_RX_FRM        = 5,  /* RxFm */
  PAL_RADIO_154_STATE_RX_ACK        = 6,  /* RxAk */
  PAL_RADIO_154_STATE_ED            = 7,  /* EnDt */
  PAL_RADIO_154_STATE_TX            = 8,  /* TxFm */
  PAL_RADIO_154_STATE_TX_CCA        = 9,  /* TxCC */
  PAL_RADIO_154_STATE_TX_ACK        = 10, /* TxAk */
  PAL_RADIO_154_NUM_STATES
} PalRadio154State_t;

/*! \brief      Operation status. */
typedef enum
{
  /* Successful statuses. */
  PAL_RADIO_154_STATUS_SUCCESS,           /*!< Operation completed successfully. */
  PAL_RADIO_154_STATUS_RX_TX_ACK_CMPL,    /*!< Rx, tx ack. completed. */
  PAL_RADIO_154_STATUS_TX_RX_ACK_CMPL,    /*!< Tx, rx ack. completed. */
  /* Failed statuses */
  PAL_RADIO_154_STATUS_RX_TO,             /*!< Rx, timed out. */
  PAL_RADIO_154_STATUS_RX_CRC_FAILED,     /*!< Rx, CRC failed. */
  PAL_RADIO_154_STATUS_TX_CCA_FAILED,     /*!< Tx, CCA failed. */
  PAL_RADIO_154_STATUS_TX_RX_ACK_TO,      /*!< Tx, rx ack. timed out. */
  PAL_RADIO_154_STATUS_TX_FAILURE         /*!< Tx, operation failed. */
} PalRadio154Status_t;

/*! \brief  Operation flags. */
typedef enum
{
  PAL_RADIO_154_FLAG_TX_AUTO_RX_ACK = 1,  /*!< Automatically wait for ack. after transmit completes. */
  PAL_RADIO_154_FLAG_RX_AUTO_TX_ACK = 2,  /*!< Automatically send ack. after receive completes. */
  PAL_RADIO_154_FLAG_AUTO_ACK       = 3,  /*!< Auto Tx and Rx ack. */
  PAL_RADIO_154_FLAG_DIS_CCA        = 4,  /*!< Disable CCA before transmit. */
  PAL_RADIO_154_FLAG_RAW            = 8,  /*!< Treat as raw frame. */
  PAL_RADIO_154_FLAG_NO_RETRIES     = 16  /*!< No retries (used for indirect frames). */
} PalRadio154OpFlags_t;

/*! \brief  Subsequent processing flags. */
typedef enum
{
  PAL_RADIO_154_FLAG_CONTINUE = 0,                /*!< Continue processing. */
  PAL_RADIO_154_FLAG_NO_FURTHER_PROC = (1 << 0),  /*!< No further processing. */
  PAL_RADIO_154_FLAG_SET_ACK_FP = (1 << 1)        /*!< Set frame pending in ack. */
} PalRadio154ProcFlags_t;

/*! \brief  Rx completion call signature. */
typedef uint8_t (*PalRadio154RxComp_t)(PalRadio154Status_t radioStatus, uint16_t len, int8_t rssi, uint32_t timestamp);

/*! \brief  Tx completion call signature. */
typedef uint8_t (*PalRadio154TxComp_t)(PalRadio154Status_t radioStatus, bool fp);

/*! \brief  ED completion call signature. */
typedef uint8_t (*PalRadio154EdComp_t)(PalRadio154Status_t radioStatus, uint8_t ed);

/*! \brief  Frame pending check call signature. */
typedef bool (*PalRadio154FpChk_t)(PalRadio154AddrMode_t addrMode, uint64_t addr);

/*! \brief  802.15.4 radio driver statistics. */
typedef struct
{
  uint32_t txSchMiss;               /*!< Number of missed Rx. */
  uint32_t rxSchMiss;               /*!< Number of missed Tx. */
  uint32_t txPkt;                   /*!< Number of successful Tx. */
  uint32_t txDmaFail;               /*!< Number of Tx DMA failures. */
  uint32_t rxPkt;                   /*!< Number of successful Rx. */
  uint32_t rxPktTimeout;            /*!< Number of Rx timeouts. */
  uint32_t rxFilterFail;            /*!< Number of Rx filter failures. */
  uint32_t rxCrcFail;               /*!< Number of CRC failures. */
  uint32_t rxDmaFail;               /*!< Number of Rx DMA failures. */
  uint32_t edReq;                   /*!< Number of ED requests. */
  uint32_t ed;                      /*!< Number of successful ED. */
  uint32_t edSchMiss;               /*!< Number of missed ED. */
  uint32_t ccaSchMiss;              /*!< Number of missed CCA. */
  uint32_t txReq;                   /*!< Number of Tx requests. */
  uint32_t rxReq;                   /*!< Number of Rx requests. */
} PalRadio154Stats_t;

/*! \brief  802.15.4 radio driver configuration. */
typedef struct PalRadio154Cfg_tag
{
  uint64_t extAddr;                 /*!< Extended address. */
  uint16_t panId;                   /*!< PAN ID. */
  uint16_t shortAddr;               /*!< Short address. */
  uint16_t vsCRCOverride;           /*!< Override default CRC. */
  uint8_t  deviceType;              /*!< Device type. */
  uint8_t  disableCCA;              /*!< Disable CCA. */
  uint8_t  minBE;                   /*!< Minimum backoff exponent. */
  uint8_t  maxBE;                   /*!< Maximum backoff exponent. */
  uint8_t  maxCSMABackoffs;         /*!< Maximum number of CSMA backoffs. */
  uint8_t  maxFrameRetries;         /*!< Maximum number of frame retries. */
  uint8_t  promiscuousMode;         /*!< Promiscuous mode. */
  uint8_t  rxOnWhenIdle;            /*!< Receive on when idle. */
  uint8_t  rxEnabled;               /*!< Receiver temporarily enabled. */
  uint8_t  chan;                    /*!< Channel */
  int8_t   txPower;                 /*!< Transmit power */
  uint8_t  opFlags;                 /*!< Operation flags (see \a PalRadio154OpFlags_t) */
} PalRadio154Cfg_t;

/*! \brief  Buffer descriptor with length as the first octet.
 * Note - must be packed so buffer immediately follows length.
 */
typedef struct
{
  uint8_t len; /*!< Length of frame precedes actual frame that follows. */
} PalRadio154LenBufDesc_t;

/*! \brief  Get frame pointer from length buffer pointer. */
#define PAL_RADIO_154_FRAME_PTR_FROM_LEN_BUF(x)     (((x) == NULL) ? NULL : (uint8_t *)(((PalRadio154LenBufDesc_t *)(x))+1))

/*! \brief  Get length buffer pointer from frame pointer. */
#define PAL_RADIO_154_LEN_BUF_PTR_FROM_FRAME(x)     (((x) == NULL) ? NULL : (uint8_t *)(((PalRadio154LenBufDesc_t *)(x))-1))

/**************************************************************************************************
  Functions
**************************************************************************************************/

/*! \brief  Initialization functions. */

/*************************************************************************************************/
/*!
 *  \brief      Initialize radio resources.
 */
/*************************************************************************************************/
void PalRadio154Init(void);

/*************************************************************************************************/
/*!
 *  \brief      De-Initialize radio resources.
 */
/*************************************************************************************************/
void PalRadio154DeInit(void);

/*! \brief  Enable and disable functions. */

/*************************************************************************************************/
/*!
 *  \brief      Enable radio resources.
 */
/*************************************************************************************************/
void PalRadio154Enable(void);

/*************************************************************************************************/
/*!
 *  \brief      Disable radio resources.
 */
/*************************************************************************************************/
void PalRadio154Disable(void);

/*! \brief  Control and Status functions. */

/*************************************************************************************************/
/*!
 *  \brief      Get radio driver state.
 *
 *  \return     Enumerated state of radio driver.
 */
/*************************************************************************************************/
PalRadio154State_t PalRadio154GetState(void);

/*************************************************************************************************/
/*!
 *  \brief      Register callbacks.
 *
 *  \param      txCback   Tx completion callback.
 *  \param      rxCback   Rx completion callback.
 *  \param      edCback   ED completion callback.
 *  \param      fpCback   Frame pending check callback.
 */
/*************************************************************************************************/
void PalRadio154RegisterCallbacks(PalRadio154TxComp_t txCback,
                                  PalRadio154RxComp_t rxCback,
                                  PalRadio154EdComp_t edCback,
                                  PalRadio154FpChk_t  fpCback);

/*************************************************************************************************/
/*!
 *  \brief      Set radio configuration settings.
 *
 *  \return     Pointer to radio configuration settings.
 */
/*************************************************************************************************/
void PalRadio154SetCfg(PalRadio154Cfg_t *pCfg);

/*************************************************************************************************/
/*!
 *  \brief      Get radio configuration settings.
 *
 *  \return     Pointer to radio configuration settings.
 *
 *  \note       Depending on implementation, these may be a copy of the config. settings.
 *              \a PalRadio154SetCfg must be used to update the configuration. The return structure
 *              must be manipulated for changing the configuration.
 */
/*************************************************************************************************/
PalRadio154Cfg_t *PalRadio154GetCfg(void);

/*************************************************************************************************/
/*!
 *  \brief      Set radio channel.
 *
 *  \param      channel   Channel to set.
 *
 *  Sets the radio channel in the device.
 */
/*************************************************************************************************/
void PalRadio154SetChannel(uint8_t channel);

/*************************************************************************************************/
/*!
 *  \brief      Get radio channel.
 *
 *  \return     Current operating channel.
 *
 *  Gets the radio channel in the device.
 */
/*************************************************************************************************/
uint8_t PalRadio154GetChannel(void);

/*************************************************************************************************/
/*!
 *  \brief      Set Tx power level.
 *
 *  \param      level   Tx power level in dBm.
 *
 *  Actual power level may differ from nominal level given by \a level. Radio implementation may
 *  limit upper and lower bounds as well as available steps. Use \a PalRadioGetTxPower()
 *  to read actual Tx power level.
 */
/*************************************************************************************************/
void PalRadio154SetTxPower(int8_t level);

/*************************************************************************************************/
/*!
 *  \brief      Get Tx power level.
 *
 *  \return     Actual Tx power level.
 *
 *  Actual power level may differ from nominal level set by \a PalRadio154SetTxPower(). Radio
 *  implementation may limit upper and lower bounds as well as available steps.
 */
/*************************************************************************************************/
int8_t PalRadio154GetTxPower(void);

/*************************************************************************************************/
/*!
 *  \brief  Return the last received RSSI.
 *
 *  \return RSSI value in dBm.
 */
/*************************************************************************************************/
int8_t PalRadio154GetLastRssi(void);

/*! \brief  Operation functions. */

/*************************************************************************************************/
/*!
 *  \brief      Perform energy detect.
 *
 *  \param      dueTime     Due time for energy detect (0 = immediate).
 *
 *  \return     true if successfully executed.
 *
 *  Perform energy detect and return RSSI to determine channel status.
 */
/*************************************************************************************************/
bool PalRadio154Ed(uint32_t dueTime);

/*************************************************************************************************/
/*!
 *  \brief      Set Tx packet buffer.
 *
 *  \param      pTxBuf  Tx buffer, with length in first octet.
 *
 *  Transmit data from supplied buffer.
 */
/*************************************************************************************************/
void PalRadio154TxData(uint8_t *pTxBuf);

/*************************************************************************************************/
/*!
 *  \brief      Start data transmission.
 *
 *  \param      dueTime   Due time (0 = immediate).
 *
 *  \return     true if successfully executed.
 *
 *  Transmit data from previously supplied buffer at \a dueTime. If \a dueTime is 0, transmit
 *  immediately.
 *
 *  \note       Buffer must have been set up prior to starting.
 */
/*************************************************************************************************/
bool PalRadio154TxStart(uint32_t dueTime);

/*************************************************************************************************/
/*!
 *  \brief      Set Rx packet buffer.
 *
 *  \param      pRxBuf  Rx buffer.
 *
 *  Receive data into supplied buffer.
 */
/*************************************************************************************************/
void PalRadio154RxData(uint8_t *pRxBuf);

/*************************************************************************************************/
/*!
 *  \brief      Start data reception.
 *
 *  \param      dueTime       Due time (0 = immediate).
 *  \param      timeoutUsec   Rx timeout (0 = no timeout).
 *
 *  \return     true if receive started as requested, false otherwise.
 *
 *  Receive data into previously supplied buffer at \a dueTime. If \a dueTime is 0, receive
 *  immediately. If timeoutUsec > 0, \a timeoutUsec will signal end of receive period.
 *
 *  \note       Buffer must have been set up prior to starting.
 */
/*************************************************************************************************/
bool PalRadio154RxStart(uint32_t dueTime, uint32_t timeoutUsec);

/*************************************************************************************************/
/*!
 *  \brief      Cancel all radio operations.
 *
 *  Radio sleep may be enabled.
 */
/*************************************************************************************************/
void PalRadio154Stop(void);

/*! \brief  Test functions. */

/*************************************************************************************************/
/*!
 *  \brief      Get radio driver statistics.
 *
 *  \param      pStats  Storage for statistics.
 */
/*************************************************************************************************/
void PalRadio154GetStats(PalRadio154Stats_t *pStats);

/*************************************************************************************************/
/*!
 *  \brief      Reset radio driver statistics.
 */
/*************************************************************************************************/
void PalRadio154ResetStats(void);

/*************************************************************************************************/
/*!
 *  \brief      Start continuous Rx mode.
 *
 *  \param      rfChan     RF channel.
 *  \param      rxPhy      Rx PHY Mode.
 */
/*************************************************************************************************/
void PalRadio154ContinuousRx(uint8_t rfChan, uint8_t rxPhy);

/*************************************************************************************************/
/*!
 *  \brief      Start continuous Tx mode.
 *
 *  \param      rfChan      RF channel.
 *  \param      modulation  Modulation.
 *  \param      txPhy       Transmit PHY.
 *  \param      txPower     Transmit power.
 */
/*************************************************************************************************/
void PalRadio154ContinuousTx(uint8_t rfChan, uint8_t modulation, uint8_t txPhy, int8_t txPower);

/*************************************************************************************************/
/*!
 *  \brief  Stop continuous Tx or Rx operation
 */
/*************************************************************************************************/
void PalRadio154ContinuousStop(void);

#ifdef __cplusplus
};
#endif

#endif /* PAL_RADIO154_H */
