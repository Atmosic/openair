/*************************************************************************************************/
/*!
 *  \file
 *
 *  \brief      BLE Baseband interface file.
 *
 *  Copyright (c) 2013-2019 Arm Ltd. All Rights Reserved.
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

#ifndef PAL_BB_BLE_H
#define PAL_BB_BLE_H

#include "pal_bb.h"
#include "pal_crypto.h"
#include "ll_defs.h"

#ifdef __cplusplus
extern "C" {
#endif

/**************************************************************************************************
  Macros
**************************************************************************************************/

#ifndef LL_ENABLE_TESTER
#define LL_ENABLE_TESTER        0       /*!< Enable LL tester extensions. */
#endif

#define PAL_BB_MAX_SW_PATT      5       /*!< Maximum number of switch patterns. */

/**************************************************************************************************
  Data Types
**************************************************************************************************/

/*! \brief      Nonce modes. */
enum
{
  PAL_BB_NONCE_MODE_PKT_CNTR,           /*!< Packet counter mode (default). */
  PAL_BB_NONCE_MODE_EXT16_CNTR,         /*!< 16-bit counter mode, PalCryptoEnc_t::pEventCounter must be non-NULL. */
  PAL_BB_NONCE_MODE_EXT64_CNTR          /*!< 64-bit counter mode, PalCryptoEnc_t::pTxPktCounter/pRxPktCounter must be non-NULL. */
};

/*! \brief      Connection type. */
enum
{
  PAL_BB_TYPE_ACL,                      /*!< ACL. */
  PAL_BB_TYPE_CIS,                      /*!< CIS. */
  PAL_BB_TYPE_BIS                       /*!< BIS. */
};

/*! \addtogroup PAL_BB_BLE_CHAN
 *  \{ */

/*! \brief     CTE parameters. */
typedef struct
{
  bool  enable;                        /*!< Enable status. */
  uint8_t cteTime;                     /*!< CTE Time (implies enable for Tx). */
  uint8_t cteType;                     /*!< CTE type. */
  uint8_t slotDur;                     /*!< Sample and switch slot duration. */
  uint8_t swPattLen;                   /*!< Switching pattern length. */
  uint8_t swPatt[PAL_BB_MAX_SW_PATT];  /*!< Antenna switching pattern list. */
  int8_t *pISampleBuf;                 /*!< Sample buffer to use in I sampling. */
  int8_t *pQSampleBuf;                 /*!< Sample buffer to use in Q sampling. */
  uint8_t numSampRcvd;                 /*!< Number of samples received from IQ sampling. */
} PalCteParam_t;                       /*!< CTE Transmit parameters. */

/*! \brief     CTE states. */
enum
{
  PAL_BB_CTE_STATE_DISABLED,
  PAL_BB_CTE_STATE_TX,
  PAL_BB_CTE_STATE_RX
};

