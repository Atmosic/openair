/*************************************************************************************************/
/*!
 *  \file   ga.h
 *
 *  \brief  Generic Audio (GA) utilities
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

#ifndef GA_H
#define GA_H

#include "wsf_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/*************************************************************************************************/
/*!
 *  \brief  Find a codec specific configuration data element in the given codec specific
 *          configuration data.
 *
 *  \param  cfgType Configuration data element type to find.
 *  \param  len     Length of configuration data.
 *  \param  pValue  Pointer to configuration data value.
 *
 *  \return Pointer to configuration data element byte array or NULL if not found.
 */
/*************************************************************************************************/
uint8_t *GaFindCfgType(uint8_t cfgType, uint16_t len, uint8_t *pValue);

/*************************************************************************************************/
/*!
 *  \brief  Set the value of a configuration data element in the given configuration data. The
 *          element is appended to the configuration data, space permitting.
 *
 *  \param  cfgType   Configuration data element type.
 *  \param  len       Length of the value.
 *  \param  pValue    Pointer to the value.
 *  \param  pCfgLen   Configuration data length.  The new length is returned in this parameter.
 *  \param  pCfg      Pointer to configuration data.
 *  \param  cfgBufLen Maximum length of the configuration data buffer maintained by caller.
 *
 *  \return true if the element was successfully added to the data, false otherwise.
 */
/*************************************************************************************************/
bool GaSetCfgValue(uint8_t cfgType, uint8_t len, uint8_t *pValue, uint8_t *pCfgLen, uint8_t *pCfg,
                   uint16_t cfgBufLen);

#ifdef __cplusplus
};
#endif

#endif /* GA_H */
