#!/usr/bin/env python3
# Copyright (c) 2026 Atmosic
#
# SPDX-License-Identifier: LicenseRef-Atmosic

"""
@file pytest/test_atcmd_gatt.py

@brief Automated pytest tests for GATT default server AT commands.

All tests run without a phone. Tests cover server enable/disable, UUID and
sec_prop configuration, service permission validation, characteristic read-value
buffer, sec_prop combinations, and live UUID updates.

"""

import logging

import pytest
from conftest import ATCommandHelper

pytestmark = pytest.mark.gatt

logger = logging.getLogger(__name__)

# ── Default values (must match firmware defaults in at_cmd_gatt.c) ──────────
DFT_SVC_PROP = "0000"
DFT_SVC_UUID = "123E4567E89B12D3A456426614174000"
DFT_CH1_PROP = "0202"  # BT_GATT_PERM_WRITE | NOTIFY_BIT
DFT_CH1_UUID = "223E4567E89B12D3A456426614174000"
DFT_CH2_PROP = "0602"  # BT_GATT_PERM_WRITE | NOTIFY_BIT | INDICATE_BIT
DFT_CH2_UUID = "323E4567E89B12D3A456426614174000"

ALT_SVC_UUID = "AA3E4567E89B12D3A456426614174000"
ALT_CH1_UUID = "BB3E4567E89B12D3A456426614174000"
ALT_CH2_UUID = "CC3E4567E89B12D3A456426614174000"

READ_VAL = "DEADBEEF"


def response_text(lines: list[str]) -> str:
    """Return joined upper-case response text for substring assertions."""
    return " ".join(line for line in lines if line).upper()


def _restore_defaults(at_cmd: ATCommandHelper) -> None:
    """Restore firmware to a known clean state (server OFF, default UUIDs)."""
    at_cmd.send_command("BLEGATTDFTSERVER=OFF")
    at_cmd.send_command(f"BLEGATTDFTSERVICE={DFT_SVC_PROP},{DFT_SVC_UUID}")
    at_cmd.send_command(f"BLEGATTDFTCHAR1={DFT_CH1_PROP},{DFT_CH1_UUID}")
    at_cmd.send_command(f"BLEGATTDFTCHAR2={DFT_CH2_PROP},{DFT_CH2_UUID}")


# ── Test classes ─────────────────────────────────────────────────────────────


class TestGattBootDefaults:
    """Verify firmware reports correct default values after initialization."""

    @pytest.fixture(autouse=True)
    def setup_defaults(self, at_cmd: ATCommandHelper):
        """Restore defaults before and after each test."""
        _restore_defaults(at_cmd)
        yield
        _restore_defaults(at_cmd)

    def test_server_default_off(self, at_cmd: ATCommandHelper):
        """Server must be OFF at boot (not persisted)."""
        lines = at_cmd.send_query("BLEGATTDFTSERVER")
        assert at_cmd.check_ok(lines)
        assert "OFF" in response_text(lines)

    def test_service_defaults(self, at_cmd: ATCommandHelper):
        """Service UUID and sec_prop must match compile-time defaults."""
        lines = at_cmd.send_query("BLEGATTDFTSERVICE")
        assert at_cmd.check_ok(lines)
        text = response_text(lines)
        assert DFT_SVC_UUID in text
        assert DFT_SVC_PROP in text

    def test_char1_defaults(self, at_cmd: ATCommandHelper):
        """Char1 UUID and sec_prop must match compile-time defaults."""
        lines = at_cmd.send_query("BLEGATTDFTCHAR1")
        assert at_cmd.check_ok(lines)
        text = response_text(lines)
        assert DFT_CH1_UUID in text
        assert DFT_CH1_PROP in text

    def test_char2_defaults(self, at_cmd: ATCommandHelper):
        """Char2 UUID and sec_prop must match compile-time defaults."""
        lines = at_cmd.send_query("BLEGATTDFTCHAR2")
        assert at_cmd.check_ok(lines)
        text = response_text(lines)
        assert DFT_CH2_UUID in text
        assert DFT_CH2_PROP in text


