source source_jimhttp.tcl
source_jimhttp http.tcl

variable nvds_tool nvds_tool
variable atm_isp atm_isp
variable bin_svc_http_err_code 206
variable platforms {}
global ::http::statusCodePhrases

if {[dict exists $::http::statusCodePhrases $bin_svc_http_err_code]} {
    puts "Warning: overriding ::http::statusCodePhrases($bin_svc_http_err_code)"
}
dict set ::http::statusCodePhrases $bin_svc_http_err_code {Atmosic Binary Service Error}

::http::add-handler GET / {
    ::http::respond [::http::make-response "Atmosic binary API server" {} $request]
}

proc ::http::make-options-response {body have_get {headers {}} {request {}}} {
    set ::http::responseTemplate \
        {HTTP/1.1 $headers(code) $::http::statusCodePhrases($headers(code))
Content-Type: $headers(contentType)
Content-Length: $length}

    set ::http::headerDefaults [dict create {*}{
        code 200
        contentType text/html
    }]

    set headers [dict merge $::http::headerDefaults $headers]

    if ($have_get) {
	set opts [list OPTIONS GET POST]
    } else {
	set opts [list OPTIONS POST]
    }
    set opts_str [join $opts ", "]

    # Handle response processing, e.g., compression.
    foreach lambda $::http::responseFilters {
        lassign [apply $lambda $body $headers $request] body headers
    }

    set length [string bytelength $body]

    set response [subst $::http::responseTemplate]

    append response \
		"\nAccess-Control-Allow-Origin: *"
    append response \
                 "\nAllow: $opts_str"

    append response \
                "\nAccess-Control-Allow-Methods: $opts_str"
    append response \
		"\nAccess-Control-Allow-Headers: X-PINGOTHER, content-type"
    return $response
}


proc add-bin-svc-options {route have_get } {
    ::http::add-handler OPTIONS $route [list apply {{have_get} {
	upvar 1 request request
	upvar 1 channel channel
       ::http::respond [::http::make-options-response "" $have_get {} $request]
    }} $have_get]
}

proc ::http::make-bin-svc-response {body {headers {}} {request {}}} {
    set ::http::responseTemplate \
        {HTTP/1.1 $headers(code) $::http::statusCodePhrases($headers(code))
Content-Type: $headers(contentType)
Content-Length: $length}

    set ::http::headerDefaults [dict create {*}{
        code 200
        contentType text/html
    }]

    set headers [dict merge $::http::headerDefaults $headers]

    # Handle response processing, e.g., compression.
    foreach lambda $::http::responseFilters {
        lassign [apply $lambda $body $headers $request] body headers
    }

    set length [string bytelength $body]

    set response [subst $::http::responseTemplate]

    # TODO: Generalize for other possible fields in the headers.
    if {[dict exists $headers cookies]} {
        foreach cookie $headers(cookies) {
            append response "\nSet-Cookie: [::http::make-cookie $cookie]"
        }
    }
    if {[dict exists $headers contentEncoding]} {
        append response \
                "\nContent-Encoding: [dict get $headers contentEncoding]"
    }
    append response \
                "\nAccess-Control-Allow-Origin: *"

    append response "\n\n$body"
    return $response
}

proc ::http::make-bin-svc-err {body {request {}}} {
    global bin_svc_http_err_code
    return [::http::make-bin-svc-response $body [list code $bin_svc_http_err_code] $request]
}

proc handle-bin-get {oocd_cmd filename mimeType} {
    ::http::log info "Running OpenOCD binary command $oocd_cmd $filename"
    upvar 2 channel channel
    upvar 2 request request
    if { [catch {verify_rom_version} msg] } {
	::http::log error "Verify ROM version failed: $msg"
	::http::respond [::http::make-bin-svc-err "<p>$msg</p>" $request]
	::http::log debug "Sent ROM version mismatch error response"
	return
    }
    ::http::log debug "Verify ROM succeeded"
    if { [catch {$oocd_cmd $filename}] } {
	::http::respond [::http::make-bin-svc-err "<p>'$oocd_cmd' failed</p>" \
			     $request]
	return
    }
    puts -nonewline $channel \
	[::http::make-bin-svc-response \
	     [::http::read-file $filename] \
	     [list contentType $mimeType] \
	     $request]
    file delete -- $filename
}

