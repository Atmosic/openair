/*                                                                           */
/* File:       swreg_simple_regs_core_macro.h                                */
/*                                                                           */
/* Arguments:  /cad/tools/cadence/blueprint_3.7.5/Linux-64bit/blueprint -eval*/
/*             $DEFINE_PROPERTY=1; -ansic swreg_simple_regs_core.rdl         */
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


#ifndef __REG_SWREG_SIMPLE_REGS_CORE_H__
#define __REG_SWREG_SIMPLE_REGS_CORE_H__

/**
 *****************************************************************************
 * @defgroup SWREG_SIMPLE_REGS_CORE swreg_simple_regs_core
 * @ingroup AT_REG
 * @brief swreg_simple_regs_core definitions.
 * @{
 *****************************************************************************
 */

/* macros for BlueprintGlobalNameSpace::SWREG_SIMPLE_simple0 */
/**
 * @defgroup swreg_simple_regs_core_simple0 simple0
 * @brief simple swreg registers For fields that refer to the sources the order is: 2: BATT 1: STORE 0: HARV For fields that refer to the destinations the order is: 4: STORE 3: AVDD 2: VDDIO 1: VDDAUX 0: DVDD For fields that refer to the supplies the order is: 3: AVDD 2: VDDIO 1: VDDAUX 0: DVDD For fields that refer to the power transfer modes the order is: 12: HARV -> STORE11: HARV -> AVDD10: HARV -> VDDIO9: HARV -> VDDAUX8: HARV -> DVDD7: STORE -> AVDD6: STORE -> VDDIO5: STORE -> VDDAUX4: STORE -> DVDD3: BATT -> AVDD2: BATT -> VDDIO1: BATT -> VDDAUX0: BATT -> DVDD definitions.
 * @{
 */
#ifndef __SWREG_SIMPLE_SIMPLE0_MACRO__
#define __SWREG_SIMPLE_SIMPLE0_MACRO__

/* macros for field loadRegSimple */
/**
 * @defgroup swreg_simple_regs_core_loadRegSimple_field loadRegSimple_field
 * @brief macros for field loadRegSimple
 * @details load the Simple shadow register
 * @{
 */
#define SWREG_SIMPLE_SIMPLE0__LOADREGSIMPLE__SHIFT                            0
#define SWREG_SIMPLE_SIMPLE0__LOADREGSIMPLE__WIDTH                            1
#define SWREG_SIMPLE_SIMPLE0__LOADREGSIMPLE__MASK                   0x00000001U
#define SWREG_SIMPLE_SIMPLE0__LOADREGSIMPLE__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define SWREG_SIMPLE_SIMPLE0__LOADREGSIMPLE__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define SWREG_SIMPLE_SIMPLE0__LOADREGSIMPLE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define SWREG_SIMPLE_SIMPLE0__LOADREGSIMPLE__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define SWREG_SIMPLE_SIMPLE0__LOADREGSIMPLE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define SWREG_SIMPLE_SIMPLE0__LOADREGSIMPLE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define SWREG_SIMPLE_SIMPLE0__LOADREGSIMPLE__RESET_VALUE            0x00000000U
/** @} */

/* macros for field scaleEnerg_ovr */
/**
 * @defgroup swreg_simple_regs_core_scaleEnerg_ovr_field scaleEnerg_ovr_field
 * @brief macros for field scaleEnerg_ovr
 * @details override scaling of energize time
 * @{
 */
#define SWREG_SIMPLE_SIMPLE0__SCALEENERG_OVR__SHIFT                           1
#define SWREG_SIMPLE_SIMPLE0__SCALEENERG_OVR__WIDTH                           1
#define SWREG_SIMPLE_SIMPLE0__SCALEENERG_OVR__MASK                  0x00000002U
#define SWREG_SIMPLE_SIMPLE0__SCALEENERG_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define SWREG_SIMPLE_SIMPLE0__SCALEENERG_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define SWREG_SIMPLE_SIMPLE0__SCALEENERG_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define SWREG_SIMPLE_SIMPLE0__SCALEENERG_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define SWREG_SIMPLE_SIMPLE0__SCALEENERG_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define SWREG_SIMPLE_SIMPLE0__SCALEENERG_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define SWREG_SIMPLE_SIMPLE0__SCALEENERG_OVR__RESET_VALUE           0x00000000U
/** @} */

