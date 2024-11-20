# Copyright (c) 2024 Atmosic
#
# SPDX-License-Identifier: Apache-2.0

if (CONFIG_ATM_MCUBOOT_EXT)
    zephyr_include_directories(.)
    zephyr_sources(atm_mcuboot_ext.c)
    if (CONFIG_ATM_MCUBOOT_UART_DEBUG_AUTH)
        zephyr_compile_definitions(DEBUG_AUTH_STATIC_CHALLENGE)
        zephyr_sources(atm_mcuboot_ext_uart_auth.c)
    endif ()
endif ()
