/*                                                                           */
/* File:       radio_rx_regs_core_macro.h                                    */
/*                                                                           */
/* Arguments:  /cad/tools/cadence/blueprint_3.7.5/Linux-64bit/blueprint -eval*/
/*             $DEFINE_PROPERTY=1; -ansic radio_rx_regs_core.rdl             */
/*                                                                           */
/* Blueprint:   3.7.5 (Wed Feb 1 23:58:40 PST 2012)                          */
/* Machine:    gull                                                          */
/* OS:         Linux 2.6.32-696.13.2.el6.x86_64                              */
/* Description:                                                              */
/*                                                                           */
/* No Description Provided                                                   */
/*                                                                           */
/* Copyright (C) 2025 Atmosic Technologies.  All rights reserved             */
/*                                                                           */


#ifndef __REG_RADIO_RX_REGS_CORE_H__
#define __REG_RADIO_RX_REGS_CORE_H__

/**
 *****************************************************************************
 * @defgroup RADIO_RX_REGS_CORE radio_rx_regs_core
 * @ingroup AT_REG
 * @brief radio_rx_regs_core definitions.
 * @{
 *****************************************************************************
 */

/* macros for BlueprintGlobalNameSpace::radio_rx_mode_ctrl */
/**
 * @defgroup radio_rx_regs_core_mode_ctrl mode_ctrl
 * @brief Enable and mode overrides definitions.
 * @{
 */
#ifndef __RADIO_RX_MODE_CTRL_MACRO__
#define __RADIO_RX_MODE_CTRL_MACRO__

/* macros for field lna_en_ovr */
/**
 * @defgroup radio_rx_regs_core_lna_en_ovr_field lna_en_ovr_field
 * @brief macros for field lna_en_ovr
 * @details LNA enable override
 * @{
 */
#define RADIO_RX_MODE_CTRL__LNA_EN_OVR__SHIFT                                 0
#define RADIO_RX_MODE_CTRL__LNA_EN_OVR__WIDTH                                 2
#define RADIO_RX_MODE_CTRL__LNA_EN_OVR__MASK                        0x00000003U
#define RADIO_RX_MODE_CTRL__LNA_EN_OVR__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000003U)
#define RADIO_RX_MODE_CTRL__LNA_EN_OVR__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000003U)
#define RADIO_RX_MODE_CTRL__LNA_EN_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000003U) | ((uint32_t)(src) &\
                    0x00000003U)
#define RADIO_RX_MODE_CTRL__LNA_EN_OVR__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000003U)))
#define RADIO_RX_MODE_CTRL__LNA_EN_OVR__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field lnapd_en_ovr */
/**
 * @defgroup radio_rx_regs_core_lnapd_en_ovr_field lnapd_en_ovr_field
 * @brief macros for field lnapd_en_ovr
 * @details LNA peak detector enable override
 * @{
 */
#define RADIO_RX_MODE_CTRL__LNAPD_EN_OVR__SHIFT                               2
#define RADIO_RX_MODE_CTRL__LNAPD_EN_OVR__WIDTH                               2
#define RADIO_RX_MODE_CTRL__LNAPD_EN_OVR__MASK                      0x0000000cU
#define RADIO_RX_MODE_CTRL__LNAPD_EN_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000000cU) >> 2)
#define RADIO_RX_MODE_CTRL__LNAPD_EN_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x0000000cU)
#define RADIO_RX_MODE_CTRL__LNAPD_EN_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000000cU) | (((uint32_t)(src) <<\
                    2) & 0x0000000cU)
#define RADIO_RX_MODE_CTRL__LNAPD_EN_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x0000000cU)))
#define RADIO_RX_MODE_CTRL__LNAPD_EN_OVR__RESET_VALUE               0x00000000U
/** @} */

/* macros for field mixer_en_ovr */
/**
 * @defgroup radio_rx_regs_core_mixer_en_ovr_field mixer_en_ovr_field
 * @brief macros for field mixer_en_ovr
 * @details Mixer enable override
 * @{
 */
#define RADIO_RX_MODE_CTRL__MIXER_EN_OVR__SHIFT                               4
#define RADIO_RX_MODE_CTRL__MIXER_EN_OVR__WIDTH                               1
#define RADIO_RX_MODE_CTRL__MIXER_EN_OVR__MASK                      0x00000010U
#define RADIO_RX_MODE_CTRL__MIXER_EN_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000010U) >> 4)
#define RADIO_RX_MODE_CTRL__MIXER_EN_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x00000010U)
#define RADIO_RX_MODE_CTRL__MIXER_EN_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | (((uint32_t)(src) <<\
                    4) & 0x00000010U)
#define RADIO_RX_MODE_CTRL__MIXER_EN_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x00000010U)))
#define RADIO_RX_MODE_CTRL__MIXER_EN_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(1) << 4)
#define RADIO_RX_MODE_CTRL__MIXER_EN_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(0) << 4)
#define RADIO_RX_MODE_CTRL__MIXER_EN_OVR__RESET_VALUE               0x00000000U
/** @} */

/* macros for field mixer_enIdual_ovr_val */
/**
 * @defgroup radio_rx_regs_core_mixer_enIdual_ovr_val_field mixer_enIdual_ovr_val_field
 * @brief macros for field mixer_enIdual_ovr_val
 * @details override value for enIdual
 * @{
 */
#define RADIO_RX_MODE_CTRL__MIXER_ENIDUAL_OVR_VAL__SHIFT                      5
#define RADIO_RX_MODE_CTRL__MIXER_ENIDUAL_OVR_VAL__WIDTH                      1
#define RADIO_RX_MODE_CTRL__MIXER_ENIDUAL_OVR_VAL__MASK             0x00000020U
#define RADIO_RX_MODE_CTRL__MIXER_ENIDUAL_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000020U) >> 5)
#define RADIO_RX_MODE_CTRL__MIXER_ENIDUAL_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 5) & 0x00000020U)
#define RADIO_RX_MODE_CTRL__MIXER_ENIDUAL_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | (((uint32_t)(src) <<\
                    5) & 0x00000020U)
#define RADIO_RX_MODE_CTRL__MIXER_ENIDUAL_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 5) & ~0x00000020U)))
#define RADIO_RX_MODE_CTRL__MIXER_ENIDUAL_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(1) << 5)
#define RADIO_RX_MODE_CTRL__MIXER_ENIDUAL_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(0) << 5)
#define RADIO_RX_MODE_CTRL__MIXER_ENIDUAL_OVR_VAL__RESET_VALUE      0x00000000U
/** @} */

/* macros for field mixer_enQdual_ovr_val */
/**
 * @defgroup radio_rx_regs_core_mixer_enQdual_ovr_val_field mixer_enQdual_ovr_val_field
 * @brief macros for field mixer_enQdual_ovr_val
 * @details override value for enQdual
 * @{
 */
#define RADIO_RX_MODE_CTRL__MIXER_ENQDUAL_OVR_VAL__SHIFT                      6
#define RADIO_RX_MODE_CTRL__MIXER_ENQDUAL_OVR_VAL__WIDTH                      1
#define RADIO_RX_MODE_CTRL__MIXER_ENQDUAL_OVR_VAL__MASK             0x00000040U
#define RADIO_RX_MODE_CTRL__MIXER_ENQDUAL_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000040U) >> 6)
#define RADIO_RX_MODE_CTRL__MIXER_ENQDUAL_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 6) & 0x00000040U)
#define RADIO_RX_MODE_CTRL__MIXER_ENQDUAL_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | (((uint32_t)(src) <<\
                    6) & 0x00000040U)
#define RADIO_RX_MODE_CTRL__MIXER_ENQDUAL_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 6) & ~0x00000040U)))
#define RADIO_RX_MODE_CTRL__MIXER_ENQDUAL_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(1) << 6)
#define RADIO_RX_MODE_CTRL__MIXER_ENQDUAL_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(0) << 6)
#define RADIO_RX_MODE_CTRL__MIXER_ENQDUAL_OVR_VAL__RESET_VALUE      0x00000000U
/** @} */

/* macros for field mixer_ensingle_ovr_val */
/**
 * @defgroup radio_rx_regs_core_mixer_ensingle_ovr_val_field mixer_ensingle_ovr_val_field
 * @brief macros for field mixer_ensingle_ovr_val
 * @details override value for ensingle
 * @{
 */
#define RADIO_RX_MODE_CTRL__MIXER_ENSINGLE_OVR_VAL__SHIFT                     7
#define RADIO_RX_MODE_CTRL__MIXER_ENSINGLE_OVR_VAL__WIDTH                     1
#define RADIO_RX_MODE_CTRL__MIXER_ENSINGLE_OVR_VAL__MASK            0x00000080U
#define RADIO_RX_MODE_CTRL__MIXER_ENSINGLE_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000080U) >> 7)
#define RADIO_RX_MODE_CTRL__MIXER_ENSINGLE_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 7) & 0x00000080U)
#define RADIO_RX_MODE_CTRL__MIXER_ENSINGLE_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | (((uint32_t)(src) <<\
                    7) & 0x00000080U)
#define RADIO_RX_MODE_CTRL__MIXER_ENSINGLE_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 7) & ~0x00000080U)))
#define RADIO_RX_MODE_CTRL__MIXER_ENSINGLE_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | ((uint32_t)(1) << 7)
#define RADIO_RX_MODE_CTRL__MIXER_ENSINGLE_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | ((uint32_t)(0) << 7)
#define RADIO_RX_MODE_CTRL__MIXER_ENSINGLE_OVR_VAL__RESET_VALUE     0x00000000U
/** @} */

/* macros for field en_tiaI_ovr */
/**
 * @defgroup radio_rx_regs_core_en_tiaI_ovr_field en_tiaI_ovr_field
 * @brief macros for field en_tiaI_ovr
 * @details Override for I-channel TIA enable
 * @{
 */
#define RADIO_RX_MODE_CTRL__EN_TIAI_OVR__SHIFT                                8
#define RADIO_RX_MODE_CTRL__EN_TIAI_OVR__WIDTH                                2
#define RADIO_RX_MODE_CTRL__EN_TIAI_OVR__MASK                       0x00000300U
#define RADIO_RX_MODE_CTRL__EN_TIAI_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000300U) >> 8)
#define RADIO_RX_MODE_CTRL__EN_TIAI_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00000300U)
#define RADIO_RX_MODE_CTRL__EN_TIAI_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000300U) | (((uint32_t)(src) <<\
                    8) & 0x00000300U)
#define RADIO_RX_MODE_CTRL__EN_TIAI_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00000300U)))
#define RADIO_RX_MODE_CTRL__EN_TIAI_OVR__RESET_VALUE                0x00000000U
/** @} */

/* macros for field en_tiaQ_ovr */
/**
 * @defgroup radio_rx_regs_core_en_tiaQ_ovr_field en_tiaQ_ovr_field
 * @brief macros for field en_tiaQ_ovr
 * @details Override for Q-channel TIA enable
 * @{
 */
#define RADIO_RX_MODE_CTRL__EN_TIAQ_OVR__SHIFT                               10
#define RADIO_RX_MODE_CTRL__EN_TIAQ_OVR__WIDTH                                2
#define RADIO_RX_MODE_CTRL__EN_TIAQ_OVR__MASK                       0x00000c00U
#define RADIO_RX_MODE_CTRL__EN_TIAQ_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000c00U) >> 10)
#define RADIO_RX_MODE_CTRL__EN_TIAQ_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x00000c00U)
#define RADIO_RX_MODE_CTRL__EN_TIAQ_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000c00U) | (((uint32_t)(src) <<\
                    10) & 0x00000c00U)
#define RADIO_RX_MODE_CTRL__EN_TIAQ_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x00000c00U)))
#define RADIO_RX_MODE_CTRL__EN_TIAQ_OVR__RESET_VALUE                0x00000000U
/** @} */

/* macros for field tiapd_en_ovr */
/**
 * @defgroup radio_rx_regs_core_tiapd_en_ovr_field tiapd_en_ovr_field
 * @brief macros for field tiapd_en_ovr
 * @details TIA peak detector enable override
 * @{
 */
#define RADIO_RX_MODE_CTRL__TIAPD_EN_OVR__SHIFT                              12
#define RADIO_RX_MODE_CTRL__TIAPD_EN_OVR__WIDTH                               2
#define RADIO_RX_MODE_CTRL__TIAPD_EN_OVR__MASK                      0x00003000U
#define RADIO_RX_MODE_CTRL__TIAPD_EN_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00003000U) >> 12)
#define RADIO_RX_MODE_CTRL__TIAPD_EN_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x00003000U)
#define RADIO_RX_MODE_CTRL__TIAPD_EN_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00003000U) | (((uint32_t)(src) <<\
                    12) & 0x00003000U)
#define RADIO_RX_MODE_CTRL__TIAPD_EN_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x00003000U)))
#define RADIO_RX_MODE_CTRL__TIAPD_EN_OVR__RESET_VALUE               0x00000000U
/** @} */

/* macros for field en_pgaI_ovr */
/**
 * @defgroup radio_rx_regs_core_en_pgaI_ovr_field en_pgaI_ovr_field
 * @brief macros for field en_pgaI_ovr
 * @details Override for I-channel PGA enable
 * @{
 */
#define RADIO_RX_MODE_CTRL__EN_PGAI_OVR__SHIFT                               14
#define RADIO_RX_MODE_CTRL__EN_PGAI_OVR__WIDTH                                2
#define RADIO_RX_MODE_CTRL__EN_PGAI_OVR__MASK                       0x0000c000U
#define RADIO_RX_MODE_CTRL__EN_PGAI_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000c000U) >> 14)
#define RADIO_RX_MODE_CTRL__EN_PGAI_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 14) & 0x0000c000U)
#define RADIO_RX_MODE_CTRL__EN_PGAI_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000c000U) | (((uint32_t)(src) <<\
                    14) & 0x0000c000U)
#define RADIO_RX_MODE_CTRL__EN_PGAI_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 14) & ~0x0000c000U)))
#define RADIO_RX_MODE_CTRL__EN_PGAI_OVR__RESET_VALUE                0x00000000U
/** @} */

/* macros for field en_pgaQ_ovr */
/**
 * @defgroup radio_rx_regs_core_en_pgaQ_ovr_field en_pgaQ_ovr_field
 * @brief macros for field en_pgaQ_ovr
 * @details Override for Q-channel PGA enable
 * @{
 */
#define RADIO_RX_MODE_CTRL__EN_PGAQ_OVR__SHIFT                               16
#define RADIO_RX_MODE_CTRL__EN_PGAQ_OVR__WIDTH                                2
#define RADIO_RX_MODE_CTRL__EN_PGAQ_OVR__MASK                       0x00030000U
#define RADIO_RX_MODE_CTRL__EN_PGAQ_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00030000U) >> 16)
#define RADIO_RX_MODE_CTRL__EN_PGAQ_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x00030000U)
#define RADIO_RX_MODE_CTRL__EN_PGAQ_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00030000U) | (((uint32_t)(src) <<\
                    16) & 0x00030000U)
#define RADIO_RX_MODE_CTRL__EN_PGAQ_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x00030000U)))
#define RADIO_RX_MODE_CTRL__EN_PGAQ_OVR__RESET_VALUE                0x00000000U
/** @} */

/* macros for field en_osdacI_ovr */
/**
 * @defgroup radio_rx_regs_core_en_osdacI_ovr_field en_osdacI_ovr_field
 * @brief macros for field en_osdacI_ovr
 * @details Override for I-channel TIA and PGA offset DAC enables
 * @{
 */
#define RADIO_RX_MODE_CTRL__EN_OSDACI_OVR__SHIFT                             18
#define RADIO_RX_MODE_CTRL__EN_OSDACI_OVR__WIDTH                              2
#define RADIO_RX_MODE_CTRL__EN_OSDACI_OVR__MASK                     0x000c0000U
#define RADIO_RX_MODE_CTRL__EN_OSDACI_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000c0000U) >> 18)
#define RADIO_RX_MODE_CTRL__EN_OSDACI_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0x000c0000U)
#define RADIO_RX_MODE_CTRL__EN_OSDACI_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000c0000U) | (((uint32_t)(src) <<\
                    18) & 0x000c0000U)
#define RADIO_RX_MODE_CTRL__EN_OSDACI_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x000c0000U)))
#define RADIO_RX_MODE_CTRL__EN_OSDACI_OVR__RESET_VALUE              0x00000000U
/** @} */

