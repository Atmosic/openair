/**
 *******************************************************************************
 *
 * @file fp_fmdn_persistent_conn.c
 *
 * @brief Atmosic Google Fast Pair Find My Device Network (FMDN) v2
 * Persistent Connection Management Implementation
 *
 * Copyright (C) Atmosic 2026
 *
 *******************************************************************************
 */

#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
#include <zephyr/bluetooth/bluetooth.h>
#include <zephyr/bluetooth/conn.h>
#include "fp_fmdn_persistent_conn.h"
#include "fp_storage.h"

LOG_MODULE_DECLARE(fmdn, CONFIG_ATM_FMDN_LOG_LEVEL);

/// Persistent connection state (only one allowed at a time)
static fp_fmdn_persistent_conn_state_t pc_state = {
	.client_id = PC_CLIENT_ID_NONE,
};

/// Per spec: "ignore the 5 most significant bits of the connection type value"
#define PC_CONN_TYPE_LSB_MASK             0x07U
/// Short CI threshold: 500ms / 1.25ms per unit = 400 units
#define PC_SHORT_CI_THRESHOLD_UNITS       400U
/// Timeout to restore low-power interval after a Seeker-requested short CI (seconds)
#define PC_SHORT_CI_RESTORE_TIMEOUT_SEC   60U
/// Timeout to revert from Persistent Interactive mode to the previous type (seconds)
#define PC_INTERACTIVE_REVERT_TIMEOUT_SEC (5U * 60U)

/// Connection type active before the last transition into Persistent Interactive mode.
/// Determines the revert target when the 5-minute timer fires.
static uint8_t pc_prev_conn_type;

/// Set in pc_le_param_req to the conn that proposed a central parameter update.
/// Cleared in pc_le_param_updated after consuming it, and on PC conn disconnect.
static struct bt_conn *pc_central_update_conn;

/// Remaining negotiation retry attempts for the current negotiation session.
static uint8_t pc_nego_retry_remaining;

/// Adv listener for persistent connection state changes.
static fp_fmdn_pc_state_cb_t pc_state_cb;

void fp_fmdn_persistent_conn_register_state_cb(fp_fmdn_pc_state_cb_t cb)
{
	pc_state_cb = cb;
}

/// Notify the registered listener of the current PC state.
/// Only fires when is_active or conn_type actually changes to avoid
/// spurious advertising restarts (e.g. during CS ranging setup).
static void pc_notify_state_changed(void)
{
	if (!pc_state_cb) {
		return;
	}

	static bool last_active;
	static uint8_t last_conn_type;

	if (last_active == pc_state.is_active && last_conn_type == pc_state.conn_type) {
		return;
	}
	last_active = pc_state.is_active;
	last_conn_type = pc_state.conn_type;
	pc_state_cb(pc_state.is_active, pc_state.conn_type);
}

static void pc_short_ci_restore_handler(struct k_work *work);
static void pc_interactive_revert_handler(struct k_work *work);
static void pc_nego_retry_handler(struct k_work *work);

static K_WORK_DELAYABLE_DEFINE(pc_short_ci_restore_work, pc_short_ci_restore_handler);
static K_WORK_DELAYABLE_DEFINE(pc_interactive_revert_work, pc_interactive_revert_handler);
static K_WORK_DELAYABLE_DEFINE(pc_nego_retry_work, pc_nego_retry_handler);

static bool pc_is_non_interactive_persistent(uint8_t conn_type_lsb)
{
	return (conn_type_lsb == PC_CONN_TYPE_PERSISTENT_CONNECTABLE) ||
	       (conn_type_lsb == PC_CONN_TYPE_PERSISTENT_DETECTABLE) ||
	       (conn_type_lsb == PC_CONN_TYPE_PERSISTENT_UNDETECTABLE);
}

