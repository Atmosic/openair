/*************************************************************************************************/
/*!
 *  \file   wsf_nvm.h
 *
 *  \brief  NVM service.
 *
 *  Copyright (c) 2019 Arm Ltd. All Rights Reserved.
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
#ifndef WSF_NVM_H
#define WSF_NVM_H

#ifdef __cplusplus
extern "C" {
#endif

/*! \addtogroup WSF_NVM_API
 *  \{ */

/*! \brief      Operation completion callback. */
typedef void (*WsfNvmCompEvent_t)(bool status);

/**************************************************************************************************
  Function Declarations
**************************************************************************************************/

/*************************************************************************************************/
/*!
 *  \brief  Read data.
 *
 *  \param  charId         charactor arrary for NVM ID.
 *
 *  \return if Read NVM successfully.
 */
/*************************************************************************************************/
static inline uint64_t WsfNvmConvertChar8to64Bit(char *charId)
{
  uint64_t retValue = 0;

  for (uint8_t i = 0; i < 8; i++)
  {
    retValue |= ((uint64_t)charId[7 - i]) << (8*i);
  }
  return retValue;
}

/*************************************************************************************************/
/*!
 *  \brief  Initialize the WSF NVM.
 */
/*************************************************************************************************/
void WsfNvmInit(void);

/*************************************************************************************************/
/*!
 *  \brief  Read data.
 *
 *  \param  id         Read ID.
 *  \param  pData      Buffer to read to.
 *  \param  len        Data length to read.
 *  \param  compCback  Read callback.
 *
 *  \return true if NVM operation is successful, false otherwise.
 */
/*************************************************************************************************/
bool WsfNvmReadData(uint64_t id, uint8_t *pData, uint16_t len, WsfNvmCompEvent_t compCback);

/*************************************************************************************************/
/*!
 *  \brief  Write data.
 *
 *  \param  id         Write ID.
 *  \param  pData      Buffer to write.
 *  \param  len        Data length to write.
 *  \param  compCback  Write callback.
 *
 *  \return true if NVM operation is successful, false otherwise.
 */
/*************************************************************************************************/
bool WsfNvmWriteData(uint64_t id, const uint8_t *pData, uint16_t len, WsfNvmCompEvent_t compCback);

/*************************************************************************************************/
/*!
 *  \brief  Erase data.
 *
 *  \param  id         Erase ID.
 *  \param  compCback  Write callback.
 *
 *  \return true if NVM operation is successful, false otherwise.
 */
/*************************************************************************************************/
bool WsfNvmEraseData(uint64_t id, WsfNvmCompEvent_t compCback);

/*************************************************************************************************/
/*!
 *  \brief  Erase all data located in NVM storage.
 *
 *  \param  compCback          Erase callback.
 *
 *  \note   Security Risk Warning. NVM storage could be shared by multiple Apps.
 */
/*************************************************************************************************/
void WsfNvmEraseDataAll(WsfNvmCompEvent_t compCback);

/*! \} */    /* WSF_NVM_API */

#ifdef __cplusplus
};
#endif

#endif /* WSF_NVM_H */
