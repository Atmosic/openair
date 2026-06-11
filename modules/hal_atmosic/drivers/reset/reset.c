/**
 ******************************************************************************
 *
 * @file reset.c
 *
 * @brief Reset Driver
 *
 * Copyright (C) Atmosic 2022-2026
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 *
 ******************************************************************************
 */

#ifdef CONFIG_SOC_FAMILY_ATM
#include <zephyr/kernel.h>
#include <soc.h>
#include <zephyr/init.h>
#endif

#include "arch.h"
#include <inttypes.h>
#include "reset.h"
#if !defined(CONFIG_SOC_FAMILY_ATM) || defined(CONFIG_ATM_PMU)
#include "spi.h"
#include "pmu.h"
#include "pmu_spi.h"
#include "pmu_top_regs_core_macro.h"
#endif
#include "at_wrpr.h"
#include "at_apb_pseq_regs_core_macro.h"
#include "sec_reset.h"
#include "pseq_status.h"

#if defined(CMSDK_SYSCON) || defined(SYS_CTRL_REG)
static uint32_t reset_syndrome;
#endif

boot_status_t boot_status(void)
{
#ifdef CMSDK_SYSCON
    if (reset_syndrome & CMSDK_SYSCON_RSTINFO_LOCKUPRESET_Msk) {
	return BOOT_STATUS_RESET_LOCKUP;
    }

    if (reset_syndrome & CMSDK_SYSCON_RSTINFO_WDOGRESETREQ_Msk) {
	return BOOT_STATUS_RESET_WDOG;
    }

    if (reset_syndrome & CMSDK_SYSCON_RSTINFO_SYSRESETREQ_Msk) {
	return BOOT_STATUS_RESET_SYS;
    }
#endif

#ifdef SYS_CTRL_REG
    if (reset_syndrome & (SYS_CTRL_REG_SSE200_RESET_SYNDROME_LOCKUP0_Msk |
	SYS_CTRL_REG_SSE200_RESET_SYNDROME_LOCKUP1_Msk)) {
	/* LOCKUP0 and LOCKUP1 do not generate reset, but when HIGH, indicate
	 * that a processor has locked-up and could be a precursor to another
	 * reset event, for example, a watchdog timer reset request */
	return BOOT_STATUS_RESET_LOCKUP;
    }

    if (reset_syndrome & SYS_CTRL_REG_SSE200_RESET_SYNDROME_NSWD_Msk) {
	return BOOT_STATUS_RESET_WDOG;
    }

    if (reset_syndrome &
	(SYS_CTRL_REG_SSE200_RESET_SYNDROME_SWD_Msk |
	    SYS_CTRL_REG_SSE200_RESET_SYNDROME_S32KWD_Msk)) {
	return BOOT_STATUS_RESET_SWDOG;
    }

    if (reset_syndrome & (SYS_CTRL_REG_SSE200_RESET_SYNDROME_SYSRSTREQ0_Msk |
	SYS_CTRL_REG_SSE200_RESET_SYNDROME_SYSRSTREQ1_Msk)) {
	return BOOT_STATUS_RESET_SYS;
    }

    if (reset_syndrome & SYS_CTRL_REG_SSE200_RESET_SYNDROME_SWRESETREQ_Msk) {
	return BOOT_STATUS_RESET_SW;
    }

    if (reset_syndrome & SYS_CTRL_REG_SSE200_RESET_SYNDROME_RESETREQ_Msk) {
	return BOOT_STATUS_RESET_EXT;
    }
#endif

    uint32_t pseq_boot_status;
#ifdef PSEQ_STATUS__BROWNOUT_TRIGGERED__MASK
    uint32_t pseq_ctrl1;
#endif
#ifdef __PSEQ_WDOG_STATUS_MACRO__
    uint32_t pseq_wdog_status;
#endif
    WRPR_CTRL_SET(CMSDK_PSEQ, WRPR_CTRL__CLK_ENABLE);
    {
	pseq_boot_status = CMSDK_PSEQ->STATUS & PSEQ_STATUS__POWER_ON_REASONS;
#ifdef PSEQ_STATUS__BROWNOUT_TRIGGERED__MASK
	pseq_ctrl1 = CMSDK_PSEQ->CTRL1;
#endif
#ifdef __PSEQ_WDOG_STATUS_MACRO__
	pseq_wdog_status = CMSDK_PSEQ->WDOG_STATUS;
#endif
    }
    WRPR_CTRL_SET(CMSDK_PSEQ, WRPR_CTRL__CLK_DISABLE);

    boot_status_t status = 0;

    if (!pseq_boot_status) {
#if !defined(CONFIG_SOC_FAMILY_ATM) || defined(CONFIG_ATM_PMU)
	uint8_t pmu_wkup_det = pmu_get_wkup_det();
	if (!pmu_wkup_det) {
#ifdef SYS_CTRL_REG
	    ASSERT_ERR(reset_syndrome &
		SYS_CTRL_REG_SSE200_RESET_SYNDROME_PoR_Msk);
#endif
#ifdef PMU_PMU_RB5__SOC_WDOG_RESET__READ
	    if (pmu_get_soc_wdog_reset()) {
		return BOOT_STATUS_SOC_RESET_PSEQ_WDOG;
	    }
#endif
#ifdef __PMU_PMU_WDOG_CTRL_MACRO__
	    if (pmu_get_pmu_wdog_reset()) {
		return BOOT_STATUS_SOC_RESET_PMU_WDOG;
	    }
#endif
	    return BOOT_STATUS_POWER_ON;
	}
	if (pmu_wkup_det & PMU_WKUP_PIN) {
	    status |= BOOT_STATUS_SOCOFF_WKUP_PIN;
	}
	if (pmu_wkup_det & PMU_WKUP_LPCOMP) {
	    status |= BOOT_STATUS_SOCOFF_WKUP_LPCOMP;
	}
	if (pmu_wkup_det & PMU_WKUP_TIMER) {
	    status |= BOOT_STATUS_SOCOFF_WKUP_TIMER;
	}
#else // !CONFIG_SOC_FAMILY_ATM || CONFIG_ATM_PMU
	return BOOT_STATUS_POWER_ON;
#endif // !CONFIG_SOC_FAMILY_ATM || CONFIG_ATM_PMU
    } else {
#ifdef PSEQ_STATUS__BTIME_PWD_LOW_TRIGGERED__READ
	if (pseq_boot_status & (PSEQ_STATUS__BTIME_PWD_LOW_TRIGGERED__MASK |
	    PSEQ_STATUS__BTIME_RFWAKE_TRIGGERED__MASK)) {
	    uint8_t src = PSEQ_WDOG_STATUS__SRC__READ(pseq_wdog_status);
	    if (src & PSEQ_WDOG_STATUS__SRC__WDOG) {
		return BOOT_STATUS_SOC_RESET_WDOG;
	    }
	    if (src & PSEQ_WDOG_STATUS__SRC__PSEQ_WDOG) {
		return BOOT_STATUS_SOC_RESET_PSEQ_WDOG;
	    }
	    if (src & PSEQ_WDOG_STATUS__SRC__SW) {
		return BOOT_STATUS_SOC_RESET_SW;
	    }

	    if (PSEQ_STATUS__BTIME_RFWAKE_TRIGGERED__READ(pseq_boot_status)) {
		return BOOT_STATUS_POWER_ON_RFWAKE;
	    }
	    return BOOT_STATUS_POWER_ON;
	}
#endif
#ifdef PSEQ_STATUS__TIMER_TRIGGERED__MASK
	if (pseq_boot_status & PSEQ_STATUS__TIMER_TRIGGERED__MASK) {
	    status |= BOOT_STATUS_HIB_WKUP_TIMER;
	}
#endif
#ifdef PSEQ_STATUS__GPIO_TRIGGERED__MASK
	if (pseq_boot_status & PSEQ_STATUS__GPIO_TRIGGERED__MASK) {
	    status |= BOOT_STATUS_HIB_WKUP_GPIO;
	}
#endif
#ifdef PSEQ_STATUS__WURX0_TRIGGERED__MASK
	if (pseq_boot_status & PSEQ_STATUS__WURX0_TRIGGERED__MASK) {
	    status |= BOOT_STATUS_HIB_WKUP_WURX0;
	}
#endif
#ifdef PSEQ_STATUS__WURX1_TRIGGERED__MASK
	if (pseq_boot_status & PSEQ_STATUS__WURX1_TRIGGERED__MASK) {
	    status |= BOOT_STATUS_HIB_WKUP_WURX1;
	}
#endif
#ifdef PSEQ_STATUS__QDEC_TRIGGERED__MASK
	if (pseq_boot_status & PSEQ_STATUS__QDEC_TRIGGERED__MASK) {
	    status |= BOOT_STATUS_HIB_WKUP_QDEC;
	}
#endif
#ifdef PSEQ_STATUS__KSM_TRIGGERED__MASK
	if (pseq_boot_status & PSEQ_STATUS__KSM_TRIGGERED__MASK) {
	    status |= BOOT_STATUS_HIB_WKUP_KSM;
	}
#endif
#ifdef PSEQ_STATUS__DBG_TRIGGERED__MASK
	if (pseq_boot_status & PSEQ_STATUS__DBG_TRIGGERED__MASK) {
	    status |= BOOT_STATUS_HIB_WKUP_DBG;
	}
#endif
#ifdef PSEQ_STATUS__SHUB_TRIGGERED__MASK
	if (pseq_boot_status & PSEQ_STATUS__SHUB_TRIGGERED__MASK) {
	    status |= BOOT_STATUS_HIB_WKUP_SHUB;
	}
#endif
#ifdef PSEQ_STATUS__SPI_TRIGGERED__MASK
	if (pseq_boot_status & PSEQ_STATUS__SPI_TRIGGERED__MASK) {
	    status |= BOOT_STATUS_HIB_WKUP_SPI;
	}
#endif
#ifdef PSEQ_STATUS__I2C_TRIGGERED__MASK
	if (pseq_boot_status & PSEQ_STATUS__I2C_TRIGGERED__MASK) {
	    status |= BOOT_STATUS_HIB_WKUP_I2C;
	}
#endif
#ifdef PSEQ_STATUS__PMU_TIMER_TRIGGERED__MASK
	if (pseq_boot_status & PSEQ_STATUS__PMU_TIMER_TRIGGERED__MASK) {
	    status |= BOOT_STATUS_HIB_WKUP_PMU_TIMER;
	}
#endif
#ifdef PSEQ_STATUS__PMU_LPCOMP_TRIGGERED__MASK
	if (pseq_boot_status & PSEQ_STATUS__PMU_LPCOMP_TRIGGERED__MASK) {
	    status |= BOOT_STATUS_HIB_WKUP_PMU_LPCOMP;
	}
#endif
#ifdef PSEQ_STATUS__ENERGY4CPU_TRIGGERED__MASK
	if (pseq_boot_status & PSEQ_STATUS__ENERGY4CPU_TRIGGERED__MASK) {
	    status |= BOOT_STATUS_HIB_WKUP_ENERGY4CPU;
	}
#endif
#ifdef PSEQ_STATUS__ENERGY4TX_TRIGGERED__MASK
	if (pseq_boot_status & PSEQ_STATUS__ENERGY4TX_TRIGGERED__MASK) {
	    status |= BOOT_STATUS_HIB_WKUP_ENERGY4TX;
	}
#endif
#ifdef PSEQ_STATUS__ENDOFLIFE_TRIGGERED__MASK
	if (pseq_boot_status & PSEQ_STATUS__ENDOFLIFE_TRIGGERED__MASK) {
	    status |= BOOT_STATUS_HIB_WKUP_ENDOFLIFE;
	}
#endif
#ifdef PSEQ_STATUS__BROWNOUT_TRIGGERED__MASK
	if (pseq_boot_status & PSEQ_STATUS__BROWNOUT_TRIGGERED__MASK) {
	    status |= BOOT_STATUS_HIB_WKUP_BROWNOUT;
	    uint32_t brownout_sel = PSEQ_CTRL1__BROWNOUT_SEL__READ(pseq_ctrl1);
	    if (brownout_sel == 1) {
		// Device is waking up from hibernation due to brownout asserted
		status |= BOOT_STATUS_HIB_WKUP_BROWNOUT_RISING;
	    } else if (brownout_sel == 2) {
		// Device is waking up from hibernation due to brownout cleared
		status |= BOOT_STATUS_HIB_WKUP_BROWNOUT_FALLING;
	    }
	}
#endif
#ifdef PSEQ_STATUS__WURX_TRIGGERED__MASK
	if (pseq_boot_status & PSEQ_STATUS__WURX_TRIGGERED__MASK) {
	    status |= BOOT_STATUS_HIB_WKUP_WURX;
	}
#endif
#ifdef __PMU_PMU_WDOG_CTRL_MACRO__
	if (pseq_boot_status & PSEQ_STATUS__PMU_WDOG_WARN_TRIGGERED__MASK) {
	    status |= BOOT_STATUS_HIB_WKUP_PMU_WDOG_WARN;
	}
#endif
#ifdef PSEQ_STATUS__RFWAKE_TRIGGERED__READ
	if (PSEQ_STATUS__RFWAKE_TRIGGERED__READ(pseq_boot_status)) {
	    return BOOT_STATUS_HIB_WKUP_RF;
	}
#endif
    }

#ifdef SYS_CTRL_REG
    ASSERT_INFO(status, reset_syndrome, pseq_boot_status);
#else
    ASSERT_INFO(status, 0, pseq_boot_status);
#endif

    return status;
}

