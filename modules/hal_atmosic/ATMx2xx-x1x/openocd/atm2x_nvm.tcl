#
# atm2x_nvm.tcl
# Production APIs for NVM (aka: OTP, efuse) operations
# Copyright (C) Atmosic 2018-2019
#

#
# NVM
#

set NVM_SIZE 4096

proc nvm_read_byte { addr } {
    global CMSDK_AHB_NVM_BASE

    return [mrb [expr {$CMSDK_AHB_NVM_BASE + $addr}]]
}

proc nvm_set_bit { byte_addr bit } {
    global CMSDK_NVM_OPMODE
    global CMSDK_NVM_ADDRESS
    global CMSDK_NVM_STATUS

    set bit_addr [expr {(($byte_addr & ~0x3ff) << 3) | (($bit & 0x7) << 10) | ($byte_addr & 0x3ff)}]
    mww $CMSDK_NVM_ADDRESS $bit_addr
    mww $CMSDK_NVM_OPMODE 0x80000002
    while {([mrw $CMSDK_NVM_STATUS] & 0x80000000) == 0x80000000} {}
}

proc nvm_fdb { addr count } {
    set ret ""

    for {set i 0} {$i < $count} {incr i} {
	set ret [concat $ret [format " %02x" [nvm_read_byte [expr {$addr+$i}]]]]
    }
    return $ret
}

proc sydney_dump_nvm { image } {
    global CMSDK_AHB_NVM_BASE
    global NVM_SIZE

    reset halt

    enable_nvm

    dump_image $image $CMSDK_AHB_NVM_BASE $NVM_SIZE
}

proc sydney_precheck_nvm { image } {
    global CMSDK_RAM_BASE
    global NVM_SIZE

    reset halt

    mww $CMSDK_RAM_BASE 0x00000000 [expr {$NVM_SIZE / 4}]
    load_image $image $CMSDK_RAM_BASE

    enable_nvm
    for {set i 0} {$i < $NVM_SIZE} {incr i} {
	set old [nvm_read_byte $i]
	set maddr [expr {$CMSDK_RAM_BASE + $i}]
	set new [mrb $maddr]

	if {($old & $new) != $old} {
	    error [format "ERROR: bit cleared @0x%x: %02x->%02x" $i $old $new]
	}
    }

    return "OK"
}

proc sydney_burn_nvm { image } {
    global CMSDK_RAM_BASE
    global NVM_SIZE
    global CMSDK_WRPR_PIN_SELECTION_E

    reset halt

    mww $CMSDK_RAM_BASE 0x00000000 [expr {$NVM_SIZE / 4}]
    load_image $image $CMSDK_RAM_BASE

    enable_nvm
    # Compute the change set
    for {set i 0} {$i < $NVM_SIZE} {incr i} {
	set old [nvm_read_byte $i]
	set maddr [expr {$CMSDK_RAM_BASE + $i}]
	set new [mrb $maddr]

	if {($old & $new) != $old} {
	    error [format "ERROR: bit cleared @0x%x: %02x->%02x" $i $old $new]
	}

	mwb $maddr [expr {$old ^ $new}]
    }

    # Set the changed bits
    for {set i 0} {$i < $NVM_SIZE} {incr i} {
	set maddr [expr {$CMSDK_RAM_BASE + $i}]
	set new [mrb $maddr]

	if {$new == 0x00} {
	    continue
	}
	for {set bit 0} {$bit < 8} {incr bit} {
	    if {($new & (1 << $bit)) == 0} {
		continue
	    }
	    nvm_set_bit $i $bit
	}
    }

    return "OK"
}

proc sydney_verify_nvm { image } {
    global CMSDK_RAM_BASE
    global NVM_SIZE

    reset halt

    mww $CMSDK_RAM_BASE 0x00000000 [expr {$NVM_SIZE / 4}]
    load_image $image $CMSDK_RAM_BASE

    enable_nvm
    for {set i 0} {$i < $NVM_SIZE} {incr i} {
	set old [nvm_read_byte $i]
	set maddr [expr {$CMSDK_RAM_BASE + $i}]
	set new [mrb $maddr]

	if {$old != $new} {
	    error [format "ERROR: difference @0x%x: %02x-%02x" $i $old $new]
	}
    }

    return "OK"
}

proc sydney_burn_autoread_bit { byte_off bit_off } {
    global NVM_SIZE

    reset halt

    enable_nvm
    set addr [expr {$NVM_SIZE - 4 + $byte_off}]
    set old [nvm_read_byte $addr]

    if {($old & (1 << $bit_off)) == 0} {
        nvm_set_bit $addr $bit_off
    }
}

set AUTOREAD_SWD_DISABLE_BIT_OFF 0
set AUTOREAD_SWD_DISABLE_BYTE_OFF 0

# !!!! Warning !!!!
# This operation will disable SWD interfacer permanently and can't be reverted.
proc sydney_burn_swd_disable {} {

    sydney_burn_autoread_bit $::AUTOREAD_SWD_DISABLE_BYTE_OFF $::AUTOREAD_SWD_DISABLE_BIT_OFF
}

set AUTOREAD_5x5_BIT_OFF 3
set AUTOREAD_5x5_BYTE_OFF 0
proc sydney_burn_5x5 {} {
    global AUTOREAD_5x5_BIT_OFF
    global AUTOREAD_5x5_BYTE_OFF

    sydney_burn_autoread_bit $AUTOREAD_5x5_BYTE_OFF $AUTOREAD_5x5_BIT_OFF
}

set AUTOREAD_STACKED_BIT_OFF 4
set AUTOREAD_STACKED_BYTE_OFF 0
proc sydney_burn_stacked {} {
    global AUTOREAD_STACKED_BIT_OFF
    global AUTOREAD_STACKED_BYTE_OFF

    sydney_burn_autoread_bit $AUTOREAD_STACKED_BYTE_OFF $AUTOREAD_STACKED_BIT_OFF
}

set AUTOREAD_HARV_TYPE_BIT_OFF 2
set AUTOREAD_HARV_TYPE_BYTE_OFF 3
proc sydney_burn_harv_type {} {
    global AUTOREAD_HARV_TYPE_BIT_OFF
    global AUTOREAD_HARV_TYPE_BYTE_OFF

    sydney_burn_autoread_bit $AUTOREAD_HARV_TYPE_BYTE_OFF $AUTOREAD_HARV_TYPE_BIT_OFF
}

set AUTOREAD_NO_32K_XTAL_BIT_OFF 7
set AUTOREAD_NO_32K_XTAL_BYTE_OFF 3
proc sydney_burn_no_32k_xtal {} {
    global AUTOREAD_NO_32K_XTAL_BIT_OFF
    global AUTOREAD_NO_32K_XTAL_BYTE_OFF

    sydney_burn_autoread_bit $AUTOREAD_NO_32K_XTAL_BYTE_OFF $AUTOREAD_NO_32K_XTAL_BIT_OFF
}

set AUTOREAD_IGNORE_32K_XTAL_CHECK_BIT_OFF 0
set AUTOREAD_IGNORE_32K_XTAL_CHECK_BYTE_OFF 3
proc sydney_burn_ignore_32k_xtal_check {} {
    sydney_burn_autoread_bit $::AUTOREAD_IGNORE_32K_XTAL_CHECK_BYTE_OFF $::AUTOREAD_IGNORE_32K_XTAL_CHECK_BIT_OFF
}
