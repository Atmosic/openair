/*************************************************************************************************/
/*!
 *  \file
 *
 *  \brief      USB driver definition.
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

#ifndef PAL_USB_H
#define PAL_USB_H

#include "pal_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/**************************************************************************************************
  Data Types
**************************************************************************************************/

/*! \brief      USB device callback. */
typedef void (*PalUsbDeviceCback_t)(uint32_t event);

/*! \brief      USB power callback. */
typedef void (*PalUsbPowerCback_t)(uint32_t event);

/*! \brief      Peripheral configuration. */
typedef struct
{
  PalUsbPowerCback_t deviceCback; /*!< USB device callback. */
  PalUsbDeviceCback_t powerCback; /*!< USB power callback. */
} PalUsbConfig_t;

/*! \addtogroup PAL_USB
 *  \{ */

/*************************************************************************************************/
/*!
 *  \brief      Initialize USB.
 *
 *  \param      id      USB ID.
 *  \param      pCfg    Peripheral configuration.
 */
/*************************************************************************************************/
void PalUsbInit(uint8_t id, PalUsbConfig_t *pCfg);

/*************************************************************************************************/
/*!
 *  \brief      De-Initialize USB.
 *
 *  \param      id      USB ID.
 */
/*************************************************************************************************/
void PalUsbDeInit(uint8_t id);

  /*! \} */    /* PAL_USB */

#ifdef __cplusplus
};
#endif

#endif /* PAL_USB_H */