/* macros for field en_osdacQ_ovr */
/**
 * @defgroup radio_rx_regs_core_en_osdacQ_ovr_field en_osdacQ_ovr_field
 * @brief macros for field en_osdacQ_ovr
 * @details Override for Q-channel TIA and PGA offset DAC enables
 * @{
 */
#define RADIO_RX_MODE_CTRL__EN_OSDACQ_OVR__SHIFT                             20
#define RADIO_RX_MODE_CTRL__EN_OSDACQ_OVR__WIDTH                              2
#define RADIO_RX_MODE_CTRL__EN_OSDACQ_OVR__MASK                     0x00300000U
#define RADIO_RX_MODE_CTRL__EN_OSDACQ_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00300000U) >> 20)
#define RADIO_RX_MODE_CTRL__EN_OSDACQ_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 20) & 0x00300000U)
#define RADIO_RX_MODE_CTRL__EN_OSDACQ_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00300000U) | (((uint32_t)(src) <<\
                    20) & 0x00300000U)
#define RADIO_RX_MODE_CTRL__EN_OSDACQ_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x00300000U)))
#define RADIO_RX_MODE_CTRL__EN_OSDACQ_OVR__RESET_VALUE              0x00000000U
/** @} */

/* macros for field adci_en_ovr */
/**
 * @defgroup radio_rx_regs_core_adci_en_ovr_field adci_en_ovr_field
 * @brief macros for field adci_en_ovr
 * @details ADC I-channel enable override
 * @{
 */
#define RADIO_RX_MODE_CTRL__ADCI_EN_OVR__SHIFT                               22
#define RADIO_RX_MODE_CTRL__ADCI_EN_OVR__WIDTH                                2
#define RADIO_RX_MODE_CTRL__ADCI_EN_OVR__MASK                       0x00c00000U
#define RADIO_RX_MODE_CTRL__ADCI_EN_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00c00000U) >> 22)
#define RADIO_RX_MODE_CTRL__ADCI_EN_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 22) & 0x00c00000U)
#define RADIO_RX_MODE_CTRL__ADCI_EN_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00c00000U) | (((uint32_t)(src) <<\
                    22) & 0x00c00000U)
#define RADIO_RX_MODE_CTRL__ADCI_EN_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 22) & ~0x00c00000U)))
#define RADIO_RX_MODE_CTRL__ADCI_EN_OVR__RESET_VALUE                0x00000000U
/** @} */

/* macros for field adcq_en_ovr */
/**
 * @defgroup radio_rx_regs_core_adcq_en_ovr_field adcq_en_ovr_field
 * @brief macros for field adcq_en_ovr
 * @details ADC Q-channel enable override
 * @{
 */
#define RADIO_RX_MODE_CTRL__ADCQ_EN_OVR__SHIFT                               24
#define RADIO_RX_MODE_CTRL__ADCQ_EN_OVR__WIDTH                                2
#define RADIO_RX_MODE_CTRL__ADCQ_EN_OVR__MASK                       0x03000000U
#define RADIO_RX_MODE_CTRL__ADCQ_EN_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x03000000U) >> 24)
#define RADIO_RX_MODE_CTRL__ADCQ_EN_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x03000000U)
#define RADIO_RX_MODE_CTRL__ADCQ_EN_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x03000000U) | (((uint32_t)(src) <<\
                    24) & 0x03000000U)
#define RADIO_RX_MODE_CTRL__ADCQ_EN_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x03000000U)))
#define RADIO_RX_MODE_CTRL__ADCQ_EN_OVR__RESET_VALUE                0x00000000U
/** @} */

/* macros for field adcref_en_ovr */
/**
 * @defgroup radio_rx_regs_core_adcref_en_ovr_field adcref_en_ovr_field
 * @brief macros for field adcref_en_ovr
 * @details ADC reference enable override
 * @{
 */
#define RADIO_RX_MODE_CTRL__ADCREF_EN_OVR__SHIFT                             26
#define RADIO_RX_MODE_CTRL__ADCREF_EN_OVR__WIDTH                              2
#define RADIO_RX_MODE_CTRL__ADCREF_EN_OVR__MASK                     0x0c000000U
#define RADIO_RX_MODE_CTRL__ADCREF_EN_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0c000000U) >> 26)
#define RADIO_RX_MODE_CTRL__ADCREF_EN_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 26) & 0x0c000000U)
#define RADIO_RX_MODE_CTRL__ADCREF_EN_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0c000000U) | (((uint32_t)(src) <<\
                    26) & 0x0c000000U)
#define RADIO_RX_MODE_CTRL__ADCREF_EN_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 26) & ~0x0c000000U)))
#define RADIO_RX_MODE_CTRL__ADCREF_EN_OVR__RESET_VALUE              0x00000000U
/** @} */

/* macros for field adc_rstb_ovr */
/**
 * @defgroup radio_rx_regs_core_adc_rstb_ovr_field adc_rstb_ovr_field
 * @brief macros for field adc_rstb_ovr
 * @details ADC reset_b override
 * @{
 */
#define RADIO_RX_MODE_CTRL__ADC_RSTB_OVR__SHIFT                              28
#define RADIO_RX_MODE_CTRL__ADC_RSTB_OVR__WIDTH                               2
#define RADIO_RX_MODE_CTRL__ADC_RSTB_OVR__MASK                      0x30000000U
#define RADIO_RX_MODE_CTRL__ADC_RSTB_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x30000000U) >> 28)
#define RADIO_RX_MODE_CTRL__ADC_RSTB_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 28) & 0x30000000U)
#define RADIO_RX_MODE_CTRL__ADC_RSTB_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x30000000U) | (((uint32_t)(src) <<\
                    28) & 0x30000000U)
#define RADIO_RX_MODE_CTRL__ADC_RSTB_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 28) & ~0x30000000U)))
#define RADIO_RX_MODE_CTRL__ADC_RSTB_OVR__RESET_VALUE               0x00000000U
/** @} */

/* macros for field rxbias_en_ovr */
/**
 * @defgroup radio_rx_regs_core_rxbias_en_ovr_field rxbias_en_ovr_field
 * @brief macros for field rxbias_en_ovr
 * @details RX bias enable override
 * @{
 */
#define RADIO_RX_MODE_CTRL__RXBIAS_EN_OVR__SHIFT                             30
#define RADIO_RX_MODE_CTRL__RXBIAS_EN_OVR__WIDTH                              2
#define RADIO_RX_MODE_CTRL__RXBIAS_EN_OVR__MASK                     0xc0000000U
#define RADIO_RX_MODE_CTRL__RXBIAS_EN_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0xc0000000U) >> 30)
#define RADIO_RX_MODE_CTRL__RXBIAS_EN_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 30) & 0xc0000000U)
#define RADIO_RX_MODE_CTRL__RXBIAS_EN_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xc0000000U) | (((uint32_t)(src) <<\
                    30) & 0xc0000000U)
#define RADIO_RX_MODE_CTRL__RXBIAS_EN_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 30) & ~0xc0000000U)))
#define RADIO_RX_MODE_CTRL__RXBIAS_EN_OVR__RESET_VALUE              0x00000000U
/** @} */
#define RADIO_RX_MODE_CTRL__TYPE                                       uint32_t
#define RADIO_RX_MODE_CTRL__READ                                    0xffffffffU
#define RADIO_RX_MODE_CTRL__WRITE                                   0xffffffffU
#define RADIO_RX_MODE_CTRL__PRESERVED                               0x00000000U
#define RADIO_RX_MODE_CTRL__RESET_VALUE                             0x00000000U

#endif /* __RADIO_RX_MODE_CTRL_MACRO__ */

/** @} end of mode_ctrl */

/* macros for BlueprintGlobalNameSpace::radio_rx_mode_ctrl2 */
/**
 * @defgroup radio_rx_regs_core_mode_ctrl2 mode_ctrl2
 * @brief Enable and mode overrides definitions.
 * @{
 */
#ifndef __RADIO_RX_MODE_CTRL2_MACRO__
#define __RADIO_RX_MODE_CTRL2_MACRO__

/* macros for field mode1M_ovr */
/**
 * @defgroup radio_rx_regs_core_mode1M_ovr_field mode1M_ovr_field
 * @brief macros for field mode1M_ovr
 * @details mode 1M override
 * @{
 */
#define RADIO_RX_MODE_CTRL2__MODE1M_OVR__SHIFT                                0
#define RADIO_RX_MODE_CTRL2__MODE1M_OVR__WIDTH                                2
#define RADIO_RX_MODE_CTRL2__MODE1M_OVR__MASK                       0x00000003U
#define RADIO_RX_MODE_CTRL2__MODE1M_OVR__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000003U)
#define RADIO_RX_MODE_CTRL2__MODE1M_OVR__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000003U)
#define RADIO_RX_MODE_CTRL2__MODE1M_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000003U) | ((uint32_t)(src) &\
                    0x00000003U)
#define RADIO_RX_MODE_CTRL2__MODE1M_OVR__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000003U)))
#define RADIO_RX_MODE_CTRL2__MODE1M_OVR__RESET_VALUE                0x00000000U
/** @} */

/* macros for field swapIQ */
/**
 * @defgroup radio_rx_regs_core_swapIQ_field swapIQ_field
 * @brief macros for field swapIQ
 * @details mixer control bit to swap I and Q
 * @{
 */
#define RADIO_RX_MODE_CTRL2__SWAPIQ__SHIFT                                    2
#define RADIO_RX_MODE_CTRL2__SWAPIQ__WIDTH                                    1
#define RADIO_RX_MODE_CTRL2__SWAPIQ__MASK                           0x00000004U
#define RADIO_RX_MODE_CTRL2__SWAPIQ__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define RADIO_RX_MODE_CTRL2__SWAPIQ__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define RADIO_RX_MODE_CTRL2__SWAPIQ__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define RADIO_RX_MODE_CTRL2__SWAPIQ__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define RADIO_RX_MODE_CTRL2__SWAPIQ__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define RADIO_RX_MODE_CTRL2__SWAPIQ__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define RADIO_RX_MODE_CTRL2__SWAPIQ__RESET_VALUE                    0x00000000U
/** @} */

/* macros for field combineIQ */
/**
 * @defgroup radio_rx_regs_core_combineIQ_field combineIQ_field
 * @brief macros for field combineIQ
 * @details mixer control bit to combineIQ
 * @{
 */
#define RADIO_RX_MODE_CTRL2__COMBINEIQ__SHIFT                                 3
#define RADIO_RX_MODE_CTRL2__COMBINEIQ__WIDTH                                 1
#define RADIO_RX_MODE_CTRL2__COMBINEIQ__MASK                        0x00000008U
#define RADIO_RX_MODE_CTRL2__COMBINEIQ__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000008U) >> 3)
#define RADIO_RX_MODE_CTRL2__COMBINEIQ__WRITE(src) \
                    (((uint32_t)(src)\
                    << 3) & 0x00000008U)
#define RADIO_RX_MODE_CTRL2__COMBINEIQ__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | (((uint32_t)(src) <<\
                    3) & 0x00000008U)
#define RADIO_RX_MODE_CTRL2__COMBINEIQ__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000008U)))
#define RADIO_RX_MODE_CTRL2__COMBINEIQ__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define RADIO_RX_MODE_CTRL2__COMBINEIQ__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)
#define RADIO_RX_MODE_CTRL2__COMBINEIQ__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field mixer_ensinglelp_ovr_val */
/**
 * @defgroup radio_rx_regs_core_mixer_ensinglelp_ovr_val_field mixer_ensinglelp_ovr_val_field
 * @brief macros for field mixer_ensinglelp_ovr_val
 * @details override value for ensinglelp
 * @{
 */
#define RADIO_RX_MODE_CTRL2__MIXER_ENSINGLELP_OVR_VAL__SHIFT                  4
#define RADIO_RX_MODE_CTRL2__MIXER_ENSINGLELP_OVR_VAL__WIDTH                  1
#define RADIO_RX_MODE_CTRL2__MIXER_ENSINGLELP_OVR_VAL__MASK         0x00000010U
#define RADIO_RX_MODE_CTRL2__MIXER_ENSINGLELP_OVR_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000010U) >> 4)
#define RADIO_RX_MODE_CTRL2__MIXER_ENSINGLELP_OVR_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x00000010U)
#define RADIO_RX_MODE_CTRL2__MIXER_ENSINGLELP_OVR_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | (((uint32_t)(src) <<\
                    4) & 0x00000010U)
#define RADIO_RX_MODE_CTRL2__MIXER_ENSINGLELP_OVR_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x00000010U)))
#define RADIO_RX_MODE_CTRL2__MIXER_ENSINGLELP_OVR_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(1) << 4)
#define RADIO_RX_MODE_CTRL2__MIXER_ENSINGLELP_OVR_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(0) << 4)
#define RADIO_RX_MODE_CTRL2__MIXER_ENSINGLELP_OVR_VAL__RESET_VALUE  0x00000000U
/** @} */

/* macros for field lna_offGain */
/**
 * @defgroup radio_rx_regs_core_lna_offGain_field lna_offGain_field
 * @brief macros for field lna_offGain
 * @details change the gain of lna
 * @{
 */
#define RADIO_RX_MODE_CTRL2__LNA_OFFGAIN__SHIFT                               5
#define RADIO_RX_MODE_CTRL2__LNA_OFFGAIN__WIDTH                               1
#define RADIO_RX_MODE_CTRL2__LNA_OFFGAIN__MASK                      0x00000020U
#define RADIO_RX_MODE_CTRL2__LNA_OFFGAIN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000020U) >> 5)
#define RADIO_RX_MODE_CTRL2__LNA_OFFGAIN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 5) & 0x00000020U)
#define RADIO_RX_MODE_CTRL2__LNA_OFFGAIN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | (((uint32_t)(src) <<\
                    5) & 0x00000020U)
#define RADIO_RX_MODE_CTRL2__LNA_OFFGAIN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 5) & ~0x00000020U)))
#define RADIO_RX_MODE_CTRL2__LNA_OFFGAIN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(1) << 5)
#define RADIO_RX_MODE_CTRL2__LNA_OFFGAIN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(0) << 5)
#define RADIO_RX_MODE_CTRL2__LNA_OFFGAIN__RESET_VALUE               0x00000000U
/** @} */
#define RADIO_RX_MODE_CTRL2__TYPE                                      uint32_t
#define RADIO_RX_MODE_CTRL2__READ                                   0x0000003fU
#define RADIO_RX_MODE_CTRL2__WRITE                                  0x0000003fU
#define RADIO_RX_MODE_CTRL2__PRESERVED                              0x00000000U
#define RADIO_RX_MODE_CTRL2__RESET_VALUE                            0x00000000U

#endif /* __RADIO_RX_MODE_CTRL2_MACRO__ */

/** @} end of mode_ctrl2 */

/* macros for BlueprintGlobalNameSpace::radio_rx_cal_cfg */
/**
 * @defgroup radio_rx_regs_core_cal_cfg cal_cfg
 * @brief Calibration configurations definitions.
 * @{
 */
#ifndef __RADIO_RX_CAL_CFG_MACRO__
#define __RADIO_RX_CAL_CFG_MACRO__

/* macros for field caldc_lna_en */
/**
 * @defgroup radio_rx_regs_core_caldc_lna_en_field caldc_lna_en_field
 * @brief macros for field caldc_lna_en
 * @details LNA enable during DC offset calibration
 * @{
 */
#define RADIO_RX_CAL_CFG__CALDC_LNA_EN__SHIFT                                 0
#define RADIO_RX_CAL_CFG__CALDC_LNA_EN__WIDTH                                 1
#define RADIO_RX_CAL_CFG__CALDC_LNA_EN__MASK                        0x00000001U
#define RADIO_RX_CAL_CFG__CALDC_LNA_EN__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define RADIO_RX_CAL_CFG__CALDC_LNA_EN__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define RADIO_RX_CAL_CFG__CALDC_LNA_EN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define RADIO_RX_CAL_CFG__CALDC_LNA_EN__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define RADIO_RX_CAL_CFG__CALDC_LNA_EN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define RADIO_RX_CAL_CFG__CALDC_LNA_EN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define RADIO_RX_CAL_CFG__CALDC_LNA_EN__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field caldc_mix_en */
/**
 * @defgroup radio_rx_regs_core_caldc_mix_en_field caldc_mix_en_field
 * @brief macros for field caldc_mix_en
 * @details Mixer enable during DC offset calibration
 * @{
 */