/* macros for field scaleEnerg_ovrVal */
/**
 * @defgroup swreg_simple_regs_core_scaleEnerg_ovrVal_field scaleEnerg_ovrVal_field
 * @brief macros for field scaleEnerg_ovrVal
 * @details override value for scaling of energize time, 3 bits for each source: setting of (0:7) corresponds to scaling of (1, 1.125, 1.375, 1.625, 2, 3, 4, 8)
 * @{
 */
#define SWREG_SIMPLE_SIMPLE0__SCALEENERG_OVRVAL__SHIFT                        2
#define SWREG_SIMPLE_SIMPLE0__SCALEENERG_OVRVAL__WIDTH                        9
#define SWREG_SIMPLE_SIMPLE0__SCALEENERG_OVRVAL__MASK               0x000007fcU
#define SWREG_SIMPLE_SIMPLE0__SCALEENERG_OVRVAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000007fcU) >> 2)
#define SWREG_SIMPLE_SIMPLE0__SCALEENERG_OVRVAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x000007fcU)
#define SWREG_SIMPLE_SIMPLE0__SCALEENERG_OVRVAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000007fcU) | (((uint32_t)(src) <<\
                    2) & 0x000007fcU)
#define SWREG_SIMPLE_SIMPLE0__SCALEENERG_OVRVAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x000007fcU)))
#define SWREG_SIMPLE_SIMPLE0__SCALEENERG_OVRVAL__RESET_VALUE        0x00000000U
/** @} */

/* macros for field enableHarv2Sup_ovr */
/**
 * @defgroup swreg_simple_regs_core_enableHarv2Sup_ovr_field enableHarv2Sup_ovr_field
 * @brief macros for field enableHarv2Sup_ovr
 * @details override enable for harvest to supplies modes
 * @{
 */
#define SWREG_SIMPLE_SIMPLE0__ENABLEHARV2SUP_OVR__SHIFT                      11
#define SWREG_SIMPLE_SIMPLE0__ENABLEHARV2SUP_OVR__WIDTH                       1
#define SWREG_SIMPLE_SIMPLE0__ENABLEHARV2SUP_OVR__MASK              0x00000800U
#define SWREG_SIMPLE_SIMPLE0__ENABLEHARV2SUP_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000800U) >> 11)
#define SWREG_SIMPLE_SIMPLE0__ENABLEHARV2SUP_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 11) & 0x00000800U)
#define SWREG_SIMPLE_SIMPLE0__ENABLEHARV2SUP_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | (((uint32_t)(src) <<\
                    11) & 0x00000800U)
#define SWREG_SIMPLE_SIMPLE0__ENABLEHARV2SUP_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 11) & ~0x00000800U)))
#define SWREG_SIMPLE_SIMPLE0__ENABLEHARV2SUP_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | ((uint32_t)(1) << 11)
#define SWREG_SIMPLE_SIMPLE0__ENABLEHARV2SUP_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000800U) | ((uint32_t)(0) << 11)
#define SWREG_SIMPLE_SIMPLE0__ENABLEHARV2SUP_OVR__RESET_VALUE       0x00000000U
/** @} */

/* macros for field enableHarv2Sup_ovrVal */
/**
 * @defgroup swreg_simple_regs_core_enableHarv2Sup_ovrVal_field enableHarv2Sup_ovrVal_field
 * @brief macros for field enableHarv2Sup_ovrVal
 * @details override value of the enable for harvest to supplies modes
 * @{
 */
#define SWREG_SIMPLE_SIMPLE0__ENABLEHARV2SUP_OVRVAL__SHIFT                   12
#define SWREG_SIMPLE_SIMPLE0__ENABLEHARV2SUP_OVRVAL__WIDTH                    1
#define SWREG_SIMPLE_SIMPLE0__ENABLEHARV2SUP_OVRVAL__MASK           0x00001000U
#define SWREG_SIMPLE_SIMPLE0__ENABLEHARV2SUP_OVRVAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00001000U) >> 12)
#define SWREG_SIMPLE_SIMPLE0__ENABLEHARV2SUP_OVRVAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 12) & 0x00001000U)
#define SWREG_SIMPLE_SIMPLE0__ENABLEHARV2SUP_OVRVAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | (((uint32_t)(src) <<\
                    12) & 0x00001000U)
