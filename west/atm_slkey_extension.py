# Copyright (c) Atmosic 2026
#
# SPDX-License-Identifier: LicenseRef-Atmosic

"""
@file atm_slkey_extension.py

@brief West extension for managing secure key slots (side-load keys)
"""

import argparse
import binascii
import os
import sys
import tempfile
from pathlib import Path
from textwrap import dedent

from west.commands import (
    WestCommand,
    Verbosity,
)  # pylint: disable=import-error,no-name-in-module

sys.path.append(
    os.path.join(
        os.path.dirname(os.path.dirname(os.path.abspath(__file__))), "tools", "scripts"
    )
)
# pylint: disable=wrong-import-position,wrong-import-order,import-error
import atm_openocd

# RRAM Private Key Constants
ATM33_PRIVATE_KEY_SLOT_SIZE = 32


def auto_int(value):
    """arg parse type that parses all int types when passes as param"""
    return int(value, 0)


def hex_string_to_bytes(hex_str):
    """Convert hex string to bytes.

    Args:
        hex_str: Hex string without spaces (e.g., "0123456789abcdef")

    Returns:
        bytes: Binary data

    Raises:
        argparse.ArgumentTypeError: If hex string is invalid
    """
    try:
        return bytes.fromhex(hex_str)
    except ValueError as err:
        raise argparse.ArgumentTypeError(f"Invalid hex string: {err}") from err


def parse_partition_file(partition_file):
    """Parse partition_info.map file to extract SEC_SIDELOAD_KEYS_OFFSET.

    Args:
        partition_file: Path to partition_info.map file

    Returns:
        int: SEC_SIDELOAD_KEYS_OFFSET value

    Raises:
        ValueError: If SEC_SIDELOAD_KEYS_OFFSET is not found in the file
    """
    if not os.path.exists(partition_file):
        raise FileNotFoundError(f"Partition file not found: {partition_file}")

    with open(partition_file, "r", encoding="utf-8") as file:
        for line in file:
            line = line.strip()
            if not line or line.startswith("#"):
                continue

            if "=" in line:
                key, value = line.split("=", 1)
                key = key.strip()
                value = value.strip()

                if key == "SEC_SIDELOAD_KEYS_OFFSET":
                    # Convert hex string to int
                    return int(value, 16)

    raise ValueError(f"SEC_SIDELOAD_KEYS_OFFSET not found in {partition_file}")


def pad_private_key(private_key):
    """Pad private key to 32 bytes with 0xFF.

    Implements the C# logic:
        byte[] fill_private_key = new byte[32];
        Array.Copy(private_key, fill_private_key, private_key.Length);
        for (int i = private_key.Length; i < fill_private_key.Length; i++) {
            fill_private_key[i] = 0xFF;
        }

    Args:
        private_key: bytes object containing the key data

    Returns:
        bytes: 32-byte padded key

    Raises:
        ValueError: If key is longer than 32 bytes
    """
    if len(private_key) > ATM33_PRIVATE_KEY_SLOT_SIZE:
        raise ValueError(
            f"Private key too long: {len(private_key)} bytes "
            f"(max {ATM33_PRIVATE_KEY_SLOT_SIZE} bytes)"
        )

    # Create 32-byte array filled with 0xFF
    fill_private_key = bytearray([0xFF] * ATM33_PRIVATE_KEY_SLOT_SIZE)

    # Copy the actual key data to the beginning
    fill_private_key[: len(private_key)] = private_key

    return bytes(fill_private_key)


