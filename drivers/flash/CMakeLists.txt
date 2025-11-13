# SPDX-License-Identifier: Apache-2.0

zephyr_library_amend()

zephyr_library_sources_ifdef(CONFIG_SOC_FLASH_ATM flash_atm.c)
zephyr_library_sources_ifdef(CONFIG_SOC_FLASH_ATM_RRAM flash_atm_rram.c)

if(CONFIG_SOC_FLASH_ATM OR CONFIG_SOC_FLASH_ATM_RRAM)
  zephyr_library_include_directories(.)
  zephyr_library_sources(flash_atm_memops.c)
endif()
