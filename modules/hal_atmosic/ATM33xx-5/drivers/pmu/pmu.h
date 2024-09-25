/**
 ******************************************************************************
 *
 * @file pmu.h
 *
 * @brief Power Management Unit APIs
 *
 * Copyright (C) Atmosic 2021-2024
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

#define CANHARV_POLL_CNT 500

#define BATT_TYPE_LI_ION 0
#define BATT_TYPE_RECHARGEABLE 1
#define BATT_TYPE_NO_BATTERY 2
#define BATT_TYPE_NON_RECHARGEABLE 3

#define VDDIO_TYPE_INTERNAL 0
#define VDDIO_TYPE_EXTERNAL 1

#define BATT_LEVEL_LE_1P8V 0
#define BATT_LEVEL_GT_1P8V 1

#define MPPT_TYPE_DIGITAL 0
#define MPPT_TYPE_ANALOG 1
#define MPPT_TYPE_DISABLED 2
#define MPPT_TYPE_INVALID 3

#define VDDPA_SRC_VDDIOP 0
#define VDDPA_SRC_VSTORE 1

#define VHARV_RANGE_0P4V_0P45V 0
#define VHARV_RANGE_0P45V_0P5V 1
#define VHARV_RANGE_0P525V_0P6V 2
#define VHARV_RANGE_0P6V_0P7V 3
#define VHARV_RANGE_0P675V_0P8V 4
#define VHARV_RANGE_0P75V_0P9V 5
#define VHARV_RANGE_0P825V_1P0V 6
#define VHARV_RANGE_0P9V_1P1V 7
#define VHARV_RANGE_0P975V_1P2V 8
#define VHARV_RANGE_1P05V_1P3V 9
#define VHARV_RANGE_1P175V_1P45V 10
#define VHARV_RANGE_1P3V_1P6V 11
#define VHARV_RANGE_1P5V_1P8V 12
#define VHARV_RANGE_1P7V_2P0V 13
#define VHARV_RANGE_1P95V_2P25V 14
#define VHARV_RANGE_2P2V_2P5V 15
#define VHARV_RANGE_INVALID 16

#define BOOST_SRC_NONE 0
#define BOOST_SRC_VHARV_INDUCTOR 1
#define BOOST_SRC_VHARV_TWO_DIODE 2

typedef enum {
    HARV_ERR_NO_ERROR,
    HARV_ERR_NO_DATA,
    HARV_ERR_BUSY,
    HARV_ERR_DISABLED,
} hm_status_t;

typedef struct hm_stats_s {
    uint32_t pmu_rb_mppt;
    uint32_t num_events;
    float inst_uwatt;
    float avg_uwatt;
    uint16_t avg_period_cnt; // event saturated
    uint16_t avg_event_cnt; // period saturated
} hm_stats_t;

/**
 * @brief Configure MPPT type
 */
void pmu_cfg_mppt(uint8_t type);

/**
 * @brief Disable rectifier
 */
void pmu_disable_rectifier(void);

/**
 * @brief Configure VHARV range
 */
void pmu_cfg_vharv_range(void);

typedef void (*harv_meter_cb)(hm_stats_t const *stats, hm_status_t status);

/**
 * @brief Configure harvesting meter
 */
void pmu_harv_meter(void);

/**
 * @brief Enable/Disable harvesting meter
 * @param[in] enable true/false
 * @param[in] cb Callback to indicate hm stats update
 * @param[in] seconds Events every 'seconds' duration. 0 implies all events sent
 * @return hm_status_t status of the requested operation
 */
hm_status_t pmu_set_harv_meter(bool enable, harv_meter_cb cb, uint32_t seconds);

/**
 * @brief Return the harvesting enabled/disabled status
 */
bool pmu_is_harvesting_disabled(void);

/**
 * @brief Configure wakeup if enough energy
 * @param[in] enable true/false
 */
void pmu_set_socoff_energy_wakeup(bool enable);

/**
 * @brief Enable/Disable PMUADC for brownout thresholds and buck boost
 * @param[in] enable true/false
 */
void pmu_set_pmuadc(bool enable);

/**
 * @brief Extend brownout period
 * @param[in] enable true/false
 */
void pmu_extend_brwnout_period(bool enable);

