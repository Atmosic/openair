#!/usr/bin/env python3
"""
@file test_esl_ap.py

@brief ESL AP pytest test implementation

This module implements the ESL (Electronic Shelf Label) AP test using pytest.
It tests ESL functionality including synchronization, sensor data, ACL connection,
image upload, LED control, and factory reset.

Copyright (C) Atmosic 2026
"""

import logging
import subprocess
import threading
import time

import pytest
import serial
from twister_harness import DeviceAdapter  # pylint: disable=import-error
from twister_harness.exceptions import (  # pylint: disable=import-error
    TwisterHarnessTimeoutException,
    TwisterHarnessException,
)

logger = logging.getLogger(__name__)

# Timeouts
TIMEOUT = 10
SYNC_TIMEOUT = 20
RESET_TIMEOUT = 3
MAX_RETRIES = 3

# Exception list for known acceptable errors
EXCEPTION_LIST = [
    "<err> esl_display: esl_display_write_ctx ",
    "<err> esl_display: esl_display_image display error:-128",
    "<err> bt_esls: esls_display_handler err:-128",
    "<err> bt_esls: unexp opcode:0",
    "<err> bt_scan: Unknown handle 0x0000 for periodic advertising report",
    "<err> bt_esls: Security failed",
    "<err> bt_adv: No valid legacy adv to resume",
]

# ESL test commands: (command, expected_response)
ESL_C_TEST_COMMANDS = [
    ("esl_c auto_ap 1\n", "state:synchronized"),
    ("esl_c auto_ap 0\n", "New ESL_AP_AUTO_MODE 0"),
    ("esl_c pawr push_sync_buf 0 100000\n", "#SLOT:0,0x0b348e00"),
    ("esl_c acl connect_esl 0000\n", "#DISCOVERY"),
    ("esl_c obj_c write 0 0 0\n", "#OTS_WRITTEN"),
    ("esl_c obj_c write 0 1 1\n", "#OTS_WRITTEN"),
    ("esl_c update_complete 0 0000\n", "esl_c update_complete 0 0000"),
    ("esl_c acl past 0\n", "state:synchronized"),
    ("esl_c pawr push_sync_buf 0 20000000\n", "#SLOT:0,0x0434110000"),
    ("esl_c pawr push_sync_buf 0 60000000FFFFFFFF\n", "#SLOT:0,0x0334000c"),
    ("esl_c pawr push_sync_buf 0 60000000F0480200\n", "#SLOT:0,0x0434110000"),
    ("esl_c pawr push_sync_buf 0 60000000F0470200\n", "#SLOT:0,0x0334000b"),
    ("esl_c pawr push_sync_buf 0 60000001F0480200\n", "#SLOT:0,0x0434110001"),
    ("esl_c pawr push_sync_buf 0 0000\n", "#SLOT:0,0x0434101200"),
    ("esl_c pawr push_sync_buf 0 6000000000000000\n", "#SLOT:0,0x0434110000"),
    ("esl_c pawr push_sync_buf 0 0000\n", "#SLOT:0,0x0434100200"),
    ("esl_c pawr push_sync_buf 0 60000001F0480200\n", "#SLOT:0,0x0434110001"),
    ("esl_c pawr push_sync_buf 0 6000000000000000\n", "#SLOT:0,0x0434110000"),
    ("esl_c pawr push_sync_buf 0 B0000033000000000000000100\n", "#SLOT:0,0x03340100"),
    ("esl_c pawr push_sync_buf 0 0000\n", "#SLOT:0,0x0434100600"),
    ("esl_c pawr push_sync_buf 0 B0000033000000000000000000\n", "#SLOT:0,0x03340100"),
    ("esl_c pawr push_sync_buf 0 0000\n", "#SLOT:0,0x0434100200"),
    ("esl_c pawr push_sync_buf 0 B0000033AA00AA00AA02153200\n", "#SLOT:0,0x03340100"),
    ("esl_c pawr push_sync_buf 0 0000\n", "#SLOT:0,0x0434100600"),
    ("esl_c pawr push_sync_buf 0 B0000033000000000000000000\n", "#SLOT:0,0x03340100"),
    (
        "esl_c pawr push_sync_buf 0 F0000033000000000000000100FFFFFFFF\n",
        "#SLOT:0,0x0334000c",
    ),
    (
        "esl_c pawr push_sync_buf 0 F0000033000000000000000100400D0300\n",
        "#SLOT:0,0x03340100",
    ),
    ("esl_c pawr push_sync_buf 0 0000\n", "#SLOT:0,0x0434100a00"),
    (
        "esl_c pawr push_sync_buf 0 F000003300000000000000010050340300\n",
        "#SLOT:0,0x0334000b",
    ),
    (
        "esl_c pawr push_sync_buf 0 F000003300000000000000010000000000\n",
        "#SLOT:0,0x03340100",
    ),
    ("esl_c pawr push_sync_buf 0 0000\n", "#SLOT:0,0x0434100200"),
]

