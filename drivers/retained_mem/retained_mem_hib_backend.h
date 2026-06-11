/**
 *******************************************************************************
 *
 * @file retained_mem_hib_backend.h
 *
 * @brief Atmosic Retained Memory Driver - Backend Interface
 *
 * Copyright (C) Atmosic 2025-2026
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 *******************************************************************************
 */

#ifndef RETAINED_MEM_HIB_BACKEND_H
#define RETAINED_MEM_HIB_BACKEND_H

#include <stdint.h>
#include <stddef.h>
#include <zephyr/sys/util.h>

/* Include hardware register definitions for capacity detection */
#include "arch.h"
#include "at_apb_pseq_regs_core_macro.h"

#if !defined(CMSDK_SHUB_BASE) && defined(CMSDK_SHUB_NONSECURE_BASE)
#define CMSDK_SHUB_BASE CMSDK_SHUB_NONSECURE_BASE
#endif

#ifdef CMSDK_SHUB_BASE
#include "at_apb_shub_regs_core_macro.h"
#endif

/**
 * @brief Maximum retained memory capacity across all backends
 *
 * This defines the maximum buffer size needed by any backend.
 * - SHUB backend (ATM33/ATM34): up to 198-246 bytes
 * - Expansion backend: 64 - 128 bytes
 */
#define RETAINED_MEM_BACKEND_MAX_CAPACITY 246

/**
 * @brief Retained memory capacity for this platform
 *
 * This macro defines the actual number of bytes available for retained
 * memory storage based on the hardware capabilities of the platform.
 * The capacity is determined at compile time based on hardware detection:
 *
 * SHUB-based platforms (ATM33/ATM34):
 * - SHUB provides 198-222 bytes
 * - PSEQ PERSISTENT1-4 provide 16 bytes (always available)
 * - PSEQ PERSISTENT5 provides 4 additional bytes (if available)
 * - PSEQ PERSISTENT6 provides 4 additional bytes (if available)
 * Total: 198-246 bytes depending on PERSISTENT register availability and SHUB
 *        version.
 *
 * Expansion-based platforms (without SHUB):
 * - PSEQ Persistent Expansion provides 64 bytes
 */
#ifdef CMSDK_SHUB_BASE
#ifdef __SHUB_PORT0_ALM0_THRHLD_MAX_3_MACRO__
#define SHUB_CAPACITY 222
#else
#define SHUB_CAPACITY 198
#endif // __SHUB_PORT0_ALM0_THRHLD_MAX_3_MACRO__

// PERSISTENT register capacities
#define PERSIST_1_6_CAPACITY 24
#define PERSIST_1_5_CAPACITY 20
#define PERSIST_1_4_CAPACITY 16

/* SHUB backend - capacity depends on available PERSISTENT registers */
#ifdef __PSEQ_PERSISTENT6_MACRO__
#define _PHYSICAL_MEM_BACKEND_CAPACITY (SHUB_CAPACITY + PERSIST_1_6_CAPACITY)
#elif defined(__PSEQ_PERSISTENT5_MACRO__)
#define _PHYSICAL_MEM_BACKEND_CAPACITY (SHUB_CAPACITY + PERSIST_1_5_CAPACITY)
#elif defined(__PSEQ_PERSISTENT1_MACRO__)
#define _PHYSICAL_MEM_BACKEND_CAPACITY (SHUB_CAPACITY + PERSIST_1_4_CAPACITY)
#else
#define _PHYSICAL_MEM_BACKEND_CAPACITY (SHUB_CAPACITY)
#endif // __PSEQ_PERSISTENT6_MACRO__
#elif defined(__PSEQ_PERSISTENT_EXPANSION_CTRL_MACRO__)
/* Expansion backend */
#ifdef __PSEQ_PERSISTENT_EXPANSION_WDATA_MACRO__
#define _PHYSICAL_MEM_BACKEND_CAPACITY                                                             \
	((1 << PSEQ_PERSISTENT_EXPANSION_CTRL__PEXPAN_ADDR__WIDTH) * 4)
#else
#define _PHYSICAL_MEM_BACKEND_CAPACITY (1 << PSEQ_PERSISTENT_EXPANSION_CTRL__PEXPAN_ADDR__WIDTH)
#endif // __PSEQ_PERSISTENT_EXPANSION_WDATA_MACRO__
#else
#error "No retained memory backend available - neither SHUB nor persistent expansion detected"
#endif // CMSDK_SHUB_BASE

#ifdef CONFIG_RETAINED_MEM_ATM_FIXED_OFFSET_0
// word aligned access can limit the final capacity
#define RETAINED_MEM_BACKEND_CAPACITY ROUND_DOWN(_PHYSICAL_MEM_BACKEND_CAPACITY, sizeof(uint32_t))
#else
#define RETAINED_MEM_BACKEND_CAPACITY _PHYSICAL_MEM_BACKEND_CAPACITY
#endif

/**
 * @brief Save data to retained memory hardware
 *
 * This function writes the specified data to the platform-specific retained
 * memory hardware. The implementation handles all hardware-specific details
 * including clock control, register access, and data formatting.
 *
 * @param src Pointer to source data buffer
 * @param len Number of bytes to save (must not exceed capacity)
 *
 * @note This function assumes len <= capacity. Caller must validate.
 * @note This function will assert if it runs out of storage space.
 */
void retained_mem_backend_save(const uint8_t *src, uint32_t len);

/**
 * @brief Restore data from retained memory hardware
 *
 * This function reads data from the platform-specific retained memory
 * hardware into the provided buffer. The implementation handles all
 * hardware-specific details including clock control, register access,
 * and data formatting.
 *
 * @param dst Pointer to destination data buffer
 * @param len Number of bytes to restore (must not exceed capacity)
 *
 * @note This function assumes len <= capacity. Caller must validate.
 */
void retained_mem_backend_restore(uint8_t *dst, uint32_t len);

/**
 * @brief Initialize retained memory hardware backend
 *
 * This function performs any platform-specific hardware initialization
 * required for retained memory operation. This is called during driver
 * initialization on cold boot.
 *
 * @return 0 on success, negative error code on failure
 */
int retained_mem_backend_init(const struct device *dev);

#endif /* RETAINED_MEM_HIB_BACKEND_H */
