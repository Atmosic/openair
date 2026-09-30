/*************************************************************************************************/
/*!
 *  \file
 *
 *  \brief      LED driver definition.
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

#ifndef PAL_LED_BLINK_H
#define PAL_LED_BLINK_H

#include "wsf_os.h"

#ifdef __cplusplus
extern "C" {
#endif

/*! \addtogroup PAL_LED_BLINK
 *  \{ */


/**************************************************************************************************
  Function Declarations
**************************************************************************************************/

/* Initialization */

/*************************************************************************************************/
/*!
 *  \brief      Initialize Blink feature of LEDs.
 *  \param      handlerId     Wsf message handler id.
 */
/*************************************************************************************************/
void PalLedBlinkInit(wsfHandlerId_t handlerId);

/*************************************************************************************************/
/*!
 *  \brief      De-initialize blink feature of LEDs.
 */
/*************************************************************************************************/
void PalLedBlinkDeInit(void);

/*************************************************************************************************/
/*!
 *  \brief  WSF event handler for the led blinking.
 *
 *  \param  event   WSF event mask.
 *  \param  pMsg    WSF message.
 *
 *  \return None.
 */
/*************************************************************************************************/
void PalLedBlinkHandler(wsfEventMask_t event, wsfMsgHdr_t *pMsg);

/* Control and Status */

/*************************************************************************************************/
/*!
 *  \brief      Set LED to blink/flash for the designated number of blinks.
 *
 *  \param      ledId           LED ID.
 *  \param      blinkPeriodMs   Timer Period (ms)
 *  \param      dutyCycle       Duty cycle (%)
 *  \param      flashCount      Number of flashes (full blinkPeriodMs duty cycles)
 */
/*************************************************************************************************/
void PalLedFlash(uint8_t ledId, uint16_t blinkPeriodMs, uint8_t dutyCycle, uint8_t flashCount);


/*************************************************************************************************/
/*!
 *  \brief      Set LED into continuous blink mode.
 *
 *  \param      ledId           LED ID.
 *  \param      blinkPeriodMs   Timer Period (ms)
 *  \param      dutyCycle       Duty cycle (%)
 */
/*************************************************************************************************/
void PalLedBlink(uint8_t ledId, uint16_t blinkPeriodMs, uint8_t dutyCycle);


/*! \} */    /* PAL_LED */

#ifdef __cplusplus
};
#endif

#endif /* PAL_LED_H */
