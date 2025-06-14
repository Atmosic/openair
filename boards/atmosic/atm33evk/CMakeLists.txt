# Copyright (c) 2021-2025 Atmosic
#
# SPDX-License-Identifier: Apache-2.0

zephyr_library()
zephyr_library_sources(board.c pinmux.c)

if(CONFIG_TRUSTED_EXECUTION_SECURE)
  zephyr_compile_options(
    -DSECURE_MODE=1
  )
endif()

zephyr_compile_options_ifdef(CONFIG_ATM_NO_SPE -DCFG_NO_SPE=1)

# Import SPE-related configurations
function(import_spe_kconfig prefix kconfig_fragment)
  # Parse the lines prefixed with 'prefix' in ${kconfig_fragment}
  file(
    STRINGS
    ${kconfig_fragment}
    DOT_CONFIG_LIST
    REGEX "^${prefix}"
    ENCODING "UTF-8"
  )

  foreach (CONFIG ${DOT_CONFIG_LIST})
    # CONFIG could look like: CONFIG_NET_BUF=y

    # Match the first part, the variable name
    string(REGEX MATCH "[^=]+" CONF_VARIABLE_NAME ${CONFIG})

    # Match the second part, variable value
    string(REGEX MATCH "=(.+$)" CONF_VARIABLE_VALUE ${CONFIG})
    # The variable name match we just did included the '=' symbol. To just get the
    # part on the RHS we use match group 1
    set(CONF_VARIABLE_VALUE ${CMAKE_MATCH_1})

    if("${CONF_VARIABLE_VALUE}" MATCHES "^\"(.*)\"$") # Is surrounded by quotes
      set(CONF_VARIABLE_VALUE ${CMAKE_MATCH_1})
    endif()

    set("SPE_${CONF_VARIABLE_NAME}" "${CONF_VARIABLE_VALUE}" PARENT_SCOPE)
    list(APPEND keys "${CONF_VARIABLE_NAME}")
  endforeach()

  foreach(outvar ${ARGN})
    set(${outvar} "${keys}" PARENT_SCOPE)
  endforeach()
endfunction()

# Merge SPE and Zephyr app together.
# Strips IDAU bit from SPE to handle signing together
function(merge_spe spe_path spe_load_addr)

  # Extensionless prefix of any output file.
  set(output ${ZEPHYR_BINARY_DIR}/${KERNEL_NAME})

  # List of additional build byproducts.
  set(byproducts)

  set(S_NS_HEX_FILE ${output}.merged.hex)
  set(S_NS_BIN_FILE ${output}.merged.bin)
  list(APPEND byproducts ${S_NS_HEX_FILE})
  list(APPEND byproducts ${S_NS_BIN_FILE})

  set(NS_APP_HEX_FILE ${CMAKE_BINARY_DIR}/zephyr/${KERNEL_HEX_NAME})
  set(S_APP_BIN_FILE ${spe_path}/zephyr/${KERNEL_BIN_NAME})
  set(S_HEX_NO_IDAU_FILE ${spe_path}/zephyr/${KERNEL_NAME}.idau_stripped.hex)
  MATH(EXPR S_ADDR_NO_IDAU "${spe_load_addr} - 0x10000000")

  set_property(GLOBAL APPEND PROPERTY extra_post_build_commands
    COMMAND ${CMAKE_OBJCOPY} ${S_APP_BIN_FILE}
      -I binary -O ihex
      --change-addresses ${S_ADDR_NO_IDAU}
      ${S_HEX_NO_IDAU_FILE}
    COMMAND ${PYTHON_EXECUTABLE} ${ZEPHYR_BASE}/scripts/build/mergehex.py
      -o ${S_NS_HEX_FILE}
      ${S_HEX_NO_IDAU_FILE}
      ${NS_APP_HEX_FILE}
    COMMAND ${CMAKE_OBJCOPY} ${S_NS_HEX_FILE}
      -I ihex -O binary
      ${S_NS_BIN_FILE}
  )

  # makes west flash choose the merged build output of a given type.
  if(CONFIG_BUILD_OUTPUT_BIN)
    set_target_properties(runners_yaml_props_target PROPERTIES "bin_file" "${S_NS_BIN_FILE}")
  endif()
  if(CONFIG_BUILD_OUTPUT_HEX)
    set_target_properties(runners_yaml_props_target PROPERTIES "hex_file" "${S_NS_HEX_FILE}")
  endif()

  if(CONFIG_BOOTLOADER_MCUBOOT)
    # need to rename files to allow 'west sign' to properly handle signing
    list(APPEND
      byproducts
      ${output}.nspe.bin
      ${output}.nspe.elf
      ${output}.nspe.hex
    )

    set_property(GLOBAL APPEND PROPERTY extra_post_build_commands
      COMMAND ${CMAKE_COMMAND} -E copy ${output}.bin ${output}.nspe.bin
      COMMAND ${CMAKE_COMMAND} -E copy ${output}.elf ${output}.nspe.elf
      COMMAND ${CMAKE_COMMAND} -E copy ${output}.hex ${output}.nspe.hex
      COMMAND ${CMAKE_COMMAND} -E copy ${output}.merged.bin ${output}.bin
      COMMAND ${CMAKE_COMMAND} -E copy ${output}.merged.hex ${output}.hex
    )
  endif()

  set_property(GLOBAL APPEND PROPERTY extra_post_build_byproducts ${byproducts})
