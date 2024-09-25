proc rram_write_enable {} {
    mww [::CMSDK_WRPR0_NONSECURE::RRAM_WRITE_PROTECTION0] 0x00000000
    mww [::CMSDK_WRPR0_NONSECURE::RRAM_WRITE_PROTECTION1] 0x00000000
    mww [::CMSDK_WRPR0_NONSECURE::RRAM_WRITE_PROTECTION2] 0x00000000
    mww [::CMSDK_WRPR0_NONSECURE::RRAM_WRITE_PROTECTION3] 0x00000000
    mww [::CMSDK_WRPR0_NONSECURE::RRAM_WRITE_PROTECTION4] 0x00000000
    mww [::CMSDK_WRPR0_NONSECURE::RRAM_WRITE_PROTECTION5] 0x00000000
    mww [::CMSDK_WRPR0_NONSECURE::RRAM_WRITE_PROTECTION6] 0x00000000
    mww [::CMSDK_WRPR0_NONSECURE::RRAM_WRITE_PROTECTION7] 0x00000000
}

proc rram_write_disable {} {
    mww [::CMSDK_WRPR0_NONSECURE::RRAM_WRITE_PROTECTION0] 0xffffffff
    mww [::CMSDK_WRPR0_NONSECURE::RRAM_WRITE_PROTECTION1] 0xffffffff
    mww [::CMSDK_WRPR0_NONSECURE::RRAM_WRITE_PROTECTION2] 0xffffffff
    mww [::CMSDK_WRPR0_NONSECURE::RRAM_WRITE_PROTECTION3] 0xffffffff
    mww [::CMSDK_WRPR0_NONSECURE::RRAM_WRITE_PROTECTION4] 0xffffffff
    mww [::CMSDK_WRPR0_NONSECURE::RRAM_WRITE_PROTECTION5] 0xffffffff
    mww [::CMSDK_WRPR0_NONSECURE::RRAM_WRITE_PROTECTION6] 0xffffffff
    mww [::CMSDK_WRPR0_NONSECURE::RRAM_WRITE_PROTECTION7] 0xffffffff
}

proc atm_erase_rram { region_start region_size } {
    if { [expr { $region_size % 4 }] } {
	error "Erase size must be a multiple of 4"
    }
    puts [format "%d bytes erased at address 0x%08x" $region_size $region_start ]
    rram_write_enable
    adapter speed 70
    mww $region_start 0xffffffff [expr {$region_size / 4}]
    adapter speed $::_SWD_KHZ
    rram_write_disable
}

proc atm_erase_rram_byte { region_start region_size } {
    puts [format "%d bytes erased at address 0x%08x" $region_size $region_start ]
    rram_write_enable
    adapter speed 70
    mwb $region_start 0xff $region_size
    adapter speed $::_SWD_KHZ
    rram_write_disable
}

# Erase RRAM up to the secure journal region
proc atm_erase_rram_all { } {
    set CMSDK_SEC_JOURNAL_BASE 0x8f800
    atm_erase_rram $::CMSDK_RRAM_BASE [expr {$CMSDK_SEC_JOURNAL_BASE - $::CMSDK_RRAM_BASE}]
}

proc atm_dump_rram [list image [list len $::CMSDK_RRAM_SIZE]] {
    dump_image $image [expr {$::CMSDK_RRAM_BASE}] $len
}

proc atm_load_rram { image {address ""} } {
    rram_write_enable
    adapter speed 70
    puts "Loading [file tail $image] into RRAM"
    if {$address eq ""} {
	puts -nonewline [load_image $image]
    } else {
	puts -nonewline [load_image $image $address]
    }
    adapter speed $::_SWD_KHZ
    rram_write_disable
}

proc atm_cond_load_rram { image } {
    # go one below LOG_LVL_ERROR
    debug_level -1
    set ret [catch {verify_image_checksum  $image}]
    # restore to default (LOG_LVL_INFO)
    debug_level 2
    if {$ret} {
	atm_load_rram $image
    } else {
	puts "[file tail $image] matches. Skipping upload"
    }
}

proc atm_verify_rram { image {address ""}} {
    if {$address eq ""} {
	puts -nonewline [verify_image $image]
    } else {
	puts -nonewline [verify_image $image $address]
    }
}
