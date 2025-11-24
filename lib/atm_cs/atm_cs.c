/**
 *******************************************************************************
 *
 * @file atm_cs.c
 *
 * @brief Atmosic Channel Sounding middleware
 *
 * Copyright (C) Atmosic 2025
 *
 *******************************************************************************
 */
#include <zephyr/bluetooth/bluetooth.h>
#include <zephyr/bluetooth/conn.h>
#include <zephyr/bluetooth/cs.h>
#include <zephyr/bluetooth/uuid.h>
#include <zephyr/logging/log.h>
#ifndef CONFIG_ATM_CS_ADV_BT_ID_DEFAULT
#include <zephyr/settings/settings.h>
#include "atm_settings.h"
#endif
#include "app_work_q.h"
#include "atm_cs.h"
#include "ras.h"

LOG_MODULE_REGISTER(atm_cs, CONFIG_ATM_CS_LOG_LEVEL);

/*
 * ============================================================================
 * Constants and Configuration
 * ============================================================================
 */

/* CS reflector configuration */
#define CS_REFLECTOR_ROLE_ENABLED    true
#define CS_INITIATOR_ROLE_ENABLED    false
#define CS_ANTENNA_SELECTION         BT_LE_CS_ANTENNA_SELECTION_OPT_REPETITIVE
#define CS_MAX_TX_POWER             BT_HCI_OP_LE_CS_MAX_MAX_TX_POWER

/*
 * ============================================================================
 * Static Variables
 * ============================================================================
 */

/* Current active connection for CS operations */
static struct bt_conn *cs_current_conn;
static K_MUTEX_DEFINE(cs_conn_mutex);

#ifndef CONFIG_ATM_CS_ADV_BT_ID_DEFAULT
#define ATM_CS_KEY_MAIN            SETTINGS_STORAGE_KEY("atm_cs")
#define ATM_CS_KEY_BT_ID           "bt_id"
#define ATM_CS_STORAGE_KEY(subkey) ATM_CS_KEY_MAIN "/" subkey

static uint8_t cs_adv_bt_id;
static bool cs_adv_bt_id_valid;

/* Forward declaration */
static uint8_t atm_cs_bt_id_get(void);

static void atm_cs_bt_id_save(uint8_t bt_id)
{
	cs_adv_bt_id = bt_id;
	int err = settings_save_one(ATM_CS_STORAGE_KEY(ATM_CS_KEY_BT_ID), (uint8_t *)&cs_adv_bt_id,
				    sizeof(cs_adv_bt_id));
	if (err) {
		LOG_ERR("save cs_adv_bt_id failed %d", err);
	}
	cs_adv_bt_id_valid = true;
}

static bool atm_cs_bt_id_valid(void)
{
	return cs_adv_bt_id_valid;
}

static int atm_cs_settings_storage_handle_set(char const *name, size_t len,
					      settings_read_cb read_cb, void *cb_arg)
{
	char const *next;
	if (settings_name_steq(name, ATM_CS_KEY_BT_ID, &next) && !next) {
		if (len != sizeof(cs_adv_bt_id)) {
			return -EINVAL;
		}
		read_cb(cb_arg, &cs_adv_bt_id, sizeof(cs_adv_bt_id));
		cs_adv_bt_id_valid = true;
		return 0;
	}
	return -ENOENT;
}
/* static subtree handler */
SETTINGS_STATIC_HANDLER_DEFINE(atm_cs_settings_storage, ATM_CS_KEY_MAIN, NULL,
			       atm_cs_settings_storage_handle_set, NULL, NULL);

