/*
 * Copyright (c) 2025 Atmosic
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>
#include <zephyr/smf.h>
#include <zephyr/sys/byteorder.h>
#include <zephyr/logging/log.h>
#include <zephyr/settings/settings.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/bluetooth/bluetooth.h>
#if defined(CONFIG_READ_RSSI) || defined(CONFIG_BT_TRANSMIT_POWER_CONTROL)
#include <zephyr/bluetooth/hci_types.h>
#endif
#ifdef CONFIG_READ_RSSI
#include <zephyr/bluetooth/hci.h>
#endif
#include <zephyr/bluetooth/conn.h>
#include <zephyr/bluetooth/gap.h>
#include <zephyr/bluetooth/gatt.h>
#include <zephyr/bluetooth/uuid.h>
#include <zephyr/bluetooth/cs.h>
#ifdef CONFIG_BT_TRANSMIT_POWER_CONTROL
#include "ll_defs.h"
#endif

#include "arch.h"
#include "ras.h"
#include "app_work_q.h"

LOG_MODULE_REGISTER(rreq_smf, CONFIG_RREQ_SMF_LOG_LEVEL);
// create config
#define CREATE_CONFIG_ID              0
#define CREATE_MAIN_MODE_TYPE         BT_CONN_LE_CS_MAIN_MODE_2
#define CREATE_SUB_MODE_TYPE          BT_CONN_LE_CS_SUB_MODE_UNUSED
#define CREATE_MIN_MAIN_MODE_STEPS    0
#define CREATE_MAX_MAIN_MODE_STEPS    0
#define CREATE_MAIN_MODE_REPETITION   2
#define CREATE_MODE_0_STEPS           2
#define CREATE_RRT_TYPE               BT_CONN_LE_CS_RTT_TYPE_AA_ONLY
#define CREATE_CS_SYNC_PHY            BT_CONN_LE_CS_SYNC_1M_PHY
#define CREATE_CHANNEL_MAP_REPETITION 1
#define CREATE_CHANNEL_SELECTION_TYPE BT_CONN_LE_CS_CHSEL_TYPE_3B
#define CREATE_CH3C_SHAPE             BT_CONN_LE_CS_CH3C_SHAPE_HAT
#define CREATE_CH3C_JUMP              2

// procedure parameter
#define MAX_PROC_LEN_IN_625US  480
#define MAX_PROC_COUNT         0
#define MIN_SUBEVENT_LEN_IN_US 21900
#define MAX_SUBEVENT_LEN_IN_US 21900
#define PROC_PHY               BT_LE_CS_PROCEDURE_PHY_1M
#define PREF_PEER_ANTENNA_NUM  2
#define PREF_PEER_ANTENNA                                                                          \
	(BT_LE_CS_PROCEDURE_PREFERRED_PEER_ANTENNA_1 | BT_LE_CS_PROCEDURE_PREFERRED_PEER_ANTENNA_2)
#define SNR_CONTROL_INITIATOR BT_LE_CS_SNR_CONTROL_NOT_USED
#define SNR_CONTROL_REFLECTOR BT_LE_CS_SNR_CONTROL_NOT_USED

#define BT_RAS_STEP_MODE_2_3_TONE_INFO_LEN(antenna_paths)                                          \
	((antenna_paths + 1) * sizeof(struct bt_hci_le_cs_step_data_tone_info))
#define BT_RAS_STEP_MODE_3_MAX_LEN                                                                 \
	(sizeof(struct bt_hci_le_cs_step_data_mode_3) +                                            \
	 BT_RAS_STEP_MODE_2_3_TONE_INFO_LEN(CONFIG_RAS_CLIENT_MAX_ANTENNA_PATH_NUM))
#define BT_RAS_STEP_MODE_2_MAX_LEN                                                                 \
	(sizeof(struct bt_hci_le_cs_step_data_mode_2) +                                            \
	 BT_RAS_STEP_MODE_2_3_TONE_INFO_LEN(CONFIG_RAS_CLIENT_MAX_ANTENNA_PATH_NUM))
#define BT_RAS_STEP_MODE_0_LOCAL_MAX_LEN sizeof(struct bt_hci_le_cs_step_data_mode_0_initiator)
#define BT_RAS_STEP_MODE_1_MAX_LEN       (sizeof(struct bt_hci_le_cs_step_data_mode_1_ss_rtt))
#define BT_RAS_STEP_MODE_0_1_LOCAL_MAX_LEN                                                         \
	MAX(BT_RAS_STEP_MODE_0_LOCAL_MAX_LEN, BT_RAS_STEP_MODE_1_MAX_LEN)
#define BT_RAS_STEP_MODE_0_1_2_LOCAL_MAX_LEN                                                       \
	MAX(BT_RAS_STEP_MODE_0_1_LOCAL_MAX_LEN, BT_RAS_STEP_MODE_2_MAX_LEN)
#define BT_RAS_MAX_STEP_DATA_LOCAL_LEN                                                             \
	MAX(BT_RAS_STEP_MODE_0_1_2_LOCAL_MAX_LEN, BT_RAS_STEP_MODE_3_MAX_LEN)
#define BT_RAS_STEP_MODE_0_PEER_MAX_LEN sizeof(struct bt_hci_le_cs_step_data_mode_0_reflector)
#define BT_RAS_STEP_MODE_0_1_PEER_MAX_LEN                                                          \
	MAX(BT_RAS_STEP_MODE_0_PEER_MAX_LEN, BT_RAS_STEP_MODE_1_MAX_LEN)
#define BT_RAS_STEP_MODE_0_1_2_PEER_MAX_LEN                                                        \
	MAX(BT_RAS_STEP_MODE_0_1_PEER_MAX_LEN, BT_RAS_STEP_MODE_2_MAX_LEN)
#define BT_RAS_MAX_STEP_DATA_PEER_LEN                                                              \
	MAX(BT_RAS_STEP_MODE_0_1_2_PEER_MAX_LEN, BT_RAS_STEP_MODE_3_MAX_LEN)
#define BT_RAS_RANGING_HEADER_LEN  4
#define BT_RAS_STEP_MODE_LEN       1
#define BT_RAS_SUBEVENT_HEADER_LEN 8

#define LOCAL_PROC_SIZE                                                                            \
	((sizeof(struct bt_le_cs_subevent_step) * BT_RAS_MAX_SUBEVENTS_PER_PROCEDURE) +            \
	 (BT_RAS_MAX_STEP_DATA_LOCAL_LEN * BT_RAS_MAX_STEPS_PER_PROCEDURE))
#define PEER_PROC_SIZE                                                                             \
	(BT_RAS_RANGING_HEADER_LEN +                                                               \
	 (BT_RAS_SUBEVENT_HEADER_LEN * BT_RAS_MAX_SUBEVENTS_PER_PROCEDURE) +                       \
	 (BT_RAS_STEP_MODE_LEN + BT_RAS_MAX_STEP_DATA_PEER_LEN) * BT_RAS_MAX_STEPS_PER_PROCEDURE)

#define PROCEDURE_COUNTER_NONE (-1)

enum rreq_smf_state {
	RREQ_SMF_STATE_INIT,
	RREQ_SMF_STATE_SCAN,
	RREQ_SMF_STATE_CONNECTED,
	RREQ_SMF_STATE_CS_SETUP,
	RREQ_SMF_STATE_CS_PROC,

	RREQ_SMF_STATE_NUM
};

enum rreq_smf_evt {
	RREQ_SMF_EVT_BT_READY,
	RREQ_SMF_EVT_BT_CONNECTED,
	RREQ_SMF_EVT_BT_SEC_CHG,
	RREQ_SMF_EVT_BT_LINK_READY,
	RREQ_SMF_EVT_BT_RAS_SUBSCRIBED,
	RREQ_SMF_EVT_BT_DISCONNECTED,
	RREQ_SMF_EVT_BT_CS_PROC_ENABLED,
};

enum rreq_smf_action {
#ifdef CONFIG_BT_TRANSMIT_POWER_CONTROL
	RREQ_SMF_ENABLE_POWER_REPORTING,
#endif
	RREQ_SMF_BT_SET_SEC,
	RREQ_SMF_GATT_EXCH_MTU,
	RREQ_SMF_RAS_DISCOVER,
	RREQ_SMF_RAS_SUBSCRIBE,
	RREQ_SMF_CS_SETUP_READ_LOCAL_CAP,
	RREQ_SMF_CS_SETUP_READ_REMOTE_CAP,
	RREQ_SMF_CS_SETUP_SET_DEFAULT_SETTING,
	RREQ_SMF_CS_SETUP_READ_REMOTE_FAE_TABLE,
	RREQ_SMF_CS_SETUP_CREATE_CONFIG,
	RREQ_SMF_CS_SETUP_ENABLE_SECURITY,
	RREQ_SMF_CS_START_SET_PROC_PARAM,
	RREQ_SMF_CS_START_PROC_ENABLE,

	RREQ_SMF_ACTION_NUM
};

enum rreq_smf_rc_type {
	RREQ_SMF_RC_DROPPED,
	RREQ_SMF_RC_LOCAL,
	RREQ_SMF_RC_PEER,

	RREQ_SMF_RC_TYPE_NUM
};

enum rreq_smf_role {
	RREQ_SMF_ROLE_LOCAL,
	RREQ_SMF_ROLE_PEER,
};

#define LOCAL_ROLE_MASK BIT(RREQ_SMF_ROLE_LOCAL)
#define PEER_ROLE_MASK  BIT(RREQ_SMF_ROLE_PEER)
#define BOTH_ROLE_MASK  (LOCAL_ROLE_MASK | PEER_ROLE_MASK)

typedef struct rreq_smf_ctrl {
	struct bt_conn *curr_conn;
	int32_t ranging_counter[RREQ_SMF_RC_TYPE_NUM];
	uint16_t action_mask;
	enum rreq_smf_evt evt;
	uint8_t n_ap;
#ifdef CONFIG_ATM_BT_PHY_1M
	uint8_t retry_count;
#endif
} rreq_smf_ctrl_t;

struct dump_log_work_info {
	struct k_work work;
	uint8_t *step_data;
	uint16_t len;
	uint16_t logged_len;
	int32_t ranging_counter;
};

struct dump_log_end_work_info {
	struct k_work work;
	enum bt_conn_le_cs_procedure_done_status status;
	int32_t ranging_counter;
};

static struct dump_log_work_info rreq_dump_log_init_work_info;
static struct dump_log_end_work_info rreq_dump_log_end_work_info;
static struct smf_ctx rreq_smf_ctx;
static const struct smf_state rreq_smf_states[RREQ_SMF_STATE_NUM];
static struct gpio_callback button_cb_data;
static struct k_work rreq_button_work;
static struct k_work rreq_smf_work;
static rreq_smf_ctrl_t rreq_smf_ctl;
static uint8_t cs_preferred_peer_antenna;

NET_BUF_SIMPLE_DEFINE_STATIC(latest_local_steps, LOCAL_PROC_SIZE);
NET_BUF_SIMPLE_DEFINE_STATIC(latest_peer_steps, PEER_PROC_SIZE);

// Function declaration needed to break dependency loop
// rreq_start_scan() -> device_found() -> data_parse_cb() -> rreq_start_scan()
static void rreq_start_scan(void);

#define LOG_DUMP_THREAD_PRIORITY K_LOWEST_APPLICATION_THREAD_PRIO
static K_THREAD_STACK_DEFINE(log_dump_work_q_stack, 1024);
struct k_work_q log_dump_work_q;

static int log_dump_init(void)
{
	const struct k_work_queue_config cfg = {
		.name = "logdumpworkq",
		.no_yield = false,
		.essential = false,
	};

	k_work_queue_init(&log_dump_work_q);
	k_work_queue_start(&log_dump_work_q, log_dump_work_q_stack,
			   K_THREAD_STACK_SIZEOF(log_dump_work_q_stack), LOG_DUMP_THREAD_PRIORITY,
			   &cfg);

	return 0;
}

static void log_hexdump(const char *prefix, const uint8_t *data, size_t len)
{
#define MAX_CHAR_SIZE     90
#define NUM_DATA_ONE_LINE 40
	char msg[MAX_CHAR_SIZE];
	size_t pos = 0;

	for (size_t i = 0; i < len; i++) {
		msg[pos++] = "0123456789ABCDEF"[data[i] >> 4];
		msg[pos++] = "0123456789ABCDEF"[data[i] & 0x0F];
		if (!((i + 1) % NUM_DATA_ONE_LINE) || ((i + 1) == len)) {
			msg[pos] = '\0';
			pos = 0;
			LOG_INF("%s %s", prefix, msg);
		}
	}
}

static void reset_rd_info(uint8_t role)
{
	if (role & LOCAL_ROLE_MASK) {
		net_buf_simple_reset(&latest_local_steps);
		rreq_smf_ctl.ranging_counter[RREQ_SMF_RC_LOCAL] = PROCEDURE_COUNTER_NONE;
	}
	if (role & PEER_ROLE_MASK) {
		net_buf_simple_reset(&latest_peer_steps);
		rreq_smf_ctl.ranging_counter[RREQ_SMF_RC_PEER] = PROCEDURE_COUNTER_NONE;
	}
}

static void rreq_dump_log_init_work_handler(struct k_work *work)
{
	struct dump_log_work_info *info = CONTAINER_OF(work, struct dump_log_work_info, work);
	if (info->logged_len >= info->len) {
		LOG_INF("Now new data");
		return;
	}
	uint16_t data_len = info->len - info->logged_len;
	LOG_INF("Ini rc:%d Log:%d->%d len:%d", info->ranging_counter, info->logged_len, info->len,
		data_len);
	log_hexdump("I", &info->step_data[info->logged_len], data_len);
	info->logged_len += data_len;
}

static void rreq_dump_log_ref_work_handler(struct k_work *work)
{
	struct dump_log_work_info *info = CONTAINER_OF(work, struct dump_log_work_info, work);
	LOG_INF("Ref Procedure: len: %d rc: %d", info->len, info->ranging_counter);
	log_hexdump("R", info->step_data, info->len);
	uint8_t *end = info->step_data + info->len;
	if (end != latest_peer_steps.data) {
		LOG_INF("More step data in buf:%d", latest_peer_steps.data - end);
	} else {
		reset_rd_info(PEER_ROLE_MASK);
	}
	k_free(info);
}

static void rreq_submit_ref_log_work(uint16_t ranging_counter, uint8_t *step_data, uint16_t len)
{
	struct dump_log_work_info *info = k_malloc(sizeof(struct dump_log_work_info));
	if (!info) {
		LOG_ERR("alloc work info failed");
		return;
	}
	k_work_init(&info->work, rreq_dump_log_ref_work_handler);
	info->len = len;
	info->ranging_counter = ranging_counter;
	info->step_data = step_data;
	k_work_submit_to_queue(&log_dump_work_q, &info->work);
}

#ifdef CONFIG_READ_RSSI
static void read_conn_rssi(uint16_t handle, int8_t *rssi)
{
	struct net_buf *buf = bt_hci_cmd_alloc(K_FOREVER);
	if (!buf) {
		LOG_ERR("Unable to alloc buf");
		return;
	}

	struct bt_hci_cp_read_rssi *cp = net_buf_add(buf, sizeof(*cp));
	cp->handle = sys_cpu_to_le16(handle);

	struct net_buf *rsp;
	int err = bt_hci_cmd_send_sync(BT_HCI_OP_READ_RSSI, buf, &rsp);
	if (err) {
		LOG_ERR("Read RSSI err:%d", err);
		return;
	}

	struct bt_hci_rp_read_rssi *rp = (void *)rsp->data;
	*rssi = rp->rssi;

	net_buf_unref(rsp);
}
#endif

static void rreq_dump_log_work_end_handler(struct k_work *work)
{
	struct dump_log_end_work_info *info =
		CONTAINER_OF(work, struct dump_log_end_work_info, work);
	if (info->status == BT_CONN_LE_CS_PROCEDURE_COMPLETE) {
		LOG_INF("*work_end rc:%u", info->ranging_counter);
		LOG_INF("Procedure end:");
		net_buf_simple_reset(&latest_local_steps);
	} else if (info->status == BT_CONN_LE_CS_PROCEDURE_ABORTED) {
		LOG_WRN("Procedure aborted");
		reset_rd_info(LOCAL_ROLE_MASK);
	}
#ifdef CONFIG_READ_RSSI
	int8_t rssi = 0xFF;
	read_conn_rssi(bt_conn_index(rreq_smf_ctl.curr_conn), &rssi);
	LOG_INF("RSSI: %d", rssi);
#endif
}

static void rreq_run_event(enum rreq_smf_evt evt)
{
	rreq_smf_ctl.evt = evt;
	smf_run_state(SMF_CTX(&rreq_smf_ctx));
}

#if defined(CONFIG_RREQ_LOG_LEVEL) && (CONFIG_RREQ_LOG_LEVEL >= LOG_LEVEL_INF)
static void rreq_addr_log(const char *func, const bt_addr_le_t *addr, uint8_t err)
{
	char addr_str[BT_ADDR_LE_STR_LEN];
	bt_addr_le_to_str(addr, addr_str, sizeof(addr_str));
	LOG_INF("%s: addr:%s err:%#x", func, addr_str, err);
}
#define ADDR_LOG(func, conn, err) rreq_addr_log(func, conn, err)
#else
#define ADDR_LOG(func, conn, err)
#endif

static void rreq_connected(struct bt_conn *conn, uint8_t err)
{
	ADDR_LOG("conn", bt_conn_get_dst(conn), err);

	if (err) {
		LOG_ERR("conn failed err:%d", err);
		bt_conn_unref(conn);
		rreq_smf_ctl.curr_conn = NULL;
		rreq_run_event(RREQ_SMF_EVT_BT_DISCONNECTED);
		return;
	}
	rreq_smf_ctl.curr_conn = conn;
	rreq_run_event(RREQ_SMF_EVT_BT_CONNECTED);
	atm_work_submit_to_app_work_q(&rreq_smf_work);
}

static void rreq_disconnected(struct bt_conn *conn, uint8_t reason)
{
	ADDR_LOG("disconn", bt_conn_get_dst(conn), reason);

	bt_conn_unref(rreq_smf_ctl.curr_conn);
	rreq_smf_ctl.curr_conn = NULL;
	rreq_smf_ctl.action_mask = 0;
#ifdef CONFIG_ATM_BT_PHY_1M
	rreq_smf_ctl.retry_count = 0;
#endif
	rreq_run_event(RREQ_SMF_EVT_BT_DISCONNECTED);
}

static void rreq_security_changed(struct bt_conn *conn, bt_security_t level,
				  enum bt_security_err err)
{
	if (err) {
		LOG_ERR("sec chg err:%u", err);
		int error = bt_conn_disconnect(rreq_smf_ctl.curr_conn,
					       BT_HCI_ERR_REMOTE_USER_TERM_CONN);
		if (error) {
			LOG_ERR("disc err:%d", error);
		}
		return;
	}
	rreq_smf_ctl.action_mask |= BIT(RREQ_SMF_BT_SET_SEC);
	rreq_run_event(RREQ_SMF_EVT_BT_SEC_CHG);
}

static void rreq_cs_remote_capabilities(struct bt_conn *conn, uint8_t status,
					struct bt_conn_le_cs_capabilities *params)
{
	LOG_DBG("CS cap exchange cmpl");
	if (status == BT_HCI_ERR_SUCCESS) {
		rreq_smf_ctl.action_mask |= BIT(RREQ_SMF_CS_SETUP_READ_REMOTE_CAP);
		// set the bit that will not read FAE table
		if (params->cs_without_fae_supported) {
			rreq_smf_ctl.action_mask |= BIT(RREQ_SMF_CS_SETUP_READ_REMOTE_FAE_TABLE);
		}
		cs_preferred_peer_antenna = PREF_PEER_ANTENNA;
		if (params->num_antennas_supported < PREF_PEER_ANTENNA_NUM) {
			cs_preferred_peer_antenna = BT_LE_CS_PROCEDURE_PREFERRED_PEER_ANTENNA_1;
		}
		atm_work_submit_to_app_work_q(&rreq_smf_work);
	}
}

static void rreq_cs_remote_fae_table(struct bt_conn *conn, uint8_t status,
				     struct bt_conn_le_cs_fae_table *params)
{
	ARG_UNUSED(params);
	LOG_DBG("CS fae table cmpl");
	if (status == BT_HCI_ERR_SUCCESS) {
		rreq_smf_ctl.action_mask |= BIT(RREQ_SMF_CS_SETUP_READ_REMOTE_FAE_TABLE);
		atm_work_submit_to_app_work_q(&rreq_smf_work);
	}
}

static void rreq_cs_config_created(struct bt_conn *conn, uint8_t status,
				   struct bt_conn_le_cs_config *config)
{
	LOG_DBG("CS config creation cmpl ID:%d", config->id);
	if (status == BT_HCI_ERR_SUCCESS) {
		rreq_smf_ctl.action_mask |= BIT(RREQ_SMF_CS_SETUP_CREATE_CONFIG);
		atm_work_submit_to_app_work_q(&rreq_smf_work);
	}
}

static void rreq_cs_security_enabled(struct bt_conn *conn, uint8_t status)
{
	LOG_DBG("CS security enabled");
	if (status == BT_HCI_ERR_SUCCESS) {
		rreq_smf_ctl.action_mask |= BIT(RREQ_SMF_CS_SETUP_ENABLE_SECURITY);
		atm_work_submit_to_app_work_q(&rreq_smf_work);
	}
}

static void rreq_cs_procedure_enabled(struct bt_conn *conn, uint8_t status,
				      struct bt_conn_le_cs_procedure_enable_complete *params)
{
	if (status == BT_HCI_ERR_SUCCESS) {
		LOG_DBG("CS procedures enabled:%d", params->state);

		if (params->state) {
			reset_rd_info(BOTH_ROLE_MASK);
			rreq_smf_ctl.action_mask |= BIT(RREQ_SMF_CS_START_PROC_ENABLE);
			rreq_run_event(RREQ_SMF_EVT_BT_CS_PROC_ENABLED);
		} else {
			rreq_smf_ctl.action_mask &= ~BIT(RREQ_SMF_CS_START_PROC_ENABLE);
		}
	}
}

static void rreq_cs_subevent_result(struct bt_conn *conn,
				    struct bt_conn_le_cs_subevent_result *result)
{
	if (rreq_smf_ctl.ranging_counter[RREQ_SMF_RC_DROPPED] == result->header.procedure_counter) {
		LOG_WRN("dropped %d", result->header.procedure_counter);
	}
	static uint8_t subevt_idx;
	if (!subevt_idx) {
		rreq_smf_ctl.n_ap = result->header.num_antenna_paths;
		LOG_INF("Procedure start: nAP: %d", rreq_smf_ctl.n_ap);
	}

	if (result->header.subevent_done_status == BT_HCI_LE_CS_SUBEVENT_DONE_STATUS_ABORTED) {
		LOG_WRN("CS subevent abort:%u %u", result->header.procedure_counter,
			result->header.subevent_abort_reason);
	}
	if (result->step_data_buf) {
		if (result->step_data_buf->len <= net_buf_simple_tailroom(&latest_local_steps)) {
			uint16_t len = result->step_data_buf->len;
			uint8_t *step_data = net_buf_simple_pull_mem(result->step_data_buf, len);
			net_buf_simple_add_mem(&latest_local_steps, step_data, len);
			LOG_INF("Init Proc:%d subevent:%d len:%d", result->header.procedure_counter,
				subevt_idx, len);
			if (!subevt_idx) {
				if (rreq_dump_log_init_work_info.logged_len !=
				    rreq_dump_log_init_work_info.len) {
					LOG_ERR("RC:%d log data fail. New event start.",
						rreq_dump_log_init_work_info.ranging_counter);
				}
				rreq_dump_log_init_work_info.ranging_counter =
					result->header.procedure_counter;
				rreq_dump_log_init_work_info.step_data = latest_local_steps.__buf;
				rreq_dump_log_init_work_info.len = len;
				rreq_dump_log_init_work_info.logged_len = 0;
			} else {
				rreq_dump_log_init_work_info.len += len;
			}
			subevt_idx++;
			k_work_submit_to_queue(&log_dump_work_q,
					       &rreq_dump_log_init_work_info.work);
		} else {
			LOG_ERR("not enough mem %d %d",
				latest_local_steps.len + result->step_data_buf->len,
				latest_local_steps.size);
			rreq_smf_ctl.ranging_counter[RREQ_SMF_RC_DROPPED] =
				result->header.procedure_counter;
			subevt_idx = 0;
			reset_rd_info(LOCAL_ROLE_MASK);
			return;
		}
	}
	if (result->header.procedure_done_status == BT_CONN_LE_CS_PROCEDURE_COMPLETE) {
		rreq_smf_ctl.ranging_counter[RREQ_SMF_RC_LOCAL] = result->header.procedure_counter;
		rreq_dump_log_end_work_info.status = BT_CONN_LE_CS_PROCEDURE_COMPLETE;
		rreq_dump_log_end_work_info.ranging_counter = result->header.procedure_counter;
		k_work_submit_to_queue(&log_dump_work_q, &rreq_dump_log_end_work_info.work);
		subevt_idx = 0;
	} else if (result->header.procedure_done_status == BT_CONN_LE_CS_PROCEDURE_ABORTED) {
		rreq_dump_log_end_work_info.status = BT_CONN_LE_CS_PROCEDURE_ABORTED;
		rreq_dump_log_end_work_info.ranging_counter = result->header.procedure_counter;
		k_work_submit_to_queue(&log_dump_work_q, &rreq_dump_log_end_work_info.work);
		subevt_idx = 0;
	}
}

#ifdef CONFIG_TX_PHY_CS_REF
static uint8_t gap_phy_to_cs_phy(uint8_t gap_phy)
{
	switch (gap_phy) {
	case BT_GAP_LE_PHY_1M:
		return BT_LE_CS_PROCEDURE_PHY_1M;
	case BT_GAP_LE_PHY_2M:
		return BT_LE_CS_PROCEDURE_PHY_2M;
	case BT_GAP_LE_PHY_CODED:
		/* Use S8 coding for Channel Sounding when connection uses Coded PHY.
		 * Rationale for choosing S8 over S2:
		 * 1. Better range: S8 provides ~3dB better sensitivity than S2
		 * 2. More robust: Lower data rate (125kbps vs 500kbps) means better
		 *    error resilience, which is crucial for ranging accuracy
		 * 3. CS priority: For ranging applications, measurement accuracy and
		 *    reliability are more important than data throughput
		 * 4. Link budget: S8 allows CS to work at greater distances where
		 *    the connection might be marginal
		 */
		return BT_LE_CS_PROCEDURE_PHY_CODED_S8;
	default:
		LOG_WRN("Unknown GAP PHY %u, defaulting to 1M", gap_phy);
		return BT_LE_CS_PROCEDURE_PHY_1M;
	}
}
#endif

