/*                                                                           */
/* File:       at_apb_tsmc_efuse_128x8_regs_core_macro.h                     */
/*                                                                           */
/* Arguments:  /cad/tools/cadence/blueprint_3.7.5/Linux-64bit/blueprint -eval*/
/*             $DEFINE_PROPERTY=1; -ansic                                    */
/*             at_apb_tsmc_efuse_128x8_regs_core.rdl                         */
/*                                                                           */
/* Blueprint:   3.7.5 (Wed Feb 1 23:58:40 PST 2012)                          */
/* Machine:    gull                                                          */
/* OS:         Linux 2.6.32-696.13.2.el6.x86_64                              */
/* Description:                                                              */
/*                                                                           */
/* No Description Provided                                                   */
/*                                                                           */
/* Copyright (C) 2024 Atmosic Technologies.  All rights reserved             */
/*                                                                           */


#ifndef __REG_AT_APB_TSMC_EFUSE_128X8_REGS_CORE_H__
#define __REG_AT_APB_TSMC_EFUSE_128X8_REGS_CORE_H__

/**
 *****************************************************************************
 * @defgroup AT_APB_TSMC_EFUSE_128X8_REGS_CORE at_apb_tsmc_efuse_128x8_regs_core
 * @ingroup AT_REG
 * @brief at_apb_tsmc_efuse_128x8_regs_core definitions.
 * @{
 *****************************************************************************
 */

/* macros for BlueprintGlobalNameSpace::EFUSE_EFUSE_RDATA0 */
/**
 * @defgroup at_apb_tsmc_efuse_128x8_regs_core_EFUSE_RDATA0 EFUSE_RDATA0
 * @brief efuse bytes 3-0 definitions.
 * @{
 */
#ifndef __EFUSE_EFUSE_RDATA0_MACRO__
#define __EFUSE_EFUSE_RDATA0_MACRO__

/* macros for field rdata */
/**
 * @defgroup at_apb_tsmc_efuse_128x8_regs_core_rdata_field rdata_field
 * @brief macros for field rdata
 * @{
 */
#define EFUSE_EFUSE_RDATA0__RDATA__SHIFT                                      0
#define EFUSE_EFUSE_RDATA0__RDATA__WIDTH                                     32
#define EFUSE_EFUSE_RDATA0__RDATA__MASK                             0xffffffffU
#define EFUSE_EFUSE_RDATA0__RDATA__READ(src)    ((uint32_t)(src) & 0xffffffffU)
#define EFUSE_EFUSE_RDATA0__RDATA__RESET_VALUE                      0x00000000U
/** @} */
#define EFUSE_EFUSE_RDATA0__TYPE                                       uint32_t
#define EFUSE_EFUSE_RDATA0__READ                                    0xffffffffU
#define EFUSE_EFUSE_RDATA0__PRESERVED                               0x00000000U
#define EFUSE_EFUSE_RDATA0__RESET_VALUE                             0x00000000U

#endif /* __EFUSE_EFUSE_RDATA0_MACRO__ */

/** @} end of EFUSE_RDATA0 */

/* macros for BlueprintGlobalNameSpace::EFUSE_EFUSE_RDATA1 */
/**
 * @defgroup at_apb_tsmc_efuse_128x8_regs_core_EFUSE_RDATA1 EFUSE_RDATA1
 * @brief efuse bytes 7-4 definitions.
 * @{
 */
#ifndef __EFUSE_EFUSE_RDATA1_MACRO__
#define __EFUSE_EFUSE_RDATA1_MACRO__

/* macros for field rdata */
/**
 * @defgroup at_apb_tsmc_efuse_128x8_regs_core_rdata_field rdata_field
 * @brief macros for field rdata
 * @{
 */
#define EFUSE_EFUSE_RDATA1__RDATA__SHIFT                                      0
#define EFUSE_EFUSE_RDATA1__RDATA__WIDTH                                     32
#define EFUSE_EFUSE_RDATA1__RDATA__MASK                             0xffffffffU
#define EFUSE_EFUSE_RDATA1__RDATA__READ(src)    ((uint32_t)(src) & 0xffffffffU)
#define EFUSE_EFUSE_RDATA1__RDATA__RESET_VALUE                      0x00000000U
/** @} */
#define EFUSE_EFUSE_RDATA1__TYPE                                       uint32_t
#define EFUSE_EFUSE_RDATA1__READ                                    0xffffffffU
#define EFUSE_EFUSE_RDATA1__PRESERVED                               0x00000000U
#define EFUSE_EFUSE_RDATA1__RESET_VALUE                             0x00000000U

#endif /* __EFUSE_EFUSE_RDATA1_MACRO__ */

/** @} end of EFUSE_RDATA1 */

/* macros for BlueprintGlobalNameSpace::EFUSE_EFUSE_RDATA2 */
/**
 * @defgroup at_apb_tsmc_efuse_128x8_regs_core_EFUSE_RDATA2 EFUSE_RDATA2
 * @brief efuse bytes 11-8 definitions.
 * @{
 */
#ifndef __EFUSE_EFUSE_RDATA2_MACRO__
#define __EFUSE_EFUSE_RDATA2_MACRO__

/* macros for field rdata */
/**
 * @defgroup at_apb_tsmc_efuse_128x8_regs_core_rdata_field rdata_field
 * @brief macros for field rdata
 * @{
 */
#define EFUSE_EFUSE_RDATA2__RDATA__SHIFT                                      0
#define EFUSE_EFUSE_RDATA2__RDATA__WIDTH                                     32
#define EFUSE_EFUSE_RDATA2__RDATA__MASK                             0xffffffffU
#define EFUSE_EFUSE_RDATA2__RDATA__READ(src)    ((uint32_t)(src) & 0xffffffffU)
#define EFUSE_EFUSE_RDATA2__RDATA__RESET_VALUE                      0x00000000U
/** @} */
#define EFUSE_EFUSE_RDATA2__TYPE                                       uint32_t
#define EFUSE_EFUSE_RDATA2__READ                                    0xffffffffU
#define EFUSE_EFUSE_RDATA2__PRESERVED                               0x00000000U
#define EFUSE_EFUSE_RDATA2__RESET_VALUE                             0x00000000U

#endif /* __EFUSE_EFUSE_RDATA2_MACRO__ */

/** @} end of EFUSE_RDATA2 */

/* macros for BlueprintGlobalNameSpace::EFUSE_EFUSE_RDATA3 */
/**
 * @defgroup at_apb_tsmc_efuse_128x8_regs_core_EFUSE_RDATA3 EFUSE_RDATA3
 * @brief efuse bytes 15-12 definitions.
 * @{
 */
#ifndef __EFUSE_EFUSE_RDATA3_MACRO__
#define __EFUSE_EFUSE_RDATA3_MACRO__

/* macros for field rdata */
/**
 * @defgroup at_apb_tsmc_efuse_128x8_regs_core_rdata_field rdata_field
 * @brief macros for field rdata
 * @{
 */
#define EFUSE_EFUSE_RDATA3__RDATA__SHIFT                                      0
#define EFUSE_EFUSE_RDATA3__RDATA__WIDTH                                     32
#define EFUSE_EFUSE_RDATA3__RDATA__MASK                             0xffffffffU
#define EFUSE_EFUSE_RDATA3__RDATA__READ(src)    ((uint32_t)(src) & 0xffffffffU)
#define EFUSE_EFUSE_RDATA3__RDATA__RESET_VALUE                      0x00000000U
/** @} */
#define EFUSE_EFUSE_RDATA3__TYPE                                       uint32_t
#define EFUSE_EFUSE_RDATA3__READ                                    0xffffffffU
#define EFUSE_EFUSE_RDATA3__PRESERVED                               0x00000000U
#define EFUSE_EFUSE_RDATA3__RESET_VALUE                             0x00000000U

#endif /* __EFUSE_EFUSE_RDATA3_MACRO__ */

/** @} end of EFUSE_RDATA3 */

/* macros for BlueprintGlobalNameSpace::EFUSE_EFUSE_RDATA4 */
/**
 * @defgroup at_apb_tsmc_efuse_128x8_regs_core_EFUSE_RDATA4 EFUSE_RDATA4
 * @brief efuse bytes 19-16 definitions.
 * @{
 */
#ifndef __EFUSE_EFUSE_RDATA4_MACRO__
#define __EFUSE_EFUSE_RDATA4_MACRO__

/* macros for field rdata */
/**
 * @defgroup at_apb_tsmc_efuse_128x8_regs_core_rdata_field rdata_field
 * @brief macros for field rdata
 * @{
 */
#define EFUSE_EFUSE_RDATA4__RDATA__SHIFT                                      0
#define EFUSE_EFUSE_RDATA4__RDATA__WIDTH                                     32
#define EFUSE_EFUSE_RDATA4__RDATA__MASK                             0xffffffffU
#define EFUSE_EFUSE_RDATA4__RDATA__READ(src)    ((uint32_t)(src) & 0xffffffffU)
#define EFUSE_EFUSE_RDATA4__RDATA__RESET_VALUE                      0x00000000U
/** @} */
#define EFUSE_EFUSE_RDATA4__TYPE                                       uint32_t
#define EFUSE_EFUSE_RDATA4__READ                                    0xffffffffU
#define EFUSE_EFUSE_RDATA4__PRESERVED                               0x00000000U
#define EFUSE_EFUSE_RDATA4__RESET_VALUE                             0x00000000U

#endif /* __EFUSE_EFUSE_RDATA4_MACRO__ */

/** @} end of EFUSE_RDATA4 */

/* macros for BlueprintGlobalNameSpace::EFUSE_EFUSE_RDATA5 */
/**
 * @defgroup at_apb_tsmc_efuse_128x8_regs_core_EFUSE_RDATA5 EFUSE_RDATA5
 * @brief efuse bytes 23-20 definitions.
 * @{
 */
#ifndef __EFUSE_EFUSE_RDATA5_MACRO__
#define __EFUSE_EFUSE_RDATA5_MACRO__

/* macros for field rdata */
/**
 * @defgroup at_apb_tsmc_efuse_128x8_regs_core_rdata_field rdata_field
 * @brief macros for field rdata
 * @{
 */
#define EFUSE_EFUSE_RDATA5__RDATA__SHIFT                                      0
#define EFUSE_EFUSE_RDATA5__RDATA__WIDTH                                     32
#define EFUSE_EFUSE_RDATA5__RDATA__MASK                             0xffffffffU
#define EFUSE_EFUSE_RDATA5__RDATA__READ(src)    ((uint32_t)(src) & 0xffffffffU)
#define EFUSE_EFUSE_RDATA5__RDATA__RESET_VALUE                      0x00000000U
/** @} */
#define EFUSE_EFUSE_RDATA5__TYPE                                       uint32_t
#define EFUSE_EFUSE_RDATA5__READ                                    0xffffffffU
#define EFUSE_EFUSE_RDATA5__PRESERVED                               0x00000000U
#define EFUSE_EFUSE_RDATA5__RESET_VALUE                             0x00000000U

