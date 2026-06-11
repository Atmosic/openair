# Copyright (c) 2026 Atmosic
#
# SPDX-License-Identifier: LicenseRef-Atmosic

"""End-to-end MCUboot swap test driven via the atm_vendor_dfu library."""

from __future__ import annotations

import logging
import time
from pathlib import Path

from twister_harness import DeviceAdapter  # pylint: disable=import-error

logger = logging.getLogger(__name__)

V1_BANNER_REGEX = r"ATM_VENDOR_DFU_TEST IMG_VER=1\.0\.0"
V2_BANNER_REGEX = r"ATM_VENDOR_DFU_TEST IMG_VER=2\.0\.0"
READY_REGEX = r"DFU_READY"


def _wait_for(dut: DeviceAdapter, regex: str, timeout: float) -> list[str]:
    lines = dut.readlines_until(regex=regex, timeout=timeout)
    assert any(
        __import__("re").search(regex, line) for line in lines
    ), f"expected pattern {regex!r} in console output: {lines}"
    return lines


def test_dfu_swap_full_cycle(dut: DeviceAdapter, dfu_host, v2_image: Path):
    """Boot v1, stream v2 via uart0, request upgrade, verify v2 banner."""
    logger.info("Waiting for v1 boot banner")
    _wait_for(dut, V1_BANNER_REGEX, timeout=60)
    _wait_for(dut, READY_REGEX, timeout=30)

    banner = dfu_host.ping()
    logger.info("Device PING: %s", banner)
    assert "IMG_VER=1.0.0" in banner

    payload = v2_image.read_bytes()
    logger.info("Streaming %d bytes of v2 image", len(payload))
    dfu_host.reset_dfu()
    dfu_host.stream_image(payload)

    logger.info("Triggering upgrade and reboot")
    try:
        dfu_host.request_go()
    except Exception as exc:  # pylint: disable=broad-except
        # Device may reboot before sending OK; tolerate read errors here.
        logger.info("GO returned %s (likely due to immediate reboot)", exc)

    logger.info("Waiting for v2 boot banner after MCUboot swap")
    time.sleep(0.5)
    _wait_for(dut, V2_BANNER_REGEX, timeout=180)
    logger.info("DFU swap completed: device booted v2.0.0")
