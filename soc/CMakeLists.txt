# Copyright (c) 2025-2026 Atmosic
#
# SPDX-License-Identifier: LicenseRef-Atmosic

if(SOC_FAMILY)
  add_subdirectory(${SOC_FAMILY})
else()
  add_subdirectory(${SOC_NAME})
endif()
