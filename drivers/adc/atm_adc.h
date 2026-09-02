/*
 * Copyright (c) 2025-2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#ifndef ATM_ADC_H
#define ATM_ADC_H

#include <zephyr/drivers/adc.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifdef CONFIG_ATM_ADC_TEST_API
/**
 * @brief Lightweight GADC test API (TEST ONLY).
 *
 * Performs @p buf_len raw single-conversion GADC reads on @p channel
 * and stores each FIFO sample (signed 16-bit) into @p buf. The polling
 * loop is bounded so a stuck datapath is reported instead of hanging
 * forever.
 *
 * Intended for hardware bring-up and validation only; bypasses the
 * Zephyr ADC subsystem and calibration, and must not be used in
 * production code.
 *
 * @param channel GADC channel id.
 * @param buf     Caller-provided buffer to receive raw FIFO samples
 *                (one entry per conversion).
 * @param buf_len Number of conversions to perform; must be > 0.
 *
 * @retval 0          on success.
 * @retval -EINVAL    @p buf is NULL or @p buf_len is 0.
 * @retval -ETIMEDOUT FIFO did not produce a sample within the polling budget.
 */
int atm_adc_test_raw_samples(uint8_t channel, int16_t *buf, uint8_t buf_len);

/**
 * @brief Copy out the driver's cached GADC calibration blob (TEST ONLY).
 *
 * @param buf      Buffer to receive the calibration blob.
 * @param buf_size Size of @p buf in bytes.
 * @param out_len  Set to the valid calibration length (0 if no tag found).
 *
 * @retval 0        on success.
 * @retval -EINVAL  @p buf or @p out_len is NULL.
 * @retval -ENOMEM  @p buf_size too small.
 */
int atm_adc_test_get_cal(void *buf, size_t buf_size, uint16_t *out_len);

/**
 * @brief Length of the leading calibration bytes that never change at run time
 *        (TEST ONLY).
 *
 * Bytes beyond this offset hold the offset compensation that the driver
 * re-computes during measurements.
 */
extern uint16_t const atm_adc_test_cal_stable_len;
#endif

#ifdef CONFIG_ATM_ADC_CAL_TEST_HOOKS
/**
 * @brief Invalidate the cached GADC calibration with a known pattern (TEST ONLY).
 *
 * A successful reload undoes it; callers must reload before leaving the test.
 */
void atm_adc_test_invalidate_cal(void);

/**
 * @brief Make reloads behave as if the journal had no GADC_CAL tag (TEST ONLY).
 */
void atm_adc_test_set_cal_missing(bool missing);
#endif

#ifdef CONFIG_ATM_ADC_CAL_RELOAD
/**
 * @brief Re-read the GADC calibration tag from the secure journal.
 *
 * The calibration is cached at init, so callers that change the active
 * secure journal at run time must call this.
 *
 * @param override When true the journal fully determines the calibration: if
 *                 the tag is absent the cached calibration is dropped and
 *                 nominal constants are used. When false the cached
 *                 calibration is retained when the tag is absent, so a
 *                 journal that does not carry the tag leaves a previously
 *                 detected calibration in place.
 */
void atm_adc_reload_cal(bool override);
#endif

/**
 * @brief ATM wrapper for adc_raw_to_millivolts with ADC_GAIN_1_8 support
 *
 * This function provides the same interface as adc_raw_to_millivolts() but
 * adds support for ADC_GAIN_1_8 which is not supported in the standard
 * Zephyr implementation.
 *
 * @param ref_mv Reference voltage in millivolts
 * @param gain ADC gain setting (including ADC_GAIN_1_8)
 * @param resolution ADC resolution in bits
 * @param valp Pointer to raw ADC value (input) and converted millivolt value (output)
 * @return 0 on success, negative error code on failure
 */
int atm_adc_raw_to_millivolts(int32_t ref_mv, enum adc_gain gain, uint8_t resolution,
	int32_t *valp);

#ifdef __cplusplus
}
#endif

#endif /* ATM_ADC_H */
