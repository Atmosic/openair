'''
@file test_atm_otp.py

@brief OTP Managment Unit tests

Copyright (C) Atmosic 2024
'''
import unittest
import atm_otp


class TestAtmOTPMethods(unittest.TestCase):
    """Test AtmOTP class"""

    def test_variables_are_set_correctly(self):
        otp = atm_otp.AtmOTP("OTP_NAME", 0, 1)
        self.assertTrue(otp.idx == 0)
        self.assertTrue(otp.end_idx == 1)
        otp = atm_otp.AtmOTP("OTP_NAME", 2, 4)
        self.assertTrue(otp.idx == 2)
        self.assertTrue(otp.size == 4)
        self.assertTrue(otp.end_idx == 6)

    def test_field_access(self):
        otp = atm_otp.AtmOTP("OTP_A", 7, 4, value=0x1, bit_fields=[
                             "sub_bit_0", "sub_bit_1", "sub_bit_2", "sub_bit_3",])
        self.assertEqual(otp.get_field("sub_bit_0"), 1)
        self.assertEqual(otp.get_idx(0), 1)

        otp = atm_otp.AtmOTP("OTP_A", 7, 4, value=0x5, bit_fields=[
                             "sub_bit_0", "sub_bit_1", "sub_bit_2", "sub_bit_3",])
        self.assertEqual(otp.get_field("sub_bit_2"), 1)
        self.assertEqual(otp.get_field("sub_bit_0"), 1)
        self.assertEqual(otp.get_idx(0), 1)
        self.assertEqual(otp.get_idx(2), 1)

    def test_error_when_bit_fields_wrong_size(self):
        self.assertRaises(RuntimeError, atm_otp.AtmOTP, "OTP_A", 7, 4, value=0x5, bit_fields=[
                          "sub_bit_1", "sub_bit_2", "sub_bit_3",])

    def test_print_functional(self):
        otp = atm_otp.AtmOTP("OTP_A", 7, 4, value=0x5, bit_fields=[
                             "sub_bit_0", "sub_bit_1", "sub_bit_2", "sub_bit_3",])
        print(otp)
        otp.pprint()


class TestAtmOTPArrayMethods(unittest.TestCase):
    """Test AtmOTPArray class"""

    def test_variables_are_initialized(self):
        otpArray = atm_otp.Atmx3_OTPArray()
        self.assertEqual(otpArray.size, 64,
                         "Verify Array defaults to correct size")
        self.assertEqual(otpArray.value, 0, "Verify value defaults to 0")

        otpArray = atm_otp.Atmx3_OTPArray(b'?\x00\x00\x00\x00\x00 \x00')
        self.assertEqual(otpArray.size, 64,
                         "Verify Array defaults to correct size")
        self.assertEqual(otpArray.value, 0x2000000000003f,
                         "Verify value set correctly")
        otp = otpArray.get_otp_group_by_name("RRAM_WRITE_LOCK")
        self.assertEqual(otp.value, 0b100000, "Verify OTP is set correctly")
        otp = otpArray.get_otp_group_by_idx(52)
        self.assertEqual(otp.value, 0b100000, "Verify OTP is set correctly")

    def test_print_functional(self):
        otpArray = atm_otp.Atmx3_OTPArray(b'?\x00\x00\x00\x00\x00 \x00')
        otpArray.print_otp_array()
        print(otpArray)

    def test_accesing_otp_bits(self):
        otpArray = atm_otp.Atmx3_OTPArray(b'?\x00\x00\x00\x00\x00 \x00')
        self.assertEqual(otpArray.get_otp_bits("RRAM_WRITE_LOCK"), "0b0100000")
        self.assertEqual(otpArray.get_otp_bits(
            "RRAM_WRITE_LOCK.SECURE_COUNTERS"), "0b1")
        self.assertEqual(otpArray.get_otp_bits("RRAM_WRITE_LOCK.5"), "0b1")
        self.assertEqual(otpArray.get_otp_bits(53), "0b1")
        self.assertEqual(otpArray.get_otp_bits(48), "0b0")
        self.assertEqual(otpArray.get_otp_bits(49), "0b0")
        self.assertEqual(otpArray.get_otp_bits(50), "0b0")
        self.assertEqual(otpArray.get_otp_bits("NABG_TRIM_LATCH"), "0b000111111")
        self.assertEqual(otpArray.get_otp_bits("NABG_TRIM_LATCH.0"), "0b1")
        self.assertEqual(otpArray.get_otp_bits("NABG_TRIM_LATCH.8"), "0b0")
        self.assertEqual(otpArray.get_otp_bits("NABG_TRIM_LATCH.8"), "0b0")

        self.assertRaises(RuntimeError, otpArray.get_otp_bits, "NABG_TRIM_LATCH.9")

        self.assertEqual(otpArray.get_otp_bits("NOIND_LATCH"), "0b0")

if __name__ == '__main__':
    unittest.main()
