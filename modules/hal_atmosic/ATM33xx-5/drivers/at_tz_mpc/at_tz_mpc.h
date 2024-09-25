/**
 *******************************************************************************
 *
 * @file at_tz_mpc.h
 *
 * @brief Memory Protection Controller (MPC) driver
 *
 * Copyright (C) Atmosic 2022
 *
 *******************************************************************************
 */

#pragma once

#include "arch.h"
#include <inttypes.h>

/**
 * @defgroup AT_TZ_MPC MPC
 * @ingroup DRIVERS
 * @brief Trustzone MPC driver
 *
 * This module contains the necessary functions to manage Memory protection
 * controllers
 *
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/// Block size of MPC_FLS
#define AT_TZ_MPC_FLS_BLK_SIZE 2048
/// Block size of MPC_RAM[0-3]
#define AT_TZ_MPC_RAM_BLK_SIZE 256

// only 128K of ext flash is configurable via MPC
#define AT_TZ_MPC_EXT_FLASH_MPC_SIZE 0x20000

typedef enum {
    /// Success
    AT_TZ_MPC_RET_OK,
    /// Bounds are invalid for configuration
    AT_TZ_MPC_RET_BAD_BOUNDS,
    /// address results in invalid block address
    AT_TZ_MPC_RET_BLK_IDX_TOO_HIGH,
    /// Memory type not supported by MPC
    AT_TZ_MPC_RET_INVALID_TYPE,
    AT_TZ_MPC_RET_MAX,
} at_tz_mpc_ret_t;

typedef enum {
    /// MPC secure attribute
    AT_TZ_MPC_ATTR_SECURE,
    /// MPC non-secure attribute
    AT_TZ_MPC_ATTR_NONSECURE,
    AT_TZ_MPC_ATTR_MAX,
} at_tz_mpc_attr_t;

typedef enum {
    /// FLASH MPC
    AT_TZ_MPC_DEV_FLASH,
    /// RAM MPC
    AT_TZ_MPC_DEV_RAM,
    AT_TZ_MPC_DEV_INVALID,
    AT_TZ_MPC_DEV_MAX,
} at_tz_mpc_id_t;

/**
 * @brief Get block size for a given MPC
 *
 * @param[in] mpc_type MPC
 * @return block size of MPC
 */
__STATIC_INLINE uint32_t at_tz_mpc_get_block_size(at_tz_mpc_id_t mpc_type)
{
    if (mpc_type == AT_TZ_MPC_DEV_FLASH) {
	return AT_TZ_MPC_FLS_BLK_SIZE;
    }
    ASSERT_INFO(mpc_type == AT_TZ_MPC_DEV_RAM, mpc_type, 0);
    // assumes all RAM mpcs have the same block size
    return AT_TZ_MPC_RAM_BLK_SIZE;
}

/**
 * @brief Enable interrupt on specific MPC
 * @note This API only enables the interrupt at the controller.
 *       User is required to implement MPC interrupt handler.
 *
 * @param[in] mpc_type MPC to enable interrupt on
 * @return AT_TZ_MPC_RET_OK on success
 */
__STATIC_INLINE at_tz_mpc_ret_t at_tz_mpc_enable_int(at_tz_mpc_id_t mpc_type)
{
    if (mpc_type == AT_TZ_MPC_DEV_FLASH) {
	MPC_FLS->INT_EN |= MPC_INT_EN_IRQ_EN_Msk;
	return AT_TZ_MPC_RET_OK;
    } else if (mpc_type == AT_TZ_MPC_DEV_RAM) {
	MPC_RAM0->INT_EN |= MPC_INT_EN_IRQ_EN_Msk;
	MPC_RAM1->INT_EN |= MPC_INT_EN_IRQ_EN_Msk;
	MPC_RAM2->INT_EN |= MPC_INT_EN_IRQ_EN_Msk;
	MPC_RAM3->INT_EN |= MPC_INT_EN_IRQ_EN_Msk;
	return AT_TZ_MPC_RET_OK;
    }
    return AT_TZ_MPC_RET_INVALID_TYPE;
}

/**
 * @brief Disable interupt on specific MPC
 *
 * @param[in] mpc_type MPC to disable interrupt on
 * @return AT_TZ_MPC_RET_OK on success
 */
__STATIC_INLINE at_tz_mpc_ret_t at_tz_mpc_disable_int(at_tz_mpc_id_t mpc_type)
{
    if (mpc_type == AT_TZ_MPC_DEV_FLASH) {
	MPC_FLS->INT_EN &= ~MPC_INT_EN_IRQ_EN_Msk;
	return AT_TZ_MPC_RET_OK;
    } else if (mpc_type == AT_TZ_MPC_DEV_RAM) {
	MPC_RAM0->INT_EN &= ~MPC_INT_EN_IRQ_EN_Msk;
	MPC_RAM1->INT_EN &= ~MPC_INT_EN_IRQ_EN_Msk;
	MPC_RAM2->INT_EN &= ~MPC_INT_EN_IRQ_EN_Msk;
	MPC_RAM3->INT_EN &= ~MPC_INT_EN_IRQ_EN_Msk;
	return AT_TZ_MPC_RET_OK;
    }
    return AT_TZ_MPC_RET_INVALID_TYPE;
}