static void pc_restore_low_power_interval(void)
{
	struct bt_le_conn_param params;
	int err = fp_fmdn_persistent_conn_get_conn_param(pc_state.conn_type, &params);

	if (err) {
		return;
	}
	/* Guard: configure may have preempted and already started its own negotiation.
	 * If the restore work was already submitted to the queue before configure ran,
	 * k_work_cancel_delayable would have failed silently — this check prevents a
	 * duplicate bt_conn_le_param_update.
	 */
	if (pc_state.negotiation_pending) {
		LOG_INF("PC: Negotiation already pending, skipping low-power interval restore");
		return;
	}
	pc_nego_retry_remaining = CONFIG_FMDN_PC_NEGO_RETRY_COUNT;
	pc_state.negotiation_pending = true;
	err = bt_conn_le_param_update(pc_state.conn, &params);
	if (err) {
		pc_state.negotiation_pending = false;
		LOG_WRN("PC: Failed to restore low-power interval: %d", err);
	} else {
		LOG_INF("PC: Re-initiated low-power interval restoration");
	}
}

static void pc_short_ci_restore_handler(struct k_work *work)
{
	ARG_UNUSED(work);

	if (!pc_state.is_active || !pc_state.conn) {
		return;
	}

	uint8_t conn_type_lsb = pc_state.conn_type & PC_CONN_TYPE_LSB_MASK;

	if (!pc_is_non_interactive_persistent(conn_type_lsb)) {
		return;
	}

	LOG_INF("PC: Short CI %us timeout on type 0x%02x - restoring low-power interval",
		PC_SHORT_CI_RESTORE_TIMEOUT_SEC, conn_type_lsb);
	pc_restore_low_power_interval();
}

static void pc_interactive_revert_handler(struct k_work *work)
{
	ARG_UNUSED(work);

	if (!pc_state.is_active || !pc_state.conn) {
		return;
	}

	uint8_t conn_type_lsb = pc_state.conn_type & PC_CONN_TYPE_LSB_MASK;

	if (conn_type_lsb != PC_CONN_TYPE_PERSISTENT_INTERACTIVE) {
		/* Already reverted by an explicit configure request */
		return;
	}

	/* Per spec: revert to the previous non-interactive persistent type, or to
	 * Persistent Connectable if the connection was not previously persistent.
	 */
	uint8_t revert_to = pc_is_non_interactive_persistent(pc_prev_conn_type)
				    ? pc_prev_conn_type
				    : PC_CONN_TYPE_PERSISTENT_CONNECTABLE;

	LOG_INF("PC: Interactive %us timeout - reverting from 0x01 to conn_type 0x%02x",
		PC_INTERACTIVE_REVERT_TIMEOUT_SEC, revert_to);
	pc_state.conn_type = revert_to;

	/* Adv params depend on conn_type; reconfigure even if CI nego fails. */
	pc_notify_state_changed();

	struct bt_le_conn_param params;
	int err = fp_fmdn_persistent_conn_get_conn_param(revert_to, &params);

	if (err) {
		return;
	}
	/* Guard: a concurrent configure may have already started a negotiation. */
	if (pc_state.negotiation_pending) {
		LOG_INF("PC: Negotiation already pending, skipping interactive revert");
		return;
	}
	pc_nego_retry_remaining = CONFIG_FMDN_PC_NEGO_RETRY_COUNT;
	pc_state.negotiation_pending = true;
	err = bt_conn_le_param_update(pc_state.conn, &params);
	if (err) {
		pc_state.negotiation_pending = false;
		LOG_WRN("PC: Failed to update params on interactive revert: %d", err);
	}
}

static void pc_nego_retry_handler(struct k_work *work)
{
	ARG_UNUSED(work);

	if (!pc_state.is_active || !pc_state.conn) {
		return;
	}

	struct bt_le_conn_param params;
	int err = fp_fmdn_persistent_conn_get_conn_param(pc_state.conn_type, &params);

	if (err) {
		return;
	}

	LOG_INF("PC: Retrying negotiation (remaining=%u)", pc_nego_retry_remaining);
	pc_state.negotiation_pending = true;
	err = bt_conn_le_param_update(pc_state.conn, &params);
	if (err) {
		pc_state.negotiation_pending = false;
		LOG_WRN("PC: Retry - failed to initiate param update: %d", err);
		fp_fmdn_persistent_conn_param_nego_complete(pc_state.conn, err);
	}
}

