#
# atm_flash.tcl
# Production APIs for flash operations
# Copyright (C) Atmosic 2018-2022
#
source [find atm_reg_wrappers.tcl]

proc do_spi_transaction { spi_name csn_stays_low opcode num_data_bytes upper lower } {
    upvar #0 $spi_name spi

    mww [::$spi(ns)::DATA_BYTES_LOWER $spi(base)] $lower
    mww [::$spi(ns)::DATA_BYTES_UPPER $spi(base)] $upper

    namespace eval ::$spi(ns)::TRANSACTION_SETUP {
	upvar "spi" spi
	upvar "csn_stays_low" csn_stays_low
	upvar "opcode" opcode
	upvar "num_data_bytes" num_data_bytes
	set transaction [expr { \
	    [DUMMY_CYCLES::WRITE $spi(dummy)] | \
	    [CSN_STAYS_LOW::WRITE $csn_stays_low] | \
	    [OPCODE::WRITE $opcode] | \
	    [CLKDIV::WRITE $spi(clkdiv)] | \
	    [RWB::MASK] | \
	    [NUM_DATA_BYTES::WRITE $num_data_bytes]}]
	mww [REG_ADDR $spi(base)] $transaction
	mww [REG_ADDR $spi(base)] [expr { $transaction | [START::MASK]}]
    }

    namespace eval ::$spi(ns)::TRANSACTION_STATUS {
	upvar "spi" spi
	while {([mrw [REG_ADDR $spi(base)]] & [RUNNING::MASK]) == \
	       [RUNNING::MASK]} {}
    }
}

proc do_spi_read { spi_name opcode {len 1} } {
    upvar #0 $spi_name spi
    do_spi_transaction $spi_name 0 $opcode $len 0x0 0x0
    return [mrw [::$spi(ns)::DATA_BYTES_LOWER $spi(base)]]
}

proc spi_write_enable { spi_name } {
    do_spi_transaction $spi_name 0 0x06 0 0x0 0x0
}

proc spi_vsr_write_enable { spi_name } {
    do_spi_transaction $spi_name 0 0x50 0 0x0 0x0
}

proc spi_macronix_exit_deep_power_down { spi_name } {
    do_spi_transaction $spi_name 0 0xab 0 0x0 0x0
}

proc spi_macronix_enter_secured_otp { spi_name } {
    do_spi_transaction $spi_name 0 0xb1 0 0x0 0x0
}

proc spi_macronix_exit_secured_otp { spi_name } {
    do_spi_transaction $spi_name 0 0xc1 0 0x0 0x0
}

proc spi_macronix_make_quad { spi_name } {
    spi_write_enable $spi_name
#   WRITE STATUS REG - High perf, Quad Enable
    do_spi_transaction $spi_name 0 0x01 3 0x0 0x020040
}

proc spi_giga_make_quad { spi_name } {
    spi_write_enable $spi_name
#   WRITE STATUS REG - Quad Enable
    do_spi_transaction $spi_name 0 0x01 2 0x0 0x0200
}

proc spi_giantec_make_quad { spi_name } {
    spi_write_enable $spi_name
#   WRITE STATUS REG - Quad Enable
    do_spi_transaction $spi_name 0 0x01 2 0x0 0x0200
}

proc spi_fudan_make_quad { spi_name } {
    spi_write_enable $spi_name
    do_spi_transaction $spi_name 0 0x31 1 0x0 0x02
}

proc spi_puya_make_quad { spi_name } {
    spi_write_enable $spi_name
#   WRITE STATUS REG - Quad Enable
    do_spi_transaction $spi_name 0 0x01 2 0x0 0x0200
}

proc spi_winbond_make_quad { spi_name } {
    spi_vsr_write_enable $spi_name
    do_spi_transaction $spi_name 0 0x31 1 0x0 0x02
}

proc flash_lower_from_addr { addr } {
    return [expr {(($addr & 0xff) << 16) | ($addr & 0xff00) | (($addr & 0xff0000) >> 16)}]
}

proc spi_read_flash_byte { spi_name addr } {
    upvar #0 $spi_name spi

    do_spi_transaction $spi_name 0 0x03 4 0x0 [flash_lower_from_addr $addr]
    return [expr {[mrw [::$spi(ns)::DATA_BYTES_LOWER $spi(base)]] >> 24}]
}

proc flash_upper_lower_to_be_word { upper lower } {
    return [expr {($lower & 0xff000000) | (($upper & 0xff) << 16) | ($upper & 0xff00) | (($upper & 0xff0000) >> 16)}]
}

proc flash_upper_lower_to_le_word { upper lower } {
    return [expr {(($upper & 0xffffff) << 8) | ($lower >> 24)}]
}

proc spi_read_flash_be_word { spi_name addr } {
    upvar #0 $spi_name spi

    do_spi_transaction $spi_name 0 0x03 7 0x0 [flash_lower_from_addr $addr]
    set lower [mrw [::$spi(ns)::DATA_BYTES_LOWER $spi(base)]]
    set upper [mrw [::$spi(ns)::DATA_BYTES_UPPER $spi(base)]]
    return [flash_upper_lower_to_be_word $upper $lower]
}

proc spi_read_flash_le_word { spi_name addr } {
    upvar #0 $spi_name spi

    do_spi_transaction $spi_name 0 0x03 7 0x0 [flash_lower_from_addr $addr]
    set lower [mrw [::$spi(ns)::DATA_BYTES_LOWER $spi(base)]]
    set upper [mrw [::$spi(ns)::DATA_BYTES_UPPER $spi(base)]]
    return [flash_upper_lower_to_le_word $upper $lower]
}

proc spi_fdb { spi_name addr count } {
    set ret ""

    for {set i 0} {$i < $count} {incr i} {
	set ret [concat $ret [format " %02x" [spi_read_flash_byte $spi_name [expr {$addr+$i}]]]]
    }
    return $ret
}

proc spi_read_pmuradio_word { spi_name block addr } {
    upvar #0 $spi_name spi

    set opcode [expr {$block << 4}]
    do_spi_transaction $spi_name 0 $opcode 5 0x0 $addr
    set lower [mrw [::$spi(ns)::DATA_BYTES_LOWER $spi(base)]]
    set upper [mrw [::$spi(ns)::DATA_BYTES_UPPER $spi(base)]]
    return [expr {(($upper & 0xff) << 24) | ($lower >> 8)}]
}

proc spi_write_pmuradio_word { spi_name block addr data } {
    upvar #0 $spi_name spi

    set opcode [expr {($block << 4) | 0x01}]
    set lower [expr {(($data & 0xffffff) << 8) | $addr}]
    set upper [expr {$data >> 24}]
    do_spi_transaction $spi_name 0 $opcode 5 $upper $lower
}

proc spi_write_disable { spi_name } {
    do_spi_transaction $spi_name 0 0x04 0 0x0 0x0
}

proc spi_read_status { spi_name {opcode 0x05} } {
    return [do_spi_read $spi_name $opcode]
}

proc spi_wait_for_no_wip { spi_name } {
    while {1} {
	set ret [spi_read_status $spi_name]
	if {($ret & 0x1) == 0x0} {
	    return $ret
	}
    }
}

proc spi_macronix_chip_erase { spi_name } {
    spi_write_enable $spi_name
    do_spi_transaction $spi_name 0 0xc7 0 0x0 0x0
    set status [spi_wait_for_no_wip $spi_name]
    if {($status & 0x02) != 0x00} {
	error [format "Chip erase command FAILED!  Status Register 0x%02x" $status]
    }
    set scur [spi_macronix_read_scur $spi_name]
    if {($scur & 0x40) != 0x00} {
	error [format "Chip erase FAILED!  Security Register 0x%02x" $scur]
    }
}

proc spi_macronix_sector_erase { spi_name addr } {
    spi_write_enable $spi_name
    do_spi_transaction $spi_name 0 0x20 3 0x0 [flash_lower_from_addr $addr]
    set status [spi_wait_for_no_wip $spi_name]
    if {($status & 0x02) != 0x00} {
	error [format "Sector 0x%06x erase command FAILED!  Status Register 0x%02x" $addr $status]
    }
    set scur [spi_macronix_read_scur $spi_name]
    if {($scur & 0x40) != 0x00} {
	error [format "Sector 0x%06x erase FAILED!  Security Register 0x%02x" $addr $scur]
    }
}

