# Copyright (c) 2024-2026 Atmosic
#
# SPDX-License-Identifier: LicenseRef-Atmosic

zephyr_include_directories(.)

if(CONFIG_ATM_PMU)
  zephyr_sources(pmu.c)
  atm_source_core_file(pmu_core pmu)
endif()
