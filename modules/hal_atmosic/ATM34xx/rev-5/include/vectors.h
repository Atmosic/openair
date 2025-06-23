
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

/// Type for ARM machine vectors
typedef void (*isr_vector_t)(void);

/// ARM machine vectors
#ifdef __ICCARM__
#define __Vectors __vector_table
#endif
extern const isr_vector_t __Vectors[];

/* ARMv8MBL Processor Exceptions */
void NMI_Handler(void);
void HardFault_Handler(void);
void MemManFault_Handler(void);
void BusFault_Handler(void);
void UsageFault_Handler(void);
void SecureFault_Handler(void);
void SVC_Handler(void);
void DebugMon_Handler(void);
void PendSV_Handler(void);
void SysTick_Handler(void);

/* External Exceptions*/
void NsRstWdog_Handler(void);
void NsIntWdog_Handler(void);
void S32kTimer_Handler(void);
void Timer0_Handler(void);
void Timer1_Handler(void);
void Reserved_Handler(void);
void DualTimer_Handler(void);
void MHU0_Handler(void);
void MHU1_Handler(void);
void MPCC_Handler(void);
void PPCC_Handler(void);
void MSC_Handler(void);
void BRD_Handler(void);
void ICACHE_Handler(void);
void SW_0_Handler(void);
void SW_1_Handler(void);
void SW_2_Handler(void);
void SW_3_Handler(void);
void SW_4_Handler(void);
void SW_5_Handler(void);
void SW_6_Handler(void);
void SW_7_Handler(void);
void SW_8_Handler(void);
void SW_9_Handler(void);

/* EXP IRQ */
void UARTRX0_Handler(void);
void UARTTX0_Handler(void);
void UARTRX1_Handler(void);
void UARTTX1_Handler(void);
void UARTRX2_Handler(void);
void UARTTX2_Handler(void);
void SPI1_Handler(void);
void SPI0_Handler(void);
void UARTOVF0_Handler(void);
void UARTOVF1_Handler(void);
void UARTOVF2_Handler(void);
void KSM_Handler(void);
void SLWTIMER_Handler(void);
void SPI2_Handler(void);
void PWM_Handler(void);
void QSPI_BREAKIN_Handler(void);
void SPI_RADIO_Handler(void);
void SPI_PMU_Handler(void);
void I2C0_Handler(void);
void I2C1_Handler(void);
void NVM_Handler(void);
void GADC_Handler(void);
void TRNG_Handler(void);
void RCOS_Handler(void);
void PDM0_Handler(void);
void I2S_Handler(void);
void AES_Handler(void);
void MDM_Handler(void);
void PLL_READY_Handler(void);
void XTAL_STABLE_Handler(void);
void CALTX_DONE_Handler(void);
void DMA0_Handler(void);
void DMA1_Handler(void);
void DMA2_Handler(void);
void DMA3_Handler(void);
void ATLC_FRC_Handler(void);
void PSEQ_FRC0_Handler(void);
void PSEQ_CNTDWN_TIMER_Handler(void);
void PSEQ_CNTDWN_TIMER_1_Handler(void);
void PSEQ_FRC1_Handler(void);
void WAIT4DBLR_Handler(void);
void PSEQ_Handler(void);
void PMU_Handler(void);
void PORT0_COMB_Handler(void);
void PORT1_COMB_Handler(void);
void PORT2_COMB_Handler(void);
void PORT3_COMB_Handler(void);
void ATLC_Handler(void);
void PORT0_0_Handler(void);
void PORT0_1_Handler(void);
void PORT0_2_Handler(void);
void PORT0_3_Handler(void);
void PORT0_4_Handler(void);
void PORT0_5_Handler(void);
void PORT0_6_Handler(void);
void PORT0_7_Handler(void);
void PORT0_8_Handler(void);
void PORT0_9_Handler(void);
void PORT0_10_Handler(void);
void PORT0_11_Handler(void);
void PORT0_12_Handler(void);
void PORT0_13_Handler(void);
void PORT0_14_Handler(void);
void PORT0_15_Handler(void);
void PORT1_0_Handler(void);
void PORT1_1_Handler(void);
void PORT1_2_Handler(void);
void PORT1_3_Handler(void);
void PORT1_4_Handler(void);
void PORT1_5_Handler(void);
void PORT1_6_Handler(void);
void PORT1_7_Handler(void);
void PORT1_8_Handler(void);
void PORT1_9_Handler(void);
void PORT1_10_Handler(void);
void PORT1_11_Handler(void);
void PORT1_12_Handler(void);
void PORT1_13_Handler(void);
void PORT1_14_Handler(void);
void PORT1_15_Handler(void);
void PORT2_0_Handler(void);
void PORT2_1_Handler(void);
void PORT2_2_Handler(void);
void PORT2_3_Handler(void);
void PORT2_4_Handler(void);
void PORT2_5_Handler(void);
void PORT2_6_Handler(void);
void PORT2_7_Handler(void);
void PORT2_8_Handler(void);
void PORT2_9_Handler(void);
void PORT2_10_Handler(void);
void PORT2_11_Handler(void);
void PORT2_12_Handler(void);
void PORT2_13_Handler(void);
void PORT2_14_Handler(void);
void PORT2_15_Handler(void);

#ifdef __cplusplus
}
#endif
