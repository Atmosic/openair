/*                                                                           */
/* File:       pmu_swreg_regs_core_macro.h                                   */
/*                                                                           */
/* Arguments:  /cad/tools/cadence/blueprint_3.7.5/Linux-64bit/blueprint -eval*/
/*             $DEFINE_PROPERTY=1; -ansic pmu_swreg_regs_core.rdl            */
/*                                                                           */
/* Blueprint:   3.7.5 (Wed Feb 1 23:58:40 PST 2012)                          */
/* Machine:    gull                                                          */
/* OS:         Linux 2.6.32-696.13.2.el6.x86_64                              */
/* Description:                                                              */
/*                                                                           */
/* No Description Provided                                                   */
/*                                                                           */
/* Copyright (C) 2021 Atmosic Technologies.  All rights reserved             */
/*                                                                           */


#ifndef __REG_PMU_SWREG_REGS_CORE_H__
#define __REG_PMU_SWREG_REGS_CORE_H__

/**
 *****************************************************************************
 * @defgroup PMU_SWREG_REGS_CORE pmu_swreg_regs_core
 * @ingroup AT_REG
 * @brief pmu_swreg_regs_core definitions.
 * @{
 *****************************************************************************
 */

/* macros for BlueprintGlobalNameSpace::SWREG_swreg_ctrl_0 */
/**
 * @defgroup pmu_swreg_regs_core_swreg_ctrl_0 swreg_ctrl_0
 * @brief swreg reg 0 For fields that refer to the sources the order is: 2: Battery 1: Store 0: Harvester For fields that refer to the destinations the order is: 4: Store 3: AVDD 2: VDDIO 1: VDDAUX 0: DVDD For fields that refer to the supplies the order is: 3: AVDD 2: VDDIO 1: VDDAUX 0: DVDD For fields that refer to the power transfer modes the order is: 13: None12: Battery -> AVDD11: Battery -> VDDIO10: Battery -> VDDAUX9: Battery -> DVDD8: Store -> AVDD7: Store -> VDDIO6: Store -> VDDAUX5: Store -> DVDD4: Harvester -> AVDD3: Harvester -> VDDIO2: Harvester -> VDDAUX1: Harvester -> DVDD0: Harvester -> Store definitions.
 * @{
 */
#ifndef __SWREG_SWREG_CTRL_0_MACRO__
#define __SWREG_SWREG_CTRL_0_MACRO__

/* macros for field overrideBuckBoost */
/**
 * @defgroup pmu_swreg_regs_core_overrideBuckBoost_field overrideBuckBoost_field
 * @brief macros for field overrideBuckBoost
 * @details override the default buck-boost mode
 * @{
 */
#define SWREG_SWREG_CTRL_0__OVERRIDEBUCKBOOST__SHIFT                          0
#define SWREG_SWREG_CTRL_0__OVERRIDEBUCKBOOST__WIDTH                          1
#define SWREG_SWREG_CTRL_0__OVERRIDEBUCKBOOST__MASK                 0x00000001U
#define SWREG_SWREG_CTRL_0__OVERRIDEBUCKBOOST__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define SWREG_SWREG_CTRL_0__OVERRIDEBUCKBOOST__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define SWREG_SWREG_CTRL_0__OVERRIDEBUCKBOOST__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define SWREG_SWREG_CTRL_0__OVERRIDEBUCKBOOST__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define SWREG_SWREG_CTRL_0__OVERRIDEBUCKBOOST__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define SWREG_SWREG_CTRL_0__OVERRIDEBUCKBOOST__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
/** @} */

/* macros for field buck_ovr */
/**
 * @defgroup pmu_swreg_regs_core_buck_ovr_field buck_ovr_field
 * @brief macros for field buck_ovr
 * @details 1 sets the respective mode to buck
 * @{
 */
#define SWREG_SWREG_CTRL_0__BUCK_OVR__SHIFT                                   1
#define SWREG_SWREG_CTRL_0__BUCK_OVR__WIDTH                                  13
#define SWREG_SWREG_CTRL_0__BUCK_OVR__MASK                          0x00003ffeU
#define SWREG_SWREG_CTRL_0__BUCK_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00003ffeU) >> 1)
#define SWREG_SWREG_CTRL_0__BUCK_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00003ffeU)
#define SWREG_SWREG_CTRL_0__BUCK_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00003ffeU) | (((uint32_t)(src) <<\
                    1) & 0x00003ffeU)
#define SWREG_SWREG_CTRL_0__BUCK_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00003ffeU)))
/** @} */

/* macros for field boost_ovr */
/**
 * @defgroup pmu_swreg_regs_core_boost_ovr_field boost_ovr_field
 * @brief macros for field boost_ovr
 * @details 1 sets the respective mode to boost
 * @{
 */
#define SWREG_SWREG_CTRL_0__BOOST_OVR__SHIFT                                 14
#define SWREG_SWREG_CTRL_0__BOOST_OVR__WIDTH                                 13
#define SWREG_SWREG_CTRL_0__BOOST_OVR__MASK                         0x07ffc000U
#define SWREG_SWREG_CTRL_0__BOOST_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x07ffc000U) >> 14)
#define SWREG_SWREG_CTRL_0__BOOST_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 14) & 0x07ffc000U)
#define SWREG_SWREG_CTRL_0__BOOST_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x07ffc000U) | (((uint32_t)(src) <<\
                    14) & 0x07ffc000U)
#define SWREG_SWREG_CTRL_0__BOOST_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 14) & ~0x07ffc000U)))
/** @} */

/* macros for field directlyCCM */
/**
 * @defgroup pmu_swreg_regs_core_directlyCCM_field directlyCCM_field
 * @brief macros for field directlyCCM
 * @details start directly in CCM mode, skipping DCM for this destination
 * @{
 */
#define SWREG_SWREG_CTRL_0__DIRECTLYCCM__SHIFT                               27
#define SWREG_SWREG_CTRL_0__DIRECTLYCCM__WIDTH                                5
#define SWREG_SWREG_CTRL_0__DIRECTLYCCM__MASK                       0xf8000000U
#define SWREG_SWREG_CTRL_0__DIRECTLYCCM__READ(src) \
                    (((uint32_t)(src)\
                    & 0xf8000000U) >> 27)
#define SWREG_SWREG_CTRL_0__DIRECTLYCCM__WRITE(src) \
                    (((uint32_t)(src)\
                    << 27) & 0xf8000000U)
#define SWREG_SWREG_CTRL_0__DIRECTLYCCM__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xf8000000U) | (((uint32_t)(src) <<\
                    27) & 0xf8000000U)
#define SWREG_SWREG_CTRL_0__DIRECTLYCCM__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 27) & ~0xf8000000U)))
/** @} */
#define SWREG_SWREG_CTRL_0__TYPE                                       uint32_t
#define SWREG_SWREG_CTRL_0__READ                                    0xffffffffU
#define SWREG_SWREG_CTRL_0__WRITE                                   0xffffffffU
#define SWREG_SWREG_CTRL_0__PRESERVED                               0x00000000U

#endif /* __SWREG_SWREG_CTRL_0_MACRO__ */

/** @} end of swreg_ctrl_0 */

/* macros for BlueprintGlobalNameSpace::SWREG_swreg_ctrl_1 */
/**
 * @defgroup pmu_swreg_regs_core_swreg_ctrl_1 swreg_ctrl_1
 * @brief swreg reg 1 definitions.
 * @{
 */
#ifndef __SWREG_SWREG_CTRL_1_MACRO__
#define __SWREG_SWREG_CTRL_1_MACRO__

/* macros for field enableCCM */
/**
 * @defgroup pmu_swreg_regs_core_enableCCM_field enableCCM_field
 * @brief macros for field enableCCM
 * @details enable CCM for the respective mode
 * @{
 */
#define SWREG_SWREG_CTRL_1__ENABLECCM__SHIFT                                  0
#define SWREG_SWREG_CTRL_1__ENABLECCM__WIDTH                                 13
#define SWREG_SWREG_CTRL_1__ENABLECCM__MASK                         0x00001fffU
#define SWREG_SWREG_CTRL_1__ENABLECCM__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00001fffU)
#define SWREG_SWREG_CTRL_1__ENABLECCM__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00001fffU)
#define SWREG_SWREG_CTRL_1__ENABLECCM__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00001fffU) | ((uint32_t)(src) &\
                    0x00001fffU)
#define SWREG_SWREG_CTRL_1__ENABLECCM__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00001fffU)))
/** @} */

/* macros for field overridePN */
/**
 * @defgroup pmu_swreg_regs_core_overridePN_field overridePN_field
 * @brief macros for field overridePN
 * @details override the enables for the P and N part of the switches
 * @{
 */
#define SWREG_SWREG_CTRL_1__OVERRIDEPN__SHIFT                                13
#define SWREG_SWREG_CTRL_1__OVERRIDEPN__WIDTH                                 1
#define SWREG_SWREG_CTRL_1__OVERRIDEPN__MASK                        0x00002000U
#define SWREG_SWREG_CTRL_1__OVERRIDEPN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00002000U) >> 13)
#define SWREG_SWREG_CTRL_1__OVERRIDEPN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 13) & 0x00002000U)
#define SWREG_SWREG_CTRL_1__OVERRIDEPN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | (((uint32_t)(src) <<\
                    13) & 0x00002000U)
#define SWREG_SWREG_CTRL_1__OVERRIDEPN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 13) & ~0x00002000U)))
#define SWREG_SWREG_CTRL_1__OVERRIDEPN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | ((uint32_t)(1) << 13)
#define SWREG_SWREG_CTRL_1__OVERRIDEPN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | ((uint32_t)(0) << 13)
/** @} */

/* macros for field harvNen_ovr */
/**
 * @defgroup pmu_swreg_regs_core_harvNen_ovr_field harvNen_ovr_field
 * @brief macros for field harvNen_ovr
 * @details enable N for the harvester
 * @{
 */
#define SWREG_SWREG_CTRL_1__HARVNEN_OVR__SHIFT                               14
#define SWREG_SWREG_CTRL_1__HARVNEN_OVR__WIDTH                                1
#define SWREG_SWREG_CTRL_1__HARVNEN_OVR__MASK                       0x00004000U
#define SWREG_SWREG_CTRL_1__HARVNEN_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00004000U) >> 14)
#define SWREG_SWREG_CTRL_1__HARVNEN_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 14) & 0x00004000U)
#define SWREG_SWREG_CTRL_1__HARVNEN_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | (((uint32_t)(src) <<\
                    14) & 0x00004000U)
#define SWREG_SWREG_CTRL_1__HARVNEN_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 14) & ~0x00004000U)))
#define SWREG_SWREG_CTRL_1__HARVNEN_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | ((uint32_t)(1) << 14)
#define SWREG_SWREG_CTRL_1__HARVNEN_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | ((uint32_t)(0) << 14)
/** @} */

/* macros for field harvPen_ovr */
/**
 * @defgroup pmu_swreg_regs_core_harvPen_ovr_field harvPen_ovr_field
 * @brief macros for field harvPen_ovr
 * @details enable P for the harvester
 * @{
 */
