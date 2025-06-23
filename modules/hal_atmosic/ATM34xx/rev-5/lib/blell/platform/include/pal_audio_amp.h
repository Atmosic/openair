/*************************************************************************************************/
/*!
 *  \file
 *
 *  \brief  Audio amplifier interface.
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

#include "pal_types.h"

/*! \brief      I2S Master Mode Configuration */
typedef enum {
  PAL_AUDIO_AMP_I2S_MODE_SLAVE,
  PAL_AUDIO_AMP_I2S_MODE_MASTER
} PalAudioAmpI2SMode_t;

/*************************************************************************************************/
/*!
 *  \brief      Set data configuration.
 *
 *  \param      mode    I2S Master Mode Configuration
 *  \param      mclk    MCLK frequency in Hz.
 *  \param      lrclk   LRCLK frequency in Hz.
 */
/*************************************************************************************************/
void PalAudioAmpDataConfig(PalAudioAmpI2SMode_t mode, uint32_t mclk, uint32_t lrclk);

/*************************************************************************************************/
/*!
 *  \brief      Get the current output gain level.
 *
 *  \return     Current output gain level.
 */
/*************************************************************************************************/
uint8_t PalAudioAmpGetOuputGain(void);

/*************************************************************************************************/
/*!
 *  \brief      Set output gain level.
 *
 *  \param      level     Output gain level in dB.
 */
/*************************************************************************************************/
void PalAudioAmpSetOutputGain(int8_t level);

/*************************************************************************************************/
/*!
 *  \brief      Set input gain level.
 *
 *  \param      level     Input gain value in dB.
 */
/*************************************************************************************************/
void PalAudioAmpSetInputGain(int8_t vol);

/*************************************************************************************************/
/*!
 *  \brief      De-Initialize audio amplifier.
 */
/*************************************************************************************************/
void PalAudioAmpDeInit(void);

/*************************************************************************************************/
/*!
 *  \brief      Initialize audio amplifier.
 */
/*************************************************************************************************/
void PalAudioAmpInit(void);
