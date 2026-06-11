/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include <zephyr/logging/log.h>
#include <zephyr/settings/settings.h>
#include <zephyr/sys/byteorder.h>
#include <zephyr/bluetooth/conn.h>
#include "at_cmd_gatt.h"
#include "at_cmd_set_common.h"

LOG_MODULE_REGISTER(at_cmd_gatt, CONFIG_AT_CMD_SET_LOG_LEVEL);

/* Sentinel value indicating an invalid attribute index */
#define AT_GATT_INVALID_ATT_IDX UINT16_MAX

/* Settings subtree paths for persistence */
#define SETTINGS_DFT_SVC_PATH   "at/gatt/dft_svc"
#define SETTINGS_DFT_CHAR1_PATH "at/gatt/dft_char1"
#define SETTINGS_DFT_CHAR2_PATH "at/gatt/dft_char2"
/* NOTE: server enabled state is intentionally NOT persisted.
 * Default is always OFF on boot; user must issue AT+BLEGATTDFTSERVER=ON. */

/* Default security properties (lower bits = BT_GATT_PERM_*, upper bits = NOTIFY/INDICATE) */
#define DFT_SVC_SEC_PROP   BT_GATT_PERM_NONE
/* char1: Write Command + Notify */
#define DFT_CHAR1_SEC_PROP (BT_GATT_PERM_WRITE | AT_CMD_GATT_CHRC_NOTIFY_BIT)
/* char2: Write Command + Notify + Indicate */
#define DFT_CHAR2_SEC_PROP                                                                         \
	(BT_GATT_PERM_WRITE | AT_CMD_GATT_CHRC_NOTIFY_BIT | AT_CMD_GATT_CHRC_INDICATE_BIT)

/* Max GATT attribute slots: svc(1) + char1(decl+val+cccd=3) + char2(decl+val+cccd=3) */
#define GATT_ATTRS_MAX 7

/* Max characteristic read-value buffer size (BLE spec Vol 3, Part F, 3.2.9) */
#define GATT_CHAR_VAL_MAX BT_ATT_MAX_ATTRIBUTE_LEN

/* Mutex to protect service registration/unregistration from concurrent access */
static struct k_mutex s_reregister_lock = Z_MUTEX_INITIALIZER(s_reregister_lock);

/* AT-format UUIDs (MSB-first) — initialized to defaults, overwritten by Settings on load */
static uint8_t s_svc_uuid[BT_UUID_SIZE_128] = {0x12, 0x3E, 0x45, 0x67, 0xE8, 0x9B, 0x12, 0xD3,
					       0xA4, 0x56, 0x42, 0x66, 0x14, 0x17, 0x40, 0x00};
static uint16_t s_svc_sec_prop = DFT_SVC_SEC_PROP;
static uint8_t s_char1_uuid[BT_UUID_SIZE_128] = {0x22, 0x3E, 0x45, 0x67, 0xE8, 0x9B, 0x12, 0xD3,
						 0xA4, 0x56, 0x42, 0x66, 0x14, 0x17, 0x40, 0x00};
static uint16_t s_char1_sec_prop = DFT_CHAR1_SEC_PROP;
static uint8_t s_char2_uuid[BT_UUID_SIZE_128] = {0x32, 0x3E, 0x45, 0x67, 0xE8, 0x9B, 0x12, 0xD3,
						 0xA4, 0x56, 0x42, 0x66, 0x14, 0x17, 0x40, 0x00};
static uint16_t s_char2_sec_prop = DFT_CHAR2_SEC_PROP;

/* Zephyr GATT UUID structs (LE byte-order) — updated before each (re-)registration */
static struct bt_uuid_128 s_svc_uuid_128 = {.uuid.type = BT_UUID_TYPE_128};
static struct bt_uuid_128 s_char1_uuid_128 = {.uuid.type = BT_UUID_TYPE_128};
static struct bt_uuid_128 s_char2_uuid_128 = {.uuid.type = BT_UUID_TYPE_128};

/* File-scope statics prevent dangling pointers: BT_UUID_GATT_* macros expand to
 * compound literals with automatic (stack) storage inside a function; keeping them
 * at file scope gives them static duration, which is safe for s_gatt_attrs[].uuid. */