#ifdef CONFIG_BT_TRANSMIT_POWER_CONTROL
static void rreq_tx_power_report(struct bt_conn *conn,
				 const struct bt_conn_le_tx_power_report *report)
{
	/* Handle different power report reasons */
	switch (report->reason) {
	case BT_HCI_LE_TX_POWER_REPORT_REASON_LOCAL_CHANGED:
		LOG_INF("Local TX power changed to %d dBm (delta: %d dB)", report->tx_power_level,
			report->delta);
		break;
	case BT_HCI_LE_TX_POWER_REPORT_REASON_REMOTE_CHANGED:
		LOG_INF("Remote TX power changed to %d dBm (delta: %d dB)", report->tx_power_level,
			report->delta);
		break;
	case BT_HCI_LE_TX_POWER_REPORT_REASON_READ_REMOTE_COMPLETED:
		/* Not used - we don't actively read remote TX power */
		break;
	default:
		LOG_WRN("Unknown power report reason: %u", report->reason);
		break;
	}

	/* Check power level limits */
	if (report->tx_power_level_flag & LL_PWR_CONTROL_LIMIT_MIN_BIT) {
		LOG_INF("TX power is at minimum level");
	}
	if (report->tx_power_level_flag & LL_PWR_CONTROL_LIMIT_MAX_BIT) {
		LOG_INF("TX power is at maximum level");
	}
}
#endif

