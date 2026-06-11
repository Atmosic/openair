/**
 *******************************************************************************
 *
 * @file at_cmd_uart.c
 *
 * @brief AT command UART module
 *
 * Copyright (C) Atmosic 2026
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 *
 *******************************************************************************
 */

#include <ctype.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <zephyr/bluetooth/bluetooth.h>
#include <zephyr/device.h>
#include <zephyr/drivers/uart.h>
#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
#include <zephyr/logging/log_ctrl.h>
#include "app_version.h"

#include <zephyr/sys/reboot.h>

#include "at_cmd.h"
#include "at_cmd_set.h"
#include "at_cmd_uart.h"
#include "platform.h"
#include "platform_common.h"
#include "platform_ctrl_battery.h"
#ifdef CONFIG_STF_TAG
#include "TagBtnCallback.h"
#endif
#ifdef CONFIG_AT_CMD_SYSDFU
#include "at_cmd_sysdfu_proc.h"
#endif

#ifdef CONFIG_AT_CMD_TAGGFPIND
#include "atm_gfp.h"
#endif
#ifdef CONFIG_AT_CMD_TAGMOTIONRPT
#include "platform_ctrl_motion_detect.h"
#endif
#if defined(CONFIG_AT_CMD_TAGFMNASN) || defined(CONFIG_AT_CMD_TAGFMNAMFI)
#include "fmna_api.h"
#endif
#ifdef CONFIG_AT_CMD_TAGCSUNPAIR
#include "atm_cs.h"
#endif

LOG_MODULE_REGISTER(at_cmd_uart, CONFIG_AT_CMD_UART_LOG_LEVEL);

#define AT_CMD_HDR              "AT+"
#define AT_CMD_HDR_LEN          (sizeof(AT_CMD_HDR) - 1)
#define AT_CMD_UART_RX_BUF_SIZE 256

static const struct device *uart_dev = DEVICE_DT_GET(DT_NODELABEL(uart0));
static char cmd_buf[AT_CMD_UART_RX_BUF_SIZE];
static uint16_t cmd_buf_idx;
static bool cmd_has_params;

static char proc_buf[AT_CMD_UART_RX_BUF_SIZE];
static uint16_t proc_buf_len;

static at_cmd_ch_t uart_ch = AT_CMD_INVALID_CH;
static struct k_work at_cmd_work;
#ifdef CONFIG_AT_CMD_TAG_SET

#ifdef CONFIG_AT_CMD_TAGRESET
static at_cmd_tag_reset_reason_t pending_tagreset_reason = AT_CMD_TAG_RESET_REASON_COLD_REBOOT;

static void tag_reset_work_handler(struct k_work *work);
static K_WORK_DEFINE(tag_reset_work, tag_reset_work_handler);
#endif /* CONFIG_AT_CMD_TAGRESET */

#ifdef CONFIG_AT_CMD_TAGSTART
static void tag_start_work_handler(struct k_work *work);
static K_WORK_DEFINE(tag_start_work, tag_start_work_handler);
#endif /* CONFIG_AT_CMD_TAGSTART */

#ifdef CONFIG_AT_CMD_TAGFMNASN
static at_cmd_tag_err_t multimode_fmna_sn_lookup_cb(void)
{
	uint8_t mode;
	if (!platform_tag_mode_get(&mode) && !(mode & platform_tag_type_to_mode(TAG_TYPE_FMNA))) {
		return AT_CMD_TAG_ERR_NOT_ALLOWED;
	}
	fmna_sn_lookup_enable();
	return AT_CMD_TAG_NO_ERR;
}
#endif /* CONFIG_AT_CMD_TAGFMNASN */

#ifdef CONFIG_AT_CMD_TAGFMNAMFI
extern void fmna_log_mfi_token(void);
static at_cmd_tag_err_t multimode_fmna_mfi_log_cb(void)
{
	uint8_t mode;
	if (!platform_tag_mode_get(&mode) && !(mode & platform_tag_type_to_mode(TAG_TYPE_FMNA))) {
		return AT_CMD_TAG_ERR_NOT_ALLOWED;
	}
	fmna_log_mfi_token();
	return AT_CMD_TAG_NO_ERR;
}
#endif

