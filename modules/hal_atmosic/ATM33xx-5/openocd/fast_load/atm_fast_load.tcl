#
# atm_fast_load.tcl
#
# Production APIs for fast_load operations
# Copyright (C) Atmosic 2023-2024
#

# The address offset of share memory
set FL_RAM_MAGIC0_OFS 0
set FL_RAM_MAGIC1_OFS 4
set FL_RAM_VER_OFS 8
set FL_RAM_FLASH_TYPE_OFS 10
set FL_RAM_PROC_TIME_OFS 11
set FL_RAM_KICK_PROG_OFS 12

# The opcode of FLASH/RRAM operation
set FL_RAM_OP_FW_LOAD 0x01
set FL_RAM_OP_ERASE 0x02
set FL_RAM_OP_VERIFY 0x04

proc fl_ram_program_page { fn } {
    if {[info exists ::env(DEBUG)]} {
	puts "<fast_load> program sector ..."
    }

    halt

    global _FL_RAM_PLATFORM
    if { $_FL_RAM_PLATFORM == "ATM22xx-x0x" ||
	$_FL_RAM_PLATFORM == "ATM22xx-x1x" } {
	bp 0x2f8 2 hw
	resume; sleep 1 busy; wait_halt
	rbp 0x2f8
    }

    resume $fn
}

proc fl_ram_get_program_wait_timeout { opcode flash_type} {
    global _FL_RAM_BLOCK_INFO
    global FL_RAM_VER_OFS
    set fl_ram_block_info $_FL_RAM_BLOCK_INFO
    set version [mrb [expr {$fl_ram_block_info + $FL_RAM_VER_OFS}]]
    if { $version < 2 } {
	return
    }

    global FLASH_TYPE_UNKNOWN
    global FLASH_TYPE_MACRONIX
    global FLASH_TYPE_WINBOND
    global FLASH_TYPE_GIGA
    global FLASH_TYPE_FUDAN
    global FLASH_TYPE_PUYA
    global FLASH_TYPE_GIANTEC
    global FLASH_TYPE_RRAM
    global FL_RAM_PROG_WAIT_TIME
    if { $flash_type == $FLASH_TYPE_UNKNOWN } {
	puts "<fast_load> Unknown flash type!"
	return
    }

    global FL_RAM_SECTOR_4K
    global FL_RAM_SECTOR_8K
    global FL_RAM_SECTOR_16K
    global FL_RAM_SECTOR_SIZE

    if { $flash_type == $FLASH_TYPE_MACRONIX } {
	set flash_name "MACRONIX"
    } elseif { $flash_type == $FLASH_TYPE_WINBOND } {
	set flash_name "WINBOND"
    } elseif { $flash_type == $FLASH_TYPE_GIGA } {
	set flash_name "GIGA"
    } elseif { $flash_type == $FLASH_TYPE_FUDAN } {
	set flash_name "FUDAN"
    } elseif { $flash_type == $FLASH_TYPE_PUYA } {
	set flash_name "PUYA"
    } elseif { $flash_type == $FLASH_TYPE_GIANTEC } {
	set flash_name "GIANTEC"
    } elseif { $flash_type == $FLASH_TYPE_RRAM } {
	set flash_name "RRAM"
    } else {
	error "<fast_load> Unknown flash type!"
    }

    if { $FL_RAM_SECTOR_SIZE == $FL_RAM_SECTOR_4K } {
	set block 4
    } elseif { $FL_RAM_SECTOR_SIZE == $FL_RAM_SECTOR_8K } {
	set block 8
    } elseif { $FL_RAM_SECTOR_SIZE == $FL_RAM_SECTOR_16K } {
	set block 16
    }

    global FLASH_${flash_name}_SEC_PROG_TIME_${block}K
    global FLASH_${flash_name}_SEC_VERIFY_TIME_${block}K
    global FL_RAM_OP_FW_LOAD
    global FL_RAM_OP_ERASE
    global FL_RAM_OP_VERIFY

    set FL_RAM_PROG_WAIT_TIME 0
    if { [expr { $opcode & $FL_RAM_OP_FW_LOAD }] } {
	set ptime [set FLASH_${flash_name}_SEC_PROG_TIME_${block}K]
	set FL_RAM_PROG_WAIT_TIME [expr {$FL_RAM_PROG_WAIT_TIME + $ptime}]
    }

    global FLASH_${flash_name}_SEC_ERASE_TIME_4K
    if { [expr { $opcode & $FL_RAM_OP_ERASE }] } {
	set etime [set FLASH_${flash_name}_SEC_ERASE_TIME_4K]
	set FL_RAM_PROG_WAIT_TIME [expr {$FL_RAM_PROG_WAIT_TIME + $etime}]
    }

    if { [expr { $opcode & $FL_RAM_OP_VERIFY }] } {
	set vtime [set FLASH_${flash_name}_SEC_VERIFY_TIME_${block}K]
	set FL_RAM_PROG_WAIT_TIME [expr {$FL_RAM_PROG_WAIT_TIME + $vtime}]
    }

    global FL_RAM_DFLT_LOAD_${block}K_CS
    global FL_RAM_DFLT_LOAD_CS
    set FL_RAM_DFLT_LOAD_CS [set FL_RAM_DFLT_LOAD_${block}K_CS]

    global FL_RAM_PROG_WAIT_TIME_DFLT
    if { $FL_RAM_PROG_WAIT_TIME_DFLT < $FL_RAM_PROG_WAIT_TIME } {
	set FL_RAM_PROG_WAIT_TIME_DFLT [expr {$FL_RAM_PROG_WAIT_TIME + \
	    $FL_RAM_DFLT_LOAD_CS}]
    }
}

