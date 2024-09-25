#
# atm2x_flash.tcl
# Production APIs for flash operations
# Copyright (C) Atmosic 2018-2022
#

#
# SPI
#

array set SPI0 {
    clkdiv	3
    dummy	0
}
set SPI0(base)			$CMSDK_SPI0_BASE
set SPI0(TRANSACTION_SETUP)	[expr {$CMSDK_SPI0_TRANSACTION_SETUP}]
set SPI0(TRANSACTION_STATUS)	[expr {$CMSDK_SPI0_TRANSACTION_STATUS}]
set SPI0(DATA_BYTES_LOWER)	[expr {$CMSDK_SPI0_DATA_BYTES_LOWER}]
set SPI0(DATA_BYTES_UPPER)	[expr {$CMSDK_SPI0_DATA_BYTES_UPPER}]
set SPI0(INTERRUPT_MASK)	[expr {$CMSDK_SPI0_INTERRUPT_MASK}]
set SPI0(INTERRUPT_STATUS)	[expr {$CMSDK_SPI0_INTERRUPT_STATUS}]
set SPI0(SET_INTERRUPT)		[expr {$CMSDK_SPI0_SET_INTERRUPT}]
set SPI0(RESET_INTERRUPT)	[expr {$CMSDK_SPI0_RESET_INTERRUPT}]
set SPI0(CORE_ID)		[expr {$CMSDK_SPI0_CORE_ID}]

array set SPI1 {
    clkdiv	3
    dummy	0
}
set SPI1(base)			$CMSDK_SPI1_BASE
set SPI1(TRANSACTION_SETUP)	[expr {$CMSDK_SPI1_TRANSACTION_SETUP}]
set SPI1(TRANSACTION_STATUS)	[expr {$CMSDK_SPI1_TRANSACTION_STATUS}]
set SPI1(DATA_BYTES_LOWER)	[expr {$CMSDK_SPI1_DATA_BYTES_LOWER}]
set SPI1(DATA_BYTES_UPPER)	[expr {$CMSDK_SPI1_DATA_BYTES_UPPER}]
set SPI1(INTERRUPT_MASK)	[expr {$CMSDK_SPI1_INTERRUPT_MASK}]
set SPI1(INTERRUPT_STATUS)	[expr {$CMSDK_SPI1_INTERRUPT_STATUS}]
set SPI1(SET_INTERRUPT)		[expr {$CMSDK_SPI1_SET_INTERRUPT}]
set SPI1(RESET_INTERRUPT)	[expr {$CMSDK_SPI1_RESET_INTERRUPT}]
set SPI1(CORE_ID)		[expr {$CMSDK_SPI1_CORE_ID}]

array set SPI2 {
    clkdiv	3
    dummy	0
}
set SPI2(base)			$CMSDK_SPI2_BASE
set SPI2(TRANSACTION_SETUP)	[expr {$CMSDK_SPI2_TRANSACTION_SETUP}]
set SPI2(TRANSACTION_STATUS)	[expr {$CMSDK_SPI2_TRANSACTION_STATUS}]
set SPI2(DATA_BYTES_LOWER)	[expr {$CMSDK_SPI2_DATA_BYTES_LOWER}]
set SPI2(DATA_BYTES_UPPER)	[expr {$CMSDK_SPI2_DATA_BYTES_UPPER}]
set SPI2(INTERRUPT_MASK)	[expr {$CMSDK_SPI2_INTERRUPT_MASK}]
set SPI2(INTERRUPT_STATUS)	[expr {$CMSDK_SPI2_INTERRUPT_STATUS}]
set SPI2(SET_INTERRUPT)		[expr {$CMSDK_SPI2_SET_INTERRUPT}]
set SPI2(RESET_INTERRUPT)	[expr {$CMSDK_SPI2_RESET_INTERRUPT}]
set SPI2(CORE_ID)		[expr {$CMSDK_SPI2_CORE_ID}]

array set RADIO {
    clkdiv	0
    dummy	3
}
set RADIO(base)			$CMSDK_RADIO_BASE
set RADIO(TRANSACTION_SETUP)	[expr {$CMSDK_RADIO_TRANSACTION_SETUP}]
set RADIO(TRANSACTION_STATUS)	[expr {$CMSDK_RADIO_TRANSACTION_STATUS}]
set RADIO(DATA_BYTES_LOWER)	[expr {$CMSDK_RADIO_DATA_BYTES_LOWER}]
set RADIO(DATA_BYTES_UPPER)	[expr {$CMSDK_RADIO_DATA_BYTES_UPPER}]
set RADIO(INTERRUPT_MASK)	[expr {$CMSDK_RADIO_INTERRUPT_MASK}]
set RADIO(INTERRUPT_STATUS)	[expr {$CMSDK_RADIO_INTERRUPT_STATUS}]
set RADIO(SET_INTERRUPT)	[expr {$CMSDK_RADIO_SET_INTERRUPT}]
set RADIO(RESET_INTERRUPT)	[expr {$CMSDK_RADIO_RESET_INTERRUPT}]
set RADIO(CORE_ID)		[expr {$CMSDK_RADIO_CORE_ID}]

