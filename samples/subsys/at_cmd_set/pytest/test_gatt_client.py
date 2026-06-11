#!/usr/bin/env python3
# Copyright (c) 2026 Atmosic
#
# SPDX-License-Identifier: LicenseRef-Atmosic

"""
@file pytest/test_gatt_client.py

@brief Single-device GATT client AT command tests.

Validates GATT client commands (CONFIG_AT_CMD_CENTRAL=y) on a single device:
  - All GATT client commands return ERROR when no BLE connection is active
  - Parameter validation (invalid handle range, invalid CCC value)

No second device required.

"""

import pytest
from conftest import ATCommandHelper

pytestmark = pytest.mark.gatt_client

# ── Representative UUIDs (DFT server defaults) ────────────────────────────────
DFT_SVC_UUID = "123E4567E89B12D3A456426614174000"
DFT_CH1_UUID = "223E4567E89B12D3A456426614174000"


class TestGattClientNoConn:
    """All GATT client commands must return ERROR when no connection is active.

    Verifies that:
    1. Commands are compiled in (CONFIG_AT_CMD_CENTRAL=y selects them).
    2. The no-connection path returns a meaningful AT error (not a crash).
    """

    def test_disc_svcs_no_conn(self, at_cmd: ATCommandHelper):
        """AT+BLEGATTDISCSVCS must return ERROR when conn_idx=0 is not connected."""
        lines = at_cmd.send_command("BLEGATTDISCSVCS=0,1,65535,0")
        assert at_cmd.check_error(
            lines
        ), f"BLEGATTDISCSVCS should return ERROR with no connection (got: {lines})"

    def test_disc_svc_no_conn(self, at_cmd: ATCommandHelper):
        """AT+BLEGATTDISCSVC must return ERROR when conn_idx=0 is not connected."""
        lines = at_cmd.send_command(f"BLEGATTDISCSVC=0,{DFT_SVC_UUID}")
        assert at_cmd.check_error(
            lines
        ), f"BLEGATTDISCSVC should return ERROR with no connection (got: {lines})"

    def test_disc_chars_no_conn(self, at_cmd: ATCommandHelper):
        """AT+BLEGATTDISCCHARS must return ERROR when conn_idx=0 is not connected."""
        lines = at_cmd.send_command("BLEGATTDISCCHARS=0,1,65535,0")
        assert at_cmd.check_error(
            lines
        ), f"BLEGATTDISCCHARS should return ERROR with no connection (got: {lines})"

    def test_disc_char_no_conn(self, at_cmd: ATCommandHelper):
        """AT+BLEGATTDISCCHAR must return ERROR when conn_idx=0 is not connected."""
        lines = at_cmd.send_command(f"BLEGATTDISCCHAR=0,{DFT_CH1_UUID}")
        assert at_cmd.check_error(
            lines
        ), f"BLEGATTDISCCHAR should return ERROR with no connection (got: {lines})"

    def test_disc_descs_no_conn(self, at_cmd: ATCommandHelper):
        """AT+BLEGATTDISCDESCS must return ERROR when conn_idx=0 is not connected."""
        lines = at_cmd.send_command("BLEGATTDISCDESCS=0,1,65535,0")
        assert at_cmd.check_error(
            lines
        ), f"BLEGATTDISCDESCS should return ERROR with no connection (got: {lines})"

    def test_read_no_conn(self, at_cmd: ATCommandHelper):
        """AT+BLEGATTRD must return ERROR when conn_idx=0 is not connected."""
        lines = at_cmd.send_command("BLEGATTRD=0,1,0")
        assert at_cmd.check_error(
            lines
        ), f"BLEGATTRD should return ERROR with no connection (got: {lines})"

    def test_wr_no_conn(self, at_cmd: ATCommandHelper):
        """AT+BLEGATTWR must return ERROR when conn_idx=0 is not connected."""
        lines = at_cmd.send_command("BLEGATTWR=0,1,DEADBEEF")
        assert at_cmd.check_error(
            lines
        ), f"BLEGATTWR should return ERROR with no connection (got: {lines})"

    def test_wrwo_no_conn(self, at_cmd: ATCommandHelper):
        """AT+BLEGATTWRWO must return ERROR when conn_idx=0 is not connected."""
        lines = at_cmd.send_command("BLEGATTWRWO=0,1,DEADBEEF")
        assert at_cmd.check_error(
            lines
        ), f"BLEGATTWRWO should return ERROR with no connection (got: {lines})"

    def test_wrcccd_no_conn(self, at_cmd: ATCommandHelper):
        """AT+BLEGATTWRCCCD must return ERROR when conn_idx=0 is not connected."""
        lines = at_cmd.send_command("BLEGATTWRCCCD=0,18,19,1")
        assert at_cmd.check_error(
            lines
        ), f"BLEGATTWRCCCD should return ERROR with no connection (got: {lines})"

    def test_mtu_get_no_conn(self, at_cmd: ATCommandHelper):
        """AT+BLEGATTMTUGET must return ERROR when conn_idx=0 is not connected."""
        lines = at_cmd.send_command("BLEGATTMTUGET=0")
        assert at_cmd.check_error(
            lines
        ), f"BLEGATTMTUGET should return ERROR with no connection (got: {lines})"

    def test_mtu_exchg_no_conn(self, at_cmd: ATCommandHelper):
        """AT+BLEGATTMTUEXCHGREQ must return ERROR when conn_idx=0 is not connected."""
        lines = at_cmd.send_command("BLEGATTMTUEXCHGREQ=0")
        assert at_cmd.check_error(
            lines
        ), f"BLEGATTMTUEXCHGREQ should return ERROR with no connection (got: {lines})"