proc fl_ram_erase { region_size region_start {er_sector_size 4096} } {
    global _FL_RAM_BLOCK_INFO
    global _FL_RAM_KICK_PROGRAM

    set fl_ram_block_info $_FL_RAM_BLOCK_INFO
    set fl_ram_kick_program $_FL_RAM_KICK_PROGRAM
    set fl_ram_buf0_addr [mrw [expr {$fl_ram_block_info + 16}]]

    set FL_RAM_INPUT_ER_ALL 0xFFFFFFFF
    if { $region_size == $FL_RAM_INPUT_ER_ALL } {
	set FL_RAM_ER_ALL 0xFFFF
	set erase_size $FL_RAM_ER_ALL
    } else {
	global FL_RAM_ER_SEC
	global FL_RAM_ER_SEC_BASE
	global FL_RAM_ER_SEC_${er_sector_size}
	set er_sector_idx 0
	set er_residue $er_sector_size
	while { $er_residue >= $FL_RAM_ER_SEC_BASE } {
	    set er_residue [expr {$er_residue / $FL_RAM_ER_SEC_BASE}]
	    incr er_sector_idx 1
	    if { $er_sector_idx >= $FL_RAM_ER_SEC(IDX_MAX) } {
		error [ format "<fast_load> unknow erase sector - index=%d, \
		    size=%d" $er_sector_idx $er_sector_size ]
	    }
	}

	set er_length [expr {$region_size / $er_sector_size}]
	if { [expr {$region_size % $er_sector_size}] } {
	    incr er_length 1
	}

	set FL_RAM_ER_SEC_OST 14
	set erase_size [expr {($er_sector_idx << $FL_RAM_ER_SEC_OST) | \
	    $er_length}]
	puts [ format "<fast_load> erase sector idx=%d, len=%d, erase_size=%#x" \
	    $er_sector_idx $er_sector_size $erase_size ]
    }

    global FLASH_TYPE_RRAM
    global FL_RAM_FLASH_TYPE_OFS
    set flash_type [mrb [expr {$fl_ram_block_info + $FL_RAM_FLASH_TYPE_OFS}]]
    puts [format "<fast_load> flash type: 0x%x, 0x%x" \
	[expr {$flash_type & $FLASH_TYPE_RRAM}] \
	[expr {$flash_type & ~$FLASH_TYPE_RRAM}]]

    global FLASH_BASE_ADDR
    if {$region_start < $FLASH_BASE_ADDR} {
	set flash_type $FLASH_TYPE_RRAM
    } else {
	set flash_type [expr {$flash_type & ~$FLASH_TYPE_RRAM}]
    }

    global FLASH_TYPE_UNKNOWN
    if {$flash_type == $FLASH_TYPE_UNKNOWN} {
	puts [format "<fast_load> skip (unknown flash)"]
	return 1
    }

    global FL_RAM_OP_ERASE
    fl_ram_get_program_wait_timeout $FL_RAM_OP_ERASE $flash_type

    global FL_RAM_PROG_WAIT_TIME
    global FL_RAM_ER_SEC_4096
    set er_size_tmp $region_size
    if { $region_size == $FL_RAM_INPUT_ER_ALL } {
	# The maximum size is 512KB
	set er_size_tmp 0x80000
    }
    set er_dft_wait_time [expr {(($er_size_tmp / $FL_RAM_ER_SEC_4096 + 1) *
	$FL_RAM_PROG_WAIT_TIME)}]
    puts [format "<fast_load> er_dft_wait_time: %d, FL_RAM_PROG_WAIT_TIME: %d" \
	$er_dft_wait_time $FL_RAM_PROG_WAIT_TIME ]

    set erase_begin [clock milliseconds]

    # set owner
    mwb [expr {$fl_ram_buf0_addr}] 1

    # set opcode
    mwb [expr {$fl_ram_buf0_addr + 1}] $FL_RAM_OP_ERASE

    # set erase size
    mwb [expr {$fl_ram_buf0_addr + 2}] [expr {$erase_size & 0xFF}]
    mwb [expr {$fl_ram_buf0_addr + 3}] [expr {($erase_size >> 8) & 0xFF}]

    # set write flash address
    mww [expr {$fl_ram_buf0_addr + 4}] $region_start

    fl_ram_program_page $fl_ram_kick_program

    after [expr {$er_dft_wait_time * 10 }]
    set fl_owner_er_retry 100
    set target_ram_addr [expr {$fl_ram_buf0_addr + 8}]
    poll off
    while { $fl_owner_er_retry > 0 } {
	if {[catch {set fl_ram_ret_owner [mrb $fl_ram_buf0_addr]} err]} {
	    puts "Get fl_ram_ret_owner failed, retry"
	    after 200
	    incr fl_owner_er_retry -1
	    continue
	}

	if {$fl_ram_ret_owner == 0x00} {
	    break
	} elseif {$fl_ram_ret_owner == 0x02} {
	    set ret_code [mrb $target_ram_addr]
	    error [format "<fast_load> erase, error code: %#x" $ret_code]
	}
	after 200
	incr fl_owner_er_retry -1
    }
    poll on

    if { !$fl_owner_er_retry } {
	error "<fast_load> Fail to erase data!"
    }

    set erase_end [clock milliseconds]
    set erase_time [expr {$erase_end - $erase_begin}]
    puts [ format "<fast_load> erase $region_size bytes spent %d ms" \
	$erase_time ]
}