array set PMU {
    clkdiv	0
    dummy	3
}
set PMU(base)			$CMSDK_PMU_BASE
set PMU(TRANSACTION_SETUP)	[expr {$CMSDK_PMU_TRANSACTION_SETUP}]
set PMU(TRANSACTION_STATUS)	[expr {$CMSDK_PMU_TRANSACTION_STATUS}]
set PMU(DATA_BYTES_LOWER)	[expr {$CMSDK_PMU_DATA_BYTES_LOWER}]
set PMU(DATA_BYTES_UPPER)	[expr {$CMSDK_PMU_DATA_BYTES_UPPER}]
set PMU(INTERRUPT_MASK)		[expr {$CMSDK_PMU_INTERRUPT_MASK}]
set PMU(INTERRUPT_STATUS)	[expr {$CMSDK_PMU_INTERRUPT_STATUS}]
set PMU(SET_INTERRUPT)		[expr {$CMSDK_PMU_SET_INTERRUPT}]
set PMU(RESET_INTERRUPT)	[expr {$CMSDK_PMU_RESET_INTERRUPT}]
set PMU(CORE_ID)		[expr {$CMSDK_PMU_CORE_ID}]


proc do_spi_transaction { spi_name csn_stays_low opcode num_data_bytes upper lower } {
    upvar #0 $spi_name spi
    set transaction [expr {($spi(dummy) << 26) | ($csn_stays_low << 25) | ($opcode << 16) | ($spi(clkdiv) << 6) | (0x00000020) | ($num_data_bytes << 1)}]

    mww $spi(DATA_BYTES_LOWER) $lower
    mww $spi(DATA_BYTES_UPPER) $upper
    mww $spi(TRANSACTION_SETUP) $transaction
    mww $spi(TRANSACTION_SETUP) [expr {$transaction | 0x00000001}]

    while {([mrw $spi(TRANSACTION_STATUS)] & 0x00000002) == 0x00000002} {}
}

proc do_spi_read { spi_name opcode {len 1} } {
    upvar #0 $spi_name spi
    do_spi_transaction $spi_name 0 $opcode $len 0x0 0x0
    return [mrw $spi(DATA_BYTES_LOWER)]
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
    return [expr {[mrw $spi(DATA_BYTES_LOWER)] >> 24}]
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
    set lower [mrw $spi(DATA_BYTES_LOWER)]
    set upper [mrw $spi(DATA_BYTES_UPPER)]
    return [flash_upper_lower_to_be_word $upper $lower]
}

proc spi_read_flash_le_word { spi_name addr } {
    upvar #0 $spi_name spi

    do_spi_transaction $spi_name 0 0x03 7 0x0 [flash_lower_from_addr $addr]
    set lower [mrw $spi(DATA_BYTES_LOWER)]
    set upper [mrw $spi(DATA_BYTES_UPPER)]
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
    set lower [mrw $spi(DATA_BYTES_LOWER)]
    set upper [mrw $spi(DATA_BYTES_UPPER)]
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
    global CMSDK_QSPI_TRANSACTION_SETUP

    mww $CMSDK_QSPI_TRANSACTION_SETUP 0x02000000
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
    global CMSDK_QSPI_TRANSACTION_SETUP

    set oe [expr {[to_oe_format_quad $nibble] << 8}]
    mww $CMSDK_QSPI_TRANSACTION_SETUP $oe
    mww $CMSDK_QSPI_TRANSACTION_SETUP [expr {0x01000000 | $oe}]
}

proc qspi_drive_byte { byte } {
    qspi_drive_nibble [expr {($byte & 0xf0) >> 4}]
    qspi_drive_nibble [expr {$byte & 0x0f}]
}

proc qspi_micron_drive_opcode { opcode } {
    qspi_drive_byte $opcode
}

proc qspi_macronix_drive_opcode { opcode } {
    global CMSDK_QSPI_TRANSACTION_SETUP

    for {set i 0} {$i < 8} {incr i} {
	set opcode [expr {$opcode << 1}]
	set drive [expr {($opcode & 0x100) | 0x200}]
	mww $CMSDK_QSPI_TRANSACTION_SETUP $drive
	mww $CMSDK_QSPI_TRANSACTION_SETUP [expr {0x01000000 | $drive}]
    }
}

