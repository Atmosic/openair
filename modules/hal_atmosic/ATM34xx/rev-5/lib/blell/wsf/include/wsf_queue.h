/*************************************************************************************************/
/*!
 *  \file   wsf_queue.h
 *
 *  \brief  General purpose queue service.
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
 *  if you do not have a copy of the Agreement, you must contact Packetcraft, Inc. prior
 *  to any use, copying or further distribution of this software.
 */
/*************************************************************************************************/
#ifndef WSF_QUEUE_H
#define WSF_QUEUE_H

#ifdef __cplusplus
extern "C" {
#endif

/*! \addtogroup WSF_QUEUE_API
 *  \{ */

/**************************************************************************************************
  Macros
**************************************************************************************************/

/*! \brief Initialize a queue */
#define WSF_QUEUE_INIT(pQueue)          {(pQueue)->pHead = NULL; (pQueue)->pTail = NULL;}

/**************************************************************************************************
  Data Types
**************************************************************************************************/

/*! \brief Queue structure */
typedef struct
{
  void      *pHead;         /*!< head of queue */
  void      *pTail;         /*!< tail of queue */
} wsfQueue_t;

/**************************************************************************************************
  Function Declarations
**************************************************************************************************/

/*************************************************************************************************/
/*!
 *  \brief  Enqueue an element to the tail of a queue.
 *
 *  \param  pQueue    Pointer to queue.
 *  \param  pElem     Pointer to element.
 */
/*************************************************************************************************/
void WsfQueueEnq(wsfQueue_t *pQueue, void *pElem);

/*************************************************************************************************/
/*!
 *  \brief  Dequeue an element from the head of a queue.
 *
 *  \param  pQueue    Pointer to queue.
 *
 *  \return Pointer to element that has been dequeued or NULL if queue is empty.
 */
/*************************************************************************************************/
void *WsfQueueDeq(wsfQueue_t *pQueue);

/*************************************************************************************************/
/*!
 *  \brief  Push an element to the head of a queue.
 *
 *  \param  pQueue    Pointer to queue.
 *  \param  pElem     Pointer to element.
 */
/*************************************************************************************************/
void WsfQueuePush(wsfQueue_t *pQueue, void *pElem);

/*************************************************************************************************/
/*!
 *  \brief  Insert an element into a queue.  This function is typically used when iterating
 *          over a queue.
 *
 *  \param  pQueue    Pointer to queue.
 *  \param  pElem     Pointer to element to be inserted.
 *  \param  pPrev     Pointer to previous element in the queue before element to be inserted.
 *                    Note:  set pPrev to NULL if pElem is first element in queue.
 *  \return None.
 */
/*************************************************************************************************/
void WsfQueueInsert(wsfQueue_t *pQueue, void *pElem, void *pPrev);

/*************************************************************************************************/
/*!
 *  \brief  Remove an element from a queue.  This function is typically used when iterating
 *          over a queue.
 *
 *  \param  pQueue    Pointer to queue.
 *  \param  pElem     Pointer to element to be removed.
 *  \param  pPrev     Pointer to previous element in the queue before element to be removed.
 */
/*************************************************************************************************/
void WsfQueueRemove(wsfQueue_t *pQueue, void *pElem, void *pPrev);

/*************************************************************************************************/
/*!
 *  \brief  Count the number of elements in a queue.
 *
 *  \param  pQueue    Pointer to queue.
 *
 *  \return Number of elements in queue.
 */
/*************************************************************************************************/
uint16_t WsfQueueCount(wsfQueue_t *pQueue);

/*************************************************************************************************/
/*!
 *  \brief  Return true if queue is empty.
 *
 *  \param  pQueue    Pointer to queue.
 *
 *  \return true if queue is empty, false otherwise.
 */
/*************************************************************************************************/
bool WsfQueueEmpty(wsfQueue_t *pQueue);

/*************************************************************************************************/
/*!
 *  \brief  Check for a queue depth of 1 element.
 *
 *  \param  pQueue      Queue.
 *
 *  \return true if Queue only has 1 element, false otherwise.
 */
/*************************************************************************************************/
bool WsfIsQueueDepthOne(wsfQueue_t *pQueue);

/*! \} */    /* WSF_QUEUE_API */

#ifdef __cplusplus
};
#endif

#endif /* WSF_QUEUE_H */
