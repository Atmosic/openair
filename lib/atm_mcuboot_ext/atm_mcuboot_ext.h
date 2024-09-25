/**
 *******************************************************************************
 *
 * @file atm_mcuboot_ext.h
 *
 * @brief  Atmosic MCUBOOT extensions definitions
 *
 * Copyright (C) Atmosic 2024
 *
 *******************************************************************************
 */
#pragma once

/**
 * @defgroup ATM_MCUBOOT_EXT Atmosic MCUBOOT extensions
 * @ingroup ATM_MCUBOOT
 * @brief ATM MCUBOOT extensions
 *
 * @{
 *
 */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Extension startup entry point.
 *
 */
void atm_mcuboot_ext_startup(void);

/**
 * @brief Check if image validation can be skipped
 * @return true if skip is allowed
 */
bool atm_mcuboot_ext_skip_img_validation(void);

/// slot descriptor for security lockdown
typedef struct {
    uint32_t slot0_offset; // primary slot offset in RRAM
    uint32_t slot0_size; // size of RRAM area to lockdown
    uint32_t slot0_trailer_unlock_size; // unlock size of the slot trailer
} sec_slot_desc_t;

/**
 * @brief Lock image slots
 * @param[in] desc slots security descriptor
 */
__NONNULL(1)
void atm_mcuboot_ext_lock_img_slots(sec_slot_desc_t const *desc);

#ifdef __cplusplus
}
#endif

/// @}
