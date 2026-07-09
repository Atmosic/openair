#!/usr/bin/env python3
# Copyright (c) 2026 Atmosic
#
# SPDX-License-Identifier: LicenseRef-Atmosic

"""
@file pytest/conftest.py

@brief Pytest configuration and fixtures for BLE AT Command tests.

"""

import logging
import re
import time

import pytest
import serial

logger = logging.getLogger(__name__)

# Default timeout for AT command responses
DEFAULT_TIMEOUT = 5.0
DEFAULT_BAUD_RATE = 115200


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
        "-T",
        "--adv-timeout",
        action="store",
        type=int,
        default=60,
        help="Timeout in seconds to wait while advertising before disabling (default: 60)",
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
    parser.addoption(
        "--dev-b-serial",
        action="store",
        type=str,
        default=None,
        help="Serial port for device B (second device in two-device tests)",
    )
    parser.addoption(
        "--dev-b-baud",
        action="store",
        type=int,
        default=DEFAULT_BAUD_RATE,
        help=f"Baud rate for device B serial port (default: {DEFAULT_BAUD_RATE})",
    )
    parser.addoption(
        "--funcpin-out-pin",
        action="store",
        type=int,
        default=10,
        help="GPIO0 pin for SYSFUNCPIN output tests (default: 10, Blue LED on Cairo/ATM53xx). "
        "Override for Paris/ATM33xx: 7 (LED1); Perth/ATM34xx: 7 (LED0).",
    )
    parser.addoption(
        "--funcpin-in-pin",
        action="store",
        type=int,
        default=9,
        help="GPIO0 pin for SYSFUNCPIN input tests (default: 9, Green LED on Cairo/ATM53xx). "
        "Override for Paris/ATM33xx: 8 (Button0); Perth/ATM34xx: 5 (Button0).",
    )


def pytest_configure(config):
    """Register local pytest markers used by the sample test groups."""
    config.addinivalue_line("markers", "basic: basic AT command tests")
    config.addinivalue_line("markers", "adv: advertising-focused AT command tests")
    config.addinivalue_line("markers", "system: system AT command tests")
    config.addinivalue_line(
        "markers", "scan_conn: BLE scan and connection AT command tests"
    )
    config.addinivalue_line("markers", "two_dev_smp: two-device BLE SMP pairing tests")
    config.addinivalue_line(
        "markers", "two_dev: two-device BLE AT command tests requiring a second DUT"
    )
    config.addinivalue_line("markers", "gatt: GATT default server AT command tests")
    config.addinivalue_line("markers", "gatt_dyn: GATT dynamic server AT command tests")
    config.addinivalue_line(
        "markers",
        "gatt_client: single-device GATT client AT command tests (no-conn validation)",
    )
    config.addinivalue_line(
        "markers", "gatt_two_dev: two-device GATT client/server AT command tests"
    )


@pytest.fixture(scope="session")
def cmd_timeout(request):
    """Get the command timeout from command line options."""
    return request.config.getoption("--cmd-timeout")


@pytest.fixture(scope="session")
def adv_timeout(request):
    """Get the advertising timeout from command line options."""
    return request.config.getoption("--adv-timeout")


@pytest.fixture(scope="session")
def base_timeout(request):
    """Get the base timeout from Twister configuration."""
    return request.config.getoption("--base-timeout", default=DEFAULT_TIMEOUT)


@pytest.fixture(scope="session")
def funcpin_out_pin(request):
    """GPIO0 pin number for SYSFUNCPIN output tests.

    Defaults to 10 (Blue LED on Cairo/ATM53xx EVK). Override via
    ``--funcpin-out-pin`` when running on other platforms:
    - Paris/ATM33xx: pin 7 (LED1 on gpio0)
    - Perth/ATM34xx: pin 7 (LED0 on gpio0)

    """
    return request.config.getoption("--funcpin-out-pin")


@pytest.fixture(scope="session")
def funcpin_in_pin(request):
    """GPIO0 pin number for SYSFUNCPIN input tests.

    Defaults to 9 (Green LED on Cairo/ATM53xx EVK). Override via
    ``--funcpin-in-pin`` when running on other platforms:
    - Paris/ATM33xx: pin 8 (Button0/sw0 on gpio0)
    - Perth/ATM34xx: pin 5 (Button0/sw0 on gpio0)

    """
    return request.config.getoption("--funcpin-in-pin")


