# Copyright (c) 2025 Atmosic
#
# SPDX-License-Identifier: Apache-2.0

function(atm_arch_get_sb_config filename config_key output_var)
  if(NOT EXISTS "${filename}")
    message(WARNING "File '${filename}' does not exist.")
    set(${output_var} "" PARENT_SCOPE)
    return()
  endif()

  # Read the file line by line
  file(STRINGS "${filename}" file_contents)
  foreach(line IN LISTS file_contents)
    if(line MATCHES "^${config_key}=(.*)")
      set(${output_var} "${CMAKE_MATCH_1}" PARENT_SCOPE)
      return()
    endif()
  endforeach()

  # If the key is not found, set output_var to an empty string
  set(${output_var} "" PARENT_SCOPE)
endfunction()

function(atm_arch_sh_update)
  if(NOT EXISTS ${atm_arch_sh_file})
    file(APPEND ${atm_arch_sh_file} "west atm_arch")
  endif()
  file(APPEND ${atm_arch_sh_file} " ${ARGN}")
endfunction(atm_arch_sh_update)

function(atm_arch_sh_done)
  if(NOT "${CONFIG_SOC_SERIES}" STREQUAL "ATMx2")
    atm_arch_get_sb_config("${sysbuild_output_dir}/zephyr/.config" "SB_CONFIG_ATM_ARCH_ERASE_ALL" SB_CONFIG_ATM_ARCH_ERASE_ALL)
    if(SB_CONFIG_ATM_ARCH_ERASE_ALL)
      atm_arch_sh_update("--erase_all")
    endif()
    atm_arch_get_sb_config("${sysbuild_output_dir}/zephyr/.config" "SB_CONFIG_ATM_ARCH_ERASE_FLASH_ALL" SB_CONFIG_ATM_ARCH_ERASE_FLASH_ALL)
    if(SB_CONFIG_ATM_ARCH_ERASE_FLASH_ALL)
      atm_arch_sh_update("--erase_flash_all")
    endif()
    atm_arch_get_sb_config("${sysbuild_output_dir}/zephyr/.config" "SB_CONFIG_ATM_ARCH_ERASE_RRAM_ALL" SB_CONFIG_ATM_ARCH_ERASE_RRAM_ALL)
    if(SB_CONFIG_ATM_ARCH_ERASE_RRAM_ALL)
      atm_arch_sh_update("--erase_rram_all")
    endif()
  endif()
  set(ATM_ARCH_NAME_NAME ${sysbuild_output_dir}/${BOARD}_${sysbuild_name}.atm)
  atm_arch_sh_update("-o")
  atm_arch_sh_update("${ATM_ARCH_NAME_NAME}\n")
  set(ATM_ARCH_TARGET zephyr_final)
  if(CMAKE_HOST_SYSTEM_NAME STREQUAL "Windows")
    add_custom_command(
      OUTPUT ${ATM_ARCH_NAME_NAME}
      COMMAND ${atm_arch_sh_file}
      COMMAND west atm_arch -i ${ATM_ARCH_NAME_NAME} --show
      COMMENT "Sysbuild generated atm file to ${ATM_ARCH_NAME_NAME}"
      DEPENDS ${ATM_ARCH_TARGET} ${atm_arch_sh_file}
    )
  else()
    add_custom_command(
      OUTPUT ${ATM_ARCH_NAME_NAME}
      COMMAND chmod +x ${atm_arch_sh_file}
      COMMAND bash ${atm_arch_sh_file}
      COMMAND west atm_arch -i ${ATM_ARCH_NAME_NAME} --show
      COMMENT "Sysbuild generated atm file to ${ATM_ARCH_NAME_NAME}"
      DEPENDS ${ATM_ARCH_TARGET} ${atm_arch_sh_file}
    )
  endif()
  add_custom_target(atm_arch ALL DEPENDS ${ATM_ARCH_NAME_NAME})
endfunction(atm_arch_sh_done)