proc fl_ram_write { image region_start opcode } {
    global _FL_RAM_BLOCK_INFO
    global _FL_RAM_KICK_PROGRAM

    set fl_ram_block_info $_FL_RAM_BLOCK_INFO
    set fl_ram_kick_program $_FL_RAM_KICK_PROGRAM

    set fl_ram_buf0_addr [mrw [expr {$fl_ram_block_info + 16}]]
    set image_size [file size $image]

    global FL_RAM_SECTOR_SIZE
    if {[info exists ::env(FL_SECTOR_SIZE)]} {
	set FL_RAM_SECTOR_SIZE $::env(FL_SECTOR_SIZE)
    }

    global FLASH_TYPE_RRAM
    global FL_RAM_FLASH_TYPE_OFS
    set flash_type [mrb [expr {$fl_ram_block_info + $FL_RAM_FLASH_TYPE_OFS}]]
    puts [format "<fast_load> flash type: 0x%x, 0x%x" \
	[expr {$flash_type & $FLASH_TYPE_RRAM}] \
	[expr {$flash_type & ~$FLASH_TYPE_RRAM}]]

    global FLASH_BASE_ADDR
    if {$region_start < $FLASH_BASE_ADDR} {
	set flash_type $FLASH_TYPE_RRAM
    } else {
	set flash_type [expr {$flash_type & ~$FLASH_TYPE_RRAM}]
    }

    global FLASH_TYPE_UNKNOWN
    if {$flash_type == $FLASH_TYPE_UNKNOWN} {
	puts [format "<fast_load> skip (unknown flash)"]
	return 1
    }

    fl_ram_get_program_wait_timeout $opcode $flash_type

    global FL_RAM_PROG_WAIT_TIME
    if {[info exists ::env(FL_PROG_WAIT)]} {
	set FL_RAM_PROG_WAIT_TIME $::env(FL_PROG_WAIT)
    }

    global FL_RAM_DFLT_LOAD_CS
    if {[info exists ::env(FL_DFLT_LOAD_CS)]} {
	set FL_RAM_DFLT_LOAD_CS $::env(FL_DFLT_LOAD_CS)
    }

    puts [format "<fast_load> image size: %u, FL_RAM_SECTOR_SIZE: %d" \
	$image_size $FL_RAM_SECTOR_SIZE]
    puts [format "<fast_load> FL_RAM_PROG_WAIT_TIME: %d cs, \
	FL_RAM_DFLT_LOAD_CS: %u cs" $FL_RAM_PROG_WAIT_TIME \
	$FL_RAM_DFLT_LOAD_CS]

    set prog_begin [clock milliseconds]

    # open image file
    set fd_image [open $image "rb"]

    set image_offset 0
    set residue_size $image_size
    set target_ram_addr [expr {$fl_ram_buf0_addr + 8}]
    set fl_ram_get_proc_time 0
    poll off
    while {$residue_size > 0} {
	# set owner
	mwb [expr {$fl_ram_buf0_addr}] 1

	# set opcode
	mwb [expr {$fl_ram_buf0_addr + 1}] $opcode

	# set write size
	if {$residue_size >= $FL_RAM_SECTOR_SIZE} {
	    set write_size $FL_RAM_SECTOR_SIZE
	    set residue_size [expr {$residue_size - $FL_RAM_SECTOR_SIZE}]
	} else {
	    set write_size $residue_size
	    set residue_size 0
	}
	mwb [expr {$fl_ram_buf0_addr + 2}] [expr {$write_size & 0xFF}]
	mwb [expr {$fl_ram_buf0_addr + 3}] [expr {($write_size >> 8) & 0xFF}]

	# set write flash address
	mww [expr {$fl_ram_buf0_addr + 4}] [expr {$region_start + $image_offset}]

	if {[info exists ::env(DEBUG)]} {
	    set sector_load_begin [clock milliseconds]
	}

	# seek image file to offset
	seek $fd_image $image_offset start
	set image_data [read $fd_image $write_size]

	# temporary binary file which will write to ram buffer
	global FL_RAM_TMP_FILE
	set tfile [open $FL_RAM_TMP_FILE wb]
	fconfigure $tfile -translation binary
	puts -nonewline $tfile $image_data
	close $tfile

	load_image $FL_RAM_TMP_FILE $target_ram_addr bin
	file delete $FL_RAM_TMP_FILE

	if {[info exists ::env(DEBUG)]} {
	    puts [format "<fast_load> write_size: 0x%x, image_offset: 0x%x, \
		residue_size: 0x%x" $write_size $image_offset $residue_size]
	}
	set image_offset [expr {$image_offset + $write_size}]

	if {[info exists ::env(DEBUG)]} {
	    set sector_load_end [clock milliseconds]
	}

	fl_ram_program_page $fl_ram_kick_program

	after [expr {$FL_RAM_PROG_WAIT_TIME * 10 }]
	set fl_owner_rd_retry 100
	while { $fl_owner_rd_retry > 0 } {
	    if {[catch {set fl_ram_ret_owner [mrb $fl_ram_buf0_addr]} err]} {
		puts "Get fl_ram_ret_owner failed, retry"
		after 50
		incr fl_owner_rd_retry -1
		continue
	    }

	    if {$fl_ram_ret_owner == 0x00} {
		if {!$fl_ram_get_proc_time} {
		    global FL_RAM_PROC_TIME_OFS
		    if {[info exists ::env(FL_PROG_WAIT)]} {
			set fl_ram_get_proc_time 1
			puts [format "<fast_load> Get proc_time: %u cs" \
			    [mrb [expr {$fl_ram_block_info + \
			    $FL_RAM_PROC_TIME_OFS}]]]
			continue
		    }
		    if { $flash_type == $FLASH_TYPE_RRAM } {
			set fl_ram_get_proc_time 1
			puts [format "<fast_load> keep FL_RAM_PROG_WAIT_TIME: \
			    %u cs for RRAM" $FL_RAM_PROG_WAIT_TIME]
			continue
		    }
		    set FL_RAM_PROG_WAIT_TIME [expr {[mrb [expr \
			{$fl_ram_block_info + $FL_RAM_PROC_TIME_OFS}]] + \
			$FL_RAM_DFLT_LOAD_CS + 1}]
		    global FL_RAM_PROG_WAIT_TIME_DFLT
		    if {$FL_RAM_PROG_WAIT_TIME > $FL_RAM_PROG_WAIT_TIME_DFLT} {
			puts [format "<fast_load> FL_RAM_PROG_WAIT_TIME: %u cs, \
			retry" $FL_RAM_PROG_WAIT_TIME]
			set FL_RAM_PROG_WAIT_TIME $FL_RAM_PROG_WAIT_TIME_DFLT
		    } else {
			set fl_ram_get_proc_time 1
			puts [format "<fast_load> update FL_RAM_PROG_WAIT_TIME: \
			    %u cs" $FL_RAM_PROG_WAIT_TIME]
		    }
		}
		break
	    } elseif {$fl_ram_ret_owner == 0x02} {
		set ret_code [mrb $target_ram_addr]
		error [format "<fast_load> error code: %#x" $ret_code]
	    }
	    after 10
	    incr fl_owner_rd_retry -1
	}

	if { !$fl_owner_rd_retry } {
	    error "<fast_load> Fail to program data!"
	}

	if {[info exists ::env(DEBUG)]} {
	    set sector_write_end [clock milliseconds]
	    puts [ format "sector load: %d ms, sector write: %d ms" \
		[expr {$sector_load_end - $sector_load_begin}] \
		[expr {$sector_write_end - $sector_load_end}]]
	}
    }
    close $fd_image
    poll on

    set prog_end [clock milliseconds]
    set prog_time [expr {$prog_end - $prog_begin}]
    puts [ format "<fast_load> Program size $image_size bytes spent %d ms" \
	$prog_time [expr {$image_size / $prog_time}]]
}

