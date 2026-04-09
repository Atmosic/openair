# Copyright (c) 2024-2026 Atmosic
#
# SPDX-License-Identifier: LicenseRef-Atmosic
#

zephyr_include_directories_ifdef(CONFIG_ATM_AES .)
zephyr_sources_ifdef(CONFIG_ATM_AES_ATM_CORE atm_aes.c)
zephyr_sources_ifdef(CONFIG_ATM_AES_HW aes_alt.c)
