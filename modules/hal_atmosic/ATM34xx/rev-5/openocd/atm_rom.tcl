
proc verify_rom_version {} {
    reset halt
    namespace eval ::CMSDK_WRPR0${::SX}::CHIPREV {
        if {[MAJOR::READ [mrw [REG_ADDR]]] == 2} {
            return
        } elseif {[MAJOR::READ [mrw [REG_ADDR]]] == 1} {
	    error "Incompatible with ATM34xx-2 part!"
        }
    }
    error "Not an ATM34xx-5 part!"
}
