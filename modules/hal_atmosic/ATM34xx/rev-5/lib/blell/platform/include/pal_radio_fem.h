/*************************************************************************************************/
/*!
 *  \file
 *
 *  \brief      Radio FEM (Front End Module).
 *
 *  Copyright (c) 2019-2024 Packetcraft, Inc.  All rights reserved.
 *  Packetcraft, Inc. confidential and proprietary.
 *  
 *  IMPORTANT.  Your use of this file is governed by a Software License Agreement
 *  ("Agreement") that must be accepted in order to download or otherwise receive a
 *  copy of this file.  You may not use or copy this file for any purpose other than
 *  as described in the Agreement.  If you do not agree to all of the terms of the
 *  Agreement do not use this file and delete all copies in your possession or control;
 *  if you do not have a copy of the Agreement, you must contact Atmosic, Inc. prior
 *  to any use, copying or further distribution of this software.
 */
/*************************************************************************************************/

#ifndef PAL_RADIO_FEM_H
#define PAL_RADIO_FEM_H

#include "pal_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/*! \addtogroup PAL_RADIO_FEM
 *  \{ */

/**************************************************************************************************
  Functions
**************************************************************************************************/

/* Initialization */

/*************************************************************************************************/
/*!
 *  \brief      Initialize FEM.
 *
 *  \param      dppiTxEnd     TBD
 *  \param      dppiRxEnd     TBD
 */
/*************************************************************************************************/
void PalRadioFemInit(uint8_t dppiTxEnd, uint8_t dppiRxEnd);

/*************************************************************************************************/
/*!
 *  \brief      Shutdown FEM.
 */
/*************************************************************************************************/
void PalRadioFemDeInit(void);

/* Control and Status */

/*************************************************************************************************/
/*!
 *  \brief      Get PA gain level.
 *
 *  \return     Gain in dBm.
 */
/*************************************************************************************************/
uint8_t PalRadioFemGetPaGainLevel(void);

/*************************************************************************************************/
/*!
 *  \brief      Get absolute maximum PA gain level.
 *
 *  \return     Gain in dBm.
 */
/*************************************************************************************************/
uint8_t PalRadioFemGetPaAbsMaxGainLevel(void);

/*************************************************************************************************/
/*!
 *  \brief      Get absolute minimum PA gain level.
 *
 *  \return     Gain in dBm.
 */
/*************************************************************************************************/
uint8_t PalRadioFemGetPaAbsMinGainLevel(void);

/*************************************************************************************************/
/*!
 *  \brief      Calculate PA gain level.
 *
 *  \param      txPwr     Transmit power in dBm.
 *  \param      pathComp  Path compensation in dBm.
 *  \param      stepSize  Size between power levels in dBm.
 *
 *  \return     Gain in dBm.
 */
/*************************************************************************************************/
uint8_t PalRadioFemCalcPaGainLevel(int8_t txPwr, int8_t pathComp, int8_t maxGain, uint8_t stepSize);

/*************************************************************************************************/
/*!
 *  \brief      Get LNA gain level.
 *
 *  \return     Gain in dBm.
 */
/*************************************************************************************************/
uint8_t PalRadioFemGetLnaGainLevel(void);

/*************************************************************************************************/
/*!
 *  \brief      Set PA gain level.
 *
 *  \param      gain    Gain in dBm.
 *
 *  \return     TBD
 */
/*************************************************************************************************/
bool PalRadioFemSetPaGainLevel(uint8_t gain);

/*************************************************************************************************/
/*!
 *  \brief      Set LNA gain level.
 *
 *  \param      gain    Gain in dBm.
 *
 *  \return     TBD
 */
/*************************************************************************************************/
bool PalRadioFemSetLnaGainLevel(uint8_t gain);

/*************************************************************************************************/
/*!
 *  \brief      Set antenna selection.
 *
 *  \param      antId   Antenna ID.
 *
 *  \return     TBD
 */
/*************************************************************************************************/
bool PalRadioFemSetAntennaSelection(uint8_t antId);

/*************************************************************************************************/
/*!
 *  \brief      Power up event handler.
 */
/*************************************************************************************************/
void PalRadioFemDisable(void);

/*************************************************************************************************/
/*!
 *  \brief      Tx start event handler.
 *
 *  \param      offsUsec    Offset in microseconds.
 */
/*************************************************************************************************/
void PalRadioFemEnableTx(uint32_t offsUsec);

/*************************************************************************************************/
/*!
 *  \brief      Rx start event handler.
 *
 *  \param      offsUsec    Offset in microseconds.
 */
/*************************************************************************************************/
void PalRadioFemEnableRx(uint32_t offsUsec);

/*! \} */    /* PAL_RADIO_FEM */

#ifdef __cplusplus
};
#endif

#endif /* PAL_RADIO_FEM_H */