#define RADIO_RX_CAL_CFG__CALDC_MIX_EN__SHIFT                                 1
#define RADIO_RX_CAL_CFG__CALDC_MIX_EN__WIDTH                                 1
#define RADIO_RX_CAL_CFG__CALDC_MIX_EN__MASK                        0x00000002U
#define RADIO_RX_CAL_CFG__CALDC_MIX_EN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define RADIO_RX_CAL_CFG__CALDC_MIX_EN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define RADIO_RX_CAL_CFG__CALDC_MIX_EN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define RADIO_RX_CAL_CFG__CALDC_MIX_EN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define RADIO_RX_CAL_CFG__CALDC_MIX_EN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define RADIO_RX_CAL_CFG__CALDC_MIX_EN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define RADIO_RX_CAL_CFG__CALDC_MIX_EN__RESET_VALUE                 0x00000001U
/** @} */

/* macros for field caldc_tia_en */
/**
 * @defgroup radio_rx_regs_core_caldc_tia_en_field caldc_tia_en_field
 * @brief macros for field caldc_tia_en
 * @details TIA enable during DC offset calibration
 * @{
 */
#define RADIO_RX_CAL_CFG__CALDC_TIA_EN__SHIFT                                 2
#define RADIO_RX_CAL_CFG__CALDC_TIA_EN__WIDTH                                 1
#define RADIO_RX_CAL_CFG__CALDC_TIA_EN__MASK                        0x00000004U
#define RADIO_RX_CAL_CFG__CALDC_TIA_EN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define RADIO_RX_CAL_CFG__CALDC_TIA_EN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define RADIO_RX_CAL_CFG__CALDC_TIA_EN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define RADIO_RX_CAL_CFG__CALDC_TIA_EN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define RADIO_RX_CAL_CFG__CALDC_TIA_EN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define RADIO_RX_CAL_CFG__CALDC_TIA_EN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define RADIO_RX_CAL_CFG__CALDC_TIA_EN__RESET_VALUE                 0x00000001U
/** @} */

/* macros for field caldc_tia_open_rcc */
/**
 * @defgroup radio_rx_regs_core_caldc_tia_open_rcc_field caldc_tia_open_rcc_field
 * @brief macros for field caldc_tia_open_rcc
 * @details Disconnect cross-coupling resistors around TIA during DC offset calibration
 * @{
 */
#define RADIO_RX_CAL_CFG__CALDC_TIA_OPEN_RCC__SHIFT                           3
#define RADIO_RX_CAL_CFG__CALDC_TIA_OPEN_RCC__WIDTH                           1
#define RADIO_RX_CAL_CFG__CALDC_TIA_OPEN_RCC__MASK                  0x00000008U
#define RADIO_RX_CAL_CFG__CALDC_TIA_OPEN_RCC__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000008U) >> 3)
#define RADIO_RX_CAL_CFG__CALDC_TIA_OPEN_RCC__WRITE(src) \
                    (((uint32_t)(src)\
                    << 3) & 0x00000008U)
#define RADIO_RX_CAL_CFG__CALDC_TIA_OPEN_RCC__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | (((uint32_t)(src) <<\
                    3) & 0x00000008U)
#define RADIO_RX_CAL_CFG__CALDC_TIA_OPEN_RCC__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000008U)))
#define RADIO_RX_CAL_CFG__CALDC_TIA_OPEN_RCC__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define RADIO_RX_CAL_CFG__CALDC_TIA_OPEN_RCC__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)
#define RADIO_RX_CAL_CFG__CALDC_TIA_OPEN_RCC__RESET_VALUE           0x00000000U
/** @} */

/* macros for field caldc_tia_open_rfb */
/**
 * @defgroup radio_rx_regs_core_caldc_tia_open_rfb_field caldc_tia_open_rfb_field
 * @brief macros for field caldc_tia_open_rfb
 * @details Disconnect feedback resistor around TIA during DC offset calibration
 * @{
 */
#define RADIO_RX_CAL_CFG__CALDC_TIA_OPEN_RFB__SHIFT                           4
#define RADIO_RX_CAL_CFG__CALDC_TIA_OPEN_RFB__WIDTH                           1
#define RADIO_RX_CAL_CFG__CALDC_TIA_OPEN_RFB__MASK                  0x00000010U
#define RADIO_RX_CAL_CFG__CALDC_TIA_OPEN_RFB__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000010U) >> 4)
#define RADIO_RX_CAL_CFG__CALDC_TIA_OPEN_RFB__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x00000010U)
#define RADIO_RX_CAL_CFG__CALDC_TIA_OPEN_RFB__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | (((uint32_t)(src) <<\
                    4) & 0x00000010U)
#define RADIO_RX_CAL_CFG__CALDC_TIA_OPEN_RFB__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x00000010U)))
#define RADIO_RX_CAL_CFG__CALDC_TIA_OPEN_RFB__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(1) << 4)
#define RADIO_RX_CAL_CFG__CALDC_TIA_OPEN_RFB__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(0) << 4)
#define RADIO_RX_CAL_CFG__CALDC_TIA_OPEN_RFB__RESET_VALUE           0x00000000U
/** @} */

/* macros for field caldc_pga_en */
/**
 * @defgroup radio_rx_regs_core_caldc_pga_en_field caldc_pga_en_field
 * @brief macros for field caldc_pga_en
 * @details PGA enable during DC offset calibration
 * @{
 */
#define RADIO_RX_CAL_CFG__CALDC_PGA_EN__SHIFT                                 5
#define RADIO_RX_CAL_CFG__CALDC_PGA_EN__WIDTH                                 1
#define RADIO_RX_CAL_CFG__CALDC_PGA_EN__MASK                        0x00000020U
#define RADIO_RX_CAL_CFG__CALDC_PGA_EN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000020U) >> 5)
#define RADIO_RX_CAL_CFG__CALDC_PGA_EN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 5) & 0x00000020U)
#define RADIO_RX_CAL_CFG__CALDC_PGA_EN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | (((uint32_t)(src) <<\
                    5) & 0x00000020U)
#define RADIO_RX_CAL_CFG__CALDC_PGA_EN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 5) & ~0x00000020U)))
#define RADIO_RX_CAL_CFG__CALDC_PGA_EN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(1) << 5)
#define RADIO_RX_CAL_CFG__CALDC_PGA_EN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(0) << 5)
#define RADIO_RX_CAL_CFG__CALDC_PGA_EN__RESET_VALUE                 0x00000001U
/** @} */

/* macros for field caldc_pga_open_rcc */
/**
 * @defgroup radio_rx_regs_core_caldc_pga_open_rcc_field caldc_pga_open_rcc_field
 * @brief macros for field caldc_pga_open_rcc
 * @details Disconnect cross-coupling resistors around PGA during DC offset calibration
 * @{
 */
#define RADIO_RX_CAL_CFG__CALDC_PGA_OPEN_RCC__SHIFT                           6
#define RADIO_RX_CAL_CFG__CALDC_PGA_OPEN_RCC__WIDTH                           1
#define RADIO_RX_CAL_CFG__CALDC_PGA_OPEN_RCC__MASK                  0x00000040U
#define RADIO_RX_CAL_CFG__CALDC_PGA_OPEN_RCC__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000040U) >> 6)
#define RADIO_RX_CAL_CFG__CALDC_PGA_OPEN_RCC__WRITE(src) \
                    (((uint32_t)(src)\
                    << 6) & 0x00000040U)
#define RADIO_RX_CAL_CFG__CALDC_PGA_OPEN_RCC__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | (((uint32_t)(src) <<\
                    6) & 0x00000040U)
#define RADIO_RX_CAL_CFG__CALDC_PGA_OPEN_RCC__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 6) & ~0x00000040U)))
#define RADIO_RX_CAL_CFG__CALDC_PGA_OPEN_RCC__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(1) << 6)
#define RADIO_RX_CAL_CFG__CALDC_PGA_OPEN_RCC__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(0) << 6)
#define RADIO_RX_CAL_CFG__CALDC_PGA_OPEN_RCC__RESET_VALUE           0x00000000U
/** @} */

/* macros for field caldc_pga_open_rfb */
/**
 * @defgroup radio_rx_regs_core_caldc_pga_open_rfb_field caldc_pga_open_rfb_field
 * @brief macros for field caldc_pga_open_rfb
 * @details Disconnect feedback resistor around PGA during DC offset calibration
 * @{
 */
#define RADIO_RX_CAL_CFG__CALDC_PGA_OPEN_RFB__SHIFT                           7
#define RADIO_RX_CAL_CFG__CALDC_PGA_OPEN_RFB__WIDTH                           1
#define RADIO_RX_CAL_CFG__CALDC_PGA_OPEN_RFB__MASK                  0x00000080U
#define RADIO_RX_CAL_CFG__CALDC_PGA_OPEN_RFB__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000080U) >> 7)
#define RADIO_RX_CAL_CFG__CALDC_PGA_OPEN_RFB__WRITE(src) \
                    (((uint32_t)(src)\
                    << 7) & 0x00000080U)
#define RADIO_RX_CAL_CFG__CALDC_PGA_OPEN_RFB__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | (((uint32_t)(src) <<\
                    7) & 0x00000080U)
#define RADIO_RX_CAL_CFG__CALDC_PGA_OPEN_RFB__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 7) & ~0x00000080U)))
#define RADIO_RX_CAL_CFG__CALDC_PGA_OPEN_RFB__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | ((uint32_t)(1) << 7)
#define RADIO_RX_CAL_CFG__CALDC_PGA_OPEN_RFB__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | ((uint32_t)(0) << 7)
#define RADIO_RX_CAL_CFG__CALDC_PGA_OPEN_RFB__RESET_VALUE           0x00000000U
/** @} */

/* macros for field caldc_adc_en */
/**
 * @defgroup radio_rx_regs_core_caldc_adc_en_field caldc_adc_en_field
 * @brief macros for field caldc_adc_en
 * @details ADC enable during DC offset calibration
 * @{
 */
#define RADIO_RX_CAL_CFG__CALDC_ADC_EN__SHIFT                                 8
#define RADIO_RX_CAL_CFG__CALDC_ADC_EN__WIDTH                                 1
#define RADIO_RX_CAL_CFG__CALDC_ADC_EN__MASK                        0x00000100U
#define RADIO_RX_CAL_CFG__CALDC_ADC_EN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000100U) >> 8)
#define RADIO_RX_CAL_CFG__CALDC_ADC_EN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00000100U)
#define RADIO_RX_CAL_CFG__CALDC_ADC_EN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | (((uint32_t)(src) <<\
                    8) & 0x00000100U)
#define RADIO_RX_CAL_CFG__CALDC_ADC_EN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00000100U)))
#define RADIO_RX_CAL_CFG__CALDC_ADC_EN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | ((uint32_t)(1) << 8)
#define RADIO_RX_CAL_CFG__CALDC_ADC_EN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | ((uint32_t)(0) << 8)
#define RADIO_RX_CAL_CFG__CALDC_ADC_EN__RESET_VALUE                 0x00000001U
/** @} */

/* macros for field pga_dcos_cal_ovr */
/**
 * @defgroup radio_rx_regs_core_pga_dcos_cal_ovr_field pga_dcos_cal_ovr_field
 * @brief macros for field pga_dcos_cal_ovr
 * @details Override to connect pga n and p inputs to each other
 * @{
 */
#define RADIO_RX_CAL_CFG__PGA_DCOS_CAL_OVR__SHIFT                             9
#define RADIO_RX_CAL_CFG__PGA_DCOS_CAL_OVR__WIDTH                             2
#define RADIO_RX_CAL_CFG__PGA_DCOS_CAL_OVR__MASK                    0x00000600U
#define RADIO_RX_CAL_CFG__PGA_DCOS_CAL_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000600U) >> 9)
#define RADIO_RX_CAL_CFG__PGA_DCOS_CAL_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x00000600U)
#define RADIO_RX_CAL_CFG__PGA_DCOS_CAL_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000600U) | (((uint32_t)(src) <<\
                    9) & 0x00000600U)
#define RADIO_RX_CAL_CFG__PGA_DCOS_CAL_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x00000600U)))
#define RADIO_RX_CAL_CFG__PGA_DCOS_CAL_OVR__RESET_VALUE             0x00000000U
/** @} */

/* macros for field calfc_lna_en */
/**
 * @defgroup radio_rx_regs_core_calfc_lna_en_field calfc_lna_en_field
 * @brief macros for field calfc_lna_en
 * @details LNA enable during RXBB filter calibration
 * @{
 */
#define RADIO_RX_CAL_CFG__CALFC_LNA_EN__SHIFT                                11
#define RADIO_RX_CAL_CFG__CALFC_LNA_EN__WIDTH                                 1
#define RADIO_RX_CAL_CFG__CALFC_LNA_EN__MASK                        0x00000800U
#define RADIO_RX_CAL_CFG__CALFC_LNA_EN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000800U) >> 11)
#define RADIO_RX_CAL_CFG__CALFC_LNA_EN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 11) & 0x00000800U)
#define RADIO_RX_CAL_CFG__CALFC_LNA_EN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | (((uint32_t)(src) <<\
                    11) & 0x00000800U)
#define RADIO_RX_CAL_CFG__CALFC_LNA_EN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 11) & ~0x00000800U)))
#define RADIO_RX_CAL_CFG__CALFC_LNA_EN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | ((uint32_t)(1) << 11)
#define RADIO_RX_CAL_CFG__CALFC_LNA_EN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | ((uint32_t)(0) << 11)
#define RADIO_RX_CAL_CFG__CALFC_LNA_EN__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field calfc_mix_en */
/**
 * @defgroup radio_rx_regs_core_calfc_mix_en_field calfc_mix_en_field
 * @brief macros for field calfc_mix_en
 * @details Mixer enable during RXBB filter calibration
 * @{
 */
#define RADIO_RX_CAL_CFG__CALFC_MIX_EN__SHIFT                                12
#define RADIO_RX_CAL_CFG__CALFC_MIX_EN__WIDTH                                 1
#define RADIO_RX_CAL_CFG__CALFC_MIX_EN__MASK                        0x00001000U
#define RADIO_RX_CAL_CFG__CALFC_MIX_EN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00001000U) >> 12)
#define RADIO_RX_CAL_CFG__CALFC_MIX_EN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x00001000U)
#define RADIO_RX_CAL_CFG__CALFC_MIX_EN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | (((uint32_t)(src) <<\
                    12) & 0x00001000U)
#define RADIO_RX_CAL_CFG__CALFC_MIX_EN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x00001000U)))
#define RADIO_RX_CAL_CFG__CALFC_MIX_EN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | ((uint32_t)(1) << 12)
#define RADIO_RX_CAL_CFG__CALFC_MIX_EN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | ((uint32_t)(0) << 12)
#define RADIO_RX_CAL_CFG__CALFC_MIX_EN__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field calfc_tia_open_rcc */
/**
 * @defgroup radio_rx_regs_core_calfc_tia_open_rcc_field calfc_tia_open_rcc_field
 * @brief macros for field calfc_tia_open_rcc
 * @details Disconnect cross-coupling resistors around TIA during RXBB filter calibration
 * @{
 */
#define RADIO_RX_CAL_CFG__CALFC_TIA_OPEN_RCC__SHIFT                          13
#define RADIO_RX_CAL_CFG__CALFC_TIA_OPEN_RCC__WIDTH                           1
#define RADIO_RX_CAL_CFG__CALFC_TIA_OPEN_RCC__MASK                  0x00002000U
#define RADIO_RX_CAL_CFG__CALFC_TIA_OPEN_RCC__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00002000U) >> 13)
#define RADIO_RX_CAL_CFG__CALFC_TIA_OPEN_RCC__WRITE(src) \
                    (((uint32_t)(src)\
                    << 13) & 0x00002000U)
#define RADIO_RX_CAL_CFG__CALFC_TIA_OPEN_RCC__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | (((uint32_t)(src) <<\
                    13) & 0x00002000U)
#define RADIO_RX_CAL_CFG__CALFC_TIA_OPEN_RCC__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 13) & ~0x00002000U)))
#define RADIO_RX_CAL_CFG__CALFC_TIA_OPEN_RCC__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | ((uint32_t)(1) << 13)
#define RADIO_RX_CAL_CFG__CALFC_TIA_OPEN_RCC__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | ((uint32_t)(0) << 13)
#define RADIO_RX_CAL_CFG__CALFC_TIA_OPEN_RCC__RESET_VALUE           0x00000001U
/** @} */

