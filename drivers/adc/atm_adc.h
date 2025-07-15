/*
 * Copyright (c) 2025 Atmosic
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef ATM_ADC_H
#define ATM_ADC_H

#include <zephyr/drivers/adc.h>

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

#endif /* ATM_ADC_H */