proc qspi_winbond_drive_opcode { opcode } {
    global CMSDK_QSPI_TRANSACTION_SETUP

    for {set i 0} {$i < 8} {incr i} {
	set opcode [expr {$opcode << 1}]
	set drive [expr {($opcode & 0x100) | 0x200}]
	mww $CMSDK_QSPI_TRANSACTION_SETUP $drive
	mww $CMSDK_QSPI_TRANSACTION_SETUP [expr {0x01000000 | $drive}]
    }
}

proc qspi_capture_byte {} {
    global CMSDK_QSPI_TRANSACTION_SETUP

    mww $CMSDK_QSPI_TRANSACTION_SETUP 0
    mww $CMSDK_QSPI_TRANSACTION_SETUP 0x01000000
    mww $CMSDK_QSPI_TRANSACTION_SETUP 0x010000f0

    mww $CMSDK_QSPI_TRANSACTION_SETUP 0
    mww $CMSDK_QSPI_TRANSACTION_SETUP 0x01000000
    mww $CMSDK_QSPI_TRANSACTION_SETUP 0x0100000f
}

proc qspi_drive_stop {} {
    global CMSDK_QSPI_TRANSACTION_SETUP

    mww $CMSDK_QSPI_TRANSACTION_SETUP 0
    mww $CMSDK_QSPI_TRANSACTION_SETUP 0x02000000
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
    global CMSDK_QSPI_READ_DATA

    qspi_drive_start
    qspi_${qspi(type)}_drive_opcode $opcode
    qspi_capture_byte
    qspi_drive_stop
    return [mrw $CMSDK_QSPI_READ_DATA]
}

proc qspi_write_disable { qspi_name } {
    do_qspi_cmd $qspi_name 0x04
}

proc qspi_write_enable { qspi_name } {
    do_qspi_cmd $qspi_name 0x06
}

proc qspi_read_flash_byte { qspi_name addr } {
    upvar #0 $qspi_name qspi
    global CMSDK_QSPI_READ_DATA

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
    return [mrw $CMSDK_QSPI_READ_DATA]
}

proc qspi_read_flash_be { qspi_name addr {len 4} } {
    upvar #0 $qspi_name qspi
    global CMSDK_QSPI_READ_DATA

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
	set ret [expr {($ret << 8) | [mrw $CMSDK_QSPI_READ_DATA]}]
    }
    qspi_drive_stop
    return $ret
}

proc qspi_read_flash_le { qspi_name addr {len 4} } {
    upvar #0 $qspi_name qspi
    global CMSDK_QSPI_READ_DATA

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
	set ret [expr {$ret | ([mrw $CMSDK_QSPI_READ_DATA] << ($i*8))}]
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
    global CMSDK_QSPI_TRANSACTION_SETUP
    global CMSDK_QSPI_REMOTE_AHB_SETUP
    global CMSDK_QSPI_REMOTE_AHB_SETUP_2
    global CMSDK_QSPI_REMOTE_AHB_SETUP_3
    global CMSDK_QSPI_REMOTE_AHB_SETUP_5

    # Byte swaps, macronix, div by 1, opcode 0xeb, mode 2, dummy 4
    set REMOTE_AHB_SETUP 0x10eceb64
    if {![info exists ::env(NO_HYPER)]} {
	enable_hpc
	# Slip half cycle, hyper
	set REMOTE_AHB_SETUP [expr {$REMOTE_AHB_SETUP | 0x60000000}]
    }
    mww $CMSDK_QSPI_REMOTE_AHB_SETUP $REMOTE_AHB_SETUP
    # READ STATUS REG, 4PP, WRITE ENABLE
    mww $CMSDK_QSPI_REMOTE_AHB_SETUP_2 0x00053806
    # Check wle, wip bit 0+, wle bit 1+
    mww $CMSDK_QSPI_REMOTE_AHB_SETUP_3 0x81300000
    # Stall: WE2PP 32, WLE 32, PP WIP 1023
    mww $CMSDK_QSPI_REMOTE_AHB_SETUP_5 0x020083ff
    # Give AHB control
    mww $CMSDK_QSPI_TRANSACTION_SETUP 0x12000000

    adapter speed 75
}

