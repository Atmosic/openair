/**
 *******************************************************************************
 *
 * @file atm_vendor.h
 *
 * @brief Header File - HCI Vendor Command
 *
 * Copyright (C) Atmosic 2020-2024
 *
 *******************************************************************************
 */

#pragma once

#ifdef CONFIG_SOC_FAMILY_ATM
#include "compiler.h"
#endif

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
#define AG_RF_POWER_MAX 7

#ifdef CHK_BUILD
#define APP_TRACE DEBUG_TRACE
#else
#define APP_TRACE(fmt, ...) DEBUG_TRACE_COND(0, fmt, ##__VA_ARGS__)
#endif

#ifdef GPIO_CTRL
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
/**
 * @brief Enable and initial HCI vendor
 */
void atm_vendor_init(void);
#else
#ifndef CFG_RUNTIME_EN_HCI_VENDOR
/**
 * @brief Enable and initial HCI vendor
 */
void vendor_specific_init(void);
#endif
#endif // CONFIG_SOC_FAMILY_ATM

#ifdef __cplusplus
}
#endif

///@}
