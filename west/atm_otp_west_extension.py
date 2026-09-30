# Copyright (c) Atmosic 2024-2026
#
# SPDX-License-Identifier: LicenseRef-Atmosic

"""
@file atm_otp_west_extension.py

@brief West extension for managing OTP
"""

import argparse
import importlib.util
import binascii
import os
import sys
import tempfile
from textwrap import dedent

sys.path.append(
    os.path.join(
        os.path.dirname(os.path.dirname(os.path.abspath(__file__))), "tools", "scripts"
    )
)
sys.path.append(
    os.path.join(
        os.path.dirname(os.path.dirname(os.path.abspath(__file__))),
        "tools",
        "scripts",
        "atm_otp",
    )
)
import atm_openocd
import atm_otp_base

from west.commands import WestCommand, Verbosity

from atm_west_utils import wrap_color, TermColors


class AtmOtpCommand(WestCommand):
    def __init__(self):
        super().__init__(
            "atmotp",  # gets stored as self.name
            "Interface with OTP on supported Atmosic chips",  # self.help
            # self.description:
            dedent(
                """
                Interface with OTP on supported chips

                Allows users to read out OTP bits as well as burn them to configure devices.
                """
            ),
        )
        self.atm_otp = None
        self.OTParray = None

    def create_default_subparser(self, subparsers, subcmd_str, help_str):
        """adds subparser with default arguments.

        Args:
            subparsers : subparser object
            subcmd_str (str): name of sub command
            help_str (str): help string
        """
        s_parser = subparsers.add_parser(
            subcmd_str, help=help_str, formatter_class=argparse.RawTextHelpFormatter
        )
        s_parser.add_argument(
            "--jlink", required=False, action="store_true", help="if using JLINK"
        )
        s_parser.add_argument(
            "--dl", required=False, action="store_true", help="if using DL Board"
        )
        s_parser.add_argument(
            "--device",
            required=True,
            help="selects FTDI interface, e.g: ATRDIxxxx, or JLINK",
        )
        s_parser.add_argument(
            "--board",
            required=True,
            help="board to build for with optional board revision",
        )
        s_parser.add_argument(
            "--openocd_config",
            required=False,
            help="Specifies the config file for openocd",
        )
        s_parser.set_defaults(subcmd=subcmd_str)
        return s_parser

    def do_add_parser(self, parser_adder):
        parser = parser_adder.add_parser(
            self.name, help=self.help, description=self.description
        )
        subparsers = parser.add_subparsers(help="sub-command to run", required=True)

        list_otp_parser = self.create_default_subparser(
            subparsers, "list_otp", "Lists available OTP bits to burn"
        )

        dump_parser = self.create_default_subparser(
            subparsers, "dump", "Dump all OTP data on specific device"
        )

        burn_parser = self.create_default_subparser(
            subparsers, "burn", "Burns OTP bit(s)"
        )
        burn_parser.add_argument(
            "--otp",
            help=dedent(
                """\
                OTP to burn. Supported formats:
                  Single bit: absolute index (e.g. 23), <NAME>.<IDX>, or <NAME>.<SUB_NAME>
                  Group value: <NAME>=<VALUE> (VALUE may be decimal, hex (0x...), or binary (0b...))
                """
            ),
        )

        get_parser = self.create_default_subparser(
            subparsers,
            "get",
            "Retrieve value of OTP by name. (use `list_otp` target to get list of available OTP bits)",
        )
        get_parser.add_argument(
            "--otp",
            help=dedent(
                f"""\
                                            Either index (e.g. 23) or Name of specific OTP to retrieve

                                            If retrieving OTP by name and the OTP spans multiple bits, you can use OTP.sub_name or OTP.idx to get specific bit
                                            (e.g. SEC_DBG_CONFIG.DEBUG_SECURED or SEC_DBG_CONFIG.1 to retrieve OTP bit 61)
                                            """
            ),
        )

        return parser

    def pull_otp(self):
        """Pulls OTP from device"""
        temp_file = "otp_temp.bin"
        cmd_ret, _, stderr = self.openocd.execute_cmd([f"otp_dump_image {temp_file}"])
        if cmd_ret != 0:
            raise RuntimeError(f"{stderr}")
        if os.path.exists(temp_file):
            # Read the file after OpenOCD writes to it
            with open(temp_file, "rb") as f:
                self.atm_otp = f.read()
            os.remove(temp_file)
        else:
            raise RuntimeError(f"OpenOCD failed to create {temp_file}")
        return cmd_ret

    def list_otp(self, args):
        """List available OTP bits for a given device

        Args:
            args: args passed at the command line
        """
        print(self.OTParray().print_otp_array())

    def burn(self, args):
        """Burn OTP bits for a given device

        Args:
            args: args passed at the command line
        """
        self.pull_otp()
        otpArray = self.OTParray(self.atm_otp)

        # Group-value mode: NAME=VALUE
        if "=" in args.otp:
            name, value_str = args.otp.split("=", 1)
            otp = otpArray.get_otp_group_by_name(name)
            try:
                new_value = int(value_str, 0)
            except ValueError as exc:
                raise RuntimeError(
                    f"Invalid value '{value_str}'. Use decimal, hex (0x...), or binary (0b...)."
                ) from exc
            max_value = (1 << otp.size) - 1
            if new_value < 0 or new_value > max_value:
                raise RuntimeError(
                    f"Value {hex(new_value)} out of range for {otp.name} "
                    f"(size={otp.size} bits, max={hex(max_value)})"
                )
            # Bits that are currently 1 but would need to become 0 — impossible
            conflict = otp.value & (~new_value & max_value)
            if conflict:
                raise RuntimeError(
                    f"Cannot burn {otp.name}={hex(new_value)}: "
                    f"bits {[i for i in range(otp.size) if conflict >> i & 1]} "
                    f"are already burned to 1 and cannot be cleared."
                )
            # Compute new full 64-bit OTP word (OR in the group bits)
            mask = max_value << otp.idx
            new_full_value = (otpArray.value & ~mask) | (new_value << otp.idx)
            if new_full_value == otpArray.value:
                print(f"{otp.name} already equals {hex(new_value)}. Nothing to burn.")
                return

            print(
                wrap_color(
                    "WARNING: This is an irreversible process. "
                    "Once burned, OTP bits cannot be reversed",
                    TermColors.RED,
                )
            )
            print(
                wrap_color(
                    f"Current value of {otp.name}: {hex(otp.value)}", TermColors.RED
                )
            )
            print(
                wrap_color(f"New value of {otp.name}: {hex(new_value)}", TermColors.RED)
            )
            print(
                wrap_color(
                    f"Full OTP word (current): {hex(otpArray.value)}", TermColors.RED
                )
            )
            print(
                wrap_color(
                    f"Full OTP word (new):     {hex(new_full_value)}", TermColors.RED
                )
            )
            print(
                f"Are you sure you want to burn {otp.name}={hex(new_value)}? (yes/no)"
            )
            answer = input()
            if answer.lower() == "no":
                return
            if answer.lower() != "yes":
                print("Please enter yes or no.")
                return
            cmd_ret, _, stderr = self.openocd.execute_cmd(
                [f"otp_burn {new_full_value}"]
            )
            if cmd_ret != 0:
                print(f"{stderr}")
            return

        # Single-bit mode: absolute index, NAME.IDX, or NAME.SUB_NAME
        otp, idx = otpArray.get_otp_group_and_idx(args.otp)
        if idx is None:
            raise RuntimeError(
                "Please use <NAME>.<IDX> to burn a single bit, "
                "or <NAME>=<VALUE> to burn a group value."
            )
        curr_val = otp.get_idx(idx)
        if curr_val == 1:
            raise RuntimeError("OTP bit already blown. Cannot re-burn OTP bits")

        print(
            wrap_color(
                "WARNING: This is an irreversible process. "
                "Once burned, OTP bits cannot be reversed",
                TermColors.RED,
            )
        )
        print(wrap_color(f"Current value of otp: {otp}", TermColors.RED))
        otp.value |= 1 << idx
        print(wrap_color(f"New value of otp: {otp}", TermColors.RED))
        print(f"Are you sure you want to burn {otp.name}.{idx}?")
        answer = input()
        if answer.lower() == "no":
            return
        if answer.lower() != "yes":
            print("Please enter yes or no.")
            return
        # dont know the format of the commandline input, calculate absolute idx
        abs_idx = otp.idx + idx
        self.openocd.reset_target()
        cmd_ret, _, stderr = self.openocd.execute_cmd([f"otp_burn_bit {abs_idx}"])
        if cmd_ret != 0:
            print(f"{stderr}")

    def get(self, args):
        """get OTP bit for a given device

        Args:
            args: args passed at the command line
        """
        self.pull_otp()
        otpArray = self.OTParray(self.atm_otp)
        print(otpArray.get_otp_bits(args.otp))

    def dump(self, args):
        """Dumps OTP bits from device

        Args:
            args: args passed at the command line
        """
        self.pull_otp()
        print(self.OTParray(self.atm_otp))

    def do_run(self, args, unknown_args):
        self.board = args.board

        atm_otp_file = atm_otp_base.get_atm_otp_script_from_board(self.board)
        if atm_otp_file is not None:
            if atm_otp_file.exists():
                spec = importlib.util.spec_from_file_location(
                    "atm_otp_module", atm_otp_file
                )
                otp_module = importlib.util.module_from_spec(spec)
                spec.loader.exec_module(otp_module)
                get_otp_array = getattr(otp_module, "get_otp_array", None)
            else:
                get_otp_array = None
        else:
            get_otp_array = None

        if callable(get_otp_array) and (otp_array := get_otp_array(self.board)):
            self.OTParray = otp_array
        else:
            raise RuntimeError("Unsupported platform")

        try:
            self.openocd = atm_openocd.AtmOpenOCD(
                self.board,
                args.device,
                args.jlink,
                args.dl,
                openocd_cfg=args.openocd_config,
            )
        except:
            raise RuntimeError("Invalid configuration. Please use supported device")

        subcmd = getattr(self, args.subcmd)
        subcmd(args)
