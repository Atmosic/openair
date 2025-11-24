/**
 *******************************************************************************
 *
 * @file fp_tag_platform_ranging.c
 *
 * @brief Fast Pair tag ranging platform implementation
 *
 * Copyright (C) Atmosic 2025
 *
 *******************************************************************************
 */

#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
#include <errno.h>
#include "fp_tag_platform_ranging.h"

LOG_MODULE_DECLARE(multimode_consumer_tag, CONFIG_MULTIMODE_CONSUMER_TAG_LOG_LEVEL);

/* ========================================================================
 * Public platform ranging interface
 * ======================================================================== */

/**
 * @brief Handle ranging capability requests
 * @param tech_id Technology ID (UWB/CS)
 * @param capability Capability structure to populate
 * @return 0 on success, negative on error
 *
 * @note Size field handling: Based on actual testing with FHN (Find Hub Network) app,
 *       the size field should contain the full structure size, not the payload size
 *       as suggested in some specification interpretations. This implementation
 *       uses sizeof(struct) which has been verified to work correctly.
 */
int fp_platform_ranging_capability_cb(rt_id_t tech_id, void *capability)
{
	LOG_INF("Platform: Capability request for technology ID 0x%02x", tech_id);

	switch (tech_id) {
#ifdef CONFIG_FMDN_RANGING_OOB_DE_TYPE_UWB_EN
	case RT_TECH_ID_UWB: {
		/* NOTE: In actual testing with FHN app, the size field behavior differs from spec.
		 * Using full struct size works correctly. */
		ranging_cap_de_uwb_t *uwb = (ranging_cap_de_uwb_t *)capability;

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
	}
#endif
#ifdef CONFIG_FMDN_RANGING_OOB_DE_TYPE_BLE_CS_EN
	case RT_TECH_ID_CS: {
		ranging_cap_de_cs_t *cs = (ranging_cap_de_cs_t *)capability;
		*cs = (ranging_cap_de_cs_t){
			.id = RT_TECH_ID_CS,
			.size = sizeof(ranging_cap_de_cs_t),
			.sec_type = CONFIG_FMDN_RANGING_CS_SECURITY_LEVEL,
			.addr = {0},
			.appearance = CONFIG_BT_DEVICE_APPEARANCE,
			.flags = CS_LE_FLAG_GENERAL_DISCOVERY_MODE,
		};
		LOG_INF("Constructed CS capabilities");
		return 0;
	}
#endif
	default:
		LOG_WRN("Platform: Unsupported technology ID 0x%02x", tech_id);
		return -ENOTSUP;
	}
}

/**
 * @brief Handle ranging configuration requests
 * @param tech_id Technology ID being configured
 * @param config Configuration data
 * @param start_immediately Whether to start immediately
 * @return 0 on success, negative on error
 */
int fp_platform_ranging_config_cb(rt_id_t tech_id, void *config, bool start_immediately)
{
	LOG_INF("Platform: Configuration request for technology ID 0x%02x", tech_id);

	switch (tech_id) {
#ifdef CONFIG_FMDN_RANGING_OOB_DE_TYPE_UWB_EN
	case RT_TECH_ID_UWB: {
		LOG_INF("Platform: UWB config received");
		ranging_conf_de_uwb_t *uwb = (ranging_conf_de_uwb_t *)config;
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
		if (start_immediately) {
			LOG_INF("Platform: UWB auto-start requested");
		}
		return 0;
	}
#endif
#ifdef CONFIG_FMDN_RANGING_OOB_DE_TYPE_BLE_CS_EN
	case RT_TECH_ID_CS: {
		LOG_INF("Platform: CS config received");
		ranging_conf_de_cs_t *cs = (ranging_conf_de_cs_t *)config;
		/* BLE Channel Sounding configuration received.
		 *
		 * Per spec: Responder doesn't need to do anything - only initiator calls BLE stack.
		 * Optionally use messages as trigger for visual feedback (e.g., blink LEDs, update
		 * UI).
		 */
		LOG_DBG("Platform: CS config acknowledged");
		(void)cs; /* Suppress unused variable warning */
		return 0;
	}
#endif
	default:
		LOG_ERR("Platform: Unsupported technology ID 0x%02x for configuration", tech_id);
		return -ENOTSUP;
	}
}

/**
 * @brief Handle ranging start requests
 * @param tech_id Technology ID to start
 * @return 0 on success, negative on error
 */
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
		return -ENOTSUP;
	}
}

/**
 * @brief Handle ranging stop requests
 * @param tech_id Technology ID to stop
 * @return 0 on success, negative on error
 */
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
		return 0;
	}
#endif
	default:
		LOG_ERR("Platform: Unsupported technology ID 0x%02x for stop", tech_id);
		return -ENOTSUP;
	}
}
