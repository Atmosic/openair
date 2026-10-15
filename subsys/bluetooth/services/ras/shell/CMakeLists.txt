# Copyright (c) 2025 Atmosic
#
# SPDX-License-Identifier: LicenseRef-Atmosic

zephyr_library()
zephyr_library_sources_ifdef(CONFIG_RAS_CLIENT_SHELL ras_client.c)
