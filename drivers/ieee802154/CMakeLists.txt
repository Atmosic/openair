# SPDX-License-Identifier: Apache-2.0

zephyr_library_amend()

zephyr_library_sources_ifdef(CONFIG_IEEE802154_ATM34 ieee802154_atm34.c)