static void rreq_le_phy_updated(struct bt_conn *conn, struct bt_conn_le_phy_info *param)
{
	LOG_INF("PHY updated: TX PHY %u, RX PHY %u", param->tx_phy, param->rx_phy);

#ifdef CONFIG_ATM_BT_PHY_1M
	/* Check if TX or RX PHY is not 1M and force update to 1M PHY */
	if ((param->tx_phy != BT_GAP_LE_PHY_1M) || (param->rx_phy != BT_GAP_LE_PHY_1M)) {
		LOG_WRN("Non-1M PHY detected (TX:%u RX:%u), update to 1M PHY", param->tx_phy,
			param->rx_phy);
#ifndef UPDATE_RETRY_TIMES
#define UPDATE_RETRY_TIMES 3
#endif
		if (rreq_smf_ctl.retry_count >= UPDATE_RETRY_TIMES) {
			LOG_ERR("Update PHY 1M %u retries", rreq_smf_ctl.retry_count);
			return;
		}
		rreq_smf_ctl.retry_count++;
		int err = bt_conn_le_phy_update(conn, BT_CONN_LE_PHY_PARAM_1M);
		if (err) {
			LOG_ERR("Failed to update PHY to 1M: %d", err);
		} else {
			LOG_INF("PHY update to 1M initiated");
		}
	} else {
		LOG_INF("PHY is already 1M (TX:%u RX:%u)", param->tx_phy, param->rx_phy);
		rreq_smf_ctl.retry_count = 0;
	}
#endif /* CONFIG_ATM_BT_PHY_1M */
}

