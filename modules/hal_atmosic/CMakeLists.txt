# Copyright (c) 2024-2025 Atmosic
#
# SPDX-License-Identifier: Apache-2.0

zephyr_include_directories(include)

add_subdirectory_ifdef(CONFIG_SOC_ATM33XX_5 ATM33xx-5)
add_subdirectory_ifdef(CONFIG_SOC_SERIES_ATM34 ATM34xx)

add_subdirectory(drivers)
