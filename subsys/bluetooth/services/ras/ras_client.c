/*
 * Copyright (c) 2025 Atmosic
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/sys/check.h>
#include <zephyr/logging/log.h>

#include <zephyr/bluetooth/bluetooth.h>
#include <zephyr/bluetooth/conn.h>
#include <zephyr/bluetooth/gatt.h>

#include "ras.h"
#include "ras_internal.h"
#include "app_work_q.h"

LOG_MODULE_REGISTER(bt_ras_client, CONFIG_BT_RAS_CLIENT_LOG_LEVEL);

enum ras_char {
	RAS_CHARC_RAS_FEATURES,
	RAS_CHARC_REALTIME_RANGING_DATA,
	RAS_CHARC_ONDEMAND_RANGING_DATA,
	RAS_CHARC_CP,
	RAS_CHARC_RANGING_DATA_READY,
	RAS_CHARC_RANGING_DATA_OVERWRITTEN,

	RAS_CHARC_MAX_NUM
};

#define RAS_CHARC_MANDATORY_MASK                                                                   \
	(BIT(RAS_CHARC_RAS_FEATURES) | BIT(RAS_CHARC_ONDEMAND_RANGING_DATA) | BIT(RAS_CHARC_CP) |  \
	 BIT(RAS_CHARC_RANGING_DATA_READY) | BIT(RAS_CHARC_RANGING_DATA_OVERWRITTEN))
#define RAS_CHARC_CCC_MANDATORY_MASK                                                               \
	((BIT(RAS_CHARC_ONDEMAND_RANGING_DATA) | BIT(RAS_CHARC_CP) |                               \
	  BIT(RAS_CHARC_RANGING_DATA_READY) | BIT(RAS_CHARC_RANGING_DATA_OVERWRITTEN)))
#define RAS_CHARC_CCC_MASK                                                                         \
	(BIT(RAS_CHARC_REALTIME_RANGING_DATA) | BIT(RAS_CHARC_ONDEMAND_RANGING_DATA) |             \
	 BIT(RAS_CHARC_CP) | BIT(RAS_CHARC_RANGING_DATA_READY) |                                   \
	 BIT(RAS_CHARC_RANGING_DATA_OVERWRITTEN))

// segment number: 0-63
#define SEGMENT_COUNT_BITS      6
// timeout for no next segment received
#define RECV_RD_SEG_TIMEOUT_SEC 1

enum seg_bit {
	FIRST_SEGMENT,
	LAST_SEGMENT,
	SEGMENT_COUNT_START,
};

enum ras_c_state {
	RAS_C_STATE_NONE,
	RAS_C_STATE_DISCOVERY,
	RAS_C_STATE_READ_FEATURES_DONE,
	RAS_C_STATE_ON_DEMAND_MODE,
	RAS_C_STATE_GET_RANGING_DATA,
#ifdef CONFIG_RAS_CLIENT_REAL_TIME_RD
	RAS_C_STATE_REALTIME_MODE,
#endif
};

struct bt_ras_client {
	struct bt_gatt_subscribe_params subscribe_params[RAS_CHARC_MAX_NUM];
	bt_ras_client_ranging_data_ready_cb rd_ready_cb;
	bt_ras_client_ranging_data_overwritten_cb rd_overwritten_cb;
	// will clean up below parameters when disconnected
	struct bt_gatt_discover_params discover;
	bt_ras_client_get_ranging_data_cmpl_cb get_rd_cmpl_cb;
	int err_status;
	struct net_buf_simple *ondemand_buf_out;
	struct bt_conn *conn;
	struct k_work_delayable timeout_work;
#ifdef CONFIG_RAS_CLIENT_REAL_TIME_RD
	bt_ras_client_get_realtime_ranging_data_cmpl_cb get_realtime_rd_cmpl_cb;
	struct net_buf_simple *realtime_buf_out;
#endif
	uint32_t ras_features;
	uint16_t ranging_counter;
	uint8_t next_seg_cnt;
	enum ras_c_state state;
	bool last_seg;
	uint8_t char_prop[RAS_CHARC_MAX_NUM];
	bool cs_enabled;
};

static const struct bt_ras_client_cb *ras_c_cb;
static struct bt_ras_client ras_c_list[CONFIG_BT_MAX_CONN];

static const struct bt_uuid *ras_uuid = BT_UUID_RAS;
static const struct bt_uuid *ras_charc_uuids[RAS_CHARC_MAX_NUM] = {
	BT_UUID_RAS_FEATURES, BT_UUID_RAS_REALTIME_RD, BT_UUID_RAS_ONDEMAND_RD,
	BT_UUID_RAS_CP,       BT_UUID_RAS_RD_READY,    BT_UUID_RAS_RD_OVERWRITTEN};

#ifdef CONFIG_RAS_CLIENT_REAL_TIME_RD
static void ras_c_realtime_rd_cmpl(struct bt_ras_client *ras_c, int err)
{
	ras_c->err_status = 0;
	ras_c->last_seg = 0;
	ras_c->next_seg_cnt = 0;
	if (err) {
		if (ras_c->realtime_buf_out->len >= sizeof(ras_rd_header_t)) {
			ras_rd_header_t *rd_hdr = (void *)ras_c->realtime_buf_out->data;
			LOG_INF("realtime rc:%u len:%u", rd_hdr->ranging_counter,
				ras_c->realtime_buf_out->len);
		} else {
			LOG_WRN("realtime invalid len:%u", ras_c->realtime_buf_out->len);
		}
	}
	if (ras_c->get_realtime_rd_cmpl_cb) {
		ras_c->get_realtime_rd_cmpl_cb(ras_c->conn, err);
	}
}
#endif

static void timeout_work_handler(struct k_work *work)
{
	struct bt_ras_client *ras_c =
		CONTAINER_OF((struct k_work_delayable *)work, struct bt_ras_client, timeout_work);
	LOG_DBG("timeout state:%u", ras_c->state);
	int err;
	if (ras_c->state == RAS_C_STATE_ON_DEMAND_MODE) {
		if (!ras_c->rd_ready_cb) {
			return;
		}
		ras_c->rd_ready_cb(ras_c->conn, 0, -ETIMEDOUT);
	} else if (ras_c->state == RAS_C_STATE_GET_RANGING_DATA) {
		ras_c->state = RAS_C_STATE_ON_DEMAND_MODE;
		if (ras_c->ras_features & RAS_FEAT_ABORT_OP) {
			NET_BUF_SIMPLE_DEFINE(abort_buf, RAS_CP_OPCODE_LEN);
			net_buf_simple_add_u8(&abort_buf, RAS_CP_CMD_OPCODE_ABORT_OP);
			err = bt_gatt_write_without_response(
				ras_c->conn, ras_c->subscribe_params[RAS_CHARC_CP].value_handle,
				abort_buf.data, abort_buf.len, false);
			if (err) {
				LOG_ERR("abort err:%d", err);
			}
		}
		if (ras_c->get_rd_cmpl_cb) {
			ras_c->get_rd_cmpl_cb(ras_c->conn, ras_c->ranging_counter, -ETIMEDOUT);
		}
#ifdef CONFIG_RAS_CLIENT_REAL_TIME_RD
	} else if (ras_c->state == RAS_C_STATE_REALTIME_MODE) {
		err = bt_gatt_unsubscribe(
			ras_c->conn, &ras_c->subscribe_params[RAS_CHARC_REALTIME_RANGING_DATA]);
		if (err) {
			LOG_ERR("unsubscribe err:%d", err);
		} else {
			ras_c->state = RAS_C_STATE_READ_FEATURES_DONE;
		}
		ras_c_realtime_rd_cmpl(ras_c, -ETIMEDOUT);
#endif
	}
}

static uint8_t ras_c_get_handle_idx(const struct bt_uuid *uuid)
{
	for (uint8_t i = 0; i < RAS_CHARC_MAX_NUM; i++) {
		if (!bt_uuid_cmp(uuid, ras_charc_uuids[i])) {
			LOG_DBG("hdl_idx %u", i);
			return i;
		}
	}
	return RAS_CHARC_MAX_NUM;
}

static struct bt_ras_client *ras_c_by_conn(const struct bt_conn *conn)
{
	if (!conn) {
		return NULL;
	}
	uint8_t conn_idx = bt_conn_index(conn);
	if (conn_idx >= CONFIG_BT_MAX_CONN) {
		LOG_ERR("invalid conn_idx:%u", conn_idx);
		return NULL;
	}
	return &ras_c_list[conn_idx];
}

static struct bt_ras_client *ras_c_by_conn_state(const struct bt_conn *conn, enum ras_c_state state)
{
	struct bt_ras_client *ras_c = ras_c_by_conn(conn);
	if (!ras_c || (ras_c->state < state)) {
		if (ras_c) {
			LOG_WRN("wrong state:%u %u", ras_c->state, state);
		}
		return NULL;
	}
	return ras_c;
}

static void ras_c_cleanup(struct bt_ras_client *ras_c)
{
	if (!ras_c) {
		return;
	}
	struct k_work_sync sync;
	k_work_cancel_delayable_sync(&ras_c->timeout_work, &sync);
	// not cleanup subscribe_params for calling the notify callback when unpair
	memset(&ras_c->discover, 0,
	       sizeof(struct bt_ras_client) - offsetof(struct bt_ras_client, discover));
}

static void ras_c_disconnected(struct bt_conn *conn, uint8_t reason)
{
	struct bt_ras_client *ras_c = ras_c_by_conn(conn);
	if (!ras_c) {
		return;
	}
	if (ras_c->state == RAS_C_STATE_GET_RANGING_DATA) {
		LOG_INF("disconn getting rd rc:%u", ras_c->ranging_counter);
		if (ras_c->get_rd_cmpl_cb) {
			ras_c->get_rd_cmpl_cb(conn, ras_c->ranging_counter, -ENOTCONN);
		}
	}
#ifdef CONFIG_RAS_CLIENT_REAL_TIME_RD
	else if (ras_c->state == RAS_C_STATE_REALTIME_MODE) {
		ras_c_realtime_rd_cmpl(ras_c, -ENOTCONN);
	}
#endif
	ras_c_cleanup(ras_c);
}

static void ras_c_cs_procedure_enabled(struct bt_conn *conn, uint8_t status,
				       struct bt_conn_le_cs_procedure_enable_complete *params)
{
	struct bt_ras_client *ras_c = ras_c_by_conn(conn);
	if (!ras_c) {
		return;
	}
	if (params->state) {
		ras_c->cs_enabled = true;
	} else {
		ras_c->cs_enabled = false;
	}

	atm_work_reschedule_for_app_work_q(
		&ras_c->timeout_work,
		K_SECONDS(CONFIG_RAS_CLIENT_RECEIVE_RANGING_DATA_TIMEOUT_SEC));
}

BT_CONN_CB_DEFINE(conn_cb) = {
	.disconnected = ras_c_disconnected,
	.le_cs_procedure_enable_complete = ras_c_cs_procedure_enabled,
};

static void ras_c_subscribe(struct bt_conn *conn, uint8_t err,
			    struct bt_gatt_subscribe_params *params)
{
	LOG_DBG("Subscribe to ccc_handle:%u err:%d", params->ccc_handle, err);
}

static uint8_t ras_c_rd_ready_ow_notify(struct bt_conn *conn,
					struct bt_gatt_subscribe_params *params, const void *data,
					uint16_t length)
{
	if (!data) {
		LOG_DBG("Ranging data unsubscribed");
		return BT_GATT_ITER_STOP;
	}
	if (length != sizeof(uint16_t)) {
		LOG_WRN("rd_notfy invalid size:%u", length);
		return BT_GATT_ITER_CONTINUE;
	}
	struct bt_ras_client *ras_c = ras_c_by_conn_state(conn, RAS_C_STATE_READ_FEATURES_DONE);
	if (!ras_c) {
		LOG_WRN("w/o context");
		return BT_GATT_ITER_STOP;
	}
	uint16_t ranging_counter = *(uint16_t *)data;
	LOG_DBG("rd_notfy rc:%u", ranging_counter);
	if (params->value_handle ==
	    ras_c->subscribe_params[RAS_CHARC_RANGING_DATA_READY].value_handle) {
		if (ras_c->rd_ready_cb) {
			ras_c->rd_ready_cb(conn, ranging_counter, 0);
		}
	} else {
		ras_c->state = RAS_C_STATE_ON_DEMAND_MODE;
		if (ras_c->rd_overwritten_cb) {
			ras_c->rd_overwritten_cb(conn, ranging_counter);
		}
	}
	return BT_GATT_ITER_CONTINUE;
}

static uint8_t ras_c_rd_notify(struct bt_ras_client *ras_c, const void *data, uint16_t length,
			       struct net_buf_simple *rd_buf_out)
{
	// segment received
	atm_work_reschedule_for_app_work_q(&ras_c->timeout_work,
					   K_SECONDS(RECV_RD_SEG_TIMEOUT_SEC));

	struct net_buf_simple segment;
	net_buf_simple_init_with_data(&segment, (uint8_t *)data, length);
	uint8_t seg_hdr = net_buf_simple_pull_u8(&segment);
	uint8_t seg_cnt = seg_hdr >> SEGMENT_COUNT_START;
	uint16_t seg_len = segment.len;
	LOG_DBG("rd len:%u seg_cnt:%u seg_len:%u", length, seg_cnt, segment.len);
	if (!ras_c->err_status) {
		// check first segment & next_seg_cnt
		if (((seg_hdr & BIT(FIRST_SEGMENT)) && seg_cnt) ||
		    (ras_c->next_seg_cnt != seg_cnt)) {
			LOG_ERR("rd hdr:%u seg_cnt:%u next:%u", seg_hdr, seg_cnt,
				ras_c->next_seg_cnt);
			ras_c->err_status = -EINVAL;
		}
	}
#ifdef CONFIG_RAS_CLIENT_REAL_TIME_RD
	if (ras_c->err_status && (ras_c->state == RAS_C_STATE_REALTIME_MODE)) {
		// check first segment after err status happened
		if ((seg_hdr & BIT(FIRST_SEGMENT)) && !seg_cnt) {
			// callback the last time status, reset err_status to recollect the data
			ras_c_realtime_rd_cmpl(ras_c, ras_c->err_status);
		}
	}
#endif
	if (!ras_c->err_status) {
		if (net_buf_simple_tailroom(rd_buf_out) < seg_len) {
			LOG_ERR("Buf:%u seg:%u", net_buf_simple_tailroom(rd_buf_out), seg_len);
			ras_c->err_status = -ENOMEM;
		} else {
			uint8_t *rd_seg = net_buf_simple_pull_mem(&segment, seg_len);
			net_buf_simple_add_mem(rd_buf_out, rd_seg, seg_len);
			ras_c->next_seg_cnt = (seg_cnt + 1) & BIT_MASK(SEGMENT_COUNT_BITS);
		}
	}
	if (seg_hdr & BIT(LAST_SEGMENT)) {
		k_work_cancel_delayable(&ras_c->timeout_work);
		ras_c->last_seg = true;
#ifdef CONFIG_RAS_CLIENT_REAL_TIME_RD
		if (ras_c->state == RAS_C_STATE_REALTIME_MODE) {
			ras_c_realtime_rd_cmpl(ras_c, ras_c->err_status);
			return BT_GATT_ITER_CONTINUE;
		}
#endif
	}
	return BT_GATT_ITER_CONTINUE;
}

static uint8_t ras_c_ondemand_rd_notify(struct bt_conn *conn,
					struct bt_gatt_subscribe_params *params, const void *data,
					uint16_t length)
{
	if (!data) {
		LOG_DBG("on_demand unsubscribed");
		return BT_GATT_ITER_STOP;
	}
	struct bt_ras_client *ras_c = ras_c_by_conn_state(conn, RAS_C_STATE_ON_DEMAND_MODE);
	if (!ras_c) {
		LOG_WRN("w/o context");
		return BT_GATT_ITER_STOP;
	}
	if (ras_c->state != RAS_C_STATE_GET_RANGING_DATA) {
		LOG_WRN("unexpected ondemand state:%u", ras_c->state);
		return BT_GATT_ITER_CONTINUE;
	}
	return ras_c_rd_notify(ras_c, data, length, ras_c->ondemand_buf_out);
}

#ifdef CONFIG_RAS_CLIENT_REAL_TIME_RD
static uint8_t ras_c_realtime_rd_notify(struct bt_conn *conn,
					struct bt_gatt_subscribe_params *params, const void *data,
					uint16_t length)
{
	LOG_DBG("%s", __func__);
	if (!data) {
		LOG_DBG("realtime unsubscribed");
		return BT_GATT_ITER_STOP;
	}
	struct bt_ras_client *ras_c = ras_c_by_conn_state(conn, RAS_C_STATE_REALTIME_MODE);
	if (!ras_c) {
		LOG_WRN("w/o context or wrong mode");
		return BT_GATT_ITER_STOP;
	}
	return ras_c_rd_notify(ras_c, data, length, ras_c->realtime_buf_out);
}
#endif

static uint8_t ras_c_cp_notify(struct bt_conn *conn, struct bt_gatt_subscribe_params *params,
			       const void *data, uint16_t length)
{
	if (!data) {
		LOG_DBG("cp unsubscribed");
		return BT_GATT_ITER_STOP;
	}
	struct bt_ras_client *ras_c = ras_c_by_conn_state(conn, RAS_C_STATE_READ_FEATURES_DONE);
	if (!ras_c) {
		LOG_WRN("w/o context");
		return BT_GATT_ITER_STOP;
	}
	// only need to handle in on-demand mode
	if (ras_c->state != RAS_C_STATE_GET_RANGING_DATA) {
		LOG_DBG("cp_notif opcode:%u len:%u", *(uint8_t *)data, length);
		return BT_GATT_ITER_CONTINUE;
	}
	struct net_buf_simple buf;
	net_buf_simple_init_with_data(&buf, (uint8_t *)data, length);
	uint8_t opcode = net_buf_simple_pull_u8(&buf);
	switch (opcode) {
	case RAS_CP_RSP_OPCODE_COMPLETE_RD_RSP: {
		if (buf.len != sizeof(uint16_t)) {
			LOG_WRN("cp cmp invalid size:%u", buf.len);
			return BT_GATT_ITER_CONTINUE;
		}
		uint16_t ranging_counter = net_buf_simple_pull_le16(&buf);
		if (ras_c->ranging_counter != ranging_counter) {
			LOG_WRN("unexpected rc:%u %u or state", ras_c->ranging_counter,
				ranging_counter);
			return BT_GATT_ITER_CONTINUE;
		}
		NET_BUF_SIMPLE_DEFINE(ack_buf, RAS_CP_OPCODE_LEN + sizeof(uint16_t));
		net_buf_simple_add_u8(&ack_buf, RAS_CP_CMD_OPCODE_ACK_RD);
		net_buf_simple_add_le16(&ack_buf, ras_c->ranging_counter);
		int err = bt_gatt_write_without_response(
			conn, ras_c->subscribe_params[RAS_CHARC_CP].value_handle, ack_buf.data,
			ack_buf.len, false);
		if (err) {
			LOG_ERR("ack cmd err:%d", err);
		}
		ras_c->state = RAS_C_STATE_ON_DEMAND_MODE;
		if (!ras_c->get_rd_cmpl_cb) {
			return BT_GATT_ITER_CONTINUE;
		}
		err = ras_c->err_status;
		if (!ras_c->last_seg && !err) {
			err = -ENODATA;
		}
		ras_c->get_rd_cmpl_cb(conn, ras_c->ranging_counter, err);
	} break;
	case RAS_CP_RSP_OPCODE_RSP_CODE: {
		if (buf.len != sizeof(uint8_t)) {
			LOG_WRN("rsp code invalid size:%u", buf.len);
			return BT_GATT_ITER_CONTINUE;
		}
		// only consider get rd rsp
		uint8_t rsp_code = net_buf_simple_pull_u8(&buf);
		int err = 0;
		if (rsp_code == RAS_CP_RSP_PROCEDURE_NOT_COMPLETED) {
			err = -ENODATA;
		} else if (rsp_code == RAS_CP_RSP_RESERVED) {
			LOG_WRN("rsp code reserved");
		} else if (rsp_code != RAS_CP_RSP_SUCCESS) {
			err = -ENOENT;
		}
		if (!err) {
			// wait for RAS_CP_RSP_OPCODE_COMPLETE_RD_RSP
			return BT_GATT_ITER_CONTINUE;
		}
		ras_c->state = RAS_C_STATE_ON_DEMAND_MODE;
		if (ras_c->get_rd_cmpl_cb) {
			ras_c->get_rd_cmpl_cb(conn, ras_c->ranging_counter, err);
		}
	} break;
	default: {
		LOG_WRN("unexpected opcode:%u", opcode);
	} break;
	}
	return BT_GATT_ITER_CONTINUE;
}

static uint8_t ras_c_gatt_read_cb(struct bt_conn *conn, uint8_t err,
				  struct bt_gatt_read_params *params, const void *data,
				  uint16_t length)
{
	struct bt_ras_client *ras_c = ras_c_by_conn_state(conn, RAS_C_STATE_DISCOVERY);
	if (!ras_c || !data || (length != sizeof(ras_c->ras_features))) {
		return BT_GATT_ITER_STOP;
	}
	if (!err) {
		ras_c->ras_features = *(uint32_t *)data;
		LOG_DBG("features=%#x state=%u", ras_c->ras_features, ras_c->state);
		ras_c->state = RAS_C_STATE_READ_FEATURES_DONE;
	}
	if (ras_c_cb && ras_c_cb->discovery_done) {
		ras_c_cb->discovery_done(conn, err);
	}
	return BT_GATT_ITER_CONTINUE;
}

static void ras_c_discovery_cmpl(struct bt_conn *conn, int err)
{
	struct bt_ras_client *ras_c = ras_c_by_conn_state(conn, RAS_C_STATE_DISCOVERY);
	if (!ras_c) {
		return;
	}
	if (err) {
		ras_c_cleanup(ras_c);
	} else {
		// prepare subscribe values
		for (uint8_t char_idx = RAS_CHARC_REALTIME_RANGING_DATA;
		     char_idx < RAS_CHARC_MAX_NUM; char_idx++) {
			if ((char_idx == RAS_CHARC_RANGING_DATA_READY) ||
			    (char_idx == RAS_CHARC_RANGING_DATA_OVERWRITTEN)) {
				ras_c->subscribe_params[char_idx].notify = ras_c_rd_ready_ow_notify;
			} else if (char_idx == RAS_CHARC_ONDEMAND_RANGING_DATA) {
				ras_c->subscribe_params[char_idx].notify = ras_c_ondemand_rd_notify;
#ifdef CONFIG_RAS_CLIENT_REAL_TIME_RD
			} else if (char_idx == RAS_CHARC_REALTIME_RANGING_DATA) {
				ras_c->subscribe_params[char_idx].notify = ras_c_realtime_rd_notify;
#endif
			} else if (char_idx == RAS_CHARC_CP) {
				ras_c->subscribe_params[char_idx].notify = ras_c_cp_notify;
			}
			ras_c->subscribe_params[char_idx].subscribe = ras_c_subscribe;
			if (char_idx == RAS_CHARC_CP) {
				ras_c->subscribe_params[char_idx].value = BT_GATT_CCC_INDICATE;
			} else {
				ras_c->subscribe_params[char_idx].value =
					BT_GATT_CCC_NOTIFY | BT_GATT_CCC_INDICATE;
			}
		}
		ras_c->conn = conn;
		k_work_init_delayable(&ras_c->timeout_work, timeout_work_handler);
		static struct bt_gatt_read_params params = {
			.func = ras_c_gatt_read_cb,
			.handle_count = 1,
		};
		params.single.handle = ras_c->subscribe_params[RAS_CHARC_RAS_FEATURES].value_handle;
		err = bt_gatt_read(conn, &params);
		if (!err) {
			return;
		}
		LOG_ERR("read features err:%d", err);
	}
	if (!ras_c_cb || !ras_c_cb->discovery_done) {
		LOG_ERR("discv cmpl null cb");
		return;
	}
	ras_c_cb->discovery_done(conn, err);
}

static void ras_c_validate_discovery(struct bt_conn *conn)
{
	struct bt_ras_client *ras_c = ras_c_by_conn_state(conn, RAS_C_STATE_DISCOVERY);
	if (!ras_c) {
		return;
	}
	uint8_t v_hdl_mask = 0;
	uint8_t ccc_hdl_mask = 0;
	for (uint8_t i = 0; i < RAS_CHARC_MAX_NUM; i++) {
		if (ras_c->subscribe_params[i].value_handle) {
			v_hdl_mask |= BIT(i);
		}
		if (ras_c->subscribe_params[i].ccc_handle) {
			ccc_hdl_mask |= BIT(i);
		}
		LOG_DBG("i:%u v_hdl:%#x ccc_hdl:%#x", i, ras_c->subscribe_params[i].value_handle,
			ras_c->subscribe_params[i].ccc_handle);
	}
	int err = 0;
	if ((v_hdl_mask & RAS_CHARC_MANDATORY_MASK) != RAS_CHARC_MANDATORY_MASK) {
		err = -ENOTSUP;
	}
	if ((v_hdl_mask & RAS_CHARC_CCC_MANDATORY_MASK) != RAS_CHARC_CCC_MANDATORY_MASK) {
		err = -ENOTSUP;
	}
	LOG_DBG("mask:%#x %#lx %#x %#lx", v_hdl_mask, RAS_CHARC_MANDATORY_MASK, ccc_hdl_mask,
		RAS_CHARC_CCC_MANDATORY_MASK);
	ras_c_discovery_cmpl(conn, err);
}

static int ras_c_discover_gatt(struct bt_conn *conn, struct bt_gatt_discover_params *discover,
			       uint16_t current_handle, uint16_t end_handle, uint8_t discovery_type,
			       const struct bt_uuid *uuid)
{
	// Update end handle if provided
	if (end_handle) {
		discover->end_handle = end_handle;
	}

	// Calculate start handle with automatic offset based on discovery type
	if (current_handle) {
		discover->start_handle = current_handle;
		// Define handle offsets for different discovery types
#define RAS_GATT_CCCD_OFFSET  2 // Traditional CCCD offset from characteristic handle
#define RAS_GATT_CHARC_OFFSET 1 // Offset for next characteristic discovery

		if (discovery_type == BT_GATT_DISCOVER_DESCRIPTOR) {
			discover->start_handle += RAS_GATT_CCCD_OFFSET;
		} else if (discovery_type == BT_GATT_DISCOVER_CHARACTERISTIC) {
			discover->start_handle += RAS_GATT_CHARC_OFFSET;
		} else {
			LOG_WRN("bad disc type:%u", discovery_type);
			// End discovery and validate discovery result
			ras_c_validate_discovery(conn);
			return -ENOTSUP;
		}
		LOG_DBG("hdl:%u->%u", current_handle, discover->start_handle);
	}

	// Validate handle boundaries
	if (discover->start_handle > discover->end_handle) {
		LOG_DBG("bad range:%u>%u", discover->start_handle, discover->end_handle);
		// End discovery and validate discovery result
		ras_c_validate_discovery(conn);
		return -EINVAL;
	}

	// Set discovery parameters
	discover->type = discovery_type;
	discover->uuid = uuid;

	LOG_DBG("disc t:%u %u->%u e:%u", discovery_type, current_handle, discover->start_handle,
		discover->end_handle);

	int err = bt_gatt_discover(conn, discover);
	if (err) {
		LOG_ERR("gatt disc fail:%d", err);
		ras_c_discovery_cmpl(conn, err);
		return err;
	}
	return 0;
}

static uint8_t ras_c_disc_cb(struct bt_conn *conn, const struct bt_gatt_attr *attr,
			     struct bt_gatt_discover_params *params)
{
	LOG_DBG("type:%u", params->type);
	struct bt_ras_client *ras_c = ras_c_by_conn_state(conn, RAS_C_STATE_DISCOVERY);
	if (!ras_c) {
		return BT_GATT_ITER_STOP;
	}
	LOG_DBG("cb %u %u", ras_c->discover.start_handle, ras_c->discover.end_handle);
	if (!attr) {
		LOG_DBG("disc done t:%u", params->type);
		ras_c_validate_discovery(conn);
		return BT_GATT_ITER_STOP;
	}

	static uint8_t charc_idx;
	switch (params->type) {
	case BT_GATT_DISCOVER_PRIMARY: {
		const struct bt_gatt_service_val *svr_val = attr->user_data;
		int err = ras_c_discover_gatt(conn, &ras_c->discover, attr->handle,
					      svr_val->end_handle, BT_GATT_DISCOVER_CHARACTERISTIC,
					      NULL);
		if (err) {
			LOG_ERR("charc disc fail:%d", err);
		}
		return BT_GATT_ITER_STOP;
	} break;
	case BT_GATT_DISCOVER_CHARACTERISTIC: {
		const struct bt_gatt_chrc *chrc = attr->user_data;
		if ((charc_idx = ras_c_get_handle_idx(chrc->uuid)) < RAS_CHARC_MAX_NUM) {
			ras_c->subscribe_params[charc_idx].value_handle = chrc->value_handle;
			ras_c->char_prop[charc_idx] = chrc->properties;

			// Check if this characteristic needs CCC
			if (!(RAS_CHARC_CCC_MASK & BIT(charc_idx))) {
				return BT_GATT_ITER_CONTINUE;
			}

			static const struct bt_uuid_16 ccc_uuid =
				BT_UUID_INIT_16(BT_UUID_GATT_CCC_VAL);
			int err = ras_c_discover_gatt(conn, &ras_c->discover, attr->handle, 0,
						      BT_GATT_DISCOVER_DESCRIPTOR, &ccc_uuid.uuid);
			if (err) {
				LOG_ERR("cccd disc fail:%d", err);
			}
			return BT_GATT_ITER_STOP;
		} else {
			return BT_GATT_ITER_CONTINUE;
		}
	} break;
	case BT_GATT_DISCOVER_DESCRIPTOR: {
		ras_c->subscribe_params[charc_idx].ccc_handle = attr->handle;
		LOG_DBG("cccd hdl:%u ch:%u", attr->handle, charc_idx);

		// Continue characteristic discovery from current handle
		int err = ras_c_discover_gatt(conn, &ras_c->discover, attr->handle, 0,
					      BT_GATT_DISCOVER_CHARACTERISTIC, NULL);
		if (err) {
			LOG_ERR("cont charc disc fail:%d", err);
		}
		return BT_GATT_ITER_STOP;
	} break;
	default: {
		return BT_GATT_ITER_CONTINUE;
	} break;
	}
	return BT_GATT_ITER_STOP;
}

/**
 * RAS GATT Discovery State Machine:
 *
 * PRIMARY -> CHARACTERISTIC -> DESCRIPTOR -> CHARACTERISTIC -> ...
 *     |            |              |              |
 *     v            v              v              v
 * Find service -> Find char -> Find CCCD -> Continue char discovery
 */
