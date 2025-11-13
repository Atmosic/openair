# Copyright (c) 2023-2025 Atmosic
#
# SPDX-License-Identifier: Apache-2.0

add_subdirectory(atm_otp)
add_subdirectory(atm_vendor_drv)
add_subdirectory(at_tz_ppc)
add_subdirectory(ble)
add_subdirectory(brwnout)
add_subdirectory(hw_cfg)
add_subdirectory(key_sideload)
add_subdirectory(lpc_rcos)
add_subdirectory(pinmux)
add_subdirectory(pmu)
add_subdirectory(pseq)
add_subdirectory(radio_hal_154)
add_subdirectory(radio_req_154)
add_subdirectory(rf)
add_subdirectory(sec_counter)
add_subdirectory(sec_dev_lockout)
add_subdirectory(sec_hw_cfg)
add_subdirectory(sec_jrnl)
add_subdirectory(spi)

zephyr_include_directories(
    rep_vec
    timer
    trng
)

if(CONFIG_ATM_ATLC OR CONFIG_DTOP_BYPASS OR CONFIG_ENTROPY_ATM_TRNG OR CONFIG_PM OR CONFIG_ATM_BROWNOUT)
    zephyr_sources(
	rep_vec/rep_vec.c
    )
endif()
