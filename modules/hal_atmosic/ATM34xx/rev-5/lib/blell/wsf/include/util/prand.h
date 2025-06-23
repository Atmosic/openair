/*************************************************************************************************/
/*!
 *  \file
 *
 *  \brief  Pseudo-random number generator interface.
 *
 *  Copyright (c) 2016-2018 Arm Ltd. All Rights Reserved.
 *  ARM confidential and proprietary.
 *
 *  Copyright (c) 2019-2022 Packetcraft, Inc.  All rights reserved.
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

#ifndef PRAND_H
#define PRAND_H

#include "wsf_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/**************************************************************************************************
  Functions
**************************************************************************************************/

/*************************************************************************************************/
/*!
 *  \brief      Initialize random number generator.
 */
/*************************************************************************************************/
void PrandInit(void);

/*************************************************************************************************/
/*!
 *  \brief  Initialize random number seeds.
 *
 *  \param pSeed    Pointer to initial seed for random numbers.
 */
/*************************************************************************************************/
void PrandSetSeed(const uint32_t *);

/*************************************************************************************************/
/*!
 *  \brief      Generate random number.
 *
 *  \return     32-bit random number.
 *
 *  This software implementation uses a xorshift random number generator.
 *      George Marsaglia (2003), "Xorshift RNGs", Journal of Statistical Software
 *
 *  \note       This routine is not a cryptographic grade random number generator.
 */
/*************************************************************************************************/
uint32_t PrandNum(void);

/*************************************************************************************************/
/*!
 *  \brief      Generate random data.
 *
 *  \param      pBuf        Storage for random data.
 *  \param      len         Length of data to generate, in bytes.
 */
/*************************************************************************************************/
void PrandGen(uint8_t *pBuf, uint16_t len);

#ifdef __cplusplus
}
#endif

#endif /* PRAND_H */
