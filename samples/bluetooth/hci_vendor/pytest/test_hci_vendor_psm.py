# Copyright (c) 2026 Atmosic
#
# SPDX-License-Identifier: LicenseRef-Atmosic

"""
Pytest system-level tests for the HCI vendor PSM command (SW-6241).

Covers the CONFIG_SOC_FAMILY_ATM path added in commit e93d76b:
  - vendor_psm_config() maps PSM modes to Zephyr PM states via
    pm_policy_state_lock_put()
  - New PSM_* constants: NONE=0, DEEP=1, RETAIN=2, HIBERNATE=4, SOC_OFF=5
  - CONFIG_VND_PSM guard in atm_hci_uart.c registers the PSM_CMD handler

Tests verify:
  1. Device boots and prints "atm_hci_init done"
  2. Undefined PSM mode values are rejected with a non-zero HCI status
  3. Valid PSM modes (NONE, DEEP, RETAIN) return HCI_STATUS_SUCCESS
  4. PSM_HIBERNATE returns HCI_STATUS_SUCCESS (device may enter soft-off
     when idle; run in a separate twister scenario for a fresh boot)
"""

from __future__ import annotations

import logging

import pytest
from twister_harness import DeviceAdapter  # pylint: disable=import-error

from hci_vendor_host import (
    HCI_STATUS_SUCCESS,
    HciVendorHost,
    PSM_DEEP,
    PSM_HIBERNATE,
    PSM_NONE,
    PSM_OPCODE_HI,
    PSM_OPCODE_LO,
    PSM_RETAIN,
)

logger = logging.getLogger(__name__)

BOOT_READY_REGEX = r"atm_hci_init done"


# ---------------------------------------------------------------------------
# Session-scoped boot fixture
# ---------------------------------------------------------------------------


@pytest.fixture(scope="class")
def hci_ready(dut: DeviceAdapter, hci_host: HciVendorHost):
    """Wait for the hci_vendor sample to boot, then clear the HCI input buffer."""
    logger.info("Waiting for boot banner: %r", BOOT_READY_REGEX)
    boot_lines = dut.readlines_until(regex=BOOT_READY_REGEX, timeout=120)
    assert any(
        "atm_hci_init done" in line for line in boot_lines
    ), f"Boot banner not found in: {boot_lines}"
    hci_host.clear_input()
    return {"boot_lines": boot_lines, "host": hci_host}


# ---------------------------------------------------------------------------
# Test class
# ---------------------------------------------------------------------------


class TestHciVendorPsm:
    """HCI vendor PSM command tests for the CONFIG_SOC_FAMILY_ATM Zephyr path.

    PSM mode values (atm_vendor_internal.h, CONFIG_SOC_FAMILY_ATM):
        PSM_NONE     = 0  — no sleep; keep UART active
        PSM_DEEP     = 1  — allow PM_STATE_SUSPEND_TO_IDLE
        PSM_RETAIN   = 2  — allow PM_STATE_SUSPEND_TO_RAM
        PSM_HIBERNATE= 4  — allow PM_STATE_SOFT_OFF substate 0
        PSM_SOC_OFF  = 5  — allow PM_STATE_SOFT_OFF substate 1  [excluded: terminal]

    Note: mode 3 is undefined in the ATM enumeration and must be rejected.
    """

    # pylint: disable=redefined-outer-name

    def _assert_opcode(self, evt, label: str) -> None:
        assert evt.opcode_lo == PSM_OPCODE_LO, (
            f"{label}: opcode_lo mismatch: got 0x{evt.opcode_lo:02x}, "
            f"expected 0x{PSM_OPCODE_LO:02x}"
        )
        assert evt.opcode_hi == PSM_OPCODE_HI, (
            f"{label}: opcode_hi mismatch: got 0x{evt.opcode_hi:02x}, "
            f"expected 0x{PSM_OPCODE_HI:02x}"
        )

    def test_boot_ready(self, hci_ready):
        """Verify the hci_vendor sample emits the expected boot banner."""
        assert any("atm_hci_init done" in line for line in hci_ready["boot_lines"])

    @pytest.mark.parametrize(
        ("mode", "label"),
        [
            (3, "undefined_3"),
            (6, "undefined_6"),
            (0xFF, "undefined_FF"),
        ],
    )
    def test_psm_invalid_mode_rejected(self, hci_ready, mode, label):
        """Undefined PSM mode values must be rejected with a non-zero HCI status.

        The vendor_psm_cmp_handler() default switch branch sets HCI_EVT_ERROR
        for any mode not in {PSM_NONE, PSM_DEEP, PSM_RETAIN, PSM_HIBERNATE, PSM_SOC_OFF}.
        """
        evt = hci_ready["host"].send_psm(mode)
        logger.info(
            "PSM mode %s (0x%02x) response: status=0x%02x", label, mode, evt.status
        )
        self._assert_opcode(evt, label)
        assert not evt.success, (
            f"PSM mode {label} (0x{mode:02x}) must be rejected; "
            f"got HCI_STATUS_SUCCESS unexpectedly"
        )
        assert evt.status != HCI_STATUS_SUCCESS

    def test_psm_none(self, hci_ready):
        """PSM_NONE (0) must be accepted: no sleep, UART stays active."""
        evt = hci_ready["host"].send_psm(PSM_NONE)
        logger.info(
            "PSM_NONE response: opcode=0x%04x status=0x%02x", evt.opcode, evt.status
        )
        self._assert_opcode(evt, "PSM_NONE")
        assert evt.success, f"PSM_NONE expected SUCCESS, got 0x{evt.status:02x}"

    def test_psm_deep(self, hci_ready):
        """PSM_DEEP (1) must be accepted: allows PM_STATE_SUSPEND_TO_IDLE."""
        evt = hci_ready["host"].send_psm(PSM_DEEP)
        logger.info(
            "PSM_DEEP response: opcode=0x%04x status=0x%02x", evt.opcode, evt.status
        )
        self._assert_opcode(evt, "PSM_DEEP")
        assert evt.success, f"PSM_DEEP expected SUCCESS, got 0x{evt.status:02x}"

    def test_psm_retain(self, hci_ready):
        """PSM_RETAIN (2) must be accepted: allows PM_STATE_SUSPEND_TO_RAM."""
        evt = hci_ready["host"].send_psm(PSM_RETAIN)
        logger.info(
            "PSM_RETAIN response: opcode=0x%04x status=0x%02x", evt.opcode, evt.status
        )
        self._assert_opcode(evt, "PSM_RETAIN")
        assert evt.success, f"PSM_RETAIN expected SUCCESS, got 0x{evt.status:02x}"

    def test_psm_hibernate(self, hci_ready):
        """PSM_HIBERNATE (4) must be accepted: allows PM_STATE_SOFT_OFF substate 0.

        Run in a dedicated twister scenario (pytest_psm_hibernate) for a fresh
        cold boot.  The HCI response must be sent before any state transition.
        """
        evt = hci_ready["host"].send_psm(PSM_HIBERNATE)
        logger.info(
            "PSM_HIBERNATE response: opcode=0x%04x status=0x%02x",
            evt.opcode,
            evt.status,
        )
        self._assert_opcode(evt, "PSM_HIBERNATE")
        assert evt.success, f"PSM_HIBERNATE expected SUCCESS, got 0x{evt.status:02x}"
