namespace eval MPC_RAM0_SECURE {
    namespace export BASE
    proc BASE {} {
	return 0x50083000
    }
    namespace export BLK_MAX
    proc BLK_MAX { {base [::MPC_RAM0_SECURE::BASE]}} {
	return [expr { [expr $base] + 0x10 }]
    }
    namespace eval BLK_MAX {
	namespace export REG_ADDR
	proc REG_ADDR { {base [::MPC_RAM0_SECURE::BASE]} } {
	    return [expr { [expr $base] + 0x10 }]
	}
	namespace eval BLK_MAX {
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
	}
    }
    namespace export BLK_CFG
    proc BLK_CFG { {base [::MPC_RAM0_SECURE::BASE]}} {
	return [expr { [expr $base] + 0x14 }]
    }
    namespace eval BLK_CFG {
	namespace export REG_ADDR
	proc REG_ADDR { {base [::MPC_RAM0_SECURE::BASE]} } {
	    return [expr { [expr $base] + 0x14 }]
	}
	namespace eval BLK_CFG {
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
	}
    }
    namespace export BLK_IDX
    proc BLK_IDX { {base [::MPC_RAM0_SECURE::BASE]}} {
	return [expr { [expr $base] + 0x18 }]
    }
    namespace eval BLK_IDX {
	namespace export REG_ADDR
	proc REG_ADDR { {base [::MPC_RAM0_SECURE::BASE]} } {
	    return [expr { [expr $base] + 0x18 }]
	}
	namespace eval BLK_IDX {
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
		return [expr {(field_val << 0) & 0xffffffff}]
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
		return [expr {!(($field_val << 0) & ~0xfffffff0)}]
	    }
	    namespace export RESET_VALUE
	    proc RESET_VALUE {} {
		return 0
	    }
	}
	namespace export RESET_VALUE
	proc RESET_VALUE {} {
	    return 0
	}
    }
    namespace export BLK_LUT
    proc BLK_IDX { {base [::MPC_RAM0_SECURE::BASE]}} {
	return [expr { [expr $base] + 0x1c }]
    }
    namespace eval BLK_LUT {
	namespace export REG_ADDR
	proc REG_ADDR { {base [::MPC_RAM0_SECURE::BASE]} } {
	    return [expr { [expr $base] + 0x1c }]
	}
	namespace eval BLK_LUT {
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
		return [expr {(field_val << 0) & 0xffffffff}]
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
		return [expr {!(($field_val << 0) & ~0xfffffff0)}]
	    }
	}
    }
}
