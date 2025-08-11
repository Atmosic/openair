/*************************************************************************************************/
/*!
 *  \file   calc128.h
 *
 *  \brief  128-bit integer utilities.
 *
 *  Copyright (c) 2010-2018 Arm Ltd. All Rights Reserved.
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
#ifndef CALC128_H
#define CALC128_H

#include "wsf_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/*! \addtogroup WSF_UTIL_API
 *  \{ */

/**************************************************************************************************
  Macros
**************************************************************************************************/

/*! \brief 128-bit integer length in bytes */
#define CALC128_LEN                 16

/**************************************************************************************************
  Global Variables
**************************************************************************************************/

/*! \brief 128-bit zero value */
extern const uint8_t calc128Zeros[CALC128_LEN];

/**************************************************************************************************
  Function Declarations
**************************************************************************************************/

/*************************************************************************************************/
/*!
 *  \brief  Copy a 128-bit integer from source to destination.
 *
 *  \param  pDst    Pointer to destination.
 *  \param  pSrc    Pointer to source.
 */
/*************************************************************************************************/
void Calc128Cpy(uint8_t *pDst, uint8_t *pSrc);

/*************************************************************************************************/
/*!
 *  \brief  Copy a 64-bit integer from source to destination.
 *
 *  \param  pDst    Pointer to destination.
 *  \param  pSrc    Pointer to source.
 */
/*************************************************************************************************/
void Calc128Cpy64(uint8_t *pDst, uint8_t *pSrc);

/*************************************************************************************************/
/*!
 *  \brief  Exclusive-or two 128-bit integers and return the result in pDst.
 *
 *  \param  pDst    Pointer to destination.
 *  \param  pSrc    Pointer to source.
 */
/*************************************************************************************************/
void Calc128Xor(uint8_t *pDst, uint8_t *pSrc);

/*! \} */    /* WSF_UTIL_API */

#ifdef __cplusplus
};
#endif

#endif /* CALC128_H */