proc spi_winbond_chip_erase { spi_name } {
    spi_write_enable $spi_name
    do_spi_transaction $spi_name 0 0xc7 0 0x0 0x0
    set status [spi_wait_for_no_wip $spi_name]
    if {($status & 0x02) != 0x00} {
	error [format "Chip erase command FAILED!  Status Register 0x%02x" $status]
    }
}

proc spi_winbond_sector_erase { spi_name addr } {
    spi_write_enable $spi_name
    do_spi_transaction $spi_name 0 0x20 3 0x0 [flash_lower_from_addr $addr]
    set status [spi_wait_for_no_wip $spi_name]
    if {($status & 0x02) != 0x00} {
	error [format "Sector 0x%06x erase command FAILED!  Status Register 0x%02x" $addr $status]
    }
}

proc spi_macronix_read_scur { spi_name } {
    return [do_spi_read $spi_name 0x2b]
}

proc spi_micron_read_evcr { spi_name } {
    return [do_spi_read $spi_name 0x65]
}

proc spi_micron_read_flag_status { spi_name } {
    return [do_spi_read $spi_name 0x70]
}

proc spi_micron_make_quad { spi_name } {
    set evcr [spi_micron_read_evcr $spi_name]
    spi_write_enable $spi_name
    do_spi_transaction $spi_name 0 0x61 1 0x0 [expr {$evcr & ~0xd0}]
}

proc spi_reset { spi_name } {
    do_spi_transaction $spi_name 0 0x66 0 0x0 0x0
    do_spi_transaction $spi_name 0 0x99 0 0x0 0x0
}

proc spi_read_flash_id { spi_name {len 1} } {
    return [do_spi_read $spi_name 0x9f $len]
}


#
# QSPI
#

array set QSPI_MICRON {
    type	micron
    dummy	2
}
array set QSPI_MACRONIX {
    type	macronix
    dummy	4
}

proc qspi_drive_start {} {
    namespace eval ::CMSDK_QSPI${::SX}::TRANSACTION_SETUP {
	mww [REG_ADDR] [CSN_VAL::MASK]
    }
}

proc to_oe_format_quad { nibble } {
    switch $nibble {
	 0 {return 0x2222}
	 1 {return 0x2223}
	 2 {return 0x2232}
	 3 {return 0x2233}
	 4 {return 0x2322}
	 5 {return 0x2323}
	 6 {return 0x2332}
	 7 {return 0x2333}
	 8 {return 0x3222}
	 9 {return 0x3223}
	10 {return 0x3232}
	11 {return 0x3233}
	12 {return 0x3322}
	13 {return 0x3323}
	14 {return 0x3332}
	15 {return 0x3333}
	default {return 0}
    }
}

proc qspi_drive_nibble { nibble } {
    set oe [expr {[to_oe_format_quad $nibble] << 8}]
    namespace eval ::CMSDK_QSPI${::SX}::TRANSACTION_SETUP {
	upvar "oe" oe
	mww [REG_ADDR] $oe
	mww [REG_ADDR] [expr {[CLK_VAL::MASK] | $oe}]
    }
}

proc qspi_drive_byte { byte } {
    qspi_drive_nibble [expr {($byte & 0xf0) >> 4}]
    qspi_drive_nibble [expr {$byte & 0x0f}]
}

proc qspi_micron_drive_opcode { opcode } {
    qspi_drive_byte $opcode
}

proc qspi_macronix_drive_opcode { opcode } {
    for {set i 0} {$i < 8} {incr i} {
	set opcode [expr {$opcode << 1}]
	set drive [expr {($opcode & 0x100) | 0x200}]
	namespace eval ::CMSDK_QSPI${::SX}::TRANSACTION_SETUP {
	    upvar "drive" drive
	    mww [REG_ADDR] $drive
	    mww [REG_ADDR] [expr {[CLK_VAL::MASK] | $drive}]
	}
    }
}

proc qspi_winbond_drive_opcode { opcode } {
    for {set i 0} {$i < 8} {incr i} {
	set opcode [expr {$opcode << 1}]
	set drive [expr {($opcode & 0x100) | 0x200}]
	namespace eval ::CMSDK_QSPI${::SX}::TRANSACTION_SETUP {
	    upvar "drive" drive
	    mww [REG_ADDR] $drive
	    mww [REG_ADDR] [expr {[CLK_VAL::MASK] | $drive}]
	}
    }
}

proc qspi_capture_byte {} {
    namespace eval ::CMSDK_QSPI${::SX}::TRANSACTION_SETUP {
	mww [REG_ADDR] 0
	mww [REG_ADDR] [CLK_VAL::MASK]
	mww [REG_ADDR] [expr {[CLK_VAL::MASK] | [SAMPLE_DIN::WRITE 0xf0]}]

	mww [REG_ADDR] 0
	mww [REG_ADDR] [CLK_VAL::MASK]
	mww [REG_ADDR] [expr {[CLK_VAL::MASK] | [SAMPLE_DIN::WRITE 0x0f]}]
    }
}

proc qspi_drive_stop {} {
    namespace eval ::CMSDK_QSPI${::SX}::TRANSACTION_SETUP {
	mww [REG_ADDR] 0
	mww [REG_ADDR] [CSN_VAL::MASK]
    }
}

proc do_qspi_cmd { qspi_name opcode } {
    upvar #0 $qspi_name qspi

    qspi_drive_start
    qspi_${qspi(type)}_drive_opcode $opcode
    qspi_drive_stop
}

proc do_qspi_write { qspi_name opcode data } {
    upvar #0 $qspi_name qspi

    qspi_drive_start
    qspi_${qspi(type)}_drive_opcode $opcode
    qspi_drive_byte $data
    qspi_drive_stop
}

proc do_qspi_read_byte { qspi_name opcode } {
    upvar #0 $qspi_name qspi

    qspi_drive_start
    qspi_${qspi(type)}_drive_opcode $opcode
    qspi_capture_byte
    qspi_drive_stop
    return [mrw [::CMSDK_QSPI${::SX}::READ_DATA]]
}

proc qspi_write_disable { qspi_name } {
    do_qspi_cmd $qspi_name 0x04
}

proc qspi_write_enable { qspi_name } {
    do_qspi_cmd $qspi_name 0x06
}

proc qspi_read_flash_byte { qspi_name addr } {
    upvar #0 $qspi_name qspi

    qspi_drive_start
    qspi_${qspi(type)}_drive_opcode 0xeb
    qspi_drive_byte [expr {($addr >> 16) & 0xff}]
    qspi_drive_byte [expr {($addr >> 8) & 0xff}]
    qspi_drive_byte [expr {$addr & 0xff}]
    for {set i 0} {$i < $qspi(dummy)} {incr i} {
	qspi_drive_byte 0x00
    }
    qspi_capture_byte
    qspi_drive_stop
    return [mrw [::CMSDK_QSPI${::SX}::READ_DATA]]
}

proc qspi_read_flash_be { qspi_name addr {len 4} } {
    upvar #0 $qspi_name qspi

    qspi_drive_start
    qspi_${qspi(type)}_drive_opcode 0xeb
    qspi_drive_byte [expr {($addr >> 16) & 0xff}]
    qspi_drive_byte [expr {($addr >> 8) & 0xff}]
    qspi_drive_byte [expr {$addr & 0xff}]
    for {set i 0} {$i < $qspi(dummy)} {incr i} {
	qspi_drive_byte 0x00
    }
    set ret 0
    for {set i 0} {$i < $len} {incr i} {
	qspi_capture_byte
	set ret [expr {($ret << 8) | [mrw [::CMSDK_QSPI${::SX}::READ_DATA]]}]
    }
    qspi_drive_stop
    return $ret
}

