/**
 ******************************************************************************
 *
 * @file batt_model_coin_internal.h
 *
 * @brief Battery model for hybrid super CAP (COIN) internal API
 *
 * Copyright (C) Atmosic 2023
 *
 ******************************************************************************
 */

#pragma once

#ifndef BATT_MODEL_COIN_INTERNAL_GUARD
#error "Should only be included in batt_model_coin source files"
#endif

#ifdef __cplusplus
extern "C" {
#endif

uint8_t batt_coin_volt_to_lvl(float volt);

#ifdef __cplusplus
}
#endif
