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

LOG_MODULE_DECLARE(fmdn, CONFIG_ATM_FMDN_LOG_LEVEL);

/// Reverse ringing timeout (FHN v2 spec: 60s)
#define RR_TIMEOUT_SECONDS 60

/// Global reverse ringing state
static fp_fmdn_reverse_ringing_state_t rr_state = {
	.enabled = false,
	.active_conn = NULL,
	.ringing = false,
	.conn_type = RR_CONN_TYPE_NONE,
	.encryption_enabled = false,
};

/// Reverse ringing action callback
static fp_fmdn_reverse_ringing_action_cb rr_action_cb;

/// Reverse ringing event callback
static fp_fmdn_reverse_ringing_event_cb rr_event_cb;

/// Reverse ringing start time in milliseconds
static uint64_t rr_start_time_ms = 0;

/// Reverse ringing state for indication
static uint8_t rr_current_state = RR_STATE_STARTED;

/// Last request sent to Seeker (for validation)
static uint8_t rr_last_request = RR_REQUEST_STOP;

/// Context for sending indication
typedef struct {
	struct bt_conn *conn;
	const struct bt_gatt_attr *attr;
} rr_indicate_ctx_t;
static rr_indicate_ctx_t rr_indicate_ctx = {0};

/// Forward declarations
static void fp_fmdn_reverse_ringing_indicate_send(struct k_work *work);
K_WORK_DEFINE(fp_fmdn_rr_indicate_work, fp_fmdn_reverse_ringing_indicate_send);