/**
 * @brief Program VBAT brownout threshold level
 * @param[in] thr       threshold level (0..31)
 */
void pmu_set_brwnout_thr_vbat(uint8_t thr);

/**
 * @brief Clear OVR bit for VBAT brownout
 */
void pmu_clear_brwnout_thr_vbat(void);

/**
 * @brief Program VSTORE brownout threshold level
 * @param[in] thr       threshold level (0..31)
 */
void pmu_set_brwnout_thr_vstore(uint8_t thr);

/**
 * @brief Program VSTORE good2start threshold level
 * @param[in] thr       threshold level (0..7)
 */
void pmu_set_good2start_thr_vstore(uint8_t thr);

/**
 * @brief Program VSTORE and VBAT good4cpu threshold level
 * @param[in] thr       threshold level (0..7)
 */
void pmu_set_good4cpu_thr(uint8_t thr);

/**
 * @brief Program VSTORE and VBAT good2tx threshold level
 * @param[in] thr       threshold level (0..7)
 */
void pmu_set_good2tx_thr(uint8_t thr);

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
 * @brief Enable/Disable harvesting load
 * @param[in] enable    1 = Enable / 0 = Disable
 */
void pmu_set_harv2load(bool enable);

/**
 * @brief Program HW params for rf Harvesting
 */
void pmu_rf_harv(void);

/**
 * @brief Program HW params for nonrf Harvesting
 */
void pmu_nonrf_harv(void);

/**
 * @brief Program HW params for concurrent Harvesting
 */
void pmu_combined_harv(void);

/**
 * @brief Program HW params to disable Harvesting
 */
void pmu_nonharv(void);

/**
 * @brief Set PMU configuration for rechargeable battery
 * @details PMU must be out of reset and clocked before invocation
 *
 * @return return status
 */
bool pmu_recharge_batt(void);

/**
 * @brief Set threshold to stop harvesting based on Vstore
 */
void pmu_cfg_vstore_max(void);

/**
 * @brief Adjust PMU voltages based on BP frequency
 * @param[in] freq  BP frequency in Hz
 */
void pmu_set_bp(uint32_t freq);

/**
 * @brief Enable/Disable lithium ion battery voltage measurement
 * @param[in] enable  Flag to enable/disable
 */
void pmu_set_liion_measurement(bool enable);

/**
 * @brief Update bias current for the adc driver opamp
 * @param[in] current  Bias current setting
 */
void pmu_set_bias_current(uint8_t current);

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
 * @brief Get CANHARVEST register value.
 * @param[in] total  CANHARVEST register polling count
 * @return Number of times the bit was set
 */
uint32_t pmu_harv_get_harvcnt(uint32_t total);

/**
 * @brief Enable/Disable vstore->vbatli bypass
 * @param[in] enable  Flag to enable/disable
 * @param[in] restart  Indicate if the charge timer needs to be restarted
 */
void pmu_vstore_vbatli_bypass(bool enable, bool restart);

/**
 * @brief Enable/Disable charge pump clock
 * @param[in] enable  Flag to enable/disable
 * @param[in] volts Voltage level
 * @param[in] restart  Indicate if the charge timer needs to be restarted
 */
void pmu_set_charge_pump(bool enable, float volts, bool restart);

/**
 * @brief Configure the battery type
 * @param[in] batt_type Battery type
 *
 * @return return status
 */
bool pmu_cfg_batt_type(uint8_t batt_type);

/**
 * @brief Run the SWREG Clock Calibration
 * @details Do not load new SWREG settings within 250us of calling this function
 */
void pmu_run_swreg_clock_cal(void);

/**
 * @brief Enable/Disable solution level config with Ext VDDIO + Enable VDDIOP
 * @details Enabled on an as-needed-basis
 * @param[in] enable  Flag to enable/disable
 */
void pmu_enable_vddiop_with_extio_sleep_fix(bool enable);

/**
 * @brief Enable/Disable VDDIOP
 * @param[in] enable  Flag to enable/disable
 */
void pmu_set_vddiop_with_extio_sleep(bool enable);

/**
 * @brief Enable/Disable boost from harv inductor
 * @param[in] enable  Flag to enable/disable
 */
void pmu_set_harv_indicator(bool enable);

#ifdef __cplusplus
}
#endif

/// @} PMU
