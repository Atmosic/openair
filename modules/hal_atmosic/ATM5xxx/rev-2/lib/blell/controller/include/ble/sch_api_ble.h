/*************************************************************************************************/
/*!
 *  \file
 *
 *  \brief      Link layer scheduler interface file.
 *
 *  Copyright (c) 2013-2019 Arm Ltd. All Rights Reserved.
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

#ifndef SCH_API_BLE_H
#define SCH_API_BLE_H

#include "wsf_types.h"
#include "bb_api.h"
#include "cfg_mac_ble.h"

#ifdef __cplusplus
extern "C" {
#endif

/**************************************************************************************************
  Macros
**************************************************************************************************/

/*! \brief      Preferred periodicity for connections. */
#define SCH_RM_PREF_PER_CONN_USEC   (SCH_RM_PREF_PER_USEC)

/*! \brief      Preferred periodicity for periodic sync. */
#define SCH_RM_PREF_PER_SYNC_USEC   (SCH_RM_PREF_PER_USEC * 4)

#define SCH_DUE_TIME_GREATER_EQUAL(dueTimeA, dueTimeB) \
        ((uint32_t)((dueTimeA) - (dueTimeB)) < (uint32_t)(0x7FFFFFFF))
/**************************************************************************************************
  Constants
**************************************************************************************************/

/*! \brief      Resource manager preference for setting interval. */
enum
{
  SCH_RM_PREF_PERFORMANCE,            /*!< Performance is preferred, search from minimum interval. */
  SCH_RM_PREF_CAPACITY                /*!< Capacity is preferred, search from maximum interval. */
};

/*! \brief      Resource manager options for offset placement. */
enum
{
  SCH_RM_WINDOW_MIDDLE,          /*!< Place offset in the middle of largest window. */
  SCH_RM_WINDOW_BEGIN,           /*!< Place offset in the beginning of largest window. */
  SCH_RM_WINDOW_END,             /*!< Place offset in the end of largest window. */
  SCH_RM_ADJACENT,               /*!< Place offset adjacent to the specified BOD. */
  SCH_RM_PRECALCULATED,          /*!< Place offset in precalculated offset index. */
};

/**************************************************************************************************
  Data Types
**************************************************************************************************/

/*! \brief      Get reference time callback signature. */
typedef uint32_t (*GetRefTimeCb_t)(uint8_t handle, uint32_t *pDurUsec);

/*! \brief      Get topology reference time callback signature. */
typedef uint32_t (*GetTopRefTimeCb_t)(uint8_t handle);

/**************************************************************************************************
  Function Declarations
**************************************************************************************************/

/* Resource manager */
uint32_t SchRmInit(uint8_t *pFreeMem, uint32_t freeMemAvail);
void SchRmReset(void);
uint32_t SchRmCalcCommonPeriodicityUsec(uint32_t peerPerUsec);
bool SchRmAdd(uint8_t handle, uint8_t pref, uint32_t minUsec, uint32_t maxUsec, uint32_t durUsec, uint32_t *pInterUsec, GetRefTimeCb_t refTimeCb);
bool SchRmStartUpdate(uint8_t handle, uint32_t minUsec, uint32_t maxUsec, uint32_t perfPerUsec, uint32_t durUsec, uint32_t *pInterUsec);
void SchRmRemove(uint8_t handle);
uint32_t SchRmGetOffsetUsec(uint32_t maxOffsUsec, uint8_t handle, uint32_t refTime, BbOpDesc_t * pAdjBod, uint8_t mode);
uint32_t SchRmGetSlotSizeUsec(void);
void SchRmUpdateBaseInterval(uint16_t interval);
void SchRmPreCalOffset(uint8_t handle);

/* BLE time utilities */
uint32_t SchBleCalcDataPktDurationUsec(uint8_t phy, uint16_t len);
uint32_t SchBleCalcAdvPktDurationUsec(uint8_t phy, uint8_t phyOptions, uint16_t len);
uint32_t SchBleCalcScanBackoffDurationUsec(uint8_t phy);
uint32_t SchBleCalcPerAdvDurationUsec(uint8_t txPhy, uint8_t fragLen, uint32_t cteTimeUsec, uint16_t addMafDelay, uint16_t len, bool worstCase, uint8_t phyOptions, uint8_t pawrHdrLen);
uint32_t SchBleCalcAuxPktDurationUsec(uint8_t phy, uint8_t phyOptions, uint16_t len);
void SchBleCalcAdvOpDuration(BbOpDesc_t *pBod, uint8_t fragLen);
bool SchBleGetNextMstConnDueTime(uint32_t *pDueTime);
uint32_t SchBleGetAlignedAuxOffsUsec(uint32_t auxOffsUsec);

#ifdef __cplusplus
};
#endif

#endif /* SCH_API_BLE_H */
