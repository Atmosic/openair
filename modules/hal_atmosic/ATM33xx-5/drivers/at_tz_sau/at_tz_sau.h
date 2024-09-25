/**
 *******************************************************************************
 *
 * @file at_tz_sau.h
 *
 * @brief Security Attribution Unit driver
 *
 * Copyright (C) Atmosic 2022
 *
 *******************************************************************************
 */

#pragma once

#include "arch.h"
#include "inttypes.h"

/**
 * @defgroup AT_TZ_SAU SAU
 * @ingroup DRIVERS
 * @brief Trustzone SAU driver
 *
 * This module contains the necessary functions to manage the SAU
 *
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#ifndef SECURE_MODE
#error "at_tz_sau is a secure-only driver."
#endif

/// Return values for sau APIs
typedef enum {
    /// Successful operation
    AT_TZ_SAU_OK,
    /// passed region is invalid, make sure region is less than
    /// at_tz_sau_num_regions()
    AT_TZ_SAU_INVALID_REGION,
    /// bad attribute. see at_tz_sau_attr_t
    AT_TZ_SAU_INVALID_ATTR,
    /// invalid base/limit address
    AT_TZ_SAU_INVALID_ADDRESS,
} at_tz_sau_ret_t;

/// Attributes for SAU regions
typedef enum {
    /// set region to NS space
    AT_TZ_SAU_NS,
    /// set region to NS-callable space
    AT_TZ_SAU_NSC,
    AT_TZ_SAU_MAX,
} at_tz_sau_attr_t;

/// SAU Base address entries must be aligned to SAU_RBAR_BADDR_Msk
#define AT_TZ_SAU_BADDR_MASK(addr) ((addr) & SAU_RBAR_BADDR_Msk)
/// SAU Limit address entries must be aligned to SAU_RBAR_BADDR_Msk
#define AT_TZ_SAU_LADDR_MASK(addr) ((addr) & SAU_RLAR_LADDR_Msk)

/// Invalid number of regions.
#define AT_TZ_SAU_INVALID_REGION_COUNT 0xff

/**
 * @brief Gets number of regions in SAU
 * @return number of regions present in SAU
 */
__STATIC_INLINE uint8_t at_tz_sau_num_regions(void)
{
    // valid region numbers are 0, 4, or 8
    static uint8_t num_regions = AT_TZ_SAU_INVALID_REGION_COUNT;
    if (num_regions != AT_TZ_SAU_INVALID_REGION_COUNT) {
	return num_regions;
    }
    num_regions = SAU->TYPE & SAU_TYPE_SREGION_Msk;
    return num_regions;
}


/**
 * @brief Returns unused region in the SAU
 *
 * @return region number, or AT_TZ_SAU_INVALID_REGION_COUNT on failure
 */
__STATIC_INLINE uint8_t at_tz_sau_get_unused_region(void)
{
    for (uint8_t i = 0; i < at_tz_sau_num_regions(); i++) {
	SAU->RNR = i;
	if (!(SAU->RLAR & SAU_RLAR_ENABLE_Msk)) {
	    return i;
	}
    }
    return AT_TZ_SAU_INVALID_REGION_COUNT;
}

/**
 * @brief Enable the Security Attribution Unit (SAU)
 * @note configures SAU to configure code to be NSCallable
 *
 * @return AT_TZ_SAU_OK on success
 */
__STATIC_INLINE at_tz_sau_ret_t at_tz_sau_enable(void)
{
    SAU->CTRL |= SAU_CTRL_ENABLE_Msk;
    // Configure code to NS callable
    SEC_CTRL_REG->NSCCFG = SEC_PRIV_CTRL_NSCCFG_CODENSC_Msk;
    return AT_TZ_SAU_OK;
}

/**
 * @brief Disable the SAU
 * @note this should be called if only using the IDAU to handle
 *       security isolation
 *
 * @return AT_TZ_SAU_OK on success
 */
__STATIC_INLINE at_tz_sau_ret_t at_tz_sau_disable(void)
{
    // clear enable bit and configure to all NS
    SAU->CTRL = SAU_CTRL_ALLNS_Msk;
    // Configure code and ram to NS callable
    SEC_CTRL_REG->NSCCFG = SEC_PRIV_CTRL_NSCCFG_RAMNSC_Msk |
	SEC_PRIV_CTRL_NSCCFG_CODENSC_Msk;
    return AT_TZ_SAU_OK;
}

/**
 * @brief Configure a single region in the SAU
 *
 * @note API is not interrupt safe
 * @note after all configurations are complete, caller must issue
 *       synchronization barriers (ISB/DSB) and flush caches
 *
 * @param[in] region region index of the SAU
 * @param[in] base base address of address space to configure
 * @param[in] limit limit address of address space to configure
 * @param[in] attr attribute to configure region to
 * @return AT_TZ_SAU_OK on success
 */
__STATIC_INLINE at_tz_sau_ret_t at_tz_sau_enable_region(uint8_t region,
    uint32_t base, uint32_t limit, at_tz_sau_attr_t attr)
{
    if (attr >= AT_TZ_SAU_MAX) {
	return AT_TZ_SAU_INVALID_ATTR;
    }
    if (region >= at_tz_sau_num_regions()) {
	return AT_TZ_SAU_INVALID_REGION;
    }
    if (base > limit) {
	return AT_TZ_SAU_INVALID_ADDRESS;
    }
    if ((base & ~SAU_RBAR_BADDR_Msk) || (limit & ~SAU_RLAR_LADDR_Msk)) {
	// bounds must be 32-byte aligned
	return AT_TZ_SAU_INVALID_ADDRESS;
    }
    uint32_t rlar_enable_mask = SAU_RLAR_ENABLE_Msk;
    if (attr == AT_TZ_SAU_NSC) {
        rlar_enable_mask |= SAU_RLAR_NSC_Msk;
    }

    SAU->RNR = region;
    SAU->RBAR = AT_TZ_SAU_BADDR_MASK(base);
    SAU->RLAR = AT_TZ_SAU_LADDR_MASK(limit) | rlar_enable_mask;
    return AT_TZ_SAU_OK;
}

/**
 * @brief Disable a single region in the SAU
 *
 * @note API is not interrupt safe
 * @note after all configurations are complete, caller must issue
 *       synchronization barriers (ISB/DSB) and flush caches
 *
 * @param[in] region region index of the SAU
 * @return AT_TZ_SAU_OK on success
 */
__STATIC_INLINE at_tz_sau_ret_t at_tz_sau_disable_region(uint8_t region)
{
    if (region >= at_tz_sau_num_regions()) {
	return AT_TZ_SAU_INVALID_REGION;
    }
    SAU->RNR = region;
    SAU->RBAR = 0;
    SAU->RLAR = 0;
    return AT_TZ_SAU_OK;
}

#ifdef __cplusplus
}
#endif

/// @}
