# Copyright (c) 2026 Atmosic
#
# SPDX-License-Identifier: LicenseRef-Atmosic

"""Host-side AT command + RDP framing helper for the at_cmd DFU pytest harness."""

from __future__ import annotations

import time

import serial

DEFAULT_BAUD_RATE = 115200
DEFAULT_RESPONSE_TIMEOUT_S = 5.0
# Maximum firmware bytes per RDP packet (256 - 3 byte header).
RDP_MAX_DATA_BYTES = 252

# RDP header op flags (bits [7:5] of the first byte).
RDP_FLAG_OP_CONT = 0x80
RDP_FLAG_OP_ACK = 0x40
RDP_FLAG_OP_END = 0x20

RDP_PACKET_START = 0x00
RDP_PACKET_CONT = 0x80
RDP_PACKET_END = 0x20
RDP_PACKET_CONT_END = 0xA0

RDP_ACK_LEN = 3
RDP_HDR_LEN = 3

AT_RESP_OK = "OK"
AT_RESP_ERROR = "ERROR"


class AtCmdDfuError(RuntimeError):
    """Raised when a device response indicates failure."""


class AtCmdDfuHost:
    """AT command + RDP binary framing client for the at_cmd DFU subsystem."""

    def __init__(
        self,
        port: str,
        baud: int = DEFAULT_BAUD_RATE,
        timeout: float = DEFAULT_RESPONSE_TIMEOUT_S,
    ):
        self.port = port
        self.baud = baud
        self.timeout = timeout
        self._serial: serial.Serial | None = None

    def open(self) -> None:
        """Open the serial port if not already open."""
        if self._serial and self._serial.is_open:
            return
        self._serial = serial.Serial(
            port=self.port,
            baudrate=self.baud,
            timeout=0.1,
            write_timeout=self.timeout,
            rtscts=False,
            dsrdtr=False,
            xonxoff=False,
        )

    def close(self) -> None:
        """Close the serial port."""
        if self._serial and self._serial.is_open:
            self._serial.close()

    def clear_input(self) -> None:
        """Flush any pending input bytes from the receive buffer."""
        if self._serial and self._serial.is_open:
            self._serial.reset_input_buffer()

    # ------------------------------------------------------------------
    # AT command helpers
    # ------------------------------------------------------------------

    def send_at_cmd(self, cmd: str) -> str:
        """Send an AT command and return the full response string.

        Reads lines until 'OK' or 'ERROR' is seen (or timeout).
        """
        line = f"AT+{cmd}\r\n"
        self._serial.write(line.encode("ascii"))
        self._serial.flush()
        return self._read_at_response()

    def _read_at_response(self) -> str:
        deadline = time.monotonic() + self.timeout
        lines: list[str] = []
        partial = b""

        while time.monotonic() < deadline:
            chunk = self._serial.read(64)
            if chunk:
                partial += chunk
                while b"\n" in partial:
                    line_b, partial = partial.split(b"\n", 1)
                    text = (
                        line_b.rstrip(b"\r").decode("ascii", errors="replace").strip()
                    )
                    if text:
                        lines.append(text)
                    if (
                        text == AT_RESP_OK
                        or text == AT_RESP_ERROR
                        or text.startswith("ERR:")
                    ):
                        return "\n".join(lines)

        raise TimeoutError(
            f"Timed out waiting for AT response on {self.port}; got: {lines}"
        )

    def _assert_ok(self, response: str, context: str) -> None:
        if not response.endswith(AT_RESP_OK):
            raise AtCmdDfuError(f"{context} failed: {response!r}")

    # ------------------------------------------------------------------
    # High-level DFU flow
    # ------------------------------------------------------------------

    def start_dfu(self, total_len: int, crc_en: bool = False) -> None:
        """Send AT+SYSDFU=0,<total_len>,<crc_en> and verify OK."""
        resp = self.send_at_cmd(f"SYSDFU=0,{total_len},{int(crc_en)}")
        self._assert_ok(resp, "AT+SYSDFU")

    def stream_image(self, image: bytes, chunk_size: int = RDP_MAX_DATA_BYTES) -> None:
        """Stream an entire firmware image using RDP framing."""
        total = len(image)
        sn = 0x00
        offset = 0

        while offset < total:
            chunk = image[offset : offset + chunk_size]
            remaining_after = total - offset - len(chunk)

            if not offset and not remaining_after:
                # Single packet: treat as END (no CONT needed).
                op = RDP_PACKET_END
            elif not offset:
                op = RDP_PACKET_START
            elif not remaining_after:
                op = RDP_PACKET_CONT_END
            else:
                op = RDP_PACKET_CONT

            self._send_rdp_packet(op, sn, chunk)
            sn = (sn + 1) & 0xFF
            offset += len(chunk)

    def _send_rdp_packet(self, op: int, sn: int, data: bytes) -> None:
        """Send one RDP packet and wait for the 3-byte ACK."""
        hdr = bytes([op, sn, len(data)])
        pkt = hdr + data
        self._serial.write(pkt)
        self._serial.flush()

        ack = self._read_exact(RDP_ACK_LEN)
        err = ack[2]
        if err:
            raise AtCmdDfuError(
                f"RDP ACK error 0x{err:02x} for SN=0x{sn:02x} op=0x{op:02x}"
            )

    def switch_bank(self) -> None:
        """Send AT+SYSSWITCHBANK= and verify OK (or tolerate reboot mid-response)."""
        try:
            resp = self.send_at_cmd("SYSSWITCHBANK=")
            self._assert_ok(resp, "AT+SYSSWITCHBANK")
        except (TimeoutError, serial.SerialException):
            # Device may reboot before the full response is transmitted.
            pass

    def mark_bank_good(self) -> None:
        """Send AT+SYSMKBANKGOOD= and verify OK."""
        resp = self.send_at_cmd("SYSMKBANKGOOD=")
        self._assert_ok(resp, "AT+SYSMKBANKGOOD")

    # ------------------------------------------------------------------
    # Internal utilities
    # ------------------------------------------------------------------

    def _read_exact(self, size: int) -> bytes:
        deadline = time.monotonic() + self.timeout
        data = bytearray()

        while len(data) < size and time.monotonic() < deadline:
            chunk = self._serial.read(size - len(data))
            if chunk:
                data.extend(chunk)

        if len(data) < size:
            raise TimeoutError(
                f"Timed out waiting for {size} bytes on {self.port} (got {len(data)})"
            )
        return bytes(data)
