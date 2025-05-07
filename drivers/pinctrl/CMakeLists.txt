# SPDX-License-Identifier: Apache-2.0

zephyr_library_amend()

zephyr_library_sources_ifdef(CONFIG_PINCTRL_ATMOSIC_ATM pinctrl_atm.c)
