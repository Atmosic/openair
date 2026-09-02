# Copyright (c) 2024-2026 Atmosic
#
# SPDX-License-Identifier: LicenseRef-Atmosic

zephyr_include_directories_ifdef(CONFIG_TRUSTED_EXECUTION_SECURE .)
zephyr_sources_ifdef(CONFIG_TRUSTED_EXECUTION_SECURE sec_service.c)

zephyr_compile_definitions_ifdef(CONFIG_ATM_VERIFY_ATMWSTK VERIFY_ATMWSTK=1)
