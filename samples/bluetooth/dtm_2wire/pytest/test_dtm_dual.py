# Copyright (c) 2026 Atmosic
#
# SPDX-License-Identifier: LicenseRef-Atmosic

"""Two-device over-the-air tests for the Bluetooth DTM 2-wire sample.

WARNING — THIS TEST RADIATES REAL BLE PACKETS OVER THE AIR
===========================================================
Unlike ``test_dtm_single.py`` (which only configures parameters and never
issues TX_TEST), this test starts real DTM TX/RX transmissions.  It must run
only on a dedicated two-EVK rig (ideally cabled/RF-shielded), never on a shared
open-air bench.  It is gated behind the ``pytest_dual`` scenario and is skipped
unless a second device is supplied via ``--dtm-dev-b-serial``.

Topology (ported from atm_hl_tools tests/internal/dtm_tests/test_dtm_dual.py):
  device A (twister DUT, ``--dtm-serial``)      -> transmitter (TX)
  device B (partner EVK, ``--dtm-dev-b-serial``) -> receiver (RX)

The roles are selected with ``--dtm-device-a-role``. Device A defaults to RX
for compatibility with the original test implementation; device B is assigned
the opposite role.

Each configuration arms the RX device, transmits from the TX device for a fixed
window, ends both tests, reads the RX packet count and asserts it is non-zero —
i.e. the configured channel/PHY/payload actually produced on-air traffic.
"""

import logging
import re
import time

import pytest
from twister_harness import DeviceAdapter  # pylint: disable=import-error

from dtm_2wire_host import (
    DTM_MOD_INDEX_STABLE,
    DTM_MOD_INDEX_STD,
    DTM_MOD_LABELS,
    DtmTestConfig,
    DTM_PARAM_PHY_MODE_LE_1M,
    DTM_PARAM_PHY_MODE_LE_2M,
    DTM_PARAM_PHY_MODE_LE_S2,
    DTM_PARAM_PHY_MODE_LE_S8,
    DTM_PAYLOAD_10101010,
    DTM_PAYLOAD_11110000,
    DTM_PAYLOAD_11111111,
    DTM_PAYLOAD_LABELS,
    DTM_PAYLOAD_PRBS9,
    DTM_PHY_LABELS,
    DTM_RESP_TEST_FEAT_LE_2M_MSK,
    DTM_RESP_TEST_FEAT_LEN_EXT_MSK,
)

logger = logging.getLogger(__name__)

# Seconds to transmit per configuration before ending the test and reading the
# RX packet count (matches the 1000 ms tx window of the original tool).
TX_WINDOW_S = 1.0

# Console-less DUTs cannot provide a boot-ready marker. Allow enough time after
# flashing for their DTM UART to initialize before sending the first command.
CONSOLELESS_BOOT_SETTLE_S = 1.0

# A single DTM exchange occasionally reports zero packets on this hardware even
# on a good link (radio warm-up / transient), while a genuinely dead
# configuration returns zero on every attempt. WARM_UP_ATTEMPTS discards
# exchanges until the radio produces packets before the measured tests start;
# MAX_RUN_ATTEMPTS retries a measured configuration so a stray zero does not fail
# the suite.
WARM_UP_ATTEMPTS = 5
MAX_RUN_ATTEMPTS = 3

DEFAULT_CHANNEL = 37
LEGACY_MAX_DATA_LEN = 37
EXTENDED_MAX_DATA_LEN = 251
EXTENDED_FEATURE_MASK = DTM_RESP_TEST_FEAT_LEN_EXT_MSK | DTM_RESP_TEST_FEAT_LE_2M_MSK

# TLF3000 probes DTM support with RX_TEST 0x40 0x10 before TEST_SETUP RESET.
TLF3000_RX_TEST_CHANNEL = 0
TLF3000_RX_TEST_PARAM_BYTE = 0x10

ALL_PHYS = (
    DTM_PARAM_PHY_MODE_LE_1M,
    DTM_PARAM_PHY_MODE_LE_2M,
    DTM_PARAM_PHY_MODE_LE_S8,
    DTM_PARAM_PHY_MODE_LE_S2,
)
ALL_PAYLOADS = (
    DTM_PAYLOAD_PRBS9,
    DTM_PAYLOAD_11110000,
    DTM_PAYLOAD_10101010,
    DTM_PAYLOAD_11111111,
)
SWEEP_CHANNELS = (0, 20, 37, 38, 39)


