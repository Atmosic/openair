namespace eval CMSDK_MDM_NONSECURE {
    namespace export BASE
    proc BASE {} {
        return 0x40156000
    }
    namespace export AGCMEAS
    proc AGCMEAS { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x0 }]
    }
    namespace eval AGCMEAS {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x0 }]
        }
        namespace eval RSSI_OFFSET {
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
                return 0x00000011
            }
        }
        namespace eval DET_MIN {
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
                return 0x0000004d
            }
        }
        namespace eval TWOMEG_RSSI_OFFSET {
            namespace export SHIFT
            proc SHIFT {} {
                return 15
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 8
            }
            namespace export MASK
            proc MASK {} {
                return 0x007f8000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x007f8000) >> 15}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 15) & 0x007f8000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x007f8000) | (($field_val << 15) & 0x007f8000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x007f8000) | (($field_val << 15) & 0x007f8000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 15) & ~0x007f8000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000011
            }
        }
        namespace eval TWOMEG_DET_MIN {
            namespace export SHIFT
            proc SHIFT {} {
                return 23
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 7
            }
            namespace export MASK
            proc MASK {} {
                return 0x3f800000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x3f800000) >> 23}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 23) & 0x3f800000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x3f800000) | (($field_val << 23) & 0x3f800000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x3f800000) | (($field_val << 23) & 0x3f800000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 23) & ~0x3f800000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000050
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x2808cd11
        }
    }
    namespace export AGCGAIN
    proc AGCGAIN { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x4 }]
    }
    namespace eval AGCGAIN {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x4 }]
        }
        namespace eval START {
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
                return 0x0000004c
            }
        }
        namespace eval RFIN_PD_QUICK_DROP {
            namespace export SHIFT
            proc SHIFT {} {
                return 14
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 7
            }
            namespace export MASK
            proc MASK {} {
                return 0x001fc000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x001fc000) >> 14}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 14) & 0x001fc000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x001fc000) | (($field_val << 14) & 0x001fc000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x001fc000) | (($field_val << 14) & 0x001fc000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 14) & ~0x001fc000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000045
            }
        }
        namespace eval TIA_QUICK_DROP {
            namespace export SHIFT
            proc SHIFT {} {
                return 21
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 7
            }
            namespace export MASK
            proc MASK {} {
                return 0x0fe00000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x0fe00000) >> 21}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 21) & 0x0fe00000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x0fe00000) | (($field_val << 21) & 0x0fe00000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x0fe00000) | (($field_val << 21) & 0x0fe00000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 21) & ~0x0fe00000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000036
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x06d1404c
        }
    }
    namespace export DCOFF
    proc DCOFF { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x8 }]
    }
    namespace eval DCOFF {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x8 }]
        }
        namespace eval FORCE {
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
        namespace eval FORCED_I {
            namespace export SHIFT
            proc SHIFT {} {
                return 1
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 8
            }
            namespace export MASK
            proc MASK {} {
                return 0x000001fe
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x000001fe) >> 1}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 1) & 0x000001fe}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x000001fe) | (($field_val << 1) & 0x000001fe)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x000001fe) | (($field_val << 1) & 0x000001fe)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 1) & ~0x000001fe)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval FORCED_Q {
            namespace export SHIFT
            proc SHIFT {} {
                return 9
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 8
            }
            namespace export MASK
            proc MASK {} {
                return 0x0001fe00
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x0001fe00) >> 9}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 9) & 0x0001fe00}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x0001fe00) | (($field_val << 9) & 0x0001fe00)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x0001fe00) | (($field_val << 9) & 0x0001fe00)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 9) & ~0x0001fe00)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x00000001
        }
    }
    namespace export TIA_FORCE_DCCALRESULTS
    proc TIA_FORCE_DCCALRESULTS { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0xc }]
    }
    namespace eval TIA_FORCE_DCCALRESULTS {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0xc }]
        }
        namespace eval Q_OFF {
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
        namespace eval I_OFF {
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
        namespace eval BB2GAIN {
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
        namespace eval FORCE {
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
    namespace export TIA_FORCE_DCCALRESULTS2
    proc TIA_FORCE_DCCALRESULTS2 { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x10 }]
    }
    namespace eval TIA_FORCE_DCCALRESULTS2 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x10 }]
        }
        namespace eval AVG_Q {
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
        namespace eval AVG_I {
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
        namespace eval FORCE {
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
    namespace export TIA_LP_FORCE_DCCALRESULTS
    proc TIA_LP_FORCE_DCCALRESULTS { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x14 }]
    }
    namespace eval TIA_LP_FORCE_DCCALRESULTS {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x14 }]
        }
        namespace eval Q_OFF {
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
        namespace eval I_OFF {
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
        namespace eval BB2GAIN {
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
        namespace eval FORCE {
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
    namespace export TIA_LP_FORCE_DCCALRESULTS2
    proc TIA_LP_FORCE_DCCALRESULTS2 { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x18 }]
    }
    namespace eval TIA_LP_FORCE_DCCALRESULTS2 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x18 }]
        }
        namespace eval AVG_Q {
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
        namespace eval AVG_I {
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
        namespace eval FORCE {
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
    namespace export PGA_FORCE_DCCALRESULTS
    proc PGA_FORCE_DCCALRESULTS { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x1c }]
    }
    namespace eval PGA_FORCE_DCCALRESULTS {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x1c }]
        }
        namespace eval Q_OFF {
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
                return 0x00000000
            }
        }
        namespace eval I_OFF {
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
                return 0x00000000
            }
        }
        namespace eval BB2GAIN {
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
        namespace eval FORCE {
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
    namespace export PGA_FORCE_DCCALRESULTS2
    proc PGA_FORCE_DCCALRESULTS2 { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x20 }]
    }
    namespace eval PGA_FORCE_DCCALRESULTS2 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x20 }]
        }
        namespace eval AVG_Q {
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
        namespace eval AVG_I {
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
        namespace eval FORCE {
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
    namespace export PGA_LP_FORCE_DCCALRESULTS
    proc PGA_LP_FORCE_DCCALRESULTS { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x24 }]
    }
    namespace eval PGA_LP_FORCE_DCCALRESULTS {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x24 }]
        }
        namespace eval Q_OFF {
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
                return 0x00000000
            }
        }
        namespace eval I_OFF {
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
                return 0x00000000
            }
        }
        namespace eval BB2GAIN {
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
        namespace eval FORCE {
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
    namespace export PGA_LP_FORCE_DCCALRESULTS2
    proc PGA_LP_FORCE_DCCALRESULTS2 { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x28 }]
    }
    namespace eval PGA_LP_FORCE_DCCALRESULTS2 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x28 }]
        }
        namespace eval AVG_Q {
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
        namespace eval AVG_I {
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
        namespace eval FORCE {
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
    namespace export NOTCH_FORCE_DCCALRESULTS
    proc NOTCH_FORCE_DCCALRESULTS { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x2c }]
    }
    namespace eval NOTCH_FORCE_DCCALRESULTS {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x2c }]
        }
        namespace eval CTN {
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
                return 0x00000000
            }
        }
        namespace eval FORCE {
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
    namespace export PGA_CAL_GAIN_FORCE_DCCALRESULTS
    proc PGA_CAL_GAIN_FORCE_DCCALRESULTS { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x30 }]
    }
    namespace eval PGA_CAL_GAIN_FORCE_DCCALRESULTS {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x30 }]
        }
        namespace eval Q_OFF {
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
                return 0x00000000
            }
        }
        namespace eval I_OFF {
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
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x000003e0) | (($field_val << 5) & 0x000003e0)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 5) & ~0x000003e0)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval FORCE {
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
    namespace export PGA_CAL_GAIN_FORCE_DCCALRESULTS2
    proc PGA_CAL_GAIN_FORCE_DCCALRESULTS2 { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x34 }]
    }
    namespace eval PGA_CAL_GAIN_FORCE_DCCALRESULTS2 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x34 }]
        }
        namespace eval AVG_Q {
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
        namespace eval AVG_I {
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
        namespace eval BB2GAIN {
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
        namespace eval FORCE_AVG {
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
        namespace eval FORCE_BB2GAIN {
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
    namespace export IQCORR
    proc IQCORR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x38 }]
    }
    namespace eval IQCORR {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x38 }]
        }
        namespace eval AMPL_CORR_DEFAULT {
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
        namespace eval PHASE_CORR_DEFAULT {
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
        namespace eval TWOMEG_AMPL_CORR_DEFAULT {
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
        namespace eval TWOMEG_PHASE_CORR_DEFAULT {
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
            return 0x00000000
        }
    }
    namespace export AGCMEAS_ALT
    proc AGCMEAS_ALT { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x3c }]
    }
    namespace eval AGCMEAS_ALT {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x3c }]
        }
        namespace eval RSSI_OFFSET {
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
                return 0x00000011
            }
        }
        namespace eval DET_MIN {
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
                return 0x0000004d
            }
        }
        namespace eval TWOMEG_RSSI_OFFSET {
            namespace export SHIFT
            proc SHIFT {} {
                return 15
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 8
            }
            namespace export MASK
            proc MASK {} {
                return 0x007f8000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x007f8000) >> 15}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 15) & 0x007f8000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x007f8000) | (($field_val << 15) & 0x007f8000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x007f8000) | (($field_val << 15) & 0x007f8000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 15) & ~0x007f8000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000011
            }
        }
        namespace eval TWOMEG_DET_MIN {
            namespace export SHIFT
            proc SHIFT {} {
                return 23
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 7
            }
            namespace export MASK
            proc MASK {} {
                return 0x3f800000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x3f800000) >> 23}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 23) & 0x3f800000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x3f800000) | (($field_val << 23) & 0x3f800000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x3f800000) | (($field_val << 23) & 0x3f800000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 23) & ~0x3f800000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000050
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x2808cd11
        }
    }
    namespace export AGCGAIN_ALT
    proc AGCGAIN_ALT { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x40 }]
    }
    namespace eval AGCGAIN_ALT {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x40 }]
        }
        namespace eval START {
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
                return 0x0000004c
            }
        }
        namespace eval RFIN_PD_QUICK_DROP {
            namespace export SHIFT
            proc SHIFT {} {
                return 14
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 7
            }
            namespace export MASK
            proc MASK {} {
                return 0x001fc000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x001fc000) >> 14}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 14) & 0x001fc000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x001fc000) | (($field_val << 14) & 0x001fc000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x001fc000) | (($field_val << 14) & 0x001fc000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 14) & ~0x001fc000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000045
            }
        }
        namespace eval TIA_QUICK_DROP {
            namespace export SHIFT
            proc SHIFT {} {
                return 21
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 7
            }
            namespace export MASK
            proc MASK {} {
                return 0x0fe00000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x0fe00000) >> 21}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 21) & 0x0fe00000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x0fe00000) | (($field_val << 21) & 0x0fe00000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x0fe00000) | (($field_val << 21) & 0x0fe00000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 21) & ~0x0fe00000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000036
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x06d1404c
        }
    }
    namespace export XLNA
    proc XLNA { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x44 }]
    }
    namespace eval XLNA {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x44 }]
        }
        namespace eval GAIN_SETTLE {
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
                return 0x0000001c
            }
        }
        namespace eval TWOMEG_GAIN_SETTLE {
            namespace export SHIFT
            proc SHIFT {} {
                return 6
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 6
            }
            namespace export MASK
            proc MASK {} {
                return 0x00000fc0
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00000fc0) >> 6}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 6) & 0x00000fc0}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00000fc0) | (($field_val << 6) & 0x00000fc0)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00000fc0) | (($field_val << 6) & 0x00000fc0)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 6) & ~0x00000fc0)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000010
            }
        }
        namespace eval RESET_FILT_DELAY {
            namespace export SHIFT
            proc SHIFT {} {
                return 12
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 6
            }
            namespace export MASK
            proc MASK {} {
                return 0x0003f000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x0003f000) >> 12}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 12) & 0x0003f000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x0003f000) | (($field_val << 12) & 0x0003f000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x0003f000) | (($field_val << 12) & 0x0003f000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 12) & ~0x0003f000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000010
            }
        }
        namespace eval TWOMEG_RESET_FILT_DELAY {
            namespace export SHIFT
            proc SHIFT {} {
                return 18
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 6
            }
            namespace export MASK
            proc MASK {} {
                return 0x00fc0000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00fc0000) >> 18}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 18) & 0x00fc0000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00fc0000) | (($field_val << 18) & 0x00fc0000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00fc0000) | (($field_val << 18) & 0x00fc0000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 18) & ~0x00fc0000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x0000000a
            }
        }
        namespace eval THRESH {
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
                return 0x0000007f
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x7f29041c
        }
    }
    namespace export XLNA_ALT
    proc XLNA_ALT { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x48 }]
    }
    namespace eval XLNA_ALT {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x48 }]
        }
        namespace eval GAIN_SETTLE {
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
                return 0x0000001c
            }
        }
        namespace eval TWOMEG_GAIN_SETTLE {
            namespace export SHIFT
            proc SHIFT {} {
                return 6
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 6
            }
            namespace export MASK
            proc MASK {} {
                return 0x00000fc0
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00000fc0) >> 6}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 6) & 0x00000fc0}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00000fc0) | (($field_val << 6) & 0x00000fc0)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00000fc0) | (($field_val << 6) & 0x00000fc0)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 6) & ~0x00000fc0)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000010
            }
        }
        namespace eval RESET_FILT_DELAY {
            namespace export SHIFT
            proc SHIFT {} {
                return 12
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 6
            }
            namespace export MASK
            proc MASK {} {
                return 0x0003f000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x0003f000) >> 12}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 12) & 0x0003f000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x0003f000) | (($field_val << 12) & 0x0003f000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x0003f000) | (($field_val << 12) & 0x0003f000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 12) & ~0x0003f000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000010
            }
        }
        namespace eval TWOMEG_RESET_FILT_DELAY {
            namespace export SHIFT
            proc SHIFT {} {
                return 18
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 6
            }
            namespace export MASK
            proc MASK {} {
                return 0x00fc0000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00fc0000) >> 18}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 18) & 0x00fc0000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00fc0000) | (($field_val << 18) & 0x00fc0000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00fc0000) | (($field_val << 18) & 0x00fc0000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 18) & ~0x00fc0000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x0000000a
            }
        }
        namespace eval THRESH {
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
                return 0x0000007f
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x7f29041c
        }
    }
    namespace export AGCSAT
    proc AGCSAT { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x4c }]
    }
    namespace eval AGCSAT {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x4c }]
        }
        namespace eval CHECK_WIN {
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
                return 0x00000004
            }
        }
        namespace eval THR_CNT {
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
                return 0x00000001
            }
        }
        namespace eval CHECK_THR_HIGH {
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
                return 0x00000066
            }
        }
        namespace eval CHECK_THR_LOW {
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
                return 0x0000009a
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x009a6614
        }
    }
    namespace export AGCSAT_ALT
    proc AGCSAT_ALT { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x50 }]
    }
    namespace eval AGCSAT_ALT {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x50 }]
        }
        namespace eval CHECK_WIN {
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
                return 0x00000004
            }
        }
        namespace eval THR_CNT {
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
                return 0x00000001
            }
        }
        namespace eval CHECK_THR_HIGH {
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
                return 0x00000066
            }
        }
        namespace eval CHECK_THR_LOW {
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
                return 0x0000009a
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x009a6614
        }
    }
    namespace export BASELINE
    proc BASELINE { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x54 }]
    }
    namespace eval BASELINE {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x54 }]
        }
        namespace eval LOW_PWR_THR {
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
                return 0x000000d6
            }
        }
        namespace eval TWOMEG_LOW_PWR_THR {
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
                return 0x000000d9
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x0000d9d6
        }
    }
    namespace export BASELINE_ALT
    proc BASELINE_ALT { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x58 }]
    }
    namespace eval BASELINE_ALT {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x58 }]
        }
        namespace eval LOW_PWR_THR {
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
                return 0x000000d6
            }
        }
        namespace eval TWOMEG_LOW_PWR_THR {
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
                return 0x000000d9
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x0000d9d6
        }
    }
    namespace export MARGIN
    proc MARGIN { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x5c }]
    }
    namespace eval MARGIN {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x5c }]
        }
        namespace eval ADC_MAX_LOW_INBAND_PWR {
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
                return 0x00000004
            }
        }
        namespace eval TWOMEG_ADC_MAX_LOW_INBAND_PWR {
            namespace export SHIFT
            proc SHIFT {} {
                return 6
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 6
            }
            namespace export MASK
            proc MASK {} {
                return 0x00000fc0
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00000fc0) >> 6}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 6) & 0x00000fc0}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00000fc0) | (($field_val << 6) & 0x00000fc0)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00000fc0) | (($field_val << 6) & 0x00000fc0)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 6) & ~0x00000fc0)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000006
            }
        }
        namespace eval STRONG_BLOCKER_THR {
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
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 12) & 0x000ff000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x000ff000) | (($field_val << 12) & 0x000ff000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x000ff000) | (($field_val << 12) & 0x000ff000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 12) & ~0x000ff000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000009
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x00009184
        }
    }
    namespace export MARGIN_ALT
    proc MARGIN_ALT { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x60 }]
    }
    namespace eval MARGIN_ALT {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x60 }]
        }
        namespace eval ADC_MAX_LOW_INBAND_PWR {
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
                return 0x00000004
            }
        }
        namespace eval TWOMEG_ADC_MAX_LOW_INBAND_PWR {
            namespace export SHIFT
            proc SHIFT {} {
                return 6
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 6
            }
            namespace export MASK
            proc MASK {} {
                return 0x00000fc0
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00000fc0) >> 6}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 6) & 0x00000fc0}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00000fc0) | (($field_val << 6) & 0x00000fc0)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00000fc0) | (($field_val << 6) & 0x00000fc0)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 6) & ~0x00000fc0)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000006
            }
        }
        namespace eval STRONG_BLOCKER_THR {
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
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 12) & 0x000ff000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x000ff000) | (($field_val << 12) & 0x000ff000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x000ff000) | (($field_val << 12) & 0x000ff000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 12) & ~0x000ff000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000009
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x00009184
        }
    }
    namespace export PWRSTEP
    proc PWRSTEP { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x64 }]
    }
    namespace eval PWRSTEP {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x64 }]
        }
        namespace eval BASELINE_MEAS_DUR {
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
        namespace eval BASELINE_MEAS_DELAY {
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
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x0000000c) | (($field_val << 2) & 0x0000000c)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 2) & ~0x0000000c)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000001
            }
        }
        namespace eval CNT {
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
                return 0x00000008
            }
        }
        namespace eval CNT_THR {
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
        namespace eval HYST_THR {
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
                return 0x00000004
            }
        }
        namespace eval DISABLE_HYST_FOR_BLOCKER {
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
                return 0x00000001
            }
        }
        namespace eval TWOMEG_BASELINE_MEAS_DUR {
            namespace export SHIFT
            proc SHIFT {} {
                return 17
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 2
            }
            namespace export MASK
            proc MASK {} {
                return 0x00060000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00060000) >> 17}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 17) & 0x00060000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00060000) | (($field_val << 17) & 0x00060000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00060000) | (($field_val << 17) & 0x00060000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 17) & ~0x00060000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000002
            }
        }
        namespace eval TWOMEG_BASELINE_MEAS_DELAY {
            namespace export SHIFT
            proc SHIFT {} {
                return 19
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 2
            }
            namespace export MASK
            proc MASK {} {
                return 0x00180000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00180000) >> 19}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 19) & 0x00180000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00180000) | (($field_val << 19) & 0x00180000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00180000) | (($field_val << 19) & 0x00180000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 19) & ~0x00180000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000001
            }
        }
        namespace eval SEPARATE_POS_AND_NEG {
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
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00200000) | (($field_val << 21) & 0x00200000)}]
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
            namespace export SET_TGT
            proc SET_TGT {addr} {
                mww $addr [expr {([mrw $addr] & ~0x00200000) | (1 << 21)}]
            }
            namespace export CLR
            proc CLR {var_name} {
                upvar $var_name var
                set var [expr {$var & ~0x00200000}]
            }
            namespace export CLR_TGT
            proc CLR_TGT {addr} {
                mww $addr [expr {[mrw $addr] & ~0x00200000}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x000d4684
        }
    }
    namespace export PWRSTEP_ALT
    proc PWRSTEP_ALT { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x68 }]
    }
    namespace eval PWRSTEP_ALT {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x68 }]
        }
        namespace eval BASELINE_MEAS_DUR {
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
        namespace eval BASELINE_MEAS_DELAY {
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
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x0000000c) | (($field_val << 2) & 0x0000000c)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 2) & ~0x0000000c)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000001
            }
        }
        namespace eval CNT {
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
                return 0x00000008
            }
        }
        namespace eval CNT_THR {
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
        namespace eval HYST_THR {
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
                return 0x00000004
            }
        }
        namespace eval DISABLE_HYST_FOR_BLOCKER {
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
                return 0x00000001
            }
        }
        namespace eval TWOMEG_BASELINE_MEAS_DUR {
            namespace export SHIFT
            proc SHIFT {} {
                return 17
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 2
            }
            namespace export MASK
            proc MASK {} {
                return 0x00060000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00060000) >> 17}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 17) & 0x00060000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00060000) | (($field_val << 17) & 0x00060000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00060000) | (($field_val << 17) & 0x00060000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 17) & ~0x00060000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000002
            }
        }
        namespace eval TWOMEG_BASELINE_MEAS_DELAY {
            namespace export SHIFT
            proc SHIFT {} {
                return 19
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 2
            }
            namespace export MASK
            proc MASK {} {
                return 0x00180000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00180000) >> 19}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 19) & 0x00180000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00180000) | (($field_val << 19) & 0x00180000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00180000) | (($field_val << 19) & 0x00180000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 19) & ~0x00180000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000001
            }
        }
        namespace eval SEPARATE_POS_AND_NEG {
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
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00200000) | (($field_val << 21) & 0x00200000)}]
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
            namespace export SET_TGT
            proc SET_TGT {addr} {
                mww $addr [expr {([mrw $addr] & ~0x00200000) | (1 << 21)}]
            }
            namespace export CLR
            proc CLR {var_name} {
                upvar $var_name var
                set var [expr {$var & ~0x00200000}]
            }
            namespace export CLR_TGT
            proc CLR_TGT {addr} {
                mww $addr [expr {[mrw $addr] & ~0x00200000}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x000d4684
        }
    }
    namespace export AGCPWR
    proc AGCPWR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x6c }]
    }
    namespace eval AGCPWR {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x6c }]
        }
        namespace eval INBAND_TARGET {
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
                return 0x00000065
            }
        }
        namespace eval ADC_MAX_TARGET {
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
                return 0x00000077
            }
        }
        namespace eval TWOMEG_INBAND_TARGET {
            namespace export SHIFT
            proc SHIFT {} {
                return 14
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 7
            }
            namespace export MASK
            proc MASK {} {
                return 0x001fc000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x001fc000) >> 14}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 14) & 0x001fc000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x001fc000) | (($field_val << 14) & 0x001fc000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x001fc000) | (($field_val << 14) & 0x001fc000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 14) & ~0x001fc000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000068
            }
        }
        namespace eval INBAND_PWR_ERR_THR_HI {
            namespace export SHIFT
            proc SHIFT {} {
                return 21
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 4
            }
            namespace export MASK
            proc MASK {} {
                return 0x01e00000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x01e00000) >> 21}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 21) & 0x01e00000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x01e00000) | (($field_val << 21) & 0x01e00000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x01e00000) | (($field_val << 21) & 0x01e00000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 21) & ~0x01e00000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x0000000c
            }
        }
        namespace eval INBAND_PWR_ERR_THR_LO {
            namespace export SHIFT
            proc SHIFT {} {
                return 25
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 4
            }
            namespace export MASK
            proc MASK {} {
                return 0x1e000000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x1e000000) >> 25}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 25) & 0x1e000000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x1e000000) | (($field_val << 25) & 0x1e000000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x1e000000) | (($field_val << 25) & 0x1e000000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 25) & ~0x1e000000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x0000000c
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x199a3be5
        }
    }
    namespace export AGCPWR_ALT
    proc AGCPWR_ALT { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x70 }]
    }
    namespace eval AGCPWR_ALT {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x70 }]
        }
        namespace eval INBAND_TARGET {
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
                return 0x00000065
            }
        }
        namespace eval ADC_MAX_TARGET {
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
                return 0x00000077
            }
        }
        namespace eval TWOMEG_INBAND_TARGET {
            namespace export SHIFT
            proc SHIFT {} {
                return 14
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 7
            }
            namespace export MASK
            proc MASK {} {
                return 0x001fc000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x001fc000) >> 14}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 14) & 0x001fc000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x001fc000) | (($field_val << 14) & 0x001fc000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x001fc000) | (($field_val << 14) & 0x001fc000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 14) & ~0x001fc000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000068
            }
        }
        namespace eval INBAND_PWR_ERR_THR_HI {
            namespace export SHIFT
            proc SHIFT {} {
                return 21
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 4
            }
            namespace export MASK
            proc MASK {} {
                return 0x01e00000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x01e00000) >> 21}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 21) & 0x01e00000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x01e00000) | (($field_val << 21) & 0x01e00000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x01e00000) | (($field_val << 21) & 0x01e00000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 21) & ~0x01e00000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x0000000c
            }
        }
        namespace eval INBAND_PWR_ERR_THR_LO {
            namespace export SHIFT
            proc SHIFT {} {
                return 25
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 4
            }
            namespace export MASK
            proc MASK {} {
                return 0x1e000000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x1e000000) >> 25}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 25) & 0x1e000000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x1e000000) | (($field_val << 25) & 0x1e000000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x1e000000) | (($field_val << 25) & 0x1e000000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 25) & ~0x1e000000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x0000000c
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x199a3be5
        }
    }
    namespace export AGCPWR2
    proc AGCPWR2 { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x74 }]
    }
    namespace eval AGCPWR2 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x74 }]
        }
        namespace eval MEAS_WIN {
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
                return 0x00000003
            }
        }
        namespace eval DET_STEP {
            namespace export SHIFT
            proc SHIFT {} {
                return 2
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 5
            }
            namespace export MASK
            proc MASK {} {
                return 0x0000007c
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x0000007c) >> 2}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 2) & 0x0000007c}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x0000007c) | (($field_val << 2) & 0x0000007c)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x0000007c) | (($field_val << 2) & 0x0000007c)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 2) & ~0x0000007c)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000006
            }
        }
        namespace eval DET_STEP_DELTA {
            namespace export SHIFT
            proc SHIFT {} {
                return 7
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 4
            }
            namespace export MASK
            proc MASK {} {
                return 0x00000780
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00000780) >> 7}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 7) & 0x00000780}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00000780) | (($field_val << 7) & 0x00000780)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00000780) | (($field_val << 7) & 0x00000780)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 7) & ~0x00000780)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000002
            }
        }
        namespace eval BASELINE_BLK_PWR_OFFSET {
            namespace export SHIFT
            proc SHIFT {} {
                return 11
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 6
            }
            namespace export MASK
            proc MASK {} {
                return 0x0001f800
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x0001f800) >> 11}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 11) & 0x0001f800}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x0001f800) | (($field_val << 11) & 0x0001f800)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x0001f800) | (($field_val << 11) & 0x0001f800)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 11) & ~0x0001f800)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000008
            }
        }
        namespace eval RSSI_THR_TO_FORCE_FFE {
            namespace export SHIFT
            proc SHIFT {} {
                return 17
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 8
            }
            namespace export MASK
            proc MASK {} {
                return 0x01fe0000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x01fe0000) >> 17}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 17) & 0x01fe0000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x01fe0000) | (($field_val << 17) & 0x01fe0000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x01fe0000) | (($field_val << 17) & 0x01fe0000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 17) & ~0x01fe0000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x000000ab
            }
        }
        namespace eval DELAY_TOTAL_PWR_FOR_BLOCKER_DET {
            namespace export SHIFT
            proc SHIFT {} {
                return 25
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 2
            }
            namespace export MASK
            proc MASK {} {
                return 0x06000000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x06000000) >> 25}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 25) & 0x06000000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x06000000) | (($field_val << 25) & 0x06000000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x06000000) | (($field_val << 25) & 0x06000000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 25) & ~0x06000000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000002
            }
        }
        namespace eval TWOMEG_DELAY_TOTAL_PWR_FOR_BLOCKER_DET {
            namespace export SHIFT
            proc SHIFT {} {
                return 27
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 2
            }
            namespace export MASK
            proc MASK {} {
                return 0x18000000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x18000000) >> 27}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 27) & 0x18000000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x18000000) | (($field_val << 27) & 0x18000000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x18000000) | (($field_val << 27) & 0x18000000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 27) & ~0x18000000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000002
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x1556411b
        }
    }
    namespace export AGCPWR2_ALT
    proc AGCPWR2_ALT { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x78 }]
    }
    namespace eval AGCPWR2_ALT {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x78 }]
        }
        namespace eval MEAS_WIN {
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
                return 0x00000003
            }
        }
        namespace eval DET_STEP {
            namespace export SHIFT
            proc SHIFT {} {
                return 2
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 5
            }
            namespace export MASK
            proc MASK {} {
                return 0x0000007c
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x0000007c) >> 2}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 2) & 0x0000007c}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x0000007c) | (($field_val << 2) & 0x0000007c)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x0000007c) | (($field_val << 2) & 0x0000007c)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 2) & ~0x0000007c)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000006
            }
        }
        namespace eval DET_STEP_DELTA {
            namespace export SHIFT
            proc SHIFT {} {
                return 7
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 4
            }
            namespace export MASK
            proc MASK {} {
                return 0x00000780
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00000780) >> 7}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 7) & 0x00000780}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00000780) | (($field_val << 7) & 0x00000780)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00000780) | (($field_val << 7) & 0x00000780)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 7) & ~0x00000780)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000002
            }
        }
        namespace eval BASELINE_BLK_PWR_OFFSET {
            namespace export SHIFT
            proc SHIFT {} {
                return 11
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 6
            }
            namespace export MASK
            proc MASK {} {
                return 0x0001f800
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x0001f800) >> 11}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 11) & 0x0001f800}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x0001f800) | (($field_val << 11) & 0x0001f800)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x0001f800) | (($field_val << 11) & 0x0001f800)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 11) & ~0x0001f800)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000008
            }
        }
        namespace eval RSSI_THR_TO_FORCE_FFE {
            namespace export SHIFT
            proc SHIFT {} {
                return 17
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 8
            }
            namespace export MASK
            proc MASK {} {
                return 0x01fe0000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x01fe0000) >> 17}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 17) & 0x01fe0000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x01fe0000) | (($field_val << 17) & 0x01fe0000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x01fe0000) | (($field_val << 17) & 0x01fe0000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 17) & ~0x01fe0000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x000000ab
            }
        }
        namespace eval DELAY_TOTAL_PWR_FOR_BLOCKER_DET {
            namespace export SHIFT
            proc SHIFT {} {
                return 25
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 2
            }
            namespace export MASK
            proc MASK {} {
                return 0x06000000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x06000000) >> 25}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 25) & 0x06000000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x06000000) | (($field_val << 25) & 0x06000000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x06000000) | (($field_val << 25) & 0x06000000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 25) & ~0x06000000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000002
            }
        }
        namespace eval TWOMEG_DELAY_TOTAL_PWR_FOR_BLOCKER_DET {
            namespace export SHIFT
            proc SHIFT {} {
                return 27
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 2
            }
            namespace export MASK
            proc MASK {} {
                return 0x18000000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x18000000) >> 27}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 27) & 0x18000000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x18000000) | (($field_val << 27) & 0x18000000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x18000000) | (($field_val << 27) & 0x18000000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 27) & ~0x18000000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000002
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x1556411b
        }
    }
    namespace export AGCTIME
    proc AGCTIME { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x7c }]
    }
    namespace eval AGCTIME {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x7c }]
        }
        namespace eval GAIN_SETTLE {
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
                return 0x0000001c
            }
        }
        namespace eval FILT_SETTLE {
            namespace export SHIFT
            proc SHIFT {} {
                return 25
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 7
            }
            namespace export MASK
            proc MASK {} {
                return 0xfe000000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0xfe000000) >> 25}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 25) & 0xfe000000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0xfe000000) | (($field_val << 25) & 0xfe000000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0xfe000000) | (($field_val << 25) & 0xfe000000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 25) & ~0xfe000000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x0000001c
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x3800001c
        }
    }
    namespace export AGCTIME_ALT
    proc AGCTIME_ALT { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x80 }]
    }
    namespace eval AGCTIME_ALT {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x80 }]
        }
        namespace eval GAIN_SETTLE {
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
                return 0x0000001c
            }
        }
        namespace eval FILT_SETTLE {
            namespace export SHIFT
            proc SHIFT {} {
                return 25
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 7
            }
            namespace export MASK
            proc MASK {} {
                return 0xfe000000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0xfe000000) >> 25}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 25) & 0xfe000000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0xfe000000) | (($field_val << 25) & 0xfe000000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0xfe000000) | (($field_val << 25) & 0xfe000000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 25) & ~0xfe000000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x0000001c
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x3800001c
        }
    }
    namespace export TWOMEG_AGCTIME
    proc TWOMEG_AGCTIME { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x84 }]
    }
    namespace eval TWOMEG_AGCTIME {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x84 }]
        }
        namespace eval GAIN_SETTLE {
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
        namespace eval FILT_SETTLE {
            namespace export SHIFT
            proc SHIFT {} {
                return 25
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 7
            }
            namespace export MASK
            proc MASK {} {
                return 0xfe000000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0xfe000000) >> 25}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 25) & 0xfe000000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0xfe000000) | (($field_val << 25) & 0xfe000000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0xfe000000) | (($field_val << 25) & 0xfe000000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 25) & ~0xfe000000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000010
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x20000010
        }
    }
    namespace export TWOMEG_AGCTIME_ALT
    proc TWOMEG_AGCTIME_ALT { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x88 }]
    }
    namespace eval TWOMEG_AGCTIME_ALT {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x88 }]
        }
        namespace eval GAIN_SETTLE {
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
        namespace eval FILT_SETTLE {
            namespace export SHIFT
            proc SHIFT {} {
                return 25
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 7
            }
            namespace export MASK
            proc MASK {} {
                return 0xfe000000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0xfe000000) >> 25}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 25) & 0xfe000000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0xfe000000) | (($field_val << 25) & 0xfe000000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0xfe000000) | (($field_val << 25) & 0xfe000000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 25) & ~0xfe000000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000010
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x20000010
        }
    }
    namespace export AGCTIME2
    proc AGCTIME2 { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x8c }]
    }
    namespace eval AGCTIME2 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x8c }]
        }
        namespace eval RX_EN_TO_SEARCH {
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
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 0) & 0x000007ff}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x000007ff) | (($field_val << 0) & 0x000007ff)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x000007ff) | (($field_val << 0) & 0x000007ff)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 0) & ~0x000007ff)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000326
            }
        }
        namespace eval LNA_PROTECT_SETTLE {
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
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x0007f800) | (($field_val << 11) & 0x0007f800)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 11) & ~0x0007f800)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000020
            }
        }
        namespace eval RESET_FILT_DELAY {
            namespace export SHIFT
            proc SHIFT {} {
                return 19
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 6
            }
            namespace export MASK
            proc MASK {} {
                return 0x01f80000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x01f80000) >> 19}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 19) & 0x01f80000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x01f80000) | (($field_val << 19) & 0x01f80000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x01f80000) | (($field_val << 19) & 0x01f80000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 19) & ~0x01f80000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000010
            }
        }
        namespace eval TWOMEG_RESET_FILT_DELAY {
            namespace export SHIFT
            proc SHIFT {} {
                return 25
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 6
            }
            namespace export MASK
            proc MASK {} {
                return 0x7e000000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x7e000000) >> 25}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 25) & 0x7e000000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x7e000000) | (($field_val << 25) & 0x7e000000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x7e000000) | (($field_val << 25) & 0x7e000000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 25) & ~0x7e000000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x0000000a
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x14810326
        }
    }
    namespace export AGCTIME2_ALT
    proc AGCTIME2_ALT { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x90 }]
    }
    namespace eval AGCTIME2_ALT {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x90 }]
        }
        namespace eval RX_EN_TO_SEARCH {
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
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 0) & 0x000007ff}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x000007ff) | (($field_val << 0) & 0x000007ff)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x000007ff) | (($field_val << 0) & 0x000007ff)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 0) & ~0x000007ff)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000326
            }
        }
        namespace eval LNA_PROTECT_SETTLE {
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
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x0007f800) | (($field_val << 11) & 0x0007f800)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 11) & ~0x0007f800)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000020
            }
        }
        namespace eval RESET_FILT_DELAY {
            namespace export SHIFT
            proc SHIFT {} {
                return 19
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 6
            }
            namespace export MASK
            proc MASK {} {
                return 0x01f80000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x01f80000) >> 19}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 19) & 0x01f80000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x01f80000) | (($field_val << 19) & 0x01f80000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x01f80000) | (($field_val << 19) & 0x01f80000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 19) & ~0x01f80000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000010
            }
        }
        namespace eval TWOMEG_RESET_FILT_DELAY {
            namespace export SHIFT
            proc SHIFT {} {
                return 25
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 6
            }
            namespace export MASK
            proc MASK {} {
                return 0x7e000000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x7e000000) >> 25}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 25) & 0x7e000000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x7e000000) | (($field_val << 25) & 0x7e000000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x7e000000) | (($field_val << 25) & 0x7e000000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 25) & ~0x7e000000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x0000000a
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x14810326
        }
    }
    namespace export AGCCNTL
    proc AGCCNTL { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x94 }]
    }
    namespace eval AGCCNTL {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x94 }]
        }
        namespace eval ENABLE_RFIN_PEAKDET {
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
        namespace eval ENABLE_TIA_PEAKDET {
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
        namespace eval MAX {
            namespace export SHIFT
            proc SHIFT {} {
                return 2
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 7
            }
            namespace export MASK
            proc MASK {} {
                return 0x000001fc
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x000001fc) >> 2}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 2) & 0x000001fc}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x000001fc) | (($field_val << 2) & 0x000001fc)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x000001fc) | (($field_val << 2) & 0x000001fc)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 2) & ~0x000001fc)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x0000004c
            }
        }
        namespace eval FORCE_RXGAIN {
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
        namespace eval FORCED_RXGAIN_VALUE {
            namespace export SHIFT
            proc SHIFT {} {
                return 10
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 7
            }
            namespace export MASK
            proc MASK {} {
                return 0x0001fc00
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x0001fc00) >> 10}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 10) & 0x0001fc00}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x0001fc00) | (($field_val << 10) & 0x0001fc00)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x0001fc00) | (($field_val << 10) & 0x0001fc00)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 10) & ~0x0001fc00)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000005
            }
        }
        namespace eval ALLOW_SAT_AFTER_PEAK {
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
                return 0x00000001
            }
        }
        namespace eval ALLOW_SAT_AFTER_SAT {
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
                return 0x00000001
            }
        }
        namespace eval BYPASS_RXFIR {
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
        namespace eval TWOMEG_BYPASS_RXFIR {
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
        namespace eval MIN_RXGAIN_INCREASE {
            namespace export SHIFT
            proc SHIFT {} {
                return 21
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 4
            }
            namespace export MASK
            proc MASK {} {
                return 0x01e00000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x01e00000) >> 21}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 21) & 0x01e00000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x01e00000) | (($field_val << 21) & 0x01e00000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x01e00000) | (($field_val << 21) & 0x01e00000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 21) & ~0x01e00000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000003
            }
        }
        namespace eval MIN_RXGAIN_DECREASE {
            namespace export SHIFT
            proc SHIFT {} {
                return 25
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 4
            }
            namespace export MASK
            proc MASK {} {
                return 0x1e000000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x1e000000) >> 25}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 25) & 0x1e000000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x1e000000) | (($field_val << 25) & 0x1e000000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x1e000000) | (($field_val << 25) & 0x1e000000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 25) & ~0x1e000000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000006
            }
        }
        namespace eval ENABLE_IQCORR {
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
        namespace eval TWOMEG_ENABLE_IQCORR {
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
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x0c661533
        }
    }
    namespace export AGCCNTL_ALT
    proc AGCCNTL_ALT { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x98 }]
    }
    namespace eval AGCCNTL_ALT {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x98 }]
        }
        namespace eval ENABLE_RFIN_PEAKDET {
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
        namespace eval ENABLE_TIA_PEAKDET {
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
        namespace eval MAX {
            namespace export SHIFT
            proc SHIFT {} {
                return 2
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 7
            }
            namespace export MASK
            proc MASK {} {
                return 0x000001fc
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x000001fc) >> 2}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 2) & 0x000001fc}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x000001fc) | (($field_val << 2) & 0x000001fc)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x000001fc) | (($field_val << 2) & 0x000001fc)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 2) & ~0x000001fc)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x0000004c
            }
        }
        namespace eval FORCE_RXGAIN {
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
        namespace eval FORCED_RXGAIN_VALUE {
            namespace export SHIFT
            proc SHIFT {} {
                return 10
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 7
            }
            namespace export MASK
            proc MASK {} {
                return 0x0001fc00
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x0001fc00) >> 10}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 10) & 0x0001fc00}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x0001fc00) | (($field_val << 10) & 0x0001fc00)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x0001fc00) | (($field_val << 10) & 0x0001fc00)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 10) & ~0x0001fc00)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000005
            }
        }
        namespace eval ALLOW_SAT_AFTER_PEAK {
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
                return 0x00000001
            }
        }
        namespace eval ALLOW_SAT_AFTER_SAT {
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
                return 0x00000001
            }
        }
        namespace eval BYPASS_RXFIR {
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
        namespace eval TWOMEG_BYPASS_RXFIR {
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
        namespace eval MIN_RXGAIN_INCREASE {
            namespace export SHIFT
            proc SHIFT {} {
                return 21
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 4
            }
            namespace export MASK
            proc MASK {} {
                return 0x01e00000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x01e00000) >> 21}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 21) & 0x01e00000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x01e00000) | (($field_val << 21) & 0x01e00000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x01e00000) | (($field_val << 21) & 0x01e00000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 21) & ~0x01e00000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000003
            }
        }
        namespace eval MIN_RXGAIN_DECREASE {
            namespace export SHIFT
            proc SHIFT {} {
                return 25
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 4
            }
            namespace export MASK
            proc MASK {} {
                return 0x1e000000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x1e000000) >> 25}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 25) & 0x1e000000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x1e000000) | (($field_val << 25) & 0x1e000000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x1e000000) | (($field_val << 25) & 0x1e000000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 25) & ~0x1e000000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000006
            }
        }
        namespace eval ENABLE_IQCORR {
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
        namespace eval TWOMEG_ENABLE_IQCORR {
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
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x0c661533
        }
    }
    namespace export AGCPD
    proc AGCPD { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x9c }]
    }
    namespace eval AGCPD {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x9c }]
        }
        namespace eval CHECK_WIN {
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
                return 0x00000008
            }
        }
        namespace eval RFIN_PEAK_THR_HIGH {
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
        namespace eval RFIN_PEAK_THR_LOW {
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
                return 0x00000002
            }
        }
        namespace eval TIA_PEAK_THR_HIGH {
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
                return 0x00000002
            }
        }
        namespace eval TIA_PEAK_THR_LOW {
            namespace export SHIFT
            proc SHIFT {} {
                return 16
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 4
            }
            namespace export MASK
            proc MASK {} {
                return 0x000f0000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x000f0000) >> 16}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 16) & 0x000f0000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x000f0000) | (($field_val << 16) & 0x000f0000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x000f0000) | (($field_val << 16) & 0x000f0000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 16) & ~0x000f0000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000002
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x00022268
        }
    }
    namespace export AGCPD_ALT
    proc AGCPD_ALT { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0xa0 }]
    }
    namespace eval AGCPD_ALT {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0xa0 }]
        }
        namespace eval CHECK_WIN {
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
                return 0x00000008
            }
        }
        namespace eval RFIN_PEAK_THR_HIGH {
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
        namespace eval RFIN_PEAK_THR_LOW {
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
                return 0x00000002
            }
        }
        namespace eval TIA_PEAK_THR_HIGH {
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
                return 0x00000002
            }
        }
        namespace eval TIA_PEAK_THR_LOW {
            namespace export SHIFT
            proc SHIFT {} {
                return 16
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 4
            }
            namespace export MASK
            proc MASK {} {
                return 0x000f0000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x000f0000) >> 16}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 16) & 0x000f0000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x000f0000) | (($field_val << 16) & 0x000f0000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x000f0000) | (($field_val << 16) & 0x000f0000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 16) & ~0x000f0000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000002
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x00022268
        }
    }
    namespace export AGCDET
    proc AGCDET { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0xa4 }]
    }
    namespace eval AGCDET {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0xa4 }]
        }
        namespace eval SAT_DELAY {
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
                return 0x00000000
            }
        }
        namespace eval TWOMEG_SAT_DELAY {
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
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x000003e0) | (($field_val << 5) & 0x000003e0)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 5) & ~0x000003e0)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval TIAPD_DELAY {
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
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00007c00) | (($field_val << 10) & 0x00007c00)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 10) & ~0x00007c00)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval TWOMEG_TIAPD_DELAY {
            namespace export SHIFT
            proc SHIFT {} {
                return 15
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 5
            }
            namespace export MASK
            proc MASK {} {
                return 0x000f8000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x000f8000) >> 15}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 15) & 0x000f8000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x000f8000) | (($field_val << 15) & 0x000f8000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x000f8000) | (($field_val << 15) & 0x000f8000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 15) & ~0x000f8000)}]
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
    namespace export AGCDET_ALT
    proc AGCDET_ALT { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0xa8 }]
    }
    namespace eval AGCDET_ALT {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0xa8 }]
        }
        namespace eval SAT_DELAY {
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
                return 0x00000000
            }
        }
        namespace eval TWOMEG_SAT_DELAY {
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
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x000003e0) | (($field_val << 5) & 0x000003e0)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 5) & ~0x000003e0)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval TIAPD_DELAY {
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
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00007c00) | (($field_val << 10) & 0x00007c00)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 10) & ~0x00007c00)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval TWOMEG_TIAPD_DELAY {
            namespace export SHIFT
            proc SHIFT {} {
                return 15
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 5
            }
            namespace export MASK
            proc MASK {} {
                return 0x000f8000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x000f8000) >> 15}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 15) & 0x000f8000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x000f8000) | (($field_val << 15) & 0x000f8000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x000f8000) | (($field_val << 15) & 0x000f8000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 15) & ~0x000f8000)}]
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
    namespace export AGCOFFSET
    proc AGCOFFSET { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0xac }]
    }
    namespace eval AGCOFFSET {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0xac }]
        }
        namespace eval ADC_QUICK_DROP {
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
                return 0x00000002
            }
        }
        namespace eval TWOMEG_ADC_QUICK_DROP {
            namespace export SHIFT
            proc SHIFT {} {
                return 6
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 6
            }
            namespace export MASK
            proc MASK {} {
                return 0x00000fc0
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00000fc0) >> 6}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 6) & 0x00000fc0}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00000fc0) | (($field_val << 6) & 0x00000fc0)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00000fc0) | (($field_val << 6) & 0x00000fc0)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 6) & ~0x00000fc0)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000002
            }
        }
        namespace eval SYDNEY_ADC_QUICK_DROP {
            namespace export SHIFT
            proc SHIFT {} {
                return 12
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 6
            }
            namespace export MASK
            proc MASK {} {
                return 0x0003f000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x0003f000) >> 12}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 12) & 0x0003f000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x0003f000) | (($field_val << 12) & 0x0003f000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x0003f000) | (($field_val << 12) & 0x0003f000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 12) & ~0x0003f000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x0000003f
            }
        }
        namespace eval SYDNEY_TWOMEG_ADC_QUICK_DROP {
            namespace export SHIFT
            proc SHIFT {} {
                return 18
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 6
            }
            namespace export MASK
            proc MASK {} {
                return 0x00fc0000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00fc0000) >> 18}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 18) & 0x00fc0000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00fc0000) | (($field_val << 18) & 0x00fc0000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00fc0000) | (($field_val << 18) & 0x00fc0000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 18) & ~0x00fc0000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x0000003f
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x00fff082
        }
    }
    namespace export AGCOFFSET_ALT
    proc AGCOFFSET_ALT { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0xb0 }]
    }
    namespace eval AGCOFFSET_ALT {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0xb0 }]
        }
        namespace eval ADC_QUICK_DROP {
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
                return 0x00000002
            }
        }
        namespace eval TWOMEG_ADC_QUICK_DROP {
            namespace export SHIFT
            proc SHIFT {} {
                return 6
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 6
            }
            namespace export MASK
            proc MASK {} {
                return 0x00000fc0
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00000fc0) >> 6}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 6) & 0x00000fc0}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00000fc0) | (($field_val << 6) & 0x00000fc0)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00000fc0) | (($field_val << 6) & 0x00000fc0)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 6) & ~0x00000fc0)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000002
            }
        }
        namespace eval SYDNEY_ADC_QUICK_DROP {
            namespace export SHIFT
            proc SHIFT {} {
                return 12
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 6
            }
            namespace export MASK
            proc MASK {} {
                return 0x0003f000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x0003f000) >> 12}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 12) & 0x0003f000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x0003f000) | (($field_val << 12) & 0x0003f000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x0003f000) | (($field_val << 12) & 0x0003f000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 12) & ~0x0003f000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x0000003f
            }
        }
        namespace eval SYDNEY_TWOMEG_ADC_QUICK_DROP {
            namespace export SHIFT
            proc SHIFT {} {
                return 18
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 6
            }
            namespace export MASK
            proc MASK {} {
                return 0x00fc0000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00fc0000) >> 18}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 18) & 0x00fc0000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00fc0000) | (($field_val << 18) & 0x00fc0000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00fc0000) | (($field_val << 18) & 0x00fc0000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 18) & ~0x00fc0000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x0000003f
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x00fff082
        }
    }
    namespace export SYNCH
    proc SYNCH { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0xb4 }]
    }
    namespace eval SYNCH {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0xb4 }]
        }
        namespace eval PG {
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
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x0000000c) | (($field_val << 2) & 0x0000000c)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 2) & ~0x0000000c)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000001
            }
        }
        namespace eval PH_REG_THR {
            namespace export SHIFT
            proc SHIFT {} {
                return 4
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 3
            }
            namespace export MASK
            proc MASK {} {
                return 0x00000070
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00000070) >> 4}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 4) & 0x00000070}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00000070) | (($field_val << 4) & 0x00000070)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00000070) | (($field_val << 4) & 0x00000070)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 4) & ~0x00000070)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000001
            }
        }
        namespace eval PH_REG_THR2 {
            namespace export SHIFT
            proc SHIFT {} {
                return 7
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 3
            }
            namespace export MASK
            proc MASK {} {
                return 0x00000380
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00000380) >> 7}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 7) & 0x00000380}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00000380) | (($field_val << 7) & 0x00000380)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00000380) | (($field_val << 7) & 0x00000380)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 7) & ~0x00000380)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000003
            }
        }
        namespace eval PH_REG_THR3 {
            namespace export SHIFT
            proc SHIFT {} {
                return 10
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 3
            }
            namespace export MASK
            proc MASK {} {
                return 0x00001c00
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00001c00) >> 10}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 10) & 0x00001c00}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00001c00) | (($field_val << 10) & 0x00001c00)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00001c00) | (($field_val << 10) & 0x00001c00)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 10) & ~0x00001c00)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000004
            }
        }
        namespace eval ENABLE_TIME_TRACK {
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
                return 0x00000001
            }
        }
        namespace eval FREQ_FORCE_INITIAL {
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
        namespace eval FREQ_FORCED_VALUE {
            namespace export SHIFT
            proc SHIFT {} {
                return 15
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 13
            }
            namespace export MASK
            proc MASK {} {
                return 0x0fff8000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x0fff8000) >> 15}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 15) & 0x0fff8000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x0fff8000) | (($field_val << 15) & 0x0fff8000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x0fff8000) | (($field_val << 15) & 0x0fff8000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 15) & ~0x0fff8000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval RST_FREQ_NO_GAIN_CHANGE_PWRSTEP {
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
        namespace eval RST_FREQ_NO_GAIN_CHANGE_RFIN {
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
        namespace eval RST_FREQ_NO_GAIN_CHANGE_TIA {
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
                return 0x00000001
            }
        }
        namespace eval RST_FREQ_NO_GAIN_CHANGE_SAT {
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
                return 0x00000001
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0xf0003194
        }
    }
    namespace export SYNCH_ALT
    proc SYNCH_ALT { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0xb8 }]
    }
    namespace eval SYNCH_ALT {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0xb8 }]
        }
        namespace eval PG {
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
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x0000000c) | (($field_val << 2) & 0x0000000c)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 2) & ~0x0000000c)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000001
            }
        }
        namespace eval PH_REG_THR {
            namespace export SHIFT
            proc SHIFT {} {
                return 4
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 3
            }
            namespace export MASK
            proc MASK {} {
                return 0x00000070
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00000070) >> 4}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 4) & 0x00000070}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00000070) | (($field_val << 4) & 0x00000070)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00000070) | (($field_val << 4) & 0x00000070)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 4) & ~0x00000070)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000001
            }
        }
        namespace eval PH_REG_THR2 {
            namespace export SHIFT
            proc SHIFT {} {
                return 7
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 3
            }
            namespace export MASK
            proc MASK {} {
                return 0x00000380
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00000380) >> 7}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 7) & 0x00000380}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00000380) | (($field_val << 7) & 0x00000380)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00000380) | (($field_val << 7) & 0x00000380)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 7) & ~0x00000380)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000003
            }
        }
        namespace eval PH_REG_THR3 {
            namespace export SHIFT
            proc SHIFT {} {
                return 10
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 3
            }
            namespace export MASK
            proc MASK {} {
                return 0x00001c00
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00001c00) >> 10}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 10) & 0x00001c00}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00001c00) | (($field_val << 10) & 0x00001c00)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00001c00) | (($field_val << 10) & 0x00001c00)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 10) & ~0x00001c00)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000004
            }
        }
        namespace eval ENABLE_TIME_TRACK {
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
                return 0x00000001
            }
        }
        namespace eval FREQ_FORCE_INITIAL {
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
        namespace eval FREQ_FORCED_VALUE {
            namespace export SHIFT
            proc SHIFT {} {
                return 15
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 13
            }
            namespace export MASK
            proc MASK {} {
                return 0x0fff8000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x0fff8000) >> 15}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 15) & 0x0fff8000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x0fff8000) | (($field_val << 15) & 0x0fff8000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x0fff8000) | (($field_val << 15) & 0x0fff8000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 15) & ~0x0fff8000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval RST_FREQ_NO_GAIN_CHANGE_PWRSTEP {
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
        namespace eval RST_FREQ_NO_GAIN_CHANGE_RFIN {
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
        namespace eval RST_FREQ_NO_GAIN_CHANGE_TIA {
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
                return 0x00000001
            }
        }
        namespace eval RST_FREQ_NO_GAIN_CHANGE_SAT {
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
                return 0x00000001
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0xf0003194
        }
    }
    namespace export TIMETRACK
    proc TIMETRACK { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0xbc }]
    }
    namespace eval TIMETRACK {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0xbc }]
        }
        namespace eval BYTE_COUNT {
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
                return 0x00000001
            }
        }
        namespace eval BYTE_COUNT2 {
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
                return 0x00000002
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x00000201
        }
    }
    namespace export TIMESYNC
    proc TIMESYNC { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0xc0 }]
    }
    namespace eval TIMESYNC {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0xc0 }]
        }
        namespace eval RSSI_THR {
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
                return 0x000000a8
            }
        }
        namespace eval CORR_TMG_ADJ {
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
                return 0x00000000
            }
        }
        namespace eval TWOMEG_CORR_TMG_ADJ {
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
                return 0x00000000
            }
        }
        namespace eval CODED_MIN_THR {
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
                return 0x00000096
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x960000a8
        }
    }
    namespace export TIMESYNC_ALT
    proc TIMESYNC_ALT { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0xc4 }]
    }
    namespace eval TIMESYNC_ALT {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0xc4 }]
        }
        namespace eval RSSI_THR {
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
                return 0x000000a8
            }
        }
        namespace eval CORR_TMG_ADJ {
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
                return 0x00000000
            }
        }
        namespace eval TWOMEG_CORR_TMG_ADJ {
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
                return 0x00000000
            }
        }
        namespace eval CODED_MIN_THR {
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
                return 0x00000096
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x960000a8
        }
    }
    namespace export SYNCDEMOD
    proc SYNCDEMOD { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0xc8 }]
    }
    namespace eval SYNCDEMOD {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0xc8 }]
        }
        namespace eval CODED_FIND_TWO_PEAKS {
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
        namespace eval FREQWIN1 {
            namespace export SHIFT
            proc SHIFT {} {
                return 1
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 3
            }
            namespace export MASK
            proc MASK {} {
                return 0x0000000e
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x0000000e) >> 1}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 1) & 0x0000000e}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x0000000e) | (($field_val << 1) & 0x0000000e)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x0000000e) | (($field_val << 1) & 0x0000000e)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 1) & ~0x0000000e)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000002
            }
        }
        namespace eval FREQWIN2 {
            namespace export SHIFT
            proc SHIFT {} {
                return 4
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 3
            }
            namespace export MASK
            proc MASK {} {
                return 0x00000070
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00000070) >> 4}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 4) & 0x00000070}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00000070) | (($field_val << 4) & 0x00000070)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00000070) | (($field_val << 4) & 0x00000070)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 4) & ~0x00000070)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000001
            }
        }
        namespace eval FREQWIN3 {
            namespace export SHIFT
            proc SHIFT {} {
                return 7
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 3
            }
            namespace export MASK
            proc MASK {} {
                return 0x00000380
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00000380) >> 7}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 7) & 0x00000380}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00000380) | (($field_val << 7) & 0x00000380)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00000380) | (($field_val << 7) & 0x00000380)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 7) & ~0x00000380)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000004
            }
        }
        namespace eval TWOMEG_FREQWIN1 {
            namespace export SHIFT
            proc SHIFT {} {
                return 10
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 3
            }
            namespace export MASK
            proc MASK {} {
                return 0x00001c00
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00001c00) >> 10}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 10) & 0x00001c00}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00001c00) | (($field_val << 10) & 0x00001c00)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00001c00) | (($field_val << 10) & 0x00001c00)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 10) & ~0x00001c00)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000002
            }
        }
        namespace eval TWOMEG_FREQWIN2 {
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
        namespace eval TWOMEG_FREQWIN3 {
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
                return 0x00000004
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x00042a15
        }
    }
    namespace export SYNCDEMOD_ALT
    proc SYNCDEMOD_ALT { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0xcc }]
    }
    namespace eval SYNCDEMOD_ALT {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0xcc }]
        }
        namespace eval CODED_FIND_TWO_PEAKS {
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
        namespace eval FREQWIN1 {
            namespace export SHIFT
            proc SHIFT {} {
                return 1
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 3
            }
            namespace export MASK
            proc MASK {} {
                return 0x0000000e
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x0000000e) >> 1}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 1) & 0x0000000e}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x0000000e) | (($field_val << 1) & 0x0000000e)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x0000000e) | (($field_val << 1) & 0x0000000e)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 1) & ~0x0000000e)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000002
            }
        }
        namespace eval FREQWIN2 {
            namespace export SHIFT
            proc SHIFT {} {
                return 4
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 3
            }
            namespace export MASK
            proc MASK {} {
                return 0x00000070
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00000070) >> 4}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 4) & 0x00000070}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00000070) | (($field_val << 4) & 0x00000070)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00000070) | (($field_val << 4) & 0x00000070)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 4) & ~0x00000070)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000001
            }
        }
        namespace eval FREQWIN3 {
            namespace export SHIFT
            proc SHIFT {} {
                return 7
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 3
            }
            namespace export MASK
            proc MASK {} {
                return 0x00000380
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00000380) >> 7}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 7) & 0x00000380}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00000380) | (($field_val << 7) & 0x00000380)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00000380) | (($field_val << 7) & 0x00000380)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 7) & ~0x00000380)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000004
            }
        }
        namespace eval TWOMEG_FREQWIN1 {
            namespace export SHIFT
            proc SHIFT {} {
                return 10
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 3
            }
            namespace export MASK
            proc MASK {} {
                return 0x00001c00
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00001c00) >> 10}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 10) & 0x00001c00}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00001c00) | (($field_val << 10) & 0x00001c00)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00001c00) | (($field_val << 10) & 0x00001c00)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 10) & ~0x00001c00)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000002
            }
        }
        namespace eval TWOMEG_FREQWIN2 {
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
        namespace eval TWOMEG_FREQWIN3 {
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
                return 0x00000004
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x00042a15
        }
    }
    namespace export RESETINITCFO
    proc RESETINITCFO { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0xd0 }]
    }
    namespace eval RESETINITCFO {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0xd0 }]
        }
        namespace eval EN {
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
        namespace eval RUNLEN_UPDT_THR {
            namespace export SHIFT
            proc SHIFT {} {
                return 1
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 6
            }
            namespace export MASK
            proc MASK {} {
                return 0x0000007e
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x0000007e) >> 1}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 1) & 0x0000007e}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x0000007e) | (($field_val << 1) & 0x0000007e)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x0000007e) | (($field_val << 1) & 0x0000007e)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 1) & ~0x0000007e)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000016
            }
        }
        namespace eval RUNLEN_THR_TO_RESET_CFO {
            namespace export SHIFT
            proc SHIFT {} {
                return 7
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 6
            }
            namespace export MASK
            proc MASK {} {
                return 0x00001f80
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00001f80) >> 7}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 7) & 0x00001f80}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00001f80) | (($field_val << 7) & 0x00001f80)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00001f80) | (($field_val << 7) & 0x00001f80)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 7) & ~0x00001f80)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x0000000f
            }
        }
        namespace eval USE_TWOSAMPLES_TO_UPDT_RUNLEN {
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
                return 0x00000001
            }
        }
        namespace eval RESET_RUNLEN_ON_GAINCHG_PWRSTEP_ONLY {
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
        namespace eval TWOMEG_EN {
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
        namespace eval TWOMEG_RUNLEN_UPDT_THR {
            namespace export SHIFT
            proc SHIFT {} {
                return 17
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 6
            }
            namespace export MASK
            proc MASK {} {
                return 0x007e0000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x007e0000) >> 17}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 17) & 0x007e0000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x007e0000) | (($field_val << 17) & 0x007e0000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x007e0000) | (($field_val << 17) & 0x007e0000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 17) & ~0x007e0000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000016
            }
        }
        namespace eval TWOMEG_RUNLEN_THR_TO_RESET_CFO {
            namespace export SHIFT
            proc SHIFT {} {
                return 23
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 6
            }
            namespace export MASK
            proc MASK {} {
                return 0x1f800000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x1f800000) >> 23}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 23) & 0x1f800000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x1f800000) | (($field_val << 23) & 0x1f800000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x1f800000) | (($field_val << 23) & 0x1f800000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 23) & ~0x1f800000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x0000000f
            }
        }
        namespace eval TWOMEG_USE_TWOSAMPLES_TO_UPDT_RUNLEN {
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
        namespace eval TWOMEG_RESET_RUNLEN_ON_GAINCHG_PWRSTEP_ONLY {
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
                return 0x00000001
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x67ac67ac
        }
    }
    namespace export RESETINITCFO_ALT
    proc RESETINITCFO_ALT { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0xd4 }]
    }
    namespace eval RESETINITCFO_ALT {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0xd4 }]
        }
        namespace eval EN {
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
        namespace eval RUNLEN_UPDT_THR {
            namespace export SHIFT
            proc SHIFT {} {
                return 1
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 6
            }
            namespace export MASK
            proc MASK {} {
                return 0x0000007e
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x0000007e) >> 1}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 1) & 0x0000007e}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x0000007e) | (($field_val << 1) & 0x0000007e)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x0000007e) | (($field_val << 1) & 0x0000007e)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 1) & ~0x0000007e)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000016
            }
        }
        namespace eval RUNLEN_THR_TO_RESET_CFO {
            namespace export SHIFT
            proc SHIFT {} {
                return 7
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 6
            }
            namespace export MASK
            proc MASK {} {
                return 0x00001f80
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00001f80) >> 7}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 7) & 0x00001f80}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00001f80) | (($field_val << 7) & 0x00001f80)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00001f80) | (($field_val << 7) & 0x00001f80)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 7) & ~0x00001f80)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x0000000f
            }
        }
        namespace eval USE_TWOSAMPLES_TO_UPDT_RUNLEN {
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
                return 0x00000001
            }
        }
        namespace eval RESET_RUNLEN_ON_GAINCHG_PWRSTEP_ONLY {
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
        namespace eval TWOMEG_EN {
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
                return 0x00000001
            }
        }
        namespace eval TWOMEG_RUNLEN_UPDT_THR {
            namespace export SHIFT
            proc SHIFT {} {
                return 17
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 6
            }
            namespace export MASK
            proc MASK {} {
                return 0x007e0000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x007e0000) >> 17}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 17) & 0x007e0000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x007e0000) | (($field_val << 17) & 0x007e0000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x007e0000) | (($field_val << 17) & 0x007e0000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 17) & ~0x007e0000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000016
            }
        }
        namespace eval TWOMEG_RUNLEN_THR_TO_RESET_CFO {
            namespace export SHIFT
            proc SHIFT {} {
                return 23
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 6
            }
            namespace export MASK
            proc MASK {} {
                return 0x1f800000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x1f800000) >> 23}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 23) & 0x1f800000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x1f800000) | (($field_val << 23) & 0x1f800000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x1f800000) | (($field_val << 23) & 0x1f800000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 23) & ~0x1f800000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x0000000f
            }
        }
        namespace eval TWOMEG_USE_TWOSAMPLES_TO_UPDT_RUNLEN {
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
        namespace eval TWOMEG_RESET_RUNLEN_ON_GAINCHG_PWRSTEP_ONLY {
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
                return 0x00000001
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x67ad67ad
        }
    }
    namespace export INTMFREQ
    proc INTMFREQ { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0xd8 }]
    }
    namespace eval INTMFREQ {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0xd8 }]
        }
        namespace eval ENABLE_INTMFREQ {
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
        namespace eval TWOMEG_ENABLE_INTMFREQ {
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
        namespace eval ALPHA1 {
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
                return 0x00000007
            }
        }
        namespace eval ALPHA2 {
            namespace export SHIFT
            proc SHIFT {} {
                return 6
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 4
            }
            namespace export MASK
            proc MASK {} {
                return 0x000003c0
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x000003c0) >> 6}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 6) & 0x000003c0}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x000003c0) | (($field_val << 6) & 0x000003c0)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x000003c0) | (($field_val << 6) & 0x000003c0)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 6) & ~0x000003c0)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000008
            }
        }
        namespace eval ALPHA3 {
            namespace export SHIFT
            proc SHIFT {} {
                return 10
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 4
            }
            namespace export MASK
            proc MASK {} {
                return 0x00003c00
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00003c00) >> 10}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 10) & 0x00003c00}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00003c00) | (($field_val << 10) & 0x00003c00)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00003c00) | (($field_val << 10) & 0x00003c00)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 10) & ~0x00003c00)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000009
            }
        }
        namespace eval ALPHA_COUNT1 {
            namespace export SHIFT
            proc SHIFT {} {
                return 14
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 6
            }
            namespace export MASK
            proc MASK {} {
                return 0x000fc000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x000fc000) >> 14}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 14) & 0x000fc000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x000fc000) | (($field_val << 14) & 0x000fc000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x000fc000) | (($field_val << 14) & 0x000fc000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 14) & ~0x000fc000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000004
            }
        }
        namespace eval ALPHA_COUNT2 {
            namespace export SHIFT
            proc SHIFT {} {
                return 20
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 6
            }
            namespace export MASK
            proc MASK {} {
                return 0x03f00000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x03f00000) >> 20}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 20) & 0x03f00000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x03f00000) | (($field_val << 20) & 0x03f00000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x03f00000) | (($field_val << 20) & 0x03f00000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 20) & ~0x03f00000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000008
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x0081261f
        }
    }
    namespace export INTMFREQ_ALT
    proc INTMFREQ_ALT { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0xdc }]
    }
    namespace eval INTMFREQ_ALT {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0xdc }]
        }
        namespace eval ENABLE_INTMFREQ {
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
        namespace eval TWOMEG_ENABLE_INTMFREQ {
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
        namespace eval ALPHA1 {
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
                return 0x00000007
            }
        }
        namespace eval ALPHA2 {
            namespace export SHIFT
            proc SHIFT {} {
                return 6
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 4
            }
            namespace export MASK
            proc MASK {} {
                return 0x000003c0
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x000003c0) >> 6}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 6) & 0x000003c0}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x000003c0) | (($field_val << 6) & 0x000003c0)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x000003c0) | (($field_val << 6) & 0x000003c0)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 6) & ~0x000003c0)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000008
            }
        }
        namespace eval ALPHA3 {
            namespace export SHIFT
            proc SHIFT {} {
                return 10
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 4
            }
            namespace export MASK
            proc MASK {} {
                return 0x00003c00
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00003c00) >> 10}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 10) & 0x00003c00}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00003c00) | (($field_val << 10) & 0x00003c00)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00003c00) | (($field_val << 10) & 0x00003c00)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 10) & ~0x00003c00)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000009
            }
        }
        namespace eval ALPHA_COUNT1 {
            namespace export SHIFT
            proc SHIFT {} {
                return 14
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 6
            }
            namespace export MASK
            proc MASK {} {
                return 0x000fc000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x000fc000) >> 14}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 14) & 0x000fc000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x000fc000) | (($field_val << 14) & 0x000fc000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x000fc000) | (($field_val << 14) & 0x000fc000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 14) & ~0x000fc000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000004
            }
        }
        namespace eval ALPHA_COUNT2 {
            namespace export SHIFT
            proc SHIFT {} {
                return 20
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 6
            }
            namespace export MASK
            proc MASK {} {
                return 0x03f00000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x03f00000) >> 20}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 20) & 0x03f00000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x03f00000) | (($field_val << 20) & 0x03f00000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x03f00000) | (($field_val << 20) & 0x03f00000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 20) & ~0x03f00000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000008
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x0081261f
        }
    }
    namespace export TSTIMEOUT
    proc TSTIMEOUT { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0xe0 }]
    }
    namespace eval TSTIMEOUT {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0xe0 }]
        }
        namespace eval CODED_NUMSAMPLES {
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
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x0007fe00) | (($field_val << 9) & 0x0007fe00)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 9) & ~0x0007fe00)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000190
            }
        }
        namespace eval CODED_EN {
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
                return 0x00000001
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x40032000
        }
    }
    namespace export DEMOD
    proc DEMOD { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0xe4 }]
    }
    namespace eval DEMOD {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0xe4 }]
        }
        namespace eval ENABLE_FFE {
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
        namespace eval UNCODED_SAT_PHASE_DIFF {
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
                return 0x00000001
            }
        }
        namespace eval UNCODED_MAX_PHASE_DIFF {
            namespace export SHIFT
            proc SHIFT {} {
                return 10
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 6
            }
            namespace export MASK
            proc MASK {} {
                return 0x0000fc00
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x0000fc00) >> 10}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 10) & 0x0000fc00}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x0000fc00) | (($field_val << 10) & 0x0000fc00)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x0000fc00) | (($field_val << 10) & 0x0000fc00)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 10) & ~0x0000fc00)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000030
            }
        }
        namespace eval ADJUST_SAT_FOR_FREQ_OFFSET {
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
        namespace eval CODED_SAT_PHASE_DIFF {
            namespace export SHIFT
            proc SHIFT {} {
                return 25
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 1
            }
            namespace export MASK
            proc MASK {} {
                return 0x02000000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x02000000) >> 25}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 25) & 0x02000000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x02000000) | (($field_val << 25) & 0x02000000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x02000000) | (($field_val << 25) & 0x02000000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 25) & ~0x02000000)}]
            }
            namespace export SET
            proc SET {var_name} {
                upvar $var_name var
                set var [expr {($var & ~0x02000000) | (1 << 25)}]
            }
            namespace export SET_TGT
            proc SET_TGT {addr} {
                mww $addr [expr {([mrw $addr] & ~0x02000000) | (1 << 25)}]
            }
            namespace export CLR
            proc CLR {var_name} {
                upvar $var_name var
                set var [expr {$var & ~0x02000000}]
            }
            namespace export CLR_TGT
            proc CLR_TGT {addr} {
                mww $addr [expr {[mrw $addr] & ~0x02000000}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000001
            }
        }
        namespace eval CODED_MAX_PHASE_DIFF {
            namespace export SHIFT
            proc SHIFT {} {
                return 26
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 6
            }
            namespace export MASK
            proc MASK {} {
                return 0xfc000000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0xfc000000) >> 26}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 26) & 0xfc000000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0xfc000000) | (($field_val << 26) & 0xfc000000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0xfc000000) | (($field_val << 26) & 0xfc000000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 26) & ~0xfc000000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000030
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0xc200c201
        }
    }
    namespace export DFEWITHFFE
    proc DFEWITHFFE { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0xe8 }]
    }
    namespace eval DFEWITHFFE {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0xe8 }]
        }
        namespace eval ADJUST1 {
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
                return 0x00000041
            }
        }
        namespace eval ADJUST2 {
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
                return 0x00000020
            }
        }
        namespace eval ADJUST3 {
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
                return 0x00000005
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x00052041
        }
    }
    namespace export DFEWITHOUTFFE
    proc DFEWITHOUTFFE { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0xec }]
    }
    namespace eval DFEWITHOUTFFE {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0xec }]
        }
        namespace eval ADJUST1 {
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
                return 0x00000017
            }
        }
        namespace eval ADJUST2 {
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
        namespace eval ADJUST3 {
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
            return 0x00000017
        }
    }
    namespace export TWOMEG_DFEWITHFFE
    proc TWOMEG_DFEWITHFFE { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0xf0 }]
    }
    namespace eval TWOMEG_DFEWITHFFE {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0xf0 }]
        }
        namespace eval ADJUST1 {
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
                return 0x00000040
            }
        }
        namespace eval ADJUST2 {
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
                return 0x0000001e
            }
        }
        namespace eval ADJUST3 {
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
                return 0x00000004
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x00041e40
        }
    }
    namespace export TWOMEG_DFEWITHOUTFFE
    proc TWOMEG_DFEWITHOUTFFE { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0xf4 }]
    }
    namespace eval TWOMEG_DFEWITHOUTFFE {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0xf4 }]
        }
        namespace eval ADJUST1 {
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
                return 0x00000017
            }
        }
        namespace eval ADJUST2 {
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
        namespace eval ADJUST3 {
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
            return 0x00000017
        }
    }
    namespace export FREQ
    proc FREQ { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0xf8 }]
    }
    namespace eval FREQ {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0xf8 }]
        }
        namespace eval ENABLE_TRACK {
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
        namespace eval ENABLE_SAME_PAT {
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
        namespace eval MU1 {
            namespace export SHIFT
            proc SHIFT {} {
                return 2
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 3
            }
            namespace export MASK
            proc MASK {} {
                return 0x0000001c
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x0000001c) >> 2}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 2) & 0x0000001c}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x0000001c) | (($field_val << 2) & 0x0000001c)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x0000001c) | (($field_val << 2) & 0x0000001c)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 2) & ~0x0000001c)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000003
            }
        }
        namespace eval MU2 {
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
        namespace eval MU3 {
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
                return 0x00000004
            }
        }
        namespace eval PAT_DLY {
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
                return 0x00000004
            }
        }
        namespace eval MU_COUNT1 {
            namespace export SHIFT
            proc SHIFT {} {
                return 14
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 8
            }
            namespace export MASK
            proc MASK {} {
                return 0x003fc000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x003fc000) >> 14}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 14) & 0x003fc000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x003fc000) | (($field_val << 14) & 0x003fc000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x003fc000) | (($field_val << 14) & 0x003fc000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 14) & ~0x003fc000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000004
            }
        }
        namespace eval MU_COUNT2 {
            namespace export SHIFT
            proc SHIFT {} {
                return 22
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 8
            }
            namespace export MASK
            proc MASK {} {
                return 0x3fc00000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x3fc00000) >> 22}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 22) & 0x3fc00000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x3fc00000) | (($field_val << 22) & 0x3fc00000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x3fc00000) | (($field_val << 22) & 0x3fc00000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 22) & ~0x3fc00000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000010
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x0401248d
        }
    }
    namespace export FREQLIM
    proc FREQLIM { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0xfc }]
    }
    namespace eval FREQLIM {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0xfc }]
        }
        namespace eval MAXWITHFFE {
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
                return 0x000001ff
            }
        }
        namespace eval MINWITHFFE {
            namespace export SHIFT
            proc SHIFT {} {
                return 9
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 7
            }
            namespace export MASK
            proc MASK {} {
                return 0x0000fe00
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x0000fe00) >> 9}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 9) & 0x0000fe00}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x0000fe00) | (($field_val << 9) & 0x0000fe00)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x0000fe00) | (($field_val << 9) & 0x0000fe00)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 9) & ~0x0000fe00)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval MAXWITHOUTFFE {
            namespace export SHIFT
            proc SHIFT {} {
                return 16
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 9
            }
            namespace export MASK
            proc MASK {} {
                return 0x01ff0000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x01ff0000) >> 16}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 16) & 0x01ff0000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x01ff0000) | (($field_val << 16) & 0x01ff0000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x01ff0000) | (($field_val << 16) & 0x01ff0000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 16) & ~0x01ff0000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x000001ff
            }
        }
        namespace eval MINWITHOUTFFE {
            namespace export SHIFT
            proc SHIFT {} {
                return 25
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 7
            }
            namespace export MASK
            proc MASK {} {
                return 0xfe000000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0xfe000000) >> 25}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 25) & 0xfe000000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0xfe000000) | (($field_val << 25) & 0xfe000000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0xfe000000) | (($field_val << 25) & 0xfe000000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 25) & ~0xfe000000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x01ff01ff
        }
    }
    namespace export LR
    proc LR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x100 }]
    }
    namespace eval LR {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x100 }]
        }
        namespace eval SYNCH_DETECT_NUM_EXP {
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
        namespace eval SYNCH_NUM_EXP {
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
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x0000000c) | (($field_val << 2) & 0x0000000c)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 2) & ~0x0000000c)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000003
            }
        }
        namespace eval NUM_CORR_WIN {
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
                return 0x00000009
            }
        }
        namespace eval NUM_CORR_AVG {
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
                return 0x00000010
            }
        }
        namespace eval CORR_THRESH_HIGH {
            namespace export SHIFT
            proc SHIFT {} {
                return 13
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 9
            }
            namespace export MASK
            proc MASK {} {
                return 0x003fe000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x003fe000) >> 13}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 13) & 0x003fe000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x003fe000) | (($field_val << 13) & 0x003fe000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x003fe000) | (($field_val << 13) & 0x003fe000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 13) & ~0x003fe000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000088
            }
        }
        namespace eval CORR_THRESH_LOW {
            namespace export SHIFT
            proc SHIFT {} {
                return 22
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 8
            }
            namespace export MASK
            proc MASK {} {
                return 0x3fc00000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x3fc00000) >> 22}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 22) & 0x3fc00000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x3fc00000) | (($field_val << 22) & 0x3fc00000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x3fc00000) | (($field_val << 22) & 0x3fc00000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 22) & ~0x3fc00000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000008
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x0211109c
        }
    }
    namespace export LR_ALT
    proc LR_ALT { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x104 }]
    }
    namespace eval LR_ALT {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x104 }]
        }
        namespace eval SYNCH_DETECT_NUM_EXP {
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
        namespace eval SYNCH_NUM_EXP {
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
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x0000000c) | (($field_val << 2) & 0x0000000c)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 2) & ~0x0000000c)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000003
            }
        }
        namespace eval NUM_CORR_WIN {
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
                return 0x00000009
            }
        }
        namespace eval NUM_CORR_AVG {
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
                return 0x00000010
            }
        }
        namespace eval CORR_THRESH_HIGH {
            namespace export SHIFT
            proc SHIFT {} {
                return 13
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 9
            }
            namespace export MASK
            proc MASK {} {
                return 0x003fe000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x003fe000) >> 13}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 13) & 0x003fe000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x003fe000) | (($field_val << 13) & 0x003fe000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x003fe000) | (($field_val << 13) & 0x003fe000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 13) & ~0x003fe000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000088
            }
        }
        namespace eval CORR_THRESH_LOW {
            namespace export SHIFT
            proc SHIFT {} {
                return 22
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 8
            }
            namespace export MASK
            proc MASK {} {
                return 0x3fc00000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x3fc00000) >> 22}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 22) & 0x3fc00000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x3fc00000) | (($field_val << 22) & 0x3fc00000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x3fc00000) | (($field_val << 22) & 0x3fc00000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 22) & ~0x3fc00000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000008
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x0211109c
        }
    }
    namespace export MIXER
    proc MIXER { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x108 }]
    }
    namespace eval MIXER {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x108 }]
        }
        namespace eval LOW_IF_FREQ {
            namespace export SHIFT
            proc SHIFT {} {
                return 0
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 14
            }
            namespace export MASK
            proc MASK {} {
                return 0x00003fff
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00003fff) >> 0}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 0) & 0x00003fff}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00003fff) | (($field_val << 0) & 0x00003fff)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00003fff) | (($field_val << 0) & 0x00003fff)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 0) & ~0x00003fff)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000333
            }
        }
        namespace eval TWOMEG_LOW_IF_FREQ {
            namespace export SHIFT
            proc SHIFT {} {
                return 14
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 14
            }
            namespace export MASK
            proc MASK {} {
                return 0x0fffc000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x0fffc000) >> 14}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 14) & 0x0fffc000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x0fffc000) | (($field_val << 14) & 0x0fffc000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x0fffc000) | (($field_val << 14) & 0x0fffc000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 14) & ~0x0fffc000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000666
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x01998333
        }
    }
    namespace export ACCESS_ADDRESS
    proc ACCESS_ADDRESS { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x10c }]
    }
    namespace eval ACCESS_ADDRESS {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x10c }]
        }
        namespace eval MATCH_THR {
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
                return 0x00000020
            }
        }
        namespace eval LSB_AUTO_MATCH {
            namespace export SHIFT
            proc SHIFT {} {
                return 6
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 4
            }
            namespace export MASK
            proc MASK {} {
                return 0x000003c0
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x000003c0) >> 6}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 6) & 0x000003c0}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x000003c0) | (($field_val << 6) & 0x000003c0)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x000003c0) | (($field_val << 6) & 0x000003c0)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 6) & ~0x000003c0)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000001
            }
        }
        namespace eval ENABLE_CODED_TIMEOUT {
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
                return 0x00000001
            }
        }
        namespace eval CODED_BIT_COUNT_TIMEOUT {
            namespace export SHIFT
            proc SHIFT {} {
                return 12
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 12
            }
            namespace export MASK
            proc MASK {} {
                return 0x00fff000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00fff000) >> 12}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 12) & 0x00fff000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00fff000) | (($field_val << 12) & 0x00fff000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00fff000) | (($field_val << 12) & 0x00fff000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 12) & ~0x00fff000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x0000017c
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x0017c460
        }
    }
    namespace export MODE
    proc MODE { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x110 }]
    }
    namespace eval MODE {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x110 }]
        }
        namespace eval PMODE {
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
        namespace eval MOD_MODE {
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
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x0000000c) | (($field_val << 2) & 0x0000000c)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 2) & ~0x0000000c)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000001
            }
        }
        namespace eval FORCE_RX_EN {
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
        namespace eval FORCED_RX_EN_VALUE {
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
        namespace eval FORCE_REG_BANK {
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
        namespace eval REG_BANK {
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
        namespace eval INVERT_REG_SELECT_FROM_LC {
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
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x00000004
        }
    }
    namespace export DCCAL
    proc DCCAL { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x114 }]
    }
    namespace eval DCCAL {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x114 }]
        }
        namespace eval BYP {
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
        namespace eval START {
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
        namespace eval AVG_ONLY {
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
        namespace eval AVG_CNT_EXP {
            namespace export SHIFT
            proc SHIFT {} {
                return 4
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 3
            }
            namespace export MASK
            proc MASK {} {
                return 0x00000070
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00000070) >> 4}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 4) & 0x00000070}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00000070) | (($field_val << 4) & 0x00000070)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00000070) | (($field_val << 4) & 0x00000070)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 4) & ~0x00000070)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000003
            }
        }
        namespace eval SRCH_BIT_CNT {
            namespace export SHIFT
            proc SHIFT {} {
                return 7
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 4
            }
            namespace export MASK
            proc MASK {} {
                return 0x00000780
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00000780) >> 7}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 7) & 0x00000780}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00000780) | (($field_val << 7) & 0x00000780)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00000780) | (($field_val << 7) & 0x00000780)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 7) & ~0x00000780)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000006
            }
        }
        namespace eval MSB {
            namespace export SHIFT
            proc SHIFT {} {
                return 12
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 3
            }
            namespace export MASK
            proc MASK {} {
                return 0x00007000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00007000) >> 12}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 12) & 0x00007000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00007000) | (($field_val << 12) & 0x00007000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00007000) | (($field_val << 12) & 0x00007000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 12) & ~0x00007000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval IQ_RATIO {
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
                return 0x000000b2
            }
        }
        namespace eval IQ_RATIO_TWOMEG {
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
                return 0x000000b2
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0xb2b20330
        }
    }
    namespace export DCCAL2
    proc DCCAL2 { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x118 }]
    }
    namespace eval DCCAL2 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x118 }]
        }
        namespace eval RF_POST_DCCAL_STTL_CNT {
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
                return 0x00000010
            }
        }
        namespace eval RF_STTL_CNT {
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
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 10) & 0x000ffc00}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x000ffc00) | (($field_val << 10) & 0x000ffc00)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x000ffc00) | (($field_val << 10) & 0x000ffc00)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 10) & ~0x000ffc00)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000010
            }
        }
        namespace eval RF_STTL_CNT_TWOMEG {
            namespace export SHIFT
            proc SHIFT {} {
                return 20
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 10
            }
            namespace export MASK
            proc MASK {} {
                return 0x3ff00000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x3ff00000) >> 20}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 20) & 0x3ff00000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x3ff00000) | (($field_val << 20) & 0x3ff00000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x3ff00000) | (($field_val << 20) & 0x3ff00000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 20) & ~0x3ff00000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000010
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x01004010
        }
    }
    namespace export DCCAL_CTRL
    proc DCCAL_CTRL { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x11c }]
    }
    namespace eval DCCAL_CTRL {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x11c }]
        }
        namespace eval BYP {
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
        namespace eval START {
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
        namespace eval MODE {
            namespace export SHIFT
            proc SHIFT {} {
                return 2
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 3
            }
            namespace export MASK
            proc MASK {} {
                return 0x0000001c
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x0000001c) >> 2}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 2) & 0x0000001c}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x0000001c) | (($field_val << 2) & 0x0000001c)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x0000001c) | (($field_val << 2) & 0x0000001c)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 2) & ~0x0000001c)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval FORCE_RES_CORR {
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
        namespace eval USE_CAL_GAIN_PGA_OFF {
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
                return 0x00000001
            }
        }
        namespace eval USE_EQ_LP_PGA_OFF {
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
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x00000040
        }
    }
    namespace export TIA_DCCAL
    proc TIA_DCCAL { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x120 }]
    }
    namespace eval TIA_DCCAL {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x120 }]
        }
        namespace eval AVG_ONLY {
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
        namespace eval AVG_CNT_EXP {
            namespace export SHIFT
            proc SHIFT {} {
                return 4
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 3
            }
            namespace export MASK
            proc MASK {} {
                return 0x00000070
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00000070) >> 4}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 4) & 0x00000070}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00000070) | (($field_val << 4) & 0x00000070)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00000070) | (($field_val << 4) & 0x00000070)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 4) & ~0x00000070)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000003
            }
        }
        namespace eval SRCH_BIT_CNT {
            namespace export SHIFT
            proc SHIFT {} {
                return 7
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 4
            }
            namespace export MASK
            proc MASK {} {
                return 0x00000780
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00000780) >> 7}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 7) & 0x00000780}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00000780) | (($field_val << 7) & 0x00000780)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00000780) | (($field_val << 7) & 0x00000780)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 7) & ~0x00000780)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000006
            }
        }
        namespace eval MSB {
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
        namespace eval IQ_RATIO {
            namespace export SHIFT
            proc SHIFT {} {
                return 14
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 9
            }
            namespace export MASK
            proc MASK {} {
                return 0x007fc000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x007fc000) >> 14}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 14) & 0x007fc000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x007fc000) | (($field_val << 14) & 0x007fc000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x007fc000) | (($field_val << 14) & 0x007fc000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 14) & ~0x007fc000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000113
            }
        }
        namespace eval IQ_RATIO_TWOMEG {
            namespace export SHIFT
            proc SHIFT {} {
                return 23
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 9
            }
            namespace export MASK
            proc MASK {} {
                return 0xff800000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0xff800000) >> 23}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 23) & 0xff800000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0xff800000) | (($field_val << 23) & 0xff800000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0xff800000) | (($field_val << 23) & 0xff800000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 23) & ~0xff800000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000113
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x89c4c330
        }
    }
    namespace export TIA_DCCAL2
    proc TIA_DCCAL2 { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x124 }]
    }
    namespace eval TIA_DCCAL2 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x124 }]
        }
        namespace eval RF_POST_DCCAL_STTL_CNT {
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
                return 0x00000050
            }
        }
        namespace eval RF_STTL_CNT {
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
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 10) & 0x000ffc00}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x000ffc00) | (($field_val << 10) & 0x000ffc00)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x000ffc00) | (($field_val << 10) & 0x000ffc00)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 10) & ~0x000ffc00)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000010
            }
        }
        namespace eval RF_STTL_CNT_TWOMEG {
            namespace export SHIFT
            proc SHIFT {} {
                return 20
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 10
            }
            namespace export MASK
            proc MASK {} {
                return 0x3ff00000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x3ff00000) >> 20}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 20) & 0x3ff00000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x3ff00000) | (($field_val << 20) & 0x3ff00000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x3ff00000) | (($field_val << 20) & 0x3ff00000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 20) & ~0x3ff00000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000010
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x01004050
        }
    }
    namespace export TIA_DCCAL3
    proc TIA_DCCAL3 { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x128 }]
    }
    namespace eval TIA_DCCAL3 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x128 }]
        }
        namespace eval RF_POST_DCCAL_LNA_PRTCT_STTL_CNT {
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
                return 0x00000030
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x00000030
        }
    }
    namespace export TIA_DCCAL4
    proc TIA_DCCAL4 { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x12c }]
    }
    namespace eval TIA_DCCAL4 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x12c }]
        }
        namespace eval IQ_RATIO {
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
                return 0x00000026
            }
        }
        namespace eval IQ_RATIO_TWOMEG {
            namespace export SHIFT
            proc SHIFT {} {
                return 9
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 9
            }
            namespace export MASK
            proc MASK {} {
                return 0x0003fe00
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x0003fe00) >> 9}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 9) & 0x0003fe00}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x0003fe00) | (($field_val << 9) & 0x0003fe00)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x0003fe00) | (($field_val << 9) & 0x0003fe00)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 9) & ~0x0003fe00)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000026
            }
        }
        namespace eval DCOC_WDTH {
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
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x00004c26
        }
    }
    namespace export PGA_DCCAL
    proc PGA_DCCAL { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x130 }]
    }
    namespace eval PGA_DCCAL {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x130 }]
        }
        namespace eval AVG_ONLY {
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
        namespace eval AVG_CNT_EXP {
            namespace export SHIFT
            proc SHIFT {} {
                return 4
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 3
            }
            namespace export MASK
            proc MASK {} {
                return 0x00000070
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00000070) >> 4}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 4) & 0x00000070}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00000070) | (($field_val << 4) & 0x00000070)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00000070) | (($field_val << 4) & 0x00000070)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 4) & ~0x00000070)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000003
            }
        }
        namespace eval SRCH_BIT_CNT {
            namespace export SHIFT
            proc SHIFT {} {
                return 7
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 4
            }
            namespace export MASK
            proc MASK {} {
                return 0x00000780
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00000780) >> 7}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 7) & 0x00000780}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00000780) | (($field_val << 7) & 0x00000780)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00000780) | (($field_val << 7) & 0x00000780)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 7) & ~0x00000780)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000005
            }
        }
        namespace eval MSB {
            namespace export SHIFT
            proc SHIFT {} {
                return 12
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 3
            }
            namespace export MASK
            proc MASK {} {
                return 0x00007000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00007000) >> 12}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 12) & 0x00007000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00007000) | (($field_val << 12) & 0x00007000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00007000) | (($field_val << 12) & 0x00007000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 12) & ~0x00007000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval IQ_RATIO {
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
                return 0x000000e0
            }
        }
        namespace eval IQ_RATIO_TWOMEG {
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
                return 0x000000e0
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0xe0e002b0
        }
    }
    namespace export PGA_DCCAL2
    proc PGA_DCCAL2 { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x134 }]
    }
    namespace eval PGA_DCCAL2 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x134 }]
        }
        namespace eval RF_POST_DCCAL_STTL_CNT {
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
                return 0x00000050
            }
        }
        namespace eval RF_STTL_CNT {
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
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 10) & 0x000ffc00}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x000ffc00) | (($field_val << 10) & 0x000ffc00)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x000ffc00) | (($field_val << 10) & 0x000ffc00)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 10) & ~0x000ffc00)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000010
            }
        }
        namespace eval RF_STTL_CNT_TWOMEG {
            namespace export SHIFT
            proc SHIFT {} {
                return 20
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 10
            }
            namespace export MASK
            proc MASK {} {
                return 0x3ff00000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x3ff00000) >> 20}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 20) & 0x3ff00000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x3ff00000) | (($field_val << 20) & 0x3ff00000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x3ff00000) | (($field_val << 20) & 0x3ff00000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 20) & ~0x3ff00000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000010
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x01004050
        }
    }
    namespace export PGA_DCCAL3
    proc PGA_DCCAL3 { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x138 }]
    }
    namespace eval PGA_DCCAL3 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x138 }]
        }
        namespace eval RF_POST_DCCAL_LNA_PRTCT_STTL_CNT {
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
                return 0x00000030
            }
        }
        namespace eval CAL_GAIN_SCL {
            namespace export SHIFT
            proc SHIFT {} {
                return 10
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 8
            }
            namespace export MASK
            proc MASK {} {
                return 0x0003fc00
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x0003fc00) >> 10}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 10) & 0x0003fc00}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x0003fc00) | (($field_val << 10) & 0x0003fc00)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x0003fc00) | (($field_val << 10) & 0x0003fc00)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 10) & ~0x0003fc00)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x000000d8
            }
        }
        namespace eval CAL_GAIN_SCL_LS {
            namespace export SHIFT
            proc SHIFT {} {
                return 18
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 3
            }
            namespace export MASK
            proc MASK {} {
                return 0x001c0000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x001c0000) >> 18}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 18) & 0x001c0000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x001c0000) | (($field_val << 18) & 0x001c0000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x001c0000) | (($field_val << 18) & 0x001c0000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 18) & ~0x001c0000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000004
            }
        }
        namespace eval CAL_GAIN_SCL_LP {
            namespace export SHIFT
            proc SHIFT {} {
                return 21
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 8
            }
            namespace export MASK
            proc MASK {} {
                return 0x1fe00000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x1fe00000) >> 21}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 21) & 0x1fe00000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x1fe00000) | (($field_val << 21) & 0x1fe00000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x1fe00000) | (($field_val << 21) & 0x1fe00000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 21) & ~0x1fe00000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x000000f3
            }
        }
        namespace eval CAL_GAIN_SCL_LP_LS {
            namespace export SHIFT
            proc SHIFT {} {
                return 29
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 3
            }
            namespace export MASK
            proc MASK {} {
                return 0xe0000000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0xe0000000) >> 29}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 29) & 0xe0000000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0xe0000000) | (($field_val << 29) & 0xe0000000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0xe0000000) | (($field_val << 29) & 0xe0000000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 29) & ~0xe0000000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000004
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x9e736030
        }
    }
    namespace export PGA_DCCAL4
    proc PGA_DCCAL4 { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x13c }]
    }
    namespace eval PGA_DCCAL4 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x13c }]
        }
        namespace eval IQ_RATIO {
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
                return 0x000000e0
            }
        }
        namespace eval IQ_RATIO_TWOMEG {
            namespace export SHIFT
            proc SHIFT {} {
                return 16
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 9
            }
            namespace export MASK
            proc MASK {} {
                return 0x01ff0000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x01ff0000) >> 16}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 16) & 0x01ff0000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x01ff0000) | (($field_val << 16) & 0x01ff0000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x01ff0000) | (($field_val << 16) & 0x01ff0000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 16) & ~0x01ff0000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x000000e0
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x00e000e0
        }
    }
    namespace export PGA_DCCAL5
    proc PGA_DCCAL5 { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x140 }]
    }
    namespace eval PGA_DCCAL5 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x140 }]
        }
        namespace eval NM_TO_LPM_SCL {
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
                return 0x00000074
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x00000074
        }
    }
    namespace export NOTCH_DCCAL
    proc NOTCH_DCCAL { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x144 }]
    }
    namespace eval NOTCH_DCCAL {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x144 }]
        }
        namespace eval AVG_ONLY {
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
        namespace eval AVG_CNT_EXP {
            namespace export SHIFT
            proc SHIFT {} {
                return 4
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 3
            }
            namespace export MASK
            proc MASK {} {
                return 0x00000070
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00000070) >> 4}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 4) & 0x00000070}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00000070) | (($field_val << 4) & 0x00000070)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00000070) | (($field_val << 4) & 0x00000070)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 4) & ~0x00000070)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000003
            }
        }
        namespace eval SRCH_BIT_CNT {
            namespace export SHIFT
            proc SHIFT {} {
                return 7
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 4
            }
            namespace export MASK
            proc MASK {} {
                return 0x00000780
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00000780) >> 7}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 7) & 0x00000780}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00000780) | (($field_val << 7) & 0x00000780)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00000780) | (($field_val << 7) & 0x00000780)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 7) & ~0x00000780)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000006
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x00000330
        }
    }
    namespace export NOTCH_DCCAL2
    proc NOTCH_DCCAL2 { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x148 }]
    }
    namespace eval NOTCH_DCCAL2 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x148 }]
        }
        namespace eval RF_POST_DCCAL_STTL_CNT {
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
                return 0x00000050
            }
        }
        namespace eval RF_STTL_CNT {
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
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 10) & 0x000ffc00}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x000ffc00) | (($field_val << 10) & 0x000ffc00)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x000ffc00) | (($field_val << 10) & 0x000ffc00)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 10) & ~0x000ffc00)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000010
            }
        }
        namespace eval RF_STTL_CNT_TWOMEG {
            namespace export SHIFT
            proc SHIFT {} {
                return 20
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 10
            }
            namespace export MASK
            proc MASK {} {
                return 0x3ff00000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x3ff00000) >> 20}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 20) & 0x3ff00000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x3ff00000) | (($field_val << 20) & 0x3ff00000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x3ff00000) | (($field_val << 20) & 0x3ff00000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 20) & ~0x3ff00000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000010
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x01004050
        }
    }
    namespace export NOTCH_DCCAL3
    proc NOTCH_DCCAL3 { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x14c }]
    }
    namespace eval NOTCH_DCCAL3 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x14c }]
        }
        namespace eval RF_POST_DCCAL_LNA_PRTCT_STTL_CNT {
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
                return 0x00000030
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x00000030
        }
    }
    namespace export DCOFFTRK
    proc DCOFFTRK { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x150 }]
    }
    namespace eval DCOFFTRK {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x150 }]
        }
        namespace eval EN {
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
        namespace eval CORR_AGC_EN {
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
        namespace eval CORR_SYNCDEMOD_EN {
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
        namespace eval MU1 {
            namespace export SHIFT
            proc SHIFT {} {
                return 3
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 3
            }
            namespace export MASK
            proc MASK {} {
                return 0x00000038
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00000038) >> 3}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 3) & 0x00000038}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00000038) | (($field_val << 3) & 0x00000038)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00000038) | (($field_val << 3) & 0x00000038)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 3) & ~0x00000038)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000002
            }
        }
        namespace eval MU2 {
            namespace export SHIFT
            proc SHIFT {} {
                return 6
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 3
            }
            namespace export MASK
            proc MASK {} {
                return 0x000001c0
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x000001c0) >> 6}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 6) & 0x000001c0}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x000001c0) | (($field_val << 6) & 0x000001c0)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x000001c0) | (($field_val << 6) & 0x000001c0)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 6) & ~0x000001c0)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000004
            }
        }
        namespace eval MU3 {
            namespace export SHIFT
            proc SHIFT {} {
                return 9
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 3
            }
            namespace export MASK
            proc MASK {} {
                return 0x00000e00
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00000e00) >> 9}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 9) & 0x00000e00}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00000e00) | (($field_val << 9) & 0x00000e00)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00000e00) | (($field_val << 9) & 0x00000e00)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 9) & ~0x00000e00)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000006
            }
        }
        namespace eval MU_COUNT1 {
            namespace export SHIFT
            proc SHIFT {} {
                return 12
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 6
            }
            namespace export MASK
            proc MASK {} {
                return 0x0003f000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x0003f000) >> 12}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 12) & 0x0003f000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x0003f000) | (($field_val << 12) & 0x0003f000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x0003f000) | (($field_val << 12) & 0x0003f000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 12) & ~0x0003f000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000002
            }
        }
        namespace eval MU_COUNT2 {
            namespace export SHIFT
            proc SHIFT {} {
                return 18
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 6
            }
            namespace export MASK
            proc MASK {} {
                return 0x00fc0000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00fc0000) >> 18}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 18) & 0x00fc0000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00fc0000) | (($field_val << 18) & 0x00fc0000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00fc0000) | (($field_val << 18) & 0x00fc0000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 18) & ~0x00fc0000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000004
            }
        }
        namespace eval CORR_DELAY_IDX {
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
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x07000000) | (($field_val << 24) & 0x07000000)}]
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
        namespace eval TWOMEG_EN {
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
                return 0x00000001
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x08102d17
        }
    }
    namespace export DCOFFTRK_ALT
    proc DCOFFTRK_ALT { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x154 }]
    }
    namespace eval DCOFFTRK_ALT {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x154 }]
        }
        namespace eval EN {
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
        namespace eval CORR_AGC_EN {
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
        namespace eval CORR_SYNCDEMOD_EN {
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
        namespace eval MU1 {
            namespace export SHIFT
            proc SHIFT {} {
                return 3
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 3
            }
            namespace export MASK
            proc MASK {} {
                return 0x00000038
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00000038) >> 3}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 3) & 0x00000038}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00000038) | (($field_val << 3) & 0x00000038)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00000038) | (($field_val << 3) & 0x00000038)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 3) & ~0x00000038)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000002
            }
        }
        namespace eval MU2 {
            namespace export SHIFT
            proc SHIFT {} {
                return 6
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 3
            }
            namespace export MASK
            proc MASK {} {
                return 0x000001c0
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x000001c0) >> 6}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 6) & 0x000001c0}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x000001c0) | (($field_val << 6) & 0x000001c0)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x000001c0) | (($field_val << 6) & 0x000001c0)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 6) & ~0x000001c0)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000004
            }
        }
        namespace eval MU3 {
            namespace export SHIFT
            proc SHIFT {} {
                return 9
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 3
            }
            namespace export MASK
            proc MASK {} {
                return 0x00000e00
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00000e00) >> 9}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 9) & 0x00000e00}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00000e00) | (($field_val << 9) & 0x00000e00)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00000e00) | (($field_val << 9) & 0x00000e00)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 9) & ~0x00000e00)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000006
            }
        }
        namespace eval MU_COUNT1 {
            namespace export SHIFT
            proc SHIFT {} {
                return 12
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 6
            }
            namespace export MASK
            proc MASK {} {
                return 0x0003f000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x0003f000) >> 12}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 12) & 0x0003f000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x0003f000) | (($field_val << 12) & 0x0003f000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x0003f000) | (($field_val << 12) & 0x0003f000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 12) & ~0x0003f000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000002
            }
        }
        namespace eval MU_COUNT2 {
            namespace export SHIFT
            proc SHIFT {} {
                return 18
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 6
            }
            namespace export MASK
            proc MASK {} {
                return 0x00fc0000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00fc0000) >> 18}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 18) & 0x00fc0000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00fc0000) | (($field_val << 18) & 0x00fc0000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00fc0000) | (($field_val << 18) & 0x00fc0000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 18) & ~0x00fc0000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000004
            }
        }
        namespace eval CORR_DELAY_IDX {
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
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x07000000) | (($field_val << 24) & 0x07000000)}]
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
        namespace eval TWOMEG_EN {
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
                return 0x00000001
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x08102d17
        }
    }
    namespace export DCOFFTRK2
    proc DCOFFTRK2 { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x158 }]
    }
    namespace eval DCOFFTRK2 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x158 }]
        }
        namespace eval RESET_FILT_DELAY {
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
        namespace eval TWOMEG_RESET_FILT_DELAY {
            namespace export SHIFT
            proc SHIFT {} {
                return 6
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 6
            }
            namespace export MASK
            proc MASK {} {
                return 0x00000fc0
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00000fc0) >> 6}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 6) & 0x00000fc0}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00000fc0) | (($field_val << 6) & 0x00000fc0)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00000fc0) | (($field_val << 6) & 0x00000fc0)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 6) & ~0x00000fc0)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x0000000a
            }
        }
        namespace eval XLNA_RESET_FILT_DELAY {
            namespace export SHIFT
            proc SHIFT {} {
                return 12
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 6
            }
            namespace export MASK
            proc MASK {} {
                return 0x0003f000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x0003f000) >> 12}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 12) & 0x0003f000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x0003f000) | (($field_val << 12) & 0x0003f000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x0003f000) | (($field_val << 12) & 0x0003f000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 12) & ~0x0003f000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000010
            }
        }
        namespace eval TWOMEG_XLNA_RESET_FILT_DELAY {
            namespace export SHIFT
            proc SHIFT {} {
                return 18
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 6
            }
            namespace export MASK
            proc MASK {} {
                return 0x00fc0000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00fc0000) >> 18}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 18) & 0x00fc0000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00fc0000) | (($field_val << 18) & 0x00fc0000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00fc0000) | (($field_val << 18) & 0x00fc0000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 18) & ~0x00fc0000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x0000000a
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x00290290
        }
    }
    namespace export DCOFFTRK2_ALT
    proc DCOFFTRK2_ALT { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x15c }]
    }
    namespace eval DCOFFTRK2_ALT {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x15c }]
        }
        namespace eval RESET_FILT_DELAY {
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
        namespace eval TWOMEG_RESET_FILT_DELAY {
            namespace export SHIFT
            proc SHIFT {} {
                return 6
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 6
            }
            namespace export MASK
            proc MASK {} {
                return 0x00000fc0
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00000fc0) >> 6}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 6) & 0x00000fc0}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00000fc0) | (($field_val << 6) & 0x00000fc0)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00000fc0) | (($field_val << 6) & 0x00000fc0)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 6) & ~0x00000fc0)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x0000000a
            }
        }
        namespace eval XLNA_RESET_FILT_DELAY {
            namespace export SHIFT
            proc SHIFT {} {
                return 12
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 6
            }
            namespace export MASK
            proc MASK {} {
                return 0x0003f000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x0003f000) >> 12}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 12) & 0x0003f000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x0003f000) | (($field_val << 12) & 0x0003f000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x0003f000) | (($field_val << 12) & 0x0003f000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 12) & ~0x0003f000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000010
            }
        }
        namespace eval TWOMEG_XLNA_RESET_FILT_DELAY {
            namespace export SHIFT
            proc SHIFT {} {
                return 18
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 6
            }
            namespace export MASK
            proc MASK {} {
                return 0x00fc0000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00fc0000) >> 18}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 18) & 0x00fc0000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00fc0000) | (($field_val << 18) & 0x00fc0000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00fc0000) | (($field_val << 18) & 0x00fc0000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 18) & ~0x00fc0000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x0000000a
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x00290290
        }
    }
    namespace export DFCNTL
    proc DFCNTL { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x160 }]
    }
    namespace eval DFCNTL {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x160 }]
        }
        namespace eval IQ_SELECT {
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
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 0) & 0x00000007}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00000007) | (($field_val << 0) & 0x00000007)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00000007) | (($field_val << 0) & 0x00000007)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 0) & ~0x00000007)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000005
            }
        }
        namespace eval TWOMEG_IQ_SELECT {
            namespace export SHIFT
            proc SHIFT {} {
                return 3
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 3
            }
            namespace export MASK
            proc MASK {} {
                return 0x00000038
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00000038) >> 3}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 3) & 0x00000038}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00000038) | (($field_val << 3) & 0x00000038)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00000038) | (($field_val << 3) & 0x00000038)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 3) & ~0x00000038)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000005
            }
        }
        namespace eval LEFT_SHIFT {
            namespace export SHIFT
            proc SHIFT {} {
                return 6
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 3
            }
            namespace export MASK
            proc MASK {} {
                return 0x000001c0
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x000001c0) >> 6}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 6) & 0x000001c0}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x000001c0) | (($field_val << 6) & 0x000001c0)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x000001c0) | (($field_val << 6) & 0x000001c0)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 6) & ~0x000001c0)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval TWOMEG_LEFT_SHIFT {
            namespace export SHIFT
            proc SHIFT {} {
                return 9
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 3
            }
            namespace export MASK
            proc MASK {} {
                return 0x00000e00
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00000e00) >> 9}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 9) & 0x00000e00}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00000e00) | (($field_val << 9) & 0x00000e00)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00000e00) | (($field_val << 9) & 0x00000e00)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 9) & ~0x00000e00)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval DYNAMIC_LEFT_SHIFT {
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
        namespace eval UPDATE_ON_CTE_ONLY {
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
                return 0x00000001
            }
        }
        namespace eval ANTMODE {
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
        namespace eval SW_ANT_SELECT {
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
        namespace eval USE_SW_ANT_SELECT {
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
        namespace eval USE_DEFAULT_SW_ANT_SELECT_FOR_CTE {
            namespace export SHIFT
            proc SHIFT {} {
                return 22
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 1
            }
            namespace export MASK
            proc MASK {} {
                return 0x00400000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00400000) >> 22}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 22) & 0x00400000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00400000) | (($field_val << 22) & 0x00400000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00400000) | (($field_val << 22) & 0x00400000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 22) & ~0x00400000)}]
            }
            namespace export SET
            proc SET {var_name} {
                upvar $var_name var
                set var [expr {($var & ~0x00400000) | (1 << 22)}]
            }
            namespace export SET_TGT
            proc SET_TGT {addr} {
                mww $addr [expr {([mrw $addr] & ~0x00400000) | (1 << 22)}]
            }
            namespace export CLR
            proc CLR {var_name} {
                upvar $var_name var
                set var [expr {$var & ~0x00400000}]
            }
            namespace export CLR_TGT
            proc CLR_TGT {addr} {
                mww $addr [expr {[mrw $addr] & ~0x00400000}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000001
            }
        }
        namespace eval SW_ANT_SELECT_FOR_CTE {
            namespace export SHIFT
            proc SHIFT {} {
                return 23
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 3
            }
            namespace export MASK
            proc MASK {} {
                return 0x03800000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x03800000) >> 23}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 23) & 0x03800000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x03800000) | (($field_val << 23) & 0x03800000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x03800000) | (($field_val << 23) & 0x03800000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 23) & ~0x03800000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval UPDATE_RD_FREQ_EST_DURING_CTE {
            namespace export SHIFT
            proc SHIFT {} {
                return 26
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 1
            }
            namespace export MASK
            proc MASK {} {
                return 0x04000000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x04000000) >> 26}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 26) & 0x04000000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x04000000) | (($field_val << 26) & 0x04000000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x04000000) | (($field_val << 26) & 0x04000000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 26) & ~0x04000000)}]
            }
            namespace export SET
            proc SET {var_name} {
                upvar $var_name var
                set var [expr {($var & ~0x04000000) | (1 << 26)}]
            }
            namespace export SET_TGT
            proc SET_TGT {addr} {
                mww $addr [expr {([mrw $addr] & ~0x04000000) | (1 << 26)}]
            }
            namespace export CLR
            proc CLR {var_name} {
                upvar $var_name var
                set var [expr {$var & ~0x04000000}]
            }
            namespace export CLR_TGT
            proc CLR_TGT {addr} {
                mww $addr [expr {[mrw $addr] & ~0x04000000}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x0040202d
        }
    }
    namespace export DFCNTL_ALT
    proc DFCNTL_ALT { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x164 }]
    }
    namespace eval DFCNTL_ALT {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x164 }]
        }
        namespace eval SW_ANT_SELECT {
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
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x00000000
        }
    }
    namespace export SWANTCTETIME
    proc SWANTCTETIME { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x168 }]
    }
    namespace eval SWANTCTETIME {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x168 }]
        }
        namespace eval RX {
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
        namespace eval TX {
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
                return 0x00000000
            }
        }
        namespace eval TWOMEG_RX {
            namespace export SHIFT
            proc SHIFT {} {
                return 14
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 7
            }
            namespace export MASK
            proc MASK {} {
                return 0x001fc000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x001fc000) >> 14}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 14) & 0x001fc000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x001fc000) | (($field_val << 14) & 0x001fc000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x001fc000) | (($field_val << 14) & 0x001fc000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 14) & ~0x001fc000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval TWOMEG_TX {
            namespace export SHIFT
            proc SHIFT {} {
                return 21
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 7
            }
            namespace export MASK
            proc MASK {} {
                return 0x0fe00000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x0fe00000) >> 21}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 21) & 0x0fe00000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x0fe00000) | (($field_val << 21) & 0x0fe00000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x0fe00000) | (($field_val << 21) & 0x0fe00000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 21) & ~0x0fe00000)}]
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
    namespace export DFTABLE
    proc DFTABLE { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x16c }]
    }
    namespace eval DFTABLE {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x16c }]
        }
        namespace eval M5TO0 {
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
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 0) & 0x00000007}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00000007) | (($field_val << 0) & 0x00000007)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00000007) | (($field_val << 0) & 0x00000007)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 0) & ~0x00000007)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000002
            }
        }
        namespace eval M11TOM6 {
            namespace export SHIFT
            proc SHIFT {} {
                return 3
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 3
            }
            namespace export MASK
            proc MASK {} {
                return 0x00000038
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00000038) >> 3}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 3) & 0x00000038}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00000038) | (($field_val << 3) & 0x00000038)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00000038) | (($field_val << 3) & 0x00000038)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 3) & ~0x00000038)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000002
            }
        }
        namespace eval M17TOM12 {
            namespace export SHIFT
            proc SHIFT {} {
                return 6
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 3
            }
            namespace export MASK
            proc MASK {} {
                return 0x000001c0
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x000001c0) >> 6}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 6) & 0x000001c0}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x000001c0) | (($field_val << 6) & 0x000001c0)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x000001c0) | (($field_val << 6) & 0x000001c0)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 6) & ~0x000001c0)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000002
            }
        }
        namespace eval M23TOM18 {
            namespace export SHIFT
            proc SHIFT {} {
                return 9
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 3
            }
            namespace export MASK
            proc MASK {} {
                return 0x00000e00
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00000e00) >> 9}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 9) & 0x00000e00}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00000e00) | (($field_val << 9) & 0x00000e00)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00000e00) | (($field_val << 9) & 0x00000e00)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 9) & ~0x00000e00)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000002
            }
        }
        namespace eval M29TOM24 {
            namespace export SHIFT
            proc SHIFT {} {
                return 12
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 3
            }
            namespace export MASK
            proc MASK {} {
                return 0x00007000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00007000) >> 12}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 12) & 0x00007000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00007000) | (($field_val << 12) & 0x00007000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00007000) | (($field_val << 12) & 0x00007000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 12) & ~0x00007000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000002
            }
        }
        namespace eval M35TOM30 {
            namespace export SHIFT
            proc SHIFT {} {
                return 15
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 3
            }
            namespace export MASK
            proc MASK {} {
                return 0x00038000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00038000) >> 15}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 15) & 0x00038000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00038000) | (($field_val << 15) & 0x00038000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00038000) | (($field_val << 15) & 0x00038000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 15) & ~0x00038000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000002
            }
        }
        namespace eval M41TOM36 {
            namespace export SHIFT
            proc SHIFT {} {
                return 18
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 3
            }
            namespace export MASK
            proc MASK {} {
                return 0x001c0000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x001c0000) >> 18}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 18) & 0x001c0000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x001c0000) | (($field_val << 18) & 0x001c0000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x001c0000) | (($field_val << 18) & 0x001c0000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 18) & ~0x001c0000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000002
            }
        }
        namespace eval BELOWM41 {
            namespace export SHIFT
            proc SHIFT {} {
                return 21
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 3
            }
            namespace export MASK
            proc MASK {} {
                return 0x00e00000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00e00000) >> 21}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 21) & 0x00e00000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00e00000) | (($field_val << 21) & 0x00e00000)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00e00000) | (($field_val << 21) & 0x00e00000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 21) & ~0x00e00000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000002
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x00492492
        }
    }
    namespace export DFSTATUS
    proc DFSTATUS { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x170 }]
    }
    namespace eval DFSTATUS {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x170 }]
        }
        namespace eval RSSI {
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
        namespace eval RXGAIN {
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
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval BASELINE_PWR {
            namespace export SHIFT
            proc SHIFT {} {
                return 15
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 8
            }
            namespace export MASK
            proc MASK {} {
                return 0x007f8000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x007f8000) >> 15}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval SAT_DETECTED {
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
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval PEAK_DETECTED {
            namespace export SHIFT
            proc SHIFT {} {
                return 24
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 1
            }
            namespace export MASK
            proc MASK {} {
                return 0x01000000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x01000000) >> 24}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval STRONG_BLOCKER {
            namespace export SHIFT
            proc SHIFT {} {
                return 25
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 1
            }
            namespace export MASK
            proc MASK {} {
                return 0x02000000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x02000000) >> 25}]
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
    namespace export ANTRX3TO0
    proc ANTRX3TO0 { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x174 }]
    }
    namespace eval ANTRX3TO0 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x174 }]
        }
        namespace eval TABLE {
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
                return 0x08040201
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x08040201
        }
    }
    namespace export ANTTX3TO0
    proc ANTTX3TO0 { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x178 }]
    }
    namespace eval ANTTX3TO0 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x178 }]
        }
        namespace eval TABLE {
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
                return 0x08040201
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x08040201
        }
    }
    namespace export ANTRX7TO4
    proc ANTRX7TO4 { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x17c }]
    }
    namespace eval ANTRX7TO4 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x17c }]
        }
        namespace eval TABLE {
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
                return 0x80402010
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x80402010
        }
    }
    namespace export ANTTX7TO4
    proc ANTTX7TO4 { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x180 }]
    }
    namespace eval ANTTX7TO4 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x180 }]
        }
        namespace eval TABLE {
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
                return 0x80402010
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x80402010
        }
    }
    namespace export ANTIDLE
    proc ANTIDLE { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x184 }]
    }
    namespace eval ANTIDLE {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x184 }]
        }
        namespace eval TABLE {
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
    namespace export ANTID3TO0
    proc ANTID3TO0 { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x188 }]
    }
    namespace eval ANTID3TO0 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x188 }]
        }
        namespace eval ANT0 {
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
        namespace eval ANT1 {
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
                return 0x00000001
            }
        }
        namespace eval ANT2 {
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
                return 0x00000002
            }
        }
        namespace eval ANT3 {
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
                return 0x00000003
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x03020100
        }
    }
    namespace export ANTID7TO4
    proc ANTID7TO4 { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x18c }]
    }
    namespace eval ANTID7TO4 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x18c }]
        }
        namespace eval ANT4 {
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
                return 0x00000004
            }
        }
        namespace eval ANT5 {
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
                return 0x00000005
            }
        }
        namespace eval ANT6 {
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
                return 0x00000006
            }
        }
        namespace eval ANT7 {
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
                return 0x00000007
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x07060504
        }
    }
    namespace export WHT_CTRL
    proc WHT_CTRL { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x190 }]
    }
    namespace eval WHT_CTRL {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x190 }]
        }
        namespace eval INIT_EN {
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
        namespace eval INIT_SD {
            namespace export SHIFT
            proc SHIFT {} {
                return 1
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 7
            }
            namespace export MASK
            proc MASK {} {
                return 0x000000fe
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x000000fe) >> 1}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 1) & 0x000000fe}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x000000fe) | (($field_val << 1) & 0x000000fe)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x000000fe) | (($field_val << 1) & 0x000000fe)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 1) & ~0x000000fe)}]
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
    namespace export DCCALRESULTS
    proc DCCALRESULTS { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x194 }]
    }
    namespace eval DCCALRESULTS {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x194 }]
        }
        namespace eval Q_OFF {
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
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval I_OFF {
            namespace export SHIFT
            proc SHIFT {} {
                return 8
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 6
            }
            namespace export MASK
            proc MASK {} {
                return 0x00003f00
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00003f00) >> 8}]
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
    namespace export DCCALRESULTS2
    proc DCCALRESULTS2 { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x198 }]
    }
    namespace eval DCCALRESULTS2 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x198 }]
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
        namespace eval AVG_Q {
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
        namespace eval AVG_I {
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
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x00000000
        }
    }
    namespace export TIA_RETENT_DCCALRESULTS
    proc TIA_RETENT_DCCALRESULTS { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x19c }]
    }
    namespace eval TIA_RETENT_DCCALRESULTS {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x19c }]
        }
        namespace eval Q_OFF {
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
        namespace eval I_OFF {
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
        namespace eval BB2GAIN {
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
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval DONE {
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
    namespace export TIA_DCCALRESULTS2
    proc TIA_DCCALRESULTS2 { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x1a0 }]
    }
    namespace eval TIA_DCCALRESULTS2 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x1a0 }]
        }
        namespace eval AVG_Q {
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
        namespace eval AVG_I {
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
        namespace eval DONE {
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
    namespace export TIA_DCCALRESULTS3
    proc TIA_DCCALRESULTS3 { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x1a4 }]
    }
    namespace eval TIA_DCCALRESULTS3 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x1a4 }]
        }
        namespace eval BB1Q_DCOC {
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
        namespace eval BB1I_DCOC {
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
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x00000000
        }
    }
    namespace export TIA_LP_RETENT_DCCALRESULTS
    proc TIA_LP_RETENT_DCCALRESULTS { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x1a8 }]
    }
    namespace eval TIA_LP_RETENT_DCCALRESULTS {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x1a8 }]
        }
        namespace eval Q_OFF {
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
        namespace eval I_OFF {
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
        namespace eval BB2GAIN {
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
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval DONE {
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
    namespace export TIA_LP_DCCALRESULTS2
    proc TIA_LP_DCCALRESULTS2 { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x1ac }]
    }
    namespace eval TIA_LP_DCCALRESULTS2 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x1ac }]
        }
        namespace eval AVG_Q {
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
        namespace eval AVG_I {
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
        namespace eval DONE {
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
    namespace export PGA_RETENT_DCCALRESULTS
    proc PGA_RETENT_DCCALRESULTS { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x1b0 }]
    }
    namespace eval PGA_RETENT_DCCALRESULTS {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x1b0 }]
        }
        namespace eval Q_OFF {
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
        namespace eval I_OFF {
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
        namespace eval BB2GAIN {
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
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval DONE {
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
    namespace export PGA_DCCALRESULTS2
    proc PGA_DCCALRESULTS2 { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x1b4 }]
    }
    namespace eval PGA_DCCALRESULTS2 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x1b4 }]
        }
        namespace eval AVG_Q {
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
        namespace eval AVG_I {
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
        namespace eval DONE {
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
    namespace export PGA_DCCALRESULTS3
    proc PGA_DCCALRESULTS3 { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x1b8 }]
    }
    namespace eval PGA_DCCALRESULTS3 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x1b8 }]
        }
        namespace eval BB2Q_DCOC {
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
        namespace eval BB2I_DCOC {
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
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x00000000
        }
    }
    namespace export PGA_LP_RETENT_DCCALRESULTS
    proc PGA_LP_RETENT_DCCALRESULTS { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x1bc }]
    }
    namespace eval PGA_LP_RETENT_DCCALRESULTS {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x1bc }]
        }
        namespace eval Q_OFF {
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
        namespace eval I_OFF {
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
        namespace eval BB2GAIN {
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
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval DONE {
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
    namespace export PGA_LP_DCCALRESULTS2
    proc PGA_LP_DCCALRESULTS2 { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x1c0 }]
    }
    namespace eval PGA_LP_DCCALRESULTS2 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x1c0 }]
        }
        namespace eval AVG_Q {
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
        namespace eval AVG_I {
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
        namespace eval DONE {
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
    namespace export NOTCH_RETENT_DCCALRESULTS
    proc NOTCH_RETENT_DCCALRESULTS { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x1c4 }]
    }
    namespace eval NOTCH_RETENT_DCCALRESULTS {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x1c4 }]
        }
        namespace eval CTN {
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
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval DONE {
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
    namespace export NOTCH_DCCALRESULTS2
    proc NOTCH_DCCALRESULTS2 { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x1c8 }]
    }
    namespace eval NOTCH_DCCALRESULTS2 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x1c8 }]
        }
        namespace eval AVG {
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
        namespace eval DONE {
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
    namespace export AGCSTATUS
    proc AGCSTATUS { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x1cc }]
    }
    namespace eval AGCSTATUS {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x1cc }]
        }
        namespace eval RSSI {
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
        namespace eval RXGAIN {
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
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval BASELINE_PWR {
            namespace export SHIFT
            proc SHIFT {} {
                return 15
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 8
            }
            namespace export MASK
            proc MASK {} {
                return 0x007f8000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x007f8000) >> 15}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval SAT_DETECTED {
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
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval PEAK_DETECTED {
            namespace export SHIFT
            proc SHIFT {} {
                return 24
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 1
            }
            namespace export MASK
            proc MASK {} {
                return 0x01000000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x01000000) >> 24}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval STRONG_BLOCKER {
            namespace export SHIFT
            proc SHIFT {} {
                return 25
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 1
            }
            namespace export MASK
            proc MASK {} {
                return 0x02000000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x02000000) >> 25}]
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
    namespace export MEASFREQ
    proc MEASFREQ { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x1d0 }]
    }
    namespace eval MEASFREQ {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x1d0 }]
        }
        namespace eval FREQ_OFFSET {
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
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval DCOFFTRK_I {
            namespace export SHIFT
            proc SHIFT {} {
                return 13
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 8
            }
            namespace export MASK
            proc MASK {} {
                return 0x001fe000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x001fe000) >> 13}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval DCOFFTRK_Q {
            namespace export SHIFT
            proc SHIFT {} {
                return 21
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 8
            }
            namespace export MASK
            proc MASK {} {
                return 0x1fe00000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x1fe00000) >> 21}]
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
    namespace export EXPER
    proc EXPER { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x1d4 }]
    }
    namespace eval EXPER {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x1d4 }]
        }
        namespace eval ADJUST_TO_TARGET_EN {
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
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 0) & 0x00000007}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00000007) | (($field_val << 0) & 0x00000007)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x00000007) | (($field_val << 0) & 0x00000007)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 0) & ~0x00000007)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000007
            }
        }
        namespace eval NEED_PWR_INCREASE_FOR_AA {
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
        namespace eval RXGAIN_LOW_MARK {
            namespace export SHIFT
            proc SHIFT {} {
                return 4
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 7
            }
            namespace export MASK
            proc MASK {} {
                return 0x000007f0
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x000007f0) >> 4}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 4) & 0x000007f0}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x000007f0) | (($field_val << 4) & 0x000007f0)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x000007f0) | (($field_val << 4) & 0x000007f0)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 4) & ~0x000007f0)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval BASELINE_PWR_LOW_MARK {
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
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x0007f800) | (($field_val << 11) & 0x0007f800)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 11) & ~0x0007f800)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000080
            }
        }
        namespace eval FORCE_CLKGAT_EN {
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
        namespace eval PD_GAIN_DROP_IS_RELATIVE {
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
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x00040007
        }
    }
    namespace export SPARE0
    proc SPARE0 { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x1d8 }]
    }
    namespace eval SPARE0 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x1d8 }]
        }
        namespace eval VAL {
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
    namespace export DEBUG
    proc DEBUG { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x1dc }]
    }
    namespace eval DEBUG {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x1dc }]
        }
        namespace eval SELECT {
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
                return 0x00000000
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x00000000
        }
    }
    namespace export LC2LC
    proc LC2LC { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x1e0 }]
    }
    namespace eval LC2LC {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x1e0 }]
        }
        namespace eval CNTL {
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
    namespace export IRQ
    proc IRQ { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x1e4 }]
    }
    namespace eval IRQ {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x1e4 }]
        }
        namespace eval DCCAL_DONE {
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
    namespace export IRQM
    proc IRQM { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x1e8 }]
    }
    namespace eval IRQM {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x1e8 }]
        }
        namespace eval DCCAL_DONE {
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
    namespace export IRQC
    proc IRQC { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x1ec }]
    }
    namespace eval IRQC {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x1ec }]
        }
        namespace eval DCCAL_DONE {
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
    namespace export ERR_INJ
    proc ERR_INJ { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x1f0 }]
    }
    namespace eval ERR_INJ {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x1f0 }]
        }
        namespace eval EN {
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
        namespace eval LFSR_SEED {
            namespace export SHIFT
            proc SHIFT {} {
                return 1
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 16
            }
            namespace export MASK
            proc MASK {} {
                return 0x0001fffe
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x0001fffe) >> 1}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 1) & 0x0001fffe}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x0001fffe) | (($field_val << 1) & 0x0001fffe)}]
            }
            namespace export MODIFY_TGT
            proc MODIFY_TGT {addr field_val} {
                mww $addr [expr {([mrw $addr] & ~0x0001fffe) | (($field_val << 1) & 0x0001fffe)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 1) & ~0x0001fffe)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000005
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x0000000a
        }
    }
    namespace export DEBUG32
    proc DEBUG32 { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x1f4 }]
    }
    namespace eval DEBUG32 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x1f4 }]
        }
        namespace eval SELECT0 {
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
                return 0x00000000
            }
        }
        namespace eval SELECT1 {
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
                return 0x00000000
            }
        }
        namespace eval SELECT2 {
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
        namespace eval SELECT3 {
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
        namespace eval NEGEDGE_Q {
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
        namespace eval NEGEDGE_TXDM {
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
        namespace eval NEGEDGE_RXGM {
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
    namespace export DUO
    proc DUO { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0x1f8 }]
    }
    namespace eval DUO {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0x1f8 }]
        }
        namespace eval PATH_LOSS {
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
                return 0x00000046
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x00000046
        }
    }
    namespace export CORE_ID
    proc CORE_ID { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
        return [expr { [expr $base] + 0xffc }]
    }
    namespace eval CORE_ID {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_MDM_NONSECURE::BASE]} } {
            return [expr { [expr $base] + 0xffc }]
        }
        namespace eval CORE_ID {
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
                return 0x4d444d20
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x4d444d20
        }
    }
}
