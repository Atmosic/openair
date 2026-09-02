# Copyright (c) 2026 Atmosic
#
# SPDX-License-Identifier: LicenseRef-Atmosic

"""Pytest smoke tests for the Bluetooth DTM 2-wire sample."""

import logging
import time

import pytest
from twister_harness import DeviceAdapter  # pylint: disable=import-error

from dtm_2wire_host import (
    DTM_CTRL_READ_PDU_SUPP,
    DTM_PARAM_PHY_MODE_LE_1M,
    DTM_PARAM_PHY_MODE_LE_2M,
    DTM_PDU_SUPPORT_OPT_MAXRXOCTETS,
    DTM_PDU_SUPPORT_OPT_MAXRXTIME,
    DTM_PDU_SUPPORT_OPT_MAXTXOCTETS,
    DTM_PDU_SUPPORT_OPT_MAXTXTIME,
    DTM_RESP_TEST_FEAT_LE_2M_MSK,
    DTM_RESP_TEST_FEAT_LE_CODED_MSK,
    DTM_RESP_TEST_FEAT_LEN_EXT_MSK,
)

logger = logging.getLogger(__name__)

BOOT_READY_REGEX = r"DTM 2-wire application started"
FEATURES_REQUIRED_MASK = (
    DTM_RESP_TEST_FEAT_LEN_EXT_MSK
    | DTM_RESP_TEST_FEAT_LE_2M_MSK
    | DTM_RESP_TEST_FEAT_LE_CODED_MSK
)
PDU_OCTET_OPTIONS = {DTM_PDU_SUPPORT_OPT_MAXTXOCTETS, DTM_PDU_SUPPORT_OPT_MAXRXOCTETS}
MAX_DTM_OCTETS = 251

# --- Boundary / invalid values used in negative tests ---
# A control code of 0x3F is not defined by the DTM spec and must be rejected.
DTM_CTRL_UNSUPPORTED = 0x3F
# PHY mode values outside the valid 0x01–0x04 range must be rejected.
# 0x05 and 0x3F are both above the maximum defined value (S2 Coded = 0x04).
DTM_PHY_MODE_ABOVE_MAX = 0x05
DTM_PHY_MODE_OUT_OF_RANGE = 0x3F
# PDU support option 0x3F is well beyond the defined range (0x00–0x03).
DTM_PDU_OPT_OUT_OF_RANGE = 0x3F


@pytest.fixture(scope="class")
def dtm_ready(dut: DeviceAdapter, dtm_host):
    """Wait for the sample to boot and prepare the raw DTM UART."""
    boot_lines = dut.readlines_until(regex=BOOT_READY_REGEX, timeout=120)
    assert any("DTM 2-wire application started" in line for line in boot_lines)

    time.sleep(0.1)
    dtm_host.clear_input()
    return {"boot_lines": boot_lines, "host": dtm_host}


