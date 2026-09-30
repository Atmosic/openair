/*
 * Copyright (c) 2025-2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include <zephyr/kernel.h>
#include <zephyr/smf.h>
#include <zephyr/sys/byteorder.h>
#include <zephyr/logging/log.h>
#include <zephyr/settings/settings.h>
#include <zephyr/bluetooth/bluetooth.h>
#include <zephyr/bluetooth/conn.h>
#include <zephyr/bluetooth/uuid.h>
#include <zephyr/bluetooth/cs.h>
#ifdef CONFIG_BTN_ON_OFF
#include <zephyr/pm/pm.h>
#include <zephyr/pm/policy.h>
#endif

#include "ras.h"
#include "rrsp_mmi.h"
#include "rrsp_buttons.h"
#include "app_work_q.h"
#ifdef CONFIG_RRSP_LED_IND
#include "rrsp_led.h"
#endif

LOG_MODULE_REGISTER(rrsp_mmi, CONFIG_RRSP_MMI_LOG_LEVEL);

typedef enum rrsp_mmi_work_evt_e {
	RRSP_MMI_WORK_EVT_ADV,
	RRSP_MMI_WORK_EVT_CS_SET_ROLE,
#ifdef CONFIG_BTN_FORCE_DISABLE_CS
	RRSP_MMI_WORK_EVT_CS_PROC_DISABLE,
	RRSP_MMI_WORK_EVT_CS_REMOVE_CONFIG,
#endif
	RRSP_MMI_WORK_EVT_INVALID,
} rrsp_mmi_work_evt_t;

struct rrsp_mmi_event_work_info {
	struct k_work work;
	uint8_t pending_cnt;
	rrsp_mmi_work_evt_t event;
	bool cs_role_enable;
};

typedef struct rrsp_mmi_ctrl_s {
	struct smf_ctx ctx;
	rrsp_mmi_evt_t evt;
	struct bt_conn *curr_conn;
	struct rrsp_mmi_event_work_info event_work;
#ifdef CONFIG_RRSP_SUBRATE_TEST
	struct k_work_delayable subrate_work;
#endif
	uint16_t remaining_cs_cnt;
	uint8_t cs_cfg;
	bool cs_role_enabled;
	bool cs_config_created;
	bool cs_sec_enabled;
#ifdef CONFIG_BTN_FORCE_DISABLE_CS
	bool cs_force_off;
#endif
} rrsp_mmi_ctrl_t;

static rrsp_mmi_ctrl_t rrsp_mmi;
static const struct smf_state rrsp_mmi_states[RRSP_MMI_STATE_IDX_MAX];

static void rrsp_mmi_run_event(rrsp_mmi_evt_t evt)
{
	rrsp_mmi.evt = evt;
	smf_run_state(SMF_CTX(&rrsp_mmi));
}

static void rrsp_mmi_connected_cb(struct bt_conn *conn, uint8_t err)
{
	char addr[BT_ADDR_LE_STR_LEN];

	(void)bt_addr_le_to_str(bt_conn_get_dst(conn), addr, sizeof(addr));
	LOG_INF("Connected to %s (err 0x%02X)", addr, err);

	if (err) {
		rrsp_mmi.curr_conn = NULL;
		rrsp_mmi_run_event(RRSP_MMI_EVT_BT_DISC);
		return;
	}

	rrsp_mmi.curr_conn = conn;
	rrsp_mmi_run_event(RRSP_MMI_EVT_BT_CONN);
}

static void rrsp_mmi_disconnected_cb(struct bt_conn *conn, uint8_t reason)
{
	char addr[BT_ADDR_LE_STR_LEN];
	bt_addr_le_to_str(bt_conn_get_dst(conn), addr, sizeof(addr));
	LOG_INF("Disconnected %s reason:%#x", addr, reason);
	rrsp_mmi.curr_conn = NULL;
	rrsp_mmi.cs_role_enabled = false;
	rrsp_mmi.cs_config_created = false;
	rrsp_mmi.cs_sec_enabled = false;
#ifdef CONFIG_BTN_FORCE_DISABLE_CS
	rrsp_mmi.cs_force_off = false;
#endif
	rrsp_mmi_run_event(RRSP_MMI_EVT_BT_DISC);
}

static void rrsp_mmi_remote_capabilities_cb(struct bt_conn *conn, uint8_t status,
					    struct bt_conn_le_cs_capabilities *params)
{
	ARG_UNUSED(params);
	if (status == BT_HCI_ERR_SUCCESS) {
		LOG_INF("CS capability exchange completed.");
	}
}

static void rrsp_mmi_cs_config_created_cb(struct bt_conn *conn, uint8_t status,
					  struct bt_conn_le_cs_config *config)
{
	if (status == BT_HCI_ERR_SUCCESS) {
		LOG_INF("CS config creation complete. ID: %d enhance:%x", config->id,
			config->cs_enhancements_1);
		rrsp_mmi.cs_cfg = config->id;
		rrsp_mmi.cs_config_created = true;
		rrsp_mmi_run_event(RRSP_MMI_EVT_CS_CFG_CREATED);
	}
}

static void rrsp_mmi_cs_config_removed_cb(struct bt_conn *conn, uint8_t config_id)
{
	LOG_INF("CS config removed. ID: %d", config_id);
	rrsp_mmi.cs_config_created = false;
	rrsp_mmi_run_event(RRSP_MMI_EVT_CS_CFG_RM);
}

static void rrsp_mmi_cs_security_enabled_cb(struct bt_conn *conn, uint8_t status)
{
	if (status == BT_HCI_ERR_SUCCESS) {
		LOG_INF("CS security enabled.");
		rrsp_mmi.cs_sec_enabled = true;
		rrsp_mmi_run_event(RRSP_MMI_EVT_CS_SEC_EN);
	}
}

static void rrsp_mmi_cs_procedure_enabled_cb(struct bt_conn *conn, uint8_t status,
					     struct bt_conn_le_cs_procedure_enable_complete *params)
{
	if (status == BT_HCI_ERR_SUCCESS) {
		LOG_INF("CS procedures enable: %u cnt:%u cfg_id:%u", params->state,
			params->procedure_count, params->config_id);

		if (params->state) {
			rrsp_mmi_run_event(RRSP_MMI_EVT_CS_PROC_EN);
			rrsp_mmi.remaining_cs_cnt = params->procedure_count;
			rrsp_mmi.cs_cfg = params->config_id;
		} else {
			rrsp_mmi_run_event(RRSP_MMI_EVT_CS_PROC_DIS);
			rrsp_mmi.remaining_cs_cnt = 0;
		}
	}
}

static void rrsp_mmi_cs_subevent_result_cb(struct bt_conn *conn,
					   struct bt_conn_le_cs_subevent_result *result)
{
	if (result->header.procedure_done_status != BT_CONN_LE_CS_PROCEDURE_INCOMPLETE) {
#define END_CS_CNT 1
		if (rrsp_mmi.remaining_cs_cnt == END_CS_CNT) {
			rrsp_mmi_run_event(RRSP_MMI_EVT_CS_PROC_DIS);
		} else if (rrsp_mmi.remaining_cs_cnt) {
			rrsp_mmi.remaining_cs_cnt--;
		}
	}
}

#ifdef CONFIG_BT_USER_PHY_UPDATE
static void rrsp_mmi_le_phy_updated(struct bt_conn *conn, struct bt_conn_le_phy_info *param)
{
	LOG_INF("PHY updated: TX PHY %u, RX PHY %u", param->tx_phy, param->rx_phy);
}
#endif

#ifdef CONFIG_RRSP_SUBRATE_TEST
#define RRSP_SUBRATE_REQ_DELAY_MS 500

static void rrsp_mmi_subrate_changed_cb(struct bt_conn *conn,
					const struct bt_conn_le_subrate_changed *params)
{
	if (params->status == BT_HCI_ERR_SUCCESS) {
		LOG_INF("Subrate changed: factor %u cont_num %u latency %u timeout %u",
			params->factor, params->continuation_number, params->peripheral_latency,
			params->supervision_timeout);
	} else {
		LOG_ERR("Subrate change failed (HCI status 0x%02x)", params->status);
	}
}

static void rrsp_mmi_security_changed_cb(struct bt_conn *conn, bt_security_t level,
					 enum bt_security_err err)
{
	if (err) {
		LOG_ERR("Security failed level:%u err:%d", level, err);
		return;
	}

	LOG_INF("Security changed level:%u, scheduling subrate in %d ms", level,
		RRSP_SUBRATE_REQ_DELAY_MS);
	atm_work_schedule_for_app_work_q(&rrsp_mmi.subrate_work, K_MSEC(RRSP_SUBRATE_REQ_DELAY_MS));
}
#endif

BT_CONN_CB_DEFINE(rrsp_mmi) = {
	.connected = rrsp_mmi_connected_cb,
	.disconnected = rrsp_mmi_disconnected_cb,
#ifdef CONFIG_BT_USER_PHY_UPDATE
	.le_phy_updated = rrsp_mmi_le_phy_updated,
#endif
#ifdef CONFIG_RRSP_SUBRATE_TEST
	.subrate_changed = rrsp_mmi_subrate_changed_cb,
	.security_changed = rrsp_mmi_security_changed_cb,
#endif
	.le_cs_read_remote_capabilities_complete = rrsp_mmi_remote_capabilities_cb,
	.le_cs_config_complete = rrsp_mmi_cs_config_created_cb,
	.le_cs_config_removed = rrsp_mmi_cs_config_removed_cb,
	.le_cs_security_enable_complete = rrsp_mmi_cs_security_enabled_cb,
	.le_cs_procedure_enable_complete = rrsp_mmi_cs_procedure_enabled_cb,
	.le_cs_subevent_data_available = rrsp_mmi_cs_subevent_result_cb,
};

static struct bt_le_ext_adv *rrsp_adv_set = NULL;
static const struct bt_data scan_data[] = {
	BT_DATA_BYTES(BT_DATA_UUID16_ALL, BT_UUID_16_ENCODE(BT_UUID_RAS_VAL)),
	BT_DATA_BYTES(BT_DATA_GAP_APPEARANCE, BT_UUID_16_ENCODE(CONFIG_BT_DEVICE_APPEARANCE)),
	BT_DATA(BT_DATA_NAME_COMPLETE, CONFIG_BT_DEVICE_NAME, sizeof(CONFIG_BT_DEVICE_NAME) - 1),
};

static const struct bt_data adv_data[] = {
	BT_DATA_BYTES(BT_DATA_FLAGS, (BT_LE_AD_GENERAL | BT_LE_AD_NO_BREDR)),
	BT_DATA_BYTES(BT_DATA_UUID16_ALL, BT_UUID_16_ENCODE(BT_UUID_RAS_VAL)),
};

static void rrsp_mmi_adv_off_cb(struct bt_le_ext_adv *adv, struct bt_le_ext_adv_sent_info *info)
{
	LOG_INF("ADV disable.");
	rrsp_mmi_run_event(RRSP_MMI_EVT_ADV_OFF);
}

static struct bt_le_ext_adv_cb rrsp_adv_cbs = {
	.sent = rrsp_mmi_adv_off_cb,
};

static void rrsp_mmi_start_adv(void)
{
	struct bt_le_adv_param adv_param = *(BT_LE_ADV_PARAM(
		BT_LE_ADV_OPT_CONN, BT_GAP_ADV_FAST_INT_MIN_1, BT_GAP_ADV_FAST_INT_MAX_1, NULL));
	adv_param.options |= BT_LE_ADV_OPT_SCANNABLE;
	int err;

	if (!rrsp_adv_set) {
		err = bt_le_ext_adv_create(&adv_param, &rrsp_adv_cbs, &rrsp_adv_set);

		if (err) {
			LOG_ERR("Failed to create advertising set (err %d)", err);
			return;
		}

		err = bt_le_ext_adv_set_data(rrsp_adv_set, adv_data, ARRAY_SIZE(adv_data),
					     scan_data, ARRAY_SIZE(scan_data));

		if (err) {
			LOG_ERR("Failed to set advertising data (err %d)", err);
			return;
		}
	}

	struct bt_le_ext_adv_start_param start_param = {
		.timeout = CONFIG_RRSP_ADV_TIMEOUT_CS,
		.num_events = 0,
	};

	err = bt_le_ext_adv_start(rrsp_adv_set, &start_param);

	if (err) {
		LOG_ERR("Failed to start advertising (err %d)", err);
		return;
	}
}

static void rrsp_mmi_cs_set_role(bool enable)
{
	if (!rrsp_mmi.curr_conn) {
		LOG_WRN("No connection, skip CS role set");
		return;
	}

	const struct bt_le_cs_set_default_settings_param default_settings = {
		.enable_initiator_role = false,
		.enable_reflector_role = enable,
		.cs_sync_antenna_selection = BT_LE_CS_ANTENNA_SELECTION_OPT_REPETITIVE,
		.max_tx_power = BT_HCI_OP_LE_CS_MAX_MAX_TX_POWER,
	};

	int err = bt_le_cs_set_default_settings(rrsp_mmi.curr_conn, &default_settings);
	if (err) {
		LOG_ERR("Failed to set CS reflector role:%u (err %d)", enable, err);
		return;
	}

	rrsp_mmi.cs_role_enabled = enable;
	LOG_INF("CS reflector role %s", enable ? "enabled" : "disabled");
#ifdef CONFIG_BTN_FORCE_DISABLE_CS
	if (!enable) {
		rrsp_mmi.cs_force_off = false;
	}
#endif
}

#ifdef CONFIG_BTN_FORCE_DISABLE_CS
static void rrsp_mmi_cs_proc_disable(void)
{
	if (!rrsp_mmi.curr_conn) {
		LOG_WRN("No connection, skip CS procedure disable");
		return;
	}

	const struct bt_le_cs_procedure_enable_param param = {
		.config_id = rrsp_mmi.cs_cfg,
		.enable = BT_CONN_LE_CS_PROCEDURES_DISABLED,
	};

	int err = bt_le_cs_procedure_enable(rrsp_mmi.curr_conn, &param);
	if (err) {
		LOG_ERR("Failed to disable CS procedure (err %d)", err);
	}
}

static void rrsp_mmi_cs_remove_config(void)
{
	if (!rrsp_mmi.curr_conn) {
		LOG_WRN("No connection, skip CS config remove");
		return;
	}

	int err = bt_le_cs_remove_config(rrsp_mmi.curr_conn, rrsp_mmi.cs_cfg);
	if (err) {
		LOG_ERR("Failed to remove CS config (err %d)", err);
	}
}
#endif

#ifdef CONFIG_RRSP_SUBRATE_TEST
#define RRSP_SUBRATE_FACTOR                 12
#define RRSP_SUBRATE_MAX_LATENCY            4
#define RRSP_SUBRATE_SUPERVISION_TIMEOUT_CS 600 /* units: 10ms */
static void rrsp_mmi_subrate_request(void)
{
	if (!rrsp_mmi.curr_conn) {
		LOG_WRN("No connection, skip subrate request");
		return;
	}

	const struct bt_conn_le_subrate_param subrate_param = {
		.subrate_min = RRSP_SUBRATE_FACTOR,
		.subrate_max = RRSP_SUBRATE_FACTOR,
		.max_latency = RRSP_SUBRATE_MAX_LATENCY,
		.continuation_number = 0,
		.supervision_timeout = RRSP_SUBRATE_SUPERVISION_TIMEOUT_CS,
	};

	int err = bt_conn_le_subrate_request(rrsp_mmi.curr_conn, &subrate_param);
	if (err) {
		LOG_ERR("Failed to request subrate params (err %d)", err);
	}
}

