namespace eval CMSDK_SWREG_SIMPLE {
    namespace export BASE
    proc BASE {} {
        return 0xe1010000
    }
    namespace export SIMPLE0
    proc SIMPLE0 { {base [::CMSDK_SWREG_SIMPLE::BASE]} } {
        return [expr { [expr $base] + 0x0 }]
    }
    namespace eval SIMPLE0 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_SWREG_SIMPLE::BASE]} } {
            return [expr { [expr $base] + 0x0 }]
        }
        namespace eval LOADREGSIMPLE {
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
        namespace eval DIVCK32MPPT {
            namespace export SHIFT
            proc SHIFT {} {
                return 1
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 5
            }
            namespace export MASK
            proc MASK {} {
                return 0x0000003e
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x0000003e) >> 1}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 1) & 0x0000003e}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x0000003e) | (($field_val << 1) & 0x0000003e)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x0000003e) | (($field_val << 1) & 0x0000003e)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 1) & ~0x0000003e)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000007
            }
        }
        namespace eval SCALEENERG_OVR {
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
        namespace eval SCALEENERG_OVRVAL {
            namespace export SHIFT
            proc SHIFT {} {
                return 7
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 9
            }
            namespace export MASK
            proc MASK {} {
                return 0x0000ff80
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x0000ff80) >> 7}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 7) & 0x0000ff80}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x0000ff80) | (($field_val << 7) & 0x0000ff80)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x0000ff80) | (($field_val << 7) & 0x0000ff80)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 7) & ~0x0000ff80)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval ENABLEHARV2SUP_OVR {
            namespace export SHIFT
            proc SHIFT {} {
                return 16
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 1
            }
            namespace export MASK
            proc MASK {} {
                return 0x00010000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00010000) >> 16}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 16) & 0x00010000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00010000) | (($field_val << 16) & 0x00010000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00010000) | (($field_val << 16) & 0x00010000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 16) & ~0x00010000)}]
            }
            namespace export SET
            proc SET {var_name} {
                upvar $var_name var
                set var [expr {($var & ~0x00010000) | (1 << 16)}]
            }
            namespace export SET_TGT
            proc SET_TGT {addr} {
                mww $addr [expr {([mrw $addr] & ~0x00010000) | (1 << 16)}]
            }
            namespace export CLR
            proc CLR {var_name} {
                upvar $var_name var
                set var [expr {$var & ~0x00010000}]
            }
            namespace export CLR_TGT
            proc CLR_TGT {addr} {
                mww $addr [expr {[mrw $addr] & ~0x00010000}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval ENABLEHARV2SUP_OVRVAL {
            namespace export SHIFT
            proc SHIFT {} {
                return 17
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 1
            }
            namespace export MASK
            proc MASK {} {
                return 0x00020000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00020000) >> 17}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 17) & 0x00020000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00020000) | (($field_val << 17) & 0x00020000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00020000) | (($field_val << 17) & 0x00020000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 17) & ~0x00020000)}]
            }
            namespace export SET
            proc SET {var_name} {
                upvar $var_name var
                set var [expr {($var & ~0x00020000) | (1 << 17)}]
            }
            namespace export SET_TGT
            proc SET_TGT {addr} {
                mww $addr [expr {([mrw $addr] & ~0x00020000) | (1 << 17)}]
            }
            namespace export CLR
            proc CLR {var_name} {
                upvar $var_name var
                set var [expr {$var & ~0x00020000}]
            }
            namespace export CLR_TGT
            proc CLR_TGT {addr} {
                mww $addr [expr {[mrw $addr] & ~0x00020000}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval FIXHARVENERG_OVR {
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
        namespace eval FIXHARVENERG_OVRVAL {
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
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x0000000e
        }
    }
    namespace export SIMPLE1
    proc SIMPLE1 { {base [::CMSDK_SWREG_SIMPLE::BASE]} } {
        return [expr { [expr $base] + 0x4 }]
    }
    namespace eval SIMPLE1 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_SWREG_SIMPLE::BASE]} } {
            return [expr { [expr $base] + 0x4 }]
        }
        namespace eval BUCKBOOST_OVR {
            namespace export SHIFT
            proc SHIFT {} {
                return 0
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 13
            }
            namespace export MASK
            proc MASK {} {
                return 0x00001fff
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00001fff) >> 0}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 0) & 0x00001fff}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00001fff) | (($field_val << 0) & 0x00001fff)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00001fff) | (($field_val << 0) & 0x00001fff)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 0) & ~0x00001fff)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval BUCK_OVRVAL {
            namespace export SHIFT
            proc SHIFT {} {
                return 13
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 13
            }
            namespace export MASK
            proc MASK {} {
                return 0x03ffe000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x03ffe000) >> 13}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 13) & 0x03ffe000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x03ffe000) | (($field_val << 13) & 0x03ffe000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x03ffe000) | (($field_val << 13) & 0x03ffe000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 13) & ~0x03ffe000)}]
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
    namespace export SIMPLE2
    proc SIMPLE2 { {base [::CMSDK_SWREG_SIMPLE::BASE]} } {
        return [expr { [expr $base] + 0x8 }]
    }
    namespace eval SIMPLE2 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_SWREG_SIMPLE::BASE]} } {
            return [expr { [expr $base] + 0x8 }]
        }
        namespace eval BOOST_OVRVAL {
            namespace export SHIFT
            proc SHIFT {} {
                return 0
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 13
            }
            namespace export MASK
            proc MASK {} {
                return 0x00001fff
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00001fff) >> 0}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 0) & 0x00001fff}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00001fff) | (($field_val << 0) & 0x00001fff)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00001fff) | (($field_val << 0) & 0x00001fff)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 0) & ~0x00001fff)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval READYFORTINYLEVEL {
            namespace export SHIFT
            proc SHIFT {} {
                return 13
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 2
            }
            namespace export MASK
            proc MASK {} {
                return 0x00006000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00006000) >> 13}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 13) & 0x00006000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00006000) | (($field_val << 13) & 0x00006000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00006000) | (($field_val << 13) & 0x00006000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 13) & ~0x00006000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000002
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x00004000
        }
    }
    namespace export CORE_ID
    proc CORE_ID { {base [::CMSDK_SWREG_SIMPLE::BASE]} } {
        return [expr { [expr $base] + 0xc }]
    }
    namespace eval CORE_ID {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_SWREG_SIMPLE::BASE]} } {
            return [expr { [expr $base] + 0xc }]
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
                return 0x53575253
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x53575253
        }
    }
}