#ifdef CONFIG_AT_CMD_TAGCSUNPAIR
static at_cmd_tag_err_t multimode_cs_unpair_cb(void)
{
	atm_cs_rrsp_unpair();
	return AT_CMD_TAG_NO_ERR;
}
#endif

#ifdef CONFIG_AT_CMD_TAGGFPIND
static at_cmd_tag_err_t multimode_gfp_ind_cb(at_cmd_tag_gfp_ind_action_t action)
{
	uint8_t mode;
	LOG_INF("GFP button indication: action=%u", action);
	if (!platform_tag_mode_get(&mode) && !(mode & platform_tag_type_to_mode(TAG_TYPE_FP))) {
		return AT_CMD_TAG_ERR_NOT_ALLOWED;
	}
	if (action == AT_CMD_TAG_GFP_IND_SINGLE_PRESS) {
		atm_gfp_button_notify();
		return AT_CMD_TAG_NO_ERR;
	}
#ifdef CONFIG_FMDN_REVERSE_RINGING
	if (action == AT_CMD_TAG_GFP_IND_DOUBLE_PRESS) {
		atm_gfp_button_double_notify();
		return AT_CMD_TAG_NO_ERR;
	}
#endif
	return AT_CMD_TAG_ERR_INVALID_PARAM;
}
#endif

#ifdef CONFIG_AT_CMD_TAGINFO
static const char *tag_fw_version_get(void)
{
	return APP_VERSION_STRING;
}

static at_cmd_tag_err_t multimode_taginfo_cb(at_cmd_tag_info_t *info)
{
	uint8_t active_mode;

	if (!info) {
		return AT_CMD_TAG_ERR_INVALID_PARAM;
	}

	snprintf(info->version, info->version_len, "%s", tag_fw_version_get());

	/* Get supported protocols from platform */
	if (platform_tag_mode_get(&active_mode)) {
		return AT_CMD_TAG_ERR_INTERNAL;
	}

	info->protocol_mask = active_mode;
	return AT_CMD_TAG_NO_ERR;
}
#endif /* CONFIG_AT_CMD_TAGINFO */

#ifdef CONFIG_AT_CMD_TAGMODE
static at_cmd_tag_err_t multimode_tagmode_cb(at_cmd_tag_mode_op_t op, uint8_t *mode)
{
	int err;

	if (!mode) {
		return AT_CMD_TAG_ERR_INVALID_PARAM;
	}

	if (op == AT_CMD_TAG_MODE_OP_GET) {
		return (platform_tag_mode_get(mode) == 0) ? AT_CMD_TAG_NO_ERR
							  : AT_CMD_TAG_ERR_INTERNAL;
	}

	err = platform_tag_mode_set(*mode);

	if (!err) {
		return AT_CMD_TAG_NO_ERR;
	}
	if (err == -EPERM) {
		return AT_CMD_TAG_ERR_NOT_ALLOWED;
	}
	return AT_CMD_TAG_ERR_INTERNAL;
}
#endif /* CONFIG_AT_CMD_TAGMODE */

#ifdef CONFIG_AT_CMD_TAGSTART
static void tag_start_work_handler(struct k_work *work)
{
	ARG_UNUSED(work);
	LOG_INF("AT command tag start");
	platform_tag_start();
}

static at_cmd_tag_err_t multimode_tagstart_cb(void)
{
	uint8_t state;

	/* If already running, return OK (idempotent) */
	if (!platform_tag_state_get(&state) && state) {
		return AT_CMD_TAG_NO_ERR;
	}

	k_work_submit(&tag_start_work);
	return AT_CMD_TAG_NO_ERR;
}
#endif /* CONFIG_AT_CMD_TAGSTART */

#ifdef CONFIG_AT_CMD_TAGRESET
static void tag_reset_work_handler(struct k_work *work)
{
	ARG_UNUSED(work);

	if (pending_tagreset_reason == AT_CMD_TAG_RESET_REASON_FACTORY_RESET) {
		LOG_INF("AT command tag factory reset requested");
		platform_factory_reset();
	} else {
		LOG_INF("AT command cold reboot requested");
	}

	LOG_PANIC();
	sys_reboot(SYS_REBOOT_COLD);
}

