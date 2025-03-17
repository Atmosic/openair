/**
 *******************************************************************************
 *
 * @file atm_vendor_drv.h
 *
 * @brief HCI Vendor command core driver APIs
 *
 * Copyright (C) Atmosic 2025
 *
 *******************************************************************************
 */

#pragma once

/**
 * @addtogroup HCI Vendor Command core drivers
 * @ingroup DRIVERS
 * @brief HCI Vendor Command core driver
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#define DISABLE_TXCW_MODE_VAL 0xFF

/**
 * @brief Enable or disable TXCW mode.
 * @param[in] channel_idx Channel index to enable TXCW mode (0xFF to disable).
 */
void atm_vendor_drv_en_txcw_mode(uint8_t channel_idx);

/**
 * @brief Set the crystal capacitor value.
 * @param[in] rx_byte The received byte value to set the capacitor.
 */
void atm_vendor_drv_xtal_cap_set(uint8_t rx_byte);

#ifdef __cplusplus
}
#endif

///@}