static void atm_cs_bt_id_load(void)
{
	if (atm_cs_bt_id_valid()) {
		uint8_t bt_id = atm_cs_bt_id_get();
		LOG_INF("CS advertising on existing BT ID %u", bt_id);
		return;
	}
	LOG_INF("CS advertising on custom BT ID");
	int ret;
#ifdef CONFIG_ATM_CS_CUSTOM_BT_ADDR
	bt_addr_le_t addr;
	ret = bt_addr_le_from_str(CONFIG_ATM_CS_CUSTOM_BT_ADDR_VALUE, "random", &addr);
	if (ret) {
		LOG_ERR("Failed to parse custom BT address (err %d)", ret);
		return;
	}
	BT_ADDR_SET_STATIC(&addr.a);
	addr.type = BT_ADDR_LE_RANDOM;
	char addr_str[BT_ADDR_LE_STR_LEN];
	bt_addr_le_to_str(&addr, addr_str, sizeof(addr_str));
	LOG_INF("Custom BT address: %s", addr_str);
	ret = bt_id_create(&addr, NULL);
#else
	ret = bt_id_create(NULL, NULL);
#endif // CONFIG_ATM_CS_CUSTOM_BT_ADDR
	if (ret < 0) {
		LOG_ERR("Failed to create bt id (err: %d)", ret);
		return;
	}
	uint8_t bt_id = ret;
	LOG_INF("CS save custom BT ID [%u]", bt_id);
	atm_cs_bt_id_save(bt_id);
}
#endif // CONFIG_ATM_CS_ADV_BT_ID_DEFAULT

static uint8_t atm_cs_bt_id_get(void)
{
#ifdef CONFIG_ATM_CS_ADV_BT_ID_DEFAULT
	return BT_ID_DEFAULT;
#else
	if (!atm_cs_bt_id_valid()) {
		__ASSERT(0, "No valid BT ID loaded");
	}
	return cs_adv_bt_id;
#endif
}

/**
 * @brief Safely set the current CS connection
 * @param conn New connection (can be NULL to clear)
 */
static void cs_conn_set(struct bt_conn *conn)
{
	k_mutex_lock(&cs_conn_mutex, K_FOREVER);

	if (cs_current_conn && conn && cs_current_conn != conn) {
		/* Warn about replacing an active connection with a different one */
		char old_addr[BT_ADDR_LE_STR_LEN];
		char new_addr[BT_ADDR_LE_STR_LEN];
		bt_addr_le_to_str(bt_conn_get_dst(cs_current_conn), old_addr, sizeof(old_addr));
		bt_addr_le_to_str(bt_conn_get_dst(conn), new_addr, sizeof(new_addr));
		LOG_WRN("Replacing active CS connection %s with %s", old_addr, new_addr);
	}

	if (cs_current_conn) {
		bt_conn_unref(cs_current_conn);
	}

	cs_current_conn = conn ? bt_conn_ref(conn) : NULL;

	k_mutex_unlock(&cs_conn_mutex);
}

/**
 * @brief Safely get the current CS connection
 * @return Connection reference (caller must unref) or NULL
 */
static struct bt_conn *cs_conn_get(void)
{
	struct bt_conn *conn = NULL;

	k_mutex_lock(&cs_conn_mutex, K_FOREVER);

	if (cs_current_conn) {
		conn = bt_conn_ref(cs_current_conn);
	}

	k_mutex_unlock(&cs_conn_mutex);

	return conn;
}
/**
 * @brief Configure default CS settings for reflector role
 *
 * This function sets up the device as a CS reflector with optimal
 * antenna selection and maximum TX power.
 */
static void cs_configure_default_settings_work_handler(struct k_work *work)
{
	struct bt_conn *conn = cs_conn_get();
	if (!conn) {
		LOG_ERR("No active connection for CS configuration");
		return;
	}

	const struct bt_le_cs_set_default_settings_param default_settings = {
		.enable_initiator_role = CS_INITIATOR_ROLE_ENABLED,
		.enable_reflector_role = CS_REFLECTOR_ROLE_ENABLED,
		.cs_sync_antenna_selection = CS_ANTENNA_SELECTION,
		.max_tx_power = CS_MAX_TX_POWER,
	};

	int err = bt_le_cs_set_default_settings(conn, &default_settings);
	if (err) {
		LOG_ERR("Failed to configure default CS settings (err %d)", err);
	} else {
		LOG_INF("CS default settings configured successfully");
	}

	bt_conn_unref(conn);
}

static K_WORK_DEFINE(cs_configure_default_settings_work, cs_configure_default_settings_work_handler);


/**
 * @brief Validate if connection should be handled by CS
 *
 * @param conn Bluetooth connection to validate
 * @return true if connection should be processed, false otherwise
 */
static bool cs_connection_is_valid(struct bt_conn *conn)
{
	if (!conn) {
		return false;
	}

	struct bt_conn_info info;
	int err = bt_conn_get_info(conn, &info);
	if (err) {
		LOG_WRN("Failed to get connection info (err %d)", err);
		return false;
	}

	/* Only handle connections on ATM_CS BT ID for individual advertising */
	uint8_t bt_id = atm_cs_bt_id_get();
	if (info.id != bt_id) {
		LOG_DBG("Ignoring connection on BT ID %u (not %u)", info.id, bt_id);
		return false;
	}

	return true;
}




