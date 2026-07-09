/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#pragma once

#include "arch.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <zephyr/bluetooth/addr.h>
#include <zephyr/bluetooth/conn.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Application-specific error codes for AT command operations.
 * These provide explicit, domain-specific error information for better
 * debugging and error handling compared to generic Zephyr errno values.
 *
 * Naming convention: AT_ERR_<DOMAIN>_<DESCRIPTION>
 *
 * Value ranges:
 *   0x00        — No error
 *   0x01-0x05   — GAP errors (legacy range, preserved for wire compatibility)
 *   0x06        — System reboot required (legacy, preserved for wire compat)
 *   0x10-0x1F   — Advertising errors
 *   0x20-0x2F   — Context errors
 *   0x30-0x3F   — Parameter validation errors
 *   0x40-0x4F   — BLE/Zephyr errno mapping
 *   0x50-0x5F   — GPIO/FIO errors
 *   0x60-0x6F   — System errors
 *   0x70-0x7F   — GATT/ATT errors
 */
typedef enum {
	/* No error */
	AT_ERR_NONE = 0x00,

	/* GAP errors (0x01-0x05) */
	AT_ERR_GAP_ROLE_INITIALIZED = 0x01,     /* GAP role already initialized */
	AT_ERR_GAP_ROLE_NOT_SUPPORTED = 0x02,   /* Requested GAP role not supported */
	AT_ERR_GAP_SET_BEFORE_INIT = 0x03,      /* Must be set before bt_enable() */
	AT_ERR_GAP_SET_AFTER_INIT = 0x04,       /* Must be set after bt_enable() */
	AT_ERR_GAP_ONLY_STATIC_RND_ADDR = 0x05, /* Only static random addr supported */

	/* Advertising errors (0x10-0x1F) */
	AT_ERR_ADV_INVALID_INDEX = 0x10,
	AT_ERR_ADV_ALREADY_ENABLED = 0x11,
	AT_ERR_ADV_NOT_ENABLED = 0x12,
	AT_ERR_ADV_SET_NOT_CREATED = 0x13,
	AT_ERR_ADV_INVALID_PARAM = 0x14,
	AT_ERR_ADV_DATA_TOO_LONG = 0x15,
	AT_ERR_ADV_SCAN_DATA_TOO_LONG = 0x16,

	/* Context errors (0x20-0x2F) */
	AT_ERR_CTX_NULL = 0x20,
	AT_ERR_CTX_NOT_INITIALIZED = 0x21,

	/* Parameter validation errors (0x30-0x3F) */
	AT_ERR_PARAM_INVALID = 0x30,
	AT_ERR_PARAM_OUT_OF_RANGE = 0x31,
	AT_ERR_PARAM_INVALID_LENGTH = 0x32,

	/* BLE/Zephyr errno mapping (0x40-0x4F) */
	AT_ERR_BLE_EINVAL = 0x40,       /* Invalid argument */
	AT_ERR_BLE_EBUSY = 0x41,        /* Device or resource busy */
	AT_ERR_BLE_ENOMEM = 0x42,       /* Out of memory */
	AT_ERR_BLE_ENOTSUP = 0x43,      /* Operation not supported */
	AT_ERR_BLE_EACCES = 0x44,       /* Permission denied */
	AT_ERR_BLE_ENODEV = 0x45,       /* No such device */
	AT_ERR_BLE_ETIMEDOUT = 0x46,    /* Operation timed out */
	AT_ERR_BLE_ECONNREFUSED = 0x47, /* Connection refused */
	AT_ERR_BLE_ECONNRESET = 0x48,   /* Connection reset */
	AT_ERR_BLE_EPIPE = 0x49,        /* Broken pipe */
	AT_ERR_BLE_EALREADY = 0x4A,     /* Operation already in progress / address already set */
	AT_ERR_BLE_UNKNOWN = 0x4F,      /* Unknown BLE error */

	/* GPIO/FIO errors (0x50-0x5F) */
	AT_ERR_GPIO_NOT_READY = 0x50, /* GPIO device not ready */
	AT_ERR_GPIO_CONFIG = 0x51,    /* GPIO pin configuration failed */

	/* System errors (0x60-0x6F) */
	AT_ERR_SYS_NEED_REBOOT = 0x60, /* Reboot required to apply setting */
	AT_ERR_SYS_NOT_READY = 0x61,
	AT_ERR_SYS_UART_NOT_READY = 0x62, /* UART device not ready */
	AT_ERR_SYS_UART_CONFIG = 0x63,    /* uart_configure() failed */

	/* GATT/ATT errors (0x70-0x7F) */
	AT_ERR_GATT_INVALID_HANDLE = 0x70,
	AT_ERR_GATT_READ_NOT_PERMITTED = 0x71,
	AT_ERR_GATT_WRITE_NOT_PERMITTED = 0x72,
	AT_ERR_GATT_INVALID_PDU = 0x73,
	AT_ERR_GATT_INSUFF_AUTHEN = 0x74,
	AT_ERR_GATT_REQUEST_NOT_SUPPORTED = 0x75,
	AT_ERR_GATT_INVALID_OFFSET = 0x76,
	AT_ERR_GATT_INSUFF_AUTHOR = 0x77,
	AT_ERR_GATT_PREPARE_QUEUE_FULL = 0x78,
	AT_ERR_GATT_ATTRIBUTE_NOT_FOUND = 0x79,
	AT_ERR_GATT_ATTRIBUTE_NOT_LONG = 0x7A,
	AT_ERR_GATT_INSUFF_ENC_KEY_SIZE = 0x7B,
	AT_ERR_GATT_INVALID_ATTR_VAL_LEN = 0x7C,
	AT_ERR_GATT_UNLIKELY = 0x7D,
	AT_ERR_GATT_INSUFF_ENC = 0x7E,
	AT_ERR_GATT_UNSUPPORTED_GRP_TYPE = 0x7F,

	/* Dynamic GATT staging errors (0x80-0x8F) */
	AT_ERR_GATT_DYN_SVC_ACTIVE = 0x80, /* service already active; cannot add char/desc */
	/* 0x81 reserved */
	/* 0x82 reserved */
	AT_ERR_GATT_DYN_NO_SVC = 0x83,  /* no ADDSERVICE issued, or all svcs already active */
	AT_ERR_GATT_DYN_NO_CHAR = 0x84, /* no ADDCHAR issued before ADDDESC */
} at_cmd_app_err_t;

