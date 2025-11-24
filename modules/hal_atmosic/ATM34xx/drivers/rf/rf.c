/**
 *******************************************************************************
 *
 * @file rf.c
 *
 * @brief Radio initialization and specific functions
 *
 * Copyright (C) Atmosic 2020-2025
 *
 *******************************************************************************
 */

#ifdef CONFIG_SOC_FAMILY_ATM
#include <zephyr/kernel.h>
#include <soc.h>
#include <zephyr/init.h>
#endif

#include "arch.h"
#include "ll_api.h"
#include "rf_api.h"
#include "radio_hal_common.h"
#include "pal_radio_rf.h"

#define RF_INTERNAL_GUARD
#include "rf_internal.h"

#ifndef CFG_CONN_TX_PWR
#define CFG_CONN_TX_PWR 0
#endif

#define UNSET_FORCE_TX_PWR_VALUE 255

#ifdef CONFIG_SOC_FAMILY_ATM
STATIC_ASSERT(CONFIG_FORCE_TX_PWR == UNSET_FORCE_TX_PWR_VALUE ||
    (CONFIG_FORCE_TX_PWR >= -20 && CONFIG_FORCE_TX_PWR <= 10),
    "CONFIG_FORCE_TX_PWR must be UNSET_FORCE_TX_PWR_VALUE (disabled) or -20..10");
#else
#define CFG_MAX_TX_PWR_UB 10
STATIC_ASSERT(CONFIG_MAX_TX_PWR <= CFG_MAX_TX_PWR_UB,
    "MAX_TX_PWR value exceeds the upper bound");
STATIC_ASSERT(CONFIG_MAX_TX_PWR >= CFG_ADV_TX_PWR, "ADV TX power exceeds");
#endif
STATIC_ASSERT(CONFIG_MAX_TX_PWR >= CFG_CONN_TX_PWR, "CONN TX power exceeds");

static int8_t txpwr_max_dbm = CONFIG_MAX_TX_PWR;
static int8_t txpwr_con_dbm = CFG_CONN_TX_PWR;
#ifndef CONFIG_SOC_FAMILY_ATM
static int8_t txpwr_adv_dbm = CFG_ADV_TX_PWR;
#endif

int8_t rf_set_txpwr_maximum_val(int8_t txpwr_dbm)
{
    if ((txpwr_dbm < txpwr_con_dbm)
#ifndef CONFIG_SOC_FAMILY_ATM
	|| (txpwr_dbm < txpwr_adv_dbm)
#endif
	) {
	return INVALID_TX_POWER_VALUE;
    }
    PalRadioRfSetMaxTxPower(txpwr_dbm);
    txpwr_max_dbm = atm_mac_get_tx_power_level(
	atm_mac_get_tx_power_index(txpwr_dbm));
    return txpwr_max_dbm;
}

static bool rf_chk_pwr_range(int8_t tx_pwr_dbm)
{
    if (tx_pwr_dbm > txpwr_max_dbm) {
	return false;
    }
    return true;
}

int8_t rf_set_cs_txpwr_val(uint16_t conhdl, int8_t txpwr_dbm)
{
    if (!rf_chk_pwr_range(txpwr_dbm)) {
	return INVALID_TX_POWER_VALUE;
    }
    txpwr_con_dbm = PalRadioGetActualTxPower(txpwr_dbm);
    LlSetAllPhyTxPowerLevel(conhdl, txpwr_con_dbm);
    return atm_mac_get_tx_power_level(
	atm_mac_get_tx_power_index(txpwr_con_dbm));
}

atm_txpwr_ovr_key rf_set_txpwr_override(int8_t txpwr_dbm)
{
    uint8_t gain_index = atm_mac_get_tx_power_index(txpwr_dbm);

    return (rf_core_set_txpwr_override(gain_index));
}

void rf_restore_txpwr_override(atm_txpwr_ovr_key key)
{
    rf_core_restore_txpwr_override(key);
}

bool rf_set_txpwr_advertising_val(int8_t txpwr_dbm)
{
    if (!rf_chk_pwr_range(txpwr_dbm)) {
	return false;
    }
#ifdef CONFIG_SOC_FAMILY_ATM
    LlSetAdvTxPower(PalRadioGetActualTxPower(txpwr_dbm));
#else
    txpwr_adv_dbm = PalRadioGetActualTxPower(txpwr_dbm);
#endif
    return true;
}

#ifndef CONFIG_SOC_FAMILY_ATM
int rf_get_txpwr_advertising_val(void)
{
    return txpwr_adv_dbm;
}
#endif

#ifndef CONFIG_SOC_FAMILY_ATM
__attribute__((constructor))
#endif
static void rf_init(void)
{
    rf_set_txpwr_maximum_val(CONFIG_MAX_TX_PWR);
#if defined(CONFIG_FORCE_TX_PWR) && \
    (CONFIG_FORCE_TX_PWR != UNSET_FORCE_TX_PWR_VALUE)
    // Vector replacement
    rf_set_txpwr_override(CONFIG_FORCE_TX_PWR);
#endif
}

#ifdef CONFIG_SOC_FAMILY_ATM
static int sys_rf_init(void)
{
    rf_init();
    return 0;
}
SYS_INIT(sys_rf_init, POST_KERNEL, CONFIG_KERNEL_INIT_PRIORITY_DEVICE);
#endif
