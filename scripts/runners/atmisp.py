# Copyright (c) 2017 Linaro Limited.
# Copyright (c) Atmosic 2021-2026
#
# SPDX-License-Identifier: Apache-2.0

"""Runner for flashing with Atmosic In-System Programming Tool."""

from os import path
from pathlib import Path
import contextlib
import platform
import os
import sys
import subprocess
import re
import yaml

from intelhex import IntelHex

# pylint: disable=import-error
from runners.core import ZephyrBinaryRunner, RunnerCaps, BuildConfiguration

sys.path.append(os.fspath(Path(__file__).parent.parent.parent / "tools" / "scripts"))
# pylint: disable=wrong-import-position
from atm_openocd import (
    get_board_dirs_from_board,
    get_openocd_config_from_board_dirs,
)

DEFAULT_OPENOCD_TCL_PORT = 6333
DEFAULT_OPENOCD_TELNET_PORT = 4444
DEFAULT_OPENOCD_GDB_PORT = 3333
DEFAULT_OPENOCD_RESET_HALT_CMD = "reset init"
DEFAULT_OPENOCD_TARGET_HANDLE = "_TARGETNAME"


@contextlib.contextmanager
def _temp_environ(**update):
    env = os.environ
    update = update or {}

    try:
        env.update(update)
        yield
    finally:
        for i in update:
            env.pop(i)


def _is_last_domain(build_dir):
    """Check if the current build_dir is the last domain in sysbuild flash_order.

    For sysbuild, domains.yaml is in the parent directory of each domain's build_dir.
    Returns True if this is the last domain or if not using sysbuild.
    """
    # Get the sysbuild root directory (parent of domain build_dir)
    sysbuild_dir = path.dirname(build_dir)
    domains_file = path.join(sysbuild_dir, "domains.yaml")

    if not path.exists(domains_file):
        # Not a sysbuild, treat as single domain (always last)
        return True

    try:
        with open(domains_file, "r", encoding="utf-8") as f:
            domains_data = yaml.safe_load(f)

        flash_order = domains_data.get("flash_order", [])
        if not flash_order:
            # No flash_order defined, use domains list
            domains_list = domains_data.get("domains", [])
            flash_order = [d["name"] for d in domains_list]

        if not flash_order:
            return True

        # Get current domain name from build_dir
        # build_dir is like: /path/to/build/<domain_name>
        current_domain = path.basename(build_dir)

        # Check if current domain is the last in flash_order
        return current_domain == flash_order[-1]
    except (yaml.YAMLError, KeyError, IndexError):
        # If parsing fails, assume it's the last domain to be safe
        return True