static at_cmd_tag_err_t multimode_tagreset_cb(at_cmd_tag_reset_reason_t reason)
{
	pending_tagreset_reason = reason;
	/* Defer reset until AT response has been sent. */
	k_work_submit(&tag_reset_work);
	return AT_CMD_TAG_NO_ERR;
}
#endif /* CONFIG_AT_CMD_TAGRESET */

#ifdef CONFIG_AT_CMD_TAGBATTERY
static at_cmd_tag_err_t multimode_tagbattery_cb(uint8_t *percentage)
{
	*percentage = platform_ctrl_batt_status_get();
	return AT_CMD_TAG_NO_ERR;
}
#endif /* CONFIG_AT_CMD_TAGBATTERY */

#ifdef CONFIG_AT_CMD_TAGSTFIND
#define STF_CONFIRM_PARING 1

static at_cmd_tag_err_t multimode_tagstfind_cb(uint8_t times)
{
	uint8_t mode;
	LOG_INF("STF button indication: times=%u", times);
	if (!platform_tag_mode_get(&mode) && !(mode & platform_tag_type_to_mode(TAG_TYPE_STF))) {
		return AT_CMD_TAG_ERR_NOT_ALLOWED;
	}
	/* times=1: single press to confirm STF pairing (OOB onboarding) */
	if (times == STF_CONFIRM_PARING) {
		SystemButtonEventCallback(EVENT_BUTTON_PUSHED);
		return AT_CMD_TAG_NO_ERR;
	}
	return AT_CMD_TAG_ERR_INVALID_PARAM;
}
#endif /* CONFIG_AT_CMD_TAGSTFIND */

#ifdef CONFIG_AT_CMD_TAGMOTIONRPT
static at_cmd_tag_err_t multimode_tagmotionrpt_cb(int16_t x_cs2, int16_t y_cs2, int16_t z_cs2)
{
	platform_ctrl_motion_detect_inject(x_cs2, y_cs2, z_cs2);
	return AT_CMD_TAG_NO_ERR;
}
#endif /* CONFIG_AT_CMD_TAGMOTIONRPT */

#endif /* CONFIG_AT_CMD_TAG_SET */

static void reset_cmd_buf(void)
{
	cmd_buf_idx = 0;
	cmd_has_params = false;
	memset(cmd_buf, 0, sizeof(cmd_buf));
}

static void at_cmd_work_handler(struct k_work *work)
{
	ARG_UNUSED(work);

	if (proc_buf_len) {
		LOG_INF("AT proc: %s", proc_buf);
		at_cmd_proc(uart_ch, proc_buf, proc_buf_len);
		proc_buf_len = 0;
	}
}

static void uart_resp_cb(at_cmd_ch_t ch, void const *data, uint16_t len)
{
	ARG_UNUSED(ch);

	if (!uart_dev || !device_is_ready(uart_dev)) {
		return;
	}

	const uint8_t *buf = data;
	for (uint16_t i = 0; i < len; i++) {
		uart_poll_out(uart_dev, buf[i]);
	}
}

static void uart_rx_byte(uint8_t byte)
{
#ifdef CONFIG_AT_CMD_SYSDFU
	if (at_cmd_sysdfu_is_active()) {
		at_cmd_sysdfu_feed_byte(byte);
		return;
	}
#endif
	char ch = (char)byte;

	if (cmd_buf_idx < AT_CMD_HDR_LEN) {
		if (toupper((unsigned char)ch) != AT_CMD_HDR[cmd_buf_idx]) {
			reset_cmd_buf();
		} else {
			cmd_buf[cmd_buf_idx] = AT_CMD_HDR[cmd_buf_idx];
			cmd_buf_idx++;
		}
		return;
	}

	if (ch == '\r' || ch == '\n') {
		if (cmd_buf_idx > AT_CMD_HDR_LEN) {
			cmd_buf[cmd_buf_idx] = '\0';
			memcpy(proc_buf, cmd_buf, cmd_buf_idx + 1);
			proc_buf_len = cmd_buf_idx;
			k_work_submit(&at_cmd_work);
		}
		reset_cmd_buf();
		return;
	}

	if (cmd_buf_idx >= (AT_CMD_UART_RX_BUF_SIZE - 1)) {
		reset_cmd_buf();
		return;
	}

	if (ch == '=') {
		cmd_has_params = true;
	}

	if (!cmd_has_params) {
		ch = (char)toupper((unsigned char)ch);
	}

	cmd_buf[cmd_buf_idx++] = ch;
}

