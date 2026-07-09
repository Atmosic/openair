#!/usr/bin/env python3
# Copyright (c) 2026 Atmosic
#
# SPDX-License-Identifier: LicenseRef-Atmosic

"""
@file pytest/test_evt_cb.py

@brief Pytest tests for AT event and callback commands: TESTEVENT, TESTCB.

These commands test the event system and callback registration framework
when AT_EVT_CB_TEST is enabled via Kconfig.

"""

import logging
import re

from conftest import ATCommandHelper

logger = logging.getLogger(__name__)

# AT+TESTEVENT response pattern: +TESTEVENT:<type>,<hex_data>
_EVT_RSP_RE = re.compile(r"\+TESTEVENT:(\d+),([0-9A-Fa-f]*)")


class TestEvtCb:
    """Tests for AT+TESTCBEVT command."""

    def test_listcmds_includes_testcbevt(self, at_cmd: ATCommandHelper):
        """AT+LISTCMDS? output should include TESTCBEVT."""
        lines = at_cmd.send_query("LISTCMDS")
        content = "\n".join(lines)
        assert (
            "+TESTCBEVT:" in content
        ), "LISTCMDS? should list TESTCBEVT when AT_EVT_CB_TEST enabled"

    def test_testcbevt_register_returns_ok(self, at_cmd: ATCommandHelper):
        """AT+TESTCBEVT=0 (register callback) should return OK."""
        response = at_cmd.send_command("TESTCBEVT=0")
        assert at_cmd.check_ok(response), "AT+TESTCBEVT=0 (register) should return OK"

    def test_testcbevt_invoke_returns_ok(self, at_cmd: ATCommandHelper):
        """AT+TESTCBEVT=1 (invoke callback) should return OK."""
        response = at_cmd.send_command("TESTCBEVT=1")
        assert at_cmd.check_ok(response), "AT+TESTCBEVT=1 (invoke) should return OK"

    def test_testcbevt_test_command_returns_ok(self, at_cmd: ATCommandHelper):
        """AT+TESTCBEVT=? (test command) should return OK."""
        response = at_cmd.send_test("TESTCBEVT")
        assert at_cmd.check_ok(response), "AT+TESTCBEVT=? should return OK"
