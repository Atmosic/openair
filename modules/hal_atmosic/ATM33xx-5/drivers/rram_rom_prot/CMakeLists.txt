# Copyright (c) 2024 Atmosic
#
# SPDX-License-Identifier: Apache-2.0

if (CONFIG_ATM_RRAM_ROM_PROT)
    zephyr_include_directories(.)
    zephyr_sources(rram_rom_prot.c)
endif ()