/**
 * @brief Enable triggering bus fault on mpc violation
 *
 * @param[in] mpc_type MPC to enable interrupt on
 * @return AT_TZ_MPC_RET_OK on success
 */
__STATIC_INLINE at_tz_mpc_ret_t at_tz_mpc_enable_bus_fault(
    at_tz_mpc_id_t mpc_type)
{
    if (mpc_type == AT_TZ_MPC_DEV_FLASH) {
	MPC_FLS->CTRL |= MPC_CTRL_CFG_SEC_RESP_Msk;
	return AT_TZ_MPC_RET_OK;
    } else if (mpc_type == AT_TZ_MPC_DEV_RAM) {
	MPC_RAM0->CTRL |= MPC_CTRL_CFG_SEC_RESP_Msk;
	MPC_RAM1->CTRL |= MPC_CTRL_CFG_SEC_RESP_Msk;
	MPC_RAM2->CTRL |= MPC_CTRL_CFG_SEC_RESP_Msk;
	MPC_RAM3->CTRL |= MPC_CTRL_CFG_SEC_RESP_Msk;
	return AT_TZ_MPC_RET_OK;
    }
    return AT_TZ_MPC_RET_INVALID_TYPE;
}

/**
 * @brief Enable lockdown feature that prevents malicious software from
 *        changing the security configuration.
 *
 * @note lockdown can only be disabled with a reset.
 *
 * @param[in] mpc_type device to lock down
 * @return AT_TZ_MPC_RET_OK on success
 */
__STATIC_INLINE at_tz_mpc_ret_t at_tz_mpc_lock_down(at_tz_mpc_id_t mpc_type)
{
    // Arm recommends that you enabled the auto-increment bit before enabling
    // the configuration lockdown feature.  When the feature is enabled, only
    // LUT dumping is available which is simpler when BLK_IDX auto-increments
    if (mpc_type == AT_TZ_MPC_DEV_FLASH) {
	MPC_FLS->CTRL |= (MPC_CTRL_AUTO_INCREMENT_Msk | MPC_CTRL_SEC_LOCK_Msk);
	return AT_TZ_MPC_RET_OK;
    } else if (mpc_type == AT_TZ_MPC_DEV_RAM) {
	MPC_RAM0->CTRL |= (MPC_CTRL_AUTO_INCREMENT_Msk | MPC_CTRL_SEC_LOCK_Msk);
	MPC_RAM1->CTRL |= (MPC_CTRL_AUTO_INCREMENT_Msk | MPC_CTRL_SEC_LOCK_Msk);
	MPC_RAM2->CTRL |= (MPC_CTRL_AUTO_INCREMENT_Msk | MPC_CTRL_SEC_LOCK_Msk);
	MPC_RAM3->CTRL |= (MPC_CTRL_AUTO_INCREMENT_Msk | MPC_CTRL_SEC_LOCK_Msk);
	return AT_TZ_MPC_RET_OK;
    }
    return AT_TZ_MPC_RET_INVALID_TYPE;
}

/**
 * @brief Configure a given region to a specific security attribute.
 *
 * @param[in] base base address for lower bound of region
 *        Must be aligned to at_tz_mpc_get_block_size(type)
 * @param[in] limit limit of region, inclusive.
 *        Must be aligned to (at_tz_mpc_get_block_size(type) - 1)
 * @param[in] attr attribute to configure region to
 * @return AT_TZ_MPC_RET_OK on success
 */
at_tz_mpc_ret_t at_tz_mpc_config_region(uint32_t base, uint32_t limit,
    at_tz_mpc_attr_t attr);

/**
 * @brief Configure remaining external flash (beyond 128k) security
 *
 * @note Size of flash is highly variable, only 128k is configurable at
 *    2k boundary, remaining up to 16M is controlled by a single bit.
 * @return AT_TZ_MPC_RET_OK on success
 */
__STATIC_INLINE at_tz_mpc_ret_t at_tz_mpc_config_remaining_ext_flash(
    at_tz_mpc_attr_t attr)
{
    MPC_FLS->BLK_IDX = 34;
    if (attr == AT_TZ_MPC_ATTR_NONSECURE) {
	MPC_FLS->BLK_LUT = 0x1;
	return AT_TZ_MPC_RET_OK;
    }
    MPC_FLS->BLK_LUT = 0x0;
    return AT_TZ_MPC_RET_OK;
}

#ifdef __cplusplus
}
#endif

/// @}