endfunction()

# Generate partition_info.map
function(atm_partition_info)
  if(EXISTS "${CONFIG_GEN_PARTITION_INFO_SCRIPT}")
    # Extensionless prefix of any output file.
    if(CONFIG_TRUSTED_EXECUTION_NONSECURE AND CONFIG_SPE_PATH)
      set(output_file ${ZEPHYR_BINARY_DIR}/partition_info.map.app)
      set(spe_output_file ${spe_path}/zephyr/partition_info.map)
      set(output_file_merge ${ZEPHYR_BINARY_DIR}/partition_info.map)
    else()
      set(output_file ${ZEPHYR_BINARY_DIR}/partition_info.map)
    endif()
    set(dt_file ${ZEPHYR_BINARY_DIR}/zephyr.dts)
    set(EXT_ARGS)
    if(CONFIG_BOOTLOADER_MCUBOOT)
      list(APPEND EXT_ARGS "--use_mcuboot")
    endif()
    if(CONFIG_BOOT_MAX_IMG_SECTORS)
      list(APPEND EXT_ARGS "--max_sector_size")
      list(APPEND EXT_ARGS "${CONFIG_BOOT_MAX_IMG_SECTORS}")
    endif()
    if(CONFIG_ROM_START_OFFSET)
      list(APPEND EXT_ARGS "--rom_start")
      list(APPEND EXT_ARGS "${CONFIG_ROM_START_OFFSET}")
    endif()
    if(CONFIG_ROM_SIZE)
      list(APPEND EXT_ARGS "--rom_size")
      list(APPEND EXT_ARGS "${CONFIG_ROM_SIZE}")
    endif()
    if(CONFIG_USER_DATA_OFFSET)
      list(APPEND EXT_ARGS "--user_data_offset")
      list(APPEND EXT_ARGS "${CONFIG_USER_DATA_OFFSET}")
    endif()
    if(USER_DATA_SIZE)
      list(APPEND EXT_ARGS "--user_data_size")
      list(APPEND EXT_ARGS "${USER_DATA_SIZE}")
    endif()
    if(CONFIG_MERGE_SPE_NSPE)
      list(APPEND EXT_ARGS "--merge_spe_nspe")
    endif()
    message("Generate Partition Info Map File to ${output_file}")
    set_property(GLOBAL APPEND PROPERTY extra_post_build_commands
      COMMAND ${PYTHON_EXECUTABLE} ${CONFIG_GEN_PARTITION_INFO_SCRIPT} gen -i ${dt_file} -o ${output_file}
        -p ${CONFIG_SOC} -f ${CONFIG_SOC_SERIES} -b ${BOARD} ${EXT_ARGS}
    )
    set_property(GLOBAL APPEND PROPERTY extra_post_build_byproducts ${output_file})
    if(CONFIG_TRUSTED_EXECUTION_NONSECURE AND CONFIG_SPE_PATH)
      message("Merge Partition Info Map File to ${output_file_merge}")
      set_property(GLOBAL APPEND PROPERTY extra_post_build_commands
        COMMAND ${PYTHON_EXECUTABLE} ${CONFIG_GEN_PARTITION_INFO_SCRIPT} merge -i1 ${spe_output_file} -i2 ${output_file} -o ${output_file_merge}
      )
      set_property(GLOBAL APPEND PROPERTY extra_post_build_byproducts ${output_file_merge})
    endif()
  else()
    message("west build can't find ${CONFIG_GEN_PARTITION_INFO_SCRIPT}, ignore generate partition info")
  endif()
