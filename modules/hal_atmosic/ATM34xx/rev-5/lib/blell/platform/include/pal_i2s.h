/*************************************************************************************************/
/*!
 *  \file
 *
 *  \brief      I2S driver definition.
 *
 *  Copyright (c) 2019 ARM Ltd. All Rights Reserved.
 *
 *  Copyright (c) 2019-2022 Packetcraft, Inc.  All rights reserved.
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

#ifndef PAL_I2S_H
#define PAL_I2S_H

#include "pal_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/*! \addtogroup PAL_I2S
 *  \{ */

/**************************************************************************************************
  Data Types
**************************************************************************************************/

/*! \brief      Operational states. */
typedef enum
{
  PAL_I2S_STATE_UNINIT = 0,         /*!< Uninitialized state. */
  PAL_I2S_STATE_ERROR  = 0,         /*!< Error state. */
  PAL_I2S_STATE_IDLE,               /*!< Initialized state. */
  PAL_I2S_STATE_READY,              /*!< Configured state. */
  PAL_I2S_STATE_BUSY                /*!< Busy state. */
} PalI2sState_t;

/*! \brief      Call signature for next buffer pointer. */
typedef void (*PalI2sCompCback_t)(void *pCtx, uint32_t ts);

/*! \brief      I2S modes. */
typedef enum
{
  PAL_I2S_MODE_MASTER,              /*!< Master mode. */
  PAL_I2S_MODE_SLAVE                /*!< Slave mode. */
} PalI2sMode_t;

/*! \brief      Channels. */
typedef enum
{
  PAL_I2S_CH_LEFT_BIT   = (1 << 0), /*!< Left channel bit. */
  PAL_I2S_CH_RIGHT_BIT  = (1 << 1)  /*!< Right channel bit. */
} PalI2sChanMask_t;

/*! \brief      I2S configuration. */
typedef struct
{
  PalI2sMode_t      mode:8;         /*!< Mode of operation. */
  uint32_t          rate;           /*!< Sample rate. */
  uint8_t           bitDepth;       /*!< Sample bit depth. */
  uint8_t           chan;           /*!< Enabled channels. */
  PalI2sCompCback_t frmCback;       /*!< Get next read buffer callback. */
  void              *pCtx;          /*!< Opaque operation context. */
} PalI2sConfig_t;

/**************************************************************************************************
  Function Declarations
**************************************************************************************************/

/* Initialization */

/*************************************************************************************************/
/*!
 *  \brief      Initialize I2S resources.
 */
/*************************************************************************************************/
void PalI2sInit(void);

/*************************************************************************************************/
/*!
 *  \brief      De-initialize I2S resource.
 */
/*************************************************************************************************/
void PalI2sDeInit(void);

/* Control and Status */


/*************************************************************************************************/
/*!
 *  \brief      Get the current state.
 *
 *  \return     Current state.
 *
 *  Return the current state of the I2S driver.
 */
/*************************************************************************************************/
PalI2sState_t PalI2sGetState(void);

/*************************************************************************************************/
/*!
 *  \brief      Initialize I2S configuration.
 *
 *  \param      pCfg         Pointer to I2s Configuration.
 */
/*************************************************************************************************/
void PalI2sConfig(PalI2sConfig_t *pCfg);

/*************************************************************************************************/
/*!
 *  \brief      De-initialize I2S configuration.
 */
/*************************************************************************************************/
void PalI2sDeConfig(void);

/* Data Transfer */

/*************************************************************************************************/
/*!
 *  \brief      Read data from I2S interface.
 *
 *  \param      pData       Read buffer.
 *  \param      len         Number of bytes to write.
 */
/*************************************************************************************************/
void PalI2sReadData(uint8_t *pData, uint16_t len);

/*************************************************************************************************/
/*!
 *  \brief      Write data to I2S interface.
 *
 *  \param      pData       Write buffer.
 *  \param      len         Number of bytes to write.
 */
/*************************************************************************************************/
void PalI2sWriteData(const uint8_t *pData, uint16_t len);

/*************************************************************************************************/
/*!
 *  \brief      Bidirectional read and write data to I2S interface.
 *
 *  \param      pRdData       Read buffer.
 *  \param      pWrData       Write buffer.
 *  \param      len           Number of bytes to read and write.
 */
/*************************************************************************************************/
void PalI2sReadWriteData(uint8_t *pRdData, const uint8_t *pWrData, uint16_t len);

/*! \} */    /* PAL_I2S */

#ifdef __cplusplus
};
#endif

#endif /* PAL_I2S_H */
