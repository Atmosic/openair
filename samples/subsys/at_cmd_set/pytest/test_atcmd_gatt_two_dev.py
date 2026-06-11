#!/usr/bin/env python3
# Copyright (c) 2026 Atmosic
#
# SPDX-License-Identifier: LicenseRef-Atmosic

"""
@file pytest/test_atcmd_gatt_two_dev.py

@brief Two-device GATT client/server integration tests via AT commands.

devA (central, twister DUT)   : CONFIG_AT_CMD_CENTRAL=y
devB (peripheral, pre-flashed): CONFIG_AT_CMD_PERIPHERAL=y,
                                CONFIG_AT_CMD_GATT_DFT_SERVER=y

Run example:
  west twister -p <BOARD> -T openair/samples/subsys/at_cmd_set \\
    -s samples.subsys.at_cmd_set.atm.two_dev.gatt \\
    --device-testing --device-serial <devA-console-port> \\
    --west-flash="--device=<devA_id>,--jlink,--erase_all" \\
    --pytest-args="--at-cmd-serial=<devA-at-port> --dev-b-serial=<devB-at-port>"
  # devB must be pre-flashed with samples.subsys.at_cmd_set.atm.pytest.gatt firmware

"""

import logging
import re
import time

import pytest
from conftest import ATCommandHelper

pytestmark = pytest.mark.gatt_two_dev

logger = logging.getLogger(__name__)

# ── DFT server defaults (must match firmware at_cmd_gatt.c) ──────────────────
DFT_SVC_UUID = "123E4567E89B12D3A456426614174000"
DFT_CH1_UUID = "223E4567E89B12D3A456426614174000"
DFT_CH2_UUID = "323E4567E89B12D3A456426614174000"
DFT_SVC_PROP = "0000"
DFT_CH1_PROP = "0202"  # WRITE + NOTIFY
DFT_CH2_PROP = "0602"  # WRITE + NOTIFY + INDICATE

NOTIFY_DATA = "AABBCCDD"
INDICATE_DATA = "11223344"
WRITE_DATA = "01020304"

# devB static random BD address (MSBs >= 0xC0 → addr_type=1)
DEV_B_BD_ADDR = "C00102030405"
DEV_B_BT_ID = 1
ADV_INST = 0
CONN_IDX = 0

# ── Dynamic GATT service constants (devB builds these at runtime) ─────────────
# 128-bit UUIDs (32 hex chars, MSB-first) – chosen to avoid conflicts with DFT
DYN_SVC_UUID = "EEBB1234AABB12D3A456426614174900"
DYN_CH1_UUID = "EEBB1234AABB12D3A456426614174901"  # READ+WRITE
DYN_CH2_UUID = "EEBB1234AABB12D3A456426614174902"  # READ+WRITE+NOTIFY
DYN_CH3_UUID = "EEBB1234AABB12D3A456426614174903"  # READ+WRITE+INDICATE
DYN_MAX_SIZE = 20  # max characteristic value size (decimal, W-format)

# sec_prop hex strings (MSB-first 2-byte AT A-format):
#   READ=0x0001, WRITE=0x0002, NOTIFY=0x0200, INDICATE=0x0400
_DYN_SVC_PROP = "0001"  # service declaration is read-only per BLE spec
_DYN_CH1_PROP = "0003"  # READ | WRITE
_DYN_CH2_PROP = "0203"  # READ | WRITE | NOTIFY
_DYN_CH3_PROP = "0403"  # READ | WRITE | INDICATE

DYN_WRITE_DATA = "DEADBEEF"
DYN_NOTIFY_DATA = "CAFEBABE"
DYN_INDI_DATA = "12345678"
DYN_REBOOT_WAIT = 3.0  # seconds for devB to become ready after SYSRESET

# ── Timing ────────────────────────────────────────────────────────────────────
SCAN_TIMEOUT = 20.0
CONNECT_WAIT = 10.0
EVT_TIMEOUT = 12.0
DISC_IDLE_TIMEOUT = 2.0  # seconds to drain async +BLEGATTDISC* events after OK

# ── Regex patterns ────────────────────────────────────────────────────────────
_DISC_SVCS_RE = re.compile(
    r"\+BLEGATTDISCSVCS:([0-9A-Fa-f]+),([0-9A-Fa-f]+),([0-9A-Fa-f]+),([0-9A-Fa-f]+)",
    re.I,
)
_DISC_SVC_RE = re.compile(
    r"\+BLEGATTDISCSVC:([0-9A-Fa-f]+),([0-9A-Fa-f]+),([0-9A-Fa-f]+),([0-9A-Fa-f]+)",
    re.I,
)
_DISC_CHARS_RE = re.compile(
    r"\+BLEGATTDISCCHARS:"
    r"([0-9A-Fa-f]+),([0-9A-Fa-f]+),([0-9A-Fa-f]+),([0-9A-Fa-f]+),([0-9A-Fa-f]+)",
    re.I,
)
_DISC_CHAR_RE = re.compile(
    r"\+BLEGATTDISCCHAR:([0-9A-Fa-f]+),([0-9A-Fa-f]+),([0-9A-Fa-f]+),([0-9A-Fa-f]+),([0-9A-Fa-f]+)",
    re.I,
)
_DISC_DESCS_RE = re.compile(
    r"\+BLEGATTDISCDESCS:([0-9A-Fa-f]+),([0-9A-Fa-f]+),([0-9A-Fa-f]+)", re.I
)


# ── Discovery helper ──────────────────────────────────────────────────────────
def _send_disc_cmd(at_cmd: ATCommandHelper, cmd: str) -> list[str]:
    """Send a GATT discovery command and collect async response events.

    bt_gatt_discover() is non-blocking: firmware returns OK immediately, then
    the +BLEGATTDISC* events arrive asynchronously via BT stack callbacks.
    We drain the serial buffer for up to DISC_IDLE_TIMEOUT seconds so all
    events are captured and disc_busy is cleared before the next command.

    """
    lines = at_cmd.send_command(cmd)
    if at_cmd.check_ok(lines):
        if at_cmd.at_serial:
            # Two-port mode: read_lines blocks per-line up to DISC_IDLE_TIMEOUT
            extra = at_cmd.at_serial.read_lines(timeout=DISC_IDLE_TIMEOUT)
        else:
            # Single-port mode: sleep to let events flush through
            time.sleep(DISC_IDLE_TIMEOUT)
            extra = []
        lines += extra
    return lines


# ── Parse helpers ─────────────────────────────────────────────────────────────
def _parse_disc_svcs(lines: list[str]) -> list[dict]:
    return [
        {
            "conn": int(m.group(1), 10),
            "start": int(m.group(2), 10),
            "end": int(m.group(3), 10),
            "uuid": m.group(4).upper(),
        }
        for l in lines
        for m in [_DISC_SVCS_RE.search(l)]
        if m
    ]


def _parse_disc_svc(lines: list[str]) -> list[dict]:
    return [
        {
            "conn": int(m.group(1), 10),
            "start": int(m.group(2), 10),
            "end": int(m.group(3), 10),
            "uuid": m.group(4).upper(),
        }
        for l in lines
        for m in [_DISC_SVC_RE.search(l)]
        if m
    ]


