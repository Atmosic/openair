# Copyright (c) Atmosic 2024-2026
#
# SPDX-License-Identifier: LicenseRef-Atmosic

"""
@file test_sec_jrnl_west_extension.py

@brief Unit test for secjrnl west extension
"""

# Test functions and fixtures intentionally reuse fixture names as parameter names,
# which is the standard pytest pattern and not a real shadowing bug.
# pylint: disable=redefined-outer-name

import ast
import os
import subprocess
import pytest


@pytest.fixture(scope="module")
def secjrnl_base_cmd():
    """Base secjrnl west sub-command."""
    return ["west", "secjrnl"]


@pytest.fixture(scope="module")
def secjrnl_dump_args(secjrnl_base_cmd):
    """Args for secjrnl dump sub-command."""
    return secjrnl_base_cmd + ["dump"]


@pytest.fixture()
def secjrnl_append_args(secjrnl_base_cmd):
    """Args for secjrnl append sub-command."""
    return secjrnl_base_cmd + ["append"]


@pytest.fixture()
def secjrnl_create_args(secjrnl_base_cmd):
    """Args for secjrnl create sub-command."""
    return secjrnl_base_cmd + ["create"]


@pytest.fixture()
def secjrnl_get_args(secjrnl_base_cmd):
    """Args for secjrnl get sub-command."""
    return secjrnl_base_cmd + ["get"]


@pytest.fixture()
def secjrnl_get_ratchet_args(secjrnl_base_cmd):
    """Args for secjrnl get_ratchet sub-command."""
    return secjrnl_base_cmd + ["get_ratchet"]


@pytest.fixture()
def secjrnl_erase_args(secjrnl_base_cmd):
    """Args for secjrnl erase sub-command."""
    return secjrnl_base_cmd + ["erase"]


@pytest.fixture(scope="module")
def secjrnl_burn_args(secjrnl_base_cmd):
    """Args for secjrnl burn sub-command."""
    return secjrnl_base_cmd + ["burn"]


@pytest.fixture(scope="module", autouse=True)
def secjrnl_base_subcmd_args(secjrnl_dump_args, secjrnl_burn_args):
    """Provides base subcommand args and preserves/restores the sec jrnl once per module."""
    board = os.environ.get("ZEPHYR_BRD")
    if not board:
        board = os.environ.get("BOARD")
    assert board is not None
    args = [
        "--board",
        board,
        "--device",
    ]
    device = os.environ.get("ATMEVK_SERIAL")
    if not device:
        device = os.environ.get("SYDNEY_SERIAL")
    if not device:
        device = os.environ.get("JLINK_SERIAL")
        args += [device, "--jlink"]
    else:
        args += [device]
    assert device is not None

    # Handle potential erases by storing and restoring secjrnl once for the whole module.
    cmd = secjrnl_dump_args + args + ["--binfile", "out.bin"]
    subprocess.run(cmd, check=True, capture_output=True)

    yield args

    cmd = secjrnl_burn_args + args + ["--sec-jrnl", "out.bin"]
    subprocess.run(cmd, check=True, capture_output=True)


def test_secjrnl_dump(secjrnl_dump_args, secjrnl_base_subcmd_args):
    """Tests secjrnl subcmd: dump."""
    # Verify that the command fails without the proper flags
    with pytest.raises(Exception):
        subprocess.run(secjrnl_dump_args, check=True, capture_output=True)

    subproc_cmd = secjrnl_dump_args + secjrnl_base_subcmd_args
    subprocess.run(subproc_cmd, check=True, capture_output=True)
    call = subprocess.run(subproc_cmd + ["--binary"], check=True, capture_output=True)
    binary_out = call.stdout.decode().strip().split("\n")
    binary_data = ast.literal_eval(binary_out[2])
    call = subprocess.run(subproc_cmd + ["--hex"], check=True, capture_output=True)
    hex_out = call.stdout.decode().strip().split("\n")
    hex_data = bytes.fromhex(hex_out[2])

    # The hex output should match a prefix of the binary output
    assert isinstance(binary_data, bytes)
    assert len(hex_data) <= len(binary_data)
    assert binary_data[: len(hex_data)] == hex_data


def test_secjrnl_get_ratchet(secjrnl_get_ratchet_args, secjrnl_base_subcmd_args):
    """Tests secjrnl subcmd: append."""
    # Verify that the command fails without the proper flags
    with pytest.raises(Exception):
        subprocess.run(secjrnl_get_ratchet_args, check=True, capture_output=True)
    subproc_cmd = secjrnl_get_ratchet_args + secjrnl_base_subcmd_args
    call = subprocess.run(subproc_cmd, check=True, capture_output=True)
    # Verify the output of the command includes the expected output
    assert b"Secure Counter =" in call.stdout


