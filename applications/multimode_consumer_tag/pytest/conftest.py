#!/usr/bin/env python3
"""
@file pytest/conftest.py

@brief Pytest configuration and fixtures for multimode_consumer_tag AT command tests.

Provides AT command helper fixture and configuration for test execution.

Copyright (C) Atmosic 2025-2026

SPDX-License-Identifier: LicenseRef-Atmosic
"""

import logging
import re
import time

import pytest
import serial

logger = logging.getLogger(__name__)

DEFAULT_TIMEOUT = 5.0
DEFAULT_BAUD_RATE = 115200
AT_BOOT_TIMEOUT = 30.0
AT_READY_REGEX = r"AT command UART ready on"


def pytest_addoption(parser):
    """Add custom command line options for AT command tests."""
    parser.addoption(
        "--cmd-timeout",
        action="store",
        type=float,
        default=DEFAULT_TIMEOUT,
        help=f"Timeout for AT command responses (default: {DEFAULT_TIMEOUT}s)",
    )
    parser.addoption(
        "--at-cmd-serial",
        action="store",
        type=str,
        default=None,
        help="Serial port for AT commands (uart0). If not specified, uses same port as console.",
    )
    parser.addoption(
        "--at-cmd-baud",
        action="store",
        type=int,
        default=DEFAULT_BAUD_RATE,
        help=f"Baud rate for AT command serial port (default: {DEFAULT_BAUD_RATE})",
    )


@pytest.fixture(scope="session")
def cmd_timeout(request):
    """Get the command timeout from command line options."""
    return request.config.getoption("--cmd-timeout")


@pytest.fixture(scope="session")
def at_cmd_serial_port(request):
    """Get the AT command serial port.

    Priority:
    1. --at-cmd-serial (explicit override, two-port mode)
    2. --device-serial from twister (single-port fallback)
    """
    explicit_port = request.config.getoption("--at-cmd-serial")
    if explicit_port:
        return explicit_port

    try:
        twister_config = getattr(request.config, "twister_harness_config", None)
        if twister_config and twister_config.devices:
            device_serial = twister_config.devices[0].serial
            if device_serial:
                return device_serial
    except (AttributeError, IndexError):
        pass

    return None


@pytest.fixture(scope="session")
def at_cmd_baud(request):
    """Get the AT command baud rate from command line options."""
    return request.config.getoption("--at-cmd-baud")


class ATCommandSerial:
    """Wrapper for serial port communication with AT commands."""

    def __init__(self, port, baud=DEFAULT_BAUD_RATE, timeout=DEFAULT_TIMEOUT):
        self.port = port
        self.baud = baud
        self.timeout = timeout
        self._serial = None

    def open(self):
        """Open the serial port."""
        if self._serial is None or not self._serial.is_open:
            logger.debug("Opening AT serial: %s at %d baud", self.port, self.baud)
            self._serial = serial.Serial(
                port=self.port,
                baudrate=self.baud,
                timeout=self.timeout,
                write_timeout=self.timeout,
            )
            self._serial.reset_input_buffer()
            self._serial.reset_output_buffer()

    def close(self):
        """Close the serial port."""
        if self._serial and self._serial.is_open:
            self._serial.close()

    def write(self, data):
        """Write data to the serial port."""
        if self._serial and self._serial.is_open:
            logger.debug("AT tx: %s", data)
            self._serial.write(data)
            self._serial.flush()

    def read_until(self, pattern, timeout=None):
        """Read lines until pattern is found or timeout. Returns list of str."""
        original_timeout = self._serial.timeout
        self._serial.timeout = 0.5
        regex = re.compile(pattern)
        lines = []
        deadline = time.time() + (timeout or self.timeout)
        while time.time() < deadline:
            raw = self._serial.readline()
            if raw:
                line = raw.decode("utf-8", errors="replace").strip()
                logger.debug("AT rx: %s", line)
                lines.append(line)
                if regex.search(line):
                    break
        self._serial.timeout = original_timeout
        return lines

    def clear_buffer(self):
        """Clear input buffer."""
        if self._serial and self._serial.is_open:
            self._serial.reset_input_buffer()


