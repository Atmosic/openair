namespace eval CMSDK_BLE_REGS_SECURE {
    namespace export BASE
    proc BASE {} {
        return 0x50120000
    }
    namespace export ENBPRESET
    proc ENBPRESET { {base [::CMSDK_BLE_REGS_SECURE::BASE]} } {
        return [expr { [expr $base] + 0x3c }]
    }
    namespace eval ENBPRESET {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_BLE_REGS_SECURE::BASE]} } {
            return [expr { [expr $base] + 0x3c }]
        }
        namespace eval TWRM {
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
                return 0x00000015
            }
        }
        namespace eval TWOSC {
            namespace export SHIFT
            proc SHIFT {} {
                return 10
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 11
            }
            namespace export MASK
            proc MASK {} {
                return 0x001ffc00
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x001ffc00) >> 10}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 10) & 0x001ffc00}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x001ffc00) | (($field_val << 10) & 0x001ffc00)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x001ffc00) | (($field_val << 10) & 0x001ffc00)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 10) & ~0x001ffc00)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000042
            }
        }
        namespace eval TWEXT {
            namespace export SHIFT
            proc SHIFT {} {
                return 21
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 11
            }
            namespace export MASK
            proc MASK {} {
                return 0xffe00000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0xffe00000) >> 21}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 21) & 0xffe00000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0xffe00000) | (($field_val << 21) & 0xffe00000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0xffe00000) | (($field_val << 21) & 0xffe00000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 21) & ~0xffe00000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000042
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x08410815
        }
    }
    namespace export DIAGCNTL
    proc DIAGCNTL { {base [::CMSDK_BLE_REGS_SECURE::BASE]} } {
        return [expr { [expr $base] + 0x50 }]
    }
    namespace eval DIAGCNTL {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_BLE_REGS_SECURE::BASE]} } {
            return [expr { [expr $base] + 0x50 }]
        }
        namespace eval DIAG0 {
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
                return 0x00000000
            }
        }
        namespace eval DIAG0_EN {
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
        namespace eval DIAG1 {
            namespace export SHIFT
            proc SHIFT {} {
                return 8
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 7
            }
            namespace export MASK
            proc MASK {} {
                return 0x00007f00
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00007f00) >> 8}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 8) & 0x00007f00}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00007f00) | (($field_val << 8) & 0x00007f00)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00007f00) | (($field_val << 8) & 0x00007f00)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 8) & ~0x00007f00)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval DIAG1_EN {
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
        namespace eval DIAG2 {
            namespace export SHIFT
            proc SHIFT {} {
                return 16
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 7
            }
            namespace export MASK
            proc MASK {} {
                return 0x007f0000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x007f0000) >> 16}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 16) & 0x007f0000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x007f0000) | (($field_val << 16) & 0x007f0000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x007f0000) | (($field_val << 16) & 0x007f0000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 16) & ~0x007f0000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval DIAG2_EN {
            namespace export SHIFT
            proc SHIFT {} {
                return 23
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 1
            }
            namespace export MASK
            proc MASK {} {
                return 0x00800000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00800000) >> 23}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 23) & 0x00800000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00800000) | (($field_val << 23) & 0x00800000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00800000) | (($field_val << 23) & 0x00800000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 23) & ~0x00800000)}]
            }
            namespace export SET
            proc SET {var_name} {
                upvar $var_name var
                set var [expr {($var & ~0x00800000) | (1 << 23)}]
            }
            namespace export SET_TGT
            proc SET_TGT {addr} {
                mww $addr [expr {([mrw $addr] & ~0x00800000) | (1 << 23)}]
            }
            namespace export CLR
            proc CLR {var_name} {
                upvar $var_name var
                set var [expr {$var & ~0x00800000}]
            }
            namespace export CLR_TGT
            proc CLR_TGT {addr} {
                mww $addr [expr {[mrw $addr] & ~0x00800000}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval DIAG3 {
            namespace export SHIFT
            proc SHIFT {} {
                return 24
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 7
            }
            namespace export MASK
            proc MASK {} {
                return 0x7f000000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x7f000000) >> 24}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 24) & 0x7f000000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x7f000000) | (($field_val << 24) & 0x7f000000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x7f000000) | (($field_val << 24) & 0x7f000000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 24) & ~0x7f000000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval DIAG3_EN {
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
            return 0x00000000
        }
    }
    namespace export DIAGSTAT
    proc DIAGSTAT { {base [::CMSDK_BLE_REGS_SECURE::BASE]} } {
        return [expr { [expr $base] + 0x60 }]
    }
    namespace eval DIAGSTAT {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_BLE_REGS_SECURE::BASE]} } {
            return [expr { [expr $base] + 0x60 }]
        }
        namespace eval DIAG0STAT {
            namespace export SHIFT
            proc SHIFT {} {
                return 0
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 8
            }
            namespace export MASK
            proc MASK {} {
                return 0x000000ff
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x000000ff) >> 0}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval DIAG1STAT {
            namespace export SHIFT
            proc SHIFT {} {
                return 8
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 8
            }
            namespace export MASK
            proc MASK {} {
                return 0x0000ff00
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x0000ff00) >> 8}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval DIAG2STAT {
            namespace export SHIFT
            proc SHIFT {} {
                return 16
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 8
            }
            namespace export MASK
            proc MASK {} {
                return 0x00ff0000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00ff0000) >> 16}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval DIAG3STAT {
            namespace export SHIFT
            proc SHIFT {} {
                return 24
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 8
            }
            namespace export MASK
            proc MASK {} {
                return 0xff000000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0xff000000) >> 24}]
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
    namespace export RADIOCNTL0
    proc RADIOCNTL0 { {base [::CMSDK_BLE_REGS_SECURE::BASE]} } {
        return [expr { [expr $base] + 0x70 }]
    }
    namespace eval RADIOCNTL0 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_BLE_REGS_SECURE::BASE]} } {
            return [expr { [expr $base] + 0x70 }]
        }
        namespace eval SPIGO {
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
        namespace eval SPICOMP {
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
        namespace eval SPIFREQ {
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
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 4) & 0x00000030}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00000030) | (($field_val << 4) & 0x00000030)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00000030) | (($field_val << 4) & 0x00000030)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 4) & ~0x00000030)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval SPICFG {
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
        namespace eval SPIPTR {
            namespace export SHIFT
            proc SHIFT {} {
                return 16
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 16
            }
            namespace export MASK
            proc MASK {} {
                return 0xffff0000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0xffff0000) >> 16}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 16) & 0xffff0000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0xffff0000) | (($field_val << 16) & 0xffff0000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0xffff0000) | (($field_val << 16) & 0xffff0000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 16) & ~0xffff0000)}]
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
    namespace export RADIOCNTL1
    proc RADIOCNTL1 { {base [::CMSDK_BLE_REGS_SECURE::BASE]} } {
        return [expr { [expr $base] + 0x74 }]
    }
    namespace eval RADIOCNTL1 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_BLE_REGS_SECURE::BASE]} } {
            return [expr { [expr $base] + 0x74 }]
        }
        namespace eval SUBVERSION {
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
                return 0x00000000
            }
        }
        namespace eval XRFSEL {
            namespace export SHIFT
            proc SHIFT {} {
                return 4
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 6
            }
            namespace export MASK
            proc MASK {} {
                return 0x000003f0
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x000003f0) >> 4}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 4) & 0x000003f0}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x000003f0) | (($field_val << 4) & 0x000003f0)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x000003f0) | (($field_val << 4) & 0x000003f0)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 4) & ~0x000003f0)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000002
            }
        }
        namespace eval JEF_SELECT {
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
        namespace eval DPCORR_EN {
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
        namespace eval SYNC_PULSE_SRC {
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
                return 0x00000001
            }
        }
        namespace eval SYNC_PULSE_MODE {
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
                return 0x00000001
            }
        }
        namespace eval FORCEAGC_LENGTH {
            namespace export SHIFT
            proc SHIFT {} {
                return 16
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 12
            }
            namespace export MASK
            proc MASK {} {
                return 0x0fff0000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x0fff0000) >> 16}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 16) & 0x0fff0000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x0fff0000) | (($field_val << 16) & 0x0fff0000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x0fff0000) | (($field_val << 16) & 0x0fff0000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 16) & ~0x0fff0000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval TXDNSL {
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
        namespace eval RXDNSL {
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
        namespace eval FORCEIQ {
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
        namespace eval FORCEAGC_EN {
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
            return 0x0000d020
        }
    }
    namespace export RADIOCNTL2
    proc RADIOCNTL2 { {base [::CMSDK_BLE_REGS_SECURE::BASE]} } {
        return [expr { [expr $base] + 0x78 }]
    }
    namespace eval RADIOCNTL2 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_BLE_REGS_SECURE::BASE]} } {
            return [expr { [expr $base] + 0x78 }]
        }
        namespace eval FREQTABLE_PTR {
            namespace export SHIFT
            proc SHIFT {} {
                return 0
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 16
            }
            namespace export MASK
            proc MASK {} {
                return 0x0000ffff
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x0000ffff) >> 0}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 0) & 0x0000ffff}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x0000ffff) | (($field_val << 0) & 0x0000ffff)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x0000ffff) | (($field_val << 0) & 0x0000ffff)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 0) & ~0x0000ffff)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000100
            }
        }
        namespace eval SYNCERR {
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
                return 0x00000000
            }
        }
        namespace eval LRSYNCERR {
            namespace export SHIFT
            proc SHIFT {} {
                return 20
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 2
            }
            namespace export MASK
            proc MASK {} {
                return 0x00300000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00300000) >> 20}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 20) & 0x00300000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00300000) | (($field_val << 20) & 0x00300000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00300000) | (($field_val << 20) & 0x00300000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 20) & ~0x00300000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval PHYMSK {
            namespace export SHIFT
            proc SHIFT {} {
                return 22
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 2
            }
            namespace export MASK
            proc MASK {} {
                return 0x00c00000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00c00000) >> 22}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 22) & 0x00c00000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00c00000) | (($field_val << 22) & 0x00c00000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00c00000) | (($field_val << 22) & 0x00c00000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 22) & ~0x00c00000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000003
            }
        }
        namespace eval LRVTBFLUSH {
            namespace export SHIFT
            proc SHIFT {} {
                return 24
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 5
            }
            namespace export MASK
            proc MASK {} {
                return 0x1f000000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x1f000000) >> 24}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 24) & 0x1f000000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x1f000000) | (($field_val << 24) & 0x1f000000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x1f000000) | (($field_val << 24) & 0x1f000000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 24) & ~0x1f000000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000014
            }
        }
        namespace eval RXCITERMBYPASS {
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
                return 0x00000001
            }
        }
        namespace eval LRSYNCCOMPMODE {
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
                return 0x00000003
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0xf4c00100
        }
    }
    namespace export RADIOCNTL3
    proc RADIOCNTL3 { {base [::CMSDK_BLE_REGS_SECURE::BASE]} } {
        return [expr { [expr $base] + 0x7c }]
    }
    namespace eval RADIOCNTL3 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_BLE_REGS_SECURE::BASE]} } {
            return [expr { [expr $base] + 0x7c }]
        }
        namespace eval TXVALID_BEH {
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
                return 0x00000000
            }
        }
        namespace eval TXRATE0CFG {
            namespace export SHIFT
            proc SHIFT {} {
                return 8
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 2
            }
            namespace export MASK
            proc MASK {} {
                return 0x00000300
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00000300) >> 8}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 8) & 0x00000300}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00000300) | (($field_val << 8) & 0x00000300)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00000300) | (($field_val << 8) & 0x00000300)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 8) & ~0x00000300)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval TXRATE1CFG {
            namespace export SHIFT
            proc SHIFT {} {
                return 10
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 2
            }
            namespace export MASK
            proc MASK {} {
                return 0x00000c00
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00000c00) >> 10}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 10) & 0x00000c00}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00000c00) | (($field_val << 10) & 0x00000c00)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00000c00) | (($field_val << 10) & 0x00000c00)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 10) & ~0x00000c00)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000001
            }
        }
        namespace eval TXRATE2CFG {
            namespace export SHIFT
            proc SHIFT {} {
                return 12
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 2
            }
            namespace export MASK
            proc MASK {} {
                return 0x00003000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00003000) >> 12}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 12) & 0x00003000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00003000) | (($field_val << 12) & 0x00003000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00003000) | (($field_val << 12) & 0x00003000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 12) & ~0x00003000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000002
            }
        }
        namespace eval TXRATE3CFG {
            namespace export SHIFT
            proc SHIFT {} {
                return 14
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 2
            }
            namespace export MASK
            proc MASK {} {
                return 0x0000c000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x0000c000) >> 14}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 14) & 0x0000c000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x0000c000) | (($field_val << 14) & 0x0000c000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x0000c000) | (($field_val << 14) & 0x0000c000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 14) & ~0x0000c000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000003
            }
        }
        namespace eval RXVALID_BEH {
            namespace export SHIFT
            proc SHIFT {} {
                return 16
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 2
            }
            namespace export MASK
            proc MASK {} {
                return 0x00030000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00030000) >> 16}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 16) & 0x00030000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00030000) | (($field_val << 16) & 0x00030000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00030000) | (($field_val << 16) & 0x00030000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 16) & ~0x00030000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval RXSYNC_ROUTING {
            namespace export SHIFT
            proc SHIFT {} {
                return 18
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 1
            }
            namespace export MASK
            proc MASK {} {
                return 0x00040000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00040000) >> 18}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 18) & 0x00040000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00040000) | (($field_val << 18) & 0x00040000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00040000) | (($field_val << 18) & 0x00040000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 18) & ~0x00040000)}]
            }
            namespace export SET
            proc SET {var_name} {
                upvar $var_name var
                set var [expr {($var & ~0x00040000) | (1 << 18)}]
            }
            namespace export SET_TGT
            proc SET_TGT {addr} {
                mww $addr [expr {([mrw $addr] & ~0x00040000) | (1 << 18)}]
            }
            namespace export CLR
            proc CLR {var_name} {
                upvar $var_name var
                set var [expr {$var & ~0x00040000}]
            }
            namespace export CLR_TGT
            proc CLR_TGT {addr} {
                mww $addr [expr {[mrw $addr] & ~0x00040000}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval RXRATE0CFG {
            namespace export SHIFT
            proc SHIFT {} {
                return 24
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 2
            }
            namespace export MASK
            proc MASK {} {
                return 0x03000000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x03000000) >> 24}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 24) & 0x03000000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x03000000) | (($field_val << 24) & 0x03000000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x03000000) | (($field_val << 24) & 0x03000000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 24) & ~0x03000000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval RXRATE1CFG {
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
                return 0x00000001
            }
        }
        namespace eval RXRATE2CFG {
            namespace export SHIFT
            proc SHIFT {} {
                return 28
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 2
            }
            namespace export MASK
            proc MASK {} {
                return 0x30000000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x30000000) >> 28}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 28) & 0x30000000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x30000000) | (($field_val << 28) & 0x30000000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x30000000) | (($field_val << 28) & 0x30000000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 28) & ~0x30000000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000002
            }
        }
        namespace eval RXRATE3CFG {
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
                return 0x00000003
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0xe400e400
        }
    }
    namespace export RADIOPWRUPDN0
    proc RADIOPWRUPDN0 { {base [::CMSDK_BLE_REGS_SECURE::BASE]} } {
        return [expr { [expr $base] + 0x80 }]
    }
    namespace eval RADIOPWRUPDN0 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_BLE_REGS_SECURE::BASE]} } {
            return [expr { [expr $base] + 0x80 }]
        }
        namespace eval TXPWRUP0 {
            namespace export SHIFT
            proc SHIFT {} {
                return 0
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 8
            }
            namespace export MASK
            proc MASK {} {
                return 0x000000ff
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x000000ff) >> 0}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 0) & 0x000000ff}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x000000ff) | (($field_val << 0) & 0x000000ff)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x000000ff) | (($field_val << 0) & 0x000000ff)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 0) & ~0x000000ff)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000032
            }
        }
        namespace eval TXPWRDN0 {
            namespace export SHIFT
            proc SHIFT {} {
                return 8
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 7
            }
            namespace export MASK
            proc MASK {} {
                return 0x00007f00
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00007f00) >> 8}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 8) & 0x00007f00}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00007f00) | (($field_val << 8) & 0x00007f00)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00007f00) | (($field_val << 8) & 0x00007f00)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 8) & ~0x00007f00)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000002
            }
        }
        namespace eval RXPWRUP0 {
            namespace export SHIFT
            proc SHIFT {} {
                return 16
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 8
            }
            namespace export MASK
            proc MASK {} {
                return 0x00ff0000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00ff0000) >> 16}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 16) & 0x00ff0000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00ff0000) | (($field_val << 16) & 0x00ff0000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00ff0000) | (($field_val << 16) & 0x00ff0000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 16) & ~0x00ff0000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000058
            }
        }
        namespace eval SYNC_POSITION0 {
            namespace export SHIFT
            proc SHIFT {} {
                return 24
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 8
            }
            namespace export MASK
            proc MASK {} {
                return 0xff000000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0xff000000) >> 24}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 24) & 0xff000000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0xff000000) | (($field_val << 24) & 0xff000000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0xff000000) | (($field_val << 24) & 0xff000000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 24) & ~0xff000000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x00580232
        }
    }
    namespace export RADIOPWRUPDN1
    proc RADIOPWRUPDN1 { {base [::CMSDK_BLE_REGS_SECURE::BASE]} } {
        return [expr { [expr $base] + 0x84 }]
    }
    namespace eval RADIOPWRUPDN1 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_BLE_REGS_SECURE::BASE]} } {
            return [expr { [expr $base] + 0x84 }]
        }
        namespace eval TXPWRUP1 {
            namespace export SHIFT
            proc SHIFT {} {
                return 0
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 8
            }
            namespace export MASK
            proc MASK {} {
                return 0x000000ff
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x000000ff) >> 0}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 0) & 0x000000ff}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x000000ff) | (($field_val << 0) & 0x000000ff)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x000000ff) | (($field_val << 0) & 0x000000ff)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 0) & ~0x000000ff)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000032
            }
        }
        namespace eval TXPWRDN1 {
            namespace export SHIFT
            proc SHIFT {} {
                return 8
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 7
            }
            namespace export MASK
            proc MASK {} {
                return 0x00007f00
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00007f00) >> 8}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 8) & 0x00007f00}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00007f00) | (($field_val << 8) & 0x00007f00)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00007f00) | (($field_val << 8) & 0x00007f00)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 8) & ~0x00007f00)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000002
            }
        }
        namespace eval RXPWRUP1 {
            namespace export SHIFT
            proc SHIFT {} {
                return 16
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 8
            }
            namespace export MASK
            proc MASK {} {
                return 0x00ff0000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00ff0000) >> 16}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 16) & 0x00ff0000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00ff0000) | (($field_val << 16) & 0x00ff0000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00ff0000) | (($field_val << 16) & 0x00ff0000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 16) & ~0x00ff0000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000058
            }
        }
        namespace eval SYNC_POSITION1 {
            namespace export SHIFT
            proc SHIFT {} {
                return 24
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 8
            }
            namespace export MASK
            proc MASK {} {
                return 0xff000000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0xff000000) >> 24}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 24) & 0xff000000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0xff000000) | (($field_val << 24) & 0xff000000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0xff000000) | (($field_val << 24) & 0xff000000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 24) & ~0xff000000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x00580232
        }
    }
    namespace export RADIOPWRUPDN2
    proc RADIOPWRUPDN2 { {base [::CMSDK_BLE_REGS_SECURE::BASE]} } {
        return [expr { [expr $base] + 0x88 }]
    }
    namespace eval RADIOPWRUPDN2 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_BLE_REGS_SECURE::BASE]} } {
            return [expr { [expr $base] + 0x88 }]
        }
        namespace eval TXPWRUP2 {
            namespace export SHIFT
            proc SHIFT {} {
                return 0
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 8
            }
            namespace export MASK
            proc MASK {} {
                return 0x000000ff
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x000000ff) >> 0}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 0) & 0x000000ff}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x000000ff) | (($field_val << 0) & 0x000000ff)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x000000ff) | (($field_val << 0) & 0x000000ff)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 0) & ~0x000000ff)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000032
            }
        }
        namespace eval TXPWRDN2 {
            namespace export SHIFT
            proc SHIFT {} {
                return 8
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 7
            }
            namespace export MASK
            proc MASK {} {
                return 0x00007f00
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00007f00) >> 8}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 8) & 0x00007f00}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00007f00) | (($field_val << 8) & 0x00007f00)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00007f00) | (($field_val << 8) & 0x00007f00)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 8) & ~0x00007f00)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000002
            }
        }
        namespace eval RXPWRUP2 {
            namespace export SHIFT
            proc SHIFT {} {
                return 16
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 8
            }
            namespace export MASK
            proc MASK {} {
                return 0x00ff0000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00ff0000) >> 16}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 16) & 0x00ff0000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00ff0000) | (($field_val << 16) & 0x00ff0000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00ff0000) | (($field_val << 16) & 0x00ff0000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 16) & ~0x00ff0000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000058
            }
        }
        namespace eval SYNC_POSITION2 {
            namespace export SHIFT
            proc SHIFT {} {
                return 24
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 8
            }
            namespace export MASK
            proc MASK {} {
                return 0xff000000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0xff000000) >> 24}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 24) & 0xff000000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0xff000000) | (($field_val << 24) & 0xff000000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0xff000000) | (($field_val << 24) & 0xff000000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 24) & ~0xff000000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x00580232
        }
    }
    namespace export RADIOPWRUPDN3
    proc RADIOPWRUPDN3 { {base [::CMSDK_BLE_REGS_SECURE::BASE]} } {
        return [expr { [expr $base] + 0x8c }]
    }
    namespace eval RADIOPWRUPDN3 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_BLE_REGS_SECURE::BASE]} } {
            return [expr { [expr $base] + 0x8c }]
        }
        namespace eval TXPWRUP3 {
            namespace export SHIFT
            proc SHIFT {} {
                return 0
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 8
            }
            namespace export MASK
            proc MASK {} {
                return 0x000000ff
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x000000ff) >> 0}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 0) & 0x000000ff}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x000000ff) | (($field_val << 0) & 0x000000ff)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x000000ff) | (($field_val << 0) & 0x000000ff)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 0) & ~0x000000ff)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000032
            }
        }
        namespace eval TXPWRDN3 {
            namespace export SHIFT
            proc SHIFT {} {
                return 8
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 7
            }
            namespace export MASK
            proc MASK {} {
                return 0x00007f00
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00007f00) >> 8}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 8) & 0x00007f00}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00007f00) | (($field_val << 8) & 0x00007f00)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00007f00) | (($field_val << 8) & 0x00007f00)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 8) & ~0x00007f00)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000002
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x00000232
        }
    }
    namespace export RADIOTXRXTIM0
    proc RADIOTXRXTIM0 { {base [::CMSDK_BLE_REGS_SECURE::BASE]} } {
        return [expr { [expr $base] + 0x90 }]
    }
    namespace eval RADIOTXRXTIM0 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_BLE_REGS_SECURE::BASE]} } {
            return [expr { [expr $base] + 0x90 }]
        }
        namespace eval TXPATHDLY0 {
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
                return 0x00000001
            }
        }
        namespace eval RXPATHDLY0 {
            namespace export SHIFT
            proc SHIFT {} {
                return 8
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 7
            }
            namespace export MASK
            proc MASK {} {
                return 0x00007f00
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00007f00) >> 8}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 8) & 0x00007f00}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00007f00) | (($field_val << 8) & 0x00007f00)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00007f00) | (($field_val << 8) & 0x00007f00)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 8) & ~0x00007f00)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000004
            }
        }
        namespace eval RFRXTMDA0 {
            namespace export SHIFT
            proc SHIFT {} {
                return 16
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 7
            }
            namespace export MASK
            proc MASK {} {
                return 0x007f0000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x007f0000) >> 16}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 16) & 0x007f0000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x007f0000) | (($field_val << 16) & 0x007f0000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x007f0000) | (($field_val << 16) & 0x007f0000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 16) & ~0x007f0000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x00000401
        }
    }
    namespace export RADIOTXRXTIM1
    proc RADIOTXRXTIM1 { {base [::CMSDK_BLE_REGS_SECURE::BASE]} } {
        return [expr { [expr $base] + 0x94 }]
    }
    namespace eval RADIOTXRXTIM1 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_BLE_REGS_SECURE::BASE]} } {
            return [expr { [expr $base] + 0x94 }]
        }
        namespace eval TXPATHDLY1 {
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
                return 0x00000001
            }
        }
        namespace eval RXPATHDLY1 {
            namespace export SHIFT
            proc SHIFT {} {
                return 8
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 7
            }
            namespace export MASK
            proc MASK {} {
                return 0x00007f00
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00007f00) >> 8}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 8) & 0x00007f00}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00007f00) | (($field_val << 8) & 0x00007f00)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00007f00) | (($field_val << 8) & 0x00007f00)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 8) & ~0x00007f00)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000002
            }
        }
        namespace eval RFRXTMDA1 {
            namespace export SHIFT
            proc SHIFT {} {
                return 16
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 7
            }
            namespace export MASK
            proc MASK {} {
                return 0x007f0000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x007f0000) >> 16}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 16) & 0x007f0000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x007f0000) | (($field_val << 16) & 0x007f0000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x007f0000) | (($field_val << 16) & 0x007f0000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 16) & ~0x007f0000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x00000201
        }
    }
    namespace export RADIOTXRXTIM2
    proc RADIOTXRXTIM2 { {base [::CMSDK_BLE_REGS_SECURE::BASE]} } {
        return [expr { [expr $base] + 0x98 }]
    }
    namespace eval RADIOTXRXTIM2 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_BLE_REGS_SECURE::BASE]} } {
            return [expr { [expr $base] + 0x98 }]
        }
        namespace eval TXPATHDLY2 {
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
                return 0x00000001
            }
        }
        namespace eval RXPATHDLY2 {
            namespace export SHIFT
            proc SHIFT {} {
                return 8
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 8
            }
            namespace export MASK
            proc MASK {} {
                return 0x0000ff00
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x0000ff00) >> 8}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 8) & 0x0000ff00}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x0000ff00) | (($field_val << 8) & 0x0000ff00)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x0000ff00) | (($field_val << 8) & 0x0000ff00)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 8) & ~0x0000ff00)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x0000002c
            }
        }
        namespace eval RFRXTMDA2 {
            namespace export SHIFT
            proc SHIFT {} {
                return 16
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 8
            }
            namespace export MASK
            proc MASK {} {
                return 0x00ff0000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00ff0000) >> 16}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 16) & 0x00ff0000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00ff0000) | (($field_val << 16) & 0x00ff0000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00ff0000) | (($field_val << 16) & 0x00ff0000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 16) & ~0x00ff0000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval RXFLUSHPATHDLY2 {
            namespace export SHIFT
            proc SHIFT {} {
                return 24
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 8
            }
            namespace export MASK
            proc MASK {} {
                return 0xff000000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0xff000000) >> 24}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 24) & 0xff000000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0xff000000) | (($field_val << 24) & 0xff000000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0xff000000) | (($field_val << 24) & 0xff000000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 24) & ~0xff000000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x0000000d
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x0d002c01
        }
    }
    namespace export RADIOTXRXTIM3
    proc RADIOTXRXTIM3 { {base [::CMSDK_BLE_REGS_SECURE::BASE]} } {
        return [expr { [expr $base] + 0x9c }]
    }
    namespace eval RADIOTXRXTIM3 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_BLE_REGS_SECURE::BASE]} } {
            return [expr { [expr $base] + 0x9c }]
        }
        namespace eval TXPATHDLY3 {
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
                return 0x00000001
            }
        }
        namespace eval RFRXTMDA3 {
            namespace export SHIFT
            proc SHIFT {} {
                return 16
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 8
            }
            namespace export MASK
            proc MASK {} {
                return 0x00ff0000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00ff0000) >> 16}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 16) & 0x00ff0000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00ff0000) | (($field_val << 16) & 0x00ff0000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00ff0000) | (($field_val << 16) & 0x00ff0000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 16) & ~0x00ff0000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval RXFLUSHPATHDLY3 {
            namespace export SHIFT
            proc SHIFT {} {
                return 24
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 8
            }
            namespace export MASK
            proc MASK {} {
                return 0xff000000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0xff000000) >> 24}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 24) & 0xff000000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0xff000000) | (($field_val << 24) & 0xff000000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0xff000000) | (($field_val << 24) & 0xff000000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 24) & ~0xff000000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x0000000d
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x0d000001
        }
    }
    namespace export RFTESTCNTL
    proc RFTESTCNTL { {base [::CMSDK_BLE_REGS_SECURE::BASE]} } {
        return [expr { [expr $base] + 0xd0 }]
    }
    namespace eval RFTESTCNTL {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_BLE_REGS_SECURE::BASE]} } {
            return [expr { [expr $base] + 0xd0 }]
        }
        namespace eval TXLENGTH {
            namespace export SHIFT
            proc SHIFT {} {
                return 0
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 9
            }
            namespace export MASK
            proc MASK {} {
                return 0x000001ff
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x000001ff) >> 0}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 0) & 0x000001ff}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x000001ff) | (($field_val << 0) & 0x000001ff)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x000001ff) | (($field_val << 0) & 0x000001ff)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 0) & ~0x000001ff)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval TXPKTCNTEN {
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
        namespace eval TXPLDSRC {
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
        namespace eval PRBSTYPE {
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
        namespace eval TXLENGTHSRC {
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
        namespace eval INFINITETX {
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
        namespace eval PERCOUNT_MODE {
            namespace export SHIFT
            proc SHIFT {} {
                return 24
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 2
            }
            namespace export MASK
            proc MASK {} {
                return 0x03000000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x03000000) >> 24}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 24) & 0x03000000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x03000000) | (($field_val << 24) & 0x03000000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x03000000) | (($field_val << 24) & 0x03000000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 24) & ~0x03000000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval RXPKTCNTEN {
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
        namespace eval INFINITERX {
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
            return 0x00000000
        }
    }
    namespace export RFTESTTXSTAT
    proc RFTESTTXSTAT { {base [::CMSDK_BLE_REGS_SECURE::BASE]} } {
        return [expr { [expr $base] + 0xd4 }]
    }
    namespace eval RFTESTTXSTAT {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_BLE_REGS_SECURE::BASE]} } {
            return [expr { [expr $base] + 0xd4 }]
        }
        namespace eval TXPKTCNT {
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
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 0) & 0xffffffff}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0xffffffff) | (($field_val << 0) & 0xffffffff)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0xffffffff) | (($field_val << 0) & 0xffffffff)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 0) & ~0xffffffff)}]
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
    namespace export RFTESTRXSTAT
    proc RFTESTRXSTAT { {base [::CMSDK_BLE_REGS_SECURE::BASE]} } {
        return [expr { [expr $base] + 0xd8 }]
    }
    namespace eval RFTESTRXSTAT {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_BLE_REGS_SECURE::BASE]} } {
            return [expr { [expr $base] + 0xd8 }]
        }
        namespace eval RXPKTCNT {
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
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 0) & 0xffffffff}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0xffffffff) | (($field_val << 0) & 0xffffffff)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0xffffffff) | (($field_val << 0) & 0xffffffff)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 0) & ~0xffffffff)}]
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
    namespace export COEXIFCNTL0
    proc COEXIFCNTL0 { {base [::CMSDK_BLE_REGS_SECURE::BASE]} } {
        return [expr { [expr $base] + 0x150 }]
    }
    namespace eval COEXIFCNTL0 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_BLE_REGS_SECURE::BASE]} } {
            return [expr { [expr $base] + 0x150 }]
        }
        namespace eval WLANCOEX_EN {
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
        namespace eval SYNCGEN_EN {
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
        namespace eval MWSCOEX_EN {
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
        namespace eval MWSWCI_EN {
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
        namespace eval WLANRXMSK {
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
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 4) & 0x00000030}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00000030) | (($field_val << 4) & 0x00000030)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00000030) | (($field_val << 4) & 0x00000030)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 4) & ~0x00000030)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000001
            }
        }
        namespace eval WLANTXMSK {
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
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 6) & 0x000000c0}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x000000c0) | (($field_val << 6) & 0x000000c0)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x000000c0) | (($field_val << 6) & 0x000000c0)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 6) & ~0x000000c0)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval MWSRXMSK {
            namespace export SHIFT
            proc SHIFT {} {
                return 8
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 2
            }
            namespace export MASK
            proc MASK {} {
                return 0x00000300
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00000300) >> 8}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 8) & 0x00000300}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00000300) | (($field_val << 8) & 0x00000300)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00000300) | (($field_val << 8) & 0x00000300)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 8) & ~0x00000300)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval MWSTXMSK {
            namespace export SHIFT
            proc SHIFT {} {
                return 10
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 2
            }
            namespace export MASK
            proc MASK {} {
                return 0x00000c00
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00000c00) >> 10}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 10) & 0x00000c00}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00000c00) | (($field_val << 10) & 0x00000c00)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00000c00) | (($field_val << 10) & 0x00000c00)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 10) & ~0x00000c00)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval MWSRXFREQMSK {
            namespace export SHIFT
            proc SHIFT {} {
                return 12
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 2
            }
            namespace export MASK
            proc MASK {} {
                return 0x00003000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00003000) >> 12}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 12) & 0x00003000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00003000) | (($field_val << 12) & 0x00003000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00003000) | (($field_val << 12) & 0x00003000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 12) & ~0x00003000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval MWSTXFREQMSK {
            namespace export SHIFT
            proc SHIFT {} {
                return 14
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 2
            }
            namespace export MASK
            proc MASK {} {
                return 0x0000c000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x0000c000) >> 14}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 14) & 0x0000c000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x0000c000) | (($field_val << 14) & 0x0000c000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x0000c000) | (($field_val << 14) & 0x0000c000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 14) & ~0x0000c000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval WLCTXPRIOMODE {
            namespace export SHIFT
            proc SHIFT {} {
                return 16
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 2
            }
            namespace export MASK
            proc MASK {} {
                return 0x00030000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00030000) >> 16}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 16) & 0x00030000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00030000) | (($field_val << 16) & 0x00030000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00030000) | (($field_val << 16) & 0x00030000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 16) & ~0x00030000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval WLCRXPRIOMODE {
            namespace export SHIFT
            proc SHIFT {} {
                return 18
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 2
            }
            namespace export MASK
            proc MASK {} {
                return 0x000c0000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x000c0000) >> 18}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 18) & 0x000c0000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x000c0000) | (($field_val << 18) & 0x000c0000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x000c0000) | (($field_val << 18) & 0x000c0000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 18) & ~0x000c0000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval MWSSCANFREQMSK {
            namespace export SHIFT
            proc SHIFT {} {
                return 20
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 2
            }
            namespace export MASK
            proc MASK {} {
                return 0x00300000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00300000) >> 20}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 20) & 0x00300000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00300000) | (($field_val << 20) & 0x00300000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00300000) | (($field_val << 20) & 0x00300000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 20) & ~0x00300000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x00000010
        }
    }
    namespace export COEXIFCNTL1
    proc COEXIFCNTL1 { {base [::CMSDK_BLE_REGS_SECURE::BASE]} } {
        return [expr { [expr $base] + 0x154 }]
    }
    namespace eval COEXIFCNTL1 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_BLE_REGS_SECURE::BASE]} } {
            return [expr { [expr $base] + 0x154 }]
        }
        namespace eval WLCPDELAY {
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
                return 0x00000000
            }
        }
        namespace eval WLCPDURATION {
            namespace export SHIFT
            proc SHIFT {} {
                return 8
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 7
            }
            namespace export MASK
            proc MASK {} {
                return 0x00007f00
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00007f00) >> 8}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 8) & 0x00007f00}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00007f00) | (($field_val << 8) & 0x00007f00)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00007f00) | (($field_val << 8) & 0x00007f00)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 8) & ~0x00007f00)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval WLCPTXTHR {
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
                return 0x00000000
            }
        }
        namespace eval WLCPRXTHR {
            namespace export SHIFT
            proc SHIFT {} {
                return 24
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 5
            }
            namespace export MASK
            proc MASK {} {
                return 0x1f000000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x1f000000) >> 24}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 24) & 0x1f000000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x1f000000) | (($field_val << 24) & 0x1f000000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x1f000000) | (($field_val << 24) & 0x1f000000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 24) & ~0x1f000000)}]
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
    namespace export DFCNTL0_1US
    proc DFCNTL0_1US { {base [::CMSDK_BLE_REGS_SECURE::BASE]} } {
        return [expr { [expr $base] + 0x180 }]
    }
    namespace eval DFCNTL0_1US {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_BLE_REGS_SECURE::BASE]} } {
            return [expr { [expr $base] + 0x180 }]
        }
        namespace eval TXSWSTINST0_1US {
            namespace export SHIFT
            proc SHIFT {} {
                return 0
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 8
            }
            namespace export MASK
            proc MASK {} {
                return 0x000000ff
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x000000ff) >> 0}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 0) & 0x000000ff}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x000000ff) | (($field_val << 0) & 0x000000ff)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x000000ff) | (($field_val << 0) & 0x000000ff)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 0) & ~0x000000ff)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x0000001a
            }
        }
        namespace eval RXSWSTINST0_1US {
            namespace export SHIFT
            proc SHIFT {} {
                return 16
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 8
            }
            namespace export MASK
            proc MASK {} {
                return 0x00ff0000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00ff0000) >> 16}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 16) & 0x00ff0000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00ff0000) | (($field_val << 16) & 0x00ff0000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00ff0000) | (($field_val << 16) & 0x00ff0000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 16) & ~0x00ff0000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x0000001a
            }
        }
        namespace eval RXSAMPSTINST0_1US {
            namespace export SHIFT
            proc SHIFT {} {
                return 24
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 8
            }
            namespace export MASK
            proc MASK {} {
                return 0xff000000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0xff000000) >> 24}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 24) & 0xff000000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0xff000000) | (($field_val << 24) & 0xff000000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0xff000000) | (($field_val << 24) & 0xff000000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 24) & ~0xff000000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000009
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x091a001a
        }
    }
    namespace export DFCNTL0_2US
    proc DFCNTL0_2US { {base [::CMSDK_BLE_REGS_SECURE::BASE]} } {
        return [expr { [expr $base] + 0x184 }]
    }
    namespace eval DFCNTL0_2US {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_BLE_REGS_SECURE::BASE]} } {
            return [expr { [expr $base] + 0x184 }]
        }
        namespace eval TXSWSTINST0_2US {
            namespace export SHIFT
            proc SHIFT {} {
                return 0
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 8
            }
            namespace export MASK
            proc MASK {} {
                return 0x000000ff
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x000000ff) >> 0}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 0) & 0x000000ff}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x000000ff) | (($field_val << 0) & 0x000000ff)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x000000ff) | (($field_val << 0) & 0x000000ff)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 0) & ~0x000000ff)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x0000001a
            }
        }
        namespace eval RXSWSTINST0_2US {
            namespace export SHIFT
            proc SHIFT {} {
                return 16
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 8
            }
            namespace export MASK
            proc MASK {} {
                return 0x00ff0000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00ff0000) >> 16}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 16) & 0x00ff0000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00ff0000) | (($field_val << 16) & 0x00ff0000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00ff0000) | (($field_val << 16) & 0x00ff0000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 16) & ~0x00ff0000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x0000001a
            }
        }
        namespace eval RXSAMPSTINST0_2US {
            namespace export SHIFT
            proc SHIFT {} {
                return 24
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 8
            }
            namespace export MASK
            proc MASK {} {
                return 0xff000000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0xff000000) >> 24}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 24) & 0xff000000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0xff000000) | (($field_val << 24) & 0xff000000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0xff000000) | (($field_val << 24) & 0xff000000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 24) & ~0xff000000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000009
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x091a001a
        }
    }
    namespace export DFCNTL1_1US
    proc DFCNTL1_1US { {base [::CMSDK_BLE_REGS_SECURE::BASE]} } {
        return [expr { [expr $base] + 0x188 }]
    }
    namespace eval DFCNTL1_1US {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_BLE_REGS_SECURE::BASE]} } {
            return [expr { [expr $base] + 0x188 }]
        }
        namespace eval TXSWSTINST1_1US {
            namespace export SHIFT
            proc SHIFT {} {
                return 0
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 8
            }
            namespace export MASK
            proc MASK {} {
                return 0x000000ff
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x000000ff) >> 0}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 0) & 0x000000ff}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x000000ff) | (($field_val << 0) & 0x000000ff)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x000000ff) | (($field_val << 0) & 0x000000ff)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 0) & ~0x000000ff)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000019
            }
        }
        namespace eval RXSWSTINST1_1US {
            namespace export SHIFT
            proc SHIFT {} {
                return 16
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 8
            }
            namespace export MASK
            proc MASK {} {
                return 0x00ff0000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00ff0000) >> 16}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 16) & 0x00ff0000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00ff0000) | (($field_val << 16) & 0x00ff0000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00ff0000) | (($field_val << 16) & 0x00ff0000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 16) & ~0x00ff0000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000018
            }
        }
        namespace eval RXSAMPSTINST1_1US {
            namespace export SHIFT
            proc SHIFT {} {
                return 24
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 8
            }
            namespace export MASK
            proc MASK {} {
                return 0xff000000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0xff000000) >> 24}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 24) & 0xff000000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0xff000000) | (($field_val << 24) & 0xff000000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0xff000000) | (($field_val << 24) & 0xff000000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 24) & ~0xff000000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000007
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x07180019
        }
    }
    namespace export DFCNTL1_2US
    proc DFCNTL1_2US { {base [::CMSDK_BLE_REGS_SECURE::BASE]} } {
        return [expr { [expr $base] + 0x18c }]
    }
    namespace eval DFCNTL1_2US {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_BLE_REGS_SECURE::BASE]} } {
            return [expr { [expr $base] + 0x18c }]
        }
        namespace eval TXSWSTINST1_2US {
            namespace export SHIFT
            proc SHIFT {} {
                return 0
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 8
            }
            namespace export MASK
            proc MASK {} {
                return 0x000000ff
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x000000ff) >> 0}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 0) & 0x000000ff}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x000000ff) | (($field_val << 0) & 0x000000ff)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x000000ff) | (($field_val << 0) & 0x000000ff)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 0) & ~0x000000ff)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000019
            }
        }
        namespace eval RXSWSTINST1_2US {
            namespace export SHIFT
            proc SHIFT {} {
                return 16
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 8
            }
            namespace export MASK
            proc MASK {} {
                return 0x00ff0000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00ff0000) >> 16}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 16) & 0x00ff0000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00ff0000) | (($field_val << 16) & 0x00ff0000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00ff0000) | (($field_val << 16) & 0x00ff0000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 16) & ~0x00ff0000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000018
            }
        }
        namespace eval RXSAMPSTINST1_2US {
            namespace export SHIFT
            proc SHIFT {} {
                return 24
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 8
            }
            namespace export MASK
            proc MASK {} {
                return 0xff000000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0xff000000) >> 24}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 24) & 0xff000000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0xff000000) | (($field_val << 24) & 0xff000000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0xff000000) | (($field_val << 24) & 0xff000000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 24) & ~0xff000000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000007
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x07180019
        }
    }
}
