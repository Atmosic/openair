# Copyright (c) 2024-2026 Atmosic
#
# SPDX-License-Identifier: LicenseRef-Atmosic

zephyr_include_directories(include)

# Registry for power-down hooks (see power.h).
zephyr_linker_sources_ifdef(CONFIG_ATM_PD SECTIONS pd_prep.ld)
zephyr_linker_sources_ifdef(CONFIG_ATM_PD_POST SECTIONS pd_post.ld)

add_subdirectory_ifdef(CONFIG_SOC_ATM33XX_5 ATM33xx-5)
add_subdirectory_ifdef(CONFIG_SOC_SERIES_ATM34 ATM34xx)
add_subdirectory_ifdef(CONFIG_SOC_SERIES_ATM5 ATM5xxx)

add_subdirectory(drivers)
