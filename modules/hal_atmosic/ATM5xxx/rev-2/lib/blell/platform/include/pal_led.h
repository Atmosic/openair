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

#ifndef PAL_LED_H
#define PAL_LED_H

#include "pal_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/*! \addtogroup PAL_LED
 *  \{ */

/**************************************************************************************************
  Data Types
**************************************************************************************************/

/*! \brief      Reserved LED IDs. */
typedef enum
{
  /* System signals. */
  PAL_LED_ID_CPU_ACTIVE     = 16,   /*!< CPU active LED ID. */
  PAL_LED_ID_ERROR          = 17,   /*!< Error LED ID. */
  /* Radio signals. */
  PAL_LED_ID_BLE_TX         = 18,   /*!< BLE Tx LED ID. */
  PAL_LED_ID_BLE_RX         = 19,   /*!< BLE Rx LED ID. */
  PAL_LED_ID_BLE_RX_FAULT   = 20,   /*!< BLE Rx fault LED ID. */
  /* Codec signals. */
  PAL_LED_ID_CODEC_ACTIVE   = 21,   /*!< Codec active LED ID. */
  PAL_LED_ID_CODEC_FAULT    = 22,   /*!< Codec fault LED ID. */

  PAL_LED_ID_MAX                    /*!< Maximum LED ID. */
} PalLedId_t;

/*! \brief      LED operation mode. */
typedef enum
{
  PAL_LED_MODE_ACTIVE_LOW   = 0x00, /*!< Active low. */
  PAL_LED_MODE_ACTIVE_HIGH  = 0x01, /*!< Active high. */
  PAL_LED_MODE_DISABLE      = 0xFF  /*!< Disable toggle. */
} PalLedMode_t;

/**************************************************************************************************
  Function Declarations
**************************************************************************************************/

/* Initialization */

/*************************************************************************************************/
/*!
 *  \brief      Initialize LEDs.
 */
/*************************************************************************************************/
void PalLedInit(void);

/*************************************************************************************************/
/*!
 *  \brief      De-initialize LEDs.
 */
/*************************************************************************************************/
void PalLedDeInit(void);

/* Control and Status */

/*************************************************************************************************/
/*!
 *  \brief      Remap LED pin.
 *
 *  \param      id              LED ID.
 *  \param      mode            LED mode.
 *  \param      pin             LED pin location.
 *
 *  \return     TBD
 */
/*************************************************************************************************/
bool PalLedRemap(PalLedId_t id, PalLedMode_t mode, uint16_t pin);

/*************************************************************************************************/
/*!
 *  \brief      Set LED on.
 *
 *  \param      ledId           LED ID.
 */
/*************************************************************************************************/
void PalLedOn(uint8_t ledId);

/*************************************************************************************************/
/*!
 *  \brief      Set LED off.
 *
 *  \param      ledId           LED ID.
 */
/*************************************************************************************************/
void PalLedOff(uint8_t ledId);

/*! \} */    /* PAL_LED */

#ifdef __cplusplus
};
#endif

#endif /* PAL_LED_H */
