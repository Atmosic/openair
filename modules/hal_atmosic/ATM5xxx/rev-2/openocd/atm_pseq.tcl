#
# atm_pseq.tcl
# Production APIs for PSEQ operations
# Copyright (C) Atmosic 2018-2022
#

proc enable_hpc {} {
    namespace eval ::CMSDK_CLKRSTGEN${::SX}::XTAL_BITS1 {
	CLKHPC_EN::SET_TGT [REG_ADDR]
    }
}

proc disable_hpc {} {
    namespace eval ::CMSDK_CLKRSTGEN${::SX}::XTAL_BITS1 {
	CLKHPC_EN::CLR_TGT [REG_ADDR]
    }
}

proc enable_emram {} {
    enable_pseq
    mww [::CMSDK_PSEQ${::SX}::EMRAM_OVERRIDES] 0
    mww [::CMSDK_PSEQ${::SX}::EMRAM_OVERRIDES6] 0
    mww [::CMSDK_PSEQ${::SX}::EMRAM_OVERRIDES5] 0
    mww [::CMSDK_PSEQ${::SX}::EMRAM_OVERRIDES4] 0
    mww [::CMSDK_PSEQ${::SX}::EMRAM_OVERRIDES3] 0
    mww [::CMSDK_PSEQ${::SX}::EMRAM_OVERRIDES2] 0
}

proc enable_uram {} {
    enable_pseq
    mww [::CMSDK_PSEQ${::SX}::SYSRAM_OVERRIDES] 0
    mww [::CMSDK_PSEQ${::SX}::SYSRAM_OVERRIDES6] 0
    mww [::CMSDK_PSEQ${::SX}::SYSRAM_OVERRIDES5] 0
    mww [::CMSDK_PSEQ${::SX}::SYSRAM_OVERRIDES4] 0
    mww [::CMSDK_PSEQ${::SX}::SYSRAM_OVERRIDES3] 0
    mww [::CMSDK_PSEQ${::SX}::SYSRAM_OVERRIDES2] 0
}
