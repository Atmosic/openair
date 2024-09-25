/**
 *******************************************************************************
 *
 * @file at_tz_ppc.h
 *
 * @brief Peripheral protection controller driver
 *
 * Copyright (C) Atmosic 2022
 *
 *******************************************************************************
 */

#pragma once

#include "arch.h"

/**
 * @defgroup AT_TZ_PPC PPC
 * @ingroup DRIVERS
 * @brief Trustzone PPC driver
 *
 * This module contains the necessary functions to manage peripheral
 * protection controllers
 *
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/// PERIPHERAL(peripheral, name prefix, bus, peripheral controller)
#define CMSDK_PPC_PERIPHERALS \
    PERIPHERAL(DMA, AT_, AHB, PPCEXP1) \
    PERIPHERAL(SHA2,, AHB, PPCEXP1) \
    PERIPHERAL(QSPI,, APB, PPCEXP0) \
    PERIPHERAL(SLWTIMER,, APB, PPCEXP0) \
    PERIPHERAL(SPI1,, APB, PPCEXP0) \
    PERIPHERAL(QDEC,, APB, PPCEXP0) \
    PERIPHERAL(SPI2,, APB, PPCEXP0) \
    PERIPHERAL(KSM,, APB, PPCEXP0) \
    PERIPHERAL(SPI0,, APB, PPCEXP0) \
    PERIPHERAL(PWM,, APB, PPCEXP0) \
    PERIPHERAL(UART1, AT_, APB, PPCEXP0) \
    PERIPHERAL(UART0, AT_, APB, PPCEXP0) \
    PERIPHERAL(SHUB,, APB, PPCEXP1) \
    PERIPHERAL(RCOS_CAL,, APB, PPCEXP1) \
    PERIPHERAL(SWD,, APB, PPCEXP1) \
    PERIPHERAL(TRNG,, APB, PPCEXP1) \
    PERIPHERAL(GADC,, APB, PPCEXP1) \
    PERIPHERAL(PSEQ,, APB, PPCEXP1) \
    PERIPHERAL(PMU,, APB, PPCEXP1) \
    PERIPHERAL(MDM,, APB, PPCEXP1) \
    PERIPHERAL(RADIO,, APB, PPCEXP1) \
    PERIPHERAL(RIF,, APB, PPCEXP1) \
    PERIPHERAL(NVM,, APB, PPCEXP1) \
    PERIPHERAL(I2C0,, APB, PPCEXP1) \
    PERIPHERAL(AES,, APB, PPCEXP2) \
    PERIPHERAL(CLKRSTGEN,, APB, PPCEXP2) \

/// These are peripherals that follow an alternative address naming conv.
/// ALT_PERIPHERAL(peripheral, address, bus, controller)
#define ALT_PPC_PERIPHERALS \
    ALT_PERIPHERAL(GPIO0, CMSDK_GPIO0, AHB, PPCEXP1) \
    ALT_PERIPHERAL(GPIO1, CMSDK_GPIO1, AHB, PPCEXP1) \
    ALT_PERIPHERAL(BLE52, ((void *)BLE_NONSECURE_BASE), AHB, PPCEXP1) \
    ALT_PERIPHERAL(BLE52, ((void *)BLE_SECURE_BASE), AHB, PPCEXP1) \
    ALT_PERIPHERAL(WRPR, CMSDK_WRPR0_SECURE, APB, PPCEXP0) \
    ALT_PERIPHERAL(WRPR, CMSDK_WRPR0_NONSECURE, APB, PPCEXP0) \
    ALT_PERIPHERAL(WRPR, CMSDK_WRPR1_SECURE, APB, PPCEXP1) \
    ALT_PERIPHERAL(WRPR, CMSDK_WRPR1_NONSECURE, APB, PPCEXP1) \
    ALT_PERIPHERAL(WRPR, CMSDK_WRPR2_SECURE, APB, PPCEXP2) \
    ALT_PERIPHERAL(WRPR, CMSDK_WRPR2_NONSECURE, APB, PPCEXP2) \

/// DUAL_PERIPHERAL(peripheral, ext, bus1, controller1, bus2, controller2)
#define DUAL_PPC_PERIPHERALS \
    DUAL_PERIPHERAL(I2S,, AHB, PPCEXP1, APB, PPCEXP2) \
    DUAL_PERIPHERAL(PDM0,, AHB, PPCEXP1, APB, PPCEXP2) \
    DUAL_PERIPHERAL(PDM1,, AHB, PPCEXP1, APB, PPCEXP2) \

/// SSE200 base peripherals follow separate PPC mask naming conv.
/// BASE_PERIPHERAL(peripheral, address, bus, controller)
#define BASE_PPC_PERIPHERALS \
    BASE_PERIPHERAL(MHU1, MHU_1, APB, PPC0) \
    BASE_PERIPHERAL(MHU0, MHU_0, APB, PPC0) \
    BASE_PERIPHERAL(DTIMER, CMSDK_DUALTIMER, APB, PPC0) \
    BASE_PERIPHERAL(TIMER1, CMSDK_TIMER1, APB, PPC0) \
    BASE_PERIPHERAL(TIMER0, CMSDK_TIMER0, APB, PPC0) \
    BASE_PERIPHERAL(S32K_Timer, S32_TIMER, APB, PPC1) \


/// Set bit at ppc bank
#define PPC_BANK_MODIFY_BIT(bank, pos, value) do { \
    bank = ((bank) & ~(1UL << (pos))) | (((value) << (pos))); \
} while (0)

/* Privilege attribute used to configure the peripheral */
typedef enum {
    /// Allows both privileged access only
    ATM_PPC_PRIV_ONLY,
    /// Allows both privileged and unprivileged access
    ATM_PPC_PRIV_UNPRIV,
} atm_ppc_priv_attr_t;

