#!/usr/bin/env python3
# Copyright (c) 2026 Atmosic
#
# SPDX-License-Identifier: LicenseRef-Atmosic

"""
@file pytest/test_builtin_cmds.py

@brief Pytest tests for embedded (built-in) AT commands: LISTCMDS, DEBUG, TESTCMD.

These commands are always registered by the AT command framework via
the NO_AT_CMD_BUILTIN guard in at_cmd.c and require no extra Kconfig.

"""

import logging
import re

import pytest
from conftest import ATCommandHelper

logger = logging.getLogger(__name__)

# AT+TESTCMD response pattern: +TESTCMD:<byte_dec>,<string>,<hex_array>
_TEST_RSP_RE = re.compile(r"\+TESTCMD:(\d+),(\w*),([0-9A-Fa-f]+)")


class TestListCmds:
    """Tests for AT+LISTCMDS command."""

    def test_listcmds_query_returns_ok(self, at_cmd: ATCommandHelper):
        """AT+LISTCMDS? should list all commands and return OK."""
        lines = at_cmd.send_query("LISTCMDS")
        assert at_cmd.check_ok(lines), "LISTCMDS? should return OK"

    def test_listcmds_query_includes_builtins(self, at_cmd: ATCommandHelper):
        """AT+LISTCMDS? output should include all three built-in commands."""
        lines = at_cmd.send_query("LISTCMDS")
        content = "\n".join(lines)
        assert "+LISTCMDS:" in content, "LISTCMDS? should list LISTCMDS itself"
        assert "+DEBUG:" in content, "LISTCMDS? should list DEBUG"
        assert "+TESTCMD:" in content, "LISTCMDS? should list TESTCMD"

    def test_listcmds_test_cmd(self, at_cmd: ATCommandHelper):
        """AT+LISTCMDS=? should return test description and OK."""
        lines = at_cmd.send_test("LISTCMDS")
        assert at_cmd.check_ok(lines), "LISTCMDS=? should return OK"
        assert any(
            "+LISTCMDS:" in line for line in lines
        ), "LISTCMDS=? should return +LISTCMDS:<desc>"


class TestDebug:
    """Tests for AT+DEBUG command."""

    def test_debug_enable(self, at_cmd: ATCommandHelper):
        """AT+DEBUG=1 should enable debug and return OK."""
        lines = at_cmd.send_command("AT+DEBUG=1")
        assert at_cmd.check_ok(lines), "DEBUG=1 should return OK"

    def test_debug_disable(self, at_cmd: ATCommandHelper):
        """AT+DEBUG=0 should disable debug and return OK."""
        lines = at_cmd.send_command("AT+DEBUG=0")
        assert at_cmd.check_ok(lines), "DEBUG=0 should return OK"

    def test_debug_out_of_range(self, at_cmd: ATCommandHelper):
        """AT+DEBUG=2 should return ERROR (range is 0~1)."""
        lines = at_cmd.send_command("AT+DEBUG=2")
        assert at_cmd.check_error(
            lines
        ), "DEBUG=2 should return ERROR (out of range B(0~1))"

    def test_debug_missing_param(self, at_cmd: ATCommandHelper):
        """AT+DEBUG= with no param should return OK (per original design spec)."""
        lines = at_cmd.send_command("AT+DEBUG=")
        assert at_cmd.check_ok(lines), "DEBUG= with missing param should return OK"

    def test_debug_test_cmd(self, at_cmd: ATCommandHelper):
        """AT+DEBUG=? should return test description and OK."""
        lines = at_cmd.send_test("DEBUG")
        assert at_cmd.check_ok(lines), "DEBUG=? should return OK"
        assert any(
            "+DEBUG:" in line for line in lines
        ), "DEBUG=? should return +DEBUG:<desc>"


