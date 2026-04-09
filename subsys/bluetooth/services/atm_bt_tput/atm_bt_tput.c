/*
 * SPDX-License-Identifier: Apache-2.0
 * Copyright (c) 2025-2026 Atmosic
 */

#include <zephyr/bluetooth/bluetooth.h>
#include <zephyr/bluetooth/hci.h>
#include <zephyr/bluetooth/gatt.h>
#include <zephyr/logging/log.h>
#include <zephyr/sys/byteorder.h>
#include <string.h>
#include <inttypes.h>
#include "atm_bt_tput.h"
#include "atm_bt_tput_internal.h"
#ifdef CONFIG_VND_API_SET_CON_TX_POWER
#include "atm_vendor_api.h"
#endif

LOG_MODULE_REGISTER(bt_throughput, CONFIG_ATM_BT_TPUTP_LOG_LEVEL);

#define NOTIFY_PRELOAD_COUNT 3

/* Default total data size for test - uses default packet size for consistency */
#define TOTAL_DATA_SIZE CONFIG_ATM_TPUT_TEST_DATA_LEN_PER_PACKET *CONFIG_ATM_TPUT_TEST_PACKET_COUNT

static K_SEM_DEFINE(write_sem, 0, 1);

struct atm_bt_tput_context {
	struct {
		uint32_t total_bytes_received;
		uint32_t total_writes;
		uint32_t total_bytes_sent;
		uint32_t notify_count;
		uint32_t write_count;
		uint64_t start_time;
		uint64_t end_time;
	} stats;

	struct {
		uint32_t total_data_len;
		uint8_t data_len_per_notify;
		uint8_t data_len_per_write;
		uint16_t packet_count;
		int8_t tx_power; // Only used to see last saved value
		bool notify_enabled;
	} config;

	struct {
		struct bt_gatt_attr *notify_crch;
		struct bt_gatt_indicate_params ind_params;
		struct bt_gatt_notify_params notify_params;
		struct bt_gatt_read_params read_params;
		struct bt_gatt_subscribe_params subscribe_params;
		struct bt_gatt_discover_params discover_params;
		struct bt_uuid_128 discover_uuid;
		const struct bt_uuid *ccc_uuid;

		uint16_t write_characteristic_handle;
		uint16_t read_characteristic_handle;
		uint16_t notify_characteristic_handle;
	} gatt;

	atm_tput_measurement_cb callback_measure;
};

bool use_ack_mode = false;

// Use defaults from KConfig, user configurable during runtime
static struct atm_bt_tput_context tput_ctx = {
	.config =
		{
			.total_data_len = TOTAL_DATA_SIZE,
			.data_len_per_notify = CONFIG_ATM_TPUT_TEST_DATA_LEN_PER_PACKET,
			.data_len_per_write = CONFIG_ATM_TPUT_TEST_DATA_LEN_PER_PACKET,
			.packet_count = CONFIG_ATM_TPUT_TEST_PACKET_COUNT,
			.tx_power = 0, /* Default to 0 dBm */
		},
	.gatt =
		{
			.ccc_uuid = BT_UUID_GATT_CCC,
		},
};

/* Helper function to update total data length */
static void update_total_data_len(void)
{
	tput_ctx.config.total_data_len =
		tput_ctx.config.data_len_per_write * tput_ctx.config.packet_count;
	LOG_DBG("Total data length updated to %" PRIu32 " bytes (%" PRIu16 " packets × %" PRIu8
		" bytes)",
		tput_ctx.config.total_data_len, tput_ctx.config.packet_count,
		tput_ctx.config.data_len_per_write);
}

/* Forward declaration */
static void ccc_cfg_changed(const struct bt_gatt_attr *attr, uint16_t value);
static void bt_throughput_send_next_indication(struct bt_conn *conn);
static void bt_throughput_send_next_notification(struct bt_conn *conn, int count);

static void indicate_cb(struct bt_conn *conn, struct bt_gatt_indicate_params *params, uint8_t err)
{
	if (err) {
		LOG_ERR("Indication failed (err %d)", err);
		return;
	}

	tput_ctx.stats.total_bytes_sent += tput_ctx.config.data_len_per_notify;
	tput_ctx.stats.notify_count++;

	LOG_DBG("Ack for indication. Per indication %" PRIu8 " Total sent: %" PRIu32,
		tput_ctx.config.data_len_per_notify, tput_ctx.stats.total_bytes_sent);

	if (tput_ctx.stats.total_bytes_sent < tput_ctx.config.total_data_len) {
		bt_throughput_send_next_indication(conn);
	}
}

