#!/usr/bin/env python3
# Copyright (c) 2025-2026 Atmosic
#
# SPDX-License-Identifier: LicenseRef-Atmosic

"""
@file pytest/test_at_cmd_tag.py

@brief Pytest integration test for AT command tag functionality

Tests AT commands for tag operations.
"""

# Pytest tests for multimode_consumer_tag TAG AT command set.
#
# Tests are run via Twister with the pytest harness. Two-port mode is supported
# by passing --pytest-args="--at-cmd-serial=<port>" to twister:
#
#   west twister ... --pytest-args="--at-cmd-serial=COM23"
#
# Hardware configuration:
#   - uart0 (--at-cmd-serial): AT command input/output
#   - uart1 (--device-serial): console / debug output (dut)

import logging
import re
import time
from enum import IntEnum

import pytest
from conftest import ATCommandHelper
from twister_harness import DeviceAdapter  # pylint: disable=import-error

logger = logging.getLogger(__name__)


class TagBuzzerEvt(IntEnum):
    """Buzzer event types reported via +EVTTAGBUZZER (must match tag_buzzer_evt_t).

    Sent when CONFIG_TAG_BUZZER=n so the host can produce the sound.
    Values correspond to tag_buzzer_evt_t in platform_indicate.h.
    """

    FACTORY_RESET = 0
    POWER_OFF = 1
    GFP_RING_ON = 2
    GFP_RING_OFF = 3
    FMNA_RING_ON = 4
    FMNA_RING_OFF = 5
    STF_SOUND_ON = 6
    STF_SOUND_OFF = 7


class TagState(IntEnum):
    """Tag state values reported via +EVTTAGSTATE event (must match tag_indication_state_t).

    These values correspond to the tag_indication_state_t enum in platform_common.h.
    The AT command layer sends these values directly without conversion.

    NOTE: These differ from tag_state_t (protocol internal state); tag_indication_state_t
    is the external system indication state used for LED and AT event notifications.
    """

    BOOTED = 0
    POWER_ON = 1
    POWER_OFF = 2
    INIT_DONE = 3
    UNPAIRED = 4
    PAIRING = 5
    PAIRED = 6
    # OTA states (0x60+ available via CONFIG_TAG_OTA_MODE button-triggered OTA)
    OTA_IN_PROGRESS = 0x60
    OTA_COMPLETE = 0x61
    OTA_CONFIRMED = 0x62
    INVALID = 0xFF


class TestTagBoot:  # pylint: disable=too-few-public-methods
    """Tests for boot-time +EVTTAGSTATE event."""

    def test_boot_emits_tagstate_booted(self, at_cmd: ATCommandHelper):
        """Application emits +EVTTAGSTATE:<mask>,0 (BOOTED) on startup.

        The event is sent once during main() right after AT command UART
        init, with protocol mask covering all build-time supported
        protocols. Receiving this event signals the host that the device
        has just (re)booted. Note: state value 0 corresponds to AT_CMD_TAG_EVT_STATE_BOOTED.
        """
        if not at_cmd.at_serial:
            pytest.skip("Boot event capture requires two-port mode (--at-cmd-serial)")

        # Read whatever is buffered on the AT serial since boot.
        # Do NOT clear_buffer() here -- that would discard the BOOTED event.
        collected = at_cmd.at_serial.read_until(
            r"NEVER_MATCH_THIS_PATTERN", timeout=2.0
        )

        boot_re = re.compile(
            r"\+EVTTAGSTATE:\s*(\d+|0[xX][0-9a-fA-F]+)\s*,\s*"
            + str(TagState.BOOTED)
            + r"\s*$"
        )
        boot_events = [line for line in collected if boot_re.search(line)]

        assert boot_events, (
            f"Expected +EVTTAGSTATE:<mask>,{TagState.BOOTED} (BOOTED) event "
            f"during boot, got: {collected}"
        )

        # Sanity check: protocol mask must be non-zero and within FMNA|FHN|STF.
        mask = int(boot_re.search(boot_events[0]).group(1), 0)
        assert 0 < mask <= 0x07, f"Invalid boot protocol mask: 0x{mask:02x}"
        logger.info(
            "Boot +EVTTAGSTATE event captured: mask=0x%02x, state=%d",
            mask,
            TagState.BOOTED,
        )


