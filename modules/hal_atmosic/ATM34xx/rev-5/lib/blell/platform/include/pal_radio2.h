/*************************************************************************************************/
/*!
 *  \file
 *
 *  \brief      Radio interface file.
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

#ifndef PAL_RADIO2_H
#define PAL_RADIO2_H

#include <stdint.h>
#include "pal_types.h"
#include "pal_bb_ble.h"

#ifdef __cplusplus
extern "C" {
#endif

/*! \addtogroup PAL_RADIO
 *  \{ */

/**************************************************************************************************
  Data Types
**************************************************************************************************/

/*! \brief  Radio state. */
typedef enum
{
  PAL_RADIO_STATE_UNINIT = 0,       /*!< Uninitialized state. */
  PAL_RADIO_STATE_ERROR = 0,        /*!< Error state. */
  PAL_RADIO_STATE_IDLE,             /*!< Idle state. */
  PAL_RADIO_STATE_TX,               /*!< Tx state. */
  PAL_RADIO_STATE_RX,               /*!< Rx state. */
  PAL_RADIO_STATE_EDS,              /*!< Energy scan state. */
  PAL_RADIO_STATE_DIAG              /*!< Diagnostics state. */
} PalRadioState_t;

/*! \brief  Radio status code. */
typedef enum
{
  PAL_RADIO_STATUS_SUCCESS,         /*!< Operation completed successfully. */
  PAL_RADIO_STATUS_FAILED,          /*!< General failure. */
  PAL_RADIO_STATUS_TIMEOUT,         /*!< Rx timed out. */
  PAL_RADIO_STATUS_CRC_FAILED,      /*!< Rx CRC match failed. */
  PAL_RADIO_STATUS_MIC_FAILED       /*!< Rx MIC match failed. */
} PalRadioStatus_t;

/*! \brief  PHY modes. */
typedef enum
{
  PAL_RADIO_PHY_1M,                 /*!< 1M PHY. */
  PAL_RADIO_PHY_2M,                 /*!< 2M PHY. */
  PAL_RADIO_PHY_CODED_DEFAULT,      /*!< Coded with options not specified. */
  PAL_RADIO_PHY_CODED_S2,           /*!< Coded S2 PHY (500-kbps). */
  PAL_RADIO_PHY_CODED_S8            /*!< Coded S8 PHY (128-kbps). */
} PalRadioPhy_t;

/*! \brief Constant Tone Extension types. */
typedef enum
{
 PAL_RADIO_AOA,                     /*!< AoA type. */
 PAL_RADIO_AOD_1US,                 /*!< AoD type with 1us resolution. */
 PAL_RADIO_AOD_2US                  /*!< AoD type with 2us resolution. */
} PalRadioCte_t;

/*! \brief  Tx completion call signature. */
typedef void (*PalRadioTxComp_t)(PalRadioStatus_t status);

/*! \brief  Rx completion call signature. */
typedef void (*PalRadioRxComp_t)(PalRadioStatus_t status, uint32_t startOffs, PalRadioPhy_t phy, int8_t rssi);

/*! \brief      EDS Scan complete callback signature. */
typedef void (*PalRadioEdsComp_t)(int8_t rssi);

/**************************************************************************************************
  Functions
**************************************************************************************************/

/* Initialization */

/*************************************************************************************************/
/*!
 *  \brief      Initialize radio resources.
 */
/*************************************************************************************************/
void PalRadioInit(void);

/*************************************************************************************************/
/*!
 *  \brief      De-Initialize radio resources.
 */
/*************************************************************************************************/
void PalRadioDeInit(void);
void PalRadioEnable(void);

/* Enable and disable */

/*************************************************************************************************/
/*!
 *  \brief      Enable radio resources.
 */
/*************************************************************************************************/
void PalRadioEnable(void);

/*************************************************************************************************/
/*!
 *  \brief      Disable radio resources.
 */
/*************************************************************************************************/
void PalRadioDisable(void);

/* Control and Status */

/*************************************************************************************************/
/*!
 *  \brief      Get radio driver state.
 *
 *  \return     Enumerated state of radio driver.
 */
/*************************************************************************************************/
PalRadioState_t PalRadioGetState(void);

