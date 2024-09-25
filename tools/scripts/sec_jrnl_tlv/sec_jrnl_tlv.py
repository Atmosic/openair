'''
@file sec_jrnl_tlv.py

@brief Secure Journal Managment

Copyright (C) Atmosic 2024
'''
import struct

SEC_JRNL_MAGIC = bytes([0x4E, 0x56, 0x44, 0x53])
SEC_JRNL_MAGIC_SIZE = 4
TLV_META_HEADER_FORMAT = 'BBH'
TLV_META_SIZE = struct.calcsize(TLV_META_HEADER_FORMAT)

SEC_JRNL_WALK_CONT = 0
SEC_JRNL_WALK_DONE = 1


class BadMagicException(Exception):
    """Magic is not the correct value
    """
    pass


class InvalidTLVException(Exception):
    """TLV tag value is invalid
    """
    pass


class TLVStatus():
    SEC_JRNL_STATUS_VALID_IDX = 0x01
    SEC_JRNL_STATUS_VALID_MASK = 0x01
    SEC_JRNL_STATUS_LOCKED_IDX = 0x02
    SEC_JRNL_STATUS_LOCKED_MASK = 1 << (SEC_JRNL_STATUS_LOCKED_IDX - 1)
    SEC_JRNL_STATUS_ERASED_IDX = 0x03
    SEC_JRNL_STATUS_ERASED_MASK = 1 << (SEC_JRNL_STATUS_ERASED_IDX - 1)

    def __init__(self, status=0x06) -> None:
        self.status = status

    def set_status_bit(self, idx, val):
        self.status = (self.status & (~(1 << (idx - 1)))) | (val << (idx - 1))

    @property
    def valid(self):
        return not (self.status & TLVStatus.SEC_JRNL_STATUS_VALID_MASK)

    @valid.setter
    def valid(self, value):
        self.set_status_bit(
            TLVStatus.SEC_JRNL_STATUS_VALID_IDX, not bool(value))

    @property
    def locked(self):
        return not (self.status & TLVStatus.SEC_JRNL_STATUS_LOCKED_MASK)

    @locked.setter
    def locked(self, value):
        self.set_status_bit(
            TLVStatus.SEC_JRNL_STATUS_LOCKED_IDX, not bool(value))

    @property
    def erased(self):
        return not (self.status & TLVStatus.SEC_JRNL_STATUS_ERASED_MASK)

    @erased.setter
    def erased(self, value):
        self.set_status_bit(
            TLVStatus.SEC_JRNL_STATUS_ERASED_IDX, not bool(value))

    def __str__(self) -> str:
        valid_str = f"[{'!' if not self.valid else '' }V]"
        erased_str = f"[{'!' if not self.erased else '' }E]"
        locked_str = f"[{'!' if not self.locked else '' }L]"
        return f"{valid_str}{locked_str}{erased_str}"


class TLV():
    PTAG_LJUST_SIZE = 10
    TAG_NAMES = {
        0xb8: "ATE",
        0xb9: "CHIP_INFO",
        0xb0: "RIF_CAL",
        0xb1: "MDM_CAL",
        0xbc: "MISC_CAL",
    }

    def __init__(self, tag, status, raw_len, data, idx=-1) -> None:
        if tag == 0xff:
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
        return (TLV_META_SIZE - 1)

    @staticmethod
    def get_tlv_size(raw_len):
        """Calculates length of TLV data

        Args:
            raw_len (int): raw length stored as uint16_t in binary data

        Returns:
            int: length of TLV
        """
        tlv_len = raw_len & 0x7f
        if raw_len & 0x80:
            tlv_len += ((raw_len & 0xff00) >> 1)
        return tlv_len

    @property
    def bin(self):
        """returns binary representation of TLV
        """
        header = struct.pack('BBH', self.tag, self.status.status, self.raw_len)
        header = header[0:self.get_header_size(self.raw_len)]
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
            TLV_META_HEADER_FORMAT, bin[idx: idx + TLV_META_SIZE])

        header_size = TLV.get_header_size(raw_tlv_len)
        data_idx = idx + header_size

        tlv_len = TLV.get_tlv_size(raw_tlv_len)
        tlv_data = bin[data_idx: data_idx + tlv_len]
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
        if data_len > 0x7f:
            data_len = (data_len & 0x7f) & ((data_len << 1) & 0xff)

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


class SecJrnl():
    SEC_JRNL_TAIL_PAD_LEN = 4
    SEC_JRNL_SECURE_ONLY_MASK = 0xfc
    SEC_JRNL_SECURE_ONLY_VAL = 0xec

    @classmethod
    def is_secure_tag(cls, tag):
        return (tag & cls.SEC_JRNL_SECURE_ONLY_MASK) == cls.SEC_JRNL_SECURE_ONLY_VAL

    def __init__(self, bin=None, max_len=1776) -> None:
        if bin is None:
            bin = b"NVDS"+b"\xFF"*(max_len-SEC_JRNL_MAGIC_SIZE)
        self.raw_bin = bin
        self.magic = struct.unpack('BBBB', bin[0:SEC_JRNL_MAGIC_SIZE])
        self.max_len = max_len

    @classmethod
    def from_file(cls, bin_file):
        """Create a SecJrnl class from a given binary file

        Args:
            bin_file: filepath to sec jrnl data
        """
        with open(bin_file, 'rb') as bin_fd:
            return cls(bin_fd.read())

    @property
    def len(self):
        return self.walk_bin(self.raw_bin) + SecJrnl.SEC_JRNL_TAIL_PAD_LEN

    @property
    def bin(self):
        return self.raw_bin[0:self.len]

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
            except InvalidTLVException as e:
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
        except InvalidTLVException as e:
            raise StopIteration

    def get(self, tag_val):
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
        self.raw_bin = self.raw_bin[0:self.ratchet_idx] + new_tlv.bin + \
            self.raw_bin[self.ratchet_idx + new_tlv.total_size:]

    @property
    def ratchet_idx(self):
        """returns Value of ratchet index to lock down entire Secure Journal
        """
        return self.len - SecJrnl.SEC_JRNL_TAIL_PAD_LEN


if __name__ == "__main__":
    import argparse
    parser = argparse.ArgumentParser(
        prog='ProgramName',
        description='What the program does',
        epilog='Text at the bottom of help')
    parser.add_argument('filename')
    args = parser.parse_args()
    jrnl = SecJrnl.from_file(args.filename)
    print(jrnl)
    print(jrnl.raw_bin)
