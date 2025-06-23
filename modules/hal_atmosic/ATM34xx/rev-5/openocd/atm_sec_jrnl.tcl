#
# atm_sec_jrnl.tcl
# Provide secure journal NVDS functions
# Copyright (C) Atmosic 2020-2024
#

set CMSDK_SEC_JOURNAL_BASE 0x8f800
set CMSDK_SEC_JOURNAL_SIZE 1776
set CMSDK_SEC_JOURNAL_RATCHET 0x8FEF0
set CMSDK_SEC_JOURNAL_OTP_BIT 53

set SEC_JRNL_MAGIC_OFFSET 0
set SEC_JRNL_MAGIC_LEN 4
set SEC_JRNL_FIRST_TAG_OFFSET [expr {$SEC_JRNL_MAGIC_OFFSET + $SEC_JRNL_MAGIC_LEN}]


# Get current ratchet value of secure journal
# Reading of the ratchet RRAM location side-loads the ratchet value into the
# hardware. This overwrites the default 0xFFFF that loads on reset
proc atm_sec_jrnl_get_ratchet { } {
    mrh $::CMSDK_SEC_JOURNAL_RATCHET
    # Need to do a double read since out of reset, takes 1 read to get value
    set counter_zero [mrh $::CMSDK_SEC_JOURNAL_RATCHET]
    return $counter_zero
}

# Verify ratchet value of secure journal
proc atm_sec_jrnl_verify_ratchet { value } {
    set ratchet_val [atm_sec_jrnl_get_ratchet]
    if {($ratchet_val != $value)} {
	return 0
    }
    return 1
}

# Asserts if the secure journal is enabled and in use
proc atm_sec_jrnl_is_enabled { } {
    return [otp_read_bit $::CMSDK_SEC_JOURNAL_OTP_BIT]
}

# Precheck to see if image can be loaded into secure journal
proc atm_sec_jrnl_precheck { image } {
    set old_sec_jrnl_file_path [format "%s.oldsec" $image]
    dump_image $old_sec_jrnl_file_path $::CMSDK_SEC_JOURNAL_BASE $::CMSDK_SEC_JOURNAL_SIZE
    set orig_fp [open $old_sec_jrnl_file_path rb]
    set new_fp [open $image rb]
    fconfigure $orig_fp -translation binary
    fconfigure $new_fp -translation binary

    set ratchet_val [atm_sec_jrnl_get_ratchet]
    set orig_data [read $orig_fp $ratchet_val]
    set new_data [read $new_fp $ratchet_val]
    close $orig_fp
    close $new_fp
    file delete $old_sec_jrnl_file_path
    if {$orig_data ne $new_data} {
	return 0
    }
    return 1
}

# increment ratchet to specific offset
proc atm_sec_jrnl_incr_ratchet_to { count } {
    set ratchet_val [atm_sec_jrnl_get_ratchet]
    if {$count <= $ratchet_val} {
	error "Unable to increment, requested ratchet is smaller than current"
    }
    if {$count > $::CMSDK_SEC_JOURNAL_SIZE} {
	error "Unable to increment, requested ratchet exceeds secure journal size"
    }

    rram_write_enable
    adapter speed 70
    while {$ratchet_val < $count} {
	# Allows ratchet to be tested without blowing OTP bit.
	# Same result, when OTP bit is blown
	set ratchet_val [expr {$ratchet_val + 1}]
	mwh $::CMSDK_SEC_JOURNAL_RATCHET $ratchet_val
    }
    adapter speed $::_SWD_KHZ
    rram_write_disable

    set verified [atm_sec_jrnl_verify_ratchet $ratchet_val]
    if {([expr {!$verified}])} {
	error "Failed to increment ratchet to requested value!"
    }

    puts "ratchet set to: [atm_sec_jrnl_get_ratchet]"
}

proc atm_erase_sec_jrnl_nvds { } {
    if { [atm_sec_jrnl_is_enabled] } {
	puts "WARNING: Can only erase 'unratcheted data'.  All ratcheted data will remain."
    } else {
	# reset the ratchet to zero
	rram_write_enable
	adapter speed 70
	mwh $::CMSDK_SEC_JOURNAL_RATCHET 0
	adapter speed $::_SWD_KHZ
	rram_write_disable
	set verified [atm_sec_jrnl_verify_ratchet 0]
	if {([expr {!$verified}])} {
	    error "Failed to clear ratchet!!"
	}
    }
    set ratchet_val [atm_sec_jrnl_get_ratchet]
    set erase_start [expr { $::CMSDK_SEC_JOURNAL_BASE + $ratchet_val }]
    set erase_size [expr { $::CMSDK_SEC_JOURNAL_SIZE - $ratchet_val }]
    atm_erase_rram_byte $erase_start $erase_size
    puts "Erasing Secure Journal @$erase_start size: $erase_size"
}

proc atm_dump_sec_jrnl_nvds { image } {
    dump_image $image $::CMSDK_SEC_JOURNAL_BASE $::CMSDK_SEC_JOURNAL_SIZE
}

proc load_offset_image {fname offset address length } {
    load_image $fname [expr {$address - $offset}] bin $address $length
}

