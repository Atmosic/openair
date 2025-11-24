/**
 *******************************************************************************
 *
 * @file sec_hw_cfg.c
 *
 * @brief Early and secure hardware configuration
 *
 * Copyright (C) Atmosic 2022-2025
 *
 *******************************************************************************
 */
#ifndef SECURE_MODE
#define SECURE_MODE 1
#endif
#ifdef CONFIG_SOC_FAMILY_ATM
#include <zephyr/kernel.h>
#include <soc.h>
#include <zephyr/init.h>
#endif

#include "arch.h"
#include "at_wrpr.h"
#include "at_clkrstgen.h"
#include "rram.h"
#include "sec_jrnl.h"

#include "sec_hw_cfg.h"

#define SEC_HW_CFG_INTERNAL_GUARD
#include "sec_hw_cfg_internal.h"
#ifdef SECURE_PROC_ENV
#include "sec_service.h"
#endif

#if defined(CONFIG_SOC_FAMILY_ATM)
#if DT_NODE_HAS_PROP(DT_NODELABEL(sysclk), clock_frequency)
#define INIT_BP_FREQ DT_PROP(DT_NODELABEL(sysclk), clock_frequency)
#endif
#endif // CONFIG_SOC_FAMILY_ATM

#ifndef INIT_BP_FREQ
#ifdef IS_FOR_SIM
#define INIT_BP_FREQ 64000000U
#else
#define INIT_BP_FREQ 32000000U
#endif
#endif // INIT_BP_FREQ

#ifndef ENABLE_FL_RAM
static uint8_t rom_version;
static void read_rom_version(void)
{
    rom_version = *(uint8_t *)(CMSDK_FLASH_BASE + ROM_SIZE - sizeof(uint32_t));
}
#endif

#if !defined(CONFIG_SOC_FAMILY_ATM) || !defined(CONFIG_BOOTLOADER_MCUBOOT)
static void bootloader_clkrstgen_init(void)
{
    if (SYS_CTRL_REG->RESET_SYNDROME !=
	SYS_CTRL_REG_SSE200_RESET_SYNDROME_PoR_Msk) {
	return;
    }

    sec_hw_cfg_core_clkrstgen_init();
}

static void sec_hw_pmu_set_bp(void)
{
    bootloader_clkrstgen_init();
    at_clkrstgen_set_bp_hint(INIT_BP_FREQ, true, false);
    {
	sec_hw_cfg_core_pmu_cfg(INIT_BP_FREQ);

#ifndef USE_RAMBOOT
	// PRRF and RRAM_R live in cacheable memory space
	uint32_t icctrl = ICACHE->ICCTRL;
	ICACHE->ICCTRL = icctrl & ~ICACHE_ICCTRL_CACHEEN_Msk;

	rram_adjust_timing(INIT_BP_FREQ / 1000000);

	ICACHE->ICCTRL = icctrl;
#endif
    }
    at_clkrstgen_set_bp_hint(INIT_BP_FREQ, false, true);
// The following workaround is necessary only before Perth 2.0
#ifndef WRPRPINS_PROT_BITS_SET1__ROM_PATCH_LOCK_SET__MASK
    sec_hw_cfg_core_pmu_set_bp_workaround(INIT_BP_FREQ);
#endif
}
#endif //!defined(CONFIG_SOC_FAMILY_ATM) || !defined(CONFIG_BOOTLOADER_MCUBOOT)

#ifndef CONFIG_SOC_FAMILY_ATM
__CONSTRUCTOR_PRIO(CONSTRUCTOR_WATCHDOG)
// NOTE: constructor function must be static for priority to be applied
static void sec_hw_cfg_construct(void)
{
#ifndef ENABLE_FL_RAM
    read_rom_version();
#endif
    sec_hw_pmu_set_bp();
}
#endif

void sec_hw_cfg_init(void)
{
    REV_HASH_CHECK(CMSDK_WRPR0_SECURE, WRPRPINS);
    REV_HASH_CHECK(CMSDK_WRPR1_SECURE, WRPRSHORT);
    REV_HASH_CHECK(CMSDK_WRPR2_SECURE, WRPRSHORT);
    REV_HASH_CHECK(CMSDK_PSEQ_SECURE, PSEQ);
    ASSERT_INFO(CMSDK_AT_PRRF_SECURE->REV_HASH == AT_PRRF_REV_HASH__RESET_VALUE,
	CMSDK_AT_PRRF_SECURE->REV_HASH, AT_PRRF_REV_HASH__RESET_VALUE);

    sec_hw_cfg_core_init();
}

#ifdef CONFIG_SOC_FAMILY_ATM
static int sec_hw_cfg_sys_init(void)
{
#ifndef ENABLE_FL_RAM
    read_rom_version();
#endif
// CONFIG_BOOTLOADER_MCUBOOT is never set by MCUBoot application and is
// set by SPE only when building with MCUboot support.
#ifndef CONFIG_BOOTLOADER_MCUBOOT
    sec_hw_pmu_set_bp();
#endif
    return 0;
}

SYS_INIT(sec_hw_cfg_sys_init, PRE_KERNEL_1, 0);
#endif // CONFIG_SOC_FAMILY_ATM

#ifndef ENABLE_FL_RAM
rom_version_t sec_hw_cfg_rom_version(void)
{
    return (rom_version_t)rom_version;
}

#ifdef SECURE_PROC_ENV
__SPE_NSC rom_version_t nsc_sec_hw_cfg_rom_version(void)
{
    return sec_hw_cfg_rom_version();
}
#elif defined(CFG_NO_SPE)
rom_version_t nsc_sec_hw_cfg_rom_version(void)
    __attribute__((alias("sec_hw_cfg_rom_version")));
#endif
#endif // ENABLE_FL_RAM