/*! \brief      BLE channelization parameters. */
typedef struct
{
  uint8_t       opType;                 /*!< Operation type. */
  uint8_t       chanIdx;                /*!< Channel index. */
  int8_t        txPower;                /*!< Active transmit power, unit is dBm. */
  uint8_t       antID;                  /*!< Antenna selection. */
  uint32_t      accAddr;                /*!< Access address. */
  uint32_t      crcInit;                /*!< CRC initialization value. */
  PalBbPhy_t    txPhy;                  /*!< Transmitter PHY. */
  PalBbPhy_t    rxPhy;                  /*!< Receiver PHY. */
  uint8_t       initTxPhyOptions;       /*!< Initial Tx PHY options. */
  uint8_t       tifsTxPhyOptions;       /*!< TIFS Tx PHY options. */
  bool          peerTxStableModIdx;     /*!< Peer uses stable modulation index on transmitter. */
  bool          peerRxStableModIdx;     /*!< Peer uses stable modulation index on receiver. */
  bool          optimizeSetParam;       /*!< Optimize setting of parameters. */
#if (CTE_PRESENT)
  PalCteParam_t txCteParam;             /*!< Tx CTE parameters. */
  PalCteParam_t rxCteParam;             /*!< Rx CTE parameters. */
#endif
  PalCryptoEnc_t enc;                   /*!< Encryption parameters (NULL if disabled). */
  uint32_t      accAddrPawr;            /*!< Access address for AUX_SYNC_SUBEVENT_RSP. */
#if (LL_FEAT_RSPOBS)
  uint32_t      accAddr2;               /*!< Access address copy for Response observation. */
#endif
#if (LL_ENABLE_TESTER)
  uint32_t      accAddrRx;              /*!< Access address override for receptions. */
  uint32_t      accAddrTx;              /*!< Access address override for transmissions. */
  uint32_t      crcInitRx;              /*!< CRC initialization override for receptions. */
  uint32_t      crcInitTx;              /*!< CRC initialization override for transmissions. */
  int8_t        txPwrOffset;            /*!< Override offset for txPower. */
#endif
} PalBbBleChan_t;

/*! \} */    /* PAL_BB_BLE_CHAN */

/*! \addtogroup PAL_BB_BLE_DATA
 *  \{
 *  This section contains driver routines used for packet transmission.
 */

/*! \brief      Transmit complete ISR callback signature. */
typedef void (*PalBbBleTxIsr_t)(uint8_t status);

/*! \brief      Receive complete ISR callback signature. */
typedef void (*PalBbBleRxIsr_t)(uint8_t status, int8_t rssi, uint32_t crc, uint32_t timestamp, uint8_t rxPhyOptions);

/*! \brief      IFS modes. */
typedef enum
{
  PAL_BB_IFS_MODE_CLR,              /*!< Clear IFS (last packet). */
  PAL_BB_IFS_MODE_TOGGLE_TIFS,      /*!< Toggle operation with TIFS timing. */
  PAL_BB_IFS_MODE_SAME_ABS,         /*!< Same operation with absolute timing. */
  PAL_BB_IFS_MODE_SAME_TIFS         /*!< Same operation with TIFS timing. */
} PalBbIfsMode_t;

/*! \brief      BLE data transfer parameters. */
typedef struct
{
  PalBbBleTxIsr_t   txCback;        /*!< Transmit completion callback. */
  PalBbBleRxIsr_t   rxCback;        /*!< Receive completion callback. */

  uint32_t          dueUsec;        /*!< Due time of the first packet in microseconds. */
  uint32_t          rxTimeoutUsec;  /*!< Receive timeout in microseconds. */
} PalBbBleDataParam_t;

/*! \brief    Operation parameters. */
typedef struct
{
  PalBbIfsMode_t    ifsMode:8;      /*!< IFS mode for next operation. */
  uint16_t          ifsDurUsec;     /*!< IFS duration. */
  uint32_t          ifsTime;        /*!< Absolute time of next PDU. */
  PalBbBleChan_t    *pIfsChan;      /*!< Channel of next PDU, NULL for no change. */
} PalBbBleOpParam_t;

/*! \brief    Transmit buffer descriptor. */
typedef struct
{
  uint16_t          len;            /*!< Length of buffer. */
  uint8_t           *pBuf;          /*!< Pointer to buffer. */
} PalBbBleTxBufDesc_t;

/*! \brief       Call signature for set CTE params function. */
typedef void (*palBbBleSetCteParamsFn_t)(PalCteParam_t *pTxCteParam, PalCteParam_t *pRxCteParam, bool cteInHdr);

/*! \brief  Channel Sounding Step completion call signature. */
typedef void (*PalBbBleStepComp_t)(PalBbStatus_t status, int8_t rssi, uint32_t startTs);

/*! \} */    /* PAL_BB_BLE_DATA */

/**************************************************************************************************
  Function Declarations
**************************************************************************************************/

