'''
@file atm_otp.py

@brief Atmosic OTP Managment

Copyright (C) Atmosic 2024
'''

import textwrap

class AtmOTP():
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
                "total size of OTP must match length of bit_fields if provided")
        self.bit_fields = bit_fields

    @property
    def end_idx(self):
        return (self.idx + self.size)

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
            pprint_str += "\n" + \
                textwrap.fill(bits_str, width=55,
                              initial_indent="    ", subsequent_indent="    ")
        return pprint_str

    def pprint(self):
        print(self.pprint_str)

    def __str__(self) -> str:
        # +2 is to account for '0b'
        bin_repr_size = self.size + 2
        return f"{self.stat_str}: {format(self.value, f'#0{bin_repr_size}b')}"


class AtmOTPArray():
    otp_array = []

    def __init__(self, bits=b'\x00\x00\x00\x00\x00\x00\x00\x00', size=64) -> None:
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
            return next(filter(lambda p: p.idx <= idx < p.end_idx, self.__class__.otp_array))
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
            return format(otp.value, f'#0{otp.size + 2}b')
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


class Atmx3_OTPArray(AtmOTPArray):
    otp_array = [
        AtmOTP("NABG_TRIM_LATCH", 0, 9),
        AtmOTP("USE_LDO_LATCH", 9),
        AtmOTP("DISABLE_CHPU_LATCH", 10),
        AtmOTP("HARV_DISABLED_LATCH", 11),
        AtmOTP("RECT_CTUNE_LATCH", 12, 3),
        AtmOTP("INTERNAL_SPARE_LATCH", 15, 4),
        AtmOTP("DISABLE_XTAL32K_LATCH", 19),
        AtmOTP("NOIND_LATCH", 20),
        AtmOTP("DISABLE_VDDIOGEN_LATCH", 21),
        AtmOTP("DISABLE_VDDGEN_LATCH", 22),
        AtmOTP("DISABLE_5V_LATCH", 23),
        AtmOTP("VBATT_LEVEL_LATCH", 24),
        AtmOTP("BATT_TYPE_LATCH", 25, 2),
        AtmOTP("VBATT_GOOD_LATCH", 27, 3),
        AtmOTP("VBATT_BROWNOUT_LATCH", 30, 7),
        AtmOTP("MPPT_TYPE_LATCH", 37, 2),
        AtmOTP("DISABLE_RFHARV_LATCH", 39),
        AtmOTP("VHARV_START_LATCH", 40, 2),
        AtmOTP("VSTORE_GOOD_LATCH", 42, 2),
        AtmOTP("VSTORE_MAX_LATCH", 44, 3),
        AtmOTP("RRAM_WRITE_LOCK", 48, 7, bit_fields=[
               "BOOT_BLOCK_0", "BOOT_BLOCK_1", "BOOT_BLOCK_2", "BOOT_BLOCK_3", "PROTECTED_DATA", "SECURE_COUNTERS", "PRIVATE_KEY_STORAGE"]),
        AtmOTP("SEC_DBG_CONFIG", 60, 2, bit_fields=[
               "DEBUG_DISABLED", "DEBUG_SECURED"]),
        AtmOTP("RRAM_JTAG_BYPASS", 62),
    ]

    def __init__(self, bits=b'\x00\x00\x00\x00\x00\x00\x00\x00', size=64) -> None:
        super().__init__(bits, size)


class Atm34_OTPArray(AtmOTPArray):
    otp_array = [
        AtmOTP("NABG_TRIM_LATCH", 0, 9),
        AtmOTP("USE_LDO_LATCH", 9),
        AtmOTP("DISABLE_CHPU_LATCH", 10),
        AtmOTP("HARV_DISABLED_LATCH", 11),
        AtmOTP("RECT_CTUNE_LATCH", 12, 3),
        AtmOTP("INTERNAL_SPARE_LATCH", 15, 4),
        AtmOTP("DISABLE_XTAL32K_LATCH", 19),
        AtmOTP("NOIND_LATCH", 20),
        AtmOTP("DISABLE_VDDIOGEN_LATCH", 21),
        AtmOTP("DISABLE_VDDGEN_LATCH", 22),
        AtmOTP("DISABLE_5V_LATCH", 23),
        AtmOTP("VBATT_LEVEL_LATCH", 24),
        AtmOTP("BATT_TYPE_LATCH", 25, 2),
        AtmOTP("VBATT_GOOD_LATCH", 27, 3),
        AtmOTP("VBATT_BROWNOUT_LATCH", 30, 7),
        AtmOTP("MPPT_TYPE_LATCH", 37, 2),
        AtmOTP("DISABLE_RFHARV_LATCH", 39),
        AtmOTP("VHARV_START_LATCH", 40, 2),
        AtmOTP("VSTORE_GOOD_LATCH", 42, 2),
        AtmOTP("VSTORE_MAX_LATCH", 44, 3),
        AtmOTP("RRAM_WRITE_LOCK", 48, 7, bit_fields=[
               "BOOT_BLOCK_0", "BOOT_BLOCK_1", "BOOT_BLOCK_2", "BOOT_BLOCK_3", "PROTECTED_DATA", "SECURE_COUNTERS", "PRIVATE_KEY_STORAGE"]),
        AtmOTP("UART1_RX_DISABLE", 56),
        AtmOTP("SEC_DBG_CONFIG", 60, 2, bit_fields=[
               "DEBUG_DISABLED", "DEBUG_SECURED"]),
        AtmOTP("RRAM_JTAG_BYPASS", 62),
    ]

    def __init__(self, bits=b'\x00\x00\x00\x00\x00\x00\x00\x00', size=64) -> None:
        super().__init__(bits, size)
