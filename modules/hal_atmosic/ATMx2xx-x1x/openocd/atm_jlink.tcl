# Pin 5 - BBOOT, Pin 11 - PWD
# Array element for mapping - pin3:pin5:pin7:pin9:pin11:pin13:pin15:pin17
set JLINK_PIO_OUT_LOW 2
set JLINK_PIO_OUT_HIGH 3
set JLINK_PIO_MAP_DEFAULT 0:0:0:0:0:0:0:0
set JLINK_PIO_MAP_BBOOT_H_PWD_L 0:$JLINK_PIO_OUT_HIGH:0:0:0:0:0:0
set JLINK_PIO_MAP_BBOOT_L_PWD_H 0:$JLINK_PIO_OUT_LOW:0:0:$JLINK_PIO_OUT_HIGH:0:0:0
set JLINK_PIO_MAP_BBOOT_L_PWD_L 0:$JLINK_PIO_OUT_LOW:0:0:$JLINK_PIO_OUT_LOW:0:0:0

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

jlink gpioconfig 0:$BBOOT_ENABLE:0:0:$PWD_ENABLE:0:0:0

proc assert_pwd {} {
    jlink gpio map $::JLINK_PIO_MAP_BBOOT_L_PWD_H
}

proc deassert_pwd {} {
    jlink gpio map $::JLINK_PIO_MAP_BBOOT_L_PWD_L
}

proc assert_bboot {} {
    jlink gpio map $::JLINK_PIO_MAP_BBOOT_H_PWD_L
}

proc deassert_bboot {} {
    jlink gpio map $::JLINK_PIO_MAP_BBOOT_L_PWD_L
}
