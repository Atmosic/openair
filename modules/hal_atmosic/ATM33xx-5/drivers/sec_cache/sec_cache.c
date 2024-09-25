/**
 *******************************************************************************
 *
 * @file sec_cache.c
 *
 * @brief Secure cache driver implementation
 *
 * Copyright (C) Atmosic 2022-2024
 *
 *******************************************************************************
 */
#ifdef CFG_NO_SPE
// for no-SPE the base for the ICACHE control registers must be a secure address
#define SECURE_MODE
#endif
#include "arch.h"
#include "sec_service.h"
#include "sec_cache.h"

#ifndef SECURE_MODE
#error "sec_cache is a secure-only driver"
#endif

void icache_disable(void)
{
    ICACHE->ICCTRL &= ~ICACHE_ICCTRL_CACHEEN_Msk;
}

void icache_enable(void)
{
    ICACHE->ICIRQSCLR |= ICACHE_ICIRQSTAT_IC_STATUS_Msk;
    ICACHE->ICCTRL |= ICACHE_ICCTRL_FINV_Msk | ICACHE_ICCTRL_CACHEEN_Msk;
}

void icache_flush(void)
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
__attribute__((cmse_nonsecure_entry)) __attribute__((used)) void
nsc_icache_disable(void)
{
    icache_disable();
}

__attribute__((cmse_nonsecure_entry)) __attribute__((used)) void
nsc_icache_enable(void)
{
    icache_enable();
}

__attribute__((cmse_nonsecure_entry)) __attribute__((used)) void
nsc_icache_flush(void)
{
    icache_flush();
}

#endif