# load new secure journal data
# set ratchet_data to 1 to lockdown programmed NVDS
proc atm_load_sec_jrnl_nvds { image {ratchet_data 0}} {
    set new_sec_jrnl_size [file size $image]
    set cur_sec_jrnl_size [atm_sec_jrnl_get_ratchet]

    if {$new_sec_jrnl_size <= $cur_sec_jrnl_size} {
	error "Unable to load, new data is smaller than ratchet size"
    }
    if {$new_sec_jrnl_size > $::CMSDK_SEC_JOURNAL_SIZE} {
	error "Unable to load, new data exceeds secure journal size"
    }

    set pre_check [atm_sec_jrnl_precheck $image]
    if {[expr {!$pre_check}]} {
	error "Mismatch between sec_jrnl and passed image!"
    }

    rram_write_enable
    adapter speed 70
    set sec_jrnl_write_off [expr { $::CMSDK_SEC_JOURNAL_BASE+$cur_sec_jrnl_size }]
    set w_size [expr { $new_sec_jrnl_size-$cur_sec_jrnl_size }]
    puts -nonewline [load_offset_image $image $cur_sec_jrnl_size $sec_jrnl_write_off $w_size]
    adapter speed $::_SWD_KHZ
    rram_write_disable

    set is_en [atm_sec_jrnl_is_enabled]
    # Even if secure counter is enabled, user does not need to ratched down the value.
    if {$ratchet_data} {
	if {[expr {!$is_en}]} {
	    puts "WARNING: Even with incrementing ratchet, data will remain mutable."
	    puts "    Please blow sec journal OTP bit to make data immutable"
	}
	atm_sec_jrnl_incr_ratchet_to [expr { $new_sec_jrnl_size - 4 }]
    } elseif {$is_en} {
	puts "WARNING: Journal was updated([expr { $new_sec_jrnl_size - 4 }] bytes) but"
	puts "    the ratchet is only protecting $cur_sec_jrnl_size bytes."
    }
}

proc atm_verify_sec_jrnl_nvds { image } {
    atm_verify_rram $image
}

# get size of secure journal tag: header(tag, status, length (VLQ)) + data
proc atm_sec_jrnl_get_tag_size { jrnl_header } {
    set jrnl_length [mrb [expr {$jrnl_header + 2}]]
    set header_size 3
    set tag_len [expr {$jrnl_length & 0x7f}]
    if {$jrnl_length & 0x80} {
	incr header_size 1
	set tag_len_append [mrb [expr {$jrnl_header + 3}]]
	set tag_len [expr {$tag_len | ($tag_len_append << 7)}]
    }
    return [expr {$header_size + $tag_len}]
}

proc atm_sec_jrnl_tag_print { tag } {
    set jrnl_header [atm_sec_jrnl_find_tag $tag 1]
    if {$jrnl_header == -1} {
	return
    }
    set jrnl_length [mrb [expr {$jrnl_header + 2}]]
    set header_size 3
    set tag_len [expr {$jrnl_length & 0x7f}]
    if {$jrnl_length & 0x80} {
	incr header_size 1
	set tag_len_append [mrb [expr {$jrnl_header + 3}]]
	set tag_len [expr {$tag_len | ($tag_len_append << 7)}]
    }
    set ptr [expr {$header_size + $jrnl_header}]
    set hexstr {}
    while {$tag_len > 0} {
	set hexstr $hexstr[format "%02x" [mrb $ptr]]
	incr ptr 1
	incr tag_len -1
    }
    puts "tag $tag: $hexstr"
}

# verify magic bytes to be 'N' 'V' 'D' 'S'
proc atm_sec_jrnl_verify_magic {{silent 0}} {
    set magic [mrw $::CMSDK_SEC_JOURNAL_BASE]
    binary scan [binary format w $magic] A* magic_str
    if {[string equal $magic_str "NVDS"]} {return 1}
    if {!$silent} {
	puts "Secure Journal not configured."
    }
    return 0
}

# find sec_jrnl_tag
proc atm_sec_jrnl_find_tag { tag {silent 0}} {
    if { ![atm_sec_jrnl_verify_magic $silent] } { return -1 }
    set sec_jrnl_end [expr {$::CMSDK_SEC_JOURNAL_BASE + $::CMSDK_SEC_JOURNAL_SIZE}]
    set jrnl_header [expr {$::CMSDK_SEC_JOURNAL_BASE + $::SEC_JRNL_FIRST_TAG_OFFSET}]
    set jrnl_header_tag [mrb $jrnl_header]
    while {$jrnl_header_tag != $tag} {
	set jrnl_header [expr {[atm_sec_jrnl_get_tag_size $jrnl_header] + $jrnl_header}]
	if {$jrnl_header >= $sec_jrnl_end} {
	    if {!$silent} {
		puts "Reached end of secure journal, tag not found."
	    }
	    return -1
	}
	set jrnl_header_tag [mrb $jrnl_header]
	if {$jrnl_header_tag == 0xff} {
	    if {!$silent} {
		puts "Tag not found."
	    }
	    return -1
	}
    }
    return $jrnl_header
}
