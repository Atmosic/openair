# Copyright (c) 2024 Atmosic
#
# SPDX-License-Identifier: Apache-2.0

if (CONFIG_ATM_SETTINGS)
    zephyr_include_directories(.)
    zephyr_sources(
	atm_settings.c
	atm_settings_init.c
	atm_settings_nvs.c
    )
endif ()