/*************************************************************************************************/
/*!
 *  \brief      Register Tx completion callback.
 *
 *  \param      cback   Completion callback.
 */
/*************************************************************************************************/
void PalRadioRegisterTxComplete(PalRadioTxComp_t cback);

/*************************************************************************************************/
/*!
 *  \brief      Register Rx completion callback.
 *
 *  \param      cback   Completion callback.
 */
/*************************************************************************************************/
void PalRadioRegisterRxComplete(PalRadioRxComp_t cback);

/*************************************************************************************************/
/*!
 *  \brief      Set access address.
 *
 *  \param      addr   Access Address.
 */
/*************************************************************************************************/
void PalRadioSetAccessAddress(uint32_t addr);

/*************************************************************************************************/
/*!
 *  \brief      Set CRC Init value.
 *
 *  \param      crcInit CRC Init value.
 */
/*************************************************************************************************/
void PalRadioSetCrcInit(uint32_t crcInit);

/*************************************************************************************************/
/*!
 *  \brief      Set RF channel index.
 *
 *  \param      chIdx   Bluetooth channel number.
 */
/*************************************************************************************************/
void PalRadioSetChannel(uint8_t chIdx);

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
void PalRadioSetTxPower(int8_t level);

/*************************************************************************************************/
/*!
 *  \brief      Get Tx power level.
 *
 *  \return     Actual Tx power level.
 *
 *  Actual power level may differ from nominal level set by \a PalRadioSetTxPower(). Radio
 *  implementation may limit upper and lower bounds as well as available steps.
 */
/*************************************************************************************************/
int8_t PalRadioGetTxPower(void);

/*************************************************************************************************/
/*!
 *  \brief      Set PHY.
 *
 *  \param      txPhy   Tx PHY mode.
 *  \param      rxPhy   Rx PHY mode.
 */
/*************************************************************************************************/
void PalRadioSetPhy(PalRadioPhy_t txPhy, PalRadioPhy_t rxPhy);

/*************************************************************************************************/
/*!
 *  \brief      Set data whitening mode.
 *
 *  \param      ena     Enable flag.
 */
/*************************************************************************************************/
void PalRadioSetDataWhitening(uint8_t ena);

/*************************************************************************************************/
/*!
 *  \brief      Enable PRBS15 constant bitstream.
 *
 *  \param      ena     Enable flag.
 */
/*************************************************************************************************/
void PalRadioSetPrbs15(uint8_t ena);

/* Continuous Tone Expression */

/*************************************************************************************************/
/*!
 *  \brief      Set transmit parameters for CTE.
 *
 *  \param      durUsec      Duration of CTE.
 *  \param      type         CTE Type.
 *  \param      isConn       true if connection-based CTE packet expected. false for advertising packets.
 */
/*************************************************************************************************/
void PalRadioCteEnableTx(uint8_t durUsec, PalRadioCte_t type, bool isConn);

/*************************************************************************************************/
/*!
 *  \brief      Set receive parameters for IQ sampling.
 *
 *  \param      slotDur      Slot switching duration.
 *  \param      isConn       true if connection-based CTE packet expected. false for advertising packets.
 */
/*************************************************************************************************/
void PalRadioCteEnableRx(uint8_t slotDur, bool isConn);

/*************************************************************************************************/
/*!
 *  \brief      Stop CTE operation.
 */
/*************************************************************************************************/
void PalRadioCteDisable(void);

/*************************************************************************************************/
/*!
 *  \brief      Get GPIO switch pattern from antenna ID.
 *
 *  \param      pattSwLen   Switching pattern length.
 *  \param      pAntId      Antenna ID array.
 */
/*************************************************************************************************/
void PalRadioCteSetAntennaPattern(uint8_t pattSwLen, uint8_t *pAntId);

/*************************************************************************************************/
/*!
 *  \brief      Get IQ samples.
 *
 *  \param      pNumSamp    Number of samples.
 *  \param      pIBuf       I sample buffer.
 *  \param      pQBuf       Q sample buffer.
 */
/*************************************************************************************************/
void PalRadioCteGetIqSamples(uint8_t *pNumSamp, int8_t *pIBuf, int8_t *pQBuf);

