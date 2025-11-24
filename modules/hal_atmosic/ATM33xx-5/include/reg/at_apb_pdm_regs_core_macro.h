/*                                                                           */
/* File:       at_apb_pdm_regs_core_macro.h                                  */
/*                                                                           */
/* Arguments:  /cad/tools/cadence/blueprint_3.7.5/Linux-64bit/blueprint -eval*/
/*             $DEFINE_PROPERTY=1; -ansic at_apb_pdm_regs_core.rdl           */
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


#ifndef __REG_AT_APB_PDM_REGS_CORE_H__
#define __REG_AT_APB_PDM_REGS_CORE_H__

/**
 *****************************************************************************
 * @defgroup AT_APB_PDM_REGS_CORE at_apb_pdm_regs_core
 * @ingroup AT_REG
 * @brief at_apb_pdm_regs_core definitions.
 * @{
 *****************************************************************************
 */

/* macros for BlueprintGlobalNameSpace::PDM_control */
/**
 * @defgroup at_apb_pdm_regs_core_control control
 * @brief Contains register fields associated with control. definitions.
 * @{
 */
#ifndef __PDM_CONTROL_MACRO__
#define __PDM_CONTROL_MACRO__

/* macros for field enable_dp */
/**
 * @defgroup at_apb_pdm_regs_core_enable_dp_field enable_dp_field
 * @brief macros for field enable_dp
 * @details enable the datapath
 * @{
 */
#define PDM_CONTROL__ENABLE_DP__SHIFT                                         0
#define PDM_CONTROL__ENABLE_DP__WIDTH                                         1
#define PDM_CONTROL__ENABLE_DP__MASK                                0x00000001U
#define PDM_CONTROL__ENABLE_DP__READ(src)       ((uint32_t)(src) & 0x00000001U)
#define PDM_CONTROL__ENABLE_DP__WRITE(src)      ((uint32_t)(src) & 0x00000001U)
#define PDM_CONTROL__ENABLE_DP__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define PDM_CONTROL__ENABLE_DP__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define PDM_CONTROL__ENABLE_DP__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define PDM_CONTROL__ENABLE_DP__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define PDM_CONTROL__ENABLE_DP__RESET_VALUE                         0x00000000U
/** @} */

/* macros for field capture_on_rising */
/**
 * @defgroup at_apb_pdm_regs_core_capture_on_rising_field capture_on_rising_field
 * @brief macros for field capture_on_rising
 * @details selects edge of pdm clock to capture pdm data  0= pdm data sampled on falling edge of pdm clock (i.e. pdm data transitions on rising edge of pdm clock)  1= pdm data sampled on rising edge of pdm clock (i.e. pdm data transitions on falling edge of pdm clock)
 * @{
 */
#define PDM_CONTROL__CAPTURE_ON_RISING__SHIFT                                 1
#define PDM_CONTROL__CAPTURE_ON_RISING__WIDTH                                 1
#define PDM_CONTROL__CAPTURE_ON_RISING__MASK                        0x00000002U
#define PDM_CONTROL__CAPTURE_ON_RISING__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define PDM_CONTROL__CAPTURE_ON_RISING__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define PDM_CONTROL__CAPTURE_ON_RISING__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define PDM_CONTROL__CAPTURE_ON_RISING__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define PDM_CONTROL__CAPTURE_ON_RISING__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define PDM_CONTROL__CAPTURE_ON_RISING__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define PDM_CONTROL__CAPTURE_ON_RISING__RESET_VALUE                 0x00000000U
/** @} */

/* macros for field swap_samples */
/**
 * @defgroup at_apb_pdm_regs_core_swap_samples_field swap_samples_field
 * @brief macros for field swap_samples
 * @details swap packed samples in pingpong buffer location  default: former samples uses lsb bits and later samples uses msb bits  applies to 16bit samples only
 * @{
 */
#define PDM_CONTROL__SWAP_SAMPLES__SHIFT                                      2
#define PDM_CONTROL__SWAP_SAMPLES__WIDTH                                      1
#define PDM_CONTROL__SWAP_SAMPLES__MASK                             0x00000004U
#define PDM_CONTROL__SWAP_SAMPLES__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define PDM_CONTROL__SWAP_SAMPLES__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define PDM_CONTROL__SWAP_SAMPLES__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define PDM_CONTROL__SWAP_SAMPLES__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define PDM_CONTROL__SWAP_SAMPLES__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define PDM_CONTROL__SWAP_SAMPLES__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define PDM_CONTROL__SWAP_SAMPLES__RESET_VALUE                      0x00000000U
/** @} */

/* macros for field pack_samples */
/**
 * @defgroup at_apb_pdm_regs_core_pack_samples_field pack_samples_field
 * @brief macros for field pack_samples
 * @details pack samples in ping-pong buffer  default: samples are stored unpacked  applies to 20/24 bit samples only
 * @{
 */
#define PDM_CONTROL__PACK_SAMPLES__SHIFT                                      3
#define PDM_CONTROL__PACK_SAMPLES__WIDTH                                      1
#define PDM_CONTROL__PACK_SAMPLES__MASK                             0x00000008U
#define PDM_CONTROL__PACK_SAMPLES__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000008U) >> 3)
#define PDM_CONTROL__PACK_SAMPLES__WRITE(src) \
                    (((uint32_t)(src)\
                    << 3) & 0x00000008U)
#define PDM_CONTROL__PACK_SAMPLES__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | (((uint32_t)(src) <<\
                    3) & 0x00000008U)
#define PDM_CONTROL__PACK_SAMPLES__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000008U)))
#define PDM_CONTROL__PACK_SAMPLES__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define PDM_CONTROL__PACK_SAMPLES__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)
#define PDM_CONTROL__PACK_SAMPLES__RESET_VALUE                      0x00000000U
/** @} */

/* macros for field pdm_clk_sel */
/**
 * @defgroup at_apb_pdm_regs_core_pdm_clk_sel_field pdm_clk_sel_field
 * @brief macros for field pdm_clk_sel
 * @details pdm clock frequency = f_pclk/(pdm_clk_sel+1)  valid range: 3 to 31  possible rates when pcm_rate_sel[0]=1:  31= 500KHz  15= 1MHz  7= 2MHz  possible rates when pcm_rate_sel[0]=0:  23= 500KHz  11= 1MHz  5= 2MHz
 * @{
 */
#define PDM_CONTROL__PDM_CLK_SEL__SHIFT                                       4
#define PDM_CONTROL__PDM_CLK_SEL__WIDTH                                       5
#define PDM_CONTROL__PDM_CLK_SEL__MASK                              0x000001f0U
#define PDM_CONTROL__PDM_CLK_SEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000001f0U) >> 4)
#define PDM_CONTROL__PDM_CLK_SEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x000001f0U)
#define PDM_CONTROL__PDM_CLK_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000001f0U) | (((uint32_t)(src) <<\
                    4) & 0x000001f0U)
#define PDM_CONTROL__PDM_CLK_SEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x000001f0U)))
#define PDM_CONTROL__PDM_CLK_SEL__RESET_VALUE                       0x0000000fU
/** @} */

/* macros for field pcm_rate_sel */
/**
 * @defgroup at_apb_pdm_regs_core_pcm_rate_sel_field pcm_rate_sel_field
 * @brief macros for field pcm_rate_sel
 * @details pcm output rate selection if msb bit3=1 it's in pcm_rate override mode  0= 6KHz  1= 8KHz  2= 12KHz  3= 16KHz  4= 24KHz  5= 32KHz  6= 48KHz  7= 64KHz
 * @{
 */
#define PDM_CONTROL__PCM_RATE_SEL__SHIFT                                      9
#define PDM_CONTROL__PCM_RATE_SEL__WIDTH                                      4
#define PDM_CONTROL__PCM_RATE_SEL__MASK                             0x00001e00U
#define PDM_CONTROL__PCM_RATE_SEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00001e00U) >> 9)
#define PDM_CONTROL__PCM_RATE_SEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x00001e00U)
#define PDM_CONTROL__PCM_RATE_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00001e00U) | (((uint32_t)(src) <<\
                    9) & 0x00001e00U)
#define PDM_CONTROL__PCM_RATE_SEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x00001e00U)))
#define PDM_CONTROL__PCM_RATE_SEL__RESET_VALUE                      0x00000003U
/** @} */

/* macros for field pcm_bit_width */
/**
 * @defgroup at_apb_pdm_regs_core_pcm_bit_width_field pcm_bit_width_field
 * @brief macros for field pcm_bit_width
 * @details pcm output sample bit width  0= 16bit  1= 20bit  2/3= 24bit
 * @{
 */
#define PDM_CONTROL__PCM_BIT_WIDTH__SHIFT                                    13
#define PDM_CONTROL__PCM_BIT_WIDTH__WIDTH                                     2
#define PDM_CONTROL__PCM_BIT_WIDTH__MASK                            0x00006000U
#define PDM_CONTROL__PCM_BIT_WIDTH__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00006000U) >> 13)
#define PDM_CONTROL__PCM_BIT_WIDTH__WRITE(src) \
                    (((uint32_t)(src)\
                    << 13) & 0x00006000U)
#define PDM_CONTROL__PCM_BIT_WIDTH__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00006000U) | (((uint32_t)(src) <<\
                    13) & 0x00006000U)
#define PDM_CONTROL__PCM_BIT_WIDTH__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 13) & ~0x00006000U)))
#define PDM_CONTROL__PCM_BIT_WIDTH__RESET_VALUE                     0x00000000U
/** @} */

/* macros for field pdm_in_dbg */
/**
 * @defgroup at_apb_pdm_regs_core_pdm_in_dbg_field pdm_in_dbg_field
 * @brief macros for field pdm_in_dbg
 * @details if 1, bypass pdm bitstream and send in dc value 1
 * @{
 */
#define PDM_CONTROL__PDM_IN_DBG__SHIFT                                       15
#define PDM_CONTROL__PDM_IN_DBG__WIDTH                                        1
#define PDM_CONTROL__PDM_IN_DBG__MASK                               0x00008000U
#define PDM_CONTROL__PDM_IN_DBG__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00008000U) >> 15)
#define PDM_CONTROL__PDM_IN_DBG__WRITE(src) \
                    (((uint32_t)(src)\
                    << 15) & 0x00008000U)
#define PDM_CONTROL__PDM_IN_DBG__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00008000U) | (((uint32_t)(src) <<\
                    15) & 0x00008000U)
#define PDM_CONTROL__PDM_IN_DBG__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 15) & ~0x00008000U)))
#define PDM_CONTROL__PDM_IN_DBG__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00008000U) | ((uint32_t)(1) << 15)
#define PDM_CONTROL__PDM_IN_DBG__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00008000U) | ((uint32_t)(0) << 15)
#define PDM_CONTROL__PDM_IN_DBG__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field stereo_mode */
/**
 * @defgroup at_apb_pdm_regs_core_stereo_mode_field stereo_mode_field
 * @brief macros for field stereo_mode
 * @details selects between stereo and mono mode of operation  1= stereo mode; act as datapath enable for other stereo datapath pair.  When this bit is set along with enable_dp, it enables stereo datapath pair  concurrently to avoid pdm data capture synchronization issues.  At that time, corresponding bits for the other datapath pair shouldn't be set.  0= mono mode; use enable_dp bit to enable each datapath.
 * @{
 */
#define PDM_CONTROL__STEREO_MODE__SHIFT                                      16
#define PDM_CONTROL__STEREO_MODE__WIDTH                                       1
#define PDM_CONTROL__STEREO_MODE__MASK                              0x00010000U
#define PDM_CONTROL__STEREO_MODE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00010000U) >> 16)
#define PDM_CONTROL__STEREO_MODE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 16) & 0x00010000U)
#define PDM_CONTROL__STEREO_MODE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | (((uint32_t)(src) <<\
                    16) & 0x00010000U)
