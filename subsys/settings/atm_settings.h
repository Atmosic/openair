/**
 *******************************************************************************
 *
 * @file atm_settings.h
 *
 * @brief Atmosic settings subsystem initialization and settings data handling
 *
 * Copyright (C) Atmosic 2024-2025
 *
 *******************************************************************************
 */

#pragma once

#include "atm_settings_init.h"

#ifdef __cplusplus
extern "C" {
#endif

#define MAIN_KEY(mainkey) #mainkey
#define KEY_NAME(keyname) #keyname
#define FACTORY_DATA_KEY(subkey) MAIN_KEY(FACTORY) "/" KEY_NAME(subkey)
#define SETTINGS_STORAGE_KEY(subkey) MAIN_KEY(SETTINGS) "/" KEY_NAME(subkey)

#if DT_NODE_EXISTS(DT_NODELABEL(factory_partition))
#if DT_NODE_EXISTS(DT_NODELABEL(rram_controller)) && \
    DT_SAME_NODE(DT_GPARENT(DT_NODELABEL(factory_partition)), \
	DT_NODELABEL(rram0))
#define FACTORY_IN_RRAM 1
#endif
#if DT_NODE_EXISTS(DT_NODELABEL(flash_controller)) && \
    DT_SAME_NODE(DT_GPARENT(DT_NODELABEL(factory_partition)), \
	DT_NODELABEL(flash0))
#define FACTORY_IN_FLASH 1
#endif
#endif // DT_NODE_EXISTS(DT_NODELABEL(factory_partition))

#ifdef __cplusplus
}
#endif
