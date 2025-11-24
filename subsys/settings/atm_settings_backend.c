/**
 *******************************************************************************
 *
 * @file atm_settings_backend.c
 *
 * @brief Atmosic settings backend initialization for settings subsystem
 *
 * Copyright (C) Atmosic 2025
 *
 *******************************************************************************
 */

#include <errno.h>
#include <zephyr/logging/log.h>
#include <zephyr/storage/flash_map.h>
#include "atm_settings_backend.h"

#define LOG_MODULE_NAME atm_settings_backend
LOG_MODULE_REGISTER(LOG_MODULE_NAME, CONFIG_ATM_SETTINGS_LOG_LEVEL);

int atm_get_device_partition_info(uint8_t part_id,
    struct part_info_s *part_info)
{
    struct flash_area const *fa;

    int rc = flash_area_open(part_id, &fa);
    if (rc) {
	return rc;
    }

    struct flash_sector fs;
    uint32_t sector_cnt = 1;

    rc = flash_area_get_sectors(part_id, &sector_cnt, &fs);
    if (rc && (rc != -ENOMEM)) {
	return rc;
    }

    part_info->part_dev = fa->fa_dev;
    part_info->part_sector_size = fs.fs_size;
    part_info->part_offset = fa->fa_off;
    part_info->part_size = fa->fa_size;

    return 0;
}

__weak int atm_settings_backend_init(
    struct settings_backend_config_s const *settings_config)
{
    ARG_UNUSED(settings_config);

    LOG_WRN("atm_settings backend not configured or unsupported.");
    return 0;
}
