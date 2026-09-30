#!/usr/bin/env python3
# Copyright (c) 2026 Atmosic
#
# SPDX-License-Identifier: LicenseRef-Atmosic

"""Two-device sensor_beacon AT command test.

DevA (central, at_cmd_set sample) — Twister DUT:
  Scans for DevB, connects, relays AT commands via GATT write/notify.

DevB (sensor_beacon, pre-flashed) — console via --dev-b-serial:
  Receives AT commands through GATT write (at_gatt.c).
  Sends AT responses through GATT notify back to DevA.

Run:
  west twister -p <BOARD> -T atmosic-internal/samples/subsys/at_cmd_set \\
    -s samples.subsys.at_cmd_set.atm.two_dev.central.sensor_beacon \\
    --device-testing --device-serial COM3 \\
    --pytest-args="--at-cmd-serial=COM4 --dev-b-serial=COM6"
"""

import logging
import re
import threading
import time

import pytest

from conftest import ATCommandHelper, ATCommandSerial

# pytest fixtures intentionally shadow module-level fixture names (W0621)
# pylint: disable=redefined-outer-name

pytestmark = pytest.mark.sensor_beacon

logger = logging.getLogger(__name__)

# ── GATT UUIDs (sensor_beacon/src/at_gatt.c) ─────────────────────────────────
# Service:  "AtmosicSB-beacon" via BT_UUID_DECLARE_REVERSE_128 → big-endian hex
# Char:     "AtmosicX\x00..\x01" via BT_UUID_DECLARE_128      → big-endian hex
SENSOR_BEACON_SVC_UUID = "41746D6F73696353422D626561636F6E"
SENSOR_BEACON_AT_CHAR_UUID = "0100000000000000006369736F6D7441"

# ── Constants ─────────────────────────────────────────────────────────────────
UNLOCK_KEY = "atm1atm123"
SENSOR_BEACON_NAME = "Atmosic Sensor Beacon"
SCAN_TIMEOUT = 20.0
CONNECT_WAIT = 35.0
EVT_TIMEOUT = 10.0
NOTIF_TIMEOUT = 10.0
REBOOT_TIMEOUT = 15.0


# ── Helpers ───────────────────────────────────────────────────────────────────


def _adv_data_name(hex_data: str) -> str | None:
    """Parse BLE adv TLVs; return Complete/Shortened Local Name or None."""
    try:
        data = bytes.fromhex(hex_data)
    except ValueError:
        return None
    i = 0
    while i < len(data) - 1:
        length = data[i]
        if length == 0 or i + length >= len(data):
            break
        ad_type, value = data[i + 1], data[i + 2 : i + 1 + length]
        if ad_type in (0x08, 0x09):
            return value.decode("utf-8", errors="replace")
        i += 1 + length
    return None


def _decode_ntf(lines: list[str]) -> str:
    """Concatenate raw bytes of all +BLEGATTNOTI notifications and decode once.

    The AT command framework may split a single response across multiple GATT
    notifications (e.g. "+SYSLOCK:" in one packet, "OFF\\r\\n" in the next,
    "\\r\\nOK\\r\\n" in another).  Joining raw bytes before decoding ensures
    patterns like "+SYSLOCK:OFF" and "OK" are always found intact.
    """
    raw = bytearray()
    for line in lines:
        m = re.search(r"\+BLEGATTNOTI:\d+,\d+,([0-9A-Fa-f]+)", line)
        if m:
            raw += bytes.fromhex(m.group(1))
    return raw.decode("utf-8", errors="replace").strip() if raw else ""


