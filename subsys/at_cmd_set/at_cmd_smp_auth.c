/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include <zephyr/init.h>
#include <zephyr/bluetooth/conn.h>
#include <zephyr/logging/log.h>
#include "at_cmd_set_common.h"
#include "at_cmd_event.h"

LOG_MODULE_DECLARE(at_cmd_set, CONFIG_AT_CMD_SET_LOG_LEVEL);

/* cancel: log only; pairing_failed will follow with the real reason */
static void smp_cancel(struct bt_conn *conn)
{
	ARG_UNUSED(conn);
	LOG_WRN("SMP auth cancelled by stack");
}

#ifdef CONFIG_AT_EVT_BLESMPPASSKEY
static void smp_passkey_display(struct bt_conn *conn, unsigned int passkey)
{
	at_cmd_ctx_t *ctx = at_cmd_ctx_get();
	uint8_t idx = at_cmd_conn_slot(conn);

	if (!ctx || (idx == UINT8_MAX)) {
		return;
	}
	at_cmd_evt_smp_passkey(ctx->ch, idx, (uint32_t)passkey);
}
#endif /* CONFIG_AT_EVT_BLESMPPASSKEY */

#ifdef CONFIG_AT_EVT_BLESMPPASSKEYREQIND
static void smp_passkey_entry(struct bt_conn *conn)
{
	at_cmd_ctx_t *ctx = at_cmd_ctx_get();
	uint8_t idx = at_cmd_conn_slot(conn);

	if (!ctx || (idx == UINT8_MAX)) {
		return;
	}
	at_cmd_evt_smp_passkeyreqind(ctx->ch, idx);
}
#endif /* CONFIG_AT_EVT_BLESMPPASSKEYREQIND */

#ifdef CONFIG_AT_EVT_BLESMPNUMCOMPIND
static void smp_passkey_confirm(struct bt_conn *conn, unsigned int passkey)
{
	at_cmd_ctx_t *ctx = at_cmd_ctx_get();
	uint8_t idx = at_cmd_conn_slot(conn);

	if (!ctx || (idx == UINT8_MAX)) {
		return;
	}
	at_cmd_evt_smp_numcompind(ctx->ch, idx, (uint32_t)passkey);
}
#endif /* CONFIG_AT_EVT_BLESMPNUMCOMPIND */

/* Pre-built auth callback tables indexed by io_cap (0..4) */
static const struct bt_conn_auth_cb auth_cb_niio = {
	/* NoInputNoOutput: all NULL — Just Works only */
};

static const struct bt_conn_auth_cb auth_cb_display_only = {
#ifdef CONFIG_AT_EVT_BLESMPPASSKEY
	.passkey_display = smp_passkey_display,
#endif
	.cancel = smp_cancel,
};

static const struct bt_conn_auth_cb auth_cb_display_yesno = {
#ifdef CONFIG_AT_EVT_BLESMPPASSKEY
	.passkey_display = smp_passkey_display,
#endif
#ifdef CONFIG_AT_EVT_BLESMPNUMCOMPIND
	.passkey_confirm = smp_passkey_confirm,
#endif
	.cancel = smp_cancel,
};

static const struct bt_conn_auth_cb auth_cb_keyboard_only = {
#ifdef CONFIG_AT_EVT_BLESMPPASSKEYREQIND
	.passkey_entry = smp_passkey_entry,
#endif
	.cancel = smp_cancel,
};

static const struct bt_conn_auth_cb auth_cb_keyboard_display = {
#ifdef CONFIG_AT_EVT_BLESMPPASSKEY
	.passkey_display = smp_passkey_display,
#endif
#ifdef CONFIG_AT_EVT_BLESMPPASSKEYREQIND
	.passkey_entry = smp_passkey_entry,
#endif
#ifdef CONFIG_AT_EVT_BLESMPNUMCOMPIND
	.passkey_confirm = smp_passkey_confirm,
#endif
	.cancel = smp_cancel,
};

const struct bt_conn_auth_cb *at_cmd_smp_get_auth_cb(uint8_t io_cap)
{
	static const struct bt_conn_auth_cb *const tbl[] = {
		&auth_cb_niio,          &auth_cb_display_only,     &auth_cb_display_yesno,
		&auth_cb_keyboard_only, &auth_cb_keyboard_display,
	};

	if (io_cap >= ARRAY_SIZE(tbl)) {
		return NULL;
	}
	return tbl[io_cap];
}

#ifdef CONFIG_AT_EVT_BLESMPPAIRENDIND
static void smp_pairing_complete(struct bt_conn *conn, bool bonded)
{
	at_cmd_ctx_t *ctx = at_cmd_ctx_get();
	uint8_t idx = at_cmd_conn_slot(conn);

	if (!ctx || (idx == UINT8_MAX)) {
		return;
	}
	at_cmd_evt_smp_pairendind(ctx->ch, idx, bonded, 0);
}

static void smp_pairing_failed(struct bt_conn *conn, enum bt_security_err reason)
{
	at_cmd_ctx_t *ctx = at_cmd_ctx_get();
	uint8_t idx = at_cmd_conn_slot(conn);

	if (!ctx || (idx == UINT8_MAX)) {
		return;
	}
	at_cmd_evt_smp_pairendind(ctx->ch, idx, false, (uint8_t)reason);
}
#endif /* CONFIG_AT_EVT_BLESMPPAIRENDIND */

static struct bt_conn_auth_info_cb at_cmd_auth_info_cb = {
#ifdef CONFIG_AT_EVT_BLESMPPAIRENDIND
	.pairing_complete = smp_pairing_complete,
	.pairing_failed = smp_pairing_failed,
#endif
};

static int at_cmd_smp_auth_init(void)
{
	return bt_conn_auth_info_cb_register(&at_cmd_auth_info_cb);
}

SYS_INIT(at_cmd_smp_auth_init, APPLICATION, CONFIG_APPLICATION_INIT_PRIORITY);

#ifdef CONFIG_ZTEST
/*
 * Test hooks: expose the static pairing-result callbacks so ZTests can invoke
 * them directly with controlled inputs.  Real BT stack callbacks remain the
 * only production caller; these wrappers exist purely to drive coverage in unit
 * tests where no real peer is available.
 */
#ifdef CONFIG_AT_EVT_BLESMPPAIRENDIND
void at_cmd_smp_auth_test_pairing_complete(struct bt_conn *conn, bool bonded)
{
	smp_pairing_complete(conn, bonded);
}

void at_cmd_smp_auth_test_pairing_failed(struct bt_conn *conn, enum bt_security_err reason)
{
	smp_pairing_failed(conn, reason);
}
#endif /* CONFIG_AT_EVT_BLESMPPAIRENDIND */
#endif /* CONFIG_ZTEST */