#endif /* __EFUSE_EFUSE_RDATA5_MACRO__ */

/** @} end of EFUSE_RDATA5 */

/* macros for BlueprintGlobalNameSpace::EFUSE_EFUSE_RDATA6 */
/**
 * @defgroup at_apb_tsmc_efuse_128x8_regs_core_EFUSE_RDATA6 EFUSE_RDATA6
 * @brief efuse bytes 27-24 definitions.
 * @{
 */
#ifndef __EFUSE_EFUSE_RDATA6_MACRO__
#define __EFUSE_EFUSE_RDATA6_MACRO__

/* macros for field rdata */
/**
 * @defgroup at_apb_tsmc_efuse_128x8_regs_core_rdata_field rdata_field
 * @brief macros for field rdata
 * @{
 */
#define EFUSE_EFUSE_RDATA6__RDATA__SHIFT                                      0
#define EFUSE_EFUSE_RDATA6__RDATA__WIDTH                                     32
#define EFUSE_EFUSE_RDATA6__RDATA__MASK                             0xffffffffU
#define EFUSE_EFUSE_RDATA6__RDATA__READ(src)    ((uint32_t)(src) & 0xffffffffU)
#define EFUSE_EFUSE_RDATA6__RDATA__RESET_VALUE                      0x00000000U
/** @} */
#define EFUSE_EFUSE_RDATA6__TYPE                                       uint32_t
#define EFUSE_EFUSE_RDATA6__READ                                    0xffffffffU
#define EFUSE_EFUSE_RDATA6__PRESERVED                               0x00000000U
#define EFUSE_EFUSE_RDATA6__RESET_VALUE                             0x00000000U

#endif /* __EFUSE_EFUSE_RDATA6_MACRO__ */

/** @} end of EFUSE_RDATA6 */

/* macros for BlueprintGlobalNameSpace::EFUSE_EFUSE_RDATA7 */
/**
 * @defgroup at_apb_tsmc_efuse_128x8_regs_core_EFUSE_RDATA7 EFUSE_RDATA7
 * @brief efuse bytes 31-28 definitions.
 * @{
 */
#ifndef __EFUSE_EFUSE_RDATA7_MACRO__
#define __EFUSE_EFUSE_RDATA7_MACRO__

/* macros for field rdata */
/**
 * @defgroup at_apb_tsmc_efuse_128x8_regs_core_rdata_field rdata_field
 * @brief macros for field rdata
 * @{
 */
#define EFUSE_EFUSE_RDATA7__RDATA__SHIFT                                      0
#define EFUSE_EFUSE_RDATA7__RDATA__WIDTH                                     32
#define EFUSE_EFUSE_RDATA7__RDATA__MASK                             0xffffffffU
#define EFUSE_EFUSE_RDATA7__RDATA__READ(src)    ((uint32_t)(src) & 0xffffffffU)
#define EFUSE_EFUSE_RDATA7__RDATA__RESET_VALUE                      0x00000000U
/** @} */
#define EFUSE_EFUSE_RDATA7__TYPE                                       uint32_t
#define EFUSE_EFUSE_RDATA7__READ                                    0xffffffffU
#define EFUSE_EFUSE_RDATA7__PRESERVED                               0x00000000U
#define EFUSE_EFUSE_RDATA7__RESET_VALUE                             0x00000000U

#endif /* __EFUSE_EFUSE_RDATA7_MACRO__ */

/** @} end of EFUSE_RDATA7 */

/* macros for BlueprintGlobalNameSpace::EFUSE_EFUSE_RDATA8 */
/**
 * @defgroup at_apb_tsmc_efuse_128x8_regs_core_EFUSE_RDATA8 EFUSE_RDATA8
 * @brief efuse bytes 35-32 definitions.
 * @{
 */
#ifndef __EFUSE_EFUSE_RDATA8_MACRO__
#define __EFUSE_EFUSE_RDATA8_MACRO__

/* macros for field rdata */
/**
 * @defgroup at_apb_tsmc_efuse_128x8_regs_core_rdata_field rdata_field
 * @brief macros for field rdata
 * @{
 */
#define EFUSE_EFUSE_RDATA8__RDATA__SHIFT                                      0
#define EFUSE_EFUSE_RDATA8__RDATA__WIDTH                                     32
#define EFUSE_EFUSE_RDATA8__RDATA__MASK                             0xffffffffU
#define EFUSE_EFUSE_RDATA8__RDATA__READ(src)    ((uint32_t)(src) & 0xffffffffU)
#define EFUSE_EFUSE_RDATA8__RDATA__RESET_VALUE                      0x00000000U
/** @} */
#define EFUSE_EFUSE_RDATA8__TYPE                                       uint32_t
#define EFUSE_EFUSE_RDATA8__READ                                    0xffffffffU
#define EFUSE_EFUSE_RDATA8__PRESERVED                               0x00000000U
#define EFUSE_EFUSE_RDATA8__RESET_VALUE                             0x00000000U

#endif /* __EFUSE_EFUSE_RDATA8_MACRO__ */

/** @} end of EFUSE_RDATA8 */

/* macros for BlueprintGlobalNameSpace::EFUSE_EFUSE_RDATA9 */
/**
 * @defgroup at_apb_tsmc_efuse_128x8_regs_core_EFUSE_RDATA9 EFUSE_RDATA9
 * @brief efuse bytes 39-36 definitions.
 * @{
 */
#ifndef __EFUSE_EFUSE_RDATA9_MACRO__
#define __EFUSE_EFUSE_RDATA9_MACRO__

/* macros for field rdata */
/**
 * @defgroup at_apb_tsmc_efuse_128x8_regs_core_rdata_field rdata_field
 * @brief macros for field rdata
 * @{
 */
#define EFUSE_EFUSE_RDATA9__RDATA__SHIFT                                      0
#define EFUSE_EFUSE_RDATA9__RDATA__WIDTH                                     32
#define EFUSE_EFUSE_RDATA9__RDATA__MASK                             0xffffffffU
#define EFUSE_EFUSE_RDATA9__RDATA__READ(src)    ((uint32_t)(src) & 0xffffffffU)
#define EFUSE_EFUSE_RDATA9__RDATA__RESET_VALUE                      0x00000000U
/** @} */
#define EFUSE_EFUSE_RDATA9__TYPE                                       uint32_t
#define EFUSE_EFUSE_RDATA9__READ                                    0xffffffffU
#define EFUSE_EFUSE_RDATA9__PRESERVED                               0x00000000U
#define EFUSE_EFUSE_RDATA9__RESET_VALUE                             0x00000000U

#endif /* __EFUSE_EFUSE_RDATA9_MACRO__ */

/** @} end of EFUSE_RDATA9 */

/* macros for BlueprintGlobalNameSpace::EFUSE_EFUSE_RDATA10 */
/**
 * @defgroup at_apb_tsmc_efuse_128x8_regs_core_EFUSE_RDATA10 EFUSE_RDATA10
 * @brief efuse bytes 43-40 definitions.
 * @{
 */
#ifndef __EFUSE_EFUSE_RDATA10_MACRO__
#define __EFUSE_EFUSE_RDATA10_MACRO__

/* macros for field rdata */
/**
 * @defgroup at_apb_tsmc_efuse_128x8_regs_core_rdata_field rdata_field
 * @brief macros for field rdata
 * @{
 */
#define EFUSE_EFUSE_RDATA10__RDATA__SHIFT                                     0
#define EFUSE_EFUSE_RDATA10__RDATA__WIDTH                                    32
#define EFUSE_EFUSE_RDATA10__RDATA__MASK                            0xffffffffU
#define EFUSE_EFUSE_RDATA10__RDATA__READ(src)   ((uint32_t)(src) & 0xffffffffU)
#define EFUSE_EFUSE_RDATA10__RDATA__RESET_VALUE                     0x00000000U
/** @} */
#define EFUSE_EFUSE_RDATA10__TYPE                                      uint32_t
#define EFUSE_EFUSE_RDATA10__READ                                   0xffffffffU
#define EFUSE_EFUSE_RDATA10__PRESERVED                              0x00000000U
#define EFUSE_EFUSE_RDATA10__RESET_VALUE                            0x00000000U

#endif /* __EFUSE_EFUSE_RDATA10_MACRO__ */

/** @} end of EFUSE_RDATA10 */

/* macros for BlueprintGlobalNameSpace::EFUSE_EFUSE_RDATA11 */
/**
 * @defgroup at_apb_tsmc_efuse_128x8_regs_core_EFUSE_RDATA11 EFUSE_RDATA11
 * @brief efuse bytes 47-44 definitions.
 * @{
 */
#ifndef __EFUSE_EFUSE_RDATA11_MACRO__
#define __EFUSE_EFUSE_RDATA11_MACRO__

/* macros for field rdata */
/**
 * @defgroup at_apb_tsmc_efuse_128x8_regs_core_rdata_field rdata_field
 * @brief macros for field rdata
 * @{
 */
#define EFUSE_EFUSE_RDATA11__RDATA__SHIFT                                     0
#define EFUSE_EFUSE_RDATA11__RDATA__WIDTH                                    32
#define EFUSE_EFUSE_RDATA11__RDATA__MASK                            0xffffffffU
#define EFUSE_EFUSE_RDATA11__RDATA__READ(src)   ((uint32_t)(src) & 0xffffffffU)
#define EFUSE_EFUSE_RDATA11__RDATA__RESET_VALUE                     0x00000000U
/** @} */
#define EFUSE_EFUSE_RDATA11__TYPE                                      uint32_t
#define EFUSE_EFUSE_RDATA11__READ                                   0xffffffffU
#define EFUSE_EFUSE_RDATA11__PRESERVED                              0x00000000U
#define EFUSE_EFUSE_RDATA11__RESET_VALUE                            0x00000000U

#endif /* __EFUSE_EFUSE_RDATA11_MACRO__ */

/** @} end of EFUSE_RDATA11 */

/* macros for BlueprintGlobalNameSpace::EFUSE_EFUSE_RDATA12 */
/**
 * @defgroup at_apb_tsmc_efuse_128x8_regs_core_EFUSE_RDATA12 EFUSE_RDATA12
 * @brief efuse bytes 51-48 definitions.
 * @{
 */
#ifndef __EFUSE_EFUSE_RDATA12_MACRO__
#define __EFUSE_EFUSE_RDATA12_MACRO__

/* macros for field rdata */
/**
 * @defgroup at_apb_tsmc_efuse_128x8_regs_core_rdata_field rdata_field
 * @brief macros for field rdata
 * @{
 */
