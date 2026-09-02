/**
 *******************************************************************************
 *
 * @file fp_fmdn_reverse_ringing.c
 *
 * @brief Atmosic Google Fast Pair Find My Device Network (FMDN) v2
 * Reverse Ringing Management Implementation
 *
 * Copyright (C) Atmosic 2026
 *
 *******************************************************************************
 */

#include <errno.h>
#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
#include <zephyr/bluetooth/bluetooth.h>
#include <zephyr/bluetooth/conn.h>
#include <zephyr/bluetooth/gatt.h>
#include "fp_fmdn_reverse_ringing.h"
#include "fp_fmdn_persistent_conn.h"
#include "fp_fmdn_sba_gatt.h"
#include "fp_fmdn_reverse_ringing_adv.h"
#include "fp_storage.h"

LOG_MODULE_DECLARE(fmdn, CONFIG_ATM_FMDN_LOG_LEVEL);

/// Reverse ringing timeout (FHN v2 spec: 60s)
#define RR_TIMEOUT_SECONDS 60

/// Persistent-path ring guard timeout — matches phone-side ringing duration.
/// Configurable via CONFIG_FMDN_REVERSE_RINGING_RING_TIMEOUT_SEC (default 300s).
#define RR_PERSISTENT_RING_TIMEOUT_SECONDS CONFIG_FMDN_REVERSE_RINGING_RING_TIMEOUT_SEC

/// Global reverse ringing state
static fp_fmdn_reverse_ringing_state_t rr_state;

/// Reverse ringing event callback
static fp_fmdn_reverse_ringing_event_cb rr_event_cb;

/// Reverse ringing state for indication
static uint8_t rr_current_state;

/// Context for sending indication
typedef struct {
	struct bt_conn *conn;
	const struct bt_gatt_attr *attr;
} rr_indicate_ctx_t;
static rr_indicate_ctx_t rr_indicate_ctx;

/* Persistent storage for in-flight indication. The GATT host keeps a reference
 * to the params (and to params->data) until the indication is confirmed or
 * fails, so neither may live on a work-handler stack frame.
 */
typedef struct __packed {
	uint8_t data_id;  ///< SBA Data ID (0x12 for Reverse Ringing, spec Table v2.6)
	uint8_t data_len; ///< Length of additional data in bytes
	uint8_t state;    ///< Requested ringing state (0x00 stop, 0x01 start)
} rr_ind_t;

static rr_ind_t rr_indicate_response;
static struct bt_gatt_indicate_params rr_indicate_params;
static atomic_t rr_indicate_inflight;

/// Timeout handler for reverse ringing
static void fp_fmdn_reverse_ringing_timeout_handler(struct k_work *work)
{
	ARG_UNUSED(work);

	/* Stop local state. Seeker reports timeout via WRITE (STATE 0x02).
	 * Provider does not send indication on timeout.
	 */
	rr_state.ringing = false;

	if (rr_state.active_conn && (rr_state.conn_type == RR_CONN_TYPE_ADVERTISEMENT)) {
		/* ADV path: 60s expired — disconnect; Seeker never sent stop WRITE */
		LOG_INF("RR: Connected ringing timeout (%ds), disconnecting", RR_TIMEOUT_SECONDS);
		int err =
			bt_conn_disconnect(rr_state.active_conn, BT_HCI_ERR_REMOTE_USER_TERM_CONN);
		if (err) {
			LOG_WRN("RR: Failed to disconnect: %d", err);
		}
		/* Connection will be cleared in disconnected callback */
		if (rr_event_cb) {
			rr_event_cb(RR_EVENT_TIMEOUT_LOCAL);
		}
	} else if (rr_state.active_conn && (rr_state.conn_type == RR_CONN_TYPE_PERSISTENT)) {
		/* Persistent path: expired — reset ringing state, keep connection */
		LOG_INF("RR: Persistent ringing timeout (%ds)", RR_PERSISTENT_RING_TIMEOUT_SECONDS);
		if (rr_event_cb) {
			rr_event_cb(RR_EVENT_PHONE_START_TIMEOUT);
		}
	} else if (!rr_state.active_conn) {
		/* ADV window expired with no Seeker connection — stop advertisement */
		LOG_INF("RR: ADV window timeout (%ds), no connection",
			ADV_RINGING_DURATION_SECONDS);
		fp_fmdn_reverse_ringing_adv_stop();
		if (rr_event_cb) {
			rr_event_cb(RR_EVENT_RR_ADV_TIMEOUT);
		}
	}

	/* Do NOT send indication - Seeker will report timeout via WRITE */
}

