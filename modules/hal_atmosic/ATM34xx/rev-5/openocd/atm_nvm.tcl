#
# atm_nvm.tcl
# Provide NVM functions
# Copyright (C) Atmosic 2024
#


proc atm_dump_nvm { image region_start region_size } {
    adapter speed 75
    dump_image $image [expr $region_start] $region_size
    adapter speed $::_SWD_KHZ
}

proc atm_load_nvm { image } {
    atm_load_rram $image
}

proc atm_verify_nvm { image } {
    atm_verify_rram $image
}