@pytest.fixture(scope="session")
def at_cmd_serial_port(request):
    """Get the AT command serial port from command line options or twister config.

    Priority:
    1. --at-cmd-serial command line option (explicit override)
    2. --device-serial from twister (via twister_harness_config)

    """
    # First check explicit --at-cmd-serial option
    explicit_port = request.config.getoption("--at-cmd-serial")
    if explicit_port:
        return explicit_port

    # Fall back to twister's --device-serial
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

    def __init__(
        self, port: str, baud: int = DEFAULT_BAUD_RATE, timeout: float = DEFAULT_TIMEOUT
    ):
        """Initialize serial port for AT commands.

        Args:
            port: Serial port name (e.g., COM4, /dev/ttyUSB0)
            baud: Baud rate
            timeout: Read timeout in seconds

        """
        self.port = port
        self.baud = baud
        self.timeout = timeout
        self._serial = None

    def open(self):
        """Open the serial port."""
        if self._serial is None or not self._serial.is_open:
            logger.debug(
                "Opening AT command serial port: %s at %s baud", self.port, self.baud
            )
            self._serial = serial.Serial(
                port=self.port,
                baudrate=self.baud,
                timeout=self.timeout,
                write_timeout=self.timeout,
            )
            # Clear any pending data
            self._serial.reset_input_buffer()
            self._serial.reset_output_buffer()

    def close(self):
        """Close the serial port."""
        if self._serial and self._serial.is_open:
            logger.debug("Closing AT command serial port: %s", self.port)
            self._serial.close()

    def write(self, data: bytes):
        """Write data to the serial port."""
        if self._serial and self._serial.is_open:
            logger.debug("AT serial tx: %s", data)
            bytes_written = self._serial.write(data)
            self._serial.flush()
            logger.debug("AT serial tx: %s bytes written", bytes_written)

    def read_lines(self, timeout: float = None) -> list[str]:
        """Read all available lines from the serial port.

        Args:
            timeout: Read timeout (uses default if None)

        Returns:
            List of lines read

        """
        if timeout:
            self._serial.timeout = timeout

        lines = []
        while True:
            line = self._serial.readline()
            if not line:
                break
            try:
                lines.append(line.decode("utf-8", errors="replace").strip())
            except UnicodeDecodeError:
                pass

        if timeout:
            self._serial.timeout = self.timeout

        return lines

    def read_until(self, pattern: str, timeout: float = None) -> list[str]:
        """Read lines until pattern is found or timeout.

        Args:
            pattern: Regex pattern to match
            timeout: Read timeout

        Returns:
            List of lines read

        """
        # Set a short per-read timeout to allow polling
        original_timeout = self._serial.timeout
        self._serial.timeout = 0.5  # 500ms per read attempt

        regex = re.compile(pattern)
        lines = []
        start_time = time.time()
        effective_timeout = timeout or self.timeout

        while (time.time() - start_time) < effective_timeout:
            line = self._serial.readline()
            if line:
                try:
                    decoded = line.decode("utf-8", errors="replace").strip()
                    logger.debug("AT serial rx: %s", decoded)
                    lines.append(decoded)
                    if regex.search(decoded):
                        break
                except UnicodeDecodeError as e:
                    logger.warning("Decode error: %s", e)

        # Restore original timeout
        self._serial.timeout = original_timeout

        return lines

    def clear_buffer(self):
        """Clear input buffer."""
        if self._serial and self._serial.is_open:
            self._serial.reset_input_buffer()


