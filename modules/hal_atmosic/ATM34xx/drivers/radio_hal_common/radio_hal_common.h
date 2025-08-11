/**
 ******************************************************************************
 *
 * @file radio_hal_common.h
 *
 * @brief ATLC Driver Common Interface
 *
 * Copyright (C) Atmosic 2022-2025
 *
 ******************************************************************************
 */

#pragma once

#include "arch.h"
#include "at_lc.h"
#include "at_lc_states.h"
#include "at_lc_regs_core_macro.h"
#include <stdint.h>
#include <inttypes.h>

/**
 * @defgroup RADIO_HAL_COMMON RADIO_HAL_COMMON
 * @ingroup DRIVERS
 * @brief ATLC Driver Common Interface
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

// Misc ATLC value definitions
#define DISABLE 0
#define ENABLE 1

// ATLC_*_CTRL0:SYNC_EN (sync word selection) subfield values
#define ATLC_CTRL0_SYNC_EN_NONE 0
#define ATLC_CTRL0_SYNC_EN_WORD_1 1
#define ATLC_CTRL0_SYNC_EN_WORD_2 2
#define ATLC_CTRL0_SYNC_EN_BOTH 3

// ATLC_*_CTRL0:AT_LC_MD (ATLC mode) subfield values
#define ATLC_CTRL0_AT_LC_MD_LEGACY 0
#define ATLC_CTRL0_AT_LC_MD_ATLC 1

#define ATLC_CMD_BLE_MASK 0x40000000
#define ATLC_CMD_154_MASK 0x80000000
#define ATLC_CMD_CMN_MASK 0xC0000000

#ifdef ENABLE_ATLC_CMD_DEBUG
#define NUM_ATLC_CMD_DEBUG 4
extern uint32_t last_atlc_cmd[NUM_ATLC_CMD_DEBUG];
extern uint32_t atlc_cmd_count;

#define WRITE_ATLC_CMD(x, mask) do { \
    last_atlc_cmd[atlc_cmd_count++ % NUM_ATLC_CMD_DEBUG] = mask | x; \
    CMSDK_ATLC_NONSECURE->CMD = x; \
} while (0)
#else
#define WRITE_ATLC_CMD(x, mask) do { \
    CMSDK_ATLC_NONSECURE->CMD = x; \
} while (0)
#endif

#define ATLC_CMD_US_EN(x, mask) \
    WRITE_ATLC_CMD(ATLC_CMD__CMD_US_EN__MASK | ATLC_CMD__VL__WRITE(x), mask)

#define ATLC_CMD_NOW(x, mask) WRITE_ATLC_CMD(ATLC_CMD__VL__WRITE(x), mask)

// Use ATLC_LC_CTRL6__HGCLKEN__MODIFY(CMSDK_ATLC_NONSECURE->LC_CTRL6, en) to
// enable and disable hclk if hw is ready for this feaure
#define TCM_CLK_EN(en) do { \
} while (0)

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
#define NUM_BYTES_PER_TCM_WORD 4
#define TCM_TFF0_ST_OFFSET        0x000
#define TCM_TFF0_ED_OFFSET        0x1FE
#define TCM_RFF0_ST_OFFSET        0x200
#define TCM_RFF0_ED_OFFSET        0x3FE
#define TX_DATA_BUFFER_TCM_OFFSET 0x600
#define ACK_154_BUFFER_TCM_OFFSET 0x700

// TX Descriptor
#define NUM_TX_DESCRIPTOR_WORDS 2

// Transmit power levels
#define MIN_TX_POWER_DBM -20
#define MAX_TX_POWER_DBM 10
// Transmit power index
enum {
    ATM_RF_POWER_LVL_LOWEST,
    ATM_RF_POWER_MINUS_20_DBM = ATM_RF_POWER_LVL_LOWEST,
    ATM_RF_POWER_MINUS_10_DBM,
    ATM_RF_POWER_MINUS_8_DBM,
    ATM_RF_POWER_MINUS_6_DBM,
    ATM_RF_POWER_MINUS_4_DBM,
    ATM_RF_POWER_MINUS_2_DBM,
    ATM_RF_POWER_0_DBM,
    ATM_RF_POWER_2_DBM,
    ATM_RF_POWER_4_DBM,
    ATM_RF_POWER_6_DBM,
    ATM_RF_POWER_8_DBM,
    ATM_RF_POWER_10_DBM,
    ATM_RF_POWER_LVL_HIGHEST = ATM_RF_POWER_10_DBM,
    ATM_RF_POWER_LVL_NUM
};

// ATLC Appended Rx Status
#define APPENDED_STATUS_CRC_ERR_READ(src) ((uint8_t)(src)&0x1U)
#define APPENDED_STATUS_MIC_ERR_READ(src) ((uint8_t)((src) >> 3) & 0x1U)

typedef void (*atm_mac_idle_callback_t)(void);
typedef bool (*atm_mac_irq_handler_t)(void);
typedef void (*atm_mac_switch_callback_t)(bool mode_154);
typedef void (*atm_mac_switch_ch_base_callback_t)(uint32_t ch_base);
typedef bool (*atm_mac_atlc_prof_check_callback_t)(uint16_t latency);

extern bool volatile atm_mac_is_sleeping;
extern bool atm_mac_is_in_low_latency;

/**
 * @brief Get ATLC TX Power Level
 *
 * This function is used to get the radio tx power level.
 *
 * @return       TX power level
 */
