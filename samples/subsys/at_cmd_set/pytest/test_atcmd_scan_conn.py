#!/usr/bin/env python3
# Copyright (c) 2026 Atmosic
#
# SPDX-License-Identifier: LicenseRef-Atmosic

"""
@file pytest/test_atcmd_scan_conn.py

@brief Pytest tests for BLE scan and connection AT commands.

"""

import time

import pytest
from conftest import ATCommandHelper

pytestmark = pytest.mark.scan_conn


def response_text(lines: list[str]) -> str:
    """Normalize AT command response lines for substring assertions."""
    return " ".join(line for line in lines if line)


class TestBLEScanCommands:
    """BLE scan and advertising-report command tests."""

    @pytest.fixture(autouse=True, scope="class")
    def limit_scan_reports(self, at_cmd: ATCommandHelper):
        """Set RSSI filter to -60 before scan tests to reduce ADV report flooding.

        Only applied when the MAC filter is not active (i.e., RSSI filter is in
        effect). Suppressing weak advertisements keeps the serial RX buffer from
        being overwhelmed during the brief scan-enable windows used by these tests.
        Restored to the permissive boot default (-90) after all class tests complete.

        """
        lines = at_cmd.send_query("BLESCANFILRSSI")
        if at_cmd.check_ok(lines) and ":ON," in response_text(lines):
            at_cmd.send_command("AT+BLESCANFILRSSI=-60")
        yield
        at_cmd.send_command("AT+BLESCANFILRSSI=-90")

    def test_blescanenable_query(self, at_cmd: ATCommandHelper):
        """Test AT+BLESCANENABLE? query returns current scan state."""
        lines = at_cmd.send_query("BLESCANENABLE")
        assert at_cmd.check_ok(lines), "BLESCANENABLE query should return OK"
        text = response_text(lines)
        assert (
            "OFF" in text or "ON" in text
        ), "BLESCANENABLE query should return ON or OFF"

    def test_blescanenable_on_off(self, at_cmd: ATCommandHelper):
        """Test enabling and disabling BLE scanning."""
        lines = at_cmd.send_command("AT+BLESCANENABLE=ON")
        assert at_cmd.check_ok(lines), "BLESCANENABLE=ON should return OK"
        time.sleep(0.5)

        lines = at_cmd.send_query("BLESCANENABLE")
        assert at_cmd.check_ok(lines), "BLESCANENABLE query should return OK"
        assert "ON" in response_text(lines), "Scan should be reported enabled (ON)"

        lines = at_cmd.send_command("AT+BLESCANENABLE=OFF")
        assert at_cmd.check_ok(lines), "BLESCANENABLE=OFF should return OK"
        time.sleep(0.5)

        lines = at_cmd.send_query("BLESCANENABLE")
        assert at_cmd.check_ok(lines), "BLESCANENABLE query should return OK"
        assert "OFF" in response_text(lines), "Scan should be reported disabled (OFF)"

    def test_blescanfilrssi_busy_when_scanning(self, at_cmd: ATCommandHelper):
        """Test that AT+BLESCANFILRSSI is rejected with error while scan is active.

        RSSI and MAC filters are mutually exclusive: RSSI is the default filter
        and is automatically bypassed when AT+BLESCANFILMAC is enabled.

        """
        lines = at_cmd.send_command("AT+BLESCANENABLE=ON")
        assert at_cmd.check_ok(lines), "BLESCANENABLE=ON should return OK"
        time.sleep(0.3)

        lines = at_cmd.send_command("AT+BLESCANFILRSSI=-70")
        assert at_cmd.check_error(
            lines
        ), "BLESCANFILRSSI must return error (EBUSY) while scanning is active"

        lines = at_cmd.send_command("AT+BLESCANENABLE=OFF")
        assert at_cmd.check_ok(lines), "BLESCANENABLE=OFF should return OK"
        time.sleep(0.3)

        lines = at_cmd.send_command("AT+BLESCANFILRSSI=-70")
        assert at_cmd.check_ok(
            lines
        ), "BLESCANFILRSSI should succeed after scan stopped"

        # Clean up: reset RSSI threshold to boot default (most permissive)
        lines = at_cmd.send_command("AT+BLESCANFILRSSI=-90")
        assert at_cmd.check_ok(
            lines
        ), "BLESCANFILRSSI reset to default should return OK"

    def test_blescanfilmac_busy_when_scanning(self, at_cmd: ATCommandHelper):
        """Test that AT+BLESCANFILMAC is rejected with error while scan is active.

        RSSI and MAC filters are mutually exclusive: enabling MAC automatically
        bypasses the RSSI filter; disabling MAC restores it.

        """
        lines = at_cmd.send_command("AT+BLESCANENABLE=ON")
        assert at_cmd.check_ok(lines), "BLESCANENABLE=ON should return OK"
        time.sleep(0.3)

        lines = at_cmd.send_command("AT+BLESCANFILMAC=ON,0,AABBCCDDEEFF")
        assert at_cmd.check_error(
            lines
        ), "BLESCANFILMAC must return error (EBUSY) while scanning is active"

        lines = at_cmd.send_command("AT+BLESCANENABLE=OFF")
        assert at_cmd.check_ok(lines), "BLESCANENABLE=OFF should return OK"
        time.sleep(0.3)

        lines = at_cmd.send_command("AT+BLESCANFILMAC=ON,0,AABBCCDDEEFF")
        assert at_cmd.check_ok(lines), "BLESCANFILMAC should succeed after scan stopped"

        # Clean up: disable MAC filter (clears Filter Accept List)
        lines = at_cmd.send_command("AT+BLESCANFILMAC=OFF,0,AABBCCDDEEFF")
        assert at_cmd.check_ok(lines), "BLESCANFILMAC disable should return OK"

    def test_blescanfil_mutual_exclusivity(self, at_cmd: ATCommandHelper):
        """Test that RSSI and MAC filters are mutually exclusive.

        Verifies three transitions:
          1. MAC off  → BLESCANFILRSSI? reports ON  (RSSI in effect)
          2. MAC on   → BLESCANFILRSSI? reports OFF (RSSI bypassed by MAC)
          3. MAC off  → BLESCANFILRSSI? reports ON  (RSSI restored, threshold kept)

        """
        # Set RSSI threshold
        lines = at_cmd.send_command("AT+BLESCANFILRSSI=-70")
        assert at_cmd.check_ok(lines), "BLESCANFILRSSI set should return OK"

        # Transition 1: MAC off → RSSI active
        lines = at_cmd.send_query("BLESCANFILRSSI")
        assert at_cmd.check_ok(lines), "BLESCANFILRSSI query should return OK"
        text = response_text(lines)
        assert ":ON," in text, "RSSI filter must be active (ON) when MAC is off"

        # Transition 2: MAC on → RSSI bypassed
        lines = at_cmd.send_command("AT+BLESCANFILMAC=ON,0,AABBCCDDEEFF")
        assert at_cmd.check_ok(lines), "BLESCANFILMAC enable should return OK"

        lines = at_cmd.send_query("BLESCANFILRSSI")
        assert at_cmd.check_ok(lines), "BLESCANFILRSSI query should return OK"
        text = response_text(lines)
        assert ":OFF," in text, "RSSI filter must be bypassed (OFF) when MAC is on"

        # Transition 3: MAC off → RSSI restored, threshold preserved
        lines = at_cmd.send_command("AT+BLESCANFILMAC=OFF,0,AABBCCDDEEFF")
        assert at_cmd.check_ok(lines), "BLESCANFILMAC disable should return OK"

        lines = at_cmd.send_query("BLESCANFILRSSI")
        assert at_cmd.check_ok(lines), "BLESCANFILRSSI query should return OK"
        text = response_text(lines)
        assert ":ON," in text, "RSSI filter must be restored (ON) after MAC is off"
        assert "-70" in text, "RSSI threshold must be preserved across transitions"

        # Clean up: reset RSSI threshold to boot default
        lines = at_cmd.send_command("AT+BLESCANFILRSSI=-90")
        assert at_cmd.check_ok(
            lines
        ), "BLESCANFILRSSI reset to default should return OK"


