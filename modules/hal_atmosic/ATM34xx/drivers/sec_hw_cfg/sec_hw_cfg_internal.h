/**
 *******************************************************************************
 *
 * @file sec_hw_cfg_internal.h
 *
 * @brief Early and secure hardware configuration internal APIs
 *
 * Copyright (C) Atmosic 2025
 *
 *******************************************************************************
 */

#pragma once

#include <stdint.h>

#include "at_wrpr.h"

#ifndef SEC_HW_CFG_INTERNAL_GUARD
#error "sec_hw_cfg_internal.h should only be included in sec_hw_cfg source files"
#endif

#ifdef __cplusplus
extern "C" {
#endif

void sec_hw_cfg_core_clkrstgen_init(void);
void sec_hw_cfg_core_pmu_cfg(uint32_t freq);
void sec_hw_cfg_core_init(void);

// The following workaround is necessary only before Perth 2.0
#ifndef WRPRPINS_PROT_BITS_SET1__ROM_PATCH_LOCK_SET__MASK
void sec_hw_cfg_core_pmu_set_bp_workaround(uint32_t freq);
#endif

#ifdef __cplusplus
}
#endif

