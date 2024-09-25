/**
 ******************************************************************************
 *
 * @file pmu_internal.h
 *
 * @brief Power Management Unit internal APIs
 *
 * Copyright (C) Atmosic 2023
 *
 ******************************************************************************
 */

#pragma once

#ifndef PMU_INTERNAL_GUARD
#error "pmu_internal.h should only be included in pmu source files"
#endif

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    NONRF_VRANGE_1P1_1P4,
    NONRF_VRANGE_1P2_1P5,
    NONRF_VRANGE_1P3_1P6,
    NONRF_VRANGE_1P4_1P7,
    NONRF_VRANGE_1P5_1P8,
    NONRF_VRANGE_1P6_1P9,
} nonrf_vrange_t;

typedef enum {
    VBAT_DEFAULT,
    VBAT_LE_1P8V,
    VBAT_GT_1P8V_VDDIO_EXT,
    VBAT_GT_1P8V_VDDIO_INT,
    VBAT_NONE,
} vbat_level_t;

void pmu_nonharv(void);
void pmu_install_hib_repvec(void);
void pmu_core_init(nonrf_vrange_t range, vbat_level_t level,
    uint32_t vstore_lwm_mv);

#ifdef __cplusplus
}
#endif
