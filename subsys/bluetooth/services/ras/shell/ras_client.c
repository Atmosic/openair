/**
 * @file
 * @brief Shell APIs for Bluetooth RAS Client
 *
 * Copyright (c) 2025 Atmosic
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdint.h>
#include <zephyr/types.h>
#include <zephyr/shell/shell.h>
#include <stdlib.h>
#include <zephyr/bluetooth/gatt.h>
#include <zephyr/bluetooth/bluetooth.h>
#include <zephyr/net_buf.h>

#include "ras.h"

/**
 * @brief Parse subscription type from shell argument
 *
 * @param sh Shell instance for error reporting
 * @param arg String argument to parse ("notify", "indicate", "auto")
 * @param value Pointer to store the parsed value
 *
 * @return 0 on success, -EINVAL on invalid argument
 */
static int parse_subscription_type(const struct shell *sh, const char *arg,
				   enum bt_ras_client_subscribe_type *value)
{
	if (strcmp(arg, "notify") == 0) {
		*value = BT_RAS_CLIENT_SUB_NOTIFY_ONLY;
	} else if (strcmp(arg, "indicate") == 0) {
		*value = BT_RAS_CLIENT_SUB_INDICATE_ONLY;
	} else if (strcmp(arg, "auto") == 0) {
		*value = BT_RAS_CLIENT_SUB_AUTO;
	} else {
		shell_error(sh, "Invalid type '%s'. Use: notify, indicate, or auto", arg);
		return -EINVAL;
	}
	return 0;
}

#ifdef CONFIG_BT_SHELL
#include "host/shell/bt.h"
#endif
#include "common/bt_shell_private.h"

/* Buffer for ranging data */
#define RAS_SHELL_RANGING_DATA_BUF_SIZE 768
static uint8_t ranging_data_buf[RAS_SHELL_RANGING_DATA_BUF_SIZE];
static struct net_buf_simple ranging_data_net_buf;

/* Local connection management when BT shell is not available */
#ifndef CONFIG_BT_SHELL
static struct bt_conn *ras_default_conn;

static void ras_connected(struct bt_conn *conn, uint8_t err)
{
	if (err) {
		bt_shell_error("Connection failed (err 0x%02x)", err);
		return;
	}

	if (ras_default_conn) {
		bt_conn_unref(ras_default_conn);
	}
	ras_default_conn = bt_conn_ref(conn);
	bt_shell_print("Connected, RAS client ready");
}

static void ras_disconnected(struct bt_conn *conn, uint8_t reason)
{
	if (conn == ras_default_conn) {
		bt_conn_unref(ras_default_conn);
		ras_default_conn = NULL;
		bt_shell_print("Disconnected (reason 0x%02x)", reason);
	}
}

BT_CONN_CB_DEFINE(ras_conn_callbacks) = {
	.connected = ras_connected,
	.disconnected = ras_disconnected,
};

static struct bt_conn *get_default_conn(void)
{
	return ras_default_conn;
}
#else
static struct bt_conn *get_default_conn(void)
{
	return default_conn;
}
#endif

/**
 * @brief Common helper to validate connection and parse subscription type
 *
 * @param sh Shell instance
 * @param argc Argument count
 * @param argv Argument vector
 * @param conn_out Pointer to store connection
 * @param value_out Pointer to store parsed subscription type
 *
 * @return 0 on success, negative error code on failure
 */
static int validate_conn_and_parse_sub_type(const struct shell *sh, size_t argc, char **argv,
					    struct bt_conn **conn_out,
					    enum bt_ras_client_subscribe_type *value_out)
{
	struct bt_conn *conn = get_default_conn();
	enum bt_ras_client_subscribe_type value = BT_RAS_CLIENT_SUB_AUTO;

	if (!conn) {
		shell_error(sh, "Not connected to any device");
		return -ENOTCONN;
	}

	/* Optional parameter for subscription type */
	if (argc > 1) {
		int err = parse_subscription_type(sh, argv[1], &value);
		if (err) {
			return err;
		}
	}

	*conn_out = conn;
	*value_out = value;
	return 0;
}

/**
 * @brief Common helper to validate connection for operations
 *
 * @param sh Shell instance
 * @param conn_out Pointer to store connection
 *
 * @return 0 on success, -ENOTCONN if not connected
 */
static int validate_connection(const struct shell *sh, struct bt_conn **conn_out)
{
	struct bt_conn *conn = get_default_conn();

	if (!conn) {
		shell_error(sh, "Not connected to any device");
		return -ENOTCONN;
	}

	*conn_out = conn;
	return 0;
}

static void ras_discover_cb(const struct bt_conn *conn, int err)
{
	if (err) {
		bt_shell_error("Failed to discover RAS err: %d\n", err);
	} else {
		bt_shell_print("RAS discover success\n");
	}
}