def _parse_disc_chars(lines: list[str]) -> list[dict]:
    results = []
    for l in lines:
        for rx in (_DISC_CHARS_RE, _DISC_CHAR_RE):
            m = rx.search(l)
            if m:
                results.append(
                    {
                        "conn": int(m.group(1), 10),
                        "decl": int(m.group(2), 10),
                        "val": int(m.group(3), 10),
                        "props": m.group(4).upper(),
                        "uuid": m.group(5).upper(),
                    }
                )
                break
    return results


def _parse_disc_descs(lines: list[str]) -> list[dict]:
    return [
        {
            "conn": int(m.group(1), 10),
            "handle": int(m.group(2), 10),
            "uuid": m.group(3).upper(),
        }
        for l in lines
        for m in [_DISC_DESCS_RE.search(l)]
        if m
    ]


# ── devB setup/cleanup helpers ────────────────────────────────────────────────
def _devb_start_gatt(dev_b: ATCommandHelper) -> None:
    """Configure devB DFT GATT server, set known BD address, start advertising."""
    # Reset and configure GATT server
    dev_b.send_command("BLEGATTDFTSERVER=OFF")
    dev_b.send_command(f"BLEGATTDFTSERVICE={DFT_SVC_PROP},{DFT_SVC_UUID}")
    dev_b.send_command(f"BLEGATTDFTCHAR1={DFT_CH1_PROP},{DFT_CH1_UUID}")
    dev_b.send_command(f"BLEGATTDFTCHAR2={DFT_CH2_PROP},{DFT_CH2_UUID}")
    dev_b.send_command("BLEGATTDFTSERVER=ON")
    # Set known BD address on identity 1 and bind to adv instance 0
    lines = dev_b.send_command(f"SYSBDADDR={DEV_B_BT_ID},{DEV_B_BD_ADDR}")
    assert dev_b.check_ok(lines), f"devB SYSBDADDR failed (got: {lines})"
    lines = dev_b.send_command(f"BLEADVSETID={ADV_INST},{DEV_B_BT_ID}")
    assert dev_b.check_ok(lines), f"devB BLEADVSETID failed (got: {lines})"
    lines = dev_b.send_command(f"BLEADVENABLE={ADV_INST},ON")
    assert dev_b.check_ok(lines), f"devB BLEADVENABLE=ON failed (got: {lines})"
    time.sleep(0.5)


def _devb_stop(dev_b: ATCommandHelper) -> None:
    """Stop devB advertising and disable GATT server."""
    dev_b.send_command(f"BLEADVENABLE={ADV_INST},OFF", wait_for_ok=False)
    time.sleep(0.3)
    dev_b.send_command("BLEGATTDFTSERVER=OFF", wait_for_ok=False)
    time.sleep(0.2)


# ── Dynamic GATT server helpers ───────────────────────────────────────────────


def _devb_build_dyn_service(dev_b: ATCommandHelper) -> bool:
    """Build and activate the dynamic GATT service on devB.

    Service layout:
      ch1: sec_prop=0x0003 (READ+WRITE), max_size=20
      ch2: sec_prop=0x0203 (READ+WRITE+NOTIFY), max_size=20
      ch3: sec_prop=0x0403 (READ+WRITE+INDICATE), max_size=20

    Firmware auto-inserts a CCC descriptor for ch2 and ch3 during
    BLEGATTSVCACTIVE. Returns True if every step returned OK.

    """
    cmds = [
        f"BLEGATTADDSERVICE={_DYN_SVC_PROP},{DYN_SVC_UUID}",
        f"BLEGATTADDCHAR={_DYN_CH1_PROP},{DYN_CH1_UUID},{DYN_MAX_SIZE}",
        f"BLEGATTADDCHAR={_DYN_CH2_PROP},{DYN_CH2_UUID},{DYN_MAX_SIZE}",
        f"BLEGATTADDCHAR={_DYN_CH3_PROP},{DYN_CH3_UUID},{DYN_MAX_SIZE}",
        "BLEGATTSVCACTIVE=00",
    ]
    for cmd in cmds:
        lines = dev_b.send_command(cmd)
        if not dev_b.check_ok(lines):
            logger.error("devB dyn service build failed: %s → %s", cmd, lines)
            return False
    return True


def _devb_start_dyn_gatt(dev_b: ATCommandHelper) -> None:
    """Build dynamic service, set devB BD address, and start advertising."""
    assert _devb_build_dyn_service(dev_b), "devB dynamic GATT service setup failed"
    lines = dev_b.send_command(f"SYSBDADDR={DEV_B_BT_ID},{DEV_B_BD_ADDR}")
    assert dev_b.check_ok(lines), f"devB SYSBDADDR failed (got: {lines})"
    lines = dev_b.send_command(f"BLEADVSETID={ADV_INST},{DEV_B_BT_ID}")
    assert dev_b.check_ok(lines), f"devB BLEADVSETID failed (got: {lines})"
    lines = dev_b.send_command(f"BLEADVENABLE={ADV_INST},ON")
    assert dev_b.check_ok(lines), f"devB BLEADVENABLE=ON failed (got: {lines})"
    time.sleep(0.5)


def _devb_stop_dyn(dev_b: ATCommandHelper) -> None:
    """Stop devB advertising and cold-reboot to clear dynamic GATT services."""
    dev_b.send_command(f"BLEADVENABLE={ADV_INST},OFF", wait_for_ok=False)
    time.sleep(0.3)
    dev_b.send_command("SYSRESET=1", wait_for_ok=False)
    time.sleep(DYN_REBOOT_WAIT)


def _deva_scan_and_connect(at_cmd: ATCommandHelper) -> list[str]:
    """devA: set MAC filter → scan → wait adv report → stop scan → connect.

    Returns lines captured while waiting for +EVTBLEGAPCONN:.

    """
    lines = at_cmd.send_command(f"BLESCANFILMAC=ON,1,{DEV_B_BD_ADDR}")
    assert at_cmd.check_ok(lines), f"BLESCANFILMAC=ON failed (got: {lines})"

    lines = at_cmd.send_command("BLESCANENABLE=ON")
    assert at_cmd.check_ok(lines), f"BLESCANENABLE=ON failed (got: {lines})"

    report = at_cmd.read_until(r"\+EVTBLEGAPADVRPT:", timeout=SCAN_TIMEOUT)
    assert any(
        "+EVTBLEGAPADVRPT:" in l for l in report
    ), f"devA did not receive +EVTBLEGAPADVRPT: within {SCAN_TIMEOUT}s"

    lines = at_cmd.send_command("BLESCANENABLE=OFF")
    assert at_cmd.check_ok(lines), f"BLESCANENABLE=OFF failed (got: {lines})"
    time.sleep(0.3)

    lines = at_cmd.send_command(f"BLEGAPCREATECONN=1,{DEV_B_BD_ADDR},30")
    assert at_cmd.check_ok(lines), f"BLEGAPCREATECONN failed (got: {lines})"

    if any("+EVTBLEGAPCONN:" in l for l in lines):
        return lines
    return at_cmd.read_until(r"\+EVTBLEGAPCONN:", timeout=CONNECT_WAIT)


