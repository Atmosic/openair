# Copyright (c) 2026 Atmosic
#
# SPDX-License-Identifier: LicenseRef-Atmosic

zephyr_library_amend()

zephyr_library_sources_ifdef(CONFIG_AUDIO_CODEC_SMA1303 sma1303.c)
zephyr_library_sources_ifdef(CONFIG_DMIC_ATM dmic_atm.c)