class DtmDualRunner:
    """Drive a TX device and an RX device through a single TX/RX exchange."""

    def __init__(self, tx_host, rx_host, data_len_ext):
        self.tx = tx_host
        self.rx = rx_host
        self.data_len_ext = data_len_ext
        self.max_data_len = (
            EXTENDED_MAX_DATA_LEN if data_len_ext else LEGACY_MAX_DATA_LEN
        )

    @staticmethod
    def config_label(config: DtmTestConfig):
        """Render a one-line description of a TX/RX configuration."""
        return (
            f"Chan:{config.channel} ({2402 + 2 * config.channel} MHz) | "
            f"TXLen:{config.length} | Payld:{DTM_PAYLOAD_LABELS[config.payload]} | "
            f"Mod:{DTM_MOD_LABELS[config.mod]} | PHY:{DTM_PHY_LABELS[config.phy]}"
        )

    def _exchange(self, config: DtmTestConfig):
        """Run one TX/RX exchange and return the RX packet count (no assertion)."""
        # Arm the receiver first so it is ready before the transmitter starts.
        self.rx.rx_test_start(config)
        self.tx.tx_test_start(config, length_extension=self.data_len_ext)
        time.sleep(TX_WINDOW_S)
        self.tx.test_end()
        return self.rx.test_end()

    def warm_up(self):
        """Discard throwaway exchanges until the radio produces packets.

        Early DTM exchanges after boot occasionally return zero while the radio
        settles, and this can persist for more than one exchange. Keep trying
        (result ignored) until one succeeds so the measured tests start warm.
        """
        config = DtmTestConfig(
            channel=DEFAULT_CHANNEL,
            phy=DTM_PARAM_PHY_MODE_LE_1M,
            length=self.max_data_len,
            payload=DTM_PAYLOAD_PRBS9,
        )
        for attempt in range(1, WARM_UP_ATTEMPTS + 1):
            pkt_count = self._exchange(config)
            logger.info(
                "DTM warm-up %d/%d -> RX pkts: %d (ignored)",
                attempt,
                WARM_UP_ATTEMPTS,
                pkt_count,
            )
            if pkt_count > 0:
                return
        logger.warning("DTM warm-up saw no packets after %d attempts", WARM_UP_ATTEMPTS)

    def run(self, config: DtmTestConfig):
        """Run a TX/RX exchange and return the RX packet count (asserted > 0).

        Retries a transient zero (see MAX_RUN_ATTEMPTS); a genuinely dead
        configuration stays zero on every attempt and still fails.
        """
        label = self.config_label(config)
        pkt_count = 0
        for attempt in range(1, MAX_RUN_ATTEMPTS + 1):
            pkt_count = self._exchange(config)
            if pkt_count > 0:
                break
            logger.warning(
                "%s -> RX pkts: 0 (attempt %d/%d), retrying",
                label,
                attempt,
                MAX_RUN_ATTEMPTS,
            )
        logger.info("%s -> RX pkts: %d", label, pkt_count)
        assert pkt_count > 0, f"No packets received for config: {label}"
        return pkt_count


def _run_tlf3000_rx_preflight(host):
    """Verify device A accepts the TLF3000 RX probe before DTM reset."""
    host.rx_test_start_raw(TLF3000_RX_TEST_CHANNEL, TLF3000_RX_TEST_PARAM_BYTE)
    probe_pkt_count = host.test_end()
    assert (
        probe_pkt_count == 0
    ), f"TLF3000 RX preflight reported {probe_pkt_count} packets; expected 0"
    logger.info("TLF3000 RX preflight completed with 0 packets")


