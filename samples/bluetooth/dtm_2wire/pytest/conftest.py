# Copyright (c) 2026 Atmosic
#
# SPDX-License-Identifier: Apache-2.0

"""Pytest fixtures for the DTM 2-wire sample."""

import logging
import os

import pytest
import serial

from dtm_2wire_host import DEFAULT_BAUD_RATE, DEFAULT_RESPONSE_TIMEOUT_S, Dtm2WireHost

logger = logging.getLogger(__name__)


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
