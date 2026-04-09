"""
@file test_sec_jrnl_tlv.py

@brief Secure Journal Managment Unit tests

Copyright (C) Atmosic 2026
"""

from sec_jrnl_tlv import SecJrnl, TLV, TLVStatus, InvalidTLVException
import unittest


class TestTLVStatusMethods(unittest.TestCase):
    """Test TLVStatus class"""

    def test_default_status(self):
        """Test default status"""
        tlv_status = TLVStatus()
        self.assertEqual(tlv_status.status, 6)
        self.assertEqual(tlv_status.valid, True)
        self.assertEqual(tlv_status.locked, False)
        self.assertEqual(tlv_status.erased, False)

    def test_override_default_status(self):
        """Test default status can be overridden"""
        tlv_status = TLVStatus(1)
        self.assertEqual(tlv_status.valid, False)
        self.assertEqual(tlv_status.locked, True)
        self.assertEqual(tlv_status.erased, True)
        tlv_status = TLVStatus(3)
        self.assertEqual(tlv_status.valid, False)
        self.assertEqual(tlv_status.locked, False)
        self.assertEqual(tlv_status.erased, True)
        tlv_status = TLVStatus(4)
        self.assertEqual(tlv_status.valid, True)
        self.assertEqual(tlv_status.locked, True)
        self.assertEqual(tlv_status.erased, False)

    def test_valid_property_setter(self):
        """Test setting the valid property"""
        tlv_status = TLVStatus(0)
        self.assertEqual(tlv_status.valid, True)
        tlv_status.valid = False
        self.assertEqual(tlv_status.valid, False)
        self.assertEqual(tlv_status.status, 1)

    def test_locked_property_setter(self):
        """Test setting the locked property"""
        tlv_status = TLVStatus(0)
        self.assertEqual(tlv_status.locked, True)
        tlv_status.locked = False
        self.assertEqual(tlv_status.locked, False)
        self.assertEqual(tlv_status.status, 2)

    def test_erased_property_setter(self):
        """Test setting the erased property"""
        tlv_status = TLVStatus(0)
        self.assertEqual(tlv_status.erased, True)
        tlv_status.erased = False
        self.assertEqual(tlv_status.erased, False)
        self.assertEqual(tlv_status.status, 4)


class TestTLVMethods(unittest.TestCase):
    """Test TLV class"""

    def test_basic_tlv_creation(self):
        """Test creating a TLV"""
        tlv = TLV(0xAA, 0x7, 2, b"\xde\xad")
        self.assertEqual(tlv.idx, -1)
        self.assertEqual(tlv.total_size, 5)
        tlv = TLV(0xAA, TLVStatus(4), 2, b"\xde\xad", idx=23)
        self.assertEqual(tlv.idx, 23)
        self.assertEqual(tlv.total_size, 5)
        tlv = TLV(0xAA, 0x7, 2, b"\xde\xad", idx=23)
        self.assertEqual(tlv.idx, 23)
        self.assertEqual(tlv.total_size, 5)

    def test_tlv_creation_fail_on_bad_tag(self):
        """Test creating a TLV with an invalid tag"""
        with self.assertRaises(InvalidTLVException):
            TLV(0xFF, 0x7, 2, b"\xde\xad")

    def test_tlv_creation_fail_on_bad_length(self):
        """Test creating a TLV with an invalid length"""
        with self.assertRaises(InvalidTLVException):
            # length should be 2 but is set to 5
            TLV(0xAA, 0x7, 5, b"\xde\xad")

    def test_tlv_bin_property(self):
        """Test the binary TLV output"""
        tlv = TLV(0xAA, 0x7, 2, b"\xde\xad")
        self.assertEqual(tlv.bin, b"\xaa\x07\x02\xde\xad")

    def test_tlv_from_bin(self):
        """Test the binary TLV input"""
        tlv = TLV.from_bin(b"\xaa\x07\x02\xde\xad", 0)
        self.assertEqual(tlv.tag, 0xAA)
        self.assertEqual(tlv.idx, 0)
        self.assertEqual(tlv.status.status, 0x7)
        self.assertEqual(tlv.total_size, 0x5)
        tlv = TLV.from_bin(b"\x00\x00\xaa\x07\x02\xde\xad", 2)
        self.assertEqual(tlv.tag, 0xAA)
        self.assertEqual(tlv.idx, 2)
        self.assertEqual(tlv.status.status, 0x7)
        self.assertEqual(tlv.total_size, 0x5)

    def test_tlv_from_content(self):
        """Test the from_contents constructor"""
        tlv = TLV.from_contents(0xDE, b"\xde\xad")
        self.assertEqual(tlv.bin, b"\xde\x06\x02\xde\xad")
        self.assertEqual(tlv.tag, 0xDE)
        self.assertEqual(tlv.idx, -1)
        self.assertEqual(tlv.status.locked, False)
        tlv = TLV.from_contents(0xDE, b"\xde\xad", True)
        self.assertEqual(tlv.bin, b"\xde\x04\x02\xde\xad")
        self.assertEqual(tlv.tag, 0xDE)
        self.assertEqual(tlv.idx, -1)
        self.assertEqual(tlv.status.locked, True)


