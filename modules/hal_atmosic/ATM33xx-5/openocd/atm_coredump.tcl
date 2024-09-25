################################################################################
#
# @file atm_coredump.tcl
#
# @brief Implements Coredump Helper functions for ATM33 platform
#
# Copyright (C) Atmosic 2022-2023
#
################################################################################

proc reg_dump {} {
    set index { 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 }

    # First 18 ints are 0s
    set str [string repeat "\u0000" 72]
    foreach x $index {
	append str [binary format i1 [ lindex [reg $x] 2]]
    }
    append str [binary format i1 0x0]
    return $str
}

proc get_section_names {} {
    set section_names {".shstrtab" ".flash" ".rom" ".rram" ".sram" ".em"}
    return $section_names
}

# Dumps flash using appropriate function for platform
proc coredump_dump_flash { CoreDumpFile } {
    set temp_file "tmpfile"

    # Catch returns 0 if no error, else no flash detected and skip dump
    if {[catch {set flash_size [atm_flash_size]}] == 0} {
	atm_dump_flash $temp_file $flash_size
	copy_tempfile $temp_file $CoreDumpFile
    }
}

proc get_headers { list_of_regions initial_offset string_table } {
    set program_header ""
    set section_headers ""

    set data_offset $initial_offset
    foreach region $list_of_regions {
	set start_addr [lindex $region 0]
	set region_size [lindex $region 1]
	set string [lindex $region 2]
	set veneer [lindex $region 3]

	set string_offset [string first $string $string_table]

	append program_headers [generate_program_header 1 $data_offset $start_addr 0 $region_size]
	append section_headers [generate_section_header $string_offset 1 4 $start_addr $data_offset $region_size 0 0 1 0]

	# if veneer add 2nd header and increment file offset
	if {$veneer} {
	    incr data_offset $region_size
	}
    }

    return [list $program_headers $section_headers]
}

proc get_regions_from_luts { lut_list base_addr blk_size label} {
    set ret_list [list]

    set counter 0
    set offset 0
    # 1 == NS, 0 == S, 0xF == reset
    set type 0xF

    variable start_addr
    variable veneer_addr
    foreach lut $lut_list {
	if {$type == 0xf} {
	    set type [expr { $lut & 1 }]
	}
	# Quicker processing if LUT is all same value
	if {($lut == 0) || ($lut == 0xffffffff)} {
	     if {($lut & 1) != $type} {
		set region_size [expr { $counter * $blk_size }]
		if {$type == 0} {
		    set start_addr [expr { ($base_addr | 0x10000000) + $offset }]
		    set veneer_addr [expr { $base_addr + $offset }]
		} else {
		    set start_addr [expr { $base_addr + $offset }]
		    set veneer_addr [expr { ($base_addr | 0x10000000) + $offset }]
		}
		lappend ret_list [list $start_addr $region_size $label 0]
		lappend ret_list [list $veneer_addr $region_size $label 1]
		incr offset $region_size
		set counter 0
		set type [expr { $lut & 1 }]
	    }
	    incr counter 32
	} else {
	    for {set i 0} {$i < 32} {incr i} {
		set cur_val [expr { $lut & 1 }]
		set lut [expr { $lut >> 1 }]
		if {$cur_val != $type} {
		    set region_size [expr { $counter * $blk_size }]
		    if {$type == 0} {
			set start_addr [expr { ($base_addr | 0x10000000) + $offset }]
			set veneer_addr [expr { $base_addr + $offset }]
		    } else {
			set start_addr [expr { $base_addr + $offset }]
			set veneer_addr [expr { ($base_addr | 0x10000000) + $offset }]
		    }
		    lappend ret_list [list $start_addr $region_size $label 0]
		    lappend ret_list [list $veneer_addr $region_size $label 1]
		    incr offset $region_size
		    set counter 0
		    set type $cur_val
		}
		incr counter
	    }
	}
    }

    # Writeout last region
    set region_size [expr { $counter * $blk_size }]
    if {$type == 0} {
	set start_addr [expr { ($base_addr | 0x10000000) + $offset }]
	set veneer_addr [expr { $base_addr + $offset }]
    } else {
	set start_addr [expr { $base_addr + $offset }]
	set veneer_addr [expr { ($base_addr | 0x10000000) + $offset }]
    }
    lappend ret_list [list $start_addr $region_size $label 0]
    lappend ret_list [list $veneer_addr $region_size $label 1]

    return $ret_list
}