/**
 * @brief Handle Bluetooth connection terminated event
 *
 * @param conn Bluetooth connection
 * @param reason Disconnection reason code
 */
static void cs_connection_terminated_cb(struct bt_conn *conn, uint8_t reason)
{
	if (!cs_connection_is_valid(conn)) {
		LOG_DBG("Ignoring disconnection - not valid for CS");
		return;
	}

	char addr[BT_ADDR_LE_STR_LEN];
	bt_addr_le_to_str(bt_conn_get_dst(conn), addr, sizeof(addr));
	LOG_INF("CS reflector disconnected from %s (reason: 0x%02X)", addr, reason);

	/* Clear connection reference */
	cs_conn_set(NULL);

	/* Restart advertising after disconnection */
	atm_cs_rrsp_start_adv();
}

/* Bluetooth connection callbacks for CS operations */
BT_CONN_CB_DEFINE(cs_connection_callbacks) = {
	.disconnected = cs_connection_terminated_cb,
};

/*
 * ============================================================================
 * CS Individual Advertising Implementation
 * ============================================================================
 */

/* Advertising set handle for CS reflector */
static struct bt_le_ext_adv *cs_adv_set = NULL;

/* Scan response data for CS advertising */
static const struct bt_data cs_scan_response_data[] = {
	BT_DATA_BYTES(BT_DATA_UUID16_ALL, BT_UUID_16_ENCODE(BT_UUID_RAS_VAL)),
	BT_DATA_BYTES(BT_DATA_GAP_APPEARANCE, BT_UUID_16_ENCODE(CONFIG_BT_DEVICE_APPEARANCE)),
	BT_DATA(BT_DATA_NAME_COMPLETE, CONFIG_BT_DEVICE_NAME, sizeof(CONFIG_BT_DEVICE_NAME) - 1),
};

/* Advertisement data for CS advertising */
static const struct bt_data cs_advertisement_data[] = {
	BT_DATA_BYTES(BT_DATA_FLAGS, (BT_LE_AD_GENERAL | BT_LE_AD_NO_BREDR)),
	BT_DATA_BYTES(BT_DATA_UUID16_ALL, BT_UUID_16_ENCODE(BT_UUID_RAS_VAL)),
};

/**
 * @brief Handle advertising timeout/completion event
 *
 * @param instance Advertising set instance
 * @param info Advertising sent information
 */
static void cs_advertising_timeout_cb(struct bt_le_ext_adv *instance,
				      struct bt_le_ext_adv_sent_info *info)
{
	LOG_INF("CS advertising timeout - cleaning up advertising set");

	if (!cs_adv_set) {
		LOG_WRN("Advertising timeout callback called but no active advertising set");
		return;
	}

	/* Clean up advertising set */
	int err = bt_le_ext_adv_delete(cs_adv_set);
	if (err) {
		LOG_ERR("Failed to delete advertising set (err %d)", err);
	}
	cs_adv_set = NULL;
}

static void cs_advertising_connected(struct bt_le_ext_adv *instance,
				     struct bt_le_ext_adv_connected_info *info)
{
	if (!info || !info->conn) {
		LOG_ERR("Invalid connection info in advertising connected callback");
		return;
	}

	struct bt_conn *conn = info->conn;

	if (!cs_connection_is_valid(conn)) {
		LOG_DBG("Ignoring advertising connection - not valid for CS");
		return;
	}

	char addr[BT_ADDR_LE_STR_LEN];
	(void)bt_addr_le_to_str(bt_conn_get_dst(conn), addr, sizeof(addr));
	LOG_INF("CS advertising connected to %s", addr);

	/* Set connection reference (safely handles any existing connection) */
	cs_conn_set(conn);

	/* Schedule CS configuration in work queue context */
	int work_err = atm_work_submit_to_app_work_q(&cs_configure_default_settings_work);
	if (work_err < 0) {
		LOG_ERR("Failed to schedule CS configuration (err %d)", work_err);
		/* Keep connection reference - it will be cleaned up by connection callbacks */
	}
}

