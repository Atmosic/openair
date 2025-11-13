/*                                                                           */
/* File:       mdm_regs_core_macro.h                                         */
/*                                                                           */
/* Arguments:  /cad/tools/cadence/blueprint_3.7.5/Linux-64bit/blueprint -eval*/
/*             $DEFINE_PROPERTY=1; -ansic mdm_regs_core.rdl                  */
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


#ifndef __REG_MDM_REGS_CORE_H__
#define __REG_MDM_REGS_CORE_H__

/**
 *****************************************************************************
 * @defgroup MDM_REGS_CORE mdm_regs_core
 * @ingroup AT_REG
 * @brief mdm_regs_core definitions.
 * @{
 *****************************************************************************
 */

/* macros for BlueprintGlobalNameSpace::MDM_agcmeas */
/**
 * @defgroup mdm_regs_core_agcmeas agcmeas
 * @brief Power measurements definitions.
 * @{
 */
#ifndef __MDM_AGCMEAS_MACRO__
#define __MDM_AGCMEAS_MACRO__

/* macros for field rssi_offset */
/**
 * @defgroup mdm_regs_core_rssi_offset_field rssi_offset_field
 * @brief macros for field rssi_offset
 * @details RSSI = rxgain - (measured_power after RXFIR) plus rssi_offset. Signed. Register replicated for 2 Mb/s
 * @{
 */
#define MDM_AGCMEAS__RSSI_OFFSET__SHIFT                                       0
#define MDM_AGCMEAS__RSSI_OFFSET__WIDTH                                       8
#define MDM_AGCMEAS__RSSI_OFFSET__MASK                              0x000000ffU
#define MDM_AGCMEAS__RSSI_OFFSET__READ(src)     ((uint32_t)(src) & 0x000000ffU)
#define MDM_AGCMEAS__RSSI_OFFSET__WRITE(src)    ((uint32_t)(src) & 0x000000ffU)
#define MDM_AGCMEAS__RSSI_OFFSET__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000ffU) | ((uint32_t)(src) &\
                    0x000000ffU)
#define MDM_AGCMEAS__RSSI_OFFSET__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000000ffU)))
#define MDM_AGCMEAS__RSSI_OFFSET__RESET_VALUE                       0x00000011U
/** @} */

/* macros for field det_min */
/**
 * @defgroup mdm_regs_core_det_min_field det_min_field
 * @brief macros for field det_min
 * @details Signed, relative to full scale agc filter output. Lowest allowed inband power measurement 7'h4d = -51. Register replicated for 2 Mb/s
 * @{
 */
#define MDM_AGCMEAS__DET_MIN__SHIFT                                           8
#define MDM_AGCMEAS__DET_MIN__WIDTH                                           7
#define MDM_AGCMEAS__DET_MIN__MASK                                  0x00007f00U
#define MDM_AGCMEAS__DET_MIN__READ(src)  (((uint32_t)(src) & 0x00007f00U) >> 8)
#define MDM_AGCMEAS__DET_MIN__WRITE(src) (((uint32_t)(src) << 8) & 0x00007f00U)
#define MDM_AGCMEAS__DET_MIN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00007f00U) | (((uint32_t)(src) <<\
                    8) & 0x00007f00U)
#define MDM_AGCMEAS__DET_MIN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00007f00U)))
#define MDM_AGCMEAS__DET_MIN__RESET_VALUE                           0x0000004dU
/** @} */

/* macros for field twomeg_rssi_offset */
/**
 * @defgroup mdm_regs_core_twomeg_rssi_offset_field twomeg_rssi_offset_field
 * @brief macros for field twomeg_rssi_offset
 * @details RSSI = rxgain - (measured_power after RXFIR) plus rssi_offset. 2 Mb/s version of register.
 * @{
 */
#define MDM_AGCMEAS__TWOMEG_RSSI_OFFSET__SHIFT                               15
#define MDM_AGCMEAS__TWOMEG_RSSI_OFFSET__WIDTH                                8
#define MDM_AGCMEAS__TWOMEG_RSSI_OFFSET__MASK                       0x007f8000U
#define MDM_AGCMEAS__TWOMEG_RSSI_OFFSET__READ(src) \
                    (((uint32_t)(src)\
                    & 0x007f8000U) >> 15)
#define MDM_AGCMEAS__TWOMEG_RSSI_OFFSET__WRITE(src) \
                    (((uint32_t)(src)\
                    << 15) & 0x007f8000U)
#define MDM_AGCMEAS__TWOMEG_RSSI_OFFSET__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x007f8000U) | (((uint32_t)(src) <<\
                    15) & 0x007f8000U)
#define MDM_AGCMEAS__TWOMEG_RSSI_OFFSET__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 15) & ~0x007f8000U)))
#define MDM_AGCMEAS__TWOMEG_RSSI_OFFSET__RESET_VALUE                0x00000011U
/** @} */

/* macros for field twomeg_det_min */
/**
 * @defgroup mdm_regs_core_twomeg_det_min_field twomeg_det_min_field
 * @brief macros for field twomeg_det_min
 * @details Signed, relative to full scale agc filter output. Lowest allowed inband power measurement 7'h50 = -48. 2 Mb/s version of this register
 * @{
 */
#define MDM_AGCMEAS__TWOMEG_DET_MIN__SHIFT                                   23
#define MDM_AGCMEAS__TWOMEG_DET_MIN__WIDTH                                    7
#define MDM_AGCMEAS__TWOMEG_DET_MIN__MASK                           0x3f800000U
#define MDM_AGCMEAS__TWOMEG_DET_MIN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x3f800000U) >> 23)
#define MDM_AGCMEAS__TWOMEG_DET_MIN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 23) & 0x3f800000U)
#define MDM_AGCMEAS__TWOMEG_DET_MIN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x3f800000U) | (((uint32_t)(src) <<\
                    23) & 0x3f800000U)
#define MDM_AGCMEAS__TWOMEG_DET_MIN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 23) & ~0x3f800000U)))
#define MDM_AGCMEAS__TWOMEG_DET_MIN__RESET_VALUE                    0x00000050U
/** @} */
#define MDM_AGCMEAS__TYPE                                              uint32_t
#define MDM_AGCMEAS__READ                                           0x3fffffffU
#define MDM_AGCMEAS__WRITE                                          0x3fffffffU
#define MDM_AGCMEAS__PRESERVED                                      0x00000000U
#define MDM_AGCMEAS__RESET_VALUE                                    0x2808cd11U

#endif /* __MDM_AGCMEAS_MACRO__ */

/** @} end of agcmeas */

/* macros for BlueprintGlobalNameSpace::MDM_agcgain */
/**
 * @defgroup mdm_regs_core_agcgain agcgain
 * @brief Gain settings definitions.
 * @{
 */
#ifndef __MDM_AGCGAIN_MACRO__
#define __MDM_AGCGAIN_MACRO__

/* macros for field start */
/**
 * @defgroup mdm_regs_core_start_field start_field
 * @brief macros for field start
 * @details RX gain to use at start of packet search
 * @{
 */
#define MDM_AGCGAIN__START__SHIFT                                             0
#define MDM_AGCGAIN__START__WIDTH                                             7
#define MDM_AGCGAIN__START__MASK                                    0x0000007fU
#define MDM_AGCGAIN__START__READ(src)           ((uint32_t)(src) & 0x0000007fU)
#define MDM_AGCGAIN__START__WRITE(src)          ((uint32_t)(src) & 0x0000007fU)
#define MDM_AGCGAIN__START__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000007fU) | ((uint32_t)(src) &\
                    0x0000007fU)
#define MDM_AGCGAIN__START__VERIFY(src)   (!(((uint32_t)(src) & ~0x0000007fU)))
#define MDM_AGCGAIN__START__RESET_VALUE                             0x0000004cU
/** @} */

/* macros for field rfin_pd_quick_drop */
/**
 * @defgroup mdm_regs_core_rfin_pd_quick_drop_field rfin_pd_quick_drop_field
 * @brief macros for field rfin_pd_quick_drop
 * @details Gain drop in dB when rfin peak detect indicated
 * @{
 */
#define MDM_AGCGAIN__RFIN_PD_QUICK_DROP__SHIFT                               14
#define MDM_AGCGAIN__RFIN_PD_QUICK_DROP__WIDTH                                7
#define MDM_AGCGAIN__RFIN_PD_QUICK_DROP__MASK                       0x001fc000U
#define MDM_AGCGAIN__RFIN_PD_QUICK_DROP__READ(src) \
                    (((uint32_t)(src)\
                    & 0x001fc000U) >> 14)
#define MDM_AGCGAIN__RFIN_PD_QUICK_DROP__WRITE(src) \
                    (((uint32_t)(src)\
                    << 14) & 0x001fc000U)
#define MDM_AGCGAIN__RFIN_PD_QUICK_DROP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x001fc000U) | (((uint32_t)(src) <<\
                    14) & 0x001fc000U)
#define MDM_AGCGAIN__RFIN_PD_QUICK_DROP__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 14) & ~0x001fc000U)))
#define MDM_AGCGAIN__RFIN_PD_QUICK_DROP__RESET_VALUE                0x00000045U
/** @} */

/* macros for field tia_quick_drop */
/**
 * @defgroup mdm_regs_core_tia_quick_drop_field tia_quick_drop_field
 * @brief macros for field tia_quick_drop
 * @details Gain drop in dB when peak detect indicated
 * @{
 */
#define MDM_AGCGAIN__TIA_QUICK_DROP__SHIFT                                   21
#define MDM_AGCGAIN__TIA_QUICK_DROP__WIDTH                                    7
#define MDM_AGCGAIN__TIA_QUICK_DROP__MASK                           0x0fe00000U
#define MDM_AGCGAIN__TIA_QUICK_DROP__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0fe00000U) >> 21)
#define MDM_AGCGAIN__TIA_QUICK_DROP__WRITE(src) \
                    (((uint32_t)(src)\
                    << 21) & 0x0fe00000U)
#define MDM_AGCGAIN__TIA_QUICK_DROP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0fe00000U) | (((uint32_t)(src) <<\
                    21) & 0x0fe00000U)
#define MDM_AGCGAIN__TIA_QUICK_DROP__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 21) & ~0x0fe00000U)))
#define MDM_AGCGAIN__TIA_QUICK_DROP__RESET_VALUE                    0x00000036U
/** @} */
#define MDM_AGCGAIN__TYPE                                              uint32_t
#define MDM_AGCGAIN__READ                                           0x0fffc07fU
#define MDM_AGCGAIN__WRITE                                          0x0fffc07fU
#define MDM_AGCGAIN__PRESERVED                                      0x00000000U
#define MDM_AGCGAIN__RESET_VALUE                                    0x06d1404cU

#endif /* __MDM_AGCGAIN_MACRO__ */

/** @} end of agcgain */

/* macros for BlueprintGlobalNameSpace::MDM_dcoff */
/**
 * @defgroup mdm_regs_core_dcoff dcoff
 * @brief DC Offset forcing definitions.
 * @{
 */
#ifndef __MDM_DCOFF_MACRO__
#define __MDM_DCOFF_MACRO__

/* macros for field force */
/**
 * @defgroup mdm_regs_core_force_field force_field
 * @brief macros for field force
 * @details If set, modem will subtract the forced_i and forced_q values after the ADC.
 * @{
 */
#define MDM_DCOFF__FORCE__SHIFT                                               0
#define MDM_DCOFF__FORCE__WIDTH                                               1
#define MDM_DCOFF__FORCE__MASK                                      0x00000001U
#define MDM_DCOFF__FORCE__READ(src)             ((uint32_t)(src) & 0x00000001U)
#define MDM_DCOFF__FORCE__WRITE(src)            ((uint32_t)(src) & 0x00000001U)
#define MDM_DCOFF__FORCE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define MDM_DCOFF__FORCE__VERIFY(src)     (!(((uint32_t)(src) & ~0x00000001U)))
#define MDM_DCOFF__FORCE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define MDM_DCOFF__FORCE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define MDM_DCOFF__FORCE__RESET_VALUE                               0x00000001U
/** @} */

/* macros for field forced_i */
/**
 * @defgroup mdm_regs_core_forced_i_field forced_i_field
 * @brief macros for field forced_i
 * @details Signed, in units of ADC LSBs
 * @{
 */
#define MDM_DCOFF__FORCED_I__SHIFT                                            1
#define MDM_DCOFF__FORCED_I__WIDTH                                            8
#define MDM_DCOFF__FORCED_I__MASK                                   0x000001feU
#define MDM_DCOFF__FORCED_I__READ(src)   (((uint32_t)(src) & 0x000001feU) >> 1)
#define MDM_DCOFF__FORCED_I__WRITE(src)  (((uint32_t)(src) << 1) & 0x000001feU)
#define MDM_DCOFF__FORCED_I__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000001feU) | (((uint32_t)(src) <<\
                    1) & 0x000001feU)
#define MDM_DCOFF__FORCED_I__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x000001feU)))
#define MDM_DCOFF__FORCED_I__RESET_VALUE                            0x00000000U
/** @} */

/* macros for field forced_q */
/**
 * @defgroup mdm_regs_core_forced_q_field forced_q_field
 * @brief macros for field forced_q
 * @details Signed, in units of ADC LSBs
 * @{
 */
#define MDM_DCOFF__FORCED_Q__SHIFT                                            9
#define MDM_DCOFF__FORCED_Q__WIDTH                                            8
#define MDM_DCOFF__FORCED_Q__MASK                                   0x0001fe00U
#define MDM_DCOFF__FORCED_Q__READ(src)   (((uint32_t)(src) & 0x0001fe00U) >> 9)
#define MDM_DCOFF__FORCED_Q__WRITE(src)  (((uint32_t)(src) << 9) & 0x0001fe00U)
#define MDM_DCOFF__FORCED_Q__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0001fe00U) | (((uint32_t)(src) <<\
                    9) & 0x0001fe00U)
#define MDM_DCOFF__FORCED_Q__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x0001fe00U)))
#define MDM_DCOFF__FORCED_Q__RESET_VALUE                            0x00000000U
/** @} */
#define MDM_DCOFF__TYPE                                                uint32_t
#define MDM_DCOFF__READ                                             0x0001ffffU
#define MDM_DCOFF__WRITE                                            0x0001ffffU
#define MDM_DCOFF__PRESERVED                                        0x00000000U
#define MDM_DCOFF__RESET_VALUE                                      0x00000001U

#endif /* __MDM_DCOFF_MACRO__ */

/** @} end of dcoff */

/* macros for BlueprintGlobalNameSpace::MDM_tia_force_dccalresults */
/**
 * @defgroup mdm_regs_core_tia_force_dccalresults tia_force_dccalresults
 * @brief Force DC offset calibration results for TIA for paris definitions.
 * @{
 */
#ifndef __MDM_TIA_FORCE_DCCALRESULTS_MACRO__
#define __MDM_TIA_FORCE_DCCALRESULTS_MACRO__

/* macros for field q_off */
/**
 * @defgroup mdm_regs_core_q_off_field q_off_field
 * @brief macros for field q_off
 * @details forced TIA Q offset
 * @{
 */
#define MDM_TIA_FORCE_DCCALRESULTS__Q_OFF__SHIFT                              0
#define MDM_TIA_FORCE_DCCALRESULTS__Q_OFF__WIDTH                              8
#define MDM_TIA_FORCE_DCCALRESULTS__Q_OFF__MASK                     0x000000ffU
#define MDM_TIA_FORCE_DCCALRESULTS__Q_OFF__READ(src) \
                    ((uint32_t)(src)\
                    & 0x000000ffU)
#define MDM_TIA_FORCE_DCCALRESULTS__Q_OFF__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x000000ffU)
#define MDM_TIA_FORCE_DCCALRESULTS__Q_OFF__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000ffU) | ((uint32_t)(src) &\
                    0x000000ffU)
#define MDM_TIA_FORCE_DCCALRESULTS__Q_OFF__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000000ffU)))
#define MDM_TIA_FORCE_DCCALRESULTS__Q_OFF__RESET_VALUE              0x00000000U
/** @} */

/* macros for field i_off */
/**
 * @defgroup mdm_regs_core_i_off_field i_off_field
 * @brief macros for field i_off
 * @details forced TIA I offset
 * @{
 */
#define MDM_TIA_FORCE_DCCALRESULTS__I_OFF__SHIFT                              8
#define MDM_TIA_FORCE_DCCALRESULTS__I_OFF__WIDTH                              8
#define MDM_TIA_FORCE_DCCALRESULTS__I_OFF__MASK                     0x0000ff00U
#define MDM_TIA_FORCE_DCCALRESULTS__I_OFF__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000ff00U) >> 8)
#define MDM_TIA_FORCE_DCCALRESULTS__I_OFF__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x0000ff00U)
#define MDM_TIA_FORCE_DCCALRESULTS__I_OFF__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000ff00U) | (((uint32_t)(src) <<\
                    8) & 0x0000ff00U)
#define MDM_TIA_FORCE_DCCALRESULTS__I_OFF__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x0000ff00U)))
#define MDM_TIA_FORCE_DCCALRESULTS__I_OFF__RESET_VALUE              0x00000000U
/** @} */

/* macros for field bb2gain */
/**
 * @defgroup mdm_regs_core_bb2gain_field bb2gain_field
 * @brief macros for field bb2gain
 * @details bb2gain value used in TIA cal
 * @{
 */
#define MDM_TIA_FORCE_DCCALRESULTS__BB2GAIN__SHIFT                           16
#define MDM_TIA_FORCE_DCCALRESULTS__BB2GAIN__WIDTH                            5
#define MDM_TIA_FORCE_DCCALRESULTS__BB2GAIN__MASK                   0x001f0000U
#define MDM_TIA_FORCE_DCCALRESULTS__BB2GAIN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x001f0000U) >> 16)
#define MDM_TIA_FORCE_DCCALRESULTS__BB2GAIN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x001f0000U)
#define MDM_TIA_FORCE_DCCALRESULTS__BB2GAIN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x001f0000U) | (((uint32_t)(src) <<\
                    16) & 0x001f0000U)
#define MDM_TIA_FORCE_DCCALRESULTS__BB2GAIN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x001f0000U)))
#define MDM_TIA_FORCE_DCCALRESULTS__BB2GAIN__RESET_VALUE            0x00000000U
/** @} */

/* macros for field force */
/**
 * @defgroup mdm_regs_core_force_field force_field
 * @brief macros for field force
 * @details force to use offset in this register
 * @{
 */
#define MDM_TIA_FORCE_DCCALRESULTS__FORCE__SHIFT                             31
#define MDM_TIA_FORCE_DCCALRESULTS__FORCE__WIDTH                              1
#define MDM_TIA_FORCE_DCCALRESULTS__FORCE__MASK                     0x80000000U
#define MDM_TIA_FORCE_DCCALRESULTS__FORCE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x80000000U) >> 31)
#define MDM_TIA_FORCE_DCCALRESULTS__FORCE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 31) & 0x80000000U)
#define MDM_TIA_FORCE_DCCALRESULTS__FORCE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | (((uint32_t)(src) <<\
                    31) & 0x80000000U)
#define MDM_TIA_FORCE_DCCALRESULTS__FORCE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 31) & ~0x80000000U)))
#define MDM_TIA_FORCE_DCCALRESULTS__FORCE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(1) << 31)
#define MDM_TIA_FORCE_DCCALRESULTS__FORCE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(0) << 31)
#define MDM_TIA_FORCE_DCCALRESULTS__FORCE__RESET_VALUE              0x00000000U
/** @} */
#define MDM_TIA_FORCE_DCCALRESULTS__TYPE                               uint32_t
#define MDM_TIA_FORCE_DCCALRESULTS__READ                            0x801fffffU
#define MDM_TIA_FORCE_DCCALRESULTS__WRITE                           0x801fffffU
#define MDM_TIA_FORCE_DCCALRESULTS__PRESERVED                       0x00000000U
#define MDM_TIA_FORCE_DCCALRESULTS__RESET_VALUE                     0x00000000U

#endif /* __MDM_TIA_FORCE_DCCALRESULTS_MACRO__ */

/** @} end of tia_force_dccalresults */

/* macros for BlueprintGlobalNameSpace::MDM_tia_force_dccalresults2 */
/**
 * @defgroup mdm_regs_core_tia_force_dccalresults2 tia_force_dccalresults2
 * @brief Force DC offset calibration results for TIA for paris definitions.
 * @{
 */
#ifndef __MDM_TIA_FORCE_DCCALRESULTS2_MACRO__
#define __MDM_TIA_FORCE_DCCALRESULTS2_MACRO__

/* macros for field avg_q */
/**
 * @defgroup mdm_regs_core_avg_q_field avg_q_field
 * @brief macros for field avg_q
 * @details calculated average of ADC Q samples
 * @{
 */
#define MDM_TIA_FORCE_DCCALRESULTS2__AVG_Q__SHIFT                             0
#define MDM_TIA_FORCE_DCCALRESULTS2__AVG_Q__WIDTH                             8
#define MDM_TIA_FORCE_DCCALRESULTS2__AVG_Q__MASK                    0x000000ffU
#define MDM_TIA_FORCE_DCCALRESULTS2__AVG_Q__READ(src) \
                    ((uint32_t)(src)\
                    & 0x000000ffU)
#define MDM_TIA_FORCE_DCCALRESULTS2__AVG_Q__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x000000ffU)
#define MDM_TIA_FORCE_DCCALRESULTS2__AVG_Q__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000ffU) | ((uint32_t)(src) &\
                    0x000000ffU)
#define MDM_TIA_FORCE_DCCALRESULTS2__AVG_Q__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000000ffU)))
#define MDM_TIA_FORCE_DCCALRESULTS2__AVG_Q__RESET_VALUE             0x00000000U
/** @} */

/* macros for field avg_i */
/**
 * @defgroup mdm_regs_core_avg_i_field avg_i_field
 * @brief macros for field avg_i
 * @details calculated average of ADC I samples
 * @{
 */
#define MDM_TIA_FORCE_DCCALRESULTS2__AVG_I__SHIFT                             8
#define MDM_TIA_FORCE_DCCALRESULTS2__AVG_I__WIDTH                             8
#define MDM_TIA_FORCE_DCCALRESULTS2__AVG_I__MASK                    0x0000ff00U
#define MDM_TIA_FORCE_DCCALRESULTS2__AVG_I__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000ff00U) >> 8)
#define MDM_TIA_FORCE_DCCALRESULTS2__AVG_I__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x0000ff00U)
#define MDM_TIA_FORCE_DCCALRESULTS2__AVG_I__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000ff00U) | (((uint32_t)(src) <<\
                    8) & 0x0000ff00U)
#define MDM_TIA_FORCE_DCCALRESULTS2__AVG_I__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x0000ff00U)))
#define MDM_TIA_FORCE_DCCALRESULTS2__AVG_I__RESET_VALUE             0x00000000U
/** @} */

/* macros for field force */
/**
 * @defgroup mdm_regs_core_force_field force_field
 * @brief macros for field force
 * @details force to use average in this register
 * @{
 */
#define MDM_TIA_FORCE_DCCALRESULTS2__FORCE__SHIFT                            31
#define MDM_TIA_FORCE_DCCALRESULTS2__FORCE__WIDTH                             1
#define MDM_TIA_FORCE_DCCALRESULTS2__FORCE__MASK                    0x80000000U
#define MDM_TIA_FORCE_DCCALRESULTS2__FORCE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x80000000U) >> 31)
#define MDM_TIA_FORCE_DCCALRESULTS2__FORCE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 31) & 0x80000000U)
#define MDM_TIA_FORCE_DCCALRESULTS2__FORCE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | (((uint32_t)(src) <<\
                    31) & 0x80000000U)
#define MDM_TIA_FORCE_DCCALRESULTS2__FORCE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 31) & ~0x80000000U)))
#define MDM_TIA_FORCE_DCCALRESULTS2__FORCE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(1) << 31)
#define MDM_TIA_FORCE_DCCALRESULTS2__FORCE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(0) << 31)
#define MDM_TIA_FORCE_DCCALRESULTS2__FORCE__RESET_VALUE             0x00000000U
/** @} */
#define MDM_TIA_FORCE_DCCALRESULTS2__TYPE                              uint32_t
#define MDM_TIA_FORCE_DCCALRESULTS2__READ                           0x8000ffffU
#define MDM_TIA_FORCE_DCCALRESULTS2__WRITE                          0x8000ffffU
#define MDM_TIA_FORCE_DCCALRESULTS2__PRESERVED                      0x00000000U
#define MDM_TIA_FORCE_DCCALRESULTS2__RESET_VALUE                    0x00000000U

#endif /* __MDM_TIA_FORCE_DCCALRESULTS2_MACRO__ */

/** @} end of tia_force_dccalresults2 */

/* macros for BlueprintGlobalNameSpace::MDM_tia_lp_force_dccalresults */
/**
 * @defgroup mdm_regs_core_tia_lp_force_dccalresults tia_lp_force_dccalresults
 * @brief Force DC offset calibration results for TIA for low power mode for paris definitions.
 * @{
 */
#ifndef __MDM_TIA_LP_FORCE_DCCALRESULTS_MACRO__
#define __MDM_TIA_LP_FORCE_DCCALRESULTS_MACRO__

/* macros for field q_off */
/**
 * @defgroup mdm_regs_core_q_off_field q_off_field
 * @brief macros for field q_off
 * @details forced TIA Q offset
 * @{
 */
#define MDM_TIA_LP_FORCE_DCCALRESULTS__Q_OFF__SHIFT                           0
#define MDM_TIA_LP_FORCE_DCCALRESULTS__Q_OFF__WIDTH                           8
#define MDM_TIA_LP_FORCE_DCCALRESULTS__Q_OFF__MASK                  0x000000ffU
#define MDM_TIA_LP_FORCE_DCCALRESULTS__Q_OFF__READ(src) \
                    ((uint32_t)(src)\
                    & 0x000000ffU)
#define MDM_TIA_LP_FORCE_DCCALRESULTS__Q_OFF__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x000000ffU)
#define MDM_TIA_LP_FORCE_DCCALRESULTS__Q_OFF__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000ffU) | ((uint32_t)(src) &\
                    0x000000ffU)
#define MDM_TIA_LP_FORCE_DCCALRESULTS__Q_OFF__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000000ffU)))
#define MDM_TIA_LP_FORCE_DCCALRESULTS__Q_OFF__RESET_VALUE           0x00000000U
/** @} */

/* macros for field i_off */
/**
 * @defgroup mdm_regs_core_i_off_field i_off_field
 * @brief macros for field i_off
 * @details forced TIA I offset
 * @{
 */
#define MDM_TIA_LP_FORCE_DCCALRESULTS__I_OFF__SHIFT                           8
#define MDM_TIA_LP_FORCE_DCCALRESULTS__I_OFF__WIDTH                           8
#define MDM_TIA_LP_FORCE_DCCALRESULTS__I_OFF__MASK                  0x0000ff00U
#define MDM_TIA_LP_FORCE_DCCALRESULTS__I_OFF__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000ff00U) >> 8)
#define MDM_TIA_LP_FORCE_DCCALRESULTS__I_OFF__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x0000ff00U)
#define MDM_TIA_LP_FORCE_DCCALRESULTS__I_OFF__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000ff00U) | (((uint32_t)(src) <<\
                    8) & 0x0000ff00U)
#define MDM_TIA_LP_FORCE_DCCALRESULTS__I_OFF__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x0000ff00U)))
#define MDM_TIA_LP_FORCE_DCCALRESULTS__I_OFF__RESET_VALUE           0x00000000U
/** @} */

/* macros for field bb2gain */
/**
 * @defgroup mdm_regs_core_bb2gain_field bb2gain_field
 * @brief macros for field bb2gain
 * @details bb2gain value used in TIA cal
 * @{
 */
#define MDM_TIA_LP_FORCE_DCCALRESULTS__BB2GAIN__SHIFT                        16
#define MDM_TIA_LP_FORCE_DCCALRESULTS__BB2GAIN__WIDTH                         5
#define MDM_TIA_LP_FORCE_DCCALRESULTS__BB2GAIN__MASK                0x001f0000U
#define MDM_TIA_LP_FORCE_DCCALRESULTS__BB2GAIN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x001f0000U) >> 16)
#define MDM_TIA_LP_FORCE_DCCALRESULTS__BB2GAIN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x001f0000U)
#define MDM_TIA_LP_FORCE_DCCALRESULTS__BB2GAIN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x001f0000U) | (((uint32_t)(src) <<\
                    16) & 0x001f0000U)
#define MDM_TIA_LP_FORCE_DCCALRESULTS__BB2GAIN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x001f0000U)))
#define MDM_TIA_LP_FORCE_DCCALRESULTS__BB2GAIN__RESET_VALUE         0x00000000U
/** @} */

/* macros for field force */
/**
 * @defgroup mdm_regs_core_force_field force_field
 * @brief macros for field force
 * @details force to use offset in this register
 * @{
 */
#define MDM_TIA_LP_FORCE_DCCALRESULTS__FORCE__SHIFT                          31
#define MDM_TIA_LP_FORCE_DCCALRESULTS__FORCE__WIDTH                           1
#define MDM_TIA_LP_FORCE_DCCALRESULTS__FORCE__MASK                  0x80000000U
#define MDM_TIA_LP_FORCE_DCCALRESULTS__FORCE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x80000000U) >> 31)
#define MDM_TIA_LP_FORCE_DCCALRESULTS__FORCE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 31) & 0x80000000U)
#define MDM_TIA_LP_FORCE_DCCALRESULTS__FORCE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | (((uint32_t)(src) <<\
                    31) & 0x80000000U)
#define MDM_TIA_LP_FORCE_DCCALRESULTS__FORCE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 31) & ~0x80000000U)))
#define MDM_TIA_LP_FORCE_DCCALRESULTS__FORCE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(1) << 31)
#define MDM_TIA_LP_FORCE_DCCALRESULTS__FORCE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(0) << 31)
#define MDM_TIA_LP_FORCE_DCCALRESULTS__FORCE__RESET_VALUE           0x00000000U
/** @} */
#define MDM_TIA_LP_FORCE_DCCALRESULTS__TYPE                            uint32_t
#define MDM_TIA_LP_FORCE_DCCALRESULTS__READ                         0x801fffffU
#define MDM_TIA_LP_FORCE_DCCALRESULTS__WRITE                        0x801fffffU
#define MDM_TIA_LP_FORCE_DCCALRESULTS__PRESERVED                    0x00000000U
#define MDM_TIA_LP_FORCE_DCCALRESULTS__RESET_VALUE                  0x00000000U

#endif /* __MDM_TIA_LP_FORCE_DCCALRESULTS_MACRO__ */

/** @} end of tia_lp_force_dccalresults */

/* macros for BlueprintGlobalNameSpace::MDM_tia_lp_force_dccalresults2 */
/**
 * @defgroup mdm_regs_core_tia_lp_force_dccalresults2 tia_lp_force_dccalresults2
 * @brief Force DC offset calibration results for TIA for low power mode for paris definitions.
 * @{
 */
#ifndef __MDM_TIA_LP_FORCE_DCCALRESULTS2_MACRO__
#define __MDM_TIA_LP_FORCE_DCCALRESULTS2_MACRO__

/* macros for field avg_q */
/**
 * @defgroup mdm_regs_core_avg_q_field avg_q_field
 * @brief macros for field avg_q
 * @details calculated average of ADC Q samples
 * @{
 */
#define MDM_TIA_LP_FORCE_DCCALRESULTS2__AVG_Q__SHIFT                          0
#define MDM_TIA_LP_FORCE_DCCALRESULTS2__AVG_Q__WIDTH                          8
#define MDM_TIA_LP_FORCE_DCCALRESULTS2__AVG_Q__MASK                 0x000000ffU
#define MDM_TIA_LP_FORCE_DCCALRESULTS2__AVG_Q__READ(src) \
                    ((uint32_t)(src)\
                    & 0x000000ffU)
#define MDM_TIA_LP_FORCE_DCCALRESULTS2__AVG_Q__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x000000ffU)
#define MDM_TIA_LP_FORCE_DCCALRESULTS2__AVG_Q__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000ffU) | ((uint32_t)(src) &\
                    0x000000ffU)
#define MDM_TIA_LP_FORCE_DCCALRESULTS2__AVG_Q__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000000ffU)))
#define MDM_TIA_LP_FORCE_DCCALRESULTS2__AVG_Q__RESET_VALUE          0x00000000U
/** @} */

/* macros for field avg_i */
/**
 * @defgroup mdm_regs_core_avg_i_field avg_i_field
 * @brief macros for field avg_i
 * @details calculated average of ADC I samples
 * @{
 */
#define MDM_TIA_LP_FORCE_DCCALRESULTS2__AVG_I__SHIFT                          8
#define MDM_TIA_LP_FORCE_DCCALRESULTS2__AVG_I__WIDTH                          8
#define MDM_TIA_LP_FORCE_DCCALRESULTS2__AVG_I__MASK                 0x0000ff00U
#define MDM_TIA_LP_FORCE_DCCALRESULTS2__AVG_I__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000ff00U) >> 8)
#define MDM_TIA_LP_FORCE_DCCALRESULTS2__AVG_I__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x0000ff00U)
#define MDM_TIA_LP_FORCE_DCCALRESULTS2__AVG_I__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000ff00U) | (((uint32_t)(src) <<\
                    8) & 0x0000ff00U)
#define MDM_TIA_LP_FORCE_DCCALRESULTS2__AVG_I__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x0000ff00U)))
#define MDM_TIA_LP_FORCE_DCCALRESULTS2__AVG_I__RESET_VALUE          0x00000000U
/** @} */

/* macros for field force */
/**
 * @defgroup mdm_regs_core_force_field force_field
 * @brief macros for field force
 * @details force to use average in this register
 * @{
 */
#define MDM_TIA_LP_FORCE_DCCALRESULTS2__FORCE__SHIFT                         31
#define MDM_TIA_LP_FORCE_DCCALRESULTS2__FORCE__WIDTH                          1
#define MDM_TIA_LP_FORCE_DCCALRESULTS2__FORCE__MASK                 0x80000000U
#define MDM_TIA_LP_FORCE_DCCALRESULTS2__FORCE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x80000000U) >> 31)
#define MDM_TIA_LP_FORCE_DCCALRESULTS2__FORCE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 31) & 0x80000000U)
#define MDM_TIA_LP_FORCE_DCCALRESULTS2__FORCE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | (((uint32_t)(src) <<\
                    31) & 0x80000000U)
#define MDM_TIA_LP_FORCE_DCCALRESULTS2__FORCE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 31) & ~0x80000000U)))
#define MDM_TIA_LP_FORCE_DCCALRESULTS2__FORCE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(1) << 31)
#define MDM_TIA_LP_FORCE_DCCALRESULTS2__FORCE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(0) << 31)
#define MDM_TIA_LP_FORCE_DCCALRESULTS2__FORCE__RESET_VALUE          0x00000000U
/** @} */
#define MDM_TIA_LP_FORCE_DCCALRESULTS2__TYPE                           uint32_t
#define MDM_TIA_LP_FORCE_DCCALRESULTS2__READ                        0x8000ffffU
#define MDM_TIA_LP_FORCE_DCCALRESULTS2__WRITE                       0x8000ffffU
#define MDM_TIA_LP_FORCE_DCCALRESULTS2__PRESERVED                   0x00000000U
#define MDM_TIA_LP_FORCE_DCCALRESULTS2__RESET_VALUE                 0x00000000U

#endif /* __MDM_TIA_LP_FORCE_DCCALRESULTS2_MACRO__ */

/** @} end of tia_lp_force_dccalresults2 */

/* macros for BlueprintGlobalNameSpace::MDM_pga_force_dccalresults */
/**
 * @defgroup mdm_regs_core_pga_force_dccalresults pga_force_dccalresults
 * @brief Force DC offset calibration results for PGA for paris definitions.
 * @{
 */
#ifndef __MDM_PGA_FORCE_DCCALRESULTS_MACRO__
#define __MDM_PGA_FORCE_DCCALRESULTS_MACRO__

/* macros for field q_off */
/**
 * @defgroup mdm_regs_core_q_off_field q_off_field
 * @brief macros for field q_off
 * @details forced PGA Q offset
 * @{
 */
#define MDM_PGA_FORCE_DCCALRESULTS__Q_OFF__SHIFT                              0
#define MDM_PGA_FORCE_DCCALRESULTS__Q_OFF__WIDTH                              5
#define MDM_PGA_FORCE_DCCALRESULTS__Q_OFF__MASK                     0x0000001fU
#define MDM_PGA_FORCE_DCCALRESULTS__Q_OFF__READ(src) \
                    ((uint32_t)(src)\
                    & 0x0000001fU)
#define MDM_PGA_FORCE_DCCALRESULTS__Q_OFF__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000001fU)
#define MDM_PGA_FORCE_DCCALRESULTS__Q_OFF__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000001fU) | ((uint32_t)(src) &\
                    0x0000001fU)
#define MDM_PGA_FORCE_DCCALRESULTS__Q_OFF__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000001fU)))
#define MDM_PGA_FORCE_DCCALRESULTS__Q_OFF__RESET_VALUE              0x00000000U
/** @} */

/* macros for field i_off */
/**
 * @defgroup mdm_regs_core_i_off_field i_off_field
 * @brief macros for field i_off
 * @details forced PGA I offset
 * @{
 */
#define MDM_PGA_FORCE_DCCALRESULTS__I_OFF__SHIFT                              8
#define MDM_PGA_FORCE_DCCALRESULTS__I_OFF__WIDTH                              5
#define MDM_PGA_FORCE_DCCALRESULTS__I_OFF__MASK                     0x00001f00U
#define MDM_PGA_FORCE_DCCALRESULTS__I_OFF__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00001f00U) >> 8)
#define MDM_PGA_FORCE_DCCALRESULTS__I_OFF__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00001f00U)
#define MDM_PGA_FORCE_DCCALRESULTS__I_OFF__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00001f00U) | (((uint32_t)(src) <<\
                    8) & 0x00001f00U)
#define MDM_PGA_FORCE_DCCALRESULTS__I_OFF__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00001f00U)))
#define MDM_PGA_FORCE_DCCALRESULTS__I_OFF__RESET_VALUE              0x00000000U
/** @} */

/* macros for field bb2gain */
/**
 * @defgroup mdm_regs_core_bb2gain_field bb2gain_field
 * @brief macros for field bb2gain
 * @details bb2gain value used in PGA cal
 * @{
 */
#define MDM_PGA_FORCE_DCCALRESULTS__BB2GAIN__SHIFT                           16
#define MDM_PGA_FORCE_DCCALRESULTS__BB2GAIN__WIDTH                            5
#define MDM_PGA_FORCE_DCCALRESULTS__BB2GAIN__MASK                   0x001f0000U
#define MDM_PGA_FORCE_DCCALRESULTS__BB2GAIN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x001f0000U) >> 16)
#define MDM_PGA_FORCE_DCCALRESULTS__BB2GAIN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x001f0000U)
#define MDM_PGA_FORCE_DCCALRESULTS__BB2GAIN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x001f0000U) | (((uint32_t)(src) <<\
                    16) & 0x001f0000U)
#define MDM_PGA_FORCE_DCCALRESULTS__BB2GAIN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x001f0000U)))
#define MDM_PGA_FORCE_DCCALRESULTS__BB2GAIN__RESET_VALUE            0x00000000U
/** @} */

/* macros for field force */
/**
 * @defgroup mdm_regs_core_force_field force_field
 * @brief macros for field force
 * @details force to use offset in this register
 * @{
 */
#define MDM_PGA_FORCE_DCCALRESULTS__FORCE__SHIFT                             31
#define MDM_PGA_FORCE_DCCALRESULTS__FORCE__WIDTH                              1
#define MDM_PGA_FORCE_DCCALRESULTS__FORCE__MASK                     0x80000000U
#define MDM_PGA_FORCE_DCCALRESULTS__FORCE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x80000000U) >> 31)
#define MDM_PGA_FORCE_DCCALRESULTS__FORCE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 31) & 0x80000000U)
#define MDM_PGA_FORCE_DCCALRESULTS__FORCE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | (((uint32_t)(src) <<\
                    31) & 0x80000000U)
#define MDM_PGA_FORCE_DCCALRESULTS__FORCE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 31) & ~0x80000000U)))
#define MDM_PGA_FORCE_DCCALRESULTS__FORCE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(1) << 31)
#define MDM_PGA_FORCE_DCCALRESULTS__FORCE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(0) << 31)
#define MDM_PGA_FORCE_DCCALRESULTS__FORCE__RESET_VALUE              0x00000000U
/** @} */
#define MDM_PGA_FORCE_DCCALRESULTS__TYPE                               uint32_t
#define MDM_PGA_FORCE_DCCALRESULTS__READ                            0x801f1f1fU
#define MDM_PGA_FORCE_DCCALRESULTS__WRITE                           0x801f1f1fU
#define MDM_PGA_FORCE_DCCALRESULTS__PRESERVED                       0x00000000U
#define MDM_PGA_FORCE_DCCALRESULTS__RESET_VALUE                     0x00000000U

#endif /* __MDM_PGA_FORCE_DCCALRESULTS_MACRO__ */

/** @} end of pga_force_dccalresults */

/* macros for BlueprintGlobalNameSpace::MDM_pga_force_dccalresults2 */
/**
 * @defgroup mdm_regs_core_pga_force_dccalresults2 pga_force_dccalresults2
 * @brief Force DC offset calibration results for PGA for paris definitions.
 * @{
 */
#ifndef __MDM_PGA_FORCE_DCCALRESULTS2_MACRO__
#define __MDM_PGA_FORCE_DCCALRESULTS2_MACRO__

/* macros for field avg_q */
/**
 * @defgroup mdm_regs_core_avg_q_field avg_q_field
 * @brief macros for field avg_q
 * @details calculated average of ADC Q samples
 * @{
 */
#define MDM_PGA_FORCE_DCCALRESULTS2__AVG_Q__SHIFT                             0
#define MDM_PGA_FORCE_DCCALRESULTS2__AVG_Q__WIDTH                             8
#define MDM_PGA_FORCE_DCCALRESULTS2__AVG_Q__MASK                    0x000000ffU
#define MDM_PGA_FORCE_DCCALRESULTS2__AVG_Q__READ(src) \
                    ((uint32_t)(src)\
                    & 0x000000ffU)
#define MDM_PGA_FORCE_DCCALRESULTS2__AVG_Q__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x000000ffU)
#define MDM_PGA_FORCE_DCCALRESULTS2__AVG_Q__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000ffU) | ((uint32_t)(src) &\
                    0x000000ffU)
#define MDM_PGA_FORCE_DCCALRESULTS2__AVG_Q__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000000ffU)))
#define MDM_PGA_FORCE_DCCALRESULTS2__AVG_Q__RESET_VALUE             0x00000000U
/** @} */

/* macros for field avg_i */
/**
 * @defgroup mdm_regs_core_avg_i_field avg_i_field
 * @brief macros for field avg_i
 * @details calculated average of ADC I samples
 * @{
 */
#define MDM_PGA_FORCE_DCCALRESULTS2__AVG_I__SHIFT                             8
#define MDM_PGA_FORCE_DCCALRESULTS2__AVG_I__WIDTH                             8
#define MDM_PGA_FORCE_DCCALRESULTS2__AVG_I__MASK                    0x0000ff00U
#define MDM_PGA_FORCE_DCCALRESULTS2__AVG_I__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000ff00U) >> 8)
#define MDM_PGA_FORCE_DCCALRESULTS2__AVG_I__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x0000ff00U)
#define MDM_PGA_FORCE_DCCALRESULTS2__AVG_I__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000ff00U) | (((uint32_t)(src) <<\
                    8) & 0x0000ff00U)
#define MDM_PGA_FORCE_DCCALRESULTS2__AVG_I__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x0000ff00U)))
#define MDM_PGA_FORCE_DCCALRESULTS2__AVG_I__RESET_VALUE             0x00000000U
/** @} */

/* macros for field force */
/**
 * @defgroup mdm_regs_core_force_field force_field
 * @brief macros for field force
 * @details force to use average in this register
 * @{
 */
#define MDM_PGA_FORCE_DCCALRESULTS2__FORCE__SHIFT                            31
#define MDM_PGA_FORCE_DCCALRESULTS2__FORCE__WIDTH                             1
#define MDM_PGA_FORCE_DCCALRESULTS2__FORCE__MASK                    0x80000000U
#define MDM_PGA_FORCE_DCCALRESULTS2__FORCE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x80000000U) >> 31)
#define MDM_PGA_FORCE_DCCALRESULTS2__FORCE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 31) & 0x80000000U)
#define MDM_PGA_FORCE_DCCALRESULTS2__FORCE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | (((uint32_t)(src) <<\
                    31) & 0x80000000U)
#define MDM_PGA_FORCE_DCCALRESULTS2__FORCE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 31) & ~0x80000000U)))
#define MDM_PGA_FORCE_DCCALRESULTS2__FORCE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(1) << 31)
#define MDM_PGA_FORCE_DCCALRESULTS2__FORCE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(0) << 31)
#define MDM_PGA_FORCE_DCCALRESULTS2__FORCE__RESET_VALUE             0x00000000U
/** @} */
#define MDM_PGA_FORCE_DCCALRESULTS2__TYPE                              uint32_t
#define MDM_PGA_FORCE_DCCALRESULTS2__READ                           0x8000ffffU
#define MDM_PGA_FORCE_DCCALRESULTS2__WRITE                          0x8000ffffU
#define MDM_PGA_FORCE_DCCALRESULTS2__PRESERVED                      0x00000000U
#define MDM_PGA_FORCE_DCCALRESULTS2__RESET_VALUE                    0x00000000U

#endif /* __MDM_PGA_FORCE_DCCALRESULTS2_MACRO__ */

/** @} end of pga_force_dccalresults2 */

/* macros for BlueprintGlobalNameSpace::MDM_pga_lp_force_dccalresults */
/**
 * @defgroup mdm_regs_core_pga_lp_force_dccalresults pga_lp_force_dccalresults
 * @brief Force DC offset calibration results for PGA for low power mode for paris definitions.
 * @{
 */
#ifndef __MDM_PGA_LP_FORCE_DCCALRESULTS_MACRO__
#define __MDM_PGA_LP_FORCE_DCCALRESULTS_MACRO__

/* macros for field q_off */
/**
 * @defgroup mdm_regs_core_q_off_field q_off_field
 * @brief macros for field q_off
 * @details forced PGA Q offset
 * @{
 */
#define MDM_PGA_LP_FORCE_DCCALRESULTS__Q_OFF__SHIFT                           0
#define MDM_PGA_LP_FORCE_DCCALRESULTS__Q_OFF__WIDTH                           5
#define MDM_PGA_LP_FORCE_DCCALRESULTS__Q_OFF__MASK                  0x0000001fU
#define MDM_PGA_LP_FORCE_DCCALRESULTS__Q_OFF__READ(src) \
                    ((uint32_t)(src)\
                    & 0x0000001fU)
#define MDM_PGA_LP_FORCE_DCCALRESULTS__Q_OFF__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000001fU)
#define MDM_PGA_LP_FORCE_DCCALRESULTS__Q_OFF__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000001fU) | ((uint32_t)(src) &\
                    0x0000001fU)
#define MDM_PGA_LP_FORCE_DCCALRESULTS__Q_OFF__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000001fU)))
#define MDM_PGA_LP_FORCE_DCCALRESULTS__Q_OFF__RESET_VALUE           0x00000000U
/** @} */

/* macros for field i_off */
/**
 * @defgroup mdm_regs_core_i_off_field i_off_field
 * @brief macros for field i_off
 * @details forced PGA I offset
 * @{
 */
#define MDM_PGA_LP_FORCE_DCCALRESULTS__I_OFF__SHIFT                           8
#define MDM_PGA_LP_FORCE_DCCALRESULTS__I_OFF__WIDTH                           5
#define MDM_PGA_LP_FORCE_DCCALRESULTS__I_OFF__MASK                  0x00001f00U
#define MDM_PGA_LP_FORCE_DCCALRESULTS__I_OFF__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00001f00U) >> 8)
#define MDM_PGA_LP_FORCE_DCCALRESULTS__I_OFF__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00001f00U)
#define MDM_PGA_LP_FORCE_DCCALRESULTS__I_OFF__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00001f00U) | (((uint32_t)(src) <<\
                    8) & 0x00001f00U)
#define MDM_PGA_LP_FORCE_DCCALRESULTS__I_OFF__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00001f00U)))
#define MDM_PGA_LP_FORCE_DCCALRESULTS__I_OFF__RESET_VALUE           0x00000000U
/** @} */

/* macros for field bb2gain */
/**
 * @defgroup mdm_regs_core_bb2gain_field bb2gain_field
 * @brief macros for field bb2gain
 * @details bb2gain value used in PGA cal
 * @{
 */
#define MDM_PGA_LP_FORCE_DCCALRESULTS__BB2GAIN__SHIFT                        16
#define MDM_PGA_LP_FORCE_DCCALRESULTS__BB2GAIN__WIDTH                         5
#define MDM_PGA_LP_FORCE_DCCALRESULTS__BB2GAIN__MASK                0x001f0000U
#define MDM_PGA_LP_FORCE_DCCALRESULTS__BB2GAIN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x001f0000U) >> 16)
#define MDM_PGA_LP_FORCE_DCCALRESULTS__BB2GAIN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x001f0000U)
#define MDM_PGA_LP_FORCE_DCCALRESULTS__BB2GAIN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x001f0000U) | (((uint32_t)(src) <<\
                    16) & 0x001f0000U)
#define MDM_PGA_LP_FORCE_DCCALRESULTS__BB2GAIN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x001f0000U)))
#define MDM_PGA_LP_FORCE_DCCALRESULTS__BB2GAIN__RESET_VALUE         0x00000000U
/** @} */

/* macros for field force */
/**
 * @defgroup mdm_regs_core_force_field force_field
 * @brief macros for field force
 * @details force to use offset in this register
 * @{
 */
#define MDM_PGA_LP_FORCE_DCCALRESULTS__FORCE__SHIFT                          31
#define MDM_PGA_LP_FORCE_DCCALRESULTS__FORCE__WIDTH                           1
#define MDM_PGA_LP_FORCE_DCCALRESULTS__FORCE__MASK                  0x80000000U
#define MDM_PGA_LP_FORCE_DCCALRESULTS__FORCE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x80000000U) >> 31)
#define MDM_PGA_LP_FORCE_DCCALRESULTS__FORCE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 31) & 0x80000000U)
#define MDM_PGA_LP_FORCE_DCCALRESULTS__FORCE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | (((uint32_t)(src) <<\
                    31) & 0x80000000U)
#define MDM_PGA_LP_FORCE_DCCALRESULTS__FORCE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 31) & ~0x80000000U)))
#define MDM_PGA_LP_FORCE_DCCALRESULTS__FORCE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(1) << 31)
#define MDM_PGA_LP_FORCE_DCCALRESULTS__FORCE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(0) << 31)
#define MDM_PGA_LP_FORCE_DCCALRESULTS__FORCE__RESET_VALUE           0x00000000U
/** @} */
#define MDM_PGA_LP_FORCE_DCCALRESULTS__TYPE                            uint32_t
#define MDM_PGA_LP_FORCE_DCCALRESULTS__READ                         0x801f1f1fU
#define MDM_PGA_LP_FORCE_DCCALRESULTS__WRITE                        0x801f1f1fU
#define MDM_PGA_LP_FORCE_DCCALRESULTS__PRESERVED                    0x00000000U
#define MDM_PGA_LP_FORCE_DCCALRESULTS__RESET_VALUE                  0x00000000U

#endif /* __MDM_PGA_LP_FORCE_DCCALRESULTS_MACRO__ */

/** @} end of pga_lp_force_dccalresults */

/* macros for BlueprintGlobalNameSpace::MDM_pga_lp_force_dccalresults2 */
/**
 * @defgroup mdm_regs_core_pga_lp_force_dccalresults2 pga_lp_force_dccalresults2
 * @brief Force DC offset calibration results for PGA for low power mode for paris definitions.
 * @{
 */
#ifndef __MDM_PGA_LP_FORCE_DCCALRESULTS2_MACRO__
#define __MDM_PGA_LP_FORCE_DCCALRESULTS2_MACRO__

/* macros for field avg_q */
/**
 * @defgroup mdm_regs_core_avg_q_field avg_q_field
 * @brief macros for field avg_q
 * @details calculated average of ADC Q samples
 * @{
 */
#define MDM_PGA_LP_FORCE_DCCALRESULTS2__AVG_Q__SHIFT                          0
#define MDM_PGA_LP_FORCE_DCCALRESULTS2__AVG_Q__WIDTH                          8
#define MDM_PGA_LP_FORCE_DCCALRESULTS2__AVG_Q__MASK                 0x000000ffU
#define MDM_PGA_LP_FORCE_DCCALRESULTS2__AVG_Q__READ(src) \
                    ((uint32_t)(src)\
                    & 0x000000ffU)
#define MDM_PGA_LP_FORCE_DCCALRESULTS2__AVG_Q__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x000000ffU)
#define MDM_PGA_LP_FORCE_DCCALRESULTS2__AVG_Q__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000ffU) | ((uint32_t)(src) &\
                    0x000000ffU)
#define MDM_PGA_LP_FORCE_DCCALRESULTS2__AVG_Q__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000000ffU)))
#define MDM_PGA_LP_FORCE_DCCALRESULTS2__AVG_Q__RESET_VALUE          0x00000000U
/** @} */

/* macros for field avg_i */
/**
 * @defgroup mdm_regs_core_avg_i_field avg_i_field
 * @brief macros for field avg_i
 * @details calculated average of ADC I samples
 * @{
 */
#define MDM_PGA_LP_FORCE_DCCALRESULTS2__AVG_I__SHIFT                          8
#define MDM_PGA_LP_FORCE_DCCALRESULTS2__AVG_I__WIDTH                          8
#define MDM_PGA_LP_FORCE_DCCALRESULTS2__AVG_I__MASK                 0x0000ff00U
#define MDM_PGA_LP_FORCE_DCCALRESULTS2__AVG_I__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000ff00U) >> 8)
#define MDM_PGA_LP_FORCE_DCCALRESULTS2__AVG_I__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x0000ff00U)
#define MDM_PGA_LP_FORCE_DCCALRESULTS2__AVG_I__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000ff00U) | (((uint32_t)(src) <<\
                    8) & 0x0000ff00U)
#define MDM_PGA_LP_FORCE_DCCALRESULTS2__AVG_I__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x0000ff00U)))
#define MDM_PGA_LP_FORCE_DCCALRESULTS2__AVG_I__RESET_VALUE          0x00000000U
/** @} */

/* macros for field force */
/**
 * @defgroup mdm_regs_core_force_field force_field
 * @brief macros for field force
 * @details force to use average in this register
 * @{
 */
#define MDM_PGA_LP_FORCE_DCCALRESULTS2__FORCE__SHIFT                         31
#define MDM_PGA_LP_FORCE_DCCALRESULTS2__FORCE__WIDTH                          1
#define MDM_PGA_LP_FORCE_DCCALRESULTS2__FORCE__MASK                 0x80000000U
#define MDM_PGA_LP_FORCE_DCCALRESULTS2__FORCE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x80000000U) >> 31)
#define MDM_PGA_LP_FORCE_DCCALRESULTS2__FORCE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 31) & 0x80000000U)
#define MDM_PGA_LP_FORCE_DCCALRESULTS2__FORCE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | (((uint32_t)(src) <<\
                    31) & 0x80000000U)
#define MDM_PGA_LP_FORCE_DCCALRESULTS2__FORCE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 31) & ~0x80000000U)))
#define MDM_PGA_LP_FORCE_DCCALRESULTS2__FORCE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(1) << 31)
#define MDM_PGA_LP_FORCE_DCCALRESULTS2__FORCE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(0) << 31)
#define MDM_PGA_LP_FORCE_DCCALRESULTS2__FORCE__RESET_VALUE          0x00000000U
/** @} */
#define MDM_PGA_LP_FORCE_DCCALRESULTS2__TYPE                           uint32_t
#define MDM_PGA_LP_FORCE_DCCALRESULTS2__READ                        0x8000ffffU
#define MDM_PGA_LP_FORCE_DCCALRESULTS2__WRITE                       0x8000ffffU
#define MDM_PGA_LP_FORCE_DCCALRESULTS2__PRESERVED                   0x00000000U
#define MDM_PGA_LP_FORCE_DCCALRESULTS2__RESET_VALUE                 0x00000000U

#endif /* __MDM_PGA_LP_FORCE_DCCALRESULTS2_MACRO__ */

/** @} end of pga_lp_force_dccalresults2 */

/* macros for BlueprintGlobalNameSpace::MDM_notch_force_dccalresults */
/**
 * @defgroup mdm_regs_core_notch_force_dccalresults notch_force_dccalresults
 * @brief DC offset calibration results for notch filter definitions.
 * @{
 */
#ifndef __MDM_NOTCH_FORCE_DCCALRESULTS_MACRO__
#define __MDM_NOTCH_FORCE_DCCALRESULTS_MACRO__

/* macros for field ctn */
/**
 * @defgroup mdm_regs_core_ctn_field ctn_field
 * @brief macros for field ctn
 * @details forced notch ctune
 * @{
 */
#define MDM_NOTCH_FORCE_DCCALRESULTS__CTN__SHIFT                              0
#define MDM_NOTCH_FORCE_DCCALRESULTS__CTN__WIDTH                              6
#define MDM_NOTCH_FORCE_DCCALRESULTS__CTN__MASK                     0x0000003fU
#define MDM_NOTCH_FORCE_DCCALRESULTS__CTN__READ(src) \
                    ((uint32_t)(src)\
                    & 0x0000003fU)
#define MDM_NOTCH_FORCE_DCCALRESULTS__CTN__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000003fU)
#define MDM_NOTCH_FORCE_DCCALRESULTS__CTN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000003fU) | ((uint32_t)(src) &\
                    0x0000003fU)
#define MDM_NOTCH_FORCE_DCCALRESULTS__CTN__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000003fU)))
#define MDM_NOTCH_FORCE_DCCALRESULTS__CTN__RESET_VALUE              0x00000000U
/** @} */

/* macros for field force */
/**
 * @defgroup mdm_regs_core_force_field force_field
 * @brief macros for field force
 * @details force to use tune in this register
 * @{
 */
#define MDM_NOTCH_FORCE_DCCALRESULTS__FORCE__SHIFT                           31
#define MDM_NOTCH_FORCE_DCCALRESULTS__FORCE__WIDTH                            1
#define MDM_NOTCH_FORCE_DCCALRESULTS__FORCE__MASK                   0x80000000U
#define MDM_NOTCH_FORCE_DCCALRESULTS__FORCE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x80000000U) >> 31)
#define MDM_NOTCH_FORCE_DCCALRESULTS__FORCE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 31) & 0x80000000U)
#define MDM_NOTCH_FORCE_DCCALRESULTS__FORCE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | (((uint32_t)(src) <<\
                    31) & 0x80000000U)
#define MDM_NOTCH_FORCE_DCCALRESULTS__FORCE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 31) & ~0x80000000U)))
#define MDM_NOTCH_FORCE_DCCALRESULTS__FORCE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(1) << 31)
#define MDM_NOTCH_FORCE_DCCALRESULTS__FORCE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(0) << 31)
#define MDM_NOTCH_FORCE_DCCALRESULTS__FORCE__RESET_VALUE            0x00000000U
/** @} */
#define MDM_NOTCH_FORCE_DCCALRESULTS__TYPE                             uint32_t
#define MDM_NOTCH_FORCE_DCCALRESULTS__READ                          0x8000003fU
#define MDM_NOTCH_FORCE_DCCALRESULTS__WRITE                         0x8000003fU
#define MDM_NOTCH_FORCE_DCCALRESULTS__PRESERVED                     0x00000000U
#define MDM_NOTCH_FORCE_DCCALRESULTS__RESET_VALUE                   0x00000000U

#endif /* __MDM_NOTCH_FORCE_DCCALRESULTS_MACRO__ */

/** @} end of notch_force_dccalresults */

/* macros for BlueprintGlobalNameSpace::MDM_pga_cal_gain_force_dccalresults */
/**
 * @defgroup mdm_regs_core_pga_cal_gain_force_dccalresults pga_cal_gain_force_dccalresults
 * @brief force DC offset calibration results for PGA at cal gain definitions.
 * @{
 */
#ifndef __MDM_PGA_CAL_GAIN_FORCE_DCCALRESULTS_MACRO__
#define __MDM_PGA_CAL_GAIN_FORCE_DCCALRESULTS_MACRO__

/* macros for field q_off */
/**
 * @defgroup mdm_regs_core_q_off_field q_off_field
 * @brief macros for field q_off
 * @details forced PGA Q offset
 * @{
 */
#define MDM_PGA_CAL_GAIN_FORCE_DCCALRESULTS__Q_OFF__SHIFT                     0
#define MDM_PGA_CAL_GAIN_FORCE_DCCALRESULTS__Q_OFF__WIDTH                     5
#define MDM_PGA_CAL_GAIN_FORCE_DCCALRESULTS__Q_OFF__MASK            0x0000001fU
#define MDM_PGA_CAL_GAIN_FORCE_DCCALRESULTS__Q_OFF__READ(src) \
                    ((uint32_t)(src)\
                    & 0x0000001fU)
#define MDM_PGA_CAL_GAIN_FORCE_DCCALRESULTS__Q_OFF__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000001fU)
#define MDM_PGA_CAL_GAIN_FORCE_DCCALRESULTS__Q_OFF__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000001fU) | ((uint32_t)(src) &\
                    0x0000001fU)
#define MDM_PGA_CAL_GAIN_FORCE_DCCALRESULTS__Q_OFF__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000001fU)))
#define MDM_PGA_CAL_GAIN_FORCE_DCCALRESULTS__Q_OFF__RESET_VALUE     0x00000000U
/** @} */

/* macros for field i_off */
/**
 * @defgroup mdm_regs_core_i_off_field i_off_field
 * @brief macros for field i_off
 * @details forced PGA I offset
 * @{
 */
#define MDM_PGA_CAL_GAIN_FORCE_DCCALRESULTS__I_OFF__SHIFT                     5
#define MDM_PGA_CAL_GAIN_FORCE_DCCALRESULTS__I_OFF__WIDTH                     5
#define MDM_PGA_CAL_GAIN_FORCE_DCCALRESULTS__I_OFF__MASK            0x000003e0U
#define MDM_PGA_CAL_GAIN_FORCE_DCCALRESULTS__I_OFF__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000003e0U) >> 5)
#define MDM_PGA_CAL_GAIN_FORCE_DCCALRESULTS__I_OFF__WRITE(src) \
                    (((uint32_t)(src)\
                    << 5) & 0x000003e0U)
#define MDM_PGA_CAL_GAIN_FORCE_DCCALRESULTS__I_OFF__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000003e0U) | (((uint32_t)(src) <<\
                    5) & 0x000003e0U)
#define MDM_PGA_CAL_GAIN_FORCE_DCCALRESULTS__I_OFF__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 5) & ~0x000003e0U)))
#define MDM_PGA_CAL_GAIN_FORCE_DCCALRESULTS__I_OFF__RESET_VALUE     0x00000000U
/** @} */

/* macros for field force */
/**
 * @defgroup mdm_regs_core_force_field force_field
 * @brief macros for field force
 * @details force to use offset in this register
 * @{
 */
#define MDM_PGA_CAL_GAIN_FORCE_DCCALRESULTS__FORCE__SHIFT                    31
#define MDM_PGA_CAL_GAIN_FORCE_DCCALRESULTS__FORCE__WIDTH                     1
#define MDM_PGA_CAL_GAIN_FORCE_DCCALRESULTS__FORCE__MASK            0x80000000U
#define MDM_PGA_CAL_GAIN_FORCE_DCCALRESULTS__FORCE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x80000000U) >> 31)
#define MDM_PGA_CAL_GAIN_FORCE_DCCALRESULTS__FORCE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 31) & 0x80000000U)
#define MDM_PGA_CAL_GAIN_FORCE_DCCALRESULTS__FORCE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | (((uint32_t)(src) <<\
                    31) & 0x80000000U)
#define MDM_PGA_CAL_GAIN_FORCE_DCCALRESULTS__FORCE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 31) & ~0x80000000U)))
#define MDM_PGA_CAL_GAIN_FORCE_DCCALRESULTS__FORCE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(1) << 31)
#define MDM_PGA_CAL_GAIN_FORCE_DCCALRESULTS__FORCE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(0) << 31)
#define MDM_PGA_CAL_GAIN_FORCE_DCCALRESULTS__FORCE__RESET_VALUE     0x00000000U
/** @} */
#define MDM_PGA_CAL_GAIN_FORCE_DCCALRESULTS__TYPE                      uint32_t
#define MDM_PGA_CAL_GAIN_FORCE_DCCALRESULTS__READ                   0x800003ffU
#define MDM_PGA_CAL_GAIN_FORCE_DCCALRESULTS__WRITE                  0x800003ffU
#define MDM_PGA_CAL_GAIN_FORCE_DCCALRESULTS__PRESERVED              0x00000000U
#define MDM_PGA_CAL_GAIN_FORCE_DCCALRESULTS__RESET_VALUE            0x00000000U

#endif /* __MDM_PGA_CAL_GAIN_FORCE_DCCALRESULTS_MACRO__ */

/** @} end of pga_cal_gain_force_dccalresults */

/* macros for BlueprintGlobalNameSpace::MDM_pga_cal_gain_force_dccalresults2 */
/**
 * @defgroup mdm_regs_core_pga_cal_gain_force_dccalresults2 pga_cal_gain_force_dccalresults2
 * @brief force DC offset calibration results for PGA at cal gain definitions.
 * @{
 */
#ifndef __MDM_PGA_CAL_GAIN_FORCE_DCCALRESULTS2_MACRO__
#define __MDM_PGA_CAL_GAIN_FORCE_DCCALRESULTS2_MACRO__

/* macros for field avg_q */
/**
 * @defgroup mdm_regs_core_avg_q_field avg_q_field
 * @brief macros for field avg_q
 * @details forced residue DC Q from DC cal
 * @{
 */
#define MDM_PGA_CAL_GAIN_FORCE_DCCALRESULTS2__AVG_Q__SHIFT                    0
#define MDM_PGA_CAL_GAIN_FORCE_DCCALRESULTS2__AVG_Q__WIDTH                    8
#define MDM_PGA_CAL_GAIN_FORCE_DCCALRESULTS2__AVG_Q__MASK           0x000000ffU
#define MDM_PGA_CAL_GAIN_FORCE_DCCALRESULTS2__AVG_Q__READ(src) \
                    ((uint32_t)(src)\
                    & 0x000000ffU)
#define MDM_PGA_CAL_GAIN_FORCE_DCCALRESULTS2__AVG_Q__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x000000ffU)
#define MDM_PGA_CAL_GAIN_FORCE_DCCALRESULTS2__AVG_Q__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000ffU) | ((uint32_t)(src) &\
                    0x000000ffU)
#define MDM_PGA_CAL_GAIN_FORCE_DCCALRESULTS2__AVG_Q__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000000ffU)))
#define MDM_PGA_CAL_GAIN_FORCE_DCCALRESULTS2__AVG_Q__RESET_VALUE    0x00000000U
/** @} */

/* macros for field avg_i */
/**
 * @defgroup mdm_regs_core_avg_i_field avg_i_field
 * @brief macros for field avg_i
 * @details forced residue DC I from DC cal
 * @{
 */
#define MDM_PGA_CAL_GAIN_FORCE_DCCALRESULTS2__AVG_I__SHIFT                    8
#define MDM_PGA_CAL_GAIN_FORCE_DCCALRESULTS2__AVG_I__WIDTH                    8
#define MDM_PGA_CAL_GAIN_FORCE_DCCALRESULTS2__AVG_I__MASK           0x0000ff00U
#define MDM_PGA_CAL_GAIN_FORCE_DCCALRESULTS2__AVG_I__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000ff00U) >> 8)
#define MDM_PGA_CAL_GAIN_FORCE_DCCALRESULTS2__AVG_I__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x0000ff00U)
#define MDM_PGA_CAL_GAIN_FORCE_DCCALRESULTS2__AVG_I__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000ff00U) | (((uint32_t)(src) <<\
                    8) & 0x0000ff00U)
#define MDM_PGA_CAL_GAIN_FORCE_DCCALRESULTS2__AVG_I__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x0000ff00U)))
#define MDM_PGA_CAL_GAIN_FORCE_DCCALRESULTS2__AVG_I__RESET_VALUE    0x00000000U
/** @} */

/* macros for field bb2gain */
/**
 * @defgroup mdm_regs_core_bb2gain_field bb2gain_field
 * @brief macros for field bb2gain
 * @details forced bb2gain value used in PGA cal
 * @{
 */
#define MDM_PGA_CAL_GAIN_FORCE_DCCALRESULTS2__BB2GAIN__SHIFT                 16
#define MDM_PGA_CAL_GAIN_FORCE_DCCALRESULTS2__BB2GAIN__WIDTH                  5
#define MDM_PGA_CAL_GAIN_FORCE_DCCALRESULTS2__BB2GAIN__MASK         0x001f0000U
#define MDM_PGA_CAL_GAIN_FORCE_DCCALRESULTS2__BB2GAIN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x001f0000U) >> 16)
#define MDM_PGA_CAL_GAIN_FORCE_DCCALRESULTS2__BB2GAIN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x001f0000U)
#define MDM_PGA_CAL_GAIN_FORCE_DCCALRESULTS2__BB2GAIN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x001f0000U) | (((uint32_t)(src) <<\
                    16) & 0x001f0000U)
#define MDM_PGA_CAL_GAIN_FORCE_DCCALRESULTS2__BB2GAIN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x001f0000U)))
#define MDM_PGA_CAL_GAIN_FORCE_DCCALRESULTS2__BB2GAIN__RESET_VALUE  0x00000000U
/** @} */

/* macros for field force_avg */
/**
 * @defgroup mdm_regs_core_force_avg_field force_avg_field
 * @brief macros for field force_avg
 * @details force to use residue DC this register
 * @{
 */
#define MDM_PGA_CAL_GAIN_FORCE_DCCALRESULTS2__FORCE_AVG__SHIFT               30
#define MDM_PGA_CAL_GAIN_FORCE_DCCALRESULTS2__FORCE_AVG__WIDTH                1
#define MDM_PGA_CAL_GAIN_FORCE_DCCALRESULTS2__FORCE_AVG__MASK       0x40000000U
#define MDM_PGA_CAL_GAIN_FORCE_DCCALRESULTS2__FORCE_AVG__READ(src) \
                    (((uint32_t)(src)\
                    & 0x40000000U) >> 30)
#define MDM_PGA_CAL_GAIN_FORCE_DCCALRESULTS2__FORCE_AVG__WRITE(src) \
                    (((uint32_t)(src)\
                    << 30) & 0x40000000U)
#define MDM_PGA_CAL_GAIN_FORCE_DCCALRESULTS2__FORCE_AVG__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | (((uint32_t)(src) <<\
                    30) & 0x40000000U)
#define MDM_PGA_CAL_GAIN_FORCE_DCCALRESULTS2__FORCE_AVG__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 30) & ~0x40000000U)))
#define MDM_PGA_CAL_GAIN_FORCE_DCCALRESULTS2__FORCE_AVG__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(1) << 30)
#define MDM_PGA_CAL_GAIN_FORCE_DCCALRESULTS2__FORCE_AVG__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(0) << 30)
#define MDM_PGA_CAL_GAIN_FORCE_DCCALRESULTS2__FORCE_AVG__RESET_VALUE \
                    0x00000000U
/** @} */

/* macros for field force_bb2gain */
/**
 * @defgroup mdm_regs_core_force_bb2gain_field force_bb2gain_field
 * @brief macros for field force_bb2gain
 * @details force to use bb2gain this register
 * @{
 */
#define MDM_PGA_CAL_GAIN_FORCE_DCCALRESULTS2__FORCE_BB2GAIN__SHIFT           31
#define MDM_PGA_CAL_GAIN_FORCE_DCCALRESULTS2__FORCE_BB2GAIN__WIDTH            1
#define MDM_PGA_CAL_GAIN_FORCE_DCCALRESULTS2__FORCE_BB2GAIN__MASK   0x80000000U
#define MDM_PGA_CAL_GAIN_FORCE_DCCALRESULTS2__FORCE_BB2GAIN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x80000000U) >> 31)
#define MDM_PGA_CAL_GAIN_FORCE_DCCALRESULTS2__FORCE_BB2GAIN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 31) & 0x80000000U)
#define MDM_PGA_CAL_GAIN_FORCE_DCCALRESULTS2__FORCE_BB2GAIN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | (((uint32_t)(src) <<\
                    31) & 0x80000000U)
#define MDM_PGA_CAL_GAIN_FORCE_DCCALRESULTS2__FORCE_BB2GAIN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 31) & ~0x80000000U)))
#define MDM_PGA_CAL_GAIN_FORCE_DCCALRESULTS2__FORCE_BB2GAIN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(1) << 31)
#define MDM_PGA_CAL_GAIN_FORCE_DCCALRESULTS2__FORCE_BB2GAIN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(0) << 31)
#define MDM_PGA_CAL_GAIN_FORCE_DCCALRESULTS2__FORCE_BB2GAIN__RESET_VALUE \
                    0x00000000U
/** @} */
#define MDM_PGA_CAL_GAIN_FORCE_DCCALRESULTS2__TYPE                     uint32_t
#define MDM_PGA_CAL_GAIN_FORCE_DCCALRESULTS2__READ                  0xc01fffffU
#define MDM_PGA_CAL_GAIN_FORCE_DCCALRESULTS2__WRITE                 0xc01fffffU
#define MDM_PGA_CAL_GAIN_FORCE_DCCALRESULTS2__PRESERVED             0x00000000U
#define MDM_PGA_CAL_GAIN_FORCE_DCCALRESULTS2__RESET_VALUE           0x00000000U

#endif /* __MDM_PGA_CAL_GAIN_FORCE_DCCALRESULTS2_MACRO__ */

/** @} end of pga_cal_gain_force_dccalresults2 */

/* macros for BlueprintGlobalNameSpace::MDM_iqcorr */
/**
 * @defgroup mdm_regs_core_iqcorr iqcorr
 * @brief I/Q correction: Default definitions.
 * @{
 */
#ifndef __MDM_IQCORR_MACRO__
#define __MDM_IQCORR_MACRO__

/* macros for field ampl_corr_default */
/**
 * @defgroup mdm_regs_core_ampl_corr_default_field ampl_corr_default_field
 * @brief macros for field ampl_corr_default
 * @details Signed
 * @{
 */
#define MDM_IQCORR__AMPL_CORR_DEFAULT__SHIFT                                  0
#define MDM_IQCORR__AMPL_CORR_DEFAULT__WIDTH                                  8
#define MDM_IQCORR__AMPL_CORR_DEFAULT__MASK                         0x000000ffU
#define MDM_IQCORR__AMPL_CORR_DEFAULT__READ(src) \
                    ((uint32_t)(src)\
                    & 0x000000ffU)
#define MDM_IQCORR__AMPL_CORR_DEFAULT__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x000000ffU)
#define MDM_IQCORR__AMPL_CORR_DEFAULT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000ffU) | ((uint32_t)(src) &\
                    0x000000ffU)
#define MDM_IQCORR__AMPL_CORR_DEFAULT__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000000ffU)))
#define MDM_IQCORR__AMPL_CORR_DEFAULT__RESET_VALUE                  0x00000000U
/** @} */

/* macros for field phase_corr_default */
/**
 * @defgroup mdm_regs_core_phase_corr_default_field phase_corr_default_field
 * @brief macros for field phase_corr_default
 * @details Signed
 * @{
 */
#define MDM_IQCORR__PHASE_CORR_DEFAULT__SHIFT                                 8
#define MDM_IQCORR__PHASE_CORR_DEFAULT__WIDTH                                 8
#define MDM_IQCORR__PHASE_CORR_DEFAULT__MASK                        0x0000ff00U
#define MDM_IQCORR__PHASE_CORR_DEFAULT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000ff00U) >> 8)
#define MDM_IQCORR__PHASE_CORR_DEFAULT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x0000ff00U)
#define MDM_IQCORR__PHASE_CORR_DEFAULT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000ff00U) | (((uint32_t)(src) <<\
                    8) & 0x0000ff00U)
#define MDM_IQCORR__PHASE_CORR_DEFAULT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x0000ff00U)))
#define MDM_IQCORR__PHASE_CORR_DEFAULT__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field twomeg_ampl_corr_default */
/**
 * @defgroup mdm_regs_core_twomeg_ampl_corr_default_field twomeg_ampl_corr_default_field
 * @brief macros for field twomeg_ampl_corr_default
 * @details Signed
 * @{
 */
#define MDM_IQCORR__TWOMEG_AMPL_CORR_DEFAULT__SHIFT                          16
#define MDM_IQCORR__TWOMEG_AMPL_CORR_DEFAULT__WIDTH                           8
#define MDM_IQCORR__TWOMEG_AMPL_CORR_DEFAULT__MASK                  0x00ff0000U
#define MDM_IQCORR__TWOMEG_AMPL_CORR_DEFAULT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00ff0000U) >> 16)
#define MDM_IQCORR__TWOMEG_AMPL_CORR_DEFAULT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x00ff0000U)
#define MDM_IQCORR__TWOMEG_AMPL_CORR_DEFAULT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00ff0000U) | (((uint32_t)(src) <<\
                    16) & 0x00ff0000U)
#define MDM_IQCORR__TWOMEG_AMPL_CORR_DEFAULT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x00ff0000U)))
#define MDM_IQCORR__TWOMEG_AMPL_CORR_DEFAULT__RESET_VALUE           0x00000000U
/** @} */

/* macros for field twomeg_phase_corr_default */
/**
 * @defgroup mdm_regs_core_twomeg_phase_corr_default_field twomeg_phase_corr_default_field
 * @brief macros for field twomeg_phase_corr_default
 * @details Signed
 * @{
 */
#define MDM_IQCORR__TWOMEG_PHASE_CORR_DEFAULT__SHIFT                         24
#define MDM_IQCORR__TWOMEG_PHASE_CORR_DEFAULT__WIDTH                          8
#define MDM_IQCORR__TWOMEG_PHASE_CORR_DEFAULT__MASK                 0xff000000U
#define MDM_IQCORR__TWOMEG_PHASE_CORR_DEFAULT__READ(src) \
                    (((uint32_t)(src)\
                    & 0xff000000U) >> 24)
#define MDM_IQCORR__TWOMEG_PHASE_CORR_DEFAULT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0xff000000U)
#define MDM_IQCORR__TWOMEG_PHASE_CORR_DEFAULT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xff000000U) | (((uint32_t)(src) <<\
                    24) & 0xff000000U)
#define MDM_IQCORR__TWOMEG_PHASE_CORR_DEFAULT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0xff000000U)))
#define MDM_IQCORR__TWOMEG_PHASE_CORR_DEFAULT__RESET_VALUE          0x00000000U
/** @} */
#define MDM_IQCORR__TYPE                                               uint32_t
#define MDM_IQCORR__READ                                            0xffffffffU
#define MDM_IQCORR__WRITE                                           0xffffffffU
#define MDM_IQCORR__PRESERVED                                       0x00000000U
#define MDM_IQCORR__RESET_VALUE                                     0x00000000U

#endif /* __MDM_IQCORR_MACRO__ */

/** @} end of iqcorr */

/* macros for BlueprintGlobalNameSpace::MDM_agcmeas_alt */
/**
 * @defgroup mdm_regs_core_agcmeas_alt agcmeas_alt
 * @brief Power measurements, alternate set definitions.
 * @{
 */
#ifndef __MDM_AGCMEAS_ALT_MACRO__
#define __MDM_AGCMEAS_ALT_MACRO__

/* macros for field rssi_offset */
/**
 * @defgroup mdm_regs_core_rssi_offset_field rssi_offset_field
 * @brief macros for field rssi_offset
 * @details RSSI = rxgain - (measured_power after RXFIR) plus rssi_offset. Signed. Register replicated for 2 Mb/s
 * @{
 */
#define MDM_AGCMEAS_ALT__RSSI_OFFSET__SHIFT                                   0
#define MDM_AGCMEAS_ALT__RSSI_OFFSET__WIDTH                                   8
#define MDM_AGCMEAS_ALT__RSSI_OFFSET__MASK                          0x000000ffU
#define MDM_AGCMEAS_ALT__RSSI_OFFSET__READ(src) ((uint32_t)(src) & 0x000000ffU)
#define MDM_AGCMEAS_ALT__RSSI_OFFSET__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x000000ffU)
#define MDM_AGCMEAS_ALT__RSSI_OFFSET__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000ffU) | ((uint32_t)(src) &\
                    0x000000ffU)
#define MDM_AGCMEAS_ALT__RSSI_OFFSET__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000000ffU)))
#define MDM_AGCMEAS_ALT__RSSI_OFFSET__RESET_VALUE                   0x00000011U
/** @} */

/* macros for field det_min */
/**
 * @defgroup mdm_regs_core_det_min_field det_min_field
 * @brief macros for field det_min
 * @details Signed, relative to full scale agc filter output. Lowest allowed inband power measurement 7'h4d = -51. Register replicated for 2 Mb/s
 * @{
 */
#define MDM_AGCMEAS_ALT__DET_MIN__SHIFT                                       8
#define MDM_AGCMEAS_ALT__DET_MIN__WIDTH                                       7
#define MDM_AGCMEAS_ALT__DET_MIN__MASK                              0x00007f00U
#define MDM_AGCMEAS_ALT__DET_MIN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00007f00U) >> 8)
#define MDM_AGCMEAS_ALT__DET_MIN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00007f00U)
#define MDM_AGCMEAS_ALT__DET_MIN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00007f00U) | (((uint32_t)(src) <<\
                    8) & 0x00007f00U)
#define MDM_AGCMEAS_ALT__DET_MIN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00007f00U)))
#define MDM_AGCMEAS_ALT__DET_MIN__RESET_VALUE                       0x0000004dU
/** @} */

/* macros for field twomeg_rssi_offset */
/**
 * @defgroup mdm_regs_core_twomeg_rssi_offset_field twomeg_rssi_offset_field
 * @brief macros for field twomeg_rssi_offset
 * @details RSSI = rxgain - (measured_power after RXFIR) plus rssi_offset. 2 Mb/s version of register.
 * @{
 */
#define MDM_AGCMEAS_ALT__TWOMEG_RSSI_OFFSET__SHIFT                           15
#define MDM_AGCMEAS_ALT__TWOMEG_RSSI_OFFSET__WIDTH                            8
#define MDM_AGCMEAS_ALT__TWOMEG_RSSI_OFFSET__MASK                   0x007f8000U
#define MDM_AGCMEAS_ALT__TWOMEG_RSSI_OFFSET__READ(src) \
                    (((uint32_t)(src)\
                    & 0x007f8000U) >> 15)
#define MDM_AGCMEAS_ALT__TWOMEG_RSSI_OFFSET__WRITE(src) \
                    (((uint32_t)(src)\
                    << 15) & 0x007f8000U)
#define MDM_AGCMEAS_ALT__TWOMEG_RSSI_OFFSET__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x007f8000U) | (((uint32_t)(src) <<\
                    15) & 0x007f8000U)
#define MDM_AGCMEAS_ALT__TWOMEG_RSSI_OFFSET__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 15) & ~0x007f8000U)))
#define MDM_AGCMEAS_ALT__TWOMEG_RSSI_OFFSET__RESET_VALUE            0x00000011U
/** @} */

/* macros for field twomeg_det_min */
/**
 * @defgroup mdm_regs_core_twomeg_det_min_field twomeg_det_min_field
 * @brief macros for field twomeg_det_min
 * @details Signed, relative to full scale agc filter output. Lowest allowed inband power measurement 7'h50 = -48. 2 Mb/s version of this register
 * @{
 */
#define MDM_AGCMEAS_ALT__TWOMEG_DET_MIN__SHIFT                               23
#define MDM_AGCMEAS_ALT__TWOMEG_DET_MIN__WIDTH                                7
#define MDM_AGCMEAS_ALT__TWOMEG_DET_MIN__MASK                       0x3f800000U
#define MDM_AGCMEAS_ALT__TWOMEG_DET_MIN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x3f800000U) >> 23)
#define MDM_AGCMEAS_ALT__TWOMEG_DET_MIN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 23) & 0x3f800000U)
#define MDM_AGCMEAS_ALT__TWOMEG_DET_MIN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x3f800000U) | (((uint32_t)(src) <<\
                    23) & 0x3f800000U)
#define MDM_AGCMEAS_ALT__TWOMEG_DET_MIN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 23) & ~0x3f800000U)))
#define MDM_AGCMEAS_ALT__TWOMEG_DET_MIN__RESET_VALUE                0x00000050U
/** @} */
#define MDM_AGCMEAS_ALT__TYPE                                          uint32_t
#define MDM_AGCMEAS_ALT__READ                                       0x3fffffffU
#define MDM_AGCMEAS_ALT__WRITE                                      0x3fffffffU
#define MDM_AGCMEAS_ALT__PRESERVED                                  0x00000000U
#define MDM_AGCMEAS_ALT__RESET_VALUE                                0x2808cd11U

#endif /* __MDM_AGCMEAS_ALT_MACRO__ */

/** @} end of agcmeas_alt */

/* macros for BlueprintGlobalNameSpace::MDM_agcgain_alt */
/**
 * @defgroup mdm_regs_core_agcgain_alt agcgain_alt
 * @brief Gain settings, alternate set definitions.
 * @{
 */
#ifndef __MDM_AGCGAIN_ALT_MACRO__
#define __MDM_AGCGAIN_ALT_MACRO__

/* macros for field start */
/**
 * @defgroup mdm_regs_core_start_field start_field
 * @brief macros for field start
 * @details RX gain to use at start of packet search
 * @{
 */
#define MDM_AGCGAIN_ALT__START__SHIFT                                         0
#define MDM_AGCGAIN_ALT__START__WIDTH                                         7
#define MDM_AGCGAIN_ALT__START__MASK                                0x0000007fU
#define MDM_AGCGAIN_ALT__START__READ(src)       ((uint32_t)(src) & 0x0000007fU)
#define MDM_AGCGAIN_ALT__START__WRITE(src)      ((uint32_t)(src) & 0x0000007fU)
#define MDM_AGCGAIN_ALT__START__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000007fU) | ((uint32_t)(src) &\
                    0x0000007fU)
#define MDM_AGCGAIN_ALT__START__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000007fU)))
#define MDM_AGCGAIN_ALT__START__RESET_VALUE                         0x0000004cU
/** @} */

/* macros for field rfin_pd_quick_drop */
/**
 * @defgroup mdm_regs_core_rfin_pd_quick_drop_field rfin_pd_quick_drop_field
 * @brief macros for field rfin_pd_quick_drop
 * @details Gain drop in dB when rfin peak detect indicated
 * @{
 */
#define MDM_AGCGAIN_ALT__RFIN_PD_QUICK_DROP__SHIFT                           14
#define MDM_AGCGAIN_ALT__RFIN_PD_QUICK_DROP__WIDTH                            7
#define MDM_AGCGAIN_ALT__RFIN_PD_QUICK_DROP__MASK                   0x001fc000U
#define MDM_AGCGAIN_ALT__RFIN_PD_QUICK_DROP__READ(src) \
                    (((uint32_t)(src)\
                    & 0x001fc000U) >> 14)
#define MDM_AGCGAIN_ALT__RFIN_PD_QUICK_DROP__WRITE(src) \
                    (((uint32_t)(src)\
                    << 14) & 0x001fc000U)
#define MDM_AGCGAIN_ALT__RFIN_PD_QUICK_DROP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x001fc000U) | (((uint32_t)(src) <<\
                    14) & 0x001fc000U)
#define MDM_AGCGAIN_ALT__RFIN_PD_QUICK_DROP__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 14) & ~0x001fc000U)))
#define MDM_AGCGAIN_ALT__RFIN_PD_QUICK_DROP__RESET_VALUE            0x00000045U
/** @} */

/* macros for field tia_quick_drop */
/**
 * @defgroup mdm_regs_core_tia_quick_drop_field tia_quick_drop_field
 * @brief macros for field tia_quick_drop
 * @details Gain drop in dB when peak detect indicated
 * @{
 */
#define MDM_AGCGAIN_ALT__TIA_QUICK_DROP__SHIFT                               21
#define MDM_AGCGAIN_ALT__TIA_QUICK_DROP__WIDTH                                7
#define MDM_AGCGAIN_ALT__TIA_QUICK_DROP__MASK                       0x0fe00000U
#define MDM_AGCGAIN_ALT__TIA_QUICK_DROP__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0fe00000U) >> 21)
#define MDM_AGCGAIN_ALT__TIA_QUICK_DROP__WRITE(src) \
                    (((uint32_t)(src)\
                    << 21) & 0x0fe00000U)
#define MDM_AGCGAIN_ALT__TIA_QUICK_DROP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0fe00000U) | (((uint32_t)(src) <<\
                    21) & 0x0fe00000U)
#define MDM_AGCGAIN_ALT__TIA_QUICK_DROP__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 21) & ~0x0fe00000U)))
#define MDM_AGCGAIN_ALT__TIA_QUICK_DROP__RESET_VALUE                0x00000036U
/** @} */
#define MDM_AGCGAIN_ALT__TYPE                                          uint32_t
#define MDM_AGCGAIN_ALT__READ                                       0x0fffc07fU
#define MDM_AGCGAIN_ALT__WRITE                                      0x0fffc07fU
#define MDM_AGCGAIN_ALT__PRESERVED                                  0x00000000U
#define MDM_AGCGAIN_ALT__RESET_VALUE                                0x06d1404cU

#endif /* __MDM_AGCGAIN_ALT_MACRO__ */

/** @} end of agcgain_alt */

/* macros for BlueprintGlobalNameSpace::MDM_xlna */
/**
 * @defgroup mdm_regs_core_xlna xlna
 * @brief XLNA control definitions.
 * @{
 */
#ifndef __MDM_XLNA_MACRO__
#define __MDM_XLNA_MACRO__

/* macros for field gain_settle */
/**
 * @defgroup mdm_regs_core_gain_settle_field gain_settle_field
 * @brief macros for field gain_settle
 * @details When XLNA switches, use this instead of agctime_gain_settle
 * @{
 */
#define MDM_XLNA__GAIN_SETTLE__SHIFT                                          0
#define MDM_XLNA__GAIN_SETTLE__WIDTH                                          6
#define MDM_XLNA__GAIN_SETTLE__MASK                                 0x0000003fU
#define MDM_XLNA__GAIN_SETTLE__READ(src)        ((uint32_t)(src) & 0x0000003fU)
#define MDM_XLNA__GAIN_SETTLE__WRITE(src)       ((uint32_t)(src) & 0x0000003fU)
#define MDM_XLNA__GAIN_SETTLE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000003fU) | ((uint32_t)(src) &\
                    0x0000003fU)
#define MDM_XLNA__GAIN_SETTLE__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000003fU)))
#define MDM_XLNA__GAIN_SETTLE__RESET_VALUE                          0x0000001cU
/** @} */

/* macros for field twomeg_gain_settle */
/**
 * @defgroup mdm_regs_core_twomeg_gain_settle_field twomeg_gain_settle_field
 * @brief macros for field twomeg_gain_settle
 * @details When XLNA switches, use this instead of twomeg_agctime_gain_settle
 * @{
 */
#define MDM_XLNA__TWOMEG_GAIN_SETTLE__SHIFT                                   6
#define MDM_XLNA__TWOMEG_GAIN_SETTLE__WIDTH                                   6
#define MDM_XLNA__TWOMEG_GAIN_SETTLE__MASK                          0x00000fc0U
#define MDM_XLNA__TWOMEG_GAIN_SETTLE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000fc0U) >> 6)
#define MDM_XLNA__TWOMEG_GAIN_SETTLE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 6) & 0x00000fc0U)
#define MDM_XLNA__TWOMEG_GAIN_SETTLE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000fc0U) | (((uint32_t)(src) <<\
                    6) & 0x00000fc0U)
#define MDM_XLNA__TWOMEG_GAIN_SETTLE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 6) & ~0x00000fc0U)))
#define MDM_XLNA__TWOMEG_GAIN_SETTLE__RESET_VALUE                   0x00000010U
/** @} */

/* macros for field reset_filt_delay */
/**
 * @defgroup mdm_regs_core_reset_filt_delay_field reset_filt_delay_field
 * @brief macros for field reset_filt_delay
 * @details When XLNA switches, use this instead of agctime2_reset_filt_delay
 * @{
 */
#define MDM_XLNA__RESET_FILT_DELAY__SHIFT                                    12
#define MDM_XLNA__RESET_FILT_DELAY__WIDTH                                     6
#define MDM_XLNA__RESET_FILT_DELAY__MASK                            0x0003f000U
#define MDM_XLNA__RESET_FILT_DELAY__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0003f000U) >> 12)
#define MDM_XLNA__RESET_FILT_DELAY__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x0003f000U)
#define MDM_XLNA__RESET_FILT_DELAY__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0003f000U) | (((uint32_t)(src) <<\
                    12) & 0x0003f000U)
#define MDM_XLNA__RESET_FILT_DELAY__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x0003f000U)))
#define MDM_XLNA__RESET_FILT_DELAY__RESET_VALUE                     0x00000010U
/** @} */

/* macros for field twomeg_reset_filt_delay */
/**
 * @defgroup mdm_regs_core_twomeg_reset_filt_delay_field twomeg_reset_filt_delay_field
 * @brief macros for field twomeg_reset_filt_delay
 * @details When XLNA switches, use this instead of agctime2_twomeg_reset_filt_delay
 * @{
 */
#define MDM_XLNA__TWOMEG_RESET_FILT_DELAY__SHIFT                             18
#define MDM_XLNA__TWOMEG_RESET_FILT_DELAY__WIDTH                              6
#define MDM_XLNA__TWOMEG_RESET_FILT_DELAY__MASK                     0x00fc0000U
#define MDM_XLNA__TWOMEG_RESET_FILT_DELAY__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00fc0000U) >> 18)
#define MDM_XLNA__TWOMEG_RESET_FILT_DELAY__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0x00fc0000U)
#define MDM_XLNA__TWOMEG_RESET_FILT_DELAY__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00fc0000U) | (((uint32_t)(src) <<\
                    18) & 0x00fc0000U)
#define MDM_XLNA__TWOMEG_RESET_FILT_DELAY__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x00fc0000U)))
#define MDM_XLNA__TWOMEG_RESET_FILT_DELAY__RESET_VALUE              0x0000000aU
/** @} */

/* macros for field thresh */
/**
 * @defgroup mdm_regs_core_thresh_field thresh_field
 * @brief macros for field thresh
 * @details During active RX, turn on XLNA when rxgain index is greater than this threshold. Turn off XLNA when rxgain index is less than this threshold. At 127, XLNA will never turn on
 * @{
 */
#define MDM_XLNA__THRESH__SHIFT                                              24
#define MDM_XLNA__THRESH__WIDTH                                               7
#define MDM_XLNA__THRESH__MASK                                      0x7f000000U
#define MDM_XLNA__THRESH__READ(src)     (((uint32_t)(src) & 0x7f000000U) >> 24)
#define MDM_XLNA__THRESH__WRITE(src)    (((uint32_t)(src) << 24) & 0x7f000000U)
#define MDM_XLNA__THRESH__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x7f000000U) | (((uint32_t)(src) <<\
                    24) & 0x7f000000U)
#define MDM_XLNA__THRESH__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x7f000000U)))
#define MDM_XLNA__THRESH__RESET_VALUE                               0x0000007fU
/** @} */
#define MDM_XLNA__TYPE                                                 uint32_t
#define MDM_XLNA__READ                                              0x7fffffffU
#define MDM_XLNA__WRITE                                             0x7fffffffU
#define MDM_XLNA__PRESERVED                                         0x00000000U
#define MDM_XLNA__RESET_VALUE                                       0x7f29041cU

#endif /* __MDM_XLNA_MACRO__ */

/** @} end of xlna */

/* macros for BlueprintGlobalNameSpace::MDM_xlna_alt */
/**
 * @defgroup mdm_regs_core_xlna_alt xlna_alt
 * @brief XLNA control, alternate set definitions.
 * @{
 */
#ifndef __MDM_XLNA_ALT_MACRO__
#define __MDM_XLNA_ALT_MACRO__

/* macros for field gain_settle */
/**
 * @defgroup mdm_regs_core_gain_settle_field gain_settle_field
 * @brief macros for field gain_settle
 * @details When XLNA switches, use this instead of agctime_gain_settle
 * @{
 */
#define MDM_XLNA_ALT__GAIN_SETTLE__SHIFT                                      0
#define MDM_XLNA_ALT__GAIN_SETTLE__WIDTH                                      6
#define MDM_XLNA_ALT__GAIN_SETTLE__MASK                             0x0000003fU
#define MDM_XLNA_ALT__GAIN_SETTLE__READ(src)    ((uint32_t)(src) & 0x0000003fU)
#define MDM_XLNA_ALT__GAIN_SETTLE__WRITE(src)   ((uint32_t)(src) & 0x0000003fU)
#define MDM_XLNA_ALT__GAIN_SETTLE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000003fU) | ((uint32_t)(src) &\
                    0x0000003fU)
#define MDM_XLNA_ALT__GAIN_SETTLE__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000003fU)))
#define MDM_XLNA_ALT__GAIN_SETTLE__RESET_VALUE                      0x0000001cU
/** @} */

/* macros for field twomeg_gain_settle */
/**
 * @defgroup mdm_regs_core_twomeg_gain_settle_field twomeg_gain_settle_field
 * @brief macros for field twomeg_gain_settle
 * @details When XLNA switches, use this instead of twomeg_agctime_gain_settle
 * @{
 */
#define MDM_XLNA_ALT__TWOMEG_GAIN_SETTLE__SHIFT                               6
#define MDM_XLNA_ALT__TWOMEG_GAIN_SETTLE__WIDTH                               6
#define MDM_XLNA_ALT__TWOMEG_GAIN_SETTLE__MASK                      0x00000fc0U
#define MDM_XLNA_ALT__TWOMEG_GAIN_SETTLE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000fc0U) >> 6)
#define MDM_XLNA_ALT__TWOMEG_GAIN_SETTLE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 6) & 0x00000fc0U)
#define MDM_XLNA_ALT__TWOMEG_GAIN_SETTLE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000fc0U) | (((uint32_t)(src) <<\
                    6) & 0x00000fc0U)
#define MDM_XLNA_ALT__TWOMEG_GAIN_SETTLE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 6) & ~0x00000fc0U)))
#define MDM_XLNA_ALT__TWOMEG_GAIN_SETTLE__RESET_VALUE               0x00000010U
/** @} */

/* macros for field reset_filt_delay */
/**
 * @defgroup mdm_regs_core_reset_filt_delay_field reset_filt_delay_field
 * @brief macros for field reset_filt_delay
 * @details When XLNA switches, use this instead of agctime2_reset_filt_delay
 * @{
 */
#define MDM_XLNA_ALT__RESET_FILT_DELAY__SHIFT                                12
#define MDM_XLNA_ALT__RESET_FILT_DELAY__WIDTH                                 6
#define MDM_XLNA_ALT__RESET_FILT_DELAY__MASK                        0x0003f000U
#define MDM_XLNA_ALT__RESET_FILT_DELAY__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0003f000U) >> 12)
#define MDM_XLNA_ALT__RESET_FILT_DELAY__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x0003f000U)
#define MDM_XLNA_ALT__RESET_FILT_DELAY__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0003f000U) | (((uint32_t)(src) <<\
                    12) & 0x0003f000U)
#define MDM_XLNA_ALT__RESET_FILT_DELAY__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x0003f000U)))
#define MDM_XLNA_ALT__RESET_FILT_DELAY__RESET_VALUE                 0x00000010U
/** @} */

/* macros for field twomeg_reset_filt_delay */
/**
 * @defgroup mdm_regs_core_twomeg_reset_filt_delay_field twomeg_reset_filt_delay_field
 * @brief macros for field twomeg_reset_filt_delay
 * @details When XLNA switches, use this instead of agctime2_twomeg_reset_filt_delay
 * @{
 */
#define MDM_XLNA_ALT__TWOMEG_RESET_FILT_DELAY__SHIFT                         18
#define MDM_XLNA_ALT__TWOMEG_RESET_FILT_DELAY__WIDTH                          6
#define MDM_XLNA_ALT__TWOMEG_RESET_FILT_DELAY__MASK                 0x00fc0000U
#define MDM_XLNA_ALT__TWOMEG_RESET_FILT_DELAY__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00fc0000U) >> 18)
#define MDM_XLNA_ALT__TWOMEG_RESET_FILT_DELAY__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0x00fc0000U)
#define MDM_XLNA_ALT__TWOMEG_RESET_FILT_DELAY__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00fc0000U) | (((uint32_t)(src) <<\
                    18) & 0x00fc0000U)
#define MDM_XLNA_ALT__TWOMEG_RESET_FILT_DELAY__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x00fc0000U)))
#define MDM_XLNA_ALT__TWOMEG_RESET_FILT_DELAY__RESET_VALUE          0x0000000aU
/** @} */

/* macros for field thresh */
/**
 * @defgroup mdm_regs_core_thresh_field thresh_field
 * @brief macros for field thresh
 * @details During active RX, turn on XLNA when rxgain index is greater than this threshold. Turn off XLNA when rxgain index is less than this threshold. At 127, XLNA will never turn on
 * @{
 */
#define MDM_XLNA_ALT__THRESH__SHIFT                                          24
#define MDM_XLNA_ALT__THRESH__WIDTH                                           7
#define MDM_XLNA_ALT__THRESH__MASK                                  0x7f000000U
#define MDM_XLNA_ALT__THRESH__READ(src) (((uint32_t)(src) & 0x7f000000U) >> 24)
#define MDM_XLNA_ALT__THRESH__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x7f000000U)
#define MDM_XLNA_ALT__THRESH__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x7f000000U) | (((uint32_t)(src) <<\
                    24) & 0x7f000000U)
#define MDM_XLNA_ALT__THRESH__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x7f000000U)))
#define MDM_XLNA_ALT__THRESH__RESET_VALUE                           0x0000007fU
/** @} */
#define MDM_XLNA_ALT__TYPE                                             uint32_t
#define MDM_XLNA_ALT__READ                                          0x7fffffffU
#define MDM_XLNA_ALT__WRITE                                         0x7fffffffU
#define MDM_XLNA_ALT__PRESERVED                                     0x00000000U
#define MDM_XLNA_ALT__RESET_VALUE                                   0x7f29041cU

#endif /* __MDM_XLNA_ALT_MACRO__ */

/** @} end of xlna_alt */

/* macros for BlueprintGlobalNameSpace::MDM_agcsat */
/**
 * @defgroup mdm_regs_core_agcsat agcsat
 * @brief Saturation control definitions.
 * @{
 */
#ifndef __MDM_AGCSAT_MACRO__
#define __MDM_AGCSAT_MACRO__

/* macros for field check_win */
/**
 * @defgroup mdm_regs_core_check_win_field check_win_field
 * @brief macros for field check_win
 * @details Number of samples to measure for EACH of I and Q. Maximum allowed is 8. If set to 0, then saturation detection is disabled.
 * @{
 */
#define MDM_AGCSAT__CHECK_WIN__SHIFT                                          0
#define MDM_AGCSAT__CHECK_WIN__WIDTH                                          4
#define MDM_AGCSAT__CHECK_WIN__MASK                                 0x0000000fU
#define MDM_AGCSAT__CHECK_WIN__READ(src)        ((uint32_t)(src) & 0x0000000fU)
#define MDM_AGCSAT__CHECK_WIN__WRITE(src)       ((uint32_t)(src) & 0x0000000fU)
#define MDM_AGCSAT__CHECK_WIN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000000fU) | ((uint32_t)(src) &\
                    0x0000000fU)
#define MDM_AGCSAT__CHECK_WIN__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000000fU)))
#define MDM_AGCSAT__CHECK_WIN__RESET_VALUE                          0x00000004U
/** @} */

/* macros for field thr_cnt */
/**
 * @defgroup mdm_regs_core_thr_cnt_field thr_cnt_field
 * @brief macros for field thr_cnt
 * @details Number of saturated I and Q samples (add up I and Q) needed to declare a saturated signal. Saturation will be declared if number of measurements is greater than or equal to thr_cnt
 * @{
 */
#define MDM_AGCSAT__THR_CNT__SHIFT                                            4
#define MDM_AGCSAT__THR_CNT__WIDTH                                            4
#define MDM_AGCSAT__THR_CNT__MASK                                   0x000000f0U
#define MDM_AGCSAT__THR_CNT__READ(src)   (((uint32_t)(src) & 0x000000f0U) >> 4)
#define MDM_AGCSAT__THR_CNT__WRITE(src)  (((uint32_t)(src) << 4) & 0x000000f0U)
#define MDM_AGCSAT__THR_CNT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000f0U) | (((uint32_t)(src) <<\
                    4) & 0x000000f0U)
#define MDM_AGCSAT__THR_CNT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x000000f0U)))
#define MDM_AGCSAT__THR_CNT__RESET_VALUE                            0x00000001U
/** @} */

/* macros for field check_thr_high */
/**
 * @defgroup mdm_regs_core_check_thr_high_field check_thr_high_field
 * @brief macros for field check_thr_high
 * @details High threshold. Signed, in units of ADC LSBs. An I or Q sample greater than or equal to check_thr_high is considered saturated.
 * @{
 */
#define MDM_AGCSAT__CHECK_THR_HIGH__SHIFT                                     8
#define MDM_AGCSAT__CHECK_THR_HIGH__WIDTH                                     8
#define MDM_AGCSAT__CHECK_THR_HIGH__MASK                            0x0000ff00U
#define MDM_AGCSAT__CHECK_THR_HIGH__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000ff00U) >> 8)
#define MDM_AGCSAT__CHECK_THR_HIGH__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x0000ff00U)
#define MDM_AGCSAT__CHECK_THR_HIGH__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000ff00U) | (((uint32_t)(src) <<\
                    8) & 0x0000ff00U)
#define MDM_AGCSAT__CHECK_THR_HIGH__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x0000ff00U)))
#define MDM_AGCSAT__CHECK_THR_HIGH__RESET_VALUE                     0x00000066U
/** @} */

/* macros for field check_thr_low */
/**
 * @defgroup mdm_regs_core_check_thr_low_field check_thr_low_field
 * @brief macros for field check_thr_low
 * @details Low threshold. Signed, in units of ADC LSBs. An I or Q sample less than or equal to check_thr_low is considered saturated. (Default 8'h9a = -102).
 * @{
 */
#define MDM_AGCSAT__CHECK_THR_LOW__SHIFT                                     16
#define MDM_AGCSAT__CHECK_THR_LOW__WIDTH                                      8
#define MDM_AGCSAT__CHECK_THR_LOW__MASK                             0x00ff0000U
#define MDM_AGCSAT__CHECK_THR_LOW__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00ff0000U) >> 16)
#define MDM_AGCSAT__CHECK_THR_LOW__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x00ff0000U)
#define MDM_AGCSAT__CHECK_THR_LOW__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00ff0000U) | (((uint32_t)(src) <<\
                    16) & 0x00ff0000U)
#define MDM_AGCSAT__CHECK_THR_LOW__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x00ff0000U)))
#define MDM_AGCSAT__CHECK_THR_LOW__RESET_VALUE                      0x0000009aU
/** @} */
#define MDM_AGCSAT__TYPE                                               uint32_t
#define MDM_AGCSAT__READ                                            0x00ffffffU
#define MDM_AGCSAT__WRITE                                           0x00ffffffU
#define MDM_AGCSAT__PRESERVED                                       0x00000000U
#define MDM_AGCSAT__RESET_VALUE                                     0x009a6614U

#endif /* __MDM_AGCSAT_MACRO__ */

/** @} end of agcsat */

/* macros for BlueprintGlobalNameSpace::MDM_agcsat_alt */
/**
 * @defgroup mdm_regs_core_agcsat_alt agcsat_alt
 * @brief Saturation control, alternate set definitions.
 * @{
 */
#ifndef __MDM_AGCSAT_ALT_MACRO__
#define __MDM_AGCSAT_ALT_MACRO__

/* macros for field check_win */
/**
 * @defgroup mdm_regs_core_check_win_field check_win_field
 * @brief macros for field check_win
 * @details Number of samples to measure for EACH of I and Q. Maximum allowed is 8. If set to 0, then saturation detection is disabled.
 * @{
 */
#define MDM_AGCSAT_ALT__CHECK_WIN__SHIFT                                      0
#define MDM_AGCSAT_ALT__CHECK_WIN__WIDTH                                      4
#define MDM_AGCSAT_ALT__CHECK_WIN__MASK                             0x0000000fU
#define MDM_AGCSAT_ALT__CHECK_WIN__READ(src)    ((uint32_t)(src) & 0x0000000fU)
#define MDM_AGCSAT_ALT__CHECK_WIN__WRITE(src)   ((uint32_t)(src) & 0x0000000fU)
#define MDM_AGCSAT_ALT__CHECK_WIN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000000fU) | ((uint32_t)(src) &\
                    0x0000000fU)
#define MDM_AGCSAT_ALT__CHECK_WIN__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000000fU)))
#define MDM_AGCSAT_ALT__CHECK_WIN__RESET_VALUE                      0x00000004U
/** @} */

/* macros for field thr_cnt */
/**
 * @defgroup mdm_regs_core_thr_cnt_field thr_cnt_field
 * @brief macros for field thr_cnt
 * @details Number of saturated I and Q samples (add up I and Q) needed to declare a saturated signal. Saturation will be declared if number of measurements is greater than or equal to thr_cnt
 * @{
 */
#define MDM_AGCSAT_ALT__THR_CNT__SHIFT                                        4
#define MDM_AGCSAT_ALT__THR_CNT__WIDTH                                        4
#define MDM_AGCSAT_ALT__THR_CNT__MASK                               0x000000f0U
#define MDM_AGCSAT_ALT__THR_CNT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000000f0U) >> 4)
#define MDM_AGCSAT_ALT__THR_CNT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x000000f0U)
#define MDM_AGCSAT_ALT__THR_CNT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000f0U) | (((uint32_t)(src) <<\
                    4) & 0x000000f0U)
#define MDM_AGCSAT_ALT__THR_CNT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x000000f0U)))
#define MDM_AGCSAT_ALT__THR_CNT__RESET_VALUE                        0x00000001U
/** @} */

/* macros for field check_thr_high */
/**
 * @defgroup mdm_regs_core_check_thr_high_field check_thr_high_field
 * @brief macros for field check_thr_high
 * @details High threshold. Signed, in units of ADC LSBs. An I or Q sample greater than or equal to check_thr_high is considered saturated.
 * @{
 */
#define MDM_AGCSAT_ALT__CHECK_THR_HIGH__SHIFT                                 8
#define MDM_AGCSAT_ALT__CHECK_THR_HIGH__WIDTH                                 8
#define MDM_AGCSAT_ALT__CHECK_THR_HIGH__MASK                        0x0000ff00U
#define MDM_AGCSAT_ALT__CHECK_THR_HIGH__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000ff00U) >> 8)
#define MDM_AGCSAT_ALT__CHECK_THR_HIGH__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x0000ff00U)
#define MDM_AGCSAT_ALT__CHECK_THR_HIGH__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000ff00U) | (((uint32_t)(src) <<\
                    8) & 0x0000ff00U)
#define MDM_AGCSAT_ALT__CHECK_THR_HIGH__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x0000ff00U)))
#define MDM_AGCSAT_ALT__CHECK_THR_HIGH__RESET_VALUE                 0x00000066U
/** @} */

/* macros for field check_thr_low */
/**
 * @defgroup mdm_regs_core_check_thr_low_field check_thr_low_field
 * @brief macros for field check_thr_low
 * @details Low threshold. Signed, in units of ADC LSBs. An I or Q sample less than or equal to check_thr_low is considered saturated. (Default 8'h9a = -102).
 * @{
 */
#define MDM_AGCSAT_ALT__CHECK_THR_LOW__SHIFT                                 16
#define MDM_AGCSAT_ALT__CHECK_THR_LOW__WIDTH                                  8
#define MDM_AGCSAT_ALT__CHECK_THR_LOW__MASK                         0x00ff0000U
#define MDM_AGCSAT_ALT__CHECK_THR_LOW__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00ff0000U) >> 16)
#define MDM_AGCSAT_ALT__CHECK_THR_LOW__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x00ff0000U)
#define MDM_AGCSAT_ALT__CHECK_THR_LOW__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00ff0000U) | (((uint32_t)(src) <<\
                    16) & 0x00ff0000U)
#define MDM_AGCSAT_ALT__CHECK_THR_LOW__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x00ff0000U)))
#define MDM_AGCSAT_ALT__CHECK_THR_LOW__RESET_VALUE                  0x0000009aU
/** @} */
#define MDM_AGCSAT_ALT__TYPE                                           uint32_t
#define MDM_AGCSAT_ALT__READ                                        0x00ffffffU
#define MDM_AGCSAT_ALT__WRITE                                       0x00ffffffU
#define MDM_AGCSAT_ALT__PRESERVED                                   0x00000000U
#define MDM_AGCSAT_ALT__RESET_VALUE                                 0x009a6614U

#endif /* __MDM_AGCSAT_ALT_MACRO__ */

/** @} end of agcsat_alt */

/* macros for BlueprintGlobalNameSpace::MDM_baseline */
/**
 * @defgroup mdm_regs_core_baseline baseline
 * @brief Thresholds for declaring a low baseline power, used in gain_delta calculation definitions.
 * @{
 */
#ifndef __MDM_BASELINE_MACRO__
#define __MDM_BASELINE_MACRO__

/* macros for field low_pwr_thr */
/**
 * @defgroup mdm_regs_core_low_pwr_thr_field low_pwr_thr_field
 * @brief macros for field low_pwr_thr
 * @details Signed. 1 Mb/s, 125 Kb/s and 500 Kb/s version. 8'hd6 = -42
 * @{
 */
#define MDM_BASELINE__LOW_PWR_THR__SHIFT                                      0
#define MDM_BASELINE__LOW_PWR_THR__WIDTH                                      8
#define MDM_BASELINE__LOW_PWR_THR__MASK                             0x000000ffU
#define MDM_BASELINE__LOW_PWR_THR__READ(src)    ((uint32_t)(src) & 0x000000ffU)
#define MDM_BASELINE__LOW_PWR_THR__WRITE(src)   ((uint32_t)(src) & 0x000000ffU)
#define MDM_BASELINE__LOW_PWR_THR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000ffU) | ((uint32_t)(src) &\
                    0x000000ffU)
#define MDM_BASELINE__LOW_PWR_THR__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000000ffU)))
#define MDM_BASELINE__LOW_PWR_THR__RESET_VALUE                      0x000000d6U
/** @} */

/* macros for field twomeg_low_pwr_thr */
/**
 * @defgroup mdm_regs_core_twomeg_low_pwr_thr_field twomeg_low_pwr_thr_field
 * @brief macros for field twomeg_low_pwr_thr
 * @details Signed. 2 Mb/s version. 8'hd9 = -39
 * @{
 */
#define MDM_BASELINE__TWOMEG_LOW_PWR_THR__SHIFT                               8
#define MDM_BASELINE__TWOMEG_LOW_PWR_THR__WIDTH                               8
#define MDM_BASELINE__TWOMEG_LOW_PWR_THR__MASK                      0x0000ff00U
#define MDM_BASELINE__TWOMEG_LOW_PWR_THR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000ff00U) >> 8)
#define MDM_BASELINE__TWOMEG_LOW_PWR_THR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x0000ff00U)
#define MDM_BASELINE__TWOMEG_LOW_PWR_THR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000ff00U) | (((uint32_t)(src) <<\
                    8) & 0x0000ff00U)
#define MDM_BASELINE__TWOMEG_LOW_PWR_THR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x0000ff00U)))
#define MDM_BASELINE__TWOMEG_LOW_PWR_THR__RESET_VALUE               0x000000d9U
/** @} */
#define MDM_BASELINE__TYPE                                             uint32_t
#define MDM_BASELINE__READ                                          0x0000ffffU
#define MDM_BASELINE__WRITE                                         0x0000ffffU
#define MDM_BASELINE__PRESERVED                                     0x00000000U
#define MDM_BASELINE__RESET_VALUE                                   0x0000d9d6U

#endif /* __MDM_BASELINE_MACRO__ */

/** @} end of baseline */

/* macros for BlueprintGlobalNameSpace::MDM_baseline_alt */
/**
 * @defgroup mdm_regs_core_baseline_alt baseline_alt
 * @brief Thresholds for declaring a low baseline power, used in gain_delta calculation, alternate set definitions.
 * @{
 */
#ifndef __MDM_BASELINE_ALT_MACRO__
#define __MDM_BASELINE_ALT_MACRO__

/* macros for field low_pwr_thr */
/**
 * @defgroup mdm_regs_core_low_pwr_thr_field low_pwr_thr_field
 * @brief macros for field low_pwr_thr
 * @details Signed. 1 Mb/s, 125 Kb/s and 500 Kb/s version. 8'hd6 = -42
 * @{
 */
#define MDM_BASELINE_ALT__LOW_PWR_THR__SHIFT                                  0
#define MDM_BASELINE_ALT__LOW_PWR_THR__WIDTH                                  8
#define MDM_BASELINE_ALT__LOW_PWR_THR__MASK                         0x000000ffU
#define MDM_BASELINE_ALT__LOW_PWR_THR__READ(src) \
                    ((uint32_t)(src)\
                    & 0x000000ffU)
#define MDM_BASELINE_ALT__LOW_PWR_THR__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x000000ffU)
#define MDM_BASELINE_ALT__LOW_PWR_THR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000ffU) | ((uint32_t)(src) &\
                    0x000000ffU)
#define MDM_BASELINE_ALT__LOW_PWR_THR__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000000ffU)))
#define MDM_BASELINE_ALT__LOW_PWR_THR__RESET_VALUE                  0x000000d6U
/** @} */

/* macros for field twomeg_low_pwr_thr */
/**
 * @defgroup mdm_regs_core_twomeg_low_pwr_thr_field twomeg_low_pwr_thr_field
 * @brief macros for field twomeg_low_pwr_thr
 * @details Signed. 2 Mb/s version. 8'hd9 = -39
 * @{
 */
#define MDM_BASELINE_ALT__TWOMEG_LOW_PWR_THR__SHIFT                           8
#define MDM_BASELINE_ALT__TWOMEG_LOW_PWR_THR__WIDTH                           8
#define MDM_BASELINE_ALT__TWOMEG_LOW_PWR_THR__MASK                  0x0000ff00U
#define MDM_BASELINE_ALT__TWOMEG_LOW_PWR_THR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000ff00U) >> 8)
#define MDM_BASELINE_ALT__TWOMEG_LOW_PWR_THR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x0000ff00U)
#define MDM_BASELINE_ALT__TWOMEG_LOW_PWR_THR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000ff00U) | (((uint32_t)(src) <<\
                    8) & 0x0000ff00U)
#define MDM_BASELINE_ALT__TWOMEG_LOW_PWR_THR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x0000ff00U)))
#define MDM_BASELINE_ALT__TWOMEG_LOW_PWR_THR__RESET_VALUE           0x000000d9U
/** @} */
#define MDM_BASELINE_ALT__TYPE                                         uint32_t
#define MDM_BASELINE_ALT__READ                                      0x0000ffffU
#define MDM_BASELINE_ALT__WRITE                                     0x0000ffffU
#define MDM_BASELINE_ALT__PRESERVED                                 0x00000000U
#define MDM_BASELINE_ALT__RESET_VALUE                               0x0000d9d6U

#endif /* __MDM_BASELINE_ALT_MACRO__ */

/** @} end of baseline_alt */

/* macros for BlueprintGlobalNameSpace::MDM_margin */
/**
 * @defgroup mdm_regs_core_margin margin
 * @brief Adjustment to gain_delta when blocker is present and inband power is low definitions.
 * @{
 */
#ifndef __MDM_MARGIN_MACRO__
#define __MDM_MARGIN_MACRO__

/* macros for field adc_max_low_inband_pwr */
/**
 * @defgroup mdm_regs_core_adc_max_low_inband_pwr_field adc_max_low_inband_pwr_field
 * @brief macros for field adc_max_low_inband_pwr
 * @details Signed. 1 Mb/s, 125 Kb/s and 500 Kb/s version
 * @{
 */
#define MDM_MARGIN__ADC_MAX_LOW_INBAND_PWR__SHIFT                             0
#define MDM_MARGIN__ADC_MAX_LOW_INBAND_PWR__WIDTH                             6
#define MDM_MARGIN__ADC_MAX_LOW_INBAND_PWR__MASK                    0x0000003fU
#define MDM_MARGIN__ADC_MAX_LOW_INBAND_PWR__READ(src) \
                    ((uint32_t)(src)\
                    & 0x0000003fU)
#define MDM_MARGIN__ADC_MAX_LOW_INBAND_PWR__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000003fU)
#define MDM_MARGIN__ADC_MAX_LOW_INBAND_PWR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000003fU) | ((uint32_t)(src) &\
                    0x0000003fU)
#define MDM_MARGIN__ADC_MAX_LOW_INBAND_PWR__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000003fU)))
#define MDM_MARGIN__ADC_MAX_LOW_INBAND_PWR__RESET_VALUE             0x00000004U
/** @} */

/* macros for field twomeg_adc_max_low_inband_pwr */
/**
 * @defgroup mdm_regs_core_twomeg_adc_max_low_inband_pwr_field twomeg_adc_max_low_inband_pwr_field
 * @brief macros for field twomeg_adc_max_low_inband_pwr
 * @details Signed. 1 Mb/s, 125 Kb/s and 500 Kb/s version
 * @{
 */
#define MDM_MARGIN__TWOMEG_ADC_MAX_LOW_INBAND_PWR__SHIFT                      6
#define MDM_MARGIN__TWOMEG_ADC_MAX_LOW_INBAND_PWR__WIDTH                      6
#define MDM_MARGIN__TWOMEG_ADC_MAX_LOW_INBAND_PWR__MASK             0x00000fc0U
#define MDM_MARGIN__TWOMEG_ADC_MAX_LOW_INBAND_PWR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000fc0U) >> 6)
#define MDM_MARGIN__TWOMEG_ADC_MAX_LOW_INBAND_PWR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 6) & 0x00000fc0U)
#define MDM_MARGIN__TWOMEG_ADC_MAX_LOW_INBAND_PWR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000fc0U) | (((uint32_t)(src) <<\
                    6) & 0x00000fc0U)
#define MDM_MARGIN__TWOMEG_ADC_MAX_LOW_INBAND_PWR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 6) & ~0x00000fc0U)))
#define MDM_MARGIN__TWOMEG_ADC_MAX_LOW_INBAND_PWR__RESET_VALUE      0x00000006U
/** @} */

/* macros for field strong_blocker_thr */
/**
 * @defgroup mdm_regs_core_strong_blocker_thr_field strong_blocker_thr_field
 * @brief macros for field strong_blocker_thr
 * @details Signed. For bit in agcstatus register, strong_blocker = (total_pwr - baseline_pwr) > cf_margin_strong_blocker_thr
 * @{
 */
#define MDM_MARGIN__STRONG_BLOCKER_THR__SHIFT                                12
#define MDM_MARGIN__STRONG_BLOCKER_THR__WIDTH                                 8
#define MDM_MARGIN__STRONG_BLOCKER_THR__MASK                        0x000ff000U
#define MDM_MARGIN__STRONG_BLOCKER_THR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000ff000U) >> 12)
#define MDM_MARGIN__STRONG_BLOCKER_THR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x000ff000U)
#define MDM_MARGIN__STRONG_BLOCKER_THR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000ff000U) | (((uint32_t)(src) <<\
                    12) & 0x000ff000U)
#define MDM_MARGIN__STRONG_BLOCKER_THR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x000ff000U)))
#define MDM_MARGIN__STRONG_BLOCKER_THR__RESET_VALUE                 0x00000009U
/** @} */
#define MDM_MARGIN__TYPE                                               uint32_t
#define MDM_MARGIN__READ                                            0x000fffffU
#define MDM_MARGIN__WRITE                                           0x000fffffU
#define MDM_MARGIN__PRESERVED                                       0x00000000U
#define MDM_MARGIN__RESET_VALUE                                     0x00009184U

#endif /* __MDM_MARGIN_MACRO__ */

/** @} end of margin */

/* macros for BlueprintGlobalNameSpace::MDM_margin_alt */
/**
 * @defgroup mdm_regs_core_margin_alt margin_alt
 * @brief Adjustment to gain_delta when blocker is present and inband power is low, alternate set definitions.
 * @{
 */
#ifndef __MDM_MARGIN_ALT_MACRO__
#define __MDM_MARGIN_ALT_MACRO__

/* macros for field adc_max_low_inband_pwr */
/**
 * @defgroup mdm_regs_core_adc_max_low_inband_pwr_field adc_max_low_inband_pwr_field
 * @brief macros for field adc_max_low_inband_pwr
 * @details Signed. 1 Mb/s, 125 Kb/s and 500 Kb/s version
 * @{
 */
#define MDM_MARGIN_ALT__ADC_MAX_LOW_INBAND_PWR__SHIFT                         0
#define MDM_MARGIN_ALT__ADC_MAX_LOW_INBAND_PWR__WIDTH                         6
#define MDM_MARGIN_ALT__ADC_MAX_LOW_INBAND_PWR__MASK                0x0000003fU
#define MDM_MARGIN_ALT__ADC_MAX_LOW_INBAND_PWR__READ(src) \
                    ((uint32_t)(src)\
                    & 0x0000003fU)
#define MDM_MARGIN_ALT__ADC_MAX_LOW_INBAND_PWR__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000003fU)
#define MDM_MARGIN_ALT__ADC_MAX_LOW_INBAND_PWR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000003fU) | ((uint32_t)(src) &\
                    0x0000003fU)
#define MDM_MARGIN_ALT__ADC_MAX_LOW_INBAND_PWR__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000003fU)))
#define MDM_MARGIN_ALT__ADC_MAX_LOW_INBAND_PWR__RESET_VALUE         0x00000004U
/** @} */

/* macros for field twomeg_adc_max_low_inband_pwr */
/**
 * @defgroup mdm_regs_core_twomeg_adc_max_low_inband_pwr_field twomeg_adc_max_low_inband_pwr_field
 * @brief macros for field twomeg_adc_max_low_inband_pwr
 * @details Signed. 1 Mb/s, 125 Kb/s and 500 Kb/s version
 * @{
 */
#define MDM_MARGIN_ALT__TWOMEG_ADC_MAX_LOW_INBAND_PWR__SHIFT                  6
#define MDM_MARGIN_ALT__TWOMEG_ADC_MAX_LOW_INBAND_PWR__WIDTH                  6
#define MDM_MARGIN_ALT__TWOMEG_ADC_MAX_LOW_INBAND_PWR__MASK         0x00000fc0U
#define MDM_MARGIN_ALT__TWOMEG_ADC_MAX_LOW_INBAND_PWR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000fc0U) >> 6)
#define MDM_MARGIN_ALT__TWOMEG_ADC_MAX_LOW_INBAND_PWR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 6) & 0x00000fc0U)
#define MDM_MARGIN_ALT__TWOMEG_ADC_MAX_LOW_INBAND_PWR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000fc0U) | (((uint32_t)(src) <<\
                    6) & 0x00000fc0U)
#define MDM_MARGIN_ALT__TWOMEG_ADC_MAX_LOW_INBAND_PWR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 6) & ~0x00000fc0U)))
#define MDM_MARGIN_ALT__TWOMEG_ADC_MAX_LOW_INBAND_PWR__RESET_VALUE  0x00000006U
/** @} */

/* macros for field strong_blocker_thr */
/**
 * @defgroup mdm_regs_core_strong_blocker_thr_field strong_blocker_thr_field
 * @brief macros for field strong_blocker_thr
 * @details Signed. For bit in agcstatus register, strong_blocker = (total_pwr - baseline_pwr) > cf_margin_strong_blocker_thr
 * @{
 */
#define MDM_MARGIN_ALT__STRONG_BLOCKER_THR__SHIFT                            12
#define MDM_MARGIN_ALT__STRONG_BLOCKER_THR__WIDTH                             8
#define MDM_MARGIN_ALT__STRONG_BLOCKER_THR__MASK                    0x000ff000U
#define MDM_MARGIN_ALT__STRONG_BLOCKER_THR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000ff000U) >> 12)
#define MDM_MARGIN_ALT__STRONG_BLOCKER_THR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x000ff000U)
#define MDM_MARGIN_ALT__STRONG_BLOCKER_THR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000ff000U) | (((uint32_t)(src) <<\
                    12) & 0x000ff000U)
#define MDM_MARGIN_ALT__STRONG_BLOCKER_THR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x000ff000U)))
#define MDM_MARGIN_ALT__STRONG_BLOCKER_THR__RESET_VALUE             0x00000009U
/** @} */
#define MDM_MARGIN_ALT__TYPE                                           uint32_t
#define MDM_MARGIN_ALT__READ                                        0x000fffffU
#define MDM_MARGIN_ALT__WRITE                                       0x000fffffU
#define MDM_MARGIN_ALT__PRESERVED                                   0x00000000U
#define MDM_MARGIN_ALT__RESET_VALUE                                 0x00009184U

#endif /* __MDM_MARGIN_ALT_MACRO__ */

/** @} end of margin_alt */

/* macros for BlueprintGlobalNameSpace::MDM_pwrstep */
/**
 * @defgroup mdm_regs_core_pwrstep pwrstep
 * @brief Control for power step detection definitions.
 * @{
 */
#ifndef __MDM_PWRSTEP_MACRO__
#define __MDM_PWRSTEP_MACRO__

/* macros for field baseline_meas_dur */
/**
 * @defgroup mdm_regs_core_baseline_meas_dur_field baseline_meas_dur_field
 * @brief macros for field baseline_meas_dur
 * @details 2'b00 -> 16; 2'b01 -> 24; 2'b10 -> 32; 2'b11 -> 40
 * @{
 */
#define MDM_PWRSTEP__BASELINE_MEAS_DUR__SHIFT                                 0
#define MDM_PWRSTEP__BASELINE_MEAS_DUR__WIDTH                                 2
#define MDM_PWRSTEP__BASELINE_MEAS_DUR__MASK                        0x00000003U
#define MDM_PWRSTEP__BASELINE_MEAS_DUR__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000003U)
#define MDM_PWRSTEP__BASELINE_MEAS_DUR__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000003U)
#define MDM_PWRSTEP__BASELINE_MEAS_DUR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000003U) | ((uint32_t)(src) &\
                    0x00000003U)
#define MDM_PWRSTEP__BASELINE_MEAS_DUR__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000003U)))
#define MDM_PWRSTEP__BASELINE_MEAS_DUR__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field baseline_meas_delay */
/**
 * @defgroup mdm_regs_core_baseline_meas_delay_field baseline_meas_delay_field
 * @brief macros for field baseline_meas_delay
 * @details Number of clocks between baseline and inband_pwr to compare 2'b00 -> 4; 2'b01 -> 8; 2'b10 -> 12; 2'b11 -> 16
 * @{
 */
#define MDM_PWRSTEP__BASELINE_MEAS_DELAY__SHIFT                               2
#define MDM_PWRSTEP__BASELINE_MEAS_DELAY__WIDTH                               2
#define MDM_PWRSTEP__BASELINE_MEAS_DELAY__MASK                      0x0000000cU
#define MDM_PWRSTEP__BASELINE_MEAS_DELAY__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000000cU) >> 2)
#define MDM_PWRSTEP__BASELINE_MEAS_DELAY__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x0000000cU)
#define MDM_PWRSTEP__BASELINE_MEAS_DELAY__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000000cU) | (((uint32_t)(src) <<\
                    2) & 0x0000000cU)
#define MDM_PWRSTEP__BASELINE_MEAS_DELAY__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x0000000cU)))
#define MDM_PWRSTEP__BASELINE_MEAS_DELAY__RESET_VALUE               0x00000001U
/** @} */

/* macros for field cnt */
/**
 * @defgroup mdm_regs_core_cnt_field cnt_field
 * @brief macros for field cnt
 * @details Number of most recent power delta values to use
 * @{
 */
#define MDM_PWRSTEP__CNT__SHIFT                                               4
#define MDM_PWRSTEP__CNT__WIDTH                                               4
#define MDM_PWRSTEP__CNT__MASK                                      0x000000f0U
#define MDM_PWRSTEP__CNT__READ(src)      (((uint32_t)(src) & 0x000000f0U) >> 4)
#define MDM_PWRSTEP__CNT__WRITE(src)     (((uint32_t)(src) << 4) & 0x000000f0U)
#define MDM_PWRSTEP__CNT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000f0U) | (((uint32_t)(src) <<\
                    4) & 0x000000f0U)
#define MDM_PWRSTEP__CNT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x000000f0U)))
#define MDM_PWRSTEP__CNT__RESET_VALUE                               0x00000008U
/** @} */

/* macros for field cnt_thr */
/**
 * @defgroup mdm_regs_core_cnt_thr_field cnt_thr_field
 * @brief macros for field cnt_thr
 * @details Out of the cnt values, how many needed to declare power step
 * @{
 */
#define MDM_PWRSTEP__CNT_THR__SHIFT                                           8
#define MDM_PWRSTEP__CNT_THR__WIDTH                                           4
#define MDM_PWRSTEP__CNT_THR__MASK                                  0x00000f00U
#define MDM_PWRSTEP__CNT_THR__READ(src)  (((uint32_t)(src) & 0x00000f00U) >> 8)
#define MDM_PWRSTEP__CNT_THR__WRITE(src) (((uint32_t)(src) << 8) & 0x00000f00U)
#define MDM_PWRSTEP__CNT_THR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000f00U) | (((uint32_t)(src) <<\
                    8) & 0x00000f00U)
#define MDM_PWRSTEP__CNT_THR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00000f00U)))
#define MDM_PWRSTEP__CNT_THR__RESET_VALUE                           0x00000006U
/** @} */

/* macros for field hyst_thr */
/**
 * @defgroup mdm_regs_core_hyst_thr_field hyst_thr_field
 * @brief macros for field hyst_thr
 * @details Power step hysteresis threshold
 * @{
 */
#define MDM_PWRSTEP__HYST_THR__SHIFT                                         12
#define MDM_PWRSTEP__HYST_THR__WIDTH                                          4
#define MDM_PWRSTEP__HYST_THR__MASK                                 0x0000f000U
#define MDM_PWRSTEP__HYST_THR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000f000U) >> 12)
#define MDM_PWRSTEP__HYST_THR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x0000f000U)
#define MDM_PWRSTEP__HYST_THR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000f000U) | (((uint32_t)(src) <<\
                    12) & 0x0000f000U)
#define MDM_PWRSTEP__HYST_THR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x0000f000U)))
#define MDM_PWRSTEP__HYST_THR__RESET_VALUE                          0x00000004U
/** @} */

/* macros for field disable_hyst_for_blocker */
/**
 * @defgroup mdm_regs_core_disable_hyst_for_blocker_field disable_hyst_for_blocker_field
 * @brief macros for field disable_hyst_for_blocker
 * @details If bit is set and there is a strong blocker, do not require hst_thr criteria to be met to declare a power step
 * @{
 */
#define MDM_PWRSTEP__DISABLE_HYST_FOR_BLOCKER__SHIFT                         16
#define MDM_PWRSTEP__DISABLE_HYST_FOR_BLOCKER__WIDTH                          1
#define MDM_PWRSTEP__DISABLE_HYST_FOR_BLOCKER__MASK                 0x00010000U
#define MDM_PWRSTEP__DISABLE_HYST_FOR_BLOCKER__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00010000U) >> 16)
#define MDM_PWRSTEP__DISABLE_HYST_FOR_BLOCKER__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x00010000U)
#define MDM_PWRSTEP__DISABLE_HYST_FOR_BLOCKER__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | (((uint32_t)(src) <<\
                    16) & 0x00010000U)
#define MDM_PWRSTEP__DISABLE_HYST_FOR_BLOCKER__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x00010000U)))
#define MDM_PWRSTEP__DISABLE_HYST_FOR_BLOCKER__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | ((uint32_t)(1) << 16)
#define MDM_PWRSTEP__DISABLE_HYST_FOR_BLOCKER__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | ((uint32_t)(0) << 16)
#define MDM_PWRSTEP__DISABLE_HYST_FOR_BLOCKER__RESET_VALUE          0x00000001U
/** @} */

/* macros for field twomeg_baseline_meas_dur */
/**
 * @defgroup mdm_regs_core_twomeg_baseline_meas_dur_field twomeg_baseline_meas_dur_field
 * @brief macros for field twomeg_baseline_meas_dur
 * @details 2'b00 -> 16; 2'b01 -> 24; 2'b10 -> 32; 2'b11 -> 40. 2M rate
 * @{
 */
#define MDM_PWRSTEP__TWOMEG_BASELINE_MEAS_DUR__SHIFT                         17
#define MDM_PWRSTEP__TWOMEG_BASELINE_MEAS_DUR__WIDTH                          2
#define MDM_PWRSTEP__TWOMEG_BASELINE_MEAS_DUR__MASK                 0x00060000U
#define MDM_PWRSTEP__TWOMEG_BASELINE_MEAS_DUR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00060000U) >> 17)
#define MDM_PWRSTEP__TWOMEG_BASELINE_MEAS_DUR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 17) & 0x00060000U)
#define MDM_PWRSTEP__TWOMEG_BASELINE_MEAS_DUR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00060000U) | (((uint32_t)(src) <<\
                    17) & 0x00060000U)
#define MDM_PWRSTEP__TWOMEG_BASELINE_MEAS_DUR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 17) & ~0x00060000U)))
#define MDM_PWRSTEP__TWOMEG_BASELINE_MEAS_DUR__RESET_VALUE          0x00000002U
/** @} */

/* macros for field twomeg_baseline_meas_delay */
/**
 * @defgroup mdm_regs_core_twomeg_baseline_meas_delay_field twomeg_baseline_meas_delay_field
 * @brief macros for field twomeg_baseline_meas_delay
 * @details Number of clocks between baseline and inband_pwr to compare 2'b00 -> 4; 2'b01 -> 8; 2'b10 -> 12; 2'b11 -> 16. 2M rate
 * @{
 */
#define MDM_PWRSTEP__TWOMEG_BASELINE_MEAS_DELAY__SHIFT                       19
#define MDM_PWRSTEP__TWOMEG_BASELINE_MEAS_DELAY__WIDTH                        2
#define MDM_PWRSTEP__TWOMEG_BASELINE_MEAS_DELAY__MASK               0x00180000U
#define MDM_PWRSTEP__TWOMEG_BASELINE_MEAS_DELAY__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00180000U) >> 19)
#define MDM_PWRSTEP__TWOMEG_BASELINE_MEAS_DELAY__WRITE(src) \
                    (((uint32_t)(src)\
                    << 19) & 0x00180000U)
#define MDM_PWRSTEP__TWOMEG_BASELINE_MEAS_DELAY__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00180000U) | (((uint32_t)(src) <<\
                    19) & 0x00180000U)
#define MDM_PWRSTEP__TWOMEG_BASELINE_MEAS_DELAY__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 19) & ~0x00180000U)))
#define MDM_PWRSTEP__TWOMEG_BASELINE_MEAS_DELAY__RESET_VALUE        0x00000001U
/** @} */

/* macros for field separate_pos_and_neg */
/**
 * @defgroup mdm_regs_core_separate_pos_and_neg_field separate_pos_and_neg_field
 * @brief macros for field separate_pos_and_neg
 * @details If bit is set, threshold positive and negative power steps separately
 * @{
 */
#define MDM_PWRSTEP__SEPARATE_POS_AND_NEG__SHIFT                             21
#define MDM_PWRSTEP__SEPARATE_POS_AND_NEG__WIDTH                              1
#define MDM_PWRSTEP__SEPARATE_POS_AND_NEG__MASK                     0x00200000U
#define MDM_PWRSTEP__SEPARATE_POS_AND_NEG__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00200000U) >> 21)
#define MDM_PWRSTEP__SEPARATE_POS_AND_NEG__WRITE(src) \
                    (((uint32_t)(src)\
                    << 21) & 0x00200000U)
#define MDM_PWRSTEP__SEPARATE_POS_AND_NEG__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00200000U) | (((uint32_t)(src) <<\
                    21) & 0x00200000U)
#define MDM_PWRSTEP__SEPARATE_POS_AND_NEG__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 21) & ~0x00200000U)))
#define MDM_PWRSTEP__SEPARATE_POS_AND_NEG__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00200000U) | ((uint32_t)(1) << 21)
#define MDM_PWRSTEP__SEPARATE_POS_AND_NEG__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00200000U) | ((uint32_t)(0) << 21)
#define MDM_PWRSTEP__SEPARATE_POS_AND_NEG__RESET_VALUE              0x00000000U
/** @} */
#define MDM_PWRSTEP__TYPE                                              uint32_t
#define MDM_PWRSTEP__READ                                           0x003fffffU
#define MDM_PWRSTEP__WRITE                                          0x003fffffU
#define MDM_PWRSTEP__PRESERVED                                      0x00000000U
#define MDM_PWRSTEP__RESET_VALUE                                    0x000d4684U

#endif /* __MDM_PWRSTEP_MACRO__ */

/** @} end of pwrstep */

/* macros for BlueprintGlobalNameSpace::MDM_pwrstep_alt */
/**
 * @defgroup mdm_regs_core_pwrstep_alt pwrstep_alt
 * @brief Control for power step detection, alternate set definitions.
 * @{
 */
#ifndef __MDM_PWRSTEP_ALT_MACRO__
#define __MDM_PWRSTEP_ALT_MACRO__

/* macros for field baseline_meas_dur */
/**
 * @defgroup mdm_regs_core_baseline_meas_dur_field baseline_meas_dur_field
 * @brief macros for field baseline_meas_dur
 * @details 2'b00 -> 16; 2'b01 -> 24; 2'b10 -> 32; 2'b11 -> 40
 * @{
 */
#define MDM_PWRSTEP_ALT__BASELINE_MEAS_DUR__SHIFT                             0
#define MDM_PWRSTEP_ALT__BASELINE_MEAS_DUR__WIDTH                             2
#define MDM_PWRSTEP_ALT__BASELINE_MEAS_DUR__MASK                    0x00000003U
#define MDM_PWRSTEP_ALT__BASELINE_MEAS_DUR__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000003U)
#define MDM_PWRSTEP_ALT__BASELINE_MEAS_DUR__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000003U)
#define MDM_PWRSTEP_ALT__BASELINE_MEAS_DUR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000003U) | ((uint32_t)(src) &\
                    0x00000003U)
#define MDM_PWRSTEP_ALT__BASELINE_MEAS_DUR__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000003U)))
#define MDM_PWRSTEP_ALT__BASELINE_MEAS_DUR__RESET_VALUE             0x00000000U
/** @} */

/* macros for field baseline_meas_delay */
/**
 * @defgroup mdm_regs_core_baseline_meas_delay_field baseline_meas_delay_field
 * @brief macros for field baseline_meas_delay
 * @details Number of clocks between baseline and inband_pwr to compare 2'b00 -> 4; 2'b01 -> 8; 2'b10 -> 12; 2'b11 -> 16
 * @{
 */
#define MDM_PWRSTEP_ALT__BASELINE_MEAS_DELAY__SHIFT                           2
#define MDM_PWRSTEP_ALT__BASELINE_MEAS_DELAY__WIDTH                           2
#define MDM_PWRSTEP_ALT__BASELINE_MEAS_DELAY__MASK                  0x0000000cU
#define MDM_PWRSTEP_ALT__BASELINE_MEAS_DELAY__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000000cU) >> 2)
#define MDM_PWRSTEP_ALT__BASELINE_MEAS_DELAY__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x0000000cU)
#define MDM_PWRSTEP_ALT__BASELINE_MEAS_DELAY__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000000cU) | (((uint32_t)(src) <<\
                    2) & 0x0000000cU)
#define MDM_PWRSTEP_ALT__BASELINE_MEAS_DELAY__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x0000000cU)))
#define MDM_PWRSTEP_ALT__BASELINE_MEAS_DELAY__RESET_VALUE           0x00000001U
/** @} */

/* macros for field cnt */
/**
 * @defgroup mdm_regs_core_cnt_field cnt_field
 * @brief macros for field cnt
 * @details Number of most recent power delta values to use
 * @{
 */
#define MDM_PWRSTEP_ALT__CNT__SHIFT                                           4
#define MDM_PWRSTEP_ALT__CNT__WIDTH                                           4
#define MDM_PWRSTEP_ALT__CNT__MASK                                  0x000000f0U
#define MDM_PWRSTEP_ALT__CNT__READ(src)  (((uint32_t)(src) & 0x000000f0U) >> 4)
#define MDM_PWRSTEP_ALT__CNT__WRITE(src) (((uint32_t)(src) << 4) & 0x000000f0U)
#define MDM_PWRSTEP_ALT__CNT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000f0U) | (((uint32_t)(src) <<\
                    4) & 0x000000f0U)
#define MDM_PWRSTEP_ALT__CNT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x000000f0U)))
#define MDM_PWRSTEP_ALT__CNT__RESET_VALUE                           0x00000008U
/** @} */

/* macros for field cnt_thr */
/**
 * @defgroup mdm_regs_core_cnt_thr_field cnt_thr_field
 * @brief macros for field cnt_thr
 * @details Out of the cnt values, how many needed to declare power step
 * @{
 */
#define MDM_PWRSTEP_ALT__CNT_THR__SHIFT                                       8
#define MDM_PWRSTEP_ALT__CNT_THR__WIDTH                                       4
#define MDM_PWRSTEP_ALT__CNT_THR__MASK                              0x00000f00U
#define MDM_PWRSTEP_ALT__CNT_THR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000f00U) >> 8)
#define MDM_PWRSTEP_ALT__CNT_THR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00000f00U)
#define MDM_PWRSTEP_ALT__CNT_THR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000f00U) | (((uint32_t)(src) <<\
                    8) & 0x00000f00U)
#define MDM_PWRSTEP_ALT__CNT_THR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00000f00U)))
#define MDM_PWRSTEP_ALT__CNT_THR__RESET_VALUE                       0x00000006U
/** @} */

/* macros for field hyst_thr */
/**
 * @defgroup mdm_regs_core_hyst_thr_field hyst_thr_field
 * @brief macros for field hyst_thr
 * @details Power step hysteresis threshold
 * @{
 */
#define MDM_PWRSTEP_ALT__HYST_THR__SHIFT                                     12
#define MDM_PWRSTEP_ALT__HYST_THR__WIDTH                                      4
#define MDM_PWRSTEP_ALT__HYST_THR__MASK                             0x0000f000U
#define MDM_PWRSTEP_ALT__HYST_THR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000f000U) >> 12)
#define MDM_PWRSTEP_ALT__HYST_THR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x0000f000U)
#define MDM_PWRSTEP_ALT__HYST_THR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000f000U) | (((uint32_t)(src) <<\
                    12) & 0x0000f000U)
#define MDM_PWRSTEP_ALT__HYST_THR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x0000f000U)))
#define MDM_PWRSTEP_ALT__HYST_THR__RESET_VALUE                      0x00000004U
/** @} */

/* macros for field disable_hyst_for_blocker */
/**
 * @defgroup mdm_regs_core_disable_hyst_for_blocker_field disable_hyst_for_blocker_field
 * @brief macros for field disable_hyst_for_blocker
 * @details If bit is set and there is a strong blocker, do not require hst_thr criteria to be met to declare a power step
 * @{
 */
#define MDM_PWRSTEP_ALT__DISABLE_HYST_FOR_BLOCKER__SHIFT                     16
#define MDM_PWRSTEP_ALT__DISABLE_HYST_FOR_BLOCKER__WIDTH                      1
#define MDM_PWRSTEP_ALT__DISABLE_HYST_FOR_BLOCKER__MASK             0x00010000U
#define MDM_PWRSTEP_ALT__DISABLE_HYST_FOR_BLOCKER__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00010000U) >> 16)
#define MDM_PWRSTEP_ALT__DISABLE_HYST_FOR_BLOCKER__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x00010000U)
#define MDM_PWRSTEP_ALT__DISABLE_HYST_FOR_BLOCKER__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | (((uint32_t)(src) <<\
                    16) & 0x00010000U)
#define MDM_PWRSTEP_ALT__DISABLE_HYST_FOR_BLOCKER__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x00010000U)))
#define MDM_PWRSTEP_ALT__DISABLE_HYST_FOR_BLOCKER__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | ((uint32_t)(1) << 16)
#define MDM_PWRSTEP_ALT__DISABLE_HYST_FOR_BLOCKER__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | ((uint32_t)(0) << 16)
#define MDM_PWRSTEP_ALT__DISABLE_HYST_FOR_BLOCKER__RESET_VALUE      0x00000001U
/** @} */

/* macros for field twomeg_baseline_meas_dur */
/**
 * @defgroup mdm_regs_core_twomeg_baseline_meas_dur_field twomeg_baseline_meas_dur_field
 * @brief macros for field twomeg_baseline_meas_dur
 * @details 2'b00 -> 16; 2'b01 -> 24; 2'b10 -> 32; 2'b11 -> 40. 2M rate
 * @{
 */
#define MDM_PWRSTEP_ALT__TWOMEG_BASELINE_MEAS_DUR__SHIFT                     17
#define MDM_PWRSTEP_ALT__TWOMEG_BASELINE_MEAS_DUR__WIDTH                      2
#define MDM_PWRSTEP_ALT__TWOMEG_BASELINE_MEAS_DUR__MASK             0x00060000U
#define MDM_PWRSTEP_ALT__TWOMEG_BASELINE_MEAS_DUR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00060000U) >> 17)
#define MDM_PWRSTEP_ALT__TWOMEG_BASELINE_MEAS_DUR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 17) & 0x00060000U)
#define MDM_PWRSTEP_ALT__TWOMEG_BASELINE_MEAS_DUR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00060000U) | (((uint32_t)(src) <<\
                    17) & 0x00060000U)
#define MDM_PWRSTEP_ALT__TWOMEG_BASELINE_MEAS_DUR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 17) & ~0x00060000U)))
#define MDM_PWRSTEP_ALT__TWOMEG_BASELINE_MEAS_DUR__RESET_VALUE      0x00000002U
/** @} */

/* macros for field twomeg_baseline_meas_delay */
/**
 * @defgroup mdm_regs_core_twomeg_baseline_meas_delay_field twomeg_baseline_meas_delay_field
 * @brief macros for field twomeg_baseline_meas_delay
 * @details Number of clocks between baseline and inband_pwr to compare 2'b00 -> 4; 2'b01 -> 8; 2'b10 -> 12; 2'b11 -> 16. 2M rate
 * @{
 */
#define MDM_PWRSTEP_ALT__TWOMEG_BASELINE_MEAS_DELAY__SHIFT                   19
#define MDM_PWRSTEP_ALT__TWOMEG_BASELINE_MEAS_DELAY__WIDTH                    2
#define MDM_PWRSTEP_ALT__TWOMEG_BASELINE_MEAS_DELAY__MASK           0x00180000U
#define MDM_PWRSTEP_ALT__TWOMEG_BASELINE_MEAS_DELAY__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00180000U) >> 19)
#define MDM_PWRSTEP_ALT__TWOMEG_BASELINE_MEAS_DELAY__WRITE(src) \
                    (((uint32_t)(src)\
                    << 19) & 0x00180000U)
#define MDM_PWRSTEP_ALT__TWOMEG_BASELINE_MEAS_DELAY__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00180000U) | (((uint32_t)(src) <<\
                    19) & 0x00180000U)
#define MDM_PWRSTEP_ALT__TWOMEG_BASELINE_MEAS_DELAY__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 19) & ~0x00180000U)))
#define MDM_PWRSTEP_ALT__TWOMEG_BASELINE_MEAS_DELAY__RESET_VALUE    0x00000001U
/** @} */

/* macros for field separate_pos_and_neg */
/**
 * @defgroup mdm_regs_core_separate_pos_and_neg_field separate_pos_and_neg_field
 * @brief macros for field separate_pos_and_neg
 * @details If bit is set, threshold positive and negative power steps separately
 * @{
 */
#define MDM_PWRSTEP_ALT__SEPARATE_POS_AND_NEG__SHIFT                         21
#define MDM_PWRSTEP_ALT__SEPARATE_POS_AND_NEG__WIDTH                          1
#define MDM_PWRSTEP_ALT__SEPARATE_POS_AND_NEG__MASK                 0x00200000U
#define MDM_PWRSTEP_ALT__SEPARATE_POS_AND_NEG__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00200000U) >> 21)
#define MDM_PWRSTEP_ALT__SEPARATE_POS_AND_NEG__WRITE(src) \
                    (((uint32_t)(src)\
                    << 21) & 0x00200000U)
#define MDM_PWRSTEP_ALT__SEPARATE_POS_AND_NEG__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00200000U) | (((uint32_t)(src) <<\
                    21) & 0x00200000U)
#define MDM_PWRSTEP_ALT__SEPARATE_POS_AND_NEG__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 21) & ~0x00200000U)))
#define MDM_PWRSTEP_ALT__SEPARATE_POS_AND_NEG__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00200000U) | ((uint32_t)(1) << 21)
#define MDM_PWRSTEP_ALT__SEPARATE_POS_AND_NEG__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00200000U) | ((uint32_t)(0) << 21)
#define MDM_PWRSTEP_ALT__SEPARATE_POS_AND_NEG__RESET_VALUE          0x00000000U
/** @} */
#define MDM_PWRSTEP_ALT__TYPE                                          uint32_t
#define MDM_PWRSTEP_ALT__READ                                       0x003fffffU
#define MDM_PWRSTEP_ALT__WRITE                                      0x003fffffU
#define MDM_PWRSTEP_ALT__PRESERVED                                  0x00000000U
#define MDM_PWRSTEP_ALT__RESET_VALUE                                0x000d4684U

#endif /* __MDM_PWRSTEP_ALT_MACRO__ */

/** @} end of pwrstep_alt */

/* macros for BlueprintGlobalNameSpace::MDM_agcpwr */
/**
 * @defgroup mdm_regs_core_agcpwr agcpwr
 * @brief Power measurement targets definitions.
 * @{
 */
#ifndef __MDM_AGCPWR_MACRO__
#define __MDM_AGCPWR_MACRO__

/* macros for field inband_target */
/**
 * @defgroup mdm_regs_core_inband_target_field inband_target_field
 * @brief macros for field inband_target
 * @details Signed, relative to full scale agc filter output 7'h65 = -27
 * @{
 */
#define MDM_AGCPWR__INBAND_TARGET__SHIFT                                      0
#define MDM_AGCPWR__INBAND_TARGET__WIDTH                                      7
#define MDM_AGCPWR__INBAND_TARGET__MASK                             0x0000007fU
#define MDM_AGCPWR__INBAND_TARGET__READ(src)    ((uint32_t)(src) & 0x0000007fU)
#define MDM_AGCPWR__INBAND_TARGET__WRITE(src)   ((uint32_t)(src) & 0x0000007fU)
#define MDM_AGCPWR__INBAND_TARGET__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000007fU) | ((uint32_t)(src) &\
                    0x0000007fU)
#define MDM_AGCPWR__INBAND_TARGET__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000007fU)))
#define MDM_AGCPWR__INBAND_TARGET__RESET_VALUE                      0x00000065U
/** @} */

/* macros for field adc_max_target */
/**
 * @defgroup mdm_regs_core_adc_max_target_field adc_max_target_field
 * @brief macros for field adc_max_target
 * @details Signed, relative to full scale ADC. 7'h77 = -9.
 * @{
 */
#define MDM_AGCPWR__ADC_MAX_TARGET__SHIFT                                     7
#define MDM_AGCPWR__ADC_MAX_TARGET__WIDTH                                     7
#define MDM_AGCPWR__ADC_MAX_TARGET__MASK                            0x00003f80U
#define MDM_AGCPWR__ADC_MAX_TARGET__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00003f80U) >> 7)
#define MDM_AGCPWR__ADC_MAX_TARGET__WRITE(src) \
                    (((uint32_t)(src)\
                    << 7) & 0x00003f80U)
#define MDM_AGCPWR__ADC_MAX_TARGET__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00003f80U) | (((uint32_t)(src) <<\
                    7) & 0x00003f80U)
#define MDM_AGCPWR__ADC_MAX_TARGET__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 7) & ~0x00003f80U)))
#define MDM_AGCPWR__ADC_MAX_TARGET__RESET_VALUE                     0x00000077U
/** @} */

/* macros for field twomeg_inband_target */
/**
 * @defgroup mdm_regs_core_twomeg_inband_target_field twomeg_inband_target_field
 * @brief macros for field twomeg_inband_target
 * @details Signed, relative to full scale agc filter output 7'h68 = -24
 * @{
 */
#define MDM_AGCPWR__TWOMEG_INBAND_TARGET__SHIFT                              14
#define MDM_AGCPWR__TWOMEG_INBAND_TARGET__WIDTH                               7
#define MDM_AGCPWR__TWOMEG_INBAND_TARGET__MASK                      0x001fc000U
#define MDM_AGCPWR__TWOMEG_INBAND_TARGET__READ(src) \
                    (((uint32_t)(src)\
                    & 0x001fc000U) >> 14)
#define MDM_AGCPWR__TWOMEG_INBAND_TARGET__WRITE(src) \
                    (((uint32_t)(src)\
                    << 14) & 0x001fc000U)
#define MDM_AGCPWR__TWOMEG_INBAND_TARGET__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x001fc000U) | (((uint32_t)(src) <<\
                    14) & 0x001fc000U)
#define MDM_AGCPWR__TWOMEG_INBAND_TARGET__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 14) & ~0x001fc000U)))
#define MDM_AGCPWR__TWOMEG_INBAND_TARGET__RESET_VALUE               0x00000068U
/** @} */

/* macros for field inband_pwr_err_thr_hi */
/**
 * @defgroup mdm_regs_core_inband_pwr_err_thr_hi_field inband_pwr_err_thr_hi_field
 * @brief macros for field inband_pwr_err_thr_hi
 * @details Threshold to check if inband power is within this range of inband target after fine gain change, for positive gain_delta1
 * @{
 */
#define MDM_AGCPWR__INBAND_PWR_ERR_THR_HI__SHIFT                             21
#define MDM_AGCPWR__INBAND_PWR_ERR_THR_HI__WIDTH                              4
#define MDM_AGCPWR__INBAND_PWR_ERR_THR_HI__MASK                     0x01e00000U
#define MDM_AGCPWR__INBAND_PWR_ERR_THR_HI__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01e00000U) >> 21)
#define MDM_AGCPWR__INBAND_PWR_ERR_THR_HI__WRITE(src) \
                    (((uint32_t)(src)\
                    << 21) & 0x01e00000U)
#define MDM_AGCPWR__INBAND_PWR_ERR_THR_HI__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01e00000U) | (((uint32_t)(src) <<\
                    21) & 0x01e00000U)
#define MDM_AGCPWR__INBAND_PWR_ERR_THR_HI__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 21) & ~0x01e00000U)))
#define MDM_AGCPWR__INBAND_PWR_ERR_THR_HI__RESET_VALUE              0x0000000cU
/** @} */

/* macros for field inband_pwr_err_thr_lo */
/**
 * @defgroup mdm_regs_core_inband_pwr_err_thr_lo_field inband_pwr_err_thr_lo_field
 * @brief macros for field inband_pwr_err_thr_lo
 * @details Threshold to check if inband power is within this range of inband target after fine gain change, for negative gain_delta1
 * @{
 */
#define MDM_AGCPWR__INBAND_PWR_ERR_THR_LO__SHIFT                             25
#define MDM_AGCPWR__INBAND_PWR_ERR_THR_LO__WIDTH                              4
#define MDM_AGCPWR__INBAND_PWR_ERR_THR_LO__MASK                     0x1e000000U
#define MDM_AGCPWR__INBAND_PWR_ERR_THR_LO__READ(src) \
                    (((uint32_t)(src)\
                    & 0x1e000000U) >> 25)
#define MDM_AGCPWR__INBAND_PWR_ERR_THR_LO__WRITE(src) \
                    (((uint32_t)(src)\
                    << 25) & 0x1e000000U)
#define MDM_AGCPWR__INBAND_PWR_ERR_THR_LO__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x1e000000U) | (((uint32_t)(src) <<\
                    25) & 0x1e000000U)
#define MDM_AGCPWR__INBAND_PWR_ERR_THR_LO__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 25) & ~0x1e000000U)))
#define MDM_AGCPWR__INBAND_PWR_ERR_THR_LO__RESET_VALUE              0x0000000cU
/** @} */
#define MDM_AGCPWR__TYPE                                               uint32_t
#define MDM_AGCPWR__READ                                            0x1fffffffU
#define MDM_AGCPWR__WRITE                                           0x1fffffffU
#define MDM_AGCPWR__PRESERVED                                       0x00000000U
#define MDM_AGCPWR__RESET_VALUE                                     0x199a3be5U

#endif /* __MDM_AGCPWR_MACRO__ */

/** @} end of agcpwr */

/* macros for BlueprintGlobalNameSpace::MDM_agcpwr_alt */
/**
 * @defgroup mdm_regs_core_agcpwr_alt agcpwr_alt
 * @brief Power measurement targets, alternate set definitions.
 * @{
 */
#ifndef __MDM_AGCPWR_ALT_MACRO__
#define __MDM_AGCPWR_ALT_MACRO__

/* macros for field inband_target */
/**
 * @defgroup mdm_regs_core_inband_target_field inband_target_field
 * @brief macros for field inband_target
 * @details Signed, relative to full scale agc filter output 7'h65 = -27
 * @{
 */
#define MDM_AGCPWR_ALT__INBAND_TARGET__SHIFT                                  0
#define MDM_AGCPWR_ALT__INBAND_TARGET__WIDTH                                  7
#define MDM_AGCPWR_ALT__INBAND_TARGET__MASK                         0x0000007fU
#define MDM_AGCPWR_ALT__INBAND_TARGET__READ(src) \
                    ((uint32_t)(src)\
                    & 0x0000007fU)
#define MDM_AGCPWR_ALT__INBAND_TARGET__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000007fU)
#define MDM_AGCPWR_ALT__INBAND_TARGET__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000007fU) | ((uint32_t)(src) &\
                    0x0000007fU)
#define MDM_AGCPWR_ALT__INBAND_TARGET__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000007fU)))
#define MDM_AGCPWR_ALT__INBAND_TARGET__RESET_VALUE                  0x00000065U
/** @} */

/* macros for field adc_max_target */
/**
 * @defgroup mdm_regs_core_adc_max_target_field adc_max_target_field
 * @brief macros for field adc_max_target
 * @details Signed, relative to full scale ADC. 7'h77 = -9.
 * @{
 */
#define MDM_AGCPWR_ALT__ADC_MAX_TARGET__SHIFT                                 7
#define MDM_AGCPWR_ALT__ADC_MAX_TARGET__WIDTH                                 7
#define MDM_AGCPWR_ALT__ADC_MAX_TARGET__MASK                        0x00003f80U
#define MDM_AGCPWR_ALT__ADC_MAX_TARGET__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00003f80U) >> 7)
#define MDM_AGCPWR_ALT__ADC_MAX_TARGET__WRITE(src) \
                    (((uint32_t)(src)\
                    << 7) & 0x00003f80U)
#define MDM_AGCPWR_ALT__ADC_MAX_TARGET__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00003f80U) | (((uint32_t)(src) <<\
                    7) & 0x00003f80U)
#define MDM_AGCPWR_ALT__ADC_MAX_TARGET__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 7) & ~0x00003f80U)))
#define MDM_AGCPWR_ALT__ADC_MAX_TARGET__RESET_VALUE                 0x00000077U
/** @} */

/* macros for field twomeg_inband_target */
/**
 * @defgroup mdm_regs_core_twomeg_inband_target_field twomeg_inband_target_field
 * @brief macros for field twomeg_inband_target
 * @details Signed, relative to full scale agc filter output 7'h68 = -24
 * @{
 */
#define MDM_AGCPWR_ALT__TWOMEG_INBAND_TARGET__SHIFT                          14
#define MDM_AGCPWR_ALT__TWOMEG_INBAND_TARGET__WIDTH                           7
#define MDM_AGCPWR_ALT__TWOMEG_INBAND_TARGET__MASK                  0x001fc000U
#define MDM_AGCPWR_ALT__TWOMEG_INBAND_TARGET__READ(src) \
                    (((uint32_t)(src)\
                    & 0x001fc000U) >> 14)
#define MDM_AGCPWR_ALT__TWOMEG_INBAND_TARGET__WRITE(src) \
                    (((uint32_t)(src)\
                    << 14) & 0x001fc000U)
#define MDM_AGCPWR_ALT__TWOMEG_INBAND_TARGET__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x001fc000U) | (((uint32_t)(src) <<\
                    14) & 0x001fc000U)
#define MDM_AGCPWR_ALT__TWOMEG_INBAND_TARGET__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 14) & ~0x001fc000U)))
#define MDM_AGCPWR_ALT__TWOMEG_INBAND_TARGET__RESET_VALUE           0x00000068U
/** @} */

/* macros for field inband_pwr_err_thr_hi */
/**
 * @defgroup mdm_regs_core_inband_pwr_err_thr_hi_field inband_pwr_err_thr_hi_field
 * @brief macros for field inband_pwr_err_thr_hi
 * @details Threshold to check if inband power is within this range of inband target after fine gain change, for positive gain_delta1
 * @{
 */
#define MDM_AGCPWR_ALT__INBAND_PWR_ERR_THR_HI__SHIFT                         21
#define MDM_AGCPWR_ALT__INBAND_PWR_ERR_THR_HI__WIDTH                          4
#define MDM_AGCPWR_ALT__INBAND_PWR_ERR_THR_HI__MASK                 0x01e00000U
#define MDM_AGCPWR_ALT__INBAND_PWR_ERR_THR_HI__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01e00000U) >> 21)
#define MDM_AGCPWR_ALT__INBAND_PWR_ERR_THR_HI__WRITE(src) \
                    (((uint32_t)(src)\
                    << 21) & 0x01e00000U)
#define MDM_AGCPWR_ALT__INBAND_PWR_ERR_THR_HI__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01e00000U) | (((uint32_t)(src) <<\
                    21) & 0x01e00000U)
#define MDM_AGCPWR_ALT__INBAND_PWR_ERR_THR_HI__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 21) & ~0x01e00000U)))
#define MDM_AGCPWR_ALT__INBAND_PWR_ERR_THR_HI__RESET_VALUE          0x0000000cU
/** @} */

/* macros for field inband_pwr_err_thr_lo */
/**
 * @defgroup mdm_regs_core_inband_pwr_err_thr_lo_field inband_pwr_err_thr_lo_field
 * @brief macros for field inband_pwr_err_thr_lo
 * @details Threshold to check if inband power is within this range of inband target after fine gain change, for negative gain_delta1
 * @{
 */
#define MDM_AGCPWR_ALT__INBAND_PWR_ERR_THR_LO__SHIFT                         25
#define MDM_AGCPWR_ALT__INBAND_PWR_ERR_THR_LO__WIDTH                          4
#define MDM_AGCPWR_ALT__INBAND_PWR_ERR_THR_LO__MASK                 0x1e000000U
#define MDM_AGCPWR_ALT__INBAND_PWR_ERR_THR_LO__READ(src) \
                    (((uint32_t)(src)\
                    & 0x1e000000U) >> 25)
#define MDM_AGCPWR_ALT__INBAND_PWR_ERR_THR_LO__WRITE(src) \
                    (((uint32_t)(src)\
                    << 25) & 0x1e000000U)
#define MDM_AGCPWR_ALT__INBAND_PWR_ERR_THR_LO__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x1e000000U) | (((uint32_t)(src) <<\
                    25) & 0x1e000000U)
#define MDM_AGCPWR_ALT__INBAND_PWR_ERR_THR_LO__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 25) & ~0x1e000000U)))
#define MDM_AGCPWR_ALT__INBAND_PWR_ERR_THR_LO__RESET_VALUE          0x0000000cU
/** @} */
#define MDM_AGCPWR_ALT__TYPE                                           uint32_t
#define MDM_AGCPWR_ALT__READ                                        0x1fffffffU
#define MDM_AGCPWR_ALT__WRITE                                       0x1fffffffU
#define MDM_AGCPWR_ALT__PRESERVED                                   0x00000000U
#define MDM_AGCPWR_ALT__RESET_VALUE                                 0x199a3be5U

#endif /* __MDM_AGCPWR_ALT_MACRO__ */

/** @} end of agcpwr_alt */

/* macros for BlueprintGlobalNameSpace::MDM_agcpwr2 */
/**
 * @defgroup mdm_regs_core_agcpwr2 agcpwr2
 * @brief Power control definitions.
 * @{
 */
#ifndef __MDM_AGCPWR2_MACRO__
#define __MDM_AGCPWR2_MACRO__

/* macros for field meas_win */
/**
 * @defgroup mdm_regs_core_meas_win_field meas_win_field
 * @brief macros for field meas_win
 * @details Number of 16 MHz samples for power measurement. Encoding: 0 -> 4; 1 -> 8; 2 -> 12; 3 -> 16 When running front end at 8 MHz (1 Mb/s, 500 Kb/s, or 125 Kb/s), then this number is cut in half
 * @{
 */
#define MDM_AGCPWR2__MEAS_WIN__SHIFT                                          0
#define MDM_AGCPWR2__MEAS_WIN__WIDTH                                          2
#define MDM_AGCPWR2__MEAS_WIN__MASK                                 0x00000003U
#define MDM_AGCPWR2__MEAS_WIN__READ(src)        ((uint32_t)(src) & 0x00000003U)
#define MDM_AGCPWR2__MEAS_WIN__WRITE(src)       ((uint32_t)(src) & 0x00000003U)
#define MDM_AGCPWR2__MEAS_WIN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000003U) | ((uint32_t)(src) &\
                    0x00000003U)
#define MDM_AGCPWR2__MEAS_WIN__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000003U)))
#define MDM_AGCPWR2__MEAS_WIN__RESET_VALUE                          0x00000003U
/** @} */

/* macros for field det_step */
/**
 * @defgroup mdm_regs_core_det_step_field det_step_field
 * @brief macros for field det_step
 * @details dB increase required for detection based on power step
 * @{
 */
#define MDM_AGCPWR2__DET_STEP__SHIFT                                          2
#define MDM_AGCPWR2__DET_STEP__WIDTH                                          5
#define MDM_AGCPWR2__DET_STEP__MASK                                 0x0000007cU
#define MDM_AGCPWR2__DET_STEP__READ(src) (((uint32_t)(src) & 0x0000007cU) >> 2)
#define MDM_AGCPWR2__DET_STEP__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x0000007cU)
#define MDM_AGCPWR2__DET_STEP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000007cU) | (((uint32_t)(src) <<\
                    2) & 0x0000007cU)
#define MDM_AGCPWR2__DET_STEP__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x0000007cU)))
#define MDM_AGCPWR2__DET_STEP__RESET_VALUE                          0x00000006U
/** @} */

/* macros for field det_step_delta */
/**
 * @defgroup mdm_regs_core_det_step_delta_field det_step_delta_field
 * @brief macros for field det_step_delta
 * @details Addition in dB to det_step if baseline power < det_min + baseline_blk_pwr_offset
 * @{
 */
#define MDM_AGCPWR2__DET_STEP_DELTA__SHIFT                                    7
#define MDM_AGCPWR2__DET_STEP_DELTA__WIDTH                                    4
#define MDM_AGCPWR2__DET_STEP_DELTA__MASK                           0x00000780U
#define MDM_AGCPWR2__DET_STEP_DELTA__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000780U) >> 7)
#define MDM_AGCPWR2__DET_STEP_DELTA__WRITE(src) \
                    (((uint32_t)(src)\
                    << 7) & 0x00000780U)
#define MDM_AGCPWR2__DET_STEP_DELTA__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000780U) | (((uint32_t)(src) <<\
                    7) & 0x00000780U)
#define MDM_AGCPWR2__DET_STEP_DELTA__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 7) & ~0x00000780U)))
#define MDM_AGCPWR2__DET_STEP_DELTA__RESET_VALUE                    0x00000002U
/** @} */

/* macros for field baseline_blk_pwr_offset */
/**
 * @defgroup mdm_regs_core_baseline_blk_pwr_offset_field baseline_blk_pwr_offset_field
 * @brief macros for field baseline_blk_pwr_offset
 * @details Used in comparison to adjust det_step
 * @{
 */
#define MDM_AGCPWR2__BASELINE_BLK_PWR_OFFSET__SHIFT                          11
#define MDM_AGCPWR2__BASELINE_BLK_PWR_OFFSET__WIDTH                           6
#define MDM_AGCPWR2__BASELINE_BLK_PWR_OFFSET__MASK                  0x0001f800U
#define MDM_AGCPWR2__BASELINE_BLK_PWR_OFFSET__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0001f800U) >> 11)
#define MDM_AGCPWR2__BASELINE_BLK_PWR_OFFSET__WRITE(src) \
                    (((uint32_t)(src)\
                    << 11) & 0x0001f800U)
#define MDM_AGCPWR2__BASELINE_BLK_PWR_OFFSET__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0001f800U) | (((uint32_t)(src) <<\
                    11) & 0x0001f800U)
#define MDM_AGCPWR2__BASELINE_BLK_PWR_OFFSET__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 11) & ~0x0001f800U)))
#define MDM_AGCPWR2__BASELINE_BLK_PWR_OFFSET__RESET_VALUE           0x00000008U
/** @} */

/* macros for field rssi_thr_to_force_ffe */
/**
 * @defgroup mdm_regs_core_rssi_thr_to_force_ffe_field rssi_thr_to_force_ffe_field
 * @brief macros for field rssi_thr_to_force_ffe
 * @details If RSSI is below this value, then use ffe (for uncoded only) 8'd127 implies always use ffe. 8'hab = -85
 * @{
 */
#define MDM_AGCPWR2__RSSI_THR_TO_FORCE_FFE__SHIFT                            17
#define MDM_AGCPWR2__RSSI_THR_TO_FORCE_FFE__WIDTH                             8
#define MDM_AGCPWR2__RSSI_THR_TO_FORCE_FFE__MASK                    0x01fe0000U
#define MDM_AGCPWR2__RSSI_THR_TO_FORCE_FFE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01fe0000U) >> 17)
#define MDM_AGCPWR2__RSSI_THR_TO_FORCE_FFE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 17) & 0x01fe0000U)
#define MDM_AGCPWR2__RSSI_THR_TO_FORCE_FFE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01fe0000U) | (((uint32_t)(src) <<\
                    17) & 0x01fe0000U)
#define MDM_AGCPWR2__RSSI_THR_TO_FORCE_FFE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 17) & ~0x01fe0000U)))
#define MDM_AGCPWR2__RSSI_THR_TO_FORCE_FFE__RESET_VALUE             0x000000abU
/** @} */

/* macros for field delay_total_pwr_for_blocker_det */
/**
 * @defgroup mdm_regs_core_delay_total_pwr_for_blocker_det_field delay_total_pwr_for_blocker_det_field
 * @brief macros for field delay_total_pwr_for_blocker_det
 * @details Delay on total_pwr for add_det_step delta Encoding: 2'b00 -> 0; 2'b01 -> 4; 2'b10 -> 8; 3'b11 -> 12
 * @{
 */
#define MDM_AGCPWR2__DELAY_TOTAL_PWR_FOR_BLOCKER_DET__SHIFT                  25
#define MDM_AGCPWR2__DELAY_TOTAL_PWR_FOR_BLOCKER_DET__WIDTH                   2
#define MDM_AGCPWR2__DELAY_TOTAL_PWR_FOR_BLOCKER_DET__MASK          0x06000000U
#define MDM_AGCPWR2__DELAY_TOTAL_PWR_FOR_BLOCKER_DET__READ(src) \
                    (((uint32_t)(src)\
                    & 0x06000000U) >> 25)
#define MDM_AGCPWR2__DELAY_TOTAL_PWR_FOR_BLOCKER_DET__WRITE(src) \
                    (((uint32_t)(src)\
                    << 25) & 0x06000000U)
#define MDM_AGCPWR2__DELAY_TOTAL_PWR_FOR_BLOCKER_DET__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x06000000U) | (((uint32_t)(src) <<\
                    25) & 0x06000000U)
#define MDM_AGCPWR2__DELAY_TOTAL_PWR_FOR_BLOCKER_DET__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 25) & ~0x06000000U)))
#define MDM_AGCPWR2__DELAY_TOTAL_PWR_FOR_BLOCKER_DET__RESET_VALUE   0x00000002U
/** @} */

/* macros for field twomeg_delay_total_pwr_for_blocker_det */
/**
 * @defgroup mdm_regs_core_twomeg_delay_total_pwr_for_blocker_det_field twomeg_delay_total_pwr_for_blocker_det_field
 * @brief macros for field twomeg_delay_total_pwr_for_blocker_det
 * @details 2M rate. Delay on total_pwr for add_det_step delta Encoding: 2'b00 -> 0; 2'b01 -> 4; 2'b10 -> 8; 3'b11 -> 12
 * @{
 */
#define MDM_AGCPWR2__TWOMEG_DELAY_TOTAL_PWR_FOR_BLOCKER_DET__SHIFT           27
#define MDM_AGCPWR2__TWOMEG_DELAY_TOTAL_PWR_FOR_BLOCKER_DET__WIDTH            2
#define MDM_AGCPWR2__TWOMEG_DELAY_TOTAL_PWR_FOR_BLOCKER_DET__MASK   0x18000000U
#define MDM_AGCPWR2__TWOMEG_DELAY_TOTAL_PWR_FOR_BLOCKER_DET__READ(src) \
                    (((uint32_t)(src)\
                    & 0x18000000U) >> 27)
#define MDM_AGCPWR2__TWOMEG_DELAY_TOTAL_PWR_FOR_BLOCKER_DET__WRITE(src) \
                    (((uint32_t)(src)\
                    << 27) & 0x18000000U)
#define MDM_AGCPWR2__TWOMEG_DELAY_TOTAL_PWR_FOR_BLOCKER_DET__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x18000000U) | (((uint32_t)(src) <<\
                    27) & 0x18000000U)
#define MDM_AGCPWR2__TWOMEG_DELAY_TOTAL_PWR_FOR_BLOCKER_DET__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 27) & ~0x18000000U)))
#define MDM_AGCPWR2__TWOMEG_DELAY_TOTAL_PWR_FOR_BLOCKER_DET__RESET_VALUE \
                    0x00000002U
/** @} */
#define MDM_AGCPWR2__TYPE                                              uint32_t
#define MDM_AGCPWR2__READ                                           0x1fffffffU
#define MDM_AGCPWR2__WRITE                                          0x1fffffffU
#define MDM_AGCPWR2__PRESERVED                                      0x00000000U
#define MDM_AGCPWR2__RESET_VALUE                                    0x1556411bU

#endif /* __MDM_AGCPWR2_MACRO__ */

/** @} end of agcpwr2 */

/* macros for BlueprintGlobalNameSpace::MDM_agcpwr2_alt */
/**
 * @defgroup mdm_regs_core_agcpwr2_alt agcpwr2_alt
 * @brief Power control, alternate set definitions.
 * @{
 */
#ifndef __MDM_AGCPWR2_ALT_MACRO__
#define __MDM_AGCPWR2_ALT_MACRO__

/* macros for field meas_win */
/**
 * @defgroup mdm_regs_core_meas_win_field meas_win_field
 * @brief macros for field meas_win
 * @details Number of 16 MHz samples for power measurement. Encoding: 0 -> 4; 1 -> 8; 2 -> 12; 3 -> 16 When running front end at 8 MHz (1 Mb/s, 500 Kb/s, or 125 Kb/s), then this number is cut in half
 * @{
 */
#define MDM_AGCPWR2_ALT__MEAS_WIN__SHIFT                                      0
#define MDM_AGCPWR2_ALT__MEAS_WIN__WIDTH                                      2
#define MDM_AGCPWR2_ALT__MEAS_WIN__MASK                             0x00000003U
#define MDM_AGCPWR2_ALT__MEAS_WIN__READ(src)    ((uint32_t)(src) & 0x00000003U)
#define MDM_AGCPWR2_ALT__MEAS_WIN__WRITE(src)   ((uint32_t)(src) & 0x00000003U)
#define MDM_AGCPWR2_ALT__MEAS_WIN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000003U) | ((uint32_t)(src) &\
                    0x00000003U)
#define MDM_AGCPWR2_ALT__MEAS_WIN__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000003U)))
#define MDM_AGCPWR2_ALT__MEAS_WIN__RESET_VALUE                      0x00000003U
/** @} */

/* macros for field det_step */
/**
 * @defgroup mdm_regs_core_det_step_field det_step_field
 * @brief macros for field det_step
 * @details dB increase required for detection based on power step
 * @{
 */
#define MDM_AGCPWR2_ALT__DET_STEP__SHIFT                                      2
#define MDM_AGCPWR2_ALT__DET_STEP__WIDTH                                      5
#define MDM_AGCPWR2_ALT__DET_STEP__MASK                             0x0000007cU
#define MDM_AGCPWR2_ALT__DET_STEP__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000007cU) >> 2)
#define MDM_AGCPWR2_ALT__DET_STEP__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x0000007cU)
#define MDM_AGCPWR2_ALT__DET_STEP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000007cU) | (((uint32_t)(src) <<\
                    2) & 0x0000007cU)
#define MDM_AGCPWR2_ALT__DET_STEP__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x0000007cU)))
#define MDM_AGCPWR2_ALT__DET_STEP__RESET_VALUE                      0x00000006U
/** @} */

/* macros for field det_step_delta */
/**
 * @defgroup mdm_regs_core_det_step_delta_field det_step_delta_field
 * @brief macros for field det_step_delta
 * @details Addition in dB to det_step if baseline power < det_min + baseline_blk_pwr_offset
 * @{
 */
#define MDM_AGCPWR2_ALT__DET_STEP_DELTA__SHIFT                                7
#define MDM_AGCPWR2_ALT__DET_STEP_DELTA__WIDTH                                4
#define MDM_AGCPWR2_ALT__DET_STEP_DELTA__MASK                       0x00000780U
#define MDM_AGCPWR2_ALT__DET_STEP_DELTA__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000780U) >> 7)
#define MDM_AGCPWR2_ALT__DET_STEP_DELTA__WRITE(src) \
                    (((uint32_t)(src)\
                    << 7) & 0x00000780U)
#define MDM_AGCPWR2_ALT__DET_STEP_DELTA__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000780U) | (((uint32_t)(src) <<\
                    7) & 0x00000780U)
#define MDM_AGCPWR2_ALT__DET_STEP_DELTA__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 7) & ~0x00000780U)))
#define MDM_AGCPWR2_ALT__DET_STEP_DELTA__RESET_VALUE                0x00000002U
/** @} */

/* macros for field baseline_blk_pwr_offset */
/**
 * @defgroup mdm_regs_core_baseline_blk_pwr_offset_field baseline_blk_pwr_offset_field
 * @brief macros for field baseline_blk_pwr_offset
 * @details Used in comparison to adjust det_step
 * @{
 */
#define MDM_AGCPWR2_ALT__BASELINE_BLK_PWR_OFFSET__SHIFT                      11
#define MDM_AGCPWR2_ALT__BASELINE_BLK_PWR_OFFSET__WIDTH                       6
#define MDM_AGCPWR2_ALT__BASELINE_BLK_PWR_OFFSET__MASK              0x0001f800U
#define MDM_AGCPWR2_ALT__BASELINE_BLK_PWR_OFFSET__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0001f800U) >> 11)
#define MDM_AGCPWR2_ALT__BASELINE_BLK_PWR_OFFSET__WRITE(src) \
                    (((uint32_t)(src)\
                    << 11) & 0x0001f800U)
#define MDM_AGCPWR2_ALT__BASELINE_BLK_PWR_OFFSET__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0001f800U) | (((uint32_t)(src) <<\
                    11) & 0x0001f800U)
#define MDM_AGCPWR2_ALT__BASELINE_BLK_PWR_OFFSET__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 11) & ~0x0001f800U)))
#define MDM_AGCPWR2_ALT__BASELINE_BLK_PWR_OFFSET__RESET_VALUE       0x00000008U
/** @} */

/* macros for field rssi_thr_to_force_ffe */
/**
 * @defgroup mdm_regs_core_rssi_thr_to_force_ffe_field rssi_thr_to_force_ffe_field
 * @brief macros for field rssi_thr_to_force_ffe
 * @details If RSSI is below this value, then use ffe (for uncoded only) 8'd127 implies always use ffe. 8'hab = -85
 * @{
 */
#define MDM_AGCPWR2_ALT__RSSI_THR_TO_FORCE_FFE__SHIFT                        17
#define MDM_AGCPWR2_ALT__RSSI_THR_TO_FORCE_FFE__WIDTH                         8
#define MDM_AGCPWR2_ALT__RSSI_THR_TO_FORCE_FFE__MASK                0x01fe0000U
#define MDM_AGCPWR2_ALT__RSSI_THR_TO_FORCE_FFE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01fe0000U) >> 17)
#define MDM_AGCPWR2_ALT__RSSI_THR_TO_FORCE_FFE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 17) & 0x01fe0000U)
#define MDM_AGCPWR2_ALT__RSSI_THR_TO_FORCE_FFE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01fe0000U) | (((uint32_t)(src) <<\
                    17) & 0x01fe0000U)
#define MDM_AGCPWR2_ALT__RSSI_THR_TO_FORCE_FFE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 17) & ~0x01fe0000U)))
#define MDM_AGCPWR2_ALT__RSSI_THR_TO_FORCE_FFE__RESET_VALUE         0x000000abU
/** @} */

/* macros for field delay_total_pwr_for_blocker_det */
/**
 * @defgroup mdm_regs_core_delay_total_pwr_for_blocker_det_field delay_total_pwr_for_blocker_det_field
 * @brief macros for field delay_total_pwr_for_blocker_det
 * @details Delay on total_pwr for add_det_step delta Encoding: 2'b00 -> 0; 2'b01 -> 4; 2'b10 -> 8; 3'b11 -> 12
 * @{
 */
#define MDM_AGCPWR2_ALT__DELAY_TOTAL_PWR_FOR_BLOCKER_DET__SHIFT              25
#define MDM_AGCPWR2_ALT__DELAY_TOTAL_PWR_FOR_BLOCKER_DET__WIDTH               2
#define MDM_AGCPWR2_ALT__DELAY_TOTAL_PWR_FOR_BLOCKER_DET__MASK      0x06000000U
#define MDM_AGCPWR2_ALT__DELAY_TOTAL_PWR_FOR_BLOCKER_DET__READ(src) \
                    (((uint32_t)(src)\
                    & 0x06000000U) >> 25)
#define MDM_AGCPWR2_ALT__DELAY_TOTAL_PWR_FOR_BLOCKER_DET__WRITE(src) \
                    (((uint32_t)(src)\
                    << 25) & 0x06000000U)
#define MDM_AGCPWR2_ALT__DELAY_TOTAL_PWR_FOR_BLOCKER_DET__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x06000000U) | (((uint32_t)(src) <<\
                    25) & 0x06000000U)
#define MDM_AGCPWR2_ALT__DELAY_TOTAL_PWR_FOR_BLOCKER_DET__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 25) & ~0x06000000U)))
#define MDM_AGCPWR2_ALT__DELAY_TOTAL_PWR_FOR_BLOCKER_DET__RESET_VALUE \
                    0x00000002U
/** @} */

/* macros for field twomeg_delay_total_pwr_for_blocker_det */
/**
 * @defgroup mdm_regs_core_twomeg_delay_total_pwr_for_blocker_det_field twomeg_delay_total_pwr_for_blocker_det_field
 * @brief macros for field twomeg_delay_total_pwr_for_blocker_det
 * @details 2M rate. Delay on total_pwr for add_det_step delta Encoding: 2'b00 -> 0; 2'b01 -> 4; 2'b10 -> 8; 3'b11 -> 12
 * @{
 */
#define MDM_AGCPWR2_ALT__TWOMEG_DELAY_TOTAL_PWR_FOR_BLOCKER_DET__SHIFT       27
#define MDM_AGCPWR2_ALT__TWOMEG_DELAY_TOTAL_PWR_FOR_BLOCKER_DET__WIDTH        2
#define MDM_AGCPWR2_ALT__TWOMEG_DELAY_TOTAL_PWR_FOR_BLOCKER_DET__MASK \
                    0x18000000U
#define MDM_AGCPWR2_ALT__TWOMEG_DELAY_TOTAL_PWR_FOR_BLOCKER_DET__READ(src) \
                    (((uint32_t)(src)\
                    & 0x18000000U) >> 27)
#define MDM_AGCPWR2_ALT__TWOMEG_DELAY_TOTAL_PWR_FOR_BLOCKER_DET__WRITE(src) \
                    (((uint32_t)(src)\
                    << 27) & 0x18000000U)
#define MDM_AGCPWR2_ALT__TWOMEG_DELAY_TOTAL_PWR_FOR_BLOCKER_DET__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x18000000U) | (((uint32_t)(src) <<\
                    27) & 0x18000000U)
#define MDM_AGCPWR2_ALT__TWOMEG_DELAY_TOTAL_PWR_FOR_BLOCKER_DET__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 27) & ~0x18000000U)))
#define MDM_AGCPWR2_ALT__TWOMEG_DELAY_TOTAL_PWR_FOR_BLOCKER_DET__RESET_VALUE \
                    0x00000002U
/** @} */
#define MDM_AGCPWR2_ALT__TYPE                                          uint32_t
#define MDM_AGCPWR2_ALT__READ                                       0x1fffffffU
#define MDM_AGCPWR2_ALT__WRITE                                      0x1fffffffU
#define MDM_AGCPWR2_ALT__PRESERVED                                  0x00000000U
#define MDM_AGCPWR2_ALT__RESET_VALUE                                0x1556411bU

#endif /* __MDM_AGCPWR2_ALT_MACRO__ */

/** @} end of agcpwr2_alt */

/* macros for BlueprintGlobalNameSpace::MDM_agctime */
/**
 * @defgroup mdm_regs_core_agctime agctime
 * @brief agc delays definitions.
 * @{
 */
#ifndef __MDM_AGCTIME_MACRO__
#define __MDM_AGCTIME_MACRO__

/* macros for field gain_settle */
/**
 * @defgroup mdm_regs_core_gain_settle_field gain_settle_field
 * @brief macros for field gain_settle
 * @details number of 16 MHz clocks from gain change to when coarse/saturation measurements can begin. MUST BE EVEN. Register replicated for 2 Mb/s
 * @{
 */
#define MDM_AGCTIME__GAIN_SETTLE__SHIFT                                       0
#define MDM_AGCTIME__GAIN_SETTLE__WIDTH                                       6
#define MDM_AGCTIME__GAIN_SETTLE__MASK                              0x0000003fU
#define MDM_AGCTIME__GAIN_SETTLE__READ(src)     ((uint32_t)(src) & 0x0000003fU)
#define MDM_AGCTIME__GAIN_SETTLE__WRITE(src)    ((uint32_t)(src) & 0x0000003fU)
#define MDM_AGCTIME__GAIN_SETTLE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000003fU) | ((uint32_t)(src) &\
                    0x0000003fU)
#define MDM_AGCTIME__GAIN_SETTLE__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000003fU)))
#define MDM_AGCTIME__GAIN_SETTLE__RESET_VALUE                       0x0000001cU
/** @} */

/* macros for field filt_settle */
/**
 * @defgroup mdm_regs_core_filt_settle_field filt_settle_field
 * @brief macros for field filt_settle
 * @details Number of 16 MHz cycles for agc filter to settle. MUST BE EVEN. Register replicated for 2 Mb/s
 * @{
 */
#define MDM_AGCTIME__FILT_SETTLE__SHIFT                                      25
#define MDM_AGCTIME__FILT_SETTLE__WIDTH                                       7
#define MDM_AGCTIME__FILT_SETTLE__MASK                              0xfe000000U
#define MDM_AGCTIME__FILT_SETTLE__READ(src) \
                    (((uint32_t)(src)\
                    & 0xfe000000U) >> 25)
#define MDM_AGCTIME__FILT_SETTLE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 25) & 0xfe000000U)
#define MDM_AGCTIME__FILT_SETTLE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xfe000000U) | (((uint32_t)(src) <<\
                    25) & 0xfe000000U)
#define MDM_AGCTIME__FILT_SETTLE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 25) & ~0xfe000000U)))
#define MDM_AGCTIME__FILT_SETTLE__RESET_VALUE                       0x0000001cU
/** @} */
#define MDM_AGCTIME__TYPE                                              uint32_t
#define MDM_AGCTIME__READ                                           0xfe00003fU
#define MDM_AGCTIME__WRITE                                          0xfe00003fU
#define MDM_AGCTIME__PRESERVED                                      0x00000000U
#define MDM_AGCTIME__RESET_VALUE                                    0x3800001cU

#endif /* __MDM_AGCTIME_MACRO__ */

/** @} end of agctime */

/* macros for BlueprintGlobalNameSpace::MDM_agctime_alt */
/**
 * @defgroup mdm_regs_core_agctime_alt agctime_alt
 * @brief agc delays, alternate set definitions.
 * @{
 */
#ifndef __MDM_AGCTIME_ALT_MACRO__
#define __MDM_AGCTIME_ALT_MACRO__

/* macros for field gain_settle */
/**
 * @defgroup mdm_regs_core_gain_settle_field gain_settle_field
 * @brief macros for field gain_settle
 * @details number of 16 MHz clocks from gain change to when coarse/saturation measurements can begin. MUST BE EVEN. Register replicated for 2 Mb/s
 * @{
 */
#define MDM_AGCTIME_ALT__GAIN_SETTLE__SHIFT                                   0
#define MDM_AGCTIME_ALT__GAIN_SETTLE__WIDTH                                   6
#define MDM_AGCTIME_ALT__GAIN_SETTLE__MASK                          0x0000003fU
#define MDM_AGCTIME_ALT__GAIN_SETTLE__READ(src) ((uint32_t)(src) & 0x0000003fU)
#define MDM_AGCTIME_ALT__GAIN_SETTLE__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000003fU)
#define MDM_AGCTIME_ALT__GAIN_SETTLE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000003fU) | ((uint32_t)(src) &\
                    0x0000003fU)
#define MDM_AGCTIME_ALT__GAIN_SETTLE__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000003fU)))
#define MDM_AGCTIME_ALT__GAIN_SETTLE__RESET_VALUE                   0x0000001cU
/** @} */

/* macros for field filt_settle */
/**
 * @defgroup mdm_regs_core_filt_settle_field filt_settle_field
 * @brief macros for field filt_settle
 * @details Number of 16 MHz cycles for agc filter to settle. MUST BE EVEN. Register replicated for 2 Mb/s
 * @{
 */
#define MDM_AGCTIME_ALT__FILT_SETTLE__SHIFT                                  25
#define MDM_AGCTIME_ALT__FILT_SETTLE__WIDTH                                   7
#define MDM_AGCTIME_ALT__FILT_SETTLE__MASK                          0xfe000000U
#define MDM_AGCTIME_ALT__FILT_SETTLE__READ(src) \
                    (((uint32_t)(src)\
                    & 0xfe000000U) >> 25)
#define MDM_AGCTIME_ALT__FILT_SETTLE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 25) & 0xfe000000U)
#define MDM_AGCTIME_ALT__FILT_SETTLE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xfe000000U) | (((uint32_t)(src) <<\
                    25) & 0xfe000000U)
#define MDM_AGCTIME_ALT__FILT_SETTLE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 25) & ~0xfe000000U)))
#define MDM_AGCTIME_ALT__FILT_SETTLE__RESET_VALUE                   0x0000001cU
/** @} */
#define MDM_AGCTIME_ALT__TYPE                                          uint32_t
#define MDM_AGCTIME_ALT__READ                                       0xfe00003fU
#define MDM_AGCTIME_ALT__WRITE                                      0xfe00003fU
#define MDM_AGCTIME_ALT__PRESERVED                                  0x00000000U
#define MDM_AGCTIME_ALT__RESET_VALUE                                0x3800001cU

#endif /* __MDM_AGCTIME_ALT_MACRO__ */

/** @} end of agctime_alt */

/* macros for BlueprintGlobalNameSpace::MDM_twomeg_agctime */
/**
 * @defgroup mdm_regs_core_twomeg_agctime twomeg_agctime
 * @brief agc delays for 2 Mb/s definitions.
 * @{
 */
#ifndef __MDM_TWOMEG_AGCTIME_MACRO__
#define __MDM_TWOMEG_AGCTIME_MACRO__

/* macros for field gain_settle */
/**
 * @defgroup mdm_regs_core_gain_settle_field gain_settle_field
 * @brief macros for field gain_settle
 * @details number of 16 MHz clocks from gain change to when coarse/saturation measurements can begin. 2 Mb/s version of register
 * @{
 */
#define MDM_TWOMEG_AGCTIME__GAIN_SETTLE__SHIFT                                0
#define MDM_TWOMEG_AGCTIME__GAIN_SETTLE__WIDTH                                6
#define MDM_TWOMEG_AGCTIME__GAIN_SETTLE__MASK                       0x0000003fU
#define MDM_TWOMEG_AGCTIME__GAIN_SETTLE__READ(src) \
                    ((uint32_t)(src)\
                    & 0x0000003fU)
#define MDM_TWOMEG_AGCTIME__GAIN_SETTLE__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000003fU)
#define MDM_TWOMEG_AGCTIME__GAIN_SETTLE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000003fU) | ((uint32_t)(src) &\
                    0x0000003fU)
#define MDM_TWOMEG_AGCTIME__GAIN_SETTLE__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000003fU)))
#define MDM_TWOMEG_AGCTIME__GAIN_SETTLE__RESET_VALUE                0x00000010U
/** @} */

/* macros for field filt_settle */
/**
 * @defgroup mdm_regs_core_filt_settle_field filt_settle_field
 * @brief macros for field filt_settle
 * @details Number of 16 MHz cycles for agc filter to settle. 2 Mb/s version of register
 * @{
 */
#define MDM_TWOMEG_AGCTIME__FILT_SETTLE__SHIFT                               25
#define MDM_TWOMEG_AGCTIME__FILT_SETTLE__WIDTH                                7
#define MDM_TWOMEG_AGCTIME__FILT_SETTLE__MASK                       0xfe000000U
#define MDM_TWOMEG_AGCTIME__FILT_SETTLE__READ(src) \
                    (((uint32_t)(src)\
                    & 0xfe000000U) >> 25)
#define MDM_TWOMEG_AGCTIME__FILT_SETTLE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 25) & 0xfe000000U)
#define MDM_TWOMEG_AGCTIME__FILT_SETTLE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xfe000000U) | (((uint32_t)(src) <<\
                    25) & 0xfe000000U)
#define MDM_TWOMEG_AGCTIME__FILT_SETTLE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 25) & ~0xfe000000U)))
#define MDM_TWOMEG_AGCTIME__FILT_SETTLE__RESET_VALUE                0x00000010U
/** @} */
#define MDM_TWOMEG_AGCTIME__TYPE                                       uint32_t
#define MDM_TWOMEG_AGCTIME__READ                                    0xfe00003fU
#define MDM_TWOMEG_AGCTIME__WRITE                                   0xfe00003fU
#define MDM_TWOMEG_AGCTIME__PRESERVED                               0x00000000U
#define MDM_TWOMEG_AGCTIME__RESET_VALUE                             0x20000010U

#endif /* __MDM_TWOMEG_AGCTIME_MACRO__ */

/** @} end of twomeg_agctime */

/* macros for BlueprintGlobalNameSpace::MDM_twomeg_agctime_alt */
/**
 * @defgroup mdm_regs_core_twomeg_agctime_alt twomeg_agctime_alt
 * @brief agc delays for 2 Mb/s definitions.
 * @{
 */
#ifndef __MDM_TWOMEG_AGCTIME_ALT_MACRO__
#define __MDM_TWOMEG_AGCTIME_ALT_MACRO__

/* macros for field gain_settle */
/**
 * @defgroup mdm_regs_core_gain_settle_field gain_settle_field
 * @brief macros for field gain_settle
 * @details number of 16 MHz clocks from gain change to when coarse/saturation measurements can begin. 2 Mb/s version of register
 * @{
 */
#define MDM_TWOMEG_AGCTIME_ALT__GAIN_SETTLE__SHIFT                            0
#define MDM_TWOMEG_AGCTIME_ALT__GAIN_SETTLE__WIDTH                            6
#define MDM_TWOMEG_AGCTIME_ALT__GAIN_SETTLE__MASK                   0x0000003fU
#define MDM_TWOMEG_AGCTIME_ALT__GAIN_SETTLE__READ(src) \
                    ((uint32_t)(src)\
                    & 0x0000003fU)
#define MDM_TWOMEG_AGCTIME_ALT__GAIN_SETTLE__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000003fU)
#define MDM_TWOMEG_AGCTIME_ALT__GAIN_SETTLE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000003fU) | ((uint32_t)(src) &\
                    0x0000003fU)
#define MDM_TWOMEG_AGCTIME_ALT__GAIN_SETTLE__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000003fU)))
#define MDM_TWOMEG_AGCTIME_ALT__GAIN_SETTLE__RESET_VALUE            0x00000010U
/** @} */

/* macros for field filt_settle */
/**
 * @defgroup mdm_regs_core_filt_settle_field filt_settle_field
 * @brief macros for field filt_settle
 * @details Number of 16 MHz cycles for agc filter to settle. 2 Mb/s version of register
 * @{
 */
#define MDM_TWOMEG_AGCTIME_ALT__FILT_SETTLE__SHIFT                           25
#define MDM_TWOMEG_AGCTIME_ALT__FILT_SETTLE__WIDTH                            7
#define MDM_TWOMEG_AGCTIME_ALT__FILT_SETTLE__MASK                   0xfe000000U
#define MDM_TWOMEG_AGCTIME_ALT__FILT_SETTLE__READ(src) \
                    (((uint32_t)(src)\
                    & 0xfe000000U) >> 25)
#define MDM_TWOMEG_AGCTIME_ALT__FILT_SETTLE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 25) & 0xfe000000U)
#define MDM_TWOMEG_AGCTIME_ALT__FILT_SETTLE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xfe000000U) | (((uint32_t)(src) <<\
                    25) & 0xfe000000U)
#define MDM_TWOMEG_AGCTIME_ALT__FILT_SETTLE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 25) & ~0xfe000000U)))
#define MDM_TWOMEG_AGCTIME_ALT__FILT_SETTLE__RESET_VALUE            0x00000010U
/** @} */
#define MDM_TWOMEG_AGCTIME_ALT__TYPE                                   uint32_t
#define MDM_TWOMEG_AGCTIME_ALT__READ                                0xfe00003fU
#define MDM_TWOMEG_AGCTIME_ALT__WRITE                               0xfe00003fU
#define MDM_TWOMEG_AGCTIME_ALT__PRESERVED                           0x00000000U
#define MDM_TWOMEG_AGCTIME_ALT__RESET_VALUE                         0x20000010U

#endif /* __MDM_TWOMEG_AGCTIME_ALT_MACRO__ */

/** @} end of twomeg_agctime_alt */

/* macros for BlueprintGlobalNameSpace::MDM_agctime2 */
/**
 * @defgroup mdm_regs_core_agctime2 agctime2
 * @brief agc delays definitions.
 * @{
 */
#ifndef __MDM_AGCTIME2_MACRO__
#define __MDM_AGCTIME2_MACRO__

/* macros for field rx_en_to_search */
/**
 * @defgroup mdm_regs_core_rx_en_to_search_field rx_en_to_search_field
 * @brief macros for field rx_en_to_search
 * @details number of 16 MHz clocks from rx_en assertion to agc start search. Need to keep in sync with rif registers for rxon and adcon.
 * @{
 */
#define MDM_AGCTIME2__RX_EN_TO_SEARCH__SHIFT                                  0
#define MDM_AGCTIME2__RX_EN_TO_SEARCH__WIDTH                                 11
#define MDM_AGCTIME2__RX_EN_TO_SEARCH__MASK                         0x000007ffU
#define MDM_AGCTIME2__RX_EN_TO_SEARCH__READ(src) \
                    ((uint32_t)(src)\
                    & 0x000007ffU)
#define MDM_AGCTIME2__RX_EN_TO_SEARCH__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x000007ffU)
#define MDM_AGCTIME2__RX_EN_TO_SEARCH__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000007ffU) | ((uint32_t)(src) &\
                    0x000007ffU)
#define MDM_AGCTIME2__RX_EN_TO_SEARCH__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000007ffU)))
#define MDM_AGCTIME2__RX_EN_TO_SEARCH__RESET_VALUE                  0x00000326U
/** @} */

/* macros for field lna_protect_settle */
/**
 * @defgroup mdm_regs_core_lna_protect_settle_field lna_protect_settle_field
 * @brief macros for field lna_protect_settle
 * @details When DC cal is bypassed, the number of 16 MHz clocks prior to transitioning to MEASURE to drop lna_protect
 * @{
 */
#define MDM_AGCTIME2__LNA_PROTECT_SETTLE__SHIFT                              11
#define MDM_AGCTIME2__LNA_PROTECT_SETTLE__WIDTH                               8
#define MDM_AGCTIME2__LNA_PROTECT_SETTLE__MASK                      0x0007f800U
#define MDM_AGCTIME2__LNA_PROTECT_SETTLE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0007f800U) >> 11)
#define MDM_AGCTIME2__LNA_PROTECT_SETTLE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 11) & 0x0007f800U)
#define MDM_AGCTIME2__LNA_PROTECT_SETTLE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0007f800U) | (((uint32_t)(src) <<\
                    11) & 0x0007f800U)
#define MDM_AGCTIME2__LNA_PROTECT_SETTLE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 11) & ~0x0007f800U)))
#define MDM_AGCTIME2__LNA_PROTECT_SETTLE__RESET_VALUE               0x00000020U
/** @} */

/* macros for field reset_filt_delay */
/**
 * @defgroup mdm_regs_core_reset_filt_delay_field reset_filt_delay_field
 * @brief macros for field reset_filt_delay
 * @details Number of 16 MHz clocks to hold agc filter in reset before releasing in the WAIT_GAIN_SETTLE state. MUST BE EVEN AND AT LEAST 4 AND LESS THAN OR EQUAL TO AGCTIME_GAIN_SETTLE. Register replicated for 2 Mb/s.
 * @{
 */
#define MDM_AGCTIME2__RESET_FILT_DELAY__SHIFT                                19
#define MDM_AGCTIME2__RESET_FILT_DELAY__WIDTH                                 6
#define MDM_AGCTIME2__RESET_FILT_DELAY__MASK                        0x01f80000U
#define MDM_AGCTIME2__RESET_FILT_DELAY__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01f80000U) >> 19)
#define MDM_AGCTIME2__RESET_FILT_DELAY__WRITE(src) \
                    (((uint32_t)(src)\
                    << 19) & 0x01f80000U)
#define MDM_AGCTIME2__RESET_FILT_DELAY__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01f80000U) | (((uint32_t)(src) <<\
                    19) & 0x01f80000U)
#define MDM_AGCTIME2__RESET_FILT_DELAY__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 19) & ~0x01f80000U)))
#define MDM_AGCTIME2__RESET_FILT_DELAY__RESET_VALUE                 0x00000010U
/** @} */

/* macros for field twomeg_reset_filt_delay */
/**
 * @defgroup mdm_regs_core_twomeg_reset_filt_delay_field twomeg_reset_filt_delay_field
 * @brief macros for field twomeg_reset_filt_delay
 * @details Number of 16 MHz clocks to hold agc filter in reset before releasing in the WAIT_GAIN_SETTLE state. MUST BE AT LEAST 4 AND LESS THAN OR EQUAL TO TWOMEG_AGCTIME_GAIN_SETTLE. 2 Mb/s version of this register
 * @{
 */
#define MDM_AGCTIME2__TWOMEG_RESET_FILT_DELAY__SHIFT                         25
#define MDM_AGCTIME2__TWOMEG_RESET_FILT_DELAY__WIDTH                          6
#define MDM_AGCTIME2__TWOMEG_RESET_FILT_DELAY__MASK                 0x7e000000U
#define MDM_AGCTIME2__TWOMEG_RESET_FILT_DELAY__READ(src) \
                    (((uint32_t)(src)\
                    & 0x7e000000U) >> 25)
#define MDM_AGCTIME2__TWOMEG_RESET_FILT_DELAY__WRITE(src) \
                    (((uint32_t)(src)\
                    << 25) & 0x7e000000U)
#define MDM_AGCTIME2__TWOMEG_RESET_FILT_DELAY__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x7e000000U) | (((uint32_t)(src) <<\
                    25) & 0x7e000000U)
#define MDM_AGCTIME2__TWOMEG_RESET_FILT_DELAY__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 25) & ~0x7e000000U)))
#define MDM_AGCTIME2__TWOMEG_RESET_FILT_DELAY__RESET_VALUE          0x0000000aU
/** @} */
#define MDM_AGCTIME2__TYPE                                             uint32_t
#define MDM_AGCTIME2__READ                                          0x7fffffffU
#define MDM_AGCTIME2__WRITE                                         0x7fffffffU
#define MDM_AGCTIME2__PRESERVED                                     0x00000000U
#define MDM_AGCTIME2__RESET_VALUE                                   0x14810326U

#endif /* __MDM_AGCTIME2_MACRO__ */

/** @} end of agctime2 */

/* macros for BlueprintGlobalNameSpace::MDM_agctime2_alt */
/**
 * @defgroup mdm_regs_core_agctime2_alt agctime2_alt
 * @brief agc delays, alternate set definitions.
 * @{
 */
#ifndef __MDM_AGCTIME2_ALT_MACRO__
#define __MDM_AGCTIME2_ALT_MACRO__

/* macros for field rx_en_to_search */
/**
 * @defgroup mdm_regs_core_rx_en_to_search_field rx_en_to_search_field
 * @brief macros for field rx_en_to_search
 * @details number of 16 MHz clocks from rx_en assertion to agc start search. Need to keep in sync with rif registers for rxon and adcon.
 * @{
 */
#define MDM_AGCTIME2_ALT__RX_EN_TO_SEARCH__SHIFT                              0
#define MDM_AGCTIME2_ALT__RX_EN_TO_SEARCH__WIDTH                             11
#define MDM_AGCTIME2_ALT__RX_EN_TO_SEARCH__MASK                     0x000007ffU
#define MDM_AGCTIME2_ALT__RX_EN_TO_SEARCH__READ(src) \
                    ((uint32_t)(src)\
                    & 0x000007ffU)
#define MDM_AGCTIME2_ALT__RX_EN_TO_SEARCH__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x000007ffU)
#define MDM_AGCTIME2_ALT__RX_EN_TO_SEARCH__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000007ffU) | ((uint32_t)(src) &\
                    0x000007ffU)
#define MDM_AGCTIME2_ALT__RX_EN_TO_SEARCH__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000007ffU)))
#define MDM_AGCTIME2_ALT__RX_EN_TO_SEARCH__RESET_VALUE              0x00000326U
/** @} */

/* macros for field lna_protect_settle */
/**
 * @defgroup mdm_regs_core_lna_protect_settle_field lna_protect_settle_field
 * @brief macros for field lna_protect_settle
 * @details When DC cal is bypassed, the number of 16 MHz clocks prior to transitioning to MEASURE to drop lna_protect
 * @{
 */
#define MDM_AGCTIME2_ALT__LNA_PROTECT_SETTLE__SHIFT                          11
#define MDM_AGCTIME2_ALT__LNA_PROTECT_SETTLE__WIDTH                           8
#define MDM_AGCTIME2_ALT__LNA_PROTECT_SETTLE__MASK                  0x0007f800U
#define MDM_AGCTIME2_ALT__LNA_PROTECT_SETTLE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0007f800U) >> 11)
#define MDM_AGCTIME2_ALT__LNA_PROTECT_SETTLE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 11) & 0x0007f800U)
#define MDM_AGCTIME2_ALT__LNA_PROTECT_SETTLE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0007f800U) | (((uint32_t)(src) <<\
                    11) & 0x0007f800U)
#define MDM_AGCTIME2_ALT__LNA_PROTECT_SETTLE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 11) & ~0x0007f800U)))
#define MDM_AGCTIME2_ALT__LNA_PROTECT_SETTLE__RESET_VALUE           0x00000020U
/** @} */

/* macros for field reset_filt_delay */
/**
 * @defgroup mdm_regs_core_reset_filt_delay_field reset_filt_delay_field
 * @brief macros for field reset_filt_delay
 * @details Number of 16 MHz clocks to hold agc filter in reset before releasing in the WAIT_GAIN_SETTLE state. MUST BE EVEN AND AT LEAST 4 AND LESS THAN OR EQUAL TO AGCTIME_GAIN_SETTLE. Register replicated for 2 Mb/s.
 * @{
 */
#define MDM_AGCTIME2_ALT__RESET_FILT_DELAY__SHIFT                            19
#define MDM_AGCTIME2_ALT__RESET_FILT_DELAY__WIDTH                             6
#define MDM_AGCTIME2_ALT__RESET_FILT_DELAY__MASK                    0x01f80000U
#define MDM_AGCTIME2_ALT__RESET_FILT_DELAY__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01f80000U) >> 19)
#define MDM_AGCTIME2_ALT__RESET_FILT_DELAY__WRITE(src) \
                    (((uint32_t)(src)\
                    << 19) & 0x01f80000U)
#define MDM_AGCTIME2_ALT__RESET_FILT_DELAY__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01f80000U) | (((uint32_t)(src) <<\
                    19) & 0x01f80000U)
#define MDM_AGCTIME2_ALT__RESET_FILT_DELAY__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 19) & ~0x01f80000U)))
#define MDM_AGCTIME2_ALT__RESET_FILT_DELAY__RESET_VALUE             0x00000010U
/** @} */

/* macros for field twomeg_reset_filt_delay */
/**
 * @defgroup mdm_regs_core_twomeg_reset_filt_delay_field twomeg_reset_filt_delay_field
 * @brief macros for field twomeg_reset_filt_delay
 * @details Number of 16 MHz clocks to hold agc filter in reset before releasing in the WAIT_GAIN_SETTLE state. MUST BE AT LEAST 4 AND LESS THAN OR EQUAL TO TWOMEG_AGCTIME_GAIN_SETTLE. 2 Mb/s version of this register
 * @{
 */
#define MDM_AGCTIME2_ALT__TWOMEG_RESET_FILT_DELAY__SHIFT                     25
#define MDM_AGCTIME2_ALT__TWOMEG_RESET_FILT_DELAY__WIDTH                      6
#define MDM_AGCTIME2_ALT__TWOMEG_RESET_FILT_DELAY__MASK             0x7e000000U
#define MDM_AGCTIME2_ALT__TWOMEG_RESET_FILT_DELAY__READ(src) \
                    (((uint32_t)(src)\
                    & 0x7e000000U) >> 25)
#define MDM_AGCTIME2_ALT__TWOMEG_RESET_FILT_DELAY__WRITE(src) \
                    (((uint32_t)(src)\
                    << 25) & 0x7e000000U)
#define MDM_AGCTIME2_ALT__TWOMEG_RESET_FILT_DELAY__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x7e000000U) | (((uint32_t)(src) <<\
                    25) & 0x7e000000U)
#define MDM_AGCTIME2_ALT__TWOMEG_RESET_FILT_DELAY__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 25) & ~0x7e000000U)))
#define MDM_AGCTIME2_ALT__TWOMEG_RESET_FILT_DELAY__RESET_VALUE      0x0000000aU
/** @} */
#define MDM_AGCTIME2_ALT__TYPE                                         uint32_t
#define MDM_AGCTIME2_ALT__READ                                      0x7fffffffU
#define MDM_AGCTIME2_ALT__WRITE                                     0x7fffffffU
#define MDM_AGCTIME2_ALT__PRESERVED                                 0x00000000U
#define MDM_AGCTIME2_ALT__RESET_VALUE                               0x14810326U

#endif /* __MDM_AGCTIME2_ALT_MACRO__ */

/** @} end of agctime2_alt */

/* macros for BlueprintGlobalNameSpace::MDM_agccntl */
/**
 * @defgroup mdm_regs_core_agccntl agccntl
 * @brief agc control definitions.
 * @{
 */
#ifndef __MDM_AGCCNTL_MACRO__
#define __MDM_AGCCNTL_MACRO__

/* macros for field enable_rfin_peakdet */
/**
 * @defgroup mdm_regs_core_enable_rfin_peakdet_field enable_rfin_peakdet_field
 * @brief macros for field enable_rfin_peakdet
 * @details RX state machine will observe lna_peakdet
 * @{
 */
#define MDM_AGCCNTL__ENABLE_RFIN_PEAKDET__SHIFT                               0
#define MDM_AGCCNTL__ENABLE_RFIN_PEAKDET__WIDTH                               1
#define MDM_AGCCNTL__ENABLE_RFIN_PEAKDET__MASK                      0x00000001U
#define MDM_AGCCNTL__ENABLE_RFIN_PEAKDET__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define MDM_AGCCNTL__ENABLE_RFIN_PEAKDET__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define MDM_AGCCNTL__ENABLE_RFIN_PEAKDET__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define MDM_AGCCNTL__ENABLE_RFIN_PEAKDET__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define MDM_AGCCNTL__ENABLE_RFIN_PEAKDET__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define MDM_AGCCNTL__ENABLE_RFIN_PEAKDET__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define MDM_AGCCNTL__ENABLE_RFIN_PEAKDET__RESET_VALUE               0x00000001U
/** @} */

/* macros for field enable_tia_peakdet */
/**
 * @defgroup mdm_regs_core_enable_tia_peakdet_field enable_tia_peakdet_field
 * @brief macros for field enable_tia_peakdet
 * @details RX state machine will observe tia_peakdet
 * @{
 */
#define MDM_AGCCNTL__ENABLE_TIA_PEAKDET__SHIFT                                1
#define MDM_AGCCNTL__ENABLE_TIA_PEAKDET__WIDTH                                1
#define MDM_AGCCNTL__ENABLE_TIA_PEAKDET__MASK                       0x00000002U
#define MDM_AGCCNTL__ENABLE_TIA_PEAKDET__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define MDM_AGCCNTL__ENABLE_TIA_PEAKDET__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define MDM_AGCCNTL__ENABLE_TIA_PEAKDET__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define MDM_AGCCNTL__ENABLE_TIA_PEAKDET__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define MDM_AGCCNTL__ENABLE_TIA_PEAKDET__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define MDM_AGCCNTL__ENABLE_TIA_PEAKDET__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define MDM_AGCCNTL__ENABLE_TIA_PEAKDET__RESET_VALUE                0x00000001U
/** @} */

/* macros for field max */
/**
 * @defgroup mdm_regs_core_max_field max_field
 * @brief macros for field max
 * @details Max RX gain
 * @{
 */
#define MDM_AGCCNTL__MAX__SHIFT                                               2
#define MDM_AGCCNTL__MAX__WIDTH                                               7
#define MDM_AGCCNTL__MAX__MASK                                      0x000001fcU
#define MDM_AGCCNTL__MAX__READ(src)      (((uint32_t)(src) & 0x000001fcU) >> 2)
#define MDM_AGCCNTL__MAX__WRITE(src)     (((uint32_t)(src) << 2) & 0x000001fcU)
#define MDM_AGCCNTL__MAX__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000001fcU) | (((uint32_t)(src) <<\
                    2) & 0x000001fcU)
#define MDM_AGCCNTL__MAX__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x000001fcU)))
#define MDM_AGCCNTL__MAX__RESET_VALUE                               0x0000004cU
/** @} */

/* macros for field force_rxgain */
/**
 * @defgroup mdm_regs_core_force_rxgain_field force_rxgain_field
 * @brief macros for field force_rxgain
 * @details If set, force rxgain
 * @{
 */
#define MDM_AGCCNTL__FORCE_RXGAIN__SHIFT                                      9
#define MDM_AGCCNTL__FORCE_RXGAIN__WIDTH                                      1
#define MDM_AGCCNTL__FORCE_RXGAIN__MASK                             0x00000200U
#define MDM_AGCCNTL__FORCE_RXGAIN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000200U) >> 9)
#define MDM_AGCCNTL__FORCE_RXGAIN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x00000200U)
#define MDM_AGCCNTL__FORCE_RXGAIN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | (((uint32_t)(src) <<\
                    9) & 0x00000200U)
#define MDM_AGCCNTL__FORCE_RXGAIN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x00000200U)))
#define MDM_AGCCNTL__FORCE_RXGAIN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | ((uint32_t)(1) << 9)
#define MDM_AGCCNTL__FORCE_RXGAIN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | ((uint32_t)(0) << 9)
#define MDM_AGCCNTL__FORCE_RXGAIN__RESET_VALUE                      0x00000000U
/** @} */

/* macros for field forced_rxgain_value */
/**
 * @defgroup mdm_regs_core_forced_rxgain_value_field forced_rxgain_value_field
 * @brief macros for field forced_rxgain_value
 * @details When rxgain forced, use this value
 * @{
 */
#define MDM_AGCCNTL__FORCED_RXGAIN_VALUE__SHIFT                              10
#define MDM_AGCCNTL__FORCED_RXGAIN_VALUE__WIDTH                               7
#define MDM_AGCCNTL__FORCED_RXGAIN_VALUE__MASK                      0x0001fc00U
#define MDM_AGCCNTL__FORCED_RXGAIN_VALUE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0001fc00U) >> 10)
#define MDM_AGCCNTL__FORCED_RXGAIN_VALUE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x0001fc00U)
#define MDM_AGCCNTL__FORCED_RXGAIN_VALUE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0001fc00U) | (((uint32_t)(src) <<\
                    10) & 0x0001fc00U)
#define MDM_AGCCNTL__FORCED_RXGAIN_VALUE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x0001fc00U)))
#define MDM_AGCCNTL__FORCED_RXGAIN_VALUE__RESET_VALUE               0x00000005U
/** @} */

/* macros for field allow_sat_after_peak */
/**
 * @defgroup mdm_regs_core_allow_sat_after_peak_field allow_sat_after_peak_field
 * @brief macros for field allow_sat_after_peak
 * @details After a peak detect, allow a saturation detect prior to the automatic fine gain change
 * @{
 */
#define MDM_AGCCNTL__ALLOW_SAT_AFTER_PEAK__SHIFT                             17
#define MDM_AGCCNTL__ALLOW_SAT_AFTER_PEAK__WIDTH                              1
#define MDM_AGCCNTL__ALLOW_SAT_AFTER_PEAK__MASK                     0x00020000U
#define MDM_AGCCNTL__ALLOW_SAT_AFTER_PEAK__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00020000U) >> 17)
#define MDM_AGCCNTL__ALLOW_SAT_AFTER_PEAK__WRITE(src) \
                    (((uint32_t)(src)\
                    << 17) & 0x00020000U)
#define MDM_AGCCNTL__ALLOW_SAT_AFTER_PEAK__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | (((uint32_t)(src) <<\
                    17) & 0x00020000U)
#define MDM_AGCCNTL__ALLOW_SAT_AFTER_PEAK__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 17) & ~0x00020000U)))
#define MDM_AGCCNTL__ALLOW_SAT_AFTER_PEAK__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(1) << 17)
#define MDM_AGCCNTL__ALLOW_SAT_AFTER_PEAK__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(0) << 17)
#define MDM_AGCCNTL__ALLOW_SAT_AFTER_PEAK__RESET_VALUE              0x00000001U
/** @} */

/* macros for field allow_sat_after_sat */
/**
 * @defgroup mdm_regs_core_allow_sat_after_sat_field allow_sat_after_sat_field
 * @brief macros for field allow_sat_after_sat
 * @details After a saturation detect, allow another saturation detect prior to the automatic fine gain change
 * @{
 */
#define MDM_AGCCNTL__ALLOW_SAT_AFTER_SAT__SHIFT                              18
#define MDM_AGCCNTL__ALLOW_SAT_AFTER_SAT__WIDTH                               1
#define MDM_AGCCNTL__ALLOW_SAT_AFTER_SAT__MASK                      0x00040000U
#define MDM_AGCCNTL__ALLOW_SAT_AFTER_SAT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00040000U) >> 18)
#define MDM_AGCCNTL__ALLOW_SAT_AFTER_SAT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0x00040000U)
#define MDM_AGCCNTL__ALLOW_SAT_AFTER_SAT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | (((uint32_t)(src) <<\
                    18) & 0x00040000U)
#define MDM_AGCCNTL__ALLOW_SAT_AFTER_SAT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x00040000U)))
#define MDM_AGCCNTL__ALLOW_SAT_AFTER_SAT__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(1) << 18)
#define MDM_AGCCNTL__ALLOW_SAT_AFTER_SAT__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(0) << 18)
#define MDM_AGCCNTL__ALLOW_SAT_AFTER_SAT__RESET_VALUE               0x00000001U
/** @} */

/* macros for field bypass_rxfir */
/**
 * @defgroup mdm_regs_core_bypass_rxfir_field bypass_rxfir_field
 * @brief macros for field bypass_rxfir
 * @details When set, RXFIR output = RXFIR input. Register replicated for 2 Mb/s
 * @{
 */
#define MDM_AGCCNTL__BYPASS_RXFIR__SHIFT                                     19
#define MDM_AGCCNTL__BYPASS_RXFIR__WIDTH                                      1
#define MDM_AGCCNTL__BYPASS_RXFIR__MASK                             0x00080000U
#define MDM_AGCCNTL__BYPASS_RXFIR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00080000U) >> 19)
#define MDM_AGCCNTL__BYPASS_RXFIR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 19) & 0x00080000U)
#define MDM_AGCCNTL__BYPASS_RXFIR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | (((uint32_t)(src) <<\
                    19) & 0x00080000U)
#define MDM_AGCCNTL__BYPASS_RXFIR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 19) & ~0x00080000U)))
#define MDM_AGCCNTL__BYPASS_RXFIR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | ((uint32_t)(1) << 19)
#define MDM_AGCCNTL__BYPASS_RXFIR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | ((uint32_t)(0) << 19)
#define MDM_AGCCNTL__BYPASS_RXFIR__RESET_VALUE                      0x00000000U
/** @} */

/* macros for field twomeg_bypass_rxfir */
/**
 * @defgroup mdm_regs_core_twomeg_bypass_rxfir_field twomeg_bypass_rxfir_field
 * @brief macros for field twomeg_bypass_rxfir
 * @details When set, RXFIR output = RXFIR input 2 Mb/s version of register
 * @{
 */
#define MDM_AGCCNTL__TWOMEG_BYPASS_RXFIR__SHIFT                              20
#define MDM_AGCCNTL__TWOMEG_BYPASS_RXFIR__WIDTH                               1
#define MDM_AGCCNTL__TWOMEG_BYPASS_RXFIR__MASK                      0x00100000U
#define MDM_AGCCNTL__TWOMEG_BYPASS_RXFIR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00100000U) >> 20)
#define MDM_AGCCNTL__TWOMEG_BYPASS_RXFIR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 20) & 0x00100000U)
#define MDM_AGCCNTL__TWOMEG_BYPASS_RXFIR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00100000U) | (((uint32_t)(src) <<\
                    20) & 0x00100000U)
#define MDM_AGCCNTL__TWOMEG_BYPASS_RXFIR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x00100000U)))
#define MDM_AGCCNTL__TWOMEG_BYPASS_RXFIR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00100000U) | ((uint32_t)(1) << 20)
#define MDM_AGCCNTL__TWOMEG_BYPASS_RXFIR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00100000U) | ((uint32_t)(0) << 20)
#define MDM_AGCCNTL__TWOMEG_BYPASS_RXFIR__RESET_VALUE               0x00000000U
/** @} */

/* macros for field min_rxgain_increase */
/**
 * @defgroup mdm_regs_core_min_rxgain_increase_field min_rxgain_increase_field
 * @brief macros for field min_rxgain_increase
 * @details Minimum amount of rxgain increase
 * @{
 */
#define MDM_AGCCNTL__MIN_RXGAIN_INCREASE__SHIFT                              21
#define MDM_AGCCNTL__MIN_RXGAIN_INCREASE__WIDTH                               4
#define MDM_AGCCNTL__MIN_RXGAIN_INCREASE__MASK                      0x01e00000U
#define MDM_AGCCNTL__MIN_RXGAIN_INCREASE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01e00000U) >> 21)
#define MDM_AGCCNTL__MIN_RXGAIN_INCREASE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 21) & 0x01e00000U)
#define MDM_AGCCNTL__MIN_RXGAIN_INCREASE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01e00000U) | (((uint32_t)(src) <<\
                    21) & 0x01e00000U)
#define MDM_AGCCNTL__MIN_RXGAIN_INCREASE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 21) & ~0x01e00000U)))
#define MDM_AGCCNTL__MIN_RXGAIN_INCREASE__RESET_VALUE               0x00000003U
/** @} */

/* macros for field min_rxgain_decrease */
/**
 * @defgroup mdm_regs_core_min_rxgain_decrease_field min_rxgain_decrease_field
 * @brief macros for field min_rxgain_decrease
 * @details Minimum amount of rxgain decrease
 * @{
 */
#define MDM_AGCCNTL__MIN_RXGAIN_DECREASE__SHIFT                              25
#define MDM_AGCCNTL__MIN_RXGAIN_DECREASE__WIDTH                               4
#define MDM_AGCCNTL__MIN_RXGAIN_DECREASE__MASK                      0x1e000000U
#define MDM_AGCCNTL__MIN_RXGAIN_DECREASE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x1e000000U) >> 25)
#define MDM_AGCCNTL__MIN_RXGAIN_DECREASE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 25) & 0x1e000000U)
#define MDM_AGCCNTL__MIN_RXGAIN_DECREASE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x1e000000U) | (((uint32_t)(src) <<\
                    25) & 0x1e000000U)
#define MDM_AGCCNTL__MIN_RXGAIN_DECREASE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 25) & ~0x1e000000U)))
#define MDM_AGCCNTL__MIN_RXGAIN_DECREASE__RESET_VALUE               0x00000006U
/** @} */

/* macros for field enable_iqcorr */
/**
 * @defgroup mdm_regs_core_enable_iqcorr_field enable_iqcorr_field
 * @brief macros for field enable_iqcorr
 * @details Enable for 1 Mb/s or coded
 * @{
 */
#define MDM_AGCCNTL__ENABLE_IQCORR__SHIFT                                    29
#define MDM_AGCCNTL__ENABLE_IQCORR__WIDTH                                     1
#define MDM_AGCCNTL__ENABLE_IQCORR__MASK                            0x20000000U
#define MDM_AGCCNTL__ENABLE_IQCORR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x20000000U) >> 29)
#define MDM_AGCCNTL__ENABLE_IQCORR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 29) & 0x20000000U)
#define MDM_AGCCNTL__ENABLE_IQCORR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | (((uint32_t)(src) <<\
                    29) & 0x20000000U)
#define MDM_AGCCNTL__ENABLE_IQCORR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 29) & ~0x20000000U)))
#define MDM_AGCCNTL__ENABLE_IQCORR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | ((uint32_t)(1) << 29)
#define MDM_AGCCNTL__ENABLE_IQCORR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | ((uint32_t)(0) << 29)
#define MDM_AGCCNTL__ENABLE_IQCORR__RESET_VALUE                     0x00000000U
/** @} */

/* macros for field twomeg_enable_iqcorr */
/**
 * @defgroup mdm_regs_core_twomeg_enable_iqcorr_field twomeg_enable_iqcorr_field
 * @brief macros for field twomeg_enable_iqcorr
 * @details Enable for 2 Mb/s
 * @{
 */
#define MDM_AGCCNTL__TWOMEG_ENABLE_IQCORR__SHIFT                             30
#define MDM_AGCCNTL__TWOMEG_ENABLE_IQCORR__WIDTH                              1
#define MDM_AGCCNTL__TWOMEG_ENABLE_IQCORR__MASK                     0x40000000U
#define MDM_AGCCNTL__TWOMEG_ENABLE_IQCORR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x40000000U) >> 30)
#define MDM_AGCCNTL__TWOMEG_ENABLE_IQCORR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 30) & 0x40000000U)
#define MDM_AGCCNTL__TWOMEG_ENABLE_IQCORR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | (((uint32_t)(src) <<\
                    30) & 0x40000000U)
#define MDM_AGCCNTL__TWOMEG_ENABLE_IQCORR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 30) & ~0x40000000U)))
#define MDM_AGCCNTL__TWOMEG_ENABLE_IQCORR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(1) << 30)
#define MDM_AGCCNTL__TWOMEG_ENABLE_IQCORR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(0) << 30)
#define MDM_AGCCNTL__TWOMEG_ENABLE_IQCORR__RESET_VALUE              0x00000000U
/** @} */
#define MDM_AGCCNTL__TYPE                                              uint32_t
#define MDM_AGCCNTL__READ                                           0x7fffffffU
#define MDM_AGCCNTL__WRITE                                          0x7fffffffU
#define MDM_AGCCNTL__PRESERVED                                      0x00000000U
#define MDM_AGCCNTL__RESET_VALUE                                    0x0c661533U

#endif /* __MDM_AGCCNTL_MACRO__ */

/** @} end of agccntl */

/* macros for BlueprintGlobalNameSpace::MDM_agccntl_alt */
/**
 * @defgroup mdm_regs_core_agccntl_alt agccntl_alt
 * @brief agc control, alternate set definitions.
 * @{
 */
#ifndef __MDM_AGCCNTL_ALT_MACRO__
#define __MDM_AGCCNTL_ALT_MACRO__

/* macros for field enable_rfin_peakdet */
/**
 * @defgroup mdm_regs_core_enable_rfin_peakdet_field enable_rfin_peakdet_field
 * @brief macros for field enable_rfin_peakdet
 * @details RX state machine will observe lna_peakdet
 * @{
 */
#define MDM_AGCCNTL_ALT__ENABLE_RFIN_PEAKDET__SHIFT                           0
#define MDM_AGCCNTL_ALT__ENABLE_RFIN_PEAKDET__WIDTH                           1
#define MDM_AGCCNTL_ALT__ENABLE_RFIN_PEAKDET__MASK                  0x00000001U
#define MDM_AGCCNTL_ALT__ENABLE_RFIN_PEAKDET__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define MDM_AGCCNTL_ALT__ENABLE_RFIN_PEAKDET__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define MDM_AGCCNTL_ALT__ENABLE_RFIN_PEAKDET__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define MDM_AGCCNTL_ALT__ENABLE_RFIN_PEAKDET__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define MDM_AGCCNTL_ALT__ENABLE_RFIN_PEAKDET__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define MDM_AGCCNTL_ALT__ENABLE_RFIN_PEAKDET__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define MDM_AGCCNTL_ALT__ENABLE_RFIN_PEAKDET__RESET_VALUE           0x00000001U
/** @} */

/* macros for field enable_tia_peakdet */
/**
 * @defgroup mdm_regs_core_enable_tia_peakdet_field enable_tia_peakdet_field
 * @brief macros for field enable_tia_peakdet
 * @details RX state machine will observe tia_peakdet
 * @{
 */
#define MDM_AGCCNTL_ALT__ENABLE_TIA_PEAKDET__SHIFT                            1
#define MDM_AGCCNTL_ALT__ENABLE_TIA_PEAKDET__WIDTH                            1
#define MDM_AGCCNTL_ALT__ENABLE_TIA_PEAKDET__MASK                   0x00000002U
#define MDM_AGCCNTL_ALT__ENABLE_TIA_PEAKDET__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define MDM_AGCCNTL_ALT__ENABLE_TIA_PEAKDET__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define MDM_AGCCNTL_ALT__ENABLE_TIA_PEAKDET__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define MDM_AGCCNTL_ALT__ENABLE_TIA_PEAKDET__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define MDM_AGCCNTL_ALT__ENABLE_TIA_PEAKDET__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define MDM_AGCCNTL_ALT__ENABLE_TIA_PEAKDET__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define MDM_AGCCNTL_ALT__ENABLE_TIA_PEAKDET__RESET_VALUE            0x00000001U
/** @} */

/* macros for field max */
/**
 * @defgroup mdm_regs_core_max_field max_field
 * @brief macros for field max
 * @details Max RX gain
 * @{
 */
#define MDM_AGCCNTL_ALT__MAX__SHIFT                                           2
#define MDM_AGCCNTL_ALT__MAX__WIDTH                                           7
#define MDM_AGCCNTL_ALT__MAX__MASK                                  0x000001fcU
#define MDM_AGCCNTL_ALT__MAX__READ(src)  (((uint32_t)(src) & 0x000001fcU) >> 2)
#define MDM_AGCCNTL_ALT__MAX__WRITE(src) (((uint32_t)(src) << 2) & 0x000001fcU)
#define MDM_AGCCNTL_ALT__MAX__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000001fcU) | (((uint32_t)(src) <<\
                    2) & 0x000001fcU)
#define MDM_AGCCNTL_ALT__MAX__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x000001fcU)))
#define MDM_AGCCNTL_ALT__MAX__RESET_VALUE                           0x0000004cU
/** @} */

/* macros for field force_rxgain */
/**
 * @defgroup mdm_regs_core_force_rxgain_field force_rxgain_field
 * @brief macros for field force_rxgain
 * @details If set, force rxgain
 * @{
 */
#define MDM_AGCCNTL_ALT__FORCE_RXGAIN__SHIFT                                  9
#define MDM_AGCCNTL_ALT__FORCE_RXGAIN__WIDTH                                  1
#define MDM_AGCCNTL_ALT__FORCE_RXGAIN__MASK                         0x00000200U
#define MDM_AGCCNTL_ALT__FORCE_RXGAIN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000200U) >> 9)
#define MDM_AGCCNTL_ALT__FORCE_RXGAIN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x00000200U)
#define MDM_AGCCNTL_ALT__FORCE_RXGAIN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | (((uint32_t)(src) <<\
                    9) & 0x00000200U)
#define MDM_AGCCNTL_ALT__FORCE_RXGAIN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x00000200U)))
#define MDM_AGCCNTL_ALT__FORCE_RXGAIN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | ((uint32_t)(1) << 9)
#define MDM_AGCCNTL_ALT__FORCE_RXGAIN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | ((uint32_t)(0) << 9)
#define MDM_AGCCNTL_ALT__FORCE_RXGAIN__RESET_VALUE                  0x00000000U
/** @} */

/* macros for field forced_rxgain_value */
/**
 * @defgroup mdm_regs_core_forced_rxgain_value_field forced_rxgain_value_field
 * @brief macros for field forced_rxgain_value
 * @details When rxgain forced, use this value
 * @{
 */
#define MDM_AGCCNTL_ALT__FORCED_RXGAIN_VALUE__SHIFT                          10
#define MDM_AGCCNTL_ALT__FORCED_RXGAIN_VALUE__WIDTH                           7
#define MDM_AGCCNTL_ALT__FORCED_RXGAIN_VALUE__MASK                  0x0001fc00U
#define MDM_AGCCNTL_ALT__FORCED_RXGAIN_VALUE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0001fc00U) >> 10)
#define MDM_AGCCNTL_ALT__FORCED_RXGAIN_VALUE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x0001fc00U)
#define MDM_AGCCNTL_ALT__FORCED_RXGAIN_VALUE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0001fc00U) | (((uint32_t)(src) <<\
                    10) & 0x0001fc00U)
#define MDM_AGCCNTL_ALT__FORCED_RXGAIN_VALUE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x0001fc00U)))
#define MDM_AGCCNTL_ALT__FORCED_RXGAIN_VALUE__RESET_VALUE           0x00000005U
/** @} */

/* macros for field allow_sat_after_peak */
/**
 * @defgroup mdm_regs_core_allow_sat_after_peak_field allow_sat_after_peak_field
 * @brief macros for field allow_sat_after_peak
 * @details After a peak detect, allow a saturation detect prior to the automatic fine gain change
 * @{
 */
#define MDM_AGCCNTL_ALT__ALLOW_SAT_AFTER_PEAK__SHIFT                         17
#define MDM_AGCCNTL_ALT__ALLOW_SAT_AFTER_PEAK__WIDTH                          1
#define MDM_AGCCNTL_ALT__ALLOW_SAT_AFTER_PEAK__MASK                 0x00020000U
#define MDM_AGCCNTL_ALT__ALLOW_SAT_AFTER_PEAK__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00020000U) >> 17)
#define MDM_AGCCNTL_ALT__ALLOW_SAT_AFTER_PEAK__WRITE(src) \
                    (((uint32_t)(src)\
                    << 17) & 0x00020000U)
#define MDM_AGCCNTL_ALT__ALLOW_SAT_AFTER_PEAK__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | (((uint32_t)(src) <<\
                    17) & 0x00020000U)
#define MDM_AGCCNTL_ALT__ALLOW_SAT_AFTER_PEAK__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 17) & ~0x00020000U)))
#define MDM_AGCCNTL_ALT__ALLOW_SAT_AFTER_PEAK__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(1) << 17)
#define MDM_AGCCNTL_ALT__ALLOW_SAT_AFTER_PEAK__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(0) << 17)
#define MDM_AGCCNTL_ALT__ALLOW_SAT_AFTER_PEAK__RESET_VALUE          0x00000001U
/** @} */

/* macros for field allow_sat_after_sat */
/**
 * @defgroup mdm_regs_core_allow_sat_after_sat_field allow_sat_after_sat_field
 * @brief macros for field allow_sat_after_sat
 * @details After a saturation detect, allow another saturation detect prior to the automatic fine gain change
 * @{
 */
#define MDM_AGCCNTL_ALT__ALLOW_SAT_AFTER_SAT__SHIFT                          18
#define MDM_AGCCNTL_ALT__ALLOW_SAT_AFTER_SAT__WIDTH                           1
#define MDM_AGCCNTL_ALT__ALLOW_SAT_AFTER_SAT__MASK                  0x00040000U
#define MDM_AGCCNTL_ALT__ALLOW_SAT_AFTER_SAT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00040000U) >> 18)
#define MDM_AGCCNTL_ALT__ALLOW_SAT_AFTER_SAT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0x00040000U)
#define MDM_AGCCNTL_ALT__ALLOW_SAT_AFTER_SAT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | (((uint32_t)(src) <<\
                    18) & 0x00040000U)
#define MDM_AGCCNTL_ALT__ALLOW_SAT_AFTER_SAT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x00040000U)))
#define MDM_AGCCNTL_ALT__ALLOW_SAT_AFTER_SAT__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(1) << 18)
#define MDM_AGCCNTL_ALT__ALLOW_SAT_AFTER_SAT__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(0) << 18)
#define MDM_AGCCNTL_ALT__ALLOW_SAT_AFTER_SAT__RESET_VALUE           0x00000001U
/** @} */

/* macros for field bypass_rxfir */
/**
 * @defgroup mdm_regs_core_bypass_rxfir_field bypass_rxfir_field
 * @brief macros for field bypass_rxfir
 * @details When set, RXFIR output = RXFIR input. Register replicated for 2 Mb/s
 * @{
 */
#define MDM_AGCCNTL_ALT__BYPASS_RXFIR__SHIFT                                 19
#define MDM_AGCCNTL_ALT__BYPASS_RXFIR__WIDTH                                  1
#define MDM_AGCCNTL_ALT__BYPASS_RXFIR__MASK                         0x00080000U
#define MDM_AGCCNTL_ALT__BYPASS_RXFIR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00080000U) >> 19)
#define MDM_AGCCNTL_ALT__BYPASS_RXFIR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 19) & 0x00080000U)
#define MDM_AGCCNTL_ALT__BYPASS_RXFIR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | (((uint32_t)(src) <<\
                    19) & 0x00080000U)
#define MDM_AGCCNTL_ALT__BYPASS_RXFIR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 19) & ~0x00080000U)))
#define MDM_AGCCNTL_ALT__BYPASS_RXFIR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | ((uint32_t)(1) << 19)
#define MDM_AGCCNTL_ALT__BYPASS_RXFIR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | ((uint32_t)(0) << 19)
#define MDM_AGCCNTL_ALT__BYPASS_RXFIR__RESET_VALUE                  0x00000000U
/** @} */

/* macros for field twomeg_bypass_rxfir */
/**
 * @defgroup mdm_regs_core_twomeg_bypass_rxfir_field twomeg_bypass_rxfir_field
 * @brief macros for field twomeg_bypass_rxfir
 * @details When set, RXFIR output = RXFIR input 2 Mb/s version of register
 * @{
 */
#define MDM_AGCCNTL_ALT__TWOMEG_BYPASS_RXFIR__SHIFT                          20
#define MDM_AGCCNTL_ALT__TWOMEG_BYPASS_RXFIR__WIDTH                           1
#define MDM_AGCCNTL_ALT__TWOMEG_BYPASS_RXFIR__MASK                  0x00100000U
#define MDM_AGCCNTL_ALT__TWOMEG_BYPASS_RXFIR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00100000U) >> 20)
#define MDM_AGCCNTL_ALT__TWOMEG_BYPASS_RXFIR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 20) & 0x00100000U)
#define MDM_AGCCNTL_ALT__TWOMEG_BYPASS_RXFIR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00100000U) | (((uint32_t)(src) <<\
                    20) & 0x00100000U)
#define MDM_AGCCNTL_ALT__TWOMEG_BYPASS_RXFIR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x00100000U)))
#define MDM_AGCCNTL_ALT__TWOMEG_BYPASS_RXFIR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00100000U) | ((uint32_t)(1) << 20)
#define MDM_AGCCNTL_ALT__TWOMEG_BYPASS_RXFIR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00100000U) | ((uint32_t)(0) << 20)
#define MDM_AGCCNTL_ALT__TWOMEG_BYPASS_RXFIR__RESET_VALUE           0x00000000U
/** @} */

/* macros for field min_rxgain_increase */
/**
 * @defgroup mdm_regs_core_min_rxgain_increase_field min_rxgain_increase_field
 * @brief macros for field min_rxgain_increase
 * @details Minimum amount of rxgain increase
 * @{
 */
#define MDM_AGCCNTL_ALT__MIN_RXGAIN_INCREASE__SHIFT                          21
#define MDM_AGCCNTL_ALT__MIN_RXGAIN_INCREASE__WIDTH                           4
#define MDM_AGCCNTL_ALT__MIN_RXGAIN_INCREASE__MASK                  0x01e00000U
#define MDM_AGCCNTL_ALT__MIN_RXGAIN_INCREASE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01e00000U) >> 21)
#define MDM_AGCCNTL_ALT__MIN_RXGAIN_INCREASE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 21) & 0x01e00000U)
#define MDM_AGCCNTL_ALT__MIN_RXGAIN_INCREASE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01e00000U) | (((uint32_t)(src) <<\
                    21) & 0x01e00000U)
#define MDM_AGCCNTL_ALT__MIN_RXGAIN_INCREASE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 21) & ~0x01e00000U)))
#define MDM_AGCCNTL_ALT__MIN_RXGAIN_INCREASE__RESET_VALUE           0x00000003U
/** @} */

/* macros for field min_rxgain_decrease */
/**
 * @defgroup mdm_regs_core_min_rxgain_decrease_field min_rxgain_decrease_field
 * @brief macros for field min_rxgain_decrease
 * @details Minimum amount of rxgain decrease
 * @{
 */
#define MDM_AGCCNTL_ALT__MIN_RXGAIN_DECREASE__SHIFT                          25
#define MDM_AGCCNTL_ALT__MIN_RXGAIN_DECREASE__WIDTH                           4
#define MDM_AGCCNTL_ALT__MIN_RXGAIN_DECREASE__MASK                  0x1e000000U
#define MDM_AGCCNTL_ALT__MIN_RXGAIN_DECREASE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x1e000000U) >> 25)
#define MDM_AGCCNTL_ALT__MIN_RXGAIN_DECREASE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 25) & 0x1e000000U)
#define MDM_AGCCNTL_ALT__MIN_RXGAIN_DECREASE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x1e000000U) | (((uint32_t)(src) <<\
                    25) & 0x1e000000U)
#define MDM_AGCCNTL_ALT__MIN_RXGAIN_DECREASE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 25) & ~0x1e000000U)))
#define MDM_AGCCNTL_ALT__MIN_RXGAIN_DECREASE__RESET_VALUE           0x00000006U
/** @} */

/* macros for field enable_iqcorr */
/**
 * @defgroup mdm_regs_core_enable_iqcorr_field enable_iqcorr_field
 * @brief macros for field enable_iqcorr
 * @details Enable for 1 Mb/s or coded
 * @{
 */
#define MDM_AGCCNTL_ALT__ENABLE_IQCORR__SHIFT                                29
#define MDM_AGCCNTL_ALT__ENABLE_IQCORR__WIDTH                                 1
#define MDM_AGCCNTL_ALT__ENABLE_IQCORR__MASK                        0x20000000U
#define MDM_AGCCNTL_ALT__ENABLE_IQCORR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x20000000U) >> 29)
#define MDM_AGCCNTL_ALT__ENABLE_IQCORR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 29) & 0x20000000U)
#define MDM_AGCCNTL_ALT__ENABLE_IQCORR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | (((uint32_t)(src) <<\
                    29) & 0x20000000U)
#define MDM_AGCCNTL_ALT__ENABLE_IQCORR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 29) & ~0x20000000U)))
#define MDM_AGCCNTL_ALT__ENABLE_IQCORR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | ((uint32_t)(1) << 29)
#define MDM_AGCCNTL_ALT__ENABLE_IQCORR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | ((uint32_t)(0) << 29)
#define MDM_AGCCNTL_ALT__ENABLE_IQCORR__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field twomeg_enable_iqcorr */
/**
 * @defgroup mdm_regs_core_twomeg_enable_iqcorr_field twomeg_enable_iqcorr_field
 * @brief macros for field twomeg_enable_iqcorr
 * @details Enable for 2 Mb/s
 * @{
 */
#define MDM_AGCCNTL_ALT__TWOMEG_ENABLE_IQCORR__SHIFT                         30
#define MDM_AGCCNTL_ALT__TWOMEG_ENABLE_IQCORR__WIDTH                          1
#define MDM_AGCCNTL_ALT__TWOMEG_ENABLE_IQCORR__MASK                 0x40000000U
#define MDM_AGCCNTL_ALT__TWOMEG_ENABLE_IQCORR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x40000000U) >> 30)
#define MDM_AGCCNTL_ALT__TWOMEG_ENABLE_IQCORR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 30) & 0x40000000U)
#define MDM_AGCCNTL_ALT__TWOMEG_ENABLE_IQCORR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | (((uint32_t)(src) <<\
                    30) & 0x40000000U)
#define MDM_AGCCNTL_ALT__TWOMEG_ENABLE_IQCORR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 30) & ~0x40000000U)))
#define MDM_AGCCNTL_ALT__TWOMEG_ENABLE_IQCORR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(1) << 30)
#define MDM_AGCCNTL_ALT__TWOMEG_ENABLE_IQCORR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(0) << 30)
#define MDM_AGCCNTL_ALT__TWOMEG_ENABLE_IQCORR__RESET_VALUE          0x00000000U
/** @} */
#define MDM_AGCCNTL_ALT__TYPE                                          uint32_t
#define MDM_AGCCNTL_ALT__READ                                       0x7fffffffU
#define MDM_AGCCNTL_ALT__WRITE                                      0x7fffffffU
#define MDM_AGCCNTL_ALT__PRESERVED                                  0x00000000U
#define MDM_AGCCNTL_ALT__RESET_VALUE                                0x0c661533U

#endif /* __MDM_AGCCNTL_ALT_MACRO__ */

/** @} end of agccntl_alt */

/* macros for BlueprintGlobalNameSpace::MDM_agcpd */
/**
 * @defgroup mdm_regs_core_agcpd agcpd
 * @brief agc peak detect control definitions.
 * @{
 */
#ifndef __MDM_AGCPD_MACRO__
#define __MDM_AGCPD_MACRO__

/* macros for field check_win */
/**
 * @defgroup mdm_regs_core_check_win_field check_win_field
 * @brief macros for field check_win
 * @details Number of samples to measure for peak detection
 * @{
 */
#define MDM_AGCPD__CHECK_WIN__SHIFT                                           0
#define MDM_AGCPD__CHECK_WIN__WIDTH                                           4
#define MDM_AGCPD__CHECK_WIN__MASK                                  0x0000000fU
#define MDM_AGCPD__CHECK_WIN__READ(src)         ((uint32_t)(src) & 0x0000000fU)
#define MDM_AGCPD__CHECK_WIN__WRITE(src)        ((uint32_t)(src) & 0x0000000fU)
#define MDM_AGCPD__CHECK_WIN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000000fU) | ((uint32_t)(src) &\
                    0x0000000fU)
#define MDM_AGCPD__CHECK_WIN__VERIFY(src) (!(((uint32_t)(src) & ~0x0000000fU)))
#define MDM_AGCPD__CHECK_WIN__RESET_VALUE                           0x00000008U
/** @} */

/* macros for field rfin_peak_thr_high */
/**
 * @defgroup mdm_regs_core_rfin_peak_thr_high_field rfin_peak_thr_high_field
 * @brief macros for field rfin_peak_thr_high
 * @details Threshold for LNA peak detector when peak not currently detected
 * @{
 */
#define MDM_AGCPD__RFIN_PEAK_THR_HIGH__SHIFT                                  4
#define MDM_AGCPD__RFIN_PEAK_THR_HIGH__WIDTH                                  4
#define MDM_AGCPD__RFIN_PEAK_THR_HIGH__MASK                         0x000000f0U
#define MDM_AGCPD__RFIN_PEAK_THR_HIGH__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000000f0U) >> 4)
#define MDM_AGCPD__RFIN_PEAK_THR_HIGH__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x000000f0U)
#define MDM_AGCPD__RFIN_PEAK_THR_HIGH__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000f0U) | (((uint32_t)(src) <<\
                    4) & 0x000000f0U)
#define MDM_AGCPD__RFIN_PEAK_THR_HIGH__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x000000f0U)))
#define MDM_AGCPD__RFIN_PEAK_THR_HIGH__RESET_VALUE                  0x00000006U
/** @} */

/* macros for field rfin_peak_thr_low */
/**
 * @defgroup mdm_regs_core_rfin_peak_thr_low_field rfin_peak_thr_low_field
 * @brief macros for field rfin_peak_thr_low
 * @details Threshold for LNA peak detector when peak currently detected
 * @{
 */
#define MDM_AGCPD__RFIN_PEAK_THR_LOW__SHIFT                                   8
#define MDM_AGCPD__RFIN_PEAK_THR_LOW__WIDTH                                   4
#define MDM_AGCPD__RFIN_PEAK_THR_LOW__MASK                          0x00000f00U
#define MDM_AGCPD__RFIN_PEAK_THR_LOW__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000f00U) >> 8)
#define MDM_AGCPD__RFIN_PEAK_THR_LOW__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00000f00U)
#define MDM_AGCPD__RFIN_PEAK_THR_LOW__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000f00U) | (((uint32_t)(src) <<\
                    8) & 0x00000f00U)
#define MDM_AGCPD__RFIN_PEAK_THR_LOW__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00000f00U)))
#define MDM_AGCPD__RFIN_PEAK_THR_LOW__RESET_VALUE                   0x00000002U
/** @} */

/* macros for field tia_peak_thr_high */
/**
 * @defgroup mdm_regs_core_tia_peak_thr_high_field tia_peak_thr_high_field
 * @brief macros for field tia_peak_thr_high
 * @details Threshold for TIA peak detector when peak not currently detected
 * @{
 */
#define MDM_AGCPD__TIA_PEAK_THR_HIGH__SHIFT                                  12
#define MDM_AGCPD__TIA_PEAK_THR_HIGH__WIDTH                                   4
#define MDM_AGCPD__TIA_PEAK_THR_HIGH__MASK                          0x0000f000U
#define MDM_AGCPD__TIA_PEAK_THR_HIGH__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000f000U) >> 12)
#define MDM_AGCPD__TIA_PEAK_THR_HIGH__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x0000f000U)
#define MDM_AGCPD__TIA_PEAK_THR_HIGH__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000f000U) | (((uint32_t)(src) <<\
                    12) & 0x0000f000U)
#define MDM_AGCPD__TIA_PEAK_THR_HIGH__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x0000f000U)))
#define MDM_AGCPD__TIA_PEAK_THR_HIGH__RESET_VALUE                   0x00000002U
/** @} */

/* macros for field tia_peak_thr_low */
/**
 * @defgroup mdm_regs_core_tia_peak_thr_low_field tia_peak_thr_low_field
 * @brief macros for field tia_peak_thr_low
 * @details Threshold for TIA peak detector when peak currently detected
 * @{
 */
#define MDM_AGCPD__TIA_PEAK_THR_LOW__SHIFT                                   16
#define MDM_AGCPD__TIA_PEAK_THR_LOW__WIDTH                                    4
#define MDM_AGCPD__TIA_PEAK_THR_LOW__MASK                           0x000f0000U
#define MDM_AGCPD__TIA_PEAK_THR_LOW__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000f0000U) >> 16)
#define MDM_AGCPD__TIA_PEAK_THR_LOW__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x000f0000U)
#define MDM_AGCPD__TIA_PEAK_THR_LOW__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000f0000U) | (((uint32_t)(src) <<\
                    16) & 0x000f0000U)
#define MDM_AGCPD__TIA_PEAK_THR_LOW__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x000f0000U)))
#define MDM_AGCPD__TIA_PEAK_THR_LOW__RESET_VALUE                    0x00000002U
/** @} */
#define MDM_AGCPD__TYPE                                                uint32_t
#define MDM_AGCPD__READ                                             0x000fffffU
#define MDM_AGCPD__WRITE                                            0x000fffffU
#define MDM_AGCPD__PRESERVED                                        0x00000000U
#define MDM_AGCPD__RESET_VALUE                                      0x00022268U

#endif /* __MDM_AGCPD_MACRO__ */

/** @} end of agcpd */

/* macros for BlueprintGlobalNameSpace::MDM_agcpd_alt */
/**
 * @defgroup mdm_regs_core_agcpd_alt agcpd_alt
 * @brief agc peak detect control, alternate set definitions.
 * @{
 */
#ifndef __MDM_AGCPD_ALT_MACRO__
#define __MDM_AGCPD_ALT_MACRO__

/* macros for field check_win */
/**
 * @defgroup mdm_regs_core_check_win_field check_win_field
 * @brief macros for field check_win
 * @details Number of samples to measure for peak detection
 * @{
 */
#define MDM_AGCPD_ALT__CHECK_WIN__SHIFT                                       0
#define MDM_AGCPD_ALT__CHECK_WIN__WIDTH                                       4
#define MDM_AGCPD_ALT__CHECK_WIN__MASK                              0x0000000fU
#define MDM_AGCPD_ALT__CHECK_WIN__READ(src)     ((uint32_t)(src) & 0x0000000fU)
#define MDM_AGCPD_ALT__CHECK_WIN__WRITE(src)    ((uint32_t)(src) & 0x0000000fU)
#define MDM_AGCPD_ALT__CHECK_WIN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000000fU) | ((uint32_t)(src) &\
                    0x0000000fU)
#define MDM_AGCPD_ALT__CHECK_WIN__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000000fU)))
#define MDM_AGCPD_ALT__CHECK_WIN__RESET_VALUE                       0x00000008U
/** @} */

/* macros for field rfin_peak_thr_high */
/**
 * @defgroup mdm_regs_core_rfin_peak_thr_high_field rfin_peak_thr_high_field
 * @brief macros for field rfin_peak_thr_high
 * @details Threshold for LNA peak detector when peak not currently detected
 * @{
 */
#define MDM_AGCPD_ALT__RFIN_PEAK_THR_HIGH__SHIFT                              4
#define MDM_AGCPD_ALT__RFIN_PEAK_THR_HIGH__WIDTH                              4
#define MDM_AGCPD_ALT__RFIN_PEAK_THR_HIGH__MASK                     0x000000f0U
#define MDM_AGCPD_ALT__RFIN_PEAK_THR_HIGH__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000000f0U) >> 4)
#define MDM_AGCPD_ALT__RFIN_PEAK_THR_HIGH__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x000000f0U)
#define MDM_AGCPD_ALT__RFIN_PEAK_THR_HIGH__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000f0U) | (((uint32_t)(src) <<\
                    4) & 0x000000f0U)
#define MDM_AGCPD_ALT__RFIN_PEAK_THR_HIGH__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x000000f0U)))
#define MDM_AGCPD_ALT__RFIN_PEAK_THR_HIGH__RESET_VALUE              0x00000006U
/** @} */

/* macros for field rfin_peak_thr_low */
/**
 * @defgroup mdm_regs_core_rfin_peak_thr_low_field rfin_peak_thr_low_field
 * @brief macros for field rfin_peak_thr_low
 * @details Threshold for LNA peak detector when peak currently detected
 * @{
 */
#define MDM_AGCPD_ALT__RFIN_PEAK_THR_LOW__SHIFT                               8
#define MDM_AGCPD_ALT__RFIN_PEAK_THR_LOW__WIDTH                               4
#define MDM_AGCPD_ALT__RFIN_PEAK_THR_LOW__MASK                      0x00000f00U
#define MDM_AGCPD_ALT__RFIN_PEAK_THR_LOW__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000f00U) >> 8)
#define MDM_AGCPD_ALT__RFIN_PEAK_THR_LOW__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00000f00U)
#define MDM_AGCPD_ALT__RFIN_PEAK_THR_LOW__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000f00U) | (((uint32_t)(src) <<\
                    8) & 0x00000f00U)
#define MDM_AGCPD_ALT__RFIN_PEAK_THR_LOW__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00000f00U)))
#define MDM_AGCPD_ALT__RFIN_PEAK_THR_LOW__RESET_VALUE               0x00000002U
/** @} */

/* macros for field tia_peak_thr_high */
/**
 * @defgroup mdm_regs_core_tia_peak_thr_high_field tia_peak_thr_high_field
 * @brief macros for field tia_peak_thr_high
 * @details Threshold for TIA peak detector when peak not currently detected
 * @{
 */
#define MDM_AGCPD_ALT__TIA_PEAK_THR_HIGH__SHIFT                              12
#define MDM_AGCPD_ALT__TIA_PEAK_THR_HIGH__WIDTH                               4
#define MDM_AGCPD_ALT__TIA_PEAK_THR_HIGH__MASK                      0x0000f000U
#define MDM_AGCPD_ALT__TIA_PEAK_THR_HIGH__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000f000U) >> 12)
#define MDM_AGCPD_ALT__TIA_PEAK_THR_HIGH__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x0000f000U)
#define MDM_AGCPD_ALT__TIA_PEAK_THR_HIGH__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000f000U) | (((uint32_t)(src) <<\
                    12) & 0x0000f000U)
#define MDM_AGCPD_ALT__TIA_PEAK_THR_HIGH__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x0000f000U)))
#define MDM_AGCPD_ALT__TIA_PEAK_THR_HIGH__RESET_VALUE               0x00000002U
/** @} */

/* macros for field tia_peak_thr_low */
/**
 * @defgroup mdm_regs_core_tia_peak_thr_low_field tia_peak_thr_low_field
 * @brief macros for field tia_peak_thr_low
 * @details Threshold for TIA peak detector when peak currently detected
 * @{
 */
#define MDM_AGCPD_ALT__TIA_PEAK_THR_LOW__SHIFT                               16
#define MDM_AGCPD_ALT__TIA_PEAK_THR_LOW__WIDTH                                4
#define MDM_AGCPD_ALT__TIA_PEAK_THR_LOW__MASK                       0x000f0000U
#define MDM_AGCPD_ALT__TIA_PEAK_THR_LOW__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000f0000U) >> 16)
#define MDM_AGCPD_ALT__TIA_PEAK_THR_LOW__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x000f0000U)
#define MDM_AGCPD_ALT__TIA_PEAK_THR_LOW__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000f0000U) | (((uint32_t)(src) <<\
                    16) & 0x000f0000U)
#define MDM_AGCPD_ALT__TIA_PEAK_THR_LOW__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x000f0000U)))
#define MDM_AGCPD_ALT__TIA_PEAK_THR_LOW__RESET_VALUE                0x00000002U
/** @} */
#define MDM_AGCPD_ALT__TYPE                                            uint32_t
#define MDM_AGCPD_ALT__READ                                         0x000fffffU
#define MDM_AGCPD_ALT__WRITE                                        0x000fffffU
#define MDM_AGCPD_ALT__PRESERVED                                    0x00000000U
#define MDM_AGCPD_ALT__RESET_VALUE                                  0x00022268U

#endif /* __MDM_AGCPD_ALT_MACRO__ */

/** @} end of agcpd_alt */

/* macros for BlueprintGlobalNameSpace::MDM_agcdet */
/**
 * @defgroup mdm_regs_core_agcdet agcdet
 * @brief 16 MHz clock delays added to saturation and TIA peak detect relative to RFIN peak detect definitions.
 * @{
 */
#ifndef __MDM_AGCDET_MACRO__
#define __MDM_AGCDET_MACRO__

/* macros for field sat_delay */
/**
 * @defgroup mdm_regs_core_sat_delay_field sat_delay_field
 * @brief macros for field sat_delay
 * @details Delay for saturation, 1M
 * @{
 */
#define MDM_AGCDET__SAT_DELAY__SHIFT                                          0
#define MDM_AGCDET__SAT_DELAY__WIDTH                                          5
#define MDM_AGCDET__SAT_DELAY__MASK                                 0x0000001fU
#define MDM_AGCDET__SAT_DELAY__READ(src)        ((uint32_t)(src) & 0x0000001fU)
#define MDM_AGCDET__SAT_DELAY__WRITE(src)       ((uint32_t)(src) & 0x0000001fU)
#define MDM_AGCDET__SAT_DELAY__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000001fU) | ((uint32_t)(src) &\
                    0x0000001fU)
#define MDM_AGCDET__SAT_DELAY__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000001fU)))
#define MDM_AGCDET__SAT_DELAY__RESET_VALUE                          0x00000000U
/** @} */

/* macros for field twomeg_sat_delay */
/**
 * @defgroup mdm_regs_core_twomeg_sat_delay_field twomeg_sat_delay_field
 * @brief macros for field twomeg_sat_delay
 * @details Delay for saturation, 2M
 * @{
 */
#define MDM_AGCDET__TWOMEG_SAT_DELAY__SHIFT                                   5
#define MDM_AGCDET__TWOMEG_SAT_DELAY__WIDTH                                   5
#define MDM_AGCDET__TWOMEG_SAT_DELAY__MASK                          0x000003e0U
#define MDM_AGCDET__TWOMEG_SAT_DELAY__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000003e0U) >> 5)
#define MDM_AGCDET__TWOMEG_SAT_DELAY__WRITE(src) \
                    (((uint32_t)(src)\
                    << 5) & 0x000003e0U)
#define MDM_AGCDET__TWOMEG_SAT_DELAY__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000003e0U) | (((uint32_t)(src) <<\
                    5) & 0x000003e0U)
#define MDM_AGCDET__TWOMEG_SAT_DELAY__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 5) & ~0x000003e0U)))
#define MDM_AGCDET__TWOMEG_SAT_DELAY__RESET_VALUE                   0x00000000U
/** @} */

/* macros for field tiapd_delay */
/**
 * @defgroup mdm_regs_core_tiapd_delay_field tiapd_delay_field
 * @brief macros for field tiapd_delay
 * @details Delay for saturation, 1M
 * @{
 */
#define MDM_AGCDET__TIAPD_DELAY__SHIFT                                       10
#define MDM_AGCDET__TIAPD_DELAY__WIDTH                                        5
#define MDM_AGCDET__TIAPD_DELAY__MASK                               0x00007c00U
#define MDM_AGCDET__TIAPD_DELAY__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00007c00U) >> 10)
#define MDM_AGCDET__TIAPD_DELAY__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x00007c00U)
#define MDM_AGCDET__TIAPD_DELAY__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00007c00U) | (((uint32_t)(src) <<\
                    10) & 0x00007c00U)
#define MDM_AGCDET__TIAPD_DELAY__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x00007c00U)))
#define MDM_AGCDET__TIAPD_DELAY__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field twomeg_tiapd_delay */
/**
 * @defgroup mdm_regs_core_twomeg_tiapd_delay_field twomeg_tiapd_delay_field
 * @brief macros for field twomeg_tiapd_delay
 * @details Delay for saturation, 2M
 * @{
 */
#define MDM_AGCDET__TWOMEG_TIAPD_DELAY__SHIFT                                15
#define MDM_AGCDET__TWOMEG_TIAPD_DELAY__WIDTH                                 5
#define MDM_AGCDET__TWOMEG_TIAPD_DELAY__MASK                        0x000f8000U
#define MDM_AGCDET__TWOMEG_TIAPD_DELAY__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000f8000U) >> 15)
#define MDM_AGCDET__TWOMEG_TIAPD_DELAY__WRITE(src) \
                    (((uint32_t)(src)\
                    << 15) & 0x000f8000U)
#define MDM_AGCDET__TWOMEG_TIAPD_DELAY__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000f8000U) | (((uint32_t)(src) <<\
                    15) & 0x000f8000U)
#define MDM_AGCDET__TWOMEG_TIAPD_DELAY__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 15) & ~0x000f8000U)))
#define MDM_AGCDET__TWOMEG_TIAPD_DELAY__RESET_VALUE                 0x00000000U
/** @} */
#define MDM_AGCDET__TYPE                                               uint32_t
#define MDM_AGCDET__READ                                            0x000fffffU
#define MDM_AGCDET__WRITE                                           0x000fffffU
#define MDM_AGCDET__PRESERVED                                       0x00000000U
#define MDM_AGCDET__RESET_VALUE                                     0x00000000U

#endif /* __MDM_AGCDET_MACRO__ */

/** @} end of agcdet */

/* macros for BlueprintGlobalNameSpace::MDM_agcdet_alt */
/**
 * @defgroup mdm_regs_core_agcdet_alt agcdet_alt
 * @brief 16 MHz clock delays added to saturation and TIA peak detect relative to RFIN peak detect, alternate set definitions.
 * @{
 */
#ifndef __MDM_AGCDET_ALT_MACRO__
#define __MDM_AGCDET_ALT_MACRO__

/* macros for field sat_delay */
/**
 * @defgroup mdm_regs_core_sat_delay_field sat_delay_field
 * @brief macros for field sat_delay
 * @details Delay for saturation, 1M
 * @{
 */
#define MDM_AGCDET_ALT__SAT_DELAY__SHIFT                                      0
#define MDM_AGCDET_ALT__SAT_DELAY__WIDTH                                      5
#define MDM_AGCDET_ALT__SAT_DELAY__MASK                             0x0000001fU
#define MDM_AGCDET_ALT__SAT_DELAY__READ(src)    ((uint32_t)(src) & 0x0000001fU)
#define MDM_AGCDET_ALT__SAT_DELAY__WRITE(src)   ((uint32_t)(src) & 0x0000001fU)
#define MDM_AGCDET_ALT__SAT_DELAY__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000001fU) | ((uint32_t)(src) &\
                    0x0000001fU)
#define MDM_AGCDET_ALT__SAT_DELAY__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000001fU)))
#define MDM_AGCDET_ALT__SAT_DELAY__RESET_VALUE                      0x00000000U
/** @} */

/* macros for field twomeg_sat_delay */
/**
 * @defgroup mdm_regs_core_twomeg_sat_delay_field twomeg_sat_delay_field
 * @brief macros for field twomeg_sat_delay
 * @details Delay for saturation, 2M
 * @{
 */
#define MDM_AGCDET_ALT__TWOMEG_SAT_DELAY__SHIFT                               5
#define MDM_AGCDET_ALT__TWOMEG_SAT_DELAY__WIDTH                               5
#define MDM_AGCDET_ALT__TWOMEG_SAT_DELAY__MASK                      0x000003e0U
#define MDM_AGCDET_ALT__TWOMEG_SAT_DELAY__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000003e0U) >> 5)
#define MDM_AGCDET_ALT__TWOMEG_SAT_DELAY__WRITE(src) \
                    (((uint32_t)(src)\
                    << 5) & 0x000003e0U)
#define MDM_AGCDET_ALT__TWOMEG_SAT_DELAY__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000003e0U) | (((uint32_t)(src) <<\
                    5) & 0x000003e0U)
#define MDM_AGCDET_ALT__TWOMEG_SAT_DELAY__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 5) & ~0x000003e0U)))
#define MDM_AGCDET_ALT__TWOMEG_SAT_DELAY__RESET_VALUE               0x00000000U
/** @} */

/* macros for field tiapd_delay */
/**
 * @defgroup mdm_regs_core_tiapd_delay_field tiapd_delay_field
 * @brief macros for field tiapd_delay
 * @details Delay for saturation, 1M
 * @{
 */
#define MDM_AGCDET_ALT__TIAPD_DELAY__SHIFT                                   10
#define MDM_AGCDET_ALT__TIAPD_DELAY__WIDTH                                    5
#define MDM_AGCDET_ALT__TIAPD_DELAY__MASK                           0x00007c00U
#define MDM_AGCDET_ALT__TIAPD_DELAY__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00007c00U) >> 10)
#define MDM_AGCDET_ALT__TIAPD_DELAY__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x00007c00U)
#define MDM_AGCDET_ALT__TIAPD_DELAY__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00007c00U) | (((uint32_t)(src) <<\
                    10) & 0x00007c00U)
#define MDM_AGCDET_ALT__TIAPD_DELAY__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x00007c00U)))
#define MDM_AGCDET_ALT__TIAPD_DELAY__RESET_VALUE                    0x00000000U
/** @} */

/* macros for field twomeg_tiapd_delay */
/**
 * @defgroup mdm_regs_core_twomeg_tiapd_delay_field twomeg_tiapd_delay_field
 * @brief macros for field twomeg_tiapd_delay
 * @details Delay for saturation, 2M
 * @{
 */
#define MDM_AGCDET_ALT__TWOMEG_TIAPD_DELAY__SHIFT                            15
#define MDM_AGCDET_ALT__TWOMEG_TIAPD_DELAY__WIDTH                             5
#define MDM_AGCDET_ALT__TWOMEG_TIAPD_DELAY__MASK                    0x000f8000U
#define MDM_AGCDET_ALT__TWOMEG_TIAPD_DELAY__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000f8000U) >> 15)
#define MDM_AGCDET_ALT__TWOMEG_TIAPD_DELAY__WRITE(src) \
                    (((uint32_t)(src)\
                    << 15) & 0x000f8000U)
#define MDM_AGCDET_ALT__TWOMEG_TIAPD_DELAY__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000f8000U) | (((uint32_t)(src) <<\
                    15) & 0x000f8000U)
#define MDM_AGCDET_ALT__TWOMEG_TIAPD_DELAY__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 15) & ~0x000f8000U)))
#define MDM_AGCDET_ALT__TWOMEG_TIAPD_DELAY__RESET_VALUE             0x00000000U
/** @} */
#define MDM_AGCDET_ALT__TYPE                                           uint32_t
#define MDM_AGCDET_ALT__READ                                        0x000fffffU
#define MDM_AGCDET_ALT__WRITE                                       0x000fffffU
#define MDM_AGCDET_ALT__PRESERVED                                   0x00000000U
#define MDM_AGCDET_ALT__RESET_VALUE                                 0x00000000U

#endif /* __MDM_AGCDET_ALT_MACRO__ */

/** @} end of agcdet_alt */

/* macros for BlueprintGlobalNameSpace::MDM_agcoffset */
/**
 * @defgroup mdm_regs_core_agcoffset agcoffset
 * @brief Paris: agcoffset_adc_quick_drop = Saturation offset of TIA with respect to ADC, in dB: New rxgain = Old rxgain - pgagain - agcoffset_adc_quick_drop Sydney ASIC with Paris FPGA (dtop_bypass): agcoffset_sydney__adc_quick_drop = Saturation offset of LNA with respect to ADC: New rxgain = Old LNA gain + 18 - agcoffset_sydney_adc_quick_drop The intent is to reduce rxgain to barely get us out of ADC saturation after the drop. Add a couple dB of margin to the values programmed below. definitions.
 * @{
 */
#ifndef __MDM_AGCOFFSET_MACRO__
#define __MDM_AGCOFFSET_MACRO__

/* macros for field adc_quick_drop */
/**
 * @defgroup mdm_regs_core_adc_quick_drop_field adc_quick_drop_field
 * @brief macros for field adc_quick_drop
 * @details Signed. 1M
 * @{
 */
#define MDM_AGCOFFSET__ADC_QUICK_DROP__SHIFT                                  0
#define MDM_AGCOFFSET__ADC_QUICK_DROP__WIDTH                                  6
#define MDM_AGCOFFSET__ADC_QUICK_DROP__MASK                         0x0000003fU
#define MDM_AGCOFFSET__ADC_QUICK_DROP__READ(src) \
                    ((uint32_t)(src)\
                    & 0x0000003fU)
#define MDM_AGCOFFSET__ADC_QUICK_DROP__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000003fU)
#define MDM_AGCOFFSET__ADC_QUICK_DROP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000003fU) | ((uint32_t)(src) &\
                    0x0000003fU)
#define MDM_AGCOFFSET__ADC_QUICK_DROP__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000003fU)))
#define MDM_AGCOFFSET__ADC_QUICK_DROP__RESET_VALUE                  0x00000002U
/** @} */

/* macros for field twomeg_adc_quick_drop */
/**
 * @defgroup mdm_regs_core_twomeg_adc_quick_drop_field twomeg_adc_quick_drop_field
 * @brief macros for field twomeg_adc_quick_drop
 * @details Signed. 2M
 * @{
 */
#define MDM_AGCOFFSET__TWOMEG_ADC_QUICK_DROP__SHIFT                           6
#define MDM_AGCOFFSET__TWOMEG_ADC_QUICK_DROP__WIDTH                           6
#define MDM_AGCOFFSET__TWOMEG_ADC_QUICK_DROP__MASK                  0x00000fc0U
#define MDM_AGCOFFSET__TWOMEG_ADC_QUICK_DROP__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000fc0U) >> 6)
#define MDM_AGCOFFSET__TWOMEG_ADC_QUICK_DROP__WRITE(src) \
                    (((uint32_t)(src)\
                    << 6) & 0x00000fc0U)
#define MDM_AGCOFFSET__TWOMEG_ADC_QUICK_DROP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000fc0U) | (((uint32_t)(src) <<\
                    6) & 0x00000fc0U)
#define MDM_AGCOFFSET__TWOMEG_ADC_QUICK_DROP__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 6) & ~0x00000fc0U)))
#define MDM_AGCOFFSET__TWOMEG_ADC_QUICK_DROP__RESET_VALUE           0x00000002U
/** @} */

/* macros for field sydney_adc_quick_drop */
/**
 * @defgroup mdm_regs_core_sydney_adc_quick_drop_field sydney_adc_quick_drop_field
 * @brief macros for field sydney_adc_quick_drop
 * @details Signed. 1M. 0x3f = -1
 * @{
 */
#define MDM_AGCOFFSET__SYDNEY_ADC_QUICK_DROP__SHIFT                          12
#define MDM_AGCOFFSET__SYDNEY_ADC_QUICK_DROP__WIDTH                           6
#define MDM_AGCOFFSET__SYDNEY_ADC_QUICK_DROP__MASK                  0x0003f000U
#define MDM_AGCOFFSET__SYDNEY_ADC_QUICK_DROP__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0003f000U) >> 12)
#define MDM_AGCOFFSET__SYDNEY_ADC_QUICK_DROP__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x0003f000U)
#define MDM_AGCOFFSET__SYDNEY_ADC_QUICK_DROP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0003f000U) | (((uint32_t)(src) <<\
                    12) & 0x0003f000U)
#define MDM_AGCOFFSET__SYDNEY_ADC_QUICK_DROP__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x0003f000U)))
#define MDM_AGCOFFSET__SYDNEY_ADC_QUICK_DROP__RESET_VALUE           0x0000003fU
/** @} */

/* macros for field sydney_twomeg_adc_quick_drop */
/**
 * @defgroup mdm_regs_core_sydney_twomeg_adc_quick_drop_field sydney_twomeg_adc_quick_drop_field
 * @brief macros for field sydney_twomeg_adc_quick_drop
 * @details Signed. 2M. 0x3f = -1
 * @{
 */
#define MDM_AGCOFFSET__SYDNEY_TWOMEG_ADC_QUICK_DROP__SHIFT                   18
#define MDM_AGCOFFSET__SYDNEY_TWOMEG_ADC_QUICK_DROP__WIDTH                    6
#define MDM_AGCOFFSET__SYDNEY_TWOMEG_ADC_QUICK_DROP__MASK           0x00fc0000U
#define MDM_AGCOFFSET__SYDNEY_TWOMEG_ADC_QUICK_DROP__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00fc0000U) >> 18)
#define MDM_AGCOFFSET__SYDNEY_TWOMEG_ADC_QUICK_DROP__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0x00fc0000U)
#define MDM_AGCOFFSET__SYDNEY_TWOMEG_ADC_QUICK_DROP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00fc0000U) | (((uint32_t)(src) <<\
                    18) & 0x00fc0000U)
#define MDM_AGCOFFSET__SYDNEY_TWOMEG_ADC_QUICK_DROP__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x00fc0000U)))
#define MDM_AGCOFFSET__SYDNEY_TWOMEG_ADC_QUICK_DROP__RESET_VALUE    0x0000003fU
/** @} */
#define MDM_AGCOFFSET__TYPE                                            uint32_t
#define MDM_AGCOFFSET__READ                                         0x00ffffffU
#define MDM_AGCOFFSET__WRITE                                        0x00ffffffU
#define MDM_AGCOFFSET__PRESERVED                                    0x00000000U
#define MDM_AGCOFFSET__RESET_VALUE                                  0x00fff082U

#endif /* __MDM_AGCOFFSET_MACRO__ */

/** @} end of agcoffset */

/* macros for BlueprintGlobalNameSpace::MDM_agcoffset_alt */
/**
 * @defgroup mdm_regs_core_agcoffset_alt agcoffset_alt
 * @brief Paris: agcoffset_adc_quick_drop = Saturation offset of TIA with respect to ADC, in dB: New rxgain = Old rxgain - pgagain - agcoffset_adc_quick_drop Sydney ASIC with Paris FPGA (dtop_bypass): agcoffset_sydney__adc_quick_drop = Saturation offset of LNA with respect to ADC: New rxgain = Old LNA gain + 18 - agcoffset_sydney_adc_quick_drop The intent is to reduce rxgain to barely get us out of ADC saturation after the drop. Add a couple dB of margin to the values programmed below. definitions.
 * @{
 */
#ifndef __MDM_AGCOFFSET_ALT_MACRO__
#define __MDM_AGCOFFSET_ALT_MACRO__

/* macros for field adc_quick_drop */
/**
 * @defgroup mdm_regs_core_adc_quick_drop_field adc_quick_drop_field
 * @brief macros for field adc_quick_drop
 * @details Signed. 1M
 * @{
 */
#define MDM_AGCOFFSET_ALT__ADC_QUICK_DROP__SHIFT                              0
#define MDM_AGCOFFSET_ALT__ADC_QUICK_DROP__WIDTH                              6
#define MDM_AGCOFFSET_ALT__ADC_QUICK_DROP__MASK                     0x0000003fU
#define MDM_AGCOFFSET_ALT__ADC_QUICK_DROP__READ(src) \
                    ((uint32_t)(src)\
                    & 0x0000003fU)
#define MDM_AGCOFFSET_ALT__ADC_QUICK_DROP__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000003fU)
#define MDM_AGCOFFSET_ALT__ADC_QUICK_DROP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000003fU) | ((uint32_t)(src) &\
                    0x0000003fU)
#define MDM_AGCOFFSET_ALT__ADC_QUICK_DROP__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000003fU)))
#define MDM_AGCOFFSET_ALT__ADC_QUICK_DROP__RESET_VALUE              0x00000002U
/** @} */

/* macros for field twomeg_adc_quick_drop */
/**
 * @defgroup mdm_regs_core_twomeg_adc_quick_drop_field twomeg_adc_quick_drop_field
 * @brief macros for field twomeg_adc_quick_drop
 * @details Signed. 2M
 * @{
 */
#define MDM_AGCOFFSET_ALT__TWOMEG_ADC_QUICK_DROP__SHIFT                       6
#define MDM_AGCOFFSET_ALT__TWOMEG_ADC_QUICK_DROP__WIDTH                       6
#define MDM_AGCOFFSET_ALT__TWOMEG_ADC_QUICK_DROP__MASK              0x00000fc0U
#define MDM_AGCOFFSET_ALT__TWOMEG_ADC_QUICK_DROP__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000fc0U) >> 6)
#define MDM_AGCOFFSET_ALT__TWOMEG_ADC_QUICK_DROP__WRITE(src) \
                    (((uint32_t)(src)\
                    << 6) & 0x00000fc0U)
#define MDM_AGCOFFSET_ALT__TWOMEG_ADC_QUICK_DROP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000fc0U) | (((uint32_t)(src) <<\
                    6) & 0x00000fc0U)
#define MDM_AGCOFFSET_ALT__TWOMEG_ADC_QUICK_DROP__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 6) & ~0x00000fc0U)))
#define MDM_AGCOFFSET_ALT__TWOMEG_ADC_QUICK_DROP__RESET_VALUE       0x00000002U
/** @} */

/* macros for field sydney_adc_quick_drop */
/**
 * @defgroup mdm_regs_core_sydney_adc_quick_drop_field sydney_adc_quick_drop_field
 * @brief macros for field sydney_adc_quick_drop
 * @details Signed. 1M. 0x3f = -1
 * @{
 */
#define MDM_AGCOFFSET_ALT__SYDNEY_ADC_QUICK_DROP__SHIFT                      12
#define MDM_AGCOFFSET_ALT__SYDNEY_ADC_QUICK_DROP__WIDTH                       6
#define MDM_AGCOFFSET_ALT__SYDNEY_ADC_QUICK_DROP__MASK              0x0003f000U
#define MDM_AGCOFFSET_ALT__SYDNEY_ADC_QUICK_DROP__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0003f000U) >> 12)
#define MDM_AGCOFFSET_ALT__SYDNEY_ADC_QUICK_DROP__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x0003f000U)
#define MDM_AGCOFFSET_ALT__SYDNEY_ADC_QUICK_DROP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0003f000U) | (((uint32_t)(src) <<\
                    12) & 0x0003f000U)
#define MDM_AGCOFFSET_ALT__SYDNEY_ADC_QUICK_DROP__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x0003f000U)))
#define MDM_AGCOFFSET_ALT__SYDNEY_ADC_QUICK_DROP__RESET_VALUE       0x0000003fU
/** @} */

/* macros for field sydney_twomeg_adc_quick_drop */
/**
 * @defgroup mdm_regs_core_sydney_twomeg_adc_quick_drop_field sydney_twomeg_adc_quick_drop_field
 * @brief macros for field sydney_twomeg_adc_quick_drop
 * @details Signed. 2M. 0x3f = -1
 * @{
 */
#define MDM_AGCOFFSET_ALT__SYDNEY_TWOMEG_ADC_QUICK_DROP__SHIFT               18
#define MDM_AGCOFFSET_ALT__SYDNEY_TWOMEG_ADC_QUICK_DROP__WIDTH                6
#define MDM_AGCOFFSET_ALT__SYDNEY_TWOMEG_ADC_QUICK_DROP__MASK       0x00fc0000U
#define MDM_AGCOFFSET_ALT__SYDNEY_TWOMEG_ADC_QUICK_DROP__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00fc0000U) >> 18)
#define MDM_AGCOFFSET_ALT__SYDNEY_TWOMEG_ADC_QUICK_DROP__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0x00fc0000U)
#define MDM_AGCOFFSET_ALT__SYDNEY_TWOMEG_ADC_QUICK_DROP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00fc0000U) | (((uint32_t)(src) <<\
                    18) & 0x00fc0000U)
#define MDM_AGCOFFSET_ALT__SYDNEY_TWOMEG_ADC_QUICK_DROP__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x00fc0000U)))
#define MDM_AGCOFFSET_ALT__SYDNEY_TWOMEG_ADC_QUICK_DROP__RESET_VALUE \
                    0x0000003fU
/** @} */
#define MDM_AGCOFFSET_ALT__TYPE                                        uint32_t
#define MDM_AGCOFFSET_ALT__READ                                     0x00ffffffU
#define MDM_AGCOFFSET_ALT__WRITE                                    0x00ffffffU
#define MDM_AGCOFFSET_ALT__PRESERVED                                0x00000000U
#define MDM_AGCOFFSET_ALT__RESET_VALUE                              0x00fff082U

#endif /* __MDM_AGCOFFSET_ALT_MACRO__ */

/** @} end of agcoffset_alt */

/* macros for BlueprintGlobalNameSpace::MDM_synch */
/**
 * @defgroup mdm_regs_core_synch synch
 * @brief Frequency and timing synchronization control definitions.
 * @{
 */
#ifndef __MDM_SYNCH_MACRO__
#define __MDM_SYNCH_MACRO__

/* macros for field pg */
/**
 * @defgroup mdm_regs_core_pg_field pg_field
 * @brief macros for field pg
 * @details Proportional gain for timing tracking Encoding: 0 -> 0. Else 2^(-pg)
 * @{
 */
#define MDM_SYNCH__PG__SHIFT                                                  2
#define MDM_SYNCH__PG__WIDTH                                                  2
#define MDM_SYNCH__PG__MASK                                         0x0000000cU
#define MDM_SYNCH__PG__READ(src)         (((uint32_t)(src) & 0x0000000cU) >> 2)
#define MDM_SYNCH__PG__WRITE(src)        (((uint32_t)(src) << 2) & 0x0000000cU)
#define MDM_SYNCH__PG__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000000cU) | (((uint32_t)(src) <<\
                    2) & 0x0000000cU)
#define MDM_SYNCH__PG__VERIFY(src) (!((((uint32_t)(src) << 2) & ~0x0000000cU)))
#define MDM_SYNCH__PG__RESET_VALUE                                  0x00000001U
/** @} */

/* macros for field ph_reg_thr */
/**
 * @defgroup mdm_regs_core_ph_reg_thr_field ph_reg_thr_field
 * @brief macros for field ph_reg_thr
 * @details Phase accumulator threshold for timing tracking Encoding: 2^(ph_reg_thr). Gear 1. Supported range: 0-5
 * @{
 */
#define MDM_SYNCH__PH_REG_THR__SHIFT                                          4
#define MDM_SYNCH__PH_REG_THR__WIDTH                                          3
#define MDM_SYNCH__PH_REG_THR__MASK                                 0x00000070U
#define MDM_SYNCH__PH_REG_THR__READ(src) (((uint32_t)(src) & 0x00000070U) >> 4)
#define MDM_SYNCH__PH_REG_THR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x00000070U)
#define MDM_SYNCH__PH_REG_THR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000070U) | (((uint32_t)(src) <<\
                    4) & 0x00000070U)
#define MDM_SYNCH__PH_REG_THR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x00000070U)))
#define MDM_SYNCH__PH_REG_THR__RESET_VALUE                          0x00000001U
/** @} */

/* macros for field ph_reg_thr2 */
/**
 * @defgroup mdm_regs_core_ph_reg_thr2_field ph_reg_thr2_field
 * @brief macros for field ph_reg_thr2
 * @details Phase accumulator threshold for timing tracking Encoding: 2^(ph_reg_thr). Gear 2. Supported range: 0-5
 * @{
 */
#define MDM_SYNCH__PH_REG_THR2__SHIFT                                         7
#define MDM_SYNCH__PH_REG_THR2__WIDTH                                         3
#define MDM_SYNCH__PH_REG_THR2__MASK                                0x00000380U
#define MDM_SYNCH__PH_REG_THR2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000380U) >> 7)
#define MDM_SYNCH__PH_REG_THR2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 7) & 0x00000380U)
#define MDM_SYNCH__PH_REG_THR2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000380U) | (((uint32_t)(src) <<\
                    7) & 0x00000380U)
#define MDM_SYNCH__PH_REG_THR2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 7) & ~0x00000380U)))
#define MDM_SYNCH__PH_REG_THR2__RESET_VALUE                         0x00000003U
/** @} */

/* macros for field ph_reg_thr3 */
/**
 * @defgroup mdm_regs_core_ph_reg_thr3_field ph_reg_thr3_field
 * @brief macros for field ph_reg_thr3
 * @details Phase accumulator threshold for timing tracking Encoding: 2^(ph_reg_thr). Gear 3. Supported range: 0-5
 * @{
 */
#define MDM_SYNCH__PH_REG_THR3__SHIFT                                        10
#define MDM_SYNCH__PH_REG_THR3__WIDTH                                         3
#define MDM_SYNCH__PH_REG_THR3__MASK                                0x00001c00U
#define MDM_SYNCH__PH_REG_THR3__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00001c00U) >> 10)
#define MDM_SYNCH__PH_REG_THR3__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x00001c00U)
#define MDM_SYNCH__PH_REG_THR3__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00001c00U) | (((uint32_t)(src) <<\
                    10) & 0x00001c00U)
#define MDM_SYNCH__PH_REG_THR3__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x00001c00U)))
#define MDM_SYNCH__PH_REG_THR3__RESET_VALUE                         0x00000004U
/** @} */

/* macros for field enable_time_track */
/**
 * @defgroup mdm_regs_core_enable_time_track_field enable_time_track_field
 * @brief macros for field enable_time_track
 * @details Enable time tracking, although can also be disabled with setting pg to 2'd0
 * @{
 */
#define MDM_SYNCH__ENABLE_TIME_TRACK__SHIFT                                  13
#define MDM_SYNCH__ENABLE_TIME_TRACK__WIDTH                                   1
#define MDM_SYNCH__ENABLE_TIME_TRACK__MASK                          0x00002000U
#define MDM_SYNCH__ENABLE_TIME_TRACK__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00002000U) >> 13)
#define MDM_SYNCH__ENABLE_TIME_TRACK__WRITE(src) \
                    (((uint32_t)(src)\
                    << 13) & 0x00002000U)
#define MDM_SYNCH__ENABLE_TIME_TRACK__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | (((uint32_t)(src) <<\
                    13) & 0x00002000U)
#define MDM_SYNCH__ENABLE_TIME_TRACK__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 13) & ~0x00002000U)))
#define MDM_SYNCH__ENABLE_TIME_TRACK__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | ((uint32_t)(1) << 13)
#define MDM_SYNCH__ENABLE_TIME_TRACK__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | ((uint32_t)(0) << 13)
#define MDM_SYNCH__ENABLE_TIME_TRACK__RESET_VALUE                   0x00000001U
/** @} */

/* macros for field freq_force_initial */
/**
 * @defgroup mdm_regs_core_freq_force_initial_field freq_force_initial_field
 * @brief macros for field freq_force_initial
 * @details Force initial frequency estimate
 * @{
 */
#define MDM_SYNCH__FREQ_FORCE_INITIAL__SHIFT                                 14
#define MDM_SYNCH__FREQ_FORCE_INITIAL__WIDTH                                  1
#define MDM_SYNCH__FREQ_FORCE_INITIAL__MASK                         0x00004000U
#define MDM_SYNCH__FREQ_FORCE_INITIAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00004000U) >> 14)
#define MDM_SYNCH__FREQ_FORCE_INITIAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 14) & 0x00004000U)
#define MDM_SYNCH__FREQ_FORCE_INITIAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | (((uint32_t)(src) <<\
                    14) & 0x00004000U)
#define MDM_SYNCH__FREQ_FORCE_INITIAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 14) & ~0x00004000U)))
#define MDM_SYNCH__FREQ_FORCE_INITIAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | ((uint32_t)(1) << 14)
#define MDM_SYNCH__FREQ_FORCE_INITIAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | ((uint32_t)(0) << 14)
#define MDM_SYNCH__FREQ_FORCE_INITIAL__RESET_VALUE                  0x00000000U
/** @} */

/* macros for field freq_forced_value */
/**
 * @defgroup mdm_regs_core_freq_forced_value_field freq_forced_value_field
 * @brief macros for field freq_forced_value
 * @details Forced initial frequency estimate value. Signed quantity. MSB has weight of -1 MHz. Subsequent bits have weight of 1/2 MHz, 1/4 MHz ... LSB has weight of 1/4096 MHz
 * @{
 */
#define MDM_SYNCH__FREQ_FORCED_VALUE__SHIFT                                  15
#define MDM_SYNCH__FREQ_FORCED_VALUE__WIDTH                                  13
#define MDM_SYNCH__FREQ_FORCED_VALUE__MASK                          0x0fff8000U
#define MDM_SYNCH__FREQ_FORCED_VALUE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0fff8000U) >> 15)
#define MDM_SYNCH__FREQ_FORCED_VALUE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 15) & 0x0fff8000U)
#define MDM_SYNCH__FREQ_FORCED_VALUE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0fff8000U) | (((uint32_t)(src) <<\
                    15) & 0x0fff8000U)
#define MDM_SYNCH__FREQ_FORCED_VALUE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 15) & ~0x0fff8000U)))
#define MDM_SYNCH__FREQ_FORCED_VALUE__RESET_VALUE                   0x00000000U
/** @} */

/* macros for field rst_freq_no_gain_change_pwrstep */
/**
 * @defgroup mdm_regs_core_rst_freq_no_gain_change_pwrstep_field rst_freq_no_gain_change_pwrstep_field
 * @brief macros for field rst_freq_no_gain_change_pwrstep
 * @details Allow (unlimited) assert_reset_freq_sync due to power step within a MEASURE state, with no gain change
 * @{
 */
#define MDM_SYNCH__RST_FREQ_NO_GAIN_CHANGE_PWRSTEP__SHIFT                    28
#define MDM_SYNCH__RST_FREQ_NO_GAIN_CHANGE_PWRSTEP__WIDTH                     1
#define MDM_SYNCH__RST_FREQ_NO_GAIN_CHANGE_PWRSTEP__MASK            0x10000000U
#define MDM_SYNCH__RST_FREQ_NO_GAIN_CHANGE_PWRSTEP__READ(src) \
                    (((uint32_t)(src)\
                    & 0x10000000U) >> 28)
#define MDM_SYNCH__RST_FREQ_NO_GAIN_CHANGE_PWRSTEP__WRITE(src) \
                    (((uint32_t)(src)\
                    << 28) & 0x10000000U)
#define MDM_SYNCH__RST_FREQ_NO_GAIN_CHANGE_PWRSTEP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x10000000U) | (((uint32_t)(src) <<\
                    28) & 0x10000000U)
#define MDM_SYNCH__RST_FREQ_NO_GAIN_CHANGE_PWRSTEP__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 28) & ~0x10000000U)))
#define MDM_SYNCH__RST_FREQ_NO_GAIN_CHANGE_PWRSTEP__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x10000000U) | ((uint32_t)(1) << 28)
#define MDM_SYNCH__RST_FREQ_NO_GAIN_CHANGE_PWRSTEP__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x10000000U) | ((uint32_t)(0) << 28)
#define MDM_SYNCH__RST_FREQ_NO_GAIN_CHANGE_PWRSTEP__RESET_VALUE     0x00000001U
/** @} */

/* macros for field rst_freq_no_gain_change_rfin */
/**
 * @defgroup mdm_regs_core_rst_freq_no_gain_change_rfin_field rst_freq_no_gain_change_rfin_field
 * @brief macros for field rst_freq_no_gain_change_rfin
 * @details Allow one assert_reset_freq_sync due to rfin peak within a MEASURE state, with no gain change
 * @{
 */
#define MDM_SYNCH__RST_FREQ_NO_GAIN_CHANGE_RFIN__SHIFT                       29
#define MDM_SYNCH__RST_FREQ_NO_GAIN_CHANGE_RFIN__WIDTH                        1
#define MDM_SYNCH__RST_FREQ_NO_GAIN_CHANGE_RFIN__MASK               0x20000000U
#define MDM_SYNCH__RST_FREQ_NO_GAIN_CHANGE_RFIN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x20000000U) >> 29)
#define MDM_SYNCH__RST_FREQ_NO_GAIN_CHANGE_RFIN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 29) & 0x20000000U)
#define MDM_SYNCH__RST_FREQ_NO_GAIN_CHANGE_RFIN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | (((uint32_t)(src) <<\
                    29) & 0x20000000U)
#define MDM_SYNCH__RST_FREQ_NO_GAIN_CHANGE_RFIN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 29) & ~0x20000000U)))
#define MDM_SYNCH__RST_FREQ_NO_GAIN_CHANGE_RFIN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | ((uint32_t)(1) << 29)
#define MDM_SYNCH__RST_FREQ_NO_GAIN_CHANGE_RFIN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | ((uint32_t)(0) << 29)
#define MDM_SYNCH__RST_FREQ_NO_GAIN_CHANGE_RFIN__RESET_VALUE        0x00000001U
/** @} */

/* macros for field rst_freq_no_gain_change_tia */
/**
 * @defgroup mdm_regs_core_rst_freq_no_gain_change_tia_field rst_freq_no_gain_change_tia_field
 * @brief macros for field rst_freq_no_gain_change_tia
 * @details Allow one assert_reset_freq_sync due to tia peak within a MEASURE state, with no gain change
 * @{
 */
#define MDM_SYNCH__RST_FREQ_NO_GAIN_CHANGE_TIA__SHIFT                        30
#define MDM_SYNCH__RST_FREQ_NO_GAIN_CHANGE_TIA__WIDTH                         1
#define MDM_SYNCH__RST_FREQ_NO_GAIN_CHANGE_TIA__MASK                0x40000000U
#define MDM_SYNCH__RST_FREQ_NO_GAIN_CHANGE_TIA__READ(src) \
                    (((uint32_t)(src)\
                    & 0x40000000U) >> 30)
#define MDM_SYNCH__RST_FREQ_NO_GAIN_CHANGE_TIA__WRITE(src) \
                    (((uint32_t)(src)\
                    << 30) & 0x40000000U)
#define MDM_SYNCH__RST_FREQ_NO_GAIN_CHANGE_TIA__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | (((uint32_t)(src) <<\
                    30) & 0x40000000U)
#define MDM_SYNCH__RST_FREQ_NO_GAIN_CHANGE_TIA__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 30) & ~0x40000000U)))
#define MDM_SYNCH__RST_FREQ_NO_GAIN_CHANGE_TIA__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(1) << 30)
#define MDM_SYNCH__RST_FREQ_NO_GAIN_CHANGE_TIA__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(0) << 30)
#define MDM_SYNCH__RST_FREQ_NO_GAIN_CHANGE_TIA__RESET_VALUE         0x00000001U
/** @} */

/* macros for field rst_freq_no_gain_change_sat */
/**
 * @defgroup mdm_regs_core_rst_freq_no_gain_change_sat_field rst_freq_no_gain_change_sat_field
 * @brief macros for field rst_freq_no_gain_change_sat
 * @details Allow one assert_reset_freq_sync due to adc sat within a MEASURE state, with no gain change
 * @{
 */
#define MDM_SYNCH__RST_FREQ_NO_GAIN_CHANGE_SAT__SHIFT                        31
#define MDM_SYNCH__RST_FREQ_NO_GAIN_CHANGE_SAT__WIDTH                         1
#define MDM_SYNCH__RST_FREQ_NO_GAIN_CHANGE_SAT__MASK                0x80000000U
#define MDM_SYNCH__RST_FREQ_NO_GAIN_CHANGE_SAT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x80000000U) >> 31)
#define MDM_SYNCH__RST_FREQ_NO_GAIN_CHANGE_SAT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 31) & 0x80000000U)
#define MDM_SYNCH__RST_FREQ_NO_GAIN_CHANGE_SAT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | (((uint32_t)(src) <<\
                    31) & 0x80000000U)
#define MDM_SYNCH__RST_FREQ_NO_GAIN_CHANGE_SAT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 31) & ~0x80000000U)))
#define MDM_SYNCH__RST_FREQ_NO_GAIN_CHANGE_SAT__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(1) << 31)
#define MDM_SYNCH__RST_FREQ_NO_GAIN_CHANGE_SAT__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(0) << 31)
#define MDM_SYNCH__RST_FREQ_NO_GAIN_CHANGE_SAT__RESET_VALUE         0x00000001U
/** @} */
#define MDM_SYNCH__TYPE                                                uint32_t
#define MDM_SYNCH__READ                                             0xfffffffcU
#define MDM_SYNCH__WRITE                                            0xfffffffcU
#define MDM_SYNCH__PRESERVED                                        0x00000000U
#define MDM_SYNCH__RESET_VALUE                                      0xf0003194U

#endif /* __MDM_SYNCH_MACRO__ */

/** @} end of synch */

/* macros for BlueprintGlobalNameSpace::MDM_synch_alt */
/**
 * @defgroup mdm_regs_core_synch_alt synch_alt
 * @brief Frequency and timing synchronization control, alternate set definitions.
 * @{
 */
#ifndef __MDM_SYNCH_ALT_MACRO__
#define __MDM_SYNCH_ALT_MACRO__

/* macros for field pg */
/**
 * @defgroup mdm_regs_core_pg_field pg_field
 * @brief macros for field pg
 * @details Proportional gain for timing tracking Encoding: 0 -> 0. Else 2^(-pg)
 * @{
 */
#define MDM_SYNCH_ALT__PG__SHIFT                                              2
#define MDM_SYNCH_ALT__PG__WIDTH                                              2
#define MDM_SYNCH_ALT__PG__MASK                                     0x0000000cU
#define MDM_SYNCH_ALT__PG__READ(src)     (((uint32_t)(src) & 0x0000000cU) >> 2)
#define MDM_SYNCH_ALT__PG__WRITE(src)    (((uint32_t)(src) << 2) & 0x0000000cU)
#define MDM_SYNCH_ALT__PG__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000000cU) | (((uint32_t)(src) <<\
                    2) & 0x0000000cU)
#define MDM_SYNCH_ALT__PG__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x0000000cU)))
#define MDM_SYNCH_ALT__PG__RESET_VALUE                              0x00000001U
/** @} */

/* macros for field ph_reg_thr */
/**
 * @defgroup mdm_regs_core_ph_reg_thr_field ph_reg_thr_field
 * @brief macros for field ph_reg_thr
 * @details Phase accumulator threshold for timing tracking Encoding: 2^(ph_reg_thr). Gear 1. Supported range: 0-5
 * @{
 */
#define MDM_SYNCH_ALT__PH_REG_THR__SHIFT                                      4
#define MDM_SYNCH_ALT__PH_REG_THR__WIDTH                                      3
#define MDM_SYNCH_ALT__PH_REG_THR__MASK                             0x00000070U
#define MDM_SYNCH_ALT__PH_REG_THR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000070U) >> 4)
#define MDM_SYNCH_ALT__PH_REG_THR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x00000070U)
#define MDM_SYNCH_ALT__PH_REG_THR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000070U) | (((uint32_t)(src) <<\
                    4) & 0x00000070U)
#define MDM_SYNCH_ALT__PH_REG_THR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x00000070U)))
#define MDM_SYNCH_ALT__PH_REG_THR__RESET_VALUE                      0x00000001U
/** @} */

/* macros for field ph_reg_thr2 */
/**
 * @defgroup mdm_regs_core_ph_reg_thr2_field ph_reg_thr2_field
 * @brief macros for field ph_reg_thr2
 * @details Phase accumulator threshold for timing tracking Encoding: 2^(ph_reg_thr). Gear 2. Supported range: 0-5
 * @{
 */
#define MDM_SYNCH_ALT__PH_REG_THR2__SHIFT                                     7
#define MDM_SYNCH_ALT__PH_REG_THR2__WIDTH                                     3
#define MDM_SYNCH_ALT__PH_REG_THR2__MASK                            0x00000380U
#define MDM_SYNCH_ALT__PH_REG_THR2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000380U) >> 7)
#define MDM_SYNCH_ALT__PH_REG_THR2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 7) & 0x00000380U)
#define MDM_SYNCH_ALT__PH_REG_THR2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000380U) | (((uint32_t)(src) <<\
                    7) & 0x00000380U)
#define MDM_SYNCH_ALT__PH_REG_THR2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 7) & ~0x00000380U)))
#define MDM_SYNCH_ALT__PH_REG_THR2__RESET_VALUE                     0x00000003U
/** @} */

/* macros for field ph_reg_thr3 */
/**
 * @defgroup mdm_regs_core_ph_reg_thr3_field ph_reg_thr3_field
 * @brief macros for field ph_reg_thr3
 * @details Phase accumulator threshold for timing tracking Encoding: 2^(ph_reg_thr). Gear 3. Supported range: 0-5
 * @{
 */
#define MDM_SYNCH_ALT__PH_REG_THR3__SHIFT                                    10
#define MDM_SYNCH_ALT__PH_REG_THR3__WIDTH                                     3
#define MDM_SYNCH_ALT__PH_REG_THR3__MASK                            0x00001c00U
#define MDM_SYNCH_ALT__PH_REG_THR3__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00001c00U) >> 10)
#define MDM_SYNCH_ALT__PH_REG_THR3__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x00001c00U)
#define MDM_SYNCH_ALT__PH_REG_THR3__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00001c00U) | (((uint32_t)(src) <<\
                    10) & 0x00001c00U)
#define MDM_SYNCH_ALT__PH_REG_THR3__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x00001c00U)))
#define MDM_SYNCH_ALT__PH_REG_THR3__RESET_VALUE                     0x00000004U
/** @} */

/* macros for field enable_time_track */
/**
 * @defgroup mdm_regs_core_enable_time_track_field enable_time_track_field
 * @brief macros for field enable_time_track
 * @details Enable time tracking, although can also be disabled with setting pg to 2'd0
 * @{
 */
#define MDM_SYNCH_ALT__ENABLE_TIME_TRACK__SHIFT                              13
#define MDM_SYNCH_ALT__ENABLE_TIME_TRACK__WIDTH                               1
#define MDM_SYNCH_ALT__ENABLE_TIME_TRACK__MASK                      0x00002000U
#define MDM_SYNCH_ALT__ENABLE_TIME_TRACK__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00002000U) >> 13)
#define MDM_SYNCH_ALT__ENABLE_TIME_TRACK__WRITE(src) \
                    (((uint32_t)(src)\
                    << 13) & 0x00002000U)
#define MDM_SYNCH_ALT__ENABLE_TIME_TRACK__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | (((uint32_t)(src) <<\
                    13) & 0x00002000U)
#define MDM_SYNCH_ALT__ENABLE_TIME_TRACK__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 13) & ~0x00002000U)))
#define MDM_SYNCH_ALT__ENABLE_TIME_TRACK__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | ((uint32_t)(1) << 13)
#define MDM_SYNCH_ALT__ENABLE_TIME_TRACK__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | ((uint32_t)(0) << 13)
#define MDM_SYNCH_ALT__ENABLE_TIME_TRACK__RESET_VALUE               0x00000001U
/** @} */

/* macros for field freq_force_initial */
/**
 * @defgroup mdm_regs_core_freq_force_initial_field freq_force_initial_field
 * @brief macros for field freq_force_initial
 * @details Force initial frequency estimate
 * @{
 */
#define MDM_SYNCH_ALT__FREQ_FORCE_INITIAL__SHIFT                             14
#define MDM_SYNCH_ALT__FREQ_FORCE_INITIAL__WIDTH                              1
#define MDM_SYNCH_ALT__FREQ_FORCE_INITIAL__MASK                     0x00004000U
#define MDM_SYNCH_ALT__FREQ_FORCE_INITIAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00004000U) >> 14)
#define MDM_SYNCH_ALT__FREQ_FORCE_INITIAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 14) & 0x00004000U)
#define MDM_SYNCH_ALT__FREQ_FORCE_INITIAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | (((uint32_t)(src) <<\
                    14) & 0x00004000U)
#define MDM_SYNCH_ALT__FREQ_FORCE_INITIAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 14) & ~0x00004000U)))
#define MDM_SYNCH_ALT__FREQ_FORCE_INITIAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | ((uint32_t)(1) << 14)
#define MDM_SYNCH_ALT__FREQ_FORCE_INITIAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | ((uint32_t)(0) << 14)
#define MDM_SYNCH_ALT__FREQ_FORCE_INITIAL__RESET_VALUE              0x00000000U
/** @} */

/* macros for field freq_forced_value */
/**
 * @defgroup mdm_regs_core_freq_forced_value_field freq_forced_value_field
 * @brief macros for field freq_forced_value
 * @details Forced initial frequency estimate value. Signed quantity. MSB has weight of -1 MHz. Subsequent bits have weight of 1/2 MHz, 1/4 MHz ... LSB has weight of 1/4096 MHz
 * @{
 */
#define MDM_SYNCH_ALT__FREQ_FORCED_VALUE__SHIFT                              15
#define MDM_SYNCH_ALT__FREQ_FORCED_VALUE__WIDTH                              13
#define MDM_SYNCH_ALT__FREQ_FORCED_VALUE__MASK                      0x0fff8000U
#define MDM_SYNCH_ALT__FREQ_FORCED_VALUE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0fff8000U) >> 15)
#define MDM_SYNCH_ALT__FREQ_FORCED_VALUE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 15) & 0x0fff8000U)
#define MDM_SYNCH_ALT__FREQ_FORCED_VALUE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0fff8000U) | (((uint32_t)(src) <<\
                    15) & 0x0fff8000U)
#define MDM_SYNCH_ALT__FREQ_FORCED_VALUE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 15) & ~0x0fff8000U)))
#define MDM_SYNCH_ALT__FREQ_FORCED_VALUE__RESET_VALUE               0x00000000U
/** @} */

/* macros for field rst_freq_no_gain_change_pwrstep */
/**
 * @defgroup mdm_regs_core_rst_freq_no_gain_change_pwrstep_field rst_freq_no_gain_change_pwrstep_field
 * @brief macros for field rst_freq_no_gain_change_pwrstep
 * @details Allow (unlimited) assert_reset_freq_sync due to power step within a MEASURE state, with no gain change
 * @{
 */
#define MDM_SYNCH_ALT__RST_FREQ_NO_GAIN_CHANGE_PWRSTEP__SHIFT                28
#define MDM_SYNCH_ALT__RST_FREQ_NO_GAIN_CHANGE_PWRSTEP__WIDTH                 1
#define MDM_SYNCH_ALT__RST_FREQ_NO_GAIN_CHANGE_PWRSTEP__MASK        0x10000000U
#define MDM_SYNCH_ALT__RST_FREQ_NO_GAIN_CHANGE_PWRSTEP__READ(src) \
                    (((uint32_t)(src)\
                    & 0x10000000U) >> 28)
#define MDM_SYNCH_ALT__RST_FREQ_NO_GAIN_CHANGE_PWRSTEP__WRITE(src) \
                    (((uint32_t)(src)\
                    << 28) & 0x10000000U)
#define MDM_SYNCH_ALT__RST_FREQ_NO_GAIN_CHANGE_PWRSTEP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x10000000U) | (((uint32_t)(src) <<\
                    28) & 0x10000000U)
#define MDM_SYNCH_ALT__RST_FREQ_NO_GAIN_CHANGE_PWRSTEP__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 28) & ~0x10000000U)))
#define MDM_SYNCH_ALT__RST_FREQ_NO_GAIN_CHANGE_PWRSTEP__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x10000000U) | ((uint32_t)(1) << 28)
#define MDM_SYNCH_ALT__RST_FREQ_NO_GAIN_CHANGE_PWRSTEP__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x10000000U) | ((uint32_t)(0) << 28)
#define MDM_SYNCH_ALT__RST_FREQ_NO_GAIN_CHANGE_PWRSTEP__RESET_VALUE 0x00000001U
/** @} */

/* macros for field rst_freq_no_gain_change_rfin */
/**
 * @defgroup mdm_regs_core_rst_freq_no_gain_change_rfin_field rst_freq_no_gain_change_rfin_field
 * @brief macros for field rst_freq_no_gain_change_rfin
 * @details Allow one assert_reset_freq_sync due to rfin peak within a MEASURE state, with no gain change
 * @{
 */
#define MDM_SYNCH_ALT__RST_FREQ_NO_GAIN_CHANGE_RFIN__SHIFT                   29
#define MDM_SYNCH_ALT__RST_FREQ_NO_GAIN_CHANGE_RFIN__WIDTH                    1
#define MDM_SYNCH_ALT__RST_FREQ_NO_GAIN_CHANGE_RFIN__MASK           0x20000000U
#define MDM_SYNCH_ALT__RST_FREQ_NO_GAIN_CHANGE_RFIN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x20000000U) >> 29)
#define MDM_SYNCH_ALT__RST_FREQ_NO_GAIN_CHANGE_RFIN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 29) & 0x20000000U)
#define MDM_SYNCH_ALT__RST_FREQ_NO_GAIN_CHANGE_RFIN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | (((uint32_t)(src) <<\
                    29) & 0x20000000U)
#define MDM_SYNCH_ALT__RST_FREQ_NO_GAIN_CHANGE_RFIN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 29) & ~0x20000000U)))
#define MDM_SYNCH_ALT__RST_FREQ_NO_GAIN_CHANGE_RFIN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | ((uint32_t)(1) << 29)
#define MDM_SYNCH_ALT__RST_FREQ_NO_GAIN_CHANGE_RFIN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | ((uint32_t)(0) << 29)
#define MDM_SYNCH_ALT__RST_FREQ_NO_GAIN_CHANGE_RFIN__RESET_VALUE    0x00000001U
/** @} */

/* macros for field rst_freq_no_gain_change_tia */
/**
 * @defgroup mdm_regs_core_rst_freq_no_gain_change_tia_field rst_freq_no_gain_change_tia_field
 * @brief macros for field rst_freq_no_gain_change_tia
 * @details Allow one assert_reset_freq_sync due to tia peak within a MEASURE state, with no gain change
 * @{
 */
#define MDM_SYNCH_ALT__RST_FREQ_NO_GAIN_CHANGE_TIA__SHIFT                    30
#define MDM_SYNCH_ALT__RST_FREQ_NO_GAIN_CHANGE_TIA__WIDTH                     1
#define MDM_SYNCH_ALT__RST_FREQ_NO_GAIN_CHANGE_TIA__MASK            0x40000000U
#define MDM_SYNCH_ALT__RST_FREQ_NO_GAIN_CHANGE_TIA__READ(src) \
                    (((uint32_t)(src)\
                    & 0x40000000U) >> 30)
#define MDM_SYNCH_ALT__RST_FREQ_NO_GAIN_CHANGE_TIA__WRITE(src) \
                    (((uint32_t)(src)\
                    << 30) & 0x40000000U)
#define MDM_SYNCH_ALT__RST_FREQ_NO_GAIN_CHANGE_TIA__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | (((uint32_t)(src) <<\
                    30) & 0x40000000U)
#define MDM_SYNCH_ALT__RST_FREQ_NO_GAIN_CHANGE_TIA__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 30) & ~0x40000000U)))
#define MDM_SYNCH_ALT__RST_FREQ_NO_GAIN_CHANGE_TIA__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(1) << 30)
#define MDM_SYNCH_ALT__RST_FREQ_NO_GAIN_CHANGE_TIA__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(0) << 30)
#define MDM_SYNCH_ALT__RST_FREQ_NO_GAIN_CHANGE_TIA__RESET_VALUE     0x00000001U
/** @} */

/* macros for field rst_freq_no_gain_change_sat */
/**
 * @defgroup mdm_regs_core_rst_freq_no_gain_change_sat_field rst_freq_no_gain_change_sat_field
 * @brief macros for field rst_freq_no_gain_change_sat
 * @details Allow one assert_reset_freq_sync due to adc sat within a MEASURE state, with no gain change
 * @{
 */
#define MDM_SYNCH_ALT__RST_FREQ_NO_GAIN_CHANGE_SAT__SHIFT                    31
#define MDM_SYNCH_ALT__RST_FREQ_NO_GAIN_CHANGE_SAT__WIDTH                     1
#define MDM_SYNCH_ALT__RST_FREQ_NO_GAIN_CHANGE_SAT__MASK            0x80000000U
#define MDM_SYNCH_ALT__RST_FREQ_NO_GAIN_CHANGE_SAT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x80000000U) >> 31)
#define MDM_SYNCH_ALT__RST_FREQ_NO_GAIN_CHANGE_SAT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 31) & 0x80000000U)
#define MDM_SYNCH_ALT__RST_FREQ_NO_GAIN_CHANGE_SAT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | (((uint32_t)(src) <<\
                    31) & 0x80000000U)
#define MDM_SYNCH_ALT__RST_FREQ_NO_GAIN_CHANGE_SAT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 31) & ~0x80000000U)))
#define MDM_SYNCH_ALT__RST_FREQ_NO_GAIN_CHANGE_SAT__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(1) << 31)
#define MDM_SYNCH_ALT__RST_FREQ_NO_GAIN_CHANGE_SAT__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(0) << 31)
#define MDM_SYNCH_ALT__RST_FREQ_NO_GAIN_CHANGE_SAT__RESET_VALUE     0x00000001U
/** @} */
#define MDM_SYNCH_ALT__TYPE                                            uint32_t
#define MDM_SYNCH_ALT__READ                                         0xfffffffcU
#define MDM_SYNCH_ALT__WRITE                                        0xfffffffcU
#define MDM_SYNCH_ALT__PRESERVED                                    0x00000000U
#define MDM_SYNCH_ALT__RESET_VALUE                                  0xf0003194U

#endif /* __MDM_SYNCH_ALT_MACRO__ */

/** @} end of synch_alt */

/* macros for BlueprintGlobalNameSpace::MDM_timetrack */
/**
 * @defgroup mdm_regs_core_timetrack timetrack
 * @brief Specifies gears for time tracking definitions.
 * @{
 */
#ifndef __MDM_TIMETRACK_MACRO__
#define __MDM_TIMETRACK_MACRO__

/* macros for field byte_count */
/**
 * @defgroup mdm_regs_core_byte_count_field byte_count_field
 * @brief macros for field byte_count
 * @details Number of bytes to process before switching from gear 1 to gear 2
 * @{
 */
#define MDM_TIMETRACK__BYTE_COUNT__SHIFT                                      0
#define MDM_TIMETRACK__BYTE_COUNT__WIDTH                                      8
#define MDM_TIMETRACK__BYTE_COUNT__MASK                             0x000000ffU
#define MDM_TIMETRACK__BYTE_COUNT__READ(src)    ((uint32_t)(src) & 0x000000ffU)
#define MDM_TIMETRACK__BYTE_COUNT__WRITE(src)   ((uint32_t)(src) & 0x000000ffU)
#define MDM_TIMETRACK__BYTE_COUNT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000ffU) | ((uint32_t)(src) &\
                    0x000000ffU)
#define MDM_TIMETRACK__BYTE_COUNT__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000000ffU)))
#define MDM_TIMETRACK__BYTE_COUNT__RESET_VALUE                      0x00000001U
/** @} */

/* macros for field byte_count2 */
/**
 * @defgroup mdm_regs_core_byte_count2_field byte_count2_field
 * @brief macros for field byte_count2
 * @details Number of bytes to process before switching to gear 3. (Includes bytes from gear 1 PLUS gear 2)
 * @{
 */
#define MDM_TIMETRACK__BYTE_COUNT2__SHIFT                                     8
#define MDM_TIMETRACK__BYTE_COUNT2__WIDTH                                     8
#define MDM_TIMETRACK__BYTE_COUNT2__MASK                            0x0000ff00U
#define MDM_TIMETRACK__BYTE_COUNT2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000ff00U) >> 8)
#define MDM_TIMETRACK__BYTE_COUNT2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x0000ff00U)
#define MDM_TIMETRACK__BYTE_COUNT2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000ff00U) | (((uint32_t)(src) <<\
                    8) & 0x0000ff00U)
#define MDM_TIMETRACK__BYTE_COUNT2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x0000ff00U)))
#define MDM_TIMETRACK__BYTE_COUNT2__RESET_VALUE                     0x00000002U
/** @} */
#define MDM_TIMETRACK__TYPE                                            uint32_t
#define MDM_TIMETRACK__READ                                         0x0000ffffU
#define MDM_TIMETRACK__WRITE                                        0x0000ffffU
#define MDM_TIMETRACK__PRESERVED                                    0x00000000U
#define MDM_TIMETRACK__RESET_VALUE                                  0x00000201U

#endif /* __MDM_TIMETRACK_MACRO__ */

/** @} end of timetrack */

/* macros for BlueprintGlobalNameSpace::MDM_timesync */
/**
 * @defgroup mdm_regs_core_timesync timesync
 * @brief Time sync RSSI and absolute difference thresholds definitions.
 * @{
 */
#ifndef __MDM_TIMESYNC_MACRO__
#define __MDM_TIMESYNC_MACRO__

/* macros for field rssi_thr */
/**
 * @defgroup mdm_regs_core_rssi_thr_field rssi_thr_field
 * @brief macros for field rssi_thr
 * @details Ignore min_thr checks if rssi <= rssi_thr. 8'd168 = -88
 * @{
 */
#define MDM_TIMESYNC__RSSI_THR__SHIFT                                         0
#define MDM_TIMESYNC__RSSI_THR__WIDTH                                         8
#define MDM_TIMESYNC__RSSI_THR__MASK                                0x000000ffU
#define MDM_TIMESYNC__RSSI_THR__READ(src)       ((uint32_t)(src) & 0x000000ffU)
#define MDM_TIMESYNC__RSSI_THR__WRITE(src)      ((uint32_t)(src) & 0x000000ffU)
#define MDM_TIMESYNC__RSSI_THR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000ffU) | ((uint32_t)(src) &\
                    0x000000ffU)
#define MDM_TIMESYNC__RSSI_THR__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000000ffU)))
#define MDM_TIMESYNC__RSSI_THR__RESET_VALUE                         0x000000a8U
/** @} */

/* macros for field corr_tmg_adj */
/**
 * @defgroup mdm_regs_core_corr_tmg_adj_field corr_tmg_adj_field
 * @brief macros for field corr_tmg_adj
 * @details When FFE is enabled post AA detection, amount of timing adjustment (range is [-8, 7])
 * @{
 */
#define MDM_TIMESYNC__CORR_TMG_ADJ__SHIFT                                     8
#define MDM_TIMESYNC__CORR_TMG_ADJ__WIDTH                                     4
#define MDM_TIMESYNC__CORR_TMG_ADJ__MASK                            0x00000f00U
#define MDM_TIMESYNC__CORR_TMG_ADJ__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000f00U) >> 8)
#define MDM_TIMESYNC__CORR_TMG_ADJ__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00000f00U)
#define MDM_TIMESYNC__CORR_TMG_ADJ__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000f00U) | (((uint32_t)(src) <<\
                    8) & 0x00000f00U)
#define MDM_TIMESYNC__CORR_TMG_ADJ__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00000f00U)))
#define MDM_TIMESYNC__CORR_TMG_ADJ__RESET_VALUE                     0x00000000U
/** @} */

/* macros for field twomeg_corr_tmg_adj */
/**
 * @defgroup mdm_regs_core_twomeg_corr_tmg_adj_field twomeg_corr_tmg_adj_field
 * @brief macros for field twomeg_corr_tmg_adj
 * @details When FFE is enabled post AA detection, amount of timing adjustment (range is [-8, 7])
 * @{
 */
#define MDM_TIMESYNC__TWOMEG_CORR_TMG_ADJ__SHIFT                             12
#define MDM_TIMESYNC__TWOMEG_CORR_TMG_ADJ__WIDTH                              4
#define MDM_TIMESYNC__TWOMEG_CORR_TMG_ADJ__MASK                     0x0000f000U
#define MDM_TIMESYNC__TWOMEG_CORR_TMG_ADJ__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000f000U) >> 12)
#define MDM_TIMESYNC__TWOMEG_CORR_TMG_ADJ__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x0000f000U)
#define MDM_TIMESYNC__TWOMEG_CORR_TMG_ADJ__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000f000U) | (((uint32_t)(src) <<\
                    12) & 0x0000f000U)
#define MDM_TIMESYNC__TWOMEG_CORR_TMG_ADJ__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x0000f000U)))
#define MDM_TIMESYNC__TWOMEG_CORR_TMG_ADJ__RESET_VALUE              0x00000000U
/** @} */

/* macros for field coded_min_thr */
/**
 * @defgroup mdm_regs_core_coded_min_thr_field coded_min_thr_field
 * @brief macros for field coded_min_thr
 * @details Minimum absolute difference for coded rates
 * @{
 */
#define MDM_TIMESYNC__CODED_MIN_THR__SHIFT                                   24
#define MDM_TIMESYNC__CODED_MIN_THR__WIDTH                                    8
#define MDM_TIMESYNC__CODED_MIN_THR__MASK                           0xff000000U
#define MDM_TIMESYNC__CODED_MIN_THR__READ(src) \
                    (((uint32_t)(src)\
                    & 0xff000000U) >> 24)
#define MDM_TIMESYNC__CODED_MIN_THR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0xff000000U)
#define MDM_TIMESYNC__CODED_MIN_THR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xff000000U) | (((uint32_t)(src) <<\
                    24) & 0xff000000U)
#define MDM_TIMESYNC__CODED_MIN_THR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0xff000000U)))
#define MDM_TIMESYNC__CODED_MIN_THR__RESET_VALUE                    0x00000096U
/** @} */
#define MDM_TIMESYNC__TYPE                                             uint32_t
#define MDM_TIMESYNC__READ                                          0xff00ffffU
#define MDM_TIMESYNC__WRITE                                         0xff00ffffU
#define MDM_TIMESYNC__PRESERVED                                     0x00000000U
#define MDM_TIMESYNC__RESET_VALUE                                   0x960000a8U

#endif /* __MDM_TIMESYNC_MACRO__ */

/** @} end of timesync */

/* macros for BlueprintGlobalNameSpace::MDM_timesync_alt */
/**
 * @defgroup mdm_regs_core_timesync_alt timesync_alt
 * @brief Time sync RSSI and absolute difference thresholds, alternate set definitions.
 * @{
 */
#ifndef __MDM_TIMESYNC_ALT_MACRO__
#define __MDM_TIMESYNC_ALT_MACRO__

/* macros for field rssi_thr */
/**
 * @defgroup mdm_regs_core_rssi_thr_field rssi_thr_field
 * @brief macros for field rssi_thr
 * @details Ignore min_thr checks if rssi <= rssi_thr. 8'd168 = -88
 * @{
 */
#define MDM_TIMESYNC_ALT__RSSI_THR__SHIFT                                     0
#define MDM_TIMESYNC_ALT__RSSI_THR__WIDTH                                     8
#define MDM_TIMESYNC_ALT__RSSI_THR__MASK                            0x000000ffU
#define MDM_TIMESYNC_ALT__RSSI_THR__READ(src)   ((uint32_t)(src) & 0x000000ffU)
#define MDM_TIMESYNC_ALT__RSSI_THR__WRITE(src)  ((uint32_t)(src) & 0x000000ffU)
#define MDM_TIMESYNC_ALT__RSSI_THR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000ffU) | ((uint32_t)(src) &\
                    0x000000ffU)
#define MDM_TIMESYNC_ALT__RSSI_THR__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000000ffU)))
#define MDM_TIMESYNC_ALT__RSSI_THR__RESET_VALUE                     0x000000a8U
/** @} */

/* macros for field corr_tmg_adj */
/**
 * @defgroup mdm_regs_core_corr_tmg_adj_field corr_tmg_adj_field
 * @brief macros for field corr_tmg_adj
 * @details When FFE is enabled post AA detection, amount of timing adjustment (range is [-8, 7])
 * @{
 */
#define MDM_TIMESYNC_ALT__CORR_TMG_ADJ__SHIFT                                 8
#define MDM_TIMESYNC_ALT__CORR_TMG_ADJ__WIDTH                                 4
#define MDM_TIMESYNC_ALT__CORR_TMG_ADJ__MASK                        0x00000f00U
#define MDM_TIMESYNC_ALT__CORR_TMG_ADJ__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000f00U) >> 8)
#define MDM_TIMESYNC_ALT__CORR_TMG_ADJ__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00000f00U)
#define MDM_TIMESYNC_ALT__CORR_TMG_ADJ__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000f00U) | (((uint32_t)(src) <<\
                    8) & 0x00000f00U)
#define MDM_TIMESYNC_ALT__CORR_TMG_ADJ__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00000f00U)))
#define MDM_TIMESYNC_ALT__CORR_TMG_ADJ__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field twomeg_corr_tmg_adj */
/**
 * @defgroup mdm_regs_core_twomeg_corr_tmg_adj_field twomeg_corr_tmg_adj_field
 * @brief macros for field twomeg_corr_tmg_adj
 * @details When FFE is enabled post AA detection, amount of timing adjustment (range is [-8, 7])
 * @{
 */
#define MDM_TIMESYNC_ALT__TWOMEG_CORR_TMG_ADJ__SHIFT                         12
#define MDM_TIMESYNC_ALT__TWOMEG_CORR_TMG_ADJ__WIDTH                          4
#define MDM_TIMESYNC_ALT__TWOMEG_CORR_TMG_ADJ__MASK                 0x0000f000U
#define MDM_TIMESYNC_ALT__TWOMEG_CORR_TMG_ADJ__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000f000U) >> 12)
#define MDM_TIMESYNC_ALT__TWOMEG_CORR_TMG_ADJ__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x0000f000U)
#define MDM_TIMESYNC_ALT__TWOMEG_CORR_TMG_ADJ__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000f000U) | (((uint32_t)(src) <<\
                    12) & 0x0000f000U)
#define MDM_TIMESYNC_ALT__TWOMEG_CORR_TMG_ADJ__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x0000f000U)))
#define MDM_TIMESYNC_ALT__TWOMEG_CORR_TMG_ADJ__RESET_VALUE          0x00000000U
/** @} */

/* macros for field coded_min_thr */
/**
 * @defgroup mdm_regs_core_coded_min_thr_field coded_min_thr_field
 * @brief macros for field coded_min_thr
 * @details Minimum absolute difference for coded rates
 * @{
 */
#define MDM_TIMESYNC_ALT__CODED_MIN_THR__SHIFT                               24
#define MDM_TIMESYNC_ALT__CODED_MIN_THR__WIDTH                                8
#define MDM_TIMESYNC_ALT__CODED_MIN_THR__MASK                       0xff000000U
#define MDM_TIMESYNC_ALT__CODED_MIN_THR__READ(src) \
                    (((uint32_t)(src)\
                    & 0xff000000U) >> 24)
#define MDM_TIMESYNC_ALT__CODED_MIN_THR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0xff000000U)
#define MDM_TIMESYNC_ALT__CODED_MIN_THR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xff000000U) | (((uint32_t)(src) <<\
                    24) & 0xff000000U)
#define MDM_TIMESYNC_ALT__CODED_MIN_THR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0xff000000U)))
#define MDM_TIMESYNC_ALT__CODED_MIN_THR__RESET_VALUE                0x00000096U
/** @} */
#define MDM_TIMESYNC_ALT__TYPE                                         uint32_t
#define MDM_TIMESYNC_ALT__READ                                      0xff00ffffU
#define MDM_TIMESYNC_ALT__WRITE                                     0xff00ffffU
#define MDM_TIMESYNC_ALT__PRESERVED                                 0x00000000U
#define MDM_TIMESYNC_ALT__RESET_VALUE                               0x960000a8U

#endif /* __MDM_TIMESYNC_ALT_MACRO__ */

/** @} end of timesync_alt */

/* macros for BlueprintGlobalNameSpace::MDM_syncdemod */
/**
 * @defgroup mdm_regs_core_syncdemod syncdemod
 * @brief Additional sync/demod controls definitions.
 * @{
 */
#ifndef __MDM_SYNCDEMOD_MACRO__
#define __MDM_SYNCDEMOD_MACRO__

/* macros for field coded_find_two_peaks */
/**
 * @defgroup mdm_regs_core_coded_find_two_peaks_field coded_find_two_peaks_field
 * @brief macros for field coded_find_two_peaks
 * @details For timing sync, coded with 2x or 4x averaging, require best absolute difference from last 4 us window and absolute difference from first 4 us window (using best timing index from last window) to exceed threshold. Coded version.
 * @{
 */
#define MDM_SYNCDEMOD__CODED_FIND_TWO_PEAKS__SHIFT                            0
#define MDM_SYNCDEMOD__CODED_FIND_TWO_PEAKS__WIDTH                            1
#define MDM_SYNCDEMOD__CODED_FIND_TWO_PEAKS__MASK                   0x00000001U
#define MDM_SYNCDEMOD__CODED_FIND_TWO_PEAKS__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define MDM_SYNCDEMOD__CODED_FIND_TWO_PEAKS__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define MDM_SYNCDEMOD__CODED_FIND_TWO_PEAKS__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define MDM_SYNCDEMOD__CODED_FIND_TWO_PEAKS__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define MDM_SYNCDEMOD__CODED_FIND_TWO_PEAKS__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define MDM_SYNCDEMOD__CODED_FIND_TWO_PEAKS__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define MDM_SYNCDEMOD__CODED_FIND_TWO_PEAKS__RESET_VALUE            0x00000001U
/** @} */

/* macros for field freqwin1 */
/**
 * @defgroup mdm_regs_core_freqwin1_field freqwin1_field
 * @brief macros for field freqwin1
 * @details Uncoded freqsync window length, default case Encoding in number of symbols 3'd0->2, 3'd1->2.5, 3'd2->3, 3'd3->3.5, 3'd4->4.0
 * @{
 */
#define MDM_SYNCDEMOD__FREQWIN1__SHIFT                                        1
#define MDM_SYNCDEMOD__FREQWIN1__WIDTH                                        3
#define MDM_SYNCDEMOD__FREQWIN1__MASK                               0x0000000eU
#define MDM_SYNCDEMOD__FREQWIN1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000000eU) >> 1)
#define MDM_SYNCDEMOD__FREQWIN1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x0000000eU)
#define MDM_SYNCDEMOD__FREQWIN1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000000eU) | (((uint32_t)(src) <<\
                    1) & 0x0000000eU)
#define MDM_SYNCDEMOD__FREQWIN1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x0000000eU)))
#define MDM_SYNCDEMOD__FREQWIN1__RESET_VALUE                        0x00000002U
/** @} */

/* macros for field freqwin2 */
/**
 * @defgroup mdm_regs_core_freqwin2_field freqwin2_field
 * @brief macros for field freqwin2
 * @details After back-to-back peak/sat and sat
 * @{
 */
#define MDM_SYNCDEMOD__FREQWIN2__SHIFT                                        4
#define MDM_SYNCDEMOD__FREQWIN2__WIDTH                                        3
#define MDM_SYNCDEMOD__FREQWIN2__MASK                               0x00000070U
#define MDM_SYNCDEMOD__FREQWIN2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000070U) >> 4)
#define MDM_SYNCDEMOD__FREQWIN2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x00000070U)
#define MDM_SYNCDEMOD__FREQWIN2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000070U) | (((uint32_t)(src) <<\
                    4) & 0x00000070U)
#define MDM_SYNCDEMOD__FREQWIN2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x00000070U)))
#define MDM_SYNCDEMOD__FREQWIN2__RESET_VALUE                        0x00000001U
/** @} */

/* macros for field freqwin3 */
/**
 * @defgroup mdm_regs_core_freqwin3_field freqwin3_field
 * @brief macros for field freqwin3
 * @details Power step, no gain change
 * @{
 */
#define MDM_SYNCDEMOD__FREQWIN3__SHIFT                                        7
#define MDM_SYNCDEMOD__FREQWIN3__WIDTH                                        3
#define MDM_SYNCDEMOD__FREQWIN3__MASK                               0x00000380U
#define MDM_SYNCDEMOD__FREQWIN3__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000380U) >> 7)
#define MDM_SYNCDEMOD__FREQWIN3__WRITE(src) \
                    (((uint32_t)(src)\
                    << 7) & 0x00000380U)
#define MDM_SYNCDEMOD__FREQWIN3__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000380U) | (((uint32_t)(src) <<\
                    7) & 0x00000380U)
#define MDM_SYNCDEMOD__FREQWIN3__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 7) & ~0x00000380U)))
#define MDM_SYNCDEMOD__FREQWIN3__RESET_VALUE                        0x00000004U
/** @} */

/* macros for field twomeg_freqwin1 */
/**
 * @defgroup mdm_regs_core_twomeg_freqwin1_field twomeg_freqwin1_field
 * @brief macros for field twomeg_freqwin1
 * @details Uncoded freqsync window length, default case Encoding in number of symbols 3'd0->2, 3'd1->2.5, 3'd2->3, 3'd3->3.5, 3'd4->4.0. 2M rate
 * @{
 */
#define MDM_SYNCDEMOD__TWOMEG_FREQWIN1__SHIFT                                10
#define MDM_SYNCDEMOD__TWOMEG_FREQWIN1__WIDTH                                 3
#define MDM_SYNCDEMOD__TWOMEG_FREQWIN1__MASK                        0x00001c00U
#define MDM_SYNCDEMOD__TWOMEG_FREQWIN1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00001c00U) >> 10)
#define MDM_SYNCDEMOD__TWOMEG_FREQWIN1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x00001c00U)
#define MDM_SYNCDEMOD__TWOMEG_FREQWIN1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00001c00U) | (((uint32_t)(src) <<\
                    10) & 0x00001c00U)
#define MDM_SYNCDEMOD__TWOMEG_FREQWIN1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x00001c00U)))
#define MDM_SYNCDEMOD__TWOMEG_FREQWIN1__RESET_VALUE                 0x00000002U
/** @} */

/* macros for field twomeg_freqwin2 */
/**
 * @defgroup mdm_regs_core_twomeg_freqwin2_field twomeg_freqwin2_field
 * @brief macros for field twomeg_freqwin2
 * @details After back-to-back peak/sat and sat. 2M rate
 * @{
 */
#define MDM_SYNCDEMOD__TWOMEG_FREQWIN2__SHIFT                                13
#define MDM_SYNCDEMOD__TWOMEG_FREQWIN2__WIDTH                                 3
#define MDM_SYNCDEMOD__TWOMEG_FREQWIN2__MASK                        0x0000e000U
#define MDM_SYNCDEMOD__TWOMEG_FREQWIN2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000e000U) >> 13)
#define MDM_SYNCDEMOD__TWOMEG_FREQWIN2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 13) & 0x0000e000U)
#define MDM_SYNCDEMOD__TWOMEG_FREQWIN2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000e000U) | (((uint32_t)(src) <<\
                    13) & 0x0000e000U)
#define MDM_SYNCDEMOD__TWOMEG_FREQWIN2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 13) & ~0x0000e000U)))
#define MDM_SYNCDEMOD__TWOMEG_FREQWIN2__RESET_VALUE                 0x00000001U
/** @} */

/* macros for field twomeg_freqwin3 */
/**
 * @defgroup mdm_regs_core_twomeg_freqwin3_field twomeg_freqwin3_field
 * @brief macros for field twomeg_freqwin3
 * @details Power step, no gain change. 2M rate
 * @{
 */
#define MDM_SYNCDEMOD__TWOMEG_FREQWIN3__SHIFT                                16
#define MDM_SYNCDEMOD__TWOMEG_FREQWIN3__WIDTH                                 3
#define MDM_SYNCDEMOD__TWOMEG_FREQWIN3__MASK                        0x00070000U
#define MDM_SYNCDEMOD__TWOMEG_FREQWIN3__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00070000U) >> 16)
#define MDM_SYNCDEMOD__TWOMEG_FREQWIN3__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x00070000U)
#define MDM_SYNCDEMOD__TWOMEG_FREQWIN3__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00070000U) | (((uint32_t)(src) <<\
                    16) & 0x00070000U)
#define MDM_SYNCDEMOD__TWOMEG_FREQWIN3__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x00070000U)))
#define MDM_SYNCDEMOD__TWOMEG_FREQWIN3__RESET_VALUE                 0x00000004U
/** @} */
#define MDM_SYNCDEMOD__TYPE                                            uint32_t
#define MDM_SYNCDEMOD__READ                                         0x0007ffffU
#define MDM_SYNCDEMOD__WRITE                                        0x0007ffffU
#define MDM_SYNCDEMOD__PRESERVED                                    0x00000000U
#define MDM_SYNCDEMOD__RESET_VALUE                                  0x00042a15U

#endif /* __MDM_SYNCDEMOD_MACRO__ */

/** @} end of syncdemod */

/* macros for BlueprintGlobalNameSpace::MDM_syncdemod_alt */
/**
 * @defgroup mdm_regs_core_syncdemod_alt syncdemod_alt
 * @brief Additional sync/demod controls, alternate set definitions.
 * @{
 */
#ifndef __MDM_SYNCDEMOD_ALT_MACRO__
#define __MDM_SYNCDEMOD_ALT_MACRO__

/* macros for field coded_find_two_peaks */
/**
 * @defgroup mdm_regs_core_coded_find_two_peaks_field coded_find_two_peaks_field
 * @brief macros for field coded_find_two_peaks
 * @details For timing sync, coded with 2x or 4x averaging, require best absolute difference from last 4 us window and absolute difference from first 4 us window (using best timing index from last window) to exceed threshold. Coded version.
 * @{
 */
#define MDM_SYNCDEMOD_ALT__CODED_FIND_TWO_PEAKS__SHIFT                        0
#define MDM_SYNCDEMOD_ALT__CODED_FIND_TWO_PEAKS__WIDTH                        1
#define MDM_SYNCDEMOD_ALT__CODED_FIND_TWO_PEAKS__MASK               0x00000001U
#define MDM_SYNCDEMOD_ALT__CODED_FIND_TWO_PEAKS__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define MDM_SYNCDEMOD_ALT__CODED_FIND_TWO_PEAKS__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define MDM_SYNCDEMOD_ALT__CODED_FIND_TWO_PEAKS__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define MDM_SYNCDEMOD_ALT__CODED_FIND_TWO_PEAKS__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define MDM_SYNCDEMOD_ALT__CODED_FIND_TWO_PEAKS__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define MDM_SYNCDEMOD_ALT__CODED_FIND_TWO_PEAKS__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define MDM_SYNCDEMOD_ALT__CODED_FIND_TWO_PEAKS__RESET_VALUE        0x00000001U
/** @} */

/* macros for field freqwin1 */
/**
 * @defgroup mdm_regs_core_freqwin1_field freqwin1_field
 * @brief macros for field freqwin1
 * @details Uncoded freqsync window length, default case Encoding in number of symbols 3'd0->2, 3'd1->2.5, 3'd2->3, 3'd3->3.5, 3'd4->4.0
 * @{
 */
#define MDM_SYNCDEMOD_ALT__FREQWIN1__SHIFT                                    1
#define MDM_SYNCDEMOD_ALT__FREQWIN1__WIDTH                                    3
#define MDM_SYNCDEMOD_ALT__FREQWIN1__MASK                           0x0000000eU
#define MDM_SYNCDEMOD_ALT__FREQWIN1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000000eU) >> 1)
#define MDM_SYNCDEMOD_ALT__FREQWIN1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x0000000eU)
#define MDM_SYNCDEMOD_ALT__FREQWIN1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000000eU) | (((uint32_t)(src) <<\
                    1) & 0x0000000eU)
#define MDM_SYNCDEMOD_ALT__FREQWIN1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x0000000eU)))
#define MDM_SYNCDEMOD_ALT__FREQWIN1__RESET_VALUE                    0x00000002U
/** @} */

/* macros for field freqwin2 */
/**
 * @defgroup mdm_regs_core_freqwin2_field freqwin2_field
 * @brief macros for field freqwin2
 * @details After back-to-back peak/sat and sat
 * @{
 */
#define MDM_SYNCDEMOD_ALT__FREQWIN2__SHIFT                                    4
#define MDM_SYNCDEMOD_ALT__FREQWIN2__WIDTH                                    3
#define MDM_SYNCDEMOD_ALT__FREQWIN2__MASK                           0x00000070U
#define MDM_SYNCDEMOD_ALT__FREQWIN2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000070U) >> 4)
#define MDM_SYNCDEMOD_ALT__FREQWIN2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x00000070U)
#define MDM_SYNCDEMOD_ALT__FREQWIN2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000070U) | (((uint32_t)(src) <<\
                    4) & 0x00000070U)
#define MDM_SYNCDEMOD_ALT__FREQWIN2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x00000070U)))
#define MDM_SYNCDEMOD_ALT__FREQWIN2__RESET_VALUE                    0x00000001U
/** @} */

/* macros for field freqwin3 */
/**
 * @defgroup mdm_regs_core_freqwin3_field freqwin3_field
 * @brief macros for field freqwin3
 * @details Power step, no gain change
 * @{
 */
#define MDM_SYNCDEMOD_ALT__FREQWIN3__SHIFT                                    7
#define MDM_SYNCDEMOD_ALT__FREQWIN3__WIDTH                                    3
#define MDM_SYNCDEMOD_ALT__FREQWIN3__MASK                           0x00000380U
#define MDM_SYNCDEMOD_ALT__FREQWIN3__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000380U) >> 7)
#define MDM_SYNCDEMOD_ALT__FREQWIN3__WRITE(src) \
                    (((uint32_t)(src)\
                    << 7) & 0x00000380U)
#define MDM_SYNCDEMOD_ALT__FREQWIN3__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000380U) | (((uint32_t)(src) <<\
                    7) & 0x00000380U)
#define MDM_SYNCDEMOD_ALT__FREQWIN3__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 7) & ~0x00000380U)))
#define MDM_SYNCDEMOD_ALT__FREQWIN3__RESET_VALUE                    0x00000004U
/** @} */

/* macros for field twomeg_freqwin1 */
/**
 * @defgroup mdm_regs_core_twomeg_freqwin1_field twomeg_freqwin1_field
 * @brief macros for field twomeg_freqwin1
 * @details Uncoded freqsync window length, default case Encoding in number of symbols 3'd0->2, 3'd1->2.5, 3'd2->3, 3'd3->3.5, 3'd4->4.0. 2M rate
 * @{
 */
#define MDM_SYNCDEMOD_ALT__TWOMEG_FREQWIN1__SHIFT                            10
#define MDM_SYNCDEMOD_ALT__TWOMEG_FREQWIN1__WIDTH                             3
#define MDM_SYNCDEMOD_ALT__TWOMEG_FREQWIN1__MASK                    0x00001c00U
#define MDM_SYNCDEMOD_ALT__TWOMEG_FREQWIN1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00001c00U) >> 10)
#define MDM_SYNCDEMOD_ALT__TWOMEG_FREQWIN1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x00001c00U)
#define MDM_SYNCDEMOD_ALT__TWOMEG_FREQWIN1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00001c00U) | (((uint32_t)(src) <<\
                    10) & 0x00001c00U)
#define MDM_SYNCDEMOD_ALT__TWOMEG_FREQWIN1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x00001c00U)))
#define MDM_SYNCDEMOD_ALT__TWOMEG_FREQWIN1__RESET_VALUE             0x00000002U
/** @} */

/* macros for field twomeg_freqwin2 */
/**
 * @defgroup mdm_regs_core_twomeg_freqwin2_field twomeg_freqwin2_field
 * @brief macros for field twomeg_freqwin2
 * @details After back-to-back peak/sat and sat. 2M rate
 * @{
 */
#define MDM_SYNCDEMOD_ALT__TWOMEG_FREQWIN2__SHIFT                            13
#define MDM_SYNCDEMOD_ALT__TWOMEG_FREQWIN2__WIDTH                             3
#define MDM_SYNCDEMOD_ALT__TWOMEG_FREQWIN2__MASK                    0x0000e000U
#define MDM_SYNCDEMOD_ALT__TWOMEG_FREQWIN2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000e000U) >> 13)
#define MDM_SYNCDEMOD_ALT__TWOMEG_FREQWIN2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 13) & 0x0000e000U)
#define MDM_SYNCDEMOD_ALT__TWOMEG_FREQWIN2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000e000U) | (((uint32_t)(src) <<\
                    13) & 0x0000e000U)
#define MDM_SYNCDEMOD_ALT__TWOMEG_FREQWIN2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 13) & ~0x0000e000U)))
#define MDM_SYNCDEMOD_ALT__TWOMEG_FREQWIN2__RESET_VALUE             0x00000001U
/** @} */

/* macros for field twomeg_freqwin3 */
/**
 * @defgroup mdm_regs_core_twomeg_freqwin3_field twomeg_freqwin3_field
 * @brief macros for field twomeg_freqwin3
 * @details Power step, no gain change. 2M rate
 * @{
 */
#define MDM_SYNCDEMOD_ALT__TWOMEG_FREQWIN3__SHIFT                            16
#define MDM_SYNCDEMOD_ALT__TWOMEG_FREQWIN3__WIDTH                             3
#define MDM_SYNCDEMOD_ALT__TWOMEG_FREQWIN3__MASK                    0x00070000U
#define MDM_SYNCDEMOD_ALT__TWOMEG_FREQWIN3__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00070000U) >> 16)
#define MDM_SYNCDEMOD_ALT__TWOMEG_FREQWIN3__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x00070000U)
#define MDM_SYNCDEMOD_ALT__TWOMEG_FREQWIN3__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00070000U) | (((uint32_t)(src) <<\
                    16) & 0x00070000U)
#define MDM_SYNCDEMOD_ALT__TWOMEG_FREQWIN3__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x00070000U)))
#define MDM_SYNCDEMOD_ALT__TWOMEG_FREQWIN3__RESET_VALUE             0x00000004U
/** @} */
#define MDM_SYNCDEMOD_ALT__TYPE                                        uint32_t
#define MDM_SYNCDEMOD_ALT__READ                                     0x0007ffffU
#define MDM_SYNCDEMOD_ALT__WRITE                                    0x0007ffffU
#define MDM_SYNCDEMOD_ALT__PRESERVED                                0x00000000U
#define MDM_SYNCDEMOD_ALT__RESET_VALUE                              0x00042a15U

#endif /* __MDM_SYNCDEMOD_ALT_MACRO__ */

/** @} end of syncdemod_alt */

/* macros for BlueprintGlobalNameSpace::MDM_resetinitcfo */
/**
 * @defgroup mdm_regs_core_resetinitcfo resetinitcfo
 * @brief Control for resetting initial CFO estimate, uncoded only definitions.
 * @{
 */
#ifndef __MDM_RESETINITCFO_MACRO__
#define __MDM_RESETINITCFO_MACRO__

/* macros for field en */
/**
 * @defgroup mdm_regs_core_en_field en_field
 * @brief macros for field en
 * @details Enable for run-length based reset of one-shot CFO estimation
 * @{
 */
#define MDM_RESETINITCFO__EN__SHIFT                                           0
#define MDM_RESETINITCFO__EN__WIDTH                                           1
#define MDM_RESETINITCFO__EN__MASK                                  0x00000001U
#define MDM_RESETINITCFO__EN__READ(src)         ((uint32_t)(src) & 0x00000001U)
#define MDM_RESETINITCFO__EN__WRITE(src)        ((uint32_t)(src) & 0x00000001U)
#define MDM_RESETINITCFO__EN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define MDM_RESETINITCFO__EN__VERIFY(src) (!(((uint32_t)(src) & ~0x00000001U)))
#define MDM_RESETINITCFO__EN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define MDM_RESETINITCFO__EN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define MDM_RESETINITCFO__EN__RESET_VALUE                           0x00000000U
/** @} */

/* macros for field runlen_updt_thr */
/**
 * @defgroup mdm_regs_core_runlen_updt_thr_field runlen_updt_thr_field
 * @brief macros for field runlen_updt_thr
 * @details Threshold for abs(diff(MF out)) below which the run-length is incremented
 * @{
 */
#define MDM_RESETINITCFO__RUNLEN_UPDT_THR__SHIFT                              1
#define MDM_RESETINITCFO__RUNLEN_UPDT_THR__WIDTH                              6
#define MDM_RESETINITCFO__RUNLEN_UPDT_THR__MASK                     0x0000007eU
#define MDM_RESETINITCFO__RUNLEN_UPDT_THR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000007eU) >> 1)
#define MDM_RESETINITCFO__RUNLEN_UPDT_THR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x0000007eU)
#define MDM_RESETINITCFO__RUNLEN_UPDT_THR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000007eU) | (((uint32_t)(src) <<\
                    1) & 0x0000007eU)
#define MDM_RESETINITCFO__RUNLEN_UPDT_THR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x0000007eU)))
#define MDM_RESETINITCFO__RUNLEN_UPDT_THR__RESET_VALUE              0x00000016U
/** @} */

/* macros for field runlen_thr_to_reset_cfo */
/**
 * @defgroup mdm_regs_core_runlen_thr_to_reset_cfo_field runlen_thr_to_reset_cfo_field
 * @brief macros for field runlen_thr_to_reset_cfo
 * @details Threshold for run-length above which assert_reset_freq_sync is asserted
 * @{
 */
#define MDM_RESETINITCFO__RUNLEN_THR_TO_RESET_CFO__SHIFT                      7
#define MDM_RESETINITCFO__RUNLEN_THR_TO_RESET_CFO__WIDTH                      6
#define MDM_RESETINITCFO__RUNLEN_THR_TO_RESET_CFO__MASK             0x00001f80U
#define MDM_RESETINITCFO__RUNLEN_THR_TO_RESET_CFO__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00001f80U) >> 7)
#define MDM_RESETINITCFO__RUNLEN_THR_TO_RESET_CFO__WRITE(src) \
                    (((uint32_t)(src)\
                    << 7) & 0x00001f80U)
#define MDM_RESETINITCFO__RUNLEN_THR_TO_RESET_CFO__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00001f80U) | (((uint32_t)(src) <<\
                    7) & 0x00001f80U)
#define MDM_RESETINITCFO__RUNLEN_THR_TO_RESET_CFO__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 7) & ~0x00001f80U)))
#define MDM_RESETINITCFO__RUNLEN_THR_TO_RESET_CFO__RESET_VALUE      0x0000000fU
/** @} */

/* macros for field use_twosamples_to_updt_runlen */
/**
 * @defgroup mdm_regs_core_use_twosamples_to_updt_runlen_field use_twosamples_to_updt_runlen_field
 * @brief macros for field use_twosamples_to_updt_runlen
 * @details When 1, use OR of two most recent abs(diff(MF out)). When 0, use just most recent
 * @{
 */
#define MDM_RESETINITCFO__USE_TWOSAMPLES_TO_UPDT_RUNLEN__SHIFT               13
#define MDM_RESETINITCFO__USE_TWOSAMPLES_TO_UPDT_RUNLEN__WIDTH                1
#define MDM_RESETINITCFO__USE_TWOSAMPLES_TO_UPDT_RUNLEN__MASK       0x00002000U
#define MDM_RESETINITCFO__USE_TWOSAMPLES_TO_UPDT_RUNLEN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00002000U) >> 13)
#define MDM_RESETINITCFO__USE_TWOSAMPLES_TO_UPDT_RUNLEN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 13) & 0x00002000U)
#define MDM_RESETINITCFO__USE_TWOSAMPLES_TO_UPDT_RUNLEN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | (((uint32_t)(src) <<\
                    13) & 0x00002000U)
#define MDM_RESETINITCFO__USE_TWOSAMPLES_TO_UPDT_RUNLEN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 13) & ~0x00002000U)))
#define MDM_RESETINITCFO__USE_TWOSAMPLES_TO_UPDT_RUNLEN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | ((uint32_t)(1) << 13)
#define MDM_RESETINITCFO__USE_TWOSAMPLES_TO_UPDT_RUNLEN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | ((uint32_t)(0) << 13)
#define MDM_RESETINITCFO__USE_TWOSAMPLES_TO_UPDT_RUNLEN__RESET_VALUE \
                    0x00000001U
/** @} */

/* macros for field reset_runlen_on_gainchg_pwrstep_only */
/**
 * @defgroup mdm_regs_core_reset_runlen_on_gainchg_pwrstep_only_field reset_runlen_on_gainchg_pwrstep_only_field
 * @brief macros for field reset_runlen_on_gainchg_pwrstep_only
 * @details When 1, don't reset run length counter if only run length triggered assert_reset_freq_sync
 * @{
 */
#define MDM_RESETINITCFO__RESET_RUNLEN_ON_GAINCHG_PWRSTEP_ONLY__SHIFT        14
#define MDM_RESETINITCFO__RESET_RUNLEN_ON_GAINCHG_PWRSTEP_ONLY__WIDTH         1
#define MDM_RESETINITCFO__RESET_RUNLEN_ON_GAINCHG_PWRSTEP_ONLY__MASK \
                    0x00004000U
#define MDM_RESETINITCFO__RESET_RUNLEN_ON_GAINCHG_PWRSTEP_ONLY__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00004000U) >> 14)
#define MDM_RESETINITCFO__RESET_RUNLEN_ON_GAINCHG_PWRSTEP_ONLY__WRITE(src) \
                    (((uint32_t)(src)\
                    << 14) & 0x00004000U)
#define MDM_RESETINITCFO__RESET_RUNLEN_ON_GAINCHG_PWRSTEP_ONLY__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | (((uint32_t)(src) <<\
                    14) & 0x00004000U)
#define MDM_RESETINITCFO__RESET_RUNLEN_ON_GAINCHG_PWRSTEP_ONLY__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 14) & ~0x00004000U)))
#define MDM_RESETINITCFO__RESET_RUNLEN_ON_GAINCHG_PWRSTEP_ONLY__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | ((uint32_t)(1) << 14)
#define MDM_RESETINITCFO__RESET_RUNLEN_ON_GAINCHG_PWRSTEP_ONLY__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | ((uint32_t)(0) << 14)
#define MDM_RESETINITCFO__RESET_RUNLEN_ON_GAINCHG_PWRSTEP_ONLY__RESET_VALUE \
                    0x00000001U
/** @} */

/* macros for field twomeg_en */
/**
 * @defgroup mdm_regs_core_twomeg_en_field twomeg_en_field
 * @brief macros for field twomeg_en
 * @details Enable for run-length based reset of one-shot CFO estimation, 2M version
 * @{
 */
#define MDM_RESETINITCFO__TWOMEG_EN__SHIFT                                   16
#define MDM_RESETINITCFO__TWOMEG_EN__WIDTH                                    1
#define MDM_RESETINITCFO__TWOMEG_EN__MASK                           0x00010000U
#define MDM_RESETINITCFO__TWOMEG_EN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00010000U) >> 16)
#define MDM_RESETINITCFO__TWOMEG_EN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x00010000U)
#define MDM_RESETINITCFO__TWOMEG_EN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | (((uint32_t)(src) <<\
                    16) & 0x00010000U)
#define MDM_RESETINITCFO__TWOMEG_EN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x00010000U)))
#define MDM_RESETINITCFO__TWOMEG_EN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | ((uint32_t)(1) << 16)
#define MDM_RESETINITCFO__TWOMEG_EN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | ((uint32_t)(0) << 16)
#define MDM_RESETINITCFO__TWOMEG_EN__RESET_VALUE                    0x00000000U
/** @} */

/* macros for field twomeg_runlen_updt_thr */
/**
 * @defgroup mdm_regs_core_twomeg_runlen_updt_thr_field twomeg_runlen_updt_thr_field
 * @brief macros for field twomeg_runlen_updt_thr
 * @details Threshold for abs(diff(MF out)) below which the run-length is incremented, 2M version
 * @{
 */
#define MDM_RESETINITCFO__TWOMEG_RUNLEN_UPDT_THR__SHIFT                      17
#define MDM_RESETINITCFO__TWOMEG_RUNLEN_UPDT_THR__WIDTH                       6
#define MDM_RESETINITCFO__TWOMEG_RUNLEN_UPDT_THR__MASK              0x007e0000U
#define MDM_RESETINITCFO__TWOMEG_RUNLEN_UPDT_THR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x007e0000U) >> 17)
#define MDM_RESETINITCFO__TWOMEG_RUNLEN_UPDT_THR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 17) & 0x007e0000U)
#define MDM_RESETINITCFO__TWOMEG_RUNLEN_UPDT_THR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x007e0000U) | (((uint32_t)(src) <<\
                    17) & 0x007e0000U)
#define MDM_RESETINITCFO__TWOMEG_RUNLEN_UPDT_THR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 17) & ~0x007e0000U)))
#define MDM_RESETINITCFO__TWOMEG_RUNLEN_UPDT_THR__RESET_VALUE       0x00000016U
/** @} */

/* macros for field twomeg_runlen_thr_to_reset_cfo */
/**
 * @defgroup mdm_regs_core_twomeg_runlen_thr_to_reset_cfo_field twomeg_runlen_thr_to_reset_cfo_field
 * @brief macros for field twomeg_runlen_thr_to_reset_cfo
 * @details Threshold for run-length above which assert_reset_freq_sync is asserted, 2M version
 * @{
 */
#define MDM_RESETINITCFO__TWOMEG_RUNLEN_THR_TO_RESET_CFO__SHIFT              23
#define MDM_RESETINITCFO__TWOMEG_RUNLEN_THR_TO_RESET_CFO__WIDTH               6
#define MDM_RESETINITCFO__TWOMEG_RUNLEN_THR_TO_RESET_CFO__MASK      0x1f800000U
#define MDM_RESETINITCFO__TWOMEG_RUNLEN_THR_TO_RESET_CFO__READ(src) \
                    (((uint32_t)(src)\
                    & 0x1f800000U) >> 23)
#define MDM_RESETINITCFO__TWOMEG_RUNLEN_THR_TO_RESET_CFO__WRITE(src) \
                    (((uint32_t)(src)\
                    << 23) & 0x1f800000U)
#define MDM_RESETINITCFO__TWOMEG_RUNLEN_THR_TO_RESET_CFO__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x1f800000U) | (((uint32_t)(src) <<\
                    23) & 0x1f800000U)
#define MDM_RESETINITCFO__TWOMEG_RUNLEN_THR_TO_RESET_CFO__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 23) & ~0x1f800000U)))
#define MDM_RESETINITCFO__TWOMEG_RUNLEN_THR_TO_RESET_CFO__RESET_VALUE \
                    0x0000000fU
/** @} */

/* macros for field twomeg_use_twosamples_to_updt_runlen */
/**
 * @defgroup mdm_regs_core_twomeg_use_twosamples_to_updt_runlen_field twomeg_use_twosamples_to_updt_runlen_field
 * @brief macros for field twomeg_use_twosamples_to_updt_runlen
 * @details When 1, use OR of two most recent abs(diff(MF out)). When 0, use just most recent, 2M version
 * @{
 */
#define MDM_RESETINITCFO__TWOMEG_USE_TWOSAMPLES_TO_UPDT_RUNLEN__SHIFT        29
#define MDM_RESETINITCFO__TWOMEG_USE_TWOSAMPLES_TO_UPDT_RUNLEN__WIDTH         1
#define MDM_RESETINITCFO__TWOMEG_USE_TWOSAMPLES_TO_UPDT_RUNLEN__MASK \
                    0x20000000U
#define MDM_RESETINITCFO__TWOMEG_USE_TWOSAMPLES_TO_UPDT_RUNLEN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x20000000U) >> 29)
#define MDM_RESETINITCFO__TWOMEG_USE_TWOSAMPLES_TO_UPDT_RUNLEN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 29) & 0x20000000U)
#define MDM_RESETINITCFO__TWOMEG_USE_TWOSAMPLES_TO_UPDT_RUNLEN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | (((uint32_t)(src) <<\
                    29) & 0x20000000U)
#define MDM_RESETINITCFO__TWOMEG_USE_TWOSAMPLES_TO_UPDT_RUNLEN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 29) & ~0x20000000U)))
#define MDM_RESETINITCFO__TWOMEG_USE_TWOSAMPLES_TO_UPDT_RUNLEN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | ((uint32_t)(1) << 29)
#define MDM_RESETINITCFO__TWOMEG_USE_TWOSAMPLES_TO_UPDT_RUNLEN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | ((uint32_t)(0) << 29)
#define MDM_RESETINITCFO__TWOMEG_USE_TWOSAMPLES_TO_UPDT_RUNLEN__RESET_VALUE \
                    0x00000001U
/** @} */

/* macros for field twomeg_reset_runlen_on_gainchg_pwrstep_only */
/**
 * @defgroup mdm_regs_core_twomeg_reset_runlen_on_gainchg_pwrstep_only_field twomeg_reset_runlen_on_gainchg_pwrstep_only_field
 * @brief macros for field twomeg_reset_runlen_on_gainchg_pwrstep_only
 * @details When 1, don't reset run length counter if only run length triggered assert_reset_freq_sync, 2M version
 * @{
 */
#define MDM_RESETINITCFO__TWOMEG_RESET_RUNLEN_ON_GAINCHG_PWRSTEP_ONLY__SHIFT 30
#define MDM_RESETINITCFO__TWOMEG_RESET_RUNLEN_ON_GAINCHG_PWRSTEP_ONLY__WIDTH  1
#define MDM_RESETINITCFO__TWOMEG_RESET_RUNLEN_ON_GAINCHG_PWRSTEP_ONLY__MASK \
                    0x40000000U
#define MDM_RESETINITCFO__TWOMEG_RESET_RUNLEN_ON_GAINCHG_PWRSTEP_ONLY__READ(src) \
                    (((uint32_t)(src)\
                    & 0x40000000U) >> 30)
#define MDM_RESETINITCFO__TWOMEG_RESET_RUNLEN_ON_GAINCHG_PWRSTEP_ONLY__WRITE(src) \
                    (((uint32_t)(src)\
                    << 30) & 0x40000000U)
#define MDM_RESETINITCFO__TWOMEG_RESET_RUNLEN_ON_GAINCHG_PWRSTEP_ONLY__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | (((uint32_t)(src) <<\
                    30) & 0x40000000U)
#define MDM_RESETINITCFO__TWOMEG_RESET_RUNLEN_ON_GAINCHG_PWRSTEP_ONLY__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 30) & ~0x40000000U)))
#define MDM_RESETINITCFO__TWOMEG_RESET_RUNLEN_ON_GAINCHG_PWRSTEP_ONLY__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(1) << 30)
#define MDM_RESETINITCFO__TWOMEG_RESET_RUNLEN_ON_GAINCHG_PWRSTEP_ONLY__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(0) << 30)
#define MDM_RESETINITCFO__TWOMEG_RESET_RUNLEN_ON_GAINCHG_PWRSTEP_ONLY__RESET_VALUE \
                    0x00000001U
/** @} */
#define MDM_RESETINITCFO__TYPE                                         uint32_t
#define MDM_RESETINITCFO__READ                                      0x7fff7fffU
#define MDM_RESETINITCFO__WRITE                                     0x7fff7fffU
#define MDM_RESETINITCFO__PRESERVED                                 0x00000000U
#define MDM_RESETINITCFO__RESET_VALUE                               0x67ac67acU

#endif /* __MDM_RESETINITCFO_MACRO__ */

/** @} end of resetinitcfo */

/* macros for BlueprintGlobalNameSpace::MDM_resetinitcfo_alt */
/**
 * @defgroup mdm_regs_core_resetinitcfo_alt resetinitcfo_alt
 * @brief Control for resetting initial CFO estimate, uncoded only, alternate set definitions.
 * @{
 */
#ifndef __MDM_RESETINITCFO_ALT_MACRO__
#define __MDM_RESETINITCFO_ALT_MACRO__

/* macros for field en */
/**
 * @defgroup mdm_regs_core_en_field en_field
 * @brief macros for field en
 * @details Enable for run-length based reset of one-shot CFO estimation
 * @{
 */
#define MDM_RESETINITCFO_ALT__EN__SHIFT                                       0
#define MDM_RESETINITCFO_ALT__EN__WIDTH                                       1
#define MDM_RESETINITCFO_ALT__EN__MASK                              0x00000001U
#define MDM_RESETINITCFO_ALT__EN__READ(src)     ((uint32_t)(src) & 0x00000001U)
#define MDM_RESETINITCFO_ALT__EN__WRITE(src)    ((uint32_t)(src) & 0x00000001U)
#define MDM_RESETINITCFO_ALT__EN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define MDM_RESETINITCFO_ALT__EN__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define MDM_RESETINITCFO_ALT__EN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define MDM_RESETINITCFO_ALT__EN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define MDM_RESETINITCFO_ALT__EN__RESET_VALUE                       0x00000001U
/** @} */

/* macros for field runlen_updt_thr */
/**
 * @defgroup mdm_regs_core_runlen_updt_thr_field runlen_updt_thr_field
 * @brief macros for field runlen_updt_thr
 * @details Threshold for abs(diff(MF out)) below which the run-length is incremented
 * @{
 */
#define MDM_RESETINITCFO_ALT__RUNLEN_UPDT_THR__SHIFT                          1
#define MDM_RESETINITCFO_ALT__RUNLEN_UPDT_THR__WIDTH                          6
#define MDM_RESETINITCFO_ALT__RUNLEN_UPDT_THR__MASK                 0x0000007eU
#define MDM_RESETINITCFO_ALT__RUNLEN_UPDT_THR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000007eU) >> 1)
#define MDM_RESETINITCFO_ALT__RUNLEN_UPDT_THR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x0000007eU)
#define MDM_RESETINITCFO_ALT__RUNLEN_UPDT_THR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000007eU) | (((uint32_t)(src) <<\
                    1) & 0x0000007eU)
#define MDM_RESETINITCFO_ALT__RUNLEN_UPDT_THR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x0000007eU)))
#define MDM_RESETINITCFO_ALT__RUNLEN_UPDT_THR__RESET_VALUE          0x00000016U
/** @} */

/* macros for field runlen_thr_to_reset_cfo */
/**
 * @defgroup mdm_regs_core_runlen_thr_to_reset_cfo_field runlen_thr_to_reset_cfo_field
 * @brief macros for field runlen_thr_to_reset_cfo
 * @details Threshold for run-length above which assert_reset_freq_sync is asserted
 * @{
 */
#define MDM_RESETINITCFO_ALT__RUNLEN_THR_TO_RESET_CFO__SHIFT                  7
#define MDM_RESETINITCFO_ALT__RUNLEN_THR_TO_RESET_CFO__WIDTH                  6
#define MDM_RESETINITCFO_ALT__RUNLEN_THR_TO_RESET_CFO__MASK         0x00001f80U
#define MDM_RESETINITCFO_ALT__RUNLEN_THR_TO_RESET_CFO__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00001f80U) >> 7)
#define MDM_RESETINITCFO_ALT__RUNLEN_THR_TO_RESET_CFO__WRITE(src) \
                    (((uint32_t)(src)\
                    << 7) & 0x00001f80U)
#define MDM_RESETINITCFO_ALT__RUNLEN_THR_TO_RESET_CFO__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00001f80U) | (((uint32_t)(src) <<\
                    7) & 0x00001f80U)
#define MDM_RESETINITCFO_ALT__RUNLEN_THR_TO_RESET_CFO__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 7) & ~0x00001f80U)))
#define MDM_RESETINITCFO_ALT__RUNLEN_THR_TO_RESET_CFO__RESET_VALUE  0x0000000fU
/** @} */

/* macros for field use_twosamples_to_updt_runlen */
/**
 * @defgroup mdm_regs_core_use_twosamples_to_updt_runlen_field use_twosamples_to_updt_runlen_field
 * @brief macros for field use_twosamples_to_updt_runlen
 * @details When 1, use OR of two most recent abs(diff(MF out)). When 0, use just most recent
 * @{
 */
#define MDM_RESETINITCFO_ALT__USE_TWOSAMPLES_TO_UPDT_RUNLEN__SHIFT           13
#define MDM_RESETINITCFO_ALT__USE_TWOSAMPLES_TO_UPDT_RUNLEN__WIDTH            1
#define MDM_RESETINITCFO_ALT__USE_TWOSAMPLES_TO_UPDT_RUNLEN__MASK   0x00002000U
#define MDM_RESETINITCFO_ALT__USE_TWOSAMPLES_TO_UPDT_RUNLEN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00002000U) >> 13)
#define MDM_RESETINITCFO_ALT__USE_TWOSAMPLES_TO_UPDT_RUNLEN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 13) & 0x00002000U)
#define MDM_RESETINITCFO_ALT__USE_TWOSAMPLES_TO_UPDT_RUNLEN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | (((uint32_t)(src) <<\
                    13) & 0x00002000U)
#define MDM_RESETINITCFO_ALT__USE_TWOSAMPLES_TO_UPDT_RUNLEN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 13) & ~0x00002000U)))
#define MDM_RESETINITCFO_ALT__USE_TWOSAMPLES_TO_UPDT_RUNLEN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | ((uint32_t)(1) << 13)
#define MDM_RESETINITCFO_ALT__USE_TWOSAMPLES_TO_UPDT_RUNLEN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | ((uint32_t)(0) << 13)
#define MDM_RESETINITCFO_ALT__USE_TWOSAMPLES_TO_UPDT_RUNLEN__RESET_VALUE \
                    0x00000001U
/** @} */

/* macros for field reset_runlen_on_gainchg_pwrstep_only */
/**
 * @defgroup mdm_regs_core_reset_runlen_on_gainchg_pwrstep_only_field reset_runlen_on_gainchg_pwrstep_only_field
 * @brief macros for field reset_runlen_on_gainchg_pwrstep_only
 * @details When 1, don't reset run length counter if only run length triggered assert_reset_freq_sync
 * @{
 */
#define MDM_RESETINITCFO_ALT__RESET_RUNLEN_ON_GAINCHG_PWRSTEP_ONLY__SHIFT    14
#define MDM_RESETINITCFO_ALT__RESET_RUNLEN_ON_GAINCHG_PWRSTEP_ONLY__WIDTH     1
#define MDM_RESETINITCFO_ALT__RESET_RUNLEN_ON_GAINCHG_PWRSTEP_ONLY__MASK \
                    0x00004000U
#define MDM_RESETINITCFO_ALT__RESET_RUNLEN_ON_GAINCHG_PWRSTEP_ONLY__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00004000U) >> 14)
#define MDM_RESETINITCFO_ALT__RESET_RUNLEN_ON_GAINCHG_PWRSTEP_ONLY__WRITE(src) \
                    (((uint32_t)(src)\
                    << 14) & 0x00004000U)
#define MDM_RESETINITCFO_ALT__RESET_RUNLEN_ON_GAINCHG_PWRSTEP_ONLY__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | (((uint32_t)(src) <<\
                    14) & 0x00004000U)
#define MDM_RESETINITCFO_ALT__RESET_RUNLEN_ON_GAINCHG_PWRSTEP_ONLY__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 14) & ~0x00004000U)))
#define MDM_RESETINITCFO_ALT__RESET_RUNLEN_ON_GAINCHG_PWRSTEP_ONLY__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | ((uint32_t)(1) << 14)
#define MDM_RESETINITCFO_ALT__RESET_RUNLEN_ON_GAINCHG_PWRSTEP_ONLY__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | ((uint32_t)(0) << 14)
#define MDM_RESETINITCFO_ALT__RESET_RUNLEN_ON_GAINCHG_PWRSTEP_ONLY__RESET_VALUE \
                    0x00000001U
/** @} */

/* macros for field twomeg_en */
/**
 * @defgroup mdm_regs_core_twomeg_en_field twomeg_en_field
 * @brief macros for field twomeg_en
 * @details Enable for run-length based reset of one-shot CFO estimation, 2M version
 * @{
 */
#define MDM_RESETINITCFO_ALT__TWOMEG_EN__SHIFT                               16
#define MDM_RESETINITCFO_ALT__TWOMEG_EN__WIDTH                                1
#define MDM_RESETINITCFO_ALT__TWOMEG_EN__MASK                       0x00010000U
#define MDM_RESETINITCFO_ALT__TWOMEG_EN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00010000U) >> 16)
#define MDM_RESETINITCFO_ALT__TWOMEG_EN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x00010000U)
#define MDM_RESETINITCFO_ALT__TWOMEG_EN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | (((uint32_t)(src) <<\
                    16) & 0x00010000U)
#define MDM_RESETINITCFO_ALT__TWOMEG_EN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x00010000U)))
#define MDM_RESETINITCFO_ALT__TWOMEG_EN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | ((uint32_t)(1) << 16)
#define MDM_RESETINITCFO_ALT__TWOMEG_EN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | ((uint32_t)(0) << 16)
#define MDM_RESETINITCFO_ALT__TWOMEG_EN__RESET_VALUE                0x00000001U
/** @} */

/* macros for field twomeg_runlen_updt_thr */
/**
 * @defgroup mdm_regs_core_twomeg_runlen_updt_thr_field twomeg_runlen_updt_thr_field
 * @brief macros for field twomeg_runlen_updt_thr
 * @details Threshold for abs(diff(MF out)) below which the run-length is incremented, 2M version
 * @{
 */
#define MDM_RESETINITCFO_ALT__TWOMEG_RUNLEN_UPDT_THR__SHIFT                  17
#define MDM_RESETINITCFO_ALT__TWOMEG_RUNLEN_UPDT_THR__WIDTH                   6
#define MDM_RESETINITCFO_ALT__TWOMEG_RUNLEN_UPDT_THR__MASK          0x007e0000U
#define MDM_RESETINITCFO_ALT__TWOMEG_RUNLEN_UPDT_THR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x007e0000U) >> 17)
#define MDM_RESETINITCFO_ALT__TWOMEG_RUNLEN_UPDT_THR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 17) & 0x007e0000U)
#define MDM_RESETINITCFO_ALT__TWOMEG_RUNLEN_UPDT_THR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x007e0000U) | (((uint32_t)(src) <<\
                    17) & 0x007e0000U)
#define MDM_RESETINITCFO_ALT__TWOMEG_RUNLEN_UPDT_THR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 17) & ~0x007e0000U)))
#define MDM_RESETINITCFO_ALT__TWOMEG_RUNLEN_UPDT_THR__RESET_VALUE   0x00000016U
/** @} */

/* macros for field twomeg_runlen_thr_to_reset_cfo */
/**
 * @defgroup mdm_regs_core_twomeg_runlen_thr_to_reset_cfo_field twomeg_runlen_thr_to_reset_cfo_field
 * @brief macros for field twomeg_runlen_thr_to_reset_cfo
 * @details Threshold for run-length above which assert_reset_freq_sync is asserted, 2M version
 * @{
 */
#define MDM_RESETINITCFO_ALT__TWOMEG_RUNLEN_THR_TO_RESET_CFO__SHIFT          23
#define MDM_RESETINITCFO_ALT__TWOMEG_RUNLEN_THR_TO_RESET_CFO__WIDTH           6
#define MDM_RESETINITCFO_ALT__TWOMEG_RUNLEN_THR_TO_RESET_CFO__MASK  0x1f800000U
#define MDM_RESETINITCFO_ALT__TWOMEG_RUNLEN_THR_TO_RESET_CFO__READ(src) \
                    (((uint32_t)(src)\
                    & 0x1f800000U) >> 23)
#define MDM_RESETINITCFO_ALT__TWOMEG_RUNLEN_THR_TO_RESET_CFO__WRITE(src) \
                    (((uint32_t)(src)\
                    << 23) & 0x1f800000U)
#define MDM_RESETINITCFO_ALT__TWOMEG_RUNLEN_THR_TO_RESET_CFO__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x1f800000U) | (((uint32_t)(src) <<\
                    23) & 0x1f800000U)
#define MDM_RESETINITCFO_ALT__TWOMEG_RUNLEN_THR_TO_RESET_CFO__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 23) & ~0x1f800000U)))
#define MDM_RESETINITCFO_ALT__TWOMEG_RUNLEN_THR_TO_RESET_CFO__RESET_VALUE \
                    0x0000000fU
/** @} */

/* macros for field twomeg_use_twosamples_to_updt_runlen */
/**
 * @defgroup mdm_regs_core_twomeg_use_twosamples_to_updt_runlen_field twomeg_use_twosamples_to_updt_runlen_field
 * @brief macros for field twomeg_use_twosamples_to_updt_runlen
 * @details When 1, use OR of two most recent abs(diff(MF out)). When 0, use just most recent, 2M version
 * @{
 */
#define MDM_RESETINITCFO_ALT__TWOMEG_USE_TWOSAMPLES_TO_UPDT_RUNLEN__SHIFT    29
#define MDM_RESETINITCFO_ALT__TWOMEG_USE_TWOSAMPLES_TO_UPDT_RUNLEN__WIDTH     1
#define MDM_RESETINITCFO_ALT__TWOMEG_USE_TWOSAMPLES_TO_UPDT_RUNLEN__MASK \
                    0x20000000U
#define MDM_RESETINITCFO_ALT__TWOMEG_USE_TWOSAMPLES_TO_UPDT_RUNLEN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x20000000U) >> 29)
#define MDM_RESETINITCFO_ALT__TWOMEG_USE_TWOSAMPLES_TO_UPDT_RUNLEN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 29) & 0x20000000U)
#define MDM_RESETINITCFO_ALT__TWOMEG_USE_TWOSAMPLES_TO_UPDT_RUNLEN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | (((uint32_t)(src) <<\
                    29) & 0x20000000U)
#define MDM_RESETINITCFO_ALT__TWOMEG_USE_TWOSAMPLES_TO_UPDT_RUNLEN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 29) & ~0x20000000U)))
#define MDM_RESETINITCFO_ALT__TWOMEG_USE_TWOSAMPLES_TO_UPDT_RUNLEN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | ((uint32_t)(1) << 29)
#define MDM_RESETINITCFO_ALT__TWOMEG_USE_TWOSAMPLES_TO_UPDT_RUNLEN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | ((uint32_t)(0) << 29)
#define MDM_RESETINITCFO_ALT__TWOMEG_USE_TWOSAMPLES_TO_UPDT_RUNLEN__RESET_VALUE \
                    0x00000001U
/** @} */

/* macros for field twomeg_reset_runlen_on_gainchg_pwrstep_only */
/**
 * @defgroup mdm_regs_core_twomeg_reset_runlen_on_gainchg_pwrstep_only_field twomeg_reset_runlen_on_gainchg_pwrstep_only_field
 * @brief macros for field twomeg_reset_runlen_on_gainchg_pwrstep_only
 * @details When 1, don't reset run length counter if only run length triggered assert_reset_freq_sync, 2M version
 * @{
 */
#define MDM_RESETINITCFO_ALT__TWOMEG_RESET_RUNLEN_ON_GAINCHG_PWRSTEP_ONLY__SHIFT \
                    30
#define MDM_RESETINITCFO_ALT__TWOMEG_RESET_RUNLEN_ON_GAINCHG_PWRSTEP_ONLY__WIDTH \
                    1
#define MDM_RESETINITCFO_ALT__TWOMEG_RESET_RUNLEN_ON_GAINCHG_PWRSTEP_ONLY__MASK \
                    0x40000000U
#define MDM_RESETINITCFO_ALT__TWOMEG_RESET_RUNLEN_ON_GAINCHG_PWRSTEP_ONLY__READ(src) \
                    (((uint32_t)(src)\
                    & 0x40000000U) >> 30)
#define MDM_RESETINITCFO_ALT__TWOMEG_RESET_RUNLEN_ON_GAINCHG_PWRSTEP_ONLY__WRITE(src) \
                    (((uint32_t)(src)\
                    << 30) & 0x40000000U)
#define MDM_RESETINITCFO_ALT__TWOMEG_RESET_RUNLEN_ON_GAINCHG_PWRSTEP_ONLY__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | (((uint32_t)(src) <<\
                    30) & 0x40000000U)
#define MDM_RESETINITCFO_ALT__TWOMEG_RESET_RUNLEN_ON_GAINCHG_PWRSTEP_ONLY__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 30) & ~0x40000000U)))
#define MDM_RESETINITCFO_ALT__TWOMEG_RESET_RUNLEN_ON_GAINCHG_PWRSTEP_ONLY__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(1) << 30)
#define MDM_RESETINITCFO_ALT__TWOMEG_RESET_RUNLEN_ON_GAINCHG_PWRSTEP_ONLY__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(0) << 30)
#define MDM_RESETINITCFO_ALT__TWOMEG_RESET_RUNLEN_ON_GAINCHG_PWRSTEP_ONLY__RESET_VALUE \
                    0x00000001U
/** @} */
#define MDM_RESETINITCFO_ALT__TYPE                                     uint32_t
#define MDM_RESETINITCFO_ALT__READ                                  0x7fff7fffU
#define MDM_RESETINITCFO_ALT__WRITE                                 0x7fff7fffU
#define MDM_RESETINITCFO_ALT__PRESERVED                             0x00000000U
#define MDM_RESETINITCFO_ALT__RESET_VALUE                           0x67ad67adU

#endif /* __MDM_RESETINITCFO_ALT_MACRO__ */

/** @} end of resetinitcfo_alt */

/* macros for BlueprintGlobalNameSpace::MDM_intmfreq */
/**
 * @defgroup mdm_regs_core_intmfreq intmfreq
 * @brief Intermediate frequency tracking control, uncoded only, between initial estimate and AA found definitions.
 * @{
 */
#ifndef __MDM_INTMFREQ_MACRO__
#define __MDM_INTMFREQ_MACRO__

/* macros for field enable_intmfreq */
/**
 * @defgroup mdm_regs_core_enable_intmfreq_field enable_intmfreq_field
 * @brief macros for field enable_intmfreq
 * @details Enable for 1 Mb
 * @{
 */
#define MDM_INTMFREQ__ENABLE_INTMFREQ__SHIFT                                  0
#define MDM_INTMFREQ__ENABLE_INTMFREQ__WIDTH                                  1
#define MDM_INTMFREQ__ENABLE_INTMFREQ__MASK                         0x00000001U
#define MDM_INTMFREQ__ENABLE_INTMFREQ__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define MDM_INTMFREQ__ENABLE_INTMFREQ__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define MDM_INTMFREQ__ENABLE_INTMFREQ__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define MDM_INTMFREQ__ENABLE_INTMFREQ__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define MDM_INTMFREQ__ENABLE_INTMFREQ__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define MDM_INTMFREQ__ENABLE_INTMFREQ__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define MDM_INTMFREQ__ENABLE_INTMFREQ__RESET_VALUE                  0x00000001U
/** @} */

/* macros for field twomeg_enable_intmfreq */
/**
 * @defgroup mdm_regs_core_twomeg_enable_intmfreq_field twomeg_enable_intmfreq_field
 * @brief macros for field twomeg_enable_intmfreq
 * @details Enable for 2 Mb
 * @{
 */
#define MDM_INTMFREQ__TWOMEG_ENABLE_INTMFREQ__SHIFT                           1
#define MDM_INTMFREQ__TWOMEG_ENABLE_INTMFREQ__WIDTH                           1
#define MDM_INTMFREQ__TWOMEG_ENABLE_INTMFREQ__MASK                  0x00000002U
#define MDM_INTMFREQ__TWOMEG_ENABLE_INTMFREQ__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define MDM_INTMFREQ__TWOMEG_ENABLE_INTMFREQ__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define MDM_INTMFREQ__TWOMEG_ENABLE_INTMFREQ__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define MDM_INTMFREQ__TWOMEG_ENABLE_INTMFREQ__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define MDM_INTMFREQ__TWOMEG_ENABLE_INTMFREQ__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define MDM_INTMFREQ__TWOMEG_ENABLE_INTMFREQ__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define MDM_INTMFREQ__TWOMEG_ENABLE_INTMFREQ__RESET_VALUE           0x00000001U
/** @} */

/* macros for field alpha1 */
/**
 * @defgroup mdm_regs_core_alpha1_field alpha1_field
 * @brief macros for field alpha1
 * @details First gear
 * @{
 */
#define MDM_INTMFREQ__ALPHA1__SHIFT                                           2
#define MDM_INTMFREQ__ALPHA1__WIDTH                                           4
#define MDM_INTMFREQ__ALPHA1__MASK                                  0x0000003cU
#define MDM_INTMFREQ__ALPHA1__READ(src)  (((uint32_t)(src) & 0x0000003cU) >> 2)
#define MDM_INTMFREQ__ALPHA1__WRITE(src) (((uint32_t)(src) << 2) & 0x0000003cU)
#define MDM_INTMFREQ__ALPHA1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000003cU) | (((uint32_t)(src) <<\
                    2) & 0x0000003cU)
#define MDM_INTMFREQ__ALPHA1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x0000003cU)))
#define MDM_INTMFREQ__ALPHA1__RESET_VALUE                           0x00000007U
/** @} */

/* macros for field alpha2 */
/**
 * @defgroup mdm_regs_core_alpha2_field alpha2_field
 * @brief macros for field alpha2
 * @details Second gear
 * @{
 */
#define MDM_INTMFREQ__ALPHA2__SHIFT                                           6
#define MDM_INTMFREQ__ALPHA2__WIDTH                                           4
#define MDM_INTMFREQ__ALPHA2__MASK                                  0x000003c0U
#define MDM_INTMFREQ__ALPHA2__READ(src)  (((uint32_t)(src) & 0x000003c0U) >> 6)
#define MDM_INTMFREQ__ALPHA2__WRITE(src) (((uint32_t)(src) << 6) & 0x000003c0U)
#define MDM_INTMFREQ__ALPHA2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000003c0U) | (((uint32_t)(src) <<\
                    6) & 0x000003c0U)
#define MDM_INTMFREQ__ALPHA2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 6) & ~0x000003c0U)))
#define MDM_INTMFREQ__ALPHA2__RESET_VALUE                           0x00000008U
/** @} */

/* macros for field alpha3 */
/**
 * @defgroup mdm_regs_core_alpha3_field alpha3_field
 * @brief macros for field alpha3
 * @details Third gear
 * @{
 */
#define MDM_INTMFREQ__ALPHA3__SHIFT                                          10
#define MDM_INTMFREQ__ALPHA3__WIDTH                                           4
#define MDM_INTMFREQ__ALPHA3__MASK                                  0x00003c00U
#define MDM_INTMFREQ__ALPHA3__READ(src) (((uint32_t)(src) & 0x00003c00U) >> 10)
#define MDM_INTMFREQ__ALPHA3__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x00003c00U)
#define MDM_INTMFREQ__ALPHA3__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00003c00U) | (((uint32_t)(src) <<\
                    10) & 0x00003c00U)
#define MDM_INTMFREQ__ALPHA3__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x00003c00U)))
#define MDM_INTMFREQ__ALPHA3__RESET_VALUE                           0x00000009U
/** @} */

/* macros for field alpha_count1 */
/**
 * @defgroup mdm_regs_core_alpha_count1_field alpha_count1_field
 * @brief macros for field alpha_count1
 * @details alpha_count1 * 8 = number of phase differences before switching from first to second gear
 * @{
 */
#define MDM_INTMFREQ__ALPHA_COUNT1__SHIFT                                    14
#define MDM_INTMFREQ__ALPHA_COUNT1__WIDTH                                     6
#define MDM_INTMFREQ__ALPHA_COUNT1__MASK                            0x000fc000U
#define MDM_INTMFREQ__ALPHA_COUNT1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000fc000U) >> 14)
#define MDM_INTMFREQ__ALPHA_COUNT1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 14) & 0x000fc000U)
#define MDM_INTMFREQ__ALPHA_COUNT1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000fc000U) | (((uint32_t)(src) <<\
                    14) & 0x000fc000U)
#define MDM_INTMFREQ__ALPHA_COUNT1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 14) & ~0x000fc000U)))
#define MDM_INTMFREQ__ALPHA_COUNT1__RESET_VALUE                     0x00000004U
/** @} */

/* macros for field alpha_count2 */
/**
 * @defgroup mdm_regs_core_alpha_count2_field alpha_count2_field
 * @brief macros for field alpha_count2
 * @details alpha_count2 * 8 = number of phase differences before switching from second to third gear. Includes first gear as well
 * @{
 */
#define MDM_INTMFREQ__ALPHA_COUNT2__SHIFT                                    20
#define MDM_INTMFREQ__ALPHA_COUNT2__WIDTH                                     6
#define MDM_INTMFREQ__ALPHA_COUNT2__MASK                            0x03f00000U
#define MDM_INTMFREQ__ALPHA_COUNT2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x03f00000U) >> 20)
#define MDM_INTMFREQ__ALPHA_COUNT2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 20) & 0x03f00000U)
#define MDM_INTMFREQ__ALPHA_COUNT2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x03f00000U) | (((uint32_t)(src) <<\
                    20) & 0x03f00000U)
#define MDM_INTMFREQ__ALPHA_COUNT2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x03f00000U)))
#define MDM_INTMFREQ__ALPHA_COUNT2__RESET_VALUE                     0x00000008U
/** @} */
#define MDM_INTMFREQ__TYPE                                             uint32_t
#define MDM_INTMFREQ__READ                                          0x03ffffffU
#define MDM_INTMFREQ__WRITE                                         0x03ffffffU
#define MDM_INTMFREQ__PRESERVED                                     0x00000000U
#define MDM_INTMFREQ__RESET_VALUE                                   0x0081261fU

#endif /* __MDM_INTMFREQ_MACRO__ */

/** @} end of intmfreq */

/* macros for BlueprintGlobalNameSpace::MDM_intmfreq_alt */
/**
 * @defgroup mdm_regs_core_intmfreq_alt intmfreq_alt
 * @brief Intermediate frequency tracking control, uncoded only, between initial estimate and AA found, alternate set definitions.
 * @{
 */
#ifndef __MDM_INTMFREQ_ALT_MACRO__
#define __MDM_INTMFREQ_ALT_MACRO__

/* macros for field enable_intmfreq */
/**
 * @defgroup mdm_regs_core_enable_intmfreq_field enable_intmfreq_field
 * @brief macros for field enable_intmfreq
 * @details Enable for 1 Mb
 * @{
 */
#define MDM_INTMFREQ_ALT__ENABLE_INTMFREQ__SHIFT                              0
#define MDM_INTMFREQ_ALT__ENABLE_INTMFREQ__WIDTH                              1
#define MDM_INTMFREQ_ALT__ENABLE_INTMFREQ__MASK                     0x00000001U
#define MDM_INTMFREQ_ALT__ENABLE_INTMFREQ__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define MDM_INTMFREQ_ALT__ENABLE_INTMFREQ__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define MDM_INTMFREQ_ALT__ENABLE_INTMFREQ__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define MDM_INTMFREQ_ALT__ENABLE_INTMFREQ__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define MDM_INTMFREQ_ALT__ENABLE_INTMFREQ__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define MDM_INTMFREQ_ALT__ENABLE_INTMFREQ__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define MDM_INTMFREQ_ALT__ENABLE_INTMFREQ__RESET_VALUE              0x00000001U
/** @} */

/* macros for field twomeg_enable_intmfreq */
/**
 * @defgroup mdm_regs_core_twomeg_enable_intmfreq_field twomeg_enable_intmfreq_field
 * @brief macros for field twomeg_enable_intmfreq
 * @details Enable for 2 Mb
 * @{
 */
#define MDM_INTMFREQ_ALT__TWOMEG_ENABLE_INTMFREQ__SHIFT                       1
#define MDM_INTMFREQ_ALT__TWOMEG_ENABLE_INTMFREQ__WIDTH                       1
#define MDM_INTMFREQ_ALT__TWOMEG_ENABLE_INTMFREQ__MASK              0x00000002U
#define MDM_INTMFREQ_ALT__TWOMEG_ENABLE_INTMFREQ__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define MDM_INTMFREQ_ALT__TWOMEG_ENABLE_INTMFREQ__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define MDM_INTMFREQ_ALT__TWOMEG_ENABLE_INTMFREQ__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define MDM_INTMFREQ_ALT__TWOMEG_ENABLE_INTMFREQ__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define MDM_INTMFREQ_ALT__TWOMEG_ENABLE_INTMFREQ__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define MDM_INTMFREQ_ALT__TWOMEG_ENABLE_INTMFREQ__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define MDM_INTMFREQ_ALT__TWOMEG_ENABLE_INTMFREQ__RESET_VALUE       0x00000001U
/** @} */

/* macros for field alpha1 */
/**
 * @defgroup mdm_regs_core_alpha1_field alpha1_field
 * @brief macros for field alpha1
 * @details First gear
 * @{
 */
#define MDM_INTMFREQ_ALT__ALPHA1__SHIFT                                       2
#define MDM_INTMFREQ_ALT__ALPHA1__WIDTH                                       4
#define MDM_INTMFREQ_ALT__ALPHA1__MASK                              0x0000003cU
#define MDM_INTMFREQ_ALT__ALPHA1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000003cU) >> 2)
#define MDM_INTMFREQ_ALT__ALPHA1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x0000003cU)
#define MDM_INTMFREQ_ALT__ALPHA1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000003cU) | (((uint32_t)(src) <<\
                    2) & 0x0000003cU)
#define MDM_INTMFREQ_ALT__ALPHA1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x0000003cU)))
#define MDM_INTMFREQ_ALT__ALPHA1__RESET_VALUE                       0x00000007U
/** @} */

/* macros for field alpha2 */
/**
 * @defgroup mdm_regs_core_alpha2_field alpha2_field
 * @brief macros for field alpha2
 * @details Second gear
 * @{
 */
#define MDM_INTMFREQ_ALT__ALPHA2__SHIFT                                       6
#define MDM_INTMFREQ_ALT__ALPHA2__WIDTH                                       4
#define MDM_INTMFREQ_ALT__ALPHA2__MASK                              0x000003c0U
#define MDM_INTMFREQ_ALT__ALPHA2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000003c0U) >> 6)
#define MDM_INTMFREQ_ALT__ALPHA2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 6) & 0x000003c0U)
#define MDM_INTMFREQ_ALT__ALPHA2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000003c0U) | (((uint32_t)(src) <<\
                    6) & 0x000003c0U)
#define MDM_INTMFREQ_ALT__ALPHA2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 6) & ~0x000003c0U)))
#define MDM_INTMFREQ_ALT__ALPHA2__RESET_VALUE                       0x00000008U
/** @} */

/* macros for field alpha3 */
/**
 * @defgroup mdm_regs_core_alpha3_field alpha3_field
 * @brief macros for field alpha3
 * @details Third gear
 * @{
 */
#define MDM_INTMFREQ_ALT__ALPHA3__SHIFT                                      10
#define MDM_INTMFREQ_ALT__ALPHA3__WIDTH                                       4
#define MDM_INTMFREQ_ALT__ALPHA3__MASK                              0x00003c00U
#define MDM_INTMFREQ_ALT__ALPHA3__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00003c00U) >> 10)
#define MDM_INTMFREQ_ALT__ALPHA3__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x00003c00U)
#define MDM_INTMFREQ_ALT__ALPHA3__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00003c00U) | (((uint32_t)(src) <<\
                    10) & 0x00003c00U)
#define MDM_INTMFREQ_ALT__ALPHA3__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x00003c00U)))
#define MDM_INTMFREQ_ALT__ALPHA3__RESET_VALUE                       0x00000009U
/** @} */

/* macros for field alpha_count1 */
/**
 * @defgroup mdm_regs_core_alpha_count1_field alpha_count1_field
 * @brief macros for field alpha_count1
 * @details alpha_count1 * 8 = number of phase differences before switching from first to second gear
 * @{
 */
#define MDM_INTMFREQ_ALT__ALPHA_COUNT1__SHIFT                                14
#define MDM_INTMFREQ_ALT__ALPHA_COUNT1__WIDTH                                 6
#define MDM_INTMFREQ_ALT__ALPHA_COUNT1__MASK                        0x000fc000U
#define MDM_INTMFREQ_ALT__ALPHA_COUNT1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000fc000U) >> 14)
#define MDM_INTMFREQ_ALT__ALPHA_COUNT1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 14) & 0x000fc000U)
#define MDM_INTMFREQ_ALT__ALPHA_COUNT1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000fc000U) | (((uint32_t)(src) <<\
                    14) & 0x000fc000U)
#define MDM_INTMFREQ_ALT__ALPHA_COUNT1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 14) & ~0x000fc000U)))
#define MDM_INTMFREQ_ALT__ALPHA_COUNT1__RESET_VALUE                 0x00000004U
/** @} */

/* macros for field alpha_count2 */
/**
 * @defgroup mdm_regs_core_alpha_count2_field alpha_count2_field
 * @brief macros for field alpha_count2
 * @details alpha_count2 * 8 = number of phase differences before switching from second to third gear. Includes first gear as well
 * @{
 */
#define MDM_INTMFREQ_ALT__ALPHA_COUNT2__SHIFT                                20
#define MDM_INTMFREQ_ALT__ALPHA_COUNT2__WIDTH                                 6
#define MDM_INTMFREQ_ALT__ALPHA_COUNT2__MASK                        0x03f00000U
#define MDM_INTMFREQ_ALT__ALPHA_COUNT2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x03f00000U) >> 20)
#define MDM_INTMFREQ_ALT__ALPHA_COUNT2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 20) & 0x03f00000U)
#define MDM_INTMFREQ_ALT__ALPHA_COUNT2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x03f00000U) | (((uint32_t)(src) <<\
                    20) & 0x03f00000U)
#define MDM_INTMFREQ_ALT__ALPHA_COUNT2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x03f00000U)))
#define MDM_INTMFREQ_ALT__ALPHA_COUNT2__RESET_VALUE                 0x00000008U
/** @} */
#define MDM_INTMFREQ_ALT__TYPE                                         uint32_t
#define MDM_INTMFREQ_ALT__READ                                      0x03ffffffU
#define MDM_INTMFREQ_ALT__WRITE                                     0x03ffffffU
#define MDM_INTMFREQ_ALT__PRESERVED                                 0x00000000U
#define MDM_INTMFREQ_ALT__RESET_VALUE                               0x0081261fU

#endif /* __MDM_INTMFREQ_ALT_MACRO__ */

/** @} end of intmfreq_alt */

/* macros for BlueprintGlobalNameSpace::MDM_tstimeout */
/**
 * @defgroup mdm_regs_core_tstimeout tstimeout
 * @brief Time sync timeout control definitions.
 * @{
 */
#ifndef __MDM_TSTIMEOUT_MACRO__
#define __MDM_TSTIMEOUT_MACRO__

/* macros for field coded_numsamples */
/**
 * @defgroup mdm_regs_core_coded_numsamples_field coded_numsamples_field
 * @brief macros for field coded_numsamples
 * @details Number of samples before declaring timeout, coded rates
 * @{
 */
#define MDM_TSTIMEOUT__CODED_NUMSAMPLES__SHIFT                                9
#define MDM_TSTIMEOUT__CODED_NUMSAMPLES__WIDTH                               10
#define MDM_TSTIMEOUT__CODED_NUMSAMPLES__MASK                       0x0007fe00U
#define MDM_TSTIMEOUT__CODED_NUMSAMPLES__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0007fe00U) >> 9)
#define MDM_TSTIMEOUT__CODED_NUMSAMPLES__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x0007fe00U)
#define MDM_TSTIMEOUT__CODED_NUMSAMPLES__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0007fe00U) | (((uint32_t)(src) <<\
                    9) & 0x0007fe00U)
#define MDM_TSTIMEOUT__CODED_NUMSAMPLES__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x0007fe00U)))
#define MDM_TSTIMEOUT__CODED_NUMSAMPLES__RESET_VALUE                0x00000190U
/** @} */

/* macros for field coded_en */
/**
 * @defgroup mdm_regs_core_coded_en_field coded_en_field
 * @brief macros for field coded_en
 * @details enable timesync timeout, coded rates
 * @{
 */
#define MDM_TSTIMEOUT__CODED_EN__SHIFT                                       30
#define MDM_TSTIMEOUT__CODED_EN__WIDTH                                        1
#define MDM_TSTIMEOUT__CODED_EN__MASK                               0x40000000U
#define MDM_TSTIMEOUT__CODED_EN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x40000000U) >> 30)
#define MDM_TSTIMEOUT__CODED_EN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 30) & 0x40000000U)
#define MDM_TSTIMEOUT__CODED_EN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | (((uint32_t)(src) <<\
                    30) & 0x40000000U)
#define MDM_TSTIMEOUT__CODED_EN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 30) & ~0x40000000U)))
#define MDM_TSTIMEOUT__CODED_EN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(1) << 30)
#define MDM_TSTIMEOUT__CODED_EN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(0) << 30)
#define MDM_TSTIMEOUT__CODED_EN__RESET_VALUE                        0x00000001U
/** @} */
#define MDM_TSTIMEOUT__TYPE                                            uint32_t
#define MDM_TSTIMEOUT__READ                                         0x4007fe00U
#define MDM_TSTIMEOUT__WRITE                                        0x4007fe00U
#define MDM_TSTIMEOUT__PRESERVED                                    0x00000000U
#define MDM_TSTIMEOUT__RESET_VALUE                                  0x40032000U

#endif /* __MDM_TSTIMEOUT_MACRO__ */

/** @} end of tstimeout */

/* macros for BlueprintGlobalNameSpace::MDM_demod */
/**
 * @defgroup mdm_regs_core_demod demod
 * @brief Various demodulation control definitions.
 * @{
 */
#ifndef __MDM_DEMOD_MACRO__
#define __MDM_DEMOD_MACRO__

/* macros for field enable_ffe */
/**
 * @defgroup mdm_regs_core_enable_ffe_field enable_ffe_field
 * @brief macros for field enable_ffe
 * @details For 1 and 2 Mb/s, enables ffe demod. Not used by coded rates
 * @{
 */
#define MDM_DEMOD__ENABLE_FFE__SHIFT                                          0
#define MDM_DEMOD__ENABLE_FFE__WIDTH                                          1
#define MDM_DEMOD__ENABLE_FFE__MASK                                 0x00000001U
#define MDM_DEMOD__ENABLE_FFE__READ(src)        ((uint32_t)(src) & 0x00000001U)
#define MDM_DEMOD__ENABLE_FFE__WRITE(src)       ((uint32_t)(src) & 0x00000001U)
#define MDM_DEMOD__ENABLE_FFE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define MDM_DEMOD__ENABLE_FFE__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define MDM_DEMOD__ENABLE_FFE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define MDM_DEMOD__ENABLE_FFE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define MDM_DEMOD__ENABLE_FFE__RESET_VALUE                          0x00000001U
/** @} */

/* macros for field uncoded_sat_phase_diff */
/**
 * @defgroup mdm_regs_core_uncoded_sat_phase_diff_field uncoded_sat_phase_diff_field
 * @brief macros for field uncoded_sat_phase_diff
 * @details Enable saturation of phase differences to range of +/- phase_diff_max. Uncoded rates
 * @{
 */
#define MDM_DEMOD__UNCODED_SAT_PHASE_DIFF__SHIFT                              9
#define MDM_DEMOD__UNCODED_SAT_PHASE_DIFF__WIDTH                              1
#define MDM_DEMOD__UNCODED_SAT_PHASE_DIFF__MASK                     0x00000200U
#define MDM_DEMOD__UNCODED_SAT_PHASE_DIFF__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000200U) >> 9)
#define MDM_DEMOD__UNCODED_SAT_PHASE_DIFF__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x00000200U)
#define MDM_DEMOD__UNCODED_SAT_PHASE_DIFF__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | (((uint32_t)(src) <<\
                    9) & 0x00000200U)
#define MDM_DEMOD__UNCODED_SAT_PHASE_DIFF__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x00000200U)))
#define MDM_DEMOD__UNCODED_SAT_PHASE_DIFF__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | ((uint32_t)(1) << 9)
#define MDM_DEMOD__UNCODED_SAT_PHASE_DIFF__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | ((uint32_t)(0) << 9)
#define MDM_DEMOD__UNCODED_SAT_PHASE_DIFF__RESET_VALUE              0x00000001U
/** @} */

/* macros for field uncoded_max_phase_diff */
/**
 * @defgroup mdm_regs_core_uncoded_max_phase_diff_field uncoded_max_phase_diff_field
 * @brief macros for field uncoded_max_phase_diff
 * @details Absolute value of maximum phase difference. Uncoded rates
 * @{
 */
#define MDM_DEMOD__UNCODED_MAX_PHASE_DIFF__SHIFT                             10
#define MDM_DEMOD__UNCODED_MAX_PHASE_DIFF__WIDTH                              6
#define MDM_DEMOD__UNCODED_MAX_PHASE_DIFF__MASK                     0x0000fc00U
#define MDM_DEMOD__UNCODED_MAX_PHASE_DIFF__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000fc00U) >> 10)
#define MDM_DEMOD__UNCODED_MAX_PHASE_DIFF__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x0000fc00U)
#define MDM_DEMOD__UNCODED_MAX_PHASE_DIFF__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000fc00U) | (((uint32_t)(src) <<\
                    10) & 0x0000fc00U)
#define MDM_DEMOD__UNCODED_MAX_PHASE_DIFF__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x0000fc00U)))
#define MDM_DEMOD__UNCODED_MAX_PHASE_DIFF__RESET_VALUE              0x00000030U
/** @} */

/* macros for field adjust_sat_for_freq_offset */
/**
 * @defgroup mdm_regs_core_adjust_sat_for_freq_offset_field adjust_sat_for_freq_offset_field
 * @brief macros for field adjust_sat_for_freq_offset
 * @details For each phase_diff sample, adjust saturation range based on current frequency offset estimate
 * @{
 */
#define MDM_DEMOD__ADJUST_SAT_FOR_FREQ_OFFSET__SHIFT                         16
#define MDM_DEMOD__ADJUST_SAT_FOR_FREQ_OFFSET__WIDTH                          1
#define MDM_DEMOD__ADJUST_SAT_FOR_FREQ_OFFSET__MASK                 0x00010000U
#define MDM_DEMOD__ADJUST_SAT_FOR_FREQ_OFFSET__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00010000U) >> 16)
#define MDM_DEMOD__ADJUST_SAT_FOR_FREQ_OFFSET__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x00010000U)
#define MDM_DEMOD__ADJUST_SAT_FOR_FREQ_OFFSET__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | (((uint32_t)(src) <<\
                    16) & 0x00010000U)
#define MDM_DEMOD__ADJUST_SAT_FOR_FREQ_OFFSET__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x00010000U)))
#define MDM_DEMOD__ADJUST_SAT_FOR_FREQ_OFFSET__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | ((uint32_t)(1) << 16)
#define MDM_DEMOD__ADJUST_SAT_FOR_FREQ_OFFSET__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | ((uint32_t)(0) << 16)
#define MDM_DEMOD__ADJUST_SAT_FOR_FREQ_OFFSET__RESET_VALUE          0x00000000U
/** @} */

/* macros for field coded_sat_phase_diff */
/**
 * @defgroup mdm_regs_core_coded_sat_phase_diff_field coded_sat_phase_diff_field
 * @brief macros for field coded_sat_phase_diff
 * @details Enable saturation of phase differences to range of +/- phase_diff_max. Coded rates
 * @{
 */
#define MDM_DEMOD__CODED_SAT_PHASE_DIFF__SHIFT                               25
#define MDM_DEMOD__CODED_SAT_PHASE_DIFF__WIDTH                                1
#define MDM_DEMOD__CODED_SAT_PHASE_DIFF__MASK                       0x02000000U
#define MDM_DEMOD__CODED_SAT_PHASE_DIFF__READ(src) \
                    (((uint32_t)(src)\
                    & 0x02000000U) >> 25)
#define MDM_DEMOD__CODED_SAT_PHASE_DIFF__WRITE(src) \
                    (((uint32_t)(src)\
                    << 25) & 0x02000000U)
#define MDM_DEMOD__CODED_SAT_PHASE_DIFF__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x02000000U) | (((uint32_t)(src) <<\
                    25) & 0x02000000U)
#define MDM_DEMOD__CODED_SAT_PHASE_DIFF__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 25) & ~0x02000000U)))
#define MDM_DEMOD__CODED_SAT_PHASE_DIFF__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x02000000U) | ((uint32_t)(1) << 25)
#define MDM_DEMOD__CODED_SAT_PHASE_DIFF__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x02000000U) | ((uint32_t)(0) << 25)
#define MDM_DEMOD__CODED_SAT_PHASE_DIFF__RESET_VALUE                0x00000001U
/** @} */

/* macros for field coded_max_phase_diff */
/**
 * @defgroup mdm_regs_core_coded_max_phase_diff_field coded_max_phase_diff_field
 * @brief macros for field coded_max_phase_diff
 * @details Absolute value of maximum phase difference. Coded rates
 * @{
 */
#define MDM_DEMOD__CODED_MAX_PHASE_DIFF__SHIFT                               26
#define MDM_DEMOD__CODED_MAX_PHASE_DIFF__WIDTH                                6
#define MDM_DEMOD__CODED_MAX_PHASE_DIFF__MASK                       0xfc000000U
#define MDM_DEMOD__CODED_MAX_PHASE_DIFF__READ(src) \
                    (((uint32_t)(src)\
                    & 0xfc000000U) >> 26)
#define MDM_DEMOD__CODED_MAX_PHASE_DIFF__WRITE(src) \
                    (((uint32_t)(src)\
                    << 26) & 0xfc000000U)
#define MDM_DEMOD__CODED_MAX_PHASE_DIFF__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xfc000000U) | (((uint32_t)(src) <<\
                    26) & 0xfc000000U)
#define MDM_DEMOD__CODED_MAX_PHASE_DIFF__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 26) & ~0xfc000000U)))
#define MDM_DEMOD__CODED_MAX_PHASE_DIFF__RESET_VALUE                0x00000030U
/** @} */
#define MDM_DEMOD__TYPE                                                uint32_t
#define MDM_DEMOD__READ                                             0xfe01fe01U
#define MDM_DEMOD__WRITE                                            0xfe01fe01U
#define MDM_DEMOD__PRESERVED                                        0x00000000U
#define MDM_DEMOD__RESET_VALUE                                      0xc200c201U

#endif /* __MDM_DEMOD_MACRO__ */

/** @} end of demod */

/* macros for BlueprintGlobalNameSpace::MDM_dfewithffe */
/**
 * @defgroup mdm_regs_core_dfewithffe dfewithffe
 * @brief DFE adjustments to make to demod_threshold when FFE is enabled (enable_ffe_demod set, and uncoded rate) definitions.
 * @{
 */
#ifndef __MDM_DFEWITHFFE_MACRO__
#define __MDM_DFEWITHFFE_MACRO__

/* macros for field adjust1 */
/**
 * @defgroup mdm_regs_core_adjust1_field adjust1_field
 * @brief macros for field adjust1
 * @details For immediately previous symbol. Signed
 * @{
 */
#define MDM_DFEWITHFFE__ADJUST1__SHIFT                                        0
#define MDM_DFEWITHFFE__ADJUST1__WIDTH                                        8
#define MDM_DFEWITHFFE__ADJUST1__MASK                               0x000000ffU
#define MDM_DFEWITHFFE__ADJUST1__READ(src)      ((uint32_t)(src) & 0x000000ffU)
#define MDM_DFEWITHFFE__ADJUST1__WRITE(src)     ((uint32_t)(src) & 0x000000ffU)
#define MDM_DFEWITHFFE__ADJUST1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000ffU) | ((uint32_t)(src) &\
                    0x000000ffU)
#define MDM_DFEWITHFFE__ADJUST1__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000000ffU)))
#define MDM_DFEWITHFFE__ADJUST1__RESET_VALUE                        0x00000041U
/** @} */

/* macros for field adjust2 */
/**
 * @defgroup mdm_regs_core_adjust2_field adjust2_field
 * @brief macros for field adjust2
 * @details Looking back two symbols. Signed
 * @{
 */
#define MDM_DFEWITHFFE__ADJUST2__SHIFT                                        8
#define MDM_DFEWITHFFE__ADJUST2__WIDTH                                        8
#define MDM_DFEWITHFFE__ADJUST2__MASK                               0x0000ff00U
#define MDM_DFEWITHFFE__ADJUST2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000ff00U) >> 8)
#define MDM_DFEWITHFFE__ADJUST2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x0000ff00U)
#define MDM_DFEWITHFFE__ADJUST2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000ff00U) | (((uint32_t)(src) <<\
                    8) & 0x0000ff00U)
#define MDM_DFEWITHFFE__ADJUST2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x0000ff00U)))
#define MDM_DFEWITHFFE__ADJUST2__RESET_VALUE                        0x00000020U
/** @} */

/* macros for field adjust3 */
/**
 * @defgroup mdm_regs_core_adjust3_field adjust3_field
 * @brief macros for field adjust3
 * @details Looking back three symbols. Signed
 * @{
 */
#define MDM_DFEWITHFFE__ADJUST3__SHIFT                                       16
#define MDM_DFEWITHFFE__ADJUST3__WIDTH                                        8
#define MDM_DFEWITHFFE__ADJUST3__MASK                               0x00ff0000U
#define MDM_DFEWITHFFE__ADJUST3__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00ff0000U) >> 16)
#define MDM_DFEWITHFFE__ADJUST3__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x00ff0000U)
#define MDM_DFEWITHFFE__ADJUST3__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00ff0000U) | (((uint32_t)(src) <<\
                    16) & 0x00ff0000U)
#define MDM_DFEWITHFFE__ADJUST3__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x00ff0000U)))
#define MDM_DFEWITHFFE__ADJUST3__RESET_VALUE                        0x00000005U
/** @} */
#define MDM_DFEWITHFFE__TYPE                                           uint32_t
#define MDM_DFEWITHFFE__READ                                        0x00ffffffU
#define MDM_DFEWITHFFE__WRITE                                       0x00ffffffU
#define MDM_DFEWITHFFE__PRESERVED                                   0x00000000U
#define MDM_DFEWITHFFE__RESET_VALUE                                 0x00052041U

#endif /* __MDM_DFEWITHFFE_MACRO__ */

/** @} end of dfewithffe */

/* macros for BlueprintGlobalNameSpace::MDM_dfewithoutffe */
/**
 * @defgroup mdm_regs_core_dfewithoutffe dfewithoutffe
 * @brief DFE adjustments to make to demod_threshold when FFE is not used (enable_ffe_demod clear, or coded rate) definitions.
 * @{
 */
#ifndef __MDM_DFEWITHOUTFFE_MACRO__
#define __MDM_DFEWITHOUTFFE_MACRO__

/* macros for field adjust1 */
/**
 * @defgroup mdm_regs_core_adjust1_field adjust1_field
 * @brief macros for field adjust1
 * @details For immediately previous symbol. Signed
 * @{
 */
#define MDM_DFEWITHOUTFFE__ADJUST1__SHIFT                                     0
#define MDM_DFEWITHOUTFFE__ADJUST1__WIDTH                                     8
#define MDM_DFEWITHOUTFFE__ADJUST1__MASK                            0x000000ffU
#define MDM_DFEWITHOUTFFE__ADJUST1__READ(src)   ((uint32_t)(src) & 0x000000ffU)
#define MDM_DFEWITHOUTFFE__ADJUST1__WRITE(src)  ((uint32_t)(src) & 0x000000ffU)
#define MDM_DFEWITHOUTFFE__ADJUST1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000ffU) | ((uint32_t)(src) &\
                    0x000000ffU)
#define MDM_DFEWITHOUTFFE__ADJUST1__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000000ffU)))
#define MDM_DFEWITHOUTFFE__ADJUST1__RESET_VALUE                     0x00000017U
/** @} */

/* macros for field adjust2 */
/**
 * @defgroup mdm_regs_core_adjust2_field adjust2_field
 * @brief macros for field adjust2
 * @details Looking back two symbols. Signed
 * @{
 */
#define MDM_DFEWITHOUTFFE__ADJUST2__SHIFT                                     8
#define MDM_DFEWITHOUTFFE__ADJUST2__WIDTH                                     8
#define MDM_DFEWITHOUTFFE__ADJUST2__MASK                            0x0000ff00U
#define MDM_DFEWITHOUTFFE__ADJUST2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000ff00U) >> 8)
#define MDM_DFEWITHOUTFFE__ADJUST2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x0000ff00U)
#define MDM_DFEWITHOUTFFE__ADJUST2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000ff00U) | (((uint32_t)(src) <<\
                    8) & 0x0000ff00U)
#define MDM_DFEWITHOUTFFE__ADJUST2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x0000ff00U)))
#define MDM_DFEWITHOUTFFE__ADJUST2__RESET_VALUE                     0x00000000U
/** @} */

/* macros for field adjust3 */
/**
 * @defgroup mdm_regs_core_adjust3_field adjust3_field
 * @brief macros for field adjust3
 * @details Looking back three symbols. Signed
 * @{
 */
#define MDM_DFEWITHOUTFFE__ADJUST3__SHIFT                                    16
#define MDM_DFEWITHOUTFFE__ADJUST3__WIDTH                                     8
#define MDM_DFEWITHOUTFFE__ADJUST3__MASK                            0x00ff0000U
#define MDM_DFEWITHOUTFFE__ADJUST3__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00ff0000U) >> 16)
#define MDM_DFEWITHOUTFFE__ADJUST3__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x00ff0000U)
#define MDM_DFEWITHOUTFFE__ADJUST3__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00ff0000U) | (((uint32_t)(src) <<\
                    16) & 0x00ff0000U)
#define MDM_DFEWITHOUTFFE__ADJUST3__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x00ff0000U)))
#define MDM_DFEWITHOUTFFE__ADJUST3__RESET_VALUE                     0x00000000U
/** @} */
#define MDM_DFEWITHOUTFFE__TYPE                                        uint32_t
#define MDM_DFEWITHOUTFFE__READ                                     0x00ffffffU
#define MDM_DFEWITHOUTFFE__WRITE                                    0x00ffffffU
#define MDM_DFEWITHOUTFFE__PRESERVED                                0x00000000U
#define MDM_DFEWITHOUTFFE__RESET_VALUE                              0x00000017U

#endif /* __MDM_DFEWITHOUTFFE_MACRO__ */

/** @} end of dfewithoutffe */

/* macros for BlueprintGlobalNameSpace::MDM_twomeg_dfewithffe */
/**
 * @defgroup mdm_regs_core_twomeg_dfewithffe twomeg_dfewithffe
 * @brief DFE adjustments to make to demod_threshold when FFE is enabled (enable_ffe_demod set, and uncoded rate) definitions.
 * @{
 */
#ifndef __MDM_TWOMEG_DFEWITHFFE_MACRO__
#define __MDM_TWOMEG_DFEWITHFFE_MACRO__

/* macros for field adjust1 */
/**
 * @defgroup mdm_regs_core_adjust1_field adjust1_field
 * @brief macros for field adjust1
 * @details For immediately previous symbol. Signed
 * @{
 */
#define MDM_TWOMEG_DFEWITHFFE__ADJUST1__SHIFT                                 0
#define MDM_TWOMEG_DFEWITHFFE__ADJUST1__WIDTH                                 8
#define MDM_TWOMEG_DFEWITHFFE__ADJUST1__MASK                        0x000000ffU
#define MDM_TWOMEG_DFEWITHFFE__ADJUST1__READ(src) \
                    ((uint32_t)(src)\
                    & 0x000000ffU)
#define MDM_TWOMEG_DFEWITHFFE__ADJUST1__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x000000ffU)
#define MDM_TWOMEG_DFEWITHFFE__ADJUST1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000ffU) | ((uint32_t)(src) &\
                    0x000000ffU)
#define MDM_TWOMEG_DFEWITHFFE__ADJUST1__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000000ffU)))
#define MDM_TWOMEG_DFEWITHFFE__ADJUST1__RESET_VALUE                 0x00000040U
/** @} */

/* macros for field adjust2 */
/**
 * @defgroup mdm_regs_core_adjust2_field adjust2_field
 * @brief macros for field adjust2
 * @details Looking back two symbols. Signed
 * @{
 */
#define MDM_TWOMEG_DFEWITHFFE__ADJUST2__SHIFT                                 8
#define MDM_TWOMEG_DFEWITHFFE__ADJUST2__WIDTH                                 8
#define MDM_TWOMEG_DFEWITHFFE__ADJUST2__MASK                        0x0000ff00U
#define MDM_TWOMEG_DFEWITHFFE__ADJUST2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000ff00U) >> 8)
#define MDM_TWOMEG_DFEWITHFFE__ADJUST2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x0000ff00U)
#define MDM_TWOMEG_DFEWITHFFE__ADJUST2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000ff00U) | (((uint32_t)(src) <<\
                    8) & 0x0000ff00U)
#define MDM_TWOMEG_DFEWITHFFE__ADJUST2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x0000ff00U)))
#define MDM_TWOMEG_DFEWITHFFE__ADJUST2__RESET_VALUE                 0x0000001eU
/** @} */

/* macros for field adjust3 */
/**
 * @defgroup mdm_regs_core_adjust3_field adjust3_field
 * @brief macros for field adjust3
 * @details Looking back three symbols. Signed
 * @{
 */
#define MDM_TWOMEG_DFEWITHFFE__ADJUST3__SHIFT                                16
#define MDM_TWOMEG_DFEWITHFFE__ADJUST3__WIDTH                                 8
#define MDM_TWOMEG_DFEWITHFFE__ADJUST3__MASK                        0x00ff0000U
#define MDM_TWOMEG_DFEWITHFFE__ADJUST3__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00ff0000U) >> 16)
#define MDM_TWOMEG_DFEWITHFFE__ADJUST3__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x00ff0000U)
#define MDM_TWOMEG_DFEWITHFFE__ADJUST3__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00ff0000U) | (((uint32_t)(src) <<\
                    16) & 0x00ff0000U)
#define MDM_TWOMEG_DFEWITHFFE__ADJUST3__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x00ff0000U)))
#define MDM_TWOMEG_DFEWITHFFE__ADJUST3__RESET_VALUE                 0x00000004U
/** @} */
#define MDM_TWOMEG_DFEWITHFFE__TYPE                                    uint32_t
#define MDM_TWOMEG_DFEWITHFFE__READ                                 0x00ffffffU
#define MDM_TWOMEG_DFEWITHFFE__WRITE                                0x00ffffffU
#define MDM_TWOMEG_DFEWITHFFE__PRESERVED                            0x00000000U
#define MDM_TWOMEG_DFEWITHFFE__RESET_VALUE                          0x00041e40U

#endif /* __MDM_TWOMEG_DFEWITHFFE_MACRO__ */

/** @} end of twomeg_dfewithffe */

/* macros for BlueprintGlobalNameSpace::MDM_twomeg_dfewithoutffe */
/**
 * @defgroup mdm_regs_core_twomeg_dfewithoutffe twomeg_dfewithoutffe
 * @brief DFE adjustments to make to demod_threshold when FFE is not used (enable_ffe_demod clear, or coded rate) definitions.
 * @{
 */
#ifndef __MDM_TWOMEG_DFEWITHOUTFFE_MACRO__
#define __MDM_TWOMEG_DFEWITHOUTFFE_MACRO__

/* macros for field adjust1 */
/**
 * @defgroup mdm_regs_core_adjust1_field adjust1_field
 * @brief macros for field adjust1
 * @details For immediately previous symbol. Signed
 * @{
 */
#define MDM_TWOMEG_DFEWITHOUTFFE__ADJUST1__SHIFT                              0
#define MDM_TWOMEG_DFEWITHOUTFFE__ADJUST1__WIDTH                              8
#define MDM_TWOMEG_DFEWITHOUTFFE__ADJUST1__MASK                     0x000000ffU
#define MDM_TWOMEG_DFEWITHOUTFFE__ADJUST1__READ(src) \
                    ((uint32_t)(src)\
                    & 0x000000ffU)
#define MDM_TWOMEG_DFEWITHOUTFFE__ADJUST1__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x000000ffU)
#define MDM_TWOMEG_DFEWITHOUTFFE__ADJUST1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000ffU) | ((uint32_t)(src) &\
                    0x000000ffU)
#define MDM_TWOMEG_DFEWITHOUTFFE__ADJUST1__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000000ffU)))
#define MDM_TWOMEG_DFEWITHOUTFFE__ADJUST1__RESET_VALUE              0x00000017U
/** @} */

/* macros for field adjust2 */
/**
 * @defgroup mdm_regs_core_adjust2_field adjust2_field
 * @brief macros for field adjust2
 * @details Looking back two symbols. Signed
 * @{
 */
#define MDM_TWOMEG_DFEWITHOUTFFE__ADJUST2__SHIFT                              8
#define MDM_TWOMEG_DFEWITHOUTFFE__ADJUST2__WIDTH                              8
#define MDM_TWOMEG_DFEWITHOUTFFE__ADJUST2__MASK                     0x0000ff00U
#define MDM_TWOMEG_DFEWITHOUTFFE__ADJUST2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000ff00U) >> 8)
#define MDM_TWOMEG_DFEWITHOUTFFE__ADJUST2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x0000ff00U)
#define MDM_TWOMEG_DFEWITHOUTFFE__ADJUST2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000ff00U) | (((uint32_t)(src) <<\
                    8) & 0x0000ff00U)
#define MDM_TWOMEG_DFEWITHOUTFFE__ADJUST2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x0000ff00U)))
#define MDM_TWOMEG_DFEWITHOUTFFE__ADJUST2__RESET_VALUE              0x00000000U
/** @} */

/* macros for field adjust3 */
/**
 * @defgroup mdm_regs_core_adjust3_field adjust3_field
 * @brief macros for field adjust3
 * @details Looking back three symbols. Signed
 * @{
 */
#define MDM_TWOMEG_DFEWITHOUTFFE__ADJUST3__SHIFT                             16
#define MDM_TWOMEG_DFEWITHOUTFFE__ADJUST3__WIDTH                              8
#define MDM_TWOMEG_DFEWITHOUTFFE__ADJUST3__MASK                     0x00ff0000U
#define MDM_TWOMEG_DFEWITHOUTFFE__ADJUST3__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00ff0000U) >> 16)
#define MDM_TWOMEG_DFEWITHOUTFFE__ADJUST3__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x00ff0000U)
#define MDM_TWOMEG_DFEWITHOUTFFE__ADJUST3__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00ff0000U) | (((uint32_t)(src) <<\
                    16) & 0x00ff0000U)
#define MDM_TWOMEG_DFEWITHOUTFFE__ADJUST3__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x00ff0000U)))
#define MDM_TWOMEG_DFEWITHOUTFFE__ADJUST3__RESET_VALUE              0x00000000U
/** @} */
#define MDM_TWOMEG_DFEWITHOUTFFE__TYPE                                 uint32_t
#define MDM_TWOMEG_DFEWITHOUTFFE__READ                              0x00ffffffU
#define MDM_TWOMEG_DFEWITHOUTFFE__WRITE                             0x00ffffffU
#define MDM_TWOMEG_DFEWITHOUTFFE__PRESERVED                         0x00000000U
#define MDM_TWOMEG_DFEWITHOUTFFE__RESET_VALUE                       0x00000017U

#endif /* __MDM_TWOMEG_DFEWITHOUTFFE_MACRO__ */

/** @} end of twomeg_dfewithoutffe */

/* macros for BlueprintGlobalNameSpace::MDM_freq */
/**
 * @defgroup mdm_regs_core_freq freq
 * @brief Frequency tracking control definitions.
 * @{
 */
#ifndef __MDM_FREQ_MACRO__
#define __MDM_FREQ_MACRO__

/* macros for field enable_track */
/**
 * @defgroup mdm_regs_core_enable_track_field enable_track_field
 * @brief macros for field enable_track
 * @details 1 is enable frequency tracking. 0 is just use initial estimate from preamble
 * @{
 */
#define MDM_FREQ__ENABLE_TRACK__SHIFT                                         0
#define MDM_FREQ__ENABLE_TRACK__WIDTH                                         1
#define MDM_FREQ__ENABLE_TRACK__MASK                                0x00000001U
#define MDM_FREQ__ENABLE_TRACK__READ(src)       ((uint32_t)(src) & 0x00000001U)
#define MDM_FREQ__ENABLE_TRACK__WRITE(src)      ((uint32_t)(src) & 0x00000001U)
#define MDM_FREQ__ENABLE_TRACK__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define MDM_FREQ__ENABLE_TRACK__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define MDM_FREQ__ENABLE_TRACK__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define MDM_FREQ__ENABLE_TRACK__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define MDM_FREQ__ENABLE_TRACK__RESET_VALUE                         0x00000001U
/** @} */

/* macros for field enable_same_pat */
/**
 * @defgroup mdm_regs_core_enable_same_pat_field enable_same_pat_field
 * @brief macros for field enable_same_pat
 * @details Perform tracking based on same 3-bit pattern in addition to flipped pattern
 * @{
 */
#define MDM_FREQ__ENABLE_SAME_PAT__SHIFT                                      1
#define MDM_FREQ__ENABLE_SAME_PAT__WIDTH                                      1
#define MDM_FREQ__ENABLE_SAME_PAT__MASK                             0x00000002U
#define MDM_FREQ__ENABLE_SAME_PAT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define MDM_FREQ__ENABLE_SAME_PAT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define MDM_FREQ__ENABLE_SAME_PAT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define MDM_FREQ__ENABLE_SAME_PAT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define MDM_FREQ__ENABLE_SAME_PAT__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define MDM_FREQ__ENABLE_SAME_PAT__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define MDM_FREQ__ENABLE_SAME_PAT__RESET_VALUE                      0x00000000U
/** @} */

/* macros for field mu1 */
/**
 * @defgroup mdm_regs_core_mu1_field mu1_field
 * @brief macros for field mu1
 * @details mu to use for first gear. Encoding: 2^(-(mu1+1))
 * @{
 */
#define MDM_FREQ__MU1__SHIFT                                                  2
#define MDM_FREQ__MU1__WIDTH                                                  3
#define MDM_FREQ__MU1__MASK                                         0x0000001cU
#define MDM_FREQ__MU1__READ(src)         (((uint32_t)(src) & 0x0000001cU) >> 2)
#define MDM_FREQ__MU1__WRITE(src)        (((uint32_t)(src) << 2) & 0x0000001cU)
#define MDM_FREQ__MU1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000001cU) | (((uint32_t)(src) <<\
                    2) & 0x0000001cU)
#define MDM_FREQ__MU1__VERIFY(src) (!((((uint32_t)(src) << 2) & ~0x0000001cU)))
#define MDM_FREQ__MU1__RESET_VALUE                                  0x00000003U
/** @} */

/* macros for field mu2 */
/**
 * @defgroup mdm_regs_core_mu2_field mu2_field
 * @brief macros for field mu2
 * @details mu to use for second gear. Encoding: 2^(-(mu2+1))
 * @{
 */
#define MDM_FREQ__MU2__SHIFT                                                  5
#define MDM_FREQ__MU2__WIDTH                                                  3
#define MDM_FREQ__MU2__MASK                                         0x000000e0U
#define MDM_FREQ__MU2__READ(src)         (((uint32_t)(src) & 0x000000e0U) >> 5)
#define MDM_FREQ__MU2__WRITE(src)        (((uint32_t)(src) << 5) & 0x000000e0U)
#define MDM_FREQ__MU2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000e0U) | (((uint32_t)(src) <<\
                    5) & 0x000000e0U)
#define MDM_FREQ__MU2__VERIFY(src) (!((((uint32_t)(src) << 5) & ~0x000000e0U)))
#define MDM_FREQ__MU2__RESET_VALUE                                  0x00000004U
/** @} */

/* macros for field mu3 */
/**
 * @defgroup mdm_regs_core_mu3_field mu3_field
 * @brief macros for field mu3
 * @details mu to use for third gear. Encoding: 2^(-(mu3+1))
 * @{
 */
#define MDM_FREQ__MU3__SHIFT                                                  8
#define MDM_FREQ__MU3__WIDTH                                                  3
#define MDM_FREQ__MU3__MASK                                         0x00000700U
#define MDM_FREQ__MU3__READ(src)         (((uint32_t)(src) & 0x00000700U) >> 8)
#define MDM_FREQ__MU3__WRITE(src)        (((uint32_t)(src) << 8) & 0x00000700U)
#define MDM_FREQ__MU3__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000700U) | (((uint32_t)(src) <<\
                    8) & 0x00000700U)
#define MDM_FREQ__MU3__VERIFY(src) (!((((uint32_t)(src) << 8) & ~0x00000700U)))
#define MDM_FREQ__MU3__RESET_VALUE                                  0x00000004U
/** @} */

/* macros for field pat_dly */
/**
 * @defgroup mdm_regs_core_pat_dly_field pat_dly_field
 * @brief macros for field pat_dly
 * @details determines number of symbols for when pattern matching times out. Encoding is 2^(pat_dly+2)
 * @{
 */
#define MDM_FREQ__PAT_DLY__SHIFT                                             11
#define MDM_FREQ__PAT_DLY__WIDTH                                              3
#define MDM_FREQ__PAT_DLY__MASK                                     0x00003800U
#define MDM_FREQ__PAT_DLY__READ(src)    (((uint32_t)(src) & 0x00003800U) >> 11)
#define MDM_FREQ__PAT_DLY__WRITE(src)   (((uint32_t)(src) << 11) & 0x00003800U)
#define MDM_FREQ__PAT_DLY__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00003800U) | (((uint32_t)(src) <<\
                    11) & 0x00003800U)
#define MDM_FREQ__PAT_DLY__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 11) & ~0x00003800U)))
#define MDM_FREQ__PAT_DLY__RESET_VALUE                              0x00000004U
/** @} */

/* macros for field mu_count1 */
/**
 * @defgroup mdm_regs_core_mu_count1_field mu_count1_field
 * @brief macros for field mu_count1
 * @details Number of bytes to process before switching from gear 1 to gear 2
 * @{
 */
#define MDM_FREQ__MU_COUNT1__SHIFT                                           14
#define MDM_FREQ__MU_COUNT1__WIDTH                                            8
#define MDM_FREQ__MU_COUNT1__MASK                                   0x003fc000U
#define MDM_FREQ__MU_COUNT1__READ(src)  (((uint32_t)(src) & 0x003fc000U) >> 14)
#define MDM_FREQ__MU_COUNT1__WRITE(src) (((uint32_t)(src) << 14) & 0x003fc000U)
#define MDM_FREQ__MU_COUNT1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x003fc000U) | (((uint32_t)(src) <<\
                    14) & 0x003fc000U)
#define MDM_FREQ__MU_COUNT1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 14) & ~0x003fc000U)))
#define MDM_FREQ__MU_COUNT1__RESET_VALUE                            0x00000004U
/** @} */

/* macros for field mu_count2 */
/**
 * @defgroup mdm_regs_core_mu_count2_field mu_count2_field
 * @brief macros for field mu_count2
 * @details Number of bytes to process before switching to gear 3. (Includes bytes from gear 1 PLUS gear 2)
 * @{
 */
#define MDM_FREQ__MU_COUNT2__SHIFT                                           22
#define MDM_FREQ__MU_COUNT2__WIDTH                                            8
#define MDM_FREQ__MU_COUNT2__MASK                                   0x3fc00000U
#define MDM_FREQ__MU_COUNT2__READ(src)  (((uint32_t)(src) & 0x3fc00000U) >> 22)
#define MDM_FREQ__MU_COUNT2__WRITE(src) (((uint32_t)(src) << 22) & 0x3fc00000U)
#define MDM_FREQ__MU_COUNT2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x3fc00000U) | (((uint32_t)(src) <<\
                    22) & 0x3fc00000U)
#define MDM_FREQ__MU_COUNT2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 22) & ~0x3fc00000U)))
#define MDM_FREQ__MU_COUNT2__RESET_VALUE                            0x00000010U
/** @} */
#define MDM_FREQ__TYPE                                                 uint32_t
#define MDM_FREQ__READ                                              0x3fffffffU
#define MDM_FREQ__WRITE                                             0x3fffffffU
#define MDM_FREQ__PRESERVED                                         0x00000000U
#define MDM_FREQ__RESET_VALUE                                       0x0401248dU

#endif /* __MDM_FREQ_MACRO__ */

/** @} end of freq */

/* macros for BlueprintGlobalNameSpace::MDM_freqlim */
/**
 * @defgroup mdm_regs_core_freqlim freqlim
 * @brief Specifies range of compensated soft demod values to be used for frequency tracking. Anything outside of this range is discarded. 0 to 512 is the full range of absolute values definitions.
 * @{
 */
#ifndef __MDM_FREQLIM_MACRO__
#define __MDM_FREQLIM_MACRO__

/* macros for field maxwithffe */
/**
 * @defgroup mdm_regs_core_maxwithffe_field maxwithffe_field
 * @brief macros for field maxwithffe
 * @details max absolute value to be used in tracking
 * @{
 */
#define MDM_FREQLIM__MAXWITHFFE__SHIFT                                        0
#define MDM_FREQLIM__MAXWITHFFE__WIDTH                                        9
#define MDM_FREQLIM__MAXWITHFFE__MASK                               0x000001ffU
#define MDM_FREQLIM__MAXWITHFFE__READ(src)      ((uint32_t)(src) & 0x000001ffU)
#define MDM_FREQLIM__MAXWITHFFE__WRITE(src)     ((uint32_t)(src) & 0x000001ffU)
#define MDM_FREQLIM__MAXWITHFFE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000001ffU) | ((uint32_t)(src) &\
                    0x000001ffU)
#define MDM_FREQLIM__MAXWITHFFE__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000001ffU)))
#define MDM_FREQLIM__MAXWITHFFE__RESET_VALUE                        0x000001ffU
/** @} */

/* macros for field minwithffe */
/**
 * @defgroup mdm_regs_core_minwithffe_field minwithffe_field
 * @brief macros for field minwithffe
 * @details min absolute value to be used in tracking
 * @{
 */
#define MDM_FREQLIM__MINWITHFFE__SHIFT                                        9
#define MDM_FREQLIM__MINWITHFFE__WIDTH                                        7
#define MDM_FREQLIM__MINWITHFFE__MASK                               0x0000fe00U
#define MDM_FREQLIM__MINWITHFFE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000fe00U) >> 9)
#define MDM_FREQLIM__MINWITHFFE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x0000fe00U)
#define MDM_FREQLIM__MINWITHFFE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000fe00U) | (((uint32_t)(src) <<\
                    9) & 0x0000fe00U)
#define MDM_FREQLIM__MINWITHFFE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x0000fe00U)))
#define MDM_FREQLIM__MINWITHFFE__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field maxwithoutffe */
/**
 * @defgroup mdm_regs_core_maxwithoutffe_field maxwithoutffe_field
 * @brief macros for field maxwithoutffe
 * @details max absolute value to be used in tracking
 * @{
 */
#define MDM_FREQLIM__MAXWITHOUTFFE__SHIFT                                    16
#define MDM_FREQLIM__MAXWITHOUTFFE__WIDTH                                     9
#define MDM_FREQLIM__MAXWITHOUTFFE__MASK                            0x01ff0000U
#define MDM_FREQLIM__MAXWITHOUTFFE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01ff0000U) >> 16)
#define MDM_FREQLIM__MAXWITHOUTFFE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x01ff0000U)
#define MDM_FREQLIM__MAXWITHOUTFFE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01ff0000U) | (((uint32_t)(src) <<\
                    16) & 0x01ff0000U)
#define MDM_FREQLIM__MAXWITHOUTFFE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x01ff0000U)))
#define MDM_FREQLIM__MAXWITHOUTFFE__RESET_VALUE                     0x000001ffU
/** @} */

/* macros for field minwithoutffe */
/**
 * @defgroup mdm_regs_core_minwithoutffe_field minwithoutffe_field
 * @brief macros for field minwithoutffe
 * @details min absolute value to be used in tracking
 * @{
 */
#define MDM_FREQLIM__MINWITHOUTFFE__SHIFT                                    25
#define MDM_FREQLIM__MINWITHOUTFFE__WIDTH                                     7
#define MDM_FREQLIM__MINWITHOUTFFE__MASK                            0xfe000000U
#define MDM_FREQLIM__MINWITHOUTFFE__READ(src) \
                    (((uint32_t)(src)\
                    & 0xfe000000U) >> 25)
#define MDM_FREQLIM__MINWITHOUTFFE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 25) & 0xfe000000U)
#define MDM_FREQLIM__MINWITHOUTFFE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xfe000000U) | (((uint32_t)(src) <<\
                    25) & 0xfe000000U)
#define MDM_FREQLIM__MINWITHOUTFFE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 25) & ~0xfe000000U)))
#define MDM_FREQLIM__MINWITHOUTFFE__RESET_VALUE                     0x00000000U
/** @} */
#define MDM_FREQLIM__TYPE                                              uint32_t
#define MDM_FREQLIM__READ                                           0xffffffffU
#define MDM_FREQLIM__WRITE                                          0xffffffffU
#define MDM_FREQLIM__PRESERVED                                      0x00000000U
#define MDM_FREQLIM__RESET_VALUE                                    0x01ff01ffU

#endif /* __MDM_FREQLIM_MACRO__ */

/** @} end of freqlim */

/* macros for BlueprintGlobalNameSpace::MDM_lr */
/**
 * @defgroup mdm_regs_core_lr lr
 * @brief Long-range specific control registers definitions.
 * @{
 */
#ifndef __MDM_LR_MACRO__
#define __MDM_LR_MACRO__

/* macros for field synch_detect_num_exp */
/**
 * @defgroup mdm_regs_core_synch_detect_num_exp_field synch_detect_num_exp_field
 * @brief macros for field synch_detect_num_exp
 * @details Number of frequency estimates for signal detection. Keep repeating measurement during detection. Encoding: 00 = 16 (10 symbols) 01 = 32 (12 symbols) 10 = 64 (16 symbols) 11 = 128 (24 symbols)
 * @{
 */
#define MDM_LR__SYNCH_DETECT_NUM_EXP__SHIFT                                   0
#define MDM_LR__SYNCH_DETECT_NUM_EXP__WIDTH                                   2
#define MDM_LR__SYNCH_DETECT_NUM_EXP__MASK                          0x00000003U
#define MDM_LR__SYNCH_DETECT_NUM_EXP__READ(src) ((uint32_t)(src) & 0x00000003U)
#define MDM_LR__SYNCH_DETECT_NUM_EXP__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000003U)
#define MDM_LR__SYNCH_DETECT_NUM_EXP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000003U) | ((uint32_t)(src) &\
                    0x00000003U)
#define MDM_LR__SYNCH_DETECT_NUM_EXP__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000003U)))
#define MDM_LR__SYNCH_DETECT_NUM_EXP__RESET_VALUE                   0x00000000U
/** @} */

/* macros for field synch_num_exp */
/**
 * @defgroup mdm_regs_core_synch_num_exp_field synch_num_exp_field
 * @brief macros for field synch_num_exp
 * @details Number of frequency estimates for demodulation and number of averages for timing sync. Encoding: 00 = NA 01 = freq: 32; timing averages (1x); (12 symbols) 10 = freq: 64; timing averages (2x); (16 symbols) 11 = freq: 128; timing averages (4x); (24 symbols)
 * @{
 */
#define MDM_LR__SYNCH_NUM_EXP__SHIFT                                          2
#define MDM_LR__SYNCH_NUM_EXP__WIDTH                                          2
#define MDM_LR__SYNCH_NUM_EXP__MASK                                 0x0000000cU
#define MDM_LR__SYNCH_NUM_EXP__READ(src) (((uint32_t)(src) & 0x0000000cU) >> 2)
#define MDM_LR__SYNCH_NUM_EXP__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x0000000cU)
#define MDM_LR__SYNCH_NUM_EXP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000000cU) | (((uint32_t)(src) <<\
                    2) & 0x0000000cU)
#define MDM_LR__SYNCH_NUM_EXP__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x0000000cU)))
#define MDM_LR__SYNCH_NUM_EXP__RESET_VALUE                          0x00000003U
/** @} */

/* macros for field num_corr_win */
/**
 * @defgroup mdm_regs_core_num_corr_win_field num_corr_win_field
 * @brief macros for field num_corr_win
 * @details Number of 4 us windows to include in correlation. Max is 10.
 * @{
 */
#define MDM_LR__NUM_CORR_WIN__SHIFT                                           4
#define MDM_LR__NUM_CORR_WIN__WIDTH                                           4
#define MDM_LR__NUM_CORR_WIN__MASK                                  0x000000f0U
#define MDM_LR__NUM_CORR_WIN__READ(src)  (((uint32_t)(src) & 0x000000f0U) >> 4)
#define MDM_LR__NUM_CORR_WIN__WRITE(src) (((uint32_t)(src) << 4) & 0x000000f0U)
#define MDM_LR__NUM_CORR_WIN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000f0U) | (((uint32_t)(src) <<\
                    4) & 0x000000f0U)
#define MDM_LR__NUM_CORR_WIN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x000000f0U)))
#define MDM_LR__NUM_CORR_WIN__RESET_VALUE                           0x00000009U
/** @} */

/* macros for field num_corr_avg */
/**
 * @defgroup mdm_regs_core_num_corr_avg_field num_corr_avg_field
 * @brief macros for field num_corr_avg
 * @details Number of phase differences to include in each 4 us (32 sample) window
 * @{
 */
#define MDM_LR__NUM_CORR_AVG__SHIFT                                           8
#define MDM_LR__NUM_CORR_AVG__WIDTH                                           5
#define MDM_LR__NUM_CORR_AVG__MASK                                  0x00001f00U
#define MDM_LR__NUM_CORR_AVG__READ(src)  (((uint32_t)(src) & 0x00001f00U) >> 8)
#define MDM_LR__NUM_CORR_AVG__WRITE(src) (((uint32_t)(src) << 8) & 0x00001f00U)
#define MDM_LR__NUM_CORR_AVG__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00001f00U) | (((uint32_t)(src) <<\
                    8) & 0x00001f00U)
#define MDM_LR__NUM_CORR_AVG__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00001f00U)))
#define MDM_LR__NUM_CORR_AVG__RESET_VALUE                           0x00000010U
/** @} */

/* macros for field corr_thresh_high */
/**
 * @defgroup mdm_regs_core_corr_thresh_high_field corr_thresh_high_field
 * @brief macros for field corr_thresh_high
 * @details Declare a detection if number of matches >= corr_thresh_high
 * @{
 */
#define MDM_LR__CORR_THRESH_HIGH__SHIFT                                      13
#define MDM_LR__CORR_THRESH_HIGH__WIDTH                                       9
#define MDM_LR__CORR_THRESH_HIGH__MASK                              0x003fe000U
#define MDM_LR__CORR_THRESH_HIGH__READ(src) \
                    (((uint32_t)(src)\
                    & 0x003fe000U) >> 13)
#define MDM_LR__CORR_THRESH_HIGH__WRITE(src) \
                    (((uint32_t)(src)\
                    << 13) & 0x003fe000U)
#define MDM_LR__CORR_THRESH_HIGH__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x003fe000U) | (((uint32_t)(src) <<\
                    13) & 0x003fe000U)
#define MDM_LR__CORR_THRESH_HIGH__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 13) & ~0x003fe000U)))
#define MDM_LR__CORR_THRESH_HIGH__RESET_VALUE                       0x00000088U
/** @} */

/* macros for field corr_thresh_low */
/**
 * @defgroup mdm_regs_core_corr_thresh_low_field corr_thresh_low_field
 * @brief macros for field corr_thresh_low
 * @details Declare a detection if number of matches <= corr_thresh_low. Would expect to set to num_corr_win*num_corr_avg - corr_thresh_low
 * @{
 */
#define MDM_LR__CORR_THRESH_LOW__SHIFT                                       22
#define MDM_LR__CORR_THRESH_LOW__WIDTH                                        8
#define MDM_LR__CORR_THRESH_LOW__MASK                               0x3fc00000U
#define MDM_LR__CORR_THRESH_LOW__READ(src) \
                    (((uint32_t)(src)\
                    & 0x3fc00000U) >> 22)
#define MDM_LR__CORR_THRESH_LOW__WRITE(src) \
                    (((uint32_t)(src)\
                    << 22) & 0x3fc00000U)
#define MDM_LR__CORR_THRESH_LOW__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x3fc00000U) | (((uint32_t)(src) <<\
                    22) & 0x3fc00000U)
#define MDM_LR__CORR_THRESH_LOW__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 22) & ~0x3fc00000U)))
#define MDM_LR__CORR_THRESH_LOW__RESET_VALUE                        0x00000008U
/** @} */
#define MDM_LR__TYPE                                                   uint32_t
#define MDM_LR__READ                                                0x3fffffffU
#define MDM_LR__WRITE                                               0x3fffffffU
#define MDM_LR__PRESERVED                                           0x00000000U
#define MDM_LR__RESET_VALUE                                         0x0211109cU

#endif /* __MDM_LR_MACRO__ */

/** @} end of lr */

/* macros for BlueprintGlobalNameSpace::MDM_lr_alt */
/**
 * @defgroup mdm_regs_core_lr_alt lr_alt
 * @brief Long-range specific control registers, alternate set definitions.
 * @{
 */
#ifndef __MDM_LR_ALT_MACRO__
#define __MDM_LR_ALT_MACRO__

/* macros for field synch_detect_num_exp */
/**
 * @defgroup mdm_regs_core_synch_detect_num_exp_field synch_detect_num_exp_field
 * @brief macros for field synch_detect_num_exp
 * @details Number of frequency estimates for signal detection. Keep repeating measurement during detection. Encoding: 00 = 16 (10 symbols) 01 = 32 (12 symbols) 10 = 64 (16 symbols) 11 = 128 (24 symbols)
 * @{
 */
#define MDM_LR_ALT__SYNCH_DETECT_NUM_EXP__SHIFT                               0
#define MDM_LR_ALT__SYNCH_DETECT_NUM_EXP__WIDTH                               2
#define MDM_LR_ALT__SYNCH_DETECT_NUM_EXP__MASK                      0x00000003U
#define MDM_LR_ALT__SYNCH_DETECT_NUM_EXP__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000003U)
#define MDM_LR_ALT__SYNCH_DETECT_NUM_EXP__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000003U)
#define MDM_LR_ALT__SYNCH_DETECT_NUM_EXP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000003U) | ((uint32_t)(src) &\
                    0x00000003U)
#define MDM_LR_ALT__SYNCH_DETECT_NUM_EXP__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000003U)))
#define MDM_LR_ALT__SYNCH_DETECT_NUM_EXP__RESET_VALUE               0x00000000U
/** @} */

/* macros for field synch_num_exp */
/**
 * @defgroup mdm_regs_core_synch_num_exp_field synch_num_exp_field
 * @brief macros for field synch_num_exp
 * @details Number of frequency estimates for demodulation and number of averages for timing sync. Encoding: 00 = NA 01 = freq: 32; timing averages (1x); (12 symbols) 10 = freq: 64; timing averages (2x); (16 symbols) 11 = freq: 128; timing averages (4x); (24 symbols)
 * @{
 */
#define MDM_LR_ALT__SYNCH_NUM_EXP__SHIFT                                      2
#define MDM_LR_ALT__SYNCH_NUM_EXP__WIDTH                                      2
#define MDM_LR_ALT__SYNCH_NUM_EXP__MASK                             0x0000000cU
#define MDM_LR_ALT__SYNCH_NUM_EXP__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000000cU) >> 2)
#define MDM_LR_ALT__SYNCH_NUM_EXP__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x0000000cU)
#define MDM_LR_ALT__SYNCH_NUM_EXP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000000cU) | (((uint32_t)(src) <<\
                    2) & 0x0000000cU)
#define MDM_LR_ALT__SYNCH_NUM_EXP__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x0000000cU)))
#define MDM_LR_ALT__SYNCH_NUM_EXP__RESET_VALUE                      0x00000003U
/** @} */

/* macros for field num_corr_win */
/**
 * @defgroup mdm_regs_core_num_corr_win_field num_corr_win_field
 * @brief macros for field num_corr_win
 * @details Number of 4 us windows to include in correlation. Max is 10.
 * @{
 */
#define MDM_LR_ALT__NUM_CORR_WIN__SHIFT                                       4
#define MDM_LR_ALT__NUM_CORR_WIN__WIDTH                                       4
#define MDM_LR_ALT__NUM_CORR_WIN__MASK                              0x000000f0U
#define MDM_LR_ALT__NUM_CORR_WIN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000000f0U) >> 4)
#define MDM_LR_ALT__NUM_CORR_WIN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x000000f0U)
#define MDM_LR_ALT__NUM_CORR_WIN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000f0U) | (((uint32_t)(src) <<\
                    4) & 0x000000f0U)
#define MDM_LR_ALT__NUM_CORR_WIN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x000000f0U)))
#define MDM_LR_ALT__NUM_CORR_WIN__RESET_VALUE                       0x00000009U
/** @} */

/* macros for field num_corr_avg */
/**
 * @defgroup mdm_regs_core_num_corr_avg_field num_corr_avg_field
 * @brief macros for field num_corr_avg
 * @details Number of phase differences to include in each 4 us (32 sample) window
 * @{
 */
#define MDM_LR_ALT__NUM_CORR_AVG__SHIFT                                       8
#define MDM_LR_ALT__NUM_CORR_AVG__WIDTH                                       5
#define MDM_LR_ALT__NUM_CORR_AVG__MASK                              0x00001f00U
#define MDM_LR_ALT__NUM_CORR_AVG__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00001f00U) >> 8)
#define MDM_LR_ALT__NUM_CORR_AVG__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00001f00U)
#define MDM_LR_ALT__NUM_CORR_AVG__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00001f00U) | (((uint32_t)(src) <<\
                    8) & 0x00001f00U)
#define MDM_LR_ALT__NUM_CORR_AVG__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00001f00U)))
#define MDM_LR_ALT__NUM_CORR_AVG__RESET_VALUE                       0x00000010U
/** @} */

/* macros for field corr_thresh_high */
/**
 * @defgroup mdm_regs_core_corr_thresh_high_field corr_thresh_high_field
 * @brief macros for field corr_thresh_high
 * @details Declare a detection if number of matches >= corr_thresh_high
 * @{
 */
#define MDM_LR_ALT__CORR_THRESH_HIGH__SHIFT                                  13
#define MDM_LR_ALT__CORR_THRESH_HIGH__WIDTH                                   9
#define MDM_LR_ALT__CORR_THRESH_HIGH__MASK                          0x003fe000U
#define MDM_LR_ALT__CORR_THRESH_HIGH__READ(src) \
                    (((uint32_t)(src)\
                    & 0x003fe000U) >> 13)
#define MDM_LR_ALT__CORR_THRESH_HIGH__WRITE(src) \
                    (((uint32_t)(src)\
                    << 13) & 0x003fe000U)
#define MDM_LR_ALT__CORR_THRESH_HIGH__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x003fe000U) | (((uint32_t)(src) <<\
                    13) & 0x003fe000U)
#define MDM_LR_ALT__CORR_THRESH_HIGH__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 13) & ~0x003fe000U)))
#define MDM_LR_ALT__CORR_THRESH_HIGH__RESET_VALUE                   0x00000088U
/** @} */

/* macros for field corr_thresh_low */
/**
 * @defgroup mdm_regs_core_corr_thresh_low_field corr_thresh_low_field
 * @brief macros for field corr_thresh_low
 * @details Declare a detection if number of matches <= corr_thresh_low. Would expect to set to num_corr_win*num_corr_avg - corr_thresh_low
 * @{
 */
#define MDM_LR_ALT__CORR_THRESH_LOW__SHIFT                                   22
#define MDM_LR_ALT__CORR_THRESH_LOW__WIDTH                                    8
#define MDM_LR_ALT__CORR_THRESH_LOW__MASK                           0x3fc00000U
#define MDM_LR_ALT__CORR_THRESH_LOW__READ(src) \
                    (((uint32_t)(src)\
                    & 0x3fc00000U) >> 22)
#define MDM_LR_ALT__CORR_THRESH_LOW__WRITE(src) \
                    (((uint32_t)(src)\
                    << 22) & 0x3fc00000U)
#define MDM_LR_ALT__CORR_THRESH_LOW__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x3fc00000U) | (((uint32_t)(src) <<\
                    22) & 0x3fc00000U)
#define MDM_LR_ALT__CORR_THRESH_LOW__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 22) & ~0x3fc00000U)))
#define MDM_LR_ALT__CORR_THRESH_LOW__RESET_VALUE                    0x00000008U
/** @} */
#define MDM_LR_ALT__TYPE                                               uint32_t
#define MDM_LR_ALT__READ                                            0x3fffffffU
#define MDM_LR_ALT__WRITE                                           0x3fffffffU
#define MDM_LR_ALT__PRESERVED                                       0x00000000U
#define MDM_LR_ALT__RESET_VALUE                                     0x0211109cU

#endif /* __MDM_LR_ALT_MACRO__ */

/** @} end of lr_alt */

/* macros for BlueprintGlobalNameSpace::MDM_mixer */
/**
 * @defgroup mdm_regs_core_mixer mixer
 * @brief Low IF frequency. definitions.
 * @{
 */
#ifndef __MDM_MIXER_MACRO__
#define __MDM_MIXER_MACRO__

/* macros for field low_if_freq */
/**
 * @defgroup mdm_regs_core_low_if_freq_field low_if_freq_field
 * @brief macros for field low_if_freq
 * @details Units are in 1/1024 MHz. 0.8 / (1/1024) = 819
 * @{
 */
#define MDM_MIXER__LOW_IF_FREQ__SHIFT                                         0
#define MDM_MIXER__LOW_IF_FREQ__WIDTH                                        14
#define MDM_MIXER__LOW_IF_FREQ__MASK                                0x00003fffU
#define MDM_MIXER__LOW_IF_FREQ__READ(src)       ((uint32_t)(src) & 0x00003fffU)
#define MDM_MIXER__LOW_IF_FREQ__WRITE(src)      ((uint32_t)(src) & 0x00003fffU)
#define MDM_MIXER__LOW_IF_FREQ__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00003fffU) | ((uint32_t)(src) &\
                    0x00003fffU)
#define MDM_MIXER__LOW_IF_FREQ__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00003fffU)))
#define MDM_MIXER__LOW_IF_FREQ__RESET_VALUE                         0x00000333U
/** @} */

/* macros for field twomeg_low_if_freq */
/**
 * @defgroup mdm_regs_core_twomeg_low_if_freq_field twomeg_low_if_freq_field
 * @brief macros for field twomeg_low_if_freq
 * @details Units are in 1/1024 MHz. 1.6 / (1/1024) = 1638
 * @{
 */
#define MDM_MIXER__TWOMEG_LOW_IF_FREQ__SHIFT                                 14
#define MDM_MIXER__TWOMEG_LOW_IF_FREQ__WIDTH                                 14
#define MDM_MIXER__TWOMEG_LOW_IF_FREQ__MASK                         0x0fffc000U
#define MDM_MIXER__TWOMEG_LOW_IF_FREQ__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0fffc000U) >> 14)
#define MDM_MIXER__TWOMEG_LOW_IF_FREQ__WRITE(src) \
                    (((uint32_t)(src)\
                    << 14) & 0x0fffc000U)
#define MDM_MIXER__TWOMEG_LOW_IF_FREQ__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0fffc000U) | (((uint32_t)(src) <<\
                    14) & 0x0fffc000U)
#define MDM_MIXER__TWOMEG_LOW_IF_FREQ__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 14) & ~0x0fffc000U)))
#define MDM_MIXER__TWOMEG_LOW_IF_FREQ__RESET_VALUE                  0x00000666U
/** @} */
#define MDM_MIXER__TYPE                                                uint32_t
#define MDM_MIXER__READ                                             0x0fffffffU
#define MDM_MIXER__WRITE                                            0x0fffffffU
#define MDM_MIXER__PRESERVED                                        0x00000000U
#define MDM_MIXER__RESET_VALUE                                      0x01998333U

#endif /* __MDM_MIXER_MACRO__ */

/** @} end of mixer */

/* macros for BlueprintGlobalNameSpace::MDM_access_address */
/**
 * @defgroup mdm_regs_core_access_address access_address
 * @brief Access address control definitions.
 * @{
 */
#ifndef __MDM_ACCESS_ADDRESS_MACRO__
#define __MDM_ACCESS_ADDRESS_MACRO__

/* macros for field match_thr */
/**
 * @defgroup mdm_regs_core_match_thr_field match_thr_field
 * @brief macros for field match_thr
 * @details Number of access address bits that need to match. 32 = all.
 * @{
 */
#define MDM_ACCESS_ADDRESS__MATCH_THR__SHIFT                                  0
#define MDM_ACCESS_ADDRESS__MATCH_THR__WIDTH                                  6
#define MDM_ACCESS_ADDRESS__MATCH_THR__MASK                         0x0000003fU
#define MDM_ACCESS_ADDRESS__MATCH_THR__READ(src) \
                    ((uint32_t)(src)\
                    & 0x0000003fU)
#define MDM_ACCESS_ADDRESS__MATCH_THR__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000003fU)
#define MDM_ACCESS_ADDRESS__MATCH_THR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000003fU) | ((uint32_t)(src) &\
                    0x0000003fU)
#define MDM_ACCESS_ADDRESS__MATCH_THR__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000003fU)))
#define MDM_ACCESS_ADDRESS__MATCH_THR__RESET_VALUE                  0x00000020U
/** @} */

/* macros for field lsb_auto_match */
/**
 * @defgroup mdm_regs_core_lsb_auto_match_field lsb_auto_match_field
 * @brief macros for field lsb_auto_match
 * @details Automatically match the specified bits of the access address. lsb of this field is lsb of access address. msb of this field is bit 3 of access address
 * @{
 */
#define MDM_ACCESS_ADDRESS__LSB_AUTO_MATCH__SHIFT                             6
#define MDM_ACCESS_ADDRESS__LSB_AUTO_MATCH__WIDTH                             4
#define MDM_ACCESS_ADDRESS__LSB_AUTO_MATCH__MASK                    0x000003c0U
#define MDM_ACCESS_ADDRESS__LSB_AUTO_MATCH__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000003c0U) >> 6)
#define MDM_ACCESS_ADDRESS__LSB_AUTO_MATCH__WRITE(src) \
                    (((uint32_t)(src)\
                    << 6) & 0x000003c0U)
#define MDM_ACCESS_ADDRESS__LSB_AUTO_MATCH__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000003c0U) | (((uint32_t)(src) <<\
                    6) & 0x000003c0U)
#define MDM_ACCESS_ADDRESS__LSB_AUTO_MATCH__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 6) & ~0x000003c0U)))
#define MDM_ACCESS_ADDRESS__LSB_AUTO_MATCH__RESET_VALUE             0x00000001U
/** @} */

/* macros for field enable_coded_timeout */
/**
 * @defgroup mdm_regs_core_enable_coded_timeout_field enable_coded_timeout_field
 * @brief macros for field enable_coded_timeout
 * @details Timeout after having seen the specified number of symbols after frequency and timing sync, coded rates
 * @{
 */
#define MDM_ACCESS_ADDRESS__ENABLE_CODED_TIMEOUT__SHIFT                      10
#define MDM_ACCESS_ADDRESS__ENABLE_CODED_TIMEOUT__WIDTH                       1
#define MDM_ACCESS_ADDRESS__ENABLE_CODED_TIMEOUT__MASK              0x00000400U
#define MDM_ACCESS_ADDRESS__ENABLE_CODED_TIMEOUT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000400U) >> 10)
#define MDM_ACCESS_ADDRESS__ENABLE_CODED_TIMEOUT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x00000400U)
#define MDM_ACCESS_ADDRESS__ENABLE_CODED_TIMEOUT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | (((uint32_t)(src) <<\
                    10) & 0x00000400U)
#define MDM_ACCESS_ADDRESS__ENABLE_CODED_TIMEOUT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x00000400U)))
#define MDM_ACCESS_ADDRESS__ENABLE_CODED_TIMEOUT__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | ((uint32_t)(1) << 10)
#define MDM_ACCESS_ADDRESS__ENABLE_CODED_TIMEOUT__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000400U) | ((uint32_t)(0) << 10)
#define MDM_ACCESS_ADDRESS__ENABLE_CODED_TIMEOUT__RESET_VALUE       0x00000001U
/** @} */

/* macros for field coded_bit_count_timeout */
/**
 * @defgroup mdm_regs_core_coded_bit_count_timeout_field coded_bit_count_timeout_field
 * @brief macros for field coded_bit_count_timeout
 * @details Number of symbols to declare timeout, coded rates
 * @{
 */
#define MDM_ACCESS_ADDRESS__CODED_BIT_COUNT_TIMEOUT__SHIFT                   12
#define MDM_ACCESS_ADDRESS__CODED_BIT_COUNT_TIMEOUT__WIDTH                   12
#define MDM_ACCESS_ADDRESS__CODED_BIT_COUNT_TIMEOUT__MASK           0x00fff000U
#define MDM_ACCESS_ADDRESS__CODED_BIT_COUNT_TIMEOUT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00fff000U) >> 12)
#define MDM_ACCESS_ADDRESS__CODED_BIT_COUNT_TIMEOUT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x00fff000U)
#define MDM_ACCESS_ADDRESS__CODED_BIT_COUNT_TIMEOUT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00fff000U) | (((uint32_t)(src) <<\
                    12) & 0x00fff000U)
#define MDM_ACCESS_ADDRESS__CODED_BIT_COUNT_TIMEOUT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x00fff000U)))
#define MDM_ACCESS_ADDRESS__CODED_BIT_COUNT_TIMEOUT__RESET_VALUE    0x0000017cU
/** @} */
#define MDM_ACCESS_ADDRESS__TYPE                                       uint32_t
#define MDM_ACCESS_ADDRESS__READ                                    0x00fff7ffU
#define MDM_ACCESS_ADDRESS__WRITE                                   0x00fff7ffU
#define MDM_ACCESS_ADDRESS__PRESERVED                               0x00000000U
#define MDM_ACCESS_ADDRESS__RESET_VALUE                             0x0017c460U

#endif /* __MDM_ACCESS_ADDRESS_MACRO__ */

/** @} end of access_address */

/* macros for BlueprintGlobalNameSpace::MDM_mode */
/**
 * @defgroup mdm_regs_core_mode mode
 * @brief Mode control definitions.
 * @{
 */
#ifndef __MDM_MODE_MACRO__
#define __MDM_MODE_MACRO__

/* macros for field pmode */
/**
 * @defgroup mdm_regs_core_pmode_field pmode_field
 * @brief macros for field pmode
 * @details 2'b00 = DUAL, normal mode, dual conversion, both I and Q 2'b01 = SINGLE, single conversion, both I and Q 2'b10 = LP_DUAL, low power mode, dual conversion. Within mdm, only I is used 2'b11 = LP_SINGLE, low power mode, single conversion. Within mdm, only I is used
 * @{
 */
#define MDM_MODE__PMODE__SHIFT                                                0
#define MDM_MODE__PMODE__WIDTH                                                2
#define MDM_MODE__PMODE__MASK                                       0x00000003U
#define MDM_MODE__PMODE__READ(src)              ((uint32_t)(src) & 0x00000003U)
#define MDM_MODE__PMODE__WRITE(src)             ((uint32_t)(src) & 0x00000003U)
#define MDM_MODE__PMODE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000003U) | ((uint32_t)(src) &\
                    0x00000003U)
#define MDM_MODE__PMODE__VERIFY(src)      (!(((uint32_t)(src) & ~0x00000003U)))
#define MDM_MODE__PMODE__RESET_VALUE                                0x00000000U
/** @} */

/* macros for field mod_mode */
/**
 * @defgroup mdm_regs_core_mod_mode_field mod_mode_field
 * @brief macros for field mod_mode
 * @details TX modulation mode for radio 00 -> No modulation 01 -> use radio LUT like sydney with tx_data[6] 10 -> bypass radio LUT for 15.4, potentially use another LUT 11 -> bypass all LUTs, directly apply tx_data[6:0] for DTOP bypass
 * @{
 */
#define MDM_MODE__MOD_MODE__SHIFT                                             2
#define MDM_MODE__MOD_MODE__WIDTH                                             2
#define MDM_MODE__MOD_MODE__MASK                                    0x0000000cU
#define MDM_MODE__MOD_MODE__READ(src)    (((uint32_t)(src) & 0x0000000cU) >> 2)
#define MDM_MODE__MOD_MODE__WRITE(src)   (((uint32_t)(src) << 2) & 0x0000000cU)
#define MDM_MODE__MOD_MODE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000000cU) | (((uint32_t)(src) <<\
                    2) & 0x0000000cU)
#define MDM_MODE__MOD_MODE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x0000000cU)))
#define MDM_MODE__MOD_MODE__RESET_VALUE                             0x00000001U
/** @} */

/* macros for field force_rx_en */
/**
 * @defgroup mdm_regs_core_force_rx_en_field force_rx_en_field
 * @brief macros for field force_rx_en
 * @details Ignore rx_en value from LC
 * @{
 */
#define MDM_MODE__FORCE_RX_EN__SHIFT                                          4
#define MDM_MODE__FORCE_RX_EN__WIDTH                                          1
#define MDM_MODE__FORCE_RX_EN__MASK                                 0x00000010U
#define MDM_MODE__FORCE_RX_EN__READ(src) (((uint32_t)(src) & 0x00000010U) >> 4)
#define MDM_MODE__FORCE_RX_EN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x00000010U)
#define MDM_MODE__FORCE_RX_EN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | (((uint32_t)(src) <<\
                    4) & 0x00000010U)
#define MDM_MODE__FORCE_RX_EN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x00000010U)))
#define MDM_MODE__FORCE_RX_EN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(1) << 4)
#define MDM_MODE__FORCE_RX_EN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(0) << 4)
#define MDM_MODE__FORCE_RX_EN__RESET_VALUE                          0x00000000U
/** @} */

/* macros for field forced_rx_en_value */
/**
 * @defgroup mdm_regs_core_forced_rx_en_value_field forced_rx_en_value_field
 * @brief macros for field forced_rx_en_value
 * @details If force_rx_en set, use this value instead
 * @{
 */
#define MDM_MODE__FORCED_RX_EN_VALUE__SHIFT                                   5
#define MDM_MODE__FORCED_RX_EN_VALUE__WIDTH                                   1
#define MDM_MODE__FORCED_RX_EN_VALUE__MASK                          0x00000020U
#define MDM_MODE__FORCED_RX_EN_VALUE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000020U) >> 5)
#define MDM_MODE__FORCED_RX_EN_VALUE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 5) & 0x00000020U)
#define MDM_MODE__FORCED_RX_EN_VALUE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | (((uint32_t)(src) <<\
                    5) & 0x00000020U)
#define MDM_MODE__FORCED_RX_EN_VALUE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 5) & ~0x00000020U)))
#define MDM_MODE__FORCED_RX_EN_VALUE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(1) << 5)
#define MDM_MODE__FORCED_RX_EN_VALUE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(0) << 5)
#define MDM_MODE__FORCED_RX_EN_VALUE__RESET_VALUE                   0x00000000U
/** @} */

/* macros for field force_reg_bank */
/**
 * @defgroup mdm_regs_core_force_reg_bank_field force_reg_bank_field
 * @brief macros for field force_reg_bank
 * @details 0: Use lc_select_alt_regs 1: Use reg_bank field
 * @{
 */
#define MDM_MODE__FORCE_REG_BANK__SHIFT                                       6
#define MDM_MODE__FORCE_REG_BANK__WIDTH                                       1
#define MDM_MODE__FORCE_REG_BANK__MASK                              0x00000040U
#define MDM_MODE__FORCE_REG_BANK__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000040U) >> 6)
#define MDM_MODE__FORCE_REG_BANK__WRITE(src) \
                    (((uint32_t)(src)\
                    << 6) & 0x00000040U)
#define MDM_MODE__FORCE_REG_BANK__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | (((uint32_t)(src) <<\
                    6) & 0x00000040U)
#define MDM_MODE__FORCE_REG_BANK__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 6) & ~0x00000040U)))
#define MDM_MODE__FORCE_REG_BANK__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(1) << 6)
#define MDM_MODE__FORCE_REG_BANK__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(0) << 6)
#define MDM_MODE__FORCE_REG_BANK__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field reg_bank */
/**
 * @defgroup mdm_regs_core_reg_bank_field reg_bank_field
 * @brief macros for field reg_bank
 * @details Register bank to select if forced. 0 = standard. 1 = alternate
 * @{
 */
#define MDM_MODE__REG_BANK__SHIFT                                             7
#define MDM_MODE__REG_BANK__WIDTH                                             1
#define MDM_MODE__REG_BANK__MASK                                    0x00000080U
#define MDM_MODE__REG_BANK__READ(src)    (((uint32_t)(src) & 0x00000080U) >> 7)
#define MDM_MODE__REG_BANK__WRITE(src)   (((uint32_t)(src) << 7) & 0x00000080U)
#define MDM_MODE__REG_BANK__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | (((uint32_t)(src) <<\
                    7) & 0x00000080U)
#define MDM_MODE__REG_BANK__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 7) & ~0x00000080U)))
#define MDM_MODE__REG_BANK__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | ((uint32_t)(1) << 7)
#define MDM_MODE__REG_BANK__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | ((uint32_t)(0) << 7)
#define MDM_MODE__REG_BANK__RESET_VALUE                             0x00000000U
/** @} */

/* macros for field invert_reg_select_from_lc */
/**
 * @defgroup mdm_regs_core_invert_reg_select_from_lc_field invert_reg_select_from_lc_field
 * @brief macros for field invert_reg_select_from_lc
 * @details If set, invert lc_select_alt_regs
 * @{
 */
#define MDM_MODE__INVERT_REG_SELECT_FROM_LC__SHIFT                            8
#define MDM_MODE__INVERT_REG_SELECT_FROM_LC__WIDTH                            1
#define MDM_MODE__INVERT_REG_SELECT_FROM_LC__MASK                   0x00000100U
#define MDM_MODE__INVERT_REG_SELECT_FROM_LC__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000100U) >> 8)
#define MDM_MODE__INVERT_REG_SELECT_FROM_LC__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00000100U)
#define MDM_MODE__INVERT_REG_SELECT_FROM_LC__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | (((uint32_t)(src) <<\
                    8) & 0x00000100U)
#define MDM_MODE__INVERT_REG_SELECT_FROM_LC__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00000100U)))
#define MDM_MODE__INVERT_REG_SELECT_FROM_LC__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | ((uint32_t)(1) << 8)
#define MDM_MODE__INVERT_REG_SELECT_FROM_LC__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | ((uint32_t)(0) << 8)
#define MDM_MODE__INVERT_REG_SELECT_FROM_LC__RESET_VALUE            0x00000000U
/** @} */
#define MDM_MODE__TYPE                                                 uint32_t
#define MDM_MODE__READ                                              0x000001ffU
#define MDM_MODE__WRITE                                             0x000001ffU
#define MDM_MODE__PRESERVED                                         0x00000000U
#define MDM_MODE__RESET_VALUE                                       0x00000004U

#endif /* __MDM_MODE_MACRO__ */

/** @} end of mode */

/* macros for BlueprintGlobalNameSpace::MDM_dccal */
/**
 * @defgroup mdm_regs_core_dccal dccal
 * @brief DC offset calibration control for TIA for sydney definitions.
 * @{
 */
#ifndef __MDM_DCCAL_MACRO__
#define __MDM_DCCAL_MACRO__

/* macros for field byp */
/**
 * @defgroup mdm_regs_core_byp_field byp_field
 * @brief macros for field byp
 * @details bypass DC calibration
 * @{
 */
#define MDM_DCCAL__BYP__SHIFT                                                 0
#define MDM_DCCAL__BYP__WIDTH                                                 1
#define MDM_DCCAL__BYP__MASK                                        0x00000001U
#define MDM_DCCAL__BYP__READ(src)               ((uint32_t)(src) & 0x00000001U)
#define MDM_DCCAL__BYP__WRITE(src)              ((uint32_t)(src) & 0x00000001U)
#define MDM_DCCAL__BYP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define MDM_DCCAL__BYP__VERIFY(src)       (!(((uint32_t)(src) & ~0x00000001U)))
#define MDM_DCCAL__BYP__SET(dst) (dst) = ((dst) & ~0x00000001U) | (uint32_t)(1)
#define MDM_DCCAL__BYP__CLR(dst) (dst) = ((dst) & ~0x00000001U) | (uint32_t)(0)
#define MDM_DCCAL__BYP__RESET_VALUE                                 0x00000000U
/** @} */

/* macros for field start */
/**
 * @defgroup mdm_regs_core_start_field start_field
 * @brief macros for field start
 * @details software trigger DC calibration start
 * @{
 */
#define MDM_DCCAL__START__SHIFT                                               1
#define MDM_DCCAL__START__WIDTH                                               1
#define MDM_DCCAL__START__MASK                                      0x00000002U
#define MDM_DCCAL__START__READ(src)      (((uint32_t)(src) & 0x00000002U) >> 1)
#define MDM_DCCAL__START__WRITE(src)     (((uint32_t)(src) << 1) & 0x00000002U)
#define MDM_DCCAL__START__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define MDM_DCCAL__START__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define MDM_DCCAL__START__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define MDM_DCCAL__START__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define MDM_DCCAL__START__RESET_VALUE                               0x00000000U
/** @} */

/* macros for field avg_only */
/**
 * @defgroup mdm_regs_core_avg_only_field avg_only_field
 * @brief macros for field avg_only
 * @details software trigger DC calibration start average only cal
 * @{
 */
#define MDM_DCCAL__AVG_ONLY__SHIFT                                            2
#define MDM_DCCAL__AVG_ONLY__WIDTH                                            1
#define MDM_DCCAL__AVG_ONLY__MASK                                   0x00000004U
#define MDM_DCCAL__AVG_ONLY__READ(src)   (((uint32_t)(src) & 0x00000004U) >> 2)
#define MDM_DCCAL__AVG_ONLY__WRITE(src)  (((uint32_t)(src) << 2) & 0x00000004U)
#define MDM_DCCAL__AVG_ONLY__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define MDM_DCCAL__AVG_ONLY__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define MDM_DCCAL__AVG_ONLY__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define MDM_DCCAL__AVG_ONLY__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define MDM_DCCAL__AVG_ONLY__RESET_VALUE                            0x00000000U
/** @} */

/* macros for field avg_cnt_exp */
/**
 * @defgroup mdm_regs_core_avg_cnt_exp_field avg_cnt_exp_field
 * @brief macros for field avg_cnt_exp
 * @details 2's power number of samples to average; valid values [2-6]
 * @{
 */
#define MDM_DCCAL__AVG_CNT_EXP__SHIFT                                         4
#define MDM_DCCAL__AVG_CNT_EXP__WIDTH                                         3
#define MDM_DCCAL__AVG_CNT_EXP__MASK                                0x00000070U
#define MDM_DCCAL__AVG_CNT_EXP__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000070U) >> 4)
#define MDM_DCCAL__AVG_CNT_EXP__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x00000070U)
#define MDM_DCCAL__AVG_CNT_EXP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000070U) | (((uint32_t)(src) <<\
                    4) & 0x00000070U)
#define MDM_DCCAL__AVG_CNT_EXP__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x00000070U)))
#define MDM_DCCAL__AVG_CNT_EXP__RESET_VALUE                         0x00000003U
/** @} */

/* macros for field srch_bit_cnt */
/**
 * @defgroup mdm_regs_core_srch_bit_cnt_field srch_bit_cnt_field
 * @brief macros for field srch_bit_cnt
 * @details number of DC offset bits to search
 * @{
 */
#define MDM_DCCAL__SRCH_BIT_CNT__SHIFT                                        7
#define MDM_DCCAL__SRCH_BIT_CNT__WIDTH                                        4
#define MDM_DCCAL__SRCH_BIT_CNT__MASK                               0x00000780U
#define MDM_DCCAL__SRCH_BIT_CNT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000780U) >> 7)
#define MDM_DCCAL__SRCH_BIT_CNT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 7) & 0x00000780U)
#define MDM_DCCAL__SRCH_BIT_CNT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000780U) | (((uint32_t)(src) <<\
                    7) & 0x00000780U)
#define MDM_DCCAL__SRCH_BIT_CNT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 7) & ~0x00000780U)))
#define MDM_DCCAL__SRCH_BIT_CNT__RESET_VALUE                        0x00000006U
/** @} */

/* macros for field msb */
/**
 * @defgroup mdm_regs_core_msb_field msb_field
 * @brief macros for field msb
 * @details 0 => 5, 1 => 6, 2 => 7, 3 => 8
 * @{
 */
#define MDM_DCCAL__MSB__SHIFT                                                12
#define MDM_DCCAL__MSB__WIDTH                                                 3
#define MDM_DCCAL__MSB__MASK                                        0x00007000U
#define MDM_DCCAL__MSB__READ(src)       (((uint32_t)(src) & 0x00007000U) >> 12)
#define MDM_DCCAL__MSB__WRITE(src)      (((uint32_t)(src) << 12) & 0x00007000U)
#define MDM_DCCAL__MSB__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00007000U) | (((uint32_t)(src) <<\
                    12) & 0x00007000U)
#define MDM_DCCAL__MSB__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x00007000U)))
#define MDM_DCCAL__MSB__RESET_VALUE                                 0x00000000U
/** @} */

/* macros for field iq_ratio */
/**
 * @defgroup mdm_regs_core_iq_ratio_field iq_ratio_field
 * @brief macros for field iq_ratio
 * @details cross coupling ratio between i and q channel for 1 Mb/s; valid format u1.7
 * @{
 */
#define MDM_DCCAL__IQ_RATIO__SHIFT                                           16
#define MDM_DCCAL__IQ_RATIO__WIDTH                                            8
#define MDM_DCCAL__IQ_RATIO__MASK                                   0x00ff0000U
#define MDM_DCCAL__IQ_RATIO__READ(src)  (((uint32_t)(src) & 0x00ff0000U) >> 16)
#define MDM_DCCAL__IQ_RATIO__WRITE(src) (((uint32_t)(src) << 16) & 0x00ff0000U)
#define MDM_DCCAL__IQ_RATIO__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00ff0000U) | (((uint32_t)(src) <<\
                    16) & 0x00ff0000U)
#define MDM_DCCAL__IQ_RATIO__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x00ff0000U)))
#define MDM_DCCAL__IQ_RATIO__RESET_VALUE                            0x000000b2U
/** @} */

/* macros for field iq_ratio_twomeg */
/**
 * @defgroup mdm_regs_core_iq_ratio_twomeg_field iq_ratio_twomeg_field
 * @brief macros for field iq_ratio_twomeg
 * @details cross coupling ratio between i and q channel for 2 Mb/s; valid format u1.7
 * @{
 */
#define MDM_DCCAL__IQ_RATIO_TWOMEG__SHIFT                                    24
#define MDM_DCCAL__IQ_RATIO_TWOMEG__WIDTH                                     8
#define MDM_DCCAL__IQ_RATIO_TWOMEG__MASK                            0xff000000U
#define MDM_DCCAL__IQ_RATIO_TWOMEG__READ(src) \
                    (((uint32_t)(src)\
                    & 0xff000000U) >> 24)
#define MDM_DCCAL__IQ_RATIO_TWOMEG__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0xff000000U)
#define MDM_DCCAL__IQ_RATIO_TWOMEG__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xff000000U) | (((uint32_t)(src) <<\
                    24) & 0xff000000U)
#define MDM_DCCAL__IQ_RATIO_TWOMEG__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0xff000000U)))
#define MDM_DCCAL__IQ_RATIO_TWOMEG__RESET_VALUE                     0x000000b2U
/** @} */
#define MDM_DCCAL__TYPE                                                uint32_t
#define MDM_DCCAL__READ                                             0xffff77f7U
#define MDM_DCCAL__WRITE                                            0xffff77f7U
#define MDM_DCCAL__PRESERVED                                        0x00000000U
#define MDM_DCCAL__RESET_VALUE                                      0xb2b20330U

#endif /* __MDM_DCCAL_MACRO__ */

/** @} end of dccal */

/* macros for BlueprintGlobalNameSpace::MDM_dccal2 */
/**
 * @defgroup mdm_regs_core_dccal2 dccal2
 * @brief DC offset calibration control for TIA, set 2 for sydney definitions.
 * @{
 */
#ifndef __MDM_DCCAL2_MACRO__
#define __MDM_DCCAL2_MACRO__

/* macros for field rf_post_dccal_sttl_cnt */
/**
 * @defgroup mdm_regs_core_rf_post_dccal_sttl_cnt_field rf_post_dccal_sttl_cnt_field
 * @brief macros for field rf_post_dccal_sttl_cnt
 * @details number of 16 MHz clocks from rf to settle after caldc is deasserted. MUST BE EVEN
 * @{
 */
#define MDM_DCCAL2__RF_POST_DCCAL_STTL_CNT__SHIFT                             0
#define MDM_DCCAL2__RF_POST_DCCAL_STTL_CNT__WIDTH                            10
#define MDM_DCCAL2__RF_POST_DCCAL_STTL_CNT__MASK                    0x000003ffU
#define MDM_DCCAL2__RF_POST_DCCAL_STTL_CNT__READ(src) \
                    ((uint32_t)(src)\
                    & 0x000003ffU)
#define MDM_DCCAL2__RF_POST_DCCAL_STTL_CNT__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x000003ffU)
#define MDM_DCCAL2__RF_POST_DCCAL_STTL_CNT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000003ffU) | ((uint32_t)(src) &\
                    0x000003ffU)
#define MDM_DCCAL2__RF_POST_DCCAL_STTL_CNT__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000003ffU)))
#define MDM_DCCAL2__RF_POST_DCCAL_STTL_CNT__RESET_VALUE             0x00000010U
/** @} */

/* macros for field rf_sttl_cnt */
/**
 * @defgroup mdm_regs_core_rf_sttl_cnt_field rf_sttl_cnt_field
 * @brief macros for field rf_sttl_cnt
 * @details number of 16 MHz clocks from rf to settle after tia gain change for 1 Mb/s. MUST BE EVEN
 * @{
 */
#define MDM_DCCAL2__RF_STTL_CNT__SHIFT                                       10
#define MDM_DCCAL2__RF_STTL_CNT__WIDTH                                       10
#define MDM_DCCAL2__RF_STTL_CNT__MASK                               0x000ffc00U
#define MDM_DCCAL2__RF_STTL_CNT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000ffc00U) >> 10)
#define MDM_DCCAL2__RF_STTL_CNT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x000ffc00U)
#define MDM_DCCAL2__RF_STTL_CNT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000ffc00U) | (((uint32_t)(src) <<\
                    10) & 0x000ffc00U)
#define MDM_DCCAL2__RF_STTL_CNT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x000ffc00U)))
#define MDM_DCCAL2__RF_STTL_CNT__RESET_VALUE                        0x00000010U
/** @} */

/* macros for field rf_sttl_cnt_twomeg */
/**
 * @defgroup mdm_regs_core_rf_sttl_cnt_twomeg_field rf_sttl_cnt_twomeg_field
 * @brief macros for field rf_sttl_cnt_twomeg
 * @details number of 16 MHz clocks from rf to settle after tia gain change for 2 Mb/s
 * @{
 */
#define MDM_DCCAL2__RF_STTL_CNT_TWOMEG__SHIFT                                20
#define MDM_DCCAL2__RF_STTL_CNT_TWOMEG__WIDTH                                10
#define MDM_DCCAL2__RF_STTL_CNT_TWOMEG__MASK                        0x3ff00000U
#define MDM_DCCAL2__RF_STTL_CNT_TWOMEG__READ(src) \
                    (((uint32_t)(src)\
                    & 0x3ff00000U) >> 20)
#define MDM_DCCAL2__RF_STTL_CNT_TWOMEG__WRITE(src) \
                    (((uint32_t)(src)\
                    << 20) & 0x3ff00000U)
#define MDM_DCCAL2__RF_STTL_CNT_TWOMEG__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x3ff00000U) | (((uint32_t)(src) <<\
                    20) & 0x3ff00000U)
#define MDM_DCCAL2__RF_STTL_CNT_TWOMEG__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x3ff00000U)))
#define MDM_DCCAL2__RF_STTL_CNT_TWOMEG__RESET_VALUE                 0x00000010U
/** @} */
#define MDM_DCCAL2__TYPE                                               uint32_t
#define MDM_DCCAL2__READ                                            0x3fffffffU
#define MDM_DCCAL2__WRITE                                           0x3fffffffU
#define MDM_DCCAL2__PRESERVED                                       0x00000000U
#define MDM_DCCAL2__RESET_VALUE                                     0x01004010U

#endif /* __MDM_DCCAL2_MACRO__ */

/** @} end of dccal2 */

/* macros for BlueprintGlobalNameSpace::MDM_dccal_ctrl */
/**
 * @defgroup mdm_regs_core_dccal_ctrl dccal_ctrl
 * @brief Global calibration control for paris definitions.
 * @{
 */
#ifndef __MDM_DCCAL_CTRL_MACRO__
#define __MDM_DCCAL_CTRL_MACRO__

/* macros for field byp */
/**
 * @defgroup mdm_regs_core_byp_field byp_field
 * @brief macros for field byp
 * @details bypass DC calibration
 * @{
 */
#define MDM_DCCAL_CTRL__BYP__SHIFT                                            0
#define MDM_DCCAL_CTRL__BYP__WIDTH                                            1
#define MDM_DCCAL_CTRL__BYP__MASK                                   0x00000001U
#define MDM_DCCAL_CTRL__BYP__READ(src)          ((uint32_t)(src) & 0x00000001U)
#define MDM_DCCAL_CTRL__BYP__WRITE(src)         ((uint32_t)(src) & 0x00000001U)
#define MDM_DCCAL_CTRL__BYP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define MDM_DCCAL_CTRL__BYP__VERIFY(src)  (!(((uint32_t)(src) & ~0x00000001U)))
#define MDM_DCCAL_CTRL__BYP__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define MDM_DCCAL_CTRL__BYP__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define MDM_DCCAL_CTRL__BYP__RESET_VALUE                            0x00000000U
/** @} */

/* macros for field start */
/**
 * @defgroup mdm_regs_core_start_field start_field
 * @brief macros for field start
 * @details software trigger DC calibration start
 * @{
 */
#define MDM_DCCAL_CTRL__START__SHIFT                                          1
#define MDM_DCCAL_CTRL__START__WIDTH                                          1
#define MDM_DCCAL_CTRL__START__MASK                                 0x00000002U
#define MDM_DCCAL_CTRL__START__READ(src) (((uint32_t)(src) & 0x00000002U) >> 1)
#define MDM_DCCAL_CTRL__START__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define MDM_DCCAL_CTRL__START__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define MDM_DCCAL_CTRL__START__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define MDM_DCCAL_CTRL__START__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define MDM_DCCAL_CTRL__START__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define MDM_DCCAL_CTRL__START__RESET_VALUE                          0x00000000U
/** @} */

/* macros for field mode */
/**
 * @defgroup mdm_regs_core_mode_field mode_field
 * @brief macros for field mode
 * @details 0 => TIA cal, 1 => PGA cal, 2 => notch cal
 * @{
 */
#define MDM_DCCAL_CTRL__MODE__SHIFT                                           2
#define MDM_DCCAL_CTRL__MODE__WIDTH                                           3
#define MDM_DCCAL_CTRL__MODE__MASK                                  0x0000001cU
#define MDM_DCCAL_CTRL__MODE__READ(src)  (((uint32_t)(src) & 0x0000001cU) >> 2)
#define MDM_DCCAL_CTRL__MODE__WRITE(src) (((uint32_t)(src) << 2) & 0x0000001cU)
#define MDM_DCCAL_CTRL__MODE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000001cU) | (((uint32_t)(src) <<\
                    2) & 0x0000001cU)
#define MDM_DCCAL_CTRL__MODE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x0000001cU)))
#define MDM_DCCAL_CTRL__MODE__RESET_VALUE                           0x00000000U
/** @} */

/* macros for field force_res_corr */
/**
 * @defgroup mdm_regs_core_force_res_corr_field force_res_corr_field
 * @brief macros for field force_res_corr
 * @details 0 => only go to residue correction when dccal is triggered, 1 => go to residue correction when dccal is bypassed and bb1dcoc and bb2dcoc are latched
 * @{
 */
#define MDM_DCCAL_CTRL__FORCE_RES_CORR__SHIFT                                 5
#define MDM_DCCAL_CTRL__FORCE_RES_CORR__WIDTH                                 1
#define MDM_DCCAL_CTRL__FORCE_RES_CORR__MASK                        0x00000020U
#define MDM_DCCAL_CTRL__FORCE_RES_CORR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000020U) >> 5)
#define MDM_DCCAL_CTRL__FORCE_RES_CORR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 5) & 0x00000020U)
#define MDM_DCCAL_CTRL__FORCE_RES_CORR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | (((uint32_t)(src) <<\
                    5) & 0x00000020U)
#define MDM_DCCAL_CTRL__FORCE_RES_CORR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 5) & ~0x00000020U)))
#define MDM_DCCAL_CTRL__FORCE_RES_CORR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(1) << 5)
#define MDM_DCCAL_CTRL__FORCE_RES_CORR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(0) << 5)
#define MDM_DCCAL_CTRL__FORCE_RES_CORR__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field use_cal_gain_pga_off */
/**
 * @defgroup mdm_regs_core_use_cal_gain_pga_off_field use_cal_gain_pga_off_field
 * @brief macros for field use_cal_gain_pga_off
 * @details 0 => do not use gain adjusted pga offset, 1 => use gain adjusted pga offset
 * @{
 */
#define MDM_DCCAL_CTRL__USE_CAL_GAIN_PGA_OFF__SHIFT                           6
#define MDM_DCCAL_CTRL__USE_CAL_GAIN_PGA_OFF__WIDTH                           1
#define MDM_DCCAL_CTRL__USE_CAL_GAIN_PGA_OFF__MASK                  0x00000040U
#define MDM_DCCAL_CTRL__USE_CAL_GAIN_PGA_OFF__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000040U) >> 6)
#define MDM_DCCAL_CTRL__USE_CAL_GAIN_PGA_OFF__WRITE(src) \
                    (((uint32_t)(src)\
                    << 6) & 0x00000040U)
#define MDM_DCCAL_CTRL__USE_CAL_GAIN_PGA_OFF__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | (((uint32_t)(src) <<\
                    6) & 0x00000040U)
#define MDM_DCCAL_CTRL__USE_CAL_GAIN_PGA_OFF__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 6) & ~0x00000040U)))
#define MDM_DCCAL_CTRL__USE_CAL_GAIN_PGA_OFF__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(1) << 6)
#define MDM_DCCAL_CTRL__USE_CAL_GAIN_PGA_OFF__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(0) << 6)
#define MDM_DCCAL_CTRL__USE_CAL_GAIN_PGA_OFF__RESET_VALUE           0x00000001U
/** @} */

/* macros for field use_eq_lp_pga_off */
/**
 * @defgroup mdm_regs_core_use_eq_lp_pga_off_field use_eq_lp_pga_off_field
 * @brief macros for field use_eq_lp_pga_off
 * @details 0 => do not use equation based lp PGA during cal state, 1 => use equation based lp PGA during cal state
 * @{
 */
#define MDM_DCCAL_CTRL__USE_EQ_LP_PGA_OFF__SHIFT                              7
#define MDM_DCCAL_CTRL__USE_EQ_LP_PGA_OFF__WIDTH                              1
#define MDM_DCCAL_CTRL__USE_EQ_LP_PGA_OFF__MASK                     0x00000080U
#define MDM_DCCAL_CTRL__USE_EQ_LP_PGA_OFF__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000080U) >> 7)
#define MDM_DCCAL_CTRL__USE_EQ_LP_PGA_OFF__WRITE(src) \
                    (((uint32_t)(src)\
                    << 7) & 0x00000080U)
#define MDM_DCCAL_CTRL__USE_EQ_LP_PGA_OFF__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | (((uint32_t)(src) <<\
                    7) & 0x00000080U)
#define MDM_DCCAL_CTRL__USE_EQ_LP_PGA_OFF__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 7) & ~0x00000080U)))
#define MDM_DCCAL_CTRL__USE_EQ_LP_PGA_OFF__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | ((uint32_t)(1) << 7)
#define MDM_DCCAL_CTRL__USE_EQ_LP_PGA_OFF__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | ((uint32_t)(0) << 7)
#define MDM_DCCAL_CTRL__USE_EQ_LP_PGA_OFF__RESET_VALUE              0x00000000U
/** @} */
#define MDM_DCCAL_CTRL__TYPE                                           uint32_t
#define MDM_DCCAL_CTRL__READ                                        0x000000ffU
#define MDM_DCCAL_CTRL__WRITE                                       0x000000ffU
#define MDM_DCCAL_CTRL__PRESERVED                                   0x00000000U
#define MDM_DCCAL_CTRL__RESET_VALUE                                 0x00000040U

#endif /* __MDM_DCCAL_CTRL_MACRO__ */

/** @} end of dccal_ctrl */

/* macros for BlueprintGlobalNameSpace::MDM_tia_dccal */
/**
 * @defgroup mdm_regs_core_tia_dccal tia_dccal
 * @brief DC offset calibration control for TIA for paris definitions.
 * @{
 */
#ifndef __MDM_TIA_DCCAL_MACRO__
#define __MDM_TIA_DCCAL_MACRO__

/* macros for field avg_only */
/**
 * @defgroup mdm_regs_core_avg_only_field avg_only_field
 * @brief macros for field avg_only
 * @details software trigger DC calibration start average only cal
 * @{
 */
#define MDM_TIA_DCCAL__AVG_ONLY__SHIFT                                        2
#define MDM_TIA_DCCAL__AVG_ONLY__WIDTH                                        1
#define MDM_TIA_DCCAL__AVG_ONLY__MASK                               0x00000004U
#define MDM_TIA_DCCAL__AVG_ONLY__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define MDM_TIA_DCCAL__AVG_ONLY__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define MDM_TIA_DCCAL__AVG_ONLY__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define MDM_TIA_DCCAL__AVG_ONLY__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define MDM_TIA_DCCAL__AVG_ONLY__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define MDM_TIA_DCCAL__AVG_ONLY__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define MDM_TIA_DCCAL__AVG_ONLY__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field avg_cnt_exp */
/**
 * @defgroup mdm_regs_core_avg_cnt_exp_field avg_cnt_exp_field
 * @brief macros for field avg_cnt_exp
 * @details 2's power number of samples to average; valid values [2-6]
 * @{
 */
#define MDM_TIA_DCCAL__AVG_CNT_EXP__SHIFT                                     4
#define MDM_TIA_DCCAL__AVG_CNT_EXP__WIDTH                                     3
#define MDM_TIA_DCCAL__AVG_CNT_EXP__MASK                            0x00000070U
#define MDM_TIA_DCCAL__AVG_CNT_EXP__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000070U) >> 4)
#define MDM_TIA_DCCAL__AVG_CNT_EXP__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x00000070U)
#define MDM_TIA_DCCAL__AVG_CNT_EXP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000070U) | (((uint32_t)(src) <<\
                    4) & 0x00000070U)
#define MDM_TIA_DCCAL__AVG_CNT_EXP__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x00000070U)))
#define MDM_TIA_DCCAL__AVG_CNT_EXP__RESET_VALUE                     0x00000003U
/** @} */

/* macros for field srch_bit_cnt */
/**
 * @defgroup mdm_regs_core_srch_bit_cnt_field srch_bit_cnt_field
 * @brief macros for field srch_bit_cnt
 * @details number of DC offset bits to search
 * @{
 */
#define MDM_TIA_DCCAL__SRCH_BIT_CNT__SHIFT                                    7
#define MDM_TIA_DCCAL__SRCH_BIT_CNT__WIDTH                                    4
#define MDM_TIA_DCCAL__SRCH_BIT_CNT__MASK                           0x00000780U
#define MDM_TIA_DCCAL__SRCH_BIT_CNT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000780U) >> 7)
#define MDM_TIA_DCCAL__SRCH_BIT_CNT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 7) & 0x00000780U)
#define MDM_TIA_DCCAL__SRCH_BIT_CNT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000780U) | (((uint32_t)(src) <<\
                    7) & 0x00000780U)
#define MDM_TIA_DCCAL__SRCH_BIT_CNT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 7) & ~0x00000780U)))
#define MDM_TIA_DCCAL__SRCH_BIT_CNT__RESET_VALUE                    0x00000006U
/** @} */

/* macros for field msb */
/**
 * @defgroup mdm_regs_core_msb_field msb_field
 * @brief macros for field msb
 * @details 0 => 5, 1 => 6, 2 => 7, 3 => 8 for dcoc width == 0, 0 => 6, 1 => 7, 2 => 8, 3 => 9 for dcoc width == 1, 0 => 7, 1 => 8, 2 => 9, 3 => 10 for dcoc width == 2
 * @{
 */
#define MDM_TIA_DCCAL__MSB__SHIFT                                            11
#define MDM_TIA_DCCAL__MSB__WIDTH                                             3
#define MDM_TIA_DCCAL__MSB__MASK                                    0x00003800U
#define MDM_TIA_DCCAL__MSB__READ(src)   (((uint32_t)(src) & 0x00003800U) >> 11)
#define MDM_TIA_DCCAL__MSB__WRITE(src)  (((uint32_t)(src) << 11) & 0x00003800U)
#define MDM_TIA_DCCAL__MSB__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00003800U) | (((uint32_t)(src) <<\
                    11) & 0x00003800U)
#define MDM_TIA_DCCAL__MSB__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 11) & ~0x00003800U)))
#define MDM_TIA_DCCAL__MSB__RESET_VALUE                             0x00000000U
/** @} */

/* macros for field iq_ratio */
/**
 * @defgroup mdm_regs_core_iq_ratio_field iq_ratio_field
 * @brief macros for field iq_ratio
 * @details cross coupling ratio between i and q channel for 1 Mb/s; valid format u2.7 2.15 * 2^7
 * @{
 */
#define MDM_TIA_DCCAL__IQ_RATIO__SHIFT                                       14
#define MDM_TIA_DCCAL__IQ_RATIO__WIDTH                                        9
#define MDM_TIA_DCCAL__IQ_RATIO__MASK                               0x007fc000U
#define MDM_TIA_DCCAL__IQ_RATIO__READ(src) \
                    (((uint32_t)(src)\
                    & 0x007fc000U) >> 14)
#define MDM_TIA_DCCAL__IQ_RATIO__WRITE(src) \
                    (((uint32_t)(src)\
                    << 14) & 0x007fc000U)
#define MDM_TIA_DCCAL__IQ_RATIO__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x007fc000U) | (((uint32_t)(src) <<\
                    14) & 0x007fc000U)
#define MDM_TIA_DCCAL__IQ_RATIO__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 14) & ~0x007fc000U)))
#define MDM_TIA_DCCAL__IQ_RATIO__RESET_VALUE                        0x00000113U
/** @} */

/* macros for field iq_ratio_twomeg */
/**
 * @defgroup mdm_regs_core_iq_ratio_twomeg_field iq_ratio_twomeg_field
 * @brief macros for field iq_ratio_twomeg
 * @details cross coupling ratio between i and q channel for 2 Mb/s; valid format u2.7 2.15 * 2^7
 * @{
 */
#define MDM_TIA_DCCAL__IQ_RATIO_TWOMEG__SHIFT                                23
#define MDM_TIA_DCCAL__IQ_RATIO_TWOMEG__WIDTH                                 9
#define MDM_TIA_DCCAL__IQ_RATIO_TWOMEG__MASK                        0xff800000U
#define MDM_TIA_DCCAL__IQ_RATIO_TWOMEG__READ(src) \
                    (((uint32_t)(src)\
                    & 0xff800000U) >> 23)
#define MDM_TIA_DCCAL__IQ_RATIO_TWOMEG__WRITE(src) \
                    (((uint32_t)(src)\
                    << 23) & 0xff800000U)
#define MDM_TIA_DCCAL__IQ_RATIO_TWOMEG__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xff800000U) | (((uint32_t)(src) <<\
                    23) & 0xff800000U)
#define MDM_TIA_DCCAL__IQ_RATIO_TWOMEG__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 23) & ~0xff800000U)))
#define MDM_TIA_DCCAL__IQ_RATIO_TWOMEG__RESET_VALUE                 0x00000113U
/** @} */
#define MDM_TIA_DCCAL__TYPE                                            uint32_t
#define MDM_TIA_DCCAL__READ                                         0xfffffff4U
#define MDM_TIA_DCCAL__WRITE                                        0xfffffff4U
#define MDM_TIA_DCCAL__PRESERVED                                    0x00000000U
#define MDM_TIA_DCCAL__RESET_VALUE                                  0x89c4c330U

#endif /* __MDM_TIA_DCCAL_MACRO__ */

/** @} end of tia_dccal */

/* macros for BlueprintGlobalNameSpace::MDM_tia_dccal2 */
/**
 * @defgroup mdm_regs_core_tia_dccal2 tia_dccal2
 * @brief DC offset calibration control for TIA, set 2 for paris definitions.
 * @{
 */
#ifndef __MDM_TIA_DCCAL2_MACRO__
#define __MDM_TIA_DCCAL2_MACRO__

/* macros for field rf_post_dccal_sttl_cnt */
/**
 * @defgroup mdm_regs_core_rf_post_dccal_sttl_cnt_field rf_post_dccal_sttl_cnt_field
 * @brief macros for field rf_post_dccal_sttl_cnt
 * @details number of 16 MHz clocks from rf to settle after caldc is deasserted. MUST BE EVEN
 * @{
 */
#define MDM_TIA_DCCAL2__RF_POST_DCCAL_STTL_CNT__SHIFT                         0
#define MDM_TIA_DCCAL2__RF_POST_DCCAL_STTL_CNT__WIDTH                        10
#define MDM_TIA_DCCAL2__RF_POST_DCCAL_STTL_CNT__MASK                0x000003ffU
#define MDM_TIA_DCCAL2__RF_POST_DCCAL_STTL_CNT__READ(src) \
                    ((uint32_t)(src)\
                    & 0x000003ffU)
#define MDM_TIA_DCCAL2__RF_POST_DCCAL_STTL_CNT__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x000003ffU)
#define MDM_TIA_DCCAL2__RF_POST_DCCAL_STTL_CNT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000003ffU) | ((uint32_t)(src) &\
                    0x000003ffU)
#define MDM_TIA_DCCAL2__RF_POST_DCCAL_STTL_CNT__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000003ffU)))
#define MDM_TIA_DCCAL2__RF_POST_DCCAL_STTL_CNT__RESET_VALUE         0x00000050U
/** @} */

/* macros for field rf_sttl_cnt */
/**
 * @defgroup mdm_regs_core_rf_sttl_cnt_field rf_sttl_cnt_field
 * @brief macros for field rf_sttl_cnt
 * @details number of 16 MHz clocks from rf to settle after tia gain change for 1 Mb/s. MUST BE EVEN
 * @{
 */
#define MDM_TIA_DCCAL2__RF_STTL_CNT__SHIFT                                   10
#define MDM_TIA_DCCAL2__RF_STTL_CNT__WIDTH                                   10
#define MDM_TIA_DCCAL2__RF_STTL_CNT__MASK                           0x000ffc00U
#define MDM_TIA_DCCAL2__RF_STTL_CNT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000ffc00U) >> 10)
#define MDM_TIA_DCCAL2__RF_STTL_CNT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x000ffc00U)
#define MDM_TIA_DCCAL2__RF_STTL_CNT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000ffc00U) | (((uint32_t)(src) <<\
                    10) & 0x000ffc00U)
#define MDM_TIA_DCCAL2__RF_STTL_CNT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x000ffc00U)))
#define MDM_TIA_DCCAL2__RF_STTL_CNT__RESET_VALUE                    0x00000010U
/** @} */

/* macros for field rf_sttl_cnt_twomeg */
/**
 * @defgroup mdm_regs_core_rf_sttl_cnt_twomeg_field rf_sttl_cnt_twomeg_field
 * @brief macros for field rf_sttl_cnt_twomeg
 * @details number of 16 MHz clocks from rf to settle after tia gain change for 2 Mb/s
 * @{
 */
#define MDM_TIA_DCCAL2__RF_STTL_CNT_TWOMEG__SHIFT                            20
#define MDM_TIA_DCCAL2__RF_STTL_CNT_TWOMEG__WIDTH                            10
#define MDM_TIA_DCCAL2__RF_STTL_CNT_TWOMEG__MASK                    0x3ff00000U
#define MDM_TIA_DCCAL2__RF_STTL_CNT_TWOMEG__READ(src) \
                    (((uint32_t)(src)\
                    & 0x3ff00000U) >> 20)
#define MDM_TIA_DCCAL2__RF_STTL_CNT_TWOMEG__WRITE(src) \
                    (((uint32_t)(src)\
                    << 20) & 0x3ff00000U)
#define MDM_TIA_DCCAL2__RF_STTL_CNT_TWOMEG__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x3ff00000U) | (((uint32_t)(src) <<\
                    20) & 0x3ff00000U)
#define MDM_TIA_DCCAL2__RF_STTL_CNT_TWOMEG__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x3ff00000U)))
#define MDM_TIA_DCCAL2__RF_STTL_CNT_TWOMEG__RESET_VALUE             0x00000010U
/** @} */
#define MDM_TIA_DCCAL2__TYPE                                           uint32_t
#define MDM_TIA_DCCAL2__READ                                        0x3fffffffU
#define MDM_TIA_DCCAL2__WRITE                                       0x3fffffffU
#define MDM_TIA_DCCAL2__PRESERVED                                   0x00000000U
#define MDM_TIA_DCCAL2__RESET_VALUE                                 0x01004050U

#endif /* __MDM_TIA_DCCAL2_MACRO__ */

/** @} end of tia_dccal2 */

/* macros for BlueprintGlobalNameSpace::MDM_tia_dccal3 */
/**
 * @defgroup mdm_regs_core_tia_dccal3 tia_dccal3
 * @brief DC offset calibration control for TIA, set 3 for paris definitions.
 * @{
 */
#ifndef __MDM_TIA_DCCAL3_MACRO__
#define __MDM_TIA_DCCAL3_MACRO__

/* macros for field rf_post_dccal_lna_prtct_sttl_cnt */
/**
 * @defgroup mdm_regs_core_rf_post_dccal_lna_prtct_sttl_cnt_field rf_post_dccal_lna_prtct_sttl_cnt_field
 * @brief macros for field rf_post_dccal_lna_prtct_sttl_cnt
 * @details number of 16 MHz clocks for lna protect to deassert. MUST BE EVEN
 * @{
 */
#define MDM_TIA_DCCAL3__RF_POST_DCCAL_LNA_PRTCT_STTL_CNT__SHIFT               0
#define MDM_TIA_DCCAL3__RF_POST_DCCAL_LNA_PRTCT_STTL_CNT__WIDTH              10
#define MDM_TIA_DCCAL3__RF_POST_DCCAL_LNA_PRTCT_STTL_CNT__MASK      0x000003ffU
#define MDM_TIA_DCCAL3__RF_POST_DCCAL_LNA_PRTCT_STTL_CNT__READ(src) \
                    ((uint32_t)(src)\
                    & 0x000003ffU)
#define MDM_TIA_DCCAL3__RF_POST_DCCAL_LNA_PRTCT_STTL_CNT__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x000003ffU)
#define MDM_TIA_DCCAL3__RF_POST_DCCAL_LNA_PRTCT_STTL_CNT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000003ffU) | ((uint32_t)(src) &\
                    0x000003ffU)
#define MDM_TIA_DCCAL3__RF_POST_DCCAL_LNA_PRTCT_STTL_CNT__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000003ffU)))
#define MDM_TIA_DCCAL3__RF_POST_DCCAL_LNA_PRTCT_STTL_CNT__RESET_VALUE \
                    0x00000030U
/** @} */
#define MDM_TIA_DCCAL3__TYPE                                           uint32_t
#define MDM_TIA_DCCAL3__READ                                        0x000003ffU
#define MDM_TIA_DCCAL3__WRITE                                       0x000003ffU
#define MDM_TIA_DCCAL3__PRESERVED                                   0x00000000U
#define MDM_TIA_DCCAL3__RESET_VALUE                                 0x00000030U

#endif /* __MDM_TIA_DCCAL3_MACRO__ */

/** @} end of tia_dccal3 */

/* macros for BlueprintGlobalNameSpace::MDM_tia_dccal4 */
/**
 * @defgroup mdm_regs_core_tia_dccal4 tia_dccal4
 * @brief DC offset calibration control for TIA, set 4 for paris definitions.
 * @{
 */
#ifndef __MDM_TIA_DCCAL4_MACRO__
#define __MDM_TIA_DCCAL4_MACRO__

/* macros for field iq_ratio */
/**
 * @defgroup mdm_regs_core_iq_ratio_field iq_ratio_field
 * @brief macros for field iq_ratio
 * @details cross coupling ratio between i and q channel for 1 Mb/s; valid format u2.7 0.3 * 2^7
 * @{
 */
#define MDM_TIA_DCCAL4__IQ_RATIO__SHIFT                                       0
#define MDM_TIA_DCCAL4__IQ_RATIO__WIDTH                                       9
#define MDM_TIA_DCCAL4__IQ_RATIO__MASK                              0x000001ffU
#define MDM_TIA_DCCAL4__IQ_RATIO__READ(src)     ((uint32_t)(src) & 0x000001ffU)
#define MDM_TIA_DCCAL4__IQ_RATIO__WRITE(src)    ((uint32_t)(src) & 0x000001ffU)
#define MDM_TIA_DCCAL4__IQ_RATIO__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000001ffU) | ((uint32_t)(src) &\
                    0x000001ffU)
#define MDM_TIA_DCCAL4__IQ_RATIO__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000001ffU)))
#define MDM_TIA_DCCAL4__IQ_RATIO__RESET_VALUE                       0x00000026U
/** @} */

/* macros for field iq_ratio_twomeg */
/**
 * @defgroup mdm_regs_core_iq_ratio_twomeg_field iq_ratio_twomeg_field
 * @brief macros for field iq_ratio_twomeg
 * @details cross coupling ratio between i and q channel for 2 Mb/s; valid format u2.7 0.3 * 2^7
 * @{
 */
#define MDM_TIA_DCCAL4__IQ_RATIO_TWOMEG__SHIFT                                9
#define MDM_TIA_DCCAL4__IQ_RATIO_TWOMEG__WIDTH                                9
#define MDM_TIA_DCCAL4__IQ_RATIO_TWOMEG__MASK                       0x0003fe00U
#define MDM_TIA_DCCAL4__IQ_RATIO_TWOMEG__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0003fe00U) >> 9)
#define MDM_TIA_DCCAL4__IQ_RATIO_TWOMEG__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x0003fe00U)
#define MDM_TIA_DCCAL4__IQ_RATIO_TWOMEG__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0003fe00U) | (((uint32_t)(src) <<\
                    9) & 0x0003fe00U)
#define MDM_TIA_DCCAL4__IQ_RATIO_TWOMEG__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x0003fe00U)))
#define MDM_TIA_DCCAL4__IQ_RATIO_TWOMEG__RESET_VALUE                0x00000026U
/** @} */

/* macros for field dcoc_wdth */
/**
 * @defgroup mdm_regs_core_dcoc_wdth_field dcoc_wdth_field
 * @brief macros for field dcoc_wdth
 * @details 0 => 6, 1 => 7, 2 => 8
 * @{
 */
#define MDM_TIA_DCCAL4__DCOC_WDTH__SHIFT                                     18
#define MDM_TIA_DCCAL4__DCOC_WDTH__WIDTH                                      2
#define MDM_TIA_DCCAL4__DCOC_WDTH__MASK                             0x000c0000U
#define MDM_TIA_DCCAL4__DCOC_WDTH__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000c0000U) >> 18)
#define MDM_TIA_DCCAL4__DCOC_WDTH__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0x000c0000U)
#define MDM_TIA_DCCAL4__DCOC_WDTH__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000c0000U) | (((uint32_t)(src) <<\
                    18) & 0x000c0000U)
#define MDM_TIA_DCCAL4__DCOC_WDTH__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x000c0000U)))
#define MDM_TIA_DCCAL4__DCOC_WDTH__RESET_VALUE                      0x00000000U
/** @} */
#define MDM_TIA_DCCAL4__TYPE                                           uint32_t
#define MDM_TIA_DCCAL4__READ                                        0x000fffffU
#define MDM_TIA_DCCAL4__WRITE                                       0x000fffffU
#define MDM_TIA_DCCAL4__PRESERVED                                   0x00000000U
#define MDM_TIA_DCCAL4__RESET_VALUE                                 0x00004c26U

#endif /* __MDM_TIA_DCCAL4_MACRO__ */

/** @} end of tia_dccal4 */

/* macros for BlueprintGlobalNameSpace::MDM_pga_dccal */
/**
 * @defgroup mdm_regs_core_pga_dccal pga_dccal
 * @brief DC offset calibration control for PGA definitions.
 * @{
 */
#ifndef __MDM_PGA_DCCAL_MACRO__
#define __MDM_PGA_DCCAL_MACRO__

/* macros for field avg_only */
/**
 * @defgroup mdm_regs_core_avg_only_field avg_only_field
 * @brief macros for field avg_only
 * @details software trigger DC calibration start average only cal
 * @{
 */
#define MDM_PGA_DCCAL__AVG_ONLY__SHIFT                                        2
#define MDM_PGA_DCCAL__AVG_ONLY__WIDTH                                        1
#define MDM_PGA_DCCAL__AVG_ONLY__MASK                               0x00000004U
#define MDM_PGA_DCCAL__AVG_ONLY__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define MDM_PGA_DCCAL__AVG_ONLY__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define MDM_PGA_DCCAL__AVG_ONLY__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define MDM_PGA_DCCAL__AVG_ONLY__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define MDM_PGA_DCCAL__AVG_ONLY__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define MDM_PGA_DCCAL__AVG_ONLY__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define MDM_PGA_DCCAL__AVG_ONLY__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field avg_cnt_exp */
/**
 * @defgroup mdm_regs_core_avg_cnt_exp_field avg_cnt_exp_field
 * @brief macros for field avg_cnt_exp
 * @details 2's power number of samples to average; valid values [2-6]
 * @{
 */
#define MDM_PGA_DCCAL__AVG_CNT_EXP__SHIFT                                     4
#define MDM_PGA_DCCAL__AVG_CNT_EXP__WIDTH                                     3
#define MDM_PGA_DCCAL__AVG_CNT_EXP__MASK                            0x00000070U
#define MDM_PGA_DCCAL__AVG_CNT_EXP__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000070U) >> 4)
#define MDM_PGA_DCCAL__AVG_CNT_EXP__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x00000070U)
#define MDM_PGA_DCCAL__AVG_CNT_EXP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000070U) | (((uint32_t)(src) <<\
                    4) & 0x00000070U)
#define MDM_PGA_DCCAL__AVG_CNT_EXP__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x00000070U)))
#define MDM_PGA_DCCAL__AVG_CNT_EXP__RESET_VALUE                     0x00000003U
/** @} */

/* macros for field srch_bit_cnt */
/**
 * @defgroup mdm_regs_core_srch_bit_cnt_field srch_bit_cnt_field
 * @brief macros for field srch_bit_cnt
 * @details number of DC offset bits to search must be less than or equal to dcoc width
 * @{
 */
#define MDM_PGA_DCCAL__SRCH_BIT_CNT__SHIFT                                    7
#define MDM_PGA_DCCAL__SRCH_BIT_CNT__WIDTH                                    4
#define MDM_PGA_DCCAL__SRCH_BIT_CNT__MASK                           0x00000780U
#define MDM_PGA_DCCAL__SRCH_BIT_CNT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000780U) >> 7)
#define MDM_PGA_DCCAL__SRCH_BIT_CNT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 7) & 0x00000780U)
#define MDM_PGA_DCCAL__SRCH_BIT_CNT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000780U) | (((uint32_t)(src) <<\
                    7) & 0x00000780U)
#define MDM_PGA_DCCAL__SRCH_BIT_CNT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 7) & ~0x00000780U)))
#define MDM_PGA_DCCAL__SRCH_BIT_CNT__RESET_VALUE                    0x00000005U
/** @} */

/* macros for field msb */
/**
 * @defgroup mdm_regs_core_msb_field msb_field
 * @brief macros for field msb
 * @details 0 => 4, 1 => 5, 2 => 6, 3 => 7
 * @{
 */
#define MDM_PGA_DCCAL__MSB__SHIFT                                            12
#define MDM_PGA_DCCAL__MSB__WIDTH                                             3
#define MDM_PGA_DCCAL__MSB__MASK                                    0x00007000U
#define MDM_PGA_DCCAL__MSB__READ(src)   (((uint32_t)(src) & 0x00007000U) >> 12)
#define MDM_PGA_DCCAL__MSB__WRITE(src)  (((uint32_t)(src) << 12) & 0x00007000U)
#define MDM_PGA_DCCAL__MSB__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00007000U) | (((uint32_t)(src) <<\
                    12) & 0x00007000U)
#define MDM_PGA_DCCAL__MSB__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x00007000U)))
#define MDM_PGA_DCCAL__MSB__RESET_VALUE                             0x00000000U
/** @} */

/* macros for field iq_ratio */
/**
 * @defgroup mdm_regs_core_iq_ratio_field iq_ratio_field
 * @brief macros for field iq_ratio
 * @details cross coupling ratio between i and q channel for 1 Mb/s; valid format u1.7 1.75 * 2^7
 * @{
 */
#define MDM_PGA_DCCAL__IQ_RATIO__SHIFT                                       16
#define MDM_PGA_DCCAL__IQ_RATIO__WIDTH                                        8
#define MDM_PGA_DCCAL__IQ_RATIO__MASK                               0x00ff0000U
#define MDM_PGA_DCCAL__IQ_RATIO__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00ff0000U) >> 16)
#define MDM_PGA_DCCAL__IQ_RATIO__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x00ff0000U)
#define MDM_PGA_DCCAL__IQ_RATIO__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00ff0000U) | (((uint32_t)(src) <<\
                    16) & 0x00ff0000U)
#define MDM_PGA_DCCAL__IQ_RATIO__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x00ff0000U)))
#define MDM_PGA_DCCAL__IQ_RATIO__RESET_VALUE                        0x000000e0U
/** @} */

/* macros for field iq_ratio_twomeg */
/**
 * @defgroup mdm_regs_core_iq_ratio_twomeg_field iq_ratio_twomeg_field
 * @brief macros for field iq_ratio_twomeg
 * @details cross coupling ratio between i and q channel for 2 Mb/s; valid format u1.7 1.75 * 2^7
 * @{
 */
#define MDM_PGA_DCCAL__IQ_RATIO_TWOMEG__SHIFT                                24
#define MDM_PGA_DCCAL__IQ_RATIO_TWOMEG__WIDTH                                 8
#define MDM_PGA_DCCAL__IQ_RATIO_TWOMEG__MASK                        0xff000000U
#define MDM_PGA_DCCAL__IQ_RATIO_TWOMEG__READ(src) \
                    (((uint32_t)(src)\
                    & 0xff000000U) >> 24)
#define MDM_PGA_DCCAL__IQ_RATIO_TWOMEG__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0xff000000U)
#define MDM_PGA_DCCAL__IQ_RATIO_TWOMEG__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xff000000U) | (((uint32_t)(src) <<\
                    24) & 0xff000000U)
#define MDM_PGA_DCCAL__IQ_RATIO_TWOMEG__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0xff000000U)))
#define MDM_PGA_DCCAL__IQ_RATIO_TWOMEG__RESET_VALUE                 0x000000e0U
/** @} */
#define MDM_PGA_DCCAL__TYPE                                            uint32_t
#define MDM_PGA_DCCAL__READ                                         0xffff77f4U
#define MDM_PGA_DCCAL__WRITE                                        0xffff77f4U
#define MDM_PGA_DCCAL__PRESERVED                                    0x00000000U
#define MDM_PGA_DCCAL__RESET_VALUE                                  0xe0e002b0U

#endif /* __MDM_PGA_DCCAL_MACRO__ */

/** @} end of pga_dccal */

/* macros for BlueprintGlobalNameSpace::MDM_pga_dccal2 */
/**
 * @defgroup mdm_regs_core_pga_dccal2 pga_dccal2
 * @brief DC offset calibration control for PGA, set 2 definitions.
 * @{
 */
#ifndef __MDM_PGA_DCCAL2_MACRO__
#define __MDM_PGA_DCCAL2_MACRO__

/* macros for field rf_post_dccal_sttl_cnt */
/**
 * @defgroup mdm_regs_core_rf_post_dccal_sttl_cnt_field rf_post_dccal_sttl_cnt_field
 * @brief macros for field rf_post_dccal_sttl_cnt
 * @details number of 16 MHz clocks from rf to settle after caldc is deasserted. MUST BE EVEN
 * @{
 */
#define MDM_PGA_DCCAL2__RF_POST_DCCAL_STTL_CNT__SHIFT                         0
#define MDM_PGA_DCCAL2__RF_POST_DCCAL_STTL_CNT__WIDTH                        10
#define MDM_PGA_DCCAL2__RF_POST_DCCAL_STTL_CNT__MASK                0x000003ffU
#define MDM_PGA_DCCAL2__RF_POST_DCCAL_STTL_CNT__READ(src) \
                    ((uint32_t)(src)\
                    & 0x000003ffU)
#define MDM_PGA_DCCAL2__RF_POST_DCCAL_STTL_CNT__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x000003ffU)
#define MDM_PGA_DCCAL2__RF_POST_DCCAL_STTL_CNT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000003ffU) | ((uint32_t)(src) &\
                    0x000003ffU)
#define MDM_PGA_DCCAL2__RF_POST_DCCAL_STTL_CNT__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000003ffU)))
#define MDM_PGA_DCCAL2__RF_POST_DCCAL_STTL_CNT__RESET_VALUE         0x00000050U
/** @} */

/* macros for field rf_sttl_cnt */
/**
 * @defgroup mdm_regs_core_rf_sttl_cnt_field rf_sttl_cnt_field
 * @brief macros for field rf_sttl_cnt
 * @details number of 16 MHz clocks from rf to settle after pga gain change for 1 Mb/s. MUST BE EVEN
 * @{
 */
#define MDM_PGA_DCCAL2__RF_STTL_CNT__SHIFT                                   10
#define MDM_PGA_DCCAL2__RF_STTL_CNT__WIDTH                                   10
#define MDM_PGA_DCCAL2__RF_STTL_CNT__MASK                           0x000ffc00U
#define MDM_PGA_DCCAL2__RF_STTL_CNT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000ffc00U) >> 10)
#define MDM_PGA_DCCAL2__RF_STTL_CNT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x000ffc00U)
#define MDM_PGA_DCCAL2__RF_STTL_CNT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000ffc00U) | (((uint32_t)(src) <<\
                    10) & 0x000ffc00U)
#define MDM_PGA_DCCAL2__RF_STTL_CNT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x000ffc00U)))
#define MDM_PGA_DCCAL2__RF_STTL_CNT__RESET_VALUE                    0x00000010U
/** @} */

/* macros for field rf_sttl_cnt_twomeg */
/**
 * @defgroup mdm_regs_core_rf_sttl_cnt_twomeg_field rf_sttl_cnt_twomeg_field
 * @brief macros for field rf_sttl_cnt_twomeg
 * @details number of 16 MHz clocks from rf to settle after pga gain change for 2 Mb/s
 * @{
 */
#define MDM_PGA_DCCAL2__RF_STTL_CNT_TWOMEG__SHIFT                            20
#define MDM_PGA_DCCAL2__RF_STTL_CNT_TWOMEG__WIDTH                            10
#define MDM_PGA_DCCAL2__RF_STTL_CNT_TWOMEG__MASK                    0x3ff00000U
#define MDM_PGA_DCCAL2__RF_STTL_CNT_TWOMEG__READ(src) \
                    (((uint32_t)(src)\
                    & 0x3ff00000U) >> 20)
#define MDM_PGA_DCCAL2__RF_STTL_CNT_TWOMEG__WRITE(src) \
                    (((uint32_t)(src)\
                    << 20) & 0x3ff00000U)
#define MDM_PGA_DCCAL2__RF_STTL_CNT_TWOMEG__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x3ff00000U) | (((uint32_t)(src) <<\
                    20) & 0x3ff00000U)
#define MDM_PGA_DCCAL2__RF_STTL_CNT_TWOMEG__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x3ff00000U)))
#define MDM_PGA_DCCAL2__RF_STTL_CNT_TWOMEG__RESET_VALUE             0x00000010U
/** @} */
#define MDM_PGA_DCCAL2__TYPE                                           uint32_t
#define MDM_PGA_DCCAL2__READ                                        0x3fffffffU
#define MDM_PGA_DCCAL2__WRITE                                       0x3fffffffU
#define MDM_PGA_DCCAL2__PRESERVED                                   0x00000000U
#define MDM_PGA_DCCAL2__RESET_VALUE                                 0x01004050U

#endif /* __MDM_PGA_DCCAL2_MACRO__ */

/** @} end of pga_dccal2 */

/* macros for BlueprintGlobalNameSpace::MDM_pga_dccal3 */
/**
 * @defgroup mdm_regs_core_pga_dccal3 pga_dccal3
 * @brief DC offset calibration control for PGA, set 3 for paris definitions.
 * @{
 */
#ifndef __MDM_PGA_DCCAL3_MACRO__
#define __MDM_PGA_DCCAL3_MACRO__

/* macros for field rf_post_dccal_lna_prtct_sttl_cnt */
/**
 * @defgroup mdm_regs_core_rf_post_dccal_lna_prtct_sttl_cnt_field rf_post_dccal_lna_prtct_sttl_cnt_field
 * @brief macros for field rf_post_dccal_lna_prtct_sttl_cnt
 * @details number of 16 MHz clocks for lna protect to deassert. MUST BE EVEN
 * @{
 */
#define MDM_PGA_DCCAL3__RF_POST_DCCAL_LNA_PRTCT_STTL_CNT__SHIFT               0
#define MDM_PGA_DCCAL3__RF_POST_DCCAL_LNA_PRTCT_STTL_CNT__WIDTH              10
#define MDM_PGA_DCCAL3__RF_POST_DCCAL_LNA_PRTCT_STTL_CNT__MASK      0x000003ffU
#define MDM_PGA_DCCAL3__RF_POST_DCCAL_LNA_PRTCT_STTL_CNT__READ(src) \
                    ((uint32_t)(src)\
                    & 0x000003ffU)
#define MDM_PGA_DCCAL3__RF_POST_DCCAL_LNA_PRTCT_STTL_CNT__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x000003ffU)
#define MDM_PGA_DCCAL3__RF_POST_DCCAL_LNA_PRTCT_STTL_CNT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000003ffU) | ((uint32_t)(src) &\
                    0x000003ffU)
#define MDM_PGA_DCCAL3__RF_POST_DCCAL_LNA_PRTCT_STTL_CNT__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000003ffU)))
#define MDM_PGA_DCCAL3__RF_POST_DCCAL_LNA_PRTCT_STTL_CNT__RESET_VALUE \
                    0x00000030U
/** @} */

/* macros for field cal_gain_scl */
/**
 * @defgroup mdm_regs_core_cal_gain_scl_field cal_gain_scl_field
 * @brief macros for field cal_gain_scl
 * @details dc offset scaling factor based on current gain and cal gain; valid format u0.8 yow need to determine the default value round(2^4 * 2^8/(1 + 224/128 + 1014/64))
 * @{
 */
#define MDM_PGA_DCCAL3__CAL_GAIN_SCL__SHIFT                                  10
#define MDM_PGA_DCCAL3__CAL_GAIN_SCL__WIDTH                                   8
#define MDM_PGA_DCCAL3__CAL_GAIN_SCL__MASK                          0x0003fc00U
#define MDM_PGA_DCCAL3__CAL_GAIN_SCL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0003fc00U) >> 10)
#define MDM_PGA_DCCAL3__CAL_GAIN_SCL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x0003fc00U)
#define MDM_PGA_DCCAL3__CAL_GAIN_SCL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0003fc00U) | (((uint32_t)(src) <<\
                    10) & 0x0003fc00U)
#define MDM_PGA_DCCAL3__CAL_GAIN_SCL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x0003fc00U)))
#define MDM_PGA_DCCAL3__CAL_GAIN_SCL__RESET_VALUE                   0x000000d8U
/** @} */

/* macros for field cal_gain_scl_ls */
/**
 * @defgroup mdm_regs_core_cal_gain_scl_ls_field cal_gain_scl_ls_field
 * @brief macros for field cal_gain_scl_ls
 * @details left shift cal_gain_scl to shift the non zero bit to msb; yow need to determine the default value floor(log2(1 + 224/128 + 1014/64))
 * @{
 */
#define MDM_PGA_DCCAL3__CAL_GAIN_SCL_LS__SHIFT                               18
#define MDM_PGA_DCCAL3__CAL_GAIN_SCL_LS__WIDTH                                3
#define MDM_PGA_DCCAL3__CAL_GAIN_SCL_LS__MASK                       0x001c0000U
#define MDM_PGA_DCCAL3__CAL_GAIN_SCL_LS__READ(src) \
                    (((uint32_t)(src)\
                    & 0x001c0000U) >> 18)
#define MDM_PGA_DCCAL3__CAL_GAIN_SCL_LS__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0x001c0000U)
#define MDM_PGA_DCCAL3__CAL_GAIN_SCL_LS__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x001c0000U) | (((uint32_t)(src) <<\
                    18) & 0x001c0000U)
#define MDM_PGA_DCCAL3__CAL_GAIN_SCL_LS__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x001c0000U)))
#define MDM_PGA_DCCAL3__CAL_GAIN_SCL_LS__RESET_VALUE                0x00000004U
/** @} */

/* macros for field cal_gain_scl_lp */
/**
 * @defgroup mdm_regs_core_cal_gain_scl_lp_field cal_gain_scl_lp_field
 * @brief macros for field cal_gain_scl_lp
 * @details dc offset scaling factor based on current gain and cal gain in low power mode; valid format u0.8 yow need to determine the default value round(2^4 * 2^8/(1 + 1014/64))
 * @{
 */
#define MDM_PGA_DCCAL3__CAL_GAIN_SCL_LP__SHIFT                               21
#define MDM_PGA_DCCAL3__CAL_GAIN_SCL_LP__WIDTH                                8
#define MDM_PGA_DCCAL3__CAL_GAIN_SCL_LP__MASK                       0x1fe00000U
#define MDM_PGA_DCCAL3__CAL_GAIN_SCL_LP__READ(src) \
                    (((uint32_t)(src)\
                    & 0x1fe00000U) >> 21)
#define MDM_PGA_DCCAL3__CAL_GAIN_SCL_LP__WRITE(src) \
                    (((uint32_t)(src)\
                    << 21) & 0x1fe00000U)
#define MDM_PGA_DCCAL3__CAL_GAIN_SCL_LP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x1fe00000U) | (((uint32_t)(src) <<\
                    21) & 0x1fe00000U)
#define MDM_PGA_DCCAL3__CAL_GAIN_SCL_LP__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 21) & ~0x1fe00000U)))
#define MDM_PGA_DCCAL3__CAL_GAIN_SCL_LP__RESET_VALUE                0x000000f3U
/** @} */

/* macros for field cal_gain_scl_lp_ls */
/**
 * @defgroup mdm_regs_core_cal_gain_scl_lp_ls_field cal_gain_scl_lp_ls_field
 * @brief macros for field cal_gain_scl_lp_ls
 * @details left shift cal_gain_scl_lp to shift the non zero bit to msb; yow need to determine the default value floor(log2(1 + 1014/64))
 * @{
 */
#define MDM_PGA_DCCAL3__CAL_GAIN_SCL_LP_LS__SHIFT                            29
#define MDM_PGA_DCCAL3__CAL_GAIN_SCL_LP_LS__WIDTH                             3
#define MDM_PGA_DCCAL3__CAL_GAIN_SCL_LP_LS__MASK                    0xe0000000U
#define MDM_PGA_DCCAL3__CAL_GAIN_SCL_LP_LS__READ(src) \
                    (((uint32_t)(src)\
                    & 0xe0000000U) >> 29)
#define MDM_PGA_DCCAL3__CAL_GAIN_SCL_LP_LS__WRITE(src) \
                    (((uint32_t)(src)\
                    << 29) & 0xe0000000U)
#define MDM_PGA_DCCAL3__CAL_GAIN_SCL_LP_LS__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xe0000000U) | (((uint32_t)(src) <<\
                    29) & 0xe0000000U)
#define MDM_PGA_DCCAL3__CAL_GAIN_SCL_LP_LS__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 29) & ~0xe0000000U)))
#define MDM_PGA_DCCAL3__CAL_GAIN_SCL_LP_LS__RESET_VALUE             0x00000004U
/** @} */
#define MDM_PGA_DCCAL3__TYPE                                           uint32_t
#define MDM_PGA_DCCAL3__READ                                        0xffffffffU
#define MDM_PGA_DCCAL3__WRITE                                       0xffffffffU
#define MDM_PGA_DCCAL3__PRESERVED                                   0x00000000U
#define MDM_PGA_DCCAL3__RESET_VALUE                                 0x9e736030U

#endif /* __MDM_PGA_DCCAL3_MACRO__ */

/** @} end of pga_dccal3 */

/* macros for BlueprintGlobalNameSpace::MDM_pga_dccal4 */
/**
 * @defgroup mdm_regs_core_pga_dccal4 pga_dccal4
 * @brief DC offset calibration control for PGA, set 4 for paris definitions.
 * @{
 */
#ifndef __MDM_PGA_DCCAL4_MACRO__
#define __MDM_PGA_DCCAL4_MACRO__

/* macros for field iq_ratio */
/**
 * @defgroup mdm_regs_core_iq_ratio_field iq_ratio_field
 * @brief macros for field iq_ratio
 * @details cross coupling ratio between i and q channel for 1 Mb/s used during gain based residue dc correction state; valid format s2.7 1.75 * 2^7
 * @{
 */
#define MDM_PGA_DCCAL4__IQ_RATIO__SHIFT                                       0
#define MDM_PGA_DCCAL4__IQ_RATIO__WIDTH                                       9
#define MDM_PGA_DCCAL4__IQ_RATIO__MASK                              0x000001ffU
#define MDM_PGA_DCCAL4__IQ_RATIO__READ(src)     ((uint32_t)(src) & 0x000001ffU)
#define MDM_PGA_DCCAL4__IQ_RATIO__WRITE(src)    ((uint32_t)(src) & 0x000001ffU)
#define MDM_PGA_DCCAL4__IQ_RATIO__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000001ffU) | ((uint32_t)(src) &\
                    0x000001ffU)
#define MDM_PGA_DCCAL4__IQ_RATIO__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000001ffU)))
#define MDM_PGA_DCCAL4__IQ_RATIO__RESET_VALUE                       0x000000e0U
/** @} */

/* macros for field iq_ratio_twomeg */
/**
 * @defgroup mdm_regs_core_iq_ratio_twomeg_field iq_ratio_twomeg_field
 * @brief macros for field iq_ratio_twomeg
 * @details cross coupling ratio between i and q channel for 2 Mb/s used during gain based residue dc correction state; valid format s2.7 1.75 * 2^7
 * @{
 */
#define MDM_PGA_DCCAL4__IQ_RATIO_TWOMEG__SHIFT                               16
#define MDM_PGA_DCCAL4__IQ_RATIO_TWOMEG__WIDTH                                9
#define MDM_PGA_DCCAL4__IQ_RATIO_TWOMEG__MASK                       0x01ff0000U
#define MDM_PGA_DCCAL4__IQ_RATIO_TWOMEG__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01ff0000U) >> 16)
#define MDM_PGA_DCCAL4__IQ_RATIO_TWOMEG__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x01ff0000U)
#define MDM_PGA_DCCAL4__IQ_RATIO_TWOMEG__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01ff0000U) | (((uint32_t)(src) <<\
                    16) & 0x01ff0000U)
#define MDM_PGA_DCCAL4__IQ_RATIO_TWOMEG__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x01ff0000U)))
#define MDM_PGA_DCCAL4__IQ_RATIO_TWOMEG__RESET_VALUE                0x000000e0U
/** @} */
#define MDM_PGA_DCCAL4__TYPE                                           uint32_t
#define MDM_PGA_DCCAL4__READ                                        0x01ff01ffU
#define MDM_PGA_DCCAL4__WRITE                                       0x01ff01ffU
#define MDM_PGA_DCCAL4__PRESERVED                                   0x00000000U
#define MDM_PGA_DCCAL4__RESET_VALUE                                 0x00e000e0U

#endif /* __MDM_PGA_DCCAL4_MACRO__ */

/** @} end of pga_dccal4 */

/* macros for BlueprintGlobalNameSpace::MDM_pga_dccal5 */
/**
 * @defgroup mdm_regs_core_pga_dccal5 pga_dccal5
 * @brief DC offset calibration control for PGA, set 5 for paris definitions.
 * @{
 */
#ifndef __MDM_PGA_DCCAL5_MACRO__
#define __MDM_PGA_DCCAL5_MACRO__

/* macros for field nm_to_lpm_scl */
/**
 * @defgroup mdm_regs_core_nm_to_lpm_scl_field nm_to_lpm_scl_field
 * @brief macros for field nm_to_lpm_scl
 * @details dc offset scaling factor based on cal gain and iq_ratio in normal mode; valid format u1.7 yow need to determine the default value round(2^7*(1 + 1014/64)/(1 + 224/128 + 1014/64))
 * @{
 */
#define MDM_PGA_DCCAL5__NM_TO_LPM_SCL__SHIFT                                  0
#define MDM_PGA_DCCAL5__NM_TO_LPM_SCL__WIDTH                                  8
#define MDM_PGA_DCCAL5__NM_TO_LPM_SCL__MASK                         0x000000ffU
#define MDM_PGA_DCCAL5__NM_TO_LPM_SCL__READ(src) \
                    ((uint32_t)(src)\
                    & 0x000000ffU)
#define MDM_PGA_DCCAL5__NM_TO_LPM_SCL__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x000000ffU)
#define MDM_PGA_DCCAL5__NM_TO_LPM_SCL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000ffU) | ((uint32_t)(src) &\
                    0x000000ffU)
#define MDM_PGA_DCCAL5__NM_TO_LPM_SCL__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000000ffU)))
#define MDM_PGA_DCCAL5__NM_TO_LPM_SCL__RESET_VALUE                  0x00000074U
/** @} */
#define MDM_PGA_DCCAL5__TYPE                                           uint32_t
#define MDM_PGA_DCCAL5__READ                                        0x000000ffU
#define MDM_PGA_DCCAL5__WRITE                                       0x000000ffU
#define MDM_PGA_DCCAL5__PRESERVED                                   0x00000000U
#define MDM_PGA_DCCAL5__RESET_VALUE                                 0x00000074U

#endif /* __MDM_PGA_DCCAL5_MACRO__ */

/** @} end of pga_dccal5 */

/* macros for BlueprintGlobalNameSpace::MDM_notch_dccal */
/**
 * @defgroup mdm_regs_core_notch_dccal notch_dccal
 * @brief DC offset calibration control for notch filter definitions.
 * @{
 */
#ifndef __MDM_NOTCH_DCCAL_MACRO__
#define __MDM_NOTCH_DCCAL_MACRO__

/* macros for field avg_only */
/**
 * @defgroup mdm_regs_core_avg_only_field avg_only_field
 * @brief macros for field avg_only
 * @details software trigger DC calibration start average only cal
 * @{
 */
#define MDM_NOTCH_DCCAL__AVG_ONLY__SHIFT                                      2
#define MDM_NOTCH_DCCAL__AVG_ONLY__WIDTH                                      1
#define MDM_NOTCH_DCCAL__AVG_ONLY__MASK                             0x00000004U
#define MDM_NOTCH_DCCAL__AVG_ONLY__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define MDM_NOTCH_DCCAL__AVG_ONLY__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define MDM_NOTCH_DCCAL__AVG_ONLY__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define MDM_NOTCH_DCCAL__AVG_ONLY__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define MDM_NOTCH_DCCAL__AVG_ONLY__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define MDM_NOTCH_DCCAL__AVG_ONLY__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define MDM_NOTCH_DCCAL__AVG_ONLY__RESET_VALUE                      0x00000000U
/** @} */

/* macros for field avg_cnt_exp */
/**
 * @defgroup mdm_regs_core_avg_cnt_exp_field avg_cnt_exp_field
 * @brief macros for field avg_cnt_exp
 * @details 2's power number of samples to average; valid values [2-6]
 * @{
 */
#define MDM_NOTCH_DCCAL__AVG_CNT_EXP__SHIFT                                   4
#define MDM_NOTCH_DCCAL__AVG_CNT_EXP__WIDTH                                   3
#define MDM_NOTCH_DCCAL__AVG_CNT_EXP__MASK                          0x00000070U
#define MDM_NOTCH_DCCAL__AVG_CNT_EXP__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000070U) >> 4)
#define MDM_NOTCH_DCCAL__AVG_CNT_EXP__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x00000070U)
#define MDM_NOTCH_DCCAL__AVG_CNT_EXP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000070U) | (((uint32_t)(src) <<\
                    4) & 0x00000070U)
#define MDM_NOTCH_DCCAL__AVG_CNT_EXP__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x00000070U)))
#define MDM_NOTCH_DCCAL__AVG_CNT_EXP__RESET_VALUE                   0x00000003U
/** @} */

/* macros for field srch_bit_cnt */
/**
 * @defgroup mdm_regs_core_srch_bit_cnt_field srch_bit_cnt_field
 * @brief macros for field srch_bit_cnt
 * @details number of ctune bits to search
 * @{
 */
#define MDM_NOTCH_DCCAL__SRCH_BIT_CNT__SHIFT                                  7
#define MDM_NOTCH_DCCAL__SRCH_BIT_CNT__WIDTH                                  4
#define MDM_NOTCH_DCCAL__SRCH_BIT_CNT__MASK                         0x00000780U
#define MDM_NOTCH_DCCAL__SRCH_BIT_CNT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000780U) >> 7)
#define MDM_NOTCH_DCCAL__SRCH_BIT_CNT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 7) & 0x00000780U)
#define MDM_NOTCH_DCCAL__SRCH_BIT_CNT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000780U) | (((uint32_t)(src) <<\
                    7) & 0x00000780U)
#define MDM_NOTCH_DCCAL__SRCH_BIT_CNT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 7) & ~0x00000780U)))
#define MDM_NOTCH_DCCAL__SRCH_BIT_CNT__RESET_VALUE                  0x00000006U
/** @} */
#define MDM_NOTCH_DCCAL__TYPE                                          uint32_t
#define MDM_NOTCH_DCCAL__READ                                       0x000007f4U
#define MDM_NOTCH_DCCAL__WRITE                                      0x000007f4U
#define MDM_NOTCH_DCCAL__PRESERVED                                  0x00000000U
#define MDM_NOTCH_DCCAL__RESET_VALUE                                0x00000330U

#endif /* __MDM_NOTCH_DCCAL_MACRO__ */

/** @} end of notch_dccal */

/* macros for BlueprintGlobalNameSpace::MDM_notch_dccal2 */
/**
 * @defgroup mdm_regs_core_notch_dccal2 notch_dccal2
 * @brief DC offset calibration control for notch filter, set 2 definitions.
 * @{
 */
#ifndef __MDM_NOTCH_DCCAL2_MACRO__
#define __MDM_NOTCH_DCCAL2_MACRO__

/* macros for field rf_post_dccal_sttl_cnt */
/**
 * @defgroup mdm_regs_core_rf_post_dccal_sttl_cnt_field rf_post_dccal_sttl_cnt_field
 * @brief macros for field rf_post_dccal_sttl_cnt
 * @details number of 16 MHz clocks from rf to settle after caldc is deasserted. MUST BE EVEN
 * @{
 */
#define MDM_NOTCH_DCCAL2__RF_POST_DCCAL_STTL_CNT__SHIFT                       0
#define MDM_NOTCH_DCCAL2__RF_POST_DCCAL_STTL_CNT__WIDTH                      10
#define MDM_NOTCH_DCCAL2__RF_POST_DCCAL_STTL_CNT__MASK              0x000003ffU
#define MDM_NOTCH_DCCAL2__RF_POST_DCCAL_STTL_CNT__READ(src) \
                    ((uint32_t)(src)\
                    & 0x000003ffU)
#define MDM_NOTCH_DCCAL2__RF_POST_DCCAL_STTL_CNT__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x000003ffU)
#define MDM_NOTCH_DCCAL2__RF_POST_DCCAL_STTL_CNT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000003ffU) | ((uint32_t)(src) &\
                    0x000003ffU)
#define MDM_NOTCH_DCCAL2__RF_POST_DCCAL_STTL_CNT__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000003ffU)))
#define MDM_NOTCH_DCCAL2__RF_POST_DCCAL_STTL_CNT__RESET_VALUE       0x00000050U
/** @} */

/* macros for field rf_sttl_cnt */
/**
 * @defgroup mdm_regs_core_rf_sttl_cnt_field rf_sttl_cnt_field
 * @brief macros for field rf_sttl_cnt
 * @details number of 16 MHz clocks from rf to settle after pga gain change for 1 Mb/s. MUST BE EVEN
 * @{
 */
#define MDM_NOTCH_DCCAL2__RF_STTL_CNT__SHIFT                                 10
#define MDM_NOTCH_DCCAL2__RF_STTL_CNT__WIDTH                                 10
#define MDM_NOTCH_DCCAL2__RF_STTL_CNT__MASK                         0x000ffc00U
#define MDM_NOTCH_DCCAL2__RF_STTL_CNT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000ffc00U) >> 10)
#define MDM_NOTCH_DCCAL2__RF_STTL_CNT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x000ffc00U)
#define MDM_NOTCH_DCCAL2__RF_STTL_CNT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000ffc00U) | (((uint32_t)(src) <<\
                    10) & 0x000ffc00U)
#define MDM_NOTCH_DCCAL2__RF_STTL_CNT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x000ffc00U)))
#define MDM_NOTCH_DCCAL2__RF_STTL_CNT__RESET_VALUE                  0x00000010U
/** @} */

/* macros for field rf_sttl_cnt_twomeg */
/**
 * @defgroup mdm_regs_core_rf_sttl_cnt_twomeg_field rf_sttl_cnt_twomeg_field
 * @brief macros for field rf_sttl_cnt_twomeg
 * @details number of 16 MHz clocks from rf to settle after pga gain change for 2 Mb/s
 * @{
 */
#define MDM_NOTCH_DCCAL2__RF_STTL_CNT_TWOMEG__SHIFT                          20
#define MDM_NOTCH_DCCAL2__RF_STTL_CNT_TWOMEG__WIDTH                          10
#define MDM_NOTCH_DCCAL2__RF_STTL_CNT_TWOMEG__MASK                  0x3ff00000U
#define MDM_NOTCH_DCCAL2__RF_STTL_CNT_TWOMEG__READ(src) \
                    (((uint32_t)(src)\
                    & 0x3ff00000U) >> 20)
#define MDM_NOTCH_DCCAL2__RF_STTL_CNT_TWOMEG__WRITE(src) \
                    (((uint32_t)(src)\
                    << 20) & 0x3ff00000U)
#define MDM_NOTCH_DCCAL2__RF_STTL_CNT_TWOMEG__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x3ff00000U) | (((uint32_t)(src) <<\
                    20) & 0x3ff00000U)
#define MDM_NOTCH_DCCAL2__RF_STTL_CNT_TWOMEG__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x3ff00000U)))
#define MDM_NOTCH_DCCAL2__RF_STTL_CNT_TWOMEG__RESET_VALUE           0x00000010U
/** @} */
#define MDM_NOTCH_DCCAL2__TYPE                                         uint32_t
#define MDM_NOTCH_DCCAL2__READ                                      0x3fffffffU
#define MDM_NOTCH_DCCAL2__WRITE                                     0x3fffffffU
#define MDM_NOTCH_DCCAL2__PRESERVED                                 0x00000000U
#define MDM_NOTCH_DCCAL2__RESET_VALUE                               0x01004050U

#endif /* __MDM_NOTCH_DCCAL2_MACRO__ */

/** @} end of notch_dccal2 */

/* macros for BlueprintGlobalNameSpace::MDM_notch_dccal3 */
/**
 * @defgroup mdm_regs_core_notch_dccal3 notch_dccal3
 * @brief DC offset calibration control for notch filter, set 3 for paris definitions.
 * @{
 */
#ifndef __MDM_NOTCH_DCCAL3_MACRO__
#define __MDM_NOTCH_DCCAL3_MACRO__

/* macros for field rf_post_dccal_lna_prtct_sttl_cnt */
/**
 * @defgroup mdm_regs_core_rf_post_dccal_lna_prtct_sttl_cnt_field rf_post_dccal_lna_prtct_sttl_cnt_field
 * @brief macros for field rf_post_dccal_lna_prtct_sttl_cnt
 * @details number of 16 MHz clocks for lna protect to deassert. MUST BE EVEN
 * @{
 */
#define MDM_NOTCH_DCCAL3__RF_POST_DCCAL_LNA_PRTCT_STTL_CNT__SHIFT             0
#define MDM_NOTCH_DCCAL3__RF_POST_DCCAL_LNA_PRTCT_STTL_CNT__WIDTH            10
#define MDM_NOTCH_DCCAL3__RF_POST_DCCAL_LNA_PRTCT_STTL_CNT__MASK    0x000003ffU
#define MDM_NOTCH_DCCAL3__RF_POST_DCCAL_LNA_PRTCT_STTL_CNT__READ(src) \
                    ((uint32_t)(src)\
                    & 0x000003ffU)
#define MDM_NOTCH_DCCAL3__RF_POST_DCCAL_LNA_PRTCT_STTL_CNT__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x000003ffU)
#define MDM_NOTCH_DCCAL3__RF_POST_DCCAL_LNA_PRTCT_STTL_CNT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000003ffU) | ((uint32_t)(src) &\
                    0x000003ffU)
#define MDM_NOTCH_DCCAL3__RF_POST_DCCAL_LNA_PRTCT_STTL_CNT__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000003ffU)))
#define MDM_NOTCH_DCCAL3__RF_POST_DCCAL_LNA_PRTCT_STTL_CNT__RESET_VALUE \
                    0x00000030U
/** @} */
#define MDM_NOTCH_DCCAL3__TYPE                                         uint32_t
#define MDM_NOTCH_DCCAL3__READ                                      0x000003ffU
#define MDM_NOTCH_DCCAL3__WRITE                                     0x000003ffU
#define MDM_NOTCH_DCCAL3__PRESERVED                                 0x00000000U
#define MDM_NOTCH_DCCAL3__RESET_VALUE                               0x00000030U

#endif /* __MDM_NOTCH_DCCAL3_MACRO__ */

/** @} end of notch_dccal3 */

/* macros for BlueprintGlobalNameSpace::MDM_dcofftrk */
/**
 * @defgroup mdm_regs_core_dcofftrk dcofftrk
 * @brief DC offset tracking definitions.
 * @{
 */
#ifndef __MDM_DCOFFTRK_MACRO__
#define __MDM_DCOFFTRK_MACRO__

/* macros for field en */
/**
 * @defgroup mdm_regs_core_en_field en_field
 * @brief macros for field en
 * @details Enable tracking
 * @{
 */
#define MDM_DCOFFTRK__EN__SHIFT                                               0
#define MDM_DCOFFTRK__EN__WIDTH                                               1
#define MDM_DCOFFTRK__EN__MASK                                      0x00000001U
#define MDM_DCOFFTRK__EN__READ(src)             ((uint32_t)(src) & 0x00000001U)
#define MDM_DCOFFTRK__EN__WRITE(src)            ((uint32_t)(src) & 0x00000001U)
#define MDM_DCOFFTRK__EN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define MDM_DCOFFTRK__EN__VERIFY(src)     (!(((uint32_t)(src) & ~0x00000001U)))
#define MDM_DCOFFTRK__EN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define MDM_DCOFFTRK__EN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define MDM_DCOFFTRK__EN__RESET_VALUE                               0x00000001U
/** @} */

/* macros for field corr_agc_en */
/**
 * @defgroup mdm_regs_core_corr_agc_en_field corr_agc_en_field
 * @brief macros for field corr_agc_en
 * @details Enable correction based on tracking
 * @{
 */
#define MDM_DCOFFTRK__CORR_AGC_EN__SHIFT                                      1
#define MDM_DCOFFTRK__CORR_AGC_EN__WIDTH                                      1
#define MDM_DCOFFTRK__CORR_AGC_EN__MASK                             0x00000002U
#define MDM_DCOFFTRK__CORR_AGC_EN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define MDM_DCOFFTRK__CORR_AGC_EN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define MDM_DCOFFTRK__CORR_AGC_EN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define MDM_DCOFFTRK__CORR_AGC_EN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define MDM_DCOFFTRK__CORR_AGC_EN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define MDM_DCOFFTRK__CORR_AGC_EN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define MDM_DCOFFTRK__CORR_AGC_EN__RESET_VALUE                      0x00000001U
/** @} */

/* macros for field corr_syncdemod_en */
/**
 * @defgroup mdm_regs_core_corr_syncdemod_en_field corr_syncdemod_en_field
 * @brief macros for field corr_syncdemod_en
 * @details Enable correction based on tracking
 * @{
 */
#define MDM_DCOFFTRK__CORR_SYNCDEMOD_EN__SHIFT                                2
#define MDM_DCOFFTRK__CORR_SYNCDEMOD_EN__WIDTH                                1
#define MDM_DCOFFTRK__CORR_SYNCDEMOD_EN__MASK                       0x00000004U
#define MDM_DCOFFTRK__CORR_SYNCDEMOD_EN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define MDM_DCOFFTRK__CORR_SYNCDEMOD_EN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define MDM_DCOFFTRK__CORR_SYNCDEMOD_EN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define MDM_DCOFFTRK__CORR_SYNCDEMOD_EN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define MDM_DCOFFTRK__CORR_SYNCDEMOD_EN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define MDM_DCOFFTRK__CORR_SYNCDEMOD_EN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define MDM_DCOFFTRK__CORR_SYNCDEMOD_EN__RESET_VALUE                0x00000001U
/** @} */

/* macros for field mu1 */
/**
 * @defgroup mdm_regs_core_mu1_field mu1_field
 * @brief macros for field mu1
 * @details First gear mu: Encoding is 2^-(mu1+2)
 * @{
 */
#define MDM_DCOFFTRK__MU1__SHIFT                                              3
#define MDM_DCOFFTRK__MU1__WIDTH                                              3
#define MDM_DCOFFTRK__MU1__MASK                                     0x00000038U
#define MDM_DCOFFTRK__MU1__READ(src)     (((uint32_t)(src) & 0x00000038U) >> 3)
#define MDM_DCOFFTRK__MU1__WRITE(src)    (((uint32_t)(src) << 3) & 0x00000038U)
#define MDM_DCOFFTRK__MU1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000038U) | (((uint32_t)(src) <<\
                    3) & 0x00000038U)
#define MDM_DCOFFTRK__MU1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000038U)))
#define MDM_DCOFFTRK__MU1__RESET_VALUE                              0x00000002U
/** @} */

/* macros for field mu2 */
/**
 * @defgroup mdm_regs_core_mu2_field mu2_field
 * @brief macros for field mu2
 * @details Second gear mu: Encoding is 2^-(mu2+2)
 * @{
 */
#define MDM_DCOFFTRK__MU2__SHIFT                                              6
#define MDM_DCOFFTRK__MU2__WIDTH                                              3
#define MDM_DCOFFTRK__MU2__MASK                                     0x000001c0U
#define MDM_DCOFFTRK__MU2__READ(src)     (((uint32_t)(src) & 0x000001c0U) >> 6)
#define MDM_DCOFFTRK__MU2__WRITE(src)    (((uint32_t)(src) << 6) & 0x000001c0U)
#define MDM_DCOFFTRK__MU2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000001c0U) | (((uint32_t)(src) <<\
                    6) & 0x000001c0U)
#define MDM_DCOFFTRK__MU2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 6) & ~0x000001c0U)))
#define MDM_DCOFFTRK__MU2__RESET_VALUE                              0x00000004U
/** @} */

/* macros for field mu3 */
/**
 * @defgroup mdm_regs_core_mu3_field mu3_field
 * @brief macros for field mu3
 * @details Third gear mu: Encoding is 2^-(mu3+2)
 * @{
 */
#define MDM_DCOFFTRK__MU3__SHIFT                                              9
#define MDM_DCOFFTRK__MU3__WIDTH                                              3
#define MDM_DCOFFTRK__MU3__MASK                                     0x00000e00U
#define MDM_DCOFFTRK__MU3__READ(src)     (((uint32_t)(src) & 0x00000e00U) >> 9)
#define MDM_DCOFFTRK__MU3__WRITE(src)    (((uint32_t)(src) << 9) & 0x00000e00U)
#define MDM_DCOFFTRK__MU3__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000e00U) | (((uint32_t)(src) <<\
                    9) & 0x00000e00U)
#define MDM_DCOFFTRK__MU3__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x00000e00U)))
#define MDM_DCOFFTRK__MU3__RESET_VALUE                              0x00000006U
/** @} */

/* macros for field mu_count1 */
/**
 * @defgroup mdm_regs_core_mu_count1_field mu_count1_field
 * @brief macros for field mu_count1
 * @details (mu_count1 * 8) = number of 16 MHz samples to switch to gear 2
 * @{
 */
#define MDM_DCOFFTRK__MU_COUNT1__SHIFT                                       12
#define MDM_DCOFFTRK__MU_COUNT1__WIDTH                                        6
#define MDM_DCOFFTRK__MU_COUNT1__MASK                               0x0003f000U
#define MDM_DCOFFTRK__MU_COUNT1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0003f000U) >> 12)
#define MDM_DCOFFTRK__MU_COUNT1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x0003f000U)
#define MDM_DCOFFTRK__MU_COUNT1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0003f000U) | (((uint32_t)(src) <<\
                    12) & 0x0003f000U)
#define MDM_DCOFFTRK__MU_COUNT1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x0003f000U)))
#define MDM_DCOFFTRK__MU_COUNT1__RESET_VALUE                        0x00000002U
/** @} */

/* macros for field mu_count2 */
/**
 * @defgroup mdm_regs_core_mu_count2_field mu_count2_field
 * @brief macros for field mu_count2
 * @details (mu_count2 * 8) = number of 16 MHz samples to switch to gear 3. (Includes gear1 + gear2). MUST BE GREATER THAN MU_COUNT1
 * @{
 */
#define MDM_DCOFFTRK__MU_COUNT2__SHIFT                                       18
#define MDM_DCOFFTRK__MU_COUNT2__WIDTH                                        6
#define MDM_DCOFFTRK__MU_COUNT2__MASK                               0x00fc0000U
#define MDM_DCOFFTRK__MU_COUNT2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00fc0000U) >> 18)
#define MDM_DCOFFTRK__MU_COUNT2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0x00fc0000U)
#define MDM_DCOFFTRK__MU_COUNT2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00fc0000U) | (((uint32_t)(src) <<\
                    18) & 0x00fc0000U)
#define MDM_DCOFFTRK__MU_COUNT2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x00fc0000U)))
#define MDM_DCOFFTRK__MU_COUNT2__RESET_VALUE                        0x00000004U
/** @} */

/* macros for field corr_delay_idx */
/**
 * @defgroup mdm_regs_core_corr_delay_idx_field corr_delay_idx_field
 * @brief macros for field corr_delay_idx
 * @details Correction is applied (8 * corr_delay_idx) 16 MHz samples after tracking reset is released
 * @{
 */
#define MDM_DCOFFTRK__CORR_DELAY_IDX__SHIFT                                  24
#define MDM_DCOFFTRK__CORR_DELAY_IDX__WIDTH                                   3
#define MDM_DCOFFTRK__CORR_DELAY_IDX__MASK                          0x07000000U
#define MDM_DCOFFTRK__CORR_DELAY_IDX__READ(src) \
                    (((uint32_t)(src)\
                    & 0x07000000U) >> 24)
#define MDM_DCOFFTRK__CORR_DELAY_IDX__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x07000000U)
#define MDM_DCOFFTRK__CORR_DELAY_IDX__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x07000000U) | (((uint32_t)(src) <<\
                    24) & 0x07000000U)
#define MDM_DCOFFTRK__CORR_DELAY_IDX__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x07000000U)))
#define MDM_DCOFFTRK__CORR_DELAY_IDX__RESET_VALUE                   0x00000000U
/** @} */

/* macros for field twomeg_en */
/**
 * @defgroup mdm_regs_core_twomeg_en_field twomeg_en_field
 * @brief macros for field twomeg_en
 * @details Enable tracking
 * @{
 */
#define MDM_DCOFFTRK__TWOMEG_EN__SHIFT                                       27
#define MDM_DCOFFTRK__TWOMEG_EN__WIDTH                                        1
#define MDM_DCOFFTRK__TWOMEG_EN__MASK                               0x08000000U
#define MDM_DCOFFTRK__TWOMEG_EN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x08000000U) >> 27)
#define MDM_DCOFFTRK__TWOMEG_EN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 27) & 0x08000000U)
#define MDM_DCOFFTRK__TWOMEG_EN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x08000000U) | (((uint32_t)(src) <<\
                    27) & 0x08000000U)
#define MDM_DCOFFTRK__TWOMEG_EN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 27) & ~0x08000000U)))
#define MDM_DCOFFTRK__TWOMEG_EN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x08000000U) | ((uint32_t)(1) << 27)
#define MDM_DCOFFTRK__TWOMEG_EN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x08000000U) | ((uint32_t)(0) << 27)
#define MDM_DCOFFTRK__TWOMEG_EN__RESET_VALUE                        0x00000001U
/** @} */
#define MDM_DCOFFTRK__TYPE                                             uint32_t
#define MDM_DCOFFTRK__READ                                          0x0fffffffU
#define MDM_DCOFFTRK__WRITE                                         0x0fffffffU
#define MDM_DCOFFTRK__PRESERVED                                     0x00000000U
#define MDM_DCOFFTRK__RESET_VALUE                                   0x08102d17U

#endif /* __MDM_DCOFFTRK_MACRO__ */

/** @} end of dcofftrk */

/* macros for BlueprintGlobalNameSpace::MDM_dcofftrk_alt */
/**
 * @defgroup mdm_regs_core_dcofftrk_alt dcofftrk_alt
 * @brief DC offset tracking, alternate set definitions.
 * @{
 */
#ifndef __MDM_DCOFFTRK_ALT_MACRO__
#define __MDM_DCOFFTRK_ALT_MACRO__

/* macros for field en */
/**
 * @defgroup mdm_regs_core_en_field en_field
 * @brief macros for field en
 * @details Enable tracking
 * @{
 */
#define MDM_DCOFFTRK_ALT__EN__SHIFT                                           0
#define MDM_DCOFFTRK_ALT__EN__WIDTH                                           1
#define MDM_DCOFFTRK_ALT__EN__MASK                                  0x00000001U
#define MDM_DCOFFTRK_ALT__EN__READ(src)         ((uint32_t)(src) & 0x00000001U)
#define MDM_DCOFFTRK_ALT__EN__WRITE(src)        ((uint32_t)(src) & 0x00000001U)
#define MDM_DCOFFTRK_ALT__EN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define MDM_DCOFFTRK_ALT__EN__VERIFY(src) (!(((uint32_t)(src) & ~0x00000001U)))
#define MDM_DCOFFTRK_ALT__EN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define MDM_DCOFFTRK_ALT__EN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define MDM_DCOFFTRK_ALT__EN__RESET_VALUE                           0x00000001U
/** @} */

/* macros for field corr_agc_en */
/**
 * @defgroup mdm_regs_core_corr_agc_en_field corr_agc_en_field
 * @brief macros for field corr_agc_en
 * @details Enable correction based on tracking
 * @{
 */
#define MDM_DCOFFTRK_ALT__CORR_AGC_EN__SHIFT                                  1
#define MDM_DCOFFTRK_ALT__CORR_AGC_EN__WIDTH                                  1
#define MDM_DCOFFTRK_ALT__CORR_AGC_EN__MASK                         0x00000002U
#define MDM_DCOFFTRK_ALT__CORR_AGC_EN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define MDM_DCOFFTRK_ALT__CORR_AGC_EN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define MDM_DCOFFTRK_ALT__CORR_AGC_EN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define MDM_DCOFFTRK_ALT__CORR_AGC_EN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define MDM_DCOFFTRK_ALT__CORR_AGC_EN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define MDM_DCOFFTRK_ALT__CORR_AGC_EN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define MDM_DCOFFTRK_ALT__CORR_AGC_EN__RESET_VALUE                  0x00000001U
/** @} */

/* macros for field corr_syncdemod_en */
/**
 * @defgroup mdm_regs_core_corr_syncdemod_en_field corr_syncdemod_en_field
 * @brief macros for field corr_syncdemod_en
 * @details Enable correction based on tracking
 * @{
 */
#define MDM_DCOFFTRK_ALT__CORR_SYNCDEMOD_EN__SHIFT                            2
#define MDM_DCOFFTRK_ALT__CORR_SYNCDEMOD_EN__WIDTH                            1
#define MDM_DCOFFTRK_ALT__CORR_SYNCDEMOD_EN__MASK                   0x00000004U
#define MDM_DCOFFTRK_ALT__CORR_SYNCDEMOD_EN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define MDM_DCOFFTRK_ALT__CORR_SYNCDEMOD_EN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define MDM_DCOFFTRK_ALT__CORR_SYNCDEMOD_EN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define MDM_DCOFFTRK_ALT__CORR_SYNCDEMOD_EN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define MDM_DCOFFTRK_ALT__CORR_SYNCDEMOD_EN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define MDM_DCOFFTRK_ALT__CORR_SYNCDEMOD_EN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define MDM_DCOFFTRK_ALT__CORR_SYNCDEMOD_EN__RESET_VALUE            0x00000001U
/** @} */

/* macros for field mu1 */
/**
 * @defgroup mdm_regs_core_mu1_field mu1_field
 * @brief macros for field mu1
 * @details First gear mu: Encoding is 2^-(mu1+2)
 * @{
 */
#define MDM_DCOFFTRK_ALT__MU1__SHIFT                                          3
#define MDM_DCOFFTRK_ALT__MU1__WIDTH                                          3
#define MDM_DCOFFTRK_ALT__MU1__MASK                                 0x00000038U
#define MDM_DCOFFTRK_ALT__MU1__READ(src) (((uint32_t)(src) & 0x00000038U) >> 3)
#define MDM_DCOFFTRK_ALT__MU1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 3) & 0x00000038U)
#define MDM_DCOFFTRK_ALT__MU1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000038U) | (((uint32_t)(src) <<\
                    3) & 0x00000038U)
#define MDM_DCOFFTRK_ALT__MU1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000038U)))
#define MDM_DCOFFTRK_ALT__MU1__RESET_VALUE                          0x00000002U
/** @} */

/* macros for field mu2 */
/**
 * @defgroup mdm_regs_core_mu2_field mu2_field
 * @brief macros for field mu2
 * @details Second gear mu: Encoding is 2^-(mu2+2)
 * @{
 */
#define MDM_DCOFFTRK_ALT__MU2__SHIFT                                          6
#define MDM_DCOFFTRK_ALT__MU2__WIDTH                                          3
#define MDM_DCOFFTRK_ALT__MU2__MASK                                 0x000001c0U
#define MDM_DCOFFTRK_ALT__MU2__READ(src) (((uint32_t)(src) & 0x000001c0U) >> 6)
#define MDM_DCOFFTRK_ALT__MU2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 6) & 0x000001c0U)
#define MDM_DCOFFTRK_ALT__MU2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000001c0U) | (((uint32_t)(src) <<\
                    6) & 0x000001c0U)
#define MDM_DCOFFTRK_ALT__MU2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 6) & ~0x000001c0U)))
#define MDM_DCOFFTRK_ALT__MU2__RESET_VALUE                          0x00000004U
/** @} */

/* macros for field mu3 */
/**
 * @defgroup mdm_regs_core_mu3_field mu3_field
 * @brief macros for field mu3
 * @details Third gear mu: Encoding is 2^-(mu3+2)
 * @{
 */
#define MDM_DCOFFTRK_ALT__MU3__SHIFT                                          9
#define MDM_DCOFFTRK_ALT__MU3__WIDTH                                          3
#define MDM_DCOFFTRK_ALT__MU3__MASK                                 0x00000e00U
#define MDM_DCOFFTRK_ALT__MU3__READ(src) (((uint32_t)(src) & 0x00000e00U) >> 9)
#define MDM_DCOFFTRK_ALT__MU3__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x00000e00U)
#define MDM_DCOFFTRK_ALT__MU3__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000e00U) | (((uint32_t)(src) <<\
                    9) & 0x00000e00U)
#define MDM_DCOFFTRK_ALT__MU3__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x00000e00U)))
#define MDM_DCOFFTRK_ALT__MU3__RESET_VALUE                          0x00000006U
/** @} */

/* macros for field mu_count1 */
/**
 * @defgroup mdm_regs_core_mu_count1_field mu_count1_field
 * @brief macros for field mu_count1
 * @details (mu_count1 * 8) = number of 16 MHz samples to switch to gear 2
 * @{
 */
#define MDM_DCOFFTRK_ALT__MU_COUNT1__SHIFT                                   12
#define MDM_DCOFFTRK_ALT__MU_COUNT1__WIDTH                                    6
#define MDM_DCOFFTRK_ALT__MU_COUNT1__MASK                           0x0003f000U
#define MDM_DCOFFTRK_ALT__MU_COUNT1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0003f000U) >> 12)
#define MDM_DCOFFTRK_ALT__MU_COUNT1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x0003f000U)
#define MDM_DCOFFTRK_ALT__MU_COUNT1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0003f000U) | (((uint32_t)(src) <<\
                    12) & 0x0003f000U)
#define MDM_DCOFFTRK_ALT__MU_COUNT1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x0003f000U)))
#define MDM_DCOFFTRK_ALT__MU_COUNT1__RESET_VALUE                    0x00000002U
/** @} */

/* macros for field mu_count2 */
/**
 * @defgroup mdm_regs_core_mu_count2_field mu_count2_field
 * @brief macros for field mu_count2
 * @details (mu_count2 * 8) = number of 16 MHz samples to switch to gear 3. (Includes gear1 + gear2). MUST BE GREATER THAN MU_COUNT1
 * @{
 */
#define MDM_DCOFFTRK_ALT__MU_COUNT2__SHIFT                                   18
#define MDM_DCOFFTRK_ALT__MU_COUNT2__WIDTH                                    6
#define MDM_DCOFFTRK_ALT__MU_COUNT2__MASK                           0x00fc0000U
#define MDM_DCOFFTRK_ALT__MU_COUNT2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00fc0000U) >> 18)
#define MDM_DCOFFTRK_ALT__MU_COUNT2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0x00fc0000U)
#define MDM_DCOFFTRK_ALT__MU_COUNT2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00fc0000U) | (((uint32_t)(src) <<\
                    18) & 0x00fc0000U)
#define MDM_DCOFFTRK_ALT__MU_COUNT2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x00fc0000U)))
#define MDM_DCOFFTRK_ALT__MU_COUNT2__RESET_VALUE                    0x00000004U
/** @} */

/* macros for field corr_delay_idx */
/**
 * @defgroup mdm_regs_core_corr_delay_idx_field corr_delay_idx_field
 * @brief macros for field corr_delay_idx
 * @details Correction is applied (8 * corr_delay_idx) 16 MHz samples after tracking reset is released
 * @{
 */
#define MDM_DCOFFTRK_ALT__CORR_DELAY_IDX__SHIFT                              24
#define MDM_DCOFFTRK_ALT__CORR_DELAY_IDX__WIDTH                               3
#define MDM_DCOFFTRK_ALT__CORR_DELAY_IDX__MASK                      0x07000000U
#define MDM_DCOFFTRK_ALT__CORR_DELAY_IDX__READ(src) \
                    (((uint32_t)(src)\
                    & 0x07000000U) >> 24)
#define MDM_DCOFFTRK_ALT__CORR_DELAY_IDX__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x07000000U)
#define MDM_DCOFFTRK_ALT__CORR_DELAY_IDX__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x07000000U) | (((uint32_t)(src) <<\
                    24) & 0x07000000U)
#define MDM_DCOFFTRK_ALT__CORR_DELAY_IDX__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x07000000U)))
#define MDM_DCOFFTRK_ALT__CORR_DELAY_IDX__RESET_VALUE               0x00000000U
/** @} */

/* macros for field twomeg_en */
/**
 * @defgroup mdm_regs_core_twomeg_en_field twomeg_en_field
 * @brief macros for field twomeg_en
 * @details Enable tracking
 * @{
 */
#define MDM_DCOFFTRK_ALT__TWOMEG_EN__SHIFT                                   27
#define MDM_DCOFFTRK_ALT__TWOMEG_EN__WIDTH                                    1
#define MDM_DCOFFTRK_ALT__TWOMEG_EN__MASK                           0x08000000U
#define MDM_DCOFFTRK_ALT__TWOMEG_EN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x08000000U) >> 27)
#define MDM_DCOFFTRK_ALT__TWOMEG_EN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 27) & 0x08000000U)
#define MDM_DCOFFTRK_ALT__TWOMEG_EN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x08000000U) | (((uint32_t)(src) <<\
                    27) & 0x08000000U)
#define MDM_DCOFFTRK_ALT__TWOMEG_EN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 27) & ~0x08000000U)))
#define MDM_DCOFFTRK_ALT__TWOMEG_EN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x08000000U) | ((uint32_t)(1) << 27)
#define MDM_DCOFFTRK_ALT__TWOMEG_EN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x08000000U) | ((uint32_t)(0) << 27)
#define MDM_DCOFFTRK_ALT__TWOMEG_EN__RESET_VALUE                    0x00000001U
/** @} */
#define MDM_DCOFFTRK_ALT__TYPE                                         uint32_t
#define MDM_DCOFFTRK_ALT__READ                                      0x0fffffffU
#define MDM_DCOFFTRK_ALT__WRITE                                     0x0fffffffU
#define MDM_DCOFFTRK_ALT__PRESERVED                                 0x00000000U
#define MDM_DCOFFTRK_ALT__RESET_VALUE                               0x08102d17U

#endif /* __MDM_DCOFFTRK_ALT_MACRO__ */

/** @} end of dcofftrk_alt */

/* macros for BlueprintGlobalNameSpace::MDM_dcofftrk2 */
/**
 * @defgroup mdm_regs_core_dcofftrk2 dcofftrk2
 * @brief DC offset tracking, additional registers definitions.
 * @{
 */
#ifndef __MDM_DCOFFTRK2_MACRO__
#define __MDM_DCOFFTRK2_MACRO__

/* macros for field reset_filt_delay */
/**
 * @defgroup mdm_regs_core_reset_filt_delay_field reset_filt_delay_field
 * @brief macros for field reset_filt_delay
 * @details Number of 16 clocks to hold DC tracking IIR in reset before releasing in the WAIT_GAIN_SETTLE state. MUST BE EVEN AND NON-ZERO.
 * @{
 */
#define MDM_DCOFFTRK2__RESET_FILT_DELAY__SHIFT                                0
#define MDM_DCOFFTRK2__RESET_FILT_DELAY__WIDTH                                6
#define MDM_DCOFFTRK2__RESET_FILT_DELAY__MASK                       0x0000003fU
#define MDM_DCOFFTRK2__RESET_FILT_DELAY__READ(src) \
                    ((uint32_t)(src)\
                    & 0x0000003fU)
#define MDM_DCOFFTRK2__RESET_FILT_DELAY__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000003fU)
#define MDM_DCOFFTRK2__RESET_FILT_DELAY__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000003fU) | ((uint32_t)(src) &\
                    0x0000003fU)
#define MDM_DCOFFTRK2__RESET_FILT_DELAY__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000003fU)))
#define MDM_DCOFFTRK2__RESET_FILT_DELAY__RESET_VALUE                0x00000010U
/** @} */

/* macros for field twomeg_reset_filt_delay */
/**
 * @defgroup mdm_regs_core_twomeg_reset_filt_delay_field twomeg_reset_filt_delay_field
 * @brief macros for field twomeg_reset_filt_delay
 * @details Number of 16 clocks to hold DC tracking IIR in reset before releasing in the WAIT_GAIN_SETTLE state, 2 Mb/s version Should be non-zero
 * @{
 */
#define MDM_DCOFFTRK2__TWOMEG_RESET_FILT_DELAY__SHIFT                         6
#define MDM_DCOFFTRK2__TWOMEG_RESET_FILT_DELAY__WIDTH                         6
#define MDM_DCOFFTRK2__TWOMEG_RESET_FILT_DELAY__MASK                0x00000fc0U
#define MDM_DCOFFTRK2__TWOMEG_RESET_FILT_DELAY__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000fc0U) >> 6)
#define MDM_DCOFFTRK2__TWOMEG_RESET_FILT_DELAY__WRITE(src) \
                    (((uint32_t)(src)\
                    << 6) & 0x00000fc0U)
#define MDM_DCOFFTRK2__TWOMEG_RESET_FILT_DELAY__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000fc0U) | (((uint32_t)(src) <<\
                    6) & 0x00000fc0U)
#define MDM_DCOFFTRK2__TWOMEG_RESET_FILT_DELAY__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 6) & ~0x00000fc0U)))
#define MDM_DCOFFTRK2__TWOMEG_RESET_FILT_DELAY__RESET_VALUE         0x0000000aU
/** @} */

/* macros for field xlna_reset_filt_delay */
/**
 * @defgroup mdm_regs_core_xlna_reset_filt_delay_field xlna_reset_filt_delay_field
 * @brief macros for field xlna_reset_filt_delay
 * @details Number of 16 clocks to hold DC tracking IIR in reset before releasing in the WAIT_GAIN_SETTLE state. MUST BE EVEN AND NON-ZERO.
 * @{
 */
#define MDM_DCOFFTRK2__XLNA_RESET_FILT_DELAY__SHIFT                          12
#define MDM_DCOFFTRK2__XLNA_RESET_FILT_DELAY__WIDTH                           6
#define MDM_DCOFFTRK2__XLNA_RESET_FILT_DELAY__MASK                  0x0003f000U
#define MDM_DCOFFTRK2__XLNA_RESET_FILT_DELAY__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0003f000U) >> 12)
#define MDM_DCOFFTRK2__XLNA_RESET_FILT_DELAY__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x0003f000U)
#define MDM_DCOFFTRK2__XLNA_RESET_FILT_DELAY__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0003f000U) | (((uint32_t)(src) <<\
                    12) & 0x0003f000U)
#define MDM_DCOFFTRK2__XLNA_RESET_FILT_DELAY__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x0003f000U)))
#define MDM_DCOFFTRK2__XLNA_RESET_FILT_DELAY__RESET_VALUE           0x00000010U
/** @} */

/* macros for field twomeg_xlna_reset_filt_delay */
/**
 * @defgroup mdm_regs_core_twomeg_xlna_reset_filt_delay_field twomeg_xlna_reset_filt_delay_field
 * @brief macros for field twomeg_xlna_reset_filt_delay
 * @details Number of 16 clocks to hold DC tracking IIR in reset before releasing in the WAIT_GAIN_SETTLE state, 2 Mb/s version Should be non-zero
 * @{
 */
#define MDM_DCOFFTRK2__TWOMEG_XLNA_RESET_FILT_DELAY__SHIFT                   18
#define MDM_DCOFFTRK2__TWOMEG_XLNA_RESET_FILT_DELAY__WIDTH                    6
#define MDM_DCOFFTRK2__TWOMEG_XLNA_RESET_FILT_DELAY__MASK           0x00fc0000U
#define MDM_DCOFFTRK2__TWOMEG_XLNA_RESET_FILT_DELAY__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00fc0000U) >> 18)
#define MDM_DCOFFTRK2__TWOMEG_XLNA_RESET_FILT_DELAY__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0x00fc0000U)
#define MDM_DCOFFTRK2__TWOMEG_XLNA_RESET_FILT_DELAY__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00fc0000U) | (((uint32_t)(src) <<\
                    18) & 0x00fc0000U)
#define MDM_DCOFFTRK2__TWOMEG_XLNA_RESET_FILT_DELAY__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x00fc0000U)))
#define MDM_DCOFFTRK2__TWOMEG_XLNA_RESET_FILT_DELAY__RESET_VALUE    0x0000000aU
/** @} */
#define MDM_DCOFFTRK2__TYPE                                            uint32_t
#define MDM_DCOFFTRK2__READ                                         0x00ffffffU
#define MDM_DCOFFTRK2__WRITE                                        0x00ffffffU
#define MDM_DCOFFTRK2__PRESERVED                                    0x00000000U
#define MDM_DCOFFTRK2__RESET_VALUE                                  0x00290290U

#endif /* __MDM_DCOFFTRK2_MACRO__ */

/** @} end of dcofftrk2 */

/* macros for BlueprintGlobalNameSpace::MDM_dcofftrk2_alt */
/**
 * @defgroup mdm_regs_core_dcofftrk2_alt dcofftrk2_alt
 * @brief DC offset tracking, additional registers, alternate set definitions.
 * @{
 */
#ifndef __MDM_DCOFFTRK2_ALT_MACRO__
#define __MDM_DCOFFTRK2_ALT_MACRO__

/* macros for field reset_filt_delay */
/**
 * @defgroup mdm_regs_core_reset_filt_delay_field reset_filt_delay_field
 * @brief macros for field reset_filt_delay
 * @details Number of 16 clocks to hold DC tracking IIR in reset before releasing in the WAIT_GAIN_SETTLE state. MUST BE EVEN AND NON-ZERO.
 * @{
 */
#define MDM_DCOFFTRK2_ALT__RESET_FILT_DELAY__SHIFT                            0
#define MDM_DCOFFTRK2_ALT__RESET_FILT_DELAY__WIDTH                            6
#define MDM_DCOFFTRK2_ALT__RESET_FILT_DELAY__MASK                   0x0000003fU
#define MDM_DCOFFTRK2_ALT__RESET_FILT_DELAY__READ(src) \
                    ((uint32_t)(src)\
                    & 0x0000003fU)
#define MDM_DCOFFTRK2_ALT__RESET_FILT_DELAY__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000003fU)
#define MDM_DCOFFTRK2_ALT__RESET_FILT_DELAY__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000003fU) | ((uint32_t)(src) &\
                    0x0000003fU)
#define MDM_DCOFFTRK2_ALT__RESET_FILT_DELAY__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000003fU)))
#define MDM_DCOFFTRK2_ALT__RESET_FILT_DELAY__RESET_VALUE            0x00000010U
/** @} */

/* macros for field twomeg_reset_filt_delay */
/**
 * @defgroup mdm_regs_core_twomeg_reset_filt_delay_field twomeg_reset_filt_delay_field
 * @brief macros for field twomeg_reset_filt_delay
 * @details Number of 16 clocks to hold DC tracking IIR in reset before releasing in the WAIT_GAIN_SETTLE state, 2 Mb/s version Should be non-zero
 * @{
 */
#define MDM_DCOFFTRK2_ALT__TWOMEG_RESET_FILT_DELAY__SHIFT                     6
#define MDM_DCOFFTRK2_ALT__TWOMEG_RESET_FILT_DELAY__WIDTH                     6
#define MDM_DCOFFTRK2_ALT__TWOMEG_RESET_FILT_DELAY__MASK            0x00000fc0U
#define MDM_DCOFFTRK2_ALT__TWOMEG_RESET_FILT_DELAY__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000fc0U) >> 6)
#define MDM_DCOFFTRK2_ALT__TWOMEG_RESET_FILT_DELAY__WRITE(src) \
                    (((uint32_t)(src)\
                    << 6) & 0x00000fc0U)
#define MDM_DCOFFTRK2_ALT__TWOMEG_RESET_FILT_DELAY__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000fc0U) | (((uint32_t)(src) <<\
                    6) & 0x00000fc0U)
#define MDM_DCOFFTRK2_ALT__TWOMEG_RESET_FILT_DELAY__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 6) & ~0x00000fc0U)))
#define MDM_DCOFFTRK2_ALT__TWOMEG_RESET_FILT_DELAY__RESET_VALUE     0x0000000aU
/** @} */

/* macros for field xlna_reset_filt_delay */
/**
 * @defgroup mdm_regs_core_xlna_reset_filt_delay_field xlna_reset_filt_delay_field
 * @brief macros for field xlna_reset_filt_delay
 * @details Number of 16 clocks to hold DC tracking IIR in reset before releasing in the WAIT_GAIN_SETTLE state. MUST BE EVEN AND NON-ZERO.
 * @{
 */
#define MDM_DCOFFTRK2_ALT__XLNA_RESET_FILT_DELAY__SHIFT                      12
#define MDM_DCOFFTRK2_ALT__XLNA_RESET_FILT_DELAY__WIDTH                       6
#define MDM_DCOFFTRK2_ALT__XLNA_RESET_FILT_DELAY__MASK              0x0003f000U
#define MDM_DCOFFTRK2_ALT__XLNA_RESET_FILT_DELAY__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0003f000U) >> 12)
#define MDM_DCOFFTRK2_ALT__XLNA_RESET_FILT_DELAY__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x0003f000U)
#define MDM_DCOFFTRK2_ALT__XLNA_RESET_FILT_DELAY__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0003f000U) | (((uint32_t)(src) <<\
                    12) & 0x0003f000U)
#define MDM_DCOFFTRK2_ALT__XLNA_RESET_FILT_DELAY__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x0003f000U)))
#define MDM_DCOFFTRK2_ALT__XLNA_RESET_FILT_DELAY__RESET_VALUE       0x00000010U
/** @} */

/* macros for field twomeg_xlna_reset_filt_delay */
/**
 * @defgroup mdm_regs_core_twomeg_xlna_reset_filt_delay_field twomeg_xlna_reset_filt_delay_field
 * @brief macros for field twomeg_xlna_reset_filt_delay
 * @details Number of 16 clocks to hold DC tracking IIR in reset before releasing in the WAIT_GAIN_SETTLE state, 2 Mb/s version Should be non-zero
 * @{
 */
#define MDM_DCOFFTRK2_ALT__TWOMEG_XLNA_RESET_FILT_DELAY__SHIFT               18
#define MDM_DCOFFTRK2_ALT__TWOMEG_XLNA_RESET_FILT_DELAY__WIDTH                6
#define MDM_DCOFFTRK2_ALT__TWOMEG_XLNA_RESET_FILT_DELAY__MASK       0x00fc0000U
#define MDM_DCOFFTRK2_ALT__TWOMEG_XLNA_RESET_FILT_DELAY__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00fc0000U) >> 18)
#define MDM_DCOFFTRK2_ALT__TWOMEG_XLNA_RESET_FILT_DELAY__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0x00fc0000U)
#define MDM_DCOFFTRK2_ALT__TWOMEG_XLNA_RESET_FILT_DELAY__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00fc0000U) | (((uint32_t)(src) <<\
                    18) & 0x00fc0000U)
#define MDM_DCOFFTRK2_ALT__TWOMEG_XLNA_RESET_FILT_DELAY__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x00fc0000U)))
#define MDM_DCOFFTRK2_ALT__TWOMEG_XLNA_RESET_FILT_DELAY__RESET_VALUE \
                    0x0000000aU
/** @} */
#define MDM_DCOFFTRK2_ALT__TYPE                                        uint32_t
#define MDM_DCOFFTRK2_ALT__READ                                     0x00ffffffU
#define MDM_DCOFFTRK2_ALT__WRITE                                    0x00ffffffU
#define MDM_DCOFFTRK2_ALT__PRESERVED                                0x00000000U
#define MDM_DCOFFTRK2_ALT__RESET_VALUE                              0x00290290U

#endif /* __MDM_DCOFFTRK2_ALT_MACRO__ */

/** @} end of dcofftrk2_alt */

/* macros for BlueprintGlobalNameSpace::MDM_dfcntl */
/**
 * @defgroup mdm_regs_core_dfcntl dfcntl
 * @brief Direction Finding control definitions.
 * @{
 */
#ifndef __MDM_DFCNTL_MACRO__
#define __MDM_DFCNTL_MACRO__

/* macros for field iq_select */
/**
 * @defgroup mdm_regs_core_iq_select_field iq_select_field
 * @brief macros for field iq_select
 * @details Tap point for RX IQ samples sent to LC. I/Q of tap point are normalized prior to sending. 3'd0 -> rif_i/q 3'd1 -> dcoff_i/q 3'd2 -> iqcorr_i/q 3'd3 -> cic_i/q 3'd4 -> mixer_i/q 3'd5 -> rxfir_i/q
 * @{
 */
#define MDM_DFCNTL__IQ_SELECT__SHIFT                                          0
#define MDM_DFCNTL__IQ_SELECT__WIDTH                                          3
#define MDM_DFCNTL__IQ_SELECT__MASK                                 0x00000007U
#define MDM_DFCNTL__IQ_SELECT__READ(src)        ((uint32_t)(src) & 0x00000007U)
#define MDM_DFCNTL__IQ_SELECT__WRITE(src)       ((uint32_t)(src) & 0x00000007U)
#define MDM_DFCNTL__IQ_SELECT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000007U) | ((uint32_t)(src) &\
                    0x00000007U)
#define MDM_DFCNTL__IQ_SELECT__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000007U)))
#define MDM_DFCNTL__IQ_SELECT__RESET_VALUE                          0x00000005U
/** @} */

/* macros for field twomeg_iq_select */
/**
 * @defgroup mdm_regs_core_twomeg_iq_select_field twomeg_iq_select_field
 * @brief macros for field twomeg_iq_select
 * @details Tap point for RX IQ samples sent to LC. I/Q of tap point are normalized prior to sending. 3'd0 -> rif_i/q 3'd1 -> dcoff_i/q 3'd2 -> iqcorr_i/q 3'd3 -> cic_i/q 3'd4 -> mixer_i/q 3'd5 -> rxfir_i/q
 * @{
 */
#define MDM_DFCNTL__TWOMEG_IQ_SELECT__SHIFT                                   3
#define MDM_DFCNTL__TWOMEG_IQ_SELECT__WIDTH                                   3
#define MDM_DFCNTL__TWOMEG_IQ_SELECT__MASK                          0x00000038U
#define MDM_DFCNTL__TWOMEG_IQ_SELECT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000038U) >> 3)
#define MDM_DFCNTL__TWOMEG_IQ_SELECT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 3) & 0x00000038U)
#define MDM_DFCNTL__TWOMEG_IQ_SELECT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000038U) | (((uint32_t)(src) <<\
                    3) & 0x00000038U)
#define MDM_DFCNTL__TWOMEG_IQ_SELECT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000038U)))
#define MDM_DFCNTL__TWOMEG_IQ_SELECT__RESET_VALUE                   0x00000005U
/** @} */

/* macros for field left_shift */
/**
 * @defgroup mdm_regs_core_left_shift_field left_shift_field
 * @brief macros for field left_shift
 * @details The output IQ samples are 8 bits, but the inputs are either 8 bits (rif/dcoff/iqcorr), 9 bits (cic/mixer) or 14 bits (rxfir) left_shift specifies which window of 8 bits to use. 0 means to use the most significant 8 bits available for the chosen field (rif/dcoff/iqcorr/cic/mixer/rxfir). If left_shift is non-zero, then left shift the chosen field by the specified amount. For rif/dcoff/iqcorr, left_shift should be 0 (8 bits in, 8 bits out, easy). For cic/mixer, left_shift should be 0 or 1. For rxfir, left_shift should be between 0 and 6. As the value of left_shift increases, the chance of overflowing also increases. Overflows by 1 bit will be correctly saturated. Overflows by more than 1 bit will not.
 * @{
 */
#define MDM_DFCNTL__LEFT_SHIFT__SHIFT                                         6
#define MDM_DFCNTL__LEFT_SHIFT__WIDTH                                         3
#define MDM_DFCNTL__LEFT_SHIFT__MASK                                0x000001c0U
#define MDM_DFCNTL__LEFT_SHIFT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000001c0U) >> 6)
#define MDM_DFCNTL__LEFT_SHIFT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 6) & 0x000001c0U)
#define MDM_DFCNTL__LEFT_SHIFT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000001c0U) | (((uint32_t)(src) <<\
                    6) & 0x000001c0U)
#define MDM_DFCNTL__LEFT_SHIFT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 6) & ~0x000001c0U)))
#define MDM_DFCNTL__LEFT_SHIFT__RESET_VALUE                         0x00000000U
/** @} */

/* macros for field twomeg_left_shift */
/**
 * @defgroup mdm_regs_core_twomeg_left_shift_field twomeg_left_shift_field
 * @brief macros for field twomeg_left_shift
 * @details Same as left_shift, but for 2Mb/s
 * @{
 */
#define MDM_DFCNTL__TWOMEG_LEFT_SHIFT__SHIFT                                  9
#define MDM_DFCNTL__TWOMEG_LEFT_SHIFT__WIDTH                                  3
#define MDM_DFCNTL__TWOMEG_LEFT_SHIFT__MASK                         0x00000e00U
#define MDM_DFCNTL__TWOMEG_LEFT_SHIFT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000e00U) >> 9)
#define MDM_DFCNTL__TWOMEG_LEFT_SHIFT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x00000e00U)
#define MDM_DFCNTL__TWOMEG_LEFT_SHIFT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000e00U) | (((uint32_t)(src) <<\
                    9) & 0x00000e00U)
#define MDM_DFCNTL__TWOMEG_LEFT_SHIFT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x00000e00U)))
#define MDM_DFCNTL__TWOMEG_LEFT_SHIFT__RESET_VALUE                  0x00000000U
/** @} */

/* macros for field dynamic_left_shift */
/**
 * @defgroup mdm_regs_core_dynamic_left_shift_field dynamic_left_shift_field
 * @brief macros for field dynamic_left_shift
 * @details 0 -> Use left_shift/twomeg_left_shift directly 1 -> Use dftable, indexed by baseline_pwr per packet
 * @{
 */
#define MDM_DFCNTL__DYNAMIC_LEFT_SHIFT__SHIFT                                12
#define MDM_DFCNTL__DYNAMIC_LEFT_SHIFT__WIDTH                                 1
#define MDM_DFCNTL__DYNAMIC_LEFT_SHIFT__MASK                        0x00001000U
#define MDM_DFCNTL__DYNAMIC_LEFT_SHIFT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00001000U) >> 12)
#define MDM_DFCNTL__DYNAMIC_LEFT_SHIFT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x00001000U)
#define MDM_DFCNTL__DYNAMIC_LEFT_SHIFT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | (((uint32_t)(src) <<\
                    12) & 0x00001000U)
#define MDM_DFCNTL__DYNAMIC_LEFT_SHIFT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x00001000U)))
#define MDM_DFCNTL__DYNAMIC_LEFT_SHIFT__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | ((uint32_t)(1) << 12)
#define MDM_DFCNTL__DYNAMIC_LEFT_SHIFT__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | ((uint32_t)(0) << 12)
#define MDM_DFCNTL__DYNAMIC_LEFT_SHIFT__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field update_on_cte_only */
/**
 * @defgroup mdm_regs_core_update_on_cte_only_field update_on_cte_only_field
 * @brief macros for field update_on_cte_only
 * @details When to update the dfstatus register 0 -> Anytime access address found 1 -> Only on CTE packets, when the LC asserts lc_direction_find_enable
 * @{
 */
#define MDM_DFCNTL__UPDATE_ON_CTE_ONLY__SHIFT                                13
#define MDM_DFCNTL__UPDATE_ON_CTE_ONLY__WIDTH                                 1
#define MDM_DFCNTL__UPDATE_ON_CTE_ONLY__MASK                        0x00002000U
#define MDM_DFCNTL__UPDATE_ON_CTE_ONLY__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00002000U) >> 13)
#define MDM_DFCNTL__UPDATE_ON_CTE_ONLY__WRITE(src) \
                    (((uint32_t)(src)\
                    << 13) & 0x00002000U)
#define MDM_DFCNTL__UPDATE_ON_CTE_ONLY__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | (((uint32_t)(src) <<\
                    13) & 0x00002000U)
#define MDM_DFCNTL__UPDATE_ON_CTE_ONLY__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 13) & ~0x00002000U)))
#define MDM_DFCNTL__UPDATE_ON_CTE_ONLY__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | ((uint32_t)(1) << 13)
#define MDM_DFCNTL__UPDATE_ON_CTE_ONLY__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | ((uint32_t)(0) << 13)
#define MDM_DFCNTL__UPDATE_ON_CTE_ONLY__RESET_VALUE                 0x00000001U
/** @} */

/* macros for field antmode */
/**
 * @defgroup mdm_regs_core_antmode_field antmode_field
 * @brief macros for field antmode
 * @details 2'b00 -> Use 3 LSBs from LC antenna id 2'b01 -> Output LC antenna id directly 2'b10 -> Compare LC antenna id to 8 IDs in antid registers
 * @{
 */
#define MDM_DFCNTL__ANTMODE__SHIFT                                           14
#define MDM_DFCNTL__ANTMODE__WIDTH                                            2
#define MDM_DFCNTL__ANTMODE__MASK                                   0x0000c000U
#define MDM_DFCNTL__ANTMODE__READ(src)  (((uint32_t)(src) & 0x0000c000U) >> 14)
#define MDM_DFCNTL__ANTMODE__WRITE(src) (((uint32_t)(src) << 14) & 0x0000c000U)
#define MDM_DFCNTL__ANTMODE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000c000U) | (((uint32_t)(src) <<\
                    14) & 0x0000c000U)
#define MDM_DFCNTL__ANTMODE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 14) & ~0x0000c000U)))
#define MDM_DFCNTL__ANTMODE__RESET_VALUE                            0x00000000U
/** @} */

/* macros for field sw_ant_select */
/**
 * @defgroup mdm_regs_core_sw_ant_select_field sw_ant_select_field
 * @brief macros for field sw_ant_select
 * @details Antenna table index controlled directly by SW. Which, if any, of these bits that are actively used is determined by the use_sw_antenna_select field
 * @{
 */
#define MDM_DFCNTL__SW_ANT_SELECT__SHIFT                                     16
#define MDM_DFCNTL__SW_ANT_SELECT__WIDTH                                      3
#define MDM_DFCNTL__SW_ANT_SELECT__MASK                             0x00070000U
#define MDM_DFCNTL__SW_ANT_SELECT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00070000U) >> 16)
#define MDM_DFCNTL__SW_ANT_SELECT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x00070000U)
#define MDM_DFCNTL__SW_ANT_SELECT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00070000U) | (((uint32_t)(src) <<\
                    16) & 0x00070000U)
#define MDM_DFCNTL__SW_ANT_SELECT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x00070000U)))
#define MDM_DFCNTL__SW_ANT_SELECT__RESET_VALUE                      0x00000000U
/** @} */

/* macros for field use_sw_ant_select */
/**
 * @defgroup mdm_regs_core_use_sw_ant_select_field use_sw_ant_select_field
 * @brief macros for field use_sw_ant_select
 * @details For each of these three bits, a '1' means to use the corresponding bit from sw_antenna_select for the antenna table index. A '0' means to use the corresponding bit from the LC antenna select as a function of antmode (only for antmode == 0 or 2)
 * @{
 */
#define MDM_DFCNTL__USE_SW_ANT_SELECT__SHIFT                                 19
#define MDM_DFCNTL__USE_SW_ANT_SELECT__WIDTH                                  3
#define MDM_DFCNTL__USE_SW_ANT_SELECT__MASK                         0x00380000U
#define MDM_DFCNTL__USE_SW_ANT_SELECT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00380000U) >> 19)
#define MDM_DFCNTL__USE_SW_ANT_SELECT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 19) & 0x00380000U)
#define MDM_DFCNTL__USE_SW_ANT_SELECT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00380000U) | (((uint32_t)(src) <<\
                    19) & 0x00380000U)
#define MDM_DFCNTL__USE_SW_ANT_SELECT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 19) & ~0x00380000U)))
#define MDM_DFCNTL__USE_SW_ANT_SELECT__RESET_VALUE                  0x00000000U
/** @} */

/* macros for field use_default_sw_ant_select_for_cte */
/**
 * @defgroup mdm_regs_core_use_default_sw_ant_select_for_cte_field use_default_sw_ant_select_for_cte_field
 * @brief macros for field use_default_sw_ant_select_for_cte
 * @details For the CTE portion of packets, the same sequencing of antennas may be wanted regardless of the antenna diversity selection specified by sw_ant_select. If so, this can be accomplished by setting the use_default_sw_ant_select_for_cte bit, which will have the effect of forcing sw_ant_select = sw_ant_select_cte during the CTE portion
 * @{
 */
#define MDM_DFCNTL__USE_DEFAULT_SW_ANT_SELECT_FOR_CTE__SHIFT                 22
#define MDM_DFCNTL__USE_DEFAULT_SW_ANT_SELECT_FOR_CTE__WIDTH                  1
#define MDM_DFCNTL__USE_DEFAULT_SW_ANT_SELECT_FOR_CTE__MASK         0x00400000U
#define MDM_DFCNTL__USE_DEFAULT_SW_ANT_SELECT_FOR_CTE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00400000U) >> 22)
#define MDM_DFCNTL__USE_DEFAULT_SW_ANT_SELECT_FOR_CTE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 22) & 0x00400000U)
#define MDM_DFCNTL__USE_DEFAULT_SW_ANT_SELECT_FOR_CTE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00400000U) | (((uint32_t)(src) <<\
                    22) & 0x00400000U)
#define MDM_DFCNTL__USE_DEFAULT_SW_ANT_SELECT_FOR_CTE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 22) & ~0x00400000U)))
#define MDM_DFCNTL__USE_DEFAULT_SW_ANT_SELECT_FOR_CTE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00400000U) | ((uint32_t)(1) << 22)
#define MDM_DFCNTL__USE_DEFAULT_SW_ANT_SELECT_FOR_CTE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00400000U) | ((uint32_t)(0) << 22)
#define MDM_DFCNTL__USE_DEFAULT_SW_ANT_SELECT_FOR_CTE__RESET_VALUE  0x00000001U
/** @} */

/* macros for field sw_ant_select_for_cte */
/**
 * @defgroup mdm_regs_core_sw_ant_select_for_cte_field sw_ant_select_for_cte_field
 * @brief macros for field sw_ant_select_for_cte
 * @details If use_default_sw_ant_select_for_cte is set, force sw_ant_select = sw_ant_select_for_cte during CTE portion
 * @{
 */
#define MDM_DFCNTL__SW_ANT_SELECT_FOR_CTE__SHIFT                             23
#define MDM_DFCNTL__SW_ANT_SELECT_FOR_CTE__WIDTH                              3
#define MDM_DFCNTL__SW_ANT_SELECT_FOR_CTE__MASK                     0x03800000U
#define MDM_DFCNTL__SW_ANT_SELECT_FOR_CTE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x03800000U) >> 23)
#define MDM_DFCNTL__SW_ANT_SELECT_FOR_CTE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 23) & 0x03800000U)
#define MDM_DFCNTL__SW_ANT_SELECT_FOR_CTE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x03800000U) | (((uint32_t)(src) <<\
                    23) & 0x03800000U)
#define MDM_DFCNTL__SW_ANT_SELECT_FOR_CTE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 23) & ~0x03800000U)))
#define MDM_DFCNTL__SW_ANT_SELECT_FOR_CTE__RESET_VALUE              0x00000000U
/** @} */

/* macros for field update_rd_freq_est_during_cte */
/**
 * @defgroup mdm_regs_core_update_rd_freq_est_during_cte_field update_rd_freq_est_during_cte_field
 * @brief macros for field update_rd_freq_est_during_cte
 * @details If high, continue to update measfreq_freq_offset even during CTE portion of packet. If low, then do not.
 * @{
 */
#define MDM_DFCNTL__UPDATE_RD_FREQ_EST_DURING_CTE__SHIFT                     26
#define MDM_DFCNTL__UPDATE_RD_FREQ_EST_DURING_CTE__WIDTH                      1
#define MDM_DFCNTL__UPDATE_RD_FREQ_EST_DURING_CTE__MASK             0x04000000U
#define MDM_DFCNTL__UPDATE_RD_FREQ_EST_DURING_CTE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x04000000U) >> 26)
#define MDM_DFCNTL__UPDATE_RD_FREQ_EST_DURING_CTE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 26) & 0x04000000U)
#define MDM_DFCNTL__UPDATE_RD_FREQ_EST_DURING_CTE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x04000000U) | (((uint32_t)(src) <<\
                    26) & 0x04000000U)
#define MDM_DFCNTL__UPDATE_RD_FREQ_EST_DURING_CTE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 26) & ~0x04000000U)))
#define MDM_DFCNTL__UPDATE_RD_FREQ_EST_DURING_CTE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x04000000U) | ((uint32_t)(1) << 26)
#define MDM_DFCNTL__UPDATE_RD_FREQ_EST_DURING_CTE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x04000000U) | ((uint32_t)(0) << 26)
#define MDM_DFCNTL__UPDATE_RD_FREQ_EST_DURING_CTE__RESET_VALUE      0x00000000U
/** @} */
#define MDM_DFCNTL__TYPE                                               uint32_t
#define MDM_DFCNTL__READ                                            0x07ffffffU
#define MDM_DFCNTL__WRITE                                           0x07ffffffU
#define MDM_DFCNTL__PRESERVED                                       0x00000000U
#define MDM_DFCNTL__RESET_VALUE                                     0x0040202dU

#endif /* __MDM_DFCNTL_MACRO__ */

/** @} end of dfcntl */

/* macros for BlueprintGlobalNameSpace::MDM_dfcntl_alt */
/**
 * @defgroup mdm_regs_core_dfcntl_alt dfcntl_alt
 * @brief Direction Finding control, alternate set, but just for one register field definitions.
 * @{
 */
#ifndef __MDM_DFCNTL_ALT_MACRO__
#define __MDM_DFCNTL_ALT_MACRO__

/* macros for field sw_ant_select */
/**
 * @defgroup mdm_regs_core_sw_ant_select_field sw_ant_select_field
 * @brief macros for field sw_ant_select
 * @details Antenna table index controlled directly by SW. Which, if any, of these bits that are actively used is determined by the use_sw_antenna_select field
 * @{
 */
#define MDM_DFCNTL_ALT__SW_ANT_SELECT__SHIFT                                 16
#define MDM_DFCNTL_ALT__SW_ANT_SELECT__WIDTH                                  3
#define MDM_DFCNTL_ALT__SW_ANT_SELECT__MASK                         0x00070000U
#define MDM_DFCNTL_ALT__SW_ANT_SELECT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00070000U) >> 16)
#define MDM_DFCNTL_ALT__SW_ANT_SELECT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x00070000U)
#define MDM_DFCNTL_ALT__SW_ANT_SELECT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00070000U) | (((uint32_t)(src) <<\
                    16) & 0x00070000U)
#define MDM_DFCNTL_ALT__SW_ANT_SELECT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x00070000U)))
#define MDM_DFCNTL_ALT__SW_ANT_SELECT__RESET_VALUE                  0x00000000U
/** @} */
#define MDM_DFCNTL_ALT__TYPE                                           uint32_t
#define MDM_DFCNTL_ALT__READ                                        0x00070000U
#define MDM_DFCNTL_ALT__WRITE                                       0x00070000U
#define MDM_DFCNTL_ALT__PRESERVED                                   0x00000000U
#define MDM_DFCNTL_ALT__RESET_VALUE                                 0x00000000U

#endif /* __MDM_DFCNTL_ALT_MACRO__ */

/** @} end of dfcntl_alt */

/* macros for BlueprintGlobalNameSpace::MDM_swantctetime */
/**
 * @defgroup mdm_regs_core_swantctetime swantctetime
 * @brief If use_default_sw_ant_select_for_cte = 1, then start forcing sw_ant_select = sw_ant_select_for_cte a programmable amount of time after the LC asserts DF_mode_enable. The programmable delay is specified differently for (TX vs RX), and (1 Mb/s vs 2 Mb/s). definitions.
 * @{
 */
#ifndef __MDM_SWANTCTETIME_MACRO__
#define __MDM_SWANTCTETIME_MACRO__

/* macros for field rx */
/**
 * @defgroup mdm_regs_core_rx_field rx_field
 * @brief macros for field rx
 * @details Delay in 16 MHz clocks for 1M rx
 * @{
 */
#define MDM_SWANTCTETIME__RX__SHIFT                                           0
#define MDM_SWANTCTETIME__RX__WIDTH                                           7
#define MDM_SWANTCTETIME__RX__MASK                                  0x0000007fU
#define MDM_SWANTCTETIME__RX__READ(src)         ((uint32_t)(src) & 0x0000007fU)
#define MDM_SWANTCTETIME__RX__WRITE(src)        ((uint32_t)(src) & 0x0000007fU)
#define MDM_SWANTCTETIME__RX__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000007fU) | ((uint32_t)(src) &\
                    0x0000007fU)
#define MDM_SWANTCTETIME__RX__VERIFY(src) (!(((uint32_t)(src) & ~0x0000007fU)))
#define MDM_SWANTCTETIME__RX__RESET_VALUE                           0x00000000U
/** @} */

/* macros for field tx */
/**
 * @defgroup mdm_regs_core_tx_field tx_field
 * @brief macros for field tx
 * @details Delay in 16 MHz clocks for 1M tx
 * @{
 */
#define MDM_SWANTCTETIME__TX__SHIFT                                           7
#define MDM_SWANTCTETIME__TX__WIDTH                                           7
#define MDM_SWANTCTETIME__TX__MASK                                  0x00003f80U
#define MDM_SWANTCTETIME__TX__READ(src)  (((uint32_t)(src) & 0x00003f80U) >> 7)
#define MDM_SWANTCTETIME__TX__WRITE(src) (((uint32_t)(src) << 7) & 0x00003f80U)
#define MDM_SWANTCTETIME__TX__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00003f80U) | (((uint32_t)(src) <<\
                    7) & 0x00003f80U)
#define MDM_SWANTCTETIME__TX__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 7) & ~0x00003f80U)))
#define MDM_SWANTCTETIME__TX__RESET_VALUE                           0x00000000U
/** @} */

/* macros for field twomeg_rx */
/**
 * @defgroup mdm_regs_core_twomeg_rx_field twomeg_rx_field
 * @brief macros for field twomeg_rx
 * @details Delay in 16 MHz clocks for 2M rx
 * @{
 */
#define MDM_SWANTCTETIME__TWOMEG_RX__SHIFT                                   14
#define MDM_SWANTCTETIME__TWOMEG_RX__WIDTH                                    7
#define MDM_SWANTCTETIME__TWOMEG_RX__MASK                           0x001fc000U
#define MDM_SWANTCTETIME__TWOMEG_RX__READ(src) \
                    (((uint32_t)(src)\
                    & 0x001fc000U) >> 14)
#define MDM_SWANTCTETIME__TWOMEG_RX__WRITE(src) \
                    (((uint32_t)(src)\
                    << 14) & 0x001fc000U)
#define MDM_SWANTCTETIME__TWOMEG_RX__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x001fc000U) | (((uint32_t)(src) <<\
                    14) & 0x001fc000U)
#define MDM_SWANTCTETIME__TWOMEG_RX__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 14) & ~0x001fc000U)))
#define MDM_SWANTCTETIME__TWOMEG_RX__RESET_VALUE                    0x00000000U
/** @} */

/* macros for field twomeg_tx */
/**
 * @defgroup mdm_regs_core_twomeg_tx_field twomeg_tx_field
 * @brief macros for field twomeg_tx
 * @details Delay in 16 MHz clocks for 2M tx
 * @{
 */
#define MDM_SWANTCTETIME__TWOMEG_TX__SHIFT                                   21
#define MDM_SWANTCTETIME__TWOMEG_TX__WIDTH                                    7
#define MDM_SWANTCTETIME__TWOMEG_TX__MASK                           0x0fe00000U
#define MDM_SWANTCTETIME__TWOMEG_TX__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0fe00000U) >> 21)
#define MDM_SWANTCTETIME__TWOMEG_TX__WRITE(src) \
                    (((uint32_t)(src)\
                    << 21) & 0x0fe00000U)
#define MDM_SWANTCTETIME__TWOMEG_TX__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0fe00000U) | (((uint32_t)(src) <<\
                    21) & 0x0fe00000U)
#define MDM_SWANTCTETIME__TWOMEG_TX__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 21) & ~0x0fe00000U)))
#define MDM_SWANTCTETIME__TWOMEG_TX__RESET_VALUE                    0x00000000U
/** @} */
#define MDM_SWANTCTETIME__TYPE                                         uint32_t
#define MDM_SWANTCTETIME__READ                                      0x0fffffffU
#define MDM_SWANTCTETIME__WRITE                                     0x0fffffffU
#define MDM_SWANTCTETIME__PRESERVED                                 0x00000000U
#define MDM_SWANTCTETIME__RESET_VALUE                               0x00000000U

#endif /* __MDM_SWANTCTETIME_MACRO__ */

/** @} end of swantctetime */

/* macros for BlueprintGlobalNameSpace::MDM_dftable */
/**
 * @defgroup mdm_regs_core_dftable dftable
 * @brief Table for direction finding IQ scaling, indexed by baseline_pwr definitions.
 * @{
 */
#ifndef __MDM_DFTABLE_MACRO__
#define __MDM_DFTABLE_MACRO__

/* macros for field m5to0 */
/**
 * @defgroup mdm_regs_core_m5to0_field m5to0_field
 * @brief macros for field m5to0
 * @details left shift for -5 <= baseline_pwr <= 0
 * @{
 */
#define MDM_DFTABLE__M5TO0__SHIFT                                             0
#define MDM_DFTABLE__M5TO0__WIDTH                                             3
#define MDM_DFTABLE__M5TO0__MASK                                    0x00000007U
#define MDM_DFTABLE__M5TO0__READ(src)           ((uint32_t)(src) & 0x00000007U)
#define MDM_DFTABLE__M5TO0__WRITE(src)          ((uint32_t)(src) & 0x00000007U)
#define MDM_DFTABLE__M5TO0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000007U) | ((uint32_t)(src) &\
                    0x00000007U)
#define MDM_DFTABLE__M5TO0__VERIFY(src)   (!(((uint32_t)(src) & ~0x00000007U)))
#define MDM_DFTABLE__M5TO0__RESET_VALUE                             0x00000002U
/** @} */

/* macros for field m11tom6 */
/**
 * @defgroup mdm_regs_core_m11tom6_field m11tom6_field
 * @brief macros for field m11tom6
 * @details left shift for -11 <= baseline_pwr <= -6
 * @{
 */
#define MDM_DFTABLE__M11TOM6__SHIFT                                           3
#define MDM_DFTABLE__M11TOM6__WIDTH                                           3
#define MDM_DFTABLE__M11TOM6__MASK                                  0x00000038U
#define MDM_DFTABLE__M11TOM6__READ(src)  (((uint32_t)(src) & 0x00000038U) >> 3)
#define MDM_DFTABLE__M11TOM6__WRITE(src) (((uint32_t)(src) << 3) & 0x00000038U)
#define MDM_DFTABLE__M11TOM6__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000038U) | (((uint32_t)(src) <<\
                    3) & 0x00000038U)
#define MDM_DFTABLE__M11TOM6__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000038U)))
#define MDM_DFTABLE__M11TOM6__RESET_VALUE                           0x00000002U
/** @} */

/* macros for field m17tom12 */
/**
 * @defgroup mdm_regs_core_m17tom12_field m17tom12_field
 * @brief macros for field m17tom12
 * @details left shift for -17 <= baseline_pwr <= -12
 * @{
 */
#define MDM_DFTABLE__M17TOM12__SHIFT                                          6
#define MDM_DFTABLE__M17TOM12__WIDTH                                          3
#define MDM_DFTABLE__M17TOM12__MASK                                 0x000001c0U
#define MDM_DFTABLE__M17TOM12__READ(src) (((uint32_t)(src) & 0x000001c0U) >> 6)
#define MDM_DFTABLE__M17TOM12__WRITE(src) \
                    (((uint32_t)(src)\
                    << 6) & 0x000001c0U)
#define MDM_DFTABLE__M17TOM12__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000001c0U) | (((uint32_t)(src) <<\
                    6) & 0x000001c0U)
#define MDM_DFTABLE__M17TOM12__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 6) & ~0x000001c0U)))
#define MDM_DFTABLE__M17TOM12__RESET_VALUE                          0x00000002U
/** @} */

/* macros for field m23tom18 */
/**
 * @defgroup mdm_regs_core_m23tom18_field m23tom18_field
 * @brief macros for field m23tom18
 * @details left shift for -23 <= baseline_pwr <= -18
 * @{
 */
#define MDM_DFTABLE__M23TOM18__SHIFT                                          9
#define MDM_DFTABLE__M23TOM18__WIDTH                                          3
#define MDM_DFTABLE__M23TOM18__MASK                                 0x00000e00U
#define MDM_DFTABLE__M23TOM18__READ(src) (((uint32_t)(src) & 0x00000e00U) >> 9)
#define MDM_DFTABLE__M23TOM18__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x00000e00U)
#define MDM_DFTABLE__M23TOM18__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000e00U) | (((uint32_t)(src) <<\
                    9) & 0x00000e00U)
#define MDM_DFTABLE__M23TOM18__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x00000e00U)))
#define MDM_DFTABLE__M23TOM18__RESET_VALUE                          0x00000002U
/** @} */

/* macros for field m29tom24 */
/**
 * @defgroup mdm_regs_core_m29tom24_field m29tom24_field
 * @brief macros for field m29tom24
 * @details left shift for -29 <= baseline_pwr <= -24
 * @{
 */
#define MDM_DFTABLE__M29TOM24__SHIFT                                         12
#define MDM_DFTABLE__M29TOM24__WIDTH                                          3
#define MDM_DFTABLE__M29TOM24__MASK                                 0x00007000U
#define MDM_DFTABLE__M29TOM24__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00007000U) >> 12)
#define MDM_DFTABLE__M29TOM24__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x00007000U)
#define MDM_DFTABLE__M29TOM24__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00007000U) | (((uint32_t)(src) <<\
                    12) & 0x00007000U)
#define MDM_DFTABLE__M29TOM24__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x00007000U)))
#define MDM_DFTABLE__M29TOM24__RESET_VALUE                          0x00000002U
/** @} */

/* macros for field m35tom30 */
/**
 * @defgroup mdm_regs_core_m35tom30_field m35tom30_field
 * @brief macros for field m35tom30
 * @details left shift for -35 <= baseline_pwr <= -30
 * @{
 */
#define MDM_DFTABLE__M35TOM30__SHIFT                                         15
#define MDM_DFTABLE__M35TOM30__WIDTH                                          3
#define MDM_DFTABLE__M35TOM30__MASK                                 0x00038000U
#define MDM_DFTABLE__M35TOM30__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00038000U) >> 15)
#define MDM_DFTABLE__M35TOM30__WRITE(src) \
                    (((uint32_t)(src)\
                    << 15) & 0x00038000U)
#define MDM_DFTABLE__M35TOM30__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00038000U) | (((uint32_t)(src) <<\
                    15) & 0x00038000U)
#define MDM_DFTABLE__M35TOM30__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 15) & ~0x00038000U)))
#define MDM_DFTABLE__M35TOM30__RESET_VALUE                          0x00000002U
/** @} */

/* macros for field m41tom36 */
/**
 * @defgroup mdm_regs_core_m41tom36_field m41tom36_field
 * @brief macros for field m41tom36
 * @details left shift for -41 <= baseline_pwr <= -36
 * @{
 */
#define MDM_DFTABLE__M41TOM36__SHIFT                                         18
#define MDM_DFTABLE__M41TOM36__WIDTH                                          3
#define MDM_DFTABLE__M41TOM36__MASK                                 0x001c0000U
#define MDM_DFTABLE__M41TOM36__READ(src) \
                    (((uint32_t)(src)\
                    & 0x001c0000U) >> 18)
#define MDM_DFTABLE__M41TOM36__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0x001c0000U)
#define MDM_DFTABLE__M41TOM36__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x001c0000U) | (((uint32_t)(src) <<\
                    18) & 0x001c0000U)
#define MDM_DFTABLE__M41TOM36__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x001c0000U)))
#define MDM_DFTABLE__M41TOM36__RESET_VALUE                          0x00000002U
/** @} */

/* macros for field belowm41 */
/**
 * @defgroup mdm_regs_core_belowm41_field belowm41_field
 * @brief macros for field belowm41
 * @details left shift for baseline_pwr < -41
 * @{
 */
#define MDM_DFTABLE__BELOWM41__SHIFT                                         21
#define MDM_DFTABLE__BELOWM41__WIDTH                                          3
#define MDM_DFTABLE__BELOWM41__MASK                                 0x00e00000U
#define MDM_DFTABLE__BELOWM41__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00e00000U) >> 21)
#define MDM_DFTABLE__BELOWM41__WRITE(src) \
                    (((uint32_t)(src)\
                    << 21) & 0x00e00000U)
#define MDM_DFTABLE__BELOWM41__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00e00000U) | (((uint32_t)(src) <<\
                    21) & 0x00e00000U)
#define MDM_DFTABLE__BELOWM41__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 21) & ~0x00e00000U)))
#define MDM_DFTABLE__BELOWM41__RESET_VALUE                          0x00000002U
/** @} */
#define MDM_DFTABLE__TYPE                                              uint32_t
#define MDM_DFTABLE__READ                                           0x00ffffffU
#define MDM_DFTABLE__WRITE                                          0x00ffffffU
#define MDM_DFTABLE__PRESERVED                                      0x00000000U
#define MDM_DFTABLE__RESET_VALUE                                    0x00492492U

#endif /* __MDM_DFTABLE_MACRO__ */

/** @} end of dftable */

/* macros for BlueprintGlobalNameSpace::MDM_dfstatus */
/**
 * @defgroup mdm_regs_core_dfstatus dfstatus
 * @brief Saved state from previous agc operation, but with different update conditions than agcstatus. (See dfcntl->statusmode) definitions.
 * @{
 */
#ifndef __MDM_DFSTATUS_MACRO__
#define __MDM_DFSTATUS_MACRO__

/* macros for field rssi */
/**
 * @defgroup mdm_regs_core_rssi_field rssi_field
 * @brief macros for field rssi
 * @details Received Signal Strength Indicator, absolute dBm. Signed.
 * @{
 */
#define MDM_DFSTATUS__RSSI__SHIFT                                             0
#define MDM_DFSTATUS__RSSI__WIDTH                                             8
#define MDM_DFSTATUS__RSSI__MASK                                    0x000000ffU
#define MDM_DFSTATUS__RSSI__READ(src)           ((uint32_t)(src) & 0x000000ffU)
#define MDM_DFSTATUS__RSSI__RESET_VALUE                             0x00000000U
/** @} */

/* macros for field rxgain */
/**
 * @defgroup mdm_regs_core_rxgain_field rxgain_field
 * @brief macros for field rxgain
 * @details Receive gain index
 * @{
 */
#define MDM_DFSTATUS__RXGAIN__SHIFT                                           8
#define MDM_DFSTATUS__RXGAIN__WIDTH                                           7
#define MDM_DFSTATUS__RXGAIN__MASK                                  0x00007f00U
#define MDM_DFSTATUS__RXGAIN__READ(src)  (((uint32_t)(src) & 0x00007f00U) >> 8)
#define MDM_DFSTATUS__RXGAIN__RESET_VALUE                           0x00000000U
/** @} */

/* macros for field baseline_pwr */
/**
 * @defgroup mdm_regs_core_baseline_pwr_field baseline_pwr_field
 * @brief macros for field baseline_pwr
 * @details Baseline power, post-RXFIR. Signed
 * @{
 */
#define MDM_DFSTATUS__BASELINE_PWR__SHIFT                                    15
#define MDM_DFSTATUS__BASELINE_PWR__WIDTH                                     8
#define MDM_DFSTATUS__BASELINE_PWR__MASK                            0x007f8000U
#define MDM_DFSTATUS__BASELINE_PWR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x007f8000U) >> 15)
#define MDM_DFSTATUS__BASELINE_PWR__RESET_VALUE                     0x00000000U
/** @} */

/* macros for field sat_detected */
/**
 * @defgroup mdm_regs_core_sat_detected_field sat_detected_field
 * @brief macros for field sat_detected
 * @details Saturation triggered packet detection
 * @{
 */
#define MDM_DFSTATUS__SAT_DETECTED__SHIFT                                    23
#define MDM_DFSTATUS__SAT_DETECTED__WIDTH                                     1
#define MDM_DFSTATUS__SAT_DETECTED__MASK                            0x00800000U
#define MDM_DFSTATUS__SAT_DETECTED__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00800000U) >> 23)
#define MDM_DFSTATUS__SAT_DETECTED__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(1) << 23)
#define MDM_DFSTATUS__SAT_DETECTED__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(0) << 23)
#define MDM_DFSTATUS__SAT_DETECTED__RESET_VALUE                     0x00000000U
/** @} */

/* macros for field peak_detected */
/**
 * @defgroup mdm_regs_core_peak_detected_field peak_detected_field
 * @brief macros for field peak_detected
 * @details Analog peak triggered packet detection
 * @{
 */
#define MDM_DFSTATUS__PEAK_DETECTED__SHIFT                                   24
#define MDM_DFSTATUS__PEAK_DETECTED__WIDTH                                    1
#define MDM_DFSTATUS__PEAK_DETECTED__MASK                           0x01000000U
#define MDM_DFSTATUS__PEAK_DETECTED__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01000000U) >> 24)
#define MDM_DFSTATUS__PEAK_DETECTED__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(1) << 24)
#define MDM_DFSTATUS__PEAK_DETECTED__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(0) << 24)
#define MDM_DFSTATUS__PEAK_DETECTED__RESET_VALUE                    0x00000000U
/** @} */

/* macros for field strong_blocker */
/**
 * @defgroup mdm_regs_core_strong_blocker_field strong_blocker_field
 * @brief macros for field strong_blocker
 * @details strong_blocker = (total_pwr - baseline_pwr) > cf_margin_strong_blocker_thr
 * @{
 */
#define MDM_DFSTATUS__STRONG_BLOCKER__SHIFT                                  25
#define MDM_DFSTATUS__STRONG_BLOCKER__WIDTH                                   1
#define MDM_DFSTATUS__STRONG_BLOCKER__MASK                          0x02000000U
#define MDM_DFSTATUS__STRONG_BLOCKER__READ(src) \
                    (((uint32_t)(src)\
                    & 0x02000000U) >> 25)
#define MDM_DFSTATUS__STRONG_BLOCKER__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x02000000U) | ((uint32_t)(1) << 25)
#define MDM_DFSTATUS__STRONG_BLOCKER__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x02000000U) | ((uint32_t)(0) << 25)
#define MDM_DFSTATUS__STRONG_BLOCKER__RESET_VALUE                   0x00000000U
/** @} */
#define MDM_DFSTATUS__TYPE                                             uint32_t
#define MDM_DFSTATUS__READ                                          0x03ffffffU
#define MDM_DFSTATUS__PRESERVED                                     0x00000000U
#define MDM_DFSTATUS__RESET_VALUE                                   0x00000000U

#endif /* __MDM_DFSTATUS_MACRO__ */

/** @} end of dfstatus */

/* macros for BlueprintGlobalNameSpace::MDM_antrx3to0 */
/**
 * @defgroup mdm_regs_core_antrx3to0 antrx3to0
 * @brief Antenna table when RX definitions.
 * @{
 */
#ifndef __MDM_ANTRX3TO0_MACRO__
#define __MDM_ANTRX3TO0_MACRO__

/* macros for field table */
/**
 * @defgroup mdm_regs_core_table_field table_field
 * @brief macros for field table
 * @details [31:24] for ant3, [23:16] for ant2, [15:8] for ant1, [7:0] for ant0
 * @{
 */
#define MDM_ANTRX3TO0__TABLE__SHIFT                                           0
#define MDM_ANTRX3TO0__TABLE__WIDTH                                          32
#define MDM_ANTRX3TO0__TABLE__MASK                                  0xffffffffU
#define MDM_ANTRX3TO0__TABLE__READ(src)         ((uint32_t)(src) & 0xffffffffU)
#define MDM_ANTRX3TO0__TABLE__WRITE(src)        ((uint32_t)(src) & 0xffffffffU)
#define MDM_ANTRX3TO0__TABLE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define MDM_ANTRX3TO0__TABLE__VERIFY(src) (!(((uint32_t)(src) & ~0xffffffffU)))
#define MDM_ANTRX3TO0__TABLE__RESET_VALUE                           0x08040201U
/** @} */
#define MDM_ANTRX3TO0__TYPE                                            uint32_t
#define MDM_ANTRX3TO0__READ                                         0xffffffffU
#define MDM_ANTRX3TO0__WRITE                                        0xffffffffU
#define MDM_ANTRX3TO0__PRESERVED                                    0x00000000U
#define MDM_ANTRX3TO0__RESET_VALUE                                  0x08040201U

#endif /* __MDM_ANTRX3TO0_MACRO__ */

/** @} end of antrx3to0 */

/* macros for BlueprintGlobalNameSpace::MDM_anttx3to0 */
/**
 * @defgroup mdm_regs_core_anttx3to0 anttx3to0
 * @brief Antenna table when TX definitions.
 * @{
 */
#ifndef __MDM_ANTTX3TO0_MACRO__
#define __MDM_ANTTX3TO0_MACRO__

/* macros for field table */
/**
 * @defgroup mdm_regs_core_table_field table_field
 * @brief macros for field table
 * @details [31:24] for ant3, [23:16] for ant2, [15:8] for ant1, [7:0] for ant0
 * @{
 */
#define MDM_ANTTX3TO0__TABLE__SHIFT                                           0
#define MDM_ANTTX3TO0__TABLE__WIDTH                                          32
#define MDM_ANTTX3TO0__TABLE__MASK                                  0xffffffffU
#define MDM_ANTTX3TO0__TABLE__READ(src)         ((uint32_t)(src) & 0xffffffffU)
#define MDM_ANTTX3TO0__TABLE__WRITE(src)        ((uint32_t)(src) & 0xffffffffU)
#define MDM_ANTTX3TO0__TABLE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define MDM_ANTTX3TO0__TABLE__VERIFY(src) (!(((uint32_t)(src) & ~0xffffffffU)))
#define MDM_ANTTX3TO0__TABLE__RESET_VALUE                           0x08040201U
/** @} */
#define MDM_ANTTX3TO0__TYPE                                            uint32_t
#define MDM_ANTTX3TO0__READ                                         0xffffffffU
#define MDM_ANTTX3TO0__WRITE                                        0xffffffffU
#define MDM_ANTTX3TO0__PRESERVED                                    0x00000000U
#define MDM_ANTTX3TO0__RESET_VALUE                                  0x08040201U

#endif /* __MDM_ANTTX3TO0_MACRO__ */

/** @} end of anttx3to0 */

/* macros for BlueprintGlobalNameSpace::MDM_antrx7to4 */
/**
 * @defgroup mdm_regs_core_antrx7to4 antrx7to4
 * @brief Antenna table when RX definitions.
 * @{
 */
#ifndef __MDM_ANTRX7TO4_MACRO__
#define __MDM_ANTRX7TO4_MACRO__

/* macros for field table */
/**
 * @defgroup mdm_regs_core_table_field table_field
 * @brief macros for field table
 * @details [31:24] for ant7, [23:16] for ant6, [15:8] for ant5, [7:0] for ant4
 * @{
 */
#define MDM_ANTRX7TO4__TABLE__SHIFT                                           0
#define MDM_ANTRX7TO4__TABLE__WIDTH                                          32
#define MDM_ANTRX7TO4__TABLE__MASK                                  0xffffffffU
#define MDM_ANTRX7TO4__TABLE__READ(src)         ((uint32_t)(src) & 0xffffffffU)
#define MDM_ANTRX7TO4__TABLE__WRITE(src)        ((uint32_t)(src) & 0xffffffffU)
#define MDM_ANTRX7TO4__TABLE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define MDM_ANTRX7TO4__TABLE__VERIFY(src) (!(((uint32_t)(src) & ~0xffffffffU)))
#define MDM_ANTRX7TO4__TABLE__RESET_VALUE                           0x80402010U
/** @} */
#define MDM_ANTRX7TO4__TYPE                                            uint32_t
#define MDM_ANTRX7TO4__READ                                         0xffffffffU
#define MDM_ANTRX7TO4__WRITE                                        0xffffffffU
#define MDM_ANTRX7TO4__PRESERVED                                    0x00000000U
#define MDM_ANTRX7TO4__RESET_VALUE                                  0x80402010U

#endif /* __MDM_ANTRX7TO4_MACRO__ */

/** @} end of antrx7to4 */

/* macros for BlueprintGlobalNameSpace::MDM_anttx7to4 */
/**
 * @defgroup mdm_regs_core_anttx7to4 anttx7to4
 * @brief Antenna table when TX definitions.
 * @{
 */
#ifndef __MDM_ANTTX7TO4_MACRO__
#define __MDM_ANTTX7TO4_MACRO__

/* macros for field table */
/**
 * @defgroup mdm_regs_core_table_field table_field
 * @brief macros for field table
 * @details [31:24] for ant7, [23:16] for ant6, [15:8] for ant5, [7:0] for ant4
 * @{
 */
#define MDM_ANTTX7TO4__TABLE__SHIFT                                           0
#define MDM_ANTTX7TO4__TABLE__WIDTH                                          32
#define MDM_ANTTX7TO4__TABLE__MASK                                  0xffffffffU
#define MDM_ANTTX7TO4__TABLE__READ(src)         ((uint32_t)(src) & 0xffffffffU)
#define MDM_ANTTX7TO4__TABLE__WRITE(src)        ((uint32_t)(src) & 0xffffffffU)
#define MDM_ANTTX7TO4__TABLE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define MDM_ANTTX7TO4__TABLE__VERIFY(src) (!(((uint32_t)(src) & ~0xffffffffU)))
#define MDM_ANTTX7TO4__TABLE__RESET_VALUE                           0x80402010U
/** @} */
#define MDM_ANTTX7TO4__TYPE                                            uint32_t
#define MDM_ANTTX7TO4__READ                                         0xffffffffU
#define MDM_ANTTX7TO4__WRITE                                        0xffffffffU
#define MDM_ANTTX7TO4__PRESERVED                                    0x00000000U
#define MDM_ANTTX7TO4__RESET_VALUE                                  0x80402010U

#endif /* __MDM_ANTTX7TO4_MACRO__ */

/** @} end of anttx7to4 */

/* macros for BlueprintGlobalNameSpace::MDM_antidle */
/**
 * @defgroup mdm_regs_core_antidle antidle
 * @brief Antenna table when neither RX or TX definitions.
 * @{
 */
#ifndef __MDM_ANTIDLE_MACRO__
#define __MDM_ANTIDLE_MACRO__

/* macros for field table */
/**
 * @defgroup mdm_regs_core_table_field table_field
 * @brief macros for field table
 * @details [7:0] for idle, independent of antenna selection
 * @{
 */
#define MDM_ANTIDLE__TABLE__SHIFT                                             0
#define MDM_ANTIDLE__TABLE__WIDTH                                             8
#define MDM_ANTIDLE__TABLE__MASK                                    0x000000ffU
#define MDM_ANTIDLE__TABLE__READ(src)           ((uint32_t)(src) & 0x000000ffU)
#define MDM_ANTIDLE__TABLE__WRITE(src)          ((uint32_t)(src) & 0x000000ffU)
#define MDM_ANTIDLE__TABLE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000ffU) | ((uint32_t)(src) &\
                    0x000000ffU)
#define MDM_ANTIDLE__TABLE__VERIFY(src)   (!(((uint32_t)(src) & ~0x000000ffU)))
#define MDM_ANTIDLE__TABLE__RESET_VALUE                             0x00000000U
/** @} */
#define MDM_ANTIDLE__TYPE                                              uint32_t
#define MDM_ANTIDLE__READ                                           0x000000ffU
#define MDM_ANTIDLE__WRITE                                          0x000000ffU
#define MDM_ANTIDLE__PRESERVED                                      0x00000000U
#define MDM_ANTIDLE__RESET_VALUE                                    0x00000000U

#endif /* __MDM_ANTIDLE_MACRO__ */

/** @} end of antidle */

/* macros for BlueprintGlobalNameSpace::MDM_antid3to0 */
/**
 * @defgroup mdm_regs_core_antid3to0 antid3to0
 * @brief Antenna IDs to match when antmode == 2'b10 definitions.
 * @{
 */
#ifndef __MDM_ANTID3TO0_MACRO__
#define __MDM_ANTID3TO0_MACRO__

/* macros for field ant0 */
/**
 * @defgroup mdm_regs_core_ant0_field ant0_field
 * @brief macros for field ant0
 * @details ID for ant0
 * @{
 */
#define MDM_ANTID3TO0__ANT0__SHIFT                                            0
#define MDM_ANTID3TO0__ANT0__WIDTH                                            7
#define MDM_ANTID3TO0__ANT0__MASK                                   0x0000007fU
#define MDM_ANTID3TO0__ANT0__READ(src)          ((uint32_t)(src) & 0x0000007fU)
#define MDM_ANTID3TO0__ANT0__WRITE(src)         ((uint32_t)(src) & 0x0000007fU)
#define MDM_ANTID3TO0__ANT0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000007fU) | ((uint32_t)(src) &\
                    0x0000007fU)
#define MDM_ANTID3TO0__ANT0__VERIFY(src)  (!(((uint32_t)(src) & ~0x0000007fU)))
#define MDM_ANTID3TO0__ANT0__RESET_VALUE                            0x00000000U
/** @} */

/* macros for field ant1 */
/**
 * @defgroup mdm_regs_core_ant1_field ant1_field
 * @brief macros for field ant1
 * @details ID for ant1
 * @{
 */
#define MDM_ANTID3TO0__ANT1__SHIFT                                            8
#define MDM_ANTID3TO0__ANT1__WIDTH                                            7
#define MDM_ANTID3TO0__ANT1__MASK                                   0x00007f00U
#define MDM_ANTID3TO0__ANT1__READ(src)   (((uint32_t)(src) & 0x00007f00U) >> 8)
#define MDM_ANTID3TO0__ANT1__WRITE(src)  (((uint32_t)(src) << 8) & 0x00007f00U)
#define MDM_ANTID3TO0__ANT1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00007f00U) | (((uint32_t)(src) <<\
                    8) & 0x00007f00U)
#define MDM_ANTID3TO0__ANT1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00007f00U)))
#define MDM_ANTID3TO0__ANT1__RESET_VALUE                            0x00000001U
/** @} */

/* macros for field ant2 */
/**
 * @defgroup mdm_regs_core_ant2_field ant2_field
 * @brief macros for field ant2
 * @details ID for ant2
 * @{
 */
#define MDM_ANTID3TO0__ANT2__SHIFT                                           16
#define MDM_ANTID3TO0__ANT2__WIDTH                                            7
#define MDM_ANTID3TO0__ANT2__MASK                                   0x007f0000U
#define MDM_ANTID3TO0__ANT2__READ(src)  (((uint32_t)(src) & 0x007f0000U) >> 16)
#define MDM_ANTID3TO0__ANT2__WRITE(src) (((uint32_t)(src) << 16) & 0x007f0000U)
#define MDM_ANTID3TO0__ANT2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x007f0000U) | (((uint32_t)(src) <<\
                    16) & 0x007f0000U)
#define MDM_ANTID3TO0__ANT2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x007f0000U)))
#define MDM_ANTID3TO0__ANT2__RESET_VALUE                            0x00000002U
/** @} */

/* macros for field ant3 */
/**
 * @defgroup mdm_regs_core_ant3_field ant3_field
 * @brief macros for field ant3
 * @details ID for ant3
 * @{
 */
#define MDM_ANTID3TO0__ANT3__SHIFT                                           24
#define MDM_ANTID3TO0__ANT3__WIDTH                                            7
#define MDM_ANTID3TO0__ANT3__MASK                                   0x7f000000U
#define MDM_ANTID3TO0__ANT3__READ(src)  (((uint32_t)(src) & 0x7f000000U) >> 24)
#define MDM_ANTID3TO0__ANT3__WRITE(src) (((uint32_t)(src) << 24) & 0x7f000000U)
#define MDM_ANTID3TO0__ANT3__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x7f000000U) | (((uint32_t)(src) <<\
                    24) & 0x7f000000U)
#define MDM_ANTID3TO0__ANT3__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x7f000000U)))
#define MDM_ANTID3TO0__ANT3__RESET_VALUE                            0x00000003U
/** @} */
#define MDM_ANTID3TO0__TYPE                                            uint32_t
#define MDM_ANTID3TO0__READ                                         0x7f7f7f7fU
#define MDM_ANTID3TO0__WRITE                                        0x7f7f7f7fU
#define MDM_ANTID3TO0__PRESERVED                                    0x00000000U
#define MDM_ANTID3TO0__RESET_VALUE                                  0x03020100U

#endif /* __MDM_ANTID3TO0_MACRO__ */

/** @} end of antid3to0 */

/* macros for BlueprintGlobalNameSpace::MDM_antid7to4 */
/**
 * @defgroup mdm_regs_core_antid7to4 antid7to4
 * @brief Antenna IDs to match when antmode == 2'b10 definitions.
 * @{
 */
#ifndef __MDM_ANTID7TO4_MACRO__
#define __MDM_ANTID7TO4_MACRO__

/* macros for field ant4 */
/**
 * @defgroup mdm_regs_core_ant4_field ant4_field
 * @brief macros for field ant4
 * @details ID for ant4
 * @{
 */
#define MDM_ANTID7TO4__ANT4__SHIFT                                            0
#define MDM_ANTID7TO4__ANT4__WIDTH                                            7
#define MDM_ANTID7TO4__ANT4__MASK                                   0x0000007fU
#define MDM_ANTID7TO4__ANT4__READ(src)          ((uint32_t)(src) & 0x0000007fU)
#define MDM_ANTID7TO4__ANT4__WRITE(src)         ((uint32_t)(src) & 0x0000007fU)
#define MDM_ANTID7TO4__ANT4__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000007fU) | ((uint32_t)(src) &\
                    0x0000007fU)
#define MDM_ANTID7TO4__ANT4__VERIFY(src)  (!(((uint32_t)(src) & ~0x0000007fU)))
#define MDM_ANTID7TO4__ANT4__RESET_VALUE                            0x00000004U
/** @} */

/* macros for field ant5 */
/**
 * @defgroup mdm_regs_core_ant5_field ant5_field
 * @brief macros for field ant5
 * @details ID for ant5
 * @{
 */
#define MDM_ANTID7TO4__ANT5__SHIFT                                            8
#define MDM_ANTID7TO4__ANT5__WIDTH                                            7
#define MDM_ANTID7TO4__ANT5__MASK                                   0x00007f00U
#define MDM_ANTID7TO4__ANT5__READ(src)   (((uint32_t)(src) & 0x00007f00U) >> 8)
#define MDM_ANTID7TO4__ANT5__WRITE(src)  (((uint32_t)(src) << 8) & 0x00007f00U)
#define MDM_ANTID7TO4__ANT5__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00007f00U) | (((uint32_t)(src) <<\
                    8) & 0x00007f00U)
#define MDM_ANTID7TO4__ANT5__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00007f00U)))
#define MDM_ANTID7TO4__ANT5__RESET_VALUE                            0x00000005U
/** @} */

/* macros for field ant6 */
/**
 * @defgroup mdm_regs_core_ant6_field ant6_field
 * @brief macros for field ant6
 * @details ID for ant6
 * @{
 */
#define MDM_ANTID7TO4__ANT6__SHIFT                                           16
#define MDM_ANTID7TO4__ANT6__WIDTH                                            7
#define MDM_ANTID7TO4__ANT6__MASK                                   0x007f0000U
#define MDM_ANTID7TO4__ANT6__READ(src)  (((uint32_t)(src) & 0x007f0000U) >> 16)
#define MDM_ANTID7TO4__ANT6__WRITE(src) (((uint32_t)(src) << 16) & 0x007f0000U)
#define MDM_ANTID7TO4__ANT6__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x007f0000U) | (((uint32_t)(src) <<\
                    16) & 0x007f0000U)
#define MDM_ANTID7TO4__ANT6__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x007f0000U)))
#define MDM_ANTID7TO4__ANT6__RESET_VALUE                            0x00000006U
/** @} */

/* macros for field ant7 */
/**
 * @defgroup mdm_regs_core_ant7_field ant7_field
 * @brief macros for field ant7
 * @details ID for ant7
 * @{
 */
#define MDM_ANTID7TO4__ANT7__SHIFT                                           24
#define MDM_ANTID7TO4__ANT7__WIDTH                                            7
#define MDM_ANTID7TO4__ANT7__MASK                                   0x7f000000U
#define MDM_ANTID7TO4__ANT7__READ(src)  (((uint32_t)(src) & 0x7f000000U) >> 24)
#define MDM_ANTID7TO4__ANT7__WRITE(src) (((uint32_t)(src) << 24) & 0x7f000000U)
#define MDM_ANTID7TO4__ANT7__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x7f000000U) | (((uint32_t)(src) <<\
                    24) & 0x7f000000U)
#define MDM_ANTID7TO4__ANT7__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x7f000000U)))
#define MDM_ANTID7TO4__ANT7__RESET_VALUE                            0x00000007U
/** @} */
#define MDM_ANTID7TO4__TYPE                                            uint32_t
#define MDM_ANTID7TO4__READ                                         0x7f7f7f7fU
#define MDM_ANTID7TO4__WRITE                                        0x7f7f7f7fU
#define MDM_ANTID7TO4__PRESERVED                                    0x00000000U
#define MDM_ANTID7TO4__RESET_VALUE                                  0x07060504U

#endif /* __MDM_ANTID7TO4_MACRO__ */

/** @} end of antid7to4 */

/* macros for BlueprintGlobalNameSpace::MDM_wht_ctrl */
/**
 * @defgroup mdm_regs_core_wht_ctrl wht_ctrl
 * @brief Whitening control definitions.
 * @{
 */
#ifndef __MDM_WHT_CTRL_MACRO__
#define __MDM_WHT_CTRL_MACRO__

/* macros for field init_en */
/**
 * @defgroup mdm_regs_core_init_en_field init_en_field
 * @brief macros for field init_en
 * @details enable overriding of the whitening initialization seed
 * @{
 */
#define MDM_WHT_CTRL__INIT_EN__SHIFT                                          0
#define MDM_WHT_CTRL__INIT_EN__WIDTH                                          1
#define MDM_WHT_CTRL__INIT_EN__MASK                                 0x00000001U
#define MDM_WHT_CTRL__INIT_EN__READ(src)        ((uint32_t)(src) & 0x00000001U)
#define MDM_WHT_CTRL__INIT_EN__WRITE(src)       ((uint32_t)(src) & 0x00000001U)
#define MDM_WHT_CTRL__INIT_EN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define MDM_WHT_CTRL__INIT_EN__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define MDM_WHT_CTRL__INIT_EN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define MDM_WHT_CTRL__INIT_EN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define MDM_WHT_CTRL__INIT_EN__RESET_VALUE                          0x00000000U
/** @} */

/* macros for field init_sd */
/**
 * @defgroup mdm_regs_core_init_sd_field init_sd_field
 * @brief macros for field init_sd
 * @details initialization seed
 * @{
 */
#define MDM_WHT_CTRL__INIT_SD__SHIFT                                          1
#define MDM_WHT_CTRL__INIT_SD__WIDTH                                          7
#define MDM_WHT_CTRL__INIT_SD__MASK                                 0x000000feU
#define MDM_WHT_CTRL__INIT_SD__READ(src) (((uint32_t)(src) & 0x000000feU) >> 1)
#define MDM_WHT_CTRL__INIT_SD__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x000000feU)
#define MDM_WHT_CTRL__INIT_SD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000feU) | (((uint32_t)(src) <<\
                    1) & 0x000000feU)
#define MDM_WHT_CTRL__INIT_SD__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x000000feU)))
#define MDM_WHT_CTRL__INIT_SD__RESET_VALUE                          0x00000000U
/** @} */
#define MDM_WHT_CTRL__TYPE                                             uint32_t
#define MDM_WHT_CTRL__READ                                          0x000000ffU
#define MDM_WHT_CTRL__WRITE                                         0x000000ffU
#define MDM_WHT_CTRL__PRESERVED                                     0x00000000U
#define MDM_WHT_CTRL__RESET_VALUE                                   0x00000000U

#endif /* __MDM_WHT_CTRL_MACRO__ */

/** @} end of wht_ctrl */

/* macros for BlueprintGlobalNameSpace::MDM_dccalresults */
/**
 * @defgroup mdm_regs_core_dccalresults dccalresults
 * @brief DC offset calibration results for TIA definitions.
 * @{
 */
#ifndef __MDM_DCCALRESULTS_MACRO__
#define __MDM_DCCALRESULTS_MACRO__

/* macros for field q_off */
/**
 * @defgroup mdm_regs_core_q_off_field q_off_field
 * @brief macros for field q_off
 * @details calculated TIA Q offset
 * @{
 */
#define MDM_DCCALRESULTS__Q_OFF__SHIFT                                        0
#define MDM_DCCALRESULTS__Q_OFF__WIDTH                                        6
#define MDM_DCCALRESULTS__Q_OFF__MASK                               0x0000003fU
#define MDM_DCCALRESULTS__Q_OFF__READ(src)      ((uint32_t)(src) & 0x0000003fU)
#define MDM_DCCALRESULTS__Q_OFF__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field i_off */
/**
 * @defgroup mdm_regs_core_i_off_field i_off_field
 * @brief macros for field i_off
 * @details calculated TIA I offset
 * @{
 */
#define MDM_DCCALRESULTS__I_OFF__SHIFT                                        8
#define MDM_DCCALRESULTS__I_OFF__WIDTH                                        6
#define MDM_DCCALRESULTS__I_OFF__MASK                               0x00003f00U
#define MDM_DCCALRESULTS__I_OFF__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00003f00U) >> 8)
#define MDM_DCCALRESULTS__I_OFF__RESET_VALUE                        0x00000000U
/** @} */
#define MDM_DCCALRESULTS__TYPE                                         uint32_t
#define MDM_DCCALRESULTS__READ                                      0x00003f3fU
#define MDM_DCCALRESULTS__PRESERVED                                 0x00000000U
#define MDM_DCCALRESULTS__RESET_VALUE                               0x00000000U

#endif /* __MDM_DCCALRESULTS_MACRO__ */

/** @} end of dccalresults */

/* macros for BlueprintGlobalNameSpace::MDM_dccalresults2 */
/**
 * @defgroup mdm_regs_core_dccalresults2 dccalresults2
 * @brief DC offset calibration results, averages for TIA definitions.
 * @{
 */
#ifndef __MDM_DCCALRESULTS2_MACRO__
#define __MDM_DCCALRESULTS2_MACRO__

/* macros for field done */
/**
 * @defgroup mdm_regs_core_done_field done_field
 * @brief macros for field done
 * @details software triiger DC calibration done
 * @{
 */
#define MDM_DCCALRESULTS2__DONE__SHIFT                                        0
#define MDM_DCCALRESULTS2__DONE__WIDTH                                        1
#define MDM_DCCALRESULTS2__DONE__MASK                               0x00000001U
#define MDM_DCCALRESULTS2__DONE__READ(src)      ((uint32_t)(src) & 0x00000001U)
#define MDM_DCCALRESULTS2__DONE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define MDM_DCCALRESULTS2__DONE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define MDM_DCCALRESULTS2__DONE__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field avg_q */
/**
 * @defgroup mdm_regs_core_avg_q_field avg_q_field
 * @brief macros for field avg_q
 * @details calculated average of ADC Q samples
 * @{
 */
#define MDM_DCCALRESULTS2__AVG_Q__SHIFT                                       8
#define MDM_DCCALRESULTS2__AVG_Q__WIDTH                                       8
#define MDM_DCCALRESULTS2__AVG_Q__MASK                              0x0000ff00U
#define MDM_DCCALRESULTS2__AVG_Q__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000ff00U) >> 8)
#define MDM_DCCALRESULTS2__AVG_Q__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field avg_i */
/**
 * @defgroup mdm_regs_core_avg_i_field avg_i_field
 * @brief macros for field avg_i
 * @details calculated average of ADC I samples
 * @{
 */
#define MDM_DCCALRESULTS2__AVG_I__SHIFT                                      16
#define MDM_DCCALRESULTS2__AVG_I__WIDTH                                       8
#define MDM_DCCALRESULTS2__AVG_I__MASK                              0x00ff0000U
#define MDM_DCCALRESULTS2__AVG_I__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00ff0000U) >> 16)
#define MDM_DCCALRESULTS2__AVG_I__RESET_VALUE                       0x00000000U
/** @} */
#define MDM_DCCALRESULTS2__TYPE                                        uint32_t
#define MDM_DCCALRESULTS2__READ                                     0x00ffff01U
#define MDM_DCCALRESULTS2__PRESERVED                                0x00000000U
#define MDM_DCCALRESULTS2__RESET_VALUE                              0x00000000U

#endif /* __MDM_DCCALRESULTS2_MACRO__ */

/** @} end of dccalresults2 */

/* macros for BlueprintGlobalNameSpace::MDM_tia_retent_dccalresults */
/**
 * @defgroup mdm_regs_core_tia_retent_dccalresults tia_retent_dccalresults
 * @brief DC offset calibration results for TIA for paris definitions.
 * @{
 */
#ifndef __MDM_TIA_RETENT_DCCALRESULTS_MACRO__
#define __MDM_TIA_RETENT_DCCALRESULTS_MACRO__

/* macros for field q_off */
/**
 * @defgroup mdm_regs_core_q_off_field q_off_field
 * @brief macros for field q_off
 * @details calculated TIA Q offset
 * @{
 */
#define MDM_TIA_RETENT_DCCALRESULTS__Q_OFF__SHIFT                             0
#define MDM_TIA_RETENT_DCCALRESULTS__Q_OFF__WIDTH                             8
#define MDM_TIA_RETENT_DCCALRESULTS__Q_OFF__MASK                    0x000000ffU
#define MDM_TIA_RETENT_DCCALRESULTS__Q_OFF__READ(src) \
                    ((uint32_t)(src)\
                    & 0x000000ffU)
#define MDM_TIA_RETENT_DCCALRESULTS__Q_OFF__RESET_VALUE             0x00000000U
/** @} */

/* macros for field i_off */
/**
 * @defgroup mdm_regs_core_i_off_field i_off_field
 * @brief macros for field i_off
 * @details calculated TIA I offset
 * @{
 */
#define MDM_TIA_RETENT_DCCALRESULTS__I_OFF__SHIFT                             8
#define MDM_TIA_RETENT_DCCALRESULTS__I_OFF__WIDTH                             8
#define MDM_TIA_RETENT_DCCALRESULTS__I_OFF__MASK                    0x0000ff00U
#define MDM_TIA_RETENT_DCCALRESULTS__I_OFF__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000ff00U) >> 8)
#define MDM_TIA_RETENT_DCCALRESULTS__I_OFF__RESET_VALUE             0x00000000U
/** @} */

/* macros for field bb2gain */
/**
 * @defgroup mdm_regs_core_bb2gain_field bb2gain_field
 * @brief macros for field bb2gain
 * @details bb2gain value used in TIA cal
 * @{
 */
#define MDM_TIA_RETENT_DCCALRESULTS__BB2GAIN__SHIFT                          16
#define MDM_TIA_RETENT_DCCALRESULTS__BB2GAIN__WIDTH                           5
#define MDM_TIA_RETENT_DCCALRESULTS__BB2GAIN__MASK                  0x001f0000U
#define MDM_TIA_RETENT_DCCALRESULTS__BB2GAIN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x001f0000U) >> 16)
#define MDM_TIA_RETENT_DCCALRESULTS__BB2GAIN__RESET_VALUE           0x00000000U
/** @} */

/* macros for field done */
/**
 * @defgroup mdm_regs_core_done_field done_field
 * @brief macros for field done
 * @details hardware/software triiger DC calibration done
 * @{
 */
#define MDM_TIA_RETENT_DCCALRESULTS__DONE__SHIFT                             31
#define MDM_TIA_RETENT_DCCALRESULTS__DONE__WIDTH                              1
#define MDM_TIA_RETENT_DCCALRESULTS__DONE__MASK                     0x80000000U
#define MDM_TIA_RETENT_DCCALRESULTS__DONE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x80000000U) >> 31)
#define MDM_TIA_RETENT_DCCALRESULTS__DONE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(1) << 31)
#define MDM_TIA_RETENT_DCCALRESULTS__DONE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(0) << 31)
#define MDM_TIA_RETENT_DCCALRESULTS__DONE__RESET_VALUE              0x00000000U
/** @} */
#define MDM_TIA_RETENT_DCCALRESULTS__TYPE                              uint32_t
#define MDM_TIA_RETENT_DCCALRESULTS__READ                           0x801fffffU
#define MDM_TIA_RETENT_DCCALRESULTS__PRESERVED                      0x00000000U
#define MDM_TIA_RETENT_DCCALRESULTS__RESET_VALUE                    0x00000000U

#endif /* __MDM_TIA_RETENT_DCCALRESULTS_MACRO__ */

/** @} end of tia_retent_dccalresults */

/* macros for BlueprintGlobalNameSpace::MDM_tia_dccalresults2 */
/**
 * @defgroup mdm_regs_core_tia_dccalresults2 tia_dccalresults2
 * @brief DC offset calibration results, averages for TIA for paris definitions.
 * @{
 */
#ifndef __MDM_TIA_DCCALRESULTS2_MACRO__
#define __MDM_TIA_DCCALRESULTS2_MACRO__

/* macros for field avg_q */
/**
 * @defgroup mdm_regs_core_avg_q_field avg_q_field
 * @brief macros for field avg_q
 * @details calculated average of ADC Q samples
 * @{
 */
#define MDM_TIA_DCCALRESULTS2__AVG_Q__SHIFT                                   0
#define MDM_TIA_DCCALRESULTS2__AVG_Q__WIDTH                                   8
#define MDM_TIA_DCCALRESULTS2__AVG_Q__MASK                          0x000000ffU
#define MDM_TIA_DCCALRESULTS2__AVG_Q__READ(src) ((uint32_t)(src) & 0x000000ffU)
#define MDM_TIA_DCCALRESULTS2__AVG_Q__RESET_VALUE                   0x00000000U
/** @} */

/* macros for field avg_i */
/**
 * @defgroup mdm_regs_core_avg_i_field avg_i_field
 * @brief macros for field avg_i
 * @details calculated average of ADC I samples
 * @{
 */
#define MDM_TIA_DCCALRESULTS2__AVG_I__SHIFT                                   8
#define MDM_TIA_DCCALRESULTS2__AVG_I__WIDTH                                   8
#define MDM_TIA_DCCALRESULTS2__AVG_I__MASK                          0x0000ff00U
#define MDM_TIA_DCCALRESULTS2__AVG_I__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000ff00U) >> 8)
#define MDM_TIA_DCCALRESULTS2__AVG_I__RESET_VALUE                   0x00000000U
/** @} */

/* macros for field done */
/**
 * @defgroup mdm_regs_core_done_field done_field
 * @brief macros for field done
 * @details software triiger DC calibration done
 * @{
 */
#define MDM_TIA_DCCALRESULTS2__DONE__SHIFT                                   31
#define MDM_TIA_DCCALRESULTS2__DONE__WIDTH                                    1
#define MDM_TIA_DCCALRESULTS2__DONE__MASK                           0x80000000U
#define MDM_TIA_DCCALRESULTS2__DONE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x80000000U) >> 31)
#define MDM_TIA_DCCALRESULTS2__DONE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(1) << 31)
#define MDM_TIA_DCCALRESULTS2__DONE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(0) << 31)
#define MDM_TIA_DCCALRESULTS2__DONE__RESET_VALUE                    0x00000000U
/** @} */
#define MDM_TIA_DCCALRESULTS2__TYPE                                    uint32_t
#define MDM_TIA_DCCALRESULTS2__READ                                 0x8000ffffU
#define MDM_TIA_DCCALRESULTS2__PRESERVED                            0x00000000U
#define MDM_TIA_DCCALRESULTS2__RESET_VALUE                          0x00000000U

#endif /* __MDM_TIA_DCCALRESULTS2_MACRO__ */

/** @} end of tia_dccalresults2 */

/* macros for BlueprintGlobalNameSpace::MDM_tia_dccalresults3 */
/**
 * @defgroup mdm_regs_core_tia_dccalresults3 tia_dccalresults3
 * @brief Current offset values being applied definitions.
 * @{
 */
#ifndef __MDM_TIA_DCCALRESULTS3_MACRO__
#define __MDM_TIA_DCCALRESULTS3_MACRO__

/* macros for field bb1q_dcoc */
/**
 * @defgroup mdm_regs_core_bb1q_dcoc_field bb1q_dcoc_field
 * @brief macros for field bb1q_dcoc
 * @details bb1q_dooc Q driven by mdm
 * @{
 */
#define MDM_TIA_DCCALRESULTS3__BB1Q_DCOC__SHIFT                               0
#define MDM_TIA_DCCALRESULTS3__BB1Q_DCOC__WIDTH                               8
#define MDM_TIA_DCCALRESULTS3__BB1Q_DCOC__MASK                      0x000000ffU
#define MDM_TIA_DCCALRESULTS3__BB1Q_DCOC__READ(src) \
                    ((uint32_t)(src)\
                    & 0x000000ffU)
#define MDM_TIA_DCCALRESULTS3__BB1Q_DCOC__RESET_VALUE               0x00000000U
/** @} */

/* macros for field bb1i_dcoc */
/**
 * @defgroup mdm_regs_core_bb1i_dcoc_field bb1i_dcoc_field
 * @brief macros for field bb1i_dcoc
 * @details bb1i_dcoc I driven by mdm
 * @{
 */
#define MDM_TIA_DCCALRESULTS3__BB1I_DCOC__SHIFT                               8
#define MDM_TIA_DCCALRESULTS3__BB1I_DCOC__WIDTH                               8
#define MDM_TIA_DCCALRESULTS3__BB1I_DCOC__MASK                      0x0000ff00U
#define MDM_TIA_DCCALRESULTS3__BB1I_DCOC__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000ff00U) >> 8)
#define MDM_TIA_DCCALRESULTS3__BB1I_DCOC__RESET_VALUE               0x00000000U
/** @} */
#define MDM_TIA_DCCALRESULTS3__TYPE                                    uint32_t
#define MDM_TIA_DCCALRESULTS3__READ                                 0x0000ffffU
#define MDM_TIA_DCCALRESULTS3__PRESERVED                            0x00000000U
#define MDM_TIA_DCCALRESULTS3__RESET_VALUE                          0x00000000U

#endif /* __MDM_TIA_DCCALRESULTS3_MACRO__ */

/** @} end of tia_dccalresults3 */

/* macros for BlueprintGlobalNameSpace::MDM_tia_lp_retent_dccalresults */
/**
 * @defgroup mdm_regs_core_tia_lp_retent_dccalresults tia_lp_retent_dccalresults
 * @brief DC offset calibration results for TIA for low power mode for paris definitions.
 * @{
 */
#ifndef __MDM_TIA_LP_RETENT_DCCALRESULTS_MACRO__
#define __MDM_TIA_LP_RETENT_DCCALRESULTS_MACRO__

/* macros for field q_off */
/**
 * @defgroup mdm_regs_core_q_off_field q_off_field
 * @brief macros for field q_off
 * @details calculated TIA Q offset
 * @{
 */
#define MDM_TIA_LP_RETENT_DCCALRESULTS__Q_OFF__SHIFT                          0
#define MDM_TIA_LP_RETENT_DCCALRESULTS__Q_OFF__WIDTH                          8
#define MDM_TIA_LP_RETENT_DCCALRESULTS__Q_OFF__MASK                 0x000000ffU
#define MDM_TIA_LP_RETENT_DCCALRESULTS__Q_OFF__READ(src) \
                    ((uint32_t)(src)\
                    & 0x000000ffU)
#define MDM_TIA_LP_RETENT_DCCALRESULTS__Q_OFF__RESET_VALUE          0x00000000U
/** @} */

/* macros for field i_off */
/**
 * @defgroup mdm_regs_core_i_off_field i_off_field
 * @brief macros for field i_off
 * @details calculated TIA I offset
 * @{
 */
#define MDM_TIA_LP_RETENT_DCCALRESULTS__I_OFF__SHIFT                          8
#define MDM_TIA_LP_RETENT_DCCALRESULTS__I_OFF__WIDTH                          8
#define MDM_TIA_LP_RETENT_DCCALRESULTS__I_OFF__MASK                 0x0000ff00U
#define MDM_TIA_LP_RETENT_DCCALRESULTS__I_OFF__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000ff00U) >> 8)
#define MDM_TIA_LP_RETENT_DCCALRESULTS__I_OFF__RESET_VALUE          0x00000000U
/** @} */

/* macros for field bb2gain */
/**
 * @defgroup mdm_regs_core_bb2gain_field bb2gain_field
 * @brief macros for field bb2gain
 * @details bb2gain value used in TIA cal
 * @{
 */
#define MDM_TIA_LP_RETENT_DCCALRESULTS__BB2GAIN__SHIFT                       16
#define MDM_TIA_LP_RETENT_DCCALRESULTS__BB2GAIN__WIDTH                        5
#define MDM_TIA_LP_RETENT_DCCALRESULTS__BB2GAIN__MASK               0x001f0000U
#define MDM_TIA_LP_RETENT_DCCALRESULTS__BB2GAIN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x001f0000U) >> 16)
#define MDM_TIA_LP_RETENT_DCCALRESULTS__BB2GAIN__RESET_VALUE        0x00000000U
/** @} */

/* macros for field done */
/**
 * @defgroup mdm_regs_core_done_field done_field
 * @brief macros for field done
 * @details hardware/software triiger DC calibration done
 * @{
 */
#define MDM_TIA_LP_RETENT_DCCALRESULTS__DONE__SHIFT                          31
#define MDM_TIA_LP_RETENT_DCCALRESULTS__DONE__WIDTH                           1
#define MDM_TIA_LP_RETENT_DCCALRESULTS__DONE__MASK                  0x80000000U
#define MDM_TIA_LP_RETENT_DCCALRESULTS__DONE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x80000000U) >> 31)
#define MDM_TIA_LP_RETENT_DCCALRESULTS__DONE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(1) << 31)
#define MDM_TIA_LP_RETENT_DCCALRESULTS__DONE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(0) << 31)
#define MDM_TIA_LP_RETENT_DCCALRESULTS__DONE__RESET_VALUE           0x00000000U
/** @} */
#define MDM_TIA_LP_RETENT_DCCALRESULTS__TYPE                           uint32_t
#define MDM_TIA_LP_RETENT_DCCALRESULTS__READ                        0x801fffffU
#define MDM_TIA_LP_RETENT_DCCALRESULTS__PRESERVED                   0x00000000U
#define MDM_TIA_LP_RETENT_DCCALRESULTS__RESET_VALUE                 0x00000000U

#endif /* __MDM_TIA_LP_RETENT_DCCALRESULTS_MACRO__ */

/** @} end of tia_lp_retent_dccalresults */

/* macros for BlueprintGlobalNameSpace::MDM_tia_lp_dccalresults2 */
/**
 * @defgroup mdm_regs_core_tia_lp_dccalresults2 tia_lp_dccalresults2
 * @brief DC offset calibration results, averages for TIA for low power mode for paris definitions.
 * @{
 */
#ifndef __MDM_TIA_LP_DCCALRESULTS2_MACRO__
#define __MDM_TIA_LP_DCCALRESULTS2_MACRO__

/* macros for field avg_q */
/**
 * @defgroup mdm_regs_core_avg_q_field avg_q_field
 * @brief macros for field avg_q
 * @details calculated average of ADC Q samples
 * @{
 */
#define MDM_TIA_LP_DCCALRESULTS2__AVG_Q__SHIFT                                0
#define MDM_TIA_LP_DCCALRESULTS2__AVG_Q__WIDTH                                8
#define MDM_TIA_LP_DCCALRESULTS2__AVG_Q__MASK                       0x000000ffU
#define MDM_TIA_LP_DCCALRESULTS2__AVG_Q__READ(src) \
                    ((uint32_t)(src)\
                    & 0x000000ffU)
#define MDM_TIA_LP_DCCALRESULTS2__AVG_Q__RESET_VALUE                0x00000000U
/** @} */

/* macros for field avg_i */
/**
 * @defgroup mdm_regs_core_avg_i_field avg_i_field
 * @brief macros for field avg_i
 * @details calculated average of ADC I samples
 * @{
 */
#define MDM_TIA_LP_DCCALRESULTS2__AVG_I__SHIFT                                8
#define MDM_TIA_LP_DCCALRESULTS2__AVG_I__WIDTH                                8
#define MDM_TIA_LP_DCCALRESULTS2__AVG_I__MASK                       0x0000ff00U
#define MDM_TIA_LP_DCCALRESULTS2__AVG_I__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000ff00U) >> 8)
#define MDM_TIA_LP_DCCALRESULTS2__AVG_I__RESET_VALUE                0x00000000U
/** @} */

/* macros for field done */
/**
 * @defgroup mdm_regs_core_done_field done_field
 * @brief macros for field done
 * @details software triiger DC calibration done
 * @{
 */
#define MDM_TIA_LP_DCCALRESULTS2__DONE__SHIFT                                31
#define MDM_TIA_LP_DCCALRESULTS2__DONE__WIDTH                                 1
#define MDM_TIA_LP_DCCALRESULTS2__DONE__MASK                        0x80000000U
#define MDM_TIA_LP_DCCALRESULTS2__DONE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x80000000U) >> 31)
#define MDM_TIA_LP_DCCALRESULTS2__DONE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(1) << 31)
#define MDM_TIA_LP_DCCALRESULTS2__DONE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(0) << 31)
#define MDM_TIA_LP_DCCALRESULTS2__DONE__RESET_VALUE                 0x00000000U
/** @} */
#define MDM_TIA_LP_DCCALRESULTS2__TYPE                                 uint32_t
#define MDM_TIA_LP_DCCALRESULTS2__READ                              0x8000ffffU
#define MDM_TIA_LP_DCCALRESULTS2__PRESERVED                         0x00000000U
#define MDM_TIA_LP_DCCALRESULTS2__RESET_VALUE                       0x00000000U

#endif /* __MDM_TIA_LP_DCCALRESULTS2_MACRO__ */

/** @} end of tia_lp_dccalresults2 */

/* macros for BlueprintGlobalNameSpace::MDM_pga_retent_dccalresults */
/**
 * @defgroup mdm_regs_core_pga_retent_dccalresults pga_retent_dccalresults
 * @brief DC offset calibration results for PGA definitions.
 * @{
 */
#ifndef __MDM_PGA_RETENT_DCCALRESULTS_MACRO__
#define __MDM_PGA_RETENT_DCCALRESULTS_MACRO__

/* macros for field q_off */
/**
 * @defgroup mdm_regs_core_q_off_field q_off_field
 * @brief macros for field q_off
 * @details calculated PGA Q offset
 * @{
 */
#define MDM_PGA_RETENT_DCCALRESULTS__Q_OFF__SHIFT                             0
#define MDM_PGA_RETENT_DCCALRESULTS__Q_OFF__WIDTH                             5
#define MDM_PGA_RETENT_DCCALRESULTS__Q_OFF__MASK                    0x0000001fU
#define MDM_PGA_RETENT_DCCALRESULTS__Q_OFF__READ(src) \
                    ((uint32_t)(src)\
                    & 0x0000001fU)
#define MDM_PGA_RETENT_DCCALRESULTS__Q_OFF__RESET_VALUE             0x00000000U
/** @} */

/* macros for field i_off */
/**
 * @defgroup mdm_regs_core_i_off_field i_off_field
 * @brief macros for field i_off
 * @details calculated PGA I offset
 * @{
 */
#define MDM_PGA_RETENT_DCCALRESULTS__I_OFF__SHIFT                             8
#define MDM_PGA_RETENT_DCCALRESULTS__I_OFF__WIDTH                             5
#define MDM_PGA_RETENT_DCCALRESULTS__I_OFF__MASK                    0x00001f00U
#define MDM_PGA_RETENT_DCCALRESULTS__I_OFF__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00001f00U) >> 8)
#define MDM_PGA_RETENT_DCCALRESULTS__I_OFF__RESET_VALUE             0x00000000U
/** @} */

/* macros for field bb2gain */
/**
 * @defgroup mdm_regs_core_bb2gain_field bb2gain_field
 * @brief macros for field bb2gain
 * @details bb2gain value used in PGA cal
 * @{
 */
#define MDM_PGA_RETENT_DCCALRESULTS__BB2GAIN__SHIFT                          16
#define MDM_PGA_RETENT_DCCALRESULTS__BB2GAIN__WIDTH                           5
#define MDM_PGA_RETENT_DCCALRESULTS__BB2GAIN__MASK                  0x001f0000U
#define MDM_PGA_RETENT_DCCALRESULTS__BB2GAIN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x001f0000U) >> 16)
#define MDM_PGA_RETENT_DCCALRESULTS__BB2GAIN__RESET_VALUE           0x00000000U
/** @} */

/* macros for field done */
/**
 * @defgroup mdm_regs_core_done_field done_field
 * @brief macros for field done
 * @details hardware/software triiger DC calibration done
 * @{
 */
#define MDM_PGA_RETENT_DCCALRESULTS__DONE__SHIFT                             31
#define MDM_PGA_RETENT_DCCALRESULTS__DONE__WIDTH                              1
#define MDM_PGA_RETENT_DCCALRESULTS__DONE__MASK                     0x80000000U
#define MDM_PGA_RETENT_DCCALRESULTS__DONE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x80000000U) >> 31)
#define MDM_PGA_RETENT_DCCALRESULTS__DONE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(1) << 31)
#define MDM_PGA_RETENT_DCCALRESULTS__DONE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(0) << 31)
#define MDM_PGA_RETENT_DCCALRESULTS__DONE__RESET_VALUE              0x00000000U
/** @} */
#define MDM_PGA_RETENT_DCCALRESULTS__TYPE                              uint32_t
#define MDM_PGA_RETENT_DCCALRESULTS__READ                           0x801f1f1fU
#define MDM_PGA_RETENT_DCCALRESULTS__PRESERVED                      0x00000000U
#define MDM_PGA_RETENT_DCCALRESULTS__RESET_VALUE                    0x00000000U

#endif /* __MDM_PGA_RETENT_DCCALRESULTS_MACRO__ */

/** @} end of pga_retent_dccalresults */

/* macros for BlueprintGlobalNameSpace::MDM_pga_dccalresults2 */
/**
 * @defgroup mdm_regs_core_pga_dccalresults2 pga_dccalresults2
 * @brief DC offset calibration results, averages for PGA definitions.
 * @{
 */
#ifndef __MDM_PGA_DCCALRESULTS2_MACRO__
#define __MDM_PGA_DCCALRESULTS2_MACRO__

/* macros for field avg_q */
/**
 * @defgroup mdm_regs_core_avg_q_field avg_q_field
 * @brief macros for field avg_q
 * @details calculated average of ADC Q samples
 * @{
 */
#define MDM_PGA_DCCALRESULTS2__AVG_Q__SHIFT                                   0
#define MDM_PGA_DCCALRESULTS2__AVG_Q__WIDTH                                   8
#define MDM_PGA_DCCALRESULTS2__AVG_Q__MASK                          0x000000ffU
#define MDM_PGA_DCCALRESULTS2__AVG_Q__READ(src) ((uint32_t)(src) & 0x000000ffU)
#define MDM_PGA_DCCALRESULTS2__AVG_Q__RESET_VALUE                   0x00000000U
/** @} */

/* macros for field avg_i */
/**
 * @defgroup mdm_regs_core_avg_i_field avg_i_field
 * @brief macros for field avg_i
 * @details calculated average of ADC I samples
 * @{
 */
#define MDM_PGA_DCCALRESULTS2__AVG_I__SHIFT                                   8
#define MDM_PGA_DCCALRESULTS2__AVG_I__WIDTH                                   8
#define MDM_PGA_DCCALRESULTS2__AVG_I__MASK                          0x0000ff00U
#define MDM_PGA_DCCALRESULTS2__AVG_I__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000ff00U) >> 8)
#define MDM_PGA_DCCALRESULTS2__AVG_I__RESET_VALUE                   0x00000000U
/** @} */

/* macros for field done */
/**
 * @defgroup mdm_regs_core_done_field done_field
 * @brief macros for field done
 * @details software triiger DC calibration done
 * @{
 */
#define MDM_PGA_DCCALRESULTS2__DONE__SHIFT                                   31
#define MDM_PGA_DCCALRESULTS2__DONE__WIDTH                                    1
#define MDM_PGA_DCCALRESULTS2__DONE__MASK                           0x80000000U
#define MDM_PGA_DCCALRESULTS2__DONE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x80000000U) >> 31)
#define MDM_PGA_DCCALRESULTS2__DONE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(1) << 31)
#define MDM_PGA_DCCALRESULTS2__DONE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(0) << 31)
#define MDM_PGA_DCCALRESULTS2__DONE__RESET_VALUE                    0x00000000U
/** @} */
#define MDM_PGA_DCCALRESULTS2__TYPE                                    uint32_t
#define MDM_PGA_DCCALRESULTS2__READ                                 0x8000ffffU
#define MDM_PGA_DCCALRESULTS2__PRESERVED                            0x00000000U
#define MDM_PGA_DCCALRESULTS2__RESET_VALUE                          0x00000000U

#endif /* __MDM_PGA_DCCALRESULTS2_MACRO__ */

/** @} end of pga_dccalresults2 */

/* macros for BlueprintGlobalNameSpace::MDM_pga_dccalresults3 */
/**
 * @defgroup mdm_regs_core_pga_dccalresults3 pga_dccalresults3
 * @brief Current offset values being applied definitions.
 * @{
 */
#ifndef __MDM_PGA_DCCALRESULTS3_MACRO__
#define __MDM_PGA_DCCALRESULTS3_MACRO__

/* macros for field bb2q_dcoc */
/**
 * @defgroup mdm_regs_core_bb2q_dcoc_field bb2q_dcoc_field
 * @brief macros for field bb2q_dcoc
 * @details bb2q_dooc Q driven by mdm
 * @{
 */
#define MDM_PGA_DCCALRESULTS3__BB2Q_DCOC__SHIFT                               0
#define MDM_PGA_DCCALRESULTS3__BB2Q_DCOC__WIDTH                               5
#define MDM_PGA_DCCALRESULTS3__BB2Q_DCOC__MASK                      0x0000001fU
#define MDM_PGA_DCCALRESULTS3__BB2Q_DCOC__READ(src) \
                    ((uint32_t)(src)\
                    & 0x0000001fU)
#define MDM_PGA_DCCALRESULTS3__BB2Q_DCOC__RESET_VALUE               0x00000000U
/** @} */

/* macros for field bb2i_dcoc */
/**
 * @defgroup mdm_regs_core_bb2i_dcoc_field bb2i_dcoc_field
 * @brief macros for field bb2i_dcoc
 * @details bb2i_dcoc I driven by mdm
 * @{
 */
#define MDM_PGA_DCCALRESULTS3__BB2I_DCOC__SHIFT                               8
#define MDM_PGA_DCCALRESULTS3__BB2I_DCOC__WIDTH                               5
#define MDM_PGA_DCCALRESULTS3__BB2I_DCOC__MASK                      0x00001f00U
#define MDM_PGA_DCCALRESULTS3__BB2I_DCOC__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00001f00U) >> 8)
#define MDM_PGA_DCCALRESULTS3__BB2I_DCOC__RESET_VALUE               0x00000000U
/** @} */
#define MDM_PGA_DCCALRESULTS3__TYPE                                    uint32_t
#define MDM_PGA_DCCALRESULTS3__READ                                 0x00001f1fU
#define MDM_PGA_DCCALRESULTS3__PRESERVED                            0x00000000U
#define MDM_PGA_DCCALRESULTS3__RESET_VALUE                          0x00000000U

#endif /* __MDM_PGA_DCCALRESULTS3_MACRO__ */

/** @} end of pga_dccalresults3 */

/* macros for BlueprintGlobalNameSpace::MDM_pga_lp_retent_dccalresults */
/**
 * @defgroup mdm_regs_core_pga_lp_retent_dccalresults pga_lp_retent_dccalresults
 * @brief DC offset calibration results for low power mode for PGA definitions.
 * @{
 */
#ifndef __MDM_PGA_LP_RETENT_DCCALRESULTS_MACRO__
#define __MDM_PGA_LP_RETENT_DCCALRESULTS_MACRO__

/* macros for field q_off */
/**
 * @defgroup mdm_regs_core_q_off_field q_off_field
 * @brief macros for field q_off
 * @details calculated PGA Q offset
 * @{
 */
#define MDM_PGA_LP_RETENT_DCCALRESULTS__Q_OFF__SHIFT                          0
#define MDM_PGA_LP_RETENT_DCCALRESULTS__Q_OFF__WIDTH                          5
#define MDM_PGA_LP_RETENT_DCCALRESULTS__Q_OFF__MASK                 0x0000001fU
#define MDM_PGA_LP_RETENT_DCCALRESULTS__Q_OFF__READ(src) \
                    ((uint32_t)(src)\
                    & 0x0000001fU)
#define MDM_PGA_LP_RETENT_DCCALRESULTS__Q_OFF__RESET_VALUE          0x00000000U
/** @} */

/* macros for field i_off */
/**
 * @defgroup mdm_regs_core_i_off_field i_off_field
 * @brief macros for field i_off
 * @details calculated PGA I offset
 * @{
 */
#define MDM_PGA_LP_RETENT_DCCALRESULTS__I_OFF__SHIFT                          8
#define MDM_PGA_LP_RETENT_DCCALRESULTS__I_OFF__WIDTH                          5
#define MDM_PGA_LP_RETENT_DCCALRESULTS__I_OFF__MASK                 0x00001f00U
#define MDM_PGA_LP_RETENT_DCCALRESULTS__I_OFF__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00001f00U) >> 8)
#define MDM_PGA_LP_RETENT_DCCALRESULTS__I_OFF__RESET_VALUE          0x00000000U
/** @} */

/* macros for field bb2gain */
/**
 * @defgroup mdm_regs_core_bb2gain_field bb2gain_field
 * @brief macros for field bb2gain
 * @details bb2gain value used in PGA cal
 * @{
 */
#define MDM_PGA_LP_RETENT_DCCALRESULTS__BB2GAIN__SHIFT                       16
#define MDM_PGA_LP_RETENT_DCCALRESULTS__BB2GAIN__WIDTH                        5
#define MDM_PGA_LP_RETENT_DCCALRESULTS__BB2GAIN__MASK               0x001f0000U
#define MDM_PGA_LP_RETENT_DCCALRESULTS__BB2GAIN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x001f0000U) >> 16)
#define MDM_PGA_LP_RETENT_DCCALRESULTS__BB2GAIN__RESET_VALUE        0x00000000U
/** @} */

/* macros for field done */
/**
 * @defgroup mdm_regs_core_done_field done_field
 * @brief macros for field done
 * @details hardware/software triiger DC calibration done
 * @{
 */
#define MDM_PGA_LP_RETENT_DCCALRESULTS__DONE__SHIFT                          31
#define MDM_PGA_LP_RETENT_DCCALRESULTS__DONE__WIDTH                           1
#define MDM_PGA_LP_RETENT_DCCALRESULTS__DONE__MASK                  0x80000000U
#define MDM_PGA_LP_RETENT_DCCALRESULTS__DONE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x80000000U) >> 31)
#define MDM_PGA_LP_RETENT_DCCALRESULTS__DONE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(1) << 31)
#define MDM_PGA_LP_RETENT_DCCALRESULTS__DONE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(0) << 31)
#define MDM_PGA_LP_RETENT_DCCALRESULTS__DONE__RESET_VALUE           0x00000000U
/** @} */
#define MDM_PGA_LP_RETENT_DCCALRESULTS__TYPE                           uint32_t
#define MDM_PGA_LP_RETENT_DCCALRESULTS__READ                        0x801f1f1fU
#define MDM_PGA_LP_RETENT_DCCALRESULTS__PRESERVED                   0x00000000U
#define MDM_PGA_LP_RETENT_DCCALRESULTS__RESET_VALUE                 0x00000000U

#endif /* __MDM_PGA_LP_RETENT_DCCALRESULTS_MACRO__ */

/** @} end of pga_lp_retent_dccalresults */

/* macros for BlueprintGlobalNameSpace::MDM_pga_lp_dccalresults2 */
/**
 * @defgroup mdm_regs_core_pga_lp_dccalresults2 pga_lp_dccalresults2
 * @brief DC offset calibration results, averages for low power mode for PGA definitions.
 * @{
 */
#ifndef __MDM_PGA_LP_DCCALRESULTS2_MACRO__
#define __MDM_PGA_LP_DCCALRESULTS2_MACRO__

/* macros for field avg_q */
/**
 * @defgroup mdm_regs_core_avg_q_field avg_q_field
 * @brief macros for field avg_q
 * @details calculated average of ADC Q samples
 * @{
 */
#define MDM_PGA_LP_DCCALRESULTS2__AVG_Q__SHIFT                                0
#define MDM_PGA_LP_DCCALRESULTS2__AVG_Q__WIDTH                                8
#define MDM_PGA_LP_DCCALRESULTS2__AVG_Q__MASK                       0x000000ffU
#define MDM_PGA_LP_DCCALRESULTS2__AVG_Q__READ(src) \
                    ((uint32_t)(src)\
                    & 0x000000ffU)
#define MDM_PGA_LP_DCCALRESULTS2__AVG_Q__RESET_VALUE                0x00000000U
/** @} */

/* macros for field avg_i */
/**
 * @defgroup mdm_regs_core_avg_i_field avg_i_field
 * @brief macros for field avg_i
 * @details calculated average of ADC I samples
 * @{
 */
#define MDM_PGA_LP_DCCALRESULTS2__AVG_I__SHIFT                                8
#define MDM_PGA_LP_DCCALRESULTS2__AVG_I__WIDTH                                8
#define MDM_PGA_LP_DCCALRESULTS2__AVG_I__MASK                       0x0000ff00U
#define MDM_PGA_LP_DCCALRESULTS2__AVG_I__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000ff00U) >> 8)
#define MDM_PGA_LP_DCCALRESULTS2__AVG_I__RESET_VALUE                0x00000000U
/** @} */

/* macros for field done */
/**
 * @defgroup mdm_regs_core_done_field done_field
 * @brief macros for field done
 * @details software triiger DC calibration done
 * @{
 */
#define MDM_PGA_LP_DCCALRESULTS2__DONE__SHIFT                                31
#define MDM_PGA_LP_DCCALRESULTS2__DONE__WIDTH                                 1
#define MDM_PGA_LP_DCCALRESULTS2__DONE__MASK                        0x80000000U
#define MDM_PGA_LP_DCCALRESULTS2__DONE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x80000000U) >> 31)
#define MDM_PGA_LP_DCCALRESULTS2__DONE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(1) << 31)
#define MDM_PGA_LP_DCCALRESULTS2__DONE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(0) << 31)
#define MDM_PGA_LP_DCCALRESULTS2__DONE__RESET_VALUE                 0x00000000U
/** @} */
#define MDM_PGA_LP_DCCALRESULTS2__TYPE                                 uint32_t
#define MDM_PGA_LP_DCCALRESULTS2__READ                              0x8000ffffU
#define MDM_PGA_LP_DCCALRESULTS2__PRESERVED                         0x00000000U
#define MDM_PGA_LP_DCCALRESULTS2__RESET_VALUE                       0x00000000U

#endif /* __MDM_PGA_LP_DCCALRESULTS2_MACRO__ */

/** @} end of pga_lp_dccalresults2 */

/* macros for BlueprintGlobalNameSpace::MDM_notch_retent_dccalresults */
/**
 * @defgroup mdm_regs_core_notch_retent_dccalresults notch_retent_dccalresults
 * @brief DC offset calibration results for notch filter definitions.
 * @{
 */
#ifndef __MDM_NOTCH_RETENT_DCCALRESULTS_MACRO__
#define __MDM_NOTCH_RETENT_DCCALRESULTS_MACRO__

/* macros for field ctn */
/**
 * @defgroup mdm_regs_core_ctn_field ctn_field
 * @brief macros for field ctn
 * @details calculated notch ctune
 * @{
 */
#define MDM_NOTCH_RETENT_DCCALRESULTS__CTN__SHIFT                             0
#define MDM_NOTCH_RETENT_DCCALRESULTS__CTN__WIDTH                             6
#define MDM_NOTCH_RETENT_DCCALRESULTS__CTN__MASK                    0x0000003fU
#define MDM_NOTCH_RETENT_DCCALRESULTS__CTN__READ(src) \
                    ((uint32_t)(src)\
                    & 0x0000003fU)
#define MDM_NOTCH_RETENT_DCCALRESULTS__CTN__RESET_VALUE             0x00000000U
/** @} */

/* macros for field done */
/**
 * @defgroup mdm_regs_core_done_field done_field
 * @brief macros for field done
 * @details hardware/software triiger DC calibration done
 * @{
 */
#define MDM_NOTCH_RETENT_DCCALRESULTS__DONE__SHIFT                           31
#define MDM_NOTCH_RETENT_DCCALRESULTS__DONE__WIDTH                            1
#define MDM_NOTCH_RETENT_DCCALRESULTS__DONE__MASK                   0x80000000U
#define MDM_NOTCH_RETENT_DCCALRESULTS__DONE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x80000000U) >> 31)
#define MDM_NOTCH_RETENT_DCCALRESULTS__DONE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(1) << 31)
#define MDM_NOTCH_RETENT_DCCALRESULTS__DONE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(0) << 31)
#define MDM_NOTCH_RETENT_DCCALRESULTS__DONE__RESET_VALUE            0x00000000U
/** @} */
#define MDM_NOTCH_RETENT_DCCALRESULTS__TYPE                            uint32_t
#define MDM_NOTCH_RETENT_DCCALRESULTS__READ                         0x8000003fU
#define MDM_NOTCH_RETENT_DCCALRESULTS__PRESERVED                    0x00000000U
#define MDM_NOTCH_RETENT_DCCALRESULTS__RESET_VALUE                  0x00000000U

#endif /* __MDM_NOTCH_RETENT_DCCALRESULTS_MACRO__ */

/** @} end of notch_retent_dccalresults */

/* macros for BlueprintGlobalNameSpace::MDM_notch_dccalresults2 */
/**
 * @defgroup mdm_regs_core_notch_dccalresults2 notch_dccalresults2
 * @brief DC offset calibration results, averages for notch filter definitions.
 * @{
 */
#ifndef __MDM_NOTCH_DCCALRESULTS2_MACRO__
#define __MDM_NOTCH_DCCALRESULTS2_MACRO__

/* macros for field avg */
/**
 * @defgroup mdm_regs_core_avg_field avg_field
 * @brief macros for field avg
 * @details calculated average of ADC I and ADC Q samples
 * @{
 */
#define MDM_NOTCH_DCCALRESULTS2__AVG__SHIFT                                   0
#define MDM_NOTCH_DCCALRESULTS2__AVG__WIDTH                                   8
#define MDM_NOTCH_DCCALRESULTS2__AVG__MASK                          0x000000ffU
#define MDM_NOTCH_DCCALRESULTS2__AVG__READ(src) ((uint32_t)(src) & 0x000000ffU)
#define MDM_NOTCH_DCCALRESULTS2__AVG__RESET_VALUE                   0x00000000U
/** @} */

/* macros for field done */
/**
 * @defgroup mdm_regs_core_done_field done_field
 * @brief macros for field done
 * @details software triiger DC calibration done
 * @{
 */
#define MDM_NOTCH_DCCALRESULTS2__DONE__SHIFT                                 31
#define MDM_NOTCH_DCCALRESULTS2__DONE__WIDTH                                  1
#define MDM_NOTCH_DCCALRESULTS2__DONE__MASK                         0x80000000U
#define MDM_NOTCH_DCCALRESULTS2__DONE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x80000000U) >> 31)
#define MDM_NOTCH_DCCALRESULTS2__DONE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(1) << 31)
#define MDM_NOTCH_DCCALRESULTS2__DONE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(0) << 31)
#define MDM_NOTCH_DCCALRESULTS2__DONE__RESET_VALUE                  0x00000000U
/** @} */
#define MDM_NOTCH_DCCALRESULTS2__TYPE                                  uint32_t
#define MDM_NOTCH_DCCALRESULTS2__READ                               0x800000ffU
#define MDM_NOTCH_DCCALRESULTS2__PRESERVED                          0x00000000U
#define MDM_NOTCH_DCCALRESULTS2__RESET_VALUE                        0x00000000U

#endif /* __MDM_NOTCH_DCCALRESULTS2_MACRO__ */

/** @} end of notch_dccalresults2 */

/* macros for BlueprintGlobalNameSpace::MDM_agcstatus */
/**
 * @defgroup mdm_regs_core_agcstatus agcstatus
 * @brief Saved state from previous agc operation. Not necessarily a successfully received packet definitions.
 * @{
 */
#ifndef __MDM_AGCSTATUS_MACRO__
#define __MDM_AGCSTATUS_MACRO__

/* macros for field rssi */
/**
 * @defgroup mdm_regs_core_rssi_field rssi_field
 * @brief macros for field rssi
 * @details Received Signal Strength Indicator, absolute dBm. Signed.
 * @{
 */
#define MDM_AGCSTATUS__RSSI__SHIFT                                            0
#define MDM_AGCSTATUS__RSSI__WIDTH                                            8
#define MDM_AGCSTATUS__RSSI__MASK                                   0x000000ffU
#define MDM_AGCSTATUS__RSSI__READ(src)          ((uint32_t)(src) & 0x000000ffU)
#define MDM_AGCSTATUS__RSSI__RESET_VALUE                            0x00000000U
/** @} */

/* macros for field rxgain */
/**
 * @defgroup mdm_regs_core_rxgain_field rxgain_field
 * @brief macros for field rxgain
 * @details Receive gain index
 * @{
 */
#define MDM_AGCSTATUS__RXGAIN__SHIFT                                          8
#define MDM_AGCSTATUS__RXGAIN__WIDTH                                          7
#define MDM_AGCSTATUS__RXGAIN__MASK                                 0x00007f00U
#define MDM_AGCSTATUS__RXGAIN__READ(src) (((uint32_t)(src) & 0x00007f00U) >> 8)
#define MDM_AGCSTATUS__RXGAIN__RESET_VALUE                          0x00000000U
/** @} */

/* macros for field baseline_pwr */
/**
 * @defgroup mdm_regs_core_baseline_pwr_field baseline_pwr_field
 * @brief macros for field baseline_pwr
 * @details Baseline power, post-RXFIR. Signed
 * @{
 */
#define MDM_AGCSTATUS__BASELINE_PWR__SHIFT                                   15
#define MDM_AGCSTATUS__BASELINE_PWR__WIDTH                                    8
#define MDM_AGCSTATUS__BASELINE_PWR__MASK                           0x007f8000U
#define MDM_AGCSTATUS__BASELINE_PWR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x007f8000U) >> 15)
#define MDM_AGCSTATUS__BASELINE_PWR__RESET_VALUE                    0x00000000U
/** @} */

/* macros for field sat_detected */
/**
 * @defgroup mdm_regs_core_sat_detected_field sat_detected_field
 * @brief macros for field sat_detected
 * @details Saturation triggered packet detection
 * @{
 */
#define MDM_AGCSTATUS__SAT_DETECTED__SHIFT                                   23
#define MDM_AGCSTATUS__SAT_DETECTED__WIDTH                                    1
#define MDM_AGCSTATUS__SAT_DETECTED__MASK                           0x00800000U
#define MDM_AGCSTATUS__SAT_DETECTED__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00800000U) >> 23)
#define MDM_AGCSTATUS__SAT_DETECTED__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(1) << 23)
#define MDM_AGCSTATUS__SAT_DETECTED__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(0) << 23)
#define MDM_AGCSTATUS__SAT_DETECTED__RESET_VALUE                    0x00000000U
/** @} */

/* macros for field peak_detected */
/**
 * @defgroup mdm_regs_core_peak_detected_field peak_detected_field
 * @brief macros for field peak_detected
 * @details Analog peak triggered packet detection
 * @{
 */
#define MDM_AGCSTATUS__PEAK_DETECTED__SHIFT                                  24
#define MDM_AGCSTATUS__PEAK_DETECTED__WIDTH                                   1
#define MDM_AGCSTATUS__PEAK_DETECTED__MASK                          0x01000000U
#define MDM_AGCSTATUS__PEAK_DETECTED__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01000000U) >> 24)
#define MDM_AGCSTATUS__PEAK_DETECTED__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(1) << 24)
#define MDM_AGCSTATUS__PEAK_DETECTED__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(0) << 24)
#define MDM_AGCSTATUS__PEAK_DETECTED__RESET_VALUE                   0x00000000U
/** @} */

/* macros for field strong_blocker */
/**
 * @defgroup mdm_regs_core_strong_blocker_field strong_blocker_field
 * @brief macros for field strong_blocker
 * @details strong_blocker = (total_pwr - baseline_pwr) > cf_margin_strong_blocker_thr
 * @{
 */
#define MDM_AGCSTATUS__STRONG_BLOCKER__SHIFT                                 25
#define MDM_AGCSTATUS__STRONG_BLOCKER__WIDTH                                  1
#define MDM_AGCSTATUS__STRONG_BLOCKER__MASK                         0x02000000U
#define MDM_AGCSTATUS__STRONG_BLOCKER__READ(src) \
                    (((uint32_t)(src)\
                    & 0x02000000U) >> 25)
#define MDM_AGCSTATUS__STRONG_BLOCKER__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x02000000U) | ((uint32_t)(1) << 25)
#define MDM_AGCSTATUS__STRONG_BLOCKER__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x02000000U) | ((uint32_t)(0) << 25)
#define MDM_AGCSTATUS__STRONG_BLOCKER__RESET_VALUE                  0x00000000U
/** @} */
#define MDM_AGCSTATUS__TYPE                                            uint32_t
#define MDM_AGCSTATUS__READ                                         0x03ffffffU
#define MDM_AGCSTATUS__PRESERVED                                    0x00000000U
#define MDM_AGCSTATUS__RESET_VALUE                                  0x00000000U

#endif /* __MDM_AGCSTATUS_MACRO__ */

/** @} end of agcstatus */

/* macros for BlueprintGlobalNameSpace::MDM_measfreq */
/**
 * @defgroup mdm_regs_core_measfreq measfreq
 * @brief Frequency offset measured by hardware definitions.
 * @{
 */
#ifndef __MDM_MEASFREQ_MACRO__
#define __MDM_MEASFREQ_MACRO__

/* macros for field freq_offset */
/**
 * @defgroup mdm_regs_core_freq_offset_field freq_offset_field
 * @brief macros for field freq_offset
 * @details Signed quantity. MSB has weight of -1 MHz. Subsequent bits have weight of 1/2 MHz, 1/4 MHz ... LSB has weight of 1/4096 MHz. Value will be updated at initial frequency estimation, and subsequent updates when tracking, if enabled
 * @{
 */
#define MDM_MEASFREQ__FREQ_OFFSET__SHIFT                                      0
#define MDM_MEASFREQ__FREQ_OFFSET__WIDTH                                     13
#define MDM_MEASFREQ__FREQ_OFFSET__MASK                             0x00001fffU
#define MDM_MEASFREQ__FREQ_OFFSET__READ(src)    ((uint32_t)(src) & 0x00001fffU)
#define MDM_MEASFREQ__FREQ_OFFSET__RESET_VALUE                      0x00000000U
/** @} */

/* macros for field dcofftrk_i */
/**
 * @defgroup mdm_regs_core_dcofftrk_i_field dcofftrk_i_field
 * @brief macros for field dcofftrk_i
 * @details DC offset tracking, I side
 * @{
 */
#define MDM_MEASFREQ__DCOFFTRK_I__SHIFT                                      13
#define MDM_MEASFREQ__DCOFFTRK_I__WIDTH                                       8
#define MDM_MEASFREQ__DCOFFTRK_I__MASK                              0x001fe000U
#define MDM_MEASFREQ__DCOFFTRK_I__READ(src) \
                    (((uint32_t)(src)\
                    & 0x001fe000U) >> 13)
#define MDM_MEASFREQ__DCOFFTRK_I__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field dcofftrk_q */
/**
 * @defgroup mdm_regs_core_dcofftrk_q_field dcofftrk_q_field
 * @brief macros for field dcofftrk_q
 * @details DC offset tracking, Q side
 * @{
 */
#define MDM_MEASFREQ__DCOFFTRK_Q__SHIFT                                      21
#define MDM_MEASFREQ__DCOFFTRK_Q__WIDTH                                       8
#define MDM_MEASFREQ__DCOFFTRK_Q__MASK                              0x1fe00000U
#define MDM_MEASFREQ__DCOFFTRK_Q__READ(src) \
                    (((uint32_t)(src)\
                    & 0x1fe00000U) >> 21)
#define MDM_MEASFREQ__DCOFFTRK_Q__RESET_VALUE                       0x00000000U
/** @} */
#define MDM_MEASFREQ__TYPE                                             uint32_t
#define MDM_MEASFREQ__READ                                          0x1fffffffU
#define MDM_MEASFREQ__PRESERVED                                     0x00000000U
#define MDM_MEASFREQ__RESET_VALUE                                   0x00000000U

#endif /* __MDM_MEASFREQ_MACRO__ */

/** @} end of measfreq */

/* macros for BlueprintGlobalNameSpace::MDM_exper */
/**
 * @defgroup mdm_regs_core_exper exper
 * @brief Experimental, not supported in matlab definitions.
 * @{
 */
#ifndef __MDM_EXPER_MACRO__
#define __MDM_EXPER_MACRO__

/* macros for field adjust_to_target_en */
/**
 * @defgroup mdm_regs_core_adjust_to_target_en_field adjust_to_target_en_field
 * @brief macros for field adjust_to_target_en
 * @details bit 0: After power step bit 1: After sat/peak bit 2: After a previous adjust-to-target
 * @{
 */
#define MDM_EXPER__ADJUST_TO_TARGET_EN__SHIFT                                 0
#define MDM_EXPER__ADJUST_TO_TARGET_EN__WIDTH                                 3
#define MDM_EXPER__ADJUST_TO_TARGET_EN__MASK                        0x00000007U
#define MDM_EXPER__ADJUST_TO_TARGET_EN__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000007U)
#define MDM_EXPER__ADJUST_TO_TARGET_EN__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000007U)
#define MDM_EXPER__ADJUST_TO_TARGET_EN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000007U) | ((uint32_t)(src) &\
                    0x00000007U)
#define MDM_EXPER__ADJUST_TO_TARGET_EN__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000007U)))
#define MDM_EXPER__ADJUST_TO_TARGET_EN__RESET_VALUE                 0x00000007U
/** @} */

/* macros for field need_pwr_increase_for_aa */
/**
 * @defgroup mdm_regs_core_need_pwr_increase_for_aa_field need_pwr_increase_for_aa_field
 * @brief macros for field need_pwr_increase_for_aa
 * @details For uncoded rates only, require a power step, saturation or peak detect before enabling AA search
 * @{
 */
#define MDM_EXPER__NEED_PWR_INCREASE_FOR_AA__SHIFT                            3
#define MDM_EXPER__NEED_PWR_INCREASE_FOR_AA__WIDTH                            1
#define MDM_EXPER__NEED_PWR_INCREASE_FOR_AA__MASK                   0x00000008U
#define MDM_EXPER__NEED_PWR_INCREASE_FOR_AA__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000008U) >> 3)
#define MDM_EXPER__NEED_PWR_INCREASE_FOR_AA__WRITE(src) \
                    (((uint32_t)(src)\
                    << 3) & 0x00000008U)
#define MDM_EXPER__NEED_PWR_INCREASE_FOR_AA__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | (((uint32_t)(src) <<\
                    3) & 0x00000008U)
#define MDM_EXPER__NEED_PWR_INCREASE_FOR_AA__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000008U)))
#define MDM_EXPER__NEED_PWR_INCREASE_FOR_AA__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define MDM_EXPER__NEED_PWR_INCREASE_FOR_AA__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)
#define MDM_EXPER__NEED_PWR_INCREASE_FOR_AA__RESET_VALUE            0x00000000U
/** @} */

/* macros for field rxgain_low_mark */
/**
 * @defgroup mdm_regs_core_rxgain_low_mark_field rxgain_low_mark_field
 * @brief macros for field rxgain_low_mark
 * @details Unsigned. If (baseline_pwr < baseline_pwr_low_mark) and (rxgain < rxgain_low_mark), then set rxgain to agcgain_start. The intent is to detect when the signal strength has drifted low (for example, a slowly fading interferer) but did not trigger the usual power step detect, and we are stuck at something other than a max rxgain setting, de-sensitized
 * @{
 */
#define MDM_EXPER__RXGAIN_LOW_MARK__SHIFT                                     4
#define MDM_EXPER__RXGAIN_LOW_MARK__WIDTH                                     7
#define MDM_EXPER__RXGAIN_LOW_MARK__MASK                            0x000007f0U
#define MDM_EXPER__RXGAIN_LOW_MARK__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000007f0U) >> 4)
#define MDM_EXPER__RXGAIN_LOW_MARK__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x000007f0U)
#define MDM_EXPER__RXGAIN_LOW_MARK__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000007f0U) | (((uint32_t)(src) <<\
                    4) & 0x000007f0U)
#define MDM_EXPER__RXGAIN_LOW_MARK__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x000007f0U)))
#define MDM_EXPER__RXGAIN_LOW_MARK__RESET_VALUE                     0x00000000U
/** @} */

/* macros for field baseline_pwr_low_mark */
/**
 * @defgroup mdm_regs_core_baseline_pwr_low_mark_field baseline_pwr_low_mark_field
 * @brief macros for field baseline_pwr_low_mark
 * @details Signed. 8'h80 = -128, disabling check
 * @{
 */
#define MDM_EXPER__BASELINE_PWR_LOW_MARK__SHIFT                              11
#define MDM_EXPER__BASELINE_PWR_LOW_MARK__WIDTH                               8
#define MDM_EXPER__BASELINE_PWR_LOW_MARK__MASK                      0x0007f800U
#define MDM_EXPER__BASELINE_PWR_LOW_MARK__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0007f800U) >> 11)
#define MDM_EXPER__BASELINE_PWR_LOW_MARK__WRITE(src) \
                    (((uint32_t)(src)\
                    << 11) & 0x0007f800U)
#define MDM_EXPER__BASELINE_PWR_LOW_MARK__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0007f800U) | (((uint32_t)(src) <<\
                    11) & 0x0007f800U)
#define MDM_EXPER__BASELINE_PWR_LOW_MARK__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 11) & ~0x0007f800U)))
#define MDM_EXPER__BASELINE_PWR_LOW_MARK__RESET_VALUE               0x00000080U
/** @} */

/* macros for field force_clkgat_en */
/**
 * @defgroup mdm_regs_core_force_clkgat_en_field force_clkgat_en_field
 * @brief macros for field force_clkgat_en
 * @details In the FPGA flow, the enable of a few hand-instantiated clock gates is bypassed. This helps FPGA implementation but results in logic that is different than the actual ASIC. This SHOULD be ok, but in case it isn't, also provide a way to do the same bypassing in ASIC, although likely with some hit on power.
 * @{
 */
#define MDM_EXPER__FORCE_CLKGAT_EN__SHIFT                                    19
#define MDM_EXPER__FORCE_CLKGAT_EN__WIDTH                                     1
#define MDM_EXPER__FORCE_CLKGAT_EN__MASK                            0x00080000U
#define MDM_EXPER__FORCE_CLKGAT_EN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00080000U) >> 19)
#define MDM_EXPER__FORCE_CLKGAT_EN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 19) & 0x00080000U)
#define MDM_EXPER__FORCE_CLKGAT_EN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | (((uint32_t)(src) <<\
                    19) & 0x00080000U)
#define MDM_EXPER__FORCE_CLKGAT_EN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 19) & ~0x00080000U)))
#define MDM_EXPER__FORCE_CLKGAT_EN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | ((uint32_t)(1) << 19)
#define MDM_EXPER__FORCE_CLKGAT_EN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | ((uint32_t)(0) << 19)
#define MDM_EXPER__FORCE_CLKGAT_EN__RESET_VALUE                     0x00000000U
/** @} */

/* macros for field pd_gain_drop_is_relative */
/**
 * @defgroup mdm_regs_core_pd_gain_drop_is_relative_field pd_gain_drop_is_relative_field
 * @brief macros for field pd_gain_drop_is_relative
 * @details If 1, gain drop for LNA/TIA peak detects is relative to current gain (like Sydney). If 0, gain drop for peak detects is relative to max gain (intended for Paris)
 * @{
 */
#define MDM_EXPER__PD_GAIN_DROP_IS_RELATIVE__SHIFT                           20
#define MDM_EXPER__PD_GAIN_DROP_IS_RELATIVE__WIDTH                            1
#define MDM_EXPER__PD_GAIN_DROP_IS_RELATIVE__MASK                   0x00100000U
#define MDM_EXPER__PD_GAIN_DROP_IS_RELATIVE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00100000U) >> 20)
#define MDM_EXPER__PD_GAIN_DROP_IS_RELATIVE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 20) & 0x00100000U)
#define MDM_EXPER__PD_GAIN_DROP_IS_RELATIVE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00100000U) | (((uint32_t)(src) <<\
                    20) & 0x00100000U)
#define MDM_EXPER__PD_GAIN_DROP_IS_RELATIVE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x00100000U)))
#define MDM_EXPER__PD_GAIN_DROP_IS_RELATIVE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00100000U) | ((uint32_t)(1) << 20)
#define MDM_EXPER__PD_GAIN_DROP_IS_RELATIVE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00100000U) | ((uint32_t)(0) << 20)
#define MDM_EXPER__PD_GAIN_DROP_IS_RELATIVE__RESET_VALUE            0x00000000U
/** @} */
#define MDM_EXPER__TYPE                                                uint32_t
#define MDM_EXPER__READ                                             0x001fffffU
#define MDM_EXPER__WRITE                                            0x001fffffU
#define MDM_EXPER__PRESERVED                                        0x00000000U
#define MDM_EXPER__RESET_VALUE                                      0x00040007U

#endif /* __MDM_EXPER_MACRO__ */

/** @} end of exper */

/* macros for BlueprintGlobalNameSpace::MDM_spare0 */
/**
 * @defgroup mdm_regs_core_spare0 spare0
 * @brief spare register 0 definitions.
 * @{
 */
#ifndef __MDM_SPARE0_MACRO__
#define __MDM_SPARE0_MACRO__

/* macros for field val */
/**
 * @defgroup mdm_regs_core_val_field val_field
 * @brief macros for field val
 * @details spare bits
 * @{
 */
#define MDM_SPARE0__VAL__SHIFT                                                0
#define MDM_SPARE0__VAL__WIDTH                                               32
#define MDM_SPARE0__VAL__MASK                                       0xffffffffU
#define MDM_SPARE0__VAL__READ(src)              ((uint32_t)(src) & 0xffffffffU)
#define MDM_SPARE0__VAL__WRITE(src)             ((uint32_t)(src) & 0xffffffffU)
#define MDM_SPARE0__VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define MDM_SPARE0__VAL__VERIFY(src)      (!(((uint32_t)(src) & ~0xffffffffU)))
#define MDM_SPARE0__VAL__RESET_VALUE                                0x00000000U
/** @} */
#define MDM_SPARE0__TYPE                                               uint32_t
#define MDM_SPARE0__READ                                            0xffffffffU
#define MDM_SPARE0__WRITE                                           0xffffffffU
#define MDM_SPARE0__PRESERVED                                       0x00000000U
#define MDM_SPARE0__RESET_VALUE                                     0x00000000U

#endif /* __MDM_SPARE0_MACRO__ */

/** @} end of spare0 */

/* macros for BlueprintGlobalNameSpace::MDM_debug */
/**
 * @defgroup mdm_regs_core_debug debug
 * @brief Expose debug signals on mdm_out definitions.
 * @{
 */
#ifndef __MDM_DEBUG_MACRO__
#define __MDM_DEBUG_MACRO__

/* macros for field select */
/**
 * @defgroup mdm_regs_core_select_field select_field
 * @brief macros for field select
 * @details 0: disable 1: {tia_peakdet_d2, meas_pwr_valid, rfin_peakdet_d2, sat, power_step_detected, r_rxfe_sm[2:0]} 2: {rx_en, rxgain[6:0]} 3: baseline_pwr[7:0] 4: raw_phase[7:0] 5: Upper 8 bits of soft_demod 6: {current_threshold_met, adjust_timing_faster, adjust_timing_slower, pd_out[1:0], r_timesync_sm[2:0]} 7: {enable_syncdemod, update_same, update_flipped, r_freq_mu_ptr[1:0], rx_data_strobe, rx_data_int, access_address_found} 8: {tx_en, tx_data_valid, tx_data, rx_en, rx_data, rx_data_valid, access_address_found, rssi_req} 9: Upper 8 bits of soft_demod_ffe 10: {lr_demap_valid, access_address_found, lr_rate_is_500k, final_flush, lr_rx_data_valid, lr_rx_data, r_vit_sm[1:0]} 11: {coded_corr_det_sign, sat, new_peak, coded_corr_detect, enable_coded_corr_det, r_rxfe_sm[2:0]} 12: rif_i[7:0] 13: rif_q[7:0] 14: {lr_compare_access_address, enable_uncoded for oscorr, match_count0[5:0]} 15: inband_pwr 16: r_last_trg_dbfs 17: {assert_reset_freq_sync, r_made_a_gain_change, adjust_to_target, r_gain_change_adjust_to_target_blocker, c_rfin_pd_meets_thr, c_tia_pd_meets_thr, r_freq_sync_window_select[1:0]} 18: {1'b0, dbg_srch_bit_cntr, dbg_dccal_st} 19: {2'b0, dbg_caldc, dbg_dccal_st} 20: dbg_pga_dcoc_i 21: dbg_pga_dcoc_i 22: {antenna_selected, left_shift, lc_iq_sampling_pulse, lc_direction_find_enable} 23: dbg_rif, which has an upstream mux in rif 24: dccal search value i 25: dccal search value q 26: dccal average i 27: dccal average q 28: dccal bb2 dcoc i 29: dccal bb2 dcoc q 30: dccal bb1 dcoc i 31: dccal bb1 dcoc q 32: cfoest, max range is +/- 0.5 MHz
 * @{
 */
#define MDM_DEBUG__SELECT__SHIFT                                              0
#define MDM_DEBUG__SELECT__WIDTH                                              6
#define MDM_DEBUG__SELECT__MASK                                     0x0000003fU
#define MDM_DEBUG__SELECT__READ(src)            ((uint32_t)(src) & 0x0000003fU)
#define MDM_DEBUG__SELECT__WRITE(src)           ((uint32_t)(src) & 0x0000003fU)
#define MDM_DEBUG__SELECT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000003fU) | ((uint32_t)(src) &\
                    0x0000003fU)
#define MDM_DEBUG__SELECT__VERIFY(src)    (!(((uint32_t)(src) & ~0x0000003fU)))
#define MDM_DEBUG__SELECT__RESET_VALUE                              0x00000000U
/** @} */
#define MDM_DEBUG__TYPE                                                uint32_t
#define MDM_DEBUG__READ                                             0x0000003fU
#define MDM_DEBUG__WRITE                                            0x0000003fU
#define MDM_DEBUG__PRESERVED                                        0x00000000U
#define MDM_DEBUG__RESET_VALUE                                      0x00000000U

#endif /* __MDM_DEBUG_MACRO__ */

/** @} end of debug */

/* macros for BlueprintGlobalNameSpace::MDM_lc2lc */
/**
 * @defgroup mdm_regs_core_lc2lc lc2lc
 * @brief LC2LC loop back mode definitions.
 * @{
 */
#ifndef __MDM_LC2LC_MACRO__
#define __MDM_LC2LC_MACRO__

/* macros for field cntl */
/**
 * @defgroup mdm_regs_core_cntl_field cntl_field
 * @brief macros for field cntl
 * @details Control, 1 to enable loop back
 * @{
 */
#define MDM_LC2LC__CNTL__SHIFT                                                0
#define MDM_LC2LC__CNTL__WIDTH                                                1
#define MDM_LC2LC__CNTL__MASK                                       0x00000001U
#define MDM_LC2LC__CNTL__READ(src)              ((uint32_t)(src) & 0x00000001U)
#define MDM_LC2LC__CNTL__WRITE(src)             ((uint32_t)(src) & 0x00000001U)
#define MDM_LC2LC__CNTL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define MDM_LC2LC__CNTL__VERIFY(src)      (!(((uint32_t)(src) & ~0x00000001U)))
#define MDM_LC2LC__CNTL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define MDM_LC2LC__CNTL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define MDM_LC2LC__CNTL__RESET_VALUE                                0x00000000U
/** @} */
#define MDM_LC2LC__TYPE                                                uint32_t
#define MDM_LC2LC__READ                                             0x00000001U
#define MDM_LC2LC__WRITE                                            0x00000001U
#define MDM_LC2LC__PRESERVED                                        0x00000000U
#define MDM_LC2LC__RESET_VALUE                                      0x00000000U

#endif /* __MDM_LC2LC_MACRO__ */

/** @} end of lc2lc */

/* macros for BlueprintGlobalNameSpace::MDM_irq */
/**
 * @defgroup mdm_regs_core_irq irq
 * @brief interrupt status definitions.
 * @{
 */
#ifndef __MDM_IRQ_MACRO__
#define __MDM_IRQ_MACRO__

/* macros for field dccal_done */
/**
 * @defgroup mdm_regs_core_dccal_done_field dccal_done_field
 * @brief macros for field dccal_done
 * @details Software triggered dc calibration done
 * @{
 */
#define MDM_IRQ__DCCAL_DONE__SHIFT                                            0
#define MDM_IRQ__DCCAL_DONE__WIDTH                                            1
#define MDM_IRQ__DCCAL_DONE__MASK                                   0x00000001U
#define MDM_IRQ__DCCAL_DONE__READ(src)          ((uint32_t)(src) & 0x00000001U)
#define MDM_IRQ__DCCAL_DONE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define MDM_IRQ__DCCAL_DONE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define MDM_IRQ__DCCAL_DONE__RESET_VALUE                            0x00000000U
/** @} */
#define MDM_IRQ__TYPE                                                  uint32_t
#define MDM_IRQ__READ                                               0x00000001U
#define MDM_IRQ__PRESERVED                                          0x00000000U
#define MDM_IRQ__RESET_VALUE                                        0x00000000U

#endif /* __MDM_IRQ_MACRO__ */

/** @} end of irq */

/* macros for BlueprintGlobalNameSpace::MDM_irqm */
/**
 * @defgroup mdm_regs_core_irqm irqm
 * @brief interrupt mask definitions.
 * @{
 */
#ifndef __MDM_IRQM_MACRO__
#define __MDM_IRQM_MACRO__

/* macros for field dccal_done */
/**
 * @defgroup mdm_regs_core_dccal_done_field dccal_done_field
 * @brief macros for field dccal_done
 * @details Software triggered dc calibration done mask
 * @{
 */
#define MDM_IRQM__DCCAL_DONE__SHIFT                                           0
#define MDM_IRQM__DCCAL_DONE__WIDTH                                           1
#define MDM_IRQM__DCCAL_DONE__MASK                                  0x00000001U
#define MDM_IRQM__DCCAL_DONE__READ(src)         ((uint32_t)(src) & 0x00000001U)
#define MDM_IRQM__DCCAL_DONE__WRITE(src)        ((uint32_t)(src) & 0x00000001U)
#define MDM_IRQM__DCCAL_DONE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define MDM_IRQM__DCCAL_DONE__VERIFY(src) (!(((uint32_t)(src) & ~0x00000001U)))
#define MDM_IRQM__DCCAL_DONE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define MDM_IRQM__DCCAL_DONE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define MDM_IRQM__DCCAL_DONE__RESET_VALUE                           0x00000000U
/** @} */
#define MDM_IRQM__TYPE                                                 uint32_t
#define MDM_IRQM__READ                                              0x00000001U
#define MDM_IRQM__WRITE                                             0x00000001U
#define MDM_IRQM__PRESERVED                                         0x00000000U
#define MDM_IRQM__RESET_VALUE                                       0x00000000U

#endif /* __MDM_IRQM_MACRO__ */

/** @} end of irqm */

/* macros for BlueprintGlobalNameSpace::MDM_irqc */
/**
 * @defgroup mdm_regs_core_irqc irqc
 * @brief interrupt clear definitions.
 * @{
 */
#ifndef __MDM_IRQC_MACRO__
#define __MDM_IRQC_MACRO__

/* macros for field dccal_done */
/**
 * @defgroup mdm_regs_core_dccal_done_field dccal_done_field
 * @brief macros for field dccal_done
 * @details Software triggered dc calibration done clear
 * @{
 */
#define MDM_IRQC__DCCAL_DONE__SHIFT                                           0
#define MDM_IRQC__DCCAL_DONE__WIDTH                                           1
#define MDM_IRQC__DCCAL_DONE__MASK                                  0x00000001U
#define MDM_IRQC__DCCAL_DONE__READ(src)         ((uint32_t)(src) & 0x00000001U)
#define MDM_IRQC__DCCAL_DONE__WRITE(src)        ((uint32_t)(src) & 0x00000001U)
#define MDM_IRQC__DCCAL_DONE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define MDM_IRQC__DCCAL_DONE__VERIFY(src) (!(((uint32_t)(src) & ~0x00000001U)))
#define MDM_IRQC__DCCAL_DONE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define MDM_IRQC__DCCAL_DONE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define MDM_IRQC__DCCAL_DONE__RESET_VALUE                           0x00000000U
/** @} */
#define MDM_IRQC__TYPE                                                 uint32_t
#define MDM_IRQC__READ                                              0x00000001U
#define MDM_IRQC__WRITE                                             0x00000001U
#define MDM_IRQC__PRESERVED                                         0x00000000U
#define MDM_IRQC__RESET_VALUE                                       0x00000000U

#endif /* __MDM_IRQC_MACRO__ */

/** @} end of irqc */

/* macros for BlueprintGlobalNameSpace::MDM_err_inj */
/**
 * @defgroup mdm_regs_core_err_inj err_inj
 * @brief error injection control, used for FPGA emulation only definitions.
 * @{
 */
#ifndef __MDM_ERR_INJ_MACRO__
#define __MDM_ERR_INJ_MACRO__

/* macros for field en */
/**
 * @defgroup mdm_regs_core_en_field en_field
 * @brief macros for field en
 * @details 1 to enable error injection
 * @{
 */
#define MDM_ERR_INJ__EN__SHIFT                                                0
#define MDM_ERR_INJ__EN__WIDTH                                                1
#define MDM_ERR_INJ__EN__MASK                                       0x00000001U
#define MDM_ERR_INJ__EN__READ(src)              ((uint32_t)(src) & 0x00000001U)
#define MDM_ERR_INJ__EN__WRITE(src)             ((uint32_t)(src) & 0x00000001U)
#define MDM_ERR_INJ__EN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define MDM_ERR_INJ__EN__VERIFY(src)      (!(((uint32_t)(src) & ~0x00000001U)))
#define MDM_ERR_INJ__EN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define MDM_ERR_INJ__EN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define MDM_ERR_INJ__EN__RESET_VALUE                                0x00000000U
/** @} */

/* macros for field lfsr_seed */
/**
 * @defgroup mdm_regs_core_lfsr_seed_field lfsr_seed_field
 * @brief macros for field lfsr_seed
 * @details lfsr seed
 * @{
 */
#define MDM_ERR_INJ__LFSR_SEED__SHIFT                                         1
#define MDM_ERR_INJ__LFSR_SEED__WIDTH                                        16
#define MDM_ERR_INJ__LFSR_SEED__MASK                                0x0001fffeU
#define MDM_ERR_INJ__LFSR_SEED__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0001fffeU) >> 1)
#define MDM_ERR_INJ__LFSR_SEED__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x0001fffeU)
#define MDM_ERR_INJ__LFSR_SEED__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0001fffeU) | (((uint32_t)(src) <<\
                    1) & 0x0001fffeU)
#define MDM_ERR_INJ__LFSR_SEED__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x0001fffeU)))
#define MDM_ERR_INJ__LFSR_SEED__RESET_VALUE                         0x00000005U
/** @} */
#define MDM_ERR_INJ__TYPE                                              uint32_t
#define MDM_ERR_INJ__READ                                           0x0001ffffU
#define MDM_ERR_INJ__WRITE                                          0x0001ffffU
#define MDM_ERR_INJ__PRESERVED                                      0x00000000U
#define MDM_ERR_INJ__RESET_VALUE                                    0x0000000aU

#endif /* __MDM_ERR_INJ_MACRO__ */

/** @} end of err_inj */

/* macros for BlueprintGlobalNameSpace::MDM_debug32 */
/**
 * @defgroup mdm_regs_core_debug32 debug32
 * @brief Expose debug signals on dbg32_out for FPGA emulation only definitions.
 * @{
 */
#ifndef __MDM_DEBUG32_MACRO__
#define __MDM_DEBUG32_MACRO__

/* macros for field select0 */
/**
 * @defgroup mdm_regs_core_select0_field select0_field
 * @brief macros for field select0
 * @details select debug out for dbg32_out[7:0]
 * @{
 */
#define MDM_DEBUG32__SELECT0__SHIFT                                           0
#define MDM_DEBUG32__SELECT0__WIDTH                                           5
#define MDM_DEBUG32__SELECT0__MASK                                  0x0000001fU
#define MDM_DEBUG32__SELECT0__READ(src)         ((uint32_t)(src) & 0x0000001fU)
#define MDM_DEBUG32__SELECT0__WRITE(src)        ((uint32_t)(src) & 0x0000001fU)
#define MDM_DEBUG32__SELECT0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000001fU) | ((uint32_t)(src) &\
                    0x0000001fU)
#define MDM_DEBUG32__SELECT0__VERIFY(src) (!(((uint32_t)(src) & ~0x0000001fU)))
#define MDM_DEBUG32__SELECT0__RESET_VALUE                           0x00000000U
/** @} */

/* macros for field select1 */
/**
 * @defgroup mdm_regs_core_select1_field select1_field
 * @brief macros for field select1
 * @details select debug out for dbg32_out[7:0]
 * @{
 */
#define MDM_DEBUG32__SELECT1__SHIFT                                           8
#define MDM_DEBUG32__SELECT1__WIDTH                                           5
#define MDM_DEBUG32__SELECT1__MASK                                  0x00001f00U
#define MDM_DEBUG32__SELECT1__READ(src)  (((uint32_t)(src) & 0x00001f00U) >> 8)
#define MDM_DEBUG32__SELECT1__WRITE(src) (((uint32_t)(src) << 8) & 0x00001f00U)
#define MDM_DEBUG32__SELECT1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00001f00U) | (((uint32_t)(src) <<\
                    8) & 0x00001f00U)
#define MDM_DEBUG32__SELECT1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00001f00U)))
#define MDM_DEBUG32__SELECT1__RESET_VALUE                           0x00000000U
/** @} */

/* macros for field select2 */
/**
 * @defgroup mdm_regs_core_select2_field select2_field
 * @brief macros for field select2
 * @details select debug out for dbg32_out[7:0]
 * @{
 */
#define MDM_DEBUG32__SELECT2__SHIFT                                          16
#define MDM_DEBUG32__SELECT2__WIDTH                                           5
#define MDM_DEBUG32__SELECT2__MASK                                  0x001f0000U
#define MDM_DEBUG32__SELECT2__READ(src) (((uint32_t)(src) & 0x001f0000U) >> 16)
#define MDM_DEBUG32__SELECT2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x001f0000U)
#define MDM_DEBUG32__SELECT2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x001f0000U) | (((uint32_t)(src) <<\
                    16) & 0x001f0000U)
#define MDM_DEBUG32__SELECT2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x001f0000U)))
#define MDM_DEBUG32__SELECT2__RESET_VALUE                           0x00000000U
/** @} */

/* macros for field select3 */
/**
 * @defgroup mdm_regs_core_select3_field select3_field
 * @brief macros for field select3
 * @details select debug out for dbg32_out[7:0]
 * @{
 */
#define MDM_DEBUG32__SELECT3__SHIFT                                          24
#define MDM_DEBUG32__SELECT3__WIDTH                                           5
#define MDM_DEBUG32__SELECT3__MASK                                  0x1f000000U
#define MDM_DEBUG32__SELECT3__READ(src) (((uint32_t)(src) & 0x1f000000U) >> 24)
#define MDM_DEBUG32__SELECT3__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x1f000000U)
#define MDM_DEBUG32__SELECT3__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x1f000000U) | (((uint32_t)(src) <<\
                    24) & 0x1f000000U)
#define MDM_DEBUG32__SELECT3__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x1f000000U)))
#define MDM_DEBUG32__SELECT3__RESET_VALUE                           0x00000000U
/** @} */

/* macros for field negedge_q */
/**
 * @defgroup mdm_regs_core_negedge_q_field negedge_q_field
 * @brief macros for field negedge_q
 * @details latch rif_q on neg edge of clk16_ddr
 * @{
 */
#define MDM_DEBUG32__NEGEDGE_Q__SHIFT                                        29
#define MDM_DEBUG32__NEGEDGE_Q__WIDTH                                         1
#define MDM_DEBUG32__NEGEDGE_Q__MASK                                0x20000000U
#define MDM_DEBUG32__NEGEDGE_Q__READ(src) \
                    (((uint32_t)(src)\
                    & 0x20000000U) >> 29)
#define MDM_DEBUG32__NEGEDGE_Q__WRITE(src) \
                    (((uint32_t)(src)\
                    << 29) & 0x20000000U)
#define MDM_DEBUG32__NEGEDGE_Q__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | (((uint32_t)(src) <<\
                    29) & 0x20000000U)
#define MDM_DEBUG32__NEGEDGE_Q__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 29) & ~0x20000000U)))
#define MDM_DEBUG32__NEGEDGE_Q__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | ((uint32_t)(1) << 29)
#define MDM_DEBUG32__NEGEDGE_Q__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x20000000U) | ((uint32_t)(0) << 29)
#define MDM_DEBUG32__NEGEDGE_Q__RESET_VALUE                         0x00000000U
/** @} */

/* macros for field negedge_txdm */
/**
 * @defgroup mdm_regs_core_negedge_txdm_field negedge_txdm_field
 * @brief macros for field negedge_txdm
 * @details latch tx data msb on neg edge of clk16_ddr
 * @{
 */
#define MDM_DEBUG32__NEGEDGE_TXDM__SHIFT                                     30
#define MDM_DEBUG32__NEGEDGE_TXDM__WIDTH                                      1
#define MDM_DEBUG32__NEGEDGE_TXDM__MASK                             0x40000000U
#define MDM_DEBUG32__NEGEDGE_TXDM__READ(src) \
                    (((uint32_t)(src)\
                    & 0x40000000U) >> 30)
#define MDM_DEBUG32__NEGEDGE_TXDM__WRITE(src) \
                    (((uint32_t)(src)\
                    << 30) & 0x40000000U)
#define MDM_DEBUG32__NEGEDGE_TXDM__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | (((uint32_t)(src) <<\
                    30) & 0x40000000U)
#define MDM_DEBUG32__NEGEDGE_TXDM__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 30) & ~0x40000000U)))
#define MDM_DEBUG32__NEGEDGE_TXDM__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(1) << 30)
#define MDM_DEBUG32__NEGEDGE_TXDM__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x40000000U) | ((uint32_t)(0) << 30)
#define MDM_DEBUG32__NEGEDGE_TXDM__RESET_VALUE                      0x00000000U
/** @} */

/* macros for field negedge_rxgm */
/**
 * @defgroup mdm_regs_core_negedge_rxgm_field negedge_rxgm_field
 * @brief macros for field negedge_rxgm
 * @details latch rx gain msb on neg edge of clk16_ddr
 * @{
 */
#define MDM_DEBUG32__NEGEDGE_RXGM__SHIFT                                     31
#define MDM_DEBUG32__NEGEDGE_RXGM__WIDTH                                      1
#define MDM_DEBUG32__NEGEDGE_RXGM__MASK                             0x80000000U
#define MDM_DEBUG32__NEGEDGE_RXGM__READ(src) \
                    (((uint32_t)(src)\
                    & 0x80000000U) >> 31)
#define MDM_DEBUG32__NEGEDGE_RXGM__WRITE(src) \
                    (((uint32_t)(src)\
                    << 31) & 0x80000000U)
#define MDM_DEBUG32__NEGEDGE_RXGM__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | (((uint32_t)(src) <<\
                    31) & 0x80000000U)
#define MDM_DEBUG32__NEGEDGE_RXGM__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 31) & ~0x80000000U)))
#define MDM_DEBUG32__NEGEDGE_RXGM__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(1) << 31)
#define MDM_DEBUG32__NEGEDGE_RXGM__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(0) << 31)
#define MDM_DEBUG32__NEGEDGE_RXGM__RESET_VALUE                      0x00000000U
/** @} */
#define MDM_DEBUG32__TYPE                                              uint32_t
#define MDM_DEBUG32__READ                                           0xff1f1f1fU
#define MDM_DEBUG32__WRITE                                          0xff1f1f1fU
#define MDM_DEBUG32__PRESERVED                                      0x00000000U
#define MDM_DEBUG32__RESET_VALUE                                    0x00000000U

#endif /* __MDM_DEBUG32_MACRO__ */

/** @} end of debug32 */

/* macros for BlueprintGlobalNameSpace::MDM_duo */
/**
 * @defgroup mdm_regs_core_duo duo
 * @brief path loss intended for FPGA/ASIC duo definitions.
 * @{
 */
#ifndef __MDM_DUO_MACRO__
#define __MDM_DUO_MACRO__

/* macros for field path_loss */
/**
 * @defgroup mdm_regs_core_path_loss_field path_loss_field
 * @brief macros for field path_loss
 * @{
 */
#define MDM_DUO__PATH_LOSS__SHIFT                                             0
#define MDM_DUO__PATH_LOSS__WIDTH                                             7
#define MDM_DUO__PATH_LOSS__MASK                                    0x0000007fU
#define MDM_DUO__PATH_LOSS__READ(src)           ((uint32_t)(src) & 0x0000007fU)
#define MDM_DUO__PATH_LOSS__WRITE(src)          ((uint32_t)(src) & 0x0000007fU)
#define MDM_DUO__PATH_LOSS__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000007fU) | ((uint32_t)(src) &\
                    0x0000007fU)
#define MDM_DUO__PATH_LOSS__VERIFY(src)   (!(((uint32_t)(src) & ~0x0000007fU)))
#define MDM_DUO__PATH_LOSS__RESET_VALUE                             0x00000046U
/** @} */
#define MDM_DUO__TYPE                                                  uint32_t
#define MDM_DUO__READ                                               0x0000007fU
#define MDM_DUO__WRITE                                              0x0000007fU
#define MDM_DUO__PRESERVED                                          0x00000000U
#define MDM_DUO__RESET_VALUE                                        0x00000046U

#endif /* __MDM_DUO_MACRO__ */

/** @} end of duo */

/* macros for BlueprintGlobalNameSpace::MDM_core_id */
/**
 * @defgroup mdm_regs_core_core_id core_id
 * @brief modem ID register definitions.
 * @{
 */
#ifndef __MDM_CORE_ID_MACRO__
#define __MDM_CORE_ID_MACRO__

/* macros for field core_id */
/**
 * @defgroup mdm_regs_core_core_id_field core_id_field
 * @brief macros for field core_id
 * @details that's MDM in hex
 * @{
 */
#define MDM_CORE_ID__CORE_ID__SHIFT                                           0
#define MDM_CORE_ID__CORE_ID__WIDTH                                          32
#define MDM_CORE_ID__CORE_ID__MASK                                  0xffffffffU
#define MDM_CORE_ID__CORE_ID__READ(src)         ((uint32_t)(src) & 0xffffffffU)
#define MDM_CORE_ID__CORE_ID__RESET_VALUE                           0x4d444d20U
/** @} */
#define MDM_CORE_ID__TYPE                                              uint32_t
#define MDM_CORE_ID__READ                                           0xffffffffU
#define MDM_CORE_ID__PRESERVED                                      0x00000000U
#define MDM_CORE_ID__RESET_VALUE                                    0x4d444d20U

#endif /* __MDM_CORE_ID_MACRO__ */

/** @} end of core_id */

/** @} end of MDM_REGS_CORE */
#endif /* __REG_MDM_REGS_CORE_H__ */