/*! \addtogroup PAL_BB_BLE_INIT
 *  \{
 *  This section contains driver routines which initialize as well as enable the BLE mode of the
 *  BB hardware.
 */

/*************************************************************************************************/
/*!
 *  \brief      Initialize the BLE baseband driver.
 *
 *  \param  pFreeMem        Free memory.
 *  \param  freeMemAvail    Amount of free memory in bytes.
 *
 *  \return Amount of free memory consumed.
 *
 *  One-time initialization of BLE baseband driver.
 */
/*************************************************************************************************/
uint32_t PalBbBleInit(uint8_t *pFreeMem, uint32_t freeMemAvail);

/*************************************************************************************************/
/*!
 *  \brief      Enable the BB hardware.
 *
 *  Wake the BB hardware out of sleep and enable for operation. All BB functionality is
 *  available when this routine completes. BB clock is set to zero and started.
 */
/*************************************************************************************************/
void PalBbBleEnable(void);

/*************************************************************************************************/
/*!
 *  \brief      Disable the BB hardware.
 *
 *  Disable the baseband and put radio hardware to sleep. Must be called from an idle state.
 *  A radio operation cannot be in progress.
 */
/*************************************************************************************************/
void PalBbBleDisable(void);

/*************************************************************************************************/
/*!
 *  \brief      Low power operation.
 *
 *  \note       Called by upper baseband code.
 */
/*************************************************************************************************/
void PalBbBleLowPower(void);

/*! \} */    /* PAL_BB_BLE_INIT */

/*! \addtogroup PAL_BB_BLE_CHAN
 *  \{
 *  This section contains the driver routine used to set the chanelization parameters.
 */

/*************************************************************************************************/
/*!
 *  \brief      Set channelization parameters.
 *
 *  \param      pChan       Channelization parameters.
 *
 *  Calling this routine will set parameters for all future transmit and receive operations
 *  until this routine is called again providing new parameters.
 *
 *  The setting of channelization parameters influence the operations of the following listed
 *  routines. Therefore, this routine is called to set the channel characteristics before
 *  the use of data routines described in \a PAL_BB_BLE_DATA.
 *
 *  \note       The \a pParam contents are not guaranteed to be static and is only valid in the
 *              context of the call to this routine. Therefore parameters requiring persistence
 *              should be copied.
 */
/*************************************************************************************************/
void PalBbBleSetChannelParam(PalBbBleChan_t *pChan);

/*************************************************************************************************/
/*!
 *  \brief      Set the inline encryption packet count for transmit.
 *
 *  \param      pktCtr  Packet counter value, a 39-bit value (upper bits are ignored).
 */
/*************************************************************************************************/
void PalBbBleSetInlineEncryptPacketCount(uint64_t pktCtr);

/*************************************************************************************************/
/*!
 *  \brief      Set the inline decryption packet count for reception.
 *
 *  \param      pktCtr  Packet counter value, a 39-bit value (upper bits are ignored).
 */
/*************************************************************************************************/
void PalBbBleSetInlineDecryptPacketCount(uint64_t pktCtr);

/*! \} */    /* PAL_BB_BLE_CHAN */

/*! \addtogroup PAL_BB_BLE_DATA
 *  \{
 *  This section contains driver routines used for packet transmission.
 */

/*************************************************************************************************/
/*!
 *  \brief      Set the data packet exchange parameters.
 *
 *  \param      pParam      Data exchange parameters.
 *
 *  Calling this routine will set parameters for all future transmit and receive operations
 *  until this routine is called again providing new parameters.
 */
/*************************************************************************************************/
void PalBbBleSetDataParams(const PalBbBleDataParam_t *pParam);

/*************************************************************************************************/
/*!
 *  \brief      Set the operation parameters.
 *
 *  \param      pOpParam    Operations parameters.
 *
 *  Calling this routine will set parameters for the next transmit or receive operations.
 */