#define MAX_PAYLOAD_SIZE 244
static uint8_t payload_data[MAX_PAYLOAD_SIZE];

static void fill_payload(uint8_t *data, uint32_t notify_count, size_t total_len)
{
	struct atm_tput_data *tlv = (struct atm_tput_data *)data;

	sys_put_be32(notify_count, (uint8_t *)&tlv->data_value.notify_count.count);
}

static void bt_throughput_send_next_indication(struct bt_conn *conn)
{
	fill_payload(payload_data, tput_ctx.stats.notify_count,
		     tput_ctx.config.data_len_per_notify);

	tput_ctx.gatt.ind_params.data = payload_data;
	tput_ctx.gatt.ind_params.len = tput_ctx.config.data_len_per_notify;

	int err = bt_gatt_indicate(conn, &tput_ctx.gatt.ind_params);
	if (err) {
		LOG_ERR("bt_gatt_indicate failed (err %d)", err);
	}
}

static void notify_cb(struct bt_conn *conn, void *user_data)
{
	tput_ctx.stats.total_bytes_sent += tput_ctx.config.data_len_per_notify;
	tput_ctx.stats.notify_count++;

	LOG_DBG("Sent notification. Per notify %" PRIu8 " Total sent: %" PRIu32,
		tput_ctx.config.data_len_per_notify, tput_ctx.stats.total_bytes_sent);

	if (tput_ctx.stats.total_bytes_sent < tput_ctx.config.total_data_len) {
		/* send 1 more */
		bt_throughput_send_next_notification(conn, 1);
	}
}

static void bt_throughput_send_next_notification(struct bt_conn *conn, int count)
{

	while (count--) {
		fill_payload(payload_data, tput_ctx.stats.notify_count,
			     tput_ctx.config.data_len_per_notify);

		tput_ctx.gatt.notify_params.data = payload_data;
		tput_ctx.gatt.notify_params.len = tput_ctx.config.data_len_per_notify;

		int err = bt_gatt_notify_cb(conn, &tput_ctx.gatt.notify_params);
		if (err) {
			LOG_ERR("bt_gatt_notify_cb failed (err %d)", err);
		}
	}
}

static void bt_throughput_server_to_client(struct bt_conn *conn)
{
	__ASSERT(tput_ctx.config.notify_enabled, "Notify disabled %d",
		 tput_ctx.config.notify_enabled);

	struct atm_tput_data *tlv = (struct atm_tput_data *)payload_data;

	tput_ctx.stats.total_bytes_sent = 0;
	tput_ctx.stats.notify_count = 0;

	/* Initialize TLV header and payload first */
	tlv->type = TAG_NOTIFY_COUNT;
	tlv->data_len = sizeof(struct notify_count_payload);
	const size_t tlv_len = ATM_TPUT_TLV_SIZE(tlv->data_len);

	struct notify_count_payload *payload = &tlv->data_value.notify_count;
	sys_put_be32(tput_ctx.stats.notify_count, (uint8_t *)&payload->count);
	memset(payload->reserved, 0, sizeof(payload->reserved));

	/* Fill remaining space with message pattern */
	if (tput_ctx.config.data_len_per_notify > tlv_len) {
		const char *message = use_ack_mode ? "ATM Throughput test indication. "
						   : "ATM Throughput test notification. ";
		size_t fill_len = tput_ctx.config.data_len_per_notify - tlv_len;
		size_t msg_len = strlen(message);

		for (size_t i = 0; i < fill_len; i++) {
			payload_data[tlv_len + i] = message[i % msg_len];
		}
	}

	if (use_ack_mode) {
		tput_ctx.gatt.ind_params.attr = tput_ctx.gatt.notify_crch;
		tput_ctx.gatt.ind_params.data = payload_data;
		tput_ctx.gatt.ind_params.len = tput_ctx.config.data_len_per_notify;
		tput_ctx.gatt.ind_params.func = indicate_cb;

		bt_throughput_send_next_indication(conn);
	} else {
		tput_ctx.gatt.notify_params.attr = tput_ctx.gatt.notify_crch;
		tput_ctx.gatt.notify_params.data = payload_data;
		tput_ctx.gatt.notify_params.len = tput_ctx.config.data_len_per_notify;
		tput_ctx.gatt.notify_params.func = notify_cb;

		/* pipline 3 notifications */
		bt_throughput_send_next_notification(conn, NOTIFY_PRELOAD_COUNT);
	}
}

