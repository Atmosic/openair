/**
 *******************************************************************************
 *
 * @file dult.c
 *
 * @brief Atmosic Detecting Unwanted Location Trackers (DULT) Middleware
 *
 * Copyright (C) Atmosic 2025
 *
 *******************************************************************************
 */

#include <errno.h>
#include <zephyr/kernel.h>
#include <zephyr/bluetooth/bluetooth.h>
#include <zephyr/bluetooth/gatt.h>
#include <zephyr/bluetooth/uuid.h>
#include <zephyr/sys/byteorder.h>
#include <zephyr/logging/log.h>
#include "app_work_q.h"
#include "atm_utils_c.h"
#include "dult.h"
#include "dult_adv.h"

LOG_MODULE_REGISTER(dult, CONFIG_ATM_DULT_LOG_LEVEL);

static void dult_sound_play_timer_handler(struct k_work *work);
static void dult_dult_read_id_timer_handler(struct k_work *work);
K_WORK_DELAYABLE_DEFINE(dult_sound_play_timer, dult_sound_play_timer_handler);
K_WORK_DELAYABLE_DEFINE(dult_read_id_timer, dult_dult_read_id_timer_handler);

static dult_mode_t cur_no_mode;
static dult_hdlrs_t const *dult_hdlrs;
static dult_user_info_t const *dult_user_info;

// DULT Service Near Owner Response
typedef struct ble_dult_no_resp_s {
	uint16_t resp_opcode;
	uint8_t data[__ARRAY_EMPTY];
} __packed ble_dult_no_resp_t;

typedef struct dult_ind_data_s {
	struct bt_conn *conn;
	const struct bt_gatt_attr *attr;
	void *p_ind_data;
	uint16_t data_len;
	struct k_work work;
} dult_ind_data_t;

// DULT opcodes for Accessory Information writes
enum dult_info_write_opcode {
	DULT_INFO_WRITE_OPCODE_GET_PRODUCT_DATA = 0x003,
	DULT_INFO_WRITE_OPCODE_GET_MANUFACTURER_NAME = 0x004,
	DULT_INFO_WRITE_OPCODE_GET_MODEL_NAME = 0x005,
	DULT_INFO_WRITE_OPCODE_GET_ACCESSORY_CATEGORY = 0x006,
	DULT_INFO_WRITE_OPCODE_GET_PROTOCOL_IMPLEMENTATION_VERSION = 0x007,
	DULT_INFO_WRITE_OPCODE_GET_ACCESSORY_CAPABILITIES = 0x008,
	DULT_INFO_WRITE_OPCODE_GET_NETWORK_ID = 0x009,
	DULT_INFO_WRITE_OPCODE_GET_FIRMWARE_VERSION = 0x00A,
	DULT_INFO_WRITE_OPCODE_GET_BATTERY_TYPE = 0x00B,
	DULT_INFO_WRITE_OPCODE_GET_BATTERY_LEVEL = 0x00C,
};

// DULT opcodes for Non-owner control writes
enum dult_ctrl_write_opcode {
	DULT_CTRL_WRITE_OPCODE_SOUND_START = 0x300,
	DULT_CTRL_WRITE_OPCODE_SOUND_STOP = 0x301,
	DULT_CTRL_WRITE_OPCODE_GET_ID = 0x404,
};

#define DULT_INFO_RESPONSE_OPCODE(dult_info_write_opcode) (0x800 | (dult_info_write_opcode))

// DULT opcodes for Non-owner control indications
enum dult_ctrl_response_opcode {
	DULT_CTRL_RESPONSE_OPCODE_COMMAND = 0x302,
	DULT_CTRL_RESPONSE_OPCODE_SOUND_COMPLETED = 0x303,
	DULT_CTRL_RESPONSE_OPCODE_GET_ID = 0x405,
};