/* Encryption */

/*************************************************************************************************/
/*!
 *  \brief      Set data crypto mode.
 *
 *  \param      txEna     Enable Tx encryption flag.
 *  \param      rxEna     Enable Rx encryption flag.
 */
/*************************************************************************************************/
void PalRadioSetEncryption(uint8_t txEna, uint8_t rxEna);

/*************************************************************************************************/
/*!
 *  \brief      Set session key.
 *
 *  \param      pSK     Session key.
 */
/*************************************************************************************************/
void PalRadioSetSessionKey(uint8_t *pSK);

/*************************************************************************************************/
/*!
 *  \brief      Set encryption initialization vector.
 *
 *  \param      pIV     Initialization Vector buffer.
 */
/*************************************************************************************************/
void PalRadioSetIV(uint8_t *pIV);

/*************************************************************************************************/
/*!
 *  \brief      Set encryption direction bit.
 *
 *  \param      dir     Direction bit (typically 0 for slave and non-zero for master).
 */
/*************************************************************************************************/
void PalRadioSetDirection(uint8_t dir);

/*************************************************************************************************/
/*!
 *  \brief      Set encryption type.
 *
 *  \param      type     0=PAL_BB_TYPE_ACL, CIS, BIS
 */
/*************************************************************************************************/
void PalRadioSetEncryptionType(uint8_t type);

/*************************************************************************************************/
/*!
 *  \brief      Set encryption packet counter.
 *
 *  \param      pktCtr   Packet counter.
 */
/*************************************************************************************************/
void PalRadioSetPacketCounter(uint64_t pktCtr);

/* Data Transfer */

/*************************************************************************************************/
/*!
 *  \brief      Set Tx start time.
 *
 *  \param      dueTime     Due time.
 *
 *  Setup the radio for a Tx operation at the given \a dueTime. Buffer for this operation
 *  must be set prior to the expiration of \a dueTime.
 *
 *  Radio may sleep until \a dueTime.
 */
/*************************************************************************************************/
void PalRadioTxStart(uint32_t dueTime);

/*************************************************************************************************/
/*!
 *  \brief      Set next Tx packet using TIFS timing.
 *
 *  \param      tifsUsec    TIFS measured in microseconds from the end of the last packet.
 */
/*************************************************************************************************/
void PalRadioTxTifs(uint16_t tifsUsec);

/*************************************************************************************************/
/*!
 *  \brief      Set next CS Tx packet using IFS timing.
 *
 *  \param      ifsUsec    IFS measured in microseconds from the end of the last packet.
 */
/*************************************************************************************************/
void PalRadioCsTxIfs(uint32_t ifsUsec);

/*************************************************************************************************/
/*!
 *  \brief      Set next Tx packet offset.
 *
 *  \param      offsUsec    Offset in microseconds.
 *
 *  \a offsUsec is measured from the last dueTime set by \a PalRadioTxStart() or \a PalRadioRxStart().
 */
/*************************************************************************************************/
void PalRadioTxOffset(uint32_t offsUsec);

/*************************************************************************************************/
/*!
 *  \brief      Set Tx packet buffer.
 *
 *  \param      pBuf    Tx buffer.
 *  \param      len     Length of \a pBuf.
 *
 *  Buffer for the next Tx operation. This routine is called after \a PalRadioTxStart() or
 *  \a PalRadioTxOffset() and before the Tx due time.
 */
/*************************************************************************************************/
void PalRadioTxData(uint8_t *pBuf, uint16_t len);

/*************************************************************************************************/
/*!
 *  \brief      Set Tx CS packet buffer.
 *
 *  \param      pBuf    Tx buffer.
 *  \param      len     Length of \a pBuf.
 *
 *  Buffer for the next Tx operation. This routine is called after \a PalRadioTxStart() or
 *  \a PalRadioTxOffset() and before the Tx due time.
 */
/*************************************************************************************************/
void PalRadioCsTxData(uint8_t *pBuf, uint16_t len);

