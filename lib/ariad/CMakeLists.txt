# Copyright (c) 2026 Atmosic
#
# SPDX-License-Identifier: LicenseRef-Atmosic

if(CONFIG_ATM_ARIAD_LIB)
  set(ATM_ARIAD_LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/${CONFIG_SOC})
  if(NOT EXISTS ${ATM_ARIAD_LIB_DIR}/lib/libariad.a)
    message(FATAL_ERROR "RREQ_USE_ARIAD: ${ATM_ARIAD_LIB_DIR}/lib/libariad.a does not exist.")
  endif()
  zephyr_include_directories(${ATM_ARIAD_LIB_DIR}/include)
  zephyr_link_libraries(-L${ATM_ARIAD_LIB_DIR}/lib)
  zephyr_link_libraries(ariad)
endif()