class AtmSlKeyCommand(WestCommand):
    """West command for managing side-load keys in secure journal."""

    def __init__(self):
        super().__init__(
            "slkey",  # gets stored as self.name
            "Interface with secure key slots (side-load keys)",  # self.help
            # self.description:
            dedent(
                """
                Interface with secure key slots (side-load keys) on supported chips.

                Allows users to read and write private key data to RRAM slots 0-7.
                Keys are automatically padded to 32 bytes with 0xFF."""
            ),
        )
        self.openocd = None
        self.sideload_keys_addr = None  # Will be set from partition file

    def create_default_subparser(self, subparsers, subcmd_str, help_str):
        """adds subparser with default arguments.

        Args:
            subparsers : subparser object
            subcmd_str (str): name of sub command
            help_str (str): help string
        """
        s_parser = subparsers.add_parser(subcmd_str, help=help_str)
        s_parser.add_argument(
            "-p",
            "--partition_file",
            required=True,
            help="partition info file path (partition_info.map)",
        )
        s_parser.add_argument(
            "--jlink", required=False, action="store_true", help="if using JLINK"
        )
        s_parser.add_argument(
            "--dl", required=False, action="store_true", help="if using DL Board"
        )
        s_parser.add_argument(
            "--flash",
            required=False,
            action="store_true",
            help="if using Flash instead of RRAM (default: RRAM)",
        )
        s_parser.add_argument(
            "--device",
            required=True,
            help="selects FTDI interface, e.g: ATRDIxxxx, or JLINK",
        )
        s_parser.add_argument(
            "--board",
            required=True,
            help="board to build for with optional board revision",
        )
        s_parser.add_argument(
            "--openocd_config",
            required=False,
            help="Specifies the config file for openocd",
        )
        s_parser.set_defaults(subcmd=subcmd_str)
        return s_parser

    def do_add_parser(self, parser_adder):
        """Add parser for slkey command."""
        parser = parser_adder.add_parser(
            self.name, help=self.help, description=self.description
        )
        subparsers = parser.add_subparsers(help="sub-command to run", required=True)

        # Read subcommand: west slkey read --slot_index 0
        read_parser = self.create_default_subparser(
            subparsers, "read", "Read private key from specified slot"
        )
        read_parser.add_argument(
            "--slot_index",
            type=int,
            required=True,
            choices=range(0, 8),
            metavar="SLOT_INDEX",
            help="Key slot number (0-7)",
        )

        # Write subcommand: west slkey write --slot_index 0 --data 010203040506
        write_parser = self.create_default_subparser(
            subparsers, "write", "Write private key to specified slot"
        )
        write_parser.add_argument(
            "--slot_index",
            type=int,
            required=True,
            choices=range(0, 8),
            metavar="SLOT_INDEX",
            help="Key slot number (0-7)",
        )
        write_parser.add_argument(
            "--data",
            type=str,
            required=True,
            help=(
                "Private key as hex string (e.g., '0102030405...'). "
                "Will be padded to 32 bytes with 0xFF"
            ),
        )

        # Read all subcommand: west slkey read_all
        read_all_parser = self.create_default_subparser(
            subparsers, "read_all", "Read all private keys from slots 0-7"
        )
        read_all_parser.add_argument(
            "-o",
            "--output",
            type=str,
            required=False,
            help="Optional output file to save all keys (256 bytes total)",
        )

        # Write all subcommand: west slkey write_all -f keys.pkey
        write_all_parser = self.create_default_subparser(
            subparsers, "write_all", "Write private keys from file to slots 0-7"
        )
        write_all_parser.add_argument(
            "-f",
            "--filename",
            type=str,
            required=True,
            help="Path to .pkey file containing private keys for slots 0-7 (256 bytes total)",
        )

        return parser

    def _read_from_device(self, address, size, use_rram):
        """Helper function to read data from device via OpenOCD.

        Args:
            address: Memory address to read from
            size: Number of bytes to read
            use_rram: True to read from RRAM/NVDS, False to read from Flash

        Returns:
            bytes: Data read from device

        Raises:
            RuntimeError: If read operation fails
        """
        self.openocd.reset_target()

        with tempfile.NamedTemporaryFile("w+b", delete=False) as temp_file_obj:
            temp_path = Path(
                temp_file_obj.name
            ).as_posix()  # openocd expects posix-style paths regardless of platform
            temp_file_obj.close()

            try:
                # Use different OpenOCD command based on storage type
                if use_rram:
                    cmd = f"atm_dump_nvds {temp_path} {address} {size}"
                else:
                    cmd = f"atm_dump_flash {temp_path} {size} {address}"

                cmd_ret, _, stderr = self.openocd.execute_cmd([cmd])

                if cmd_ret != 0:
                    raise RuntimeError(
                        f"Failed to read from address 0x{address:X}: {stderr}"
                    )

                with open(temp_file_obj.name, "rb") as temp_file_read:
                    data = temp_file_read.read()

                return data
            finally:
                if os.path.exists(temp_file_obj.name):
                    os.remove(temp_file_obj.name)

    def _write_to_device(self, address, data, size, use_rram):
        """Helper function to write data to device via OpenOCD.

        Args:
            address: Memory address to write to
            data: Binary data to write
            size: Number of bytes to write (used for flash command)
            use_rram: True to write to RRAM/NVDS, False to write to Flash

        Raises:
            RuntimeError: If write operation fails
        """
        self.openocd.reset_target()

        with tempfile.NamedTemporaryFile("w+b", delete=False) as temp_file_obj:
            temp_file_obj.write(data)
            temp_file_obj.flush()
            temp_path = Path(
                temp_file_obj.name
            ).as_posix()  # openocd expects posix-style paths regardless of platform

            temp_file_obj.close()
            try:
                # Use different OpenOCD command based on storage type
                if use_rram:
                    # Use atm_load_rram to write to RRAM
                    cmd = f"atm_load_rram {temp_path} {address}"
                else:
                    # Use atm_load_flash_nvds to write to Flash
                    cmd = f"atm_load_flash_nvds {temp_path} {address} {size}"

                cmd_ret, _, stderr = self.openocd.execute_cmd([cmd])

                if cmd_ret != 0:
                    raise RuntimeError(
                        f"Failed to write to address 0x{address:X}: {stderr}"
                    )

                return cmd_ret
            finally:
                if os.path.exists(temp_file_obj.name):
                    os.remove(temp_file_obj.name)

    def read(self, args):
        """Read private key from specified slot.

        Args:
            args: args passed at the command line
        """
        slot_index = args.slot_index

        # Calculate address for this slot
        address = self.sideload_keys_addr + (ATM33_PRIVATE_KEY_SLOT_SIZE * slot_index)

        storage_type = "Flash" if args.flash else "RRAM"
        print(
            f"Reading private key from slot {slot_index} "
            f"(address 0x{address:X}) from {storage_type}..."
        )

        # Use helper function to read from device
        key_data = self._read_from_device(
            address, ATM33_PRIVATE_KEY_SLOT_SIZE, not args.flash
        )

        # Display as hex string
        hex_str = binascii.b2a_hex(key_data).decode("utf-8")
        print(f"Slot {slot_index} ({len(key_data)} bytes): {hex_str}")

        return 0

    def write(self, args):
        """Write private key to specified slot.

        Args:
            args: args passed at the command line
        """
        slot_index = args.slot_index

        # Convert hex string to bytes
        try:
            private_key = hex_string_to_bytes(args.data)
        except argparse.ArgumentTypeError as err:
            print(f"Error: {err}")
            sys.exit(1)

        # Pad to 32 bytes with 0xFF
        try:
            padded_key = pad_private_key(private_key)
        except ValueError as err:
            print(f"Error: {err}")
            sys.exit(1)

        # Calculate address for this slot
        address = self.sideload_keys_addr + (ATM33_PRIVATE_KEY_SLOT_SIZE * slot_index)

        storage_type = "Flash" if args.flash else "RRAM"
        print(
            f"Writing private key to slot {slot_index} "
            f"(address 0x{address:X}) to {storage_type}..."
        )
        if self.verbosity >= Verbosity.DBG:
            print(f"Padded key (hex): {binascii.b2a_hex(padded_key).decode('utf-8')}")

        # Use helper function to write to device
        self._write_to_device(
            address, padded_key, ATM33_PRIVATE_KEY_SLOT_SIZE, not args.flash
        )
        print(f"Successfully wrote private key to slot {slot_index}")

        return 0

    def read_all(self, args):
        """Read all private keys from slots 0-7.

        Args:
            args: args passed at the command line
        """
        storage_type = "Flash" if args.flash else "RRAM"
        total_size = 8 * ATM33_PRIVATE_KEY_SLOT_SIZE  # 256 bytes
        start_address = self.sideload_keys_addr

        print(f"Reading all private keys from slots 0-7 from {storage_type}...")
        print(f"Reading {total_size} bytes from address 0x{start_address:X}...")

        # Use helper function to read all 256 bytes in one operation
        all_keys_data = self._read_from_device(
            start_address, total_size, not args.flash
        )

        # Parse the data into individual slots for display
        print("\n" + "=" * 70)
        print("All Slot Data:")
        print("=" * 70)
        for slot_index in range(8):
            offset = slot_index * ATM33_PRIVATE_KEY_SLOT_SIZE
            key_data = all_keys_data[offset : offset + ATM33_PRIVATE_KEY_SLOT_SIZE]
            hex_str = binascii.b2a_hex(key_data).decode("utf-8")
            print(f"Slot {slot_index}: {hex_str}")
        print("=" * 70)

        # Save to file if output is specified
        if args.output:
            with open(args.output, "wb") as output_file:
                output_file.write(all_keys_data)
            print(
                f"\nSuccessfully saved all {len(all_keys_data)} bytes to {args.output}"
            )
        else:
            print(f"\nSuccessfully read all {len(all_keys_data)} bytes from slots 0-7")

    def write_all(self, args):
        """Write private keys from file to slots 0-7.

        Args:
            args: args passed at the command line
        """
        filename = args.filename

        if not os.path.exists(filename):
            print(f"Error: File not found: {filename}")
            sys.exit(1)

        # Read the file (should be in binary format)
        with open(filename, "rb") as input_file:
            file_data = input_file.read()

        # File should contain 8 keys of 32 bytes each = 256 bytes (binary format)
        expected_binary_size = 8 * ATM33_PRIVATE_KEY_SLOT_SIZE  # 256 bytes

        if len(file_data) != expected_binary_size:
            print(
                f"Error: File size is {len(file_data)} bytes, expected "
                f"{expected_binary_size} bytes"
            )
            print(
                f"File should contain 8 private keys of "
                f"{ATM33_PRIVATE_KEY_SLOT_SIZE} bytes each (256 bytes total"
                f" in binary format)"
            )
            sys.exit(1)

        storage_type = "Flash" if args.flash else "RRAM"
        total_size = len(file_data)  # Should be 256 bytes
        start_address = self.sideload_keys_addr

        print(
            f"Writing {total_size} bytes from {filename} to slots 0-7 in "
            f"{storage_type}..."
        )
        print(f"Writing to address 0x{start_address:X}...")

        # Use helper function to write all 256 bytes in one operation
        self._write_to_device(start_address, file_data, total_size, not args.flash)

        print(f"Successfully wrote all {total_size} bytes to slots 0-7")

    def do_run(self, args, unknown_args):  # pylint: disable=unused-argument
        """Execute the slkey command.

        Args:
            args: Parsed command line arguments
            unknown_args: Unknown arguments (unused)
        """
        # Parse partition file to get SEC_SIDELOAD_KEYS_OFFSET
        try:
            self.sideload_keys_addr = parse_partition_file(args.partition_file)
            print(f"SEC_SIDELOAD_KEYS_OFFSET: 0x{self.sideload_keys_addr:X}")
        except (FileNotFoundError, ValueError) as err:
            print(f"Error parsing partition file: {err}")
            sys.exit(1)

        self.board = args.board  # pylint: disable=attribute-defined-outside-init
        # Set up OpenOCD connection
        try:
            self.openocd = atm_openocd.AtmOpenOCD(
                self.board,
                args.device,
                args.jlink,
                args.dl,
                openocd_cfg=args.openocd_config,
            )
        except Exception:  # pylint: disable=broad-exception-caught
            print("Invalid configuration. Please use supported device")
            sys.exit(1)

        # Call the appropriate subcommand method
        subcmd = getattr(self, args.subcmd)
        subcmd(args)
