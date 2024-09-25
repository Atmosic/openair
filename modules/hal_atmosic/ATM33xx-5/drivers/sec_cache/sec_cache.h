/**
 *******************************************************************************
 *
 * @file sec_cache.h
 *
 * @brief Secure cache driver header file
 *
 * Copyright (C) Atmosic 2022-2024
 *
 *******************************************************************************
 */

#pragma once

/**
 * @defgroup SEC_CACHE Secure cache
 * @ingroup DRIVERS
 * @brief Secure cache driver to manage CPU caches
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#if (defined(SECURE_MODE) || defined(CFG_NO_SPE))
/**
 * @brief Disable instruction cache
 */
void icache_disable(void);

/**
 * @brief Enable instruction cache
 */
void icache_enable(void);

/**
 * @brief Flush instruction cache
 */
void icache_flush(void);

#define ICACHE_DISABLE() icache_disable()
#define ICACHE_ENABLE() icache_enable()
#define ICACHE_FLUSH() icache_flush()

#else

#define ICACHE_DISABLE() nsc_icache_disable()
#define ICACHE_ENABLE() nsc_icache_enable()
#define ICACHE_FLUSH() nsc_icache_flush()

#endif // (defined(SECURE_MODE) || defined(CFG_NO_SPE))

/**
 * @brief NS-callable fucntion of icache_disable
 */
void nsc_icache_disable(void);

/**
 * @brief NS-callable fucntion of icache_enable
 */
void nsc_icache_enable(void);

/**
 * @brief NS-callable fucntion of icache_flush
 */
void nsc_icache_flush(void);

#ifdef __cplusplus
}
#endif

/// @}
