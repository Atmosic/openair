#
# atm2x_rom.tcl
# Production APIs for ROM operations
# Copyright (C) Atmosic 2018-2020
#

proc verify_rom_version {} {
    reset halt
    if {[mrw 0x3cdb0] == 0x422d5752} {
	error "Incompatible with ATM2xE1 or ATM2xE2 part!"
    } elseif {[mrw 0x3d8e8] == 0x422d5752} {
	error "Incompatible with ATM2xE2b part!"
    } elseif {[mrw 0x3ae2c] == 0x422d5752} {
	error "Incompatible with ATM2xE3, ATM2xE3a, or ATM2xE3b part!"
    } elseif {[mrw 0x3ea30] == 0x422d5752} {
	error "Incompatible with ATM2xE3c or ATMx2xx-x0x part!"
    } elseif {[mrw 0x3f2c8] == 0x454c422d} {
	error "Incompatible with ATMx2xx-x1x part!"
    }
}

proc get_rom_version {} {
    reset halt
    if {[mrw 0x3cdb0] == 0x422d5752} {
	return [list ATM2xE1 ATM2xE2]
    } elseif {[mrw 0x3d8e8] == 0x422d5752} {
	return [list ATM2xE2b]
    } elseif {[mrw 0x3ae2c] == 0x422d5752} {
	return [list ATM2xE3 ATM2xE3a ATM2xE3b]
    } elseif {[mrw 0x3ea30] == 0x422d5752} {
	return [list ATM2xE3c ATM22xx-x0x ATM32xx-x0x]
    } elseif {[mrw 0x3f2c8] == 0x454c422d} {
	return [list ATM22xx-x1x ATM32xx-x1x]
    }
    error "Unrecognized platform"
}

proc load_ram_image { external_flash_init image {entry_point 0x20014000} } {
    reset halt

    # Hijack flash app
    bp $external_flash_init 2 hw
    resume; sleep 1; wait_halt
    rbp $external_flash_init

    # Relocate stack if necessary
    if {$entry_point != 0x20014000} {
	set src 0x20014000
	set end [lindex [reg sp] 2]
	set dst $entry_point
	puts -nonewline "Relocate stack $end..$src"
	while {$src != $end} {
	    incr src -4
	    incr dst -4
	    mww $dst [mrw $src]
	}
	set dstx [format 0x%x $dst]
	puts " to $dstx..$entry_point"
	reg sp $dst
    }

    load_image $image $entry_point
}