/* macros for field calfc_tia_open_rfb */
/**
 * @defgroup radio_rx_regs_core_calfc_tia_open_rfb_field calfc_tia_open_rfb_field
 * @brief macros for field calfc_tia_open_rfb
 * @details Disconnect feedback resistors around TIA during RXBB filter calibration
 * @{
 */
#define RADIO_RX_CAL_CFG__CALFC_TIA_OPEN_RFB__SHIFT                          14
#define RADIO_RX_CAL_CFG__CALFC_TIA_OPEN_RFB__WIDTH                           1
#define RADIO_RX_CAL_CFG__CALFC_TIA_OPEN_RFB__MASK                  0x00004000U
#define RADIO_RX_CAL_CFG__CALFC_TIA_OPEN_RFB__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00004000U) >> 14)
#define RADIO_RX_CAL_CFG__CALFC_TIA_OPEN_RFB__WRITE(src) \
                    (((uint32_t)(src)\
                    << 14) & 0x00004000U)
#define RADIO_RX_CAL_CFG__CALFC_TIA_OPEN_RFB__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | (((uint32_t)(src) <<\
                    14) & 0x00004000U)
#define RADIO_RX_CAL_CFG__CALFC_TIA_OPEN_RFB__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 14) & ~0x00004000U)))
#define RADIO_RX_CAL_CFG__CALFC_TIA_OPEN_RFB__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | ((uint32_t)(1) << 14)
#define RADIO_RX_CAL_CFG__CALFC_TIA_OPEN_RFB__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | ((uint32_t)(0) << 14)
#define RADIO_RX_CAL_CFG__CALFC_TIA_OPEN_RFB__RESET_VALUE           0x00000001U
/** @} */

/* macros for field calfc_pga_open_rcc */
/**
 * @defgroup radio_rx_regs_core_calfc_pga_open_rcc_field calfc_pga_open_rcc_field
 * @brief macros for field calfc_pga_open_rcc
 * @details Disconnect cross-coupling resistors around PGA during RXBB filter calibration
 * @{
 */
#define RADIO_RX_CAL_CFG__CALFC_PGA_OPEN_RCC__SHIFT                          15
#define RADIO_RX_CAL_CFG__CALFC_PGA_OPEN_RCC__WIDTH                           1
#define RADIO_RX_CAL_CFG__CALFC_PGA_OPEN_RCC__MASK                  0x00008000U
#define RADIO_RX_CAL_CFG__CALFC_PGA_OPEN_RCC__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00008000U) >> 15)
#define RADIO_RX_CAL_CFG__CALFC_PGA_OPEN_RCC__WRITE(src) \
                    (((uint32_t)(src)\
                    << 15) & 0x00008000U)
#define RADIO_RX_CAL_CFG__CALFC_PGA_OPEN_RCC__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00008000U) | (((uint32_t)(src) <<\
                    15) & 0x00008000U)
#define RADIO_RX_CAL_CFG__CALFC_PGA_OPEN_RCC__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 15) & ~0x00008000U)))
#define RADIO_RX_CAL_CFG__CALFC_PGA_OPEN_RCC__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00008000U) | ((uint32_t)(1) << 15)
#define RADIO_RX_CAL_CFG__CALFC_PGA_OPEN_RCC__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00008000U) | ((uint32_t)(0) << 15)
#define RADIO_RX_CAL_CFG__CALFC_PGA_OPEN_RCC__RESET_VALUE           0x00000001U
/** @} */

/* macros for field calfc_pga_open_rfb */
/**
 * @defgroup radio_rx_regs_core_calfc_pga_open_rfb_field calfc_pga_open_rfb_field
 * @brief macros for field calfc_pga_open_rfb
 * @details Disconnect feedback resistors around PGA during RXBB filter calibration
 * @{
 */
#define RADIO_RX_CAL_CFG__CALFC_PGA_OPEN_RFB__SHIFT                          16
#define RADIO_RX_CAL_CFG__CALFC_PGA_OPEN_RFB__WIDTH                           1
#define RADIO_RX_CAL_CFG__CALFC_PGA_OPEN_RFB__MASK                  0x00010000U
#define RADIO_RX_CAL_CFG__CALFC_PGA_OPEN_RFB__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00010000U) >> 16)
#define RADIO_RX_CAL_CFG__CALFC_PGA_OPEN_RFB__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x00010000U)
#define RADIO_RX_CAL_CFG__CALFC_PGA_OPEN_RFB__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | (((uint32_t)(src) <<\
                    16) & 0x00010000U)
#define RADIO_RX_CAL_CFG__CALFC_PGA_OPEN_RFB__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x00010000U)))
#define RADIO_RX_CAL_CFG__CALFC_PGA_OPEN_RFB__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | ((uint32_t)(1) << 16)
#define RADIO_RX_CAL_CFG__CALFC_PGA_OPEN_RFB__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | ((uint32_t)(0) << 16)
#define RADIO_RX_CAL_CFG__CALFC_PGA_OPEN_RFB__RESET_VALUE           0x00000001U
/** @} */

/* macros for field calfc_pga_connectrcc2rfb */
/**
 * @defgroup radio_rx_regs_core_calfc_pga_connectrcc2rfb_field calfc_pga_connectrcc2rfb_field
 * @brief macros for field calfc_pga_connectrcc2rfb
 * @details PGA connect rcc to rfb during RXBB filter calibration
 * @{
 */
#define RADIO_RX_CAL_CFG__CALFC_PGA_CONNECTRCC2RFB__SHIFT                    17
#define RADIO_RX_CAL_CFG__CALFC_PGA_CONNECTRCC2RFB__WIDTH                     1
#define RADIO_RX_CAL_CFG__CALFC_PGA_CONNECTRCC2RFB__MASK            0x00020000U
#define RADIO_RX_CAL_CFG__CALFC_PGA_CONNECTRCC2RFB__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00020000U) >> 17)
#define RADIO_RX_CAL_CFG__CALFC_PGA_CONNECTRCC2RFB__WRITE(src) \
                    (((uint32_t)(src)\
                    << 17) & 0x00020000U)
#define RADIO_RX_CAL_CFG__CALFC_PGA_CONNECTRCC2RFB__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | (((uint32_t)(src) <<\
                    17) & 0x00020000U)
#define RADIO_RX_CAL_CFG__CALFC_PGA_CONNECTRCC2RFB__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 17) & ~0x00020000U)))
#define RADIO_RX_CAL_CFG__CALFC_PGA_CONNECTRCC2RFB__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(1) << 17)
#define RADIO_RX_CAL_CFG__CALFC_PGA_CONNECTRCC2RFB__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(0) << 17)
#define RADIO_RX_CAL_CFG__CALFC_PGA_CONNECTRCC2RFB__RESET_VALUE     0x00000000U
/** @} */

/* macros for field calfc_pga_op_cal */
/**
 * @defgroup radio_rx_regs_core_calfc_pga_op_cal_field calfc_pga_op_cal_field
 * @brief macros for field calfc_pga_op_cal
 * @details enable pga opamp calibration
 * @{
 */
#define RADIO_RX_CAL_CFG__CALFC_PGA_OP_CAL__SHIFT                            18
#define RADIO_RX_CAL_CFG__CALFC_PGA_OP_CAL__WIDTH                             1
#define RADIO_RX_CAL_CFG__CALFC_PGA_OP_CAL__MASK                    0x00040000U
#define RADIO_RX_CAL_CFG__CALFC_PGA_OP_CAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00040000U) >> 18)
#define RADIO_RX_CAL_CFG__CALFC_PGA_OP_CAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0x00040000U)
#define RADIO_RX_CAL_CFG__CALFC_PGA_OP_CAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | (((uint32_t)(src) <<\
                    18) & 0x00040000U)
#define RADIO_RX_CAL_CFG__CALFC_PGA_OP_CAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x00040000U)))
#define RADIO_RX_CAL_CFG__CALFC_PGA_OP_CAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(1) << 18)
#define RADIO_RX_CAL_CFG__CALFC_PGA_OP_CAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(0) << 18)
#define RADIO_RX_CAL_CFG__CALFC_PGA_OP_CAL__RESET_VALUE             0x00000000U
/** @} */

/* macros for field calfc_init_osc */
/**
 * @defgroup radio_rx_regs_core_calfc_init_osc_field calfc_init_osc_field
 * @brief macros for field calfc_init_osc
 * @details initialize loop nodes for osc during RXBB calibration
 * @{
 */
#define RADIO_RX_CAL_CFG__CALFC_INIT_OSC__SHIFT                              19
#define RADIO_RX_CAL_CFG__CALFC_INIT_OSC__WIDTH                               1
#define RADIO_RX_CAL_CFG__CALFC_INIT_OSC__MASK                      0x00080000U
#define RADIO_RX_CAL_CFG__CALFC_INIT_OSC__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00080000U) >> 19)
#define RADIO_RX_CAL_CFG__CALFC_INIT_OSC__WRITE(src) \
                    (((uint32_t)(src)\
                    << 19) & 0x00080000U)
#define RADIO_RX_CAL_CFG__CALFC_INIT_OSC__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | (((uint32_t)(src) <<\
                    19) & 0x00080000U)
#define RADIO_RX_CAL_CFG__CALFC_INIT_OSC__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 19) & ~0x00080000U)))
#define RADIO_RX_CAL_CFG__CALFC_INIT_OSC__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | ((uint32_t)(1) << 19)
#define RADIO_RX_CAL_CFG__CALFC_INIT_OSC__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | ((uint32_t)(0) << 19)
#define RADIO_RX_CAL_CFG__CALFC_INIT_OSC__RESET_VALUE               0x00000000U
/** @} */

/* macros for field calfc_start_osc */
/**
 * @defgroup radio_rx_regs_core_calfc_start_osc_field calfc_start_osc_field
 * @brief macros for field calfc_start_osc
 * @details start osc during RXBB calibration
 * @{
 */
#define RADIO_RX_CAL_CFG__CALFC_START_OSC__SHIFT                             20
#define RADIO_RX_CAL_CFG__CALFC_START_OSC__WIDTH                              1
#define RADIO_RX_CAL_CFG__CALFC_START_OSC__MASK                     0x00100000U
#define RADIO_RX_CAL_CFG__CALFC_START_OSC__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00100000U) >> 20)
#define RADIO_RX_CAL_CFG__CALFC_START_OSC__WRITE(src) \
                    (((uint32_t)(src)\
                    << 20) & 0x00100000U)
#define RADIO_RX_CAL_CFG__CALFC_START_OSC__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00100000U) | (((uint32_t)(src) <<\
                    20) & 0x00100000U)
#define RADIO_RX_CAL_CFG__CALFC_START_OSC__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x00100000U)))
#define RADIO_RX_CAL_CFG__CALFC_START_OSC__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00100000U) | ((uint32_t)(1) << 20)
#define RADIO_RX_CAL_CFG__CALFC_START_OSC__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00100000U) | ((uint32_t)(0) << 20)
#define RADIO_RX_CAL_CFG__CALFC_START_OSC__RESET_VALUE              0x00000000U
/** @} */

/* macros for field calfc_adc_en */
/**
 * @defgroup radio_rx_regs_core_calfc_adc_en_field calfc_adc_en_field
 * @brief macros for field calfc_adc_en
 * @details ADC enable during RXBB filter calibration
 * @{
 */
#define RADIO_RX_CAL_CFG__CALFC_ADC_EN__SHIFT                                21
#define RADIO_RX_CAL_CFG__CALFC_ADC_EN__WIDTH                                 1
#define RADIO_RX_CAL_CFG__CALFC_ADC_EN__MASK                        0x00200000U
#define RADIO_RX_CAL_CFG__CALFC_ADC_EN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00200000U) >> 21)
#define RADIO_RX_CAL_CFG__CALFC_ADC_EN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 21) & 0x00200000U)
#define RADIO_RX_CAL_CFG__CALFC_ADC_EN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00200000U) | (((uint32_t)(src) <<\
                    21) & 0x00200000U)
#define RADIO_RX_CAL_CFG__CALFC_ADC_EN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 21) & ~0x00200000U)))
#define RADIO_RX_CAL_CFG__CALFC_ADC_EN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00200000U) | ((uint32_t)(1) << 21)
#define RADIO_RX_CAL_CFG__CALFC_ADC_EN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00200000U) | ((uint32_t)(0) << 21)
#define RADIO_RX_CAL_CFG__CALFC_ADC_EN__RESET_VALUE                 0x00000001U
/** @} */

/* macros for field calfc_notch_en */
/**
 * @defgroup radio_rx_regs_core_calfc_notch_en_field calfc_notch_en_field
 * @brief macros for field calfc_notch_en
 * @details enable notch calibration
 * @{
 */
#define RADIO_RX_CAL_CFG__CALFC_NOTCH_EN__SHIFT                              22
#define RADIO_RX_CAL_CFG__CALFC_NOTCH_EN__WIDTH                               1
#define RADIO_RX_CAL_CFG__CALFC_NOTCH_EN__MASK                      0x00400000U
#define RADIO_RX_CAL_CFG__CALFC_NOTCH_EN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00400000U) >> 22)
#define RADIO_RX_CAL_CFG__CALFC_NOTCH_EN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 22) & 0x00400000U)
#define RADIO_RX_CAL_CFG__CALFC_NOTCH_EN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00400000U) | (((uint32_t)(src) <<\
                    22) & 0x00400000U)
#define RADIO_RX_CAL_CFG__CALFC_NOTCH_EN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 22) & ~0x00400000U)))
#define RADIO_RX_CAL_CFG__CALFC_NOTCH_EN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00400000U) | ((uint32_t)(1) << 22)
#define RADIO_RX_CAL_CFG__CALFC_NOTCH_EN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00400000U) | ((uint32_t)(0) << 22)
#define RADIO_RX_CAL_CFG__CALFC_NOTCH_EN__RESET_VALUE               0x00000000U
/** @} */

/* macros for field calrx_lna_en */
/**
 * @defgroup radio_rx_regs_core_calrx_lna_en_field calrx_lna_en_field
 * @brief macros for field calrx_lna_en
 * @details LNA enable during RX loopback calibration (reserved)
 * @{
 */
#define RADIO_RX_CAL_CFG__CALRX_LNA_EN__SHIFT                                23
#define RADIO_RX_CAL_CFG__CALRX_LNA_EN__WIDTH                                 1
#define RADIO_RX_CAL_CFG__CALRX_LNA_EN__MASK                        0x00800000U
#define RADIO_RX_CAL_CFG__CALRX_LNA_EN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00800000U) >> 23)
#define RADIO_RX_CAL_CFG__CALRX_LNA_EN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 23) & 0x00800000U)
#define RADIO_RX_CAL_CFG__CALRX_LNA_EN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | (((uint32_t)(src) <<\
                    23) & 0x00800000U)
#define RADIO_RX_CAL_CFG__CALRX_LNA_EN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 23) & ~0x00800000U)))
#define RADIO_RX_CAL_CFG__CALRX_LNA_EN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(1) << 23)
#define RADIO_RX_CAL_CFG__CALRX_LNA_EN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(0) << 23)
#define RADIO_RX_CAL_CFG__CALRX_LNA_EN__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field calrx_mix_en */
/**
 * @defgroup radio_rx_regs_core_calrx_mix_en_field calrx_mix_en_field
 * @brief macros for field calrx_mix_en
 * @details Mixer enable during RX loopback calibration (reserved)
 * @{
 */
#define RADIO_RX_CAL_CFG__CALRX_MIX_EN__SHIFT                                24
#define RADIO_RX_CAL_CFG__CALRX_MIX_EN__WIDTH                                 1
#define RADIO_RX_CAL_CFG__CALRX_MIX_EN__MASK                        0x01000000U
#define RADIO_RX_CAL_CFG__CALRX_MIX_EN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01000000U) >> 24)
#define RADIO_RX_CAL_CFG__CALRX_MIX_EN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x01000000U)
#define RADIO_RX_CAL_CFG__CALRX_MIX_EN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | (((uint32_t)(src) <<\
                    24) & 0x01000000U)
#define RADIO_RX_CAL_CFG__CALRX_MIX_EN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x01000000U)))
#define RADIO_RX_CAL_CFG__CALRX_MIX_EN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(1) << 24)
#define RADIO_RX_CAL_CFG__CALRX_MIX_EN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(0) << 24)
#define RADIO_RX_CAL_CFG__CALRX_MIX_EN__RESET_VALUE                 0x00000001U
/** @} */

