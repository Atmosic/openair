Methods to Save Data to External Flash
######################################

This document explores different approaches to saving data in external flash memory using Zephyr's test example applications. Flash memory is a crucial component in embedded systems, allowing for persistent data storage across power cycles. Zephyr provides several built-in subsystems and APIs to facilitate seamless data logging and storage management. This document highlights two specific Zephyr test examples that demonstrate best practices for utilizing external flash storage.

log_backend_fs
==============

Zephyr provides a flexible and configurable logging subsystem that supports multiple backends for log storage and output. The logging backend determines where the log messages are sent, such as a serial console, memory buffer, or filesystem. The ``log_backend_fs`` example demonstrates logging to a filesystem using LittleFS, which is useful for applications requiring persistent logs, such as crash diagnostics, event tracking, and debugging in deployed systems.

The ``log_backend_fs`` application is located at ``openair/tests/subsys/logging/log_backend_fs``. This application requires a device tree node named ``lfs1`` to be defined for the LittleFS partition. To build this application with a customized board name, copy one of the overlay files that matches the Atmosic Wireless SoC provided in ``boards/`` under the above directory. Then, rename the filename to match the customized board name and continue to follow the instructions below.

This application tests the following:
 * Writes to a file, reads it back, and verifies that the content matches.
 * Fills a log file beyond the size limit and checks if a new log file is created.
 * Verifies that the oldest log file is deleted when the log file limit is reached.
 * Removes all saved logs.

Here are the example build commands for the application:

Without MCUboot::

    west build -p -s <APP> -b <BOARD> -d build/<BOARD>/<APP>

With MCUboot::

    west build -p -s <APP> -b <BOARD>@mcuboot -d build/<BOARD>/<APP> -- \
        -DCONFIG_BOOTLOADER_MCUBOOT=y -DCONFIG_MCUBOOT_SIGNATURE_KEY_FILE=\"bootloader/mcuboot/root-ec-p256.pem\"

flash_map
=========

Zephyr’s storage subsystem is useful for partitioning and managing flash memory regions efficiently. It provides a structured way to organize flash storage, enabling easier access and modification of data.

The ``flash_map`` application is located at ``zephyr/tests/subsys/storage/flash_map``. Since this application tests access to the ``slot1_partition``, it requires to build with MCUboot.

This application tests the following APIs:

* ``flash_area_open()`` with a valid partition (``slot1_partition``) and with a disabled flash area.
* ``flash_area_write()``.
* ``flash_area_read()``.
* ``flash_area_check_int_sha256()``.
* ``flash_area_erase()``.
* ``flash_area_flatten()``.
* ``flash_write()``.
* ``flash_read()``.