@pytest.fixture(scope="class")
def dtm_dual(
    dut: DeviceAdapter,
    dtm_host,
    dtm_host_b,
    dtm_tx_power,
    dtm_device_a_config,
):
    """Boot device A, prepare both raw UARTs and detect the negotiated capabilities.

    ``dtm_host`` is device A and ``dtm_host_b`` is device B. Their roles are
    selected by ``--dtm-device-a-role``. Length extension and 2M/Coded PHY
    sweeps are only exercised when both devices report support; otherwise the
    test falls back to legacy 1M coverage.
    """
    if not dtm_device_a_config.skip_ready:
        boot_lines = dut.readlines_until(
            regex=dtm_device_a_config.ready_regex, timeout=120
        )
        assert any(
            re.search(dtm_device_a_config.ready_regex, line) for line in boot_lines
        )
        time.sleep(0.1)
    else:
        time.sleep(CONSOLELESS_BOOT_SETTLE_S)

    dtm_host.clear_input()
    dtm_host_b.clear_input()

    # Match the TLF3000 probe before sending any setup/reset command to device A.
    # Luxor has no receiver and simulates this RX test, so TEST_END must report 0.
    _run_tlf3000_rx_preflight(dtm_host)

    if dtm_device_a_config.role == "tx":
        tx_host, rx_host = dtm_host, dtm_host_b
    else:
        tx_host, rx_host = dtm_host_b, dtm_host
    logger.info(
        "DTM roles: device A=%s, device B=%s",
        dtm_device_a_config.role.upper(),
        "RX" if dtm_device_a_config.role == "tx" else "TX",
    )

    # Reset both devices to a known state.
    for name, host in (("TX", tx_host), ("RX", rx_host)):
        event = host.reset()
        assert event.status == 0, f"{name} reset failed (status={event.status})"

    # Optional explicit transmitter power (default: leave the firmware default).
    if dtm_tx_power is not None:
        event = tx_host.set_tx_power(dtm_tx_power)
        assert (
            event.status == 0
        ), f"set TX power {dtm_tx_power} dBm failed (status={event.status})"
        logger.info("TX power set to %d dBm on the transmitter", dtm_tx_power)

    tx_feat = tx_host.read_test_features().response
    rx_feat = rx_host.read_test_features().response
    logger.info("DTM features: TX=0x%04x RX=0x%04x", tx_feat, rx_feat)

    # Match the original tool: if either side lacks length-extension + 2M, run
    # legacy-only coverage (1M PHY, <=37 byte packets, no length extension).
    data_len_ext = (
        tx_feat & EXTENDED_FEATURE_MASK == EXTENDED_FEATURE_MASK
        and rx_feat & EXTENDED_FEATURE_MASK == EXTENDED_FEATURE_MASK
    )
    if not data_len_ext:
        logger.info("One side lacks extended features; running legacy 1M coverage only")

    runner = DtmDualRunner(tx_host, rx_host, data_len_ext)
    # Absorb the unreliable first-exchange radio warm-up before the measured tests.
    runner.warm_up()
    return runner


class TestDtm2WireDual:
    """Two-device DTM TX/RX coverage (channels, PHYs, payloads, modulation)."""

    # pylint: disable=redefined-outer-name

    def _phys(self, dtm_dual):
        return ALL_PHYS if dtm_dual.data_len_ext else (DTM_PARAM_PHY_MODE_LE_1M,)

    def test_basic_tx_rx(self, dtm_dual):
        """Single TX/RX exchange on channel 37, 1M PHY, PRBS9 payload."""
        dtm_dual.run(
            DtmTestConfig(
                channel=DEFAULT_CHANNEL,
                phy=DTM_PARAM_PHY_MODE_LE_1M,
                length=dtm_dual.max_data_len,
                payload=DTM_PAYLOAD_PRBS9,
            )
        )

    def test_data_option_coverage(self, dtm_dual, dtm_expedite):
        """Sweep TX data lengths and payload types (channel 37, std modulation)."""
        lengths = [23, dtm_dual.max_data_len]
        if dtm_expedite:
            payloads = (DTM_PAYLOAD_PRBS9,)
            phys = (DTM_PARAM_PHY_MODE_LE_1M,)
        else:
            payloads = ALL_PAYLOADS
            phys = self._phys(dtm_dual)

        for length in lengths:
            for payload in payloads:
                for phy in phys:
                    dtm_dual.run(
                        DtmTestConfig(
                            channel=DEFAULT_CHANNEL,
                            phy=phy,
                            length=length,
                            payload=payload,
                        )
                    )

    def test_phy_option_coverage(self, dtm_dual, dtm_expedite):
        """Sweep PHYs and modulation indices (channel 37, max length, PRBS9)."""
        if dtm_expedite:
            phys = (DTM_PARAM_PHY_MODE_LE_1M,)
            if dtm_dual.data_len_ext:
                phys = (DTM_PARAM_PHY_MODE_LE_1M, DTM_PARAM_PHY_MODE_LE_2M)
            mods = (DTM_MOD_INDEX_STD,)
        else:
            phys = self._phys(dtm_dual)
            mods = (DTM_MOD_INDEX_STD, DTM_MOD_INDEX_STABLE)

        for phy in phys:
            for mod in mods:
                dtm_dual.run(
                    DtmTestConfig(
                        channel=DEFAULT_CHANNEL,
                        phy=phy,
                        length=dtm_dual.max_data_len,
                        payload=DTM_PAYLOAD_PRBS9,
                        mod=mod,
                    )
                )

    def test_channel_sweep_coverage(self, dtm_dual, dtm_expedite):
        """Sweep channels across PHYs (max length, PRBS9, std modulation)."""
        if dtm_expedite:
            channels = (37, 39)
            phys = (DTM_PARAM_PHY_MODE_LE_1M,)
        else:
            channels = SWEEP_CHANNELS
            phys = self._phys(dtm_dual)

        for phy in phys:
            for channel in channels:
                dtm_dual.run(
                    DtmTestConfig(
                        channel=channel,
                        phy=phy,
                        length=dtm_dual.max_data_len,
                        payload=DTM_PAYLOAD_PRBS9,
                    )
                )