static bool pc_le_param_req(struct bt_conn *conn, struct bt_le_conn_param *param)
{
	LOG_INF("PC: le_param_req min=%u max=%u latency=%u timeout=%u is_active=%d conn_match=%d",
		param->interval_min, param->interval_max, param->latency, param->timeout,
		pc_state.is_active, (pc_state.conn == conn));

	/* Track the CPR conn when not yet in a PC session (CPR may arrive before
	 * configure establishes pc_state.conn), or when it is the PC conn itself.
	 * Ignore CPR from other connections while PC is active to avoid overwriting.
	 */
	if (!pc_state.is_active || (pc_state.conn == conn)) {
		pc_central_update_conn = conn;
	}

	if (!pc_state.is_active || (pc_state.conn != conn)) {
		return true;
	}

	uint8_t conn_type_lsb = pc_state.conn_type & PC_CONN_TYPE_LSB_MASK;

	if (pc_is_non_interactive_persistent(conn_type_lsb) &&
	    (param->interval_max < PC_SHORT_CI_THRESHOLD_UNITS)) {
		LOG_INF("PC: Accepting short CI (max=%u units) on type 0x%02x - "
			"starting %us restore timer",
			param->interval_max, conn_type_lsb, PC_SHORT_CI_RESTORE_TIMEOUT_SEC);
		k_work_reschedule(&pc_short_ci_restore_work,
				  K_SECONDS(PC_SHORT_CI_RESTORE_TIMEOUT_SEC));
	}

	return true;
}

static void pc_le_param_updated(struct bt_conn *conn, uint16_t interval, uint16_t latency,
				uint16_t timeout)
{
	LOG_DBG("PC: le_param_updated interval=%u latency=%u timeout=%u is_active=%d conn_match=%d",
		interval, latency, timeout, pc_state.is_active, (pc_state.conn == conn));

	if (!pc_state.is_active || (pc_state.conn != conn)) {
		/* Clear CPR tracking even on early return: if this conn's CPR
		 * le_param_updated fires before configure sets is_active, we must
		 * not carry the stale pointer into the post-configure negotiation's
		 * le_param_updated where it would cause a false from_central=true.
		 */
		if (pc_central_update_conn == conn) {
			pc_central_update_conn = NULL;
		}
		return;
	}

	if (!pc_state.negotiation_pending) {
		/* No active negotiation from our side. */
		LOG_INF("PC: le_param_updated - not our negotiation, ignoring");
		return;
	}

	bool from_central = (pc_central_update_conn == conn);

	pc_central_update_conn = NULL;

	/* Outcome-based check: regardless of who initiated the update, if the
	 * resulting interval satisfies our requirements the negotiation goal is
	 * achieved.  This handles the race where our LL request and the central's
	 * CPR are both in flight — the one that completes first may carry the right
	 * interval even though pc_central_update_pending is still set.
	 */
	struct bt_le_conn_param expected;
	int err = fp_fmdn_persistent_conn_get_conn_param(pc_state.conn_type, &expected);

	if (err) {
		LOG_ERR("PC: le_param_updated - failed to get expected params: %d", err);
		pc_state.negotiation_pending = false;
		fp_fmdn_persistent_conn_param_nego_complete(conn, err);
		return;
	}

	bool satisfies = (interval >= expected.interval_min) && (interval <= expected.interval_max);

	LOG_INF("PC: le_param_updated interval=%u (expected %u-%u) latency=%u timeout=%u "
		"from=%s -> %s",
		interval, expected.interval_min, expected.interval_max, latency, timeout,
		from_central ? "central" : "us", satisfies ? "OK" : "MISMATCH");

	if (satisfies) {
		/* Negotiation goal achieved — accept regardless of initiator. */
		pc_state.negotiation_pending = false;
		fp_fmdn_persistent_conn_param_nego_complete(conn, 0);
	} else if (from_central) {
		/* Central changed CI to a different range; our request is still
		 * pending (stored in Zephyr or in-flight) — keep negotiation_pending.
		 */
		LOG_INF("PC: Central update doesn't satisfy our params, negotiation still pending");
	} else {
		/* Our request completed but with wrong interval — MISMATCH. */
		pc_state.negotiation_pending = false;
		fp_fmdn_persistent_conn_param_nego_complete(conn, -EINVAL);
	}
}

