#!/usr/bin/env python3

"""
@file pytest/test_atcmd_smp.py

@brief Two-device BLE SMP pairing tests for the AT command set sample.

Requires two boards running the AT command sample:
  - Device A (DUT)   : flashed by Twister; central role (initiator).
  - Device B (peripheral): pre-flashed; accessed via --dev-b-serial.

Test scenarios
--------------
1. Just Works pairing (L2)  : A (NIIO) connects and pairs with B (NIIO).
2. Bonded Just Works (L2)   : Same but bond=1; verifies bonded=1 in PAIREND.
3. L3 MITM failure          : A requests sec_level=3 but B is NIIO so the SMP
                              stack cannot achieve MITM — pairing fails with a
                              nonzero bt_security_err code.

Copyright (c) 2026 Atmosic

SPDX-License-Identifier: LicenseRef-Atmosic
"""

import logging
import time

import pytest

from conftest import ATCommandHelper

logger = logging.getLogger(__name__)

pytestmark = pytest.mark.two_dev_smp

# Static random BD address assigned to Device B for the duration of each test.
# Two MSBs of the first byte must be 1 (>= 0xC0) for a valid static random address.
_DEV_B_BD_ADDR = "C00102030405"

# BT identity index used on Device B (must be >= 1; 0 is BT_ID_DEFAULT and is restricted)
_DEV_B_BT_ID = 1

# Advertising instance index
_ADV_INST = 0

# Timeouts (seconds)
_SCAN_TIMEOUT = 20
_CONN_TIMEOUT = 30
_PAIR_TIMEOUT = 15

# BT_SECURITY_ERR_AUTH_REQUIREMENT value in Zephyr
_BT_SECURITY_ERR_AUTH_REQUIREMENT = 4


# ---------------------------------------------------------------------------
# Module-level helpers
# ---------------------------------------------------------------------------


def _establish_ble_conn(at_cmd: ATCommandHelper, dev_b: ATCommandHelper) -> None:
    """Set B's BD address, advertise, scan to verify, then connect from A.

    Mirrors the approach in test_atcmd_two_dev.py to avoid address-type
    ambiguity: Device B is assigned a known valid static random address on
    identity 1 so that Device A can always connect with addr_type=1 (random).
    A scan step confirms Device B is actually advertising before the connection
    attempt is made.
    """
    # Pre-condition: stop any advertising on Device B that may have been left active by a
    # previous test session.  This prevents AT+SYSBDADDR from returning EBUSY (error 0x41)
    # when identity 1 is still in use.  Ignore errors — Device B may not be advertising.
    dev_b.send_command(f"AT+BLEADVENABLE={_ADV_INST},OFF", wait_for_ok=False)
    time.sleep(0.3)

    # --- Device B: set a known static random address on identity 1 ---
    lines = dev_b.send_command(f"AT+SYSBDADDR={_DEV_B_BT_ID},{_DEV_B_BD_ADDR}")
    assert dev_b.check_ok(
        lines
    ), f"SYSBDADDR set on device B must return OK (got: {lines})"
    logger.info(
        "Device B: BD address set to %s on identity %d", _DEV_B_BD_ADDR, _DEV_B_BT_ID
    )

    # --- Device B: bind identity 1 to advertising instance 0 ---
    lines = dev_b.send_command(f"AT+BLEADVSETID={_ADV_INST},{_DEV_B_BT_ID}")
    assert dev_b.check_ok(
        lines
    ), f"BLEADVSETID on device B must return OK (got: {lines})"

    # --- Device B: start connectable advertising ---
    lines = dev_b.send_command(f"AT+BLEADVENABLE={_ADV_INST},ON")
    assert dev_b.check_ok(
        lines
    ), f"BLEADVENABLE=ON on device B must return OK (got: {lines})"
    logger.info("Device B: advertising started")
    time.sleep(0.5)

    # --- Device A: set controller MAC filter to Device B's address (before scan) ---
    lines = at_cmd.send_command(f"AT+BLESCANFILMAC=ON,1,{_DEV_B_BD_ADDR}")
    assert at_cmd.check_ok(
        lines
    ), f"BLESCANFILMAC=ON on device A must return OK (got: {lines})"
    logger.info("Device A: MAC filter set to addr_type=1 addr=%s", _DEV_B_BD_ADDR)

    # --- Device A: start scanning ---
    lines = at_cmd.send_command("AT+BLESCANENABLE=ON")
    assert at_cmd.check_ok(
        lines
    ), f"BLESCANENABLE=ON on device A must return OK (got: {lines})"
    logger.info("Device A: scanning, waiting for +EVTBLEGAPADVRPT: from device B")

    # --- Device A: wait for adv report confirming Device B is visible ---
    report_lines = at_cmd.read_until(r"\+EVTBLEGAPADVRPT:", timeout=_SCAN_TIMEOUT)
    assert any("+EVTBLEGAPADVRPT:" in line for line in report_lines), (
        f"Device A did not receive +EVTBLEGAPADVRPT: within {_SCAN_TIMEOUT}s "
        f"(MAC filter={_DEV_B_BD_ADDR})"
    )
    logger.info("Device A: adv report received: %s", " ".join(report_lines))

    # --- Device A: stop scanning ---
    lines = at_cmd.send_command("AT+BLESCANENABLE=OFF")
    assert at_cmd.check_ok(
        lines
    ), f"BLESCANENABLE=OFF on device A must return OK (got: {lines})"
    time.sleep(0.3)

    # --- Device A: initiate connection (addr_type=1 random, known static address) ---
    logger.info(
        "Device A: connecting → addr_type=1 addr=%s timeout=30s", _DEV_B_BD_ADDR
    )
    lines = at_cmd.send_command(
        f"AT+BLEGAPCREATECONN=1,{_DEV_B_BD_ADDR},{_CONN_TIMEOUT}"
    )
    assert at_cmd.check_ok(
        lines
    ), f"BLEGAPCREATECONN on device A must return OK (got: {lines})"

    # --- Device A: wait for asynchronous connection event ---
    conn_lines = at_cmd.read_until(r"\+EVTBLEGAPCONN:", timeout=_CONN_TIMEOUT)
    assert any(
        "+EVTBLEGAPCONN:" in line for line in conn_lines
    ), "Device A must receive +EVTBLEGAPCONN: event after connection"
    logger.info("Device A: +EVTBLEGAPCONN: %s", " ".join(conn_lines))