#define SWREG_SWREG_CTRL_1__HARVPEN_OVR__SHIFT                               15
#define SWREG_SWREG_CTRL_1__HARVPEN_OVR__WIDTH                                1
#define SWREG_SWREG_CTRL_1__HARVPEN_OVR__MASK                       0x00008000U
#define SWREG_SWREG_CTRL_1__HARVPEN_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00008000U) >> 15)
#define SWREG_SWREG_CTRL_1__HARVPEN_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 15) & 0x00008000U)
#define SWREG_SWREG_CTRL_1__HARVPEN_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00008000U) | (((uint32_t)(src) <<\
                    15) & 0x00008000U)
#define SWREG_SWREG_CTRL_1__HARVPEN_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 15) & ~0x00008000U)))
#define SWREG_SWREG_CTRL_1__HARVPEN_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00008000U) | ((uint32_t)(1) << 15)
#define SWREG_SWREG_CTRL_1__HARVPEN_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00008000U) | ((uint32_t)(0) << 15)
/** @} */

/* macros for field storeNen_ovr */
/**
 * @defgroup pmu_swreg_regs_core_storeNen_ovr_field storeNen_ovr_field
 * @brief macros for field storeNen_ovr
 * @details enable N for the store
 * @{
 */
#define SWREG_SWREG_CTRL_1__STORENEN_OVR__SHIFT                              16
#define SWREG_SWREG_CTRL_1__STORENEN_OVR__WIDTH                               1
#define SWREG_SWREG_CTRL_1__STORENEN_OVR__MASK                      0x00010000U
#define SWREG_SWREG_CTRL_1__STORENEN_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00010000U) >> 16)
#define SWREG_SWREG_CTRL_1__STORENEN_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x00010000U)
#define SWREG_SWREG_CTRL_1__STORENEN_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | (((uint32_t)(src) <<\
                    16) & 0x00010000U)
#define SWREG_SWREG_CTRL_1__STORENEN_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x00010000U)))
#define SWREG_SWREG_CTRL_1__STORENEN_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | ((uint32_t)(1) << 16)
#define SWREG_SWREG_CTRL_1__STORENEN_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | ((uint32_t)(0) << 16)
/** @} */

/* macros for field storePen_ovr */
/**
 * @defgroup pmu_swreg_regs_core_storePen_ovr_field storePen_ovr_field
 * @brief macros for field storePen_ovr
 * @details enable P for the store
 * @{
 */
#define SWREG_SWREG_CTRL_1__STOREPEN_OVR__SHIFT                              17
#define SWREG_SWREG_CTRL_1__STOREPEN_OVR__WIDTH                               1
#define SWREG_SWREG_CTRL_1__STOREPEN_OVR__MASK                      0x00020000U
#define SWREG_SWREG_CTRL_1__STOREPEN_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00020000U) >> 17)
#define SWREG_SWREG_CTRL_1__STOREPEN_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 17) & 0x00020000U)
#define SWREG_SWREG_CTRL_1__STOREPEN_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | (((uint32_t)(src) <<\
                    17) & 0x00020000U)
#define SWREG_SWREG_CTRL_1__STOREPEN_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 17) & ~0x00020000U)))
#define SWREG_SWREG_CTRL_1__STOREPEN_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(1) << 17)
#define SWREG_SWREG_CTRL_1__STOREPEN_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(0) << 17)
/** @} */

/* macros for field battNen_ovr */
/**
 * @defgroup pmu_swreg_regs_core_battNen_ovr_field battNen_ovr_field
 * @brief macros for field battNen_ovr
 * @details enable N for the battery
 * @{
 */
#define SWREG_SWREG_CTRL_1__BATTNEN_OVR__SHIFT                               18
#define SWREG_SWREG_CTRL_1__BATTNEN_OVR__WIDTH                                1
#define SWREG_SWREG_CTRL_1__BATTNEN_OVR__MASK                       0x00040000U
#define SWREG_SWREG_CTRL_1__BATTNEN_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00040000U) >> 18)
#define SWREG_SWREG_CTRL_1__BATTNEN_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0x00040000U)
#define SWREG_SWREG_CTRL_1__BATTNEN_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | (((uint32_t)(src) <<\
                    18) & 0x00040000U)
#define SWREG_SWREG_CTRL_1__BATTNEN_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x00040000U)))
#define SWREG_SWREG_CTRL_1__BATTNEN_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(1) << 18)
#define SWREG_SWREG_CTRL_1__BATTNEN_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(0) << 18)
/** @} */

/* macros for field battPen_ovr */
/**
 * @defgroup pmu_swreg_regs_core_battPen_ovr_field battPen_ovr_field
 * @brief macros for field battPen_ovr
 * @details enable P for the battery
 * @{
 */
#define SWREG_SWREG_CTRL_1__BATTPEN_OVR__SHIFT                               19
#define SWREG_SWREG_CTRL_1__BATTPEN_OVR__WIDTH                                1
#define SWREG_SWREG_CTRL_1__BATTPEN_OVR__MASK                       0x00080000U
#define SWREG_SWREG_CTRL_1__BATTPEN_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00080000U) >> 19)
#define SWREG_SWREG_CTRL_1__BATTPEN_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 19) & 0x00080000U)
#define SWREG_SWREG_CTRL_1__BATTPEN_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | (((uint32_t)(src) <<\
                    19) & 0x00080000U)
#define SWREG_SWREG_CTRL_1__BATTPEN_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 19) & ~0x00080000U)))
#define SWREG_SWREG_CTRL_1__BATTPEN_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | ((uint32_t)(1) << 19)
#define SWREG_SWREG_CTRL_1__BATTPEN_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | ((uint32_t)(0) << 19)
/** @} */

/* macros for field dvddPen_ovr */
/**
 * @defgroup pmu_swreg_regs_core_dvddPen_ovr_field dvddPen_ovr_field
 * @brief macros for field dvddPen_ovr
 * @details enable P for dvdd
 * @{
 */
#define SWREG_SWREG_CTRL_1__DVDDPEN_OVR__SHIFT                               20
#define SWREG_SWREG_CTRL_1__DVDDPEN_OVR__WIDTH                                1
#define SWREG_SWREG_CTRL_1__DVDDPEN_OVR__MASK                       0x00100000U
#define SWREG_SWREG_CTRL_1__DVDDPEN_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00100000U) >> 20)
#define SWREG_SWREG_CTRL_1__DVDDPEN_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 20) & 0x00100000U)
#define SWREG_SWREG_CTRL_1__DVDDPEN_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00100000U) | (((uint32_t)(src) <<\
                    20) & 0x00100000U)
#define SWREG_SWREG_CTRL_1__DVDDPEN_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x00100000U)))
#define SWREG_SWREG_CTRL_1__DVDDPEN_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00100000U) | ((uint32_t)(1) << 20)
#define SWREG_SWREG_CTRL_1__DVDDPEN_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00100000U) | ((uint32_t)(0) << 20)
/** @} */

/* macros for field avddPen_ovr */
/**
 * @defgroup pmu_swreg_regs_core_avddPen_ovr_field avddPen_ovr_field
 * @brief macros for field avddPen_ovr
 * @details enable P for avdd
 * @{
 */
#define SWREG_SWREG_CTRL_1__AVDDPEN_OVR__SHIFT                               21
#define SWREG_SWREG_CTRL_1__AVDDPEN_OVR__WIDTH                                1
#define SWREG_SWREG_CTRL_1__AVDDPEN_OVR__MASK                       0x00200000U
#define SWREG_SWREG_CTRL_1__AVDDPEN_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00200000U) >> 21)
#define SWREG_SWREG_CTRL_1__AVDDPEN_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 21) & 0x00200000U)
#define SWREG_SWREG_CTRL_1__AVDDPEN_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00200000U) | (((uint32_t)(src) <<\
                    21) & 0x00200000U)
#define SWREG_SWREG_CTRL_1__AVDDPEN_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 21) & ~0x00200000U)))
#define SWREG_SWREG_CTRL_1__AVDDPEN_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00200000U) | ((uint32_t)(1) << 21)
#define SWREG_SWREG_CTRL_1__AVDDPEN_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00200000U) | ((uint32_t)(0) << 21)
/** @} */

/* macros for field delEnergDump */
/**
 * @defgroup pmu_swreg_regs_core_delEnergDump_field delEnergDump_field
 * @brief macros for field delEnergDump
 * @details non-overlap time between energize and dump
 * @{
 */
#define SWREG_SWREG_CTRL_1__DELENERGDUMP__SHIFT                              22
#define SWREG_SWREG_CTRL_1__DELENERGDUMP__WIDTH                               4
#define SWREG_SWREG_CTRL_1__DELENERGDUMP__MASK                      0x03c00000U
#define SWREG_SWREG_CTRL_1__DELENERGDUMP__READ(src) \
                    (((uint32_t)(src)\
                    & 0x03c00000U) >> 22)
#define SWREG_SWREG_CTRL_1__DELENERGDUMP__WRITE(src) \
                    (((uint32_t)(src)\
                    << 22) & 0x03c00000U)
#define SWREG_SWREG_CTRL_1__DELENERGDUMP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x03c00000U) | (((uint32_t)(src) <<\
                    22) & 0x03c00000U)
#define SWREG_SWREG_CTRL_1__DELENERGDUMP__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 22) & ~0x03c00000U)))
/** @} */

/* macros for field delZCD1 */
/**
 * @defgroup pmu_swreg_regs_core_delZCD1_field delZCD1_field
 * @brief macros for field delZCD1
 * @details first delay for the Zero Crossing Detection circuit
 * @{
 */
#define SWREG_SWREG_CTRL_1__DELZCD1__SHIFT                                   26
#define SWREG_SWREG_CTRL_1__DELZCD1__WIDTH                                    2
#define SWREG_SWREG_CTRL_1__DELZCD1__MASK                           0x0c000000U
#define SWREG_SWREG_CTRL_1__DELZCD1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0c000000U) >> 26)
#define SWREG_SWREG_CTRL_1__DELZCD1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 26) & 0x0c000000U)
#define SWREG_SWREG_CTRL_1__DELZCD1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0c000000U) | (((uint32_t)(src) <<\
                    26) & 0x0c000000U)
#define SWREG_SWREG_CTRL_1__DELZCD1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 26) & ~0x0c000000U)))
/** @} */

/* macros for field delZCD2 */
/**
 * @defgroup pmu_swreg_regs_core_delZCD2_field delZCD2_field
 * @brief macros for field delZCD2
 * @details second delay for the Zero Crossing Detection circuit
 * @{
 */
#define SWREG_SWREG_CTRL_1__DELZCD2__SHIFT                                   28
#define SWREG_SWREG_CTRL_1__DELZCD2__WIDTH                                    2
#define SWREG_SWREG_CTRL_1__DELZCD2__MASK                           0x30000000U
#define SWREG_SWREG_CTRL_1__DELZCD2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x30000000U) >> 28)
#define SWREG_SWREG_CTRL_1__DELZCD2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 28) & 0x30000000U)
#define SWREG_SWREG_CTRL_1__DELZCD2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x30000000U) | (((uint32_t)(src) <<\
                    28) & 0x30000000U)
#define SWREG_SWREG_CTRL_1__DELZCD2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 28) & ~0x30000000U)))
/** @} */

