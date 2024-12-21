# Copyright (c) 2024 Atmosic
#
# SPDX-License-Identifier: Apache-2.0

# Include SPE if enabled.
if(SB_CONFIG_SPE)
  sysbuild_add_subdirectory(spe)
endif()