def _teardown_ble_conn(at_cmd: ATCommandHelper, dev_b: ATCommandHelper) -> None:
    """Best-effort cleanup: stop scan, disconnect A, clear MAC filter, disable B advertising."""
    # Stop scan first (may be active if setup failed before the scan step completed)
    at_cmd.send_command("AT+BLESCANENABLE=OFF", wait_for_ok=False)
    time.sleep(0.3)
    at_cmd.send_command("AT+BLEGAPDISCONNECT=0", wait_for_ok=False)
    time.sleep(1.0)
    at_cmd.send_command(f"AT+BLESCANFILMAC=OFF,1,{_DEV_B_BD_ADDR}", wait_for_ok=False)
    dev_b.send_command(f"AT+BLEADVENABLE={_ADV_INST},OFF", wait_for_ok=False)
    time.sleep(0.5)


def _parse_pairend(lines: list[str]) -> tuple[int, int, int]:
    """Parse +EVTBLESMPPAIRENDIND:<idx>,<bonded>,<err> from event lines.

    Returns:
        (idx, bonded, err) tuple, or (-1, -1, -1) if line not found.
    """
    for line in lines:
        if "+EVTBLESMPPAIRENDIND:" not in line:
            continue
        try:
            payload = line.split("+EVTBLESMPPAIRENDIND:")[-1].strip()
            parts = payload.split(",")
            return int(parts[0]), int(parts[1]), int(parts[2])
        except (IndexError, ValueError):
            pass
    return -1, -1, -1


# ---------------------------------------------------------------------------
# Test classes
# ---------------------------------------------------------------------------


class TestBLESMPTwoDevJustWorks:
    """Just Works pairing (L2, no MITM) between A (NIIO) and B (NIIO)."""

    @pytest.fixture(autouse=True, scope="class")
    def ble_conn(self, at_cmd: ATCommandHelper, dev_b_at_cmd: ATCommandHelper):
        """Establish BLE connection before each test and tear it down after."""
        try:
            _establish_ble_conn(at_cmd, dev_b_at_cmd)
            yield
        finally:
            _teardown_ble_conn(at_cmd, dev_b_at_cmd)

    def test_just_works_pairing(self, at_cmd: ATCommandHelper):
        """AT+BLESMPPAIRREQ with NIIO/L2 must succeed (err=0, bonded=0)."""
        lines = at_cmd.send_command("AT+BLESMPPAIRREQ=0,0,0,0,2")
        assert at_cmd.check_ok(lines), "BLESMPPAIRREQ should return OK"

        pair_lines = at_cmd.wait_for_event(
            r"\+EVTBLESMPPAIRENDIND:", timeout=_PAIR_TIMEOUT
        )
        idx, bonded, err = _parse_pairend(pair_lines)
        assert idx != -1, f"Device A must receive +EVTBLESMPPAIRENDIND: {pair_lines}"
        assert err == 0, f"Just Works pairing must succeed (err=0), got err={err}"
        assert bonded == 0, f"bond=0 so bonded must be 0, got bonded={bonded}"