static void uart_isr_cb(const struct device *dev, void *user_data)
{
	ARG_UNUSED(user_data);

	if (!uart_irq_update(dev)) {
		return;
	}

	while (uart_irq_rx_ready(dev)) {
		uint8_t byte;

		if (uart_fifo_read(dev, &byte, 1) == 1) {
			uart_rx_byte(byte);
		}
	}
}

at_cmd_ch_t at_cmd_uart_ch_get(void)
{
	return uart_ch;
}

int at_cmd_uart_multimode_tag_init(void)
{
	at_cmd_alloc_ctx_t at_ctx = {
		.xfer = AT_CMD_DFT_XFER_UART,
		.resp = uart_resp_cb,
	};
#ifdef CONFIG_AT_CMD_TAG_SET
	at_cmd_set_callbacks_t callbacks = {
#ifdef CONFIG_AT_CMD_TAGINFO
		.tag_cb.get_info_cb = multimode_taginfo_cb,
#endif
#ifdef CONFIG_AT_CMD_TAGMODE
		.tag_cb.mode_cb = multimode_tagmode_cb,
#endif
#ifdef CONFIG_AT_CMD_TAGSTART
		.tag_cb.start_cb = multimode_tagstart_cb,
#endif
#ifdef CONFIG_AT_CMD_TAGBATTERY
		.tag_cb.get_battery_cb = multimode_tagbattery_cb,
#endif
#ifdef CONFIG_AT_CMD_TAGRESET
		.tag_cb.reset_cb = multimode_tagreset_cb,
#endif
#ifdef CONFIG_AT_CMD_TAGSTFIND
		.tag_cb.stfind_cb = multimode_tagstfind_cb,
#endif
#ifdef CONFIG_AT_CMD_TAGFMNASN
		.tag_cb.fmna_sn_lookup_cb = multimode_fmna_sn_lookup_cb,
#endif
#ifdef CONFIG_AT_CMD_TAGFMNAMFI
		.tag_cb.fmna_mfi_log_cb = multimode_fmna_mfi_log_cb,
#endif
#ifdef CONFIG_AT_CMD_TAGCSUNPAIR
		.tag_cb.cs_unpair_cb = multimode_cs_unpair_cb,
#endif
#ifdef CONFIG_AT_CMD_TAGGFPIND
		.tag_cb.gfp_ind_cb = multimode_gfp_ind_cb,
#endif
#ifdef CONFIG_AT_CMD_TAGMOTIONRPT
		.tag_cb.motionrpt_cb = multimode_tagmotionrpt_cb,
#endif
	};
#endif

	at_cmd_ctx_init();

	if (!device_is_ready(uart_dev)) {
		LOG_ERR("AT command UART device not ready");
		return -ENODEV;
	}

	uart_ch = at_cmd_alloc(&at_ctx);
	if (uart_ch == AT_CMD_INVALID_CH) {
		LOG_ERR("Failed to allocate AT command channel");
		return -ENOMEM;
	}

	at_cmd_set_channel(uart_ch);
#ifdef CONFIG_AT_CMD_TAG_SET
	at_cmd_set_callbacks_register(&callbacks);
#endif
	k_work_init(&at_cmd_work, at_cmd_work_handler);
	reset_cmd_buf();
	proc_buf_len = 0;

	uart_irq_callback_set(uart_dev, uart_isr_cb);
	uart_irq_rx_enable(uart_dev);

	LOG_INF("AT command UART ready on %s", uart_dev->name);
	return 0;
}
