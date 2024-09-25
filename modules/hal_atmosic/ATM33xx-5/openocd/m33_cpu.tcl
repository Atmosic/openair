source [find target/swj-dp.tcl]

set ::env(NO_HYPER) 1

set _CHIPNAME Paris
set _ENDIAN little
# JTAG IDCODE register
set _CPUTAPID 0x6BA02477

swj_newdap $_CHIPNAME cpu -expected-id $_CPUTAPID -irlen 4

set _TARGETNAME $_CHIPNAME.cpu
set _CTINAME ParisCTI
dap create $_CHIPNAME.dap -chain-position $_CHIPNAME.cpu
cti create $_CTINAME -dap $_CHIPNAME.dap -ap-num 0 -baseaddr 0xF0002000
target create $_TARGETNAME cortex_m -dap $_CHIPNAME.dap -ap-num 1 -coreid 0
$_TARGETNAME configure -work-area-backup 1 -work-area-phys 0x20010000 -work-area-size 128
#TO DO: To be removed and replaced with mechanism purely on the debugger client 
$_TARGETNAME configure -event gdb-attach cti_on
$_TARGETNAME configure -event gdb-detach cti_off

set _RESET_HARD_ON_EXIT 0
set _RESET_HARD_TIME 100
if {[info exists ::env(FTDI_RESET_HARD_TIME)]} {
    set _RESET_HARD_TIME $::env(FTDI_RESET_HARD_TIME)
    puts "_RESET_HARD_TIME set to $_RESET_HARD_TIME"
}

rename init orig_init
proc init {} {
    orig_init

    # Cannot change memaccess until after init has run
    $::_CHIPNAME.dap memaccess 1024

    adapter speed $::_SWD_KHZ
}

rename exit orig_exit
proc exit {} {
    poll off
    # Deassert syspwrupreq and dbgpwrupreq
    $::_CHIPNAME.dap dpreg 4 0x00000041
    if {$::_RESET_HARD_ON_EXIT} {
	set_reset
	sleep $::_RESET_HARD_TIME
	release_reset
    }
    orig_exit
}

reset_config none
cortex_m reset_config sysresetreq

proc reset_hard [list [list reset_time $_RESET_HARD_TIME] ] {
    poll off
    set_reset
    sleep $reset_time
    release_reset
    sleep 100
    poll on
}

proc polloff_n_reset_hard {} {
    poll off
    $::_CHIPNAME.dap dpreg 4 0x00000041
    set_reset
    sleep $::_RESET_HARD_TIME
    release_reset
}

proc cti_on {} {
    halt
    $::_CTINAME enable on
    $::_CTINAME write CTR 0x1
    $::_CTINAME write OUTEN0 0x4
    $::_CTINAME write OUTEN2 0x4
    $::_CTINAME write APPPULSE 0x4
    puts [$::_CTINAME dump]
}

proc cti_off {} {
    halt
    $::_CTINAME enable on
    $::_CTINAME write CTR 0x1
    $::_CTINAME write INACK 0x5
    $::_CTINAME write OUTEN1 0x8
    $::_CTINAME write OUTEN3 0x8
    $::_CTINAME write APPPULSE 0x8
    puts [$::_CTINAME dump]
}