class TestBLEGAPCreateConn:
    """Tests for AT+BLEGAPCREATECONN — initiates a central connection."""

    def test_blegapcreateconn_test_query(self, at_cmd: ATCommandHelper):
        """Test AT+BLEGAPCREATECONN=? returns the command parameter format."""
        lines = at_cmd.send_test("BLEGAPCREATECONN")
        assert at_cmd.check_ok(lines), "BLEGAPCREATECONN=? should return OK"

    def test_blegapcreateconn_invalid_addr_type(self, at_cmd: ATCommandHelper):
        """Test BLEGAPCREATECONN with addr_type=2 (>1) returns an error.

        The B(0~1) format constraint allows only 0 (public) or 1 (random).
        Providing 2 must result in an error response.

        """
        lines = at_cmd.send_command("AT+BLEGAPCREATECONN=2,010203040506,10")
        assert at_cmd.check_error(
            lines
        ), "BLEGAPCREATECONN with addr_type=2 should return error (PARAM_INVALID)"

    def test_blegapcreateconn_missing_params(self, at_cmd: ATCommandHelper):
        """Test BLEGAPCREATECONN with missing timeout_sec parameter returns an error."""
        lines = at_cmd.send_command("AT+BLEGAPCREATECONN=0,010203040506")
        assert at_cmd.check_error(
            lines
        ), "BLEGAPCREATECONN with missing timeout_sec should return error"