// DULT command response status
enum dult_cmd_response_status {
	DULT_CMD_RESPONSE_STATUS_SUCCESS = 0x0000,
	DULT_CMD_RESPONSE_STATUS_INVALID_STATE = 0x0001,
	DULT_CMD_RESPONSE_STATUS_INVALID_CONFIGURATION = 0x0002,
	DULT_CMD_RESPONSE_STATUS_INVALID_LENGTH = 0x0003,
	DULT_CMD_RESPONSE_STATUS_INVALID_PARAM = 0x0004,
	DULT_CMD_RESPONSE_STATUS_INVALID_COMMAND = 0xFFFF,
};

static ssize_t dult_write_handler(struct bt_conn *conn, const struct bt_gatt_attr *attr,
				  const void *buf, uint16_t len, uint16_t offset, uint8_t flags);

// Accessory non-owner GATT service UUIDs defined by the DULT specification
#define DULT_NON_OWNER_SERVICE                                                                     \
	BT_UUID_DECLARE_128(BT_UUID_128_ENCODE(0x15190001, 0x12F4, 0xC226, 0x88ED, 0x2AC5579F2A85))
#define DULT_NON_OWNER_CHARACTERISTIC                                                              \
	BT_UUID_DECLARE_128(BT_UUID_128_ENCODE(0x8E0C0001, 0x1D68, 0xFB92, 0xBF61, 0x48377421680E))

BT_GATT_SERVICE_DEFINE(dult_svc, BT_GATT_PRIMARY_SERVICE(DULT_NON_OWNER_SERVICE),
		       BT_GATT_CHARACTERISTIC(DULT_NON_OWNER_CHARACTERISTIC,
					      BT_GATT_CHRC_WRITE | BT_GATT_CHRC_INDICATE,
					      BT_GATT_PERM_WRITE, NULL, dult_write_handler, NULL),
		       BT_GATT_CCC(NULL, BT_GATT_PERM_READ | BT_GATT_PERM_WRITE), );

#define SLAB_ALIGN            4
#define DULT_INDICATION_COUNT 2
#define SLAB_BLOCK_SIZE       ROUND_UP(sizeof(struct bt_gatt_indicate_params), SLAB_ALIGN)
K_MEM_SLAB_DEFINE_STATIC(indicate_params_slab, SLAB_BLOCK_SIZE, DULT_INDICATION_COUNT, SLAB_ALIGN);

static void dult_indicate_params_destroy_cb(struct bt_gatt_indicate_params *params)
{
	k_mem_slab_free(&indicate_params_slab, params);
	LOG_DBG("Indicate params destroy callback");
}

static bool dult_is_mtu_sufficient(struct bt_conn *conn, uint16_t data_len)
{
	static const size_t att_header_len = 3;
	uint16_t mtu = bt_gatt_get_mtu(conn);

	return (data_len + att_header_len) <= mtu;
}

static int dult_gatt_indicate(struct bt_conn *conn, const struct bt_gatt_attr *attr,
			      const void *data, uint16_t data_len)
{
	struct bt_gatt_indicate_params *indicate_params;

	if (!dult_is_mtu_sufficient(conn, data_len)) {
		LOG_WRN("Too small MTU to send GATT indication");
		return -EINVAL;
	}

	int err = k_mem_slab_alloc(&indicate_params_slab, (void **)&indicate_params, K_NO_WAIT);
	if (err) {
		LOG_ERR("Failed to allocate memory slab: err=%d", err);
		return -ENOMEM;
	}

	*indicate_params = (struct bt_gatt_indicate_params){
		.uuid = NULL,
		.attr = attr,
		.func = NULL,
		.destroy = dult_indicate_params_destroy_cb,
		.data = data,
		.len = data_len,
	};

	err = bt_gatt_indicate(conn, indicate_params);
	if (err) {
		k_mem_slab_free(&indicate_params_slab, indicate_params);
		LOG_ERR("Failed to send GATT indication: err=%d", err);
		return err;
	}
	LOG_HEXDUMP_DBG(data, data_len, "dult_gatt_indicate:");
	return 0;
}

static void *dult_safe_malloc(size_t m_size)
{
	void *data = k_malloc(m_size);
	__ASSERT(data, "malloc data failed");
	memset(data, 0, m_size);
	return data;
}

typedef struct {
	struct bt_conn *conn;
} sound_ind_info_t;
static sound_ind_info_t *sound_info;

