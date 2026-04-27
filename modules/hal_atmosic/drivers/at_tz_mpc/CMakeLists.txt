# Copyright (c) 2024-2026 Atmosic
#
# SPDX-License-Identifier: LicenseRef-Atmosic
#

if (CONFIG_ATM_TZ_MPC)
    zephyr_include_directories(.)
    zephyr_sources(at_tz_mpc.c)
endif ()