static const struct bt_uuid *s_uuid_gatt_primary = BT_UUID_GATT_PRIMARY;
static const struct bt_uuid *s_uuid_gatt_chrc = BT_UUID_GATT_CHRC;
static const struct bt_uuid *s_uuid_gatt_ccc = BT_UUID_GATT_CCC;

/* CCC managed user data — holds per-connection subscription state */
static struct bt_gatt_ccc_managed_user_data s_char1_ccc;
static struct bt_gatt_ccc_managed_user_data s_char2_ccc;

/* CHRC declaration structs; build_attrs() updates .properties before each (re-)registration. */
static struct bt_gatt_chrc s_char1_chrc = BT_GATT_CHRC_INIT(
	&s_char1_uuid_128.uuid, 0U, BT_GATT_CHRC_WRITE_WITHOUT_RESP | BT_GATT_CHRC_NOTIFY);
static struct bt_gatt_chrc s_char2_chrc = BT_GATT_CHRC_INIT(
	&s_char2_uuid_128.uuid, 0U,
	BT_GATT_CHRC_WRITE_WITHOUT_RESP | BT_GATT_CHRC_NOTIFY | BT_GATT_CHRC_INDICATE);

/* GATT attribute storage; CCCD included only when NOTIFY or INDICATE is set. */
static uint8_t s_char1v_idx; /* index of char1 value attr, set by build_attrs() */
static uint8_t s_char2v_idx; /* index of char2 value attr, set by build_attrs() */
static struct bt_gatt_attr s_gatt_attrs[GATT_ATTRS_MAX];
static struct bt_gatt_service s_gatt_service = {
	.attrs = s_gatt_attrs,
};

/* true when the service is currently registered with the BT stack */
static bool s_registered;

/* true when a UUID/perm change was deferred because a connection was active */
static bool s_pending_reregister;

/* Pre-set read-value buffers; returned by gatt_read_cb when client reads the characteristic */
static uint8_t s_char1_val_buf[GATT_CHAR_VAL_MAX];
static uint16_t s_char1_val_len;
static uint8_t s_char2_val_buf[GATT_CHAR_VAL_MAX];
static uint16_t s_char2_val_len;

/**
 * @brief GATT characteristic write callback
 *
 * Called when client writes to characteristic
 */
static ssize_t gatt_write_cb(struct bt_conn *conn, const struct bt_gatt_attr *attr, const void *buf,
			     uint16_t len, uint16_t offset, uint8_t flags)
{
	uint8_t slot = at_cmd_conn_slot(conn);

	LOG_DBG("Write: slot=%u, handle=0x%04x, len=%u", slot, attr->handle, len);
	at_cmd_evt_gatt_from_ble(slot, attr->handle, AT_GATT_ACT_WRITE, buf, len);

	return len;
}

/**
 * @brief GATT characteristic read callback
 *
 * Zephyr read callbacks are synchronous — no READ_CFM round-trip is possible.
 * Returns the pre-set value buffer (set via AT+BLEGATTDFTCHAR*VAL).
 * Notifies the host of the read event (informational).
 */
static ssize_t gatt_read_cb(struct bt_conn *conn, const struct bt_gatt_attr *attr, void *buf,
			    uint16_t len, uint16_t offset)
{
	uint8_t slot = at_cmd_conn_slot(conn);

	LOG_DBG("Read: slot=%u, handle=0x%04x, offset=%u", slot, attr->handle, offset);
	at_cmd_evt_gatt_from_ble(slot, attr->handle, AT_GATT_ACT_READ, NULL, 0);

	/* Select value buffer by pointer comparison (handle is 0 in unit-test mode) */
	uint8_t *val = (attr == &s_gatt_attrs[s_char1v_idx]) ? s_char1_val_buf : s_char2_val_buf;
	uint16_t vlen = (attr == &s_gatt_attrs[s_char1v_idx]) ? s_char1_val_len : s_char2_val_len;

	return bt_gatt_attr_read(conn, attr, buf, len, offset, val, vlen);
}

/**
 * @brief Rebuild the GATT attribute table based on current chrc properties.
 *
 * Follows the csip_set_member.c pattern: fill s_gatt_attrs sequentially,
 * skip CCCD when the characteristic does not advertise NOTIFY or INDICATE,
 * then set s_gatt_service.attr_count to the actual count.
 *
 * Also records the value attr indices in s_char1v_idx / s_char2v_idx so
 * that update_attrs() can patch .perm without relying on fixed offsets.
 */
