"""
@file sec_jrnl_tlv.py

@brief Secure Journal Managment

Copyright (C) Atmosic 2024-2026
"""

import struct

SEC_JRNL_MAGIC = bytes([0x4E, 0x56, 0x44, 0x53])
SEC_JRNL_MAGIC_SIZE = 4
TLV_META_HEADER_FORMAT = "BBH"
TLV_META_SIZE = struct.calcsize(TLV_META_HEADER_FORMAT)

SEC_JRNL_WALK_CONT = 0
SEC_JRNL_WALK_DONE = 1


class BadMagicException(Exception):
    """Magic is not the correct value"""


class InvalidTLVException(Exception):
    """TLV tag value is invalid"""


class TLVStatus:
    """Status byte from TLV data"""

    SEC_JRNL_STATUS_VALID_IDX = 0x01
    SEC_JRNL_STATUS_VALID_MASK = 0x01
    SEC_JRNL_STATUS_LOCKED_IDX = 0x02
    SEC_JRNL_STATUS_LOCKED_MASK = 1 << (SEC_JRNL_STATUS_LOCKED_IDX - 1)
    SEC_JRNL_STATUS_ERASED_IDX = 0x03
    SEC_JRNL_STATUS_ERASED_MASK = 1 << (SEC_JRNL_STATUS_ERASED_IDX - 1)

    def __init__(self, status=0x06) -> None:
        self.status = status

    def set_status_bit(self, idx, val):
        """Set a bit in the status byte"""
        self.status = (self.status & (~(1 << (idx - 1)))) | (val << (idx - 1))

    @property
    def valid(self):
        """Get the valid bit"""
        return not self.status & TLVStatus.SEC_JRNL_STATUS_VALID_MASK

    @valid.setter
    def valid(self, value):
        """Set the valid bit"""
        self.set_status_bit(TLVStatus.SEC_JRNL_STATUS_VALID_IDX, not bool(value))

    @property
    def locked(self):
        """Get the locked bit"""
        return not self.status & TLVStatus.SEC_JRNL_STATUS_LOCKED_MASK

    @locked.setter
    def locked(self, value):
        """Set the locked bit"""
        self.set_status_bit(TLVStatus.SEC_JRNL_STATUS_LOCKED_IDX, not bool(value))

    @property
    def erased(self):
        """Get the erased bit"""
        return not self.status & TLVStatus.SEC_JRNL_STATUS_ERASED_MASK

    @erased.setter
    def erased(self, value):
        """Set the erased bit"""
        self.set_status_bit(TLVStatus.SEC_JRNL_STATUS_ERASED_IDX, not bool(value))

    def __str__(self) -> str:
        valid_str = f"[{'!' if not self.valid else '' }V]"
        erased_str = f"[{'!' if not self.erased else '' }E]"
        locked_str = f"[{'!' if not self.locked else '' }L]"
        return f"{valid_str}{locked_str}{erased_str}"