/*************************************************************************************************/
/*!
 *  \brief      Set Rx start time.
 *
 *  \param      dueTime         Due time.
 *  \param      rxTimeoutUsec   Rx correlation timeout.
 *
 *  \return     TBD
 *
 *  Setup the radio for an Rx operation at the given \a dueTime. Buffer for this operation
 *  must be set prior to the expiration of \a dueTime.
 *
 *  Radio may sleep until \a dueTime.
 */
/*************************************************************************************************/
bool PalRadioRxStart(uint32_t dueTime, uint32_t rxTimeoutUsec);

/*************************************************************************************************/
/*!
 *  \brief      Set next Tx packet using TIFS timing.
 *
 *  \param      tifsUsec        TIFS measured in microseconds from the end of the last packet.
 *  \param      rxTimeoutUsec   Rx correlation timeout.
 */
/*************************************************************************************************/
void PalRadioRxTifs(uint16_t tifsUsec, uint32_t rxTimeoutUsec);

/*************************************************************************************************/
/*!
 *  \brief      Set next CS Tx packet using IFS timing.
 *
 *  \param      ifsUsec         IFS measured in microseconds from the end of the last packet.
 *  \param      rxTimeoutUsec   Rx correlation timeout.
 */
/*************************************************************************************************/
void PalRadioCsRxIfs(uint32_t ifsUsec, uint32_t rxTimeoutUsec);

/*************************************************************************************************/
/*!
 *  \brief      Set next Rx packet offset.
 *
 *  \param      offsUsec        Offset in microseconds.
 *  \param      rxTimeoutUsec   Rx correlation timeout.
 *
 *  \return     TBD
 *
 *  \a offsUsec is measured from last dueTime set by \a PalRadioTxStart() or \a PalRadioRxStart().
 */
/*************************************************************************************************/
bool PalRadioRxOffset(uint32_t offsUsec, uint32_t rxTimeoutUsec);

/*************************************************************************************************/
/*!
 *  \brief      Set Rx packet buffer.
 *
 *  \param      pBuf    Rx buffer.
 *  \param      len     Length of \a pBuf.
 *
 *  Buffer for the next Rx operation. This routine is called after \a PalRadioRxStart() or
 *  \a PalRadioRxOffset() and before the Rx due time.
 */
/*************************************************************************************************/
void PalRadioRxData(uint8_t *pBuf, uint16_t len);

/*************************************************************************************************/
/*!
 *  \brief      Read Rx payload data from CSEM radio.
 *
 *  This routine is called after \a PalRadioRxData() and before starting next Rx operation.
 */
/*************************************************************************************************/
void PalRadioReadRxPayload(void);

/*************************************************************************************************/
/*!
 *  \brief      No more radio operations.
 *
 *  Radio sleep may be enabled.
 */
/*************************************************************************************************/
void PalRadioStop(void);

/* Energy Detection Scan */

/*************************************************************************************************/
/*!
 *  \brief      Start energy detect on a single channel.
 *
 *  \param      durUsec     Scan duration in microseconds.
 *  \param      cback       Scan completion callback.
 */
/*************************************************************************************************/
void PalRadioEdsStart(uint32_t durUsec, PalRadioEdsComp_t cback);

/*************************************************************************************************/
/*!
 *  \brief      Stops energy detect.
 */
/*************************************************************************************************/
void PalRadioEdsStop(void);

#ifdef FEAT_TX_INFINITE
/*************************************************************************************************/
/*!
 *  \brief      Check tx_infnt.
 *
 *  \return     True infinite Tx
 *  \return     False finite Tx
 */
/*************************************************************************************************/
bool PalRadioGetTxInfnt(void);
#endif

/*************************************************************************************************/
/*!
 *  \brief      Enable CRC and data whitening.
 *
 *  \param      ena        TRUE to enable CRC and data whitening.
 */
/*************************************************************************************************/
void PalRadioCsCrcAndWhiteningEnable(bool ena);

/*************************************************************************************************/
/*!
 *  \brief      Set CS RF channel index.
 *
 *  \param      chNum   Bluetooth channel number.
 */
/*************************************************************************************************/
void PalRadioCsSetChannel(uint8_t chNum);

/*! \} */    /* PAL_RADIO */

#ifdef __cplusplus
};
#endif

#endif /* PAL_RADIO2_H */
