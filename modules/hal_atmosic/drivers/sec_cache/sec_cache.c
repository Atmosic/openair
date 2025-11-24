/**
 *******************************************************************************
 *
 * @file sec_cache.c
 *
 * @brief Secure cache driver implementation
 *
 * Copyright (C) Atmosic 2022-2025
 *
 *******************************************************************************
 */
#ifdef CFG_NO_SPE
// for no-SPE the base for the ICACHE control registers must be a secure address
#ifndef SECURE_MODE
#define SECURE_MODE
#endif
#endif // CFG_NO_SPE
#include "arch.h"
#include "sec_service.h"
#include "sec_cache.h"

#ifndef SECURE_MODE
#error "sec_cache is a secure-only driver"
#endif

#ifdef ATM_CACHE_FUNC_IN_RAM
// locate cache maintence functions to RAM
#define __CACHE_FUNC_LOC __attribute__((noinline, section(".data_text")))
#else
#define __CACHE_FUNC_LOC
#endif

__CACHE_FUNC_LOC void icache_disable(void)
{
    ICACHE->ICCTRL &= ~ICACHE_ICCTRL_CACHEEN_Msk;
}

__CACHE_FUNC_LOC void icache_enable(void)
{
    ICACHE->ICIRQSCLR |= ICACHE_ICIRQSTAT_IC_STATUS_Msk;
    ICACHE->ICCTRL |= ICACHE_ICCTRL_FINV_Msk | ICACHE_ICCTRL_CACHEEN_Msk;
}

__CACHE_FUNC_LOC void icache_flush(void)
{
    if (!(ICACHE->ICCTRL & ICACHE_ICCTRL_CACHEEN_Msk)) {
	return;
    }

    ICACHE->ICIRQSCLR |= ICACHE_ICIRQSTAT_IC_STATUS_Msk;
    ICACHE->ICCTRL |= ICACHE_ICCTRL_FINV_Msk;
    while (!(ICACHE->ICIRQSTAT & ICACHE_ICIRQSTAT_IC_STATUS_Msk)) {
	__ASM volatile("yield");
    }
}

#ifdef SECURE_PROC_ENV
__SPE_NSC void nsc_icache_disable(void)
{
    icache_disable();
}

__SPE_NSC void nsc_icache_enable(void)
{
    icache_enable();
}

__SPE_NSC void nsc_icache_flush(void)
{
    icache_flush();
}
#endif
