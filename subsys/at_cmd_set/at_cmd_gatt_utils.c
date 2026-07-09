/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include <zephyr/logging/log.h>
#include <zephyr/bluetooth/gatt.h>
#include "at_cmd_gatt_utils.h"
#include "at_cmd_set_common.h"
#if defined(CONFIG_AT_CMD_GATT_DFT_SERVER)
#include "at_cmd_gatt.h"
#endif
#if defined(CONFIG_AT_CMD_GATT_DYN_SERVER)
#include "at_cmd_gatt_dyn.h"
#endif

LOG_MODULE_REGISTER(at_cmd_gatt_utils, CONFIG_AT_CMD_SET_LOG_LEVEL);

/* ---- Permission / property helpers ---------------------------------------- */

bool at_cmd_gatt_is_valid_perm(uint16_t perm)
{
	return (perm & ~AT_GATT_PERM_VALID_MASK) == 0;
}

uint8_t at_cmd_gatt_sec_prop_to_chrc_props(uint16_t sec_prop)
{
	uint8_t props = 0;

	if (sec_prop & AT_GATT_PERM_READ_MASK) {
		props |= BT_GATT_CHRC_READ;
	}
	if (sec_prop & AT_GATT_PERM_WRITE_MASK) {
		props |= BT_GATT_CHRC_WRITE_WITHOUT_RESP;
	}
	if (sec_prop & AT_CMD_GATT_CHRC_NOTIFY_BIT) {
		props |= BT_GATT_CHRC_NOTIFY;
	}
	if (sec_prop & AT_CMD_GATT_CHRC_INDICATE_BIT) {
		props |= BT_GATT_CHRC_INDICATE;
	}
	return props;
}

/* ---- AT+BLEGATTTOBLE (notify / indicate) ---------------------------------- */

/* bt_gatt_indicate() is async; params must remain valid until completion */
static struct bt_gatt_indicate_params s_ind_params;

at_cmd_result_t at_cmd_gatt_to_ble(uint8_t conidx, uint16_t handle, at_cmd_gatt_act_t action,
				   const uint8_t *data, uint16_t len)
{
	struct bt_conn *conn = at_cmd_conn_get(conidx);

	if (!conn) {
		return (at_cmd_result_t){.err = -ENOTCONN, .app_err = AT_ERR_BLE_EINVAL};
	}

	struct bt_gatt_attr *attr = NULL;

#if defined(CONFIG_AT_CMD_GATT_DFT_SERVER)
	attr = at_cmd_gatt_dft_find_attr_by_handle(handle);
#endif
#if defined(CONFIG_AT_CMD_GATT_DYN_SERVER)
	if (!attr) {
		attr = at_cmd_gatt_dyn_find_attr_by_handle(handle);
	}
#endif

	if (!attr) {
		return (at_cmd_result_t){.err = -ENOENT, .app_err = AT_ERR_GATT_INVALID_HANDLE};
	}

	int ret = 0;

	switch (action) {
	case AT_GATT_ACT_NOTIFY:
		ret = bt_gatt_notify(conn, attr, (void *)data, len);
		break;
	case AT_GATT_ACT_INDICATE:
		s_ind_params = (struct bt_gatt_indicate_params){
			.attr = attr,
			.data = data,
			.len = len,
		};
		ret = bt_gatt_indicate(conn, &s_ind_params);
		break;
	default:
		return (at_cmd_result_t){.err = -EINVAL, .app_err = AT_ERR_PARAM_INVALID};
	}

	return (at_cmd_result_t){.err = ret, .app_err = ret ? at_cmd_map_errno(ret) : 0};
}
