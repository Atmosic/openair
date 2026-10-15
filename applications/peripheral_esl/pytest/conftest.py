#!/usr/bin/env python3
"""
@file conftest.py

@brief Pytest configuration for ESL AP test

This module provides pytest fixtures for the ESL (Electronic Shelf Label) test.
It handles device path resolution for both the Nordic ESL AP tester and the
Atmosic ESL tag device.

Copyright (C) Atmosic 2026
"""

import glob
import logging
import os
import subprocess

import pytest

logger = logging.getLogger(__name__)


def pytest_addoption(parser):
    """Add custom command line options"""
    parser.addoption("--tester-serial", help="Nordic ESL AP tester serial number")
    parser.addoption(
        "--esl-tag-uart",
        help="ESL tag UART device path (optional, auto-detected if not provided)",
    )


def get_nrf_dev_from_serial(serial: str) -> str:
    """
    Find the /dev/ttyACM* device corresponding to the given serial number.

    Args:
        serial: The serial number to look for

    Returns:
        The device path (e.g., /dev/ttyACM0) or None if not found
    """
    logger.info("Looking for ttyACM device with serial: %s", serial)
    acm_devices = sorted(glob.glob("/dev/ttyACM*"))
    logger.info("Found ttyACM devices: %s", acm_devices)

    for dev in acm_devices:
        try:
            result = subprocess.run(
                ["udevadm", "info", dev], capture_output=True, text=True, check=False
            )
            for line in result.stdout.splitlines():
                if "ID_SERIAL_SHORT" in line:
                    sn = line.split("=")[1].strip()
                    logger.info("  %s -> ID_SERIAL_SHORT=%s", dev, sn)
                    if sn == serial:
                        logger.info("  => Matched! Using %s", dev)
                        return dev
        except (OSError, subprocess.SubprocessError) as exc:
            logger.warning("  %s -> udevadm error: %s", dev, exc)
            continue
    logger.error("No ttyACM device found for serial: %s", serial)
    return None


def get_esl_tag_uart_path() -> str:
    """
    Resolve the ESL tag UART device path based on environment variables.

    Returns:
        The UART device path for the ESL tag
    """
    serial_configs = [
        (
            "SYDNEY_SERIAL",
            lambda s: (
                f"/dev/serial/by-id/usb-FTDI_ATMDL_{s}-if01-port0"
                if "ATMDL" in s
                else f"/dev/ttyUSB.{s}USB1.SydneyA.UART1"
            ),
        ),
        ("PARIS_SERIAL", lambda s: f"/dev/ttyUSB.{s}USB1.SydneyA.UART1"),
        ("PARIS_FPGA_SERIAL", lambda s: f"/dev/ttyUSB.{s}USB0.SydneyA.UART1"),
        ("SYDNEY_FPGA_SERIAL", lambda s: f"/dev/ttyUSB.{s}.SydneyA.UART1"),
        ("JLINK_SERIAL", lambda s: f"/dev/serial/by-id/usb-SEGGER_J-Link_{s}-if02"),
    ]

    for env_var, path_func in serial_configs:
        serial_val = os.environ.get(env_var)
        if serial_val:
            return path_func(serial_val)

    return "/dev/ttyUSB.SydneyA.UART1"


@pytest.fixture(scope="session")
def tester_serial(request):
    """Get the Nordic ESL AP tester serial number"""
    serial = request.config.getoption("--tester-serial")
    if not serial:
        serial = os.environ.get("TESTER_SERIAL")
    if not serial:
        pytest.fail("--tester-serial or TESTER_SERIAL environment variable is required")
    return serial


@pytest.fixture(scope="session")
def tester_device_path(tester_serial):  # pylint: disable=redefined-outer-name
    """Get the Nordic ESL AP tester device path"""
    dev_path = get_nrf_dev_from_serial(tester_serial)
    if not dev_path:
        pytest.fail(f"Could not find device for tester serial: {tester_serial}")
    logger.info("Tester device path resolved: %s (serial=%s)", dev_path, tester_serial)
    return dev_path


@pytest.fixture(scope="session")
def esl_tag_uart_path(request):
    """Get the ESL tag UART device path"""
    uart_path = request.config.getoption("--esl-tag-uart")
    if not uart_path:
        uart_path = get_esl_tag_uart_path()
    logger.info("ESL tag UART path resolved: %s", uart_path)
    return uart_path
