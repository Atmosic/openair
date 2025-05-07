# Copyright (c) 2024-2025 Atmosic
#
# SPDX-License-Identifier: Apache-2.0

if(CONFIG_ATM_FMNA_LIB)
  zephyr_include_directories(.)

  zephyr_compile_options(
    -DuECC_ENABLE_VLI_API=1
    -DuECC_SUPPORT_COMPRESSED_POINT=0
    -DuECC_SUPPORT_POINT_ADD
  )

  if(CONFIG_USE_UARP)
    set(UARP _uarp)
  endif()

  if(CONFIG_LOG AND CONFIG_ATM_FMNA_LIB_DEBUG)
    set(DBG _dbg)
  endif()

  zephyr_link_libraries(
    -L${CMAKE_CURRENT_SOURCE_DIR}/${CONFIG_SOC}
    atm_fmna${UARP}${DBG}
  )

endif()
