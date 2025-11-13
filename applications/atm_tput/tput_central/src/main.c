/*
 * SPDX-License-Identifier: Apache-2.0
 * Copyright (c) 2025 Atmosic
 */

#include <zephyr/bluetooth/bluetooth.h>
#include <zephyr/bluetooth/conn.h>
#include <zephyr/bluetooth/gatt.h>
#include <zephyr/bluetooth/hci.h>
#include <zephyr/logging/log.h>
#include <zephyr/shell/shell.h>
#include <zephyr/sys/util.h>
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include "atm_bt_tput.h"

LOG_MODULE_REGISTER(ble_tput_test, CONFIG_ATM_BT_TPUTP_LOG_LEVEL);

#define MIN_CONN_INTERVAL          6
#define MAX_CONN_INTERVAL          3200
#define INTERVAL_UNIT_TO_MS_X100   125 /*  1 unit = 1.25 1.25*100 */
#define TIMEOUT_UNIT_TO_MS         10
#define ATM_BT_GAP_DATA_TIME       2120
#define ATM_SUPERVISION_TIMEOUT    100
#define LINK_CONFIG_UPDATE_PENDING (1 << 0)
#define PHY_UPDATE_PENDING         (1 << 1)
#define CONN_PARAM_UPDATE_PENDING  (1 << 2)
#define DATA_LEN_UPDATE_PENDING    (1 << 3)
#define FILTER_DEVICE_NAME         "ATM_TPUTP Periph"
#define FILTER_DEVICE_NAME_LEN     (sizeof(FILTER_DEVICE_NAME) - 1)

static void device_found(const bt_addr_le_t *addr, int8_t rssi, uint8_t adv_type,
			 struct net_buf_simple *buf);
static void scan_start(void);
static void set_configurations(void);
static void tput_test_start_work_handler(struct k_work *work);
K_WORK_DEFINE(tput_test_start_work, tput_test_start_work_handler);
K_THREAD_STACK_DEFINE(atm_tput_stack, 1024);
static struct k_work_q atm_tput_work_q;
static uint8_t link_state_flags;

enum atm_phy_modes {
	ATM_BT_1M_PHY,
	ATM_BT_2M_PHY,
	ATM_BT_CODED_S2_PHY,
	ATM_BT_CODED_S8_PHY,
};

enum test_direction {
	TEST_C2S_ONLY = 0,
	TEST_S2C_ONLY = 1,
	TEST_BOTH = 2, /* Default: C2S followed by S2C */
};

typedef struct {
	struct bt_conn *default_conn;
	struct bt_le_conn_param user_conn_params;
	struct bt_conn_le_data_len_param data_len_param;
	bt_addr_le_t target_bd_addr;
	uint8_t user_phy_mode;
	bool connected;
	bool is_central;
	bool use_bd_addr_filter;
	bool params_configured;
	bool data_length_configured;
	bool phy_mode_configured;
	bool conn_interval_configured;
	enum test_direction test_direction;
} atm_bt_tput_context;

static atm_bt_tput_context atm_bt_ctx = {
	.user_phy_mode = CONFIG_ATM_TPUT_TEST_PHY_MODE,
	.test_direction = TEST_BOTH,
	.user_conn_params =
		{
			.interval_min = CONFIG_ATM_TPUT_TEST_CONN_INTERVAL_MIN,
			.interval_max = CONFIG_ATM_TPUT_TEST_CONN_INTERVAL_MAX,
			.latency = 0,
			.timeout = ATM_SUPERVISION_TIMEOUT,
		},
	.data_len_param =
		{
			.tx_max_len = BT_GAP_DATA_LEN_MAX,
			.tx_max_time = ATM_BT_GAP_DATA_TIME,
		},
};

static void atm_tput_measure_s2c_cb(struct bt_conn *conn, double throughput)
{
	LOG_INF("%s(%d): %f kbps\n", __func__, __LINE__, throughput);
	LOG_INF("Test complete");
#ifdef CONFIG_AUTO_TEST
	LOG_INF("Central side is done \n");
	atm_tput_client_done(conn);
#endif
}

static void atm_tput_measure_c2s_cb(struct bt_conn *conn, double throughput)
{
	LOG_INF("%s(%d): %f kbps\n", __func__, __LINE__, throughput);

	/* Only start S2C test if direction is BOTH or S2C_ONLY */
	if (atm_bt_ctx.test_direction == TEST_BOTH) {
		atm_tput_measure_s2c(conn, atm_tput_measure_s2c_cb);
	} else {
		LOG_INF("Test complete (C2S only)");
	}
}