proc qspi_giga_make_ahb {} {
    global CMSDK_QSPI_TRANSACTION_SETUP
    global CMSDK_QSPI_REMOTE_AHB_SETUP
    global CMSDK_QSPI_REMOTE_AHB_SETUP_2
    global CMSDK_QSPI_REMOTE_AHB_SETUP_3
    global CMSDK_QSPI_REMOTE_AHB_SETUP_5

    # Serial PP addr, swaps, macronix, div by 1, opcode 0xeb, mode 2, dummy 4
    set REMOTE_AHB_SETUP 0x18eceb64
    if {![info exists ::env(NO_HYPER)]} {
	enable_hpc
	# Slip half cycle, hyper
	set REMOTE_AHB_SETUP [expr {$REMOTE_AHB_SETUP | 0x60000000}]
    }
    mww $CMSDK_QSPI_REMOTE_AHB_SETUP $REMOTE_AHB_SETUP
    # READ STATUS REG, QIPP, WRITE ENABLE
    mww $CMSDK_QSPI_REMOTE_AHB_SETUP_2 0x00053206
    # Check wle, wip bit 0+, wle bit 1+
    mww $CMSDK_QSPI_REMOTE_AHB_SETUP_3 0x81300000
    # Stall: WE2PP 32, WLE 32, PP WIP 1023
    mww $CMSDK_QSPI_REMOTE_AHB_SETUP_5 0x020083ff
    # Give AHB control
    mww $CMSDK_QSPI_TRANSACTION_SETUP 0x12000000

    adapter speed 75
}

proc qspi_giantec_make_ahb {} {
    global CMSDK_QSPI_TRANSACTION_SETUP
    global CMSDK_QSPI_REMOTE_AHB_SETUP
    global CMSDK_QSPI_REMOTE_AHB_SETUP_2
    global CMSDK_QSPI_REMOTE_AHB_SETUP_3
    global CMSDK_QSPI_REMOTE_AHB_SETUP_5

    # Serial PP addr, swaps, macronix, div by 1, opcode 0xeb, mode 2, dummy 4
    set REMOTE_AHB_SETUP 0x18eceb64
    if {![info exists ::env(NO_HYPER)]} {
	enable_hpc
	# Slip half cycle, hyper
	set REMOTE_AHB_SETUP [expr {$REMOTE_AHB_SETUP | 0x60000000}]
    }
    mww $CMSDK_QSPI_REMOTE_AHB_SETUP $REMOTE_AHB_SETUP
    # READ STATUS REG, QIPP, WRITE ENABLE
    mww $CMSDK_QSPI_REMOTE_AHB_SETUP_2 0x00053206
    # Check wle, wip bit 0+, wle bit 1+
    mww $CMSDK_QSPI_REMOTE_AHB_SETUP_3 0x81300000
    # Stall: WE2PP 32, WLE 32, PP WIP 1023
    mww $CMSDK_QSPI_REMOTE_AHB_SETUP_5 0x020083ff
    # Give AHB control
    mww $CMSDK_QSPI_TRANSACTION_SETUP 0x12000000

    adapter speed 75
}

proc qspi_fudan_make_ahb {} {
    global CMSDK_QSPI_TRANSACTION_SETUP
    global CMSDK_QSPI_REMOTE_AHB_SETUP
    global CMSDK_QSPI_REMOTE_AHB_SETUP_2
    global CMSDK_QSPI_REMOTE_AHB_SETUP_3
    global CMSDK_QSPI_REMOTE_AHB_SETUP_5

    # Serial PP addr, swaps, macronix, div by 1, opcode 0xeb, mode 2, dummy 4
    set REMOTE_AHB_SETUP 0x18eceb64
    if {![info exists ::env(NO_HYPER)]} {
	enable_hpc
	# Slip half cycle, hyper
	set REMOTE_AHB_SETUP [expr {$REMOTE_AHB_SETUP | 0x60000000}]
    }
    mww $CMSDK_QSPI_REMOTE_AHB_SETUP $REMOTE_AHB_SETUP
    # READ STATUS REG, QIPP, WRITE ENABLE
    mww $CMSDK_QSPI_REMOTE_AHB_SETUP_2 0x00053206
    # Check wle, wip bit 0+, wle bit 1+
    mww $CMSDK_QSPI_REMOTE_AHB_SETUP_3 0x81300000
    # Stall: WE2PP 32, WLE 32, PP WIP 1023
    mww $CMSDK_QSPI_REMOTE_AHB_SETUP_5 0x020083ff
    # Give AHB control
    mww $CMSDK_QSPI_TRANSACTION_SETUP 0x12000000

    adapter speed 75
}

proc qspi_puya_make_ahb {} {
    global CMSDK_QSPI_TRANSACTION_SETUP
    global CMSDK_QSPI_REMOTE_AHB_SETUP
    global CMSDK_QSPI_REMOTE_AHB_SETUP_2
    global CMSDK_QSPI_REMOTE_AHB_SETUP_3
    global CMSDK_QSPI_REMOTE_AHB_SETUP_5

    # Serial PP addr, swaps, macronix, div by 1, opcode 0xeb, mode 2, dummy 4
    set REMOTE_AHB_SETUP 0x18eceb64
    if {![info exists ::env(NO_HYPER)]} {
	enable_hpc
	# Slip half cycle, hyper
	set REMOTE_AHB_SETUP [expr {$REMOTE_AHB_SETUP | 0x60000000}]
    }
    mww $CMSDK_QSPI_REMOTE_AHB_SETUP $REMOTE_AHB_SETUP
    # READ STATUS REG, QIPP, WRITE ENABLE
    mww $CMSDK_QSPI_REMOTE_AHB_SETUP_2 0x00053206
    # Check wle, wip bit 0+, wle bit 1+
    mww $CMSDK_QSPI_REMOTE_AHB_SETUP_3 0x81300000
    # Stall: WE2PP 32, WLE 32, PP WIP 1023
    mww $CMSDK_QSPI_REMOTE_AHB_SETUP_5 0x020083ff
    # Give AHB control
    mww $CMSDK_QSPI_TRANSACTION_SETUP 0x12000000

    adapter speed 5
}