#define PDM_CONTROL__STEREO_MODE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 16) & ~0x00010000U)))
#define PDM_CONTROL__STEREO_MODE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | ((uint32_t)(1) << 16)
#define PDM_CONTROL__STEREO_MODE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00010000U) | ((uint32_t)(0) << 16)
#define PDM_CONTROL__STEREO_MODE__RESET_VALUE                       0x00000000U
/** @} */
#define PDM_CONTROL__TYPE                                              uint32_t
#define PDM_CONTROL__READ                                           0x0001ffffU
#define PDM_CONTROL__WRITE                                          0x0001ffffU
#define PDM_CONTROL__PRESERVED                                      0x00000000U
#define PDM_CONTROL__RESET_VALUE                                    0x000006f0U

#endif /* __PDM_CONTROL_MACRO__ */

/** @} end of control */

/* macros for BlueprintGlobalNameSpace::PDM_filter_config */
/**
 * @defgroup at_apb_pdm_regs_core_filter_config filter_config
 * @brief Contains register fields associated with filter_config. definitions.
 * @{
 */
#ifndef __PDM_FILTER_CONFIG_MACRO__
#define __PDM_FILTER_CONFIG_MACRO__

/* macros for field cic_ord */
/**
 * @defgroup at_apb_pdm_regs_core_cic_ord_field cic_ord_field
 * @brief macros for field cic_ord
 * @details cic order  0= 3rd order  1= 4th order  2/3= unused
 * @{
 */
#define PDM_FILTER_CONFIG__CIC_ORD__SHIFT                                     0
#define PDM_FILTER_CONFIG__CIC_ORD__WIDTH                                     2
#define PDM_FILTER_CONFIG__CIC_ORD__MASK                            0x00000003U
#define PDM_FILTER_CONFIG__CIC_ORD__READ(src)   ((uint32_t)(src) & 0x00000003U)
#define PDM_FILTER_CONFIG__CIC_ORD__WRITE(src)  ((uint32_t)(src) & 0x00000003U)
#define PDM_FILTER_CONFIG__CIC_ORD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000003U) | ((uint32_t)(src) &\
                    0x00000003U)
#define PDM_FILTER_CONFIG__CIC_ORD__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000003U)))
#define PDM_FILTER_CONFIG__CIC_ORD__RESET_VALUE                     0x00000000U
/** @} */

/* macros for field hpf_ord */
/**
 * @defgroup at_apb_pdm_regs_core_hpf_ord_field hpf_ord_field
 * @brief macros for field hpf_ord
 * @details hpf order  0= 1st order  1= 2nd order  2/3= 3rd order
 * @{
 */
#define PDM_FILTER_CONFIG__HPF_ORD__SHIFT                                     2
#define PDM_FILTER_CONFIG__HPF_ORD__WIDTH                                     2
#define PDM_FILTER_CONFIG__HPF_ORD__MASK                            0x0000000cU
#define PDM_FILTER_CONFIG__HPF_ORD__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000000cU) >> 2)
#define PDM_FILTER_CONFIG__HPF_ORD__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x0000000cU)
#define PDM_FILTER_CONFIG__HPF_ORD__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000000cU) | (((uint32_t)(src) <<\
                    2) & 0x0000000cU)
#define PDM_FILTER_CONFIG__HPF_ORD__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x0000000cU)))
#define PDM_FILTER_CONFIG__HPF_ORD__RESET_VALUE                     0x00000000U
/** @} */

/* macros for field hpf_bw */
/**
 * @defgroup at_apb_pdm_regs_core_hpf_bw_field hpf_bw_field
 * @brief macros for field hpf_bw
 * @details hpf bandwidth selection when hpf_ord=0, bandwidth will be (Hz):  0= 10, 1= 20, 2= 40, 3= 80, 4= 161, 5= 324, 6= 658, 7= 1359  when hpf_ord=1, bandwidth will be (Hz):  0= 9, 1= 19, 2= 37, 3= 75, 4= 151, 5= 304, 6= 616, 7= 1269  when hpf_ord=2, bandwidth will be (Hz):  0= 15, 1= 30, 2= 60, 3= 120, 4= 242, 5= 487, 6= 989, 7= 2036
 * @{
 */
#define PDM_FILTER_CONFIG__HPF_BW__SHIFT                                      4
#define PDM_FILTER_CONFIG__HPF_BW__WIDTH                                      4
#define PDM_FILTER_CONFIG__HPF_BW__MASK                             0x000000f0U
#define PDM_FILTER_CONFIG__HPF_BW__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000000f0U) >> 4)
#define PDM_FILTER_CONFIG__HPF_BW__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x000000f0U)
#define PDM_FILTER_CONFIG__HPF_BW__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000000f0U) | (((uint32_t)(src) <<\
                    4) & 0x000000f0U)
#define PDM_FILTER_CONFIG__HPF_BW__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x000000f0U)))
#define PDM_FILTER_CONFIG__HPF_BW__RESET_VALUE                      0x00000005U
/** @} */

/* macros for field hpf_bypass */
/**
 * @defgroup at_apb_pdm_regs_core_hpf_bypass_field hpf_bypass_field
 * @brief macros for field hpf_bypass
 * @details 1= bypass hpf
 * @{
 */
#define PDM_FILTER_CONFIG__HPF_BYPASS__SHIFT                                  8
#define PDM_FILTER_CONFIG__HPF_BYPASS__WIDTH                                  1
#define PDM_FILTER_CONFIG__HPF_BYPASS__MASK                         0x00000100U
#define PDM_FILTER_CONFIG__HPF_BYPASS__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000100U) >> 8)
#define PDM_FILTER_CONFIG__HPF_BYPASS__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00000100U)
#define PDM_FILTER_CONFIG__HPF_BYPASS__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | (((uint32_t)(src) <<\
                    8) & 0x00000100U)
#define PDM_FILTER_CONFIG__HPF_BYPASS__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00000100U)))
#define PDM_FILTER_CONFIG__HPF_BYPASS__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | ((uint32_t)(1) << 8)
#define PDM_FILTER_CONFIG__HPF_BYPASS__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | ((uint32_t)(0) << 8)
#define PDM_FILTER_CONFIG__HPF_BYPASS__RESET_VALUE                  0x00000000U
/** @} */

/* macros for field hpf_init_enable */
/**
 * @defgroup at_apb_pdm_regs_core_hpf_init_enable_field hpf_init_enable_field
 * @brief macros for field hpf_init_enable
 * @details 1= enable hpf initialization
 * @{
 */
#define PDM_FILTER_CONFIG__HPF_INIT_ENABLE__SHIFT                             9
#define PDM_FILTER_CONFIG__HPF_INIT_ENABLE__WIDTH                             1
#define PDM_FILTER_CONFIG__HPF_INIT_ENABLE__MASK                    0x00000200U
#define PDM_FILTER_CONFIG__HPF_INIT_ENABLE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000200U) >> 9)
#define PDM_FILTER_CONFIG__HPF_INIT_ENABLE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x00000200U)
#define PDM_FILTER_CONFIG__HPF_INIT_ENABLE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | (((uint32_t)(src) <<\
                    9) & 0x00000200U)
#define PDM_FILTER_CONFIG__HPF_INIT_ENABLE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x00000200U)))
#define PDM_FILTER_CONFIG__HPF_INIT_ENABLE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | ((uint32_t)(1) << 9)
#define PDM_FILTER_CONFIG__HPF_INIT_ENABLE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | ((uint32_t)(0) << 9)
#define PDM_FILTER_CONFIG__HPF_INIT_ENABLE__RESET_VALUE             0x00000001U
/** @} */

/* macros for field hpf1_init_shift */
/**
 * @defgroup at_apb_pdm_regs_core_hpf1_init_shift_field hpf1_init_shift_field
 * @brief macros for field hpf1_init_shift
 * @details hpf1 initialization shift amount, max=10  for values > max, operation is same as max
 * @{
 */
#define PDM_FILTER_CONFIG__HPF1_INIT_SHIFT__SHIFT                            10
#define PDM_FILTER_CONFIG__HPF1_INIT_SHIFT__WIDTH                             4
#define PDM_FILTER_CONFIG__HPF1_INIT_SHIFT__MASK                    0x00003c00U
#define PDM_FILTER_CONFIG__HPF1_INIT_SHIFT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00003c00U) >> 10)
#define PDM_FILTER_CONFIG__HPF1_INIT_SHIFT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x00003c00U)
#define PDM_FILTER_CONFIG__HPF1_INIT_SHIFT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00003c00U) | (((uint32_t)(src) <<\
                    10) & 0x00003c00U)
#define PDM_FILTER_CONFIG__HPF1_INIT_SHIFT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x00003c00U)))
#define PDM_FILTER_CONFIG__HPF1_INIT_SHIFT__RESET_VALUE             0x0000000aU
/** @} */

/* macros for field hpf2_init_shift */
/**
 * @defgroup at_apb_pdm_regs_core_hpf2_init_shift_field hpf2_init_shift_field
 * @brief macros for field hpf2_init_shift
 * @details hpf2 initialization shift amount, max=24  for values > max, operation is same as max
 * @{
 */
#define PDM_FILTER_CONFIG__HPF2_INIT_SHIFT__SHIFT                            14
#define PDM_FILTER_CONFIG__HPF2_INIT_SHIFT__WIDTH                             5
#define PDM_FILTER_CONFIG__HPF2_INIT_SHIFT__MASK                    0x0007c000U
#define PDM_FILTER_CONFIG__HPF2_INIT_SHIFT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0007c000U) >> 14)
#define PDM_FILTER_CONFIG__HPF2_INIT_SHIFT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 14) & 0x0007c000U)
#define PDM_FILTER_CONFIG__HPF2_INIT_SHIFT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0007c000U) | (((uint32_t)(src) <<\
                    14) & 0x0007c000U)
#define PDM_FILTER_CONFIG__HPF2_INIT_SHIFT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 14) & ~0x0007c000U)))
#define PDM_FILTER_CONFIG__HPF2_INIT_SHIFT__RESET_VALUE             0x00000018U
/** @} */

/* macros for field hbf_bypass_ovrd_val */
/**
 * @defgroup at_apb_pdm_regs_core_hbf_bypass_ovrd_val_field hbf_bypass_ovrd_val_field
 * @brief macros for field hbf_bypass_ovrd_val
 * @details hbf bypass override value  used only during pcm_rate override mode:  0= enable hbf  1= bypass hbf; output rate=input rate
 * @{
 */
#define PDM_FILTER_CONFIG__HBF_BYPASS_OVRD_VAL__SHIFT                        19
#define PDM_FILTER_CONFIG__HBF_BYPASS_OVRD_VAL__WIDTH                         1
#define PDM_FILTER_CONFIG__HBF_BYPASS_OVRD_VAL__MASK                0x00080000U
#define PDM_FILTER_CONFIG__HBF_BYPASS_OVRD_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00080000U) >> 19)
#define PDM_FILTER_CONFIG__HBF_BYPASS_OVRD_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 19) & 0x00080000U)
#define PDM_FILTER_CONFIG__HBF_BYPASS_OVRD_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | (((uint32_t)(src) <<\
                    19) & 0x00080000U)
#define PDM_FILTER_CONFIG__HBF_BYPASS_OVRD_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 19) & ~0x00080000U)))
#define PDM_FILTER_CONFIG__HBF_BYPASS_OVRD_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | ((uint32_t)(1) << 19)
#define PDM_FILTER_CONFIG__HBF_BYPASS_OVRD_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | ((uint32_t)(0) << 19)
#define PDM_FILTER_CONFIG__HBF_BYPASS_OVRD_VAL__RESET_VALUE         0x00000000U
/** @} */

/* macros for field lpf_bw */
/**
 * @defgroup at_apb_pdm_regs_core_lpf_bw_field lpf_bw_field
 * @brief macros for field lpf_bw
 * @details lpf bandwidth override selection used only during pcm_rate override mode:  if pcm_rate_sel[0]=1, bandwidth will be (KHz):  0= 4  1= 6  2= 8  3= 10  4= 12  5= 14  6/7= 15.5  if pcm_rate_sel[0]=0, bandwidth will be (KHz):  0= 3  1= 4.5  2= 6  3= 7.5  4= 9  5= 10  6/7= 11.5
 * @{
 */