static void tput_service_ready_cb(void)
{
#ifdef CONFIG_SHELL
	LOG_INF("Throughput service ready. Use 'start_test' command to begin testing.");
#else
	/* Auto-start test when shell is not available */
	k_work_submit_to_queue(&atm_tput_work_q, &tput_test_start_work);
#endif
}

static void tput_test_start_work_handler(struct k_work *work)
{
	switch (atm_bt_ctx.test_direction) {
	case TEST_C2S_ONLY:
	case TEST_BOTH:
		atm_tput_measure_c2s(atm_bt_ctx.default_conn, atm_tput_measure_c2s_cb);
		break;
	case TEST_S2C_ONLY:
		atm_tput_measure_s2c(atm_bt_ctx.default_conn, atm_tput_measure_s2c_cb);
		break;
	}
}

static void mtu_exchange_cb(struct bt_conn *conn, uint8_t err,
			    struct bt_gatt_exchange_params *params)
{
	LOG_INF("MTU exchange %s (%" PRIu16 ")", err == 0U ? "successful" : "failed",
		bt_gatt_get_mtu(conn));
	if (!err) {
		set_configurations();
	}
}

static struct bt_gatt_exchange_params mtu_exchange_params = {.func = mtu_exchange_cb};

static int mtu_exchange(struct bt_conn *conn)
{
	int err;

	LOG_INF("Current MTU = %" PRIu16, bt_gatt_get_mtu(conn));

	LOG_INF("Exchange MTU...");
	err = bt_gatt_exchange_mtu(conn, &mtu_exchange_params);
	if (err) {
		LOG_INF("MTU exchange failed (err %d)", err);
	}

	return err;
}

void mtu_updated(struct bt_conn *conn, uint16_t tx, uint16_t rx)
{
	LOG_INF("Updated MTU: TX: %" PRIu16 " RX: %" PRIu16 " bytes", tx, rx);
}

static struct bt_gatt_cb gatt_callbacks = {
	.att_mtu_updated = mtu_updated,
};

static void check_link_ready(void)
{
	if (link_state_flags &
	    (PHY_UPDATE_PENDING | CONN_PARAM_UPDATE_PENDING | DATA_LEN_UPDATE_PENDING)) {
		return;
	}

	link_state_flags &= ~LINK_CONFIG_UPDATE_PENDING;

	/* link configuration update is done, connect the service */
	LOG_INF("Link ready, connecting TPUT service...");
	atm_tput_service_connect(atm_bt_ctx.default_conn, tput_service_ready_cb);
}

static void connected_cb(struct bt_conn *conn, uint8_t conn_err)
{
	int err = 0;
	atm_bt_tput_context *ctx = &atm_bt_ctx;

	if (conn_err) {
		LOG_ERR("Connection failed (err %" PRIu8 ")", conn_err);
		bt_conn_unref(ctx->default_conn);
		atm_bt_ctx.default_conn = NULL;
		return;
	}

	LOG_INF("Connected");

	ctx->default_conn = bt_conn_ref(conn);
	if (!ctx->default_conn) {
		LOG_ERR("Failed to reference connection");
		return;
	}
	ctx->connected = true;

	(void)mtu_exchange(conn);

	if (conn != ctx->default_conn) {
		LOG_INF("Connection is not the default.");
		return;
	}

	struct bt_conn_info info;
	err = bt_conn_get_info(conn, &info);
	if (err) {
		LOG_ERR("bt_conn_get_info() returned %d", err);
		return;
	}

	uint32_t interval_ms_x100 = info.le.interval * INTERVAL_UNIT_TO_MS_X100;
	uint16_t timeout_ms = info.le.timeout * TIMEOUT_UNIT_TO_MS;

	LOG_INF("Current conn params: interval %d.%02d ms, latency %d intervals, timeout %d ms",
		interval_ms_x100 / 100, interval_ms_x100 % 100, info.le.latency, timeout_ms);
}

static void disconnected_cb(struct bt_conn *conn, uint8_t reason)
{
	LOG_INF("Disconnected (reason %" PRIu8 ")", reason);

	if (atm_bt_ctx.default_conn) {
		bt_conn_unref(atm_bt_ctx.default_conn);
		atm_bt_ctx.default_conn = NULL;
	}
	atm_bt_ctx.connected = false;
	scan_start();
}

