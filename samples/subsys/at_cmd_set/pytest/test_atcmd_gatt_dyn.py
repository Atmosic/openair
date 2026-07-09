#!/usr/bin/env python3
# Copyright (c) 2026 Atmosic
#
# SPDX-License-Identifier: LicenseRef-Atmosic

"""
@file pytest/test_atcmd_gatt_dyn.py

@brief Automated pytest tests for GATT dynamic server AT commands.

All tests run without a phone. Tests cover ordering errors, parameter
validation, and basic add+activate flow.

Note: Dynamic GATT services, once activated (BLEGATTSVCACTIVE), persist
in the GATT database until device reboot. Tests that stage or activate
services use the cleanup_after_test fixture to reboot the device after
each test. Each test uses unique UUIDs to avoid conflicts.

"""

import re
import time
import logging

import pytest
from conftest import ATCommandHelper

pytestmark = pytest.mark.gatt_dyn

logger = logging.getLogger(__name__)

# Reboot readiness poll settings
_REBOOT_READY_RETRIES = 10
_REBOOT_READY_DELAY = 1.0  # seconds between retries


def _wait_dut_ready(
    at_cmd: ATCommandHelper, retries: int = _REBOOT_READY_RETRIES
) -> None:
    """Poll AT+DEBUG? after cold reboot until the device responds OK.

    More reliable than a fixed sleep because reboot time varies with
    hardware, log level, and CI load. Note: Cold reboot (SYSRESET=1) is used
    to ensure TYPE_POWER_ON boot type for proper EUI initialization.

    Raises:
        RuntimeError: If DUT does not respond within timeout window.
    """
    for attempt in range(retries):
        try:
            if at_cmd.check_ok(at_cmd.send_query("DEBUG")):
                logger.debug("DUT ready after %d attempt(s)", attempt + 1)
                return
        except (OSError, RuntimeError):
            pass
        time.sleep(_REBOOT_READY_DELAY)
    raise RuntimeError(
        f"DUT did not respond within {retries * _REBOOT_READY_DELAY}s after reboot. "
        "Check device connection, logs, or increase _REBOOT_READY_RETRIES."
    )


def _sysreset_and_wait(at_cmd: ATCommandHelper) -> None:
    """Trigger cold reboot and wait for DUT to become ready.

    Cold reboot (SYSRESET=1) is used instead of warm reboot to ensure
    TYPE_POWER_ON boot type, avoiding EUI initialization assert when
    CONFIG_ATM_SETTINGS is not available.
    """
    at_cmd.send_command("SYSRESET=1", wait_for_ok=False)
    _wait_dut_ready(at_cmd)


# ── Test UUIDs (MSB-first, 32 hex chars) ─────────────────────────────────────
# Each test uses unique UUIDs to avoid global state pollution across reboots.

# Ordering error tests
SVC_ORDER = "D1A03E67E89B12D3A456426614174000"
CHAR_ORDER = "D1A03E67E89B12D3A456426614174001"
DESC_ORDER = "D1A03E67E89B12D3A456426614174002"

# Service permission validation
SVC_PERM = "D2B03E67E89B12D3A456426614174000"

# Activate / empty-service tests
SVC_EMPTY = "D3C03E67E89B12D3A456426614174000"
SVC_EMPTY2 = "D3C03E67E89B12D3A456426614174010"

# Add-char error tests
SVC_CHERR = "D4D03E67E89B12D3A456426614174000"
CHAR_CHERR = "D4D03E67E89B12D3A456426614174001"
DESC_CHERR = "D4D03E67E89B12D3A456426614174002"

# Add-char-to-active test
SVC_ACTIVE = "D5E03E67E89B12D3A456426614174000"
CHR_ACTIVE1 = "D5E03E67E89B12D3A456426614174001"
CHR_ACTIVE2 = "D5E03E67E89B12D3A456426614174002"

# Basic flow tests
SVC_FLOW1 = "D6F03E67E89B12D3A456426614174000"
CH_FLOW1 = "D6F03E67E89B12D3A456426614174001"
SVC_FLOW2 = "D6F13E67E89B12D3A456426614174010"
CH_FLOW2 = "D6F13E67E89B12D3A456426614174011"


def response_text(lines: list[str]) -> str:
    """Return joined upper-case response for substring assertions."""
    return " ".join(line for line in lines if line).upper()


def check_app_err(lines: list[str], hex_str: str) -> bool:
    """Return True if any response line contains the app_err hex code.

    Matches patterns like  +CMD:80  +CMD:0,80  etc.
    hex_str is the expected value as uppercase hex, e.g. "80", "83".
    """
    pat = re.compile(rf"[,:]0*{hex_str}\b", re.IGNORECASE)
    return any(pat.search(line) for line in lines)


