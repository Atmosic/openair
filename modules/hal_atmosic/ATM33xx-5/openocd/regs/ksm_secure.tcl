namespace eval CMSDK_KSM_SECURE {
    namespace export BASE
    proc BASE {} {
        return 0x5014a000
    }
    namespace export CTRL0
    proc CTRL0 { {base [::CMSDK_KSM_SECURE::BASE]} } {
        return [expr { [expr $base] + 0x0 }]
    }
    namespace eval CTRL0 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_KSM_SECURE::BASE]} } {
            return [expr { [expr $base] + 0x0 }]
        }
        namespace eval GO {
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
        namespace eval LOOPBACK {
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
        namespace eval POP {
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
        namespace eval FLUSH {
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
        namespace eval CONSECSCAN {
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
                return 0x00000008
            }
        }
        namespace eval KSM_NOT_EMPTY_TO_INTRPT {
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
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x00000800
        }
    }
    namespace export TIME_PARAM0
    proc TIME_PARAM0 { {base [::CMSDK_KSM_SECURE::BASE]} } {
        return [expr { [expr $base] + 0x4 }]
    }
    namespace eval TIME_PARAM0 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_KSM_SECURE::BASE]} } {
            return [expr { [expr $base] + 0x4 }]
        }
        namespace eval T2 {
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
                return 0x00000010
            }
        }
        namespace eval T1 {
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
                return 0x00000010
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x00100010
        }
    }
    namespace export TIME_PARAM1
    proc TIME_PARAM1 { {base [::CMSDK_KSM_SECURE::BASE]} } {
        return [expr { [expr $base] + 0x8 }]
    }
    namespace eval TIME_PARAM1 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_KSM_SECURE::BASE]} } {
            return [expr { [expr $base] + 0x8 }]
        }
        namespace eval T4 {
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
                return 0x00000040
            }
        }
        namespace eval T3 {
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
                return 0x00000008
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x00080040
        }
    }
    namespace export MATRIX_SIZE
    proc MATRIX_SIZE { {base [::CMSDK_KSM_SECURE::BASE]} } {
        return [expr { [expr $base] + 0xc }]
    }
    namespace eval MATRIX_SIZE {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_KSM_SECURE::BASE]} } {
            return [expr { [expr $base] + 0xc }]
        }
        namespace eval NUM_COL {
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
                return 0x00000007
            }
        }
        namespace eval NUM_ROW {
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
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 8) & 0x00001f00}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00001f00) | (($field_val << 8) & 0x00001f00)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00001f00) | (($field_val << 8) & 0x00001f00)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 8) & ~0x00001f00)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000013
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x00001307
        }
    }
    namespace export KEYBOARD_PACKET
    proc KEYBOARD_PACKET { {base [::CMSDK_KSM_SECURE::BASE]} } {
        return [expr { [expr $base] + 0x40 }]
    }
    namespace eval KEYBOARD_PACKET {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_KSM_SECURE::BASE]} } {
            return [expr { [expr $base] + 0x40 }]
        }
        namespace eval ROW {
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
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval COL {
            namespace export SHIFT
            proc SHIFT {} {
                return 5
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 5
            }
            namespace export MASK
            proc MASK {} {
                return 0x000003e0
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x000003e0) >> 5}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval PRESSED_RELEASED_N {
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
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval EMPTY {
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
    namespace export LOW_POWER
    proc LOW_POWER { {base [::CMSDK_KSM_SECURE::BASE]} } {
        return [expr { [expr $base] + 0x44 }]
    }
    namespace eval LOW_POWER {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_KSM_SECURE::BASE]} } {
            return [expr { [expr $base] + 0x44 }]
        }
        namespace eval KEY {
            namespace export SHIFT
            proc SHIFT {} {
                return 0
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 11
            }
            namespace export MASK
            proc MASK {} {
                return 0x000007ff
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x000007ff) >> 0}]
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
    namespace export LPBACK_KSI
    proc LPBACK_KSI { {base [::CMSDK_KSM_SECURE::BASE]} } {
        return [expr { [expr $base] + 0x58 }]
    }
    namespace eval LPBACK_KSI {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_KSM_SECURE::BASE]} } {
            return [expr { [expr $base] + 0x58 }]
        }
        namespace eval LPBACK_KSI {
            namespace export SHIFT
            proc SHIFT {} {
                return 0
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 20
            }
            namespace export MASK
            proc MASK {} {
                return 0x000fffff
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x000fffff) >> 0}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 0) & 0x000fffff}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x000fffff) | (($field_val << 0) & 0x000fffff)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x000fffff) | (($field_val << 0) & 0x000fffff)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 0) & ~0x000fffff)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x000fffff
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x000fffff
        }
    }
    namespace export STATUS
    proc STATUS { {base [::CMSDK_KSM_SECURE::BASE]} } {
        return [expr { [expr $base] + 0x80 }]
    }
    namespace eval STATUS {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_KSM_SECURE::BASE]} } {
            return [expr { [expr $base] + 0x80 }]
        }
        namespace eval COMMAND_TAKEN {
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
    namespace export INTERRUPTS
    proc INTERRUPTS { {base [::CMSDK_KSM_SECURE::BASE]} } {
        return [expr { [expr $base] + 0xc0 }]
    }
    namespace eval INTERRUPTS {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_KSM_SECURE::BASE]} } {
            return [expr { [expr $base] + 0xc0 }]
        }
        namespace eval INTRPT0 {
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
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval INTRPT1 {
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
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval INTRPT2 {
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
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval INTRPT3 {
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
    namespace export INTERRUPT_MASK
    proc INTERRUPT_MASK { {base [::CMSDK_KSM_SECURE::BASE]} } {
        return [expr { [expr $base] + 0xc4 }]
    }
    namespace eval INTERRUPT_MASK {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_KSM_SECURE::BASE]} } {
            return [expr { [expr $base] + 0xc4 }]
        }
        namespace eval MASK_INTRPT0 {
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
                return 0x00000001
            }
        }
        namespace eval MASK_INTRPT1 {
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
                return 0x00000001
            }
        }
        namespace eval MASK_INTRPT2 {
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
                return 0x00000001
            }
        }
        namespace eval MASK_INTRPT3 {
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
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x0000000f
        }
    }
    namespace export INTERRUPT_CLEAR
    proc INTERRUPT_CLEAR { {base [::CMSDK_KSM_SECURE::BASE]} } {
        return [expr { [expr $base] + 0xc8 }]
    }
    namespace eval INTERRUPT_CLEAR {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_KSM_SECURE::BASE]} } {
            return [expr { [expr $base] + 0xc8 }]
        }
        namespace eval CLEAR_INTRPT0 {
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
        namespace eval CLEAR_INTRPT1 {
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
        namespace eval CLEAR_INTRPT2 {
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
        namespace eval CLEAR_INTRPT3 {
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
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x00000000
        }
    }
    namespace export DEBUG
    proc DEBUG { {base [::CMSDK_KSM_SECURE::BASE]} } {
        return [expr { [expr $base] + 0xff4 }]
    }
    namespace eval DEBUG {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_KSM_SECURE::BASE]} } {
            return [expr { [expr $base] + 0xff4 }]
        }
        namespace eval KB {
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
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval FIFO {
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
    namespace export DEBUG2
    proc DEBUG2 { {base [::CMSDK_KSM_SECURE::BASE]} } {
        return [expr { [expr $base] + 0xff8 }]
    }
    namespace eval DEBUG2 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_KSM_SECURE::BASE]} } {
            return [expr { [expr $base] + 0xff8 }]
        }
        namespace eval KR {
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
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval KP {
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
    proc CORE_ID { {base [::CMSDK_KSM_SECURE::BASE]} } {
        return [expr { [expr $base] + 0xffc }]
    }
    namespace eval CORE_ID {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_KSM_SECURE::BASE]} } {
            return [expr { [expr $base] + 0xffc }]
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
                return 0x4b534d20
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x4b534d20
        }
    }
}