void reset_test_params(void)
{
	tput_ctx.stats.total_bytes_sent = 0;
	tput_ctx.stats.total_bytes_received = 0;
	tput_ctx.stats.total_writes = 0;
	tput_ctx.stats.notify_count = 0;
	tput_ctx.stats.write_count = 0;
	LOG_DBG("Test params are reset...");
}

static ssize_t write_callback(struct bt_conn *conn, const struct bt_gatt_attr *attr,
			      const void *buf, uint16_t len, uint16_t offset, uint8_t flags)
{
	/* TODO define a protocol to enable control and data messages */

	/* Check if this could be a control message (TLV format) */
	if (len < ATM_TPUT_TLV_HEADER_SIZE) {
		/* Not enough data for TLV header */
		LOG_WRN("Received data too short: %" PRIu16 " bytes", len);
		return len;
	}

	const struct atm_tput_data *tlv = (const struct atm_tput_data *)buf;
	uint8_t type = tlv->type;
	uint8_t value_len = tlv->data_len;

	/* Early return if length mismatch */
	if (len < ATM_TPUT_TLV_SIZE(value_len)) {
		LOG_WRN("Received control message length mismatch: expected %" PRIu16
			", got %" PRIu16,
			ATM_TPUT_TLV_SIZE(value_len), len);
		return len;
	}

	/* Handle control messages with switch statement */
	switch (type) {
	case TAG_TRIGGER_S2C_TEST: {
		if (value_len == sizeof(use_ack_mode)) {
			/* Legacy format: just ack mode */
			use_ack_mode = tlv->data_value.cmd_or_mode ? true : false;
		} else if (value_len == sizeof(struct s2c_test_params)) {
			/* New format: packet count, payload size, and ack mode */
			const struct s2c_test_params *params = &tlv->data_value.s2c_params;

			tput_ctx.config.packet_count = params->packet_count;
			tput_ctx.config.data_len_per_notify = params->payload_size;
			tput_ctx.config.data_len_per_write = params->payload_size;
			use_ack_mode = params->use_ack_mode ? true : false;
			update_total_data_len();

			LOG_INF("S2C test configured: %" PRIu16 " packets × %" PRIu8
				" bytes = %" PRIu32 " total bytes, "
				"ack_mode=%s",
				params->packet_count, params->payload_size,
				tput_ctx.config.total_data_len, use_ack_mode ? "true" : "false");
		} else {
			LOG_WRN("Invalid S2C trigger message length: %" PRIu8, value_len);
			break;
		}
		bt_throughput_server_to_client(conn);
	} break;

	case TAG_SET_TX_POWER: {
		if (value_len != sizeof(struct tx_power_config)) {
			LOG_WRN("Invalid TX power message length: %" PRIu8, value_len);
			break;
		}

		/* TX Power configuration message */
		int8_t tx_pwr = tlv->data_value.tx_power.tx_power;
		tput_ctx.config.tx_power = tx_pwr;

#ifdef CONFIG_VND_API_SET_CON_TX_POWER
		/* Apply TX power setting using vendor API */
		uint16_t conn_hdl;
		if (bt_hci_get_conn_handle(conn, &conn_hdl) == 0) {
			uint8_t result = atm_vendor_set_con_tx_power(conn_hdl, tx_pwr);
			if (result == 0) {
				LOG_INF("Peripheral TX power set to %" PRId8 " dBm", tx_pwr);
			} else {
				LOG_WRN("Failed to set peripheral TX power to %" PRId8
					" dBm (err %" PRIu8 ")",
					tx_pwr, result);
			}
		} else {
			LOG_WRN("Failed to get connection handle for TX power setting");
		}
#else
		LOG_INF("TX power config received: %" PRId8 " dBm (vendor API not enabled)",
			tx_pwr);
#endif
	} break;

#ifdef CONFIG_ATM_TPUT_AUTO_TEST
	case ATM_TPUT_END_TEST_CMD: {
		if (value_len != sizeof(uint8_t)) {
			LOG_WRN("Invalid end test command length: %" PRIu8, value_len);
			break;
		}

		uint8_t cmd = tlv->data_value.cmd_or_mode;
		if (cmd == ATM_TPUT_END_TEST_CMD) {
			LOG_INF("Received test end command");
			bt_conn_disconnect(conn, BT_HCI_ERR_LOCALHOST_TERM_CONN);
			break;
		}
		LOG_WRN("Invalid end test command value: %" PRIu8, cmd);
	} break;
	case ATM_C2S_DATA: {
		// Do nothing
	} break;
#endif

	default: {
		/* Unknown control message type - treat as test data */
		LOG_WRN("Unknown control message type: %" PRIu8, type);
	} break;
	}

	tput_ctx.stats.total_bytes_received += len;
	tput_ctx.stats.total_writes++;
	LOG_DBG("Received data, length: %" PRIu16, len);

	return len;
}

