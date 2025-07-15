/*
 * Copyright (c) 2025 Atmosic
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/drivers/adc.h>
#include "atm_adc.h"

int atm_adc_raw_to_millivolts(int32_t ref_mv, enum adc_gain gain, uint8_t resolution, int32_t *valp)
{
    if (gain == ADC_GAIN_1_8) {
        int32_t adc_mv = *valp * ref_mv * 8;  // Invert 1/8 gain
        *valp = (adc_mv >> resolution);
        return 0;
    }

    return adc_raw_to_millivolts(ref_mv, gain, resolution, valp);
}
