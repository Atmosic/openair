#
# atm_otp.tcl
# Production APIs for OTP (aka: NVM, efuse) operations
# Copyright (C) Atmosic 2022
#

#
# OTP
#

set OTP_SIZE 64

set OTP {
    OTP_NABG_TRIM_LATCH
    OTP_USE_LDO_LATCH
    OTP_DISABLE_CHPU_LATCH
    OTP_HARV_DISABLED_LATCH
    OTP_RECT_CTUNE_LATCH
    OTP_INTERNAL_SPARE_LATCH
    OTP_DISABLE_XTAL32K_LATCH
    OTP_NOIND_LATCH
    OTP_DISABLE_VDDIOGEN_LATCH
    OTP_DISABLE_VDDGEN_LATCH
    OTP_DISABLE_5V_LATCH
    OTP_VBATT_LEVEL_LATCH
    OTP_BATT_TYPE_LATCH
    OTP_VBATT_GOOD_LATCH
    OTP_VBATT_BROWNOUT_LATCH
    OTP_MPPT_TYPE_LATCH
    OTP_DISABLE_RFHARV_LATCH
    OTP_VHARV_START_LATCH
    OTP_VSTORE_GOOD_LATCH
    OTP_VSTORE_MAX_LATCH
    OTP_RRAM_WRITE_LOCK
    OTP_SEC_DBG_CONFIG
    OTP_RRAM_JTAG_BYPASS
}

set OTP_BIT(OTP_NABG_TRIM_LATCH) 0
set OTP_LEN(OTP_NABG_TRIM_LATCH) 9

set OTP_BIT(OTP_USE_LDO_LATCH) 9
set OTP_LEN(OTP_USE_LDO_LATCH) 1

set OTP_BIT(OTP_DISABLE_CHPU_LATCH) 10
set OTP_LEN(OTP_DISABLE_CHPU_LATCH) 1

set OTP_BIT(OTP_HARV_DISABLED_LATCH) 11
set OTP_LEN(OTP_HARV_DISABLED_LATCH) 1

set OTP_BIT(OTP_RECT_CTUNE_LATCH) 12
set OTP_LEN(OTP_RECT_CTUNE_LATCH) 3

set OTP_BIT(OTP_INTERNAL_SPARE_LATCH) 15
set OTP_LEN(OTP_INTERNAL_SPARE_LATCH) 4

set OTP_BIT(OTP_DISABLE_XTAL32K_LATCH) 19
set OTP_LEN(OTP_DISABLE_XTAL32K_LATCH) 1

set OTP_BIT(OTP_NOIND_LATCH) 20
set OTP_LEN(OTP_NOIND_LATCH) 1

set OTP_BIT(OTP_DISABLE_VDDIOGEN_LATCH) 21
set OTP_LEN(OTP_DISABLE_VDDIOGEN_LATCH) 1

set OTP_BIT(OTP_DISABLE_VDDGEN_LATCH) 22
set OTP_LEN(OTP_DISABLE_VDDGEN_LATCH) 1

set OTP_BIT(OTP_DISABLE_5V_LATCH) 23
set OTP_LEN(OTP_DISABLE_5V_LATCH) 1

set OTP_BIT(OTP_VBATT_LEVEL_LATCH) 24
set OTP_LEN(OTP_VBATT_LEVEL_LATCH) 1

set OTP_BIT(OTP_BATT_TYPE_LATCH) 25
set OTP_LEN(OTP_BATT_TYPE_LATCH) 2

set OTP_BIT(OTP_VBATT_GOOD_LATCH) 27
set OTP_LEN(OTP_VBATT_GOOD_LATCH) 3

set OTP_BIT(OTP_VBATT_BROWNOUT_LATCH) 30
set OTP_LEN(OTP_VBATT_BROWNOUT_LATCH) 7

