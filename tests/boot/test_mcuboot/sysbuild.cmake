# Copyright (c) 2026 Atmosic
#
## SPDX-License-Identifier: LicenseRef-Atmosic
#
# This is a local version of the sysbuild.cmake from
# zephyr/tests/boot/test_mcuboot, modified to use our local swapped_app
# which contains a custom Kconfig.

cmake_minimum_required(VERSION 3.20.0)

# Add the mcuboot key file to the secondary swapped app
# This must be done here to ensure that the same key file is used for signing
# both the primary and secondary apps
set(swapped_app_CONFIG_MCUBOOT_SIGNATURE_KEY_FILE
    \"${SB_CONFIG_BOOT_SIGNATURE_KEY_FILE}\" CACHE STRING
    "Signature key file for signing" FORCE)

# Add the swapped app to the build - use LOCAL swapped_app with custom Kconfig
ExternalZephyrProject_Add(
  APPLICATION swapped_app
  SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR}/swapped_app
)

# This section ensures that sysbuild-related configurations, such as the MCUBOOT swap type,
# are passed down to the swapped_app image.
set_target_properties(swapped_app PROPERTIES
  IMAGE_CONF_SCRIPT ${ZEPHYR_BASE}/share/sysbuild/image_configurations/MAIN_image_default.cmake
)

# Ensure swapped_app is built after spe
if(SB_CONFIG_SPE)
  add_dependencies(swapped_app spe)
  sysbuild_add_dependencies(CONFIGURE swapped_app spe)

  # Set SPE_PATH so swapped_app links against libentryveneers.a
  set(sysbuild_spe_path "${CMAKE_BINARY_DIR}/spe")
  set_property(TARGET swapped_app APPEND_STRING PROPERTY CONFIG "CONFIG_SPE_PATH=\"${sysbuild_spe_path}\"\n")
endif()

# Add the swapped app to the list of images to flash
# Ensure the flashing order of images is as follows:
# - mcuboot
# - swapped app
# - primary app (test_mcuboot)
# This order means that if the debugger resets the MCU in between flash
# iterations, the MCUBoot swap won't be triggered until the secondary app
# is actually present in flash.
sysbuild_add_dependencies(FLASH test_mcuboot swapped_app)
sysbuild_add_dependencies(FLASH swapped_app mcuboot)
