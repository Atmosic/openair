'''
@file test_atm_otp_west_extension.py

@brief Unit test for atmotp west extension

Copyright (c) Atmosic 2024
'''

import os
import subprocess
import sys
import pytest
import re


@pytest.fixture
def atmotp_base_cmd():
    return ["west", "atmotp"]


@pytest.fixture(autouse=True)
def atmotp_base_subcmd_args():
    assert os.environ.get('BOARD') is not None
    assert os.environ.get('JLINK_SERIAL') is not None
    return ["--board", os.environ.get('BOARD'), "--device", os.environ.get('JLINK_SERIAL')]


@pytest.fixture()
def atmotp_dump_args(atmotp_base_cmd):
    return atmotp_base_cmd + ["dump"]


@pytest.fixture()
def atmotp_list_otp_args(atmotp_base_cmd):
    return atmotp_base_cmd + ["list_otp"]


@pytest.fixture()
def atmotp_get_args(atmotp_base_cmd):
    return atmotp_base_cmd + ["get"]


def test_atmotp_list_otp(atmotp_list_otp_args, atmotp_base_subcmd_args):
    '''Tests atmotp subcmd: list_otp.'''
    # Verify that the command fails without the proper flags
    with pytest.raises(Exception):
        subprocess.run(atmotp_list_otp_args,
                       check=True,
                       capture_output=True)

    subproc_cmd = atmotp_list_otp_args + atmotp_base_subcmd_args
    # Each board will have a differernt output so this test just sanity checks the commands
    # do not fail. The output cannot really be tested easily
    subprocess.run(subproc_cmd,
                   check=True,
                   capture_output=True)


def test_atmotp_dump(atmotp_dump_args, atmotp_base_subcmd_args):
    '''Tests atmotp subcmd: dump.'''
    # Verify that the command fails without the proper flags
    with pytest.raises(Exception):
        subprocess.run(atmotp_dump_args,
                       check=True,
                       capture_output=True)
    subproc_cmd = atmotp_dump_args + atmotp_base_subcmd_args
    subprocess.run(subproc_cmd,
                   check=True,
                   capture_output=True)


def test_atmotp_get(atmotp_get_args, atmotp_base_subcmd_args):
    '''Tests atmotp subcmd: get commands'''
    # Verify that the command fails without the proper flags
    with pytest.raises(Exception):
        subprocess.run(atmotp_get_args,
                       check=True,
                       capture_output=True)
    subproc_cmd = atmotp_get_args + atmotp_base_subcmd_args
    call = subprocess.run(subproc_cmd + ["--otp", "RRAM_WRITE_LOCK"],
                          check=True,
                          capture_output=True)
    bin_output = call.stdout.split(b"\n")[1].decode(encoding='utf-8', errors='strict')  # strip OpenOCD print
    expected_len = 7
    assert re.search(fr"0b[0-1]{{{expected_len}}}", bin_output)
    call = subprocess.run(subproc_cmd + ["--otp", "53"],
                          check=True,
                          capture_output=True)

    bin_output_53 = call.stdout.split(b"\n")[1].decode(encoding='utf-8', errors='strict')  # strip OpenOCD print
    expected_len = 1
    assert re.search(fr"0b[0-1]{{{expected_len}}}", bin_output_53)
    call = subprocess.run(subproc_cmd + ["--otp", "RRAM_WRITE_LOCK.5"],
                          check=True,
                          capture_output=True)
    bin_output_RRAM_WRITE_LOCK_5 = call.stdout.split(
        b"\n")[1].decode(encoding='utf-8', errors='strict')  # strip OpenOCD print
    expected_len = 1
    assert re.search(fr"0b[0-1]{{{expected_len}}}", bin_output_RRAM_WRITE_LOCK_5)
    call = subprocess.run(subproc_cmd + ["--otp", "RRAM_WRITE_LOCK.SECURE_COUNTERS"],
                          check=True,
                          capture_output=True)
    bin_output_RRAM_WRITE_LOCK_SECURE_COUNTERS = call.stdout.split(b"\n")[
        1].decode(encoding='utf-8', errors='strict')  # strip OpenOCD print
    expected_len = 1
    assert re.search(fr"0b[0-1]{{{expected_len}}}",
                     bin_output_RRAM_WRITE_LOCK_SECURE_COUNTERS)
    assert bin_output_53 == bin_output_RRAM_WRITE_LOCK_5 == bin_output_RRAM_WRITE_LOCK_SECURE_COUNTERS