static struct bt_gatt_attr *dult_gatt_get_attr(const struct bt_uuid *uuid)
{
	return bt_gatt_find_by_uuid(dult_svc.attrs, dult_svc.attr_count, uuid);
}

static void dult_gatt_sound_play_complete_ind_send(struct k_work *work)
{
	if (!sound_info) {
		LOG_INF("Ignore send sound play complete indicate");
		return;
	}
	LOG_INF("Send sound play complete indicate");
	uint8_t *data = dult_safe_malloc(sizeof(uint16_t));
	atm_set_be16(data, DULT_CTRL_RESPONSE_OPCODE_SOUND_COMPLETED);
	dult_gatt_indicate(sound_info->conn, dult_gatt_get_attr(DULT_NON_OWNER_CHARACTERISTIC),
			   data, sizeof(uint16_t));
	k_free(sound_info);
	sound_info = NULL;
}
K_WORK_DEFINE(dult_gatt_sound_play_complete_ind, dult_gatt_sound_play_complete_ind_send);

uint8_t dult_play_cnt;
#define DULT_PLAY_COUNT_MAX 10
static void dult_sound_play_timer_handler(struct k_work *work)
{
	bool sound_play = (!k_work_delayable_busy_get(&dult_sound_play_timer));
	if (sound_play && dult_play_cnt < DULT_PLAY_COUNT_MAX) {
		LOG_DBG("Play sound count (%u)", dult_play_cnt);
		atm_work_reschedule_for_app_work_q(&dult_sound_play_timer,
						   K_SECONDS(DULT_PLAY_SOUND_INT_SEC));
		dult_play_cnt++;
	} else {
		if (sound_play) {
			LOG_INF("Play sound exceed max count %d, stop play", DULT_PLAY_COUNT_MAX);
		}
		k_work_cancel_delayable(&dult_sound_play_timer);
		dult_play_cnt = 0;
		atm_work_submit_to_app_work_q(&dult_gatt_sound_play_complete_ind);
	}
}

static void dult_sound_play_invoke_update(struct k_work *work)
{
	bool sound_play;
	dult_play_cnt = 0;
	if (k_work_delayable_busy_get(&dult_sound_play_timer)) {
		LOG_INF("Disable sound play");
		k_work_cancel_delayable(&dult_sound_play_timer);
		LOG_DBG("To Send sound play complete indicate");
		atm_work_submit_to_app_work_q(&dult_gatt_sound_play_complete_ind);
		sound_play = false;
	} else {
		LOG_INF("Enable sound play");
		atm_work_reschedule_for_app_work_q(&dult_sound_play_timer,
						   K_SECONDS(DULT_PLAY_SOUND_INT_SEC));
		sound_play = true;
	}
	if (dult_hdlrs->sound_action_cb) {
		dult_hdlrs->sound_action_cb(sound_play);
	}
}
K_WORK_DEFINE(dult_sound_play_update, dult_sound_play_invoke_update);

static void dult_dult_read_id_timer_handler(struct k_work *work)
{
	LOG_WRN("Read ID Timeout");
}

static void dult_read_id_update(bool en)
{
	if (en) {
		LOG_INF("Enable Read ID in %d mimutes", DULT_READ_ID_INT_MIN);
		atm_work_reschedule_for_app_work_q(&dult_read_id_timer,
						   K_MINUTES(DULT_READ_ID_INT_MIN));
	} else {
		LOG_DBG("Cancel Read ID timer");
		k_work_cancel_delayable(&dult_read_id_timer);
	}
}

static int dult_cmd_resp_send(struct bt_conn *conn, struct bt_gatt_attr const *attr,
			      uint16_t opcode, enum dult_cmd_response_status status)
{
	uint16_t response_status = status;
	static const size_t cmd_response_operand_len = sizeof(opcode) + sizeof(response_status);
	NET_BUF_SIMPLE_DEFINE(buf, cmd_response_operand_len);
	net_buf_simple_add_le16(&buf, opcode);
	net_buf_simple_add_le16(&buf, response_status);

	return dult_gatt_indicate(conn, attr, buf.data, buf.len);
}

