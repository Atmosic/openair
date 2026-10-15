# Copyright (c) 2024-2026 Atmosic
#
# SPDX-License-Identifier: LicenseRef-Atmosic

if(CONFIG_APP_WORK_Q)
    zephyr_include_directories(.)
    zephyr_sources(app_work_q.c)
endif()
