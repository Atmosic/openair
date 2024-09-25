namespace eval CMSDK_AT_PRRF_NONSECURE {
    namespace export BASE
    proc BASE {} {
        return 0x1ffe00
    }
    namespace export PATCH_TAG0
    proc PATCH_TAG0 { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x0 }]
    }
    namespace eval PATCH_TAG0 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x0 }]
        }
        namespace eval ADDR {
            namespace export SHIFT
            proc SHIFT {} {
                return 0
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 22
            }
            namespace export MASK
            proc MASK {} {
                return 0x003fffff
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x003fffff) >> 0}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 0) & 0x003fffff}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x003fffff) | (($field_val << 0) & 0x003fffff)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x003fffff) | (($field_val << 0) & 0x003fffff)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 0) & ~0x003fffff)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval NWORD {
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
                return 0x00000000
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x00000000
        }
    }
    namespace export PATCH_TAG1
    proc PATCH_TAG1 { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x4 }]
    }
    namespace eval PATCH_TAG1 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x4 }]
        }
        namespace eval ADDR {
            namespace export SHIFT
            proc SHIFT {} {
                return 0
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 22
            }
            namespace export MASK
            proc MASK {} {
                return 0x003fffff
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x003fffff) >> 0}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 0) & 0x003fffff}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x003fffff) | (($field_val << 0) & 0x003fffff)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x003fffff) | (($field_val << 0) & 0x003fffff)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 0) & ~0x003fffff)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval NWORD {
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
                return 0x00000000
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x00000000
        }
    }
    namespace export PATCH_TAG2
    proc PATCH_TAG2 { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x8 }]
    }
    namespace eval PATCH_TAG2 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x8 }]
        }
        namespace eval ADDR {
            namespace export SHIFT
            proc SHIFT {} {
                return 0
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 22
            }
            namespace export MASK
            proc MASK {} {
                return 0x003fffff
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x003fffff) >> 0}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 0) & 0x003fffff}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x003fffff) | (($field_val << 0) & 0x003fffff)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x003fffff) | (($field_val << 0) & 0x003fffff)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 0) & ~0x003fffff)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval NWORD {
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
                return 0x00000000
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x00000000
        }
    }
    namespace export PATCH_TAG3
    proc PATCH_TAG3 { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0xc }]
    }
    namespace eval PATCH_TAG3 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0xc }]
        }
        namespace eval ADDR {
            namespace export SHIFT
            proc SHIFT {} {
                return 0
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 22
            }
            namespace export MASK
            proc MASK {} {
                return 0x003fffff
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x003fffff) >> 0}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 0) & 0x003fffff}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x003fffff) | (($field_val << 0) & 0x003fffff)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x003fffff) | (($field_val << 0) & 0x003fffff)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 0) & ~0x003fffff)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval NWORD {
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
                return 0x00000000
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x00000000
        }
    }
    namespace export PATCH_TAG4
    proc PATCH_TAG4 { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x10 }]
    }
    namespace eval PATCH_TAG4 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x10 }]
        }
        namespace eval ADDR {
            namespace export SHIFT
            proc SHIFT {} {
                return 0
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 22
            }
            namespace export MASK
            proc MASK {} {
                return 0x003fffff
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x003fffff) >> 0}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 0) & 0x003fffff}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x003fffff) | (($field_val << 0) & 0x003fffff)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x003fffff) | (($field_val << 0) & 0x003fffff)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 0) & ~0x003fffff)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval NWORD {
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
                return 0x00000000
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x00000000
        }
    }
    namespace export PATCH_TAG5
    proc PATCH_TAG5 { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x14 }]
    }
    namespace eval PATCH_TAG5 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x14 }]
        }
        namespace eval ADDR {
            namespace export SHIFT
            proc SHIFT {} {
                return 0
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 22
            }
            namespace export MASK
            proc MASK {} {
                return 0x003fffff
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x003fffff) >> 0}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 0) & 0x003fffff}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x003fffff) | (($field_val << 0) & 0x003fffff)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x003fffff) | (($field_val << 0) & 0x003fffff)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 0) & ~0x003fffff)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval NWORD {
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
                return 0x00000000
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x00000000
        }
    }
    namespace export PATCH_TAG6
    proc PATCH_TAG6 { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x18 }]
    }
    namespace eval PATCH_TAG6 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x18 }]
        }
        namespace eval ADDR {
            namespace export SHIFT
            proc SHIFT {} {
                return 0
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 22
            }
            namespace export MASK
            proc MASK {} {
                return 0x003fffff
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x003fffff) >> 0}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 0) & 0x003fffff}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x003fffff) | (($field_val << 0) & 0x003fffff)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x003fffff) | (($field_val << 0) & 0x003fffff)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 0) & ~0x003fffff)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval NWORD {
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
                return 0x00000000
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x00000000
        }
    }
    namespace export PATCH_TAG7
    proc PATCH_TAG7 { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x1c }]
    }
    namespace eval PATCH_TAG7 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x1c }]
        }
        namespace eval ADDR {
            namespace export SHIFT
            proc SHIFT {} {
                return 0
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 22
            }
            namespace export MASK
            proc MASK {} {
                return 0x003fffff
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x003fffff) >> 0}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 0) & 0x003fffff}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x003fffff) | (($field_val << 0) & 0x003fffff)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x003fffff) | (($field_val << 0) & 0x003fffff)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 0) & ~0x003fffff)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval NWORD {
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
                return 0x00000000
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x00000000
        }
    }
    namespace export PATCH_TAG8
    proc PATCH_TAG8 { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x20 }]
    }
    namespace eval PATCH_TAG8 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x20 }]
        }
        namespace eval ADDR {
            namespace export SHIFT
            proc SHIFT {} {
                return 0
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 22
            }
            namespace export MASK
            proc MASK {} {
                return 0x003fffff
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x003fffff) >> 0}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 0) & 0x003fffff}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x003fffff) | (($field_val << 0) & 0x003fffff)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x003fffff) | (($field_val << 0) & 0x003fffff)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 0) & ~0x003fffff)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval NWORD {
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
                return 0x00000000
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x00000000
        }
    }
    namespace export PATCH_TAG9
    proc PATCH_TAG9 { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x24 }]
    }
    namespace eval PATCH_TAG9 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x24 }]
        }
        namespace eval ADDR {
            namespace export SHIFT
            proc SHIFT {} {
                return 0
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 22
            }
            namespace export MASK
            proc MASK {} {
                return 0x003fffff
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x003fffff) >> 0}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 0) & 0x003fffff}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x003fffff) | (($field_val << 0) & 0x003fffff)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x003fffff) | (($field_val << 0) & 0x003fffff)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 0) & ~0x003fffff)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval NWORD {
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
                return 0x00000000
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x00000000
        }
    }
    namespace export PATCH_TAG10
    proc PATCH_TAG10 { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x28 }]
    }
    namespace eval PATCH_TAG10 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x28 }]
        }
        namespace eval ADDR {
            namespace export SHIFT
            proc SHIFT {} {
                return 0
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 22
            }
            namespace export MASK
            proc MASK {} {
                return 0x003fffff
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x003fffff) >> 0}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 0) & 0x003fffff}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x003fffff) | (($field_val << 0) & 0x003fffff)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x003fffff) | (($field_val << 0) & 0x003fffff)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 0) & ~0x003fffff)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval NWORD {
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
                return 0x00000000
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x00000000
        }
    }
    namespace export PATCH_TAG11
    proc PATCH_TAG11 { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x2c }]
    }
    namespace eval PATCH_TAG11 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x2c }]
        }
        namespace eval ADDR {
            namespace export SHIFT
            proc SHIFT {} {
                return 0
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 22
            }
            namespace export MASK
            proc MASK {} {
                return 0x003fffff
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x003fffff) >> 0}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 0) & 0x003fffff}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x003fffff) | (($field_val << 0) & 0x003fffff)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x003fffff) | (($field_val << 0) & 0x003fffff)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 0) & ~0x003fffff)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval NWORD {
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
                return 0x00000000
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x00000000
        }
    }
    namespace export PATCH_TAG12
    proc PATCH_TAG12 { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x30 }]
    }
    namespace eval PATCH_TAG12 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x30 }]
        }
        namespace eval ADDR {
            namespace export SHIFT
            proc SHIFT {} {
                return 0
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 22
            }
            namespace export MASK
            proc MASK {} {
                return 0x003fffff
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x003fffff) >> 0}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 0) & 0x003fffff}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x003fffff) | (($field_val << 0) & 0x003fffff)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x003fffff) | (($field_val << 0) & 0x003fffff)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 0) & ~0x003fffff)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval NWORD {
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
                return 0x00000000
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x00000000
        }
    }
    namespace export PATCH_TAG13
    proc PATCH_TAG13 { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x34 }]
    }
    namespace eval PATCH_TAG13 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x34 }]
        }
        namespace eval ADDR {
            namespace export SHIFT
            proc SHIFT {} {
                return 0
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 22
            }
            namespace export MASK
            proc MASK {} {
                return 0x003fffff
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x003fffff) >> 0}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 0) & 0x003fffff}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x003fffff) | (($field_val << 0) & 0x003fffff)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x003fffff) | (($field_val << 0) & 0x003fffff)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 0) & ~0x003fffff)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval NWORD {
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
                return 0x00000000
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x00000000
        }
    }
    namespace export PATCH_TAG14
    proc PATCH_TAG14 { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x38 }]
    }
    namespace eval PATCH_TAG14 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x38 }]
        }
        namespace eval ADDR {
            namespace export SHIFT
            proc SHIFT {} {
                return 0
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 22
            }
            namespace export MASK
            proc MASK {} {
                return 0x003fffff
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x003fffff) >> 0}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 0) & 0x003fffff}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x003fffff) | (($field_val << 0) & 0x003fffff)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x003fffff) | (($field_val << 0) & 0x003fffff)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 0) & ~0x003fffff)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval NWORD {
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
                return 0x00000000
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x00000000
        }
    }
    namespace export PATCH_TAG15
    proc PATCH_TAG15 { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x3c }]
    }
    namespace eval PATCH_TAG15 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x3c }]
        }
        namespace eval ADDR {
            namespace export SHIFT
            proc SHIFT {} {
                return 0
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 22
            }
            namespace export MASK
            proc MASK {} {
                return 0x003fffff
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x003fffff) >> 0}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 0) & 0x003fffff}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x003fffff) | (($field_val << 0) & 0x003fffff)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x003fffff) | (($field_val << 0) & 0x003fffff)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 0) & ~0x003fffff)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval NWORD {
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
                return 0x00000000
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x00000000
        }
    }
    namespace export PATCH0
    proc PATCH0 { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x40 }]
    }
    namespace eval PATCH0 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x40 }]
        }
        namespace eval PATCH0 {
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
    namespace export PATCH1
    proc PATCH1 { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x44 }]
    }
    namespace eval PATCH1 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x44 }]
        }
        namespace eval PATCH1 {
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
    namespace export PATCH2
    proc PATCH2 { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x48 }]
    }
    namespace eval PATCH2 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x48 }]
        }
        namespace eval PATCH2 {
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
    namespace export PATCH3
    proc PATCH3 { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x4c }]
    }
    namespace eval PATCH3 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x4c }]
        }
        namespace eval PATCH3 {
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
    namespace export PATCH4
    proc PATCH4 { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x50 }]
    }
    namespace eval PATCH4 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x50 }]
        }
        namespace eval PATCH4 {
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
    namespace export PATCH5
    proc PATCH5 { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x54 }]
    }
    namespace eval PATCH5 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x54 }]
        }
        namespace eval PATCH5 {
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
    namespace export PATCH6
    proc PATCH6 { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x58 }]
    }
    namespace eval PATCH6 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x58 }]
        }
        namespace eval PATCH6 {
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
    namespace export PATCH7
    proc PATCH7 { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x5c }]
    }
    namespace eval PATCH7 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x5c }]
        }
        namespace eval PATCH7 {
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
    namespace export PATCH8
    proc PATCH8 { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x60 }]
    }
    namespace eval PATCH8 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x60 }]
        }
        namespace eval PATCH8 {
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
    namespace export PATCH9
    proc PATCH9 { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x64 }]
    }
    namespace eval PATCH9 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x64 }]
        }
        namespace eval PATCH9 {
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
    namespace export PATCH10
    proc PATCH10 { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x68 }]
    }
    namespace eval PATCH10 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x68 }]
        }
        namespace eval PATCH10 {
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
    namespace export PATCH11
    proc PATCH11 { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x6c }]
    }
    namespace eval PATCH11 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x6c }]
        }
        namespace eval PATCH11 {
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
    namespace export PATCH12
    proc PATCH12 { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x70 }]
    }
    namespace eval PATCH12 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x70 }]
        }
        namespace eval PATCH12 {
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
    namespace export PATCH13
    proc PATCH13 { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x74 }]
    }
    namespace eval PATCH13 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x74 }]
        }
        namespace eval PATCH13 {
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
    namespace export PATCH14
    proc PATCH14 { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x78 }]
    }
    namespace eval PATCH14 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x78 }]
        }
        namespace eval PATCH14 {
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
    namespace export PATCH15
    proc PATCH15 { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x7c }]
    }
    namespace eval PATCH15 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x7c }]
        }
        namespace eval PATCH15 {
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
    namespace export PATCH16
    proc PATCH16 { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x80 }]
    }
    namespace eval PATCH16 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x80 }]
        }
        namespace eval PATCH16 {
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
    namespace export PATCH17
    proc PATCH17 { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x84 }]
    }
    namespace eval PATCH17 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x84 }]
        }
        namespace eval PATCH17 {
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
    namespace export PATCH18
    proc PATCH18 { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x88 }]
    }
    namespace eval PATCH18 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x88 }]
        }
        namespace eval PATCH18 {
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
    namespace export PATCH19
    proc PATCH19 { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x8c }]
    }
    namespace eval PATCH19 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x8c }]
        }
        namespace eval PATCH19 {
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
    namespace export PATCH20
    proc PATCH20 { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x90 }]
    }
    namespace eval PATCH20 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x90 }]
        }
        namespace eval PATCH20 {
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
    namespace export PATCH21
    proc PATCH21 { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x94 }]
    }
    namespace eval PATCH21 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x94 }]
        }
        namespace eval PATCH21 {
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
    namespace export PATCH22
    proc PATCH22 { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x98 }]
    }
    namespace eval PATCH22 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x98 }]
        }
        namespace eval PATCH22 {
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
    namespace export PATCH23
    proc PATCH23 { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x9c }]
    }
    namespace eval PATCH23 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x9c }]
        }
        namespace eval PATCH23 {
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
    namespace export PATCH24
    proc PATCH24 { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0xa0 }]
    }
    namespace eval PATCH24 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0xa0 }]
        }
        namespace eval PATCH24 {
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
    namespace export PATCH25
    proc PATCH25 { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0xa4 }]
    }
    namespace eval PATCH25 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0xa4 }]
        }
        namespace eval PATCH25 {
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
    namespace export PATCH26
    proc PATCH26 { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0xa8 }]
    }
    namespace eval PATCH26 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0xa8 }]
        }
        namespace eval PATCH26 {
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
    namespace export PATCH27
    proc PATCH27 { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0xac }]
    }
    namespace eval PATCH27 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0xac }]
        }
        namespace eval PATCH27 {
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
    namespace export PATCH28
    proc PATCH28 { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0xb0 }]
    }
    namespace eval PATCH28 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0xb0 }]
        }
        namespace eval PATCH28 {
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
    namespace export PATCH29
    proc PATCH29 { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0xb4 }]
    }
    namespace eval PATCH29 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0xb4 }]
        }
        namespace eval PATCH29 {
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
    namespace export PATCH30
    proc PATCH30 { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0xb8 }]
    }
    namespace eval PATCH30 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0xb8 }]
        }
        namespace eval PATCH30 {
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
    namespace export PATCH31
    proc PATCH31 { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0xbc }]
    }
    namespace eval PATCH31 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0xbc }]
        }
        namespace eval PATCH31 {
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
    namespace export PATCH32
    proc PATCH32 { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0xc0 }]
    }
    namespace eval PATCH32 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0xc0 }]
        }
        namespace eval PATCH32 {
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
    namespace export PATCH33
    proc PATCH33 { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0xc4 }]
    }
    namespace eval PATCH33 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0xc4 }]
        }
        namespace eval PATCH33 {
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
    namespace export PATCH34
    proc PATCH34 { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0xc8 }]
    }
    namespace eval PATCH34 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0xc8 }]
        }
        namespace eval PATCH34 {
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
    namespace export PATCH35
    proc PATCH35 { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0xcc }]
    }
    namespace eval PATCH35 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0xcc }]
        }
        namespace eval PATCH35 {
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
    namespace export PATCH36
    proc PATCH36 { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0xd0 }]
    }
    namespace eval PATCH36 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0xd0 }]
        }
        namespace eval PATCH36 {
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
    namespace export PATCH37
    proc PATCH37 { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0xd4 }]
    }
    namespace eval PATCH37 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0xd4 }]
        }
        namespace eval PATCH37 {
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
    namespace export PATCH38
    proc PATCH38 { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0xd8 }]
    }
    namespace eval PATCH38 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0xd8 }]
        }
        namespace eval PATCH38 {
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
    namespace export PATCH39
    proc PATCH39 { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0xdc }]
    }
    namespace eval PATCH39 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0xdc }]
        }
        namespace eval PATCH39 {
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
    namespace export PATCH40
    proc PATCH40 { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0xe0 }]
    }
    namespace eval PATCH40 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0xe0 }]
        }
        namespace eval PATCH40 {
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
    namespace export PATCH41
    proc PATCH41 { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0xe4 }]
    }
    namespace eval PATCH41 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0xe4 }]
        }
        namespace eval PATCH41 {
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
    namespace export PATCH42
    proc PATCH42 { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0xe8 }]
    }
    namespace eval PATCH42 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0xe8 }]
        }
        namespace eval PATCH42 {
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
    namespace export PATCH43
    proc PATCH43 { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0xec }]
    }
    namespace eval PATCH43 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0xec }]
        }
        namespace eval PATCH43 {
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
    namespace export PATCH44
    proc PATCH44 { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0xf0 }]
    }
    namespace eval PATCH44 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0xf0 }]
        }
        namespace eval PATCH44 {
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
    namespace export PATCH45
    proc PATCH45 { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0xf4 }]
    }
    namespace eval PATCH45 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0xf4 }]
        }
        namespace eval PATCH45 {
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
    namespace export PATCH46
    proc PATCH46 { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0xf8 }]
    }
    namespace eval PATCH46 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0xf8 }]
        }
        namespace eval PATCH46 {
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
    namespace export PATCH47
    proc PATCH47 { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0xfc }]
    }
    namespace eval PATCH47 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0xfc }]
        }
        namespace eval PATCH47 {
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
    namespace export RRAM_WRT_CONFIG_LO
    proc RRAM_WRT_CONFIG_LO { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x100 }]
    }
    namespace eval RRAM_WRT_CONFIG_LO {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x100 }]
        }
        namespace eval DIN {
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
    namespace export RRAM_WRT_CONFIG_HI
    proc RRAM_WRT_CONFIG_HI { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x104 }]
    }
    namespace eval RRAM_WRT_CONFIG_HI {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x104 }]
        }
        namespace eval DIN {
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
    namespace export RRAM_READ_CONFIG_LO
    proc RRAM_READ_CONFIG_LO { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x108 }]
    }
    namespace eval RRAM_READ_CONFIG_LO {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x108 }]
        }
        namespace eval DOUT {
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
    namespace export RRAM_READ_CONFIG_HI
    proc RRAM_READ_CONFIG_HI { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x10c }]
    }
    namespace eval RRAM_READ_CONFIG_HI {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x10c }]
        }
        namespace eval DOUT {
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
    namespace export RRAM_CACHE_CONFIG
    proc RRAM_CACHE_CONFIG { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x110 }]
    }
    namespace eval RRAM_CACHE_CONFIG {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x110 }]
        }
        namespace eval CACHE_MODE {
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
        namespace eval ENABLE_CACHE {
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
        namespace eval INVALIDATE_CACHE {
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
        namespace eval ENABLE_FINE_CLOCK_GATING {
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
    namespace export RRAM_MEM_CONFIG
    proc RRAM_MEM_CONFIG { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x114 }]
    }
    namespace eval RRAM_MEM_CONFIG {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x114 }]
        }
        namespace eval RRAM_SPEEDUP_B {
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
        namespace eval TRC_INFO {
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
        namespace eval TRC_LVEN {
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
        namespace eval TRC_TIN {
            namespace export SHIFT
            proc SHIFT {} {
                return 3
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 15
            }
            namespace export MASK
            proc MASK {} {
                return 0x0003fff8
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x0003fff8) >> 3}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 3) & 0x0003fff8}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x0003fff8) | (($field_val << 3) & 0x0003fff8)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x0003fff8) | (($field_val << 3) & 0x0003fff8)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 3) & ~0x0003fff8)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval EN_FINE_CKG {
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
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x00000000
        }
    }
    namespace export RRAM_STATUS
    proc RRAM_STATUS { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x118 }]
    }
    namespace eval RRAM_STATUS {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_AT_PRRF_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x118 }]
        }
        namespace eval BUSY {
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
        namespace eval ERR {
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
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x00000000
        }
    }
}
