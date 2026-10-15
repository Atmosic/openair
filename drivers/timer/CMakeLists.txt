# Copyright (c) 2026 Atmosic Technologies, Inc.
# SPDX-License-Identifier: LicenseRef-Atmosic

zephyr_library_amend()

zephyr_library_sources_ifdef(CONFIG_CMSDK_TIMER cmsdk_timer.c)