FACTORY_RESET_COMMANDS = [
    ("esl_c acl connect_esl 0000\n", "#DISCOVERY"),
    ("esl_c factory 0\n", "Disconnected"),
]


class EslTester:
    """ESL AP Tester class for Nordic ESL AP communication"""

    def __init__(self, tester_port: str, tester_serial: str):
        self.tester_serial = tester_serial
        self.terminate_event = threading.Event()
        self.error_detected = False
        self._monitor_thread = None

        # Open serial port for Nordic ESL AP tester
        logger.info("Opening tester serial port: %s", tester_port)
        self.ser = serial.Serial(tester_port, 115200, timeout=TIMEOUT)
        logger.info(
            "Tester serial port opened: %s (is_open=%s)", tester_port, self.ser.is_open
        )

    def close(self):
        """Close serial connection and stop monitoring"""
        self.terminate_event.set()
        if self.ser:
            self.ser.close()

    def reset_device(self):
        """Reset the Nordic device using nrfutil"""
        command = ["nrfutil", "device", "reset", "--serial-number", self.tester_serial]
        logger.info("reset_device cmd: %s", " ".join(command))
        try:
            result = subprocess.run(command, capture_output=True, text=True, check=True)
            logger.info("reset_device... (returncode=%d)", result.returncode)
            if result.stdout.strip():
                logger.info("reset_device stdout: %s", result.stdout.strip())
            if result.stderr.strip():
                logger.info("reset_device stderr: %s", result.stderr.strip())
            time.sleep(RESET_TIMEOUT)
            logger.info(
                "After reset: ser.is_open=%s, ser.port=%s",
                self.ser.is_open,
                self.ser.port,
            )
        except subprocess.CalledProcessError as e:
            logger.error(
                "reset_device failed: returncode=%d, stderr=%s", e.returncode, e.stderr
            )
            raise RuntimeError(f"Reset nrf device failed: {e.stderr}") from e
        except FileNotFoundError as e:
            logger.error("nrfutil not found in PATH: %s", e)
            raise RuntimeError(f"nrfutil not found: {e}") from e

    def send_and_check_response(
        self, command: str, expected: str, timeout: int = TIMEOUT
    ):
        """Send command and wait for expected response"""
        for tries in range(MAX_RETRIES):
            start_time = time.time()
            logger.debug(
                "ser state before write: is_open=%s, port=%s, in_waiting=%s",
                self.ser.is_open,
                self.ser.port,
                self.ser.in_waiting,
            )
            self.ser.write(command.encode())
            logger.info("Sent: %s", command.strip())

            while time.time() - start_time < timeout:
                if self.terminate_event.is_set():
                    raise RuntimeError("Test terminated due to error detection")
                if self.ser.in_waiting > 0:
                    response = self.ser.readline().decode("utf-8").strip()
                    logger.info("Received: %s", response)
                    if expected in response:
                        logger.info("Received expected response!")
                        return
                time.sleep(0.1)
            logger.info(
                "Retry %d/%d (ser.is_open=%s, ser.in_waiting=%s)",
                tries + 1,
                MAX_RETRIES,
                self.ser.is_open,
                self.ser.in_waiting,
            )
        raise TimeoutError(f"Timeout waiting for: {expected}")

    def execute_commands(self, commands: list):
        """Execute a list of (command, expected_response) tuples"""
        for command, expected in commands:
            if self.terminate_event.is_set():
                raise RuntimeError("Test terminated due to error detection")
            self.send_and_check_response(command, expected)

    def unbond(self):
        """Reset device and AP state"""
        self.reset_device()
        self.send_and_check_response("esl_c reset_ap\n", "esl_c reset_ap")

    def discovery(self, associated: bool = False):
        """Check tag discovery state"""
        expected = "state:unsynchronized" if associated else "state:unassociated"
        self.send_and_check_response("esl_c esl_c tag_state\n", expected)

    def start_monitoring(self, dut: DeviceAdapter):
        """Start monitoring ESL tag output for errors via twister's DeviceAdapter.

        Reads from twister's internal queue (no separate serial port needed),
        avoiding serial port conflicts while preserving real-time <err> detection.
        """
        self._monitor_thread = threading.Thread(
            target=self._monitor_device_output,
            args=(dut,),
            daemon=True,
        )
        self._monitor_thread.start()

    def _monitor_device_output(self, dut: DeviceAdapter):
        """Monitor device output from twister's DeviceAdapter for <err> patterns."""
        while not self.terminate_event.is_set():
            try:
                line = dut.readline(timeout=0.5, print_output=False)
            except TwisterHarnessTimeoutException:
                continue
            except TwisterHarnessException:
                # Device disconnected or not running
                break

            if "<err>" in line:
                if not any(exc in line for exc in EXCEPTION_LIST):
                    logger.error("Error detected in ESL tag output: %s", line)
                    self.error_detected = True
                    self.terminate_event.set()
                    return
            else:
                logger.debug("ESL tag: %s", line)


