# Copyright (C) 2025-2026 Atmosic
# SPDX-License-Identifier: LicenseRef-Atmosic

"""Pytest configuration and fixtures for Bluetooth Observer tests."""

import glob
import logging
import re
from pathlib import Path

import pytest

logger = logging.getLogger(__name__)


def pytest_addoption(parser):
    """Add local parser options to pytest."""
    parser.addoption(
        "--expected-adv",
        action="store",
        default=None,
        help="Expected advertisement payload hex string",
    )
    parser.addoption(
        "--expected-rsp",
        action="store",
        default=None,
        help="Expected scan response payload hex string",
    )
    parser.addoption(
        "--expected-adv-phy",
        action="store",
        default=None,
        help="Expected PHY pattern for advertisement (e.g., 'Pri PHY: LE 1M, Sec PHY: No packets')",
    )
    parser.addoption(
        "--expected-rsp-phy",
        action="store",
        default=None,
        help="Expected PHY pattern for scan response "
        "(e.g., 'Pri PHY: LE 1M, Sec PHY: No packets')",
    )


@pytest.fixture(scope="session")
def base_timeout(request):
    """Get the base timeout from Twister configuration."""
    return request.config.getoption("--base-timeout")


@pytest.fixture
def expected_payloads(request):
    """Fixture providing expected advertisement and scan response payloads."""
    adv = request.config.getoption("--expected-adv")
    rsp = request.config.getoption("--expected-rsp")
    adv_phy = request.config.getoption("--expected-adv-phy")
    rsp_phy = request.config.getoption("--expected-rsp-phy")
    return {"adv": adv, "rsp": rsp, "adv_phy": adv_phy, "rsp_phy": rsp_phy}


def _extract_bd_addr_from_log(handler_log_path):
    """
    Extract BD address from a handler.log file.

    Args:
        handler_log_path: Path to handler.log file

    Returns:
        str or None: BD address if found, None otherwise
    """
    bd_addr_pattern = re.compile(
        r"(?:I:\s*)?Identity:\s*([0-9A-Fa-f]{2}:[0-9A-Fa-f]{2}:[0-9A-Fa-f]{2}:"
        r"[0-9A-Fa-f]{2}:[0-9A-Fa-f]{2}:[0-9A-Fa-f]{2})"
    )

    try:
        with open(handler_log_path, "r", encoding="utf-8") as f:
            for line in f:
                match = bd_addr_pattern.search(line)
                if match:
                    return match.group(1)
    except (OSError, IOError, UnicodeDecodeError) as e:
        logger.warning("Failed to read %s: %s", handler_log_path, e)

    return None


def _detect_from_two_device_testing(twister_harness_config):
    """
    Try to detect BD address from two-device testing setup.

    Args:
        twister_harness_config: Twister harness configuration

    Returns:
        str or None: BD address if found, None otherwise
    """
    # Try to find beacon handler.log in the same twister-out directory
    build_dir = Path(twister_harness_config.build_dir)

    # Navigate up to find twister-out directory
    twister_out_dir = _find_twister_out_dir(build_dir)
    if not twister_out_dir:
        return None

    # Look for beacon sample handler.log
    beacon_handler_log = twister_out_dir / "handler.log"

    if not beacon_handler_log.exists():
        logger.info("Beacon handler.log not found at: %s", beacon_handler_log)
        return None

    bd_addr = _extract_bd_addr_from_log(beacon_handler_log)
    if bd_addr:
        logger.info("Auto-detected beacon BD address from handler.log: %s", bd_addr)

    return bd_addr


def _find_twister_out_dir(build_dir):
    """
    Navigate up from build_dir to find twister-out directory.

    Args:
        build_dir: Starting build directory path

    Returns:
        Path or None: twister-out directory if found, None otherwise
    """
    current = build_dir
    while current.parent != current:
        if current.name.startswith("twister-out"):
            return current
        current = current.parent
    return None


def _search_beacon_logs_in_workspace(twister_out_observer):
    """
    Search for beacon handler.log files in workspace.

    Args:
        twister_out_observer: Path to twister-out-observer directory

    Returns:
        str or None: BD address if found, None otherwise
    """
    logger.debug("Twister-out-observer directory: %s", twister_out_observer)

    # Navigate up to workspace root
    workspace_root = twister_out_observer.parent
    logger.debug("Workspace root: %s", workspace_root)

    # Look for beacon output directory
    beacon_out_pattern = workspace_root / "twister-out*"
    logger.debug("Looking for beacon output in: %s", beacon_out_pattern)

    # Find all twister-out directories
    twister_dirs = glob.glob(str(workspace_root / "twister-out*"))

    for twister_dir in twister_dirs:
        twister_path = Path(twister_dir)
        if not twister_path.exists():
            logger.debug("Beacon output directory not found: %s", twister_path)
            continue

        logger.debug("Beacon output directory exists: %s", twister_path)

        # Search for handler.log files
        logger.debug("Searching for handler.log files...")
        handler_logs = list(twister_path.rglob("handler.log"))
        logger.debug("Found %d handler.log file(s)", len(handler_logs))

        for handler_log in handler_logs:
            logger.info("Checking handler.log: %s", handler_log)
            bd_addr = _extract_bd_addr_from_log(handler_log)
            if bd_addr:
                logger.info(
                    "Auto-detected beacon BD address from %s: %s", handler_log, bd_addr
                )
                return bd_addr
            logger.debug("  No Identity line found in %s", handler_log)

    return None


def detect_beacon_bd_addr_from_handler_log(twister_harness_config):
    """
    Auto-detect beacon BD address from handler.log.

    This function should be called AFTER observer flash is complete,
    to ensure beacon has had enough time to initialize and write Identity line.

    Returns:
        str or None: BD address if found, None otherwise
    """
    # Get build_dir from first device in devices list
    if not twister_harness_config.devices:
        logger.warning("No devices in twister_harness_config")
        return None

    build_dir = Path(twister_harness_config.devices[0].build_dir)
    logger.debug("Observer build_dir: %s", build_dir)

    # Find twister-out directory
    twister_out_dir = _find_twister_out_dir(build_dir)
    if not twister_out_dir:
        logger.warning("Could not find twister-out directory in build path")
        return None

    # Search for beacon logs in workspace
    bd_addr = _search_beacon_logs_in_workspace(twister_out_dir)

    if not bd_addr:
        logger.info("No BD address auto-detected")

    return bd_addr
