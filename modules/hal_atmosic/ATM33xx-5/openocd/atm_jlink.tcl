set JLINK_PIO_OUT_LOW 2
set JLINK_PIO_OUT_HIGH 3

adapter driver jlink

if {[info exists ::env(JLINK_SERIAL)]} {
    set _JLINK_SERIAL [format "%s" $::env(JLINK_SERIAL)]
    puts "JLINK serial $_JLINK_SERIAL"
    adapter serial $_JLINK_SERIAL
}

transport select swd

set BBOOT_ENABLE $JLINK_PIO_OUT_LOW
if {[info exists ::env(FTDI_BENIGN_BOOT)]} {
    if {$::env(FTDI_BENIGN_BOOT) ne "0"} {
	set BBOOT_ENABLE $JLINK_PIO_OUT_HIGH
    }
}

set PWD_ENABLE $JLINK_PIO_OUT_LOW
if {[info exists ::env(FTDI_HARD_RESET)]} {
    if {$::env(FTDI_HARD_RESET) ne "0"} {
	set PWD_ENABLE $JLINK_PIO_OUT_HIGH
    }
}

set CONNECT_ENABLE $JLINK_PIO_OUT_LOW
if {[info exists ::env(JLINK_NO_K22)]} {
    if {$::env(JLINK_NO_K22) ne "0"} {
	set CONNECT_ENABLE $JLINK_PIO_OUT_HIGH
    }
}

jlink gpioconfig [jlink_pio_map]

proc assert_pwd {} {
    set ::PWD_ENABLE $::JLINK_PIO_OUT_HIGH
    jlink gpio map [jlink_pio_map]
}

proc deassert_pwd {} {
    set ::PWD_ENABLE $::JLINK_PIO_OUT_LOW
    jlink gpio map [jlink_pio_map]
}

proc assert_bboot {} {
    set ::BBOOT_ENABLE $::JLINK_PIO_OUT_HIGH
    jlink gpio map [jlink_pio_map]
}

proc deassert_bboot {} {
    set ::BBOOT_ENABLE $::JLINK_PIO_OUT_LOW
    jlink gpio map [jlink_pio_map]
}

proc assert_connect {} {
    set ::CONNECT_ENABLE $::JLINK_PIO_OUT_LOW
    jlink gpio map [jlink_pio_map]
}

proc deassert_connect {} {
    set ::CONNECT_ENABLE $::JLINK_PIO_OUT_HIGH
    jlink gpio map [jlink_pio_map]
}
