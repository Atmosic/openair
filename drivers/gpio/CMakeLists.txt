# Copyright (c) 2025-2026 Atmosic
# SPDX-License-Identifier: LicenseRef-Atmosic

zephyr_library_amend()

zephyr_library_sources_ifdef(CONFIG_GPIO_ATM gpio_atm.c)
zephyr_library_sources_ifdef(CONFIG_GPIO_KTS162X gpio_kts162x.c)
