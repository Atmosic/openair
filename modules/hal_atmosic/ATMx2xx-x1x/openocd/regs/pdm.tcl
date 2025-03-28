set CMSDK_PDM_BASE            0x5000f000
set CMSDK_PDM_CONTROL [expr { $CMSDK_PDM_BASE + 0x0 }]
set CMSDK_PDM_CONTROL_ENABLE_DP__RESET_VALUE 0x00000000
set CMSDK_PDM_CONTROL_BYPASS_IIR__RESET_VALUE 0x00000000
set CMSDK_PDM_CONTROL_CAPTURE_ON_RISING__RESET_VALUE 0x00000000
set CMSDK_PDM_CONTROL_PDM_CLK_SEL__RESET_VALUE 0x00000001
set CMSDK_PDM_CONTROL__RESET_VALUE 0x00000008
set CMSDK_PDM_IIR_CONFIG [expr { $CMSDK_PDM_BASE + 0x4 }]
set CMSDK_PDM_IIR_CONFIG_BIT_SHIFT_AMOUNT__RESET_VALUE 0x00000005
set CMSDK_PDM_IIR_CONFIG__RESET_VALUE 0x00000005
set CMSDK_PDM_GAIN_CONTROL_CONFIG [expr { $CMSDK_PDM_BASE + 0x8 }]
set CMSDK_PDM_GAIN_CONTROL_CONFIG_CODE__RESET_VALUE 0x00000040
set CMSDK_PDM_GAIN_CONTROL_CONFIG__RESET_VALUE 0x00000040
set CMSDK_PDM_PCM_SAMPLE [expr { $CMSDK_PDM_BASE + 0xc }]
set CMSDK_PDM_PCM_SAMPLE_DATA__RESET_VALUE 0x00000000
set CMSDK_PDM_PCM_SAMPLE_EMPTY__RESET_VALUE 0x00000000
set CMSDK_PDM_PCM_SAMPLE__RESET_VALUE 0x00000000
set CMSDK_PDM_FIFO_DEBUG [expr { $CMSDK_PDM_BASE + 0x10 }]
set CMSDK_PDM_FIFO_DEBUG_STATUS__RESET_VALUE 0x00000000
set CMSDK_PDM_FIFO_DEBUG__RESET_VALUE 0x00000000
set CMSDK_PDM_INTERRUPTS [expr { $CMSDK_PDM_BASE + 0x14 }]
set CMSDK_PDM_INTERRUPTS_INTRPT0__RESET_VALUE 0x00000000
set CMSDK_PDM_INTERRUPTS_INTRPT1__RESET_VALUE 0x00000000
set CMSDK_PDM_INTERRUPTS_INTRPT2__RESET_VALUE 0x00000000
set CMSDK_PDM_INTERRUPTS_INTRPT3__RESET_VALUE 0x00000000
set CMSDK_PDM_INTERRUPTS_INTRPT4__RESET_VALUE 0x00000000
set CMSDK_PDM_INTERRUPTS_INTRPT5__RESET_VALUE 0x00000000
set CMSDK_PDM_INTERRUPTS__RESET_VALUE 0x00000000
set CMSDK_PDM_INTERRUPT_MASK [expr { $CMSDK_PDM_BASE + 0x18 }]
set CMSDK_PDM_INTERRUPT_MASK_MASK_INTRPT0__RESET_VALUE 0x00000001
set CMSDK_PDM_INTERRUPT_MASK_MASK_INTRPT1__RESET_VALUE 0x00000001
set CMSDK_PDM_INTERRUPT_MASK_MASK_INTRPT2__RESET_VALUE 0x00000001
set CMSDK_PDM_INTERRUPT_MASK_MASK_INTRPT3__RESET_VALUE 0x00000001
set CMSDK_PDM_INTERRUPT_MASK_MASK_INTRPT4__RESET_VALUE 0x00000001
set CMSDK_PDM_INTERRUPT_MASK_MASK_INTRPT5__RESET_VALUE 0x00000001
set CMSDK_PDM_INTERRUPT_MASK__RESET_VALUE 0x0000003f
set CMSDK_PDM_INTERRUPT_CLEAR [expr { $CMSDK_PDM_BASE + 0x1c }]
set CMSDK_PDM_INTERRUPT_CLEAR_CLEAR_INTRPT0__RESET_VALUE 0x00000000
set CMSDK_PDM_INTERRUPT_CLEAR_CLEAR_INTRPT1__RESET_VALUE 0x00000000
set CMSDK_PDM_INTERRUPT_CLEAR_CLEAR_INTRPT2__RESET_VALUE 0x00000000
set CMSDK_PDM_INTERRUPT_CLEAR_CLEAR_INTRPT3__RESET_VALUE 0x00000000
set CMSDK_PDM_INTERRUPT_CLEAR_CLEAR_INTRPT4__RESET_VALUE 0x00000000
set CMSDK_PDM_INTERRUPT_CLEAR_CLEAR_INTRPT5__RESET_VALUE 0x00000000
set CMSDK_PDM_INTERRUPT_CLEAR__RESET_VALUE 0x00000000
set CMSDK_PDM_CORE_ID [expr { $CMSDK_PDM_BASE + 0xffc }]
set CMSDK_PDM_CORE_ID_ID__RESET_VALUE 0x50444d20
set CMSDK_PDM_CORE_ID__RESET_VALUE 0x50444d20
