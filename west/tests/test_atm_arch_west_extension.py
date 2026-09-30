# Copyright (c) Atmosic 2024-2026
#
# SPDX-License-Identifier: LicenseRef-Atmosic

"""
@file test_atm_arch_west_extension.py

@brief Unit test for atm_arch west extension
"""

import os
import subprocess
from pathlib import Path

import pytest


@pytest.fixture(name="atm_arch_base_cmd")
def atm_arch_base_command():
    """Return the base command used by atm_arch subprocess tests."""
    return ["west", "atm_arch"]


@pytest.fixture()
def atm_arch_show_args(atm_arch_base_cmd):
    return atm_arch_base_cmd + ["--show"]


@pytest.fixture()
def atm_arch_show_extra_args(atm_arch_base_cmd):
    assert os.environ.get("ATM_ISP_FILE") is not None
    assert os.environ.get("INPUT_ATM_FILE") is not None
    return [
        "--atm_isp_path",
        os.environ.get("ATM_ISP_PATH"),
        "--input_atm_file",
        os.environ.get("INPUT_ATM_FILE"),
    ]


@pytest.fixture()
def atm_arch_burn_args(atm_arch_base_cmd):
    return atm_arch_base_cmd + ["--burn"]


@pytest.fixture()
def atm_arch_burn_extra_args():
    assert os.environ.get("ATM_ISP_FILE") is not None
    assert os.environ.get("OPENOCD_PKG_ROOT") is not None
    assert os.environ.get("INPUT_ATM_FILE") is not None
    return [
        "--atm_isp_path",
        os.environ.get("ATM_ISP_PATH"),
        "--input_atm_file",
        os.environ.get("INPUT_ATM_FILE"),
        "--openocd_pkg_root",
        os.environ.get("OPENOCD_PKG_ROOT"),
    ]


@pytest.fixture()
def atm_arch_create_args(atm_arch_base_cmd):
    return atm_arch_base_cmd


@pytest.fixture()
def atm_arch_create_extra_args():
    assert os.environ.get("ATM_ISP_FILE") is not None
    assert os.environ.get("PATITION_INFO_FILE") is not None
    assert os.environ.get("OUTPUT_ATM_FILE") is not None
    return [
        "--atm_isp_path",
        os.environ.get("ATM_ISP_PATH"),
        "--partition_info_file",
        os.environ.get("PATITION_INFO_FILE"),
        "--output_atm_file",
        os.environ.get("OUTPUT_ATM_FILE"),
    ]


@pytest.fixture()
def atm_arch_append_args(atm_arch_base_cmd):
    return atm_arch_base_cmd + ["--append"]


@pytest.fixture()
def atm_arch_append_extra_args():
    extra_args = []
    assert os.environ.get("ATM_ISP_FILE") is not None
    extra_args.append("--atm_isp_path")
    extra_args.append(os.environ.get("ATM_ISP_FILE"))
    assert os.environ.get("INPUT_ATM_FILE") is not None
    extra_args.append("--input_atm_file")
    extra_args.append(os.environ.get("OUTPUT_ATM_FILE"))
    assert os.environ.get("PATITION_INFO_FILE") is not None
    extra_args.append("--partition_info_file")
    extra_args.append(os.environ.get("PATITION_INFO_FILE"))
    assert os.environ.get("OUTPUT_ATM_FILE") is not None
    extra_args.append("--output_atm_file")
    extra_args.append(os.environ.get("OUTPUT_ATM_FILE"))
    if os.environ.get("STORAGE_DATA_FILE") is not None:
        extra_args.append("--storage_data_file")
        extra_args.append(os.environ.get("STORAGE_DATA_FILE"))
    if os.environ.get("FACTORY_DATA_FILE") is not None:
        extra_args.append("--factory_data_file")
        extra_args.append(os.environ.get("FACTORY_DATA_FILE"))
    if os.environ.get("SPE_FILE") is not None:
        extra_args.append("--spe_file")
        extra_args.append(os.environ.get("SPE_FILE"))
    if os.environ.get("APP_FILE") is not None:
        extra_args.append("--app_file")
        extra_args.append(os.environ.get("APP_FILE"))
    if os.environ.get("MCUBOOT_FILE") is not None:
        extra_args.append("--mcuboot_file")
        extra_args.append(os.environ.get("MCUBOOT_FILE"))
    if os.environ.get("ATMWSTK_FILE") is not None:
        extra_args.append("--atmwstk_file")
        extra_args.append(os.environ.get("ATMWSTK_FILE"))
    return extra_args


def test_atm_arch_show(atm_arch_show_args, atm_arch_show_extra_args):
    """Tests atm_arch subcmd: show."""
    # show contents of file
    with pytest.raises(Exception):
        subprocess.run(atm_arch_show_args, check=True, capture_output=True)
    subproc_cmd = atm_arch_show_args + atm_arch_show_extra_args
    # test just sanity checks the commands do not fail.
    subprocess.run(subproc_cmd, check=True, capture_output=True)


def test_atm_arch_burn(atm_arch_burn_args, atm_arch_burn_extra_args):
    """Tests atm_arch subcmd: burn."""
    # show contents of file
    with pytest.raises(Exception):
        subprocess.run(atm_arch_show_args, check=True, capture_output=True)
    subproc_cmd = atm_arch_burn_args + atm_arch_burn_extra_args
    # test just sanity checks the commands do not fail.
    subprocess.run(subproc_cmd, check=True, capture_output=True)