proc qspi_read_flash_le { qspi_name addr {len 4} } {
    upvar #0 $qspi_name qspi

    qspi_drive_start
    qspi_${qspi(type)}_drive_opcode 0xeb
    qspi_drive_byte [expr {($addr >> 16) & 0xff}]
    qspi_drive_byte [expr {($addr >> 8) & 0xff}]
    qspi_drive_byte [expr {$addr & 0xff}]
    for {set i 0} {$i < $qspi(dummy)} {incr i} {
	qspi_drive_byte 0x00
    }
    set ret 0
    for {set i 0} {$i < $len} {incr i} {
	qspi_capture_byte
	set ret [expr {$ret | ([mrw [::CMSDK_QSPI${::SX}::READ_DATA]] << ($i*8))}]
    }
    qspi_drive_stop
    return $ret
}

proc qspi_fdb { qspi_name addr count } {
    set ret ""

    for {set i 0} {$i < $count} {incr i} {
	set ret [concat $ret [format " %02x" [qspi_read_flash_byte $qspi_name [expr {$addr+$i}]]]]
    }
    return $ret
}

proc qspi_reset { qspi_name } {
    do_qspi_cmd $qspi_name 0x66
    do_qspi_cmd $qspi_name 0x99
}

proc qspi_micron_read_status {} {
    return [do_qspi_read_byte QSPI_MICRON 0x05]
}

proc qspi_micron_wait_for_no_wip {} {
    while {1} {
	set ret [qspi_micron_read_status]
	if {($ret & 0x1) == 0x0} {
	    return $ret
	}
    }
}

proc qspi_micron_read_evcr {} {
    return [do_qspi_read_byte QSPI_MICRON 0x65]
}

proc qspi_micron_read_flag_status {} {
    return [do_qspi_read_byte QSPI_MICRON 0x70]
}

proc qspi_micron_read_flash_id {} {
    return [do_qspi_read_byte QSPI_MICRON 0xaf]
}

proc qspi_micron_bulk_erase { } {
    qspi_write_enable QSPI_MICRON

    qspi_drive_start
    qspi_micron_drive_opcode 0xc7
    qspi_drive_stop

    set status [qspi_micron_wait_for_no_wip]
    if {($status & 0x02) != 0x00} {
	error [format "Chip erase command FAILED!  Status Register 0x%02x" $status]
    }
    set flag_status [qspi_micron_read_flag_status]
    if {($flag_status & 0x20) != 0x00} {
	error [format "Chip erase FAILED!  Flag Status Register 0x%02x" $flag_status]
    }
}

proc qspi_micron_subsector_erase { addr } {
    qspi_write_enable QSPI_MICRON

    qspi_drive_start
    qspi_micron_drive_opcode 0x20
    qspi_drive_byte [expr {($addr >> 16) & 0xff}]
    qspi_drive_byte [expr {($addr >> 8) & 0xff}]
    qspi_drive_byte [expr {$addr & 0xff}]
    qspi_drive_stop

    set status [qspi_micron_wait_for_no_wip]
    if {($status & 0x02) != 0x00} {
	error [format "Sector 0x%06x erase command FAILED!  Status Register 0x%02x" $addr $status]
    }
    set flag_status [qspi_micron_read_flag_status]
    if {($flag_status & 0x20) != 0x00} {
	error [format "Sector 0x%06x erase FAILED!  Flag Status Register 0x%02x" $addr $flag_status]
    }
}

proc qspi_macronix_make_ahb {} {
    namespace eval ::CMSDK_QSPI${::SX}::REMOTE_AHB_SETUP {
	set REMOTE_AHB_SETUP [expr { \
	    [SKEW_CSN_ACT_WEN::MASK] | \
	    [ENABLE_CLOCKS::MASK] | \
	    [WDATA_WORD_SWAP::MASK] | \
	    [WDATA_HALFWORD_SWAP::MASK] | \
	    [QUAD_OVERHEAD::MASK] | \
	    [RDATA_BYTE_SWAP::MASK] | \
	    [CLKDIVSEL::WRITE 0] | \
	    [OPCODE::WRITE 0xeb] | \
	    [IS_OPCODE::MASK] | \
	    [MODE::WRITE 2] | \
	    [DUMMY_CYCLES::WRITE 4]}]
	if {![info exists ::env(NO_HYPER)]} {
	    enable_hpc
	    set REMOTE_AHB_SETUP [expr {$REMOTE_AHB_SETUP | [SLIP_HALF_CYCLE::MASK] | [HYPER::MASK]}]
	}
	mww [REG_ADDR] $REMOTE_AHB_SETUP
    }

    # READ STATUS REG, 4PP, WRITE ENABLE
    namespace eval ::CMSDK_QSPI${::SX}::REMOTE_AHB_SETUP_2 {
	mww [REG_ADDR] [expr { \
	    [OPCODE_SE::WRITE 0x00] | \
	    [OPCODE_WIP::WRITE 0x05] | \
	    [OPCODE_PP::WRITE 0x38] | \
	    [OPCODE_WE::WRITE 0x06]}]
    }

    namespace eval ::CMSDK_QSPI${::SX}::REMOTE_AHB_SETUP_3 {
	mww [REG_ADDR] [expr { \
	    [CHECK_WLE::MASK] | \
	    [WIP_BIT::WRITE 0] | \
	    [WIP_POLARITY::MASK] | \
	    [WLE_BIT::WRITE 1] | \
	    [WLE_POLARITY::MASK] | \
	    [ENABLE_PERFORMANCE_MODE::MASK] | \
	    [OPCODE_PERFORMANCE_MODE::WRITE 0x5a]}]
    }

    namespace eval ::CMSDK_QSPI${::SX}::REMOTE_AHB_SETUP_5 {
	mww [REG_ADDR] [expr { \
	    [STALL_WE2PP::WRITE 32] | \
	    [STALL_WLE::WRITE 32] | \
	    [PP_STALL_WIP::WRITE 1023]}]
    }

    namespace eval ::CMSDK_QSPI${::SX}::TRANSACTION_SETUP {
	mww [REG_ADDR] [expr { \
	    [REMOTE_AHB_QSPI_HAS_CONTROL::MASK] | \
	    [CSN_VAL::MASK]}]
    }

    adapter speed 75
}

proc qspi_giga_make_ahb {} {
    namespace eval ::CMSDK_QSPI${::SX}::REMOTE_AHB_SETUP {
	set REMOTE_AHB_SETUP [expr { \
	    [SKEW_CSN_ACT_WEN::MASK] | \
	    [SERIALIZE_PP_ADDRESS::MASK] | \
	    [ENABLE_CLOCKS::MASK] | \
	    [WDATA_WORD_SWAP::MASK] | \
	    [WDATA_HALFWORD_SWAP::MASK] | \
	    [QUAD_OVERHEAD::MASK] | \
	    [RDATA_BYTE_SWAP::MASK] | \
	    [CLKDIVSEL::WRITE 0] | \
	    [OPCODE::WRITE 0xeb] | \
	    [IS_OPCODE::MASK] | \
	    [MODE::WRITE 2] | \
	    [DUMMY_CYCLES::WRITE 4]}]
	if {![info exists ::env(NO_HYPER)]} {
	    enable_hpc
	    set REMOTE_AHB_SETUP [expr {$REMOTE_AHB_SETUP | [SLIP_HALF_CYCLE::MASK] | [HYPER::MASK]}]
	}
	mww [REG_ADDR] $REMOTE_AHB_SETUP
    }

    # READ STATUS REG, QIPP, WRITE ENABLE
    namespace eval ::CMSDK_QSPI${::SX}::REMOTE_AHB_SETUP_2 {
	mww [REG_ADDR] [expr { \
	    [OPCODE_SE::WRITE 0x00] | \
	    [OPCODE_WIP::WRITE 0x05] | \
	    [OPCODE_PP::WRITE 0x32] | \
	    [OPCODE_WE::WRITE 0x06]}]
    }

    namespace eval ::CMSDK_QSPI${::SX}::REMOTE_AHB_SETUP_3 {
	mww [REG_ADDR] [expr { \
	    [CHECK_WLE::MASK] | \
	    [WIP_BIT::WRITE 0] | \
	    [WIP_POLARITY::MASK] | \
	    [WLE_BIT::WRITE 1] | \
	    [WLE_POLARITY::MASK] | \
	    [ENABLE_PERFORMANCE_MODE::MASK] | \
	    [OPCODE_PERFORMANCE_MODE::WRITE 0xa0]}]
    }

    namespace eval ::CMSDK_QSPI${::SX}::REMOTE_AHB_SETUP_5 {
	mww [REG_ADDR] [expr { \
	    [STALL_WE2PP::WRITE 32] | \
	    [STALL_WLE::WRITE 32] | \
	    [PP_STALL_WIP::WRITE 1023]}]
    }

    namespace eval ::CMSDK_QSPI${::SX}::TRANSACTION_SETUP {
	mww [REG_ADDR] [expr { \
	    [REMOTE_AHB_QSPI_HAS_CONTROL::MASK] | \
	    [CSN_VAL::MASK]}]
    }

    adapter speed 75
}

