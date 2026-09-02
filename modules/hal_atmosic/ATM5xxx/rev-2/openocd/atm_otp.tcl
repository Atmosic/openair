# Copyright (c) 2022-2026 Atmosic
#
# SPDX-License-Identifier: LicenseRef-Atmosic
#
# Production APIs for OTP (aka: NVM, efuse) operations

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
    # Calculate byte address and bit position within that byte
    set byte_addr [expr {$bit / 8}]
    set bit_in_byte [expr {$bit % 8}]

    # Create byte value with only the target bit set
    set byte_value [expr {1 << $bit_in_byte}]

    # Program single byte using otp_program_range
    set buf {}
    lappend buf $byte_value
    otp_program_range $byte_addr 1 $buf
}

proc otp_set_bits { bits } {
    puts [format "Programming bits: %016x" $bits]
    set buf {}
    for {set i 0} {$i < $::OTP_SIZE / 8} {incr i} {
        set byte_value [expr {($bits >> ($i * 8)) & 0xFF}]
        lappend buf $byte_value
    }
    otp_program_range 0 [expr {$::OTP_SIZE / 8}] $buf
}

proc otp_program_range {address length buf {invert 0}} {
    # Read current OTP value for the target range
    set current_otp [otp_read_range $address $length]

    # Program each byte
    for {set i 0} {$i < $length} {incr i} {
        set otp_addr [expr {$address + $i}]
        set byte_value [lindex $buf $i]

        if {$invert} {
            set byte_value [expr {$byte_value ^ 0xFF}]
        }

        set current_byte [lindex $current_otp $i]
        # Clear bits in byte_value that are already programmed (set to 1) in OTP
        # Logic: new_byte_value = byte_value & (~current_byte)
        #   - Bits that are 1 in current_byte will be cleared to 0 in byte_value
        #   - Bits that are 0 in current_byte will retain value from byte_value
        # This prevents re-programming bits that are already burned
        set byte_value [expr {$byte_value & (~$current_byte)}]
        # If byte_value becomes 0, no new bits need to be programmed
        if {$byte_value == 0} { continue }

        namespace eval ::CMSDK_NVM_SECURE::OPMODE1 {
            upvar 1 otp_addr otp_addr
            upvar 1 byte_value byte_value
            mww [REG_ADDR] [expr {[OTP_A::WRITE $otp_addr] | \
                [OTP_A_MAP::WRITE $byte_value]}]
        }
        namespace eval ::CMSDK_NVM_SECURE::OPMODE {
            mww [REG_ADDR] [expr {[GO::MASK] | [PROGRAM::MASK]}]
        }
        namespace eval ::CMSDK_NVM_SECURE::STATUS {
            while {1} {
                set status [mrw [REG_ADDR]]
                if {[DONE::READ $status]} {
                    break
                }
            }
        }
    }

    return
}

proc otp_read_range {address length {invert 0}} {
    # Initialize result list
    set buf {}

    # Read each byte
    for {set i 0} {$i < $length} {incr i} {
        set otp_addr [expr {$address + $i}]
        namespace eval ::CMSDK_NVM_SECURE::OPMODE1 {
            upvar 1 otp_addr otp_addr
            mww [REG_ADDR] [OTP_A::WRITE $otp_addr]
        }
        namespace eval ::CMSDK_NVM_SECURE::OPMODE {
            mww [REG_ADDR] [expr {[GO::MASK] | [READ::MASK]}]
        }
        namespace eval ::CMSDK_NVM_SECURE::STATUS {
            while {1} {
                set status [mrw [REG_ADDR]]
                if {[DONE::READ $status]} {
                    break
                }
            }
            upvar 1 byte_value byte_value
            set byte_value [OTP_Q::READ $status]
        }

        if {$invert} {
            set byte_value [expr {$byte_value ^ 0xFF}]
        }

        lappend buf $byte_value
    }

    return $buf
}

proc otp_read_bits { start_bit num_bits } {
    if {$start_bit + $num_bits > $::OTP_SIZE} {
        set num_bits [expr { $::OTP_SIZE - $start_bit }]
    }
    set otp_list [otp_read_range 0 [expr {$::OTP_SIZE / 8}]]
    set otp 0
    for {set i 0} {$i < $::OTP_SIZE / 8} {incr i} {
        set byte_value [lindex $otp_list $i]
        set otp [expr {$otp | ($byte_value << ($i * 8))}]
    }
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

    set otp_data [otp_read_bits 0 $::OTP_SIZE]
    puts $otp_data
    set fp [open $image wb]
    for {set i 0} {$i < $::OTP_SIZE / 8} {incr i} {
        set byte [expr {($otp_data >> ($i * 8)) & 0xFF}]
        puts -nonewline $fp [binary format c $byte]
    }
    close $fp

    disable_nvm
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