proc qspi_winbond_make_ahb {} {
    global CMSDK_QSPI_TRANSACTION_SETUP
    global CMSDK_QSPI_REMOTE_AHB_SETUP
    global CMSDK_QSPI_REMOTE_AHB_SETUP_2
    global CMSDK_QSPI_REMOTE_AHB_SETUP_3
    global CMSDK_QSPI_REMOTE_AHB_SETUP_5

    # Serial PP addr, swaps, macronix, div by 1, opcode 0xeb, mode 2, dummy 4
    set REMOTE_AHB_SETUP 0x18eceb64
    if {![info exists ::env(NO_HYPER)]} {
	enable_hpc
	# Slip half cycle, hyper
	set REMOTE_AHB_SETUP [expr {$REMOTE_AHB_SETUP | 0x60000000}]
    }
    mww $CMSDK_QSPI_REMOTE_AHB_SETUP $REMOTE_AHB_SETUP
    # READ STATUS REG, QIPP, WRITE ENABLE
    mww $CMSDK_QSPI_REMOTE_AHB_SETUP_2 0x00053206
    # Check wle, wip bit 0+, wle bit 1+
    mww $CMSDK_QSPI_REMOTE_AHB_SETUP_3 0x81300000
    # Stall: WE2PP 32, WLE 32, PP WIP 1023
    mww $CMSDK_QSPI_REMOTE_AHB_SETUP_5 0x020083ff
    # Give AHB control
    mww $CMSDK_QSPI_TRANSACTION_SETUP 0x12000000

    adapter speed 75
}

proc qspi_micron_make_ahb {} {
    global CMSDK_QSPI_TRANSACTION_SETUP
    global CMSDK_QSPI_REMOTE_AHB_SETUP
    global CMSDK_QSPI_REMOTE_AHB_SETUP_2

    qspi_write_enable QSPI_MICRON
    # WRITE VOLATILE CONFIG REG
    do_qspi_write QSPI_MICRON 0x81 0x2b

    # Byte swaps, div by 1, opcode 0xeb, mode 2, dummy 2
    set REMOTE_AHB_SETUP 0x10e4eb62
    if {![info exists ::env(NO_HYPER)]} {
	enable_hpc
	# Slip half cycle, hyper
	set REMOTE_AHB_SETUP [expr {$REMOTE_AHB_SETUP | 0x60000000}]
    }
    mww $CMSDK_QSPI_REMOTE_AHB_SETUP $REMOTE_AHB_SETUP
    # READ STATUS REG, PAGE PROGRAM, WRITE ENABLE
    mww $CMSDK_QSPI_REMOTE_AHB_SETUP_2 0x00050206
    # Give AHB control
    mww $CMSDK_QSPI_TRANSACTION_SETUP 0x12000000

    adapter speed 75
}

