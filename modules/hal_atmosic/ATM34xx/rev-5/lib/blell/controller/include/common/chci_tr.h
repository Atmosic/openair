/*************************************************************************************************/
/*!
 *  \file
 *
 *  \brief  Controller HCI transport interface file.
 *
 *  Copyright (c) 2013-2019 ARM Ltd. All Rights Reserved.
 *
 *  Copyright (c) 2019-2020 Packetcraft, Inc.  All rights reserved.
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

#ifndef CHCI_TR_H
#define CHCI_TR_H

#include "wsf_types.h"
#include "wsf_os.h"

#ifdef __cplusplus
extern "C" {
#endif

/**************************************************************************************************
  Macros
**************************************************************************************************/

#ifndef UART_BAUD
/*! \brief  Default UART baud rate. */
#define UART_BAUD   1000000
#endif

#ifndef UART_HWFC
/*! \brief  Default Hardware Flow Control. */
#define UART_HWFC    1
#endif

/**************************************************************************************************
  Function Declarations
**************************************************************************************************/

/*************************************************************************************************/
/*!
 *  \brief  Signal the completion of a message receive.
 *
 *  \param  prot    Protocol.
 *  \param  type    Message type.
 *  \param  pBuf    Message.
 */
/*************************************************************************************************/
void chciTrRecv(uint8_t prot, uint8_t type, uint8_t *pBuf);

/*************************************************************************************************/
/*!
 *  \brief  Signal the completion of a message transmission.
 */
/*************************************************************************************************/
void chciTrSendComplete(void);

#ifdef __cplusplus
};
#endif

#endif /* CHCI_TR_H */
