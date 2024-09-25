
gdb_port 3333
telnet_port 4444
tcl_port 6666

bindto 0.0.0.0

if { [catch {source [find http/openocd_http.tcl]} errMsg] } {
    puts stderr "Failed to start OpenOCD HTTP server"
    puts stderr [errorInfo $errMsg [info stacktrace]]
    if { [info exists ::env(HTTP_KEEP_GOING)] && $::env(HTTP_KEEP_GOING) ne 0 } {
	puts stderr "Ignoring HTTP server error"
    } else {
	error "Stopping due to HTTP server error (set HTTP_KEEP_GOING to bypass)"
    }
}