/* macros for field calrx_tia_en */
/**
 * @defgroup radio_rx_regs_core_calrx_tia_en_field calrx_tia_en_field
 * @brief macros for field calrx_tia_en
 * @details TIA enable during RX loopback calibration (reserved)
 * @{
 */
#define RADIO_RX_CAL_CFG__CALRX_TIA_EN__SHIFT                                25
#define RADIO_RX_CAL_CFG__CALRX_TIA_EN__WIDTH                                 1
#define RADIO_RX_CAL_CFG__CALRX_TIA_EN__MASK                        0x02000000U
#define RADIO_RX_CAL_CFG__CALRX_TIA_EN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x02000000U) >> 25)
#define RADIO_RX_CAL_CFG__CALRX_TIA_EN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 25) & 0x02000000U)
#define RADIO_RX_CAL_CFG__CALRX_TIA_EN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x02000000U) | (((uint32_t)(src) <<\
                    25) & 0x02000000U)
#define RADIO_RX_CAL_CFG__CALRX_TIA_EN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 25) & ~0x02000000U)))
#define RADIO_RX_CAL_CFG__CALRX_TIA_EN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x02000000U) | ((uint32_t)(1) << 25)
#define RADIO_RX_CAL_CFG__CALRX_TIA_EN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x02000000U) | ((uint32_t)(0) << 25)
#define RADIO_RX_CAL_CFG__CALRX_TIA_EN__RESET_VALUE                 0x00000001U
/** @} */

/* macros for field calrx_tia_open_rcc */
/**
 * @defgroup radio_rx_regs_core_calrx_tia_open_rcc_field calrx_tia_open_rcc_field
 * @brief macros for field calrx_tia_open_rcc
 * @details Disconnect cross-coupling resistors around TIA during RX loopback calibration (reserved)
 * @{
 */
#define RADIO_RX_CAL_CFG__CALRX_TIA_OPEN_RCC__SHIFT                          26
#define RADIO_RX_CAL_CFG__CALRX_TIA_OPEN_RCC__WIDTH                           1
#define RADIO_RX_CAL_CFG__CALRX_TIA_OPEN_RCC__MASK                  0x04000000U
#define RADIO_RX_CAL_CFG__CALRX_TIA_OPEN_RCC__READ(src) \
                    (((uint32_t)(src)\
                    & 0x04000000U) >> 26)
#define RADIO_RX_CAL_CFG__CALRX_TIA_OPEN_RCC__WRITE(src) \
                    (((uint32_t)(src)\
                    << 26) & 0x04000000U)
#define RADIO_RX_CAL_CFG__CALRX_TIA_OPEN_RCC__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x04000000U) | (((uint32_t)(src) <<\
                    26) & 0x04000000U)
#define RADIO_RX_CAL_CFG__CALRX_TIA_OPEN_RCC__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 26) & ~0x04000000U)))
#define RADIO_RX_CAL_CFG__CALRX_TIA_OPEN_RCC__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x04000000U) | ((uint32_t)(1) << 26)
#define RADIO_RX_CAL_CFG__CALRX_TIA_OPEN_RCC__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x04000000U) | ((uint32_t)(0) << 26)
#define RADIO_RX_CAL_CFG__CALRX_TIA_OPEN_RCC__RESET_VALUE           0x00000000U
/** @} */

/* macros for field calrx_tia_open_rfb */
/**
 * @defgroup radio_rx_regs_core_calrx_tia_open_rfb_field calrx_tia_open_rfb_field
 * @brief macros for field calrx_tia_open_rfb
 * @details Disconnect feedback resistors around TIA during RX loopback calibration (reserved)
 * @{
 */
#define RADIO_RX_CAL_CFG__CALRX_TIA_OPEN_RFB__SHIFT                          27
#define RADIO_RX_CAL_CFG__CALRX_TIA_OPEN_RFB__WIDTH                           1
#define RADIO_RX_CAL_CFG__CALRX_TIA_OPEN_RFB__MASK                  0x08000000U
#define RADIO_RX_CAL_CFG__CALRX_TIA_OPEN_RFB__READ(src) \
                    (((uint32_t)(src)\
                    & 0x08000000U) >> 27)
#define RADIO_RX_CAL_CFG__CALRX_TIA_OPEN_RFB__WRITE(src) \
                    (((uint32_t)(src)\
                    << 27) & 0x08000000U)
#define RADIO_RX_CAL_CFG__CALRX_TIA_OPEN_RFB__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x08000000U) | (((uint32_t)(src) <<\
                    27) & 0x08000000U)
#define RADIO_RX_CAL_CFG__CALRX_TIA_OPEN_RFB__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 27) & ~0x08000000U)))
#define RADIO_RX_CAL_CFG__CALRX_TIA_OPEN_RFB__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x08000000U) | ((uint32_t)(1) << 27)
#define RADIO_RX_CAL_CFG__CALRX_TIA_OPEN_RFB__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x08000000U) | ((uint32_t)(0) << 27)
#define RADIO_RX_CAL_CFG__CALRX_TIA_OPEN_RFB__RESET_VALUE           0x00000000U
/** @} */

/* macros for field calrx_pga_en */
/**
 * @defgroup radio_rx_regs_core_calrx_pga_en_field calrx_pga_en_field
 * @brief macros for field calrx_pga_en
 * @details PGA enable during RX loopback calibration (reserved)
 * @{
 */
#define RADIO_RX_CAL_CFG__CALRX_PGA_EN__SHIFT                                28
#define RADIO_RX_CAL_CFG__CALRX_PGA_EN__WIDTH                                 1
#define RADIO_RX_CAL_CFG__CALRX_PGA_EN__MASK                        0x10000000U
#define RADIO_RX_CAL_CFG__CALRX_PGA_EN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x10000000U) >> 28)
#define RADIO_RX_CAL_CFG__CALRX_PGA_EN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 28) & 0x10000000U)
#define RADIO_RX_CAL_CFG__CALRX_PGA_EN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x10000000U) | (((uint32_t)(src) <<\
                    28) & 0x10000000U)
#define RADIO_RX_CAL_CFG__CALRX_PGA_EN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 28) & ~0x10000000U)))
#define RADIO_RX_CAL_CFG__CALRX_PGA_EN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x10000000U) | ((uint32_t)(1) << 28)
#define RADIO_RX_CAL_CFG__CALRX_PGA_EN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x10000000U) | ((uint32_t)(0) << 28)
#define RADIO_RX_CAL_CFG__CALRX_PGA_EN__RESET_VALUE                 0x00000001U
/** @} */

/* macros for field calrx_pga_open_rcc */
/**
 * @defgroup radio_rx_regs_core_calrx_pga_open_rcc_field calrx_pga_open_rcc_field
 * @brief macros for field calrx_pga_open_rcc
 * @details Disconnect cross-coupling resistors around PGA during RX loopback calibration (reserved)
 * @{
 */
#define RADIO_RX_CAL_CFG__CALRX_PGA_OPEN_RCC__SHIFT                          29
#define RADIO_RX_CAL_CFG__CALRX_PGA_OPEN_RCC__WIDTH                           1
#define RADIO_RX_CAL_CFG__CALRX_PGA_OPEN_RCC__MASK                  0x20000000U
#define RADIO_RX_CAL_CFG__CALRX_PGA_OPEN_RCC__READ(src) \
                    (((uint32_t)(src)\
                    & 0x20000000U) >> 29)
#define RADIO_RX_CAL_CFG__CALRX_PGA_OPEN_RCC__WRITE(src) \
                    (((uint32_t)(src)\
                    << 29) & 0x20000000U)
#define RADIO_RX_CAL_CFG__CALRX_PGA_OPEN_RCC__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | (((uint32_t)(src) <<\
                    29) & 0x20000000U)
#define RADIO_RX_CAL_CFG__CALRX_PGA_OPEN_RCC__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 29) & ~0x20000000U)))
#define RADIO_RX_CAL_CFG__CALRX_PGA_OPEN_RCC__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | ((uint32_t)(1) << 29)
#define RADIO_RX_CAL_CFG__CALRX_PGA_OPEN_RCC__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | ((uint32_t)(0) << 29)
#define RADIO_RX_CAL_CFG__CALRX_PGA_OPEN_RCC__RESET_VALUE           0x00000000U
/** @} */

/* macros for field calrx_pga_open_rfb */
/**
 * @defgroup radio_rx_regs_core_calrx_pga_open_rfb_field calrx_pga_open_rfb_field
 * @brief macros for field calrx_pga_open_rfb
 * @details Disconnect feedback resistors around PGA during RX loopback calibration (reserved)
 * @{
 */
#define RADIO_RX_CAL_CFG__CALRX_PGA_OPEN_RFB__SHIFT                          30
#define RADIO_RX_CAL_CFG__CALRX_PGA_OPEN_RFB__WIDTH                           1
#define RADIO_RX_CAL_CFG__CALRX_PGA_OPEN_RFB__MASK                  0x40000000U
#define RADIO_RX_CAL_CFG__CALRX_PGA_OPEN_RFB__READ(src) \
                    (((uint32_t)(src)\
                    & 0x40000000U) >> 30)
#define RADIO_RX_CAL_CFG__CALRX_PGA_OPEN_RFB__WRITE(src) \
                    (((uint32_t)(src)\
                    << 30) & 0x40000000U)
#define RADIO_RX_CAL_CFG__CALRX_PGA_OPEN_RFB__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | (((uint32_t)(src) <<\
                    30) & 0x40000000U)
#define RADIO_RX_CAL_CFG__CALRX_PGA_OPEN_RFB__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 30) & ~0x40000000U)))
#define RADIO_RX_CAL_CFG__CALRX_PGA_OPEN_RFB__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(1) << 30)
#define RADIO_RX_CAL_CFG__CALRX_PGA_OPEN_RFB__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(0) << 30)
#define RADIO_RX_CAL_CFG__CALRX_PGA_OPEN_RFB__RESET_VALUE           0x00000000U
/** @} */

/* macros for field calrx_adc_en */
/**
 * @defgroup radio_rx_regs_core_calrx_adc_en_field calrx_adc_en_field
 * @brief macros for field calrx_adc_en
 * @details ADC enable during RX loopback calibration (reserved)
 * @{
 */
#define RADIO_RX_CAL_CFG__CALRX_ADC_EN__SHIFT                                31
#define RADIO_RX_CAL_CFG__CALRX_ADC_EN__WIDTH                                 1
#define RADIO_RX_CAL_CFG__CALRX_ADC_EN__MASK                        0x80000000U
#define RADIO_RX_CAL_CFG__CALRX_ADC_EN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x80000000U) >> 31)
#define RADIO_RX_CAL_CFG__CALRX_ADC_EN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 31) & 0x80000000U)
#define RADIO_RX_CAL_CFG__CALRX_ADC_EN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | (((uint32_t)(src) <<\
                    31) & 0x80000000U)
#define RADIO_RX_CAL_CFG__CALRX_ADC_EN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 31) & ~0x80000000U)))
#define RADIO_RX_CAL_CFG__CALRX_ADC_EN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(1) << 31)
#define RADIO_RX_CAL_CFG__CALRX_ADC_EN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(0) << 31)
#define RADIO_RX_CAL_CFG__CALRX_ADC_EN__RESET_VALUE                 0x00000001U
/** @} */
#define RADIO_RX_CAL_CFG__TYPE                                         uint32_t
#define RADIO_RX_CAL_CFG__READ                                      0xffffffffU
#define RADIO_RX_CAL_CFG__WRITE                                     0xffffffffU
#define RADIO_RX_CAL_CFG__PRESERVED                                 0x00000000U
#define RADIO_RX_CAL_CFG__RESET_VALUE                               0x9321e126U

#endif /* __RADIO_RX_CAL_CFG_MACRO__ */

/** @} end of cal_cfg */

/* macros for BlueprintGlobalNameSpace::radio_rx_gain_ctrl */
/**
 * @defgroup radio_rx_regs_core_gain_ctrl gain_ctrl
 * @brief Gain control overrides definitions.
 * @{
 */
#ifndef __RADIO_RX_GAIN_CTRL_MACRO__
#define __RADIO_RX_GAIN_CTRL_MACRO__

/* macros for field rfgain_ov_en */
/**
 * @defgroup radio_rx_regs_core_rfgain_ov_en_field rfgain_ov_en_field
 * @brief macros for field rfgain_ov_en
 * @details When set, take LNA gain from override registers, note DC offset won't be applied correctly
 * @{
 */
#define RADIO_RX_GAIN_CTRL__RFGAIN_OV_EN__SHIFT                               0
#define RADIO_RX_GAIN_CTRL__RFGAIN_OV_EN__WIDTH                               1
#define RADIO_RX_GAIN_CTRL__RFGAIN_OV_EN__MASK                      0x00000001U
#define RADIO_RX_GAIN_CTRL__RFGAIN_OV_EN__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define RADIO_RX_GAIN_CTRL__RFGAIN_OV_EN__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define RADIO_RX_GAIN_CTRL__RFGAIN_OV_EN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define RADIO_RX_GAIN_CTRL__RFGAIN_OV_EN__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define RADIO_RX_GAIN_CTRL__RFGAIN_OV_EN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define RADIO_RX_GAIN_CTRL__RFGAIN_OV_EN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define RADIO_RX_GAIN_CTRL__RFGAIN_OV_EN__RESET_VALUE               0x00000000U
/** @} */

/* macros for field bbgain_ov_en */
/**
 * @defgroup radio_rx_regs_core_bbgain_ov_en_field bbgain_ov_en_field
 * @brief macros for field bbgain_ov_en
 * @details When set, take TIA and PGA gain from override registers
 * @{
 */
#define RADIO_RX_GAIN_CTRL__BBGAIN_OV_EN__SHIFT                               1
#define RADIO_RX_GAIN_CTRL__BBGAIN_OV_EN__WIDTH                               1
#define RADIO_RX_GAIN_CTRL__BBGAIN_OV_EN__MASK                      0x00000002U
#define RADIO_RX_GAIN_CTRL__BBGAIN_OV_EN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define RADIO_RX_GAIN_CTRL__BBGAIN_OV_EN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define RADIO_RX_GAIN_CTRL__BBGAIN_OV_EN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define RADIO_RX_GAIN_CTRL__BBGAIN_OV_EN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define RADIO_RX_GAIN_CTRL__BBGAIN_OV_EN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define RADIO_RX_GAIN_CTRL__BBGAIN_OV_EN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define RADIO_RX_GAIN_CTRL__BBGAIN_OV_EN__RESET_VALUE               0x00000000U
/** @} */

/* macros for field lnagain_ovr */
/**
 * @defgroup radio_rx_regs_core_lnagain_ovr_field lnagain_ovr_field
 * @brief macros for field lnagain_ovr
 * @details LNA gain override when rfgain_ov_en = 1
 * @{
 */
#define RADIO_RX_GAIN_CTRL__LNAGAIN_OVR__SHIFT                                2
#define RADIO_RX_GAIN_CTRL__LNAGAIN_OVR__WIDTH                                3
#define RADIO_RX_GAIN_CTRL__LNAGAIN_OVR__MASK                       0x0000001cU
#define RADIO_RX_GAIN_CTRL__LNAGAIN_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000001cU) >> 2)
#define RADIO_RX_GAIN_CTRL__LNAGAIN_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x0000001cU)
#define RADIO_RX_GAIN_CTRL__LNAGAIN_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000001cU) | (((uint32_t)(src) <<\
                    2) & 0x0000001cU)
#define RADIO_RX_GAIN_CTRL__LNAGAIN_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x0000001cU)))
#define RADIO_RX_GAIN_CTRL__LNAGAIN_OVR__RESET_VALUE                0x00000007U
/** @} */

/* macros for field tia_gain_ovr */
/**
 * @defgroup radio_rx_regs_core_tia_gain_ovr_field tia_gain_ovr_field
 * @brief macros for field tia_gain_ovr
 * @details Override value for TIA gain
 * @{
 */
#define RADIO_RX_GAIN_CTRL__TIA_GAIN_OVR__SHIFT                               5
#define RADIO_RX_GAIN_CTRL__TIA_GAIN_OVR__WIDTH                               2
#define RADIO_RX_GAIN_CTRL__TIA_GAIN_OVR__MASK                      0x00000060U
#define RADIO_RX_GAIN_CTRL__TIA_GAIN_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000060U) >> 5)
#define RADIO_RX_GAIN_CTRL__TIA_GAIN_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 5) & 0x00000060U)
#define RADIO_RX_GAIN_CTRL__TIA_GAIN_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000060U) | (((uint32_t)(src) <<\
                    5) & 0x00000060U)
