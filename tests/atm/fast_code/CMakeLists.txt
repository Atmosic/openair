# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.20.0)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(fast_code)

# Add application source code
target_sources(app PRIVATE
    src/main.c
    src/fast_code_test.c
)

# Copy linker snippet to generated include directory
configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/fast_code_snippet.ld
    ${CMAKE_BINARY_DIR}/zephyr/include/generated/snippets-fast-code.ld
    COPYONLY
)
