/**
 *******************************************************************************
 *
 * @file fp_tag_platform_ranging.h
 *
 * @brief Fast Pair tag ranging platform implementation
 *
 * Copyright (C) Atmosic 2025-2026
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 *
 *******************************************************************************
 */

#pragma once

#include "atm_gfp.h"

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
 * @brief Handle ranging start requests
 * @param tech_id Technology ID to start
 * @return 0 on success, negative on error
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
