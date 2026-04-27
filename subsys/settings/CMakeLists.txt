# Copyright (c) 2024-2026 Atmosic
#
# SPDX-License-Identifier: Apache-2.0

if(CONFIG_ATM_SETTINGS)
  zephyr_library()
  zephyr_include_directories(.)
  zephyr_library_sources(
    atm_settings.c
    atm_settings_init.c
    atm_settings_backend.c
  )
  zephyr_library_sources_ifdef(CONFIG_SETTINGS_NVS atm_settings_nvs.c)
endif()
