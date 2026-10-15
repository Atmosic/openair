# Copyright (C) 2025-2026 Atmosic
# SPDX-License-Identifier: LicenseRef-Atmosic

"""
Pytest tests for Bluetooth Observer sample.

This test suite verifies that the observer can successfully scan for
and detect beacon advertisements.
"""

import logging
import re
import time

import pytest  # pylint: disable=import-error

from conftest import detect_beacon_bd_addr_from_handler_log
from twister_harness.exceptions import (  # pylint: disable=import-error
    TwisterHarnessTimeoutException,
)

logger = logging.getLogger(__name__)

PYTEST_TIMEOUT_GRACE_SECONDS = 5.0


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
    Parse [DEVICE] line to extract device information.

    Args:
        line: [DEVICE] line

    Returns:
        dict: Device information, or None if not a valid line
    """
    if "[DEVICE]:" not in line:
        return None

    result = {}

    # Extract BD address
    match = re.search(r"\[DEVICE\]:\s+([0-9A-Fa-f]{2}(?::[0-9A-Fa-f]{2}){5})", line)
    if match:
        result["bd_addr"] = match.group(1)

    # Extract AD evt type
    match = re.search(r"AD evt type (\d+)", line)
    if match:
        result["ad_evt_type"] = int(match.group(1))

    # Extract advertising data length
    match = re.search(r"AD data len: (\d+)", line)
    if match:
        result["data_len"] = int(match.group(1))

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


def _check_hci_payload_match(hci_line, scan_ctx, found, payload_type):
    """
    Check an HCI EVT line for a matching payload independently.

    Args:
        hci_line: HCI EVT line to parse
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

    payload_name = "Advertisement" if payload_type == "adv" else "Scan Response"
    logger.info("Found matching %s HCI payload from %s", payload_name, addr)
    return True


def _check_device_match(device_line, scan_ctx, found, payload_type):
    """Check a [DEVICE] line independently for a matching device record."""
    if found or not scan_ctx.get(f"{payload_type}_bytes"):
        return found

    device_info = _parse_device_line(device_line)
    if not device_info:
        return found

    expected_evt_type = 2 if payload_type == "adv" else 4
    expected_payload = scan_ctx[f"{payload_type}_bytes"]
    phy_pattern = scan_ctx.get(f"{payload_type}_phy")
    matches = (
        device_info.get("ad_evt_type") == expected_evt_type
        and _is_address_match(device_info.get("bd_addr"), scan_ctx.get("bd_addr"))
        and device_info.get("data_len") == expected_payload[0]
        and (not phy_pattern or device_info.get("phy_info") == phy_pattern)
    )
    if not matches:
        return found

    payload_name = "Advertisement" if payload_type == "adv" else "Scan Response"
    logger.info("Found matching %s [DEVICE] record", payload_name)
    return True


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


def _init_found_status(expected_adv_bytes, expected_rsp_bytes):
    """Initialize independent HCI and [DEVICE] match status."""
    return {
        "adv_hci": expected_adv_bytes is None,
        "adv_device": expected_adv_bytes is None,
        "rsp_hci": expected_rsp_bytes is None,
        "rsp_device": expected_rsp_bytes is None,
    }


def _process_scan_line(line, scan_ctx, found):
    """Process one HCI or [DEVICE] line without pairing unrelated records."""
    if "HCI EVT: 3e" in line:
        found["adv_hci"] = _check_hci_payload_match(
            line, scan_ctx, found["adv_hci"], "adv"
        )
        found["rsp_hci"] = _check_hci_payload_match(
            line, scan_ctx, found["rsp_hci"], "rsp"
        )
    elif "[DEVICE]:" in line:
        found["adv_device"] = _check_device_match(
            line, scan_ctx, found["adv_device"], "adv"
        )
        found["rsp_device"] = _check_device_match(
            line, scan_ctx, found["rsp_device"], "rsp"
        )


def _missing_matches(found):
    """Return the names of independent matches that are still missing."""
    return ", ".join(name for name, matched in found.items() if not matched)


def _get_timeout_seconds(base_timeout):
    """Convert the Twister timeout to a pytest timeout with a grace period."""
    try:
        timeout_seconds = float(base_timeout)
    except (TypeError, ValueError):
        pytest.fail(f"Invalid observer timeout: {base_timeout!r}", pytrace=False)
    timeout_seconds -= PYTEST_TIMEOUT_GRACE_SECONDS
    if timeout_seconds <= 0:
        pytest.fail(
            "Observer timeout must exceed the pytest timeout grace period",
            pytrace=False,
        )
    return timeout_seconds


def _wait_for_scan_results(dut, scan_ctx, found, timeout_seconds):
    """Read and process lines until all independent scan results are found."""
    deadline = time.monotonic() + timeout_seconds
    while not all(found.values()):
        remaining = deadline - time.monotonic()
        if remaining <= 0:
            missing = _missing_matches(found)
            logger.error(
                "Observer scan timed out after %.1f seconds; missing: %s",
                timeout_seconds,
                missing,
            )
            pytest.fail(
                f"Observer scan timed out; missing matches: {missing}",
                pytrace=False,
            )
        try:
            line = dut.readline(timeout=min(1.0, remaining))
        except (TwisterHarnessTimeoutException, TimeoutError):
            continue

        if line:
            _process_scan_line(line, scan_ctx, found)


def test_observer_match_payloads(
    dut, expected_payloads, twister_harness_config, base_timeout
):
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
    found = _init_found_status(expected_adv_bytes, expected_rsp_bytes)
    timeout_seconds = _get_timeout_seconds(base_timeout)

    _log_expected_payloads(
        adv_hex,
        rsp_hex,
        expected_payloads.get("adv_phy"),
        expected_payloads.get("rsp_phy"),
    )

    _wait_for_scan_results(dut, scan_ctx, found, timeout_seconds)