proc qspi_giantec_make_ahb {} {
    namespace eval ::CMSDK_QSPI${::SX}::REMOTE_AHB_SETUP {
	set REMOTE_AHB_SETUP [expr { \
	    [SKEW_CSN_ACT_WEN::MASK] | \
	    [SERIALIZE_PP_ADDRESS::MASK] | \
	    [ENABLE_CLOCKS::MASK] | \
	    [WDATA_WORD_SWAP::MASK] | \
	    [WDATA_HALFWORD_SWAP::MASK] | \
	    [QUAD_OVERHEAD::MASK] | \
	    [RDATA_BYTE_SWAP::MASK] | \
	    [CLKDIVSEL::WRITE 0] | \
	    [OPCODE::WRITE 0xeb] | \
	    [IS_OPCODE::MASK] | \
	    [MODE::WRITE 2] | \
	    [DUMMY_CYCLES::WRITE 4]}]
	if {![info exists ::env(NO_HYPER)]} {
	    enable_hpc
	    set REMOTE_AHB_SETUP [expr {$REMOTE_AHB_SETUP | [SLIP_HALF_CYCLE::MASK] | [HYPER::MASK]}]
	}
	mww [REG_ADDR] $REMOTE_AHB_SETUP
    }

    # READ STATUS REG, QIPP, WRITE ENABLE
    namespace eval ::CMSDK_QSPI${::SX}::REMOTE_AHB_SETUP_2 {
	mww [REG_ADDR] [expr { \
	    [OPCODE_SE::WRITE 0x00] | \
	    [OPCODE_WIP::WRITE 0x05] | \
	    [OPCODE_PP::WRITE 0x32] | \
	    [OPCODE_WE::WRITE 0x06]}]
    }

    namespace eval ::CMSDK_QSPI${::SX}::REMOTE_AHB_SETUP_3 {
	mww [REG_ADDR] [expr { \
	    [CHECK_WLE::MASK] | \
	    [WIP_BIT::WRITE 0] | \
	    [WIP_POLARITY::MASK] | \
	    [WLE_BIT::WRITE 1] | \
	    [WLE_POLARITY::MASK] | \
	    [ENABLE_PERFORMANCE_MODE::MASK] | \
	    [OPCODE_PERFORMANCE_MODE::WRITE 0xa0]}]
    }

    namespace eval ::CMSDK_QSPI${::SX}::REMOTE_AHB_SETUP_5 {
	mww [REG_ADDR] [expr { \
	    [STALL_WE2PP::WRITE 32] | \
	    [STALL_WLE::WRITE 32] | \
	    [PP_STALL_WIP::WRITE 1023]}]
    }

    namespace eval ::CMSDK_QSPI${::SX}::TRANSACTION_SETUP {
	mww [REG_ADDR] [expr { \
	    [REMOTE_AHB_QSPI_HAS_CONTROL::MASK] | \
	    [CSN_VAL::MASK]}]
    }

    adapter speed 75
}

proc qspi_fudan_make_ahb {} {
    namespace eval ::CMSDK_QSPI${::SX}::REMOTE_AHB_SETUP {
	set REMOTE_AHB_SETUP [expr { \
	    [SKEW_CSN_ACT_WEN::MASK] | \
	    [SERIALIZE_PP_ADDRESS::MASK] | \
	    [ENABLE_CLOCKS::MASK] | \
	    [WDATA_WORD_SWAP::MASK] | \
	    [WDATA_HALFWORD_SWAP::MASK] | \
	    [QUAD_OVERHEAD::MASK] | \
	    [RDATA_BYTE_SWAP::MASK] | \
	    [CLKDIVSEL::WRITE 0] | \
	    [OPCODE::WRITE 0xeb] | \
	    [IS_OPCODE::MASK] | \
	    [MODE::WRITE 2] | \
	    [DUMMY_CYCLES::WRITE 4]}]
	if {![info exists ::env(NO_HYPER)]} {
	    enable_hpc
	    set REMOTE_AHB_SETUP [expr {$REMOTE_AHB_SETUP | [SLIP_HALF_CYCLE::MASK] | [HYPER::MASK]}]
	}
	mww [REG_ADDR] $REMOTE_AHB_SETUP
    }

    # READ STATUS REG, QIPP, WRITE ENABLE
    namespace eval ::CMSDK_QSPI${::SX}::REMOTE_AHB_SETUP_2 {
	mww [REG_ADDR] [expr { \
	    [OPCODE_SE::WRITE 0x00] | \
	    [OPCODE_WIP::WRITE 0x05] | \
	    [OPCODE_PP::WRITE 0x32] | \
	    [OPCODE_WE::WRITE 0x06]}]
    }

    namespace eval ::CMSDK_QSPI${::SX}::REMOTE_AHB_SETUP_3 {
	mww [REG_ADDR] [expr { \
	    [CHECK_WLE::MASK] | \
	    [WIP_BIT::WRITE 0] | \
	    [WIP_POLARITY::MASK] | \
	    [WLE_BIT::WRITE 1] | \
	    [WLE_POLARITY::MASK] | \
	    [ENABLE_PERFORMANCE_MODE::MASK] | \
	    [OPCODE_PERFORMANCE_MODE::WRITE 0xa0]}]
    }

    namespace eval ::CMSDK_QSPI${::SX}::REMOTE_AHB_SETUP_5 {
	mww [REG_ADDR] [expr { \
	    [STALL_WE2PP::WRITE 32] | \
	    [STALL_WLE::WRITE 32] | \
	    [PP_STALL_WIP::WRITE 1023]}]
    }

    namespace eval ::CMSDK_QSPI${::SX}::TRANSACTION_SETUP {
	mww [REG_ADDR] [expr { \
	    [REMOTE_AHB_QSPI_HAS_CONTROL::MASK] | \
	    [CSN_VAL::MASK]}]
    }

    adapter speed 75
}

proc qspi_puya_make_ahb {} {
    namespace eval ::CMSDK_QSPI${::SX}::REMOTE_AHB_SETUP {
	set REMOTE_AHB_SETUP [expr { \
	    [SKEW_CSN_ACT_WEN::MASK] | \
	    [SERIALIZE_PP_ADDRESS::MASK] | \
	    [ENABLE_CLOCKS::MASK] | \
	    [WDATA_WORD_SWAP::MASK] | \
	    [WDATA_HALFWORD_SWAP::MASK] | \
	    [QUAD_OVERHEAD::MASK] | \
	    [RDATA_BYTE_SWAP::MASK] | \
	    [CLKDIVSEL::WRITE 0] | \
	    [OPCODE::WRITE 0xeb] | \
	    [IS_OPCODE::MASK] | \
	    [MODE::WRITE 2] | \
	    [DUMMY_CYCLES::WRITE 4]}]
	if {![info exists ::env(NO_HYPER)]} {
	    enable_hpc
	    set REMOTE_AHB_SETUP [expr {$REMOTE_AHB_SETUP | [SLIP_HALF_CYCLE::MASK] | [HYPER::MASK]}]
	}
	mww [REG_ADDR] $REMOTE_AHB_SETUP
    }

    # READ STATUS REG, QIPP, WRITE ENABLE
    namespace eval ::CMSDK_QSPI${::SX}::REMOTE_AHB_SETUP_2 {
	mww [REG_ADDR] [expr { \
	    [OPCODE_SE::WRITE 0x00] | \
	    [OPCODE_WIP::WRITE 0x05] | \
	    [OPCODE_PP::WRITE 0x32] | \
	    [OPCODE_WE::WRITE 0x06]}]
    }

    namespace eval ::CMSDK_QSPI${::SX}::REMOTE_AHB_SETUP_3 {
	mww [REG_ADDR] [expr { \
	    [CHECK_WLE::MASK] | \
	    [WIP_BIT::WRITE 0] | \
	    [WIP_POLARITY::MASK] | \
	    [WLE_BIT::WRITE 1] | \
	    [WLE_POLARITY::MASK] | \
	    [ENABLE_PERFORMANCE_MODE::MASK] | \
	    [OPCODE_PERFORMANCE_MODE::WRITE 0xa0]}]
    }

    namespace eval ::CMSDK_QSPI${::SX}::REMOTE_AHB_SETUP_5 {
	mww [REG_ADDR] [expr { \
	    [STALL_WE2PP::WRITE 32] | \
	    [STALL_WLE::WRITE 32] | \
	    [PP_STALL_WIP::WRITE 1023]}]
    }

    namespace eval ::CMSDK_QSPI${::SX}::TRANSACTION_SETUP {
	mww [REG_ADDR] [expr { \
	    [REMOTE_AHB_QSPI_HAS_CONTROL::MASK] | \
	    [CSN_VAL::MASK]}]
    }

    adapter speed 5
}