#define SWREG_SIMPLE_SIMPLE0__ENABLEHARV2SUP_OVRVAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 12) & ~0x00001000U)))
#define SWREG_SIMPLE_SIMPLE0__ENABLEHARV2SUP_OVRVAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | ((uint32_t)(1) << 12)
#define SWREG_SIMPLE_SIMPLE0__ENABLEHARV2SUP_OVRVAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00001000U) | ((uint32_t)(0) << 12)
#define SWREG_SIMPLE_SIMPLE0__ENABLEHARV2SUP_OVRVAL__RESET_VALUE    0x00000000U
/** @} */

/* macros for field fixHarvEnerg_ovr */
/**
 * @defgroup swreg_simple_regs_core_fixHarvEnerg_ovr_field fixHarvEnerg_ovr_field
 * @brief macros for field fixHarvEnerg_ovr
 * @details override fixing the energize time (fixHarvEnerg) for all destinations when the source is the harvester if fixHarvEnerg=1 the target for the harvest to supply modes is the energize time, otherwise it is the dump time if set, timeTargetHarv2Store_SH is used as the energize time
 * @{
 */
#define SWREG_SIMPLE_SIMPLE0__FIXHARVENERG_OVR__SHIFT                        13
#define SWREG_SIMPLE_SIMPLE0__FIXHARVENERG_OVR__WIDTH                         1
#define SWREG_SIMPLE_SIMPLE0__FIXHARVENERG_OVR__MASK                0x00002000U
#define SWREG_SIMPLE_SIMPLE0__FIXHARVENERG_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00002000U) >> 13)
#define SWREG_SIMPLE_SIMPLE0__FIXHARVENERG_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 13) & 0x00002000U)
#define SWREG_SIMPLE_SIMPLE0__FIXHARVENERG_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | (((uint32_t)(src) <<\
                    13) & 0x00002000U)
#define SWREG_SIMPLE_SIMPLE0__FIXHARVENERG_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 13) & ~0x00002000U)))
#define SWREG_SIMPLE_SIMPLE0__FIXHARVENERG_OVR__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | ((uint32_t)(1) << 13)
#define SWREG_SIMPLE_SIMPLE0__FIXHARVENERG_OVR__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00002000U) | ((uint32_t)(0) << 13)
#define SWREG_SIMPLE_SIMPLE0__FIXHARVENERG_OVR__RESET_VALUE         0x00000000U
/** @} */

/* macros for field fixHarvEnerg_ovrVal */
/**
 * @defgroup swreg_simple_regs_core_fixHarvEnerg_ovrVal_field fixHarvEnerg_ovrVal_field
 * @brief macros for field fixHarvEnerg_ovrVal
 * @details override value for fixing the energize time for all destinations when the source is the harvester
 * @{
 */
#define SWREG_SIMPLE_SIMPLE0__FIXHARVENERG_OVRVAL__SHIFT                     14
#define SWREG_SIMPLE_SIMPLE0__FIXHARVENERG_OVRVAL__WIDTH                      1
#define SWREG_SIMPLE_SIMPLE0__FIXHARVENERG_OVRVAL__MASK             0x00004000U
#define SWREG_SIMPLE_SIMPLE0__FIXHARVENERG_OVRVAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00004000U) >> 14)
#define SWREG_SIMPLE_SIMPLE0__FIXHARVENERG_OVRVAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 14) & 0x00004000U)
#define SWREG_SIMPLE_SIMPLE0__FIXHARVENERG_OVRVAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | (((uint32_t)(src) <<\
                    14) & 0x00004000U)
#define SWREG_SIMPLE_SIMPLE0__FIXHARVENERG_OVRVAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 14) & ~0x00004000U)))
#define SWREG_SIMPLE_SIMPLE0__FIXHARVENERG_OVRVAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | ((uint32_t)(1) << 14)
#define SWREG_SIMPLE_SIMPLE0__FIXHARVENERG_OVRVAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00004000U) | ((uint32_t)(0) << 14)
#define SWREG_SIMPLE_SIMPLE0__FIXHARVENERG_OVRVAL__RESET_VALUE      0x00000000U
/** @} */

/* macros for field buckBoost_ovr */
/**
 * @defgroup swreg_simple_regs_core_buckBoost_ovr_field buckBoost_ovr_field
 * @brief macros for field buckBoost_ovr
 * @details override the buck or boost mode
 * @{
 */
