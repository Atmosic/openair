#
# reg_wrappers.tcl
# API to access device registers
# Copyright (C) Atmosic 2020-2025
#

source [find atm_sec_jrnl.tcl]

proc atm_print_part_number { pkg_opts } {
    switch -- $pkg_opts {
	2 {
	    set is_7x7 0
	    set is_5x5 1
	    set is_stacked 0
	}
	5 {
	    set is_7x7 0
	    set is_5x5 1
	    set is_stacked 1
	}
	6 {
	    set is_7x7 1
	    set is_5x5 0
	    set is_stacked 1
	}
	7 {
	    set is_7x7 0
	    set is_5x5 0
	    set is_stacked 1
	}
	8 {
	    set is_7x7 0
	    set is_5x5 0
	    set is_stacked 0
	}
    }

    puts [format "ATM34%s-5 silicon: %s%s pkg" \
	[expr {$is_7x7 ? "30/e" : "05"}] \
	[expr {$is_7x7 ? "7x7" : [expr {$is_5x5 ? "5x5" : "BGA"}]}] \
	[expr {$is_stacked ? " stacked" : ""}]]
}

proc atm_setup_ext_flash {} {
    mww [::CMSDK_WRPR0_NONSECURE::PSEL_E] 0x04030800
    mww [::CMSDK_WRPR0_NONSECURE::PSEL_F] 0x00070605
    mww [::CMSDK_WRPR0_NONSECURE::PUPD_OVRD_VAL] 0x00420000
    mww [::CMSDK_WRPR0_NONSECURE::PUPD_OVRD] 0x00420000
}

proc atm_setup_stacked_flash {} {
    mww [::CMSDK_WRPR0_NONSECURE::PSEL_H] 0x04000000
    mww [::CMSDK_WRPR0_NONSECURE::PSEL_J] 0x03050706
    mww [::CMSDK_WRPR0_NONSECURE::PSEL_K] 0x00000008
    mww [::CMSDK_WRPR0_NONSECURE::PUPD_OVRD] 0x00000000
    mww [::CMSDK_WRPR0_NONSECURE::PUPD_OVRD2] 0x00000012
}

proc get_chip_package {} {
    # CHIP_INFO tag ID = 0xb9
    set chip_info_header [ atm_sec_jrnl_find_tag 0xb9 ]
    if {$chip_info_header == -1} {
	return -1
    }

    # header = 3 bytes, version = 2 bytes, package = 1 byte
    set chip_package [expr [mrb [expr {$chip_info_header + 5}]]]
    return $chip_package
}

proc setup_pkg_config {} {
    set pkg_opts [ get_chip_package ]

    # Only matches if decimal int, won't match on hex int
    switch -- $pkg_opts {
	2 { atm_setup_ext_flash }
	5 { atm_setup_stacked_flash }
	6 { atm_setup_stacked_flash }
	7 { atm_setup_stacked_flash }
	8 { atm_setup_ext_flash }
	default {
	    puts "Invalid package option ($pkg_opts). Default to 7x7 stacked package setup."
	    atm_setup_stacked_flash
	    set pkg_opts 6
	}
    }
    atm_print_part_number $pkg_opts
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