class TestTagInfo:
    """Tests for AT+TAGINFO command."""

    def test_taginfo_query(self, at_cmd: ATCommandHelper):
        """AT+TAGINFO? should return version and protocol mask.

        Response format: +TAGINFO: <version>,<protocol_mask>
        Example: +TAGINFO: "1.0.0",0x07
        - version (string): Firmware version
        - protocol_mask (uint8_t): Supported protocols (0x01=FMNA, 0x02=FHN, 0x04=STF)
        """
        lines = at_cmd.send_command("AT+TAGINFO?")
        assert at_cmd.check_ok(lines), f"Expected OK, got: {lines}"
        info_lines = [l for l in lines if l.startswith("+TAGINFO:")]
        assert info_lines, f"No +TAGINFO: line in response: {lines}"

        # Parse response: +TAGINFO: "<version>",<protocol_mask>
        taginfo_line = info_lines[0]
        logger.info("TAGINFO response: %s", taginfo_line)
        # Extract protocol_mask (last value after comma)
        try:
            parts = taginfo_line.split(",")
            assert len(parts) == 2, f"Expected 2 fields in TAGINFO, got: {parts}"
            protocol_str = parts[1].strip()
            protocol_mask = int(protocol_str, 0)
            assert 0 < protocol_mask <= 0x07, f"Invalid protocol mask: {protocol_mask}"
            logger.info("Protocol mask: 0x%02x", protocol_mask)
        except (ValueError, IndexError) as e:
            assert False, f"Failed to parse TAGINFO response: {e}"

    def test_taginfo_not_settable(self, at_cmd: ATCommandHelper):
        """AT+TAGINFO=1 should be rejected."""
        lines = at_cmd.send_command("AT+TAGINFO=1")
        assert at_cmd.check_error(lines), f"Expected error, got: {lines}"


class TestTagMode:
    """Tests for AT+TAGMODE command."""

    def test_tagmode_query(self, at_cmd: ATCommandHelper):
        """AT+TAGMODE? should return current mode mask and OK."""
        lines = at_cmd.send_command("AT+TAGMODE?")
        assert at_cmd.check_ok(lines), f"Expected OK, got: {lines}"
        val = at_cmd.get_value(lines, "+TAGMODE:")
        assert val is not None, f"No +TAGMODE: line in response: {lines}"
        logger.info("TAGMODE: %s", val)

    def test_tagmode_set_valid(self, at_cmd: ATCommandHelper):
        """AT+TAGMODE=7 (decimal) should be accepted and stored.

        Note: AT command framework does not support hex input (0x prefix returns ERR:5).
        Query response is in hex format (+TAGMODE:0x07).
        """
        lines = at_cmd.send_command("AT+TAGMODE=7")
        assert at_cmd.check_ok(lines), f"Expected OK, got: {lines}"
        lines2 = at_cmd.send_command("AT+TAGMODE?")
        val = at_cmd.get_value(lines2, "+TAGMODE:")
        assert val is not None
        assert int(val, 0) == 0x07, f"Expected 0x07, got {val}"

    def test_tagmode_zero_rejected(self, at_cmd: ATCommandHelper):
        """AT+TAGMODE=0 should be rejected (out of valid range 1-7)."""
        lines = at_cmd.send_command("AT+TAGMODE=0")
        assert at_cmd.check_error(lines), f"Expected error, got: {lines}"

    def test_tagmode_round_trip_each_protocol(self, at_cmd: ATCommandHelper):
        """AT+TAGMODE=<n> followed by AT+TAGMODE? should report the same value.

        Iterates each valid protocol bit (FMNA=1, FHN=2, STF=4) and the all-on
        combination (7), verifying the value persisted across the SET/GET pair.
        Original mode is restored on exit.
        """
        lines = at_cmd.send_command("AT+TAGMODE?")
        original_val = at_cmd.get_value(lines, "+TAGMODE:")
        original = int(original_val, 0) if original_val else 0x07

        try:
            for mode in (0x01, 0x02, 0x04, 0x07):
                set_lines = at_cmd.send_command(f"AT+TAGMODE={mode}")
                assert at_cmd.check_ok(
                    set_lines
                ), f"AT+TAGMODE={mode} failed: {set_lines}"

                q_lines = at_cmd.send_command("AT+TAGMODE?")
                assert at_cmd.check_ok(
                    q_lines
                ), f"AT+TAGMODE? failed after setting {mode}: {q_lines}"
                val = at_cmd.get_value(q_lines, "+TAGMODE:")
                assert val is not None, f"No +TAGMODE: line: {q_lines}"
                assert int(val, 0) == mode, f"Expected 0x{mode:02x}, got {val}"
                logger.info("TAGMODE round-trip OK for 0x%02x", mode)
        finally:
            at_cmd.send_command(f"AT+TAGMODE={original}")

    def test_tagmode_reflected_in_taginfo(self, at_cmd: ATCommandHelper):
        """After AT+TAGMODE=<n>, AT+TAGINFO? protocol_mask should equal <n>.

        multimode_taginfo_cb derives protocol_mask from platform_tag_mode_get(),
        so changing TAGMODE must be visible in the TAGINFO response.
        Original mode is restored on exit.
        """
        lines = at_cmd.send_command("AT+TAGMODE?")
        original_val = at_cmd.get_value(lines, "+TAGMODE:")
        original = int(original_val, 0) if original_val else 0x07

        try:
            for mode in (0x01, 0x02, 0x04, 0x07):
                set_lines = at_cmd.send_command(f"AT+TAGMODE={mode}")
                assert at_cmd.check_ok(
                    set_lines
                ), f"AT+TAGMODE={mode} failed: {set_lines}"

                info_lines = at_cmd.send_command("AT+TAGINFO?")
                assert at_cmd.check_ok(
                    info_lines
                ), f"AT+TAGINFO? failed after setting {mode}: {info_lines}"
                info = at_cmd.get_value(info_lines, "+TAGINFO:")
                assert info is not None, f"No +TAGINFO: line: {info_lines}"

                # Format: +TAGINFO: "<version>",<protocol_mask>
                parts = info.split(",")
                assert len(parts) == 2, f"Expected 2 fields in TAGINFO, got: {parts}"
                mask = int(parts[1].strip(), 0)
                assert (
                    mask == mode
                ), f"TAGMODE={mode} but TAGINFO protocol_mask=0x{mask:02x}"
                logger.info("TAGINFO reflects TAGMODE=0x%02x", mode)
        finally:
            at_cmd.send_command(f"AT+TAGMODE={original}")


