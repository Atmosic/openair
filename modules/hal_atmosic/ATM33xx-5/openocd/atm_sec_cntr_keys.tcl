#
# atm_sec_cntr_keys.tcl
# Provide secure Counter and Key functions
# Copyright (C) Atmosic 2023
#


set CMSDK_SECURE_COUNTER_OFFSET 0x8FEF0

set NUM_SECURE_COUNTERS 8
# each counter is a word
set SECURE_COUNTER_SIZE 4

set CMSDK_SIDELOAD_KEY_OFFSET 0x8FF00
set NUM_SIDELOAD_KEYS 8
set SIDELOAD_KEY_SLOT_SIZE 32

proc atm_erase_secure_counters { } {
    adapter speed 50
    rram_write_enable
    mww $::CMSDK_SECURE_COUNTER_OFFSET 0x00 [expr { $::SECURE_COUNTER_SIZE*$::NUM_SECURE_COUNTERS }]
    rram_write_disable
    adapter speed $::_SWD_KHZ
}

proc atm_print_secure_counter { {counter_idx ""} } {
    if {$counter_idx eq ""} {
	for {set i 0} {$i < $::NUM_SECURE_COUNTERS} {incr i} {
	    set counter_offset [expr { $::CMSDK_SECURE_COUNTER_OFFSET + ($i*$::SECURE_COUNTER_SIZE) }]
	    set counter_val [mrw $counter_offset]
	    puts "secure_counter\[$i\] = [format 0x%x $counter_val]"
	}
    } else {
	if {!($counter_idx < $::NUM_SECURE_COUNTERS)} {
	    error "Secure counter index must be between 0-7"
	}
	set counter_offset [expr { $::CMSDK_SECURE_COUNTER_OFFSET + ($counter_idx*$::SECURE_COUNTER_SIZE) }]
	set counter_val [mrw $counter_offset]
	puts "secure_counter\[$counter_idx\] = [format 0x%x $counter_val]"
    }
}


proc print_key { key_idx } {
    set key_offset [expr { $::CMSDK_SIDELOAD_KEY_OFFSET + ($key_idx*$::SIDELOAD_KEY_SLOT_SIZE) }]
    set key ""
    for {set i 0} {$i < [expr { $::SIDELOAD_KEY_SLOT_SIZE / 4 }]} {incr i} {
        append key [format "%08x" [mrw [expr { $key_offset + $i * 4 }] ]]
    }
    return $key
}

proc atm_print_sideload_key { {key_idx ""} } {
    if {$key_idx eq ""} {
	for {set i 0} {$i < $::NUM_SECURE_COUNTERS} {incr i} {
	    puts "sideload_key_\[$i\] = [print_key $i]"
	}
    } else {
	if {!($key_idx < $::NUM_SIDELOAD_KEYS)} {
	    error "Sideload key index must be between 0-7"
	}
	puts "sideload_key\[$key_idx\] = [print_key $key_idx]"
    }
}

proc atm_write_sideload_key { key_idx {key_data ""} } {
    adapter speed 50
    if {!($key_idx < $::NUM_SIDELOAD_KEYS)} {
	error "Sideload key index must be between 0-7"
    }
    set key_offset [expr { $::CMSDK_SIDELOAD_KEY_OFFSET + ($key_idx*$::SIDELOAD_KEY_SLOT_SIZE) }]
    rram_write_enable
    if {$key_data eq ""} {
        for {set i 0} {$i < [expr { $::SIDELOAD_KEY_SLOT_SIZE / 4 }]} {incr i} {
            mww [expr { $key_offset + $i*4 }] 0
        }
    } else {
        load_image $key_data $key_offset bin $::SIDELOAD_KEY_SLOT_SIZE
    }
    rram_write_disable
}
