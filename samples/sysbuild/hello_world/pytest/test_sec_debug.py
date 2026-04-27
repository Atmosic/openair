#!/usr/bin/env python
"""
@file test_sec_debug.py

@brief Secure Debug Authentication test

Copyright (C) Atmosic 2025
"""

import os
import sys
from dataclasses import dataclass
from pathlib import Path
from typing import BinaryIO, Optional

from twister_harness import DeviceAdapter  # pylint: disable=import-error

# Add the tools/scripts directory to the path
openair_dir = Path(__file__).resolve().parents[4]
scripts_dir = openair_dir / "tools" / "scripts"
sys.path.insert(0, str(scripts_dir))
from sec_debug_unlock import (
    command_unlock,
)  # pylint: disable=import-error,wrong-import-position


@dataclass
class Arguments:
    """Arguments for the command_unlock function"""

    baud: int
    port: str
    key: BinaryIO
    passwd: Optional[str]
    verbose: bool = False


def test_sec_debug(unlaunched_dut: DeviceAdapter):
    """Test secure debug unlock functionality"""
    unlaunched_dut.launch()

    key_path = openair_dir / "lib" / "atm_debug_auth" / "root-debug-ec-p256.pem"
    with open(key_path, "rb") as key_file:
        args = Arguments(115200, os.environ["ZEPHYR_UART0"], key_file, None, True)
        return command_unlock(args)