int bt_ras_client_discover(struct bt_conn *conn)
{
	if (!ras_c_cb || !ras_c_cb->discovery_done) {
		return -EINVAL;
	}

	struct bt_ras_client *ras_c = ras_c_by_conn(conn);
	if (!ras_c) {
		return -EINVAL;
	}
	if (ras_c->state >= RAS_C_STATE_DISCOVERY) {
		return -EINVAL;
	}
	ras_c_cleanup(ras_c);

	ras_c->discover = (struct bt_gatt_discover_params){
		.uuid = ras_uuid,
		.func = ras_c_disc_cb,
		.start_handle = BT_ATT_FIRST_ATTRIBUTE_HANDLE,
		.end_handle = BT_ATT_LAST_ATTRIBUTE_HANDLE,
		.type = BT_GATT_DISCOVER_PRIMARY,
	};
	ras_c->state = RAS_C_STATE_DISCOVERY;
	int err = bt_gatt_discover(conn, &ras_c->discover);
	if (err) {
		ras_c_cleanup(ras_c);
	}
	return err;
}

int bt_ras_client_cb_register(const struct bt_ras_client_cb *cb)
{
	if (!cb->discovery_done) {
		return -EINVAL;
	}
	if (ras_c_cb) {
		return -EALREADY;
	}
	ras_c_cb = cb;

	return 0;
}

