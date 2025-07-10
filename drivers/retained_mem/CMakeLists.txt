# Copyright (c) 2025 Atmosic Technologies
# SPDX-License-Identifier: Apache-2.0

zephyr_library_amend()

zephyr_library_sources_ifdef(CONFIG_RETAINED_MEM_ATM_HIB retained_mem_hib.c)
