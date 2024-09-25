/**
 *******************************************************************************
 *
 * @file atm_bp_clock.c
 *
 * @brief Wrapper for atm_bp_clock related functions
 *
 * Copyright (C) Atmosic 2023-2024
 *
 *******************************************************************************
 */

#ifdef CONFIG_SOC_FAMILY_ATM
#include <zephyr/kernel.h>
#include <soc.h>
#include <zephyr/init.h>
#endif

#include <stdint.h>
#include <inttypes.h>
#include "arch.h"
#include "atm_bp_clock.h"
#define __CLKRSTGEN_GET_STATIC_INLINE __STATIC
#define __CLKRSTGEN_SET_STATIC_INLINE \
    __attribute__((section(".data_text"))) __STATIC
#include "at_clkrstgen.h"
#ifdef SECURE_MODE
#include "rep_vec.h"
#endif

#if PLF_DEBUG
static uint32_t atm_bp_clock_max_freq;
#endif

uint32_t atm_bp_clock_get(void)
{
    return at_clkrstgen_get_bp();
}

#if PLF_DEBUG
uint32_t atm_bp_clock_max_get(void)
{
    return atm_bp_clock_max_freq;
}
#endif

__attribute__((noinline, section(".data_text"))) void
atm_bp_clock_set_hint(uint32_t freq, bool set, bool commit)
{
    ASSERT_INFO(!atm_bp_clock_max_freq || (freq <= atm_bp_clock_max_freq),
	freq, atm_bp_clock_max_freq);
    at_clkrstgen_set_bp_hint(freq, set, commit);
}

__attribute__((noinline, section(".data_text"))) void
atm_bp_clock_set(uint32_t freq)
{
    ASSERT_INFO(!atm_bp_clock_max_freq || (freq <= atm_bp_clock_max_freq),
	freq, atm_bp_clock_max_freq);
    at_clkrstgen_set_bp(freq);
}

bool atm_bp_clock_critical_section_allowed(uint32_t freq)
{
#ifdef SECURE_MODE
    return true;
#else
    uint32_t min_freq = 0;
    uint32_t bp_freq = atm_bp_clock_get();
    if (bp_freq <= freq) {
	return true;
    }
    rep_vec__uint32_t__uint32_t_p__invoke(rv_plf_bp_throttle, NULL, bp_freq,
	&min_freq);
    DEBUG_TRACE_COND(min_freq > freq,
	"atm_bp_clock critical section not allowed due to bp "
	"throttle at %" PRIu32 "Hz",
	min_freq);
    return min_freq <= freq;
#endif
}

#if PLF_DEBUG
#ifndef CONFIG_SOC_FAMILY_ATM
__CONSTRUCTOR_PRIO(CONSTRUCTOR_USER_INIT)
#endif
static void atm_bp_clock_constructor(void)
{
    atm_bp_clock_max_freq = at_clkrstgen_get_bp();
}

#ifdef CONFIG_SOC_FAMILY_ATM
static int atm_bp_clock_sys_init(void)
{
    atm_bp_clock_constructor();
    return 0;
}

SYS_INIT(atm_bp_clock_sys_init, PRE_KERNEL_2, 9);
#endif
#endif
