#!/usr/bin/env python3
# Copyright (c) 2026 Atmosic
#
# SPDX-License-Identifier: LicenseRef-Atmosic

"""
@file pytest/test_atcmd_system.py

@brief Pytest tests for system basic AT commands.

"""

import re
import time

import pytest
from conftest import ATCommandHelper
from twister_harness import DeviceAdapter  # pylint: disable=import-error

pytestmark = pytest.mark.system

SYSSTORAGE_READY_PATTERN = re.compile(r"\+SYSSTORAGE:(READY|NOT_READY)")
SYSFUNCPIN_RSP_PATTERN = re.compile(r"\+SYSFUNCPIN:(\d+),(\d+),(\d+)")
SYSPM_RSP_PATTERN = re.compile(r"\+SYSPM:(\d+),(\d+),(\d+)")
SYSUARTBR_RSP_PATTERN = re.compile(r"\+SYSUARTBR:(\d+)")
SYSUARTFC_RSP_PATTERN = re.compile(r"\+SYSUARTFC:([01])")
SYSUARTRAW_RSP_PATTERN = re.compile(r"\+SYSUARTRAW:(\d+),(\d+),([01]),(\d+)")


class TestATCommandSystem:  # pylint: disable=too-few-public-methods
    """System AT command tests."""

    def test_sysbdaddr_query(self, at_cmd: ATCommandHelper):
        """SYSBDADDR query should report a Bluetooth address."""
        lines = at_cmd.send_query("SYSBDADDR")
        assert at_cmd.check_ok(lines), "SYSBDADDR query should return OK"
        assert at_cmd.extract_bd_addr(lines), "SYSBDADDR query should report an address"

    def test_sysbdaddr_set(self, at_cmd: ATCommandHelper):
        """SYSBDADDR should support setting a non-default identity when idle."""
        lines = at_cmd.send_test("SYSBDADDR")
        assert at_cmd.check_ok(lines), "SYSBDADDR test should return OK"

        lines = at_cmd.send_command("AT+SYSBDADDR=1,C21122334455")
        assert at_cmd.check_ok(
            lines
        ), "SYSBDADDR set on non-default identity should return OK"

    def test_sysbdaddr_set_reject_default_identity(self, at_cmd: ATCommandHelper):
        """SYSBDADDR should reject attempts to set identity 0."""
        lines = at_cmd.send_command("AT+SYSBDADDR=0,C21122334455")
        assert at_cmd.check_error(
            lines
        ), "SYSBDADDR should reject setting default identity"

    def test_sysbdaddr_set_reject_invalid_addr(self, at_cmd: ATCommandHelper):
        """SYSBDADDR should reject non-static-random addresses."""
        lines = at_cmd.send_command("AT+SYSBDADDR=1,001122334455")
        assert at_cmd.check_error(
            lines
        ), "SYSBDADDR should reject invalid identity address"

    def test_sysbdaddr_set_reject_while_advertising(self, at_cmd: ATCommandHelper):
        """SYSBDADDR should reject set when the target bt_id is currently advertising.

        adv index 0 defaults to bt_id 0.  We must first assign bt_id 1 to the
        instance (BLEADVSETID) and ensure the identity exists (SYSBDADDR while
        idle) before enabling advertising, so that sysbdaddr_adv_active(1)
        fires and triggers the EBUSY rejection.

        """
        # Ensure bt_id 1 exists before advertising with it
        lines = at_cmd.send_command("AT+SYSBDADDR=1,C21122334455")
        assert at_cmd.check_ok(
            lines
        ), "SYSBDADDR set on bt_id 1 while idle should return OK"

        # Assign bt_id 1 to adv instance 0
        lines = at_cmd.send_command("AT+BLEADVSETID=0,1")
        assert at_cmd.check_ok(lines), "BLEADVSETID=0,1 should return OK"

        lines = at_cmd.send_command("AT+BLEADVENABLE=0,ON")
        assert at_cmd.check_ok(lines), "BLEADVENABLE=0,ON should return OK"
        time.sleep(0.5)

        try:
            lines = at_cmd.send_command("AT+SYSBDADDR=1,C21122334455")
            assert at_cmd.check_error(
                lines
            ), "SYSBDADDR should reject set while bt_id 1 is advertising"
        finally:
            lines = at_cmd.send_command("AT+BLEADVENABLE=0,OFF")
            assert at_cmd.check_ok(lines), "BLEADVENABLE=0,OFF should return OK"
            time.sleep(0.5)
            # Restore adv instance 0 to the default bt_id 0
            lines = at_cmd.send_command("AT+BLEADVSETID=0,0")
            assert at_cmd.check_ok(lines), "BLEADVSETID=0,0 should return OK"

    def test_sysstorage_query(self, at_cmd: ATCommandHelper):
        """SYSSTORAGE query should report backend availability."""
        lines = at_cmd.send_query("SYSSTORAGE")
        assert at_cmd.check_ok(lines), "SYSSTORAGE query should return OK"
        assert any(
            SYSSTORAGE_READY_PATTERN.match(line) for line in lines
        ), "SYSSTORAGE query should report READY or NOT_READY"

    def test_sysstorage_exec(self, at_cmd: ATCommandHelper):
        """SYSSTORAGE should support SAVE and GET key/value actions."""
        storage_key = "ATCMD/TEST"
        storage_value = "VALUE123"

        lines = at_cmd.send_test("SYSSTORAGE")
        assert at_cmd.check_ok(lines), "SYSSTORAGE test should return OK"

        lines = at_cmd.send_command(f"AT+SYSSTORAGE=SAVE,{storage_key},{storage_value}")
        assert at_cmd.check_ok(lines), "SYSSTORAGE=SAVE should return OK"

        lines = at_cmd.send_command(f"AT+SYSSTORAGE=GET,{storage_key},")
        assert at_cmd.check_ok(lines), "SYSSTORAGE=GET should return OK"
        assert any(
            line == f"+SYSSTORAGE:{storage_key},{storage_value}" for line in lines
        ), "SYSSTORAGE=GET should return the stored key/value pair"

    def test_sysreset_exec(self, dut: DeviceAdapter, at_cmd: ATCommandHelper):
        """SYSRESET should reboot the target and return to ready state."""
        lines = at_cmd.send_test("SYSRESET")
        assert at_cmd.check_ok(lines), "SYSRESET test should return OK"

        at_cmd.send_command("AT+SYSRESET=1", wait_for_ok=False)
        lines = dut.readlines_until(regex=r"Ready for AT commands", timeout=30)
        assert any(
            "Ready for AT commands" in line for line in lines
        ), "Device should reboot and become ready again after SYSRESET"