@pytest.fixture
def cleanup_after_test(at_cmd: ATCommandHelper):
    """Perform cold reboot after the test to clear all staged/activated services.

    Used by tests that stage or activate services; those changes persist
    in firmware memory until reboot. Cold reboot (SYSRESET=1) is used to
    ensure proper EUI initialization on the next boot.
    """
    yield
    _sysreset_and_wait(at_cmd)


# ── Ordering errors (no state change; no cleanup needed) ─────────────────────


def test_addchar_without_service(at_cmd: ATCommandHelper):
    """ADDCHAR before ADDSERVICE → NO_SVC (0x83)."""
    lines = at_cmd.send_command(f"BLEGATTADDCHAR=0003,{CHAR_ORDER},16")
    assert at_cmd.check_error(lines)
    assert check_app_err(lines, "83"), "Expected app_err=83 (NO_SVC)"


def test_adddesc_without_char(at_cmd: ATCommandHelper):
    """ADDDESC before any ADDCHAR → NO_CHAR (0x84)."""
    lines = at_cmd.send_command("BLEGATTADDDESC=2902")
    assert at_cmd.check_error(lines)
    assert check_app_err(lines, "84"), "Expected app_err=84 (NO_CHAR)"


def test_adddescuserdfd_without_char(at_cmd: ATCommandHelper):
    """ADDDESCUSERDFD before any ADDCHAR → NO_CHAR (0x84)."""
    lines = at_cmd.send_command(f"BLEGATTADDDESCUSERDFD=0001,{DESC_ORDER},8")
    assert at_cmd.check_error(lines)
    assert check_app_err(lines, "84"), "Expected app_err=84 (NO_CHAR)"


def test_activate_without_any_service(at_cmd: ATCommandHelper):
    """BLEGATTSVCACTIVE with no staged service → NO_SVC (0x83)."""
    lines = at_cmd.send_command("BLEGATTSVCACTIVE=00")
    assert at_cmd.check_error(lines)
    assert check_app_err(lines, "83"), "Expected app_err=83 (NO_SVC)"


# ── Service sec_prop validation ───────────────────────────────────────────────


@pytest.mark.parametrize("prop", ["0002", "0008", "0020", "0003"])
def test_svc_write_bits_rejected(at_cmd: ATCommandHelper, prop: str):
    """Any WRITE-type bit in service sec_prop must be rejected (BLE spec: read-only)."""
    lines = at_cmd.send_command(f"BLEGATTADDSERVICE={prop},{SVC_PERM}")
    assert at_cmd.check_error(lines), f"sec_prop={prop} should be rejected"


@pytest.mark.parametrize("prop", ["0000", "0001"])
@pytest.mark.usefixtures("cleanup_after_test")
def test_svc_read_bits_accepted(at_cmd: ATCommandHelper, prop: str):
    """READ / NONE sec_prop must be accepted."""
    lines = at_cmd.send_command(f"BLEGATTADDSERVICE={prop},{SVC_PERM}")
    assert at_cmd.check_ok(lines), f"sec_prop={prop} should be accepted"


# ── Activate / empty-service tests ───────────────────────────────────────────


def test_activate_nonzero_reason(at_cmd: ATCommandHelper):
    """reason byte != 0x00 must return PARAM_INVALID (0x30)."""
    lines = at_cmd.send_command("BLEGATTSVCACTIVE=01")
    assert at_cmd.check_error(lines)
    assert check_app_err(lines, "30"), "Expected app_err=30 (PARAM_INVALID)"


@pytest.mark.usefixtures("cleanup_after_test")
def test_activate_empty_service(at_cmd: ATCommandHelper):
    """Staged service with no chars must succeed (BT Core Spec allows it).

    Per BT Core Spec, characteristics are optional in a service definition.
    """
    lines = at_cmd.send_command(f"BLEGATTADDSERVICE=0000,{SVC_EMPTY}")
    assert at_cmd.check_ok(lines), "ADDSERVICE must succeed"
    lines = at_cmd.send_command("BLEGATTSVCACTIVE=00")
    assert at_cmd.check_ok(lines), "BLEGATTSVCACTIVE with empty service must succeed"


@pytest.mark.usefixtures("cleanup_after_test")
def test_addservice_without_prior_char_allowed(at_cmd: ATCommandHelper):
    """Calling ADDSERVICE when previous service has no chars must succeed.

    Per BT Core Spec, services without characteristics are valid.
    """
    lines = at_cmd.send_command(f"BLEGATTADDSERVICE=0000,{SVC_EMPTY}")
    assert at_cmd.check_ok(lines), "First ADDSERVICE must succeed"
    lines = at_cmd.send_command(f"BLEGATTADDSERVICE=0000,{SVC_EMPTY2}")
    assert at_cmd.check_ok(lines), "Second ADDSERVICE (no prior char) must succeed"


