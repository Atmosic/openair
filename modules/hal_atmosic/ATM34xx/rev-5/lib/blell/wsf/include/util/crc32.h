/*************************************************************************************************/
/*!
 *  \file   crc32.h
 *
 *  \brief  CRC-32 utilities.
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
#ifndef CRC32_H
#define CRC32_H

#ifdef __cplusplus
extern "C" {
#endif

/*! \addtogroup WSF_UTIL_API
 *  \{ */

/*************************************************************************************************/
/*!
 *  \brief  Calculate the CRC-32 of the given buffer.
 *
 *  \param  crcInit  Initial value of the CRC.
 *  \param  len      Length of the buffer.
 *  \param  pBuf     Buffer to compute the CRC.
 *  \return TBD.
 *
 *  This routine was originally generated with crcmod.py using the following parameters:
 *    - polynomial 0x104C11DB7
 *    - bit reverse algorithm
 */
/*************************************************************************************************/
uint32_t CalcCrc32(uint32_t crcInit, uint32_t len, const uint8_t *pBuf);

/*************************************************************************************************/
/*!
 *  \brief  Calculate the CRC-32 of the given buffer by segments.
 *
 *  \param  crcInit     Initial value of the CRC.
 *  \param  len         Length of the buffer.
 *  \param  pBuf        Buffer to compute the CRC.
 *  \param  endOfStream The following buffer is the end of the stream.
 *
 */
/*************************************************************************************************/
uint32_t CalcSegmentCrc32(uint32_t crcInit, uint32_t len, const uint8_t* pBuf, bool endOfStream);

/*! \} */    /* WSF_UTIL_API */

#ifdef __cplusplus
};
#endif

#endif /* CRC32_H */
