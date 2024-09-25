# Copyright (c) 2024 Atmosic
#
# SPDX-License-Identifier: Apache-2.0

if (CONFIG_ATM_MCUBOOT_EXT)
    zephyr_include_directories(.)
    zephyr_sources(atm_mcuboot_ext.c)
endif ()
