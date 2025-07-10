puts "SWD board type - $SWDBOARD_TYPE"

adapter driver ftdi
if {$SWDBOARD_TYPE eq "SWDBOARD_APT" || $SWDBOARD_TYPE eq "SWDBOARD_DL"} {
    ftdi vid_pid 0x0403 0x6011
    set _FTDI_RESET 0x80
    set _FTDI_BBOOT 0x40
    set _FTDI_SWD_ENABLE 0x0
} else {
    ftdi vid_pid 0x0403 0x6010
    set _FTDI_RESET 0x8000
    set _FTDI_BBOOT 0x4000
    # Use FT2232H ACBUS4 pin as GPIO (GPIOH4)
    set _FTDI_SWD_ENABLE 0x1000
}

if {[info exists ::env(FTDI_SWD_ENABLE)]} {
    set _FTDI_SWD_ENABLE $::env(FTDI_SWD_ENABLE)
    puts "set _FTDI_SWD_ENABLE to $_FTDI_SWD_ENABLE"
}

if {[info exists ::env(SYDNEY_SERIAL)]} {
    if {$SWDBOARD_TYPE eq "SWDBOARD_APT" || $SWDBOARD_TYPE eq "SWDBOARD_DL"} {
	set _FTDI_SERIAL $::env(SYDNEY_SERIAL)
    } else {
	set _FTDI_SERIAL [format "%s%s" $::env(SYDNEY_SERIAL) "USB1"]
    }
    puts "FTDI serial $_FTDI_SERIAL"
    adapter serial $_FTDI_SERIAL
} elseif {[info exists ::env(PARIS_SERIAL)]} {
    set _FTDI_SERIAL [format "%s%s" $::env(PARIS_SERIAL) "USB1"]
    puts "FTDI serial $_FTDI_SERIAL"
    adapter serial $_FTDI_SERIAL
}

ftdi channel 0
set _FTDI_OD 0x0000
set _FTDI_OE 0x0003

if {[info exists ::env(FTDI_HARD_RESET)]} {
    set _FTDI_OE [expr {$_FTDI_OE | $_FTDI_RESET}]
    if {$::env(FTDI_HARD_RESET) ne "0"} {
	set _FTDI_OD [expr {$_FTDI_OD | $_FTDI_RESET}]
    }
}

if {[info exists ::env(FTDI_BENIGN_BOOT)]} {
    set _FTDI_OE [expr {$_FTDI_OE | $_FTDI_BBOOT}]
    if {$::env(FTDI_BENIGN_BOOT) ne "0"} {
	set _FTDI_OD [expr {$_FTDI_OD | $_FTDI_BBOOT}]
    }
}

set _FTDI_OE [expr {$_FTDI_OE | $_FTDI_SWD_ENABLE}]
set _FTDI_OD [expr {$_FTDI_OD | $_FTDI_SWD_ENABLE}]
puts [format "FTDI_OE: 0x%x, FTDI_OD: 0x%x" $_FTDI_OE $_FTDI_OD]

ftdi layout_init $_FTDI_OD $_FTDI_OE
ftdi layout_signal SRST -data $_FTDI_RESET -oe $_FTDI_RESET
ftdi layout_signal BBOOT -data $_FTDI_BBOOT -oe $_FTDI_BBOOT
ftdi layout_signal SWDENABLE -data $_FTDI_SWD_ENABLE -oe $_FTDI_SWD_ENABLE

transport select swd
ftdi layout_signal SWD_EN -data 0
ftdi layout_signal SWDIO_OE -data 0


proc assert_pwd {} {
    ftdi set_signal SRST 1
}

proc deassert_pwd {} {
    global _FTDI_SWD_ENABLE

    if {$_FTDI_SWD_ENABLE} {
	ftdi set_signal SWDENABLE 0
	ftdi set_signal SWDENABLE z
    }
    ftdi set_signal SRST 0
    ftdi set_signal SRST z
}

proc assert_bboot {} {
    ftdi set_signal BBOOT 1
}

proc deassert_bboot {} {
    ftdi set_signal BBOOT 0
    ftdi set_signal BBOOT z
}

