/*
 * SPDX-License-Identifier: Apache-2.0
 * Copyright (c) 2025-2026 Atmosic
 */

#ifndef AT_CMD_CALLBACKS_H
#define AT_CMD_CALLBACKS_H

#include <zephyr/kernel.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief AT Command extension library error codes
 *
 * Standardized error codes used by the AT command extension library and callback functions.
 * This eliminates dependency on application-specific error types.
 */
typedef enum {
	AT_CMD_EXT_ERR_SUCCESS = 0,      /**< Operation completed successfully */
	AT_CMD_EXT_ERR_UNLOCK_REQUIRED,  /**< Device must be unlocked first */
	AT_CMD_EXT_ERR_INVALID_PASSWORD, /**< Invalid unlock password/key */
	AT_CMD_EXT_ERR_WRITE_FAILED,     /**< Write operation failed */
	AT_CMD_EXT_ERR_READ_FAILED,      /**< Read operation failed */
	AT_CMD_EXT_ERR_INVALID_PARAM,    /**< Invalid parameter provided */
	AT_CMD_EXT_ERR_NOT_SUPPORTED,    /**< Operation not supported */
	AT_CMD_EXT_ERR_TIMEOUT,          /**< Operation timed out */
	AT_CMD_EXT_ERR_BUSY,             /**< Resource is busy */
	AT_CMD_EXT_ERR_UNKNOWN           /**< Unknown error */
} at_cmd_ext_err_t;

/**
 * @brief Callback function type for setting device name
 *
 * @param name Device name string
 * @param len Length of device name
 * @return at_cmd_ext_err_t error code
 */
typedef at_cmd_ext_err_t (*at_cmd_set_device_name_cb_t)(const uint8_t *name, uint16_t len);

/**
 * @brief Callback function type for setting advertising interval
 *
 * @param interval Advertising interval in units of 0.625ms
 * @return at_cmd_ext_err_t error code
 */
typedef at_cmd_ext_err_t (*at_cmd_set_adv_interval_cb_t)(uint32_t interval);

/**
 * @brief Callback function type for setting advertising data
 *
 * @param data Advertising data buffer
 * @param len Length of advertising data
 * @return at_cmd_ext_err_t error code
 */
typedef at_cmd_ext_err_t (*at_cmd_set_adv_data_cb_t)(const uint8_t *data, uint16_t len);

/**
 * @brief Callback function type for device reset
 *
 * @return at_cmd_ext_err_t error code
 */
typedef at_cmd_ext_err_t (*at_cmd_reset_device_cb_t)(void);

/**
 * @brief Callback function type for unlock procedure
 *
 * @param key Unlock key string
 * @param len Length of unlock key
 * @return at_cmd_ext_err_t error code
 */
typedef at_cmd_ext_err_t (*at_cmd_unlock_update_proc_cb_t)(const uint8_t *key, uint16_t len);

/**
 * @brief Callback function type for checking unlock state
 *
 * @return at_cmd_ext_err_t AT_CMD_EXT_ERR_SUCCESS if unlocked, AT_CMD_EXT_ERR_UNLOCK_REQUIRED if
 * locked
 */
typedef at_cmd_ext_err_t (*at_cmd_check_unlock_state_cb_t)(void);

/**
 * @brief AT Command extension callbacks structure
 *
 * This structure contains function pointers for extended AT command handlers
 * that applications need to implement. Applications register these callbacks
 * during library initialization to enable extended AT command functionality.
 */
typedef struct {
	/** Set device name callback (required for SETDEVICENAME command) */
	at_cmd_set_device_name_cb_t set_device_name;

	/** Set advertising interval callback (required for SETADVINTERVAL command) */
	at_cmd_set_adv_interval_cb_t set_adv_interval;

	/** Set advertising data callback (required for SETADVDATA command) */
	at_cmd_set_adv_data_cb_t set_adv_data;

	/** Reset device callback (required for SYSRESET command) */
	at_cmd_reset_device_cb_t reset_device;

	/** Unlock procedure callback (required for UNLOCK command) */
	at_cmd_unlock_update_proc_cb_t unlock_update_proc;

	/** Check unlock state callback (required for security validation) */
	at_cmd_check_unlock_state_cb_t check_unlock_state;
} at_cmd_extension_callbacks_t;

/**
 * @brief Initialize AT command extension library with callbacks
 *
 * This function registers the application-specific callback functions
 * that will be called by the extended AT command handlers.
 *
 * @param callbacks Pointer to callback structure containing application handlers
 * @return 0 on success, negative error code on failure
 */
int at_cmd_extension_init(const at_cmd_extension_callbacks_t *callbacks);

#ifdef __cplusplus
}
#endif

#endif /* AT_CMD_CALLBACKS_H */
