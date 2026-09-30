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
V3_BANNER_REGEX = r"ATM_VENDOR_DFU_TEST IMG_VER=3\.0\.0"
READY_REGEX = r"DFU_READY"


def _wait_for(dut: DeviceAdapter, regex: str, timeout: float) -> list[str]:
    lines = dut.readlines_until(regex=regex, timeout=timeout)
    assert any(
        __import__("re").search(regex, line) for line in lines
    ), f"expected pattern {regex!r} in console output: {lines}"
    return lines


def _upgrade(dut: DeviceAdapter, dfu_host, image: Path, banner_regex: str) -> None:
    """Stream one image, request upgrade, and wait for its boot banner."""
    payload = image.read_bytes()
    logger.info("Streaming %d bytes", len(payload))
    dfu_host.reset_dfu()
    dfu_host.stream_image(payload)

    logger.info("Triggering upgrade and reboot")
    try:
        dfu_host.request_go()
    except Exception as exc:  # pylint: disable=broad-except
        # Device may reboot before sending OK; tolerate read errors here.
        logger.info("GO returned %s (likely due to immediate reboot)", exc)

    time.sleep(0.5)
    _wait_for(dut, banner_regex, timeout=180)


def test_dfu_swap_full_cycle(
    dut: DeviceAdapter, dfu_host, v2_image: Path, v3_image: Path
):
    """Two consecutive upgrades: v1->v2 then v2->v3.

    The second cycle regresses if the staging slot is not fully erased before
    an upgrade: stale MCUboot trailer / swap-status left by the first swap makes
    the bootloader reject the secondary image, so v3 never boots.
    """
    logger.info("Waiting for v1 boot banner")
    _wait_for(dut, V1_BANNER_REGEX, timeout=60)
    _wait_for(dut, READY_REGEX, timeout=30)

    banner = dfu_host.ping()
    logger.info("Device PING: %s", banner)
    assert "IMG_VER=1.0.0" in banner

    logger.info("Cycle 1: upgrading v1 -> v2")
    _upgrade(dut, dfu_host, v2_image, V2_BANNER_REGEX)
    _wait_for(dut, READY_REGEX, timeout=30)
    banner = dfu_host.ping()
    logger.info("Device PING after cycle 1: %s", banner)
    assert "IMG_VER=2.0.0" in banner
    logger.info("Cycle 1 completed: device booted v2.0.0")

    logger.info("Cycle 2: upgrading v2 -> v3")
    _upgrade(dut, dfu_host, v3_image, V3_BANNER_REGEX)
    logger.info("Cycle 2 completed: device booted v3.0.0")
