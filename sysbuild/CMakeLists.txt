# Copyright (c) 2024-2026 Atmosic
#
# SPDX-License-Identifier: LicenseRef-Atmosic

# Include sysbuild module.
sysbuild_add_subdirectory(module)

# Include SPE if enabled.
if(SB_CONFIG_SPE)
  sysbuild_add_subdirectory(spe)
endif()

# Include ATM_ARCH if enabled.
if(SB_CONFIG_ATM_ARCH)
  sysbuild_add_subdirectory(atm_arch)
endif()