def _deva_cleanup(at_cmd: ATCommandHelper) -> None:
    """Best-effort devA cleanup: disconnect, cancel pending, stop scan."""
    at_cmd.send_command("BLEGAPDISCONNECT=0", wait_for_ok=False)
    time.sleep(0.3)
    at_cmd.send_command("BLEGAPCANCELCREATECONN=", wait_for_ok=False)
    time.sleep(0.5)
    at_cmd.send_command("BLESCANENABLE=OFF", wait_for_ok=False)
    time.sleep(0.3)


# ── Test class ────────────────────────────────────────────────────────────────
class TestGattClientTwoDev:  # pylint: disable=too-many-public-methods
    """Two-device GATT client/server test.

    devA (central, twister DUT) exercises all GATT client AT commands against
    devB (peripheral, pre-flashed) running the DFT GATT server.

    Commands tested:
      AT+BLEGATTDISCSVCS, AT+BLEGATTDISCSVC, AT+BLEGATTDISCCHARS,
      AT+BLEGATTDISCCHAR, AT+BLEGATTDISCDESCS,
      AT+BLEGATTRD, AT+BLEGATTWR, AT+BLEGATTWRWO, AT+BLEGATTWRCCCD,
      AT+BLEGATTMTUEXCHGREQ

    Events verified:
      +BLEGATTRD, +BLEGATTWR, +BLEGATTNOTI, +BLEGATTINDI,
      +EVTBLEGATTFROMBLE, +EVTBLEGATTMTUEXCHGREQ

    """

    @pytest.fixture(scope="class")
    def gatt_results(
        self, at_cmd: ATCommandHelper, dev_b_at_cmd: ATCommandHelper
    ) -> dict:
        """Run the full GATT lifecycle once; yield a results dict for assertions."""
        # pylint: disable=too-many-locals,too-many-branches,too-many-statements
        r = {
            # connection
            "setup_conn": False,
            # discovery
            "disc_svcs_ok": False,
            "disc_svcs_found": False,
            "disc_svc_ok": False,
            "disc_svc_found": False,
            "disc_chars_ok": False,
            "disc_chars_ch1": False,
            "disc_chars_ch2": False,
            "disc_char_ok": False,
            "disc_char_found": False,
            "disc_descs_ok": False,
            "disc_descs_cccd": False,
            # read / write
            "read_ok": False,
            "read_evt": False,
            "wrwo_ok": False,
            "wrwo_srv_evt": False,
            "wr_ok": False,
            "wr_evt": False,
            "wr_srv_evt": False,
            # subscribe / notify / indicate / unsubscribe
            "wrcccd_noti_ok": False,
            "toble_noti_ok": False,
            "noti_evt": False,
            "wrcccd_indi_ok": False,
            "toble_indi_ok": False,
            "indi_evt": False,
            "unsubscribe_ok": False,
            # edge cases
            "disc_empty_ok": False,
            # MTU
            "mtu_ok": False,
            "mtu_evt": False,
        }
        ctx: dict = {}

        try:
            _devb_start_gatt(dev_b_at_cmd)
            conn_lines = _deva_scan_and_connect(at_cmd)
            r["setup_conn"] = any("+EVTBLEGAPCONN:" in l for l in conn_lines)
            logger.info("devA +EVTBLEGAPCONN: %s", " ".join(conn_lines))

            if not r["setup_conn"]:
                logger.error("Connection failed; skipping GATT operations")
                yield r
                return

            # ── [1] BLEGATTDISCSVCS ───────────────────────────────────────────
            lines = _send_disc_cmd(at_cmd, f"BLEGATTDISCSVCS={CONN_IDX},1,65535,0")
            r["disc_svcs_ok"] = at_cmd.check_ok(lines)
            svcs = _parse_disc_svcs(lines)
            dft = next((s for s in svcs if s["uuid"] == DFT_SVC_UUID.upper()), None)
            r["disc_svcs_found"] = dft is not None
            if dft:
                ctx["svc_start"] = dft["start"]
                ctx["svc_end"] = dft["end"]
            logger.info("BLEGATTDISCSVCS svcs=%s", svcs)

            # ── [2] BLEGATTDISCSVC ────────────────────────────────────────────
            lines = _send_disc_cmd(at_cmd, f"BLEGATTDISCSVC={CONN_IDX},{DFT_SVC_UUID}")
            r["disc_svc_ok"] = at_cmd.check_ok(lines)
            svc1 = _parse_disc_svc(lines)
            r["disc_svc_found"] = any(s["uuid"] == DFT_SVC_UUID.upper() for s in svc1)

            # ── [3] BLEGATTDISCCHARS ──────────────────────────────────────────
            start, end = ctx.get("svc_start"), ctx.get("svc_end")
            if start is not None and end is not None:
                lines = _send_disc_cmd(
                    at_cmd, f"BLEGATTDISCCHARS={CONN_IDX},{start},{end},0"
                )
                r["disc_chars_ok"] = at_cmd.check_ok(lines)
                chars = _parse_disc_chars(lines)
                ch1 = next(
                    (c for c in chars if c["uuid"] == DFT_CH1_UUID.upper()), None
                )
                ch2 = next(
                    (c for c in chars if c["uuid"] == DFT_CH2_UUID.upper()), None
                )
                r["disc_chars_ch1"] = ch1 is not None
                r["disc_chars_ch2"] = ch2 is not None
                if ch1:
                    ctx["ch1_val"] = ch1["val"]
                    ctx["ch1_decl"] = ch1["decl"]
                if ch2:
                    ctx["ch2_val"] = ch2["val"]
                    ctx["ch2_decl"] = ch2["decl"]
                logger.info("BLEGATTDISCCHARS ch1=%s ch2=%s", ch1, ch2)

            # ── [4] BLEGATTDISCCHAR ───────────────────────────────────────────
            lines = _send_disc_cmd(at_cmd, f"BLEGATTDISCCHAR={CONN_IDX},{DFT_CH1_UUID}")
            r["disc_char_ok"] = at_cmd.check_ok(lines)
            chars1 = _parse_disc_chars(lines)
            r["disc_char_found"] = any(
                c["uuid"] == DFT_CH1_UUID.upper() for c in chars1
            )

            # ── [5] BLEGATTDISCDESCS (ch1 CCCD) ──────────────────────────────
            ch1_val = ctx.get("ch1_val")
            svc_end = ctx.get("svc_end")
            ch2_decl = ctx.get("ch2_decl", svc_end)
            if ch1_val is not None and svc_end is not None and ch2_decl is not None:
                desc_end = min(ch2_decl - 1, svc_end)
                lines = _send_disc_cmd(
                    at_cmd, f"BLEGATTDISCDESCS={CONN_IDX},{ch1_val + 1},{desc_end},0"
                )
                r["disc_descs_ok"] = at_cmd.check_ok(lines)
                descs = _parse_disc_descs(lines)
                cccd = next((d for d in descs if "2902" in d["uuid"]), None)
                r["disc_descs_cccd"] = cccd is not None
                if cccd:
                    ctx["ch1_cccd"] = cccd["handle"]
                logger.info("BLEGATTDISCDESCS descs=%s", descs)

            # ── [6] BLEGATTRD ─────────────────────────────────────────────────
            ch2_val = ctx.get("ch2_val")
            if ch2_val is not None:
                lines = at_cmd.send_command(f"BLEGATTRD={CONN_IDX},{ch2_val},0")
                r["read_ok"] = at_cmd.check_ok(lines)
                if not any("+BLEGATTRD:" in l for l in lines):
                    lines += at_cmd.read_until(r"\+BLEGATTRD:", timeout=EVT_TIMEOUT)
                r["read_evt"] = any("+BLEGATTRD:" in l for l in lines)
                logger.info("BLEGATTRD lines=%s", lines)

            # ── [7] BLEGATTWRWO ───────────────────────────────────────────────
            if ch1_val is not None:
                lines = at_cmd.send_command(
                    f"BLEGATTWRWO={CONN_IDX},{ch1_val},{WRITE_DATA}"
                )
                r["wrwo_ok"] = at_cmd.check_ok(lines)
                srv = dev_b_at_cmd.read_until(
                    r"\+EVTBLEGATTFROMBLE:", timeout=EVT_TIMEOUT
                )
                r["wrwo_srv_evt"] = any("+EVTBLEGATTFROMBLE:" in l for l in srv)

            # ── [8] BLEGATTWRCCCD – subscribe notify on ch1 ──────────────────
            ch1_cccd = ctx.get("ch1_cccd")
            if ch1_val is not None and ch1_cccd is not None:
                lines = at_cmd.send_command(
                    f"BLEGATTWRCCCD={CONN_IDX},{ch1_val},{ch1_cccd},1"
                )
                r["wrcccd_noti_ok"] = at_cmd.check_ok(lines)
                time.sleep(0.5)  # allow CCCD write to reach server

                # trigger notify from server: ch1 BLE handle (discovered), action=02
                lines2 = dev_b_at_cmd.send_command(
                    f"BLEGATTTOBLE=0,{ch1_val},02,{NOTIFY_DATA}"
                )
                r["toble_noti_ok"] = dev_b_at_cmd.check_ok(lines2)

                noti = at_cmd.read_until(r"\+BLEGATTNOTI:", timeout=EVT_TIMEOUT)
                r["noti_evt"] = any(
                    "+BLEGATTNOTI:" in l and NOTIFY_DATA.upper() in l.upper()
                    for l in noti
                )
                logger.info("BLEGATTNOTI lines=%s", noti)

            # ── [9] BLEGATTWRCCCD – subscribe indicate on ch2 ────────────────
            if ch2_val is not None:
                # discover ch2 CCCD if not yet in ctx
                ch2_cccd = ctx.get("ch2_cccd")
                if ch2_cccd is None and svc_end is not None:
                    lines = _send_disc_cmd(
                        at_cmd, f"BLEGATTDISCDESCS={CONN_IDX},{ch2_val + 1},{svc_end},0"
                    )
                    descs2 = _parse_disc_descs(lines)
                    cccd2 = next((d for d in descs2 if "2902" in d["uuid"]), None)
                    if cccd2:
                        ctx["ch2_cccd"] = cccd2["handle"]
                        ch2_cccd = cccd2["handle"]

                if ch2_cccd is not None:
                    lines = at_cmd.send_command(
                        f"BLEGATTWRCCCD={CONN_IDX},{ch2_val},{ch2_cccd},2"
                    )
                    r["wrcccd_indi_ok"] = at_cmd.check_ok(lines)
                    time.sleep(0.5)

                    # trigger indicate: ch2 BLE handle (discovered), action=03
                    lines2 = dev_b_at_cmd.send_command(
                        f"BLEGATTTOBLE=0,{ch2_val},03,{INDICATE_DATA}"
                    )
                    r["toble_indi_ok"] = dev_b_at_cmd.check_ok(lines2)

                    indi = at_cmd.read_until(r"\+BLEGATTINDI:", timeout=EVT_TIMEOUT)
                    r["indi_evt"] = any(
                        "+BLEGATTINDI:" in l and INDICATE_DATA.upper() in l.upper()
                        for l in indi
                    )
                    logger.info("BLEGATTINDI lines=%s", indi)

            # ── [10] BLEGATTWRCCCD – unsubscribe ch1 ─────────────────────────
            if ch1_val is not None and ch1_cccd is not None:
                lines = at_cmd.send_command(
                    f"BLEGATTWRCCCD={CONN_IDX},{ch1_val},{ch1_cccd},0"
                )
                r["unsubscribe_ok"] = at_cmd.check_ok(lines)

            # ── [11] BLEGATTWR – plain write with response ────────────────────
            if ch1_val is not None:
                lines = at_cmd.send_command(
                    f"BLEGATTWR={CONN_IDX},{ch1_val},{WRITE_DATA}"
                )
                r["wr_ok"] = at_cmd.check_ok(lines)
                if not any("+BLEGATTWR:" in l for l in lines):
                    lines += at_cmd.read_until(r"\+BLEGATTWR:", timeout=EVT_TIMEOUT)
                r["wr_evt"] = any("+BLEGATTWR:" in l for l in lines)
                srv2 = dev_b_at_cmd.read_until(
                    r"\+EVTBLEGATTFROMBLE:", timeout=EVT_TIMEOUT
                )
                r["wr_srv_evt"] = any("+EVTBLEGATTFROMBLE:" in l for l in srv2)

            # ── [12] BLEGATTDISCCHARS – empty range ───────────────────────────
            if svc_end is not None:
                lines = _send_disc_cmd(
                    at_cmd,
                    f"BLEGATTDISCCHARS={CONN_IDX},{svc_end + 1},{svc_end + 10},0",
                )
                empty_chars = _parse_disc_chars(lines)
                r["disc_empty_ok"] = at_cmd.check_ok(lines) and len(empty_chars) == 0

            # ── [13] BLEGATTMTUEXCHGREQ ───────────────────────────────────────
            lines = at_cmd.send_command(f"BLEGATTMTUEXCHGREQ={CONN_IDX}")
            r["mtu_ok"] = at_cmd.check_ok(lines)
            if not any("+EVTBLEGATTMTUEXCHGREQ:" in l for l in lines):
                lines += at_cmd.read_until(
                    r"\+EVTBLEGATTMTUEXCHGREQ:", timeout=EVT_TIMEOUT
                )
            r["mtu_evt"] = any("+EVTBLEGATTMTUEXCHGREQ:" in l for l in lines)
            logger.info("BLEGATTMTUEXCHGREQ lines=%s", lines)

            # ── Disconnect ────────────────────────────────────────────────────
            disc = at_cmd.send_command("BLEGAPDISCONNECT=0")
            assert at_cmd.check_ok(disc), f"BLEGAPDISCONNECT=0 failed (got: {disc})"
            at_cmd.read_until(r"\+EVTBLEGAPDISCONN:", timeout=EVT_TIMEOUT)

        finally:
            _deva_cleanup(at_cmd)
            _devb_stop(dev_b_at_cmd)

        yield r

    # ── Assertions ────────────────────────────────────────────────────────────

    def test_connection_setup(self, gatt_results: dict):
        """devA must establish BLE connection to devB GATT server."""
        assert gatt_results["setup_conn"], "+EVTBLEGAPCONN: not received"

    def test_disc_svcs_ok(self, gatt_results: dict):
        """AT+BLEGATTDISCSVCS must return OK."""
        assert gatt_results["disc_svcs_ok"], "BLEGATTDISCSVCS did not return OK"

    def test_disc_svcs_dft_service_found(self, gatt_results: dict):
        """AT+BLEGATTDISCSVCS must discover the DFT service UUID."""
        assert gatt_results[
            "disc_svcs_found"
        ], f"DFT service {DFT_SVC_UUID} not found via BLEGATTDISCSVCS"

    def test_disc_svc_ok(self, gatt_results: dict):
        """AT+BLEGATTDISCSVC must return OK."""
        assert gatt_results["disc_svc_ok"], "BLEGATTDISCSVC did not return OK"

    def test_disc_svc_found(self, gatt_results: dict):
        """AT+BLEGATTDISCSVC must find the DFT service by UUID."""
        assert gatt_results[
            "disc_svc_found"
        ], f"DFT service {DFT_SVC_UUID} not found via BLEGATTDISCSVC"

    def test_disc_chars_ok(self, gatt_results: dict):
        """AT+BLEGATTDISCCHARS must return OK."""
        assert gatt_results["disc_chars_ok"], "BLEGATTDISCCHARS did not return OK"

    def test_disc_chars_ch1_found(self, gatt_results: dict):
        """AT+BLEGATTDISCCHARS must discover char1 (DFT_CH1_UUID)."""
        assert gatt_results[
            "disc_chars_ch1"
        ], f"Char1 {DFT_CH1_UUID} not found via BLEGATTDISCCHARS"

    def test_disc_chars_ch2_found(self, gatt_results: dict):
        """AT+BLEGATTDISCCHARS must discover char2 (DFT_CH2_UUID)."""
        assert gatt_results[
            "disc_chars_ch2"
        ], f"Char2 {DFT_CH2_UUID} not found via BLEGATTDISCCHARS"

    def test_disc_char_ok(self, gatt_results: dict):
        """AT+BLEGATTDISCCHAR must return OK."""
        assert gatt_results["disc_char_ok"], "BLEGATTDISCCHAR did not return OK"

    def test_disc_char_found(self, gatt_results: dict):
        """AT+BLEGATTDISCCHAR must find char1 by UUID."""
        assert gatt_results[
            "disc_char_found"
        ], f"Char1 {DFT_CH1_UUID} not found via BLEGATTDISCCHAR"

    def test_disc_descs_ok(self, gatt_results: dict):
        """AT+BLEGATTDISCDESCS must return OK."""
        assert gatt_results["disc_descs_ok"], "BLEGATTDISCDESCS did not return OK"

    def test_disc_descs_cccd_found(self, gatt_results: dict):
        """AT+BLEGATTDISCDESCS must find char1 CCCD (UUID 0x2902)."""
        assert gatt_results["disc_descs_cccd"], "Char1 CCCD (UUID 2902) not found"

    def test_read_ok(self, gatt_results: dict):
        """AT+BLEGATTRD must return OK (read request accepted)."""
        assert gatt_results["read_ok"], "BLEGATTRD did not return OK"

    def test_read_event(self, gatt_results: dict):
        """+BLEGATTRD: event must be emitted after AT+BLEGATTRD."""
        assert gatt_results["read_evt"], "+BLEGATTRD: event not received"

    def test_wrwo_ok(self, gatt_results: dict):
        """AT+BLEGATTWRWO must return OK (write without response accepted)."""
        assert gatt_results["wrwo_ok"], "BLEGATTWRWO did not return OK"

    def test_wrwo_server_event(self, gatt_results: dict):
        """devB must receive +EVTBLEGATTFROMBLE: after AT+BLEGATTWRWO from devA."""
        assert gatt_results[
            "wrwo_srv_evt"
        ], "+EVTBLEGATTFROMBLE: not received on devB after BLEGATTWRWO"

    def test_wrcccd_notify_ok(self, gatt_results: dict):
        """AT+BLEGATTWRCCCD with ccc_value=1 (notify) must return OK."""
        assert gatt_results[
            "wrcccd_noti_ok"
        ], "BLEGATTWRCCCD notify subscribe did not return OK"

    def test_blegatttoble_notify_ok(self, gatt_results: dict):
        """AT+BLEGATTTOBLE notify on devB must return OK."""
        assert gatt_results[
            "toble_noti_ok"
        ], "BLEGATTTOBLE notify did not return OK on devB"

    def test_notify_event(self, gatt_results: dict):
        """+BLEGATTNOTI: event with correct data must be received on devA."""
        assert gatt_results[
            "noti_evt"
        ], f"+BLEGATTNOTI: with data {NOTIFY_DATA} not received on devA"

    def test_wrcccd_indicate_ok(self, gatt_results: dict):
        """AT+BLEGATTWRCCCD with ccc_value=2 (indicate) must return OK."""
        assert gatt_results[
            "wrcccd_indi_ok"
        ], "BLEGATTWRCCCD indicate subscribe did not return OK"

    def test_blegatttoble_indicate_ok(self, gatt_results: dict):
        """AT+BLEGATTTOBLE indicate on devB must return OK."""
        assert gatt_results[
            "toble_indi_ok"
        ], "BLEGATTTOBLE indicate did not return OK on devB"

    def test_indicate_event(self, gatt_results: dict):
        """+BLEGATTINDI: event with correct data must be received on devA."""
        assert gatt_results[
            "indi_evt"
        ], f"+BLEGATTINDI: with data {INDICATE_DATA} not received on devA"

    def test_unsubscribe_ok(self, gatt_results: dict):
        """AT+BLEGATTWRCCCD with ccc_value=0 (unsubscribe) must return OK."""
        assert gatt_results[
            "unsubscribe_ok"
        ], "BLEGATTWRCCCD unsubscribe did not return OK"

    def test_wr_ok(self, gatt_results: dict):
        """AT+BLEGATTWR (write with response) must return OK."""
        assert gatt_results["wr_ok"], "BLEGATTWR did not return OK"

    def test_wr_event(self, gatt_results: dict):
        """+BLEGATTWR: event must be emitted after AT+BLEGATTWR."""
        assert gatt_results["wr_evt"], "+BLEGATTWR: event not received"

    def test_wr_server_event(self, gatt_results: dict):
        """devB must receive +EVTBLEGATTFROMBLE: after AT+BLEGATTWR from devA."""
        assert gatt_results[
            "wr_srv_evt"
        ], "+EVTBLEGATTFROMBLE: not received on devB after BLEGATTWR"

    def test_disc_empty_range(self, gatt_results: dict):
        """AT+BLEGATTDISCCHARS on empty handle range must return OK with no results."""
        assert gatt_results[
            "disc_empty_ok"
        ], "BLEGATTDISCCHARS on empty range failed or returned unexpected results"

    def test_mtu_exchange_ok(self, gatt_results: dict):
        """AT+BLEGATTMTUEXCHGREQ must return OK."""
        assert gatt_results["mtu_ok"], "BLEGATTMTUEXCHGREQ did not return OK"

    def test_mtu_exchange_event(self, gatt_results: dict):
        """+EVTBLEGATTMTUEXCHGREQ: event must be emitted after MTU exchange request."""
        assert gatt_results["mtu_evt"], "+EVTBLEGATTMTUEXCHGREQ: event not received"