class TestSecJrnlMethods(unittest.TestCase):
    """Test SecJrnl class"""

    def setUp(self) -> None:
        """Set up an example secure journal"""
        self.sec_jrnl_bin = (
            b"NVDS\xb8\x06\x1c\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
            b"\x00\x00\x00\x00\x92E(\x0c\x02\x03\xd4\x00\x00\x00\x00\x00\xb9\x06\x04\x11\x00"
            b"\x01\x01\xb0\x06\x1c\xe1!\x00\x00\xd8\x05\x00\x00\xa0\x80*\x02P\x80\x10\x01\x10"
            b"\x00\x00\x00\xcd\r\x1f\x00\x1b\x06\x00\x00\xb1\x06<\x15P\x8b)L\x00P\x04\xfb\xfb"
            b"\x01\x00LS\x17\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x0f\x0f\x17"
            b"\x80\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
            b"\x00\x00\x00\x00\x00\x00\x01\x00\x02\xbc\x06,\x11\x00\x00\x00\x07\x00\x06*\x08\xc0"
            b"\x04*\x10\x00\xfa.\xba;t<\xfc\x10\x16\x0ey\x18%\x00\x93d\x7f\x00\xd6\x94\xd2\x06?"
            b"\x00\x00\x00\x00\x00\x02\x00\xd0\x06\x04\xde\xad\xbe\xef"
        )
        return super().setUp()

    def test_sec_jrnl_creation(self):
        """Test secure journal creation"""
        secjrnl = SecJrnl(self.sec_jrnl_bin)
        tags = []
        for tag in iter(secjrnl):
            tags.append(tag.tag)
        self.assertEqual([0xB8, 0xB9, 0xB0, 0xB1, 0xBC, 0xD0], tags)

    def test_sec_jrnl_get_tag(self):
        """Test getting a tag"""
        secjrnl = SecJrnl(self.sec_jrnl_bin)
        secjrnl = SecJrnl(self.sec_jrnl_bin)
        tlv = secjrnl.get(0xB0)
        self.assertEqual(tlv.tag, 0xB0)
        tlv = secjrnl.get(0x11)
        self.assertEqual(tlv, None)

    def test_sec_jrnl_append_tag(self):
        """Test appending a tag"""
        secjrnl = SecJrnl(self.sec_jrnl_bin)
        tlv = secjrnl.get(0x01)
        self.assertEqual(tlv, None)
        secjrnl.append_tag(0x01, b"hello", False)
        tlv = secjrnl.get(0x01)
        self.assertEqual(tlv.tag, 0x01)


class TestTLVTagNameMethods(unittest.TestCase):
    """Test TLV tag name conversion methods"""

    def test_tag_name_to_number_valid(self):
        """Test converting valid tag names to numbers"""
        self.assertEqual(TLV.tag_name_to_number("ATE"), 0xB8)
        self.assertEqual(TLV.tag_name_to_number("CHIP_INFO"), 0xB9)
        self.assertEqual(TLV.tag_name_to_number("RIF_CAL"), 0xB0)
        self.assertEqual(TLV.tag_name_to_number("MDM_CAL"), 0xB1)

    def test_tag_name_to_number_case_insensitive(self):
        """Test that tag name lookup is case-insensitive"""
        self.assertEqual(TLV.tag_name_to_number("ate"), 0xB8)
        self.assertEqual(TLV.tag_name_to_number("Ate"), 0xB8)
        self.assertEqual(TLV.tag_name_to_number("chip_info"), 0xB9)

    def test_tag_name_to_number_invalid(self):
        """Test that invalid tag names return None"""
        self.assertIsNone(TLV.tag_name_to_number("INVALID_TAG"))
        self.assertIsNone(TLV.tag_name_to_number(""))


