/*************************************************************************************************/
/*!
 *  \file   fcs.h
 *
 *  \brief  FCS utilities (3GPP TS 27.010).
 *
 *  Copyright (c) 2010-2017 Arm Ltd. All Rights Reserved.
 *
 *  Copyright (c) 2019 Packetcraft, Inc.  All rights reserved.
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
#ifndef FCS_H
#define FCS_H

#ifdef __cplusplus
extern "C" {
#endif

/*************************************************************************************************/
/*!
 *  \brief  Calculate the FCS of the given buffer.
 *
 *  \param  len      Length of the buffer.
 *  \param  pBuf     Buffer to compute the CRC.
 *
 *  \return FCS value.
 */
/*************************************************************************************************/
uint8_t FcsCalc(uint32_t len, const uint8_t *pBuf);

/*************************************************************************************************/
/*!
 *  \brief  Computes resultant CRC by appending one byte.
 *
 *  \param  pFcs     CRC value on which to append the byte.
 *  \param  byte     Byte to be added to CRC computation.
 *
 *  \return FCS value.
 */
/*************************************************************************************************/
void FcsAddByte(uint8_t *pFcs, uint8_t byte);

#ifdef __cplusplus
};
#endif

#endif /* FCS_H */
