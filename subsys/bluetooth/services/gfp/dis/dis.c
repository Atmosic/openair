/*
 * Copyright (c) 2025-2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

/**
 *******************************************************************************
 *
 * @file dis.c
 *
 * @brief Atmosic Google Fast Pair Device Information Service (DIS)
 *
 *******************************************************************************
 */

#include <zephyr/types.h>
#include <stddef.h>
#include <string.h>
#include <errno.h>
#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
#include <zephyr/bluetooth/bluetooth.h>
#include <zephyr/bluetooth/conn.h>
#include <zephyr/bluetooth/uuid.h>
#include <zephyr/bluetooth/gatt.h>
#include "fp_auth.h"
#include "fp_conn.h"
#include "fp_mode.h"

LOG_MODULE_REGISTER(gfp_dis, CONFIG_ATM_GFP_DIS_LOG_LEVEL);

/* Firmware version string buffer (application-defined format).
 * Special strings: "status-updating" or "status-abnormal"
 * Buffer size: CONFIG_GFP_DIS_FW_VERSION_STR_MAX
 */
static char gfp_dis_fw_version[CONFIG_GFP_DIS_FW_VERSION_STR_MAX];

struct bond_check_ctx {
	const bt_addr_le_t *peer_addr;
	bool found;
};

static void bond_check_cb(const struct bt_bond_info *info, void *user_data)
{
	struct bond_check_ctx *ctx = user_data;
	bt_addr_le_t peer_id = *ctx->peer_addr;

	/* Normalize: strip the resolved-RPA bit (bit 1) so that
	 * BT_ADDR_LE_PUBLIC_ID / BT_ADDR_LE_RANDOM_ID map back to
	 * the plain identity address type stored in the bond list.
	 */
	peer_id.type &= BT_ADDR_LE_RANDOM;
	if (bt_addr_le_eq(&info->addr, &peer_id)) {
		ctx->found = true;
	}
}

static bool is_peer_bonded(struct bt_conn *conn)
{
	struct bt_conn_info info;

	if (bt_conn_get_info(conn, &info)) {
		return false;
	}

	struct bond_check_ctx ctx = {
		.peer_addr = bt_conn_get_dst(conn),
	};

	bt_foreach_bond(info.id, bond_check_cb, &ctx);
	return ctx.found;
}

/**
 * @brief Check if connection is allowed to read Firmware Revision
 *
 * Per spec, access is granted when any of the following is true:
 *   1. The Provider is discoverable — any device may read.
 *   2. The connection is with a bonded Seeker (even before re-encryption).
 *   3. A preceding operation on this connection proved the Seeker's knowledge
 *      of the account key (KBP crypto verified).
 *
 * @param conn Bluetooth connection
 * @return true if access is permitted, false otherwise
 */
static bool is_connection_authenticated(struct bt_conn *conn)
{
	if (!conn || !fp_conn_validate(conn)) {
		// Not a fp connection
		return false;
	}
	/* Condition 1: any device allowed while Provider is discoverable */
	if (fp_mode_get() == FP_MODE_PAIRING) {
		LOG_DBG("Firmware revision read allowed: Provider is discoverable");
		return true;
	}
	/* Condition 2: bonded Seeker — allowed even as the first operation on
	 * the connection, before re-encryption completes.
	 */
	if (is_peer_bonded(conn)) {
		LOG_DBG("Firmware revision read allowed: bonded peer");
		return true;
	}
	/* Condition 3: non-bonded Seeker that proved account key knowledge via
	 * a preceding operation on this connection (e.g. beacon parameters read,
	 * provisioning state read).
	 */
	if (fp_auth_is_account_key_proven(conn)) {
		LOG_DBG("Firmware revision read allowed: account key proven");
		return true;
	}
	LOG_WRN("Firmware revision read attempt from non-bonded connection");
	return false;
}

#define GFP_DIS_ATT_ERR_UNAUTHENTICATED 0x80

/**
 * @brief Read firmware revision characteristic
 *
 * FHN v2: firmware revision is returned only when either of the following is true:
 *   - The Seeker is bonded (allowed even before re-encryption on reconnect), OR
 *   - A preceding operation on this connection proved the Seeker's knowledge of
 *     the account key (e.g. beacon parameters read, provisioning state read).
 * Otherwise the Provider returns ATT application error 0x80 (unauthenticated).
 * Per spec, an empty string must never be returned.
 */
static ssize_t read_fw_revision(struct bt_conn *conn, const struct bt_gatt_attr *attr, void *buf,
				uint16_t len, uint16_t offset)
{
	if (!is_connection_authenticated(conn)) {
		LOG_WRN("Firmware revision read rejected - unauthenticated connection");
		return BT_GATT_ERR(GFP_DIS_ATT_ERR_UNAUTHENTICATED);
	}

	if (!gfp_dis_fw_version[0]) {
		LOG_ERR("Firmware revision read rejected - version string not initialized");
		return BT_GATT_ERR(BT_ATT_ERR_UNLIKELY);
	}

	LOG_DBG("Firmware revision read: %s", gfp_dis_fw_version);
	return bt_gatt_attr_read(conn, attr, buf, len, offset, gfp_dis_fw_version,
				 strlen(gfp_dis_fw_version));
}

BT_GATT_SERVICE_DEFINE(gfp_dis_svc, BT_GATT_PRIMARY_SERVICE(BT_UUID_DIS),
		       BT_GATT_CHARACTERISTIC(BT_UUID_DIS_FIRMWARE_REVISION, BT_GATT_CHRC_READ,
					      BT_GATT_PERM_READ, read_fw_revision, NULL, NULL), );

int gfp_dis_init(const char *fw_version)
{
	size_t fw_version_len = strlen(fw_version);
	if (fw_version_len >= sizeof(gfp_dis_fw_version)) {
		LOG_ERR("Firmware version string too long (%zu >= %zu)", fw_version_len,
			sizeof(gfp_dis_fw_version));
		return -ENAMETOOLONG;
	}

	strncpy(gfp_dis_fw_version, fw_version, sizeof(gfp_dis_fw_version) - 1);
	gfp_dis_fw_version[sizeof(gfp_dis_fw_version) - 1] = '\0';

	LOG_INF("Initialized with firmware version: %s", gfp_dis_fw_version);
	return 0;
}
