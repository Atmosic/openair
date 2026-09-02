/*
 * Copyright (c) Atmosic 2026
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include <zephyr/bluetooth/uuid.h>
#include <zephyr/bluetooth/gatt.h>
#include <zephyr/logging/log.h>
#include <string.h>

#include "hogp.h"

LOG_MODULE_REGISTER(hogp, CONFIG_HOGP_LOG_LEVEL);

/* -------------------------------------------------------------------------
 * HID service static data
 * -----------------------------------------------------------------------*/

enum {
	HIDS_REMOTE_WAKE = BIT(0),
	HIDS_NORMALLY_CONNECTABLE = BIT(1),
};

struct hids_info {
	uint16_t version; /* bcdHID: USB HID spec revision */
	uint8_t code;     /* bCountryCode */
	uint8_t flags;
} __packed;

struct hids_report_ref {
	uint8_t id;   /* Report ID */
	uint8_t type; /* Report type: 1=Input, 2=Output, 3=Feature */
} __packed;

enum {
	HIDS_INPUT = 0x01,
	HIDS_OUTPUT = 0x02,
	HIDS_FEATURE = 0x03,
};

static const struct hids_info info = {
	.version = 0x0111, /* HID spec 1.11 */
	.code = 0x00,      /* Not localized */
	.flags = HIDS_NORMALLY_CONNECTABLE,
};

static const struct hids_report_ref kbd_input_ref = {
	.id = HOGP_REPORT_ID_KBD,
	.type = HIDS_INPUT,
};

static const struct hids_report_ref led_output_ref = {
	.id = HOGP_REPORT_ID_LED,
	.type = HIDS_OUTPUT,
};

static const struct hids_report_ref consumer_input_ref = {
	.id = HOGP_REPORT_ID_CONSUMER,
	.type = HIDS_INPUT,
};

/*
 * HID Report Map:
 *   Report 1 (INPUT,  8 B): Keyboard — modifier + reserved + 6 key codes
 *   Report 2 (OUTPUT, 1 B): LED indicators (host → device)
 *   Report 3 (INPUT,  4 B): Consumer Control — 2×uint16_t key codes
 */
static const uint8_t report_map[] = {
	/* --- Keyboard + LED (Usage Page: Generic Desktop, Usage: Keyboard) --- */
	0x05, 0x01,               /* Usage Page (Generic Desktop) */
	0x09, 0x06,               /* Usage (Keyboard) */
	0xA1, 0x01,               /* Collection (Application) */
	0x85, HOGP_REPORT_ID_KBD, /* Report ID */

	/* Modifier keys: 8 × 1-bit */
	0x05, 0x07, /* Usage Page (Key Codes) */
	0x19, 0xE0, /* Usage Minimum (224 = Left Ctrl) */
	0x29, 0xE7, /* Usage Maximum (231 = Right Meta) */
	0x15, 0x00, /* Logical Minimum (0) */
	0x25, 0x01, /* Logical Maximum (1) */
	0x75, 0x01, /* Report Size (1 bit) */
	0x95, 0x08, /* Report Count (8) */
	0x81, 0x02, /* Input (Data, Variable, Absolute) */

	/* Reserved byte: 8 × 1-bit constant */
	0x75, 0x01, 0x95, 0x08, 0x81, 0x01, /* Input (Constant) */

	/* Key array: 6 × 8-bit */
	0x95, HOGP_KEY_ARRAY_SIZE, /* Report Count (6) */
	0x75, 0x08,                /* Report Size (8 bits) */
	0x15, 0x00,                /* Logical Minimum (0) */
	0x25, 0x65,                /* Logical Maximum (101) */
	0x05, 0x07,                /* Usage Page (Key Codes) */
	0x19, 0x00,                /* Usage Minimum (0) */
	0x29, 0x65,                /* Usage Maximum (101) */
	0x81, 0x00,                /* Input (Data, Array) */

	/* LED output: 5 indicators + 3-bit pad */
	0x85, HOGP_REPORT_ID_LED, /* Report ID */
	0x95, 0x05,               /* Report Count (5) */
	0x75, 0x01,               /* Report Size (1) */
	0x05, 0x08,               /* Usage Page (LEDs) */
	0x19, 0x01,               /* Usage Minimum (Num Lock) */
	0x29, 0x05,               /* Usage Maximum (Kana) */
	0x91, 0x02,               /* Output (Data, Variable, Absolute) */
	0x95, 0x01,               /* Report Count (1) */
	0x75, 0x03,               /* Report Size (3) — padding */
	0x91, 0x01,               /* Output (Constant) */

	0xC0, /* End Collection */

	/* --- Consumer Control ------------------------------------------------ */
	0x05, 0x0C,                    /* Usage Page (Consumer Devices) */
	0x09, 0x01,                    /* Usage (Consumer Control) */
	0xA1, 0x01,                    /* Collection (Application) */
	0x85, HOGP_REPORT_ID_CONSUMER, /* Report ID */
	0x75, 0x10,                    /* Report Size (16 bits) */
	0x95, 0x02,                    /* Report Count (2) */
	0x15, 0x01,                    /* Logical Minimum (1) */
	0x26, 0xFF, 0x07,              /* Logical Maximum (2047) */
	0x19, 0x01,                    /* Usage Minimum (1) */
	0x2A, 0x9C, 0x02,              /* Usage Maximum (0x029C) */
	0x81, 0x00,                    /* Input (Data, Array) */
	0xC0,                          /* End Collection */
};

