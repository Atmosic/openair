/**
 *******************************************************************************
 *
 * @file sec_hw_cfg_internal.h
 *
 * @brief Early and secure hardware configuration internal APIs
 *
 * Copyright (C) Atmosic 2024
 *
 *******************************************************************************
 */

#pragma once

#ifndef SEC_HW_CFG_INTERNAL_GUARD
#error "sec_hw_cfg_internal.h should only be included in sec_hw_cfg source files"
#endif

#ifdef __cplusplus
extern "C" {
#endif

void sec_hw_cfg_core_pseq_init(void);
void sec_hw_cfg_core_pmu_set_bp(uint32_t freq, bool use_ramboot);
void sec_hw_cfg_core_init(void);

#ifdef __cplusplus
}
#endif
