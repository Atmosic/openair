/**
 ******************************************************************************
 *
 * @file pmu.c
 *
 * @brief Power Management Unit Driver
 *
 * Copyright (C) Atmosic 2020-2024
 *
 ******************************************************************************
 */

#include "arch.h"
#include "at_wrpr.h"
#include "at_apb_nvm_regs_core_macro.h"
#include "nvm.h"
#include "pmu.h"
#define PMU_INTERNAL_GUARD
#include "pmu_internal.h"

#define VSTORE_LWM_MV_DEFAULT 400

__attribute__((constructor))
static void pmu_init(void)
{
    vbat_level_t level = VBAT_DEFAULT;
#if defined(VBAT_GT_1p8V_VDDIO_EXT)
    level = VBAT_GT_1P8V_VDDIO_EXT;
#elif defined(VBAT_GT_1p8V_VDDIO_INT)
    level = VBAT_GT_1P8V_VDDIO_INT;
#elif defined(VBAT_LE_1p8V)
    level = VBAT_LE_1P8V;
#elif defined(CFG_RF_HARV) || defined(CFG_NONRF_HARV)
#if defined(NO_VBAT)
    level = VBAT_NONE;
#endif // NO_VBAT
#endif

    nonrf_vrange_t range = NONRF_VRANGE_1P6_1P9;
#if defined(CFG_NONRF_VRANGE_1p1_1p4)
    range = NONRF_VRANGE_1P1_1P4;
#elif defined(CFG_NONRF_VRANGE_1p2_1p5)
    range = NONRF_VRANGE_1P2_1P5;
#elif defined(CFG_NONRF_VRANGE_1p3_1p6)
    range = NONRF_VRANGE_1P3_1P6;
#elif defined(CFG_NONRF_VRANGE_1p4_1p7)
    range = NONRF_VRANGE_1P4_1P7;
#elif defined(CFG_NONRF_VRANGE_1p5_1p8)
    range = NONRF_VRANGE_1P5_1P8;
#endif

    uint32_t vstore_lwm = VSTORE_LWM_MV_DEFAULT;
#ifdef VSTORE_LWM
    vstore_lwm = VSTORE_LWM * 1000;
#endif

    pmu_core_init(range, level, vstore_lwm);

#if defined(BRWNOUT_THR)
    STATIC_ASSERT(((BRWNOUT_THR >= 0) && (BRWNOUT_THR <= 7) &&
	!(BRWNOUT_THR % 2)), "Brownout Threshold is invalid");
    pmu_set_brwnout_thr(BRWNOUT_THR);
#endif

#if (defined(CFG_RF_HARV) || defined(CFG_NONRF_HARV)) && !defined(AUTO_TEST)
    ASSERT_ERR(NVM_EFUSE_AUTOREAD__OTP_HARV_DISABLED__READ(nvm_EFUSE_AUTOREAD)
	== 0);
#if defined(CFG_RF_HARV) && defined(CFG_NONRF_HARV)
    // Use default settings for combined harvesting
    // No MPPT:rect_stage=3: default nonrf_vrange_1p6_1p9
    pmu_harv(false, 3);
#elif defined(CFG_RF_HARV)
    pmu_rf_harv();
#else // CFG_NONRF_HARV
    pmu_nonrf_harv();
#endif // CFG_RF_HARV && CFG_NONRF_HARV

#if defined(VSTORE_MAX_EQ_3p0V)
    pmu_stopharv_threshold(VSTORE_EQ_3p0V);
#endif // VSTORE_MAX_EQ_3p0V

#else  // !((CFG_RF_HARV || CFG_NONRF_HARV) && !AUTO_TEST)
    pmu_nonharv();
    pmu_install_hib_repvec();
#endif // (CFG_RF_HARV || CFG_NONRF_HARV) && !AUTO_TEST

#ifdef CFG_RECHBATT
    pmu_recharge_batt();
#endif
}
