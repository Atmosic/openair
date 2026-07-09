#!/usr/bin/env python3
# Copyright (c) 2026 Atmosic
#
# SPDX-License-Identifier: LicenseRef-Atmosic

"""
@file pytest/test_atcmd_adv.py

@brief Pytest tests for advertising-focused BLE AT commands.

"""

import re
import time

import pytest
from conftest import ATCommandHelper

pytestmark = pytest.mark.adv


def response_text(lines: list[str]) -> str:
    """Normalize AT command response lines for substring assertions."""
    return " ".join(line for line in lines if line)


class TestBLEAdvCommands:  # pylint: disable=too-few-public-methods
    """BLE advertising command tests."""

    def test_bleadvenable_query(self, at_cmd: ATCommandHelper):
        """Test AT+BLEADVENABLE? query."""
        lines = at_cmd.send_query("BLEADVENABLE")
        assert at_cmd.check_ok(lines), "BLEADVENABLE query should return OK"
        text = response_text(lines)
        assert "0" in text or "1" in text, "BLEADVENABLE should return 0 or 1"

    def test_bleadvenable_enable_disable(self, at_cmd: ATCommandHelper):
        """Test enabling and disabling advertising."""
        lines = at_cmd.send_command("AT+BLEADVENABLE=0,ON")
        assert at_cmd.check_ok(lines), "BLEADVENABLE=0,ON should return OK"
        time.sleep(0.5)

        lines = at_cmd.send_query("BLEADVENABLE")
        assert at_cmd.check_ok(lines), "BLEADVENABLE query should return OK"
        text = response_text(lines)
        assert (
            "0,1" in text or "+BLEADVENABLE:0,1" in text
        ), "Advertising should be enabled on instance 0"

        lines = at_cmd.send_command("AT+BLEADVENABLE=0,OFF")
        assert at_cmd.check_ok(lines), "BLEADVENABLE=0,OFF should return OK"
        time.sleep(0.5)

        lines = at_cmd.send_query("BLEADVENABLE")
        assert at_cmd.check_ok(lines), "BLEADVENABLE query should return OK"
        text = response_text(lines)
        assert (
            "0,0" in text or "+BLEADVENABLE:0,0" in text
        ), "Advertising should be disabled on instance 0"

    def test_bleadvtxpwr_query(self, at_cmd: ATCommandHelper):
        """Test AT+BLEADVTXPWR? query after creating an adv set."""
        lines = at_cmd.send_command("AT+BLEADVENABLE=0,ON")
        assert at_cmd.check_ok(lines), "BLEADVENABLE=0,ON should return OK"
        time.sleep(0.5)

        lines = at_cmd.send_query("BLEADVTXPWR")
        assert at_cmd.check_ok(lines), "BLEADVTXPWR query should return OK"
        assert re.search(
            r"\+BLEADVTXPWR:0,-?[0-9]+", response_text(lines)
        ), "BLEADVTXPWR query should return TX power for instance 0"

        lines = at_cmd.send_command("AT+BLEADVENABLE=0,OFF")
        assert at_cmd.check_ok(lines), "BLEADVENABLE=0,OFF should return OK"
        time.sleep(0.5)

    def test_bleadvdata_set_query(self, at_cmd: ATCommandHelper):
        """Test AT+BLEADVDATA set and query."""
        test_data = "0102030405"
        lines = at_cmd.send_command(f"AT+BLEADVDATA=0,{test_data}")
        assert at_cmd.check_ok(lines), "BLEADVDATA set should return OK"

        lines = at_cmd.send_query("BLEADVDATA")
        assert at_cmd.check_ok(lines), "BLEADVDATA query should return OK"
        assert f"+BLEADVDATA:0,{test_data}" in response_text(
            lines
        ), "BLEADVDATA query should return the stored data for instance 0"

    def test_blescanrspdata_set_query(self, at_cmd: ATCommandHelper):
        """Test AT+BLESCANRSPDATA set and query."""
        test_data = "0A0B0C0D"
        lines = at_cmd.send_command(f"AT+BLESCANRSPDATA=0,{test_data}")
        assert at_cmd.check_ok(lines), "BLESCANRSPDATA set should return OK"

        lines = at_cmd.send_query("BLESCANRSPDATA")
        assert at_cmd.check_ok(lines), "BLESCANRSPDATA query should return OK"
        assert f"+BLESCANRSPDATA:0,{test_data}" in response_text(
            lines
        ), "BLESCANRSPDATA query should return the stored data for instance 0"

    def test_bleadvsetid_set_query(self, at_cmd: ATCommandHelper):
        """Test AT+BLEADVSETID set and query."""
        lines = at_cmd.send_command("AT+BLEADVSETID=0,1")
        assert at_cmd.check_ok(lines), "BLEADVSETID set should return OK"

        lines = at_cmd.send_query("BLEADVSETID")
        assert at_cmd.check_ok(lines), "BLEADVSETID query should return OK"
        assert "0,1" in response_text(
            lines
        ), "BLEADVSETID query should return the assigned bt_id"

        lines = at_cmd.send_command("AT+BLEADVSETID=0,0")
        assert at_cmd.check_ok(lines), "BLEADVSETID reset should return OK"

    def test_bleextadvparm_set_query(self, at_cmd: ATCommandHelper):
        """Test AT+BLEEXTADVPARM set and query."""
        lines = at_cmd.send_command("AT+BLEEXTADVPARM=0,32,48,0,1")
        assert at_cmd.check_ok(lines), "BLEEXTADVPARM set should return OK"

        lines = at_cmd.send_query("BLEEXTADVPARM")
        assert at_cmd.check_ok(lines), "BLEEXTADVPARM query should return OK"
        assert "0,32,48,0,1" in response_text(
            lines
        ), "BLEEXTADVPARM query should return the configured values"

    def test_bleadvlegacyparm_set_query(self, at_cmd: ATCommandHelper):
        """Test AT+BLEADVLEGACYPARM set and query."""
        lines = at_cmd.send_command("AT+BLEADVLEGACYPARM=0,32,48,0")
        assert at_cmd.check_ok(lines), "BLEADVLEGACYPARM set should return OK"

        lines = at_cmd.send_query("BLEADVLEGACYPARM")
        assert at_cmd.check_ok(lines), "BLEADVLEGACYPARM query should return OK"
        assert "0,32,48,0" in response_text(
            lines
        ), "BLEADVLEGACYPARM query should return the configured values"