function(atm_arch_sh_gen)
  file(REAL_PATH "${CMAKE_BINARY_DIR}/.." sysbuild_output_dir)
  atm_arch_get_sb_config("${sysbuild_output_dir}/zephyr/.config" "SB_CONFIG_ATM_ARCH" SB_CONFIG_ATM_ARCH)
  if(NOT SB_CONFIG_ATM_ARCH)
    return()
  endif()
  get_property(sysbuild_name TARGET sysbuild_cache PROPERTY SYSBUILD_NAME)
  get_property(sysbuild_main_app TARGET sysbuild_cache PROPERTY SYSBUILD_MAIN_APP)
  if(CMAKE_HOST_SYSTEM_NAME STREQUAL "Windows")
    set(atm_arch_sh_file ${sysbuild_output_dir}/atm_arch_gen.bat CACHE INTERNAL "atm_arch script file")
  else()
    set(atm_arch_sh_file ${sysbuild_output_dir}/atm_arch_gen.sh CACHE INTERNAL "atm_arch script file")
  endif()
  if("${sysbuild_name}" STREQUAL "mcuboot")
    atm_arch_sh_update("--mcuboot_file=${ZEPHYR_BINARY_DIR}/zephyr.bin")
  elseif("${sysbuild_name}" STREQUAL "spe")
    if(NOT CONFIG_BOOTLOADER_MCUBOOT)
      set(GLOBAL_ATM_ARCH_ARGS CACHE INTERNAL "Global atm file list args")
      atm_arch_sh_update("--spe_file=${ZEPHYR_BINARY_DIR}/zephyr.bin")
    endif()
  else()
    if(CONFIG_ATM_SPLIT_IMG)
      if(CONFIG_BOOTLOADER_MCUBOOT)
          atm_arch_sh_update("--app_file=${ZEPHYR_BINARY_DIR}/zephyr.signed.flash.bin")
          atm_arch_sh_update("--spe_file=${ZEPHYR_BINARY_DIR}/zephyr.signed.bin")
      else()
          atm_arch_sh_update("--atmwstk_file=${ZEPHYR_BINARY_DIR}/zephyr.rram.bin")
          atm_arch_sh_update("--app_file=${ZEPHYR_BINARY_DIR}/zephyr.flash.bin")
      endif()
    else()
      if(CONFIG_BOOTLOADER_MCUBOOT)
        atm_arch_sh_update("--app_file=${ZEPHYR_BINARY_DIR}/zephyr.signed.bin")
      else()
        atm_arch_sh_update("--app_file=${ZEPHYR_BINARY_DIR}/zephyr.bin")
      endif()
      if(CONFIG_USE_ATMWSTK)
        atm_arch_sh_update("--atmwstk_file=${ZEPHYR_BINARY_DIR}/atmwstk_${CONFIG_ATMWSTK}.bin")
      endif()
    endif()
    if(CONFIG_ATM_MCUBOOT_SECURE_DEBUG)
      atm_arch_sh_update("--sec_dbg_enable")
      if(NOT CONFIG_ATM_SEC_DEBUG_AUTH_SIGNATURE_KEY_FILE STREQUAL "")
        file(REAL_PATH ${CONFIG_ATM_SEC_DEBUG_AUTH_SIGNATURE_KEY_FILE} debug_key_file)
        atm_arch_sh_update("--sec_dbg_key=${debug_key_file}")
      endif()
    endif()
    if(EXISTS "${CONFIG_GEN_TAG_DATA_BIN_FILE_SCRIPT}")
      if(EXISTS "${CMAKE_SOURCE_DIR}/tag_data/settings.yml")
        atm_arch_sh_update("--storage_data_file=${ZEPHYR_BINARY_DIR}/zephyr_settings.bin")
      endif()
      if(EXISTS "${CMAKE_SOURCE_DIR}/tag_data/factory.yml")
        atm_arch_sh_update("--factory_data_file=${ZEPHYR_BINARY_DIR}/zephyr_factory.bin")
      endif()
    endif()
    atm_arch_sh_update("--partition_info_file=${ZEPHYR_BINARY_DIR}/partition_info.map")
    atm_arch_sh_done()
  endif()
endfunction(atm_arch_sh_gen)
