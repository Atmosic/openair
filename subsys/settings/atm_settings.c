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

static int factory_data_handle_set(char const *name, size_t len,
    settings_read_cb read_cb, void *cb_arg)
{
    char const *next;

    if (settings_name_steq(name, KEY_NAME(COMPANY_ID), &next) && !next) {
	uint16_t company_id;
	if (len != sizeof(company_id)) {
	    return -EINVAL;
	}
	read_cb(cb_arg, &company_id, sizeof(company_id));
	LOG_INF("%s/%s = %#x", MAIN_KEY(FACTORY), name, company_id);
	return 0;
    }

    if (settings_name_steq(name, KEY_NAME(SERIAL_NUMBER), &next) && !next) {
	uint32_t serial_number;
	if (len != sizeof(serial_number)) {
	    return -EINVAL;
	}
	read_cb(cb_arg, &serial_number, sizeof(serial_number));
	LOG_INF("%s/%s = %#x", MAIN_KEY(FACTORY), name, serial_number);
	return 0;
    }

    return -ENOENT;
}

static int settings_storage_handle_set(char const *name, size_t len,
    settings_read_cb read_cb, void *cb_arg)
{
    char const *next;

    if (settings_name_steq(name, KEY_NAME(VERSION), &next) && !next) {
	uint16_t version;
	if (len != sizeof(version)) {
	    return -EINVAL;
	}
	read_cb(cb_arg, &version, sizeof(version));
	LOG_INF("%s/%s = %d", MAIN_KEY(SETTINGS), name, version);
	return 0;
    }

    return -ENOENT;
}

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

/* static subtree handler */
SETTINGS_STATIC_HANDLER_DEFINE(factory_data, MAIN_KEY(FACTORY), NULL,
    factory_data_handle_set, NULL, NULL);

SETTINGS_STATIC_HANDLER_DEFINE(settings_storage, MAIN_KEY(SETTINGS), NULL,
    settings_storage_handle_set, NULL, NULL);
