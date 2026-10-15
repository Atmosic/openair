namespace eval CMSDK_GPIO0_NONSECURE {
    namespace export BASE
    proc BASE {} {
        return 0x40100000
    }
    namespace export DATA
    proc DATA { {base [::CMSDK_GPIO0_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x0 }]
    }
    namespace eval DATA {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_GPIO0_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x0 }]
        }
        namespace eval DATA {
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
                return 0x00000000
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x00000000
        }
    }
    namespace export DATAOUT
    proc DATAOUT { {base [::CMSDK_GPIO0_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x4 }]
    }
    namespace eval DATAOUT {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_GPIO0_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x4 }]
        }
        namespace eval DATAOUT {
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
                return 0x00000000
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x00000000
        }
    }
    namespace export INENABLE_SET
    proc INENABLE_SET { {base [::CMSDK_GPIO0_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x8 }]
    }
    namespace eval INENABLE_SET {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_GPIO0_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x8 }]
        }
        namespace eval INENABLE_SET {
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
                return 0x00000000
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x00000000
        }
    }
    namespace export INENABLE_CLR
    proc INENABLE_CLR { {base [::CMSDK_GPIO0_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0xc }]
    }
    namespace eval INENABLE_CLR {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_GPIO0_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0xc }]
        }
        namespace eval INENABLE_CLR {
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
                return 0x00000000
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x00000000
        }
    }
    namespace export OUTENSET
    proc OUTENSET { {base [::CMSDK_GPIO0_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x10 }]
    }
    namespace eval OUTENSET {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_GPIO0_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x10 }]
        }
        namespace eval OUTENSET {
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
                return 0x00000000
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x00000000
        }
    }
    namespace export OUTENCLR
    proc OUTENCLR { {base [::CMSDK_GPIO0_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x14 }]
    }
    namespace eval OUTENCLR {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_GPIO0_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x14 }]
        }
        namespace eval OUTENCLR {
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
                return 0x00000000
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x00000000
        }
    }
    namespace export ALTFUNCSET
    proc ALTFUNCSET { {base [::CMSDK_GPIO0_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x18 }]
    }
    namespace eval ALTFUNCSET {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_GPIO0_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x18 }]
        }
        namespace eval ALTFUNCSET {
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
                return 0x00000000
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x00000000
        }
    }
    namespace export ALTFUNCCLR
    proc ALTFUNCCLR { {base [::CMSDK_GPIO0_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x1c }]
    }
    namespace eval ALTFUNCCLR {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_GPIO0_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x1c }]
        }
        namespace eval ALTFUNCCLR {
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
                return 0x00000000
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x00000000
        }
    }
    namespace export INTENSET
    proc INTENSET { {base [::CMSDK_GPIO0_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x20 }]
    }
    namespace eval INTENSET {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_GPIO0_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x20 }]
        }
        namespace eval INTENSET {
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
                return 0x00000000
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x00000000
        }
    }
    namespace export INTENCLR
    proc INTENCLR { {base [::CMSDK_GPIO0_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x24 }]
    }
    namespace eval INTENCLR {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_GPIO0_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x24 }]
        }
        namespace eval INTENCLR {
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
                return 0x00000000
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x00000000
        }
    }
    namespace export INTTYPESET
    proc INTTYPESET { {base [::CMSDK_GPIO0_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x28 }]
    }
    namespace eval INTTYPESET {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_GPIO0_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x28 }]
        }
        namespace eval INTTYPESET {
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
                return 0x00000000
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x00000000
        }
    }
    namespace export INTTYPECLR
    proc INTTYPECLR { {base [::CMSDK_GPIO0_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x2c }]
    }
    namespace eval INTTYPECLR {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_GPIO0_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x2c }]
        }
        namespace eval INTTYPECLR {
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
                return 0x00000000
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x00000000
        }
    }
    namespace export INTPOLSET
    proc INTPOLSET { {base [::CMSDK_GPIO0_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x30 }]
    }
    namespace eval INTPOLSET {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_GPIO0_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x30 }]
        }
        namespace eval INTPOLSET {
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
                return 0x00000000
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x00000000
        }
    }
    namespace export INTPOLCLR
    proc INTPOLCLR { {base [::CMSDK_GPIO0_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x34 }]
    }
    namespace eval INTPOLCLR {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_GPIO0_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x34 }]
        }
        namespace eval INTPOLCLR {
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
                return 0x00000000
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x00000000
        }
    }
    namespace export INTSTATUS_CLEAR
    proc INTSTATUS_CLEAR { {base [::CMSDK_GPIO0_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x38 }]
    }
    namespace eval INTSTATUS_CLEAR {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_GPIO0_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x38 }]
        }
        namespace eval INTSTATUS_CLEAR {
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
                return 0x00000000
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x00000000
        }
    }
    namespace export PULLUP_ENABLE_SET
    proc PULLUP_ENABLE_SET { {base [::CMSDK_GPIO0_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x5c }]
    }
    namespace eval PULLUP_ENABLE_SET {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_GPIO0_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x5c }]
        }
        namespace eval PULLUP_ENABLE_SET {
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
                return 0x00000000
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x00000000
        }
    }
    namespace export PULLUP_ENABLE_CLR
    proc PULLUP_ENABLE_CLR { {base [::CMSDK_GPIO0_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x60 }]
    }
    namespace eval PULLUP_ENABLE_CLR {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_GPIO0_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x60 }]
        }
        namespace eval PULLUP_ENABLE_CLR {
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
                return 0x00000000
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x00000000
        }
    }
    namespace export PULLDOWN_ENABLE_SET
    proc PULLDOWN_ENABLE_SET { {base [::CMSDK_GPIO0_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x64 }]
    }
    namespace eval PULLDOWN_ENABLE_SET {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_GPIO0_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x64 }]
        }
        namespace eval PULLDOWN_ENABLE_SET {
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
                return 0x00000000
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x00000000
        }
    }
    namespace export PULLDOWN_ENABLE_CLR
    proc PULLDOWN_ENABLE_CLR { {base [::CMSDK_GPIO0_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x68 }]
    }
    namespace eval PULLDOWN_ENABLE_CLR {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_GPIO0_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x68 }]
        }
        namespace eval PULLDOWN_ENABLE_CLR {
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
                return 0x00000000
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x00000000
        }
    }
    namespace export MASKLOWBYTE
    proc MASKLOWBYTE { {base [::CMSDK_GPIO0_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x400 }]
    }
    namespace eval MASKLOWBYTE {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_GPIO0_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x400 }]
        }
        namespace eval MASKLOWBYTE {
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
                return 0x00000000
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x00000000
        }
    }
    namespace export MASKHIGHBYTE
    proc MASKHIGHBYTE { {base [::CMSDK_GPIO0_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x800 }]
    }
    namespace eval MASKHIGHBYTE {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_GPIO0_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x800 }]
        }
        namespace eval MASKHIGHBYTE {
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
                return 0x00000000
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x00000000
        }
    }
    namespace export PID4
    proc PID4 { {base [::CMSDK_GPIO0_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0xfd0 }]
    }
    namespace eval PID4 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_GPIO0_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0xfd0 }]
        }
        namespace eval JEP106_C_CODE {
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
                return 0x00000004
            }
        }
        namespace eval BLOCK_COUNT {
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
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x00000004
        }
    }
    namespace export PID5
    proc PID5 { {base [::CMSDK_GPIO0_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0xfd4 }]
    }
    namespace eval PID5 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_GPIO0_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0xfd4 }]
        }
        namespace eval PID5 {
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
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x00000000
        }
    }
    namespace export PID6
    proc PID6 { {base [::CMSDK_GPIO0_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0xfd8 }]
    }
    namespace eval PID6 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_GPIO0_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0xfd8 }]
        }
        namespace eval PID6 {
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
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x00000000
        }
    }
    namespace export PID7
    proc PID7 { {base [::CMSDK_GPIO0_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0xfdc }]
    }
    namespace eval PID7 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_GPIO0_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0xfdc }]
        }
        namespace eval PID7 {
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
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x00000000
        }
    }
    namespace export PID0
    proc PID0 { {base [::CMSDK_GPIO0_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0xfe0 }]
    }
    namespace eval PID0 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_GPIO0_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0xfe0 }]
        }
        namespace eval PART_NUM {
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
                return 0x00000021
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x00000021
        }
    }
    namespace export PID1
    proc PID1 { {base [::CMSDK_GPIO0_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0xfe4 }]
    }
    namespace eval PID1 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_GPIO0_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0xfe4 }]
        }
        namespace eval PART_NUM {
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
                return 0x00000008
            }
        }
        namespace eval JEP106_ID_3_0 {
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
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x0000000b
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x000000b8
        }
    }
    namespace export PID2
    proc PID2 { {base [::CMSDK_GPIO0_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0xfe8 }]
    }
    namespace eval PID2 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_GPIO0_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0xfe8 }]
        }
        namespace eval JEP106_ID_6_4 {
            namespace export SHIFT
            proc SHIFT {} {
                return 0
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 3
            }
            namespace export MASK
            proc MASK {} {
                return 0x00000007
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00000007) >> 0}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000003
            }
        }
        namespace eval JEDEC_USED {
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
                return 0x00000001
            }
        }
        namespace eval REV {
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
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000001
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x0000001b
        }
    }
    namespace export PID3
    proc PID3 { {base [::CMSDK_GPIO0_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0xfec }]
    }
    namespace eval PID3 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_GPIO0_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0xfec }]
        }
        namespace eval MOD_NUM {
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
        namespace eval ECOREVNUM {
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
    namespace export CID0
    proc CID0 { {base [::CMSDK_GPIO0_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0xff0 }]
    }
    namespace eval CID0 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_GPIO0_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0xff0 }]
        }
        namespace eval CID0 {
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
                return 0x0000000d
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x0000000d
        }
    }
    namespace export CID1
    proc CID1 { {base [::CMSDK_GPIO0_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0xff4 }]
    }
    namespace eval CID1 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_GPIO0_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0xff4 }]
        }
        namespace eval CID1 {
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
                return 0x000000f0
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x000000f0
        }
    }
    namespace export CID2
    proc CID2 { {base [::CMSDK_GPIO0_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0xff8 }]
    }
    namespace eval CID2 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_GPIO0_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0xff8 }]
        }
        namespace eval CID2 {
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
                return 0x00000005
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x00000005
        }
    }
    namespace export CID3
    proc CID3 { {base [::CMSDK_GPIO0_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0xffc }]
    }
    namespace eval CID3 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_GPIO0_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0xffc }]
        }
        namespace eval CID3 {
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
                return 0x000000b1
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x000000b1
        }
    }
}