BT_CONN_CB_DEFINE(conn_cb) = {
	.connected = rreq_connected,
	.disconnected = rreq_disconnected,
	.security_changed = rreq_security_changed,
	.le_phy_updated = rreq_le_phy_updated,
#ifdef CONFIG_BT_TRANSMIT_POWER_CONTROL
	.tx_power_report = rreq_tx_power_report,
#endif
	.le_cs_read_remote_capabilities_complete = rreq_cs_remote_capabilities,
	.le_cs_read_remote_fae_table_complete = rreq_cs_remote_fae_table,
	.le_cs_config_complete = rreq_cs_config_created,
	.le_cs_security_enable_complete = rreq_cs_security_enabled,
	.le_cs_procedure_enable_complete = rreq_cs_procedure_enabled,
	.le_cs_subevent_data_available = rreq_cs_subevent_result,
};

static void get_rd_cmpl_mode(struct bt_conn *conn, uint16_t ranging_counter, int err, bool realtime)
{
	if (err) {
		LOG_ERR("rd_cmpl_cb err:%d", err);
		reset_rd_info(PEER_ROLE_MASK);
		if (err == -ETIMEDOUT) {
			int error = bt_conn_disconnect(rreq_smf_ctl.curr_conn,
						       BT_HCI_ERR_REMOTE_USER_TERM_CONN);
			if (error) {
				LOG_ERR("disc err:%d", error);
			}
		}
		return;
	}
	uint16_t parsed_rc;
	int error = bt_ras_client_ranging_data_parse(&latest_peer_steps, &parsed_rc);
	if (error) {
		LOG_ERR("parse data err:%d", error);
		return;
	}
#define RANGING_COUNTER_MASK_ONDEMAND 0xFFFFFFFF
	uint32_t ranging_counter_mask = RANGING_COUNTER_MASK_ONDEMAND;
#ifdef CONFIG_RAS_CLIENT_REAL_TIME_RD
	if (realtime) {
#define RANGING_COUNTER_MASK_REALTIME 0xFFF
		rreq_smf_ctl.ranging_counter[RREQ_SMF_RC_PEER] = parsed_rc;
		ranging_counter = parsed_rc;
		ranging_counter_mask = RANGING_COUNTER_MASK_REALTIME;
	}
#endif
	bool mismatch = (rreq_smf_ctl.ranging_counter[RREQ_SMF_RC_PEER] !=
			 (rreq_smf_ctl.ranging_counter[RREQ_SMF_RC_LOCAL] & ranging_counter_mask));
	if (mismatch) {
		LOG_WRN("mismatch %u %u %d %d %u", ranging_counter, parsed_rc,
			rreq_smf_ctl.ranging_counter[RREQ_SMF_RC_PEER],
			rreq_smf_ctl.ranging_counter[RREQ_SMF_RC_LOCAL], realtime);
	}
	LOG_DBG("rd_cmpl_cb_mode rc:%u %u %d %d %u", ranging_counter, parsed_rc,
		rreq_smf_ctl.ranging_counter[RREQ_SMF_RC_PEER],
		rreq_smf_ctl.ranging_counter[RREQ_SMF_RC_LOCAL], realtime);
	rreq_submit_ref_log_work(ranging_counter, latest_peer_steps.data, latest_peer_steps.len);
	net_buf_simple_pull_mem(&latest_peer_steps, latest_peer_steps.len);
}

