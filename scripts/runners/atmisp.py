# Copyright (c) 2017 Linaro Limited.
# Copyright (c) Atmosic 2021-2025
#
# SPDX-License-Identifier: Apache-2.0

'''Runner for flashing with Atmosic In-System Programming Tool.'''

from os import path
from pathlib import Path
import contextlib
import platform
import os
import sys
import subprocess
import re

from intelhex import IntelHex
from runners.core import ZephyrBinaryRunner, RunnerCaps, BuildConfiguration

DEFAULT_OPENOCD_TCL_PORT = 6333
DEFAULT_OPENOCD_TELNET_PORT = 4444
DEFAULT_OPENOCD_GDB_PORT = 3333

@contextlib.contextmanager
def _temp_environ(**update):
    env = os.environ
    update = update or {}

    try:
        env.update(update)
        yield
    finally:
        [env.pop(i) for i in update]

class AtmispBinaryRunner(ZephyrBinaryRunner):
    '''Runner front-end for atmisp.'''

    def __init__(self, cfg, device, atm_plat, jlink=False,
                 atm_openocd_base=None, atm_openocd_search=None, no_atm_openocd=False,
                 openocd_config=None, verify=False,
                 erase_flash=False,
                 noreset=False, gdb_config=None,
                 use_elf=None,
                 factory_data_file=False,
                 fast_load=False,
                 atmwstk=None,
                 tcl_port=DEFAULT_OPENOCD_TCL_PORT,
                 telnet_port=DEFAULT_OPENOCD_TELNET_PORT,
                 gdb_port=DEFAULT_OPENOCD_GDB_PORT,
                 prog_rom=False,
                 rom_image=None,
                 memory_space=None):
        super().__init__(cfg)

        if not openocd_config:
            default = path.join(cfg.board_dir, 'support', 'openocd.cfg')
            if path.exists(default):
                openocd_config = default
        self.openocd_config = openocd_config

        if self.openocd_config is not None and path.exists(self.openocd_config):
            search_args = ['-s', path.dirname(self.openocd_config)]
        else:
            search_args = []

        if jlink and no_atm_openocd:
            self.logger.error('Must use Atmosic OpenOCD with J-Link')
            sys.exit(1)

        if not no_atm_openocd and atm_openocd_base is None:
            # Unfortunately the env var ZEPHYR_MODULES is only defined during
            # Zephyr CMake builds... so we have to derive that from ZEPHYR_BASE
            zephyr_modules = os.path.join(os.path.dirname(os.path.abspath(os.environ['ZEPHYR_BASE'])), 'modules')
            atm_openocd_base = os.path.join(zephyr_modules, 'hal', 'atmosic_lib', 'tools', 'openocd')
            atm_openocd_search = os.path.join(atm_openocd_base, 'tcl')

        if atm_openocd_base is not None:
            plat = platform.system()
            suffix = ''
            if plat.startswith('MSYS') or plat == 'Windows':
                plat = 'Windows_NT'
                suffix = '.exe'
            elif plat == 'Darwin':
                arch = platform.machine().lower()
                plat = f'Darwin/{arch}'
            openocd = os.path.join(atm_openocd_base, 'bin', plat, 'openocd' + suffix)
            atm_openocd_search = os.path.join(atm_openocd_base, 'tcl')
            self.logger.debug("Using ATM OpenOCD '{}'".format(openocd))
        elif cfg.openocd is not None:
            openocd = cfg.openocd
        else:
            openocd = 'openocd'

        if cfg.openocd_search is not None and atm_openocd_base is None:
            for dir in cfg.openocd_search:
                search_args.extend(['-s', dir])

        if atm_openocd_search is not None:
            search_args.extend(['-s', atm_openocd_search])
        self.openocd_cmd = [openocd] + search_args

        if not gdb_config:
            default = path.join(cfg.board_dir, 'support', 'atm.gdb')
            if path.exists(default):
                gdb_config = default

        self.erase_flash = erase_flash
        self.atm_plat = atm_plat
        self.openocd_config = openocd_config
        self.gdb_config = gdb_config
        self.device = device
        self.jlink = jlink
        self.verify = verify
        self.noreset = noreset
        self.tcl_port = tcl_port
        self.telnet_port = telnet_port
        self.gdb_port = gdb_port
        self.gdb_cmd = [cfg.gdb] if cfg.gdb else None
        self.elf_name = [Path(cfg.elf_file).as_posix()]
        self.build_config = BuildConfiguration(cfg.build_dir)
        self.prog_rom = prog_rom
        self.rom_image = rom_image
        self.memory_space = memory_space
        self.memory_spaces = self.parse_memory_spaces(memory_space)
        is_split_img = self.build_config.getboolean('CONFIG_ATM_SPLIT_IMG')
        if cfg.hex_file is not None:
            if is_split_img:
                # Runner hexfile string could include multiple files,
                # delimited by ','
                self.hex_name = [Path(hex_f).as_posix() \
                                 for hex_f in cfg.hex_file.split(",")]
                self.bin_name = [Path(hex_f).with_suffix(".bin").as_posix() \
                                 for hex_f in cfg.hex_file.split(",")]
            else:
                self.hex_name = [Path(cfg.hex_file).as_posix()]
                self.bin_name = \
                    [Path(cfg.hex_file).with_suffix(".bin").as_posix()]
        if atmwstk:
            atmwstk_bin_name = f"{atmwstk}.bin"
            atmwstk_hex_name = f"{atmwstk}.hex"
            atmwstk_elf_name = f"{atmwstk}.elf"
            self.bin_name.append(Path(atmwstk_bin_name).as_posix())
            self.hex_name.append(Path(atmwstk_hex_name).as_posix())
            self.elf_name.append(Path(atmwstk_elf_name).as_posix())
        if factory_data_file:
            factory_hex_path = os.path.join(cfg.build_dir, 'zephyr', 'zephyr_factory.hex')
            if os.path.exists(factory_hex_path):
                self.hex_name.append(Path(factory_hex_path).as_posix())
            factory_bin_path = os.path.join(cfg.build_dir, 'zephyr', 'zephyr_factory.bin')
            if os.path.exists(factory_bin_path):
                self.bin_name.append(Path(factory_bin_path).as_posix())
            factory_elf_path = os.path.join(cfg.build_dir, 'zephyr', 'zephyr_factory.elf')
            if os.path.exists(factory_elf_path):
                self.elf_name.append(Path(factory_elf_path).as_posix())
            settings_hex_path = os.path.join(cfg.build_dir, 'zephyr', 'zephyr_settings.hex')
            if os.path.exists(settings_hex_path):
                self.hex_name.append(Path(settings_hex_path).as_posix())
            settings_bin_path = os.path.join(cfg.build_dir, 'zephyr', 'zephyr_settings.bin')
            if os.path.exists(settings_bin_path):
                self.bin_name.append(Path(settings_bin_path).as_posix())
            settings_elf_path = os.path.join(cfg.build_dir, 'zephyr', 'zephyr_settings.elf')
            if os.path.exists(settings_elf_path):
                self.elf_name.append(Path(settings_elf_path).as_posix())


        self.use_elf = use_elf
        if fast_load and not use_elf:
            self.fast_load = True
            self.fl_bin = os.path.join(os.path.dirname(openocd_config), 'fast_load', 'fast_load.bin')
            # The objdump locate at the same directory with gdb
            objdump = cfg.gdb.replace("-gdb-py", "-objdump").replace("-gdb", "-objdump")
            if not os.path.exists(objdump):
                self.logger.error("<fast_load> %s not exist", objdump)
                sys.exit(1)
            self.fl_prog_addr = None

            for file in self.hex_name:
                content = subprocess.run([objdump, "-h", file], capture_output=True, text=True)
                pattern = re.compile(r"\s+0\s+.sec1\s+[0-9a-fA-F]+\s+[0-9a-fA-F]+\s+([0-9a-fA-F]+)\s+")
                match = pattern.search(content.stdout)
                if match:
                    hex_addr = '0x' + match.group(1)
                    int_addr = int(hex_addr, 16) & 0xEFFFFFFF
                    if self.fl_prog_addr is None:
                        self.fl_prog_addr = hex(int_addr)
                    else:
                        self.fl_prog_addr += ','
                        self.fl_prog_addr += hex(int_addr)

            self.logger.info("<fast_load> program address: %s", self.fl_prog_addr)
        else:
            self.fast_load = False
            self.fl_bin = None

    @staticmethod
    def parse_memory_spaces(memory_space_str):
        if not memory_space_str:  # Handles None or empty string
            return []
        memory_spaces = []
        entries = memory_space_str.split()
        for entry in entries:
            try:
                mem_type, start, size = entry.split(',')
                start = int(start, 16)
                size = int(size, 16)
                memory_spaces.append({"type": mem_type, "start": start, "size": size})
            except ValueError as e:
                raise ValueError(f"Invalid memory_space format: {entry}. Expected format: TYPE,START,SIZE") from e
        return memory_spaces

    @staticmethod
    def find_target_memory_space(hex_file, memory_spaces):
        if not os.path.exists(hex_file):
            raise FileNotFoundError(f"Hex file not found: {hex_file}")
        ih = IntelHex(hex_file)
        hex_addresses = {addr | 0x10000000 for addr in ih.addresses()}

        for mem in memory_spaces:
            mem_start = mem["start"]
            mem_end = mem_start + mem["size"]
            if any(mem_start <= addr < mem_end for addr in hex_addresses):
                return mem
        return None

    @classmethod
    def name(cls):
        return 'atmisp'

    @classmethod
    def capabilities(cls):
        return RunnerCaps(commands={'flash', 'attach', 'debug'})

    @classmethod
    def do_add_parser(cls, parser):

        # required argument(s)
        parser.add_argument('--device', required=True,
                            help='selects FTDI interface, e.g: ATRDIxxxx, or JLINK')
        parser.add_argument('--atm_plat', required=True,
                            help='Specifies the Atmosic platform')

        # optional argument(s)
        parser.add_argument('--erase_flash', default=False, required=False, action='store_true',
                            help='Erase flash')
        parser.add_argument('--jlink', default=False, required=False, action='store_true',
                            help='if using JLINK')
        parser.add_argument('--no_atm_openocd', default=False, required=False, action='store_true',
                            help='Do not use Atmosic OpenOCD')
        parser.add_argument('--atm_openocd_base', required=False,
                            help='Path to Atmosic OpenOCD binaries')
        parser.add_argument('--openocd_config', required=False,
                            help='if given, override default config file')

        parser.add_argument('--verify', default=False, required=False, action='store_true',
                            help='verify writes, default False')

        parser.add_argument('--noreset', default=False, required=False, action='store_true',
                            help='Do not reset the device after flashing, default False')

        parser.add_argument('--use-elf', default=False, required=False, action='store_true',
                            dest='use_elf',
                            help='Use ELF rather than HEX')

        parser.add_argument('--factory_data_file', default=False, required=False, action='store_true',
                            help='Enable factory data file')

        parser.add_argument('--fast_load', default=False, required=False, action='store_true',
                            help='Enable fast load feature')

        parser.add_argument('--atmwstk', required=False,
                            help='atmwstk path and file prefix of bin, elf and hex to be programmed at the same time')
        # debug argument(s)
        parser.add_argument('--gdb_config', required=False,
                            help='if given, overrides default config file')

        parser.add_argument('--tcl-port', default=DEFAULT_OPENOCD_TCL_PORT,
                            help='openocd TCL port, defaults to 6333')

        parser.add_argument('--telnet-port',
                            default=DEFAULT_OPENOCD_TELNET_PORT,
                            help='openocd telnet port, defaults to 4444')

        parser.add_argument('--gdb-port', default=DEFAULT_OPENOCD_GDB_PORT,
                            help='openocd gdb port, defaults to 3333')

        parser.add_argument('--prog_rom', default=False, required=False, action='store_true',
                            help='Program ROM')

        parser.add_argument('--rom_image', required=False,
                            help='if given, override default rom_image file')

        parser.add_argument('--memory_space', required=False,
                            help='specify the memory space:"TYPE1,start_address,space_size TYPE2,start_address,space_size"')

    @classmethod
    def do_create(cls, cfg, args):
        return AtmispBinaryRunner(cfg, device=args.device, atm_plat=args.atm_plat,
            jlink=args.jlink, atm_openocd_base=args.atm_openocd_base, no_atm_openocd=args.no_atm_openocd,
            openocd_config=args.openocd_config, gdb_config=args.gdb_config,
            verify=args.verify, noreset=args.noreset, use_elf=args.use_elf,
            erase_flash=args.erase_flash, factory_data_file=args.factory_data_file,
            fast_load=args.fast_load, atmwstk=args.atmwstk, prog_rom=args.prog_rom, rom_image=args.rom_image,
            memory_space=args.memory_space)

    def do_run(self, command, **kwargs):
        self.require(self.openocd_cmd[0])
        is_split_img = self.build_config.getboolean('CONFIG_ATM_SPLIT_IMG')
        if not is_split_img:
            self.ensure_output('bin')

        self.cfg_cmd = []
        if self.openocd_config is not None:
            self.cfg_cmd = ['-f', self.openocd_config]

        if self.jlink:
            os.environ['JLINK_SERIAL'] = self.device
            os.environ['SWDIF'] = 'JLINK'
        else:
            os.environ["SYDNEY_SERIAL"] = self.device
            os.environ['SWDIF'] = 'FTDI'
        if command == 'flash':
            self.logger.debug('Flashing on Atmosic platform ' + self.atm_plat)
            if self.atm_plat == 'atm2':
                self.do_flash_atm2(**kwargs)
            elif self.atm_plat == 'atmx3' or self.atm_plat == 'atm34':
                self.do_flash_atmx3(**kwargs)
            elif self.memory_space is not None:
                for file in self.hex_name:
                    target_memory = self.find_target_memory_space(file, self.memory_spaces)
                    if target_memory is None:
                        print("No matching memory space found for the given hex file.")
                    if target_memory["type"] == "FLASH":
                        print(f"Hex file will be programmed into: {target_memory}")
                        self.do_load_flash(**kwargs)
                    else:
                        print("No matching memory space found for the given hex file.")
            else:
                self.logger.error('Flashing unsupported for platform')
                sys.exit(1)
        elif command in ('attach', 'debug'):
            self.do_attach(command, **kwargs)

    def do_reset_target(self):
        with _temp_environ(FTDI_BENIGN_BOOT='1', FTDI_HARD_RESET='1'):
            self.call(self.openocd_cmd + self.cfg_cmd + [
                '-c init',
                '-c release_reset',
                '-c sleep 100',
                '-c set_normal_boot',
                '-c exit',
            ])

    def do_flash_atm2(self, **kwargs):
        region_start = self.build_config['CONFIG_FLASH_LOAD_OFFSET']
        region_size = self.build_config['CONFIG_FLASH_LOAD_SIZE']
        load_address = self.flash_address_from_build_conf(self.build_config)
        print("Flash: Start(%#x) Size(%#x) Load(%#x)" % (region_start,
            region_size, load_address))
        bin_file = str.replace(self.cfg.bin_file, "\\", "\\\\")
        cmd_prefix = self.openocd_cmd + self.cfg_cmd
        cmd_flash = cmd_prefix + ['-c init', '-c sydney_load_flash ' +
            bin_file + ' ' + str(region_start) + ' ' +
            str(region_size) + ' ' + str(load_address)]
        if self.verify:
            cmd_flash += ['-c sydney_verify_flash ' + bin_file +
            ' ' + str(load_address)]
        if not self.noreset:
            cmd_flash += ['-c set _RESET_HARD_ON_EXIT 1']
        cmd_flash += ['-c exit']
        self.do_reset_target()
        cmd_flash = [item.replace("\\", "/") for item in cmd_flash]
        self.check_call(cmd_flash)

    def do_flash_atmx3(self, **kwargs):
        is_split_img = self.build_config.getboolean('CONFIG_ATM_SPLIT_IMG')
        if is_split_img:
            if self.use_elf:
                self.logger.error('--use_elf does not support split images')
                sys.exit(1)

        if self.fast_load:
            if not self.bin_name:
                self.logger.error('The fast load requires bin file')
                sys.exit(1)
        if self.cfg.hex_file is None and self.use_elf is None:
            self.logger.error('atmx3 requires hex')
            sys.exit(1)
        self.do_reset_target()
        cmd_prefix = self.openocd_cmd + self.cfg_cmd
        if self.fast_load:
            cmd_flash = cmd_prefix + ['-c init', '-c atmx3_load_ram_image ' + self.fl_bin]
        else:
            cmd_flash = cmd_prefix + ['-c init', '-c verify_rom_version']
        if self.erase_flash:
            if self.fast_load:
                FL_CMD_ERASE = '0x02'
                cmd_flash += ['-c atm_fast_load 0xFFFFFFFF ' + FL_CMD_ERASE + ' 0x10000']
                cmd_flash += ['-c atm_fast_load 0xFFFFFFFF ' + FL_CMD_ERASE + ' 0x200000']
            else:
                cmd_flash += ['-c catch {atm_erase_flash}']
                cmd_flash += ['-c atm_erase_rram_all']
        if self.fast_load:
            FL_CMD_WRITE = '0x01'
            if self.verify:
                FL_CMD_WRITE = '0x05'
            addr_list = self.fl_prog_addr.split(',')
            for index, addr in enumerate(addr_list):
                cmd_flash += ['-c atm_fast_load ' + self.bin_name[index] + ' ' + FL_CMD_WRITE + ' ' + addr]
        else:
            if self.use_elf:
                if os.path.isabs(self.elf_name[0]):
                    image = [self.elf_name[0]]
                else:
                    image = [str.replace(path.join(os.path.dirname(os.path.abspath(os.environ['ZEPHYR_BASE'])), self.elf_name[0]), "\\", "\\\\")]
            else:
                image = self.hex_name
            if is_split_img:
                region_size = self.build_config['CONFIG_FLASH_LOAD_SIZE']
                if (len(image) != 2):
                    self.logger.error('2 images required when programming split image')
                    sys.exit(1)
                cmd_flash += ['-c atm_load_rram ' + image[0]]
                if self.verify:
                    cmd_flash += ['-c atm_verify_rram ' + image[0]]
                cmd_flash += ['-c atm_load_flash ' + image[1] + " 0 " + str(region_size)]
                if self.verify:
                    cmd_flash += ['-c atm_verify_flash ' + image[1]]
            else:
                for img in image:
                    cmd_flash += ['-c atm_load_rram ' + img]
                    if self.verify:
                        cmd_flash += ['-c atm_verify_rram ' + img]
        if not self.noreset and not self.fast_load:
            cmd_flash += ['-c set _RESET_HARD_ON_EXIT 1']
        cmd_flash += ['-c exit']
        cmd_flash = [item.replace("\\", "/") for item in cmd_flash]
        self.logger.debug('cmd_flash: %s'%(' '.join(cmd_flash)))
        if self.fast_load:
            with _temp_environ(FAST_LOAD='1'):
                self.check_call(cmd_flash)
                self.do_reset_target()
                cmd_flash = cmd_prefix
                cmd_flash += ['-c init']
                cmd_flash += ['-c verify_rom_version']
                if not self.noreset:
                    cmd_flash += ['-c set _RESET_HARD_ON_EXIT 1']
                cmd_flash += ['-c exit']
                cmd_flash = [item.replace("\\", "/") for item in cmd_flash]
                self.check_call(cmd_flash)
        else:
            self.check_call(cmd_flash)

    def do_load_flash(self, **kwargs):
        region_start = self.build_config['CONFIG_FLASH_LOAD_OFFSET']
        region_size = self.build_config['CONFIG_FLASH_LOAD_SIZE']
        load_address = self.flash_address_from_build_conf(self.build_config)
        self.logger.debug("Flash: Start(%#x) Size(%#x) Load(%#x)", region_start, region_size, load_address)

        if self.fast_load:
            if not self.bin_name:
                self.logger.error('The fast load requires bin file')
                sys.exit(1)
        self.do_reset_target()
        cmd_prefix = self.openocd_cmd + self.cfg_cmd
        if self.fast_load:
            cmd_flash = cmd_prefix + ['-c init', '-c atmx3_load_ram_image ' + self.fl_bin]
        else:
            cmd_flash = cmd_prefix + ['-c init']
        if self.erase_flash:
            if self.fast_load:
                FL_CMD_ERASE = '0x02'
                cmd_flash += ['-c atm_fast_load 0xFFFFFFFF ' + FL_CMD_ERASE + ' 0x200000']
            else:
                cmd_flash += ['-c catch {atm_erase_flash}']
        if self.fast_load:
            FL_CMD_WRITE = '0x01'
            if self.verify:
                FL_CMD_WRITE = '0x05'
            addr_list = self.fl_prog_addr.split(',')
            for index, addr in enumerate(addr_list):
                cmd_flash += ['-c atm_fast_load ' + self.bin_name[index] + ' ' + FL_CMD_WRITE + ' ' + addr]
        else:
            if self.use_elf:
                if os.path.isabs(self.elf_name[0]):
                    image = [self.elf_name[0]]
                else:
                    image = [str.replace(path.join(os.path.dirname(os.path.abspath(os.environ['ZEPHYR_BASE'])), self.elf_name[0]), "\\", "\\\\")]
            else:
                image = self.hex_name

            for img in image:
                cmd_flash += ['-c atm_load_flash ' + img + ' ' + str(region_start) + ' ' +
                    str(region_size)]
                if self.verify:
                    cmd_flash += ['-c atm_verify_flash ' + img]
        self.logger.debug('self.rom_image: %s', self.rom_image)
        if self.prog_rom:
            cmd_flash += ['-c unlock_fpga_rom ']
            cmd_flash += ['-c puts -nonewline [load_image ' + self.rom_image + '] ']
            cmd_flash += ['-c lock_fpga_rom']
        if not self.noreset and not self.fast_load:
            cmd_flash += ['-c set _RESET_HARD_ON_EXIT 1']
        cmd_flash += ['-c exit']
        cmd_flash = [item.replace("\\", "/") for item in cmd_flash]
        self.logger.debug('cmd_flash: %s', ' '.join(cmd_flash))
        if self.fast_load:
            with _temp_environ(FAST_LOAD='1'):
                self.check_call(cmd_flash)
                self.do_reset_target()
                cmd_flash = cmd_prefix
                cmd_flash += ['-c init']
                cmd_flash += ['-c verify_rom_version']
                if not self.noreset:
                    cmd_flash += ['-c set _RESET_HARD_ON_EXIT 1']
                cmd_flash += ['-c exit']
                cmd_flash = [item.replace("\\", "/") for item in cmd_flash]
                self.check_call(cmd_flash)
        else:
            self.check_call(cmd_flash)

    def do_attach(self, command, **kwargs):
        if self.gdb_cmd is None:
            raise ValueError('Cannot debug; no gdb specified')
        if self.elf_name is None:
            raise ValueError('Cannot debug; no .elf specified')

        pre_init_cmd = []
        server_cmd = (self.openocd_cmd + self.cfg_cmd +
                      ['-c', 'tcl_port {}'.format(self.tcl_port),
                       '-c', 'telnet_port {}'.format(self.telnet_port),
                       '-c', 'gdb_port {}'.format(self.gdb_port)] +
                      pre_init_cmd + ['-c', 'init',
                                      '-c', 'targets',
                                      '-c', 'halt'])
        gdb_cmd = (self.gdb_cmd + ['-x', self.gdb_config] +
                   ['-ex', 'target extended-remote :{}'.format(self.gdb_port),
                    self.elf_name[0]])
        if command == 'debug':
            self.do_flash_atmx3()
        self.require(gdb_cmd[0])
        self.run_server_and_client(server_cmd, gdb_cmd)