class SensorBeaconGattClient:
    """Relay AT commands to sensor_beacon DevB via DevA GATT write/notify."""

    def __init__(
        self, at_cmd: ATCommandHelper, conn_idx: int, char_handle: int, ccc_handle: int
    ):
        self.at_cmd = at_cmd
        self.conn_idx = conn_idx
        self.char_handle = char_handle
        self.ccc_handle = ccc_handle
        self.buffered_events = []  # Store events encountered during send()

    def send(self, command: str, timeout: float = NOTIF_TIMEOUT) -> str:
        """GATT-write AT command to DevB; return decoded notification response.

        AT responses may be split across multiple GATT notifications.
        Keep collecting notifications until raw bytes contain OK or ERR,
        or until timeout expires.
        """
        hex_cmd = command.encode().hex()
        # Send BLEGATTWR command directly (bypass send_command to avoid OK/ERR wait)
        gatt_cmd = f"AT+BLEGATTWR={self.conn_idx},{self.char_handle},{hex_cmd}\r\n"
        self.at_cmd.at_serial.clear_buffer()
        self.at_cmd.at_serial.write(gatt_cmd.encode())
        time.sleep(0.1)  # Brief delay for response

        # Wait for +BLEGATTWR response and collect any BLEGATTNOTI that came with it
        blegattwr_lines = self.at_cmd.read_until(r"\+BLEGATTWR:", timeout=2.0)

        # Now read the actual AT response via BLEGATTNOTI notifications
        raw = bytearray()
        deadline = time.time() + timeout
        no_notif_count = 0  # Track consecutive reads with no notifications

        # Process any BLEGATTNOTI in the BLEGATTWR response first
        # Also buffer any events (like +EVTBLEGAPDISCONN) for later checking
        for line in blegattwr_lines:
            if "+EVTBLEGAPDISCONN:" in line or "+EVTBLEGAPCONN:" in line:
                self.buffered_events.append(line)
            m = re.search(r"\+BLEGATTNOTI:\d+,\d+,([0-9A-Fa-f]+)", line)
            if m:
                raw += bytes.fromhex(m.group(1))

        while time.time() < deadline:
            remaining = max(0.5, deadline - time.time())
            # Use longer timeout per read to accommodate DevB processing delay
            # For query commands, OK notification may be delayed, so use longer timeout
            lines = self.at_cmd.read_until(
                r"\+BLEGATTNOTI:", timeout=min(5.0, remaining)
            )

            # Always check for events in the lines, even if no BLEGATTNOTI found
            for line in lines:
                if "+EVTBLEGAPDISCONN:" in line or "+EVTBLEGAPCONN:" in line:
                    self.buffered_events.append(line)

            if not any("+BLEGATTNOTI:" in l for l in lines):
                no_notif_count += 1
                # For query commands, OK may arrive late after the query response
                # Wait longer before giving up (increased from 2 to 4 attempts)
                if no_notif_count >= 4:
                    break
                continue
            no_notif_count = 0  # Reset counter when notification found
            for line in lines:
                m = re.search(r"\+BLEGATTNOTI:\d+,\d+,([0-9A-Fa-f]+)", line)
                if m:
                    raw += bytes.fromhex(m.group(1))
            decoded = raw.decode("utf-8", errors="replace")
            if "OK" in decoded or "ERR" in decoded:
                break
        return raw.decode("utf-8", errors="replace").strip()

    def check_event(self, event_pattern: str) -> bool:
        r"""Check if an event was buffered during send() operations.

        Args:
            event_pattern: Regex pattern to search for (e.g. r"\+EVTBLEGAPDISCONN:")

        Returns:
            True if event found in buffer, False otherwise
        """
        for event in self.buffered_events:
            if re.search(event_pattern, event):
                return True
        return False

    def clear_events(self):
        """Clear buffered events."""
        self.buffered_events.clear()

    @staticmethod
    def ok(rsp: str) -> bool:
        """Check if response contains OK."""
        return "OK" in rsp

    @staticmethod
    def error(rsp: str) -> bool:
        """Check if response contains ERROR."""
        return "ERR" in rsp


# ── Fixtures ──────────────────────────────────────────────────────────────────


class DevBConsoleLogger:
    """Background thread logger for DevB console output."""

    def __init__(self, serial_conn, logger_obj):
        self.serial_conn = serial_conn
        self.logger = logger_obj
        self.stop_flag = False
        self.thread = None

    def start(self):
        """Start background logging thread."""
        self.stop_flag = False
        self.thread = threading.Thread(target=self._log_loop, daemon=True)
        self.thread.start()

    def _log_loop(self):
        """Background loop reading and logging serial output."""
        while not self.stop_flag:
            try:
                lines = self.serial_conn.read_lines(timeout=0.5)
                for line in lines:
                    if line:
                        self.logger.info("DevB: %s", line)
            except (OSError, UnicodeDecodeError) as e:
                if not self.stop_flag:
                    self.logger.debug("DevB read error: %s", e)

    def stop(self):
        """Stop background logging thread."""
        self.stop_flag = True
        if self.thread:
            self.thread.join(timeout=2.0)


