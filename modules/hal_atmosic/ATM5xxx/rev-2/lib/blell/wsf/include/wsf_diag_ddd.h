/*************************************************************************************************/
/*!
 *  \file   wsf_diag_ddd.h
 *
 *  \brief  Diagnostics.
 *
 *  Copyright (c) 2019-2023 Packetcraft, Inc.  All rights reserved.
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

#ifndef WSF_DIAG_DDD_H
#define WSF_DIAG_DDD_H

#ifdef __cplusplus
extern "C" {
#endif

/**************************************************************************************************
  Data Types
**************************************************************************************************/

/*! \brief      Diagnostics types. Must match definition in format_ddd.py. */
typedef enum
{
  /* Diagnostics markers */
  WSF_DIAG_INFO_TYPE_TIMESTAMP      = 0x0000,
  WSF_DIAG_INFO_TYPE_START          = 0x0010,
  /* System types */
  WSF_DIAG_INFO_TYPE_SYS_STATS      = 0x0010,
  WSF_DIAG_INFO_TYPE_POOL_STATS     = 0x0011,
  /* LL types */
  WSF_DIAG_INFO_TYPE_LL_RSSI        = 0x0020,
  WSF_DIAG_INFO_TYPE_LL_ISO_STATS   = 0x0021,
  /* Link Robustness types */
  WSF_DIAG_INFO_TYPE_LR_EDS         = 0x0030,
  /* End marker */
  WSF_DIAG_INFO_TYPE_TOTAL
} WsfDiagInfoType_t;

/*! \brief    Diagnostic information handler call signature. */
typedef uint16_t (*WsfDiagInfoHandler_t)(uint8_t * pBuf);

/**************************************************************************************************
  Function Declarations
**************************************************************************************************/

/*************************************************************************************************/
/*!
 *  \brief  Initialize diagnostics for flash storage.
 */
/*************************************************************************************************/
void WsfDiagInitFlashStore(void);

/*************************************************************************************************/
/*!
 *  \brief  Register diagnostics info retrieval callback.
 */
/*************************************************************************************************/
void WsfDiagRegisterHandler(WsfDiagInfoType_t info, WsfDiagInfoHandler_t cback);

/*************************************************************************************************/
/*!
 *  \brief  Gets system diagnostics info.
 *
 *  \param  pbuf      Buffer to contain system info.
 *
 *  \return Amount of bytes stored.
 */
/*************************************************************************************************/
uint16_t WsfDiagBuildDiagInfo(uint8_t *pBuf);

/*************************************************************************************************/
/*!
 *  \brief  Retrieve and build current time.
 *
 *  \param  pBuf         Buffer to contain time.
 *
 *  \return Length of object.
 */
/*************************************************************************************************/
uint16_t WsfDiagBuildTimestamp(uint8_t *pBuf);

/*************************************************************************************************/
/*!
 *  \brief  Retrieve and build system statistics object.
 *
 *  \param  pBuf         Buffer to contain stats.
 *
 *  \return Length of object.
 */
/*************************************************************************************************/
uint16_t WsfDiagBuildSysStatsHandler(uint8_t *pBuf);

/*************************************************************************************************/
/*!
 *  \brief  Retrieve and build pool statistics object.
 *
 *  \param  pBuf         Buffer to contain stats.
 *
 *  \return Length of object.
 */
/*************************************************************************************************/
uint16_t WsfDiagBuildPoolStatsHandler(uint8_t *pBuf);

#ifdef __cplusplus
};
#endif

#endif /* WSF_DIAG_DDD_H */