static ssize_t dult_write_err_handle(struct bt_conn *conn, const struct bt_gatt_attr *attr,
				     uint16_t opcode, uint16_t write_len, int err)
{
	ssize_t res = write_len;

	if (err) {
		LOG_WRN("Handling command failed: err=%d (Accessory non-owner write)", err);
		if (err == -ENOMEM) {
			LOG_WRN("No more indication buffers available "
				"(Accessory non-owner write)");
			// Not sending Command Response to not overload indication buffer
		} else if (err == -ENOTSUP) {
			LOG_WRN("Opcode not supported on accessory side: opcode=%#05X (Accessory "
				"non-owner write)",
				opcode);
			err = dult_cmd_resp_send(conn, attr, opcode,
						 DULT_CMD_RESPONSE_STATUS_INVALID_COMMAND);
		}
	}

	if (err) {
		if (err == -ENOMEM) {
			res = BT_GATT_ERR(BT_ATT_ERR_INSUFFICIENT_RESOURCES);
		} else {
			res = BT_GATT_ERR(BT_ATT_ERR_UNLIKELY);
		}
	}
	return res;
}

static dult_battery_level_t dult_get_battery_level(void)
{
	uint8_t battery_percentage = DULT_BATTERY_LEVEL_NONE;
	if (dult_hdlrs->battery_status_cb) {
		battery_percentage = dult_hdlrs->battery_status_cb();
	}
	if (battery_percentage == DULT_BATTERY_LEVEL_NONE) {
		return DULT_BATTERY_LEVEL_NOT_SUPPORT;
	}
	if (battery_percentage <= 10) {
		return DULT_BATTERY_LEVEL_CRITICAL;
	} else if (battery_percentage <= 30) {
		return DULT_BATTERY_LEVEL_LOW;
	} else if (battery_percentage <= 70) {
		return DULT_BATTERY_LEVEL_NORMAL;
	} else {
		return DULT_BATTERY_LEVEL_FULL;
	}
}

