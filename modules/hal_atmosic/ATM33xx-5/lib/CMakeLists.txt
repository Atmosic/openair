# Copyright (c) 2024 Atmosic
#
# SPDX-License-Identifier: Apache-2.0

if (CONFIG_TRUSTED_EXECUTION_SECURE)
    zephyr_include_directories(
	sec_assert
	sec_service
    )
    zephyr_sources(
	sec_assert/sec_assert.c
	sec_service/sec_service.c
    )
endif ()
