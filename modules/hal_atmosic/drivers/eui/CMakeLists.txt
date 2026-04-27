# Copyright (c) 2024-2026 Atmosic
#
# SPDX-License-Identifier: LicenseRef-Atmosic
#

if(CONFIG_ATM_EUI)
    zephyr_include_directories(.)
    zephyr_sources(eui.c)
endif()

zephyr_compile_definitions_ifdef(CONFIG_ATM_EUI_ALLOW_RANDOM EUI_ALLOW_RANDOM)
zephyr_compile_definitions_ifdef(CONFIG_ATM_EUI48_ALLOW_BUILTIN EUI48_ALLOW_BUILTIN)