#ifndef CONFIG_SOC_FAMILY_ATM
__CONSTRUCTOR_PRIO(CONSTRUCTOR_RESET)
#endif
#if !defined(CONFIG_SOC_FAMILY_ATM) || defined(CONFIG_RESET_PRINT)
static void reset_print(void)
{
#if !defined(CONFIG_SOC_FAMILY_ATM) && defined(SYS_CTRL_REG)
    reset_syndrome = secure_rclr_reset_syndrome();
#endif

    DEBUG_TRACE("boot_status = %x", boot_status());

    if (is_boot_type(TYPE_POWER_ON)) {
	DEBUG_TRACE("Cold boot");
	DEBUG_TRACE_COND(is_boot_reason(BOOT_STATUS_POWER_ON),
	    " Power on Reset");
	DEBUG_TRACE_COND(is_boot_reason(BOOT_STATUS_POWER_ON_RFWAKE),
	    " RF wake");
    }
    if (is_boot_type(TYPE_SOC_RESET)) {
	DEBUG_TRACE("SOC reset");
	DEBUG_TRACE_COND(is_boot_reason(BOOT_STATUS_SOC_RESET_PSEQ_WDOG),
	    " PSEQ WDOG");
	DEBUG_TRACE_COND(is_boot_reason(BOOT_STATUS_SOC_RESET_PMU_WDOG),
	    " PMU WDOG");
	DEBUG_TRACE_COND(is_boot_reason(BOOT_STATUS_SOC_RESET_WDOG), " WDOG");
	DEBUG_TRACE_COND(is_boot_reason(BOOT_STATUS_SOC_RESET_SW),
	    " SW Request");
    }
    if (is_boot_type(TYPE_RESET)) {
	DEBUG_TRACE("CPU reset");
	DEBUG_TRACE_COND(is_boot_reason(BOOT_STATUS_RESET_LOCKUP),
	    " CPU Lock-up Status");
	DEBUG_TRACE_COND(is_boot_reason(BOOT_STATUS_RESET_WDOG),
	    " Non Secure WDOG");
	DEBUG_TRACE_COND(is_boot_reason(BOOT_STATUS_RESET_SWDOG),
	    " Secure WDOG");
	DEBUG_TRACE_COND(is_boot_reason(BOOT_STATUS_RESET_SYS),
	    " CPU System Reset Request");
	DEBUG_TRACE_COND(is_boot_reason(BOOT_STATUS_RESET_SW),
	    " Software Reset Request");
	DEBUG_TRACE_COND(is_boot_reason(BOOT_STATUS_RESET_EXT),
	    " External Reset Request");
    }
    if (is_boot_type(TYPE_HIB)) {
	DEBUG_TRACE_COND(is_boot_reason(BOOT_STATUS_HIB_WKUP_TIMER), "timer");
	DEBUG_TRACE_COND(is_boot_reason(BOOT_STATUS_HIB_WKUP_GPIO), "gpio");
	DEBUG_TRACE_COND(is_boot_reason(BOOT_STATUS_HIB_WKUP_WURX0), "wurx0");
	DEBUG_TRACE_COND(is_boot_reason(BOOT_STATUS_HIB_WKUP_WURX1), "wurx1");
	DEBUG_TRACE_COND(is_boot_reason(BOOT_STATUS_HIB_WKUP_QDEC), "qdec");
	DEBUG_TRACE_COND(is_boot_reason(BOOT_STATUS_HIB_WKUP_KSM), "ksm");
	DEBUG_TRACE_COND(is_boot_reason(BOOT_STATUS_HIB_WKUP_DBG), "dbg");
	DEBUG_TRACE_COND(is_boot_reason(BOOT_STATUS_HIB_WKUP_SHUB), "shub");
	DEBUG_TRACE_COND(is_boot_reason(BOOT_STATUS_HIB_WKUP_SPI), "spi");
	DEBUG_TRACE_COND(is_boot_reason(BOOT_STATUS_HIB_WKUP_I2C), "i2c");
	DEBUG_TRACE_COND(is_boot_reason(BOOT_STATUS_HIB_WKUP_PMU_TIMER),
	    "pmu_timer");
	DEBUG_TRACE_COND(is_boot_reason(BOOT_STATUS_HIB_WKUP_PMU_LPCOMP),
	    "pmu_lpcomp");
	DEBUG_TRACE_COND(is_boot_reason(BOOT_STATUS_HIB_WKUP_ENERGY4CPU),
	    "energy4CPU");
	DEBUG_TRACE_COND(is_boot_reason(BOOT_STATUS_HIB_WKUP_ENERGY4TX),
	    "energy4TX");
	DEBUG_TRACE_COND(is_boot_reason(BOOT_STATUS_HIB_WKUP_ENDOFLIFE),
	    "endoflife");
	DEBUG_TRACE_COND(is_boot_reason(BOOT_STATUS_HIB_WKUP_BROWNOUT),
	    "brownout");
	DEBUG_TRACE_COND(is_boot_reason(BOOT_STATUS_HIB_WKUP_WURX), "wurx");
	DEBUG_TRACE_COND(is_boot_reason(BOOT_STATUS_HIB_WKUP_PMU_WDOG_WARN),
	    "pmu_wdog_warn");
	DEBUG_TRACE_COND(is_boot_reason(BOOT_STATUS_HIB_WKUP_BROWNOUT_RISING),
	    "brownout_rising");
	DEBUG_TRACE_COND(is_boot_reason(BOOT_STATUS_HIB_WKUP_BROWNOUT_FALLING),
	    "brownout_falling");
	DEBUG_TRACE_COND(is_boot_reason(BOOT_STATUS_HIB_WKUP_RF), "RF wake");
	DEBUG_TRACE("triggered Hiberation wakeup");
    }
    if (is_boot_type(TYPE_SOCOFF)) {
	DEBUG_TRACE_COND(is_boot_reason(BOOT_STATUS_SOCOFF_WKUP_PIN),
	    " pin triggered");
	DEBUG_TRACE_COND(is_boot_reason(BOOT_STATUS_SOCOFF_WKUP_LPCOMP),
	    " lpcomp triggered");
	DEBUG_TRACE_COND(is_boot_reason(BOOT_STATUS_SOCOFF_WKUP_TIMER),
	    " timer triggered");
	DEBUG_TRACE("SOC off wakeup");
    }
}
#endif // !defined(CONFIG_SOC_FAMILY_ATM) || defined(CONFIG_RESET_PRINT)

#ifdef CONFIG_SOC_FAMILY_ATM
static int reset_sys_init(void)
{
#ifdef CMSDK_SYSCON
    reset_syndrome = CMSDK_SYSCON->RSTINFO;
    CMSDK_SYSCON->RSTINFO = reset_syndrome;
#endif

#ifdef SYS_CTRL_REG
#ifdef CONFIG_MCUBOOT
    reset_syndrome = secure_reset_get_syndrome();
#else
    reset_syndrome = secure_rclr_reset_syndrome();
#endif
#endif // SYS_CTRL_REG

#ifdef CONFIG_RESET_PRINT
    reset_print();
#endif
    return 0;
}

SYS_INIT(reset_sys_init, PRE_KERNEL_2, 4);
#endif
