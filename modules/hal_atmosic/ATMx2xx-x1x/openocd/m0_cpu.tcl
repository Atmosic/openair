source [find target/swj-dp.tcl]

set _CHIPNAME Sydney
set _ENDIAN little
# JTAG IDCODE register
set _CPUTAPID 0x0BA01477

swj_newdap $_CHIPNAME cpu -expected-id $_CPUTAPID -irlen 4

set _TARGETNAME $_CHIPNAME.cpu
dap create $_CHIPNAME.dap -chain-position $_CHIPNAME.cpu
target create $_TARGETNAME cortex_m -dap $_CHIPNAME.dap
$_TARGETNAME configure -work-area-backup 1 -work-area-phys 0x20010000 -work-area-size 128

set _RESET_HARD_ON_EXIT 0
set _RESET_HARD_TIME 2000
if {[info exists ::env(FTDI_RESET_HARD_TIME)]} {
    set _RESET_HARD_TIME $::env(FTDI_RESET_HARD_TIME)
    puts "_RESET_HARD_TIME set to $_RESET_HARD_TIME"
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
