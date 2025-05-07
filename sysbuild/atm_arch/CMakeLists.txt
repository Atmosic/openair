# Copyright (c) 2025 Atmosic
#
# SPDX-License-Identifier: Apache-2.0

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