proc add-bin-svc-get {route oocd_cmd filename} {
    ::http::add-handler GET $route [list apply {{oocd_cmd filename mimeType} {
	poll on
	handle-bin-get $oocd_cmd $filename $mimeType
	polloff_n_reset_hard
    }} $oocd_cmd $filename [::mime::type $filename]]
}

proc get-xargs {req_form} {
    ::http::log debug "get-xargs"
    if {! [dict exists $req_form xargs]} {
	::http::log debug "No xargs in URI"
	return {}
    }
    set xargs_str [dict get $req_form xargs]
    ::http::log debug "xargs_str: $xargs_str"
    set xargs [lsearch -all -inline -not -exact [split $xargs_str] {}]
    ::http::log debug "xargs: $xargs"
    return $xargs
}

proc handle-bin-post {oocd_cmd filename mimeType} {
    ::http::log info "Running OpenOCD SVC command $oocd_cmd $filename"
    ::http::log debug "in [pwd]"
    upvar 2 channel channel
    upvar 2 request request
    if { [catch {verify_rom_version} msg] } {
	::http::log error "Verify ROM version failed: $msg"
	::http::respond [::http::make-bin-svc-err "<p>$msg</p>" $request]
	::http::log debug "Sent ROM version mismatch error response"
	return
    }
    ::http::log debug "Verify ROM succeeded"
    if {$request(contentLength) != [string length $request(formPost)]} {
	::http::log warning "content and formPost lengths differ"
    }
    # First, write posted data to a file
    set error 1
    set fileopen 1
    if { [catch {open $filename w} outfile] } {
	::http::log error "Could not open $filename for writing\n'$outfile'"
	set fileopen 0
    } elseif { [catch {puts -nonewline $outfile $request(formPost)}] } {
	::http::log error "Could not write to $filename\n$outfile"
    } else {
	set error 0
    }
    if {$fileopen} {
	close $outfile
    }
    # Upon successful saving of bin/nvm, load/burn on device
    set args [list $oocd_cmd $filename \
		  {*}[get-xargs [dict get $request form]]]
    if {$error} {
	set errMsg "Failed to save posted data to file"
    } elseif { [catch {{*}$args} msg] } {
	set errMsg "'$oocd_cmd' failed: $msg"
    } else {
	set errMsg ""
    }
    file delete -- $filename
    if {$errMsg eq ""} {
	::http::log info "'$args' executed AOK"
	set resp [::http::make-bin-svc-response "" {} $request]
    } else {
	::http::log warning "Command '$args' failed"
	::http::log warning "Responding with error: $errMsg"
	set resp [::http::make-bin-svc-err "<p>$errMsg</p>" $request]
    }
    ::http::respond $resp
}

proc add-bin-svc-post {route oocd_cmd filename} {
    ::http::add-handler POST $route [list apply {{oocd_cmd filename mimeType} {
	poll on
	handle-bin-post $oocd_cmd $filename $mimeType
	polloff_n_reset_hard
    }} $oocd_cmd $filename [::mime::type $filename]]
}

proc add-service {route oocd_cmd_get oocd_cmd_post filename {have_get 1} } {
    if ($have_get) {
	add-bin-svc-get $route $oocd_cmd_get $filename
    }
    add-bin-svc-post $route $oocd_cmd_post $filename
    add-bin-svc-options $route $have_get
}

# Filter out all args of the atm_isp burn subcommand except -e, -v,
# -c, or their combinations
proc filter_isp_burn_args { isp_burn_args args } {
    return [lsearch -all -inline {*}$args -regexp $isp_burn_args {^\-[evc]+$}]
}

