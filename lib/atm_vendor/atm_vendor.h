/*
 * Copyright (c) 2020-2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#pragma once

#include <stdbool.h>
#include "compiler.h" // __NORETURN inline functions

/**
 * @defgroup ATM_BTFM_VEND HCI Vendor Command
 * @ingroup ATM_BTFM_PROC
 * @brief HCI Vendor Command
 *
 * This module contains the necessary API to deal with vendor command.
 *
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#define AG_VERSION 7

#ifdef CHK_BUILD
#define APP_TRACE DEBUG_TRACE
#else
#define APP_TRACE(fmt, ...) DEBUG_TRACE_COND(0, fmt, ##__VA_ARGS__)
#endif

#ifdef GPIO_CTRL
/**
 * @brief Init GPIO setting for Atmosic Production Tester
 */
void ag_gpio_init(void);
#endif

/**
 * @brief Enter hci vendor mode
 */
__NORETURN void atm_vendor_enter_hci_vendor_mode(void);

/**
 * @brief Exit hci vendor mode
 */
__NORETURN void atm_vendor_exit_hci_vendor_mode(void);

/**
 * @brief Get current hci vendor mode enable status
 * @return Hci vendor mode enable status
 */
bool atm_vendor_get_hci_vendor_en(void);

#ifdef CONFIG_SOC_FAMILY_ATM
#ifdef CFG_VND_BYPASS_RX_DC_CAL
/**
 * @brief Check if RX DC offset calibration on HCI reset is bypassed.
 *
 * Returns true if the BYPASS_RX_DC_CAL vendor command has been received,
 * indicating that calibration should be skipped (e.g. during MPTool testing).
 *
 * @return true if bypass is active, false otherwise.
 */
bool atm_vendor_rx_dc_cal_is_bypassed(void);
#endif

/**
 * @brief Enable and initial HCI vendor
 */
void atm_vendor_init(void);
#elif !defined(CFG_RUNTIME_EN_HCI_VENDOR)
/**
 * @brief Enable and initial HCI vendor
 */
void vendor_specific_init(void);
#endif // CONFIG_SOC_FAMILY_ATM

#ifdef __cplusplus
}
#endif

///@}
