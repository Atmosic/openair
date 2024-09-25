#!/usr/bin/env python
"""
@file atm_arch_extension.py

@Defines to generate/show/burn atm isp atm file

Copyright (C) Atmosic 2024
"""

import argparse
import os
from pathlib import Path
import sys
import ast
from west.commands import WestCommand

ROOT_DIR = Path(os.path.dirname(os.path.realpath(__file__)))

BASE_ADDR = 0x10000000

TYPE_NVDS = 0
TYPE_SPE = 1
TYPE_APP = 2
TYPE_MCUBOOT = 3
TYPE_ATMWSTK = 4
TYPE_EXTRA_FILE = 5
TYPE_FACTORY_DATA = 6

ARCH_USAGE = ''' \
west atmarch [-h] [-i {input file name} | --append] [-s] [-d]
           [-o {output file name}]
           [-p {partition_info map file}]
           [--atm_isp_path {atm_isp exe file}]
           [--nvds_file {nvds file}]
           [--factory_data_file {factory data file}]
           [--spe_file {spe file}]
           [--app_file {app file}]
           [--mcuboot_file {mcuboot file}]
           [--atmwstk_file {atmwstk file}]
'''

class AtmPartInfo:
    def __init(self):
        pass

    def setattr(self, name, value):
        self.__setattr__(name, value)

    def parse_info(self, filepath):
        f = open(filepath, 'r')
        for line in f.readlines():
            key, value = line.strip().split('=')
            if key is not None and value is not None:
                self.setattr(key, value)
        f.close()


