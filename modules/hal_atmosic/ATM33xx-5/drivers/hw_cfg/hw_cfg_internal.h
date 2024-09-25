/**
 ******************************************************************************
 *
 * @file hw_cfg_internal.h
 *
 * @brief Hardware Configuration internal APIs
 *
 * Copyright (C) Atmosic 2024
 *
 ******************************************************************************
 */

#pragma once

#ifndef HW_CFG_INTERNAL_GUARD
#error "hw_cfg_internal.h should only be included in hw_cfg source files"
#endif

#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    uint8_t vddpa_src;
    bool force_lpc_rcos;
} hw_cfg_core_param;

void hw_cfg_core_cal(void);
void hw_cfg_radio_init(void);
bool hw_cfg_core_init(hw_cfg_core_param const *param);

#ifdef __cplusplus
}
#endif