static void at_cmd_gatt_dft_build_attrs(void)
{
	uint8_t cnt = 0;

	/* [cnt] Primary Service */
	s_gatt_attrs[cnt++] = (struct bt_gatt_attr)BT_GATT_ATTRIBUTE(
		s_uuid_gatt_primary, BT_GATT_PERM_READ, bt_gatt_attr_read_service, NULL,
		&s_svc_uuid_128);

	/* [cnt] Char1 declaration */
	s_gatt_attrs[cnt++] = (struct bt_gatt_attr)BT_GATT_ATTRIBUTE(
		s_uuid_gatt_chrc, BT_GATT_PERM_READ, bt_gatt_attr_read_chrc, NULL, &s_char1_chrc);

	/* [cnt] Char1 value — record index for perm patching */
	s_char1v_idx = cnt;
	s_gatt_attrs[cnt++] = (struct bt_gatt_attr)BT_GATT_ATTRIBUTE(
		&s_char1_uuid_128.uuid, s_char1_sec_prop & AT_GATT_ATT_PERM_MASK, gatt_read_cb,
		gatt_write_cb, NULL);

	/* [cnt] Char1 CCCD — only when NOTIFY or INDICATE is advertised */
	if (s_char1_chrc.properties & (BT_GATT_CHRC_NOTIFY | BT_GATT_CHRC_INDICATE)) {
		s_gatt_attrs[cnt++] = (struct bt_gatt_attr)BT_GATT_ATTRIBUTE(
			s_uuid_gatt_ccc, AT_GATT_PERM_CCC, bt_gatt_attr_read_ccc,
			bt_gatt_attr_write_ccc, &s_char1_ccc);
	}

	/* [cnt] Char2 declaration */
	s_gatt_attrs[cnt++] = (struct bt_gatt_attr)BT_GATT_ATTRIBUTE(
		s_uuid_gatt_chrc, BT_GATT_PERM_READ, bt_gatt_attr_read_chrc, NULL, &s_char2_chrc);

	/* [cnt] Char2 value — record index for perm patching */
	s_char2v_idx = cnt;
	s_gatt_attrs[cnt++] = (struct bt_gatt_attr)BT_GATT_ATTRIBUTE(
		&s_char2_uuid_128.uuid, s_char2_sec_prop & AT_GATT_ATT_PERM_MASK, gatt_read_cb,
		gatt_write_cb, NULL);

	/* [cnt] Char2 CCCD — only when NOTIFY or INDICATE is advertised */
	if (s_char2_chrc.properties & (BT_GATT_CHRC_NOTIFY | BT_GATT_CHRC_INDICATE)) {
		s_gatt_attrs[cnt++] = (struct bt_gatt_attr)BT_GATT_ATTRIBUTE(
			s_uuid_gatt_ccc, AT_GATT_PERM_CCC, bt_gatt_attr_read_ccc,
			bt_gatt_attr_write_ccc, &s_char2_ccc);
	}

	s_gatt_service.attr_count = cnt;
	LOG_DBG("Built %u attrs (char1v=%u, char2v=%u)", cnt, s_char1v_idx, s_char2v_idx);
}

/**
 * @brief Update UUIDs, CHRC properties, and rebuild the attribute table.
 *
 * Called before every (re-)registration:
 * 1. Converts AT-format (MSB-first) UUIDs to Zephyr LE format.
 * 2. Derives CHRC properties from sec_prop.
 * 3. Rebuilds s_gatt_attrs[] with conditional CCCD inclusion.
 */
static void at_cmd_gatt_dft_update_attrs(void)
{
	/* Convert MSB-first AT UUIDs to Zephyr LE format */
	sys_memcpy_swap(s_svc_uuid_128.val, s_svc_uuid, BT_UUID_SIZE_128);
	sys_memcpy_swap(s_char1_uuid_128.val, s_char1_uuid, BT_UUID_SIZE_128);
	sys_memcpy_swap(s_char2_uuid_128.val, s_char2_uuid, BT_UUID_SIZE_128);

	/* Derive CHRC properties from sec_prop (must be before build_attrs) */
	s_char1_chrc.properties = at_cmd_gatt_sec_prop_to_chrc_props(s_char1_sec_prop);
	s_char2_chrc.properties = at_cmd_gatt_sec_prop_to_chrc_props(s_char2_sec_prop);

	/* Rebuild attr table (CCCD conditional, sets attr_count) */
	at_cmd_gatt_dft_build_attrs();
}