# ── Add-char parameter validation ─────────────────────────────────────────────


@pytest.mark.parametrize("prop", ["0800", "FFFF"])
@pytest.mark.usefixtures("cleanup_after_test")
def test_char_invalid_sec_prop(at_cmd: ATCommandHelper, prop: str):
    """Out-of-range sec_prop for ADDCHAR must be rejected."""
    assert at_cmd.check_ok(
        at_cmd.send_command(f"BLEGATTADDSERVICE=0000,{SVC_CHERR}")
    ), "Setup: ADDSERVICE must succeed"
    assert at_cmd.check_ok(
        at_cmd.send_command(f"BLEGATTADDCHAR=0003,{CHAR_CHERR},16")
    ), "Setup: first ADDCHAR must succeed"
    lines = at_cmd.send_command(
        f"BLEGATTADDCHAR={prop},D4D03E67E89B12D3A456426614173900,16"
    )
    assert at_cmd.check_error(lines), f"sec_prop={prop} should be rejected"


@pytest.mark.usefixtures("cleanup_after_test")
def test_adddescuserdfd_notify_bit_rejected(at_cmd: ATCommandHelper):
    """ADDDESCUSERDFD with NOTIFY bit (0x0200) must return PARAM_INVALID (0x30).

    NOTIFY/INDICATE bits are valid for characteristics only, not descriptors.
    """
    assert at_cmd.check_ok(
        at_cmd.send_command(f"BLEGATTADDSERVICE=0000,{SVC_CHERR}")
    ), "Setup: ADDSERVICE must succeed"
    assert at_cmd.check_ok(
        at_cmd.send_command(f"BLEGATTADDCHAR=0003,{CHAR_CHERR},16")
    ), "Setup: ADDCHAR must succeed"
    lines = at_cmd.send_command(f"BLEGATTADDDESCUSERDFD=0200,{DESC_CHERR},8")
    assert at_cmd.check_error(lines)
    assert check_app_err(lines, "30"), "Expected app_err=30 (PARAM_INVALID)"


# ── Add char to active service ────────────────────────────────────────────────


@pytest.mark.usefixtures("cleanup_after_test")
def test_addchar_to_active_service(at_cmd: ATCommandHelper):
    """Adding a char to an already-active service → SVC_ACTIVE (0x80)."""
    assert at_cmd.check_ok(
        at_cmd.send_command(f"BLEGATTADDSERVICE=0000,{SVC_ACTIVE}")
    ), "Setup: ADDSERVICE must succeed"
    assert at_cmd.check_ok(
        at_cmd.send_command(f"BLEGATTADDCHAR=0003,{CHR_ACTIVE1},16")
    ), "Setup: ADDCHAR must succeed"
    assert at_cmd.check_ok(
        at_cmd.send_command("BLEGATTSVCACTIVE=00")
    ), "Setup: BLEGATTSVCACTIVE must succeed"

    lines = at_cmd.send_command(f"BLEGATTADDCHAR=0003,{CHR_ACTIVE2},16")
    assert at_cmd.check_error(lines)
    assert check_app_err(lines, "80"), "Expected app_err=80 (SVC_ACTIVE)"


# ── Basic happy-path flow ─────────────────────────────────────────────────────


@pytest.mark.usefixtures("cleanup_after_test")
def test_add_service_char_activate(at_cmd: ATCommandHelper):
    """Full add + activate sequence must succeed."""
    lines = at_cmd.send_command(f"BLEGATTADDSERVICE=0000,{SVC_FLOW1}")
    assert at_cmd.check_ok(lines), "BLEGATTADDSERVICE must succeed"

    lines = at_cmd.send_command(f"BLEGATTADDCHAR=0003,{CH_FLOW1},32")
    assert at_cmd.check_ok(lines), "BLEGATTADDCHAR must succeed"

    lines = at_cmd.send_command("BLEGATTSVCACTIVE=00")
    assert at_cmd.check_ok(lines), "BLEGATTSVCACTIVE must succeed"


@pytest.mark.usefixtures("cleanup_after_test")
def test_add_second_service_after_first(at_cmd: ATCommandHelper):
    """Add service + char + activate with a second UUID set → OK."""
    lines = at_cmd.send_command(f"BLEGATTADDSERVICE=0000,{SVC_FLOW2}")
    assert at_cmd.check_ok(lines), "ADDSERVICE must succeed"

    lines = at_cmd.send_command(f"BLEGATTADDCHAR=0001,{CH_FLOW2},8")
    assert at_cmd.check_ok(lines), "ADDCHAR must succeed"

    lines = at_cmd.send_command("BLEGATTSVCACTIVE=00")
    assert at_cmd.check_ok(lines), "BLEGATTSVCACTIVE must succeed"


if __name__ == "__main__":
    pytest.main([__file__, "-v"])
