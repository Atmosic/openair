/*
 * Copyright (c) 2025 Atmosic
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>
#include <zephyr/settings/settings.h>
#include <zephyr/logging/log.h>
#include <zephyr/sys/byteorder.h>

#include <zephyr/bluetooth/bluetooth.h>
#include <zephyr/bluetooth/conn.h>
#include <zephyr/bluetooth/gatt.h>
#include <zephyr/bluetooth/hci_types.h>

#include "ras.h"
#include "ras_internal.h"
#include "app_work_q.h"
#ifdef CONFIG_RAS_PTS_FAKE_CS_DATA
#include "cs_fakedata.h"
#endif

LOG_MODULE_REGISTER(bt_ras, CONFIG_BT_RAS_LOG_LEVEL);

#define RAS_MAX_STEP_DATA_LEN                                                                      \
	(sizeof(struct bt_hci_le_cs_step_data_mode_2) +                                            \
	 ((CONFIG_RAS_MAX_ANTENNA_PATH_NUM + 1) *                                                  \
	  sizeof(struct bt_hci_le_cs_step_data_tone_info)))

#define RAS_DATA_BUFFER_MAX_SIZE                                                                   \
	(sizeof(struct ras_rd_header_s) +                                                          \
	 (sizeof(struct ras_rd_subevent_hdr_s) * BT_RAS_MAX_SUBEVENTS_PER_PROCEDURE) +             \
	 ((sizeof(struct ras_rd_step_data_s) + RAS_MAX_STEP_DATA_LEN) *                            \
	  BT_RAS_MAX_STEPS_PER_PROCEDURE))

typedef enum ras_buf_sts_e {
	RAS_BUF_FREE,
	RAS_BUF_UPDATING,
	RAS_BUF_DONE,
} ras_buf_sts_t;

typedef struct ras_rd_buffer_s {
	uint8_t status;
	uint16_t data_offset;
	uint16_t ranging_cnt;
	uint8_t proc_data[RAS_DATA_BUFFER_MAX_SIZE];
} ras_rd_buffer_t;

typedef enum ras_conn_work_evt_e {
#ifdef CONFIG_RAS_ACTIVE_SECURE_CHANGE
	RAS_CONN_WORK_EVT_SECURE_LVL,
#endif
#ifdef CONFIG_RAS_SECURE_FORCE_DISCONN
	RAS_CONN_WORK_EVT_FORCE_DISC,
#endif
	RAS_CONN_WORK_EVT_INVALID,
} ras_conn_work_evt_t;

#if RAS_CONN_WORK_EVT_INVALID > 0
typedef struct ras_conn_work_info_s {
	struct k_work work;
	uint8_t pending_cnt;
	ras_conn_work_evt_t event;
} ras_conn_work_info_t;
#endif

typedef enum ras_sts_work_evt_e {
	RAS_STS_WORK_EVT_RD_READY,
	RAS_STS_WORK_EVT_RD_OVRWRT,
	RAS_STS_WORK_EVT_INVALID,
} ras_sts_work_evt_t;

typedef struct ras_sts_work_info_s {
	struct k_work work;
	ras_sts_work_evt_t event;
} ras_sts_work_info_t;

typedef enum ras_cp_rsp_work_type_e {
	RAS_CP_RSP_WORK_TYPE_CODE_RSP,
	RAS_CP_RSP_WORK_TYPE_CMP_RD_RSP,
} ras_cp_rsp_work_type_t;

typedef struct ras_cp_rsp_work_info_s {
	struct k_work work;
	struct bt_conn *conn;
	ras_cp_rsp_work_type_t type;
	union {
		uint8_t rsp_code;
		uint16_t ranging_counter;
	} para;
} ras_cp_rsp_work_info_t;

typedef enum ras_trans_work_evt_e {
	RAS_TRANS_WORK_EVT_START,
	RAS_TRANS_WORK_EVT_CONT,
	RAS_TRANS_WORK_EVT_END,
	RAS_TRANS_WORK_EVT_INVALID,
} ras_trans_work_evt_t;

typedef enum ras_trans_work_err_e {
	RAS_TRANS_WORK_ERR_SUCCESS,
	RAS_TRANS_WORK_ERR_BUSY = RAS_CP_RSP_SERVER_BUSY,
	RAS_TRANS_WORK_ERR_NO_DATA = RAS_CP_RSP_NO_RECORDS_FOUND,
} ras_trans_work_err_t;

typedef struct ras_rd_trans_work_info_s {
	struct k_work work;
	uint8_t pending_cnt;
	ras_trans_work_evt_t event;
	bool is_on_demand;
	uint16_t ranging_cnt;
	uint16_t sent_len;
	uint16_t seg_cnt;
	ras_rd_buffer_t *rd_buf;
	struct bt_gatt_indicate_params ras_rd_trans_para;
	ras_seg_data_t seg_buf;
} ras_rd_trans_work_info_t;

typedef enum ras_timeout_work_evt_e {
	RAS_TIMEOUT_WORK_EVT_WAIT_ACK,
	RAS_TIMEOUT_WORK_EVT_INVALID,
} ras_timeout_work_evt_t;

typedef struct ras_timeout_work_info_s {
	struct k_work_delayable work;
	uint8_t pending_cnt;
	ras_timeout_work_evt_t event;
	uint16_t ranging_cnt;
} ras_timeout_work_info_t;

typedef struct ras_ctrl_s {
	struct bt_conn *curr_conn;
	uint8_t cs_select_tx_pwr;
	uint32_t ras_feature;
	uint16_t ras_rd_ready_cnt;
	uint16_t ras_rd_ovrwrt_cnt;
	struct bt_gatt_indicate_params ras_rd_sts_para;
	struct bt_gatt_indicate_params ras_cp_para;
	ras_cp_t ras_cp_rsp;
	uint8_t sts_work_pending;
	uint8_t cp_rsp_work_pending;
#if RAS_CONN_WORK_EVT_INVALID > 0
	ras_conn_work_info_t ras_conn_work;
#endif
	ras_rd_trans_work_info_t ras_trs_work;
	ras_timeout_work_info_t ras_timeout_work;
} ras_ctrl_t;

static ras_ctrl_t ras;
static ras_rd_buffer_t ras_buf[CONFIG_RAS_RD_BUFFER_NUM];

static bool ras_ind_notify_is_enable(struct bt_conn *conn, const struct bt_uuid *uuid);
static ras_trans_work_err_t ras_transit_evt_work_put(ras_trans_work_evt_t evt, bool is_on_demand,
						     uint16_t ranging_cnt);
static int ras_cp_indicate(struct bt_conn *conn, uint16_t len);
static void ras_cp_rsp_work_put(struct bt_conn *conn, ras_cp_rsp_work_type_t type, uint16_t param);

static ras_rd_buffer_t *ras_rdbuf_get_buf(uint16_t ranging_cnt)
{
	for (uint8_t i = 0; i < CONFIG_RAS_RD_BUFFER_NUM; i++) {
		if (ras_buf[i].status != RAS_BUF_FREE && ras_buf[i].ranging_cnt == ranging_cnt) {
			return &ras_buf[i];
		}
	}

	return NULL;
}

static ras_rd_buffer_t *ras_rdbuf_get_new(void)
{
	for (uint8_t i = 0; i < CONFIG_RAS_RD_BUFFER_NUM; i++) {
		if (ras_buf[i].status == RAS_BUF_FREE) {
			return &ras_buf[i];
		}
	}

	return NULL;
}

static bool ras_rdbuf_free_buf(uint16_t ranging_cnt)
{
	for (uint8_t i = 0; i < CONFIG_RAS_RD_BUFFER_NUM; i++) {
		if (ras_buf[i].status != RAS_BUF_FREE && ras_buf[i].ranging_cnt == ranging_cnt) {
			ras_buf[i].status = RAS_BUF_FREE;
			ras_buf[i].data_offset = 0;
			ras_buf[i].ranging_cnt = 0;
			return true;
		}
	}

	return false;
}

static ras_rd_buffer_t *ras_rdbuf_free_one_buf(uint16_t *ranging_cnt)
{
	uint32_t last_rc = UINT16_MAX + 1;
	uint16_t free_idx;
	// find the oldest one
	for (uint8_t i = 0; i < CONFIG_RAS_RD_BUFFER_NUM; i++) {
		if (ras_buf[i].status != RAS_BUF_FREE && ras_buf[i].ranging_cnt < last_rc) {
			last_rc = ras_buf[i].ranging_cnt;
			free_idx = i;
		}
	}

	if (last_rc == UINT16_MAX + 1) {
		LOG_ERR("No buffer can be free");
		return NULL;
	}

	LOG_INF("Free buf%u: ranging conter - %u", free_idx, last_rc);
	*ranging_cnt = last_rc;

	ras_buf[free_idx].status = RAS_BUF_FREE;
	ras_buf[free_idx].data_offset = 0;
	ras_buf[free_idx].ranging_cnt = 0;

	return &ras_buf[free_idx];
}

static void ras_rdbuf_free_all_buf(void)
{
	for (uint8_t i = 0; i < CONFIG_RAS_RD_BUFFER_NUM; i++) {
		if (ras_buf[i].status != RAS_BUF_FREE) {
			LOG_INF("Free buf%u: ranging conter - %u", i, ras_buf[i].ranging_cnt);
			ras_buf[i].status = RAS_BUF_FREE;
			ras_buf[i].data_offset = 0;
			ras_buf[i].ranging_cnt = 0;
		}
	}
}

static void ras_timeout_work_handler(struct k_work *work)
{
	struct k_work_delayable *timer_work = k_work_delayable_from_work(work);
	ras_timeout_work_info_t *info =
		CONTAINER_OF(timer_work, struct ras_timeout_work_info_s, work);

	LOG_DBG("timeout:%d", info->event);

	if (!ras.curr_conn) {
		LOG_ERR("Link is disconnect");
		info->pending_cnt -= 1;
		return;
	}

	switch (info->event) {
	case RAS_TIMEOUT_WORK_EVT_WAIT_ACK: {
		// Timeout triggered. Fail to wait ACK. Clear procedure data
		LOG_WRN("CP ACK timeout: clear procedure-%d", info->ranging_cnt);
		ras_rdbuf_free_buf(info->ranging_cnt);
	} break;
	default: {
		LOG_ERR("Unexpected event");
	} break;
	}
	info->pending_cnt -= 1;
}

static void ras_timeout_evt_work_put(ras_timeout_work_evt_t evt, uint16_t rd_cnt, k_timeout_t delay)
{
	if (ras.ras_timeout_work.pending_cnt) {
		LOG_ERR("timeout evt overwrite:%d->%d", ras.ras_timeout_work.event, evt);
	} else {
		ras.ras_timeout_work.pending_cnt += 1;
	}
	ras.ras_timeout_work.event = evt;
	ras.ras_timeout_work.ranging_cnt = rd_cnt;
	atm_work_reschedule_for_app_work_q(&ras.ras_timeout_work.work, delay);
}

static void ras_timeout_evt_work_cancel(uint16_t rd_cnt)
{
	if (!ras.ras_timeout_work.pending_cnt) {
		LOG_ERR("No pending event");
		return;
	}
	ras.ras_timeout_work.pending_cnt -= 1;
	if (rd_cnt != ras.ras_timeout_work.ranging_cnt) {
		LOG_WRN("Unexpected ranging count: %u - %u", rd_cnt,
			ras.ras_timeout_work.ranging_cnt);
	}
	k_work_cancel_delayable(&ras.ras_timeout_work.work);
}

static ssize_t ras_read_ras_feature(struct bt_conn *conn, const struct bt_gatt_attr *attr,
				    void *buf, uint16_t len, uint16_t offset)
{
	return bt_gatt_attr_read(conn, attr, buf, len, offset, &ras.ras_feature,
				 sizeof(ras.ras_feature));
}

#if CONFIG_RAS_REAL_TIME_RD
static ssize_t ras_realtime_rd_ccc_write_cfm(struct bt_conn *conn, const struct bt_gatt_attr *attr,
					     uint16_t value)
{
	LOG_INF("realtime wr ccc:%u", value);

	if (!ras.curr_conn || ras.curr_conn != conn) {
		LOG_INF("realtime: Update connect");
		ras.curr_conn = conn;
	}

	if (value && ras_ind_notify_is_enable(conn, BT_UUID_RAS_ONDEMAND_RD)) {
		LOG_ERR("Enable real time RD at same time.");
		return BT_GATT_ERR(BT_ATT_ERR_CCC_IMPROPER_CONF);
	}
	return sizeof(value);
}

static void ras_realtime_rd_ccc_changed(const struct bt_gatt_attr *attr, uint16_t value)
{
	LOG_INF("realtime: ccc:%u", value);
}
#endif

static ssize_t ras_ondemand_rd_ccc_write_cfm(struct bt_conn *conn, const struct bt_gatt_attr *attr,
					     uint16_t value)
{
	LOG_INF("ondemand wr ccc:%u", value);

	if (!ras.curr_conn || ras.curr_conn != conn) {
		LOG_INF("ondemand: Update connect");
		ras.curr_conn = conn;
	}

#if CONFIG_RAS_REAL_TIME_RD
	if (value && ras_ind_notify_is_enable(conn, BT_UUID_RAS_REALTIME_RD)) {
		LOG_ERR("Enable real time RD at same time.");
		return BT_GATT_ERR(BT_ATT_ERR_CCC_IMPROPER_CONF);
	}
#endif
	return sizeof(value);
}

static void ras_ondemand_rd_ccc_changed(const struct bt_gatt_attr *attr, uint16_t value)
{
	LOG_INF("ondemand ccc:%u", value);
}

static ssize_t ras_write_control_point(struct bt_conn *conn, struct bt_gatt_attr const *attr,
				       void const *buf, uint16_t len, uint16_t offset,
				       uint8_t flags)
{
	ras_cp_t const *cp_cmd = buf;

	LOG_INF("CP cmd:%u", cp_cmd->opcode);

	switch (cp_cmd->opcode) {
	case RAS_CP_CMD_OPCODE_GET_RD: {
		if (len != (sizeof(cp_cmd->para.ranging_cnt) + sizeof(cp_cmd->opcode))) {
			ras_cp_rsp_work_put(conn, RAS_CP_RSP_WORK_TYPE_CODE_RSP,
					    RAS_CP_RSP_INVALID_PARAMETER);
			break;
		}
		if (!ras_ind_notify_is_enable(conn, BT_UUID_RAS_ONDEMAND_RD)) {
			ras_cp_rsp_work_put(conn, RAS_CP_RSP_WORK_TYPE_CODE_RSP,
					    RAS_CP_RSP_OPCODE_NOT_SUPPORTED);
			break;
		}
		ras_trans_work_err_t err = ras_transit_evt_work_put(RAS_TRANS_WORK_EVT_START, true,
								    cp_cmd->para.ranging_cnt);
		if (err) {
			ras_cp_rsp_work_put(conn, RAS_CP_RSP_WORK_TYPE_CODE_RSP, err);
			break;
		}
	} break;
	case RAS_CP_CMD_OPCODE_ACK_RD: {
		if (len != (sizeof(cp_cmd->para.ranging_cnt) + sizeof(cp_cmd->opcode))) {
			ras_cp_rsp_work_put(conn, RAS_CP_RSP_WORK_TYPE_CODE_RSP,
					    RAS_CP_RSP_INVALID_PARAMETER);
			break;
		}

		if (ras.ras_trs_work.pending_cnt ||
		    ras.ras_trs_work.event == RAS_TRANS_WORK_EVT_CONT) {
			ras_cp_rsp_work_put(conn, RAS_CP_RSP_WORK_TYPE_CODE_RSP,
					    RAS_CP_RSP_SERVER_BUSY);
			break;
		}

		if (!ras_rdbuf_free_buf(cp_cmd->para.ranging_cnt)) {
			ras_cp_rsp_work_put(conn, RAS_CP_RSP_WORK_TYPE_CODE_RSP,
					    RAS_CP_RSP_NO_RECORDS_FOUND);
			break;
		}

		ras_cp_rsp_work_put(conn, RAS_CP_RSP_WORK_TYPE_CODE_RSP, RAS_CP_RSP_SUCCESS);

		// Clear RAS_CP_ACK_DATA_TIMEOUT timer
		ras_timeout_evt_work_cancel(cp_cmd->para.ranging_cnt);

	} break;
	case RAS_CP_CMD_OPCODE_RETRIEVE_LOST_RD_SEGMENTS:
	case RAS_CP_CMD_OPCODE_ABORT_OP:
	case RAS_CP_CMD_OPCODE_SET_FILTER: {
		LOG_WRN("Unsupport command");
		ras_cp_rsp_work_put(conn, RAS_CP_RSP_WORK_TYPE_CODE_RSP,
				    RAS_CP_RSP_OPCODE_NOT_SUPPORTED);
	} break;
	default: {
		LOG_ERR("Unexpected command");
		ras_cp_rsp_work_put(conn, RAS_CP_RSP_WORK_TYPE_CODE_RSP,
				    RAS_CP_RSP_OPCODE_NOT_SUPPORTED);
	} break;
	}

	return len;
}

static void ras_cp_ccc_changed(const struct bt_gatt_attr *attr, uint16_t value)
{
	LOG_INF("cp ccc:%u", value);
}

static ssize_t ras_read_rd_ready(struct bt_conn *conn, const struct bt_gatt_attr *attr, void *buf,
				 uint16_t len, uint16_t offset)
{
	return bt_gatt_attr_read(conn, attr, buf, len, offset, &ras.ras_rd_ready_cnt,
				 sizeof(ras.ras_rd_ready_cnt));
}

static void ras_rd_ready_ccc_changed(const struct bt_gatt_attr *attr, uint16_t value)
{
	LOG_INF("ready ccc:%u", value);
}

static ssize_t ras_read_rd_ovrwrt(struct bt_conn *conn, const struct bt_gatt_attr *attr, void *buf,
				  uint16_t len, uint16_t offset)
{
	return bt_gatt_attr_read(conn, attr, buf, len, offset, &ras.ras_rd_ovrwrt_cnt,
				 sizeof(ras.ras_rd_ovrwrt_cnt));
}

static void ras_rd_ovrwrt_ccc_changed(const struct bt_gatt_attr *attr, uint16_t value)
{
	LOG_INF("overwrite ccc:%u", value);
}

// Ranging Service Declaration
BT_GATT_SERVICE_DEFINE(
	ras_svc, BT_GATT_PRIMARY_SERVICE(BT_UUID_RAS),
	BT_GATT_CHARACTERISTIC(BT_UUID_RAS_FEATURES, BT_GATT_CHRC_READ, BT_GATT_PERM_READ_ENCRYPT,
			       ras_read_ras_feature, NULL, &ras.ras_feature),
#if CONFIG_RAS_REAL_TIME_RD
	BT_GATT_CHARACTERISTIC(BT_UUID_RAS_REALTIME_RD, BT_GATT_CHRC_INDICATE | BT_GATT_CHRC_NOTIFY,
			       BT_GATT_PERM_NONE, NULL, NULL, NULL),
	BT_GATT_CCC_MANAGED(
		((struct bt_gatt_ccc_managed_user_data[]){BT_GATT_CCC_MANAGED_USER_DATA_INIT(
			ras_realtime_rd_ccc_changed, ras_realtime_rd_ccc_write_cfm, NULL)}),
		BT_GATT_PERM_READ_ENCRYPT | BT_GATT_PERM_WRITE_ENCRYPT),
#endif
	BT_GATT_CHARACTERISTIC(BT_UUID_RAS_ONDEMAND_RD, BT_GATT_CHRC_INDICATE | BT_GATT_CHRC_NOTIFY,
			       BT_GATT_PERM_NONE, NULL, NULL, NULL),
	BT_GATT_CCC_MANAGED(
		((struct bt_gatt_ccc_managed_user_data[]){BT_GATT_CCC_MANAGED_USER_DATA_INIT(
			ras_ondemand_rd_ccc_changed, ras_ondemand_rd_ccc_write_cfm, NULL)}),
		BT_GATT_PERM_READ_ENCRYPT | BT_GATT_PERM_WRITE_ENCRYPT),
	BT_GATT_CHARACTERISTIC(BT_UUID_RAS_CP,
			       BT_GATT_CHRC_WRITE_WITHOUT_RESP | BT_GATT_CHRC_INDICATE,
			       BT_GATT_PERM_WRITE_ENCRYPT, NULL, ras_write_control_point, NULL),
	BT_GATT_CCC(ras_cp_ccc_changed, BT_GATT_PERM_READ_ENCRYPT | BT_GATT_PERM_WRITE_ENCRYPT),
	BT_GATT_CHARACTERISTIC(BT_UUID_RAS_RD_READY,
			       BT_GATT_CHRC_READ | BT_GATT_CHRC_INDICATE | BT_GATT_CHRC_NOTIFY,
			       BT_GATT_PERM_READ_ENCRYPT, ras_read_rd_ready, NULL,
			       &ras.ras_rd_ready_cnt),
	BT_GATT_CCC(ras_rd_ready_ccc_changed,
		    BT_GATT_PERM_READ_ENCRYPT | BT_GATT_PERM_WRITE_ENCRYPT),
	BT_GATT_CHARACTERISTIC(BT_UUID_RAS_RD_OVERWRITTEN,
			       BT_GATT_CHRC_READ | BT_GATT_CHRC_INDICATE | BT_GATT_CHRC_NOTIFY,
			       BT_GATT_PERM_READ_ENCRYPT, ras_read_rd_ovrwrt, NULL,
			       &ras.ras_rd_ovrwrt_cnt),
	BT_GATT_CCC(ras_rd_ovrwrt_ccc_changed,
		    BT_GATT_PERM_READ_ENCRYPT | BT_GATT_PERM_WRITE_ENCRYPT), );

static bool ras_ind_notify_is_enable(struct bt_conn *conn, const struct bt_uuid *uuid)
{
	struct bt_gatt_attr *attr = bt_gatt_find_by_uuid(ras_svc.attrs, ras_svc.attr_count, uuid);

	if (!attr || !conn) {
		LOG_ERR("Unkown UUID:%#x or conn:%p", BT_UUID_16(uuid)->val, (void *)conn);
		return false;
	}

	// Priority of Indicate is higher than notify.
	if (bt_gatt_is_subscribed(conn, attr, BT_GATT_CCC_INDICATE) ||
	    bt_gatt_is_subscribed(conn, attr, BT_GATT_CCC_NOTIFY)) {
		return true;
	}

	return false;
}

static void ras_cp_ind_cmp_cb(struct bt_conn *conn, struct bt_gatt_indicate_params *params,
			      uint8_t err)
{
	LOG_DBG("error %u", err);
}

static int ras_cp_indicate(struct bt_conn *conn, uint16_t len)
{
	struct bt_gatt_attr *attr =
		bt_gatt_find_by_uuid(ras_svc.attrs, ras_svc.attr_count, BT_UUID_RAS_CP);

	if (!attr || !conn) {
		LOG_ERR("cp ind:Invalid input:%p %p", (void *)attr, (void *)conn);
		return -EINVAL;
	}

	if (bt_gatt_is_subscribed(conn, attr, BT_GATT_CCC_INDICATE)) {
		ras.ras_cp_para.attr = attr;
		ras.ras_cp_para.data = &ras.ras_cp_rsp;
		ras.ras_cp_para.len = len;
		ras.ras_cp_para.func = ras_cp_ind_cmp_cb;
		int err = bt_gatt_indicate(conn, &ras.ras_cp_para);
		if (err) {
			LOG_DBG("Failed to send ind:%x (err %d)\n", ras.ras_cp_rsp.opcode, err);
		}
		return err;
	}

	LOG_WRN("Peer is not subscribed UUID:%x", BT_UUID_RAS_CP_VAL);
	return -EINVAL;
}

static void ras_rd_seg_notify_cmp_cb(struct bt_conn *conn, void *user_data)
{
	LOG_DBG("seg notify complete");
}

static void ras_rd_seg_ind_cmp_cb(struct bt_conn *conn, struct bt_gatt_indicate_params *params,
				  uint8_t err)
{
	LOG_DBG("error %u", err);
}

static int ras_rd_seg_notify_or_indicate(struct bt_conn *conn, const struct bt_uuid *uuid,
					 ras_seg_data_t *seg_data, uint16_t len)
{
	struct bt_gatt_attr *attr = bt_gatt_find_by_uuid(ras_svc.attrs, ras_svc.attr_count, uuid);

	if (!attr || !conn) {
		LOG_ERR("seg nrf:Invalid input:%p %p", (void *)attr, (void *)conn);
		return -EINVAL;
	}

	// Priority of Notify is higher than Idication.
	if (bt_gatt_is_subscribed(conn, attr, BT_GATT_CCC_NOTIFY)) {
		struct bt_gatt_notify_params notify_param = {
			.data = seg_data,
			.len = len,
			.func = ras_rd_seg_notify_cmp_cb,
			.attr = attr,
		};
		int err = bt_gatt_notify_cb(conn, &notify_param);
		if (err) {
			LOG_DBG("Failed to send ind (err %d)\n", err);
		}
		return err;
	} else if (bt_gatt_is_subscribed(conn, attr, BT_GATT_CCC_INDICATE)) {
		ras.ras_trs_work.ras_rd_trans_para.attr = attr;
		ras.ras_trs_work.ras_rd_trans_para.data = seg_data,
		ras.ras_trs_work.ras_rd_trans_para.len = len;
		ras.ras_trs_work.ras_rd_trans_para.func = ras_rd_seg_ind_cmp_cb;
		int err = bt_gatt_indicate(conn, &ras.ras_trs_work.ras_rd_trans_para);
		if (err) {
			LOG_DBG("Failed to send ind (err %d)\n", err);
		}
		return err;
	}

	LOG_WRN("Peer is not subscribed UUID:%x", BT_UUID_16(uuid)->val);
	return -EINVAL;
}

static ras_trans_work_err_t ras_transit_evt_work_put(ras_trans_work_evt_t evt, bool is_on_demand,
						     uint16_t ranging_cnt)
{
	if (ras.ras_trs_work.pending_cnt) {
		LOG_ERR("trans event drop:%d->%d, cnt:%u", ras.ras_trs_work.event, evt,
			ras.ras_trs_work.pending_cnt);
		return RAS_TRANS_WORK_ERR_BUSY;
	}
	if (evt == RAS_TRANS_WORK_EVT_START) {
		// Check previous state
		if (ras.ras_trs_work.event == RAS_TRANS_WORK_EVT_CONT) {
			LOG_ERR("Previous Flow did no cmp");
			return RAS_TRANS_WORK_ERR_BUSY;
		}
		// Find the ranging data buffer
		ras.ras_trs_work.rd_buf = ras_rdbuf_get_buf(ranging_cnt);
		if (!ras.ras_trs_work.rd_buf) {
			LOG_ERR("No Ranging Data:%d", ranging_cnt);
			return RAS_TRANS_WORK_ERR_NO_DATA;
		}
		if (is_on_demand) {
			ras_cp_rsp_work_put(ras.curr_conn, RAS_CP_RSP_WORK_TYPE_CODE_RSP,
					    RAS_CP_RSP_SUCCESS);
		}
		ras.ras_trs_work.ranging_cnt = ranging_cnt;
		ras.ras_trs_work.sent_len = 0;
		ras.ras_trs_work.seg_cnt = 0;
	}
	ras.ras_trs_work.pending_cnt += 1;
	ras.ras_trs_work.event = evt;
	ras.ras_trs_work.is_on_demand = is_on_demand;
	atm_work_submit_to_app_work_q(&ras.ras_trs_work.work);
	return RAS_TRANS_WORK_ERR_SUCCESS;
}

static void ras_transit_evt_work_cancel(void)
{
	int ret = k_work_cancel(&ras.ras_trs_work.work);

	/* If work is not running, we can safely clear the info */
	if (!(ret & K_WORK_RUNNING)) {
		ras.ras_trs_work.pending_cnt = 0;
		ras.ras_trs_work.event = 0;
	} else {
		/* Work is still running, mark it as cancelled so the handler can detect it */
		ras.ras_trs_work.event = RAS_TRANS_WORK_EVT_INVALID;
		/* The running work handler will decrement pending_cnt when it exits */
		LOG_WRN("Cancel work as work is running");
	}
}

