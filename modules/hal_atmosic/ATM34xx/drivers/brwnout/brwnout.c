/**
 ******************************************************************************
 *
 * @file brwnout.c
 *
 * @brief Brownout Driver
 *
 * Copyright (C) Atmosic 2022-2026
 *
 ******************************************************************************
 */

#ifdef CONFIG_SOC_FAMILY_ATM
#include <zephyr/kernel.h>
#include <zephyr/init.h>
#include <zephyr/device.h>
#include <zephyr/pm/pm.h>
#include <zephyr/logging/log.h>
#endif
#include "arch.h"
#include <inttypes.h>
#include <limits.h>
#include "brwnout.h"
#include "at_wrpr.h"
#include "pmu_cfg.h"
#include "pmu.h"
#include "reset.h"
#ifndef CONFIG_SOC_FAMILY_ATM
#include "pseq.h"
#include "interrupt.h"
#include "pinmux.h"
#include "sw_event.h"
#else
#include "power.h"
#include "atm_bp_clock.h"

LOG_MODULE_REGISTER(brownout, LOG_LEVEL_INF);
#undef DEBUG_TRACE
#define DEBUG_TRACE(fmt, ...) LOG_INF(fmt, ##__VA_ARGS__)
#define DT_DRV_COMPAT atmosic_brownout
#endif

#define BROWNOUT_INTERNAL_GUARD
#include "brwnout.ih"

#ifdef CONFIG_BROWNOUT_THR_VBAT
#define BRWNOUT_THR_VBAT CONFIG_BROWNOUT_THR_VBAT
#endif

#if defined(CONFIG_BROWNOUT_THR_VSTORE) && (CONFIG_BROWNOUT_THR_VSTORE != -1)
#define BRWNOUT_THR_VSTORE CONFIG_BROWNOUT_THR_VSTORE
#endif

#ifndef BRWNOUT_THR_VBAT
#define BRWNOUT_THR_VBAT 0
#endif
#ifndef BRWNOUT_THR_VSTORE
#if (BATT_TYPE == BATT_TYPE_RECHARGEABLE)
#define BRWNOUT_THR_VSTORE 31
#else
#define BRWNOUT_THR_VSTORE 0
#endif // BATT_TYPE == BATT_TYPE_RECHARGEABLE
#endif // BRWNOUT_THR_VSTORE

#define BRWNOUT_THR_VBAT_MAX 31

#ifdef CONFIG_BROWNOUT_THR_VBAT_HYSTERESIS_DELTA
#define BRWNOUT_THR_VBAT_HYSTERESIS_DELTA \
    CONFIG_BROWNOUT_THR_VBAT_HYSTERESIS_DELTA
#else
#define BRWNOUT_THR_VBAT_HYSTERESIS_DELTA 10
#endif

#ifndef MIN
#define MIN(x, y) (((x) < (y)) ? (x) : (y))
#endif

#define BRWNOUT_THR_VBAT_WITH_HYSTERESIS \
    MIN(BRWNOUT_THR_VBAT + BRWNOUT_THR_VBAT_HYSTERESIS_DELTA, \
	BRWNOUT_THR_VBAT_MAX)

#if (BATT_TYPE != BATT_TYPE_LI_ION)
#define GOODTOSTART_THR_DEFAULT 0
#define GOODTOSTART_THR_BRWNOUT 3
#endif

static bool brwnout_stat;
static bool brwnout_disabled;
#ifndef CONFIG_SOC_FAMILY_ATM
static sw_event_id_t brwnout_event_id;
#endif

static void brwnout_plf_off(void)
{
    // Increase VBAT brownout threshold for hysteresis
    pmu_set_brwnout_thr_vbat(BRWNOUT_THR_VBAT_WITH_HYSTERESIS);

    // Set wake_only_if_enough_energy
#if (BATT_TYPE != BATT_TYPE_LI_ION) && !defined(CONFIG_SOC_FAMILY_ATM)
    pmu_set_good2start_thr_vstore(GOODTOSTART_THR_BRWNOUT);
#endif

    uint32_t pmu_status;
    WRPR_CTRL_PUSH(CMSDK_PSEQ, WRPR_CTRL__CLK_ENABLE) {
	pmu_status = CMSDK_PSEQ->PMU_STATUS;
    } WRPR_CTRL_POP();
    DEBUG_TRACE("pmu stat: %#" PRIx32, pmu_status);

#ifndef CONFIG_SOC_FAMILY_ATM
    pmu_set_socoff_energy_wakeup(true);

#if (BATT_LEVEL == BATT_LEVEL_LE_1P8V)
    pmu_set_socoff_swreg_override(true);
#endif

    // Any non-zero duration should be fine since all we need is for the
    // timer to wake up the chip from the hibernation state. Since it is in
    // response to a brownout event, that gate should already be in place
    // to ensure that the chip will wake up only once enough energy has
    // been accumulated.
#define WAKEUP_DURATION 10
    pseq_soc_off(WAKEUP_DURATION);
#else // CONFIG_SOC_FAMILY_ATM
#ifdef CONFIG_PM
    brwnout_set_trigger(2);
    atm_pseq_hibernate(IDLE_FOREVER);
#else
    STATIC_ASSERT(false, "CONFIG_PM needs to be set for brownout support");
#endif
#endif // CONFIG_SOC_FAMILY_ATM
}

