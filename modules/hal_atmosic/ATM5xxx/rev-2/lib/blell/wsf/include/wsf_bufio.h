/*************************************************************************************************/
/*!
 *  \file   wsf_bufio.h
 *
 *  \brief  Buffer I/O service.
 *
 *  Copyright (c) 2009-2018 Arm Ltd. All Rights Reserved.
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
#ifndef WSF_BUF_IO_H
#define WSF_BUF_IO_H

#ifdef __cplusplus
extern "C" {
#endif

/*! \addtogroup WSF_BUF_IO_API
 *  \{ */


/**************************************************************************************************
  Macros
**************************************************************************************************/

/**************************************************************************************************
  Data Types
**************************************************************************************************/

/**************************************************************************************************
  Callback Function Datatypes
**************************************************************************************************/

/*! \brief    Buffer IO UART Rx callback. */
typedef void (*WsfBufIoUartRxCback_t)(uint8_t rxByte);

/**************************************************************************************************
  Function Declarations
**************************************************************************************************/

/*************************************************************************************************/
/*!
 *  \brief  Initialize the platform UART.
 *
 *  \param  pBuf    Tx Buffer pointer.
 *  \param  size    Length of buffer.
 *  \param  baud    UART baud rate
 *  \param  hwFlow  Use UART HW Flow control
 *
 *  \return memory used.
 */
/*************************************************************************************************/
uint32_t WsfBufIoUartInit(void *pBuf, uint32_t size, uint32_t baud, bool hwFlow);

/*************************************************************************************************/
/*!
 *  \brief     Register the platform UART RX callback.
 *
 *  \param     rxCback  Callback function for UART RX.
 */
/*************************************************************************************************/
void WsfBufIoUartRegister(WsfBufIoUartRxCback_t rxCback);

#ifdef WSF_BUFIO_IDLE
/*************************************************************************************************/
/*!
 *  \brief Service platform UART. Transmit any buffered TX data
 *
 *  \return if any buffered data
 */
/*************************************************************************************************/
bool WsfBufIoUartService(void);
#endif

/*************************************************************************************************/
/*!
 *  \brief  Transmit buffer on platform UART.
 *
 *  \param  pBuf    Buffer to transmit.
 *  \param  len     Length of buffer in octets.
 * 
 *  \return if write successfully.
 */
/*************************************************************************************************/
bool WsfBufIoWrite(const      uint8_t *pBuf, uint32_t len);

/*! \} */    /* WSF_BUF_IO_API */

#ifdef __cplusplus
};
#endif

#endif /* WSF_BUF_IO_H */