static void rrsp_mmi_subrate_work_handler(struct k_work *work)
{
	rrsp_mmi_subrate_request();
}
#endif

static void rrsp_mmi_evt_work_handler(struct k_work *work)
{
	struct rrsp_mmi_event_work_info *info =
		CONTAINER_OF(work, struct rrsp_mmi_event_work_info, work);

	switch (info->event) {
	case RRSP_MMI_WORK_EVT_ADV: {
		rrsp_mmi_start_adv();
	} break;
	case RRSP_MMI_WORK_EVT_CS_SET_ROLE: {
		rrsp_mmi_cs_set_role(info->cs_role_enable);
	} break;
#ifdef CONFIG_BTN_FORCE_DISABLE_CS
	case RRSP_MMI_WORK_EVT_CS_PROC_DISABLE: {
		rrsp_mmi_cs_proc_disable();
	} break;
	case RRSP_MMI_WORK_EVT_CS_REMOVE_CONFIG: {
		rrsp_mmi_cs_remove_config();
	} break;
#endif
	default: {
		LOG_ERR("Unexpected event");
	} break;
	}
	info->pending_cnt -= 1;
}

static void rrsp_mmi_evt_work_put_role(rrsp_mmi_work_evt_t evt, bool role_enable)
{
	rrsp_mmi.event_work.pending_cnt += 1;
	if (rrsp_mmi.event_work.pending_cnt > 1) {
		LOG_ERR("event overwrite:%d->%d", rrsp_mmi.event_work.event, evt);
	}
	rrsp_mmi.event_work.event = evt;
	rrsp_mmi.event_work.cs_role_enable = role_enable;
	atm_work_submit_to_app_work_q(&rrsp_mmi.event_work.work);
}