#define PDM_FILTER_CONFIG__LPF_BW__SHIFT                                     20
#define PDM_FILTER_CONFIG__LPF_BW__WIDTH                                      3
#define PDM_FILTER_CONFIG__LPF_BW__MASK                             0x00700000U
#define PDM_FILTER_CONFIG__LPF_BW__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00700000U) >> 20)
#define PDM_FILTER_CONFIG__LPF_BW__WRITE(src) \
                    (((uint32_t)(src)\
                    << 20) & 0x00700000U)
#define PDM_FILTER_CONFIG__LPF_BW__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00700000U) | (((uint32_t)(src) <<\
                    20) & 0x00700000U)
#define PDM_FILTER_CONFIG__LPF_BW__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 20) & ~0x00700000U)))
#define PDM_FILTER_CONFIG__LPF_BW__RESET_VALUE                      0x00000000U
/** @} */

/* macros for field lpf_bypass_ovrd_val */
/**
 * @defgroup at_apb_pdm_regs_core_lpf_bypass_ovrd_val_field lpf_bypass_ovrd_val_field
 * @brief macros for field lpf_bypass_ovrd_val
 * @details lpf bypass override value  used only during pcm_rate override mode:  0= enable lpf  1= bypass lpf; output rate=input rate
 * @{
 */
#define PDM_FILTER_CONFIG__LPF_BYPASS_OVRD_VAL__SHIFT                        23
#define PDM_FILTER_CONFIG__LPF_BYPASS_OVRD_VAL__WIDTH                         1
#define PDM_FILTER_CONFIG__LPF_BYPASS_OVRD_VAL__MASK                0x00800000U
#define PDM_FILTER_CONFIG__LPF_BYPASS_OVRD_VAL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00800000U) >> 23)
#define PDM_FILTER_CONFIG__LPF_BYPASS_OVRD_VAL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 23) & 0x00800000U)
#define PDM_FILTER_CONFIG__LPF_BYPASS_OVRD_VAL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | (((uint32_t)(src) <<\
                    23) & 0x00800000U)
#define PDM_FILTER_CONFIG__LPF_BYPASS_OVRD_VAL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 23) & ~0x00800000U)))
#define PDM_FILTER_CONFIG__LPF_BYPASS_OVRD_VAL__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(1) << 23)
#define PDM_FILTER_CONFIG__LPF_BYPASS_OVRD_VAL__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00800000U) | ((uint32_t)(0) << 23)
#define PDM_FILTER_CONFIG__LPF_BYPASS_OVRD_VAL__RESET_VALUE         0x00000000U
/** @} */

/* macros for field downsample_ratio */
/**
 * @defgroup at_apb_pdm_regs_core_downsample_ratio_field downsample_ratio_field
 * @brief macros for field downsample_ratio
 * @details downsample override  used only during pcm_rate override mode:  downsampling by 1/(1+downsample_ratio)
 * @{
 */
#define PDM_FILTER_CONFIG__DOWNSAMPLE_RATIO__SHIFT                           24
#define PDM_FILTER_CONFIG__DOWNSAMPLE_RATIO__WIDTH                            2
#define PDM_FILTER_CONFIG__DOWNSAMPLE_RATIO__MASK                   0x03000000U
#define PDM_FILTER_CONFIG__DOWNSAMPLE_RATIO__READ(src) \
                    (((uint32_t)(src)\
                    & 0x03000000U) >> 24)
#define PDM_FILTER_CONFIG__DOWNSAMPLE_RATIO__WRITE(src) \
                    (((uint32_t)(src)\
                    << 24) & 0x03000000U)
#define PDM_FILTER_CONFIG__DOWNSAMPLE_RATIO__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x03000000U) | (((uint32_t)(src) <<\
                    24) & 0x03000000U)
#define PDM_FILTER_CONFIG__DOWNSAMPLE_RATIO__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 24) & ~0x03000000U)))
#define PDM_FILTER_CONFIG__DOWNSAMPLE_RATIO__RESET_VALUE            0x00000000U
/** @} */
#define PDM_FILTER_CONFIG__TYPE                                        uint32_t
#define PDM_FILTER_CONFIG__READ                                     0x03ffffffU
#define PDM_FILTER_CONFIG__WRITE                                    0x03ffffffU
#define PDM_FILTER_CONFIG__PRESERVED                                0x00000000U
#define PDM_FILTER_CONFIG__RESET_VALUE                              0x00062a50U

#endif /* __PDM_FILTER_CONFIG_MACRO__ */

/** @} end of filter_config */

/* macros for BlueprintGlobalNameSpace::PDM_filter_config1 */
/**
 * @defgroup at_apb_pdm_regs_core_filter_config1 filter_config1
 * @brief Contains register fields associated with filter_config1. definitions.
 * @{
 */
#ifndef __PDM_FILTER_CONFIG1_MACRO__
#define __PDM_FILTER_CONFIG1_MACRO__

/* macros for field interp_bypass */
/**
 * @defgroup at_apb_pdm_regs_core_interp_bypass_field interp_bypass_field
 * @brief macros for field interp_bypass
 * @details 1= bypass interpolator, also resets the fir filter taps
 * @{
 */
#define PDM_FILTER_CONFIG1__INTERP_BYPASS__SHIFT                              0
#define PDM_FILTER_CONFIG1__INTERP_BYPASS__WIDTH                              1
#define PDM_FILTER_CONFIG1__INTERP_BYPASS__MASK                     0x00000001U
#define PDM_FILTER_CONFIG1__INTERP_BYPASS__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define PDM_FILTER_CONFIG1__INTERP_BYPASS__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define PDM_FILTER_CONFIG1__INTERP_BYPASS__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define PDM_FILTER_CONFIG1__INTERP_BYPASS__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define PDM_FILTER_CONFIG1__INTERP_BYPASS__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define PDM_FILTER_CONFIG1__INTERP_BYPASS__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define PDM_FILTER_CONFIG1__INTERP_BYPASS__RESET_VALUE              0x00000000U
/** @} */

/* macros for field interp_skp_sample */
/**
 * @defgroup at_apb_pdm_regs_core_interp_skp_sample_field interp_skp_sample_field
 * @brief macros for field interp_skp_sample
 * @details skip one sample to accomodate cfo frequency drift, auto-clear
 * @{
 */
#define PDM_FILTER_CONFIG1__INTERP_SKP_SAMPLE__SHIFT                          1
#define PDM_FILTER_CONFIG1__INTERP_SKP_SAMPLE__WIDTH                          1
#define PDM_FILTER_CONFIG1__INTERP_SKP_SAMPLE__MASK                 0x00000002U
#define PDM_FILTER_CONFIG1__INTERP_SKP_SAMPLE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define PDM_FILTER_CONFIG1__INTERP_SKP_SAMPLE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define PDM_FILTER_CONFIG1__INTERP_SKP_SAMPLE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define PDM_FILTER_CONFIG1__INTERP_SKP_SAMPLE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define PDM_FILTER_CONFIG1__INTERP_SKP_SAMPLE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define PDM_FILTER_CONFIG1__INTERP_SKP_SAMPLE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define PDM_FILTER_CONFIG1__INTERP_SKP_SAMPLE__RESET_VALUE          0x00000000U
/** @} */

/* macros for field interp_add_sample */
/**
 * @defgroup at_apb_pdm_regs_core_interp_add_sample_field interp_add_sample_field
 * @brief macros for field interp_add_sample
 * @details add one sample to accomodate cfo frequency drift, auto-clear
 * @{
 */
#define PDM_FILTER_CONFIG1__INTERP_ADD_SAMPLE__SHIFT                          2
#define PDM_FILTER_CONFIG1__INTERP_ADD_SAMPLE__WIDTH                          1
#define PDM_FILTER_CONFIG1__INTERP_ADD_SAMPLE__MASK                 0x00000004U
#define PDM_FILTER_CONFIG1__INTERP_ADD_SAMPLE__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define PDM_FILTER_CONFIG1__INTERP_ADD_SAMPLE__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define PDM_FILTER_CONFIG1__INTERP_ADD_SAMPLE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define PDM_FILTER_CONFIG1__INTERP_ADD_SAMPLE__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define PDM_FILTER_CONFIG1__INTERP_ADD_SAMPLE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define PDM_FILTER_CONFIG1__INTERP_ADD_SAMPLE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define PDM_FILTER_CONFIG1__INTERP_ADD_SAMPLE__RESET_VALUE          0x00000000U
/** @} */

/* macros for field interp_ph_idx0 */
/**
 * @defgroup at_apb_pdm_regs_core_interp_ph_idx0_field interp_ph_idx0_field
 * @brief macros for field interp_ph_idx0
 * @details index-0 into interpolator coefficient table
 * @{
 */
#define PDM_FILTER_CONFIG1__INTERP_PH_IDX0__SHIFT                             3
#define PDM_FILTER_CONFIG1__INTERP_PH_IDX0__WIDTH                             8
#define PDM_FILTER_CONFIG1__INTERP_PH_IDX0__MASK                    0x000007f8U
#define PDM_FILTER_CONFIG1__INTERP_PH_IDX0__READ(src) \
                    (((uint32_t)(src)\
                    & 0x000007f8U) >> 3)
#define PDM_FILTER_CONFIG1__INTERP_PH_IDX0__WRITE(src) \
                    (((uint32_t)(src)\
                    << 3) & 0x000007f8U)
#define PDM_FILTER_CONFIG1__INTERP_PH_IDX0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x000007f8U) | (((uint32_t)(src) <<\
                    3) & 0x000007f8U)
#define PDM_FILTER_CONFIG1__INTERP_PH_IDX0__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x000007f8U)))
#define PDM_FILTER_CONFIG1__INTERP_PH_IDX0__RESET_VALUE             0x0000007fU
/** @} */

/* macros for field interp_ph_idx1 */
/**
 * @defgroup at_apb_pdm_regs_core_interp_ph_idx1_field interp_ph_idx1_field
 * @brief macros for field interp_ph_idx1
 * @details index-1 into interpolator coefficient table; for use only when add sample
 * @{
 */
#define PDM_FILTER_CONFIG1__INTERP_PH_IDX1__SHIFT                            11
#define PDM_FILTER_CONFIG1__INTERP_PH_IDX1__WIDTH                             8
#define PDM_FILTER_CONFIG1__INTERP_PH_IDX1__MASK                    0x0007f800U
#define PDM_FILTER_CONFIG1__INTERP_PH_IDX1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0007f800U) >> 11)
#define PDM_FILTER_CONFIG1__INTERP_PH_IDX1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 11) & 0x0007f800U)
#define PDM_FILTER_CONFIG1__INTERP_PH_IDX1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0007f800U) | (((uint32_t)(src) <<\
                    11) & 0x0007f800U)
#define PDM_FILTER_CONFIG1__INTERP_PH_IDX1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 11) & ~0x0007f800U)))
#define PDM_FILTER_CONFIG1__INTERP_PH_IDX1__RESET_VALUE             0x00000000U
/** @} */

/* macros for field interp_ph_idx_updt */
/**
 * @defgroup at_apb_pdm_regs_core_interp_ph_idx_updt_field interp_ph_idx_updt_field
 * @brief macros for field interp_ph_idx_updt
 * @details interpolator phase indices update indicator for HW to capture, auto-clear
 * @{
 */
#define PDM_FILTER_CONFIG1__INTERP_PH_IDX_UPDT__SHIFT                        19
#define PDM_FILTER_CONFIG1__INTERP_PH_IDX_UPDT__WIDTH                         1
#define PDM_FILTER_CONFIG1__INTERP_PH_IDX_UPDT__MASK                0x00080000U
#define PDM_FILTER_CONFIG1__INTERP_PH_IDX_UPDT__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00080000U) >> 19)
#define PDM_FILTER_CONFIG1__INTERP_PH_IDX_UPDT__WRITE(src) \
                    (((uint32_t)(src)\
                    << 19) & 0x00080000U)
