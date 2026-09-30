/*
 * Copyright (c) Atmosic 2026
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#pragma once

#include <stdint.h>
#include <zephyr/bluetooth/gatt.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @file hogp.h
 * @brief HID over GATT Profile (HOGP) library
 *
 * Implements a BLE HID peripheral service with:
 *   - Keyboard INPUT report   (Report ID 1): 8 bytes
 *     [modifier][reserved][key0]..[key5]
 *   - LED OUTPUT report       (Report ID 2): 1 byte (host → device)
 *   - Consumer Control INPUT  (Report ID 3): 4 bytes (2 × uint16_t)
 *
 * The GATT service is registered at system init via BT_GATT_SERVICE_DEFINE.
 * Call hogp_init() before enabling the BT stack so callbacks are in place
 * before any connection is established.
 */

/** Number of regular (non-modifier) keys in a keyboard report */
#define HOGP_KEY_ARRAY_SIZE 6

/** HID Report ID assignments */
#define HOGP_REPORT_ID_KBD      1
#define HOGP_REPORT_ID_LED      2
#define HOGP_REPORT_ID_CONSUMER 3

/** Keyboard modifier bitmask values (USB HID) */
#define HOGP_MOD_LCTRL  BIT(0)
#define HOGP_MOD_LSHIFT BIT(1)
#define HOGP_MOD_LALT   BIT(2)
#define HOGP_MOD_LMETA  BIT(3)
#define HOGP_MOD_RCTRL  BIT(4)
#define HOGP_MOD_RSHIFT BIT(5)
#define HOGP_MOD_RALT   BIT(6)
#define HOGP_MOD_RMETA  BIT(7)

/** LED output bitmask values (USB HID) */
#define HOGP_LED_NUM_LOCK    BIT(0)
#define HOGP_LED_CAPS_LOCK   BIT(1)
#define HOGP_LED_SCROLL_LOCK BIT(2)
#define HOGP_LED_COMPOSE     BIT(3)
#define HOGP_LED_KANA        BIT(4)

/**
 * Keyboard INPUT report (Report ID 1, 8 bytes).
 * One modifier byte, one reserved byte, six key-code bytes.
 */
struct hogp_kbd_report {
	uint8_t modifier_keys;
	uint8_t reserved;
	uint8_t keys[HOGP_KEY_ARRAY_SIZE];
} __packed;

/**
 * Consumer Control INPUT report (Report ID 3, 4 bytes).
 * Two 16-bit consumer key codes; set unused slot to 0.
 */
struct hogp_consumer_report {
	uint16_t key1;
	uint16_t key2;
} __packed;

/** HIDS connection state as seen by the application */
typedef enum {
	/** Device connected but host has not enabled notifications (CCC = 0) */
	HOGP_STATE_SUSPEND,
	/** Device connected and host has enabled keyboard notifications (CCC = 1) */
	HOGP_STATE_READY,
} hogp_state_t;

/**
 * Callback invoked when the keyboard report CCC descriptor changes.
 *
 * @param state  New HIDS state.
 */
typedef void (*hogp_state_cb_t)(hogp_state_t state);

/**
 * Callback invoked when the host writes the LED OUTPUT report.
 *
 * @param led_bitmap  LED state bitmask (@ref HOGP_LED_CAPS_LOCK etc.).
 */
typedef void (*hogp_led_cb_t)(uint8_t led_bitmap);

/**
 * @brief Register application callbacks and prepare the HOGP library.
 *
 * Must be called before BT is enabled so the callbacks are registered before
 * any connection arrives.  Safe to call multiple times — later calls replace
 * the registered callbacks.
 *
 * @param state_cb  Called when keyboard CCC changes (may be NULL).
 * @param led_cb    Called when host writes LED output report (may be NULL).
 */
void hogp_init(hogp_state_cb_t state_cb, hogp_led_cb_t led_cb);

/**
 * @brief Send a keyboard INPUT report notification.
 *
 * Sends to all connected peers that have enabled notifications.
 * Returns 0 on success, -ENOTCONN if no peer has enabled notifications,
 * or a negative Bluetooth error code.
 *
 * @param report  Keyboard report to send; NULL sends a release-all report.
 */
int hogp_send_kbd_report(const struct hogp_kbd_report *report);

/**
 * @brief Send a keyboard release-all report (all keys up).
 *
 * Convenience wrapper for hogp_send_kbd_report(NULL).
 */
static inline int hogp_send_kbd_release_all(void)
{
	return hogp_send_kbd_report(NULL);
}

/**
 * @brief Send a Consumer Control INPUT report notification.
 *
 * @param key1  First consumer key code (0 = no key).
 * @param key2  Second consumer key code (0 = no key).
 */
int hogp_send_consumer_report(uint16_t key1, uint16_t key2);

/**
 * @brief Get the current HIDS connection state.
 */
hogp_state_t hogp_get_state(void);

#ifdef __cplusplus
}
#endif