static void le_phy_updated_cb(struct bt_conn *conn, struct bt_conn_le_phy_info *param)
{
	LOG_INF("LE PHY updated: TX PHY %" PRIu8 ", RX PHY %" PRIu8, param->tx_phy, param->rx_phy);

	if (link_state_flags & LINK_CONFIG_UPDATE_PENDING) {
		link_state_flags &= ~PHY_UPDATE_PENDING;
		check_link_ready();
	}
}

static void le_data_len_updated_cb(struct bt_conn *conn, struct bt_conn_le_data_len_info *info)
{
	LOG_INF("LE Data Length updated: TX [octets %" PRIu16 ", time %" PRIu16
		"] RX [octets %" PRIu16 ", time %" PRIu16 "]",
		info->tx_max_len, info->tx_max_time, info->rx_max_len, info->rx_max_time);

	if (link_state_flags & LINK_CONFIG_UPDATE_PENDING) {
		link_state_flags &= ~DATA_LEN_UPDATE_PENDING;
		check_link_ready();
	}
}

static void le_param_updated_cb(struct bt_conn *conn, uint16_t interval, uint16_t latency,
				uint16_t timeout)
{
	uint32_t interval_ms_x100 = interval * INTERVAL_UNIT_TO_MS_X100;
	uint16_t timeout_ms = timeout * 10;

	LOG_INF("Conn params updated: interval %" PRIu32 ".%02" PRIu32 " ms, latency %" PRIu16
		" intervals, timeout %" PRIu16 " ms",
		interval_ms_x100 / 100, interval_ms_x100 % 100, latency, timeout_ms);

	if (link_state_flags & LINK_CONFIG_UPDATE_PENDING) {
		link_state_flags &= ~CONN_PARAM_UPDATE_PENDING;
		check_link_ready();
	}
}

static struct bt_conn_cb conn_callbacks = {
	.connected = connected_cb,
	.disconnected = disconnected_cb,
	.le_phy_updated = le_phy_updated_cb,
	.le_data_len_updated = le_data_len_updated_cb,
	.le_param_updated = le_param_updated_cb,
};

struct adv_info {
	const bt_addr_le_t *addr;
	int8_t rssi;
};

static bool tputp_target_found(struct bt_data *data, void *user_data)
{
	if (data->type != BT_DATA_NAME_COMPLETE) {
		return true;
	}

	struct adv_info *info = user_data;
	const bt_addr_le_t *addr = info->addr;
	int8_t rssi = info->rssi;

	char devid[BT_ADDR_LE_STR_LEN];
	bt_addr_le_to_str(addr, devid, sizeof(devid));

	char devname[FILTER_DEVICE_NAME_LEN + 1] = {0};

	if (data->data_len < FILTER_DEVICE_NAME_LEN) {
		return false;
	}

	memcpy(devname, data->data, FILTER_DEVICE_NAME_LEN);
	if (memcmp(FILTER_DEVICE_NAME, devname, FILTER_DEVICE_NAME_LEN)) {
		return false;
	}

	LOG_INF("Addr: %s, Name: %s, RSSI: %" PRId8 ", Type: %" PRIu8 ", Len: %" PRIu8, devid,
		devname, rssi, data->type, data->data_len);

	int err = bt_le_scan_stop();
	if (err) {
		LOG_ERR("Stop LE scan failed (err %d)", err);
		return false;
	}

	err = bt_conn_le_create(addr, BT_CONN_LE_CREATE_CONN, BT_LE_CONN_PARAM_DEFAULT,
				&atm_bt_ctx.default_conn);
	if (err) {
		LOG_ERR("Create connection failed (err %d)", err);
		bt_le_scan_start(BT_LE_SCAN_ACTIVE, device_found);
	}

	return false;
}

static void device_found(const bt_addr_le_t *addr, int8_t rssi, uint8_t adv_type,
			 struct net_buf_simple *buf)
{
	char addr_str[BT_ADDR_LE_STR_LEN];
	atm_bt_tput_context *ctx = &atm_bt_ctx;

	if (adv_type != BT_GAP_ADV_TYPE_ADV_IND && adv_type != BT_GAP_ADV_TYPE_ADV_DIRECT_IND) {
		return;
	}