static void ras_rd_seg_trans_work_handler(struct k_work *work)
{
	struct ras_rd_trans_work_info_s *info =
		CONTAINER_OF(work, struct ras_rd_trans_work_info_s, work);

	LOG_DBG("%d", info->event);

	/* Check if work was cancelled while running */
	if (info->event == RAS_TRANS_WORK_EVT_INVALID) {
		LOG_DBG("Work was cancelled, exiting");
		info->pending_cnt -= 1;
		info->event = 0; /* Clear the invalid state */
		return;
	}

	if (!ras.curr_conn || !info->rd_buf) {
		LOG_ERR("Link is disconnect or data miss");
		info->pending_cnt -= 1;
		return;
	}

	struct bt_uuid const *uuid =
		info->is_on_demand ? BT_UUID_RAS_ONDEMAND_RD : BT_UUID_RAS_REALTIME_RD;

	// Get max size
	uint16_t seg_max = bt_gatt_get_mtu(ras.curr_conn) - RAS_SEG_DATA_GATT_HDR;
	int16_t unsend_len = info->rd_buf->data_offset - info->sent_len;

	if (unsend_len < 0) {
		LOG_ERR("Unexpected data length");
		info->pending_cnt -= 1;
		return;
	}

	if (unsend_len > seg_max) {
		unsend_len = seg_max;
	}

	info->seg_buf.header.first_seg = 0;
	info->seg_buf.header.last_seg = 0;

	switch (info->event) {
	case RAS_TRANS_WORK_EVT_START: {
		info->seg_buf.header.first_seg = 1;
	}
	case RAS_TRANS_WORK_EVT_CONT: {
		info->seg_buf.header.seg_counter = info->seg_cnt;
		memcpy(info->seg_buf.seg_data, &info->rd_buf->proc_data[info->sent_len],
		       unsend_len);
		info->sent_len += unsend_len;
		info->seg_cnt += 1;
		if (info->sent_len >= info->rd_buf->data_offset) {
			info->seg_buf.header.last_seg = 1;
		}
		ras_rd_seg_notify_or_indicate(ras.curr_conn, uuid, &info->seg_buf,
					      unsend_len + sizeof(info->seg_buf.header));
	} break;
	case RAS_TRANS_WORK_EVT_END: {
		if (info->is_on_demand) {
			ras_cp_rsp_work_put(ras.curr_conn, RAS_CP_RSP_WORK_TYPE_CMP_RD_RSP,
					    info->ranging_cnt);
		} else {
			ras_rdbuf_free_buf(info->ranging_cnt);
		}
	} break;
	default: {
		LOG_ERR("Unexpected event");
	} break;
	}

	// Clear the count as task finished. Need to clear as earlier return
	info->pending_cnt -= 1;
	// Trigger next step
	if (info->event != RAS_TRANS_WORK_EVT_END && info->event != RAS_TRANS_WORK_EVT_INVALID) {
		if (info->seg_buf.header.last_seg) {
			ras_transit_evt_work_put(RAS_TRANS_WORK_EVT_END, info->is_on_demand,
						 info->ranging_cnt);
		} else {
			ras_transit_evt_work_put(RAS_TRANS_WORK_EVT_CONT, info->is_on_demand,
						 info->ranging_cnt);
		}
	}
}

