namespace eval CMSDK_RADIO_RX {
    namespace export BASE
    proc BASE {} {
        return 0x0
    }
    namespace export BLOCK
    proc BLOCK {} {
        return 0
    }
    namespace export MODE_CTRL
    proc MODE_CTRL { {base [::CMSDK_RADIO_RX::BASE]} } {
        return [expr { [expr $base] + 0x0 }]
    }
    namespace eval MODE_CTRL {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_RADIO_RX::BASE]} } {
            return [expr { [expr $base] + 0x0 }]
        }
        namespace eval LNA_EN_OVR {
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
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 0) & ~0x00000003)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval LNAPD_EN_OVR {
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
        namespace eval MIXER_EN_OVR {
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
        namespace eval MIXER_ENIDUAL_OVR_VAL {
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
        namespace eval MIXER_ENQDUAL_OVR_VAL {
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
        namespace eval MIXER_ENSINGLE_OVR_VAL {
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
        namespace eval EN_TIAI_OVR {
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
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 8) & ~0x00000300)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval EN_TIAQ_OVR {
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
                return 0x00000000
            }
        }
        namespace eval TIAPD_EN_OVR {
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
                return 0x00000000
            }
        }
        namespace eval EN_PGAI_OVR {
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
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 14) & ~0x0000c000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval EN_PGAQ_OVR {
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
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 16) & ~0x00030000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval EN_OSDACI_OVR {
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
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 18) & ~0x000c0000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval EN_OSDACQ_OVR {
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
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 20) & ~0x00300000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval ADCI_EN_OVR {
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
                return 0x00000000
            }
        }
        namespace eval ADCQ_EN_OVR {
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
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 24) & ~0x03000000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval ADCREF_EN_OVR {
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
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 26) & ~0x0c000000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval ADC_RSTB_OVR {
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
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 28) & ~0x30000000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval RXBIAS_EN_OVR {
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
            return 0x00000000
        }
    }
    namespace export MODE_CTRL2
    proc MODE_CTRL2 { {base [::CMSDK_RADIO_RX::BASE]} } {
        return [expr { [expr $base] + 0x4 }]
    }
    namespace eval MODE_CTRL2 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_RADIO_RX::BASE]} } {
            return [expr { [expr $base] + 0x4 }]
        }
        namespace eval MODE1M_OVR {
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
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 0) & ~0x00000003)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval SWAPIQ {
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
        namespace eval COMBINEIQ {
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
        namespace eval MIXER_ENSINGLELP_OVR_VAL {
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
        namespace eval LNA_OFFGAIN {
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
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x00000000
        }
    }
    namespace export CAL_CFG
    proc CAL_CFG { {base [::CMSDK_RADIO_RX::BASE]} } {
        return [expr { [expr $base] + 0x8 }]
    }
    namespace eval CAL_CFG {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_RADIO_RX::BASE]} } {
            return [expr { [expr $base] + 0x8 }]
        }
        namespace eval CALDC_LNA_EN {
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
        namespace eval CALDC_MIX_EN {
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
                return 0x00000001
            }
        }
        namespace eval CALDC_TIA_EN {
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
                return 0x00000001
            }
        }
        namespace eval CALDC_TIA_OPEN_RCC {
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
        namespace eval CALDC_TIA_OPEN_RFB {
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
        namespace eval CALDC_PGA_EN {
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
                return 0x00000001
            }
        }
        namespace eval CALDC_PGA_OPEN_RCC {
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
        namespace eval CALDC_PGA_OPEN_RFB {
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
        namespace eval CALDC_ADC_EN {
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
                return 0x00000001
            }
        }
        namespace eval PGA_DCOS_CAL_OVR {
            namespace export SHIFT
            proc SHIFT {} {
                return 9
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 2
            }
            namespace export MASK
            proc MASK {} {
                return 0x00000600
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00000600) >> 9}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 9) & 0x00000600}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00000600) | (($field_val << 9) & 0x00000600)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 9) & ~0x00000600)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval CALFC_LNA_EN {
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
        namespace eval CALFC_MIX_EN {
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
        namespace eval CALFC_TIA_OPEN_RCC {
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
                return 0x00000001
            }
        }
        namespace eval CALFC_TIA_OPEN_RFB {
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
                return 0x00000001
            }
        }
        namespace eval CALFC_PGA_OPEN_RCC {
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
                return 0x00000001
            }
        }
        namespace eval CALFC_PGA_OPEN_RFB {
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
                return 0x00000001
            }
        }
        namespace eval CALFC_PGA_CONNECTRCC2RFB {
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
        namespace eval CALFC_PGA_OP_CAL {
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
        namespace eval CALFC_INIT_OSC {
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
        namespace eval CALFC_START_OSC {
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
        namespace eval CALFC_ADC_EN {
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
        namespace eval CALFC_NOTCH_EN {
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
        namespace eval CALRX_LNA_EN {
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
        namespace eval CALRX_MIX_EN {
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
                return 0x00000001
            }
        }
        namespace eval CALRX_TIA_EN {
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
                return 0x00000001
            }
        }
        namespace eval CALRX_TIA_OPEN_RCC {
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
        namespace eval CALRX_TIA_OPEN_RFB {
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
        namespace eval CALRX_PGA_EN {
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
                return 0x00000001
            }
        }
        namespace eval CALRX_PGA_OPEN_RCC {
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
        namespace eval CALRX_PGA_OPEN_RFB {
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
        namespace eval CALRX_ADC_EN {
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
            return 0x9321e126
        }
    }
    namespace export GAIN_CTRL
    proc GAIN_CTRL { {base [::CMSDK_RADIO_RX::BASE]} } {
        return [expr { [expr $base] + 0xc }]
    }
    namespace eval GAIN_CTRL {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_RADIO_RX::BASE]} } {
            return [expr { [expr $base] + 0xc }]
        }
        namespace eval RFGAIN_OV_EN {
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
        namespace eval BBGAIN_OV_EN {
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
        namespace eval LNAGAIN_OVR {
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
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 2) & ~0x0000001c)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000007
            }
        }
        namespace eval TIA_GAIN_OVR {
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
                return 0x00000000
            }
        }
        namespace eval PGA_GAIN_OVR {
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
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 7) & ~0x00000f80)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000018
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x00000c1c
        }
    }
    namespace export ANA_CTRL
    proc ANA_CTRL { {base [::CMSDK_RADIO_RX::BASE]} } {
        return [expr { [expr $base] + 0x10 }]
    }
    namespace eval ANA_CTRL {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_RADIO_RX::BASE]} } {
            return [expr { [expr $base] + 0x10 }]
        }
        namespace eval LNA_SHORTSRC {
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
        namespace eval LNA_CTUNE {
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
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 1) & ~0x0000000e)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000004
            }
        }
        namespace eval TIA_OPEN_RCC {
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
        namespace eval TIA_OPEN_RFB {
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
        namespace eval PGA_OPEN_RCC {
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
        namespace eval PGA_OPEN_RFB {
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
        namespace eval TIA_PKDET_REF_CTRL {
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
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 8) & ~0x00000700)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval TESTIQ_CTRL {
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
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 11) & ~0x00003800)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval RX_ATBSEL {
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
        namespace eval ADC_ATBSEL {
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
                return 0x00000000
            }
        }
        namespace eval LNA_REFLVLBIASCAS {
            namespace export SHIFT
            proc SHIFT {} {
                return 21
            }
            namespace export WIDTH
            proc WIDTH {} {
                return 2
            }
            namespace export MASK
            proc MASK {} {
                return 0x00600000
            }
            namespace export READ
            proc READ {reg_val} {
                return [expr {($reg_val & 0x00600000) >> 21}]
            }
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 21) & 0x00600000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x00600000) | (($field_val << 21) & 0x00600000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 21) & ~0x00600000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000001
            }
        }
        namespace eval RX_SPARE {
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
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 23) & ~0xff800000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x00200008
        }
    }
    namespace export LNAGAIN0
    proc LNAGAIN0 { {base [::CMSDK_RADIO_RX::BASE]} } {
        return [expr { [expr $base] + 0x14 }]
    }
    namespace eval LNAGAIN0 {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_RADIO_RX::BASE]} } {
            return [expr { [expr $base] + 0x14 }]
        }
        namespace eval ENTRY0 {
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
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 0) & ~0x0000001f)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval ENTRY1 {
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
                return 0x00000001
            }
        }
        namespace eval ENTRY2 {
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
                return 0x00000003
            }
        }
        namespace eval ENTRY3 {
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
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 15) & ~0x000f8000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000007
            }
        }
        namespace eval ENTRY4 {
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
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 20) & 0x01f00000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x01f00000) | (($field_val << 20) & 0x01f00000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 20) & ~0x01f00000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x0000000f
            }
        }
        namespace eval ENTRY5 {
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
            namespace export WRITE
            proc WRITE {field_val} {
                return [expr {($field_val << 25) & 0x3e000000}]
            }
            namespace export MODIFY
            proc MODIFY {var_name field_val} {
                upvar $var_name var
                set var [expr {($var & ~0x3e000000) | (($field_val << 25) & 0x3e000000)}]
            }
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 25) & ~0x3e000000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x0000001f
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x3ef38c20
        }
    }
    namespace export RXBIAS
    proc RXBIAS { {base [::CMSDK_RADIO_RX::BASE]} } {
        return [expr { [expr $base] + 0x18 }]
    }
    namespace eval RXBIAS {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_RADIO_RX::BASE]} } {
            return [expr { [expr $base] + 0x18 }]
        }
        namespace eval SEL_IRTIAPKDET_REF {
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
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 0) & ~0x00000007)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000003
            }
        }
        namespace eval SEL_ICTIA {
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
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 3) & ~0x00000038)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000007
            }
        }
        namespace eval SEL_ICTIADCOC {
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
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 6) & ~0x000001c0)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000003
            }
        }
        namespace eval SEL_IRPGADCOC {
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
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 9) & ~0x00000e00)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000003
            }
        }
        namespace eval SEL_ICADC {
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
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 12) & ~0x00007000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000003
            }
        }
        namespace eval SEL_ICSPARE {
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
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 15) & ~0x00038000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000003
            }
        }
        namespace eval SEL_IRRXBB {
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
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 18) & ~0x001c0000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000003
            }
        }
        namespace eval SEL_IRADC {
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
            namespace export VERIFY
            proc VERIFY {field_val} {
                return [expr {!(($field_val << 21) & ~0x00e00000)}]
            }
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000003
            }
        }
        namespace eval SEL_IRSPARE {
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
                return 0x00000003
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x036db6fb
        }
    }
    namespace export STATUS
    proc STATUS { {base [::CMSDK_RADIO_RX::BASE]} } {
        return [expr { [expr $base] + 0x1c }]
    }
    namespace eval STATUS {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_RADIO_RX::BASE]} } {
            return [expr { [expr $base] + 0x1c }]
        }
        namespace eval TIA_PEAKDET {
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
        namespace eval LNA_EN {
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
        namespace eval LNA_PEAKDET {
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
        namespace eval MIX_EN {
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
        namespace eval TIAI_EN {
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
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval PGAI_EN {
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
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval ADCI_EN {
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
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval ADCREF_EN {
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
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval ADC_RSTB {
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
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval RXBIAS_EN {
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
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval LNAGAIN {
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
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval TIA_GAIN {
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
            namespace export RESET_VALUE
            proc RESET_VALUE {} {
                return 0x00000000
            }
        }
        namespace eval PGA_GAIN {
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
    proc CORE_ID { {base [::CMSDK_RADIO_RX::BASE]} } {
        return [expr { [expr $base] + 0x20 }]
    }
    namespace eval CORE_ID {
        namespace export REG_ADDR
        proc REG_ADDR { {base [::CMSDK_RADIO_RX::BASE]} } {
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
                return 0x52582020
            }
        }
        namespace export RESET_VALUE
        proc RESET_VALUE {} {
            return 0x52582020
        }
    }
}
