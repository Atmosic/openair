#!/usr/bin/env python3
# Copyright (c) 2026 Atmosic
#
# SPDX-License-Identifier: LicenseRef-Atmosic
"""
pack_combined_image.py - Pack two MCUboot signed binaries into a single
combined-image OTA binary consumed by openair/lib/atm_vendor_dfu.

Combines Image 0 (typically zephyr.signed.bin, RRAM slot1_partition) and
Image 1 (typically zephyr.signed.flash.bin, external-flash slot3_partition)
into one ATMX-tagged binary that the on-device helper splits back into the
correct MCUboot secondary slots.

Header format (all little-endian, 32 bytes total):
  Offset  Size  Field
  ----------------------------------------------
  0x00    4     magic    = 0x584D5441 (ASCII 'ATMX')
  0x04    4     version  = 1
  0x08    4     img0_size  (size of Image 0 binary in bytes)
  0x0C    4     img1_size  (size of Image 1 binary in bytes)
  0x10    16    reserved   (zeros)

Followed immediately by the raw bytes of Image 0, then Image 1.
"""

import argparse
import os
import struct
import sys

ATM_VENDOR_DFU_MAGIC = 0x584D5441  # 'ATMX' in little-endian
ATM_VENDOR_DFU_VERSION = 1
ATM_VENDOR_DFU_HDR_SIZE = 32


def pack(img0_path: str, img1_path: str, out_path: str) -> int:
    """Pack two signed binaries into a combined-image OTA binary.

    Returns 0 on success, non-zero on error.
    """
    for path in (img0_path, img1_path):
        if not os.path.isfile(path):
            print(f"ERROR: file not found: {path}", file=sys.stderr)
            return 1

    with open(img0_path, "rb") as f:
        img0 = f.read()
    with open(img1_path, "rb") as f:
        img1 = f.read()

    img0_size = len(img0)
    img1_size = len(img1)

    # '<IIII' = 4 x uint32_t (16 bytes), then '16x' = 16 reserved bytes
    header = struct.pack(
        "<IIII16x", ATM_VENDOR_DFU_MAGIC, ATM_VENDOR_DFU_VERSION, img0_size, img1_size
    )
    assert len(header) == ATM_VENDOR_DFU_HDR_SIZE, "Header size mismatch"

    with open(out_path, "wb") as f:
        f.write(header)
        f.write(img0)
        f.write(img1)

    total = ATM_VENDOR_DFU_HDR_SIZE + img0_size + img1_size
    print(f"Created {out_path}:")
    print(
        f"  Header:  {ATM_VENDOR_DFU_HDR_SIZE} bytes  "
        f"(magic=0x{ATM_VENDOR_DFU_MAGIC:08X} ver={ATM_VENDOR_DFU_VERSION})"
    )
    print(f"  Image 0: {img0_size} bytes  ({img0_path})")
    print(f"  Image 1: {img1_size} bytes  ({img1_path})")
    print(f"  Total:   {total} bytes")
    return 0


def main() -> int:
    """Entry point: parse CLI arguments and invoke pack()."""
    parser = argparse.ArgumentParser(
        description="Pack a combined-image OTA binary for atm_vendor_dfu"
    )
    parser.add_argument("img0", help="Image 0 binary (e.g. zephyr.signed.bin, RRAM)")
    parser.add_argument(
        "img1", help="Image 1 binary (e.g. zephyr.signed.flash.bin, External Flash)"
    )
    parser.add_argument(
        "-o",
        "--output",
        required=True,
        help="Output combined binary (e.g. combined_fw_upd.bin)",
    )
    args = parser.parse_args()
    return pack(args.img0, args.img1, args.output)


if __name__ == "__main__":
    sys.exit(main())
