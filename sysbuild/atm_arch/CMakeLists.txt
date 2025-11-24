# Copyright (c) 2025 Atmosic
#
# SPDX-License-Identifier: Apache-2.0

# Include the atm_arch helper functions
include(${CMAKE_CURRENT_LIST_DIR}/../cmake/atm_arch.cmake)

if(NOT DEFINED PYTHON_EXECUTABLE)
  message(FATAL_ERROR "PYTHON_EXECUTABLE not found")
endif()

execute_process(
  COMMAND ${PYTHON_EXECUTABLE} --version
  OUTPUT_VARIABLE py_version
  ERROR_VARIABLE py_version_err
  RESULT_VARIABLE py_version_output_result
)

if(NOT "${py_version_output_result}" STREQUAL "0")
  message(FATAL_ERROR "Checking Python version error: ${py_version_err}")
endif()

if("${py_version}" MATCHES "3.11")
  message(FATAL_ERROR "Python version ${py_version} not support west atm_arch, suggest to use python 3.10 or 3.12 or -DSB_CONFIG_ATM_ARCH=n to disable sysbuild to generate atm file by default")
endif()

# Create the atm_arch target at the sysbuild level
# The atm_arch script file is generated during each image's configuration
# This target ensures the script runs after all images are built
atm_arch_get_script_filename("${CMAKE_BINARY_DIR}" atm_arch_sh_file)

set(ATM_ARCH_OUTPUT ${CMAKE_BINARY_DIR}/${BOARD}_${DEFAULT_IMAGE}.atm)

# Build the list of image dependencies
# The atm_arch target must depend on ALL images that contribute binaries
set(ATM_ARCH_IMAGE_DEPS ${DEFAULT_IMAGE})

# Add mcuboot dependency if enabled
if(SB_CONFIG_BOOTLOADER_MCUBOOT)
  list(APPEND ATM_ARCH_IMAGE_DEPS mcuboot)
endif()

# Add spe dependency if enabled and not overridden
if(SB_CONFIG_SPE AND NOT SB_CONFIG_OVERRIDE_NO_SPE)
  list(APPEND ATM_ARCH_IMAGE_DEPS spe)
endif()

# The custom target depends on all images being built
# This ensures mcuboot, spe, and the main app are all built before atm_arch runs
if(CMAKE_HOST_SYSTEM_NAME STREQUAL "Windows")
  add_custom_target(atm_arch ALL
    COMMAND ${atm_arch_sh_file}
    COMMAND west atm_arch -i ${ATM_ARCH_OUTPUT} --show
    COMMENT "Sysbuild generated atm file to ${ATM_ARCH_OUTPUT}"
    DEPENDS ${ATM_ARCH_IMAGE_DEPS}
  )
else()
  add_custom_target(atm_arch ALL
    COMMAND chmod +x ${atm_arch_sh_file}
    COMMAND ${atm_arch_sh_file}
    COMMAND west atm_arch -i ${ATM_ARCH_OUTPUT} --show
    COMMENT "Sysbuild generated atm file to ${ATM_ARCH_OUTPUT}"
    DEPENDS ${ATM_ARCH_IMAGE_DEPS}
  )
endif()
