# Copyright (c) 2025 Atmosic
#
# SPDX-License-Identifier: Apache-2.0

if(CONFIG_BT_RAS)
  zephyr_include_directories(include)
  zephyr_sources(ras.c)
endif()

if(CONFIG_BT_RAS_CLIENT)
  zephyr_include_directories(include)
  zephyr_sources(ras_client.c)
endif()