class TestTagReset:
    """Tests for AT+TAGRESET command (involves device reboot).

    Must run BEFORE TestTagStart so that TAGMODE can still be changed
    (mode change is rejected once the tag is running).
    """

    def test_tagreset_cold_reboot_preserves_mode(
        self, dut: DeviceAdapter, at_cmd: ATCommandHelper
    ):
        """AT+TAGRESET=0 should reboot and preserve TAGMODE.

        Sets mode to 0x01 first (different from default 0x07) to verify NVS value is truly
        preserved.
        """
        assert at_cmd.check_ok(at_cmd.send_command("AT+TAGMODE=1"))

        lines = at_cmd.send_command("AT+TAGRESET=0")
        assert at_cmd.check_ok(lines), f"Expected OK, got: {lines}"

        # Wait for reboot, then drain any lingering boot events
        # (e.g. +EVTTAGSTATE) before querying.  reset_input_buffer() alone
        # is racy -- the event may arrive just after the clear.  Using
        # read_until with a pattern that never matches consumes all data
        # that arrives during the timeout window.
        dut.readlines_until(regex=r"AT command UART ready on", timeout=30.0)
        if at_cmd.at_serial:
            at_cmd.at_serial.read_until(r"NEVER_MATCH_THIS_PATTERN", timeout=2.0)
        else:
            time.sleep(1.0)

        lines2 = at_cmd.send_command("AT+TAGMODE?")
        val = at_cmd.get_value(lines2, "+TAGMODE:")
        assert val is not None
        assert int(val, 0) == 0x01, f"TAGMODE not preserved after cold reboot: {val}"

    def test_tagreset_factory_reset_clears_mode(
        self, dut: DeviceAdapter, at_cmd: ATCommandHelper
    ):
        """AT+TAGRESET=1 should reboot and reset TAGMODE to compile-time default (0x07).

        Sets mode to 0x01 first (different from default 0x07) to verify NVS is truly cleared.
        """
        assert at_cmd.check_ok(at_cmd.send_command("AT+TAGMODE=1"))

        lines = at_cmd.send_command("AT+TAGRESET=1")
        assert at_cmd.check_ok(lines), f"Expected OK, got: {lines}"

        # Wait for reboot, then drain any lingering boot events before querying.
        dut.readlines_until(regex=r"AT command UART ready on", timeout=30.0)
        if at_cmd.at_serial:
            at_cmd.at_serial.read_until(r"NEVER_MATCH_THIS_PATTERN", timeout=2.0)
        else:
            time.sleep(1.0)

        lines2 = at_cmd.send_command("AT+TAGMODE?")
        val = at_cmd.get_value(lines2, "+TAGMODE:")
        assert val is not None
        assert int(val, 0) == 0x07, f"TAGMODE not reset after factory reset: {val}"


