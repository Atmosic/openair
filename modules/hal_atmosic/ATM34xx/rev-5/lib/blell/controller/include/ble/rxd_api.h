/*************************************************************************************************/
/*!
 *  \file
 *
 *  \brief      Receiver diversity interface file.
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

#ifndef RXD_API_H
#define RXD_API_H

#include "wsf_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/**************************************************************************************************
  Function Declarations
**************************************************************************************************/

/*************************************************************************************************/
/*!
 *  \brief      Enable/disable BIS antenna selection.
 *
 *  \param      bisHandle       BIS handle.
 *  \param      enable          Enable/disable BIS antenna selection.
 *  \param      intervalMs      Antenna selection interval.
 *  \param      threshold       Antenna selection threshold.
 *
 *  \return     Status error code.
 */
/*************************************************************************************************/
uint8_t RxdSetBisEnable(uint16_t bisHandle, bool enable, uint16_t intervalMs, uint8_t threshold);

/*************************************************************************************************/
/*!
 *  \brief      Set BIS antenna selection interval.
 *
 *  \param      bisHandle       BIS handle.
 *  \param      intervalMs      Antenna selection interval.
 *
 *  \return     Status error code.
 */
/*************************************************************************************************/
uint8_t RxdSetBisInterval(uint16_t bisHandle, uint16_t intervalMs);

/*************************************************************************************************/
/*!
 *  \brief      Set BIS antenna selection threshold.
 *
 *  \param      bisHandle          BIS handle.
 *  \param      threshold          Antenna selection threshold.
 *
 *  \return     Status error code.
 */
/*************************************************************************************************/
uint8_t RxdSetBisThreshold(uint16_t bisHandle, uint8_t threshold);

/*************************************************************************************************/
/*!
 *  \brief      Get primary antenna ID.
 *
 *  \param      rssi   Buffer to read RSSI for all antennas.
 *
 *  \return     Primary antenna ID.
 */
/*************************************************************************************************/
uint8_t RxdGetAntId(int8_t rssi[BB_MAX_ANT]);

/*************************************************************************************************/
/*!
 *  \brief      Get the current average RSSI value for all antennas and the current selected primary antenna for BIS.
 *
 *  \param      bisHandle          BIS handle.
 *  \param      pRssi              RSSI values.
 *  \param      pPriAnt            Primary antenna.
 *
 *  \return     Status error code.
 */
/*************************************************************************************************/
uint8_t RxdGetBisStatus(uint16_t bisHandle, uint8_t *pRssi, uint8_t *pPriAnt);

/*************************************************************************************************/
/*!
 *  \brief      Initialize BIS receiver diversity.
 */
/*************************************************************************************************/
void RxdBisInit(void);

/*************************************************************************************************/
/*!
 *  \brief      Enable/disable ACL antenna selection.
 *
 *  \param      aclHandle       ACL handle.
 *  \param      enable          Enable/disable ACL antenna selection.
 *  \param      intervalMs      Antenna selection interval.
 *  \param      threshold       Antenna selection threshold.
 *
 *  \return     Status error code.
 */
/*************************************************************************************************/
uint8_t RxdSetAclEnable(uint16_t aclHandle, bool enable, uint16_t intervalMs, uint8_t threshold);

/*************************************************************************************************/
/*!
 *  \brief      Set ACL antenna selection interval.
 *
 *  \param      aclHandle       ACL handle.
 *  \param      intervalMs      Antenna selection interval.
 *
 *  \return     Status error code.
 */
/*************************************************************************************************/
uint8_t RxdSetAclInterval(uint16_t aclHandle, uint16_t intervalMs);

/*************************************************************************************************/
/*!
 *  \brief      Set ACL antenna selection threshold.
 *
 *  \param      aclHandle          ACL handle.
 *  \param      threshold          Antenna selection threshold.
 *
 *  \return     Status error code.
 */
/*************************************************************************************************/
uint8_t RxdSetAclThreshold(uint16_t aclHandle, uint8_t threshold);

/*************************************************************************************************/
/*!
 *  \brief      Get the current average RSSI value for all antennas and the current selected primary antenna for ACL.
 *
 *  \param      aclHandle          ACL handle.
 *  \param      pRssi              RSSI values.
 *  \param      pPriAnt            Primary antenna.
 *
 *  \return     Status error code.
 */
/*************************************************************************************************/
uint8_t RxdGetAclStatus(uint16_t aclHandle, int8_t *pRssi, uint8_t *pPriAnt);

/*************************************************************************************************/
/*!
 *  \brief      Initialize ACL receiver diversity.
 */
/*************************************************************************************************/
void RxdAclInit(void);

#ifdef __cplusplus
};
#endif

#endif /* AFH_API_H */
