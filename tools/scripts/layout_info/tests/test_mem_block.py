#!/usr/bin/env python3
"""
@file test_mem_block.py

@brief Unit tests for mem_block

Copyright (C) Atmosic 2023
"""
import pytest
import mem_block


@pytest.mark.parametrize(
    ("name", "region"),
    [
        ("TEST_BLOCK_1", [0, 100]),
        ("TEST_BLOCK_2", [0, 2000]),
        ("TEST_BLOCK_3", [200, 4000]),
    ],
)
class TestSingleBlock:
    def test_block_creation(self, name: str, region) -> None:
        block = mem_block.MemBlock(name, region)
        print(block)

    def test_block_size(self, name: str, region) -> None:
        block = mem_block.MemBlock(name, region)
        assert block.size == region[1] - region[0]

    def test_block_self_subset(self, name: str, region) -> None:
        block = mem_block.MemBlock(name, region)
        assert block.is_subset_of(block)

    def test_block_self_overlap(self, name: str, region) -> None:
        block = mem_block.MemBlock(name, region)
        assert block.overlaps(block)


@pytest.mark.parametrize(
    ("block1", "block2"),
    [
        (mem_block.MemBlock("B1", [0, 100]), mem_block.MemBlock("B2", [0, 2000])),
        (mem_block.MemBlock("B1", [100, 300]), mem_block.MemBlock("B2", [0, 5000])),
    ],
)
class TestTwoBlocksTest:
    def test_block_subsets(self, block1, block2) -> None:
        assert block1.is_subset_of(block2)
        assert not block2.is_subset_of(block1)

    def test_block_overlaps(self, block1, block2) -> None:
        assert block1.overlaps(block2)
        assert block2.overlaps(block1)

    def test_block_add(self, block1, block2) -> None:
        block2.add_block(block1)
        assert len(block2.sub_blocks) > 0

    def test_block_add_neg(self, block1, block2) -> None:
        with pytest.raises(ValueError):
            block1.add_block(block2)
        assert len(block1.sub_blocks) == 0