#define PDM_FILTER_CONFIG1__INTERP_PH_IDX_UPDT__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | (((uint32_t)(src) <<\
                    19) & 0x00080000U)
#define PDM_FILTER_CONFIG1__INTERP_PH_IDX_UPDT__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 19) & ~0x00080000U)))
#define PDM_FILTER_CONFIG1__INTERP_PH_IDX_UPDT__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | ((uint32_t)(1) << 19)
#define PDM_FILTER_CONFIG1__INTERP_PH_IDX_UPDT__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00080000U) | ((uint32_t)(0) << 19)
#define PDM_FILTER_CONFIG1__INTERP_PH_IDX_UPDT__RESET_VALUE         0x00000000U
/** @} */
#define PDM_FILTER_CONFIG1__TYPE                                       uint32_t
#define PDM_FILTER_CONFIG1__READ                                    0x000fffffU
#define PDM_FILTER_CONFIG1__WRITE                                   0x000fffffU
#define PDM_FILTER_CONFIG1__PRESERVED                               0x00000000U
#define PDM_FILTER_CONFIG1__RESET_VALUE                             0x000003f8U

#endif /* __PDM_FILTER_CONFIG1_MACRO__ */

/** @} end of filter_config1 */

/* macros for BlueprintGlobalNameSpace::PDM_gain_control_config */
/**
 * @defgroup at_apb_pdm_regs_core_gain_control_config gain_control_config
 * @brief Contains register fields associated with gain_control_config. definitions.
 * @{
 */
#ifndef __PDM_GAIN_CONTROL_CONFIG_MACRO__
#define __PDM_GAIN_CONTROL_CONFIG_MACRO__

/* macros for field code */
/**
 * @defgroup at_apb_pdm_regs_core_code_field code_field
 * @brief macros for field code
 * @details gain code for LUT
 * @{
 */
#define PDM_GAIN_CONTROL_CONFIG__CODE__SHIFT                                  0
#define PDM_GAIN_CONTROL_CONFIG__CODE__WIDTH                                  7
#define PDM_GAIN_CONTROL_CONFIG__CODE__MASK                         0x0000007fU
#define PDM_GAIN_CONTROL_CONFIG__CODE__READ(src) \
                    ((uint32_t)(src)\
                    & 0x0000007fU)
#define PDM_GAIN_CONTROL_CONFIG__CODE__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x0000007fU)
#define PDM_GAIN_CONTROL_CONFIG__CODE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000007fU) | ((uint32_t)(src) &\
                    0x0000007fU)
#define PDM_GAIN_CONTROL_CONFIG__CODE__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x0000007fU)))
#define PDM_GAIN_CONTROL_CONFIG__CODE__RESET_VALUE                  0x00000040U
/** @} */

/* macros for field cic_gain_sel */
/**
 * @defgroup at_apb_pdm_regs_core_cic_gain_sel_field cic_gain_sel_field
 * @brief macros for field cic_gain_sel
 * @details allow gain-scaling at the output of cic through bit shifting  zero-padding for left shift; rounding, dropping lsbs for right shift.  0= no scaling  1-4= up scaling; zero-padding +1 to +4 respectively  5-7= down scaling; dropping lsbs -1 to -3 respectively
 * @{
 */
#define PDM_GAIN_CONTROL_CONFIG__CIC_GAIN_SEL__SHIFT                          7
#define PDM_GAIN_CONTROL_CONFIG__CIC_GAIN_SEL__WIDTH                          3
#define PDM_GAIN_CONTROL_CONFIG__CIC_GAIN_SEL__MASK                 0x00000380U
#define PDM_GAIN_CONTROL_CONFIG__CIC_GAIN_SEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000380U) >> 7)
#define PDM_GAIN_CONTROL_CONFIG__CIC_GAIN_SEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 7) & 0x00000380U)
#define PDM_GAIN_CONTROL_CONFIG__CIC_GAIN_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000380U) | (((uint32_t)(src) <<\
                    7) & 0x00000380U)
#define PDM_GAIN_CONTROL_CONFIG__CIC_GAIN_SEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 7) & ~0x00000380U)))
#define PDM_GAIN_CONTROL_CONFIG__CIC_GAIN_SEL__RESET_VALUE          0x00000000U
/** @} */

/* macros for field hpf_gain_sel */
/**
 * @defgroup at_apb_pdm_regs_core_hpf_gain_sel_field hpf_gain_sel_field
 * @brief macros for field hpf_gain_sel
 * @details allow gain-scaling at the output of hpf through bit shifting  zero-padding for left shift; rounding, dropping lsbs for right shift.  0= no scaling  1-4= up scaling; zero-padding +1 to +4 respectively  5-7= down scaling; dropping lsbs -1 to -3 respectively
 * @{
 */
#define PDM_GAIN_CONTROL_CONFIG__HPF_GAIN_SEL__SHIFT                         10
#define PDM_GAIN_CONTROL_CONFIG__HPF_GAIN_SEL__WIDTH                          3
#define PDM_GAIN_CONTROL_CONFIG__HPF_GAIN_SEL__MASK                 0x00001c00U
#define PDM_GAIN_CONTROL_CONFIG__HPF_GAIN_SEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00001c00U) >> 10)
#define PDM_GAIN_CONTROL_CONFIG__HPF_GAIN_SEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 10) & 0x00001c00U)
#define PDM_GAIN_CONTROL_CONFIG__HPF_GAIN_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00001c00U) | (((uint32_t)(src) <<\
                    10) & 0x00001c00U)
#define PDM_GAIN_CONTROL_CONFIG__HPF_GAIN_SEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 10) & ~0x00001c00U)))
#define PDM_GAIN_CONTROL_CONFIG__HPF_GAIN_SEL__RESET_VALUE          0x00000000U
/** @} */

/* macros for field hbf_gain_sel */
/**
 * @defgroup at_apb_pdm_regs_core_hbf_gain_sel_field hbf_gain_sel_field
 * @brief macros for field hbf_gain_sel
 * @details allow gain-scaling at the output of hbf through bit shifting  zero-padding for left shift; rounding, dropping lsbs for right shift.  0= no scaling  1-4= up scaling; zero-padding +1 to +4 respectively  5-7= down scaling; dropping lsbs -1 to -3 respectively
 * @{
 */
#define PDM_GAIN_CONTROL_CONFIG__HBF_GAIN_SEL__SHIFT                         13
#define PDM_GAIN_CONTROL_CONFIG__HBF_GAIN_SEL__WIDTH                          3
#define PDM_GAIN_CONTROL_CONFIG__HBF_GAIN_SEL__MASK                 0x0000e000U
#define PDM_GAIN_CONTROL_CONFIG__HBF_GAIN_SEL__READ(src) \
                    (((uint32_t)(src)\
                    & 0x0000e000U) >> 13)
#define PDM_GAIN_CONTROL_CONFIG__HBF_GAIN_SEL__WRITE(src) \
                    (((uint32_t)(src)\
                    << 13) & 0x0000e000U)
#define PDM_GAIN_CONTROL_CONFIG__HBF_GAIN_SEL__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x0000e000U) | (((uint32_t)(src) <<\
                    13) & 0x0000e000U)
#define PDM_GAIN_CONTROL_CONFIG__HBF_GAIN_SEL__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 13) & ~0x0000e000U)))
#define PDM_GAIN_CONTROL_CONFIG__HBF_GAIN_SEL__RESET_VALUE          0x00000000U
/** @} */
#define PDM_GAIN_CONTROL_CONFIG__TYPE                                  uint32_t
#define PDM_GAIN_CONTROL_CONFIG__READ                               0x0000ffffU
#define PDM_GAIN_CONTROL_CONFIG__WRITE                              0x0000ffffU
#define PDM_GAIN_CONTROL_CONFIG__PRESERVED                          0x00000000U
#define PDM_GAIN_CONTROL_CONFIG__RESET_VALUE                        0x00000040U

#endif /* __PDM_GAIN_CONTROL_CONFIG_MACRO__ */

/** @} end of gain_control_config */

/* macros for BlueprintGlobalNameSpace::PDM_pcm_sample */
/**
 * @defgroup at_apb_pdm_regs_core_pcm_sample pcm_sample
 * @brief A read of this register pops data FIFO definitions.
 * @{
 */
#ifndef __PDM_PCM_SAMPLE_MACRO__
#define __PDM_PCM_SAMPLE_MACRO__

/* macros for field data */
/**
 * @defgroup at_apb_pdm_regs_core_data_field data_field
 * @brief macros for field data
 * @details signed, twos complement
 * @{
 */
#define PDM_PCM_SAMPLE__DATA__SHIFT                                           0
#define PDM_PCM_SAMPLE__DATA__WIDTH                                          24
#define PDM_PCM_SAMPLE__DATA__MASK                                  0x00ffffffU
#define PDM_PCM_SAMPLE__DATA__READ(src)         ((uint32_t)(src) & 0x00ffffffU)
#define PDM_PCM_SAMPLE__DATA__RESET_VALUE                           0x00000000U
/** @} */

/* macros for field empty */
/**
 * @defgroup at_apb_pdm_regs_core_empty_field empty_field
 * @brief macros for field empty
 * @details if 1, ignore data sample because fifo has been drained
 * @{
 */
#define PDM_PCM_SAMPLE__EMPTY__SHIFT                                         31
#define PDM_PCM_SAMPLE__EMPTY__WIDTH                                          1
#define PDM_PCM_SAMPLE__EMPTY__MASK                                 0x80000000U
#define PDM_PCM_SAMPLE__EMPTY__READ(src) \
                    (((uint32_t)(src)\
                    & 0x80000000U) >> 31)
#define PDM_PCM_SAMPLE__EMPTY__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(1) << 31)
#define PDM_PCM_SAMPLE__EMPTY__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x80000000U) | ((uint32_t)(0) << 31)
#define PDM_PCM_SAMPLE__EMPTY__RESET_VALUE                          0x00000000U
/** @} */
#define PDM_PCM_SAMPLE__TYPE                                           uint32_t
#define PDM_PCM_SAMPLE__READ                                        0x80ffffffU
#define PDM_PCM_SAMPLE__PRESERVED                                   0x00000000U
#define PDM_PCM_SAMPLE__RESET_VALUE                                 0x00000000U

#endif /* __PDM_PCM_SAMPLE_MACRO__ */

/** @} end of pcm_sample */

/* macros for BlueprintGlobalNameSpace::PDM_fifo_debug */
/**
 * @defgroup at_apb_pdm_regs_core_fifo_debug fifo_debug
 * @brief Contains register fields associated with fifo_debug. definitions.
 * @{
 */
#ifndef __PDM_FIFO_DEBUG_MACRO__
#define __PDM_FIFO_DEBUG_MACRO__

/* macros for field status */
/**
 * @defgroup at_apb_pdm_regs_core_status_field status_field
 * @brief macros for field status
 * @details {overrun, underrun, full, empty, 4'd0, rdaddr(unsigned int; 4b), wraddr(unsigned int; 4b)}
 * @{
 */
#define PDM_FIFO_DEBUG__STATUS__SHIFT                                         0
#define PDM_FIFO_DEBUG__STATUS__WIDTH                                        16
#define PDM_FIFO_DEBUG__STATUS__MASK                                0x0000ffffU
#define PDM_FIFO_DEBUG__STATUS__READ(src)       ((uint32_t)(src) & 0x0000ffffU)
#define PDM_FIFO_DEBUG__STATUS__RESET_VALUE                         0x00000000U
/** @} */
#define PDM_FIFO_DEBUG__TYPE                                           uint32_t
#define PDM_FIFO_DEBUG__READ                                        0x0000ffffU
#define PDM_FIFO_DEBUG__PRESERVED                                   0x00000000U
#define PDM_FIFO_DEBUG__RESET_VALUE                                 0x00000000U

#endif /* __PDM_FIFO_DEBUG_MACRO__ */

/** @} end of fifo_debug */

/* macros for BlueprintGlobalNameSpace::PDM_interrupts */
/**
 * @defgroup at_apb_pdm_regs_core_interrupts interrupts
 * @brief Contains register fields associated with interrupts. definitions.
 * @{
 */
