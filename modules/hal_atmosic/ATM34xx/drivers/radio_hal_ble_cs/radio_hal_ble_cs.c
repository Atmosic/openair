/**
 *******************************************************************************
 *
 * @file radio_hal_ble_cs.c
 *
 * @brief Channel sounding driver
 *
 * Copyright (C) Atmosic 2024-2025
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

uint32_t atm_mac_ble_cs_get_rf_delay_one_eighth_ns(void)
{
    return CONFIG_RF_DELAY_ONE_EIGHTH_NS;
}

bool atm_mac_ble_cs_adjust_phase(void)
{
#ifdef REF_PHS_CORR_SUPP
    return true;
#else
    return false;
#endif
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
