/*
 * SPDX-License-Identifier: LicenseRef-Atmosic
 * Copyright (c) 2025-2026 Atmosic
 */

#pragma once

#include <zephyr/kernel.h>
#include <stdint.h>
#include "at_cmd_callbacks.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief AT command state machine states
 */
typedef enum {
	ATCMD_ST_IDLE,
	ATCMD_ST_IN,
	ATCMD_ST_PROCESSING
} atcmd_st_t;

/**
 * @brief Lock state enumeration
 */
typedef enum {
	UNLOCK_UPD,
	LOCK_UPD,
} lock_st_t;

/**
 * @brief Initialize AT command manager
 *
 * @return 0 on success, negative error code on failure
 */
int at_cmd_manager_init(void);

/**
 * @brief Set device name via AT command
 *
 * @param name Device name string
 * @param len Length of device name
 * @return at_cmd_ext_err_t error code
 */
at_cmd_ext_err_t at_cmd_set_device_name(const uint8_t *name, uint16_t len);

/**
 * @brief Set advertising interval via AT command
 *
 * @param interval Advertising interval in units of 0.625ms
 * @return at_cmd_ext_err_t error code
 */
at_cmd_ext_err_t at_cmd_set_adv_interval(uint32_t interval);

/**
 * @brief Set advertising data via AT command
 *
 * @param data Advertising data buffer
 * @param len Length of advertising data
 * @return at_cmd_ext_err_t error code
 */
at_cmd_ext_err_t at_cmd_set_adv_data(const uint8_t *data, uint16_t len);

/**
 * @brief Reset device via AT command
 *
 * @return at_cmd_ext_err_t error code
 */
at_cmd_ext_err_t at_cmd_reset_device(void);

/**
 * @brief Unlock update procedure via AT command
 *
 * @param key Unlock key string
 * @param len Length of unlock key
 * @return at_cmd_ext_err_t error code
 */
at_cmd_ext_err_t at_cmd_unlock_update_proc(const uint8_t *key, uint16_t len);

/**
 * @brief Check if device is unlocked for AT command operations
 *
 * @return at_cmd_ext_err_t AT_CMD_EXT_ERR_SUCCESS if unlocked, AT_CMD_EXT_ERR_UNLOCK_REQUIRED if
 * locked
 */
at_cmd_ext_err_t at_cmd_check_unlock_state(void);

/**
 * @brief Initialize unlock state (device starts locked)
 */
void at_cmd_unlock_init(void);

/**
 * @brief Handle connection events for unlock state management
 *
 * @param connected true if connected, false if disconnected
 */
void at_cmd_connection_event(bool connected);

#ifdef __cplusplus
}
#endif