static void ras_rd_sts_notify_cmp_cb(struct bt_conn *conn, void *user_data)
{
	LOG_DBG("sts notify completed");
}

static void ras_rd_sts_ind_cmp_cb(struct bt_conn *conn, struct bt_gatt_indicate_params *params,
				  uint8_t err)
{
	LOG_DBG("error %u", err);
}

static int ras_rd_sts_notify_or_indicate(struct bt_conn *conn, const struct bt_uuid *uuid,
					 uint16_t ranging_counter)
{
	struct bt_gatt_attr *attr = bt_gatt_find_by_uuid(ras_svc.attrs, ras_svc.attr_count, uuid);

	if (!attr || !conn) {
		LOG_ERR("sts nrf:Invalid input:%p %p", (void *)attr, (void *)conn);
		return -EINVAL;
	}

	// Priority of Indicate is higher than notify.
	if (bt_gatt_is_subscribed(conn, attr, BT_GATT_CCC_INDICATE)) {
		ras.ras_rd_sts_para.attr = attr;
		ras.ras_rd_sts_para.data = &ranging_counter,
		ras.ras_rd_sts_para.len = sizeof(ranging_counter);
		ras.ras_rd_sts_para.func = ras_rd_sts_ind_cmp_cb;
		int err = bt_gatt_indicate(conn, &ras.ras_rd_sts_para);
		if (err) {
			LOG_DBG("Failed to send ind (err %d)\n", err);
		}
		return err;
	} else if (bt_gatt_is_subscribed(conn, attr, BT_GATT_CCC_NOTIFY)) {
		struct bt_gatt_notify_params notify_param = {
			.data = &ranging_counter,
			.len = sizeof(ranging_counter),
			.func = ras_rd_sts_notify_cmp_cb,
			.attr = attr,
		};
		int err = bt_gatt_notify_cb(conn, &notify_param);
		if (err) {
			LOG_DBG("Failed to send ind (err %d)\n", err);
		}
		return err;
	}

	LOG_WRN("Peer is not subscribed UUID:%x", BT_UUID_16(uuid)->val);
	return -EINVAL;
}

