/*************************************************************************************************/
/*!
 *  \file
 *
 *  \brief      PDM driver definition.
 *
 *  Copyright (c) 2019-2023 Packetcraft, Inc.  All rights reserved.
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

#ifndef PAL_PDM_H
#define PAL_PDM_H

#include "pal_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/*! \addtogroup PAL_PDM
 *  \{ */

/**************************************************************************************************
  Data Types
**************************************************************************************************/

/*! \brief      Operational states. */
typedef enum
{
  PAL_PDM_STATE_UNINIT = 0,         /*!< Uninitialized state. */
  PAL_PDM_STATE_ERROR  = 0,         /*!< Error state. */
  PAL_PDM_STATE_READY,              /*!< Initialized and configured state. */
  PAL_PDM_STATE_BUSY                /*!< Busy state. */
} PalPdmState_t;

/*! \brief      PDM modes. */
typedef enum
{
  PAL_PDM_MODE_MONO,                /*!< Mono mode. */
  PAL_PDM_MODE_STEREO               /*!< Stereo mode. */
} PalPdmMode_t;

/*! \brief      Call signature for next buffer pointer. */
typedef void (*PalPdmCompCback_t)(void *pCtx, uint32_t ts);

/*! \brief      PDM configuration. */
typedef struct
{
  PalPdmMode_t      mode:8;         /*!< Mode of operation. */
  PalPdmCompCback_t frmCback;       /*!< Get next read buffer callback. */
  void              *pCtx;          /*!< Opaque operation context. */
} PalPdmConfig_t;

/**************************************************************************************************
  Function Declarations
**************************************************************************************************/

/* Initialization */

/*************************************************************************************************/
/*!
 *  \brief      Initialize PDM resources.
 *
 *  \param      pCfg         Pointer to PDM Configuration.
 */
/*************************************************************************************************/
void PalPdmInit(PalPdmConfig_t *pCfg);

/*************************************************************************************************/
/*!
 *  \brief      De-initialize PDM resource.
 */
/*************************************************************************************************/
void PalPdmDeInit(void);

/*************************************************************************************************/
/*!
 *  \brief      Supply the sample buffer.
 *
 *  \param      pBuf        Pointer to the receive buffer.
 *  \param      len         Length of the receive buffer in 16-bit words.
 */
/*************************************************************************************************/
void PalPdmReadData(int16_t *pBuf, uint16_t len);

/*! \} */    /* PAL_PDM */

#ifdef __cplusplus
};
#endif

#endif /* PAL_PDM_H */