#ifdef CONFIG_BT_USER_CONN_PARAM_REJECTED
static void pc_le_param_update_rejected(struct bt_conn *conn, uint8_t hci_err)
{
	LOG_DBG("PC: le_param_update_rejected hci_err=0x%02x is_active=%d conn_match=%d", hci_err,
		pc_state.is_active, (pc_state.conn == conn));

	if (!pc_state.is_active || (pc_state.conn != conn)) {
		return;
	}

	if (!pc_state.negotiation_pending) {
		LOG_INF("PC: le_param_update_rejected - not our negotiation, ignoring");
		return;
	}

	pc_state.negotiation_pending = false;
	uint8_t conn_type_lsb = pc_state.conn_type & PC_CONN_TYPE_LSB_MASK;

	/* Collision errors are transient — the remote was busy with another LL
	 * procedure.  Allow the retry mechanism to recover.
	 * All other rejection reasons indicate a fundamental parameter problem;
	 * exhaust retries immediately so nego_complete disconnects right away.
	 */
	bool retriable = (hci_err == BT_HCI_ERR_LL_PROC_COLLISION) ||
			 (hci_err == BT_HCI_ERR_DIFF_TRANS_COLLISION);

	if (!retriable) {
		pc_nego_retry_remaining = 0;
	}

	LOG_WRN("PC: Negotiation rejected (hci_err=0x%02x) on type 0x%02x (%s)", hci_err,
		conn_type_lsb, retriable ? "retriable" : "fatal");
	fp_fmdn_persistent_conn_param_nego_complete(pc_state.conn, -ECONNREFUSED);
}
#endif /* CONFIG_BT_USER_CONN_PARAM_REJECTED */

BT_CONN_CB_DEFINE(pc_conn_cb) = {
	.le_param_req = pc_le_param_req,
	.le_param_updated = pc_le_param_updated,
#ifdef CONFIG_BT_USER_CONN_PARAM_REJECTED
	.le_param_update_rejected = pc_le_param_update_rejected,
#endif
};

static void fp_fmdn_persistent_conn_reset(void)
{
	k_work_cancel_delayable(&pc_short_ci_restore_work);
	k_work_cancel_delayable(&pc_interactive_revert_work);
	k_work_cancel_delayable(&pc_nego_retry_work);
	pc_state.conn = NULL;
	pc_state.client_id = PC_CLIENT_ID_NONE;
	pc_state.conn_type = 0;
	pc_state.is_active = false;
	pc_state.negotiate_interval = false;
	pc_state.negotiation_pending = false;
	pc_central_update_conn = NULL;
}

int fp_fmdn_persistent_conn_init(void)
{
	/* Load saved client ID from NVS (if any)
	 * This enforces ownership across power cycles - only the Seeker that
	 * configured persistent connection with force bit can reconnect,
	 * or a new Seeker must use force bit to take over.
	 */
	uint8_t saved_client_id;
	if (!fp_storage_pc_client_id_get(&saved_client_id)) {
		pc_state.client_id = saved_client_id;
		LOG_INF("PC: Loaded saved client ID from NVS: %u", saved_client_id);
	} else {
		LOG_DBG("PC: No saved client ID in NVS");
	}

	LOG_DBG("Persistent Connection module initialized");
	return 0;
}

void fp_fmdn_persistent_conn_deinit(void)
{
	LOG_DBG("Persistent Connection module deinitialized");
	fp_fmdn_persistent_conn_reset();
}