int8_t atm_mac_get_tx_power_level(uint8_t index);

/**
 * @brief Get ATLC TX Power Index
 *
 * This function is used to get the radio tx power index.
 *
 * @return       TX power index
 */
uint8_t atm_mac_get_tx_power_index(int8_t power_level);

/**
 * @brief Register ATLC Idle Callback
 *
 * This function is used to register a callback for when ATLC goes idle.
 *
 * @param[in]    callback       Callback Function
 */
__NONNULL(1)
void atm_mac_register_idle_callback(atm_mac_idle_callback_t callback);

/**
 * @brief Register ATLC IRQ Handler
 *
 * This function is used to register a callback for the ATLC IRQ Handler.
 *
 * @param[in]    handler       Handler Function
 */
__NONNULL(1)
void atm_mac_register_irq_handler(atm_mac_irq_handler_t handler);

/**
 * @brief Register ATLC Mode Switch Callback
 *
 * This function is used to register a callback when switching ATLC modes.
 *
 * @param[in]    callback       Callback Function
 */
__NONNULL(1)
void atm_mac_register_switch_callback(atm_mac_switch_callback_t callback);

/**
 * @brief Stop ATLC Radio
 *
 * This function is used to stop radio for TX/RX command of the ATLC.
 *
 */
__STATIC_INLINE void atm_mac_radio_stop(void)
{
    ATLC_CMD_NOW(AT_LC_CMD_ABRT, ATLC_CMD_CMN_MASK);
    // The ATLC will not be ready for another operation until it has returned
    // to idle. Transitioning this state will take at most 5 cycles at 16 MHz.
    while (ATLC_LC_ST4__FLW_ST__READ(CMSDK_ATLC_NONSECURE->LC_ST4) !=
	FLW_ST_IDL) {
    }
}

/**
 * @brief Switch ATLC Mode
 *
 * This function is used to switch ATLC modes.
 *
 * @param[in]    mode_154       True for 15.4, False for BLE
 */
void atm_mac_radio_switch_mode(bool mode_154);

/**
 * @brief Register ATLC Channel Base Switch Callback
 *
 * This function is used to register a callback when switching ATLC radio base
 * channel.
 *
 * @param[in]    callback       Callback Function
 */
__NONNULL(1)
void atm_mac_register_switch_ch_base_callback(atm_mac_switch_ch_base_callback_t
    callback);

/**
 * @brief Switch ATLC Channel Base
 *
 * This function is used to switch ATLC Radio Channel Base.
 *
 * @param[in]    ch_base      Radio channel base configuration
 */
void atm_mac_radio_switch_ch_base(uint32_t ch_base);

/**
 * @brief Register atlc profile check callback
 *
 * This function is used to register atlc profile check callback to decide if
 * bypass current failure.
 *
 * @param[in]    cb       Callback to decide if bypass current profile failure
 */
__NONNULL(1)
void atm_mac_register_atlc_prof_check_cb(atm_mac_atlc_prof_check_callback_t cb);

/**
 * @brief Get tx_infnt
 *
 * This function is used to get tx_infnt.
 *
 *  \return     True infinite Tx
 *  \return     False finite Tx
 */
__STATIC_INLINE bool atm_mac_get_tx_infnt(void)
{
    return ATLC_LC_RFT_CTRL0__TX_INFNT__READ(
	CMSDK_ATLC_NONSECURE->LC_RFT_CTRL0);
}

/**
 * @brief Dump debug info for ATLC_CMD
 *
 * This function is a no-op unless ENABLE_ATLC_CMD_DEBUG is set
 */
__STATIC_INLINE void atm_mac_dump_atlc_cmd_debug(void)
{
#ifdef ENABLE_ATLC_CMD_DEBUG
    DEBUG_TRACE("Total ATLC command writes: %" PRIu32, atlc_cmd_count);
    for (int i = 0; (i < NUM_ATLC_CMD_DEBUG) && (i < atlc_cmd_count); i++) {
	uint32_t index = (atlc_cmd_count + i) % NUM_ATLC_CMD_DEBUG;
	DEBUG_TRACE("ATLC CMD write 0x%" PRIx32, last_atlc_cmd[index]);
    }
#endif
}

/**
 * @brief Get 32 random bits
 *
 */
uint32_t atm_mac_rand(void);

#ifdef __cplusplus
}
#endif

/// @}
