/**
 ******************************************************************************
 *
 * @file sec_assert.h
 *
 * @brief Secure Assert library
 *
 * Copyright (C) Atmosic 2022-2024
 *
 ******************************************************************************
 */

#pragma once

/**
 * @defgroup SEC_ASSERT Secure Assert
 * @ingroup ATM_UTILS
 * @brief Secure Assert library
 * @{
 */
#include <stdio.h>
#include "arch.h"

#if PLF_DEBUG
#define SEC_ASSERT(cond) \
    do { \
	if (!(cond)) { \
	    sec_assert(__MODULE__, __LINE__); \
	} \
    } while (0)
#else
#define SEC_ASSERT(cond) \
    do { \
	if (!(cond)) { \
	    sec_assert(NULL, 0); \
	} \
    } while (0)
#endif

/**
 * @brief Print the sercure assertion error reason and halt execution to wait
 * for a watchdog reset.
 *
 * @param[in] file C string containing file where the assertion is located.
 * @param[in] line Line number in the file where the assertion is located.
 *
 * @note If we are in release mode no details will be emitted
 */
__NO_RETURN
void sec_assert(const char *file, int line);

/// @} SEC_ASSERT
