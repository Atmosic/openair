/**
 ******************************************************************************
 *
 * @file radio_hal_common.c
 *
 * @brief ATLC Driver Common Interface
 *
 * Copyright (C) Atmosic 2022-2026
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 *
 ******************************************************************************
 */

#ifdef CONFIG_SOC_FAMILY_ATM
#include <zephyr/kernel.h>
#include <zephyr/devicetree.h>
#include <zephyr/sys/util.h>
#include <soc.h>
#include <zephyr/init.h>
#include <zephyr/random/random.h>

#define ATMBLE DT_INST(0, atmosic_ble)
#endif

#include "arch.h"
#include "at_wrpr.h"
#include "hw_cfg.h"
#include "vectors.h"

#include "radio_hal_common.h"
#define RADIO_HAL_COMMON_INTERNAL_GUARD
#include "radio_hal_common.ih"

/*
TCM layout
0x40128000     ATLC_TCM_NONSECURE_BASE
0x000 - 0x1FE  TFF0
0x200 - 0x3FE  RFF0
0x600 - 0x6FE  TX_DATA_BUFFER
0x700 - 0x7FF  ACK_154_BUFFER
0x401287FF     END

Current 15.4 usage
 - TFF0 8 bytes (two descriptor words)
 - RFF0 128 bytes (max 15.4 packet size)
 - TX_DATA_BUFFER 128 bytes (max 15.4 packet size)
 - ACK_154_BUFFER 128 bytes (max 15.4 packet size)
Current BLE usage
 - TFF0 8 bytes (two descriptor words)
 - RFF0 257 bytes (max BLE packet size)
 - TX_DATA_BUFFER 257 bytes (max BLE packet size)
*/

#define ATLC_FIFO_UNIT 2
#ifdef CONFIG_SOC_FAMILY_ATM
#if DT_NODE_EXISTS(DT_NODELABEL(atlc_tcm))
/* Access child nodes via labels */
#define UNUSED_TCM_ADDR 0
#define UNUSED_TCM_SIZE 0

/* Helper macro to safely get reg property or use default using COND_CODE_1 */
#define ATLC_TCM_REG_ADDR(label) \
    COND_CODE_1(DT_NODE_EXISTS(DT_NODELABEL(label)), \
	(DT_REG_ADDR(DT_NODELABEL(label))), (UNUSED_TCM_ADDR))
#define ATLC_TCM_REG_SIZE(label) \
    COND_CODE_1(DT_NODE_EXISTS(DT_NODELABEL(label)), \
	(DT_REG_SIZE(DT_NODELABEL(label))), (UNUSED_TCM_SIZE))

#define TFF0_ST_OFFSET         ATLC_TCM_REG_ADDR(tff0)
#define TFF0_SIZE              ATLC_TCM_REG_SIZE(tff0)
#define RFF0_ST_OFFSET         ATLC_TCM_REG_ADDR(rff0)
#define RFF0_SIZE              ATLC_TCM_REG_SIZE(rff0)
#define TX_DATA_BUF_TCM_OFFSET ATLC_TCM_REG_ADDR(tx_buffer)
#define ACK_154_BUF_TCM_OFFSET ATLC_TCM_REG_ADDR(ack_154)
#else
#error "atlc_tcm device tree node is required for Zephyr builds"
#endif
#else // CONFIG_SOC_FAMILY_ATM
#define TFF0_ST_OFFSET         0x000
#define TFF0_SIZE              0x200
#define RFF0_ST_OFFSET         0x200
#define RFF0_SIZE              0x200
#define TX_DATA_BUF_TCM_OFFSET 0x600
#define ACK_154_BUF_TCM_OFFSET 0x700
#endif // CONFIG_SOC_FAMILY_ATM

uint16_t const atlc_tff0_st_offset = TFF0_ST_OFFSET;
uint16_t const atlc_rff0_st_offset = RFF0_ST_OFFSET;
uint16_t const atlc_tx_buf_tcm_offset = TX_DATA_BUF_TCM_OFFSET;
uint16_t const atlc_ack_154_buf_tcm_offset = ACK_154_BUF_TCM_OFFSET;
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
#ifdef NVIC
    NVIC_DisableIRQ(ATLC_IRQn);
    NVIC_ClearPendingIRQ(ATLC_IRQn);
#endif
    CMSDK_ATLC_NONSECURE->LC_IRQC = CMSDK_ATLC_NONSECURE->LC_IRQ;
#ifdef CONFIG_SOC_FAMILY_ATM
#ifdef _IRQ_PRIO_OFFSET
    BUILD_ASSERT(DT_IRQ_BY_NAME(ATMBLE, atlc, priority) < _IRQ_PRIO_OFFSET,
	"ZLL too small");
#endif
    IRQ_DIRECT_CONNECT(DT_IRQ_BY_NAME(ATMBLE, atlc, irq),
	DT_IRQ_BY_NAME(ATMBLE, atlc, priority), ATLC_Handler, IRQ_ZERO_LATENCY);
    irq_enable(DT_IRQ_BY_NAME(ATMBLE, atlc, irq));
#else // CONFIG_SOC_FAMILY_ATM
    NVIC_SetPriority(ATLC_IRQn, IRQ_PRI_VERY_HIGH);
    NVIC_EnableIRQ(ATLC_IRQn);
#endif // CONFIG_SOC_FAMILY_ATM

    atm_mac_core_init(TFF0_SIZE, RFF0_SIZE);
}

#ifdef CONFIG_SOC_FAMILY_ATM
static int atm_mac_sys_init(void)
{
    atm_mac_init();
    return 0;
}

SYS_INIT(atm_mac_sys_init, PRE_KERNEL_2, 10);
#endif

static int8_t const valid_tx_power_levels[ATM_RF_POWER_LVL_NUM] = {
    [ATM_RF_POWER_MINUS_20_DBM] = -20,
    [ATM_RF_POWER_MINUS_10_DBM] = -10,
    [ATM_RF_POWER_MINUS_8_DBM] = -8,
    [ATM_RF_POWER_MINUS_6_DBM] = -6,
    [ATM_RF_POWER_MINUS_4_DBM] = -4,
    [ATM_RF_POWER_MINUS_2_DBM] = -2,
    [ATM_RF_POWER_0_DBM] = 0,
    [ATM_RF_POWER_2_DBM] = 2,
    [ATM_RF_POWER_4_DBM] = 4,
#if CONFIG_ATM_MAX_TX_POWER_DBM >= 6
    [ATM_RF_POWER_6_DBM] = 6,
#endif
#if CONFIG_ATM_MAX_TX_POWER_DBM >= 8
    [ATM_RF_POWER_8_DBM] = 8,
#endif
#if CONFIG_ATM_MAX_TX_POWER_DBM >= 10
    [ATM_RF_POWER_10_DBM] = 10,
#endif
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