proc qspi_winbond_make_ahb {} {
    namespace eval ::CMSDK_QSPI${::SX}::REMOTE_AHB_SETUP {
	set REMOTE_AHB_SETUP [expr { \
	    [SKEW_CSN_ACT_WEN::MASK] | \
	    [SERIALIZE_PP_ADDRESS::MASK] | \
	    [ENABLE_CLOCKS::MASK] | \
	    [WDATA_WORD_SWAP::MASK] | \
	    [WDATA_HALFWORD_SWAP::MASK] | \
	    [QUAD_OVERHEAD::MASK] | \
	    [RDATA_BYTE_SWAP::MASK] | \
	    [CLKDIVSEL::WRITE 0] | \
	    [OPCODE::WRITE 0xeb] | \
	    [IS_OPCODE::MASK] | \
	    [MODE::WRITE 2] | \
	    [DUMMY_CYCLES::WRITE 4]}]
	if {![info exists ::env(NO_HYPER)]} {
	    enable_hpc
	    set REMOTE_AHB_SETUP [expr {$REMOTE_AHB_SETUP | [SLIP_HALF_CYCLE::MASK] | [HYPER::MASK]}]
	}
	mww [REG_ADDR] $REMOTE_AHB_SETUP
    }

    # READ STATUS REG, QIPP, WRITE ENABLE
    namespace eval ::CMSDK_QSPI${::SX}::REMOTE_AHB_SETUP_2 {
	mww [REG_ADDR] [expr { \
	    [OPCODE_SE::WRITE 0x00] | \
	    [OPCODE_WIP::WRITE 0x05] | \
	    [OPCODE_PP::WRITE 0x32] | \
	    [OPCODE_WE::WRITE 0x06]}]
    }

    namespace eval ::CMSDK_QSPI${::SX}::REMOTE_AHB_SETUP_3 {
	mww [REG_ADDR] [expr { \
	    [CHECK_WLE::MASK] | \
	    [WIP_BIT::WRITE 0] | \
	    [WIP_POLARITY::MASK] | \
	    [WLE_BIT::WRITE 1] | \
	    [WLE_POLARITY::MASK]}]
    }

    namespace eval ::CMSDK_QSPI${::SX}::REMOTE_AHB_SETUP_5 {
	mww [REG_ADDR] [expr { \
	    [STALL_WE2PP::WRITE 32] | \
	    [STALL_WLE::WRITE 32] | \
	    [PP_STALL_WIP::WRITE 1023]}]
    }

    namespace eval ::CMSDK_QSPI${::SX}::TRANSACTION_SETUP {
	mww [REG_ADDR] [expr { \
	    [REMOTE_AHB_QSPI_HAS_CONTROL::MASK] | \
	    [CSN_VAL::MASK]}]
    }

    adapter speed 75
}

proc qspi_micron_make_ahb {} {
    qspi_write_enable QSPI_MICRON
    # WRITE VOLATILE CONFIG REG
    do_qspi_write QSPI_MICRON 0x81 0x2b

    namespace eval ::CMSDK_QSPI${::SX}::REMOTE_AHB_SETUP {
	set REMOTE_AHB_SETUP [expr { \
	    [SKEW_CSN_ACT_WEN::MASK] | \
	    [ENABLE_CLOCKS::MASK] | \
	    [WDATA_WORD_SWAP::MASK] | \
	    [WDATA_HALFWORD_SWAP::MASK] | \
	    [RDATA_BYTE_SWAP::MASK] | \
	    [CLKDIVSEL::WRITE 0] | \
	    [OPCODE::WRITE 0xeb] | \
	    [IS_OPCODE::MASK] | \
	    [MODE::WRITE 2] | \
	    [DUMMY_CYCLES::WRITE 1]}]
	if {![info exists ::env(NO_HYPER)]} {
	    enable_hpc
	    set REMOTE_AHB_SETUP [expr {$REMOTE_AHB_SETUP | [SLIP_HALF_CYCLE::MASK] | [HYPER::MASK]}]
	}
	mww [REG_ADDR] $REMOTE_AHB_SETUP
    }

    # READ STATUS REG, PAGE PROGRAM, WRITE ENABLE
    namespace eval ::CMSDK_QSPI${::SX}::REMOTE_AHB_SETUP_2 {
	mww [REG_ADDR] [expr { \
	    [OPCODE_SE::WRITE 0x00] | \
	    [OPCODE_WIP::WRITE 0x05] | \
	    [OPCODE_PP::WRITE 0x02] | \
	    [OPCODE_WE::WRITE 0x06]}]
    }

    namespace eval ::CMSDK_QSPI${::SX}::REMOTE_AHB_SETUP_3 {
	mww [REG_ADDR] [expr { \
	    [CHECK_WLE::MASK] | \
	    [WIP_BIT::WRITE 0] | \
	    [WIP_POLARITY::MASK] | \
	    [WLE_BIT::WRITE 1] | \
	    [WLE_POLARITY::MASK]}]
    }

    namespace eval ::CMSDK_QSPI${::SX}::REMOTE_AHB_SETUP_5 {
	mww [REG_ADDR] [expr { \
	    [STALL_WE2PP::WRITE 32] | \
	    [STALL_WLE::WRITE 32] | \
	    [PP_STALL_WIP::WRITE 1023]}]
    }

    namespace eval ::CMSDK_QSPI${::SX}::TRANSACTION_SETUP {
	mww [REG_ADDR] [expr { \
	    [REMOTE_AHB_QSPI_HAS_CONTROL::MASK] | \
	    [CSN_VAL::MASK]}]
    }

    adapter speed 75
}

proc qspi_disable_ahb {} {
    namespace eval ::CMSDK_QSPI${::SX}::TRANSACTION_SETUP {
	mww [REG_ADDR] [CSN_VAL::MASK]
    }
    if {![info exists ::env(NO_HYPER)]} {
	disable_hpc
    }
}

proc qspi_micron_make_spi {} {
    qspi_write_enable QSPI_MICRON
    # WRITE VOLATILE CONFIG REG
    do_qspi_write QSPI_MICRON 0x81 0xfb

    set evcr [qspi_micron_read_evcr]
    qspi_write_enable QSPI_MICRON
    # WRITE ENHANCED VOLATILE CONFIG REG
    do_qspi_write QSPI_MICRON 0x61 [expr {$evcr | 0xd0}]
}


#
# Flash procs
#

proc check_flash_mem_cap { maker mem_cap region_end } {
    set byte_size [expr {1 << $mem_cap}]
    puts [format "%s %uMb flash (%u bytes)" $maker [expr {1 << ($mem_cap - 17)}] $byte_size]
    if {!$region_end} {
	return $byte_size
    }
    if {$byte_size >= $region_end} {
	return $byte_size
    }
    error [format "Check FLASH_SIZE setting: region_end 0x%x too large for flash device size 0x%x" $region_end $byte_size]
}

