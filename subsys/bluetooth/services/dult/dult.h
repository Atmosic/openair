/**
 *******************************************************************************
 *
 * @file dult.h
 *
 * @brief Detecting Unwanted Location Trackers Service
 *
 * Copyright (C) Atmosic 2025-2026
 *
 *******************************************************************************
 */

#pragma once

/**
 * @defgroup ATM_BTDULTS Detecting Unwanted Location Trackers Service
 * @brief Detecting Unwanted Location Trackers Service
 *
 * @{
 */

#include "compiler.h" // __NONNULL_ALL inline functions
#include <zephyr/bluetooth/uuid.h>
#include <zephyr/bluetooth/gatt.h>
#include "dult_common.h"

#ifdef __cplusplus
extern "C" {
#endif

/// DULT accessory info data length
#define DULT_DATA_LEN           64
/// DULT accessory info product data length
#define DULT_PRODUCT_DATA_LEN   8
/// DULT accessory info category length
#define DULT_CATEGORY_LEN       8
/// DULT accessory info version length
#define DULT_VER_LEN            4
/// DULT play sound total duration in seconds
#define DULT_PLAY_SOUND_DUR_SEC 12
/// DULT read id interval in minutes
#define DULT_READ_ID_INT_MIN    5

/// DULT Battery Level
typedef enum {
	/// Index of battery level full
	DULT_BATTERY_LEVEL_FULL = 0x0,
	/// Index of battery level normal
	DULT_BATTERY_LEVEL_NORMAL = 0x1,
	/// Index of battery level low
	DULT_BATTERY_LEVEL_LOW = 0x2,
	/// Index of battery level critical
	DULT_BATTERY_LEVEL_CRITICAL = 0x3,
	/// Index of battery level not support
	DULT_BATTERY_LEVEL_NOT_SUPPORT = 0x4,
	/// Index of battery level none
	DULT_BATTERY_LEVEL_NONE = 0xFF,
} dult_battery_level_t;

/**
 * @brief DULT init
 *
 * @return 0 if successful. Otherwise, a (negative) error code is returned.
 */
int dult_init(void);

/**
 * @brief DULT deinit
 */
void dult_deinit(void);

/**
 * @brief Reset DULT service
 */
void dult_reset(void);

/**
 * @brief DULT enable
 * @param[in] en enable or disable dult
 */
void dult_enable(bool en);

/**
 * @brief Get the DULT Accessory Non-Owner GATT service.
 *
 * Lets another module reuse this single service instance instead of defining a
 * second service with the same standard UUID (which would collide in the GATT DB).
 *
 * @return Pointer to the DULT non-owner GATT service.
 */
struct bt_gatt_service_static const *dult_svc_get(void);

/**
 * @brief Redirect writes to the DULT non-owner characteristic to a custom handler.
 *
 * While set, the DULT write handler forwards every write to @p write_handler
 * instead of the default DULT handling, so another user of the shared service can
 * process writes while its connection is active. Assumes only one user is active
 * at a time. Call dult_restore_write_handler() to revert.
 *
 * @param[in] write_handler GATT write callback to route writes to.
 */
void dult_overwrite_write_handler(ssize_t (*write_handler)(struct bt_conn *conn,
							   const struct bt_gatt_attr *attr,
							   const void *buf, uint16_t len,
							   uint16_t offset, uint8_t flags));

/**
 * @brief Restore the default DULT non-owner write handler.
 */
void dult_restore_write_handler(void);

/**
 * @brief DULT node update
 * @param[in] mode dult mode type
 */
void dult_mode_update(dult_mode_t mode);

/**
 * @brief DULT read id enable
 */
void dult_read_id_enable(void);

/// DULT Handlers
typedef struct dult_hdlrs_s {
	/// get id callback function
	uint8_t (*dult_get_id_cb)(uint8_t *id);
	/// get battery status callback function
	uint8_t (*battery_status_cb)(void);
	/// play sound callback function
	void (*sound_action_cb)(bool action);
#ifdef CONFIG_DULT_MOTION_DETECT
	/// Enable or disable motion sensor hardware; called by the DULT UT state machine
	void (*motion_hw_enable_cb)(bool enable);
#ifndef CONFIG_DULT_MOTION_DETECT_TRIGGER
	/// Raw motion snapshot getter (degrees 0–90); polled by the DULT UT state machine
	uint8_t (*motion_raw_get_cb)(void);
#endif
#endif
} dult_hdlrs_t;

/// DULT Service User Information
typedef struct dult_user_info_s {
	/// Model ID
	uint8_t model_id[DULT_PRODUCT_DATA_LEN];
	/// Length of Model ID
	uint8_t model_id_len;
} dult_user_info_t;

/**
 * @brief dult handlers register
 * @param[in] hdlr dult handlers structure
 * @param[in] hdlr dult user info structure
 * @param[in] bt_id dult adv bt id
 */
__NONNULL_ALL
void dult_handlers_register(dult_hdlrs_t const *hdlrs, dult_user_info_t const *user_info,
			    uint8_t bt_id);

#ifdef __cplusplus
}
#endif

///@}
