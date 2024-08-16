/**
 *******************************************************************************
 *
 * @file atm_settings_nvs.h
 *
 * @brief Atmosic settings NVS backend initialization for settings subsystem
 *
 * Copyright (C) Atmosic 2024
 *
 *******************************************************************************
 */

#pragma once

#include <stdio.h>
#include "compiler.h"

#ifdef __cplusplus
extern "C" {
#endif

struct part_info_s {
    struct device const *part_dev;
    size_t part_sector_size;
    off_t part_offset;
    size_t part_size;
};

struct settings_backend_config_s {
    struct part_info_s part_info;
    bool backend_reg_src;
    bool backend_reg_dst;
};

/**
 * @brief Get specific partition information
 *
 * Get the specified partition information defined in the device tree based on
 * the partition ID.
 *
 * @param[in] part_id Partition ID
 * @param[out] part_info Pointer to location to store retrieved information
 * @return 0 on success
 */
__NONNULL(2)
int atm_get_device_partition_info(uint8_t part_id,
    struct part_info_s *part_info);

/**
 * @brief Initialize the settings subsystem backends
 *
 * Initialize the settings subsystem backends based on the specified settings
 * configuration information instead of settings storage partition.
 *
 * @param[in] settings_config Pointer to a specific settings configuration
 * @return 0 on success
 */
__NONNULL_ALL
int atm_settings_backend_init(
    struct settings_backend_config_s const *settings_config);

#ifdef __cplusplus
}
#endif
