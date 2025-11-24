/*
 * Copyright (C) Atmosic 2025
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>
#include <zephyr/devicetree.h>
#include <zephyr/shell/shell.h>
#include <zephyr/shell/shell_dummy.h>
#include <zephyr/ztest.h>
#include <stdio.h>
#include <string.h>

ZTEST(atm_shell, test_atm_shell_crc)
{
	const struct shell *sh = shell_backend_dummy_get_ptr();

	if (!sh) {
		printk("Dummy shell not found!\n");
		return;
	}

	// Wait a bit to let shell backend initialize
	k_sleep(K_MSEC(100));

	shell_start(sh);  // Start after delay

	/* Get flash controller name from device tree (without leading separator) */
	const char *flash_ctrl_name = DT_NODE_FULL_NAME(DT_NODELABEL(flash_controller));

	/* Build the command string dynamically */
	char cmd[128];
	int retv =
		snprintf(cmd, sizeof(cmd), "atm_flash check_crc %s 0x1f8000 20", flash_ctrl_name);
	zassert_true(retv > 0, "cmd is assembled");

	printk("flash controller: %s, cmd to execute: %s\n", flash_ctrl_name, cmd);
	int ret = shell_execute_cmd(sh, cmd);
	printk("Command executed with return: %d\n", ret);

	k_sleep(K_MSEC(100)); // Allow time for output

	size_t out_len;
	const char *out = shell_backend_dummy_get_output(sh, &out_len);
	printk("Shell output (%zu bytes):\n%.*s\n", out_len, (int)out_len, out);
	// Check if "crc_result" appears in output
	const char *keyword = "crc_result";
	zassert_not_null(strstr(out, keyword), "\"%s\" not found in shell output", keyword);
	printk("atm shell test! %s\n\x04\n", CONFIG_BOARD_TARGET);
}

ZTEST_SUITE(atm_shell, NULL, NULL, NULL, NULL, NULL);