# pylint: disable=too-many-instance-attributes
class AtmispBinaryRunner(ZephyrBinaryRunner):
    """Runner front-end for atmisp."""

    # pylint: disable=too-many-arguments, too-many-locals, too-many-branches, too-many-statements
    def __init__(
        self,
        cfg,
        device,
        *,
        rram=False,
        jlink=False,
        atm_openocd_base=None,
        atm_openocd_search=None,
        no_atm_openocd=False,
        openocd_config=None,
        verify=False,
        erase_all=False,
        erase_flash=False,
        erase_flash_size=None,
        erase_flash_addr=None,
        erase_rram=False,
        ext_flash_base_addr=0x200000,
        noreset=False,
        gdb_config=None,
        use_elf=None,
        factory_data_file=False,
        fast_load=False,
        fast_load_bin="",
        atmwstk=None,
        pre_init=None,
        no_init=False,
        target_handle=DEFAULT_OPENOCD_TARGET_HANDLE,
        no_targets=False,
        reset_halt_cmd=DEFAULT_OPENOCD_RESET_HALT_CMD,
        tcl_port=DEFAULT_OPENOCD_TCL_PORT,
        telnet_port=DEFAULT_OPENOCD_TELNET_PORT,
        gdb_port=DEFAULT_OPENOCD_GDB_PORT,
        prog_rom=False,
        rom_image=None,
        memory_space=None,
        dl=False,
        reset_only=False,
    ):
        super().__init__(cfg)
        self.reset_only = reset_only

        print(cfg.board_dir)
        if not openocd_config:
            try:
                openocd_config = get_openocd_config_from_board_dirs([cfg.board_dir])
            except FileNotFoundError:
                self.logger.warning("Cannot locate openocd config")
        if not openocd_config:
            try:
                board_name = BuildConfiguration(cfg.build_dir).get("CONFIG_BOARD")
                board_dirs = get_board_dirs_from_board(board_name)
                openocd_config = get_openocd_config_from_board_dirs(board_dirs)
            except FileNotFoundError:
                self.logger.warning("Cannot locate openocd config")

        if not openocd_config:
            default = path.join(cfg.board_dir, "support", "openocd.cfg")
            if path.exists(default):
                openocd_config = default
        self.openocd_config = openocd_config

        if self.openocd_config is not None and path.exists(self.openocd_config):
            search_args = ["-s", path.dirname(self.openocd_config)]
        else:
            search_args = []

        if atm_openocd_search is not None:
            search_args.extend(["-s", atm_openocd_search])

        if jlink and no_atm_openocd:
            self.logger.error("Must use Atmosic OpenOCD with J-Link")
            sys.exit(1)

        if not no_atm_openocd and atm_openocd_base is None:
            # Unfortunately the env var ZEPHYR_MODULES is only defined during
            # Zephyr CMake builds... so we have to derive that from ZEPHYR_BASE
            zephyr_modules = os.path.join(
                os.path.dirname(os.path.abspath(os.environ["ZEPHYR_BASE"])), "modules"
            )
            atm_openocd_base = os.path.join(
                zephyr_modules, "hal", "atmosic_lib", "tools", "openocd"
            )
            atm_openocd_search = os.path.join(atm_openocd_base, "tcl")

        if atm_openocd_base is not None:
            plat = platform.system()
            suffix = ""
            if plat.startswith("MSYS") or plat == "Windows":
                plat = "Windows_NT"
                suffix = ".exe"
            elif plat == "Darwin":
                arch = platform.machine().lower()
                plat = f"Darwin/{arch}"
            openocd = os.path.join(atm_openocd_base, "bin", plat, "openocd" + suffix)
            atm_openocd_search = os.path.join(atm_openocd_base, "tcl")
            self.logger.debug(f"Using ATM OpenOCD '{openocd}'")
        elif cfg.openocd is not None:
            openocd = cfg.openocd
        else:
            openocd = "openocd"

        if cfg.openocd_search is not None and atm_openocd_base is None:
            for search_dir in cfg.openocd_search:
                search_args.extend(["-s", search_dir])

        if atm_openocd_search is not None:
            search_args.extend(["-s", atm_openocd_search])
        self.openocd_cmd = [openocd] + search_args

        if not gdb_config:
            default = path.join(cfg.board_dir, "support", "atm.gdb")
            if path.exists(default):
                gdb_config = default

        # Initialize build configuration early to check SOC capabilities
        self.build_config = BuildConfiguration(cfg.build_dir)

        # Check if the target SOC has RRAM support based on device tree
        has_rram = self.build_config.getboolean(
            "CONFIG_DT_HAS_ATMOSIC_RRAM_CONTROLLER_ENABLED"
        )

        self.erase_all = erase_all
        if erase_all:
            self.erase_flash = True
            # Only enable RRAM erase if SOC supports it
            if has_rram:
                self.erase_rram = True
            else:
                self.logger.warning(
                    "--erase_all: RRAM not supported on this SOC, "
                    "skipping RRAM erase (flash erase will proceed)"
                )
        else:
            self.erase_flash = erase_flash
            self.erase_rram = erase_rram
            if not has_rram and self.erase_rram:
                # Reject RRAM erase if SOC does not support it
                self.logger.error("RRAM is not supported on this SOC")
                sys.exit(1)
        self.erase_flash_size = erase_flash_size
        self.erase_flash_addr = erase_flash_addr
        self.ext_flash_base_addr = ext_flash_base_addr
        self.rram = rram
        self.openocd_config = openocd_config
        self.gdb_config = gdb_config
        self.device = device
        self.pre_init = pre_init or []
        self.init_arg = [] if no_init else ["-c init"]
        self.targets_arg = [] if no_targets else ["-c targets"]
        self.reset_halt_cmd = reset_halt_cmd
        self.target_handle = target_handle
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
        self.dl = dl
        is_split_img = self.build_config.getboolean("CONFIG_ATM_SPLIT_IMG")
        if cfg.hex_file is not None:
            if is_split_img:
                # Runner hexfile string could include multiple files,
                # delimited by ','
                self.hex_name = [
                    Path(hex_f).as_posix() for hex_f in cfg.hex_file.split(",")
                ]
                self.bin_name = [
                    Path(hex_f).with_suffix(".bin").as_posix()
                    for hex_f in cfg.hex_file.split(",")
                ]
            else:
                self.hex_name = [Path(cfg.hex_file).as_posix()]
                self.bin_name = [Path(cfg.hex_file).with_suffix(".bin").as_posix()]
        if atmwstk:
            atmwstk_bin_name = f"{atmwstk}.bin"
            atmwstk_hex_name = f"{atmwstk}.hex"
            atmwstk_elf_name = f"{atmwstk}.elf"
            self.bin_name.append(Path(atmwstk_bin_name).as_posix())
            self.hex_name.append(Path(atmwstk_hex_name).as_posix())
            self.elf_name.append(Path(atmwstk_elf_name).as_posix())
        if factory_data_file:
            factory_hex_path = os.path.join(
                cfg.build_dir, "zephyr", "zephyr_factory.hex"
            )
            if os.path.exists(factory_hex_path):
                self.hex_name.append(Path(factory_hex_path).as_posix())
            factory_bin_path = os.path.join(
                cfg.build_dir, "zephyr", "zephyr_factory.bin"
            )
            if os.path.exists(factory_bin_path):
                self.bin_name.append(Path(factory_bin_path).as_posix())
            factory_elf_path = os.path.join(
                cfg.build_dir, "zephyr", "zephyr_factory.elf"
            )
            if os.path.exists(factory_elf_path):
                self.elf_name.append(Path(factory_elf_path).as_posix())
            settings_hex_path = os.path.join(
                cfg.build_dir, "zephyr", "zephyr_settings.hex"
            )
            if os.path.exists(settings_hex_path):
                self.hex_name.append(Path(settings_hex_path).as_posix())
            settings_bin_path = os.path.join(
                cfg.build_dir, "zephyr", "zephyr_settings.bin"
            )
            if os.path.exists(settings_bin_path):
                self.bin_name.append(Path(settings_bin_path).as_posix())
            settings_elf_path = os.path.join(
                cfg.build_dir, "zephyr", "zephyr_settings.elf"
            )
            if os.path.exists(settings_elf_path):
                self.elf_name.append(Path(settings_elf_path).as_posix())

        self.use_elf = use_elf
        if fast_load and not use_elf:
            self.fast_load = True
            self.fl_bin = fast_load_bin
            # The objdump locate at the same directory with gdb
            objdump = cfg.gdb.replace("-gdb-py", "-objdump").replace("-gdb", "-objdump")
            if not os.path.exists(objdump):
                self.logger.error("<fast_load> %s not exist", objdump)
                sys.exit(1)
            self.fl_prog_addr = None

            for file in self.hex_name:
                content = subprocess.run(
                    [objdump, "-h", file], capture_output=True, text=True, check=True
                )
                pattern = re.compile(
                    r"\s+0\s+.sec1\s+[0-9a-fA-F]+\s+[0-9a-fA-F]+\s+"
                    r"([0-9a-fA-F]+)\s+"
                )
                match = pattern.search(content.stdout)
                if match:
                    hex_addr = "0x" + match.group(1)
                    int_addr = int(hex_addr, 16) & 0xEFFFFFFF
                    if self.fl_prog_addr is None:
                        self.fl_prog_addr = hex(int_addr)
                    else:
                        self.fl_prog_addr += ","
                        self.fl_prog_addr += hex(int_addr)

            self.logger.info("<fast_load> program address: %s", self.fl_prog_addr)
        else:
            self.fast_load = False
            self.fl_bin = None
        self.cfg_cmd = []

    @staticmethod
    def parse_memory_spaces(memory_space_str):
        """parse memory spaces"""
        if not memory_space_str:  # Handles None or empty string
            return []
        memory_spaces = []
        entries = memory_space_str.split()
        for entry in entries:
            try:
                mem_type, start, size = entry.split(",")
                start = int(start, 16)
                size = int(size, 16)
                memory_spaces.append({"type": mem_type, "start": start, "size": size})
            except ValueError as e:
                raise ValueError(
                    f"Invalid memory_space format: {entry}. Expected format: TYPE,START,SIZE"
                ) from e
        return memory_spaces

    @staticmethod
    def find_target_memory_space(hex_file, memory_spaces):
        """find target memory space"""
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
        """name of this runner"""
        return "atmisp"

    @classmethod
    def capabilities(cls):
        """capabilities of this runner"""
        return RunnerCaps(commands={"flash", "attach", "debug", "debugserver"})

    @classmethod
    def do_add_parser(cls, parser):
        """add parser of this runner"""
        # required argument(s)
        parser.add_argument(
            "--device",
            required=True,
            help="selects FTDI interface, e.g: ATRDIxxxx, or JLINK",
        )

        # optional argument(s)
        parser.add_argument(
            "--erase_all",
            default=False,
            required=False,
            action="store_true",
            help="Erase all",
        )
        parser.add_argument(
            "--erase_flash",
            default=False,
            required=False,
            action="store_true",
            help="Erase flash, if not --erase_flash_size, erase whole flash by default",
        )
        parser.add_argument(
            "--erase_flash_addr",
            required=False,
            help="Specify erase flash addr as 0x200000, "
            "only take effect with --erase_flash or --erase_all.",
        )
        parser.add_argument(
            "--erase_flash_size",
            required=False,
            help="Specify erase flash size as 0x800000, "
            "only take effect with --erase_flash or --erase_all.",
        )
        parser.add_argument(
            "--erase_rram",
            default=False,
            required=False,
            action="store_true",
            help="Erase RRAM",
        )
        parser.add_argument(
            "--rram",
            default=False,
            required=False,
            action="store_true",
            help="If primary application storage is RRAM",
        )
        parser.add_argument(
            "--jlink",
            default=False,
            required=False,
            action="store_true",
            help="if using JLINK",
        )
        parser.add_argument(
            "--no_atm_openocd",
            default=False,
            required=False,
            action="store_true",
            help="Do not use Atmosic OpenOCD",
        )
        parser.add_argument(
            "--atm_openocd_base",
            required=False,
            help="Path to Atmosic OpenOCD binaries",
        )
        parser.add_argument(
            "--atm_openocd_search",
            required=False,
            help="Search path to openocd's tcl scripts",
        )
        parser.add_argument(
            "--openocd_config",
            required=False,
            help="if given, override default config file (full path)",
        )

        parser.add_argument(
            "--verify",
            default=False,
            required=False,
            action="store_true",
            help="verify writes, default False",
        )

        parser.add_argument(
            "--noreset",
            default=False,
            required=False,
            action="store_true",
            help="Do not reset the device after flashing, default False",
        )

        parser.add_argument(
            "--use-elf",
            default=False,
            required=False,
            action="store_true",
            dest="use_elf",
            help="Use ELF rather than HEX",
        )

        parser.add_argument(
            "--factory_data_file",
            default=False,
            required=False,
            action="store_true",
            help="Enable factory data file",
        )

        parser.add_argument(
            "--ext_flash_base_addr",
            default="0x200000",
            required=False,
            help="Base address of external flash",
        )
        parser.add_argument(
            "--fast_load",
            default=False,
            required=False,
            action="store_true",
            help="Enable fast load feature",
        )
        parser.add_argument(
            "--fast_load_bin",
            default="",
            required=False,
            help="Path to fast_load.bin",
        )

        parser.add_argument(
            "--atmwstk",
            required=False,
            help="atmwstk path and file prefix of bin, elf and hex to be programmed"
            "at the same time",
        )
        # debug argument(s)
        parser.add_argument(
            "--gdb_config",
            required=False,
            help="if given, overrides default config file (full path)",
        )

        parser.add_argument(
            "--tcl-port",
            default=DEFAULT_OPENOCD_TCL_PORT,
            help="openocd TCL port, defaults to 6333",
        )

        parser.add_argument(
            "--telnet-port",
            default=DEFAULT_OPENOCD_TELNET_PORT,
            help="openocd telnet port, defaults to 4444",
        )

        parser.add_argument(
            "--gdb-port",
            default=DEFAULT_OPENOCD_GDB_PORT,
            help="openocd gdb port, defaults to 3333",
        )

        parser.add_argument(
            "--prog_rom",
            default=False,
            required=False,
            action="store_true",
            help="Program ROM",
        )

        parser.add_argument(
            "--rom_image",
            required=False,
            help="if given, override default rom_image file (full path)",
        )

        parser.add_argument(
            "--memory_space",
            required=False,
            help='specify the memory space:"TYPE1,start_address,space_size TYPE2,'
            'start_address,space_size"',
        )
        parser.add_argument(
            "--target-handle",
            default=DEFAULT_OPENOCD_TARGET_HANDLE,
            help=f"""Internal handle used in openocd targets cfg
                            files, defaults to "{DEFAULT_OPENOCD_TARGET_HANDLE}".
                            """,
        )
        parser.add_argument(
            "--dl",
            default=False,
            required=False,
            action="store_true",
            help="if using DL board",
        )

        parser.add_argument(
            "--reset_only",
            default=False,
            required=False,
            action="store_true",
            help="skip flash operation and only perform reset",
        )

    @classmethod
    def do_create(cls, cfg, args):
        """create this runner"""
        return AtmispBinaryRunner(
            cfg,
            device=args.device,
            rram=args.rram,
            jlink=args.jlink,
            atm_openocd_base=args.atm_openocd_base,
            atm_openocd_search=args.atm_openocd_search,
            no_atm_openocd=args.no_atm_openocd,
            openocd_config=args.openocd_config,
            gdb_config=args.gdb_config,
            verify=args.verify,
            noreset=args.noreset,
            use_elf=args.use_elf,
            erase_flash=args.erase_flash,
            erase_flash_addr=(
                int(args.erase_flash_addr, 16) if args.erase_flash_addr else None
            ),
            erase_flash_size=(
                int(args.erase_flash_size, 16) if args.erase_flash_size else None
            ),
            ext_flash_base_addr=int(args.ext_flash_base_addr, 16),
            factory_data_file=args.factory_data_file,
            fast_load=args.fast_load,
            fast_load_bin=args.fast_load_bin,
            target_handle=args.target_handle,
            atmwstk=args.atmwstk,
            prog_rom=args.prog_rom,
            rom_image=args.rom_image,
            memory_space=args.memory_space,
            erase_all=args.erase_all,
            erase_rram=args.erase_rram,
            dl=args.dl,
            reset_only=args.reset_only,
        )

    def print_gdbserver_message(self):
        """print gdbserver message"""
        if not self.thread_info_enabled:
            thread_msg = "; no thread info available"
        elif self.supports_thread_info():
            thread_msg = "; thread info enabled"
        else:
            thread_msg = "; update OpenOCD software for thread info"
        self.logger.info(
            "OpenOCD GDB server running on port " f"{self.gdb_port}{thread_msg}"
        )

    # Converts a version string component to integer
    @staticmethod
    def to_num(number):
        dev_match = re.search(r"^\d*\+dev", number)
        dev_version = not dev_match is None

        num_match = re.search(r"^\d*", number)
        num = int(num_match.group(0))

        if dev_version:
            num += 1

        return num

    def read_version(self):
        self.require(self.openocd_cmd[0])

        # OpenOCD prints in stderr, need redirect to get output
        out = self.check_output(
            [self.openocd_cmd[0], "--version"], stderr=subprocess.STDOUT
        ).decode()

        version_match = re.search(r"Open On-Chip Debugger (\d+.\d+.\d+)", out)
        version = version_match.group(1).split(".")

        return [AtmispBinaryRunner.to_num(i) for i in version]

    def supports_thread_info(self):
        # Zephyr rtos was introduced after 0.11.0
        (major, minor, rev) = self.read_version()
        return (major, minor, rev) > (0, 11, 0)

    def do_run(self, command, **kwargs):
        """perform this runner"""
        self.require(self.openocd_cmd[0])
        is_split_img = self.build_config.getboolean("CONFIG_ATM_SPLIT_IMG")
        if not is_split_img:
            self.ensure_output("bin")

        if self.openocd_config is not None:
            self.cfg_cmd = ["-f", self.openocd_config]

        if self.jlink:
            os.environ["JLINK_SERIAL"] = self.device
            os.environ["SWDIF"] = "JLINK"
        else:
            os.environ["SYDNEY_SERIAL"] = self.device
            os.environ["SWDIF"] = "FTDI"
            if self.dl:
                os.environ["SWDBOARD"] = "DL"
        if command == "flash":
            if self.reset_only:
                self.logger.info("Skipping flash operation (--reset_only specified)")

                # Only reset on the last domain in sysbuild
                if not _is_last_domain(self.cfg.build_dir):
                    self.logger.info("Not the last domain, skipping reset")
                    return

                self.logger.info(
                    "Last domain - performing reset to run existing firmware..."
                )
                # FTDI needs extra step to set GPIO pins first
                if not self.jlink:
                    self.do_reset_target()
                # Connect SWD and trigger reset on exit
                self.call(
                    self.openocd_cmd
                    + self.cfg_cmd
                    + ["-c init", "-c set _RESET_HARD_ON_EXIT 1", "-c exit"]
                )
                return
            storage_type = "Ext Flash"
            if self.rram:
                storage_type = "RRAM"
                if is_split_img:
                    storage_type += " + Ext Flash"
            self.logger.debug("Flashing to " + storage_type)
            if self.rram:
                self.do_flash_rram(**kwargs)
            elif self.memory_space is not None:
                if any(m["type"] == "ROM" for m in self.memory_spaces):
                    self.do_flash_rom_only(**kwargs)
                else:
                    found_flash = False
                    for file in self.hex_name:
                        target_memory = self.find_target_memory_space(
                            file, self.memory_spaces
                        )
                        if target_memory is None:
                            print(
                                "No matching memory space found for the given hex file."
                            )
                        if target_memory["type"] == "FLASH":
                            print(f"Hex file will be programmed into: {target_memory}")
                            found_flash = True
                        else:
                            print(
                                "No matching memory space found for the given hex file."
                            )
                    if found_flash:
                        self.do_load_flash(**kwargs)
            else:
                self.logger.error("Flashing unsupported for platform")
                sys.exit(1)
        elif command in ("attach", "debug"):
            self.do_attach(command, **kwargs)
        else:
            self.do_debugserver(**kwargs)

    def do_reset_target(self):
        """perform reset target"""
        with _temp_environ(FTDI_BENIGN_BOOT="1", FTDI_HARD_RESET="1"):
            self.call(
                self.openocd_cmd
                + self.cfg_cmd
                + [
                    "-c init_rr_nb_exit",
                ]
            )

    def do_flash_rram(self, **kwargs):
        """perform flash for RRAM, or RRAM + Ext Flash for split image"""
        _ = kwargs
        is_split_img = self.build_config.getboolean("CONFIG_ATM_SPLIT_IMG")
        if is_split_img:
            if self.use_elf:
                self.logger.error("--use_elf does not support split images")
                sys.exit(1)

        if self.fast_load:
            if not self.bin_name:
                self.logger.error("The fast load requires bin file")
                sys.exit(1)
        if self.cfg.hex_file is None and self.use_elf is None:
            self.logger.error("RRAM requires hex")
            sys.exit(1)
        self.do_reset_target()
        cmd_prefix = self.openocd_cmd + self.cfg_cmd
        if self.fast_load:
            cmd_flash = cmd_prefix + [
                "-c init",
                "-c atmx3_load_ram_image " + self.fl_bin,
            ]
        else:
            cmd_flash = cmd_prefix + ["-c init", "-c verify_rom_version"]
        if self.erase_flash or self.erase_rram:
            if self.fast_load:
                fl_cmd_erase = "0x02"
                if self.erase_rram:
                    cmd_flash += [
                        "-c atm_fast_load 0xFFFFFFFF " + fl_cmd_erase + " 0x10000"
                    ]
                if self.erase_flash:
                    if self.erase_flash_size:
                        erase_size = hex(self.erase_flash_size)
                    else:
                        erase_size = "0xFFFFFFFF"
                    if self.erase_flash_addr:
                        erase_addr = hex(self.erase_flash_addr)
                    else:
                        erase_addr = hex(self.ext_flash_base_addr)
                    cmd_flash += [
                        "-c atm_fast_load "
                        + erase_size
                        + " "
                        + fl_cmd_erase
                        + " "
                        + erase_addr
                    ]
            else:
                if self.erase_flash:
                    if self.erase_flash_size:
                        erase_size = hex(self.erase_flash_size)
                        if self.erase_flash_addr:
                            erase_addr = hex(
                                self.erase_flash_addr - self.ext_flash_base_addr
                            )
                        else:
                            erase_addr = "0x0"
                        cmd_flash += [
                            "-c atm_erase_flash " + erase_size + " " + erase_addr
                        ]
                    else:
                        cmd_flash += ["-c catch {atm_erase_flash}"]
                if self.erase_rram:
                    cmd_flash += ["-c atm_erase_rram_all"]
        if self.fast_load:
            fl_cmd_write = "0x01"
            if self.verify:
                fl_cmd_write = "0x05"
            addr_list = self.fl_prog_addr.split(",")
            for index, addr in enumerate(addr_list):
                cmd_flash += [
                    "-c atm_fast_load "
                    + self.bin_name[index]
                    + " "
                    + fl_cmd_write
                    + " "
                    + addr
                ]
        else:
            if self.use_elf:
                if os.path.isabs(self.elf_name[0]):
                    image = [self.elf_name[0]]
                else:
                    image = [
                        str.replace(
                            path.join(
                                os.path.dirname(
                                    os.path.abspath(os.environ["ZEPHYR_BASE"])
                                ),
                                self.elf_name[0],
                            ),
                            "\\",
                            "\\\\",
                        )
                    ]
            else:
                image = self.hex_name
            if is_split_img:
                region_size = self.build_config["CONFIG_FLASH_LOAD_SIZE"]
                if len(image) != 2:
                    self.logger.error("2 images required when programming split image")
                    sys.exit(1)
                cmd_flash += ["-c atm_load_rram " + image[0]]
                if self.verify:
                    cmd_flash += ["-c atm_verify_rram " + image[0]]
                cmd_flash += [
                    "-c atm_load_flash " + image[1] + " 0 " + str(region_size)
                ]
                if self.verify:
                    cmd_flash += ["-c atm_verify_flash " + image[1]]
            else:
                for img in image:
                    cmd_flash += ["-c atm_load_rram " + img]
                    if self.verify:
                        cmd_flash += ["-c atm_verify_rram " + img]
        if not self.noreset and not self.fast_load:
            cmd_flash += ["-c set _RESET_HARD_ON_EXIT 1"]
        cmd_flash += ["-c exit"]
        cmd_flash = [item.replace("\\", "/") for item in cmd_flash]
        self.logger.debug(f"cmd_flash: {' '.join(cmd_flash)}")
        if self.fast_load:
            with _temp_environ(FAST_LOAD="1"):
                self.check_call(cmd_flash)
                if self.noreset:
                    return
                self.do_reset_target()
                cmd_flash = cmd_prefix
                cmd_flash += ["-c init"]
                cmd_flash += ["-c verify_rom_version"]
                cmd_flash += ["-c set _RESET_HARD_ON_EXIT 1"]
                cmd_flash += ["-c exit"]
                cmd_flash = [item.replace("\\", "/") for item in cmd_flash]
                self.check_call(cmd_flash)
        else:
            self.check_call(cmd_flash)

    def do_load_flash(self, **kwargs):
        """perform load flash"""
        _ = kwargs
        if self.fast_load:
            if not self.bin_name:
                self.logger.error("The fast load requires bin file")
                sys.exit(1)
        self.do_reset_target()
        cmd_prefix = self.openocd_cmd + self.cfg_cmd
        if self.fast_load:
            cmd_flash = cmd_prefix + [
                "-c init",
                "-c atmx3_load_ram_image " + self.fl_bin,
            ]
        else:
            cmd_flash = cmd_prefix + ["-c init"]
        if self.erase_flash:
            if self.fast_load:
                fl_cmd_erase = "0x02"
                if self.erase_flash_size:
                    erase_size = hex(self.erase_flash_size)
                else:
                    erase_size = "0xFFFFFFFF"
                if self.erase_flash_addr:
                    erase_addr = hex(self.erase_flash_addr)
                else:
                    erase_addr = hex(self.ext_flash_base_addr)
                cmd_flash += [
                    "-c atm_fast_load "
                    + erase_size
                    + " "
                    + fl_cmd_erase
                    + " "
                    + erase_addr
                ]
            else:
                if self.erase_flash_size:
                    erase_size = hex(self.erase_flash_size)
                    if self.erase_flash_addr:
                        erase_addr = hex(
                            self.erase_flash_addr - self.ext_flash_base_addr
                        )
                    else:
                        erase_addr = "0x0"
                    cmd_flash += ["-c atm_erase_flash " + erase_size + " " + erase_addr]
                else:
                    cmd_flash += ["-c catch {atm_erase_flash}"]
        if self.fast_load:
            fl_cmd_write = "0x01"
            if self.verify:
                fl_cmd_write = "0x05"
            addr_list = self.fl_prog_addr.split(",")
            for index, addr in enumerate(addr_list):
                cmd_flash += [
                    "-c atm_fast_load "
                    + self.bin_name[index]
                    + " "
                    + fl_cmd_write
                    + " "
                    + addr
                ]
        else:
            if self.use_elf:
                if os.path.isabs(self.elf_name[0]):
                    image = [self.elf_name[0]]
                else:
                    image = [
                        str.replace(
                            path.join(
                                os.path.dirname(
                                    os.path.abspath(os.environ["ZEPHYR_BASE"])
                                ),
                                self.elf_name[0],
                            ),
                            "\\",
                            "\\\\",
                        )
                    ]
            else:
                image = self.hex_name

            for img in image:
                if self.use_elf:
                    region_start = self.build_config["CONFIG_FLASH_LOAD_OFFSET"]
                    region_size = self.build_config["CONFIG_FLASH_LOAD_SIZE"]
                    load_address = self.flash_address_from_build_conf(self.build_config)
                else:
                    ih = IntelHex(img)
                    img_start = ih.minaddr()
                    img_end = ih.maxaddr()
                    img_size = img_end - img_start + 1
                    region_start = (img_start & ~0x10000000) - self.ext_flash_base_addr
                    region_size = img_size
                    load_address = img_start
                self.logger.debug(
                    "Flash: Start(%#x) Size(%#x) Load(%#x)",
                    region_start,
                    region_size,
                    load_address,
                )
                cmd_flash += [
                    "-c atm_load_flash "
                    + img
                    + " "
                    + str(region_start)
                    + " "
                    + str(region_size)
                ]
                if self.verify:
                    cmd_flash += ["-c atm_verify_flash " + img]
        self.logger.debug("self.rom_image: %s", self.rom_image)
        if self.prog_rom:
            cmd_flash += ["-c unlock_fpga_rom "]
            cmd_flash += ["-c puts -nonewline [load_image " + self.rom_image + "] "]
            cmd_flash += ["-c lock_fpga_rom"]
        if not self.noreset and not self.fast_load:
            cmd_flash += ["-c set _RESET_HARD_ON_EXIT 1"]
        cmd_flash += ["-c exit"]
        cmd_flash = [item.replace("\\", "/") for item in cmd_flash]
        self.logger.debug("cmd_flash: %s", " ".join(cmd_flash))
        if self.fast_load:
            with _temp_environ(FAST_LOAD="1"):
                self.check_call(cmd_flash)
                self.do_reset_target()
                cmd_flash = cmd_prefix
                cmd_flash += ["-c init"]
                cmd_flash += ["-c verify_rom_version"]
                if not self.noreset:
                    cmd_flash += ["-c set _RESET_HARD_ON_EXIT 1"]
                cmd_flash += ["-c exit"]
                cmd_flash = [item.replace("\\", "/") for item in cmd_flash]
                self.check_call(cmd_flash)
        else:
            self.check_call(cmd_flash)

    def do_flash_rom_only(self, **kwargs):
        """Program FPGA ROM only (no flash/RRAM).

        Used when --memory_space contains a ROM-type entry (and neither
        --rram nor a FLASH-type memory_space is the target). Falls back
        to the compiled zephyr.elf when --rom_image is not supplied.
        """
        _ = kwargs
        rom_img = self.rom_image if self.rom_image else self.elf_name[0]
        self.logger.info("Programming FPGA ROM with: %s", rom_img)
        self.do_reset_target()
        cmd = self.openocd_cmd + self.cfg_cmd + ["-c init"]
        cmd += ["-c unlock_fpga_rom"]
        cmd += ["-c puts -nonewline [load_image " + rom_img + "]"]
        cmd += ["-c lock_fpga_rom"]
        if not self.noreset:
            cmd += ["-c set _RESET_HARD_ON_EXIT 1"]
        cmd += ["-c exit"]
        cmd = [item.replace("\\", "/") for item in cmd]
        self.logger.debug("cmd_flash: %s", " ".join(cmd))
        self.check_call(cmd)

    def do_debugserver(self, **kwargs):
        """perform debugserver"""
        _ = kwargs
        pre_init_cmd = []
        for i in self.pre_init:
            pre_init_cmd.append("-c")
            pre_init_cmd.append(i)

        if self.thread_info_enabled and self.supports_thread_info():
            pre_init_cmd.append("-c")
            rtos_command = f"${self.target_handle} configure -rtos Zephyr"
            pre_init_cmd.append(rtos_command)

        cmd = (
            self.openocd_cmd
            + self.cfg_cmd
            + [
                "-c",
                f"tcl_port {self.tcl_port}",
                "-c",
                f"telnet_port {self.telnet_port}",
                "-c",
                f"gdb_port {self.gdb_port}",
            ]
            + pre_init_cmd
            + self.init_arg
            + self.targets_arg
            + ["-c", self.reset_halt_cmd]
        )
        self.print_gdbserver_message()
        self.check_call(cmd)

    def do_attach(self, command, **kwargs):
        """perform attach"""
        _ = kwargs
        if self.gdb_cmd is None:
            raise ValueError("Cannot debug; no gdb specified")
        if self.elf_name is None:
            raise ValueError("Cannot debug; no .elf specified")

        pre_init_cmd = []
        server_cmd = (
            self.openocd_cmd
            + self.cfg_cmd
            + [
                "-c",
                f"tcl_port {self.tcl_port}",
                "-c",
                f"telnet_port {self.telnet_port}",
                "-c",
                f"gdb_port {self.gdb_port}",
            ]
            + pre_init_cmd
            + ["-c", "init", "-c", "targets", "-c", "halt"]
        )
        gdb_cmd = (
            self.gdb_cmd
            + ["-x", self.gdb_config]
            + ["-ex", f"target extended-remote :{self.gdb_port}", self.elf_name[0]]
        )
        if command == "debug":
            self.do_flash_rram()
        self.require(gdb_cmd[0])
        self.run_server_and_client(server_cmd, gdb_cmd)
