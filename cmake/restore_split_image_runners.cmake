# CMake script to restore split image file lists in runners.yaml
# This script modifies the runners.yaml file to use comma-separated file lists
# instead of single files for MCUboot signed binaries.
# This runs as a post-build command after all signing processes are complete.

# Check if the runners.yaml file exists
if(NOT EXISTS "${RUNNERS_YAML_FILE}")
  message(FATAL_ERROR "runners.yaml file not found: ${RUNNERS_YAML_FILE}")
endif()

# Read the current runners.yaml file
file(READ "${RUNNERS_YAML_FILE}" YAML_CONTENT)

message(STATUS "Restoring split image file lists in runners.yaml")
message(STATUS "  RRAM signed bin: ${RRAM_SPLIT_BIN}")
message(STATUS "  Flash signed bin: ${FLASH_SPLIT_BIN}")
message(STATUS "  RRAM signed hex: ${RRAM_SPLIT_HEX}")
message(STATUS "  Flash signed hex: ${FLASH_SPLIT_HEX}")

# Check if the signed files exist (consolidated pattern)
set(FILES_EXIST TRUE)
set(FILE_VARS "RRAM_SPLIT_BIN;FLASH_SPLIT_BIN;RRAM_SPLIT_HEX;FLASH_SPLIT_HEX")
set(FILE_NAMES "RRAM signed bin;Flash signed bin;RRAM signed hex;Flash signed hex")

list(LENGTH FILE_VARS num_files)
math(EXPR max_index "${num_files} - 1")

foreach(i RANGE ${max_index})
  list(GET FILE_VARS ${i} file_var)
  list(GET FILE_NAMES ${i} file_name)

  if(NOT "${${file_var}}" STREQUAL "" AND NOT EXISTS "${${file_var}}")
    message(WARNING "${file_name} file not found: ${${file_var}}")
    set(FILES_EXIST FALSE)
  endif()
endforeach()

if(NOT FILES_EXIST)
  message(WARNING "Some signed files are missing, skipping runners.yaml restoration")
  return()
endif()

# Handle file restoration using consolidated pattern
set(FILE_TYPES "bin;hex")
set(RRAM_FILES "${RRAM_SPLIT_BIN};${RRAM_SPLIT_HEX}")
set(FLASH_FILES "${FLASH_SPLIT_BIN};${FLASH_SPLIT_HEX}")

list(LENGTH FILE_TYPES num_types)
math(EXPR max_type_index "${num_types} - 1")

foreach(i RANGE ${max_type_index})
  list(GET FILE_TYPES ${i} file_type)
  list(GET RRAM_FILES ${i} rram_file)
  list(GET FLASH_FILES ${i} flash_file)

  # Handle files if both RRAM and FLASH files are available
  if(NOT "${rram_file}" STREQUAL "" AND NOT "${flash_file}" STREQUAL "")
    # Create the comma-separated file list
    set(FILE_LIST "${rram_file},${flash_file}")
    message(STATUS "Restoring ${file_type} file list: ${FILE_LIST}")

    # Store original content for validation
    set(ORIGINAL_YAML_CONTENT "${YAML_CONTENT}")

    # Try multiple regex patterns for robustness (most specific to most general)
    set(REPLACEMENT_SUCCESS FALSE)

    # Pattern 1: Standard format with newline prefix (most common)
    string(REGEX REPLACE
      "(^|[\r\n])[ \t]*${file_type}_file:[ \t]*[^\r\n]*"
      "\\1  ${file_type}_file: ${FILE_LIST}"
      YAML_CONTENT "${YAML_CONTENT}")

    # Check if replacement occurred
    if(NOT "${YAML_CONTENT}" STREQUAL "${ORIGINAL_YAML_CONTENT}")
      set(REPLACEMENT_SUCCESS TRUE)
      message(STATUS "Successfully updated ${file_type}_file using standard pattern")
    else()
      # Pattern 2: Fallback - match anywhere in line (less precise but more flexible)
      string(REGEX REPLACE
        "${file_type}_file:[ \t]*[^\r\n]*"
        "${file_type}_file: ${FILE_LIST}"
        YAML_CONTENT "${YAML_CONTENT}")

      if(NOT "${YAML_CONTENT}" STREQUAL "${ORIGINAL_YAML_CONTENT}")
        set(REPLACEMENT_SUCCESS TRUE)
        message(STATUS "Successfully updated ${file_type}_file using fallback pattern")
      endif()
    endif()

    # Validate replacement success
    if(NOT REPLACEMENT_SUCCESS)
      message(WARNING "Failed to update ${file_type}_file in runners.yaml - pattern not found")
      message(STATUS "Searched for: ${file_type}_file: <value>")
    endif()
  endif()
endforeach()

# Write the modified content back to the file
file(WRITE "${RUNNERS_YAML_FILE}" "${YAML_CONTENT}")
file(WRITE "${ATM_SPLIT_HOOK_DONE}" "done")

message(STATUS "Successfully restored split image file lists in runners.yaml")