class TLV:
    """Secure Journal data item containing type, length, and value information"""

    PTAG_LJUST_SIZE = 10
    # Tag definitions from calibration.h
    TAG_NAMES = {
        0x01: "BD_ADDR",
        0xB0: "RIF_CAL",
        0xB1: "MDM_CAL",
        0xB8: "ATE",
        0xB9: "CHIP_INFO",
        0xBC: "MISC_CAL",
        0xC2: "XTAL_CAL",
        0xC6: "RES_CAL",
    }

    # Reverse mapping: name -> tag number
    NAME_TO_TAG = {v: k for k, v in TAG_NAMES.items()}

    # Struct schemas mapping tag numbers to field definitions
    # Each schema is a list of tuples: (field_name, struct_format, array_size or None)
    # struct_format uses Python struct module format characters:
    # I = uint32_t, H = uint16_t, B = uint8_t, b = int8_t
    TAG_SCHEMAS = {
        0x01: [  # bd_addr_s
            ("bd_addr", "B", 6),
        ],
        0xB0: [  # rif_cal_s
            ("bias", "I", None),
            ("rxbbf", "I", None),
            ("rxbbf_1m", "I", None),
            ("rxbbf_2m", "I", None),
            ("syntx_modgain", "I", None),
            ("syntx_vcocap", "I", None),
            ("lna", "I", None),
        ],
        0xB1: [  # mdm_cal_s
            ("agcmeas", "I", None),
            ("dcoff", "I", None),
            ("pga_force_dccalresults", "I", None),
            ("iqcorr", "I", None),
            ("iqcorr2", "I", None),
        ],
        0xB8: [  # ate_s
            ("rsvd", "I", 7),
        ],
        0xB9: [  # chip_info_s
            ("version", "H", None),
            ("package", "B", None),
            ("test_day", "B", None),
            ("test_month", "B", None),
            ("test_year", "B", None),
            ("test_temperature", "H", None),
            ("otp_version", "B", None),
        ],
        0xC2: [  # xtal_cal_s
            ("xtal_bits1", "I", None),
            ("xtal_bits0", "I", None),
        ],
        0xC6: [  # res_cal_s
            ("version", "B", None),
            ("rsvd", "B", 3),
            ("words", "I", 4),
        ],
    }

    @staticmethod
    def tag_name_to_number(name):
        """Convert a tag name to its numeric value.

        Args:
            name (str): Tag name (e.g., 'ATE', 'CHIP_INFO')

        Returns:
            int: Tag number, or None if not found
        """
        return TLV.NAME_TO_TAG.get(name.upper())

    @staticmethod
    def json_to_binary(tag, json_data):
        """Convert JSON data to binary according to tag's struct schema.

        Args:
            tag (int): Tag number
            json_data (dict): JSON data with field names and values

        Returns:
            bytes: Binary representation of the data

        Raises:
            ValueError: If tag has no schema or field is unknown
        """
        if tag not in TLV.TAG_SCHEMAS:
            raise ValueError(f"No schema defined for tag 0x{tag:02X}")

        schema = TLV.TAG_SCHEMAS[tag]
        result = b""

        for field_name, fmt, array_size in schema:
            if field_name not in json_data:
                raise ValueError(f"Missing field '{field_name}' for tag 0x{tag:02X}")

            value = json_data[field_name]

            if array_size is not None:
                # Handle array fields
                if not isinstance(value, list):
                    raise ValueError(
                        f"Field '{field_name}' must be a list of {array_size} elements"
                    )
                if len(value) != array_size:
                    raise ValueError(
                        f"Field '{field_name}' must have {array_size} elements, "
                        f"got {len(value)}"
                    )
                for item in value:
                    result += struct.pack("<" + fmt, item)
            else:
                # Handle scalar fields
                result += struct.pack("<" + fmt, value)

        return result

    @staticmethod
    def binary_to_json(tag, data):
        """Convert binary data to JSON according to tag's struct schema.

        Args:
            tag (int): Tag number
            data (bytes): Binary data

        Returns:
            dict: JSON representation of the data, or None if no schema
        """
        if tag not in TLV.TAG_SCHEMAS:
            return None

        schema = TLV.TAG_SCHEMAS[tag]
        result = {}
        offset = 0

        for field_name, fmt, array_size in schema:
            fmt_size = struct.calcsize(fmt)

            if array_size is not None:
                # Handle array fields
                values = []
                for _ in range(array_size):
                    if offset + fmt_size <= len(data):
                        (value,) = struct.unpack(
                            "<" + fmt, data[offset : offset + fmt_size]
                        )
                        values.append(value)
                        offset += fmt_size
                result[field_name] = values
            else:
                # Handle scalar fields
                if offset + fmt_size <= len(data):
                    (value,) = struct.unpack(
                        "<" + fmt, data[offset : offset + fmt_size]
                    )
                    result[field_name] = value
                    offset += fmt_size

        return result

    # pylint: disable=too-many-arguments
    def __init__(self, tag, status, raw_len, data, idx=-1) -> None:
        if tag == 0xFF:
            raise InvalidTLVException("Bad tag")
        self.tag = tag
        if isinstance(status, TLVStatus):
            self.status = status
        else:
            self.status = TLVStatus(status)
        self.data = data
        self.raw_len = raw_len
        self.header_size = TLV.get_header_size(raw_len)
        self.tlv_len = TLV.get_tlv_size(raw_len)
        if self.tlv_len != len(data):
            raise InvalidTLVException("Invalid Length")
        # optionally track index where TLV is located
        self.idx = idx

    @staticmethod
    def get_header_size(raw_len):
        """Calculate proper header size (i.e. if using compressed format)

        Args:
            raw_len (int): raw length stored as uint16_t in binary data

        Returns:
            int: correct header size
        """
        if raw_len & 0x80:
            return TLV_META_SIZE
        return TLV_META_SIZE - 1

    @staticmethod
    def get_tlv_size(raw_len):
        """Calculates length of TLV data

        Args:
            raw_len (int): raw length stored as uint16_t in binary data

        Returns:
            int: length of TLV
        """
        tlv_len = raw_len & 0x7F
        if raw_len & 0x80:
            tlv_len += (raw_len & 0xFF00) >> 1
        return tlv_len

    @property
    def bin(self):
        """returns binary representation of TLV"""
        header = struct.pack("BBH", self.tag, self.status.status, self.raw_len)
        header = header[0 : self.get_header_size(self.raw_len)]
        return header + self.data

    @property
    def total_size(self):
        """Calculates total size of tlv in bytes (header + data)

        Returns:
            int: size of TLV
        """
        return TLV.get_header_size(self.raw_len) + TLV.get_tlv_size(self.raw_len)

    @classmethod
    def from_bin(cls, bin, idx):
        """Returns TLV class from a binary data format

        Args:
            bin (bytes): binary
            idx (int): index in binary

        Raises:
            InvalidTLVException: if passed binary is not valid or reached end

        Returns:
            TLV: tlv class from binary
        """
        if idx + TLV_META_SIZE >= len(bin):
            raise InvalidTLVException

        tlv_type, tlv_status, raw_tlv_len = struct.unpack(
            TLV_META_HEADER_FORMAT, bin[idx : idx + TLV_META_SIZE]
        )

        header_size = TLV.get_header_size(raw_tlv_len)
        data_idx = idx + header_size

        tlv_len = TLV.get_tlv_size(raw_tlv_len)
        tlv_data = bin[data_idx : data_idx + tlv_len]
        return cls(tlv_type, tlv_status, raw_tlv_len, tlv_data, idx=idx)

    @classmethod
    def from_contents(cls, tag, content, locked=False):
        """Returns TLV class from data

        Note: this should be used when generating a new TLV, not related to an
        existing binary. This class properly builds meta header data from just
        tag and content

        Args:
            tag (int): tag for tlv
            content: data for tlv
            locked (bool): sets locked bit in status.

        Raises:
            InvalidTLVException: if passed binary is not valid or reached end

        Returns:
            TLV: tlv class from binary
        """
        tlv_status = TLVStatus()
        tlv_status.locked = locked
        data_len = len(content)
        if data_len > 0x7F:
            data_len = (data_len & 0x7F) & ((data_len << 1) & 0xFF)

        return cls(tag, tlv_status, data_len, content)

    @property
    def ptag(self):
        """Print format for given tag.

        Returns:
            str: name of tag, or default format
        """
        if self.tag in TLV.TAG_NAMES:
            return TLV.TAG_NAMES[self.tag].ljust(TLV.PTAG_LJUST_SIZE)
        return f"tag:({'{:02x}'.format(self.tag)})".ljust(TLV.PTAG_LJUST_SIZE)

    @property
    def pidx(self):
        """Print format for given tag.

        Returns:
            str: name of tag, or default format
        """
        if self.idx == -1:
            return ""
        return f"@{'{:04x}'.format(self.idx + self.header_size)} "

    def __str__(self) -> str:
        p_str = f"{self.pidx}{self.ptag} {self.status} data: [{' '.join('{:02x}'.format(b)  for b in self.data)}]"
        return p_str


