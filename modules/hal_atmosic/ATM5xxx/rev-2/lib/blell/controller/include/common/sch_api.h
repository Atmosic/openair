/*************************************************************************************************/
/*!
 *  \file
 *
 *  \brief      Multi-protocol scheduler interface file.
 *
 *  Copyright (c) 2013-2019 ARM Ltd. All Rights Reserved.
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

#ifndef SCH_API_H
#define SCH_API_H

#include "wsf_types.h"
#include "wsf_os.h"
#include "bb_api.h"

#ifdef __cplusplus
extern "C" {
#endif

/**************************************************************************************************
  Macros
**************************************************************************************************/

/*! \brief      Maximum scheduler span between BODs. */
#define SCH_MAX_SPAN                    0x80000000

/**************************************************************************************************
  Data Types
**************************************************************************************************/

/*! \brief      Conflict action call signature. */
typedef BbOpDesc_t*(*BbConflictAct_t)(BbOpDesc_t *pNewBod, BbOpDesc_t *pExistBod);

/**************************************************************************************************
  Function Declarations
**************************************************************************************************/

/* Initialization */
void SchInit(void);
void SchHandlerInit(wsfHandlerId_t handlerId);
void SchReset(void);
uint16_t SchStatsGetHandlerWatermarkUsec(void);

/* Control */
void SchHandler(wsfEventMask_t event, wsfMsgHdr_t *pMsg);

/* List maintenance */
void SchInsertNextAvailable(BbOpDesc_t *pBod);
bool SchInsertAtDueTime(BbOpDesc_t *pBod, BbConflictAct_t conflictCback);
bool SchInsertEarlyAsPossible(BbOpDesc_t *pBod, uint32_t min, uint32_t max);
bool SchInsertLateAsPossible(BbOpDesc_t *pBod, uint32_t min, uint32_t max);
bool SchExecuteEarlyAsPossible(BbOpDesc_t *pBod, uint32_t expireUsec);
void SchRemove(BbOpDesc_t *pBod);
void SchReload(BbOpDesc_t *pBod);
bool SchIsBodCancellable(BbOpDesc_t *pBod);
bool SchGetNextDueTimeUsec(uint32_t *pNextTime);

#if (SCH_BG_BOD_ENABLE)
void SchInsertBackground(BbOpDesc_t *pBod);
void SchRemoveBackground(void);
#endif

#ifdef __cplusplus
};
#endif

#endif /* SCH_API_H */