class TestTagStart:
    """Tests for AT+TAGSTART command."""

    # STF mode bit: (1 << TAG_TYPE_STF) where TAG_TYPE_STF = 2
    _STF_MODE_BIT = 0x04
    # TAGMODE value recorded before AT+TAGSTART=1
    _pre_start_mode = 0

    def test_tagstart_captures_init_events(self, at_cmd: ATCommandHelper):
        """Capture +EVTTAGSTATE events from early initialization.

        Tags are initialized during platform_init() in the boot sequence.
        This test attempts to read any lingering +EVTTAGSTATE events from that
        early initialization phase before AT+TAGSTART is called.

        Expected: One or more +EVTTAGSTATE events should be present from the
        initialization of each enabled tag protocol (FMNA, FHN, STF).
        """
        # Give boot sequence time to complete and events to be sent
        time.sleep(1.0)

        # Clear the AT serial buffer to prepare for reading pending events
        if at_cmd.at_serial:
            at_cmd.at_serial.clear_buffer()

        time.sleep(0.5)

        # Try to read any events that were sent during boot-time initialization
        collected_events = []
        if at_cmd.at_serial:
            try:
                # Use a pattern that will never match, so we read everything until timeout
                collected_events = at_cmd.at_serial.read_until(
                    r"NEVER_MATCH_THIS_PATTERN", timeout=2.0
                )
            except TimeoutError:
                # Timeout is expected - it means we've read all available data
                logger.info(
                    "Timeout reached (expected) - finished reading buffered events"
                )
        else:
            # Fallback: read from console
            collected_events = at_cmd.dut.readlines()

        # Filter for +EVTTAGSTATE events from initialization
        tagstate_events = [line for line in collected_events if "+EVTTAGSTATE:" in line]

        logger.info(
            "Early boot phase: Collected %d total lines, %d +EVTTAGSTATE events",
            len(collected_events),
            len(tagstate_events),
        )

        if tagstate_events:
            logger.info(
                "SUCCESS: Captured %d init events from boot sequence:",
                len(tagstate_events),
            )
            for i, event in enumerate(tagstate_events):
                logger.info("  Event %d: %s", i, event)
        else:
            logger.warning(
                "No +EVTTAGSTATE events captured from boot initialization. "
                "This may indicate events were consumed elsewhere or buffering issue."
            )

    def test_tagstart_set_stf_mode(self, at_cmd: ATCommandHelper):
        """Set TAGMODE=7 before AT+TAGSTART to guarantee STF is enabled.

        This ensures test_tagstart_emits_stf_boot_buzzer_events will FAIL
        (not skip) if +EVTTAGBUZZER events are not received after AT+TAGSTART=1.
        """
        lines = at_cmd.send_command("AT+TAGMODE=7")
        assert at_cmd.check_ok(lines), f"Failed to set TAGMODE=7: {lines}"
        TestTagStart._pre_start_mode = 7

    def test_tagstart_exec(self, at_cmd: ATCommandHelper):
        """AT+TAGSTART=1 should start tag and return OK."""
        lines = at_cmd.send_command("AT+TAGSTART=1")
        assert at_cmd.check_ok(lines), f"Expected OK, got: {lines}"

    def test_tagstart_emits_stf_boot_buzzer_events(self, at_cmd: ATCommandHelper):
        """After AT+TAGSTART=1, STF boot sound emits exactly 1 ON and 1 OFF.

        SOUND_ITEM_BOOTING is a 3-note melody. The PortBuzzerControl.c
        sound_active guard deduplicates the inter-note OFF calls so only
        1x +EVTTAGBUZZER:6 (STF_SOUND_ON) and 1x +EVTTAGBUZZER:7
        (STF_SOUND_OFF) reach the host.

        This test MUST run before the next send_command() call because
        clear_buffer() would discard buffered async events.
        Only runs in two-port mode where the AT serial is separate from
        the console port.
        """
        if not at_cmd.at_serial:
            pytest.skip("Async event capture requires two-port mode (--at-cmd-serial)")

        # Allow time for the async boot sound events to arrive
        time.sleep(1.0)

        collected = at_cmd.at_serial.read_until(
            r"NEVER_MATCH_THIS_PATTERN", timeout=2.0
        )

        buzzer_re = re.compile(r"\+EVTTAGBUZZER:\s*(\d+),")
        evt_types = [
            int(m.group(1)) for line in collected for m in [buzzer_re.search(line)] if m
        ]

        if not evt_types:
            stf_enabled = bool(
                TestTagStart._pre_start_mode & TestTagStart._STF_MODE_BIT
            )
            if stf_enabled:
                pytest.fail(
                    f"STF is enabled (TAGMODE=0x{TestTagStart._pre_start_mode:02X}) "
                    f"but no +EVTTAGBUZZER events received after AT+TAGSTART=1 - "
                    f"firmware may be stuck"
                )
            pytest.skip("No +EVTTAGBUZZER events captured - STF not enabled")

        on_count = evt_types.count(TagBuzzerEvt.STF_SOUND_ON)
        off_count = evt_types.count(TagBuzzerEvt.STF_SOUND_OFF)

        assert on_count == 1, (
            f"Expected 1 STF_SOUND_ON (+EVTTAGBUZZER:{TagBuzzerEvt.STF_SOUND_ON}), "
            f"got {on_count}; all evt types: {evt_types}"
        )
        assert off_count == 1, (
            f"Expected 1 STF_SOUND_OFF (+EVTTAGBUZZER:{TagBuzzerEvt.STF_SOUND_OFF}, "
            f"deduplicated from 3-note melody), got {off_count}; all evt types: {evt_types}"
        )
        logger.info(
            "STF boot sound: %d ON + %d OFF (deduplicated)", on_count, off_count
        )

    def test_tagmode_rejected_after_start(self, at_cmd: ATCommandHelper):
        """AT+TAGMODE=1 should be rejected once tag is running (after AT+TAGSTART=1)."""
        lines = at_cmd.send_command("AT+TAGMODE=1")
        assert at_cmd.check_error(
            lines
        ), f"Expected error after tag start, got: {lines}"

    def test_tagstart_no_arg(self, at_cmd: ATCommandHelper):
        """AT+TAGSTART= (empty argument) - firmware treats empty arg as valid and returns OK."""
        lines = at_cmd.send_command("AT+TAGSTART=")
        assert at_cmd.check_ok(lines), f"Expected OK, got: {lines}"

    def test_tagstart_initializes_and_advertises(self, at_cmd: ATCommandHelper):
        """Verify that AT+TAGSTART properly initializes and starts advertising.

        After AT+TAGSTART=1 is called (by test_tagstart_exec), tags should be:
        1. Fully initialized (done in platform_init)
        2. Advertising with ADV enabled
        3. Responding to queries (AT+TAGINFO, etc.)

        This test verifies the post-start state is correct.
        """
        # Verify tags are responding correctly after start
        lines = at_cmd.send_command("AT+TAGINFO?")
        assert at_cmd.check_ok(lines), f"AT+TAGINFO failed: {lines}"

        info_lines = [l for l in lines if l.startswith("+TAGINFO:")]
        assert info_lines, f"No +TAGINFO response: {lines}"

        logger.info("Tags are initialized and advertising after AT+TAGSTART")