pc_result_t fp_fmdn_persistent_conn_configure(struct bt_conn *conn, uint8_t flags,
					      uint8_t client_id, uint8_t conn_type)
{
	LOG_INF("PC: Configure request - flags=0x%02x, client_id=0x%02x, conn_type=0x%02x", flags,
		client_id, conn_type);

	/* Per FHN v2 spec: "ignore the 5 most significant bits of the connection type value" */
	uint8_t conn_type_lsb = conn_type & PC_CONN_TYPE_LSB_MASK;

	/* Reject any non-release request that would store 0xFE when current != 0xFF.
	 * conn_type 0x00 always stores 0xFF regardless of client_id, so exempt it.
	 */
	if ((client_id == PC_CLIENT_ID_OEM) && (conn_type_lsb != PC_CONN_TYPE_NON_PERSISTENT) &&
	    (pc_state.client_id != PC_CLIENT_ID_NONE)) {
		LOG_WRN("PC: Rejecting 0xFE claim while current=0x%02x", pc_state.client_id);
		return PC_RESULT_OEM_OWNS;
	}

	/* When OEM owns, only a release (conn_type 0x00 → stores 0xFF) is permitted. */
	if ((pc_state.client_id == PC_CLIENT_ID_OEM) &&
	    (conn_type_lsb != PC_CONN_TYPE_NON_PERSISTENT)) {
		LOG_WRN("PC: OEM app owns persistent connection, rejecting");
		return PC_RESULT_OEM_OWNS;
	}

	/* Per spec: "If the client ID in the request is different from the client ID currently
	 * stored on the Provider, the Provider will act depending on Bit 1 of the first byte."
	 * pc_state.client_id is the single authoritative stored value (loaded from NVS at boot
	 * and kept current at runtime). PC_CLIENT_ID_NONE (0xFF) means the persistent connection
	 * is not owned by any Seeker — any incoming client_id is accepted freely.
	 */
	bool client_id_free = (pc_state.client_id == PC_CLIENT_ID_NONE);
	bool client_id_matches = client_id_free || (client_id == pc_state.client_id);

	if (!client_id_matches) {
		if (!(flags & PC_FLAG_FORCE)) {
			LOG_WRN("PC: Client ID mismatch (stored=0x%02x, req=0x%02x), rejecting",
				pc_state.client_id, client_id);
			return PC_RESULT_ANOTHER_EXISTS;
		}
		/* Force bit set: disconnect any existing persistent connection and take over.
		 * Only disconnect if the old connection is different from the current one —
		 * the requester may be on the same connection reclaiming ownership.
		 */
		LOG_INF("PC: Force bit set, taking over from client ID 0x%02x", pc_state.client_id);
		if (pc_state.is_active && pc_state.conn && (pc_state.conn != conn)) {
			bt_conn_disconnect(pc_state.conn, BT_HCI_ERR_REMOTE_USER_TERM_CONN);
		}
	}

	bool reconfigure_only = pc_state.is_active && (pc_state.conn == conn);
	uint8_t old_conn_type_lsb = pc_state.conn_type & PC_CONN_TYPE_LSB_MASK;

	/* Update persistent connection state (common for all paths) */
	if (conn_type_lsb != PC_CONN_TYPE_NON_PERSISTENT) {
		if (!reconfigure_only) {
			pc_state.conn = conn;
			pc_state.is_active = true;
		}
	} else {
		pc_state.is_active = false;
		pc_state.conn = NULL;
	}
	/* When releasing to non-persistent, always restore client_id to NONE */
	pc_state.client_id =
		(conn_type_lsb == PC_CONN_TYPE_NON_PERSISTENT) ? PC_CLIENT_ID_NONE : client_id;
	pc_state.conn_type = conn_type;
	/* Cancel any in-flight negotiation from a timer handler; this configure supersedes it. */
	pc_state.negotiation_pending = false;
	k_work_cancel_delayable(&pc_nego_retry_work);
	pc_state.negotiate_interval = (flags & PC_FLAG_NEGOTIATE) != 0;

	/* Manage timers for short-CI restoration and Interactive revert.
	 *
	 * Persistent Interactive (0x01): start/restart the 5-minute revert timer.
	 * The short-CI restore timer is not needed because Interactive already
	 * uses low-latency intervals (30-100ms) by spec.
	 *
	 * All other types: cancel both timers.  Fresh interval negotiation (if
	 * requested) will re-establish the correct interval immediately, so there
	 * is nothing to restore.
	 */
	if (conn_type_lsb == PC_CONN_TYPE_PERSISTENT_INTERACTIVE) {
		pc_prev_conn_type = old_conn_type_lsb;
		k_work_reschedule(&pc_interactive_revert_work,
				  K_SECONDS(PC_INTERACTIVE_REVERT_TIMEOUT_SEC));
		k_work_cancel_delayable(&pc_short_ci_restore_work);
	} else {
		k_work_cancel_delayable(&pc_interactive_revert_work);
		k_work_cancel_delayable(&pc_short_ci_restore_work);
	}

	/* Persist ownership across power cycles.
	 * Save when client_id is first set (was NONE) or forcibly changed.
	 * Delete when releasing back to non-persistent (client_id restored to NONE).
	 */
	if (conn_type_lsb == PC_CONN_TYPE_NON_PERSISTENT) {
		fp_storage_pc_client_id_delete();
	} else if (client_id_free || !client_id_matches) {
		fp_storage_pc_client_id_save(client_id);
	}

	LOG_INF("PC: Configured - client_id=0x%02x, conn_type=0x%02x, negotiate=%s",
		pc_state.client_id, conn_type_lsb, pc_state.negotiate_interval ? "yes" : "no");

	/* Per spec: "If negotiation fails, the Provider should disconnect from the Seeker,
	 * except when the requested connection type is 0x00 or 0x01."
	 */
	bool disconnect_on_nego_fail = (conn_type_lsb != PC_CONN_TYPE_NON_PERSISTENT) &&
				       (conn_type_lsb != PC_CONN_TYPE_PERSISTENT_INTERACTIVE);

	/* A Provider that supports persistent connections shall not use BLE
	 * Connection Subrating for any connection that is configured as persistent. When a
	 * subrated connection is configured as a persistent connection, the Provider and Seeker
	 * must terminate any active subrating procedures. Following termination, the connection
	 * must be maintained using standard connection intervals updated within the ranges.
	 *
	 * Terminate by requesting subrate_factor = 1 (no subrating) whenever the connection is
	 * being made persistent. This is a no-op when the connection is not currently subrated.
	 */
#ifdef CONFIG_BT_SUBRATING
	if (conn_type_lsb != PC_CONN_TYPE_NON_PERSISTENT) {
		struct bt_conn_remote_info remote_info;
		int sr_err = bt_conn_get_remote_info(conn, &remote_info);

		if (!sr_err && BT_FEAT_LE_CONN_SUBRATING(remote_info.le.features)) {
			struct bt_conn_le_subrate_param sr_param = {
				.subrate_min = 1,
				.subrate_max = 1,
				.max_latency = 0,
				.continuation_number = 0,
				.supervision_timeout = 800, /* 8 s (800 * 10 ms) */
			};
			int terminate_err = bt_conn_le_subrate_request(conn, &sr_param);

			if (terminate_err) {
				LOG_WRN("PC: Failed to terminate subrating (err=%d)",
					terminate_err);
			} else {
				LOG_INF("PC: Subrating termination initiated (factor=1)");
			}
		}
	}
#endif

	/* Per spec: "When Bit 2 of the first request byte is set, the Provider is responsible
	 * for negotiating the configured connection interval with the Seeker immediately after
	 * a persistent connection is established or reconfigured."
	 * Note: BLE Connection Subrating is banned for persistent connections (see above) so
	 * there is no longer any subrating-based exemption from this negotiation.
	 */
	if (pc_state.negotiate_interval) {
		struct bt_le_conn_param pc_conn_params;

		int err = fp_fmdn_persistent_conn_get_conn_param(conn_type, &pc_conn_params);

		if (err) {
			LOG_ERR("PC: Failed to get connection parameters: %d", err);
			pc_notify_state_changed();
			return PC_RESULT_SUCCESS;
		}

		LOG_INF("PC: Initiating connection parameter update - type=0x%02x, interval=%u-%u "
			"latency=%u timeout=%u",
			conn_type_lsb, pc_conn_params.interval_min, pc_conn_params.interval_max,
			pc_conn_params.latency, pc_conn_params.timeout);
		pc_nego_retry_remaining = CONFIG_FMDN_PC_NEGO_RETRY_COUNT;
		pc_state.negotiation_pending = true;
		err = bt_conn_le_param_update(conn, &pc_conn_params);
		LOG_INF("PC: bt_conn_le_param_update ret=%d", err);
		if (err) {
			LOG_ERR("PC: Failed to initiate parameter update: %d", err);
			pc_state.negotiation_pending = false;
			if (disconnect_on_nego_fail) {
				bt_conn_disconnect(conn, BT_HCI_ERR_REMOTE_USER_TERM_CONN);
				pc_state.is_active = false;
				pc_state.conn = NULL;
			}
			pc_notify_state_changed();
			return PC_RESULT_SUCCESS;
		}
	}

	pc_notify_state_changed();
	return PC_RESULT_SUCCESS;
}