#define SWREG_SIMPLE_SIMPLE0__BUCKBOOST_OVR__SHIFT                           15
#define SWREG_SIMPLE_SIMPLE0__BUCKBOOST_OVR__WIDTH                           13
#define SWREG_SIMPLE_SIMPLE0__BUCKBOOST_OVR__MASK                   0x0fff8000U
#define SWREG_SIMPLE_SIMPLE0__BUCKBOOST_OVR__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0fff8000U) >> 15)
#define SWREG_SIMPLE_SIMPLE0__BUCKBOOST_OVR__WRITE(src) \
                    (((uint32_t)(src)\
                    << 15) & 0x0fff8000U)
#define SWREG_SIMPLE_SIMPLE0__BUCKBOOST_OVR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0fff8000U) | (((uint32_t)(src) <<\
                    15) & 0x0fff8000U)
#define SWREG_SIMPLE_SIMPLE0__BUCKBOOST_OVR__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 15) & ~0x0fff8000U)))
#define SWREG_SIMPLE_SIMPLE0__BUCKBOOST_OVR__RESET_VALUE            0x00000000U
/** @} */
#define SWREG_SIMPLE_SIMPLE0__TYPE                                     uint32_t
#define SWREG_SIMPLE_SIMPLE0__READ                                  0x0fffffffU
#define SWREG_SIMPLE_SIMPLE0__WRITE                                 0x0fffffffU
#define SWREG_SIMPLE_SIMPLE0__PRESERVED                             0x00000000U
#define SWREG_SIMPLE_SIMPLE0__RESET_VALUE                           0x00000000U

#endif /* __SWREG_SIMPLE_SIMPLE0_MACRO__ */

/** @} end of simple0 */

/* macros for BlueprintGlobalNameSpace::SWREG_SIMPLE_simple1 */
/**
 * @defgroup swreg_simple_regs_core_simple1 simple1
 * @brief simple swreg registers definitions.
 * @{
 */
#ifndef __SWREG_SIMPLE_SIMPLE1_MACRO__
#define __SWREG_SIMPLE_SIMPLE1_MACRO__

/* macros for field buck_ovrVal */
/**
 * @defgroup swreg_simple_regs_core_buck_ovrVal_field buck_ovrVal_field
 * @brief macros for field buck_ovrVal
 * @details if set when the corresponding buckBoost_ovr bit is one, buck mode will be used for this power transfer mode
 * @{
 */
#define SWREG_SIMPLE_SIMPLE1__BUCK_OVRVAL__SHIFT                              0
#define SWREG_SIMPLE_SIMPLE1__BUCK_OVRVAL__WIDTH                             13
#define SWREG_SIMPLE_SIMPLE1__BUCK_OVRVAL__MASK                     0x00001fffU
#define SWREG_SIMPLE_SIMPLE1__BUCK_OVRVAL__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00001fffU)
#define SWREG_SIMPLE_SIMPLE1__BUCK_OVRVAL__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00001fffU)
#define SWREG_SIMPLE_SIMPLE1__BUCK_OVRVAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00001fffU) | ((uint32_t)(src) &\
                    0x00001fffU)
#define SWREG_SIMPLE_SIMPLE1__BUCK_OVRVAL__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00001fffU)))
#define SWREG_SIMPLE_SIMPLE1__BUCK_OVRVAL__RESET_VALUE              0x00000000U
/** @} */

/* macros for field boost_ovrVal */
/**
 * @defgroup swreg_simple_regs_core_boost_ovrVal_field boost_ovrVal_field
 * @brief macros for field boost_ovrVal
 * @details if set when the corresponding buckBoost_ovr bit is one and buck_ovrVal is zero, boost mode will be used for this power transfer mode.if both buck_ovrVal and boost_ovrVal are zero buck-boost mode will be used.
 * @{
 */
#define SWREG_SIMPLE_SIMPLE1__BOOST_OVRVAL__SHIFT                            13
#define SWREG_SIMPLE_SIMPLE1__BOOST_OVRVAL__WIDTH                            13
#define SWREG_SIMPLE_SIMPLE1__BOOST_OVRVAL__MASK                    0x03ffe000U
#define SWREG_SIMPLE_SIMPLE1__BOOST_OVRVAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x03ffe000U) >> 13)
#define SWREG_SIMPLE_SIMPLE1__BOOST_OVRVAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 13) & 0x03ffe000U)
#define SWREG_SIMPLE_SIMPLE1__BOOST_OVRVAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x03ffe000U) | (((uint32_t)(src) <<\
                    13) & 0x03ffe000U)