# Makes a system call to atm_isp with "burn -i <archive> -t
# atm_ispX.tcl -d atm_isp_X <args...>" as arguments.  <args...> is
# filtered first.
#
# This function manages the files generated by atm_isp.  If an atm_isp
# error occurs in debug mode (::http::verbosity >= 3), the files used
# as arguments to -t/-d won't be cleaned up.
proc sydney_burn_archive { archive args } {
    ::http::log debug "sydney_burn_archive archive=$archive args=$args"
    global atm_isp
    set atm_isp_xargs [filter_isp_burn_args $args]
    set atm_isp_xargs_ignored [filter_isp_burn_args $args -not]
    if {$atm_isp_xargs_ignored ne ""} {
	::http::log warning "Ignored archive xargs $atm_isp_xargs_ignored"
    }
    set atm_isp_tcl_script "atm_isp_[pid].tcl"
    set atm_isp_tmp_dir "atm_isp_[pid]"
    set argv [list $atm_isp burn -i $archive]
    lappend argv -t $atm_isp_tcl_script
    lappend argv -d $atm_isp_tmp_dir
    lappend argv {*}$atm_isp_xargs
    set errMsg {}
    ::http::log debug "sydney_burn_archive: executing '$argv'"
    if { [catch { file mkdir $atm_isp_tmp_dir } ] } {
	set errMsg "Failed to make temp directory '$atm_isp_tmp_dir'"
    } elseif { [catch { exec >@stdout 2>@stderr {*}$argv } msg] } {
	set errMsg "Command '$argv' failed: $msg"
    } elseif { [catch {source $atm_isp_tcl_script} msg] } {
	set errMsg "Sourcing '$atm_isp_tcl_script' failed: $msg"
    }
    if { $errMsg ne {} && $::http::verbosity >= 3 } { # 3 is "debug"
	::http::log debug "Kept atm_isp_tcl_script=$atm_isp_tcl_script and atm_isp_tmp_dir=$atm_isp_tmp_dir"
    } else {
	file delete -- $atm_isp_tcl_script
	file delete -force -- $atm_isp_tmp_dir
	::http::log debug "Deleted atm_isp_tcl_script=$atm_isp_tcl_script and atm_isp_tmp_dir=$atm_isp_tmp_dir"
    }
    if { $errMsg eq {} } {
	::http::log debug "Successfully executed '$argv' and sourced the generated script"
    } else {
	error $errMsg
    }
}

add-service /verify_flash {} atm_verify_flash image 0
add-service /elf atm_dump_flash atm_load_flash image
add-service /nvds/flash atm_dump_nvds atm_load_nvds flash_nvds_[pid].bin
add-service /nvds/otp sydney_dump_nvm sydney_burn_nvm otp_nvds_[pid].nvm
add-service /isp/burn {} sydney_burn_archive arch.atm 0

# Takes individual tag data files and makes a system call to
# "nvds_tool" with -b and the appropriate -e/-l -t&-d pairs.
#
# There are two methods to determine the arguments passed to nvds_tool:
#
#  M-1) Get all arguments verbatim (modulo -hbvpSo:O:) from the URI as in:
#
#           /nvds/tool/b?-i%20-e%20b6%20-t%2001%20-d%20foo.bin
#
#     to execute "nvds_tool -b -i -e b6 -t 01 -d foo.bin"
#
#  M-2) If no erasing or locking of a tag (nvds_tool -e or -l) is
#     needed, and there's no specific or non-lexicographic order in
#     which the tag data should be passed to nvds_tool, then the tags
#     can just come in as the "filename" metadata accomponied with the
#     uploaded tag data files.  The URL can encode "?isotp=" for -i,
#     "?rebuild=<filename>" for -r <filename>, and "?sort_tags=" to
#     sort the <tag>s in the "-t <tag> -d <data>" pairs.
#
# Todo-1: allow option for tag data to come in as just binary blobs, not
#         necessarily as files.

