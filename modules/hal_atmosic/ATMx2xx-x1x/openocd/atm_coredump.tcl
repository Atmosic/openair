################################################################################
#
# @file atm_coredump.tcl
#
# @brief Implements Coredump Helper functions for ATM22/ATM32 paltform
#
# Copyright (C) Atmosic 2022
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
    set section_names {".shstrtab" ".flash" ".rom" ".sram" ".em"}
    return $section_names
}

# Dumps flash using appropriate function for platform
proc coredump_dump_flash { CoreDumpFile } {
    set temp_file "tmpfile"

    sydney_dump_flash $temp_file [sydney_flash_size]
    copy_tempfile $temp_file $CoreDumpFile
}

proc get_headers { list_of_regions initial_offset string_table } {
    set program_header ""
    set section_headers ""

    set data_offset $initial_offset
    foreach region $list_of_regions {
	set start_addr [lindex $region 0]
	set region_size [lindex $region 1]
	set string [lindex $region 2]

	set string_offset [string first $string $string_table]

	append program_headers [generate_program_header 1 $data_offset $start_addr 0 $region_size]
	append section_headers [generate_section_header $string_offset 1 4 $start_addr $data_offset $region_size 0 0 1 0]

	incr data_offset $region_size
    }

    return [list $program_headers $section_headers]
}

proc get_list_of_regions {} {
    # Each region is of format {start_addr size section_name}
    set list_of_regions [list]
    lappend list_of_regions [list $::CMSDK_ROM_BASE 0x40000 ".rom"]

    set num_sram_banks 6
    set sram_bank_size 0x4000
    set num_em_banks 2
    set em_bank_size 0x4000

    enable_pseq
    set sram_override [mrw $::CMSDK_PSEQ_SYSRAM_OVERRIDES]
    set emram_override [mrw $::CMSDK_PSEQ_EMRAM_OVERRIDES]
    disable_pseq

    set sram_active_sections [active_sections $::CMSDK_RAM_BASE $sram_bank_size $num_sram_banks $sram_override]
    set em_active_sections [active_sections $::CMSDK_EM_BASE $em_bank_size $num_em_banks $emram_override]

    foreach start $sram_active_sections {
	lappend list_of_regions [list $start $sram_bank_size ".sram"]
    }

    foreach start $em_active_sections {
	lappend list_of_regions [list $start $em_bank_size ".em"]
    }

    lappend list_of_regions [list $::CMSDK_FLASH_BASE [sydney_flash_size] ".flash"]
}
