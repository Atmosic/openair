/**
 *******************************************************************************
 *
 * @file atm_settings_nvs.c
 *
 * @brief Atmosic settings NVS backend initialization for settings subsystem
 *
 * Copyright (C) Atmosic 2024
 *
 *******************************************************************************
 */

#include <zephyr/storage/flash_map.h>
#include "settings/settings_nvs.h"
#include "atm_settings_nvs.h"

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

int atm_settings_backend_init(
    struct settings_backend_config_s const *settings_config)
{
    size_t nvs_sector_size = CONFIG_SETTINGS_NVS_SECTOR_SIZE_MULT *
	settings_config->part_info.part_sector_size;

    if (nvs_sector_size > UINT16_MAX) {
	return -EDOM;
    }

    uint16_t cnt = settings_config->part_info.part_size / nvs_sector_size;
    if (cnt > CONFIG_SETTINGS_NVS_SECTOR_COUNT) {
	cnt = CONFIG_SETTINGS_NVS_SECTOR_COUNT;
    }

    static struct settings_nvs default_settings_nvs;

    /* define the nvs file system using the page_info */
    default_settings_nvs.cf_nvs.sector_size = nvs_sector_size;
    default_settings_nvs.cf_nvs.sector_count = cnt;
    default_settings_nvs.cf_nvs.offset = settings_config->part_info.part_offset;
    default_settings_nvs.flash_dev = settings_config->part_info.part_dev;

    int rc = settings_nvs_backend_init(&default_settings_nvs);
    if (rc) {
	return rc;
    }

    if (settings_config->backend_reg_src) {
	rc = settings_nvs_src(&default_settings_nvs);
	if (rc) {
	    return rc;
	}
    }

    if (settings_config->backend_reg_dst) {
	rc = settings_nvs_dst(&default_settings_nvs);
	if (rc) {
	    return rc;
	}
    }

    return 0;
}
