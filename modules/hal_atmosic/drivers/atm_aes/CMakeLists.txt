# Copyright (c) 2024 Atmosic
#
# SPDX-License-Identifier: Apache-2.0

if (CONFIG_ATM_AES)
    zephyr_include_directories(.)
    zephyr_sources(atm_aes.c)
endif ()

zephyr_sources_ifdef(CONFIG_ATM_AES_HW aes_alt.c)
