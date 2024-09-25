/**
 *******************************************************************************
 *
 * @file atmwstk.h
 *
 * @brief Application support for separate wireless stack image
 *
 * Copyright (C) Atmosic 2021-2024
 *
 *******************************************************************************
 */

#pragma once

/**
 * @defgroup ATMWSTK Atmosic wireless stack
 * @ingroup DRIVERS
 * @brief Application support for separate wireless stack image
 * @{
 */

#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

struct rwip_rf_api;

#ifdef __ICCARM__
#define __VALIST __Va_list
#elif defined(__ARMCC_VERSION)
#define __VALIST va_list
#elif defined(CONFIG_SOC_FAMILY_ATM) && !defined(__VALIST)
#define __VALIST __gnuc_va_list
#endif

/// Akin to shared library PLT
typedef struct {
    void (*rf_init)(struct rwip_rf_api *api);

    void (*free)(void *__ptr);
    void *(*malloc)(size_t __size);
    int (*memcmp)(const void *__s1, const void *__s2, size_t __n);
    void *(*memcpy)(void * __dest, const void * __src, size_t __n);
    void *(*memmove)(void *__dest, const void *__src, size_t __n);
    void *(*memset)(void *__s, int __c, size_t __n);
    int (*rand)(void);
    void (*srand)(unsigned int __seed);
    int (*strncmp)(const char *__s1, const char *__s2, size_t __n);
    int (*vprintf)(const char *__fmt, __VALIST __va);
    int (*putchar)(int _c);
    size_t (*strlen)(const char *__s);

    int (*ecc_valid_public_key_256r1)(uint8_t const *pub_key);
    void (*ecc_compute_public_key_256r1)(uint8_t const *priv_key,
	uint8_t *pub_key);
    void (*ecc_shared_secret_256r1)(uint8_t const *pub_key,
	uint8_t const *priv_key, uint8_t *secret);

    void *(*dma_memcpy)(void *d, const void *s, size_t n);
    void *(*dma_memset)(void *m, int c, size_t n);
    void (*dma_copy)(uint8_t channel, void* p_dst_addr, const void* p_src_addr,
	uint16_t size);
} libc_iface_t;

/**
 * @brief Entry point for separate image
 * @param[in] libc_iface External functions needed by wireless stack.
 */
void atmwstk_main(libc_iface_t const *libc_iface);

#ifdef __cplusplus
}
#endif

/// @} ATMWSTK