static void get_rd_cmpl_cb(struct bt_conn *conn, uint16_t ranging_counter, int err)
{
	get_rd_cmpl_mode(conn, ranging_counter, err, false);
}

static void rd_ready_cb(struct bt_conn *conn, uint16_t ranging_counter, int err)
{
	LOG_DBG("rd_ready_cb err:%d rc:%u peer:%d", err, ranging_counter,
		rreq_smf_ctl.ranging_counter[RREQ_SMF_RC_PEER]);
	if (err || (rreq_smf_ctl.ranging_counter[RREQ_SMF_RC_PEER] != PROCEDURE_COUNTER_NONE)) {
		LOG_INF("err: %d or get rd already rc:%d %d", err,
			rreq_smf_ctl.ranging_counter[RREQ_SMF_RC_PEER], ranging_counter);
		return;
	}
	err = bt_ras_client_cp_get_ranging_data(conn, ranging_counter, &latest_peer_steps,
						get_rd_cmpl_cb);
	if (err) {
		LOG_ERR("get rd err:%d", err);
		return;
	}
	rreq_smf_ctl.ranging_counter[RREQ_SMF_RC_PEER] = ranging_counter;
}

static void rd_overwritten_cb(struct bt_conn *conn, uint16_t ranging_counter)
{
	LOG_INF("ow_cb rc:%u peer:%d", ranging_counter,
		rreq_smf_ctl.ranging_counter[RREQ_SMF_RC_PEER]);
	if (ranging_counter == rreq_smf_ctl.ranging_counter[RREQ_SMF_RC_PEER]) {
		LOG_INF("ow_cb reset info");
		reset_rd_info(BOTH_ROLE_MASK);
	}
}

static int cs_proc_enable(enum bt_conn_le_cs_procedure_enable_state state)
{
	LOG_INF("CS proc enable:%u", state);
	const struct bt_le_cs_procedure_enable_param param = {
		.config_id = CREATE_CONFIG_ID,
		.enable = state,
	};
	return bt_le_cs_procedure_enable(rreq_smf_ctl.curr_conn, &param);
}

#ifdef CONFIG_RAS_CLIENT_REAL_TIME_RD
static void get_rt_rd_cmpl_cb(struct bt_conn *conn, int err)
{
	get_rd_cmpl_mode(conn, 0, err, true);
}
#endif

static void rreq_button_work_handler(struct k_work *work)
{
	LOG_INF("btn work");
	int err;
#ifdef CONFIG_BTN_DISABLE_CS_PROC
	if ((SMF_CTX(&rreq_smf_ctx)->current) == &rreq_smf_states[RREQ_SMF_STATE_CS_PROC]) {
		enum bt_conn_le_cs_procedure_enable_state state =
			(rreq_smf_ctl.action_mask & BIT(RREQ_SMF_CS_START_PROC_ENABLE))
				? BT_CONN_LE_CS_PROCEDURES_DISABLED
				: BT_CONN_LE_CS_PROCEDURES_ENABLED;
		err = cs_proc_enable(state);
		if (err) {
			LOG_ERR("en/dis CS proc err:%d", err);
		}
		return;
	}
#endif
	err = bt_unpair(BT_ID_DEFAULT, BT_ADDR_LE_ANY);
	if (err) {
		LOG_ERR("unpair err:%d", err);
	}
}

static void exchange_func(struct bt_conn *conn, uint8_t err, struct bt_gatt_exchange_params *params)
{
	LOG_INF("MTU:%u err:%d", bt_gatt_get_mtu(conn), err);
	rreq_smf_ctl.action_mask |= BIT(RREQ_SMF_GATT_EXCH_MTU);
	rreq_run_event(RREQ_SMF_EVT_BT_LINK_READY);
}

static int rreq_smf_get_antenna_counts(uint8_t config, uint8_t *local_count, uint8_t *peer_count)
{
	if (!local_count || !peer_count) {
		LOG_ERR("Invalid parameters: local_count=%p, peer_count=%p", local_count,
			peer_count);
		return -EINVAL;
	}

	switch (config) {
	case BT_LE_CS_TONE_ANTENNA_CONFIGURATION_A1_B1: // 1 local antenna, 1 peer antenna
		*local_count = 1;
		*peer_count = 1;
		break;
	case BT_LE_CS_TONE_ANTENNA_CONFIGURATION_A2_B1: // 2 local antennas, 1 peer antenna
		*local_count = 2;
		*peer_count = 1;
		break;
	case BT_LE_CS_TONE_ANTENNA_CONFIGURATION_A3_B1: // 3 local antennas, 1 peer antenna
		*local_count = 3;
		*peer_count = 1;
		break;
	case BT_LE_CS_TONE_ANTENNA_CONFIGURATION_A4_B1: // 4 local antennas, 1 peer antenna
		*local_count = 4;
		*peer_count = 1;
		break;
	case BT_LE_CS_TONE_ANTENNA_CONFIGURATION_A1_B2: // 1 local antenna, 2 peer antennas
		*local_count = 1;
		*peer_count = 2;
		break;
	case BT_LE_CS_TONE_ANTENNA_CONFIGURATION_A1_B3: // 1 local antenna, 3 peer antennas
		*local_count = 1;
		*peer_count = 3;
		break;
	case BT_LE_CS_TONE_ANTENNA_CONFIGURATION_A1_B4: // 1 local antenna, 4 peer antennas
		*local_count = 1;
		*peer_count = 4;
		break;
	case BT_LE_CS_TONE_ANTENNA_CONFIGURATION_A2_B2: // 2 local antennas, 2 peer antennas
		*local_count = 2;
		*peer_count = 2;
		break;
	default:
		LOG_ERR("Invalid CS tone antenna config: %u", config);
		*local_count = 0;
		*peer_count = 0;
		return -EINVAL;
	}

	LOG_DBG("Antenna config %u: local=%u, peer=%u", config, *local_count, *peer_count);
	return 0;
}

/**
 * @brief Select CS tone antenna configuration based on local and peer antenna counts
 *
 * @param local_antennas Number of local antennas available (1-4)
 * @param peer_antennas Number of peer antennas available (1-4)
 * @return uint8_t CS tone antenna configuration (0-7), or BT_LE_CS_TONE_ANTENNA_CONFIGURATION_A1_B1
 * if no match
 */
