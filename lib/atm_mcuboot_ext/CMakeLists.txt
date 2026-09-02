# Copyright (c) 2024-2026 Atmosic
#
# SPDX-License-Identifier: LicenseRef-Atmosic

if(CONFIG_ATM_MCUBOOT_EXT)
    zephyr_include_directories(.)
    zephyr_sources(atm_mcuboot_ext.c)
    if(CONFIG_ATM_MCUBOOT_UART_DEBUG_AUTH)
        zephyr_compile_definitions(DEBUG_AUTH_STATIC_CHALLENGE)
        zephyr_sources(atm_mcuboot_ext_uart_auth.c)
    endif()
endif()
