namespace eval SEC_PRIV_CTRL_SECURE {
    namespace export BASE
    proc BASE {} {
	return 0x50080000
    }
    namespace export AHBNSPPCEXP1
    proc AHBNSPPCEXP1 { {base [::SEC_PRIV_CTRL_SECURE::BASE]} } {
	return [expr { [expr $base] + 0x64 }]
    }
    namespace eval AHBNSPPCEXP1 {
	namespace export REG_ADDR
	proc REG_ADDR { {base [::SEC_PRIV_CTRL_SECURE::BASE]} } {
	    return [expr { [expr $base] + 0x64 }]
	}
	namespace eval GPIO0 {
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
		set var [expr {(var & ~0x00000001) | (($field_val << 0) & 0x00000001)}]
	    }
	    namespace export MODIFY_TGT
	    proc MODIFY_TGT {addr field_val} {
		mww $addr [expr {([mrw $addr] & ~0x00000001) | (($field_val << 0) & 0x00000001)}]
	    }
	    namespace export VERIFY
	    proc VERIFY {field_val} {
		return [expr {!(($field_val << 0) & ~0x00000001)}]
	    }
	    namespace export RESET_VALUE
	    proc RESET_VALUE {} {
		return 0x00000000
	    }
	}
	namespace eval GPIO1 {
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
		set var [expr {(var & ~0x00000002) | (($field_val << 1) & 0x00000002)}]
	    }
	    namespace export MODIFY_TGT
	    proc MODIFY_TGT {addr field_val} {
		mww $addr [expr {([mrw $addr] & ~0x00000002) | (($field_val << 1) & 0x00000002)}]
	    }
	    namespace export VERIFY
	    proc VERIFY {field_val} {
		return [expr {!(($field_val << 1) & ~0x00000002)}]
	    }
	    namespace export RESET_VALUE
	    proc RESET_VALUE {} {
		return 0x00000000
	    }
	}
	namespace eval SHA2 {
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
		set var [expr {(var & ~0x00000004) | (($field_val << 2) & 0x00000004)}]
	    }
	    namespace export MODIFY_TGT
	    proc MODIFY_TGT {addr field_val} {
		mww $addr [expr {([mrw $addr] & ~0x00000004) | (($field_val << 2) & 0x00000004)}]
	    }
	    namespace export VERIFY
	    proc VERIFY {field_val} {
		return [expr {!(($field_val << 2) & ~0x00000004)}]
	    }
	    namespace export RESET_VALUE
	    proc RESET_VALUE {} {
		return 0x00000000
	    }
	}
	namespace eval DMA {
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
		set var [expr {(var & ~0x00000008) | (($field_val << 3) & 0x00000008)}]
	    }
	    namespace export MODIFY_TGT
	    proc MODIFY_TGT {addr field_val} {
		mww $addr [expr {([mrw $addr] & ~0x00000008) | (($field_val << 3) & 0x00000008)}]
	    }
	    namespace export VERIFY
	    proc VERIFY {field_val} {
		return [expr {!(($field_val << 3) & ~0x00000008)}]
	    }
	    namespace export RESET_VALUE
	    proc RESET_VALUE {} {
		return 0x00000000
	    }
	}
	namespace eval AHB2APB_MPC {
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
		set var [expr {(var & ~0x00000010) | (($field_val << 4) & 0x00000010)}]
	    }
	    namespace export MODIFY_TGT
	    proc MODIFY_TGT {addr field_val} {
		mww $addr [expr {([mrw $addr] & ~0x00000010) | (($field_val << 4) & 0x00000010)}]
	    }
	    namespace export VERIFY
	    proc VERIFY {field_val} {
		return [expr {!(($field_val << 4) & ~0x00000010)}]
	    }
	    namespace export RESET_VALUE
	    proc RESET_VALUE {} {
		return 0x00000000
	    }
	}
	namespace eval PDM0 {
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
		set var [expr {(var & ~0x00000040) | (($field_val << 6) & 0x00000040)}]
	    }
	    namespace export MODIFY_TGT
	    proc MODIFY_TGT {addr field_val} {
		mww $addr [expr {([mrw $addr] & ~0x00000040) | (($field_val << 6) & 0x00000040)}]
	    }
	    namespace export VERIFY
	    proc VERIFY {field_val} {
		return [expr {!(($field_val << 6) & ~0x00000040)}]
	    }
	    namespace export RESET_VALUE
	    proc RESET_VALUE {} {
		return 0x00000000
	    }
	}
	namespace eval PDM1 {
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
		set var [expr {(var & ~0x00000080) | (($field_val << 7) & 0x00000080)}]
	    }
	    namespace export MODIFY_TGT
	    proc MODIFY_TGT {addr field_val} {
		mww $addr [expr {([mrw $addr] & ~0x00000080) | (($field_val << 7) & 0x00000080)}]
	    }
	    namespace export VERIFY
	    proc VERIFY {field_val} {
		return [expr {!(($field_val << 7) & ~0x00000080)}]
	    }
	    namespace export RESET_VALUE
	    proc RESET_VALUE {} {
		return 0x00000000
	    }
	}
	namespace eval I2S {
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
		set var [expr {(var & ~0x00000100) | (($field_val << 8) & 0x00000100)}]
	    }
	    namespace export MODIFY_TGT
	    proc MODIFY_TGT {addr field_val} {
		mww $addr [expr {([mrw $addr] & ~0x00000100) | (($field_val << 8) & 0x00000100)}]
	    }
	    namespace export VERIFY
	    proc VERIFY {field_val} {
		return [expr {!(($field_val << 8) & ~0x00000100)}]
	    }
	    namespace export RESET_VALUE
	    proc RESET_VALUE {} {
		return 0x00000000
	    }
	}
	namespace eval BLE52 {
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
		set var [expr {(var & ~0x00000200) | (($field_val << 9) & 0x00000200)}]
	    }
	    namespace export MODIFY_TGT
	    proc MODIFY_TGT {addr field_val} {
		mww $addr [expr {([mrw $addr] & ~0x00000200) | (($field_val << 9) & 0x00000200)}]
	    }
	    namespace export VERIFY
	    proc VERIFY {field_val} {
		return [expr {!(($field_val << 9) & ~0x00000200)}]
	    }
	    namespace export RESET_VALUE
	    proc RESET_VALUE {} {
		return 0x00000000
	    }
	}
    }
    namespace export APBNSPPCEXP0
    proc APBNSPPCEXP0 { {base [::SEC_PRIV_CTRL_SECURE::BASE]} } {
	return [expr { [expr $base] + 0x80 }]
    }
    namespace eval APBNSPPCEXP0 {
	namespace export REG_ADDR
	proc REG_ADDR { {base [::SEC_PRIV_CTRL_SECURE::BASE]} } {
	    return [expr { [expr $base] + 0x80 }]
	}
	namespace eval WRPR {
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
	    namespace export RESET_VALUE
	    proc RESET_VALUE {} {
		return 0x00000000
	    }
	}
	namespace eval UART0 {
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
	    namespace export RESET_VALUE
	    proc RESET_VALUE {} {
		return 0x00000000
	    }
	}
	namespace eval UART1 {
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
	    namespace export RESET_VALUE
	    proc RESET_VALUE {} {
		return 0x00000000
	    }
	}
	namespace eval PWM {
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
	    namespace export RESET_VALUE
	    proc RESET_VALUE {} {
		return 0x00000000
	    }
	}
	namespace eval SPI0 {
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
	    namespace export RESET_VALUE
	    proc RESET_VALUE {} {
		return 0x00000000
	    }
	}
	namespace eval KSM {
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
	    namespace export RESET_VALUE
	    proc RESET_VALUE {} {
		return 0x00000000
	    }
	}
	namespace eval SPI2 {
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
	    namespace export RESET_VALUE
	    proc RESET_VALUE {} {
		return 0x00000000
	    }
	}
	namespace eval QDEC {
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
	    namespace export RESET_VALUE
	    proc RESET_VALUE {} {
		return 0x00000000
	    }
	}
	namespace eval SPI1 {
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
	    namespace export RESET_VALUE
	    proc RESET_VALUE {} {
		return 0x00000000
	    }
	}
	namespace eval SLWTIMER {
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
	    namespace export RESET_VALUE
	    proc RESET_VALUE {} {
		return 0x00000000
	    }
	}
	namespace eval QSPI {
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
	    namespace export RESET_VALUE
	    proc RESET_VALUE {} {
		return 0x00000000
	    }
	}
    }
    namespace export APBNSPPCEXP1
    proc APBNSPPCEXP1 { {base [::SEC_PRIV_CTRL_SECURE::BASE]} } {
	return [expr { [expr $base] + 0x84 }]
    }
    namespace eval APBNSPPCEXP1 {
	namespace export REG_ADDR
	proc REG_ADDR { {base [::SEC_PRIV_CTRL_SECURE::BASE]} } {
	    return [expr { [expr $base] + 0x84 }]
	}
	namespace eval I2C0 {
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
	    namespace export RESET_VALUE
	    proc RESET_VALUE {} {
		return 0x00000000
	    }
	}
	namespace eval I2C1 {
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
		return [expr {($field_val << 0) & 0x00000002}]
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
	    namespace export RESET_VALUE
	    proc RESET_VALUE {} {
		return 0x00000000
	    }
	}
	namespace eval NVM {
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
	    namespace export RESET_VALUE
	    proc RESET_VALUE {} {
		return 0x00000000
	    }
	}
	namespace eval WRPR {
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
	    namespace export RESET_VALUE
	    proc RESET_VALUE {} {
		return 0x00000000
	    }
	}
	namespace eval RIF {
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
	    namespace export RESET_VALUE
	    proc RESET_VALUE {} {
		return 0x00000000
	    }
	}
	namespace eval RADIO {
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
	    namespace export RESET_VALUE
	    proc RESET_VALUE {} {
		return 0x00000000
	    }
	}
	namespace eval MDM {
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
	    namespace export RESET_VALUE
	    proc RESET_VALUE {} {
		return 0x00000000
	    }
	}
	namespace eval PMU {
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
	    namespace export RESET_VALUE
	    proc RESET_VALUE {} {
		return 0x00000000
	    }
	}
	namespace eval PSEQ {
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
	    namespace export RESET_VALUE
	    proc RESET_VALUE {} {
		return 0x00000000
	    }
	}
	namespace eval SWD {
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
	    namespace export RESET_VALUE
	    proc RESET_VALUE {} {
		return 0x00000000
	    }
	}
	namespace eval GADC {
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
	    namespace export RESET_VALUE
	    proc RESET_VALUE {} {
		return 0x00000000
	    }
	}
	namespace eval TRNG {
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
	    namespace export RESET_VALUE
	    proc RESET_VALUE {} {
		return 0x00000000
	    }
	}
	namespace eval RCOS_CAL {
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
	    namespace export RESET_VALUE
	    proc RESET_VALUE {} {
		return 0x00000000
	    }
	}
	namespace eval SHUB {
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
	    namespace export RESET_VALUE
	    proc RESET_VALUE {} {
		return 0x00000000
	    }
	}
	namespace eval AT_LC {
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
	    namespace export RESET_VALUE
	    proc RESET_VALUE {} {
		return 0x00000000
	    }
	}
    }
    namespace export APBNSPPCEXP2
    proc APBNSPPCEXP2 { {base [::SEC_PRIV_CTRL_SECURE::BASE]} } {
	return [expr { [expr $base] + 0x88 }]
    }
    namespace eval APBNSPPCEXP2 {
	namespace export REG_ADDR
	proc REG_ADDR { {base [::SEC_PRIV_CTRL_SECURE::BASE]} } {
	    return [expr { [expr $base] + 0x88 }]
	}
	namespace eval PDM0 {
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
	    namespace export RESET_VALUE
	    proc RESET_VALUE {} {
		return 0x00000000
	    }
	}
	namespace eval PDM1 {
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
	    namespace export RESET_VALUE
	    proc RESET_VALUE {} {
		return 0x00000000
	    }
	}
	namespace eval WRPR {
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
	    namespace export RESET_VALUE
	    proc RESET_VALUE {} {
		return 0x00000000
	    }
	}
	namespace eval I2S {
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
		return [expr {!(($field_val << 0) & ~0x00000020)}]
	    }
	    namespace export RESET_VALUE
	    proc RESET_VALUE {} {
		return 0x00000000
	    }
	}
	namespace eval CLKRSTGEN {
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
	    namespace export RESET_VALUE
	    proc RESET_VALUE {} {
		return 0x00000000
	    }
	}
	namespace eval AES {
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
	    namespace export RESET_VALUE
	    proc RESET_VALUE {} {
		return 0x00000000
	    }
	}
    }
}
