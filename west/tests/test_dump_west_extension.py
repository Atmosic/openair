# Copyright (c) Atmosic 2025-2026
#
# SPDX-License-Identifier: LicenseRef-Atmosic

"""
@file test_dump_west_extension.py

@brief Unit test for dump west extension
"""

import os
import subprocess
import pytest  # pylint: disable=import-error


@pytest.fixture
def dump_base_cmd():
    """Tests dump base command."""
    return ["west", "dump"]


def _get_base_args():
    """Helper to get base arguments that are common to all tests."""
    assert os.environ.get("BOARD") is not None
    assert os.environ.get("OUTPUT_FILE") is not None
    assert os.environ.get("START_ADDR") is not None
    assert os.environ.get("SIZE") is not None
    return [
        "--board",
        os.environ.get("BOARD"),
        "-o",
        os.environ.get("OUTPUT_FILE"),
        "--start_addr",
        os.environ.get("START_ADDR"),
        "--size",
        os.environ.get("SIZE"),
    ]


@pytest.fixture
def dump_jlink_args():
    """Fixture for JLINK-specific arguments."""
    assert os.environ.get("JLINK_SERIAL") is not None
    base_args = _get_base_args()
    return base_args + [
        "--device",
        os.environ.get("JLINK_SERIAL"),
        "--jlink",
    ]


@pytest.fixture
def dump_dl_args():
    """Fixture for DL board-specific arguments."""
    assert os.environ.get("SYDNEY_SERIAL") is not None
    base_args = _get_base_args()
    return base_args + [
        "--device",
        os.environ.get("SYDNEY_SERIAL"),
        "--dl",
    ]


# pylint: disable=redefined-outer-name
def test_dump_flash_jlink(dump_base_cmd, dump_jlink_args):
    """Tests dump flash with JLINK."""
    # Verify that the command fails without the proper flags
    with pytest.raises((subprocess.CalledProcessError, FileNotFoundError)):
        subprocess.run(dump_base_cmd, check=True, capture_output=True)
    subproc_cmd = dump_base_cmd + dump_jlink_args
    subprocess.run(subproc_cmd, check=True, capture_output=True)


# pylint: disable=redefined-outer-name
def test_dump_flash_dl(dump_base_cmd, dump_dl_args):
    """Tests dump flash with DL board."""
    # Verify that the command fails without the proper flags
    with pytest.raises((subprocess.CalledProcessError, FileNotFoundError)):
        subprocess.run(dump_base_cmd, check=True, capture_output=True)
    subproc_cmd = dump_base_cmd + dump_dl_args
    subprocess.run(subproc_cmd, check=True, capture_output=True)


# pylint: disable=redefined-outer-name
def test_dump_rram_jlink(dump_base_cmd, dump_jlink_args):
    """Tests dump rram with JLINK."""
    # Verify that the command fails without the proper flags
    with pytest.raises((subprocess.CalledProcessError, FileNotFoundError)):
        subprocess.run(dump_base_cmd, check=True, capture_output=True)
    subproc_cmd = dump_base_cmd + dump_jlink_args
    subprocess.run(subproc_cmd + ["--rram"], check=True, capture_output=True)


# pylint: disable=redefined-outer-name
def test_dump_rram_dl(dump_base_cmd, dump_dl_args):
    """Tests dump rram with DL board."""
    # Verify that the command fails without the proper flags
    with pytest.raises((subprocess.CalledProcessError, FileNotFoundError)):
        subprocess.run(dump_base_cmd, check=True, capture_output=True)
    subproc_cmd = dump_base_cmd + dump_dl_args
    subprocess.run(subproc_cmd + ["--rram"], check=True, capture_output=True)
