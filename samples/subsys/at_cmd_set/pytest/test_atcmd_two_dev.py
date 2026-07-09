#!/usr/bin/env python3
# Copyright (c) 2026 Atmosic
#
# SPDX-License-Identifier: LicenseRef-Atmosic

"""Two-device AT command test: devB (peripheral) sets BD address and advertises,
devA (central, twister DUT) scans for devB's address then connects.

Hardware setup:
  devA (central)    -- connected via twister --device-serial (dut / at_cmd fixture)
  devB (peripheral) -- pre-flashed with CONFIG_AT_CMD_PERIPHERAL=y, CONFIG_AT_CMD_CENTRAL=n
                       connected via --dev-b-serial CLI option (dev_b_at_cmd fixture)

Run example:
  # Pre-flash devB as peripheral first:
  #   west build -p always -b <BOARD> atmosic-internal/samples/bluetooth/at_cmd \\
  #     -- -DCONFIG_AT_CMD_PERIPHERAL=y -DCONFIG_AT_CMD_CENTRAL=n
  #   west flash --device=<devB_id> --jlink

  west twister -p <BOARD> -T atmosic-internal/samples/bluetooth/at_cmd \\
    -s samples.bluetooth.at_cmd.atm.pytest.two_dev \\
    --device-testing --device-serial COM3 \\
    --west-flash="--device=<devA_id>,--jlink,--erase_all" \\
    --pytest-args="--at-cmd-serial=COM4 --dev-b-serial=COM6"

"""

import logging
import re
import time

import pytest
from conftest import ATCommandHelper

pytestmark = pytest.mark.two_dev

logger = logging.getLogger(__name__)

# Static random BD address devB (peripheral) will use.
# Two MSBs of the first byte must be 1 (>= 0xC0) for a valid static random address.
DEV_B_BD_ADDR = "C00102030405"

# BT identity index for devB (must be >= 1; 0 is BT_ID_DEFAULT and is restricted)
DEV_B_BT_ID = 1

# Advertising instance index
ADV_INST = 0

# Seconds to wait for devA's adv report to appear on devB
SCAN_TIMEOUT = 20.0

# Seconds to wait after initiating connection before checking state
CONNECT_WAIT = 8.0

# Seconds to wait for an event after a triggering BLE action
EVT_TIMEOUT = 10.0


