/*************************************************************************************************/
/*!
 *  \file
 *
 *  \brief      Button driver definition.
 *
 *  Copyright (c) 2018-2019 ARM Ltd. All Rights Reserved.
 *
 *  Copyright (c) 2019-2022 Packetcraft, Inc.  All rights reserved.
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

#ifndef PAL_BTN_H
#define PAL_BTN_H

#include "pal_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/*! \addtogroup PAL_BUTTON
 *  \{ */

/**************************************************************************************************
  Data Types
**************************************************************************************************/

/*! \brief      Operational states. */
typedef enum
{
  PAL_BTN_STATE_UNINIT = 0,     /*!< Uninitialized state. */
  PAL_BTN_STATE_ERROR  = 0,     /*!< Error state. */
  PAL_BTN_STATE_READY           /*!< Ready state. */
} PalBtnState_t;

/*! \brief      Button position. */
typedef enum
{
  PAL_BTN_POS_INVALID,          /*!< Button position is invalid. */
  PAL_BTN_POS_DOWN,             /*!< Button position is depressed. */
  PAL_BTN_POS_UP                /*!< Button position is released. */
} PalBtnPos_t;

/*! \brief      Action callback signature. */
typedef void (*PalBtnActionCback_t)(uint8_t btnId, PalBtnPos_t pos);

/*! \brief      Audio button assignments (only mapped in audio applications). */
enum
{
  PAL_BTN_AUDIO_PLAY = 0x80,    /*!< Play button. */
  PAL_BTN_AUDIO_FWD,            /*!< Fast Forward button. */
  PAL_BTN_AUDIO_RWD,            /*!< Fast Rewind button. */
  PAL_BTN_AUDIO_VOL_UP,         /*!< Volume Up button. */
  PAL_BTN_AUDIO_VOL_DN,         /*!< Volume Down button. */
  PAL_BTN_AUDIO_MUTE,           /*!< Mute button. */
  PAL_BTN_PAUSE                 /*!< Pause button. */
};

/**************************************************************************************************
  Function Declarations
**************************************************************************************************/

/* Initialization */

/*************************************************************************************************/
/*! 
 *  \brief      Initialize buttons
 *
 *  \param      actCback      Button event callback (called in ISR context).
 */
/*************************************************************************************************/
void PalBtnInit(PalBtnActionCback_t actCback);

/*************************************************************************************************/
/*!
 *  \brief      De-Initialize buttons.
 *
 *  De-Initialize all buttons.
 */
/*************************************************************************************************/
void PalBtnDeInit(void);

/* Control and Status */

/*************************************************************************************************/
/*!
 *  \brief      Get the current state.
 *
 *  \return     Current state.
 *
 *  Return the current state of the TWI.
 */
/*************************************************************************************************/
PalBtnState_t PalBtnGetState(void);

/*************************************************************************************************/
/*!
 *  \brief      Get button state.
 *
 *  \param      btnId           Button ID.
 *
 *  \return     Button state.
 *
 *  Get the current button state.
 */
/*************************************************************************************************/
PalBtnPos_t PalBtnGetPosition(uint8_t btnId);

/*! \} */    /* PAL_BUTTON */

#ifdef __cplusplus
};
#endif

#endif /* PAL_BTN_H */