static uint8_t rreq_smf_select_antenna_config(uint8_t local_antennas, uint8_t peer_antennas)
{
	if (!local_antennas || !peer_antennas ||
	    local_antennas > BT_LE_CS_ANTENNA_SELECTION_OPT_FOUR ||
	    peer_antennas > BT_LE_CS_ANTENNA_SELECTION_OPT_FOUR) {
		LOG_ERR("Invalid antenna counts: local=%u, peer=%u", local_antennas, peer_antennas);
		return BT_LE_CS_TONE_ANTENNA_CONFIGURATION_A1_B1; // Default fallback
	}

	// Find exact match for the antenna configuration
	if (local_antennas == 1 && peer_antennas == 1) {
		return BT_LE_CS_TONE_ANTENNA_CONFIGURATION_A1_B1;
	} else if (local_antennas == 2 && peer_antennas == 1) {
		return BT_LE_CS_TONE_ANTENNA_CONFIGURATION_A2_B1;
	} else if (local_antennas == 3 && peer_antennas == 1) {
		return BT_LE_CS_TONE_ANTENNA_CONFIGURATION_A3_B1;
	} else if (local_antennas == 4 && peer_antennas == 1) {
		return BT_LE_CS_TONE_ANTENNA_CONFIGURATION_A4_B1;
	} else if (local_antennas == 1 && peer_antennas == 2) {
		return BT_LE_CS_TONE_ANTENNA_CONFIGURATION_A1_B2;
	} else if (local_antennas == 1 && peer_antennas == 3) {
		return BT_LE_CS_TONE_ANTENNA_CONFIGURATION_A1_B3;
	} else if (local_antennas == 1 && peer_antennas == 4) {
		return BT_LE_CS_TONE_ANTENNA_CONFIGURATION_A1_B4;
	} else if (local_antennas == 2 && peer_antennas == 2) {
		return BT_LE_CS_TONE_ANTENNA_CONFIGURATION_A2_B2;
	} else {
		// No exact match found, find best fit
		LOG_WRN("No exact match for %u local, %u peer antennas, finding best fit",
			local_antennas, peer_antennas);

		// Priority: maximize total antenna paths while staying within limits
		uint8_t best_config = BT_LE_CS_TONE_ANTENNA_CONFIGURATION_A1_B1;
		uint8_t max_paths = 1;

		for (uint8_t config = 0; config <= BT_LE_CS_TONE_ANTENNA_CONFIGURATION_A2_B2;
		     config++) {
			uint8_t cfg_local, cfg_peer;
			if (!rreq_smf_get_antenna_counts(config, &cfg_local, &cfg_peer)) {
				if (cfg_local <= local_antennas && cfg_peer <= peer_antennas) {
					uint8_t paths = cfg_local * cfg_peer;
					if (paths > max_paths) {
						max_paths = paths;
						best_config = config;
					}
				}
			}
		}

		LOG_INF("Selected best fit config %u for %u local, %u peer antennas", best_config,
			local_antennas, peer_antennas);
		return best_config;
	}
}

static void rreq_smf_work_handler(struct k_work *work)
{
	static uint8_t local_antenna_count;
	if (!rreq_smf_ctl.curr_conn) {
		LOG_INF("no conn");
		return;
	}
	enum rreq_smf_action next_action = RREQ_SMF_ACTION_NUM;
	for (uint8_t i = 0; i < RREQ_SMF_ACTION_NUM; i++) {
		if (!(rreq_smf_ctl.action_mask & BIT(i))) {
			next_action = i;
			break;
		}
	}
	LOG_DBG("next_action:%d", next_action);
	int err = 0;
	switch (next_action) {
#ifdef CONFIG_BT_TRANSMIT_POWER_CONTROL
	case RREQ_SMF_ENABLE_POWER_REPORTING: {
		/* Enable power reporting for both local and remote TX power changes */
		err = bt_conn_le_set_tx_power_report_enable(rreq_smf_ctl.curr_conn, true, true);
		if (!err) {
			LOG_INF("Power reporting enabled");
		} else {
			LOG_ERR("Failed to enable power reporting: %d", err);
		}
		rreq_smf_ctl.action_mask |= BIT(RREQ_SMF_ENABLE_POWER_REPORTING);
		atm_work_submit_to_app_work_q(&rreq_smf_work);
	} break;
#endif
	case RREQ_SMF_BT_SET_SEC: {
		err = bt_conn_set_security(rreq_smf_ctl.curr_conn, BT_SECURITY_L2);
		if (err) {
			int error = bt_conn_disconnect(rreq_smf_ctl.curr_conn,
						       BT_HCI_ERR_REMOTE_USER_TERM_CONN);
			if (error) {
				LOG_ERR("disc err:%d", error);
			}
		}
	} break;
	case RREQ_SMF_GATT_EXCH_MTU: {
		static struct bt_gatt_exchange_params params = {
			.func = exchange_func,
		};
		err = bt_gatt_exchange_mtu(rreq_smf_ctl.curr_conn, &params);
	} break;
	case RREQ_SMF_RAS_DISCOVER: {
		err = bt_ras_client_discover(rreq_smf_ctl.curr_conn);
	} break;
	case RREQ_SMF_RAS_SUBSCRIBE: {
		/*
		 * Subscribe to RAS CCCD notifications before CS procedure setup.
		 * This ensures we can receive ranging data notifications once
		 * CS procedures start generating data.
		 */

		/* Subscribe to common RAS characteristics first */
		err = bt_ras_client_cp_subscribe(rreq_smf_ctl.curr_conn, BT_RAS_CLIENT_SUB_AUTO);
		if (err && (err != -EALREADY)) {
			LOG_ERR("rd cp subs err:%d", err);
			return;
		}
		/* Try real-time subscription first if supported, fallback to on-demand mode */
#ifdef CONFIG_RAS_CLIENT_REAL_TIME_RD
		err = bt_ras_client_realtime_ranging_data_subscribe(
			rreq_smf_ctl.curr_conn, &latest_peer_steps, get_rt_rd_cmpl_cb,
			BT_RAS_CLIENT_SUB_AUTO);
		if (!err || (err == -EALREADY)) {
			/* Real-time subscription successful - skip on-demand subscriptions */
		} else {
			LOG_DBG("rt subs err:%d, fallback to on-demand mode", err);
#endif
			/* On-demand mode subscriptions */
			err = bt_ras_client_ranging_data_overwritten_subscribe(
				rreq_smf_ctl.curr_conn, rd_overwritten_cb, BT_RAS_CLIENT_SUB_AUTO);
			if (err && (err != -EALREADY)) {
				LOG_ERR("rd overwritten subs err:%d", err);
				return;
			}
			err = bt_ras_client_ranging_data_ready_subscribe(
				rreq_smf_ctl.curr_conn, rd_ready_cb, BT_RAS_CLIENT_SUB_AUTO);
			if (err && (err != -EALREADY)) {
				LOG_ERR("rd ready subs err:%d", err);
				return;
			}
			err = bt_ras_client_on_demand_ranging_data_subscribe(
				rreq_smf_ctl.curr_conn, BT_RAS_CLIENT_SUB_AUTO);
			if (err && (err != -EALREADY)) {
				LOG_ERR("rd on_demand subs err:%d", err);
				return;
			}
#ifdef CONFIG_RAS_CLIENT_REAL_TIME_RD
		}
#endif

		rreq_smf_ctl.action_mask |= BIT(RREQ_SMF_RAS_SUBSCRIBE);
		rreq_run_event(RREQ_SMF_EVT_BT_RAS_SUBSCRIBED);
	} break;
	case RREQ_SMF_CS_SETUP_READ_LOCAL_CAP: {
		struct bt_conn_le_cs_capabilities local_cap;
		err = bt_le_cs_read_local_supported_capabilities(&local_cap);
		if (!err) {
			rreq_smf_ctl.action_mask |= BIT(RREQ_SMF_CS_SETUP_READ_LOCAL_CAP);
			local_antenna_count = local_cap.num_antennas_supported;
			atm_work_submit_to_app_work_q(&rreq_smf_work);
		}
	} break;
	case RREQ_SMF_CS_SETUP_READ_REMOTE_CAP: {
		err = bt_le_cs_read_remote_supported_capabilities(rreq_smf_ctl.curr_conn);
	} break;
	case RREQ_SMF_CS_SETUP_SET_DEFAULT_SETTING: {
		const struct bt_le_cs_set_default_settings_param param = {
			.enable_initiator_role = true,
			.enable_reflector_role = false,
			.cs_sync_antenna_selection = BT_LE_CS_ANTENNA_SELECTION_OPT_REPETITIVE,
			.max_tx_power = BT_HCI_OP_LE_CS_MAX_MAX_TX_POWER,
		};
		err = bt_le_cs_set_default_settings(rreq_smf_ctl.curr_conn, &param);
		if (!err) {
			rreq_smf_ctl.action_mask |= BIT(RREQ_SMF_CS_SETUP_SET_DEFAULT_SETTING);
			atm_work_submit_to_app_work_q(&rreq_smf_work);
		}
	} break;
	case RREQ_SMF_CS_SETUP_READ_REMOTE_FAE_TABLE: {
		err = bt_le_cs_read_remote_fae_table(rreq_smf_ctl.curr_conn);
	} break;
	case RREQ_SMF_CS_SETUP_CREATE_CONFIG: {
		struct bt_le_cs_create_config_params params = {
			.id = CREATE_CONFIG_ID,
			.main_mode_type = CREATE_MAIN_MODE_TYPE,
			.sub_mode_type = CREATE_SUB_MODE_TYPE,
			.min_main_mode_steps = CREATE_MIN_MAIN_MODE_STEPS,
			.max_main_mode_steps = CREATE_MAX_MAIN_MODE_STEPS,
			.main_mode_repetition = CREATE_MAIN_MODE_REPETITION,
			.mode_0_steps = CREATE_MODE_0_STEPS,
			.role = BT_CONN_LE_CS_ROLE_INITIATOR,
			.rtt_type = CREATE_RRT_TYPE,
			.cs_sync_phy = CREATE_CS_SYNC_PHY,
			.channel_map_repetition = CREATE_CHANNEL_MAP_REPETITION,
			.channel_selection_type = CREATE_CHANNEL_SELECTION_TYPE,
			.ch3c_shape = CREATE_CH3C_SHAPE,
			.ch3c_jump = CREATE_CH3C_JUMP,
		};
		bt_le_cs_set_valid_chmap_bits(params.channel_map);
		err = bt_le_cs_create_config(rreq_smf_ctl.curr_conn, &params,
					     BT_LE_CS_CREATE_CONFIG_CONTEXT_LOCAL_AND_REMOTE);
	} break;
	case RREQ_SMF_CS_SETUP_ENABLE_SECURITY: {
		err = bt_le_cs_security_enable(rreq_smf_ctl.curr_conn);
	} break;
	case RREQ_SMF_CS_START_SET_PROC_PARAM: {
		struct bt_conn_info info;
		uint8_t current_tx_phy = BT_GAP_LE_PHY_1M;

		int info_err = bt_conn_get_info(rreq_smf_ctl.curr_conn, &info);
		if (!info_err && info.type == BT_CONN_TYPE_LE) {
			current_tx_phy = info.le.phy->tx_phy;
		} else {
			LOG_WRN("Failed to get conn info:%d", info_err);
		}
#ifdef CONFIG_TX_PHY_CS_REF
		uint8_t cs_phy = gap_phy_to_cs_phy(current_tx_phy);
		LOG_INF("Using CS PHY %u, delta PWR %d", cs_phy, CONFIG_TX_POWER_DELTA);
#endif
		struct bt_le_cs_set_procedure_parameters_param param = {
			.config_id = CREATE_CONFIG_ID,
			.max_procedure_len = MAX_PROC_LEN_IN_625US,
			.max_procedure_count = MAX_PROC_COUNT,
			.min_subevent_len = MIN_SUBEVENT_LEN_IN_US,
			.max_subevent_len = MAX_SUBEVENT_LEN_IN_US,
			.tone_antenna_config_selection = CONFIG_CS_PROC_ANT_CFG_SEL,
#ifdef CONFIG_TX_PHY_CS_REF
			.phy = cs_phy,
#else
			.phy = PROC_PHY,
#endif
			.tx_power_delta = CONFIG_TX_POWER_DELTA,
			.preferred_peer_antenna = cs_preferred_peer_antenna,
			.snr_control_initiator = SNR_CONTROL_INITIATOR,
			.snr_control_reflector = SNR_CONTROL_REFLECTOR,
		};
#define DEFAULT_PROC_INTERVAL_CONN_INT 12
#define LONG_PROC_INTERVAL_CONN_INT    16
		if (current_tx_phy == BT_GAP_LE_PHY_2M) {
			param.min_procedure_interval = DEFAULT_PROC_INTERVAL_CONN_INT;
			param.max_procedure_interval = DEFAULT_PROC_INTERVAL_CONN_INT;
		} else {
			param.min_procedure_interval = LONG_PROC_INTERVAL_CONN_INT;
			param.max_procedure_interval = LONG_PROC_INTERVAL_CONN_INT;
		}

		// Check antenna configuration
		// Count the number of high bits in preferred_peer_antenna (indicates antenna
		// amount)
		uint8_t peer_antenna_count = __builtin_popcount(param.preferred_peer_antenna);

		// Extract peer antenna number from tone_antenna_config_selection
		uint8_t peer_ant_cfg, local_ant_cfg;
		rreq_smf_get_antenna_counts(param.tone_antenna_config_selection, &local_ant_cfg,
					    &peer_ant_cfg);

		// If peer antenna from tone config is greater than peer antenna count,
		// select appropriate configuration based on available antennas
		bool reset_tone_config = false;
		if (peer_ant_cfg > peer_antenna_count && peer_antenna_count) {
			peer_ant_cfg = peer_antenna_count;
			reset_tone_config = true;
			LOG_WRN("Invalid config - %u (%u*%u): peer_antenna_count=%u",
				param.tone_antenna_config_selection, local_ant_cfg, peer_ant_cfg,
				peer_antenna_count);
		}
		if (local_ant_cfg > local_antenna_count && local_antenna_count) {
			reset_tone_config = true;
			local_ant_cfg = local_antenna_count;
			LOG_WRN("Invalid config - %u (%u*%u): local_antenna_count=%u",
				param.tone_antenna_config_selection, local_ant_cfg, peer_ant_cfg,
				local_antenna_count);
		}
		if (reset_tone_config) {
			// Select optimal configuration based on available antenna counts
			uint8_t new_config =
				rreq_smf_select_antenna_config(local_ant_cfg, peer_ant_cfg);
			param.tone_antenna_config_selection = new_config;
			LOG_INF("Selected optimal tone_antenna_config_selection=%u for %u local, "
				"%u peer antennas",
				new_config, local_antenna_count, peer_antenna_count);
		}

		err = bt_le_cs_set_procedure_parameters(rreq_smf_ctl.curr_conn, &param);
		if (!err) {
			rreq_smf_ctl.action_mask |= BIT(RREQ_SMF_CS_START_SET_PROC_PARAM);
			atm_work_submit_to_app_work_q(&rreq_smf_work);
		}
	} break;
	case RREQ_SMF_CS_START_PROC_ENABLE: {
		err = cs_proc_enable(BT_CONN_LE_CS_PROCEDURES_ENABLED);
	} break;
	case RREQ_SMF_ACTION_NUM:
	default: {
		LOG_ERR("Unexpected action:%u", next_action);
	} break;
	}
	if (err) {
		LOG_ERR("next_action:%u err:%d", next_action, err);
	}
}