	bt_addr_le_to_str(addr, addr_str, sizeof(addr_str));

	if (ctx->use_bd_addr_filter && bt_addr_le_cmp(addr, &ctx->target_bd_addr) != 0) {
		LOG_INF("Address not match: got %s", addr_str);
		return;
	}

	/* The threshold can be configured from Kconfig (CONFIG_ATM_BT_RSSI_THRESHOLD) */
	if (rssi < CONFIG_ATM_BT_RSSI_THRESHOLD) {
		LOG_INF("Rejected %s: RSSI %" PRId8 " below threshold", addr_str, rssi);
		return;
	}

	struct adv_info info = {
		.addr = addr,
		.rssi = rssi,
	};

	bt_data_parse(buf, tputp_target_found, &info);
}

static void scan_start(void)
{
	int err;

	err = bt_le_scan_start(BT_LE_SCAN_ACTIVE, device_found);
	if (err) {
		LOG_ERR("Scanning failed to start (err %d)", err);
		return;
	}

	LOG_INF("Scanning successfully started");
}

static void set_configurations(void)
{
	int err = 0;
	atm_bt_tput_context *ctx = &atm_bt_ctx;

	/* Central starts PHY update; both devices will negotiate and apply the selected mode. */
	if (ctx->phy_mode_configured) {
		struct bt_conn_le_phy_param update_phy = {0};

		switch (ctx->user_phy_mode) {
		case ATM_BT_1M_PHY:
			err = bt_conn_le_phy_update(ctx->default_conn, BT_CONN_LE_PHY_PARAM_1M);
			break;

		case ATM_BT_2M_PHY:
			err = bt_conn_le_phy_update(ctx->default_conn, BT_CONN_LE_PHY_PARAM_2M);
			break;

		case ATM_BT_CODED_S2_PHY:
			update_phy.pref_rx_phy = BT_GAP_LE_PHY_CODED;
			update_phy.pref_tx_phy = BT_GAP_LE_PHY_CODED;
			update_phy.options = BT_CONN_LE_PHY_OPT_CODED_S2;
			err = bt_conn_le_phy_update(ctx->default_conn, &update_phy);
			break;

		case ATM_BT_CODED_S8_PHY:
			update_phy.pref_rx_phy = BT_GAP_LE_PHY_CODED;
			update_phy.pref_tx_phy = BT_GAP_LE_PHY_CODED;
			update_phy.options = BT_CONN_LE_PHY_OPT_CODED_S8;
			err = bt_conn_le_phy_update(ctx->default_conn, &update_phy);
			break;

		default:
			LOG_WRN("Unknown PHY mode configured");
			err = -EINVAL;
		}

		if (err) {
			LOG_ERR("PHY update failed: %d", err);
			return;
		}

		ctx->phy_mode_configured = false;
		link_state_flags |= PHY_UPDATE_PENDING;
	}

	if (ctx->conn_interval_configured) {
		err = bt_conn_le_param_update(ctx->default_conn, &ctx->user_conn_params);
		if (err) {
			LOG_ERR("Update connection failed (err %d)", err);
			return;
		}

		ctx->conn_interval_configured = false;
		link_state_flags |= CONN_PARAM_UPDATE_PENDING;
	}

	if (ctx->data_length_configured) {
		err = bt_conn_le_data_len_update(ctx->default_conn, &ctx->data_len_param);
		if (err) {
			LOG_ERR("Data length update failed: %d", err);
			return;
		} else {
			LOG_INF("Data length update initiated: %" PRIu16 " octets / %" PRIu16 " us",
				ctx->data_len_param.tx_max_len, ctx->data_len_param.tx_max_time);
		}

		ctx->data_length_configured = false;
		link_state_flags |= DATA_LEN_UPDATE_PENDING;
	}

	if (link_state_flags) {
		link_state_flags |= LINK_CONFIG_UPDATE_PENDING;
	}
}

#if defined(CONFIG_SHELL)
static int start_tput_test(const struct shell *shell, size_t argc, char **argv)
{
	if (!atm_bt_ctx.default_conn) {
		LOG_ERR("No device connected");
		return 0;
	}

	if (atm_bt_ctx.params_configured) {
		set_configurations();
	}

	k_sleep(K_MSEC(1000));

	k_work_submit_to_queue(&atm_tput_work_q, &tput_test_start_work);

	return 0;
}