/* macros for field size */
/**
 * @defgroup pmu_swreg_regs_core_size_field size_field
 * @brief macros for field size
 * @details switch size
 * @{
 */
#define SWREG_SWREG_CTRL_1__SIZE__SHIFT                                      30
#define SWREG_SWREG_CTRL_1__SIZE__WIDTH                                       2
#define SWREG_SWREG_CTRL_1__SIZE__MASK                              0xc0000000U
#define SWREG_SWREG_CTRL_1__SIZE__READ(src) \
                    (((uint32_t)(src)\
                    & 0xc0000000U) >> 30)
#define SWREG_SWREG_CTRL_1__SIZE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 30) & 0xc0000000U)
#define SWREG_SWREG_CTRL_1__SIZE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xc0000000U) | (((uint32_t)(src) <<\
                    30) & 0xc0000000U)
#define SWREG_SWREG_CTRL_1__SIZE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 30) & ~0xc0000000U)))
/** @} */
#define SWREG_SWREG_CTRL_1__TYPE                                       uint32_t
#define SWREG_SWREG_CTRL_1__READ                                    0xffffffffU
#define SWREG_SWREG_CTRL_1__WRITE                                   0xffffffffU
#define SWREG_SWREG_CTRL_1__PRESERVED                               0x00000000U

#endif /* __SWREG_SWREG_CTRL_1_MACRO__ */

/** @} end of swreg_ctrl_1 */

/* macros for BlueprintGlobalNameSpace::SWREG_swreg_ctrl_2 */
/**
 * @defgroup pmu_swreg_regs_core_swreg_ctrl_2 swreg_ctrl_2
 * @brief swreg reg 2 definitions.
 * @{
 */
#ifndef __SWREG_SWREG_CTRL_2_MACRO__
#define __SWREG_SWREG_CTRL_2_MACRO__

/* macros for field overrideEnS */
/**
 * @defgroup pmu_swreg_regs_core_overrideEnS_field overrideEnS_field
 * @brief macros for field overrideEnS
 * @details override enables for the 3 sources
 * @{
 */
#define SWREG_SWREG_CTRL_2__OVERRIDEENS__SHIFT                                0
#define SWREG_SWREG_CTRL_2__OVERRIDEENS__WIDTH                                3
#define SWREG_SWREG_CTRL_2__OVERRIDEENS__MASK                       0x00000007U
#define SWREG_SWREG_CTRL_2__OVERRIDEENS__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000007U)
#define SWREG_SWREG_CTRL_2__OVERRIDEENS__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000007U)
#define SWREG_SWREG_CTRL_2__OVERRIDEENS__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000007U) | ((uint32_t)(src) &\
                    0x00000007U)
#define SWREG_SWREG_CTRL_2__OVERRIDEENS__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000007U)))
/** @} */

/* macros for field enableSource_ovr */
/**
 * @defgroup pmu_swreg_regs_core_enableSource_ovr_field enableSource_ovr_field
 * @brief macros for field enableSource_ovr
 * @details override enable values for the 3 sources
 * @{
 */
#define SWREG_SWREG_CTRL_2__ENABLESOURCE_OVR__SHIFT                           3
#define SWREG_SWREG_CTRL_2__ENABLESOURCE_OVR__WIDTH                           3
#define SWREG_SWREG_CTRL_2__ENABLESOURCE_OVR__MASK                  0x00000038U
#define SWREG_SWREG_CTRL_2__ENABLESOURCE_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000038U) >> 3)
#define SWREG_SWREG_CTRL_2__ENABLESOURCE_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 3) & 0x00000038U)
#define SWREG_SWREG_CTRL_2__ENABLESOURCE_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000038U) | (((uint32_t)(src) <<\
                    3) & 0x00000038U)
#define SWREG_SWREG_CTRL_2__ENABLESOURCE_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000038U)))
/** @} */

/* macros for field overrideEnD */
/**
 * @defgroup pmu_swreg_regs_core_overrideEnD_field overrideEnD_field
 * @brief macros for field overrideEnD
 * @details override enables for the 5 destinations
 * @{
 */
#define SWREG_SWREG_CTRL_2__OVERRIDEEND__SHIFT                                6
#define SWREG_SWREG_CTRL_2__OVERRIDEEND__WIDTH                                5
#define SWREG_SWREG_CTRL_2__OVERRIDEEND__MASK                       0x000007c0U
#define SWREG_SWREG_CTRL_2__OVERRIDEEND__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000007c0U) >> 6)
#define SWREG_SWREG_CTRL_2__OVERRIDEEND__WRITE(src) \
                    (((uint32_t)(src)\
                    << 6) & 0x000007c0U)
#define SWREG_SWREG_CTRL_2__OVERRIDEEND__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000007c0U) | (((uint32_t)(src) <<\
                    6) & 0x000007c0U)
#define SWREG_SWREG_CTRL_2__OVERRIDEEND__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 6) & ~0x000007c0U)))
/** @} */

/* macros for field enableDest_ovr */
/**
 * @defgroup pmu_swreg_regs_core_enableDest_ovr_field enableDest_ovr_field
 * @brief macros for field enableDest_ovr
 * @details override enable values for the 5 destinations
 * @{
 */
#define SWREG_SWREG_CTRL_2__ENABLEDEST_OVR__SHIFT                            11
#define SWREG_SWREG_CTRL_2__ENABLEDEST_OVR__WIDTH                             5
#define SWREG_SWREG_CTRL_2__ENABLEDEST_OVR__MASK                    0x0000f800U
#define SWREG_SWREG_CTRL_2__ENABLEDEST_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000f800U) >> 11)
#define SWREG_SWREG_CTRL_2__ENABLEDEST_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 11) & 0x0000f800U)
#define SWREG_SWREG_CTRL_2__ENABLEDEST_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000f800U) | (((uint32_t)(src) <<\
                    11) & 0x0000f800U)
#define SWREG_SWREG_CTRL_2__ENABLEDEST_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 11) & ~0x0000f800U)))
/** @} */

/* macros for field overrideEnHarv2Sup */
/**
 * @defgroup pmu_swreg_regs_core_overrideEnHarv2Sup_field overrideEnHarv2Sup_field
 * @brief macros for field overrideEnHarv2Sup
 * @details override enable for the harvester to supply mode
 * @{
 */
#define SWREG_SWREG_CTRL_2__OVERRIDEENHARV2SUP__SHIFT                        16
#define SWREG_SWREG_CTRL_2__OVERRIDEENHARV2SUP__WIDTH                         1
#define SWREG_SWREG_CTRL_2__OVERRIDEENHARV2SUP__MASK                0x00010000U
#define SWREG_SWREG_CTRL_2__OVERRIDEENHARV2SUP__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00010000U) >> 16)
#define SWREG_SWREG_CTRL_2__OVERRIDEENHARV2SUP__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x00010000U)
#define SWREG_SWREG_CTRL_2__OVERRIDEENHARV2SUP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | (((uint32_t)(src) <<\
                    16) & 0x00010000U)
#define SWREG_SWREG_CTRL_2__OVERRIDEENHARV2SUP__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x00010000U)))
#define SWREG_SWREG_CTRL_2__OVERRIDEENHARV2SUP__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | ((uint32_t)(1) << 16)
#define SWREG_SWREG_CTRL_2__OVERRIDEENHARV2SUP__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | ((uint32_t)(0) << 16)
/** @} */

/* macros for field enableHarv2Sup_ovr */
/**
 * @defgroup pmu_swreg_regs_core_enableHarv2Sup_ovr_field enableHarv2Sup_ovr_field
 * @brief macros for field enableHarv2Sup_ovr
 * @details override enable value for the harvester to supply mode
 * @{
 */
#define SWREG_SWREG_CTRL_2__ENABLEHARV2SUP_OVR__SHIFT                        17
#define SWREG_SWREG_CTRL_2__ENABLEHARV2SUP_OVR__WIDTH                         1
#define SWREG_SWREG_CTRL_2__ENABLEHARV2SUP_OVR__MASK                0x00020000U
#define SWREG_SWREG_CTRL_2__ENABLEHARV2SUP_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00020000U) >> 17)
#define SWREG_SWREG_CTRL_2__ENABLEHARV2SUP_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 17) & 0x00020000U)
#define SWREG_SWREG_CTRL_2__ENABLEHARV2SUP_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | (((uint32_t)(src) <<\
                    17) & 0x00020000U)
#define SWREG_SWREG_CTRL_2__ENABLEHARV2SUP_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 17) & ~0x00020000U)))
#define SWREG_SWREG_CTRL_2__ENABLEHARV2SUP_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(1) << 17)
#define SWREG_SWREG_CTRL_2__ENABLEHARV2SUP_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00020000U) | ((uint32_t)(0) << 17)
/** @} */

/* macros for field dig_test_out_sel */
/**
 * @defgroup pmu_swreg_regs_core_dig_test_out_sel_field dig_test_out_sel_field
 * @brief macros for field dig_test_out_sel
 * @details digital bus select signal, as follows:9-0: NC1: a 66% duty-cycle test clock, while holding the switcher in reset10: mode: Store -> VSUP1, Buck11: mode: Battery -> VSUP1, Buck12: mode: Battery -> VSUP1, BuckBoost13: swSampleIndCurrent14: swEnergize15: harvesting16: suppliesReady20-17: supReady21: vbattGood22: vstoreGood23: mustHarvest24: canHarvest28-25: vsupLowB29: indCurrentSign30: clk while the switcher is functioning normally31: NC
 * @{
 */
#define SWREG_SWREG_CTRL_2__DIG_TEST_OUT_SEL__SHIFT                          18
#define SWREG_SWREG_CTRL_2__DIG_TEST_OUT_SEL__WIDTH                           5
#define SWREG_SWREG_CTRL_2__DIG_TEST_OUT_SEL__MASK                  0x007c0000U
#define SWREG_SWREG_CTRL_2__DIG_TEST_OUT_SEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x007c0000U) >> 18)
#define SWREG_SWREG_CTRL_2__DIG_TEST_OUT_SEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0x007c0000U)
#define SWREG_SWREG_CTRL_2__DIG_TEST_OUT_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x007c0000U) | (((uint32_t)(src) <<\
                    18) & 0x007c0000U)
#define SWREG_SWREG_CTRL_2__DIG_TEST_OUT_SEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x007c0000U)))
/** @} */

/* macros for field clkFixedTime */
/**
 * @defgroup pmu_swreg_regs_core_clkFixedTime_field clkFixedTime_field
 * @brief macros for field clkFixedTime
 * @details the number of delay units for the low time and the minimum up time of the clock
 * @{
 */
#define SWREG_SWREG_CTRL_2__CLKFIXEDTIME__SHIFT                              23
#define SWREG_SWREG_CTRL_2__CLKFIXEDTIME__WIDTH                               3
#define SWREG_SWREG_CTRL_2__CLKFIXEDTIME__MASK                      0x03800000U
#define SWREG_SWREG_CTRL_2__CLKFIXEDTIME__READ(src) \
                    (((uint32_t)(src)\
                    & 0x03800000U) >> 23)
#define SWREG_SWREG_CTRL_2__CLKFIXEDTIME__WRITE(src) \
                    (((uint32_t)(src)\
                    << 23) & 0x03800000U)