static int ras_c_check_indicate(struct bt_ras_client *ras_c, uint8_t char_idx,
				enum bt_ras_client_subscribe_type sub_type)
{
	uint16_t available_methods = 0;
	uint16_t selected_method = 0;

	/* Determine what subscription methods the characteristic supports */
	if (ras_c->char_prop[char_idx] & BT_GATT_CHRC_INDICATE) {
		available_methods |= BT_GATT_CCC_INDICATE;
	}
	if (ras_c->char_prop[char_idx] & BT_GATT_CHRC_NOTIFY) {
		available_methods |= BT_GATT_CCC_NOTIFY;
	}

	if (!available_methods) {
		LOG_ERR("Characteristic %u does not support notifications or indications",
			char_idx);
		return -EOPNOTSUPP;
	}

	/* Select subscription method based on requested type */
	switch (sub_type) {
	case BT_RAS_CLIENT_SUB_AUTO:
		/* Auto-detect: enable notification and indication both if all supported */
		selected_method = available_methods;
		break;

	case BT_RAS_CLIENT_SUB_NOTIFY_ONLY:
		if (!(available_methods & BT_GATT_CCC_NOTIFY)) {
			LOG_ERR("Characteristic %u does not support notifications", char_idx);
			return -EOPNOTSUPP;
		}
		selected_method = BT_GATT_CCC_NOTIFY;
		break;

	case BT_RAS_CLIENT_SUB_INDICATE_ONLY:
		if (!(available_methods & BT_GATT_CCC_INDICATE)) {
			LOG_ERR("Characteristic %u does not support indications", char_idx);
			return -EOPNOTSUPP;
		}
		selected_method = BT_GATT_CCC_INDICATE;
		break;

	default:
		LOG_ERR("Invalid subscription type: %d", sub_type);
		return -EINVAL;
	}

