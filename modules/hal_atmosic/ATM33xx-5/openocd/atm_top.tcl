#
# atm_top.tcl
# Production top level for ATM33 devices
# Copyright (C) Atmosic 2022
#

source [find mem_helper.tcl]

set CMSDK_ROM_BASE   0x00000000
set CMSDK_ROM_SIZE   0x10000
set CMSDK_RRAM_BASE  0x00010000
set CMSDK_RRAM_SIZE  0x80000
set CMSDK_FLASH_BASE 0x00200000
set CMSDK_RAM_BASE   0x20000000
set CMSDK_RAM_SIZE   0x20000
set CMSDK_EM_BASE    0x40128000

set SX "_SECURE"
source [find atm_peripheral_wrapper_operations.tcl]
source [find atm2x_pseq.tcl]
source [find atm_flash.tcl]
source [find atm_rram.tcl]
source [find atm_nvds.tcl]
source [find atm_otp.tcl]
source [find atm_sec_cntr_keys.tcl]
source [find atm_sec_jrnl.tcl]
source [find atm_rom.tcl]
source [find atm2x_gdb.tcl]
source [find atm_coredump.tcl]
source [find coredump.tcl]
source [find trustzone/sec_priv_ctrl_secure.tcl]
source [find trustzone/mpc_fls_secure.tcl]
source [find trustzone/mpc_ram0_secure.tcl]
source [find trustzone/mpc_ram1_secure.tcl]
source [find trustzone/mpc_ram2_secure.tcl]
source [find trustzone/mpc_ram3_secure.tcl]
