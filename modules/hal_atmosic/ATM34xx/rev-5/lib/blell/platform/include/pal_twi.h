/*************************************************************************************************/
/*!
 *  \file
 *
 *  \brief      TWI driver definition.
 *
 *  Copyright (c) 2018 ARM Ltd. All Rights Reserved.
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

#ifndef PAL_TWI_H
#define PAL_TWI_H

#include "pal_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/*! \addtogroup PAL_TWI
 *  \{ */

/**************************************************************************************************
  Macros
**************************************************************************************************/

/*! \brief      Invalid device ID. */
#define PAL_TWI_INVALID_ID      0xFF

/**************************************************************************************************
  Data Types
**************************************************************************************************/

/*! \brief      Operation ready callback. */
typedef void (*PalTwiOpReadyCback_t)(uint8_t id);

/*! \brief      Completion callback (success=true if ACK received, false otherwise). */
typedef void (*PalTwiCompCback_t)(uint8_t id, bool success);

/*! \brief      TWI device configuration. */
typedef struct
{
  uint8_t devAddr;                      /*!< Device address. */
  PalTwiOpReadyCback_t opReadyCback;    /*!< Operation ready callback. */
  PalTwiCompCback_t rdCback;            /*!< Read data completion callback. */
  PalTwiCompCback_t wrCback;            /*!< Write data completion callback. */
} PalTwiDevConfig_t;

/*! \brief      Operational states. */
typedef enum
{
  PAL_TWI_STATE_UNINIT = 0,             /*!< Uninitialized state. */
  PAL_TWI_STATE_ERROR  = 0,             /*!< Error state. */
  PAL_TWI_STATE_READY,                  /*!< Ready state. */
  PAL_TWI_STATE_BUSY_DATA_PEND,         /*!< Busy state (operation in progress), Data pending substate. */
  PAL_TWI_STATE_BUSY_DATA_XFER          /*!< Busy state (operation in progress), Data transfer substate. */
} PalTwiState_t;

/**************************************************************************************************
  Function Declarations
**************************************************************************************************/

/* Initialization */

/*************************************************************************************************/
/*!
 *  \brief      Initialize TWI resources.
 */
/*************************************************************************************************/
void PalTwiInit(void);

/*************************************************************************************************/
/*!
 *  \brief      De-Initialize the TWI resources.
 */
/*************************************************************************************************/
void PalTwiDeInit(void);

/*************************************************************************************************/
/*!
 *  \brief      Register a device on the TWI bus.
 *
 *  \param      pDevCfg     Device configuration.
 *
 *  \return     Device handle.
 */
/*************************************************************************************************/
uint8_t PalTwiRegisterDevice(PalTwiDevConfig_t *pDevCfg);

/* Control and Status */

/*************************************************************************************************/
/*!
 *  \brief      Get the current state.
 *
 *  \return     Current state.
 *
 *  Return the current state of the TWI.
 */
/*************************************************************************************************/
PalTwiState_t PalTwiGetState(void);

/* Data Transfer */

/*************************************************************************************************/
/*!
 *  \brief      Always start an operation before reading or writing on TWI interface.
 *
 *  \param      handle      Device handle.
 */
/*************************************************************************************************/
void PalTwiStartOperation(uint8_t handle);

/*************************************************************************************************/
/*!
 *  \brief      Always stop an operation after reading or writing on TWI interface.
 *
 *  \param      handle      Device handle.
 */
/*************************************************************************************************/
void PalTwiStopOperation(uint8_t handle);

/*************************************************************************************************/
/*!
 *  \brief      Read data from TWI interface.
 *
 *  \param      handle      Device handle.
 *  \param      pData       Read buffer.
 *  \param      len         Number of bytes to write.
 *
 *  Read \a len bytes from \a pData to the TWI device.
 */
/*************************************************************************************************/
void PalTwiReadData(uint8_t handle, uint8_t *pData, uint8_t len);

/*************************************************************************************************/
/*!
 *  \brief      Write data to TWI interface.
 *
 *  \param      handle      Device handle.
 *  \param      pData       Write buffer.
 *  \param      len         Number of bytes to write.
 *
 *  Transfer \a len bytes from \a pData to the TWI device.
 */
/*************************************************************************************************/
void PalTwiWriteData(uint8_t handle, const uint8_t *pData, uint8_t len);

/*! \} */    /* PAL_TWI */

#ifdef __cplusplus
};
#endif

#endif /* PAL_TWI_H */
