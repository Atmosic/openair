/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include <errno.h>
#include <string.h>
#include <zephyr/logging/log.h>
#include <zephyr/settings/settings.h>
#include "at_cmd.h"
#include "at_cmd_set_common.h"

#define CMD_NAME          "SYSSTORAGE"
#define CMD_PARM_FMT      "S(~4),S(~64),S(~128)"
#define CMD_PARM_OPT_GET  "GET"
#define CMD_PARM_OPT_SAVE "SAVE"
#define CMD_PARM_OPT_DEL  "DEL"
#define CMD_PARM_DESC     "<GET|SAVE|DEL>,<key>,<value>"
#define CMD_PARM_NUM      3
#define RSP_PARM_FMT      "S,S"
#define RSP_PARM_NUM      2

#define STORAGE_STATUS_READY     "READY"
#define STORAGE_STATUS_NOT_READY "NOT_READY"

#define STORAGE_KEY_MAX_LEN   64U
#define STORAGE_VALUE_MAX_LEN 128U

LOG_MODULE_REGISTER(sysstorage, CONFIG_AT_CMD_SET_LOG_LEVEL);

static bool at_cmd_sys_storage_ready(void)
{
	void *storage = NULL;

	if (settings_storage_get(&storage)) {
		return false;
	}

	return !!storage;
}

static int at_cmd_sys_storage_get(const char *key, char *value, size_t value_buf_len,
				  size_t *value_len)
{
	ssize_t len;

	if ((!key) || (!value) || (!value_len)) {
		return -EINVAL;
	}

	len = settings_get_val_len(key);
	if (len < 0) {
		return (int)len;
	}

	if (!len) {
		return -ENOENT;
	}

	if ((size_t)len > value_buf_len) {
		return -EOVERFLOW;
	}

	len = settings_load_one(key, value, value_buf_len);
	if (len < 0) {
		return (int)len;
	}

	*value_len = (size_t)len;

	return 0;
}

static int at_cmd_sys_storage_save(const char *key, const char *value, size_t value_len)
{
	if ((!key) || (!value) || (!value_len)) {
		return -EINVAL;
	}

	return settings_save_one(key, value, value_len);
}

static int at_cmd_sys_storage_del(const char *key)
{
	if (!key) {
		return -EINVAL;
	}

	return settings_delete(key);
}

static void fn_cmd_handler(at_cmd_param_t *param)
{
	LOG_DBG("at_type (%d), err (%d)", param->type, param->err);

	if (param->err != AT_CMD_ERR_NO_ERROR) {
		return;
	}

	if (param->type == at_cmd_type_query) {
		const char *status = at_cmd_sys_storage_ready() ? STORAGE_STATUS_READY
								: STORAGE_STATUS_NOT_READY;
		at_cmd_resp(param->ch, at_all, param->cmd, 0, 1, status);
		return;
	}

	if (param->type != at_cmd_type_exec) {
		return;
	}

	if (!at_cmd_sys_storage_ready()) {
		LOG_ERR("Storage backend is not ready");
		AT_CMD_APP_ERR_TO_PARAM(AT_ERR_SYS_NOT_READY, param);
		return;
	}

	uint8_t op_len = AT_PASR_GET_PARAM_LEN(param, 0);
	uint8_t key_len = AT_PASR_GET_PARAM_LEN(param, 1);
	uint8_t value_len = AT_PASR_GET_PARAM_LEN(param, 2);

	if ((!op_len) || (!key_len)) {
		LOG_ERR("Operation and key must not be empty");
		AT_CMD_APP_ERR_TO_PARAM(AT_ERR_PARAM_INVALID_LENGTH, param);
		return;
	}

	const uint8_t *op = AT_PASR_GET_PARAM(param, string, 0);
	const uint8_t *key_param = AT_PASR_GET_PARAM(param, string, 1);
	char key[STORAGE_KEY_MAX_LEN + 1U];
	memcpy(key, key_param, key_len);
	key[key_len] = '\0';

	int ret;

	if ((op_len == (sizeof(CMD_PARM_OPT_GET) - 1U)) &&
	    (!memcmp(op, CMD_PARM_OPT_GET, op_len))) {
		if (value_len) {
			LOG_ERR("GET command does not accept a value parameter");
			AT_CMD_APP_ERR_TO_PARAM(AT_ERR_PARAM_INVALID, param);
			return;
		}
		char value[STORAGE_VALUE_MAX_LEN + 1U];
		size_t stored_value_len = 0U;
		ret = at_cmd_sys_storage_get(key, value, STORAGE_VALUE_MAX_LEN, &stored_value_len);
		if (ret) {
			LOG_ERR("Failed to get storage key \"%s\": %d", key, ret);
			AT_CMD_ERRNO_TO_PARAM(ret, param);
			return;
		}
		value[stored_value_len] = '\0';
		at_cmd_resp(param->ch, at_all, param->cmd, 0, RSP_PARM_NUM, key, value);
		return;
	} else if ((op_len == (sizeof(CMD_PARM_OPT_SAVE) - 1U)) &&
		   (!memcmp(op, CMD_PARM_OPT_SAVE, op_len))) {
		if (!value_len) {
			LOG_ERR("SAVE command requires a non-empty value");
			AT_CMD_APP_ERR_TO_PARAM(AT_ERR_PARAM_INVALID_LENGTH, param);
			return;
		}

		ret = at_cmd_sys_storage_save(
			key, (const char *)AT_PASR_GET_PARAM(param, string, 2), value_len);
		if (ret) {
			LOG_ERR("Failed to save storage key \"%s\": %d", key, ret);
			AT_CMD_ERRNO_TO_PARAM(ret, param);
			return;
		}
	} else if ((op_len == (sizeof(CMD_PARM_OPT_DEL) - 1U)) &&
		   (!memcmp(op, CMD_PARM_OPT_DEL, op_len))) {
		if (value_len) {
			LOG_ERR("DEL command does not accept a value parameter");
			AT_CMD_APP_ERR_TO_PARAM(AT_ERR_PARAM_INVALID, param);
			return;
		}

		ret = at_cmd_sys_storage_del(key);
		if (ret) {
			LOG_ERR("Failed to delete storage key \"%s\": %d", key, ret);
			AT_CMD_ERRNO_TO_PARAM(ret, param);
			return;
		}
	} else {
		LOG_ERR("Unknown operation \"%.*s\", allowed: GET|SAVE|DEL", op_len, op);
		AT_CMD_APP_ERR_TO_PARAM(AT_ERR_PARAM_INVALID, param);
		return;
	}
}

AT_COMMAND(CMD_NAME, CMD_PARM_FMT, CMD_PARM_NUM, fn_cmd_handler, CMD_PARM_DESC, RSP_PARM_FMT,
	   RSP_PARM_NUM);
