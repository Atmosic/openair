# Copyright (c) 2025-2026 Atmosic
#
# SPDX-License-Identifier: LicenseRef-Atmosic
#

if(CONFIG_ATM_NV_MEM_ROM_PROT OR CONFIG_ATM_NV_MEM_FLASH_PROT)
  zephyr_include_directories(.)
  zephyr_sources(nv_mem_prot.c)
endif()

zephyr_sources_ifdef(CONFIG_ATM_NV_MEM_ROM_PROT rom_prot.c)
zephyr_sources_ifdef(CONFIG_ATM_NV_MEM_FLASH_PROT flash_prot.c)
