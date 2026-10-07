# Copyright (c) 2026 Atmosic
#
## SPDX-License-Identifier: LicenseRef-Atmosic

cmake_minimum_required(VERSION 3.20.0)

set(OA_APP_DIR tests/subsys/random/rng)

# Ensure that APPLICATION_CONFIG_DIR does not have path errors during
# cross-platform compilation.
cmake_path(CONVERT "$ENV{ZEPHYR_BASE}" TO_CMAKE_PATH_LIST OA_ZEPHYR_BASE)
set(APPLICATION_CONFIG_DIR ${OA_ZEPHYR_BASE}/${OA_APP_DIR})

set(APPLICATION_BOARD_DIR ${CMAKE_CURRENT_SOURCE_DIR})

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(rng)

add_subdirectory(${ZEPHYR_BASE}/${OA_APP_DIR} ${OA_APP_DIR})

if(CONFIG_ENTROPY_ATM_TRNG AND NOT CONFIG_BUILD_WITH_TFM)
  target_sources(app PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/main_atm_timing.c)
endif()

if(CONFIG_ENTROPY_ATM_TRNG AND CONFIG_PSA_CSPRNG_GENERATOR AND NOT CONFIG_BUILD_WITH_TFM)
  target_sources(app PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/main_atm_psa.c)
  target_link_options(app PUBLIC
    -Wl,--wrap=psa_generate_random
    -Wl,--wrap=mbedtls_ctr_drbg_random
    -Wl,--wrap=mbedtls_platform_get_entropy
    -Wl,--wrap=z_impl_sys_rand_get
  )
endif()
