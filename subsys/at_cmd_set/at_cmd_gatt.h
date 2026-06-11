/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#pragma once

#include <zephyr/bluetooth/uuid.h>
#include <string.h>
#include "at_cmd_gatt_utils.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Enable or disable the default GATT server
 *
 * Registers or unregisters the GATT service with the Bluetooth stack.
 * The service remains in the same configuration; only its registration state changes.
 *
 * @param state true to enable (register), false to disable (unregister)
 * @return at_cmd_result_t with error code if registration/unregistration fails
 */
at_cmd_result_t at_cmd_gatt_dft_server_set(bool state);

/**
 * @brief Get the current enable/disable state of default GATT server
 *
 * @return true if server is registered (enabled), false if unregistered (disabled)
 */
bool at_cmd_gatt_dft_server_get(void);

/**
 * @brief Set and persist default service UUID and properties
 *
 * @param sec_prop BT_GATT_PERM_* bitmask for service read permission
 * @param uuid 16-byte service UUID
 * @return at_cmd_result_t with error code if validation or storage fails
 */
at_cmd_result_t at_cmd_gatt_dft_service_set(uint16_t sec_prop, const uint8_t *uuid);

/**
 * @brief Get default service UUID and properties
 *
 * @param sec_prop [out] BT_GATT_PERM_* bitmask (read permission)
 * @param uuid [out] 16-byte service UUID buffer
 * @return at_cmd_result_t success or error code
 */
at_cmd_result_t at_cmd_gatt_dft_service_get(uint16_t *sec_prop, uint8_t *uuid);

/**
 * @brief Set and persist default characteristic 1 configuration
 *
 * @param sec_prop BT_GATT_PERM_* bitmask for characteristic value read/write permission
 * @param uuid 16-byte characteristic UUID
 * @return at_cmd_result_t with error code if validation or storage fails
 */
at_cmd_result_t at_cmd_gatt_dft_char1_set(uint16_t sec_prop, const uint8_t *uuid);

/**
 * @brief Get default characteristic 1 configuration
 *
 * @param sec_prop [out] BT_GATT_PERM_* bitmask
 * @param uuid [out] 16-byte characteristic UUID buffer
 * @return at_cmd_result_t success or error code
 */
at_cmd_result_t at_cmd_gatt_dft_char1_get(uint16_t *sec_prop, uint8_t *uuid);

/**
 * @brief Set and persist default characteristic 2 configuration
 *
 * @param sec_prop BT_GATT_PERM_* bitmask for characteristic value read/write permission
 * @param uuid 16-byte characteristic UUID
 * @return at_cmd_result_t with error code if validation or storage fails
 */
at_cmd_result_t at_cmd_gatt_dft_char2_set(uint16_t sec_prop, const uint8_t *uuid);

/**
 * @brief Get default characteristic 2 configuration
 *
 * @param sec_prop [out] BT_GATT_PERM_* bitmask
 * @param uuid [out] 16-byte characteristic UUID buffer
 * @return at_cmd_result_t success or error code
 */
at_cmd_result_t at_cmd_gatt_dft_char2_get(uint16_t *sec_prop, uint8_t *uuid);

/**
 * @brief Set pre-defined read value for characteristic 1
 *
 * The value is returned to the client on ATT_READ_REQ.
 * Not persisted; cleared on reboot.
 *
 * @param data Payload buffer (may be NULL when len is 0)
 * @param len  Payload length in bytes (0–BT_ATT_MAX_ATTRIBUTE_LEN)
 * @return at_cmd_result_t with err=0 on success, -EINVAL if len exceeds the limit
 */
at_cmd_result_t at_cmd_gatt_dft_char1_val_set(const uint8_t *data, uint16_t len);

/**
 * @brief Get pre-defined read value for characteristic 1
 *
 * @param[out] data Buffer to copy the stored value into (must be at least BT_ATT_MAX_ATTRIBUTE_LEN)
 * @param[out] len  Number of bytes written to @p data
 * @return at_cmd_result_t with err=0 on success
 */
