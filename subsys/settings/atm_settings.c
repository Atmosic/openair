/**
 *******************************************************************************
 *
 * @file atm_settings.c
 *
 * @brief Atmosic settings subsystem initialization and settings data handling
 *
 * Copyright (C) Atmosic 2024-2025
 *
 *******************************************************************************
 */

#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <zephyr/settings/settings.h>
#include <zephyr/logging/log.h>
#include <zephyr/storage/flash_map.h>
#include "atm_settings.h"
#if DT_NODE_EXISTS(DT_NODELABEL(rram_controller))
#include "rram_rom_prot.h"
#elif CONFIG_DT_HAS_ATMOSIC_SEC_NV_MEM_FLASH_PROT_ENABLED
#include "flash_prot.h"
#endif

#define LOG_MODULE_NAME atm_settings
LOG_MODULE_REGISTER(LOG_MODULE_NAME, CONFIG_ATM_SETTINGS_LOG_LEVEL);

#define PART_ADDR(label) ( \
    DT_REG_ADDR(DT_MTD_FROM_FIXED_PARTITION(DT_NODELABEL(label))) + \
    DT_REG_ADDR(DT_NODELABEL(label)) \
)

static int atm_settings_init(void)
{
#if DT_NODE_EXISTS(DT_NODELABEL(factory_partition))
    LOG_INF("Factory data range: [0x%08x - 0x%08x]",
	(unsigned int)PART_ADDR(factory_partition),
	(unsigned int)PART_ADDR(factory_partition) +
	    (unsigned int)DT_REG_SIZE(DT_NODELABEL(factory_partition)) - 1);
#endif
#if DT_NODE_EXISTS(DT_NODELABEL(storage_partition))
    LOG_INF("Settings storage range: [0x%08x - 0x%08x]",
	(unsigned int)PART_ADDR(storage_partition),
	(unsigned int)PART_ADDR(storage_partition) +
	    (unsigned int)DT_REG_SIZE(DT_NODELABEL(storage_partition)) - 1);
#endif

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

#if DT_NODE_EXISTS(DT_NODELABEL(factory_partition)) && \
    (DT_NODE_EXISTS(DT_NODELABEL(rram_controller)) || \
	CONFIG_DT_HAS_ATMOSIC_SEC_NV_MEM_FLASH_PROT_ENABLED)
    uint32_t factory_offset = factory_config.part_info.part_offset;
    uint32_t factory_size = factory_config.part_info.part_size;
    bool sec_s;
#if DT_NODE_EXISTS(DT_NODELABEL(rram_controller))
    sec_s = rram_prot_sticky_write_disable(factory_offset, factory_size);
#elif CONFIG_DT_HAS_ATMOSIC_SEC_NV_MEM_FLASH_PROT_ENABLED
    sec_s = flash_prot_sticky_write_disable(factory_offset, factory_size);
#endif
    if (!sec_s) {
	LOG_INF("settings factory data WP: fail (0x%" PRIx32 ", 0x%" PRIx32 ")",
	    factory_offset, factory_size);
	return -EINVAL;
    }
    LOG_INF("settings factory data WP: OK.");
#endif // factory_partition

    return 0;
}

// The atm_settings_init initialization process must be later than
// flash_atm_rram_init initialization, and earlier than the first function using
// the settings subsystem api (such as ble_driver_init initialization)
SYS_INIT(atm_settings_init, POST_KERNEL, CONFIG_ATM_SETTINGS_INIT_PRIORITY);