def test_atm_arch_create(atm_arch_create_args, atm_arch_create_extra_args):
    """Tests atm_arch subcmd: create."""
    # show contents of file
    with pytest.raises(Exception):
        subprocess.run(atm_arch_show_args, check=True, capture_output=True)
    subproc_cmd = atm_arch_create_args + atm_arch_create_extra_args
    # test just sanity checks the commands do not fail.
    subprocess.run(subproc_cmd, check=True, capture_output=True)


def test_atm_arch_append(atm_arch_append_args, atm_arch_append_extra_args):
    """Tests atm_arch subcmd: append."""
    # show contents of file
    with pytest.raises(Exception):
        subprocess.run(atm_arch_show_args, check=True, capture_output=True)
    subproc_cmd = atm_arch_append_args + atm_arch_append_extra_args
    # test just sanity checks the commands do not fail.
    subprocess.run(subproc_cmd, check=True, capture_output=True)


def test_atm_arch_accepts_repeated_erase_options(atm_arch_base_cmd, tmp_path):
    """The west command archives repeated erase options before programming."""
    partition_info = tmp_path / "partition_info.map"
    partition_info.write_text(
        "\n".join(
            [
                "PLATFORM_FAMILY=atm33",
                "PLATFORM_NAME=ATM33xx-5",
                "BOARD=TEST_BOARD",
                "RRAM_START=0x10000",
                "RRAM_SIZE=0x100000",
                "EXT_FLASH_START=0x200000",
                "EXT_FLASH_SIZE=0x400000",
                "APP_START=0x20000",
                "APP_SIZE=0x1000",
            ]
        ),
        encoding="utf-8",
    )
    app_file = tmp_path / "app.bin"
    app_file.write_bytes(b"test image")
    output_file = tmp_path / "output.atm"

    create_cmd = atm_arch_base_cmd + [
        "--partition_info_file",
        str(partition_info),
        "--output_atm_file",
        str(output_file),
        "--app_file",
        str(app_file),
        "--erase_flash=0x200000,0x1000",
        "--erase_flash=0x201000,0x1000",
        "--erase_rram=0x70000,0x100",
        "--erase_rram=0x71000,0x100",
    ]
    subprocess.run(create_cmd, check=True, capture_output=True, text=True)

    show_cmd = atm_arch_base_cmd + [
        "--show",
        "--input_atm_file",
        str(output_file),
    ]
    result = subprocess.run(show_cmd, check=True, capture_output=True, text=True)
    archive_commands = [
        line
        for line in result.stdout.splitlines()
        if line.startswith(("EraseFlash", "EraseRram", "LoadRram"))
    ]

    assert [line.split()[0] for line in archive_commands] == [
        "EraseFlash",
        "EraseFlash",
        "EraseRram",
        "EraseRram",
        "LoadRram",
    ]

    openocd_pkg_root = Path(__file__).resolve().parents[2] / "modules" / "hal_atmosic"
    burn_dir = tmp_path / "burn"
    burn_cmd = atm_arch_base_cmd + [
        "--burn",
        "--input_atm_file",
        str(output_file),
        "--openocd_pkg_root",
        str(openocd_pkg_root),
        "--dst_dir",
        str(burn_dir),
    ]
    subprocess.run(burn_cmd, check=True, capture_output=True, text=True)
    burn_commands = [
        line.split()
        for line in (burn_dir / "atm.tcl").read_text(encoding="utf-8").splitlines()
        if line.startswith("atm_fast_load")
    ]
    assert [command[2] for command in burn_commands] == [
        "0x2",
        "0x2",
        "0x2",
        "0x2",
        "0x1",
    ]


def test_atm_arch_atm5_fast_load_uses_revision_path(atm_arch_base_cmd, tmp_path):
    """The ATM5 fast-load binary is resolved below the revision directory."""
    partition_info = tmp_path / "partition_info.map"
    partition_info.write_text(
        "\n".join(
            [
                "PLATFORM_FAMILY=atm5",
                "PLATFORM_NAME=ATM5xxx-2",
                "BOARD=TEST_BOARD",
                "RRAM_START=0x10000",
                "RRAM_SIZE=0x100000",
                "APP_START=0x20000",
                "APP_SIZE=0x1000",
            ]
        ),
        encoding="utf-8",
    )
    app_file = tmp_path / "app.bin"
    app_file.write_bytes(b"test image")
    output_file = tmp_path / "output.atm"
    subprocess.run(
        atm_arch_base_cmd
        + [
            "--partition_info_file",
            str(partition_info),
            "--output_atm_file",
            str(output_file),
            "--app_file",
            str(app_file),
        ],
        check=True,
        capture_output=True,
        text=True,
    )

    openocd_pkg_root = Path(__file__).resolve().parents[2] / "modules" / "hal_atmosic"
    burn_dir = tmp_path / "burn"
    subprocess.run(
        atm_arch_base_cmd
        + [
            "--burn",
            "--input_atm_file",
            str(output_file),
            "--openocd_pkg_root",
            str(openocd_pkg_root),
            "--fast_load",
            "--dst_dir",
            str(burn_dir),
        ],
        check=True,
        capture_output=True,
        text=True,
    )

    fast_load_bin = (
        openocd_pkg_root
        / "ATM5xxx"
        / "rev-2"
        / "openocd"
        / "fast_load"
        / "fast_load.bin"
    )
    script = (burn_dir / "atm.tcl").read_text(encoding="utf-8")
    assert f"atmx3_load_ram_image {{{fast_load_bin}}}" in script