/* -------------------------------------------------------------------------
 * Runtime state
 * -----------------------------------------------------------------------*/

static hogp_state_cb_t state_cb;
static hogp_led_cb_t led_cb;
static hogp_state_t hids_state = HOGP_STATE_SUSPEND;
static uint8_t ctrl_point;
static uint8_t led_value;
static bool consumer_notify_enabled;

/* Last sent keyboard report, used to generate release-all */
static struct hogp_kbd_report current_kbd_report;

/* -------------------------------------------------------------------------
 * GATT read/write callbacks
 * -----------------------------------------------------------------------*/

static ssize_t read_info(struct bt_conn *conn, const struct bt_gatt_attr *attr, void *buf,
			 uint16_t len, uint16_t offset)
{
	return bt_gatt_attr_read(conn, attr, buf, len, offset, &info, sizeof(info));
}

static ssize_t read_report_map(struct bt_conn *conn, const struct bt_gatt_attr *attr, void *buf,
			       uint16_t len, uint16_t offset)
{
	return bt_gatt_attr_read(conn, attr, buf, len, offset, report_map, sizeof(report_map));
}

static ssize_t read_report_ref(struct bt_conn *conn, const struct bt_gatt_attr *attr, void *buf,
			       uint16_t len, uint16_t offset)
{
	return bt_gatt_attr_read(conn, attr, buf, len, offset, attr->user_data,
				 sizeof(struct hids_report_ref));
}

static ssize_t read_input_report(struct bt_conn *conn, const struct bt_gatt_attr *attr, void *buf,
				 uint16_t len, uint16_t offset)
{
	return bt_gatt_attr_read(conn, attr, buf, len, offset, NULL, 0);
}

static ssize_t write_ctrl_point(struct bt_conn *conn, const struct bt_gatt_attr *attr,
				const void *buf, uint16_t len, uint16_t offset, uint8_t flags)
{
	if (offset + len > sizeof(ctrl_point)) {
		return BT_GATT_ERR(BT_ATT_ERR_INVALID_OFFSET);
	}
	memcpy(&ctrl_point + offset, buf, len);
	return len;
}

static ssize_t read_led_report(struct bt_conn *conn, const struct bt_gatt_attr *attr, void *buf,
			       uint16_t len, uint16_t offset)
{
	return bt_gatt_attr_read(conn, attr, buf, len, offset, &led_value, sizeof(led_value));
}

static ssize_t write_led_report(struct bt_conn *conn, const struct bt_gatt_attr *attr,
				const void *buf, uint16_t len, uint16_t offset, uint8_t flags)
{
	if (offset + len > sizeof(led_value)) {
		return BT_GATT_ERR(BT_ATT_ERR_INVALID_OFFSET);
	}
	memcpy(&led_value + offset, buf, len);
	LOG_DBG("LED report: 0x%02x", led_value);
	if (led_cb) {
		led_cb(led_value);
	}
	return len;
}

/* -------------------------------------------------------------------------
 * CCC changed callbacks
 * -----------------------------------------------------------------------*/

static void kbd_ccc_changed(const struct bt_gatt_attr *attr, uint16_t value)
{
	hogp_state_t new_state =
		(value == BT_GATT_CCC_NOTIFY) ? HOGP_STATE_READY : HOGP_STATE_SUSPEND;

	LOG_INF("KBD CCC: %u -> state %d", value, new_state);
	hids_state = new_state;
	if (state_cb) {
		state_cb(new_state);
	}
}

static void consumer_ccc_changed(const struct bt_gatt_attr *attr, uint16_t value)
{
	consumer_notify_enabled = (value == BT_GATT_CCC_NOTIFY);
	LOG_INF("Consumer CCC: %u", value);
}

/* -------------------------------------------------------------------------
 * GATT service definition
 *
 * Attribute index map:
 *   [0]  Primary service declaration
 *   [1]  HID Info characteristic declaration
 *   [2]  HID Info value
 *   [3]  Report Map characteristic declaration
 *   [4]  Report Map value
 *   [5]  Keyboard Input characteristic declaration
 *   [6]  Keyboard Input value          ← hogp_send_kbd_report() notifies here
 *   [7]  Keyboard Input CCC
 *   [8]  Keyboard Input Report Ref descriptor
 *   [9]  LED Output characteristic declaration
 *  [10]  LED Output value
 *  [11]  LED Output Report Ref descriptor
 *  [12]  Consumer Input characteristic declaration
 *  [13]  Consumer Input value          ← hogp_send_consumer_report() notifies here
 *  [14]  Consumer Input CCC
 *  [15]  Consumer Input Report Ref descriptor
 *  [16]  Control Point characteristic declaration
 *  [17]  Control Point value
 * -----------------------------------------------------------------------*/

