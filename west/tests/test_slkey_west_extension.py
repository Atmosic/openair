# Copyright (c) Atmosic 2026
#
# SPDX-License-Identifier: LicenseRef-Atmosic

"""
@file test_slkey_west_extension.py

@brief Unit test for slkey west extension
"""

import os
import subprocess
import tempfile
import pytest  # pylint: disable=import-error


@pytest.fixture
def slkey_base_cmd():
    """Tests slkey base command."""
    return ["west", "slkey"]


def _get_base_args():
    """Helper to get base arguments that are common to all tests."""
    assert os.environ.get("BOARD") is not None
    assert os.environ.get("PARTITION_FILE") is not None
    return [
        "--board",
        os.environ.get("BOARD"),
        "--partition_file",
        os.environ.get("PARTITION_FILE"),
    ]


@pytest.fixture
def slkey_jlink_args():
    """Fixture for JLINK-specific arguments."""
    assert os.environ.get("JLINK_SERIAL") is not None
    base_args = _get_base_args()
    return base_args + [
        "--device",
        os.environ.get("JLINK_SERIAL"),
        "--jlink",
    ]


@pytest.fixture
def slkey_dl_args():
    """Fixture for DL board-specific arguments."""
    assert os.environ.get("SYDNEY_SERIAL") is not None
    base_args = _get_base_args()
    return base_args + [
        "--device",
        os.environ.get("SYDNEY_SERIAL"),
        "--dl",
    ]


# pylint: disable=redefined-outer-name
def test_read_slot_jlink(slkey_base_cmd, slkey_jlink_args):
    """Tests reading a single slot with JLINK."""
    # Verify that the command fails without the proper flags
    with pytest.raises((subprocess.CalledProcessError, FileNotFoundError)):
        subprocess.run(slkey_base_cmd, check=True, capture_output=True)
    # Test reading slot 0
    subproc_cmd = slkey_base_cmd + ["read"] + slkey_jlink_args + ["--slot_index", "0"]
    subprocess.run(subproc_cmd, check=True, capture_output=True)


# pylint: disable=redefined-outer-name
def test_read_slot_dl(slkey_base_cmd, slkey_dl_args):
    """Tests reading a single slot with DL board."""
    # Verify that the command fails without the proper flags
    with pytest.raises((subprocess.CalledProcessError, FileNotFoundError)):
        subprocess.run(slkey_base_cmd, check=True, capture_output=True)
    # Test reading slot 0
    subproc_cmd = slkey_base_cmd + ["read"] + slkey_dl_args + ["--slot_index", "0"]
    subprocess.run(subproc_cmd, check=True, capture_output=True)


# pylint: disable=redefined-outer-name
def test_read_slot_flash_jlink(slkey_base_cmd, slkey_jlink_args):
    """Tests reading a single slot from Flash with JLINK."""
    # Test reading slot 0 from Flash
    subproc_cmd = (
        slkey_base_cmd + ["read"] + slkey_jlink_args + ["--slot_index", "0", "--flash"]
    )
    subprocess.run(subproc_cmd, check=True, capture_output=True)


# pylint: disable=redefined-outer-name
def test_read_slot_flash_dl(slkey_base_cmd, slkey_dl_args):
    """Tests reading a single slot from Flash with DL board."""
    # Test reading slot 0 from Flash
    subproc_cmd = (
        slkey_base_cmd + ["read"] + slkey_dl_args + ["--slot_index", "0", "--flash"]
    )
    subprocess.run(subproc_cmd, check=True, capture_output=True)


# pylint: disable=redefined-outer-name
def test_write_slot_jlink(slkey_base_cmd, slkey_jlink_args):
    """Tests writing a single slot with JLINK."""
    # Test writing a 32-byte key to slot 0
    test_key = "0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef"
    subproc_cmd = (
        slkey_base_cmd
        + ["write"]
        + slkey_jlink_args
        + ["--slot_index", "0", "--data", test_key]
    )
    subprocess.run(subproc_cmd, check=True, capture_output=True)


