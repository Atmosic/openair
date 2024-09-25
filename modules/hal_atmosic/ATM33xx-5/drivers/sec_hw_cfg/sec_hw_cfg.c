/**
 *******************************************************************************
 *
 * @file sec_hw_cfg.c
 *
 * @brief Early and secure hardware configuration
 *
 * Copyright (C) Atmosic 2022-2024
 *
 *******************************************************************************
 */
#ifdef CONFIG_SOC_FAMILY_ATM
#include <zephyr/kernel.h>
#include <soc.h>
#include <zephyr/init.h>
#endif

#include "arch.h"
#include "at_clkrstgen.h"

#include "sec_hw_cfg.h"

#define SEC_HW_CFG_INTERNAL_GUARD
#include "sec_hw_cfg_internal.h"

static void bootloader_pseq_init(void)
{
#ifndef USE_RAMBOOT
    if (SYS_CTRL_REG->RESET_SYNDROME !=
	SYS_CTRL_REG_SSE200_RESET_SYNDROME_PoR_Msk) {
	return;
    }
#endif

    sec_hw_cfg_core_pseq_init();
}

#if defined(CONFIG_SOC_FAMILY_ATM)
#if DT_NODE_HAS_PROP(DT_NODELABEL(sysclk), clock_frequency)
#define INIT_BP_FREQ DT_PROP(DT_NODELABEL(sysclk), clock_frequency)
#endif
#endif // CONFIG_SOC_FAMILY_ATM

#ifndef INIT_BP_FREQ
#ifdef IS_FOR_SIM
#define INIT_BP_FREQ 96000000U
#else
#define INIT_BP_FREQ 16000000U
#endif
#endif // INIT_BP_FREQ

#ifdef USE_RAMBOOT
#define RAMBOOT true
#else
#define RAMBOOT false
#endif

#ifndef CONFIG_SOC_FAMILY_ATM
__CONSTRUCTOR_PRIO(CONSTRUCTOR_WATCHDOG)
// NOTE: constructor function must be static for priority to be applied
#endif
static void sec_hw_pmu_set_bp(void)
{
    at_clkrstgen_set_bp_hint(INIT_BP_FREQ, true, false);
    sec_hw_cfg_core_pmu_set_bp(INIT_BP_FREQ, RAMBOOT);
    at_clkrstgen_set_bp_hint(INIT_BP_FREQ, false, true);
}

void sec_hw_cfg_init(void)
{
    bootloader_pseq_init();
    sec_hw_cfg_core_init();
}

#ifdef CONFIG_SOC_FAMILY_ATM
static int sec_hw_cfg_sys_init(void)
{
    sec_hw_pmu_set_bp();
    return 0;
}

SYS_INIT(sec_hw_cfg_sys_init, PRE_KERNEL_1, 0);
#endif
