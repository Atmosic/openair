# Copyright (c) 2026 Atmosic
#
## SPDX-License-Identifier: LicenseRef-Atmosic

cmake_minimum_required(VERSION 3.20.0)

set(OA_APP_DIR tests/crypto/mbedtls_psa)

# Ensure that APPLICATION_CONFIG_DIR does not have path errors during
# cross-platform compilation.
cmake_path(CONVERT "$ENV{ZEPHYR_BASE}" TO_CMAKE_PATH_LIST OA_ZEPHYR_BASE)
set(APPLICATION_CONFIG_DIR ${OA_ZEPHYR_BASE}/${OA_APP_DIR})

set(APPLICATION_SOC_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(APPLICATION_BOARD_DIR ${CMAKE_CURRENT_SOURCE_DIR})

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(mbedtls_psa)

add_subdirectory(${ZEPHYR_BASE}/${OA_APP_DIR} ${OA_APP_DIR})

# Append openair-local ZTEST cases to the upstream mbedtls_psa test
# suite that exercise the Atmosic SHA-2 PSA wrapper's clone path.
target_sources(app PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/main_atm.c)

# Append openair-local ZTEST cases that exercise the Atmosic AES PSA
# wrapper's decrypt, AES-256, CTR, and software-fallback paths.
target_sources(app PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/main_atm_aes.c)

# Multithreaded stress tests target the HW-engine synchronization in the
# multi-context wrapper, so they are only compiled in when both the
# multi-context API and Zephyr multithreading are enabled.
if(CONFIG_ATM_SHA2_API_MULTI AND CONFIG_MULTITHREADING)
  target_sources(app PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/main_atm_mt.c)
endif()
