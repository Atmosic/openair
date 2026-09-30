/*************************************************************************************************/
/*!
 *  \file
 *
 *  \brief      RTC timer interface file.
 *
 *  Copyright (c) 2018 Arm Ltd. All Rights Reserved.
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

#ifndef PAL_RTC_H
#define PAL_RTC_H

#include "pal_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/*! \addtogroup PAL_RTC
 *  \{ */

/**************************************************************************************************
  Type Definitions
**************************************************************************************************/

/*! \brief      Operational states. */
typedef enum
{
  PAL_RTC_STATE_UNINIT = 0,     /*!< Uninitialized state. */
  PAL_RTC_STATE_ERROR  = 0,     /*!< Error state. */
  PAL_RTC_STATE_READY  = 1      /*!< Ready state. */
} PalRtcState_t;

/*! \brief  Platform RTC callback. */
typedef void (*palRtcIrqCback_t)(void);

/**************************************************************************************************
  Macros
**************************************************************************************************/

#ifndef PAL_RTC_TICKS_PER_SEC
#define PAL_RTC_TICKS_PER_SEC 32768
#endif

/**************************************************************************************************
  Function Declarations
**************************************************************************************************/

/* Initialization */

/*************************************************************************************************/
/*!
 *  \brief      RTC initialization.
 */
/*************************************************************************************************/
void PalRtcInit(void);

/*************************************************************************************************/
/*!
 *  \brief      RTC de-initialization.
 */
/*************************************************************************************************/
void PalRtcDeInit(void);

/* Control and Status */

/*************************************************************************************************/
/*!
 *  \brief  Get RTC current time.
 *
 *  \return FRC time.
 */
/*************************************************************************************************/
uint32_t PalRtcGetCurrentTime(void);

/*************************************************************************************************/
/*!
 *  \brief  Calculate RTC delta time in milliseconds.
 *
 *  \param  endTime       End time counter
 *  \param  startTime     Start time counter
 *
 *  \return Delta time in milliseconds
 */
/*************************************************************************************************/
uint32_t PalRtcCalcDeltaTimeMs(uint32_t endTime, uint32_t startTime);

/*************************************************************************************************/
/*!
 *  \brief  Calculate RTC counter from time in milliseconds.
 *
 *  \param  timeMs        Time in milliseconds
 *
 *  \return Time in LPC
 */
/*************************************************************************************************/
uint32_t PalRtcMsToRtcCount(uint32_t timeMs);

uint32_t PalRtcGetCurrentTime(void);
uint32_t PalRtcCalcDeltaTimeMs(uint32_t endTime, uint32_t startTime);
uint32_t PalRtcMsToRtcCount(uint32_t timeMs);
/*! \} */    /* PAL_RTC */

#ifdef __cplusplus
};
#endif

#endif
