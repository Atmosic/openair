namespace eval CMSDK_SWREG_AON {
    namespace export BASE
    proc BASE {} {
        return 0xe1000000
    }
    namespace export AON0
    proc AON0 { {base [::CMSDK_SWREG_AON::BASE]} } {
        return [expr { [expr $base] + 0x0 }]
    }
    namespace eval AON0 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_SWREG_AON::BASE]} } {
            return [expr { [expr $base] + 0x0 }]
        }
        namespace eval CLKFIXEDMAIN_SH {
            namespace export SHIFT
            proc SHIFT {} {
                return 0
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 4
            }
            namespace export MASK
            proc MASK {} {
                return 0x0000000f
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x0000000f) >> 0}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 0) & 0x0000000f}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x0000000f) | (($field_val << 0) & 0x0000000f)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x0000000f) | (($field_val << 0) & 0x0000000f)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 0) & ~0x0000000f)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000003
            }
        }
        namespace eval CLKFIXEDSIMPLE_SH {
            namespace export SHIFT
            proc SHIFT {} {
                return 4
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 4
            }
            namespace export MASK
            proc MASK {} {
                return 0x000000f0
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x000000f0) >> 4}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 4) & 0x000000f0}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x000000f0) | (($field_val << 4) & 0x000000f0)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x000000f0) | (($field_val << 4) & 0x000000f0)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 4) & ~0x000000f0)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000006
            }
        }
        namespace eval CLKFIXEDTINY_SH {
            namespace export SHIFT
            proc SHIFT {} {
                return 8
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 4
            }
            namespace export MASK
            proc MASK {} {
                return 0x00000f00
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00000f00) >> 8}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 8) & 0x00000f00}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00000f00) | (($field_val << 8) & 0x00000f00)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00000f00) | (($field_val << 8) & 0x00000f00)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 8) & ~0x00000f00)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000006
            }
        }
        namespace eval SKIPSAMPLE_SH {
            namespace export SHIFT
            proc SHIFT {} {
                return 12
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 1
            }
            namespace export MASK
            proc MASK {} {
                return 0x00001000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00001000) >> 12}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 12) & 0x00001000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00001000) | (($field_val << 12) & 0x00001000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00001000) | (($field_val << 12) & 0x00001000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 12) & ~0x00001000)}]
            }
            namespace export SET
            proc SET {var_name} {
                upvar $var_name var
                set var [expr {($var & ~0x00001000) | (1 << 12)}]
            }
            namespace export SET_TGT
            proc SET_TGT {addr} {
                mww $addr [expr {([mrw $addr] & ~0x00001000) | (1 << 12)}]
            }
            namespace export CLR
            proc CLR {var_name} {
                upvar $var_name var
                set var [expr {$var & ~0x00001000}]
            }
            namespace export CLR_TGT
            proc CLR_TGT {addr} {
                mww $addr [expr {[mrw $addr] & ~0x00001000}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000001
            }
        }
        namespace eval TIMESTEPSETTLETARGET_SH {
            namespace export SHIFT
            proc SHIFT {} {
                return 13
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 3
            }
            namespace export MASK
            proc MASK {} {
                return 0x0000e000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x0000e000) >> 13}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 13) & 0x0000e000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x0000e000) | (($field_val << 13) & 0x0000e000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x0000e000) | (($field_val << 13) & 0x0000e000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 13) & ~0x0000e000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000001
            }
        }
        namespace eval TIMESTEPSTEPUP_SH {
            namespace export SHIFT
            proc SHIFT {} {
                return 16
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 3
            }
            namespace export MASK
            proc MASK {} {
                return 0x00070000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00070000) >> 16}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 16) & 0x00070000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00070000) | (($field_val << 16) & 0x00070000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00070000) | (($field_val << 16) & 0x00070000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 16) & ~0x00070000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000003
            }
        }
        namespace eval TIMESTEPSTEPDN_SH {
            namespace export SHIFT
            proc SHIFT {} {
                return 19
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 3
            }
            namespace export MASK
            proc MASK {} {
                return 0x00380000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00380000) >> 19}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 19) & 0x00380000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00380000) | (($field_val << 19) & 0x00380000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00380000) | (($field_val << 19) & 0x00380000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 19) & ~0x00380000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval TIMEAFTERDUMP_SH {
            namespace export SHIFT
            proc SHIFT {} {
                return 22
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 4
            }
            namespace export MASK
            proc MASK {} {
                return 0x03c00000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x03c00000) >> 22}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 22) & 0x03c00000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x03c00000) | (($field_val << 22) & 0x03c00000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x03c00000) | (($field_val << 22) & 0x03c00000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 22) & ~0x03c00000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000001
            }
        }
        namespace eval INDCURRENTHISTORYLENGTH_SH {
            namespace export SHIFT
            proc SHIFT {} {
                return 26
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 2
            }
            namespace export MASK
            proc MASK {} {
                return 0x0c000000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x0c000000) >> 26}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 26) & 0x0c000000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x0c000000) | (($field_val << 26) & 0x0c000000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x0c000000) | (($field_val << 26) & 0x0c000000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 26) & ~0x0c000000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000002
            }
        }
        namespace eval ENABLEHARV2SUPFIRST_SH {
            namespace export SHIFT
            proc SHIFT {} {
                return 28
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 1
            }
            namespace export MASK
            proc MASK {} {
                return 0x10000000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x10000000) >> 28}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 28) & 0x10000000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x10000000) | (($field_val << 28) & 0x10000000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x10000000) | (($field_val << 28) & 0x10000000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 28) & ~0x10000000)}]
            }
            namespace export SET
            proc SET {var_name} {
                upvar $var_name var
                set var [expr {($var & ~0x10000000) | (1 << 28)}]
            }
            namespace export SET_TGT
            proc SET_TGT {addr} {
                mww $addr [expr {([mrw $addr] & ~0x10000000) | (1 << 28)}]
            }
            namespace export CLR
            proc CLR {var_name} {
                upvar $var_name var
                set var [expr {$var & ~0x10000000}]
            }
            namespace export CLR_TGT
            proc CLR_TGT {addr} {
                mww $addr [expr {[mrw $addr] & ~0x10000000}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000001
            }
        }
        namespace eval MPPTFULLSETTLING_SH {
            namespace export SHIFT
            proc SHIFT {} {
                return 29
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 1
            }
            namespace export MASK
            proc MASK {} {
                return 0x20000000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x20000000) >> 29}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 29) & 0x20000000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x20000000) | (($field_val << 29) & 0x20000000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x20000000) | (($field_val << 29) & 0x20000000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 29) & ~0x20000000)}]
            }
            namespace export SET
            proc SET {var_name} {
                upvar $var_name var
                set var [expr {($var & ~0x20000000) | (1 << 29)}]
            }
            namespace export SET_TGT
            proc SET_TGT {addr} {
                mww $addr [expr {([mrw $addr] & ~0x20000000) | (1 << 29)}]
            }
            namespace export CLR
            proc CLR {var_name} {
                upvar $var_name var
                set var [expr {$var & ~0x20000000}]
            }
            namespace export CLR_TGT
            proc CLR_TGT {addr} {
                mww $addr [expr {[mrw $addr] & ~0x20000000}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x18433663
        }
    }
    namespace export AON1
    proc AON1 { {base [::CMSDK_SWREG_AON::BASE]} } {
        return [expr { [expr $base] + 0x4 }]
    }
    namespace eval AON1 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_SWREG_AON::BASE]} } {
            return [expr { [expr $base] + 0x4 }]
        }
        namespace eval MPPTSETTLINGTIMEOUTCOEF_SH {
            namespace export SHIFT
            proc SHIFT {} {
                return 0
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 5
            }
            namespace export MASK
            proc MASK {} {
                return 0x0000001f
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x0000001f) >> 0}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 0) & 0x0000001f}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x0000001f) | (($field_val << 0) & 0x0000001f)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x0000001f) | (($field_val << 0) & 0x0000001f)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 0) & ~0x0000001f)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x0000000f
            }
        }
        namespace eval TIMEDUMPTARGET_DVDD_SH {
            namespace export SHIFT
            proc SHIFT {} {
                return 5
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 7
            }
            namespace export MASK
            proc MASK {} {
                return 0x00000fe0
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00000fe0) >> 5}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 5) & 0x00000fe0}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00000fe0) | (($field_val << 5) & 0x00000fe0)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00000fe0) | (($field_val << 5) & 0x00000fe0)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 5) & ~0x00000fe0)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000032
            }
        }
        namespace eval TIMEDUMPTARGET_VAUX_SH {
            namespace export SHIFT
            proc SHIFT {} {
                return 12
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 7
            }
            namespace export MASK
            proc MASK {} {
                return 0x0007f000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x0007f000) >> 12}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 12) & 0x0007f000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x0007f000) | (($field_val << 12) & 0x0007f000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x0007f000) | (($field_val << 12) & 0x0007f000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 12) & ~0x0007f000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x0000000a
            }
        }
        namespace eval TIMEDUMPTARGET_VDDIO_SH {
            namespace export SHIFT
            proc SHIFT {} {
                return 19
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 7
            }
            namespace export MASK
            proc MASK {} {
                return 0x03f80000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x03f80000) >> 19}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 19) & 0x03f80000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x03f80000) | (($field_val << 19) & 0x03f80000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x03f80000) | (($field_val << 19) & 0x03f80000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 19) & ~0x03f80000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000015
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x00a8a64f
        }
    }
    namespace export AON2
    proc AON2 { {base [::CMSDK_SWREG_AON::BASE]} } {
        return [expr { [expr $base] + 0x8 }]
    }
    namespace eval AON2 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_SWREG_AON::BASE]} } {
            return [expr { [expr $base] + 0x8 }]
        }
        namespace eval TIMEDUMPTARGET_AVDD_SH {
            namespace export SHIFT
            proc SHIFT {} {
                return 0
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 7
            }
            namespace export MASK
            proc MASK {} {
                return 0x0000007f
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x0000007f) >> 0}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 0) & 0x0000007f}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x0000007f) | (($field_val << 0) & 0x0000007f)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x0000007f) | (($field_val << 0) & 0x0000007f)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 0) & ~0x0000007f)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000032
            }
        }
        namespace eval TIMETARGETHARV2STORE_SH {
            namespace export SHIFT
            proc SHIFT {} {
                return 7
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 7
            }
            namespace export MASK
            proc MASK {} {
                return 0x00003f80
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00003f80) >> 7}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 7) & 0x00003f80}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00003f80) | (($field_val << 7) & 0x00003f80)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00003f80) | (($field_val << 7) & 0x00003f80)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 7) & ~0x00003f80)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x0000001e
            }
        }
        namespace eval TARGETISDUMPHARV2STORE_SH {
            namespace export SHIFT
            proc SHIFT {} {
                return 14
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 1
            }
            namespace export MASK
            proc MASK {} {
                return 0x00004000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00004000) >> 14}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 14) & 0x00004000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00004000) | (($field_val << 14) & 0x00004000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00004000) | (($field_val << 14) & 0x00004000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 14) & ~0x00004000)}]
            }
            namespace export SET
            proc SET {var_name} {
                upvar $var_name var
                set var [expr {($var & ~0x00004000) | (1 << 14)}]
            }
            namespace export SET_TGT
            proc SET_TGT {addr} {
                mww $addr [expr {([mrw $addr] & ~0x00004000) | (1 << 14)}]
            }
            namespace export CLR
            proc CLR {var_name} {
                upvar $var_name var
                set var [expr {$var & ~0x00004000}]
            }
            namespace export CLR_TGT
            proc CLR_TGT {addr} {
                mww $addr [expr {[mrw $addr] & ~0x00004000}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval CHARGESTARTINGREADY_SH {
            namespace export SHIFT
            proc SHIFT {} {
                return 15
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 1
            }
            namespace export MASK
            proc MASK {} {
                return 0x00008000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00008000) >> 15}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 15) & 0x00008000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00008000) | (($field_val << 15) & 0x00008000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00008000) | (($field_val << 15) & 0x00008000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 15) & ~0x00008000)}]
            }
            namespace export SET
            proc SET {var_name} {
                upvar $var_name var
                set var [expr {($var & ~0x00008000) | (1 << 15)}]
            }
            namespace export SET_TGT
            proc SET_TGT {addr} {
                mww $addr [expr {([mrw $addr] & ~0x00008000) | (1 << 15)}]
            }
            namespace export CLR
            proc CLR {var_name} {
                upvar $var_name var
                set var [expr {$var & ~0x00008000}]
            }
            namespace export CLR_TGT
            proc CLR_TGT {addr} {
                mww $addr [expr {[mrw $addr] & ~0x00008000}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval TIMEENERGSTART_BATTERY {
            namespace export SHIFT
            proc SHIFT {} {
                return 16
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 5
            }
            namespace export MASK
            proc MASK {} {
                return 0x001f0000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x001f0000) >> 16}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 16) & 0x001f0000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x001f0000) | (($field_val << 16) & 0x001f0000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x001f0000) | (($field_val << 16) & 0x001f0000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 16) & ~0x001f0000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000008
            }
        }
        namespace eval TIMEENERGSTART_STORE {
            namespace export SHIFT
            proc SHIFT {} {
                return 21
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 5
            }
            namespace export MASK
            proc MASK {} {
                return 0x03e00000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x03e00000) >> 21}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 21) & 0x03e00000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x03e00000) | (($field_val << 21) & 0x03e00000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x03e00000) | (($field_val << 21) & 0x03e00000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 21) & ~0x03e00000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x0000000c
            }
        }
        namespace eval TIMEAFTERDUMP_START {
            namespace export SHIFT
            proc SHIFT {} {
                return 26
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 4
            }
            namespace export MASK
            proc MASK {} {
                return 0x3c000000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x3c000000) >> 26}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 26) & 0x3c000000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x3c000000) | (($field_val << 26) & 0x3c000000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x3c000000) | (($field_val << 26) & 0x3c000000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 26) & ~0x3c000000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000007
            }
        }
        namespace eval LOADREGAON {
            namespace export SHIFT
            proc SHIFT {} {
                return 30
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 1
            }
            namespace export MASK
            proc MASK {} {
                return 0x40000000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x40000000) >> 30}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 30) & 0x40000000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x40000000) | (($field_val << 30) & 0x40000000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x40000000) | (($field_val << 30) & 0x40000000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 30) & ~0x40000000)}]
            }
            namespace export SET
            proc SET {var_name} {
                upvar $var_name var
                set var [expr {($var & ~0x40000000) | (1 << 30)}]
            }
            namespace export SET_TGT
            proc SET_TGT {addr} {
                mww $addr [expr {([mrw $addr] & ~0x40000000) | (1 << 30)}]
            }
            namespace export CLR
            proc CLR {var_name} {
                upvar $var_name var
                set var [expr {$var & ~0x40000000}]
            }
            namespace export CLR_TGT
            proc CLR_TGT {addr} {
                mww $addr [expr {[mrw $addr] & ~0x40000000}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval CHANGEFSM_OVR {
            namespace export SHIFT
            proc SHIFT {} {
                return 31
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 1
            }
            namespace export MASK
            proc MASK {} {
                return 0x80000000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x80000000) >> 31}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 31) & 0x80000000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x80000000) | (($field_val << 31) & 0x80000000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x80000000) | (($field_val << 31) & 0x80000000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 31) & ~0x80000000)}]
            }
            namespace export SET
            proc SET {var_name} {
                upvar $var_name var
                set var [expr {($var & ~0x80000000) | (1 << 31)}]
            }
            namespace export SET_TGT
            proc SET_TGT {addr} {
                mww $addr [expr {([mrw $addr] & ~0x80000000) | (1 << 31)}]
            }
            namespace export CLR
            proc CLR {var_name} {
                upvar $var_name var
                set var [expr {$var & ~0x80000000}]
            }
            namespace export CLR_TGT
            proc CLR_TGT {addr} {
                mww $addr [expr {[mrw $addr] & ~0x80000000}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x1d880f32
        }
    }
    namespace export AON3
    proc AON3 { {base [::CMSDK_SWREG_AON::BASE]} } {
        return [expr { [expr $base] + 0xc }]
    }
    namespace eval AON3 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_SWREG_AON::BASE]} } {
            return [expr { [expr $base] + 0xc }]
        }
        namespace eval CHANGEFSM_OVRVAL {
            namespace export SHIFT
            proc SHIFT {} {
                return 0
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 1
            }
            namespace export MASK
            proc MASK {} {
                return 0x00000001
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00000001) >> 0}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 0) & 0x00000001}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00000001) | (($field_val << 0) & 0x00000001)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00000001) | (($field_val << 0) & 0x00000001)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 0) & ~0x00000001)}]
            }
            namespace export SET
            proc SET {var_name} {
                upvar $var_name var
                set var [expr {($var & ~0x00000001) | (1 << 0)}]
            }
            namespace export SET_TGT
            proc SET_TGT {addr} {
                mww $addr [expr {([mrw $addr] & ~0x00000001) | (1 << 0)}]
            }
            namespace export CLR
            proc CLR {var_name} {
                upvar $var_name var
                set var [expr {$var & ~0x00000001}]
            }
            namespace export CLR_TGT
            proc CLR_TGT {addr} {
                mww $addr [expr {[mrw $addr] & ~0x00000001}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval FSMTOUSE_OVRVAL {
            namespace export SHIFT
            proc SHIFT {} {
                return 1
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 2
            }
            namespace export MASK
            proc MASK {} {
                return 0x00000006
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00000006) >> 1}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 1) & 0x00000006}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00000006) | (($field_val << 1) & 0x00000006)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00000006) | (($field_val << 1) & 0x00000006)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 1) & ~0x00000006)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000003
            }
        }
        namespace eval RSTSTOREUNAVAILABLE {
            namespace export SHIFT
            proc SHIFT {} {
                return 3
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 1
            }
            namespace export MASK
            proc MASK {} {
                return 0x00000008
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00000008) >> 3}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 3) & 0x00000008}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00000008) | (($field_val << 3) & 0x00000008)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00000008) | (($field_val << 3) & 0x00000008)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 3) & ~0x00000008)}]
            }
            namespace export SET
            proc SET {var_name} {
                upvar $var_name var
                set var [expr {($var & ~0x00000008) | (1 << 3)}]
            }
            namespace export SET_TGT
            proc SET_TGT {addr} {
                mww $addr [expr {([mrw $addr] & ~0x00000008) | (1 << 3)}]
            }
            namespace export CLR
            proc CLR {var_name} {
                upvar $var_name var
                set var [expr {$var & ~0x00000008}]
            }
            namespace export CLR_TGT
            proc CLR_TGT {addr} {
                mww $addr [expr {[mrw $addr] & ~0x00000008}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000001
            }
        }
        namespace eval USEHOTSTART {
            namespace export SHIFT
            proc SHIFT {} {
                return 4
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 1
            }
            namespace export MASK
            proc MASK {} {
                return 0x00000010
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00000010) >> 4}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 4) & 0x00000010}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00000010) | (($field_val << 4) & 0x00000010)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00000010) | (($field_val << 4) & 0x00000010)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 4) & ~0x00000010)}]
            }
            namespace export SET
            proc SET {var_name} {
                upvar $var_name var
                set var [expr {($var & ~0x00000010) | (1 << 4)}]
            }
            namespace export SET_TGT
            proc SET_TGT {addr} {
                mww $addr [expr {([mrw $addr] & ~0x00000010) | (1 << 4)}]
            }
            namespace export CLR
            proc CLR {var_name} {
                upvar $var_name var
                set var [expr {$var & ~0x00000010}]
            }
            namespace export CLR_TGT
            proc CLR_TGT {addr} {
                mww $addr [expr {[mrw $addr] & ~0x00000010}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000001
            }
        }
        namespace eval CLKUNITDELTOP {
            namespace export SHIFT
            proc SHIFT {} {
                return 5
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 3
            }
            namespace export MASK
            proc MASK {} {
                return 0x000000e0
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x000000e0) >> 5}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 5) & 0x000000e0}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x000000e0) | (($field_val << 5) & 0x000000e0)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x000000e0) | (($field_val << 5) & 0x000000e0)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 5) & ~0x000000e0)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000004
            }
        }
        namespace eval CLKFIXEDTOP {
            namespace export SHIFT
            proc SHIFT {} {
                return 8
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 3
            }
            namespace export MASK
            proc MASK {} {
                return 0x00000700
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00000700) >> 8}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 8) & 0x00000700}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00000700) | (($field_val << 8) & 0x00000700)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00000700) | (($field_val << 8) & 0x00000700)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 8) & ~0x00000700)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000003
            }
        }
        namespace eval ENABLESOURCE_OVR {
            namespace export SHIFT
            proc SHIFT {} {
                return 11
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 3
            }
            namespace export MASK
            proc MASK {} {
                return 0x00003800
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00003800) >> 11}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 11) & 0x00003800}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00003800) | (($field_val << 11) & 0x00003800)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00003800) | (($field_val << 11) & 0x00003800)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 11) & ~0x00003800)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval ENABLESOURCE_OVRVAL {
            namespace export SHIFT
            proc SHIFT {} {
                return 14
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 3
            }
            namespace export MASK
            proc MASK {} {
                return 0x0001c000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x0001c000) >> 14}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 14) & 0x0001c000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x0001c000) | (($field_val << 14) & 0x0001c000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x0001c000) | (($field_val << 14) & 0x0001c000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 14) & ~0x0001c000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval ENABLEDEST_OVR {
            namespace export SHIFT
            proc SHIFT {} {
                return 17
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 5
            }
            namespace export MASK
            proc MASK {} {
                return 0x003e0000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x003e0000) >> 17}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 17) & 0x003e0000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x003e0000) | (($field_val << 17) & 0x003e0000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x003e0000) | (($field_val << 17) & 0x003e0000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 17) & ~0x003e0000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval ENABLEDEST_OVRVAL {
            namespace export SHIFT
            proc SHIFT {} {
                return 22
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 5
            }
            namespace export MASK
            proc MASK {} {
                return 0x07c00000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x07c00000) >> 22}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 22) & 0x07c00000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x07c00000) | (($field_val << 22) & 0x07c00000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x07c00000) | (($field_val << 22) & 0x07c00000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 22) & ~0x07c00000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval POWERONSIMPLE {
            namespace export SHIFT
            proc SHIFT {} {
                return 27
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 1
            }
            namespace export MASK
            proc MASK {} {
                return 0x08000000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x08000000) >> 27}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 27) & 0x08000000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x08000000) | (($field_val << 27) & 0x08000000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x08000000) | (($field_val << 27) & 0x08000000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 27) & ~0x08000000)}]
            }
            namespace export SET
            proc SET {var_name} {
                upvar $var_name var
                set var [expr {($var & ~0x08000000) | (1 << 27)}]
            }
            namespace export SET_TGT
            proc SET_TGT {addr} {
                mww $addr [expr {([mrw $addr] & ~0x08000000) | (1 << 27)}]
            }
            namespace export CLR
            proc CLR {var_name} {
                upvar $var_name var
                set var [expr {$var & ~0x08000000}]
            }
            namespace export CLR_TGT
            proc CLR_TGT {addr} {
                mww $addr [expr {[mrw $addr] & ~0x08000000}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval POWERONMAIN {
            namespace export SHIFT
            proc SHIFT {} {
                return 28
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 1
            }
            namespace export MASK
            proc MASK {} {
                return 0x10000000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x10000000) >> 28}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 28) & 0x10000000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x10000000) | (($field_val << 28) & 0x10000000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x10000000) | (($field_val << 28) & 0x10000000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 28) & ~0x10000000)}]
            }
            namespace export SET
            proc SET {var_name} {
                upvar $var_name var
                set var [expr {($var & ~0x10000000) | (1 << 28)}]
            }
            namespace export SET_TGT
            proc SET_TGT {addr} {
                mww $addr [expr {([mrw $addr] & ~0x10000000) | (1 << 28)}]
            }
            namespace export CLR
            proc CLR {var_name} {
                upvar $var_name var
                set var [expr {$var & ~0x10000000}]
            }
            namespace export CLR_TGT
            proc CLR_TGT {addr} {
                mww $addr [expr {[mrw $addr] & ~0x10000000}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval RESETPREVIOUSFSM {
            namespace export SHIFT
            proc SHIFT {} {
                return 29
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 1
            }
            namespace export MASK
            proc MASK {} {
                return 0x20000000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x20000000) >> 29}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 29) & 0x20000000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x20000000) | (($field_val << 29) & 0x20000000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x20000000) | (($field_val << 29) & 0x20000000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 29) & ~0x20000000)}]
            }
            namespace export SET
            proc SET {var_name} {
                upvar $var_name var
                set var [expr {($var & ~0x20000000) | (1 << 29)}]
            }
            namespace export SET_TGT
            proc SET_TGT {addr} {
                mww $addr [expr {([mrw $addr] & ~0x20000000) | (1 << 29)}]
            }
            namespace export CLR
            proc CLR {var_name} {
                upvar $var_name var
                set var [expr {$var & ~0x20000000}]
            }
            namespace export CLR_TGT
            proc CLR_TGT {addr} {
                mww $addr [expr {[mrw $addr] & ~0x20000000}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval HSTINY_OVR {
            namespace export SHIFT
            proc SHIFT {} {
                return 30
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 1
            }
            namespace export MASK
            proc MASK {} {
                return 0x40000000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x40000000) >> 30}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 30) & 0x40000000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x40000000) | (($field_val << 30) & 0x40000000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x40000000) | (($field_val << 30) & 0x40000000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 30) & ~0x40000000)}]
            }
            namespace export SET
            proc SET {var_name} {
                upvar $var_name var
                set var [expr {($var & ~0x40000000) | (1 << 30)}]
            }
            namespace export SET_TGT
            proc SET_TGT {addr} {
                mww $addr [expr {([mrw $addr] & ~0x40000000) | (1 << 30)}]
            }
            namespace export CLR
            proc CLR {var_name} {
                upvar $var_name var
                set var [expr {$var & ~0x40000000}]
            }
            namespace export CLR_TGT
            proc CLR_TGT {addr} {
                mww $addr [expr {[mrw $addr] & ~0x40000000}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval HSTINY_OVRVAL {
            namespace export SHIFT
            proc SHIFT {} {
                return 31
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 1
            }
            namespace export MASK
            proc MASK {} {
                return 0x80000000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x80000000) >> 31}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 31) & 0x80000000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x80000000) | (($field_val << 31) & 0x80000000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x80000000) | (($field_val << 31) & 0x80000000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 31) & ~0x80000000)}]
            }
            namespace export SET
            proc SET {var_name} {
                upvar $var_name var
                set var [expr {($var & ~0x80000000) | (1 << 31)}]
            }
            namespace export SET_TGT
            proc SET_TGT {addr} {
                mww $addr [expr {([mrw $addr] & ~0x80000000) | (1 << 31)}]
            }
            namespace export CLR
            proc CLR {var_name} {
                upvar $var_name var
                set var [expr {$var & ~0x80000000}]
            }
            namespace export CLR_TGT
            proc CLR_TGT {addr} {
                mww $addr [expr {[mrw $addr] & ~0x80000000}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x0000039e
        }
    }
    namespace export AON4
    proc AON4 { {base [::CMSDK_SWREG_AON::BASE]} } {
        return [expr { [expr $base] + 0x10 }]
    }
    namespace eval AON4 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_SWREG_AON::BASE]} } {
            return [expr { [expr $base] + 0x10 }]
        }
        namespace eval HSSIMPLE_OVR {
            namespace export SHIFT
            proc SHIFT {} {
                return 0
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 1
            }
            namespace export MASK
            proc MASK {} {
                return 0x00000001
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00000001) >> 0}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 0) & 0x00000001}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00000001) | (($field_val << 0) & 0x00000001)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00000001) | (($field_val << 0) & 0x00000001)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 0) & ~0x00000001)}]
            }
            namespace export SET
            proc SET {var_name} {
                upvar $var_name var
                set var [expr {($var & ~0x00000001) | (1 << 0)}]
            }
            namespace export SET_TGT
            proc SET_TGT {addr} {
                mww $addr [expr {([mrw $addr] & ~0x00000001) | (1 << 0)}]
            }
            namespace export CLR
            proc CLR {var_name} {
                upvar $var_name var
                set var [expr {$var & ~0x00000001}]
            }
            namespace export CLR_TGT
            proc CLR_TGT {addr} {
                mww $addr [expr {[mrw $addr] & ~0x00000001}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval HSSIMPLE_OVRVAL {
            namespace export SHIFT
            proc SHIFT {} {
                return 1
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 1
            }
            namespace export MASK
            proc MASK {} {
                return 0x00000002
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00000002) >> 1}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 1) & 0x00000002}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00000002) | (($field_val << 1) & 0x00000002)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00000002) | (($field_val << 1) & 0x00000002)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 1) & ~0x00000002)}]
            }
            namespace export SET
            proc SET {var_name} {
                upvar $var_name var
                set var [expr {($var & ~0x00000002) | (1 << 1)}]
            }
            namespace export SET_TGT
            proc SET_TGT {addr} {
                mww $addr [expr {([mrw $addr] & ~0x00000002) | (1 << 1)}]
            }
            namespace export CLR
            proc CLR {var_name} {
                upvar $var_name var
                set var [expr {$var & ~0x00000002}]
            }
            namespace export CLR_TGT
            proc CLR_TGT {addr} {
                mww $addr [expr {[mrw $addr] & ~0x00000002}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval HSMAIN_OVR {
            namespace export SHIFT
            proc SHIFT {} {
                return 2
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 1
            }
            namespace export MASK
            proc MASK {} {
                return 0x00000004
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00000004) >> 2}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 2) & 0x00000004}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00000004) | (($field_val << 2) & 0x00000004)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00000004) | (($field_val << 2) & 0x00000004)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 2) & ~0x00000004)}]
            }
            namespace export SET
            proc SET {var_name} {
                upvar $var_name var
                set var [expr {($var & ~0x00000004) | (1 << 2)}]
            }
            namespace export SET_TGT
            proc SET_TGT {addr} {
                mww $addr [expr {([mrw $addr] & ~0x00000004) | (1 << 2)}]
            }
            namespace export CLR
            proc CLR {var_name} {
                upvar $var_name var
                set var [expr {$var & ~0x00000004}]
            }
            namespace export CLR_TGT
            proc CLR_TGT {addr} {
                mww $addr [expr {[mrw $addr] & ~0x00000004}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval HSMAIN_OVRVAL {
            namespace export SHIFT
            proc SHIFT {} {
                return 3
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 1
            }
            namespace export MASK
            proc MASK {} {
                return 0x00000008
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00000008) >> 3}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 3) & 0x00000008}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00000008) | (($field_val << 3) & 0x00000008)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00000008) | (($field_val << 3) & 0x00000008)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 3) & ~0x00000008)}]
            }
            namespace export SET
            proc SET {var_name} {
                upvar $var_name var
                set var [expr {($var & ~0x00000008) | (1 << 3)}]
            }
            namespace export SET_TGT
            proc SET_TGT {addr} {
                mww $addr [expr {([mrw $addr] & ~0x00000008) | (1 << 3)}]
            }
            namespace export CLR
            proc CLR {var_name} {
                upvar $var_name var
                set var [expr {$var & ~0x00000008}]
            }
            namespace export CLR_TGT
            proc CLR_TGT {addr} {
                mww $addr [expr {[mrw $addr] & ~0x00000008}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval LOADSHADOWAON_OVR {
            namespace export SHIFT
            proc SHIFT {} {
                return 4
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 1
            }
            namespace export MASK
            proc MASK {} {
                return 0x00000010
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00000010) >> 4}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 4) & 0x00000010}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00000010) | (($field_val << 4) & 0x00000010)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00000010) | (($field_val << 4) & 0x00000010)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 4) & ~0x00000010)}]
            }
            namespace export SET
            proc SET {var_name} {
                upvar $var_name var
                set var [expr {($var & ~0x00000010) | (1 << 4)}]
            }
            namespace export SET_TGT
            proc SET_TGT {addr} {
                mww $addr [expr {([mrw $addr] & ~0x00000010) | (1 << 4)}]
            }
            namespace export CLR
            proc CLR {var_name} {
                upvar $var_name var
                set var [expr {$var & ~0x00000010}]
            }
            namespace export CLR_TGT
            proc CLR_TGT {addr} {
                mww $addr [expr {[mrw $addr] & ~0x00000010}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval LOADSHADOWAON_OVRVAL {
            namespace export SHIFT
            proc SHIFT {} {
                return 5
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 1
            }
            namespace export MASK
            proc MASK {} {
                return 0x00000020
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00000020) >> 5}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 5) & 0x00000020}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00000020) | (($field_val << 5) & 0x00000020)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00000020) | (($field_val << 5) & 0x00000020)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 5) & ~0x00000020)}]
            }
            namespace export SET
            proc SET {var_name} {
                upvar $var_name var
                set var [expr {($var & ~0x00000020) | (1 << 5)}]
            }
            namespace export SET_TGT
            proc SET_TGT {addr} {
                mww $addr [expr {([mrw $addr] & ~0x00000020) | (1 << 5)}]
            }
            namespace export CLR
            proc CLR {var_name} {
                upvar $var_name var
                set var [expr {$var & ~0x00000020}]
            }
            namespace export CLR_TGT
            proc CLR_TGT {addr} {
                mww $addr [expr {[mrw $addr] & ~0x00000020}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval LOADSHADOWSIMPLE_OVR {
            namespace export SHIFT
            proc SHIFT {} {
                return 6
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 1
            }
            namespace export MASK
            proc MASK {} {
                return 0x00000040
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00000040) >> 6}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 6) & 0x00000040}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00000040) | (($field_val << 6) & 0x00000040)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00000040) | (($field_val << 6) & 0x00000040)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 6) & ~0x00000040)}]
            }
            namespace export SET
            proc SET {var_name} {
                upvar $var_name var
                set var [expr {($var & ~0x00000040) | (1 << 6)}]
            }
            namespace export SET_TGT
            proc SET_TGT {addr} {
                mww $addr [expr {([mrw $addr] & ~0x00000040) | (1 << 6)}]
            }
            namespace export CLR
            proc CLR {var_name} {
                upvar $var_name var
                set var [expr {$var & ~0x00000040}]
            }
            namespace export CLR_TGT
            proc CLR_TGT {addr} {
                mww $addr [expr {[mrw $addr] & ~0x00000040}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval LOADSHADOWSIMPLE_OVRVAL {
            namespace export SHIFT
            proc SHIFT {} {
                return 7
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 1
            }
            namespace export MASK
            proc MASK {} {
                return 0x00000080
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00000080) >> 7}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 7) & 0x00000080}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00000080) | (($field_val << 7) & 0x00000080)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00000080) | (($field_val << 7) & 0x00000080)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 7) & ~0x00000080)}]
            }
            namespace export SET
            proc SET {var_name} {
                upvar $var_name var
                set var [expr {($var & ~0x00000080) | (1 << 7)}]
            }
            namespace export SET_TGT
            proc SET_TGT {addr} {
                mww $addr [expr {([mrw $addr] & ~0x00000080) | (1 << 7)}]
            }
            namespace export CLR
            proc CLR {var_name} {
                upvar $var_name var
                set var [expr {$var & ~0x00000080}]
            }
            namespace export CLR_TGT
            proc CLR_TGT {addr} {
                mww $addr [expr {[mrw $addr] & ~0x00000080}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval LOADSHADOWMAIN_OVR {
            namespace export SHIFT
            proc SHIFT {} {
                return 8
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 1
            }
            namespace export MASK
            proc MASK {} {
                return 0x00000100
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00000100) >> 8}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 8) & 0x00000100}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00000100) | (($field_val << 8) & 0x00000100)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00000100) | (($field_val << 8) & 0x00000100)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 8) & ~0x00000100)}]
            }
            namespace export SET
            proc SET {var_name} {
                upvar $var_name var
                set var [expr {($var & ~0x00000100) | (1 << 8)}]
            }
            namespace export SET_TGT
            proc SET_TGT {addr} {
                mww $addr [expr {([mrw $addr] & ~0x00000100) | (1 << 8)}]
            }
            namespace export CLR
            proc CLR {var_name} {
                upvar $var_name var
                set var [expr {$var & ~0x00000100}]
            }
            namespace export CLR_TGT
            proc CLR_TGT {addr} {
                mww $addr [expr {[mrw $addr] & ~0x00000100}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval LOADSHADOWMAIN_OVRVAL {
            namespace export SHIFT
            proc SHIFT {} {
                return 9
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 1
            }
            namespace export MASK
            proc MASK {} {
                return 0x00000200
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00000200) >> 9}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 9) & 0x00000200}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00000200) | (($field_val << 9) & 0x00000200)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00000200) | (($field_val << 9) & 0x00000200)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 9) & ~0x00000200)}]
            }
            namespace export SET
            proc SET {var_name} {
                upvar $var_name var
                set var [expr {($var & ~0x00000200) | (1 << 9)}]
            }
            namespace export SET_TGT
            proc SET_TGT {addr} {
                mww $addr [expr {([mrw $addr] & ~0x00000200) | (1 << 9)}]
            }
            namespace export CLR
            proc CLR {var_name} {
                upvar $var_name var
                set var [expr {$var & ~0x00000200}]
            }
            namespace export CLR_TGT
            proc CLR_TGT {addr} {
                mww $addr [expr {[mrw $addr] & ~0x00000200}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval LOADSHADOWUNITDEL_OVR {
            namespace export SHIFT
            proc SHIFT {} {
                return 10
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 1
            }
            namespace export MASK
            proc MASK {} {
                return 0x00000400
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00000400) >> 10}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 10) & 0x00000400}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00000400) | (($field_val << 10) & 0x00000400)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00000400) | (($field_val << 10) & 0x00000400)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 10) & ~0x00000400)}]
            }
            namespace export SET
            proc SET {var_name} {
                upvar $var_name var
                set var [expr {($var & ~0x00000400) | (1 << 10)}]
            }
            namespace export SET_TGT
            proc SET_TGT {addr} {
                mww $addr [expr {([mrw $addr] & ~0x00000400) | (1 << 10)}]
            }
            namespace export CLR
            proc CLR {var_name} {
                upvar $var_name var
                set var [expr {$var & ~0x00000400}]
            }
            namespace export CLR_TGT
            proc CLR_TGT {addr} {
                mww $addr [expr {[mrw $addr] & ~0x00000400}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval LOADSHADOWUNITDEL_OVRVAL {
            namespace export SHIFT
            proc SHIFT {} {
                return 11
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 1
            }
            namespace export MASK
            proc MASK {} {
                return 0x00000800
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00000800) >> 11}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 11) & 0x00000800}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00000800) | (($field_val << 11) & 0x00000800)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00000800) | (($field_val << 11) & 0x00000800)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 11) & ~0x00000800)}]
            }
            namespace export SET
            proc SET {var_name} {
                upvar $var_name var
                set var [expr {($var & ~0x00000800) | (1 << 11)}]
            }
            namespace export SET_TGT
            proc SET_TGT {addr} {
                mww $addr [expr {([mrw $addr] & ~0x00000800) | (1 << 11)}]
            }
            namespace export CLR
            proc CLR {var_name} {
                upvar $var_name var
                set var [expr {$var & ~0x00000800}]
            }
            namespace export CLR_TGT
            proc CLR_TGT {addr} {
                mww $addr [expr {[mrw $addr] & ~0x00000800}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval UPDATEUNITDEL_OVR {
            namespace export SHIFT
            proc SHIFT {} {
                return 12
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 1
            }
            namespace export MASK
            proc MASK {} {
                return 0x00001000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00001000) >> 12}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 12) & 0x00001000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00001000) | (($field_val << 12) & 0x00001000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00001000) | (($field_val << 12) & 0x00001000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 12) & ~0x00001000)}]
            }
            namespace export SET
            proc SET {var_name} {
                upvar $var_name var
                set var [expr {($var & ~0x00001000) | (1 << 12)}]
            }
            namespace export SET_TGT
            proc SET_TGT {addr} {
                mww $addr [expr {([mrw $addr] & ~0x00001000) | (1 << 12)}]
            }
            namespace export CLR
            proc CLR {var_name} {
                upvar $var_name var
                set var [expr {$var & ~0x00001000}]
            }
            namespace export CLR_TGT
            proc CLR_TGT {addr} {
                mww $addr [expr {[mrw $addr] & ~0x00001000}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval UPDATEUNITDEL_OVRVAL {
            namespace export SHIFT
            proc SHIFT {} {
                return 13
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 1
            }
            namespace export MASK
            proc MASK {} {
                return 0x00002000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00002000) >> 13}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 13) & 0x00002000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00002000) | (($field_val << 13) & 0x00002000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00002000) | (($field_val << 13) & 0x00002000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 13) & ~0x00002000)}]
            }
            namespace export SET
            proc SET {var_name} {
                upvar $var_name var
                set var [expr {($var & ~0x00002000) | (1 << 13)}]
            }
            namespace export SET_TGT
            proc SET_TGT {addr} {
                mww $addr [expr {([mrw $addr] & ~0x00002000) | (1 << 13)}]
            }
            namespace export CLR
            proc CLR {var_name} {
                upvar $var_name var
                set var [expr {$var & ~0x00002000}]
            }
            namespace export CLR_TGT
            proc CLR_TGT {addr} {
                mww $addr [expr {[mrw $addr] & ~0x00002000}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval CLKUNITDELREG {
            namespace export SHIFT
            proc SHIFT {} {
                return 14
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 5
            }
            namespace export MASK
            proc MASK {} {
                return 0x0007c000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x0007c000) >> 14}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 14) & 0x0007c000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x0007c000) | (($field_val << 14) & 0x0007c000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x0007c000) | (($field_val << 14) & 0x0007c000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 14) & ~0x0007c000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000009
            }
        }
        namespace eval TINYSOURCESTORE_OVR {
            namespace export SHIFT
            proc SHIFT {} {
                return 19
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 1
            }
            namespace export MASK
            proc MASK {} {
                return 0x00080000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00080000) >> 19}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 19) & 0x00080000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00080000) | (($field_val << 19) & 0x00080000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00080000) | (($field_val << 19) & 0x00080000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 19) & ~0x00080000)}]
            }
            namespace export SET
            proc SET {var_name} {
                upvar $var_name var
                set var [expr {($var & ~0x00080000) | (1 << 19)}]
            }
            namespace export SET_TGT
            proc SET_TGT {addr} {
                mww $addr [expr {([mrw $addr] & ~0x00080000) | (1 << 19)}]
            }
            namespace export CLR
            proc CLR {var_name} {
                upvar $var_name var
                set var [expr {$var & ~0x00080000}]
            }
            namespace export CLR_TGT
            proc CLR_TGT {addr} {
                mww $addr [expr {[mrw $addr] & ~0x00080000}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval TINYSOURCESTORE_OVRVAL {
            namespace export SHIFT
            proc SHIFT {} {
                return 20
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 1
            }
            namespace export MASK
            proc MASK {} {
                return 0x00100000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00100000) >> 20}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 20) & 0x00100000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00100000) | (($field_val << 20) & 0x00100000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00100000) | (($field_val << 20) & 0x00100000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 20) & ~0x00100000)}]
            }
            namespace export SET
            proc SET {var_name} {
                upvar $var_name var
                set var [expr {($var & ~0x00100000) | (1 << 20)}]
            }
            namespace export SET_TGT
            proc SET_TGT {addr} {
                mww $addr [expr {([mrw $addr] & ~0x00100000) | (1 << 20)}]
            }
            namespace export CLR
            proc CLR {var_name} {
                upvar $var_name var
                set var [expr {$var & ~0x00100000}]
            }
            namespace export CLR_TGT
            proc CLR_TGT {addr} {
                mww $addr [expr {[mrw $addr] & ~0x00100000}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval PN_OVR {
            namespace export SHIFT
            proc SHIFT {} {
                return 21
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 10
            }
            namespace export MASK
            proc MASK {} {
                return 0x7fe00000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x7fe00000) >> 21}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 21) & 0x7fe00000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x7fe00000) | (($field_val << 21) & 0x7fe00000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x7fe00000) | (($field_val << 21) & 0x7fe00000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 21) & ~0x7fe00000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x00024000
        }
    }
    namespace export AON5
    proc AON5 { {base [::CMSDK_SWREG_AON::BASE]} } {
        return [expr { [expr $base] + 0x14 }]
    }
    namespace eval AON5 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_SWREG_AON::BASE]} } {
            return [expr { [expr $base] + 0x14 }]
        }
        namespace eval PN_OVRVAL {
            namespace export SHIFT
            proc SHIFT {} {
                return 0
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 10
            }
            namespace export MASK
            proc MASK {} {
                return 0x000003ff
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x000003ff) >> 0}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 0) & 0x000003ff}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x000003ff) | (($field_val << 0) & 0x000003ff)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x000003ff) | (($field_val << 0) & 0x000003ff)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 0) & ~0x000003ff)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x000003ff
            }
        }
        namespace eval SIZE {
            namespace export SHIFT
            proc SHIFT {} {
                return 10
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 20
            }
            namespace export MASK
            proc MASK {} {
                return 0x3ffffc00
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x3ffffc00) >> 10}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 10) & 0x3ffffc00}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x3ffffc00) | (($field_val << 10) & 0x3ffffc00)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x3ffffc00) | (($field_val << 10) & 0x3ffffc00)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 10) & ~0x3ffffc00)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x000fffff
            }
        }
        namespace eval DELZCD1 {
            namespace export SHIFT
            proc SHIFT {} {
                return 30
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 2
            }
            namespace export MASK
            proc MASK {} {
                return 0xc0000000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0xc0000000) >> 30}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 30) & 0xc0000000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0xc0000000) | (($field_val << 30) & 0xc0000000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0xc0000000) | (($field_val << 30) & 0xc0000000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 30) & ~0xc0000000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000001
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x7fffffff
        }
    }
    namespace export AON6
    proc AON6 { {base [::CMSDK_SWREG_AON::BASE]} } {
        return [expr { [expr $base] + 0x18 }]
    }
    namespace eval AON6 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_SWREG_AON::BASE]} } {
            return [expr { [expr $base] + 0x18 }]
        }
        namespace eval DELZCD2 {
            namespace export SHIFT
            proc SHIFT {} {
                return 0
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 2
            }
            namespace export MASK
            proc MASK {} {
                return 0x00000003
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00000003) >> 0}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 0) & 0x00000003}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00000003) | (($field_val << 0) & 0x00000003)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00000003) | (($field_val << 0) & 0x00000003)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 0) & ~0x00000003)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000001
            }
        }
        namespace eval DELENERGDUMP {
            namespace export SHIFT
            proc SHIFT {} {
                return 2
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 4
            }
            namespace export MASK
            proc MASK {} {
                return 0x0000003c
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x0000003c) >> 2}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 2) & 0x0000003c}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x0000003c) | (($field_val << 2) & 0x0000003c)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x0000003c) | (($field_val << 2) & 0x0000003c)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 2) & ~0x0000003c)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000003
            }
        }
        namespace eval ATETEST {
            namespace export SHIFT
            proc SHIFT {} {
                return 6
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 1
            }
            namespace export MASK
            proc MASK {} {
                return 0x00000040
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00000040) >> 6}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 6) & 0x00000040}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00000040) | (($field_val << 6) & 0x00000040)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00000040) | (($field_val << 6) & 0x00000040)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 6) & ~0x00000040)}]
            }
            namespace export SET
            proc SET {var_name} {
                upvar $var_name var
                set var [expr {($var & ~0x00000040) | (1 << 6)}]
            }
            namespace export SET_TGT
            proc SET_TGT {addr} {
                mww $addr [expr {([mrw $addr] & ~0x00000040) | (1 << 6)}]
            }
            namespace export CLR
            proc CLR {var_name} {
                upvar $var_name var
                set var [expr {$var & ~0x00000040}]
            }
            namespace export CLR_TGT
            proc CLR_TGT {addr} {
                mww $addr [expr {[mrw $addr] & ~0x00000040}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval DIGTESTSEL {
            namespace export SHIFT
            proc SHIFT {} {
                return 7
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 5
            }
            namespace export MASK
            proc MASK {} {
                return 0x00000f80
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00000f80) >> 7}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 7) & 0x00000f80}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00000f80) | (($field_val << 7) & 0x00000f80)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00000f80) | (($field_val << 7) & 0x00000f80)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 7) & ~0x00000f80)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval SPARE {
            namespace export SHIFT
            proc SHIFT {} {
                return 12
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 4
            }
            namespace export MASK
            proc MASK {} {
                return 0x0000f000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x0000f000) >> 12}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 12) & 0x0000f000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x0000f000) | (($field_val << 12) & 0x0000f000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x0000f000) | (($field_val << 12) & 0x0000f000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 12) & ~0x0000f000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000003
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x0000300d
        }
    }
    namespace export READOUT
    proc READOUT { {base [::CMSDK_SWREG_AON::BASE]} } {
        return [expr { [expr $base] + 0x1c }]
    }
    namespace eval READOUT {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_SWREG_AON::BASE]} } {
            return [expr { [expr $base] + 0x1c }]
        }
        namespace eval STATETOP {
            namespace export SHIFT
            proc SHIFT {} {
                return 0
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 4
            }
            namespace export MASK
            proc MASK {} {
                return 0x0000000f
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x0000000f) >> 0}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval FSMCURRENT {
            namespace export SHIFT
            proc SHIFT {} {
                return 4
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 2
            }
            namespace export MASK
            proc MASK {} {
                return 0x00000030
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00000030) >> 4}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval FSMPREVIOUS {
            namespace export SHIFT
            proc SHIFT {} {
                return 6
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 2
            }
            namespace export MASK
            proc MASK {} {
                return 0x000000c0
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x000000c0) >> 6}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval SUPREADY {
            namespace export SHIFT
            proc SHIFT {} {
                return 8
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 5
            }
            namespace export MASK
            proc MASK {} {
                return 0x00001f00
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00001f00) >> 8}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval SUPPLIESREADY {
            namespace export SHIFT
            proc SHIFT {} {
                return 13
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 1
            }
            namespace export MASK
            proc MASK {} {
                return 0x00002000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00002000) >> 13}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval CLKUNITDELACTIVE {
            namespace export SHIFT
            proc SHIFT {} {
                return 14
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 5
            }
            namespace export MASK
            proc MASK {} {
                return 0x0007c000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x0007c000) >> 14}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x00000000
        }
    }
    namespace export CORE_ID
    proc CORE_ID { {base [::CMSDK_SWREG_AON::BASE]} } {
        return [expr { [expr $base] + 0x20 }]
    }
    namespace eval CORE_ID {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_SWREG_AON::BASE]} } {
            return [expr { [expr $base] + 0x20 }]
        }
        namespace eval ID {
            namespace export SHIFT
            proc SHIFT {} {
                return 0
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 32
            }
            namespace export MASK
            proc MASK {} {
                return 0xffffffff
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0xffffffff) >> 0}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x53575241
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x53575241
        }
    }
}
