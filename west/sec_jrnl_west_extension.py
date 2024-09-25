'''
@file sec_jrnl_west_ext.py

@brief West extension for managing secure journal

Copyright (c) Atmosic 2024
'''

import binascii
import codecs
import subprocess
import tempfile
from textwrap import dedent
from west.util import quote_sh_list
from atm_west_utils import wrap_color, TermColors
import argparse
from west.commands import WestCommand, Verbosity
from os import path
import os
import sys
sys.path.append(os.path.join(os.path.dirname(os.path.dirname(os.path.abspath(__file__))), 'tools', 'scripts'))
import atm_openocd
from sec_jrnl_tlv.sec_jrnl_tlv import SecJrnl

def auto_int(x):
    """arg parse type that parses all int types when passes as param"""
    return int(x, 0)

def unescaped_str(arg_str):
    return codecs.decode(str(arg_str), 'unicode_escape')


class SecJrnlCommand(WestCommand):

    def __init__(self):
        super().__init__(
            'secjrnl',  # gets stored as self.name
            'Interface with secure journal on supported chips',  # self.help
            # self.description:
            dedent('''
            Interface with secure journal on supported chips .

            Allows users to manage the secure journal through a variety of sub
            commands.'''))
        self.sec_jrnl = None

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

        dump_parser = self.create_default_subparser(
            subparsers, 'dump', 'Dump all TLVs from the secure journal')
        dump_parser.add_argument('-b','--binary', default=False, required=False,
                                   action='store_true', help='Dump secure jrnl as raw bin')
        dump_parser.add_argument('--hex', default=False, required=False,
                                   action='store_true', help='Dump secure jrnl as hex')

        get_parser = self.create_default_subparser(
            subparsers, 'get', 'Get individual TLV from secure journal')
        get_parser.add_argument('--tag', required=True, type=auto_int, help='Tag for TLV')

        self.create_default_subparser(
            subparsers, 'erase', 'Erase all non-ratcheted TLVs from the secure journal')
        self.create_default_subparser(
            subparsers, 'get_ratchet', 'Return secure ratchet index')

        append_parser = self.create_default_subparser(
            subparsers, 'append', 'Appends a single TLV to the secure journal')
        append_parser.add_argument('--tag', required=True, type=auto_int, help='Tag for TLV')
        append_parser.add_argument('--data', required=True, type=unescaped_str, help='Data for TLV')
        append_parser.add_argument('--locked', default=False, required=False,
                                   action='store_true',
                                   help='Lock down tag, prevent overriding')
        append_parser.add_argument('--dry-run', default=False, required=False,
                                   action='store_true',
                                   help='Append tag but dont push to device')
        ratchet_jrnl_parser = self.create_default_subparser(
            subparsers, 'ratchet_jrnl', 'Increment secure ratchet index')
        ratchet_jrnl_parser.add_argument('-y', default=False, required=False,
                                   action='store_true', help='Skip user input and ratchet Secure Journal')
        create_parser = subparsers.add_parser('create', help="Build a local secure journal binary file")
        create_parser.add_argument('--len', type=auto_int, required=False, help='Length of outputed bin file', default=1776)
        create_parser.add_argument('-t', '--tag', type=auto_int, required=False, action='append',
                            help='tag to append, each tag and data will be processed sequentially')
        create_parser.add_argument('-d', '--data', type=unescaped_str, required=False, help='tag data to append.', action='append')
        create_parser.add_argument('--board', required=True,
                              help='board to build for with optional board revision')
        create_parser.add_argument('-o', '--outfile', required=False, type=argparse.FileType('wb'), default='-')

        create_parser.set_defaults(subcmd='create')

        return parser

    def pull_sec_jrnl(self, force=False):
        '''Pulls secure journal from device

        Args:
            force (bool, optional): force pull sec_jrnl nvds even if local copy exists. Defaults to False.
        '''
        self.openocd.reset_target()
        if (self.sec_jrnl is None) or (force):
            tf = tempfile.NamedTemporaryFile('w+b')
            cmd_ret, _, _ = self.openocd.execute_cmd([f'atm_dump_sec_jrnl_nvds {tf.name}'])
            self.sec_jrnl = tf.read()
            tf.close()
            return cmd_ret

    def push_sec_jrnl(self, bin):
        '''Push secure journal from device
        '''
        tf = tempfile.NamedTemporaryFile('w+b')
        tf.write(bin)
        tf.flush()
        cmd_ret, _, _ = self.openocd.execute_cmd([f'atm_load_sec_jrnl_nvds {tf.name}'])
        tf.close()
        return cmd_ret

    def append(self, args):
        '''Append tag to secure journal. DOES NOT INCR RATCHET

        Args:
            args: args passed at the command line

        '''
        self.pull_sec_jrnl()
        sec_jrnl = SecJrnl(self.sec_jrnl)
        locked = args.locked
        old_tlv = sec_jrnl.get(args.tag)
        if (old_tlv is not None) and old_tlv.status.locked:
            raise RuntimeError(f"Existing tag ({old_tlv.tag}) is already locked down in Secure Journal. Cannot overwrite with new data.")

        if (hasattr(sec_jrnl, 'is_secure_tag')) and sec_jrnl.is_secure_tag(args.tag):
            print(f"\nWARNING: Tag {wrap_color(hex(args.tag), TermColors.BOLD)} is a user-secure tag. This means the tag can only be accessed via the secure application.")
            print(f"All user-secure tags {wrap_color('must', TermColors.BOLD)} be locked. You will not be able to update this value after ratcheting")
            print("Are you sure you want this?")
            answer = input()
            if answer.lower() == "no":
                return
            if answer.lower() != "yes":
                print("Please enter yes or no.")
                return
            # secure-only tags MUST be locked down - force it.
            locked = True
        sec_jrnl.append_tag(args.tag, args.data.encode('ascii'), locked)
        if (args.dry_run):
            print(sec_jrnl)
        else:
            self.push_sec_jrnl(sec_jrnl.bin)

    def create(self, args):
        '''Create a brand new secure journal bin file.

        Note: The `create` target is used to build binary files locally. If the
              device already has entries in the secure journal, you will not be
              able to use the output of this function

        Args:
            args: args passed at the command line
        '''
        sec_jrnl = SecJrnl(max_len=args.len)
        if len(args.tag) != len(args.data):
            raise RuntimeError("There must be an equal number of --data flags to --tag flags.")
        for tag, data in zip(args.tag, args.data):
            tag_data = data
            if os.path.isfile(data):
                with open(data, 'rb') as fd:
                    tag_data = bytes(fd.read())
            else:
                tag_data = bytes.fromhex("".join("{:02x}".format(ord(c)) for c in data))
            sec_jrnl.append_tag(tag, tag_data, False)
        args.outfile.write(sec_jrnl.raw_bin)
        args.outfile.flush()
        args.outfile.close()


    def dump(self, args):
        """Dumps secure journal from device

        Args:
            args: args passed at the command line
        """
        self.pull_sec_jrnl()
        if args.binary:
            print(self.sec_jrnl)
        elif args.hex:
            print(binascii.b2a_hex(SecJrnl(self.sec_jrnl).bin).decode("utf-8"))
        else:
            print(SecJrnl(self.sec_jrnl))

    def get(self, args):
        """Returns single TLV from secure journal

        Args:
            args: args passed at the command line
        """
        self.pull_sec_jrnl()
        tlv = SecJrnl(self.sec_jrnl).get(args.tag)
        if tlv is None:
            raise RuntimeError("TLV does not exist on device")
        print(tlv)

    def erase(self, args):
        """Erases non-ratcheted secure journal

        Args:
            args: args passed at the command line
        """
        self.openocd.reset_target()
        _,_,cmd_stderr = self.openocd.execute_cmd(['atm_erase_sec_jrnl_nvds'])
        print(cmd_stderr.decode("utf-8"))

    def _get_ratchet(self):
        self.openocd.reset_target()
        _,_,cmd_stderr = self.openocd.execute_cmd(['atm_sec_jrnl_get_ratchet'])
        # TODO: handle return string output better.
        return auto_int(cmd_stderr.decode().split()[-1])

    def get_ratchet(self, args):
        """Get secure ratchet index

        Args:
            args: args passed at the command line
        """
        ratchet_val = self._get_ratchet()
        # TODO: handle return string output better.
        print(f"Secure Counter = {ratchet_val}")

    def ratchet_jrnl(self, args):
        """Increment secure ratchet index

        Args:
            args: args passed at the command line
        """
        self.pull_sec_jrnl()
        sec_jrnl = SecJrnl(self.sec_jrnl)
        # check current ratchet value
        ratchet_val = self._get_ratchet()
        new_ratchet_val = sec_jrnl.ratchet_idx
        if (ratchet_val == new_ratchet_val):
            raise RuntimeError("No unratcheted tags found. Cannot ratchet empty data."
                               "Please append new tags before attempting to ratchet_jrnl")
        if not args.y:
            print(f"WARNING: The following tags will be ratcheted down:")
            for tag in iter(sec_jrnl):
                if tag.idx >= ratchet_val:
                    print(f"\t{tag}{wrap_color('   ; Note: this tag is LOCKED and cannot be updated if you ratchet', TermColors.RED) if tag.status.locked else ''}")
            print(f"Are you sure you want to increment the ratchet index from {ratchet_val} to {new_ratchet_val}?")
            answer = input()
            if answer.lower() == "no":
                return
            if answer.lower() != "yes":
                print("Please enter yes or no.")
                return
        self.openocd.reset_target()
        self.openocd.execute_cmd([f"atm_sec_jrnl_incr_ratchet_to {new_ratchet_val}"])

    def do_run(self, args, unknown_args):
        self.board = args.board
        # If we need to interact with a physical device, set openocd.
        if hasattr(args, 'device'):
            try:
                self.openocd = atm_openocd.AtmOpenOCD(self.board, args.device, args.jlink, openocd_cfg=args.openocd_config)
            except:
                raise RuntimeError("Invalid configuration. Please use supported device")

        subcmd = getattr(self, args.subcmd)
        subcmd(args)
