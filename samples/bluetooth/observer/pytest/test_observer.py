# Copyright (C) 2025-2026 Atmosic
# SPDX-License-Identifier: LicenseRef-Atmosic

"""
Pytest tests for Bluetooth Observer sample.

This test suite verifies that the observer can successfully scan for
and detect beacon advertisements.
"""

import logging
import re

import pytest  # pylint: disable=import-error

from conftest import detect_beacon_bd_addr_from_handler_log
from twister_harness.exceptions import (  # pylint: disable=import-error
    TwisterHarnessTimeoutException,
)

logger = logging.getLogger(__name__)


def _hex_str_to_bytes(hex_str):
    """
    Convert hex string to bytes.

    The hex string includes a length byte as the first byte (for scan response).
    The length byte indicates the length of the remaining payload bytes.

    Args:
        hex_str: Hex string (e.g., "0c 09 54 65 73 74" where 0c is the length)

    Returns:
        bytes: The complete payload bytes including the length byte
    """
    if not hex_str:
        return None
    try:
        full_bytes = bytes.fromhex(hex_str.replace(" ", ""))
        if len(full_bytes) < 1:
            return None
        return full_bytes
    except ValueError:
        logger.warning("Invalid expected hex string: %s", hex_str)
        return None


def _parse_hci_evt_line(line):
    """
    Parse HCI EVT line to extract BDADDR and payload data.

    Args:
        line: HCI EVT line (e.g., "HCI EVT: 3e 39 0d 01 12 00 00 a1 00 a1 6b 69 7c ...")

    Returns:
        tuple: (addr, data, evt_type) where addr is the device address,
               data is the payload bytes including data_len byte as first byte,
               and evt_type is the LE event type,
               or (None, None, None) if not a valid HCI EVT line
    """
    if "HCI EVT: 3e" not in line:
        return None, None, None

    # Extract hex data from HCI EVT line
    match = re.search(r"HCI EVT:\s+((?:[0-9a-fA-F]{2}\s*)+)", line)
    if not match:
        return None, None, None

    hex_data_str = match.group(1)
    try:
        evt_data = bytes.fromhex(hex_data_str.replace(" ", ""))
    except ValueError:
        logger.warning("Failed to convert HCI EVT hex data: %s", hex_data_str)
        return None, None, None

    # HCI LE Meta Event structure for advertising report (0x3e 0x0d)
    # Byte 0: 0x3e (HCI LE Meta Event)
    # Byte 1: parameter length
    # Byte 2: subevent code (0x0d for LE Advertising Report)
    # Byte 3: number of reports
    # Byte 4: event type
    # Bytes 5-6: unknown/reserved
    # Bytes 7-12: address (little-endian, 6 bytes)
    # Byte 13: address type
    # Byte 14: data status
    # Byte 15: RSSI
    # Byte 16: TX Power
    # Bytes 17-26: other info (10 bytes)
    # Byte 27: data length
    # Bytes 28+: advertising data

    if len(evt_data) < 28:
        return None, None, None

    # Extract AD event type from byte 4 (lower 2 bits)
    # 0x00 = ADV_IND (type 0), 0x01 = ADV_DIRECT_IND (type 1),
    # 0x02 = ADV_SCAN_IND (type 2), 0x03 = ADV_NONCONN_IND (type 3)
    # But the actual mapping is: 0 = ADV_IND, 1 = ADV_DIRECT_IND,
    # 2 = ADV_SCAN_IND, 3 = ADV_NONCONN_IND, 4 = SCAN_RSP
    # The byte 4 contains: bits 0-1 = event type, bits 2-7 = other info
    evt_type = evt_data[4] & 0x0F  # Extract lower 4 bits for event type
    # Extract address (little-endian, 6 bytes)
    addr_bytes = evt_data[7:13]
    addr = ":".join(f"{b:02X}" for b in reversed(addr_bytes))

    # Extract advertising data with data_len byte as first byte
    data_len = evt_data[27]
    if len(evt_data) < 28 + data_len:
        return None, None, None

    # Include data_len byte as first byte of payload for consistency
    payload = bytes([data_len]) + evt_data[28 : 28 + data_len]
    return addr, payload, evt_type


