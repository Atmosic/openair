namespace eval CMSDK_NVM_NONSECURE {
    namespace export BASE
    proc BASE {} {
        return 0x40152000
    }
    namespace export OPMODE
    proc OPMODE { {base [::CMSDK_NVM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x0 }]
    }
    namespace eval OPMODE {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_NVM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x0 }]
        }
        namespace eval READ {
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
        namespace eval PROGRAM {
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
        namespace eval GO {
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
    namespace export OPMODE1
    proc OPMODE1 { {base [::CMSDK_NVM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x4 }]
    }
    namespace eval OPMODE1 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_NVM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x4 }]
        }
        namespace eval OTP_A {
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
        namespace eval OTP_A_MAP {
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
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x00000000
        }
    }
    namespace export STATUS
    proc STATUS { {base [::CMSDK_NVM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x8 }]
    }
    namespace eval STATUS {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_NVM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x8 }]
        }
        namespace eval DONE {
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
        namespace eval OTP_Q {
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
        namespace eval RUNNING {
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
    namespace export STATUS1
    proc STATUS1 { {base [::CMSDK_NVM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0xc }]
    }
    namespace eval STATUS1 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_NVM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0xc }]
        }
        namespace eval AUTO_READ_BUSY {
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
    namespace export OTP_CFG_LOW
    proc OTP_CFG_LOW { {base [::CMSDK_NVM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x10 }]
    }
    namespace eval OTP_CFG_LOW {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_NVM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x10 }]
        }
        namespace eval OTP_CFG_LOW {
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
                return 0x00000000
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x00000000
        }
    }
    namespace export OTP_CFG_HIGH
    proc OTP_CFG_HIGH { {base [::CMSDK_NVM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x14 }]
    }
    namespace eval OTP_CFG_HIGH {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_NVM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x14 }]
        }
        namespace eval OTP_CFG_HIGH {
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
                return 0x00000000
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x00000000
        }
    }
    namespace export T_RD_TIME0
    proc T_RD_TIME0 { {base [::CMSDK_NVM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x18 }]
    }
    namespace eval T_RD_TIME0 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_NVM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x18 }]
        }
        namespace eval T_SUR_PG {
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
        namespace eval T_SUR_CS {
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
                return 0x00000001
            }
        }
        namespace eval T_SUR_PS_CS {
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
                return 0x00000001
            }
        }
        namespace eval T_SUR_PD_CS {
            namespace export SHIFT
            proc SHIFT {} {
                return 24
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 4
            }
            namespace export MASK
            proc MASK {} {
                return 0x0f000000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x0f000000) >> 24}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 24) & 0x0f000000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x0f000000) | (($field_val << 24) & 0x0f000000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x0f000000) | (($field_val << 24) & 0x0f000000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 24) & ~0x0f000000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000009
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x09010101
        }
    }
    namespace export T_RD_TIME1
    proc T_RD_TIME1 { {base [::CMSDK_NVM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x1c }]
    }
    namespace eval T_RD_TIME1 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_NVM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x1c }]
        }
        namespace eval T_SUR_PS {
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
        namespace eval T_SUR_PD {
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
                return 0x00000009
            }
        }
        namespace eval T_SUR_A {
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
                return 0x00000001
            }
        }
        namespace eval T_SUR_LD {
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
                return 0x00000001
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x01010901
        }
    }
    namespace export T_RD_TIME2
    proc T_RD_TIME2 { {base [::CMSDK_NVM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x20 }]
    }
    namespace eval T_RD_TIME2 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_NVM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x20 }]
        }
        namespace eval T_HR_PS_CS {
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
        namespace eval T_HR_PS {
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
                return 0x00000001
            }
        }
        namespace eval T_HR_PD_CS {
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
                return 0x00000001
            }
        }
        namespace eval T_HR_PD {
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
                return 0x00000002
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x02010101
        }
    }
    namespace export T_RD_TIME3
    proc T_RD_TIME3 { {base [::CMSDK_NVM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x24 }]
    }
    namespace eval T_RD_TIME3 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_NVM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x24 }]
        }
        namespace eval T_HR_A {
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
        namespace eval T_HR_LD {
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
                return 0x00000001
            }
        }
        namespace eval T_HR_PG {
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
                return 0x00000001
            }
        }
        namespace eval T_HR_CS {
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
                return 0x00000001
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x01010101
        }
    }
    namespace export T_RD_TIME4
    proc T_RD_TIME4 { {base [::CMSDK_NVM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x28 }]
    }
    namespace eval T_RD_TIME4 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_NVM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x28 }]
        }
        namespace eval T_RD {
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
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x00000001
        }
    }
    namespace export T_PR_TIME0
    proc T_PR_TIME0 { {base [::CMSDK_NVM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x2c }]
    }
    namespace eval T_PR_TIME0 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_NVM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x2c }]
        }
        namespace eval T_SUP_PG {
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
        namespace eval T_SUP_CS {
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
                return 0x00000001
            }
        }
        namespace eval T_SUP_PS_CS {
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
                return 0x00000001
            }
        }
        namespace eval T_SUP_PD {
            namespace export SHIFT
            proc SHIFT {} {
                return 24
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 4
            }
            namespace export MASK
            proc MASK {} {
                return 0x0f000000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x0f000000) >> 24}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 24) & 0x0f000000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x0f000000) | (($field_val << 24) & 0x0f000000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x0f000000) | (($field_val << 24) & 0x0f000000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 24) & ~0x0f000000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000009
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x09010101
        }
    }
    namespace export T_PR_TIME1
    proc T_PR_TIME1 { {base [::CMSDK_NVM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x30 }]
    }
    namespace eval T_PR_TIME1 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_NVM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x30 }]
        }
        namespace eval T_SUP_PS {
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
        namespace eval T_SUP_PD_PS {
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
                return 0x00000009
            }
        }
        namespace eval T_SUP_A {
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
                return 0x00000001
            }
        }
        namespace eval T_SUP_LD {
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
                return 0x00000001
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x01010901
        }
    }
    namespace export T_PR_TIME2
    proc T_PR_TIME2 { {base [::CMSDK_NVM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x34 }]
    }
    namespace eval T_PR_TIME2 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_NVM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x34 }]
        }
        namespace eval T_HP_PS_CS {
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
        namespace eval T_HP_PS {
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
                return 0x00000001
            }
        }
        namespace eval T_HP_PD_PS {
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
                return 0x00000001
            }
        }
        namespace eval T_HP_PD {
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
                return 0x00000002
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x02010101
        }
    }
    namespace export T_PR_TIME3
    proc T_PR_TIME3 { {base [::CMSDK_NVM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x38 }]
    }
    namespace eval T_PR_TIME3 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_NVM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x38 }]
        }
        namespace eval T_HP_A {
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
        namespace eval T_HP_LD {
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
                return 0x00000001
            }
        }
        namespace eval T_HP_PG {
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
                return 0x00000001
            }
        }
        namespace eval T_HP_CS {
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
                return 0x00000001
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x01010101
        }
    }
    namespace export T_PR_TIME4
    proc T_PR_TIME4 { {base [::CMSDK_NVM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x3c }]
    }
    namespace eval T_PR_TIME4 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_NVM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x3c }]
        }
        namespace eval T_HP_POR {
            namespace export SHIFT
            proc SHIFT {} {
                return 0
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 6
            }
            namespace export MASK
            proc MASK {} {
                return 0x0000003f
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x0000003f) >> 0}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 0) & 0x0000003f}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x0000003f) | (($field_val << 0) & 0x0000003f)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x0000003f) | (($field_val << 0) & 0x0000003f)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 0) & ~0x0000003f)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000012
            }
        }
        namespace eval T_SUP_POR {
            namespace export SHIFT
            proc SHIFT {} {
                return 16
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 6
            }
            namespace export MASK
            proc MASK {} {
                return 0x003f0000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x003f0000) >> 16}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 16) & 0x003f0000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x003f0000) | (($field_val << 16) & 0x003f0000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x003f0000) | (($field_val << 16) & 0x003f0000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 16) & ~0x003f0000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000019
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x00190012
        }
    }
    namespace export T_PR_TIME5
    proc T_PR_TIME5 { {base [::CMSDK_NVM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x40 }]
    }
    namespace eval T_PR_TIME5 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_NVM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x40 }]
        }
        namespace eval T_PI {
            namespace export SHIFT
            proc SHIFT {} {
                return 0
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 6
            }
            namespace export MASK
            proc MASK {} {
                return 0x0000003f
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x0000003f) >> 0}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 0) & 0x0000003f}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x0000003f) | (($field_val << 0) & 0x0000003f)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x0000003f) | (($field_val << 0) & 0x0000003f)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 0) & ~0x0000003f)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000010
            }
        }
        namespace eval T_PP {
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
                return 0x00000040
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x00400010
        }
    }
    namespace export INTERRUPT_STATUS
    proc INTERRUPT_STATUS { {base [::CMSDK_NVM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x44 }]
    }
    namespace eval INTERRUPT_STATUS {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_NVM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x44 }]
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
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x00000000
        }
    }
    namespace export INTERRUPT_MASK
    proc INTERRUPT_MASK { {base [::CMSDK_NVM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x48 }]
    }
    namespace eval INTERRUPT_MASK {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_NVM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x48 }]
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
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x00000000
        }
    }
    namespace export INTERRUPT_SET
    proc INTERRUPT_SET { {base [::CMSDK_NVM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x4c }]
    }
    namespace eval INTERRUPT_SET {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_NVM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x4c }]
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
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x00000000
        }
    }
    namespace export INTERRUPT_RESET
    proc INTERRUPT_RESET { {base [::CMSDK_NVM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x50 }]
    }
    namespace eval INTERRUPT_RESET {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_NVM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x50 }]
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
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x00000000
        }
    }
    namespace export CORE_ID
    proc CORE_ID { {base [::CMSDK_NVM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0xff4 }]
    }
    namespace eval CORE_ID {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_NVM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0xff4 }]
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
                return 0x554e564d
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x554e564d
        }
    }
    namespace export REV_HASH
    proc REV_HASH { {base [::CMSDK_NVM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0xff8 }]
    }
    namespace eval REV_HASH {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_NVM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0xff8 }]
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
                return 0x00000000
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x00000000
        }
    }
    namespace export REV_KEY
    proc REV_KEY { {base [::CMSDK_NVM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0xffc }]
    }
    namespace eval REV_KEY {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_NVM_NONSECURE::BASE]} } {
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
                return 0x52455620
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x52455620
        }
    }
}
