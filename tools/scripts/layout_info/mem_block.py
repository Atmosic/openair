#!/usr/bin/env python3
"""
@file mem_block.py

@brief Memory Blocks for layout_info

Copyright (C) Atmosic 2023-2025
"""
from typing import List
import textwrap
import os


def human_readable(x):
    """return a human readable format of a value"""
    return f"{int(x/1024)}K"


class MemBlock:
    """Memory Block class"""

    # Filler character
    if os.name == "nt":
        FILL_CH = " "
        LIM_CH = "_"
        EDGE_CH = "|"
    else:
        FILL_CH = "░"
        LIM_CH = "─"
        EDGE_CH = "│"
    SUB_LIM_CH = "-"
    MIN_BLOCK_HEIGHT_PP = 3
    # Does not include edge width. total width is 22
    BLOCK_WIDTH_PP = 20

    def __init__(self, name: str, region: List[int] = None, sub_title: str = ""):
        if len(region) != 2:
            raise ValueError("Bad region input")
        self.name = name
        self.sub_title = sub_title
        self.l_bound = region[0]
        self.u_bound = region[1]
        self.sub_lim_char = MemBlock.SUB_LIM_CH
        if os.name == "nt":
            self.left_end_pp = "|"
            self.right_end_pp = "|"
        else:
            self.left_end_pp = "├"
            self.right_end_pp = "┤"
        self.sub_blocks = []

    @property
    def size(self):
        """Return size of memory block"""
        return self.u_bound - self.l_bound

    def add_block(self, block: "MemBlock"):
        """Add memory block"""
        if not block.is_subset_of(self):
            raise ValueError("block must be in range.")
        self.sub_blocks.append(block)

    def get_tree(self, level=0):
        """Return tree of memory blocks"""
        ret = "\t" * level + repr(self.name) + "\n"
        for child in self.sub_blocks:
            ret += child.get_tree(level + 1)
        return ret

    def __lt__(self, other: "MemBlock"):
        if (self.l_bound < other.l_bound) and (self.u_bound < other.u_bound):
            # fully less than, no overlap
            return 1
        if other.is_subset_of(self):
            # other is a subset of self. self is larger.
            return 0
        if self.is_subset_of(other):
            # self is a subset of other. other is larger.
            return 1
        return (self.l_bound < other.l_bound) or (self.u_bound < other.u_bound)

    def is_subset_of(self, other: "MemBlock"):
        """Checks if new block exists in self

        Args:
            other (MemBlock): other memory block to check

        Returns:
            bool: True if overlap, False otherwise
        """
        return (self.l_bound >= other.l_bound) and (self.u_bound <= other.u_bound)

    def overlaps(self, other: "MemBlock"):
        """Checks if two blocks overlap

        Args:
            other (MemBlock): other memory block to check

        Returns:
            bool: True if overlap, False otherwise
        """
        return (self.l_bound <= other.u_bound) and (other.l_bound <= self.u_bound)

    def fill_reserved(self):
        """Automatically inserts reserved blocks between empty memory spaces."""
        sorted_blocks = sorted(self.sub_blocks)
        prev_l_bound = -1
        prev_u_bound = -1
        reserved_blocks = []
        for block in sorted_blocks:
            if prev_l_bound != -1:
                if prev_u_bound != block.l_bound:
                    reserved_blocks.append(ReservedBlock([prev_u_bound, block.l_bound]))
            prev_l_bound = block.l_bound
            prev_u_bound = block.u_bound
        self.sub_blocks += reserved_blocks

    def promote_to_mem_region(self):
        """Promote a memory block to a memory region."""
        region = MemoryRegion(self.name, [self.l_bound, self.u_bound])
        region.sub_blocks = self.sub_blocks
        # Fill in reserved regions.
        region.fill_reserved()
        return region

    def __str__(self):
        name_pad = 4
        name_max_len = MemBlock.BLOCK_WIDTH_PP - name_pad
        if len(self.sub_blocks) == 0:
            p_str = (
                f"{MemBlock.EDGE_CH}"
                + f"{MemBlock.FILL_CH*MemBlock.BLOCK_WIDTH_PP}"
                + f"{MemBlock.EDGE_CH}\n"
            )
            name = " ".join(self.name.split("_"))
            lines = textwrap.wrap(name, name_max_len)
            for i, line in enumerate(lines):
                p_str += (
                    f"{MemBlock.EDGE_CH}"
                    + f"{line.center(MemBlock.BLOCK_WIDTH_PP,MemBlock.FILL_CH)}"
                    + f"{MemBlock.EDGE_CH}"
                )
                if i == 0:
                    p_str += f"({self.size:#0{7}x} {human_readable(self.size)})"
                p_str += "\n"
            p_str += (
                f"{MemBlock.EDGE_CH}"
                + f"{MemBlock.FILL_CH*MemBlock.BLOCK_WIDTH_PP}"
                + f"{MemBlock.EDGE_CH}\n"
            )
        else:
            sub_delimit_str = (
                f"{self.left_end_pp}"
                + f"{MemBlock.SUB_LIM_CH*MemBlock.BLOCK_WIDTH_PP}"
                + f"{self.right_end_pp}"
            )
            sorted_blocks = sorted(self.sub_blocks, reverse=True)
            p_str = str(sorted_blocks[0])
            for block in sorted_blocks[1:]:
                p_str += sub_delimit_str
                p_str += f" {hex(block.u_bound)}\n"
                p_str += str(block)
        return p_str


