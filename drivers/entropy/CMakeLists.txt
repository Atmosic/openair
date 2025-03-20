# SPDX-License-Identifier: Apache-2.0

zephyr_library_amend()

zephyr_library_sources_ifdef(CONFIG_ENTROPY_ATM_TRNG entropy_atm.c)
