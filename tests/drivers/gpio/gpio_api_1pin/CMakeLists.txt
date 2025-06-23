# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.20.0)

set(OA_APP_DIR tests/drivers/gpio/gpio_api_1pin)

# Ensure that APPLICATION_CONFIG_DIR does not have path errors during
# cross-platform compilation.
cmake_path(CONVERT "$ENV{ZEPHYR_BASE}" TO_CMAKE_PATH_LIST OA_ZEPHYR_BASE)
set(APPLICATION_CONFIG_DIR ${OA_ZEPHYR_BASE}/${OA_APP_DIR})

set(EXTRA_CONF_FILE ${CMAKE_CURRENT_SOURCE_DIR}/prj.conf)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(gpio_api_1pin)

add_subdirectory(${ZEPHYR_BASE}/${OA_APP_DIR} ${OA_APP_DIR})
zephyr_include_directories(${ZEPHYR_BASE}/${OA_APP_DIR}/src)
zephyr_library_sources(test_gpio_get_config.c)
