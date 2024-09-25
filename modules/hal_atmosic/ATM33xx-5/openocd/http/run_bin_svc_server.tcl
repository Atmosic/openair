source bin_svc_server.tcl
source_jimhttp arguments.tcl

proc main {} {
    global argv
    global argv0

    stdout buffering line

    set optionalArgs [list -p port 8080 -i ip 0.0.0.0 -v verbosity 2 -n nvds_tool nvds_tool -s atm_isp atm_isp]
    set error [catch {
        set args [::arguments::parse {} $optionalArgs $argv]
    } errorMessage]
    if {$error} {
        puts "Error: $errorMessage"
        puts [::arguments::usage {} $optionalArgs $argv0]
        exit 1
    }
    if { [catch {start-bin-server $args} errMsg ] } {
	puts "Error: could not start http server - $errMsg"
    }
}

main
