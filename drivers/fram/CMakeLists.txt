# SPDX-License-Identifier: Apache-2.0

zephyr_syscall_header(
    ${ZEPHYR_OPENAIR_MODULE_DIR}/include/zephyr/drivers/fram.h
)

zephyr_library()

zephyr_library_sources_ifdef(CONFIG_USERSPACE fram_handlers.c)
