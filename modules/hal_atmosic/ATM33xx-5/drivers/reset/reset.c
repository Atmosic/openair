/**
 ******************************************************************************
 *
 * @file reset.c
 *
 * @brief Reset Driver
 *
 * Copyright (C) Atmosic 2022-2023
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
#include "spi.h"
#include "reset.h"
#include "pmu.h"
#include "pmu_spi.h"
#include "at_wrpr.h"
#include "at_apb_pseq_regs_core_macro.h"
#include "pmu_top_regs_core_macro.h"
#include "sec_reset.h"
#include "pseq_status.h"

static uint32_t reset_syndrome;

boot_status_t boot_status(void)
{
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

    uint32_t pseq_boot_status;
    WRPR_CTRL_SET(CMSDK_PSEQ, WRPR_CTRL__CLK_ENABLE);
    {
	pseq_boot_status = CMSDK_PSEQ->STATUS & PSEQ_STATUS__POWER_ON_REASONS;
    }
    WRPR_CTRL_SET(CMSDK_PSEQ, WRPR_CTRL__CLK_DISABLE);

    boot_status_t status = 0;

    if (!pseq_boot_status) {
	uint8_t pmu_wkup_det = pmu_get_wkup_det();
	if (!pmu_wkup_det) {
	    ASSERT_ERR(reset_syndrome &
		SYS_CTRL_REG_SSE200_RESET_SYNDROME_PoR_Msk);
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
	if (pmu_get_soc_wdog_reset()) {
	    status |= BOOT_STATUS_SOCOFF_WDOG_RESET;
	}
    } else {
	if (pseq_boot_status & PSEQ_STATUS__TIMER_TRIGGERED__MASK) {
	    status |= BOOT_STATUS_HIB_WKUP_TIMER;
	}
	if (pseq_boot_status & PSEQ_STATUS__GPIO_TRIGGERED__MASK) {
	    status |= BOOT_STATUS_HIB_WKUP_GPIO;
	}
	if (pseq_boot_status & PSEQ_STATUS__WURX0_TRIGGERED__MASK) {
	    status |= BOOT_STATUS_HIB_WKUP_WURX0;
	}
	if (pseq_boot_status & PSEQ_STATUS__WURX1_TRIGGERED__MASK) {
	    status |= BOOT_STATUS_HIB_WKUP_WURX1;
	}
	if (pseq_boot_status & PSEQ_STATUS__QDEC_TRIGGERED__MASK) {
	    status |= BOOT_STATUS_HIB_WKUP_QDEC;
	}
	if (pseq_boot_status & PSEQ_STATUS__KSM_TRIGGERED__MASK) {
	    status |= BOOT_STATUS_HIB_WKUP_KSM;
	}
	if (pseq_boot_status & PSEQ_STATUS__DBG_TRIGGERED__MASK) {
	    status |= BOOT_STATUS_HIB_WKUP_DBG;
	}
	if (pseq_boot_status & PSEQ_STATUS__SHUB_TRIGGERED__MASK) {
	    status |= BOOT_STATUS_HIB_WKUP_SHUB;
	}
	if (pseq_boot_status & PSEQ_STATUS__SPI_TRIGGERED__MASK) {
	    status |= BOOT_STATUS_HIB_WKUP_SPI;
	}
	if (pseq_boot_status & PSEQ_STATUS__I2C_TRIGGERED__MASK) {
	    status |= BOOT_STATUS_HIB_WKUP_I2C;
	}
	if (pseq_boot_status & PSEQ_STATUS__PMU_TIMER_TRIGGERED__MASK) {
	    status |= BOOT_STATUS_HIB_WKUP_PMU_TIMER;
	}
	if (pseq_boot_status & PSEQ_STATUS__PMU_LPCOMP_TRIGGERED__MASK) {
	    status |= BOOT_STATUS_HIB_WKUP_PMU_LPCOMP;
	}
	if (pseq_boot_status & PSEQ_STATUS__ENERGY4CPU_TRIGGERED__MASK) {
	    status |= BOOT_STATUS_HIB_WKUP_ENERGY4CPU;
	}
	if (pseq_boot_status & PSEQ_STATUS__ENERGY4TX_TRIGGERED__MASK) {
	    status |= BOOT_STATUS_HIB_WKUP_ENERGY4TX;
	}
	if (pseq_boot_status & PSEQ_STATUS__ENDOFLIFE_TRIGGERED__MASK) {
	    status |= BOOT_STATUS_HIB_WKUP_ENDOFLIFE;
	}
	if (pseq_boot_status & PSEQ_STATUS__BROWNOUT_TRIGGERED__MASK) {
	    status |= BOOT_STATUS_HIB_WKUP_BROWNOUT;
	}
	if (pseq_boot_status & PSEQ_STATUS__WURX_TRIGGERED__MASK) {
	    status |= BOOT_STATUS_HIB_WKUP_WURX;
	}
    }

    ASSERT_ERR(status);

    return status;
}

#ifndef CONFIG_SOC_FAMILY_ATM
__CONSTRUCTOR_PRIO(CONSTRUCTOR_RESET)
#endif
static void reset_print(void)
{
    reset_syndrome = secure_rclr_reset_syndrome();

    DEBUG_TRACE("boot_status = %x", boot_status());

    if (is_boot_type(TYPE_POWER_ON)) {
	DEBUG_TRACE("Cold boot");
	DEBUG_TRACE_COND(is_boot_type(TYPE_POWER_ON), " Power on Reset");
    }
    if (is_boot_type(TYPE_RESET)) {
	DEBUG_TRACE("System reset");
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
	DEBUG_TRACE("triggered Hiberation wakeup");
    }
    if (is_boot_type(TYPE_SOCOFF)) {
	DEBUG_TRACE_COND(is_boot_reason(BOOT_STATUS_SOCOFF_WKUP_PIN),
	    " pin triggered");
	DEBUG_TRACE_COND(is_boot_reason(BOOT_STATUS_SOCOFF_WKUP_LPCOMP),
	    " lpcomp triggered");
	DEBUG_TRACE_COND(is_boot_reason(BOOT_STATUS_SOCOFF_WKUP_TIMER),
	    " timer triggered");
	DEBUG_TRACE_COND(is_boot_reason(BOOT_STATUS_SOCOFF_WDOG_RESET),
	    " wdog forced");
	DEBUG_TRACE("SOC off wakeup");
    }
}

#ifdef CONFIG_SOC_FAMILY_ATM
static int reset_sys_init(void)
{
    reset_print();
    return 0;
}

SYS_INIT(reset_sys_init, PRE_KERNEL_2, 4);
#endif