#define RADIO_RX_GAIN_CTRL__TIA_GAIN_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 5) & ~0x00000060U)))
#define RADIO_RX_GAIN_CTRL__TIA_GAIN_OVR__RESET_VALUE               0x00000000U
/** @} */

/* macros for field pga_gain_ovr */
/**
 * @defgroup radio_rx_regs_core_pga_gain_ovr_field pga_gain_ovr_field
 * @brief macros for field pga_gain_ovr
 * @details Override value for PGA gain
 * @{
 */
#define RADIO_RX_GAIN_CTRL__PGA_GAIN_OVR__SHIFT                               7
#define RADIO_RX_GAIN_CTRL__PGA_GAIN_OVR__WIDTH                               5
#define RADIO_RX_GAIN_CTRL__PGA_GAIN_OVR__MASK                      0x00000f80U
#define RADIO_RX_GAIN_CTRL__PGA_GAIN_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000f80U) >> 7)
#define RADIO_RX_GAIN_CTRL__PGA_GAIN_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 7) & 0x00000f80U)
#define RADIO_RX_GAIN_CTRL__PGA_GAIN_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000f80U) | (((uint32_t)(src) <<\
                    7) & 0x00000f80U)
#define RADIO_RX_GAIN_CTRL__PGA_GAIN_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 7) & ~0x00000f80U)))
#define RADIO_RX_GAIN_CTRL__PGA_GAIN_OVR__RESET_VALUE               0x00000018U
/** @} */
#define RADIO_RX_GAIN_CTRL__TYPE                                       uint32_t
#define RADIO_RX_GAIN_CTRL__READ                                    0x00000fffU
#define RADIO_RX_GAIN_CTRL__WRITE                                   0x00000fffU
#define RADIO_RX_GAIN_CTRL__PRESERVED                               0x00000000U
#define RADIO_RX_GAIN_CTRL__RESET_VALUE                             0x00000c1cU

#endif /* __RADIO_RX_GAIN_CTRL_MACRO__ */

/** @} end of gain_ctrl */

/* macros for BlueprintGlobalNameSpace::radio_rx_ana_ctrl */
/**
 * @defgroup radio_rx_regs_core_ana_ctrl ana_ctrl
 * @brief Analog adjustments and test mode control definitions.
 * @{
 */
#ifndef __RADIO_RX_ANA_CTRL_MACRO__
#define __RADIO_RX_ANA_CTRL_MACRO__

/* macros for field lna_shortSrc */
/**
 * @defgroup radio_rx_regs_core_lna_shortSrc_field lna_shortSrc_field
 * @brief macros for field lna_shortSrc
 * @details short source degen inductor
 * @{
 */
#define RADIO_RX_ANA_CTRL__LNA_SHORTSRC__SHIFT                                0
#define RADIO_RX_ANA_CTRL__LNA_SHORTSRC__WIDTH                                1
#define RADIO_RX_ANA_CTRL__LNA_SHORTSRC__MASK                       0x00000001U
#define RADIO_RX_ANA_CTRL__LNA_SHORTSRC__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define RADIO_RX_ANA_CTRL__LNA_SHORTSRC__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define RADIO_RX_ANA_CTRL__LNA_SHORTSRC__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define RADIO_RX_ANA_CTRL__LNA_SHORTSRC__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define RADIO_RX_ANA_CTRL__LNA_SHORTSRC__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define RADIO_RX_ANA_CTRL__LNA_SHORTSRC__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define RADIO_RX_ANA_CTRL__LNA_SHORTSRC__RESET_VALUE                0x00000000U
/** @} */

/* macros for field lna_ctune */
/**
 * @defgroup radio_rx_regs_core_lna_ctune_field lna_ctune_field
 * @brief macros for field lna_ctune
 * @details find the best value
 * @{
 */
#define RADIO_RX_ANA_CTRL__LNA_CTUNE__SHIFT                                   1
#define RADIO_RX_ANA_CTRL__LNA_CTUNE__WIDTH                                   3
#define RADIO_RX_ANA_CTRL__LNA_CTUNE__MASK                          0x0000000eU
#define RADIO_RX_ANA_CTRL__LNA_CTUNE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000000eU) >> 1)
#define RADIO_RX_ANA_CTRL__LNA_CTUNE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x0000000eU)
#define RADIO_RX_ANA_CTRL__LNA_CTUNE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000000eU) | (((uint32_t)(src) <<\
                    1) & 0x0000000eU)
#define RADIO_RX_ANA_CTRL__LNA_CTUNE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x0000000eU)))
#define RADIO_RX_ANA_CTRL__LNA_CTUNE__RESET_VALUE                   0x00000004U
/** @} */

/* macros for field tia_open_rcc */
/**
 * @defgroup radio_rx_regs_core_tia_open_rcc_field tia_open_rcc_field
 * @brief macros for field tia_open_rcc
 * @details when =1, disconnect cross-coupling resistor around TIA and revert to real filter
 * @{
 */
#define RADIO_RX_ANA_CTRL__TIA_OPEN_RCC__SHIFT                                4
#define RADIO_RX_ANA_CTRL__TIA_OPEN_RCC__WIDTH                                1
#define RADIO_RX_ANA_CTRL__TIA_OPEN_RCC__MASK                       0x00000010U
#define RADIO_RX_ANA_CTRL__TIA_OPEN_RCC__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000010U) >> 4)
#define RADIO_RX_ANA_CTRL__TIA_OPEN_RCC__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x00000010U)
#define RADIO_RX_ANA_CTRL__TIA_OPEN_RCC__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | (((uint32_t)(src) <<\
                    4) & 0x00000010U)
#define RADIO_RX_ANA_CTRL__TIA_OPEN_RCC__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x00000010U)))
#define RADIO_RX_ANA_CTRL__TIA_OPEN_RCC__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(1) << 4)
#define RADIO_RX_ANA_CTRL__TIA_OPEN_RCC__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(0) << 4)
#define RADIO_RX_ANA_CTRL__TIA_OPEN_RCC__RESET_VALUE                0x00000000U
/** @} */

/* macros for field tia_open_rfb */
/**
 * @defgroup radio_rx_regs_core_tia_open_rfb_field tia_open_rfb_field
 * @brief macros for field tia_open_rfb
 * @details may need for test
 * @{
 */
#define RADIO_RX_ANA_CTRL__TIA_OPEN_RFB__SHIFT                                5
#define RADIO_RX_ANA_CTRL__TIA_OPEN_RFB__WIDTH                                1
#define RADIO_RX_ANA_CTRL__TIA_OPEN_RFB__MASK                       0x00000020U
#define RADIO_RX_ANA_CTRL__TIA_OPEN_RFB__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000020U) >> 5)
#define RADIO_RX_ANA_CTRL__TIA_OPEN_RFB__WRITE(src) \
                    (((uint32_t)(src)\
                    << 5) & 0x00000020U)
#define RADIO_RX_ANA_CTRL__TIA_OPEN_RFB__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | (((uint32_t)(src) <<\
                    5) & 0x00000020U)
#define RADIO_RX_ANA_CTRL__TIA_OPEN_RFB__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 5) & ~0x00000020U)))
#define RADIO_RX_ANA_CTRL__TIA_OPEN_RFB__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(1) << 5)
#define RADIO_RX_ANA_CTRL__TIA_OPEN_RFB__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(0) << 5)
#define RADIO_RX_ANA_CTRL__TIA_OPEN_RFB__RESET_VALUE                0x00000000U
/** @} */

/* macros for field pga_open_rcc */
/**
 * @defgroup radio_rx_regs_core_pga_open_rcc_field pga_open_rcc_field
 * @brief macros for field pga_open_rcc
 * @details when =1, disconnect cross-coupling resistor around TIA and revert to real filter
 * @{
 */
#define RADIO_RX_ANA_CTRL__PGA_OPEN_RCC__SHIFT                                6
#define RADIO_RX_ANA_CTRL__PGA_OPEN_RCC__WIDTH                                1
#define RADIO_RX_ANA_CTRL__PGA_OPEN_RCC__MASK                       0x00000040U
#define RADIO_RX_ANA_CTRL__PGA_OPEN_RCC__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000040U) >> 6)
#define RADIO_RX_ANA_CTRL__PGA_OPEN_RCC__WRITE(src) \
                    (((uint32_t)(src)\
                    << 6) & 0x00000040U)
#define RADIO_RX_ANA_CTRL__PGA_OPEN_RCC__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | (((uint32_t)(src) <<\
                    6) & 0x00000040U)
#define RADIO_RX_ANA_CTRL__PGA_OPEN_RCC__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 6) & ~0x00000040U)))
#define RADIO_RX_ANA_CTRL__PGA_OPEN_RCC__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(1) << 6)
#define RADIO_RX_ANA_CTRL__PGA_OPEN_RCC__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(0) << 6)
#define RADIO_RX_ANA_CTRL__PGA_OPEN_RCC__RESET_VALUE                0x00000000U
/** @} */

/* macros for field pga_open_rfb */
/**
 * @defgroup radio_rx_regs_core_pga_open_rfb_field pga_open_rfb_field
 * @brief macros for field pga_open_rfb
 * @details may need for test
 * @{
 */
#define RADIO_RX_ANA_CTRL__PGA_OPEN_RFB__SHIFT                                7
#define RADIO_RX_ANA_CTRL__PGA_OPEN_RFB__WIDTH                                1
#define RADIO_RX_ANA_CTRL__PGA_OPEN_RFB__MASK                       0x00000080U
#define RADIO_RX_ANA_CTRL__PGA_OPEN_RFB__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000080U) >> 7)
#define RADIO_RX_ANA_CTRL__PGA_OPEN_RFB__WRITE(src) \
                    (((uint32_t)(src)\
                    << 7) & 0x00000080U)
#define RADIO_RX_ANA_CTRL__PGA_OPEN_RFB__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | (((uint32_t)(src) <<\
                    7) & 0x00000080U)
#define RADIO_RX_ANA_CTRL__PGA_OPEN_RFB__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 7) & ~0x00000080U)))
#define RADIO_RX_ANA_CTRL__PGA_OPEN_RFB__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | ((uint32_t)(1) << 7)
#define RADIO_RX_ANA_CTRL__PGA_OPEN_RFB__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | ((uint32_t)(0) << 7)
#define RADIO_RX_ANA_CTRL__PGA_OPEN_RFB__RESET_VALUE                0x00000000U
/** @} */

/* macros for field tia_pkdet_ref_ctrl */
/**
 * @defgroup radio_rx_regs_core_tia_pkdet_ref_ctrl_field tia_pkdet_ref_ctrl_field
 * @brief macros for field tia_pkdet_ref_ctrl
 * @details adjusts tia peak detector level
 * @{
 */
#define RADIO_RX_ANA_CTRL__TIA_PKDET_REF_CTRL__SHIFT                          8
#define RADIO_RX_ANA_CTRL__TIA_PKDET_REF_CTRL__WIDTH                          3
#define RADIO_RX_ANA_CTRL__TIA_PKDET_REF_CTRL__MASK                 0x00000700U
#define RADIO_RX_ANA_CTRL__TIA_PKDET_REF_CTRL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000700U) >> 8)
#define RADIO_RX_ANA_CTRL__TIA_PKDET_REF_CTRL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00000700U)
#define RADIO_RX_ANA_CTRL__TIA_PKDET_REF_CTRL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000700U) | (((uint32_t)(src) <<\
                    8) & 0x00000700U)
#define RADIO_RX_ANA_CTRL__TIA_PKDET_REF_CTRL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00000700U)))
#define RADIO_RX_ANA_CTRL__TIA_PKDET_REF_CTRL__RESET_VALUE          0x00000000U
/** @} */

/* macros for field testiq_ctrl */
/**
 * @defgroup radio_rx_regs_core_testiq_ctrl_field testiq_ctrl_field
 * @brief macros for field testiq_ctrl
 * @details connect RXBB test points to the testIQ bus (uses one-hot format); 0=hiZ, 1=TIA input, 2=TIA output, 4=PGA output, other values=invalid
 * @{
 */
#define RADIO_RX_ANA_CTRL__TESTIQ_CTRL__SHIFT                                11
#define RADIO_RX_ANA_CTRL__TESTIQ_CTRL__WIDTH                                 3
#define RADIO_RX_ANA_CTRL__TESTIQ_CTRL__MASK                        0x00003800U
#define RADIO_RX_ANA_CTRL__TESTIQ_CTRL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00003800U) >> 11)
#define RADIO_RX_ANA_CTRL__TESTIQ_CTRL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 11) & 0x00003800U)
#define RADIO_RX_ANA_CTRL__TESTIQ_CTRL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00003800U) | (((uint32_t)(src) <<\
                    11) & 0x00003800U)
#define RADIO_RX_ANA_CTRL__TESTIQ_CTRL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 11) & ~0x00003800U)))
#define RADIO_RX_ANA_CTRL__TESTIQ_CTRL__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field rx_atbsel */
/**
 * @defgroup radio_rx_regs_core_rx_atbsel_field rx_atbsel_field
 * @brief macros for field rx_atbsel
 * @details RXFE and RXBB analog test bus selection, 0 = high-Z; 1 = LNA peakdet vref; 2 = LNA peakdet voltage; 3 = RXBB vref_lo_boost; 4 = RXBB common-mode voltage; 5 = spare ir1u current; 6 = spare ic1u current
 * @{
 */
#define RADIO_RX_ANA_CTRL__RX_ATBSEL__SHIFT                                  14
#define RADIO_RX_ANA_CTRL__RX_ATBSEL__WIDTH                                   3
#define RADIO_RX_ANA_CTRL__RX_ATBSEL__MASK                          0x0001c000U
#define RADIO_RX_ANA_CTRL__RX_ATBSEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0001c000U) >> 14)
#define RADIO_RX_ANA_CTRL__RX_ATBSEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 14) & 0x0001c000U)
#define RADIO_RX_ANA_CTRL__RX_ATBSEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0001c000U) | (((uint32_t)(src) <<\
                    14) & 0x0001c000U)
#define RADIO_RX_ANA_CTRL__RX_ATBSEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 14) & ~0x0001c000U)))
#define RADIO_RX_ANA_CTRL__RX_ATBSEL__RESET_VALUE                   0x00000000U
/** @} */

/* macros for field adc_atbsel */
/**
 * @defgroup radio_rx_regs_core_adc_atbsel_field adc_atbsel_field
 * @brief macros for field adc_atbsel
 * @details ADC analog test bus selection, 0 = high-Z; 1 = nbias; 2 = vref0p2; 3 = refnQ; 4 = refpQ; 5 = refnI; 6 = refpI; 7 = ic1u
 * @{
 */
#define RADIO_RX_ANA_CTRL__ADC_ATBSEL__SHIFT                                 17
#define RADIO_RX_ANA_CTRL__ADC_ATBSEL__WIDTH                                  4
#define RADIO_RX_ANA_CTRL__ADC_ATBSEL__MASK                         0x001e0000U
#define RADIO_RX_ANA_CTRL__ADC_ATBSEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x001e0000U) >> 17)
#define RADIO_RX_ANA_CTRL__ADC_ATBSEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 17) & 0x001e0000U)
#define RADIO_RX_ANA_CTRL__ADC_ATBSEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x001e0000U) | (((uint32_t)(src) <<\
                    17) & 0x001e0000U)
#define RADIO_RX_ANA_CTRL__ADC_ATBSEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 17) & ~0x001e0000U)))
#define RADIO_RX_ANA_CTRL__ADC_ATBSEL__RESET_VALUE                  0x00000000U
/** @} */

/* macros for field lna_refLVlBiasCas */
/**
 * @defgroup radio_rx_regs_core_lna_refLVlBiasCas_field lna_refLVlBiasCas_field
 * @brief macros for field lna_refLVlBiasCas
 * @details lna cascode bias
 * @{
 */
#define RADIO_RX_ANA_CTRL__LNA_REFLVLBIASCAS__SHIFT                          21
#define RADIO_RX_ANA_CTRL__LNA_REFLVLBIASCAS__WIDTH                           2
#define RADIO_RX_ANA_CTRL__LNA_REFLVLBIASCAS__MASK                  0x00600000U
#define RADIO_RX_ANA_CTRL__LNA_REFLVLBIASCAS__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00600000U) >> 21)
#define RADIO_RX_ANA_CTRL__LNA_REFLVLBIASCAS__WRITE(src) \
                    (((uint32_t)(src)\
                    << 21) & 0x00600000U)