proc fl_ram_init {} {
    global _FL_RAM_BLOCK_INFO
    global _FL_RAM_KICK_PROGRAM

    set init_begin [clock milliseconds]

    set fl_ram_block_info $_FL_RAM_BLOCK_INFO
    set fl_ram_kick_program $_FL_RAM_KICK_PROGRAM
    set fl_ram_buf0_addr [mrw [expr {$fl_ram_block_info + 16}]]

    mwb [expr {$fl_ram_buf0_addr}] 1
    mwb [expr {$fl_ram_buf0_addr + 1}] 1
    mwb [expr {$fl_ram_buf0_addr + 2}] 0
    mwb [expr {$fl_ram_buf0_addr + 3}] 0

    mww [expr {$fl_ram_buf0_addr + 4}] 0
    fl_ram_program_page $fl_ram_kick_program

    # calculate the firmware (fl_ram) initial time and overhead, the initial
    # time should less than 100 ms
    sleep 20 busy
    set fl_owner_rd_retry 8
    while { $fl_owner_rd_retry > 0 } {
	if {([mrb $fl_ram_buf0_addr] & 0xFF) == 0x00} {
	    break
	}
	sleep 10 busy
	incr fl_owner_rd_retry -1
    }

    if { !$fl_owner_rd_retry } {
	error "<fast_load> Initial fail!"
    }

    set init_end [clock milliseconds]
    set init_time [expr {$init_end - $init_begin}]
    puts [ format "<fast_load> Initialize spent %d ms" $init_time]
}

