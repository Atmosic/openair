#!/usr/bin/env python
"""
@file atm_arch_extension.py

@Defines to generate/show/burn atm isp atm file

Copyright (C) Atmosic 2024-2025
"""

import argparse
import hashlib
import os
from pathlib import Path
import sys
import ast
from west.commands import WestCommand

ROOT_DIR = Path(os.path.dirname(os.path.realpath(__file__)))

BASE_ADDR = 0x10000000

TYPE_STORAGE_DATA = 0
TYPE_SPE = 1
TYPE_APP = 2
TYPE_MCUBOOT = 3
TYPE_ATMWSTK = 4
TYPE_EXTRA_FILE = 5
TYPE_FACTORY_DATA = 6

RRAM_ALIGNMENT = 0x100
FLASH_ALIGNMENT = 0x400

ARCH_USAGE = ''' \
west atm_arch [-h] [-i {input file name} | --append] [-s] [-d]
           [-o {output file name}]
           [-p {partition_info map file}]
           [--atm_isp_path {atm_isp exe file}]
           [--storage_data_file {storage data file}]
           [--factory_data_file {factory data file}]
           [--spe_file {spe file}]
           [--app_file {app file}]
           [--mcuboot_file {mcuboot file}]
           [--atmwstk_file {atmwstk file}]
           [--sec_dbg_enable]
           [--sec_dbg_key {sec_dbg_key file}]
           [--sec_dbg_static_unlock]
           [--sec_boot_enable]
           [--sec_boot_key {sec_boot_key file}]
           [--erase_all]
           [--erase_flash_all]
           [--erase_flash {address,size}]
           [--erase_rram_all]
           [--erase_rram {address,size}]
           [--load_bin {bin_file,address}]
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
        self.protobuf_check_gen()

    def protobuf_check_gen(self):
        tools_path = str(Path(self.atm_isp_exe_path).resolve().parents[0])
        atm_isp_python_path = os.path.join(tools_path, 'atm_isp_python')
        if not os.path.exists(atm_isp_python_path):
            os.makedirs(atm_isp_python_path)
        atm_isp_proto = 'atm_isp.proto'
        atm_isp_proto_path = os.path.join(tools_path, atm_isp_proto)
        if not os.path.exists(atm_isp_proto_path):
            print(f"Cannot find {atm_isp_proto_path} for generate atm_isp_python")
            sys.exit(1)
        # always re-generate atm_isp_python with current installed grpcio_tools
        # and protobuf
        cmd_arg = ['python', '-m', 'grpc_tools.protoc',
               f"--proto_path={tools_path}",
               f"--python_out={atm_isp_python_path}",
               atm_isp_proto]
        return self.exe_cmd(cmd_arg)


    def decode_atm(self, input_file):
        # atm_isp decode [-h] [-i ARCHIVE]
        cmd_arg = ['python', self.atm_isp_exe_path, 'decode', '-i', input_file]
        return self.exe_cmd(cmd_arg)

    def burn_atm(self, input_file, openocd_pkg_root, device=None, dst_dir=None,
                 openocd_script_only=False, fast_load=False):
        # atm_isp decode [-h] [-i ARCHIVE]
        cmd_arg = ['python', self.atm_isp_exe_path, 'burn', '-i', input_file, '-z',
                   '--openocd_pkg_root', openocd_pkg_root]
        if dst_dir:
            cmd_arg.append('-d')
            cmd_arg.append(dst_dir)
        if openocd_script_only:
            cmd_arg.append('-E')
        if fast_load:
            cmd_arg.append('-f')
        return self.exe_cmd(cmd_arg)

    def update_partInfo(self, partInfo):
        self.partInfo = partInfo

    def init_atm(self, output_file, sd_key_cs, sb_key_cs, sd_static_unlock):
        if not self.partInfo.PLATFORM_FAMILY or \
            not self.partInfo.PLATFORM_NAME or \
            not self.partInfo.BOARD:
            print(f"Cannot find PLATFORM_FAMILY or PLATFORM_NAME "
                  "or BOARD info")
            sys.exit(1)
        # atm_isp init [-o NEW_ARCHIVE] [-t] [-s] \
        #              [-sec_dbg_key_checksum sec_dbg_key_checksum] \
        #              [-b] family name board
        cmd_arg = ['python', self.atm_isp_exe_path, 'init', '-o', output_file, '-z']
        cmd_arg.append(self.partInfo.PLATFORM_FAMILY)
        cmd_arg.append(self.partInfo.PLATFORM_NAME)
        cmd_arg.append(self.partInfo.BOARD)
        if sd_key_cs:
            cmd_arg.append('--sec_dbg')
            cmd_arg.append('--sec_dbg_key_checksum')
            cmd_arg.append(sd_key_cs)
            if sd_static_unlock:
                cmd_arg.append('--sec_dbg_static_unlock')
        if sb_key_cs:
            cmd_arg.append('--sec_boot')
            cmd_arg.append('--sec_boot_key_checksum')
            cmd_arg.append(sb_key_cs)
        if hasattr(self.partInfo, 'REV_PFX'):
            cmd_arg.append('--revision')
            cmd_arg.append(self.partInfo.REV_PFX)
        return self.exe_cmd(cmd_arg)

    def append_erase_flash(self, region_start, region_size, input_file,
                           output_file):
        if not self.partInfo.EXT_FLASH_START or \
            not self.partInfo.EXT_FLASH_SIZE:
            print(f"Cannot find EXT_FLASH_START and EXT_FLASH_SIZE info")
            sys.exit(1)
        ext_flash_start = ast.literal_eval(self.partInfo.EXT_FLASH_START)
        ext_flash_size = ast.literal_eval(self.partInfo.EXT_FLASH_SIZE)
        if not region_start and not region_size:
            region_size = ext_flash_size
            region_start = 0x0
        elif region_start < ext_flash_start or \
            region_size > ext_flash_size or \
            region_start > (ext_flash_start + ext_flash_size) or \
            (region_start + region_size ) > (ext_flash_start + ext_flash_size):
            print(f"region_start,region_size [{hex(region_start)},"
                  f"{hex(region_size)}] exceed flash range")
            sys.exit(1)
        cmd_arg = ['python', self.atm_isp_exe_path, 'eraseFlash', '-i',
                   input_file, '-o', output_file]
        cmd_arg.append(hex(region_size))
        cmd_arg.append(hex(region_start))
        cmd_arg.append(hex(ext_flash_start))
        return self.exe_cmd(cmd_arg)

    def append_erase_rram(self, region_start, region_size, input_file,
                          output_file):
        if not self.partInfo.RRAM_START or not self.partInfo.RRAM_SIZE:
            print(f"Cannot find RRAM_START and RRAM_SIZE info")
            sys.exit(1)
        rram_start = ast.literal_eval(self.partInfo.RRAM_START)
        rram_size = ast.literal_eval(self.partInfo.RRAM_SIZE)
        if not region_start and not region_size:
            region_size = rram_size
            region_start = rram_start
        elif region_start < rram_start or region_size > rram_size or \
            region_start > (rram_start + rram_size) or \
            (region_start + region_size ) > (rram_start + rram_size):
            print(f"region_start,region_size [{hex(region_start)},"
                  f"{hex(region_size)}] exceed rram range")
            sys.exit(1)
        cmd_arg = ['python', self.atm_isp_exe_path, 'eraseRram', '-i',
                   input_file, '-o', output_file]
        cmd_arg.append(hex(region_start))
        cmd_arg.append(hex(region_size))
        cmd_arg.append(hex(BASE_ADDR))
        return self.exe_cmd(cmd_arg)

    def append_load(self, filepath, region_start, input_file,
                    output_file):
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
        extrainfo = 'USER_BIN_FILE'
        if rram_size and region_start >= rram_start and \
            region_start < rram_start + rram_size:
            region_size = self.get_aligned_size(filepath, RRAM_ALIGNMENT)
            cmd_arg = ['python', self.atm_isp_exe_path, 'loadRram', '-i',
                       input_file, '-o', output_file, '-extrainfo', extrainfo]
            cmd_arg.append(filepath)
            cmd_arg.append(hex(region_start))
            cmd_arg.append(hex(region_size))
            cmd_arg.append(hex(BASE_ADDR))
        else:
            if ext_flash_size and region_start >= ext_flash_start and \
                region_start < ext_flash_start + ext_flash_size:
                region_start = region_start - ext_flash_start
            region_size = self.get_aligned_size(filepath, FLASH_ALIGNMENT)
            cmd_arg = ['python', self.atm_isp_exe_path, 'loadFlashNvds', '-i',
                       input_file, '-o', output_file, '-extrainfo', extrainfo]
            cmd_arg.append(filepath)
            cmd_arg.append(hex(region_start))
            cmd_arg.append(hex(region_size))
        return self.exe_cmd(cmd_arg)

    def append(self, load_type, filepath, input_file, output_file):
        if load_type == TYPE_STORAGE_DATA:
            if not self.partInfo.STORAGE_DATA_START or \
                not self.partInfo.STORAGE_DATA_SIZE:
                print(f"Cannot find STORAGE_DATA_START and STORAGE_DATA_SIZE"
                       " info")
                sys.exit(1)
            region_start = self.partInfo.STORAGE_DATA_START
            region_size = self.partInfo.STORAGE_DATA_SIZE
            extra_info = 'STORAGE_DATA'
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
            if hasattr(self.partInfo, 'ATM_SPLIT_IMG') and hasattr(self.partInfo, 'USE_MCUBOOT'):
                if not self.partInfo.PRIMARY_IMG_START or \
                    not self.partInfo.PRIMARY_IMG_SIZE:
                    print(f"Cannot find PRIMARY_IMG_START and PRIMARY_IMG_SIZE info")
                    sys.exit(1)
                region_start = self.partInfo.PRIMARY_IMG_START
                region_size = self.partInfo.PRIMARY_IMG_SIZE
                extra_info = 'SIGNED_SPE_FASTCODE'
            else:
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
                if hasattr(self.partInfo, 'ATM_NO_SPE'):
                    if not self.partInfo.APP_START or \
                            not self.partInfo.APP_SIZE:
                        print(f"Cannot find APP_START and APP_SIZE info")
                        sys.exit(1)
                    region_start = self.partInfo.APP_START
                    region_size = self.partInfo.APP_SIZE
                else:
                    if hasattr(self.partInfo, 'NS_APP_START') and \
                        hasattr(self.partInfo, 'NS_APP_SIZE'):
                        region_start = self.partInfo.NS_APP_START
                        region_size = self.partInfo.NS_APP_SIZE
                    elif hasattr(self.partInfo, 'PRIMARY_IMG_START') and \
                            hasattr(self.partInfo, 'PRIMARY_IMG_SIZE'):
                        # atmx2 build app only without use_mcuboot
                        region_start = self.partInfo.PRIMARY_IMG_START
                        region_size = self.partInfo.PRIMARY_IMG_SIZE
                    else:
                        print(f"Cannot find NS_APP_START or PRIMARY_IMG_START "
                              "info")
                        sys.exit(1)
            else:
                if hasattr(self.partInfo, 'ATM_SPLIT_IMG'):
                    extra_info = 'APP'
                    if not self.partInfo.NS_APP_START or \
                        not self.partInfo.NS_APP_SIZE:
                        print(f"Cannot find NS_APP_START and "
                          "NS_APP_SIZE info")
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
            if filepath.endswith(".elf"):
                binfile = filepath.replace(".elf", ".bin")
                self.do_objcopy(filepath, binfile)
                filepath = binfile
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
            cmd_arg = ['python', self.atm_isp_exe_path, 'loadRram', '-i', input_file,
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
            cmd_arg = ['python', self.atm_isp_exe_path, 'loadFlashNvds', '-i', input_file,
                       '-o', output_file, '-extrainfo', extra_info]
            cmd_arg.append(filepath)
            cmd_arg.append(region_start)
            cmd_arg.append(region_size)
        return self.exe_cmd(cmd_arg)

    def add_extra(self, filepath, input_file, output_file):
        img_type = 0
        # atm_isp cmdExtend [-h] [-i ARCHIVE] [-o NEW_ARCHIVE] [-v]
        #                   [-extrainfo EXTRAINFO] image [type]
        cmd_arg = ['python', self.atm_isp_exe_path, 'cmdExtend', '-i', input_file,
                   '-o', output_file, '-extrainfo', 'LAYOUT_MAP']
        cmd_arg.append(filepath)
        cmd_arg.append(f"{img_type}")
        return self.exe_cmd(cmd_arg)

    def do_objcopy(self, elffile, binfile):
        ZEPHYR_SDK_INSTALL_DIR = os.getenv("ZEPHYR_SDK_INSTALL_DIR")
        CMAKE_OBJCOPY = os.path.join(ZEPHYR_SDK_INSTALL_DIR, "arm-zephyr-eabi",
            "bin", "arm-zephyr-eabi-objcopy")
        cmd_arg = [CMAKE_OBJCOPY, "-O", "binary"]
        cmd_arg.append(elffile)
        cmd_arg.append(binfile)
        return self.exe_cmd(cmd_arg)

    def exe_cmd(self, cmd_arg):
        cmd = ' '.join(cmd_arg)
        if self.debug:
            print(f"Executing [{cmd}]")
        exit_code = os.system(cmd)
        if exit_code != 0:
            raise Exception(f"[{cmd}]command returned status [{exit_code}]")

    def get_aligned_size(self, filepath, alignment):
        file_size = os.path.getsize(filepath)
        # check alignment
        remainder = file_size % alignment
        is_aligned = (remainder == 0)
        if remainder == 0:
            return file_size
        return (file_size + (alignment - remainder))


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
        group.add_argument("-f", "--fast_load", action='store_true',
                        help="fast_load enabled, default false")
        group.add_argument("-storage_data_file", "--storage_data_file",
                        required=False, default=None,
                        help="storage data file path, binary format only")
        group.add_argument("-factory_data_file", "--factory_data_file",
                        required=False, default=None,
                        help="factory data file path, binary format only")
        group.add_argument("-spe_file", "--spe_file",
                        required=False, default=None,
                        help="spe file path, binary format only")
        group.add_argument("-app_file", "--app_file",
                        required=False, default=None,
                        help="application file path, binary format only")
        group.add_argument("-mcuboot_file", "--mcuboot_file",
                        required=False, default=None,
                        help="mcuboot file path, binary format only")
        group.add_argument("-atmwstk_file", "--atmwstk_file",
                        required=False, default=None,
                        help="atmwstk file path, binary or elf format only")
        group.add_argument('-sd', '--sec_dbg_enable', action='store_true',
                           help='secure debug eanble, specify secure debug key '
                           'with --sec_dbg_key, default: zephyrproject/openair'
                           '/lib/atm_debug_auth/root-debug-ec-p256.pem')
        group.add_argument("-sec_dbg_key", "--sec_dbg_key",
                        required=False, default=None,
                        help="secure debug key file path")
        group.add_argument('-sec_dbg_static_unlock', '--sec_dbg_static_unlock',
                           action='store_true',
                           help='secure debug static challenge enable')
        group.add_argument('-sb', '--sec_boot_enable', action='store_true',
                           help='secure boot eanble, specify secure boot key '
                           'with --sec_boot_key')
        group.add_argument("-sec_boot_key", "--sec_boot_key",
                        required=False, default=None,
                        help="secure boot key file path")
        group.add_argument("-openocd_pkg_root", "--openocd_pkg_root",
                        required=False, default=None,
                        help="Path to directory where openocd and its "
                        "scripts are found")
        group.add_argument("-dst_dir", "--dst_dir",
                        required=False, default=None,
                        help="Use this directory to dump openocd script in")
        group.add_argument('-e', '--openocd_script_only', action='store_true',
                           help='Stop after preparing OpenOCD script')
        group.add_argument('-erase_all', '--erase_all', action='store_true',
                           help="Erase whole flash and rram before load binary "
                           "files")
        group.add_argument('-erase_flash_all', '--erase_flash_all',
                           action='store_true', help="Erase whole flash before "
                           "load binary files")
        group.add_argument("-erase_flash", "--erase_flash", required=False,
                           default=None, help="customized flash erase, ex: "
                           "--erase_flash=address,size")
        group.add_argument('-erase_rram_all', '--erase_rram_all',
                           action='store_true',
                           help='Erase whole rram before load binary files')
        group.add_argument("-erase_rram", "--erase_rram", required=False,
                           default=None, help="customized rram erase, ex: "
                           "--erase_rram=address,size")
        group.add_argument("-load_bin", "--load_bin", required=False,
                           default=None, help="customized load bin file, ex: "
                           "--load_bin=bin_file,address")
        return parser

    def check_sec_key_checksum(self, args):
        sd_cs = None
        sb_cs = None
        sd_static_unlock = False
        if args.sec_dbg_enable:
            if args.sec_dbg_key:
                sec_dbg_key = args.sec_dbg_key
            else:
                sec_dbg_key = os.path.join(str(Path(__file__).resolve().parents[1]), 'lib',
                    'atm_debug_auth', 'root-debug-ec-p256.pem')
            if not os.path.exists(sec_dbg_key):
                print(f"{sec_dbg_key} not exist")
                sys.exit(1)
            sd_cs  = hashlib.md5(open(sec_dbg_key,'rb').read()).hexdigest()
            if args.sec_dbg_static_unlock:
                sd_static_unlock = True
        if args.sec_boot_enable:
            if not args.sec_boot_key:
                print(f"using --sec_boot_key to specify secure boot key path")
                sys.exit(1)
            sec_boot_key = args.sec_boot_key
            if not os.path.exists(sec_boot_key):
                print(f"{sec_boot_key} not exist")
                sys.exit(1)
            sb_cs  = hashlib.md5(open(sec_boot_key,'rb').read()).hexdigest()
        return sd_cs, sb_cs, sd_static_unlock

    def check_erase_commands(self, args):
        if args.erase_all or args.erase_flash_all or args.erase_flash or \
            args.erase_rram_all or args.erase_rram:
            return True
        return False

    def do_run(self, args, remainder):
        atm_isp_path = os.path.join(str(Path(__file__).resolve().parents[1]),
            'tools', 'scripts', 'atm_isp')
        if not os.path.exists(atm_isp_path):
                print(f"{atm_isp_path} not exist")
                sys.exit(1)
        atmisp = AtmIsp(atm_isp_path, args.debug)
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
                                   None, dst_dir, args.openocd_script_only,
                                   args.fast_load)

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
            # erase command cannot be append
            if self.check_erase_commands(args):
                print(f"append not support erase commands")
                sys.exit(1)
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
            sd_key_checksum, sb_key_checksum, sd_static_unlock = \
                    self.check_sec_key_checksum(args)
            atmisp.init_atm(args.output_atm_file, sd_key_checksum,
                            sb_key_checksum, sd_static_unlock)
        # add erase command first:
        if self.check_erase_commands(args):
            if partInfo.PLATFORM_FAMILY == 'atmx2':
                print(f"{partInfo.PLATFORM_FAMILY} not support erase command")
                sys.exit(1)
            # when erase_all, the other erase could be ignored
            if args.erase_all:
                atmisp.append_erase_flash(None, None, input_file,
                                          args.output_atm_file)
                atmisp.append_erase_rram(None, None, input_file,
                                         args.output_atm_file)
            else:
                if args.erase_flash_all or args.erase_flash:
                    # when erase_flash_all, the other flash erase could be
                    # ignored
                    if args.erase_flash_all:
                        region_start = None
                        region_size = None
                    else:
                        erase_args = args.erase_flash.split(',')
                        if len(erase_args) != 2:
                            print(f"{args.erase_flash} should be address,size")
                            sys.exit(1)
                        region_start = ast.literal_eval(erase_args[0])
                        region_size = ast.literal_eval(erase_args[1])
                    atmisp.append_erase_flash(region_start, region_size,
                                              input_file, args.output_atm_file)
                if args.erase_rram_all or args.erase_rram:
                    # when erase_rram_all, the other rram erase could be
                    # ignored
                    if args.erase_rram_all:
                        region_start = None
                        region_size = None
                    else:
                        erase_args = args.erase_rram.split(',')
                        if len(erase_args) != 2:
                            print(f"{args.erase_rram} should be address,size")
                            sys.exit(1)
                        region_start = ast.literal_eval(erase_args[0])
                        region_size = ast.literal_eval(erase_args[1])
                    atmisp.append_erase_rram(region_start, region_size,
                                             input_file, args.output_atm_file)

        if args.storage_data_file:
            if not os.path.exists(args.storage_data_file):
                print(f"{args.storage_data_file} not exist")
                sys.exit(1)

            atmisp.append(TYPE_STORAGE_DATA, args.storage_data_file, input_file,
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
            if not args.atmwstk_file.endswith(".bin"):
                if not os.getenv("ZEPHYR_SDK_INSTALL_DIR"):
                    print(f"ZEPHYR_SDK_INSTALL_DIR not set cannot transfer"
                          f"{args.atmwstk_file} to binary. Please transfer elf "
                          f"to binary offline and then --atmswtk_file with the "
                          f"transfered binary file")
                    sys.exit(1)
            atmisp.append(TYPE_ATMWSTK, args.atmwstk_file, input_file,
                            args.output_atm_file)
        if args.load_bin:
            load_args = args.load_bin.split(',')
            if len(load_args) != 2:
                print(f"{args.load_bin} should be bin_flie,address")
                sys.exit(1)
            bin_file = load_args[0]
            region_start = ast.literal_eval(load_args[1])
            if not os.path.exists(bin_file):
                print(f"{bin_file} not exist")
                sys.exit(1)
            atmisp.append_load(bin_file, region_start, input_file,
                               args.output_atm_file)
        atmisp.add_extra(args.partition_info_file, input_file,
                         args.output_atm_file)
