/**
 *******************************************************************************
 *
 * @file atm_utils_c.h
 *
 * @brief ATM common utility functions
 *
 * Copyright (C) Atmosic 2022-2026
 *
 *******************************************************************************
 */
#pragma once

#include <stdint.h>
#include <stdbool.h>
#include "arch.h"

/**
 * @defgroup ATM_UTILS_C Atmosic common utilities related to C
 * @ingroup ATM_UTILS
 * @brief ATM common utility C functions
 *
 * Common utility inline functions and macros
 *
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#ifndef ARRAY_LEN
// put the array name in the index operator intentionally
// this way the issue caused by operator overloading in C++ will be noticed
#define ARRAY_LEN(x) (sizeof(x) / sizeof(0[x]))
#endif

#ifndef CONTAINER_OF
#define CONTAINER_OF(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))
#endif

/**
 * @brief Read a 16-bit little-endian value from any address in memory space.
 * @param[in] ptr The address of the first byte of the value.
 * @return The 16-bit value.
 */
__NONNULL_ALL
__STATIC_FORCEINLINE uint16_t atm_get_le16(void const *ptr)
{
    typedef struct __PACKED {
	uint16_t val;
    } atm_le16_t;
    atm_le16_t const *pu16 = (atm_le16_t const *)ptr;
#if (CPU_LE)
    return pu16->val;
#else
    return __REVSH(pu16->val);
#endif
}

/**
 * @brief Read a 24-bit little-endian value from any address in memory space.
 * @param[in] ptr The address of the first byte of the value.
 * @return The 24-bit value.
 */
__NONNULL_ALL
__STATIC_FORCEINLINE uint32_t atm_get_le24(void const *ptr)
{
    uint8_t const volatile *p = (uint8_t const volatile *)ptr;
    return p[0] | (p[1] << 8) | (p[2] << 16);
}

/**
 * @brief Read a 32-bit little-endian value from any address in memory space.
 * @param[in] ptr The address of the first byte of the value.
 * @return The 32-bit value.
 */
__NONNULL_ALL
__STATIC_FORCEINLINE uint32_t atm_get_le32(void const *ptr)
{
    typedef struct __PACKED {
	uint32_t val;
    } atm_le32_t;
    atm_le32_t const *pu32 = (atm_le32_t const *)ptr;
#if (CPU_LE)
    return pu32->val;
#else
    return __REV(pu32->val);
#endif
}

/**
 * @brief Read a 16-bit big-endian value from any address in memory space.
 * @param[in] ptr The address of the first byte of the value.
 * @return The 16-bit value.
 */
__NONNULL_ALL
__STATIC_FORCEINLINE uint16_t atm_get_be16(void const *ptr)
{
    typedef struct __PACKED {
	uint16_t val;
    } atm_be16_t;
    atm_be16_t const *pu16 = (atm_be16_t const *)ptr;
#if (!CPU_LE)
    return pu16->val;
#else
    return __REVSH(pu16->val);
#endif
}

/**
 * @brief Read a 24-bit big-endian value from any address in memory space.
 * @param[in] ptr The address of the first byte of the value.
 * @return The 24-bit value.
 */
__NONNULL_ALL
__STATIC_FORCEINLINE uint32_t atm_get_be24(void const *ptr)
{
    uint8_t const volatile *p = (uint8_t const volatile *)ptr;
    return p[2] | (p[1] << 8) | (p[0] << 16);
}

/**
 * @brief Read a 32-bit big-endian value from any address in memory space.
 * @param[in] ptr The address of the first byte of the value.
 * @return The 32-bit value.
 */
__NONNULL_ALL
__STATIC_FORCEINLINE uint32_t atm_get_be32(void const *ptr)
{
    typedef struct __PACKED {
	uint32_t val;
    } atm_be32_t;
    atm_be32_t const *pu32 = (atm_be32_t const *)ptr;
#if (!CPU_LE)
    return pu32->val;
#else
    return __REV(pu32->val);
#endif
}

/**
 * @brief Write a 16-bit value to any address in memory space. The value will be
 * written in little-endian order.
 * @param[in] ptr The address of the first byte to write the value.
 * @param[in] value The 16-bit value to be written
 */
__NONNULL(1)
__STATIC_FORCEINLINE void atm_set_le16(void *ptr, uint16_t value)
{
    typedef struct __PACKED {
	uint16_t val;
    } atm_le16_t;
    atm_le16_t *pu16 = (atm_le16_t *)ptr;
#if (CPU_LE)
    pu16->val = value;
#else
    pu16->val = __REVSH(value);
#endif
}

/**
 * @brief Write a 24-bit value to any address in memory space. The value will be
 * written in little-endian order.
 * @param[in] ptr The address of the first byte to write the value.
 * @param[in] value The 24-bit value to be written
 */
__NONNULL(1)
__STATIC_FORCEINLINE void atm_set_le24(void *ptr, uint32_t value)
{
    uint8_t volatile *p = (uint8_t volatile *)ptr;
    p[0] = value;
    p[1] = value >> 8;
    p[2] = value >> 16;
}

/**
 * @brief Write a 32-bit value to any address in memory space. The value will be
 * written in little-endian order.
 * @param[in] ptr The address of the first byte to write the value.
 * @param[in] value The 32-bit value to be written
 */
__NONNULL(1)
__STATIC_FORCEINLINE void atm_set_le32(void *ptr, uint32_t value)
{
    typedef struct __PACKED {
	uint32_t val;
    } atm_le32_t;
    atm_le32_t *pu32 = (atm_le32_t *)ptr;
#if (CPU_LE)
    pu32->val = value;
#else
    pu32->val = __REV(value);
#endif
}

/**
 * @brief Write a 16-bit value to any address in memory space. The value will be
 * written in big-endian order.
 * @param[in] ptr The address of the first byte to write the value.
 * @param[in] value The 16-bit value to be written
 */
__NONNULL(1)
__STATIC_FORCEINLINE void atm_set_be16(void *ptr, uint16_t value)
{
    typedef struct __PACKED {
	uint16_t val;
    } atm_be16_t;
    atm_be16_t *pu16 = (atm_be16_t *)ptr;
#if (!CPU_LE)
    pu16->val = value;
#else
    pu16->val = __REVSH(value);
#endif
}

/**
 * @brief Write a 24-bit value to any address in memory space. The value will be
 * written in big-endian order.
 * @param[in] ptr The address of the first byte to write the value.
 * @param[in] value The 24-bit value to be written
 */
__NONNULL(1)
__STATIC_FORCEINLINE void atm_set_be24(void *ptr, uint32_t value)
{
    uint8_t volatile *p = (uint8_t volatile *)ptr;
    p[2] = value;
    p[1] = value >> 8;
    p[0] = value >> 16;
}

/**
 * @brief Write a 32-bit value to any address in memory space. The value will be
 * written in big-endian order.
 * @param[in] ptr The address of the first byte to write the value.
 * @param[in] value The 32-bit value to be written
 */
__NONNULL(1)
__STATIC_FORCEINLINE void atm_set_be32(void *ptr, uint32_t value)
{
    typedef struct __PACKED {
	uint32_t val;
    } atm_be32_t;
    atm_be32_t *pu32 = (atm_be32_t *)ptr;
#if (!CPU_LE)
    pu32->val = value;
#else
    pu32->val = __REV(value);
#endif
}

#ifdef __cplusplus
}
#endif

/// @} ATM_UTILS
