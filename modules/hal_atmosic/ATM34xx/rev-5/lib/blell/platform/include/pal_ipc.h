/*************************************************************************************************/
/*!
 *  \file
 *
 *  \brief      IPC driver definition.
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

#ifndef PAL_IPC_H
#define PAL_IPC_H

#include "pal_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/*! \addtogroup PAL_IPC
 *  \{ */

/**************************************************************************************************
  Type Definitions
**************************************************************************************************/

/*! \brief      Message types. */
typedef enum
{
  /* Values 0-15 available for application-specific use. */
  PAL_IPC_TYPE_APP_MIN = 0,         /*!< Lower limit of IPC message types reserved for use by Application */
  PAL_IPC_TYPE_APP_MAX = 15,        /*!< Upper limit of IPC message types reserved for use by Application */
  /* System IPC types. */
  PAL_IPC_TYPE_HCI = 16,            /*!< HCI message type. */
  PAL_IPC_TYPE_AIF = 17,            /*!< AIF message type. */
  PAL_IPC_TYPE_BTN = 18,            /*!< Button message type. */
  PAL_IPC_TYPE_OOB_KEYS = 19,       /*!< OOB keys message type. */
  PAL_IPC_TYPE_TERMINAL = 20,       /*!< Terminal message type. */
  PAL_IPC_TYPE_TRACE = 21,          /*!< Trace message type. */
  PAL_IPC_TYPE_DIAG = 22,           /*!< Diagnostics message type. */
  PAL_IPC_TYPE_MAX                  /*!< Maximum message type. */
} PalIpcType_t;

/*! \brief      Operational states. */
typedef enum
{
  PAL_IPC_STATE_UNINIT = 0,         /*!< Uninitialized state. */
  PAL_IPC_STATE_ERROR  = 0,         /*!< Error state. */
  PAL_IPC_STATE_IDLE,               /*!< Initialized state. */
  PAL_IPC_STATE_BUSY                /*!< Busy state. */
} PalIpcState_t;

typedef void (*PalIpcMsgHandler_t)(const uint8_t *pBuf, uint16_t len);

/**************************************************************************************************
  Function Declarations
**************************************************************************************************/

/* Initialization */

/*************************************************************************************************/
/*!
 *  \brief      Initialize IPC.
 */
/*************************************************************************************************/
void PalIpcInit(void);

/*************************************************************************************************/
/*!
 *  \brief      De-Initialize IPC.
 */
/*************************************************************************************************/
void PalIpcDeInit(void);

/* Control and Status */

/*************************************************************************************************/
/*!
 *  \brief      Get the current state.
 *
 *  \return     Current state.
 *
 *  Return the current state of the IPC driver.
 */
/*************************************************************************************************/
PalIpcState_t PalIpcGetState(void);

/* Data Transfer */

/*************************************************************************************************/
/*!
 *  \brief      Write data over IPC.
 *
 *  \param      msgType IPC message type.
 *  \param      pData   Write buffer.
 *  \param      len     Number of bytes to write.
 */
/*************************************************************************************************/
void PalIpcWriteData(PalIpcType_t msgType, const uint8_t *pData, uint16_t len);

/*************************************************************************************************/
/*!
 *  \brief      Register receive message callback.
 *
 *  \param      msgType     IPC message type.
 *  \param      recvCback   Receive message callback.
 */
/*************************************************************************************************/
void PalIpcRegisterHandler(PalIpcType_t msgType, PalIpcMsgHandler_t recvCback);

/*! \} */    /* PAL_IPC */

#ifdef __cplusplus
};
#endif

#endif /* PAL_IPC_H */