class TestTwoDevBdAddrAdvConnect:  # pylint: disable=too-few-public-methods
    """Two-device test: devB (peripheral, pre-flashed) sets a known BD address and
    starts connectable advertising; devA (central, twister DUT) scans to locate
    devB's address, initiates a BLE connection, and verifies the connection and

    disconnection events (+EVTBLEGAPCONN, +EVTBLEGAPDISCONN)."""

    def test_dev_b_adv_dev_a_scan_connect(
        self, at_cmd: ATCommandHelper, dev_b_at_cmd: ATCommandHelper
    ):
        """devB sets BD address, advertises; devA scans, connects, verifies events.

        AT command flow
        ---------------
        devB: AT+SYSBDADDR=1,C0:01:02:03:04:05  -- set BD addr on identity 1
        devB: AT+BLEADVSETID=0,1                 -- bind identity 1 to adv inst 0
        devB: AT+BLEADVENABLE=0,ON               -- start connectable advertising
        devA: AT+BLESCANFILMAC=ON,1,<addr>       -- set controller accept-list filter
        devA: AT+BLESCANENABLE=ON                -- start scanning (only devB passes filter)
        devA: (wait for +EVTBLEGAPADVRPT:)       -- first report is guaranteed from devB
        devA: AT+BLESCANENABLE=OFF               -- stop scanning
        devA: AT+BLEGAPCREATECONN=1,<addr>,30   -- initiate connection (30 s timeout)
        devA: (wait for +EVTBLEGAPCONN:)         -- connection established event
        devA: AT+BLEGAPDISCONNECT=0              -- graceful disconnect
        devA: (wait for +EVTBLEGAPDISCONN:)      -- disconnection event

        AT+BLESCANFILMAC programs the controller Filter Accept List so only
        devB's advertisements reach the host.  The filter must be set before
        AT+BLESCANENABLE=ON and cleared afterwards.

        """
        conn_addr = DEV_B_BD_ADDR

        try:
            # --- devB: set BD address on identity 1 ---
            lines = dev_b_at_cmd.send_command(
                f"AT+SYSBDADDR={DEV_B_BT_ID},{DEV_B_BD_ADDR}"
            )
            assert dev_b_at_cmd.check_ok(
                lines
            ), f"SYSBDADDR set should return OK (got: {lines})"
            logger.info(
                "devB: BD address set to %s on identity %d", DEV_B_BD_ADDR, DEV_B_BT_ID
            )

            # --- devB: assign identity 1 to adv instance 0 ---
            lines = dev_b_at_cmd.send_command(
                f"AT+BLEADVSETID={ADV_INST},{DEV_B_BT_ID}"
            )
            assert dev_b_at_cmd.check_ok(
                lines
            ), f"BLEADVSETID set should return OK (got: {lines})"

            # --- devB: start connectable advertising ---
            lines = dev_b_at_cmd.send_command(f"AT+BLEADVENABLE={ADV_INST},ON")
            assert dev_b_at_cmd.check_ok(
                lines
            ), f"BLEADVENABLE=ON should return OK (got: {lines})"
            logger.info("devB: advertising started")
            time.sleep(0.5)

            # --- devA: set controller MAC filter to devB's address (before scan) ---
            # addr_type=1 (static random); addr in MSB-first hex without colons.
            lines = at_cmd.send_command(f"AT+BLESCANFILMAC=ON,1,{conn_addr}")
            assert at_cmd.check_ok(
                lines
            ), f"BLESCANFILMAC=ON should return OK (got: {lines})"
            logger.info("devA: MAC filter set to addr_type=1 addr=%s", conn_addr)

            # --- devA: start scanning — controller accept-list ensures only devB arrives ---
            lines = at_cmd.send_command("AT+BLESCANENABLE=ON")
            assert at_cmd.check_ok(
                lines
            ), f"BLESCANENABLE=ON should return OK (got: {lines})"
            logger.info(
                "devA: scanning started, waiting for +EVTBLEGAPADVRPT: from devB"
            )

            # --- devA: wait for adv report — filter guarantees it is from devB ---
            # +EVTBLEGAPADVRPT:<evt_type>,<addr_type>,<addr_hex>,<rssi>,<dlen>,<data>
            report_lines = at_cmd.read_until(
                r"\+EVTBLEGAPADVRPT:", timeout=SCAN_TIMEOUT
            )
            assert any("+EVTBLEGAPADVRPT:" in line for line in report_lines), (
                f"devA did not receive +EVTBLEGAPADVRPT: within {SCAN_TIMEOUT}s "
                f"(MAC filter={conn_addr})"
            )
            logger.info("devA: adv report received: %s", " ".join(report_lines))

            # --- devA: stop scanning ---
            lines = at_cmd.send_command("AT+BLESCANENABLE=OFF")
            assert at_cmd.check_ok(
                lines
            ), f"BLESCANENABLE=OFF should return OK (got: {lines})"
            time.sleep(0.3)

            # --- devA: initiate connection to devB (addr_type=1 random, 30 s timeout) ---
            logger.info("devA: connecting → addr_type=1 addr=%s timeout=30s", conn_addr)
            lines = at_cmd.send_command(f"AT+BLEGAPCREATECONN=1,{conn_addr},30")
            assert at_cmd.check_ok(
                lines
            ), f"BLEGAPCREATECONN should return OK (got: {lines})"

            # --- devA: wait for +EVTBLEGAPCONN: (connection established event) ---
            logger.info("devA: waiting for +EVTBLEGAPCONN:")
            conn_evt_lines = at_cmd.read_until(
                r"\+EVTBLEGAPCONN:", timeout=CONNECT_WAIT
            )
            assert any("+EVTBLEGAPCONN:" in line for line in conn_evt_lines), (
                f"+EVTBLEGAPCONN: event must be emitted after link establishment "
                f"(got: {conn_evt_lines})"
            )
            logger.info("devA +EVTBLEGAPCONN: %s", " ".join(conn_evt_lines))

            # --- devA: disconnect connection slot 0 ---
            logger.info("devA: disconnecting connection slot 0")
            lines = at_cmd.send_command("AT+BLEGAPDISCONNECT=0")
            assert at_cmd.check_ok(
                lines
            ), f"BLEGAPDISCONNECT=0 should return OK (got: {lines})"

            # --- devA: wait for +EVTBLEGAPDISCONN: (disconnection event) ---
            logger.info("devA: waiting for +EVTBLEGAPDISCONN:")
            disconn_evt_lines = at_cmd.read_until(
                r"\+EVTBLEGAPDISCONN:", timeout=EVT_TIMEOUT
            )
            assert any("+EVTBLEGAPDISCONN:" in line for line in disconn_evt_lines), (
                f"+EVTBLEGAPDISCONN: event must be emitted after disconnect "
                f"(got: {disconn_evt_lines})"
            )
            logger.info("devA +EVTBLEGAPDISCONN: %s", " ".join(disconn_evt_lines))

        finally:
            # Cleanup devA: disconnect any active connection, cancel any pending attempt,
            # disable reports/scan
            at_cmd.send_command("AT+BLEGAPDISCONNECT=0", wait_for_ok=False)
            time.sleep(0.3)
            at_cmd.send_command("AT+BLEGAPCANCELCREATECONN=", wait_for_ok=False)
            time.sleep(0.5)
            at_cmd.send_command("AT+BLESCANENABLE=OFF", wait_for_ok=False)
            time.sleep(0.3)
            # Cleanup devB: stop advertising
            dev_b_at_cmd.send_command(
                f"AT+BLEADVENABLE={ADV_INST},OFF", wait_for_ok=False
            )
            time.sleep(0.3)


