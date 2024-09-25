/**
 ******************************************************************************
 *
 * @file brwnout.c
 *
 * @brief Brownout Driver
 *
 * Copyright (C) Atmosic 2022-2024
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
#include "rep_vec.h"
#include "pmu_cfg.h"
#include "pmu.h"
#include "reset.h"
#ifndef CONFIG_SOC_FAMILY_ATM
#include "pseq.h"
#include "interrupt.h"
#include "sw_event.h"
#include "sw_timer.h"
#include "gadc.h"
#include "timer.h"
#else
#include "power.h"
#include "atm_bp_clock.h"

LOG_MODULE_REGISTER(brownout, LOG_LEVEL_INF);
#undef DEBUG_TRACE
#define DEBUG_TRACE(fmt, ...) LOG_INF(fmt, ##__VA_ARGS__)
#define DT_DRV_COMPAT atmosic_brownout
#endif

#define BROWNOUT_INTERNAL_GUARD
#include "brwnout_internal.h"

#ifdef CONFIG_BROWNOUT_THR_VBAT
#define BRWNOUT_THR_VBAT CONFIG_BROWNOUT_THR_VBAT
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
#ifndef WAKEUP_THR_VBATLI
#ifdef BATT_MODEL_HSC
#define WAKEUP_THR_VBATLI 26
#else
#define WAKEUP_THR_VBATLI 31
#endif
#endif // WAKEUP_THR_VBATLI
#ifndef BRWNOUT_MON_INTV_ACTIVE_MIN
#define BRWNOUT_MON_INTV_ACTIVE_MIN 2
#endif
#ifndef BRWNOUT_MON_INTV_LOW_PWR_MIN
#define BRWNOUT_MON_INTV_LOW_PWR_MIN 60
#endif
#ifndef BRWNOUT_THR_VBATLI
#ifdef BATT_MODEL_HSC
#define BRWNOUT_THR_VBATLI 2.8f
#else
#define BRWNOUT_THR_VBATLI 3.25f
#endif
#endif // BRWNOUT_THR_VBATLI
#if (BATT_TYPE != BATT_TYPE_LI_ION)
#define GOODTOSTART_THR_DEFAULT 0
#define GOODTOSTART_THR_BRWNOUT 3
#endif

static bool brwnout_stat;
static bool brwnout_disabled;
#ifndef CONFIG_SOC_FAMILY_ATM
static sw_event_id_t brwnout_event_id;
#endif
#if (BATT_TYPE == BATT_TYPE_LI_ION)
static uint32_t brwnout_check_ts;
static bool brwnout_detect;
static sw_event_id_t brwnout_check_id;
#endif

static void brwnout_plf_off(void)
{
    // Set wake_only_if_enough_energy
#if (BATT_TYPE == BATT_TYPE_LI_ION)
    pmu_set_brwnout_thr_vbat(WAKEUP_THR_VBATLI);
#if !(defined(BOOST_FROM_VHARV_INDUCTOR) || defined(BOOST_FROM_VHARV_TWO_DIODE))
    pmu_extend_brwnout_period(true);
#endif // BOOST_FROM_VHARV_INDUCTOR || BOOST_FROM_VHARV_TWO_DIODE
#else
    pmu_set_good2start_thr_vstore(GOODTOSTART_THR_BRWNOUT);

    uint32_t pmu_status;
    WRPR_CTRL_PUSH(CMSDK_PSEQ, WRPR_CTRL__CLK_ENABLE) {
	pmu_status = CMSDK_PSEQ->PMU_STATUS;
    } WRPR_CTRL_POP();
    DEBUG_TRACE("pmu stat: %#" PRIx32, pmu_status);
#endif // (BATT_TYPE == BATT_TYPE_LI_ION)
    pmu_set_socoff_energy_wakeup(true);

    // Any non-zero duration should be fine since all we need is for the
    // timer to wake up the chip from the SOC off state. Since it is in
    // response to a brownout event, that gate should already be in place
    // to ensure that the chip will wake up only once enough energy has
    // been accumulated.
#define WAKEUP_DURATION 10
#ifndef CONFIG_SOC_FAMILY_ATM
    pseq_soc_off(WAKEUP_DURATION);
#else
#ifdef CONFIG_PM
    atm_pseq_soc_off(WAKEUP_DURATION);
#endif
#endif
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

#if (BATT_TYPE == BATT_TYPE_LI_ION)
__FAST static rep_vec_err_t
brwnout_prevent_hib(bool *prevent, int32_t *pseq_dur, int32_t ble_dur)
{
    if (!brwnout_disabled && !brwnout_detect &&
	(!(*pseq_dur) || (atm_lpc_to_cs(*pseq_dur) > 
	(BRWNOUT_MON_INTV_LOW_PWR_MIN * CS_PER_MINUTE)))) {
	*pseq_dur = atm_cs_to_lpc(BRWNOUT_MON_INTV_LOW_PWR_MIN * CS_PER_MINUTE);
    }
    return (RV_NEXT);
}

static void batt_process_vbat(float result, struct gadc_fifo_s raw_fifo,
    struct gadc_cal_s cal, gadc_cb_ctx_t const *ctx)
{
    brwnout_check_ts = atm_lpc_to_ms(atm_get_sys_time());
    if (result < BRWNOUT_THR_VBATLI) {
	brwnout_detect = true;
#ifndef CONFIG_SOC_FAMILY_ATM
	sw_event_set(brwnout_event_id);
#endif
    }
}

static void brwnout_check_async(sw_event_id_t event_id,
    __UNUSED const void *context)
{
    ASSERT_ERR(event_id == brwnout_check_id);
    sw_event_clear(brwnout_check_id);
    gadc_sample_channel(LI_ION_BATT, batt_process_vbat,
	LI_ION_BATT_GEXT_DEFAULT, NULL);
}

__FAST static rep_vec_err_t brwnout_back_from_retain_all(void)
{
    if (brwnout_disabled) {
	return (RV_NEXT);
    }

    uint32_t cur = atm_lpc_to_ms(atm_get_sys_time());
    if ((cur - brwnout_check_ts) >
	(BRWNOUT_MON_INTV_ACTIVE_MIN * MS_PER_SEC * SEC_PER_MIN)) {
	sw_event_set(brwnout_check_id);
    }

    return (RV_NEXT);
}
#else
__FAST void PMU_Handler(void)
{
    // Clear brwnout interrupt
    brwnout_clear_intr();

    if (brwnout_disabled) {
	return;
    }

    NVIC_DisableIRQ(PMU_IRQn);

#ifndef CONFIG_SOC_FAMILY_ATM
    // Allow any interrupted operation to finish before soc off
    sw_event_set(brwnout_event_id);
#else
    k_work_submit(&brwnout_event);
#endif
}

#ifdef CONFIG_SOC_FAMILY_ATM
static void brwnout_isr(void *arg)
{
    ARG_UNUSED(arg);
    PMU_Handler();
}
#endif

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
    pmu_set_brwnout_thr_vstore(BRWNOUT_THR_VSTORE);
    pmu_set_good2start_thr_vstore(GOODTOSTART_THR_DEFAULT);
}
#endif // BATT_TYPE != BATT_TYPE_LI_ION

static rep_vec_err_t brwnout_appm_init(void)
{
#ifndef CONFIG_SOC_FAMILY_ATM
    brwnout_event_id = sw_event_alloc(brwnout_plf_off_async, NULL);
#endif

#if (BATT_TYPE == BATT_TYPE_LI_ION)
    brwnout_check_id = sw_event_alloc(brwnout_check_async, NULL);
    gadc_sample_channel(LI_ION_BATT, batt_process_vbat,
	LI_ION_BATT_GEXT_DEFAULT, NULL);
#else
    brwnout_enable_intr();
    NVIC_ClearPendingIRQ(PMU_IRQn);
    NVIC_EnableIRQ(PMU_IRQn);
#endif

    return (RV_NEXT);
}

#ifndef CONFIG_SOC_FAMILY_ATM
__attribute__((constructor))
#endif
static void brwnout_init(void)
{
#if (BATT_TYPE != BATT_TYPE_LI_ION)
    if (is_boot_reason(BOOT_STATUS_HIB_WKUP_BROWNOUT)) {
	brwnout_plf_off();
    }
#endif

    pmu_set_socoff_energy_wakeup(false);

#if (BATT_TYPE == BATT_TYPE_LI_ION)
    pmu_clear_brwnout_thr_vbat();
#if !(defined(BOOST_FROM_VHARV_INDUCTOR) || defined(BOOST_FROM_VHARV_TWO_DIODE))
    pmu_extend_brwnout_period(false);
#endif // BOOST_FROM_VHARV || BOOST_FROM_VHARV_TWO_DIODE
    RV_PLF_BACK_FROM_RETAIN_ALL_ADD(brwnout_back_from_retain_all);
    RV_PLF_PREVENT_HIBERNATION_ADD_LAST(brwnout_prevent_hib);
    ASSERT_ERR(BRWNOUT_MON_INTV_ACTIVE_MIN <= (atm_lpc_to_ms(UINT_MAX) /
	(MS_PER_SEC * SEC_PER_MIN)));
#else
    brwnout_set_thresholds();
#ifndef CONFIG_SOC_FAMILY_ATM
    interrupt_install(PMU_IRQn, INTISR_SRC_PMU, IRQ_PRI_UI, PMU_Handler);
#else
    IRQ_CONNECT(DT_INST_IRQN(0), DT_INST_IRQ(0, priority), brwnout_isr, DEVICE_DT_INST_GET(0), 0);
    irq_enable(DT_INST_IRQN(0));
#endif
#endif // (BATT_TYPE == BATT_TYPE_LI_ION)

#ifndef CONFIG_SOC_FAMILY_ATM
    RV_APPM_INIT_ADD(brwnout_appm_init);
#else
    brwnout_appm_init();
#endif
}

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
