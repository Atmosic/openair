# Copyright (c) 2023-2025 Atmosic
#
# SPDX-License-Identifier: Apache-2.0

add_subdirectory(atm_otp)
add_subdirectory(atm_vendor_drv)
add_subdirectory(at_tz_ppc)
add_subdirectory(ble)
add_subdirectory(brwnout)
add_subdirectory(fixed_atmwstk)
add_subdirectory(hw_cfg)
add_subdirectory(key_sideload)
add_subdirectory(lpc_rcos)
add_subdirectory(pinmux)
add_subdirectory(pmu)
add_subdirectory(pseq)
add_subdirectory(rf)
add_subdirectory(sec_counter)
add_subdirectory(sec_dev_lockout)
add_subdirectory(sec_hw_cfg)
add_subdirectory(sec_jrnl)
add_subdirectory(spi)
add_subdirectory(workarounds)

zephyr_include_directories(
  reg
  rep_vec
  timer
  trng
)
