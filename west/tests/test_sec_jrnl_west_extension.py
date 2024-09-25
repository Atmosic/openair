'''
@file test_sec_jrnl_west_extension.py

@brief Unit test for secjrnl west extension

Copyright (c) Atmosic 2024
'''

import os
import subprocess
import sys
import pytest

@pytest.fixture
def secjrnl_base_cmd():
    return ["west", "secjrnl"]

@pytest.fixture(autouse=True)
def secjrnl_base_subcmd_args():
    assert os.environ.get('BOARD') is not None
    assert os.environ.get('JLINK_SERIAL') is not None
    return ["--board", os.environ.get('BOARD'), "--device", os.environ.get('JLINK_SERIAL')]

@pytest.fixture()
def secjrnl_dump_args(secjrnl_base_cmd):
    return secjrnl_base_cmd + ["dump"]

@pytest.fixture()
def secjrnl_append_args(secjrnl_base_cmd):
    return secjrnl_base_cmd + ["append"]

@pytest.fixture()
def secjrnl_get_args(secjrnl_base_cmd):
    return secjrnl_base_cmd + ["get"]

@pytest.fixture()
def secjrnl_get_ratchet_args(secjrnl_base_cmd):
    return secjrnl_base_cmd + ["get_ratchet"]

@pytest.fixture()
def secjrnl_erase_args(secjrnl_base_cmd):
    return secjrnl_base_cmd + ["erase"]


def test_secjrnl_dump(secjrnl_dump_args, secjrnl_base_subcmd_args):
    '''Tests secjrnl subcmd: dump.'''
    # Verify that the command fails without the proper flags
    with pytest.raises(Exception):
        subprocess.run(secjrnl_dump_args,
                       check=True,
                       capture_output=True)

    subproc_cmd = secjrnl_dump_args + secjrnl_base_subcmd_args
    # Each board will have a differernt output so this test just sanity checks the commands
    # do not fail. The output cannot really be tested easily
    subprocess.run(subproc_cmd,
                   check=True,
                   capture_output=True)
    subprocess.run(subproc_cmd + ["--binary"],
                   check=True,
                   capture_output=True)
    subprocess.run(subproc_cmd + ["--hex"],
                   check=True,
                   capture_output=True)

def test_secjrnl_get_ratchet(secjrnl_get_ratchet_args, secjrnl_base_subcmd_args):
    '''Tests secjrnl subcmd: append.'''
    # Verify that the command fails without the proper flags
    with pytest.raises(Exception):
        subprocess.run(secjrnl_get_ratchet_args,
                       check=True,
                       capture_output=True)
    subproc_cmd = secjrnl_get_ratchet_args + secjrnl_base_subcmd_args
    call = subprocess.run(subproc_cmd,
                          check=True,
                          capture_output=True)
    # Verify the output of the command includes the expected output
    assert b"Secure Counter =" in call.stdout

def test_secjrnl_get_append(secjrnl_append_args, secjrnl_get_args, secjrnl_base_subcmd_args):
    '''Tests secjrnl subcmd: append and get commands'''
    # Verify that the command fails without the proper flags
    with pytest.raises(Exception):
        subprocess.run(secjrnl_append_args,
                       check=True,
                       capture_output=True)
    subproc_cmd = secjrnl_append_args + secjrnl_base_subcmd_args
    call = subprocess.run(subproc_cmd + ["--tag", "0x01", "--data", "\x68\x65\x6c\x6c\x6f"],
                          check=True,
                          capture_output=True)
    call = subprocess.run(secjrnl_get_args + secjrnl_base_subcmd_args + ["--tag", "0x01"],
                          check=True,
                          capture_output=True)

    assert b"tag:(01)" in call.stdout

def test_secjrnl_get_erase(secjrnl_erase_args, secjrnl_append_args, secjrnl_get_args, secjrnl_base_subcmd_args):
    # Verify that the command fails without the proper flags
    with pytest.raises(Exception):
        subprocess.run(secjrnl_erase_args,
                       check=True,
                       capture_output=True)
    subproc_erase_cmd = secjrnl_erase_args + secjrnl_base_subcmd_args
    subproc_append_cmd = secjrnl_append_args + secjrnl_base_subcmd_args
    subproc_get_cmd = secjrnl_get_args + secjrnl_base_subcmd_args
    call = subprocess.run(subproc_append_cmd + ["--tag", "0x05", "--data", "\x68\x65\x6c\x6c\x6f"],
                          check=True,
                          capture_output=True)
    call = subprocess.run(subproc_append_cmd + ["--tag", "0x06", "--data", "\x68\x65\x6c\x6c\x6f"],
                          check=True,
                          capture_output=True)
    call = subprocess.run(subproc_append_cmd + ["--tag", "0x07", "--data", "\x68\x65\x6c\x6c\x6f"],
                          check=True,
                          capture_output=True)
    # Sanity check all three tags were appended.
    call = subprocess.run(subproc_get_cmd + ["--tag", "0x05"],
                          check=True,
                          capture_output=True)
    assert b"tag:(05)" in call.stdout
    call = subprocess.run(subproc_get_cmd + ["--tag", "0x06"],
                          check=True,
                          capture_output=True)
    assert b"tag:(06)" in call.stdout
    call = subprocess.run(subproc_get_cmd + ["--tag", "0x07"],
                          check=True,
                          capture_output=True)
    assert b"tag:(07)" in call.stdout

    call = subprocess.run(subproc_erase_cmd,
                          check=True,
                          capture_output=True)
    with pytest.raises(Exception):
        subprocess.run(subproc_get_cmd + ["--tag", "0x05"],
                            check=True,
                            capture_output=True)
    with pytest.raises(Exception):
        subprocess.run(subproc_get_cmd + ["--tag", "0x06"],
                            check=True,
                            capture_output=True)
    with pytest.raises(Exception):
        subprocess.run(subproc_get_cmd + ["--tag", "0x07"],
                            check=True,
                            capture_output=True)