class TestSYSFUNCPIN:
    """Tests for AT+SYSFUNCPIN command (Tier 1 — no GPIO trigger required)."""

    def test_sysfuncpin_test_form(self, at_cmd: ATCommandHelper):
        """AT+SYSFUNCPIN=? should return the parameter description and OK."""
        lines = at_cmd.send_test("SYSFUNCPIN")
        assert at_cmd.check_ok(lines), "SYSFUNCPIN=? should return OK"

    def test_sysfuncpin_query(self, at_cmd: ATCommandHelper):
        """AT+SYSFUNCPIN? should return +SYSFUNCPIN:<io>,<direction>,<signal> and OK."""
        lines = at_cmd.send_query("SYSFUNCPIN")
        assert at_cmd.check_ok(lines), "SYSFUNCPIN? should return OK"
        assert any(
            SYSFUNCPIN_RSP_PATTERN.match(line) for line in lines
        ), f"SYSFUNCPIN? response should match {SYSFUNCPIN_RSP_PATTERN.pattern}"

    def test_sysfuncpin_output_low(self, at_cmd: ATCommandHelper, funcpin_out_pin: int):
        """AT+SYSFUNCPIN=<out>,1,0 should configure the output pin as low and return OK."""
        lines = at_cmd.send_command(f"AT+SYSFUNCPIN={funcpin_out_pin},1,0")
        assert at_cmd.check_ok(lines), "SYSFUNCPIN output low should return OK"

    def test_sysfuncpin_output_high(
        self, at_cmd: ATCommandHelper, funcpin_out_pin: int
    ):
        """AT+SYSFUNCPIN=<out>,1,1 should configure the output pin as high and return OK."""
        lines = at_cmd.send_command(f"AT+SYSFUNCPIN={funcpin_out_pin},1,1")
        assert at_cmd.check_ok(lines), "SYSFUNCPIN output high should return OK"

    def test_sysfuncpin_query_after_exec(
        self, at_cmd: ATCommandHelper, funcpin_out_pin: int
    ):
        """AT+SYSFUNCPIN? should echo back the last configured io, direction, signal."""
        lines = at_cmd.send_command(f"AT+SYSFUNCPIN={funcpin_out_pin},1,1")
        assert at_cmd.check_ok(lines), "SYSFUNCPIN exec should return OK"

        lines = at_cmd.send_query("SYSFUNCPIN")
        assert at_cmd.check_ok(lines), "SYSFUNCPIN? should return OK"
        assert any(
            line == f"+SYSFUNCPIN:{funcpin_out_pin},1,1" for line in lines
        ), f"SYSFUNCPIN? should echo back {funcpin_out_pin},1,1; got: {lines}"

    def test_sysfuncpin_reject_output_pullup(
        self, at_cmd: ATCommandHelper, funcpin_out_pin: int
    ):
        """AT+SYSFUNCPIN with direction=output and signal=pull-up must be rejected."""
        lines = at_cmd.send_command(f"AT+SYSFUNCPIN={funcpin_out_pin},1,4")
        assert at_cmd.check_error(
            lines
        ), "SYSFUNCPIN output+pull-up should return ERROR"

    def test_sysfuncpin_input_pullup(
        self, at_cmd: ATCommandHelper, funcpin_in_pin: int
    ):
        """AT+SYSFUNCPIN=<in>,0,4 should configure the input pin with pull-up and return OK."""
        lines = at_cmd.send_command(f"AT+SYSFUNCPIN={funcpin_in_pin},0,4")
        assert at_cmd.check_ok(lines), "SYSFUNCPIN input pull-up should return OK"