#define SWREG_SWREG_CTRL_2__CLKFIXEDTIME__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x03800000U) | (((uint32_t)(src) <<\
                    23) & 0x03800000U)
#define SWREG_SWREG_CTRL_2__CLKFIXEDTIME__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 23) & ~0x03800000U)))
/** @} */

/* macros for field clkUnitDel */
/**
 * @defgroup pmu_swreg_regs_core_clkUnitDel_field clkUnitDel_field
 * @brief macros for field clkUnitDel
 * @details adjusts the unit delay of the clock
 * @{
 */
#define SWREG_SWREG_CTRL_2__CLKUNITDEL__SHIFT                                26
#define SWREG_SWREG_CTRL_2__CLKUNITDEL__WIDTH                                 3
#define SWREG_SWREG_CTRL_2__CLKUNITDEL__MASK                        0x1c000000U
#define SWREG_SWREG_CTRL_2__CLKUNITDEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x1c000000U) >> 26)
#define SWREG_SWREG_CTRL_2__CLKUNITDEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 26) & 0x1c000000U)
#define SWREG_SWREG_CTRL_2__CLKUNITDEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x1c000000U) | (((uint32_t)(src) <<\
                    26) & 0x1c000000U)
#define SWREG_SWREG_CTRL_2__CLKUNITDEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 26) & ~0x1c000000U)))
/** @} */

/* macros for field spareExt0 */
/**
 * @defgroup pmu_swreg_regs_core_spareExt0_field spareExt0_field
 * @brief macros for field spareExt0
 * @details spare external 0
 * @{
 */
#define SWREG_SWREG_CTRL_2__SPAREEXT0__SHIFT                                 29
#define SWREG_SWREG_CTRL_2__SPAREEXT0__WIDTH                                  3
#define SWREG_SWREG_CTRL_2__SPAREEXT0__MASK                         0xe0000000U
#define SWREG_SWREG_CTRL_2__SPAREEXT0__READ(src) \
                    (((uint32_t)(src)\
                    & 0xe0000000U) >> 29)
#define SWREG_SWREG_CTRL_2__SPAREEXT0__WRITE(src) \
                    (((uint32_t)(src)\
                    << 29) & 0xe0000000U)
#define SWREG_SWREG_CTRL_2__SPAREEXT0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xe0000000U) | (((uint32_t)(src) <<\
                    29) & 0xe0000000U)
#define SWREG_SWREG_CTRL_2__SPAREEXT0__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 29) & ~0xe0000000U)))
/** @} */
#define SWREG_SWREG_CTRL_2__TYPE                                       uint32_t
#define SWREG_SWREG_CTRL_2__READ                                    0xffffffffU
#define SWREG_SWREG_CTRL_2__WRITE                                   0xffffffffU
#define SWREG_SWREG_CTRL_2__PRESERVED                               0x00000000U

#endif /* __SWREG_SWREG_CTRL_2_MACRO__ */

/** @} end of swreg_ctrl_2 */

/* macros for BlueprintGlobalNameSpace::SWREG_swreg_ctrl_3 */
/**
 * @defgroup pmu_swreg_regs_core_swreg_ctrl_3 swreg_ctrl_3
 * @brief swreg reg 3 definitions.
 * @{
 */
#ifndef __SWREG_SWREG_CTRL_3_MACRO__
#define __SWREG_SWREG_CTRL_3_MACRO__

/* macros for field skipSample */
/**
 * @defgroup pmu_swreg_regs_core_skipSample_field skipSample_field
 * @brief macros for field skipSample
 * @details skip the sampling state after the idle state
 * @{
 */
#define SWREG_SWREG_CTRL_3__SKIPSAMPLE__SHIFT                                 0
#define SWREG_SWREG_CTRL_3__SKIPSAMPLE__WIDTH                                 1
#define SWREG_SWREG_CTRL_3__SKIPSAMPLE__MASK                        0x00000001U
#define SWREG_SWREG_CTRL_3__SKIPSAMPLE__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define SWREG_SWREG_CTRL_3__SKIPSAMPLE__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define SWREG_SWREG_CTRL_3__SKIPSAMPLE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define SWREG_SWREG_CTRL_3__SKIPSAMPLE__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define SWREG_SWREG_CTRL_3__SKIPSAMPLE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define SWREG_SWREG_CTRL_3__SKIPSAMPLE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
/** @} */

/* macros for field timePlanLong */
/**
 * @defgroup pmu_swreg_regs_core_timePlanLong_field timePlanLong_field
 * @brief macros for field timePlanLong
 * @details plan (and sample, if used) state duration after dump. The leftover inductor current is dissipated during this time
 * @{
 */
#define SWREG_SWREG_CTRL_3__TIMEPLANLONG__SHIFT                               1
#define SWREG_SWREG_CTRL_3__TIMEPLANLONG__WIDTH                               7
#define SWREG_SWREG_CTRL_3__TIMEPLANLONG__MASK                      0x000000feU
#define SWREG_SWREG_CTRL_3__TIMEPLANLONG__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000000feU) >> 1)
#define SWREG_SWREG_CTRL_3__TIMEPLANLONG__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x000000feU)
#define SWREG_SWREG_CTRL_3__TIMEPLANLONG__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000feU) | (((uint32_t)(src) <<\
                    1) & 0x000000feU)
#define SWREG_SWREG_CTRL_3__TIMEPLANLONG__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x000000feU)))
/** @} */

/* macros for field timePlanLong_Start */
/**
 * @defgroup pmu_swreg_regs_core_timePlanLong_Start_field timePlanLong_Start_field
 * @brief macros for field timePlanLong_Start
 * @details plan (and sample, if used) state duration after dump before the supplies are ready (consider reducing to allow providing higher current at startup)
 * @{
 */
#define SWREG_SWREG_CTRL_3__TIMEPLANLONG_START__SHIFT                         8
#define SWREG_SWREG_CTRL_3__TIMEPLANLONG_START__WIDTH                         7
#define SWREG_SWREG_CTRL_3__TIMEPLANLONG_START__MASK                0x00007f00U
#define SWREG_SWREG_CTRL_3__TIMEPLANLONG_START__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00007f00U) >> 8)
#define SWREG_SWREG_CTRL_3__TIMEPLANLONG_START__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00007f00U)
#define SWREG_SWREG_CTRL_3__TIMEPLANLONG_START__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00007f00U) | (((uint32_t)(src) <<\
                    8) & 0x00007f00U)
#define SWREG_SWREG_CTRL_3__TIMEPLANLONG_START__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00007f00U)))
/** @} */

/* macros for field timePlanShort */
/**
 * @defgroup pmu_swreg_regs_core_timePlanShort_field timePlanShort_field
 * @brief macros for field timePlanShort
 * @details plan (and sample, if used) state duration when the previous state is not dump
 * @{
 */
#define SWREG_SWREG_CTRL_3__TIMEPLANSHORT__SHIFT                             15
#define SWREG_SWREG_CTRL_3__TIMEPLANSHORT__WIDTH                              3
#define SWREG_SWREG_CTRL_3__TIMEPLANSHORT__MASK                     0x00038000U
#define SWREG_SWREG_CTRL_3__TIMEPLANSHORT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00038000U) >> 15)
#define SWREG_SWREG_CTRL_3__TIMEPLANSHORT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 15) & 0x00038000U)
#define SWREG_SWREG_CTRL_3__TIMEPLANSHORT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00038000U) | (((uint32_t)(src) <<\
                    15) & 0x00038000U)
#define SWREG_SWREG_CTRL_3__TIMEPLANSHORT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 15) & ~0x00038000U)))
/** @} */

/* macros for field timeStep_Step */
/**
 * @defgroup pmu_swreg_regs_core_timeStep_Step_field timeStep_Step_field
 * @brief macros for field timeStep_Step
 * @details step in adjusting the variable timestep
 * @{
 */
#define SWREG_SWREG_CTRL_3__TIMESTEP_STEP__SHIFT                             18
#define SWREG_SWREG_CTRL_3__TIMESTEP_STEP__WIDTH                              3
#define SWREG_SWREG_CTRL_3__TIMESTEP_STEP__MASK                     0x001c0000U
#define SWREG_SWREG_CTRL_3__TIMESTEP_STEP__READ(src) \
                    (((uint32_t)(src)\
                    & 0x001c0000U) >> 18)
#define SWREG_SWREG_CTRL_3__TIMESTEP_STEP__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0x001c0000U)
#define SWREG_SWREG_CTRL_3__TIMESTEP_STEP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x001c0000U) | (((uint32_t)(src) <<\
                    18) & 0x001c0000U)
#define SWREG_SWREG_CTRL_3__TIMESTEP_STEP__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x001c0000U)))
/** @} */

/* macros for field timeStep_Max */
/**
 * @defgroup pmu_swreg_regs_core_timeStep_Max_field timeStep_Max_field
 * @brief macros for field timeStep_Max
 * @details maximum timestep
 * @{
 */
#define SWREG_SWREG_CTRL_3__TIMESTEP_MAX__SHIFT                              21
#define SWREG_SWREG_CTRL_3__TIMESTEP_MAX__WIDTH                               5
#define SWREG_SWREG_CTRL_3__TIMESTEP_MAX__MASK                      0x03e00000U
#define SWREG_SWREG_CTRL_3__TIMESTEP_MAX__READ(src) \
                    (((uint32_t)(src)\
                    & 0x03e00000U) >> 21)
#define SWREG_SWREG_CTRL_3__TIMESTEP_MAX__WRITE(src) \
                    (((uint32_t)(src)\
                    << 21) & 0x03e00000U)
#define SWREG_SWREG_CTRL_3__TIMESTEP_MAX__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x03e00000U) | (((uint32_t)(src) <<\
                    21) & 0x03e00000U)
#define SWREG_SWREG_CTRL_3__TIMESTEP_MAX__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 21) & ~0x03e00000U)))
/** @} */

/* macros for field timeStep_FastSettle */
/**
 * @defgroup pmu_swreg_regs_core_timeStep_FastSettle_field timeStep_FastSettle_field
 * @brief macros for field timeStep_FastSettle
 * @details timeStep during fast settling
 * @{
 */
#define SWREG_SWREG_CTRL_3__TIMESTEP_FASTSETTLE__SHIFT                       26
#define SWREG_SWREG_CTRL_3__TIMESTEP_FASTSETTLE__WIDTH                        3
#define SWREG_SWREG_CTRL_3__TIMESTEP_FASTSETTLE__MASK               0x1c000000U
#define SWREG_SWREG_CTRL_3__TIMESTEP_FASTSETTLE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x1c000000U) >> 26)
#define SWREG_SWREG_CTRL_3__TIMESTEP_FASTSETTLE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 26) & 0x1c000000U)
#define SWREG_SWREG_CTRL_3__TIMESTEP_FASTSETTLE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x1c000000U) | (((uint32_t)(src) <<\
                    26) & 0x1c000000U)
#define SWREG_SWREG_CTRL_3__TIMESTEP_FASTSETTLE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 26) & ~0x1c000000U)))
/** @} */

