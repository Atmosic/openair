#
# atm_nvds.tcl
# Provide NVDS functions
# Copyright (C) Atmosic 2022
#

proc sydney_erase_nvds { {region_start 0x78000} {region_size 0x8000} } {
    sydney_erase_flash_nvds $region_start $region_size
}

proc sydney_dump_nvds { image {region_start 0x78000} {region_size 0x8000} {mem_bank "bank0"} } {
    sydney_dump_flash_nvds $image $region_start $region_size $mem_bank
}

proc sydney_load_nvds { image {region_start 0x78000} {region_size 0x8000} } {
    sydney_load_flash_nvds $image $region_start $region_size
}

proc sydney_verify_nvds { image {region_start 0x78000} {region_size 0x8000} } {
    sydney_verify_flash_nvds $image $region_start $region_size
}

