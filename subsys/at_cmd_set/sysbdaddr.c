/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include <errno.h>
#include <zephyr/bluetooth/conn.h>
#include <zephyr/bluetooth/bluetooth.h>
#include <zephyr/bluetooth/addr.h>
#include <zephyr/logging/log.h>
#include <zephyr/sys/byteorder.h>
#include <zephyr/sys/util.h>
#include "at_cmd.h"
#include "at_cmd_set_common.h"

#define CMD_NAME          "SYSBDADDR"
#define CMD_PARM_FMT      "B,A(6~6)"
#define CMD_PARM_DESC     "<bt_id>,<addr(6B)>"
#define CMD_PARM_NUM      2
#define RSP_PARM_PAIR_FMT "B,A(6~6)"
#define RSP_PARM_PAIR_NUM 2
#define RSP_PARM_FMT      LISTIFY(CONFIG_BT_ID_MAX, _AT_CMD_FMT_ITEM, (), RSP_PARM_PAIR_FMT)
#define RSP_PARM_NUM      (CONFIG_BT_ID_MAX * RSP_PARM_PAIR_NUM)

LOG_MODULE_REGISTER(sysbdaddr, CONFIG_AT_CMD_SET_LOG_LEVEL);

#if defined(CONFIG_BT_CONN)
static void sysbdaddr_count_conn(struct bt_conn *conn, void *user_data)
{
	ARG_UNUSED(conn);
	uint8_t *count = user_data;

	(*count)++;
}
#endif

static bool at_cmd_sys_bdaddr_conn_active(void)
{
#if defined(CONFIG_BT_CONN)
	uint8_t count = 0;

	bt_conn_foreach(BT_CONN_TYPE_ALL, sysbdaddr_count_conn, &count);
	return count;
#else
	return false;
#endif
}

static int at_cmd_sys_bdaddr_set(uint8_t id, const bt_addr_le_t *addr)
{
	bt_addr_le_t identities[CONFIG_BT_ID_MAX];
	bt_addr_le_t addr_copy;
	size_t count = ARRAY_SIZE(identities);
	int ret;

	bt_id_get(identities, &count);
	if (id > count) {
		return -EINVAL;
	}

	bt_addr_le_copy(&addr_copy, addr);
	if (id == count) {
		ret = bt_id_create(&addr_copy, NULL);
		if (ret < 0) {
			return ret;
		}

		return (ret == id) ? 0 : -EINVAL;
	}

	/* Idempotent: if the identity already holds the exact same address, no reset needed. */
	if (bt_addr_le_eq(&identities[id], &addr_copy)) {
		return 0;
	}

	ret = bt_id_reset(id, &addr_copy, NULL);
	return (ret < 0) ? ret : 0;
}

static bool sysbdaddr_adv_active(uint8_t id)
{
#ifdef CONFIG_AT_CMD_BLEADVENABLE
	const at_cmd_ctx_t *ctx = at_cmd_ctx_get();

	if (!ctx) {
		return false;
	}

	for (uint8_t i = 0; i < AT_CMD_ADV_MAX_INST; i++) {
		if (ctx->adv_enabled[i] && (ctx->adv_bt_id[i] == id)) {
			return true;
		}
	}
#else
	ARG_UNUSED(id);
#endif
	return false;
}

static void fn_cmd_handler(at_cmd_param_t *param)
{
	LOG_DBG("at_type (%d), err (%d)", param->type, param->err);

	if (param->err != AT_CMD_ERR_NO_ERROR) {
		return;
	}

	if (param->type == at_cmd_type_exec) {
		uint8_t id = AT_PASR_GET_PARAM(param, u8, 0);

		if ((id == BT_ID_DEFAULT) || (id >= CONFIG_BT_ID_MAX)) {
			LOG_ERR("Invalid BT identity id %u, must be in range [1, %u]", id,
				CONFIG_BT_ID_MAX - 1);
			AT_CMD_APP_ERR_TO_PARAM(AT_ERR_PARAM_INVALID, param);
			return;
		}

		if ((sysbdaddr_adv_active(id)) || (at_cmd_sys_bdaddr_conn_active())) {
			LOG_ERR("Cannot update BD address while advertising or connection is "
				"active");
			AT_CMD_ERRNO_TO_PARAM(-EBUSY, param);
			return;
		}
		uint8_t *addr_bytes = AT_PASR_GET_PARAM(param, array, 1);
		bt_addr_le_t set_addr;
		sys_memcpy_swap(set_addr.a.val, addr_bytes, BT_ADDR_SIZE);
		set_addr.type = BT_ADDR_LE_RANDOM;
		if (!bt_addr_le_is_identity(&set_addr)) {
			LOG_ERR("Address is not a valid identity address");
			AT_CMD_APP_ERR_TO_PARAM(AT_ERR_PARAM_INVALID, param);
			return;
		}

		int ret = at_cmd_sys_bdaddr_set(id, &set_addr);
		if (ret) {
			LOG_ERR("Failed to set BD address for id %u: %d", id, ret);
			AT_CMD_ERRNO_TO_PARAM(ret, param);
		}
	} else if (param->type == at_cmd_type_query) {
		bt_addr_le_t identities[CONFIG_BT_ID_MAX];
		size_t count = ARRAY_SIZE(identities);

		bt_id_get(identities, &count);
		if (!count) {
			LOG_ERR("No BT identities available");
			AT_CMD_APP_ERR_TO_PARAM(AT_ERR_SYS_NOT_READY, param);
			return;
		}

		for (uint8_t i = 0; i < (uint8_t)count; i++) {
			uint8_t addr_be[BT_ADDR_SIZE];

			sys_memcpy_swap(addr_be, identities[i].a.val, sizeof(addr_be));
			AT_CMD_RSP_REPEAT(param->ch, param->cmd, i, (uint8_t)count,
					  RSP_PARM_PAIR_NUM, i, addr_be, sizeof(addr_be));
		}
	}
}

AT_COMMAND(CMD_NAME, CMD_PARM_FMT, CMD_PARM_NUM, fn_cmd_handler, CMD_PARM_DESC, RSP_PARM_FMT,
	   RSP_PARM_NUM);
