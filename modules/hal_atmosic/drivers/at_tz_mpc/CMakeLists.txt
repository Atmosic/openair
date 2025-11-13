# Copyright (c) 2024 Atmosic
#
# SPDX-License-Identifier: Apache-2.0

if (CONFIG_ATM_TZ_MPC)
    zephyr_include_directories(.)
    zephyr_sources(at_tz_mpc.c)
endif ()