#ifndef __PDM_INTERRUPTS_MACRO__
#define __PDM_INTERRUPTS_MACRO__

/* macros for field intrpt0 */
/**
 * @defgroup at_apb_pdm_regs_core_intrpt0_field intrpt0_field
 * @brief macros for field intrpt0
 * @details interpolator done processing current pcm sample
 * @{
 */
#define PDM_INTERRUPTS__INTRPT0__SHIFT                                        0
#define PDM_INTERRUPTS__INTRPT0__WIDTH                                        1
#define PDM_INTERRUPTS__INTRPT0__MASK                               0x00000001U
#define PDM_INTERRUPTS__INTRPT0__READ(src)      ((uint32_t)(src) & 0x00000001U)
#define PDM_INTERRUPTS__INTRPT0__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define PDM_INTERRUPTS__INTRPT0__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define PDM_INTERRUPTS__INTRPT0__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field intrpt1 */
/**
 * @defgroup at_apb_pdm_regs_core_intrpt1_field intrpt1_field
 * @brief macros for field intrpt1
 * @details hw wrote to ping pong buffer
 * @{
 */
#define PDM_INTERRUPTS__INTRPT1__SHIFT                                        1
#define PDM_INTERRUPTS__INTRPT1__WIDTH                                        1
#define PDM_INTERRUPTS__INTRPT1__MASK                               0x00000002U
#define PDM_INTERRUPTS__INTRPT1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define PDM_INTERRUPTS__INTRPT1__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define PDM_INTERRUPTS__INTRPT1__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define PDM_INTERRUPTS__INTRPT1__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field intrpt2 */
/**
 * @defgroup at_apb_pdm_regs_core_intrpt2_field intrpt2_field
 * @brief macros for field intrpt2
 * @details ping pong buffer A is locked and needs to be emptied
 * @{
 */
#define PDM_INTERRUPTS__INTRPT2__SHIFT                                        2
#define PDM_INTERRUPTS__INTRPT2__WIDTH                                        1
#define PDM_INTERRUPTS__INTRPT2__MASK                               0x00000004U
#define PDM_INTERRUPTS__INTRPT2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define PDM_INTERRUPTS__INTRPT2__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define PDM_INTERRUPTS__INTRPT2__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define PDM_INTERRUPTS__INTRPT2__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field intrpt3 */
/**
 * @defgroup at_apb_pdm_regs_core_intrpt3_field intrpt3_field
 * @brief macros for field intrpt3
 * @details ping pong buffer B is locked and needs to be emptied
 * @{
 */
#define PDM_INTERRUPTS__INTRPT3__SHIFT                                        3
#define PDM_INTERRUPTS__INTRPT3__WIDTH                                        1
#define PDM_INTERRUPTS__INTRPT3__MASK                               0x00000008U
#define PDM_INTERRUPTS__INTRPT3__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000008U) >> 3)
#define PDM_INTERRUPTS__INTRPT3__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define PDM_INTERRUPTS__INTRPT3__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)
#define PDM_INTERRUPTS__INTRPT3__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field intrpt4 */
/**
 * @defgroup at_apb_pdm_regs_core_intrpt4_field intrpt4_field
 * @brief macros for field intrpt4
 * @details error in buffer A; hw wants to write to buffer but lock hasn't been released by sw
 * @{
 */
#define PDM_INTERRUPTS__INTRPT4__SHIFT                                        4
#define PDM_INTERRUPTS__INTRPT4__WIDTH                                        1
#define PDM_INTERRUPTS__INTRPT4__MASK                               0x00000010U
#define PDM_INTERRUPTS__INTRPT4__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000010U) >> 4)
#define PDM_INTERRUPTS__INTRPT4__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(1) << 4)
#define PDM_INTERRUPTS__INTRPT4__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(0) << 4)
#define PDM_INTERRUPTS__INTRPT4__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field intrpt5 */
/**
 * @defgroup at_apb_pdm_regs_core_intrpt5_field intrpt5_field
 * @brief macros for field intrpt5
 * @details error in buffer B; hw wants to write to buffer but lock hasn't been released by sw
 * @{
 */
#define PDM_INTERRUPTS__INTRPT5__SHIFT                                        5
#define PDM_INTERRUPTS__INTRPT5__WIDTH                                        1
#define PDM_INTERRUPTS__INTRPT5__MASK                               0x00000020U
#define PDM_INTERRUPTS__INTRPT5__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000020U) >> 5)
#define PDM_INTERRUPTS__INTRPT5__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(1) << 5)
#define PDM_INTERRUPTS__INTRPT5__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(0) << 5)
#define PDM_INTERRUPTS__INTRPT5__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field intrpt6 */
/**
 * @defgroup at_apb_pdm_regs_core_intrpt6_field intrpt6_field
 * @brief macros for field intrpt6
 * @details ping pong buffer C is locked and needs to be emptied
 * @{
 */
#define PDM_INTERRUPTS__INTRPT6__SHIFT                                        6
#define PDM_INTERRUPTS__INTRPT6__WIDTH                                        1
#define PDM_INTERRUPTS__INTRPT6__MASK                               0x00000040U
#define PDM_INTERRUPTS__INTRPT6__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000040U) >> 6)
#define PDM_INTERRUPTS__INTRPT6__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(1) << 6)
#define PDM_INTERRUPTS__INTRPT6__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(0) << 6)
#define PDM_INTERRUPTS__INTRPT6__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field intrpt7 */
/**
 * @defgroup at_apb_pdm_regs_core_intrpt7_field intrpt7_field
 * @brief macros for field intrpt7
 * @details ping pong buffer D is locked and needs to be emptied
 * @{
 */
#define PDM_INTERRUPTS__INTRPT7__SHIFT                                        7
#define PDM_INTERRUPTS__INTRPT7__WIDTH                                        1
#define PDM_INTERRUPTS__INTRPT7__MASK                               0x00000080U
#define PDM_INTERRUPTS__INTRPT7__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000080U) >> 7)
#define PDM_INTERRUPTS__INTRPT7__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | ((uint32_t)(1) << 7)
#define PDM_INTERRUPTS__INTRPT7__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | ((uint32_t)(0) << 7)
#define PDM_INTERRUPTS__INTRPT7__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field intrpt8 */
/**
 * @defgroup at_apb_pdm_regs_core_intrpt8_field intrpt8_field
 * @brief macros for field intrpt8
 * @details error in buffer C; hw wants to write to buffer but lock hasn't been released by sw
 * @{
 */
#define PDM_INTERRUPTS__INTRPT8__SHIFT                                        8
#define PDM_INTERRUPTS__INTRPT8__WIDTH                                        1
#define PDM_INTERRUPTS__INTRPT8__MASK                               0x00000100U
#define PDM_INTERRUPTS__INTRPT8__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000100U) >> 8)
#define PDM_INTERRUPTS__INTRPT8__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | ((uint32_t)(1) << 8)
#define PDM_INTERRUPTS__INTRPT8__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | ((uint32_t)(0) << 8)
#define PDM_INTERRUPTS__INTRPT8__RESET_VALUE                        0x00000000U
/** @} */

/* macros for field intrpt9 */
/**
 * @defgroup at_apb_pdm_regs_core_intrpt9_field intrpt9_field
 * @brief macros for field intrpt9
 * @details error in buffer D; hw wants to write to buffer but lock hasn't been released by sw
 * @{
 */
#define PDM_INTERRUPTS__INTRPT9__SHIFT                                        9
#define PDM_INTERRUPTS__INTRPT9__WIDTH                                        1
#define PDM_INTERRUPTS__INTRPT9__MASK                               0x00000200U
#define PDM_INTERRUPTS__INTRPT9__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000200U) >> 9)
#define PDM_INTERRUPTS__INTRPT9__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | ((uint32_t)(1) << 9)
#define PDM_INTERRUPTS__INTRPT9__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | ((uint32_t)(0) << 9)
#define PDM_INTERRUPTS__INTRPT9__RESET_VALUE                        0x00000000U
/** @} */
#define PDM_INTERRUPTS__TYPE                                           uint32_t
#define PDM_INTERRUPTS__READ                                        0x000003ffU
#define PDM_INTERRUPTS__PRESERVED                                   0x00000000U
#define PDM_INTERRUPTS__RESET_VALUE                                 0x00000000U

#endif /* __PDM_INTERRUPTS_MACRO__ */

/** @} end of interrupts */

/* macros for BlueprintGlobalNameSpace::PDM_interrupt_mask */
/**
 * @defgroup at_apb_pdm_regs_core_interrupt_mask interrupt_mask
 * @brief Contains register fields associated with interrupt_mask. definitions.
 * @{
 */
#ifndef __PDM_INTERRUPT_MASK_MACRO__
#define __PDM_INTERRUPT_MASK_MACRO__

/* macros for field mask_intrpt0 */
/**
 * @defgroup at_apb_pdm_regs_core_mask_intrpt0_field mask_intrpt0_field
 * @brief macros for field mask_intrpt0
 * @details allow intrpt0 to propogate to core's single output interrupt
 * @{
 */
#define PDM_INTERRUPT_MASK__MASK_INTRPT0__SHIFT                               0
#define PDM_INTERRUPT_MASK__MASK_INTRPT0__WIDTH                               1
#define PDM_INTERRUPT_MASK__MASK_INTRPT0__MASK                      0x00000001U
#define PDM_INTERRUPT_MASK__MASK_INTRPT0__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define PDM_INTERRUPT_MASK__MASK_INTRPT0__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define PDM_INTERRUPT_MASK__MASK_INTRPT0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define PDM_INTERRUPT_MASK__MASK_INTRPT0__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define PDM_INTERRUPT_MASK__MASK_INTRPT0__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define PDM_INTERRUPT_MASK__MASK_INTRPT0__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define PDM_INTERRUPT_MASK__MASK_INTRPT0__RESET_VALUE               0x00000001U
/** @} */

/* macros for field mask_intrpt1 */
/**
 * @defgroup at_apb_pdm_regs_core_mask_intrpt1_field mask_intrpt1_field
 * @brief macros for field mask_intrpt1
 * @details allow intrpt1 to propogate to core's single output interrupt
 * @{
 */
#define PDM_INTERRUPT_MASK__MASK_INTRPT1__SHIFT                               1
#define PDM_INTERRUPT_MASK__MASK_INTRPT1__WIDTH                               1
#define PDM_INTERRUPT_MASK__MASK_INTRPT1__MASK                      0x00000002U
#define PDM_INTERRUPT_MASK__MASK_INTRPT1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define PDM_INTERRUPT_MASK__MASK_INTRPT1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define PDM_INTERRUPT_MASK__MASK_INTRPT1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define PDM_INTERRUPT_MASK__MASK_INTRPT1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define PDM_INTERRUPT_MASK__MASK_INTRPT1__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define PDM_INTERRUPT_MASK__MASK_INTRPT1__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define PDM_INTERRUPT_MASK__MASK_INTRPT1__RESET_VALUE               0x00000001U
/** @} */

/* macros for field mask_intrpt2 */
/**
 * @defgroup at_apb_pdm_regs_core_mask_intrpt2_field mask_intrpt2_field
 * @brief macros for field mask_intrpt2
 * @details allow intrpt2 to propogate to core's single output interrupt
 * @{
 */
#define PDM_INTERRUPT_MASK__MASK_INTRPT2__SHIFT                               2
#define PDM_INTERRUPT_MASK__MASK_INTRPT2__WIDTH                               1
#define PDM_INTERRUPT_MASK__MASK_INTRPT2__MASK                      0x00000004U
#define PDM_INTERRUPT_MASK__MASK_INTRPT2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define PDM_INTERRUPT_MASK__MASK_INTRPT2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define PDM_INTERRUPT_MASK__MASK_INTRPT2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define PDM_INTERRUPT_MASK__MASK_INTRPT2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define PDM_INTERRUPT_MASK__MASK_INTRPT2__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define PDM_INTERRUPT_MASK__MASK_INTRPT2__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define PDM_INTERRUPT_MASK__MASK_INTRPT2__RESET_VALUE               0x00000001U
/** @} */

