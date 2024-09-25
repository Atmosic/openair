################################################################################
#
# @file coredump.tcl
#
# @brief Common File to Generate Coredump, relies on platform specific helper
#        files
#
# Copyright (C) Atmosic 2022-2023
#
################################################################################

proc generate_string_header { string_list } {

    set string_str [binary format c1 0x0]

    foreach name $string_list {
	append string_str $name
	append string_str [binary format c1 0x0]
    }

    return $string_str
}

proc generate_section_header { sh_name sh_type sh_flags sh_addr sh_offset sh_size sh_link sh_info sh_addralign sh_entsize } {
    set str [binary format i1 $sh_name]
    append str [binary format i1 $sh_type]
    append str [binary format i1 $sh_flags]
    append str [binary format i1 $sh_addr]
    append str [binary format i1 $sh_offset]
    append str [binary format i1 $sh_size]
    append str [binary format i1 $sh_link]
    append str [binary format i1 $sh_info]
    append str [binary format i1 $sh_addralign]
    append str [binary format i1 $sh_entsize]

    return $str
}

proc generate_program_header { p_type p_offset p_vaddr p_paddr p_filesz } {
    set str [binary format i1 $p_type]
    append str [binary format i1 $p_offset]
    append str [binary format i1 $p_vaddr]
    append str [binary format i1 $p_paddr]
    append str [binary format i1 $p_filesz]
    #memsz
    append str [binary format i1 0x0]
    #flags
    append str [binary format i1 0x0]
    #align
    append str [binary format i1 0x0]

    return $str
}

proc generate_pt_note { reg_dump } {
    # PT_NOTE Section
    # namesz
    set str [binary format i1 0x5]

    # descsz
    append str [binary format i1 [string length $reg_dump]]

    # type (NT_PRSTATUS == 1)
    append str [binary format i1 0x1]

    # name (+ padding)
    append str "CORE"
    append str [string repeat "\u0000" 4]

    # desc
    append str $reg_dump

    return $str
}

proc generate_elf_header { elf_header_size program_header_size num_prog_headers section_header_size num_sections } {

    set symtbl_section [expr { $num_sections - 1 }]

    # e_ident/EI_MAGIC
    set str [binary format c1a3 0x7f ELF]

    # e_ident/EI_CLASS
    append str [binary format c1 0x1]

    # e_ident/EI_DATA (Little Endian)
    append str [binary format c1 0x1]

    # e_ident/EI_VERSION (EV_CURRENT)
    append str [binary format c1 0x1]

    # e_ident/EI_PAD (9 Bytes)
    append str [binary format c9 {0x0 0x0 0x0 0x0 0x0 0x0 0x0 0x0 0x0}]

    # e_type (Core File)
    append str [binary format s1 0x4]

    # e_machine (EM_ARM)
    append str [binary format s1 40]

    # e_version (0x1)
    append str [binary format i1 0x1]

    # e_entry (0x0)
    append str [binary format i1 0x0]

    # e_phoff (0x0)
    append str [binary format i1 $elf_header_size]

    # e_shoff
    set e_shoff [expr { $program_header_size * $num_prog_headers }]
    set e_shoff [expr { $elf_header_size + $e_shoff }]
    append str [binary format i1 $e_shoff]

    # e_flags (0x0)
    append str [binary format i1 0x0]

    # e_ehsize
    append str [binary format s1 $elf_header_size]

    # e_phentsize
    append str [binary format s1 $program_header_size]

    # e_phnum
    append str [binary format s1 $num_prog_headers]

    # e_shentsize
    append str [binary format s1 $section_header_size]

    # e_shnum
    append str [binary format s1 $num_sections]

    # e_shstrndx (last section is symbol table)
    append str [binary format s1 $symtbl_section]

    return $str
}

# Return list of active sections based on override flag
proc active_sections { bank_start_addr bank_size no_of_banks override override_shift } {
    set act_sec_list {}
    for {set i 0} {$i < $no_of_banks} {incr i} {
	set start [expr { $bank_start_addr + ($i * $bank_size) }]
	if { !($override & [expr {1<<($override_shift+$i) | 1<<$i}]) } {
	    lappend act_sec_list $start
	}
    }
    return $act_sec_list
}

proc copy_tempfile { temp_file coredump_file } {
    set platform $::tcl_platform(os)
    if { $platform == "Windows NT" || $platform == "mingw" } {
	exec cmd /c copy /b $coredump_file + $temp_file
    } else {
	exec cat $temp_file >> $coredump_file
    }
}

# Dump all regions except external flash
proc dump_core { list_of_regions CoreDumpFile } {
    set temp_file "tmpfile"

    # Each region is of format {start_addr size section_name}
    foreach region $list_of_regions {
	# For Non-TrustZone parts length will be 3
	set list_length [llength $region]
	set veneer [lindex $region 3]
	if {$list_length == 3 || !$veneer} {
	    if {[string equal ".flash" [lindex $region 2]]} {
		coredump_dump_flash $CoreDumpFile
	    } else {
		dump_image $temp_file [lindex $region 0] [lindex $region 1]
		copy_tempfile $temp_file $CoreDumpFile
	    }
	}
    }
}

