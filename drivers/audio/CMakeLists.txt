# SPDX-License-Identifier: Apache-2.0

zephyr_library_amend()

zephyr_library_sources_ifdef(CONFIG_AUDIO_CODEC_SMA1303 sma1303.c)
