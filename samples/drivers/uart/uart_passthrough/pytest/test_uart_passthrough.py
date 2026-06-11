# Copyright (c) 2026 Atmosic
#
# SPDX-License-Identifier: Apache-2.0

"""
Pytest test for UART passthrough functionality.

This test sends data to UART0 and verifies that it is forwarded to UART1 (console).
Data sent to UART0 is passed through by firmware via uart_poll_out to UART1,
so the test string should appear directly on the console output.

Note: dut is connected to UART1 (console), UART0 requires separate connection
via ZEPHYR_UART0 environment variable.
"""

import logging
import os

import serial
from twister_harness import DeviceAdapter  # pylint: disable=import-error

logger = logging.getLogger(__name__)

TEST_STRING = "HelloUART"


def test_uart_passthrough(dut: DeviceAdapter):
    """
    Test UART passthrough functionality.

    This test sends data to UART0 and verifies it is forwarded to UART1 (console).
    """
    logger.info("Starting UART passthrough test")

    # Get UART0 device from environment variable
    uart0_device = os.environ.get("ZEPHYR_UART0")
    assert uart0_device, "ZEPHYR_UART0 environment variable not set"

    # Wait for firmware to be ready to receive external test data
    dut.readlines_until(regex="Waiting for external test data", timeout=120)
    logger.info("Device ready for external test data")

    # Open serial port at 115200 baud
    with serial.Serial(uart0_device, baudrate=115200, timeout=1) as ser:
        # Log UART0 configuration
        logger.info(
            "UART0 config: port=%s baudrate=%d bytesize=%d parity=%s stopbits=%s",
            ser.port,
            ser.baudrate,
            ser.bytesize,
            ser.parity,
            ser.stopbits,
        )

        payload = (TEST_STRING + "\n").encode()
        logger.info("Sending to UART0 (%s): %s", uart0_device, TEST_STRING)
        for i in range(1, 4):
            ser.write(payload)
            ser.flush()
            logger.info("echo %d: sent %r", i, payload)

    # Wait for test string to appear on console (UART1)
    # Data sent to UART0 is forwarded via uart_poll_out to UART1
    lines = dut.readlines_until(regex=TEST_STRING, timeout=10)

    test_passed = any(TEST_STRING in line for line in lines)

    if test_passed:
        logger.info("UART passthrough test PASSED")
    else:
        logger.error("UART passthrough test FAILED - data not forwarded")

    assert test_passed, "UART passthrough test failed - data not forwarded to UART1"
