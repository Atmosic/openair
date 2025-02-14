# Copyright (c) 2024 Atmosic
#
# SPDX-License-Identifier: Apache-2.0

zephyr_include_directories(.)
zephyr_sources_ifdef(CONFIG_ATM_DMA dma.c)
zephyr_compile_definitions_ifdef(CONFIG_ATM_DMA_MINIMAL CFG_DMA_MINIMAL)
