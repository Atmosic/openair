# Copyright (c) 2026 Atmosic
#
# SPDX-License-Identifier: LicenseRef-Atmosic

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
DTM_CMD_RX_TEST = 0x01
DTM_CMD_TX_TEST = 0x02
DTM_CMD_TEST_END = 0x03
DTM_CMD_FIELD_SHIFT = 6
DTM_CTRL_RESET = 0x00
DTM_CTRL_SET_LEN_EXT = 0x01
DTM_CTRL_SET_PHY_MODE = 0x02
DTM_CTRL_SET_RECV_MOD = 0x03
DTM_CTRL_READ_TEST_FEAT = 0x04
DTM_CTRL_READ_PDU_SUPP = 0x05
DTM_CTRL_SET_TX_PWR = 0x09
# Sentinels for the TX power parameter (carried raw in the low byte).
DTM_TX_PWR_MAX_SET = 0x7F
DTM_TX_PWR_MIN_SET = 0x7E
DTM_PARAM_FIELD_SHIFT = 2
DTM_PARAM_READ_TEST_FEAT_TEST_CASES = 0x00
DTM_RESP_TEST_FEAT_LEN_EXT_MSK = 0x0001
DTM_RESP_TEST_FEAT_LE_2M_MSK = 0x0002
DTM_RESP_TEST_FEAT_TX_STABLE_MOD_MSK = 0x0004
DTM_RESP_TEST_FEAT_LE_CODED_MSK = 0x0008
DTM_PDU_SUPPORT_OPT_MAXTXOCTETS = 0x00
DTM_PDU_SUPPORT_OPT_MAXTXTIME = 0x01
DTM_PDU_SUPPORT_OPT_MAXRXOCTETS = 0x02
DTM_PDU_SUPPORT_OPT_MAXRXTIME = 0x03

DTM_PARAM_PHY_MODE_LE_1M = 0x01
DTM_PARAM_PHY_MODE_LE_2M = 0x02
DTM_PARAM_PHY_MODE_LE_S8 = 0x03
DTM_PARAM_PHY_MODE_LE_S2 = 0x04

# TX payload packet types (TEST_SETUP length field carries the lower 6 length bits;
# the payload type occupies the low 2 bits of the same parameter byte).
DTM_PAYLOAD_PRBS9 = 0x00
DTM_PAYLOAD_11110000 = 0x01
DTM_PAYLOAD_10101010 = 0x02
DTM_PAYLOAD_11111111 = 0x03

# Receiver/transmitter modulation index options.
DTM_MOD_INDEX_STD = 0x00
DTM_MOD_INDEX_STABLE = 0x01

# Human-readable labels for log output (mirrors the atm_hl_tools dtm_api dicts).
DTM_PAYLOAD_LABELS = {
    DTM_PAYLOAD_PRBS9: "PRBS9",
    DTM_PAYLOAD_11110000: "11110000",
    DTM_PAYLOAD_10101010: "10101010",
    DTM_PAYLOAD_11111111: "11111111",
}
DTM_PHY_LABELS = {
    DTM_PARAM_PHY_MODE_LE_1M: "1M",
    DTM_PARAM_PHY_MODE_LE_2M: "2M",
    DTM_PARAM_PHY_MODE_LE_S8: "CODED_S8",
    DTM_PARAM_PHY_MODE_LE_S2: "CODED_S2",
}
DTM_MOD_LABELS = {
    DTM_MOD_INDEX_STD: "Std Mod",
    DTM_MOD_INDEX_STABLE: "Stable Mod",
}

DTM_EVT_TYPE_MASK = 0x80
DTM_EVT_STATUS_MASK = 0x01


class DtmError(Exception):
    """Raised when the DUT rejects a DTM command or returns an unexpected event."""


@dataclass(frozen=True)
class DtmEvent:
    """Parsed DTM response event."""

    is_packet_report: bool
    status: int
    response: int


