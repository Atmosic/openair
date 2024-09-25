
proc verify_si_det {} {
    enable_pseq
    namespace eval ::::CMSDK_PSEQ${::SX}::PMU_STATUS {
	if {[VBUS5DET::READ [mrw [REG_ADDR]]] != 1} {
	    error "Incompatible ATM33xx-5 part!"
	}
    }
    disable_pseq
}

proc verify_rom_version {} {
    reset halt
    namespace eval ::CMSDK_WRPR0${::SX}::CHIPREV {
	if {[MAJOR::READ [mrw [REG_ADDR]]] == 1} {
	    verify_si_det
	    return
	}
    }
    if {[mrw 0x10000cbc] == 0x4d4f5200} {
	error "Incompatible with ATM33xx-2 or ATM33xx-3 part!"
    }
    error "Not an ATM33xx-5 part!"
}