static void rrsp_mmi_evt_work_put(rrsp_mmi_work_evt_t evt)
{
	rrsp_mmi_evt_work_put_role(evt, false);
}

static void rrsp_mmi_bt_ready(int err)
{
	LOG_INF("ready: %d", err);

	if (IS_ENABLED(CONFIG_SETTINGS)) {
		settings_load();
	}

	if (err) {
		LOG_ERR("BT initial fail: %d", err);
	}

	k_work_init(&rrsp_mmi.event_work.work, rrsp_mmi_evt_work_handler);
#ifdef CONFIG_RRSP_SUBRATE_TEST
	k_work_init_delayable(&rrsp_mmi.subrate_work, rrsp_mmi_subrate_work_handler);
#endif

	rrsp_mmi_run_event(RRSP_MMI_EVT_BT_READY);
}

static void rrsp_mmi_init_entry(void *obj)
{
	LOG_INF("init_entry");
	int err = bt_enable(rrsp_mmi_bt_ready);
	if (err) {
		LOG_INF("Bluetooth init failed (err %d)\n", err);
		return;
	}
}

static enum smf_state_result rrsp_mmi_init_run(void *obj)
{
	LOG_INF("init_run:%u", rrsp_mmi.evt);

	switch (rrsp_mmi.evt) {
	case RRSP_MMI_EVT_BT_READY: {
		smf_set_state(SMF_CTX(&rrsp_mmi), &rrsp_mmi_states[RRSP_MMI_STATE_ADV]);
	} break;
	default: {
		LOG_ERR("Unexpected evt:%u", rrsp_mmi.evt);
	} break;
	}
	return SMF_EVENT_PROPAGATE;
}

