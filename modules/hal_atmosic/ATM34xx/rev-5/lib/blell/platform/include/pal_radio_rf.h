/*************************************************************************************************/
/*!
 *  \file
 *
 *  \brief      Radio interface file.
 *
 *  Copyright (c) 2018-2019 Arm Ltd. All Rights Reserved.
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

#ifndef PAL_RADIO_RF_H
#define PAL_RADIO_RF_H

#include "pal_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/*! \addtogroup PAL_RADIO
 *  \{ */

/**************************************************************************************************
  Function Declarations
**************************************************************************************************/

/*************************************************************************************************/
/*!
 *  \brief      Initialize RF path compensation.
 */
/*************************************************************************************************/
void PalRadioInitPathComp(void);

/*************************************************************************************************/
/*!
 *  \brief      Get the actual Tx power at the antenna (expressed in 1dBm units).
 *
 *  \param      txPwr           Tx power provided by the host (expressed in 1dBm units).
 *
 *  \return     Actual Tx power at the antenna (expressed in 1dBm units).
 *
 *  Tx path compensation is only used for extended ADV header.
 *  Compensation is not considered when filling in HCI events.
 */
/*************************************************************************************************/
int8_t PalRadioGetActualTxPower(int8_t txPwr);

/*************************************************************************************************/
/*!
 *  \brief      Get the actual Tx power change
 *
 *  \param      reqPwr           Requested power.
 *  \param      delta           Delta from prior value
 *
 *  \return     Actual Tx power value
 *
 *  Increase or decrease a single step allowed by the hardware.
 */
/*************************************************************************************************/
int8_t PalRadioGetActualPowerChange(int8_t reqPwr, int8_t delta);

/*************************************************************************************************/
/*!
 *  \brief      Set RF path compensation.
 *
 *  \param      txPathComp      RF transmit path compensation value (expressed in 0.1dBm units).
 *  \param      rxPathComp      RF receive path compensation value (expressed in 0.1dBm units).
 *
 *  \return     true if successful, false otherwise.
 */
/*************************************************************************************************/
bool PalRadioWriteRfPathComp(int16_t txPathComp, int16_t rxPathComp);

/*************************************************************************************************/
/*!
 *  \brief      Get supported transmit power.
 *
 *  \param      pMinTxPwr   Return buffer for minimum transmit power (expressed in 1dBm units).
 *  \param      pMaxTxPwr   Return buffer for maximum transmit power (expressed in 1dBm units).
 */
/*************************************************************************************************/
void PalRadioGetSupTxPower(int8_t *pMinTxPwr, int8_t *pMaxTxPwr);

/*************************************************************************************************/
/*!
 *  \brief      Read RF path compensation.
 *
 *  \param      pTxPathComp Return buffer for RF transmit path compensation value (expressed in 0.1dBm units).
 *  \param      pRxPathComp Return buffer for RF receive path compensation value (expressed in 0.1dBm units).
 */
/*************************************************************************************************/
void PalRadioReadRfPathComp(int16_t *pTxPathComp, int16_t *pRxPathComp);

/*************************************************************************************************/
/*!
 *  \brief      Set the absolute maximum Tx power delivered at the antenna.
 *
 *  \param      maxTxPwr    Transmit power in dBm.
 *
 *  \return     true if successful, false otherwise.
 *
 *  \note       \a maxTxPwr includes gain from on-chip PA, FEM and path loss.
 */
/*************************************************************************************************/
uint8_t PalRadioRfSetMaxTxPower(uint8_t maxTxPwr);

/*************************************************************************************************/
/*!
 *  \brief      Select antenna.
 *
 *  \param      antId     Antenna ID.
 *
 *  \return     true if successful, false otherwise.
 */
/*************************************************************************************************/
uint8_t PalRadioRfSelectAntenna(uint8_t antId);

/*! \} */    /* PAL_RADIO */

#ifdef __cplusplus
};
#endif

#endif /* PAL_RADIO_RF_H */
