# Copyright (C) Atmosic 2024-2026
#
# SPDX-License-Identifier: LicenseRef-Atmosic

"""
@file atm_openocd.py

@brief Helper file for Atmosic openocd
"""

import argparse
import contextlib
import glob
import os
from pathlib import Path
import platform
import subprocess
import sys
import yaml

ZEPHYR_BASE = Path(__file__).parent.parent.parent.parent / "zephyr"
sys.path.append(os.fspath(ZEPHYR_BASE / "scripts"))
# pylint: disable=import-error,no-name-in-module,wrong-import-position
import list_boards
import zephyr_module
from west.manifest import Manifest


@contextlib.contextmanager
def _temp_environ(update_dict):
    """create a temp env context manager"""
    env = os.environ
    update = update_dict or {}

    try:
        env.update(update)
        yield
    finally:
        [env.pop(i) for i in update]


def get_atm_openocd():
    """Retrieves Atmosic openocd executable and seach path.

    Returns:
        openocd executable and search path
    """
    # Unfortunately the env var ZEPHYR_MODULES is only defined during
    # Zephyr CMake builds... so we have to derive that from ZEPHYR_BASE
    zephyr_modules = os.path.join(
        os.path.dirname(os.path.abspath(os.environ["ZEPHYR_BASE"])), "modules"
    )
    atm_openocd_base = os.path.join(
        zephyr_modules, "hal", "atmosic_lib", "tools", "openocd"
    )
    openocd_search = os.path.join(atm_openocd_base, "tcl")
    openocd = None
    openocd_search = None
    if atm_openocd_base is not None:
        plat = platform.system()
        if plat.startswith("MSYS") or plat.startswith("Windows"):
            plat = "Windows_NT"
        elif plat == "Darwin":
            arch = platform.machine().lower()
            plat = f"Darwin/{arch}"
        elif plat == "Linux":
            pass
        else:
            raise ValueError(f"Unrecognized platform: {plat}")

        openocd = os.path.join(atm_openocd_base, "bin", plat, "openocd")
        openocd_search = os.path.join(atm_openocd_base, "tcl")
        print("Using ATM OpenOCD '{}'".format(openocd))
    return (openocd, openocd_search)


def get_openocd_config_from_board_dirs(board_dirs):
    """Get OpenOCD configuration path for one or more board directories.

    Looks for a ``runner_config.yml`` file in any of ``board_dirs``

    Args:
        board_dirs: Board configuration directories

    Returns:
        Path to the OpenOCD config file, or None if not found
    """

    for board_dir in board_dirs:
        runner_config_file = Path(board_dir) / "runner_config.yml"
        try:
            with runner_config_file.open("r", encoding="utf-8") as f:
                config = yaml.load(f.read(), Loader=yaml.SafeLoader)
        except FileNotFoundError:
            continue
        return config.get("openocd_config").replace("ZEPHYR_BASE", str(ZEPHYR_BASE))


def get_board_dirs_from_board(board_name):
    """Get all board configuration directories for a board.

    Returns the full list of directories Zephyr associates with the board,
    including any contributed by ``extend:`` entries in sibling ``board.yml``
    files (see ``zephyr/scripts/list_boards.py``).
    """
    args = argparse.Namespace(
        board=board_name,
        board_dir=[],
        arch_roots=[],
        board_roots=[],
        soc_roots=[],
        fuzzy_match=None,
    )

    module_settings = {
        "arch_root": [ZEPHYR_BASE],
        "board_root": [ZEPHYR_BASE],
        "soc_root": [ZEPHYR_BASE],
    }
    for module in zephyr_module.parse_modules(ZEPHYR_BASE, Manifest.from_file()):
        for key, dirs in module_settings.items():
            root = module.meta.get("build", {}).get("settings", {}).get(key)
            if root is not None:
                dirs.append(Path(module.project) / root)

    args.arch_roots += module_settings["arch_root"]
    args.board_roots += module_settings["board_root"]
    args.soc_roots += module_settings["soc_root"]

    boards = list_boards.find_v2_boards(args)
    return boards[board_name].directories


class AtmOpenOCD:

    def __init__(
        self,
        board,
        device,
        jlink,
        dl,
        openocd_bin=None,
        openocd_search=None,
        openocd_cfg=None,
    ) -> None:
        atm_openocd_bin, atm_openocd_search = get_atm_openocd()

        if not openocd_bin:
            self.openocd_bin = atm_openocd_bin
        else:
            self.openocd_bin = openocd_bin

        if not openocd_search:
            self.openocd_search = atm_openocd_search
        else:
            self.openocd_search = openocd_search

        if self.openocd_bin is None:
            raise RuntimeError("Could not find Openocd executable")
        if self.openocd_search is None:
            raise RuntimeError("Could not find Openocd search directory.")

        # If openocd_cfg not provided, try to infer it from the board
        if openocd_cfg is None and board is not None:
            board_dirs = get_board_dirs_from_board(board)
            openocd_cfg = get_openocd_config_from_board_dirs(board_dirs)
            if openocd_cfg:
                print(f"Inferred OpenOCD config for board '{board}': {openocd_cfg}")

        self.openocd_cfg = openocd_cfg

        if (self.openocd_cfg is None) or (not os.path.exists(self.openocd_cfg)):
            raise RuntimeError(
                f"Could not find openocd.cfg file. "
                f"Please provide openocd_cfg parameter or ensure board '{board}' "
                f"has a runner_config.yml file in its board directory."
            )

        self.device = device
        if jlink:
            self.swdif = "JLINK"
            ser_name = "JLINK_SERIAL"
        else:
            self.swdif = "FTDI"
            ser_name = "SYDNEY_SERIAL"

        self.env_dict = {"SWDIF": self.swdif, ser_name: str(self.device)}
        if dl:
            self.env_dict["SWDBOARD"] = "DL"

    @property
    def base_cmd(self):
        return (
            [self.openocd_bin]
            + ["-s", os.path.dirname(self.openocd_cfg)]
            + ["-s", self.openocd_search]
            + ["-f", self.openocd_cfg]
        )

    def execute_cmd_raw(self, cmds, env_var=None):
        """Executes openocd command on device exactly
        Args:
            cmd (List[str]): open ocd command to run
            env_var (optional): dictionary of environmental commands to add to cmd

        Returns:
            Tuple(returncode, stdout and stderr) of command
        """
        exec_env = dict(self.env_dict)
        if env_var:
            exec_env.update(env_var)
        openocd_cmds = ["-c " + s for s in cmds]

        with _temp_environ(exec_env):
            call = subprocess.run(
                self.base_cmd + openocd_cmds,
                check=False,
                capture_output=True,
                text=True,
            )

        return (call.returncode, call.stdout, call.stderr)

    def execute_cmd(self, cmds, env_var=None):
        """Executes openocd command on device

        This function automatically includes 'init' at the start of the command
        set, and 'exit' at the end.

        Args:
            cmd (List[str]): open ocd command to run
            env_var (optional): dictionary of environmental commands to add to cmd

        Returns:
            Tuple(returncode, stdout and stderr) of command
        """
        return self.execute_cmd_raw(["init"] + cmds + ["exit"], env_var)

    def reset_target(self):
        """Issues `reset_target` on device
        Args:
            device (str): device jlink serial
            base_openocd_cmd (str): base openocd command
        """
        return self.execute_cmd_raw(
            ["init_rr_nb_exit"],
            env_var={"FTDI_BENIGN_BOOT": "1", "FTDI_HARD_RESET": "1"},
        )