@pytest.fixture(scope="session")
def dev_b_console(dev_b_serial_port, dev_b_baud):
    """Raw serial to DevB for console log monitoring with background logging."""
    if not dev_b_serial_port:
        pytest.skip("--dev-b-serial not specified; skipping sensor_beacon two-dev test")
    conn = ATCommandSerial(dev_b_serial_port, dev_b_baud)
    conn.open()

    # Start background logging
    dev_b_logger = DevBConsoleLogger(conn, logger)
    dev_b_logger.start()

    yield conn

    # Stop logging and close connection
    dev_b_logger.stop()
    conn.close()


@pytest.fixture(scope="class")
def sensor_beacon_client(at_cmd: ATCommandHelper, dev_b_console):
    # pylint: disable=too-many-locals
    """Scan→connect→discover→notify-enable; yield SensorBeaconGattClient.

    dev_b_console is a dependency to ensure background logging is active during tests.
    Complex setup requires multiple local variables for discovery state tracking.
    """
    _ = dev_b_console  # Use fixture dependency for background logging
    advrpt_re = re.compile(
        r"\+EVTBLEGAPADVRPT:(\d+),(\d+),([0-9A-Fa-f]{12}),(-?\d+),(\d+),([0-9A-Fa-f]*)"
    )
    dev_b_addr = dev_b_addr_type = None

    try:
        # Scan for DevB by device name in adv data
        assert at_cmd.check_ok(at_cmd.send_command("AT+BLESCANENABLE=ON"))
        deadline = time.time() + SCAN_TIMEOUT
        while time.time() < deadline and not dev_b_addr:
            for line in at_cmd.read_until(r"\+EVTBLEGAPADVRPT:", timeout=2.0):
                m = advrpt_re.search(line)
                if (
                    m
                    and _adv_data_name(m.group(6))
                    and _adv_data_name(m.group(6)).startswith(SENSOR_BEACON_NAME)
                    and "AAFE" not in m.group(6).upper()
                ):
                    # skip non-connectable adv_set (has Eddystone AAFE)
                    dev_b_addr_type, dev_b_addr = m.group(2), m.group(3)
                    logger.info(
                        "Found sensor_beacon: %s (type=%s)", dev_b_addr, dev_b_addr_type
                    )
                    break
        assert dev_b_addr, f"sensor_beacon not found within {SCAN_TIMEOUT}s"

        # Stop scan immediately after finding device
        # (same pattern as test_atcmd_gatt_two_dev.py)
        at_cmd.send_command("AT+BLESCANENABLE=OFF")
        time.sleep(0.3)

        # Connect — +EVTBLEGAPCONN: may already be in send_command response lines
        lines = at_cmd.send_command(
            f"AT+BLEGAPCREATECONN={dev_b_addr_type},{dev_b_addr},30"
        )
        assert at_cmd.check_ok(lines), f"BLEGAPCREATECONN failed: {lines}"

        if any("+EVTBLEGAPCONN:" in l for l in lines):
            conn_lines = lines
        else:
            conn_lines = at_cmd.read_until(r"\+EVTBLEGAPCONN:", timeout=CONNECT_WAIT)

        assert any(
            "+EVTBLEGAPCONN:" in l for l in conn_lines
        ), f"+EVTBLEGAPCONN: not received (lines={conn_lines})"
        logger.info("Connection established: %s", conn_lines)

        # GATT discovery — firmware returns OK immediately, async events follow.
        # Use read_until to wait for each specific event (reliable regardless of timing).
        disc_drain_timeout = 2.0

        def disc_cmd(cmd, event_re):
            """Send discovery command and collect response lines."""
            lines = at_cmd.send_command(cmd)
            assert at_cmd.check_ok(lines), f"{cmd} failed: {lines}"
            if not any(re.search(event_re, l) for l in lines):
                lines += at_cmd.read_until(event_re, timeout=EVT_TIMEOUT)
            # Drain remaining async events to clear disc_busy
            if at_cmd.at_serial:
                lines += at_cmd.at_serial.read_lines(timeout=disc_drain_timeout)
            return lines

        # Discover AT GATT service by UUID
        svc_lines = disc_cmd(
            f"AT+BLEGATTDISCSVC=0,{SENSOR_BEACON_SVC_UUID}", r"\+BLEGATTDISCSVC:"
        )
        svc_m = next(
            (
                re.search(r"\+BLEGATTDISCSVC:(\d+),(\d+),(\d+)", l)
                for l in svc_lines
                if re.search(r"\+BLEGATTDISCSVC:", l)
            ),
            None,
        )
        assert svc_m, f"Service not found: {svc_lines}"
        svc_end = int(svc_m.group(3))  # group(3) = end_handle

        # Discover TXRX characteristic by UUID
        char_lines = disc_cmd(
            f"AT+BLEGATTDISCCHAR=0,{SENSOR_BEACON_AT_CHAR_UUID}", r"\+BLEGATTDISCCHAR:"
        )
        char_m = next(
            (
                re.search(r"\+BLEGATTDISCCHAR:(\d+),(\d+),(\d+)", l)
                for l in char_lines
                if re.search(r"\+BLEGATTDISCCHAR:", l)
            ),
            None,
        )
        assert char_m, f"Characteristic not found: {char_lines}"
        char_handle = int(char_m.group(3))  # group(3) = val_handle

        # Discover CCC descriptor
        desc_lines = disc_cmd(
            f"AT+BLEGATTDISCDESCS=0,{char_handle + 1},{svc_end},0",
            r"\+BLEGATTDISCDESCS:",
        )
        desc_m = next(
            (
                re.search(r"\+BLEGATTDISCDESCS:(\d+),(\d+),", l)
                for l in desc_lines
                if re.search(r"\+BLEGATTDISCDESCS:", l)
            ),
            None,
        )
        assert desc_m, f"CCC descriptor not found: {desc_lines}"
        ccc_handle = int(desc_m.group(2))  # group(2) = handle

        # Enable notifications
        lines = at_cmd.send_command(f"AT+BLEGATTWRCCCD=0,{char_handle},{ccc_handle},1")
        assert at_cmd.check_ok(lines), f"BLEGATTWRCCCD enable failed: {lines}"
        logger.info("sensor_beacon GATT ready: char=%d ccc=%d", char_handle, ccc_handle)

        yield SensorBeaconGattClient(at_cmd, 0, char_handle, ccc_handle)

    finally:
        at_cmd.send_command("AT+BLEGAPDISCONNECT=0", wait_for_ok=False)
        time.sleep(0.5)
        at_cmd.send_command("AT+BLESCANENABLE=OFF", wait_for_ok=False)