#define EFUSE_EFUSE_RDATA12__RDATA__SHIFT                                     0
#define EFUSE_EFUSE_RDATA12__RDATA__WIDTH                                    32
#define EFUSE_EFUSE_RDATA12__RDATA__MASK                            0xffffffffU
#define EFUSE_EFUSE_RDATA12__RDATA__READ(src)   ((uint32_t)(src) & 0xffffffffU)
#define EFUSE_EFUSE_RDATA12__RDATA__RESET_VALUE                     0x00000000U
/** @} */
#define EFUSE_EFUSE_RDATA12__TYPE                                      uint32_t
#define EFUSE_EFUSE_RDATA12__READ                                   0xffffffffU
#define EFUSE_EFUSE_RDATA12__PRESERVED                              0x00000000U
#define EFUSE_EFUSE_RDATA12__RESET_VALUE                            0x00000000U

#endif /* __EFUSE_EFUSE_RDATA12_MACRO__ */

/** @} end of EFUSE_RDATA12 */

/* macros for BlueprintGlobalNameSpace::EFUSE_EFUSE_RDATA13 */
/**
 * @defgroup at_apb_tsmc_efuse_128x8_regs_core_EFUSE_RDATA13 EFUSE_RDATA13
 * @brief efuse bytes 55-52 definitions.
 * @{
 */
#ifndef __EFUSE_EFUSE_RDATA13_MACRO__
#define __EFUSE_EFUSE_RDATA13_MACRO__

/* macros for field rdata */
/**
 * @defgroup at_apb_tsmc_efuse_128x8_regs_core_rdata_field rdata_field
 * @brief macros for field rdata
 * @{
 */
#define EFUSE_EFUSE_RDATA13__RDATA__SHIFT                                     0
#define EFUSE_EFUSE_RDATA13__RDATA__WIDTH                                    32
#define EFUSE_EFUSE_RDATA13__RDATA__MASK                            0xffffffffU
#define EFUSE_EFUSE_RDATA13__RDATA__READ(src)   ((uint32_t)(src) & 0xffffffffU)
#define EFUSE_EFUSE_RDATA13__RDATA__RESET_VALUE                     0x00000000U
/** @} */
#define EFUSE_EFUSE_RDATA13__TYPE                                      uint32_t
#define EFUSE_EFUSE_RDATA13__READ                                   0xffffffffU
#define EFUSE_EFUSE_RDATA13__PRESERVED                              0x00000000U
#define EFUSE_EFUSE_RDATA13__RESET_VALUE                            0x00000000U

#endif /* __EFUSE_EFUSE_RDATA13_MACRO__ */

/** @} end of EFUSE_RDATA13 */

/* macros for BlueprintGlobalNameSpace::EFUSE_EFUSE_RDATA14 */
/**
 * @defgroup at_apb_tsmc_efuse_128x8_regs_core_EFUSE_RDATA14 EFUSE_RDATA14
 * @brief efuse bytes 59-56 definitions.
 * @{
 */
#ifndef __EFUSE_EFUSE_RDATA14_MACRO__
#define __EFUSE_EFUSE_RDATA14_MACRO__

/* macros for field rdata */
/**
 * @defgroup at_apb_tsmc_efuse_128x8_regs_core_rdata_field rdata_field
 * @brief macros for field rdata
 * @{
 */
#define EFUSE_EFUSE_RDATA14__RDATA__SHIFT                                     0
#define EFUSE_EFUSE_RDATA14__RDATA__WIDTH                                    32
#define EFUSE_EFUSE_RDATA14__RDATA__MASK                            0xffffffffU
#define EFUSE_EFUSE_RDATA14__RDATA__READ(src)   ((uint32_t)(src) & 0xffffffffU)
#define EFUSE_EFUSE_RDATA14__RDATA__RESET_VALUE                     0x00000000U
/** @} */
#define EFUSE_EFUSE_RDATA14__TYPE                                      uint32_t
#define EFUSE_EFUSE_RDATA14__READ                                   0xffffffffU
#define EFUSE_EFUSE_RDATA14__PRESERVED                              0x00000000U
#define EFUSE_EFUSE_RDATA14__RESET_VALUE                            0x00000000U

#endif /* __EFUSE_EFUSE_RDATA14_MACRO__ */

/** @} end of EFUSE_RDATA14 */

/* macros for BlueprintGlobalNameSpace::EFUSE_EFUSE_RDATA15 */
/**
 * @defgroup at_apb_tsmc_efuse_128x8_regs_core_EFUSE_RDATA15 EFUSE_RDATA15
 * @brief efuse bytes 63-60 definitions.
 * @{
 */
#ifndef __EFUSE_EFUSE_RDATA15_MACRO__
#define __EFUSE_EFUSE_RDATA15_MACRO__

/* macros for field rdata */
/**
 * @defgroup at_apb_tsmc_efuse_128x8_regs_core_rdata_field rdata_field
 * @brief macros for field rdata
 * @{
 */
#define EFUSE_EFUSE_RDATA15__RDATA__SHIFT                                     0
#define EFUSE_EFUSE_RDATA15__RDATA__WIDTH                                    32
#define EFUSE_EFUSE_RDATA15__RDATA__MASK                            0xffffffffU
#define EFUSE_EFUSE_RDATA15__RDATA__READ(src)   ((uint32_t)(src) & 0xffffffffU)
#define EFUSE_EFUSE_RDATA15__RDATA__RESET_VALUE                     0x00000000U
/** @} */
#define EFUSE_EFUSE_RDATA15__TYPE                                      uint32_t
#define EFUSE_EFUSE_RDATA15__READ                                   0xffffffffU
#define EFUSE_EFUSE_RDATA15__PRESERVED                              0x00000000U
#define EFUSE_EFUSE_RDATA15__RESET_VALUE                            0x00000000U

#endif /* __EFUSE_EFUSE_RDATA15_MACRO__ */

/** @} end of EFUSE_RDATA15 */

/* macros for BlueprintGlobalNameSpace::EFUSE_EFUSE_RDATA16 */
/**
 * @defgroup at_apb_tsmc_efuse_128x8_regs_core_EFUSE_RDATA16 EFUSE_RDATA16
 * @brief efuse bytes 67-64 definitions.
 * @{
 */
#ifndef __EFUSE_EFUSE_RDATA16_MACRO__
#define __EFUSE_EFUSE_RDATA16_MACRO__

/* macros for field rdata */
/**
 * @defgroup at_apb_tsmc_efuse_128x8_regs_core_rdata_field rdata_field
 * @brief macros for field rdata
 * @{
 */
#define EFUSE_EFUSE_RDATA16__RDATA__SHIFT                                     0
#define EFUSE_EFUSE_RDATA16__RDATA__WIDTH                                    32
#define EFUSE_EFUSE_RDATA16__RDATA__MASK                            0xffffffffU
#define EFUSE_EFUSE_RDATA16__RDATA__READ(src)   ((uint32_t)(src) & 0xffffffffU)
#define EFUSE_EFUSE_RDATA16__RDATA__RESET_VALUE                     0x00000000U
/** @} */
#define EFUSE_EFUSE_RDATA16__TYPE                                      uint32_t
#define EFUSE_EFUSE_RDATA16__READ                                   0xffffffffU
#define EFUSE_EFUSE_RDATA16__PRESERVED                              0x00000000U
#define EFUSE_EFUSE_RDATA16__RESET_VALUE                            0x00000000U

#endif /* __EFUSE_EFUSE_RDATA16_MACRO__ */

/** @} end of EFUSE_RDATA16 */

/* macros for BlueprintGlobalNameSpace::EFUSE_EFUSE_RDATA17 */
/**
 * @defgroup at_apb_tsmc_efuse_128x8_regs_core_EFUSE_RDATA17 EFUSE_RDATA17
 * @brief efuse bytes 71-68 definitions.
 * @{
 */
#ifndef __EFUSE_EFUSE_RDATA17_MACRO__
#define __EFUSE_EFUSE_RDATA17_MACRO__

/* macros for field rdata */
/**
 * @defgroup at_apb_tsmc_efuse_128x8_regs_core_rdata_field rdata_field
 * @brief macros for field rdata
 * @{
 */
#define EFUSE_EFUSE_RDATA17__RDATA__SHIFT                                     0
#define EFUSE_EFUSE_RDATA17__RDATA__WIDTH                                    32
#define EFUSE_EFUSE_RDATA17__RDATA__MASK                            0xffffffffU
#define EFUSE_EFUSE_RDATA17__RDATA__READ(src)   ((uint32_t)(src) & 0xffffffffU)
#define EFUSE_EFUSE_RDATA17__RDATA__RESET_VALUE                     0x00000000U
/** @} */
#define EFUSE_EFUSE_RDATA17__TYPE                                      uint32_t
#define EFUSE_EFUSE_RDATA17__READ                                   0xffffffffU
#define EFUSE_EFUSE_RDATA17__PRESERVED                              0x00000000U
#define EFUSE_EFUSE_RDATA17__RESET_VALUE                            0x00000000U

#endif /* __EFUSE_EFUSE_RDATA17_MACRO__ */

/** @} end of EFUSE_RDATA17 */

/* macros for BlueprintGlobalNameSpace::EFUSE_EFUSE_RDATA18 */
/**
 * @defgroup at_apb_tsmc_efuse_128x8_regs_core_EFUSE_RDATA18 EFUSE_RDATA18
 * @brief efuse bytes 75-72 definitions.
 * @{
 */
#ifndef __EFUSE_EFUSE_RDATA18_MACRO__
#define __EFUSE_EFUSE_RDATA18_MACRO__

/* macros for field rdata */
/**
 * @defgroup at_apb_tsmc_efuse_128x8_regs_core_rdata_field rdata_field
 * @brief macros for field rdata
 * @{
 */
#define EFUSE_EFUSE_RDATA18__RDATA__SHIFT                                     0
#define EFUSE_EFUSE_RDATA18__RDATA__WIDTH                                    32
#define EFUSE_EFUSE_RDATA18__RDATA__MASK                            0xffffffffU
#define EFUSE_EFUSE_RDATA18__RDATA__READ(src)   ((uint32_t)(src) & 0xffffffffU)
#define EFUSE_EFUSE_RDATA18__RDATA__RESET_VALUE                     0x00000000U
/** @} */
#define EFUSE_EFUSE_RDATA18__TYPE                                      uint32_t
#define EFUSE_EFUSE_RDATA18__READ                                   0xffffffffU
#define EFUSE_EFUSE_RDATA18__PRESERVED                              0x00000000U
#define EFUSE_EFUSE_RDATA18__RESET_VALUE                            0x00000000U

#endif /* __EFUSE_EFUSE_RDATA18_MACRO__ */

/** @} end of EFUSE_RDATA18 */

/* macros for BlueprintGlobalNameSpace::EFUSE_EFUSE_RDATA19 */
/**
 * @defgroup at_apb_tsmc_efuse_128x8_regs_core_EFUSE_RDATA19 EFUSE_RDATA19
 * @brief efuse bytes 79-76 definitions.
 * @{
 */
#ifndef __EFUSE_EFUSE_RDATA19_MACRO__
#define __EFUSE_EFUSE_RDATA19_MACRO__

