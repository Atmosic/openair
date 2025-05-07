/**
 *******************************************************************************
 *
 * @file dult.h
 *
 * @brief Detecting Unwanted Location Trackers Service
 *
 * Copyright (C) Atmosic 2025
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
/// DULT play sound interval in seconds
#define DULT_PLAY_SOUND_INT_SEC 12
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