endfunction()

# Generate layout_info.map
function(layout_info)
  set(partition_file ${ZEPHYR_BINARY_DIR}/partition_info.map)
  if(EXISTS "${CONFIG_GEN_LAYOUT_INFO_SCRIPT}")
    message("Generate Layout Information File to ${layout_info_file}")
    set_property(GLOBAL APPEND PROPERTY extra_post_build_commands
    COMMAND ${PYTHON_EXECUTABLE} ${CONFIG_GEN_LAYOUT_INFO_SCRIPT} --layout-file ${partition_file} > ${layout_info_file}
    )
    set_property(GLOBAL APPEND PROPERTY extra_post_build_byproducts ${layout_info_file})
  endif()
endfunction()

# Generate tag data bin files
function(atm_generate_tag_data_bin_file)
  if(EXISTS "${CONFIG_GEN_TAG_DATA_BIN_FILE_SCRIPT}")
    set(partition_file ${ZEPHYR_BINARY_DIR}/partition_info.map)
    set(settings_yaml_file ${CMAKE_SOURCE_DIR}/tag_data/settings.yml)
    set(factory_yaml_file ${CMAKE_SOURCE_DIR}/tag_data/factory.yml)
    if(EXISTS "${settings_yaml_file}")
      set_property(GLOBAL APPEND PROPERTY extra_post_build_commands
      COMMAND ${PYTHON_EXECUTABLE} ${CONFIG_GEN_TAG_DATA_BIN_FILE_SCRIPT} -t settings -z ${CONFIG_ZSG_TOOL_PATH} -o ${CMAKE_OBJCOPY} -p ${partition_file} -y ${settings_yaml_file} -b ${ZEPHYR_BINARY_DIR}/zephyr_settings.bin
      )
    else()
      message("ignore generate settings.bin")
    endif()
    if(EXISTS "${factory_yaml_file}")
      set_property(GLOBAL APPEND PROPERTY extra_post_build_commands
      COMMAND ${PYTHON_EXECUTABLE} ${CONFIG_GEN_TAG_DATA_BIN_FILE_SCRIPT} -t factory -z ${CONFIG_ZSG_TOOL_PATH} -o ${CMAKE_OBJCOPY} -p ${partition_file} -y ${factory_yaml_file} -b ${ZEPHYR_BINARY_DIR}/zephyr_factory.bin
      )
    else()
      message("ignore generate factory.bin")
    endif()
  else()
    message("west build can't find 'CONFIG_GEN_TAG_DATA_BIN_FILE_SCRIPT', ignore generate tag data bin file")
  endif()
endfunction()