/* macros for field rdata */
/**
 * @defgroup at_apb_tsmc_efuse_128x8_regs_core_rdata_field rdata_field
 * @brief macros for field rdata
 * @{
 */
#define EFUSE_EFUSE_RDATA19__RDATA__SHIFT                                     0
#define EFUSE_EFUSE_RDATA19__RDATA__WIDTH                                    32
#define EFUSE_EFUSE_RDATA19__RDATA__MASK                            0xffffffffU
#define EFUSE_EFUSE_RDATA19__RDATA__READ(src)   ((uint32_t)(src) & 0xffffffffU)
#define EFUSE_EFUSE_RDATA19__RDATA__RESET_VALUE                     0x00000000U
/** @} */
#define EFUSE_EFUSE_RDATA19__TYPE                                      uint32_t
#define EFUSE_EFUSE_RDATA19__READ                                   0xffffffffU
#define EFUSE_EFUSE_RDATA19__PRESERVED                              0x00000000U
#define EFUSE_EFUSE_RDATA19__RESET_VALUE                            0x00000000U

#endif /* __EFUSE_EFUSE_RDATA19_MACRO__ */

/** @} end of EFUSE_RDATA19 */

/* macros for BlueprintGlobalNameSpace::EFUSE_EFUSE_RDATA20 */
/**
 * @defgroup at_apb_tsmc_efuse_128x8_regs_core_EFUSE_RDATA20 EFUSE_RDATA20
 * @brief efuse bytes 83-80 definitions.
 * @{
 */
#ifndef __EFUSE_EFUSE_RDATA20_MACRO__
#define __EFUSE_EFUSE_RDATA20_MACRO__

/* macros for field rdata */
/**
 * @defgroup at_apb_tsmc_efuse_128x8_regs_core_rdata_field rdata_field
 * @brief macros for field rdata
 * @{
 */
#define EFUSE_EFUSE_RDATA20__RDATA__SHIFT                                     0
#define EFUSE_EFUSE_RDATA20__RDATA__WIDTH                                    32
#define EFUSE_EFUSE_RDATA20__RDATA__MASK                            0xffffffffU
#define EFUSE_EFUSE_RDATA20__RDATA__READ(src)   ((uint32_t)(src) & 0xffffffffU)
#define EFUSE_EFUSE_RDATA20__RDATA__RESET_VALUE                     0x00000000U
/** @} */
#define EFUSE_EFUSE_RDATA20__TYPE                                      uint32_t
#define EFUSE_EFUSE_RDATA20__READ                                   0xffffffffU
#define EFUSE_EFUSE_RDATA20__PRESERVED                              0x00000000U
#define EFUSE_EFUSE_RDATA20__RESET_VALUE                            0x00000000U

#endif /* __EFUSE_EFUSE_RDATA20_MACRO__ */

/** @} end of EFUSE_RDATA20 */

/* macros for BlueprintGlobalNameSpace::EFUSE_EFUSE_RDATA21 */
/**
 * @defgroup at_apb_tsmc_efuse_128x8_regs_core_EFUSE_RDATA21 EFUSE_RDATA21
 * @brief efuse bytes 87-84 definitions.
 * @{
 */
#ifndef __EFUSE_EFUSE_RDATA21_MACRO__
#define __EFUSE_EFUSE_RDATA21_MACRO__

/* macros for field rdata */
/**
 * @defgroup at_apb_tsmc_efuse_128x8_regs_core_rdata_field rdata_field
 * @brief macros for field rdata
 * @{
 */
#define EFUSE_EFUSE_RDATA21__RDATA__SHIFT                                     0
#define EFUSE_EFUSE_RDATA21__RDATA__WIDTH                                    32
#define EFUSE_EFUSE_RDATA21__RDATA__MASK                            0xffffffffU
#define EFUSE_EFUSE_RDATA21__RDATA__READ(src)   ((uint32_t)(src) & 0xffffffffU)
#define EFUSE_EFUSE_RDATA21__RDATA__RESET_VALUE                     0x00000000U
/** @} */
#define EFUSE_EFUSE_RDATA21__TYPE                                      uint32_t
#define EFUSE_EFUSE_RDATA21__READ                                   0xffffffffU
#define EFUSE_EFUSE_RDATA21__PRESERVED                              0x00000000U
#define EFUSE_EFUSE_RDATA21__RESET_VALUE                            0x00000000U

#endif /* __EFUSE_EFUSE_RDATA21_MACRO__ */

/** @} end of EFUSE_RDATA21 */

/* macros for BlueprintGlobalNameSpace::EFUSE_EFUSE_RDATA22 */
/**
 * @defgroup at_apb_tsmc_efuse_128x8_regs_core_EFUSE_RDATA22 EFUSE_RDATA22
 * @brief efuse bytes 91-88 definitions.
 * @{
 */
#ifndef __EFUSE_EFUSE_RDATA22_MACRO__
#define __EFUSE_EFUSE_RDATA22_MACRO__

/* macros for field rdata */
/**
 * @defgroup at_apb_tsmc_efuse_128x8_regs_core_rdata_field rdata_field
 * @brief macros for field rdata
 * @{
 */
#define EFUSE_EFUSE_RDATA22__RDATA__SHIFT                                     0
#define EFUSE_EFUSE_RDATA22__RDATA__WIDTH                                    32
#define EFUSE_EFUSE_RDATA22__RDATA__MASK                            0xffffffffU
#define EFUSE_EFUSE_RDATA22__RDATA__READ(src)   ((uint32_t)(src) & 0xffffffffU)
#define EFUSE_EFUSE_RDATA22__RDATA__RESET_VALUE                     0x00000000U
/** @} */
#define EFUSE_EFUSE_RDATA22__TYPE                                      uint32_t
#define EFUSE_EFUSE_RDATA22__READ                                   0xffffffffU
#define EFUSE_EFUSE_RDATA22__PRESERVED                              0x00000000U
#define EFUSE_EFUSE_RDATA22__RESET_VALUE                            0x00000000U

#endif /* __EFUSE_EFUSE_RDATA22_MACRO__ */

/** @} end of EFUSE_RDATA22 */

/* macros for BlueprintGlobalNameSpace::EFUSE_EFUSE_RDATA23 */
/**
 * @defgroup at_apb_tsmc_efuse_128x8_regs_core_EFUSE_RDATA23 EFUSE_RDATA23
 * @brief efuse bytes 95-92 definitions.
 * @{
 */
#ifndef __EFUSE_EFUSE_RDATA23_MACRO__
#define __EFUSE_EFUSE_RDATA23_MACRO__

/* macros for field rdata */
/**
 * @defgroup at_apb_tsmc_efuse_128x8_regs_core_rdata_field rdata_field
 * @brief macros for field rdata
 * @{
 */
#define EFUSE_EFUSE_RDATA23__RDATA__SHIFT                                     0
#define EFUSE_EFUSE_RDATA23__RDATA__WIDTH                                    32
#define EFUSE_EFUSE_RDATA23__RDATA__MASK                            0xffffffffU
#define EFUSE_EFUSE_RDATA23__RDATA__READ(src)   ((uint32_t)(src) & 0xffffffffU)
#define EFUSE_EFUSE_RDATA23__RDATA__RESET_VALUE                     0x00000000U
/** @} */
#define EFUSE_EFUSE_RDATA23__TYPE                                      uint32_t
#define EFUSE_EFUSE_RDATA23__READ                                   0xffffffffU
#define EFUSE_EFUSE_RDATA23__PRESERVED                              0x00000000U
#define EFUSE_EFUSE_RDATA23__RESET_VALUE                            0x00000000U

#endif /* __EFUSE_EFUSE_RDATA23_MACRO__ */

/** @} end of EFUSE_RDATA23 */

/* macros for BlueprintGlobalNameSpace::EFUSE_EFUSE_RDATA24 */
/**
 * @defgroup at_apb_tsmc_efuse_128x8_regs_core_EFUSE_RDATA24 EFUSE_RDATA24
 * @brief efuse bytes 99-96 definitions.
 * @{
 */
#ifndef __EFUSE_EFUSE_RDATA24_MACRO__
#define __EFUSE_EFUSE_RDATA24_MACRO__

/* macros for field rdata */
/**
 * @defgroup at_apb_tsmc_efuse_128x8_regs_core_rdata_field rdata_field
 * @brief macros for field rdata
 * @{
 */
#define EFUSE_EFUSE_RDATA24__RDATA__SHIFT                                     0
#define EFUSE_EFUSE_RDATA24__RDATA__WIDTH                                    32
#define EFUSE_EFUSE_RDATA24__RDATA__MASK                            0xffffffffU
#define EFUSE_EFUSE_RDATA24__RDATA__READ(src)   ((uint32_t)(src) & 0xffffffffU)
#define EFUSE_EFUSE_RDATA24__RDATA__RESET_VALUE                     0x00000000U
/** @} */
#define EFUSE_EFUSE_RDATA24__TYPE                                      uint32_t
#define EFUSE_EFUSE_RDATA24__READ                                   0xffffffffU
#define EFUSE_EFUSE_RDATA24__PRESERVED                              0x00000000U
#define EFUSE_EFUSE_RDATA24__RESET_VALUE                            0x00000000U

#endif /* __EFUSE_EFUSE_RDATA24_MACRO__ */

/** @} end of EFUSE_RDATA24 */

/* macros for BlueprintGlobalNameSpace::EFUSE_EFUSE_RDATA25 */
/**
 * @defgroup at_apb_tsmc_efuse_128x8_regs_core_EFUSE_RDATA25 EFUSE_RDATA25
 * @brief efuse bytes 103-100 definitions.
 * @{
 */
#ifndef __EFUSE_EFUSE_RDATA25_MACRO__
#define __EFUSE_EFUSE_RDATA25_MACRO__

/* macros for field rdata */
/**
 * @defgroup at_apb_tsmc_efuse_128x8_regs_core_rdata_field rdata_field
 * @brief macros for field rdata
 * @{
 */
#define EFUSE_EFUSE_RDATA25__RDATA__SHIFT                                     0
#define EFUSE_EFUSE_RDATA25__RDATA__WIDTH                                    32
#define EFUSE_EFUSE_RDATA25__RDATA__MASK                            0xffffffffU
#define EFUSE_EFUSE_RDATA25__RDATA__READ(src)   ((uint32_t)(src) & 0xffffffffU)
#define EFUSE_EFUSE_RDATA25__RDATA__RESET_VALUE                     0x00000000U
/** @} */
#define EFUSE_EFUSE_RDATA25__TYPE                                      uint32_t
#define EFUSE_EFUSE_RDATA25__READ                                   0xffffffffU
#define EFUSE_EFUSE_RDATA25__PRESERVED                              0x00000000U
#define EFUSE_EFUSE_RDATA25__RESET_VALUE                            0x00000000U

#endif /* __EFUSE_EFUSE_RDATA25_MACRO__ */

