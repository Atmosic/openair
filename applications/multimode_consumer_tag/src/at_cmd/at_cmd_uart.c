/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include <errno.h>
#include <zephyr/device.h>
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
#ifdef CONFIG_AT_CMD_TAGADDR
#include <zephyr/bluetooth/bluetooth.h>
#ifdef CONFIG_FMNA_TAG
#include "fmna_api.h"
#endif
#ifdef CONFIG_FHN_TAG
#include "atm_gfp.h"
#endif
#ifdef CONFIG_STF_TAG
#include "TagSdk.h"
#endif
#endif /* CONFIG_AT_CMD_TAGADDR */

LOG_MODULE_DECLARE(at_cmd_uart, CONFIG_MULTIMODE_CONSUMER_TAG_LOG_LEVEL);

static const struct device *uart_dev = DEVICE_DT_GET(DT_NODELABEL(uart0));
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

#ifdef CONFIG_AT_CMD_TAGADDR
static at_cmd_tag_err_t multimode_tagaddr_cb(uint8_t protocol, bt_addr_le_t *addr)
{
	int err = -ENODEV;

	switch (protocol) {
#ifdef CONFIG_FMNA_TAG
	case AT_CMD_TAG_MODE_FMNA:
		err = fmna_get_adv_addr(addr);
		break;
#endif
#ifdef CONFIG_FHN_TAG
	case AT_CMD_TAG_MODE_FHN:
		err = atm_gfp_get_adv_addr(addr);
		break;
#endif
#ifdef CONFIG_STF_TAG
	case AT_CMD_TAG_MODE_STF: {
#ifdef CONFIG_ATM_STF_MULTI_MODE
		uint8_t bdaddr[BT_ADDR_SIZE];
		TagResult_t ret = TagGetAdvAddr(bdaddr);

		if (ret == TAG_RESULT_SUCCESS) {
			memcpy(addr->a.val, bdaddr, BT_ADDR_SIZE);
			err = 0;
		}
#endif /* CONFIG_ATM_STF_MULTI_MODE */
		break;
	}
#endif /* CONFIG_STF_TAG */
	default:
		break;
	}

	return err ? AT_CMD_TAG_ERR_INTERNAL : AT_CMD_TAG_NO_ERR;
}
#endif /* CONFIG_AT_CMD_TAGADDR */

#endif /* CONFIG_AT_CMD_TAG_SET */

int at_cmd_uart_multimode_tag_init(void)
{
	int err = at_cmd_set_uart_ch_init(uart_dev);

	if (err) {
		LOG_ERR("Failed to init AT command UART channel");
		return err;
	}

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
#ifdef CONFIG_AT_CMD_TAGADDR
		.tag_cb.addr_cb = multimode_tagaddr_cb,
#endif
	};

	at_cmd_set_callbacks_register(&callbacks);
#endif /* CONFIG_AT_CMD_TAG_SET */

	LOG_INF("AT command UART ready on %s", uart_dev->name);
	return 0;
}