static void ras_ranging_data_overwritten_cb(struct bt_conn *conn, uint16_t ranging_counter)
{
	bt_shell_print("Ranging data overwritten: counter=%u\n", ranging_counter);
}

static void ras_get_ranging_data_cmpl_cb(struct bt_conn *conn, uint16_t ranging_counter, int err)
{
	if (err) {
		bt_shell_error("Get ranging data failed: counter=%u, err=%d\n", ranging_counter,
			       err);
	} else {
		bt_shell_print("Get ranging data success: counter=%u, data_len=%u\n",
			       ranging_counter, ranging_data_net_buf.len);

		/* Parse the ranging data */
		uint16_t parsed_counter;
		int parse_err =
			bt_ras_client_ranging_data_parse(&ranging_data_net_buf, &parsed_counter);
		if (parse_err == 0) {
			bt_shell_print("Parsed ranging counter: %u, remaining data: %u bytes\n",
				       parsed_counter, ranging_data_net_buf.len);
		} else {
			bt_shell_error("Failed to parse ranging data: %d\n", parse_err);
		}
	}
	net_buf_simple_reset(&ranging_data_net_buf);
}

static void ras_ranging_data_ready_cb(struct bt_conn *conn, uint16_t ranging_counter, int err)
{
	if (err) {
		bt_shell_error("Ranging data ready error: %d\n", err);
	} else {
		bt_shell_print("Ranging data ready: counter=%u\n", ranging_counter);
		/* Reset the buffer before getting new data */
		net_buf_simple_reset(&ranging_data_net_buf);

		int get_err = bt_ras_client_cp_get_ranging_data(
			conn, ranging_counter, &ranging_data_net_buf, ras_get_ranging_data_cmpl_cb);
		if (get_err) {
			bt_shell_error("RAS get ranging data failed: %d\n", get_err);
		} else {
			bt_shell_print("RAS get ranging data started for counter: %u \n",
				       ranging_counter);
		}
	}
}

#ifdef CONFIG_RAS_CLIENT_REAL_TIME_RD
static void ras_get_realtime_ranging_data_cmpl_cb(struct bt_conn *conn, int err)
{
	if (err) {
		bt_shell_error("Get realtime ranging data failed: err=%d\n", err);
	} else {
		bt_shell_print("Get realtime ranging data success: data_len=%u\n",
			       ranging_data_net_buf.len);

		/* Parse the ranging data */
		uint16_t parsed_counter;
		int parse_err =
			bt_ras_client_ranging_data_parse(&ranging_data_net_buf, &parsed_counter);
		if (parse_err == 0) {
			bt_shell_print("Parsed ranging counter: %u, remaining data: %u bytes\n",
				       parsed_counter, ranging_data_net_buf.len);
		} else {
			bt_shell_error("Failed to parse ranging data: %d\n", parse_err);
		}
	}

	net_buf_simple_reset(&ranging_data_net_buf);
}
#endif

static struct bt_ras_client_cb ras_client_callbacks = {
	.discovery_done = ras_discover_cb,
};

static int cmd_ras_client_init(const struct shell *sh, size_t argc, char **argv)
{
	/* Initialize the ranging data buffer */
	net_buf_simple_init_with_data(&ranging_data_net_buf, ranging_data_buf,
				      sizeof(ranging_data_buf));
	net_buf_simple_reset(&ranging_data_net_buf);

	int err = bt_ras_client_cb_register(&ras_client_callbacks);
	if (err) {
		shell_print(sh, "RAS client register failed: %d", err);
	} else {
		shell_print(sh, "RAS client initialized");
	}

	return err;
}

static int cmd_ras_client_discover(const struct shell *sh, size_t argc, char **argv)
{
	struct bt_conn *conn;

	int err = validate_connection(sh, &conn);
	if (err) {
		return err;
	}

	err = bt_ras_client_discover(conn);
	if (err) {
		shell_print(sh, "RAS discover failed: %d", err);
	}

	return err;
}

static int cmd_ras_client_subscribe_rd_ready(const struct shell *sh, size_t argc, char **argv)
{
	struct bt_conn *conn;
	enum bt_ras_client_subscribe_type value;

	int err = validate_conn_and_parse_sub_type(sh, argc, argv, &conn, &value);
	if (err) {
		return err;
	}

	err = bt_ras_client_ranging_data_ready_subscribe(conn, ras_ranging_data_ready_cb, value);
	if (err) {
		shell_print(sh, "RAS ranging data ready subscribe failed: %d", err);
	} else {
		shell_print(sh, "RAS ranging data ready subscribed");
	}

	return err;
}