	ras_c->subscribe_params[char_idx].value = selected_method;
	LOG_DBG("Selected %s for characteristic %u",
		(selected_method == BT_GATT_CCC_INDICATE) ? "indications" : "notifications",
		char_idx);

	return 0;
}

int bt_ras_client_ranging_data_ready_subscribe(struct bt_conn *conn,
					       const bt_ras_client_ranging_data_ready_cb cb,
					       enum bt_ras_client_subscribe_type value)
{
	struct bt_ras_client *ras_c = ras_c_by_conn_state(conn, RAS_C_STATE_READ_FEATURES_DONE);
	if (!ras_c) {
		return -EINVAL;
	}

	int err = ras_c_check_indicate(ras_c, RAS_CHARC_RANGING_DATA_READY, value);
	if (err) {
		return err;
	}

	err = bt_gatt_subscribe(conn, &ras_c->subscribe_params[RAS_CHARC_RANGING_DATA_READY]);
	if (err && (err != -EALREADY)) {
		LOG_ERR("Ranging data ready subscribe err:%d", err);
		return err;
	}
	ras_c->rd_ready_cb = cb;

	if (ras_c->cs_enabled) {
		atm_work_reschedule_for_app_work_q(
			&ras_c->timeout_work,
			K_SECONDS(CONFIG_RAS_CLIENT_RECEIVE_RANGING_DATA_TIMEOUT_SEC));
	}

