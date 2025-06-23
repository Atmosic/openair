/*************************************************************************************************/
/*!
 *  \file   bda.h
 *
 *  \brief  Bluetooth device address utilities.
 *
 *  Copyright (c) 2009-2018 Arm Ltd. All Rights Reserved.
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
#ifndef BDA_H
#define BDA_H

#ifdef __cplusplus
extern "C" {
#endif

/*! \addtogroup WSF_UTIL_API
 *  \{ */

/**************************************************************************************************
  Macros
**************************************************************************************************/

/*! \brief      BD address length */
#define BDA_ADDR_LEN                  6

/*! \brief      BD address string length */
#define BDA_ADDR_STR_LEN              (BDA_ADDR_LEN * 2)

/*! \brief      BDA RPA check */
#define BDA_ADDR_IS_RPA(bda)          (((bda)[5] & 0xC0) == 0x40)

/*! \brief      BDA NRPA check */
#define BDA_ADDR_IS_NRPA(bda)         (((bda)[5] & 0xC0) == 0x00)

/*! \brief      BDA static random check */
#define BDA_ADDR_IS_STATIC(bda)       (((bda)[5] & 0xC0) == 0xC0)

/*! \brief      BDA64 RPA check */
#define BDA64_ADDR_IS_RPA(bda64)      ((((bda64) >> 40) & 0xC0) == 0x40)

/*! \brief      BDA64 NRPA check */
#define BDA64_ADDR_IS_NRPA(bda64)     ((((bda64) >> 40) & 0xC0) == 0x00)

/*! \brief      BDA64 static random check */
#define BDA64_ADDR_IS_STATIC(bda64)   ((((bda64) >> 40) & 0xC0) == 0xC0)

/**************************************************************************************************
  Data Types
**************************************************************************************************/

/*! \brief      BD address data type */
typedef uint8_t bdAddr_t[BDA_ADDR_LEN];

/**************************************************************************************************
  Function Declarations
**************************************************************************************************/

/*************************************************************************************************/
/*!
 *  \brief  Copy a BD address from source to destination.
 *
 *  \param  pDst    Pointer to destination.
 *  \param  pSrc    Pointer to source.
 */
/*************************************************************************************************/
void BdaCpy(uint8_t *pDst, const uint8_t *pSrc);


/*************************************************************************************************/
/*!
 *  \brief  Compare two BD addresses.
 *
 *  \param  pAddr1  First address.
 *  \param  pAddr2  Second address.
 *
 *  \return true if addresses match, false otherwise.
 */
/*************************************************************************************************/
bool BdaCmp(const uint8_t *pAddr1, const uint8_t *pAddr2);

/*************************************************************************************************/
/*!
 *  \brief  Set a BD address to all zeros.
 *
 *  \param  pDst    Pointer to destination.
 *
 *  \return pDst + BDA_ADDR_LEN
 */
/*************************************************************************************************/
uint8_t *BdaClr(uint8_t *pDst);

/*************************************************************************************************/
/*!
*  \brief  Check if a BD address is all zeros.
*
*  \param  pAddr    Pointer to address.
*
*  \return true if address is all zeros, false otherwise.
*/
/*************************************************************************************************/
bool BdaIsZeros(const uint8_t *pAddr);

/*************************************************************************************************/
/*!
 *  \brief  Convert a BD address to a string.
 *
 *  \param  pAddr    Pointer to BD address.
 *
 *  \return Pointer to string.
 */
/*************************************************************************************************/
char *Bda2Str(const uint8_t *pAddr);

/*! \} */    /* WSF_UTIL_API */

#ifdef __cplusplus
};
#endif

#endif /* BDA_H */