proc atm_discover_flash { {region_end 0x0} } {
    setup_pkg_config

    for {set i 0} {$i < 2} {incr i} {
	set id [spi_read_flash_id SPI2 3]
	#puts [format "flash id 0x%06x" $id]
	set flash_id [expr {$id & 0xffff}]
	set mem_cap [expr {$id >> 16}]
	if {$flash_id == 0x28c2} {
	    set flash_size [check_flash_mem_cap "Macronix" $mem_cap $region_end]
	    return [list "macronix" $flash_size $mem_cap]
	} elseif {$flash_id == 0x65c8} {
	    set flash_size [check_flash_mem_cap "GigaDevice" $mem_cap $region_end]
	    return [list "giga" $flash_size $mem_cap]
	} elseif {($flash_id == 0x40c4) || ($flash_id == 0x60c4)} {
	    set flash_size [check_flash_mem_cap "Giantec" $mem_cap $region_end]
	    return [list "giantec" $flash_size $mem_cap]
	} elseif {$flash_id == 0x28a1} {
	    set flash_size [check_flash_mem_cap "Fudan" $mem_cap $region_end]
	    return [list "fudan" $flash_size $mem_cap]
	} elseif {($flash_id == 0x4085) || ($flash_id == 0x6085)} {
	    set flash_size [check_flash_mem_cap "Puya" $mem_cap $region_end]
	    return [list "puya" $flash_size $mem_cap]
	} elseif {$flash_id == 0x60ef} {
	    set flash_size [check_flash_mem_cap "Winbond" $mem_cap $region_end]
	    return [list "winbond" $flash_size $mem_cap]
	} elseif {$flash_id == 0xba20} {
	    set flash_size [check_flash_mem_cap "Micron" $mem_cap $region_end]
	    return [list "micron" $flash_size $mem_cap]
	} else {
	    # Might have been in deep power down or performance enhanced mode
	    spi_macronix_exit_deep_power_down SPI2

	    # Might be a micron in qspi mode
	    enable_qspi
	    atm_micron_qspi_2_spi
	}
    }
    error [format "Unknown flash 0x%06x" $id]
}

proc atm_macronix_enable_ahb_bridge {} {
    spi_macronix_make_quad SPI2
    if {([spi_read_status SPI2] & 0x40) == 0x00} {
	error "Failed to set QE"
    }
    enable_qspi
    qspi_macronix_make_ahb
    return "Macronix OK"
}

proc atm_giga_enable_ahb_bridge {} {
    if {([spi_read_status SPI2 0x35] & 0x02) == 0x00} {
	spi_giga_make_quad SPI2
	if {([spi_read_status SPI2 0x35] & 0x02) == 0x00} {
	    error "Failed to set QE"
	}
    }
    enable_qspi
    qspi_giga_make_ahb
    return "Giga OK"
}

proc atm_giantec_enable_ahb_bridge {} {
    if {([spi_read_status SPI2 0x35] & 0x02) == 0x00} {
	spi_giantec_make_quad SPI2
	if {([spi_read_status SPI2 0x35] & 0x02) == 0x00} {
	    error "Failed to set QE"
	}
    }
    enable_qspi
    qspi_giantec_make_ahb
    return "Giantec OK"
}

proc atm_fudan_enable_ahb_bridge {} {
    if {([spi_read_status SPI2 0x35] & 0x02) == 0x00} {
	spi_fudan_make_quad SPI2
	if {([spi_read_status SPI2 0x35] & 0x02) == 0x00} {
	    error "Failed to set QE"
	}
    }
    enable_qspi
    qspi_fudan_make_ahb
    return "Fudan OK"
}

proc atm_puya_enable_ahb_bridge {} {
    if {([spi_read_status SPI2 0x35] & 0x02) == 0x00} {
	spi_puya_make_quad SPI2
	if {([spi_read_status SPI2 0x35] & 0x02) == 0x00} {
	    error "Failed to set QE"
	}
    }
    enable_qspi
    qspi_puya_make_ahb
    return "Puya OK"
}

proc atm_winbond_enable_ahb_bridge {} {
    if {([spi_read_status SPI2 0x35] & 0x02) == 0x00} {
	spi_winbond_make_quad SPI2
	if {([spi_read_status SPI2 0x35] & 0x02) == 0x00} {
	    error "Failed to set QE"
	}
    }
    enable_qspi
    qspi_winbond_make_ahb
    return "Winbond OK"
}

proc atm_micron_enable_ahb_bridge {} {
    spi_micron_make_quad SPI2
    enable_qspi
    if {[qspi_micron_read_flash_id] != 0x20} {
	error "Failed to read qspi flash id"
    }
    qspi_micron_make_ahb
    return "Micron OK"
}

proc atm_enable_ahb_bridge {} {
    enable_spi2
    lassign [atm_discover_flash] flash size

    atm_${flash}_enable_ahb_bridge
}

proc atm_disable_ahb_bridge {} {
    adapter speed $::_SWD_KHZ
    qspi_disable_ahb
}

proc atm_macronix_qspi_2_spi {} {
    reset_qspi
}

proc atm_giga_qspi_2_spi {} {
    reset_qspi
}

proc atm_giantec_qspi_2_spi {} {
    reset_qspi
}

proc atm_fudan_qspi_2_spi {} {
    reset_qspi
}

proc atm_puya_qspi_2_spi {} {
    reset_qspi
}

proc atm_winbond_qspi_2_spi {} {
    reset_qspi
}

proc atm_micron_qspi_2_spi {} {
    qspi_micron_make_spi
    reset_qspi
}

proc atm_macronix_ahb_2_spi {} {
    atm_disable_ahb_bridge
    atm_macronix_qspi_2_spi
}

proc atm_giga_ahb_2_spi {} {
    atm_disable_ahb_bridge
    atm_giga_qspi_2_spi
}

proc atm_giantec_ahb_2_spi {} {
    atm_disable_ahb_bridge
    atm_giantec_qspi_2_spi
}

proc atm_fudan_ahb_2_spi {} {
    atm_disable_ahb_bridge
    atm_fudan_qspi_2_spi
}

proc atm_puya_ahb_2_spi {} {
    atm_disable_ahb_bridge
    atm_puya_qspi_2_spi
}

proc atm_winbond_ahb_2_spi {} {
    atm_disable_ahb_bridge
    atm_winbond_qspi_2_spi
}

proc atm_micron_ahb_2_spi {} {
    atm_disable_ahb_bridge
    atm_micron_qspi_2_spi
}

proc atm_macronix_erase_whole { } {
    spi_macronix_make_quad SPI2
    if {([spi_read_status SPI2] & 0x40) == 0x00} {
	error "Failed to set QE"
    }
    spi_macronix_chip_erase SPI2
    enable_qspi
}

proc atm_macronix_erase { start end } {
    spi_macronix_make_quad SPI2
    if {([spi_read_status SPI2] & 0x40) == 0x00} {
	error "Failed to set QE"
    }
    for {set i $start} {$i < $end} {set i [expr {$i + 0x1000}]} {
	spi_macronix_sector_erase SPI2 $i
    }
    enable_qspi
}

proc atm_giga_erase_whole { } {
    if {([spi_read_status SPI2 0x35] & 0x02) == 0x00} {
	spi_giga_make_quad SPI2
	if {([spi_read_status SPI2 0x35] & 0x02) == 0x00} {
	    error "Failed to set QE"
	}
    }
    spi_winbond_chip_erase SPI2
    enable_qspi
}

proc atm_giga_erase { start end } {
    if {([spi_read_status SPI2 0x35] & 0x02) == 0x00} {
	spi_giga_make_quad SPI2
	if {([spi_read_status SPI2 0x35] & 0x02) == 0x00} {
	    error "Failed to set QE"
	}
    }
    for {set i $start} {$i < $end} {set i [expr {$i + 0x1000}]} {
	spi_winbond_sector_erase SPI2 $i
    }
    enable_qspi
}

