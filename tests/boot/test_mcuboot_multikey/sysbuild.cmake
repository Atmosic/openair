# Copyright (c) 2026 Atmosic
#
## SPDX-License-Identifier: LicenseRef-Atmosic
#
# This is a test for MCUboot multiple key support.
# It creates a swapped app signed with the second key to test multiple key support.

cmake_minimum_required(VERSION 3.20.0)

# Add the mcuboot key file to the swapped app
# The swapped app will be signed with key 2 to test that MCUboot can verify
# images signed with either key 1 or key 2
set(swapped_app_CONFIG_MCUBOOT_SIGNATURE_KEY_FILE
    \"${SB_CONFIG_BOOT_SIGNATURE_KEY_FILE_2}\" CACHE STRING
    "Signature key file for signing swapped app" FORCE)

# Add the swapped app (signed with key 2)
ExternalZephyrProject_Add(
  APPLICATION swapped_app
  SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR}/swapped_app
)

# Set image configuration
set_target_properties(swapped_app PROPERTIES
  IMAGE_CONF_SCRIPT ${ZEPHYR_BASE}/share/sysbuild/image_configurations/MAIN_image_default.cmake
)

# Ensure proper flashing order
sysbuild_add_dependencies(FLASH test_mcuboot_multikey swapped_app)
sysbuild_add_dependencies(FLASH swapped_app mcuboot)

