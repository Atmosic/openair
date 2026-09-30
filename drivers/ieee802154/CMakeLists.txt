# Copyright (c) 2025-2026 Atmosic
# SPDX-License-Identifier: LicenseRef-Atmosic

zephyr_library_amend()

zephyr_library_sources_ifdef(CONFIG_IEEE802154_ATM34 ieee802154_atm34.c)
