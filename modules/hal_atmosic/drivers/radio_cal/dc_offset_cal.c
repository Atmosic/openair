/**
 ******************************************************************************
 *
 * @file dc_offset_cal.c
 *
 * @brief DC Offset Calibration APIs
 *
 * Copyright (C) Atmosic 2026
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 *
 ******************************************************************************
 */

#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
#include <string.h>
#include <inttypes.h>
#include "dc_offset_cal.h"
#include "calibration.h"
#include "sec_jrnl.h"
#include "atm_utils_c.h"
#define HW_CFG_INTERNAL_GUARD
#include "hw_cfg.ih"

LOG_MODULE_REGISTER(dc_offset_cal, LOG_LEVEL_INF);

bool atm_dc_offset_cal_trigger(void)
{
    bool success = true;

    // Called 3 times to cover all channels
    for (int i = 0; i < 3; i++) {
	if (!hw_cfg_core_attempt_calibration()) {
	    LOG_ERR("Channel %d calibration FAILED", i);
	    success = false;
	    break;
	}
    }

    return success;
}

bool atm_dc_offset_cal_read_values(dc_offset_cal_data_t *cal_data)
{
    // Calculate number of calibration values from structure size
    const int NUM_CAL_VALUES = sizeof(dc_offset_cal_data_t) / sizeof(uint32_t);
    // Read calibration values DIRECTLY from MDM hardware registers
    volatile uint32_t const *calibrations = &CMSDK_MDM->LNA_TIA_LW_DCCAL_DC0;
    uint32_t *cal_data_ptr = &cal_data->lna_tia_lw_dccal_dc0;
    for (int i = 0; i < NUM_CAL_VALUES; i++) {
	cal_data_ptr[i] = calibrations[i];
    }

    return true;
}

bool atm_dc_offset_cal_store_to_sec_jrnl(dc_offset_cal_data_t const *cal_data)
{
    // Get CUST_CFG tag to fetch dc offset calibration data
    cust_cfg_len = sizeof(cust_cfg);
    sec_jrnl_ret_status_t status =
	nsc_sec_jrnl_get(ATM_TAG_CUST_CFG, &cust_cfg_len, (uint8_t *)&cust_cfg);
    if (status != SEC_JRNL_OK) {
	cust_cfg.cust = 0;
	cust_cfg.external_pa_gain = 0;
	// Clear the fields that should NOT be included in tag 0xbd storage
	cust_cfg.pbr_offset = 0;
	cust_cfg.rtt_offset = 0;
	cust_cfg.pmu_top_pmu2 = 0;
	// Calculate storage size excluding pbr_offset, rtt_offset, and
	// pmu_top_pmu2
#define CUST_CFG_EXCLUDE_SIZE \
    (sizeof(uint16_t) + sizeof(uint16_t) + sizeof(uint32_t))
	cust_cfg_len -= CUST_CFG_EXCLUDE_SIZE;
    }

    // Set version
    cust_cfg.version = 1;

    // Copy LNA TIA DC calibration values
    int NUM_CAL_VALUES = sizeof(dc_offset_cal_data_t) / sizeof(uint32_t);
    uint32_t *cust_data_ptr = &cust_cfg.lna_tia_lw_dccal_dc0;
    uint32_t const *cal_data_ptr = &cal_data->lna_tia_lw_dccal_dc0;
    for (int i = 0; i < NUM_CAL_VALUES; i++) {
	cust_data_ptr[i] = cal_data_ptr[i];
    }

    // Append LNA TIA DC offset data as CUST_CFG
    status = nsc_sec_jrnl_append(ATM_TAG_CUST_CFG, &cust_cfg_len,
	(uint8_t const *)&cust_cfg);
    if (status != SEC_JRNL_OK) {
	return false;
    }

    return true;
}

bool atm_dc_offset_cal_trigger_and_save(void)
{
    LOG_INF("Starting complete DC offset calibration process");

    // Step 1: Trigger calibration
    LOG_DBG("Triggering DC offset calibration");
    if (!atm_dc_offset_cal_trigger()) {
	LOG_ERR("Failed to trigger DC offset calibration");
	return false;
    }
    LOG_DBG("DC offset calibration completed successfully");

    // Step 2: Read calibration values
    LOG_DBG("Reading DC offset calibration values from registers");
    dc_offset_cal_data_t cal_data;
    if (!atm_dc_offset_cal_read_values(&cal_data)) {
	LOG_ERR("Failed to read DC offset calibration values");
	return false;
    }
    int NUM_CAL_VALUES = sizeof(dc_offset_cal_data_t) / sizeof(uint32_t);
    uint32_t *cal_data_ptr = &cal_data.lna_tia_lw_dccal_dc0;
    LOG_DBG("DC offset calibration values:");
    for (int i = 0; i < NUM_CAL_VALUES; i++) {
	LOG_DBG("0x%08" PRIx32, cal_data_ptr[i]);
    }

    // Step 3: Store to secure journal
    LOG_DBG("Storing DC offset calibration data to secure journal");
    if (!atm_dc_offset_cal_store_to_sec_jrnl(&cal_data)) {
	LOG_ERR("Failed to store DC offset calibration data");
	return false;
    }

    LOG_INF("Complete DC offset calibration process finished successfully");
    return true;
}
