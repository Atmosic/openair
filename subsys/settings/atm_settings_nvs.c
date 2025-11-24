/**
 *******************************************************************************
 *
 * @file atm_settings_nvs.c
 *
 * @brief Atmosic settings NVS backend initialization for settings subsystem
 *
 * Copyright (C) Atmosic 2024-2025
 *
 *******************************************************************************
 */

#include "settings/settings_nvs.h"
#include "atm_settings_backend.h"

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
