/**
 ******************************************************************************
 *
 * @file pmu_internal.h
 *
 * @brief Power Management Unit internal APIs
 *
 * Copyright (C) Atmosic 2024
 *
 ******************************************************************************
 */

#pragma once

#ifndef PMU_INTERNAL_GUARD
#error "pmu_internal.h should only be included in pmu source files"
#endif

#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    uint32_t inductance;
    uint32_t ref_inductance;
    uint16_t vstore_max;
    uint8_t boost_src;
    uint8_t vharv_range;
    uint8_t batt_type;
    uint8_t vddio_type;
    uint8_t batt_level;
    uint8_t vddpa_src;
    uint8_t dig_test_sel;
    bool ext_vddio_with_vddiop_enabled;
} pmu_core_param;

bool pmu_core_init(pmu_core_param const *param);
void pmu_core_post_init(void);
void pmu_cfg_dbg_sig(void);
bool pmu_harv_meter_core_init(uint32_t *pmu_rb_mppt);
void pmu_update_hm_stats(hm_stats_t *stats, hm_status_t *stats_valid);
void pmu_reset_harv_meter(void);

#ifdef __cplusplus
}
#endif