class ATCommandHelper:
    """Helper class for sending AT commands and parsing responses."""

    # Response patterns
    OK_PATTERN = re.compile(r"OK")
    ERROR_PATTERN = re.compile(r"(ERROR|ERR)")
    BD_ADDR_PATTERN = re.compile(r"(?<![0-9A-Fa-f])[0-9A-Fa-f]{12}(?![0-9A-Fa-f])")

    def __init__(
        self, dut, timeout: float = DEFAULT_TIMEOUT, at_serial: ATCommandSerial = None
    ):
        """Initialize AT command helper.

        Args:
            dut: Device under test (DeviceAdapter) - used for console monitoring
            timeout: Default timeout for commands
            at_serial: Optional separate serial port for AT commands (uart0)

        """
        self.dut = dut
        self.timeout = timeout
        self.at_serial = at_serial  # If None, use dut for both console and AT commands

    def send_command(self, cmd: str, wait_for_ok: bool = True) -> list[str]:
        """Send an AT command and wait for response.

        Args:
            cmd: AT command to send (with or without AT+ prefix)
            wait_for_ok: Wait for OK response

        Returns:
            List of response lines

        """
        # Ensure command has AT+ prefix
        if not cmd.upper().startswith("AT+"):
            cmd = f"AT+{cmd}"

        logger.info("Sending AT command: %s", cmd)

        # Use separate AT serial port if available, otherwise use dut
        if self.at_serial:
            # Two-port mode: AT commands via at_serial (uart0)
            self.at_serial.clear_buffer()
            self.at_serial.write(f"{cmd}\r\n".encode())

            # Wait a bit for response
            time.sleep(0.1)

            if wait_for_ok:
                lines = self.at_serial.read_until(
                    r"(OK|ERROR|ERR:)", timeout=self.timeout
                )
                if not lines:
                    logger.error("Timeout waiting for response")
            else:
                time.sleep(0.5)
                lines = self.at_serial.read_lines(timeout=self.timeout)
        else:
            # Single-port mode: use dut for everything
            self.dut.clear_buffer()
            self.dut.write(f"{cmd}\r\n".encode())

            # Wait a bit for response
            time.sleep(0.1)

            if wait_for_ok:
                try:
                    lines = self.dut.readlines_until(
                        regex=r"(OK|ERROR|ERR:)", timeout=self.timeout
                    )
                except TimeoutError as e:
                    logger.error("Timeout waiting for response: %s", e)
                    lines = self.dut.readlines()
            else:
                time.sleep(0.5)
                lines = self.dut.readlines()

        logger.info("Response: %s", lines)
        return lines

    def send_query(self, cmd: str) -> list[str]:
        """Send a query command (AT+CMD?).

        Args:
            cmd: Command name without AT+ prefix or ? suffix

        Returns:
            List of response lines

        """
        if cmd.upper().startswith("AT+"):
            cmd = cmd[3:]
        if cmd.endswith("?"):
            cmd = cmd[:-1]
        return self.send_command(f"AT+{cmd}?")

    def send_test(self, cmd: str) -> list[str]:
        """Send a test command (AT+CMD=?).

        Args:
            cmd: Command name without AT+ prefix or =? suffix

        Returns:
            List of response lines

        """
        if cmd.upper().startswith("AT+"):
            cmd = cmd[3:]
        if cmd.endswith("=?"):
            cmd = cmd[:-2]
        return self.send_command(f"AT+{cmd}=?")

    def read_until(self, pattern: str, timeout: float = None) -> list[str]:
        """Read lines until *pattern* is found or *timeout* expires.

        Delegates to ``at_serial.read_until`` in two-port mode or
        ``dut.readlines_until`` in single-port mode.

        Args:
            pattern: Regex pattern to match
            timeout: Read timeout in seconds

        Returns:
            List of lines read (may be empty on timeout)

        """
        if timeout is None:
            timeout = self.timeout
        if self.at_serial:
            return self.at_serial.read_until(pattern, timeout=timeout)
        try:
            return self.dut.readlines_until(regex=pattern, timeout=timeout)
        except TimeoutError:
            return []

    def check_ok(self, lines: list[str]) -> bool:
        """Check if response contains OK."""
        return any(self.OK_PATTERN.search(line) for line in lines)

    def check_error(self, lines: list[str]) -> bool:
        """Check if response contains ERROR."""
        return any(self.ERROR_PATTERN.search(line) for line in lines)

    def extract_bd_addr(self, lines: list[str]) -> str | None:
        """Extract BD address from response lines."""
        for line in lines:
            match = self.BD_ADDR_PATTERN.search(line)
            if match:
                return match.group(0)
        return None

    def wait_for_event(self, pattern: str, timeout: float = None) -> list[str]:
        """Wait for an unsolicited event line matching pattern.

        Reads lines from the serial port (or dut) until a line matching
        ``pattern`` is found or the timeout expires.

        Args:
            pattern: Regex pattern to match against incoming lines.
            timeout: Maximum seconds to wait (uses default if None).

        Returns:
            Lines read up to and including the matching line, or an empty
            list when the timeout expires without a match.
        """
        effective_timeout = timeout or self.timeout
        if self.at_serial:
            return self.at_serial.read_until(pattern, timeout=effective_timeout)
        try:
            return self.dut.readlines_until(regex=pattern, timeout=effective_timeout)
        except TimeoutError:
            return []