def _parse_device_line(line):
    """
    Parse [DEVICE] line to extract AD evt type and PHY information.

    Args:
        line: [DEVICE] line

    Returns:
        dict: Dictionary with 'ad_evt_type' and 'phy_info', or None if not a valid line
    """
    if "[DEVICE]:" not in line:
        return None

    result = {}

    # Extract AD evt type
    match = re.search(r"AD evt type (\d+)", line)
    if match:
        result["ad_evt_type"] = int(match.group(1))

    # Extract PHY information
    match = re.search(r"Pri PHY: ([^,]+), Sec PHY: ([^,]+)", line)
    if match:
        result["phy_info"] = f"Pri PHY: {match.group(1)}, Sec PHY: {match.group(2)}"

    return result if result else None


def _normalize_bd_addr(addr):
    """Normalize BD address to comparable format.

    Handles two formats:
    - With colons (big-endian): 7C:69:6B:00:00:75 -> 7c696b000075
    - Without colons (little-endian from observer): 7500006b697c -> reverse bytes
    """
    if not addr:
        return None
    addr_lower = addr.lower()
    if ":" in addr_lower:
        return addr_lower.replace(":", "")
    pairs = [addr_lower[i : i + 2] for i in range(0, len(addr_lower), 2)]
    return "".join(reversed(pairs))


def _is_address_match(addr, expected_bd_addr):
    """Check if scanned address matches expected address."""
    if not expected_bd_addr:
        return True
    return _normalize_bd_addr(addr) == _normalize_bd_addr(expected_bd_addr)


def _check_payload_match(hci_line, device_line, scan_ctx, found, payload_type):
    """
    Check if HCI EVT line contains matching payload (ADV or RSP).

    Args:
        hci_line: HCI EVT line to parse
        device_line: [DEVICE] line for additional validation
        scan_ctx: Scan context containing expected payloads and PHY info
        found: Current found status
        payload_type: Type of payload ('adv' or 'rsp')

    Returns:
        bool: True if matching payload found, otherwise current found status
    """
    # Early return if already found or no expected payload
    payload_key = f"{payload_type}_bytes"
    if found or not scan_ctx.get(payload_key):
        return found

    # Parse and validate HCI EVT line
    addr, data, _ = _parse_hci_evt_line(hci_line)
    payload_matches = (
        data
        and _is_address_match(addr, scan_ctx.get("bd_addr"))
        and data == scan_ctx.get(payload_key)
    )

    if not payload_matches:
        return found

    # Check AD evt type from [DEVICE] line
    expected_evt_type = 2 if payload_type == "adv" else 4  # 2=ADV_IND, 4=SCAN_RSP
    if device_line:
        device_info = _parse_device_line(device_line)
        if device_info and device_info.get("ad_evt_type") != expected_evt_type:
            return found

    # Payload matched successfully
    payload_name = "Advertisement" if payload_type == "adv" else "Scan Response"
    logger.info("Found matching %s payload from %s", payload_name, addr)

    # Check PHY pattern if specified
    phy_key = f"{payload_type}_phy"
    phy_pattern = scan_ctx.get(phy_key)
    if not phy_pattern:
        return True

    # Verify PHY matches if specified
    if device_line:
        device_info = _parse_device_line(device_line)
        if device_info and device_info.get("phy_info") == phy_pattern:
            logger.info("Found matching %s with PHY: %s", payload_name, phy_pattern)
            return True

    return found


def _check_adv_match(hci_line, device_line, scan_ctx, found_adv):
    """Check if HCI EVT line contains matching advertisement payload."""
    return _check_payload_match(hci_line, device_line, scan_ctx, found_adv, "adv")


def _check_rsp_match(hci_line, device_line, scan_ctx, found_rsp):
    """Check if HCI EVT line contains matching scan response payload."""
    return _check_payload_match(hci_line, device_line, scan_ctx, found_rsp, "rsp")


