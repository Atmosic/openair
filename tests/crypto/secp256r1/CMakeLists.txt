# Copyright (c) 2026 Atmosic
#
## SPDX-License-Identifier: LicenseRef-Atmosic

cmake_minimum_required(VERSION 3.20.0)

set(OA_APP_DIR tests/crypto/secp256r1)

# Ensure that APPLICATION_CONFIG_DIR does not have path errors during
# cross-platform compilation.
cmake_path(CONVERT "$ENV{ZEPHYR_BASE}" TO_CMAKE_PATH_LIST OA_ZEPHYR_BASE)
set(APPLICATION_CONFIG_DIR ${OA_ZEPHYR_BASE}/${OA_APP_DIR})

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(secp256r1)

add_subdirectory(${ZEPHYR_BASE}/${OA_APP_DIR} ${OA_APP_DIR})

# Append an openair-local ZTEST case to the upstream secp256r1 test
# suite to exercise the Atmosic uECC PSA driver's sign/verify path.
target_sources(app PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/main_atm.c)