class TestGattServerOnOff:
    """Verify AT+BLEGATTDFTSERVER ON/OFF control and edge cases."""

    @pytest.fixture(autouse=True)
    def setup_defaults(self, at_cmd: ATCommandHelper):
        """Restore defaults before and after each test."""
        _restore_defaults(at_cmd)
        yield
        _restore_defaults(at_cmd)

    def test_server_on(self, at_cmd: ATCommandHelper):
        """Server ON command must succeed."""
        lines = at_cmd.send_command("BLEGATTDFTSERVER=ON")
        assert at_cmd.check_ok(lines)

    def test_server_query_on(self, at_cmd: ATCommandHelper):
        """Query after ON must return ON state."""
        at_cmd.send_command("BLEGATTDFTSERVER=ON")
        lines = at_cmd.send_query("BLEGATTDFTSERVER")
        assert at_cmd.check_ok(lines)
        assert "ON" in response_text(lines)

    def test_server_on_idempotent(self, at_cmd: ATCommandHelper):
        """Calling ON twice must succeed."""
        at_cmd.send_command("BLEGATTDFTSERVER=ON")
        lines = at_cmd.send_command("BLEGATTDFTSERVER=ON")
        assert at_cmd.check_ok(lines)

    def test_server_off(self, at_cmd: ATCommandHelper):
        """Server OFF after ON must succeed."""
        at_cmd.send_command("BLEGATTDFTSERVER=ON")
        lines = at_cmd.send_command("BLEGATTDFTSERVER=OFF")
        assert at_cmd.check_ok(lines)

    def test_server_query_off(self, at_cmd: ATCommandHelper):
        """Query after OFF must return OFF state."""
        at_cmd.send_command("BLEGATTDFTSERVER=ON")
        at_cmd.send_command("BLEGATTDFTSERVER=OFF")
        lines = at_cmd.send_query("BLEGATTDFTSERVER")
        assert at_cmd.check_ok(lines)
        assert "OFF" in response_text(lines)

    def test_server_off_idempotent(self, at_cmd: ATCommandHelper):
        """Calling OFF twice must succeed."""
        lines = at_cmd.send_command("BLEGATTDFTSERVER=OFF")
        assert at_cmd.check_ok(lines)

    def test_server_invalid_param(self, at_cmd: ATCommandHelper):
        """Invalid parameter must return error."""
        lines = at_cmd.send_command("BLEGATTDFTSERVER=INVALID")
        assert at_cmd.check_error(lines)


class TestGattConfigOffline:
    """UUID and sec_prop changes while server is OFF (stored to Settings)."""

    @pytest.fixture(autouse=True)
    def setup_defaults(self, at_cmd: ATCommandHelper):
        """Restore defaults before and after each test."""
        _restore_defaults(at_cmd)
        yield
        _restore_defaults(at_cmd)

    def test_service_uuid_set(self, at_cmd: ATCommandHelper):
        """Set service UUID and verify via query."""
        lines = at_cmd.send_command(f"BLEGATTDFTSERVICE=0000,{ALT_SVC_UUID}")
        assert at_cmd.check_ok(lines)
        lines = at_cmd.send_query("BLEGATTDFTSERVICE")
        assert ALT_SVC_UUID in response_text(lines)

    def test_char1_set_read_only(self, at_cmd: ATCommandHelper):
        """Set Char1 to READ-only sec_prop and verify."""
        lines = at_cmd.send_command(f"BLEGATTDFTCHAR1=0001,{ALT_CH1_UUID}")
        assert at_cmd.check_ok(lines)
        lines = at_cmd.send_query("BLEGATTDFTCHAR1")
        text = response_text(lines)
        assert ALT_CH1_UUID in text
        assert "0001" in text

    def test_char2_set_notify_indicate(self, at_cmd: ATCommandHelper):
        """Set Char2 to NOTIFY+INDICATE sec_prop and verify."""
        lines = at_cmd.send_command(f"BLEGATTDFTCHAR2=0600,{ALT_CH2_UUID}")
        assert at_cmd.check_ok(lines)
        lines = at_cmd.send_query("BLEGATTDFTCHAR2")
        text = response_text(lines)
        assert ALT_CH2_UUID in text
        assert "0600" in text


class TestGattServicePermValidation:
    """Service Declaration must only accept READ-type permissions (BLE spec)."""

    @pytest.fixture(autouse=True)
    def setup_defaults(self, at_cmd: ATCommandHelper):
        """Restore defaults before and after each test."""
        _restore_defaults(at_cmd)
        yield
        _restore_defaults(at_cmd)

    @pytest.mark.parametrize("prop", ["0002", "0008", "0020", "0100", "0003"])
    def test_write_bits_rejected(self, at_cmd: ATCommandHelper, prop: str):
        """Any WRITE-type bit in sec_prop must be rejected."""
        lines = at_cmd.send_command(f"BLEGATTDFTSERVICE={prop},{DFT_SVC_UUID}")
        assert at_cmd.check_error(lines), f"sec_prop={prop} should be rejected"

    @pytest.mark.parametrize("prop", ["0000", "0001", "0004", "0010", "0080"])
    def test_read_bits_accepted(self, at_cmd: ATCommandHelper, prop: str):
        """READ-type or NONE sec_prop must be accepted."""
        lines = at_cmd.send_command(f"BLEGATTDFTSERVICE={prop},{DFT_SVC_UUID}")
        assert at_cmd.check_ok(lines), f"sec_prop={prop} should be accepted"