# copy ATMWSTK file to ZEPHYR_BINARY_DIR and tranfer to bin and hex format
function(atmswstk_image)
  if(NOT CONFIG_ATMWSTK_PATH)
    message(FATAL_ERROR "atmwstk overwrite requires CONFIG_ATMWSTK_PATH")
  endif()
  if(CONFIG_ATMWSTK_PD50)
    set(ATMWSTK_FILENAME "atmwstk_PD50LL")
  elseif(CONFIG_ATMWSTK_FULL)
    set(ATMWSTK_FILENAME "atmwstk_LL")
  else()
    message(DEPRECATION "CONFIG_ATMWSTK will be deprecated in the future, please choose one of CONFIG_ATMWSTK_PD50 or CONFIG_ATMWSTK_FULL.")
    set(ATMWSTK_FILENAME "atmwstk_${CONFIG_ATMWSTK}")
  endif()
  set(ATMWSTK_FILE_PATH "${CONFIG_ATMWSTK_PATH}/${ATMWSTK_FILENAME}.elf")
  if(NOT EXISTS "${ATMWSTK_FILE_PATH}")
    message(FATAL_ERROR "west build can't find ${ATMWSTK_FILE_PATH}")
  endif()
  set(ATMWSTK_ELF ${ZEPHYR_BINARY_DIR}/${ATMWSTK_FILENAME}.elf)
  set(ATMWSTK_BIN ${ZEPHYR_BINARY_DIR}/${ATMWSTK_FILENAME}.bin)
  set(ATMWSTK_HEX ${ZEPHYR_BINARY_DIR}/${ATMWSTK_FILENAME}.hex)
  set_property(GLOBAL APPEND PROPERTY extra_post_build_commands
    COMMAND ${CMAKE_COMMAND} -E copy ${ATMWSTK_FILE_PATH} ${ATMWSTK_ELF}
    COMMAND ${CMAKE_OBJCOPY} ${ATMWSTK_ELF} -O binary ${ATMWSTK_BIN}
    COMMAND ${CMAKE_OBJCOPY} ${ATMWSTK_ELF} -O ihex ${ATMWSTK_HEX}
  )
  set(atmwstk_byproducts)
  list(APPEND atmwstk_byproducts ${ATMWSTK_ELF})
  list(APPEND atmwstk_byproducts ${ATMWSTK_BIN})
  list(APPEND atmwstk_byproducts ${ATMWSTK_HEX})
  set_property(GLOBAL APPEND PROPERTY extra_post_build_byproducts ${atmwstk_byproducts})
endfunction()

# Handle additional atm33 tasks
function(zephyr_atmosic_tasks)
  if(CONFIG_TRUSTED_EXECUTION_NONSECURE AND CONFIG_SPE_PATH)
    set(spe_path "${CONFIG_SPE_PATH}")
    if(NOT IS_ABSOLUTE "${spe_path}")
      # Relative paths are relative to 'west topdir'.
      set(spe_path "${WEST_TOPDIR}/${spe_path}")
    endif()
    if(NOT EXISTS "${spe_path}")
      message(FATAL_ERROR "west build can't find dir ${spe_path} (Note: Relative paths are relative to the west workspace topdir \"${WEST_TOPDIR}\")")
    endif()

    # Extensionless prefix of any output file.
    set(output ${ZEPHYR_BINARY_DIR}/${KERNEL_NAME})
    # Process SPE configs
    set(SPEDOTCONFIG ${spe_path}/zephyr/.config)
    import_spe_kconfig(CONFIG_ ${SPEDOTCONFIG})
    assert(${SPE_CONFIG_TRUSTED_EXECUTION_SECURE} "Error: Application passed as CONFIG_SPE_PATH is not configured as a SPE.")

    # link the veneer library
    zephyr_compile_definitions(CONFIG_ARM_FIRMWARE_USES_SECURE_ENTRY_FUNCS)
    zephyr_link_libraries(${spe_path}/${CONFIG_ATM_ARM_ENTRY_VENEERS_LIB_NAME})

    if(CONFIG_MERGE_SPE_NSPE)
      MATH(EXPR S_LOAD_OFFSET "${SPE_CONFIG_FLASH_BASE_ADDRESS} + ${SPE_CONFIG_FLASH_LOAD_OFFSET}")
      merge_spe(${spe_path} ${S_LOAD_OFFSET})
    endif()
  endif()
  if(CONFIG_USE_ATMWSTK)
    atmswstk_image()
  endif()
  if(CONFIG_GEN_PARTITION_INFO)
    atm_partition_info()
    if(CONFIG_TRUSTED_EXECUTION_NONSECURE)
      set(layout_info_file ${ZEPHYR_BINARY_DIR}/layout.info)
      layout_info()
    endif()
    if(CONFIG_ATM_SETTINGS AND NOT CONFIG_AUTO_TEST)
      atm_generate_tag_data_bin_file()
    endif()
    if(DEFINED SYSBUILD AND SYSBUILD)
      include(${ZEPHYR_OPENAIR_MODULE_DIR}/sysbuild/cmake/atm_arch.cmake)
      atm_arch_sh_gen()
    endif()
  endif()
endfunction()

zephyr_atmosic_tasks()