static void ras_sts_work_handler(struct k_work *work)
{
	struct ras_sts_work_info_s *info = CONTAINER_OF(work, struct ras_sts_work_info_s, work);

	LOG_DBG("%d", info->event);

	if (!ras.curr_conn) {
		LOG_ERR("Link is disconnect");
		k_free(info);
		ras.sts_work_pending -= 1;
		return;
	}

	switch (info->event) {
	case RAS_STS_WORK_EVT_RD_READY: {
#if CONFIG_RAS_REAL_TIME_RD
		if (ras_ind_notify_is_enable(ras.curr_conn, BT_UUID_RAS_REALTIME_RD)) {
			ras_transit_evt_work_put(RAS_TRANS_WORK_EVT_START, false,
						 ras.ras_rd_ready_cnt);
		} else
#endif
		{
			ras_rd_sts_notify_or_indicate(ras.curr_conn, BT_UUID_RAS_RD_READY,
						      ras.ras_rd_ready_cnt);
		}
	} break;
	case RAS_STS_WORK_EVT_RD_OVRWRT: {
		// Stop procedure since data is overwritten
		ras_transit_evt_work_cancel();
		ras_timeout_evt_work_cancel(ras.ras_rd_ovrwrt_cnt);
#if CONFIG_RAS_REAL_TIME_RD
		if (ras_ind_notify_is_enable(ras.curr_conn, BT_UUID_RAS_REALTIME_RD)) {
			break;
		}
#endif
		ras_rd_sts_notify_or_indicate(ras.curr_conn, BT_UUID_RAS_RD_OVERWRITTEN,
					      ras.ras_rd_ovrwrt_cnt);
	} break;
	default: {
		LOG_ERR("Unexpected event");
	} break;
	}
	k_free(info);
	ras.sts_work_pending -= 1;
}

