# Copyright (c) 2024-2025 Atmosic
#
# SPDX-License-Identifier: Apache-2.0

# Include SPE if enabled.
if(SB_CONFIG_SPE)
  sysbuild_add_subdirectory(spe)
endif()

# Include ATM_ARCH if enabled.
if(SB_CONFIG_ATM_ARCH)
  sysbuild_add_subdirectory(atm_arch)
endif()