/*************************************************************************************************/
void PalBbBleSetOpParams(const PalBbBleOpParam_t *pOpParam);

/*************************************************************************************************/
/*!
 *  \brief      Clear IFS in operation.
 *
 *  The BB may choose not to enable IFS after the next Tx or Rx.
 */
/*************************************************************************************************/
void PalBbBleClrOpParams(void);

/*************************************************************************************************/
/*!
 *  \brief      Set TIFS in operation.
 *
 *  The BB must enable TIFS after the next Tx or Rx.
 */
/*************************************************************************************************/
void PalBbBleSetTifs(uint16_t ifsDurUsec);

/*************************************************************************************************/
/*!
 *  \brief      Set absolute time IFS in operation.
 *
 *  \param  ifsTime     Due time of the next PDU.
 *  \param  pIfsChan    Channel of the next PDU.
 *
 *  The BB must enable IFS with absolute time after the next Tx or Rx.
 */
/*************************************************************************************************/
void PalBbBleSetAbsIfs(uint32_t ifsTime, PalBbBleChan_t *pIfsChan);

/*************************************************************************************************/
/*!
 *  \brief      Transmit a packet.
 *
 *  \param      descs       Array of transmit buffer descriptors.
 *  \param      cnt         Number of descriptors.
 *
 *  Set the first data buffer for the first packet of an alternating Tx-Rx data exchange cycle.
 */
/*************************************************************************************************/
void PalBbBleTxData(PalBbBleTxBufDesc_t descs[], uint8_t cnt);

/*************************************************************************************************/
/*!
 *  \brief      Transmit packet at TIFS after the last packet received.
 *
 *  \param      descs       Array of transmit buffer descriptor.
 *  \param      cnt         Number of descriptors.
 *
 *  If possible, the transmit will occur at the TIFS timing. If not possible, the callback status
 *  will indicate this.
 */
/*************************************************************************************************/
void PalBbBleTxTifsData(PalBbBleTxBufDesc_t descs[], uint8_t cnt);

/*************************************************************************************************/
/*!
 *  \brief      Receive packet.
 *
 *  \param      pBuf        Receive data buffer.
 *  \param      len         Length of data buffer.
 *
 *  Set the first data buffer for the first packet of an alternating Rx-Tx data exchange cycle.
 */
/*************************************************************************************************/
void PalBbBleRxData(uint8_t *pBuf, uint16_t len);

/*************************************************************************************************/
/*!
 *  \brief      Receive CS packet.
 *
 *  \param      pBuf        Receive data buffer.
 *  \param      len         Length of data buffer.
 *
 *  Set the first data buffer for the first packet of an alternating Rx-Tx data exchange cycle.
 */
/*************************************************************************************************/
void PalBbBleCsRxData(uint8_t *pBuf, uint16_t len);

/*************************************************************************************************/
/*!
 *  \brief      Receive packet at TIFS after the last packet transmitted.
 *
 *  \param      pBuf        Receive data buffer.
 *  \param      len         Length of data buffer.
 *
 *  If possible, the receive will occur on the TIFS timing. If not possible, the callback status
 *  will indicate this.
 */
/*************************************************************************************************/
void PalBbBleRxTifsData(uint8_t *pBuf, uint16_t len);

/*************************************************************************************************/
/*!
 *  \brief      Transmit packet at TIFS after the last packet received.
 *
 *  \param      descs       Array of transmit buffer descriptor.
 *  \param      cnt         Number of descriptors.
 */
/*************************************************************************************************/
void PalBbBleCsTxIfsData(PalBbBleTxBufDesc_t descs[], uint8_t cnt);

/*************************************************************************************************/
/*!
 *  \brief      Receive CS packet after the last packet transmitted.
 *
 *  \param      pBuf        Receive data buffer.
 *  \param      len         Length of data buffer.
 */
/*************************************************************************************************/
void PalBbBleCsRxIfsData(uint8_t *pBuf, uint16_t len);