static at_cmd_result_t at_cmd_gatt_dft_service_register(void)
{
	if (s_registered) {
		return (at_cmd_result_t){.err = -EINVAL, .app_err = at_cmd_map_errno(-EINVAL)};
	}

	/* Apply current UUIDs and permissions to static attribute array */
	at_cmd_gatt_dft_update_attrs();

	LOG_INF("Registering default GATT service");

	int ret = bt_gatt_service_register(&s_gatt_service);
	if (ret) {
		LOG_ERR("Failed to register GATT service: %d", ret);
		return (at_cmd_result_t){.err = ret, .app_err = at_cmd_map_errno(ret)};
	}

	s_registered = true;
	return at_cmd_result_ok();
}

/**
 * @brief Unregister the default GATT service
 */
static at_cmd_result_t at_cmd_gatt_dft_service_unregister(void)
{
	if (!s_registered) {
		return (at_cmd_result_t){.err = -EINVAL, .app_err = at_cmd_map_errno(-EINVAL)};
	}

	LOG_INF("Unregistering default GATT service");

	int ret = bt_gatt_service_unregister(&s_gatt_service);
	if (ret) {
		LOG_ERR("Failed to unregister GATT service: %d", ret);
		return (at_cmd_result_t){.err = ret, .app_err = at_cmd_map_errno(ret)};
	}

	s_registered = false;
	return at_cmd_result_ok();
}

void at_cmd_gatt_dft_config_init(void)
{
	ssize_t ret;

	/* Load Service UUID */
	struct {
		uint8_t uuid[BT_UUID_SIZE_128];
		uint8_t sec_prop_be[2];
	} svc_data;

	ret = settings_load_one(SETTINGS_DFT_SVC_PATH, &svc_data, sizeof(svc_data));
	if (ret == (ssize_t)sizeof(svc_data)) {
		memcpy(s_svc_uuid, svc_data.uuid, BT_UUID_SIZE_128);
		s_svc_sec_prop = sys_get_be16(svc_data.sec_prop_be);
		LOG_DBG("Loaded Service from Settings");
	} else {
		LOG_INF("Service not in Settings (ret=%zd), using default", ret);
		/* s_svc_uuid / s_svc_sec_prop already hold compile-time defaults */
	}

	/* Load Characteristic 1 */
	struct {
		uint8_t uuid[BT_UUID_SIZE_128];
		uint8_t sec_prop_be[2];
	} char1_data;

	ret = settings_load_one(SETTINGS_DFT_CHAR1_PATH, &char1_data, sizeof(char1_data));
	if (ret == (ssize_t)sizeof(char1_data)) {
		memcpy(s_char1_uuid, char1_data.uuid, BT_UUID_SIZE_128);
		s_char1_sec_prop = sys_get_be16(char1_data.sec_prop_be);
		LOG_DBG("Loaded Char1 from Settings");
	} else {
		LOG_INF("Char1 not in Settings (ret=%zd), using default", ret);
	}

	/* Load Characteristic 2 */
	struct {
		uint8_t uuid[BT_UUID_SIZE_128];
		uint8_t sec_prop_be[2];
	} char2_data;

	ret = settings_load_one(SETTINGS_DFT_CHAR2_PATH, &char2_data, sizeof(char2_data));
	if (ret == (ssize_t)sizeof(char2_data)) {
		memcpy(s_char2_uuid, char2_data.uuid, BT_UUID_SIZE_128);
		s_char2_sec_prop = sys_get_be16(char2_data.sec_prop_be);
		LOG_DBG("Loaded Char2 from Settings");
	} else {
		LOG_INF("Char2 not in Settings (ret=%zd), using default", ret);
	}
}

/**
 * @brief Save GATT configuration from module-level static vars to Settings
 */
