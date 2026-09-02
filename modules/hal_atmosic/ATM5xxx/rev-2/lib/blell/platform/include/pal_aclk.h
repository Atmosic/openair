/*************************************************************************************************/
/*!
 *  \file
 *
 *  \brief      Audio PLL.
 *
 *  Copyright (c) 2019-2023 Packetcraft, Inc.  All rights reserved.
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

#ifndef PAL_ACLK_H
#define PAL_ACLK_H

#include "pal_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/*! \addtogroup PAL_TWI
 *  \{ */

/*************************************************************************************************/
/*!
 *  \brief      Initialize Audio PLL.
 */
/*************************************************************************************************/
void PalAclkInit(void);

/*************************************************************************************************/
/*!
 *  \brief      De-Initialize Audio PLL.
 */
/*************************************************************************************************/
void PalAclkDeInit(void);

/*************************************************************************************************/
/*!
 *  \brief      Set Audio PLL center frequency.
 *
 *  \param      freqHz  Center frequency.
 */
/*************************************************************************************************/
void PalAclkCenter(uint32_t freqHz);

/*************************************************************************************************/
/*!
 *  \brief      Adjust Audio PLL frequency.
 *
 *  \param      freqHz  Frequency adjustment.
 */
/*************************************************************************************************/
void PalAclkAdjust(int32_t freqHz);

/*! \} */    /* PAL_TWI */

#ifdef __cplusplus
};
#endif

#endif /* PAL_ACLK_H */