proc qspi_disable_ahb {} {
    global CMSDK_QSPI_TRANSACTION_SETUP

    mww $CMSDK_QSPI_TRANSACTION_SETUP 0x02000000
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
# Sydney procs
#

proc sydney_setup_5x5 {} {
    global CMSDK_WRPR_PIN_SELECTION_C
    global CMSDK_WRPR_PIN_SELECTION_D
    global CMSDK_WRPR_PIN_SELECTION_E

    mww $CMSDK_WRPR_PIN_SELECTION_C 0x003fff84
    mww $CMSDK_WRPR_PIN_SELECTION_D 0x19120528
    mww $CMSDK_WRPR_PIN_SELECTION_E 0x50000000
}

proc sydney_setup_5x5_stacked {} {
    global CMSDK_WRPR_PIN_SELECTION_A
    global CMSDK_WRPR_PIN_SELECTION_B
    global CMSDK_WRPR_PIN_SELECTION_C
    global CMSDK_WRPR_PIN_SELECTION_D

    mww $CMSDK_WRPR_PIN_SELECTION_A 0x0000052c
    mww $CMSDK_WRPR_PIN_SELECTION_B 0x6b400000
    mww $CMSDK_WRPR_PIN_SELECTION_C 0x003fff84
    mww $CMSDK_WRPR_PIN_SELECTION_D 0x18000000
}

proc sydney_print_part_number { nvm_efuse_autoread } {
    set pkg [expr {$nvm_efuse_autoread & 0x08}]
    set stacked [expr {$nvm_efuse_autoread & 0x10}]
    set non_harv [expr {$nvm_efuse_autoread & 0x100}]
    set csp [expr {$nvm_efuse_autoread & 0x2000}]
    set pkg_7x7 [expr {$nvm_efuse_autoread & 0x4000}]

    puts [format "ATM%d2%d%d-x1x silicon: %s pkg, %s" \
	[expr {$non_harv ? 2 : 3}] \
	[expr {$pkg ? [expr {$csp ? 5 : 0}] : [expr {$pkg_7x7 ? 3 : 2}]}] \
	[expr {$stacked ? 2 : 1}] \
	[expr {$pkg ? [expr {$csp ? "CSP" : "5x5"}] : [expr {$pkg_7x7 ? "7x7" : "6x6"}]}] \
	[expr {$stacked ? "Stacked flash" : "External flash"}]]
}

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

proc sydney_discover_flash { {region_end 0x0} } {
    global CMSDK_NVM_EFUSE_AUTOREAD

    enable_nvm
    set nvm_EFUSE_AUTOREAD [mrw $CMSDK_NVM_EFUSE_AUTOREAD]
    set pkg_opts [expr {$nvm_EFUSE_AUTOREAD & 0x18}]
    if {$pkg_opts == 0x08} {
	sydney_setup_5x5
    } elseif {$pkg_opts == 0x18} {
	sydney_setup_5x5_stacked
    }
    sydney_print_part_number $nvm_EFUSE_AUTOREAD

    for {set i 0} {$i < 2} {incr i} {
	set id [spi_read_flash_id SPI2 3]
#	puts [format "flash id 0x%06x" $id]
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
	    sydney_micron_qspi_2_spi
	}
    }
    error [format "Unknown flash 0x%06x" $id]
}

proc sydney_macronix_enable_ahb_bridge {} {
    spi_macronix_make_quad SPI2
    if {([spi_read_status SPI2] & 0x40) == 0x00} {
	error "Failed to set QE"
    }
    enable_qspi
    qspi_macronix_make_ahb
    return "Macronix OK"
}