@dataclass(frozen=True)
class DtmTestConfig:
    """A single DTM TX/RX test point (channel, PHY, length, payload, modulation)."""

    channel: int
    phy: int
    length: int
    payload: int = DTM_PAYLOAD_PRBS9
    mod: int = DTM_MOD_INDEX_STD


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

    def set_recv_modulation(self, mod: int) -> DtmEvent:
        """Select the receiver/transmitter modulation index (Std or Stable)."""
        return self.send_test_setup(DTM_CTRL_SET_RECV_MOD, mod)

    def set_tx_power(self, dbm: int) -> DtmEvent:
        """Set the DTM transmitter power level in dBm.

        Unlike the other TEST_SETUP parameters (which sit in a shifted 6-bit
        field), the firmware reads TX power as a signed 8-bit value taken
        straight from the low byte (DTM_PARAM_GET_TX_PWR_LVL = (int8_t)d).  It
        is therefore sent raw rather than via send_test_setup().  The special
        values DTM_TX_PWR_MAX_SET / DTM_TX_PWR_MIN_SET request the maximum /
        minimum supported power.
        """
        cmd_byte = (DTM_CMD_TEST_SETUP << DTM_CMD_FIELD_SHIFT) | DTM_CTRL_SET_TX_PWR
        return self.request(cmd_byte, dbm & 0xFF)

    def set_test_params(self, phy: int, modulation: int = None, length: int = None):
        """Configure PHY mode and, optionally, modulation and length-extension bits.

        ``length`` is the full TX packet length; only its upper 2 bits are
        programmed here (the lower 6 bits travel in the TX_TEST parameter byte).
        Raises ``DtmError`` if the device rejects any setup command.
        """
        self._expect_ok(self.set_phy_mode(phy), "set PHY mode")
        if modulation is not None:
            self._expect_ok(
                self.set_recv_modulation(modulation), "set receiver modulation"
            )
        if length is not None:
            self._expect_ok(
                self.set_length_extension(length >> 6), "set length extension"
            )

    def rx_test_start(self, config: "DtmTestConfig") -> None:
        """Configure and start an RX test on ``config.channel`` (no payload/length)."""
        self.set_test_params(config.phy, modulation=config.mod, length=0)
        cmd_byte = (DTM_CMD_RX_TEST << DTM_CMD_FIELD_SHIFT) | (config.channel & 0x3F)
        self._expect_ok(self.request(cmd_byte, 0x00), "start RX test")

    def rx_test_start_raw(self, channel: int, param_byte: int) -> None:
        """Start RX without setup, as testers can do before issuing DTM reset."""
        cmd_byte = (DTM_CMD_RX_TEST << DTM_CMD_FIELD_SHIFT) | (channel & 0x3F)
        self._expect_ok(self.request(cmd_byte, param_byte), "start raw RX test")

    def tx_test_start(
        self, config: "DtmTestConfig", length_extension: bool = True
    ) -> None:
        """Configure and start a TX test transmitting ``config.payload``."""
        self.set_test_params(
            config.phy, length=config.length if length_extension else None
        )
        cmd_byte = (DTM_CMD_TX_TEST << DTM_CMD_FIELD_SHIFT) | (config.channel & 0x3F)
        param_byte = ((config.length & 0x3F) << DTM_PARAM_FIELD_SHIFT) | (
            config.payload & 0x03
        )
        self._expect_ok(self.request(cmd_byte, param_byte), "start TX test")

    def test_end(self) -> int:
        """End the running test and return the received packet count.

        Per the DTM spec a TEST_END returns a packet-report event carrying the
        number of received packets (0 for a transmitter).  A plain status event
        is tolerated (treated as 0 packets) as long as it reports success.
        """
        cmd_byte = DTM_CMD_TEST_END << DTM_CMD_FIELD_SHIFT
        event = self.request(cmd_byte, 0x00)
        if event.is_packet_report:
            return event.response
        if event.status != 0:
            raise DtmError(f"TEST_END failed (status={event.status})")
        return 0

    @staticmethod
    def _expect_ok(event: DtmEvent, what: str) -> None:
        if event.is_packet_report or event.status != 0:
            raise DtmError(f"DTM command failed: {what} (status={event.status})")

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