static void rrsp_mmi_adv_entry(void *obj)
{
	LOG_INF("adv_entry");
	rrsp_mmi_evt_work_put(RRSP_MMI_WORK_EVT_ADV);
#ifdef CONFIG_RRSP_LED_IND
	rrsp_led_update(RRSP_LED_PAT_MODE_PAIR, true);
#endif
}

static enum smf_state_result rrsp_mmi_adv_run(void *obj)
{
	LOG_INF("adv_run-%u", rrsp_mmi.evt);

	switch (rrsp_mmi.evt) {
	case RRSP_MMI_EVT_BT_CONN: {
		smf_set_state(SMF_CTX(&rrsp_mmi), &rrsp_mmi_states[RRSP_MMI_STATE_CONNECTED]);
	} break;
	case RRSP_MMI_EVT_BT_DISC: {
		rrsp_mmi_evt_work_put(RRSP_MMI_WORK_EVT_ADV);
	} break;
	case RRSP_MMI_EVT_PWR_OFF: {
		int error = bt_le_ext_adv_stop(rrsp_adv_set);
		if (error) {
			LOG_ERR("disc err:%d", error);
		}
		rrsp_adv_set = NULL;
		smf_set_state(SMF_CTX(&rrsp_mmi), &rrsp_mmi_states[RRSP_MMI_STATE_OFF]);
	} break;
	case RRSP_MMI_EVT_ADV_OFF: {
		LOG_INF("Off: ADV off");
#ifdef CONFIG_RRSP_LED_IND
		rrsp_led_update(RRSP_LED_PAT_EVT_PWROFF, true);
#endif
		rrsp_adv_set = NULL;
		smf_set_state(SMF_CTX(&rrsp_mmi), &rrsp_mmi_states[RRSP_MMI_STATE_OFF]);
	} break;
	default: {
		LOG_ERR("Unexpected evt:%u", rrsp_mmi.evt);
	} break;
	}
	return SMF_EVENT_PROPAGATE;
}

