#
# atm2x_gdb.tcl
# GDB helper functions for ATM2x devices
# Copyright (C) Atmosic 2020
#

# Fully reset target device and halt at first instruction.
# (gdb) monitor reset_hard_halt
proc reset_hard_halt {} {
    set_benign_boot
    reset_hard
    set_normal_boot
    reset halt

    # Undo what ROM benign boot might have done to OVERRIDES reg
    enable_pseq
    namespace eval ::CMSDK_PSEQ_NONSECURE::OVERRIDES {
	mww [REG_ADDR] [RESET_VALUE]
    }
    disable_pseq

    cti_on
}
