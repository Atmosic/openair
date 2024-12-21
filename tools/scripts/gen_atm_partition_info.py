#!/usr/bin/env python
"""
@file gen_atm_partition_info.py

@Defines to parse dts file for generating the partition_info.map file with arguments

Copyright (C) Atmosic 2024
"""

import sys
import argparse
import os
from pathlib import Path

ZEPHYR_BASE = os.getenv("ZEPHYR_BASE")
if not ZEPHYR_BASE:
    # set ZEPHYR_BASE.
    ZEPHYR_BASE = os.path.join(str(Path(__file__).resolve().parents[5]),
                               'zephyr')
    # Propagate this decision to child processes.
    os.environ['ZEPHYR_BASE'] = ZEPHYR_BASE
    print(f'ZEPHYR_BASE unset, using "{ZEPHYR_BASE}"')

# import devicetree code from zephyr repository until zephyr support to use
# standalone repository
sys.path.append(os.path.join(ZEPHYR_BASE, 'scripts', 'dts',
                             'python-devicetree', 'src'))

from devicetree import dtlib


SEC_BASE_ADDR=0x10000000
DEFAULT_ROM_OFFSET=0x0
DEFAULT_ROM_SIZE=0x10000
ST_PASS = 0
ST_ERROR = 1

def utils_get_node_by_lable(dt_node, labelname):
        for node in dt_node.node_iter():
            for label in node.labels:
                if label == labelname:
                    return node
        return None

def utils_get_node_property_reg(dt_node):
        ret = ST_ERROR
        reg0 = None
        reg1 = None
        try:
            reginfo = dt_node.props.get('reg', 'Not found')
            if not reginfo:
                return ST_ERROR, None, None
            nums = dtlib.to_nums(reginfo.value)
            if len(nums) == 2:
                ret = ST_PASS
                reg0 = nums[0]
                reg1 = nums[1]
        except:
            print("except Error")
        return ret, reg0, reg1

def parse_args():
    global args
    base_parser = argparse.ArgumentParser(add_help=False)
    base_parser.add_argument("-d", "--debug", action='store_true',
                        help="debug enabled, default false")
    parser = argparse.ArgumentParser(description="Atmosic Zephyr Generate "
                                     "Partition Info Map Tool")
    subparsers = parser.add_subparsers(dest='opcode')
    gen_parser = subparsers.add_parser('gen', parents=[base_parser])
    gen_parser.add_argument("-i", "--input_file", required=True, default=None,
                            help="input devicetree .dts file path")
    gen_parser.add_argument("-o", "--output_file", required=True, default=None,
                            help="output partition_info file path")
    gen_parser.add_argument("-p", "--platform_name", required=True,default=None,
                            help="platform name, ex: ATM33 or ATM34")
    gen_parser.add_argument("-f", "--platform_family",
                            required=True, default=None,
                            help="platform family, ex: ATM33xx-5 or ATM34xx-5")
    gen_parser.add_argument("-b", "--board", required=False, default=None,
                            help="board name, ex: ATMEVK-3330e-QN")
    gen_parser.add_argument("-use_mcuboot", "--use_mcuboot",
                            action='store_true',
                            help="USE_MCUBOOT enabled, default false")
    gen_parser.add_argument("-merge_spe_nspe", "--merge_spe_nspe", action='store_true',
                            help="MERGE_SPE_NSPE enabled, default false")
    gen_parser.add_argument("-use_mcuboot_overwrite", "--use_mcuboot_overwrite",
                            action='store_true',
                            help="USE_MCUBOOT_OVERWRITE enabled, default false")
    gen_parser.add_argument("-mcuboot_secondary_ext_flash",
                            "--mcuboot_secondary_ext_flash",
                            action='store_true',
                            help="MCUBOOT_SECONDARY_EXT_FLASH enabled, "
                            "default false")
    gen_parser.add_argument("-max_sector_size", "--max_sector_size",
                            required=False, default=None, help="max sector size")
    gen_parser.add_argument("-rom_start", "--rom_start", required=False,
                            default=None, help="rom start")
    gen_parser.add_argument("-rom_size", "--rom_size", required=False,
                            default=None, help="rom size")
    gen_parser.add_argument("-user_data_offset", "--user_data_offset",
                            required=False, default=None,
                            help="user data offset")
    gen_parser.add_argument("-user_data_size", "--user_data_size",
                            required=False, default=None, help="user data size")
    merge_parser = subparsers.add_parser('merge', parents=[base_parser])
    merge_parser.add_argument("-i1", "--input_file1", required=True,
                              default=None,
                              help="input partition_info file path to be merge")
    merge_parser.add_argument("-i2", "--input_file2", required=True,
                              default=None,
                              help="input partition_info file path to be merge")
    merge_parser.add_argument("-o", "--output_file", required=True, default=None,
                              help="output partition_info file path")
    gen_parser.add_argument("-revision", "--revision", required=False,
                            default=None, help="revision of ATM34xx")
    gen_parser.add_argument("-split_img", "--split_img", required=False,
                            default=None,
                            help="Image split across multiple memory regions")
    args = parser.parse_args()


