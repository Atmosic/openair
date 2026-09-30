/**
 * @file fp_tag_platform_ranging.h
 *
 * @brief Fast Pair tag ranging platform implementation
 *
 * Copyright (c) 2025-2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#pragma once

#include "atm_gfp.h"
#ifdef CONFIG_AT_CMD_TAGRANGING
#include "at_cmd_tag.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

#ifdef CONFIG_FMDN_PRECISION_FINDING
#include "compiler.h"

/**
 * @brief Handle ranging capability requests
 * @param tech_id Technology ID (UWB/CS)
 * @param capability Struct containing the capability pointer for tech_id
 * @return 0 on success, negative on error
 */
__NONNULL(2)
int fp_platform_ranging_capability_cb(rt_id_t tech_id, ranging_capability_t *capability);

#ifdef CONFIG_AT_CMD_TAGRANGING
/**
 * @brief Check whether a ranging technology is enabled by the runtime gate.
 *
 * @param tech_id Ranging technology ID.
 * @return true if the technology is runtime-enabled.
 */
bool fp_platform_ranging_is_enabled_cb(rt_id_t tech_id);

#ifdef CONFIG_AT_CMD_TAGRANGINGCAPUWB
/**
 * @brief Get or set the host-provisioned UWB ranging capability.
 *
 * @param op Callback operation; GET reads the cache and SET updates it.
 * @param capability Input capability for SET, output capability for GET.
 * @return TAG AT command error code.
 */
at_cmd_tag_err_t fp_platform_ranging_capability_uwb_cb(at_cmd_tag_op_t op,
						       at_cmd_tag_ranging_cap_uwb_t *capability);
#endif

#ifdef CONFIG_AT_CMD_TAGRANGINGCAPCS
/**
 * @brief Get or set the host-provisioned BLE CS ranging capability.
 *
 * @param op Callback operation; GET reads the cache and SET updates it.
 * @param capability Input capability for SET, output capability for GET.
 * @return TAG AT command error code.
 */
at_cmd_tag_err_t fp_platform_ranging_capability_cs_cb(at_cmd_tag_op_t op,
						      at_cmd_tag_ranging_cap_cs_t *capability);
#endif

/**
 * @brief Get or set the runtime ranging technology gate.
 *
 * @param op Callback operation; GET reads the enabled mask and SET updates it.
 * @param action Gate action for SET; ignored for GET.
 * @param tech_mask Input mask for SET, output mask for GET.
 * @return TAG AT command error code.
 */
at_cmd_tag_err_t fp_platform_ranging_gate_cb(at_cmd_tag_op_t op,
					     at_cmd_tag_ranging_gate_action_t action,
					     uint8_t *tech_mask);
#endif /* CONFIG_AT_CMD_TAGRANGING */

/**
 * @brief Handle ranging configuration requests
 * @param tech_id Technology ID being configured
 * @param config Struct containing the config pointer for tech_id
 * @param start_immediately Whether to start immediately
 * @return 0 on success, negative on error
 */
__NONNULL(2)
int fp_platform_ranging_config_cb(rt_id_t tech_id, ranging_config_t *config,
				  bool start_immediately);

/**
 * @brief Handle deprecated legacy Start Ranging requests
 * @param tech_id Technology ID to start
 * @return 0 on success, negative on error
 * @deprecated New seekers use configuration with start_immediately.
 */
int fp_platform_ranging_start_cb(rt_id_t tech_id);

/**
 * @brief Handle ranging stop requests
 * @param tech_id Technology ID to stop
 * @return 0 on success, negative on error
 */
int fp_platform_ranging_stop_cb(rt_id_t tech_id);

#endif /* CONFIG_FMDN_PRECISION_FINDING */

#ifdef __cplusplus
}
#endif
