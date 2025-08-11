/*************************************************************************************************/
/*!
 *  \file   wsf_msg.h
 *
 *  \brief  Message passing service.
 *
 *  Copyright (c) 2009-2018 Arm Ltd. All Rights Reserved.
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
#ifndef WSF_MSG_H
#define WSF_MSG_H

#include "wsf_queue.h"
#include "wsf_os.h"

#ifdef __cplusplus
extern "C" {
#endif

/*! \addtogroup WSF_MSG_API
 *  \{ */


/**************************************************************************************************
  Data Types
**************************************************************************************************/

extern const uint8_t WSF_MSG_HDR_SIZE;     /*!< TBD. */

/**************************************************************************************************
  Function Declarations
**************************************************************************************************/

/*************************************************************************************************/
/*!
 *  \brief  Allocate a data message buffer to be sent with WsfMsgSend().
 *
 *  \param  len       Message length in bytes.
 *  \param  tailroom  Tailroom length in bytes.
 *
 *  \return Pointer to data message buffer or NULL if allocation failed.
 */
/*************************************************************************************************/
void *WsfMsgDataAlloc(uint16_t len, uint8_t tailroom);

/*************************************************************************************************/
/*!
 *  \brief  Allocate a message buffer to be sent with WsfMsgSend().
 *
 *  \param  len   Message length in bytes.
 *
 *  \return Pointer to message buffer or NULL if allocation failed.
 */
/*************************************************************************************************/
void *WsfMsgAlloc(uint16_t len);

/*************************************************************************************************/
/*!
 *  \brief  Free a message buffer allocated with WsfMsgAlloc().
 *
 *  \param  pMsg  Pointer to message buffer.
 */
/*************************************************************************************************/
void WsfMsgFree(void *pMsg);

/*************************************************************************************************/
/*!
 *  \brief  Send a message to an event handler.
 *
 *  \param  handlerId   Event handler ID.
 *  \param  pMsg        Pointer to message buffer.
 */
/*************************************************************************************************/
void WsfMsgSend(wsfHandlerId_t handlerId, void *pMsg);

/*************************************************************************************************/
/*!
 *  \brief  Enqueue a message.
 *
 *  \param  pQueue     Pointer to queue.
 *  \param  handlerId  Set message handler ID to this value.
 *  \param  pMsg       Pointer to message buffer.
 */
/*************************************************************************************************/
void WsfMsgEnq(wsfQueue_t *pQueue, wsfHandlerId_t handlerId, void *pMsg);

/*************************************************************************************************/
/*!
 *  \brief  Dequeue a message.
 *
 *  \param  pQueue      Pointer to queue.
 *  \param  pHandlerId  Handler ID of returned message; this is a return parameter.
 *
 *  \return Pointer to message that has been dequeued or NULL if queue is empty.
 */
/*************************************************************************************************/
void *WsfMsgDeq(wsfQueue_t *pQueue, wsfHandlerId_t *pHandlerId);

/*************************************************************************************************/
/*!
 *  \brief  Get the next message without removing it from the queue.
 *
 *  \param  pQueue      Pointer to queue.
 *  \param  pHandlerId  Handler ID of returned message; this is a return parameter.
 *
 *  \return Pointer to the next message on the queue or NULL if queue is empty.
 */
/*************************************************************************************************/
void *WsfMsgPeek(wsfQueue_t *pQueue, wsfHandlerId_t *pHandlerId);

/*************************************************************************************************/
/*!
 *  \brief  Get the Nth message without removing it from the queue.
 *
 *  \param  pQueue      Pointer to queue.
 *  \param  n           Nth item from the top (0 = top element).
 *  \param  pHandlerId  Handler ID of returned message; this is a return parameter.
 *
 *  \return Pointer to the next message on the queue or NULL if queue is empty.
 */
/*************************************************************************************************/
void *WsfMsgNPeek(wsfQueue_t *pQueue, uint8_t n, wsfHandlerId_t *pHandlerId);

/*! \} */    /* WSF_MSG_API */

#ifdef __cplusplus
};
#endif

#endif /* WSF_MSG_H */
