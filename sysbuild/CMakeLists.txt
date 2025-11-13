# Copyright (c) 2024-2025 Atmosic
#
# SPDX-License-Identifier: Apache-2.0

# Include sysbuild module.
sysbuild_add_subdirectory(module)

# Include SPE if enabled.
if(SB_CONFIG_SPE AND NOT SB_CONFIG_OVERRIDE_NO_SPE)
  sysbuild_add_subdirectory(spe)
endif()

# Include ATM_ARCH if enabled.
if(SB_CONFIG_ATM_ARCH)
  sysbuild_add_subdirectory(atm_arch)
endif()
