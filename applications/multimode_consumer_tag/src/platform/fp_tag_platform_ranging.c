/*
 * Copyright (c) 2025-2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#include <zephyr/logging/log.h>
#include <errno.h>
#include "fp_tag_platform_ranging.h"
#include "ranging_oob_de.h"
#ifdef CONFIG_AT_CMD_TAG_SET
#include "at_cmd_uart.h"
#include "at_cmd_event.h"
#include "at_cmd_tag.h"
#endif

LOG_MODULE_DECLARE(multimode_consumer_tag, CONFIG_MULTIMODE_CONSUMER_TAG_LOG_LEVEL);

#ifdef CONFIG_AT_CMD_TAGRANGING
static uint8_t ranging_enabled_mask;

#ifdef CONFIG_AT_CMD_TAGRANGINGCAPUWB
static bool ranging_uwb_cap_valid = true;
static at_cmd_tag_ranging_cap_uwb_t ranging_uwb_cap = {
	.addr = {0xE2, 0xF6},
	.channel_mask = CONFIG_FMDN_RANGING_UWB_CHANNEL_MASK,
	.preamble_mask = CONFIG_FMDN_RANGING_UWB_PREAMBLE_MASK,
	.config_id_mask = CONFIG_FMDN_RANGING_UWB_CONFIG_ID_MASK,
	.min_ranging_int = CONFIG_FMDN_RANGING_UWB_MIN_RANGING_INT,
	.min_slot_dur = CONFIG_FMDN_RANGING_UWB_MIN_SLOT_DUR,
	.device_role = CONFIG_FMDN_RANGING_UWB_DEVICE_ROLE,
};
#endif

#ifdef CONFIG_AT_CMD_TAGRANGINGCAPCS
static bool ranging_cs_cap_valid = true;
static at_cmd_tag_ranging_cap_cs_t ranging_cs_cap = {
	.sec_type = CONFIG_FMDN_RANGING_CS_SECURITY_LEVEL,
};
#endif

static uint8_t ranging_supported_mask(void)
{
	uint8_t mask = 0;

#ifdef CONFIG_AT_CMD_TAGRANGINGCAPUWB
	mask |= AT_CMD_TAG_RANGING_TECH_MASK_UWB;
#endif
#ifdef CONFIG_AT_CMD_TAGRANGINGCAPCS
	mask |= AT_CMD_TAG_RANGING_TECH_MASK_CS;
#endif
	return mask;
}

static uint8_t ranging_cap_valid_mask(void)
{
	uint8_t mask = 0;

#ifdef CONFIG_AT_CMD_TAGRANGINGCAPUWB
	if (ranging_uwb_cap_valid) {
		mask |= AT_CMD_TAG_RANGING_TECH_MASK_UWB;
	}
#endif
#ifdef CONFIG_AT_CMD_TAGRANGINGCAPCS
	if (ranging_cs_cap_valid) {
		mask |= AT_CMD_TAG_RANGING_TECH_MASK_CS;
	}
#endif
	return mask;
}

bool fp_platform_ranging_is_enabled_cb(rt_id_t tech_id)
{
	return ranging_enabled_mask & BIT(tech_id);
}

#ifdef CONFIG_AT_CMD_TAGRANGINGCAPUWB
at_cmd_tag_err_t fp_platform_ranging_capability_uwb_cb(at_cmd_tag_op_t op,
						       at_cmd_tag_ranging_cap_uwb_t *capability)
{
	if (!capability) {
		return AT_CMD_TAG_ERR_INVALID_PARAM;
	}

	if (op == AT_CMD_TAG_OP_GET) {
		if (!ranging_uwb_cap_valid) {
			return AT_CMD_TAG_ERR_NOT_ALLOWED;
		}
		*capability = ranging_uwb_cap;
	} else if (op == AT_CMD_TAG_OP_SET) {
		ranging_uwb_cap = *capability;
		ranging_uwb_cap_valid = true;
	} else {
		return AT_CMD_TAG_ERR_INVALID_PARAM;
	}
	return AT_CMD_TAG_NO_ERR;
}
#endif

#ifdef CONFIG_AT_CMD_TAGRANGINGCAPCS
at_cmd_tag_err_t fp_platform_ranging_capability_cs_cb(at_cmd_tag_op_t op,
						      at_cmd_tag_ranging_cap_cs_t *capability)
{
	if (!capability) {
		return AT_CMD_TAG_ERR_INVALID_PARAM;
	}

	if (op == AT_CMD_TAG_OP_GET) {
		if (!ranging_cs_cap_valid) {
			return AT_CMD_TAG_ERR_NOT_ALLOWED;
		}
		*capability = ranging_cs_cap;
	} else if (op == AT_CMD_TAG_OP_SET) {
		ranging_cs_cap = *capability;
		ranging_cs_cap_valid = true;
	} else {
		return AT_CMD_TAG_ERR_INVALID_PARAM;
	}
	return AT_CMD_TAG_NO_ERR;
}
#endif

at_cmd_tag_err_t fp_platform_ranging_gate_cb(at_cmd_tag_op_t op,
					     at_cmd_tag_ranging_gate_action_t action,
					     uint8_t *tech_mask)
{
	if (!tech_mask) {
		return AT_CMD_TAG_ERR_INVALID_PARAM;
	}
	if (op == AT_CMD_TAG_OP_GET) {
		*tech_mask = ranging_enabled_mask;
		return AT_CMD_TAG_NO_ERR;
	}
	if (op != AT_CMD_TAG_OP_SET) {
		return AT_CMD_TAG_ERR_INVALID_PARAM;
	}

	uint8_t targets = 0;
	uint8_t supported_mask = ranging_supported_mask();
	if (*tech_mask == AT_CMD_TAG_RANGING_TECH_MASK_ALL) {
		targets = supported_mask;
	} else if (*tech_mask == 0 || (*tech_mask & ~supported_mask)) {
		return AT_CMD_TAG_ERR_INVALID_PARAM;
	} else {
		targets = *tech_mask;
	}

	if (action == AT_CMD_TAG_RANGING_GATE_ON) {
		if ((targets & ranging_cap_valid_mask()) != targets) {
			return AT_CMD_TAG_ERR_NOT_ALLOWED;
		}
		ranging_enabled_mask |= targets;
	} else if (action == AT_CMD_TAG_RANGING_GATE_OFF) {
		ranging_enabled_mask &= (uint8_t)~targets;
	} else {
		return AT_CMD_TAG_ERR_INVALID_PARAM;
	}
	return AT_CMD_TAG_NO_ERR;
}
#endif /* CONFIG_AT_CMD_TAGRANGING */