static ssize_t dult_write_handler(struct bt_conn *conn, const struct bt_gatt_attr *attr,
				  const void *buf, uint16_t len, uint16_t offset, uint8_t flags)
{
	ssize_t res = len;
	uint16_t opcode;
	int err = 0;

	if (offset != 0) {
		LOG_WRN("Invalid offset: off=%" PRIu16 " (dult gatt write)", offset);
		res = BT_GATT_ERR(BT_ATT_ERR_INVALID_OFFSET);
		return res;
	}

	if (len != sizeof(opcode)) {
		LOG_WRN("Invalid length: len=%" PRIu16 " (dult gatt write)", len);
		res = BT_GATT_ERR(BT_ATT_ERR_INVALID_ATTRIBUTE_LEN);
		return res;
	}

	opcode = sys_get_le16(buf);
	LOG_DBG("Received opcode: %" PRIu16 " (dult gatt write)", opcode);
	if (cur_no_mode != DULT_NO_MODE_SEPERATED) {
		LOG_WRN("Invalid near-owner state mode: mode=%u "
			"(Accessory non-owner write)",
			cur_no_mode);
		res = dult_cmd_resp_send(conn, attr, opcode,
					 DULT_CMD_RESPONSE_STATUS_INVALID_COMMAND);
		return res;
	}
	ble_dult_no_resp_t *resp = NULL;
	uint16_t data_len = 0;
	switch (opcode) {
	case DULT_INFO_WRITE_OPCODE_GET_PRODUCT_DATA:
		data_len = DULT_PRODUCT_DATA_LEN;
		resp = dult_safe_malloc(sizeof(ble_dult_no_resp_t) + data_len);
		memset(resp->data, 0, DULT_PRODUCT_DATA_LEN);
		uint8_t offset = DULT_PRODUCT_DATA_LEN - dult_user_info->model_id_len;
		memcpy(resp->data + offset, dult_user_info->model_id, dult_user_info->model_id_len);
		break;

	case DULT_INFO_WRITE_OPCODE_GET_MANUFACTURER_NAME:
		data_len = sizeof(CONFIG_DULT_MANUFACTURER_NAME) - 1;
		resp = dult_safe_malloc(sizeof(ble_dult_no_resp_t) + data_len);
		memcpy(resp->data, CONFIG_DULT_MANUFACTURER_NAME,
		       sizeof(CONFIG_DULT_MANUFACTURER_NAME) - 1);
		break;

	case DULT_INFO_WRITE_OPCODE_GET_MODEL_NAME:
		data_len = sizeof(CONFIG_DULT_MODEL_NAME) - 1;
		resp = dult_safe_malloc(sizeof(ble_dult_no_resp_t) + data_len);
		memcpy(resp->data, CONFIG_DULT_MODEL_NAME, sizeof(CONFIG_DULT_MODEL_NAME) - 1);
		break;

	case DULT_INFO_WRITE_OPCODE_GET_ACCESSORY_CATEGORY:
		data_len = DULT_CATEGORY_LEN;
		resp = dult_safe_malloc(sizeof(ble_dult_no_resp_t) + data_len);
		resp->data[0] = CONFIG_DULT_ACCESSORY_CATEGORY_TYPE;
		break;

	case DULT_INFO_WRITE_OPCODE_GET_PROTOCOL_IMPLEMENTATION_VERSION:
		uint32_t version = CONFIG_DULT_PROTOCOL_IMPLEMENTATION_VERSION;
		data_len = sizeof(version);
		resp = dult_safe_malloc(sizeof(ble_dult_no_resp_t) + data_len);
		memcpy(resp->data, &version, sizeof(version));
		break;

	case DULT_INFO_WRITE_OPCODE_GET_ACCESSORY_CAPABILITIES:
		uint32_t capability = CONFIG_DULT_ACCESSORY_CAPABILITIES;
		data_len = sizeof(capability);
		resp = dult_safe_malloc(sizeof(ble_dult_no_resp_t) + data_len);
		atm_set_le32(resp->data, capability);
		break;

	case DULT_INFO_WRITE_OPCODE_GET_NETWORK_ID:
		data_len = sizeof(uint8_t);
		resp = dult_safe_malloc(sizeof(ble_dult_no_resp_t) + data_len);
		resp->data[0] = CONFIG_DULT_NETWORK_ID;
		break;

	case DULT_INFO_WRITE_OPCODE_GET_FIRMWARE_VERSION:
		data_len = DULT_VER_LEN;
		resp = dult_safe_malloc(sizeof(ble_dult_no_resp_t) + data_len);
		/*
		 * Byte 0: revision version number
		 * Byte 1: minor version number
		 * Byte 2-3: major version number
		 */
		resp->data[0] = CONFIG_DULT_FIRMWARE_VERSION_REVISION;
		resp->data[1] = CONFIG_DULT_FIRMWARE_VERSION_MINOR;
		atm_set_be16(&resp->data[2], CONFIG_DULT_FIRMWARE_VERSION_MAJOR);
		break;

	case DULT_INFO_WRITE_OPCODE_GET_BATTERY_TYPE:
		data_len = sizeof(uint8_t);
		resp = dult_safe_malloc(sizeof(ble_dult_no_resp_t) + data_len);
		resp->data[0] = CONFIG_DULT_BATTERY_TYPE;
		break;

	case DULT_INFO_WRITE_OPCODE_GET_BATTERY_LEVEL:
		data_len = sizeof(uint8_t);
		resp = dult_safe_malloc(sizeof(ble_dult_no_resp_t) + data_len);
		resp->data[0] = dult_get_battery_level();
		break;

	case DULT_CTRL_WRITE_OPCODE_SOUND_START:
		uint16_t state;
		data_len = sizeof(opcode) + sizeof(state);
		resp = dult_safe_malloc(sizeof(ble_dult_no_resp_t) + data_len);
		memcpy(resp->data, &opcode, sizeof(opcode));
		if (k_work_delayable_busy_get(&dult_sound_play_timer)) {
			LOG_INF("Sound has already started");
			state = DULT_CMD_RESPONSE_STATUS_INVALID_STATE;
		} else {
			sound_info = k_malloc(sizeof(sound_ind_info_t));
			__ASSERT(sound_info, "malloc sound_info failed");
			sound_info->conn = conn;
			atm_work_submit_to_app_work_q(&dult_sound_play_update);
			state = DULT_CMD_RESPONSE_STATUS_SUCCESS;
		}
		memcpy(resp->data + sizeof(opcode), &state, sizeof(state));
		break;

	case DULT_CTRL_WRITE_OPCODE_SOUND_STOP:
		if (!k_work_delayable_busy_get(&dult_sound_play_timer)) {
			LOG_INF("Sound does not start");
			uint16_t state = DULT_CMD_RESPONSE_STATUS_INVALID_STATE;
			data_len = sizeof(opcode) + sizeof(state);
			resp = dult_safe_malloc(sizeof(ble_dult_no_resp_t) + data_len);
			memcpy(resp->data, &opcode, sizeof(opcode));
			memcpy(resp->data + sizeof(opcode), &state, sizeof(state));
		} else {
			atm_work_submit_to_app_work_q(&dult_sound_play_update);
		}
		break;

	case DULT_CTRL_WRITE_OPCODE_GET_ID:
		if (!k_work_delayable_busy_get(&dult_read_id_timer) ||
		    !dult_hdlrs->dult_get_id_cb) {
			LOG_INF("Read ID not enabled");
			resp = dult_safe_malloc(sizeof(ble_dult_no_resp_t));
		} else {
			uint8_t id[DULT_DATA_LEN];
			data_len = dult_hdlrs->dult_get_id_cb(id);
			dult_read_id_update(false);
			resp = dult_safe_malloc(sizeof(ble_dult_no_resp_t) + data_len);
			memcpy(resp->data, id, data_len);
			atm_set_le16(&resp->resp_opcode, DULT_CTRL_RESPONSE_OPCODE_GET_ID);
		}
		break;

	default:
		LOG_WRN("Unknown opcode  %#x", opcode);
	}
	if (resp) {
		if (opcode < DULT_CTRL_WRITE_OPCODE_SOUND_START) {
			atm_set_le16(&resp->resp_opcode, DULT_INFO_RESPONSE_OPCODE(opcode));
		} else {
			if (opcode == DULT_CTRL_WRITE_OPCODE_GET_ID) {
				atm_set_le16(&resp->resp_opcode, DULT_CTRL_RESPONSE_OPCODE_GET_ID);
			} else {
				atm_set_le16(&resp->resp_opcode, DULT_CTRL_RESPONSE_OPCODE_COMMAND);
			}
		}
		data_len += sizeof(opcode);
		err = dult_gatt_indicate(conn, attr, resp, data_len);
		k_free(resp);
	}
	return dult_write_err_handle(conn, attr, opcode, len, err);
}

