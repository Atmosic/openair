# Copyright (c) 2024-2025 Atmosic
#
# SPDX-License-Identifier: Apache-2.0

if(CONFIG_ATM_PMU)
  zephyr_include_directories(.)
  zephyr_sources(pmu.c)
  atm_source_core_file(pmu_core pmu)
endif()