# ─────────────────────────────────────────────────────────────────────────────
# Shared helpers used by the two-device test classes below
# ─────────────────────────────────────────────────────────────────────────────


def _dev_b_start_advertising(dev_b_at_cmd: ATCommandHelper) -> None:
    """Set devB BD address on identity 1 and start connectable advertising."""
    lines = dev_b_at_cmd.send_command(f"AT+SYSBDADDR={DEV_B_BT_ID},{DEV_B_BD_ADDR}")
    assert dev_b_at_cmd.check_ok(lines), f"SYSBDADDR failed (got: {lines})"

    lines = dev_b_at_cmd.send_command(f"AT+BLEADVSETID={ADV_INST},{DEV_B_BT_ID}")
    assert dev_b_at_cmd.check_ok(lines), f"BLEADVSETID failed (got: {lines})"

    lines = dev_b_at_cmd.send_command(f"AT+BLEADVENABLE={ADV_INST},ON")
    assert dev_b_at_cmd.check_ok(lines), f"BLEADVENABLE=ON failed (got: {lines})"
    time.sleep(0.5)


def _dev_a_scan_and_connect(
    at_cmd: ATCommandHelper, conn_addr: str, timeout_sec: int = 30
) -> list[str]:
    """Set MAC filter, scan for devB, clear filter, then connect.

    Uses AT+BLESCANFILMAC to program the controller accept-list so only
    devB's advertisements are forwarded as +EVTBLEGAPADVRPT: events.

    Returns the lines captured while waiting for +EVTBLEGAPCONN: so the
    caller can assert the event was received and inspect the event payload.

    """
    # --- Set controller MAC filter before starting scan ---
    # addr_type=1 (static random); addr in MSB-first hex, no colons.
    lines = at_cmd.send_command(f"AT+BLESCANFILMAC=ON,1,{conn_addr}")
    assert at_cmd.check_ok(lines), f"BLESCANFILMAC=ON failed (got: {lines})"
    logger.info("devA: MAC filter set to addr_type=1 addr=%s", conn_addr)

    # --- Start scanning — controller accept-list ensures only devB arrives ---
    lines = at_cmd.send_command("AT+BLESCANENABLE=ON")
    assert at_cmd.check_ok(lines), f"BLESCANENABLE=ON failed (got: {lines})"
    logger.info("devA: scanning started, waiting for +EVTBLEGAPADVRPT: from devB")

    # --- Wait for adv report — filter guarantees it is from devB ---
    report_lines = at_cmd.read_until(r"\+EVTBLEGAPADVRPT:", timeout=SCAN_TIMEOUT)
    assert any("+EVTBLEGAPADVRPT:" in line for line in report_lines), (
        f"devA did not receive +EVTBLEGAPADVRPT: within {SCAN_TIMEOUT}s "
        f"(MAC filter={conn_addr})"
    )
    logger.info("devA: adv report received: %s", " ".join(report_lines))

    # --- Stop scanning ---
    lines = at_cmd.send_command("AT+BLESCANENABLE=OFF")
    assert at_cmd.check_ok(lines), f"BLESCANENABLE=OFF failed (got: {lines})"
    time.sleep(0.3)

    logger.info(
        "devA: connecting → addr_type=1 addr=%s timeout=%ds", conn_addr, timeout_sec
    )
    lines = at_cmd.send_command(f"AT+BLEGAPCREATECONN=1,{conn_addr},{timeout_sec}")
    assert at_cmd.check_ok(lines), f"BLEGAPCREATECONN failed (got: {lines})"
    logger.info("devA: connection attempt accepted; waiting for +EVTBLEGAPCONN:")

    # +EVTBLEGAPCONN: may arrive in the serial buffer before the OK response if the
    # BLE link establishes very quickly.  In that case send_command's internal
    # read_until(OK) already consumed it — detect and re-use those lines so the
    # event is not silently dropped before the caller's read_until can see it.
    if any("+EVTBLEGAPCONN:" in line for line in lines):
        logger.info(
            "devA: +EVTBLEGAPCONN: already in send_command response, skipping extra read"
        )
        return lines

    conn_evt_lines = at_cmd.read_until(r"\+EVTBLEGAPCONN:", timeout=CONNECT_WAIT)
    return conn_evt_lines


