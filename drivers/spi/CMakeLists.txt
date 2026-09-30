# Copyright (c) 2025-2026 Atmosic
# SPDX-License-Identifier: LicenseRef-Atmosic

zephyr_library_amend()

zephyr_library_include_directories(${ZEPHYR_BASE}/drivers/spi)

zephyr_library_sources_ifdef(CONFIG_SPI_ATM spi_atm.c)