::http::add-handler OPTIONS /nvds/tool/b {
    set resp [::http::make-options-response "" $have_get {} $request]

    ::http::respond $resp
}

::http::add-handler POST /nvds/tool/b {
    global nvds_tool
    set err_msg {}
    set tmp_files {}
    set posted_files {}
    set existing_nvds_filename {}
    set out nvds
    set argv [list $nvds_tool -b -o $out]
    if {![dict exists $request files]} {
	set err_msg "No files posted to /nvds/tool/b"
    } elseif {3 <= $::http::verbosity} {
	::http::log debug "begin url form data"
	dict for {key info} [dict get $request form] {
	    ::http::log debug "$key=[dict get $request form $key]"
	}
	::http::log debug "end url form data"
    }
    # Create temporary files
    set existing_nvds_fname_client {}
    dict for {fname_client info} [dict get $request files] {
	if {$err_msg ne ""} {
	    break
	}
	if {[dict exists $request files $fname_client filename]} {
	    set filename [dict get $request files $fname_client filename]
	} else {
	    set filename [file tail $fname_client]
	}
	::http::log debug "Received $fname_client as $filename"
	if {$existing_nvds_filename eq $filename} {
	    set existing_nvds_fname_client $fname_client
	}
	set content [dict get $request files $fname_client content]
	set fileopen 1
	if { [catch {open $filename w} outfile] } {
	    set err_msg "Could not open $filename for writing\n'$outfile'"
	    set fileopen 0
	} elseif { [catch {puts -nonewline $outfile $content}] } {
	    set err_msg "Could not write to $filename\n$outfile"
	} else {
	    ::http::log debug "Saved [string length $content] bytes in $filename"
	    lappend tmp_files $filename
	}
	if {$fileopen} {
	    close $outfile
	}
    }
    if {$err_msg eq ""} {
	if {[dict exists $request form nvds_tool_args]} {
	    ::http::log debug "METHOD 1 -- verbatim nvds_tool_args"
	    # Method M-1
	    #
	    # Note: every nvds_tool opt, including those that don't
	    # take arguments, should have come in prefixed with a "-"
	    # and separated from its argument or the next option with
	    # a "%20".  For example, "-ie01" to erase tag 01 from OTP
	    # is not acceptable, even though nvds_tool itself
	    # correctly recognizes these options because it uses
	    # getopts, which we don't have in tcl.
	    set xargs_str [dict get $request form nvds_tool_args]
	    ::http::log debug "xargs_str: $xargs_str"
	    set xargs [lsearch -all -inline -not -exact [split $xargs_str] {}]
	    ::http::log debug "xargs: $xargs"
	    proc filter_xargs { opt {has_arg 0} } {
		::http::log debug "opt=$opt,has_arg=$has_arg"
		upvar 1 xargs xargs
		set idx [lsearch $xargs $opt]
		if {$idx != -1} {
		    set last $idx
		    if {$has_arg} {
			incr last
		    }
		    ::http::log warning "ignoring '[lrange $xargs $idx $last]' in nvds_tool_args"
		    set xargs [lreplace $xargs $idx $last]
		}
	    }
	    ::http::log debug "filter out opts with no args"
	    foreach opt {-h -b -v -p -S} {
		filter_xargs $opt
	    }
	    ::http::log debug "filter out opts with args"
	    foreach opt {-o -O} {
		filter_xargs $opt 1
	    }
	    lappend argv {*}$xargs
	} else {
	    # Method M-2
	    ::http::log debug "METHOD 2 -- ?rebuild=<fname>&isotp=&sort_tags="
	    if {[dict exists $request form rebuild]} {
		set existing_nvds_filename [dict get $request form rebuild]
	    }
	    if {[dict exists $request form isotp]} {
		lappend argv -i
	    }
	    if {$existing_nvds_filename ne ""} {
		lappend argv -r $existing_nvds_filename
	    }
	    set tags $tmp_files
	    if {$existing_nvds_filename ne ""} {
		if {$existing_nvds_fname_client eq ""} {
		    set err_msg "$existing_nvds_filename to rebuild not uploaded"
		} else {
		    set idx [lsearch -exact $tags $existing_nvds_filename]
		    if {$idx == -1} {
			set err_msg "Could not find $existing_nvds_filename in temporary files list"
		    } else {
			set tags [lreplace $tags $idx $idx]
		    }
		}
	    }
	    set do_sort 0
	    if { [dict exists $request form sort_tags] } {
		set do_sort 1
	    } elseif { [info exists ::env(HTTP_NVDS_SORT_TAGS)] } {
		set do_sort $::env(HTTP_NVDS_SORT_TAGS)
	    }
	    if {$do_sort} {
		set tags [lsort -ascii $tags]
	    }
	    foreach tag $tags {
		lappend argv -t $tag -d $tag
	    }
	}
	::http::log debug "argv: $argv"
	if { [catch { exec >@stdout 2>@stderr {*}$argv } msg] } {
	    set err_msg "Failed to execute $nvds_tool: $msg"
	} else {
	    ::http::log debug "responding with produced NVDS [file size $out]"
	    puts -nonewline $channel \
		[::http::make-bin-svc-response \
		     [::http::read-file $out] \
		     [list contentType [::mime::type $out]] \
		     $request]
	    file delete -- $out
	}
    }
    # Delete temporary files
    foreach filename $tmp_files {
	file delete -- $filename
    }
    if {$err_msg eq ""} {
	set succ_msg "'$argv' succeeded"
	::http::log info $succ_msg
	set resp [::http::make-response "<p><$succ_msg</p>" {} $request]
    } else {
	::http::log error "$err_msg"
	set resp [::http::make-bin-svc-err "<p>$err_msg</p>" $request]
    }
    ::http::respond $resp
}