# ── Test class ────────────────────────────────────────────────────────────────


class TestSensorBeaconAtCmd:
    """Exercise all AT commands supported by sensor_beacon via BLE GATT.

    Sequence within class matters: unlock comes before commands that need it.
    A single GATT connection is shared across all tests (class-scoped fixture).
    """

    def test_syslock_initially_locked(self, sensor_beacon_client):
        """AT+SYSLOCK? must report ON (locked) on a fresh connection."""
        rsp = sensor_beacon_client.send("AT+SYSLOCK?")
        assert "+SYSLOCK:ON" in rsp, f"Expected +SYSLOCK:ON (got: {rsp!r})"

    def test_command_blocked_when_locked(self, sensor_beacon_client):
        """AT+BLEGAPDEVNAME? must return ERROR while channel is locked."""
        rsp = sensor_beacon_client.send("AT+BLEGAPDEVNAME?")
        assert sensor_beacon_client.error(
            rsp
        ), f"Expected ERROR while locked (got: {rsp!r})"

    def test_sysunlock_wrong_key(self, sensor_beacon_client):
        """AT+SYSUNLOCK with wrong key must return ERROR."""
        rsp = sensor_beacon_client.send("AT+SYSUNLOCK=wrongkey")
        assert sensor_beacon_client.error(
            rsp
        ), f"Expected ERROR for wrong key (got: {rsp!r})"

    def test_sysunlock_correct_key(self, sensor_beacon_client):
        """AT+SYSUNLOCK with correct key must return OK and unlock the channel."""
        rsp = sensor_beacon_client.send(f"AT+SYSUNLOCK={UNLOCK_KEY}")
        assert sensor_beacon_client.ok(
            rsp
        ), f"Expected OK for correct key (got: {rsp!r})"

    def test_syslock_query_after_unlock(self, sensor_beacon_client):
        """AT+SYSLOCK? must report OFF (unlocked) after AT+SYSUNLOCK succeeds."""
        rsp = sensor_beacon_client.send("AT+SYSLOCK?")
        assert "+SYSLOCK:OFF" in rsp, f"Expected +SYSLOCK:OFF (got: {rsp!r})"

    def test_devname_query(self, sensor_beacon_client):
        """AT+BLEGAPDEVNAME? returns current device name with OK."""
        rsp = sensor_beacon_client.send("AT+BLEGAPDEVNAME?")
        assert (
            sensor_beacon_client.ok(rsp) and "+BLEGAPDEVNAME:" in rsp
        ), f"Expected +BLEGAPDEVNAME: response (got: {rsp!r})"

    def test_devname_set_and_verify(self, sensor_beacon_client):
        """AT+BLEGAPDEVNAME=<name> updates name; query confirms change."""
        new_name = "sb_test"
        rsp = sensor_beacon_client.send(f"AT+BLEGAPDEVNAME={new_name}")
        assert sensor_beacon_client.ok(rsp), f"Expected OK for name set (got: {rsp!r})"
        rsp = sensor_beacon_client.send("AT+BLEGAPDEVNAME?")
        assert new_name in rsp, f"Expected '{new_name}' in query (got: {rsp!r})"

    def test_devname_restore(self, sensor_beacon_client):
        """Restore original device name after test_devname_set_and_verify."""
        rsp = sensor_beacon_client.send(f"AT+BLEGAPDEVNAME={SENSOR_BEACON_NAME}")
        assert sensor_beacon_client.ok(
            rsp
        ), f"Expected OK restoring name (got: {rsp!r})"

    def test_bleadvlegacyparm_invalid(self, sensor_beacon_client):
        """AT+BLEADVLEGACYPARM with out-of-range interval must return ERROR."""
        rsp = sensor_beacon_client.send("AT+BLEADVLEGACYPARM=0,10,10,0")
        assert sensor_beacon_client.error(
            rsp
        ), f"Expected ERROR for invalid interval 10 (got: {rsp!r})"

    def test_bleadvdata_not_supported(self, sensor_beacon_client):
        """AT+BLEADVDATA is not supported by sensor_beacon; must return ERROR."""
        rsp = sensor_beacon_client.send("AT+BLEADVDATA=0,DEADBEEF")
        assert sensor_beacon_client.error(
            rsp
        ), f"Expected ERROR for unsupported BLEADVDATA (got: {rsp!r})"

    def test_sysreset(self, at_cmd: ATCommandHelper, sensor_beacon_client):
        """AT+SYSRESET=1 reboots DevB; DevA sees disconnect event."""
        # Clear any previous buffered events
        sensor_beacon_client.clear_events()

        # Send reset command
        # The disconnect event may arrive during send() and will be buffered
        sensor_beacon_client.send("AT+SYSRESET=1", timeout=3.0)

        # Check if disconnect event was buffered during send()
        if sensor_beacon_client.check_event(r"\+EVTBLEGAPDISCONN:"):
            logger.info("Disconnect event was buffered during send()")
        else:
            # If not buffered, wait for it on the serial port
            disc_lines = at_cmd.read_until(
                r"\+EVTBLEGAPDISCONN:", timeout=REBOOT_TIMEOUT
            )
            assert any(
                "+EVTBLEGAPDISCONN:" in l for l in disc_lines
            ), f"+EVTBLEGAPDISCONN: not received after SYSRESET (got: {disc_lines})"

        # Note: We don't verify DevB reboot here because:
        # 1. The serial port temporarily disconnects during reboot, causing SerialException
        # 2. We've already verified the disconnect event, which confirms SYSRESET worked
        # 3. DevB reboot verification is not essential for this AT command test