/* macros for field spareExt1 */
/**
 * @defgroup pmu_swreg_regs_core_spareExt1_field spareExt1_field
 * @brief macros for field spareExt1
 * @details spare external 1
 * @{
 */
#define SWREG_SWREG_CTRL_3__SPAREEXT1__SHIFT                                 29
#define SWREG_SWREG_CTRL_3__SPAREEXT1__WIDTH                                  3
#define SWREG_SWREG_CTRL_3__SPAREEXT1__MASK                         0xe0000000U
#define SWREG_SWREG_CTRL_3__SPAREEXT1__READ(src) \
                    (((uint32_t)(src)\
                    & 0xe0000000U) >> 29)
#define SWREG_SWREG_CTRL_3__SPAREEXT1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 29) & 0xe0000000U)
#define SWREG_SWREG_CTRL_3__SPAREEXT1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xe0000000U) | (((uint32_t)(src) <<\
                    29) & 0xe0000000U)
#define SWREG_SWREG_CTRL_3__SPAREEXT1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 29) & ~0xe0000000U)))
/** @} */
#define SWREG_SWREG_CTRL_3__TYPE                                       uint32_t
#define SWREG_SWREG_CTRL_3__READ                                    0xffffffffU
#define SWREG_SWREG_CTRL_3__WRITE                                   0xffffffffU
#define SWREG_SWREG_CTRL_3__PRESERVED                               0x00000000U

#endif /* __SWREG_SWREG_CTRL_3_MACRO__ */

/** @} end of swreg_ctrl_3 */

/* macros for BlueprintGlobalNameSpace::SWREG_swreg_ctrl_4 */
/**
 * @defgroup pmu_swreg_regs_core_swreg_ctrl_4 swreg_ctrl_4
 * @brief swreg reg 4 definitions.
 * @{
 */
#ifndef __SWREG_SWREG_CTRL_4_MACRO__
#define __SWREG_SWREG_CTRL_4_MACRO__

/* macros for field attempt_Enter_CCM */
/**
 * @defgroup pmu_swreg_regs_core_attempt_Enter_CCM_field attempt_Enter_CCM_field
 * @brief macros for field attempt_Enter_CCM
 * @details number of DCM consecutive attempts after which if the supply is still low CCM mode starts
 * @{
 */
#define SWREG_SWREG_CTRL_4__ATTEMPT_ENTER_CCM__SHIFT                          0
#define SWREG_SWREG_CTRL_4__ATTEMPT_ENTER_CCM__WIDTH                          4
#define SWREG_SWREG_CTRL_4__ATTEMPT_ENTER_CCM__MASK                 0x0000000fU
#define SWREG_SWREG_CTRL_4__ATTEMPT_ENTER_CCM__READ(src) \
                    ((uint32_t)(src)\
                    & 0x0000000fU)
#define SWREG_SWREG_CTRL_4__ATTEMPT_ENTER_CCM__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000000fU)
#define SWREG_SWREG_CTRL_4__ATTEMPT_ENTER_CCM__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000000fU) | ((uint32_t)(src) &\
                    0x0000000fU)
#define SWREG_SWREG_CTRL_4__ATTEMPT_ENTER_CCM__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000000fU)))
/** @} */

/* macros for field attempt_Shift_CCM_Gear */
/**
 * @defgroup pmu_swreg_regs_core_attempt_Shift_CCM_Gear_field attempt_Shift_CCM_Gear_field
 * @brief macros for field attempt_Shift_CCM_Gear
 * @details number of CCM consecutive attempts after which if the supply is still low the CCM gear increases
 * @{
 */
#define SWREG_SWREG_CTRL_4__ATTEMPT_SHIFT_CCM_GEAR__SHIFT                     4
#define SWREG_SWREG_CTRL_4__ATTEMPT_SHIFT_CCM_GEAR__WIDTH                     4
#define SWREG_SWREG_CTRL_4__ATTEMPT_SHIFT_CCM_GEAR__MASK            0x000000f0U
#define SWREG_SWREG_CTRL_4__ATTEMPT_SHIFT_CCM_GEAR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000000f0U) >> 4)
#define SWREG_SWREG_CTRL_4__ATTEMPT_SHIFT_CCM_GEAR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x000000f0U)
#define SWREG_SWREG_CTRL_4__ATTEMPT_SHIFT_CCM_GEAR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000f0U) | (((uint32_t)(src) <<\
                    4) & 0x000000f0U)
#define SWREG_SWREG_CTRL_4__ATTEMPT_SHIFT_CCM_GEAR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x000000f0U)))
/** @} */

/* macros for field CCM_CyclesMax */
/**
 * @defgroup pmu_swreg_regs_core_CCM_CyclesMax_field CCM_CyclesMax_field
 * @brief macros for field CCM_CyclesMax
 * @details maximum number of energize-dump cycles in the same CCM session (consider increasing for higher output power)
 * @{
 */
#define SWREG_SWREG_CTRL_4__CCM_CYCLESMAX__SHIFT                              8
#define SWREG_SWREG_CTRL_4__CCM_CYCLESMAX__WIDTH                              3
#define SWREG_SWREG_CTRL_4__CCM_CYCLESMAX__MASK                     0x00000700U
#define SWREG_SWREG_CTRL_4__CCM_CYCLESMAX__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000700U) >> 8)
#define SWREG_SWREG_CTRL_4__CCM_CYCLESMAX__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00000700U)
#define SWREG_SWREG_CTRL_4__CCM_CYCLESMAX__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000700U) | (((uint32_t)(src) <<\
                    8) & 0x00000700U)
#define SWREG_SWREG_CTRL_4__CCM_CYCLESMAX__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00000700U)))
/** @} */

/* macros for field CCM_CyclesMin */
/**
 * @defgroup pmu_swreg_regs_core_CCM_CyclesMin_field CCM_CyclesMin_field
 * @brief macros for field CCM_CyclesMin
 * @details minimum number of energize-dump cycles in the same CCM session
 * @{
 */
#define SWREG_SWREG_CTRL_4__CCM_CYCLESMIN__SHIFT                             11
#define SWREG_SWREG_CTRL_4__CCM_CYCLESMIN__WIDTH                              3
#define SWREG_SWREG_CTRL_4__CCM_CYCLESMIN__MASK                     0x00003800U
#define SWREG_SWREG_CTRL_4__CCM_CYCLESMIN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00003800U) >> 11)
#define SWREG_SWREG_CTRL_4__CCM_CYCLESMIN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 11) & 0x00003800U)
#define SWREG_SWREG_CTRL_4__CCM_CYCLESMIN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00003800U) | (((uint32_t)(src) <<\
                    11) & 0x00003800U)
#define SWREG_SWREG_CTRL_4__CCM_CYCLESMIN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 11) & ~0x00003800U)))
/** @} */

/* macros for field CCM_GearInit */
/**
 * @defgroup pmu_swreg_regs_core_CCM_GearInit_field CCM_GearInit_field
 * @brief macros for field CCM_GearInit
 * @details initial CCM gear
 * @{
 */
#define SWREG_SWREG_CTRL_4__CCM_GEARINIT__SHIFT                              14
#define SWREG_SWREG_CTRL_4__CCM_GEARINIT__WIDTH                               4
#define SWREG_SWREG_CTRL_4__CCM_GEARINIT__MASK                      0x0003c000U
#define SWREG_SWREG_CTRL_4__CCM_GEARINIT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0003c000U) >> 14)
#define SWREG_SWREG_CTRL_4__CCM_GEARINIT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 14) & 0x0003c000U)
#define SWREG_SWREG_CTRL_4__CCM_GEARINIT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0003c000U) | (((uint32_t)(src) <<\
                    14) & 0x0003c000U)
#define SWREG_SWREG_CTRL_4__CCM_GEARINIT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 14) & ~0x0003c000U)))
/** @} */

/* macros for field easierEnterCCM */
/**
 * @defgroup pmu_swreg_regs_core_easierEnterCCM_field easierEnterCCM_field
 * @brief macros for field easierEnterCCM
 * @details relaxes the requirements on settling to steady-steaty to allow entering CCM
 * @{
 */
#define SWREG_SWREG_CTRL_4__EASIERENTERCCM__SHIFT                            18
#define SWREG_SWREG_CTRL_4__EASIERENTERCCM__WIDTH                             1
#define SWREG_SWREG_CTRL_4__EASIERENTERCCM__MASK                    0x00040000U
#define SWREG_SWREG_CTRL_4__EASIERENTERCCM__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00040000U) >> 18)
#define SWREG_SWREG_CTRL_4__EASIERENTERCCM__WRITE(src) \
                    (((uint32_t)(src)\
                    << 18) & 0x00040000U)
#define SWREG_SWREG_CTRL_4__EASIERENTERCCM__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | (((uint32_t)(src) <<\
                    18) & 0x00040000U)
#define SWREG_SWREG_CTRL_4__EASIERENTERCCM__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 18) & ~0x00040000U)))
#define SWREG_SWREG_CTRL_4__EASIERENTERCCM__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(1) << 18)
#define SWREG_SWREG_CTRL_4__EASIERENTERCCM__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00040000U) | ((uint32_t)(0) << 18)
/** @} */

/* macros for field ateTest */
/**
 * @defgroup pmu_swreg_regs_core_ateTest_field ateTest_field
 * @brief macros for field ateTest
 * @details turns on ATE testing To close a pair source and destination switch, set ateTest=1, select the desired mode by setting ateModeSel, ateBuck, ateBoost and set ateEnerg=1/0 for energize/dump
 * @{
 */
#define SWREG_SWREG_CTRL_4__ATETEST__SHIFT                                   19
#define SWREG_SWREG_CTRL_4__ATETEST__WIDTH                                    1
#define SWREG_SWREG_CTRL_4__ATETEST__MASK                           0x00080000U
#define SWREG_SWREG_CTRL_4__ATETEST__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00080000U) >> 19)
#define SWREG_SWREG_CTRL_4__ATETEST__WRITE(src) \
                    (((uint32_t)(src)\
                    << 19) & 0x00080000U)
#define SWREG_SWREG_CTRL_4__ATETEST__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | (((uint32_t)(src) <<\
                    19) & 0x00080000U)
#define SWREG_SWREG_CTRL_4__ATETEST__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 19) & ~0x00080000U)))
#define SWREG_SWREG_CTRL_4__ATETEST__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | ((uint32_t)(1) << 19)
#define SWREG_SWREG_CTRL_4__ATETEST__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | ((uint32_t)(0) << 19)
/** @} */

/* macros for field ateModeSel */
/**
 * @defgroup pmu_swreg_regs_core_ateModeSel_field ateModeSel_field
 * @brief macros for field ateModeSel
 * @details the power transfer mode activated in ate testing (Better to change the default to 4'b1111 which corresponds to none)
 * @{
 */
#define SWREG_SWREG_CTRL_4__ATEMODESEL__SHIFT                                20
#define SWREG_SWREG_CTRL_4__ATEMODESEL__WIDTH                                 4
#define SWREG_SWREG_CTRL_4__ATEMODESEL__MASK                        0x00f00000U
#define SWREG_SWREG_CTRL_4__ATEMODESEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00f00000U) >> 20)
#define SWREG_SWREG_CTRL_4__ATEMODESEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 20) & 0x00f00000U)
#define SWREG_SWREG_CTRL_4__ATEMODESEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00f00000U) | (((uint32_t)(src) <<\
                    20) & 0x00f00000U)
