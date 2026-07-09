# Copyright (c) 2024-2026 Atmosic
#
# SPDX-License-Identifier: Apache-2.0

if(CONFIG_ATM_FMNA)
  zephyr_include_directories(.)

  zephyr_library()
  zephyr_library_sources(atm_fmna_gatt.c)
endif()

if(CONFIG_ATM_FMNA_LIB)
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
