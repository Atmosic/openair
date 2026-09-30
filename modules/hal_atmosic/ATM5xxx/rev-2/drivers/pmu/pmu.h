/**
 ******************************************************************************
 *
 * @file pmu.h
 *
 * @brief Power Management Unit APIs
 *
 * Copyright (C) Atmosic 2021-2026
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 *
 *
 ******************************************************************************
 */

#pragma once

#include "arch.h"

/**
 * @defgroup PMU PMU
 * @ingroup DRIVERS
 * @brief Power Management driver
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Program brownout threshold level
 * @details PMU must be out of reset and clocked before invocation
 * @param[in] thr       threshold level (0..31)
 */
void pmu_set_brwnout_thr(uint8_t thr);

/**
 * @brief Enable/Disable socoff wakeup based on low power comparator
 * @param[in] enable    1 = Enable / 0 = Disable
 * @param[in] pin       pin number (3 or 4 only) used for wakeup
 * @param[in] ref       voltage threshold
 *
 * @return return status
 */
bool pmu_socoff_wakeup_lpcomp(bool enable, uint8_t pin, uint8_t ref);

/**
 * @brief Enable/Disable socoff wakeup based on GPIO P5 (high level)
 * @param[in] enable    1 = Enable / 0 = Disable
 */
void pmu_socoff_wakeup_gpio(bool enable);

/**
 * @brief Read pmu_wkup_det value
 *
 * @return value of pmu_wkup_det
 */
uint8_t pmu_get_wkup_det(void);

/// PMU wakeup by pin
#define PMU_WKUP_PIN 0x01
/// PMU wakeup by low power comparator
#define PMU_WKUP_LPCOMP 0x02
/// PMU wakeup by timer
#define PMU_WKUP_TIMER 0x04

/**
 * @brief Read and clear pmu_soc_wdog_reset value
 *
 * @return value of pmu_soc_wdog_reset
 */
bool pmu_get_soc_wdog_reset(void);

/**
 * @brief Read and clear pmu_wdog_reset value
 *
 * @return value of pmu_wdog_reset
 */
bool pmu_get_pmu_wdog_reset(void);

/**
 * @brief Enable/Disable PMU watchdog
 * @param[in] enable  Flag to enable/disable
 */
void pmu_set_pmu_wdog_reset(bool enable);

/**
 * @brief Force PMU and SOC reset
 */
__NORETURN void pmu_reset(void);

/**
 * @brief PMU watchdog warning interrupt handler
 *
 * Called by central PMU_Handler() when PMU watchdog warning fires.
 * Defined in wdt_atmosic_unified.c when CONFIG_ATM_PMU_WDT_ENABLE is enabled.
 */
void wdt_pmu_handler(void);

/**
 * @brief Reads the PMU status register and returns flags indicating which
 * interrupt sources are active.
 *
 * @param[out] brownout  Set true if brownout interrupt pending
 * @param[out] wdog_warn Set true if PMU watchdog warning pending
 */
void pmu_isr_source(bool *brownout, bool *wdog_warn);
#ifdef __cplusplus
}
#endif

/// @} PMU