#define SWREG_SIMPLE_SIMPLE1__BOOST_OVRVAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 13) & ~0x03ffe000U)))
#define SWREG_SIMPLE_SIMPLE1__BOOST_OVRVAL__RESET_VALUE             0x00000000U
/** @} */

/* macros for field readyForTinyLevel */
/**
 * @defgroup swreg_simple_regs_core_readyForTinyLevel_field readyForTinyLevel_field
 * @brief macros for field readyForTinyLevel
 * @details transition to the tiny FSM is delayed until the simple FSM has settled according to this setting:0: no wait1: wait until all enabled supplies are ready2: wait until all enabled supplies are ready and the targets have settled3: wait until all enabled supplies have fully settled
 * @{
 */
#define SWREG_SIMPLE_SIMPLE1__READYFORTINYLEVEL__SHIFT                       26
#define SWREG_SIMPLE_SIMPLE1__READYFORTINYLEVEL__WIDTH                        2
#define SWREG_SIMPLE_SIMPLE1__READYFORTINYLEVEL__MASK               0x0c000000U
#define SWREG_SIMPLE_SIMPLE1__READYFORTINYLEVEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0c000000U) >> 26)
#define SWREG_SIMPLE_SIMPLE1__READYFORTINYLEVEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 26) & 0x0c000000U)
#define SWREG_SIMPLE_SIMPLE1__READYFORTINYLEVEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0c000000U) | (((uint32_t)(src) <<\
                    26) & 0x0c000000U)
#define SWREG_SIMPLE_SIMPLE1__READYFORTINYLEVEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 26) & ~0x0c000000U)))
#define SWREG_SIMPLE_SIMPLE1__READYFORTINYLEVEL__RESET_VALUE        0x00000002U
/** @} */
#define SWREG_SIMPLE_SIMPLE1__TYPE                                     uint32_t
#define SWREG_SIMPLE_SIMPLE1__READ                                  0x0fffffffU
#define SWREG_SIMPLE_SIMPLE1__WRITE                                 0x0fffffffU
#define SWREG_SIMPLE_SIMPLE1__PRESERVED                             0x00000000U
#define SWREG_SIMPLE_SIMPLE1__RESET_VALUE                           0x08000000U

#endif /* __SWREG_SIMPLE_SIMPLE1_MACRO__ */

/** @} end of simple1 */

/* macros for BlueprintGlobalNameSpace::SWREG_SIMPLE_core_id */
/**
 * @defgroup swreg_simple_regs_core_core_id core_id
 * @brief Contains register fields associated with core_id. definitions.
 * @{
 */
#ifndef __SWREG_SIMPLE_CORE_ID_MACRO__
#define __SWREG_SIMPLE_CORE_ID_MACRO__

/* macros for field id */
/**
 * @defgroup swreg_simple_regs_core_id_field id_field
 * @brief macros for field id
 * @details SWRS in ASCII
 * @{
 */
#define SWREG_SIMPLE_CORE_ID__ID__SHIFT                                       0
#define SWREG_SIMPLE_CORE_ID__ID__WIDTH                                      32
#define SWREG_SIMPLE_CORE_ID__ID__MASK                              0xffffffffU
#define SWREG_SIMPLE_CORE_ID__ID__READ(src)     ((uint32_t)(src) & 0xffffffffU)
#define SWREG_SIMPLE_CORE_ID__ID__RESET_VALUE                       0x53575253U
/** @} */
#define SWREG_SIMPLE_CORE_ID__TYPE                                     uint32_t
#define SWREG_SIMPLE_CORE_ID__READ                                  0xffffffffU
#define SWREG_SIMPLE_CORE_ID__PRESERVED                             0x00000000U
#define SWREG_SIMPLE_CORE_ID__RESET_VALUE                           0x53575253U

#endif /* __SWREG_SIMPLE_CORE_ID_MACRO__ */

/** @} end of core_id */

/** @} end of SWREG_SIMPLE_REGS_CORE */
#endif /* __REG_SWREG_SIMPLE_REGS_CORE_H__ */