const fp_fmdn_persistent_conn_state_t *fp_fmdn_persistent_conn_get_state(void)
{
	return &pc_state;
}

void fp_fmdn_persistent_conn_param_nego_complete(struct bt_conn *conn, int status)
{
	if (!pc_state.is_active) {
		return;
	}

	LOG_INF("PC: Param negotiation complete - status=%d", status);

	if (!status) {
		pc_nego_retry_remaining = CONFIG_FMDN_PC_NEGO_RETRY_COUNT;
		return;
	}

	/* Per spec: disconnect on negotiation failure, except for types 0x00 and 0x01 */
	uint8_t conn_type_lsb = pc_state.conn_type & PC_CONN_TYPE_LSB_MASK;
	bool disconnect_on_nego_fail = (conn_type_lsb != PC_CONN_TYPE_NON_PERSISTENT) &&
				       (conn_type_lsb != PC_CONN_TYPE_PERSISTENT_INTERACTIVE);

	if (disconnect_on_nego_fail && pc_nego_retry_remaining) {
		pc_nego_retry_remaining--;
		LOG_WRN("PC: Negotiation failed, retrying in %u ms (remaining=%u)",
			CONFIG_FMDN_PC_NEGO_RETRY_INTERVAL_MS, pc_nego_retry_remaining);
		k_work_reschedule(&pc_nego_retry_work,
				  K_MSEC(CONFIG_FMDN_PC_NEGO_RETRY_INTERVAL_MS));
		return;
	}

	if (disconnect_on_nego_fail) {
		LOG_WRN("PC: Parameter negotiation failed (all retries exhausted), disconnecting");
		bt_conn_disconnect(conn, BT_HCI_ERR_REMOTE_USER_TERM_CONN);
		pc_state.is_active = false;
		pc_state.conn = NULL;
		pc_state.negotiation_pending = false;
		k_work_cancel_delayable(&pc_short_ci_restore_work);
		k_work_cancel_delayable(&pc_interactive_revert_work);
		k_work_cancel_delayable(&pc_nego_retry_work);
		/* pc_state.conn is already NULL, so the later disconnected() handler
		 * skips its notify block — notify here to restore default advertising.
		 * client_id/conn_type are intentionally preserved (disconnect ≠ release).
		 */
		pc_notify_state_changed();
	} else {
		LOG_WRN("PC: Parameter negotiation failed (type=0x%02x), keeping connection",
			conn_type_lsb);
	}
}

