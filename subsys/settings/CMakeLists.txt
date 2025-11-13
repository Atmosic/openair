# Copyright (c) 2024-2025 Atmosic
#
# SPDX-License-Identifier: Apache-2.0

if(CONFIG_ATM_SETTINGS)
    zephyr_include_directories(.)
    zephyr_sources(
	atm_settings.c
	atm_settings_init.c
	atm_settings_backend.c
    )
    zephyr_sources_ifdef(CONFIG_SETTINGS_NVS atm_settings_nvs.c)
endif()
