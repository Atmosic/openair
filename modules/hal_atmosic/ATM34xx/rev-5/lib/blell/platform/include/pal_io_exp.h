/*************************************************************************************************/
/*!
 *  \file
 *
 *  \brief      I/O expander driver definition.
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

#ifndef PAL_IO_EXP_H
#define PAL_IO_EXP_H

#include "pal_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/*! \addtogroup PAL_IO_EXP
 *  \{ */

/**************************************************************************************************
  Macros
**************************************************************************************************/

/*! \brief      Invalid device ID. */
#define PAL_IO_EXP_INVALID_ID 0xFF

/**************************************************************************************************
  Data Types
**************************************************************************************************/

/*! \brief      Read register completion callback. */
typedef void (*PalIoExpReadCompCback_t)(uint32_t value);

/*! \brief      Write register completion callback. */
typedef void (*PalIoExpWriteCompCback_t)(void);

/*! \brief      Device configuration. */
typedef struct
{
  PalIoExpReadCompCback_t rdCback;  /*!< Read data completion callback. */
  PalIoExpWriteCompCback_t wrCback; /*!< Write data completion callback. */
  uint32_t inputMask;               /*!< Bitmask for input pins (1 for input, 0 for output). */
  uint8_t addr;                     /*!< Device address defined by the voltage on the board. */
} PalIoExpConfig_t;

/*! \brief      Operational states. */
typedef enum
{
  PAL_IO_EXP_STATE_UNINIT = 0,  /*!< Uninitialized state. */
  PAL_IO_EXP_STATE_ERROR  = 0,  /*!< Error state. */
  PAL_IO_EXP_STATE_READY  = 1,  /*!< Ready state. */
  PAL_IO_EXP_STATE_BUSY   = 2,  /*!< Busy state. */
} PalIoExpState_t;

/**************************************************************************************************
  Function Declarations
**************************************************************************************************/

/* Initialization */

/*************************************************************************************************/
/*!
 *  \brief    Initialize I/O Expander.
 *
 *  \param    pCfg     I/O Expander configuration.
 *
 *  \return   Device ID.
 */
/*************************************************************************************************/
uint8_t PalIoExpInit(PalIoExpConfig_t *pCfg);

/*! \brief  TBD */
void PalIoExpDeInit(void);

/* Control and Status */

/*************************************************************************************************/
/*!
 *  \brief      Get the current state.
 *
 *  \param      id   Device ID.
 *
 *  \return     Current state.
 */
/*************************************************************************************************/
PalIoExpState_t PalIoExpGetState(uint8_t id);

/* Data transfer */

/*************************************************************************************************/
/*!
 *  \brief    Read port status.
 *
 *  \param    id   Device ID.
 *
 *  \note     This is a non-blocking API. Port value will be reported in rdCback.
 */
/*************************************************************************************************/
void PalIoExpRead(uint8_t id);

/*************************************************************************************************/
/*!
 *  \brief    Write port value.
 *
 *  \param    id      Device ID.
 *  \param    value   New port value.
 *
 *  \note     This is a non-blocking API.
 */
/*************************************************************************************************/
void PalIoExpWrite(uint8_t id, uint32_t value);

/*! \} */    /* PAL_IO_EXP */

#ifdef __cplusplus
};
#endif

#endif /* PAL_IO_EXP_H */