static void button_pressed(const struct device *dev, struct gpio_callback *cb, uint32_t pins)
{
	LOG_INF("btn pressed");
	atm_work_submit_to_app_work_q(&rreq_button_work);
}

static void configure_button_irq(const struct gpio_dt_spec btn)
{
	if (!gpio_is_ready_dt(&btn)) {
		LOG_ERR("button device is not ready");
		return;
	}
	int err = gpio_pin_configure_dt(&btn, GPIO_INPUT);
	if (err) {
		LOG_ERR("Failed to configure %s pin %u err:%d", btn.port->name, btn.pin, err);
		return;
	}
	err = gpio_pin_interrupt_configure_dt(&btn, GPIO_INT_EDGE_TO_ACTIVE);
	if (err) {
		LOG_ERR("Failed to configure interrupt on %s pin %u err:%d", btn.port->name,
			btn.pin, err);
		return;
	}
	gpio_init_callback(&button_cb_data, button_pressed, 0);
	button_cb_data.pin_mask |= BIT(btn.pin);
	err = gpio_add_callback(btn.port, &button_cb_data);
	if (err) {
		LOG_ERR("Failed to add callback err:%d", err);
		return;
	}
	LOG_INF("Set up button at %s pin %u", btn.port->name, btn.pin);
}

static void rreq_discovery_done(const struct bt_conn *conn, int err)
{
	if (err) {
		LOG_ERR("discv done err:%d", err);
		int error = bt_conn_disconnect(rreq_smf_ctl.curr_conn,
					       BT_HCI_ERR_REMOTE_USER_TERM_CONN);
		if (error) {
			LOG_ERR("disconn err:%d", error);
		}
		return;
	}
	rreq_smf_ctl.action_mask |= BIT(RREQ_SMF_RAS_DISCOVER);
	atm_work_submit_to_app_work_q(&rreq_smf_work);
}

