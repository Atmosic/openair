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

typedef enum {
    XTAL_32K_P0 = 0,
    XTAL_32K_P4 = 4,
    XTAL_32K_P6 = 6,
    XTAL_32K_P7 = 7,
    XTAL_32K_P8 = 8,
    XTAL_32K_P14 = 14,
    XTAL_32K_P15 = 15,
    XTAL_32K_P22 = 22,
    XTAL_32K_P23 = 23,
    XTAL_32K_P26 = 26,
    XTAL_32K_P27 = 27,
    XTAL_32K_P28 = 28,
    XTAL_32K_P29 = 29,
    XTAL_32K_P30 = 30,
} xtal_32k_pin_t;

#define DISABLE_TXCW_MODE_VAL 0xFF

/**
 * @brief Enable or disable TXCW mode.
 * @param[in] channel_idx Channel index to enable TXCW mode (0xFF to disable).
 */
void atm_vendor_drv_en_txcw_mode(uint8_t channel_idx);

// bit Defines for WFI, NO_CLOCK power config, used in power measure tests
#define PWR_BP_FREQ_ADJUST 0x0001
#define PWR_BLE52_DISABLE 0x0002
#define PWR_MDM_CLK_DISABLE 0x0004
#define PWR_RRAM_SD 0x0008

/**
 * @brief Perform power measurement prologue work.
 * @param[in] power_config_mode Power configuration mode.
 * @param[in] bp_freq Backplane frequency in MHz.
 *                    - 0: Represents 0.5 MHz.
 *                    - Non-zero values indicate actual MHz frequency.
 */
void atm_vendor_drv_power_measure_prologue_work(uint16_t power_config_mode,
    uint8_t bp_freq);

/**
 * @brief Extend the watchdog timer.
 */
void atm_vendor_drv_extend_wdog_timer(void);

/**
 * @brief Recover the watchdog timer.
 */
void atm_vendor_drv_recover_wdog_timer(void);

/**
 * @brief Bring out the clock MPC on the debug bus.
 */
void atm_vendor_drv_bring_out_clk_mpc_on_debug_bus(void);

/**
 * @brief Disable the MPC clock.
 */
void atm_vendor_drv_disable_mpc_clk(void);

/**
 * @brief Set the crystal capacitor value.
 * @param[in] rx_byte The received byte value to set the capacitor.
 */
void atm_vendor_drv_xtal_cap_set(uint8_t rx_byte);

/**
 * @brief Select the 32kHz crystal pin output.
 * @param[in] pin The pin to select.
 * @return true if the pin selection is successful.
 */
bool atm_vendor_drv_xtal_32k_pin_out_sel(xtal_32k_pin_t pin);

#ifdef __cplusplus
}
#endif

///@}