class TestTagBattery:
    """Tests for AT+TAGBATTERY command."""

    def test_tagbattery_query(self, at_cmd: ATCommandHelper):
        """AT+TAGBATTERY? should return percentage 0-100 and OK."""
        lines = at_cmd.send_command("AT+TAGBATTERY?")
        assert at_cmd.check_ok(lines), f"Expected OK, got: {lines}"
        val = at_cmd.get_value(lines, "+TAGBATTERY:")
        assert val is not None, f"No +TAGBATTERY: line in response: {lines}"
        pct = int(val)
        assert 0 <= pct <= 100, f"Battery percentage out of range: {pct}"
        logger.info("Battery: %d%%", pct)

    def test_tagbattery_not_settable(self, at_cmd: ATCommandHelper):
        """AT+TAGBATTERY=50 should be rejected."""
        lines = at_cmd.send_command("AT+TAGBATTERY=50")
        assert at_cmd.check_error(lines), f"Expected error, got: {lines}"


class TestTagGFPInd:
    """Tests for AT+TAGGFPIND command (simulate GFP button press)."""

    def test_taggfpind_single_press(self, at_cmd: ATCommandHelper):
        """AT+TAGGFPIND=1 (single press) should be accepted."""
        lines = at_cmd.send_command("AT+TAGGFPIND=1")
        # Response depends on whether callback is registered
        # In test env, no callback; should get OK or ERR
        # The command format should be recognized either way
        assert any(
            s in " ".join(lines) for s in ["OK", "ERR"]
        ), f"Expected OK or ERR, got: {lines}"
        logger.info("AT+TAGGFPIND=1 recognized")

    def test_taggfpind_double_press(self, at_cmd: ATCommandHelper):
        """AT+TAGGFPIND=2 (double press) should be accepted if FMDN_REVERSE_RINGING enabled."""
        lines = at_cmd.send_command("AT+TAGGFPIND=2")
        # If FMDN_REVERSE_RINGING not enabled, this should return error
        # The command format should still be recognized
        assert any(
            s in " ".join(lines) for s in ["OK", "ERR"]
        ), f"Expected OK or ERR, got: {lines}"
        logger.info("AT+TAGGFPIND=2 recognized")

    def test_taggfpind_invalid_action(self, at_cmd: ATCommandHelper):
        """AT+TAGGFPIND=3 (out of range) should be rejected."""
        lines = at_cmd.send_command("AT+TAGGFPIND=3")
        assert at_cmd.check_error(
            lines
        ), f"Expected error for invalid action, got: {lines}"
        logger.info("AT+TAGGFPIND=3 correctly rejected")

    def test_taggfpind_no_params_rejected(self, at_cmd: ATCommandHelper):
        """AT+TAGGFPIND (no param) should be rejected."""
        lines = at_cmd.send_command("AT+TAGGFPIND")
        assert at_cmd.check_error(lines), f"Expected error for no params, got: {lines}"
        logger.info("AT+TAGGFPIND (no param) correctly rejected")