class AtmPartInfo:
    def __init(self):
        ROM_ADDR = None
        ROM_SIZE = None
        PRIMARY_IMG_START = None
        PRIMARY_IMG_OFFSET = None
        PRIMARY_IMG_SIZE = None
        SPE_START = None
        SPE_OFFSET = None
        SPE_SIZE = None
        NS_APP_START = None
        NS_APP_OFFSET = None
        NS_APP_SIZE = None
        OTA_STAGING_START = None
        OTA_STAGING_OFFSET = None
        OTA_STAGING_SIZE = None
        STORAGE_DATA_START = None
        STORAGE_DATA_OFFSET = None
        STORAGE_DATA_SIZE = None
        FACTORY_DATA_START = None
        FACTORY_DATA_OFFSET = None
        FACTORY_DATA_SIZE = None
        USER_DATA_START = None
        USER_DATA_OFFSET = None
        USER_DATA_SIZE = None
        SEC_JRNL_START = None
        SEC_JRNL_OFFSET = None
        SEC_JRNL_SIZE = None
        SEC_CNTRS_KEYS_START = None
        SEC_CNTRS_KEYS_OFFSET = None
        SEC_CNTRS_KEYS_SIZE = None
        MCUBOOT_START = None
        MCUBOOT_OFFSET = None
        MCUBOOT_SIZE = None
        MCUBOOT_SCRATCH_START = None
        MCUBOOT_SCRATCH_OFFSET = None
        MCUBOOT_SCRATCH_SIZE = None
        ATMWSTK_START = None
        ATMWSTK_OFFSET = None
        ATMWSTK_SIZE = None
        TOTAL_RRAM_START = None
        RRAM_START = None
        RRAM_SIZE = None
        USE_MCUBOOT = None
        USE_MCUBOOT_OVERWRITE = None
        MCUBOOT_MAX_IMG_SECTORS = None
        ATM_NO_SPE = None
        EXT_FLASH_START = None
        EXT_FLASH_SIZE = None
        EXT_FLASH_MCUBOOT_SCRATCH_START = None
        EXT_FLASH_MCUBOOT_SCRATCH_OFFSET = None
        EXT_FLASH_MCUBOOT_SCRATCH_SIZE = None
        EXT_FLASH_OTA_STAGING_START = None
        EXT_FLASH_OTA_STAGING_OFFSET = None
        EXT_FLASH_OTA_STAGING_SIZE = None
        EXT_FLASH_NSPE_STAGING_START = None
        EXT_FLASH_NSPE_STAGING_OFFSET = None
        EXT_FLASH_NSPE_STAGING_SIZE = None
        EXT_FLASH_UNUSED_START = None
        EXT_FLASH_UNUSED_SIZE = None
        EXT_FLASH_USER_DATA_START = None
        BOARD = None
        PLATFORM_NAME = None
        PLATFORM_FAMILY = None
        ERASE_BLOCK_SIZE = None
        REV_PFX = None
        ATM_SPLIT_IMG = None


class PartInfoMerge:
    def __init__(self, infile1, infile2, outfile):
        self.infile1 = infile1
        self.infile2 = infile2
        self.outfile = outfile
        self.input_part_info = None
        self.output_part_info = None

    def init(self):
        self.input1_part_info = self.parse_part_info(self.infile1)
        self.input2_part_info = self.parse_part_info(self.infile2)

    def parse_part_info(self, filename):
        part_info = AtmPartInfo()
        with open(filename) as f:
            for line in f.readlines():
                try:
                    key, value = line.strip().split("=")
                    part_info.__setattr__(key, value)
                except:
                    # ignore
                    pass
        return part_info

    def merge_info(self):
        for key, value in self.input1_part_info.__dict__.items():
            if value is not None:
                if hasattr(self.input2_part_info, key) and \
                        self.input2_part_info.__getattribute__(key):
                    # ignore key already in input2_part_info
                    pass
                else:
                    self.input2_part_info.__setattr__(key, value)

    def update_data(self):
        with open(self.outfile, "w+") as f:
            for key, value in self.input2_part_info.__dict__.items():
                if value is not None:
                    f.write(f"{key}={value}\n")
        f.close()


    def printPartInfo(self, part_info):
        print("PartInfo:")
        for key, value in part_info.__dict__.items():
             print(f"key = {key} value = {value}")