proc atm_giantec_erase_whole { } {
    if {([spi_read_status SPI2 0x35] & 0x02) == 0x00} {
	spi_giantec_make_quad SPI2
	if {([spi_read_status SPI2 0x35] & 0x02) == 0x00} {
	    error "Failed to set QE"
	}
    }
    spi_winbond_chip_erase SPI2
    enable_qspi
}

proc atm_giantec_erase { start end } {
    if {([spi_read_status SPI2 0x35] & 0x02) == 0x00} {
	spi_giantec_make_quad SPI2
	if {([spi_read_status SPI2 0x35] & 0x02) == 0x00} {
	    error "Failed to set QE"
	}
    }
    for {set i $start} {$i < $end} {set i [expr {$i + 0x1000}]} {
	spi_winbond_sector_erase SPI2 $i
    }
    enable_qspi
}

proc atm_fudan_erase_whole { } {
    if {([spi_read_status SPI2 0x35] & 0x02) == 0x00} {
	spi_fudan_make_quad SPI2
	if {([spi_read_status SPI2 0x35] & 0x02) == 0x00} {
	    error "Failed to set QE"
	}
    }
    spi_winbond_chip_erase SPI2
    enable_qspi
}

proc atm_fudan_erase { start end } {
    if {([spi_read_status SPI2 0x35] & 0x02) == 0x00} {
	spi_fudan_make_quad SPI2
	if {([spi_read_status SPI2 0x35] & 0x02) == 0x00} {
	    error "Failed to set QE"
	}
    }
    for {set i $start} {$i < $end} {set i [expr {$i + 0x1000}]} {
	spi_winbond_sector_erase SPI2 $i
    }
    enable_qspi
}

proc atm_puya_erase_whole { } {
    if {([spi_read_status SPI2 0x35] & 0x02) == 0x00} {
	spi_puya_make_quad SPI2
	if {([spi_read_status SPI2 0x35] & 0x02) == 0x00} {
	    error "Failed to set QE"
	}
    }
    spi_winbond_chip_erase SPI2
    enable_qspi
}

proc atm_puya_erase { start end } {
    if {([spi_read_status SPI2 0x35] & 0x02) == 0x00} {
	spi_puya_make_quad SPI2
	if {([spi_read_status SPI2 0x35] & 0x02) == 0x00} {
	    error "Failed to set QE"
	}
    }
    for {set i $start} {$i < $end} {set i [expr {$i + 0x1000}]} {
	spi_winbond_sector_erase SPI2 $i
    }
    enable_qspi
}

proc atm_winbond_erase_whole { } {
    if {([spi_read_status SPI2 0x35] & 0x02) == 0x00} {
	spi_winbond_make_quad SPI2
	if {([spi_read_status SPI2 0x35] & 0x02) == 0x00} {
	    error "Failed to set QE"
	}
    }
    spi_winbond_chip_erase SPI2
    enable_qspi
}

proc atm_winbond_erase { start end } {
    if {([spi_read_status SPI2 0x35] & 0x02) == 0x00} {
	spi_winbond_make_quad SPI2
	if {([spi_read_status SPI2 0x35] & 0x02) == 0x00} {
	    error "Failed to set QE"
	}
    }
    for {set i $start} {$i < $end} {set i [expr {$i + 0x1000}]} {
	spi_winbond_sector_erase SPI2 $i
    }
    enable_qspi
}

proc atm_winbond_protect_flash { {mpr_lock_size 0} } {
    puts [format "atm_winbond_protect_flash: mpr_lock_size = 0x%x" $mpr_lock_size]

    set status_reg 0
    if {$mpr_lock_size == 0} {
	puts "disable protection"
    } elseif {$mpr_lock_size == 0x1000} {
	puts "protect - 4KB (07F000 - 07FFFF)"
	# WRITE STATUS REG - SEC, TB, BP2, BP1, BP0 [1,0,0,0,1]
	set status_reg 0x44
    } elseif {$mpr_lock_size == 0x2000} {
	puts "protect - 8KB (07E000 - 07FFFF)"
	# WRITE STATUS REG - SEC, TB, BP2, BP1, BP0 [1,0,0,1,0]
	set status_reg 0x48
    } elseif {$mpr_lock_size == 0x4000} {
	puts "protect - 16KB (07C000 - 07FFFF)"
	# WRITE STATUS REG - SEC, TB, BP2, BP1, BP0 [1,0,0,1,1]
	set status_reg 0x4c
    } elseif {$mpr_lock_size == 0x8000} {
	puts "protect - 32KB (078000 - 07FFFF)"
	# WRITE STATUS REG - SEC, TB, BP2, BP1, BP0 [1,0,1,1,0]
	set status_reg 0x58
    } else {
	error "Protection size not supported."
    }
    return $status_reg
}

proc atm_micron_erase_whole { } {
    spi_micron_make_quad SPI2
    enable_qspi
    if {[qspi_micron_read_flash_id] != 0x20} {
	error "Failed to read qspi flash id"
    }
    qspi_micron_bulk_erase
}

proc atm_micron_erase { start end } {
    spi_micron_make_quad SPI2
    enable_qspi
    if {[qspi_micron_read_flash_id] != 0x20} {
	error "Failed to read qspi flash id"
    }
    for {set i $start} {$i < $end} {set i [expr {$i + 0x1000}]} {
	qspi_micron_subsector_erase $i
    }
}

proc atm_erase_upgd_data {flash size} {
    set part_offset [expr {$size / 2}]
    set end [expr {$part_offset + 0x1000}]
    puts [format "Erasing upgd sector at 0x%08x to 0x%08x " $part_offset $end]
    atm_${flash}_erase $part_offset $end
}

proc atm_macronix_dump_otp { image {len 8192} } {
    reset halt
    enable_spi2
    set flash [atm_discover_flash]
    if {$flash != "macronix"} {
	error [format "Wrong flash type: %s" $flash]
    }

    set scur [spi_macronix_read_scur SPI2]
    puts [format "Security Register 0x%02x" $scur]

    spi_macronix_enter_secured_otp SPI2

    atm_${flash}_enable_ahb_bridge

    dump_image $image $::CMSDK_FLASH_BASE $len

    atm_${flash}_ahb_2_spi

    spi_macronix_exit_secured_otp SPI2
}

proc atm_erase_flash {{len 0x78000} {start_off 0x0}} {
    reset halt
    enable_spi2
    lassign [atm_discover_flash $len] flash size

    if {[info exists ::env(ERASE_WHOLE)]} {
	puts [format "Erasing whole device"]
	atm_${flash}_erase_whole
    } else {
	if { [expr {$start_off % 0x1000}] != 0} {
	    error "Must Erase along a sector boundary! [expr {$start_off % 0x1000}]"
	}
	puts [format "Erasing flash @0x%x, len=0x%x" $start_off $len]
	atm_${flash}_erase $start_off $len
	if {[info exists ::env(ERASE_UPGRADE_DATA)]} {
	    atm_erase_upgd_data $flash $size
	}
    }

    atm_${flash}_qspi_2_spi
    return "OK"
}

proc atm_flash_size { } {
    reset halt
    enable_spi2
    lassign [atm_discover_flash] flash size

    return $size
}

proc atm_dump_flash [list image [list len 0x78000] [list start_addr $::CMSDK_FLASH_BASE]] {
    reset halt
    enable_spi2
    lassign [atm_discover_flash $len] flash size

    # Dump entire flash for len == 0
    if {!$len} {
	set len $size
    }

    atm_${flash}_enable_ahb_bridge

    dump_image $image $start_addr $len

    atm_${flash}_ahb_2_spi
}

proc atm_load_flash { image {region_start 0x0} {region_size 0x78000} {address ""} } {
    reset halt
    enable_spi2
    puts "Loading [file tail $image] into FLASH"
    set region_end [expr {$region_start + $region_size}]
    lassign [atm_discover_flash $region_end] flash size

    if {[info exists ::env(ERASE_WHOLE)]} {
	puts [format "Erasing whole device"]
	atm_${flash}_erase_whole
    } else {
	atm_${flash}_erase $region_start $region_end
	if {[info exists ::env(ERASE_UPGRADE_DATA)]} {
	    atm_erase_upgd_data $flash $size
	}
    }

    qspi_${flash}_make_ahb

    if {$address == ""} {
	puts -nonewline [load_image $image]
    } else {
	puts -nonewline [load_image $image $address]
    }

    atm_${flash}_ahb_2_spi
    spi_wait_for_no_wip SPI2
}

