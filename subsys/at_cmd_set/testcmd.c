/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include <zephyr/logging/log.h>
#include "arch.h"
#include "at_cmd.h"
#include "at_cmd_set.h"

#define CMD_NAME      "TESTCMD"
#define CMD_PARM_FMT  "B,B,S(0~4),A(4~4)"
#define CMD_PARM_NUM  4
#define CMD_PARM_DESC "<0x01: rsp all|0x02: rsp multi>,<test byte>,<test string>,<test array>"
#define RSP_PARM_FMT  "B,S,A(4~4)"
#define RSP_PARM_NUM  3

#define AT_CMD_TEST_MODE_RSP_ALL   0x01
#define AT_CMD_TEST_MODE_RSP_MULTI 0x02

static uint8_t at_cmd_test_mode = AT_CMD_TEST_MODE_RSP_ALL;
static uint8_t at_cmd_test_byte = 0x42;
static char at_cmd_test_string[5] = "TEST";
static uint8_t at_cmd_test_array[4] = {0xAA, 0xBB, 0xCC, 0xDD};
static uint16_t at_cmd_test_array_len = 4;

static void at_cmd_test_hdlr(at_cmd_param_t *param)
{
	if (param->err != AT_CMD_ERR_NO_ERROR) {
		return;
	}

	if (param->type == at_cmd_type_query) {
		// Query mode: Return test data based on current mode
		if (at_cmd_test_mode == AT_CMD_TEST_MODE_RSP_ALL) {
			// Mode 1: Send all parameters at once
			at_cmd_resp(param->ch, at_all, param->cmd, 0, 3, at_cmd_test_byte,
				    at_cmd_test_string, at_cmd_test_array, at_cmd_test_array_len);
		} else if (at_cmd_test_mode == AT_CMD_TEST_MODE_RSP_MULTI) {
			// Mode 2: Send parameters separately
			at_cmd_resp(param->ch, at_prefix | at_data, param->cmd, 0, 1,
				    at_cmd_test_byte);
			at_cmd_resp(param->ch, at_data, param->cmd, 1, 1, at_cmd_test_string);
			at_cmd_resp(param->ch, at_data | at_postfix, param->cmd, 2, 1,
				    at_cmd_test_array, at_cmd_test_array_len);
		}
	} else if (param->type == at_cmd_type_exec) {
		uint8_t mode = AT_PASR_GET_PARAM(param, u8, 0);
		uint8_t test_byte = AT_PASR_GET_PARAM(param, u8, 1);
		char const *test_str = AT_PASR_GET_PARAM(param, string, 2);
		uint8_t const *test_arr = AT_PASR_GET_PARAM(param, array, 3);
		uint16_t test_str_len = AT_PASR_GET_PARAM_LEN(param, 2);
		uint16_t test_arr_len = AT_PASR_GET_PARAM_LEN(param, 3);

		// Update test parameters
		at_cmd_test_mode = mode;
		at_cmd_test_byte = test_byte;

		if (test_str_len < sizeof(at_cmd_test_string)) {
			strncpy(at_cmd_test_string, test_str, sizeof(at_cmd_test_string) - 1);
			at_cmd_test_string[sizeof(at_cmd_test_string) - 1] = 0;
		}

		if (test_arr_len <= sizeof(at_cmd_test_array)) {
			memcpy(at_cmd_test_array, (void const *)test_arr, test_arr_len);
			at_cmd_test_array_len = test_arr_len;
		}
	}
}

AT_COMMAND(CMD_NAME, CMD_PARM_FMT, CMD_PARM_NUM, at_cmd_test_hdlr, CMD_PARM_DESC, RSP_PARM_FMT,
	   RSP_PARM_NUM);
