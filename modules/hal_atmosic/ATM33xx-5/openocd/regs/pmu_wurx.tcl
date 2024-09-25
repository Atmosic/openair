namespace eval CMSDK_PMU_WURX {
    namespace export BASE
    proc BASE {} {
        return 0x0
    }
    namespace export BLOCK
    proc BLOCK {} {
        return 10
    }
    namespace export WURX_GENERAL
    proc WURX_GENERAL { {base [::CMSDK_PMU_WURX::BASE]} } {
        return [expr { [expr $base] + 0x0 }]
    }
    namespace eval WURX_GENERAL {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_PMU_WURX::BASE]} } {
            return [expr { [expr $base] + 0x0 }]
        }
        namespace eval WURX_SELECT {
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
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 0) & ~0x00000001)}]
            }
            namespace export SET
            proc SET {var_name} {
                upvar $var_name var
                set var [expr {($var & ~0x00000001) | (1 << 0)}]
            }
            namespace export CLR
            proc CLR {var_name} {
                upvar $var_name var
                set var [expr {$var & ~0x00000001}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval WURX0_EN_OVR {
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
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 1) & ~0x00000002)}]
            }
            namespace export SET
            proc SET {var_name} {
                upvar $var_name var
                set var [expr {($var & ~0x00000002) | (1 << 1)}]
            }
            namespace export CLR
            proc CLR {var_name} {
                upvar $var_name var
                set var [expr {$var & ~0x00000002}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval WURX0_EN_VAL {
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
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 2) & ~0x00000004)}]
            }
            namespace export SET
            proc SET {var_name} {
                upvar $var_name var
                set var [expr {($var & ~0x00000004) | (1 << 2)}]
            }
            namespace export CLR
            proc CLR {var_name} {
                upvar $var_name var
                set var [expr {$var & ~0x00000004}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval WURX1_EN_OVR {
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
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 3) & ~0x00000008)}]
            }
            namespace export SET
            proc SET {var_name} {
                upvar $var_name var
                set var [expr {($var & ~0x00000008) | (1 << 3)}]
            }
            namespace export CLR
            proc CLR {var_name} {
                upvar $var_name var
                set var [expr {$var & ~0x00000008}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval WURX1_EN_VAL {
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
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 4) & ~0x00000010)}]
            }
            namespace export SET
            proc SET {var_name} {
                upvar $var_name var
                set var [expr {($var & ~0x00000010) | (1 << 4)}]
            }
            namespace export CLR
            proc CLR {var_name} {
                upvar $var_name var
                set var [expr {$var & ~0x00000010}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval WAKEUP0_OVR {
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
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 5) & ~0x00000020)}]
            }
            namespace export SET
            proc SET {var_name} {
                upvar $var_name var
                set var [expr {($var & ~0x00000020) | (1 << 5)}]
            }
            namespace export CLR
            proc CLR {var_name} {
                upvar $var_name var
                set var [expr {$var & ~0x00000020}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval WAKEUP0_OVR_VAL {
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
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 6) & ~0x00000040)}]
            }
            namespace export SET
            proc SET {var_name} {
                upvar $var_name var
                set var [expr {($var & ~0x00000040) | (1 << 6)}]
            }
            namespace export CLR
            proc CLR {var_name} {
                upvar $var_name var
                set var [expr {$var & ~0x00000040}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval WAKEUP1_OVR {
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
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 7) & ~0x00000080)}]
            }
            namespace export SET
            proc SET {var_name} {
                upvar $var_name var
                set var [expr {($var & ~0x00000080) | (1 << 7)}]
            }
            namespace export CLR
            proc CLR {var_name} {
                upvar $var_name var
                set var [expr {$var & ~0x00000080}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval WAKEUP1_OVR_VAL {
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
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 8) & ~0x00000100)}]
            }
            namespace export SET
            proc SET {var_name} {
                upvar $var_name var
                set var [expr {($var & ~0x00000100) | (1 << 8)}]
            }
            namespace export CLR
            proc CLR {var_name} {
                upvar $var_name var
                set var [expr {$var & ~0x00000100}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval INIT_CAL_OVR {
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
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 9) & ~0x00000200)}]
            }
            namespace export SET
            proc SET {var_name} {
                upvar $var_name var
                set var [expr {($var & ~0x00000200) | (1 << 9)}]
            }
            namespace export CLR
            proc CLR {var_name} {
                upvar $var_name var
                set var [expr {$var & ~0x00000200}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000001
            }
        }
        namespace eval INIT_CAL_OVR_VAL {
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
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 10) & ~0x00000400)}]
            }
            namespace export SET
            proc SET {var_name} {
                upvar $var_name var
                set var [expr {($var & ~0x00000400) | (1 << 10)}]
            }
            namespace export CLR
            proc CLR {var_name} {
                upvar $var_name var
                set var [expr {$var & ~0x00000400}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000001
            }
        }
        namespace eval BIAS {
            namespace export SHIFT
            proc SHIFT {} {
                return 11
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 4
            }
            namespace export MASK
            proc MASK {} {
                return 0x00007800
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00007800) >> 11}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 11) & 0x00007800}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00007800) | (($field_val << 11) & 0x00007800)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 11) & ~0x00007800)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000004
            }
        }
        namespace eval ATBSEL {
            namespace export SHIFT
            proc SHIFT {} {
                return 15
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 4
            }
            namespace export MASK
            proc MASK {} {
                return 0x00078000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00078000) >> 15}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 15) & 0x00078000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00078000) | (($field_val << 15) & 0x00078000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 15) & ~0x00078000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval ATTNIN_OVR {
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
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 19) & ~0x00080000)}]
            }
            namespace export SET
            proc SET {var_name} {
                upvar $var_name var
                set var [expr {($var & ~0x00080000) | (1 << 19)}]
            }
            namespace export CLR
            proc CLR {var_name} {
                upvar $var_name var
                set var [expr {$var & ~0x00080000}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval ATTNIN_OVR_VAL {
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
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 20) & ~0x00100000)}]
            }
            namespace export SET
            proc SET {var_name} {
                upvar $var_name var
                set var [expr {($var & ~0x00100000) | (1 << 20)}]
            }
            namespace export CLR
            proc CLR {var_name} {
                upvar $var_name var
                set var [expr {$var & ~0x00100000}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval THR_CAL_EN_REG {
            namespace export SHIFT
            proc SHIFT {} {
                return 21
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 1
            }
            namespace export MASK
            proc MASK {} {
                return 0x00200000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00200000) >> 21}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 21) & 0x00200000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00200000) | (($field_val << 21) & 0x00200000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 21) & ~0x00200000)}]
            }
            namespace export SET
            proc SET {var_name} {
                upvar $var_name var
                set var [expr {($var & ~0x00200000) | (1 << 21)}]
            }
            namespace export CLR
            proc CLR {var_name} {
                upvar $var_name var
                set var [expr {$var & ~0x00200000}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000001
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x00202600
        }
    }
    namespace export WURX_GENERAL2
    proc WURX_GENERAL2 { {base [::CMSDK_PMU_WURX::BASE]} } {
        return [expr { [expr $base] + 0x4 }]
    }
    namespace eval WURX_GENERAL2 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_PMU_WURX::BASE]} } {
            return [expr { [expr $base] + 0x4 }]
        }
        namespace eval LOAD_OVR {
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
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 0) & ~0x00000001)}]
            }
            namespace export SET
            proc SET {var_name} {
                upvar $var_name var
                set var [expr {($var & ~0x00000001) | (1 << 0)}]
            }
            namespace export CLR
            proc CLR {var_name} {
                upvar $var_name var
                set var [expr {$var & ~0x00000001}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval LOAD_OVR_VAL {
            namespace export SHIFT
            proc SHIFT {} {
                return 1
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 9
            }
            namespace export MASK
            proc MASK {} {
                return 0x000003fe
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x000003fe) >> 1}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 1) & 0x000003fe}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x000003fe) | (($field_val << 1) & 0x000003fe)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 1) & ~0x000003fe)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000064
            }
        }
        namespace eval OFFSET_OVR {
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
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 10) & ~0x00000400)}]
            }
            namespace export SET
            proc SET {var_name} {
                upvar $var_name var
                set var [expr {($var & ~0x00000400) | (1 << 10)}]
            }
            namespace export CLR
            proc CLR {var_name} {
                upvar $var_name var
                set var [expr {$var & ~0x00000400}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval OFFSET_OVR_VAL {
            namespace export SHIFT
            proc SHIFT {} {
                return 11
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 8
            }
            namespace export MASK
            proc MASK {} {
                return 0x0007f800
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x0007f800) >> 11}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 11) & 0x0007f800}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x0007f800) | (($field_val << 11) & 0x0007f800)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 11) & ~0x0007f800)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000064
            }
        }
        namespace eval OFFSIMBALANCE {
            namespace export SHIFT
            proc SHIFT {} {
                return 19
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 5
            }
            namespace export MASK
            proc MASK {} {
                return 0x00f80000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00f80000) >> 19}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 19) & 0x00f80000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00f80000) | (($field_val << 19) & 0x00f80000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 19) & ~0x00f80000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval OFFSRANGE {
            namespace export SHIFT
            proc SHIFT {} {
                return 24
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 3
            }
            namespace export MASK
            proc MASK {} {
                return 0x07000000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x07000000) >> 24}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 24) & 0x07000000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x07000000) | (($field_val << 24) & 0x07000000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 24) & ~0x07000000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval THR {
            namespace export SHIFT
            proc SHIFT {} {
                return 27
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 5
            }
            namespace export MASK
            proc MASK {} {
                return 0xf8000000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0xf8000000) >> 27}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 27) & 0xf8000000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0xf8000000) | (($field_val << 27) & 0xf8000000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 27) & ~0xf8000000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x000320c8
        }
    }
    namespace export WURX0_0
    proc WURX0_0 { {base [::CMSDK_PMU_WURX::BASE]} } {
        return [expr { [expr $base] + 0x8 }]
    }
    namespace eval WURX0_0 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_PMU_WURX::BASE]} } {
            return [expr { [expr $base] + 0x8 }]
        }
        namespace eval UID {
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
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 0) & ~0xffffffff)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0xaaaaaaaa
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0xaaaaaaaa
        }
    }
    namespace export WURX0_1
    proc WURX0_1 { {base [::CMSDK_PMU_WURX::BASE]} } {
        return [expr { [expr $base] + 0xc }]
    }
    namespace eval WURX0_1 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_PMU_WURX::BASE]} } {
            return [expr { [expr $base] + 0xc }]
        }
        namespace eval GID {
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
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 0) & ~0xffffffff)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0xffffffff
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0xffffffff
        }
    }
    namespace export WURX0_2
    proc WURX0_2 { {base [::CMSDK_PMU_WURX::BASE]} } {
        return [expr { [expr $base] + 0x10 }]
    }
    namespace eval WURX0_2 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_PMU_WURX::BASE]} } {
            return [expr { [expr $base] + 0x10 }]
        }
        namespace eval ERR_THRESHOLD {
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
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 0) & ~0x0000003f)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x0000001f
            }
        }
        namespace eval TOO_LO1 {
            namespace export SHIFT
            proc SHIFT {} {
                return 6
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 5
            }
            namespace export MASK
            proc MASK {} {
                return 0x000007c0
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x000007c0) >> 6}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 6) & 0x000007c0}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x000007c0) | (($field_val << 6) & 0x000007c0)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 6) & ~0x000007c0)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000005
            }
        }
        namespace eval TOO_LO2 {
            namespace export SHIFT
            proc SHIFT {} {
                return 11
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 5
            }
            namespace export MASK
            proc MASK {} {
                return 0x0000f800
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x0000f800) >> 11}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 11) & 0x0000f800}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x0000f800) | (($field_val << 11) & 0x0000f800)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 11) & ~0x0000f800)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x0000000a
            }
        }
        namespace eval TOO_HI {
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
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 16) & ~0x001f0000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x0000000a
            }
        }
        namespace eval CORR_LENGTH {
            namespace export SHIFT
            proc SHIFT {} {
                return 21
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 6
            }
            namespace export MASK
            proc MASK {} {
                return 0x07e00000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x07e00000) >> 21}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 21) & 0x07e00000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x07e00000) | (($field_val << 21) & 0x07e00000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 21) & ~0x07e00000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000020
            }
        }
        namespace eval THR_LENGTH {
            namespace export SHIFT
            proc SHIFT {} {
                return 27
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 4
            }
            namespace export MASK
            proc MASK {} {
                return 0x78000000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x78000000) >> 27}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 27) & 0x78000000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x78000000) | (($field_val << 27) & 0x78000000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 27) & ~0x78000000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000001
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x0c0a515f
        }
    }
    namespace export WURX0_3
    proc WURX0_3 { {base [::CMSDK_PMU_WURX::BASE]} } {
        return [expr { [expr $base] + 0x14 }]
    }
    namespace eval WURX0_3 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_PMU_WURX::BASE]} } {
            return [expr { [expr $base] + 0x14 }]
        }
        namespace eval ENERGY_TOOLOW {
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
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 0) & ~0x000001ff)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000004
            }
        }
        namespace eval ENERGY_TOOHIGH {
            namespace export SHIFT
            proc SHIFT {} {
                return 9
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 10
            }
            namespace export MASK
            proc MASK {} {
                return 0x0007fe00
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x0007fe00) >> 9}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 9) & 0x0007fe00}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x0007fe00) | (($field_val << 9) & 0x0007fe00)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 9) & ~0x0007fe00)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000006
            }
        }
        namespace eval SYM1_THRESHOLD {
            namespace export SHIFT
            proc SHIFT {} {
                return 19
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 10
            }
            namespace export MASK
            proc MASK {} {
                return 0x1ff80000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x1ff80000) >> 19}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 19) & 0x1ff80000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x1ff80000) | (($field_val << 19) & 0x1ff80000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 19) & ~0x1ff80000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000002
            }
        }
        namespace eval CLK_FREQ {
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
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 29) & ~0x20000000)}]
            }
            namespace export SET
            proc SET {var_name} {
                upvar $var_name var
                set var [expr {($var & ~0x20000000) | (1 << 29)}]
            }
            namespace export CLR
            proc CLR {var_name} {
                upvar $var_name var
                set var [expr {$var & ~0x20000000}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000001
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x20100c04
        }
    }
    namespace export WURX0_4
    proc WURX0_4 { {base [::CMSDK_PMU_WURX::BASE]} } {
        return [expr { [expr $base] + 0x18 }]
    }
    namespace eval WURX0_4 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_PMU_WURX::BASE]} } {
            return [expr { [expr $base] + 0x18 }]
        }
        namespace eval TIMER_MAX {
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
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 0) & ~0x000003ff)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x0000000f
            }
        }
        namespace eval SYM_SILENT_THR {
            namespace export SHIFT
            proc SHIFT {} {
                return 10
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 5
            }
            namespace export MASK
            proc MASK {} {
                return 0x00007c00
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00007c00) >> 10}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 10) & 0x00007c00}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00007c00) | (($field_val << 10) & 0x00007c00)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 10) & ~0x00007c00)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000008
            }
        }
        namespace eval INIT_CAL_STEP {
            namespace export SHIFT
            proc SHIFT {} {
                return 15
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 9
            }
            namespace export MASK
            proc MASK {} {
                return 0x00ff8000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00ff8000) >> 15}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 15) & 0x00ff8000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00ff8000) | (($field_val << 15) & 0x00ff8000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 15) & ~0x00ff8000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000100
            }
        }
        namespace eval CAL_SILENT_THR {
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
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 24) & ~0x7f000000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000008
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x0880200f
        }
    }
    namespace export WURX1_0
    proc WURX1_0 { {base [::CMSDK_PMU_WURX::BASE]} } {
        return [expr { [expr $base] + 0x1c }]
    }
    namespace eval WURX1_0 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_PMU_WURX::BASE]} } {
            return [expr { [expr $base] + 0x1c }]
        }
        namespace eval UID {
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
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 0) & ~0xffffffff)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0xaaaaaaaa
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0xaaaaaaaa
        }
    }
    namespace export WURX1_1
    proc WURX1_1 { {base [::CMSDK_PMU_WURX::BASE]} } {
        return [expr { [expr $base] + 0x20 }]
    }
    namespace eval WURX1_1 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_PMU_WURX::BASE]} } {
            return [expr { [expr $base] + 0x20 }]
        }
        namespace eval GID {
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
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 0) & ~0xffffffff)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0xffffffff
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0xffffffff
        }
    }
    namespace export WURX1_2
    proc WURX1_2 { {base [::CMSDK_PMU_WURX::BASE]} } {
        return [expr { [expr $base] + 0x24 }]
    }
    namespace eval WURX1_2 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_PMU_WURX::BASE]} } {
            return [expr { [expr $base] + 0x24 }]
        }
        namespace eval ERR_THRESHOLD {
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
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 0) & ~0x0000003f)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x0000001f
            }
        }
        namespace eval TOO_LO1 {
            namespace export SHIFT
            proc SHIFT {} {
                return 6
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 5
            }
            namespace export MASK
            proc MASK {} {
                return 0x000007c0
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x000007c0) >> 6}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 6) & 0x000007c0}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x000007c0) | (($field_val << 6) & 0x000007c0)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 6) & ~0x000007c0)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000005
            }
        }
        namespace eval TOO_LO2 {
            namespace export SHIFT
            proc SHIFT {} {
                return 11
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 5
            }
            namespace export MASK
            proc MASK {} {
                return 0x0000f800
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x0000f800) >> 11}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 11) & 0x0000f800}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x0000f800) | (($field_val << 11) & 0x0000f800)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 11) & ~0x0000f800)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x0000000a
            }
        }
        namespace eval TOO_HI {
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
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 16) & ~0x001f0000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x0000000a
            }
        }
        namespace eval CORR_LENGTH {
            namespace export SHIFT
            proc SHIFT {} {
                return 21
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 6
            }
            namespace export MASK
            proc MASK {} {
                return 0x07e00000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x07e00000) >> 21}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 21) & 0x07e00000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x07e00000) | (($field_val << 21) & 0x07e00000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 21) & ~0x07e00000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000020
            }
        }
        namespace eval THR_LENGTH {
            namespace export SHIFT
            proc SHIFT {} {
                return 27
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 4
            }
            namespace export MASK
            proc MASK {} {
                return 0x78000000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x78000000) >> 27}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 27) & 0x78000000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x78000000) | (($field_val << 27) & 0x78000000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 27) & ~0x78000000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000001
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x0c0a515f
        }
    }
    namespace export WURX1_3
    proc WURX1_3 { {base [::CMSDK_PMU_WURX::BASE]} } {
        return [expr { [expr $base] + 0x28 }]
    }
    namespace eval WURX1_3 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_PMU_WURX::BASE]} } {
            return [expr { [expr $base] + 0x28 }]
        }
        namespace eval ENERGY_TOOLOW {
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
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 0) & ~0x000001ff)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000004
            }
        }
        namespace eval ENERGY_TOOHIGH {
            namespace export SHIFT
            proc SHIFT {} {
                return 9
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 10
            }
            namespace export MASK
            proc MASK {} {
                return 0x0007fe00
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x0007fe00) >> 9}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 9) & 0x0007fe00}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x0007fe00) | (($field_val << 9) & 0x0007fe00)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 9) & ~0x0007fe00)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000006
            }
        }
        namespace eval SYM1_THRESHOLD {
            namespace export SHIFT
            proc SHIFT {} {
                return 19
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 10
            }
            namespace export MASK
            proc MASK {} {
                return 0x1ff80000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x1ff80000) >> 19}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 19) & 0x1ff80000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x1ff80000) | (($field_val << 19) & 0x1ff80000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 19) & ~0x1ff80000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000002
            }
        }
        namespace eval CLK_FREQ {
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
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 29) & ~0x20000000)}]
            }
            namespace export SET
            proc SET {var_name} {
                upvar $var_name var
                set var [expr {($var & ~0x20000000) | (1 << 29)}]
            }
            namespace export CLR
            proc CLR {var_name} {
                upvar $var_name var
                set var [expr {$var & ~0x20000000}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000001
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x20100c04
        }
    }
    namespace export WURX1_4
    proc WURX1_4 { {base [::CMSDK_PMU_WURX::BASE]} } {
        return [expr { [expr $base] + 0x2c }]
    }
    namespace eval WURX1_4 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_PMU_WURX::BASE]} } {
            return [expr { [expr $base] + 0x2c }]
        }
        namespace eval TIMER_MAX {
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
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 0) & ~0x000003ff)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x0000000f
            }
        }
        namespace eval SYM_SILENT_THR {
            namespace export SHIFT
            proc SHIFT {} {
                return 10
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 5
            }
            namespace export MASK
            proc MASK {} {
                return 0x00007c00
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00007c00) >> 10}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 10) & 0x00007c00}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00007c00) | (($field_val << 10) & 0x00007c00)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 10) & ~0x00007c00)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000008
            }
        }
        namespace eval INIT_CAL_STEP {
            namespace export SHIFT
            proc SHIFT {} {
                return 15
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 9
            }
            namespace export MASK
            proc MASK {} {
                return 0x00ff8000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00ff8000) >> 15}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 15) & 0x00ff8000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00ff8000) | (($field_val << 15) & 0x00ff8000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 15) & ~0x00ff8000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000100
            }
        }
        namespace eval CAL_SILENT_THR {
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
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 24) & ~0x7f000000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000008
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x0880200f
        }
    }
    namespace export WURX_RB0
    proc WURX_RB0 { {base [::CMSDK_PMU_WURX::BASE]} } {
        return [expr { [expr $base] + 0x30 }]
    }
    namespace eval WURX_RB0 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_PMU_WURX::BASE]} } {
            return [expr { [expr $base] + 0x30 }]
        }
        namespace eval STATE {
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
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval OUT_ENERGY {
            namespace export SHIFT
            proc SHIFT {} {
                return 2
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 10
            }
            namespace export MASK
            proc MASK {} {
                return 0x00000ffc
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00000ffc) >> 2}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval CAL_STEP {
            namespace export SHIFT
            proc SHIFT {} {
                return 12
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 8
            }
            namespace export MASK
            proc MASK {} {
                return 0x000ff000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x000ff000) >> 12}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval MONITOR_2HI {
            namespace export SHIFT
            proc SHIFT {} {
                return 20
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 5
            }
            namespace export MASK
            proc MASK {} {
                return 0x01f00000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x01f00000) >> 20}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval MONITOR_2LO {
            namespace export SHIFT
            proc SHIFT {} {
                return 25
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 5
            }
            namespace export MASK
            proc MASK {} {
                return 0x3e000000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x3e000000) >> 25}]
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
    namespace export WURX_RB1
    proc WURX_RB1 { {base [::CMSDK_PMU_WURX::BASE]} } {
        return [expr { [expr $base] + 0x34 }]
    }
    namespace eval WURX_RB1 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_PMU_WURX::BASE]} } {
            return [expr { [expr $base] + 0x34 }]
        }
        namespace eval OFFSET_CAL {
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
        namespace eval ANALOG_CAL {
            namespace export SHIFT
            proc SHIFT {} {
                return 8
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 9
            }
            namespace export MASK
            proc MASK {} {
                return 0x0001ff00
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x0001ff00) >> 8}]
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
    namespace export WURX_RB2
    proc WURX_RB2 { {base [::CMSDK_PMU_WURX::BASE]} } {
        return [expr { [expr $base] + 0x38 }]
    }
    namespace eval WURX_RB2 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_PMU_WURX::BASE]} } {
            return [expr { [expr $base] + 0x38 }]
        }
        namespace eval CNT_DET0 {
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
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval CNT_DET1 {
            namespace export SHIFT
            proc SHIFT {} {
                return 10
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 10
            }
            namespace export MASK
            proc MASK {} {
                return 0x000ffc00
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x000ffc00) >> 10}]
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
    namespace export WURX_SPARE
    proc WURX_SPARE { {base [::CMSDK_PMU_WURX::BASE]} } {
        return [expr { [expr $base] + 0x3c }]
    }
    namespace eval WURX_SPARE {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_PMU_WURX::BASE]} } {
            return [expr { [expr $base] + 0x3c }]
        }
        namespace eval WURX_DIG_IN_SEL {
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
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 0) & ~0x00000001)}]
            }
            namespace export SET
            proc SET {var_name} {
                upvar $var_name var
                set var [expr {($var & ~0x00000001) | (1 << 0)}]
            }
            namespace export CLR
            proc CLR {var_name} {
                upvar $var_name var
                set var [expr {$var & ~0x00000001}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000001
            }
        }
        namespace eval LONGRST {
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
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 1) & ~0x00000002)}]
            }
            namespace export SET
            proc SET {var_name} {
                upvar $var_name var
                set var [expr {($var & ~0x00000002) | (1 << 1)}]
            }
            namespace export CLR
            proc CLR {var_name} {
                upvar $var_name var
                set var [expr {$var & ~0x00000002}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval DELRST {
            namespace export SHIFT
            proc SHIFT {} {
                return 2
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 2
            }
            namespace export MASK
            proc MASK {} {
                return 0x0000000c
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x0000000c) >> 2}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 2) & 0x0000000c}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x0000000c) | (($field_val << 2) & 0x0000000c)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 2) & ~0x0000000c)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval BYPASSAMP {
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
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 4) & ~0x00000010)}]
            }
            namespace export SET
            proc SET {var_name} {
                upvar $var_name var
                set var [expr {($var & ~0x00000010) | (1 << 4)}]
            }
            namespace export CLR
            proc CLR {var_name} {
                upvar $var_name var
                set var [expr {$var & ~0x00000010}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval SETTLE1_REG {
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
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 5) & 0x000003e0}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x000003e0) | (($field_val << 5) & 0x000003e0)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 5) & ~0x000003e0)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x0000000d
            }
        }
        namespace eval SETTLE2_REG {
            namespace export SHIFT
            proc SHIFT {} {
                return 10
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 5
            }
            namespace export MASK
            proc MASK {} {
                return 0x00007c00
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00007c00) >> 10}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 10) & 0x00007c00}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00007c00) | (($field_val << 10) & 0x00007c00)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 10) & ~0x00007c00)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000011
            }
        }
        namespace eval SPARES {
            namespace export SHIFT
            proc SHIFT {} {
                return 15
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 17
            }
            namespace export MASK
            proc MASK {} {
                return 0xffff8000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0xffff8000) >> 15}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 15) & 0xffff8000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0xffff8000) | (($field_val << 15) & 0xffff8000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 15) & ~0xffff8000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x000045a1
        }
    }
    namespace export CORE_ID
    proc CORE_ID { {base [::CMSDK_PMU_WURX::BASE]} } {
        return [expr { [expr $base] + 0x40 }]
    }
    namespace eval CORE_ID {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_PMU_WURX::BASE]} } {
            return [expr { [expr $base] + 0x40 }]
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
                return 0x57555258
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x57555258
        }
    }
}