#define SWREG_SWREG_CTRL_4__ATEMODESEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x00f00000U)))
/** @} */

/* macros for field ateBuck */
/**
 * @defgroup pmu_swreg_regs_core_ateBuck_field ateBuck_field
 * @brief macros for field ateBuck
 * @details buck mode in ate testing
 * @{
 */
#define SWREG_SWREG_CTRL_4__ATEBUCK__SHIFT                                   24
#define SWREG_SWREG_CTRL_4__ATEBUCK__WIDTH                                    1
#define SWREG_SWREG_CTRL_4__ATEBUCK__MASK                           0x01000000U
#define SWREG_SWREG_CTRL_4__ATEBUCK__READ(src) \
                    (((uint32_t)(src)\
                    & 0x01000000U) >> 24)
#define SWREG_SWREG_CTRL_4__ATEBUCK__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x01000000U)
#define SWREG_SWREG_CTRL_4__ATEBUCK__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | (((uint32_t)(src) <<\
                    24) & 0x01000000U)
#define SWREG_SWREG_CTRL_4__ATEBUCK__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x01000000U)))
#define SWREG_SWREG_CTRL_4__ATEBUCK__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(1) << 24)
#define SWREG_SWREG_CTRL_4__ATEBUCK__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x01000000U) | ((uint32_t)(0) << 24)
/** @} */

/* macros for field ateBoost */
/**
 * @defgroup pmu_swreg_regs_core_ateBoost_field ateBoost_field
 * @brief macros for field ateBoost
 * @details boost mode in ate testing
 * @{
 */
#define SWREG_SWREG_CTRL_4__ATEBOOST__SHIFT                                  25
#define SWREG_SWREG_CTRL_4__ATEBOOST__WIDTH                                   1
#define SWREG_SWREG_CTRL_4__ATEBOOST__MASK                          0x02000000U
#define SWREG_SWREG_CTRL_4__ATEBOOST__READ(src) \
                    (((uint32_t)(src)\
                    & 0x02000000U) >> 25)
#define SWREG_SWREG_CTRL_4__ATEBOOST__WRITE(src) \
                    (((uint32_t)(src)\
                    << 25) & 0x02000000U)
#define SWREG_SWREG_CTRL_4__ATEBOOST__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x02000000U) | (((uint32_t)(src) <<\
                    25) & 0x02000000U)
#define SWREG_SWREG_CTRL_4__ATEBOOST__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 25) & ~0x02000000U)))
#define SWREG_SWREG_CTRL_4__ATEBOOST__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x02000000U) | ((uint32_t)(1) << 25)
#define SWREG_SWREG_CTRL_4__ATEBOOST__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x02000000U) | ((uint32_t)(0) << 25)
/** @} */

/* macros for field ateEnerg */
/**
 * @defgroup pmu_swreg_regs_core_ateEnerg_field ateEnerg_field
 * @brief macros for field ateEnerg
 * @details energize in ate testing
 * @{
 */
#define SWREG_SWREG_CTRL_4__ATEENERG__SHIFT                                  26
#define SWREG_SWREG_CTRL_4__ATEENERG__WIDTH                                   1
#define SWREG_SWREG_CTRL_4__ATEENERG__MASK                          0x04000000U
#define SWREG_SWREG_CTRL_4__ATEENERG__READ(src) \
                    (((uint32_t)(src)\
                    & 0x04000000U) >> 26)
#define SWREG_SWREG_CTRL_4__ATEENERG__WRITE(src) \
                    (((uint32_t)(src)\
                    << 26) & 0x04000000U)
#define SWREG_SWREG_CTRL_4__ATEENERG__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x04000000U) | (((uint32_t)(src) <<\
                    26) & 0x04000000U)
#define SWREG_SWREG_CTRL_4__ATEENERG__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 26) & ~0x04000000U)))
#define SWREG_SWREG_CTRL_4__ATEENERG__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x04000000U) | ((uint32_t)(1) << 26)
#define SWREG_SWREG_CTRL_4__ATEENERG__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x04000000U) | ((uint32_t)(0) << 26)
/** @} */

/* macros for field ateSampleIndCurrent */
/**
 * @defgroup pmu_swreg_regs_core_ateSampleIndCurrent_field ateSampleIndCurrent_field
 * @brief macros for field ateSampleIndCurrent
 * @details sample inductor current sign in ate testing. To test the Zero Current Crossing comparator     Activate a mode with ateModeSel, ateBuck in dump configuration with ateEnerg=0. It can be buck-boost or buck, but not boost. Set ateSampleIndCurrent=1.    Apply a small positive/negative current to the source terminal of the inductor, which is grounded during dump.    Terminate the mode by setting ateModeSel=4'd13, which will make the current flow through the internal sense resistor   Read the indCurrentSign bit in the readout register, it should be 0/1
 * @{
 */
#define SWREG_SWREG_CTRL_4__ATESAMPLEINDCURRENT__SHIFT                       27
#define SWREG_SWREG_CTRL_4__ATESAMPLEINDCURRENT__WIDTH                        1
#define SWREG_SWREG_CTRL_4__ATESAMPLEINDCURRENT__MASK               0x08000000U
#define SWREG_SWREG_CTRL_4__ATESAMPLEINDCURRENT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x08000000U) >> 27)
#define SWREG_SWREG_CTRL_4__ATESAMPLEINDCURRENT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 27) & 0x08000000U)
#define SWREG_SWREG_CTRL_4__ATESAMPLEINDCURRENT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x08000000U) | (((uint32_t)(src) <<\
                    27) & 0x08000000U)
#define SWREG_SWREG_CTRL_4__ATESAMPLEINDCURRENT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 27) & ~0x08000000U)))
#define SWREG_SWREG_CTRL_4__ATESAMPLEINDCURRENT__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x08000000U) | ((uint32_t)(1) << 27)
#define SWREG_SWREG_CTRL_4__ATESAMPLEINDCURRENT__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x08000000U) | ((uint32_t)(0) << 27)
/** @} */
#define SWREG_SWREG_CTRL_4__TYPE                                       uint32_t
#define SWREG_SWREG_CTRL_4__READ                                    0x0fffffffU
#define SWREG_SWREG_CTRL_4__WRITE                                   0x0fffffffU
#define SWREG_SWREG_CTRL_4__PRESERVED                               0x00000000U

#endif /* __SWREG_SWREG_CTRL_4_MACRO__ */

/** @} end of swreg_ctrl_4 */

/* macros for BlueprintGlobalNameSpace::SWREG_swreg_ctrl_5 */
/**
 * @defgroup pmu_swreg_regs_core_swreg_ctrl_5 swreg_ctrl_5
 * @brief swreg reg 5 definitions.
 * @{
 */
#ifndef __SWREG_SWREG_CTRL_5_MACRO__
#define __SWREG_SWREG_CTRL_5_MACRO__

/* macros for field timeEnergStart_Harvest */
/**
 * @defgroup pmu_swreg_regs_core_timeEnergStart_Harvest_field timeEnergStart_Harvest_field
 * @brief macros for field timeEnergStart_Harvest
 * @details initial energize time when the source is the harvester, before the distination is ready, common for all destinations
 * @{
 */
#define SWREG_SWREG_CTRL_5__TIMEENERGSTART_HARVEST__SHIFT                     0
#define SWREG_SWREG_CTRL_5__TIMEENERGSTART_HARVEST__WIDTH                     7
#define SWREG_SWREG_CTRL_5__TIMEENERGSTART_HARVEST__MASK            0x0000007fU
#define SWREG_SWREG_CTRL_5__TIMEENERGSTART_HARVEST__READ(src) \
                    ((uint32_t)(src)\
                    & 0x0000007fU)
#define SWREG_SWREG_CTRL_5__TIMEENERGSTART_HARVEST__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000007fU)
#define SWREG_SWREG_CTRL_5__TIMEENERGSTART_HARVEST__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000007fU) | ((uint32_t)(src) &\
                    0x0000007fU)
#define SWREG_SWREG_CTRL_5__TIMEENERGSTART_HARVEST__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000007fU)))
/** @} */

/* macros for field timeEnergStart_Store */
/**
 * @defgroup pmu_swreg_regs_core_timeEnergStart_Store_field timeEnergStart_Store_field
 * @brief macros for field timeEnergStart_Store
 * @details initial energize time when the source is the store, before the distination is ready, common for all destinations
 * @{
 */
#define SWREG_SWREG_CTRL_5__TIMEENERGSTART_STORE__SHIFT                       7
#define SWREG_SWREG_CTRL_5__TIMEENERGSTART_STORE__WIDTH                       7
#define SWREG_SWREG_CTRL_5__TIMEENERGSTART_STORE__MASK              0x00003f80U
#define SWREG_SWREG_CTRL_5__TIMEENERGSTART_STORE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00003f80U) >> 7)
#define SWREG_SWREG_CTRL_5__TIMEENERGSTART_STORE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 7) & 0x00003f80U)
#define SWREG_SWREG_CTRL_5__TIMEENERGSTART_STORE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00003f80U) | (((uint32_t)(src) <<\
                    7) & 0x00003f80U)
#define SWREG_SWREG_CTRL_5__TIMEENERGSTART_STORE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 7) & ~0x00003f80U)))
/** @} */

/* macros for field timeEnergStart_Battery */
/**
 * @defgroup pmu_swreg_regs_core_timeEnergStart_Battery_field timeEnergStart_Battery_field
 * @brief macros for field timeEnergStart_Battery
 * @details initial energize time when the source is the battery, before the distination is ready, common for all destinations
 * @{
 */
#define SWREG_SWREG_CTRL_5__TIMEENERGSTART_BATTERY__SHIFT                    14
#define SWREG_SWREG_CTRL_5__TIMEENERGSTART_BATTERY__WIDTH                     7
#define SWREG_SWREG_CTRL_5__TIMEENERGSTART_BATTERY__MASK            0x001fc000U
#define SWREG_SWREG_CTRL_5__TIMEENERGSTART_BATTERY__READ(src) \
                    (((uint32_t)(src)\
                    & 0x001fc000U) >> 14)
#define SWREG_SWREG_CTRL_5__TIMEENERGSTART_BATTERY__WRITE(src) \
                    (((uint32_t)(src)\
                    << 14) & 0x001fc000U)
#define SWREG_SWREG_CTRL_5__TIMEENERGSTART_BATTERY__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x001fc000U) | (((uint32_t)(src) <<\
                    14) & 0x001fc000U)
#define SWREG_SWREG_CTRL_5__TIMEENERGSTART_BATTERY__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 14) & ~0x001fc000U)))
/** @} */

/* macros for field timeTarget_Harvest_Store */
/**
 * @defgroup pmu_swreg_regs_core_timeTarget_Harvest_Store_field timeTarget_Harvest_Store_field
 * @brief macros for field timeTarget_Harvest_Store
 * @details target time in Steady State for the Harvester->Store mode
 * @{
 */