	return err;
}

int bt_ras_client_ranging_data_overwritten_subscribe(
	struct bt_conn *conn, const bt_ras_client_ranging_data_overwritten_cb cb,
	enum bt_ras_client_subscribe_type value)
{
	struct bt_ras_client *ras_c = ras_c_by_conn_state(conn, RAS_C_STATE_READ_FEATURES_DONE);
	if (!ras_c) {
		return -EINVAL;
	}

	int err = ras_c_check_indicate(ras_c, RAS_CHARC_RANGING_DATA_OVERWRITTEN, value);
	if (err) {
		return err;
	}

	err = bt_gatt_subscribe(conn, &ras_c->subscribe_params[RAS_CHARC_RANGING_DATA_OVERWRITTEN]);
	if (err) {
		LOG_ERR("Ranging data ow subscribe err:%d", err);
		return err;
	}
	ras_c->rd_overwritten_cb = cb;
	return err;
}

int bt_ras_client_ranging_data_ready_unsubscribe(struct bt_conn *conn)
{
	struct bt_ras_client *ras_c = ras_c_by_conn_state(conn, RAS_C_STATE_READ_FEATURES_DONE);
	if (!ras_c) {
		return -EINVAL;
	}

	int err = bt_gatt_unsubscribe(conn, &ras_c->subscribe_params[RAS_CHARC_RANGING_DATA_READY]);
	if (err) {
		LOG_ERR("Ranging data ready unsubscribe err:%d", err);
		return err;
	}

	ras_c->rd_ready_cb = NULL;
	k_work_cancel_delayable(&ras_c->timeout_work);
	return err;
}

