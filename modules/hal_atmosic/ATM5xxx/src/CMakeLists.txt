# Copyright (c) 2023-2025 Atmosic
#
# SPDX-License-Identifier: Apache-2.0

zephyr_sources(
  power.c
  soc.c
)

zephyr_sources_ifdef(CONFIG_CPU_HAS_CUSTOM_FIXED_SOC_MPU_REGIONS
  mpu_regions.c
)
