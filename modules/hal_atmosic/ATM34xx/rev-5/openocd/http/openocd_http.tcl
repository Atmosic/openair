# Routine for sourcing Jim Tcl scripts.  Jim Tcl doesn't have a find
# function.  Therefore, Jim Tcl scripts don't use the idiom "source
# [find X.tcl]" commonly used in OpenOCD scripts.
proc source_jimtcl_script {jimtcl_script} {
    set saved_pwd [pwd]
    cd [file dirname [find $jimtcl_script]]
    source $jimtcl_script
    cd $saved_pwd
}

proc openocd_http_dir {} {
    if {[info exists ::env(OPENOCD_HTTP_DIR)]} {
        return $::env(OPENOCD_HTTP_DIR)
    }
    return [file dirname [file normalize [info script]]]
}

set argv {}
set argv0 openocd_bin_http
if {[info exists ::env(HTTP_BIN_PORT)]} {
    lappend argv -p $::env(HTTP_BIN_PORT)
}
if {[info exists ::env(HTTP_BIN_IP)]} {
    lappend argv -i $::env(HTTP_BIN_IP)
}
if {[info exists ::env(HTTP_BIN_VERBOSITY)]} {
    lappend argv -v $::env(HTTP_BIN_VERBOSITY)
}
if {[info exists ::env(HTTP_NVDS_TOOL)]} {
    lappend argv -n $::env(HTTP_NVDS_TOOL)
}
if {[info exists ::env(HTTP_ATM_ISP)]} {
    lappend argv -s $::env(HTTP_ATM_ISP)
}
source_jimtcl_script [file join [openocd_http_dir] run_bin_svc_server.tcl]
