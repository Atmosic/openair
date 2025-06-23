/*************************************************************************************************/
/*!
 *  \file   wsf_assert.h
 *
 *  \brief  Assert macro.
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
#ifndef WSF_ASSERT_H
#define WSF_ASSERT_H

#include "wsf_trace.h"

#ifdef __cplusplus
extern "C" {
#endif

/*! \addtogroup WSF_ASSERT_API
 *  \{ */

/**************************************************************************************************
  Function Prototypes
**************************************************************************************************/

#if WSF_TOKEN_ENABLED == 1
/*************************************************************************************************/
/*!
 *  \brief  Perform an assert action.
 *
 *  \param  modId   Name of file originating assert.
 *  \param  line    Line number of assert statement.
 */
/*************************************************************************************************/
void WsfAssert(uint16_t modId, uint16_t line);
#else
/*************************************************************************************************/
/*!
 *  \brief  Perform an assert action.
 *
 *  \param  pFile   Name of file originating assert.
 *  \param  line    Line number of assert statement.
 */
/*************************************************************************************************/
void WsfAssert(const char *pFile, uint16_t line);
#endif

/*************************************************************************************************/
/*!
 *  \brief  Get number of asserts.
 *
 *  \return Number of asserts.
 */
/*************************************************************************************************/
uint16_t WsfAssertNum(void);

/*************************************************************************************************/
/*!
 *  \brief  Enable assert trap.
 *
 *  \param  enaAssertTrap     true to enable assert trap.
 */
/*************************************************************************************************/
void WsfAssertTrapEnable(bool enaAssertTrap);

/**************************************************************************************************
  Macros
**************************************************************************************************/

#ifndef WSF_ASSERT_ENABLED
/*! \brief  Enable assertion statements. */
#define WSF_ASSERT_ENABLED 0
#endif

#ifndef WSF_TOKEN_ENABLED
/*! \brief  Enable tokenized tracing. */
#define WSF_TOKEN_ENABLED 0
#endif

/*************************************************************************************************/
/*!
 *  \brief  Run-time assert macro.  The assert executes when the expression is false.
 *
 *  \param  expr    Boolean expression to be tested.
 */
/*************************************************************************************************/
#ifndef WSF_ASSERT
#ifdef WSF_ASSERT_INFO
#define WSF_ASSERT(expr) WSF_ASSERT_INFO(expr, 0, 0)
#else
#if WSF_ASSERT_ENABLED == 1
#if WSF_TOKEN_ENABLED == 1
#define WSF_ASSERT(expr)      if (!(expr)) {WsfAssert(MODULE_ID, (uint16_t) __LINE__);}
#else
#define WSF_ASSERT(expr)      if (!(expr)) {WsfAssert(__FILE__, (uint16_t) __LINE__);}
#endif
#else
#define WSF_ASSERT(expr)
#endif
#endif
#endif

/*************************************************************************************************/
/*!
 *  \brief  Compile-time assert macro.  This macro causes a compiler error when the
 *          expression is false.  Note that this macro is generally used at file scope to
 *          test constant expressions.  Errors may result of it is used in executing code.
 *
 *  \param  expr    Boolean expression to be tested.
 */
/*************************************************************************************************/
#define WSF_CT_ASSERT(expr)     extern char wsf_ct_assert[(expr) ? 1 : -1]

/*! \} */    /* WSF_ASSERT_API */

#ifdef __cplusplus
};
#endif

#endif /* WSF_ASSERT_H */
