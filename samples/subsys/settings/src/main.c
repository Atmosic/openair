/*
 * Copyright (c) 2024-2025 Atmosic
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/ztest.h>
#include <stdio.h>
#include <stdbool.h>
#include <zephyr/settings/settings.h>
#include "atm_settings.h"

static int load_err;

static void clear_load_error_status(void)
{
    load_err = 0;
}

static int get_load_error_status(void)
{
    return load_err;
}

static uint16_t company_id;
static uint32_t serial_number;

static int factory_data_handle_set(char const *name, size_t len,
    settings_read_cb read_cb, void *cb_arg)
{
    char const *next;

    if (settings_name_steq(name, KEY_NAME(COMPANY_ID), &next) && !next) {
	if (len != sizeof(company_id)) {
	    load_err = -EINVAL;
	    return load_err;
	}
	read_cb(cb_arg, &company_id, sizeof(company_id));
	return 0;
    }

    if (settings_name_steq(name, KEY_NAME(SERIAL_NUMBER), &next) && !next) {
	if (len != sizeof(serial_number)) {
	    load_err = -EINVAL;
	    return load_err;
	}
	read_cb(cb_arg, &serial_number, sizeof(serial_number));
	return 0;
    }

    load_err = -ENOENT;
    return load_err;
}

static char version[4];
static uint32_t test_key;

static int settings_storage_handle_set(char const *name, size_t len,
    settings_read_cb read_cb, void *cb_arg)
{
    char const *next;

    if (settings_name_steq(name, KEY_NAME(VERSION), &next) && !next) {
	if (len != sizeof(version)) {
	    load_err = -EINVAL;
	    return load_err;
	}
	read_cb(cb_arg, &version, sizeof(version));
	return 0;
    }

    if (settings_name_steq(name, KEY_NAME(TEST_KEY), &next) && !next) {
	if (len != sizeof(test_key)) {
	    load_err = -EINVAL;
	    return load_err;
	}
	read_cb(cb_arg, &test_key, sizeof(test_key));
	return 0;
    }

    load_err = -ENOENT;
    return load_err;
}

/* static subtree handler */
SETTINGS_STATIC_HANDLER_DEFINE(factory_data, MAIN_KEY(FACTORY), NULL,
    factory_data_handle_set, NULL, NULL);

SETTINGS_STATIC_HANDLER_DEFINE(settings_storage, MAIN_KEY(SETTINGS), NULL,
    settings_storage_handle_set, NULL, NULL);

static int settings_test_key_access_check(uint32_t check_value)
{
    /* save TEST_KEY key-value directly */
    printk("save %s key: %#x\n", SETTINGS_STORAGE_KEY(TEST_KEY), check_value);
    int rc = settings_save_one(SETTINGS_STORAGE_KEY(TEST_KEY), &check_value,
	sizeof(check_value));
    if (rc) {
	printk("Failed to save key-value\n");
	return rc;
    }

    /* load key-value after saving certain key-value */
    rc = settings_load_subtree(SETTINGS_STORAGE_KEY(TEST_KEY));
    if (rc) {
	printk("Failed to load key-value\n");
	return rc;
    }

    printk("load %s key: %#x\n", SETTINGS_STORAGE_KEY(TEST_KEY), test_key);
    if (test_key != check_value) {
	rc = -EINVAL;
	printk("Failed to load key-value\n");
	return rc;
    }

    return 0;
}

ZTEST(atm_settings_test, test_atm_settings_call)
{
    clear_load_error_status();

    /* load all pre-saved key-values in the factory data and settings storage */
    int rc = settings_load();
    zassert_true(!rc, "Failed to load key-value");

    #define PRE_COMPANY_ID 0x0A24
    #define PRE_SERIAL_NUM 0x12345678
    #define PRE_VERSION "1.23"

    if (company_id) {
	printk("load %s key: %#x\n", FACTORY_DATA_KEY(COMPANY_ID), company_id);
	zassert_true((company_id == PRE_COMPANY_ID),
	    "Failed to load key-value");
    }
    if (serial_number) {
	printk("load %s key: %#x\n", FACTORY_DATA_KEY(SERIAL_NUMBER),
	    serial_number);
	zassert_true((serial_number == PRE_SERIAL_NUM),
	    "Failed to load key-value");
    }
    if (strcmp(version, "")) {
	printk("load %s key: %s\n", SETTINGS_STORAGE_KEY(VERSION), version);
	zassert_true((strcmp(version, PRE_VERSION) == 0),
	    "Failed to load key-value");
    }

    rc = settings_test_key_access_check(0x5AA50FF0);
    zassert_true(!rc, "Failed to access key-value");

    rc = settings_test_key_access_check(0xA55AF00F);
    zassert_true(!rc, "Failed to access key-value");

    rc = get_load_error_status();
    zassert_true(!rc, "Failed to load key-value");

    printk("atm settings to save and load key-value! %s\n", CONFIG_BOARD);
}

ZTEST_SUITE(atm_settings_test, NULL, NULL, NULL, NULL, NULL);
