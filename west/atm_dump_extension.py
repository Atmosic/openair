#!/usr/bin/env python
# Copyright (C) Atmosic 2025-2026
#
# SPDX-License-Identifier: LicenseRef-Atmosic

"""
@file atm_dump_extension.py

@brief West extension for dumping binary data.
"""

from textwrap import dedent
import os
import sys

sys.path.append(
    os.path.join(
        os.path.dirname(os.path.dirname(os.path.abspath(__file__))), "tools", "scripts"
    )
)
# pylint: disable=wrong-import-position,import-error
import atm_openocd

from west.commands import WestCommand  # pylint: disable=import-error,no-name-in-module


class AtmDumpCommand(WestCommand):
    """West extension command for dumping binary data from device."""

    def __init__(self):
        super().__init__(
            "dump",  # gets stored as self.name
            "Dump binary data from device",  # self.help
            # self.description:
            dedent(
                """
                Dump binary data from device
                """
            ),
        )
        self.openocd = None

    def do_add_parser(self, parser_adder):
        """Function add west dump parser"""
        parser = parser_adder.add_parser(
            self.name, help=self.help, description=self.description
        )
        parser.add_argument(
            "--jlink", required=False, action="store_true", help="if using JLINK"
        )
        parser.add_argument(
            "--dl", required=False, action="store_true", help="if using DL Board"
        )
        parser.add_argument(
            "--rram", required=False, action="store_true", help="if using RRAM"
        )
        parser.add_argument(
            "--device",
            required=True,
            help="selects FTDI interface, e.g: ATRDIxxxx, or JLINK, or ATMDLxxxx",
        )
        parser.add_argument(
            "--board",
            required=True,
            help="board to build for with optional board revision",
        )
        parser.add_argument(
            "--openocd_config",
            required=False,
            help="Specifies the config file for openocd",
        )
        parser.add_argument(
            "-o", "--output_file", required=True, default=None, help="output file path"
        )
        parser.add_argument(
            "--start_addr", required=True, help="start address to dump data from"
        )
        parser.add_argument("--size", required=True, help="size of data to dump")
        parser.add_argument(
            "--offset_addr", required=False, help="offset address of output file"
        )
        return parser

    def dump_flash_data(self, args):
        """Pulls flash data from device"""
        print(f"call dump_flash_data args: {args}")
        start_addr = args.start_addr
        size = args.size
        try:
            self.openocd.reset_target()
            cmd_ret, _, stderr = self.openocd.execute_cmd(
                [f"atm_dump_flash {args.output_file} {size} {start_addr}"]
            )
            print(f"atm_dump_flash {args.output_file} {size} {start_addr}")
            if cmd_ret != 0:
                print(f"{stderr}")
            else:
                # If offset is set, prepend 0xFF data before the dumped data
                if args.offset_addr and os.path.exists(args.output_file):
                    with open(args.output_file, "rb") as file_handle:
                        data = file_handle.read()
                    padding_len = int(
                        args.offset_addr, 0
                    )  # Support hex (0x) and decimal
                    with open(args.output_file, "wb") as file_handle:
                        file_handle.write(b"\xff" * padding_len)
                        file_handle.write(data)
            return cmd_ret
        except RuntimeError as exc:
            print(f"Execute dump_flash_data failed: {exc}")
            sys.exit(1)

    def dump_rram_data(self, args):
        """Pulls rram data from device"""
        print(f"Call dump_rram_data args: {args}")
        start_addr = args.start_addr
        size = args.size
        try:
            self.openocd.reset_target()
            cmd_ret, _, stderr = self.openocd.execute_cmd(
                [f"atm_dump_nvds {args.output_file} {start_addr} " f"{size}"]
            )
            print(f"atm_dump_nvds {args.output_file} {start_addr} {size}")
            if cmd_ret != 0:
                print(f"{stderr}")
            else:
                # If offset is set, prepend 0xFF data before the dumped data
                if args.offset_addr and os.path.exists(args.output_file):
                    with open(args.output_file, "rb") as file_handle:
                        data = file_handle.read()
                    padding_len = int(
                        args.offset_addr, 0
                    )  # Support hex (0x) and decimal
                    with open(args.output_file, "wb") as file_handle:
                        file_handle.write(b"\xff" * padding_len)
                        file_handle.write(data)
            return cmd_ret
        except RuntimeError as exc:
            print(f"Execute dump_rram_data failed: {exc}")
            sys.exit(1)

    def do_run(self, args, unknown_args):  # pylint: disable=unused-argument
        """Execute the dump command.

        Args:
            args: Parsed command line arguments
            unknown_args: Unknown arguments (unused)
        """
        try:
            self.openocd = atm_openocd.AtmOpenOCD(
                args.board,
                args.device,
                args.jlink,
                args.dl,
                openocd_cfg=args.openocd_config,
            )
        except Exception:  # pylint: disable=broad-exception-caught
            print("Invalid configuration. Please use supported device")
            sys.exit(1)

        if args.rram:
            self.dump_rram_data(args)
        else:
            self.dump_flash_data(args)
