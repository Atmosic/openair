# Copyright (C) Atmosic 2026
#
# SPDX-License-Identifier: LicenseRef-Atmosic

"""
@file atm_otp.py

@brief Atmosic OTP Managment
"""

from atm_otp.atm_otp_base import AtmOTP, AtmOTPArray


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
        AtmOTP(
            "RRAM_WRITE_LOCK",
            48,
            7,
            bit_fields=[
                "BOOT_BLOCK_0",
                "BOOT_BLOCK_1",
                "BOOT_BLOCK_2",
                "BOOT_BLOCK_3",
                "PROTECTED_DATA",
                "SECURE_COUNTERS",
                "PRIVATE_KEY_STORAGE",
            ],
        ),
        AtmOTP("UART1_RX_DISABLE", 56),
        AtmOTP("SEC_DBG_CONFIG", 60, 2, bit_fields=["DEBUG_DISABLED", "DEBUG_SECURED"]),
        AtmOTP("RRAM_JTAG_BYPASS", 62),
    ]

    def __init__(self, bits=b"\x00\x00\x00\x00\x00\x00\x00\x00", size=64) -> None:
        super().__init__(bits, size)


def get_otp_array(board):
    """Return the OTP array class corresponding to the given board."""

    if "34" in board:
        return Atm34_OTPArray
    return None
