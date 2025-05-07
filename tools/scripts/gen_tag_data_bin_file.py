#!/usr/bin/env python
"""
@file gen_tag_data_bin_file.py

@Parse the content of partition_info.map and generate tag data bin file

Copyright (C) Atmosic 2024-2025
"""

import sys
import platform
import argparse
import os
import subprocess

class AtmSettingsInfo:
    STORAGE_DATA_START = None
    STORAGE_DATA_SIZE = None
    FACTORY_DATA_START = None
    FACTORY_DATA_SIZE = None
    ERASE_BLOCK_SIZE = None

def parse_settings_info(filename):
    info = AtmSettingsInfo()
    with open(filename, 'r') as f:
        lines = f.readlines()

    for line in lines:
        if "=" in line:
            key, value = line.strip().split("=")
            if key == "STORAGE_DATA_START":
                info.STORAGE_DATA_START = value
            elif key == "STORAGE_DATA_SIZE":
                info.STORAGE_DATA_SIZE = value
            elif key == "FACTORY_DATA_START":
                info.FACTORY_DATA_START = value
            elif key == "FACTORY_DATA_SIZE":
                info.FACTORY_DATA_SIZE = value
            elif key == "ERASE_BLOCK_SIZE":
                info.ERASE_BLOCK_SIZE = value
    return info

def run_with_timeout(command, timeout=None):
    process = subprocess.Popen(command, shell=True, stdout=subprocess.PIPE,
                               stderr=subprocess.PIPE, encoding='utf-8',
                               errors='ignore')
    print(f"run [{command}]")
    try:
        stdout, stderr = process.communicate(timeout=timeout)
        if (stdout):
            return process.returncode
        return process.returncode
    except subprocess.TimeoutExpired:
        print(f"run {command} expired")
        return -1

def parse_args(args=None):
    parser = argparse.ArgumentParser(
        description="Atmosic Zephyr Generate Tag Data Bin File Tool")
    parser.add_argument("-z", "--zsg_tool_path", required=True, default=None,
                        help="zsg tool path")
    parser.add_argument("-t", "--file_type", required=True, default=None,
                        help="bin file type")
    parser.add_argument("-p", "--partition_file", required=True,
                        default=None, help="partition_info.map file path")
    parser.add_argument("-y", "--yaml_file", required=True, default=None,
                        help="tag data yaml file path")
    parser.add_argument("-b", "--bin_file", required=True, default=None,
                        help="tag datab in file path")
    parser.add_argument("-o", "--objcopy_file", required=True, default=None,
                        help="objcopy exe file path")
    return parser.parse_args(args)

def main(args=None):
    args = parse_args(args)
    if not os.path.exists(args.partition_file):
        print(f"{args.partition_file} not exist")
        sys.exit(1)
    if not os.path.exists(args.yaml_file):
        print(f"{args.yaml_file} not exist")
        sys.exit(1)
    if not os.path.exists(args.objcopy_file):
        print(f"{args.objcopy_file} not exist")
        sys.exit(1)

    settings_info = parse_settings_info(args.partition_file)
    zsg_full_path = ""
    if sys.platform == "win32":
        zsg_full_path = os.path.join(args.zsg_tool_path, "Windows_NT",
                                     "zsg.exe")
    elif sys.platform == "linux":
        zsg_full_path = os.path.join(args.zsg_tool_path, "Linux", "zsg")
    elif sys.platform == 'darwin':
        architecture = platform.machine()
        if architecture == 'x86_64':
            zsg_full_path = os.path.join(args.zsg_tool_path, "Darwin_x86_64",
                                         "zsg")
        elif architecture == 'arm64':
            zsg_full_path = os.path.join(args.zsg_tool_path, "Darwin_arm64",
                                         "zsg")

    part_start = ""
    part_size = 0
    part_sector_size = int(settings_info.ERASE_BLOCK_SIZE, 16)
    if args.file_type == "settings":
        part_start = settings_info.STORAGE_DATA_START
        part_size = int(settings_info.STORAGE_DATA_SIZE, 16)
    elif args.file_type == "factory":
        part_start = settings_info.FACTORY_DATA_START
        part_size = int(settings_info.FACTORY_DATA_SIZE, 16)
    else:
        print("Unknow file type!")
        sys.exit(1)

    if os.path.exists(args.bin_file):
        os.remove(args.bin_file)

    # Generate bin file
    cmd = f"{zsg_full_path} write {args.yaml_file} {part_sector_size} " \
          f"{part_size} {args.bin_file}"
    rc = run_with_timeout(cmd)
    if rc != 0:
        print("Execute generate command failed")
        sys.exit(1)

    if not os.path.exists(args.bin_file):
        print(f"Generate {args.file_type}.bin file failed")
        sys.exit(1)

    # Convert .bin file to .hex file
    des_dir = os.path.dirname(args.bin_file)
    hex_name = f"zephyr_{args.file_type}.hex"
    cmd = f"{args.objcopy_file} --change-addresses {part_start} -I binary" \
          f" -O ihex {args.bin_file} {des_dir}/{hex_name}"
    rc = run_with_timeout(cmd)
    if rc != 0:
        print("Execute convert .hex file command failed")
        sys.exit(1)

    if not os.path.exists(hex_name):
        print(f"Convert {hex_name} file failed")
        sys.exit(1)

    print(f"Generate and convert {args.file_type}.bin file successful")

if __name__ == '__main__':
    main()