static void rrsp_mmi_adv_exit(void *obj)
{
#ifdef CONFIG_RRSP_LED_IND
	rrsp_led_update(RRSP_LED_PAT_MODE_PAIR, false);
#endif
}

static void rrsp_mmi_connected_entry(void *obj)
{
	LOG_INF("con_entry");

	if (!rrsp_mmi.curr_conn) {
		LOG_ERR("No connection link info");
	}
	rrsp_mmi.cs_config_created = false;
	rrsp_mmi.cs_sec_enabled = false;
#ifdef CONFIG_BTN_FORCE_DISABLE_CS
	if (!rrsp_mmi.cs_force_off)
#endif
	{
		rrsp_mmi_evt_work_put_role(RRSP_MMI_WORK_EVT_CS_SET_ROLE, true);
	}
#ifdef CONFIG_RRSP_LED_IND
	rrsp_led_update(RRSP_LED_PAT_MODE_OPR, true);
#endif
}

static enum smf_state_result rrsp_mmi_connected_run(void *obj)
{
	LOG_INF("con_run-%u", rrsp_mmi.evt);

	switch (rrsp_mmi.evt) {
	case RRSP_MMI_EVT_BT_DISC: {
		smf_set_state(SMF_CTX(&rrsp_mmi), &rrsp_mmi_states[RRSP_MMI_STATE_ADV]);
	} break;
	case RRSP_MMI_EVT_CS_CFG_CREATED:
	case RRSP_MMI_EVT_CS_SEC_EN: {
		if (rrsp_mmi.cs_role_enabled && rrsp_mmi.cs_config_created &&
		    rrsp_mmi.cs_sec_enabled) {
			LOG_INF("CS setup complete: role:%u cfg:%u sec:%u",
				rrsp_mmi.cs_role_enabled, rrsp_mmi.cs_config_created,
				rrsp_mmi.cs_sec_enabled);
			smf_set_state(SMF_CTX(&rrsp_mmi),
				      &rrsp_mmi_states[RRSP_MMI_STATE_CS_SETUP_CMP]);
		}
	} break;
	case RRSP_MMI_EVT_PWR_OFF: {
		int error =
			bt_conn_disconnect(rrsp_mmi.curr_conn, BT_HCI_ERR_REMOTE_USER_TERM_CONN);
		if (error) {
			LOG_ERR("disc err:%d", error);
		}
		smf_set_state(SMF_CTX(&rrsp_mmi), &rrsp_mmi_states[RRSP_MMI_STATE_OFF]);
	} break;
	case RRSP_MMI_EVT_ADV_OFF: {
	} break;
#ifdef CONFIG_BTN_FORCE_DISABLE_CS
	case RRSP_MMI_EVT_CS_FORCE_OFF: {
		LOG_INF("Force disable CS: revert reflector role");
		rrsp_mmi.cs_force_off = false;
		rrsp_mmi_evt_work_put_role(RRSP_MMI_WORK_EVT_CS_SET_ROLE, true);
	} break;
#endif
	default: {
		LOG_ERR("Unexpected evt:%u", rrsp_mmi.evt);
	} break;
	}
	return SMF_EVENT_PROPAGATE;
}

