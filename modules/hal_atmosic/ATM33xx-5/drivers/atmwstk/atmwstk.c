/**
 *******************************************************************************
 *
 * @file atmwstk.c
 *
 * @brief Application support for separate wireless stack image
 *
 * Copyright (C) Atmosic 2021-2024
 *
 *******************************************************************************
 */

#ifdef CONFIG_SOC_FAMILY_ATM
#include <zephyr/kernel.h>
#include <soc.h>
#include <zephyr/init.h>
#include <zephyr/random/random.h>
#include <stdio.h>
#endif

#include "arch.h"
#include <stdlib.h>
#include <string.h>
#include "atmwstk.h"
#ifndef CONFIG_SOC_FAMILY_ATM
#include "atm_ecc_port.h"
#endif
#include "dma.h"

#ifdef CONFIG_SOC_FAMILY_ATM
static int atmwstk_rand(void)
{
    return (sys_rand32_get());
}

static void atmwstk_srand(unsigned int seed)
{
}

#if PLF_DEBUG
static int atmwstk_putchar(int c)
{
    return putc(c, stdout);
}
#endif

static int atmwstk_init(void)
{
    static libc_iface_t const libc_iface = {
	.rf_init = rf_init,

	.free = k_free,
	.malloc = k_malloc,
	.memcmp = memcmp,
	.memcpy = memcpy,
	.memmove = memmove,
	.memset = memset,
	.rand = atmwstk_rand,
	.srand = atmwstk_srand,
	.strncmp = strncmp,

#if PLF_DEBUG
	.vprintf = vprintf,
	.putchar = atmwstk_putchar,
	.strlen = strlen,
#endif

	.dma_memcpy = dma_memcpy,
	.dma_memset = dma_memset,
	.dma_copy = dma_copy,
    };

    atmwstk_main(&libc_iface);

    return 0;
}

SYS_INIT(atmwstk_init, PRE_KERNEL_1, 1);
#else // CONFIG_SOC_FAMILY_ATM
__CONSTRUCTOR_PRIO(CONSTRUCTOR_WATCHDOG)
// NOTE: constructor function must be static for priority to be applied
static void atmwstk_init_constructor(void)
{
    static libc_iface_t const libc_iface = {
	.rf_init = rf_init,

	.free = free,
	.malloc = malloc,
	.memcmp = memcmp,
	.memcpy = memcpy,
	.memmove = memmove,
	.memset = memset,
	.rand = rand,
	.srand = srand,
	.strncmp = strncmp,

#if PLF_DEBUG
	.vprintf = vprintf,
	.putchar = putchar,
	.strlen = strlen,
#endif

	.ecc_valid_public_key_256r1 = ecc_valid_public_key_256r1,
	.ecc_compute_public_key_256r1 = ecc_compute_public_key_256r1,
	.ecc_shared_secret_256r1 = ecc_shared_secret_256r1,

	.dma_memcpy = dma_memcpy,
	.dma_memset = dma_memset,
	.dma_copy = dma_copy,
    };

    atmwstk_main(&libc_iface);
}
#endif // CONFIG_SOC_FAMILY_ATM