class TestGattClientParamValidation:
    """GATT client AT command parameter validation (independent of connection state)."""

    def test_disc_svcs_invalid_range(self, at_cmd: ATCommandHelper):
        """AT+BLEGATTDISCSVCS with start > end must return ERROR."""
        lines = at_cmd.send_command("BLEGATTDISCSVCS=0,100,50,0")
        assert at_cmd.check_error(
            lines
        ), f"BLEGATTDISCSVCS start>end should return ERROR (got: {lines})"

    def test_disc_svcs_zero_start(self, at_cmd: ATCommandHelper):
        """AT+BLEGATTDISCSVCS with start_handle=0 must return ERROR (handle 0 reserved)."""
        lines = at_cmd.send_command("BLEGATTDISCSVCS=0,0,65535,0")
        assert at_cmd.check_error(
            lines
        ), f"BLEGATTDISCSVCS handle=0 should return ERROR (got: {lines})"

    def test_disc_chars_invalid_range(self, at_cmd: ATCommandHelper):
        """AT+BLEGATTDISCCHARS with start > end must return ERROR."""
        lines = at_cmd.send_command("BLEGATTDISCCHARS=0,200,100,0")
        assert at_cmd.check_error(
            lines
        ), f"BLEGATTDISCCHARS start>end should return ERROR (got: {lines})"

    def test_disc_descs_invalid_range(self, at_cmd: ATCommandHelper):
        """AT+BLEGATTDISCDESCS with start > end must return ERROR."""
        lines = at_cmd.send_command("BLEGATTDISCDESCS=0,200,100,0")
        assert at_cmd.check_error(
            lines
        ), f"BLEGATTDISCDESCS start>end should return ERROR (got: {lines})"

    def test_wrcccd_invalid_ccc_value(self, at_cmd: ATCommandHelper):
        """AT+BLEGATTWRCCCD with ccc_value=3 must return ERROR (only 0/1/2 valid)."""
        lines = at_cmd.send_command("BLEGATTWRCCCD=0,18,19,3")
        assert at_cmd.check_error(
            lines
        ), f"BLEGATTWRCCCD ccc_value=3 should return ERROR (got: {lines})"


if __name__ == "__main__":
    pytest.main([__file__, "-v"])
