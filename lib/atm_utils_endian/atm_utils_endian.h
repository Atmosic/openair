/**
 *******************************************************************************
 *
 * @file atm_utils_endian.h
 *
 * @brief ATM common endian conversion functions
 *
 * Copyright (C) Atmosic 2022
 *
 *******************************************************************************
 */

#pragma once

#include "arch.h"

/**
 * @defgroup ATM_UTILS_ENDIAN Atmosic common endianness
 * @ingroup ATM_UTILS
 * @brief ATM common endian conversion functions
 *
 * @{
 *
 */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Reverse byte array in-place
 *
 * @param[in] ptr The address of the first byte of the array.
 * @param[in] len The length of byte array
 */
__NONNULL(1)
__STATIC_FORCEINLINE void atm_reverse(uint8_t *ptr, uint16_t len)
{
    int low = 0;
    int high = len - 1;
    while (low < high) {
	uint8_t temp = ptr[low];
	ptr[low++] = ptr[high];
	ptr[high--] = temp;
    }
}

/**
 * @brief Reverse and copy byte array
 *
 * @note This function doesn't support overlapping memory
 *
 * @param[in] dst The reversed byte array
 * @param[in] src The input byte array
 * @param[in] len The length of byte array
 */
__NONNULL(1, 2)
__STATIC_FORCEINLINE void atm_reverse_bcpy(uint8_t *dst, uint8_t const *src, uint16_t len)
{
    // Can't reverse and copy overlapping buffers
    ASSERT_ERR(((dst <= src) && ((dst + len) <= src)) ||
	((src <= dst) && ((src + len) <= dst)));

    int idx = 0;
    while (idx < len) {
	dst[idx] = src[len - 1 - idx];
	idx++;
    }
}

/**
 * @brief Byte swap 32 bits value
 *
 * @param[in] val The input value
 * @return The swapped value
 */
__STATIC_FORCEINLINE uint32_t atm_bswap32(uint32_t val)
{
    return __REV(val);
}

/**
 * @brief Byte swap 16 bits value
 *
 * @param[in] val The input value
 * @return The swapped value
 */
__STATIC_FORCEINLINE uint16_t atm_bswap16(uint16_t val)
{
    return __REV16(val);
}

/**
 * @brief Byte swap 16 bits with macro
 */
#define ATM_BSWAP16(val) (((val << 8) & 0xFF00) | ((val >> 8) & 0xFF))

/**
 * @brief Convert to little-endian 32-bit value
 *
 * @param[in] val The input value
 * @return The little-endian 32-bit value
 */
__STATIC_FORCEINLINE uint32_t atm_convert_le32(uint32_t val)
{
#if (CPU_LE)
    return val;
#else
    return atm_bswap32(val);
#endif
}

/**
 * @brief Convert to little-endian 16-bit value
 *
 * @param[in] val The input value.
 * @return The little-endian 16-bit value
 */
__STATIC_FORCEINLINE uint16_t atm_convert_le16(uint16_t val)
{
#if (CPU_LE)
    return val;
#else
    return atm_bswap16(val);
#endif
}

#ifdef __cplusplus
}
#endif

/// @}
