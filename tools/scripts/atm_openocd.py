'''
@file atm_openocd.py

@brief Helper file for Atmosic openocd

Copyright (C) Atmosic 2024-2025
'''
import contextlib
import glob
import os
from pathlib import Path
import platform
import subprocess

def get_atm_plat_dir_from_board(board):
    """Generates the partial platform path from a specific board

    Note: the path is relative to $ZEPHYR_BASE

    Returns:
        str: partial platform path
        None: if path cannot be found
    """
    try:
        # if a revision is passed, strip it before continuing
        board,_ = board.split("@")
    except:
        board = board
    # if a ns board is passed, strip before continuing
    if board.endswith('ns'):
        board = board.split("/", 1)[0]

    soc = get_soc_from_board(board)

    if soc == "ATM33xx-5":
        openocd_dir_path = os.path.join('openair', 'modules', 'hal_atmosic')
        return os.path.join(openocd_dir_path, "ATM33xx-5")
    elif soc.startswith("ATM34xx"):
        openocd_dir_path = os.path.join('atmosic-private', 'modules', 'hal_atmosic')
        if soc.endswith("-2"):
            return os.path.join(openocd_dir_path, "ATM34xx", "rev-2")
        elif soc.endswith("-5"):
            return os.path.join(openocd_dir_path, "ATM34xx", "rev-5")
        else:
            raise RuntimeError("Could not match board revision.")
    return None

def get_soc_from_board(board):
    def get_soc_from_west_boards(board, board_path):
        try:
            west_boards_results = subprocess.run(
                ["west", "boards", "-f", "{qualifiers}", "--board", board,
                 "--board-root", board_path],
                text=True, capture_output=True, check=True)
            if west_boards_results.stdout:
                qualifiers = west_boards_results.stdout.strip().split(",")
                socs = [i for i in qualifiers if not i.endswith("/ns")]
                print(socs)
                return socs[0]
            else:
                return None
        except subprocess.CalledProcessError:
            return None

    # First check if the given board is defined in regular board paths.
    board_paths = [
        "./zephyr/boards/atmosic/",
        "./atmosic-internal/boards/atmosic/"]

    for board_path in board_paths:
        soc = get_soc_from_west_boards(board, board_path)
        if soc is not None:
            return soc

    # If none match, check the board name.
    atm33 = ["3325", "3330"]
    atm34 = ["3405", "3425", "3430"]
    if any(i in board for i in atm33):
        return "ATM33xx-5"
    elif any(i in board for i in atm34):
        if board.endswith("-5"):
            return "ATM34xx-5"
        else:
            return "ATM34xx-2"
    return None


@contextlib.contextmanager
def _temp_environ(update_dict):
    """create a temp env context manager
    """
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
    zephyr_modules = os.path.join(os.path.dirname(
        os.path.abspath(os.environ['ZEPHYR_BASE'])),  'modules')
    atm_openocd_base = os.path.join(
        zephyr_modules, 'hal', 'atmosic_lib', 'tools', 'openocd')
    openocd_search = os.path.join(atm_openocd_base, 'tcl')
    openocd = None
    openocd_search = None
    if atm_openocd_base is not None:
        plat = platform.system()
        if plat.startswith('MSYS'):
            plat = 'Windows'
        elif plat == 'Darwin':
            arch = platform.machine().lower()
            plat = f'Darwin/{arch}'
        openocd = os.path.join(atm_openocd_base, 'bin', plat, 'openocd')
        openocd_search = os.path.join(atm_openocd_base, 'tcl')
        print("Using ATM OpenOCD '{}'".format(openocd))
    return (openocd, openocd_search)


def get_atm_openocd_cfg(board):
    """Returns the correct openocd.cfg for a given Atmosic platform.

    Args:
        board (str): board of atmosic platform

    Returns:
        str: path to openocd.cfg
    """
    zephyr_top = os.path.dirname(
        os.path.abspath(os.environ['ZEPHYR_BASE']))

    atm_plat_dir = get_atm_plat_dir_from_board(board)
    def_path = os.path.join(zephyr_top, atm_plat_dir, 'openocd', '*openocd.cfg')
    try:
        default = glob.glob(def_path, recursive=True)[0]
        # even if glob succeeds, sanity check file exists
        if os.path.exists(default):
            return default
        return None
    except:
        # glob raises exception when nothing is found
        return None


class AtmOpenOCD():

    def __init__(self, board, device, jlink, openocd_bin=None, openocd_search=None, openocd_cfg=None) -> None:
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

        if not openocd_cfg:
            self.openocd_cfg = get_atm_openocd_cfg(board)
            if self.openocd_cfg is None:
                raise RuntimeError("Could not find Openocd config file. Please pass config file via: `--openocd_config`")
        else:
            self.openocd_cfg = openocd_cfg

        if (self.openocd_cfg is None) or (not os.path.exists(self.openocd_cfg)):
            raise RuntimeError("Could not find openocd.cfg file")

        self.device = device
        if jlink:
            self.swdif = "JLINK"
            ser_name = "JLINK_SERIAL"
        else:
            self.swdif = "FTDI"
            ser_name = "SYDNEY_SERIAL"

        self.env_dict = {
            "SWDIF": self.swdif,
            ser_name: str(self.device)
        }

    @property
    def base_cmd(self):
        return [self.openocd_bin] + ['-s', os.path.dirname(self.openocd_cfg)] + \
            ['-s', self.openocd_search] + ['-f', self.openocd_cfg]

    def execute_cmd(self, cmds, env_var={}):
        """Executes openocd command on device
        Args:
            cmd (List[str]): open ocd command to run
            env_var (optional): dictionary of environmental commands to add to cmd

        Returns:
            Tuple(returncode, stdout and stderr) of command
        """
        exec_env = dict(self.env_dict)
        exec_env.update(env_var)
        openocd_cmds = ["-c " + s for s in cmds]

        with _temp_environ(exec_env):
            call = subprocess.run(self.base_cmd + ['-c init'] +
                                  openocd_cmds + ['-c exit'],
                                  check=True,
                                  capture_output=True)

        return (call.returncode, call.stdout, call.stderr)

    def reset_target(self):
        """Issues `reset_target` on device
        Args:
            device (str): device jlink serial
            base_openocd_cmd (str): base openocd command
        """
        return self.execute_cmd(["release_reset", "sleep 100", "set_normal_boot"],
                         env_var={"FTDI_BENIGN_BOOT": '1', "FTDI_HARD_RESET": '1'})
