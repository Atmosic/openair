/*************************************************************************************************/
/*!
 *  \file
 *
 *  \brief      Channel sounding interface file.
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

#ifndef CS_API_H
#define CS_API_H

#include "wsf_types.h"

#ifdef __cplusplus
extern "C" {
#endif

#define LL_MAX_CS                 1

enum
{
  CS_MODE_1 = 1,
  CS_MODE_2 = 2,
  CS_MODE_3 = 3,
  CS_MODE_NONE = 0xFF
};

/**************************************************************************************************
  Function Declarations
**************************************************************************************************/

/*************************************************************************************************/
/*!
 *  \brief     Read CS local supported capabilities
 *
 *  \param     pCsSupCap           Supported capabilities.
 *
 *  \return    Status error code.
 */
/*************************************************************************************************/
uint8_t LlCsReadLocalSupCap(LlCsSupParams_t *pCsSupCap);

/*************************************************************************************************/
/*!
 *  \brief     Read remote supported capabilities
 *
 *  \param     connHandle        Connection handle.
 *
 *  \return    Status error code.
 */
/*************************************************************************************************/
uint8_t LlCsReadRemoteSupCap(uint16_t connHandle);

/*************************************************************************************************/
/*!
 *  \brief     Write CS cached remote supported capabilities
 *
 *  \param     connHandle        Connection handle.
 *  \param     pCsSupCap           Supported capabilities.
 *
 *  \return    Status error code.
 */
/*************************************************************************************************/
uint8_t LlCsWriteCachRemoteSupCap(uint16_t connHandle, LlCsSupParams_t *pCsSupCap);

/*************************************************************************************************/
/*!
 *  \brief     CS enable security procedure.
 *
 *  \param     connHandle        Connection handle.
 *
 *  \return    Status error code.
 */
/*************************************************************************************************/
uint8_t LlCsSecurityEnable(uint16_t connHandle);

/*************************************************************************************************/
/*!
 *  \brief     Set default CS settings.
 *
 *  \param     connHandle               Connection handle.
 *  \param     roleEnable               Initiator role enabled.
 *  \param     csSyncAntennaSelection   CS Sync antena selection
 *  \param     maxTxPow                 Max transmission power.
 *
 *  \return    Status error code.
 */
/*************************************************************************************************/
uint8_t LlCsSetDefaultSettings(uint16_t connHandle, uint8_t roleEnable, uint8_t csSyncAntennaSelection, uint8_t maxTxPow);

/*************************************************************************************************/
/*!
 *  \brief     Read remote FAE table.
 *
 *  \param     connHandle        Connection handle.
 *
 *  \return    Status error code.
 */
/*************************************************************************************************/
uint8_t LlCsReadRemoteFaeTbl(uint16_t connHandle);

/*************************************************************************************************/
/*!
 *  \brief     Write CS cached remote FAE table.
 *
 *  \param     connHandle        Connection handle.
 *  \param     pRemFaeTbl        Remote FAE table.
 *
 *  \return    Status error code.
 */
/*************************************************************************************************/
uint8_t LlCsWriteCachRemoteFaeTbl(uint16_t connHandle, uint8_t *pRemFaeTbl);

/*************************************************************************************************/
/*!
 *  \brief     Create CS configuration.
 *
 *  \param     connHandle        Connection handle.
 *  \param     pCsCfg            CS configuration.
 *
 *  \return    Status error code.
 */
/*************************************************************************************************/
uint8_t LlCsCreateConfig(uint16_t connHandle, LlCsCreateCfg_t *pCsCfg);

/*************************************************************************************************/
/*!
 *  \brief     Remove CS configuration.
 *
 *  \param     connHandle        Connection handle.
 *  \param     configId          Configuration identifier.
 *
 *  \return    Status error code.
 */
/*************************************************************************************************/
uint8_t LlCsRemoveConfig(uint16_t connHandle, uint8_t configId);

/*************************************************************************************************/
/*!
 *  \brief     Set CS channel classification.
 *
 *  \param     pChanClass        Channel classification.
 *
 *  \return    Status error code.
 */
/*************************************************************************************************/
uint8_t LlCsSetChanClass(uint8_t *pChanClass);

/*************************************************************************************************/
/*!
 *  \brief     Set CS procedure parameters
 *
 *  \param     connHandle        Connection handle.
 *  \param     pProcCfg          Procedure parameters configuration to be set.
 *
 *  \return    Status error code.
 */
/*************************************************************************************************/
uint8_t LlCsSetProcedureParams(uint16_t connHandle, LlCsProcParams_t *pProcCfg);

/*************************************************************************************************/
/*!
 *  \brief     Set CS procedure enable
 *
 *  \param     connHandle        Connection handle.
 *  \param     configId          Configuration identifier.
 *  \param     enable            Enable/Disable
 *
 *  \return    Status error code.
 */
/*************************************************************************************************/
uint8_t LlCsProcedureEn(uint16_t connHandle, uint8_t configId, uint8_t enable);

/*************************************************************************************************/
/*!
 *  \brief     CS Test
 *
 *  \param     pCsTestCfg        CS test configuration.
 *
 *  \return    Status error code.
 */
/*************************************************************************************************/
uint8_t LlCsTest(LlCsTest_t *pCsTestCfg);

/*************************************************************************************************/
/*!
 *  \brief     CS Test end
 *
 *  \return    Status error code.
 */
/*************************************************************************************************/
uint8_t LlCsTestEnd(void);

/*************************************************************************************************/
/*!
 *  \brief      Initialize LL subsystem for operation for peripheral channel sounding.
 *
 *  This function initializes the LL subsystem for peripheral channel sounding.
 */
/*************************************************************************************************/
void LlCsPeripheralInit(void);

/*************************************************************************************************/
/*!
 *  \brief      Initialize LL subsystem for operation for central channel sounding.
 *
 *  This function initializes the LL subsystem for central channel sounding.
 */
/*************************************************************************************************/
void LlCsCentralInit(void);

/*************************************************************************************************/
/*!
 *  \brief  Initialize channel sounding memory resources.
 *
 *  \param  pFreeMem    Pointer to free memory.
 *  \param  freeMemSize Size of pFreeMem.
 *
 *  \return Amount of free memory consumed.
 */
/*************************************************************************************************/
uint32_t LctrInitCsMem(uint8_t *pFreeMem, uint32_t freeMemSize);

/*************************************************************************************************/
/*!
 *  \brief      Initialize memory for CS.
 *
 *  \param      pFreeMem        Pointer to free memory.
 *  \param      freeMemSize     Size of pFreeMem.
 *
 *  \return     Amount of free memory consumed.
 *
 *  This function allocates memory for CS
 *
 *  \note       This routine must be called after LlInitRunTimeCfg() but only once before any
 *              other initialization routines.
 */
/*************************************************************************************************/
uint32_t LlInitCsMem(uint8_t *pFreeMem, uint32_t freeMemSize);

#ifdef __cplusplus
};
#endif

#endif /* CS_API_H */
