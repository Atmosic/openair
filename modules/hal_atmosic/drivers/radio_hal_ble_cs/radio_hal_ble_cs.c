/**
 *******************************************************************************
 *
 * @file radio_hal_ble_cs.c
 *
 * @brief Channel sounding driver
 *
 * Copyright (C) Atmosic 2024-2026
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 *
 *******************************************************************************
 */

#include "arch.h"
#include "radio_hal_ble_cs.h"
#ifdef LDO_MODE_EN
#include "hw_cfg.h"
#endif

#ifndef CONFIG_RF_DELAY_ONE_EIGHTH_NS
#define CONFIG_RF_DELAY_ONE_EIGHTH_NS 18
#endif

static uint16_t rf_delay_one_eighth_ns = CONFIG_RF_DELAY_ONE_EIGHTH_NS;

uint8_t atm_mac_ble_cs_phase_adj_en =
#ifdef REF_PHS_CORR_SUPP
    1;
#else
    0;
#endif

uint16_t atm_mac_ble_cs_get_rf_delay_one_eighth_ns(void)
{
    return rf_delay_one_eighth_ns;
}

void atm_mac_ble_cs_set_rf_delay_one_eighth_ns(uint16_t delay)
{
    ASSERT_INFO(delay <= ATM_MAC_BLE_CS_RF_DELAY_MAX, delay,
	ATM_MAC_BLE_CS_RF_DELAY_MAX);
    rf_delay_one_eighth_ns = delay;
}

bool atm_mac_ble_cs_adjust_phase(void)
{
    return atm_mac_ble_cs_phase_adj_en;
}

void atm_mac_ble_enable_cs_ldo(bool enable)
{
#ifdef LDO_MODE_EN
    if (atm_mac_ble_ldo_enable) {
	atm_mac_ble_ldo_enable(enable);
    }
#endif
}

void atm_mac_ble_set_cs_ldo(bool enable)
{
#ifdef LDO_MODE_EN
    hw_cfg_set_ldo(enable);
#endif
}
