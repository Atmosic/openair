# Copyright (c) 2022-2026 Atmosic
#
# SPDX-License-Identifier: LicenseRef-Atmosic
#
# Provide NVDS functions


proc atm_erase_nvds { {region_start 0x78000} {region_size 0x8000} } {
    set flash_region_offset [expr {$region_start - $::CMSDK_FLASH_BASE}]
    atm_erase_flash $region_size $flash_region_offset
}

proc atm_dump_nvds { image {region_start 0x78000} {region_size 0x8000} {mem_bank "bank0"} } {
    atm_dump_flash $image $region_size $region_start
}

proc atm_load_nvds { image {region_start 0x78000} {region_size 0x8000} } {
    set flash_region_offset [expr {$region_start - $::CMSDK_FLASH_BASE}]
    atm_load_flash $image $flash_region_offset $region_size $region_start
}

proc atm_verify_nvds { image {region_start 0x78000} {region_size 0x8000} } {
    atm_verify_flash $image $region_start
}