class TestBLESMPTwoDevBonding:
    """Just Works pairing with bond=1; verifies bonded=1 in +EVTBLESMPPAIRENDIND."""

    @pytest.fixture(autouse=True, scope="class")
    def ble_conn(self, at_cmd: ATCommandHelper, dev_b_at_cmd: ATCommandHelper):
        """Establish BLE connection before each test and tear it down after."""
        try:
            _establish_ble_conn(at_cmd, dev_b_at_cmd)
            yield
        finally:
            _teardown_ble_conn(at_cmd, dev_b_at_cmd)

    def test_bonded_just_works(self, at_cmd: ATCommandHelper):
        """AT+BLESMPPAIRREQ with bond=1 must report bonded=1 and err=0."""
        lines = at_cmd.send_command("AT+BLESMPPAIRREQ=0,0,0,1,2")
        assert at_cmd.check_ok(lines), "BLESMPPAIRREQ with bond=1 should return OK"

        pair_lines = at_cmd.wait_for_event(
            r"\+EVTBLESMPPAIRENDIND:", timeout=_PAIR_TIMEOUT
        )
        idx, bonded, err = _parse_pairend(pair_lines)
        assert idx != -1, f"Device A must receive +EVTBLESMPPAIRENDIND: {pair_lines}"
        assert (
            err == 0
        ), f"Bonded Just Works pairing must succeed (err=0), got err={err}"
        assert bonded == 1, f"bond=1 so bonded must be 1, got bonded={bonded}"


class TestBLESMPTwoDevMITMFailure:
    """L3 pairing failure when B (responder) has no auth_cb registered (NIIO).

    B has no bt_conn_auth_cb installed at the global level, so the SMP stack
    treats B as NoInputNoOutput.  A requests sec_level=3 (MITM required), but
    Just Works (the only method reachable with NIIO peer) provides no MITM.
    The stack reports BT_SECURITY_ERR_AUTH_REQUIREMENT in +EVTBLESMPPAIRENDIND.
    """

    @pytest.fixture(autouse=True, scope="class")
    def ble_conn(self, at_cmd: ATCommandHelper, dev_b_at_cmd: ATCommandHelper):
        """Establish BLE connection before each test and tear it down after."""
        try:
            _establish_ble_conn(at_cmd, dev_b_at_cmd)
            yield
        finally:
            _teardown_ble_conn(at_cmd, dev_b_at_cmd)

    def test_l3_fails_niio_peer(self, at_cmd: ATCommandHelper):
        """BLESMPPAIRREQ with sec_level=3 and NIIO peer must fail (err != 0).

        Zephyr SMP may detect that MITM is impossible with NIIO capability and
        reject the request synchronously (ERR returned immediately), or it may
        accept the command and report failure asynchronously via
        +EVTBLESMPPAIRENDIND with a nonzero err code.  Both outcomes are valid.
        """
        lines = at_cmd.send_command("AT+BLESMPPAIRREQ=0,0,0,0,3")

        if at_cmd.check_ok(lines):
            # Async path: command accepted; wait for the pairing failure event.
            pair_lines = at_cmd.wait_for_event(
                r"\+EVTBLESMPPAIRENDIND:", timeout=_PAIR_TIMEOUT
            )
            idx, bonded, err = _parse_pairend(pair_lines)
            assert (
                idx != -1
            ), f"Device A must receive +EVTBLESMPPAIRENDIND: {pair_lines}"
            assert (
                err != 0
            ), f"L3 with NIIO peer must fail with nonzero err, got err={err}"
            logger.info(
                "L3 MITM failure confirmed (async): idx=%d bonded=%d err=%d "
                "(expected BT_SECURITY_ERR_AUTH_REQUIREMENT=%d)",
                idx,
                bonded,
                err,
                _BT_SECURITY_ERR_AUTH_REQUIREMENT,
            )
        else:
            # Sync path: SMP stack immediately rejected L3 (MITM impossible
            # with NIIO capability) — ERR returned directly by the command.
            logger.info(
                "L3 MITM failure confirmed (sync): BLESMPPAIRREQ returned ERR "
                "immediately (stack detected MITM impossible with NIIO capability)"
            )
