# Copyright (c) 2024-2026 Atmosic
#
# SPDX-License-Identifier: LicenseRef-Atmosic

if(CONFIG_TRUSTED_EXECUTION_SECURE OR CONFIG_ZTEST)
    zephyr_include_directories(.)
    zephyr_sources(sec_assert.c)
endif()