proc get_list_of_regions {} {
    # Each region is of format {start_addr size section_name veneer}
    # veneer is a bool indicating to incremement file offset or not, used for TZ
    set list_of_regions [list]

    variable fls_blk_size
    namespace eval ::MPC_FLS_SECURE::BLK_CFG {
	upvar fls_blk_size blk_size
	set blk_size [expr { 1 << ([mrw [REG_ADDR]] + 5) }]
    }

    ####### ROM #######
    set rom_luts [list]
    set num_rom_blks [expr { $::CMSDK_ROM_SIZE / (32 * $fls_blk_size) }]
    for {set i 0} {$i < $num_rom_blks} {incr i} {
	namespace eval ::MPC_FLS_SECURE::BLK_IDX {
	    upvar i j
	    BLK_IDX::MODIFY_TGT [REG_ADDR] $j
	}
	namespace eval ::MPC_FLS_SECURE::BLK_LUT {
	    upvar rom_luts lut_list
	    set LUT_VAL [mrw [REG_ADDR]]
	    lappend lut_list $LUT_VAL
	}
    }

    set list_of_regions [concat $list_of_regions [get_regions_from_luts $rom_luts $::CMSDK_ROM_BASE $fls_blk_size ".rom"]]

    ######## RRAM ########
    set rram_luts [list]
    set num_rram_blks [expr { $::CMSDK_RRAM_SIZE / (32 * $fls_blk_size) }]
    set rram_end_blk [expr { $num_rom_blks + $num_rram_blks }]
    for {set i $num_rom_blks} {$i < $rram_end_blk} {incr i} {
	namespace eval ::MPC_FLS_SECURE::BLK_IDX {
	    upvar i j
	    BLK_IDX::MODIFY_TGT [REG_ADDR] $j
	}
	namespace eval ::MPC_FLS_SECURE::BLK_LUT {
	    upvar rram_luts lut_list
	    set LUT_VAL [mrw [REG_ADDR]]
	    lappend lut_list $LUT_VAL
	}
    }

    set list_of_regions [concat $list_of_regions [get_regions_from_luts $rram_luts $::CMSDK_RRAM_BASE $fls_blk_size ".rram"]]

    ######## EM / SRAM Get Active Sections ########
    set PREV_SX $::SX

    # Need to update global SX for WRPR1 in enable/disable_pseq
    namespace eval ::SEC_PRIV_CTRL_SECURE::APBNSPPCEXP1 {
	set apbnsppcexp1_val [mrw [REG_ADDR]]
	if { [WRPR::READ $apbnsppcexp1_val] } {
	    set ::SX "_NONSECURE"
	} else {
	    set ::SX "_SECURE"
	}
    }
    enable_pseq

    variable PSEQ_SX
    namespace eval ::SEC_PRIV_CTRL_SECURE::APBNSPPCEXP1 {
	upvar PSEQ_SX TEMP_SX
	set apbnsppcexp1_val [mrw [REG_ADDR]]
	if { [PSEQ::READ $apbnsppcexp1_val] } {
	    set TEMP_SX "_NONSECURE"
	} else {
	    set TEMP_SX "_SECURE"
	}
    }
    set sram_override [mrw [::CMSDK_PSEQ${PSEQ_SX}::SYSRAM_OVERRIDES]]
    set sram_override_shift [::CMSDK_PSEQ${PSEQ_SX}::SYSRAM_OVERRIDES::OVERRIDE_SYSRAM_VDDCUT::SHIFT]
    set num_sram_banks [::CMSDK_PSEQ${PSEQ_SX}::SYSRAM_OVERRIDES::OVERRIDE_SYSRAM_VDDCUT::WIDTH]

    set emram_override [mrw [::CMSDK_PSEQ${PSEQ_SX}::EMRAM_OVERRIDES]]
    set emram_override_shift [::CMSDK_PSEQ${PSEQ_SX}::EMRAM_OVERRIDES::OVERRIDE_EMRAM_VDDCUT::SHIFT]
    set num_emram_banks [::CMSDK_PSEQ${PSEQ_SX}::EMRAM_OVERRIDES::OVERRIDE_EMRAM_VDDCUT::WIDTH]

    disable_pseq
    set ::SX $PREV_SX

    ######## SRAM ########
    # SRAM Region refers to SRAM0, SRAM1, SRAM2, SRAM3
    set num_sram_regions 4
    set num_sram_banks_per_region [expr { $num_sram_banks / $num_sram_regions }]
    set sram_bank_size 0x4000
    set sram_active_sections [active_sections $::CMSDK_RAM_BASE $sram_bank_size $num_sram_banks $sram_override $sram_override_shift]

    variable sram_blk_size
    namespace eval ::MPC_RAM0_SECURE::BLK_CFG {
	upvar sram_blk_size blk_size
	set blk_size [expr { 1 << ([mrw [REG_ADDR]] + 5) }]
    }

    set sram0_luts [list]
    set sram1_luts [list]
    set sram2_luts [list]
    set sram3_luts [list]
    set num_sram_blks [expr { ($sram_bank_size * $num_sram_banks_per_region) / (32 * $sram_blk_size) }]
    for {set i 0} {$i < $num_sram_blks} {incr i} {
	# RAM 0
	namespace eval ::MPC_RAM0_SECURE::BLK_IDX {
	    upvar i j
	    BLK_IDX::MODIFY_TGT [REG_ADDR] $j
	}
	namespace eval ::MPC_RAM0_SECURE::BLK_LUT {
	    upvar sram0_luts lut_list
	    set LUT_VAL [mrw [REG_ADDR]]
	    lappend lut_list $LUT_VAL
	}
	# RAM 1
	namespace eval ::MPC_RAM1_SECURE::BLK_IDX {
	    upvar i j
	    BLK_IDX::MODIFY_TGT [REG_ADDR] $j
	}
	namespace eval ::MPC_RAM1_SECURE::BLK_LUT {
	    upvar sram1_luts lut_list
	    set LUT_VAL [mrw [REG_ADDR]]
	    lappend lut_list $LUT_VAL
	}
	# RAM 2
	namespace eval ::MPC_RAM2_SECURE::BLK_IDX {
	    upvar i j
	    BLK_IDX::MODIFY_TGT [REG_ADDR] $j
	}
	namespace eval ::MPC_RAM2_SECURE::BLK_LUT {
	    upvar sram2_luts lut_list
	    set LUT_VAL [mrw [REG_ADDR]]
	    lappend lut_list $LUT_VAL
	}
	# RAM 3
	namespace eval ::MPC_RAM3_SECURE::BLK_IDX {
	    upvar i j
	    BLK_IDX::MODIFY_TGT [REG_ADDR] $j
	}
	namespace eval ::MPC_RAM3_SECURE::BLK_LUT {
	    upvar sram3_luts lut_list
	    set LUT_VAL [mrw [REG_ADDR]]
	    lappend lut_list $LUT_VAL
	}
    }

    set sram_region_size [expr { $sram_bank_size * $num_sram_banks_per_region }]
    set sram_luts_per_bank [expr { ($sram_bank_size / $sram_blk_size) / 32 }]
    foreach start_addr $sram_active_sections {
	variable cur_ram_luts
	if {$start_addr < ($::CMSDK_RAM_BASE + $sram_region_size)} {
	    # RAM 0
	    set cur_ram_luts $sram0_luts
	} elseif {$start_addr < ($::CMSDK_RAM_BASE + (2 * $sram_region_size))} {
	    # RAM 1
	    set cur_ram_luts $sram1_luts
	} elseif {$start_addr < ($::CMSDK_RAM_BASE + (3 * $sram_region_size))} {
	    # RAM 2
	    set cur_ram_luts $sram2_luts
	} else {
	    # RAM 3
	    set cur_ram_luts $sram3_luts
	}

	# Pull out the currect LUT values for given bank into new list
	variable start_lut
	if {$start_addr & $sram_bank_size} {
	    set start_lut $sram_luts_per_bank
	} else {
	    set start_lut 0
	}
	set cur_bank_luts [lrange $cur_ram_luts $start_lut [expr { $start_lut + $sram_luts_per_bank - 1 }]]
	set list_of_regions [concat $list_of_regions [get_regions_from_luts $cur_bank_luts $start_addr $sram_blk_size ".sram"]]
    }

    ####### Exchange Memory ########
    # Defines Secure or Non-secure address based on the BLE link controller PPC
    variable EM_ADDR
    namespace eval ::SEC_PRIV_CTRL_SECURE::AHBNSPPCEXP1 {
	upvar EM_ADDR TEMP_ADDR
	set ahbnsppcexp1_val [mrw [REG_ADDR]]
	if { [BLE52::READ $ahbnsppcexp1_val] } {
	    set TEMP_ADDR $::CMSDK_EM_BASE
	} else {
	    set TEMP_ADDR [expr { $::CMSDK_EM_BASE | 0x10000000 }]
	}
    }

    set em_bank_size 0x4000
    set em_active_sections [active_sections $EM_ADDR $em_bank_size $num_emram_banks $emram_override $emram_override_shift]

    foreach start_addr $em_active_sections {
	variable veneer_addr
	if {$start_addr & 0x10000000} {
	    set veneer_addr [expr { $start_addr & ~0x10000000 }]
	} else {
	    set veneer_addr [expr { $start_addr | 0x10000000 }]
	}
	lappend list_of_regions [list $start_addr $em_bank_size ".em" 0]
	lappend list_of_regions [list $veneer_addr $em_bank_size ".em" 1]
    }

    ######## QSPI/External Flash ########
    set PREV_SX $::SX

    # Need to update global SX for WRPR0 in enable_dev for SPI2/QSPI
    # TODO: SPI2 and QSPI may have different PPC config than WRPR
    namespace eval ::SEC_PRIV_CTRL_SECURE::APBNSPPCEXP0 {
	set apbnsppcexp0_val [mrw [REG_ADDR]]
	if { [WRPR::READ $apbnsppcexp0_val] } {
	    set ::SX "_NONSECURE"
	} else {
	    set ::SX "_SECURE"
	}
    }

    if {[catch {set flash_size [atm_flash_size]}]} {
	lappend list_of_regions [list $::CMSDK_FLASH_BASE 0 ".flash" 0]
	lappend list_of_regions [list [expr { $::CMSDK_FLASH_BASE | 0x10000000 }] 0 ".flash" 1]
	return $list_of_regions
    }

    set ::SX $PREV_SX

    set qspi_luts [list]
    # There are 34 LUTs even though BLK_MAX returns 511, last 2 are for QSPI
    set qspi_end_idx 34
    set remainder 0
    # Only need to limit LUTs read or set remainder if less than 128 kB
    if {$flash_size < 0x20000} {
	set flash_num_luts [expr { $flash_size / $fls_blk_size }]
	set qspi_end_index [expr { ($flash_num_luts / 32) + 32 }]
	set remainder [expr { $flash_num_luts / 32.0 }]
    }

    for {set i 32} {$i < $qspi_end_idx} {incr i} {
	namespace eval ::MPC_FLS_SECURE::BLK_IDX {
	    upvar i j
	    BLK_IDX::MODIFY_TGT [REG_ADDR] $j
	}
	namespace eval ::MPC_FLS_SECURE::BLK_LUT {
	    upvar qspi_luts lut_list
	    set LUT_VAL [mrw [REG_ADDR]]
	    lappend lut_list $LUT_VAL
	}
    }

    set list_of_regions [concat $list_of_regions [get_regions_from_luts $qspi_luts $::CMSDK_FLASH_BASE $fls_blk_size ".flash"]]

    # If QSPI Flash does not evenly fit in BLK (x < 64kB || 64 kB < x < 128 kB)
    if {$remainder > 0} {
	set flash_remainder_lut
	namespace eval ::MPC_FLS_SECURE::BLK_IDX {
	    upvar qspi_end_idx remainder_idx
	    BLK_IDX::MODIFY_TGT [REG_ADDR] $remainder_idx
	}
	# Writeout remainder
	set base_addr [expr { $::CMSDK_FLASH_BASE + (($qspi_end_idx - 32) * 32 * $fls_blk_size) }]
	set type [expr { $flash_remainder_lut & 1 }]
	set counter 0
	set offset 0
	for {set i 0} {$i < (32 * $remainder)} {incr i} {
	    set cur_val [expr { $flash_remainder_lut & 1 }]
	    set lut [expr { $flash_remainder_lut >> 1 }]
	    if {$cur_val != $type} {
		set region_size [expr { $counter * $fls_blk_size }]
		if {$type == 0} {
		    set start_addr [expr { ($base_addr | 0x10000000) + $offset }]
		    set veneer_addr [expr { $base_addr + $offset }]
		} else {
		    set start_addr [expr { $base_addr + $offset }]
		    set veneer_addr [expr { ($base_addr | 0x10000000) + $offset }]
		}
		lappend list_of_regions [list $start_addr $region_size ".flash" 0]
		lappend list_of_regions [list $veneer_addr $region_size ".flash" 1]
		incr offset $region_size
		set counter 0
		set type $cur_val
	    }
	    incr counter
	}

	set region_size [expr { $counter * $fls_blk_size }]
	if {$type == 0} {
	    set start_addr [expr { ($base_addr | 0x10000000) + $offset }]
	    set veneer_addr [expr { $base_addr + $offset }]
	} else {
	    set start_addr [expr { $base_addr + $offset }]
	    set veneer_addr [expr { ($base_addr | 0x10000000) + $offset }]
	}
	lappend list_of_regions [list $start_addr $region_size ".flash" 0]
	lappend list_of_regions [list $veneer_addr $region_size ".flash" 1]
    }

    # All external flash after 128 kB (0x20000) is Non-Secure
    if {$flash_size > 0x20000} {
	lappend list_of_regions [list [expr { $::CMSDK_FLASH_BASE + 0x20000 }] [expr { $flash_size - 0x20000 }] ".flash" 0]
	lappend list_of_regions [list [expr { ($::CMSDK_FLASH_BASE | 0x10000000) + 0x20000 }] [expr { $flash_size - 0x20000 }] ".flash" 1]
    }

    return $list_of_regions
}
