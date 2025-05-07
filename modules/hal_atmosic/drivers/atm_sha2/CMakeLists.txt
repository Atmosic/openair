# Copyright (c) 2024 Atmosic
#
# SPDX-License-Identifier: Apache-2.0

if (CONFIG_ATM_SHA2)
    zephyr_include_directories(.)
    zephyr_sources(atm_sha2.c)
endif ()

zephyr_sources_ifdef(CONFIG_ATM_SHA2_HW sha256_alt.c)
