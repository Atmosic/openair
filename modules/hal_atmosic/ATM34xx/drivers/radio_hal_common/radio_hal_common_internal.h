/**
 ******************************************************************************
 *
 * @file radio_hal_common_internal.h
 *
 * @brief ATLC Driver Common Interface
 *
 * Copyright (C) Atmosic 2025
 *
 ******************************************************************************
 */

#pragma once

#ifndef RADIO_HAL_COMMON_INTERNAL_GUARD
#error "radio_hal_common_internal.h should only be included in radio_hal_common source files"
#endif

#ifdef __cplusplus
extern "C" {
#endif

void atm_mac_handler(void);
void atm_mac_rev_hash_check(void);
void atm_mac_core_init(void);

#ifdef __cplusplus
}
#endif
