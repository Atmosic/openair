/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include "rc_mmi.h"
#include "rc_gap.h"
#include "rc_hids.h"
#ifdef CONFIG_RC_VOICE
#include "atvv.h"
#endif

#include <stddef.h>
#include <errno.h>
#include <zephyr/sys/util.h>
#include <zephyr/kernel.h>

#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <zephyr/drivers/retained_mem.h>
#include <zephyr/logging/log.h>
#include <zephyr/settings/settings.h>

#include <zephyr/bluetooth/bluetooth.h>
#include <zephyr/bluetooth/hci.h>
#include <zephyr/bluetooth/conn.h>
#include <zephyr/bluetooth/uuid.h>
#include <zephyr/bluetooth/gatt.h>
#include <zephyr/bluetooth/addr.h>

#include <zephyr/smf.h>
#include "reset.h"
#ifdef CONFIG_ATM_VENDOR_API
#include "atm_vendor_api.h"
#endif

LOG_MODULE_REGISTER(rc_gap, CONFIG_HID_REMOTE_LOG_LEVEL);

/* Manufacturer-specific AD payload for RC advertising */
#define RC_HID_ADV_DAT_MANU      0x24, 0x0A, 0x01, 0x05, 0x00
#define RC_ADV_TIMEOUT_UNITS(ms) DIV_ROUND_UP(ms, 10)

#ifdef CONFIG_BT_SMP_SC_ONLY
#define BT_SECURITY_LVL BT_SECURITY_L4
#else
#define BT_SECURITY_LVL BT_SECURITY_L2
#endif