static int cmd_ras_client_subscribe_rd_overwritten(const struct shell *sh, size_t argc, char **argv)
{
	struct bt_conn *conn;
	enum bt_ras_client_subscribe_type value;

	int err = validate_conn_and_parse_sub_type(sh, argc, argv, &conn, &value);
	if (err) {
		return err;
	}

	err = bt_ras_client_ranging_data_overwritten_subscribe(
		conn, ras_ranging_data_overwritten_cb, value);
	if (err) {
		shell_print(sh, "RAS ranging data overwritten subscribe failed: %d", err);
	} else {
		shell_print(sh, "RAS ranging data overwritten subscribed");
	}

	return err;
}

static int cmd_ras_client_unsubscribe_rd_ready(const struct shell *sh, size_t argc, char **argv)
{
	struct bt_conn *conn;

	int err = validate_connection(sh, &conn);
	if (err) {
		return err;
	}

	err = bt_ras_client_ranging_data_ready_unsubscribe(conn);
	if (err) {
		shell_print(sh, "RAS ranging data ready unsubscribe failed: %d", err);
	} else {
		shell_print(sh, "RAS ranging data ready unsubscribed");
	}

	return err;
}

static int cmd_ras_client_unsubscribe_rd_overwritten(const struct shell *sh, size_t argc,
						     char **argv)
{
	struct bt_conn *conn;

	int err = validate_connection(sh, &conn);
	if (err) {
		return err;
	}

	err = bt_ras_client_ranging_data_overwritten_unsubscribe(conn);
	if (err) {
		shell_print(sh, "RAS ranging data overwritten unsubscribe failed: %d", err);
	} else {
		shell_print(sh, "RAS ranging data overwritten unsubscribed");
	}

	return err;
}

static int cmd_ras_client_subscribe_ondemand(const struct shell *sh, size_t argc, char **argv)
{
	struct bt_conn *conn;
	enum bt_ras_client_subscribe_type value;

	int err = validate_conn_and_parse_sub_type(sh, argc, argv, &conn, &value);
	if (err) {
		return err;
	}

	err = bt_ras_client_on_demand_ranging_data_subscribe(conn, value);
	if (err) {
		shell_print(sh, "RAS on-demand ranging data subscribe failed: %d", err);
	} else {
		shell_print(sh, "RAS on-demand ranging data subscribed");
	}

	return err;
}

static int cmd_ras_client_unsubscribe_ondemand(const struct shell *sh, size_t argc, char **argv)
{
	struct bt_conn *conn;

	int err = validate_connection(sh, &conn);
	if (err) {
		return err;
	}

	err = bt_ras_client_on_demand_ranging_data_unsubscribe(conn);
	if (err) {
		shell_print(sh, "RAS on-demand ranging data unsubscribe failed: %d", err);
	} else {
		shell_print(sh, "RAS on-demand ranging data unsubscribed");
	}

	return err;
}

static int cmd_ras_client_subscribe_cp(const struct shell *sh, size_t argc, char **argv)
{
	struct bt_conn *conn;
	enum bt_ras_client_subscribe_type value;

	int err = validate_conn_and_parse_sub_type(sh, argc, argv, &conn, &value);
	if (err) {
		return err;
	}

	err = bt_ras_client_cp_subscribe(conn, value);
	if (err) {
		shell_print(sh, "RAS control point subscribe failed: %d", err);
	} else {
		shell_print(sh, "RAS control point subscribed");
	}

	return err;
}

static int cmd_ras_client_get_ranging_data(const struct shell *sh, size_t argc, char **argv)
{
	struct bt_conn *conn;
	uint16_t ranging_counter;

	int err = validate_connection(sh, &conn);
	if (err) {
		return err;
	}

	if (argc < 2) {
		shell_error(sh, "Usage: get_ranging_data <ranging_counter>");
		return -EINVAL;
	}

	ranging_counter = (uint16_t)strtoul(argv[1], NULL, 0);

	/* Reset the buffer before getting new data */
	net_buf_simple_reset(&ranging_data_net_buf);

	err = bt_ras_client_cp_get_ranging_data(conn, ranging_counter, &ranging_data_net_buf,
						ras_get_ranging_data_cmpl_cb);
	if (err) {
		shell_print(sh, "RAS get ranging data failed: %d", err);
	} else {
		shell_print(sh, "RAS get ranging data started for counter: %u", ranging_counter);
	}

	return err;
}

