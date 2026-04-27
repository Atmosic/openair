# Copyright (c) 2025 Atmosic Technologies
# SPDX-License-Identifier: Apache-2.0

zephyr_library_amend()

# Main driver file (common logic)
zephyr_library_sources_ifdef(CONFIG_RETAINED_MEM_ATM_HIB retained_mem_hib.c)

# Backend selection based on hardware capabilities
# The backend is selected at compile time based on Kconfig options
zephyr_library_sources_ifdef(CONFIG_RETAINED_MEM_BACKEND_SHUB retained_mem_hib_shub.c)
zephyr_library_sources_ifdef(CONFIG_RETAINED_MEM_BACKEND_EXPANSION retained_mem_hib_expansion.c)
