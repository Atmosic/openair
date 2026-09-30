/**
 ******************************************************************************
 *
 * @file brwnout.c
 *
 * @brief Brownout Driver
 *
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 *
 ******************************************************************************
 */

#include <zephyr/kernel.h>
#include <zephyr/init.h>
#include <zephyr/device.h>
#include <zephyr/pm/pm.h>
#include <zephyr/logging/log.h>

#include "arch.h"
#include <inttypes.h>
#include <limits.h>
#include "brwnout.h"
#include "at_wrpr.h"
#include "pmu.h"
#include "reset.h"
#include "power.h"
#include "atm_bp_clock.h"

LOG_MODULE_REGISTER(brownout, LOG_LEVEL_INF);
#undef DEBUG_TRACE
#define DEBUG_TRACE(fmt, ...) LOG_INF(fmt, ##__VA_ARGS__)
#define DT_DRV_COMPAT atmosic_brownout

#define BROWNOUT_INTERNAL_GUARD
#include "brwnout.ih"

#define BROWNOUT_THR_VBAT_MIN 3 // 0.95 V boost, 1.9 V buck
#define BROWNOUT_THR_VBAT_MAX 14 // 1.225 V boost, 2.45 V buck
#define BROWNOUT_THR_VBAT DT_INST_PROP(0, brownout_thr_vbat)
#define BROWNOUT_THR_VBAT_HYSTERESIS_DELTA \
    DT_INST_PROP(0, brownout_thr_vbat_hysteresis_delta)

#define BROWNOUT_THR_VBAT_WITH_HYSTERESIS \
    (BROWNOUT_THR_VBAT + BROWNOUT_THR_VBAT_HYSTERESIS_DELTA)

#ifdef CONFIG_BROWNOUT_IMMEDIATELY
#define BROWNOUT_RAMFUNC __ramfunc
#else
#define BROWNOUT_RAMFUNC
#endif

BROWNOUT_RAMFUNC
static void brwnout_plf_off(void)
{
    // Increase brownout threshold for hysteresis
    pmu_set_brwnout_thr(BROWNOUT_THR_VBAT_WITH_HYSTERESIS);

#ifndef CONFIG_BROWNOUT_IMMEDIATELY
    uint32_t pmu_status;
    WRPR_CTRL_PUSH(CMSDK_PSEQ, WRPR_CTRL__CLK_ENABLE) {
	pmu_status = CMSDK_PSEQ->PMU_STATUS;
    } WRPR_CTRL_POP();
    DEBUG_TRACE("pmu stat: %#" PRIx32, pmu_status);
#endif

#ifdef CONFIG_PM
    brwnout_set_trigger(2);
    atm_pseq_hibernate(0, ATM_PD_URGENCY_URGENT);
#else
    STATIC_ASSERT(false, "CONFIG_PM needs to be set for brownout support");
#endif
}

#ifndef CONFIG_BROWNOUT_IMMEDIATELY
static void brwnout_plf_off_async(struct k_work *work)
{
    brwnout_plf_off();
}

K_WORK_DEFINE(brwnout_event, brwnout_plf_off_async);
#endif

/**
 * @brief Brownout PMU interrupt handler
 *
 * Called by central PMU_Handler() in pmu.c when brownout interrupt fires.
 * The interrupt source is cleared in pmu_isr_source() before this is called.
 */
BROWNOUT_RAMFUNC
void brwnout_pmu_handler(void)
{
#ifdef CONFIG_BROWNOUT_IMMEDIATELY
    // Trigger the power-off sequence immediately in interrupt context
    brwnout_plf_off();
#else
    k_work_submit(&brwnout_event);
#endif
}

static void brwnout_init(void)
{
    if (is_boot_reason(BOOT_STATUS_HIB_WKUP_BROWNOUT_RISING)) {
	brwnout_plf_off();
    }
    STATIC_ASSERT(((BROWNOUT_THR_VBAT >= BROWNOUT_THR_VBAT_MIN) &&
		      (BROWNOUT_THR_VBAT <= BROWNOUT_THR_VBAT_MAX)),
	"Brownout threshold VBAT is not within 3..14 range");
    STATIC_ASSERT((BROWNOUT_THR_VBAT_HYSTERESIS_DELTA >= 0),
	"Brownout threshold VBAT hysteresis delta must not be negative");
    STATIC_ASSERT(((BROWNOUT_THR_VBAT + BROWNOUT_THR_VBAT_HYSTERESIS_DELTA >=
		       BROWNOUT_THR_VBAT_MIN) &&
		      (BROWNOUT_THR_VBAT + BROWNOUT_THR_VBAT_HYSTERESIS_DELTA <=
			  BROWNOUT_THR_VBAT_MAX)),
	"Brownout threshold VBAT plus hysteresis delta is not within 3..14 range");

    pmu_set_brwnout_thr(BROWNOUT_THR_VBAT);

    brwnout_enable_intr();
    NVIC_ClearPendingIRQ(PMU_IRQn);
    NVIC_EnableIRQ(PMU_IRQn);
}

__NORETURN void brwnout_force_socoff(void)
{
    brwnout_plf_off();
    while (1)
	;
}

static int brwnout_driver_init(struct device const *dev)
{
    ARG_UNUSED(dev);
    brwnout_init();

    return 0;
}

DEVICE_DT_INST_DEFINE(0, brwnout_driver_init, NULL, NULL, NULL, POST_KERNEL,
    CONFIG_KERNEL_INIT_PRIORITY_DEVICE, NULL);
