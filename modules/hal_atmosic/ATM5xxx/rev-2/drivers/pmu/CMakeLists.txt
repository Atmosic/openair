# Copyright (c) 2024-2026 Atmosic
#
# SPDX-License-Identifier: LicenseRef-Atmosic

if(CONFIG_ATM_PMU)
  zephyr_include_directories(.)
  zephyr_sources(pmu.c)
  atm_source_core_file(pmu_core pmu)
endif()
