# Copyright (c) Atmosic 2026
#
# SPDX-License-Identifier: LicenseRef-Atmosic

zephyr_include_directories_ifdef(CONFIG_AUDIO_ADPCM_ENC .)
zephyr_sources_ifdef(CONFIG_AUDIO_ADPCM_ENC adpcm_enc.c)
