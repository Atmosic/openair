# SPDX-License-Identifier: Apache-2.0

# zephyr-keep-sorted-start
add_subdirectory_ifdef(CONFIG_ADC adc)
add_subdirectory_ifdef(CONFIG_AUDIO audio)
add_subdirectory_ifdef(CONFIG_ENTROPY_GENERATOR entropy)
add_subdirectory_ifdef(CONFIG_FLASH flash)
add_subdirectory_ifdef(CONFIG_FRAM fram)
add_subdirectory_ifdef(CONFIG_GPIO gpio)
add_subdirectory_ifdef(CONFIG_HWINFO hwinfo)
add_subdirectory_ifdef(CONFIG_I2C i2c)
add_subdirectory_ifdef(CONFIG_I2S i2s)
add_subdirectory_ifdef(CONFIG_KSCAN kscan)
add_subdirectory_ifdef(CONFIG_PWM pwm)
add_subdirectory_ifdef(CONFIG_SENSOR sensor)
add_subdirectory_ifdef(CONFIG_SERIAL serial)
add_subdirectory_ifdef(CONFIG_SPI spi)
# zephyr-keep-sorted-stop