@pytest.fixture(name="esl_tester", scope="function")
def esl_tester_fixture(tester_device_path, tester_serial):
    """Create and configure the ESL tester instance"""
    tester = EslTester(tester_device_path, tester_serial)
    yield tester
    tester.close()


def test_esl_ap(esl_tester, unlaunched_dut: DeviceAdapter):
    """
    ESL AP Integration Test

    This test performs three complete ESL test cycles:
    1. Unbond -> Discovery (unassociated) -> ESL commands -> Factory reset
    2. Unbond -> Discovery (unassociated) -> ESL commands
    3. Wait for sync timeout -> Discovery (unsynchronized) -> ESL commands -> Unassociate

    The test validates:
    - ESL tag synchronization with AP
    - Sensor data reading
    - ACL connection establishment
    - Image upload via OTS
    - Display control (timed image, update)
    - LED control (on/off, timed, repeat)
    - Factory reset

    Uses unlaunched_dut to manually control flash timing and wait for device ready.
    """
    logger.info("Starting ESL AP test")

    logger.info("Flashing device...")
    unlaunched_dut.launch()
    logger.info("Device flashed and ready")

    # Start monitoring ESL tag output for <err> via twister's DeviceAdapter
    esl_tester.start_monitoring(unlaunched_dut)

    # Test Cycle 1: Full cycle with factory reset
    logger.info("=== Test Cycle 1: Full cycle with factory reset ===")
    esl_tester.unbond()
    esl_tester.reset_device()
    esl_tester.discovery(associated=False)
    esl_tester.execute_commands(ESL_C_TEST_COMMANDS)
    esl_tester.execute_commands(FACTORY_RESET_COMMANDS)
    esl_tester.unbond()

    # Test Cycle 2: Re-associate after factory reset
    logger.info("=== Test Cycle 2: Re-associate after factory reset ===")
    esl_tester.reset_device()
    esl_tester.discovery(associated=False)
    esl_tester.execute_commands(ESL_C_TEST_COMMANDS)

    # Test Cycle 3: Sync timeout and re-sync
    logger.info("=== Test Cycle 3: Sync timeout and re-sync ===")
    esl_tester.reset_device()
    # Wait for ESL synchronization state timeout
    logger.info("Waiting %ds for sync timeout...", SYNC_TIMEOUT)
    time.sleep(SYNC_TIMEOUT)
    esl_tester.discovery(associated=True)
    esl_tester.execute_commands(ESL_C_TEST_COMMANDS)

    # Final unassociate command
    logger.info("=== Final unassociate ===")
    esl_tester.send_and_check_response(
        "esl_c pawr push_sync_buf 0 010000\n", "#SLOT:0,0x0434100000"
    )

    # Final device reset
    esl_tester.reset_device()

    # Check if any errors were detected by the monitoring thread
    if esl_tester.error_detected:
        pytest.fail("ESL test failed: Error detected in ESL tag console output")

    logger.info("ESL AP test PASSED")