def test_secjrnl_get_append(
    secjrnl_append_args, secjrnl_get_args, secjrnl_base_subcmd_args
):
    """Tests secjrnl subcmd: append and get commands"""
    # Verify that the command fails without the proper flags
    with pytest.raises(Exception):
        subprocess.run(secjrnl_append_args, check=True, capture_output=True)
    subproc_cmd = secjrnl_append_args + secjrnl_base_subcmd_args
    call = subprocess.run(
        subproc_cmd + ["--tag", "0x01", "--data", "\x68\x65\x6c\x6c\x6f"],
        check=True,
        capture_output=True,
    )
    call = subprocess.run(
        secjrnl_get_args + secjrnl_base_subcmd_args + ["--tag", "0x01"],
        check=True,
        capture_output=True,
    )

    assert b"BD_ADDR" in call.stdout


def test_secjrnl_append_data_file(
    tmp_path, secjrnl_append_args, secjrnl_get_args, secjrnl_base_subcmd_args
):
    """Tests secjrnl append sub-command: --data <file> is read as a file.

    Regression test for SOFTWARE-11309, where --data <file> was never read
    as a file and instead the literal path string was used as the TLV data.
    """
    subproc_append_cmd = secjrnl_append_args + secjrnl_base_subcmd_args
    subproc_get_cmd = secjrnl_get_args + secjrnl_base_subcmd_args

    data_file = tmp_path / "tlv_data.bin"
    file_contents = b"\x01\x02\x03\x04\x05\x06"
    data_file.write_bytes(file_contents)

    subprocess.run(
        subproc_append_cmd + ["--tag", "0x01", "--data", str(data_file)],
        check=True,
        capture_output=True,
    )
    call = subprocess.run(
        subproc_get_cmd + ["--tag", "0x01"], check=True, capture_output=True
    )
    stdout = call.stdout.decode()

    # The TLV data should match the contents of the file...
    assert "01 02 03 04 05 06" in stdout
    # ...and not the literal path string that was passed via --data.
    assert str(data_file) not in stdout


def test_secjrnl_create_data_file(tmp_path, secjrnl_create_args):
    """Tests secjrnl create sub-command: --data <file> is read as a file.

    Regression test for SOFTWARE-11309, where --data <file> was never read
    as a file and instead the literal path string was used as the TLV data.
    """
    board = os.environ.get("ZEPHYR_BRD")
    if not board:
        board = os.environ.get("BOARD")
    assert board is not None

    data_file = tmp_path / "tlv_data.bin"
    file_contents = b"\x01\x02\x03\x04\x05\x06"
    data_file.write_bytes(file_contents)

    outfile = tmp_path / "sec_jrnl_out.bin"
    cmd = secjrnl_create_args + [
        "--board",
        board,
        "--tag",
        "0x01",
        "--data",
        str(data_file),
        "-o",
        str(outfile),
    ]
    subprocess.run(cmd, check=True, capture_output=True)

    written = outfile.read_bytes()

    # The TLV data should match the contents of the file...
    assert file_contents in written
    # ...and not the literal path string that was passed via --data.
    assert str(data_file).encode() not in written


def test_secjrnl_get_erase(
    secjrnl_erase_args, secjrnl_append_args, secjrnl_get_args, secjrnl_base_subcmd_args
):
    """Tests secjrnl subcmd: erase, append and get commands."""
    # Verify that the command fails without the proper flags
    with pytest.raises(Exception):
        subprocess.run(secjrnl_erase_args, check=True, capture_output=True)
    subproc_erase_cmd = secjrnl_erase_args + secjrnl_base_subcmd_args
    subproc_append_cmd = secjrnl_append_args + secjrnl_base_subcmd_args
    subproc_get_cmd = secjrnl_get_args + secjrnl_base_subcmd_args
    call = subprocess.run(
        subproc_append_cmd + ["--tag", "0x05", "--data", "\x68\x65\x6c\x6c\x6f"],
        check=True,
        capture_output=True,
    )
    call = subprocess.run(
        subproc_append_cmd + ["--tag", "0x06", "--data", "\x68\x65\x6c\x6c\x6f"],
        check=True,
        capture_output=True,
    )
    call = subprocess.run(
        subproc_append_cmd + ["--tag", "0x07", "--data", "\x68\x65\x6c\x6c\x6f"],
        check=True,
        capture_output=True,
    )
    # Sanity check all three tags were appended.
    call = subprocess.run(
        subproc_get_cmd + ["--tag", "0x05"], check=True, capture_output=True
    )
    assert b"tag:(05)" in call.stdout
    call = subprocess.run(
        subproc_get_cmd + ["--tag", "0x06"], check=True, capture_output=True
    )
    assert b"tag:(06)" in call.stdout
    call = subprocess.run(
        subproc_get_cmd + ["--tag", "0x07"], check=True, capture_output=True
    )
    assert b"tag:(07)" in call.stdout

    call = subprocess.run(subproc_erase_cmd, check=True, capture_output=True)
    with pytest.raises(Exception):
        subprocess.run(
            subproc_get_cmd + ["--tag", "0x05"], check=True, capture_output=True
        )
    with pytest.raises(Exception):
        subprocess.run(
            subproc_get_cmd + ["--tag", "0x06"], check=True, capture_output=True
        )
    with pytest.raises(Exception):
        subprocess.run(
            subproc_get_cmd + ["--tag", "0x07"], check=True, capture_output=True
        )