/* macros for field mask_intrpt3 */
/**
 * @defgroup at_apb_pdm_regs_core_mask_intrpt3_field mask_intrpt3_field
 * @brief macros for field mask_intrpt3
 * @details allow intrpt3 to propogate to core's single output interrupt
 * @{
 */
#define PDM_INTERRUPT_MASK__MASK_INTRPT3__SHIFT                               3
#define PDM_INTERRUPT_MASK__MASK_INTRPT3__WIDTH                               1
#define PDM_INTERRUPT_MASK__MASK_INTRPT3__MASK                      0x00000008U
#define PDM_INTERRUPT_MASK__MASK_INTRPT3__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000008U) >> 3)
#define PDM_INTERRUPT_MASK__MASK_INTRPT3__WRITE(src) \
                    (((uint32_t)(src)\
                    << 3) & 0x00000008U)
#define PDM_INTERRUPT_MASK__MASK_INTRPT3__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | (((uint32_t)(src) <<\
                    3) & 0x00000008U)
#define PDM_INTERRUPT_MASK__MASK_INTRPT3__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000008U)))
#define PDM_INTERRUPT_MASK__MASK_INTRPT3__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define PDM_INTERRUPT_MASK__MASK_INTRPT3__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)
#define PDM_INTERRUPT_MASK__MASK_INTRPT3__RESET_VALUE               0x00000001U
/** @} */

/* macros for field mask_intrpt4 */
/**
 * @defgroup at_apb_pdm_regs_core_mask_intrpt4_field mask_intrpt4_field
 * @brief macros for field mask_intrpt4
 * @details allow intrpt4 to propogate to core's single output interrupt
 * @{
 */
#define PDM_INTERRUPT_MASK__MASK_INTRPT4__SHIFT                               4
#define PDM_INTERRUPT_MASK__MASK_INTRPT4__WIDTH                               1
#define PDM_INTERRUPT_MASK__MASK_INTRPT4__MASK                      0x00000010U
#define PDM_INTERRUPT_MASK__MASK_INTRPT4__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000010U) >> 4)
#define PDM_INTERRUPT_MASK__MASK_INTRPT4__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x00000010U)
#define PDM_INTERRUPT_MASK__MASK_INTRPT4__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | (((uint32_t)(src) <<\
                    4) & 0x00000010U)
#define PDM_INTERRUPT_MASK__MASK_INTRPT4__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x00000010U)))
#define PDM_INTERRUPT_MASK__MASK_INTRPT4__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(1) << 4)
#define PDM_INTERRUPT_MASK__MASK_INTRPT4__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(0) << 4)
#define PDM_INTERRUPT_MASK__MASK_INTRPT4__RESET_VALUE               0x00000001U
/** @} */

/* macros for field mask_intrpt5 */
/**
 * @defgroup at_apb_pdm_regs_core_mask_intrpt5_field mask_intrpt5_field
 * @brief macros for field mask_intrpt5
 * @details allow intrpt5 to propogate to core's single output interrupt
 * @{
 */
#define PDM_INTERRUPT_MASK__MASK_INTRPT5__SHIFT                               5
#define PDM_INTERRUPT_MASK__MASK_INTRPT5__WIDTH                               1
#define PDM_INTERRUPT_MASK__MASK_INTRPT5__MASK                      0x00000020U
#define PDM_INTERRUPT_MASK__MASK_INTRPT5__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000020U) >> 5)
#define PDM_INTERRUPT_MASK__MASK_INTRPT5__WRITE(src) \
                    (((uint32_t)(src)\
                    << 5) & 0x00000020U)
#define PDM_INTERRUPT_MASK__MASK_INTRPT5__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | (((uint32_t)(src) <<\
                    5) & 0x00000020U)
#define PDM_INTERRUPT_MASK__MASK_INTRPT5__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 5) & ~0x00000020U)))
#define PDM_INTERRUPT_MASK__MASK_INTRPT5__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(1) << 5)
#define PDM_INTERRUPT_MASK__MASK_INTRPT5__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(0) << 5)
#define PDM_INTERRUPT_MASK__MASK_INTRPT5__RESET_VALUE               0x00000001U
/** @} */

/* macros for field mask_intrpt6 */
/**
 * @defgroup at_apb_pdm_regs_core_mask_intrpt6_field mask_intrpt6_field
 * @brief macros for field mask_intrpt6
 * @details allow intrpt6 to propogate to core's single output interrupt
 * @{
 */
#define PDM_INTERRUPT_MASK__MASK_INTRPT6__SHIFT                               6
#define PDM_INTERRUPT_MASK__MASK_INTRPT6__WIDTH                               1
#define PDM_INTERRUPT_MASK__MASK_INTRPT6__MASK                      0x00000040U
#define PDM_INTERRUPT_MASK__MASK_INTRPT6__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000040U) >> 6)
#define PDM_INTERRUPT_MASK__MASK_INTRPT6__WRITE(src) \
                    (((uint32_t)(src)\
                    << 6) & 0x00000040U)
#define PDM_INTERRUPT_MASK__MASK_INTRPT6__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | (((uint32_t)(src) <<\
                    6) & 0x00000040U)
#define PDM_INTERRUPT_MASK__MASK_INTRPT6__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 6) & ~0x00000040U)))
#define PDM_INTERRUPT_MASK__MASK_INTRPT6__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(1) << 6)
#define PDM_INTERRUPT_MASK__MASK_INTRPT6__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(0) << 6)
#define PDM_INTERRUPT_MASK__MASK_INTRPT6__RESET_VALUE               0x00000001U
/** @} */

/* macros for field mask_intrpt7 */
/**
 * @defgroup at_apb_pdm_regs_core_mask_intrpt7_field mask_intrpt7_field
 * @brief macros for field mask_intrpt7
 * @details allow intrpt7 to propogate to core's single output interrupt
 * @{
 */
#define PDM_INTERRUPT_MASK__MASK_INTRPT7__SHIFT                               7
#define PDM_INTERRUPT_MASK__MASK_INTRPT7__WIDTH                               1
#define PDM_INTERRUPT_MASK__MASK_INTRPT7__MASK                      0x00000080U
#define PDM_INTERRUPT_MASK__MASK_INTRPT7__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000080U) >> 7)
#define PDM_INTERRUPT_MASK__MASK_INTRPT7__WRITE(src) \
                    (((uint32_t)(src)\
                    << 7) & 0x00000080U)
#define PDM_INTERRUPT_MASK__MASK_INTRPT7__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | (((uint32_t)(src) <<\
                    7) & 0x00000080U)
#define PDM_INTERRUPT_MASK__MASK_INTRPT7__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 7) & ~0x00000080U)))
#define PDM_INTERRUPT_MASK__MASK_INTRPT7__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | ((uint32_t)(1) << 7)
#define PDM_INTERRUPT_MASK__MASK_INTRPT7__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | ((uint32_t)(0) << 7)
#define PDM_INTERRUPT_MASK__MASK_INTRPT7__RESET_VALUE               0x00000001U
/** @} */

/* macros for field mask_intrpt8 */
/**
 * @defgroup at_apb_pdm_regs_core_mask_intrpt8_field mask_intrpt8_field
 * @brief macros for field mask_intrpt8
 * @details allow intrpt8 to propogate to core's single output interrupt
 * @{
 */
#define PDM_INTERRUPT_MASK__MASK_INTRPT8__SHIFT                               8
#define PDM_INTERRUPT_MASK__MASK_INTRPT8__WIDTH                               1
#define PDM_INTERRUPT_MASK__MASK_INTRPT8__MASK                      0x00000100U
#define PDM_INTERRUPT_MASK__MASK_INTRPT8__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000100U) >> 8)
#define PDM_INTERRUPT_MASK__MASK_INTRPT8__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00000100U)
#define PDM_INTERRUPT_MASK__MASK_INTRPT8__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | (((uint32_t)(src) <<\
                    8) & 0x00000100U)
#define PDM_INTERRUPT_MASK__MASK_INTRPT8__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00000100U)))
#define PDM_INTERRUPT_MASK__MASK_INTRPT8__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | ((uint32_t)(1) << 8)
#define PDM_INTERRUPT_MASK__MASK_INTRPT8__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | ((uint32_t)(0) << 8)
#define PDM_INTERRUPT_MASK__MASK_INTRPT8__RESET_VALUE               0x00000001U
/** @} */

/* macros for field mask_intrpt9 */
/**
 * @defgroup at_apb_pdm_regs_core_mask_intrpt9_field mask_intrpt9_field
 * @brief macros for field mask_intrpt9
 * @details allow intrpt9 to propogate to core's single output interrupt
 * @{
 */
#define PDM_INTERRUPT_MASK__MASK_INTRPT9__SHIFT                               9
#define PDM_INTERRUPT_MASK__MASK_INTRPT9__WIDTH                               1
#define PDM_INTERRUPT_MASK__MASK_INTRPT9__MASK                      0x00000200U
#define PDM_INTERRUPT_MASK__MASK_INTRPT9__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000200U) >> 9)
#define PDM_INTERRUPT_MASK__MASK_INTRPT9__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x00000200U)
#define PDM_INTERRUPT_MASK__MASK_INTRPT9__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | (((uint32_t)(src) <<\
                    9) & 0x00000200U)
#define PDM_INTERRUPT_MASK__MASK_INTRPT9__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x00000200U)))
#define PDM_INTERRUPT_MASK__MASK_INTRPT9__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | ((uint32_t)(1) << 9)
#define PDM_INTERRUPT_MASK__MASK_INTRPT9__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | ((uint32_t)(0) << 9)
#define PDM_INTERRUPT_MASK__MASK_INTRPT9__RESET_VALUE               0x00000001U
/** @} */
#define PDM_INTERRUPT_MASK__TYPE                                       uint32_t
#define PDM_INTERRUPT_MASK__READ                                    0x000003ffU
#define PDM_INTERRUPT_MASK__WRITE                                   0x000003ffU
#define PDM_INTERRUPT_MASK__PRESERVED                               0x00000000U
#define PDM_INTERRUPT_MASK__RESET_VALUE                             0x000003ffU

#endif /* __PDM_INTERRUPT_MASK_MACRO__ */

/** @} end of interrupt_mask */

/* macros for BlueprintGlobalNameSpace::PDM_interrupt_clear */
/**
 * @defgroup at_apb_pdm_regs_core_interrupt_clear interrupt_clear
 * @brief Contains register fields associated with interrupt_clear. definitions.
 * @{
 */
#ifndef __PDM_INTERRUPT_CLEAR_MACRO__
#define __PDM_INTERRUPT_CLEAR_MACRO__

/* macros for field clear_intrpt0 */
/**
 * @defgroup at_apb_pdm_regs_core_clear_intrpt0_field clear_intrpt0_field
 * @brief macros for field clear_intrpt0
 * @details clear interrupt 0; not self reseting
 * @{
 */
#define PDM_INTERRUPT_CLEAR__CLEAR_INTRPT0__SHIFT                             0
#define PDM_INTERRUPT_CLEAR__CLEAR_INTRPT0__WIDTH                             1
#define PDM_INTERRUPT_CLEAR__CLEAR_INTRPT0__MASK                    0x00000001U
#define PDM_INTERRUPT_CLEAR__CLEAR_INTRPT0__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define PDM_INTERRUPT_CLEAR__CLEAR_INTRPT0__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define PDM_INTERRUPT_CLEAR__CLEAR_INTRPT0__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define PDM_INTERRUPT_CLEAR__CLEAR_INTRPT0__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define PDM_INTERRUPT_CLEAR__CLEAR_INTRPT0__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define PDM_INTERRUPT_CLEAR__CLEAR_INTRPT0__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define PDM_INTERRUPT_CLEAR__CLEAR_INTRPT0__RESET_VALUE             0x00000000U
/** @} */

/* macros for field clear_intrpt1 */
/**
 * @defgroup at_apb_pdm_regs_core_clear_intrpt1_field clear_intrpt1_field
 * @brief macros for field clear_intrpt1
 * @details clear interrupt 1; not self reseting
 * @{
 */