at_cmd_result_t at_cmd_gatt_dft_char1_val_get(uint8_t *data, uint16_t *len);

/**
 * @brief Set pre-defined read value for characteristic 2
 *
 * The value is returned to the client on ATT_READ_REQ.
 * Not persisted; cleared on reboot.
 *
 * @param data Payload buffer (may be NULL when len is 0)
 * @param len  Payload length in bytes (0–BT_ATT_MAX_ATTRIBUTE_LEN)
 * @return at_cmd_result_t with err=0 on success, -EINVAL if len exceeds the limit
 */
at_cmd_result_t at_cmd_gatt_dft_char2_val_set(const uint8_t *data, uint16_t len);

/**
 * @brief Get pre-defined read value for characteristic 2
 *
 * @param[out] data Buffer to copy the stored value into (must be at least BT_ATT_MAX_ATTRIBUTE_LEN)
 * @param[out] len  Number of bytes written to @p data
 * @return at_cmd_result_t with err=0 on success
 */
at_cmd_result_t at_cmd_gatt_dft_char2_val_get(uint8_t *data, uint16_t *len);

/**
 * @brief Called when all BLE connections have been dropped
 *
 * If a UUID or permission change was made while a connection was active,
 * this function applies the deferred re-registration so the next
 * incoming connection will discover the updated GATT attributes.
 *
 * Must be called from the disconnected callback when conn_count reaches 0.
 */
void at_cmd_gatt_dft_on_all_disconnected(void);

/**
 * @brief Initialize GATT default server configuration from Settings
 *
 * Loads persisted UUIDs from non-volatile Settings storage into module-level
 * static variables. Should be called once during system startup.
 *
 * @note Called automatically from at_cmd_set initialization.
 */
void at_cmd_gatt_dft_config_init(void);

/**
 * @brief Find a DFT service attribute by its BT GATT handle
 *
 * @param handle BT GATT attribute handle (attr->handle)
 * @return Pointer to the matching bt_gatt_attr, or NULL if not found or
 *         service not registered
 */
struct bt_gatt_attr *at_cmd_gatt_dft_find_attr_by_handle(uint16_t handle);

#ifdef CONFIG_ZTEST
/**
 * @brief Test hook: simulate gatt_read_cb without a real BT connection.
 *
 * @p attidx is a 0-based array index into s_gatt_attrs[] (NOT a BT handle).
 * Use at_cmd_gatt_test_get_char_attidx() to obtain the correct index.
 * The BT stack is not running in unit tests so attr->handle is always 0;
 * this hook keeps the array-index convention internally to select the right
 * value buffer.
 * Returns -ENOENT when the service is not registered or attidx is out of range.
 */
ssize_t at_cmd_gatt_test_gatt_read(uint8_t conidx, uint16_t attidx, void *buf, uint16_t buf_len,
				   uint16_t offset);

/**
 * @brief Test hook: simulate gatt_write_cb without a real BT connection.
 *
 * See at_cmd_gatt_test_gatt_read() for the attidx convention.
 * Returns -ENOENT when the service is not registered or attidx is out of range.
 */
ssize_t at_cmd_gatt_test_gatt_write(uint8_t conidx, uint16_t attidx, const void *buf, uint16_t len,
				    uint8_t flags);

/** Symbolic char_num values for at_cmd_gatt_test_get_char_attidx() */
#define AT_GATT_CHAR_NUM_1 1U
#define AT_GATT_CHAR_NUM_2 2U

/**
 * @brief Test hook: return the s_gatt_attrs[] array index of a characteristic value attr.
 *
 * Returns the array index (not the BT handle) so that test hooks can select
 * the correct value buffer without a running BT stack.
 *
 * @param char_num AT_GATT_CHAR_NUM_1 or AT_GATT_CHAR_NUM_2
 * @return array index, or UINT16_MAX if char_num is invalid
 */
uint16_t at_cmd_gatt_test_get_char_attidx(uint8_t char_num);
#endif /* CONFIG_ZTEST */

#ifdef __cplusplus
}
#endif
