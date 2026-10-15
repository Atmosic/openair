# Copyright (c) 2026 Atmosic
#
# SPDX-License-Identifier: LicenseRef-Atmosic

"""
Pytest system-level tests for the HCI vendor GPIO self test command (0xF80E).

Covers the CONFIG_VND_GPIO_TEST handlers in atm_vendor.c:
  - vendor_gpio_self_test_handler() parses <num_pair> [<io_a> <io_b>]... and
    runs gpio_self_test() over each pair in both directions
  - vendor_gpio_self_test_cmp_handler() emits an HCI Command Complete event,
    reporting HCI_EVT_ERROR when any pair failed

Tests verify:
  1. Device boots and prints "atm_hci_init done"
  2. A zero-pair request returns HCI_STATUS_SUCCESS (no GPIO access)
  3. A pin pair that cannot map to any GPIO bank is rejected with a non-zero
     HCI status

Note: outcomes for physically wired pin pairs depend on the board harness, so
only wiring-independent cases are asserted here.
"""

from __future__ import annotations

import logging

import pytest
from twister_harness import DeviceAdapter  # pylint: disable=import-error

from hci_vendor_host import (
    GPIO_INVALID_PIN,
    GPIO_SELF_TEST_OPCODE_HI,
    GPIO_SELF_TEST_OPCODE_LO,
    HCI_STATUS_SUCCESS,
    HciVendorHost,
)

logger = logging.getLogger(__name__)

BOOT_READY_REGEX = r"atm_hci_init done"


# ---------------------------------------------------------------------------
# Class-scoped boot fixture
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


class TestHciVendorGpioSelfTest:
    """HCI vendor GPIO self test command tests (CONFIG_VND_GPIO_TEST)."""

    # pylint: disable=redefined-outer-name

    def _assert_opcode(self, evt, label: str) -> None:
        assert evt.opcode_lo == GPIO_SELF_TEST_OPCODE_LO, (
            f"{label}: opcode_lo mismatch: got 0x{evt.opcode_lo:02x}, "
            f"expected 0x{GPIO_SELF_TEST_OPCODE_LO:02x}"
        )
        assert evt.opcode_hi == GPIO_SELF_TEST_OPCODE_HI, (
            f"{label}: opcode_hi mismatch: got 0x{evt.opcode_hi:02x}, "
            f"expected 0x{GPIO_SELF_TEST_OPCODE_HI:02x}"
        )

    def test_boot_ready(self, hci_ready):
        """Verify the hci_vendor sample emits the expected boot banner."""
        assert any("atm_hci_init done" in line for line in hci_ready["boot_lines"])

    def test_gpio_self_test_no_pairs(self, hci_ready):
        """A zero-pair request performs no GPIO access and must succeed."""
        evt = hci_ready["host"].send_gpio_self_test([])
        logger.info(
            "GPIO self test (0 pairs) response: opcode=0x%04x status=0x%02x",
            evt.opcode,
            evt.status,
        )
        self._assert_opcode(evt, "no_pairs")
        assert (
            evt.success
        ), f"zero-pair GPIO self test expected SUCCESS, got 0x{evt.status:02x}"

    def test_gpio_self_test_invalid_pin_rejected(self, hci_ready):
        """A pin pair that maps to no GPIO bank must be rejected.

        atm_io_ctrl_get_dev() fails for out-of-range pins, so gpio_self_test()
        returns false and vendor_gpio_self_test_cmp_handler() sets HCI_EVT_ERROR.
        """
        evt = hci_ready["host"].send_gpio_self_test(
            [(GPIO_INVALID_PIN, GPIO_INVALID_PIN)]
        )
        logger.info("GPIO self test (invalid pin) response: status=0x%02x", evt.status)
        self._assert_opcode(evt, "invalid_pin")
        assert not evt.success, (
            "GPIO self test with an unmappable pin must be rejected; "
            "got HCI_STATUS_SUCCESS unexpectedly"
        )
        assert evt.status != HCI_STATUS_SUCCESS