proc atm_fast_load { image {opcode 0x01} {region_start 0x0} } {
    adapter speed 4000

    # wait fl_ram ready
    sleep 50

    global _FL_RAM_BLOCK_INFO
    global FL_RAM_VER_OFS
    set fl_ram_block_info $_FL_RAM_BLOCK_INFO
    if {[info exists ::env(DEBUG)]} {
	puts [format "<fast_load> fl_ram_block_info: 0x%x, info0: 0x%x, \
	    info1: 0x%x, info2: 0x%x, info3: 0x%x, version: %x" \
	    $fl_ram_block_info [mrw $fl_ram_block_info] \
	    [mrw [expr {$fl_ram_block_info + 4}]] \
	    [mrw [expr {$fl_ram_block_info + 8}]] \
	    [mrw [expr {$fl_ram_block_info + 12}]] \
	    [mrb [expr {$fl_ram_block_info + $FL_RAM_VER_OFS}]]]
    }

    # check magic number
    global FL_RAM_MAGIC0_OFS
    global FL_RAM_MAGIC1_OFS

    set FL_RAM_MAGIC_1 0x5f445753
    set FL_RAM_MAGIC_2 0x4f47454e

    set magic1 [mrw [expr {$fl_ram_block_info + $FL_RAM_MAGIC0_OFS}]]
    set magic2 [mrw [expr {$fl_ram_block_info + $FL_RAM_MAGIC1_OFS}]]
    if {$magic1 != $FL_RAM_MAGIC_1 || $magic2 != $FL_RAM_MAGIC_2} {
	error [format "<fast_load> wrong magic number: 0x%x 0x%x" $magic1 $magic2]
    }

    # check kick program
    global _FL_RAM_KICK_PROGRAM
    global FL_RAM_KICK_PROG_OFS

    set FL_RAM_ARM_INSTR_MODE_MASK 0xFFFFFFFE
    set fl_ram_kick_program $_FL_RAM_KICK_PROGRAM
    set fn_kick [mrw [expr {$fl_ram_block_info + $FL_RAM_KICK_PROG_OFS}]]
    if {[expr {$fn_kick & $FL_RAM_ARM_INSTR_MODE_MASK}] != \
	$fl_ram_kick_program} {
	error [format "<fast_load> wrong kick program: 0x%x" $fn_kick]
    }

    fl_ram_init

    global FL_RAM_OP_ERASE
    if { $opcode == $FL_RAM_OP_ERASE } {
	fl_ram_erase $image $region_start
    } else {
	fl_ram_write $image $region_start $opcode
    }
}