/* ========================================================================
 * Public platform ranging interface
 * ======================================================================== */

int fp_platform_ranging_capability_cb(rt_id_t tech_id, ranging_capability_t *capability)
{
	LOG_INF("Platform: Capability request for technology ID 0x%02x", tech_id);

	switch (tech_id) {
#ifdef CONFIG_FMDN_RANGING_OOB_DE_TYPE_UWB_EN
	case RT_TECH_ID_UWB: {
#ifdef CONFIG_AT_CMD_TAGRANGINGCAPUWB
		if (!capability->uwb) {
			return -EINVAL;
		}
		at_cmd_tag_ranging_cap_uwb_t host_cap = ranging_uwb_cap;
		ranging_cap_de_uwb_t *uwb = capability->uwb;
		*uwb = (ranging_cap_de_uwb_t){
			.id = RT_TECH_ID_UWB,
			.size = sizeof(ranging_cap_de_uwb_t),
			.addr = {host_cap.addr[0], host_cap.addr[1]},
			.channel_mask = host_cap.channel_mask,
			.preamble_mask = host_cap.preamble_mask,
			.config_id_mask = host_cap.config_id_mask,
			.min_ranging_int = host_cap.min_ranging_int,
			.min_slot_dur = host_cap.min_slot_dur,
			.device_role = host_cap.device_role,
		};
#ifdef CONFIG_AT_EVT_TAGRANGINGCAP
		at_cmd_evt_tag_ranging_cap(at_cmd_set_uart_ch_get(), tech_id);
#endif
		return 0;
#else
		/* NOTE: In actual testing with FHN app, the size field behavior differs from spec.
		 * Using full struct size works correctly. */
		ranging_cap_de_uwb_t *uwb = capability->uwb;

		/* UWB Capability Parameters
		 *
		 * These values define the device's UWB ranging capabilities and should be
		 * updated by the actual hardware implementation to match the device's
		 * supported UWB features. The parameters are configured via Kconfig options
		 * in openair/subsys/bluetooth/services/gfp/fmdn/Kconfig.fhpf_uwb
		 *
		 * - addr: Device UWB address (2 bytes) - platform-specific
		 * - channel_mask: Supported UWB channels
		 * - preamble_mask: Supported preamble indices (1-32)
		 * - config_id_mask: Supported configuration IDs
		 * - min_ranging_int: Minimum ranging interval (ms)
		 * - min_slot_dur: Minimum slot duration
		 * - device_role: Device role bitmap (e.g., 0x01 = Reflector only)
		 */
		*uwb = (ranging_cap_de_uwb_t){
			.id = RT_TECH_ID_UWB,
			.size = sizeof(ranging_cap_de_uwb_t),
			.addr = {0xE2, 0xF6},
			.channel_mask = CONFIG_FMDN_RANGING_UWB_CHANNEL_MASK,
			.preamble_mask = CONFIG_FMDN_RANGING_UWB_PREAMBLE_MASK,
			.config_id_mask = CONFIG_FMDN_RANGING_UWB_CONFIG_ID_MASK,
			.min_ranging_int = CONFIG_FMDN_RANGING_UWB_MIN_RANGING_INT,
			.min_slot_dur = CONFIG_FMDN_RANGING_UWB_MIN_SLOT_DUR,
			.device_role = CONFIG_FMDN_RANGING_UWB_DEVICE_ROLE,
		};

		LOG_INF("Constructed UWB capabilities: addr=0x%04x, role=0x%02x",
			(uwb->addr[1] << 8) | uwb->addr[0], uwb->device_role);
		return 0;
#endif /* CONFIG_AT_CMD_TAGRANGINGCAPUWB */
	}
#endif /* CONFIG_FMDN_RANGING_OOB_DE_TYPE_UWB_EN */
#ifdef CONFIG_FMDN_RANGING_OOB_DE_TYPE_BLE_CS_EN
	case RT_TECH_ID_CS: {
#ifdef CONFIG_AT_CMD_TAGRANGINGCAPCS
		if (!capability->cs) {
			return -EINVAL;
		}
		ranging_cap_de_cs_t *cs = capability->cs;
		*cs = (ranging_cap_de_cs_t){
			.id = RT_TECH_ID_CS,
			.size = sizeof(ranging_cap_de_cs_t),
			.sec_type = ranging_cs_cap.sec_type,
			.addr = {0},
		};
#ifdef CONFIG_AT_EVT_TAGRANGINGCAP
		at_cmd_evt_tag_ranging_cap(at_cmd_set_uart_ch_get(), tech_id);
#endif
		return 0;
#else
		ranging_cap_de_cs_t *cs = capability->cs;
		*cs = (ranging_cap_de_cs_t){
			.id = RT_TECH_ID_CS,
			.size = sizeof(ranging_cap_de_cs_t),
			.sec_type = CONFIG_FMDN_RANGING_CS_SECURITY_LEVEL,
			.addr = {0},
		};
		LOG_INF("Constructed CS capabilities");
		return 0;
#endif /* CONFIG_AT_CMD_TAGRANGINGCAPCS */
	}
#endif /* CONFIG_FMDN_RANGING_OOB_DE_TYPE_BLE_CS_EN */
	default:
		LOG_WRN("Platform: Unsupported technology ID 0x%02x", tech_id);
		return -ENOTSUP;
	}
}