BT_GATT_SERVICE_DEFINE(
	hogp_svc, BT_GATT_PRIMARY_SERVICE(BT_UUID_HIDS),

	/* HID Info (read-only) */
	BT_GATT_CHARACTERISTIC(BT_UUID_HIDS_INFO, BT_GATT_CHRC_READ, BT_GATT_PERM_READ, read_info,
			       NULL, NULL),

	/* Report Map (read-only) */
	BT_GATT_CHARACTERISTIC(BT_UUID_HIDS_REPORT_MAP, BT_GATT_CHRC_READ, BT_GATT_PERM_READ,
			       read_report_map, NULL, NULL),

	/* Keyboard INPUT report: read + notify, encrypted CCC write */
	BT_GATT_CHARACTERISTIC(BT_UUID_HIDS_REPORT, BT_GATT_CHRC_READ | BT_GATT_CHRC_NOTIFY,
			       BT_GATT_PERM_READ, read_input_report, NULL, NULL),
	BT_GATT_CCC(kbd_ccc_changed, BT_GATT_PERM_READ | BT_GATT_PERM_WRITE_ENCRYPT),
	BT_GATT_DESCRIPTOR(BT_UUID_HIDS_REPORT_REF, BT_GATT_PERM_READ, read_report_ref, NULL,
			   (void *)&kbd_input_ref),

	/* LED OUTPUT report: read + write (host sets LEDs) */
	BT_GATT_CHARACTERISTIC(BT_UUID_HIDS_REPORT,
			       BT_GATT_CHRC_READ | BT_GATT_CHRC_WRITE |
				       BT_GATT_CHRC_WRITE_WITHOUT_RESP,
			       BT_GATT_PERM_READ | BT_GATT_PERM_WRITE, read_led_report,
			       write_led_report, NULL),
	BT_GATT_DESCRIPTOR(BT_UUID_HIDS_REPORT_REF, BT_GATT_PERM_READ, read_report_ref, NULL,
			   (void *)&led_output_ref),

	/* Consumer Control INPUT report: read + notify, encrypted CCC write */
	BT_GATT_CHARACTERISTIC(BT_UUID_HIDS_REPORT, BT_GATT_CHRC_READ | BT_GATT_CHRC_NOTIFY,
			       BT_GATT_PERM_READ, read_input_report, NULL, NULL),
	BT_GATT_CCC(consumer_ccc_changed, BT_GATT_PERM_READ | BT_GATT_PERM_WRITE_ENCRYPT),
	BT_GATT_DESCRIPTOR(BT_UUID_HIDS_REPORT_REF, BT_GATT_PERM_READ, read_report_ref, NULL,
			   (void *)&consumer_input_ref),

	/* HID Control Point (write-without-response) */
	BT_GATT_CHARACTERISTIC(BT_UUID_HIDS_CTRL_POINT, BT_GATT_CHRC_WRITE_WITHOUT_RESP,
			       BT_GATT_PERM_WRITE, NULL, write_ctrl_point, &ctrl_point), );

/* -------------------------------------------------------------------------
 * Public API
 * -----------------------------------------------------------------------*/

void hogp_init(hogp_state_cb_t s_cb, hogp_led_cb_t l_cb)
{
	state_cb = s_cb;
	led_cb = l_cb;
}

int hogp_send_kbd_report(const struct hogp_kbd_report *rpt)
{
	struct bt_gatt_notify_params params = {0};

	if (hids_state != HOGP_STATE_READY) {
		return -ENOTCONN;
	}

	if (rpt) {
		current_kbd_report = *rpt;
	} else {
		memset(&current_kbd_report, 0, sizeof(current_kbd_report));
	}

	params.attr = &hogp_svc.attrs[6];
	params.data = &current_kbd_report;
	params.len = sizeof(current_kbd_report);

	int ret = bt_gatt_notify_cb(NULL, &params);
	if (ret) {
		LOG_DBG("KBD notify err %d", ret);
	}
	return ret;
}

int hogp_send_consumer_report(uint16_t key1, uint16_t key2)
{
	struct bt_gatt_notify_params params = {0};
	struct hogp_consumer_report rpt = {.key1 = key1, .key2 = key2};

	if (!consumer_notify_enabled) {
		return -ENOTCONN;
	}

	params.attr = &hogp_svc.attrs[13];
	params.data = &rpt;
	params.len = sizeof(rpt);

	int ret = bt_gatt_notify_cb(NULL, &params);
	if (ret) {
		LOG_DBG("Consumer notify err %d", ret);
	}
	return ret;
}

hogp_state_t hogp_get_state(void)
{
	return hids_state;
}
