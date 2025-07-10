# SPDX-License-Identifier: Apache-2.0

zephyr_library_amend()

zephyr_library_include_directories(${ZEPHYR_BASE}/drivers/adc)

zephyr_library_sources_ifdef(CONFIG_ADC_ATMx2 adc_atmx2.c)
zephyr_library_sources_ifdef(CONFIG_ADC_ATMx3 adc_atmx3.c)
zephyr_library_sources_ifdef(CONFIG_ADC_ATM34 adc_atm34.c)
