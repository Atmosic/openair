/**
 *******************************************************************************
 *
 * @file atm_settings_init.c
 *
 * @brief Atmosic settings partition initialization for settings subsystem
 *
 * Copyright (C) Atmosic 2024-2025
 *
 *******************************************************************************
 */

#include <errno.h>
#include <zephyr/kernel.h>
#include <zephyr/storage/flash_map.h>
#include "atm_settings_init.h"
#include "../subsys/settings/src/settings_priv.h"

#if DT_NODE_EXISTS(DT_NODELABEL(factory_partition))
#define FACTORY_PARTITION FIXED_PARTITION_ID(factory_partition)
#endif

static bool atm_settings_subsys_initialized;

int atm_settings_factory_partition_info_get(struct part_info_s *part_info)
{
#ifdef FACTORY_PARTITION
    return atm_get_device_partition_info(FACTORY_PARTITION, part_info);
#else
    return -ENOENT;
#endif
}

int atm_settings_subsys_init(
    struct settings_backend_config_s const *settings_config)
{
    settings_lock_take();

    int err = 0;

    if (!atm_settings_subsys_initialized) {
	err = atm_settings_backend_init(settings_config);

	if (!err) {
	    atm_settings_subsys_initialized = true;
	}
    }

    settings_lock_release();

    return err;
}
