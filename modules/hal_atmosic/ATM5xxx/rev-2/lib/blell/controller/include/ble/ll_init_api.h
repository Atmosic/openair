/*************************************************************************************************/
/*!
 *  \file
 *
 *  \brief  LL initialization implementation file.
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
 *
 *
 *  Initialization conditional compilation are used to control LL initialization options.
 *  Define one or more of the following to enable roles and features.
 *
 *    - INIT_BROADCASTER (default)
 *    - INIT_OBSERVER
 *    - INIT_PERIPHERAL
 *    - INIT_CENTRAL
 *    - INIT_ENCRYPTED
 *    - BT_VER
 *
 *  \note   Each feature may require additional \ref LlRtCfg_t requirements.
 */
/*************************************************************************************************/

#ifndef LL_INIT_API_H
#define LL_INIT_API_H

#include "wsf_types.h"
#include "bb_api.h"
#include "ll_api.h"

#ifdef __cplusplus
extern "C" {
#endif

/*!
 *  \addtogroup LL_INIT_API
 *  \{
 */

/**************************************************************************************************
  Macros
**************************************************************************************************/

#ifndef BT_VER
/*! \brief  Initialize default BT version. */
#define BT_VER        LL_VER_BT_CORE_SPEC_6_0
#endif

/*! \brief  Initialize LL as capable of being a central. */
#define LL_FEATURE_INIT_CENTRAL (1 << 0)

/*! \brief  Initialize LL as capable of being a peripheral. */
#define LL_FEATURE_INIT_PERIPHERAL (1 << 1)

/*! \brief  Initialize LL as capable of being a broadcaster. */
#define LL_FEATURE_INIT_BROADCASTER (1 << 2)

/*! \brief  Initialize LL as capable of being an observer. */
#define LL_FEATURE_INIT_OBSERVER (1 << 3)

/*! \brief  Initialize LL with CS (Channel Sounding) support. */
#define LL_FEATURE_INIT_CS (1 << 4)

/*! \brief  Initialize LL with BIS (Broadcast Isochronous Stream) support. */
#define LL_FEATURE_INIT_BIS (1 << 5)

/*! \brief  Initialize LL with CIS (Connected Isochronous Stream) support. */
#define LL_FEATURE_INIT_CIS (1 << 6)

/*! \brief  Initialize LL with ISO (Isochronous) support. */
#define LL_FEATURE_INIT_ISO (1 << 7)

/*! \brief  Initialize LL with PAWR (Periodic Advertising with Responses) support. */
#define LL_FEATURE_INIT_PAWR (1 << 8)

/*! \brief  Initialize LL with EXTFEAT (Extended Features) support. */
#define LL_FEATURE_INIT_EXTFEAT (1 << 9)

/*! \brief  Initialize LL with DBAF (Decision Based Advertising Filtering) support. */
#define LL_FEATURE_INIT_DBAF (1 << 10)

/*! \brief  Initialize LL with MONADV (Monitored Advertisers) support. */
#define LL_FEATURE_INIT_MONADV (1 << 11)

/*! \brief  Initialize LL with all features enabled. */
#define LL_FEATURE_INIT_ALL (LL_FEATURE_INIT_CENTRAL | LL_FEATURE_INIT_PERIPHERAL \
  | LL_FEATURE_INIT_BROADCASTER | LL_FEATURE_INIT_OBSERVER | LL_FEATURE_INIT_CS \
  | LL_FEATURE_INIT_BIS | LL_FEATURE_INIT_CIS | LL_FEATURE_INIT_ISO | LL_FEATURE_INIT_PAWR \
  | LL_FEATURE_INIT_EXTFEAT | LL_FEATURE_INIT_DBAF | LL_FEATURE_INIT_MONADV)

/*! \brief Check that all of the feature bits in mask are set in featureEn */
#define LL_FEAT_ALL(featureEn, mask) (((featureEn) & (mask)) == (mask))

/**************************************************************************************************
  Data Types
**************************************************************************************************/

/*! \brief      Runtime configuration parameters. */
typedef struct
{
  const BbRtCfg_t   *pBbRtCfg;      /*!< BB runtime configuration. */
  const uint8_t     wlSizeCfg;      /*!< Whitelist size configuration. */
  const uint8_t     rlSizeCfg;      /*!< Resolving list size configuration. */
  const uint8_t     plSizeCfg;      /*!< Periodic list size configuration. */
  const LlRtCfg_t   *pLlRtCfg;      /*!< LL runtime configuration. */
  uint8_t           *pFreeMem;      /*!< Pointer to free memory, returns adjusted location of free memory. */
  uint32_t          freeMemAvail;   /*!< Amount of free memory available, returns adjusted amount of free memory. */
  uint32_t          featureEn;      /*!< Which feature to enable. Set to 0xFFFFFFFF if using build define enables. */
} LlInitRtCfg_t;

/**************************************************************************************************
  Functions Declarations
**************************************************************************************************/

/* System initializers. */
uint32_t LlInit(LlInitRtCfg_t *pCfg);
uint32_t LlInitControllerInit(LlInitRtCfg_t *pCfg);

/* Intermediate initializers. */
uint32_t LlInitSetBbRtCfg(const BbRtCfg_t *pBbRtCfg, const uint8_t wlSizeCfg, const uint8_t rlSizeCfg,
                          const uint8_t plSizeCfg, uint8_t *pFreeMem, uint32_t freeMemAvail,
                          uint32_t featureEn);
uint32_t LlInitSetLlRtCfg(const LlRtCfg_t *pLlRtCfg, uint8_t *pFreeMem, uint32_t freeMemAvail,
                          uint32_t featureEn);
uint32_t LlInitBbInit(uint8_t *pFreeMem, uint32_t freeMemAvail, uint32_t featureEn);
uint32_t LlInitSchInit(uint8_t *pFreeMem, uint32_t freeMemAvail);
uint32_t LlInitLlInit(uint8_t *pFreeMem, uint32_t freeMemAvail, uint32_t featureEn);
void LlInitChciTrInit(uint16_t maxAclLen, uint16_t maxIsoLen);
void LlInitLhciInit(uint32_t featureEn);
void LlInitLhciHandler(void);

/*! \} */    /* LL_INIT_API */

#ifdef __cplusplus
};
#endif

#endif /* LL_INIT_API_H */