@pytest.fixture(scope="class")
def at_cmd_serial_connection(
    at_cmd_serial_port, at_cmd_baud
):  # pylint: disable=redefined-outer-name
    """Fixture providing serial connection for AT commands (uart0).

    This fixture opens a separate serial port for AT command I/O when
    --at-cmd-serial is specified. Otherwise returns None.

    Scope is "class" so the serial connection is reused across all tests
    in a test class, avoiding repeated open/close cycles.

    """
    if at_cmd_serial_port:
        at_serial = ATCommandSerial(at_cmd_serial_port, at_cmd_baud)
        at_serial.open()
        yield at_serial
        at_serial.close()
    else:
        yield None


@pytest.fixture(scope="class")
def at_cmd(
    dut, cmd_timeout, at_cmd_serial_connection
):  # pylint: disable=redefined-outer-name
    """Fixture providing AT command helper for the DUT.

    If --at-cmd-serial is specified, AT commands are sent via that port (uart0)
    and console output is monitored via dut (uart1).
    Otherwise, both console and AT commands use the same port.

    Scope is "class" so the device is flashed once and all tests in the class
    run without re-flashing, significantly speeding up test execution.

    """
    # Create AT command helper
    helper = ATCommandHelper(
        dut, timeout=cmd_timeout, at_serial=at_cmd_serial_connection
    )

    # Verify device is ready via AT command handshake
    # This is more reliable than console print monitoring, especially with class-scoped fixtures
    # Uses AT+DEBUG? which is a built-in command, always available, and has no side effects
    max_retries = 5
    retry_delay = 1.0

    for attempt in range(max_retries):
        try:
            # Send a lightweight query command to verify device is ready
            # AT+DEBUG? is a built-in command that always exists and has no side effects
            lines = helper.send_query("DEBUG")
            if helper.check_ok(lines):
                logger.info(
                    "Device ready for AT commands (verified via AT+DEBUG? handshake)"
                )
                return helper
            logger.debug(
                "Attempt %d/%d: No OK response from device", attempt + 1, max_retries
            )
        except (TimeoutError, OSError, serial.SerialException) as e:
            logger.debug("Attempt %d/%d failed: %s", attempt + 1, max_retries, e)

        if attempt < max_retries - 1:
            time.sleep(retry_delay)

    # If we get here, device didn't respond to AT commands
    raise RuntimeError(
        f"Device failed to respond to AT command handshake after {max_retries} attempts. "
        "Device may not be ready or AT command interface may be unavailable."
    )


@pytest.fixture(scope="session")
def dev_b_serial_port(request):
    """Get device B serial port from --dev-b-serial command line option."""
    return request.config.getoption("--dev-b-serial")


@pytest.fixture(scope="session")
def dev_b_baud(request):
    """Get device B baud rate from --dev-b-baud command line option."""
    return request.config.getoption("--dev-b-baud")


@pytest.fixture(scope="class")
def dev_b_serial_connection(
    dev_b_serial_port, dev_b_baud
):  # pylint: disable=redefined-outer-name
    """Fixture providing a serial connection to device B (central) for two-device tests.

    Skips the test class if --dev-b-serial is not specified.
    Scope is "class" so the connection is reused across all tests in the class.

    """
    if not dev_b_serial_port:
        pytest.skip("--dev-b-serial not specified; skipping two-device test")
    at_serial = ATCommandSerial(dev_b_serial_port, dev_b_baud)
    at_serial.open()
    yield at_serial
    at_serial.close()


@pytest.fixture(scope="class")
def dev_b_at_cmd(
    dev_b_serial_connection, cmd_timeout
):  # pylint: disable=redefined-outer-name
    """Fixture providing an AT command helper for device B (central).

    Device B communicates solely via --dev-b-serial (no twister dut).
    Scope is "class" so the helper is reused across all tests in the class.

    """
    helper = ATCommandHelper(
        dut=None, timeout=cmd_timeout, at_serial=dev_b_serial_connection
    )

    max_retries = 5
    retry_delay = 1.0

    for attempt in range(max_retries):
        try:
            lines = helper.send_query("DEBUG")
            if helper.check_ok(lines):
                logger.info(
                    "Device B ready for AT commands (verified via AT+DEBUG? handshake)"
                )
                return helper
            logger.debug(
                "devB attempt %d/%d: no OK from device", attempt + 1, max_retries
            )
        except (TimeoutError, OSError, serial.SerialException) as e:
            logger.debug("devB attempt %d/%d failed: %s", attempt + 1, max_retries, e)

        if attempt < max_retries - 1:
            time.sleep(retry_delay)

    raise RuntimeError(
        f"Device B failed to respond to AT command handshake after {max_retries} attempts. "
        "Check --dev-b-serial port and that the device is running the AT command sample."
    )
