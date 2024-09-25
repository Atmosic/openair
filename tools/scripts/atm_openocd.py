'''
@file atm_openocd.py

@brief Helper file for Atmosic openocd

Copyright (C) Atmosic 2024
'''
import contextlib
import glob
import os
from pathlib import Path
import platform
import subprocess

def get_atm_plat_dir_from_board(board):
    """Generates the partial platform path from a specific board

    Returns:
        str: partial platform path
    """
    try:
        # if a revision is passed, strip it before continuing
        board,_ = board.split("@")
    except:
        board = board
    # if a ns board is passed, strip before continuing
    if board.endswith('_ns'):
        board = board[:-3]
    if "ATMEVK-33" in board:
        return "ATM33xx-5"
    if "ATMEVK-34" in board:
        plat = "ATM34xx"
        rev = board.split("-")[-1]
        return f"{plat}/rev-{rev}"



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
    # Unfortunately the env var ZEPHYR_MODULES is only defined during
    # Zephyr CMake builds... so we have to derive that from ZEPHYR_BASE
    zephyr_modules = os.path.join(os.path.dirname(
        os.path.abspath(os.environ['ZEPHYR_BASE'])),  'modules')
    
    atm_plat_dir = get_atm_plat_dir_from_board(board)
    def_path = os.path.join(zephyr_modules, 'hal', 'atmosic_lib', atm_plat_dir, 'openocd', '*openocd.cfg')
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
        else:
            self.openocd_cfg = openocd_cfg

        if self.openocd_cfg is None:
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