static void rrsp_mmi_connected_exit(void *obj)
{
#ifdef CONFIG_RRSP_LED_IND
	if (!rrsp_mmi.curr_conn) {
		rrsp_led_update(RRSP_LED_PAT_MODE_OPR, false);
	}
#endif
}

static void rrsp_mmi_cs_setup_cmp_entry(void *obj)
{
	LOG_INF("setup_entry");
#ifdef CONFIG_RRSP_LED_IND
	rrsp_led_update(RRSP_LED_PAT_MODE_OPR, true);
#endif
}

static enum smf_state_result rrsp_mmi_cs_setup_cmp_run(void *obj)
{
	LOG_INF("setup_run-%u", rrsp_mmi.evt);

	switch (rrsp_mmi.evt) {
	case RRSP_MMI_EVT_BT_DISC: {
		smf_set_state(SMF_CTX(&rrsp_mmi), &rrsp_mmi_states[RRSP_MMI_STATE_ADV]);
	} break;
	case RRSP_MMI_EVT_CS_SEC_EN: {
		LOG_INF("Re-config again");
	} break;
	case RRSP_MMI_EVT_CS_PROC_EN: {
		smf_set_state(SMF_CTX(&rrsp_mmi), &rrsp_mmi_states[RRSP_MMI_STATE_CS_PROC_EN]);
	} break;
	case RRSP_MMI_EVT_PWR_OFF: {
		int error =
			bt_conn_disconnect(rrsp_mmi.curr_conn, BT_HCI_ERR_REMOTE_USER_TERM_CONN);
		if (error) {
			LOG_ERR("disc err:%d", error);
		}
		smf_set_state(SMF_CTX(&rrsp_mmi), &rrsp_mmi_states[RRSP_MMI_STATE_OFF]);
	} break;
	case RRSP_MMI_EVT_CS_CFG_RM: {
		LOG_INF("CS config removed, back to connected");
		smf_set_state(SMF_CTX(&rrsp_mmi), &rrsp_mmi_states[RRSP_MMI_STATE_CONNECTED]);
#ifdef CONFIG_BTN_FORCE_DISABLE_CS
		if (rrsp_mmi.cs_force_off) {
			rrsp_mmi_evt_work_put_role(RRSP_MMI_WORK_EVT_CS_SET_ROLE, false);
		}
#endif
	} break;
#ifdef CONFIG_BTN_FORCE_DISABLE_CS
	case RRSP_MMI_EVT_CS_FORCE_OFF: {
		LOG_INF("Force disable CS: remove CS config");
		rrsp_mmi.cs_force_off = true;
		rrsp_mmi_evt_work_put(RRSP_MMI_WORK_EVT_CS_REMOVE_CONFIG);
	} break;
#endif
	default: {
		LOG_ERR("Unexpected evt:%u", rrsp_mmi.evt);
	} break;
	}
	return SMF_EVENT_PROPAGATE;
}

