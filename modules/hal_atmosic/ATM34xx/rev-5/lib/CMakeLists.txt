# Copyright (c) 2024 Atmosic
#
# SPDX-License-Identifier: Apache-2.0

if(CONFIG_BT)
    add_subdirectory(blell)
endif()

if(CONFIG_DTOP_BYPASS)
    zephyr_link_libraries(
	-L${CMAKE_CURRENT_SOURCE_DIR}
	-udtop_bypass_init_public
    )

    if(CONFIG_ATM_PLF_DEBUG)
	zephyr_link_libraries(dtop_bypass_dbg)
    else ()
	zephyr_link_libraries(dtop_bypass)
    endif()
endif()