static ssize_t read_throughput_callback(struct bt_conn *conn, const struct bt_gatt_attr *attr,
					void *buf, uint16_t len, uint16_t offset)
{
	char tput_data[64];
	int tput_data_len;

	tput_data_len = snprintf(tput_data, sizeof(tput_data),
				 "Bytes rx: %" PRIu32 ", Writes: %" PRIu32 ", Bytes tx: %" PRIu32
				 ", Notifications: %" PRIu32,
				 tput_ctx.stats.total_bytes_received, tput_ctx.stats.total_writes,
				 tput_ctx.stats.total_bytes_sent, tput_ctx.stats.notify_count);

	return bt_gatt_attr_read(conn, attr, buf, len, offset, tput_data, tput_data_len);
}

BT_GATT_SERVICE_DEFINE(throughput_svc, BT_GATT_PRIMARY_SERVICE(THROUGHPUT_SERVICE_UUID),
		       BT_GATT_CHARACTERISTIC(THROUGHPUT_WRITE_CHARACTERISTIC_UUID,
					      BT_GATT_CHRC_WRITE_WITHOUT_RESP | BT_GATT_CHRC_WRITE,
					      BT_GATT_PERM_WRITE, NULL, write_callback, NULL),
		       BT_GATT_CHARACTERISTIC(THROUGHPUT_READ_CHARACTERISTIC_UUID,
					      BT_GATT_CHRC_READ, BT_GATT_PERM_READ,
					      read_throughput_callback, NULL, NULL),
		       BT_GATT_CHARACTERISTIC(THROUGHPUT_NOTIFY_CHARACTERISTIC_UUID,
					      BT_GATT_CHRC_NOTIFY | BT_GATT_CHRC_INDICATE,
					      BT_GATT_PERM_NONE, NULL, NULL, NULL),
		       BT_GATT_CCC(ccc_cfg_changed, BT_GATT_PERM_READ | BT_GATT_PERM_WRITE), );

static void ccc_cfg_changed(const struct bt_gatt_attr *attr, uint16_t value)
{
	tput_ctx.config.notify_enabled = true;
	if (!tput_ctx.gatt.notify_crch) {
		tput_ctx.gatt.notify_crch = bt_gatt_find_by_uuid(
			throughput_svc.attrs, 0xffff, THROUGHPUT_NOTIFY_CHARACTERISTIC_UUID);
	}

	if (value == BT_GATT_CCC_NOTIFY) {
		LOG_INF("Subscribing with CCC value: NOTIFY");
		reset_test_params();
	} else if (value == BT_GATT_CCC_INDICATE) {
		LOG_INF("Subscribing with CCC value: INDICATE");
		reset_test_params();
	} else {
		LOG_INF("Client unsubscribed");
	}
}