class AtmIsp:
    def __init__(self, atm_isp_path, debug=False):
        self.atm_isp_exe_path = atm_isp_path
        self.partInfo = None
        self.debug = debug

    def decode_atm(self, input_file):
        # atm_isp decode [-h] [-i ARCHIVE]
        cmd_arg = [self.atm_isp_exe_path, 'decode', '-i', input_file]
        return self.exe_cmd(cmd_arg)

    def burn_atm(self, input_file, openocd_pkg_root, device=None, dst_dir=None,
                 openocd_script_only=False):
        # atm_isp decode [-h] [-i ARCHIVE]
        cmd_arg = [self.atm_isp_exe_path, 'burn', '-i', input_file, '-z',
                   '--openocd_pkg_root', openocd_pkg_root]
        if dst_dir:
            cmd_arg.append('-d')
            cmd_arg.append(dst_dir)
        if openocd_script_only:
            cmd_arg.append('-E')
        return self.exe_cmd(cmd_arg)

    def update_partInfo(self, partInfo):
        self.partInfo = partInfo

    def init_atm(self, output_file):
        if not self.partInfo.PLATFORM_FAMILY or \
            not self.partInfo.PLATFORM_NAME or \
            not self.partInfo.BOARD:
            print(f"Cannot find PLATFORM_FAMILY or PLATFORM_NAME "
                  "or BOARD info")
            sys.exit(1)
        # atm_isp init [-o NEW_ARCHIVE] [-t] [-s] \
        #              [-sec_dbg_key_checksum sec_dbg_key_checksum] \
        #              [-b] family name board
        cmd_arg = [self.atm_isp_exe_path, 'init', '-o', output_file, '-z']
        cmd_arg.append(self.partInfo.PLATFORM_FAMILY)
        cmd_arg.append(self.partInfo.PLATFORM_NAME)
        cmd_arg.append(self.partInfo.BOARD)
        return self.exe_cmd(cmd_arg)

    def append(self, load_type, filepath, input_file, output_file):
        if load_type == TYPE_NVDS:
            if not self.partInfo.NVDS_START or not self.partInfo.NVDS_SIZE:
                print(f"Cannot find NVDS_START and NVDS_SIZE info")
                sys.exit(1)
            region_start = self.partInfo.NVDS_START
            region_size = self.partInfo.NVDS_SIZE
            extra_info = 'NVDS'
        elif load_type == TYPE_FACTORY_DATA:
            if not self.partInfo.FACTORY_DATA_START or \
                not self.partInfo.FACTORY_DATA_SIZE:
                print(f"Cannot find FACTORY_DATA_START and FACTORY_DATA_SIZE"
                       "info")
                sys.exit(1)
            region_start = self.partInfo.FACTORY_DATA_START
            region_size = self.partInfo.FACTORY_DATA_SIZE
            extra_info = 'FACTORY_DATA'
        elif load_type == TYPE_SPE:
            if not self.partInfo.SPE_START or \
                    not self.partInfo.SPE_SIZE:
                print(f"Cannot find SPE_START and SPE_SIZE info")
                sys.exit(1)
            region_start = self.partInfo.SPE_START
            region_size = self.partInfo.SPE_SIZE
            extra_info = 'BOOTLOADER'
        elif load_type == TYPE_APP:
            if not hasattr(self.partInfo, 'USE_MCUBOOT'):
                extra_info = 'APP'
                if not self.partInfo.NS_APP_START or \
                        not self.partInfo.NS_APP_SIZE:
                    print(f"Cannot find NS_APP_START and NS_APP_SIZE info")
                    sys.exit(1)
                region_start = self.partInfo.NS_APP_START
                region_size = self.partInfo.NS_APP_SIZE
            else:
                extra_info = 'SIGNED_APP'
                if not self.partInfo.PRIMARY_IMG_START or \
                        not self.partInfo.PRIMARY_IMG_SIZE:
                    print(f"Cannot find PRIMARY_IMG_START and "
                          "PRIMARY_IMG_SIZE info")
                    sys.exit(1)
                region_start = self.partInfo.PRIMARY_IMG_START
                region_size = self.partInfo.PRIMARY_IMG_SIZE
        elif load_type == TYPE_MCUBOOT:
            if not self.partInfo.MCUBOOT_START or \
                    not self.partInfo.MCUBOOT_SIZE:
                print(f"Cannot find MCUBOOT_START and MCUBOOT_SIZE info")
                sys.exit(1)
            region_start = self.partInfo.MCUBOOT_START
            region_size = self.partInfo.MCUBOOT_SIZE
            extra_info = 'MCUBOOT'
        elif load_type == TYPE_ATMWSTK:
            if not self.partInfo.ATMWSTK_START or \
                    not self.partInfo.ATMWSTK_SIZE:
                print(f"Cannot find ATMWSTK_START and ATMWSTK_SIZE info")
                sys.exit(1)
            region_start = self.partInfo.ATMWSTK_START
            region_size = self.partInfo.ATMWSTK_SIZE
            extra_info = 'ATMWSTK'
        else:
            print(f"Unknown type {load_type}")
            sys.exit(1)
        if hasattr(self.partInfo, 'RRAM_START'):
            rram_start = ast.literal_eval(self.partInfo.RRAM_START)
            rram_size = ast.literal_eval(self.partInfo.RRAM_SIZE)
        else:
            rram_size = 0
        if hasattr(self.partInfo, 'EXT_FLASH_START'):
            ext_flash_start = ast.literal_eval(self.partInfo.EXT_FLASH_START)
            ext_flash_size = ast.literal_eval(self.partInfo.EXT_FLASH_SIZE)
        else:
            ext_flash_size = 0
        if rram_size and ast.literal_eval(region_start) >= rram_start and \
                ast.literal_eval(region_start) < rram_start + rram_size:
            # atm_isp loadRram [-h] [-i ARCHIVE] [-o NEW_ARCHIVE] [-v]
            #                 [-mpr_start MPR_START] [-mpr_size MPR_SIZE]
            #                 [-mpr_lock_size MPR_LOCK_SIZE] [-extrainfo EXTRAINFO]
            #                 image [region_start] [region_size] [address]
            cmd_arg = [self.atm_isp_exe_path, 'loadRram', '-i', input_file,
                       '-o', output_file, '-extrainfo', extra_info]
            cmd_arg.append(filepath)
            cmd_arg.append(region_start)
            cmd_arg.append(region_size)
            cmd_arg.append(hex(BASE_ADDR))
        else:
            if ext_flash_size and \
                    ast.literal_eval(region_start) >= ext_flash_start and \
                    ast.literal_eval(region_start) < ext_flash_start + \
                    ext_flash_size:
                region_start = \
                    hex(ast.literal_eval(region_start) - ext_flash_start)
            # atm_isp loadFlashNvds [-h] [-i ARCHIVE] [-o NEW_ARCHIVE] [-v]
            #                 [-mpr_start MPR_START] [-mpr_size MPR_SIZE]
            #                 [-mpr_lock_size MPR_LOCK_SIZE] [-extrainfo EXTRAINFO]
            #                 image [region_start] [region_size] [address]
            cmd_arg = [self.atm_isp_exe_path, 'loadFlashNvds', '-i', input_file,
                       '-o', output_file, '-extrainfo', extra_info]
            cmd_arg.append(filepath)
            cmd_arg.append(region_start)
            cmd_arg.append(region_size)
        return self.exe_cmd(cmd_arg)

    def add_extra(self, filepath, input_file, output_file):
        img_type = 0
        # atm_isp cmdExtend [-h] [-i ARCHIVE] [-o NEW_ARCHIVE] [-v]
        #                   [-extrainfo EXTRAINFO] image [type]
        cmd_arg = [self.atm_isp_exe_path, 'cmdExtend', '-i', input_file,
                   '-o', output_file, '-extrainfo', 'LAYOUT_MAP']
        cmd_arg.append(filepath)
        cmd_arg.append(f"{img_type}")
        return self.exe_cmd(cmd_arg)

    def exe_cmd(self, cmd_arg):
        cmd = ' '.join(cmd_arg)
        if self.debug:
            print(f"Executing [{cmd}]")
        exit_code = os.system(cmd)
        if exit_code != 0:
            raise Exception(f"[{cmd}]command returned status [{exit_code}]")