def _cleanup_dev_a(at_cmd: ATCommandHelper) -> None:
    """Best-effort cleanup of devA: disconnect, cancel pending, clear filter, stop scan."""
    at_cmd.send_command("AT+BLEGAPDISCONNECT=0", wait_for_ok=False)
    time.sleep(0.3)
    at_cmd.send_command("AT+BLEGAPCANCELCREATECONN=", wait_for_ok=False)
    time.sleep(0.5)
    at_cmd.send_command("AT+BLESCANENABLE=OFF", wait_for_ok=False)
    time.sleep(0.3)


def _cleanup_dev_b(dev_b_at_cmd: ATCommandHelper) -> None:
    """Best-effort cleanup of devB: stop advertising."""
    dev_b_at_cmd.send_command(f"AT+BLEADVENABLE={ADV_INST},OFF", wait_for_ok=False)
    time.sleep(0.3)


class TestTwoDevConnectionQueries:  # pylint: disable=too-few-public-methods
    """Two-device test: verify connection events and connection-dependent AT commands.

    devB (peripheral, pre-flashed) advertises with a known BD address.
    devA (central, twister DUT) connects and exercises:

    Events (emitted asynchronously from BT callbacks):
      - +EVTBLEGAPCONN:<idx>,<addr_type>,<addr>        connection established
      - +EVTBLEGAPLINKINFO:<idx>,<features>             remote LE feature exchange
      - +EVTBLEGAPPAR:<idx>,<interval>,<latency>,<to>  connection parameter update
      - +EVTBLEGAPDISCONN:<idx>,<reason>               connection terminated

    Commands (queried once the link is established):
      - AT+BLEGAPGETCONNSTAT=0              role, peer addr, interval, latency, timeout
      - AT+BLEGAPGETPEERINFO=0              peer identity addr type, addr, sec level, key size
      - AT+BLEGAPGETRSSI=0                  RSSI in dBm (signed byte)
      - AT+BLECONNTXPWR?                    get current TX power for all active connections
      - AT+BLECONNTXPWR=0,0                 set connection TX power to 0 dBm
      - AT+BLEGAPPARNEGO=0,24,40,0,400      request connection parameter update
      - AT+BLEGAPDISCONNECT=0               graceful disconnection

    """

    @pytest.fixture(scope="class")
    def connection_events(self, at_cmd: ATCommandHelper, dev_b_at_cmd: ATCommandHelper):
        """Establish a full connection lifecycle and collect all connection events.

        Runs once per class: devB advertises, devA scans and connects, all
        connection-scoped commands are exercised, the link is torn down, and
        the captured event lines are yielded in a dict keyed by short event
        name so individual test methods can verify each event independently.

        """
        events = {
            "conn": [],
            "linkinfo": [],
            "par": [],
            "parnego": [],
            "disconn": [],
        }

        try:
            _dev_b_start_advertising(dev_b_at_cmd)
            events["conn"] = _dev_a_scan_and_connect(at_cmd, DEV_B_BD_ADDR)
            logger.info("devA +EVTBLEGAPCONN: %s", " ".join(events["conn"]))

            # +EVTBLEGAPLINKINFO: fires after mandatory LE feature exchange
            events["linkinfo"] = at_cmd.read_until(
                r"\+EVTBLEGAPLINKINFO:", timeout=EVT_TIMEOUT
            )
            logger.info("devA +EVTBLEGAPLINKINFO: %s", " ".join(events["linkinfo"]))

            # +EVTBLEGAPPAR: optional — fires only if a conn param update occurs
            events["par"] = at_cmd.read_until(r"\+EVTBLEGAPPAR:", timeout=EVT_TIMEOUT)
            if any("+EVTBLEGAPPAR:" in line for line in events["par"]):
                logger.info("devA +EVTBLEGAPPAR: %s", " ".join(events["par"]))
            else:
                logger.info(
                    "devA: +EVTBLEGAPPAR not received within %ss (optional)",
                    EVT_TIMEOUT,
                )

            # Exercise connection-scoped commands while the link is active
            for cmd, rsp_prefix, desc in (
                ("AT+BLEGAPGETCONNSTAT=0", "+BLEGAPGETCONNSTAT:", "role/addr/params"),
                (
                    "AT+BLEGAPGETPEERINFO=0",
                    "+BLEGAPGETPEERINFO:",
                    "peer identity/security",
                ),
                ("AT+BLEGAPGETRSSI=0", "+BLEGAPGETRSSI:", "RSSI"),
                ("AT+BLECONNTXPWR?", "+BLECONNTXPWR:", "TX power query"),
                ("AT+BLECONNTXPWR=0,0", None, "TX power set"),
                ("AT+BLEGAPPARNEGO=0,24,40,0,400", None, "param negotiation"),
            ):
                lines = at_cmd.send_command(cmd)
                assert at_cmd.check_ok(
                    lines
                ), f"{cmd} must return OK on active conn (got: {lines})"
                if rsp_prefix:
                    assert any(
                        rsp_prefix in line for line in lines
                    ), f"{cmd} response prefix '{rsp_prefix}' missing (got: {lines})"
                logger.info("devA %s (%s): %s", cmd, desc, " ".join(lines))

            # --- devA: wait for +EVTBLEGAPPAR: triggered by AT+BLEGAPPARNEGO ---
            # The peer accepts the parameter update and the stack emits the event.
            logger.info("devA: waiting for +EVTBLEGAPPAR: triggered by BLEGAPPARNEGO")
            events["parnego"] = at_cmd.read_until(
                r"\+EVTBLEGAPPAR:", timeout=EVT_TIMEOUT
            )
            if any("+EVTBLEGAPPAR:" in line for line in events["parnego"]):
                logger.info(
                    "devA +EVTBLEGAPPAR (parnego): %s", " ".join(events["parnego"])
                )
            else:
                logger.warning(
                    "devA: +EVTBLEGAPPAR not received within %ss after BLEGAPPARNEGO",
                    EVT_TIMEOUT,
                )

            # Initiate graceful disconnect
            lines = at_cmd.send_command("AT+BLEGAPDISCONNECT=0")
            assert at_cmd.check_ok(
                lines
            ), f"BLEGAPDISCONNECT=0 must return OK (got: {lines})"
            logger.info("devA: disconnect issued; waiting for +EVTBLEGAPDISCONN:")

            # +EVTBLEGAPDISCONN: fires from the BT disconnected callback
            events["disconn"] = at_cmd.read_until(
                r"\+EVTBLEGAPDISCONN:", timeout=EVT_TIMEOUT
            )
            logger.info("devA +EVTBLEGAPDISCONN: %s", " ".join(events["disconn"]))

        finally:
            _cleanup_dev_a(at_cmd)
            _cleanup_dev_b(dev_b_at_cmd)

        yield events

    def test_evtblegapconn(self, connection_events: dict):
        """Verify +EVTBLEGAPCONN: event is emitted when the link is established.

        +EVTBLEGAPCONN:<idx>,<addr_type>,<addr>

        """
        lines = connection_events["conn"]
        assert any("+EVTBLEGAPCONN:" in line for line in lines), (
            f"+EVTBLEGAPCONN: event must be emitted after link establishment "
            f"(got: {lines})"
        )

    def test_evtblegaplinkinfo(self, connection_events: dict):
        """Verify +EVTBLEGAPLINKINFO: event fires after the LE feature exchange.

        +EVTBLEGAPLINKINFO:<idx>,<features(8B)>
        Fires when the mandatory remote LE feature exchange procedure completes.

        """
        lines = connection_events["linkinfo"]
        assert any("+EVTBLEGAPLINKINFO:" in line for line in lines), (
            f"+EVTBLEGAPLINKINFO: event must fire after LE feature exchange "
            f"(got: {lines})"
        )

    def test_evtblegappar(self, connection_events: dict):
        """Verify +EVTBLEGAPPAR: event format when a connection parameter update occurs.

        +EVTBLEGAPPAR:<idx>,<interval>,<latency>,<supervision_timeout>
        This event is optional: it fires only when the peripheral or central triggers
        an LL connection parameter update procedure.  The test is skipped when the
        event was not observed during the connection lifecycle.

        """
        lines = connection_events["par"]
        if not any("+EVTBLEGAPPAR:" in line for line in lines):
            pytest.skip(
                "+EVTBLEGAPPAR: not received (optional — no conn param update occurred)"
            )
        assert any(
            "+EVTBLEGAPPAR:" in line for line in lines
        ), f"+EVTBLEGAPPAR: event expected in captured lines (got: {lines})"

    def test_evtblegapdisconn(self, connection_events: dict):
        """Verify +EVTBLEGAPDISCONN: event is emitted when the link is torn down.

        +EVTBLEGAPDISCONN:<idx>,<reason>
        Fires from the BT disconnected callback after the link is fully torn down.

        """
        lines = connection_events["disconn"]
        assert any("+EVTBLEGAPDISCONN:" in line for line in lines), (
            f"+EVTBLEGAPDISCONN: event must be emitted after disconnect "
            f"(got: {lines})"
        )

    def test_blegapparnego(self, connection_events: dict):
        """Verify AT+BLEGAPPARNEGO triggers +EVTBLEGAPPAR: when a connection is active.

        AT+BLEGAPPARNEGO=0,24,40,0,400 requests interval 30–50 ms (24×1.25/40×1.25 ms),
        no slave latency, 4 s supervision timeout on connection slot 0.
        The peer accepts the update and the stack emits:
          +EVTBLEGAPPAR:<idx>,<interval>,<latency>,<supervision_timeout>

        """
        lines = connection_events["parnego"]
        assert any("+EVTBLEGAPPAR:" in line for line in lines), (
            f"+EVTBLEGAPPAR: must be emitted after AT+BLEGAPPARNEGO=0,24,40,0,400 "
            f"(got: {lines})"
        )


