/*************************************************************************************************/
/*!
 *  \file
 *
 *  \brief  System hooks.
 *
 *  Copyright (c) 2016-2019 Arm Ltd. All Rights Reserved.
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

#ifndef PAL_SYS_H
#define PAL_SYS_H

#include "pal_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/*! \addtogroup PAL_SYS
 *  \{ */

/**************************************************************************************************
  Macros
**************************************************************************************************/

#ifdef DEBUG

/*! \brief      Error check routines; for use with PAL implementation only. */
#define PAL_SYS_ASSERT(expr)    { if (!(expr)) { PalSysAssertTrap(); } }

#else

/*! \brief      Error check routines (disabled). */
#define PAL_SYS_ASSERT(expr)

#endif

/*! \brief    Align to the next largest width (w must be byte size of 2, 4, 8, 16). */
#define PAL_SYS_ALIGN(x,w)      (((x) + (w) - 1) / (w))

/*! \brief      Reset reason code. */
typedef enum
{
  PAL_SYS_RESET_COLD_BOOT,      /*!< Reset due to cold boot. */
  PAL_SYS_RESET_DEEP_SLEEP,     /*!< Boot from deep sleep. */
  PAL_SYS_RESET_REASON_HCI,     /*!< Reset due to HCI command. */
} PalSysResetReasons_t;

/**************************************************************************************************
  Function Declarations
**************************************************************************************************/

/* Initialization */

/*************************************************************************************************/
/*!
 *  \brief      Common platform initialization.
 */
/*************************************************************************************************/
void PalSysInit(void);

/*************************************************************************************************/
/*!
 *  \brief      Extended platform initialization.
 *
 *  \param      heapSizeOverride    Override heap size if nonzero heapOverride.
 */
/*************************************************************************************************/
void PalSysInitExt(uint32_t heapSizeOverride);

/*************************************************************************************************/
/*!
 *  \brief  get heap end address.
 *  \return heap end.
 */
/*************************************************************************************************/
unsigned long PalSysGetHeapEnd(void);

/*************************************************************************************************/
/*!
 *  \brief  get heap start address.
 *  \return heap start.
 */
/*************************************************************************************************/
unsigned long PalSysGetHeapStart(void);

/*************************************************************************************************/
/*!
 *  \brief      Common platform initialization completion.
 */
/*************************************************************************************************/
void PalSysInitFinalize(void);

/* Diagnostics */

/*************************************************************************************************/
/*!
 *  \brief      System fault trap.
 */
/*************************************************************************************************/
void PalSysAssertTrap(void);

/*************************************************************************************************/
/*!
 *  \brief      Set system trap.
 *
 *  \param      enable    Enable assert trap or not.
 */
/*************************************************************************************************/
void PalSysSetTrap(bool enable);

/*************************************************************************************************/
/*!
 *  \brief      Get assert count.
 *
 *  \param      clear     Clear counter.
 *
 *  \return     Number of assertions.
 */
/*************************************************************************************************/
uint32_t PalSysGetAssertCount(bool clear);

/*************************************************************************************************/
/*!
 *  \brief      Count stack usage.
 *
 *  \return     Number of bytes used by the stack.
 */
/*************************************************************************************************/
uint32_t PalSysGetStackUsage(void);

/*************************************************************************************************/
/*!
 *  \brief  Write buffer to diagnostics port.
 *
 *  \param  pBuf      Buffer.
 *  \param  len       Buffer length.
 *
 *  \return Always true.
 */
/*************************************************************************************************/
bool PalSysDiagTraceWrite(const uint8_t *pBuf, uint32_t len);

/* Power Management */

/*************************************************************************************************/
/*!
 *  \brief      System sleep.
 *
 *  \param      nextWakeMs  Next CPU wakeup time.
 *
 *  \note       Caller of this routine must ensure IRQ are disabled before entering this call.
 */
/*************************************************************************************************/
void PalSysSleep(uint32_t nextWakeMs);

/*************************************************************************************************/
/*!
 *  \brief      Check for Deep Sleep wake-up, and perform a warm-boot procedure if detected.
 */
/*************************************************************************************************/
void PalSysWakeFromDeepSleep(void);

/* Critical Section */

/*************************************************************************************************/
/*!
 *  \brief      Enter a critical section.
 */
/*************************************************************************************************/
void PalSysCsEnter(void);

/*************************************************************************************************/
/*!
 *  \brief      Exit a critical section.
 */
/*************************************************************************************************/
void PalSysCsExit(void);

/*************************************************************************************************/
/*!
 *  \brief  Pal background task entry
 */
/*************************************************************************************************/
#ifdef PAL_SYS_BACKGROUND_TASK
void PalSysRunBackground(void);
#endif
/* Reset */

/*************************************************************************************************/
/*!
 *  \brief      Reset system.
 *
 *  \param      reason    Reset reason code.
 */
/*************************************************************************************************/
void PalSysReset(PalSysResetReasons_t reason);

/*************************************************************************************************/
/*!
 *  \brief      Get reset reason code.
 *
 *  \return     Reset reason code.
 */
/*************************************************************************************************/
PalSysResetReasons_t PalSysGetResetReason(void);

/* Critical Interrupt Section */

/*! \brief      Critical interrupt callback function. */
typedef void (*PalSysCiCback_t)(void);

/*************************************************************************************************/
/*!
 *  \brief      Save callback for critical interrupt section.
 *
 *  \param      cback   Critical interrupt callback function.
 */
/*************************************************************************************************/
void PalSysCiInit(PalSysCiCback_t cback);

/*************************************************************************************************/
/*!
 *  \brief      Enter a critical interrupt section.
 */
/*************************************************************************************************/
void PalSysCiEnter(void);

/*************************************************************************************************/
/*!
 *  \brief      Exit a critical interrupt section.
 */
/*************************************************************************************************/
void PalSysCiExit(void);

/*************************************************************************************************/
/*!
 *  \brief     Set critical interrupt section IRQ.
 */
/*************************************************************************************************/
void PalSysCiSetIrq(void);

/*! \} */    /* PAL_SYS */

#ifdef __cplusplus
};
#endif

#endif  /* PAL_SYS_H */