class TestGattCharVal:
    """Verify AT+BLEGATTDFTCHAR*VAL set/query/clear."""

    @pytest.fixture(autouse=True)
    def setup_defaults(self, at_cmd: ATCommandHelper):
        """Restore defaults before and after each test."""
        _restore_defaults(at_cmd)
        yield
        _restore_defaults(at_cmd)

    def test_char1_val_set(self, at_cmd: ATCommandHelper):
        """Set Char1 read value must succeed."""
        lines = at_cmd.send_command(f"BLEGATTDFTCHAR1VAL={READ_VAL}")
        assert at_cmd.check_ok(lines)

    def test_char1_val_query(self, at_cmd: ATCommandHelper):
        """Query Char1 read value must return stored data."""
        at_cmd.send_command(f"BLEGATTDFTCHAR1VAL={READ_VAL}")
        lines = at_cmd.send_query("BLEGATTDFTCHAR1VAL")
        assert at_cmd.check_ok(lines)
        assert READ_VAL in response_text(lines)

    def test_char2_val_set(self, at_cmd: ATCommandHelper):
        """Set Char2 read value must succeed."""
        lines = at_cmd.send_command(f"BLEGATTDFTCHAR2VAL={READ_VAL}")
        assert at_cmd.check_ok(lines)

    def test_char2_val_query(self, at_cmd: ATCommandHelper):
        """Query Char2 read value must return stored data."""
        at_cmd.send_command(f"BLEGATTDFTCHAR2VAL={READ_VAL}")
        lines = at_cmd.send_query("BLEGATTDFTCHAR2VAL")
        assert at_cmd.check_ok(lines)
        assert READ_VAL in response_text(lines)

    def test_char1_val_clear(self, at_cmd: ATCommandHelper):
        """Empty payload clears the buffer; query must still return OK."""
        at_cmd.send_command(f"BLEGATTDFTCHAR1VAL={READ_VAL}")
        lines = at_cmd.send_command("BLEGATTDFTCHAR1VAL=")
        assert at_cmd.check_ok(lines)
        lines = at_cmd.send_query("BLEGATTDFTCHAR1VAL")
        assert at_cmd.check_ok(lines)


class TestGattSecPropCombinations:
    """Verify all valid sec_prop bit patterns are accepted; out-of-range rejected."""

    @pytest.fixture(autouse=True)
    def setup_defaults(self, at_cmd: ATCommandHelper):
        """Restore defaults and turn server ON before each test."""
        _restore_defaults(at_cmd)
        at_cmd.send_command("BLEGATTDFTSERVER=ON")
        yield
        _restore_defaults(at_cmd)

    @pytest.mark.parametrize(
        "prop,desc",
        [
            ("0000", "NONE"),
            ("0001", "READ"),
            ("0002", "WRITE"),
            ("0200", "NOTIFY"),
            ("0400", "INDICATE"),
            ("0600", "NOTIFY+INDICATE"),
            ("0201", "READ+NOTIFY"),
            ("0202", "WRITE+NOTIFY (char1 default)"),
            ("0602", "WRITE+NOTIFY+INDICATE (char2 default)"),
            ("0103", "READ+WRITE+READ_ENCRYPT"),
            ("07FF", "all valid bits"),
        ],
    )
    def test_valid_sec_prop(self, at_cmd: ATCommandHelper, prop: str, desc: str):
        """All in-range sec_prop combinations must be accepted."""
        lines = at_cmd.send_command(f"BLEGATTDFTCHAR1={prop},{DFT_CH1_UUID}")
        assert at_cmd.check_ok(lines), f"sec_prop={prop} ({desc}) should be accepted"

    @pytest.mark.parametrize("prop", ["0800", "FFFF"])
    def test_invalid_sec_prop(self, at_cmd: ATCommandHelper, prop: str):
        """Bits above the valid mask must be rejected."""
        lines = at_cmd.send_command(f"BLEGATTDFTCHAR1={prop},{DFT_CH1_UUID}")
        assert at_cmd.check_error(lines), f"sec_prop={prop} should be rejected"


class TestGattUuidChangeLive:
    """UUID updates while server is ON and no connection (immediate re-register)."""

    @pytest.fixture(autouse=True)
    def setup_defaults(self, at_cmd: ATCommandHelper):
        """Restore defaults and turn server ON before each test."""
        _restore_defaults(at_cmd)
        at_cmd.send_command("BLEGATTDFTSERVER=ON")
        yield
        _restore_defaults(at_cmd)

    def test_service_uuid_live_update(self, at_cmd: ATCommandHelper):
        """Update service UUID while server ON and verify."""
        lines = at_cmd.send_command(f"BLEGATTDFTSERVICE=0000,{ALT_SVC_UUID}")
        assert at_cmd.check_ok(lines)
        lines = at_cmd.send_query("BLEGATTDFTSERVICE")
        assert ALT_SVC_UUID in response_text(lines)

    def test_char1_uuid_live_update(self, at_cmd: ATCommandHelper):
        """Update Char1 UUID while server ON and verify."""
        lines = at_cmd.send_command(f"BLEGATTDFTCHAR1=0202,{ALT_CH1_UUID}")
        assert at_cmd.check_ok(lines)
        lines = at_cmd.send_query("BLEGATTDFTCHAR1")
        assert ALT_CH1_UUID in response_text(lines)

    def test_char2_uuid_live_update(self, at_cmd: ATCommandHelper):
        """Update Char2 UUID while server ON and verify."""
        lines = at_cmd.send_command(f"BLEGATTDFTCHAR2=0602,{ALT_CH2_UUID}")
        assert at_cmd.check_ok(lines)
        lines = at_cmd.send_query("BLEGATTDFTCHAR2")
        assert ALT_CH2_UUID in response_text(lines)


if __name__ == "__main__":
    pytest.main([__file__, "-v"])
