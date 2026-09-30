# Copyright (c) 2026 Atmosic
#
# SPDX-License-Identifier: LicenseRef-Atmosic

"""Pytest fixtures for the HCI vendor PSM system-level test."""

from __future__ import annotations

import logging
import os

import pytest
import serial

from hci_vendor_host import DEFAULT_BAUD_RATE, DEFAULT_RESPONSE_TIMEOUT_S, HciVendorHost

logger = logging.getLogger(__name__)


def pytest_addoption(parser):
    """Register HCI UART command-line options."""
    parser.addoption(
        "--hci-serial",
        action="store",
        type=str,
        default=None,
        help=(
            "Raw serial port carrying H4 HCI traffic (hci_vendor sample)."
            " Falls back to ZEPHYR_HCI_UART or ZEPHYR_UART0."
        ),
    )
    parser.addoption(
        "--hci-baud",
        action="store",
        type=int,
        default=DEFAULT_BAUD_RATE,
        help=f"Baud rate for the HCI UART port (default: {DEFAULT_BAUD_RATE})",
    )
    parser.addoption(
        "--hci-timeout",
        action="store",
        type=float,
        default=DEFAULT_RESPONSE_TIMEOUT_S,
        help=f"Timeout in seconds waiting for an HCI event (default: {DEFAULT_RESPONSE_TIMEOUT_S})",
    )


@pytest.fixture(scope="session")
def hci_serial_port(request) -> str:
    """Resolve the HCI UART port for the hci_vendor sample."""
    port = request.config.getoption("--hci-serial")
    if port:
        return port

    port = os.environ.get("ZEPHYR_HCI_UART") or os.environ.get("ZEPHYR_UART0")
    if port:
        return port

    pytest.skip(
        "HCI UART port not provided. "
        "Set --hci-serial or export ZEPHYR_HCI_UART / ZEPHYR_UART0."
    )


@pytest.fixture(scope="session")
def hci_baud(request) -> int:
    """Return the configured HCI UART baud rate."""
    return request.config.getoption("--hci-baud")


@pytest.fixture(scope="session")
def hci_timeout(request) -> float:
    """Return the configured HCI event timeout."""
    return request.config.getoption("--hci-timeout")


@pytest.fixture(scope="class")
def hci_host(
    hci_serial_port, hci_baud, hci_timeout
):  # pylint: disable=redefined-outer-name
    """Open an HciVendorHost for one test class and close it afterwards."""
    logger.info(
        "Opening HCI UART %s at %d baud (timeout %.1fs)",
        hci_serial_port,
        hci_baud,
        hci_timeout,
    )
    host = HciVendorHost(hci_serial_port, baud=hci_baud, timeout=hci_timeout)
    try:
        host.open()
    except (serial.SerialException, OSError) as exc:
        pytest.skip(f"Cannot open HCI UART {hci_serial_port}: {exc}")
    host.clear_input()
    try:
        yield host
    finally:
        host.close()
