# Copyright (c) 2026 Atmosic Technologies, Inc.
# SPDX-License-Identifier: Apache-2.0

zephyr_library_amend()

zephyr_library_sources_ifdef(CONFIG_CMSDK_TIMER cmsdk_timer.c)