proc sydney_giga_enable_ahb_bridge {} {
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

proc sydney_giantec_enable_ahb_bridge {} {
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

proc sydney_fudan_enable_ahb_bridge {} {
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

proc sydney_puya_enable_ahb_bridge {} {
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

proc sydney_winbond_enable_ahb_bridge {} {
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

proc sydney_micron_enable_ahb_bridge {} {
    spi_micron_make_quad SPI2
    enable_qspi
    if {[qspi_micron_read_flash_id] != 0x20} {
	error "Failed to read qspi flash id"
    }
    qspi_micron_make_ahb
    return "Micron OK"
}

proc sydney_enable_ahb_bridge {} {
    enable_spi2
    lassign [sydney_discover_flash] flash size

    sydney_${flash}_enable_ahb_bridge
}

proc sydney_disable_ahb_bridge {} {
    global _SWD_KHZ

    adapter speed $_SWD_KHZ
    qspi_disable_ahb
}

proc sydney_macronix_qspi_2_spi {} {
    reset_qspi
}

proc sydney_giga_qspi_2_spi {} {
    reset_qspi
}

proc sydney_giantec_qspi_2_spi {} {
    reset_qspi
}

proc sydney_fudan_qspi_2_spi {} {
    reset_qspi
}

proc sydney_puya_qspi_2_spi {} {
    reset_qspi
}

proc sydney_winbond_qspi_2_spi {} {
    reset_qspi
}

proc sydney_micron_qspi_2_spi {} {
    qspi_micron_make_spi
    reset_qspi
}

proc sydney_macronix_ahb_2_spi {} {
    sydney_disable_ahb_bridge
    sydney_macronix_qspi_2_spi
}

proc sydney_giga_ahb_2_spi {} {
    sydney_disable_ahb_bridge
    sydney_giga_qspi_2_spi
}

proc sydney_giantec_ahb_2_spi {} {
    sydney_disable_ahb_bridge
    sydney_giantec_qspi_2_spi
}

proc sydney_fudan_ahb_2_spi {} {
    sydney_disable_ahb_bridge
    sydney_fudan_qspi_2_spi
}

proc sydney_puya_ahb_2_spi {} {
    sydney_disable_ahb_bridge
    sydney_puya_qspi_2_spi
}

proc sydney_winbond_ahb_2_spi {} {
    sydney_disable_ahb_bridge
    sydney_winbond_qspi_2_spi
}

proc sydney_micron_ahb_2_spi {} {
    sydney_disable_ahb_bridge
    sydney_micron_qspi_2_spi
}

proc sydney_macronix_erase_whole { } {
    spi_macronix_make_quad SPI2
    if {([spi_read_status SPI2] & 0x40) == 0x00} {
	error "Failed to set QE"
    }
    spi_macronix_chip_erase SPI2
    enable_qspi
}

proc sydney_macronix_erase { start end } {
    spi_macronix_make_quad SPI2
    if {([spi_read_status SPI2] & 0x40) == 0x00} {
	error "Failed to set QE"
    }
    for {set i $start} {$i < $end} {set i [expr {$i + 0x1000}]} {
	spi_macronix_sector_erase SPI2 $i
    }
    enable_qspi
}

proc sydney_giga_erase_whole { } {
    if {([spi_read_status SPI2 0x35] & 0x02) == 0x00} {
	spi_giga_make_quad SPI2
	if {([spi_read_status SPI2 0x35] & 0x02) == 0x00} {
	    error "Failed to set QE"
	}
    }
    spi_winbond_chip_erase SPI2
    enable_qspi
}

proc sydney_giga_erase { start end } {
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

proc sydney_giantec_erase_whole { } {
    if {([spi_read_status SPI2 0x35] & 0x02) == 0x00} {
	spi_giantec_make_quad SPI2
	if {([spi_read_status SPI2 0x35] & 0x02) == 0x00} {
	    error "Failed to set QE"
	}
    }
    spi_winbond_chip_erase SPI2
    enable_qspi
}

proc sydney_giantec_erase { start end } {
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

proc sydney_fudan_erase_whole { } {
    if {([spi_read_status SPI2 0x35] & 0x02) == 0x00} {
	spi_fudan_make_quad SPI2
	if {([spi_read_status SPI2 0x35] & 0x02) == 0x00} {
	    error "Failed to set QE"
	}
    }
    spi_winbond_chip_erase SPI2
    enable_qspi
}

proc sydney_fudan_erase { start end } {
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

proc sydney_puya_erase_whole { } {
    if {([spi_read_status SPI2 0x35] & 0x02) == 0x00} {
	spi_puya_make_quad SPI2
	if {([spi_read_status SPI2 0x35] & 0x02) == 0x00} {
	    error "Failed to set QE"
	}
    }
    spi_winbond_chip_erase SPI2
    enable_qspi
}

proc sydney_puya_erase { start end } {
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

proc sydney_winbond_erase_whole { } {
    if {([spi_read_status SPI2 0x35] & 0x02) == 0x00} {
	spi_winbond_make_quad SPI2
	if {([spi_read_status SPI2 0x35] & 0x02) == 0x00} {
	    error "Failed to set QE"
	}
    }
    spi_winbond_chip_erase SPI2
    enable_qspi
}

proc sydney_winbond_erase { start end } {
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

proc sydney_winbond_protect_flash { {mpr_lock_size 0} } {
    puts [format "sydney_winbond_protect_flash: mpr_lock_size = 0x%x" $mpr_lock_size]

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

proc sydney_micron_erase_whole { } {
    spi_micron_make_quad SPI2
    enable_qspi
    if {[qspi_micron_read_flash_id] != 0x20} {
	error "Failed to read qspi flash id"
    }
    qspi_micron_bulk_erase
}

proc sydney_micron_erase { start end } {
    spi_micron_make_quad SPI2
    enable_qspi
    if {[qspi_micron_read_flash_id] != 0x20} {
	error "Failed to read qspi flash id"
    }
    for {set i $start} {$i < $end} {set i [expr {$i + 0x1000}]} {
	qspi_micron_subsector_erase $i
    }
}

proc sydney_macronix_dump_otp { image {len 8192} } {
    reset halt
    enable_spi2
    lassign [sydney_discover_flash] flash size
    if {$flash != "macronix"} {
	error [format "Wrong flash type: %s" $flash]
    }

    set scur [spi_macronix_read_scur SPI2]
    puts [format "Security Register 0x%02x" $scur]

    spi_macronix_enter_secured_otp SPI2

    sydney_${flash}_enable_ahb_bridge

    dump_image $image 0x10000000 $len

    sydney_${flash}_ahb_2_spi

    spi_macronix_exit_secured_otp SPI2
}

proc sydney_erase_upgd_data {flash size} {
    set part_offset [expr {$size / 2}]
    set end [expr {$part_offset + 0x1000}]
    puts [format "Erasing upgd sector at 0x%08x to 0x%08x " $part_offset $end]
    sydney_${flash}_erase $part_offset $end
}

proc sydney_erase_flash { {len 0x78000} } {
    reset halt
    enable_spi2
    lassign [sydney_discover_flash $len] flash size

    if {[info exists ::env(ERASE_WHOLE)]} {
	puts [format "Erasing whole device"]
	sydney_${flash}_erase_whole
    } else {
	sydney_${flash}_erase 0x00000 $len
	if {[info exists ::env(ERASE_UPGRADE_DATA)]} {
	    sydney_erase_upgd_data $flash $size
	}
    }

    sydney_${flash}_qspi_2_spi
    return "OK"
}

proc sydney_flash_size { } {
    reset halt
    enable_spi2
    lassign [sydney_discover_flash] flash size

    return $size
}

proc sydney_dump_flash { image {len 0x78000} } {
    reset halt
    enable_spi2
    lassign [sydney_discover_flash $len] flash size

    # Dump entire flash for len == 0
    if {!$len} {
	set len $size
    }

    sydney_${flash}_enable_ahb_bridge

    dump_image $image 0x10000000 $len

    sydney_${flash}_ahb_2_spi
}

proc sydney_load_flash { image {region_start 0x0} {region_size 0x78000} {address ""} } {
    reset halt
    enable_spi2
    set region_end [expr {$region_start + $region_size}]
    lassign [sydney_discover_flash $region_end] flash size

    if {[info exists ::env(ERASE_WHOLE)]} {
	puts [format "Erasing whole device"]
	sydney_${flash}_erase_whole
    } else {
	sydney_${flash}_erase $region_start $region_end
	if {[info exists ::env(ERASE_UPGRADE_DATA)]} {
	    sydney_erase_upgd_data $flash $size
	}
    }

    qspi_${flash}_make_ahb

    if {$address == ""} {
	puts -nonewline [load_image $image]
    } else {
	puts -nonewline [load_image $image $address]
    }

    sydney_${flash}_ahb_2_spi
    spi_wait_for_no_wip SPI2
}

proc sydney_verify_flash { image {address ""} } {
    reset halt
    enable_spi2
    lassign [sydney_discover_flash] flash size

    sydney_${flash}_enable_ahb_bridge

    if {$address == ""} {
	puts -nonewline [verify_image $image]
    } else {
	puts -nonewline [verify_image $image $address]
    }

    sydney_${flash}_ahb_2_spi
}

proc sydney_protect_flash { {mpr_lock_size 0} } {
    reset halt
    enable_spi2
    lassign [sydney_discover_flash] flash size
    set id [spi_read_flash_id SPI2 3]
    if { $id != 0x1360ef} {
	puts [format "flash id 0x%06x" $id]
	error "Not a W25Q40EW part"
    }

    set cur_status [spi_read_status SPI2]
    puts [format "sydney_protect_flash: current status register1 = 0x%02x" $cur_status]

    set write_status [sydney_${flash}_protect_flash $mpr_lock_size]

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

proc sydney_erase_flash_nvds { region_start region_size } {
    reset halt
    enable_spi2
    set region_end [expr {$region_start + $region_size}]
    lassign [sydney_discover_flash $region_end] flash size

    sydney_${flash}_erase $region_start $region_end

    sydney_${flash}_qspi_2_spi
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

proc sydney_get_active_bank_addr { region_start region_size mem_bank mem_cap } {
    set FLASH_START_ADDR 0x10000000
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

proc sydney_dump_flash_nvds { image region_start region_size mem_bank } {
    reset halt
    enable_spi2
    set region_end [expr {$region_start + $region_size}]
    lassign [sydney_discover_flash $region_end] flash size mem_cap

    sydney_${flash}_enable_ahb_bridge

    set active_bank_addr [sydney_get_active_bank_addr $region_start $region_size $mem_bank $mem_cap]
    puts "Returned bank address is $active_bank_addr\n"
    dump_image $image [expr {$active_bank_addr + $region_start}] $region_size

    sydney_${flash}_ahb_2_spi
}

proc sydney_load_flash_nvds { image region_start region_size } {
    reset halt
    enable_spi2
    set region_end [expr {$region_start + $region_size}]
    lassign [sydney_discover_flash $region_end] flash size

    sydney_${flash}_erase $region_start $region_end

    qspi_${flash}_make_ahb

    puts -nonewline [load_image $image [expr {0x10000000 + $region_start}]]

    sydney_${flash}_ahb_2_spi
    spi_wait_for_no_wip SPI2
}

proc sydney_verify_flash_nvds { image region_start region_size } {
    reset halt
    enable_spi2
    set region_end [expr {$region_start + $region_size}]
    lassign [sydney_discover_flash $region_end] flash size

    sydney_${flash}_enable_ahb_bridge

    puts -nonewline [verify_image $image [expr {0x10000000 + $region_start}]]

    sydney_${flash}_ahb_2_spi
}
