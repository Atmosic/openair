# Copyright (c) 2026 Atmosic
#
# SPDX-License-Identifier: LicenseRef-Atmosic

"""Minimal raw serial host helper for Atmosic HCI vendor (H4) commands."""

from __future__ import annotations

import struct
import time
from dataclasses import dataclass, field

import serial

DEFAULT_BAUD_RATE = 2000000
DEFAULT_RESPONSE_TIMEOUT_S = 5.0

# H4 packet type indicators
H4_CMD = 0x01
H4_EVT = 0x04

# HCI event code
HCI_EVT_CMD_COMPLETE = 0x0E

# MFG OGF (Atmosic manufacturing group)
MFG_OGF = 0x3E
# MFG_OGF_SB1 = MFG_OGF << 2 = 0xF8 — stored as opcode MSB in the HCI event buffer
MFG_OGF_SB1 = MFG_OGF << 2

# PSM vendor command — opcode 0xF80F
# OCF enum value: MFG_OCF_PSM = 0x0F (15th entry starting from 0x01)
PSM_CMD_OCF = 0x0F
PSM_CMD_OGF_SB1 = MFG_OGF_SB1  # 0xF8

# Little-endian opcode bytes stored/returned in HCI packets
PSM_OPCODE_LO = PSM_CMD_OCF  # 0x0F
PSM_OPCODE_HI = PSM_CMD_OGF_SB1  # 0xF8

# PSM mode values for CONFIG_SOC_FAMILY_ATM (atm_vendor_internal.h)
PSM_NONE = 0  # No sleep; keep UART unparked
PSM_DEEP = 1  # PM_STATE_SUSPEND_TO_IDLE
PSM_RETAIN = 2  # PM_STATE_SUSPEND_TO_RAM
PSM_HIBERNATE = 4  # PM_STATE_SOFT_OFF substate 0
PSM_SOC_OFF = 5  # PM_STATE_SOFT_OFF substate 1

# HCI return status
HCI_STATUS_SUCCESS = 0x00


@dataclass(frozen=True)
class HciCmdCompleteEvent:
    """Parsed HCI Command Complete event (0x0E)."""

    opcode_lo: int
    opcode_hi: int
    status: int
    extra: bytes = field(default=b"")

    @property
    def opcode(self) -> int:
        """Full 16-bit HCI opcode."""
        return (self.opcode_hi << 8) | self.opcode_lo

    @property
    def success(self) -> bool:
        """True when the device returned HCI_STATUS_SUCCESS (0x00)."""
        return self.status == HCI_STATUS_SUCCESS


class HciVendorHost:
    """Host-side helper for sending HCI vendor commands via H4 UART.

    Wire format (H4 raw):
      Command:  01 <ocf> <ogf_sb1> <param_len> <params…>
      Response: 04 0E <total_param_len> <num_hci> <ocf> <ogf_sb1> <status> [<extra…>]
    """

    def __init__(
        self,
        port: str,
        baud: int = DEFAULT_BAUD_RATE,
        timeout: float = DEFAULT_RESPONSE_TIMEOUT_S,
    ) -> None:
        self.port = port
        self.baud = baud
        self.timeout = timeout
        self._serial: serial.Serial | None = None

    # ------------------------------------------------------------------
    # Lifecycle
    # ------------------------------------------------------------------

    def open(self) -> None:
        """Open the configured serial port."""
        if self._serial and self._serial.is_open:
            return
        self._serial = serial.Serial(
            port=self.port,
            baudrate=self.baud,
            timeout=0.1,
            write_timeout=self.timeout,
        )

    def close(self) -> None:
        """Close the serial port."""
        if self._serial and self._serial.is_open:
            self._serial.close()

    def clear_input(self) -> None:
        """Discard any pending bytes before issuing a command."""
        if self._serial and self._serial.is_open:
            self._serial.reset_input_buffer()

    # ------------------------------------------------------------------
    # Low-level transport
    # ------------------------------------------------------------------

    def _write(self, data: bytes) -> None:
        self._serial.write(data)
        self._serial.flush()

    def _read_exact(self, size: int) -> bytes:
        deadline = time.monotonic() + self.timeout
        buf = bytearray()
        while len(buf) < size and time.monotonic() < deadline:
            chunk = self._serial.read(size - len(buf))
            if chunk:
                buf.extend(chunk)
        if len(buf) < size:
            raise TimeoutError(
                f"Timeout waiting for {size} bytes on {self.port}; got {len(buf)}"
            )
        return bytes(buf)

    def _send_cmd(self, ocf: int, ogf_sb1: int, params: bytes) -> None:
        """Send one H4 HCI command packet."""
        pkt = bytes([H4_CMD, ocf, ogf_sb1, len(params)]) + params
        self._write(pkt)

    def _recv_cmd_complete(self) -> HciCmdCompleteEvent:
        """Read and parse one H4 HCI Command Complete event."""
        h4_type = self._read_exact(1)[0]
        if h4_type != H4_EVT:
            raise ValueError(
                f"Unexpected H4 type 0x{h4_type:02x}; expected 0x{H4_EVT:02x}"
            )
        evt_code, param_len = struct.unpack("BB", self._read_exact(2))
        if evt_code != HCI_EVT_CMD_COMPLETE:
            raise ValueError(f"Unexpected HCI event code 0x{evt_code:02x}")
        # params layout: num_hci(1) | opcode_lo(1) | opcode_hi(1) | status(1) | extra(…)
        params = self._read_exact(param_len)
        opcode_lo = params[1]
        opcode_hi = params[2]
        status = params[3]
        extra = params[4:] if len(params) > 4 else b""
        return HciCmdCompleteEvent(
            opcode_lo=opcode_lo, opcode_hi=opcode_hi, status=status, extra=extra
        )

    # ------------------------------------------------------------------
    # Vendor commands
    # ------------------------------------------------------------------

    def send_psm(self, psm_mode: int) -> HciCmdCompleteEvent:
        """Send the PSM vendor command and return the parsed Command Complete event.

        Args:
            psm_mode: One of PSM_NONE / PSM_DEEP / PSM_RETAIN /
                      PSM_HIBERNATE / PSM_SOC_OFF, or an arbitrary byte
                      value to test error handling.
        """
        self._send_cmd(PSM_OPCODE_LO, PSM_OPCODE_HI, bytes([psm_mode & 0xFF]))
        return self._recv_cmd_complete()