K_WORK_DELAYABLE_DEFINE(fp_fmdn_rr_timer_id, fp_fmdn_reverse_ringing_timeout_handler);

static void fp_fmdn_reverse_ringing_clear_session(void)
{
	k_work_cancel_delayable(&fp_fmdn_rr_timer_id);
	fp_fmdn_reverse_ringing_adv_stop();
	rr_state.active_conn = NULL;
	rr_state.ringing = false;
	rr_state.conn_type = RR_CONN_TYPE_NONE;
	rr_state.encryption_enabled = false;
}

static void fp_fmdn_reverse_ringing_notify_connected_if_secure(struct bt_conn *conn)
{
	if ((rr_state.active_conn != conn) || (rr_state.conn_type != RR_CONN_TYPE_ADVERTISEMENT) ||
	    (rr_state.encryption_enabled) || (bt_conn_get_security(conn) < BT_SECURITY_L4)) {
		return;
	}

	LOG_INF("RR: Security Mode 1 Level 4 enabled on advertisement connection");
	rr_state.encryption_enabled = true;
	if (rr_event_cb) {
		rr_event_cb(RR_EVENT_RR_ADV_CONNECTED);
	}
}

static void fp_fmdn_reverse_ringing_associate_adv_connection(struct bt_conn *conn)
{
	if (rr_state.active_conn == conn) {
		if (rr_state.conn_type == RR_CONN_TYPE_ADVERTISEMENT) {
			fp_fmdn_reverse_ringing_notify_connected_if_secure(conn);
		}
		return;
	}

	if (rr_state.active_conn) {
		LOG_WRN("RR: Ignoring advertisement connection while another RR connection is "
			"active");
		return;
	}

	LOG_INF("RR: Associating connection with advertisement-based ringing");
	fp_fmdn_reverse_ringing_adv_stop();
	rr_state.active_conn = conn;
	rr_state.conn_type = RR_CONN_TYPE_ADVERTISEMENT;
	rr_state.encryption_enabled = false;
	k_work_reschedule_for_queue(&k_sys_work_q, &fp_fmdn_rr_timer_id,
				    K_SECONDS(RR_TIMEOUT_SECONDS));
	fp_fmdn_reverse_ringing_notify_connected_if_secure(conn);
}

static void fp_fmdn_rr_indicate_done(struct bt_conn *conn, struct bt_gatt_indicate_params *params,
				     uint8_t err)
{
	ARG_UNUSED(conn);
	ARG_UNUSED(params);
	if (err) {
		LOG_WRN("RR: Indication confirmation error 0x%02x", err);
		if (rr_current_state == RR_REQUEST_START) {
			/* START not received by phone — ring never started; reset state.
			 * STOP failure is self-healing via Seeker WRITE or disconnected().
			 */
			rr_state.ringing = false;
			if (rr_event_cb) {
				rr_event_cb(RR_EVENT_PHONE_FAILED);
			}
		}
		return;
	}

	LOG_DBG("RR: Indication confirmed");

	if ((rr_state.conn_type == RR_CONN_TYPE_PERSISTENT) && rr_event_cb) {
		if (rr_current_state == RR_REQUEST_START) {
			/* Start timeout guard — clean up if Seeker sends no stop WRITE */
			k_work_reschedule_for_queue(&k_sys_work_q, &fp_fmdn_rr_timer_id,
						    K_SECONDS(RR_PERSISTENT_RING_TIMEOUT_SECONDS));
			rr_event_cb(RR_EVENT_START_INDICATION_CONFIRMED);
		} else {
			rr_event_cb(RR_EVENT_STOP_INDICATION_CONFIRMED);
		}
	}
}

static void fp_fmdn_rr_indicate_destroy(struct bt_gatt_indicate_params *params)
{
	ARG_UNUSED(params);
	atomic_clear(&rr_indicate_inflight);
}

