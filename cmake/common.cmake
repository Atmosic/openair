# Code coverage
if(CONFIG_COVERAGE AND CONFIG_AUTO_TEST)
  # Reset coverage properties
  set_compiler_property(PROPERTY no_coverage -fno-profile-arcs -fno-test-coverage -finline)
  zephyr_compile_options($<TARGET_PROPERTY:compiler,no_coverage>)

  # app target
  set_property(TARGET app APPEND PROPERTY COMPILE_OPTIONS -fno-profile-arcs -fno-test-coverage -finline)

  # library source files
  function(set_coverage_properties_for_files file_list patterns_list)
    foreach(pattern IN LISTS ${patterns_list})
        foreach(file IN LISTS ${file_list})
            get_filename_component(file_name ${file} NAME)
            if(${file_name} MATCHES ${pattern})
                set_source_files_properties(
                    ${file}
                    DIRECTORY ${ZEPHYR_BASE}
                    PROPERTIES COMPILE_OPTIONS $<TARGET_PROPERTY:compiler,coverage>
                )
            endif()
        endforeach()
    endforeach()
  endfunction()
endif()

# Conditionally includes ATM core source files or links precompiled objects
# based on availability and configuration.
#
# This function provides a flexible mechanism for including ATM core files
# in the build process. It first checks if a C source file exists, and if so,
# includes it in the build (subject to configuration). If the source file
# doesn't exist, it falls back to linking a precompiled object file.
#
# Parameters:
#   base_name           - The base filename (without extension) of the core file
#   precompiled_dir     - Directory path where the precompiled object (.po) file is located,
#                         relative to PRECOMPILED_DRIVER_DIR.
#   options             - Optional. If specified as "FAST", locates precompiled object into memory
#                         at RRAM speeds or faster. Must be specified along with precompiled_dir
#
# Configuration Dependencies:
#   CONFIG_ATM_BUILD_CORE_C_FILES - Must be enabled to build C source files
function(atm_source_core_file base_name precompiled_dir)
  # Parse options argument if present
  set(use_fast_precompiled FALSE)
  if(ARGC GREATER 2 AND ARGV2 STREQUAL "FAST")
    set(use_fast_precompiled TRUE)
  endif()

  # The core.c file may exist either in the current source directory or the
  # precompiled driver dir
  set(core_c_file "${CMAKE_CURRENT_SOURCE_DIR}/${base_name}.c")
  if(NOT EXISTS ${core_c_file})
    set(core_c_file "${PRECOMPILED_DRIVER_DIR}/${precompiled_dir}/${base_name}.c")
  endif()

  if(EXISTS ${core_c_file})
    if(CONFIG_ATM_BUILD_CORE_C_FILES)
      # Use C source file if present and configured
      zephyr_sources(${core_c_file})
      if(use_fast_precompiled)
	  zephyr_code_relocate(FILES ${core_c_file} LOCATION RAM_TEXT_RODATA NOKEEP)
      endif()
    else()
      message(FATAL_ERROR "CONFIG_ATM_BUILD_CORE_C_FILES is needed to build ${base_name}.c")
    endif()
  elseif(use_fast_precompiled)
    # Call chip-specific helper to locate the object into a faster location
    atm_relocate_fast_core_file(${precompiled_dir} ${base_name}.po)
  else()
    # Use Zephyr's linking helper
    zephyr_link_libraries(
      ${LINKERFLAGPREFIX},${PRECOMPILED_DRIVER_DIR}/${precompiled_dir}/${base_name}.po)
  endif()
endfunction()
