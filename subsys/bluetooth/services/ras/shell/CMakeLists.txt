# Copyright (c) 2025 Atmosic
#
# SPDX-License-Identifier: Apache-2.0

zephyr_library()
zephyr_library_sources_ifdef(CONFIG_RAS_CLIENT_SHELL ras_client.c)
