# Copyright (c) 2024-2026 Atmosic
#
# SPDX-License-Identifier: LicenseRef-Atmosic
#

if(CONFIG_ATM_RRAM_ROM_PROT)
    zephyr_include_directories(.)
    zephyr_sources(rram_rom_prot.c)
endif()