/**
 * Reason codes carried in the +EVTSYSFUNCPIN event payload.
 * These are not AT command errors; they are event notification codes
 * that indicate why the GPIO function-pin event was triggered.
 */
typedef enum {
	AT_SYSFUNCPIN_REASON_INTR = 4, /* GPIO interrupt fired */
} at_cmd_sysfuncpin_reason_t;

/**
 * Maximum advertising data length
 * For Atmosic platforms (ATLC-based), use CONFIG_ATM_MAX_ADV_DATA_LEN
 * Extended advertising supports up to 1650 bytes, legacy is limited to 31
 */
#ifdef CONFIG_ATM_MAX_ADV_DATA_LEN
#if CONFIG_ATM_MAX_ADV_DATA_LEN > 0
#define AT_CMD_MAX_ADV_DATA_LEN CONFIG_ATM_MAX_ADV_DATA_LEN
#else
#define AT_CMD_MAX_ADV_DATA_LEN 31
#endif
#else // CONFIG_ATM_MAX_ADV_DATA_LEN
#define AT_CMD_MAX_ADV_DATA_LEN 31
#endif // CONFIG_ATM_MAX_ADV_DATA_LEN

/** @cond INTERNAL_HIDDEN */
#define AT_CMD_XSTR(x) AT_CMD_STR(x)
#define AT_CMD_STR(x)  #x
/** @endcond */

/** Stringified AT_CMD_MAX_ADV_DATA_LEN for use in format strings */
#define AT_CMD_MAX_ADV_DATA_LEN_STR AT_CMD_XSTR(AT_CMD_MAX_ADV_DATA_LEN)

/**
 * Maximum number of advertising instances
 * Uses Kconfig option AT_CMD_ADV_MAX_INST if available, otherwise 1
 */
