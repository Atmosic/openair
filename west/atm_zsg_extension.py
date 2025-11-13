#!/usr/bin/env python
"""
@file atm_zsg_extension.py

Handles generation, reading, display, and dumping of binary flash images
for the Zephyr Settings Subsystem using the NVS backend.

Copyright (C) Atmosic 2025
"""

import os
import sys
import platform
import subprocess
from dataclasses import dataclass
from pathlib import Path

sys.path.append(
    os.path.join(
        os.path.dirname(os.path.dirname(os.path.abspath(__file__))), "tools", "scripts"
    )
)
# pylint: disable=wrong-import-position,disable=import-error
import atm_openocd

# pylint: disable=import-error,no-name-in-module
from west.commands import WestCommand


@dataclass
class AtmSettingsInfo:
    """Holds information about storage and factory data layout."""

    storage_data_start: str = None
    storage_data_size: str = None
    factory_data_start: str = None
    factory_data_size: str = None
    erase_block_size: str = None


class AtmZsgCommand(WestCommand):
    """Class representing west zsg command"""

    def __init__(self):
        super().__init__(
            "zsg",
            # Keep this in sync with the string in west-commands.yml.
            "Atmosic zsg tool required files and info",
            "Atmosic zsg tool required files and info",
        )
        self.part_sector_size = None
        self.part_start = None
        self.part_size = None
        self.zsg_full_path = None
        self.openocd = None
        self.part_type = None

    def create_default_subparser(self, subparsers, subcmd_str, help_str):
        """adds subparser with default arguments.

        Args:
            subparsers : subparser object
            subcmd_str (str): name of sub command
            help_str (str): help string
        """
        s_parser = subparsers.add_parser(subcmd_str, help=help_str)
        s_parser.add_argument(
            "-p",
            "--partition_file",
            required=True,
            default=None,
            help="partition info file path",
        )
        s_parser.set_defaults(subcmd=subcmd_str)
        return s_parser

    def do_add_parser(self, parser_adder):
        """Function add west zsg parser"""
        parser = parser_adder.add_parser(
            self.name, help=self.help, description=self.description
        )
        subparsers = parser.add_subparsers(help="sub-command to run", required=True)

        write_parser = self.create_default_subparser(
            subparsers,
            "write",
            "To generate binary string data to the settings storage area",
        )
        write_parser.add_argument(
            "-i", "--input_file", required=True, default=None, help="input file path"
        )
        write_parser.add_argument(
            "-o", "--output_file", required=True, default=None, help="output file path"
        )
        write_parser.add_argument(
            "-t",
            "--partition_type",
            required=True,
            default=None,
            help="Type of Zephyr subsystem storage (e.g., factory or settings)",
        )
        write_parser.add_argument(
            "-obj", "--objcopy_file", required=False, help="objcopy exe file path"
        )
        write_parser.add_argument(
            "--hex",
            default=False,
            required=False,
            action="store_true",
            help="Convert the bin file to hex",
        )

        read_parser = self.create_default_subparser(
            subparsers,
            "read",
            "Read NVS information from a bin file and save it to a YAML file",
        )
        read_parser.add_argument(
            "-i", "--input_file", required=True, default=None, help="input file path"
        )
        read_parser.add_argument(
            "-o", "--output_file", required=True, default=None, help="output file path"
        )
        read_parser.add_argument(
            "-t",
            "--partition_type",
            required=True,
            default=None,
            help="Type of Zephyr subsystem storage (e.g., factory or settings)",
        )

        show_parser = self.create_default_subparser(
            subparsers, "show", "Show NVS information from a bin file"
        )
        show_parser.add_argument(
            "-i", "--input_file", required=True, default=None, help="input file path"
        )
        show_parser.add_argument(
            "-t",
            "--partition_type",
            required=True,
            default=None,
            help="Type of Zephyr subsystem storage (e.g., factory or settings)",
        )
        show_parser.add_argument(
            "-s",
            "--style",
            required=True,
            choices=["show_verbose", "show_pretty"],
            help="display output using the specified style",
        )

        dump_parser = self.create_default_subparser(
            subparsers, "dump", "Dump bin file from device"
        )
        dump_parser.add_argument(
            "--jlink", required=False, action="store_true", help="if using JLINK"
        )
        dump_parser.add_argument(
            "--dl", required=False, action="store_true", help="if using DL Board"
        )
        dump_parser.add_argument(
            "--device",
            required=True,
            help="selects FTDI interface, e.g: ATRDIxxxx, or JLINK",
        )
        dump_parser.add_argument(
            "--board",
            required=True,
            help="board to build for with optional board revision",
        )
        dump_parser.add_argument(
            "--openocd_config",
            required=False,
            help="Specifies the config file for openocd",
        )
        dump_parser.add_argument(
            "-o", "--output_file", required=True, default=None, help="output file path"
        )
        dump_parser.add_argument(
            "-t",
            "--partition_type",
            required=True,
            default=None,
            help="Type of Zephyr subsystem storage (e.g., factory or settings)",
        )

        scan_parser = self.create_default_subparser(
            subparsers, "scan", "lists all ATEs with validity"
        )
        scan_parser.add_argument(
            "-i", "--input_file", required=True, default=None, help="input file path"
        )
        scan_parser.add_argument(
            "-t",
            "--partition_type",
            required=True,
            default=None,
            help="Type of Zephyr subsystem storage (e.g., factory or settings)",
        )
        return parser

    def exe_cmd(self, cmd):
        """Function execute command"""
        try:
            result = subprocess.run(cmd, shell=True, check=True)
            return result.returncode
        except subprocess.CalledProcessError as exc:
            raise RuntimeError(
                f"Command [{cmd}] failed with status "
                f"[{exc.returncode}]. Error: "
                f"{exc.stderr}"
            ) from exc

    def pull_subsystem_data(self, args):
        """Pulls subsystem data from device"""
        try:
            self.openocd.reset_target()
            cmd_ret, _, stderr = self.openocd.execute_cmd(
                [
                    f"atm_dump_flash {args.output_file} {self.part_size} "
                    f"{self.part_start}"
                ]
            )
            if cmd_ret != 0:
                print(f"{stderr}")
            return cmd_ret
        except RuntimeError as exc:
            print(f"Execute pull_subsystem_data failed: {exc}")
            sys.exit(1)

    def parse_settings_info(self, filename):
        """Parse the settings file and return an AtmSettingsInfo object."""
        info = AtmSettingsInfo()
        with open(filename, "r", encoding="utf-8") as file_obj:
            lines = file_obj.readlines()

        for line in lines:
            if "=" in line:
                key, value = line.strip().split("=")
                if key == "STORAGE_DATA_START":
                    info.storage_data_start = value
                elif key == "STORAGE_DATA_SIZE":
                    info.storage_data_size = value
                elif key == "FACTORY_DATA_START":
                    info.factory_data_start = value
                elif key == "FACTORY_DATA_SIZE":
                    info.factory_data_size = value
                elif key == "ERASE_BLOCK_SIZE":
                    info.erase_block_size = value
        return info

    def do_run(self, args, _unknown_args):
        """Function do run west atm_zsg"""
        if not os.path.exists(args.partition_file):
            print(f"{args.partition_file} not exist")
            sys.exit(1)

        # Get partition info
        info = self.parse_settings_info(args.partition_file)
        self.part_sector_size = int(info.erase_block_size, 16)
        if "settings" in args.partition_type.lower():
            if (
                info.storage_data_start is not None
                and info.storage_data_size is not None
            ):
                self.part_start = info.storage_data_start
                self.part_size = int(info.storage_data_size, 16)
            else:
                print("The storage information in partition_info.map is empty.")
                sys.exit(1)
        elif "factory" in args.partition_type.lower():
            if (
                info.factory_data_start is not None
                and info.factory_data_size is not None
            ):
                self.part_start = info.factory_data_start
                self.part_size = int(info.factory_data_size, 16)
            else:
                print("The factory information in partition_info.map is empty.")
                sys.exit(1)
        else:
            print("Unknown partition_type!!")
            sys.exit(1)

        # Check if partition_type is settings_all or factory_all
        if "all" in args.partition_type.lower():
            self.part_type = "ALL"
        else:
            self.part_type = args.partition_type

        # Get zsg tool path and verify it exists on the filesystem.
        zsg_tool_path = os.path.join(
            str(Path(__file__).resolve().parents[2]),
            "modules",
            "hal",
            "atmosic_lib",
            "tools",
            "zsg",
        )
        if sys.platform == "win32":
            self.zsg_full_path = os.path.join(zsg_tool_path, "Windows_NT", "zsg.exe")
        elif sys.platform == "linux":
            self.zsg_full_path = os.path.join(zsg_tool_path, "Linux", "zsg")
        elif sys.platform == "darwin":
            architecture = platform.machine()
            if architecture == "x86_64":
                self.zsg_full_path = os.path.join(zsg_tool_path, "Darwin_x86_64", "zsg")
            elif architecture == "arm64":
                self.zsg_full_path = os.path.join(zsg_tool_path, "Darwin_arm64", "zsg")
            else:
                raise RuntimeError(
                    f"Unsupported Darwin architecture: " f"{architecture}"
                )
        else:
            raise RuntimeError(f"Unsupported platform: {sys.platform}")

        # Verify the zsg tool exists
        if not os.path.exists(self.zsg_full_path):
            raise RuntimeError(f"ZSG tool not found at: {self.zsg_full_path}")

        subcmd = getattr(self, args.subcmd)
        subcmd(args)

    def write(self, args):
        """To generate binary string data to the settings storage area

        Args:
            args: args passed at the command line
        """
        if not args.input_file:
            print("Required input_file")
            sys.exit(1)
        if not os.path.exists(args.input_file):
            print(f"{args.input_file} not exist")
            sys.exit(1)

        cmd = (
            f"{self.zsg_full_path} write {args.input_file} "
            f"{self.part_sector_size} {self.part_size} {args.output_file}"
        )
        try:
            self.exe_cmd(cmd)
        except RuntimeError as exc:
            print(f"Execute [{cmd}] failed: {exc}")
            sys.exit(1)

        if not os.path.exists(args.output_file):
            print(f"{self.part_type}.bin file not exist.")
            sys.exit(1)

        # Convert .bin file to .hex file
        if args.hex:
            if not args.objcopy_file or not os.path.exists(args.objcopy_file):
                print(f"{args.objcopy_file} not exist")
                sys.exit(1)
            hex_path = os.path.splitext(args.output_file)[0] + ".hex"
            cmd = (
                f"{args.objcopy_file} --change-addresses {self.part_start} "
                f"-I binary -O ihex {args.output_file} {hex_path}"
            )
            try:
                self.exe_cmd(cmd)
            except RuntimeError as exc:
                print(f"Execute convert .hex file command failed: {exc}")
                sys.exit(1)
            if not os.path.exists(hex_path):
                print(f"Convert {hex_path} file failed")
                sys.exit(1)

    def read(self, args):
        """Read NVS information from a bin file and save it to a YAML file

        Args:
            args: args passed at the command line
        """
        if not args.input_file:
            print("Required input_file")
            sys.exit(1)
        if not os.path.exists(args.input_file):
            print(f"{args.input_file} not exist")
            sys.exit(1)

        cmd = (
            f"{self.zsg_full_path} read {args.input_file} "
            f"{self.part_type} {self.part_sector_size} "
            f"{self.part_size} {args.output_file}"
        )
        try:
            self.exe_cmd(cmd)
        except RuntimeError as exc:
            print(f"Execute [{cmd}] failed: {exc}")
            sys.exit(1)

        if not os.path.exists(args.output_file):
            print(f"{self.part_type}.yml file not exist.")
            sys.exit(1)

    def show(self, args):
        """Show NVS information from a bin file

        Args:
            args: args passed at the command line
        """
        if not args.input_file:
            print("Required input_file")
            sys.exit(1)
        if not os.path.exists(args.input_file):
            print(f"{args.input_file} not exist")
            sys.exit(1)
        if args.style not in ("show_pretty", "show_verbose"):
            print("Unknown display style!")
            sys.exit(1)

        cmd = (
            f"{self.zsg_full_path} show {args.input_file} "
            f"{self.part_type} {self.part_sector_size} "
            f"{self.part_size} {args.style}"
        )
        try:
            self.exe_cmd(cmd)
        except RuntimeError as exc:
            print(f"Execute [{cmd}] failed: {exc}")
            sys.exit(1)

    def dump(self, args):
        """Dump bin file from device

        Args:
            args: args passed at the command line
        """
        try:
            self.openocd = atm_openocd.AtmOpenOCD(
                args.board,
                args.device,
                args.jlink,
                args.dl,
                openocd_cfg=args.openocd_config,
            )
        except Exception as exc:
            print("Invalid configuration. Please use supported device")
            sys.exit(1)
        self.pull_subsystem_data(args)

    def scan(self, args):
        """lists all ATEs with validity

        Args:
            args: args passed at the command line
        """
        if not args.input_file:
            print("Required input_file")
            sys.exit(1)
        if not os.path.exists(args.input_file):
            print(f"{args.input_file} not exist")
            sys.exit(1)

        cmd = (
            f"{self.zsg_full_path} scan {args.input_file} "
            f"{self.part_sector_size} {self.part_size}"
        )
        try:
            self.exe_cmd(cmd)
        except RuntimeError as exc:
            print(f"Execute [{cmd}] failed: {exc}")
            sys.exit(1)
