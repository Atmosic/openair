#!/usr/bin/env python3
"""
@file layout_info.py

@brief Visualize memory layouts.

Copyright (C) Atmosic 2023
"""
import itertools
import argparse
import sys
from mem_block import auto_sort
from mem_block import MemBlock

LAYOUT_INFO_VERSION = "0.0.0"

# list of known regions not to dump
blackout_list = ["SECONDARY_SLOT_TRAILER"]

# list of filtered var_types
filter_list = ["OFFSET"]

SECURE_ADDR_BASE = 0x10000000


def auto_int(x):
    """arg parse type that parses all int types when passes as param"""
    return int(x, 0)


class PartitionEntry:
    """Single Partition"""

    def __init__(self, name: str, lbound: int = -1, size: int = -1):
        """Processed Entry from Parititon Map"""
        self.name = name
        self.lbound = lbound
        self.size = size

    @property
    def ubound(self):
        """upper bound of partition entry"""
        return self.lbound + self.size

    def is_valid(self):
        """Check if entry is valid"""
        return self.lbound != -1 and self.size != -1

    def __str__(self):
        return f"[{self.name} ({self.lbound}-{self.ubound})]"

    def __repr__(self):
        return f"[{self.name} ({self.lbound}-{self.ubound})]"


class Partitions:
    """All Partitions"""

    def __init__(self) -> None:
        self.paritions = {}

    def __getitem__(self, name):
        return self.paritions[name]

    def __iter__(self):
        return iter(self.paritions)

    def keys(self):
        """return partition labels"""
        return self.paritions.keys()

    def items(self):
        """All partitions in the list"""
        return self.paritions.items()

    def values(self):
        """return partition size/offsets"""
        return self.paritions.values()

    def add(self, name, value, vtype):
        """Add new partition entry"""
        if name in self.paritions:
            if vtype == "SIZE":
                self.paritions[name].size = value
            else:
                self.paritions[name].lbound = value
        else:
            if vtype == "SIZE":
                self.paritions[name] = PartitionEntry(name, size=value)
            else:
                self.paritions[name] = PartitionEntry(name, lbound=value)

    def __str__(self):
        return str(self.paritions)


def dump_layout(memory_types, max_spacing=40):
    """Display memory block layout"""
    spacing = " " * 5  # Between cards.
    for pieces in itertools.zip_longest(
        *(str(block).splitlines() for block in memory_types)
    ):
        pieces = [x.ljust(max_spacing) for x in pieces if x is not None]
        print(spacing.join(pieces))


def handle_partitions(layout_flags):
    """Create memory block for all  valid partitions"""
    blocks = []
    for flag in layout_flags:
        if layout_flags[flag].is_valid():
            blocks.append(
                MemBlock(
                    layout_flags[flag].name,
                    [layout_flags[flag].lbound, layout_flags[flag].ubound],
                )
            )

    top_blocks = auto_sort(blocks)
    dump_layout(top_blocks)


def main():
    """Generate human readable partition layout information"""
    parser = argparse.ArgumentParser(
        description="Visualize memory layout for Atmosic chips"
    )
    parser.add_argument(
        "--version",
        action="store_true",
        help="Print out current version of layout_info tool",
    )
    parser.add_argument(
        "-v", "--verbose", action="store_true", help="Enable verbose output"
    )
    parser.add_argument(
        "--layout-file", required=True, help="Layout variables to build layout."
    )

    args = parser.parse_args()

    if args.version:
        print(f"layout_info version: {LAYOUT_INFO_VERSION}")
        sys.exit(0)

    layout_partitions = Partitions()
    with open(args.layout_file, "r", encoding="ascii") as f:
        for flag in f.readlines():
            name, value = flag.strip().split("=")
            try:
                value = auto_int(value)
                # Normalize to non secure address space
                if value & SECURE_ADDR_BASE:
                    value &= ~SECURE_ADDR_BASE
                mem_name, var_type = name.rsplit("_", 1)
                if mem_name not in blackout_list:
                    if var_type not in filter_list:
                        layout_partitions.add(mem_name, value, var_type)
            except ValueError:
                # Ignore non-value related layout_map flags
                pass

    handle_partitions(layout_partitions)


if __name__ == "__main__":
    main()
