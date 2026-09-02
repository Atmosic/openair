/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#pragma once

/**
 * @addtogroup ATM_RADIO_CAL Radio Calibration
 * @ingroup DRIVERS
 * @brief Radio Calibration module
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#if CONFIG_ATM_RADIO_CAL_DECISION
/**
 * @brief Triger calibration when requested
 *
 * This function requests recalibration due to excessive DC offset when
 * demodulating
 */
void atm_radio_cal_trigger(void);
#endif

#if CONFIG_ATM_RADIO_CAL_DEMAND
/**
 * @brief Request an immediate RX DC offset calibration.
 *
 * Directly schedules a calibration via the MAC manager, bypassing any
 * debounce or decision logic. Safe to call from any Zephyr thread context
 * (not ISR).
 */
void atm_radio_cal_request(void);
#endif

#ifdef __cplusplus
}
#endif

///@}