/*************************************************************************************************/
/*!
 *  \brief      Cancel TIFS timer.
 *
 *  This stops any active TIFS timer operation. This routine is always called in the callback
 *  (i.e. ISR) context.
 */
/*************************************************************************************************/
void PalBbBleCancelTifs(void);

/*************************************************************************************************/
/*!
 *  \brief      Cancel a pending transmit or receive.
 *
 *  This stops any active radio operation. This routine is never called in the callback
 *  (i.e. ISR) context.
 */
/*************************************************************************************************/
void PalBbBleCancelData(void);

/*! \} */    /* PAL_BB_BLE_DATA */

/*! \addtogroup PAL_BB_BLE_TEST
 *  \{
 *  This section contains driver routines used for test modes.
 */

/*************************************************************************************************/
/*!
 *  \brief      Enable or disable data whitening.
 *
 *  \param      enable       Flag to indicate data whitening.
 *
 *  Sets an internal variable that indicates if data whitening is enabled or not.
 */
/*************************************************************************************************/
void PalBbBleEnableDataWhitening(bool enable);

/*************************************************************************************************/
/*!
 *  \brief      Enable or disable PRBS15.
 *
 *  \param      enable       Flag to indicate PRBS15.
 *
 *  Immediately enable or disable continuous PRBS15 bitstream. Setting the channelization
 *  parameters with \a PalBbBleSetChannelParam() must precede enabling PRBS15.
 *
 *  Use of \a PAL_BB_BLE_DATA routines is not allowed while PRBS15 is enabled.
 */
/*************************************************************************************************/
void PalBbBleEnablePrbs15(bool enable);

/*! \} */    /* PAL_BB_BLE_TEST */

/*! \addtogroup PAL_BB_BLE_CTE
 *  \{
 *  This section contains driver routines used for constant tone expression.
 */

/*************************************************************************************************/
/*!
 *  \brief      Initialize BB CTE resources.
 */
/*************************************************************************************************/
void PalRadioCteInit(void);

/*************************************************************************************************/
/*!
 *  \brief      Transmit a CS packet.
 *
 *  \param      descs       Array of transmit buffer descriptors.
 *  \param      cnt         Number of descriptors.
 *
 *  Set the first data buffer for the first CS packet of an alternating Tx-Rx CS exchange cycle.
 */
/*************************************************************************************************/
void PalBbBleCsTxData(PalBbBleTxBufDesc_t descs[], uint8_t cnt);

/*************************************************************************************************/
/*!
 *  \brief      Set CS channelization parameters.
 *
 *  \param      pChan       Channelization parameters.
 *
 *  Calling this routine will set parameters for all future transmit and receive operations
 *  until this routine is called again providing new parameters.
 *
 *  The setting of channelization parameters influence the operations of the following listed
 *  routines. Therefore, this routine is called to set the channel characteristics before
 *  the use of data routines described in \a PAL_BB_BLE_DATA.
 *
 *  \note       The \a pParam contents are not guaranteed to be static and is only valid in the
 *              context of the call to this routine. Therefore parameters requiring persistence
 *              should be copied.
 */
/*************************************************************************************************/
void PalBbBleCsSetChannelParam(PalBbBleChan_t *pChan);

/*************************************************************************************************/
/*!
*  \brief      Register Channel Sounding Step completion callback.
*
*  \param      cback   Completion callback.
*/
/*************************************************************************************************/
void PalBbBleCsRegisterStepComplete(PalBbBleStepComp_t cback);

/*! \} */    /* PAL_BB_BLE_CTE */

/*! \addtogroup PAL_BB_BLE_CS
 *  \{
 *  This section contains driver routines used for Channel Sounding.
 */

/*! \brief      Channel Sounding roles values. */
enum
{
  PAL_BB_BLE_CS_ROLE_INITIATOR,
  PAL_BB_BLE_CS_ROLE_REFLECTOR
};

