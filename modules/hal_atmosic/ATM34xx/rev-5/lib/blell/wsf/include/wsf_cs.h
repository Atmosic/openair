/*************************************************************************************************/
/*!
 *  \file   wsf_cs.h
 *
 *  \brief  Critical section macros.
 *
 *  Copyright (c) 2009-2018 Arm Ltd. All Rights Reserved.
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
#ifndef WSF_CS_H
#define WSF_CS_H

#ifdef __cplusplus
extern "C" {
#endif

/**************************************************************************************************
  External Variables
**************************************************************************************************/
extern uint8_t wsfCsNesting;

/*! \addtogroup WSF_CS_API
 *  \{ */

/**************************************************************************************************
  Macros
**************************************************************************************************/

#ifndef WSF_CS_STATS
/*! \brief  Use CS statistics hooks. */
#define WSF_CS_STATS    false
#endif

#ifndef WSF_CI_ENABLE
/*! \brief  Enable critical interrupts. */
#define WSF_CI_ENABLE   false
#endif

/*************************************************************************************************/
/*!
  *  \def    WSF_CS_INIT
  *
  *  \brief  Initialize critical section.  This macro may define a variable.
  *
  *  \param  cs    Critical section variable to be defined.
  */
/*************************************************************************************************/
#define WSF_CS_INIT(cs)

/*************************************************************************************************/
/*!
  *  \def    WSF_CS_ENTER
  *
  *  \brief  Enter a critical section.
  *
  *  \param  cs    Critical section variable.
  */
/*************************************************************************************************/
#define WSF_CS_ENTER(cs)       WsfCsEnter()

/*************************************************************************************************/
/*!
  *  \def    WSF_CS_EXIT
  *
  *  \brief  Exit a critical section.
  *
  *  \param  cs    Critical section variable.
  */
/*************************************************************************************************/
#define WSF_CS_EXIT(cs)        WsfCsExit()

/**************************************************************************************************
  Function Declarations
**************************************************************************************************/

/*************************************************************************************************/
/*!
 *  \brief   Get critical section duration watermark level.
 *
 *  \return  Critical section duration watermark level.
 */
/*************************************************************************************************/
uint32_t WsfCsStatsGetCsWaterMark(void);

/*************************************************************************************************/
/*!
 *  \brief   Enter a critical section.
 */
/*************************************************************************************************/
void WsfCsEnter(void);

/*************************************************************************************************/
/*!
 *  \brief   Exit a critical section.
 */
/*************************************************************************************************/
void WsfCsExit(void);


#if (WSF_CI_ENABLE == false)
#define WSF_CI_ENTER()
#define WSF_CI_EXIT()
#else
/*! \brief      Critical interrupt sections. */
#define WSF_CI_ENTER()                  WsfCiEnter()
#define WSF_CI_EXIT()                   WsfCiExit()
#endif

#if (WSF_CI_ENABLE == true)
/*************************************************************************************************/
/*!
 *  \brief   Enter a critical interrupt section.
 */
/*************************************************************************************************/
void WsfCiEnter(void);

/*************************************************************************************************/
/*!
 *  \brief   Exit a critical interrupt section.
 */
/*************************************************************************************************/
void WsfCiExit(void);

/*************************************************************************************************/
/*!
 *  \brief  Initialize critical interrupt section handler.
 *
 *  \param  cb   Critical interrupt callback function.
 */
/*************************************************************************************************/
void WsfCiInit(void (*cb)(void));

/*************************************************************************************************/
/*!
 *  \brief   Set critical interrupt section IRQ.
 */
/*************************************************************************************************/
void WsfSetCiIrq(void);

#endif

/*! \} */    /* WSF_CS_API */

#ifdef __cplusplus
};
#endif

#endif /* WSF_CS_H */