#define ADDR_INF(str1, addr, str2, ...)                                                            \
	do {                                                                                       \
		char c_addr[BT_ADDR_LE_STR_LEN];                                                   \
		bt_addr_le_to_str(addr, c_addr, sizeof(c_addr));                                   \
		LOG_INF(str1 "%s" str2, c_addr, ##__VA_ARGS__);                                    \
	} while (0)

enum {
	GAP_S_INIT,
	GAP_S_IDLE,
	GAP_S_ADV0ING,
	GAP_S_ADV1ING,
	GAP_S_ADV_STOPPING,
	GAP_S_CONNECTED,
	GAP_S_RFTEST,

	GAP_S_NUM,
};

typedef enum {
	GAP_OP_INITING,
	GAP_OP_INITED,
	GAP_OP_ADV0ING,
	GAP_OP_ADV1ING,
	GAP_OP_ADV_STOP,
	GAP_OP_ADV_STOPPING,
	GAP_OP_CONNECTED,
	GAP_OP_DISCONNECTED,
} rc_gap_op_t;

static bool is_pairing = true;
static bool pairing_forced;
static uint32_t active_id;

#define RC_RECONNECT_ADV_COUNT CONFIG_BT_MAX_PAIRED

/* Keep one advertising set available for undirected pairing in addition to
 * one directed reconnect set per stored bond. */
BUILD_ASSERT(CONFIG_BT_EXT_ADV_MAX_ADV_SET >= (CONFIG_BT_MAX_PAIRED + 1),
	     "CONFIG_BT_EXT_ADV_MAX_ADV_SET must cover reconnect and pairing sets");

enum rc_adv_id {
	RC_ADV_RECONNECT_BASE,
	RC_ADV_PAIRING = RC_ADV_RECONNECT_BASE + RC_RECONNECT_ADV_COUNT,
	RC_ADV_COUNT,
};

#define PAIRING_MARKER_MAGIC  0x50414952U /* 'PAIR' */
#define PAIRING_MARKER_OFFSET 0
static const struct device *const pairing_marker_dev =
	DEVICE_DT_GET(DT_NODELABEL(retained_mem_hib));
static struct bt_le_ext_adv *adv_sets[RC_ADV_COUNT];
static bool pairing_adv_active;
static bool reconnect_adv_active[RC_RECONNECT_ADV_COUNT];
static struct bt_conn *current_conn;
static struct bt_conn *connections[CONFIG_BT_MAX_CONN];
static size_t connection_count;
struct rc_reconnect_peer {
	bt_addr_le_t addr;
};

static struct rc_reconnect_peer reconnect_peers[CONFIG_BT_MAX_PAIRED];
static size_t reconnect_peer_count;

struct gap_ctx {
	struct smf_ctx ctx;
	rc_gap_op_t evt;
};

static struct gap_ctx gap_ctx;
static const struct smf_state gap_states[GAP_S_NUM];

static struct bt_data const adv_data[] = {
	BT_DATA_BYTES(BT_DATA_FLAGS, (BT_LE_AD_GENERAL | BT_LE_AD_NO_BREDR)),
	BT_DATA_BYTES(BT_DATA_UUID16_ALL, BT_UUID_16_ENCODE(BT_UUID_HIDS_VAL)),
	BT_DATA_BYTES(BT_DATA_GAP_APPEARANCE, BT_UUID_16_ENCODE(CONFIG_BT_DEVICE_APPEARANCE)),
	BT_DATA_BYTES(BT_DATA_MANUFACTURER_DATA, RC_HID_ADV_DAT_MANU),
};

static struct bt_data const pairing_scan_data[] = {
	BT_DATA_BYTES(BT_DATA_UUID16_ALL, BT_UUID_16_ENCODE(BT_UUID_HIDS_VAL)),
	BT_DATA_BYTES(BT_DATA_GAP_APPEARANCE, BT_UUID_16_ENCODE(CONFIG_BT_DEVICE_APPEARANCE)),
	BT_DATA(BT_DATA_NAME_COMPLETE, CONFIG_BT_DEVICE_NAME, sizeof(CONFIG_BT_DEVICE_NAME) - 1),
};

static struct bt_data const reconn_scan_data[] = {
	BT_DATA(BT_DATA_NAME_COMPLETE, CONFIG_BT_DEVICE_NAME, sizeof(CONFIG_BT_DEVICE_NAME) - 1),
};

static void rc_gap_transition(rc_gap_op_t op)
{
	gap_ctx.evt = op;
	smf_run_state(SMF_CTX(&gap_ctx));
}

static void check_is_pairing(struct bt_bond_info const *info, void *data)
{
	ARG_UNUSED(data);

	is_pairing = false;
	if (reconnect_peer_count < ARRAY_SIZE(reconnect_peers)) {
		reconnect_peers[reconnect_peer_count].addr = info->addr;
		LOG_INF("Reconnect bond[%u] local id=%u", (unsigned int)reconnect_peer_count,
			(unsigned int)active_id);
		ADDR_INF("Reconnect bond target ", &info->addr, "\n");
		reconnect_peer_count++;
	}
}

static void rc_gap_reset_bond_information(void)
{
	is_pairing = true;
	reconnect_peer_count = 0;
}

static void rc_gap_update_bond_information(void)
{
	rc_gap_reset_bond_information();
	if (pairing_forced) {
		return;
	}
	bt_foreach_bond(active_id, check_is_pairing, NULL);
}

static void rc_pairing_marker_init(void)
{
	uint32_t marker = 0;

	if (!device_is_ready(pairing_marker_dev)) {
		LOG_WRN("Pairing marker device is not ready");
		return;
	}

	if (is_boot_unretained()) {
		int err = retained_mem_write(pairing_marker_dev, PAIRING_MARKER_OFFSET,
					     (const uint8_t *)&marker, sizeof(marker));

		if (err) {
			LOG_WRN("Failed to clear pairing marker (err %d)", err);
		}
		return;
	}

	if (!retained_mem_read(pairing_marker_dev, PAIRING_MARKER_OFFSET, (uint8_t *)&marker,
			       sizeof(marker)) &&
	    marker == PAIRING_MARKER_MAGIC) {
		pairing_forced = true;
		is_pairing = true;
		LOG_INF("Pairing marker restored after retained-memory wakeup");
	}
}

static int rc_reconnect_adv_index(const struct bt_le_ext_adv *adv)
{
	for (int i = 0; i < RC_RECONNECT_ADV_COUNT; i++) {
		if (adv_sets[RC_ADV_RECONNECT_BASE + i] == adv) {
			return i;
		}
	}

	return -1;
}

static bool rc_reconnect_adv_any_active(void)
{
	for (int i = 0; i < RC_RECONNECT_ADV_COUNT; i++) {
		if (reconnect_adv_active[i]) {
			return true;
		}
	}

	return false;
}

static void rc_stop_reconnect_advertising(void)
{
	for (int i = 0; i < RC_RECONNECT_ADV_COUNT; i++) {
		if (adv_sets[RC_ADV_RECONNECT_BASE + i]) {
			bt_le_ext_adv_stop(adv_sets[RC_ADV_RECONNECT_BASE + i]);
		}
		reconnect_adv_active[i] = false;
	}
}

static void rc_stop_reconnect_advertising_for_conn(const struct bt_conn *conn)
{
	struct bt_conn_info conn_info;
	const bt_addr_le_t *peer_addr;

	if (bt_conn_get_info(conn, &conn_info)) {
		return;
	}

	peer_addr = bt_conn_get_dst(conn);
	for (size_t i = 0; i < reconnect_peer_count && i < RC_RECONNECT_ADV_COUNT; i++) {
		if (conn_info.id != active_id ||
		    bt_addr_le_cmp(&reconnect_peers[i].addr, peer_addr)) {
			continue;
		}

		if (adv_sets[RC_ADV_RECONNECT_BASE + i]) {
			int err = bt_le_ext_adv_stop(adv_sets[RC_ADV_RECONNECT_BASE + i]);

			if (err && err != -EALREADY) {
				LOG_WRN("Failed to stop reconnect advertising %u (err %d)",
					(unsigned int)i, err);
			}
		}
		reconnect_adv_active[i] = false;
		break;
	}
}

struct rc_bond_match {
	const bt_addr_le_t *addr;
	bool matched;
};

static void rc_check_bond_match(const struct bt_bond_info *info, void *data)
{
	struct rc_bond_match *match = data;

	if (!bt_addr_le_cmp(&info->addr, match->addr)) {
		match->matched = true;
	}
}

static bool rc_peer_is_bonded(struct bt_conn *conn)
{
	struct bt_conn_info conn_info;
	const bt_addr_le_t *peer_addr = bt_conn_get_dst(conn);
	struct rc_bond_match match = {
		.addr = peer_addr,
	};

	if (bt_conn_get_info(conn, &conn_info)) {
		return false;
	}

	bt_foreach_bond(conn_info.id, rc_check_bond_match, &match);
	return match.matched;
}

static int rc_connection_find(struct bt_conn *conn)
{
	for (size_t i = 0; i < connection_count; i++) {
		if (connections[i] == conn) {
			return (int)i;
		}
	}

	return -1;
}

static bool rc_connection_add(struct bt_conn *conn)
{
	if (rc_connection_find(conn) >= 0) {
		current_conn = conn;
		return true;
	}

	if (connection_count >= ARRAY_SIZE(connections)) {
		return false;
	}

	connections[connection_count++] = bt_conn_ref(conn);
	current_conn = conn;
	LOG_INF("BLE connections=%u", (unsigned int)connection_count);
	return true;
}

static void rc_connection_remove(struct bt_conn *conn)
{
	int index = rc_connection_find(conn);

	if (index < 0) {
		return;
	}

	bt_conn_unref(connections[index]);
	for (size_t i = (size_t)index + 1; i < connection_count; i++) {
		connections[i - 1] = connections[i];
	}
	connection_count--;

	if (current_conn == conn) {
		current_conn = connection_count ? connections[connection_count - 1] : NULL;
	}
}

static void rc_connected(struct bt_conn *conn, uint8_t err)
{
	if (err) {
		struct bt_conn_info conn_info;

		if (!bt_conn_get_info(conn, &conn_info)) {
			LOG_INF("Connection failed: local id=%u status=%u",
				(unsigned int)conn_info.id, (unsigned int)err);
		}
		ADDR_INF("Failed to connect to ", bt_conn_get_dst(conn), " (%u)\n", err);
		return;
	}

	struct bt_conn_info conn_info;
	if (!bt_conn_get_info(conn, &conn_info)) {
		LOG_INF("Connection callback: local id=%u", (unsigned int)conn_info.id);
	}

	/* In forced pairing mode, do not let an old bonded host consume the
	 * undirected pairing advertisement before a new central can connect. */
	if (connection_count == 0 && is_pairing && rc_peer_is_bonded(conn)) {
		ADDR_INF("Rejecting bonded peer during pairing: ", bt_conn_get_dst(conn), "\n");
		bt_conn_disconnect(conn, BT_HCI_ERR_REMOTE_USER_TERM_CONN);
		return;
	}

	if (!rc_connection_add(conn)) {
		LOG_ERR("Connection limit reached");
		bt_conn_disconnect(conn, BT_HCI_ERR_CONN_LIMIT_EXCEEDED);
		return;
	}

	if (pairing_adv_active) {
		int stop_err = bt_le_ext_adv_stop(adv_sets[RC_ADV_PAIRING]);

		if (stop_err && stop_err != -EALREADY) {
			LOG_WRN("Failed to stop pairing advertising (err %d)", stop_err);
		}
		pairing_adv_active = false;
	}
	rc_stop_reconnect_advertising_for_conn(conn);

#ifdef CONFIG_VND_API_SET_CON_TX_POWER
	{
		uint16_t conn_hdl;
		if (bt_hci_get_conn_handle(conn, &conn_hdl)) {
			ADDR_INF("Get hdl", bt_conn_get_dst(conn), ":FAIL");
			return;
		}
		if (atm_vendor_set_con_tx_power(conn_hdl, TX_POWER_0_DBM)) {
			LOG_ERR("Set con tx pwr fail");
		}
	}
#endif
	ADDR_INF("Connected peer ", bt_conn_get_dst(conn), "\n");

	int error = bt_conn_set_security(conn, BT_SECURITY_LVL);
	if (error) {
		LOG_INF("Failed to set security %d\n", error);
	}

	rc_gap_transition(GAP_OP_CONNECTED);
}

static void rc_disconnected(struct bt_conn *conn, uint8_t reason)
{
	ADDR_INF("Disconnected from ", bt_conn_get_dst(conn), " (reason 0x%02x)\n", reason);

	rc_connection_remove(conn);
	LOG_INF("BLE connections=%u", (unsigned int)connection_count);
	if (connection_count) {
		LOG_INF("%u BLE connection(s) remain", (unsigned int)connection_count);
		return;
	}

#ifdef CONFIG_RC_VOICE
	atvv_reset_connection();
#endif

	rc_gap_transition(GAP_OP_DISCONNECTED);
}

#ifdef CONFIG_BT_SMP_SC_ONLY
static void rc_identity_resolved(struct bt_conn *conn, const bt_addr_le_t *rpa,
				 const bt_addr_le_t *identity)
{
	ADDR_INF("Identity resolved ", identity, "");
	ADDR_INF(" -> Identity resolved ", rpa, "\n");
}
#endif

static void rc_mtu_exchange_cb(struct bt_conn *conn, uint8_t err,
			       struct bt_gatt_exchange_params *params)
{
	if (err) {
		LOG_ERR("MTU exchange failed (err %u)", err);
	} else {
		LOG_INF("MTU exchanged: %u", bt_gatt_get_mtu(conn));
	}
#ifdef CONFIG_RC_VOICE
	int mtu_err = atvv_set_att_mtu(err ? 0 : bt_gatt_get_mtu(conn));
	if (mtu_err) {
		LOG_ERR("ATVV audio disabled: ATT MTU %u is too small", bt_gatt_get_mtu(conn));
	}
#endif
}

static struct bt_gatt_exchange_params rc_mtu_params = {
	.func = rc_mtu_exchange_cb,
};

static void rc_security_changed(struct bt_conn *conn, bt_security_t level, enum bt_security_err err)
{
	struct bt_conn_info info;
	int info_err = bt_conn_get_info(conn, &info);

	if (info_err) {
		LOG_ERR("Unable to get connection info (err %d)", info_err);
		return;
	}

	if (err) {
		ADDR_INF("Security failed: ", bt_conn_get_dst(conn), " level %u err %d\n", level,
			 err);
		bt_unpair(info.id, bt_conn_get_dst(conn));
		if (is_pairing) {
			rc_mmi_run_event(MMI_OP_PAIR_FAIL);
		}
		return;
	}

	ADDR_INF("Security changed: ", bt_conn_get_dst(conn), " level %u\n", level);

	/* Request larger ATT MTU for 128-byte ATVV audio frames */
	int mtu_err = bt_gatt_exchange_mtu(conn, &rc_mtu_params);
	if (mtu_err) {
		LOG_ERR("MTU exchange request failed (%d)", mtu_err);
#ifdef CONFIG_RC_VOICE
		int atvv_mtu_err = atvv_set_att_mtu(bt_gatt_get_mtu(conn));
		if (atvv_mtu_err) {
			LOG_ERR("ATVV audio disabled: ATT MTU %u is too small",
				bt_gatt_get_mtu(conn));
		}
#endif
	}

	if (rc_hids_get_state() == RC_HIDS_READY) {
		rc_mmi_run_event(MMI_OP_HID_READY);
	} else {
		rc_mmi_run_event(MMI_OP_PAIR_SUCCESS);
	}
}

static void rc_le_param_updated(struct bt_conn *conn, uint16_t interval, uint16_t latency,
				uint16_t timeout)
{
	LOG_INF("le_param_updated: interval:%d latency:%d timeout:%d", interval, latency, timeout);
}

static void rc_att_mtu_updated(struct bt_conn *conn, uint16_t tx, uint16_t rx)
{
	LOG_INF("ATT MTU updated: tx=%u rx=%u", tx, rx);
#ifdef CONFIG_RC_VOICE
	int mtu_err = atvv_set_att_mtu(MIN(tx, rx));
	if (mtu_err) {
		LOG_ERR("ATVV audio disabled: ATT MTU %u is too small", MIN(tx, rx));
	}
#endif
}

static struct bt_gatt_cb rc_gatt_cb = {
	.att_mtu_updated = rc_att_mtu_updated,
};

BT_CONN_CB_DEFINE(conn_callbacks) = {
	.connected = rc_connected,
	.disconnected = rc_disconnected,
#ifdef CONFIG_BT_SMP_SC_ONLY
	.identity_resolved = rc_identity_resolved,
#endif
	.security_changed = rc_security_changed,
	.le_param_updated = rc_le_param_updated,
};

int rc_gap_settings_store_bt_id(uint32_t bt_id)
{
	if (bt_id >= CONFIG_BT_ID_MAX) {
		return -EINVAL;
	}

	int err = settings_save_one("rc/current_id", &bt_id, sizeof(bt_id));
	if (err) {
		LOG_ERR("Failed to store current_id (err %d)\n", err);
	}
	return err;
}

static int rc_settings_handle_set(char const *name, size_t len, settings_read_cb read_cb,
				  void *cb_arg)
{
	const char *next;

	if (settings_name_steq(name, "current_id", &next) && !next) {
		if (len != sizeof(active_id)) {
			return -EINVAL;
		}
		int err = read_cb(cb_arg, &active_id, sizeof(active_id));
		if (err < 0) {
			return err;
		}
		if (active_id >= CONFIG_BT_ID_MAX) {
			LOG_WRN("Ignoring invalid stored BT identity %u", (unsigned int)active_id);
			active_id = BT_ID_DEFAULT;
		}
		return 0;
	}

	return -ENOENT;
}

SETTINGS_STATIC_HANDLER_DEFINE(rc_settings_storage, "rc", NULL, rc_settings_handle_set, NULL, NULL);

static void rc_gap_init_cfm(int err)
{
	if (err) {
		LOG_INF("Bluetooth init failed (err %d)\n", err);
		return;
	}

	LOG_INF("Bluetooth initialized\n");

	if (IS_ENABLED(CONFIG_SETTINGS)) {
		settings_load();
	}

	if (active_id >= CONFIG_BT_ID_MAX) {
		LOG_WRN("Using default BT identity instead of %u", (unsigned int)active_id);
		active_id = BT_ID_DEFAULT;
	}

	rc_gap_transition(GAP_OP_INITED);
}

static void rc_adv_sent_cb(struct bt_le_ext_adv *adv, struct bt_le_ext_adv_sent_info *info)
{
	int reconnect_index = rc_reconnect_adv_index(adv);

	ARG_UNUSED(info);

	if (adv == adv_sets[RC_ADV_PAIRING]) {
		LOG_INF("Advertising timeout: pairing local id=%u", (unsigned int)active_id);
		pairing_adv_active = false;

		/* Pairing advertising is auxiliary when a bonded link is active. */
		if (connection_count) {
			LOG_INF("Pairing advertising stopped while connected");
			return;
		}
	} else if (reconnect_index >= 0) {
		LOG_INF("Advertising timeout: reconnect[%u] local id=%u",
			(unsigned int)reconnect_index, (unsigned int)active_id);
		ADDR_INF("Advertising target ", &reconnect_peers[reconnect_index].addr, "\n");
		reconnect_adv_active[reconnect_index] = false;
		if (connection_count || rc_reconnect_adv_any_active()) {
			return;
		}
	}

	rc_gap_transition(GAP_OP_ADV_STOP);
}

static struct bt_le_ext_adv_cb adv_callbacks = {
	.sent = rc_adv_sent_cb,
};

#define PAIRING_ADV_OPT     (BT_LE_ADV_OPT_CONN | BT_LE_ADV_OPT_SCANNABLE)
#define RECONN_ADV_OPT      (BT_LE_ADV_OPT_CONN)
#define RECONN_DIRECTED_OPT (BT_LE_ADV_OPT_CONN | BT_LE_ADV_OPT_DIR_MODE_LOW_DUTY)

static int rc_create_adv(enum rc_adv_id adv_id, bool pairing, const struct rc_reconnect_peer *peer)
{
	if (adv_sets[adv_id]) {
		LOG_INF("Advertising set already created...");
		return -EALREADY;
	}

	struct bt_le_adv_param adv_param = {
		.id = active_id,
		.sid = adv_id,
		.secondary_max_skip = 0,
		.options =
			pairing ? PAIRING_ADV_OPT : (peer ? RECONN_DIRECTED_OPT : RECONN_ADV_OPT),
		.interval_min = CONFIG_RC_ADV_INTERVAL_MIN,
		.interval_max = CONFIG_RC_ADV_INTERVAL_MAX,
		.peer = (!pairing && peer) ? &peer->addr : NULL,
	};

	if (peer) {
		LOG_INF("Create reconnect[%u]: local id=%u",
			(unsigned int)(adv_id - RC_ADV_RECONNECT_BASE), (unsigned int)active_id);
		ADDR_INF("Reconnect advertising target ", &peer->addr, "\n");
	} else {
		LOG_INF("Create pairing advertising: local id=%u", (unsigned int)active_id);
	}

	LOG_INF("Advertising set create...");
	int err = bt_le_ext_adv_create(&adv_param, &adv_callbacks, &adv_sets[adv_id]);
	if (err) {
		LOG_ERR("Failed to create advertising set (err %d)\n", err);
		return err;
	}

	bool directed = !pairing && peer;
	struct bt_data const *ad = directed ? NULL : adv_data;
	size_t ad_len = directed ? 0 : ARRAY_SIZE(adv_data);
	struct bt_data const *sd = pairing ? pairing_scan_data : reconn_scan_data;
	size_t sd_len = pairing || !directed ? (pairing ? ARRAY_SIZE(pairing_scan_data)
							: ARRAY_SIZE(reconn_scan_data))
					     : 0;

	for (int retry = 0; retry < 5; retry++) {
		err = bt_le_ext_adv_set_data(adv_sets[adv_id], ad, ad_len, directed ? NULL : sd,
					     sd_len);
		if (err != -ENOBUFS) {
			break;
		}
		LOG_WRN("bt_le_ext_adv_set_data ENOBUFS, retry %d", retry + 1);
		k_msleep(500);
	}
	if (err) {
		LOG_ERR("Failed to set advertising data (err %d)\n", err);
		bt_le_ext_adv_delete(adv_sets[adv_id]);
		adv_sets[adv_id] = NULL;
	}

	return err;
}

static void rc_start_adv(enum rc_adv_id adv_id, bool pairing)
{
	if (!adv_sets[adv_id]) {
		LOG_ERR("Advertising set %d is not created", adv_id);
		return;
	}

	struct bt_le_ext_adv_start_param ext_adv_start_param = {
		/* ADV0 = reconnect, ADV1 = pairing — swap relative to kbd convention */
		.timeout = RC_ADV_TIMEOUT_UNITS(pairing ? CONFIG_RC_ADV1_DURATION_MS
							: CONFIG_RC_ADV0_DURATION_MS),
		.num_events = 0,
	};

	int err = bt_le_ext_adv_start(adv_sets[adv_id], &ext_adv_start_param);
	if (err) {
		LOG_ERR("Failed to start advertising (err %d)\n", err);
		return;
	}

	if (adv_id == RC_ADV_PAIRING) {
		pairing_adv_active = true;
	} else {
		int reconnect_index = rc_reconnect_adv_index(adv_sets[adv_id]);

		if (reconnect_index >= 0) {
			reconnect_adv_active[reconnect_index] = true;
		}
	}

	LOG_INF("Advertising Start");
	if (connection_count == 0 &&
	    ((pairing && gap_ctx.ctx.current != &gap_states[GAP_S_ADV1ING]) ||
	     (!pairing && gap_ctx.ctx.current != &gap_states[GAP_S_ADV0ING]))) {
		rc_gap_transition(pairing ? GAP_OP_ADV1ING : GAP_OP_ADV0ING);
	}
}

static void rc_gap_reconnecting(void)
{
	if (gap_ctx.ctx.current == &gap_states[GAP_S_IDLE]) {
		for (size_t i = 0; i < reconnect_peer_count && i < RC_RECONNECT_ADV_COUNT; i++) {
			enum rc_adv_id adv_id = RC_ADV_RECONNECT_BASE + i;

			if (!adv_sets[adv_id] &&
			    rc_create_adv(adv_id, false, &reconnect_peers[i])) {
				LOG_ERR("Failed to create reconnect advertising %u",
					(unsigned int)i);
				continue;
			}
			rc_start_adv(adv_id, false);
		}
	}
}

static void rc_gap_pairing(void)
{
	if (gap_ctx.ctx.current == &gap_states[GAP_S_IDLE]) {
		if (!adv_sets[RC_ADV_PAIRING] && rc_create_adv(RC_ADV_PAIRING, true, NULL)) {
			return;
		}
		rc_start_adv(RC_ADV_PAIRING, true);
	}
}

static void rc_gap_s_init_op_inited(void)
{
	rc_gap_update_bond_information();

	if (pairing_forced) {
		LOG_INF("Pairing mode forced until cold boot");
	}

	rc_mmi_run_event(MMI_OP_INIT_DONE);

	LOG_INF("[%d] %s", active_id, is_pairing ? "Pairing" : "Reconnecting");

#ifdef CONFIG_VND_API_SET_ADV_TX_POWER
	if (atm_vendor_set_adv_tx_power(TX_POWER_0_DBM)) {
		LOG_ERR("Set adv tx pwr fail");
	}
#endif
	if (is_pairing) {
		int err = rc_create_adv(RC_ADV_PAIRING, true, NULL);

		if (err) {
			LOG_ERR("Advertising set create failed (err %d)\n", err);
			return;
		}
		rc_start_adv(RC_ADV_PAIRING, true);
	} else {
		rc_gap_reconnecting();
	}
}

/* SMF state entry functions. */

static void gap_init_entry(void *obj)
{
	LOG_DBG("gap_s:GAP_S_INIT");
}

static void gap_idle_entry(void *obj)
{
	LOG_DBG("gap_s:GAP_S_IDLE");
}

static void gap_adv0ing_entry(void *obj)
{
	LOG_DBG("gap_s:GAP_S_ADV0ING");
}

static void gap_adv1ing_entry(void *obj)
{
	LOG_DBG("gap_s:GAP_S_ADV1ING");
}

static void gap_stopping_entry(void *obj)
{
	LOG_DBG("gap_s:GAP_S_ADV_STOPPING");
}

static void gap_connected_entry(void *obj)
{
	LOG_DBG("gap_s:GAP_S_CONNECTED");
}

static void gap_rftest_entry(void *obj)
{
	LOG_DBG("gap_s:GAP_S_RFTEST");
}

/* SMF state handlers. */

static enum smf_state_result gap_init_run(void *obj)
{
	switch (gap_ctx.evt) {
	case GAP_OP_INITED:
		/* State must change to IDLE before the handler runs, because
		 * rc_gap_s_init_op_inited() calls rc_start_adv() which
		 * recursively calls rc_gap_transition() — that recursive
		 * smf_run_state() must dispatch to gap_idle_run, not
		 * gap_init_run. */
		smf_set_state(SMF_CTX(&gap_ctx), &gap_states[GAP_S_IDLE]);
		rc_gap_s_init_op_inited();
		break;
	case GAP_OP_ADV0ING:
		rc_mmi_run_event(MMI_OP_RECONNING);
		smf_set_state(SMF_CTX(&gap_ctx), &gap_states[GAP_S_ADV0ING]);
		break;
	case GAP_OP_ADV1ING:
		rc_mmi_run_event(MMI_OP_PAIRING);
		smf_set_state(SMF_CTX(&gap_ctx), &gap_states[GAP_S_ADV1ING]);
		break;
	default:
		break;
	}
	return SMF_EVENT_PROPAGATE;
}

static enum smf_state_result gap_idle_run(void *obj)
{
	switch (gap_ctx.evt) {
	case GAP_OP_ADV0ING:
		rc_mmi_run_event(MMI_OP_RECONNING);
		smf_set_state(SMF_CTX(&gap_ctx), &gap_states[GAP_S_ADV0ING]);
		break;
	case GAP_OP_ADV1ING:
		rc_mmi_run_event(MMI_OP_PAIRING);
		smf_set_state(SMF_CTX(&gap_ctx), &gap_states[GAP_S_ADV1ING]);
		break;
	default:
		break;
	}
	return SMF_EVENT_PROPAGATE;
}

static enum smf_state_result gap_adv0ing_run(void *obj)
{
	switch (gap_ctx.evt) {
	case GAP_OP_INITED:
		/* Stay in ADV0ING — no action */
		break;
	case GAP_OP_ADV_STOP:
		rc_mmi_run_event(MMI_OP_RECONN_FAIL);
		smf_set_state(SMF_CTX(&gap_ctx), &gap_states[GAP_S_IDLE]);
		break;
	case GAP_OP_CONNECTED:
		rc_mmi_run_event(MMI_OP_CONNECTED);
		smf_set_state(SMF_CTX(&gap_ctx), &gap_states[GAP_S_CONNECTED]);
		break;
	case GAP_OP_ADV_STOPPING:
		smf_set_state(SMF_CTX(&gap_ctx), &gap_states[GAP_S_ADV_STOPPING]);
		break;
	default:
		break;
	}
	return SMF_EVENT_PROPAGATE;
}

static enum smf_state_result gap_adv1ing_run(void *obj)
{
	switch (gap_ctx.evt) {
	case GAP_OP_INITED:
		/* Stay in ADV1ING — no action */
		break;
	case GAP_OP_ADV_STOP:
		rc_mmi_run_event(MMI_OP_PAIR_FAIL_ADV_TOUT);
		smf_set_state(SMF_CTX(&gap_ctx), &gap_states[GAP_S_IDLE]);
		break;
	case GAP_OP_CONNECTED:
		rc_mmi_run_event(MMI_OP_CONNECTED);
		smf_set_state(SMF_CTX(&gap_ctx), &gap_states[GAP_S_CONNECTED]);
		break;
	case GAP_OP_ADV_STOPPING:
		smf_set_state(SMF_CTX(&gap_ctx), &gap_states[GAP_S_ADV_STOPPING]);
		break;
	default:
		break;
	}
	return SMF_EVENT_PROPAGATE;
}

static enum smf_state_result gap_stopping_run(void *obj)
{
	switch (gap_ctx.evt) {
	case GAP_OP_ADV_STOP:
		rc_mmi_run_event(MMI_OP_ADV_STOPPED);
		smf_set_state(SMF_CTX(&gap_ctx), &gap_states[GAP_S_IDLE]);
		break;
	default:
		break;
	}
	return SMF_EVENT_PROPAGATE;
}

static enum smf_state_result gap_connected_run(void *obj)
{
	switch (gap_ctx.evt) {
	case GAP_OP_DISCONNECTED:
		rc_gap_update_bond_information();
		smf_set_state(SMF_CTX(&gap_ctx), &gap_states[GAP_S_IDLE]);
		rc_mmi_run_event(MMI_OP_DISCONNED);
		break;
	case GAP_OP_ADV_STOP:
		/* Stay in CONNECTED — no action */
		break;
	default:
		break;
	}
	return SMF_EVENT_PROPAGATE;
}

static enum smf_state_result gap_rftest_run(void *obj)
{
	return SMF_EVENT_PROPAGATE;
}

/* SMF state table. */

static const struct smf_state gap_states[GAP_S_NUM] = {
	[GAP_S_INIT] = SMF_CREATE_STATE(gap_init_entry, gap_init_run, NULL, NULL, NULL),
	[GAP_S_IDLE] = SMF_CREATE_STATE(gap_idle_entry, gap_idle_run, NULL, NULL, NULL),
	[GAP_S_ADV0ING] = SMF_CREATE_STATE(gap_adv0ing_entry, gap_adv0ing_run, NULL, NULL, NULL),
	[GAP_S_ADV1ING] = SMF_CREATE_STATE(gap_adv1ing_entry, gap_adv1ing_run, NULL, NULL, NULL),
	[GAP_S_ADV_STOPPING] =
		SMF_CREATE_STATE(gap_stopping_entry, gap_stopping_run, NULL, NULL, NULL),
	[GAP_S_CONNECTED] =
		SMF_CREATE_STATE(gap_connected_entry, gap_connected_run, NULL, NULL, NULL),
	[GAP_S_RFTEST] = SMF_CREATE_STATE(gap_rftest_entry, gap_rftest_run, NULL, NULL, NULL),
};

static void auth_cancel(struct bt_conn *conn)
{
	ADDR_INF("Pairing cancelled: ", bt_conn_get_dst(conn), "\n");
}

static void pairing_complete(struct bt_conn *conn, bool bonded)
{
	LOG_INF("Pairing Complete\n");
	if (bonded) {
		/* A dynamic pairing attempt may complete while another link remains up. */
		rc_gap_update_bond_information();
	}
}

static void pairing_failed(struct bt_conn *conn, enum bt_security_err reason)
{
	LOG_INF("Pairing Failed (%d). Disconnecting.\n", reason);
	bt_conn_disconnect(conn, BT_HCI_ERR_AUTH_FAIL);
}

static struct bt_conn_auth_cb auth_cb_display = {
	.cancel = auth_cancel,
};

static struct bt_conn_auth_info_cb auth_cb_info = {
	.pairing_complete = pairing_complete,
	.pairing_failed = pairing_failed,
};

void rc_gap_init(void)
{
	smf_set_initial(SMF_CTX(&gap_ctx), &gap_states[GAP_S_INIT]);
	rc_pairing_marker_init();

	int err = bt_enable(rc_gap_init_cfm);
	if (err) {
		LOG_INF("Bluetooth init failed (err %d)\n", err);
		return;
	}
	bt_conn_auth_cb_register(&auth_cb_display);
	bt_conn_auth_info_cb_register(&auth_cb_info);
	bt_gatt_cb_register(&rc_gatt_cb);
}

void rc_gap_discoverable(bool enable)
{
	if (enable) {
		if (!is_pairing) {
			rc_gap_reconnecting();
		} else {
			rc_gap_pairing();
		}
		return;
	}

	const struct smf_state *s = gap_ctx.ctx.current;
	if (s == &gap_states[GAP_S_ADV1ING]) {
		LOG_INF("bt_le_ext_adv_stop\n");
		rc_gap_transition(GAP_OP_ADV_STOPPING);
		if (adv_sets[RC_ADV_PAIRING]) {
			bt_le_ext_adv_stop(adv_sets[RC_ADV_PAIRING]);
		}
		pairing_adv_active = false;
		rc_gap_transition(GAP_OP_ADV_STOP);
	} else if (s == &gap_states[GAP_S_ADV0ING]) {
		LOG_INF("bt_le_ext_adv_stop\n");
		rc_gap_transition(GAP_OP_ADV_STOPPING);
		rc_stop_reconnect_advertising();
		rc_gap_transition(GAP_OP_ADV_STOP);
	} else if (pairing_adv_active && adv_sets[RC_ADV_PAIRING]) {
		LOG_INF("Stopping auxiliary pairing advertising");
		bt_le_ext_adv_stop(adv_sets[RC_ADV_PAIRING]);
		pairing_adv_active = false;
	}
}

void rc_gap_disconnect(void)
{
	LOG_INF("bt_conn_disconnect\n");
	if (current_conn) {
		bt_conn_disconnect(current_conn, BT_HCI_ERR_REMOTE_USER_TERM_CONN);
	}
}

void rc_gap_remove_all_bond(void)
{
	LOG_INF("Removing all bonds\n");
	for (size_t i = 0; i < CONFIG_BT_ID_MAX; i++) {
		bt_unpair(i, NULL);
	}
}

void rc_gap_remove_current_bond(void)
{
	LOG_INF("Removing current bond\n");
	bt_unpair(active_id, NULL);
}

void rc_gap_set_force_pairing(void)
{
	uint32_t marker = PAIRING_MARKER_MAGIC;

	pairing_forced = true;
	is_pairing = true;

	if (device_is_ready(pairing_marker_dev)) {
		int err = retained_mem_write(pairing_marker_dev, PAIRING_MARKER_OFFSET,
					     (const uint8_t *)&marker, sizeof(marker));

		if (err) {
			LOG_WRN("Failed to save pairing marker (err %d)", err);
		}
	}

	LOG_INF("Pairing mode forced until cold boot");

	if (gap_ctx.ctx.current == &gap_states[GAP_S_ADV0ING]) {
		rc_gap_discoverable(false);
	}

	if (!connection_count && gap_ctx.ctx.current == &gap_states[GAP_S_IDLE]) {
		rc_gap_pairing();
	}
}

void rc_gap_param_update(bool low_latency)
{
	if (!current_conn) {
		return;
	}
	/* Power-save params mirror PPCP (CONFIG_BT_PERIPHERAL_PREF_*) so prj.conf
	 * is the single source of truth.  Low-latency (audio) uses latency=0. */
	struct bt_le_conn_param param = {
		.interval_min = CONFIG_BT_PERIPHERAL_PREF_MIN_INT,
		.interval_max = CONFIG_BT_PERIPHERAL_PREF_MAX_INT,
		.latency = low_latency ? 0 : CONFIG_BT_PERIPHERAL_PREF_LATENCY,
		.timeout = CONFIG_BT_PERIPHERAL_PREF_TIMEOUT,
	};
	LOG_INF("param_update(%s): int=%d lat=%d timeout=%d", low_latency ? "fast" : "save",
		param.interval_min, param.latency, param.timeout);
	int err = bt_conn_le_param_update(current_conn, &param);
	if (err) {
		LOG_WRN("param_update(%s) err %d", low_latency ? "fast" : "save", err);
	}
}