int bt_ras_client_ranging_data_overwritten_unsubscribe(struct bt_conn *conn)
{
	struct bt_ras_client *ras_c = ras_c_by_conn_state(conn, RAS_C_STATE_READ_FEATURES_DONE);
	if (!ras_c) {
		return -EINVAL;
	}

	int err = bt_gatt_unsubscribe(conn,
				      &ras_c->subscribe_params[RAS_CHARC_RANGING_DATA_OVERWRITTEN]);
	if (err) {
		LOG_ERR("Ranging data overwritten unsubscribe err:%d", err);
		return err;
	}

	ras_c->rd_overwritten_cb = NULL;
	return err;
}

int bt_ras_client_on_demand_ranging_data_subscribe(struct bt_conn *conn,
						   enum bt_ras_client_subscribe_type value)
{
	struct bt_ras_client *ras_c = ras_c_by_conn_state(conn, RAS_C_STATE_READ_FEATURES_DONE);
	if (!ras_c) {
		return -EINVAL;
	}
#ifdef CONFIG_RAS_CLIENT_REAL_TIME_RD
	if (ras_c->state == RAS_C_STATE_REALTIME_MODE) {
		return -EINVAL;
	}
#endif

	int err = ras_c_check_indicate(ras_c, RAS_CHARC_ONDEMAND_RANGING_DATA, value);
	if (err) {
		return err;
	}

