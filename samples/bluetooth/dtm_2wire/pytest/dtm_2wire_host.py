# Copyright (c) 2026 Atmosic
#
# SPDX-License-Identifier: Apache-2.0

"""Minimal raw serial host helper for Bluetooth DTM 2-wire."""

from __future__ import annotations

from dataclasses import dataclass
import time

import serial

DEFAULT_BAUD_RATE = 115200
DEFAULT_RESPONSE_TIMEOUT_S = 0.5
DTM_MESSAGE_SIZE_BYTES = 2
DTM_MIN_TURNAROUND_S = 0.005

DTM_CMD_TEST_SETUP = 0x00
DTM_CMD_FIELD_SHIFT = 6
DTM_CTRL_RESET = 0x00
DTM_CTRL_SET_LEN_EXT = 0x01
DTM_CTRL_SET_PHY_MODE = 0x02
DTM_CTRL_READ_TEST_FEAT = 0x04
DTM_CTRL_READ_PDU_SUPP = 0x05
DTM_PARAM_FIELD_SHIFT = 2
DTM_PARAM_READ_TEST_FEAT_TEST_CASES = 0x00
DTM_RESP_TEST_FEAT_LEN_EXT_MSK = 0x0001
DTM_RESP_TEST_FEAT_LE_2M_MSK = 0x0002
DTM_RESP_TEST_FEAT_LE_CODED_MSK = 0x0008
DTM_PDU_SUPPORT_OPT_MAXTXOCTETS = 0x00
DTM_PDU_SUPPORT_OPT_MAXTXTIME = 0x01
DTM_PDU_SUPPORT_OPT_MAXRXOCTETS = 0x02
DTM_PDU_SUPPORT_OPT_MAXRXTIME = 0x03

DTM_PARAM_PHY_MODE_LE_1M = 0x01
DTM_PARAM_PHY_MODE_LE_2M = 0x02
DTM_PARAM_PHY_MODE_LE_S8 = 0x03
DTM_PARAM_PHY_MODE_LE_S2 = 0x04

DTM_EVT_TYPE_MASK = 0x80
DTM_EVT_STATUS_MASK = 0x01


@dataclass(frozen=True)
class DtmEvent:
    """Parsed DTM response event."""

    is_packet_report: bool
    status: int
    response: int


class Dtm2WireHost:
    """Minimal host-side helper for DTM 2-wire commands."""

    def __init__(
        self,
        port: str,
        baud: int = DEFAULT_BAUD_RATE,
        timeout: float = DEFAULT_RESPONSE_TIMEOUT_S,
    ):
        self.port = port
        self.baud = baud
        self.timeout = timeout
        self._serial = None

    def open(self):
        """Open the configured serial port."""
        if self._serial and self._serial.is_open:
            return

        self._serial = serial.Serial(
            port=self.port,
            baudrate=self.baud,
            timeout=0.05,
            write_timeout=self.timeout,
            rtscts=False,
            dsrdtr=False,
            xonxoff=False,
        )

    def close(self):
        """Close the serial port."""
        if self._serial and self._serial.is_open:
            self._serial.close()

    def clear_input(self):
        """Discard any pending bytes before sending DTM traffic."""
        if self._serial and self._serial.is_open:
            self._serial.reset_input_buffer()

    def request(self, cmd_byte: int, param_byte: int) -> DtmEvent:
        """Send one raw DTM command and parse the 2-byte event response."""
        payload = bytes((cmd_byte & 0xFF, param_byte & 0xFF))
        time.sleep(DTM_MIN_TURNAROUND_S)
        self._serial.write(payload)
        self._serial.flush()
        return self.parse_event(self._read_exact(DTM_MESSAGE_SIZE_BYTES))

    def send_test_setup(self, control: int, param: int) -> DtmEvent:
        """Send a standard DTM test setup command."""
        cmd_byte = (DTM_CMD_TEST_SETUP << DTM_CMD_FIELD_SHIFT) | (control & 0x3F)
        param_byte = (param & 0x3F) << DTM_PARAM_FIELD_SHIFT
        return self.request(cmd_byte, param_byte)

    def reset(self) -> DtmEvent:
        """Send the DTM reset command."""
        return self.send_test_setup(DTM_CTRL_RESET, 0)

    def read_test_features(self) -> DtmEvent:
        """Read supported DTM test features."""
        return self.send_test_setup(
            DTM_CTRL_READ_TEST_FEAT, DTM_PARAM_READ_TEST_FEAT_TEST_CASES
        )

    def read_pdu_support(self, option: int) -> DtmEvent:
        """Read one supported PDU parameter."""
        return self.send_test_setup(DTM_CTRL_READ_PDU_SUPP, option)

    def set_phy_mode(self, phy: int) -> DtmEvent:
        """Configure the DTM PHY mode without starting a test.

        Valid values are DTM_PARAM_PHY_MODE_LE_1M (0x01), LE_2M (0x02),
        LE_S8 (0x03), and LE_S2 (0x04).  Any other value should be
        rejected by the device with a non-zero status.
        """
        return self.send_test_setup(DTM_CTRL_SET_PHY_MODE, phy)

    def set_length_extension(self, upper_bits: int) -> DtmEvent:
        """Configure the upper 2 bits of the TX packet length extension.

        ``upper_bits`` is bits [7:6] of the full packet length field
        (valid range 0–3).  Setting this before a TX test allows packets
        longer than 63 bytes.  No RF is transmitted by this command.
        """
        return self.send_test_setup(DTM_CTRL_SET_LEN_EXT, upper_bits & 0x03)

    def _read_exact(self, size: int) -> bytes:
        deadline = time.monotonic() + self.timeout
        data = bytearray()

        while len(data) < size and time.monotonic() < deadline:
            chunk = self._serial.read(size - len(data))
            if chunk:
                data.extend(chunk)

        if len(data) < size:
            raise TimeoutError(f"Timed out waiting for {size} DTM bytes on {self.port}")

        return bytes(data)

    @staticmethod
    def parse_event(data: bytes) -> DtmEvent:
        """Parse a raw 2-byte DTM event."""
        if len(data) != DTM_MESSAGE_SIZE_BYTES:
            raise ValueError(
                f"Expected {DTM_MESSAGE_SIZE_BYTES} bytes, got {len(data)}"
            )

        first, second = data
        if first & DTM_EVT_TYPE_MASK:
            response = ((first & ~DTM_EVT_TYPE_MASK) << 8) | second
            return DtmEvent(is_packet_report=True, status=0, response=response)

        status = second & DTM_EVT_STATUS_MASK
        response = (((first & ~DTM_EVT_TYPE_MASK) << 8) | second) >> 1
        return DtmEvent(is_packet_report=False, status=status, response=response)