static uint8_t notify_func(struct bt_conn *conn, struct bt_gatt_subscribe_params *params,
			   const void *data, uint16_t length)
{
	if (!data) {
		LOG_INF("Notification subscription terminated");
		return BT_GATT_ITER_STOP;
	}

	tput_ctx.stats.total_bytes_received += length;
	tput_ctx.stats.notify_count++;

	if (tput_ctx.stats.total_bytes_received >= tput_ctx.config.total_data_len) {
		tput_ctx.stats.end_time = k_uptime_get();

		uint64_t time_spent_ms = tput_ctx.stats.end_time - tput_ctx.stats.start_time;
		float throughput = ((tput_ctx.stats.total_bytes_received * 8.0) / time_spent_ms);

		LOG_INF("S2C Total bytes received: %" PRIu32, tput_ctx.stats.total_bytes_received);
		LOG_INF("S2C Notifications: %" PRIu32, tput_ctx.stats.notify_count);
		LOG_INF("S2C Time spent: %llu ms", time_spent_ms);
		LOG_INF("S2C Throughput: %.2f kbps", (double)throughput);

		if (tput_ctx.callback_measure) {
			tput_ctx.callback_measure(conn, throughput);
		}
		int err = bt_gatt_unsubscribe(conn, &tput_ctx.gatt.subscribe_params);
		if (err) {
			LOG_ERR("Unsubscribe failed (err %d)", err);
		} else {
			LOG_INF("Unsubscribed from notifications/indications");
			reset_test_params();
		}
	}
	LOG_DBG("%s received: %" PRIu16 " bytes", use_ack_mode ? "INDICATION" : "NOTIFICATION",
		length);

	return BT_GATT_ITER_CONTINUE;
}

static atm_tput_service_ready_cb tput_ready_cb;

static uint8_t discover_func(struct bt_conn *conn, const struct bt_gatt_attr *attr,
			     struct bt_gatt_discover_params *params)
{
	if (!attr) {
		LOG_INF("Discovery complete");
		return BT_GATT_ITER_STOP;
	}

	int err = 0;

	if (!bt_uuid_cmp(tput_ctx.gatt.discover_params.uuid, THROUGHPUT_SERVICE_UUID)) {
		LOG_INF("Attribute handle %" PRIu16, attr->handle);
		memcpy(&tput_ctx.gatt.discover_uuid, THROUGHPUT_WRITE_CHARACTERISTIC_UUID,
		       sizeof(tput_ctx.gatt.discover_uuid));
		tput_ctx.gatt.discover_params.uuid = &tput_ctx.gatt.discover_uuid.uuid;
		tput_ctx.gatt.discover_params.start_handle = attr->handle + 1;
		tput_ctx.gatt.discover_params.type = BT_GATT_DISCOVER_CHARACTERISTIC;
		err = bt_gatt_discover(conn, &tput_ctx.gatt.discover_params);
		if (err) {
			LOG_INF("Discover failed (err %d)", err);
		}
	} else if (!bt_uuid_cmp(tput_ctx.gatt.discover_params.uuid,
				THROUGHPUT_WRITE_CHARACTERISTIC_UUID)) {
		tput_ctx.gatt.write_characteristic_handle = bt_gatt_attr_value_handle(attr);
		LOG_INF("Write charac handle %" PRIu16, tput_ctx.gatt.write_characteristic_handle);
		memcpy(&tput_ctx.gatt.discover_uuid, THROUGHPUT_READ_CHARACTERISTIC_UUID,
		       sizeof(tput_ctx.gatt.discover_uuid));
		tput_ctx.gatt.discover_params.uuid = &tput_ctx.gatt.discover_uuid.uuid;
		tput_ctx.gatt.discover_params.start_handle = attr->handle + 1;
		tput_ctx.gatt.discover_params.type = BT_GATT_DISCOVER_CHARACTERISTIC;
		err = bt_gatt_discover(conn, &tput_ctx.gatt.discover_params);
		if (err) {
			LOG_INF("Discover failed (err %d)\n", err);
		}
	} else if (!bt_uuid_cmp(tput_ctx.gatt.discover_params.uuid,
				THROUGHPUT_READ_CHARACTERISTIC_UUID)) {
		tput_ctx.gatt.read_characteristic_handle = bt_gatt_attr_value_handle(attr);
		LOG_INF("Read charac handle %" PRIu16, tput_ctx.gatt.read_characteristic_handle);
		memcpy(&tput_ctx.gatt.discover_uuid, THROUGHPUT_NOTIFY_CHARACTERISTIC_UUID,
		       sizeof(tput_ctx.gatt.discover_uuid));
		tput_ctx.gatt.discover_params.uuid = &tput_ctx.gatt.discover_uuid.uuid;
		tput_ctx.gatt.discover_params.start_handle = attr->handle + 1;
		tput_ctx.gatt.discover_params.type = BT_GATT_DISCOVER_CHARACTERISTIC;
		err = bt_gatt_discover(conn, &tput_ctx.gatt.discover_params);
		if (err) {
			LOG_INF("Discover failed (err %d)\n", err);
		}
	} else if (!bt_uuid_cmp(tput_ctx.gatt.discover_params.uuid,
				THROUGHPUT_NOTIFY_CHARACTERISTIC_UUID)) {
		tput_ctx.gatt.notify_characteristic_handle = bt_gatt_attr_value_handle(attr);
		LOG_INF("Notify charac handle %" PRIu16,
			tput_ctx.gatt.notify_characteristic_handle);
		tput_ctx.gatt.subscribe_params.value_handle =
			tput_ctx.gatt.notify_characteristic_handle;
		tput_ctx.gatt.discover_params.uuid = tput_ctx.gatt.ccc_uuid;
		tput_ctx.gatt.discover_params.start_handle = attr->handle + 2;
		tput_ctx.gatt.discover_params.type = BT_GATT_DISCOVER_DESCRIPTOR;
		err = bt_gatt_discover(conn, &tput_ctx.gatt.discover_params);
		if (err) {
			LOG_INF("Discover failed (err %d)\n", err);
		}
	} else {
		tput_ctx.gatt.subscribe_params.ccc_handle = attr->handle;
		tput_ctx.gatt.subscribe_params.notify = notify_func;
		/* if we reached here this discovery state machine has found all characteristics */
		LOG_INF("TPUT service discovery complete!");
		if (tput_ready_cb) {
			tput_ready_cb();
		}
	}

