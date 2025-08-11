/**
 ******************************************************************************
 *
 * @file radio_hal_common.c
 *
 * @brief ATLC Driver Common Interface
 *
 * Copyright (C) Atmosic 2022-2025
 *
 ******************************************************************************
 */

#ifdef CONFIG_SOC_FAMILY_ATM
#include <zephyr/kernel.h>
#include <soc.h>
#include <zephyr/init.h>
#include <zephyr/random/random.h>
#endif

#include "arch.h"
#include "at_wrpr.h"
#include "vectors.h"

#include "radio_hal_common.h"
#define RADIO_HAL_COMMON_INTERNAL_GUARD
#include "radio_hal_common_internal.h"

static atm_mac_switch_callback_t switch_callback;
static atm_mac_switch_ch_base_callback_t switch_ch_base_callback;

#ifdef CONFIG_SOC_FAMILY_ATM
ISR_DIRECT_DECLARE(ATLC_Handler)
#else
void ATLC_Handler(void)
#endif
{
    atm_mac_handler();
#ifdef CONFIG_SOC_FAMILY_ATM
    return 0;
#endif
}

#ifndef CONFIG_SOC_FAMILY_ATM
__attribute__((constructor))
#endif
static void atm_mac_init(void)
{
    atm_mac_rev_hash_check();

    // take MDM out of reset
    WRPR_CTRL_SET(CMSDK_MDM, WRPR_CTRL__CLK_DISABLE);

    // Setup ATLC IRQ
    NVIC_DisableIRQ(ATLC_IRQn);
    NVIC_ClearPendingIRQ(ATLC_IRQn);
    CMSDK_ATLC_NONSECURE->LC_IRQC = CMSDK_ATLC_NONSECURE->LC_IRQ;
#ifdef CONFIG_SOC_FAMILY_ATM
    BUILD_ASSERT(IRQ_PRI_VERY_HIGH < _IRQ_PRIO_OFFSET, "ZLL too small");
    IRQ_DIRECT_CONNECT(ATLC_IRQn, IRQ_PRI_VERY_HIGH, ATLC_Handler,
	IRQ_ZERO_LATENCY);
    irq_enable(ATLC_IRQn);
#else
    NVIC_SetPriority(ATLC_IRQn, IRQ_PRI_VERY_HIGH);
    NVIC_EnableIRQ(ATLC_IRQn);
#endif

    atm_mac_core_init();
}

#ifdef CONFIG_SOC_FAMILY_ATM
static int atm_mac_sys_init(void)
{
    atm_mac_init();
    return 0;
}

SYS_INIT(atm_mac_sys_init, PRE_KERNEL_2, 10);
#endif

static int8_t const valid_tx_power_levels[ATM_RF_POWER_LVL_NUM] =
{
  [ATM_RF_POWER_MINUS_20_DBM] = -20,
  [ATM_RF_POWER_MINUS_10_DBM] = -10,
  [ATM_RF_POWER_MINUS_8_DBM] = -8,
  [ATM_RF_POWER_MINUS_6_DBM] = -6,
  [ATM_RF_POWER_MINUS_4_DBM] = -4,
  [ATM_RF_POWER_MINUS_2_DBM] = -2,
  [ATM_RF_POWER_0_DBM] = 0,
  [ATM_RF_POWER_2_DBM] = 2,
  [ATM_RF_POWER_4_DBM] = 4,
  [ATM_RF_POWER_6_DBM] = 6,
  [ATM_RF_POWER_8_DBM] = 8,
  [ATM_RF_POWER_10_DBM] = 10,
};

int8_t atm_mac_get_tx_power_level(uint8_t index)
{
    if (index > ATM_RF_POWER_LVL_HIGHEST) {
	index = ATM_RF_POWER_LVL_HIGHEST;
    }
    return valid_tx_power_levels[index];
}

uint8_t atm_mac_get_tx_power_index(int8_t power_level)
{
    uint8_t index;
    for (index = ATM_RF_POWER_LVL_HIGHEST; index > 0; index--) {
	if (power_level >= valid_tx_power_levels[index]) {
	    return index;
	}
    }
    return 0;
}

void atm_mac_register_switch_callback(atm_mac_switch_callback_t callback)
{
    switch_callback = callback;
}

void atm_mac_radio_switch_mode(bool mode_154)
{
    static bool mode_154_enabled = false;
    if ((switch_callback) && (mode_154_enabled != mode_154)) {
	mode_154_enabled = mode_154;
	switch_callback(mode_154);
    }
}

void atm_mac_register_switch_ch_base_callback(atm_mac_switch_ch_base_callback_t
    callback)
{
    switch_ch_base_callback = callback;
}

void atm_mac_radio_switch_ch_base(uint32_t ch_base)
{
    if (switch_ch_base_callback) {
	switch_ch_base_callback(ch_base);
    }
}

uint32_t atm_mac_rand(void)
{
#ifdef CONFIG_SOC_FAMILY_ATM
    return sys_rand32_get();
#else
    return rand();
#endif
}
