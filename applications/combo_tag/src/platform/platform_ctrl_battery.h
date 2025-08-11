/**
 *******************************************************************************
 *
 * @file platform_ctrl_battery.h
 *
 * @brief Platform control battery For FMNA and FMDN Combo Tag
 *
 * Copyright (C) Atmosic 2025
 *
 *******************************************************************************
 */

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Platform control battery status get
 *
 * @return battery status in percentage
 */
uint8_t platform_ctrl_batt_status_get(void);

#ifdef __cplusplus
}
#endif

///@}