class TestBLEGAPCancelCreateConn:
    """Tests for AT+BLEGAPCANCELCREATECONN — cancels a pending connection creation.

    Distinct from BLEGAPDISCONNECT: cancel targets the initiating state before
    the link is established; disconnect terminates an already-connected slot.

    """

    def test_blegapcancelcreateconn_test_query(self, at_cmd: ATCommandHelper):
        """Test AT+BLEGAPCANCELCREATECONN=? returns the command parameter format."""
        lines = at_cmd.send_test("BLEGAPCANCELCREATECONN")
        assert at_cmd.check_ok(lines), "BLEGAPCANCELCREATECONN=? should return OK"

    def test_blegapcancelcreateconn_no_pending(self, at_cmd: ATCommandHelper):
        """Test BLEGAPCANCELCREATECONN returns error when no connection creation is pending.

        Without a prior successful BLEGAPCREATECONN, the handler rejects the
        cancel with AT_ERR_BLE_EINVAL (pending_create_conn flag is false).

        """
        lines = at_cmd.send_command("AT+BLEGAPCANCELCREATECONN=")
        assert at_cmd.check_error(
            lines
        ), "BLEGAPCANCELCREATECONN must return error (EINVAL) when no connection is pending"


class TestBLEGAPDisconnect:
    """Tests for AT+BLEGAPDISCONNECT — terminates an established connection slot.

    Distinct from BLEGAPCANCELCREATECONN: disconnect targets an already-connected
    slot identified by index; cancel targets the pending-creation state.

    """

    def test_blegapdisconnect_test_query(self, at_cmd: ATCommandHelper):
        """Test AT+BLEGAPDISCONNECT=? returns command format string."""
        lines = at_cmd.send_test("BLEGAPDISCONNECT")
        assert at_cmd.check_ok(
            lines
        ), "BLEGAPDISCONNECT=? must return OK with format string"

    def test_blegapdisconnect_no_connection(self, at_cmd: ATCommandHelper):
        """Test BLEGAPDISCONNECT returns error when no connection exists at index 0."""
        lines = at_cmd.send_command("AT+BLEGAPDISCONNECT=0")
        assert at_cmd.check_error(
            lines
        ), "BLEGAPDISCONNECT=0 must return error (ENOENT) when no connection exists"

    def test_blegapdisconnect_invalid_idx(self, at_cmd: ATCommandHelper):
        """Test BLEGAPDISCONNECT returns error for an out-of-range index (255)."""
        lines = at_cmd.send_command("AT+BLEGAPDISCONNECT=255")
        assert at_cmd.check_error(
            lines
        ), "BLEGAPDISCONNECT=255 must return error (ENOENT) for out-of-range index"