#ifdef CONFIG_AT_CMD_ADV_MAX_INST
#ifdef CONFIG_BT_EXT_ADV_MAX_ADV_SET
BUILD_ASSERT(CONFIG_AT_CMD_ADV_MAX_INST <= CONFIG_BT_EXT_ADV_MAX_ADV_SET,
	     "AT_CMD_ADV_MAX_INST exceeds BT_EXT_ADV_MAX_ADV_SET");
#endif
#define AT_CMD_ADV_MAX_INST CONFIG_AT_CMD_ADV_MAX_INST
#else
#define AT_CMD_ADV_MAX_INST 1
#endif

/**
 * Invalid advertising index (no advertising set associated)
 */
#define AT_CMD_ADV_IDX_NONE 0xFF

#ifdef CONFIG_AT_CMD_SET_CALLBACKS

#ifdef CONFIG_AT_CMD_TAG_SET
#include "at_cmd_tag.h"
#endif

/**
 * Callback registration structure for AT command set features
 */
typedef struct {
#ifdef CONFIG_AT_CMD_TAG_SET
	at_cmd_set_tag_callbacks_t tag_cb;
#endif
#ifdef CONFIG_AT_EVT_CB_TEST
	void (*test_cb)(uint8_t ch);
#endif
} at_cmd_set_callbacks_t;

#endif /* CONFIG_AT_CMD_SET_CALLBACKS */

#ifdef CONFIG_AT_CMD_BLESCANFILRSSI
/** Boot-default RSSI threshold for AT+BLESCANFILRSSI (dBm) — most permissive */
#define AT_CMD_SCAN_RSSI_MIN -90
/** Strictest RSSI threshold accepted by AT+BLESCANFILRSSI (dBm) */
#define AT_CMD_SCAN_RSSI_MAX -40
#endif // CONFIG_AT_CMD_BLESCANFILRSSI

/**
 * AT Command context structure
 */
typedef struct {
	/* AT command channel */
	uint8_t ch;
#ifdef CONFIG_AT_CMD_BLEADVENABLE
	/* Advertising BT ID per instance */
	uint8_t adv_bt_id[AT_CMD_ADV_MAX_INST];
	/* Advertising enabled flag */
	bool adv_enabled[AT_CMD_ADV_MAX_INST];
#ifdef CONFIG_BT_EXT_ADV
	struct bt_le_ext_adv *adv_set[AT_CMD_ADV_MAX_INST];
#endif

	/* Advertising parameters per instance */
	uint16_t adv_intv_min[AT_CMD_ADV_MAX_INST];
	uint16_t adv_intv_max[AT_CMD_ADV_MAX_INST];
	uint16_t adv_duration[AT_CMD_ADV_MAX_INST];
#ifdef CONFIG_BT_EXT_ADV
	uint8_t adv_primary_phy[AT_CMD_ADV_MAX_INST];
#endif

	/* Advertising data per instance */
	uint8_t adv_data[AT_CMD_ADV_MAX_INST][AT_CMD_MAX_ADV_DATA_LEN];
	uint16_t adv_data_len[AT_CMD_ADV_MAX_INST];

	/* Scan response data per instance */
	uint8_t scan_data[AT_CMD_ADV_MAX_INST][AT_CMD_MAX_ADV_DATA_LEN];
	uint16_t scan_data_len[AT_CMD_ADV_MAX_INST];
#endif // CONFIG_AT_CMD_BLEADVENABLE

#ifdef CONFIG_AT_CMD_SET_CALLBACKS
	/* AT command set callbacks */
	at_cmd_set_callbacks_t callbacks;
#endif

#ifdef CONFIG_AT_CMD_BLESCANENABLE
	/* Current scan state */
	bool scan_enabled;
#ifdef CONFIG_AT_CMD_BLESCANFILMAC
	/* Address-based scan filter state (controller Filter Accept List) */
	bool scan_mac_filter_enabled;
	bt_addr_le_t scan_filter_addr;
#endif // CONFIG_AT_CMD_BLESCANFILMAC
#ifdef CONFIG_AT_CMD_BLESCANFILRSSI
	/* RSSI threshold (always active; bypassed when MAC filter is on) */
	int8_t scan_rssi_threshold;
#endif // CONFIG_AT_CMD_BLESCANFILRSSI
#endif // CONFIG_AT_CMD_BLESCANENABLE
#ifdef CONFIG_AT_CMD_SET_CONN_TRACKING
	/* All tracked connections (central and peripheral) */
	struct bt_conn *conns[CONFIG_BT_MAX_CONN];
	/* Number of currently active connections in conns[] */
	uint8_t conn_count;
#endif
} at_cmd_ctx_t;