static int at_cmd_gatt_dft_config_save(void)
{
	int ret;

	struct {
		uint8_t uuid[BT_UUID_SIZE_128];
		uint8_t sec_prop_be[2];
	} svc_data;
	memcpy(svc_data.uuid, s_svc_uuid, BT_UUID_SIZE_128);
	sys_put_be16(s_svc_sec_prop, svc_data.sec_prop_be);

	ret = settings_save_one(SETTINGS_DFT_SVC_PATH, &svc_data, sizeof(svc_data));
	if (ret) {
		LOG_ERR("Failed to save Service UUID: %d", ret);
		return ret;
	}

	struct {
		uint8_t uuid[BT_UUID_SIZE_128];
		uint8_t sec_prop_be[2];
	} char1_data;
	memcpy(char1_data.uuid, s_char1_uuid, BT_UUID_SIZE_128);
	sys_put_be16(s_char1_sec_prop, char1_data.sec_prop_be);

	ret = settings_save_one(SETTINGS_DFT_CHAR1_PATH, &char1_data, sizeof(char1_data));
	if (ret) {
		LOG_ERR("Failed to save Char1: %d", ret);
		return ret;
	}

	struct {
		uint8_t uuid[BT_UUID_SIZE_128];
		uint8_t sec_prop_be[2];
	} char2_data;
	memcpy(char2_data.uuid, s_char2_uuid, BT_UUID_SIZE_128);
	sys_put_be16(s_char2_sec_prop, char2_data.sec_prop_be);

	ret = settings_save_one(SETTINGS_DFT_CHAR2_PATH, &char2_data, sizeof(char2_data));
	if (ret) {
		LOG_ERR("Failed to save Char2: %d", ret);
		return ret;
	}

	return 0;
}

/* Find a DFT service attribute by its BT GATT handle. */
struct bt_gatt_attr *at_cmd_gatt_dft_find_attr_by_handle(uint16_t handle)
{
	if (!s_registered) {
		return NULL;
	}

	for (uint16_t i = 0; i < s_gatt_service.attr_count; i++) {
		if (s_gatt_attrs[i].handle == handle) {
			return &s_gatt_attrs[i];
		}
	}
	return NULL;
}

at_cmd_result_t at_cmd_gatt_dft_server_set(bool state)
{
	bool enabled = s_registered;

	if (enabled == state) {
		return at_cmd_result_ok();
	}

	if (state) {
		at_cmd_result_t result = at_cmd_gatt_dft_service_register();

		if (result.err || result.app_err) {
			LOG_ERR("Failed to register default GATT service: %d", result.err);
			return result;
		}
	} else {
		at_cmd_result_t result = at_cmd_gatt_dft_service_unregister();

		if (result.err || result.app_err) {
			LOG_ERR("Failed to unregister default GATT service: %d", result.err);
			return result;
		}
	}

	return at_cmd_result_ok();
}

/**
 * @brief Get the current state of default GATT server
 */
bool at_cmd_gatt_dft_server_get(void)
{
	return s_registered;
}

/**
 * @brief Check if any BLE connections are currently active
 *
 * @return true if at least one connection is active
 */
static bool at_cmd_gatt_has_active_connection(void)
{
	at_cmd_ctx_t *ctx = at_cmd_ctx_get();

	return ctx && (ctx->conn_count > 0);
}

/**
 * @brief Re-register service if enabled and no active connections
 *
 * If the server is enabled and no peers are connected, unregisters then
 * re-registers the service so the new UUID/sec_prop takes effect immediately.
 * If peers are connected the UUID is already saved to Settings and will take
 * effect after the next AT+BLEGATTDFTSERVER=OFF / ON cycle or reboot.
 *
 * @param context_name Descriptive name for logging
 * @return at_cmd_result_t
 */
static at_cmd_result_t at_cmd_gatt_reregister_if_enabled(const char *context_name)
{
	if (!s_registered) {
		return at_cmd_result_ok();
	}

	if (at_cmd_gatt_has_active_connection()) {
		LOG_WRN("%s UUID saved; will re-register automatically when all peers disconnect",
			context_name);
		s_pending_reregister = true;
		return at_cmd_result_ok();
	}

	k_mutex_lock(&s_reregister_lock, K_FOREVER);

	at_cmd_result_t result = at_cmd_gatt_dft_service_unregister();

	if (result.err) {
		LOG_ERR("Failed to unregister service: %d", result.err);
	} else {
		result = at_cmd_gatt_dft_service_register();
		if (result.err) {
			LOG_ERR("Failed to re-register service: %d", result.err);
		} else {
			LOG_INF("Service re-registered with new %s", context_name);
		}
	}

	k_mutex_unlock(&s_reregister_lock);
	return result;
}