static void rrsp_mmi_cs_setup_cmp_exit(void *obj)
{
#ifdef CONFIG_RRSP_LED_IND
	rrsp_led_update(RRSP_LED_PAT_MODE_OPR, false);
#endif
}

static void rrsp_mmi_cs_proc_en_entry(void *obj)
{
	LOG_INF("cs_entry");
#ifdef CONFIG_RRSP_LED_IND
	rrsp_led_update(RRSP_LED_PAT_MODE_CS, true);
#endif
}

static enum smf_state_result rrsp_mmi_cs_proc_en_run(void *obj)
{
	LOG_INF("cs_run-%u", rrsp_mmi.evt);

	switch (rrsp_mmi.evt) {
	case RRSP_MMI_EVT_BT_DISC: {
		smf_set_state(SMF_CTX(&rrsp_mmi), &rrsp_mmi_states[RRSP_MMI_STATE_ADV]);
	} break;
	case RRSP_MMI_EVT_CS_PROC_DIS: {
		LOG_INF("CS procedure disabled, back to CS setup complete");
#ifdef CONFIG_BTN_FORCE_DISABLE_CS
		if (rrsp_mmi.cs_force_off) {
			rrsp_mmi_evt_work_put(RRSP_MMI_WORK_EVT_CS_REMOVE_CONFIG);
		}
#endif
		smf_set_state(SMF_CTX(&rrsp_mmi), &rrsp_mmi_states[RRSP_MMI_STATE_CS_SETUP_CMP]);
	} break;
	case RRSP_MMI_EVT_PWR_OFF: {
		const struct bt_le_cs_procedure_enable_param param = {
			.config_id = rrsp_mmi.cs_cfg,
			.enable = BT_CONN_LE_CS_PROCEDURES_DISABLED,
		};
		bt_le_cs_procedure_enable(rrsp_mmi.curr_conn, &param);

		int error =
			bt_conn_disconnect(rrsp_mmi.curr_conn, BT_HCI_ERR_REMOTE_USER_TERM_CONN);
		if (error) {
			LOG_ERR("disc err:%d", error);
		}
		smf_set_state(SMF_CTX(&rrsp_mmi), &rrsp_mmi_states[RRSP_MMI_STATE_OFF]);
	} break;
	case RRSP_MMI_EVT_CS_CFG_RM: {
		LOG_INF("CS config removed, back to connected");
		smf_set_state(SMF_CTX(&rrsp_mmi), &rrsp_mmi_states[RRSP_MMI_STATE_CONNECTED]);
#ifdef CONFIG_BTN_FORCE_DISABLE_CS
		if (rrsp_mmi.cs_force_off) {
			rrsp_mmi_evt_work_put_role(RRSP_MMI_WORK_EVT_CS_SET_ROLE, false);
		}
#endif
	} break;
#ifdef CONFIG_BTN_FORCE_DISABLE_CS
	case RRSP_MMI_EVT_CS_FORCE_OFF: {
		LOG_INF("Force disable CS: disable CS procedure");
		rrsp_mmi.cs_force_off = true;
		rrsp_mmi_evt_work_put(RRSP_MMI_WORK_EVT_CS_PROC_DISABLE);
	} break;
#endif
	default: {
		LOG_ERR("Unexpected evt:%u", rrsp_mmi.evt);
	} break;
	}
	return SMF_EVENT_PROPAGATE;
}