	return BT_GATT_ITER_STOP;
}

static uint8_t read_func(struct bt_conn *conn, uint8_t err, struct bt_gatt_read_params *params,
			 const void *data, uint16_t length)
{
	if (length) {
		uint64_t time_spent_ms = (tput_ctx.stats.end_time - tput_ctx.stats.start_time);
		float throughput = ((tput_ctx.stats.total_bytes_sent * 8.0) / time_spent_ms);

		LOG_INF("C2S Total bytes sent: %" PRIu32, tput_ctx.stats.total_bytes_sent);
		LOG_INF("C2S Total writes: %" PRIu32, tput_ctx.stats.write_count);
		LOG_INF("C2S Total time spent: %llu ms", time_spent_ms);
		LOG_INF("C2S Throughput: %.2f kbps", (double)throughput);

		reset_test_params();

		tput_ctx.callback_measure(conn, throughput);

		return BT_GATT_ITER_STOP;
	}

	return BT_GATT_ITER_CONTINUE;
}

static void read_throughput_metrics(struct bt_conn *conn, uint16_t handle)
{
	tput_ctx.gatt.read_params.func = read_func;
	tput_ctx.gatt.read_params.handle_count = 1;
	tput_ctx.gatt.read_params.single.handle = handle;
	tput_ctx.gatt.read_params.single.offset = 0U;

	int err = bt_gatt_read(conn, &tput_ctx.gatt.read_params);
	if (err) {
		LOG_ERR("Read failed (err %d)", err);
	}
}

void atm_tput_service_connect(struct bt_conn *conn, atm_tput_service_ready_cb cb)
{
	tput_ready_cb = cb;
	memcpy(&tput_ctx.gatt.discover_uuid, THROUGHPUT_SERVICE_UUID,
	       sizeof(tput_ctx.gatt.discover_uuid));
	tput_ctx.gatt.discover_params.uuid = &tput_ctx.gatt.discover_uuid.uuid;
	tput_ctx.gatt.discover_params.func = discover_func;
	tput_ctx.gatt.discover_params.start_handle = BT_ATT_FIRST_ATTRIBUTE_HANDLE;
	tput_ctx.gatt.discover_params.end_handle = BT_ATT_LAST_ATTRIBUTE_HANDLE;
	tput_ctx.gatt.discover_params.type = BT_GATT_DISCOVER_PRIMARY;

	int err = bt_gatt_discover(conn, &tput_ctx.gatt.discover_params);
	if (err) {
		LOG_ERR("Discover failed (err %d)", err);
	}
}

static void c2s_write_cb(struct bt_conn *conn, uint8_t err, struct bt_gatt_write_params *params)
{
	if (err) {
		LOG_ERR("Write failed (err %" PRIu8 ")", err);
	}
	k_sem_give(&write_sem);
}