/* Advertising callbacks */
static struct bt_le_ext_adv_cb cs_advertising_callbacks = {
	.sent = cs_advertising_timeout_cb,
	.connected = cs_advertising_connected,
};

/**
 * @brief Start CS reflector advertising (work queue handler)
 *
 * Creates and starts extended advertising for CS reflector functionality.
 * Uses fast advertising intervals for quick discoverability.
 */
static void cs_start_advertising_work_handler(struct k_work *work)
{
	int err;

	/* Configure advertising parameters */
	struct bt_le_adv_param adv_param = *(BT_LE_ADV_PARAM(
		BT_LE_ADV_OPT_CONN,
		BT_GAP_ADV_FAST_INT_MIN_1,
		BT_GAP_ADV_FAST_INT_MAX_1,
		NULL));
	adv_param.id = atm_cs_bt_id_get();
	LOG_INF("CS reflector advertising on BT ID %u", adv_param.id);
	adv_param.options |= BT_LE_ADV_OPT_SCANNABLE;
#ifdef CONFIG_ATM_CS_CUSTOM_BT_ADDR
	adv_param.options |= BT_LE_ADV_OPT_USE_IDENTITY;
#endif
	/* Create advertising set if it doesn't exist */
	if (!cs_adv_set) {
		err = bt_le_ext_adv_create(&adv_param, &cs_advertising_callbacks, &cs_adv_set);
		if (err) {
			LOG_ERR("Failed to create CS advertising set (err %d)", err);
			return;
		}

		/* Set advertising and scan response data */
		err = bt_le_ext_adv_set_data(cs_adv_set,
					     cs_advertisement_data, ARRAY_SIZE(cs_advertisement_data),
					     cs_scan_response_data, ARRAY_SIZE(cs_scan_response_data));
		if (err) {
			LOG_ERR("Failed to set CS advertising data (err %d)", err);
			/* Clean up on failure */
			bt_le_ext_adv_delete(cs_adv_set);
			cs_adv_set = NULL;
			return;
		}
	}

	/* Configure advertising start parameters */
	struct bt_le_ext_adv_start_param start_param = {
		.timeout = CONFIG_ATM_CS_ADV_TIMEOUT_CS,
		.num_events = 0,
	};

	/* Start advertising */
	err = bt_le_ext_adv_start(cs_adv_set, &start_param);
	if (err) {
		LOG_ERR("Failed to start CS advertising (err %d)", err);
		return;
	}

	LOG_INF("CS reflector advertising started successfully (timeout: %d cs)",
		CONFIG_ATM_CS_ADV_TIMEOUT_CS);
}

static K_WORK_DEFINE(cs_start_advertising_work, cs_start_advertising_work_handler);

void atm_cs_rrsp_unpair(void)
{
	uint8_t bt_id = atm_cs_bt_id_get();
	LOG_INF("Unpairing CS reflector from BT ID %u", bt_id);

	int err = bt_unpair(bt_id, BT_ADDR_LE_ANY);
	if (err) {
		LOG_ERR("Failed to unpair BT ID %u (err %d)", bt_id, err);
		return;
	}
	LOG_INF("Successfully unpaired BT ID %u", bt_id);
}

void atm_cs_rrsp_init(void)
{
#ifndef CONFIG_ATM_CS_ADV_BT_ID_DEFAULT
	if (settings_load_subtree(ATM_CS_KEY_MAIN)) {
		LOG_ERR("Failed to load settings");
		return;
	}
	atm_cs_bt_id_load();
#endif
}

void atm_cs_rrsp_start_adv(void)
{
	LOG_DBG("Scheduling CS advertising start");
	int err = atm_work_submit_to_app_work_q(&cs_start_advertising_work);
	if (err < 0) {
		LOG_ERR("Failed to schedule CS advertising start (err %d)", err);
	}
}

void atm_cs_rrsp_stop_adv(void)
{
	if (!cs_adv_set) {
		LOG_DBG("No active CS advertising to stop");
		return;
	}

	int err = bt_le_ext_adv_stop(cs_adv_set);
	if (err) {
		LOG_ERR("Failed to stop CS advertising (err %d)", err);
	}

	err = bt_le_ext_adv_delete(cs_adv_set);
	if (err) {
		LOG_ERR("Failed to delete CS advertising set (err %d)", err);
	}

	cs_adv_set = NULL;
	LOG_INF("CS advertising stopped and cleaned up");
}