class TestBLEGAPGetConnStat:
    """Tests for AT+BLEGAPGETCONNSTAT — queries status of a tracked connection slot.

    Returns role, peer address, connection interval, latency and supervision
    timeout for the slot identified by index.

    """

    def test_blegapgetconnstat_test_query(self, at_cmd: ATCommandHelper):
        """Test AT+BLEGAPGETCONNSTAT=? returns command format string."""
        lines = at_cmd.send_test("BLEGAPGETCONNSTAT")
        assert at_cmd.check_ok(
            lines
        ), "BLEGAPGETCONNSTAT=? must return OK with format string"

    def test_blegapgetconnstat_no_connection(self, at_cmd: ATCommandHelper):
        """Test BLEGAPGETCONNSTAT returns error when no connection exists at index 0."""
        lines = at_cmd.send_command("AT+BLEGAPGETCONNSTAT=0")
        assert at_cmd.check_error(
            lines
        ), "BLEGAPGETCONNSTAT=0 must return error when no connection exists"

    def test_blegapgetconnstat_invalid_idx(self, at_cmd: ATCommandHelper):
        """Test BLEGAPGETCONNSTAT returns error for an out-of-range index (255)."""
        lines = at_cmd.send_command("AT+BLEGAPGETCONNSTAT=255")
        assert at_cmd.check_error(
            lines
        ), "BLEGAPGETCONNSTAT=255 must return error for out-of-range index"


class TestBLEConnTxPwr:
    """Tests for AT+BLECONNTXPWR — sets TX power for a specific connection slot.

    The command is exec-only: AT+BLECONNTXPWR=<conn_idx>,<dBm>.
    dBm must be in [-20, 10]; the RF driver rounds to the nearest supported level.
    Without an active connection the command returns an error.

    """

    def test_bleconntxpwr_test_query(self, at_cmd: ATCommandHelper):
        """Test AT+BLECONNTXPWR=? returns command format string."""
        lines = at_cmd.send_test("BLECONNTXPWR")
        assert at_cmd.check_ok(
            lines
        ), "BLECONNTXPWR=? must return OK with format string"

    def test_bleconntxpwr_no_connection(self, at_cmd: ATCommandHelper):
        """Test BLECONNTXPWR returns error when no connection exists at index 0."""
        lines = at_cmd.send_command("AT+BLECONNTXPWR=0,0")
        assert at_cmd.check_error(
            lines
        ), "BLECONNTXPWR=0,0 must return error when no connection exists"

    def test_bleconntxpwr_invalid_idx(self, at_cmd: ATCommandHelper):
        """Test BLECONNTXPWR returns error for an out-of-range index (255)."""
        lines = at_cmd.send_command("AT+BLECONNTXPWR=255,0")
        assert at_cmd.check_error(
            lines
        ), "BLECONNTXPWR=255,0 must return error for out-of-range index"

    def test_bleconntxpwr_invalid_dbm(self, at_cmd: ATCommandHelper):
        """Test BLECONNTXPWR returns error when dBm is outside the allowed range."""
        lines = at_cmd.send_command("AT+BLECONNTXPWR=0,50")
        assert at_cmd.check_error(
            lines
        ), "BLECONNTXPWR=0,50 must return error because 50 dBm exceeds the b(-20~10) range"


