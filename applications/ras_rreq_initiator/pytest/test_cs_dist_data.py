#!/usr/bin/env python3
"""
@file pytest/test_cs_dist_data.py

@brief Pytest integration test for CS distance measurements

This test integrates with Twister harness by executing the CS distance test
and checking its return code. All validation logic is in the test_cs_dist.py script.

Copyright (C) Atmosic 2025-2026

SPDX-License-Identifier: LicenseRef-Atmosic
"""
import glob
import logging
import os
import shutil
import subprocess
from pathlib import Path

import pytest

from twister_harness import DeviceAdapter  # pylint: disable=import-error

logger = logging.getLogger(__name__)
logger.setLevel(logging.DEBUG)

# Path to the CS distance test script
CS_DIST_TEST_SCRIPT_RELATIVE_PATH = (
    "sw-eng/tools/atmosic/atm_cs_dist_tools/tests/test_cs_dist.py"
)


class TestCsDistData:
    """Integration tests for CS distance measurements"""

    def _copy_cs_rreq_data_to_log_dir(self, log_dir: Path) -> None:
        """
        Move cs_rreq_data.txt from current working directory to the log directory
        and rename it to cs_rreq_data.log.

        This file contains the CS distance measurement data and should be stored
        alongside twister_harness.log for easy access.

        Args:
            log_dir: Path to the directory where twister_harness.log is located
        """
        source_filename = "cs_rreq_data.txt"
        dest_filename = "cs_rreq_data.log"

        source_path = Path.cwd() / source_filename
        dest_path = log_dir / dest_filename

        logger.info(
            "Attempting to move and rename %s to %s...", source_filename, dest_filename
        )
        logger.debug("  Source: %s", source_path)
        logger.debug("  Destination: %s", dest_path)

        if source_path.exists():
            try:
                shutil.move(str(source_path), str(dest_path))
                logger.info("✓ Successfully moved %s to %s", source_filename, dest_path)
            except (OSError, shutil.Error) as e:
                logger.warning(
                    "✗ Failed to move %s: %s: %s", source_filename, type(e).__name__, e
                )
        else:
            logger.debug("✗ %s not found at %s", source_filename, source_path)

    def _flash_and_prepare_device(self, unlaunched_dut: DeviceAdapter) -> None:
        """Flash device and disconnect from serial port."""
        logger.info("Flashing device...")
        unlaunched_dut.launch()
        logger.info("✓ Device flashed successfully")

        logger.info("Disconnecting from serial port (subprocess will connect)...")
        unlaunched_dut.disconnect()
        logger.info("✓ Serial port disconnected")

    def _log_device_config(
        self, unlaunched_dut: DeviceAdapter, cs_dist_script: str
    ) -> tuple:
        """Log device configuration and return device parameters."""
        # Zephyr 4.4 moved per-UART serial config into device_config.serial_configs[].
        serial_configs = getattr(unlaunched_dut.device_config, "serial_configs", None)
        primary = serial_configs[0] if serial_configs else None
        port = primary.port if primary else None
        baud = primary.baud if primary else None

        logger.info("Device configuration from unlaunched_dut fixture:")
        logger.info("  Port: %s", port)
        logger.info("  Baud rate: %s", baud)
        logger.info("  Device ID: %s", unlaunched_dut.device_config.id)
        logger.info("  Platform: %s", unlaunched_dut.device_config.platform)
        logger.info("  Script: %s", cs_dist_script)

        return port, baud

    def _verify_device_and_script(self, port: str, cs_dist_script: str) -> None:
        """Verify that serial device and script exist."""
        if os.path.exists(port):
            logger.info("✓ Serial device exists: %s", port)
        else:
            logger.warning("✗ Serial device NOT found: %s", port)
            logger.warning("  Available /dev/tty* devices:")
            tty_devices = glob.glob("/dev/tty*")
            for dev in sorted(tty_devices)[:10]:  # Show first 10
                logger.warning("    - %s", dev)

        if os.path.exists(cs_dist_script):
            logger.info("✓ Script exists: %s", cs_dist_script)
        else:
            logger.error("✗ Script NOT found: %s", cs_dist_script)

    def _run_cs_dist_subprocess(self, cmd: list) -> subprocess.CompletedProcess:
        """Execute the CS distance test subprocess."""
        logger.info("Starting subprocess...")
        try:
            result = subprocess.run(
                cmd, capture_output=True, text=True, timeout=300, check=False
            )

            logger.info("Subprocess completed with return code: %d", result.returncode)
            logger.info("STDOUT length: %d bytes", len(result.stdout))
            logger.info("STDERR length: %d bytes", len(result.stderr))

            if result.stderr:
                logger.warning("STDERR output:")
                for line in result.stderr.split("\n"):
                    if line.strip():
                        logger.warning("  %s", line)

            return result

        except subprocess.TimeoutExpired as e:
            logger.error("✗ Subprocess TIMEOUT after %s seconds", e.timeout)
            logger.error("  stdout so far: %s", e.stdout)
            logger.error("  stderr so far: %s", e.stderr)
            # Return a CompletedProcess with timeout return code instead of raising
            # This allows the test to continue and log/copy data before failing
            return subprocess.CompletedProcess(
                args=cmd,
                returncode=124,  # Standard timeout exit code
                stdout=e.stdout if e.stdout else "",
                stderr=e.stderr if e.stderr else "",
            )
        except OSError as e:
            logger.error("✗ Subprocess execution failed: %s: %s", type(e).__name__, e)
            # Return a CompletedProcess with error return code instead of raising
            # This allows the test to continue and log/copy data before failing
            return subprocess.CompletedProcess(
                args=cmd,
                returncode=1,  # Generic error exit code
                stdout="",
                stderr=str(e),
            )

    def _log_test_result(self, result: subprocess.CompletedProcess) -> None:
        """Log the test result."""
        logger.info("=" * 80)
        if result.returncode == 0:
            logger.info("✓ TEST PASSED - Return code 0")
        else:
            logger.error("✗ TEST FAILED - Return code %d", result.returncode)
        logger.info("=" * 80)

    @pytest.fixture
    def cs_dist_script(self):
        """Locate the test_cs_dist.py script"""
        logger.info("=" * 80)
        logger.info("FIXTURE: cs_dist_script - Starting script location search")
        logger.info("=" * 80)

        # Try multiple possible locations
        possible_paths = []

        # First, try using ProjDir2 environment variable (set by sysbuild_pipeline.groovy)
        proj_dir2 = os.environ.get("ProjDir2")
        logger.debug("ProjDir2 environment variable: %s", proj_dir2)

        if proj_dir2:
            path1 = os.path.join(proj_dir2, CS_DIST_TEST_SCRIPT_RELATIVE_PATH)
            logger.debug("Checking ProjDir2 path: %s", path1)
            possible_paths.append(path1)

        # Try to find sw-eng directory by traversing up from current location
        current_dir = os.getcwd()
        logger.debug("Current working directory: %s", current_dir)
        logger.debug("Traversing up directory tree to find sw-eng...")

        traversal_count = 0
        while current_dir != os.path.dirname(current_dir):  # Stop at root
            traversal_count += 1
            sw_eng_path = os.path.join(current_dir, CS_DIST_TEST_SCRIPT_RELATIVE_PATH)
            logger.debug("  [%d] Checking: %s", traversal_count, sw_eng_path)

            if os.path.exists(sw_eng_path):
                logger.info("✓ Found test_cs_dist.py at: %s", sw_eng_path)
                possible_paths.append(sw_eng_path)
                break
            current_dir = os.path.dirname(current_dir)

        logger.debug("Total paths to check: %d", len(possible_paths))
        for i, path in enumerate(possible_paths, 1):
            logger.debug("  [%d] %s - exists: %s", i, path, os.path.exists(path))
            if os.path.exists(path):
                logger.info("✓ Using script: %s", path)
                return path

        error_msg = (
            f"test_cs_dist.py not found in expected locations. "
            f"ProjDir2={proj_dir2}, cwd={os.getcwd()}"
        )
        logger.error(error_msg)
        logger.error("Searched paths: %s", possible_paths)
        pytest.fail(error_msg)
        return None

    def test_cs_dist(self, cs_dist_script, unlaunched_dut: DeviceAdapter):
        """
        Test CS distance measurements.

        Executes test_cs_dist.py which performs all validations:
        - Connects to serial device
        - Records CS measurements
        - Validates RC values (expects 50)
        - Checks for aborts (expects 0)
        - Returns 0 on success, 1 on failure

        The unlaunched_dut fixture:
        - Flashes the device with the built application
        - Does NOT connect to the serial port (avoiding conflicts with subprocess)
        - Provides device configuration (serial port, baud rate, etc.)
        """
        logger.info("=" * 80)
        logger.info("TEST: test_cs_dist - Starting CS distance test")
        logger.info("=" * 80)

        # Flash device and prepare for testing
        self._flash_and_prepare_device(unlaunched_dut)

        # Get and log device configuration
        port, baud = self._log_device_config(unlaunched_dut, cs_dist_script)

        # Verify device and script exist
        self._verify_device_and_script(port, cs_dist_script)

        # Build and execute command
        cmd = ["python3", cs_dist_script, "-p", port, "-b", str(baud)]
        logger.info("Command to execute: %s", " ".join(cmd))

        # Run the test subprocess
        result = self._run_cs_dist_subprocess(cmd)

        # Log test result
        self._log_test_result(result)

        # Copy cs_rreq_data.txt to the same directory as twister_harness.log
        # Do this BEFORE the assertion so we capture data even if test fails
        logger.info("=" * 80)
        logger.info("Copying measurement data file...")
        log_dir = Path(unlaunched_dut.device_config.build_dir)
        self._copy_cs_rreq_data_to_log_dir(log_dir)
        logger.info("=" * 80)

        # test_cs_dist.py returns 0 on success, 1 on failure
        # All validation is done inside test_cs_dist.py
        if result.returncode != 0:
            # Log the subprocess output to both logger and pytest summary
            logger.error("CS dist test failed with return code %d", result.returncode)
            logger.error("stdout:\n%s", result.stdout)
            logger.error("stderr:\n%s", result.stderr)
            pytest.fail(f"CS dist test failed with return code {result.returncode}")


if __name__ == "__main__":
    pytest.main([__file__, "-v"])
