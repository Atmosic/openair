/**
 *******************************************************************************
 *
 * @file atm_settings_init.h
 *
 * @brief Atmosic settings partition initialization for settings subsystem
 *
 * Copyright (C) Atmosic 2024
 *
 *******************************************************************************
 */

#pragma once

#include "compiler.h"
#include "atm_settings_nvs.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Get factory partition information
 *
 * Get the factory partition information defined in the device tree.
 *
 * @param[out] part_info Pointer to location to store retrieved information
 * @return 0 on success
 */
__NONNULL_ALL
int atm_settings_factory_partition_info_get(struct part_info_s *part_info);

/**
 * @brief Initialize a specific partition for settings subsystem
 *
 * Provide proprietary settings subsystem initialization that allows for more
 * flexibility in configuring the settings subsystem instead of settings storage
 * partition only.
 *
 * @param[in] settings_config Pointer to a specific settings configuration
 * @return 0 on success
 */
__NONNULL_ALL
int atm_settings_subsys_init(
    struct settings_backend_config_s const *settings_config);

#ifdef __cplusplus
}
#endif