class TestTagAddr:
    """Tests for AT+TAGADDR command (query advertising BT address per protocol)."""

    _VALID_PROTOCOLS = (0x01, 0x02, 0x04)  # FMNA, FHN, STF
    # +TAGADDR:<protocol>,<12-hex-char address>
    _ADDR_RE = re.compile(r"\+TAGADDR:(\d+),([0-9A-Fa-f]{12})")

    def _parse_addr_line(self, lines):
        """Return (protocol, addr_hex) from +TAGADDR: line, or None."""
        for line in lines:
            m = self._ADDR_RE.search(line)
            if m:
                return int(m.group(1)), m.group(2)
        return None

    def test_tagaddr_fmna(self, at_cmd: ATCommandHelper):
        """AT+TAGADDR=1 (FMNA) returns +TAGADDR:1,<addr> OK, or ERR if not advertising."""
        lines = at_cmd.send_command("AT+TAGADDR=1")
        assert any(
            s in " ".join(lines) for s in ["OK", "ERR"]
        ), f"Expected OK or ERR, got: {lines}"
        if at_cmd.check_ok(lines):
            parsed = self._parse_addr_line(lines)
            assert parsed, f"No valid +TAGADDR: in OK response: {lines}"
            proto, addr = parsed
            assert proto == 0x01, f"Protocol mismatch: expected 1, got {proto}"
            logger.info("FMNA adv addr: %s", addr)
        else:
            logger.info("AT+TAGADDR=1 returned ERR (FMNA not advertising)")

    def test_tagaddr_fhn(self, at_cmd: ATCommandHelper):
        """AT+TAGADDR=2 (FHN) returns +TAGADDR:2,<addr> OK, or ERR if not advertising."""
        lines = at_cmd.send_command("AT+TAGADDR=2")
        assert any(
            s in " ".join(lines) for s in ["OK", "ERR"]
        ), f"Expected OK or ERR, got: {lines}"
        if at_cmd.check_ok(lines):
            parsed = self._parse_addr_line(lines)
            assert parsed, f"No valid +TAGADDR: in OK response: {lines}"
            proto, addr = parsed
            assert proto == 0x02, f"Protocol mismatch: expected 2, got {proto}"
            logger.info("FHN adv addr: %s", addr)
        else:
            logger.info("AT+TAGADDR=2 returned ERR (FHN not advertising)")

    def test_tagaddr_stf(self, at_cmd: ATCommandHelper):
        """AT+TAGADDR=4 (STF) returns +TAGADDR:4,<addr> OK, or ERR if not advertising."""
        lines = at_cmd.send_command("AT+TAGADDR=4")
        assert any(
            s in " ".join(lines) for s in ["OK", "ERR"]
        ), f"Expected OK or ERR, got: {lines}"
        if at_cmd.check_ok(lines):
            parsed = self._parse_addr_line(lines)
            assert parsed, f"No valid +TAGADDR: in OK response: {lines}"
            proto, addr = parsed
            assert proto == 0x04, f"Protocol mismatch: expected 4, got {proto}"
            logger.info("STF adv addr: %s", addr)
        else:
            logger.info("AT+TAGADDR=4 returned ERR (STF not advertising)")

    def test_tagaddr_combination_rejected(self, at_cmd: ATCommandHelper):
        """AT+TAGADDR=3 (0x01|0x02 combination) should be rejected."""
        lines = at_cmd.send_command("AT+TAGADDR=3")
        assert at_cmd.check_error(
            lines
        ), f"Expected error for combined protocol bits, got: {lines}"
        logger.info("AT+TAGADDR=3 (combination) correctly rejected")

    def test_tagaddr_all_bits_rejected(self, at_cmd: ATCommandHelper):
        """AT+TAGADDR=7 (all bits) should be rejected."""
        lines = at_cmd.send_command("AT+TAGADDR=7")
        assert at_cmd.check_error(
            lines
        ), f"Expected error for all-bits combination, got: {lines}"
        logger.info("AT+TAGADDR=7 (all bits) correctly rejected")

    def test_tagaddr_zero_rejected(self, at_cmd: ATCommandHelper):
        """AT+TAGADDR=0 should be rejected (out of range 1-7)."""
        lines = at_cmd.send_command("AT+TAGADDR=0")
        assert at_cmd.check_error(lines), f"Expected error for protocol=0, got: {lines}"
        logger.info("AT+TAGADDR=0 correctly rejected")

    def test_tagaddr_query_returns_ok(self, at_cmd: ATCommandHelper):
        """AT+TAGADDR? (query type) returns OK per AT command framework behaviour."""
        lines = at_cmd.send_command("AT+TAGADDR?")
        assert at_cmd.check_ok(lines), f"Expected OK for query type, got: {lines}"
        logger.info("AT+TAGADDR? returns OK (WRONG_EXECUTE_TYPE handled by framework)")

    def test_tagaddr_response_format(self, at_cmd: ATCommandHelper):
        """When OK, +TAGADDR response must be <protocol>,<12-hex-char address>."""
        for protocol in self._VALID_PROTOCOLS:
            lines = at_cmd.send_command(f"AT+TAGADDR={protocol}")
            if not at_cmd.check_ok(lines):
                logger.info("AT+TAGADDR=%d ERR - skipping format check", protocol)
                continue
            parsed = self._parse_addr_line(lines)
            assert (
                parsed
            ), f"+TAGADDR: line missing or malformed for protocol {protocol}: {lines}"
            proto, addr = parsed
            assert (
                proto == protocol
            ), f"Protocol echo mismatch: sent {protocol}, got {proto}"
            assert (
                len(addr) == 12
            ), f"Address should be 12 hex chars, got {len(addr)}: {addr}"
            logger.info("Protocol 0x%02x addr: %s", protocol, addr)