#define PDM_INTERRUPT_CLEAR__CLEAR_INTRPT1__SHIFT                             1
#define PDM_INTERRUPT_CLEAR__CLEAR_INTRPT1__WIDTH                             1
#define PDM_INTERRUPT_CLEAR__CLEAR_INTRPT1__MASK                    0x00000002U
#define PDM_INTERRUPT_CLEAR__CLEAR_INTRPT1__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000002U) >> 1)
#define PDM_INTERRUPT_CLEAR__CLEAR_INTRPT1__WRITE(src) \
                    (((uint32_t)(src)\
                    << 1) & 0x00000002U)
#define PDM_INTERRUPT_CLEAR__CLEAR_INTRPT1__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | (((uint32_t)(src) <<\
                    1) & 0x00000002U)
#define PDM_INTERRUPT_CLEAR__CLEAR_INTRPT1__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 1) & ~0x00000002U)))
#define PDM_INTERRUPT_CLEAR__CLEAR_INTRPT1__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(1) << 1)
#define PDM_INTERRUPT_CLEAR__CLEAR_INTRPT1__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000002U) | ((uint32_t)(0) << 1)
#define PDM_INTERRUPT_CLEAR__CLEAR_INTRPT1__RESET_VALUE             0x00000000U
/** @} */

/* macros for field clear_intrpt2 */
/**
 * @defgroup at_apb_pdm_regs_core_clear_intrpt2_field clear_intrpt2_field
 * @brief macros for field clear_intrpt2
 * @details clear interrupt 2; not self reseting
 * @{
 */
#define PDM_INTERRUPT_CLEAR__CLEAR_INTRPT2__SHIFT                             2
#define PDM_INTERRUPT_CLEAR__CLEAR_INTRPT2__WIDTH                             1
#define PDM_INTERRUPT_CLEAR__CLEAR_INTRPT2__MASK                    0x00000004U
#define PDM_INTERRUPT_CLEAR__CLEAR_INTRPT2__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000004U) >> 2)
#define PDM_INTERRUPT_CLEAR__CLEAR_INTRPT2__WRITE(src) \
                    (((uint32_t)(src)\
                    << 2) & 0x00000004U)
#define PDM_INTERRUPT_CLEAR__CLEAR_INTRPT2__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | (((uint32_t)(src) <<\
                    2) & 0x00000004U)
#define PDM_INTERRUPT_CLEAR__CLEAR_INTRPT2__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 2) & ~0x00000004U)))
#define PDM_INTERRUPT_CLEAR__CLEAR_INTRPT2__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(1) << 2)
#define PDM_INTERRUPT_CLEAR__CLEAR_INTRPT2__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000004U) | ((uint32_t)(0) << 2)
#define PDM_INTERRUPT_CLEAR__CLEAR_INTRPT2__RESET_VALUE             0x00000000U
/** @} */

/* macros for field clear_intrpt3 */
/**
 * @defgroup at_apb_pdm_regs_core_clear_intrpt3_field clear_intrpt3_field
 * @brief macros for field clear_intrpt3
 * @details clear interrupt 3; not self reseting
 * @{
 */
#define PDM_INTERRUPT_CLEAR__CLEAR_INTRPT3__SHIFT                             3
#define PDM_INTERRUPT_CLEAR__CLEAR_INTRPT3__WIDTH                             1
#define PDM_INTERRUPT_CLEAR__CLEAR_INTRPT3__MASK                    0x00000008U
#define PDM_INTERRUPT_CLEAR__CLEAR_INTRPT3__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000008U) >> 3)
#define PDM_INTERRUPT_CLEAR__CLEAR_INTRPT3__WRITE(src) \
                    (((uint32_t)(src)\
                    << 3) & 0x00000008U)
#define PDM_INTERRUPT_CLEAR__CLEAR_INTRPT3__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | (((uint32_t)(src) <<\
                    3) & 0x00000008U)
#define PDM_INTERRUPT_CLEAR__CLEAR_INTRPT3__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 3) & ~0x00000008U)))
#define PDM_INTERRUPT_CLEAR__CLEAR_INTRPT3__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(1) << 3)
#define PDM_INTERRUPT_CLEAR__CLEAR_INTRPT3__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000008U) | ((uint32_t)(0) << 3)
#define PDM_INTERRUPT_CLEAR__CLEAR_INTRPT3__RESET_VALUE             0x00000000U
/** @} */

/* macros for field clear_intrpt4 */
/**
 * @defgroup at_apb_pdm_regs_core_clear_intrpt4_field clear_intrpt4_field
 * @brief macros for field clear_intrpt4
 * @details clear interrupt 4; not self reseting
 * @{
 */
#define PDM_INTERRUPT_CLEAR__CLEAR_INTRPT4__SHIFT                             4
#define PDM_INTERRUPT_CLEAR__CLEAR_INTRPT4__WIDTH                             1
#define PDM_INTERRUPT_CLEAR__CLEAR_INTRPT4__MASK                    0x00000010U
#define PDM_INTERRUPT_CLEAR__CLEAR_INTRPT4__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000010U) >> 4)
#define PDM_INTERRUPT_CLEAR__CLEAR_INTRPT4__WRITE(src) \
                    (((uint32_t)(src)\
                    << 4) & 0x00000010U)
#define PDM_INTERRUPT_CLEAR__CLEAR_INTRPT4__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | (((uint32_t)(src) <<\
                    4) & 0x00000010U)
#define PDM_INTERRUPT_CLEAR__CLEAR_INTRPT4__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 4) & ~0x00000010U)))
#define PDM_INTERRUPT_CLEAR__CLEAR_INTRPT4__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(1) << 4)
#define PDM_INTERRUPT_CLEAR__CLEAR_INTRPT4__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000010U) | ((uint32_t)(0) << 4)
#define PDM_INTERRUPT_CLEAR__CLEAR_INTRPT4__RESET_VALUE             0x00000000U
/** @} */

/* macros for field clear_intrpt5 */
/**
 * @defgroup at_apb_pdm_regs_core_clear_intrpt5_field clear_intrpt5_field
 * @brief macros for field clear_intrpt5
 * @details clear interrupt 5; not self reseting
 * @{
 */
#define PDM_INTERRUPT_CLEAR__CLEAR_INTRPT5__SHIFT                             5
#define PDM_INTERRUPT_CLEAR__CLEAR_INTRPT5__WIDTH                             1
#define PDM_INTERRUPT_CLEAR__CLEAR_INTRPT5__MASK                    0x00000020U
#define PDM_INTERRUPT_CLEAR__CLEAR_INTRPT5__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000020U) >> 5)
#define PDM_INTERRUPT_CLEAR__CLEAR_INTRPT5__WRITE(src) \
                    (((uint32_t)(src)\
                    << 5) & 0x00000020U)
#define PDM_INTERRUPT_CLEAR__CLEAR_INTRPT5__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | (((uint32_t)(src) <<\
                    5) & 0x00000020U)
#define PDM_INTERRUPT_CLEAR__CLEAR_INTRPT5__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 5) & ~0x00000020U)))
#define PDM_INTERRUPT_CLEAR__CLEAR_INTRPT5__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(1) << 5)
#define PDM_INTERRUPT_CLEAR__CLEAR_INTRPT5__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000020U) | ((uint32_t)(0) << 5)
#define PDM_INTERRUPT_CLEAR__CLEAR_INTRPT5__RESET_VALUE             0x00000000U
/** @} */

/* macros for field clear_intrpt6 */
/**
 * @defgroup at_apb_pdm_regs_core_clear_intrpt6_field clear_intrpt6_field
 * @brief macros for field clear_intrpt6
 * @details clear interrupt 6; not self reseting
 * @{
 */
#define PDM_INTERRUPT_CLEAR__CLEAR_INTRPT6__SHIFT                             6
#define PDM_INTERRUPT_CLEAR__CLEAR_INTRPT6__WIDTH                             1
#define PDM_INTERRUPT_CLEAR__CLEAR_INTRPT6__MASK                    0x00000040U
#define PDM_INTERRUPT_CLEAR__CLEAR_INTRPT6__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000040U) >> 6)
#define PDM_INTERRUPT_CLEAR__CLEAR_INTRPT6__WRITE(src) \
                    (((uint32_t)(src)\
                    << 6) & 0x00000040U)
#define PDM_INTERRUPT_CLEAR__CLEAR_INTRPT6__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | (((uint32_t)(src) <<\
                    6) & 0x00000040U)
#define PDM_INTERRUPT_CLEAR__CLEAR_INTRPT6__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 6) & ~0x00000040U)))
#define PDM_INTERRUPT_CLEAR__CLEAR_INTRPT6__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(1) << 6)
#define PDM_INTERRUPT_CLEAR__CLEAR_INTRPT6__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000040U) | ((uint32_t)(0) << 6)
#define PDM_INTERRUPT_CLEAR__CLEAR_INTRPT6__RESET_VALUE             0x00000000U
/** @} */

/* macros for field clear_intrpt7 */
/**
 * @defgroup at_apb_pdm_regs_core_clear_intrpt7_field clear_intrpt7_field
 * @brief macros for field clear_intrpt7
 * @details clear interrupt 7; not self reseting
 * @{
 */
#define PDM_INTERRUPT_CLEAR__CLEAR_INTRPT7__SHIFT                             7
#define PDM_INTERRUPT_CLEAR__CLEAR_INTRPT7__WIDTH                             1
#define PDM_INTERRUPT_CLEAR__CLEAR_INTRPT7__MASK                    0x00000080U
#define PDM_INTERRUPT_CLEAR__CLEAR_INTRPT7__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000080U) >> 7)
#define PDM_INTERRUPT_CLEAR__CLEAR_INTRPT7__WRITE(src) \
                    (((uint32_t)(src)\
                    << 7) & 0x00000080U)
#define PDM_INTERRUPT_CLEAR__CLEAR_INTRPT7__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | (((uint32_t)(src) <<\
                    7) & 0x00000080U)
#define PDM_INTERRUPT_CLEAR__CLEAR_INTRPT7__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 7) & ~0x00000080U)))
#define PDM_INTERRUPT_CLEAR__CLEAR_INTRPT7__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | ((uint32_t)(1) << 7)
#define PDM_INTERRUPT_CLEAR__CLEAR_INTRPT7__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000080U) | ((uint32_t)(0) << 7)
#define PDM_INTERRUPT_CLEAR__CLEAR_INTRPT7__RESET_VALUE             0x00000000U
/** @} */

/* macros for field clear_intrpt8 */
/**
 * @defgroup at_apb_pdm_regs_core_clear_intrpt8_field clear_intrpt8_field
 * @brief macros for field clear_intrpt8
 * @details clear interrupt 8; not self reseting
 * @{
 */
#define PDM_INTERRUPT_CLEAR__CLEAR_INTRPT8__SHIFT                             8
#define PDM_INTERRUPT_CLEAR__CLEAR_INTRPT8__WIDTH                             1
#define PDM_INTERRUPT_CLEAR__CLEAR_INTRPT8__MASK                    0x00000100U
#define PDM_INTERRUPT_CLEAR__CLEAR_INTRPT8__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000100U) >> 8)
#define PDM_INTERRUPT_CLEAR__CLEAR_INTRPT8__WRITE(src) \
                    (((uint32_t)(src)\
                    << 8) & 0x00000100U)
#define PDM_INTERRUPT_CLEAR__CLEAR_INTRPT8__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | (((uint32_t)(src) <<\
                    8) & 0x00000100U)
#define PDM_INTERRUPT_CLEAR__CLEAR_INTRPT8__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 8) & ~0x00000100U)))
#define PDM_INTERRUPT_CLEAR__CLEAR_INTRPT8__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | ((uint32_t)(1) << 8)
#define PDM_INTERRUPT_CLEAR__CLEAR_INTRPT8__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000100U) | ((uint32_t)(0) << 8)
#define PDM_INTERRUPT_CLEAR__CLEAR_INTRPT8__RESET_VALUE             0x00000000U
/** @} */