class MemoryType(MemBlock):
    """block of memory that is RESERVED."""

    def __init__(self, name, region=None):
        super().__init__(name, region=region)
        self.sub_lim_char = MemBlock.LIM_CH


class ReservedBlock(MemBlock):
    """block of memory that is RESERVED."""

    def __init__(self, region=None):
        super().__init__("RESERVED", region=region)


class MemoryRegion(MemBlock):
    """Memory block that defines a top level Memory type (e.g. flash, rram)"""

    def __init__(self, name, region=None):
        super().__init__(name, region=region)
        self.mem_type = name

    def __str__(self):
        p_str = f"{self.mem_type.center(MemBlock.BLOCK_WIDTH_PP + 2)}\n"
        p_str += f"*{MemBlock.LIM_CH*MemBlock.BLOCK_WIDTH_PP}*"
        if len(self.sub_blocks) == 0:
            p_str += f" {hex(self.u_bound)}\n" + super().__str__()
        else:
            sub_delimit_str = f"{self.left_end_pp}{MemBlock.LIM_CH*MemBlock.BLOCK_WIDTH_PP}{self.right_end_pp}"
            p_str += sub_delimit_str.join(
                [
                    f" {hex(block.u_bound)}\n" + str(block)
                    for block in sorted(self.sub_blocks, reverse=True)
                ]
            )
        p_str += f"*{MemBlock.LIM_CH * MemBlock.BLOCK_WIDTH_PP}* {hex(self.l_bound)}\n"
        return p_str


def get_min_sub_block(block1, block2):
    """find the smallest sub block that one block fits into another"""
    if block1.is_subset_of(block2):
        if len(block2.sub_blocks):
            for s_block in block2.sub_blocks:
                ret = get_min_sub_block(block1, s_block)
                if ret is not None:
                    return ret
        return block2
    return None


def swap_ext_flash_with_parent(memory_regions):
    """Swap parent region with EXT_FLASH child when they have identical address ranges

    When any region contains EXT_FLASH as a child with the same address range, swap them so:
    - Header shows "EXT_FLASH"
    - Content shows the original parent region name
    """
    for region in memory_regions:
        # Look for EXT_FLASH in direct children with same address range
        for sub_block in region.sub_blocks:
            if (
                "EXT_FLASH" in sub_block.name.upper()
                and sub_block.l_bound == region.l_bound
                and sub_block.u_bound == region.u_bound
            ):
                # Swap header and content
                original_name = region.mem_type
                region.mem_type = sub_block.name
                region.sub_blocks = [
                    MemBlock(original_name, [region.l_bound, region.u_bound])
                ]
                break

    return sorted(memory_regions)


def auto_sort(blocks):
    """Auto sort all blocks"""
    s_blocks = sorted(blocks, reverse=True)
    top_blocks = []
    while s_blocks:
        curr_block = s_blocks.pop(0)
        if curr_block.size == 0:
            # Dont add empty blocks.
            continue
        parent_block = None
        for t_block in top_blocks:
            parent_block = get_min_sub_block(curr_block, t_block)
        if parent_block is None:
            top_blocks.append(curr_block)
        else:
            parent_block.add_block(curr_block)

    # Promote to memory regions and swap EXT_FLASH with parent if needed
    memory_regions = [b.promote_to_mem_region() for b in sorted(top_blocks)]
    return swap_ext_flash_with_parent(memory_regions)