class DevStreeParser:
    def __init__(self, args):
        self.dts_file = args.input_file
        self.outfile = args.output_file
        self.debug = args.debug
        self.platform_name = args.platform_name
        self.platform_family = args.platform_family
        self.board = None
        if args.board:
            self.board = args.board
        self.use_mcuboot = args.use_mcuboot
        self.use_mcuboot_overwrite = args.use_mcuboot_overwrite
        self.mcuboot_secondary_ext_flash = args.mcuboot_secondary_ext_flash
        self.merge_spe_nspe = args.merge_spe_nspe
        self.part_info = None
        self.max_sector_size = None
        self.rom_start = None
        self.rom_size = None
        self.user_data_offset = None
        self.user_data_size = None
        self.sec_jrnl_offset = None
        self.sec_jrnl_size = None
        self.sec_cntrs_keys_offset = None
        self.sec_cntrs_keys_size = None
        self.revision = None
        self.split_img = None

        if args.max_sector_size:
            self.max_sector_size = args.max_sector_size
        if args.rom_start:
            self.rom_start = int(args.rom_start, 16)
        else:
            self.rom_start = DEFAULT_ROM_OFFSET
        if args.rom_size:
            self.rom_size = int(args.rom_size, 16)
        else:
            self.rom_start = DEFAULT_ROM_SIZE
        if args.user_data_offset:
            self.user_data_offset = int(args.user_data_offset, 16)
        if args.user_data_size:
            self.user_data_size = int(args.user_data_size, 16)
        if args.revision:
            self.revision = args.revision
        if args.split_img:
            self.split_img = args.split_img

    def init(self):
        dt = dtlib.DT(self.dts_file)
        if dt:
            self.dt = dt
        else:
            print(f"DeviceTree parsing {args.input_file} failed")
            sys.exit(1)
        if os.path.exists(self.outfile):
            os.remove(self.outfile)
        self.part_info = AtmPartInfo()
        self.part_info.PLATFORM_NAME = self.platform_name
        self.part_info.PLATFORM_FAMILY = self.platform_family.lower()
        if self.use_mcuboot:
            self.part_info.USE_MCUBOOT = 1
        if self.part_info.PLATFORM_FAMILY != 'atmx2':
            if self.max_sector_size:
                self.part_info.MCUBOOT_MAX_IMG_SECTORS = self.max_sector_size
            if self.use_mcuboot_overwrite:
                self.part_info.USE_MCUBOOT_OVERWRITE = 1
            if self.rom_start:
                self.part_info.ROM_ADDR = hex(self.rom_start)
            if self.rom_size:
                self.part_info.ROM_SIZE = hex(self.rom_size)
        if self.merge_spe_nspe:
            self.part_info.ATM_NO_SPE = 1
        if self.revision:
            self.part_info.REV_PFX = self.revision
        if self.split_img:
            self.part_info.ATM_SPLIT_IMG = self.split_img

    def debug_print(self, msg):
        if self.debug:
            print(msg)

    def update_data(self):
        with open(self.outfile, "a+") as f:
            for key, value in self.part_info.__dict__.items():
                if value is not None:
                    f.write(f"{key}={value}\n")
        f.close()

    def parsing_board(self):
        # transfer BOARD
        # atmosic_sdk : ATMEVK_3330e_QN, Zephyr: ATMEVK-3330e-QN_ns
        board_name_prefix = None
        if self.board:
            name_split = self.board.split('_')
            if len(name_split) > 2:
                board_name_prefix = self.board
            else:
                board_name_prefix = name_split[0]
        self.part_info.BOARD = board_name_prefix.replace("-", "_")

    def parsing_not_use_mcuboot(self, rram0, rram_start, rram_size):
        # PRIMARY image as RRAM
        self.part_info.PRIMARY_IMG_START = hex(rram_start)
        self.part_info.PRIMARY_IMG_OFFSET = hex(rram_start - rram_start)
        self.part_info.PRIMARY_IMG_SIZE = hex(rram_size)
        spe_partition = utils_get_node_by_lable(rram0, "spe_partition")
        if spe_partition:
            ret_spe, spe_start, spe_size = \
                utils_get_node_property_reg(spe_partition)
            if ret_spe == ST_PASS:
                self.debug_print(f"spe_start = {hex(spe_start)}, "
                                 f"spe_size = {hex(spe_size)}")
                if not self.merge_spe_nspe:
                    self.part_info.SPE_START = hex(spe_start + rram_start)
                    self.part_info.SPE_OFFSET = hex(spe_start)
                    self.part_info.SPE_SIZE = hex(spe_size)
        nspe_partition = utils_get_node_by_lable(rram0, "nspe_partition")
        if nspe_partition:
            ret_nspe, nspe_start, nspe_size = \
                utils_get_node_property_reg(nspe_partition)
            if ret_nspe == ST_PASS:
                self.debug_print(f"nspe_start = {hex(nspe_start)}, "
                                 f"nspe_size = {hex(nspe_size)}")
                if not self.merge_spe_nspe:
                    self.part_info.NS_APP_START = hex(nspe_start + rram_start)
                    self.part_info.NS_APP_OFFSET = hex(nspe_start)
                    self.part_info.NS_APP_SIZE = hex(nspe_size)
        if not self.merge_spe_nspe:
            # ATMWSTK from fast_code_partition
            fast_code_partition = utils_get_node_by_lable(rram0,
                "fast_code_partition")
            ret = ST_ERROR
            if fast_code_partition:
                ret, atmwstk_start, atmwstk_size = \
                        utils_get_node_property_reg(fast_code_partition)
            else:
                # ATMWSTK from slot2_partition
                slot2_partition = utils_get_node_by_lable(rram0,
                    "slot2_partition")
                if slot2_partition:
                    ret, atmwstk_start, atmwstk_size = \
                        utils_get_node_property_reg(slot2_partition)
            if ret == ST_PASS:
                self.debug_print(f"atmwstk_start = {hex(atmwstk_start)}, "
                    f"atmwstk_size = {hex(atmwstk_size)}")
                self.part_info.ATMWSTK_START = hex(atmwstk_start + rram_start)
                self.part_info.ATMWSTK_OFFSET = hex(atmwstk_start)
                self.part_info.ATMWSTK_SIZE = hex(atmwstk_size)
        else:
            # No MCUBOOT and Merge SPE NSPE
            if ret_spe == ST_PASS and ret_nspe == ST_PASS:
                self.part_info.APP_START = hex(spe_start + rram_start)
                self.part_info.APP_SIZE = hex(spe_size + nspe_size)

    def parsing_use_mcuboot(self, rram0, rram_start, rram_size):
        # MCUBOOT from boot_partition
        boot_partition = utils_get_node_by_lable(rram0, "boot_partition")
        if boot_partition:
            ret, mcuboot_start, mcuboot_size = \
                    utils_get_node_property_reg(boot_partition)
            if ret == ST_PASS:
                self.debug_print(f"mcuboot_start = {hex(mcuboot_start)}, "
                                f"mcuboot_size = {hex(mcuboot_size)}")
                self.part_info.MCUBOOT_START = hex(mcuboot_start + rram_start)
                self.part_info.MCUBOOT_OFFSET = hex(mcuboot_start)
                self.part_info.MCUBOOT_SIZE = hex(mcuboot_size)
        # MCUBOOT_SCRASH from scratch_partition
        scratch_partition = utils_get_node_by_lable(rram0, "scratch_partition")
        if scratch_partition:
            ret, scratch_start, scratch_size = \
                    utils_get_node_property_reg(scratch_partition)
            if ret == ST_PASS:
                self.debug_print(f"rram0 scratch_start = {hex(scratch_start)}, "
                                f"scratch_size = {hex(scratch_size)}")
                self.part_info.MCUBOOT_SCRATCH_START = \
                        hex(scratch_start + rram_start)
                self.part_info.MCUBOOT_SCRATCH_OFFSET = hex(scratch_start)
                self.part_info.MCUBOOT_SCRATCH_SIZE = hex(scratch_size)
        # PRIMARY image from slot0_partition
        slot0_partition = utils_get_node_by_lable(rram0, "slot0_partition")
        if not slot0_partition:
            return
        ret, primary_start, primary_size = \
                utils_get_node_property_reg(slot0_partition)
        if ret == ST_PASS:
            self.debug_print(f"primary_start = {hex(primary_start)}, "
                            f"primary_size = {hex(primary_size)}")
            self.part_info.PRIMARY_IMG_START = hex(primary_start + rram_start)
            self.part_info.PRIMARY_IMG_OFFSET = hex(primary_start)
            self.part_info.PRIMARY_IMG_SIZE = hex(primary_size)
        if not self.merge_spe_nspe:
            spe_partition = utils_get_node_by_lable(rram0, "spe_partition")
            if spe_partition:
                ret, spe_start, spe_size = \
                        utils_get_node_property_reg(spe_partition)
                if ret == ST_PASS:
                    self.debug_print(f"spe_start = {hex(spe_start)}, "
                                    f"spe_size = {hex(spe_size)}")
                    self.part_info.SPE_START = hex(spe_start + rram_start)
                    self.part_info.SPE_OFFSET = hex(spe_start)
                    self.part_info.SPE_SIZE = hex(spe_size)
            nspe_partition = utils_get_node_by_lable(rram0, "nspe_partition")
            if nspe_partition:
                ret, nspe_start, nspe_size = \
                        utils_get_node_property_reg(nspe_partition)
                if ret == ST_PASS:
                    self.debug_print(f"nspe_start = {hex(nspe_start)}, "
                                    f"nspe_size = {hex(nspe_size)}")
                    self.part_info.NS_APP_START = hex(nspe_start + rram_start)
                    self.part_info.NS_APP_OFFSET = hex(nspe_start)
                    self.part_info.NS_APP_SIZE = hex(nspe_size)
        # OTA_STAGING from slot1_partition
        slot1_partition = utils_get_node_by_lable(rram0, "slot1_partition")
        if slot1_partition:
            ret, ota_staging_start, ota_staging_size = \
                    utils_get_node_property_reg(slot1_partition)
            if ret == ST_PASS:
                self.debug_print(f"ota_staging_start = {hex(ota_staging_start)}, "
                                f"ota_staging_size = {hex(ota_staging_size)}")
                self.part_info.OTA_STAGING_START = \
                        hex(ota_staging_start + rram_start)
                self.part_info.OTA_STAGING_OFFSET = hex(ota_staging_start)
                self.part_info.OTA_STAGING_SIZE = hex(ota_staging_size)
        # ATMWSTK from slot2_partition
        slot2_partition = utils_get_node_by_lable(rram0, "slot2_partition")
        if slot2_partition:
            ret, atmwstk_start, atmwstk_size = \
                    utils_get_node_property_reg(slot2_partition)
            if ret == ST_PASS:
                self.debug_print(f"atmwstk_start = {hex(atmwstk_start)}, "
                                f"atmwstk_size = {hex(atmwstk_size)}")
                self.part_info.ATMWSTK_START = hex(atmwstk_start + rram_start)
                self.part_info.ATMWSTK_OFFSET = hex(atmwstk_start)
                self.part_info.ATMWSTK_SIZE = hex(atmwstk_size)

    def parsing_rram(self):
        rram_controller = utils_get_node_by_lable(self.dt, "rram_controller")
        ret, rram0_start, rram0_size = \
                utils_get_node_property_reg(rram_controller)
        if ret == ST_ERROR:
            return
        self.debug_print(f"rram0_start = {hex(rram0_start)}, "
                         f"rram0_size = {hex(rram0_size)}")
        if rram0_start > SEC_BASE_ADDR:
            rram0_start = rram0_start - SEC_BASE_ADDR
        self.part_info.RRAM_START = hex(rram0_start)
        self.part_info.RRAM_SIZE = hex(rram0_size)
        rram0 = utils_get_node_by_lable(rram_controller, "rram0")
        if not rram0:
            print("Parsing rram0 failed")
            return
        if not self.use_mcuboot:
            self.parsing_not_use_mcuboot(rram0, rram0_start, rram0_size)
        else:
            self.parsing_use_mcuboot(rram0, rram0_start, rram0_size)
        # settings data from storage_partition
        storage_partition = utils_get_node_by_lable(rram0, "storage_partition")
        if storage_partition:
            ret, storage_data_start, storage_data_size = \
                    utils_get_node_property_reg(storage_partition)
            if ret == ST_ERROR:
                print("Parsing rram storage failed")
                return
            self.debug_print(f"storage_data_start = {hex(storage_data_start)}, "
                             f"storage_data_size = {hex(storage_data_size)}")
            self.part_info.STORAGE_DATA_START = \
                hex(storage_data_start + rram0_start)
            self.part_info.STORAGE_DATA_OFFSET = hex(storage_data_start)
            self.part_info.STORAGE_DATA_SIZE = hex(storage_data_size)
        # factory data from factory_partition
        factory_data_partition = utils_get_node_by_lable(rram0,
                                                         "factory_partition")
        if factory_data_partition:
            ret, factory_data_start, factory_data_size = \
                    utils_get_node_property_reg(factory_data_partition)
            if ret == ST_ERROR:
                print("Parsing rram factory data failed")
                return
            self.debug_print(f"factory_data_start = {hex(factory_data_start)}, "
                             f"factory_data_size = {hex(factory_data_size)}")
            self.part_info.FACTORY_DATA_START = \
                hex(factory_data_start + rram0_start)
            self.part_info.FACTORY_DATA_OFFSET = hex(factory_data_start)
            self.part_info.FACTORY_DATA_SIZE = hex(factory_data_size)
        # erase block size from erase-block-size
        erase_block_size = rram0.props.get('erase-block-size', 'Not found')
        if erase_block_size:
            self.part_info.ERASE_BLOCK_SIZE = hex(dtlib.to_nums(erase_block_size.value)[0])
        # partition info from input arguments
        if self.user_data_offset:
            self.part_info.USER_DATA_START = \
                    hex(self.user_data_offset + rram0_start)
            self.part_info.USER_DATA_OFFSET = hex(self.user_data_offset)
        if self.user_data_size:
            self.part_info.USER_DATA_SIZE = hex(self.user_data_size)

    def parsing_flash(self):
        flash_controller = utils_get_node_by_lable(self.dt, "flash_controller")
        if flash_controller:
            ret, flash0_start, flash0_size = \
                    utils_get_node_property_reg(flash_controller)
            if ret == ST_ERROR:
                return
            self.debug_print(f"flash0_start = {hex(flash0_start)}, "
                         f"flash0_size = {hex(flash0_size)}")
        if flash0_start > SEC_BASE_ADDR:
            flash0_start = flash0_start - SEC_BASE_ADDR
        self.part_info.EXT_FLASH_START = hex(flash0_start)
        self.part_info.EXT_FLASH_SIZE = hex(flash0_size)
        flash0 = utils_get_node_by_lable(flash_controller, "flash0")
        if not flash0:
            print("Parsing flash0 failed")
            return
        # MCUBOOT_SCRASH from scratch_partition
        scratch_partition = utils_get_node_by_lable(flash0, "scratch_partition")
        if scratch_partition:
            ret, scratch_start, scratch_size = \
                    utils_get_node_property_reg(scratch_partition)
            if ret == ST_PASS:
                self.debug_print(f"flash0 scratch_start = {hex(scratch_start)}, "
                             f"scratch_size = {hex(scratch_size)}")
                self.part_info.EXT_FLASH_MCUBOOT_SCRATCH_START = \
                    hex(scratch_start + flash0_start)
                self.part_info.EXT_FLASH_MCUBOOT_SCRATCH_OFFSET = \
                    hex(scratch_start)
                self.part_info.EXT_FLASH_MCUBOOT_SCRATCH_SIZE = hex(scratch_size)
        # OTA_STAGING from slot1_partition
        slot1_partition = utils_get_node_by_lable(flash0, "slot1_partition")
        if slot1_partition:
            ret, ota_staging_start, ota_staging_size = \
                    utils_get_node_property_reg(slot1_partition)
            if ret == ST_PASS:
                self.debug_print(f"ota_staging_start = {hex(ota_staging_start)}, "
                             f"ota_staging_size = {hex(ota_staging_size)}")
                self.part_info.EXT_FLASH_OTA_STAGING_START = \
                    hex(ota_staging_start + flash0_start)
                self.part_info.EXT_FLASH_OTA_STAGING_OFFSET = \
                    hex(ota_staging_start)
                self.part_info.EXT_FLASH_OTA_STAGING_SIZE = hex(ota_staging_size)
        # NSPE from slot2_partition
        slot2_partition = utils_get_node_by_lable(flash0, "slot2_partition")
        if slot2_partition:
            ret, nspe_start, nspe_size = \
                utils_get_node_property_reg(slot2_partition)
            if ret == ST_PASS:
                self.debug_print(f"nspe_start = {hex(nspe_start)}, "
                                f"nspe_size = {hex(nspe_size)}")
                self.part_info.NS_APP_START = hex(nspe_start + flash0_start)
                self.part_info.NS_APP_OFFSET = hex(nspe_start)
                self.part_info.NS_APP_SIZE = hex(nspe_size)
        # NSPE_STAGING from slot3_partition
        slot3_partition = utils_get_node_by_lable(flash0, "slot3_partition")
        if slot3_partition:
            ret, nspe_staging_start, nspe_staging_size = \
                    utils_get_node_property_reg(slot3_partition)
            if ret == ST_PASS:
                self.debug_print(f"nspe_staging_start = {hex(nspe_staging_start)}, "
                             f"nspe_staging_size = {hex(nspe_staging_size)}")
                self.part_info.EXT_FLASH_NSPE_STAGING_START = \
                    hex(nspe_staging_start + flash0_start)
                self.part_info.EXT_FLASH_NSPE_STAGING_OFFSET = \
                    hex(nspe_staging_start)
                self.part_info.EXT_FLASH_NSPE_STAGING_SIZE = hex(nspe_staging_size)
        if not self.merge_spe_nspe and not self.split_img:
            spe_partition = utils_get_node_by_lable(flash0, "spe_partition")
            if spe_partition:
                ret, spe_start, spe_size = \
                        utils_get_node_property_reg(spe_partition)
                if ret == ST_PASS:
                    self.debug_print(f"spe_start = {hex(spe_start)}, "
                                    f"spe_size = {hex(spe_size)}")
                    self.part_info.SPE_START = hex(spe_start + flash0_start)
                    self.part_info.SPE_OFFSET = hex(spe_start)
                    self.part_info.SPE_SIZE = hex(spe_size)
            nspe_partition = utils_get_node_by_lable(flash0, "nspe_partition")
            if nspe_partition:
                ret, nspe_start, nspe_size = \
                        utils_get_node_property_reg(nspe_partition)
                if ret == ST_PASS:
                    self.debug_print(f"nspe_start = {hex(nspe_start)}, "
                                 f"nspe_size = {hex(nspe_size)}")
                    self.part_info.NS_APP_START = hex(nspe_start + flash0_start)
                    self.part_info.NS_APP_OFFSET = hex(nspe_start)
                    self.part_info.NS_APP_SIZE = hex(nspe_size)
        # settings data from storage_partition
        storage_partition = utils_get_node_by_lable(flash0, "storage_partition")
        if storage_partition:
            ret, storage_data_start, storage_data_size = \
                    utils_get_node_property_reg(storage_partition)
            if ret == ST_ERROR:
                return
            self.debug_print(f"storage_data_start = {hex(storage_data_start)}, "
                             f"storage_data_size = {hex(storage_data_size)}")
            self.part_info.STORAGE_DATA_START = \
                hex(storage_data_start + flash0_start)
            self.part_info.STORAGE_DATA_OFFSET = hex(storage_data_start)
            self.part_info.STORAGE_DATA_SIZE = hex(storage_data_size)
        # factory data from factory_partition
        factory_data_partition = utils_get_node_by_lable(flash0,
                                                         "factory_partition")
        if factory_data_partition:
            ret, factory_data_start, factory_data_size = \
                    utils_get_node_property_reg(factory_data_partition)
            if ret == ST_ERROR:
                return
            self.debug_print(f"factory_data_start = {hex(factory_data_start)}, "
                             f"factory_data_size = {hex(factory_data_size)}")
            self.part_info.FACTORY_DATA_START = \
                hex(factory_data_start + flash0_start)
            self.part_info.FACTORY_DATA_OFFSET = hex(factory_data_start)
            self.part_info.FACTORY_DATA_SIZE = hex(factory_data_size)

    def parsing_ext_flash(self):
        flash_controller = utils_get_node_by_lable(self.dt, "flash_controller")
        if not flash_controller:
            print("Parsing flash_controller failed")
            return
        flash0 = utils_get_node_by_lable(flash_controller, "flash0")
        if not flash0:
            print("Parsing flash0 failed")
            return
        ret, flash0_start, flash0_size = utils_get_node_property_reg(flash0)
        if ret == ST_ERROR:
            print("Parsing flash_controller failed")
            return
        self.debug_print(f"flash0_start = {hex(flash0_start)}, "
                         f"flash0_size = {hex(flash0_size)}")
        self.part_info.FLASH_START = hex(flash0_start)
        self.part_info.FLASH_SIZE = hex(flash0_size)
        self.part_info.FLASH_TOTAL = hex(flash0_size)
        # MCUBOOT from boot_partition
        boot_partition = utils_get_node_by_lable(flash0, "boot_partition")
        if boot_partition:
            ret, mcuboot_start, mcuboot_size = \
                    utils_get_node_property_reg(boot_partition)
            if ret == ST_PASS:
                self.debug_print(f"mcuboot_start = {hex(mcuboot_start)}, "
                                f"mcuboot_size = {hex(mcuboot_size)}")
                self.part_info.MCUBOOT_START = hex(mcuboot_start + flash0_start)
                self.part_info.MCUBOOT_OFFSET = hex(mcuboot_start)
                self.part_info.MCUBOOT_SIZE = hex(mcuboot_size)
        # MCUBOOT_SCRASH from scratch_partition
        scratch_partition = utils_get_node_by_lable(flash0, "scratch_partition")
        if scratch_partition:
            ret, scratch_start, scratch_size = \
                    utils_get_node_property_reg(scratch_partition)
            if ret == ST_PASS:
                self.debug_print(f"rram0 scratch_start = {hex(scratch_start)}, "
                                f"scratch_size = {hex(scratch_size)}")
                self.part_info.MCUBOOT_SCRATCH_START = \
                        hex(scratch_start + flash0_start)
                self.part_info.MCUBOOT_SCRATCH_OFFSET = hex(scratch_start)
                self.part_info.MCUBOOT_SCRATCH_SIZE = hex(scratch_size)
        # PRIMARY image from slot0_partition
        slot0_partition = utils_get_node_by_lable(flash0, "slot0_partition")
        if not slot0_partition:
            return
        ret, primary_start, primary_size = \
                utils_get_node_property_reg(slot0_partition)
        if ret == ST_PASS:
            self.debug_print(f"primary_start = {hex(primary_start)}, "
                            f"primary_size = {hex(primary_size)}")
            self.part_info.PRIMARY_IMG_START = hex(primary_start + flash0_start)
            self.part_info.PRIMARY_IMG_OFFSET = hex(primary_start)
            self.part_info.PRIMARY_IMG_SIZE = hex(primary_size)
        # OTA_STAGING from slot1_partition
        slot1_partition = utils_get_node_by_lable(flash0, "slot1_partition")
        if slot1_partition:
            ret, ota_staging_start, ota_staging_size = \
                    utils_get_node_property_reg(slot1_partition)
            if ret == ST_PASS:
                self.debug_print(f"ota_staging_start = {hex(ota_staging_start)}, "
                                f"ota_staging_size = {hex(ota_staging_size)}")
                self.part_info.OTA_STAGING_START = \
                        hex(ota_staging_start + flash0_start)
                self.part_info.OTA_STAGING_OFFSET = hex(ota_staging_start)
                self.part_info.OTA_STAGING_SIZE = hex(ota_staging_size)
        # settings data from storage_partition
        storage_partition = utils_get_node_by_lable(flash0, "storage_partition")
        if storage_partition:
            ret, storage_data_start, storage_data_size = \
                    utils_get_node_property_reg(storage_partition)
            if ret == ST_ERROR:
                print("Parsing rram storage failed")
                return
            self.debug_print(f"storage_data_start = {hex(storage_data_start)}, "
                             f"storage_data_size = {hex(storage_data_size)}")
            self.part_info.STORAGE_DATA_START = \
                hex(storage_data_start + flash0_start)
            self.part_info.STORAGE_DATA_OFFSET = hex(storage_data_start)
            self.part_info.STORAGE_DATA_SIZE = hex(storage_data_size)
        # factory data from factory_partition
        factory_data_partition = utils_get_node_by_lable(flash0,
                                                         "factory_partition")
        if factory_data_partition:
            ret, factory_data_start, factory_data_size = \
                    utils_get_node_property_reg(factory_data_partition)
            if ret == ST_ERROR:
                print("Parsing flash factory data failed")
                return
            self.debug_print(f"factory_data_start = {hex(factory_data_start)}, "
                             f"factory_data_size = {hex(factory_data_size)}")
            self.part_info.FACTORY_DATA_START = \
                hex(factory_data_start + flash0_start)
            self.part_info.FACTORY_DATA_OFFSET = hex(factory_data_start)
            self.part_info.FACTORY_DATA_SIZE = hex(factory_data_size)
        # erase block size from erase-block-size
        erase_block_size = flash0.props.get('erase-block-size', 'Not found')
        if erase_block_size:
            self.part_info.ERASE_BLOCK_SIZE = hex(dtlib.to_nums(erase_block_size.value)[0])

    def parsing_sec_jrnl_and_key(self):
        sec_jrnl = utils_get_node_by_lable(self.dt, "sec_jrnl")
        if sec_jrnl:
            ret, sec_jrnl_start, sec_jrnl_size = \
                    utils_get_node_property_reg(sec_jrnl)
            if ret == ST_PASS:
                self.debug_print(f"sec_jrnl_start = {hex(sec_jrnl_start)}, "
                         f"sec_jrnl_size = {hex(sec_jrnl_size)}")
            self.part_info.SEC_JRNL_START = hex(sec_jrnl_start)
            self.part_info.SEC_JRNL_OFFSET = hex(sec_jrnl_start - SEC_BASE_ADDR)
            self.part_info.SEC_JRNL_SIZE = hex(sec_jrnl_size)

        sec_cntr_keys = utils_get_node_by_lable(self.dt, "sec_cntr_keys")
        if sec_cntr_keys:
            ret, sec_cntr_keys_start, sec_cntr_keys_size = \
                    utils_get_node_property_reg(sec_cntr_keys)
            if ret == ST_PASS:
                self.debug_print(
                        f"sec_cntr_keys_start = {hex(sec_cntr_keys_start)}, "
                        f"sec_cntr_keys_size = {hex(sec_cntr_keys_size)}")
            self.part_info.SEC_CNTRS_KEYS_START = hex(sec_cntr_keys_start)
            self.part_info.SEC_CNTRS_KEYS_OFFSET = \
                hex(sec_cntr_keys_start - SEC_BASE_ADDR)
            self.part_info.SEC_CNTRS_KEYS_SIZE = hex(sec_cntr_keys_size)

    def summary(self):
        if hasattr(self.part_info, "RRAM_START") and \
                hasattr(self.part_info, "RRAM_SIZE") and \
                hasattr(self.part_info, "SEC_JRNL_SIZE") and \
                hasattr(self.part_info, "SEC_CNTRS_KEYS_SIZE"):
            self.part_info.TOTAL_RRAM_START = \
                hex(int(self.part_info.RRAM_START, 16) +
                    int(self.part_info.RRAM_SIZE, 16) + 
                    int(self.part_info.SEC_JRNL_SIZE, 16) + 
                    int(self.part_info.SEC_CNTRS_KEYS_SIZE, 16))

def main():
    parse_args()
    if args.opcode == 'gen':
        if not os.path.exists(args.input_file):
            print(f"{args.input_file} not exist")
            sys.exit(1)
        dtsParser = DevStreeParser(args)
        dtsParser.init()
        dtsParser.parsing_board()
        if dtsParser.platform_family.lower() != 'atmx2':
            dtsParser.parsing_rram()
            dtsParser.parsing_flash()
            dtsParser.parsing_sec_jrnl_and_key()
        else:
            dtsParser.parsing_ext_flash()
        dtsParser.summary()
        dtsParser.update_data()
    elif args.opcode == 'merge':
        if not os.path.exists(args.input_file1):
            print(f"{args.input_file1} not exist")
            sys.exit(1)
        if not os.path.exists(args.input_file2):
            print(f"{args.input_file2} not exist")
            sys.exit(1)
        partinfomerge = PartInfoMerge(
                args.input_file1, args.input_file2, args.output_file)
        partinfomerge.init()
        partinfomerge.merge_info()
        partinfomerge.update_data()
    else:
        print(f"opcode {args.opcode} not support")
        sys.exit(1)


if __name__ == '__main__':
    main()