::http::add-handler OPTIONS /nvds/tool/s {
    set resp [::http::make-options-response "" $have_get {} $request]

    ::http::respond $resp
}

# Takes an NVDS file and returns a list of address-tag-length
# triplets.  This information is sufficient for the client to extract
# the individual tag data.  For example,
# "7,1,6;16,6,39;58,11,28;89,12,24;116,5,3;122,9,4;129,17,1;133,18,1"
# corresponds to an NVDS file that pretty-prints as follows.
#
# @0007 01  c9 00 00 6b 69 7c
# @0010 06  00 00 00 00 01 02 00 00 00 00 00 00 00 00 00 00 00 00 00 40 06 00 00 40 06 00 00 07 01 00 00 00 00 00 00 00 00 00 00
# @003a 0b  03 03 aa fe 0e 16 aa fe 10 00 01 61 74 6d 6f 73 69 63 07 08 08 41 30 30 30 30 63 39
# @0059 0c  17 09 41 54 4d 30 32 30 31 20 45 33 61 20 42 43 4e 20 30 30 30 30 63 39
# @0074 05  00 00 1e
# @007a 09  b8 0b 00 00
# @0081 11  04
# @0085 12  02
#
::http::add-handler POST /nvds/tool/s {
    ::http::log debug "/nvds/tool/s"
    set NVDS \x4e\x56\x44\x53
    set NVDS_inv \xb1\xa9\xbb\xac
    set errMsg {}
    set reqLen [string length $request(formPost)]
    ::http::log debug "reqLen=$reqLen"
    if {$reqLen < 4} {
	set errMsg "binary data length too short: $reqLen"
    } else {
	set magic_bytes [string range $request(formPost) 0 3]
	if {[string equal $magic_bytes $NVDS]} {
	    set isOTP 0
	} elseif {[string equal $magic_bytes $NVDS_inv]} {
	    set isOTP 1
	} elseif {[string equal $magic_bytes \x00\x00\x00\x00]} {
	    set errMsg "NVDS is blank"
	} else {
	    set errMsg "unknown bytes"
	}
    }
    if {$errMsg ne ""} {
	::http::log error "Magic bytes check failed: $errMsg"
	::http::respond [::http::make-bin-svc-err "<p>Magic bytes check of NVDS failed: $errMsg</p>" $request]
	return
    }

    ::http::log debug "isOTP=$isOTP"

    global nvds_tool
    # First, write posted data to a file
    set filename nvds
    set error 1
    set fileopen 1
    if { [catch {open $filename w} outfile] } {
	::http::log error "Could not open $filename for writing\n'$outfile'"
	set fileopen 0
    } elseif { [catch {puts -nonewline $outfile $request(formPost)}] } {
	::http::log error "Could not write to $filename\n$outfile"
    } else {
	set error 0
    }
    if {$fileopen} {
	close $outfile
    }
    # Upon successful saving of bin/nvm, get the split instructions
    # (addr-tag-len triplets) to send back to the client
    set splitdir split_nvds
    set argv [list $nvds_tool]
    if {[dict exists $request form isotp] || $isOTP} {
	lappend argv -i
    }
    lappend argv -vr $filename
    if {$error} {
	set errMsg "Failed to save posted data to file"
    } elseif { [catch { file mkdir $splitdir } msg] } {
	set errMsg $msg
    } elseif { [catch { exec {*}$argv } nvds_tool_output] } {
	set errMsg "'$argv' failed: $nvds_tool_output"
    } else {
	set errMsg ""
    }
    file delete -- $filename $splitdir
    if {$errMsg eq ""} {
	::http::log info "split AOK with '$argv'"
	set addr_tag_len_list {}
	foreach tag_data_line [split $nvds_tool_output "\n"] {
	    set tokens [split $tag_data_line]
	    set addr [expr { 0x[string trimleft [lindex $tokens 0] @] }]
	    set tag [expr { 0x[lindex $tokens 1] }]
	    set len [expr { [llength [lsearch -all -inline -not -exact $tokens {}]] - 2 }]
	    set addr_tag_len [join [list $addr $tag $len] ","]
	    ::http::log info "addr_tag_len=$addr_tag_len"
	    lappend addr_tag_len_list $addr_tag_len
	}
	set resp_text [join $addr_tag_len_list ";"]
	::http::log info "resp_text=$resp_text"
	set resp [::http::make-bin-svc-response $resp_text {} $request]
    } else {
	::http::log warning "Responding with error: $errMsg"
	set resp [::http::make-bin-svc-err "<p>$errMsg</p>" $request]
    }
    ::http::respond $resp
}