static void ras_sts_evt_work_put(ras_sts_work_evt_t evt)
{
	ras_sts_work_info_t *sts_wrk = k_malloc(sizeof(ras_sts_work_info_t));
	if (!sts_wrk) {
		LOG_ERR("Failed to allocate memory for status work");
		return;
	}
	k_work_init(&sts_wrk->work, ras_sts_work_handler);
	sts_wrk->event = evt;
	atm_work_submit_to_app_work_q(&sts_wrk->work);
	ras.sts_work_pending += 1;
}

static void ras_cp_rsp_work_handler(struct k_work *work)
{
	ras_cp_rsp_work_info_t *info = CONTAINER_OF(work, ras_cp_rsp_work_info_t, work);

	LOG_DBG("cp rsp: type=%u", info->type);

	if (!info->conn || info->conn != ras.curr_conn) {
		LOG_ERR("Connection mismatch or null");
		k_free(info);
		ras.cp_rsp_work_pending -= 1;
		return;
	}

	uint16_t len;
	int err = 0;

	switch (info->type) {
	case RAS_CP_RSP_WORK_TYPE_CODE_RSP: {
		ras.ras_cp_rsp.opcode = RAS_CP_RSP_OPCODE_RSP_CODE;
		ras.ras_cp_rsp.para.code_val = info->para.rsp_code;
		len = sizeof(ras.ras_cp_rsp.para.code_val) + RAS_CP_OPCODE_LEN;
		ras_cp_indicate(info->conn, len);
	} break;
	case RAS_CP_RSP_WORK_TYPE_CMP_RD_RSP: {
		ras.ras_cp_rsp.opcode = RAS_CP_RSP_OPCODE_COMPLETE_RD_RSP;
		ras.ras_cp_rsp.para.ranging_cnt = info->para.ranging_counter;
		len = sizeof(ras.ras_cp_rsp.para.ranging_cnt) + RAS_CP_OPCODE_LEN;
		err = ras_cp_indicate(info->conn, len);
		if (!err) {
			// Wait Ack within RAS_CP_ACK_DATA_TIMEOUT
			ras_timeout_evt_work_put(RAS_TIMEOUT_WORK_EVT_WAIT_ACK,
						 info->para.ranging_counter,
						 RAS_CP_ACK_DATA_TIMEOUT);
		} else {
			LOG_ERR("ras_cp_indicate failed: %d", err);
		}
	} break;
	default: {
		LOG_ERR("Unexpected response type: %u", info->type);
	} break;
	}

	k_free(info);
	ras.cp_rsp_work_pending -= 1;
}

