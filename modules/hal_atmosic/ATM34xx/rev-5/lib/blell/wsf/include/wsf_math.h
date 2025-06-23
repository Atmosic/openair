/*************************************************************************************************/
/*!
 *  \file   wsf_math.h
 *
 *  \brief  Common math utilities.
 *
 *  Copyright (c) 2013-2018 Arm Ltd. All Rights Reserved.
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
#ifndef WSF_MATH_H
#define WSF_MATH_H

#include "wsf_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/*! \addtogroup WSF_MATH_API
 *  \{ */

/**************************************************************************************************
  Macros
**************************************************************************************************/

/*! \brief      Returns the minimum of two values. */
#define WSF_MIN(a,b)              ((a) < (b) ? (a) : (b))

/*! \brief      Returns the maximum of two values. */
#define WSF_MAX(a,b)              ((a) > (b) ? (a) : (b))

/*! \brief      Returns if a device only has one bit set. */
#define WSF_MULTIPLE_BITS_SET(a)  (((a) & ((a) - 1)) != 0)

/*! \brief      Returns the absolute value of x. */
#define WSF_ABS(x)                ((x) > 0 ? (x) : -(x))

/*! \} */    /* WSF_MATH_API */

#ifdef __cplusplus
};
#endif

#endif /* WSF_MATH_H */