/** @} end of EFUSE_RDATA25 */

/* macros for BlueprintGlobalNameSpace::EFUSE_EFUSE_RDATA26 */
/**
 * @defgroup at_apb_tsmc_efuse_128x8_regs_core_EFUSE_RDATA26 EFUSE_RDATA26
 * @brief efuse bytes 107-104 definitions.
 * @{
 */
#ifndef __EFUSE_EFUSE_RDATA26_MACRO__
#define __EFUSE_EFUSE_RDATA26_MACRO__

/* macros for field rdata */
/**
 * @defgroup at_apb_tsmc_efuse_128x8_regs_core_rdata_field rdata_field
 * @brief macros for field rdata
 * @{
 */
#define EFUSE_EFUSE_RDATA26__RDATA__SHIFT                                     0
#define EFUSE_EFUSE_RDATA26__RDATA__WIDTH                                    32
#define EFUSE_EFUSE_RDATA26__RDATA__MASK                            0xffffffffU
#define EFUSE_EFUSE_RDATA26__RDATA__READ(src)   ((uint32_t)(src) & 0xffffffffU)
#define EFUSE_EFUSE_RDATA26__RDATA__RESET_VALUE                     0x00000000U
/** @} */
#define EFUSE_EFUSE_RDATA26__TYPE                                      uint32_t
#define EFUSE_EFUSE_RDATA26__READ                                   0xffffffffU
#define EFUSE_EFUSE_RDATA26__PRESERVED                              0x00000000U
#define EFUSE_EFUSE_RDATA26__RESET_VALUE                            0x00000000U

#endif /* __EFUSE_EFUSE_RDATA26_MACRO__ */

/** @} end of EFUSE_RDATA26 */

/* macros for BlueprintGlobalNameSpace::EFUSE_EFUSE_RDATA27 */
/**
 * @defgroup at_apb_tsmc_efuse_128x8_regs_core_EFUSE_RDATA27 EFUSE_RDATA27
 * @brief efuse bytes 111-108 definitions.
 * @{
 */
#ifndef __EFUSE_EFUSE_RDATA27_MACRO__
#define __EFUSE_EFUSE_RDATA27_MACRO__

/* macros for field rdata */
/**
 * @defgroup at_apb_tsmc_efuse_128x8_regs_core_rdata_field rdata_field
 * @brief macros for field rdata
 * @{
 */
#define EFUSE_EFUSE_RDATA27__RDATA__SHIFT                                     0
#define EFUSE_EFUSE_RDATA27__RDATA__WIDTH                                    32
#define EFUSE_EFUSE_RDATA27__RDATA__MASK                            0xffffffffU
#define EFUSE_EFUSE_RDATA27__RDATA__READ(src)   ((uint32_t)(src) & 0xffffffffU)
#define EFUSE_EFUSE_RDATA27__RDATA__RESET_VALUE                     0x00000000U
/** @} */
#define EFUSE_EFUSE_RDATA27__TYPE                                      uint32_t
#define EFUSE_EFUSE_RDATA27__READ                                   0xffffffffU
#define EFUSE_EFUSE_RDATA27__PRESERVED                              0x00000000U
#define EFUSE_EFUSE_RDATA27__RESET_VALUE                            0x00000000U

#endif /* __EFUSE_EFUSE_RDATA27_MACRO__ */

/** @} end of EFUSE_RDATA27 */

/* macros for BlueprintGlobalNameSpace::EFUSE_EFUSE_RDATA28 */
/**
 * @defgroup at_apb_tsmc_efuse_128x8_regs_core_EFUSE_RDATA28 EFUSE_RDATA28
 * @brief efuse bytes 115-112 definitions.
 * @{
 */
#ifndef __EFUSE_EFUSE_RDATA28_MACRO__
#define __EFUSE_EFUSE_RDATA28_MACRO__

/* macros for field rdata */
/**
 * @defgroup at_apb_tsmc_efuse_128x8_regs_core_rdata_field rdata_field
 * @brief macros for field rdata
 * @{
 */
#define EFUSE_EFUSE_RDATA28__RDATA__SHIFT                                     0
#define EFUSE_EFUSE_RDATA28__RDATA__WIDTH                                    32
#define EFUSE_EFUSE_RDATA28__RDATA__MASK                            0xffffffffU
#define EFUSE_EFUSE_RDATA28__RDATA__READ(src)   ((uint32_t)(src) & 0xffffffffU)
#define EFUSE_EFUSE_RDATA28__RDATA__RESET_VALUE                     0x00000000U
/** @} */
#define EFUSE_EFUSE_RDATA28__TYPE                                      uint32_t
#define EFUSE_EFUSE_RDATA28__READ                                   0xffffffffU
#define EFUSE_EFUSE_RDATA28__PRESERVED                              0x00000000U
#define EFUSE_EFUSE_RDATA28__RESET_VALUE                            0x00000000U

#endif /* __EFUSE_EFUSE_RDATA28_MACRO__ */

/** @} end of EFUSE_RDATA28 */

/* macros for BlueprintGlobalNameSpace::EFUSE_EFUSE_RDATA29 */
/**
 * @defgroup at_apb_tsmc_efuse_128x8_regs_core_EFUSE_RDATA29 EFUSE_RDATA29
 * @brief efuse bytes 119-116 definitions.
 * @{
 */
#ifndef __EFUSE_EFUSE_RDATA29_MACRO__
#define __EFUSE_EFUSE_RDATA29_MACRO__

/* macros for field rdata */
/**
 * @defgroup at_apb_tsmc_efuse_128x8_regs_core_rdata_field rdata_field
 * @brief macros for field rdata
 * @{
 */
#define EFUSE_EFUSE_RDATA29__RDATA__SHIFT                                     0
#define EFUSE_EFUSE_RDATA29__RDATA__WIDTH                                    32
#define EFUSE_EFUSE_RDATA29__RDATA__MASK                            0xffffffffU
#define EFUSE_EFUSE_RDATA29__RDATA__READ(src)   ((uint32_t)(src) & 0xffffffffU)
#define EFUSE_EFUSE_RDATA29__RDATA__RESET_VALUE                     0x00000000U
/** @} */
#define EFUSE_EFUSE_RDATA29__TYPE                                      uint32_t
#define EFUSE_EFUSE_RDATA29__READ                                   0xffffffffU
#define EFUSE_EFUSE_RDATA29__PRESERVED                              0x00000000U
#define EFUSE_EFUSE_RDATA29__RESET_VALUE                            0x00000000U

#endif /* __EFUSE_EFUSE_RDATA29_MACRO__ */

/** @} end of EFUSE_RDATA29 */

/* macros for BlueprintGlobalNameSpace::EFUSE_EFUSE_RDATA30 */
/**
 * @defgroup at_apb_tsmc_efuse_128x8_regs_core_EFUSE_RDATA30 EFUSE_RDATA30
 * @brief efuse bytes 123-120 definitions.
 * @{
 */
#ifndef __EFUSE_EFUSE_RDATA30_MACRO__
#define __EFUSE_EFUSE_RDATA30_MACRO__

/* macros for field rdata */
/**
 * @defgroup at_apb_tsmc_efuse_128x8_regs_core_rdata_field rdata_field
 * @brief macros for field rdata
 * @{
 */
#define EFUSE_EFUSE_RDATA30__RDATA__SHIFT                                     0
#define EFUSE_EFUSE_RDATA30__RDATA__WIDTH                                    32
#define EFUSE_EFUSE_RDATA30__RDATA__MASK                            0xffffffffU
#define EFUSE_EFUSE_RDATA30__RDATA__READ(src)   ((uint32_t)(src) & 0xffffffffU)
#define EFUSE_EFUSE_RDATA30__RDATA__RESET_VALUE                     0x00000000U
/** @} */
#define EFUSE_EFUSE_RDATA30__TYPE                                      uint32_t
#define EFUSE_EFUSE_RDATA30__READ                                   0xffffffffU
#define EFUSE_EFUSE_RDATA30__PRESERVED                              0x00000000U
#define EFUSE_EFUSE_RDATA30__RESET_VALUE                            0x00000000U

#endif /* __EFUSE_EFUSE_RDATA30_MACRO__ */

/** @} end of EFUSE_RDATA30 */

/* macros for BlueprintGlobalNameSpace::EFUSE_EFUSE_RDATA31 */
/**
 * @defgroup at_apb_tsmc_efuse_128x8_regs_core_EFUSE_RDATA31 EFUSE_RDATA31
 * @brief efuse bytes 127-124 definitions.
 * @{
 */
#ifndef __EFUSE_EFUSE_RDATA31_MACRO__
#define __EFUSE_EFUSE_RDATA31_MACRO__

/* macros for field rdata */
/**
 * @defgroup at_apb_tsmc_efuse_128x8_regs_core_rdata_field rdata_field
 * @brief macros for field rdata
 * @{
 */
#define EFUSE_EFUSE_RDATA31__RDATA__SHIFT                                     0
#define EFUSE_EFUSE_RDATA31__RDATA__WIDTH                                    32
#define EFUSE_EFUSE_RDATA31__RDATA__MASK                            0xffffffffU
#define EFUSE_EFUSE_RDATA31__RDATA__READ(src)   ((uint32_t)(src) & 0xffffffffU)
#define EFUSE_EFUSE_RDATA31__RDATA__RESET_VALUE                     0x00000000U
/** @} */
#define EFUSE_EFUSE_RDATA31__TYPE                                      uint32_t
#define EFUSE_EFUSE_RDATA31__READ                                   0xffffffffU
#define EFUSE_EFUSE_RDATA31__PRESERVED                              0x00000000U
#define EFUSE_EFUSE_RDATA31__RESET_VALUE                            0x00000000U

#endif /* __EFUSE_EFUSE_RDATA31_MACRO__ */

/** @} end of EFUSE_RDATA31 */

/* macros for BlueprintGlobalNameSpace::EFUSE_opmode */
/**
 * @defgroup at_apb_tsmc_efuse_128x8_regs_core_opmode opmode
 * @brief efuse program control definitions.
 * @{
 */
#ifndef __EFUSE_OPMODE_MACRO__
#define __EFUSE_OPMODE_MACRO__

/* macros for field wadr */
/**
 * @defgroup at_apb_tsmc_efuse_128x8_regs_core_wadr_field wadr_field
 * @brief macros for field wadr
 * @details efuse programming address
 * @{
 */
#define EFUSE_OPMODE__WADR__SHIFT                                             0
#define EFUSE_OPMODE__WADR__WIDTH                                             5
#define EFUSE_OPMODE__WADR__MASK                                    0x0000001fU
#define EFUSE_OPMODE__WADR__READ(src)           ((uint32_t)(src) & 0x0000001fU)
#define EFUSE_OPMODE__WADR__WRITE(src)          ((uint32_t)(src) & 0x0000001fU)
#define EFUSE_OPMODE__WADR__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000001fU) | ((uint32_t)(src) &\
                    0x0000001fU)
