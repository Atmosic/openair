/**
 *******************************************************************************
 *
 * @file fp_tag_platform_ranging.h
 *
 * @brief Fast Pair tag ranging platform implementation
 *
 * Copyright (C) Atmosic 2025
 *
 *******************************************************************************
 */

#pragma once

#ifdef CONFIG_FMDN_PRECISION_FINDING

#include "compiler.h" // __NONNULL inline functions
#include "ranging_oob_de.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Handle ranging capability requests
 * @param tech_id Technology ID (UWB/CS)
 * @param capability Capability structure to populate
 * @return 0 on success, negative on error
 */
__NONNULL(2)
int fp_platform_ranging_capability_cb(rt_id_t tech_id, void *capability);

/**
 * @brief Handle ranging configuration requests
 * @param tech_id Technology ID being configured
 * @param config Configuration data
 * @param start_immediately Whether to start immediately
 * @return 0 on success, negative on error
 */
__NONNULL(2)
int fp_platform_ranging_config_cb(rt_id_t tech_id, void *config, bool start_immediately);

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

#endif // CONFIG_FMDN_PRECISION_FINDING

#ifdef __cplusplus
}
#endif
