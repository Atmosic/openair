/**
 *******************************************************************************
 *
 * @file atm_cs.h
 *
 * @brief Atmosic Channel Sounding middleware
 *
 * Copyright (C) Atmosic 2025
 *
 *******************************************************************************
 */

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @defgroup ATM_CS_API Channel Sounding API
 * @ingroup ATM_CS_API
 * @brief Channel Sounding middleware for precise distance measurement and
 *        ranging.
 *
 * This module provides Channel Sounding (CS) functionality for Bluetooth-based
 * ranging operations. It supports both individual and shared advertising modes,
 * connection management, and reflector operations for distance measurement.
 *
 * The CS middleware integrates with the Bluetooth stack to provide:
 * - CS reflector functionality for ranging operations
 * - Individual advertising mode for dedicated CS discovery
 * - Connection management and pairing operations
 * - Integration with Fast Pair services when configured
 *
 * @{
 */

/**
 * @brief Unpair CS reflector
 *
 * @note This function should be called when resetting the device or when pairing needs to be
 *       cleared for ATM_CS_ADV_BT_ID.
 *
 * @warning Calling this function will remove all pairing information for ATM_CS_ADV_BT_ID and may
 *          affect other services using the same ID.
 */
void atm_cs_rrsp_unpair(void);

/**
 * @brief Initialize CS reflector
 *
 * Configures the CS reflector functionality and prepares the module for operation.
 * This function should be called during system initialization before any other CS APIs.
 *
 * @note This function must be called before starting CS advertising.
 *
 * @see atm_cs_rrsp_start_adv() to start advertising
 */
void atm_cs_rrsp_init(void);

/**
 * @brief Start CS reflector advertising
 *
 * Initiates extended advertising for CS reflector functionality on ATM_CS_ADV_BT_ID.
 * The advertising includes CS-specific data with RAS UUID and runs independently
 *
 * The advertising will continue until:
 * - A connection is established
 * - Timeout occurs (if configured)
 * - Manually stopped via atm_cs_rrsp_stop_adv()
 *
 * @note The advertising uses ATM_CS_ADV_BT_ID (0) for CS-specific discovery
 *
 * @see atm_cs_rrsp_stop_adv() to stop advertising
 */
void atm_cs_rrsp_start_adv(void);

/**
 * @brief Stop CS reflector advertising
 *
 * Stops the current CS advertising and cleans up associated resources.
 * This function is safe to call even if no advertising is currently active.
 *
 * After calling this function:
 * - CS advertising will be stopped immediately
 * - Advertising resources will be freed
 * - The device will no longer be discoverable for CS connections
 *
 * @note Safe to call multiple times or when advertising is not active
 *
 * @see atm_cs_rrsp_start_adv() to start advertising
 */
void atm_cs_rrsp_stop_adv(void);

/**
 * @}
 */

#ifdef __cplusplus
}
#endif
