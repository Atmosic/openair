# Copyright (c) 2024 Atmosic
#
# SPDX-License-Identifier: Apache-2.0

if (CONFIG_ATM_SEC_DEV_LOCKOUT)
    zephyr_include_directories(.)
    zephyr_sources(sec_dev_lockout.c)
endif ()
