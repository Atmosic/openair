/*
 * Copyright (c) 2025-2026 Atmosic
 *
 * SPDX-License-Identifier: Apache-2.0
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