/// Send reverse ringing indication
static void fp_fmdn_reverse_ringing_indicate_send(struct k_work *work)
{
	ARG_UNUSED(work);

	if (!rr_indicate_ctx.conn) {
		LOG_ERR("RR: No connection for indication");
		return;
	}

	/* START (0x01) indication only allowed on persistent connections */
	if ((rr_current_state == RR_REQUEST_START) &&
	    (rr_state.conn_type != RR_CONN_TYPE_PERSISTENT)) {
		LOG_ERR("RR: Cannot send START (0x01) indication on non-persistent connection");
		memset(&rr_indicate_ctx, 0, sizeof(rr_indicate_ctx));
		return;
	}

	/* Get SBA attribute (from write request or SBA module) */
	const struct bt_gatt_attr *attr = rr_indicate_ctx.attr;
	if (!attr) {
		attr = fp_fmdn_sba_gatt_get_attr();
		if (!attr) {
			LOG_ERR("RR: SBA attribute not available for indication");
			memset(&rr_indicate_ctx, 0, sizeof(rr_indicate_ctx));
			return;
		}
	}

	/* The previous indication's params/data must remain owned by the host
	 * until its destroy() callback runs; reject overlapping submissions.
	 */
	if (!atomic_cas(&rr_indicate_inflight, 0, 1)) {
		LOG_WRN("RR: Indication already in flight, dropping new request");
		memset(&rr_indicate_ctx, 0, sizeof(rr_indicate_ctx));
		return;
	}

	rr_indicate_response.data_id = SBA_DATA_ID_REVERSE_RINGING;
	rr_indicate_response.data_len = sizeof(rr_indicate_response.state);
	rr_indicate_response.state = rr_current_state;

	memset(&rr_indicate_params, 0, sizeof(rr_indicate_params));
	rr_indicate_params.attr = attr;
	rr_indicate_params.data = &rr_indicate_response;
	rr_indicate_params.len = sizeof(rr_indicate_response);
	rr_indicate_params.func = fp_fmdn_rr_indicate_done;
	rr_indicate_params.destroy = fp_fmdn_rr_indicate_destroy;

	int err = bt_gatt_indicate(rr_indicate_ctx.conn, &rr_indicate_params);
	if (err) {
		LOG_ERR("RR: Failed to send indication: %d", err);
		/* destroy() is not invoked when bt_gatt_indicate() fails synchronously */
		atomic_clear(&rr_indicate_inflight);
	} else {
		LOG_DBG("RR: Indication submitted with state 0x%02x", rr_current_state);
	}

	memset(&rr_indicate_ctx, 0, sizeof(rr_indicate_ctx));
}

K_WORK_DEFINE(fp_fmdn_rr_indicate_work, fp_fmdn_reverse_ringing_indicate_send);

/// Stop reverse ringing and send REQUEST to Seeker
static void fp_fmdn_reverse_ringing_send_stop_request(void)
{
	rr_current_state = RR_REQUEST_STOP;
	rr_state.ringing = false;

	/* Send INDICATION with REQUEST 0x00 (stop ringing) */
	k_work_submit(&fp_fmdn_rr_indicate_work);
}

int fp_fmdn_reverse_ringing_init(void)
{
	LOG_INF("Reverse Ringing module initialized");
	memset(&rr_state, 0, sizeof(rr_state));

	/* Restore Seeker-controlled enable flag across power cycles */
	bool saved_enabled = false;
	if (!fp_storage_rr_enabled_get(&saved_enabled)) {
		rr_state.enabled = saved_enabled;
		LOG_INF("RR: Loaded saved enabled flag from NVS: %u", saved_enabled);
	} else {
		LOG_DBG("RR: No saved enabled flag in NVS");
	}

	/* Initialize advertisement-based ringing module */
	int err = fp_fmdn_reverse_ringing_adv_init();
	if (err) {
		LOG_ERR("RR: Failed to initialize advertisement-based ringing: %d", err);
		return err;
	}

	return 0;
}

void fp_fmdn_reverse_ringing_deinit(void)
{
	LOG_INF("Reverse Ringing module deinitialized");

	/* Deinitialize advertisement-based ringing module */
	fp_fmdn_reverse_ringing_adv_deinit();

	memset(&rr_state, 0, sizeof(rr_state));
}