void fp_fmdn_persistent_conn_disconnected(struct bt_conn *conn)
{
	if (pc_state.conn == conn) {
		LOG_INF("PC: Persistent connection disconnected");
		if (pc_state.is_active) {
			k_work_cancel_delayable(&pc_short_ci_restore_work);
			k_work_cancel_delayable(&pc_interactive_revert_work);
			k_work_cancel_delayable(&pc_nego_retry_work);
			pc_state.is_active = false;
			pc_state.conn = NULL;
			pc_state.negotiation_pending = false;
			/* Restore default adv. */
			pc_notify_state_changed();
		}
		pc_central_update_conn = NULL;
	} else if (pc_central_update_conn == conn) {
		/* pc_state.conn was already cleared before this disconnect event fired
		 * (e.g. by fp_fmdn_persistent_conn_param_nego_complete). Still clear
		 * the stale CPR pointer so it is not carried into the next session.
		 */
		pc_central_update_conn = NULL;
	}
}

int fp_fmdn_persistent_conn_oem_acquire(void)
{
	if (pc_state.client_id != PC_CLIENT_ID_NONE) {
		LOG_WRN("PC: OEM acquire failed - client_id=0x%02x already in use",
			pc_state.client_id);
		return -EBUSY;
	}
	pc_state.client_id = PC_CLIENT_ID_OEM;
	LOG_INF("PC: OEM acquired persistent connection ownership");
	return 0;
}

void fp_fmdn_persistent_conn_oem_release(void)
{
	if (pc_state.client_id != PC_CLIENT_ID_OEM) {
		LOG_WRN("PC: OEM release called but OEM does not own connection (0x%02x)",
			pc_state.client_id);
		return;
	}
	pc_state.client_id = PC_CLIENT_ID_NONE;
	LOG_INF("PC: OEM released persistent connection ownership");
}