#define EFUSE_OPMODE__WADR__VERIFY(src)   (!(((uint32_t)(src) & ~0x0000001fU)))
#define EFUSE_OPMODE__WADR__RESET_VALUE                             0x00000000U
/** @} */

/* macros for field go */
/**
 * @defgroup at_apb_tsmc_efuse_128x8_regs_core_go_field go_field
 * @brief macros for field go
 * @details opcode start when rising edge on 'go' is detected. self-clearing
 * @{
 */
#define EFUSE_OPMODE__GO__SHIFT                                              31
#define EFUSE_OPMODE__GO__WIDTH                                               1
#define EFUSE_OPMODE__GO__MASK                                      0x80000000U
#define EFUSE_OPMODE__GO__READ(src)     (((uint32_t)(src) & 0x80000000U) >> 31)
#define EFUSE_OPMODE__GO__WRITE(src)    (((uint32_t)(src) << 31) & 0x80000000U)
#define EFUSE_OPMODE__GO__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | (((uint32_t)(src) <<\
                    31) & 0x80000000U)
#define EFUSE_OPMODE__GO__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 31) & ~0x80000000U)))
#define EFUSE_OPMODE__GO__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(1) << 31)
#define EFUSE_OPMODE__GO__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(0) << 31)
#define EFUSE_OPMODE__GO__RESET_VALUE                               0x00000000U
/** @} */
#define EFUSE_OPMODE__TYPE                                             uint32_t
#define EFUSE_OPMODE__READ                                          0x8000001fU
#define EFUSE_OPMODE__WRITE                                         0x8000001fU
#define EFUSE_OPMODE__PRESERVED                                     0x00000000U
#define EFUSE_OPMODE__RESET_VALUE                                   0x00000000U

#endif /* __EFUSE_OPMODE_MACRO__ */

/** @} end of opmode */

/* macros for BlueprintGlobalNameSpace::EFUSE_EFUSE_WDATA */
/**
 * @defgroup at_apb_tsmc_efuse_128x8_regs_core_EFUSE_WDATA EFUSE_WDATA
 * @brief efuse write data definitions.
 * @{
 */
#ifndef __EFUSE_EFUSE_WDATA_MACRO__
#define __EFUSE_EFUSE_WDATA_MACRO__

/* macros for field wdata */
/**
 * @defgroup at_apb_tsmc_efuse_128x8_regs_core_wdata_field wdata_field
 * @brief macros for field wdata
 * @details for bits in wdata = 1, efuse A = { wadr, effset of wdata } will be programmed.
 * @{
 */
#define EFUSE_EFUSE_WDATA__WDATA__SHIFT                                       0
#define EFUSE_EFUSE_WDATA__WDATA__WIDTH                                      32
#define EFUSE_EFUSE_WDATA__WDATA__MASK                              0xffffffffU
#define EFUSE_EFUSE_WDATA__WDATA__READ(src)     ((uint32_t)(src) & 0xffffffffU)
#define EFUSE_EFUSE_WDATA__WDATA__WRITE(src)    ((uint32_t)(src) & 0xffffffffU)
#define EFUSE_EFUSE_WDATA__WDATA__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0xffffffffU) | ((uint32_t)(src) &\
                    0xffffffffU)
#define EFUSE_EFUSE_WDATA__WDATA__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0xffffffffU)))
#define EFUSE_EFUSE_WDATA__WDATA__RESET_VALUE                       0x00000000U
/** @} */
#define EFUSE_EFUSE_WDATA__TYPE                                        uint32_t
#define EFUSE_EFUSE_WDATA__READ                                     0xffffffffU
#define EFUSE_EFUSE_WDATA__WRITE                                    0xffffffffU
#define EFUSE_EFUSE_WDATA__PRESERVED                                0x00000000U
#define EFUSE_EFUSE_WDATA__RESET_VALUE                              0x00000000U

#endif /* __EFUSE_EFUSE_WDATA_MACRO__ */

/** @} end of EFUSE_WDATA */

/* macros for BlueprintGlobalNameSpace::EFUSE_status */
/**
 * @defgroup at_apb_tsmc_efuse_128x8_regs_core_status status
 * @brief efuse programming status definitions.
 * @{
 */
#ifndef __EFUSE_STATUS_MACRO__
#define __EFUSE_STATUS_MACRO__

/* macros for field done */
/**
 * @defgroup at_apb_tsmc_efuse_128x8_regs_core_done_field done_field
 * @brief macros for field done
 * @details program done
 * @{
 */
#define EFUSE_STATUS__DONE__SHIFT                                             0
#define EFUSE_STATUS__DONE__WIDTH                                             1
#define EFUSE_STATUS__DONE__MASK                                    0x00000001U
#define EFUSE_STATUS__DONE__READ(src)           ((uint32_t)(src) & 0x00000001U)
#define EFUSE_STATUS__DONE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define EFUSE_STATUS__DONE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define EFUSE_STATUS__DONE__RESET_VALUE                             0x00000000U
/** @} */

/* macros for field running */
/**
 * @defgroup at_apb_tsmc_efuse_128x8_regs_core_running_field running_field
 * @brief macros for field running
 * @details program running
 * @{
 */
#define EFUSE_STATUS__RUNNING__SHIFT                                         31
#define EFUSE_STATUS__RUNNING__WIDTH                                          1
#define EFUSE_STATUS__RUNNING__MASK                                 0x80000000U
#define EFUSE_STATUS__RUNNING__READ(src) \
                    (((uint32_t)(src)\
                    & 0x80000000U) >> 31)
#define EFUSE_STATUS__RUNNING__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(1) << 31)
#define EFUSE_STATUS__RUNNING__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(0) << 31)
#define EFUSE_STATUS__RUNNING__RESET_VALUE                          0x00000000U
/** @} */
#define EFUSE_STATUS__TYPE                                             uint32_t
#define EFUSE_STATUS__READ                                          0x80000001U
#define EFUSE_STATUS__PRESERVED                                     0x00000000U
#define EFUSE_STATUS__RESET_VALUE                                   0x00000000U

#endif /* __EFUSE_STATUS_MACRO__ */

/** @} end of status */

/* macros for BlueprintGlobalNameSpace::EFUSE_t_pgm_strobe */
/**
 * @defgroup at_apb_tsmc_efuse_128x8_regs_core_t_pgm_strobe t_pgm_strobe
 * @brief STROBE width for program definitions.
 * @{
 */
#ifndef __EFUSE_T_PGM_STROBE_MACRO__
#define __EFUSE_T_PGM_STROBE_MACRO__

/* macros for field cycle */
/**
 * @defgroup at_apb_tsmc_efuse_128x8_regs_core_cycle_field cycle_field
 * @brief macros for field cycle
 * @details program strobe width 10000ns, for 16Mhz , cycle = 159
 * @{
 */
#define EFUSE_T_PGM_STROBE__CYCLE__SHIFT                                      0
#define EFUSE_T_PGM_STROBE__CYCLE__WIDTH                                     11
#define EFUSE_T_PGM_STROBE__CYCLE__MASK                             0x000007ffU
#define EFUSE_T_PGM_STROBE__CYCLE__READ(src)    ((uint32_t)(src) & 0x000007ffU)
#define EFUSE_T_PGM_STROBE__CYCLE__WRITE(src)   ((uint32_t)(src) & 0x000007ffU)
#define EFUSE_T_PGM_STROBE__CYCLE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000007ffU) | ((uint32_t)(src) &\
                    0x000007ffU)
#define EFUSE_T_PGM_STROBE__CYCLE__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x000007ffU)))
#define EFUSE_T_PGM_STROBE__CYCLE__RESET_VALUE                      0x0000009fU
/** @} */
#define EFUSE_T_PGM_STROBE__TYPE                                       uint32_t
#define EFUSE_T_PGM_STROBE__READ                                    0x000007ffU
#define EFUSE_T_PGM_STROBE__WRITE                                   0x000007ffU
#define EFUSE_T_PGM_STROBE__PRESERVED                               0x00000000U
#define EFUSE_T_PGM_STROBE__RESET_VALUE                             0x0000009fU

#endif /* __EFUSE_T_PGM_STROBE_MACRO__ */

/** @} end of t_pgm_strobe */

/* macros for BlueprintGlobalNameSpace::EFUSE_t_rd_strobe */
/**
 * @defgroup at_apb_tsmc_efuse_128x8_regs_core_t_rd_strobe t_rd_strobe
 * @brief STROBW width for read definitions.
 * @{
 */
#ifndef __EFUSE_T_RD_STROBE_MACRO__
#define __EFUSE_T_RD_STROBE_MACRO__

/* macros for field cycle */
/**
 * @defgroup at_apb_tsmc_efuse_128x8_regs_core_cycle_field cycle_field
 * @brief macros for field cycle
 * @details read strobe width 46ns, for 16 MHz , cycle = 1
 * @{
 */
#define EFUSE_T_RD_STROBE__CYCLE__SHIFT                                       0
#define EFUSE_T_RD_STROBE__CYCLE__WIDTH                                       4
#define EFUSE_T_RD_STROBE__CYCLE__MASK                              0x0000000fU
#define EFUSE_T_RD_STROBE__CYCLE__READ(src)     ((uint32_t)(src) & 0x0000000fU)
#define EFUSE_T_RD_STROBE__CYCLE__WRITE(src)    ((uint32_t)(src) & 0x0000000fU)
#define EFUSE_T_RD_STROBE__CYCLE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000000fU) | ((uint32_t)(src) &\
                    0x0000000fU)
#define EFUSE_T_RD_STROBE__CYCLE__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000000fU)))
#define EFUSE_T_RD_STROBE__CYCLE__RESET_VALUE                       0x00000001U
/** @} */
#define EFUSE_T_RD_STROBE__TYPE                                        uint32_t
#define EFUSE_T_RD_STROBE__READ                                     0x0000000fU
#define EFUSE_T_RD_STROBE__WRITE                                    0x0000000fU
#define EFUSE_T_RD_STROBE__PRESERVED                                0x00000000U
#define EFUSE_T_RD_STROBE__RESET_VALUE                              0x00000001U

#endif /* __EFUSE_T_RD_STROBE_MACRO__ */

/** @} end of t_rd_strobe */

/* macros for BlueprintGlobalNameSpace::EFUSE_t_pgm_mode */
/**
 * @defgroup at_apb_tsmc_efuse_128x8_regs_core_t_pgm_mode t_pgm_mode
 * @brief PGM mode PGENB to STRONE setup/hold time for program mode definitions.
 * @{
 */
#ifndef __EFUSE_T_PGM_MODE_MACRO__
#define __EFUSE_T_PGM_MODE_MACRO__

/* macros for field hold2 */
/**
 * @defgroup at_apb_tsmc_efuse_128x8_regs_core_hold2_field hold2_field
 * @brief macros for field hold2
 * @details clock cycle * ( N +1 ), max hold time of VDDQ, CSB, A, LOAD to STROBE
 * @{
 */