class TestTLVJsonBinaryConversion(unittest.TestCase):
    """Test TLV JSON to binary and binary to JSON conversion methods"""

    def test_json_to_binary_ate(self):
        """Test converting ATE (0xB8) JSON to binary - 7 uint32_t reserved fields"""
        json_data = {"rsvd": [0, 0, 0, 0, 0, 0, 0]}
        binary = TLV.json_to_binary(0xB8, json_data)
        # 7 uint32_t = 28 bytes, all zeros
        expected = b"\x00" * 28
        self.assertEqual(binary, expected)

    def test_json_to_binary_ate_with_values(self):
        """Test ATE with non-zero values"""
        json_data = {"rsvd": [1, 2, 3, 4, 5, 6, 7]}
        binary = TLV.json_to_binary(0xB8, json_data)
        # Little-endian uint32_t values
        expected = (
            b"\x01\x00\x00\x00"  # 1
            b"\x02\x00\x00\x00"  # 2
            b"\x03\x00\x00\x00"  # 3
            b"\x04\x00\x00\x00"  # 4
            b"\x05\x00\x00\x00"  # 5
            b"\x06\x00\x00\x00"  # 6
            b"\x07\x00\x00\x00"  # 7
        )
        self.assertEqual(binary, expected)

    def test_json_to_binary_chip_info(self):
        """Test converting CHIP_INFO (0xB9) JSON to binary"""
        json_data = {
            "version": 0x0011,
            "package": 1,
            "test_day": 15,
            "test_month": 6,
            "test_year": 24,
            "test_temperature": 25,
            "otp_version": 1,
        }
        binary = TLV.json_to_binary(0xB9, json_data)
        # version(H=2) + package(B=1) + test_day(B=1) + test_month(B=1) +
        # test_year(B=1) + test_temperature(H=2) + otp_version(B=1) = 10 bytes
        expected = (
            b"\x11\x00"  # version = 0x0011 (little-endian)
            b"\x01"  # package = 1
            b"\x0f"  # test_day = 15
            b"\x06"  # test_month = 6
            b"\x18"  # test_year = 24
            b"\x19\x00"  # test_temperature = 25 (little-endian)
            b"\x01"  # otp_version = 1
        )
        self.assertEqual(binary, expected)

    def test_json_to_binary_rif_cal(self):
        """Test converting RIF_CAL (0xB0) JSON to binary"""
        json_data = {
            "bias": 0x000021E1,
            "rxbbf": 0x000005D8,
            "rxbbf_1m": 0x022A80A0,
            "rxbbf_2m": 0x01108050,
            "syntx_modgain": 0x00000010,
            "syntx_vcocap": 0x001F0DCD,
            "lna": 0x0000061B,
        }
        binary = TLV.json_to_binary(0xB0, json_data)
        # 7 uint32_t = 28 bytes
        self.assertEqual(len(binary), 28)
        # Check first value (bias) in little-endian
        self.assertEqual(binary[0:4], b"\xe1\x21\x00\x00")

    def test_json_to_binary_mdm_cal(self):
        """Test converting MDM_CAL (0xB1) JSON to binary"""
        json_data = {
            "agcmeas": 0x298B5015,
            "dcoff": 0x0450004C,
            "pga_force_dccalresults": 0x0001FBFB,
            "iqcorr": 0x0017534C,
            "iqcorr2": 0x00000000,
        }
        binary = TLV.json_to_binary(0xB1, json_data)
        # 5 uint32_t = 20 bytes
        self.assertEqual(len(binary), 20)

    def test_json_to_binary_xtal_cal(self):
        """Test converting XTAL_CAL (0xC2) JSON to binary"""
        json_data = {
            "xtal_bits1": 0x12345678,
            "xtal_bits0": 0xABCDEF01,
        }
        binary = TLV.json_to_binary(0xC2, json_data)
        expected = (
            b"\x78\x56\x34\x12"  # xtal_bits1 (little-endian)
            b"\x01\xef\xcd\xab"  # xtal_bits0 (little-endian)
        )
        self.assertEqual(binary, expected)

    def test_json_to_binary_missing_field(self):
        """Test that missing fields raise ValueError"""
        json_data = {"version": 1}  # Missing other required fields
        with self.assertRaises(ValueError) as ctx:
            TLV.json_to_binary(0xB9, json_data)
        self.assertIn("Missing field", str(ctx.exception))

    def test_json_to_binary_wrong_array_size(self):
        """Test that wrong array size raises ValueError"""
        json_data = {"rsvd": [0, 0, 0]}  # Should be 7 elements
        with self.assertRaises(ValueError) as ctx:
            TLV.json_to_binary(0xB8, json_data)
        self.assertIn("must have 7 elements", str(ctx.exception))

    def test_json_to_binary_no_schema(self):
        """Test that tags without schema raise ValueError"""
        with self.assertRaises(ValueError) as ctx:
            TLV.json_to_binary(0x02, {"data": 123})
        self.assertIn("No schema defined", str(ctx.exception))

    def test_binary_to_json_ate(self):
        """Test converting ATE binary back to JSON"""
        binary = (
            b"\x01\x00\x00\x00"
            b"\x02\x00\x00\x00"
            b"\x03\x00\x00\x00"
            b"\x04\x00\x00\x00"
            b"\x05\x00\x00\x00"
            b"\x06\x00\x00\x00"
            b"\x07\x00\x00\x00"
        )
        json_data = TLV.binary_to_json(0xB8, binary)
        self.assertEqual(json_data, {"rsvd": [1, 2, 3, 4, 5, 6, 7]})

    def test_binary_to_json_chip_info(self):
        """Test converting CHIP_INFO binary back to JSON"""
        binary = (
            b"\x11\x00"  # version = 0x0011
            b"\x01"  # package = 1
            b"\x0f"  # test_day = 15
            b"\x06"  # test_month = 6
            b"\x18"  # test_year = 24
            b"\x19\x00"  # test_temperature = 25
            b"\x01"  # otp_version = 1
        )
        json_data = TLV.binary_to_json(0xB9, binary)
        expected = {
            "version": 0x0011,
            "package": 1,
            "test_day": 15,
            "test_month": 6,
            "test_year": 24,
            "test_temperature": 25,
            "otp_version": 1,
        }
        self.assertEqual(json_data, expected)

    def test_binary_to_json_no_schema(self):
        """Test that tags without schema return None"""
        result = TLV.binary_to_json(0x02, b"\x00\x00")
        self.assertIsNone(result)

    def test_roundtrip_ate(self):
        """Test JSON -> binary -> JSON roundtrip for ATE"""
        original = {"rsvd": [100, 200, 300, 400, 500, 600, 700]}
        binary = TLV.json_to_binary(0xB8, original)
        recovered = TLV.binary_to_json(0xB8, binary)
        self.assertEqual(original, recovered)

    def test_roundtrip_chip_info(self):
        """Test JSON -> binary -> JSON roundtrip for CHIP_INFO"""
        original = {
            "version": 256,
            "package": 2,
            "test_day": 25,
            "test_month": 12,
            "test_year": 25,
            "test_temperature": 85,
            "otp_version": 3,
        }
        binary = TLV.json_to_binary(0xB9, original)
        recovered = TLV.binary_to_json(0xB9, binary)
        self.assertEqual(original, recovered)

    def test_roundtrip_rif_cal(self):
        """Test JSON -> binary -> JSON roundtrip for RIF_CAL"""
        original = {
            "bias": 0x12345678,
            "rxbbf": 0xABCDEF01,
            "rxbbf_1m": 0x11223344,
            "rxbbf_2m": 0x55667788,
            "syntx_modgain": 0x99AABBCC,
            "syntx_vcocap": 0xDDEEFF00,
            "lna": 0x01020304,
        }
        binary = TLV.json_to_binary(0xB0, original)
        recovered = TLV.binary_to_json(0xB0, binary)
        self.assertEqual(original, recovered)

    def test_roundtrip_mdm_cal(self):
        """Test JSON -> binary -> JSON roundtrip for MDM_CAL"""
        original = {
            "agcmeas": 0x11111111,
            "dcoff": 0x22222222,
            "pga_force_dccalresults": 0x33333333,
            "iqcorr": 0x44444444,
            "iqcorr2": 0x55555555,
        }
        binary = TLV.json_to_binary(0xB1, original)
        recovered = TLV.binary_to_json(0xB1, binary)
        self.assertEqual(original, recovered)

    def test_roundtrip_xtal_cal(self):
        """Test JSON -> binary -> JSON roundtrip for XTAL_CAL"""
        original = {
            "xtal_bits1": 0xDEADBEEF,
            "xtal_bits0": 0xCAFEBABE,
        }
        binary = TLV.json_to_binary(0xC2, original)
        recovered = TLV.binary_to_json(0xC2, binary)
        self.assertEqual(original, recovered)


if __name__ == "__main__":
    unittest.main()
