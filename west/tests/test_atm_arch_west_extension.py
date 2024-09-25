'''
@file test_atm_arch_west_extension.py

@brief Unit test for atm_arch west extension

Copyright (c) Atmosic 2024
'''

import os
import subprocess
import sys
import pytest


@pytest.fixture
def atm_arch_base_cmd():
    return ["west", "atm_arch"]


@pytest.fixture()
def atm_arch_show_args(atm_arch_base_cmd):
    return atm_arch_base_cmd + ["--show"]


@pytest.fixture()
def atm_arch_show_extra_args(atm_arch_base_cmd):
    assert os.environ.get('ATM_ISP_FILE') is not None
    assert os.environ.get('INPUT_ATM_FILE') is not None
    return ['--atm_isp_path', os.environ.get('ATM_ISP_PATH'),
            '--input_atm_file', os.environ.get('INPUT_ATM_FILE')]


@pytest.fixture()
def atm_arch_burn_args(atm_arch_base_cmd):
    return atm_arch_base_cmd + ["--burn"]


@pytest.fixture()
def atm_arch_burn_extra_args():
    assert os.environ.get('ATM_ISP_FILE') is not None
    assert os.environ.get('OPENOCD_PKG_ROOT') is not None
    assert os.environ.get('INPUT_ATM_FILE') is not None
    return ['--atm_isp_path', os.environ.get('ATM_ISP_PATH'),
            '--input_atm_file', os.environ.get('INPUT_ATM_FILE'),
            '--openocd_pkg_root', os.environ.get('OPENOCD_PKG_ROOT')]


@pytest.fixture()
def atm_arch_create_args(atm_arch_base_cmd):
    return atm_arch_base_cmd


@pytest.fixture()
def atm_arch_create_extra_args():
    assert os.environ.get('ATM_ISP_FILE') is not None
    assert os.environ.get('PATITION_INFO_FILE') is not None
    assert os.environ.get('OUTPUT_ATM_FILE') is not None
    return ['--atm_isp_path', os.environ.get('ATM_ISP_PATH'),
            '--partition_info_file', os.environ.get('PATITION_INFO_FILE'),
            '--output_atm_file', os.environ.get('OUTPUT_ATM_FILE')]


@pytest.fixture()
def atm_arch_append_args(atm_arch_base_cmd):
    return atm_arch_base_cmd + ["--append"]


@pytest.fixture()
def atm_arch_append_extra_args():
    extra_args = []
    assert os.environ.get('ATM_ISP_FILE') is not None
    extra_args.append('--atm_isp_path')
    extra_args.append(os.environ.get('ATM_ISP_FILE'))
    assert os.environ.get('INPUT_ATM_FILE') is not None
    extra_args.append('--input_atm_file')
    extra_args.append(os.environ.get('OUTPUT_ATM_FILE'))
    assert os.environ.get('PATITION_INFO_FILE') is not None
    extra_args.append('--partition_info_file')
    extra_args.append(os.environ.get('PATITION_INFO_FILE'))
    assert os.environ.get('OUTPUT_ATM_FILE') is not None
    extra_args.append('--output_atm_file')
    extra_args.append(os.environ.get('OUTPUT_ATM_FILE'))
    if os.environ.get('NVDS_FILE') is not None:
        extra_args.append('--nvds_file')
        extra_args.append(os.environ.get('NVDS_FILE'))
    if os.environ.get('FACTORY_DATA_FILE') is not None:
        extra_args.append('--factory_data_file')
        extra_args.append(os.environ.get('FACTORY_DATA_FILE'))
    if os.environ.get('SPE_FILE') is not None:
        extra_args.append('--spe_file')
        extra_args.append(os.environ.get('SPE_FILE'))
    if os.environ.get('APP_FILE') is not None:
        extra_args.append('--app_file')
        extra_args.append(os.environ.get('APP_FILE'))
    if os.environ.get('MCUBOOT_FILE') is not None:
        extra_args.append('--mcuboot_file')
        extra_args.append(os.environ.get('MCUBOOT_FILE'))
    if os.environ.get('ATMWSTK_FILE') is not None:
        extra_args.append('--atmwstk_file')
        extra_args.append(os.environ.get('ATMWSTK_FILE'))
    return extra_args


def test_atm_arch_show(atm_arch_show_args, atm_arch_show_extra_args):
    '''Tests atm_arch subcmd: show.'''
    # show contents of file
    with pytest.raises(Exception):
        subprocess.run(atm_arch_show_args,
                       check=True,
                       capture_output=True)
    subproc_cmd = atm_arch_show_args + atm_arch_show_extra_args
    # test just sanity checks the commands do not fail.
    subprocess.run(subproc_cmd,
                   check=True,
                   capture_output=True)


def test_atm_arch_burn(atm_arch_burn_args, atm_arch_burn_extra_args):
    '''Tests atm_arch subcmd: burn.'''
    # show contents of file
    with pytest.raises(Exception):
        subprocess.run(atm_arch_show_args,
                       check=True,
                       capture_output=True)
    subproc_cmd = atm_arch_burn_args + atm_arch_burn_extra_args
    # test just sanity checks the commands do not fail.
    subprocess.run(subproc_cmd,
                   check=True,
                   capture_output=True)


def test_atm_arch_create(atm_arch_create_args, atm_arch_create_extra_args):
    '''Tests atm_arch subcmd: create.'''
    # show contents of file
    with pytest.raises(Exception):
        subprocess.run(atm_arch_show_args,
                       check=True,
                       capture_output=True)
    subproc_cmd = atm_arch_create_args + atm_arch_create_extra_args
    # test just sanity checks the commands do not fail.
    subprocess.run(subproc_cmd,
                   check=True,
                   capture_output=True)


def test_atm_arch_append(atm_arch_append_args, atm_arch_append_extra_args):
    '''Tests atm_arch subcmd: append.'''
    # show contents of file
    with pytest.raises(Exception):
        subprocess.run(atm_arch_show_args,
                       check=True,
                       capture_output=True)
    subproc_cmd = atm_arch_append_args + atm_arch_append_extra_args
    # test just sanity checks the commands do not fail.
    subprocess.run(subproc_cmd,
                   check=True,
                   capture_output=True)