int dult_init(void)
{
	LOG_DBG("start");
	return 0;
}

void dult_deinit(void)
{
	k_work_cancel_delayable(&dult_sound_play_timer);
	k_work_cancel_delayable(&dult_read_id_timer);
}

void dult_reset(void)
{
	dult_deinit();
	cur_no_mode = DULT_NO_MODE_NEAR_OWNER;
}

void dult_enable(bool en)
{
	if (!en) {
		dult_reset();
		dult_adv_disable();
		return;
	}
	cur_no_mode = DULT_NO_MODE_SEPERATED;
	dult_adv_enable(cur_no_mode);
}

void dult_mode_update(dult_mode_t mode)
{
	LOG_DBG("Update Near Owner mode from %u to %u", cur_no_mode, mode);
	if (cur_no_mode != DULT_NO_MODE_SEPERATED) {
		dult_enable(false);
	}
}

void dult_read_id_enable(void)
{
	if (!k_work_delayable_busy_get(&dult_read_id_timer) &&
	    (cur_no_mode == DULT_NO_MODE_SEPERATED)) {
		dult_read_id_update(true);
	}
}

void dult_handlers_register(dult_hdlrs_t const *hdlrs, dult_user_info_t const *user_info,
			    uint8_t bt_id)
{
	dult_hdlrs = hdlrs;
	dult_user_info = user_info;
	dult_adv_bt_id_set(bt_id);
}