# pylint: disable=redefined-outer-name
def test_write_slot_dl(slkey_base_cmd, slkey_dl_args):
    """Tests writing a single slot with DL board."""
    # Test writing a 32-byte key to slot 0
    test_key = "0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef"
    subproc_cmd = (
        slkey_base_cmd
        + ["write"]
        + slkey_dl_args
        + ["--slot_index", "0", "--data", test_key]
    )
    subprocess.run(subproc_cmd, check=True, capture_output=True)


# pylint: disable=redefined-outer-name
def test_write_slot_flash_jlink(slkey_base_cmd, slkey_jlink_args):
    """Tests writing a single slot to Flash with JLINK."""
    # Test writing a 32-byte key to slot 0 in Flash
    test_key = "0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef"
    subproc_cmd = (
        slkey_base_cmd
        + ["write"]
        + slkey_jlink_args
        + ["--slot_index", "0", "--data", test_key, "--flash"]
    )
    subprocess.run(subproc_cmd, check=True, capture_output=True)


# pylint: disable=redefined-outer-name
def test_write_slot_flash_dl(slkey_base_cmd, slkey_dl_args):
    """Tests writing a single slot to Flash with DL board."""
    # Test writing a 32-byte key to slot 0 in Flash
    test_key = "0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef"
    subproc_cmd = (
        slkey_base_cmd
        + ["write"]
        + slkey_dl_args
        + ["--slot_index", "0", "--data", test_key, "--flash"]
    )
    subprocess.run(subproc_cmd, check=True, capture_output=True)


# pylint: disable=redefined-outer-name
def test_read_all_jlink(slkey_base_cmd, slkey_jlink_args):
    """Tests reading all slots with JLINK."""
    # Test reading all slots (0-7)
    subproc_cmd = slkey_base_cmd + ["read_all"] + slkey_jlink_args
    subprocess.run(subproc_cmd, check=True, capture_output=True)


# pylint: disable=redefined-outer-name
def test_read_all_dl(slkey_base_cmd, slkey_dl_args):
    """Tests reading all slots with DL board."""
    # Test reading all slots (0-7)
    subproc_cmd = slkey_base_cmd + ["read_all"] + slkey_dl_args
    subprocess.run(subproc_cmd, check=True, capture_output=True)


# pylint: disable=redefined-outer-name
def test_read_all_flash_jlink(slkey_base_cmd, slkey_jlink_args):
    """Tests reading all slots from Flash with JLINK."""
    # Test reading all slots from Flash
    subproc_cmd = slkey_base_cmd + ["read_all"] + slkey_jlink_args + ["--flash"]
    subprocess.run(subproc_cmd, check=True, capture_output=True)


# pylint: disable=redefined-outer-name
def test_read_all_flash_dl(slkey_base_cmd, slkey_dl_args):
    """Tests reading all slots from Flash with DL board."""
    # Test reading all slots from Flash
    subproc_cmd = slkey_base_cmd + ["read_all"] + slkey_dl_args + ["--flash"]
    subprocess.run(subproc_cmd, check=True, capture_output=True)


# pylint: disable=redefined-outer-name
def test_read_all_with_output_jlink(slkey_base_cmd, slkey_jlink_args):
    """Tests reading all slots with output file using JLINK."""
    with tempfile.NamedTemporaryFile(
        mode="wb", delete=False, suffix=".bin"
    ) as temp_file:
        output_file = temp_file.name

    try:
        # Test reading all slots and saving to file
        subproc_cmd = (
            slkey_base_cmd + ["read_all"] + slkey_jlink_args + ["-o", output_file]
        )
        subprocess.run(subproc_cmd, check=True, capture_output=True)

        # Verify the output file exists and has correct size (256 bytes = 8 slots * 32 bytes)
        assert os.path.exists(output_file)
        assert os.path.getsize(output_file) == 256
    finally:
        if os.path.exists(output_file):
            os.remove(output_file)