class TestSYSPM:
    """Tests for AT+SYSPM command (Tier 1 — exec path intentionally excluded).

    AT+SYSPM=1,<io>,<level> calls atm_pseq_hibernate(IDLE_FOREVER) which puts
    the device into deep sleep permanently. Sending the exec command in an
    automated test would disconnect the device and hang the runner. Only the
    test form and query are verified here.

    For manual Tier 3 hardware testing of the exec path:
        AT+SYSPM=1,5,1   (hibernate, Button0 / P5 / gpio0-5, wake on HIGH)
        Press Button0 on the board to wake the device.

    """

    def test_syspm_test_form(self, at_cmd: ATCommandHelper):
        """AT+SYSPM=? should return the parameter description and OK."""
        lines = at_cmd.send_test("SYSPM")
        assert at_cmd.check_ok(lines), "SYSPM=? should return OK"

    def test_syspm_query(self, at_cmd: ATCommandHelper):
        """AT+SYSPM? should return +SYSPM:<mode>,<io>,<wakeup_level> and OK."""
        lines = at_cmd.send_query("SYSPM")
        assert at_cmd.check_ok(lines), "SYSPM? should return OK"
        assert any(
            SYSPM_RSP_PATTERN.match(line) for line in lines
        ), f"SYSPM? response should match {SYSPM_RSP_PATTERN.pattern}"


class TestSYSUARTBR:
    """Tests for AT+SYSUARTBR command (Tier 1 — exec path intentionally excluded).

    AT+SYSUARTBR=<baud_rate>,<defer_apply_cs> schedules uart_configure() on the
    console UART used by the AT command transport. Sending a valid exec command
    in an automated test would break serial I/O after the defer window expires.
    Only the test form, query, and invalid-parameter rejection are automated here.

    For manual Tier 3 hardware testing of the exec path:
        AT+SYSUARTBR=115200,10   (switch to 115200 baud, 100 ms defer)
        Switch the host serial port to 115200 within the 100 ms defer window.

    """

    def test_sysuartbr_test_form(self, at_cmd: ATCommandHelper):
        """AT+SYSUARTBR=? should return the parameter description and OK."""
        lines = at_cmd.send_test("SYSUARTBR")
        assert at_cmd.check_ok(lines), "SYSUARTBR=? should return OK"

    def test_sysuartbr_query(self, at_cmd: ATCommandHelper):
        """AT+SYSUARTBR? should return +SYSUARTBR:<baud_rate> and OK."""
        lines = at_cmd.send_query("SYSUARTBR")
        assert at_cmd.check_ok(lines), "SYSUARTBR? should return OK"
        assert any(
            SYSUARTBR_RSP_PATTERN.match(line) for line in lines
        ), f"SYSUARTBR? response should match {SYSUARTBR_RSP_PATTERN.pattern}"

    def test_sysuartbr_invalid_baud(self, at_cmd: ATCommandHelper):
        """AT+SYSUARTBR with a baud rate not in the allowed set must be rejected."""
        lines = at_cmd.send_command("AT+SYSUARTBR=9600,10")
        assert at_cmd.check_error(lines), "SYSUARTBR with 9600 should return ERROR"


