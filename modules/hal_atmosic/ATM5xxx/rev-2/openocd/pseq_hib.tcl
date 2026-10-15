poll off

source [find mem_helper.tcl]
set SX "_SECURE"
source [find atm_peripheral_wrapper_operations.tcl]

# lpc freq in Hz
proc pseq_hib {} {
  set lpc_f 32768 
  enable_pseq 
  # set up hib wake mask
  namespace eval ::CMSDK_PSEQ${::SX}::HIB_WAKE_MASK {
	WATCH_CNTDOWN::SET_TGT [REG_ADDR]
  }
  puts "RESET CTRL0"
  mww [::CMSDK_PSEQ${::SX}::CTRL0] 0x20000
  # set up timer dur
  
  set dur 5; # seconds
  # converting second to num LPC
  set dur_lpc [expr { $dur * $lpc_f } ] 
  mww [::CMSDK_PSEQ${::SX}::INIT_COUNT_DOWN] $dur_lpc

  puts "loading the counter value"
  namespace eval ::CMSDK_PSEQ${::SX}::COUNTER_CONTROL {
	  LOAD_COUNT_DOWN_TIMER::SET_TGT [REG_ADDR]
  }
  sleep 2
  namespace eval ::CMSDK_PSEQ${::SX}::COUNTER_CONTROL {
	  LOAD_COUNT_DOWN_TIMER::CLR_TGT [REG_ADDR]
  }

  sleep 2
  puts "wait until no pending"
  set load_pending 1 
  #while {$load_pending} {
  #  namespace eval ::CMSDK_PSEQ${::SX}::INST_PENDING {
  #    set load_pending [CNTDWN_TIMER_LOAD::READ [REG_ADDR]]
  #  }
  #  set msg [format "load_pending %x" $load_pending]
  #  puts $msg
  #}
  puts "Block DBG_WAKE"
  namespace eval ::CMSDK_PSEQ${::SX}::CTRL0 {
    BLOCK_DBG_WAKE::MODIFY_TGT [REG_ADDR] 1
  }
  puts "Manage xtal"
  namespace eval ::CMSDK_PSEQ${::SX}::CTRL0 {
    MANAGE_XTAL::MODIFY_TGT [REG_ADDR] 1
  }

  puts "Trigger HIB"
  namespace eval ::CMSDK_PSEQ${::SX}::CTRL0 {
    #REQ_HIB_TO_ACT::MODIFY_TGT [REG_ADDR] 1
    REQ_HIBERNATE_STATE::MODIFY_TGT [REG_ADDR] 1
  }

  
  puts "wait for wakeup based on dur above"
  set wait_time_ms [expr { $dur * 1000 } ];
  set wait_time_ms [expr { $wait_time_ms + 10 } ];

  sleep $wait_time_ms
  puts "wait for wakeup based on dur done"

}
proc pseq_hib_wakeup_init {} {
  enable_pseq 
  sleep 2
  puts "RESET CTRL0"
  mww [::CMSDK_PSEQ${::SX}::CTRL0] 0x20000
  
  enable_pseq 
  puts "MOVE to ACTIVE STATE"
  namespace eval ::CMSDK_PSEQ${::SX}::CTRL0 {
    REQ_BLE_TO_BOOT::MODIFY_TGT [REG_ADDR] 1
  }
  sleep 2
  puts "MOVE to ACTIVE STATE"
  namespace eval ::CMSDK_PSEQ${::SX}::CTRL0 {
    REQ_BLE_TO_BOOT::MODIFY_TGT [REG_ADDR] 0
  }

}

# lpc freq in Hz
proc pseq_ret {} {
  set lpc_f 32768 
  enable_pseq 
  # set up hib wake mask
  namespace eval ::CMSDK_PSEQ${::SX}::RETAIN_ALL_WAKE_MASK {
	WATCH_CNTDOWN::SET_TGT [REG_ADDR]
  }

  puts "MOVE to ACTIVE STATE"
  namespace eval ::CMSDK_PSEQ${::SX}::CTRL0 {
    REQ_BLE_TO_BOOT::MODIFY_TGT [REG_ADDR] 1
  }
  puts "MOVE to ACTIVE STATE"
  namespace eval ::CMSDK_PSEQ${::SX}::CTRL0 {
    REQ_BLE_TO_BOOT::MODIFY_TGT [REG_ADDR] 0
  }
  # set up timer dur
  
  set dur 2; # seconds
  # converting second to num LPC
  set dur_lpc [expr { $dur * $lpc_f } ] 
  mww [::CMSDK_PSEQ${::SX}::INIT_COUNT_DOWN] $dur_lpc

  puts "loading the counter value"
  namespace eval ::CMSDK_PSEQ${::SX}::COUNTER_CONTROL {
	  LOAD_COUNT_DOWN_TIMER::SET_TGT [REG_ADDR]
  }
  namespace eval ::CMSDK_PSEQ${::SX}::COUNTER_CONTROL {
	  LOAD_COUNT_DOWN_TIMER::CLR_TGT [REG_ADDR]
  }

  puts "wait until no pending"
  set load_pending 1 
  #while {$load_pending} {
  #  namespace eval ::CMSDK_PSEQ${::SX}::INST_PENDING {
  #    set load_pending [CNTDWN_TIMER_LOAD::READ [REG_ADDR]]
  #  }
  #  set msg [format "load_pending %x" $load_pending]
  #  puts $msg
  #}
  puts "Block DBG_WAKE"
  namespace eval ::CMSDK_PSEQ${::SX}::CTRL0 {
    BLOCK_DBG_WAKE::MODIFY_TGT [REG_ADDR] 1
  }
  puts "Manage xtal"
  namespace eval ::CMSDK_PSEQ${::SX}::CTRL0 {
    MANAGE_XTAL::MODIFY_TGT [REG_ADDR] 1
  }

  puts "Trigger RETAIN"
  namespace eval ::CMSDK_PSEQ${::SX}::CTRL0 {
    REQ_RETAIN_ALL_STATE::MODIFY_TGT [REG_ADDR] 1
  }

  
  puts "wait for wakeup based on dur above"
  set wait_time_ms [expr { $dur * 1000 } ];
  set wait_time_ms [expr { $wait_time_ms + 1 } ];

  sleep $wait_time_ms
  

}
