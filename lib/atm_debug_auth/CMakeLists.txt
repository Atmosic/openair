# Copyright (c) 2017 Open Source Foundries Limited
# Copyright (c) 2024 Atmosic
#
# SPDX-License-Identifier: Apache-2.0

if(CONFIG_ATM_SEC_DEBUG_AUTH)
    zephyr_include_directories(.)
    zephyr_sources(atm_debug_auth.c)

    if(NOT CONFIG_ATM_SEC_DEBUG_AUTH_SIGNATURE_KEY_FILE STREQUAL "")
        get_filename_component(BOOT_DIR ${APPLICATION_SOURCE_DIR} DIRECTORY)
        # Path to top-level repository root directory.
        get_filename_component(MCUBOOT_DIR ${BOOT_DIR} DIRECTORY)
	if(IS_ABSOLUTE ${CONFIG_ATM_SEC_DEBUG_AUTH_SIGNATURE_KEY_FILE})
	    set(DEBUG_KEY_FILE ${CONFIG_ATM_SEC_DEBUG_AUTH_SIGNATURE_KEY_FILE})
	elseif((DEFINED ZEPHYR_BASE) AND
            (EXISTS ${CMAKE_CURRENT_LIST_DIR}/${CONFIG_ATM_SEC_DEBUG_AUTH_SIGNATURE_KEY_FILE}))
            set(DEBUG_KEY_FILE ${CMAKE_CURRENT_LIST_DIR}/${CONFIG_ATM_SEC_DEBUG_AUTH_SIGNATURE_KEY_FILE})
        else()
            set(DEBUG_KEY_FILE ${ZEPHYR_BASE}/../${CONFIG_ATM_SEC_DEBUG_AUTH_SIGNATURE_KEY_FILE})
        endif()
        message("MCUBoot debug key file: ${DEBUG_KEY_FILE}")
	get_filename_component(default_key_path ${CMAKE_CURRENT_LIST_DIR}/root-debug-ec-p256.pem REALPATH)
	get_filename_component(chosen_key_path ${DEBUG_KEY_FILE} REALPATH)

	if(default_key_path STREQUAL chosen_key_path)
	    message(WARNING "Secure debug is built using the development key. This key is widely distributed and should NEVER be used for production.")
	endif()
        set(GENERATED_DEBUG_PUBKEY ${ZEPHYR_BINARY_DIR}/autogen-pubkey-debug.c)
        add_custom_command(
            OUTPUT ${GENERATED_DEBUG_PUBKEY}
            COMMAND
            ${PYTHON_EXECUTABLE}
            ${MCUBOOT_DIR}/scripts/imgtool.py
            getpub
            -k
            ${DEBUG_KEY_FILE}
            -n secure_debug_key
            > ${GENERATED_DEBUG_PUBKEY}
            DEPENDS ${DEBUG_KEY_FILE}
        )
	zephyr_library_named(debug_auth_key)
	zephyr_library_sources(${GENERATED_DEBUG_PUBKEY})
	add_dependencies(app debug_auth_key)
    else()
	message( FATAL_ERROR "CONFIG_ATM_SEC_DEBUG_AUTH_SIGNATURE_KEY_FILE must be set if enabling secure debug." )
    endif()
endif()

