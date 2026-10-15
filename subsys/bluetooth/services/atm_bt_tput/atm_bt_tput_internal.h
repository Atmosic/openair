/*
 * Copyright (c) 2025-2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#pragma once

#include <zephyr/bluetooth/uuid.h>

#ifdef __cplusplus
extern "C" {
#endif

#define THROUGHPUT_SERVICE_UUID_VAL                                                                \
	BT_UUID_128_ENCODE(0x991ad067, 0xe278, 0x40ff, 0x86c0, 0xb624eae2360a)
#define THROUGHPUT_WRITE_CHARACTERISTIC_UUID_VAL                                                   \
	BT_UUID_128_ENCODE(0x12f2a2e8, 0xf0e4, 0x449c, 0xb4c2, 0x4ec9eaa33f6e)
#define THROUGHPUT_READ_CHARACTERISTIC_UUID_VAL                                                    \
	BT_UUID_128_ENCODE(0x6c0e7f3b, 0xaae0, 0x4a12, 0x91ad, 0xc3d16afc92a3)
#define THROUGHPUT_NOTIFY_CHARACTERISTIC_UUID_VAL                                                  \
	BT_UUID_128_ENCODE(0xb359d6fc, 0xaf9a, 0x4341, 0x84e7, 0x464cffcf86fd)
#define THROUGHPUT_SERVICE_UUID BT_UUID_DECLARE_128(THROUGHPUT_SERVICE_UUID_VAL)
#define THROUGHPUT_WRITE_CHARACTERISTIC_UUID                                                       \
	BT_UUID_DECLARE_128(THROUGHPUT_WRITE_CHARACTERISTIC_UUID_VAL)
#define THROUGHPUT_READ_CHARACTERISTIC_UUID                                                        \
	BT_UUID_DECLARE_128(THROUGHPUT_READ_CHARACTERISTIC_UUID_VAL)
#define THROUGHPUT_NOTIFY_CHARACTERISTIC_UUID                                                      \
	BT_UUID_DECLARE_128(THROUGHPUT_NOTIFY_CHARACTERISTIC_UUID_VAL)

/**
 * @brief TLV type field values for throughput service protocol
 *
 * These values are used in the type field of TLV-formatted messages
 * to identify different commands and data types.
 */
enum atm_tput_tlv_type {
	/** @brief Trigger Server-to-Client throughput test */
	TAG_TRIGGER_S2C_TEST = 0xFA,
	/** @brief Notify count data */
	TAG_NOTIFY_COUNT = 0xFB,
	/** @brief Set TX power configuration */
	TAG_SET_TX_POWER = 0xFC,
#ifdef CONFIG_ATM_TPUT_AUTO_TEST
	/** @brief C2S test data indicator */
	ATM_C2S_DATA = 0xFE,
	/** @brief Command to signal end of automated testing */
	ATM_TPUT_END_TEST_CMD = 0xFF,
#endif
};

/**
 * @brief S2C test parameters structure
 */
struct s2c_test_params {
	uint16_t packet_count;
	uint8_t payload_size;
	uint8_t use_ack_mode;
} __packed;

/**
 * @brief TX power configuration structure
 */
struct tx_power_config {
	int8_t tx_power;
} __packed;

/**
 * @brief Notify count payload structure
 */
struct notify_count_payload {
	uint32_t count;
	uint8_t reserved[4];
} __packed;

/**
 * @brief TLV (Type-Length-Value) data structure
 *
 * This structure represents TLV-formatted messages used for control messages
 * and data transmission in the throughput service. The value data follows
 * immediately after the type and data_len fields in memory.
 */
struct atm_tput_data {
	/** @brief Type field identifying the data/command type */
	uint8_t type;
	/** @brief Length of the data value in bytes */
	uint8_t data_len;
	/** @brief Value data - can be interpreted as different types based on 'type' field */
	union {
		/** @brief Single byte value for commands or mode flags */
		uint8_t cmd_or_mode;
		/** @brief S2C test parameters */
		struct s2c_test_params s2c_params;
		/** @brief TX power configuration */
		struct tx_power_config tx_power;
		/** @brief Notify count payload */
		struct notify_count_payload notify_count;
		/** @brief Raw byte array for generic data (must be last for flexible array) */
		uint8_t raw_bytes[0];
	} data_value;
} __packed;

/**
 * @brief Size of TLV header (type + data_len fields)
 */
#define ATM_TPUT_TLV_HEADER_SIZE offsetof(struct atm_tput_data, data_value)

/**
 * @brief Get pointer to TLV value data from a buffer
 *
 * @param buf Pointer to buffer containing TLV data
 * @return Pointer to the value portion (skips type and length bytes)
 */
#define ATM_TPUT_TLV_VALUE(buf) ((uint8_t *)(buf) + ATM_TPUT_TLV_HEADER_SIZE)

/**
 * @brief Get total size of a TLV message
 *
 * @param value_len Length of the value portion
 * @return Total size including type, length, and value
 */
#define ATM_TPUT_TLV_SIZE(value_len) (ATM_TPUT_TLV_HEADER_SIZE + (value_len))

#ifdef CONFIG_ZTEST
#include <zephyr/bluetooth/gatt.h>

void reset_test_params(void);
ssize_t atm_tput_test_write_cb(struct bt_conn *conn, const struct bt_gatt_attr *attr,
			       const void *buf, uint16_t len, uint16_t offset, uint8_t flags);
void atm_tput_test_ccc_cfg_changed(const struct bt_gatt_attr *attr, uint16_t value);
void atm_tput_test_indicate_cb(struct bt_conn *conn, struct bt_gatt_indicate_params *params,
			       uint8_t err);
uint8_t atm_tput_test_notify_func(struct bt_conn *conn, struct bt_gatt_subscribe_params *params,
				  const void *data, uint16_t length);

/* Pre-set notify_crch, notify_params.attr and ind_params.attr with a non-NULL
 * fake attr so bt_gatt_notify_cb / bt_gatt_indicate pass their assertion
 * "params->attr || params->uuid" in tests without bt_enable(). */
void atm_tput_test_set_notify_crch(struct bt_gatt_attr *attr);

void atm_tput_test_notify_cb(struct bt_conn *conn);
ssize_t atm_tput_test_read_throughput_cb(struct bt_conn *conn, const struct bt_gatt_attr *attr,
					 void *buf, uint16_t len, uint16_t offset);
void atm_tput_test_c2s_write_cb(struct bt_conn *conn, uint8_t err,
				struct bt_gatt_write_params *params);
uint8_t atm_tput_test_read_func(struct bt_conn *conn, uint8_t err,
				struct bt_gatt_read_params *params, const void *data,
				uint16_t length);
/* Call atm_tput_service_connect() first to initialise discover_params. */
uint8_t atm_tput_test_discover_func(struct bt_conn *conn, const struct bt_gatt_attr *attr);
void atm_tput_test_read_throughput_metrics(struct bt_conn *conn, uint16_t handle);
/* Set non-zero handles to prevent __ASSERT inside atm_tput_measure_* / client_done. */
void atm_tput_test_set_gatt_handles(uint16_t write_hdl, uint16_t read_hdl);
/* Set notify and ccc_handle so bt_gatt_subscribe assertions pass. */
void atm_tput_test_set_subscribe_params(uint16_t ccc_hdl);
void atm_tput_test_set_callback_measure(atm_tput_measurement_cb cb);

#endif /* CONFIG_ZTEST */

#ifdef __cplusplus
}
#endif