#define RADIO_RX_ANA_CTRL__LNA_REFLVLBIASCAS__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00600000U) | (((uint32_t)(src) <<\
                    21) & 0x00600000U)
#define RADIO_RX_ANA_CTRL__LNA_REFLVLBIASCAS__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 21) & ~0x00600000U)))
#define RADIO_RX_ANA_CTRL__LNA_REFLVLBIASCAS__RESET_VALUE           0x00000001U
/** @} */

/* macros for field rx_spare */
/**
 * @defgroup radio_rx_regs_core_rx_spare_field rx_spare_field
 * @brief macros for field rx_spare
 * @details Spare bits
 * @{
 */
#define RADIO_RX_ANA_CTRL__RX_SPARE__SHIFT                                   23
#define RADIO_RX_ANA_CTRL__RX_SPARE__WIDTH                                    9
#define RADIO_RX_ANA_CTRL__RX_SPARE__MASK                           0xff800000U
#define RADIO_RX_ANA_CTRL__RX_SPARE__READ(src) \
                    (((uint32_t)(src)\
                    & 0xff800000U) >> 23)
#define RADIO_RX_ANA_CTRL__RX_SPARE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 23) & 0xff800000U)
#define RADIO_RX_ANA_CTRL__RX_SPARE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xff800000U) | (((uint32_t)(src) <<\
                    23) & 0xff800000U)
#define RADIO_RX_ANA_CTRL__RX_SPARE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 23) & ~0xff800000U)))
#define RADIO_RX_ANA_CTRL__RX_SPARE__RESET_VALUE                    0x00000000U
/** @} */
#define RADIO_RX_ANA_CTRL__TYPE                                        uint32_t
#define RADIO_RX_ANA_CTRL__READ                                     0xffffffffU
#define RADIO_RX_ANA_CTRL__WRITE                                    0xffffffffU
#define RADIO_RX_ANA_CTRL__PRESERVED                                0x00000000U
#define RADIO_RX_ANA_CTRL__RESET_VALUE                              0x00200008U

#endif /* __RADIO_RX_ANA_CTRL_MACRO__ */

/** @} end of ana_ctrl */

/* macros for BlueprintGlobalNameSpace::radio_rx_lnagain0 */
/**
 * @defgroup radio_rx_regs_core_lnagain0 lnagain0
 * @brief LNA gain table for LNA, should fix definitions.
 * @{
 */
#ifndef __RADIO_RX_LNAGAIN0_MACRO__
#define __RADIO_RX_LNAGAIN0_MACRO__

/* macros for field entry0 */
/**
 * @defgroup radio_rx_regs_core_entry0_field entry0_field
 * @brief macros for field entry0
 * @details LNA gain index 0
 * @{
 */
#define RADIO_RX_LNAGAIN0__ENTRY0__SHIFT                                      0
#define RADIO_RX_LNAGAIN0__ENTRY0__WIDTH                                      5
#define RADIO_RX_LNAGAIN0__ENTRY0__MASK                             0x0000001fU
#define RADIO_RX_LNAGAIN0__ENTRY0__READ(src)    ((uint32_t)(src) & 0x0000001fU)
#define RADIO_RX_LNAGAIN0__ENTRY0__WRITE(src)   ((uint32_t)(src) & 0x0000001fU)
#define RADIO_RX_LNAGAIN0__ENTRY0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000001fU) | ((uint32_t)(src) &\
                    0x0000001fU)
#define RADIO_RX_LNAGAIN0__ENTRY0__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000001fU)))
#define RADIO_RX_LNAGAIN0__ENTRY0__RESET_VALUE                      0x00000000U
/** @} */

/* macros for field entry1 */
/**
 * @defgroup radio_rx_regs_core_entry1_field entry1_field
 * @brief macros for field entry1
 * @details LNA gain index 1
 * @{
 */
#define RADIO_RX_LNAGAIN0__ENTRY1__SHIFT                                      5
#define RADIO_RX_LNAGAIN0__ENTRY1__WIDTH                                      5
#define RADIO_RX_LNAGAIN0__ENTRY1__MASK                             0x000003e0U
#define RADIO_RX_LNAGAIN0__ENTRY1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000003e0U) >> 5)
#define RADIO_RX_LNAGAIN0__ENTRY1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 5) & 0x000003e0U)
#define RADIO_RX_LNAGAIN0__ENTRY1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000003e0U) | (((uint32_t)(src) <<\
                    5) & 0x000003e0U)
#define RADIO_RX_LNAGAIN0__ENTRY1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 5) & ~0x000003e0U)))
#define RADIO_RX_LNAGAIN0__ENTRY1__RESET_VALUE                      0x00000001U
/** @} */

/* macros for field entry2 */
/**
 * @defgroup radio_rx_regs_core_entry2_field entry2_field
 * @brief macros for field entry2
 * @details LNA gain index 2
 * @{
 */
#define RADIO_RX_LNAGAIN0__ENTRY2__SHIFT                                     10
#define RADIO_RX_LNAGAIN0__ENTRY2__WIDTH                                      5
#define RADIO_RX_LNAGAIN0__ENTRY2__MASK                             0x00007c00U
#define RADIO_RX_LNAGAIN0__ENTRY2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00007c00U) >> 10)
#define RADIO_RX_LNAGAIN0__ENTRY2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x00007c00U)
#define RADIO_RX_LNAGAIN0__ENTRY2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00007c00U) | (((uint32_t)(src) <<\
                    10) & 0x00007c00U)
#define RADIO_RX_LNAGAIN0__ENTRY2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x00007c00U)))
#define RADIO_RX_LNAGAIN0__ENTRY2__RESET_VALUE                      0x00000003U
/** @} */

/* macros for field entry3 */
/**
 * @defgroup radio_rx_regs_core_entry3_field entry3_field
 * @brief macros for field entry3
 * @details LNA gain index 3
 * @{
 */
#define RADIO_RX_LNAGAIN0__ENTRY3__SHIFT                                     15
#define RADIO_RX_LNAGAIN0__ENTRY3__WIDTH                                      5
#define RADIO_RX_LNAGAIN0__ENTRY3__MASK                             0x000f8000U
#define RADIO_RX_LNAGAIN0__ENTRY3__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000f8000U) >> 15)
#define RADIO_RX_LNAGAIN0__ENTRY3__WRITE(src) \
                    (((uint32_t)(src)\
                    << 15) & 0x000f8000U)
#define RADIO_RX_LNAGAIN0__ENTRY3__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000f8000U) | (((uint32_t)(src) <<\
                    15) & 0x000f8000U)
#define RADIO_RX_LNAGAIN0__ENTRY3__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 15) & ~0x000f8000U)))
#define RADIO_RX_LNAGAIN0__ENTRY3__RESET_VALUE                      0x00000007U
/** @} */

/* macros for field entry4 */
/**
 * @defgroup radio_rx_regs_core_entry4_field entry4_field
 * @brief macros for field entry4
 * @details LNA gain index 4
 * @{
 */
#define RADIO_RX_LNAGAIN0__ENTRY4__SHIFT                                     20
#define RADIO_RX_LNAGAIN0__ENTRY4__WIDTH                                      5
#define RADIO_RX_LNAGAIN0__ENTRY4__MASK                             0x01f00000U
#define RADIO_RX_LNAGAIN0__ENTRY4__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01f00000U) >> 20)
#define RADIO_RX_LNAGAIN0__ENTRY4__WRITE(src) \
                    (((uint32_t)(src)\
                    << 20) & 0x01f00000U)
#define RADIO_RX_LNAGAIN0__ENTRY4__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01f00000U) | (((uint32_t)(src) <<\
                    20) & 0x01f00000U)
#define RADIO_RX_LNAGAIN0__ENTRY4__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x01f00000U)))
#define RADIO_RX_LNAGAIN0__ENTRY4__RESET_VALUE                      0x0000000fU
/** @} */

/* macros for field entry5 */
/**
 * @defgroup radio_rx_regs_core_entry5_field entry5_field
 * @brief macros for field entry5
 * @details LNA gain index 5
 * @{
 */
#define RADIO_RX_LNAGAIN0__ENTRY5__SHIFT                                     25
#define RADIO_RX_LNAGAIN0__ENTRY5__WIDTH                                      5
#define RADIO_RX_LNAGAIN0__ENTRY5__MASK                             0x3e000000U
#define RADIO_RX_LNAGAIN0__ENTRY5__READ(src) \
                    (((uint32_t)(src)\
                    & 0x3e000000U) >> 25)
#define RADIO_RX_LNAGAIN0__ENTRY5__WRITE(src) \
                    (((uint32_t)(src)\
                    << 25) & 0x3e000000U)
#define RADIO_RX_LNAGAIN0__ENTRY5__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x3e000000U) | (((uint32_t)(src) <<\
                    25) & 0x3e000000U)
#define RADIO_RX_LNAGAIN0__ENTRY5__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 25) & ~0x3e000000U)))
#define RADIO_RX_LNAGAIN0__ENTRY5__RESET_VALUE                      0x0000001fU
/** @} */
#define RADIO_RX_LNAGAIN0__TYPE                                        uint32_t
#define RADIO_RX_LNAGAIN0__READ                                     0x3fffffffU
#define RADIO_RX_LNAGAIN0__WRITE                                    0x3fffffffU
#define RADIO_RX_LNAGAIN0__PRESERVED                                0x00000000U
#define RADIO_RX_LNAGAIN0__RESET_VALUE                              0x3ef38c20U

#endif /* __RADIO_RX_LNAGAIN0_MACRO__ */

/** @} end of lnagain0 */

/* macros for BlueprintGlobalNameSpace::radio_rx_rxbias */
/**
 * @defgroup radio_rx_regs_core_rxbias rxbias
 * @brief Bias current settings, 0.25uA to 2uA in 0.25uA steps definitions.
 * @{
 */
#ifndef __RADIO_RX_RXBIAS_MACRO__
#define __RADIO_RX_RXBIAS_MACRO__

/* macros for field sel_irtiapkdet_ref */
/**
 * @defgroup radio_rx_regs_core_sel_irtiapkdet_ref_field sel_irtiapkdet_ref_field
 * @brief macros for field sel_irtiapkdet_ref
 * @details Mixer IC bias current, default 1uA
 * @{
 */
#define RADIO_RX_RXBIAS__SEL_IRTIAPKDET_REF__SHIFT                            0
#define RADIO_RX_RXBIAS__SEL_IRTIAPKDET_REF__WIDTH                            3
#define RADIO_RX_RXBIAS__SEL_IRTIAPKDET_REF__MASK                   0x00000007U
#define RADIO_RX_RXBIAS__SEL_IRTIAPKDET_REF__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000007U)
#define RADIO_RX_RXBIAS__SEL_IRTIAPKDET_REF__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000007U)
#define RADIO_RX_RXBIAS__SEL_IRTIAPKDET_REF__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000007U) | ((uint32_t)(src) &\
                    0x00000007U)
#define RADIO_RX_RXBIAS__SEL_IRTIAPKDET_REF__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000007U)))
#define RADIO_RX_RXBIAS__SEL_IRTIAPKDET_REF__RESET_VALUE            0x00000003U
/** @} */

/* macros for field sel_ictia */
/**
 * @defgroup radio_rx_regs_core_sel_ictia_field sel_ictia_field
 * @brief macros for field sel_ictia
 * @details TIA IC bias current for both I and Q channels, default 1uA
 * @{
 */
#define RADIO_RX_RXBIAS__SEL_ICTIA__SHIFT                                     3
#define RADIO_RX_RXBIAS__SEL_ICTIA__WIDTH                                     3
#define RADIO_RX_RXBIAS__SEL_ICTIA__MASK                            0x00000038U
#define RADIO_RX_RXBIAS__SEL_ICTIA__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000038U) >> 3)
#define RADIO_RX_RXBIAS__SEL_ICTIA__WRITE(src) \
                    (((uint32_t)(src)\
                    << 3) & 0x00000038U)
#define RADIO_RX_RXBIAS__SEL_ICTIA__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000038U) | (((uint32_t)(src) <<\
                    3) & 0x00000038U)
#define RADIO_RX_RXBIAS__SEL_ICTIA__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000038U)))
#define RADIO_RX_RXBIAS__SEL_ICTIA__RESET_VALUE                     0x00000007U
/** @} */

/* macros for field sel_ictiadcoc */
/**
 * @defgroup radio_rx_regs_core_sel_ictiadcoc_field sel_ictiadcoc_field
 * @brief macros for field sel_ictiadcoc
 * @details TIA offset DAC IC bias current for both I and Q channels, default 0.75uA
 * @{
 */
#define RADIO_RX_RXBIAS__SEL_ICTIADCOC__SHIFT                                 6
#define RADIO_RX_RXBIAS__SEL_ICTIADCOC__WIDTH                                 3
#define RADIO_RX_RXBIAS__SEL_ICTIADCOC__MASK                        0x000001c0U
#define RADIO_RX_RXBIAS__SEL_ICTIADCOC__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000001c0U) >> 6)
#define RADIO_RX_RXBIAS__SEL_ICTIADCOC__WRITE(src) \
                    (((uint32_t)(src)\
                    << 6) & 0x000001c0U)
#define RADIO_RX_RXBIAS__SEL_ICTIADCOC__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000001c0U) | (((uint32_t)(src) <<\
                    6) & 0x000001c0U)
#define RADIO_RX_RXBIAS__SEL_ICTIADCOC__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 6) & ~0x000001c0U)))
#define RADIO_RX_RXBIAS__SEL_ICTIADCOC__RESET_VALUE                 0x00000003U
/** @} */

/* macros for field sel_irpgadcoc */
/**
 * @defgroup radio_rx_regs_core_sel_irpgadcoc_field sel_irpgadcoc_field
 * @brief macros for field sel_irpgadcoc
 * @details PGA offset DAC IC bias current for both I and Q channels, default 1uA
 * @{
 */
#define RADIO_RX_RXBIAS__SEL_IRPGADCOC__SHIFT                                 9
#define RADIO_RX_RXBIAS__SEL_IRPGADCOC__WIDTH                                 3
#define RADIO_RX_RXBIAS__SEL_IRPGADCOC__MASK                        0x00000e00U
#define RADIO_RX_RXBIAS__SEL_IRPGADCOC__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000e00U) >> 9)
#define RADIO_RX_RXBIAS__SEL_IRPGADCOC__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x00000e00U)
#define RADIO_RX_RXBIAS__SEL_IRPGADCOC__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000e00U) | (((uint32_t)(src) <<\
                    9) & 0x00000e00U)
#define RADIO_RX_RXBIAS__SEL_IRPGADCOC__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x00000e00U)))
#define RADIO_RX_RXBIAS__SEL_IRPGADCOC__RESET_VALUE                 0x00000003U
/** @} */

/* macros for field sel_icadc */
/**
 * @defgroup radio_rx_regs_core_sel_icadc_field sel_icadc_field
 * @brief macros for field sel_icadc
 * @details ADC IC bias current, default 1uA
 * @{
 */
#define RADIO_RX_RXBIAS__SEL_ICADC__SHIFT                                    12
#define RADIO_RX_RXBIAS__SEL_ICADC__WIDTH                                     3
#define RADIO_RX_RXBIAS__SEL_ICADC__MASK                            0x00007000U
#define RADIO_RX_RXBIAS__SEL_ICADC__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00007000U) >> 12)
#define RADIO_RX_RXBIAS__SEL_ICADC__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x00007000U)
#define RADIO_RX_RXBIAS__SEL_ICADC__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00007000U) | (((uint32_t)(src) <<\
                    12) & 0x00007000U)
#define RADIO_RX_RXBIAS__SEL_ICADC__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x00007000U)))
#define RADIO_RX_RXBIAS__SEL_ICADC__RESET_VALUE                     0x00000003U
/** @} */

/* macros for field sel_icspare */
/**
 * @defgroup radio_rx_regs_core_sel_icspare_field sel_icspare_field
 * @brief macros for field sel_icspare
 * @details Spare IC bias currents, default 1uA
 * @{
 */