int fp_fmdn_persistent_conn_get_conn_param(uint8_t conn_type, struct bt_le_conn_param *param)
{
	/* Per FHN v2 spec: "The Provider should ignore the 5 most significant bits of the
	 * connection type value. Only the 3 least significant bits are used."
	 */
	uint8_t conn_type_lsb = conn_type & PC_CONN_TYPE_LSB_MASK;

	/* For all non-interactive connection types (Connectable, Detectable and Undetectable), the
	 * peripheral latency should be 0. This is because higher latency would result in slow
	 * performance of GATT operations sent to the peripheral when using large connection
	 * interval."
	 * Non-persistent (0x00) and Persistent Interactive (0x01) use short CI (30-100 ms) where
	 * non-zero latency would be harmless, but setting it to 0 for all types is safe and keeps
	 * the implementation simple.
	 */
	param->latency = 0;
	param->timeout = 800; // 8 seconds supervision timeout

	// Set interval based on connection type per FHN v2 spec table
	switch (conn_type_lsb) {
	case PC_CONN_TYPE_NON_PERSISTENT: // 30-100ms
		param->interval_min = 24; // 30ms (24 * 1.25ms)
		param->interval_max = 80; // 100ms (80 * 1.25ms)
		LOG_DBG("PC: Non-persistent connection params: 30-100ms");
		break;
	case PC_CONN_TYPE_PERSISTENT_INTERACTIVE: // 30-100ms
		param->interval_min = 24;         // 30ms (24 * 1.25ms)
		param->interval_max = 80;         // 100ms (80 * 1.25ms)
		LOG_DBG("PC: Persistent Interactive connection params: 30-100ms");
		break;
	case PC_CONN_TYPE_PERSISTENT_CONNECTABLE: // 500-800ms
		param->interval_min = 400;        // 500ms (400 * 1.25ms)
		param->interval_max = 640;        // 800ms (640 * 1.25ms)
		LOG_DBG("PC: Persistent Connectable connection params: 500-800ms");
		break;
	case PC_CONN_TYPE_PERSISTENT_DETECTABLE: // 500-800ms
		param->interval_min = 400;       // 500ms (400 * 1.25ms)
		param->interval_max = 640;       // 800ms (640 * 1.25ms)
		LOG_DBG("PC: Persistent Detectable connection params: 500-800ms");
		break;
	case PC_CONN_TYPE_PERSISTENT_UNDETECTABLE: // 500-800ms
		param->interval_min = 400;         // 500ms (400 * 1.25ms)
		param->interval_max = 640;         // 800ms (640 * 1.25ms)
		LOG_DBG("PC: Persistent Undetectable connection params: 500-800ms");
		break;
	default:
		LOG_ERR("PC: Unknown connection type 0x%02x", conn_type_lsb);
		return -EINVAL;
	}

	return 0;
}

int fp_fmdn_persistent_conn_get_adv_param(uint8_t conn_type, fp_fmdn_pc_adv_param_t *adv_param)
{
	/* Per FHN v2 spec: "ignore the 5 most significant bits of the connection type value" */
	uint8_t conn_type_lsb = conn_type & PC_CONN_TYPE_LSB_MASK;

	// Set advertisement parameters based on connection type
	switch (conn_type_lsb) {
	case PC_CONN_TYPE_NON_PERSISTENT: // default frequency (at least once every 2 seconds per
					  // FHN spec)
		adv_param->interval_ms = 2000;
		adv_param->connectable = true;
		LOG_DBG("PC: Non-persistent adv params: 2000ms, connectable=true");
		break;
	case PC_CONN_TYPE_PERSISTENT_INTERACTIVE: // at least once every 30 seconds, connectable
		adv_param->interval_ms = 30000;
		adv_param->connectable = true;
		LOG_DBG("PC: Persistent Interactive adv params: 30000ms, connectable=true");
		break;
	case PC_CONN_TYPE_PERSISTENT_CONNECTABLE: // at least once every 3 seconds, connectable
		adv_param->interval_ms = 3000;
		adv_param->connectable = true;
		LOG_DBG("PC: Persistent Connectable adv params: 3000ms, connectable=true");
		break;
	case PC_CONN_TYPE_PERSISTENT_DETECTABLE: // at least once every 30 seconds, NOT connectable
		adv_param->interval_ms = 30000;
		adv_param->connectable = false;
		LOG_DBG("PC: Persistent Detectable adv params: 30000ms, connectable=false");
		break;
	case PC_CONN_TYPE_PERSISTENT_UNDETECTABLE: // NO advertisements
		adv_param->interval_ms = 0;
		adv_param->connectable = false;
		LOG_DBG("PC: Persistent Undetectable adv params: no advertisements");
		break;
	default:
		// Should not reach here due to LSB masking
		adv_param->interval_ms = 0;
		adv_param->connectable = false;
		break;
	}

	return 0;
}