void atm_tput_measure_c2s(struct bt_conn *conn, atm_tput_measurement_cb cb)
{
	__ASSERT(tput_ctx.gatt.write_characteristic_handle, "Invalid write handle %d",
		 tput_ctx.gatt.write_characteristic_handle);

	uint8_t data[MAX_PAYLOAD_SIZE];
	int err;

	k_sleep(K_MSEC(500));
	reset_test_params();
#ifdef CONFIG_ATM_TPUT_AUTO_TEST
	struct atm_tput_data *tlv = (struct atm_tput_data *)data;
	tlv->type = ATM_C2S_DATA;
	tlv->data_len = tput_ctx.config.data_len_per_write - ATM_TPUT_TLV_HEADER_SIZE;
#endif

	tput_ctx.callback_measure = cb;
	tput_ctx.stats.start_time = k_uptime_get();

	while (tput_ctx.stats.total_bytes_sent < tput_ctx.config.total_data_len) {
		if (use_ack_mode) {
			struct bt_gatt_write_params params;

			params.handle = tput_ctx.gatt.write_characteristic_handle;
			params.data = data;
			params.length = tput_ctx.config.data_len_per_write;
			params.func = c2s_write_cb;
			params.offset = 0;

			err = bt_gatt_write(conn, &params);
			if (!err) {
				k_sem_take(&write_sem, K_FOREVER);
			}

		} else {
			err = bt_gatt_write_without_response(
				conn, tput_ctx.gatt.write_characteristic_handle, data,
				tput_ctx.config.data_len_per_write, false);
		}

		if (err) {
			LOG_ERR("Write %s response failed (err %d)",
				use_ack_mode ? "with" : "without", err);
		} else {
			tput_ctx.stats.total_bytes_sent += tput_ctx.config.data_len_per_write;
			tput_ctx.stats.write_count++;
			LOG_DBG("Data written: %" PRIu8 " bytes",
				tput_ctx.config.data_len_per_write);
		}
	}

	tput_ctx.stats.end_time = k_uptime_get();

	__ASSERT(tput_ctx.gatt.read_characteristic_handle, "Invalid read handle %d",
		 tput_ctx.gatt.read_characteristic_handle);
	read_throughput_metrics(conn, tput_ctx.gatt.read_characteristic_handle);
}

void atm_tput_measure_s2c(struct bt_conn *conn, atm_tput_measurement_cb cb)
{
	tput_ctx.callback_measure = cb;
	__ASSERT(tput_ctx.gatt.write_characteristic_handle, "Invalid write handle %d",
		 tput_ctx.gatt.write_characteristic_handle);

	tput_ctx.gatt.subscribe_params.value =
		use_ack_mode ? BT_GATT_CCC_INDICATE : BT_GATT_CCC_NOTIFY;

	int err = bt_gatt_subscribe(conn, &tput_ctx.gatt.subscribe_params);
	if (err) {
		LOG_ERR("Subscribe failed (err %d)", err);
	} else {
		LOG_INF("Subscribed to %s", use_ack_mode ? "Indication" : "Notification");
	}

	uint8_t data[sizeof(struct atm_tput_data)];
	struct atm_tput_data *tlv = (struct atm_tput_data *)data;
	tlv->type = TAG_TRIGGER_S2C_TEST;
	tlv->data_len = sizeof(struct s2c_test_params);

	struct s2c_test_params *params = &tlv->data_value.s2c_params;
	params->packet_count = tput_ctx.config.packet_count;
	params->payload_size = tput_ctx.config.data_len_per_notify;
	params->use_ack_mode = use_ack_mode;

	size_t actual_size = ATM_TPUT_TLV_SIZE(tlv->data_len);
	err = bt_gatt_write_without_response(conn, tput_ctx.gatt.write_characteristic_handle, data,
					     actual_size, false);
	if (err) {
		LOG_ERR("Write without response failed (err %d)", err);
	} else {
		LOG_DBG("Data written: %zu bytes", actual_size);
	}

	tput_ctx.stats.start_time = k_uptime_get();
}