	err = bt_gatt_subscribe(conn, &ras_c->subscribe_params[RAS_CHARC_ONDEMAND_RANGING_DATA]);
	if (err) {
		LOG_ERR("Ranging data od subscribe err:%d", err);
	}
	ras_c->state = RAS_C_STATE_ON_DEMAND_MODE;
	return err;
}

int bt_ras_client_on_demand_ranging_data_unsubscribe(struct bt_conn *conn)
{
	struct bt_ras_client *ras_c = ras_c_by_conn_state(conn, RAS_C_STATE_READ_FEATURES_DONE);
	if (!ras_c) {
		return -EINVAL;
	}
#ifdef CONFIG_RAS_CLIENT_REAL_TIME_RD
	if (ras_c->state == RAS_C_STATE_REALTIME_MODE) {
		return -EINVAL;
	}
#endif
	int err = bt_gatt_unsubscribe(conn,
				      &ras_c->subscribe_params[RAS_CHARC_ONDEMAND_RANGING_DATA]);
	if (err) {
		LOG_ERR("Ranging data od unsubscribe err:%d", err);
		return err;
	}
	k_work_cancel_delayable(&ras_c->timeout_work);
	return err;
}

int bt_ras_client_cp_subscribe(struct bt_conn *conn, enum bt_ras_client_subscribe_type value)
{
	struct bt_ras_client *ras_c = ras_c_by_conn_state(conn, RAS_C_STATE_READ_FEATURES_DONE);
	if (!ras_c) {
		return -EINVAL;
	}

	int err = ras_c_check_indicate(ras_c, RAS_CHARC_CP, value);
	if (err) {
		return err;
	}

	err = bt_gatt_subscribe(conn, &ras_c->subscribe_params[RAS_CHARC_CP]);
	if (err) {
		LOG_ERR("Ranging data cp subscribe err:%d", err);
	}
	return err;
}

