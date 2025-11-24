"""
@file test_zsg_west_extension.py

@brief Unit test for zsg west extension

Copyright (c) Atmosic 2025
"""

import os
import subprocess
import pytest


@pytest.fixture
def zsg_base_cmd():
    """Tests zsg base command."""
    return ["west", "zsg"]


@pytest.fixture()
# pylint: disable=redefined-outer-name
def zsg_dump_args(zsg_base_cmd):
    """Tests zsg dump command."""
    return zsg_base_cmd + ["dump"]


@pytest.fixture()
# pylint: disable=redefined-outer-name
def zsg_show_args(zsg_base_cmd):
    """Tests zsg show command."""
    return zsg_base_cmd + ["show"]


@pytest.fixture()
# pylint: disable=redefined-outer-name
def zsg_write_args(zsg_base_cmd):
    """Tests zsg write command."""
    return zsg_base_cmd + ["write"]


@pytest.fixture()
# pylint: disable=redefined-outer-name
def zsg_read_args(zsg_base_cmd):
    """Tests zsg read command."""
    return zsg_base_cmd + ["read"]


@pytest.fixture()
# pylint: disable=redefined-outer-name
def zsg_scan_args(zsg_base_cmd):
    """Tests zsg scan command."""
    return zsg_base_cmd + ["scan"]


def _build_args_from_env(env_vars):
    """Helper function to build command arguments from environment variables."""
    extra_args = []
    for env_var, flag in env_vars.items():
        value = os.environ.get(env_var)
        if value is not None:
            if isinstance(flag, list):
                extra_args.extend(flag)
            else:
                extra_args.extend([flag, value])
        elif env_var in [
            "PARTITION_FILE",
            "PARTITION_TYPE",
            "INPUT_FILE",
            "OUTPUT_FILE",
            "BOARD",
            "OPENOCD_CFG",
            "OBJCOPY_FILE",
        ]:
            pytest.skip(f"Required environment variable {env_var} not set")
    return extra_args


# pylint: disable=redefined-outer-name
def test_zsg_write(zsg_write_args, atm_write_extra_args):
    """Tests zsg subcmd: write."""
    # Verify that the command fails without the proper flags
    with pytest.raises((subprocess.CalledProcessError, FileNotFoundError)):
        subprocess.run(zsg_write_args, check=True, capture_output=True)
    subproc_cmd = zsg_write_args + atm_write_extra_args
    # Each board will have a differernt output so this test just sanity
    # checks the commands do not fail. The output cannot really be tested easily
    subprocess.run(subproc_cmd, check=True, capture_output=True)
    subprocess.run(subproc_cmd + ["--hex"], check=True, capture_output=True)


# pylint: disable=redefined-outer-name
def test_zsg_read(zsg_read_args, atm_read_extra_args):
    """Tests zsg subcmd: read."""
    # Verify that the command fails without the proper flags
    with pytest.raises((subprocess.CalledProcessError, FileNotFoundError)):
        subprocess.run(zsg_read_args, check=True, capture_output=True)
    subproc_cmd = zsg_read_args + atm_read_extra_args
    subprocess.run(subproc_cmd, check=True, capture_output=True)


# pylint: disable=redefined-outer-name
def test_zsg_show(zsg_show_args, atm_show_extra_args):
    """Tests zsg subcmd: show"""
    # Verify that the command fails without the proper flags
    with pytest.raises((subprocess.CalledProcessError, FileNotFoundError)):
        subprocess.run(zsg_show_args, check=True, capture_output=True)
    subproc_cmd = zsg_show_args + atm_show_extra_args
    subprocess.run(subproc_cmd + ["-s", "show_pretty"], check=True, capture_output=True)
    subprocess.run(
        subproc_cmd + ["-s", "show_verbose"], check=True, capture_output=True
    )


# pylint: disable=redefined-outer-name
def test_zsg_dump(zsg_dump_args, zsg_dump_extra_args):
    """Tests zsg subcmd: dump."""
    # Verify that the command fails without the proper flags
    with pytest.raises((subprocess.CalledProcessError, FileNotFoundError)):
        subprocess.run(zsg_dump_args, check=True, capture_output=True)
    subproc_cmd = zsg_dump_args + zsg_dump_extra_args
    subprocess.run(subproc_cmd, check=True, capture_output=True)


# pylint: disable=redefined-outer-name
def test_zsg_scan(zsg_scan_args, zsg_scan_extra_args):
    """Tests zsg subcmd: scan."""
    # Verify that the command fails without the proper flags
    with pytest.raises((subprocess.CalledProcessError, FileNotFoundError)):
        subprocess.run(zsg_scan_args, check=True, capture_output=True)
    subproc_cmd = zsg_scan_args + zsg_scan_extra_args
    subprocess.run(subproc_cmd, check=True, capture_output=True)


@pytest.fixture()
def atm_write_extra_args():
    """Tests zsg extra argument: write."""
    env_mapping = {
        "PARTITION_FILE": "-p",
        "PARTITION_TYPE": "-t",
        "INPUT_FILE": "-i",
        "OUTPUT_FILE": "-o",
        "OBJCOPY_FILE": "-obj",
    }
    return _build_args_from_env(env_mapping)


@pytest.fixture()
def atm_read_extra_args():
    """Tests zsg extra argument: read."""
    env_mapping = {
        "PARTITION_FILE": "-p",
        "PARTITION_TYPE": "-t",
        "INPUT_FILE": "-i",
        "OUTPUT_FILE": "-o",
    }
    return _build_args_from_env(env_mapping)


@pytest.fixture()
def atm_show_extra_args():
    """Tests zsg extra argument: show."""
    env_mapping = {"PARTITION_FILE": "-p", "PARTITION_TYPE": "-t", "INPUT_FILE": "-i"}
    return _build_args_from_env(env_mapping)


@pytest.fixture()
def zsg_dump_extra_args():
    """Tests zsg extra argument: dump."""
    env_mapping = {
        "BOARD": "--board",
        "JLINK_SERIAL": "--device",
        "OPENOCD_CFG": "--openocd_config",
        "SUPPORT_JLINK": ["--jlink"],
        "PARTITION_FILE": "-p",
        "PARTITION_TYPE": "-t",
        "OUTPUT_FILE": "-o",
    }
    return _build_args_from_env(env_mapping)


@pytest.fixture()
def atm_scan_extra_args():
    """Tests zsg extra argument: scan."""
    env_mapping = {
        "PARTITION_FILE": "-p",
        "PARTITION_TYPE": "-t",
        "INPUT_FILE": "-i",
    }
    return _build_args_from_env(env_mapping)