proc atm_verify_flash { image {address ""} } {
    reset halt
    enable_spi2
    lassign [atm_discover_flash] flash size

    atm_${flash}_enable_ahb_bridge

    if {$address == ""} {
	puts -nonewline [verify_image $image]
    } else {
	puts -nonewline [verify_image $image $address]
    }

    atm_${flash}_ahb_2_spi
}

proc atm_protect_flash { {mpr_lock_size 0} } {
    reset halt
    enable_spi2
    lassign [atm_discover_flash] flash size
    set id [spi_read_flash_id SPI2 3]
    if { $id != 0x1360ef} {
	puts [format "flash id 0x%06x" $id]
	error "Not a W25Q40EW part"
    }

    set cur_status [spi_read_status SPI2]
    puts [format "atm_protect_flash: current status register1 = 0x%02x" $cur_status]

    set write_status [atm_${flash}_protect_flash $mpr_lock_size]

    if { $cur_status == $write_status } {
	puts [format "Not update status register"]
	return $cur_status
    }

    spi_write_enable SPI2
    do_spi_transaction SPI2 0 0x01 1 0x0 $write_status
    while {1} {
	set ret [spi_read_status SPI2]
	if {($ret & $write_status) == $write_status} {
	    return $ret
	}
    }
}

proc atm_erase_flash_nvds { region_start region_size } {
    reset halt
    enable_spi2
    set region_end [expr {$region_start + $region_size}]
    lassign [atm_discover_flash $region_end] flash size

    atm_${flash}_erase $region_start $region_end

    atm_${flash}_qspi_2_spi
    return "OK"
}

proc return_winning_seq { seq0 seq1 mem_cap } {
    set seq [expr {$seq0 + 1}]
    set seq0 [expr {$seq & 0x0f}]
    if {$seq0 == $seq1} {
        return 1
    } else {
        return 0
    }
}

proc id_is_valid { upgrade_status } {
    set FLASH_UPGRADE_STATUS_ID_MASK 0xffffff00
    set FLASH_UPGRADE_STATUS_ID_ROM 0x4d4f5200
    set FLASH_UPGRADE_STATUS_ID_USR 0x52535500
    set id [expr {$upgrade_status & $FLASH_UPGRADE_STATUS_ID_MASK}]
    set id_rom [expr {$id == $FLASH_UPGRADE_STATUS_ID_ROM}]
    set id_usr [expr {$id == $FLASH_UPGRADE_STATUS_ID_USR}]
    set ret [expr {$id_rom || $id_usr}]
    puts "$id $id_rom $id_usr $ret\n"
    return $ret
}

proc status_is_all_good { upgrade_status } {
    set FLASH_UPGRADE_STATUS_STATE_MASK 0x0f
    set FLASH_UPGRADE_STATUS_nBAD_MASK 0x08
    set FLASH_UPGRADE_STATUS_nBOOTED_MASK 0x04
    set upgd_status_mask [expr {$upgrade_status & $FLASH_UPGRADE_STATUS_STATE_MASK}]
    set bad_booted_mask [expr {$FLASH_UPGRADE_STATUS_nBAD_MASK | $FLASH_UPGRADE_STATUS_nBOOTED_MASK}]
    set ret [expr {$upgd_status_mask != $bad_booted_mask}]
    return $ret
}

proc atm_get_active_bank_addr { region_start region_size mem_bank mem_cap } {
    set FLASH_START_ADDR $::CMSDK_FLASH_BASE
    set FLASH_UPGRADE_STATUS_WOFF 0x10
    set FLASH_UPGRADE_STATUS_SEQ_MASK 0xf0
    set active_standby_flag 0

    set bank_off [expr {1 << ($mem_cap-3)}]
    #convert $bank_off to byte address
    set bank_off [expr {$bank_off*4}]

    if {$mem_bank=="active"} {
        puts "$mem_bank\n"
        set active_standby_flag 0
    } elseif {$mem_bank=="standby"} {
        puts "$mem_bank\n"
        set active_standby_flag 1
    } elseif {$mem_bank=="bank0"} {
        puts "Bank 0\n"
        return $FLASH_START_ADDR
    } elseif {$mem_bank=="bank1"} {
        puts "Bank 1\n"
        return [expr {$FLASH_START_ADDR + $bank_off}]
    } else {
        error "$mem_bank is not a valid MEM_BANK value. Allowed values 'active', 'standby', 'bank0', or 'bank1'"
    }

    set b0_us_addr [expr {$FLASH_START_ADDR + $FLASH_UPGRADE_STATUS_WOFF}]
    set b1_us_addr [expr {$FLASH_START_ADDR + $FLASH_UPGRADE_STATUS_WOFF + $bank_off}]
    puts "bank_off $bank_off\nb0 $b0_us_addr\nb1 $b1_us_addr\n"
    set region_end [expr {$region_start + $region_size}]
    set b0_us [mrw $b0_us_addr]
    set b1_us [mrw $b1_us_addr]
    puts "mem_cap $mem_cap\nb0_us $b0_us\nb1_us $b1_us\n"
    set b0 [id_is_valid $b0_us]
    set b1 [id_is_valid $b1_us]

    if {$b0} {
        set b0 [status_is_all_good $b0_us]
    }

    if {$b1} {
        set b1 [status_is_all_good $b1_us]
    }

    #map winning sequence if both b0 and b1 pass
    if {$b0 && $b1} {
        set b0_seq_mask [expr { $b0_us & $FLASH_UPGRADE_STATUS_SEQ_MASK} ]
        set b1_seq_mask [expr { $b1_us & $FLASH_UPGRADE_STATUS_SEQ_MASK} ]
        set b0_seq [expr { $b0_seq_mask >> 4 } ]
        set b1_seq [expr { $b1_seq_mask >> 4 } ]
        set b1 [return_winning_seq $b0_seq $b1_seq $mem_cap]
    }
    puts "b0 b1 $b0 $b1\n"
    #if bank 1 is not active, default to bank 0
    if {$b1} {
        if {$active_standby_flag == 0} {
            return [expr {$FLASH_START_ADDR + $bank_off}]
        } else {
            return $FLASH_START_ADDR
        }

    } else {
        if {$active_standby_flag == 0} {
            return $FLASH_START_ADDR
        } else {
            return [expr {$FLASH_START_ADDR + $bank_off}]
        }
    }
}

proc atm_dump_flash_nvds { image region_start region_size mem_bank } {
    reset halt
    enable_spi2
    set region_end [expr {$region_start + $region_size}]
    lassign [atm_discover_flash $region_end] flash size mem_cap

    atm_${flash}_enable_ahb_bridge

    set active_bank_addr [atm_get_active_bank_addr $region_start $region_size $mem_bank $mem_cap]
    puts "Returned bank address is $active_bank_addr\n"
    dump_image $image [expr {$active_bank_addr + $region_start}] $region_size

    atm_${flash}_ahb_2_spi
}

proc atm_load_flash_nvds { image region_start region_size } {
    reset halt
    enable_spi2
    set region_end [expr {$region_start + $region_size}]
    lassign [atm_discover_flash $region_end] flash size

    atm_${flash}_erase $region_start $region_end

    qspi_${flash}_make_ahb

    puts -nonewline [load_image $image [expr {$::CMSDK_FLASH_BASE + $region_start}]]

    atm_${flash}_ahb_2_spi
    spi_wait_for_no_wip SPI2
}

proc atm_verify_flash_nvds { image region_start region_size } {
    reset halt
    enable_spi2
    set region_end [expr {$region_start + $region_size}]
    lassign [atm_discover_flash $region_end] flash size

    atm_${flash}_enable_ahb_bridge

    puts -nonewline [verify_image $image [expr {$::CMSDK_FLASH_BASE + $region_start}]]

    atm_${flash}_ahb_2_spi
}