set OTP_BIT(OTP_MPPT_TYPE_LATCH) 37
set OTP_LEN(OTP_MPPT_TYPE_LATCH) 2

set OTP_BIT(OTP_DISABLE_RFHARV_LATCH) 39
set OTP_LEN(OTP_DISABLE_RFHARV_LATCH) 1

set OTP_BIT(OTP_VHARV_START_LATCH) 40
set OTP_LEN(OTP_VHARV_START_LATCH) 2

set OTP_BIT(OTP_VSTORE_GOOD_LATCH) 42
set OTP_LEN(OTP_VSTORE_GOOD_LATCH) 2

set OTP_BIT(OTP_VSTORE_MAX_LATCH) 44
set OTP_LEN(OTP_VSTORE_MAX_LATCH) 3

set OTP_BIT(OTP_SPARE_LATCH) 47
set OTP_LEN(OTP_SPARE_LATCH) 1

set OTP_BIT(OTP_RRAM_WRITE_LOCK) 48
set OTP_LEN(OTP_RRAM_WRITE_LOCK) 7

set OTP_BIT(OTP_SPARE_2_LATCH) 55
set OTP_LEN(OTP_SPARE_2_LATCH) 1

set OTP_BIT(OTP_RESERVED_1) 56
set OTP_LEN(OTP_RESERVED_1) 4

set OTP_BIT(OTP_SEC_DBG_CONFIG) 60
set OTP_LEN(OTP_SEC_DBG_CONFIG) 2

set OTP_BIT(OTP_RRAM_JTAG_BYPASS) 62
set OTP_LEN(OTP_RRAM_JTAG_BYPASS) 1

set OTP_RRAM_WRITE_LOCK(BOOT_BLOCK_0) 48
set OTP_RRAM_WRITE_LOCK(BOOT_BLOCK_1) 49
set OTP_RRAM_WRITE_LOCK(BOOT_BLOCK_2) 50
set OTP_RRAM_WRITE_LOCK(BOOT_BLOCK_3) 51
set OTP_RRAM_WRITE_LOCK(PROTECTED_DATA) 52
set OTP_RRAM_WRITE_LOCK(SECURE_COUNTERS) 53
set OTP_RRAM_WRITE_LOCK(PRIVATE_KEY_STORAGE) 54

set OTP_SEC_DBG(DEBUG_DISABLED) 60
set OTP_SEC_DBG(DEBUG_SECURED) 61

# Helper functions

proc otp_set_bit { bit } {
    mww [::CMSDK_NVM_SECURE::CTRL::REG_ADDR] \
        [::CMSDK_NVM_SECURE::CTRL::NUM_PGM_BIT::WRITE [expr { $bit + 1 }]]

    namespace eval ::CMSDK_NVM_SECURE::OPMODE {
        mww [REG_ADDR] [expr {[GO::MASK] | [PROGRAM::MASK]}]
    }
    namespace eval ::CMSDK_NVM_SECURE::STATUS {
	while {([mrw [REG_ADDR]] & [RUNNING::MASK]) == [RUNNING::MASK]} {}
    }
}

proc otp_set_bits { bits } {
    mww [::CMSDK_NVM_SECURE::CTRL::REG_ADDR] \
        [expr {[::CMSDK_NVM_SECURE::CTRL::NUM_PGM_BIT::WRITE $::OTP_SIZE] | \
        [::CMSDK_NVM_SECURE::CTRL::BURST_MODE::MASK]}]
    puts [format "Programming bits: %016x" $bits]
    set d0 [expr { $bits & ((1 << 32) - 1) }]
    set d1 [expr { ($bits >> 32) & ((1 << 32) - 1) }]
    mww [::CMSDK_NVM_SECURE::DATA0::REG_ADDR] $d0
    mww [::CMSDK_NVM_SECURE::DATA1::REG_ADDR] $d1
    namespace eval ::CMSDK_NVM_SECURE::OPMODE {
        mww [REG_ADDR] [expr {[GO::MASK] | [PROGRAM::MASK]}]
    }
    namespace eval ::CMSDK_NVM_SECURE::STATUS {
	while {([mrw [REG_ADDR]] & [RUNNING::MASK]) == [RUNNING::MASK]} {}
    }
}