static int set_ack_policy(const struct shell *shell, size_t argc, char **argv)
{
	if (argc < 1) {
		shell_print(shell, "Usage: start_test <ack|no_ack>");
		return -EINVAL;
	}

	if (strcmp(argv[0], "on") == 0) {
		use_ack_mode = true;
		shell_print(shell, "Run test in ACK mode (with indications/write-with-response)");
	} else if (strcmp(argv[0], "off") == 0) {
		use_ack_mode = false;
		shell_print(shell, "Run test in NO-ACK mode (with notify/write-without-response)");
	} else {
		shell_print(shell, "Invalid argument. Use 'on' or 'off'");
		return -EINVAL;
	}

	return 0;
}

static int cmd_set_phy(const struct shell *shell, size_t argc, char **argv)
{
	if (argc < 1) {
		shell_error(shell, "PHY option missing (1M, 2M, CODED)");
		return -EINVAL;
	}

	const char *user_phy = argv[0];

	if (strcmp(user_phy, "1M") == 0) {
		atm_bt_ctx.user_phy_mode = ATM_BT_1M_PHY;
	} else if (strcmp(user_phy, "2M") == 0) {
		atm_bt_ctx.user_phy_mode = ATM_BT_2M_PHY;
	} else if (strcmp(user_phy, "CODED_S2") == 0) {
		atm_bt_ctx.user_phy_mode = ATM_BT_CODED_S2_PHY;
	} else if (strcmp(user_phy, "CODED_S8") == 0) {
		atm_bt_ctx.user_phy_mode = ATM_BT_CODED_S8_PHY;
	} else {
		shell_error(shell, "Unknown PHY option: %s", user_phy);
		return -EINVAL;
	}

	atm_bt_ctx.params_configured = true;
	atm_bt_ctx.phy_mode_configured = true;

	shell_print(shell, "PHY set to %s.", user_phy);
	return 0;
}

static int set_conn_interval(const struct shell *shell, size_t argc, char **argv)
{
	if (argc != 2) {
		shell_error(shell, "Usage: set_conn_interval <interval> (in 1.25ms units)");
		return -EINVAL;
	}

	uint32_t interval = (uint16_t)atoi(argv[1]);

	if (interval < MIN_CONN_INTERVAL || interval > MAX_CONN_INTERVAL) {
		shell_error(shell, "Interval out of range (%d to %d units)", MIN_CONN_INTERVAL,
			    MAX_CONN_INTERVAL);
		return -EINVAL;
	}

	atm_bt_ctx.user_conn_params.interval_min = interval;
	atm_bt_ctx.user_conn_params.interval_max = interval;

	/*
	 * Calculate supervision timeout based on connection interval
	 * BLE spec requires: timeout > (1 + connSlaveLatency) * connInterval * 2
	 * Where
	 *   - timeout = timeout_cs * 10ms
	 *   - connInterval = interval_max * 1.25ms
	 *   - connSlaveLatency = unitless number of events
	 * Which can be simplified to
	 *   - timeout_cs * 10 ms > (1 + latency) * interval_max * 1.25 ms * 2
	 *   - timeout_cs * (10 ms / 2.5 ms) > (1 + latency) * interval_max
	 *   - timeout_cs * 4 > (1 + latency) * interval_max
	 * Add some margin and ensure minimum timeout of 100 (1 second)
	 */
	uint16_t min_timeout_cs =
		DIV_ROUND_UP((1 + atm_bt_ctx.user_conn_params.latency) * interval, 4) + 1;
	min_timeout_cs = CLAMP(min_timeout_cs, 100, 3200);

	atm_bt_ctx.user_conn_params.timeout = min_timeout_cs;

	atm_bt_ctx.params_configured = true;
	atm_bt_ctx.conn_interval_configured = true;

	shell_print(shell, "Conn interval set to %" PRIu16 " units (%" PRIu16 ".%02" PRIu16 " ms)",
		    interval, interval * INTERVAL_UNIT_TO_MS_X100 / 100,
		    interval * INTERVAL_UNIT_TO_MS_X100 % 100);
	shell_print(shell, "Supervision timeout adjusted to %" PRIu16 " units (%" PRIu16 " ms)",
		    min_timeout_cs, min_timeout_cs * 10);
	return 0;
}

