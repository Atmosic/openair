/**
 *******************************************************************************
 *
 * @file dis.c
 *
 * @brief Atmosic Google Fast Pair Device Information Service (DIS)
 *
 * Copyright (C) Atmosic 2025-2026
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
#include "fp_conn.h"
#include "fp_mode.h"

LOG_MODULE_REGISTER(gfp_dis, CONFIG_ATM_GFP_DIS_LOG_LEVEL);

/* Firmware version string buffer (application-defined format).
 * Special strings: "status-updating" or "status-abnormal"
 * Buffer size: CONFIG_GFP_DIS_FW_VERSION_STR_MAX
 */
static char gfp_dis_fw_version[CONFIG_GFP_DIS_FW_VERSION_STR_MAX];

/**
 * @brief Check if connection is authenticated or bonded
 * @param conn Bluetooth connection
 * @return true if connection is authenticated/bonded, false otherwise
 */
static bool is_connection_authenticated(struct bt_conn *conn)
{
	if (!conn || !fp_conn_validate(conn)) {
		// Not a fp connection
		return false;
	}
	if (fp_mode_get() == FP_MODE_PAIRING) {
		LOG_DBG("Firmware revision read attempt allowed when the Provider is discoverable");
		return true;
	}
	/* Check security level - L3 and above indicate authentication/bonding */
	bt_security_t sec_level = bt_conn_get_security(conn);
	if (sec_level < BT_SECURITY_L3) {
		LOG_WRN("Firmware revision read attempt from non-authentication connection");
		return false;
	}
	return true;
}

#define GFP_DIS_ATT_ERR_UNAUTHENTICATED 0x80

/**
 * @brief Read firmware revision characteristic
 *
 * FHN v2: firmware revision is returned only when either of the following is true:
 *   - The Seeker is bonded (security level >= L3), OR
 *   - Any FHN operation authenticated with the account key was successfully completed
 *     over the same connection before this read (expressed here as pairing mode / L3+).
 * Otherwise the Provider returns ATT application error 0x80 (unauthenticated).
 */
static ssize_t read_fw_revision(struct bt_conn *conn, const struct bt_gatt_attr *attr, void *buf,
				uint16_t len, uint16_t offset)
{
	if (!is_connection_authenticated(conn)) {
		LOG_WRN("Firmware revision read rejected - unauthenticated connection");
		return BT_GATT_ERR(GFP_DIS_ATT_ERR_UNAUTHENTICATED);
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