# ── Dynamic GATT server tests ─────────────────────────────────────────────────


class TestGattDynBuildErrors:  # pylint: disable=too-few-public-methods
    """Two-device test: dynamic GATT service build error handling on devB.

    devB attempts invalid build sequences via AT commands and verifies that
    the firmware returns appropriate error responses.  No BLE connection to
    devA is needed for these tests.

    Error cases exercised:
      ADDCHAR without prior ADDSERVICE  → NO_SVC error
      ADDDESC without prior ADDCHAR     → NO_CHAR error
      BLEGATTSVCACTIVE, no staged svc   → NO_SVC error
      ADDSERVICE with write-perm bits   → PARAM_INVALID error
      ADDCHAR on already-active service → SVC_ACTIVE error

    """

    @pytest.fixture(scope="class")
    def build_errors(self, dev_b_at_cmd: ATCommandHelper) -> dict:
        """Run all error-case sequences on devB; yield a result dict."""
        r = {
            "addchar_no_svc": False,
            "adddesc_no_char": False,
            "svcactive_no_svc": False,
            "svc_write_bits": False,
            "addchar_to_active": False,
        }

        try:
            # [1] ADDCHAR before ADDSERVICE
            lines = dev_b_at_cmd.send_command(
                f"BLEGATTADDCHAR={_DYN_CH1_PROP},{DYN_CH1_UUID},{DYN_MAX_SIZE}"
            )
            r["addchar_no_svc"] = dev_b_at_cmd.check_error(lines)

            # [2] ADDDESC before ADDCHAR
            lines = dev_b_at_cmd.send_command("BLEGATTADDDESC=2902")
            r["adddesc_no_char"] = dev_b_at_cmd.check_error(lines)

            # [3] BLEGATTSVCACTIVE with no staged service
            lines = dev_b_at_cmd.send_command("BLEGATTSVCACTIVE=00")
            r["svcactive_no_svc"] = dev_b_at_cmd.check_error(lines)

            # [4] ADDSERVICE with write permission bits (BLE spec: svc decl is read-only)
            lines = dev_b_at_cmd.send_command(f"BLEGATTADDSERVICE=0002,{DYN_SVC_UUID}")
            r["svc_write_bits"] = dev_b_at_cmd.check_error(lines)

            # [5] ADDCHAR on an already-active service
            activated = (
                dev_b_at_cmd.check_ok(
                    dev_b_at_cmd.send_command(
                        f"BLEGATTADDSERVICE={_DYN_SVC_PROP},{DYN_SVC_UUID}"
                    )
                )
                and dev_b_at_cmd.check_ok(
                    dev_b_at_cmd.send_command(
                        f"BLEGATTADDCHAR={_DYN_CH1_PROP},{DYN_CH1_UUID},{DYN_MAX_SIZE}"
                    )
                )
                and dev_b_at_cmd.check_ok(
                    dev_b_at_cmd.send_command("BLEGATTSVCACTIVE=00")
                )
            )
            if activated:
                lines = dev_b_at_cmd.send_command(
                    f"BLEGATTADDCHAR={_DYN_CH1_PROP},{DYN_CH2_UUID},{DYN_MAX_SIZE}"
                )
                r["addchar_to_active"] = dev_b_at_cmd.check_error(lines)

        finally:
            # Cold-reboot devB to clear any staged/active dynamic services
            dev_b_at_cmd.send_command("SYSRESET=1", wait_for_ok=False)
            time.sleep(DYN_REBOOT_WAIT)

        yield r

    # ── Assertions ────────────────────────────────────────────────────────────

    def test_addchar_without_service(self, build_errors: dict):
        """BLEGATTADDCHAR before BLEGATTADDSERVICE must return error (NO_SVC)."""
        assert build_errors[
            "addchar_no_svc"
        ], "Expected error for BLEGATTADDCHAR without prior BLEGATTADDSERVICE"

    def test_adddesc_without_char(self, build_errors: dict):
        """BLEGATTADDDESC before BLEGATTADDCHAR must return error (NO_CHAR)."""
        assert build_errors[
            "adddesc_no_char"
        ], "Expected error for BLEGATTADDDESC without prior BLEGATTADDCHAR"

    def test_svcactive_no_service(self, build_errors: dict):
        """BLEGATTSVCACTIVE with no staged service must return error."""
        assert build_errors[
            "svcactive_no_svc"
        ], "Expected error for BLEGATTSVCACTIVE with no staged service"

    def test_addservice_write_bits_rejected(self, build_errors: dict):
        """BLEGATTADDSERVICE with write permission bits must return error."""
        assert build_errors[
            "svc_write_bits"
        ], "Expected error for BLEGATTADDSERVICE with write permission bits"

    def test_addchar_to_active_service(self, build_errors: dict):
        """BLEGATTADDCHAR on an already-active service must return error (SVC_ACTIVE)."""
        assert build_errors[
            "addchar_to_active"
        ], "Expected error for BLEGATTADDCHAR on active service"


