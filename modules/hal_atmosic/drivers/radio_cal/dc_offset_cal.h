/**
 ******************************************************************************
 *
 * @file dc_offset_cal.h
 *
 * @brief DC Offset Calibration APIs
 *
 * Copyright (C) Atmosic 2026
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 *
 ******************************************************************************
 */

#pragma once

/**
 * @defgroup DC_OFFSET_CAL DC Offset Calibration
 * @ingroup DRIVERS
 * @brief DC Offset Calibration APIs
 * @{
 */

#include <stdint.h>
#include <stdbool.h>
#include "compiler.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief DC offset calibration data structure
 *
 * This structure holds the LNA TIA DC offset calibration values that can be
 * read from MDM hardware registers after calibration is complete.
 */
typedef struct {
    uint32_t lna_tia_lw_dccal_dc0; ///< LNA TIA low gain DC cal 0
    uint32_t lna_tia_lw_dccal_dc1; ///< LNA TIA low gain DC cal 1
    uint32_t lna_tia_lw_dccal_dc2; ///< LNA TIA low gain DC cal 2
    uint32_t lna_tia_lw_dccal_dc3; ///< LNA TIA low gain DC cal 3
    uint32_t lna_tia_md_dccal_dc0; ///< LNA TIA medium gain DC cal 0
    uint32_t lna_tia_md_dccal_dc1; ///< LNA TIA medium gain DC cal 1
    uint32_t lna_tia_md_dccal_dc2; ///< LNA TIA medium gain DC cal 2
    uint32_t lna_tia_md_dccal_dc3; ///< LNA TIA medium gain DC cal 3
    uint32_t lna_tia_hg_dccal_dc0; ///< LNA TIA high gain DC cal 0
    uint32_t lna_tia_hg_dccal_dc1; ///< LNA TIA high gain DC cal 1
    uint32_t lna_tia_hg_dccal_dc2; ///< LNA TIA high gain DC cal 2
    uint32_t lna_tia_hg_dccal_dc3; ///< LNA TIA high gain DC cal 3
} dc_offset_cal_data_t;

/**
 * @brief Trigger DC offset calibration
 *
 * This function triggers the hardware calibration process and returns
 * the result. It uses the existing hw_cfg_core_attempt_calibration()
 * function.
 *
 * @return true if calibration succeeded, false otherwise
 */
bool atm_dc_offset_cal_trigger(void);

/**
 * @brief Read DC offset calibration values from hardware registers
 *
 * This function reads the calibration data from hardware registers
 * after calibration has been completed and fills the provided data structure.
 *
 * @param[out] cal_data Pointer to structure to store calibration data
 * @return true if data was successfully read, false otherwise
 */
__NONNULL_ALL
bool atm_dc_offset_cal_read_values(dc_offset_cal_data_t *cal_data);

/**
 * @brief Store DC offset calibration data to secure journal
 *
 * This function stores the provided calibration data to the secure journal
 * for persistent storage using a sec_jrnl_append implementation.
 *
 * @param[in] cal_data Pointer to calibration data to store
 * @return true if data was successfully stored, false otherwise
 */
__NONNULL_ALL
bool atm_dc_offset_cal_store_to_sec_jrnl(dc_offset_cal_data_t const *cal_data);

/**
 * @brief Perform complete DC offset calibration and store results
 *
 * This is a convenient function that combines all three operations:
 * 1. Trigger calibration
 * 2. Read calibration values
 * 3. Store to secure journal
 *
 * @return true if all operations succeeded, false otherwise
 */
bool atm_dc_offset_cal_trigger_and_save(void);

#ifdef __cplusplus
}
#endif

/// @} DC_OFFSET_CAL