/* macros for field clear_intrpt9 */
/**
 * @defgroup at_apb_pdm_regs_core_clear_intrpt9_field clear_intrpt9_field
 * @brief macros for field clear_intrpt9
 * @details clear interrupt 9; not self reseting
 * @{
 */
#define PDM_INTERRUPT_CLEAR__CLEAR_INTRPT9__SHIFT                             9
#define PDM_INTERRUPT_CLEAR__CLEAR_INTRPT9__WIDTH                             1
#define PDM_INTERRUPT_CLEAR__CLEAR_INTRPT9__MASK                    0x00000200U
#define PDM_INTERRUPT_CLEAR__CLEAR_INTRPT9__READ(src) \
                    (((uint32_t)(src)\
                    & 0x00000200U) >> 9)
#define PDM_INTERRUPT_CLEAR__CLEAR_INTRPT9__WRITE(src) \
                    (((uint32_t)(src)\
                    << 9) & 0x00000200U)
#define PDM_INTERRUPT_CLEAR__CLEAR_INTRPT9__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | (((uint32_t)(src) <<\
                    9) & 0x00000200U)
#define PDM_INTERRUPT_CLEAR__CLEAR_INTRPT9__VERIFY(src) \
                    (!((((uint32_t)(src)\
                    << 9) & ~0x00000200U)))
#define PDM_INTERRUPT_CLEAR__CLEAR_INTRPT9__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | ((uint32_t)(1) << 9)
#define PDM_INTERRUPT_CLEAR__CLEAR_INTRPT9__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000200U) | ((uint32_t)(0) << 9)
#define PDM_INTERRUPT_CLEAR__CLEAR_INTRPT9__RESET_VALUE             0x00000000U
/** @} */
#define PDM_INTERRUPT_CLEAR__TYPE                                      uint32_t
#define PDM_INTERRUPT_CLEAR__READ                                   0x000003ffU
#define PDM_INTERRUPT_CLEAR__WRITE                                  0x000003ffU
#define PDM_INTERRUPT_CLEAR__PRESERVED                              0x00000000U
#define PDM_INTERRUPT_CLEAR__RESET_VALUE                            0x00000000U

#endif /* __PDM_INTERRUPT_CLEAR_MACRO__ */

/** @} end of interrupt_clear */

/* macros for BlueprintGlobalNameSpace::PDM_buffer_access_mode */
/**
 * @defgroup at_apb_pdm_regs_core_buffer_access_mode buffer_access_mode
 * @brief Contains register fields associated with buffer_access_mode. definitions.
 * @{
 */
#ifndef __PDM_BUFFER_ACCESS_MODE_MACRO__
#define __PDM_BUFFER_ACCESS_MODE_MACRO__

/* macros for field dma_mode */
/**
 * @defgroup at_apb_pdm_regs_core_dma_mode_field dma_mode_field
 * @brief macros for field dma_mode
 * @details 1= pingpong buffer has fifo-like interface.  read address is auto-incremented from base address of buffer A by an internal counter, counting from 0 to 63 and wraps around.  buffer full interrupt is cleared by HW at the end of the last read of the buffer.  The auto-increment counter is cleared when fifo_mode is 0.
 * @{
 */
#define PDM_BUFFER_ACCESS_MODE__DMA_MODE__SHIFT                               0
#define PDM_BUFFER_ACCESS_MODE__DMA_MODE__WIDTH                               1
#define PDM_BUFFER_ACCESS_MODE__DMA_MODE__MASK                      0x00000001U
#define PDM_BUFFER_ACCESS_MODE__DMA_MODE__READ(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define PDM_BUFFER_ACCESS_MODE__DMA_MODE__WRITE(src) \
                    ((uint32_t)(src)\
                    & 0x00000001U)
#define PDM_BUFFER_ACCESS_MODE__DMA_MODE__MODIFY(dst, src) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | ((uint32_t)(src) &\
                    0x00000001U)
#define PDM_BUFFER_ACCESS_MODE__DMA_MODE__VERIFY(src) \
                    (!(((uint32_t)(src)\
                    & ~0x00000001U)))
#define PDM_BUFFER_ACCESS_MODE__DMA_MODE__SET(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(1)
#define PDM_BUFFER_ACCESS_MODE__DMA_MODE__CLR(dst) \
                    (dst) = ((dst) &\
                    ~0x00000001U) | (uint32_t)(0)
#define PDM_BUFFER_ACCESS_MODE__DMA_MODE__RESET_VALUE               0x00000000U
/** @} */
#define PDM_BUFFER_ACCESS_MODE__TYPE                                   uint32_t
#define PDM_BUFFER_ACCESS_MODE__READ                                0x00000001U
#define PDM_BUFFER_ACCESS_MODE__WRITE                               0x00000001U
#define PDM_BUFFER_ACCESS_MODE__PRESERVED                           0x00000000U
#define PDM_BUFFER_ACCESS_MODE__RESET_VALUE                         0x00000000U

#endif /* __PDM_BUFFER_ACCESS_MODE_MACRO__ */

/** @} end of buffer_access_mode */

/* macros for BlueprintGlobalNameSpace::PDM_auto_counter */
/**
 * @defgroup at_apb_pdm_regs_core_auto_counter auto_counter
 * @brief Contains register fields associated with auto_counter. definitions.
 * @{
 */
#ifndef __PDM_AUTO_COUNTER_MACRO__
#define __PDM_AUTO_COUNTER_MACRO__

/* macros for field count */
/**
 * @defgroup at_apb_pdm_regs_core_count_field count_field
 * @brief macros for field count
 * @details current value of the auto increment counter.
 * @{
 */
#define PDM_AUTO_COUNTER__COUNT__SHIFT                                        0
#define PDM_AUTO_COUNTER__COUNT__WIDTH                                        6
#define PDM_AUTO_COUNTER__COUNT__MASK                               0x0000003fU
#define PDM_AUTO_COUNTER__COUNT__READ(src)      ((uint32_t)(src) & 0x0000003fU)
#define PDM_AUTO_COUNTER__COUNT__RESET_VALUE                        0x00000000U
/** @} */
#define PDM_AUTO_COUNTER__TYPE                                         uint32_t
#define PDM_AUTO_COUNTER__READ                                      0x0000003fU
#define PDM_AUTO_COUNTER__PRESERVED                                 0x00000000U
#define PDM_AUTO_COUNTER__RESET_VALUE                               0x00000000U

#endif /* __PDM_AUTO_COUNTER_MACRO__ */

/** @} end of auto_counter */

/* macros for BlueprintGlobalNameSpace::PDM_buffer_depth */
/**
 * @defgroup at_apb_pdm_regs_core_buffer_depth buffer_depth
 * @brief Contains register fields associated with buffer_depth. definitions.
 * @{
 */
#ifndef __PDM_BUFFER_DEPTH_MACRO__
#define __PDM_BUFFER_DEPTH_MACRO__

/* macros for field depth */
/**
 * @defgroup at_apb_pdm_regs_core_depth_field depth_field
 * @brief macros for field depth
 * @details one buffer depth
 * @{
 */
#define PDM_BUFFER_DEPTH__DEPTH__SHIFT                                        0
#define PDM_BUFFER_DEPTH__DEPTH__WIDTH                                        5
#define PDM_BUFFER_DEPTH__DEPTH__MASK                               0x0000001fU
#define PDM_BUFFER_DEPTH__DEPTH__READ(src)      ((uint32_t)(src) & 0x0000001fU)
#define PDM_BUFFER_DEPTH__DEPTH__RESET_VALUE                        0x00000010U
/** @} */
#define PDM_BUFFER_DEPTH__TYPE                                         uint32_t
#define PDM_BUFFER_DEPTH__READ                                      0x0000001fU
#define PDM_BUFFER_DEPTH__PRESERVED                                 0x00000000U
#define PDM_BUFFER_DEPTH__RESET_VALUE                               0x00000010U

#endif /* __PDM_BUFFER_DEPTH_MACRO__ */

/** @} end of buffer_depth */

/* macros for BlueprintGlobalNameSpace::PDM_core_id */
/**
 * @defgroup at_apb_pdm_regs_core_core_id core_id
 * @brief Contains register fields associated with core_id. definitions.
 * @{
 */
#ifndef __PDM_CORE_ID_MACRO__
#define __PDM_CORE_ID_MACRO__

/* macros for field id */
/**
 * @defgroup at_apb_pdm_regs_core_id_field id_field
 * @brief macros for field id
 * @details 'PDM ' in ASCII
 * @{
 */
#define PDM_CORE_ID__ID__SHIFT                                                0
#define PDM_CORE_ID__ID__WIDTH                                               32
#define PDM_CORE_ID__ID__MASK                                       0xffffffffU
#define PDM_CORE_ID__ID__READ(src)              ((uint32_t)(src) & 0xffffffffU)
#define PDM_CORE_ID__ID__RESET_VALUE                                0x50444d20U
/** @} */
#define PDM_CORE_ID__TYPE                                              uint32_t
#define PDM_CORE_ID__READ                                           0xffffffffU
#define PDM_CORE_ID__PRESERVED                                      0x00000000U
#define PDM_CORE_ID__RESET_VALUE                                    0x50444d20U

#endif /* __PDM_CORE_ID_MACRO__ */

/** @} end of core_id */

/* macros for BlueprintGlobalNameSpace::PDM_rev_hash */
/**
 * @defgroup at_apb_pdm_regs_core_rev_hash rev_hash
 * @brief Contains register fields associated with rev_hash. definitions.
 * @{
 */
#ifndef __PDM_REV_HASH_MACRO__
#define __PDM_REV_HASH_MACRO__

/* macros for field id */
/**
 * @defgroup at_apb_pdm_regs_core_id_field id_field
 * @brief macros for field id
 * @details crc32 of this document; don't change value to anything other than 32'h00000000; scripts will fill it out in the verilog
 * @{
 */
#define PDM_REV_HASH__ID__SHIFT                                               0
#define PDM_REV_HASH__ID__WIDTH                                              32
#define PDM_REV_HASH__ID__MASK                                      0xffffffffU
#define PDM_REV_HASH__ID__READ(src)             ((uint32_t)(src) & 0xffffffffU)
#define PDM_REV_HASH__ID__RESET_VALUE                               0x00000000U
/** @} */
#define PDM_REV_HASH__TYPE                                             uint32_t
#define PDM_REV_HASH__READ                                          0xffffffffU
#define PDM_REV_HASH__PRESERVED                                     0x00000000U
#define PDM_REV_HASH__RESET_VALUE                                   0x00000000U

#endif /* __PDM_REV_HASH_MACRO__ */

/** @} end of rev_hash */

/* macros for BlueprintGlobalNameSpace::PDM_rev_key */
/**
 * @defgroup at_apb_pdm_regs_core_rev_key rev_key
 * @brief Contains register fields associated with rev_key. definitions.
 * @{
 */
#ifndef __PDM_REV_KEY_MACRO__
#define __PDM_REV_KEY_MACRO__

/* macros for field id */
/**
 * @defgroup at_apb_pdm_regs_core_id_field id_field
 * @brief macros for field id
 * @details REV in ASCII
 * @{
 */
#define PDM_REV_KEY__ID__SHIFT                                                0
#define PDM_REV_KEY__ID__WIDTH                                               32
#define PDM_REV_KEY__ID__MASK                                       0xffffffffU
#define PDM_REV_KEY__ID__READ(src)              ((uint32_t)(src) & 0xffffffffU)
#define PDM_REV_KEY__ID__RESET_VALUE                                0x52455620U
/** @} */
#define PDM_REV_KEY__TYPE                                              uint32_t
#define PDM_REV_KEY__READ                                           0xffffffffU
#define PDM_REV_KEY__PRESERVED                                      0x00000000U
#define PDM_REV_KEY__RESET_VALUE                                    0x52455620U

#endif /* __PDM_REV_KEY_MACRO__ */

/** @} end of rev_key */

/** @} end of AT_APB_PDM_REGS_CORE */
#endif /* __REG_AT_APB_PDM_REGS_CORE_H__ */