static void ras_cp_rsp_work_put(struct bt_conn *conn, ras_cp_rsp_work_type_t type, uint16_t param)
{
	ras_cp_rsp_work_info_t *cp_rsp_wrk = k_malloc(sizeof(ras_cp_rsp_work_info_t));
	if (!cp_rsp_wrk) {
		LOG_ERR("Failed to allocate memory for CP response work (type=%u, param=%u)", type,
			param);

		// Fallback: send SERVER_BUSY response synchronously only if no other work is
		// pending This ensures proper response ordering
		if (type == RAS_CP_RSP_WORK_TYPE_CODE_RSP && ras.cp_rsp_work_pending == 0) {
			ras.ras_cp_rsp.opcode = RAS_CP_RSP_OPCODE_RSP_CODE;
			ras.ras_cp_rsp.para.code_val = RAS_CP_RSP_SERVER_BUSY;
			uint16_t len = sizeof(ras.ras_cp_rsp.para.code_val) + RAS_CP_OPCODE_LEN;
			int err = ras_cp_indicate(conn, len);
			if (err) {
				LOG_ERR("Failed to send fallback response: %d", err);
			}
		} else {
			// Cannot send response due to pending work or memory failure
			// Log the critical failure - client may timeout
			LOG_ERR("Critical: Cannot send response due to memory failure (pending=%u)",
				ras.cp_rsp_work_pending);
		}
		return;
	}

	k_work_init(&cp_rsp_wrk->work, ras_cp_rsp_work_handler);
	cp_rsp_wrk->conn = conn;
	cp_rsp_wrk->type = type;

	switch (type) {
	case RAS_CP_RSP_WORK_TYPE_CODE_RSP:
		cp_rsp_wrk->para.rsp_code = (uint8_t)param;
		break;
	case RAS_CP_RSP_WORK_TYPE_CMP_RD_RSP:
		cp_rsp_wrk->para.ranging_counter = param;
		break;
	default:
		LOG_ERR("Invalid work type: %u", type);
		k_free(cp_rsp_wrk);
		return;
	}

	atm_work_submit_to_app_work_q(&cp_rsp_wrk->work);
	ras.cp_rsp_work_pending += 1;
}