class TestDtm2Wire:
    """Standard DTM 2-wire command coverage for a single device.

    NOTE FOR FUTURE MAINTAINERS — NO RF IS TRANSMITTED IN THESE TESTS
    ===================================================================
    Single EVKs operate in open-air environments.  Issuing a real
    DTM TX test would radiate BLE packets and may interfere with other
    devices in the area.  Tests that call ``set_phy_mode()`` or
    ``set_length_extension()`` only configure parameters on the device;
    they do NOT issue the TX_TEST start command, so no RF is generated.

    To validate actual on-air transmission, a cabled (RF-shielded)
    setup with two devices is required.  Add such tests to a dedicated
    ``pytest_dual_tx`` / ``pytest_dual_rx`` test entry in sample.yaml
    so they are not accidentally run on open-air rigs.
    """

    # pylint: disable=redefined-outer-name

    def test_boot_ready(self, dtm_ready):
        """Verify the sample prints the expected boot message."""
        assert any(
            "DTM 2-wire application started" in line for line in dtm_ready["boot_lines"]
        )

    def test_reset(self, dtm_ready):
        """Send DTM reset and verify the device acknowledges with status=0."""
        event = dtm_ready["host"].reset()
        logger.info(
            "DTM reset response: status=%d response=0x%04x",
            event.status,
            event.response,
        )
        assert not event.is_packet_report
        assert event.status == 0
        assert event.response == 0

    def test_read_test_features(self, dtm_ready):
        """Verify the device reports support for Length Extension, 2M PHY, and Coded PHY."""
        event = dtm_ready["host"].read_test_features()
        logger.info(
            "DTM feature response: status=%d response=0x%04x",
            event.status,
            event.response,
        )
        assert not event.is_packet_report
        assert event.status == 0
        assert event.response & FEATURES_REQUIRED_MASK == FEATURES_REQUIRED_MASK

    @pytest.mark.parametrize(
        ("option", "name"),
        [
            (DTM_PDU_SUPPORT_OPT_MAXTXOCTETS, "max_tx_octets"),
            (DTM_PDU_SUPPORT_OPT_MAXTXTIME, "max_tx_time"),
            (DTM_PDU_SUPPORT_OPT_MAXRXOCTETS, "max_rx_octets"),
            (DTM_PDU_SUPPORT_OPT_MAXRXTIME, "max_rx_time"),
        ],
    )
    def test_read_pdu_support(self, dtm_ready, option, name):
        """Verify each PDU support parameter returns a valid non-zero value."""
        event = dtm_ready["host"].read_pdu_support(option)
        logger.info(
            "DTM PDU support %s: status=%d response=%d",
            name,
            event.status,
            event.response,
        )
        assert not event.is_packet_report
        assert event.status == 0
        assert event.response > 0
        if option in PDU_OCTET_OPTIONS:
            assert event.response <= MAX_DTM_OCTETS

    # ------------------------------------------------------------------
    # Negative tests — error-path validation
    # ------------------------------------------------------------------

    def test_setup_unsupported_control_rejected(self, dtm_ready):
        """Device must reject a TEST_SETUP command with an undefined control code."""
        host = dtm_ready["host"]
        host.reset()
        event = host.send_test_setup(DTM_CTRL_UNSUPPORTED, 0x00)
        logger.info(
            "Unsupported control 0x%02x: status=%d response=0x%04x",
            DTM_CTRL_UNSUPPORTED,
            event.status,
            event.response,
        )
        assert not event.is_packet_report
        assert (
            event.status != 0
        ), "DUT must reject an unsupported TEST_SETUP control code"

    @pytest.mark.parametrize(
        ("phy", "label"),
        [
            (DTM_PHY_MODE_ABOVE_MAX, "above_max_0x05"),
            (DTM_PHY_MODE_OUT_OF_RANGE, "out_of_range_0x3F"),
        ],
    )
    def test_setup_invalid_phy_mode_rejected(self, dtm_ready, phy, label):
        """Device must reject PHY mode values above the valid maximum (0x04 = S2 Coded)."""
        host = dtm_ready["host"]
        host.reset()
        event = host.set_phy_mode(phy)
        logger.info("PHY mode %s (0x%02x): status=%d", label, phy, event.status)
        assert not event.is_packet_report
        assert (
            event.status != 0
        ), f"DUT must reject out-of-range PHY mode {label} (0x{phy:02x})"

    def test_setup_pdu_option_out_of_range_rejected(self, dtm_ready):
        """Device must reject a READ_PDU_SUPPORT option that is out of the defined range."""
        host = dtm_ready["host"]
        host.reset()
        event = host.send_test_setup(DTM_CTRL_READ_PDU_SUPP, DTM_PDU_OPT_OUT_OF_RANGE)
        logger.info(
            "Out-of-range PDU option 0x%02x: status=%d",
            DTM_PDU_OPT_OUT_OF_RANGE,
            event.status,
        )
        assert not event.is_packet_report
        assert event.status != 0, "DUT must reject out-of-range PDU support option"

    # ------------------------------------------------------------------
    # TX pre-flight setup tests — parameter configuration only, NO RF
    # ------------------------------------------------------------------

    @pytest.mark.parametrize(
        ("phy", "label"),
        [
            (DTM_PARAM_PHY_MODE_LE_1M, "LE_1M"),
            (DTM_PARAM_PHY_MODE_LE_2M, "LE_2M"),
        ],
    )
    def test_setup_tx_phy_mode_valid(self, dtm_ready, phy, label):
        """Valid PHY modes must be accepted (status=0).  No TX_TEST is issued; no RF."""
        host = dtm_ready["host"]
        host.reset()
        event = host.set_phy_mode(phy)
        logger.info("Set PHY mode %s (0x%02x): status=%d", label, phy, event.status)
        assert not event.is_packet_report
        assert event.status == 0, f"DUT must accept valid PHY mode {label}"

    def test_setup_tx_length_extension_valid(self, dtm_ready):
        """Length extension upper-bits setting must be accepted.  No TX_TEST is issued."""
        host = dtm_ready["host"]
        host.reset()
        # upper_bits=0 means standard lengths (<=63 bytes); accepted for any PHY.
        event = host.set_length_extension(0)
        logger.info("Set length extension bits=0: status=%d", event.status)
        assert not event.is_packet_report
        assert (
            event.status == 0
        ), "DUT must accept length extension setup with upper_bits=0"
        # upper_bits=3 enables the maximum packet-length extension.
        event = host.set_length_extension(3)
        logger.info("Set length extension bits=3: status=%d", event.status)
        assert not event.is_packet_report
        assert (
            event.status == 0
        ), "DUT must accept length extension setup with upper_bits=3"