static int set_payload_size(const struct shell *shell, size_t argc, char **argv)
{
	if (argc != 2) {
		shell_error(shell, "Usage: set_payload_size <size> (in bytes, 1-244)");
		return -EINVAL;
	}

	uint32_t payload_size = (uint32_t)atoi(argv[1]);

	if (payload_size < 1 || payload_size > 244) {
		shell_error(shell, "Payload size out of range (1 to 244 bytes)");
		return -EINVAL;
	}

	atm_tput_set_payload_size(payload_size);

	shell_print(shell,
		    "Payload size set to %" PRIu32 " bytes for both C2S and S2C transactions",
		    payload_size);
	return 0;
}

static int show_payload_size(const struct shell *shell, size_t argc, char **argv)
{
	uint32_t current_size = atm_tput_get_payload_size();
	shell_print(shell, "Current payload size: %" PRIu32 " bytes", current_size);
	return 0;
}

static int set_packet_count(const struct shell *shell, size_t argc, char **argv)
{
	if (argc != 2) {
		shell_error(shell, "Usage: set_packet_count <count> (1-65535)");
		return -EINVAL;
	}

	uint32_t input = (uint32_t)atoi(argv[1]);

	if (input < 1 || input > 65535) {
		shell_error(shell, "Packet count out of range (1 to 65535)");
		return -EINVAL;
	}

	uint16_t packet_count = (uint16_t)input;
	atm_tput_set_packet_count(packet_count);

	shell_print(shell, "Packet count set to %" PRIu16 " packets", packet_count);
	return 0;
}

static int show_packet_count(const struct shell *shell, size_t argc, char **argv)
{
	uint16_t current_count = atm_tput_get_packet_count();
	shell_print(shell, "Current packet count: %" PRIu16 " packets", current_count);
	return 0;
}

#ifdef CONFIG_VND_API_SET_CON_TX_POWER
static int set_tx_power(const struct shell *shell, size_t argc, char **argv)
{
	if (argc != 2) {
		shell_error(shell, "Usage: set_tx_power <power> (in dBm)");
		shell_print(shell, "Supported levels: -20, -10, -8, -4, -2, 0, 2, 4, 6, 8, 10");
		return -EINVAL;
	}

	if (!atm_bt_ctx.default_conn) {
		shell_error(shell, "No device connected");
		return -ENOTCONN;
	}

	int8_t tx_power = (int8_t)atoi(argv[1]);

	/* Use the new API that handles both central and peripheral */
	atm_tput_set_tx_power(atm_bt_ctx.default_conn, (int8_t)tx_power);

	shell_print(shell, "TX power configuration sent: %" PRId8 " dBm", tx_power);
	return 0;
}

static int show_tx_power(const struct shell *shell, size_t argc, char **argv)
{
	int8_t current_power = atm_tput_get_tx_power();
	shell_print(shell, "Current TX power: %" PRId8 " dBm", current_power);
	return 0;
}

static int show_tx_power_info(const struct shell *shell, size_t argc, char **argv)
{
	shell_print(shell, "Atmosic Vendor TX Power Control");
	shell_print(shell,
		    "Supported TX power levels: -20, -10, -8, -4, -2, 0, 2, 4, 6, 8, 10 dBm");
	shell_print(shell, "Usage: set_tx_power <power_dbm>");

	int8_t current_power = atm_tput_get_tx_power();
	shell_print(shell, "Current setting: %" PRId8 " dBm", current_power);

	if (!atm_bt_ctx.default_conn) {
		shell_print(shell, "Status: No device connected");
	} else {
		shell_print(shell, "Status: Device connected, ready to set TX power");
	}

	return 0;
}
#endif /* CONFIG_VND_API_SET_CON_TX_POWER */

static int set_test_direction(const struct shell *shell, size_t argc, char **argv)
{
	if (argc != 2) {
		shell_error(shell, "Usage: set_test_direction <c2s|s2c|both>");
		return -EINVAL;
	}

	if (strcmp(argv[1], "c2s") == 0) {
		atm_bt_ctx.test_direction = TEST_C2S_ONLY;
		shell_print(shell, "Test direction set to: C2S only");
	} else if (strcmp(argv[1], "s2c") == 0) {
		atm_bt_ctx.test_direction = TEST_S2C_ONLY;
		shell_print(shell, "Test direction set to: S2C only");
	} else if (strcmp(argv[1], "both") == 0) {
		atm_bt_ctx.test_direction = TEST_BOTH;
		shell_print(shell, "Test direction set to: Both (C2S + S2C)");
	} else {
		shell_error(shell, "Invalid direction. Use 'c2s', 's2c', or 'both'");
		return -EINVAL;
	}

	return 0;
}

