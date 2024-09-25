#
# atm2x_pseq.tcl
# Production APIs for PSEQ operations
# Copyright (C) Atmosic 2018-2019
#

proc enable_hpc {} {
    global CMSDK_PSEQ_XTAL_BITS1

    enable_pseq
    set xb1 [mrw $CMSDK_PSEQ_XTAL_BITS1]
    mww $CMSDK_PSEQ_XTAL_BITS1 [expr {$xb1 | (1 << 19)}]
    disable_pseq
}

proc disable_hpc {} {
    global CMSDK_PSEQ_XTAL_BITS1

    enable_pseq
    set xb1 [mrw $CMSDK_PSEQ_XTAL_BITS1]
    mww $CMSDK_PSEQ_XTAL_BITS1 [expr {$xb1 & ~(1 << 19)}]
    disable_pseq
}

proc enable_emram {} {
    global CMSDK_PSEQ_EMRAM_OVERRIDES
    global CMSDK_PSEQ_EMRAM_OVERRIDES2
    global CMSDK_PSEQ_EMRAM_OVERRIDES3
    global CMSDK_PSEQ_EMRAM_OVERRIDES4
    global CMSDK_PSEQ_EMRAM_OVERRIDES5
    global CMSDK_PSEQ_EMRAM_OVERRIDES6

    enable_pseq
    mww $CMSDK_PSEQ_EMRAM_OVERRIDES 0
    mww $CMSDK_PSEQ_EMRAM_OVERRIDES6 0
    mww $CMSDK_PSEQ_EMRAM_OVERRIDES5 0
    mww $CMSDK_PSEQ_EMRAM_OVERRIDES4 0
    mww $CMSDK_PSEQ_EMRAM_OVERRIDES3 0
    mww $CMSDK_PSEQ_EMRAM_OVERRIDES2 0
}

proc enable_uram {} {
    global CMSDK_PSEQ_SYSRAM_OVERRIDES
    global CMSDK_PSEQ_SYSRAM_OVERRIDES2
    global CMSDK_PSEQ_SYSRAM_OVERRIDES3
    global CMSDK_PSEQ_SYSRAM_OVERRIDES4
    global CMSDK_PSEQ_SYSRAM_OVERRIDES5
    global CMSDK_PSEQ_SYSRAM_OVERRIDES6

    enable_pseq
    mww $CMSDK_PSEQ_SYSRAM_OVERRIDES 0
    mww $CMSDK_PSEQ_SYSRAM_OVERRIDES6 0
    mww $CMSDK_PSEQ_SYSRAM_OVERRIDES5 0
    mww $CMSDK_PSEQ_SYSRAM_OVERRIDES4 0
    mww $CMSDK_PSEQ_SYSRAM_OVERRIDES3 0
    mww $CMSDK_PSEQ_SYSRAM_OVERRIDES2 0
}
