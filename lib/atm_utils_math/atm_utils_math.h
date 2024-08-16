/**
 *******************************************************************************
 *
 * @file atm_utils_math.h
 *
 * @brief ATM common math functions
 *
 * Copyright (C) Atmosic 2022-2024
 *
 *******************************************************************************
 */

#pragma once

/**
 * @defgroup ATM_UTILS_MATH Atmosic common math
 * @ingroup ATM_UTILS
 * @brief ATM common math macros and functions
 *
 * @{
 *
 */

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdlib.h>
#include "compiler.h"

/// Macro to return a value with a single bit set
#define ATM_BIT(x) (1UL << (x))

/// Macro to return the next highest 4-byte aligned value
#define ATM_ALIGN_4_BYTES(x) (((uint32_t)(x) + 0x03) & ~0x03)

/// Macro to return the smallest integer value greater than or equal to (x/y)
#define ATM_CEIL_VAL(x, y) (((x) + ((y)-1)) / (y))

/// Macro to return the nearest integer value of (x/y)
#define ATM_ROUND_VAL(x, y) (((x) + ((y) >> 1)) / (y))

/// Macro to return the minimum between two values
#define ATM_MIN(x, y) (((x) < (y)) ? (x) : (y))

/// Macro to return the maximum between two values
#define ATM_MAX(x, y) (((x) > (y)) ? (x) : (y))

/// Macro to return the absolute value
#define ATM_ABS(x) (((x) < 0) ? -(x) : (x))

#if (!defined(CONFIG_SOC_FAMILY_ATM) || defined(CONFIG_MINIMAL_LIBC_RAND))
#define ATM_UTIL_MATH_LIBC_HAS_RAND
#endif // CONFIG_SOC_FAMILY_ATM

#ifdef ATM_UTIL_MATH_LIBC_HAS_RAND
/**
 * @brief Function to get an 8 bit random number.
 *
 * @note Known PRNG functions suffer from extreme
 * predictability in the lower bits. Shift off to
 * get better rand byte
 */
__STATIC_INLINE uint8_t atm_rand_byte(void)
{
    return ((rand() >> 16) & 0xFF);
}

/**
 * @brief Function to get an 16 bit random number.
 *
 * @note Known PRNG functions suffer from extreme
 * predictability in the lower bits. Shift off to
 * get better rand byte
 */
__STATIC_INLINE uint16_t atm_rand_hword(void)
{
    return (rand() >> 16);
}

/**
 * @brief Function to get an 32 bit random number.
 */
__STATIC_INLINE uint32_t atm_rand_word(void)
{
    return rand();
}
#endif // ATM_UTIL_MATH_LIBC_HAS_RAND

/**
 * @brief Count leading zeros
 *
 * @param[in] val The input value to count
 * @return Number of leading zeros
 */
__INLINE uint32_t atm_clz(uint32_t val)
{
#if defined(__ICCARM__)
    return __CLZ(val);
#elif defined(__arm__)
    return __builtin_clz(val);
#elif defined(__GNUC__)
    if (!val) {
	return 32;
    }
    return __builtin_clz(val);
#else
    if (!val) {
	return 32;
    }
    uint32_t i = 0;
    while (!(val & (1 << (31 - i)))) {
	i++;
    }
    return i;
#endif
}

/**
 * @brief Count trailing zeros
 *
 * @param[in] val The input value to count
 * @return Number of trailing zeros
 */
__INLINE uint32_t atm_ctz(uint32_t val)
{
#if defined(__arm__) && defined(CFG_ROM)
    return __builtin_ctz(val);
#elif defined(__GNUC__)
    if (!val) {
	return 32;
    }
    return __builtin_ctz(val);
#else
    if (!val) {
	return 32;
    }
    uint32_t count = 0;
    while (!(val & 1)) {
	count++;
	val >>= 1;
    }
    return count;
#endif
}

/**
 * @brief Returns the number of one’s(set bits) in a 32-bit value
 *
 * @param[in] val The input value to count
 * @return The number of one’s(set bits)
 */
__INLINE int atm_popcount(uint32_t val)
{
#ifdef __GNUC__
    return __builtin_popcount(val);
#else
    int i = 0;
    for (; val; val &= val - 1) {
	i++;
    }
    return i;
#endif
}

#ifdef __cplusplus
}
#endif

/// @}
