# Copyright (c) 2026 Atmosic
#
# SPDX-License-Identifier: LicenseRef-Atmosic

"""End-to-end MCUboot swap test driven via AT command DFU protocol."""

from __future__ import annotations

import logging
import time
from pathlib import Path

from twister_harness import DeviceAdapter  # pylint: disable=import-error

logger = logging.getLogger(__name__)

V1_BANNER_REGEX = r"AT_CMD_DFU_TEST IMG_VER=1\.0\.0"
V2_BANNER_REGEX = r"AT_CMD_DFU_TEST IMG_VER=2\.0\.0"
READY_REGEX = r"DFU_READY"


def _wait_for(dut: DeviceAdapter, regex: str, timeout: float) -> list[str]:
    lines = dut.readlines_until(regex=regex, timeout=timeout)
    assert any(
        __import__("re").search(regex, line) for line in lines
    ), f"expected pattern {regex!r} in console output: {lines}"
    return lines


def test_at_cmd_dfu_swap_full_cycle(
    dut: DeviceAdapter, at_cmd_dfu_host, v2_image: Path
):
    """Boot v1, stream v2 via AT+SYSDFU on uart0, request upgrade, verify v2 banner."""
    logger.info("Waiting for v1 boot banner")
    _wait_for(dut, V1_BANNER_REGEX, timeout=60)
    _wait_for(dut, READY_REGEX, timeout=30)

    payload = v2_image.read_bytes()
    logger.info("Starting AT+SYSDFU transfer: %d bytes", len(payload))
    at_cmd_dfu_host.start_dfu(len(payload), crc_en=False)

    logger.info("Streaming v2 image via RDP")
    at_cmd_dfu_host.stream_image(payload)

    logger.info("Triggering MCUboot upgrade via AT+SYSSWITCHBANK")
    at_cmd_dfu_host.switch_bank()

    logger.info("Waiting for v2 boot banner after MCUboot swap")
    time.sleep(0.5)
    _wait_for(dut, V2_BANNER_REGEX, timeout=180)
    _wait_for(dut, READY_REGEX, timeout=30)
    logger.info("DFU swap completed: device booted v2.0.0")

    logger.info("Confirming v2 image via AT+SYSMKBANKGOOD")
    at_cmd_dfu_host.mark_bank_good()
    logger.info("Image confirmed: MCUboot will not revert on next reboot")