class TestBLEGAPGetPeerInfo:
    """Tests for AT+BLEGAPGETPEERINFO — queries peer identity and security info.

    Returns peer identity address type, peer identity address (6 bytes),
    security level (0–4) and encryption key size (0–16) for the connection
    slot identified by index.

    """

    def test_blegapgetpeerinfo_test_query(self, at_cmd: ATCommandHelper):
        """Test AT+BLEGAPGETPEERINFO=? returns command format string."""
        lines = at_cmd.send_test("BLEGAPGETPEERINFO")
        assert at_cmd.check_ok(
            lines
        ), "BLEGAPGETPEERINFO=? must return OK with format string"

    def test_blegapgetpeerinfo_no_connection(self, at_cmd: ATCommandHelper):
        """Test BLEGAPGETPEERINFO returns error when no connection exists at index 0."""
        lines = at_cmd.send_command("AT+BLEGAPGETPEERINFO=0")
        assert at_cmd.check_error(
            lines
        ), "BLEGAPGETPEERINFO=0 must return error when no connection exists"

    def test_blegapgetpeerinfo_invalid_idx(self, at_cmd: ATCommandHelper):
        """Test BLEGAPGETPEERINFO returns error for an out-of-range index (255)."""
        lines = at_cmd.send_command("AT+BLEGAPGETPEERINFO=255")
        assert at_cmd.check_error(
            lines
        ), "BLEGAPGETPEERINFO=255 must return error for out-of-range index"


class TestBLEGAPGetRSSI:
    """Tests for AT+BLEGAPGETRSSI — reads the RSSI of a tracked connection slot.

    Issues an HCI Read RSSI command for the slot identified by index and
    returns the received signal strength in dBm as a signed byte.
    Without an active connection the command returns an error.

    """

    def test_blegapgetrssi_test_query(self, at_cmd: ATCommandHelper):
        """Test AT+BLEGAPGETRSSI=? returns command format string."""
        lines = at_cmd.send_test("BLEGAPGETRSSI")
        assert at_cmd.check_ok(
            lines
        ), "BLEGAPGETRSSI=? must return OK with format string"

    def test_blegapgetrssi_no_connection(self, at_cmd: ATCommandHelper):
        """Test BLEGAPGETRSSI returns error when no connection exists at index 0."""
        lines = at_cmd.send_command("AT+BLEGAPGETRSSI=0")
        assert at_cmd.check_error(
            lines
        ), "BLEGAPGETRSSI=0 must return error when no connection exists"

    def test_blegapgetrssi_invalid_idx(self, at_cmd: ATCommandHelper):
        """Test BLEGAPGETRSSI returns error for an out-of-range index (255)."""
        lines = at_cmd.send_command("AT+BLEGAPGETRSSI=255")
        assert at_cmd.check_error(
            lines
        ), "BLEGAPGETRSSI=255 must return error for out-of-range index"


class TestBLEGAPParNego:
    """Tests for AT+BLEGAPPARNEGO — requests a BLE connection parameter update.

    The command calls bt_conn_le_param_update() for a tracked connection slot.
    Interval values are in 1.25 ms units; the supervision timeout is in 10 ms units.
    Without an active connection the command must return an error (AT_ERR_BLE_EINVAL).

    """

    def test_blegapparnego_test_query(self, at_cmd: ATCommandHelper):
        """Test AT+BLEGAPPARNEGO=? returns the command parameter format."""
        lines = at_cmd.send_test("BLEGAPPARNEGO")
        assert at_cmd.check_ok(
            lines
        ), "BLEGAPPARNEGO=? must return OK with format string"

    def test_blegapparnego_no_connection(self, at_cmd: ATCommandHelper):
        """Test BLEGAPPARNEGO returns error when no connection exists at index 0."""
        lines = at_cmd.send_command("AT+BLEGAPPARNEGO=0,24,40,0,400")
        assert at_cmd.check_error(
            lines
        ), "BLEGAPPARNEGO=0,... must return error when no connection exists"

    def test_blegapparnego_invalid_idx(self, at_cmd: ATCommandHelper):
        """Test BLEGAPPARNEGO returns error for an out-of-range connection index (255).

        The B(0~<CONN_IDX_MAX>) format constraint (CONN_IDX_MAX = BT_MAX_CONN - 1)
        rejects 255 before the handler is invoked.

        """
        lines = at_cmd.send_command("AT+BLEGAPPARNEGO=255,24,40,0,400")
        assert at_cmd.check_error(
            lines
        ), "BLEGAPPARNEGO=255,... must return error for out-of-range conn_idx"