at_cmd_result_t at_cmd_gatt_dft_service_set(uint16_t sec_prop, const uint8_t *uuid)
{
	/* BLE spec: Service Declaration is read-only; reject any write-type perms */
	if (sec_prop & AT_GATT_PERM_WRITE_MASK) {
		LOG_ERR("Service sec_prop 0x%04X contains write bits (not allowed)", sec_prop);
		return (at_cmd_result_t){.err = -EINVAL, .app_err = AT_ERR_PARAM_INVALID};
	}

	memcpy(s_svc_uuid, uuid, BT_UUID_SIZE_128);
	s_svc_sec_prop = sec_prop;
	int ret = at_cmd_gatt_dft_config_save();
	if (ret) {
		return (at_cmd_result_t){.err = ret, .app_err = at_cmd_map_errno(ret)};
	}

	/* If server is enabled, automatically re-register with new UUID */
	return at_cmd_gatt_reregister_if_enabled("Service UUID");
}

at_cmd_result_t at_cmd_gatt_dft_service_get(uint16_t *sec_prop, uint8_t *uuid)
{
	memcpy(uuid, s_svc_uuid, BT_UUID_SIZE_128);
	*sec_prop = s_svc_sec_prop;
	return at_cmd_result_ok();
}

at_cmd_result_t at_cmd_gatt_dft_char1_set(uint16_t sec_prop, const uint8_t *uuid)
{
	memcpy(s_char1_uuid, uuid, BT_UUID_SIZE_128);
	s_char1_sec_prop = sec_prop;
	int ret = at_cmd_gatt_dft_config_save();
	if (ret) {
		return (at_cmd_result_t){.err = ret, .app_err = at_cmd_map_errno(ret)};
	}

	/* If server is enabled, automatically re-register with new UUID */
	return at_cmd_gatt_reregister_if_enabled("Characteristic 1 UUID");
}

at_cmd_result_t at_cmd_gatt_dft_char1_get(uint16_t *sec_prop, uint8_t *uuid)
{
	memcpy(uuid, s_char1_uuid, BT_UUID_SIZE_128);
	*sec_prop = s_char1_sec_prop;
	return at_cmd_result_ok();
}

at_cmd_result_t at_cmd_gatt_dft_char2_set(uint16_t sec_prop, const uint8_t *uuid)
{
	memcpy(s_char2_uuid, uuid, BT_UUID_SIZE_128);
	s_char2_sec_prop = sec_prop;
	int ret = at_cmd_gatt_dft_config_save();
	if (ret) {
		return (at_cmd_result_t){.err = ret, .app_err = at_cmd_map_errno(ret)};
	}

	/* If server is enabled, automatically re-register with new UUID */
	return at_cmd_gatt_reregister_if_enabled("Characteristic 2 UUID");
}

at_cmd_result_t at_cmd_gatt_dft_char2_get(uint16_t *sec_prop, uint8_t *uuid)
{
	memcpy(uuid, s_char2_uuid, BT_UUID_SIZE_128);
	*sec_prop = s_char2_sec_prop;
	return at_cmd_result_ok();
}

/**
 * @brief Called when all BLE connections have been dropped.
 *
 * If a UUID/perm change was deferred while a connection was active,
 * automatically re-registers the GATT service now so the next
 * connection will see the updated attributes.
 */
void at_cmd_gatt_dft_on_all_disconnected(void)
{
	if (!s_pending_reregister) {
		return;
	}

	s_pending_reregister = false;

	if (!s_registered) {
		return;
	}

	LOG_INF("All peers disconnected — applying pending GATT re-registration");

	k_mutex_lock(&s_reregister_lock, K_FOREVER);

	at_cmd_result_t result = at_cmd_gatt_dft_service_unregister();

	if (!result.err) {
		result = at_cmd_gatt_dft_service_register();
		if (result.err) {
			LOG_ERR("Pending re-registration failed: %d", result.err);
		} else {
			LOG_INF("GATT service re-registered with updated UUID/perm");
		}
	}

	k_mutex_unlock(&s_reregister_lock);
}

