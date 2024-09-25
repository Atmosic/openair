'''
@file atm_otp_west_extension.py

@brief West extension for managing OTP

Copyright (c) Atmosic 2024
'''

import binascii
import tempfile
from textwrap import dedent

from west.commands import WestCommand, Verbosity
import os
import sys
sys.path.append(os.path.join(os.path.dirname(
    os.path.dirname(os.path.abspath(__file__))), 'tools', 'scripts'))
from atm_otp.atm_otp import Atmx3_OTPArray, Atm34_OTPArray
import atm_openocd

from atm_west_utils import wrap_color, TermColors
class AtmOtpCommand(WestCommand):
    def __init__(self):
        super().__init__(
            'atmotp',  # gets stored as self.name
            'Interface with OTP on supported Atmosic chips',  # self.help
            # self.description:
            dedent(
                '''
                Interface with OTP on supported chips

                Allows users to read out OTP bits as well as burn them to configure devices.
                '''
            )
        )

    def create_default_subparser(self, subparsers, subcmd_str, help_str):
        """adds subparser with default arguments.

        Args:
            subparsers : subparser object
            subcmd_str (str): name of sub command
            help_str (str): help string
        """
        s_parser = subparsers.add_parser(subcmd_str, help=help_str)
        s_parser.add_argument('--jlink', default=True, required=False, action='store_true',
                              help='if using JLINK')
        s_parser.add_argument('--device', required=True,
                              help='selects FTDI interface, e.g: ATRDIxxxx, or JLINK')
        s_parser.add_argument('--board', required=True,
                              help='board to build for with optional board revision')
        s_parser.add_argument('--openocd_config', required=False,
                              help='Specifies the config file for openocd')
        s_parser.set_defaults(subcmd=subcmd_str)
        return s_parser

    def do_add_parser(self, parser_adder):
        parser = parser_adder.add_parser(self.name,
                                         help=self.help,
                                         description=self.description)
        subparsers = parser.add_subparsers(
            help='sub-command to run', required=True)

        list_otp_parser = self.create_default_subparser(
            subparsers, 'list_otp', 'Lists available OTP bits to burn')

        dump_parser = self.create_default_subparser(
            subparsers, 'dump', 'Dump all OTP data on specific device')

        burn_parser = self.create_default_subparser(
            subparsers, 'burn', 'Burns a single OTP bit')
        burn_parser.add_argument('--otp',
                                 help="OTP Bit to burn, can either be either absolute index (e.g. 23) or <NAME>.<IDX> or <NAME>.<SUB_NAME>")

        get_parser = self.create_default_subparser(
            subparsers, 'get', 'Retrieve value of OTP by name. (use `list_otp` target to get list of available OTP bits)')
        get_parser.add_argument('--otp',
                                help=dedent(f'''\
                                            Either index (e.g. 23) or Name of specific OTP to retrieve

                                            If retrieving OTP by name and the OTP spans multiple bits, you can use OTP.sub_name or OTP.idx to get specific bit
                                            (e.g. SEC_DBG_CONFIG.DEBUG_SECURED or SEC_DBG_CONFIG.1 to retrieve OTP bit 61)
                                            '''
                                            )
                                )

        return parser

    def pull_otp(self):
        '''Pulls OTP from device
        '''
        self.openocd.reset_target()
        tf = tempfile.NamedTemporaryFile('w+b')
        cmd_ret, _, _ = self.openocd.execute_cmd([f'otp_dump_image {tf.name}'])
        self.atm_otp = tf.read()
        tf.close()
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
        otp, idx = otpArray.get_otp_group_and_idx(args.otp)
        if idx is None:
            raise RuntimeError("Can only burn single bits at a time. Cannot burn an entire multi-bit OTP config. "
                               "Please use <NAME>.<IDX> to burn a single bit")
        curr_val = otp.get_idx(idx)
        if curr_val == 1:
            raise RuntimeError(
                "OTP bit already blown. Cannot re-burn OTP bits")

        print(wrap_color(
            "WARNING: This is an irreversible process. Once burned, OTP bits cannot be reversed", TermColors.RED))
        print(wrap_color(f"Current value of otp: {otp}", TermColors.RED))
        otp.value |= (1 << idx)
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
        self.openocd.execute_cmd([f'otp_burn_bit {abs_idx}'])

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

        plat_dir = atm_openocd.get_atm_plat_dir_from_board(self.board)
        if (plat_dir == "ATM33xx-5"):
            self.OTParray = Atmx3_OTPArray
        elif ("ATM34xx" in self.atm_plat):
            self.OTParray = Atm34_OTPArray
        else:
            raise RuntimeError("Unsupported platform")

        try:
            self.openocd = atm_openocd.AtmOpenOCD(self.board, args.device, args.jlink, openocd_cfg=args.openocd_config)
        except:
            raise RuntimeError("Invalid configuration. Please use supported device")

        subcmd = getattr(self, args.subcmd)
        subcmd(args)