class AtmArchCommand(WestCommand):
    def __init__(self):
        super().__init__(
            'atm_arch',
            # Keep this in sync with the string in west-commands.yml.
            'Atmosic Archive flash required files and info',
            "Atmosic Archive flash required files and info.",
            accepts_unknown_args=True)

    def do_add_parser(self, parser_adder):
        parser = parser_adder.add_parser(
            self.name,
            help=self.help,
            formatter_class=argparse.RawDescriptionHelpFormatter,
            description=self.description,
            usage=ARCH_USAGE)
        group = parser.add_argument_group('atm isp archive tool')
        group.add_argument("-atm_isp_path", "--atm_isp_path",
                        required=True, default=None,
                        help="specify atm_isp exe path path")
        group.add_argument("-d", "--debug", action='store_true',
                        help="debug enabled, default false")
        group.add_argument("-s", "--show", action='store_true',
                        help="show archive")
        group.add_argument("-b", "--burn", action='store_true',
                        help="burn archive")
        group.add_argument("-a", "--append", action='store_true',
                        help="append to input atm file")
        group.add_argument("-i", "--input_atm_file",
                        required=False, default=None,
                        help="input atm file path")
        group.add_argument("-o", "--output_atm_file",
                        required=False, default=None,
                        help="output atm file path")
        group.add_argument("-p", "--partition_info_file",
                        required=False, default=None,
                        help="partition info file path")
        group.add_argument("-nvds_file", "--nvds_file",
                        required=False, default=None,
                        help="nvds file path")
        group.add_argument("-factory_data_file", "--factory_data_file",
                        required=False, default=None,
                        help="factory data file path")
        group.add_argument("-spe_file", "--spe_file",
                        required=False, default=None,
                        help="spe file path")
        group.add_argument("-app_file", "--app_file",
                        required=False, default=None,
                        help="application file path")
        group.add_argument("-mcuboot_file", "--mcuboot_file",
                        required=False, default=None,
                        help="mcuboot file path")
        group.add_argument("-atmwstk_file", "--atmwstk_file",
                        required=False, default=None,
                        help="atmwstk file path")
        group.add_argument("-openocd_pkg_root", "--openocd_pkg_root",
                        required=False, default=None,
                        help="Path to directory where openocd and its "
                        "scripts are found")
        group.add_argument("-dst_dir", "--dst_dir",
                        required=False, default=None,
                        help="Use this directory to dump openocd script in")
        group.add_argument('-e', '--openocd_script_only', action='store_true',
                           help='Stop after preparing OpenOCD script')
        return parser


    def do_run(self, args, remainder):
        if not os.path.exists(args.atm_isp_path):
                print(f"{args.atm_isp_path} not exist")
                sys.exit(1)
        atmisp = AtmIsp(args.atm_isp_path, args.debug)
        if args.show:
            if not args.input_atm_file:
                print(f"Required input_atm_file")
                sys.exit(1)
            if not os.path.exists(args.input_atm_file):
                print(f"{args.input_atm_file} not exist")
                sys.exit(1)
            return atmisp.decode_atm(args.input_atm_file)

        if args.burn:
            if args.dst_dir:
                dst_dir = args.dst_dir
            else:
                dst_dir = None
            if not args.input_atm_file:
                print(f"Required input_atm_file")
                sys.exit(1)
            if not os.path.exists(args.input_atm_file):
                print(f"{args.input_atm_file} not exist")
                sys.exit(1)
            if not args.openocd_pkg_root:
                print(f"Required openocd_pkg_root")
                sys.exit(1)
            if not os.path.exists(args.openocd_pkg_root):
                print(f"{args.openocd_pkg_root} not exist")
                sys.exit(1)
            return atmisp.burn_atm(args.input_atm_file, args.openocd_pkg_root,
                                   None, dst_dir, args.openocd_script_only)

        if not args.partition_info_file:
            print(f"Required partition_info_file")
            sys.exit(1)
        if not args.output_atm_file:
            print(f"Required output_atm_file")
            sys.exit(1)
        if not os.path.exists(args.partition_info_file):
            print(f"{args.partition_info_file} not exist")
            sys.exit(1)
        if args.append:
            if not os.path.exists(args.input_atm_file):
                print(f"{args.input_atm_file} not exist")
                sys.exit(1)
            input_file = args.input_atm_file
        else:
            input_file = args.output_atm_file
        partInfo = AtmPartInfo()
        partInfo.parse_info(args.partition_info_file)
        atmisp.update_partInfo(partInfo)
        if not args.append:
            atmisp.init_atm(args.output_atm_file)
        if args.nvds_file:
            if not os.path.exists(args.nvds_file):
                print(f"{args.nvds_file} not exist")
                sys.exit(1)

            atmisp.append(TYPE_NVDS, args.nvds_file, input_file,
                            args.output_atm_file)
        if args.factory_data_file:
            if not os.path.exists(args.factory_data_file):
                print(f"{args.factory_data_file} not exist")
                sys.exit(1)
            atmisp.append(TYPE_FACTORY_DATA, args.factory_data_file, input_file,
                            args.output_atm_file)
        if args.spe_file:
            if not os.path.exists(args.spe_file):
                print(f"{args.spe_file} not exist")
                sys.exit(1)
            atmisp.append(TYPE_SPE, args.spe_file, input_file,
                            args.output_atm_file)
        if args.app_file:
            if not os.path.exists(args.app_file):
                print(f"{args.app_file} not exist")
                sys.exit(1)
            atmisp.append(TYPE_APP, args.app_file, input_file,
                            args.output_atm_file)
        if args.mcuboot_file:
            if not os.path.exists(args.mcuboot_file):
                print(f"{args.mcuboot_file} not exist")
                sys.exit(1)
            atmisp.append(TYPE_MCUBOOT, args.mcuboot_file, input_file,
                            args.output_atm_file)
        if args.atmwstk_file:
            if not os.path.exists(args.atmwstk_file):
                print(f"{args.atmwstk_file} not exist")
                sys.exit(1)
            atmisp.append(TYPE_ATMWSTK, args.atmwstk_file, input_file,
                            args.output_atm_file)
        atmisp.add_extra(args.partition_info_file, input_file,
                         args.output_atm_file)
