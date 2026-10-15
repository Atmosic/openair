# Copyright (c) 2024-2026 Atmosic
#
# SPDX-License-Identifier: LicenseRef-Atmosic

zephyr_include_directories(.)
zephyr_sources_ifdef(CONFIG_ATM_ASM atm_asm.c)
zephyr_compile_definitions(CFG_S_MAX_ENTRY=CONFIG_ATM_ASM_MAX_ENTRY)
