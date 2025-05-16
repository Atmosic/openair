# Copyright (c) 2025 Atmosic
#
# SPDX-License-Identifier: Apache-2.0

if(CONFIG_AUDIO_STREAM)
  zephyr_library()
  zephyr_library_sources(audio_stream.c)
endif()
