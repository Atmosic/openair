/**
 *******************************************************************************
 *
 * @file atm_utils_reg.h
 *
 * @brief ATM utility functions for register access
 *
 * Copyright (C) Atmosic 2022-2023
 *
 *******************************************************************************
 */
#pragma once

#include <stddef.h>
#include <stdint.h>
#include "arch.h"

/**
 * @defgroup ATM_UTILS_REG ATM utility functions for register access
 * @ingroup ATM_UTILS
 * @brief ATM utility functions for register access
 *
 * Utility inline functions for register access
 *
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    uint32_t d;
} __PACKED misaligned_uint32_t;

/**
 * @brief Write a register from a potentially unaligned source
 * @param[out] reg The address of the register
 * @param[in] data The address of the data
 */
__NONNULL_ALL
__INLINE
void atm_reg_write(uint32_t volatile *reg, void const *data)
{
    *reg = ((misaligned_uint32_t const *)data)->d;
}

/**
 * @brief Read a register to a potentially unaligned destination
 * @param[in] reg The address of the register
 * @param[out] data The address of the destination
 */
__NONNULL_ALL
__INLINE
void atm_reg_read(uint32_t volatile const *reg, void *data)
{
    ((misaligned_uint32_t *)data)->d = *reg;
}

/**
 * @brief Write a series of registers from a potentially unaligned source
 *
 * @note Register writes are always words. If there is not enough bytes to fill
 * the final word it will be padded with 0s
 *
 * @param[out] reg The address of the register
 * @param[in] data The address of the data
 * @param[in] num_bytes The number of bytes from the source
 */
__NONNULL(1, 2)
void atm_reg_write_multiple(uint32_t volatile *reg, uint8_t const *data,
    size_t const num_bytes);

/**
 * @brief Read a series of registers from a potentially unaligned source
 *
 * @note Register reads are always words. Extra bytes read are discarded.
 *
 * @param[in] reg The address of the register
 * @param[out] data The address of the destination
 * @param[in] num_bytes The number of bytes to write to the destination
 */
__NONNULL(1, 2)
void atm_reg_read_multiple(uint32_t volatile const *reg, uint8_t *data,
    size_t const num_bytes);

/**
 * @brief Write a right-aligned series of registers from a potentially unaligned
 * source.
 *
 * @note Register writes are always words. If there is not enough bytes to fill
 * the initial word it will be padded with 0s
 *
 * @param[out] reg The address of the register
 * @param[in] num_regs The number of registers in the field
 * @param[in] data The address of the data
 * @param[in] num_bytes The number of bytes from the source
 */
__NONNULL(1, 3)
void atm_reg_write_multiple_r(uint32_t volatile *reg, size_t const num_regs,
    uint8_t const *data, size_t const num_bytes);

/**
 * @brief Read a right-aligned series of registers from a potentially unaligned
 * source
 *
 * @note Register reads are always words. Extra bytes read are discarded.
 *
 * @param[in] reg The address of the register
 * @param[in] num_regs The number of registers in the field
 * @param[out] data The address of the destination
 * @param[in] num_bytes The number of bytes to write to the destination
 */
__NONNULL(1, 3)
void atm_reg_read_multiple_r(uint32_t volatile const *reg,
    size_t const num_regs, uint8_t *data, size_t const num_bytes);

#ifdef __cplusplus
}
#endif

/// @} ATM_UTILS_REG