static void rrsp_mmi_cs_proc_en_exit(void *obj)
{
	LOG_INF("CS disable");
#ifdef CONFIG_RRSP_LED_IND
	rrsp_led_update(RRSP_LED_PAT_MODE_CS, false);
#endif
}

static void rrsp_mmi_off_entry(void *obj)
{
	LOG_INF("MMI off entry");
#ifdef CONFIG_BTN_ON_OFF
	if (!rrsp_adv_set) {
		rrsp_mmi_unlock_sleep();
	}
#endif
}

static enum smf_state_result rrsp_mmi_off_run(void *obj)
{
	switch (rrsp_mmi.evt) {
	case RRSP_MMI_EVT_ADV_OFF: {
		LOG_INF("Off: ADV off");
	} break;
	case RRSP_MMI_EVT_BT_DISC: {
		LOG_INF("Off: Disconnect");
#ifdef CONFIG_BTN_ON_OFF
		rrsp_mmi_unlock_sleep();
#endif
	} break;
	case RRSP_MMI_EVT_CS_PROC_DIS: {
		LOG_INF("Off: CS Disable");
	} break;
	default: {
		LOG_ERR("Unexpected evt:%u", rrsp_mmi.evt);
	} break;
	}
	return SMF_EVENT_PROPAGATE;
}

static const struct smf_state rrsp_mmi_states[RRSP_MMI_STATE_IDX_MAX] = {
	[RRSP_MMI_STATE_INIT] =
		SMF_CREATE_STATE(rrsp_mmi_init_entry, rrsp_mmi_init_run, NULL, NULL, NULL),
	[RRSP_MMI_STATE_ADV] = SMF_CREATE_STATE(rrsp_mmi_adv_entry, rrsp_mmi_adv_run,
						rrsp_mmi_adv_exit, NULL, NULL),
	[RRSP_MMI_STATE_CONNECTED] =
		SMF_CREATE_STATE(rrsp_mmi_connected_entry, rrsp_mmi_connected_run,
				 rrsp_mmi_connected_exit, NULL, NULL),
	[RRSP_MMI_STATE_CS_SETUP_CMP] =
		SMF_CREATE_STATE(rrsp_mmi_cs_setup_cmp_entry, rrsp_mmi_cs_setup_cmp_run,
				 rrsp_mmi_cs_setup_cmp_exit, NULL, NULL),
	[RRSP_MMI_STATE_CS_PROC_EN] =
		SMF_CREATE_STATE(rrsp_mmi_cs_proc_en_entry, rrsp_mmi_cs_proc_en_run,
				 rrsp_mmi_cs_proc_en_exit, NULL, NULL),
	[RRSP_MMI_STATE_OFF] =
		SMF_CREATE_STATE(rrsp_mmi_off_entry, rrsp_mmi_off_run, NULL, NULL, NULL),
};

void rrsp_mmi_init(void)
{
	smf_set_initial(SMF_CTX(&rrsp_mmi), &rrsp_mmi_states[RRSP_MMI_STATE_INIT]);
}

rrsp_mmi_state_t rrsp_mmi_get_state(void)
{
	for (uint8_t i = 0; i < RRSP_MMI_STATE_IDX_MAX; i++) {
		if ((SMF_CTX(&rrsp_mmi)->current) == &rrsp_mmi_states[i]) {
			return i;
		}
	}
	return RRSP_MMI_STATE_IDX_MAX;
}

void rrsp_mmi_off(void)
{
	rrsp_mmi_run_event(RRSP_MMI_EVT_PWR_OFF);
#ifdef CONFIG_RRSP_LED_IND
	rrsp_led_cancel_all_bg();
#endif
}

#ifdef CONFIG_BTN_FORCE_DISABLE_CS
void rrsp_mmi_force_cs_off(void)
{
	rrsp_mmi_run_event(RRSP_MMI_EVT_CS_FORCE_OFF);
}
#endif

#ifdef CONFIG_BTN_ON_OFF
void rrsp_mmi_unlock_sleep(void)
{
	// unlock SOFT OFF which is locked on power.c
	pm_policy_state_lock_put(PM_STATE_SOFT_OFF, PM_ALL_SUBSTATES);
}
#endif