int fp_fmdn_reverse_ringing_init(void)
{
	LOG_INF("Reverse Ringing module initialized");
	memset(&rr_state, 0, sizeof(rr_state));

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

/// Stop reverse ringing and send REQUEST to Seeker
/// @param request_value The REQUEST value to send (RR_REQUEST_STOP = 0x00)
static void fp_fmdn_reverse_ringing_send_stop_request(void)
{
	rr_current_state = RR_REQUEST_STOP; // Send REQUEST 0x00, not STATE
	rr_last_request = RR_REQUEST_STOP;  // Track last request for validation
	rr_start_time_ms = 0;
	rr_state.ringing = false;

	/* Notify application that we're sending stop request to phone */
	if (rr_event_cb) {
		rr_event_cb(RR_EVENT_REQUEST_SENT);
	}

	/* Send INDICATION with REQUEST 0x00 (stop ringing) */
	k_work_submit(&fp_fmdn_rr_indicate_work);
}

/// Timeout handler for reverse ringing
static void fp_fmdn_reverse_ringing_timeout_handler(struct k_work *work)
{
	ARG_UNUSED(work);
	LOG_INF("RR: Ringing timeout (60s) - stopping local tracking");

	/* Stop local state. Seeker reports timeout via WRITE (STATE 0x02).
	 * Provider does not send indication on timeout.
	 */
	rr_start_time_ms = 0;
	rr_state.ringing = false;

	/* Close advertisement-based connections after 60s timeout */
	if (rr_state.active_conn && (rr_state.conn_type == RR_CONN_TYPE_ADVERTISEMENT)) {
		LOG_INF("RR: Disconnecting advertisement-based connection after timeout");
		int err =
			bt_conn_disconnect(rr_state.active_conn, BT_HCI_ERR_REMOTE_USER_TERM_CONN);
		if (err) {
			LOG_WRN("RR: Failed to disconnect: %d", err);
		}
		/* Connection will be cleared in disconnected callback */
	}

	/* Notify application to stop ringing */
	if (rr_action_cb) {
		rr_action_cb(false);
	}

	/* Notify application (for LED/feedback) */
	if (rr_event_cb) {
		rr_event_cb(RR_EVENT_TIMEOUT_LOCAL);
	}

	/* Do NOT send indication - Seeker will report timeout via WRITE */
}
K_WORK_DELAYABLE_DEFINE(fp_fmdn_rr_timer_id, fp_fmdn_reverse_ringing_timeout_handler);

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

	uint8_t response[2] = {SBA_DATA_ID_REVERSE_RINGING, rr_current_state};
	struct bt_gatt_indicate_params indicate_params = {
		.attr = (struct bt_gatt_attr *)attr,
		.data = response,
		.len = sizeof(response),
	};
	int err = bt_gatt_indicate(rr_indicate_ctx.conn, &indicate_params);
	if (err) {
		LOG_ERR("RR: Failed to send indication: %d", err);
	} else {
		LOG_DBG("RR: Indication sent successfully with state 0x%02x", rr_current_state);
	}

	memset(&rr_indicate_ctx, 0, sizeof(rr_indicate_ctx));
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
	rr_state.enabled = enable;

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

	/* Validate state matches expected response */
	if (rr_last_request == RR_REQUEST_START) {
		if ((state != RR_STATE_STARTED) && (state != RR_STATE_FAILED_TO_START)) {
			LOG_WRN("RR: Unexpected state 0x%02x after START request", state);
		}
	} else if (rr_last_request == RR_REQUEST_STOP) {
		if ((state != RR_STATE_STOPPED_PROVIDER) && (state != RR_STATE_STOPPED_TIMEOUT) &&
		    (state != RR_STATE_STOPPED_USER)) {
			LOG_WRN("RR: Unexpected state 0x%02x after STOP request", state);
		}
	}

	fp_fmdn_reverse_ringing_event_t event;
	/* Handle each state and notify application */
	switch (state) {
	case RR_STATE_STARTED:
		LOG_INF("RR: Seeker confirmed ringing started");
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
		/* Stop timeout timer */
		k_work_cancel_delayable(&fp_fmdn_rr_timer_id);
		rr_state.ringing = false;
		rr_start_time_ms = 0;

		/* Notify application to stop ringing */
		if (rr_action_cb) {
			rr_action_cb(false);
		}
	} else {
		/* Phone started ringing - notify application to start ringing */
		if (rr_action_cb) {
			rr_action_cb(true);
		}
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

void fp_fmdn_reverse_ringing_disconnected(struct bt_conn *conn)
{
	LOG_DBG("RR: Connection disconnected");

	if (rr_state.active_conn == conn) {
		rr_state.active_conn = NULL;
		rr_state.ringing = false;
		rr_state.conn_type = RR_CONN_TYPE_NONE;
		rr_state.encryption_enabled = false;
		LOG_INF("RR: Active connection cleared");
	}
}

void fp_fmdn_reverse_ringing_connected(struct bt_conn *conn)
{
	LOG_DBG("RR: Connection established");

	/* Check if Seeker connected in response to reverse ringing advertisement */
	const fp_fmdn_reverse_ringing_adv_state_t *adv_state =
		fp_fmdn_reverse_ringing_adv_get_state();
	if (adv_state && (adv_state->active && rr_state.ringing)) {
		LOG_INF("RR: Advertisement-based connection established");

		fp_fmdn_reverse_ringing_adv_stop();

		rr_state.active_conn = conn;
		rr_state.conn_type = RR_CONN_TYPE_ADVERTISEMENT;
		rr_state.encryption_enabled = false;

		/* User feedback provided when encryption enabled */
	}
}

void fp_fmdn_reverse_ringing_encryption_enabled(struct bt_conn *conn)
{
	LOG_DBG("RR: Encryption enabled on connection");

	/* Provide user feedback (LED/beep) when encryption enabled on adv-based connection */
	if ((rr_state.active_conn == conn) && (rr_state.conn_type == RR_CONN_TYPE_ADVERTISEMENT) &&
	    !rr_state.encryption_enabled) {

		LOG_INF("RR: Encryption enabled on advertisement-based connection");
		rr_state.encryption_enabled = true;

		if (rr_event_cb) {
			rr_event_cb(RR_EVENT_ADV_CONNECTED);
		}
	}
}

void fp_fmdn_reverse_ringing_action_reg(fp_fmdn_reverse_ringing_action_cb const hdlr)
{
	if (!rr_action_cb) {
		rr_action_cb = hdlr;
		LOG_INF("RR: Action callback registered");
	}
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
		/* Single press while ringing - send STOP indication */
		LOG_INF("RR: Stop ringing by user button press");
		k_work_cancel_delayable(&fp_fmdn_rr_timer_id);

		if (rr_state.active_conn) {
			LOG_INF("RR: Stop ringing by Provider’s request (button press)");
			rr_indicate_ctx.conn = rr_state.active_conn;
			rr_indicate_ctx.attr = NULL;
			fp_fmdn_reverse_ringing_send_stop_request();
		} else {
			/* No active connection - just stop local ringing and advertising */
			fp_fmdn_reverse_ringing_adv_stop();
			rr_start_time_ms = 0;
			rr_state.ringing = false;

			/* Notify application to stop ringing */
			if (rr_action_cb) {
				rr_action_cb(false);
			}
		}

	} else if (active && !rr_state.ringing) {
		/* Double press while not ringing - start reverse ringing
		 * Per spec line 263: Check for persistent connection first
		 */
		const fp_fmdn_persistent_conn_state_t *pc_state =
			fp_fmdn_persistent_conn_get_state();

		if (pc_state && pc_state->is_active) {
			/* Persistent connection exists - send GATT indication with requested state
			 * 0x01 (start) Per spec line 263: "tag sends GATT indication operation with
			 * data ID 0x12 and requested ringing state 0x01 (start ringing)"
			 */
			LOG_INF("RR: Persistent connection available, sending start indication");

			/* Store connection and prepare indication */
			rr_state.active_conn = pc_state->conn;
			rr_state.conn_type =
				RR_CONN_TYPE_PERSISTENT; /* Mark as persistent connection */
			rr_indicate_ctx.conn = pc_state->conn;
			rr_indicate_ctx.attr = NULL; /* Will be set by GATT layer if needed */

			/* Send indication with REQUESTED state (0x01 = start) */
			rr_current_state =
				RR_REQUEST_START;           /* Use request value, not state value */
			rr_last_request = RR_REQUEST_START; /* Track last request for validation */
			k_work_submit(&fp_fmdn_rr_indicate_work);

			/* Start ringing locally */
			rr_state.ringing = true;

			/* Notify application to start ringing */
			if (rr_action_cb) {
				rr_action_cb(true);
			}

		} else {
			/* No persistent connection - use advertisement-based ringing */
			LOG_INF("RR: No persistent connection, starting advertisement-based "
				"ringing");
			if (!fp_fmdn_reverse_ringing_adv_start()) {
				rr_state.ringing = true;
				rr_start_time_ms = k_uptime_get();
				k_work_reschedule_for_queue(
					&k_sys_work_q, &fp_fmdn_rr_timer_id,
					K_SECONDS(ADV_RINGING_DURATION_SECONDS));
			} else {
				LOG_ERR("RR: Failed to start advertisement-based ringing");
			}
		}
	}
}