#define EFUSE_T_PGM_MODE__HOLD2__SHIFT                                        0
#define EFUSE_T_PGM_MODE__HOLD2__WIDTH                                        2
#define EFUSE_T_PGM_MODE__HOLD2__MASK                               0x00000003U
#define EFUSE_T_PGM_MODE__HOLD2__READ(src)      ((uint32_t)(src) & 0x00000003U)
#define EFUSE_T_PGM_MODE__HOLD2__WRITE(src)     ((uint32_t)(src) & 0x00000003U)
#define EFUSE_T_PGM_MODE__HOLD2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000003U) | ((uint32_t)(src) &\
                    0x00000003U)
#define EFUSE_T_PGM_MODE__HOLD2__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000003U)))
#define EFUSE_T_PGM_MODE__HOLD2__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field hold1 */
/**
 * @defgroup at_apb_tsmc_efuse_128x8_regs_core_hold1_field hold1_field
 * @brief macros for field hold1
 * @details clock cycle * ( N +1 ), hold time from PGENB to VDDQ
 * @{
 */
#define EFUSE_T_PGM_MODE__HOLD1__SHIFT                                        8
#define EFUSE_T_PGM_MODE__HOLD1__WIDTH                                        2
#define EFUSE_T_PGM_MODE__HOLD1__MASK                               0x00000300U
#define EFUSE_T_PGM_MODE__HOLD1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000300U) >> 8)
#define EFUSE_T_PGM_MODE__HOLD1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00000300U)
#define EFUSE_T_PGM_MODE__HOLD1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000300U) | (((uint32_t)(src) <<\
                    8) & 0x00000300U)
#define EFUSE_T_PGM_MODE__HOLD1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00000300U)))
#define EFUSE_T_PGM_MODE__HOLD1__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field setup2 */
/**
 * @defgroup at_apb_tsmc_efuse_128x8_regs_core_setup2_field setup2_field
 * @brief macros for field setup2
 * @details clock cycle * ( N +1 ), max setup time of VDDQ, CSB, A, LOAD to STROBE
 * @{
 */
#define EFUSE_T_PGM_MODE__SETUP2__SHIFT                                      16
#define EFUSE_T_PGM_MODE__SETUP2__WIDTH                                       2
#define EFUSE_T_PGM_MODE__SETUP2__MASK                              0x00030000U
#define EFUSE_T_PGM_MODE__SETUP2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00030000U) >> 16)
#define EFUSE_T_PGM_MODE__SETUP2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x00030000U)
#define EFUSE_T_PGM_MODE__SETUP2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00030000U) | (((uint32_t)(src) <<\
                    16) & 0x00030000U)
#define EFUSE_T_PGM_MODE__SETUP2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x00030000U)))
#define EFUSE_T_PGM_MODE__SETUP2__RESET_VALUE                       0x00000000U
/** @} */

/* macros for field setup1 */
/**
 * @defgroup at_apb_tsmc_efuse_128x8_regs_core_setup1_field setup1_field
 * @brief macros for field setup1
 * @details clock cycle * ( N +1 ), setup time from PGENB to VDDQ
 * @{
 */
#define EFUSE_T_PGM_MODE__SETUP1__SHIFT                                      24
#define EFUSE_T_PGM_MODE__SETUP1__WIDTH                                       2
#define EFUSE_T_PGM_MODE__SETUP1__MASK                              0x03000000U
#define EFUSE_T_PGM_MODE__SETUP1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x03000000U) >> 24)
#define EFUSE_T_PGM_MODE__SETUP1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x03000000U)
#define EFUSE_T_PGM_MODE__SETUP1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x03000000U) | (((uint32_t)(src) <<\
                    24) & 0x03000000U)
#define EFUSE_T_PGM_MODE__SETUP1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x03000000U)))
#define EFUSE_T_PGM_MODE__SETUP1__RESET_VALUE                       0x00000000U
/** @} */
#define EFUSE_T_PGM_MODE__TYPE                                         uint32_t
#define EFUSE_T_PGM_MODE__READ                                      0x03030303U
#define EFUSE_T_PGM_MODE__WRITE                                     0x03030303U
#define EFUSE_T_PGM_MODE__PRESERVED                                 0x00000000U
#define EFUSE_T_PGM_MODE__RESET_VALUE                               0x00000000U

#endif /* __EFUSE_T_PGM_MODE_MACRO__ */

/** @} end of t_pgm_mode */

/* macros for BlueprintGlobalNameSpace::EFUSE_t_rd_mode */
/**
 * @defgroup at_apb_tsmc_efuse_128x8_regs_core_t_rd_mode t_rd_mode
 * @brief READ mode timing definitions.
 * @{
 */
#ifndef __EFUSE_T_RD_MODE_MACRO__
#define __EFUSE_T_RD_MODE_MACRO__

/* macros for field hold2 */
/**
 * @defgroup at_apb_tsmc_efuse_128x8_regs_core_hold2_field hold2_field
 * @brief macros for field hold2
 * @details clock cycle * ( N +1 ), max hold time of PGENB, CSB, A, LOAD to STROBE
 * @{
 */
#define EFUSE_T_RD_MODE__HOLD2__SHIFT                                         0
#define EFUSE_T_RD_MODE__HOLD2__WIDTH                                         2
#define EFUSE_T_RD_MODE__HOLD2__MASK                                0x00000003U
#define EFUSE_T_RD_MODE__HOLD2__READ(src)       ((uint32_t)(src) & 0x00000003U)
#define EFUSE_T_RD_MODE__HOLD2__WRITE(src)      ((uint32_t)(src) & 0x00000003U)
#define EFUSE_T_RD_MODE__HOLD2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000003U) | ((uint32_t)(src) &\
                    0x00000003U)
#define EFUSE_T_RD_MODE__HOLD2__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000003U)))
#define EFUSE_T_RD_MODE__HOLD2__RESET_VALUE                         0x00000000U
/** @} */

/* macros for field hold1 */
/**
 * @defgroup at_apb_tsmc_efuse_128x8_regs_core_hold1_field hold1_field
 * @brief macros for field hold1
 * @details clock cycle * ( N +1 ), hold time from VDDQ to PGENB
 * @{
 */
#define EFUSE_T_RD_MODE__HOLD1__SHIFT                                         8
#define EFUSE_T_RD_MODE__HOLD1__WIDTH                                         2
#define EFUSE_T_RD_MODE__HOLD1__MASK                                0x00000300U
#define EFUSE_T_RD_MODE__HOLD1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000300U) >> 8)
#define EFUSE_T_RD_MODE__HOLD1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00000300U)
#define EFUSE_T_RD_MODE__HOLD1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000300U) | (((uint32_t)(src) <<\
                    8) & 0x00000300U)
#define EFUSE_T_RD_MODE__HOLD1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00000300U)))
#define EFUSE_T_RD_MODE__HOLD1__RESET_VALUE                         0x00000000U
/** @} */

/* macros for field setup2 */
/**
 * @defgroup at_apb_tsmc_efuse_128x8_regs_core_setup2_field setup2_field
 * @brief macros for field setup2
 * @details clock cycle * ( N +1 ), max setup time of PGENB, CSB, A, LOAD to STROBE
 * @{
 */
#define EFUSE_T_RD_MODE__SETUP2__SHIFT                                       16
#define EFUSE_T_RD_MODE__SETUP2__WIDTH                                        2
#define EFUSE_T_RD_MODE__SETUP2__MASK                               0x00030000U
#define EFUSE_T_RD_MODE__SETUP2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00030000U) >> 16)
#define EFUSE_T_RD_MODE__SETUP2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x00030000U)
#define EFUSE_T_RD_MODE__SETUP2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00030000U) | (((uint32_t)(src) <<\
                    16) & 0x00030000U)
#define EFUSE_T_RD_MODE__SETUP2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x00030000U)))
#define EFUSE_T_RD_MODE__SETUP2__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field setup1 */
/**
 * @defgroup at_apb_tsmc_efuse_128x8_regs_core_setup1_field setup1_field
 * @brief macros for field setup1
 * @details clock cycle * ( N +1 ), setup time from VDDQ to PGENB
 * @{
 */
#define EFUSE_T_RD_MODE__SETUP1__SHIFT                                       24
#define EFUSE_T_RD_MODE__SETUP1__WIDTH                                        2
#define EFUSE_T_RD_MODE__SETUP1__MASK                               0x03000000U
#define EFUSE_T_RD_MODE__SETUP1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x03000000U) >> 24)
#define EFUSE_T_RD_MODE__SETUP1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x03000000U)
#define EFUSE_T_RD_MODE__SETUP1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x03000000U) | (((uint32_t)(src) <<\
                    24) & 0x03000000U)
#define EFUSE_T_RD_MODE__SETUP1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x03000000U)))
#define EFUSE_T_RD_MODE__SETUP1__RESET_VALUE                        0x00000000U
/** @} */
#define EFUSE_T_RD_MODE__TYPE                                          uint32_t
#define EFUSE_T_RD_MODE__READ                                       0x03030303U
#define EFUSE_T_RD_MODE__WRITE                                      0x03030303U
#define EFUSE_T_RD_MODE__PRESERVED                                  0x00000000U
#define EFUSE_T_RD_MODE__RESET_VALUE                                0x00000000U

#endif /* __EFUSE_T_RD_MODE_MACRO__ */

/** @} end of t_rd_mode */

/* macros for BlueprintGlobalNameSpace::EFUSE_interrupt_status */
/**
 * @defgroup at_apb_tsmc_efuse_128x8_regs_core_interrupt_status interrupt_status
 * @brief Contains register fields associated with interrupt_status. definitions.
 * @{
 */
#ifndef __EFUSE_INTERRUPT_STATUS_MACRO__
#define __EFUSE_INTERRUPT_STATUS_MACRO__

/* macros for field intrpt0 */
/**
 * @defgroup at_apb_tsmc_efuse_128x8_regs_core_intrpt0_field intrpt0_field
 * @brief macros for field intrpt0
 * @details saw a rising edge on program done; independent of mask
 * @{
 */
#define EFUSE_INTERRUPT_STATUS__INTRPT0__SHIFT                                0
#define EFUSE_INTERRUPT_STATUS__INTRPT0__WIDTH                                1
#define EFUSE_INTERRUPT_STATUS__INTRPT0__MASK                       0x00000001U
#define EFUSE_INTERRUPT_STATUS__INTRPT0__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define EFUSE_INTERRUPT_STATUS__INTRPT0__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define EFUSE_INTERRUPT_STATUS__INTRPT0__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define EFUSE_INTERRUPT_STATUS__INTRPT0__RESET_VALUE                0x00000000U
/** @} */
#define EFUSE_INTERRUPT_STATUS__TYPE                                   uint32_t
#define EFUSE_INTERRUPT_STATUS__READ                                0x00000001U
#define EFUSE_INTERRUPT_STATUS__PRESERVED                           0x00000000U
#define EFUSE_INTERRUPT_STATUS__RESET_VALUE                         0x00000000U

