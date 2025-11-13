# SPDX-License-Identifier: Apache-2.0

# zephyr-keep-sorted-start
add_subdirectory_ifdef(CONFIG_ADC adc)
add_subdirectory_ifdef(CONFIG_ATM_ANTENNA_SWITCH atm_antenna)
add_subdirectory_ifdef(CONFIG_ATM_BUZZER atm_buzzer)
add_subdirectory_ifdef(CONFIG_AUDIO audio)
add_subdirectory_ifdef(CONFIG_ENTROPY_GENERATOR entropy)
add_subdirectory_ifdef(CONFIG_FLASH flash)
add_subdirectory_ifdef(CONFIG_GPIO gpio)
add_subdirectory_ifdef(CONFIG_HWINFO hwinfo)
add_subdirectory_ifdef(CONFIG_I2C i2c)
add_subdirectory_ifdef(CONFIG_I2S i2s)
add_subdirectory_ifdef(CONFIG_IEEE802154 ieee802154)
add_subdirectory_ifdef(CONFIG_INPUT input)
add_subdirectory_ifdef(CONFIG_PINCTRL pinctrl)
add_subdirectory_ifdef(CONFIG_PWM pwm)
add_subdirectory_ifdef(CONFIG_RETAINED_MEM retained_mem)
add_subdirectory_ifdef(CONFIG_SENSOR sensor)
add_subdirectory_ifdef(CONFIG_SERIAL serial)
add_subdirectory_ifdef(CONFIG_SPI spi)
add_subdirectory_ifdef(CONFIG_WURX wurx)
# zephyr-keep-sorted-stop