::http::add-handler OPTIONS /nvds/otp/rmw {
    ::http::respond [::http::make-options-response {} 0 {} $request]
}

::http::add-handler POST /nvds/otp/rmw {
    ::http::log debug "/nvds/otp/rmw"
    set NVDS \x4e\x56\x44\x53
    set NVDS_inv \xb1\xa9\xbb\xac
    set errMsg {}
    set reqLen [string length $request(formPost)]
    ::http::log debug "reqLen=$reqLen"
    if {$reqLen < 4} {
	set errMsg "binary data length too short: $reqLen"
    } else {
	set magic_bytes [string range $request(formPost) 0 3]
	if {[string equal $magic_bytes $NVDS]} {
	    set errMsg "format is for flash, not OTP"
	} elseif {[string equal $magic_bytes $NVDS_inv]} {
	    set isOTP 1
	} elseif {[string equal $magic_bytes \x00\x00\x00\x00]} {
	    set errMsg "NVDS is blank"
	} else {
	    set errMsg "unknown bytes"
	}
    }
    if {$errMsg ne ""} {
	::http::log error "Magic bytes check failed: $errMsg"
	::http::respond [::http::make-bin-svc-err "<p>Magic bytes check of NVDS failed: $errMsg</p>" $request]
	return
    }

    global nvds_tool
    # First, write posted data to a file
    set filename nvds_[pid].nvm
    set error 1
    set fileopen 1
    if { [catch {open $filename w} outfile] } {
	::http::log error "Could not open $filename for writing\n'$outfile'"
	set fileopen 0
    } elseif { [catch {puts -nonewline $outfile $request(formPost)}] } {
	::http::log error "Could not write to $filename\n$outfile"
    } else {
	set error 0
    }
    if {$fileopen} {
	close $outfile
    }
    if {$error} {
	set errMsg "Failed to save posted data to file"
	::http::log warning "Responding with error: $errMsg"
	::http::respond [::http::make-bin-svc-err "<p>$errMsg</p>" $request]
	return
    }
    if {$request(contentLength) != [string length $request(formPost)]} {
	::http::log warning "content and formPost lengths differ"
    }
    set dev_otp_old dev_otp_old_[pid].nvm
    set dev_otp_new dev_otp_new_[pid].nvm
    set argv [list $nvds_tool -i -r $dev_otp_old -r $filename -b -o $dev_otp_new]
    poll on
    if { [catch { verify_rom_version } msg] } {
	set errMsg "Verify ROM version failed: $msg"
    } elseif { [catch { sydney_dump_nvm $dev_otp_old } msg ] } {
	set errMsg "Dump OTP failed: $msg"
    } elseif { [catch { exec {*}$argv } msg] } {
	set errMsg "Merging OTP with '$argv' failed: $msg"
    } elseif { [catch { sydney_burn_nvm $dev_otp_new } msg ] } {
	set errMsg "Burn OTP failed: $msg"
    } else {
	set errMsg ""
    }
    polloff_n_reset_hard
    file delete -- $dev_otp_old $filename
    file delete -force -- $dev_otp_new
    if {$errMsg eq ""} {
	::http::log info "Read-modify-write of OTP went AOK"
	set resp [::http::make-bin-svc-response {} {} $request]
    } else {
	::http::log warning "Responding with error: $errMsg"
	set resp [::http::make-bin-svc-err "<p>$errMsg</p>" $request]
    }
    ::http::respond $resp
}

