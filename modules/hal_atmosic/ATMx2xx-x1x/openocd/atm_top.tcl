#
# atm_top.tcl
# Production top level for ATM2/ATM3 devices
# Copyright (C) Atmosic 2018-2022
#

source [find mem_helper.tcl]

set CMSDK_ROM_BASE   0x00000000
set CMSDK_FLASH_BASE 0x10000000
set CMSDK_RAM_BASE   0x20000000
set CMSDK_EM_BASE    0x30008000
set CMSDK_AHB_NVM_BASE		0x60000000
set CMSDK_AT_DMA_BASE		0x70000000
set CMSDK_AHB_PDM_PP_BASE	0x80000000

source [find atm2x_peripheral_wrapper_operations.tcl]
source [find atm2x_pseq.tcl]
source [find atm2x_flash.tcl]
source [find atm_nvds.tcl]
source [find atm2x_gdb.tcl]
source [find atm2x_nvm.tcl]
source [find atm2x_rom.tcl]
source [find atm_coredump.tcl]
source [find coredump.tcl]