class SecJrnl:
    """Secure Journal"""

    SEC_JRNL_TAIL_PAD_LEN = 5
    SEC_JRNL_SECURE_ONLY_MASK = 0xFC
    SEC_JRNL_SECURE_ONLY_VAL = 0xEC

    @classmethod
    def is_secure_tag(cls, tag):
        """Checks if given tag is SECURE_ONLY"""
        return (tag & cls.SEC_JRNL_SECURE_ONLY_MASK) == cls.SEC_JRNL_SECURE_ONLY_VAL

    def __init__(self, bin=None, max_len=1776) -> None:
        if bin is None:
            bin = b"NVDS" + b"\xff" * (max_len - SEC_JRNL_MAGIC_SIZE)
        self.raw_bin = bin
        self.magic = struct.unpack("BBBB", bin[0:SEC_JRNL_MAGIC_SIZE])
        self.max_len = max_len

    @classmethod
    def from_file(cls, bin_file):
        """Create a SecJrnl class from a given binary file

        Args:
            bin_file: filepath to sec jrnl data
        """
        with open(bin_file, "rb") as bin_fd:
            return cls(bin_fd.read())

    @property
    def len(self):
        """Length of secure journal, including padding"""
        return self.walk_bin(self.raw_bin) + SecJrnl.SEC_JRNL_TAIL_PAD_LEN

    @property
    def bin(self):
        """Binary representation of secure journal data"""
        return self.raw_bin[0 : self.len]

    def walk_bin(self, bin=None, func=lambda tlv: SEC_JRNL_WALK_CONT):
        """Provides an interface to iterate through binary

        Note: the function passed must return SEC_JRNL_WALK_CONT to continue
        iterating, if it returns SEC_JRNL_WALK_DONE, walk_bin will exit on the current TLV.

        Args:
            bin: binary file to iterate. Defaults to self.bin
            func: function to execute on each TLV, Defaults to lambda tlv:SEC_JRNL_WALK_CONT.

        Returns:
            int: index of TLV (or if completed, length of TLVs)
        """
        if bin is None:
            bin = self.raw_bin
        tlv_off = SEC_JRNL_MAGIC_SIZE
        while tlv_off < self.max_len:
            try:
                tlv = TLV.from_bin(bin, tlv_off)
            except InvalidTLVException:
                return tlv_off
            if func(tlv) == SEC_JRNL_WALK_DONE:
                return tlv_off
            tlv_off += tlv.total_size
        return tlv_off

    def __iter__(self):
        self.iter_tlv_off = SEC_JRNL_MAGIC_SIZE
        return self

    def __next__(self):
        try:
            tlv = TLV.from_bin(self.bin, self.iter_tlv_off)
            self.iter_tlv_off += tlv.total_size
            return tlv
        except InvalidTLVException as exc:
            raise StopIteration from exc

    def get(self, tag_val):
        """Get TLV matching tag"""
        ret = None
        for tlv in iter(self):
            if tag_val == tlv.tag:
                ret = tlv
                if tlv.status.locked:
                    return ret
        return ret

    def __str__(self):
        tlv_str_array = []
        for tlv in iter(self):
            tlv_str_array.append(str(tlv))
        return "\n".join(tlv_str_array)

    def append_tag(self, tag, data, locked=False):
        """Append tag to Secure Journal

        Args:
            tag (int): tag
            data: data content of TLV
            locked (bool, optional): Lock down tag. Defaults to False.
        """
        new_tlv = TLV.from_contents(tag, data, locked)
        if (self.ratchet_idx + new_tlv.total_size) > self.max_len:
            raise RuntimeError("Secure Journal can hold no more data")
        self.raw_bin = (
            self.raw_bin[0 : self.ratchet_idx]
            + new_tlv.bin
            + b"\xff" * (SecJrnl.SEC_JRNL_TAIL_PAD_LEN)
            + self.raw_bin[
                self.ratchet_idx + new_tlv.total_size + SecJrnl.SEC_JRNL_TAIL_PAD_LEN :
            ]
        )

    @property
    def ratchet_idx(self):
        """returns Value of ratchet index to lock down entire Secure Journal"""
        return self.len - SecJrnl.SEC_JRNL_TAIL_PAD_LEN


if __name__ == "__main__":
    import argparse

    parser = argparse.ArgumentParser(
        prog="ProgramName",
        description="What the program does",
        epilog="Text at the bottom of help",
    )
    parser.add_argument("filename")
    args = parser.parse_args()
    jrnl = SecJrnl.from_file(args.filename)
    print(jrnl)
    print(jrnl.raw_bin)
