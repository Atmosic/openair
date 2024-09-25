#
# reg_wrappers.tcl
# API to access device registers
# Copyright (C) Atmosic 2020-2022
#

source [find atm_sec_jrnl.tcl]

set CHIP_INFO_TAG 0xb9

proc atm_print_part_number { pkg_opts harv_opts } {
    set is_7x7 [expr {$pkg_opts == 1}]
    set is_5x5 [expr {$pkg_opts == 2}]
    set is_csp [expr {$pkg_opts == 3}]
    set is_stacked [expr {$pkg_opts == 5}]
    set is_harv [expr {$harv_opts == 1}]

    puts [format "ATM33%s-5 silicon: %s pkg" \
	[expr {$is_harv ? "30e": ($is_7x7 ? "30" : "25")}] \
	[expr {$is_5x5 ? "5x5" : ($is_csp ? "CSP" : \
	($is_stacked ? "5x5 stacked" : "7x7"))}]]
}

proc atm_setup_7x7 {} {
    mww [::CMSDK_WRPR0_NONSECURE::PSEL_E] 0x04030000
    mww [::CMSDK_WRPR0_NONSECURE::PSEL_F] 0x08070605
}

proc atm_setup_5x5 {} {
    mww [::CMSDK_WRPR0_NONSECURE::PSEL_E] 0x04030800
    mww [::CMSDK_WRPR0_NONSECURE::PSEL_F] 0x00070605
}

proc atm_setup_csp {} {
    mww [::CMSDK_WRPR0_NONSECURE::PSEL_E] 0x04030800
    mww [::CMSDK_WRPR0_NONSECURE::PSEL_F] 0x00070605
}

proc atm_setup_5x5_stacked {} {
    mww [::CMSDK_WRPR0_NONSECURE::PSEL_A] 0x00050201
    mww [::CMSDK_WRPR0_NONSECURE::PSEL_B] 0x00030000
    mww [::CMSDK_WRPR0_NONSECURE::PSEL_D] 0x06000400
    mww [::CMSDK_WRPR0_NONSECURE::PSEL_E] 0x00000007
    mww [::CMSDK_WRPR0_NONSECURE::PSEL_F] 0x08000000
}

# chip_info_header: 8btag, 8bstatus, 8blength
# chip_info: 16bversions, 8bpackage, 8bharvesting
# get chip package. Return: 1=7x7, 2=5x5, 3=CSP, 5=5x5_stacked
proc get_chip_package {} {
    set chip_info_header [ atm_sec_jrnl_find_tag  $::CHIP_INFO_TAG ]
    # default to 7x7 if tag not found
    if {$chip_info_header == -1} {
	return -1
    }

    set chip_package [expr [mrb [expr {$chip_info_header + 5}]]]
    set chip_harvesting [expr [mrb [expr {$chip_info_header + 6}]]]
    return [list $chip_package $chip_harvesting]

}

proc setup_pkg_config {} {
    set result [get_chip_package]
    set pkg_opts [lindex $result 0]
    set harv_opts [lindex $result 1]

    # Only matches if decimal int, won't match on hex int
    switch -- $pkg_opts {
	1 { atm_setup_7x7 }
	2 { atm_setup_5x5 }
	3 { atm_setup_csp }
	5 { atm_setup_5x5_stacked }
	default {
	    atm_setup_7x7; puts "Invalid package option ($pkg_opts). Default to 7x7 package setup.";
	    set pkg_opts 1
	    set harv_opts 1
	}
    }
    atm_print_part_number $pkg_opts $harv_opts
}

#
# SPI
#

array set SPI0 {
    clkdiv	3
    dummy	0
}
set SPI0(ns)			"CMSDK_SPI0_NONSECURE"
set SPI0(base)			[::CMSDK_SPI0_NONSECURE::BASE]

array set SPI1 {
    clkdiv	3
    dummy	0
}
set SPI1(ns)			"CMSDK_SPI1_NONSECURE"
set SPI1(base)			[::CMSDK_SPI1_NONSECURE::BASE]

array set SPI2 {
    clkdiv	3
    dummy	0
}
set SPI2(ns)			"CMSDK_SPI2_NONSECURE"
set SPI2(base)			[::CMSDK_SPI2_NONSECURE::BASE]

array set RADIO {
    clkdiv	0
    dummy	3
}
set RADIO(ns)			"CMSDK_RADIO_NONSECURE"
set RADIO(base)			[::CMSDK_RADIO_NONSECURE::BASE]

array set PMU {
    clkdiv	0
    dummy	3
}
set PMU(ns)			"CMSDK_PMU_NONSECURE"
set PMU(base)			[::CMSDK_PMU_NONSECURE::BASE]
