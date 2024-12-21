# Copyright (c) 2023-2024 Atmosic
#
# SPDX-License-Identifier: Apache-2.0

add_subdirectory(atm_aes)
add_subdirectory(atm_otp)
add_subdirectory(atm_sha2)
add_subdirectory(atmwstk)
add_subdirectory(at_tz_mpc)
add_subdirectory(at_tz_ppc)
add_subdirectory(at_tz_sau)
add_subdirectory(batt_model_hsc_liion)
add_subdirectory(brwnout)
add_subdirectory(hw_cfg)
add_subdirectory(lpc)
add_subdirectory(pmu)
add_subdirectory(pseq)
add_subdirectory(reset)
add_subdirectory(rf)
add_subdirectory(rram_rom_prot)
add_subdirectory(sec_cache)
add_subdirectory(sec_counter)
add_subdirectory(sec_debug)
add_subdirectory(sec_dev_lockout)
add_subdirectory(sec_hw_cfg)
add_subdirectory(sec_jrnl)
add_subdirectory(sec_reset)
add_subdirectory(spi)
add_subdirectory(workarounds)

zephyr_include_directories(
    reg
)

if (CONFIG_ATM_PLF_DEBUG)
    zephyr_compile_definitions(
	CFG_PLF_DEBUG
    )
    zephyr_sources(
	user_debug.c
    )
endif ()

if (CONFIG_ATM_UECC)
    zephyr_include_directories(
	${ZEPHYR_BASE}/../modules/crypto/micro-ecc
    )
endif ()

if (CONFIG_ATM_AES_HW OR CONFIG_ATM_SHA2_HW OR CONFIG_ATM_UECC)
    zephyr_include_directories(
	../config
    )
    zephyr_link_libraries(mbedTLS)
endif ()

if (CONFIG_ADC OR CONFIG_BT OR CONFIG_ENTROPY_ATM_TRNG OR CONFIG_PM)
    assert(CONFIG_ATM_ARM_FIRMWARE_USES_SECURE_ENTRY_FUNCS "Must provide NSC functions")
endif ()

if (CONFIG_BT OR CONFIG_ENTROPY_ATM_TRNG)
    add_subdirectory(ble)
endif ()
