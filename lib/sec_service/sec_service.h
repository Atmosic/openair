/**
 ******************************************************************************
 *
 * @file sec_service.h
 *
 * @brief Secure Services
 *
 * Copyright (C) Atmosic 2022-2024
 *
 ******************************************************************************
 */

#pragma once

/**
 * @defgroup SEC_SERVICE Secure Services
 * @ingroup SPE_API
 * @brief Library functions for secure services
 * @{
 */

#ifdef SECURE_PROC_ENV
#define __SPE_NSC __attribute__((cmse_nonsecure_entry)) __attribute__((used))
#else
#define __SPE_NSC
#endif

#ifndef VERIFY_ATMWSTK
#if defined(ATMWSTK) && (defined(CFG_PLF_DEBUG) || defined(USE_SECURE_BOOT))
#define VERIFY_ATMWSTK 1
#else
#define VERIFY_ATMWSTK 0
#endif
#endif

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

/**
 * @brief checks if caller has access to passed address range
 *
 * @param ptr ptr to address in question
 * @param len length of region
 * @param ns_caller true if from NS space
 * @param write check for write access
 * @return true if access is OK, false otherwise
 */
bool mem_check_has_access(void const *ptr, uint32_t len, bool ns_caller,
    bool write);

#if VERIFY_ATMWSTK
/**
 * @brief Verify the integrity of the ATMWSTK
 * @return true if stack verifies, else false
 */
bool verify_atmwstk(void);
#endif

/**
 * @brief Lock down security settings for the platform
 */
void sec_lockdown(void);


/**
 * @brief Perform secure PPC configuration.
 *
 * @note, weak alias, override-able via SPE extensions
 */
void sec_ppc_cfg(void);

#ifdef __cplusplus
}
#endif

/// @}