/**
 * @brief Initialize AT command context
 * @return Pointer to the AT command context
 */
at_cmd_ctx_t *at_cmd_ctx_init(void);

/**
 * @brief Get AT command context
 * @return Pointer to the AT command context, or NULL if not initialized
 */
at_cmd_ctx_t *at_cmd_ctx_get(void);

/**
 * @brief Set AT command channel
 * @param ch AT command channel
 */
void at_cmd_set_channel(uint8_t ch);

#ifdef CONFIG_AT_CMD_SET_CALLBACKS

/**
 * @brief Register AT command set callbacks
 * @param callbacks Pointer to the AT command set callbacks structure
 */
__NONNULL_ALL
void at_cmd_set_callbacks_register(at_cmd_set_callbacks_t const *callbacks);

#endif /* CONFIG_AT_CMD_SET_CALLBACKS */

#ifdef CONFIG_AT_CMD_SET_EVENTS

/**
 * @brief Event handler function pointer
 * @param ch AT command channel
 * @param evt_data Event data pointer
 * @param evt_data_len Event data length
 */
typedef void (*at_cmd_evt_handler_t)(uint8_t ch, void const *evt_data, uint16_t evt_data_len);

/**
 * @brief Submit event to app work queue for asynchronous processing
 * @param handler Event handler function
 * @param ch AT command channel
 * @param evt_data Event data pointer
 * @param evt_data_len Event data length
 * @return 0 on success, negative on error
 */
int at_cmd_evt_submit(at_cmd_evt_handler_t handler, uint8_t ch, void const *evt_data,
		      uint16_t evt_data_len);

/**
 * @brief Create virtual AT command for event response
 * @param evt_name Event name (e.g., "TESTEVENT", "TAGEVT")
 * @param evt_rsp_fmt Response format (e.g., "B,A(0~32)")
 * @param evt_rsp_num Number of response parameters
 *
 * Usage:
 *   at_cmd_resp(ch, at_all, AT_CMD_EVT_DEF("TESTEVENT", "B,A(0~32)", 2),
 *               0, 2, evt_type, evt_data, evt_len);
 */
#define AT_CMD_EVT_DEF(evt_name, evt_rsp_fmt, evt_rsp_num)                                         \
	(&(at_cmd_t){                                                                              \
		.str = evt_name,                                                                   \
		.rsp_fmt = evt_rsp_fmt,                                                            \
		.rsp_num = evt_rsp_num,                                                            \
	})

#endif /* CONFIG_AT_CMD_SET_EVENTS */

#ifdef CONFIG_AT_CMD_SYSUARTRAW

/**
 * @brief Check if the UART transparent raw bridge is currently active.
 * @return true if raw mode is enabled, false otherwise.
 */
bool at_cmd_sysuartraw_is_active(void);

/**
 * @brief Forward a received UART byte into the raw bridge buffer.
 *
 * Call this from the UART ISR when at_cmd_sysuartraw_is_active() returns
 * true. The byte is placed in a ring buffer and transmitted over BLE via
 * a deferred work item.
 *
 * @param byte Received byte.
 */
void at_cmd_sysuartraw_rx_byte(uint8_t byte);

/**
 * @brief Feed BLE-received data into the raw bridge (direction=1: BLE→UART).
 *
 * Call this from the application's GATT write handler for the characteristic
 * identified by the att_idx parameter passed to AT+SYSUARTRAW. The data is
 * written to the UART output and the transfer exits automatically once the
 * configured length has been received.
 *
 * @param data Pointer to the received data buffer.
 * @param len  Number of bytes in the buffer.
 */
void at_cmd_sysuartraw_rx_ble_data(const uint8_t *data, uint16_t len);

#endif /* CONFIG_AT_CMD_SYSUARTRAW */

#ifdef __cplusplus
}
#endif
