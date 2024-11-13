# Copyright (c) 2024 Atmosic
#
# SPDX-License-Identifier: Apache-2.0

zephyr_include_directories_ifdef(CONFIG_TRUSTED_EXECUTION_SECURE .)
zephyr_sources_ifdef(CONFIG_TRUSTED_EXECUTION_SECURE sec_service.c)
