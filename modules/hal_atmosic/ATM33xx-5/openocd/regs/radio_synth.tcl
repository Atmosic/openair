namespace eval CMSDK_RADIO_SYNTH {
    namespace export BASE
    proc BASE {} {
        return 0x0
    }
    namespace export BLOCK
    proc BLOCK {} {
        return 1
    }
    namespace export SYNTH_CTRL_0
    proc SYNTH_CTRL_0 { {base [::CMSDK_RADIO_SYNTH::BASE]} } {
        return [expr { [expr $base] + 0x0 }]
    }
    namespace eval SYNTH_CTRL_0 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_RADIO_SYNTH::BASE]} } {
            return [expr { [expr $base] + 0x0 }]
        }
        namespace eval DISABLESYNTHANALOG {
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
        namespace eval DISABLEVCO {
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
        namespace eval DISABLECP {
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
        namespace eval DISABLETXMODHF {
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
        namespace eval DISABLETXMODLF {
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
        namespace eval DISABLESDM {
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
        namespace eval CHANOVR {
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
        namespace eval CHANINT_8MHZ {
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
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 7) & ~0x0000ff80)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000096
            }
        }
        namespace eval CHANFRAC_8MHZ {
            namespace export SHIFT
            proc SHIFT {} {
                return 16
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 15
            }
            namespace export MASK
            proc MASK {} {
                return 0x7fff0000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x7fff0000) >> 16}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 16) & 0x7fff0000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x7fff0000) | (($field_val << 16) & 0x7fff0000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 16) & ~0x7fff0000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval ALWAYSSHORTR {
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
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 31) & ~0x80000000)}]
            }
            namespace export SET
            proc SET {var_name} {
                upvar $var_name var
                set var [expr {($var & ~0x80000000) | (1 << 31)}]
            }
            namespace export CLR
            proc CLR {var_name} {
                upvar $var_name var
                set var [expr {$var & ~0x80000000}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x00004b00
        }
    }
    namespace export SYNTH_CTRL_1
    proc SYNTH_CTRL_1 { {base [::CMSDK_RADIO_SYNTH::BASE]} } {
        return [expr { [expr $base] + 0x4 }]
    }
    namespace eval SYNTH_CTRL_1 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_RADIO_SYNTH::BASE]} } {
            return [expr { [expr $base] + 0x4 }]
        }
        namespace eval ATBSEL {
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
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 0) & ~0x0000000f)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval MONITORVC {
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
        namespace eval MONALARMCOUNTMAX {
            namespace export SHIFT
            proc SHIFT {} {
                return 5
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 2
            }
            namespace export MASK
            proc MASK {} {
                return 0x00000060
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00000060) >> 5}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 5) & 0x00000060}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00000060) | (($field_val << 5) & 0x00000060)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 5) & ~0x00000060)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000002
            }
        }
        namespace eval MONSTATELENGTH_STEADYSTATE_X4U {
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
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 7) & ~0x00000380)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000004
            }
        }
        namespace eval MONVCREFHI {
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
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 10) & ~0x00000c00)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000002
            }
        }
        namespace eval MONVCREFLO {
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
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 12) & ~0x00003000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000002
            }
        }
        namespace eval OVERRIDEFSM {
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
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 14) & ~0x00004000)}]
            }
            namespace export SET
            proc SET {var_name} {
                upvar $var_name var
                set var [expr {($var & ~0x00004000) | (1 << 14)}]
            }
            namespace export CLR
            proc CLR {var_name} {
                upvar $var_name var
                set var [expr {$var & ~0x00004000}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval VCOCAPS_OV {
            namespace export SHIFT
            proc SHIFT {} {
                return 15
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 7
            }
            namespace export MASK
            proc MASK {} {
                return 0x003f8000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x003f8000) >> 15}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 15) & 0x003f8000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x003f8000) | (($field_val << 15) & 0x003f8000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 15) & ~0x003f8000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000040
            }
        }
        namespace eval PINVC_OV {
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
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 22) & ~0x00400000)}]
            }
            namespace export SET
            proc SET {var_name} {
                upvar $var_name var
                set var [expr {($var & ~0x00400000) | (1 << 22)}]
            }
            namespace export CLR
            proc CLR {var_name} {
                upvar $var_name var
                set var [expr {$var & ~0x00400000}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval SHORTR_OV {
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
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 23) & ~0x00800000)}]
            }
            namespace export SET
            proc SET {var_name} {
                upvar $var_name var
                set var [expr {($var & ~0x00800000) | (1 << 23)}]
            }
            namespace export CLR
            proc CLR {var_name} {
                upvar $var_name var
                set var [expr {$var & ~0x00800000}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval DIVRST_OV {
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
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 24) & 0x01000000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x01000000) | (($field_val << 24) & 0x01000000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 24) & ~0x01000000)}]
            }
            namespace export SET
            proc SET {var_name} {
                upvar $var_name var
                set var [expr {($var & ~0x01000000) | (1 << 24)}]
            }
            namespace export CLR
            proc CLR {var_name} {
                upvar $var_name var
                set var [expr {$var & ~0x01000000}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval PFDRST_OV {
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
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 25) & ~0x02000000)}]
            }
            namespace export SET
            proc SET {var_name} {
                upvar $var_name var
                set var [expr {($var & ~0x02000000) | (1 << 25)}]
            }
            namespace export CLR
            proc CLR {var_name} {
                upvar $var_name var
                set var [expr {$var & ~0x02000000}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval ENSD_OV {
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
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 26) & ~0x04000000)}]
            }
            namespace export SET
            proc SET {var_name} {
                upvar $var_name var
                set var [expr {($var & ~0x04000000) | (1 << 26)}]
            }
            namespace export CLR
            proc CLR {var_name} {
                upvar $var_name var
                set var [expr {$var & ~0x04000000}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval DIVENFORCE {
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
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 27) & ~0x08000000)}]
            }
            namespace export SET
            proc SET {var_name} {
                upvar $var_name var
                set var [expr {($var & ~0x08000000) | (1 << 27)}]
            }
            namespace export CLR
            proc CLR {var_name} {
                upvar $var_name var
                set var [expr {$var & ~0x08000000}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval SYNTHONFORCE {
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
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 28) & ~0x10000000)}]
            }
            namespace export SET
            proc SET {var_name} {
                upvar $var_name var
                set var [expr {($var & ~0x10000000) | (1 << 28)}]
            }
            namespace export CLR
            proc CLR {var_name} {
                upvar $var_name var
                set var [expr {$var & ~0x10000000}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval OPENLOOPSS {
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
                return 0x00000000
            }
        }
        namespace eval SPAREEXT {
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
            return 0x00202a40
        }
    }
    namespace export SYNTH_CTRL_2
    proc SYNTH_CTRL_2 { {base [::CMSDK_RADIO_SYNTH::BASE]} } {
        return [expr { [expr $base] + 0x8 }]
    }
    namespace eval SYNTH_CTRL_2 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_RADIO_SYNTH::BASE]} } {
            return [expr { [expr $base] + 0x8 }]
        }
        namespace eval TXMODDATAOVR {
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
        namespace eval TXMODDATA {
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
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 1) & ~0x000000fe)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000020
            }
        }
        namespace eval LOCKTESTEN {
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
        namespace eval DISABLEVCOMODCLK {
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
                return 0x00000000
            }
        }
        namespace eval RXLO_COMBINEIQ {
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
        namespace eval OVERRIDERXLOGEN {
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
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 11) & ~0x00000800)}]
            }
            namespace export SET
            proc SET {var_name} {
                upvar $var_name var
                set var [expr {($var & ~0x00000800) | (1 << 11)}]
            }
            namespace export CLR
            proc CLR {var_name} {
                upvar $var_name var
                set var [expr {$var & ~0x00000800}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval RXLO_ENIDUAL_OV {
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
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 12) & ~0x00001000)}]
            }
            namespace export SET
            proc SET {var_name} {
                upvar $var_name var
                set var [expr {($var & ~0x00001000) | (1 << 12)}]
            }
            namespace export CLR
            proc CLR {var_name} {
                upvar $var_name var
                set var [expr {$var & ~0x00001000}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval RXLO_ENQDUAL_OV {
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
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 13) & ~0x00002000)}]
            }
            namespace export SET
            proc SET {var_name} {
                upvar $var_name var
                set var [expr {($var & ~0x00002000) | (1 << 13)}]
            }
            namespace export CLR
            proc CLR {var_name} {
                upvar $var_name var
                set var [expr {$var & ~0x00002000}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval RXLO_ENSINGLELP_OV {
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
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 14) & ~0x00004000)}]
            }
            namespace export SET
            proc SET {var_name} {
                upvar $var_name var
                set var [expr {($var & ~0x00004000) | (1 << 14)}]
            }
            namespace export CLR
            proc CLR {var_name} {
                upvar $var_name var
                set var [expr {$var & ~0x00004000}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval RXLO_ENSINGLE_OV {
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
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 15) & ~0x00008000)}]
            }
            namespace export SET
            proc SET {var_name} {
                upvar $var_name var
                set var [expr {($var & ~0x00008000) | (1 << 15)}]
            }
            namespace export CLR
            proc CLR {var_name} {
                upvar $var_name var
                set var [expr {$var & ~0x00008000}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval DISABLERXLOBUF {
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
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 16) & ~0x00010000)}]
            }
            namespace export SET
            proc SET {var_name} {
                upvar $var_name var
                set var [expr {($var & ~0x00010000) | (1 << 16)}]
            }
            namespace export CLR
            proc CLR {var_name} {
                upvar $var_name var
                set var [expr {$var & ~0x00010000}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval PA_BYPASSDUTY {
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
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 17) & ~0x00020000)}]
            }
            namespace export SET
            proc SET {var_name} {
                upvar $var_name var
                set var [expr {($var & ~0x00020000) | (1 << 17)}]
            }
            namespace export CLR
            proc CLR {var_name} {
                upvar $var_name var
                set var [expr {$var & ~0x00020000}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval ENPADRIVEROVRVALUE {
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
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 18) & ~0x00040000)}]
            }
            namespace export SET
            proc SET {var_name} {
                upvar $var_name var
                set var [expr {($var & ~0x00040000) | (1 << 18)}]
            }
            namespace export CLR
            proc CLR {var_name} {
                upvar $var_name var
                set var [expr {$var & ~0x00040000}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval ENPADRIVER_SEL {
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
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 19) & ~0x00180000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000002
            }
        }
        namespace eval ENPAOVRVALUE {
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
                return 0x00000000
            }
        }
        namespace eval ENPA_SEL {
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
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 22) & ~0x00c00000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000002
            }
        }
        namespace eval ENPALDOOVRVALUE {
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
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 24) & 0x01000000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x01000000) | (($field_val << 24) & 0x01000000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 24) & ~0x01000000)}]
            }
            namespace export SET
            proc SET {var_name} {
                upvar $var_name var
                set var [expr {($var & ~0x01000000) | (1 << 24)}]
            }
            namespace export CLR
            proc CLR {var_name} {
                upvar $var_name var
                set var [expr {$var & ~0x01000000}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval ENPALDO_SEL {
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
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 25) & ~0x06000000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000002
            }
        }
        namespace eval VCOTUNEMARGIN_X16M {
            namespace export SHIFT
            proc SHIFT {} {
                return 27
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 3
            }
            namespace export MASK
            proc MASK {} {
                return 0x38000000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x38000000) >> 27}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 27) & 0x38000000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x38000000) | (($field_val << 27) & 0x38000000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 27) & ~0x38000000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000004
            }
        }
        namespace eval DONTROUNDUP_MODGAINCAL {
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
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 30) & ~0x40000000)}]
            }
            namespace export SET
            proc SET {var_name} {
                upvar $var_name var
                set var [expr {($var & ~0x40000000) | (1 << 30)}]
            }
            namespace export CLR
            proc CLR {var_name} {
                upvar $var_name var
                set var [expr {$var & ~0x40000000}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval DONTROUNDUP_VCOCAPSCAL {
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
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 31) & ~0x80000000)}]
            }
            namespace export SET
            proc SET {var_name} {
                upvar $var_name var
                set var [expr {($var & ~0x80000000) | (1 << 31)}]
            }
            namespace export CLR
            proc CLR {var_name} {
                upvar $var_name var
                set var [expr {$var & ~0x80000000}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000001
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0xa4900040
        }
    }
    namespace export SYNTH_CTRL_3
    proc SYNTH_CTRL_3 { {base [::CMSDK_RADIO_SYNTH::BASE]} } {
        return [expr { [expr $base] + 0xc }]
    }
    namespace eval SYNTH_CTRL_3 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_RADIO_SYNTH::BASE]} } {
            return [expr { [expr $base] + 0xc }]
        }
        namespace eval MODVARSIZE_CAL {
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
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 0) & ~0x0000000f)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x0000000f
            }
        }
        namespace eval MODVARBIAS_1M {
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
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 4) & ~0x000000f0)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000008
            }
        }
        namespace eval MODBUCKETSIZE_1M {
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
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 8) & ~0x00001f00)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000007
            }
        }
        namespace eval MODDELAYHF_1M {
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
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 13) & ~0x00002000)}]
            }
            namespace export SET
            proc SET {var_name} {
                upvar $var_name var
                set var [expr {($var & ~0x00002000) | (1 << 13)}]
            }
            namespace export CLR
            proc CLR {var_name} {
                upvar $var_name var
                set var [expr {$var & ~0x00002000}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval MODRELPATHDELAY_1M {
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
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 14) & ~0x0001c000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval MODVARBIAS_2M {
            namespace export SHIFT
            proc SHIFT {} {
                return 17
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 4
            }
            namespace export MASK
            proc MASK {} {
                return 0x001e0000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x001e0000) >> 17}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 17) & 0x001e0000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x001e0000) | (($field_val << 17) & 0x001e0000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 17) & ~0x001e0000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000008
            }
        }
        namespace eval MODBUCKETSIZE_2M {
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
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 21) & ~0x03e00000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000007
            }
        }
        namespace eval MODDELAYHF_2M {
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
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 26) & ~0x04000000)}]
            }
            namespace export SET
            proc SET {var_name} {
                upvar $var_name var
                set var [expr {($var & ~0x04000000) | (1 << 26)}]
            }
            namespace export CLR
            proc CLR {var_name} {
                upvar $var_name var
                set var [expr {$var & ~0x04000000}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval MODRELPATHDELAY_2M {
            namespace export SHIFT
            proc SHIFT {} {
                return 27
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 3
            }
            namespace export MASK
            proc MASK {} {
                return 0x38000000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x38000000) >> 27}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 27) & 0x38000000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x38000000) | (($field_val << 27) & 0x38000000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 27) & ~0x38000000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval TXRATE_HADM {
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
            return 0x40f0078f
        }
    }
    namespace export SYNTH_READOUT
    proc SYNTH_READOUT { {base [::CMSDK_RADIO_SYNTH::BASE]} } {
        return [expr { [expr $base] + 0x10 }]
    }
    namespace eval SYNTH_READOUT {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_RADIO_SYNTH::BASE]} } {
            return [expr { [expr $base] + 0x10 }]
        }
        namespace eval FSM_STATE {
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
        namespace eval FSM_VCOCAPS {
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
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval FSM_DIVCAPSEARCH {
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
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval FSM_ENSYNTHANALOG {
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
        namespace eval FSM_PINVC {
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
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval FSM_SHORTR {
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
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval FSM_DIVRST {
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
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval FSM_DIVENTOGGLE {
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
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval FSM_PFDRST {
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
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval FSM_ENSD {
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
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval FSM_VC2HI_SYNC {
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
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval FSM_VC2LO_SYNC {
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
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval FSM_NOLOCK_SYNC {
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
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval TXMODGAIN {
            namespace export SHIFT
            proc SHIFT {} {
                return 23
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 5
            }
            namespace export MASK
            proc MASK {} {
                return 0x0f800000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x0f800000) >> 23}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval VCOCAPSCOARSE {
            namespace export SHIFT
            proc SHIFT {} {
                return 28
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 3
            }
            namespace export MASK
            proc MASK {} {
                return 0x70000000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x70000000) >> 28}]
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
    proc CORE_ID { {base [::CMSDK_RADIO_SYNTH::BASE]} } {
        return [expr { [expr $base] + 0x14 }]
    }
    namespace eval CORE_ID {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_RADIO_SYNTH::BASE]} } {
            return [expr { [expr $base] + 0x14 }]
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
                return 0x53594e54
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x53594e54
        }
    }
}