#ifndef CONFIG_SOC_FAMILY_ATM
static void brwnout_plf_off_async(sw_event_id_t event_id,
    __UNUSED const void *context)
{
    ASSERT_ERR(event_id == brwnout_event_id);
    sw_event_clear(brwnout_event_id);
    brwnout_plf_off();
}
#else
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
void brwnout_pmu_handler(void)
{
    if (brwnout_disabled) {
	return;
    }

#ifndef CONFIG_SOC_FAMILY_ATM
    // Allow any interrupted operation to finish before hibernation
    sw_event_set(brwnout_event_id);
#else
    k_work_submit(&brwnout_event);
#endif
}

static void brwnout_set_thresholds(void)
{
    STATIC_ASSERT(((BRWNOUT_THR_VBAT >= 0) && (BRWNOUT_THR_VBAT <= 31)),
	"Brownout threshold VBAT is not within 0..31 range");
    STATIC_ASSERT(((BRWNOUT_THR_VSTORE >= 0) && (BRWNOUT_THR_VSTORE <= 31)),
	"Brownout threshold VSTORE is not within 0..31 range");
#if (BATT_TYPE == BATT_TYPE_RECHARGEABLE)
    STATIC_ASSERT((BRWNOUT_THR_VSTORE == 31),
	"Brownout threshold VSTORE cannot be overridden");
#if (BATT_LEVEL == BATT_LEVEL_GT_1P8V)
    STATIC_ASSERT((BRWNOUT_THR_VBAT <= 17),
	"Brownout threshold VBAT is not within 0..17 range");
#endif // (BATT_LEVEL == BATT_LEVEL_GT_1P8V)
#endif // (BATT_TYPE == BATT_TYPE_RECHARGEABLE)

    pmu_set_brwnout_thr_vbat(BRWNOUT_THR_VBAT);
#if (BATT_TYPE != BATT_TYPE_LI_ION)
    pmu_set_brwnout_thr_vstore(BRWNOUT_THR_VSTORE);
#ifndef CONFIG_SOC_FAMILY_ATM
    pmu_set_good2start_thr_vstore(GOODTOSTART_THR_DEFAULT);
#endif
#endif
}

static rep_vec_err_t brwnout_appm_init(void)
{
#ifndef CONFIG_SOC_FAMILY_ATM
    brwnout_event_id = sw_event_alloc(brwnout_plf_off_async, NULL);
#endif

    brwnout_enable_intr();
    NVIC_ClearPendingIRQ(PMU_IRQn);
    NVIC_EnableIRQ(PMU_IRQn);


    return (RV_NEXT);
}

#ifdef CONFIG_SOC_FAMILY_ATM
static void brwnout_init(void)
{
    if (is_boot_reason(BOOT_STATUS_HIB_WKUP_BROWNOUT_RISING)) {
	brwnout_plf_off();
    }
    brwnout_set_thresholds();
    brwnout_appm_init();
}
#else
__attribute__((constructor))
static void brwnout_init(void)
{
    if (is_boot_reason(BOOT_STATUS_HIB_WKUP_BROWNOUT)) {
	brwnout_plf_off();
    }
    pmu_set_socoff_energy_wakeup(false);
    brwnout_set_thresholds();
    interrupt_install(PMU_IRQn, INTISR_SRC_PMU, IRQ_PRI_UI, PMU_Handler);
    RV_APPM_INIT_ADD(brwnout_appm_init);
}
#endif

__NORETURN void brwnout_force_socoff(void)
{
    brwnout_plf_off();
    while(1);
}

void brwnout_enable(void)
{
    brwnout_disabled = false;
}

void brwnout_disable(void)
{
    brwnout_disabled = true;
}

bool brwnout_status(void)
{
    return brwnout_stat;
}

#ifdef CONFIG_SOC_FAMILY_ATM
static int brwnout_driver_init(struct device const *dev)
{
    ARG_UNUSED(dev);
    brwnout_init();

    return 0;
}

DEVICE_DT_INST_DEFINE(0, brwnout_driver_init, NULL, NULL, NULL,
		      POST_KERNEL, CONFIG_KERNEL_INIT_PRIORITY_DEVICE,
		      NULL);
#endif