proc otp_read_bits { start_bit num_bits } {
    if {$start_bit + $num_bits > $::OTP_SIZE} {
        set num_bits [expr { $::OTP_SIZE - $start_bit }]
    }
    namespace eval ::CMSDK_NVM_SECURE::OPMODE {
        mww [REG_ADDR] [expr {[GO::MASK] | [READ::MASK]}]
    }
    namespace eval ::CMSDK_NVM_SECURE::STATUS {
	while {([mrw [REG_ADDR]] & [RUNNING::MASK]) == [RUNNING::MASK]} {}
    }
    set data0 [mrw [::CMSDK_NVM_SECURE::DATA0]]
    set data1 [mrw [::CMSDK_NVM_SECURE::DATA1]]
    set otp [expr { ($data1 << 32) | $data0 }]
    if {$num_bits == 64} {
        # special case, (1 << 64) - 1 doesn't mask with &
        return $otp
    } else {
        return [expr { ($otp >> $start_bit) & ((1 << $num_bits) - 1) }]
    }
}

proc otp_read { } {
    return [otp_read_bits 0 $::OTP_SIZE]
}

# public api to burn a single bit

proc otp_burn_bit { bit } {
    reset halt
    enable_nvm

    otp_set_bit $bit

    disable_nvm
}


# public api to read a single bit

proc otp_read_bit { bit } {
    # Don't reset since we're only reading
    enable_nvm

    set otp_bit [otp_read_bits $bit 1]

    disable_nvm
    return [expr {!!$otp_bit}]
}

# public api operating on full 64 bit input

proc otp_burn { value } {
    reset halt
    enable_nvm

    otp_set_bits $value

    disable_nvm
}

proc otp_precheck { value } {
    reset halt
    enable_nvm

    set burned [otp_read]
    if {($burned & $value) != $burned} {
        error [format "ERROR: bit cleared %016x->%016x" $burned $value]
    }

    disable_nvm
    return "OK"
}

proc otp_verify { value } {
    reset halt
    enable_nvm

    set burned [otp_read]
    if {$burned != $value} {
        error [format "ERROR: difference: %016x-%016x" $burned $value]
    }

    disable_nvm
}

# dump otp to a file

proc otp_dump_image { image } {
    reset halt
    enable_nvm

    puts [otp_read_bits 0 $::OTP_SIZE]
    dump_image $image [::CMSDK_NVM_SECURE::DATA0] [expr {$::OTP_SIZE / 8}]
}

# Print otp in a human readable format

proc otp_print { } {
    reset halt
    enable_nvm

    puts [format "OTP: 0x%016x" [otp_read_bits 0 $::OTP_SIZE]]
    foreach v $::OTP {
        set len $::OTP_LEN($v)
        set bits [otp_read_bits $::OTP_BIT($v) $len]
        set hex_digits [expr { ($len + 3) / 4 }]
        puts [format "${v}: 0b%0${len}b, 0x%0${hex_digits}x" $bits $bits]
    }

    disable_nvm
}

# security api

proc burn_rram_jtag_bypass { } {
    reset halt
    enable_nvm

    otp_set_bit $::OTP_BIT(OTP_RRAM_JTAG_BYPASS)

    disable_nvm
}

proc burn_sec_dbg_config { type } {
    reset halt
    enable_nvm

    otp_set_bit $::OTP_SEC_DBG($type)

    disable_nvm
}

proc burn_rram_write_lock { region } {
    reset halt
    enable_nvm

    otp_set_bit $::OTP_RRAM_WRITE_LOCK($region)

    disable_nvm
    reset_hard
}
