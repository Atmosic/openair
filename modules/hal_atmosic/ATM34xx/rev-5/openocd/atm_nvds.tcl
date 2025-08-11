#
# atm_nvds.tcl
# Provide NVDS functions
# Copyright (C) Atmosic 2022
#


proc atm_erase_nvds { region_start region_size } {
    atm_erase_rram [expr { $region_start }] $region_size
}

proc atm_dump_nvds { image region_start region_size } {
    adapter speed 75
    dump_image $image [expr { $region_start }] $region_size
    adapter speed $::_SWD_KHZ
}

proc atm_load_nvds { image } {
    atm_load_rram $image
}

proc atm_verify_nvds { image } {
    atm_verify_rram $image
}
