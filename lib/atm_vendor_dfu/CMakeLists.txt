# Copyright (c) 2026 Atmosic
#
# SPDX-License-Identifier: Apache-2.0

if(CONFIG_ATM_VENDOR_DFU)
  zephyr_include_directories(.)
  zephyr_sources(atm_vendor_dfu.c)
endif()

# CMake helper exposed to applications regardless of CONFIG_ATM_VENDOR_DFU
# so the post-build packing step can be invoked even by applications that drive
# the upgrade flow from a different module.
#
# atm_pack_combined_image(IMG0 <path> IMG1 <path> OUTPUT <path>)
#   IMG0    Path to the Image 0 signed binary (RRAM slot).
#   IMG1    Path to the Image 1 signed binary (External Flash slot).
#   OUTPUT  Path to the combined "ATMX" binary to produce.
#
# The function registers a custom command/target that depends on zephyr_final
# so signing is guaranteed to have completed before packing.
function(atm_pack_combined_image)
  cmake_parse_arguments(ACI "" "IMG0;IMG1;OUTPUT" "" ${ARGN})
  if(NOT ACI_IMG0 OR NOT ACI_IMG1 OR NOT ACI_OUTPUT)
    message(FATAL_ERROR
      "atm_pack_combined_image: IMG0, IMG1 and OUTPUT are all required")
  endif()

  set(_pack_script
    "${CMAKE_CURRENT_FUNCTION_LIST_DIR}/scripts/pack_combined_image.py")
  if(NOT EXISTS "${_pack_script}")
    message(FATAL_ERROR
      "atm_pack_combined_image: script not found at ${_pack_script}")
  endif()

  add_custom_command(
    OUTPUT ${ACI_OUTPUT}
    COMMAND ${PYTHON_EXECUTABLE} ${_pack_script}
      ${ACI_IMG0} ${ACI_IMG1}
      -o ${ACI_OUTPUT}
    DEPENDS zephyr_final
    COMMENT "Packing combined-image OTA binary: ${ACI_OUTPUT}"
  )
  add_custom_target(atm_combined_image_pack ALL DEPENDS ${ACI_OUTPUT})
  message(STATUS "Combined-image OTA pack enabled: ${ACI_OUTPUT}")
endfunction()

# Auto-invoke the packing helper for split-image MCUboot applications that
# enable vendor DFU. Applications that need custom paths or a different output
# filename can call atm_pack_combined_image() explicitly instead of relying on
# this default.
if(CONFIG_ATM_VENDOR_DFU AND CONFIG_ATM_SPLIT_IMG
   AND CONFIG_BOOTLOADER_MCUBOOT AND CONFIG_BUILD_OUTPUT_BIN)
  atm_pack_combined_image(
    IMG0   ${ZEPHYR_BINARY_DIR}/${KERNEL_NAME}.signed.bin
    IMG1   ${ZEPHYR_BINARY_DIR}/${KERNEL_NAME}.signed.flash.bin
    OUTPUT ${ZEPHYR_BINARY_DIR}/combined_fw_upd.bin
  )
endif()
