# Copyright (c) 2022-2026 Atmosic
#
# SPDX-License-Identifier: LicenseRef-Atmosic
#
# Provide secure journal NVDS functions

set CMSDK_SEC_JOURNAL_OFFSET 0x1000
set CMSDK_SEC_JOURNAL_BASE [expr {$::CMSDK_FLASH_BASE + $::CMSDK_SEC_JOURNAL_OFFSET}]
set CMSDK_SEC_JOURNAL_SIZE 4096

proc atm_erase_sec_jrnl_nvds { } {
    atm_erase_flash $::CMSDK_SEC_JOURNAL_SIZE $::CMSDK_SEC_JOURNAL_OFFSET
}

proc atm_dump_sec_jrnl_nvds { image } {
    atm_dump_flash $image $::CMSDK_SEC_JOURNAL_SIZE $::CMSDK_SEC_JOURNAL_BASE
}

proc atm_load_sec_jrnl_nvds { image } {
    atm_load_flash $image $::CMSDK_SEC_JOURNAL_OFFSET \
        $::CMSDK_SEC_JOURNAL_SIZE $::CMSDK_SEC_JOURNAL_BASE
}

proc atm_verify_sec_jrnl_nvds { image } {
    atm_verify_flash $image $::CMSDK_SEC_JOURNAL_BASE
}

set OTP_STORAGE_BASE 0
set OTP_STORAGE_SIZE 512
set CMSDK_SEC_JOURNAL_OTP_BASE [expr {$::OTP_STORAGE_BASE + ($::OTP_SIZE / 8)}]
set CMSDK_SEC_JOURNAL_OTP_SIZE [expr {$::OTP_STORAGE_SIZE - ($::OTP_SIZE / 8)}]

proc atm_dump_sec_jrnl_otp { image } {
    reset halt
    enable_nvm

    set buf [otp_read_range $::CMSDK_SEC_JOURNAL_OTP_BASE $::CMSDK_SEC_JOURNAL_OTP_SIZE 1]
    puts $buf
    set fp [open $image wb]
    for {set i 0} {$i < $::CMSDK_SEC_JOURNAL_OTP_SIZE} {incr i} {
        set byte [lindex $buf $i]
        puts -nonewline $fp [binary format c $byte]
    }
    close $fp

    disable_nvm
}

proc atm_load_sec_jrnl_otp { image } {
    set img_size [file size $image]
    if {$img_size > $::CMSDK_SEC_JOURNAL_OTP_SIZE} {
        error "Unable to load: image size ($img_size) exceeds OTP journal size\
               ($::CMSDK_SEC_JOURNAL_OTP_SIZE)"
    }
    if {$img_size < $::CMSDK_SEC_JOURNAL_OTP_SIZE} {
        puts "WARNING: image size ($img_size) is smaller than OTP journal size\
              ($::CMSDK_SEC_JOURNAL_OTP_SIZE), only $img_size bytes will be written."
    }
    set write_size $img_size

    set fp [open $image rb]
    set buf {}
    for {set i 0} {$i < $write_size} {incr i} {
        binary scan [read $fp 1] cu byte_value
        lappend buf $byte_value
    }
    close $fp

    reset halt
    enable_nvm

    otp_program_range $::CMSDK_SEC_JOURNAL_OTP_BASE $write_size $buf 1

    disable_nvm
}