#ifdef CONFIG_ATM_TPUT_AUTO_TEST
void atm_tput_client_done(struct bt_conn *conn)
{
	__ASSERT(tput_ctx.gatt.write_characteristic_handle, "Invalid write handle %d",
		 tput_ctx.gatt.write_characteristic_handle);

	uint8_t data[sizeof(struct atm_tput_data)];
	struct atm_tput_data *tlv = (struct atm_tput_data *)data;
	tlv->type = ATM_TPUT_END_TEST_CMD;
	tlv->data_len = sizeof(uint8_t);
	tlv->data_value.cmd_or_mode = ATM_TPUT_END_TEST_CMD;

	size_t actual_size = ATM_TPUT_TLV_SIZE(tlv->data_len);
	int err = bt_gatt_write_without_response(conn, tput_ctx.gatt.write_characteristic_handle,
						 data, actual_size, false);
	if (err) {
		LOG_ERR("Failed to issue end test command (err %d)", err);
	}
}
#endif /* CONFIG_ATM_TPUT_AUTO_TEST */

void atm_tput_set_payload_size(uint32_t payload_size)
{
	if (payload_size < 1 || payload_size > MAX_PAYLOAD_SIZE) {
		LOG_ERR("Invalid payload size: %" PRIu32 " (valid range: 1-%" PRIu32 ")",
			payload_size, MAX_PAYLOAD_SIZE);
		return;
	}

	tput_ctx.config.data_len_per_notify = (uint8_t)payload_size;
	tput_ctx.config.data_len_per_write = (uint8_t)payload_size;
	update_total_data_len();

	LOG_INF("Payload size set to %" PRIu32 " bytes for both C2S and S2C transactions",
		payload_size);
}

uint32_t atm_tput_get_payload_size(void)
{
	return tput_ctx.config.data_len_per_write;
}

void atm_tput_set_packet_count(uint16_t packet_count)
{
	if (packet_count == 0) {
		LOG_ERR("Invalid packet count: %" PRIu16 " (valid range: 1-65535)", packet_count);
		return;
	}

	tput_ctx.config.packet_count = packet_count;
	update_total_data_len();

	LOG_INF("Packet count set to %" PRIu16 " packets", packet_count);
}

uint16_t atm_tput_get_packet_count(void)
{
	return tput_ctx.config.packet_count;
}

void atm_tput_set_tx_power(struct bt_conn *conn, int8_t tx_power)
{
	if (!conn) {
		LOG_ERR("Invalid connection for TX power setting");
		return;
	}

	/* Validate TX power level against supported values */
	int8_t supported_levels[] = {-20, -10, -8, -4, -2, 0, 2, 4, 6, 8, 10};
	bool valid = false;
	for (size_t i = 0; i < ARRAY_SIZE(supported_levels); i++) {
		if (tx_power == supported_levels[i]) {
			valid = true;
			break;
		}
	}

	if (!valid) {
		LOG_ERR("Invalid TX power level: %" PRId8
			" (supported: -20,-10,-8,-4,-2,0,2,4,6,8,10)",
			tx_power);
		return;
	}

	/* Store the TX power setting */
	tput_ctx.config.tx_power = tx_power;

	int err;
#ifdef CONFIG_VND_API_SET_CON_TX_POWER
	/* Set TX power on central device */
	uint16_t conn_hdl;
	err = bt_hci_get_conn_handle(conn, &conn_hdl);
	if (err) {
		LOG_ERR("Failed to get connection handle for central TX power (err %d)", err);
	} else {
		uint8_t result = atm_vendor_set_con_tx_power(conn_hdl, tx_power);
		if (result == 0) {
			LOG_INF("Central TX power set to %" PRId8 " dBm", tx_power);
		} else {
			LOG_ERR("Failed to set central TX power to %" PRId8 " dBm (err %" PRIu8 ")",
				tx_power, result);
		}
	}
#endif

	/* Send TX power configuration to peripheral */
	uint8_t data[sizeof(struct atm_tput_data)];
	struct atm_tput_data *tlv = (struct atm_tput_data *)data;
	tlv->type = TAG_SET_TX_POWER;
	tlv->data_len = sizeof(struct tx_power_config);

	tlv->data_value.tx_power.tx_power = tx_power;

	size_t actual_size = ATM_TPUT_TLV_SIZE(tlv->data_len);
	err = bt_gatt_write_without_response(conn, tput_ctx.gatt.write_characteristic_handle, data,
					     actual_size, false);
	if (err) {
		LOG_ERR("Failed to send TX power config to peripheral (err %d)", err);
	} else {
		LOG_INF("TX power configuration sent to peripheral: %" PRId8 " dBm", tx_power);
	}
}

int8_t atm_tput_get_tx_power(void)
{
	return tput_ctx.config.tx_power;
}
