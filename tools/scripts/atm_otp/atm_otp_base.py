# Copyright (C) Atmosic 2026
#
# SPDX-License-Identifier: LicenseRef-Atmosic

"""
@file atm_otp_base.py

@brief Atmosic OTP Framework
"""

import textwrap
import os
from pathlib import Path
import yaml
import atm_openocd

THIS_ZEPHYR = Path(__file__).parent.parent.parent.parent.parent / "zephyr"
ZEPHYR_BASE = Path(os.environ.get("ZEPHYR_BASE", THIS_ZEPHYR))


def get_atm_otp_script_from_board(board_name):
    """Get OTP script path for a specific board.

    Args:
        board_name: Name of the board

    Returns:
        Path to the OTP script file, or None if not found.
    """

    board_dirs = atm_openocd.get_board_dirs_from_board(board_name)
    for board_dir in board_dirs:
        runner_config_file = Path(board_dir) / "runner_config.yml"
        try:
            with runner_config_file.open("r", encoding="utf-8") as f:
                config = yaml.load(f.read(), Loader=yaml.SafeLoader)
        except FileNotFoundError:
            continue

    # Get and expand the otp_script value
    otp_script = config.get("otp_script")
    if otp_script is None:
        return None
    otp_script = otp_script.replace("ZEPHYR_BASE", str(ZEPHYR_BASE))
    print(f"Inferred OTP script for board '{board_name}': {otp_script}")
    return Path(otp_script)


class AtmOTP:
    def __init__(self, name, idx, size=1, value=0, bit_fields=[]) -> None:
        self.name = name
        self.idx = idx
        if size < 1:
            raise RuntimeError("OTP must be at least 1 bit long")
        self.size = size
        self.value = value

        # bit_fields is an optional sub-naming of individual bits.
        # If passed, then they need to match size of OTP
        if len(bit_fields) and len(bit_fields) != self.size:
            raise RuntimeError(
                "total size of OTP must match length of bit_fields if provided"
            )
        self.bit_fields = bit_fields

    @property
    def end_idx(self):
        return self.idx + self.size - 1

    def get_field(self, name):
        try:
            idx = self.bit_fields.index(name)
            return (self.value >> idx) & 0x1
        except:
            raise RuntimeError("Field does not exist!")

    def get_idx(self, idx):
        if idx < self.size:
            return (self.value >> idx) & 0x1
        raise RuntimeError(f"index ({idx}) not available in {self.name}")

    @property
    def stat_str(self):
        """Returns string of stats of OTP.

        Does not include information regarding value of the OTP
        """
        return f"{self.name} [{self.idx}{'-' + str(self.end_idx) if self.size > 1 else ''}]"

    @property
    def pprint_str(self):
        pprint_str = str(self)
        if len(self.bit_fields):
            bits_str = ""
            for i, bit_field in enumerate(self.bit_fields):
                bits_str += f"{bit_field}: {(self.value >> i) & 0x1}".ljust(23)
            pprint_str += "\n" + textwrap.fill(
                bits_str, width=55, initial_indent="    ", subsequent_indent="    "
            )
        return pprint_str

    def pprint(self):
        print(self.pprint_str)

    def __str__(self) -> str:
        # +2 is to account for '0b'
        bin_repr_size = self.size + 2
        return f"{self.stat_str}: {format(self.value, f'#0{bin_repr_size}b')}"


class AtmOTPArray:
    otp_array = []

    def __init__(self, bits=b"\x00\x00\x00\x00\x00\x00\x00\x00", size=64) -> None:
        self.value = int.from_bytes(bits, byteorder="little")
        self.size = size
        self.populate_otp()

    def populate_otp(self):
        for otp in self.otp_array:
            otp.value = (self.value >> otp.idx) & ((1 << otp.size) - 1)

    def get_otp_group_by_name(self, name) -> AtmOTP:
        if "." in name:
            name, _ = name.split(".")
        try:
            return next(filter(lambda p: p.name == name, self.__class__.otp_array))
        except:
            raise RuntimeError("OTP does not exist")

    def get_otp_group_by_idx(self, idx) -> AtmOTP:
        try:
            return next(
                filter(lambda p: p.idx <= idx <= p.end_idx, self.__class__.otp_array)
            )
        except:
            raise RuntimeError("OTP does not exist")

    def get_otp_group_and_idx(self, val):
        try:
            idx = int(val)
            otp = self.get_otp_group_by_idx(idx)
            return (otp, idx - otp.idx)
        except:
            name = val
            sub = None
            if "." in name:
                name, sub = name.split(".")
            otp = self.get_otp_group_by_name(name)
            if sub is None:
                if otp.size > 1:
                    return (otp, None)
                return (otp, 0)
            try:
                idx = int(sub)
                return (otp, idx)
            except:
                return (otp, otp.bit_fields.index(sub))

    def get_otp_bits(self, val):
        otp, idx = self.get_otp_group_and_idx(val)

        if idx is None:
            return format(otp.value, f"#0{otp.size + 2}b")
        return bin(otp.get_idx(idx))

    def __str__(self):
        pstr = f"OTP: {hex(self.value)}\n"
        for otp in self.otp_array:
            pstr += otp.pprint_str + "\n"
        return pstr

    @property
    def otp_array_str(self):
        pstr = ""
        for otp in self.otp_array:
            pstr += f"{otp.stat_str}\n"
        return pstr

    def print_otp_array(self):
        print(self.otp_array_str)
