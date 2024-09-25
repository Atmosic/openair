/**
 *******************************************************************************
 *
 * @file atm_settings.c
 *
 * @brief Atmosic settings subsystem initialization and settings data handling
 *
 * Copyright (C) Atmosic 2024
 *
 *******************************************************************************
 */

#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <zephyr/settings/settings.h>
#include <zephyr/logging/log.h>
#include "atm_settings.h"

#define LOG_MODULE_NAME atm_settings
LOG_MODULE_REGISTER(LOG_MODULE_NAME, CONFIG_ATM_SETTINGS_LOG_LEVEL);

int atm_settings_init(void)
{
    int rc = settings_subsys_init();
    if (rc) {
	LOG_INF("settings subsys initialization: fail (err %d)", rc);
	return rc;
    }
    LOG_INF("settings subsys initialization: OK.");

    struct settings_backend_config_s factory_config;

    rc = atm_settings_factory_partition_info_get(&factory_config.part_info);
    if (rc) {
	LOG_INF("get settings factory partition: fail (err %d)", rc);
	return rc;
    }

    factory_config.backend_reg_src = true;
    factory_config.backend_reg_dst = false;

    rc = atm_settings_subsys_init(&factory_config);
    if (rc) {
	LOG_INF("settings factory initialization: fail (err %d)", rc);
	return rc;
    }
    LOG_INF("settings factory initialization: OK.");

    return 0;
}