#define SWREG_SWREG_CTRL_5__TIMETARGET_HARVEST_STORE__SHIFT                  21
#define SWREG_SWREG_CTRL_5__TIMETARGET_HARVEST_STORE__WIDTH                   7
#define SWREG_SWREG_CTRL_5__TIMETARGET_HARVEST_STORE__MASK          0x0fe00000U
#define SWREG_SWREG_CTRL_5__TIMETARGET_HARVEST_STORE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0fe00000U) >> 21)
#define SWREG_SWREG_CTRL_5__TIMETARGET_HARVEST_STORE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 21) & 0x0fe00000U)
#define SWREG_SWREG_CTRL_5__TIMETARGET_HARVEST_STORE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0fe00000U) | (((uint32_t)(src) <<\
                    21) & 0x0fe00000U)
#define SWREG_SWREG_CTRL_5__TIMETARGET_HARVEST_STORE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 21) & ~0x0fe00000U)))
/** @} */
#define SWREG_SWREG_CTRL_5__TYPE                                       uint32_t
#define SWREG_SWREG_CTRL_5__READ                                    0x0fffffffU
#define SWREG_SWREG_CTRL_5__WRITE                                   0x0fffffffU
#define SWREG_SWREG_CTRL_5__PRESERVED                               0x00000000U

#endif /* __SWREG_SWREG_CTRL_5_MACRO__ */

/** @} end of swreg_ctrl_5 */

/* macros for BlueprintGlobalNameSpace::SWREG_swreg_ctrl_6 */
/**
 * @defgroup pmu_swreg_regs_core_swreg_ctrl_6 swreg_ctrl_6
 * @brief swreg reg 6 definitions.
 * @{
 */
#ifndef __SWREG_SWREG_CTRL_6_MACRO__
#define __SWREG_SWREG_CTRL_6_MACRO__

/* macros for field fixDumpTime_Harvest_Store */
/**
 * @defgroup pmu_swreg_regs_core_fixDumpTime_Harvest_Store_field fixDumpTime_Harvest_Store_field
 * @brief macros for field fixDumpTime_Harvest_Store
 * @details if 1 the dump time is fixed otherwise the energize time is fixed in steady state for the Harvester->Store mode
 * @{
 */
#define SWREG_SWREG_CTRL_6__FIXDUMPTIME_HARVEST_STORE__SHIFT                  0
#define SWREG_SWREG_CTRL_6__FIXDUMPTIME_HARVEST_STORE__WIDTH                  1
#define SWREG_SWREG_CTRL_6__FIXDUMPTIME_HARVEST_STORE__MASK         0x00000001U
#define SWREG_SWREG_CTRL_6__FIXDUMPTIME_HARVEST_STORE__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define SWREG_SWREG_CTRL_6__FIXDUMPTIME_HARVEST_STORE__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define SWREG_SWREG_CTRL_6__FIXDUMPTIME_HARVEST_STORE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define SWREG_SWREG_CTRL_6__FIXDUMPTIME_HARVEST_STORE__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define SWREG_SWREG_CTRL_6__FIXDUMPTIME_HARVEST_STORE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define SWREG_SWREG_CTRL_6__FIXDUMPTIME_HARVEST_STORE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
/** @} */

/* macros for field timeDumpTarget_dvdd */
/**
 * @defgroup pmu_swreg_regs_core_timeDumpTarget_dvdd_field timeDumpTarget_dvdd_field
 * @brief macros for field timeDumpTarget_dvdd
 * @details target dump time in Steady State for dvdd, all sources
 * @{
 */
#define SWREG_SWREG_CTRL_6__TIMEDUMPTARGET_DVDD__SHIFT                        1
#define SWREG_SWREG_CTRL_6__TIMEDUMPTARGET_DVDD__WIDTH                        7
#define SWREG_SWREG_CTRL_6__TIMEDUMPTARGET_DVDD__MASK               0x000000feU
#define SWREG_SWREG_CTRL_6__TIMEDUMPTARGET_DVDD__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000000feU) >> 1)
#define SWREG_SWREG_CTRL_6__TIMEDUMPTARGET_DVDD__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x000000feU)
#define SWREG_SWREG_CTRL_6__TIMEDUMPTARGET_DVDD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000feU) | (((uint32_t)(src) <<\
                    1) & 0x000000feU)
#define SWREG_SWREG_CTRL_6__TIMEDUMPTARGET_DVDD__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x000000feU)))
/** @} */

/* macros for field timeDumpTarget_vddaux */
/**
 * @defgroup pmu_swreg_regs_core_timeDumpTarget_vddaux_field timeDumpTarget_vddaux_field
 * @brief macros for field timeDumpTarget_vddaux
 * @details target dump time in Steady State for vddaux, all sources
 * @{
 */
#define SWREG_SWREG_CTRL_6__TIMEDUMPTARGET_VDDAUX__SHIFT                      8
#define SWREG_SWREG_CTRL_6__TIMEDUMPTARGET_VDDAUX__WIDTH                      7
#define SWREG_SWREG_CTRL_6__TIMEDUMPTARGET_VDDAUX__MASK             0x00007f00U
#define SWREG_SWREG_CTRL_6__TIMEDUMPTARGET_VDDAUX__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00007f00U) >> 8)
#define SWREG_SWREG_CTRL_6__TIMEDUMPTARGET_VDDAUX__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00007f00U)
#define SWREG_SWREG_CTRL_6__TIMEDUMPTARGET_VDDAUX__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00007f00U) | (((uint32_t)(src) <<\
                    8) & 0x00007f00U)
#define SWREG_SWREG_CTRL_6__TIMEDUMPTARGET_VDDAUX__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00007f00U)))
/** @} */

/* macros for field timeDumpTarget_vddio */
/**
 * @defgroup pmu_swreg_regs_core_timeDumpTarget_vddio_field timeDumpTarget_vddio_field
 * @brief macros for field timeDumpTarget_vddio
 * @details target dump time in Steady State for vddio, all sources
 * @{
 */
#define SWREG_SWREG_CTRL_6__TIMEDUMPTARGET_VDDIO__SHIFT                      15
#define SWREG_SWREG_CTRL_6__TIMEDUMPTARGET_VDDIO__WIDTH                       7
#define SWREG_SWREG_CTRL_6__TIMEDUMPTARGET_VDDIO__MASK              0x003f8000U
#define SWREG_SWREG_CTRL_6__TIMEDUMPTARGET_VDDIO__READ(src) \
                    (((uint32_t)(src)\
                    & 0x003f8000U) >> 15)
#define SWREG_SWREG_CTRL_6__TIMEDUMPTARGET_VDDIO__WRITE(src) \
                    (((uint32_t)(src)\
                    << 15) & 0x003f8000U)
#define SWREG_SWREG_CTRL_6__TIMEDUMPTARGET_VDDIO__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x003f8000U) | (((uint32_t)(src) <<\
                    15) & 0x003f8000U)
#define SWREG_SWREG_CTRL_6__TIMEDUMPTARGET_VDDIO__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 15) & ~0x003f8000U)))
/** @} */

/* macros for field timeDumpTarget_avdd */
/**
 * @defgroup pmu_swreg_regs_core_timeDumpTarget_avdd_field timeDumpTarget_avdd_field
 * @brief macros for field timeDumpTarget_avdd
 * @details target dump time in Steady State for avdd, all sources
 * @{
 */
#define SWREG_SWREG_CTRL_6__TIMEDUMPTARGET_AVDD__SHIFT                       22
#define SWREG_SWREG_CTRL_6__TIMEDUMPTARGET_AVDD__WIDTH                        7
#define SWREG_SWREG_CTRL_6__TIMEDUMPTARGET_AVDD__MASK               0x1fc00000U
#define SWREG_SWREG_CTRL_6__TIMEDUMPTARGET_AVDD__READ(src) \
                    (((uint32_t)(src)\
                    & 0x1fc00000U) >> 22)
#define SWREG_SWREG_CTRL_6__TIMEDUMPTARGET_AVDD__WRITE(src) \
                    (((uint32_t)(src)\
                    << 22) & 0x1fc00000U)
#define SWREG_SWREG_CTRL_6__TIMEDUMPTARGET_AVDD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x1fc00000U) | (((uint32_t)(src) <<\
                    22) & 0x1fc00000U)
#define SWREG_SWREG_CTRL_6__TIMEDUMPTARGET_AVDD__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 22) & ~0x1fc00000U)))
/** @} */

/* macros for field timeMin */
/**
 * @defgroup pmu_swreg_regs_core_timeMin_field timeMin_field
 * @brief macros for field timeMin
 * @details The min energize or dump time allowed. Does not apply to CCM mode.
 * @{
 */
#define SWREG_SWREG_CTRL_6__TIMEMIN__SHIFT                                   29
#define SWREG_SWREG_CTRL_6__TIMEMIN__WIDTH                                    3
#define SWREG_SWREG_CTRL_6__TIMEMIN__MASK                           0xe0000000U
#define SWREG_SWREG_CTRL_6__TIMEMIN__READ(src) \
                    (((uint32_t)(src)\
                    & 0xe0000000U) >> 29)
#define SWREG_SWREG_CTRL_6__TIMEMIN__WRITE(src) \
                    (((uint32_t)(src)\
                    << 29) & 0xe0000000U)
#define SWREG_SWREG_CTRL_6__TIMEMIN__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xe0000000U) | (((uint32_t)(src) <<\
                    29) & 0xe0000000U)
#define SWREG_SWREG_CTRL_6__TIMEMIN__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 29) & ~0xe0000000U)))
/** @} */
#define SWREG_SWREG_CTRL_6__TYPE                                       uint32_t
#define SWREG_SWREG_CTRL_6__READ                                    0xffffffffU
#define SWREG_SWREG_CTRL_6__WRITE                                   0xffffffffU
#define SWREG_SWREG_CTRL_6__PRESERVED                               0x00000000U

#endif /* __SWREG_SWREG_CTRL_6_MACRO__ */

/** @} end of swreg_ctrl_6 */

/* macros for BlueprintGlobalNameSpace::SWREG_swreg_ctrl_7 */
/**
 * @defgroup pmu_swreg_regs_core_swreg_ctrl_7 swreg_ctrl_7
 * @brief swreg reg 7 definitions.
 * @{
 */
#ifndef __SWREG_SWREG_CTRL_7_MACRO__
#define __SWREG_SWREG_CTRL_7_MACRO__

/* macros for field timeMax */
/**
 * @defgroup pmu_swreg_regs_core_timeMax_field timeMax_field
 * @brief macros for field timeMax
 * @details The max energize or dump time allowed. Does not apply to CCM mode.
 * @{
 */
#define SWREG_SWREG_CTRL_7__TIMEMAX__SHIFT                                    0
#define SWREG_SWREG_CTRL_7__TIMEMAX__WIDTH                                    9
#define SWREG_SWREG_CTRL_7__TIMEMAX__MASK                           0x000001ffU
#define SWREG_SWREG_CTRL_7__TIMEMAX__READ(src)  ((uint32_t)(src) & 0x000001ffU)
#define SWREG_SWREG_CTRL_7__TIMEMAX__WRITE(src) ((uint32_t)(src) & 0x000001ffU)
#define SWREG_SWREG_CTRL_7__TIMEMAX__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000001ffU) | ((uint32_t)(src) &\
                    0x000001ffU)