int fp_fmdn_reverse_ringing_configure(struct bt_conn *conn, uint8_t flags)
{
	LOG_DBG("RR: Configure request, flags=0x%02x", flags);

	/* Ignore 0xFF per spec */
	if (flags == 0xFF) {
		LOG_DBG("RR: Ignoring configuration (0xFF)");
		return 0;
	}

	bool enable = (flags & RR_FLAG_ENABLE) != 0;
	bool changed = (rr_state.enabled != enable) || !fp_storage_rr_enabled_valid();
	rr_state.enabled = enable;

	if (changed) {
		fp_storage_rr_enabled_save(enable);
	}

	LOG_INF("RR: Configuration %s", enable ? "enabled" : "disabled");
	return 0;
}

int fp_fmdn_reverse_ringing_state_update(struct bt_conn *conn, uint8_t state)
{
	LOG_DBG("RR: State update from Seeker, state=0x%02x", state);

	/* Seeker sends: 0x00=Started, 0x01=Failed, 0x02=Timeout, 0x03=User, 0x04=Provider */
	if (state > RR_STATE_STOPPED_PROVIDER) {
		LOG_WRN("RR: Invalid state update 0x%02x", state);
		return -EINVAL;
	}

	/* The RR ADV connected callback is not guaranteed to identify the connection on all
	 * controller paths.  Use the first Started state write as the fallback identifier. */
	if ((state == RR_STATE_STARTED) && (rr_state.ringing)) {
		fp_fmdn_reverse_ringing_associate_adv_connection(conn);
	}

	fp_fmdn_reverse_ringing_event_t event;
	/* Handle each state and notify application */
	switch (state) {
	case RR_STATE_STARTED:
		LOG_INF("RR: Seeker confirmed ringing started");
		rr_state.ringing = true;
		event = RR_EVENT_PHONE_STARTED;
		break;

	case RR_STATE_FAILED_TO_START:
		LOG_INF("RR: Seeker failed to start ringing");
		event = RR_EVENT_PHONE_FAILED;
		break;

	case RR_STATE_STOPPED_TIMEOUT:
		LOG_INF("RR: Seeker stopped ringing (timeout)");
		event = RR_EVENT_PHONE_STOPPED_TIMEOUT;
		break;

	case RR_STATE_STOPPED_USER:
		LOG_INF("RR: Seeker stopped ringing (user dismissed)");
		event = RR_EVENT_PHONE_STOPPED_USER;
		break;

	case RR_STATE_STOPPED_PROVIDER:
		LOG_INF("RR: Seeker stopped ringing (Provider requested)");
		event = RR_EVENT_PHONE_STOPPED_PROVIDER;
		break;

	default:
		LOG_WRN("RR: Unknown state 0x%02x", state);
		return -EINVAL;
	}
	if (event != RR_EVENT_PHONE_STARTED) {
		/* Any non-Started state is a valid stop/failure and releases the RR session. */
		fp_fmdn_reverse_ringing_clear_session();
	}
	if (rr_event_cb) {
		rr_event_cb(event);
	}

	return 0;
}

const fp_fmdn_reverse_ringing_state_t *fp_fmdn_reverse_ringing_get_state(void)
{
	return &rr_state;
}

bool fp_fmdn_is_reverse_ringing_enabled(void)
{
	return rr_state.enabled;
}

bool fp_fmdn_is_reverse_ringing_started(void)
{
	return rr_state.ringing;
}

void fp_fmdn_reverse_ringing_disconnected(struct bt_conn *conn)
{
	LOG_DBG("RR: Connection disconnected");

	if (rr_state.active_conn == conn) {
		bool was_ringing = rr_state.ringing;
		fp_fmdn_reverse_ringing_clear_session();
		LOG_INF("RR: Active connection cleared");
		if (was_ringing && rr_event_cb) {
			rr_event_cb(RR_EVENT_PHONE_STOPPED_DISCONNECTED);
		}
	}
}