/*! \brief      Channel Sounding role type. */
typedef uint8_t PalBbBleCsRole_t;

/*! \brief      Channel Sounding Step completion call signature. */
typedef void (*PalBbBleCsStepComp_t)(uint8_t status, int8_t rssi, uint32_t startTs);

/*! \brief      Channel Sounding Step parameters. */
typedef struct
{
  uint8_t mode;                     /*!< Mode. */

  /* Antenna */
  uint8_t pattSwLen;                        /*!< Switching pattern length. */
  uint8_t antId[LL_CS_MAX_NUM_ANT_PATHS];   /*!< Antenna ID array. */
  /* Timing */
  uint32_t rxTimeoutUsec;           /*!< Receive timeout in microseconds. */
  uint16_t syncLen;                 /*!< CS_SYNC buffer length. */
  struct
  {
    uint32_t aa;                    /*!< Access Address. */
    uint8_t *pSyncBuf;              /*!< CS_SYNC buffer. */
    bool extSlotPrsnt;              /*!< Extension slot present. */
  } init;                           /*!< Initiator step parameters. */
  struct
  {
    uint32_t aa;                    /*!< Access Address. */
    uint8_t *pSyncBuf;              /*!< CS_SYNC buffer. */
    bool extSlotPrsnt;              /*!< Extension slot present. */
  } ref;                            /*!< Reflector step parameters. */
} PalBbBleCsStep_t;

/*************************************************************************************************/
/*!
*  \brief      Initialize radio resources for Channel Sounding.
*/
/*************************************************************************************************/
void PalBbBleCsInit(void);

/*************************************************************************************************/
/*!
*  \brief      Set Channel Sounding step parameters.
*
*  \param      pParam     Step parameters.
*/
/*************************************************************************************************/
void PalBbBleCsSetParam(PalBbBleCsStep_t *pParam);

/*************************************************************************************************/
/*!
*  \brief      Enable Channel Sounding operation step parameters.
*
*  \param      pParam     Step parameters.
*  \param      enable     True if Channel Sounding enabled.
*/
/*************************************************************************************************/
void PalBbBleCsEnableSteps(bool enable, uint8_t role);

/*************************************************************************************************/
/*!
*  \brief      Set Channel Sounding radio configuration.
*
*  \param      pParam     Step parameters.
*  \param      enable     True if Channel Sounding enabled.
*/
/*************************************************************************************************/
void PalBbBleCsSetRadio(PalBbBleCsStep_t *pParam);

/*************************************************************************************************/
/*!
*  \brief      Set Channel Sounding start time.
*
*  \param      dueTime     Due time.
*
*  Radio may sleep until \a dueTime.
*/
/*************************************************************************************************/
void PalBbBleCsStartStep(uint32_t dueTime);
/*************************************************************************************************/
/*!
*  \brief      Get Channel Sounding reference power level.
*
*  \return     Reference power level
*/
/*************************************************************************************************/
int8_t PalBbBleCsGetRefPwrLvl(void);

/*************************************************************************************************/
/*!
*  \brief      Get Channel Sounding frequency compensation value.
*
*  \return     Frequency compensation value
*/
/*************************************************************************************************/
uint16_t PalBbBleCsGetFreqComp(void);

/*************************************************************************************************/
/*!
*  \brief      Cancel Cs step early scheduling.
*
*/
/*************************************************************************************************/
void PalBbBleCsCancelScheduling(void);

/*************************************************************************************************/
/*!
*  \brief      Backup PAL BB BLE data..
*/
/*************************************************************************************************/
void PalBbBleBackupData(void);

/*************************************************************************************************/
/*!
*  \brief      Restore PAL BB BLE data..
*/
/*************************************************************************************************/
void PalBbBleRestoreData(void);

/*! \} */    /* PAL_BB_BLE_CS */

#ifdef __cplusplus
};
#endif

#endif /* PAL_BB_BLE_H */