at_cmd_result_t at_cmd_gatt_dft_char1_val_set(const uint8_t *data, uint16_t len)
{
	if (len > GATT_CHAR_VAL_MAX) {
		return (at_cmd_result_t){.err = -EINVAL, .app_err = AT_ERR_PARAM_INVALID};
	}
	memcpy(s_char1_val_buf, data, len);
	s_char1_val_len = len;
	return at_cmd_result_ok();
}

at_cmd_result_t at_cmd_gatt_dft_char1_val_get(uint8_t *data, uint16_t *len)
{
	memcpy(data, s_char1_val_buf, s_char1_val_len);
	*len = s_char1_val_len;
	return at_cmd_result_ok();
}

at_cmd_result_t at_cmd_gatt_dft_char2_val_set(const uint8_t *data, uint16_t len)
{
	if (len > GATT_CHAR_VAL_MAX) {
		return (at_cmd_result_t){.err = -EINVAL, .app_err = AT_ERR_PARAM_INVALID};
	}
	memcpy(s_char2_val_buf, data, len);
	s_char2_val_len = len;
	return at_cmd_result_ok();
}

at_cmd_result_t at_cmd_gatt_dft_char2_val_get(uint8_t *data, uint16_t *len)
{
	memcpy(data, s_char2_val_buf, s_char2_val_len);
	*len = s_char2_val_len;
	return at_cmd_result_ok();
}

#ifdef CONFIG_ZTEST
/*
 * Test hooks: expose the static GATT read/write callbacks so Ztests can
 * invoke them directly with controlled inputs.  Bypasses bt_conn_index()
 * (which requires a real BT connection) by accepting conidx directly.
 * attr_idx is a 0-based index into s_gatt_attrs[] (NOT a BT handle);
 * attr->handle is always 0 when the BT stack is not running in unit tests.
 */

/**
 * @brief Test hook: simulate gatt_read_cb without a real BT connection.
 */
ssize_t at_cmd_gatt_test_gatt_read(uint8_t conidx, uint16_t attidx, void *buf, uint16_t buf_len,
				   uint16_t offset)
{
	if (!s_registered || attidx >= s_gatt_service.attr_count) {
		return -ENOENT;
	}

	/* attr->handle is 0 in unit tests (BT stack not running) */
	at_cmd_evt_gatt_from_ble(conidx, s_gatt_attrs[attidx].handle, AT_GATT_ACT_READ, NULL, 0);

	uint8_t *val = (attidx == s_char1v_idx) ? s_char1_val_buf : s_char2_val_buf;
	uint16_t vlen = (attidx == s_char1v_idx) ? s_char1_val_len : s_char2_val_len;

	if (offset > vlen) {
		return -EINVAL;
	}
	uint16_t copy_len = MIN(buf_len, vlen - offset);

	if (buf && copy_len) {
		memcpy(buf, val + offset, copy_len);
	}
	return (ssize_t)copy_len;
}

/**
 * @brief Test hook: simulate gatt_write_cb without a real BT connection.
 */
ssize_t at_cmd_gatt_test_gatt_write(uint8_t conidx, uint16_t attidx, const void *buf, uint16_t len,
				    uint8_t flags)
{
	if (!s_registered || attidx >= s_gatt_service.attr_count) {
		return -ENOENT;
	}

	/* attr->handle is 0 in unit tests (BT stack not running) */
	at_cmd_evt_gatt_from_ble(conidx, s_gatt_attrs[attidx].handle, AT_GATT_ACT_WRITE, buf, len);
	return (ssize_t)len;
}

/**
 * @brief Test hook: return the attribute index of a characteristic value.
 *
 * @param char_num 1 for Char1, 2 for Char2
 * @return attribute index, or UINT16_MAX if char_num is invalid
 */
uint16_t at_cmd_gatt_test_get_char_attidx(uint8_t char_num)
{
	if (char_num == AT_GATT_CHAR_NUM_1) {
		return s_char1v_idx;
	}
	if (char_num == AT_GATT_CHAR_NUM_2) {
		return s_char2v_idx;
	}
	return UINT16_MAX;
}
#endif /* CONFIG_ZTEST */
