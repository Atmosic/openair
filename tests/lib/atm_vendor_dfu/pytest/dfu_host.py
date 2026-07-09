# Copyright (c) 2026 Atmosic
#
# SPDX-License-Identifier: LicenseRef-Atmosic

"""Host-side framing helper for the atm_vendor_dfu pytest harness."""

from __future__ import annotations

import struct
import time

import serial

DEFAULT_BAUD_RATE = 115200
DEFAULT_RESPONSE_TIMEOUT_S = 5.0
DEFAULT_CHUNK_BYTES = 512

REQ_MAGIC = 0xA1B2C3D4
RESP_MAGIC = 0xD4C3B2A1
HDR_LEN = 9

CMD_PING = 0x01
CMD_RESET = 0x02
CMD_WRITE = 0x03
CMD_GO = 0x04


class DfuHostError(RuntimeError):
    """Raised when the device returns a non-zero status or framing fails."""


class DfuHost:
    """Minimal binary framing client for the atm_vendor_dfu test app."""

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
        """Open the configured serial port."""
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
        """Close the serial port if open."""
        if self._serial and self._serial.is_open:
            self._serial.close()

    def clear_input(self) -> None:
        """Discard any pending RX bytes."""
        if self._serial and self._serial.is_open:
            self._serial.reset_input_buffer()

    def request(self, cmd: int, payload: bytes = b"") -> bytes:
        """Send one framed request and return the response payload."""
        hdr = struct.pack("<IBI", REQ_MAGIC, cmd & 0xFF, len(payload))
        self._serial.write(hdr + payload)
        self._serial.flush()
        return self._read_response()

    def _read_response(self) -> bytes:
        raw = self._read_exact(HDR_LEN)
        magic, status, length = struct.unpack("<IBI", raw)
        if magic != RESP_MAGIC:
            raise DfuHostError(f"Bad response magic: 0x{magic:08x}")
        body = self._read_exact(length) if length else b""
        if status:
            raise DfuHostError(f"Device returned status {status}: {body!r}")
        return body

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

    # High-level helpers ------------------------------------------------

    def ping(self) -> str:
        """Read the running banner string."""
        return self.request(CMD_PING).decode("ascii", errors="replace")

    def reset_dfu(self) -> None:
        """Tell the device to reset its DFU streaming state."""
        self.request(CMD_RESET)

    def write_chunk(self, chunk: bytes) -> None:
        """Stream a single chunk of image data."""
        if len(chunk) > 4096:
            raise ValueError(f"Chunk too large: {len(chunk)} bytes")
        self.request(CMD_WRITE, chunk)

    def stream_image(self, image: bytes, chunk_size: int = DEFAULT_CHUNK_BYTES) -> None:
        """Stream an entire image in fixed-size chunks."""
        for offset in range(0, len(image), chunk_size):
            self.write_chunk(image[offset : offset + chunk_size])

    def request_go(self) -> None:
        """Trigger the upgrade request and reboot."""
        self.request(CMD_GO)
