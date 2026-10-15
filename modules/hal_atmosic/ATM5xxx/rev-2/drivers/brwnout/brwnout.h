/**
 ******************************************************************************
 *
 * @file brwnout.h
 *
 * @brief Brownout Driver APIs
 *
 * Copyright (C) Atmosic 2026
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 *
 ******************************************************************************
 */

#pragma once

/**
 * @defgroup BRWNOUT BRWNOUT
 * @ingroup DRIVERS
 * @brief Brownout Driver API: Configure brownout support
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Force to soc off
 */
extern void brwnout_force_socoff(void);

/**
 * @brief Brownout PMU interrupt handler
 *
 * Called by central PMU_Handler() when brownout interrupt fires.
 */
void brwnout_pmu_handler(void);

#ifdef __cplusplus
}
#endif

/// @} BRWNOUT
