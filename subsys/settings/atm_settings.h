/**
 *******************************************************************************
 *
 * @file atm_settings.h
 *
 * @brief Atmosic settings subsystem initialization and settings data handling
 *
 * Copyright (C) Atmosic 2024
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

#ifdef __cplusplus
}
#endif