#endif /* __EFUSE_INTERRUPT_STATUS_MACRO__ */

/** @} end of interrupt_status */

/* macros for BlueprintGlobalNameSpace::EFUSE_interrupt_mask */
/**
 * @defgroup at_apb_tsmc_efuse_128x8_regs_core_interrupt_mask interrupt_mask
 * @brief Contains register fields associated with interrupt_mask. definitions.
 * @{
 */
#ifndef __EFUSE_INTERRUPT_MASK_MACRO__
#define __EFUSE_INTERRUPT_MASK_MACRO__

/* macros for field intrpt0 */
/**
 * @defgroup at_apb_tsmc_efuse_128x8_regs_core_intrpt0_field intrpt0_field
 * @brief macros for field intrpt0
 * @details 1=allow intrpt0 to be OR'ed into core interrupt
 * @{
 */
#define EFUSE_INTERRUPT_MASK__INTRPT0__SHIFT                                  0
#define EFUSE_INTERRUPT_MASK__INTRPT0__WIDTH                                  1
#define EFUSE_INTERRUPT_MASK__INTRPT0__MASK                         0x00000001U
#define EFUSE_INTERRUPT_MASK__INTRPT0__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define EFUSE_INTERRUPT_MASK__INTRPT0__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define EFUSE_INTERRUPT_MASK__INTRPT0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define EFUSE_INTERRUPT_MASK__INTRPT0__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define EFUSE_INTERRUPT_MASK__INTRPT0__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define EFUSE_INTERRUPT_MASK__INTRPT0__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define EFUSE_INTERRUPT_MASK__INTRPT0__RESET_VALUE                  0x00000000U
/** @} */
#define EFUSE_INTERRUPT_MASK__TYPE                                     uint32_t
#define EFUSE_INTERRUPT_MASK__READ                                  0x00000001U
#define EFUSE_INTERRUPT_MASK__WRITE                                 0x00000001U
#define EFUSE_INTERRUPT_MASK__PRESERVED                             0x00000000U
#define EFUSE_INTERRUPT_MASK__RESET_VALUE                           0x00000000U

#endif /* __EFUSE_INTERRUPT_MASK_MACRO__ */

/** @} end of interrupt_mask */

/* macros for BlueprintGlobalNameSpace::EFUSE_interrupt_set */
/**
 * @defgroup at_apb_tsmc_efuse_128x8_regs_core_interrupt_set interrupt_set
 * @brief Contains register fields associated with interrupt_set. definitions.
 * @{
 */
#ifndef __EFUSE_INTERRUPT_SET_MACRO__
#define __EFUSE_INTERRUPT_SET_MACRO__

/* macros for field intrpt0 */
/**
 * @defgroup at_apb_tsmc_efuse_128x8_regs_core_intrpt0_field intrpt0_field
 * @brief macros for field intrpt0
 * @details (__SELF_CLEARING__)
 * @{
 */
#define EFUSE_INTERRUPT_SET__INTRPT0__SHIFT                                   0
#define EFUSE_INTERRUPT_SET__INTRPT0__WIDTH                                   1
#define EFUSE_INTERRUPT_SET__INTRPT0__MASK                          0x00000001U
#define EFUSE_INTERRUPT_SET__INTRPT0__READ(src) ((uint32_t)(src) & 0x00000001U)
#define EFUSE_INTERRUPT_SET__INTRPT0__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define EFUSE_INTERRUPT_SET__INTRPT0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define EFUSE_INTERRUPT_SET__INTRPT0__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define EFUSE_INTERRUPT_SET__INTRPT0__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define EFUSE_INTERRUPT_SET__INTRPT0__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define EFUSE_INTERRUPT_SET__INTRPT0__RESET_VALUE                   0x00000000U
/** @} */
#define EFUSE_INTERRUPT_SET__TYPE                                      uint32_t
#define EFUSE_INTERRUPT_SET__READ                                   0x00000001U
#define EFUSE_INTERRUPT_SET__WRITE                                  0x00000001U
#define EFUSE_INTERRUPT_SET__PRESERVED                              0x00000000U
#define EFUSE_INTERRUPT_SET__RESET_VALUE                            0x00000000U

#endif /* __EFUSE_INTERRUPT_SET_MACRO__ */

/** @} end of interrupt_set */

/* macros for BlueprintGlobalNameSpace::EFUSE_interrupt_reset */
/**
 * @defgroup at_apb_tsmc_efuse_128x8_regs_core_interrupt_reset interrupt_reset
 * @brief Contains register fields associated with interrupt_reset. definitions.
 * @{
 */
#ifndef __EFUSE_INTERRUPT_RESET_MACRO__
#define __EFUSE_INTERRUPT_RESET_MACRO__

/* macros for field intrpt0 */
/**
 * @defgroup at_apb_tsmc_efuse_128x8_regs_core_intrpt0_field intrpt0_field
 * @brief macros for field intrpt0
 * @details (__SELF_CLEARING__)
 * @{
 */
#define EFUSE_INTERRUPT_RESET__INTRPT0__SHIFT                                 0
#define EFUSE_INTERRUPT_RESET__INTRPT0__WIDTH                                 1
#define EFUSE_INTERRUPT_RESET__INTRPT0__MASK                        0x00000001U
#define EFUSE_INTERRUPT_RESET__INTRPT0__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define EFUSE_INTERRUPT_RESET__INTRPT0__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define EFUSE_INTERRUPT_RESET__INTRPT0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define EFUSE_INTERRUPT_RESET__INTRPT0__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define EFUSE_INTERRUPT_RESET__INTRPT0__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define EFUSE_INTERRUPT_RESET__INTRPT0__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define EFUSE_INTERRUPT_RESET__INTRPT0__RESET_VALUE                 0x00000000U
/** @} */
#define EFUSE_INTERRUPT_RESET__TYPE                                    uint32_t
#define EFUSE_INTERRUPT_RESET__READ                                 0x00000001U
#define EFUSE_INTERRUPT_RESET__WRITE                                0x00000001U
#define EFUSE_INTERRUPT_RESET__PRESERVED                            0x00000000U
#define EFUSE_INTERRUPT_RESET__RESET_VALUE                          0x00000000U

#endif /* __EFUSE_INTERRUPT_RESET_MACRO__ */

/** @} end of interrupt_reset */

/* macros for BlueprintGlobalNameSpace::EFUSE_core_id */
/**
 * @defgroup at_apb_tsmc_efuse_128x8_regs_core_core_id core_id
 * @brief CORE ID definitions.
 * @{
 */
#ifndef __EFUSE_CORE_ID_MACRO__
#define __EFUSE_CORE_ID_MACRO__

/* macros for field id */
/**
 * @defgroup at_apb_tsmc_efuse_128x8_regs_core_id_field id_field
 * @brief macros for field id
 * @details NVM in ASCII
 * @{
 */
#define EFUSE_CORE_ID__ID__SHIFT                                              0
#define EFUSE_CORE_ID__ID__WIDTH                                             32
#define EFUSE_CORE_ID__ID__MASK                                     0xffffffffU
#define EFUSE_CORE_ID__ID__READ(src)            ((uint32_t)(src) & 0xffffffffU)
#define EFUSE_CORE_ID__ID__RESET_VALUE                              0x4e564d20U
/** @} */
#define EFUSE_CORE_ID__TYPE                                            uint32_t
#define EFUSE_CORE_ID__READ                                         0xffffffffU
#define EFUSE_CORE_ID__PRESERVED                                    0x00000000U
#define EFUSE_CORE_ID__RESET_VALUE                                  0x4e564d20U

#endif /* __EFUSE_CORE_ID_MACRO__ */

/** @} end of core_id */

/* macros for BlueprintGlobalNameSpace::EFUSE_rev_hash */
/**
 * @defgroup at_apb_tsmc_efuse_128x8_regs_core_rev_hash rev_hash
 * @brief Contains register fields associated with rev_hash. definitions.
 * @{
 */
#ifndef __EFUSE_REV_HASH_MACRO__
#define __EFUSE_REV_HASH_MACRO__

/* macros for field id */
/**
 * @defgroup at_apb_tsmc_efuse_128x8_regs_core_id_field id_field
 * @brief macros for field id
 * @details crc32 of this document; don't change value to anything other than 32'h00000000; scripts will fill it out in the verilog
 * @{
 */
#define EFUSE_REV_HASH__ID__SHIFT                                             0
#define EFUSE_REV_HASH__ID__WIDTH                                            32
#define EFUSE_REV_HASH__ID__MASK                                    0xffffffffU
#define EFUSE_REV_HASH__ID__READ(src)           ((uint32_t)(src) & 0xffffffffU)
#define EFUSE_REV_HASH__ID__RESET_VALUE                             0x83b42913U
/** @} */
#define EFUSE_REV_HASH__TYPE                                           uint32_t
#define EFUSE_REV_HASH__READ                                        0xffffffffU
#define EFUSE_REV_HASH__PRESERVED                                   0x00000000U
#define EFUSE_REV_HASH__RESET_VALUE                                 0x83b42913U

#endif /* __EFUSE_REV_HASH_MACRO__ */

/** @} end of rev_hash */

/* macros for BlueprintGlobalNameSpace::EFUSE_rev_key */
/**
 * @defgroup at_apb_tsmc_efuse_128x8_regs_core_rev_key rev_key
 * @brief Contains register fields associated with rev_key. definitions.
 * @{
 */
#ifndef __EFUSE_REV_KEY_MACRO__
#define __EFUSE_REV_KEY_MACRO__

/* macros for field id */
/**
 * @defgroup at_apb_tsmc_efuse_128x8_regs_core_id_field id_field
 * @brief macros for field id
 * @details REV in ASCII
 * @{
 */
#define EFUSE_REV_KEY__ID__SHIFT                                              0
#define EFUSE_REV_KEY__ID__WIDTH                                             32
#define EFUSE_REV_KEY__ID__MASK                                     0xffffffffU
#define EFUSE_REV_KEY__ID__READ(src)            ((uint32_t)(src) & 0xffffffffU)
#define EFUSE_REV_KEY__ID__RESET_VALUE                              0x52455620U
/** @} */
#define EFUSE_REV_KEY__TYPE                                            uint32_t
#define EFUSE_REV_KEY__READ                                         0xffffffffU
#define EFUSE_REV_KEY__PRESERVED                                    0x00000000U
#define EFUSE_REV_KEY__RESET_VALUE                                  0x52455620U

#endif /* __EFUSE_REV_KEY_MACRO__ */

/** @} end of rev_key */

/** @} end of AT_APB_TSMC_EFUSE_128X8_REGS_CORE */
#endif /* __REG_AT_APB_TSMC_EFUSE_128X8_REGS_CORE_H__ */