class TestSYSUARTFC:
    """Tests for AT+SYSUARTFC command (Tier 1 — enable path excluded).

    AT+SYSUARTFC=1 enables RTS/CTS hardware flow control. On boards where the
    CTS line is not connected, enabling FC stalls UART TX and breaks the test
    runner's connection. Only the test form, query, and the safe disable path
    (action=0) are automated here.

    For manual Tier 3 hardware testing of the enable path (board with CTS/RTS wired):
        AT+SYSUARTFC=1   (enable RTS/CTS)
        AT+SYSUARTFC?    (verify +SYSUARTFC:1)
        AT+SYSUARTFC=0   (restore no flow control)

    """

    def test_sysuartfc_test_form(self, at_cmd: ATCommandHelper):
        """AT+SYSUARTFC=? should return the parameter description and OK."""
        lines = at_cmd.send_test("SYSUARTFC")
        assert at_cmd.check_ok(lines), "SYSUARTFC=? should return OK"

    def test_sysuartfc_query(self, at_cmd: ATCommandHelper):
        """AT+SYSUARTFC? should return +SYSUARTFC:<0|1> and OK."""
        lines = at_cmd.send_query("SYSUARTFC")
        assert at_cmd.check_ok(lines), "SYSUARTFC? should return OK"
        assert any(
            SYSUARTFC_RSP_PATTERN.match(line) for line in lines
        ), f"SYSUARTFC? response should match {SYSUARTFC_RSP_PATTERN.pattern}"

    def test_sysuartfc_disable(self, at_cmd: ATCommandHelper):
        """AT+SYSUARTFC=0 (disable flow control) should succeed."""
        lines = at_cmd.send_command("AT+SYSUARTFC=0")
        assert at_cmd.check_ok(lines), "SYSUARTFC=0 should return OK"

    def test_sysuartfc_query_after_disable(self, at_cmd: ATCommandHelper):
        """After AT+SYSUARTFC=0 the query should report +SYSUARTFC:0."""
        at_cmd.send_command("AT+SYSUARTFC=0")
        lines = at_cmd.send_query("SYSUARTFC")
        assert at_cmd.check_ok(lines), "SYSUARTFC? should return OK"
        assert any(
            line == "+SYSUARTFC:0" for line in lines
        ), "SYSUARTFC? should report 0 after disable"


class TestSYSUARTRAW:
    """Tests for AT+SYSUARTRAW command (Tier 1 — BT transfer path excluded).

    AT+SYSUARTRAW=<conn_idx>,<att_idx>,<direction>,<length>

    Triggers a bounded raw data transfer over BLE. The command auto-returns to
    AT mode after <length> bytes are transferred in the specified direction.
    Requires an active BLE connection and cannot be fully tested in automation.

    For manual Tier 3 hardware testing:
        Establish a BLE connection (conn_idx=0) with a peer
        AT+SYSUARTRAW=0,0,0,12   (UART→BLE: send 12 bytes then return to AT mode)
        Send 12 raw bytes over UART — they appear on the BLE peer as notifications
        AT+SYSUARTRAW=0,0,1,12   (BLE→UART: receive 12 bytes then return to AT mode)
        Peer writes 12 bytes to the data characteristic — bytes appear on UART

    """

    def test_sysuartraw_test_form(self, at_cmd: ATCommandHelper):
        """AT+SYSUARTRAW=? should return the parameter description and OK."""
        lines = at_cmd.send_test("SYSUARTRAW")
        assert at_cmd.check_ok(lines), "SYSUARTRAW=? should return OK"

    def test_sysuartraw_query(self, at_cmd: ATCommandHelper):
        """AT+SYSUARTRAW? should return +SYSUARTRAW:<conn_idx>,<att_idx>,<direction>,<length>."""
        lines = at_cmd.send_query("SYSUARTRAW")
        assert at_cmd.check_ok(lines), "SYSUARTRAW? should return OK"
        assert any(
            SYSUARTRAW_RSP_PATTERN.match(line) for line in lines
        ), f"SYSUARTRAW? response should match {SYSUARTRAW_RSP_PATTERN.pattern}"

    def test_sysuartraw_invalid_conn(self, at_cmd: ATCommandHelper):
        """AT+SYSUARTRAW=0,0,0,12 with no active BLE connection must be rejected."""
        lines = at_cmd.send_command("AT+SYSUARTRAW=0,0,0,12")
        assert at_cmd.check_error(
            lines
        ), "SYSUARTRAW=0,0,0,12 with no connection should return ERROR"