static int show_test_direction(const struct shell *shell, size_t argc, char **argv)
{
	const char *direction_str;

	switch (atm_bt_ctx.test_direction) {
	case TEST_C2S_ONLY:
		direction_str = "C2S only";
		break;
	case TEST_S2C_ONLY:
		direction_str = "S2C only";
		break;
	case TEST_BOTH:
		direction_str = "Both (C2S + S2C)";
		break;
	default:
		direction_str = "Unknown";
		break;
	}

	shell_print(shell, "Current test direction: %s", direction_str);
	return 0;
}

#endif /* CONFIG_SHELL */

int main(void)
{
	int err;

	LOG_INF("Starting BLE Throughput");

	err = bt_enable(NULL);
	if (err) {
		LOG_ERR("Bluetooth init failed (err %d)", err);
		return err;
	}

	bt_conn_cb_register(&conn_callbacks);
	bt_gatt_cb_register(&gatt_callbacks);

	atm_bt_ctx.conn_interval_configured = true;
	atm_bt_ctx.phy_mode_configured = true;
	atm_bt_ctx.data_length_configured = true;

	k_work_queue_start(&atm_tput_work_q, atm_tput_stack, K_THREAD_STACK_SIZEOF(atm_tput_stack),
			   5, NULL);
	scan_start();

	return 0;
}

#if defined(CONFIG_SHELL)
SHELL_STATIC_SUBCMD_SET_CREATE(sub_phy_cmds, SHELL_CMD(1M, NULL, "Use 1 Mbps PHY", cmd_set_phy),
			       SHELL_CMD(2M, NULL, "Use 2 Mbps PHY", cmd_set_phy),
			       SHELL_CMD(CODED_S2, NULL, "Use CODED_S2 PHY", cmd_set_phy),
			       SHELL_CMD(CODED_S8, NULL, "Use CODED_S8 PHY", cmd_set_phy),
			       SHELL_SUBCMD_SET_END);

SHELL_STATIC_SUBCMD_SET_CREATE(
	set_ack_cmd,
	SHELL_CMD(on, NULL, "Run throughput test with ACK (indications)", set_ack_policy),
	SHELL_CMD(off, NULL, "Run throughput test without ACK (notifications)", set_ack_policy),
	SHELL_SUBCMD_SET_END);

SHELL_CMD_REGISTER(start_test, NULL, "Start throughput test", start_tput_test);
SHELL_CMD_REGISTER(ack, &set_ack_cmd, "Change ack policy", NULL);
SHELL_CMD_REGISTER(set_phy, &sub_phy_cmds, "Set BLE PHY: 1M or 2M", NULL);
SHELL_CMD_ARG_REGISTER(set_conn_interval, NULL,
		       "Set connection interval: 6 > (value * 1.25) < 3200", set_conn_interval, 2,
		       0);
SHELL_CMD_ARG_REGISTER(set_payload_size, NULL, "Set payload size for C2S and S2C: 1-244 bytes",
		       set_payload_size, 2, 0);
SHELL_CMD_REGISTER(show_payload_size, NULL, "Show current payload size", show_payload_size);
SHELL_CMD_ARG_REGISTER(set_packet_count, NULL, "Set number of packets to send: 1-65535",
		       set_packet_count, 2, 0);
SHELL_CMD_REGISTER(show_packet_count, NULL, "Show current packet count", show_packet_count);
SHELL_CMD_ARG_REGISTER(set_test_direction, NULL, "Set test direction: c2s, s2c, or both",
		       set_test_direction, 2, 0);
SHELL_CMD_REGISTER(show_test_direction, NULL, "Show current test direction", show_test_direction);
#ifdef CONFIG_VND_API_SET_CON_TX_POWER
SHELL_CMD_ARG_REGISTER(set_tx_power, NULL, "Set connection TX power: -20 to 10 dBm", set_tx_power,
		       2, 0);
SHELL_CMD_REGISTER(show_tx_power, NULL, "Show current TX power setting", show_tx_power);
SHELL_CMD_REGISTER(show_tx_power_info, NULL, "Show TX power information and supported levels",
		   show_tx_power_info);
#endif /* CONFIG_VND_API_SET_CON_TX_POWER */
#endif /* CONFIG_SHELL */