#ifdef SECURE_MODE

/* Secure attribute used to configure the peripheral */
typedef enum {
    ATM_PPC_SECURE,
    ATM_PPC_NONSECURE,
} atm_ppc_sec_attr_t;

/**
 * @brief Set peripheral to secure or non-secure state
 *
 * @param[in] peripheral pointer to peripheral
 * @param[in] secure sets peripheral to secure or non-secure
 */
__NONNULL(1)
__STATIC_INLINE void at_tz_ppc_configure(void const *peripheral,
    atm_ppc_sec_attr_t secure)
{
#define PERIPHERAL(PERI, EXT, BUS, BANK) \
    case ((uintptr_t) CMSDK_##EXT##PERI##_NONSECURE): \
    case ((uintptr_t) CMSDK_##EXT##PERI##_SECURE): \
	PPC_BANK_MODIFY_BIT(SEC_CTRL_REG->BUS##NS##BANK, \
	    SEC_PRIV_CTRL_##BUS##NS##BANK##_##PERI##_Pos, secure);\
	break;
// Alt peripherals follow a diff address naming vs reg peripherals
#define ALT_PERIPHERAL(PERI, ADDR, BUS, BANK) \
    case ((uintptr_t) ADDR): \
	PPC_BANK_MODIFY_BIT(SEC_CTRL_REG->BUS##NS##BANK, \
	    SEC_PRIV_CTRL_##BUS##NS##BANK##_##PERI##_Pos, secure); \
	break;
// Dual periphals are peripherals that require setting two controllers.
// register file on APB and fifo on AHB
#define DUAL_PERIPHERAL(PERI, EXT, BUS1, BANK1, BUS2, BANK2) \
    case ((uintptr_t) CMSDK_##EXT##PERI##_NONSECURE): \
    case ((uintptr_t) CMSDK_##EXT##PERI##_SECURE): \
	PPC_BANK_MODIFY_BIT(SEC_CTRL_REG->BUS1##NS##BANK1, \
	    SEC_PRIV_CTRL_##BUS1##NS##BANK1##_##PERI##_Pos, secure); \
	PPC_BANK_MODIFY_BIT(SEC_CTRL_REG->BUS2##NS##BANK2, \
	    SEC_PRIV_CTRL_##BUS2##NS##BANK2##_##PERI##_Pos, secure); \
	break;
// Base peripherals follow a diff address naming vs reg peripherals
#define BASE_PERIPHERAL(PERI, ADDR, BUS, BANK) \
    case ((uintptr_t) ADDR): \
	PPC_BANK_MODIFY_BIT(SEC_CTRL_REG->BUS##NS##BANK, \
	    SEC_PRIV_CTRL_##BUS##NS##BANK##_NS_##PERI##_Pos, secure); \
	break;

    uintptr_t peri = (uintptr_t) peripheral;
    switch(peri) {
	// handle common cmsdk peripherals
	CMSDK_PPC_PERIPHERALS
	// handle peripherals with non-standard naming
	ALT_PPC_PERIPHERALS
	// handle dual ppc peripherals
	DUAL_PPC_PERIPHERALS
	// handle base peripherals
	BASE_PPC_PERIPHERALS
	default: ASSERT_INFO(0, peripheral, secure);
    }
#undef PERIPHERAL
#undef ALT_PERIPHERAL
#undef DUAL_PERIPHERAL
#undef BASE_PERIPHERAL
}

/**
 * @brief Set peripheral privilege in secure state
 *
 * @param[in] peripheral pointer to peripheral
 * @param[in] priv sets peripheral to priv or unpriv in secure space
 */
__NONNULL(1)
__STATIC_INLINE void at_tz_ppc_configure_sec_priv(void const *peripheral,
    atm_ppc_priv_attr_t priv)
{
#define PERIPHERAL(PERI, EXT, BUS, BANK) \
    case ((uintptr_t) CMSDK_##EXT##PERI##_SECURE): \
    case ((uintptr_t) CMSDK_##EXT##PERI##_NONSECURE): \
	PPC_BANK_MODIFY_BIT(SEC_CTRL_REG->BUS##SP##BANK, \
	    SEC_PRIV_CTRL_##BUS##SP##BANK##_##PERI##_Pos, priv);\
	break;
// Alt peripherals follow a diff address naming vs reg peripherals
#define ALT_PERIPHERAL(PERI, ADDR, BUS, BANK) \
    case ((uintptr_t) ADDR): \
	PPC_BANK_MODIFY_BIT(SEC_CTRL_REG->BUS##SP##BANK, \
	    SEC_PRIV_CTRL_##BUS##SP##BANK##_##PERI##_Pos, priv); \
	break;
// Dual periphals are peripherals that require setting two controllers.
// register file on APB and fifo on AHB
#define DUAL_PERIPHERAL(PERI, EXT, BUS1, BANK1, BUS2, BANK2) \
    case ((uintptr_t) CMSDK_##EXT##PERI##_SECURE): \
    case ((uintptr_t) CMSDK_##EXT##PERI##_NONSECURE): \
	PPC_BANK_MODIFY_BIT(SEC_CTRL_REG->BUS1##SP##BANK1, \
	    SEC_PRIV_CTRL_##BUS1##SP##BANK1##_##PERI##_Pos, priv); \
	PPC_BANK_MODIFY_BIT(SEC_CTRL_REG->BUS2##SP##BANK2, \
	    SEC_PRIV_CTRL_##BUS2##SP##BANK2##_##PERI##_Pos, priv); \
	break;
// Base peripherals follow a diff address naming vs reg peripherals
#define BASE_PERIPHERAL(PERI, ADDR, BUS, BANK) \
    case ((uintptr_t) ADDR): \
	PPC_BANK_MODIFY_BIT(SEC_CTRL_REG->BUS##SP##BANK, \
	    SEC_PRIV_CTRL_##BUS##SP##BANK##_SP_##PERI##_Pos, priv); \
	break;

    uintptr_t peri = (uintptr_t) peripheral;
    switch(peri) {
	// handle common cmsdk peripherals
	CMSDK_PPC_PERIPHERALS
	// handle peripherals with non-standard naming
	ALT_PPC_PERIPHERALS
	// handle dual ppc peripherals
	DUAL_PPC_PERIPHERALS
	// handle base peripherals
	BASE_PPC_PERIPHERALS
	default: ASSERT_INFO(0, peripheral, priv);
    }
#undef PERIPHERAL
#undef ALT_PERIPHERAL
#undef DUAL_PERIPHERAL
#undef BASE_PERIPHERAL
}

/**
 * @brief Configure all peripherals to non-secure for basic operation
 */
__STATIC_INLINE void at_tz_ppc_init_ns_cfg(void)
{
    SEC_CTRL_REG->AHBNSPPCEXP1 = SEC_PRIV_CTRL_AHBNSPPCEXP1_BLE52_Msk |
	SEC_PRIV_CTRL_AHBNSPPCEXP1_I2S_Msk |
	SEC_PRIV_CTRL_AHBNSPPCEXP1_PDM1_Msk |
	SEC_PRIV_CTRL_AHBNSPPCEXP1_PDM0_Msk |
	SEC_PRIV_CTRL_AHBNSPPCEXP1_DMA_Msk |
	SEC_PRIV_CTRL_AHBNSPPCEXP1_SHA2_Msk |
	SEC_PRIV_CTRL_AHBNSPPCEXP1_GPIO1_Msk |
	SEC_PRIV_CTRL_AHBNSPPCEXP1_GPIO0_Msk;

    SEC_CTRL_REG->APBNSPPC0 = SEC_PRIV_CTRL_APBNSPPC0_NS_DTIMER_Msk |
	SEC_PRIV_CTRL_APBNSPPC0_NS_TIMER1_Msk |
	SEC_PRIV_CTRL_APBNSPPC0_NS_TIMER0_Msk |
	SEC_PRIV_CTRL_APBNSPPC0_NS_MHU0_Msk |
	SEC_PRIV_CTRL_APBNSPPC0_NS_MHU1_Msk;

    // Leave S32Ktimer as a secure peripheral. PPC1 incorrectly
    // disables secure access to the SYS_CTRL_REG registers which are always
    // secure.
    // SEC_CTRL_REG->APBNSPPC1 = SEC_PRIV_CTRL_APBNSPPC1_NS_S32K_Timer_Msk;

    SEC_CTRL_REG->APBNSPPCEXP0 = SEC_PRIV_CTRL_APBNSPPCEXP0_QSPI_Msk |
	SEC_PRIV_CTRL_APBNSPPCEXP0_SLWTIMER_Msk |
	SEC_PRIV_CTRL_APBNSPPCEXP0_SPI1_Msk |
	SEC_PRIV_CTRL_APBNSPPCEXP0_QDEC_Msk |
	SEC_PRIV_CTRL_APBNSPPCEXP0_SPI2_Msk |
	SEC_PRIV_CTRL_APBNSPPCEXP0_KSM_Msk |
	SEC_PRIV_CTRL_APBNSPPCEXP0_SPI0_Msk |
	SEC_PRIV_CTRL_APBNSPPCEXP0_PWM_Msk |
	SEC_PRIV_CTRL_APBNSPPCEXP0_UART1_Msk |
	SEC_PRIV_CTRL_APBNSPPCEXP0_UART0_Msk |
	SEC_PRIV_CTRL_APBNSPPCEXP0_WRPR_Msk;

    SEC_CTRL_REG->APBNSPPCEXP1 = SEC_PRIV_CTRL_APBNSPPCEXP1_ATLC_Msk |
	SEC_PRIV_CTRL_APBNSPPCEXP1_SHUB_Msk |
	SEC_PRIV_CTRL_APBNSPPCEXP1_RCOS_CAL_Msk |
	SEC_PRIV_CTRL_APBNSPPCEXP1_TRNG_Msk |
	SEC_PRIV_CTRL_APBNSPPCEXP1_GADC_Msk |
	SEC_PRIV_CTRL_APBNSPPCEXP1_PSEQ_Msk |
	SEC_PRIV_CTRL_APBNSPPCEXP1_PMU_Msk |
	SEC_PRIV_CTRL_APBNSPPCEXP1_MDM_Msk |
	SEC_PRIV_CTRL_APBNSPPCEXP1_RADIO_Msk |
	SEC_PRIV_CTRL_APBNSPPCEXP1_RIF_Msk |
	SEC_PRIV_CTRL_APBNSPPCEXP1_WRPR_Msk |
	SEC_PRIV_CTRL_APBNSPPCEXP1_NVM_Msk |
	SEC_PRIV_CTRL_APBNSPPCEXP1_I2C1_Msk |
	SEC_PRIV_CTRL_APBNSPPCEXP1_SWD_Msk |
	SEC_PRIV_CTRL_APBNSPPCEXP1_I2C0_Msk;

    SEC_CTRL_REG->APBNSPPCEXP2 = SEC_PRIV_CTRL_APBNSPPCEXP2_AES_Msk |
	SEC_PRIV_CTRL_APBNSPPCEXP2_CLKRSTGEN_Msk |
	SEC_PRIV_CTRL_APBNSPPCEXP2_I2S_Msk |
	SEC_PRIV_CTRL_APBNSPPCEXP2_WRPR_Msk |
	SEC_PRIV_CTRL_APBNSPPCEXP2_PDM1_Msk |
	SEC_PRIV_CTRL_APBNSPPCEXP2_PDM0_Msk;

    // Set all peripherals to unprivileged mode.
    SEC_CTRL_REG->AHBSPPPCEXP1 = SEC_PRIV_CTRL_AHBSPPPCEXP1_BLE52_Msk |
	SEC_PRIV_CTRL_AHBSPPPCEXP1_I2S_Msk |
	SEC_PRIV_CTRL_AHBSPPPCEXP1_PDM1_Msk |
	SEC_PRIV_CTRL_AHBSPPPCEXP1_PDM0_Msk |
	SEC_PRIV_CTRL_AHBSPPPCEXP1_DMA_Msk |
	SEC_PRIV_CTRL_AHBSPPPCEXP1_SHA2_Msk |
	SEC_PRIV_CTRL_AHBSPPPCEXP1_GPIO1_Msk |
	SEC_PRIV_CTRL_AHBSPPPCEXP1_GPIO0_Msk;
    SEC_CTRL_REG->APBSPPPC0 = SEC_PRIV_CTRL_APBSPPPC0_SP_DTIMER_Msk |
	SEC_PRIV_CTRL_APBSPPPC0_SP_TIMER1_Msk |
	SEC_PRIV_CTRL_APBSPPPC0_SP_TIMER0_Msk |
	SEC_PRIV_CTRL_APBSPPPC0_SP_MHU0_Msk |
	SEC_PRIV_CTRL_APBSPPPC0_SP_MHU1_Msk;
    SEC_CTRL_REG->APBSPPPC1 = SEC_PRIV_CTRL_APBSPPPC1_SP_S32K_Timer_Msk;
    SEC_CTRL_REG->APBSPPPCEXP0 = SEC_PRIV_CTRL_APBSPPPCEXP0_QSPI_Msk |
	SEC_PRIV_CTRL_APBSPPPCEXP0_SLWTIMER_Msk |
	SEC_PRIV_CTRL_APBSPPPCEXP0_SPI1_Msk |
	SEC_PRIV_CTRL_APBSPPPCEXP0_QDEC_Msk |
	SEC_PRIV_CTRL_APBSPPPCEXP0_SPI2_Msk |
	SEC_PRIV_CTRL_APBSPPPCEXP0_KSM_Msk |
	SEC_PRIV_CTRL_APBSPPPCEXP0_SPI0_Msk |
	SEC_PRIV_CTRL_APBSPPPCEXP0_PWM_Msk |
	SEC_PRIV_CTRL_APBSPPPCEXP0_UART1_Msk |
	SEC_PRIV_CTRL_APBSPPPCEXP0_UART0_Msk |
	SEC_PRIV_CTRL_APBSPPPCEXP0_WRPR_Msk;
    SEC_CTRL_REG->APBSPPPCEXP1 = SEC_PRIV_CTRL_APBSPPPCEXP1_ATLC_Msk |
	SEC_PRIV_CTRL_APBSPPPCEXP1_SHUB_Msk |
	SEC_PRIV_CTRL_APBSPPPCEXP1_RCOS_CAL_Msk |
	SEC_PRIV_CTRL_APBSPPPCEXP1_TRNG_Msk |
	SEC_PRIV_CTRL_APBSPPPCEXP1_GADC_Msk |
	SEC_PRIV_CTRL_APBSPPPCEXP1_PSEQ_Msk |
	SEC_PRIV_CTRL_APBSPPPCEXP1_PMU_Msk |
	SEC_PRIV_CTRL_APBSPPPCEXP1_MDM_Msk |
	SEC_PRIV_CTRL_APBSPPPCEXP1_RADIO_Msk |
	SEC_PRIV_CTRL_APBSPPPCEXP1_RIF_Msk |
	SEC_PRIV_CTRL_APBSPPPCEXP1_WRPR_Msk |
	SEC_PRIV_CTRL_APBSPPPCEXP1_NVM_Msk |
	SEC_PRIV_CTRL_APBSPPPCEXP1_I2C1_Msk |
	SEC_PRIV_CTRL_APBSPPPCEXP1_SWD_Msk |
	SEC_PRIV_CTRL_APBSPPPCEXP1_I2C0_Msk;
    SEC_CTRL_REG->APBSPPPCEXP2 = SEC_PRIV_CTRL_APBSPPPCEXP2_AES_Msk |
	SEC_PRIV_CTRL_APBSPPPCEXP2_CLKRSTGEN_Msk |
	SEC_PRIV_CTRL_APBSPPPCEXP2_I2S_Msk |
	SEC_PRIV_CTRL_APBSPPPCEXP2_WRPR_Msk |
	SEC_PRIV_CTRL_APBSPPPCEXP2_PDM1_Msk |
	SEC_PRIV_CTRL_APBSPPPCEXP2_PDM0_Msk;

    NONSEC_CTRL_REG->AHBNSPPPCEXP1 = NONSEC_PRIV_CTRL_AHBNSPPPCEXP1_BLE52_Msk |
	NONSEC_PRIV_CTRL_AHBNSPPPCEXP1_I2S_Msk |
	NONSEC_PRIV_CTRL_AHBNSPPPCEXP1_PDM1_Msk |
	NONSEC_PRIV_CTRL_AHBNSPPPCEXP1_PDM0_Msk |
	NONSEC_PRIV_CTRL_AHBNSPPPCEXP1_DMA_Msk |
	NONSEC_PRIV_CTRL_AHBNSPPPCEXP1_SHA2_Msk |
	NONSEC_PRIV_CTRL_AHBNSPPPCEXP1_GPIO1_Msk |
	NONSEC_PRIV_CTRL_AHBNSPPPCEXP1_GPIO0_Msk;
    NONSEC_CTRL_REG->APBNSPPPC0 = NONSEC_PRIV_CTRL_APBNSPPPC0_NSP_DTIMER_Msk |
	NONSEC_PRIV_CTRL_APBNSPPPC0_NSP_TIMER1_Msk |
	NONSEC_PRIV_CTRL_APBNSPPPC0_NSP_TIMER0_Msk |
	NONSEC_PRIV_CTRL_APBNSPPPC0_NSP_MHU0_Msk |
	NONSEC_PRIV_CTRL_APBNSPPPC0_NSP_MHU1_Msk;
    NONSEC_CTRL_REG->APBNSPPPC1 =
	NONSEC_PRIV_CTRL_APBNSPPPC1_NSP_S32K_Timer_Msk;
    NONSEC_CTRL_REG->APBNSPPPCEXP0 = NONSEC_PRIV_CTRL_APBNSPPPCEXP0_QSPI_Msk |
	NONSEC_PRIV_CTRL_APBNSPPPCEXP0_SLWTIMER_Msk |
	NONSEC_PRIV_CTRL_APBNSPPPCEXP0_SPI1_Msk |
	NONSEC_PRIV_CTRL_APBNSPPPCEXP0_QDEC_Msk |
	NONSEC_PRIV_CTRL_APBNSPPPCEXP0_SPI2_Msk |
	NONSEC_PRIV_CTRL_APBNSPPPCEXP0_KSM_Msk |
	NONSEC_PRIV_CTRL_APBNSPPPCEXP0_SPI0_Msk |
	NONSEC_PRIV_CTRL_APBNSPPPCEXP0_PWM_Msk |
	NONSEC_PRIV_CTRL_APBNSPPPCEXP0_UART1_Msk |
	NONSEC_PRIV_CTRL_APBNSPPPCEXP0_UART0_Msk |
	NONSEC_PRIV_CTRL_APBNSPPPCEXP0_WRPR_Msk;
    NONSEC_CTRL_REG->APBNSPPPCEXP1 = NONSEC_PRIV_CTRL_APBNSPPPCEXP1_ATLC_Msk |
	NONSEC_PRIV_CTRL_APBNSPPPCEXP1_SHUB_Msk |
	NONSEC_PRIV_CTRL_APBNSPPPCEXP1_RCOS_CAL_Msk |
	NONSEC_PRIV_CTRL_APBNSPPPCEXP1_TRNG_Msk |
	NONSEC_PRIV_CTRL_APBNSPPPCEXP1_GADC_Msk |
	NONSEC_PRIV_CTRL_APBNSPPPCEXP1_PSEQ_Msk |
	NONSEC_PRIV_CTRL_APBNSPPPCEXP1_PMU_Msk |
	NONSEC_PRIV_CTRL_APBNSPPPCEXP1_MDM_Msk |
	NONSEC_PRIV_CTRL_APBNSPPPCEXP1_RADIO_Msk |
	NONSEC_PRIV_CTRL_APBNSPPPCEXP1_RIF_Msk |
	NONSEC_PRIV_CTRL_APBNSPPPCEXP1_WRPR_Msk |
	NONSEC_PRIV_CTRL_APBNSPPPCEXP1_NVM_Msk |
	NONSEC_PRIV_CTRL_APBNSPPPCEXP1_I2C1_Msk |
	NONSEC_PRIV_CTRL_APBNSPPPCEXP1_SWD_Msk |
	NONSEC_PRIV_CTRL_APBNSPPPCEXP1_I2C0_Msk;
    NONSEC_CTRL_REG->APBNSPPPCEXP2 = NONSEC_PRIV_CTRL_APBNSPPPCEXP2_AES_Msk |
	NONSEC_PRIV_CTRL_APBNSPPPCEXP2_CLKRSTGEN_Msk |
	NONSEC_PRIV_CTRL_APBNSPPPCEXP2_I2S_Msk |
	NONSEC_PRIV_CTRL_APBNSPPPCEXP2_WRPR_Msk |
	NONSEC_PRIV_CTRL_APBNSPPPCEXP2_PDM1_Msk |
	NONSEC_PRIV_CTRL_APBNSPPPCEXP2_PDM0_Msk;
}

#endif //SECURE_MODE

/**
 * @brief Set peripheral privilege in non-secure state
 *
 * @param[in] peripheral pointer to peripheral
 * @param[in] priv sets peripheral to priv or unpriv in non-secure space
 */
__NONNULL(1)
__STATIC_INLINE void at_tz_ppc_configure_nonsec_priv(void const *peripheral,
    atm_ppc_priv_attr_t priv)
{
#define PERIPHERAL(PERI, EXT, BUS, BANK) \
    case ((uintptr_t) CMSDK_##EXT##PERI##_NONSECURE): \
	PPC_BANK_MODIFY_BIT(NONSEC_CTRL_REG->BUS##NSP##BANK, \
	    NONSEC_PRIV_CTRL_##BUS##NSP##BANK##_##PERI##_Pos, priv);\
	break;
// Alt peripherals follow a diff address naming vs reg peripherals
#define ALT_PERIPHERAL(PERI, ADDR, BUS, BANK) \
    case ((uintptr_t) ADDR): \
	PPC_BANK_MODIFY_BIT(NONSEC_CTRL_REG->BUS##NSP##BANK, \
	    NONSEC_PRIV_CTRL_##BUS##NSP##BANK##_##PERI##_Pos, priv); \
	break;
// Dual periphals are peripherals that require setting two controllers.
// register file on APB and fifo on AHB
#define DUAL_PERIPHERAL(PERI, EXT, BUS1, BANK1, BUS2, BANK2) \
    case ((uintptr_t)CMSDK_##EXT##PERI##_NONSECURE): \
	PPC_BANK_MODIFY_BIT(NONSEC_CTRL_REG->BUS1##NSP##BANK1, \
	    NONSEC_PRIV_CTRL_##BUS1##NSP##BANK1##_##PERI##_Pos, priv); \
	PPC_BANK_MODIFY_BIT(NONSEC_CTRL_REG->BUS2##NSP##BANK2, \
	    NONSEC_PRIV_CTRL_##BUS2##NSP##BANK2##_##PERI##_Pos, priv); \
	break;
// Base peripherals follow a diff address naming vs reg peripherals
#define BASE_PERIPHERAL(PERI, ADDR, BUS, BANK) \
    case ((uintptr_t) ADDR): \
	PPC_BANK_MODIFY_BIT(NONSEC_CTRL_REG->BUS##NSP##BANK, \
	    NONSEC_PRIV_CTRL_##BUS##NSP##BANK##_NSP_##PERI##_Pos, priv); \
	break;

    uintptr_t peri = (uintptr_t) peripheral;
    switch(peri) {
	// handle common cmsdk peripherals
	CMSDK_PPC_PERIPHERALS
	// handle peripherals with non-standard naming
	ALT_PPC_PERIPHERALS
	// handle dual ppc peripherals
	DUAL_PPC_PERIPHERALS
	// handle base peripherals
	BASE_PPC_PERIPHERALS
	default: ASSERT_INFO(0, peripheral, priv);
    }
#undef PERIPHERAL
#undef ALT_PERIPHERAL
#undef DUAL_PERIPHERAL
#undef BASE_PERIPHERAL
}


#ifdef __cplusplus
}
#endif

/// @}