def _log_expected_payloads(adv_hex, rsp_hex, adv_phy, rsp_phy):
    """Log expected payload information."""
    if adv_hex:
        logger.info("Expected ADV payload: %s", adv_hex)
    if rsp_hex:
        logger.info("Expected RSP payload: %s", rsp_hex)
    if adv_phy:
        logger.info("Expected ADV PHY: %s", adv_phy)
    if rsp_phy:
        logger.info("Expected RSP PHY: %s", rsp_phy)
    logger.info("Starting scan for expected payloads...")


def _init_scan_context(expected_payloads, expected_bd_addr):
    """Initialize scan context from expected payloads and beacon address."""
    adv_hex = expected_payloads.get("adv")
    rsp_hex = expected_payloads.get("rsp")
    adv_phy = expected_payloads.get("adv_phy")
    rsp_phy = expected_payloads.get("rsp_phy")

    expected_adv_bytes = _hex_str_to_bytes(adv_hex)
    expected_rsp_bytes = _hex_str_to_bytes(rsp_hex)

    return (
        {
            "bd_addr": expected_bd_addr,
            "adv_bytes": expected_adv_bytes,
            "rsp_bytes": expected_rsp_bytes,
            "adv_phy": adv_phy,
            "rsp_phy": rsp_phy,
            "adv_hex": adv_hex,
            "rsp_hex": rsp_hex,
        },
        expected_adv_bytes,
        expected_rsp_bytes,
    )


def _process_hex_scan_lines(hci_line, device_line, scan_ctx, found_adv, found_rsp):
    """Process HCI EVT and [DEVICE] lines and check for payload matches."""
    if "HCI EVT: 3e" not in hci_line:
        return found_adv, found_rsp

    found_adv = _check_adv_match(hci_line, device_line, scan_ctx, found_adv)
    found_rsp = _check_rsp_match(hci_line, device_line, scan_ctx, found_rsp)
    return found_adv, found_rsp


def test_observer_match_payloads(dut, expected_payloads, twister_harness_config):
    """
    Test that the observer detects specific Advertisement and Scan Response payloads.

    This test verifies that:
    1. The payload content matches the expected hex string
    2. The payload comes from the correct BDADDR (detected from handler.log)
    3. The AD evt type is correct (2 for ADV, 4 for SCAN_RSP)
    4. The PHY information matches (if specified)
    """
    adv_hex = expected_payloads.get("adv")
    rsp_hex = expected_payloads.get("rsp")

    if not adv_hex and not rsp_hex:
        pytest.skip("No expected payloads provided via command line")

    # Detect expected beacon address from other device's logs
    expected_bd_addr = detect_beacon_bd_addr_from_handler_log(twister_harness_config)
    if not expected_bd_addr:
        pytest.fail("Failed to detect beacon BD address from handler.log")
    logger.info("Expecting beacon address: %s", expected_bd_addr)

    # Initialize scan context
    scan_ctx, expected_adv_bytes, expected_rsp_bytes = _init_scan_context(
        expected_payloads, expected_bd_addr
    )

    # If a type is not expected (None), consider it found
    found_adv = expected_adv_bytes is None
    found_rsp = expected_rsp_bytes is None

    _log_expected_payloads(
        adv_hex,
        rsp_hex,
        expected_payloads.get("adv_phy"),
        expected_payloads.get("rsp_phy"),
    )

    hci_lines = []  # Queue to store HCI EVT lines

    while True:
        try:
            line = dut.readline(timeout=1.0)
        except (TwisterHarnessTimeoutException, TimeoutError):
            continue

        if not line:
            continue

        # Track HCI EVT and [DEVICE] lines
        if "HCI EVT: 3e" in line:
            hci_lines.append(line)
        elif "[DEVICE]:" in line:
            # Process the pair of HCI EVT and [DEVICE] lines
            # Match with the first HCI EVT in the queue
            if hci_lines:
                hci_line = hci_lines.pop(0)
                found_adv, found_rsp = _process_hex_scan_lines(
                    hci_line, line, scan_ctx, found_adv, found_rsp
                )

        if found_adv and found_rsp:
            break

    assert (
        found_adv or not expected_adv_bytes
    ), f"Failed to find Advertisement payload: {adv_hex}"
    assert (
        found_rsp or not expected_rsp_bytes
    ), f"Failed to find Scan Response payload: {rsp_hex}"