#define RADIO_RX_RXBIAS__SEL_ICSPARE__SHIFT                                  15
#define RADIO_RX_RXBIAS__SEL_ICSPARE__WIDTH                                   3
#define RADIO_RX_RXBIAS__SEL_ICSPARE__MASK                          0x00038000U
#define RADIO_RX_RXBIAS__SEL_ICSPARE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00038000U) >> 15)
#define RADIO_RX_RXBIAS__SEL_ICSPARE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 15) & 0x00038000U)
#define RADIO_RX_RXBIAS__SEL_ICSPARE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00038000U) | (((uint32_t)(src) <<\
                    15) & 0x00038000U)
#define RADIO_RX_RXBIAS__SEL_ICSPARE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 15) & ~0x00038000U)))
#define RADIO_RX_RXBIAS__SEL_ICSPARE__RESET_VALUE                   0x00000003U
/** @} */

/* macros for field sel_irrxbb */
/**
 * @defgroup radio_rx_regs_core_sel_irrxbb_field sel_irrxbb_field
 * @brief macros for field sel_irrxbb
 * @details RXBB IR bias current, default 1uA
 * @{
 */
#define RADIO_RX_RXBIAS__SEL_IRRXBB__SHIFT                                   18
#define RADIO_RX_RXBIAS__SEL_IRRXBB__WIDTH                                    3
#define RADIO_RX_RXBIAS__SEL_IRRXBB__MASK                           0x001c0000U
#define RADIO_RX_RXBIAS__SEL_IRRXBB__READ(src) \
                    (((uint32_t)(src)\
                    & 0x001c0000U) >> 18)
#define RADIO_RX_RXBIAS__SEL_IRRXBB__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0x001c0000U)
#define RADIO_RX_RXBIAS__SEL_IRRXBB__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x001c0000U) | (((uint32_t)(src) <<\
                    18) & 0x001c0000U)
#define RADIO_RX_RXBIAS__SEL_IRRXBB__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x001c0000U)))
#define RADIO_RX_RXBIAS__SEL_IRRXBB__RESET_VALUE                    0x00000003U
/** @} */

/* macros for field sel_iradc */
/**
 * @defgroup radio_rx_regs_core_sel_iradc_field sel_iradc_field
 * @brief macros for field sel_iradc
 * @details ADC IR bias current, default 1uA
 * @{
 */
#define RADIO_RX_RXBIAS__SEL_IRADC__SHIFT                                    21
#define RADIO_RX_RXBIAS__SEL_IRADC__WIDTH                                     3
#define RADIO_RX_RXBIAS__SEL_IRADC__MASK                            0x00e00000U
#define RADIO_RX_RXBIAS__SEL_IRADC__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00e00000U) >> 21)
#define RADIO_RX_RXBIAS__SEL_IRADC__WRITE(src) \
                    (((uint32_t)(src)\
                    << 21) & 0x00e00000U)
#define RADIO_RX_RXBIAS__SEL_IRADC__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00e00000U) | (((uint32_t)(src) <<\
                    21) & 0x00e00000U)
#define RADIO_RX_RXBIAS__SEL_IRADC__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 21) & ~0x00e00000U)))
#define RADIO_RX_RXBIAS__SEL_IRADC__RESET_VALUE                     0x00000003U
/** @} */

/* macros for field sel_irspare */
/**
 * @defgroup radio_rx_regs_core_sel_irspare_field sel_irspare_field
 * @brief macros for field sel_irspare
 * @details Spare IR bias currents, default 1uA
 * @{
 */
#define RADIO_RX_RXBIAS__SEL_IRSPARE__SHIFT                                  24
#define RADIO_RX_RXBIAS__SEL_IRSPARE__WIDTH                                   3
#define RADIO_RX_RXBIAS__SEL_IRSPARE__MASK                          0x07000000U
#define RADIO_RX_RXBIAS__SEL_IRSPARE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x07000000U) >> 24)
#define RADIO_RX_RXBIAS__SEL_IRSPARE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x07000000U)
#define RADIO_RX_RXBIAS__SEL_IRSPARE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x07000000U) | (((uint32_t)(src) <<\
                    24) & 0x07000000U)
#define RADIO_RX_RXBIAS__SEL_IRSPARE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x07000000U)))
#define RADIO_RX_RXBIAS__SEL_IRSPARE__RESET_VALUE                   0x00000003U
/** @} */
#define RADIO_RX_RXBIAS__TYPE                                          uint32_t
#define RADIO_RX_RXBIAS__READ                                       0x07ffffffU
#define RADIO_RX_RXBIAS__WRITE                                      0x07ffffffU
#define RADIO_RX_RXBIAS__PRESERVED                                  0x00000000U
#define RADIO_RX_RXBIAS__RESET_VALUE                                0x036db6fbU

#endif /* __RADIO_RX_RXBIAS_MACRO__ */

/** @} end of rxbias */

/* macros for BlueprintGlobalNameSpace::radio_rx_status */
/**
 * @defgroup radio_rx_regs_core_status status
 * @brief Applied enables, ctune, and LNA peak detector readback definitions.
 * @{
 */
#ifndef __RADIO_RX_STATUS_MACRO__
#define __RADIO_RX_STATUS_MACRO__

/* macros for field tia_peakdet */
/**
 * @defgroup radio_rx_regs_core_tia_peakdet_field tia_peakdet_field
 * @brief macros for field tia_peakdet
 * @details tia peak detector status
 * @{
 */
#define RADIO_RX_STATUS__TIA_PEAKDET__SHIFT                                   0
#define RADIO_RX_STATUS__TIA_PEAKDET__WIDTH                                   1
#define RADIO_RX_STATUS__TIA_PEAKDET__MASK                          0x00000001U
#define RADIO_RX_STATUS__TIA_PEAKDET__READ(src) ((uint32_t)(src) & 0x00000001U)
#define RADIO_RX_STATUS__TIA_PEAKDET__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define RADIO_RX_STATUS__TIA_PEAKDET__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define RADIO_RX_STATUS__TIA_PEAKDET__RESET_VALUE                   0x00000000U
/** @} */

/* macros for field lna_en */
/**
 * @defgroup radio_rx_regs_core_lna_en_field lna_en_field
 * @brief macros for field lna_en
 * @details LNA enable status
 * @{
 */
#define RADIO_RX_STATUS__LNA_EN__SHIFT                                        1
#define RADIO_RX_STATUS__LNA_EN__WIDTH                                        1
#define RADIO_RX_STATUS__LNA_EN__MASK                               0x00000002U
#define RADIO_RX_STATUS__LNA_EN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define RADIO_RX_STATUS__LNA_EN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define RADIO_RX_STATUS__LNA_EN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define RADIO_RX_STATUS__LNA_EN__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field lna_peakdet */
/**
 * @defgroup radio_rx_regs_core_lna_peakdet_field lna_peakdet_field
 * @brief macros for field lna_peakdet
 * @details LNA peak detector comparator output status
 * @{
 */
#define RADIO_RX_STATUS__LNA_PEAKDET__SHIFT                                   2
#define RADIO_RX_STATUS__LNA_PEAKDET__WIDTH                                   1
#define RADIO_RX_STATUS__LNA_PEAKDET__MASK                          0x00000004U
#define RADIO_RX_STATUS__LNA_PEAKDET__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define RADIO_RX_STATUS__LNA_PEAKDET__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define RADIO_RX_STATUS__LNA_PEAKDET__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define RADIO_RX_STATUS__LNA_PEAKDET__RESET_VALUE                   0x00000000U
/** @} */

/* macros for field mix_en */
/**
 * @defgroup radio_rx_regs_core_mix_en_field mix_en_field
 * @brief macros for field mix_en
 * @details Mixer enable status
 * @{
 */
#define RADIO_RX_STATUS__MIX_EN__SHIFT                                        3
#define RADIO_RX_STATUS__MIX_EN__WIDTH                                        1
#define RADIO_RX_STATUS__MIX_EN__MASK                               0x00000008U
#define RADIO_RX_STATUS__MIX_EN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000008U) >> 3)
#define RADIO_RX_STATUS__MIX_EN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define RADIO_RX_STATUS__MIX_EN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)
#define RADIO_RX_STATUS__MIX_EN__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field tiai_en */
/**
 * @defgroup radio_rx_regs_core_tiai_en_field tiai_en_field
 * @brief macros for field tiai_en
 * @details TIA I-channel enable status
 * @{
 */
#define RADIO_RX_STATUS__TIAI_EN__SHIFT                                       4
#define RADIO_RX_STATUS__TIAI_EN__WIDTH                                       1
#define RADIO_RX_STATUS__TIAI_EN__MASK                              0x00000010U
#define RADIO_RX_STATUS__TIAI_EN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000010U) >> 4)
#define RADIO_RX_STATUS__TIAI_EN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(1) << 4)
#define RADIO_RX_STATUS__TIAI_EN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(0) << 4)
#define RADIO_RX_STATUS__TIAI_EN__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field pgai_en */
/**
 * @defgroup radio_rx_regs_core_pgai_en_field pgai_en_field
 * @brief macros for field pgai_en
 * @details PGA I-channel enable status
 * @{
 */
#define RADIO_RX_STATUS__PGAI_EN__SHIFT                                       5
#define RADIO_RX_STATUS__PGAI_EN__WIDTH                                       1
#define RADIO_RX_STATUS__PGAI_EN__MASK                              0x00000020U
#define RADIO_RX_STATUS__PGAI_EN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000020U) >> 5)
#define RADIO_RX_STATUS__PGAI_EN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(1) << 5)
#define RADIO_RX_STATUS__PGAI_EN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(0) << 5)
#define RADIO_RX_STATUS__PGAI_EN__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field adci_en */
/**
 * @defgroup radio_rx_regs_core_adci_en_field adci_en_field
 * @brief macros for field adci_en
 * @details ADC I-channel enable status
 * @{
 */
#define RADIO_RX_STATUS__ADCI_EN__SHIFT                                       6
#define RADIO_RX_STATUS__ADCI_EN__WIDTH                                       1
#define RADIO_RX_STATUS__ADCI_EN__MASK                              0x00000040U
#define RADIO_RX_STATUS__ADCI_EN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000040U) >> 6)
#define RADIO_RX_STATUS__ADCI_EN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(1) << 6)
#define RADIO_RX_STATUS__ADCI_EN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(0) << 6)
#define RADIO_RX_STATUS__ADCI_EN__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field adcref_en */
/**
 * @defgroup radio_rx_regs_core_adcref_en_field adcref_en_field
 * @brief macros for field adcref_en
 * @details ADC reference enable status
 * @{
 */
#define RADIO_RX_STATUS__ADCREF_EN__SHIFT                                     7
#define RADIO_RX_STATUS__ADCREF_EN__WIDTH                                     1
#define RADIO_RX_STATUS__ADCREF_EN__MASK                            0x00000080U
#define RADIO_RX_STATUS__ADCREF_EN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000080U) >> 7)
#define RADIO_RX_STATUS__ADCREF_EN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | ((uint32_t)(1) << 7)
#define RADIO_RX_STATUS__ADCREF_EN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | ((uint32_t)(0) << 7)
#define RADIO_RX_STATUS__ADCREF_EN__RESET_VALUE                     0x00000000U
/** @} */

/* macros for field adc_rstb */
/**
 * @defgroup radio_rx_regs_core_adc_rstb_field adc_rstb_field
 * @brief macros for field adc_rstb
 * @details ADC reset_b status
 * @{
 */
#define RADIO_RX_STATUS__ADC_RSTB__SHIFT                                      8
#define RADIO_RX_STATUS__ADC_RSTB__WIDTH                                      1
#define RADIO_RX_STATUS__ADC_RSTB__MASK                             0x00000100U
#define RADIO_RX_STATUS__ADC_RSTB__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000100U) >> 8)
#define RADIO_RX_STATUS__ADC_RSTB__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | ((uint32_t)(1) << 8)
#define RADIO_RX_STATUS__ADC_RSTB__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | ((uint32_t)(0) << 8)
#define RADIO_RX_STATUS__ADC_RSTB__RESET_VALUE                      0x00000000U
/** @} */

/* macros for field rxbias_en */
/**
 * @defgroup radio_rx_regs_core_rxbias_en_field rxbias_en_field
 * @brief macros for field rxbias_en
 * @details RX bias enable status
 * @{
 */
#define RADIO_RX_STATUS__RXBIAS_EN__SHIFT                                     9
#define RADIO_RX_STATUS__RXBIAS_EN__WIDTH                                     1
#define RADIO_RX_STATUS__RXBIAS_EN__MASK                            0x00000200U
#define RADIO_RX_STATUS__RXBIAS_EN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000200U) >> 9)
#define RADIO_RX_STATUS__RXBIAS_EN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | ((uint32_t)(1) << 9)
#define RADIO_RX_STATUS__RXBIAS_EN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | ((uint32_t)(0) << 9)
#define RADIO_RX_STATUS__RXBIAS_EN__RESET_VALUE                     0x00000000U
/** @} */

/* macros for field lnagain */
/**
 * @defgroup radio_rx_regs_core_lnagain_field lnagain_field
 * @brief macros for field lnagain
 * @details LNA gain status
 * @{
 */
#define RADIO_RX_STATUS__LNAGAIN__SHIFT                                      10
#define RADIO_RX_STATUS__LNAGAIN__WIDTH                                       3
#define RADIO_RX_STATUS__LNAGAIN__MASK                              0x00001c00U
#define RADIO_RX_STATUS__LNAGAIN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00001c00U) >> 10)
#define RADIO_RX_STATUS__LNAGAIN__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field tia_gain */
/**
 * @defgroup radio_rx_regs_core_tia_gain_field tia_gain_field
 * @brief macros for field tia_gain
 * @details TIA gain status
 * @{
 */
#define RADIO_RX_STATUS__TIA_GAIN__SHIFT                                     13
#define RADIO_RX_STATUS__TIA_GAIN__WIDTH                                      2
#define RADIO_RX_STATUS__TIA_GAIN__MASK                             0x00006000U
#define RADIO_RX_STATUS__TIA_GAIN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00006000U) >> 13)
#define RADIO_RX_STATUS__TIA_GAIN__RESET_VALUE                      0x00000000U
/** @} */

/* macros for field pga_gain */
/**
 * @defgroup radio_rx_regs_core_pga_gain_field pga_gain_field
 * @brief macros for field pga_gain
 * @details PGA gain status
 * @{
 */
#define RADIO_RX_STATUS__PGA_GAIN__SHIFT                                     15
#define RADIO_RX_STATUS__PGA_GAIN__WIDTH                                      5
#define RADIO_RX_STATUS__PGA_GAIN__MASK                             0x000f8000U
#define RADIO_RX_STATUS__PGA_GAIN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000f8000U) >> 15)
#define RADIO_RX_STATUS__PGA_GAIN__RESET_VALUE                      0x00000000U
/** @} */
#define RADIO_RX_STATUS__TYPE                                          uint32_t
#define RADIO_RX_STATUS__READ                                       0x000fffffU
#define RADIO_RX_STATUS__PRESERVED                                  0x00000000U
#define RADIO_RX_STATUS__RESET_VALUE                                0x00000000U

#endif /* __RADIO_RX_STATUS_MACRO__ */

/** @} end of status */

/* macros for BlueprintGlobalNameSpace::radio_rx_core_id */
/**
 * @defgroup radio_rx_regs_core_core_id core_id
 * @brief Core ID definitions.
 * @{
 */
#ifndef __RADIO_RX_CORE_ID_MACRO__
#define __RADIO_RX_CORE_ID_MACRO__

/* macros for field id */
/**
 * @defgroup radio_rx_regs_core_id_field id_field
 * @brief macros for field id
 * @details RX in ASCII
 * @{
 */
#define RADIO_RX_CORE_ID__ID__SHIFT                                           0
#define RADIO_RX_CORE_ID__ID__WIDTH                                          32
#define RADIO_RX_CORE_ID__ID__MASK                                  0xffffffffU
#define RADIO_RX_CORE_ID__ID__READ(src)         ((uint32_t)(src) & 0xffffffffU)
#define RADIO_RX_CORE_ID__ID__RESET_VALUE                           0x52582020U
/** @} */
#define RADIO_RX_CORE_ID__TYPE                                         uint32_t
#define RADIO_RX_CORE_ID__READ                                      0xffffffffU
#define RADIO_RX_CORE_ID__PRESERVED                                 0x00000000U
#define RADIO_RX_CORE_ID__RESET_VALUE                               0x52582020U

#endif /* __RADIO_RX_CORE_ID_MACRO__ */

/** @} end of core_id */

/** @} end of RADIO_RX_REGS_CORE */
#endif /* __REG_RADIO_RX_REGS_CORE_H__ */