# ─────────────────────────────────────────────────────────────────────────────
# MTU constants and helpers
# ─────────────────────────────────────────────────────────────────────────────

# Default ATT MTU before any exchange (BT Core Spec, Vol. 3 Part F §3.2.8)
BT_ATT_DEFAULT_LE_MTU = 23

_MTU_RSP_RE = re.compile(r"\+BLEGATTMTUGET:(\d+)")
_MTUEXCHANGE_EVT_RE = re.compile(r"\+EVTBLEGATTMTUEXCHANGE:(\d+),(\d+)")
_MTUEXCHGREQ_EVT_RE = re.compile(r"\+EVTBLEGATTMTUEXCHGREQ:(\d+),(\d+)")


def _parse_mtu(lines):
    """Return the MTU integer from a +BLEGATTMTUGET:<mtu> line, or None."""
    for line in lines:
        m = _MTU_RSP_RE.search(line)
        if m:
            return int(m.group(1))
    return None


class TestTwoDevMtu:
    """Two-device MTU test class.

    devB (peripheral) advertises with a known BD address.
    devA (central, twister DUT) connects and exercises MTU commands:

    Commands:
      - AT+BLEGATTMTUGET=0       : query current UATT MTU (default 23 before exchange)
      - AT+BLEGATTMTUEXCHGREQ=0  : initiate ATT MTU exchange with peer; returns OK
      - AT+BLEGATTMTUEXCHGREQ=0  : second attempt; must fail with EALREADY

    Events:
      - +EVTBLEGATTMTUEXCHANGE:<idx>,<mtu>  : new MTU active (fires on att_mtu_updated)
      - +EVTBLEGATTMTUEXCHGREQ:<idx>,<err>  : exchange result (0 = success)

    """

    @pytest.fixture(scope="class")
    def mtu_events(self, at_cmd: ATCommandHelper, dev_b_at_cmd: ATCommandHelper):
        """Establish a connection, exercise MTU commands and collect all results.

        Runs once per class (scope="class"). Yields a dict keyed by event/result
        name so individual test methods can assert each outcome independently.

        """
        events = {
            "conn": [],
            "mtu_initial": [],
            "mtuexchgreq_ok": [],
            "evtmtuexchange": [],
            "evtmtuexchgreq": [],
            "mtu_after": [],
            "mtuexchgreq_dup": [],
        }

        try:
            _dev_b_start_advertising(dev_b_at_cmd)
            events["conn"] = _dev_a_scan_and_connect(at_cmd, DEV_B_BD_ADDR)
            assert any(
                "+EVTBLEGAPCONN:" in l for l in events["conn"]
            ), f"Connection must be established before MTU tests (got: {events['conn']})"
            logger.info("devA +EVTBLEGAPCONN: %s", " ".join(events["conn"]))

            # --- Query default MTU before exchange (must be 23) ---
            events["mtu_initial"] = at_cmd.send_command("AT+BLEGATTMTUGET=0")
            logger.info(
                "devA BLEGATTMTUGET initial: %s", " ".join(events["mtu_initial"])
            )

            # --- Initiate MTU exchange ---
            events["mtuexchgreq_ok"] = at_cmd.send_command("AT+BLEGATTMTUEXCHGREQ=0")
            logger.info(
                "devA BLEGATTMTUEXCHGREQ: %s", " ".join(events["mtuexchgreq_ok"])
            )

            # +EVTBLEGATTMTUEXCHANGE fires first (att_mtu_updated precedes exchange_cb)
            events["evtmtuexchange"] = at_cmd.read_until(
                r"\+EVTBLEGATTMTUEXCHANGE:", timeout=EVT_TIMEOUT
            )
            logger.info(
                "devA +EVTBLEGATTMTUEXCHANGE: %s", " ".join(events["evtmtuexchange"])
            )

            # +EVTBLEGATTMTUEXCHGREQ fires second (from mtu_exchange_cb)
            events["evtmtuexchgreq"] = at_cmd.read_until(
                r"\+EVTBLEGATTMTUEXCHGREQ:", timeout=EVT_TIMEOUT
            )
            logger.info(
                "devA +EVTBLEGATTMTUEXCHGREQ: %s", " ".join(events["evtmtuexchgreq"])
            )

            # --- Query MTU again — must reflect negotiated value ---
            events["mtu_after"] = at_cmd.send_command("AT+BLEGATTMTUGET=0")
            logger.info("devA BLEGATTMTUGET after: %s", " ".join(events["mtu_after"]))

            # --- Second exchange request must fail (one-shot per connection) ---
            events["mtuexchgreq_dup"] = at_cmd.send_command("AT+BLEGATTMTUEXCHGREQ=0")
            logger.info(
                "devA BLEGATTMTUEXCHGREQ dup: %s", " ".join(events["mtuexchgreq_dup"])
            )

            # --- Clean disconnect ---
            lines = at_cmd.send_command("AT+BLEGAPDISCONNECT=0")
            assert at_cmd.check_ok(
                lines
            ), f"BLEGAPDISCONNECT=0 must return OK (got: {lines})"
            at_cmd.read_until(r"\+EVTBLEGAPDISCONN:", timeout=EVT_TIMEOUT)

        finally:
            _cleanup_dev_a(at_cmd)
            _cleanup_dev_b(dev_b_at_cmd)

        yield events

    def test_connection_established(self, mtu_events: dict):
        """Verify the BLE connection was established before MTU commands are exercised."""
        lines = mtu_events["conn"]
        assert any(
            "+EVTBLEGAPCONN:" in l for l in lines
        ), f"+EVTBLEGAPCONN: must be received before MTU tests (got: {lines})"

    def test_mtuset_initial_default(self, mtu_events: dict):
        """AT+BLEGATTMTUGET=0 before exchange must return 23 (BT default ATT MTU).

        +BLEGATTMTUGET:<mtu>  OK

        """
        lines = mtu_events["mtu_initial"]
        assert any(
            "OK" in l for l in lines
        ), f"BLEGATTMTUGET=0 must return OK (got: {lines})"
        mtu = _parse_mtu(lines)
        assert mtu is not None, f"+BLEGATTMTUGET: prefix missing (got: {lines})"
        assert (
            mtu == BT_ATT_DEFAULT_LE_MTU
        ), f"Initial MTU must be {BT_ATT_DEFAULT_LE_MTU} before any exchange (got: {mtu})"

    def test_mtuexchgreq_returns_ok(self, mtu_events: dict):
        """AT+BLEGATTMTUEXCHGREQ=0 must return OK (request sent, async result pending)."""
        lines = mtu_events["mtuexchgreq_ok"]
        assert any(
            "OK" in l for l in lines
        ), f"BLEGATTMTUEXCHGREQ=0 must return OK on active connection (got: {lines})"

    def test_evtblegattmtuexchange(self, mtu_events: dict):
        """+EVTBLEGATTMTUEXCHANGE:<idx>,<mtu> fires when ATT MTU is updated.

        idx must be 0 (connection slot) and mtu must be > 23 (negotiation succeeded).

        """
        lines = mtu_events["evtmtuexchange"]
        matched = next(
            (
                _MTUEXCHANGE_EVT_RE.search(l)
                for l in lines
                if _MTUEXCHANGE_EVT_RE.search(l)
            ),
            None,
        )
        assert (
            matched is not None
        ), f"+EVTBLEGATTMTUEXCHANGE: must be emitted after MTU exchange (got: {lines})"
        idx, mtu = int(matched.group(1)), int(matched.group(2))
        assert idx == 0, f"+EVTBLEGATTMTUEXCHANGE conn_idx must be 0 (got: {idx})"
        assert (
            mtu > BT_ATT_DEFAULT_LE_MTU
        ), f"+EVTBLEGATTMTUEXCHANGE mtu must be > {BT_ATT_DEFAULT_LE_MTU} (got: {mtu})"

    def test_evtblegattmtuexchgreq_success(self, mtu_events: dict):
        """+EVTBLEGATTMTUEXCHGREQ:<idx>,<err> fires with err=0 on successful exchange.

        Always emitted from mtu_exchange_cb regardless of outcome; err=0 = success.

        """
        lines = mtu_events["evtmtuexchgreq"]
        matched = next(
            (
                _MTUEXCHGREQ_EVT_RE.search(l)
                for l in lines
                if _MTUEXCHGREQ_EVT_RE.search(l)
            ),
            None,
        )
        assert (
            matched is not None
        ), f"+EVTBLEGATTMTUEXCHGREQ: must be emitted after exchange (got: {lines})"
        idx, err = int(matched.group(1)), int(matched.group(2))
        assert idx == 0, f"+EVTBLEGATTMTUEXCHGREQ conn_idx must be 0 (got: {idx})"
        assert (
            err == 0
        ), f"+EVTBLEGATTMTUEXCHGREQ err must be 0 (success) after exchange (got: {err})"

    def test_mtuset_after_exchange(self, mtu_events: dict):
        """AT+BLEGATTMTUGET=0 after exchange must report the negotiated MTU (> 23)."""
        lines = mtu_events["mtu_after"]
        assert any(
            "OK" in l for l in lines
        ), f"BLEGATTMTUGET=0 after exchange must return OK (got: {lines})"
        mtu = _parse_mtu(lines)
        assert (
            mtu is not None
        ), f"+BLEGATTMTUGET: prefix missing after exchange (got: {lines})"
        assert (
            mtu > BT_ATT_DEFAULT_LE_MTU
        ), f"MTU after exchange must be > {BT_ATT_DEFAULT_LE_MTU} (got: {mtu})"

    def test_mtuexchgreq_dup_fails(self, mtu_events: dict):
        """Second AT+BLEGATTMTUEXCHGREQ=0 must fail (one-shot per BLE connection).

        BLE spec: MTU exchange is performed at most once per connection.
        Handler returns AT_ERR_BLE_EALREADY for repeated attempts.

        """
        lines = mtu_events["mtuexchgreq_dup"]
        assert any(
            "ERR" in l for l in lines
        ), f"Second BLEGATTMTUEXCHGREQ=0 must return ERR (EALREADY) (got: {lines})"
