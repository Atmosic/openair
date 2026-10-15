# Copyright (c) 2022-2026 Atmosic
#
# SPDX-License-Identifier: LicenseRef-Atmosic
#
# Production top level for ATM34 devices

source [find mem_helper.tcl]

set CMSDK_ROM_BASE   0x00000000
set CMSDK_ROM_SIZE   0x80000
set CMSDK_FLASH_BASE 0x00200000
set CMSDK_RAM_BASE   0x20000000
set CMSDK_RAM_SIZE   0x40000
set CMSDK_TCM_BASE   0x40128000

set SX "_SECURE"
source [find atm_peripheral_wrapper_operations.tcl]
source [find atm_pseq.tcl]
source [find atm_flash.tcl]
source [find atm_nvds.tcl]
source [find atm_otp.tcl]
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
