# Copyright (c) 2026 Atmosic
#
# SPDX-License-Identifier: LicenseRef-Atmosic

"""Pytest fixtures for the DTM 2-wire sample."""

from dataclasses import dataclass
import logging
import os

import pytest
import serial

from dtm_2wire_host import DEFAULT_BAUD_RATE, DEFAULT_RESPONSE_TIMEOUT_S, Dtm2WireHost

logger = logging.getLogger(__name__)


@dataclass(frozen=True)
class DtmDeviceAConfig:
    """Device A role and boot-ready expression for a dual-device test."""

    role: str
    ready_regex: str
    skip_ready: bool


def pytest_addoption(parser):
    """Add DTM UART command line options."""
    parser.addoption(
        "--dtm-serial",
        action="store",
        type=str,
        default=None,
        help=(
            "Raw serial port for DTM 2-wire traffic."
            " Falls back to ZEPHYR_DTM_UART or ZEPHYR_UART0."
        ),
    )
    parser.addoption(
        "--dtm-baud",
        action="store",
        type=int,
        default=DEFAULT_BAUD_RATE,
        help=f"Baud rate for the DTM UART port (default: {DEFAULT_BAUD_RATE})",
    )
    parser.addoption(
        "--dtm-timeout",
        action="store",
        type=float,
        default=DEFAULT_RESPONSE_TIMEOUT_S,
        help=f"Timeout in seconds for a DTM response (default: {DEFAULT_RESPONSE_TIMEOUT_S})",
    )
    parser.addoption(
        "--dtm-dev-b-serial",
        action="store",
        type=str,
        default=None,
        help=(
            "Raw serial port for the second DTM device (device B) in two-device"
            " tests. Falls back to ZEPHYR2_DTM_UART or ZEPHYR2_UART0."
        ),
    )
    parser.addoption(
        "--dtm-dev-b-baud",
        action="store",
        type=int,
        default=DEFAULT_BAUD_RATE,
        help=f"Baud rate for the device B DTM UART (default: {DEFAULT_BAUD_RATE})",
    )
    parser.addoption(
        "--dtm-device-a-role",
        action="store",
        choices=("tx", "rx"),
        default="rx",
        help=(
            "DTM role assigned to device A, the Twister DUT (default: rx). "
            "Device B is assigned the opposite role."
        ),
    )
    parser.addoption(
        "--dtm-dut-ready-regex",
        action="store",
        default=r"DTM 2-wire application started",
        help="Regex indicating that device A is ready for DTM commands.",
    )
    parser.addoption(
        "--dtm-skip-dut-ready",
        action="store_true",
        default=False,
        help="Do not wait for a device A boot message (for console-less release builds).",
    )
    parser.addoption(
        "--dtm-expedite",
        action="store_true",
        default=False,
        help=(
            "Shorten the two-device coverage sweeps (fewer channels/PHYs/payloads)"
            " to keep CI runtime down."
        ),
    )
    parser.addoption(
        "--dtm-tx-power",
        action="store",
        type=int,
        default=None,
        help=(
            "Override the transmitter power level (dBm) on the TX device before the"
            " two-device sweep. The firmware default forces maximum power, which"
            " over-saturates a cabled two-EVK rig; set a moderate value (e.g. 0)"
            " for over-the-air/cabled DTM. Default: leave the firmware default."
        ),
    )


@pytest.fixture(scope="session")
def dtm_serial_port(request):
    """Resolve the raw DTM UART port for the sample."""
    port = request.config.getoption("--dtm-serial")
    if port:
        return port

    port = os.environ.get("ZEPHYR_DTM_UART") or os.environ.get("ZEPHYR_UART0")
    if port:
        return port

    return pytest.skip(
        "DTM UART port not provided. Set --dtm-serial or export ZEPHYR_DTM_UART/ZEPHYR_UART0."
    )


@pytest.fixture(scope="session")
def dtm_baud(request):
    """Return the configured DTM UART baud rate."""
    return request.config.getoption("--dtm-baud")


@pytest.fixture(scope="session")
def dtm_timeout(request):
    """Return the configured DTM response timeout."""
    return request.config.getoption("--dtm-timeout")


@pytest.fixture(scope="class")
def dtm_host(
    dtm_serial_port, dtm_baud, dtm_timeout
):  # pylint: disable=redefined-outer-name
    """Provide an opened raw DTM 2-wire host interface."""
    logger.info("Opening DTM UART %s at %d baud", dtm_serial_port, dtm_baud)
    host = Dtm2WireHost(dtm_serial_port, baud=dtm_baud, timeout=dtm_timeout)
    try:
        host.open()
    except (serial.SerialException, OSError) as exc:
        pytest.skip(f"Cannot open DTM UART {dtm_serial_port}: {exc}")
    host.clear_input()
    try:
        yield host
    finally:
        host.close()


@pytest.fixture(scope="session")
def dtm_dev_b_serial_port(request):
    """Resolve the device B DTM UART port for two-device tests."""
    port = request.config.getoption("--dtm-dev-b-serial")
    if port:
        return port

    return os.environ.get("ZEPHYR2_DTM_UART") or os.environ.get("ZEPHYR2_UART0")


@pytest.fixture(scope="session")
def dtm_dev_b_baud(request):
    """Return the configured device B DTM UART baud rate."""
    return request.config.getoption("--dtm-dev-b-baud")


@pytest.fixture(scope="session")
def dtm_device_a_config(request):
    """Return the configured role and boot-ready expression for device A."""
    return DtmDeviceAConfig(
        role=request.config.getoption("--dtm-device-a-role"),
        ready_regex=request.config.getoption("--dtm-dut-ready-regex"),
        skip_ready=request.config.getoption("--dtm-skip-dut-ready"),
    )


@pytest.fixture(scope="session")
def dtm_expedite(request):
    """Return True when the two-device coverage sweeps should be shortened."""
    return request.config.getoption("--dtm-expedite")


@pytest.fixture(scope="session")
def dtm_tx_power(request):
    """Return the TX power override in dBm, or None to keep the firmware default."""
    return request.config.getoption("--dtm-tx-power")


@pytest.fixture(scope="class")
def dtm_host_b(
    dtm_dev_b_serial_port, dtm_dev_b_baud, dtm_timeout
):  # pylint: disable=redefined-outer-name
    """Provide an opened raw DTM host for device B, or skip if it is not configured.

    Two-device tests require a second EVK running the same sample, reachable on
    its own raw UART. Without ``--dtm-dev-b-serial`` (or ZEPHYR2_*_UART0) the
    test is skipped so single-device rigs are unaffected.
    """
    if not dtm_dev_b_serial_port:
        pytest.skip(
            "Device B DTM UART not provided. Set --dtm-dev-b-serial or export"
            " ZEPHYR2_DTM_UART/ZEPHYR2_UART0 to run two-device DTM tests."
        )

    logger.info(
        "Opening device B DTM UART %s at %d baud", dtm_dev_b_serial_port, dtm_dev_b_baud
    )
    host = Dtm2WireHost(dtm_dev_b_serial_port, baud=dtm_dev_b_baud, timeout=dtm_timeout)
    try:
        host.open()
    except (serial.SerialException, OSError) as exc:
        pytest.skip(f"Cannot open device B DTM UART {dtm_dev_b_serial_port}: {exc}")
    host.clear_input()
    try:
        yield host
    finally:
        host.close()
