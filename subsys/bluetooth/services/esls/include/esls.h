/**
 *******************************************************************************
 *
 * @file esls.h
 *
 * @brief Electronic Shelf Label Service Header File
 *
 * Copyright (c) 2024-2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 *
 *******************************************************************************
 */

#pragma once

#include "compiler.h"

#ifdef __cplusplus
extern "C" {
#endif

enum bt_esls_display_type {
	BT_ESLS_DISPLAY_TYPE_BLACK_WHITE = 0x01,
	BT_ESLS_DISPLAY_TYPE_THREE_GRAY_SCALE,
	BT_ESLS_DISPLAY_TYPE_FOUR_GRAY_SCALE,
	BT_ESLS_DISPLAY_TYPE_EIGHT_GRAY_SCALE,
	BT_ESLS_DISPLAY_TYPE_SIXTEEN_SCALE,
	BT_ESLS_DISPLAY_TYPE_RED_BLACK_WHITE,
	BT_ESLS_DISPLAY_TYPE_YELLOW_BLACK_WHITE,
	BT_ESLS_DISPLAY_TYPE_RED_YELLOW_BLACK_WHITE,
	BT_ESLS_DISPLAY_TYPE_SEVEN_COLOR,
	BT_ESLS_DISPLAY_TYPE_SIXTEEN_COLOR,
	BT_ESLS_DISPLAY_TYPE_FULL_RGB,
};

struct bt_esls_display_info {
	/// the width of the display in pixels
	uint16_t width;
	/// the height of the display in pixels
	uint16_t height;
	/// display type
	enum bt_esls_display_type type;
} __packed;

struct sensor_type_vendor_specific {
	/// a unique 16-bit number assigned by the Bluetooth SIG to a member company
	uint16_t company_id;
	/// a number assigned to a vendor-specific sensor type
	uint16_t sensor_code;
};

enum bt_esls_size_type {
	/// size type for 16-bit value
	BT_ESLS_SIZE_TYPE_16_BITS,
	/// size type for 32-bit value
	BT_ESLS_SIZE_TYPE_32_BITS,
};

enum bt_esls_led_type {
	/// led type for the sRGB LED
	BT_ESLS_LED_TYPE_SRGB,
	/// led type for the monochrome LED
	BT_ESLS_LED_TYPE_MONOCHROME,
};

struct bt_esls_sensor_info {
	/// size type
	enum bt_esls_size_type type;
	union {
		/// a Property ID from the Mesh Device Properties for
		/// BT_ESLS_SIZE_TYPE_16_BITS type
		uint16_t property_id;
		/// a 32-bit vendor-specific value for BT_ESLS_SIZE_TYPE_32_BITS type
		struct sensor_type_vendor_specific vendor_specific;
	};
} __packed;

struct bt_esls_init_param {
#if CONFIG_BT_ESLS_SENSOR_NUM > 0
	/// sensor information
	struct bt_esls_sensor_info sensors_info[CONFIG_BT_ESLS_SENSOR_NUM];
	/// callback for reading sensor data
	int (*sensor_read_data)(uint8_t sensor_idx, uint8_t *sensor_data, uint8_t *sensor_data_len);
#endif
#if CONFIG_BT_ESLS_ADV_MANU_DATA_MAX
	/// manufacturer data in the advertising
	uint8_t *app_adv_data;
	/// manufacturer data length
	uint8_t app_adv_len;
#endif
#if CONFIG_BT_ESLS_DISPLAY_NUM > 0
	/// display information
	struct bt_esls_display_info display_info[CONFIG_BT_ESLS_DISPLAY_NUM];
	/// callback to display image
	int (*display_image)(uint8_t display_idx, uint8_t img_idx);
#endif
#if CONFIG_BT_ESLS_IMAGE_NUM > 0
	/// callbck for writing image data to storage
	int (*write_image_data)(uint8_t image_idx, uint8_t *buf, uint16_t len);
	/// callbeack for reading image data from storage
	int (*read_image_data)(uint8_t image_idx, uint8_t *buf, uint16_t offset, uint16_t len);
	/// callback for reading image size
	int (*read_image_size)(uint8_t img_idx, uint16_t *size);
	/// callback for reading image name
	int (*get_image_name)(uint8_t image_idx, char **name);
	/// callback to delete image
	int (*delete_image_data)(void);
#endif
#if CONFIG_BT_ESLS_LED_NUM > 0
	/// LED information
	uint8_t led[CONFIG_BT_ESLS_LED_NUM];
	/// callback of LED control
	int (*led_control)(uint8_t led_idx, bool on_off, uint8_t color_brightness_info);
#endif
};

#if CONFIG_BT_ESLS_LED_NUM > 0
#define ESLS_LED_INFO_RED_SET(led_info, value)      (led_info |= (value & 0x03))
#define ESLS_LED_INFO_GREEN_SET(led_info, value)    (led_info |= ((value & 0x03) << 2))
#define ESLS_LED_INFO_BLUE_SET(led_info, value)     (led_info |= ((value & 0x03) << 4))
#define ESLS_LED_INFO_LED_TYPE_SET(led_info, value) (led_info |= ((value & 0x03) << 6))

#define ESLS_LED_CTRL_RED(led_info)        (led_info & 0x03)
#define ESLS_LED_CTRL_GREEN(led_info)      ((led_info >> 2) & 0x03)
#define ESLS_LED_CTRL_BLUE(led_info)       ((led_info >> 4) & 0x03)
#define ESLS_LED_CTRL_BRIGHTNESS(led_info) ((led_info >> 6) & 0x03)
#endif

/**
 * @brief Initialize a electronic shelf label service
 *
 * Provide information or callbacks of the electronic shelf label service.
 *
 * @param[in] init_param Pointer to the parameters.
 * @return Zero in case of success and error code in case of error.
 */
__NONNULL_ALL
int bt_esls_init(struct bt_esls_init_param const *init_param);

/**
 * @brief Unassociate with access point
 *
 * Remove all bonding information with the AP, delete the value of the AP Sync
 * Key Material in internal storage, the ESL ID, and delete all stored commands.
 *
 * @return Zero in case of success and error code in case of error.
 */
int bt_esls_unassociate(void);

/**
 * @brief Set Service Needed value
 *
 * The Service Needed state may be True or False.
 *
 * If a condition occurs that causes the ESL to set the Service Needed state to
 * True, then the ESL shall set the value of the Service Needed bit to True.
 * Once set to True, the value of the Service Needed bit shall remain True until
 * it is successfully reset by the Client
 *
 * @param[in] set Pointer to the Service Needed state.
 */
void bt_esls_service_needed_bit_set(bool set);

#if CONFIG_AUTO_TEST
/**
 * @brief Check the test is ended or not
 *
 * @return true if the test is ended, false otherwise.
 */
bool test_end_check(void);

#endif

#ifdef __cplusplus
}
#endif
