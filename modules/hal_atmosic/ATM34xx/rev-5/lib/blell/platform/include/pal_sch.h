/*************************************************************************************************/
/*!
 *  \file
 *
 *  \brief  Scheduler event ISR hooks.
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

#ifndef PAL_SCH_H
#define PAL_SCH_H

#ifdef __cplusplus
extern "C" {
#endif

/**************************************************************************************************
  Macros
**************************************************************************************************/

#if (SCH_ENABLE_EVT_ISR)
#define SCH_EVT_CS_ENTER() PalSchCsEnter()
#define SCH_EVT_CS_EXIT() PalSchCsExit()
#else
#define SCH_EVT_CS_ENTER()
#define SCH_EVT_CS_EXIT()
#endif

/**************************************************************************************************
  Function Declarations
**************************************************************************************************/

/*************************************************************************************************/
/*!
 *  \brief  Schedule event callback type
 */
/*************************************************************************************************/
typedef void (*PalSchEvtCback_t)(void);

/*************************************************************************************************/
/*!
 *  \brief  Set pending IRQ for scheduler event
 */
/*************************************************************************************************/
void PalSchSetPendingIRQ(void);

/*************************************************************************************************/
/*!
 *  \brief  PAL scheduler driver initialization
 *
 *  \param  cb        Scheduler event callback function
 */
/*************************************************************************************************/
void PalSchInit(PalSchEvtCback_t cb);

/*************************************************************************************************/
/*!
 *  \brief  Disable scheduler IRQ mask
 */
/*************************************************************************************************/
void PalSchCsEnter(void);

/*************************************************************************************************/
/*!
 *  \brief  Enable scheduler IRQ mask
 */
/*************************************************************************************************/
void PalSchCsExit(void);

#ifdef __cplusplus
};
#endif

#endif  /* PAL_SCH_H */
