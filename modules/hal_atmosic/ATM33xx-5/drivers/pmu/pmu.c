/**
 ******************************************************************************
 *
 * @file pmu.c
 *
 * @brief Power Management Unit Driver
 *
 * Copyright (C) Atmosic 2021-2024
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
#include "pmu_cfg.h"
#include "pmu.h"
#include "at_wrpr.h"
#include "at_pinmux.h"
#include "atm_bp_clock.h"
#define PMU_INTERNAL_GUARD
#include "pmu_internal.h"
#include "pinmux.h"

#ifdef CONFIG_SOC_FAMILY_ATM
#define DT_DRV_COMPAT atmosic_atmx3_pmu

#if DT_NODE_HAS_PROP(DT_NODELABEL(pmu), vddio_type)
#define VDDIO_TYPE DT_PROP(DT_NODELABEL(pmu), vddio_type)
#endif

#if DT_NODE_HAS_PROP(DT_NODELABEL(pmu), vstore_max)
#define VSTORE_MAX DT_PROP(DT_NODELABEL(pmu), vstore_max)
#endif

#if DT_PROP(DT_NODELABEL(pmu), rf_harv)
#define CFG_RF_HARV
#endif

#if DT_PROP(DT_NODELABEL(pmu), nonrf_harv)
#define CFG_NONRF_HARV
#endif

#if DT_NODE_HAS_PROP(DT_NODELABEL(pmu), vharv_range)
#define VHARV_RANGE DT_PROP(DT_NODELABEL(pmu), vharv_range)
#endif

#if DT_PROP(DT_NODELABEL(pmu), vharv_ll)
#define VHARV_LL
#endif

#if DT_PROP(DT_NODELABEL(pmu), vharv_ul)
#define VHARV_UL
#endif

#if DT_NODE_HAS_PROP(DT_NODELABEL(pmu), dig_test_out_pin)
#define PIN_PMU_DIG_TEST_OUT DT_PROP(DT_NODELABEL(pmu), dig_test_out_pin)
#endif

#if DT_NODE_HAS_PROP(DT_NODELABEL(pmu), boost_io_pin)
#define PIN_BOOSTER_IO DT_PROP(DT_NODELABEL(pmu), boost_io_pin)
#endif

#if DT_PROP(DT_NODELABEL(pmu), harv_meter)
#define CFG_HARV_METER
#endif

#if DT_NODE_HAS_PROP(DT_NODELABEL(pmu), inductor_nhenry)
#define INDUCTOR_NHENRY DT_PROP(DT_NODELABEL(pmu), inductor_nhenry)
#endif
#endif // CONFIG_SOC_FAMILY_ATM

#ifndef VDDIO_TYPE
#define VDDIO_TYPE VDDIO_TYPE_INTERNAL
#endif

#ifndef VSTORE_MAX
#define VSTORE_MAX 3300
#endif

#ifdef BOOST_FROM_VHARV_INDUCTOR
#ifdef VHARV_LL
#define DIG_TEST_SEL 21
#elif defined(VHARV_UL)
#define DIG_TEST_SEL 20
#else // VHARV_LL || VHARV_UL
#error "VHARV_LL or VHARV_UL needs to be defined for BOOST_FROM_VHARV_INDUCTOR"
#endif // VHARV_LL || VHARV_UL
#endif // BOOST_FROM_VHARV_INDUCTOR

#ifdef CFG_HARV_METER
#ifndef VHARV_RANGE
#error "VHARV_RANGE needs to be defined for harvesting meter"
#endif // VHARV_RANGE
#include "sw_event.h"
#include "sw_timer.h"
#include <string.h>
#include "timer.h"
#define REF_INDUCTOR_NHENRY 3300
#ifndef INDUCTOR_NHENRY
#define INDUCTOR_NHENRY REF_INDUCTOR_NHENRY
#endif
#endif // CFG_HARV_METER

STATIC_ASSERT(((VDDIO_TYPE == VDDIO_TYPE_INTERNAL) ||
    (BATT_LEVEL != BATT_LEVEL_LE_1P8V)),
    "Unsupported combination: VDDIO disabled and BATT_LEVEL_LE_1P8V");
STATIC_ASSERT(((BATT_LEVEL >= BATT_LEVEL_LE_1P8V) &&
    (BATT_LEVEL <= BATT_LEVEL_GT_1P8V)), "Invalid battery level");

#ifdef CFG_HARV_METER
static hm_stats_t hm_stats;
static hm_status_t hm_stats_valid;
static harv_meter_cb hm_stats_update;
static sw_event_id_t hm_event_id;
static sw_timer_id_t hm_timer_id;
static uint32_t hm_stats_dur;
__FAST static rep_vec_err_t
pmu_back_from_retain_all(void)
{
    // Skip stats update if the harv meter is not running
    if (!hm_stats_update) {
	return (RV_NEXT);
    }

    sw_event_set(hm_event_id);
    return (RV_NEXT);
}

static void hm_update_timeout(uint8_t idx, void const *ctx)
{
    hm_stats_update(&hm_stats, hm_stats_valid);
}

static void hm_update_event(sw_event_id_t event_id,
    __UNUSED const void *context)
{
    ASSERT_ERR(event_id == hm_event_id);
    sw_event_clear(hm_event_id);

    pmu_update_hm_stats(&hm_stats, &hm_stats_valid);

    // Duration of 0 implies, send all the updates
    if (!hm_stats_dur) {
	hm_stats_update(&hm_stats, hm_stats_valid);
    }

    pmu_reset_harv_meter();
}
#endif

void pmu_harv_meter(void)
{
    uint32_t pmu_rb_mppt;
    bool status = pmu_harv_meter_core_init(&pmu_rb_mppt);
    if (!status) {
	DEBUG_TRACE("Harvesting meter only supported for MPPT_TYPE_DISABLED");
	ASSERT_ERR(0);
    }
    DEBUG_TRACE("pmu_rb_mppt: %#" PRIx32, pmu_rb_mppt);
#ifdef CFG_HARV_METER
    hm_event_id = sw_event_alloc(hm_update_event, NULL);
    hm_timer_id = sw_timer_alloc(hm_update_timeout, NULL);
    RV_PLF_BACK_FROM_RETAIN_ALL_ADD(pmu_back_from_retain_all);
#endif
}

hm_status_t pmu_set_harv_meter(bool enable, harv_meter_cb cb, uint32_t seconds)
{
#ifdef CFG_HARV_METER
    if (!enable) {
	hm_stats_update = NULL;
	hm_stats_dur = 0;
	memset(&hm_stats, 0, sizeof(hm_stats));
	sw_timer_clear(hm_timer_id);
	return HARV_ERR_NO_ERROR;
    }

    if (hm_stats_update) {
	return HARV_ERR_BUSY;
    }

    pmu_reset_harv_meter();
    hm_stats_update = cb;
    hm_stats_dur = seconds;
    if (seconds) {
	sw_timer_set(hm_timer_id, CS_PER_SEC * seconds);
    }

    return HARV_ERR_NO_ERROR;
#else
    return HARV_ERR_DISABLED;
#endif
}

void pmu_cfg_dbg_sig(void)
{
#if (BATT_TYPE == BATT_TYPE_LI_ION)
#ifdef BOOST_FROM_VHARV_INDUCTOR
    PINMUX_CFG_DBG_SIG(PIN_PMU_DIG_TEST_OUT, PMU_DIG_TEST_OUT);
#else
    PINMUX_CFG_DBG_SIG(PIN_BOOSTER_IO, CLK_CP);
#endif
#endif // BATT_TYPE == BATT_TYPE_LI_ION
}

#ifndef CONFIG_SOC_FAMILY_ATM
__attribute__((constructor))
#endif
static void pmu_init(void)
{
    uint32_t bp_freq = atm_bp_clock_get();
    DEBUG_TRACE("bp_freq is %" PRIu32, bp_freq);
    pmu_set_bp(bp_freq);

    pmu_core_param param = {
	.batt_type = BATT_TYPE,
	.vddio_type = VDDIO_TYPE,
	.batt_level = BATT_LEVEL,
	.vddpa_src = VDDPA_SRC,
	.vstore_max = VSTORE_MAX,
	.boost_src =
#ifdef BOOST_FROM_VHARV_INDUCTOR
	    BOOST_SRC_VHARV_INDUCTOR,
#elif defined (BOOST_FROM_VHARV_TWO_DIODE)
	    BOOST_SRC_VHARV_TWO_DIODE,
#else
	    BOOST_SRC_NONE,
#endif
	.vharv_range =
#ifdef VHARV_RANGE
	    VHARV_RANGE,
#else
	    VHARV_RANGE_INVALID,
#endif
	.dig_test_sel =
#ifdef DIG_TEST_SEL
	    DIG_TEST_SEL,
#else
	    0,
#endif
	.ext_vddio_with_vddiop_enabled =
#ifdef EXTERNAL_VDDIO_WITH_VDDIOP_ENABLED 
	    true,
#else
	    false,
#endif
	.inductance =
#ifdef CFG_HARV_METER
	    INDUCTOR_NHENRY,
#else
	    0,
#endif
	.ref_inductance =
#ifdef CFG_HARV_METER
	    REF_INDUCTOR_NHENRY,
#else
	    0,
#endif
    };

    if (!pmu_core_init(&param)) {
	DEBUG_TRACE("Invalid vstore_max or batt_type");
	return;
    }

#if (defined(CFG_RF_HARV) || defined(CFG_NONRF_HARV)) && !defined(AUTO_TEST)
#ifdef CFG_NONRF_HARV
#ifndef VHARV_RANGE
#error "VHARV_RANGE needs to be defined for non-rf harvesting"
#else
    STATIC_ASSERT(((VHARV_RANGE >= VHARV_RANGE_0P4V_0P45V) &&
	(VHARV_RANGE <= VHARV_RANGE_2P2V_2P5V)), "Invalid vharv range");
#endif
#ifdef CFG_RF_HARV
    pmu_combined_harv();
#else
    pmu_nonrf_harv();
#endif
#else // CFG_NONRF_HARV
    pmu_rf_harv();
#endif // CFG_NONRF_HARV
#else  // !((CFG_RF_HARV || CFG_NONRF_HARV) && !AUTO_TEST)
    pmu_nonharv();
#endif // (CFG_RF_HARV || CFG_NONRF_HARV) && !AUTO_TEST

    pmu_core_post_init();
}

#ifdef CONFIG_SOC_FAMILY_ATM
static int pmu_sys_init(void)
{
    pmu_init();
    return 0;
}

SYS_INIT(pmu_sys_init, PRE_KERNEL_2, 10);
#endif