int fp_platform_ranging_config_cb(rt_id_t tech_id, ranging_config_t *config, bool start_immediately)
{
	LOG_INF("Platform: Configuration request for technology ID 0x%02x", tech_id);

	switch (tech_id) {
#ifdef CONFIG_FMDN_RANGING_OOB_DE_TYPE_UWB_EN
	case RT_TECH_ID_UWB: {
		LOG_INF("Platform: UWB config received");
		ranging_conf_de_uwb_t *uwb = config->uwb;
		LOG_DBG("Platform: UWB config: session_key_len=0x%02x, config_id=0x%02x, "
			"channel=0x%02x, role=0x%02x, mode=0x%02x",
			uwb->session_key_len, uwb->config_id, uwb->channel, uwb->device_role,
			uwb->device_mode);

		/* UWB configuration received.
		 *
		 * In this reference implementation, we simply acknowledge the configuration.
		 * Customers can implement actual UWB hardware configuration here if needed
		 * based on the received parameters.
		 */
#ifdef CONFIG_AT_EVT_TAGRANGINGCFGUWB
		at_cmd_evt_tag_ranging_cfg_uwb(at_cmd_set_uart_ch_get(), uwb->session_key_len,
					       uwb->config_id, uwb->channel, uwb->device_role,
					       uwb->device_mode, start_immediately);
#else
		if (start_immediately) {
			LOG_INF("Platform: UWB auto-start requested");
		}
#endif
		return 0;
	}
#endif
#ifdef CONFIG_FMDN_RANGING_OOB_DE_TYPE_BLE_CS_EN
	case RT_TECH_ID_CS: {
		LOG_INF("Platform: CS config received");
		ranging_conf_de_cs_t *cs = config->cs;
		/* BLE Channel Sounding configuration received.
		 *
		 * Per spec: Responder doesn't need to do anything - only initiator calls BLE stack.
		 * Optionally use messages as trigger for visual feedback (e.g., blink LEDs, update
		 * UI).
		 */
		LOG_DBG("Platform: CS config acknowledged");
		(void)cs; /* Suppress unused variable warning */
#ifdef CONFIG_AT_EVT_TAGRANGINGCFGCS
		uint8_t sec_type = 0xFF;
#ifdef CONFIG_RANGING_OOB_DE_TYPE_BLE_CS_CONFIG_SEC_TYPE
		sec_type = cs->sec_type;
#endif
		at_cmd_evt_tag_ranging_cfg_cs(at_cmd_set_uart_ch_get(), sec_type,
					      start_immediately);
#endif /* CONFIG_AT_EVT_TAGRANGINGCFGCS */
		return 0;
	}
#endif /* CONFIG_FMDN_RANGING_OOB_DE_TYPE_BLE_CS_EN */
	default:
		LOG_ERR("Platform: Unsupported technology ID 0x%02x for configuration", tech_id);
#ifdef CONFIG_AT_CMD_TAG_SET
		at_cmd_evt_tag_error(at_cmd_set_uart_ch_get(), AT_CMD_TAG_MODE_FHN,
				     AT_CMD_TAG_ERR_INVALID_PARAM);
#endif
		return -ENOTSUP;
	}
}