static void rreq_bt_ready(int err)
{
	if (err) {
		LOG_ERR("BT ready err:%d", err);
		return;
	}

	if (IS_ENABLED(CONFIG_SETTINGS)) {
		settings_load();
	}
	// work init
	k_work_init(&rreq_button_work, rreq_button_work_handler);
	k_work_init(&rreq_smf_work, rreq_smf_work_handler);
	k_work_init(&rreq_dump_log_init_work_info.work, rreq_dump_log_init_work_handler);
	k_work_init(&rreq_dump_log_end_work_info.work, rreq_dump_log_work_end_handler);
	// button init
#define SW0_NODE DT_ALIAS(sw1)
	static const struct gpio_dt_spec button0 = GPIO_DT_SPEC_GET_OR(SW0_NODE, gpios, {0});
	configure_button_irq(button0);

	for (uint8_t i = 0; i < RREQ_SMF_RC_TYPE_NUM; i++) {
		rreq_smf_ctl.ranging_counter[i] = PROCEDURE_COUNTER_NONE;
	}

	static const struct bt_ras_client_cb cb = {
		.discovery_done = rreq_discovery_done,
	};
	bt_ras_client_cb_register(&cb);

	rreq_run_event(RREQ_SMF_EVT_BT_READY);
}

static void rreq_init_entry(void *obj)
{
	int err = bt_enable(rreq_bt_ready);
	if (err) {
		LOG_INF("BT init failed err:%d", err);
	}
}

static enum smf_state_result rreq_init_run(void *obj)
{
	LOG_INF("init evt:%d", rreq_smf_ctl.evt);

	switch (rreq_smf_ctl.evt) {
	case RREQ_SMF_EVT_BT_READY: {
		smf_set_state(SMF_CTX(&rreq_smf_ctx), &rreq_smf_states[RREQ_SMF_STATE_SCAN]);
	} break;
	default: {
		LOG_ERR("Unexpected evt:%u", rreq_smf_ctl.evt);
	} break;
	}
	return SMF_EVENT_PROPAGATE;
}

static bool data_parse_cb(struct bt_data *data, void *user_data)
{
	struct bt_uuid_16 adv_uuid;

	if ((data->type != BT_DATA_UUID16_ALL) && (data->type != BT_DATA_UUID16_SOME)) {
		return true;
	}
	if (!bt_uuid_create(&adv_uuid.uuid, data->data, BT_UUID_SIZE_16)) {
		return true;
	}
	if (!bt_uuid_cmp(&adv_uuid.uuid, BT_UUID_RAS)) {
		int err = bt_le_scan_stop();
		if (err) {
			LOG_ERR("scan stop err:%d", err);
		}
		bt_addr_le_t *addr = user_data;
		struct bt_le_conn_param *param = BT_LE_CONN_PARAM_DEFAULT;
		err = bt_conn_le_create(addr, BT_CONN_LE_CREATE_CONN, param,
					&rreq_smf_ctl.curr_conn);
		if (err) {
			LOG_ERR("conn create err:%d", err);
			rreq_start_scan();
		}
		return false;
	}
	return true;
}

static void device_found(const bt_addr_le_t *addr, int8_t rssi, uint8_t type,
			 struct net_buf_simple *ad)
{
	bt_data_parse(ad, data_parse_cb, (void *)addr);
}

static void rreq_start_scan(void)
{
	int err = bt_le_scan_start(BT_LE_SCAN_PASSIVE, device_found);
	if (err) {
		LOG_ERR("scan err:%d", err);
		ASSERT_ERR(0);
	}
}

static void rreq_scan_entry(void *obj)
{
	rreq_start_scan();
	LOG_INF("scan entry");
}

static enum smf_state_result rreq_scan_run(void *obj)
{
	switch (rreq_smf_ctl.evt) {
	case RREQ_SMF_EVT_BT_CONNECTED: {
		smf_set_state(SMF_CTX(&rreq_smf_ctx), &rreq_smf_states[RREQ_SMF_STATE_CONNECTED]);
	} break;
	case RREQ_SMF_EVT_BT_DISCONNECTED: {
		smf_set_state(SMF_CTX(&rreq_smf_ctx), &rreq_smf_states[RREQ_SMF_STATE_SCAN]);
	} break;
	default: {
		LOG_ERR("Unexpected evt:%d", rreq_smf_ctl.evt);
	} break;
	}
	return SMF_EVENT_PROPAGATE;
}

static void rreq_connected_entry(void *obj)
{
	LOG_INF("conn entry");

	if (!rreq_smf_ctl.curr_conn) {
		LOG_ERR("No connection link info");
	}
}

static enum smf_state_result rreq_connected_run(void *obj)
{
	switch (rreq_smf_ctl.evt) {
#ifdef CONFIG_BT_TRANSMIT_POWER_CONTROL
	case RREQ_SMF_EVT_BT_CONNECTED: {
		atm_work_submit_to_app_work_q(&rreq_smf_work);
	} break;
#endif
	case RREQ_SMF_EVT_BT_SEC_CHG: {
		atm_work_submit_to_app_work_q(&rreq_smf_work);
	} break;
	case RREQ_SMF_EVT_BT_LINK_READY: {
		atm_work_submit_to_app_work_q(&rreq_smf_work);
	} break;
	case RREQ_SMF_EVT_BT_RAS_SUBSCRIBED: {
		smf_set_state(SMF_CTX(&rreq_smf_ctx), &rreq_smf_states[RREQ_SMF_STATE_CS_SETUP]);
	} break;
	case RREQ_SMF_EVT_BT_DISCONNECTED: {
		smf_set_state(SMF_CTX(&rreq_smf_ctx), &rreq_smf_states[RREQ_SMF_STATE_SCAN]);
	} break;
	default: {
		LOG_ERR("Unexpected evt:%u", rreq_smf_ctl.evt);
	} break;
	}
	return SMF_EVENT_PROPAGATE;
}

static void rreq_cs_setup_entry(void *obj)
{
	LOG_INF("cs_setup_entry");
	atm_work_submit_to_app_work_q(&rreq_smf_work);
}

static enum smf_state_result rreq_cs_setup_run(void *obj)
{
	switch (rreq_smf_ctl.evt) {
	case RREQ_SMF_EVT_BT_DISCONNECTED: {
		smf_set_state(SMF_CTX(&rreq_smf_ctx), &rreq_smf_states[RREQ_SMF_STATE_SCAN]);
	} break;
	case RREQ_SMF_EVT_BT_CS_PROC_ENABLED: {
		smf_set_state(SMF_CTX(&rreq_smf_ctx), &rreq_smf_states[RREQ_SMF_STATE_CS_PROC]);
	} break;
	default: {
		LOG_ERR("Unexpected evt:%d", rreq_smf_ctl.evt);
	} break;
	}
	return SMF_EVENT_PROPAGATE;
}

static void rreq_cs_proc_entry(void *obj)
{
	LOG_INF("cs_proc_en_entry");
}

static enum smf_state_result rreq_cs_proc_run(void *obj)
{
	switch (rreq_smf_ctl.evt) {
	case RREQ_SMF_EVT_BT_DISCONNECTED: {
		smf_set_state(SMF_CTX(&rreq_smf_ctx), &rreq_smf_states[RREQ_SMF_STATE_SCAN]);
	} break;
	default: {
		LOG_INF("unhandled evt:%d", rreq_smf_ctl.evt);
	} break;
	}
	return SMF_EVENT_PROPAGATE;
}

static const struct smf_state rreq_smf_states[RREQ_SMF_STATE_NUM] = {
	[RREQ_SMF_STATE_INIT] = SMF_CREATE_STATE(rreq_init_entry, rreq_init_run, NULL, NULL, NULL),
	[RREQ_SMF_STATE_SCAN] = SMF_CREATE_STATE(rreq_scan_entry, rreq_scan_run, NULL, NULL, NULL),
	[RREQ_SMF_STATE_CONNECTED] =
		SMF_CREATE_STATE(rreq_connected_entry, rreq_connected_run, NULL, NULL, NULL),
	[RREQ_SMF_STATE_CS_SETUP] =
		SMF_CREATE_STATE(rreq_cs_setup_entry, rreq_cs_setup_run, NULL, NULL, NULL),
	[RREQ_SMF_STATE_CS_PROC] =
		SMF_CREATE_STATE(rreq_cs_proc_entry, rreq_cs_proc_run, NULL, NULL, NULL),
};

void rreq_smf_init(void)
{
	log_dump_init();
	smf_set_initial(SMF_CTX(&rreq_smf_ctx), &rreq_smf_states[RREQ_SMF_STATE_INIT]);
}