#ifdef CONFIG_RAS_CLIENT_REAL_TIME_RD
static int cmd_ras_client_subscribe_realtime(const struct shell *sh, size_t argc, char **argv)
{
	struct bt_conn *conn;
	enum bt_ras_client_subscribe_type value;

	int err = validate_conn_and_parse_sub_type(sh, argc, argv, &conn, &value);
	if (err) {
		return err;
	}

	/* Reset the buffer before getting new data */
	net_buf_simple_reset(&ranging_data_net_buf);

	err = bt_ras_client_realtime_ranging_data_subscribe(
		conn, &ranging_data_net_buf, ras_get_realtime_ranging_data_cmpl_cb, value);
	if (err) {
		shell_print(sh, "RAS realtime ranging data subscribe failed: %d", err);
	} else {
		shell_print(sh, "RAS realtime ranging data subscribed");
	}

	return err;
}

static int cmd_ras_client_unsubscribe_realtime(const struct shell *sh, size_t argc, char **argv)
{
	struct bt_conn *conn;

	int err = validate_connection(sh, &conn);
	if (err) {
		return err;
	}

	err = bt_ras_client_realtime_ranging_data_unsubscribe(conn);
	if (err) {
		shell_print(sh, "RAS realtime ranging data unsubscribe failed: %d", err);
	} else {
		shell_print(sh, "RAS realtime ranging data unsubscribed");
	}

	return err;
}
#endif

static int cmd_ras_client_status(const struct shell *sh, size_t argc, char **argv)
{
	struct bt_conn *conn = get_default_conn();

	if (conn) {
		char addr[BT_ADDR_LE_STR_LEN];
		struct bt_conn_info info;

		if (bt_conn_get_info(conn, &info) == 0) {
			bt_addr_le_to_str(info.le.dst, addr, sizeof(addr));
			shell_print(sh, "Connected to: %s", addr);
		} else {
			shell_print(sh, "Connected (address unavailable)");
		}
	} else {
		shell_print(sh, "Not connected");
	}

	return 0;
}

static int cmd_ras_client(const struct shell *sh, size_t argc, char **argv)
{
	if (argc == 1) {
		shell_help(sh);
		return SHELL_CMD_HELP_PRINTED;
	}

	shell_error(sh, "%s unknown parameter: %s", argv[0], argv[1]);
	return -ENOEXEC;
}

SHELL_STATIC_SUBCMD_SET_CREATE(
	ras_cli_cmds,
	SHELL_CMD_ARG(init, NULL, "Initialize the client and register callbacks",
		      cmd_ras_client_init, 1, 0),
	SHELL_CMD_ARG(status, NULL, "Show connection status", cmd_ras_client_status, 1, 0),
	SHELL_CMD_ARG(discover, NULL, "Discover RAS service", cmd_ras_client_discover, 1, 0),
	SHELL_CMD_ARG(subs_rd_ready, NULL,
		      "Subscribe to ranging data ready notifications [notify|indicate|auto]",
		      cmd_ras_client_subscribe_rd_ready, 1, 1),
	SHELL_CMD_ARG(unsubs_rd_ready, NULL, "Unsubscribe from ranging data ready notifications",
		      cmd_ras_client_unsubscribe_rd_ready, 1, 0),
	SHELL_CMD_ARG(subs_rd_ovr, NULL,
		      "Subscribe to ranging data overwritten notifications [notify|indicate|auto]",
		      cmd_ras_client_subscribe_rd_overwritten, 1, 1),
	SHELL_CMD_ARG(unsubs_rd_ovr, NULL,
		      "Unsubscribe from ranging data overwritten notifications",
		      cmd_ras_client_unsubscribe_rd_overwritten, 1, 0),
	SHELL_CMD_ARG(subs_ondemand, NULL,
		      "Subscribe to on-demand ranging data [notify|indicate|auto]",
		      cmd_ras_client_subscribe_ondemand, 1, 1),
	SHELL_CMD_ARG(unsubs_ondemand, NULL, "Unsubscribe from on-demand ranging data",
		      cmd_ras_client_unsubscribe_ondemand, 1, 0),
	SHELL_CMD_ARG(subs_cp, NULL,
		      "Subscribe to control point notifications [notify|indicate|auto]",
		      cmd_ras_client_subscribe_cp, 1, 1),
	SHELL_CMD_ARG(get_rd, NULL, "Get ranging data <ranging_counter>",
		      cmd_ras_client_get_ranging_data, 2, 0),
#ifdef CONFIG_RAS_CLIENT_REAL_TIME_RD
	SHELL_CMD_ARG(subs_realtime, NULL,
		      "Subscribe to realtime ranging data [notify|indicate|auto]",
		      cmd_ras_client_subscribe_realtime, 1, 1),
	SHELL_CMD_ARG(unsubs_realtime, NULL, "Unsubscribe from realtime ranging data",
		      cmd_ras_client_unsubscribe_realtime, 1, 0),
#endif
	SHELL_SUBCMD_SET_END);

SHELL_CMD_ARG_REGISTER(ras_client, &ras_cli_cmds, "Bluetooth RAS client shell commands",
		       cmd_ras_client, 1, 0);