# pylint: disable=redefined-outer-name
def test_read_all_with_output_dl(slkey_base_cmd, slkey_dl_args):
    """Tests reading all slots with output file using DL board."""
    with tempfile.NamedTemporaryFile(
        mode="wb", delete=False, suffix=".bin"
    ) as temp_file:
        output_file = temp_file.name

    try:
        # Test reading all slots and saving to file
        subproc_cmd = (
            slkey_base_cmd + ["read_all"] + slkey_dl_args + ["-o", output_file]
        )
        subprocess.run(subproc_cmd, check=True, capture_output=True)

        # Verify the output file exists and has correct size (256 bytes = 8 slots * 32 bytes)
        assert os.path.exists(output_file)
        assert os.path.getsize(output_file) == 256
    finally:
        if os.path.exists(output_file):
            os.remove(output_file)


# pylint: disable=redefined-outer-name
def test_write_all_jlink(slkey_base_cmd, slkey_jlink_args):
    """Tests writing all slots from file with JLINK."""
    # Create a temporary file with 256 bytes (8 slots * 32 bytes each)
    with tempfile.NamedTemporaryFile(
        mode="wb", delete=False, suffix=".pkey"
    ) as temp_file:
        # Write test data: 256 bytes of incrementing pattern
        test_data = bytes(range(256))
        temp_file.write(test_data)
        input_file = temp_file.name

    try:
        # Test writing all slots from file
        subproc_cmd = (
            slkey_base_cmd + ["write_all"] + slkey_jlink_args + ["-f", input_file]
        )
        subprocess.run(subproc_cmd, check=True, capture_output=True)
    finally:
        if os.path.exists(input_file):
            os.remove(input_file)


# pylint: disable=redefined-outer-name
def test_write_all_dl(slkey_base_cmd, slkey_dl_args):
    """Tests writing all slots from file with DL board."""
    # Create a temporary file with 256 bytes (8 slots * 32 bytes each)
    with tempfile.NamedTemporaryFile(
        mode="wb", delete=False, suffix=".pkey"
    ) as temp_file:
        # Write test data: 256 bytes of incrementing pattern
        test_data = bytes(range(256))
        temp_file.write(test_data)
        input_file = temp_file.name

    try:
        # Test writing all slots from file
        subproc_cmd = (
            slkey_base_cmd + ["write_all"] + slkey_dl_args + ["-f", input_file]
        )
        subprocess.run(subproc_cmd, check=True, capture_output=True)
    finally:
        if os.path.exists(input_file):
            os.remove(input_file)


# pylint: disable=redefined-outer-name
def test_write_all_flash_jlink(slkey_base_cmd, slkey_jlink_args):
    """Tests writing all slots to Flash from file with JLINK."""
    # Create a temporary file with 256 bytes (8 slots * 32 bytes each)
    with tempfile.NamedTemporaryFile(
        mode="wb", delete=False, suffix=".pkey"
    ) as temp_file:
        # Write test data: 256 bytes of incrementing pattern
        test_data = bytes(range(256))
        temp_file.write(test_data)
        input_file = temp_file.name

    try:
        # Test writing all slots to Flash from file
        subproc_cmd = (
            slkey_base_cmd
            + ["write_all"]
            + slkey_jlink_args
            + ["-f", input_file, "--flash"]
        )
        subprocess.run(subproc_cmd, check=True, capture_output=True)
    finally:
        if os.path.exists(input_file):
            os.remove(input_file)


# pylint: disable=redefined-outer-name
def test_write_all_flash_dl(slkey_base_cmd, slkey_dl_args):
    """Tests writing all slots to Flash from file with DL board."""
    # Create a temporary file with 256 bytes (8 slots * 32 bytes each)
    with tempfile.NamedTemporaryFile(
        mode="wb", delete=False, suffix=".pkey"
    ) as temp_file:
        # Write test data: 256 bytes of incrementing pattern
        test_data = bytes(range(256))
        temp_file.write(test_data)
        input_file = temp_file.name

    try:
        # Test writing all slots to Flash from file
        subproc_cmd = (
            slkey_base_cmd
            + ["write_all"]
            + slkey_dl_args
            + ["-f", input_file, "--flash"]
        )
        subprocess.run(subproc_cmd, check=True, capture_output=True)
    finally:
        if os.path.exists(input_file):
            os.remove(input_file)