class TestBLEGAPDevName:
    """Tests for AT+BLEGAPDEVNAME — get/set the BLE GAP device name.

    AT+BLEGAPDEVNAME=<name>  sets the GAP device name via bt_set_name() (exec)
    AT+BLEGAPDEVNAME?        reads the current name via bt_get_name() (query)
    Maximum name length is CONFIG_BT_DEVICE_NAME_MAX bytes (typically 28).

    """

    def test_blegapdevname_test_query(self, at_cmd: ATCommandHelper):
        """Test AT+BLEGAPDEVNAME=? returns the command parameter format."""
        lines = at_cmd.send_test("BLEGAPDEVNAME")
        assert at_cmd.check_ok(
            lines
        ), "BLEGAPDEVNAME=? must return OK with format string"

    def test_blegapdevname_query(self, at_cmd: ATCommandHelper):
        """Test AT+BLEGAPDEVNAME? returns the current GAP device name."""
        lines = at_cmd.send_query("BLEGAPDEVNAME")
        assert at_cmd.check_ok(lines), "BLEGAPDEVNAME query must return OK"
        assert any(
            "+BLEGAPDEVNAME:" in line for line in lines
        ), "BLEGAPDEVNAME query must include +BLEGAPDEVNAME: response line"

    def test_blegapdevname_set_and_restore(self, at_cmd: ATCommandHelper):
        """Test AT+BLEGAPDEVNAME=<name> sets the device name and is readable back."""
        test_name = "ATCMDTest"
        lines = at_cmd.send_command(f"AT+BLEGAPDEVNAME={test_name}")
        assert at_cmd.check_ok(lines), f"BLEGAPDEVNAME={test_name} must return OK"

        # Verify the name was applied.
        # bt_set_name() / bt_get_name() may uppercase the stored name on some
        # Zephyr targets, so compare case-insensitively.
        lines = at_cmd.send_query("BLEGAPDEVNAME")
        assert at_cmd.check_ok(lines), "BLEGAPDEVNAME query after set must return OK"
        assert any(
            test_name.lower() in line.lower() for line in lines
        ), f"BLEGAPDEVNAME query must return the newly-set name '{test_name}'"

        # Restore a safe default name
        lines = at_cmd.send_command("AT+BLEGAPDEVNAME=Atmosic")
        assert at_cmd.check_ok(lines), "BLEGAPDEVNAME restore must return OK"

    def test_blegapdevname_toolong(self, at_cmd: ATCommandHelper):
        """Test AT+BLEGAPDEVNAME with a name exceeding BT_DEVICE_NAME_MAX returns error.

        BT_DEVICE_NAME_MAX is typically 28 bytes. Sending 64 characters exceeds
        any reasonable limit and must be rejected with AT_ERR_PARAM_INVALID_LENGTH.

        """
        too_long = "A" * 64
        lines = at_cmd.send_command(f"AT+BLEGAPDEVNAME={too_long}")
        assert at_cmd.check_error(
            lines
        ), "BLEGAPDEVNAME with a name exceeding the maximum length must return error"
