# Copyright (c) Atmosic 2026
#
# SPDX-License-Identifier: LicenseRef-Atmosic

zephyr_include_directories_ifdef(CONFIG_ATM_ATVV .)
zephyr_sources_ifdef(CONFIG_ATM_ATVV atvv.c)