#ifdef CONFIG_RAS_SECURE_FORCE_DISCONN
static void ras_disconnect(void)
{
	if (!ras.curr_conn) {
		return;
	}
	bt_conn_disconnect(ras.curr_conn, BT_HCI_ERR_REMOTE_USER_TERM_CONN);
}
#endif

#if RAS_CONN_WORK_EVT_INVALID > 0
static void ras_conn_work_handler(struct k_work *work)
{
	ras_conn_work_info_t *info = CONTAINER_OF(work, struct ras_conn_work_info_s, work);

	LOG_DBG("conn evt:%u", info->event);

	if (!ras.curr_conn) {
		LOG_ERR("Link is disconnect");
		info->pending_cnt -= 1;
		return;
	}

	switch (info->event) {
#ifdef CONFIG_RAS_ACTIVE_SECURE_CHANGE
	case RAS_CONN_WORK_EVT_SECURE_LVL: {
		int error = bt_conn_set_security(ras.curr_conn, CONFIG_RAS_SECURE_LVL);
		if (error) {
			LOG_ERR("Failed to set security %d", error);
		}
	} break;
#endif
#ifdef CONFIG_RAS_SECURE_FORCE_DISCONN
	case RAS_CONN_WORK_EVT_FORCE_DISC: {
		ras_disconnect();
	} break;
#endif
	default: {
		LOG_ERR("Unexpected event");
	} break;
	}
	info->pending_cnt -= 1;
}

static void ras_conn_evt_work_put(ras_conn_work_evt_t evt)
{
	if (ras.ras_conn_work.pending_cnt) {
		LOG_ERR("conn evt overwrite:%d->%d", ras.ras_conn_work.event, evt);
	} else {
		ras.ras_conn_work.pending_cnt += 1;
	}
	ras.ras_conn_work.event = evt;
	atm_work_submit_to_app_work_q(&ras.ras_conn_work.work);
}
#endif

static void ras_connected(struct bt_conn *conn, uint8_t err)
{
	char addr[BT_ADDR_LE_STR_LEN];
	bt_addr_le_to_str(bt_conn_get_dst(conn), addr, sizeof(addr));
	if (err) {
		LOG_ERR("Failed to connect to %s (%u)", addr, err);
		return;
	}
	LOG_INF("Connected %s", addr);
#ifdef CONFIG_RAS_ACTIVE_SECURE_CHANGE
	ras_conn_evt_work_put(RAS_CONN_WORK_EVT_SECURE_LVL);
#endif
}

static void ras_clear_work(void)
{
#if RAS_CONN_WORK_EVT_INVALID > 0
	k_work_cancel(&ras.ras_conn_work.work);
	ras.ras_conn_work.pending_cnt = 0;
#endif
	k_work_cancel_delayable(&ras.ras_timeout_work.work);
	ras.ras_timeout_work.pending_cnt = 0;
	LOG_INF("RAS sts work:%u, cp_rsp work:%u", ras.sts_work_pending, ras.cp_rsp_work_pending);
}

static void ras_disconnected(struct bt_conn *conn, uint8_t reason)
{
	char addr[BT_ADDR_LE_STR_LEN];
	bt_addr_le_to_str(bt_conn_get_dst(conn), addr, sizeof(addr));
	LOG_INF("Disconnected %s reason:%#x", addr, reason);
	if (ras.curr_conn != conn) {
		LOG_WRN("Not RAS connect");
		return;
	}
	ras.curr_conn = NULL;
	// Clear all work queue related connection
	ras_clear_work();
	// Clear all data buf
	ras_rdbuf_free_all_buf();
}

static void ras_security_changed(struct bt_conn *conn, bt_security_t level,
				 enum bt_security_err err)
{
	char addr[BT_ADDR_LE_STR_LEN];
	bt_addr_le_to_str(bt_conn_get_dst(conn), addr, sizeof(addr));

	if (err || (level < CONFIG_RAS_SECURE_LVL)) {
		LOG_ERR("Security failed:%s level:%u err:%d", addr, level, err);
#ifdef CONFIG_RAS_SECURE_FORCE_DISCONN
		ras_conn_evt_work_put(RAS_CONN_WORK_EVT_FORCE_DISC);
#endif
		return;
	}
	struct bt_conn_info info;
	bt_conn_get_info(conn, &info);

	LOG_INF("Security changed:%s level:%u ID:%d", addr, level, info.id);
}

static void ras_le_param_updated(struct bt_conn *conn, uint16_t interval, uint16_t latency,
				 uint16_t timeout)
{
	LOG_INF("interval:%u latency:%u timeout:%u", interval, latency, timeout);
}

static void ras_cs_procedure_enabled_cb(struct bt_conn *conn, uint8_t status,
					struct bt_conn_le_cs_procedure_enable_complete *params)
{
	if (status == BT_HCI_ERR_SUCCESS) {
		if (params->state == BT_CONN_LE_CS_PROCEDURES_ENABLED) {
			LOG_INF("CS procedures enabled.");
			if (!ras.curr_conn) {
				LOG_INF("cs enable: Update connect");
				ras.curr_conn = conn;
			}
			ras.cs_select_tx_pwr = params->selected_tx_power;
		} else {
			LOG_INF("CS procedures disabled.");
		}
	}
}

