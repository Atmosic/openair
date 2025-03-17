/**
 ******************************************************************************
 *
 * @file pmu.h
 *
 * @brief Power Management Unit APIs
 *
 * Copyright (C) Atmosic 2020-2025
 *
 *
 ******************************************************************************
 */

#pragma once

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
 * @brief Set PMU configuration for rechargeable battery
 * @details PMU must be out of reset and clocked before invocation
 */
extern void pmu_recharge_batt(void);

/**
 * @brief Program HW params for harvester meter
 */
extern void pmu_harv_meter(void);

/**
 * @brief Program brownout threshold level
 * @details PMU must be out of reset and clocked before invocation
 * @param[in] thr       threshold level (0..7)
 */
extern void pmu_set_brwnout_thr(uint8_t thr);

/**
 * @brief Enable/Disable socoff wakeup based on low power comparator
 * @param[in] enable    1 = Enable / 0 = Disable
 * @param[in] pin       pin number used for wakeup
 * @param[in] ref       wakeup reference voltage setting
 */
extern void pmu_socoff_wakeup_lpcomp(bool enable, uint8_t pin, uint8_t ref);

/**
 * @brief Enable/Disable socoff wakeup based on GPIO P10 (rising edge)
 * @param[in] enable    1 = Enable / 0 = Disable
 */
extern void pmu_socoff_wakeup_gpio(bool enable);

/**
 * @brief Program HW params for combined rf and nonrf Harvesting
 * @param[in] mppt Enable(true)/Disable(false) Maximum Power Point Tracking
 * @param[in] rect_stage  Rectifier stages (1..3) Applicable only when mppt
 *            is disabled
 */
extern void pmu_harv(bool mppt, uint8_t rect_stage);

/**
 * @brief Program HW params for rf Harvesting
 */
extern void pmu_rf_harv(void);

/**
 * @brief Program HW params for nonrf Harvesting
 */
extern void pmu_nonrf_harv(void);

/**
 * @brief Set PMU configuration for rechargeable battery
 * @details PMU must be out of reset and clocked before invocation
 */
extern void pmu_recharge_batt(void);

/**
 * @brief Supported Vstore capacity
 */
typedef enum {
    /// 3.0 Volts
    VSTORE_EQ_3p0V,
    /// 3.3 Volts
    VSTORE_EQ_3p3V,
} vstore_t;

/**
 * @brief Set threshold to stop harvesting based on Vstore
 * @details PMU must be out of reset and clocked before invocation
 * @param[in] vstore    Vstore capacity
 */
extern void pmu_stopharv_threshold(vstore_t vstore);

/**
 * @brief Read pmu_wkup_det value
 *
 * @return value of pmu_wkup_det
 */
extern uint8_t pmu_get_wkup_det(void);

/**
 * @brief Read pseq_boot_status value
 *
 * @return value of pseq_boot_status
 */
extern uint32_t pseq_get_boot_status(void);

/**
 * @brief Program PMU registers to support lpc_rcos
 */
void pmu_lpc_rcos_init(void);

/**
 * @brief Program PMU registers prior to calibrating LPC
 */
void pmu_start_lpc_rcos_retn(void);

/**
 * @brief Restore PMU registers after calibrating LPC
 */
void pmu_finish_lpc_rcos_retn(void);

/// PMU wakeup causes
#define PMU_WKUP_PIN 0x01
#define PMU_WKUP_LPCOMP 0x02
#define PMU_WKUP_TIMER 0x04
#define PMU_WKUP_NA 0x08

/**
 * @brief Get harve count value.
 * @return The register value.
 */
uint32_t pmu_harv_get_harvcnt(uint32_t total);
#ifdef __cplusplus
}
#endif

/// @} PMU