proc atm2x_load_ram_image { image } {
    global _FL_RAM_PLATFORM
    if { $_FL_RAM_PLATFORM == "ATM22xx-x1x" } {
	set external_flash_init 0x0000601d
    } else {
	set external_flash_init 0x00006b18
    }

    load_ram_image $external_flash_init $image 0x2000C000
    resume 0x2000C000
}

proc atmx3_load_ram_image { image } {
    reset halt

    ## load ram code's image
    sleep 1
    global _FL_RAM_VECTOR_TABLE
    set ram_image_addr $_FL_RAM_VECTOR_TABLE

    if {[info exists ::env(DEBUG)]} {
	puts [format "<fast_load> Download ram image <0x%x>" $ram_image_addr]
    }

    load_image $image $ram_image_addr

    sleep 1
    global _FL_RAM_RESET_HANDLER_PROGRAM
    set reset_handler_program $_FL_RAM_RESET_HANDLER_PROGRAM
    puts [format "<fast_load> reset_handler_program addr 0x%x" $reset_handler_program]

    global _FL_RAM_STACK_TOP
    set stack_top $_FL_RAM_STACK_TOP
    puts [format "<fast_load> stack top addr 0x%x" $stack_top]

    puts [format "<fast_load> run the reset handler program..."]
    set_reg {pc 0x$reset_handler_program sp 0x$stack_top}
    resume $reset_handler_program
    sleep 400

    halt
}
