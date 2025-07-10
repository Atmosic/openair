/*************************************************************************************************/
/*!
 *  \file
 *
 *  \brief      FRC interface file.
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

#ifndef PAL_FRC_H
#define PAL_FRC_H

#include "pal_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/*! \addtogroup PAL_FRC
 *  \{ */

/**************************************************************************************************
  Data Types
**************************************************************************************************/

/*! \brief      Expiration callback. */
typedef void (*PalFrcExpCback_t)(void);

/*! \brief      FRC states. */
typedef enum
{
  PAL_FRC_STATE_UNINIT = 0,         /*!< Uninitialized state. */
  PAL_FRC_STATE_ERROR  = 0,         /*!< Error state. */
  PAL_FRC_STATE_READY,              /*!< Ready state. */
  PAL_FRC_STATE_BUSY                /*!< Busy state. */
} PalFrcState_t;

/*! \brief      Reserved FRC timer ID. */
typedef enum
{
  PAL_FRC_ID_SCH       = 0,         /*!< Scheduler timer ID. */
  PAL_FRC_ID_AUD       = 1,         /*!< Audio timer ID. */
  PAL_FRC_ID_MAX                    /*!< Number of timer instances. */
} PalFrcId_t;

/**************************************************************************************************
  Function Declarations
**************************************************************************************************/

/* Initialization */

/*************************************************************************************************/
/*!
 *  \brief      FRC initialization.
 */
/*************************************************************************************************/
void PalFrcInit(void);

/*************************************************************************************************/
/*!
 *  \brief      FRC de-initialization.
 */
/*************************************************************************************************/
void PalFrcDeInit(void);

/* Control and Status */

/*************************************************************************************************/
/*!
 *  \brief      Start a timer.
 *
 *  \param      expTime     Expiration time.
 *  \param      expCback    Expiration callback.
 */
/*************************************************************************************************/
void PalFrcSetTimer(PalFrcId_t id, uint32_t expTimeUsec, PalFrcExpCback_t expCback);

/*************************************************************************************************/
/*!
 *  \brief      Clear timer.
 */
/*************************************************************************************************/
void PalFrcClearTimer(PalFrcId_t id);

/*************************************************************************************************/
/*!
 *  \brief      Get duration to the next timer expiration.
 *
 *  \return     Duration to next expiration in microseconds; 0 if no timer is set.
 */
/*************************************************************************************************/
uint32_t PalFrcGetNextExpiration(void);

/*************************************************************************************************/
/*!
 *  \brief      Get current time.
 *
 *  \return     FRC time.
 */
/*************************************************************************************************/
uint32_t PalFrcGetCurrentTime(void);

/*************************************************************************************************/
/*!
 *  \brief      Get delta between target and reference time.
 *
 *  \param      endTime       End time.
 *  \param      startTime     Start time.
 *
 *  \return     A positive number in microseconds between \a startTime and \a endTime.
 *              0 if \startTime is after \a endTime (negative delta).
 */
/*************************************************************************************************/
static inline uint32_t PalFrcCalcDeltaTime(uint32_t endTime, uint32_t startTime)
{
  uint32_t delta = endTime - startTime;

  /* Large delta indicates an invalid time in the past. */
  return ((delta & (UINT32_C(1) << 31)) != 0) ? 0 : delta;
}

/*! \} */    /* PAL_FRC */

#ifdef __cplusplus
};
#endif

#endif
