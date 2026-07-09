#!/usr/bin/env python3
# Copyright (c) 2026 Atmosic
#
# SPDX-License-Identifier: LicenseRef-Atmosic

"""
@file pytest/test_atcmd.py

@brief Pytest tests for BLE AT Command sample.

This module contains test cases for verifying AT command functionality
over UART. Tests are run using Twister with the pytest harness.

"""

import logging
import re

import pytest
from conftest import ATCommandHelper
from twister_harness import DeviceAdapter  # pylint: disable=import-error

pytestmark = pytest.mark.basic

logger = logging.getLogger(__name__)
LIST_CMD_PATTERN = re.compile(r"\+([A-Z0-9]+):")
EXPECTED_AT_COMMANDS = {
    "BLEADVDATA",
    "BLEADVENABLE",
    "BLEADVLEGACYPARM",
    "BLEADVSETID",
    "BLEADVTXPWR",
    "BLECONNTXPWR",
    "BLEEXTADVPARM",
    "BLESCANRSPDATA",
    "SYSBDADDR",
    "SYSRESET",
    "SYSSTORAGE",
}


def get_listed_commands(at_cmd: ATCommandHelper) -> set[str]:
    """Return the command names reported by AT+LISTCMDS?."""
    lines = at_cmd.send_query("LISTCMDS")
    assert at_cmd.check_ok(lines), "LISTCMDS query should return OK"
    return {match.group(1) for line in lines if (match := LIST_CMD_PATTERN.match(line))}


class TestATCommandBasic:  # pylint: disable=too-few-public-methods
    """Basic AT command tests."""

    def test_device_ready(self, dut: DeviceAdapter):
        """Verify device boots and is ready for AT commands."""
        logger.info("Waiting for device to be ready...")
        lines = dut.readlines_until(regex=r"Ready for AT commands", timeout=30)
        assert any(
            "Ready for AT commands" in line for line in lines
        ), "Device did not report ready for AT commands"
        logger.info("Device is ready for AT commands")

    def test_list_commands(self, at_cmd: ATCommandHelper):
        """Test AT+LISTCMDS? command to list available commands."""
        listed_cmds = get_listed_commands(at_cmd)
        logger.info("Found %d commands: %s", len(listed_cmds), sorted(listed_cmds))
        assert listed_cmds, "Should list at least one command"
        missing = EXPECTED_AT_COMMANDS - listed_cmds
        assert not missing, f"Missing expected AT commands: {sorted(missing)}"


class TestInvalidCommands:  # pylint: disable=too-few-public-methods
    """Tests for invalid/error scenarios."""

    def test_invalid_command(self, at_cmd: ATCommandHelper):
        """Test that invalid command returns ERROR."""
        lines = at_cmd.send_command("AT+INVALIDCMD123")
        assert at_cmd.check_error(lines), "Invalid command should return ERROR"

    def test_empty_command(self, at_cmd: ATCommandHelper):
        """Test empty command handling."""
        lines = at_cmd.send_command("AT+", wait_for_ok=False)
        # Should either return error or be ignored
        logger.info("Empty command response: %s", lines)


if __name__ == "__main__":
    pytest.main([__file__, "-v"])