class ATCommandHelper:
    """Helper class for sending AT commands and parsing responses."""

    OK_PATTERN = re.compile(r"OK")
    ERROR_PATTERN = re.compile(r"ERR")

    def __init__(self, dut, timeout=DEFAULT_TIMEOUT, at_serial=None):
        """Initialize AT command helper.

        Args:
            dut: DeviceAdapter - used for console monitoring.
            timeout: Default timeout for commands.
            at_serial: Optional ATCommandSerial for uart0 (two-port mode).
                       If None, uses dut for both console and AT commands.
        """
        self.dut = dut
        self.timeout = timeout
        self.at_serial = at_serial

    def send_command(self, cmd, wait_for_ok=True):
        """Send an AT command and return response lines."""
        logger.info("Sending AT command: %s", cmd)

        if self.at_serial:
            # Two-port mode: AT commands via at_serial (uart0)
            self.at_serial.clear_buffer()
            self.at_serial.write(f"{cmd}\r\n".encode())
            time.sleep(0.1)
            if wait_for_ok:
                lines = self.at_serial.read_until(
                    r"(OK|ERROR|ERR)", timeout=self.timeout
                )
                if not lines:
                    logger.error("Timeout waiting for response to: %s", cmd)
            else:
                time.sleep(0.5)
                lines = self.at_serial.read_until(r".", timeout=0.5)
        else:
            # Single-port mode: use dut for everything
            self.dut.clear_buffer()
            self.dut.write(f"{cmd}\r\n".encode())
            time.sleep(0.1)
            if wait_for_ok:
                try:
                    lines = self.dut.readlines_until(
                        regex=r"(OK|ERROR|ERR)", timeout=self.timeout
                    )
                except TimeoutError:
                    lines = self.dut.readlines()
            else:
                time.sleep(0.5)
                lines = self.dut.readlines()

        logger.info("Response: %s", lines)
        return lines

    def check_ok(self, lines):
        """Check if response contains OK."""
        return any(self.OK_PATTERN.search(line) for line in lines)

    def check_error(self, lines):
        """Check if response contains ERROR, ERR:X, or bare ERR."""
        return any(self.ERROR_PATTERN.search(line) for line in lines)

    def get_value(self, lines, prefix):
        """Extract value from response line matching prefix."""
        for line in lines:
            if line.startswith(prefix):
                return line[len(prefix) :]
        return None


@pytest.fixture(scope="session")
def at_cmd_serial_connection(
    at_cmd_serial_port, at_cmd_baud
):  # pylint: disable=redefined-outer-name
    """Fixture providing serial connection for AT commands (uart0).

    Opens a separate serial port when --at-cmd-serial is specified (two-port mode).
    Otherwise returns None (single-port mode, AT commands go through dut).

    Scope is 'session' so the connection is opened once for the entire test session.
    Requires pytest_dut_scope: session in sample.yaml (one flash per session).
    """
    if at_cmd_serial_port:
        at_serial = ATCommandSerial(at_cmd_serial_port, at_cmd_baud)
        at_serial.open()
        yield at_serial
        at_serial.close()
    else:
        yield None


@pytest.fixture(scope="session")
def at_cmd(
    dut, cmd_timeout, at_cmd_serial_connection
):  # pylint: disable=redefined-outer-name
    """Fixture providing ATCommandHelper for the DUT.

    Waits for device boot ready message on console (dut), then returns helper.
    Scope is 'session' (requires pytest_dut_scope: session in sample.yaml).
    Device is flashed only once for the entire test session.

    Two-port mode:  AT commands via --at-cmd-serial (uart0), logs via dut (uart1).
    Single-port mode: AT commands and logs both via dut.
    """
    try:
        dut.readlines_until(regex=AT_READY_REGEX, timeout=AT_BOOT_TIMEOUT)
        logger.info("Device ready for AT commands")
    except TimeoutError as e:
        logger.warning("Timeout waiting for ready message: %s", e)
        time.sleep(2.0)

    return ATCommandHelper(dut, timeout=cmd_timeout, at_serial=at_cmd_serial_connection)