class TestGattDynServerTwoDev:  # pylint: disable=too-many-public-methods
    """Two-device test: devB acts as a dynamic GATT server.

    devB builds a custom GATT service via AT commands:
      ch1: READ+WRITE  (exercises BLEGATTRD / BLEGATTWR)
      ch2: READ+WRITE+NOTIFY   (exercises BLEGATTWRCCCD + BLEGATTTOBLE notify)
      ch3: READ+WRITE+INDICATE (exercises BLEGATTWRCCCD + BLEGATTTOBLE indicate)

    devA (central, twister DUT) connects, discovers the service, and
    performs the GATT operations above.

    Note: devB is rebooted in fixture teardown to clear dynamic services.

    """

    @pytest.fixture(scope="class")
    def dyn_results(
        self, at_cmd: ATCommandHelper, dev_b_at_cmd: ATCommandHelper
    ) -> dict:
        """Build devB dynamic service, connect devA, run full GATT lifecycle."""
        # pylint: disable=too-many-locals,too-many-branches,too-many-statements
        r = {
            "build_ok": False,
            "conn_ok": False,
            "disc_svc_ok": False,
            "disc_svc_found": False,
            "disc_chars_ok": False,
            "disc_ch1_found": False,
            "disc_ch2_found": False,
            "disc_ch3_found": False,
            "read_ok": False,
            "read_evt": False,
            "read_data_ok": False,
            "wr_ok": False,
            "wr_evt": False,
            "wr_srv_evt": False,
            "wr_srv_data_ok": False,
            "sub_noti_ok": False,
            "toble_noti_ok": False,
            "noti_evt": False,
            "sub_indi_ok": False,
            "toble_indi_ok": False,
            "indi_evt": False,
        }
        ctx: dict = {}

        try:
            _devb_start_dyn_gatt(dev_b_at_cmd)
            r["build_ok"] = True

            conn_lines = _deva_scan_and_connect(at_cmd)
            r["conn_ok"] = any("+EVTBLEGAPCONN:" in l for l in conn_lines)
            logger.info("devA +EVTBLEGAPCONN: %s", " ".join(conn_lines))
            if not r["conn_ok"]:
                yield r
                return

            # ── [1] Discover service by UUID ──────────────────────────────────
            lines = _send_disc_cmd(at_cmd, f"BLEGATTDISCSVC={CONN_IDX},{DYN_SVC_UUID}")
            r["disc_svc_ok"] = at_cmd.check_ok(lines)
            svcs = _parse_disc_svc(lines)
            dyn = next(
                (s for s in svcs if s["uuid"].upper() == DYN_SVC_UUID.upper()), None
            )
            r["disc_svc_found"] = dyn is not None
            if dyn:
                ctx["svc_start"] = dyn["start"]
                ctx["svc_end"] = dyn["end"]
            logger.info("BLEGATTDISCSVC dyn=%s", dyn)

            # ── [2] Discover characteristics in service range ──────────────────
            svc_start = ctx.get("svc_start")
            svc_end = ctx.get("svc_end")
            if svc_start is not None and svc_end is not None:
                lines = _send_disc_cmd(
                    at_cmd,
                    f"BLEGATTDISCCHARS={CONN_IDX},{svc_start},{svc_end},0",
                )
                r["disc_chars_ok"] = at_cmd.check_ok(lines)
                chars = _parse_disc_chars(lines)
                ch1 = next(
                    (c for c in chars if c["uuid"].upper() == DYN_CH1_UUID.upper()),
                    None,
                )
                ch2 = next(
                    (c for c in chars if c["uuid"].upper() == DYN_CH2_UUID.upper()),
                    None,
                )
                ch3 = next(
                    (c for c in chars if c["uuid"].upper() == DYN_CH3_UUID.upper()),
                    None,
                )
                r["disc_ch1_found"] = ch1 is not None
                r["disc_ch2_found"] = ch2 is not None
                r["disc_ch3_found"] = ch3 is not None
                if ch1:
                    ctx["ch1_val"] = ch1["val"]
                if ch2:
                    ctx["ch2_val"] = ch2["val"]
                    ctx["ch2_decl"] = ch2["decl"]
                if ch3:
                    ctx["ch3_val"] = ch3["val"]
                    ctx["ch3_decl"] = ch3["decl"]
                logger.info("BLEGATTDISCCHARS ch1=%s ch2=%s ch3=%s", ch1, ch2, ch3)

            # ── [3] Write ch1 (with response); verify server+client events ──
            ch1_val = ctx.get("ch1_val")
            if ch1_val is not None:
                lines = at_cmd.send_command(
                    f"BLEGATTWR={CONN_IDX},{ch1_val},{DYN_WRITE_DATA}"
                )
                r["wr_ok"] = at_cmd.check_ok(lines)
                if not any("+BLEGATTWR:" in l for l in lines):
                    lines += at_cmd.read_until(r"\+BLEGATTWR:", timeout=EVT_TIMEOUT)
                r["wr_evt"] = any("+BLEGATTWR:" in l for l in lines)
                srv = dev_b_at_cmd.read_until(
                    r"\+EVTBLEGATTFROMBLE:", timeout=EVT_TIMEOUT
                )
                r["wr_srv_evt"] = any("+EVTBLEGATTFROMBLE:" in l for l in srv)
                # Parse +EVTBLEGATTFROMBLE:<conn>,<handle>,<write_type>,<data> verify data
                _fromble_re = re.compile(
                    r"\+EVTBLEGATTFROMBLE:[0-9A-Fa-f]+,[0-9A-Fa-f]+,[0-9A-Fa-f]+,([0-9A-Fa-f]+)",
                    re.I,
                )
                fromble_data = None
                for line in srv:
                    m = _fromble_re.search(line)
                    if m:
                        fromble_data = m.group(1)
                        break
                r["wr_srv_data_ok"] = (
                    fromble_data is not None
                    and fromble_data.upper() == DYN_WRITE_DATA.upper()
                )
                logger.info(
                    "BLEGATTWR ch1: lines=%s srv=%s fromble_data=%s",
                    lines,
                    srv,
                    fromble_data,
                )

            # ── [4] Read ch1; verify event + returned data == DYN_WRITE_DATA ─
            if ch1_val is not None:
                lines = at_cmd.send_command(f"BLEGATTRD={CONN_IDX},{ch1_val},0")
                r["read_ok"] = at_cmd.check_ok(lines)
                if not any("+BLEGATTRD:" in l for l in lines):
                    lines += at_cmd.read_until(r"\+BLEGATTRD:", timeout=EVT_TIMEOUT)
                r["read_evt"] = any("+BLEGATTRD:" in l for l in lines)
                # Parse +BLEGATTRD:<conn>,<handle>,<data> and verify data
                _rd_re = re.compile(
                    r"\+BLEGATTRD:[0-9A-Fa-f]+,[0-9A-Fa-f]+,([0-9A-Fa-f]*)", re.I
                )
                rd_data = None
                for line in lines:
                    m = _rd_re.search(line)
                    if m:
                        rd_data = m.group(1)
                        break
                r["read_data_ok"] = (
                    rd_data is not None and rd_data.upper() == DYN_WRITE_DATA.upper()
                )
                logger.info(
                    "BLEGATTRD ch1 lines=%s rd_data=%s expected=%s",
                    lines,
                    rd_data,
                    DYN_WRITE_DATA,
                )

            # ── [5] Subscribe notify on ch2; devB triggers notify ─────────────
            ch2_val = ctx.get("ch2_val")
            ch3_decl = ctx.get("ch3_decl")
            if ch2_val is not None and svc_end is not None:
                # Discover ch2 CCCD: between ch2_val+1 and ch3_decl-1 (or svc_end)
                cccd_end = (ch3_decl - 1) if ch3_decl is not None else svc_end
                lines = _send_disc_cmd(
                    at_cmd,
                    f"BLEGATTDISCDESCS={CONN_IDX},{ch2_val + 1},{cccd_end},0",
                )
                descs = _parse_disc_descs(lines)
                ch2_cccd = next(
                    (d["handle"] for d in descs if "2902" in d["uuid"]), None
                )
                if ch2_cccd is not None:
                    lines = at_cmd.send_command(
                        f"BLEGATTWRCCCD={CONN_IDX},{ch2_val},{ch2_cccd},1"
                    )
                    r["sub_noti_ok"] = at_cmd.check_ok(lines)
                    time.sleep(0.5)

                    # devB sends notify; ch2_val is the BT attribute handle
                    # (same handle devA discovered via BLEGATTDISCCHARS)
                    lines2 = dev_b_at_cmd.send_command(
                        f"BLEGATTTOBLE=0,{ch2_val},02,{DYN_NOTIFY_DATA}"
                    )
                    r["toble_noti_ok"] = dev_b_at_cmd.check_ok(lines2)

                    noti = at_cmd.read_until(r"\+BLEGATTNOTI:", timeout=EVT_TIMEOUT)
                    r["noti_evt"] = any(
                        "+BLEGATTNOTI:" in l and DYN_NOTIFY_DATA.upper() in l.upper()
                        for l in noti
                    )
                    logger.info("BLEGATTNOTI lines=%s", noti)

            # ── [6] Subscribe indicate on ch3; devB triggers indicate ─────────
            ch3_val = ctx.get("ch3_val")
            if ch3_val is not None and svc_end is not None:
                lines = _send_disc_cmd(
                    at_cmd,
                    f"BLEGATTDISCDESCS={CONN_IDX},{ch3_val + 1},{svc_end},0",
                )
                descs = _parse_disc_descs(lines)
                ch3_cccd = next(
                    (d["handle"] for d in descs if "2902" in d["uuid"]), None
                )
                if ch3_cccd is not None:
                    lines = at_cmd.send_command(
                        f"BLEGATTWRCCCD={CONN_IDX},{ch3_val},{ch3_cccd},2"
                    )
                    r["sub_indi_ok"] = at_cmd.check_ok(lines)
                    time.sleep(0.5)

                    lines2 = dev_b_at_cmd.send_command(
                        f"BLEGATTTOBLE=0,{ch3_val},03,{DYN_INDI_DATA}"
                    )
                    r["toble_indi_ok"] = dev_b_at_cmd.check_ok(lines2)

                    indi = at_cmd.read_until(r"\+BLEGATTINDI:", timeout=EVT_TIMEOUT)
                    r["indi_evt"] = any(
                        "+BLEGATTINDI:" in l and DYN_INDI_DATA.upper() in l.upper()
                        for l in indi
                    )
                    logger.info("BLEGATTINDI lines=%s", indi)

            # ── Disconnect ────────────────────────────────────────────────────
            disc = at_cmd.send_command("BLEGAPDISCONNECT=0")
            assert at_cmd.check_ok(disc), f"BLEGAPDISCONNECT=0 failed (got: {disc})"
            at_cmd.read_until(r"\+EVTBLEGAPDISCONN:", timeout=EVT_TIMEOUT)

        finally:
            _deva_cleanup(at_cmd)
            _devb_stop_dyn(dev_b_at_cmd)

        yield r

    # ── Assertions ────────────────────────────────────────────────────────────

    def test_dyn_service_build(self, dyn_results: dict):
        """devB must build and activate the dynamic GATT service successfully."""
        assert dyn_results[
            "build_ok"
        ], "Dynamic GATT service build/activate on devB failed"

    def test_connection_setup(self, dyn_results: dict):
        """devA must establish BLE connection to devB dynamic GATT server."""
        assert dyn_results["conn_ok"], "+EVTBLEGAPCONN: not received from devB"

    def test_disc_svc_ok(self, dyn_results: dict):
        """AT+BLEGATTDISCSVC must return OK for the dynamic service UUID."""
        assert dyn_results["disc_svc_ok"], "BLEGATTDISCSVC did not return OK"

    def test_disc_svc_found(self, dyn_results: dict):
        """AT+BLEGATTDISCSVC must find the dynamic service by UUID."""
        assert dyn_results[
            "disc_svc_found"
        ], f"Dynamic service {DYN_SVC_UUID} not found via BLEGATTDISCSVC"

    def test_disc_chars_ok(self, dyn_results: dict):
        """AT+BLEGATTDISCCHARS must return OK over the dynamic service handle range."""
        assert dyn_results["disc_chars_ok"], "BLEGATTDISCCHARS did not return OK"

    def test_disc_ch1_found(self, dyn_results: dict):
        """AT+BLEGATTDISCCHARS must discover ch1 (READ+WRITE)."""
        assert dyn_results[
            "disc_ch1_found"
        ], f"Dynamic ch1 {DYN_CH1_UUID} not found via BLEGATTDISCCHARS"

    def test_disc_ch2_found(self, dyn_results: dict):
        """AT+BLEGATTDISCCHARS must discover ch2 (READ+WRITE+NOTIFY)."""
        assert dyn_results[
            "disc_ch2_found"
        ], f"Dynamic ch2 {DYN_CH2_UUID} not found via BLEGATTDISCCHARS"

    def test_disc_ch3_found(self, dyn_results: dict):
        """AT+BLEGATTDISCCHARS must discover ch3 (READ+WRITE+INDICATE)."""
        assert dyn_results[
            "disc_ch3_found"
        ], f"Dynamic ch3 {DYN_CH3_UUID} not found via BLEGATTDISCCHARS"

    def test_read_ok(self, dyn_results: dict):
        """AT+BLEGATTRD on ch1 must return OK."""
        assert dyn_results["read_ok"], "BLEGATTRD ch1 did not return OK"

    def test_read_event(self, dyn_results: dict):
        """+BLEGATTRD: event must be received after AT+BLEGATTRD on ch1."""
        assert dyn_results["read_evt"], "+BLEGATTRD: event not received for ch1"

    def test_read_data(self, dyn_results: dict):
        """+BLEGATTRD: data must match the previously written DYN_WRITE_DATA."""
        assert dyn_results[
            "read_data_ok"
        ], f"+BLEGATTRD: returned data does not match {DYN_WRITE_DATA}"

    def test_write_ok(self, dyn_results: dict):
        """AT+BLEGATTWR (write with response) on ch1 must return OK."""
        assert dyn_results["wr_ok"], "BLEGATTWR ch1 did not return OK"

    def test_write_event(self, dyn_results: dict):
        """+BLEGATTWR: event must be received after AT+BLEGATTWR on ch1."""
        assert dyn_results["wr_evt"], "+BLEGATTWR: event not received for ch1"

    def test_write_server_event(self, dyn_results: dict):
        """devB must receive +EVTBLEGATTFROMBLE: after AT+BLEGATTWR from devA."""
        assert dyn_results[
            "wr_srv_evt"
        ], "+EVTBLEGATTFROMBLE: not received on devB after BLEGATTWR on ch1"

    def test_write_server_data(self, dyn_results: dict):
        """+EVTBLEGATTFROMBLE: data on devB must match written DYN_WRITE_DATA."""
        assert dyn_results[
            "wr_srv_data_ok"
        ], f"+EVTBLEGATTFROMBLE: data on devB does not match {DYN_WRITE_DATA}"

    def test_subscribe_notify_ok(self, dyn_results: dict):
        """AT+BLEGATTWRCCCD with ccc_value=1 on ch2 CCCD must return OK."""
        assert dyn_results[
            "sub_noti_ok"
        ], "BLEGATTWRCCCD notify subscribe on ch2 failed"

    def test_toble_notify_ok(self, dyn_results: dict):
        """AT+BLEGATTTOBLE notify on devB ch2 must return OK."""
        assert dyn_results["toble_noti_ok"], "BLEGATTTOBLE notify on ch2 failed on devB"

    def test_notify_event(self, dyn_results: dict):
        """+BLEGATTNOTI: with correct payload must be received on devA from ch2."""
        assert dyn_results[
            "noti_evt"
        ], f"+BLEGATTNOTI: with data {DYN_NOTIFY_DATA} not received on devA"

    def test_subscribe_indicate_ok(self, dyn_results: dict):
        """AT+BLEGATTWRCCCD with ccc_value=2 on ch3 CCCD must return OK."""
        assert dyn_results[
            "sub_indi_ok"
        ], "BLEGATTWRCCCD indicate subscribe on ch3 failed"

    def test_toble_indicate_ok(self, dyn_results: dict):
        """AT+BLEGATTTOBLE indicate on devB ch3 must return OK."""
        assert dyn_results[
            "toble_indi_ok"
        ], "BLEGATTTOBLE indicate on ch3 failed on devB"

    def test_indicate_event(self, dyn_results: dict):
        """+BLEGATTINDI: with correct payload must be received on devA from ch3."""
        assert dyn_results[
            "indi_evt"
        ], f"+BLEGATTINDI: with data {DYN_INDI_DATA} not received on devA"


if __name__ == "__main__":
    pytest.main([__file__, "-v"])