proc get_coredump { {CoreDumpFile "Coredump"} } {
#  CoreFile Layout Details:
#  +++++++++++++++++++++++++++++++++++++++++++++++++++
#  +                 ELF header                      +
#  +++++++++++++++++++++++++++++++++++++++++++++++++++
#  +                 Program Header #1               +
#  +++++++++++++++++++++++++++++++++++++++++++++++++++
#  +                 Program Header #2               +
#  +++++++++++++++++++++++++++++++++++++++++++++++++++
#  ...
#  +                 Program Header #n               +
#  +++++++++++++++++++++++++++++++++++++++++++++++++++
#  +                 Section Header #1               +
#  +++++++++++++++++++++++++++++++++++++++++++++++++++
#  +                 Section Header #2               +
#  +++++++++++++++++++++++++++++++++++++++++++++++++++
#  ...
#  +                 Section Header #n               +
#  +++++++++++++++++++++++++++++++++++++++++++++++++++
#  +         PT_NOTE/RegDump section data             +
#  +++++++++++++++++++++++++++++++++++++++++++++++++++
#  +         shstrtab/String table data              +
#  +++++++++++++++++++++++++++++++++++++++++++++++++++
#  +                                                 +
#  +                 Dumped Data                     +
#  +                                                 +
#  +++++++++++++++++++++++++++++++++++++++++++++++++++
#

    halt
    set saved_reg_dump [reg_dump]

    # "fconfigure $fp -translation binary" not work with tcl of OpenOCD
    set fp [open $CoreDumpFile wb]

    set oss $::tcl_platform(os)
    puts "Operating System: $oss"

    # Constants
    set elf_header_size		52
    set section_header_size	40
    set program_header_size	32

    # 20 bytes is from namesz (4), descsz (4), type (4), name (8)
    set ptnote_size [expr { 20 + [string length $saved_reg_dump] }]

    set list_of_regions [get_list_of_regions]
    set num_regions [llength $list_of_regions]

    # Print out regions that we are dumping, useful for debugging
    puts "Address  Size\tLabel"
    foreach region $list_of_regions {
	set list_length [llength $region]
	set veneer_val [lindex $region 3]
	if {$list_length == 3 || $veneer_val == 0 } {
	    set addr [format %08x [lindex $region 0]]
	    set size [format %x [lindex $region 1]]
	    set lbl [lindex $region 2]
	    puts "$addr $size\t$lbl"
	}
    }

    # + 1 for PT_NOTE
    set num_prog_headers [expr { $num_regions + 1 }]

    # + 2 for EMPTY and SHSTRTAB sections
    set num_sections [expr { $num_regions + 2 }]

    # Some constants to aid with offset calculation
    set program_total_size [expr { $program_header_size * $num_prog_headers }]
    set section_total_size [expr { $section_header_size * $num_sections }]
    set header_size [expr { $elf_header_size + $program_total_size + $section_total_size }]

    # Need to add length of array to add null terminator count (+ 1 is for EMPTY section header)
    set section_names [get_section_names]
    set string_tbl_size [expr { [llength $section_names] + [string length [string map {"\"" "" " " ""} $section_names]] + 1 }]
    set string_table [generate_string_header $section_names]

    # Offset and size calculations
    set strtab_string_offset [string first ".shstrtab" $string_table]

    ######### Start Writing File #########

    ### Write ELF_HEADER ###
    puts -nonewline $fp [generate_elf_header $elf_header_size $program_header_size $num_prog_headers $section_header_size $num_sections]

    # Generate Program Headers and Section Headers for memory regions
    set headers [get_headers $list_of_regions [expr { $header_size + $ptnote_size + $string_tbl_size }] $string_table]
    set program_headers [lindex $headers 0]
    set section_headers [lindex $headers 1]

    ### Write Program Headers ###

    # Write Memory Region Program Headers
    puts -nonewline $fp $program_headers

    # Generate Program header for holding registers in PT_NOTE section
    puts -nonewline $fp [generate_program_header 0x4 $header_size 0x0 0x0 $ptnote_size]

    ### Write Section Headers ###
    # Empty Section
    puts -nonewline $fp [generate_section_header 0 0 0 0 0 0 0 0 0 0]

    # Write Memory Region Sections
    puts -nonewline $fp $section_headers

    # String Table section header
    set string_table_offset [expr { $header_size + $ptnote_size }]
    # Not sure where it is documented but according to readelf flag of 0x20 corresponds to Strings
    puts -nonewline $fp [generate_section_header $strtab_string_offset 3 0x20 0 $string_table_offset $string_tbl_size 0 0 1 0]

    ### Write PT_NOTE (reg dump) ###
    puts -nonewline $fp [generate_pt_note $saved_reg_dump]

    ### Write String Table ###
    puts -nonewline $fp $string_table

    close $fp

    ### Write Core Dump ###
    dump_core $list_of_regions $CoreDumpFile

    puts ""
    puts "##########################################################"
    puts " Dump saved to file: $CoreDumpFile"
    puts "##########################################################"
    puts ""
    puts "##########################################################"
    puts " In order to do offline Coredump analysis, please use gdb "
    puts " from toolchain version                                   "
    puts " gcc-arm-11.2-2022.02-x86_64-arm-none-eabi or later       "
    puts " https://developer.arm.com/tools-and-software/            "
    puts " open-source-software/developer-tools/gnu-toolchain/      "
    puts " downloads                                                "
    puts "##########################################################"
    puts ""
}