static void ras_rdbuf_update_data(struct bt_conn_le_cs_subevent_result *result)
{
	// Search buf
	ras_rd_buffer_t *buf = ras_rdbuf_get_buf(result->header.procedure_counter);

	// New data
	if (!buf) {
		// Update procedure counter
		buf = ras_rdbuf_get_new();
		if (!buf) {
			// Overwrite data
			buf = ras_rdbuf_free_one_buf(&ras.ras_rd_ovrwrt_cnt);
			if (!buf) {
				LOG_ERR("No buffer for ranging data: %d",
					result->header.procedure_counter);
				return;
			}
			ras_sts_evt_work_put(RAS_STS_WORK_EVT_RD_OVRWRT);
		}

		if (buf->data_offset != 0) {
			LOG_ERR("Unexpected offset: %d", buf->data_offset);
			buf->data_offset = 0;
		}
		buf->status = RAS_BUF_UPDATING;
		buf->ranging_cnt = result->header.procedure_counter;
		/// Update Ranging Header
		ras_rd_header_t *rd_hdr = (ras_rd_header_t *)&buf->proc_data[0];
		rd_hdr->ranging_counter = result->header.procedure_counter;
		rd_hdr->cfg_id = result->header.config_id;
		rd_hdr->tx_pwr = ras.cs_select_tx_pwr;
		rd_hdr->antenna_path_masks = BIT_MASK(result->header.num_antenna_paths);
		buf->data_offset = sizeof(ras_rd_header_t);
	}

	// Update subevent header
	ras_rd_subevent_hdr_t *subevt_hdr =
		(ras_rd_subevent_hdr_t *)&buf->proc_data[buf->data_offset];

	subevt_hdr->acl_conn_evt = result->header.start_acl_conn_event;
	subevt_hdr->freq_comp = result->header.frequency_compensation;
	subevt_hdr->ranging_done = result->header.procedure_done_status;
	subevt_hdr->subevt_done = result->header.subevent_done_status;
	subevt_hdr->ranging_abrt_reason = result->header.procedure_abort_reason;
	subevt_hdr->subevt_abrt_reason = result->header.subevent_abort_reason;
	subevt_hdr->ref_pwr_lvl = result->header.reference_power_level;
	subevt_hdr->reported_step = result->header.num_steps_reported;

	buf->data_offset += sizeof(ras_rd_subevent_hdr_t);

	// Update step data
	if (result->step_data_buf) {
		struct bt_hci_evt_le_cs_subevent_result_step *step;
		uint16_t step_offset = 0;
		ras_rd_step_data_t *ras_step;

		while (step_offset < result->step_data_buf->len) {
			step = (struct bt_hci_evt_le_cs_subevent_result_step *)&result
				       ->step_data_buf->data[step_offset];
			ras_step = (ras_rd_step_data_t *)&buf->proc_data[buf->data_offset];
			buf->data_offset += (sizeof(ras_rd_step_data_t) + step->step_data_length);
			if (buf->data_offset > RAS_DATA_BUFFER_MAX_SIZE) {
				LOG_ERR("Overflow: unexpected data size:%d", buf->data_offset);
				return;
			}
			ras_step->mode = step->step_mode;
			memcpy(ras_step->data, step->step_data, step->step_data_length);
			step_offset += (sizeof(struct bt_hci_evt_le_cs_subevent_result_step) +
					step->step_data_length);
		}
	}

	if (result->header.procedure_done_status != BT_CONN_LE_CS_PROCEDURE_INCOMPLETE) {
		buf->status = RAS_BUF_DONE;
		LOG_INF("Update Proc:%u done.Len:%u", buf->ranging_cnt, buf->data_offset);
	}
}

static void ras_cs_subevent_result_cb(struct bt_conn *conn,
				      struct bt_conn_le_cs_subevent_result *result)
{
	ras_rdbuf_update_data(result);

	if (result->header.subevent_done_status == BT_HCI_LE_CS_SUBEVENT_DONE_STATUS_ABORTED) {
		LOG_WRN("CS subevent abort: %u %u", result->header.procedure_counter,
			result->header.subevent_abort_reason);
	}

	if (result->header.procedure_done_status != BT_CONN_LE_CS_PROCEDURE_INCOMPLETE) {
		ras.ras_rd_ready_cnt = result->header.procedure_counter;
		ras_sts_evt_work_put(RAS_STS_WORK_EVT_RD_READY);
		LOG_INF("CS procedure%u done:0x%x", result->header.procedure_counter,
			result->header.procedure_done_status);
	}
}

BT_CONN_CB_DEFINE(ras_cb) = {
	.connected = ras_connected,
	.disconnected = ras_disconnected,
	.security_changed = ras_security_changed,
	.le_param_updated = ras_le_param_updated,
	.le_cs_procedure_enable_complete = ras_cs_procedure_enabled_cb,
	.le_cs_subevent_data_available = ras_cs_subevent_result_cb,
};

static int bt_ras_init(void)
{
	LOG_INF("ras initialized");

#if CONFIG_RAS_REAL_TIME_RD
	ras.ras_feature |= RAS_FEAT_REALTIME_RD;
#endif

#if RAS_CONN_WORK_EVT_INVALID > 0
	k_work_init(&ras.ras_conn_work.work, ras_conn_work_handler);
#endif
	k_work_init(&ras.ras_trs_work.work, ras_rd_seg_trans_work_handler);
	k_work_init_delayable(&ras.ras_timeout_work.work, ras_timeout_work_handler);

	return 0;
}

SYS_INIT(bt_ras_init, APPLICATION, CONFIG_APPLICATION_INIT_PRIORITY);

#ifdef CONFIG_RAS_PTS_FAKE_CS_DATA
#define CS_FAKE_DATA_CONFIG_ID         0
#define CS_FAKE_DATA_TXPWR             0
#define CS_FAKE_DATA_ANTENNA_PATH_MASK 0xF
int ras_fake_cs_data(uint16_t ranging_cnt)
{
	// Search buf
	ras_rd_buffer_t *buf = ras_rdbuf_get_new();
	if (!buf) {
		LOG_ERR("No buffer for fake ranging data:: %" PRIu16, ranging_cnt);
		return -ENOMEM;
	}

	// Check if buffer has enough space for fake data
	uint32_t required_size = sizeof(ras_rd_header_t) + sizeof(cs_fake_data);
	if (required_size > RAS_DATA_BUFFER_MAX_SIZE) {
		LOG_ERR("Fake data too large: required=%u, available=%u", required_size,
			RAS_DATA_BUFFER_MAX_SIZE);
		return -ENOSPC;
	}

	if (buf->data_offset) {
		LOG_ERR("Unexpected offset: %d", buf->data_offset);
		buf->data_offset = 0;
	}

	buf->status = RAS_BUF_UPDATING;
	buf->ranging_cnt = ranging_cnt;
	// Update Ranging Header
	ras_rd_header_t *rd_hdr = (ras_rd_header_t *)&buf->proc_data[0];
	rd_hdr->ranging_counter = ranging_cnt;
	rd_hdr->cfg_id = CS_FAKE_DATA_CONFIG_ID;
	rd_hdr->tx_pwr = CS_FAKE_DATA_TXPWR;
	rd_hdr->antenna_path_masks = CS_FAKE_DATA_ANTENNA_PATH_MASK;
	buf->data_offset = sizeof(ras_rd_header_t);

	// subevent header and data is included in data file
	memcpy(&buf->proc_data[buf->data_offset], cs_fake_data, sizeof(cs_fake_data));
	buf->data_offset += sizeof(cs_fake_data);
	LOG_INF("Fake data len:%u (header:%u + data:%u)", buf->data_offset, sizeof(ras_rd_header_t),
		sizeof(cs_fake_data));

	buf->status = RAS_BUF_DONE;
	ras_sts_evt_work_put(RAS_STS_WORK_EVT_RD_READY);

	return 0;
}
#endif