if {$SWDBOARD_TYPE eq "SWDBOARD_APT" || $SWDBOARD_TYPE eq "SWDBOARD_DL"} {
    set _FTDI_VBAT_EN 0x08
    set _FTDI_VCCIO_EN 0x10
    set _FTDI_LS_EN 0x20
    # Use FT4232HQ BDBUS[2|3] pin connect to DUT GPIO1
    set _FTDI_DUT_GPIO_1 0x0
    set _FTDI_OD [expr {$_FTDI_OD | $_FTDI_LS_EN | $_FTDI_VCCIO_EN | $_FTDI_VBAT_EN}]
    set _FTDI_OE [expr {$_FTDI_OE | $_FTDI_LS_EN | $_FTDI_VCCIO_EN | $_FTDI_VBAT_EN}]

    if {[info exists ::env(FTDI_VBAT_EN)] && $::env(FTDI_VBAT_EN) eq "0"} {
	set _FTDI_OD [expr {$_FTDI_OD & ~$_FTDI_VBAT_EN}]
    }

    if {[info exists ::env(FTDI_VCCIO_EN)] && $::env(FTDI_VCCIO_EN) eq "0"} {
	set _FTDI_OD [expr {$_FTDI_OD & ~$_FTDI_VCCIO_EN}]
    }

    if {[info exists ::env(FTDI_LS_EN)] && $::env(FTDI_LS_EN) eq "0"} {
	set _FTDI_OD [expr {$_FTDI_OD & ~$_FTDI_LS_EN}]
    }

    if {[info exists ::env(FTDI_DUT_GPIO_1)]} {
	set _FTDI_DUT_GPIO_1 $::env(FTDI_DUT_GPIO_1)
	set _FTDI_OD [expr {$_FTDI_OD | $_FTDI_DUT_GPIO_1}]
	set _FTDI_OE [expr {$_FTDI_OD | $_FTDI_DUT_GPIO_1}]
    }
    puts [format "FTDI_OE: 0x%x, FTDI_OD: 0x%x" $_FTDI_OE $_FTDI_OD]

    ftdi layout_init $_FTDI_OD $_FTDI_OE
    ftdi layout_signal VBAT_EN -data $_FTDI_VBAT_EN -oe $_FTDI_VBAT_EN
    ftdi layout_signal VCCIO_EN -data $_FTDI_VCCIO_EN -oe $_FTDI_VCCIO_EN
    ftdi layout_signal LS_EN -data $_FTDI_LS_EN -oe $_FTDI_LS_EN
    ftdi layout_signal DUT_GPIO_1 -data $_FTDI_DUT_GPIO_1 -oe $_FTDI_DUT_GPIO_1
}

proc assert_vbat {} {
    global SWDBOARD_TYPE

    if {$SWDBOARD_TYPE eq "SWDBOARD_APT" || $SWDBOARD_TYPE eq "SWDBOARD_DL"} {
	ftdi set_signal VBAT_EN 1
    }
}

proc deassert_vbat {} {
    global SWDBOARD_TYPE

    if {$SWDBOARD_TYPE eq "SWDBOARD_APT" || $SWDBOARD_TYPE eq "SWDBOARD_DL"} {
	ftdi set_signal VBAT_EN 0
	ftdi set_signal VBAT_EN z
    }
}

proc assert_vccio {} {
    global SWDBOARD_TYPE

    if {$SWDBOARD_TYPE eq "SWDBOARD_APT" || $SWDBOARD_TYPE eq "SWDBOARD_DL"} {
	ftdi set_signal VCCIO_EN 1
    }
}

proc deassert_vccio {} {
    global SWDBOARD_TYPE

    if {$SWDBOARD_TYPE eq "SWDBOARD_APT" || $SWDBOARD_TYPE eq "SWDBOARD_DL"} {
	ftdi set_signal VCCIO_EN 0
	ftdi set_signal VCCIO_EN z
    }
}

proc assert_ls {} {
    global SWDBOARD_TYPE

    if {$SWDBOARD_TYPE eq "SWDBOARD_APT" || $SWDBOARD_TYPE eq "SWDBOARD_DL"} {
	ftdi set_signal LS_EN 1
    }
}

proc deassert_ls {} {
    global SWDBOARD_TYPE

    if {$SWDBOARD_TYPE eq "SWDBOARD_APT" || $SWDBOARD_TYPE eq "SWDBOARD_DL"} {
	ftdi set_signal LS_EN 0
	ftdi set_signal LS_EN z
    }
}
