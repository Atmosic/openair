# Copyright (c) 2025-2026 Atmosic Technologies
# SPDX-License-Identifier: LicenseRef-Atmosic

zephyr_library_amend()

zephyr_library_sources_ifdef(CONFIG_RETAINED_MEM_ATM_HIB
  retained_mem_hib.c
  retained_mem_hib_shub.c
  retained_mem_hib_expansion.c
)

zephyr_include_directories_ifdef(CONFIG_RETAINED_MEM_TEST_ATM_BACKEND_INIT .)