#define SWREG_SWREG_CTRL_7__TIMEMAX__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000001ffU)))
/** @} */

/* macros for field spareInt */
/**
 * @defgroup pmu_swreg_regs_core_spareInt_field spareInt_field
 * @brief macros for field spareInt
 * @details spare internal 0: when set to 1 gates the harvesting signal with (canHarvest & !mustHarvest) 1: if 1, the PMOS device is used for the dvdd switch (can be overriden with overridePN) 2: if 1, the PMOS device is used for the avdd switch (can be overriden with overridePN)
 * @{
 */
#define SWREG_SWREG_CTRL_7__SPAREINT__SHIFT                                  10
#define SWREG_SWREG_CTRL_7__SPAREINT__WIDTH                                  22
#define SWREG_SWREG_CTRL_7__SPAREINT__MASK                          0xfffffc00U
#define SWREG_SWREG_CTRL_7__SPAREINT__READ(src) \
                    (((uint32_t)(src)\
                    & 0xfffffc00U) >> 10)
#define SWREG_SWREG_CTRL_7__SPAREINT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0xfffffc00U)
#define SWREG_SWREG_CTRL_7__SPAREINT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xfffffc00U) | (((uint32_t)(src) <<\
                    10) & 0xfffffc00U)
#define SWREG_SWREG_CTRL_7__SPAREINT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0xfffffc00U)))
/** @} */
#define SWREG_SWREG_CTRL_7__TYPE                                       uint32_t
#define SWREG_SWREG_CTRL_7__READ                                    0xfffffdffU
#define SWREG_SWREG_CTRL_7__WRITE                                   0xfffffdffU
#define SWREG_SWREG_CTRL_7__PRESERVED                               0x00000000U

#endif /* __SWREG_SWREG_CTRL_7_MACRO__ */

/** @} end of swreg_ctrl_7 */

/* macros for BlueprintGlobalNameSpace::SWREG_swreg_readout */
/**
 * @defgroup pmu_swreg_regs_core_swreg_readout swreg_readout
 * @brief swreg readout bits definitions.
 * @{
 */
#ifndef __SWREG_SWREG_READOUT_MACRO__
#define __SWREG_SWREG_READOUT_MACRO__

/* macros for field vsupLowB */
/**
 * @defgroup pmu_swreg_regs_core_vsupLowB_field vsupLowB_field
 * @brief macros for field vsupLowB
 * @details supply sensing comparators for the four supplies
 * @{
 */
#define SWREG_SWREG_READOUT__VSUPLOWB__SHIFT                                  0
#define SWREG_SWREG_READOUT__VSUPLOWB__WIDTH                                  4
#define SWREG_SWREG_READOUT__VSUPLOWB__MASK                         0x0000000fU
#define SWREG_SWREG_READOUT__VSUPLOWB__READ(src) \
                    ((uint32_t)(src)\
                    & 0x0000000fU)
/** @} */

/* macros for field vbattGood */
/**
 * @defgroup pmu_swreg_regs_core_vbattGood_field vbattGood_field
 * @brief macros for field vbattGood
 * @details vbatt good comparator
 * @{
 */
#define SWREG_SWREG_READOUT__VBATTGOOD__SHIFT                                 4
#define SWREG_SWREG_READOUT__VBATTGOOD__WIDTH                                 1
#define SWREG_SWREG_READOUT__VBATTGOOD__MASK                        0x00000010U
#define SWREG_SWREG_READOUT__VBATTGOOD__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000010U) >> 4)
#define SWREG_SWREG_READOUT__VBATTGOOD__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(1) << 4)
#define SWREG_SWREG_READOUT__VBATTGOOD__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(0) << 4)
/** @} */

/* macros for field vstoreGood */
/**
 * @defgroup pmu_swreg_regs_core_vstoreGood_field vstoreGood_field
 * @brief macros for field vstoreGood
 * @details vstore good comparator
 * @{
 */
#define SWREG_SWREG_READOUT__VSTOREGOOD__SHIFT                                5
#define SWREG_SWREG_READOUT__VSTOREGOOD__WIDTH                                1
#define SWREG_SWREG_READOUT__VSTOREGOOD__MASK                       0x00000020U
#define SWREG_SWREG_READOUT__VSTOREGOOD__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000020U) >> 5)
#define SWREG_SWREG_READOUT__VSTOREGOOD__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(1) << 5)
#define SWREG_SWREG_READOUT__VSTOREGOOD__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(0) << 5)
/** @} */

/* macros for field canHarvest */
/**
 * @defgroup pmu_swreg_regs_core_canHarvest_field canHarvest_field
 * @brief macros for field canHarvest
 * @details can harvest comparator
 * @{
 */
#define SWREG_SWREG_READOUT__CANHARVEST__SHIFT                                6
#define SWREG_SWREG_READOUT__CANHARVEST__WIDTH                                1
#define SWREG_SWREG_READOUT__CANHARVEST__MASK                       0x00000040U
#define SWREG_SWREG_READOUT__CANHARVEST__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000040U) >> 6)
#define SWREG_SWREG_READOUT__CANHARVEST__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(1) << 6)
#define SWREG_SWREG_READOUT__CANHARVEST__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(0) << 6)
/** @} */

/* macros for field mustHarvest */
/**
 * @defgroup pmu_swreg_regs_core_mustHarvest_field mustHarvest_field
 * @brief macros for field mustHarvest
 * @details must harvest comparator
 * @{
 */
#define SWREG_SWREG_READOUT__MUSTHARVEST__SHIFT                               7
#define SWREG_SWREG_READOUT__MUSTHARVEST__WIDTH                               1
#define SWREG_SWREG_READOUT__MUSTHARVEST__MASK                      0x00000080U
#define SWREG_SWREG_READOUT__MUSTHARVEST__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000080U) >> 7)
#define SWREG_SWREG_READOUT__MUSTHARVEST__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | ((uint32_t)(1) << 7)
#define SWREG_SWREG_READOUT__MUSTHARVEST__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | ((uint32_t)(0) << 7)
/** @} */

/* macros for field indCurrentSign */
/**
 * @defgroup pmu_swreg_regs_core_indCurrentSign_field indCurrentSign_field
 * @brief macros for field indCurrentSign
 * @details inductor current sign
 * @{
 */
#define SWREG_SWREG_READOUT__INDCURRENTSIGN__SHIFT                            8
#define SWREG_SWREG_READOUT__INDCURRENTSIGN__WIDTH                            1
#define SWREG_SWREG_READOUT__INDCURRENTSIGN__MASK                   0x00000100U
#define SWREG_SWREG_READOUT__INDCURRENTSIGN__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000100U) >> 8)
#define SWREG_SWREG_READOUT__INDCURRENTSIGN__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | ((uint32_t)(1) << 8)
#define SWREG_SWREG_READOUT__INDCURRENTSIGN__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | ((uint32_t)(0) << 8)
/** @} */

/* macros for field supReady */
/**
 * @defgroup pmu_swreg_regs_core_supReady_field supReady_field
 * @brief macros for field supReady
 * @details the 4 supply ready signals
 * @{
 */
#define SWREG_SWREG_READOUT__SUPREADY__SHIFT                                  9
#define SWREG_SWREG_READOUT__SUPREADY__WIDTH                                  4
#define SWREG_SWREG_READOUT__SUPREADY__MASK                         0x00001e00U
#define SWREG_SWREG_READOUT__SUPREADY__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00001e00U) >> 9)
/** @} */

/* macros for field suppliesReady */
/**
 * @defgroup pmu_swreg_regs_core_suppliesReady_field suppliesReady_field
 * @brief macros for field suppliesReady
 * @details suppliesReady signal
 * @{
 */
#define SWREG_SWREG_READOUT__SUPPLIESREADY__SHIFT                            13
#define SWREG_SWREG_READOUT__SUPPLIESREADY__WIDTH                             1
#define SWREG_SWREG_READOUT__SUPPLIESREADY__MASK                    0x00002000U
#define SWREG_SWREG_READOUT__SUPPLIESREADY__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00002000U) >> 13)
#define SWREG_SWREG_READOUT__SUPPLIESREADY__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | ((uint32_t)(1) << 13)
#define SWREG_SWREG_READOUT__SUPPLIESREADY__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | ((uint32_t)(0) << 13)
/** @} */

/* macros for field harvesting */
/**
 * @defgroup pmu_swreg_regs_core_harvesting_field harvesting_field
 * @brief macros for field harvesting
 * @details harvesting signal
 * @{
 */
#define SWREG_SWREG_READOUT__HARVESTING__SHIFT                               14
#define SWREG_SWREG_READOUT__HARVESTING__WIDTH                                1
#define SWREG_SWREG_READOUT__HARVESTING__MASK                       0x00004000U
#define SWREG_SWREG_READOUT__HARVESTING__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00004000U) >> 14)
#define SWREG_SWREG_READOUT__HARVESTING__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | ((uint32_t)(1) << 14)
#define SWREG_SWREG_READOUT__HARVESTING__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | ((uint32_t)(0) << 14)
/** @} */

/* macros for field state */
/**
 * @defgroup pmu_swreg_regs_core_state_field state_field
 * @brief macros for field state
 * @details the fsm state
 * @{
 */
#define SWREG_SWREG_READOUT__STATE__SHIFT                                    15
#define SWREG_SWREG_READOUT__STATE__WIDTH                                     3
#define SWREG_SWREG_READOUT__STATE__MASK                            0x00038000U
#define SWREG_SWREG_READOUT__STATE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00038000U) >> 15)
/** @} */
#define SWREG_SWREG_READOUT__TYPE                                      uint32_t
#define SWREG_SWREG_READOUT__READ                                   0x0003ffffU
#define SWREG_SWREG_READOUT__PRESERVED                              0x00000000U

#endif /* __SWREG_SWREG_READOUT_MACRO__ */

/** @} end of swreg_readout */

/* macros for BlueprintGlobalNameSpace::SWREG_core_id */
/**
 * @defgroup pmu_swreg_regs_core_core_id core_id
 * @brief Contains register fields associated with core_id. definitions.
 * @{
 */
#ifndef __SWREG_CORE_ID_MACRO__
#define __SWREG_CORE_ID_MACRO__

/* macros for field id */
/**
 * @defgroup pmu_swreg_regs_core_id_field id_field
 * @brief macros for field id
 * @details SWRG in ASCII
 * @{
 */
#define SWREG_CORE_ID__ID__SHIFT                                              0
#define SWREG_CORE_ID__ID__WIDTH                                             32
#define SWREG_CORE_ID__ID__MASK                                     0xffffffffU
#define SWREG_CORE_ID__ID__READ(src)            ((uint32_t)(src) & 0xffffffffU)
/** @} */
#define SWREG_CORE_ID__TYPE                                            uint32_t
#define SWREG_CORE_ID__READ                                         0xffffffffU
#define SWREG_CORE_ID__PRESERVED                                    0x00000000U

#endif /* __SWREG_CORE_ID_MACRO__ */

/** @} end of core_id */

/** @} end of PMU_SWREG_REGS_CORE */
#endif /* __REG_PMU_SWREG_REGS_CORE_H__ */
