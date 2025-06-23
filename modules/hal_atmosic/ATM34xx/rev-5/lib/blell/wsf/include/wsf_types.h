/*************************************************************************************************/
/*!
 *  \file   wsf_types.h
 *
 *  \brief  Platform-independent data types.
 *
 *  Copyright (c) 2009-2019 Arm Ltd. All Rights Reserved.
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
#ifndef WSF_TYPES_H
#define WSF_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif

/*! \addtogroup WSF_TYPES
 *  \{ */

/**************************************************************************************************
  Data Types
**************************************************************************************************/

/** \name Integer Data Types
 *
 */
/**@{*/

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#ifndef UINT64_C
#define UINT64_C(x) x##ULL
#endif

#ifndef UINT32_C
#define UINT32_C(x) x##UL
#endif

#ifndef UINT8_C
#define UINT8_C(x) (x)
#endif

/*! \} */    /* Integer Data Types */

#ifdef __cplusplus
};
#endif
/*! \} */    /* WSF_TYPES */
#endif /* WSF_TYPES_H */
