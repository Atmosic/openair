/*
 * Copyright (c) 2025 Atmosic
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/**
 * @brief Non-Secure Callable (NSC) API for SPE secure fault management
 *
 * This header provides NS/NSC API functions that can be called from NSPE to
 * interact with SPE secure fault data.
 */

#pragma once

#include <stdint.h>
#include <zephyr/arch/arm/exception.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @defgroup nsc_api Non-Secure Callable API
 * @brief NSC functions for SPE-NSPE communication
 * @{
 */

/**
 * @brief Basic Exception Stack Frame Structure
 *
 * This structure represents the core registers captured in an exception stack
 * frame.
 */
typedef struct {
    uint32_t xpsr;
    uint32_t lr;
    uint32_t pc;
} atm_spe_basic_sf_t;

/**
 * @brief SPE Secure Fault Data Structure
 *
 * This structure contains all the information captured when a secure fault
 * occurs in the SPE. It is stored in noinit memory to survive system resets
 * and can be retrieved by NSPE for debugging purposes.
 */
typedef struct {
    /** Magic number for data validation */
    uint32_t magic;
    /** Fault reason code from the fatal error handler */
    uint32_t fault_reason;
    /** Basic exception stack frame (core registers only) */
    atm_spe_basic_sf_t basic_sf;
} __attribute__((packed)) atm_spe_secure_fault_data_t;

/**
 * @brief Get complete secure fault information
 *
 * Retrieves all secure fault information and fills a secure fault data
 * structure. When clear is true, the operation atomically copies the data and
 * clears the fault storage magic number with interrupts disabled to ensure
 * consistency.
 *
 * @param fault_data Pointer to atm_spe_secure_fault_data_t structure to fill
 * @param clear If true, atomically clear the fault data after copying
 * @return true if data retrieved successfully, false otherwise
 */
bool atm_nsc_spe_get_secure_fault_data(atm_spe_secure_fault_data_t *fault_data,
    bool clear);

/**
 * @}
 */

#ifdef __cplusplus
}
#endif