proc set_platforms {} {
    global platforms
    if {$platforms ne ""} {
	return ""
    }
    set errMsg {}
    poll on
    if { [ catch {get_rom_version} rom_ver ] } {
	set errMsg "get_rom_ver err: $rom_ver"
    }
    polloff_n_reset_hard
    if {$errMsg ne {}} {
	error $errMsg
    }
    set platforms $rom_ver
}

if {[info exists ::env(HTTP_APP)] && $::env(HTTP_APP)} {
    source [find app.tcl]
}

::http::add-handler GET /nvds/platforms {
    # Thought: eagerly, rather than lazily, call set_platforms before starting
    # the HTTP server.  Do that once and read the result from that point on out.
    if { [ catch {set_platforms} errMsg ] } {
	::http::log info "Error: $errMsg"
	set resp [::http::make-bin-svc-err "<p>$errMsg</p>" $request]
    } else {
	global platforms
	::http::log info "Platforms: $platforms"
	set resp [::http::make-bin-svc-response [join $platforms ","] {} $request]
    }
    ::http::respond $resp
}

# Start the HTTP server binding it to $ipAddress and $port.  Similar
# to ::http::start-server, but it has no wait.
proc start-server-no-wait {ipAddress port} {
    set ::http::serverSocket [socket stream.server $ipAddress:$port]
    $::http::serverSocket readable {
        set client [$::http::serverSocket accept addr]
        ::http::serve-and-trap-errors $client {*}[split $addr :]
    }
}

proc start-bin-server {args_dict} {
    global ::http::crashOnError
    global ::http::verbosity
    global nvds_tool
    global atm_isp
    dict with args_dict {
	set nvds_tool $nvds_tool
	set atm_isp $atm_isp
	set ::http::verbosity $verbosity
	start-server-no-wait $ip $port
	puts "Info : Listening on port $port for binary http requests"
    }
}
