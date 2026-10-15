/**
 ******************************************************************************
 *
 * @file pmu.c
 *
 * @brief Power Management Unit Driver
 *
 * Copyright (C) Atmosic 2021-2026
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 *
 ******************************************************************************
 */

#ifdef CONFIG_SOC_FAMILY_ATM
#include <zephyr/kernel.h>
#include <soc.h>
#include <zephyr/init.h>
#include <zephyr/irq.h>
#endif

#include "arch.h"
#include <inttypes.h>
#include <string.h>
#include "at_wrpr.h"
#include "at_pinmux.h"
#include "pmu.h"
#include "at_clkrstgen.h"
#include "atm_bp_clock.h"
#ifdef CONFIG_ATM_BROWNOUT
#include "brwnout.h"
#endif
#define PMU_INTERNAL_GUARD
#include "pmu.ih"
#include "pinmux.h"

#define DT_DRV_COMPAT atmosic_atmx3_pmu

static void pmu_init(void)
{
    DEBUG_TRACE("%s", __func__);

    pmu_core_param param = {
	.pmu_wdog_timeout = CONFIG_PMU_WDOG_TIMEOUT,
    };

    if (!pmu_core_init(&param)) {
	DEBUG_TRACE("Invalid vstore_max or batt_type");
	return;
    }
}

/**
 * @brief Weak default watchdog PMU handler
 *
 * This default handler logs an error since no proper handler was configured.
 * The interrupt source is cleared in pmu_isr_source() before this is called.
 * For Zephyr builds, the real handler is in wdt_atmosic_unified.c when
 * CONFIG_WDT_ATMOSIC_PMU_ENABLE is set.
 */
__WEAK void wdt_pmu_handler(void)
{
    DEBUG_TRACE("ERROR: PMU watchdog warning with no handler configured!");
}

/**
 * @brief Central PMU interrupt service routine
 */
__FAST void PMU_Handler(void)
{
    bool brownout, wdog_warn;
    pmu_isr_source(&brownout, &wdog_warn);

#if defined(CONFIG_ATM_BROWNOUT)
    if (brownout) {
	brwnout_pmu_handler();
    }
#endif

    if (wdog_warn) {
	wdt_pmu_handler();
    }
}

#ifdef CONFIG_SOC_FAMILY_ATM
/**
 * @brief Direct PMU ISR for Zephyr
 *
 * Uses IRQ_DIRECT_CONNECT for lower latency interrupt handling.
 * Returns 0 since PMU handling doesn't require kernel reschedule.
 * Placed in SRAM (__FAST) to avoid flash wait states.
 */
ISR_DIRECT_DECLARE(pmu_isr)
{
    PMU_Handler();
    return 0;
}

static int pmu_sys_init(void)
{
    pmu_init();

    /* Register PMU interrupt handler using direct connect for lower latency */
    IRQ_DIRECT_CONNECT(DT_INST_IRQ_BY_NAME(0, pmu, irq),
	DT_INST_IRQ_BY_NAME(0, pmu, priority), pmu_isr, 0);
    irq_enable(DT_INST_IRQ_BY_NAME(0, pmu, irq));

    return 0;
}

SYS_INIT(pmu_sys_init, PRE_KERNEL_2, 10);
#endif
