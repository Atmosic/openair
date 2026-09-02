/*************************************************************************************************/
/*!
 *  \file
 *
 *  \brief      UART driver definition.
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
 *  if you do not have a copy of the Agreement, you must contact Atmosic, Inc. prior
 *  to any use, copying or further distribution of this software.
 */
/*************************************************************************************************/

#ifndef PAL_UART_H
#define PAL_UART_H

#include "pal_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/*! \addtogroup PAL_UART
 *  \{ */

/**************************************************************************************************
  Data Types
**************************************************************************************************/

/*! \brief      Completion callback. */
typedef void (*PalUartCompCback_t)(void);

/*! \brief      Peripheral configuration. */
typedef struct
{
  PalUartCompCback_t rdCback;   /*!< Read data completion callback. */
  PalUartCompCback_t wrCback;   /*!< Write data completion callback. */
  uint32_t baud;                /*!< Baud rate. */
  bool hwFlow;                /*!< Use HW Flow control */
} PalUartConfig_t;

/*! \brief      Operational states. */
typedef enum
{
  PAL_UART_STATE_UNINIT = 0,    /*!< Uninitialized state. */
  PAL_UART_STATE_ERROR  = 0,    /*!< Error state. */
  PAL_UART_STATE_READY  = 1,    /*!< Ready state. */
  PAL_UART_STATE_BUSY   = 2,    /*!< Busy state. */
} PalUartState_t;

/*! \brief      Reserved UART ID. */
typedef enum
{
  PAL_UART_ID_USER      = 0,    /*!< UART instance for application. */
  PAL_UART_ID_CHCI      = 1,    /*!< UART instance for HCI transport. */
  PAL_UART_ID_TERMINAL  = 2,    /*!< UART instance for terminal. */
  PAL_UART_ID_TOKEN     = 3,    /*!< UART instance for token diagnostics. */
  PAL_UART_ID_MAX               /*!< Number of UART instances. */
} PalUartId_t;

/**************************************************************************************************
  Function Declarations
**************************************************************************************************/

/* Initialization */

/*************************************************************************************************/
/*!
 *  \brief      Initialize UART.
 *
 *  \param      id      UART ID.
 *  \param      pCfg    Peripheral configuration.
 */
/*************************************************************************************************/
void PalUartInit(PalUartId_t id, const PalUartConfig_t *pCfg);

/*************************************************************************************************/
/*!
 *  \brief      De-Initialize UART.
 *
 *  \param      id      UART ID.
 */
/*************************************************************************************************/
void PalUartDeInit(PalUartId_t id);

/* Control and Status */

/*************************************************************************************************/
/*!
 *  \brief      Get the current state.
 *
 *  \param      id      UART ID.
 *
 *  \return     Current state.
 */
/*************************************************************************************************/
PalUartState_t PalUartGetState(PalUartId_t id);

/* Data Transfer */

/*************************************************************************************************/
/*!
 *  \brief      Read data from Rx FIFO.
 *
 *  \param      id      UART ID.
 *  \param      pData   Read buffer.
 *  \param      len     Number of bytes to read.
 */
/*************************************************************************************************/
void PalUartReadData(PalUartId_t id, uint8_t *pData, uint16_t len);

/*************************************************************************************************/
/*!
 *  \brief      Write data to Tx FIFO.
 *
 *  \param      id      UART ID.
 *  \param      pData   Write buffer.
 *  \param      len     Number of bytes to write.
 */
/*************************************************************************************************/
void PalUartWriteData(PalUartId_t id, const uint8_t *pData, uint16_t len);

/*! \} */    /* PAL_UART */

#ifdef __cplusplus
};
#endif

#endif /* PAL_UART_H */
