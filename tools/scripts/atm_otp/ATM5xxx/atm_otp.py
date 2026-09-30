# Copyright (C) Atmosic 2026
#
# SPDX-License-Identifier: LicenseRef-Atmosic

"""
@file atm_otp.py

@brief Atmosic OTP Managment
"""

from atm_otp.atm_otp_base import AtmOTP, AtmOTPArray


class Atm5_OTPArray(AtmOTPArray):
    otp_array = [
        AtmOTP("NABG_TRIM_LATCH", 0, 9),
        AtmOTP("VDDIO_RANGE_LATCH", 9),
        AtmOTP("HARV_DISABLED_LATCH", 10),
        AtmOTP("SEC_DBG_CONFIG", 14, 2, bit_fields=["DEBUG_DISABLED", "DEBUG_SECURED"]),
        AtmOTP("SECURE_FLASH_LOCK", 48),
        AtmOTP("FLASH_LOCK0", 49),
        AtmOTP("FLASH_LOCK1", 50),
        AtmOTP("FLASH_LOCK2", 51),
        AtmOTP("FLASH_ADDRESSABLE_ADDR", 52, 3),
        AtmOTP("UART_RX1_DISABLED_LATCH", 56),
        AtmOTP("DISABLE_UPPER_128KB_SRAM_LATCH", 57),
        AtmOTP("DISABLE_CS_LATCH", 58),
        AtmOTP("RESERVED", 63),
    ]

    def __init__(self, bits=b"\x00\x00\x00\x00\x00\x00\x00\x00", size=64) -> None:
        super().__init__(bits, size)


def get_otp_array(board):
    """Return the OTP array class corresponding to the given board."""

    if "52" in board or "53" in board:
        return Atm5_OTPArray
    return None
