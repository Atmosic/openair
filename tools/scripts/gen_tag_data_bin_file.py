#!/usr/bin/env python
"""
@file gen_tag_data_bin_file.py

@Parse the content of partition_info.map and generate tag data bin file

Copyright (C) Atmosic 2024-2025
"""

import sys
import argparse
import os
import subprocess


def run_with_timeout(command, timeout=None):
    """
    Execute a shell command with an optional timeout.

    Args:
        command (str): The shell command to execute.
        timeout (int, optional): The timeout in seconds.
                                 Defaults to None (no timeout).

    Returns:
        int: The return code of the process. Returns -1 if the
             command times out.
    """
    with subprocess.Popen(
        command,
        shell=True,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        encoding="utf-8",
        errors="ignore",
    ) as process:
        print(f"run [{command}]")
        try:
            _, _ = process.communicate(timeout=timeout)
            return process.returncode
        except subprocess.TimeoutExpired:
            print(f"run {command} expired")
            return -1


def parse_args(args=None):
    """
    Parse command-line arguments and convert them into variables.

    This function sets up the argument parser, defines supported arguments,
    and parses them from sys.args. The parsed arguments are returned as an
    object with attributes corresponding to each argument.

    Returns:
        argparse.Namespace: Parsed arguments as object attributes.
    """
    parser = argparse.ArgumentParser(
        description="Atmosic Zephyr Generate Tag Data Bin File Tool"
    )
    parser.add_argument(
        "-t",
        "--partition_type",
        required=True,
        default=None,
        help="Type of Zephyr subsystem " "storage (e.g., factory or settings)",
    )
    parser.add_argument(
        "-p",
        "--partition_file",
        required=True,
        default=None,
        help="partition info file path",
    )
    parser.add_argument(
        "-i", "--input_file", required=True, default=None, help="input file path"
    )
    parser.add_argument(
        "-o", "--output_file", required=False, default=None, help="output file path"
    )
    parser.add_argument(
        "-obj", "--objcopy_file", required=True, help="objcopy exe file path"
    )
    return parser.parse_args(args)


def main(args=None):
    """
    Main entry point of the program that handles argument parsing and execution.

    Functionality includes:
    - Parsing command-line arguments (parse_args)
    - Generating a bin file based on the parsed arguments
    - Running commands with timeout handling (run_with_timeout)

    Args:
        args (list, optional): List of command-line arguments. Defaults to None,
                               which means arguments are read from sys.argv.
    """
    args = parse_args(args)
    if not os.path.exists(args.partition_file):
        print(f"{args.partition_file} not exist")
        sys.exit(1)
    if not os.path.exists(args.input_file):
        print(f"{args.input_file} not exist")
        sys.exit(1)
    if args.output_file and os.path.exists(args.output_file):
        os.remove(args.output_file)
    if args.objcopy_file and not os.path.exists(args.objcopy_file):
        print(f"{args.objcopy_file} not exist")
        sys.exit(1)

    cmd = (
        f"west zsg write -i {args.input_file} -o {args.output_file} "
        f"-p {args.partition_file} -t {args.partition_type} "
        f"-obj {args.objcopy_file} --hex"
    )
    return_code = run_with_timeout(cmd)
    if return_code != 0:
        print("Execute generate command failed")
        sys.exit(1)

    if not os.path.exists(args.output_file):
        print(f"Generate {args.partition_type}.bin file failed")
        sys.exit(1)

    hex_path = os.path.splitext(args.output_file)[0] + ".hex"
    if not os.path.exists(hex_path):
        print(f"Convert {hex_path} file failed")
        sys.exit(1)

    print(f"Generate and convert {args.partition_type}.bin file successful")


if __name__ == "__main__":
    main()