int bt_ras_client_cp_get_ranging_data(struct bt_conn *conn, uint16_t ranging_counter,
				      struct net_buf_simple *ranging_data_out,
				      const bt_ras_client_get_ranging_data_cmpl_cb cb)
{
	struct bt_ras_client *ras_c = ras_c_by_conn_state(conn, RAS_C_STATE_ON_DEMAND_MODE);
	if (!ras_c) {
		return -EINVAL;
	}
	if (ras_c->state == RAS_C_STATE_GET_RANGING_DATA) {
		return -EBUSY;
	}
	NET_BUF_SIMPLE_DEFINE(get_rd_buf, RAS_CP_OPCODE_LEN + sizeof(uint16_t));
	net_buf_simple_add_u8(&get_rd_buf, RAS_CP_CMD_OPCODE_GET_RD);
	net_buf_simple_add_le16(&get_rd_buf, ranging_counter);
	int err = bt_gatt_write_without_response(conn,
						 ras_c->subscribe_params[RAS_CHARC_CP].value_handle,
						 get_rd_buf.data, get_rd_buf.len, false);
	if (err) {
		LOG_ERR("get_rd cmd err:%d", err);
		return err;
	}
	ras_c->state = RAS_C_STATE_GET_RANGING_DATA;
	ras_c->ondemand_buf_out = ranging_data_out;
	ras_c->get_rd_cmpl_cb = cb;
	ras_c->ranging_counter = ranging_counter;
	ras_c->err_status = 0;
	ras_c->next_seg_cnt = 0;
	ras_c->last_seg = false;

	atm_work_reschedule_for_app_work_q(
		&ras_c->timeout_work,
		K_SECONDS(CONFIG_RAS_CLIENT_RECEIVE_RANGING_DATA_TIMEOUT_SEC));
	return err;
}

#ifdef CONFIG_RAS_CLIENT_REAL_TIME_RD
int bt_ras_client_realtime_ranging_data_subscribe(
	struct bt_conn *conn, struct net_buf_simple *ranging_data_out,
	const bt_ras_client_get_realtime_ranging_data_cmpl_cb cb,
	enum bt_ras_client_subscribe_type value)
{
	struct bt_ras_client *ras_c = ras_c_by_conn_state(conn, RAS_C_STATE_READ_FEATURES_DONE);
	if (!ras_c || (ras_c->state != RAS_C_STATE_READ_FEATURES_DONE)) {
		return -EINVAL;
	}
	if (!(ras_c->ras_features & RAS_FEAT_REALTIME_RD)) {
		return -EOPNOTSUPP;
	}

	int err = ras_c_check_indicate(ras_c, RAS_CHARC_REALTIME_RANGING_DATA, value);
	if (err) {
		return err;
	}

	err = bt_gatt_subscribe(conn, &ras_c->subscribe_params[RAS_CHARC_REALTIME_RANGING_DATA]);
	if (err && (err != -EALREADY)) {
		LOG_ERR("Ranging data rt subscribe err:%d", err);
		return err;
	}
	ras_c->state = RAS_C_STATE_REALTIME_MODE;
	ras_c->realtime_buf_out = ranging_data_out;
	ras_c->get_realtime_rd_cmpl_cb = cb;
	if (ras_c->cs_enabled) {
		atm_work_reschedule_for_app_work_q(
			&ras_c->timeout_work,
			K_SECONDS(CONFIG_RAS_CLIENT_RECEIVE_RANGING_DATA_TIMEOUT_SEC));
	}
	return err;
}

int bt_ras_client_realtime_ranging_data_unsubscribe(struct bt_conn *conn)
{
	struct bt_ras_client *ras_c = ras_c_by_conn_state(conn, RAS_C_STATE_REALTIME_MODE);
	if (!ras_c) {
		return -EINVAL;
	}
	int err = bt_gatt_unsubscribe(conn,
				      &ras_c->subscribe_params[RAS_CHARC_REALTIME_RANGING_DATA]);
	if (err) {
		LOG_ERR("Ranging data rt unsubscribe err:%d", err);
		return err;
	}
	k_work_cancel_delayable(&ras_c->timeout_work);
	ras_c->state = RAS_C_STATE_READ_FEATURES_DONE;
	return err;
}
#endif

int bt_ras_client_ranging_data_parse(struct net_buf_simple *ranging_data_buf,
				     uint16_t *ranging_counter_out)
{
	if (ranging_data_buf->len < sizeof(ras_rd_header_t)) {
		return -EINVAL;
	}
	ras_rd_header_t *rd_hdr =
		net_buf_simple_pull_mem(ranging_data_buf, sizeof(ras_rd_header_t));
	*ranging_counter_out = rd_hdr->ranging_counter;
	return 0;
}