/* Deprecated: retained for legacy Start Ranging DE compatibility. */
int fp_platform_ranging_start_cb(rt_id_t tech_id)
{
	LOG_INF("Platform: Start ranging request for technology ID 0x%02x", tech_id);

	switch (tech_id) {
#ifdef CONFIG_FMDN_RANGING_OOB_DE_TYPE_UWB_EN
	case RT_TECH_ID_UWB: {
		/* UWB ranging start requested.
		 *
		 * In this reference implementation, we simply acknowledge the start request.
		 * Customers can implement actual UWB hardware start logic here if needed.
		 */
		LOG_INF("Platform: UWB ranging start acknowledged");
		return 0;
	}
#endif
#ifdef CONFIG_FMDN_RANGING_OOB_DE_TYPE_BLE_CS_EN
	case RT_TECH_ID_CS: {
		/* BLE Channel Sounding configuration received.
		 *
		 * Per spec: Responder doesn't need to do anything - only initiator calls BLE stack.
		 * Optionally use messages as trigger for visual feedback (e.g., blink LEDs, update
		 * UI).
		 */
		LOG_INF("Platform: CS ranging start acknowledged");
		return 0;
	}
#endif
	default:
		LOG_ERR("Platform: Unsupported technology ID 0x%02x for start", tech_id);
#ifdef CONFIG_AT_CMD_TAG_SET
		at_cmd_evt_tag_error(at_cmd_set_uart_ch_get(), AT_CMD_TAG_MODE_FHN,
				     AT_CMD_TAG_ERR_INVALID_PARAM);
#endif
		return -ENOTSUP;
	}
}

int fp_platform_ranging_stop_cb(rt_id_t tech_id)
{
	LOG_INF("Platform: Stop ranging request for technology ID 0x%02x", tech_id);

	switch (tech_id) {
#ifdef CONFIG_FMDN_RANGING_OOB_DE_TYPE_UWB_EN
	case RT_TECH_ID_UWB: {
		/* UWB ranging stop requested.
		 *
		 * In this reference implementation, we simply acknowledge the stop request.
		 * Customers can implement actual UWB hardware stop logic here if needed.
		 */
		LOG_INF("Platform: UWB ranging stop acknowledged");
#ifdef CONFIG_AT_EVT_TAGRANGING
		at_cmd_evt_tag_ranging(at_cmd_set_uart_ch_get(), RT_TECH_ID_UWB, 0);
#endif
		return 0;
	}
#endif
#ifdef CONFIG_FMDN_RANGING_OOB_DE_TYPE_BLE_CS_EN
	case RT_TECH_ID_CS: {
		/* BLE Channel Sounding configuration received.
		 *
		 * Per spec: Responder doesn't need to do anything - only initiator calls BLE stack.
		 * Optionally use messages as trigger for visual feedback (e.g., blink LEDs, update
		 * UI).
		 */
		LOG_INF("Platform: CS ranging stop acknowledged");
#ifdef CONFIG_AT_EVT_TAGRANGING
		at_cmd_evt_tag_ranging(at_cmd_set_uart_ch_get(), RT_TECH_ID_CS, 0);
#endif
		return 0;
	}
#endif
	default:
		LOG_ERR("Platform: Unsupported technology ID 0x%02x for stop", tech_id);
#ifdef CONFIG_AT_CMD_TAG_SET
		at_cmd_evt_tag_error(at_cmd_set_uart_ch_get(), AT_CMD_TAG_MODE_FHN,
				     AT_CMD_TAG_ERR_INVALID_PARAM);
#endif
		return -ENOTSUP;
	}
}