class TestTest:
    """Tests for AT+TESTCMD command."""

    def _set_test_values(self, at_cmd, *params):
        """Helper: set TESTCMD state via exec and assert OK."""
        cmd = "AT+TESTCMD=" + ",".join(str(p) for p in params)
        lines = at_cmd.send_command(cmd)
        assert at_cmd.check_ok(lines), f"TESTCMD exec should return OK (cmd={cmd})"

    def test_test_query_response_format(self, at_cmd: ATCommandHelper):
        """AT+TESTCMD? response should match +TESTCMD:<byte>,<str>,<hex> format."""
        self._set_test_values(at_cmd, 1, 66, "TEST", "AABBCCDD")
        lines = at_cmd.send_query("TESTCMD")
        assert at_cmd.check_ok(lines), "TESTCMD? should return OK"
        assert any(
            _TEST_RSP_RE.search(line) for line in lines
        ), f"TESTCMD? response should match pattern {_TEST_RSP_RE.pattern}"

    def test_test_query_returns_set_values(self, at_cmd: ATCommandHelper):
        """AT+TESTCMD? should reflect values set by exec."""
        self._set_test_values(at_cmd, 1, 30, "ABCD", "11223344")
        lines = at_cmd.send_query("TESTCMD")
        assert at_cmd.check_ok(lines), "TESTCMD? should return OK"
        content = "\n".join(lines)
        assert (
            "+TESTCMD:30,ABCD,11223344" in content
        ), "Expected +TESTCMD:30,ABCD,11223344"

    def test_test_mode1_all_at_once(self, at_cmd: ATCommandHelper):
        """AT+TESTCMD=1 (mode 1) sends all params at once in one response."""
        self._set_test_values(at_cmd, 1, 10, "HI", "DEADBEEF")
        lines = at_cmd.send_query("TESTCMD")
        assert at_cmd.check_ok(lines), "TESTCMD? should return OK"
        content = "\n".join(lines)
        assert (
            "+TESTCMD:10,HI,DEADBEEF" in content
        ), "Mode 1 query should return all values in single +TESTCMD line"

    def test_test_mode2_multi_part(self, at_cmd: ATCommandHelper):
        """AT+TESTCMD=2 (mode 2) sends params in multiple calls but same output."""
        self._set_test_values(at_cmd, 2, 20, "AB", "CAFEBABE")
        lines = at_cmd.send_query("TESTCMD")
        assert at_cmd.check_ok(lines), "TESTCMD? should return OK"
        content = "\n".join(lines)
        assert (
            "+TESTCMD:20,AB,CAFEBABE" in content
        ), "Mode 2 query should return all values in single +TESTCMD line"

    def test_test_string_too_long(self, at_cmd: ATCommandHelper):
        """AT+TESTCMD with string > 4 chars should return ERROR (S(0~4))."""
        lines = at_cmd.send_command("AT+TESTCMD=1,12,ABCDE,AABBCCDD")
        assert at_cmd.check_error(
            lines
        ), "String longer than 4 chars should return ERROR"

    def test_test_array_wrong_length(self, at_cmd: ATCommandHelper):
        """AT+TESTCMD with array != 4 bytes should return ERROR (A(4~4))."""
        lines = at_cmd.send_command("AT+TESTCMD=1,12,AB,AABB")
        assert at_cmd.check_error(
            lines
        ), "Array not exactly 4 bytes should return ERROR"

    def test_test_missing_params(self, at_cmd: ATCommandHelper):
        """AT+TESTCMD= with no params should return ERROR."""
        lines = at_cmd.send_command("AT+TESTCMD=")
        assert at_cmd.check_error(
            lines
        ), "TESTCMD= with missing params should return ERROR"

    def test_test_test_cmd(self, at_cmd: ATCommandHelper):
        """AT+TESTCMD=? should return test description and OK."""
        lines = at_cmd.send_test("TESTCMD")
        assert at_cmd.check_ok(lines), "TESTCMD=? should return OK"
        assert any(
            "+TESTCMD:" in line for line in lines
        ), "TESTCMD=? should return +TESTCMD:<desc>"


if __name__ == "__main__":
    pytest.main([__file__, "-v"])