void fp_fmdn_reverse_ringing_connected(struct bt_conn *conn)
{
	LOG_DBG("RR: Connection established");

	/* Check if Seeker connected in response to reverse ringing advertisement */
	const fp_fmdn_reverse_ringing_adv_state_t *adv_state =
		fp_fmdn_reverse_ringing_adv_get_state();
	if (adv_state && adv_state->active) {
		LOG_INF("RR: Advertisement-based connection established");

		fp_fmdn_reverse_ringing_associate_adv_connection(conn);

		/* User feedback provided when encryption enabled */
	}
}

void fp_fmdn_reverse_ringing_encryption_enabled(struct bt_conn *conn)
{
	LOG_DBG("RR: Encryption enabled on connection");
	fp_fmdn_reverse_ringing_notify_connected_if_secure(conn);
}

void fp_fmdn_reverse_ringing_event_reg(fp_fmdn_reverse_ringing_event_cb const hdlr)
{
	if (!rr_event_cb) {
		rr_event_cb = hdlr;
		LOG_INF("RR: Event callback registered");
	}
}

void fp_fmdn_reverse_ringing_button_press(fp_tap_type_t tap_type)
{
	bool active = (tap_type == FP_DOUBLE_TAP);
	LOG_INF("RR: Button press detected %s", active ? "double press" : "single press");

	if (!rr_state.enabled) {
		LOG_INF("RR: Reverse ringing is disabled");
		return;
	}

	if (rr_state.ringing && !active) {
		/* Single press while ringing — spec defines stop only after Seeker has connected */
		if (rr_state.active_conn) {
			LOG_INF("RR: Stop ringing by Provider's request (button press)");
			k_work_cancel_delayable(&fp_fmdn_rr_timer_id);
			rr_indicate_ctx.conn = rr_state.active_conn;
			rr_indicate_ctx.attr = NULL;
			fp_fmdn_reverse_ringing_send_stop_request();
		}
		/* No conn yet — let ADV timer expire (spec silent on ADV-window cancellation) */

	} else if (active && !rr_state.ringing) {
		/* Double press while not ringing - start reverse ringing */
		if (rr_state.active_conn) {
			LOG_WRN("RR: Double press ignored, RR connection is still active");
			return;
		}

		const fp_fmdn_persistent_conn_state_t *pc_state =
			fp_fmdn_persistent_conn_get_state();

		if (pc_state && pc_state->is_active) {
			/* Persistent connection exists - send GATT indication with requested state
			 * 0x01 (start ringing)
			 */
			LOG_INF("RR: Persistent connection available, sending start indication");

			/* Store connection and prepare indication */
			rr_state.active_conn = pc_state->conn;
			rr_state.conn_type =
				RR_CONN_TYPE_PERSISTENT; /* Mark as persistent connection */
			rr_indicate_ctx.conn = pc_state->conn;
			rr_indicate_ctx.attr = NULL; /* Will be set by GATT layer if needed */

			/* Send indication with REQUESTED state (0x01 = start) */
			rr_current_state = RR_REQUEST_START;
			k_work_submit(&fp_fmdn_rr_indicate_work);

			/* Start ringing locally */
			rr_state.ringing = true;

		} else {
			/* No persistent connection - use advertisement-based ringing */
			LOG_INF("RR: No persistent connection, starting advertisement-based "
				"ringing");
			if (!fp_fmdn_reverse_ringing_adv_start()) {
				rr_state.ringing = true;
				k_work_reschedule_for_queue(
					&k_sys_work_q, &fp_fmdn_rr_timer_id,
					K_SECONDS(ADV_RINGING_DURATION_SECONDS));
				if (rr_event_cb) {
					rr_event_cb(RR_EVENT_RR_ADV_STARTED);
				}
			} else {
				LOG_ERR("RR: Failed to start advertisement-based ringing");
				if (rr_event_cb) {
					rr_event_cb(RR_EVENT_RR_ADV_START_FAILED);
				}
			}
		}
	} else {
		if (active && rr_state.ringing) {
			/* Double press while phone is ringing (connected) */
			LOG_WRN("RR: Double press ignored, phone already ringing");
		} else if (!active && !rr_state.ringing) {
			/* Single press while not ringing — nothing to stop */
			LOG_DBG("RR: Single press ignored, not ringing");
		}
	}
}
