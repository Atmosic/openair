# Copyright (c) 2025-2026 Atmosic
# SPDX-License-Identifier: LicenseRef-Atmosic

zephyr_library_amend()

zephyr_library_sources_ifdef(CONFIG_I2S_ATM i2s_atm.c)

zephyr_include_directories_ifdef(CONFIG_I2S_ATM .)
