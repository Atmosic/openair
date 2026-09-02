//-----------------------------------------------------------------------------
// The confidential and proprietary information contained in this file may
// only be used by a person authorised under and to the extent permitted
// by a subsisting licensing agreement from Atmosic.
//
//            (C) COPYRIGHT 2017-2022 Atmosic
//                ALL RIGHTS RESERVED
//
// This entire notice must be reproduced on all copies of this file
// and copies of this file may only be made by a person if such person is
// permitted to do so under the terms of a subsisting license agreement
// from Atmosic.
//
// This file defines DESCRIPTOR for LC
// THIS FILE IS AUTO-GENERATED, PLEASE DO NOT MODIFY.
//-----------------------------------------------------------------------------


#ifndef __AT_LC_DESCRIPTOR_MACRO_H__
#define __AT_LC_DESCRIPTOR_MACRO_H__

/**
 * @defgroup atlc_TxDescriptor_wrd0
 * @brief TxDescriptorWord0Macro
 * @{
 */
#ifndef __ATCL_TXDESCRIPTOR_WRD0_MACRO__

#define __ATCL_TXDESCRIPTOR_WRD0_MACRO__


/**
 * @defgroup atlc_TxDescriptor_wrd0 TxPower 
 * @brief macro for field TxPower
 * @{
 */
#define ATLC_TXDESCRIPTOR_WRD0__TXPOWER__SHIFT                               26
#define ATLC_TXDESCRIPTOR_WRD0__TXPOWER__WIDTH                                4
#define ATLC_TXDESCRIPTOR_WRD0__TXPOWER__MASK                       0x3C000000U
#define ATLC_TXDESCRIPTOR_WRD0__TXPOWER__READ(src) \
					(((uint32_t)(src) \
					& 0x3C000000U) >> 26)
#define ATLC_TXDESCRIPTOR_WRD0__TXPOWER__WRITE(src) \
					(((uint32_t)(src) \
					<< 26) & 0x3C000000U)
#define ATLC_TXDESCRIPTOR_WRD0__TXPOWER__MODIFY(dst, src) \
					(dst) = ((dst) &\
					~0x3C000000U) | (((uint32_t)(src) <<\
					26) & 0x3C000000U)
#define ATLC_TXDESCRIPTOR_WRD0__TXPOWER__VERIFY(src) \
					(!((((uint32_t)(src) \
					<< 26) & ~0x3C000000U)))
#define ATLC_TXDESCRIPTOR_WRD0__TXPOWER__RESET                      0x00000000U
/** @} */
/**
 * @defgroup atlc_TxDescriptor_wrd0 ChannelIndex 
 * @brief macro for field ChannelIndex
 * @{
 */
#define ATLC_TXDESCRIPTOR_WRD0__CHANNELINDEX__SHIFT                          17
#define ATLC_TXDESCRIPTOR_WRD0__CHANNELINDEX__WIDTH                           7
#define ATLC_TXDESCRIPTOR_WRD0__CHANNELINDEX__MASK                  0x00FE0000U
#define ATLC_TXDESCRIPTOR_WRD0__CHANNELINDEX__READ(src) \
					(((uint32_t)(src) \
					& 0x00FE0000U) >> 17)
#define ATLC_TXDESCRIPTOR_WRD0__CHANNELINDEX__WRITE(src) \
					(((uint32_t)(src) \
					<< 17) & 0x00FE0000U)
#define ATLC_TXDESCRIPTOR_WRD0__CHANNELINDEX__MODIFY(dst, src) \
					(dst) = ((dst) &\
					~0x00FE0000U) | (((uint32_t)(src) <<\
					17) & 0x00FE0000U)
#define ATLC_TXDESCRIPTOR_WRD0__CHANNELINDEX__VERIFY(src) \
					(!((((uint32_t)(src) \
					<< 17) & ~0x00FE0000U)))
#define ATLC_TXDESCRIPTOR_WRD0__CHANNELINDEX__RESET                 0x00000000U
/** @} */
/**
 * @defgroup atlc_TxDescriptor_wrd0 MICLen 
 * @brief macro for field MICLen
 * @{
 */
#define ATLC_TXDESCRIPTOR_WRD0__MICLEN__SHIFT                                14
#define ATLC_TXDESCRIPTOR_WRD0__MICLEN__WIDTH                                 2
#define ATLC_TXDESCRIPTOR_WRD0__MICLEN__MASK                        0x0000C000U
#define ATLC_TXDESCRIPTOR_WRD0__MICLEN__READ(src) \
					(((uint32_t)(src) \
					& 0x0000C000U) >> 14)
#define ATLC_TXDESCRIPTOR_WRD0__MICLEN__WRITE(src) \
					(((uint32_t)(src) \
					<< 14) & 0x0000C000U)
#define ATLC_TXDESCRIPTOR_WRD0__MICLEN__MODIFY(dst, src) \
					(dst) = ((dst) &\
					~0x0000C000U) | (((uint32_t)(src) <<\
					14) & 0x0000C000U)
#define ATLC_TXDESCRIPTOR_WRD0__MICLEN__VERIFY(src) \
					(!((((uint32_t)(src) \
					<< 14) & ~0x0000C000U)))
#define ATLC_TXDESCRIPTOR_WRD0__MICLEN__RESET                       0x00000000U
/** @} */
/**
 * @defgroup atlc_TxDescriptor_wrd0 CryptEn 
 * @brief macro for field CryptEn
 * @{
 */
#define ATLC_TXDESCRIPTOR_WRD0__CRYPTEN__SHIFT                               13
#define ATLC_TXDESCRIPTOR_WRD0__CRYPTEN__WIDTH                                1
#define ATLC_TXDESCRIPTOR_WRD0__CRYPTEN__MASK                       0x00002000U
#define ATLC_TXDESCRIPTOR_WRD0__CRYPTEN__READ(src) \
					(((uint32_t)(src) \
					& 0x00002000U) >> 13)
#define ATLC_TXDESCRIPTOR_WRD0__CRYPTEN__WRITE(src) \
					(((uint32_t)(src) \
					<< 13) & 0x00002000U)
#define ATLC_TXDESCRIPTOR_WRD0__CRYPTEN__MODIFY(dst, src) \
					(dst) = ((dst) &\
					~0x00002000U) | (((uint32_t)(src) <<\
					13) & 0x00002000U)
#define ATLC_TXDESCRIPTOR_WRD0__CRYPTEN__VERIFY(src) \
					(!((((uint32_t)(src) \
					<< 13) & ~0x00002000U)))
#define ATLC_TXDESCRIPTOR_WRD0__CRYPTEN__RESET                      0x00000000U
/** @} */
/**
 * @defgroup atlc_TxDescriptor_wrd0 WhiteEn 
 * @brief macro for field WhiteEn
 * @{
 */
#define ATLC_TXDESCRIPTOR_WRD0__WHITEEN__SHIFT                               12
#define ATLC_TXDESCRIPTOR_WRD0__WHITEEN__WIDTH                                1
#define ATLC_TXDESCRIPTOR_WRD0__WHITEEN__MASK                       0x00001000U
#define ATLC_TXDESCRIPTOR_WRD0__WHITEEN__READ(src) \
					(((uint32_t)(src) \
					& 0x00001000U) >> 12)
#define ATLC_TXDESCRIPTOR_WRD0__WHITEEN__WRITE(src) \
					(((uint32_t)(src) \
					<< 12) & 0x00001000U)
#define ATLC_TXDESCRIPTOR_WRD0__WHITEEN__MODIFY(dst, src) \
					(dst) = ((dst) &\
					~0x00001000U) | (((uint32_t)(src) <<\
					12) & 0x00001000U)
#define ATLC_TXDESCRIPTOR_WRD0__WHITEEN__VERIFY(src) \
					(!((((uint32_t)(src) \
					<< 12) & ~0x00001000U)))
#define ATLC_TXDESCRIPTOR_WRD0__WHITEEN__RESET                      0x00000000U
/** @} */
/**
 * @defgroup atlc_TxDescriptor_wrd0 CRCEn 
 * @brief macro for field CRCEn
 * @{
 */
#define ATLC_TXDESCRIPTOR_WRD0__CRCEN__SHIFT                                 11
#define ATLC_TXDESCRIPTOR_WRD0__CRCEN__WIDTH                                  1
#define ATLC_TXDESCRIPTOR_WRD0__CRCEN__MASK                         0x00000800U
#define ATLC_TXDESCRIPTOR_WRD0__CRCEN__READ(src) \
					(((uint32_t)(src) \
					& 0x00000800U) >> 11)
#define ATLC_TXDESCRIPTOR_WRD0__CRCEN__WRITE(src) \
					(((uint32_t)(src) \
					<< 11) & 0x00000800U)
#define ATLC_TXDESCRIPTOR_WRD0__CRCEN__MODIFY(dst, src) \
					(dst) = ((dst) &\
					~0x00000800U) | (((uint32_t)(src) <<\
					11) & 0x00000800U)
#define ATLC_TXDESCRIPTOR_WRD0__CRCEN__VERIFY(src) \
					(!((((uint32_t)(src) \
					<< 11) & ~0x00000800U)))
#define ATLC_TXDESCRIPTOR_WRD0__CRCEN__RESET                        0x00000000U
/** @} */
/**
 * @defgroup atlc_TxDescriptor_wrd0 Rate 
 * @brief macro for field Rate
 * @{
 */
#define ATLC_TXDESCRIPTOR_WRD0__RATE__SHIFT                                   6
#define ATLC_TXDESCRIPTOR_WRD0__RATE__WIDTH                                   4
#define ATLC_TXDESCRIPTOR_WRD0__RATE__MASK                          0x000003C0U
#define ATLC_TXDESCRIPTOR_WRD0__RATE__READ(src) \
					(((uint32_t)(src) \
					& 0x000003C0U) >> 6)
#define ATLC_TXDESCRIPTOR_WRD0__RATE__WRITE(src) \
					(((uint32_t)(src) \
					<< 6) & 0x000003C0U)
#define ATLC_TXDESCRIPTOR_WRD0__RATE__MODIFY(dst, src) \
					(dst) = ((dst) &\
					~0x000003C0U) | (((uint32_t)(src) <<\
					6) & 0x000003C0U)
#define ATLC_TXDESCRIPTOR_WRD0__RATE__VERIFY(src) \
					(!((((uint32_t)(src) \
					<< 6) & ~0x000003C0U)))
#define ATLC_TXDESCRIPTOR_WRD0__RATE__RESET                         0x00000000U
/** @} */
/**
 * @defgroup atlc_TxDescriptor_wrd0 Protocol 
 * @brief macro for field Protocol
 * @{
 */
#define ATLC_TXDESCRIPTOR_WRD0__PROTOCOL__SHIFT                               0
#define ATLC_TXDESCRIPTOR_WRD0__PROTOCOL__WIDTH                               4
#define ATLC_TXDESCRIPTOR_WRD0__PROTOCOL__MASK                      0x0000000FU
#define ATLC_TXDESCRIPTOR_WRD0__PROTOCOL__READ(src) \
					(((uint32_t)(src) \
					& 0x0000000FU) >> 0)
#define ATLC_TXDESCRIPTOR_WRD0__PROTOCOL__WRITE(src) \
					(((uint32_t)(src) \
					<< 0) & 0x0000000FU)
#define ATLC_TXDESCRIPTOR_WRD0__PROTOCOL__MODIFY(dst, src) \
					(dst) = ((dst) &\
					~0x0000000FU) | (((uint32_t)(src) <<\
					0) & 0x0000000FU)
#define ATLC_TXDESCRIPTOR_WRD0__PROTOCOL__VERIFY(src) \
					(!((((uint32_t)(src) \
					<< 0) & ~0x0000000FU)))
#define ATLC_TXDESCRIPTOR_WRD0__PROTOCOL__RESET                     0x00000000U
/** @} */
/** @} */
#endif /*__ATLCTXDESCRIPTOR_WRD0_MACRO__*/
/**
 * @defgroup atlc_TxDescriptor_wrd1
 * @brief TxDescriptorWord1Macro
 * @{
 */
#ifndef __ATCL_TXDESCRIPTOR_WRD1_MACRO__

#define __ATCL_TXDESCRIPTOR_WRD1_MACRO__


/**
 * @defgroup atlc_TxDescriptor_wrd1 AA 
 * @brief macro for field AA
 * @{
 */
#define ATLC_TXDESCRIPTOR_WRD1__AA__SHIFT                                     0
#define ATLC_TXDESCRIPTOR_WRD1__AA__WIDTH                                    32
#define ATLC_TXDESCRIPTOR_WRD1__AA__MASK                            0xFFFFFFFFU
#define ATLC_TXDESCRIPTOR_WRD1__AA__READ(src) \
					(((uint32_t)(src) \
					& 0xFFFFFFFFU) >> 0)
#define ATLC_TXDESCRIPTOR_WRD1__AA__WRITE(src) \
					(((uint32_t)(src) \
					<< 0) & 0xFFFFFFFFU)
#define ATLC_TXDESCRIPTOR_WRD1__AA__MODIFY(dst, src) \
					(dst) = ((dst) &\
					~0xFFFFFFFFU) | (((uint32_t)(src) <<\
					0) & 0xFFFFFFFFU)
#define ATLC_TXDESCRIPTOR_WRD1__AA__VERIFY(src) \
					(!((((uint32_t)(src) \
					<< 0) & ~0xFFFFFFFFU)))
#define ATLC_TXDESCRIPTOR_WRD1__AA__RESET                           0x00000000U
/** @} */
/** @} */
#endif /*__ATLCTXDESCRIPTOR_WRD1_MACRO__*/
/**
 * @defgroup atlc_TxDescriptor_wrd2
 * @brief TxDescriptorWord2Macro
 * @{
 */
#ifndef __ATCL_TXDESCRIPTOR_WRD2_MACRO__

#define __ATCL_TXDESCRIPTOR_WRD2_MACRO__


/**
 * @defgroup atlc_TxDescriptor_wrd2 EventType 
 * @brief macro for field EventType
 * @{
 */
#define ATLC_TXDESCRIPTOR_WRD2__EVENTTYPE__SHIFT                             18
#define ATLC_TXDESCRIPTOR_WRD2__EVENTTYPE__WIDTH                              4
#define ATLC_TXDESCRIPTOR_WRD2__EVENTTYPE__MASK                     0x003C0000U
#define ATLC_TXDESCRIPTOR_WRD2__EVENTTYPE__READ(src) \
					(((uint32_t)(src) \
					& 0x003C0000U) >> 18)
#define ATLC_TXDESCRIPTOR_WRD2__EVENTTYPE__WRITE(src) \
					(((uint32_t)(src) \
					<< 18) & 0x003C0000U)
#define ATLC_TXDESCRIPTOR_WRD2__EVENTTYPE__MODIFY(dst, src) \
					(dst) = ((dst) &\
					~0x003C0000U) | (((uint32_t)(src) <<\
					18) & 0x003C0000U)
#define ATLC_TXDESCRIPTOR_WRD2__EVENTTYPE__VERIFY(src) \
					(!((((uint32_t)(src) \
					<< 18) & ~0x003C0000U)))
#define ATLC_TXDESCRIPTOR_WRD2__EVENTTYPE__RESET                    0x00000000U
/** @} */
/**
 * @defgroup atlc_TxDescriptor_wrd2 WhiteInitSeed 
 * @brief macro for field WhiteInitSeed
 * @{
 */
#define ATLC_TXDESCRIPTOR_WRD2__WHITEINITSEED__SHIFT                         10
#define ATLC_TXDESCRIPTOR_WRD2__WHITEINITSEED__WIDTH                          8
#define ATLC_TXDESCRIPTOR_WRD2__WHITEINITSEED__MASK                 0x0003FC00U
#define ATLC_TXDESCRIPTOR_WRD2__WHITEINITSEED__READ(src) \
					(((uint32_t)(src) \
					& 0x0003FC00U) >> 10)
#define ATLC_TXDESCRIPTOR_WRD2__WHITEINITSEED__WRITE(src) \
					(((uint32_t)(src) \
					<< 10) & 0x0003FC00U)
#define ATLC_TXDESCRIPTOR_WRD2__WHITEINITSEED__MODIFY(dst, src) \
					(dst) = ((dst) &\
					~0x0003FC00U) | (((uint32_t)(src) <<\
					10) & 0x0003FC00U)
#define ATLC_TXDESCRIPTOR_WRD2__WHITEINITSEED__VERIFY(src) \
					(!((((uint32_t)(src) \
					<< 10) & ~0x0003FC00U)))
#define ATLC_TXDESCRIPTOR_WRD2__WHITEINITSEED__RESET                0x00000000U
/** @} */
/**
 * @defgroup atlc_TxDescriptor_wrd2 StartTimeP5US 
 * @brief macro for field StartTimeP5US
 * @{
 */
#define ATLC_TXDESCRIPTOR_WRD2__STARTTIMEP5US__SHIFT                          0
#define ATLC_TXDESCRIPTOR_WRD2__STARTTIMEP5US__WIDTH                         10
#define ATLC_TXDESCRIPTOR_WRD2__STARTTIMEP5US__MASK                 0x000003FFU
#define ATLC_TXDESCRIPTOR_WRD2__STARTTIMEP5US__READ(src) \
					(((uint32_t)(src) \
					& 0x000003FFU) >> 0)
#define ATLC_TXDESCRIPTOR_WRD2__STARTTIMEP5US__WRITE(src) \
					(((uint32_t)(src) \
					<< 0) & 0x000003FFU)
#define ATLC_TXDESCRIPTOR_WRD2__STARTTIMEP5US__MODIFY(dst, src) \
					(dst) = ((dst) &\
					~0x000003FFU) | (((uint32_t)(src) <<\
					0) & 0x000003FFU)
#define ATLC_TXDESCRIPTOR_WRD2__STARTTIMEP5US__VERIFY(src) \
					(!((((uint32_t)(src) \
					<< 0) & ~0x000003FFU)))
#define ATLC_TXDESCRIPTOR_WRD2__STARTTIMEP5US__RESET                0x00000000U
/** @} */
/** @} */
#endif /*__ATLCTXDESCRIPTOR_WRD2_MACRO__*/
/**
 * @defgroup atlc_TxDescriptor_wrd3
 * @brief TxDescriptorWord3Macro
 * @{
 */
#ifndef __ATCL_TXDESCRIPTOR_WRD3_MACRO__

#define __ATCL_TXDESCRIPTOR_WRD3_MACRO__


/**
 * @defgroup atlc_TxDescriptor_wrd3 CRCInitSeed 
 * @brief macro for field CRCInitSeed
 * @{
 */
#define ATLC_TXDESCRIPTOR_WRD3__CRCINITSEED__SHIFT                            0
#define ATLC_TXDESCRIPTOR_WRD3__CRCINITSEED__WIDTH                           32
#define ATLC_TXDESCRIPTOR_WRD3__CRCINITSEED__MASK                   0xFFFFFFFFU
#define ATLC_TXDESCRIPTOR_WRD3__CRCINITSEED__READ(src) \
					(((uint32_t)(src) \
					& 0xFFFFFFFFU) >> 0)
#define ATLC_TXDESCRIPTOR_WRD3__CRCINITSEED__WRITE(src) \
					(((uint32_t)(src) \
					<< 0) & 0xFFFFFFFFU)
#define ATLC_TXDESCRIPTOR_WRD3__CRCINITSEED__MODIFY(dst, src) \
					(dst) = ((dst) &\
					~0xFFFFFFFFU) | (((uint32_t)(src) <<\
					0) & 0xFFFFFFFFU)
#define ATLC_TXDESCRIPTOR_WRD3__CRCINITSEED__VERIFY(src) \
					(!((((uint32_t)(src) \
					<< 0) & ~0xFFFFFFFFU)))
#define ATLC_TXDESCRIPTOR_WRD3__CRCINITSEED__RESET                  0x00000000U
/** @} */
/** @} */
#endif /*__ATLCTXDESCRIPTOR_WRD3_MACRO__*/
/**
 * @defgroup atlc_TxDescriptor_wrd4
 * @brief TxDescriptorWord4Macro
 * @{
 */
#ifndef __ATCL_TXDESCRIPTOR_WRD4_MACRO__

#define __ATCL_TXDESCRIPTOR_WRD4_MACRO__


/**
 * @defgroup atlc_TxDescriptor_wrd4 StartTimeUS 
 * @brief macro for field StartTimeUS
 * @{
 */
#define ATLC_TXDESCRIPTOR_WRD4__STARTTIMEUS__SHIFT                            0
#define ATLC_TXDESCRIPTOR_WRD4__STARTTIMEUS__WIDTH                           32
#define ATLC_TXDESCRIPTOR_WRD4__STARTTIMEUS__MASK                   0xFFFFFFFFU
#define ATLC_TXDESCRIPTOR_WRD4__STARTTIMEUS__READ(src) \
					(((uint32_t)(src) \
					& 0xFFFFFFFFU) >> 0)
#define ATLC_TXDESCRIPTOR_WRD4__STARTTIMEUS__WRITE(src) \
					(((uint32_t)(src) \
					<< 0) & 0xFFFFFFFFU)
#define ATLC_TXDESCRIPTOR_WRD4__STARTTIMEUS__MODIFY(dst, src) \
					(dst) = ((dst) &\
					~0xFFFFFFFFU) | (((uint32_t)(src) <<\
					0) & 0xFFFFFFFFU)
#define ATLC_TXDESCRIPTOR_WRD4__STARTTIMEUS__VERIFY(src) \
					(!((((uint32_t)(src) \
					<< 0) & ~0xFFFFFFFFU)))
#define ATLC_TXDESCRIPTOR_WRD4__STARTTIMEUS__RESET                  0x00000000U
/** @} */
/** @} */
#endif /*__ATLCTXDESCRIPTOR_WRD4_MACRO__*/
/**
 * @defgroup atlc_TxDescriptor_wrd5
 * @brief TxDescriptorWord5Macro
 * @{
 */
#ifndef __ATCL_TXDESCRIPTOR_WRD5_MACRO__

#define __ATCL_TXDESCRIPTOR_WRD5_MACRO__


/**
 * @defgroup atlc_TxDescriptor_wrd5 StartTime 
 * @brief macro for field StartTime
 * @{
 */
#define ATLC_TXDESCRIPTOR_WRD5__STARTTIME__SHIFT                              0
#define ATLC_TXDESCRIPTOR_WRD5__STARTTIME__WIDTH                             32
#define ATLC_TXDESCRIPTOR_WRD5__STARTTIME__MASK                     0xFFFFFFFFU
#define ATLC_TXDESCRIPTOR_WRD5__STARTTIME__READ(src) \
					(((uint32_t)(src) \
					& 0xFFFFFFFFU) >> 0)
#define ATLC_TXDESCRIPTOR_WRD5__STARTTIME__WRITE(src) \
					(((uint32_t)(src) \
					<< 0) & 0xFFFFFFFFU)
#define ATLC_TXDESCRIPTOR_WRD5__STARTTIME__MODIFY(dst, src) \
					(dst) = ((dst) &\
					~0xFFFFFFFFU) | (((uint32_t)(src) <<\
					0) & 0xFFFFFFFFU)
#define ATLC_TXDESCRIPTOR_WRD5__STARTTIME__VERIFY(src) \
					(!((((uint32_t)(src) \
					<< 0) & ~0xFFFFFFFFU)))
#define ATLC_TXDESCRIPTOR_WRD5__STARTTIME__RESET                    0x00000000U
/** @} */
/** @} */
#endif /*__ATLCTXDESCRIPTOR_WRD5_MACRO__*/
/**
 * @defgroup atlc_TxDescriptor_wrd6
 * @brief TxDescriptorWord6Macro
 * @{
 */
#ifndef __ATCL_TXDESCRIPTOR_WRD6_MACRO__

#define __ATCL_TXDESCRIPTOR_WRD6_MACRO__


/**
 * @defgroup atlc_TxDescriptor_wrd6 CSMA_MinBaclExp 
 * @brief macro for field CSMA_MinBaclExp
 * @{
 */
#define ATLC_TXDESCRIPTOR_WRD6__CSMA_MINBACLEXP__SHIFT                       24
#define ATLC_TXDESCRIPTOR_WRD6__CSMA_MINBACLEXP__WIDTH                        8
#define ATLC_TXDESCRIPTOR_WRD6__CSMA_MINBACLEXP__MASK               0xFF000000U
#define ATLC_TXDESCRIPTOR_WRD6__CSMA_MINBACLEXP__READ(src) \
					(((uint32_t)(src) \
					& 0xFF000000U) >> 24)
#define ATLC_TXDESCRIPTOR_WRD6__CSMA_MINBACLEXP__WRITE(src) \
					(((uint32_t)(src) \
					<< 24) & 0xFF000000U)
#define ATLC_TXDESCRIPTOR_WRD6__CSMA_MINBACLEXP__MODIFY(dst, src) \
					(dst) = ((dst) &\
					~0xFF000000U) | (((uint32_t)(src) <<\
					24) & 0xFF000000U)
#define ATLC_TXDESCRIPTOR_WRD6__CSMA_MINBACLEXP__VERIFY(src) \
					(!((((uint32_t)(src) \
					<< 24) & ~0xFF000000U)))
#define ATLC_TXDESCRIPTOR_WRD6__CSMA_MINBACLEXP__RESET              0x00000000U
/** @} */
/**
 * @defgroup atlc_TxDescriptor_wrd6 CSMA_MaxBaclExp 
 * @brief macro for field CSMA_MaxBaclExp
 * @{
 */
#define ATLC_TXDESCRIPTOR_WRD6__CSMA_MAXBACLEXP__SHIFT                       16
#define ATLC_TXDESCRIPTOR_WRD6__CSMA_MAXBACLEXP__WIDTH                        8
#define ATLC_TXDESCRIPTOR_WRD6__CSMA_MAXBACLEXP__MASK               0x00FF0000U
#define ATLC_TXDESCRIPTOR_WRD6__CSMA_MAXBACLEXP__READ(src) \
					(((uint32_t)(src) \
					& 0x00FF0000U) >> 16)
#define ATLC_TXDESCRIPTOR_WRD6__CSMA_MAXBACLEXP__WRITE(src) \
					(((uint32_t)(src) \
					<< 16) & 0x00FF0000U)
#define ATLC_TXDESCRIPTOR_WRD6__CSMA_MAXBACLEXP__MODIFY(dst, src) \
					(dst) = ((dst) &\
					~0x00FF0000U) | (((uint32_t)(src) <<\
					16) & 0x00FF0000U)
#define ATLC_TXDESCRIPTOR_WRD6__CSMA_MAXBACLEXP__VERIFY(src) \
					(!((((uint32_t)(src) \
					<< 16) & ~0x00FF0000U)))
#define ATLC_TXDESCRIPTOR_WRD6__CSMA_MAXBACLEXP__RESET              0x00000000U
/** @} */
/**
 * @defgroup atlc_TxDescriptor_wrd6 CSMA_MaxNumOfBackOff 
 * @brief macro for field CSMA_MaxNumOfBackOff
 * @{
 */
#define ATLC_TXDESCRIPTOR_WRD6__CSMA_MAXNUMOFBACKOFF__SHIFT                   8
#define ATLC_TXDESCRIPTOR_WRD6__CSMA_MAXNUMOFBACKOFF__WIDTH                   8
#define ATLC_TXDESCRIPTOR_WRD6__CSMA_MAXNUMOFBACKOFF__MASK          0x0000FF00U
#define ATLC_TXDESCRIPTOR_WRD6__CSMA_MAXNUMOFBACKOFF__READ(src) \
					(((uint32_t)(src) \
					& 0x0000FF00U) >> 8)
#define ATLC_TXDESCRIPTOR_WRD6__CSMA_MAXNUMOFBACKOFF__WRITE(src) \
					(((uint32_t)(src) \
					<< 8) & 0x0000FF00U)
#define ATLC_TXDESCRIPTOR_WRD6__CSMA_MAXNUMOFBACKOFF__MODIFY(dst, src) \
					(dst) = ((dst) &\
					~0x0000FF00U) | (((uint32_t)(src) <<\
					8) & 0x0000FF00U)
#define ATLC_TXDESCRIPTOR_WRD6__CSMA_MAXNUMOFBACKOFF__VERIFY(src) \
					(!((((uint32_t)(src) \
					<< 8) & ~0x0000FF00U)))
#define ATLC_TXDESCRIPTOR_WRD6__CSMA_MAXNUMOFBACKOFF__RESET         0x00000000U
/** @} */
/**
 * @defgroup atlc_TxDescriptor_wrd6 CSMA_MaxDuration 
 * @brief macro for field CSMA_MaxDuration
 * @{
 */
#define ATLC_TXDESCRIPTOR_WRD6__CSMA_MAXDURATION__SHIFT                       0
#define ATLC_TXDESCRIPTOR_WRD6__CSMA_MAXDURATION__WIDTH                       8
#define ATLC_TXDESCRIPTOR_WRD6__CSMA_MAXDURATION__MASK              0x000000FFU
#define ATLC_TXDESCRIPTOR_WRD6__CSMA_MAXDURATION__READ(src) \
					(((uint32_t)(src) \
					& 0x000000FFU) >> 0)
#define ATLC_TXDESCRIPTOR_WRD6__CSMA_MAXDURATION__WRITE(src) \
					(((uint32_t)(src) \
					<< 0) & 0x000000FFU)
#define ATLC_TXDESCRIPTOR_WRD6__CSMA_MAXDURATION__MODIFY(dst, src) \
					(dst) = ((dst) &\
					~0x000000FFU) | (((uint32_t)(src) <<\
					0) & 0x000000FFU)
#define ATLC_TXDESCRIPTOR_WRD6__CSMA_MAXDURATION__VERIFY(src) \
					(!((((uint32_t)(src) \
					<< 0) & ~0x000000FFU)))
#define ATLC_TXDESCRIPTOR_WRD6__CSMA_MAXDURATION__RESET             0x00000000U
/** @} */
/** @} */
#endif /*__ATLCTXDESCRIPTOR_WRD6_MACRO__*/
/**
 * @defgroup atlc_TxDescriptor_wrd7
 * @brief TxDescriptorWord7Macro
 * @{
 */
#ifndef __ATCL_TXDESCRIPTOR_WRD7_MACRO__

#define __ATCL_TXDESCRIPTOR_WRD7_MACRO__


/**
 * @defgroup atlc_TxDescriptor_wrd7 TxLen 
 * @brief macro for field TxLen
 * @{
 */
#define ATLC_TXDESCRIPTOR_WRD7__TXLEN__SHIFT                                 16
#define ATLC_TXDESCRIPTOR_WRD7__TXLEN__WIDTH                                 16
#define ATLC_TXDESCRIPTOR_WRD7__TXLEN__MASK                         0xFFFF0000U
#define ATLC_TXDESCRIPTOR_WRD7__TXLEN__READ(src) \
					(((uint32_t)(src) \
					& 0xFFFF0000U) >> 16)
#define ATLC_TXDESCRIPTOR_WRD7__TXLEN__WRITE(src) \
					(((uint32_t)(src) \
					<< 16) & 0xFFFF0000U)
#define ATLC_TXDESCRIPTOR_WRD7__TXLEN__MODIFY(dst, src) \
					(dst) = ((dst) &\
					~0xFFFF0000U) | (((uint32_t)(src) <<\
					16) & 0xFFFF0000U)
#define ATLC_TXDESCRIPTOR_WRD7__TXLEN__VERIFY(src) \
					(!((((uint32_t)(src) \
					<< 16) & ~0xFFFF0000U)))
#define ATLC_TXDESCRIPTOR_WRD7__TXLEN__RESET                        0x00000000U
/** @} */
/**
 * @defgroup atlc_TxDescriptor_wrd7 TxDataPtr 
 * @brief macro for field TxDataPtr
 * @{
 */
#define ATLC_TXDESCRIPTOR_WRD7__TXDATAPTR__SHIFT                              0
#define ATLC_TXDESCRIPTOR_WRD7__TXDATAPTR__WIDTH                             16
#define ATLC_TXDESCRIPTOR_WRD7__TXDATAPTR__MASK                     0x0000FFFFU
#define ATLC_TXDESCRIPTOR_WRD7__TXDATAPTR__READ(src) \
					(((uint32_t)(src) \
					& 0x0000FFFFU) >> 0)
#define ATLC_TXDESCRIPTOR_WRD7__TXDATAPTR__WRITE(src) \
					(((uint32_t)(src) \
					<< 0) & 0x0000FFFFU)
#define ATLC_TXDESCRIPTOR_WRD7__TXDATAPTR__MODIFY(dst, src) \
					(dst) = ((dst) &\
					~0x0000FFFFU) | (((uint32_t)(src) <<\
					0) & 0x0000FFFFU)
#define ATLC_TXDESCRIPTOR_WRD7__TXDATAPTR__VERIFY(src) \
					(!((((uint32_t)(src) \
					<< 0) & ~0x0000FFFFU)))
#define ATLC_TXDESCRIPTOR_WRD7__TXDATAPTR__RESET                    0x00000000U
/** @} */
/** @} */
#endif /*__ATLCTXDESCRIPTOR_WRD7_MACRO__*/
/**
 * @defgroup atlc_TxDescriptor_wrd8
 * @brief TxDescriptorWord8Macro
 * @{
 */
#ifndef __ATCL_TXDESCRIPTOR_WRD8_MACRO__

#define __ATCL_TXDESCRIPTOR_WRD8_MACRO__


/**
 * @defgroup atlc_TxDescriptor_wrd8 IV_0 
 * @brief macro for field IV_0
 * @{
 */
#define ATLC_TXDESCRIPTOR_WRD8__IV_0__SHIFT                                   0
#define ATLC_TXDESCRIPTOR_WRD8__IV_0__WIDTH                                  32
#define ATLC_TXDESCRIPTOR_WRD8__IV_0__MASK                          0xFFFFFFFFU
#define ATLC_TXDESCRIPTOR_WRD8__IV_0__READ(src) \
					(((uint32_t)(src) \
					& 0xFFFFFFFFU) >> 0)
#define ATLC_TXDESCRIPTOR_WRD8__IV_0__WRITE(src) \
					(((uint32_t)(src) \
					<< 0) & 0xFFFFFFFFU)
#define ATLC_TXDESCRIPTOR_WRD8__IV_0__MODIFY(dst, src) \
					(dst) = ((dst) &\
					~0xFFFFFFFFU) | (((uint32_t)(src) <<\
					0) & 0xFFFFFFFFU)
#define ATLC_TXDESCRIPTOR_WRD8__IV_0__VERIFY(src) \
					(!((((uint32_t)(src) \
					<< 0) & ~0xFFFFFFFFU)))
#define ATLC_TXDESCRIPTOR_WRD8__IV_0__RESET                         0x00000000U
/** @} */
/** @} */
#endif /*__ATLCTXDESCRIPTOR_WRD8_MACRO__*/
/**
 * @defgroup atlc_TxDescriptor_wrd9
 * @brief TxDescriptorWord9Macro
 * @{
 */
#ifndef __ATCL_TXDESCRIPTOR_WRD9_MACRO__

#define __ATCL_TXDESCRIPTOR_WRD9_MACRO__


/**
 * @defgroup atlc_TxDescriptor_wrd9 IV_1 
 * @brief macro for field IV_1
 * @{
 */
#define ATLC_TXDESCRIPTOR_WRD9__IV_1__SHIFT                                   0
#define ATLC_TXDESCRIPTOR_WRD9__IV_1__WIDTH                                  32
#define ATLC_TXDESCRIPTOR_WRD9__IV_1__MASK                          0xFFFFFFFFU
#define ATLC_TXDESCRIPTOR_WRD9__IV_1__READ(src) \
					(((uint32_t)(src) \
					& 0xFFFFFFFFU) >> 0)
#define ATLC_TXDESCRIPTOR_WRD9__IV_1__WRITE(src) \
					(((uint32_t)(src) \
					<< 0) & 0xFFFFFFFFU)
#define ATLC_TXDESCRIPTOR_WRD9__IV_1__MODIFY(dst, src) \
					(dst) = ((dst) &\
					~0xFFFFFFFFU) | (((uint32_t)(src) <<\
					0) & 0xFFFFFFFFU)
#define ATLC_TXDESCRIPTOR_WRD9__IV_1__VERIFY(src) \
					(!((((uint32_t)(src) \
					<< 0) & ~0xFFFFFFFFU)))
#define ATLC_TXDESCRIPTOR_WRD9__IV_1__RESET                         0x00000000U
/** @} */
/** @} */
#endif /*__ATLCTXDESCRIPTOR_WRD9_MACRO__*/
/**
 * @defgroup atlc_TxDescriptor_wrd10
 * @brief TxDescriptorWord10Macro
 * @{
 */
#ifndef __ATCL_TXDESCRIPTOR_WRD10_MACRO__

#define __ATCL_TXDESCRIPTOR_WRD10_MACRO__


/**
 * @defgroup atlc_TxDescriptor_wrd10 PKTCNTR_0 
 * @brief macro for field PKTCNTR_0
 * @{
 */
#define ATLC_TXDESCRIPTOR_WRD10__PKTCNTR_0__SHIFT                             0
#define ATLC_TXDESCRIPTOR_WRD10__PKTCNTR_0__WIDTH                            32
#define ATLC_TXDESCRIPTOR_WRD10__PKTCNTR_0__MASK                    0xFFFFFFFFU
#define ATLC_TXDESCRIPTOR_WRD10__PKTCNTR_0__READ(src) \
					(((uint32_t)(src) \
					& 0xFFFFFFFFU) >> 0)
#define ATLC_TXDESCRIPTOR_WRD10__PKTCNTR_0__WRITE(src) \
					(((uint32_t)(src) \
					<< 0) & 0xFFFFFFFFU)
#define ATLC_TXDESCRIPTOR_WRD10__PKTCNTR_0__MODIFY(dst, src) \
					(dst) = ((dst) &\
					~0xFFFFFFFFU) | (((uint32_t)(src) <<\
					0) & 0xFFFFFFFFU)
#define ATLC_TXDESCRIPTOR_WRD10__PKTCNTR_0__VERIFY(src) \
					(!((((uint32_t)(src) \
					<< 0) & ~0xFFFFFFFFU)))
#define ATLC_TXDESCRIPTOR_WRD10__PKTCNTR_0__RESET                   0x00000000U
/** @} */
/** @} */
#endif /*__ATLCTXDESCRIPTOR_WRD10_MACRO__*/
/**
 * @defgroup atlc_TxDescriptor_wrd11
 * @brief TxDescriptorWord11Macro
 * @{
 */
#ifndef __ATCL_TXDESCRIPTOR_WRD11_MACRO__

#define __ATCL_TXDESCRIPTOR_WRD11_MACRO__


/**
 * @defgroup atlc_TxDescriptor_wrd11 DrctnBt 
 * @brief macro for field DrctnBt
 * @{
 */
#define ATLC_TXDESCRIPTOR_WRD11__DRCTNBT__SHIFT                               8
#define ATLC_TXDESCRIPTOR_WRD11__DRCTNBT__WIDTH                               1
#define ATLC_TXDESCRIPTOR_WRD11__DRCTNBT__MASK                      0x00000100U
#define ATLC_TXDESCRIPTOR_WRD11__DRCTNBT__READ(src) \
					(((uint32_t)(src) \
					& 0x00000100U) >> 8)
#define ATLC_TXDESCRIPTOR_WRD11__DRCTNBT__WRITE(src) \
					(((uint32_t)(src) \
					<< 8) & 0x00000100U)
#define ATLC_TXDESCRIPTOR_WRD11__DRCTNBT__MODIFY(dst, src) \
					(dst) = ((dst) &\
					~0x00000100U) | (((uint32_t)(src) <<\
					8) & 0x00000100U)
#define ATLC_TXDESCRIPTOR_WRD11__DRCTNBT__VERIFY(src) \
					(!((((uint32_t)(src) \
					<< 8) & ~0x00000100U)))
#define ATLC_TXDESCRIPTOR_WRD11__DRCTNBT__RESET                     0x00000000U
/** @} */
/**
 * @defgroup atlc_TxDescriptor_wrd11 PKTCNTR_1 
 * @brief macro for field PKTCNTR_1
 * @{
 */
#define ATLC_TXDESCRIPTOR_WRD11__PKTCNTR_1__SHIFT                             0
#define ATLC_TXDESCRIPTOR_WRD11__PKTCNTR_1__WIDTH                             7
#define ATLC_TXDESCRIPTOR_WRD11__PKTCNTR_1__MASK                    0x0000007FU
#define ATLC_TXDESCRIPTOR_WRD11__PKTCNTR_1__READ(src) \
					(((uint32_t)(src) \
					& 0x0000007FU) >> 0)
#define ATLC_TXDESCRIPTOR_WRD11__PKTCNTR_1__WRITE(src) \
					(((uint32_t)(src) \
					<< 0) & 0x0000007FU)
#define ATLC_TXDESCRIPTOR_WRD11__PKTCNTR_1__MODIFY(dst, src) \
					(dst) = ((dst) &\
					~0x0000007FU) | (((uint32_t)(src) <<\
					0) & 0x0000007FU)
#define ATLC_TXDESCRIPTOR_WRD11__PKTCNTR_1__VERIFY(src) \
					(!((((uint32_t)(src) \
					<< 0) & ~0x0000007FU)))
#define ATLC_TXDESCRIPTOR_WRD11__PKTCNTR_1__RESET                   0x00000000U
/** @} */
/** @} */
#endif /*__ATLCTXDESCRIPTOR_WRD11_MACRO__*/
/**
 * @defgroup atlc_TxDescriptor_wrd12
 * @brief TxDescriptorWord12Macro
 * @{
 */
#ifndef __ATCL_TXDESCRIPTOR_WRD12_MACRO__

#define __ATCL_TXDESCRIPTOR_WRD12_MACRO__


/**
 * @defgroup atlc_TxDescriptor_wrd12 RSVD 
 * @brief macro for field RSVD
 * @{
 */
#define ATLC_TXDESCRIPTOR_WRD12__RSVD__SHIFT                                  0
#define ATLC_TXDESCRIPTOR_WRD12__RSVD__WIDTH                                 32
#define ATLC_TXDESCRIPTOR_WRD12__RSVD__MASK                         0xFFFFFFFFU
#define ATLC_TXDESCRIPTOR_WRD12__RSVD__READ(src) \
					(((uint32_t)(src) \
					& 0xFFFFFFFFU) >> 0)
#define ATLC_TXDESCRIPTOR_WRD12__RSVD__WRITE(src) \
					(((uint32_t)(src) \
					<< 0) & 0xFFFFFFFFU)
#define ATLC_TXDESCRIPTOR_WRD12__RSVD__MODIFY(dst, src) \
					(dst) = ((dst) &\
					~0xFFFFFFFFU) | (((uint32_t)(src) <<\
					0) & 0xFFFFFFFFU)
#define ATLC_TXDESCRIPTOR_WRD12__RSVD__VERIFY(src) \
					(!((((uint32_t)(src) \
					<< 0) & ~0xFFFFFFFFU)))
#define ATLC_TXDESCRIPTOR_WRD12__RSVD__RESET                        0x00000000U
/** @} */
/** @} */
#endif /*__ATLCTXDESCRIPTOR_WRD12_MACRO__*/
/**
 * @defgroup atlc_TxDescriptor_wrd13
 * @brief TxDescriptorWord13Macro
 * @{
 */
#ifndef __ATCL_TXDESCRIPTOR_WRD13_MACRO__

#define __ATCL_TXDESCRIPTOR_WRD13_MACRO__


/**
 * @defgroup atlc_TxDescriptor_wrd13 Status_NumOfBackOff 
 * @brief macro for field Status_NumOfBackOff
 * @{
 */
#define ATLC_TXDESCRIPTOR_WRD13__STATUS_NUMOFBACKOFF__SHIFT                   2
#define ATLC_TXDESCRIPTOR_WRD13__STATUS_NUMOFBACKOFF__WIDTH                   8
#define ATLC_TXDESCRIPTOR_WRD13__STATUS_NUMOFBACKOFF__MASK          0x000003FCU
#define ATLC_TXDESCRIPTOR_WRD13__STATUS_NUMOFBACKOFF__READ(src) \
					(((uint32_t)(src) \
					& 0x000003FCU) >> 2)
#define ATLC_TXDESCRIPTOR_WRD13__STATUS_NUMOFBACKOFF__WRITE(src) \
					(((uint32_t)(src) \
					<< 2) & 0x000003FCU)
#define ATLC_TXDESCRIPTOR_WRD13__STATUS_NUMOFBACKOFF__MODIFY(dst, src) \
					(dst) = ((dst) &\
					~0x000003FCU) | (((uint32_t)(src) <<\
					2) & 0x000003FCU)
#define ATLC_TXDESCRIPTOR_WRD13__STATUS_NUMOFBACKOFF__VERIFY(src) \
					(!((((uint32_t)(src) \
					<< 2) & ~0x000003FCU)))
#define ATLC_TXDESCRIPTOR_WRD13__STATUS_NUMOFBACKOFF__RESET         0x00000000U
/** @} */
/**
 * @defgroup atlc_TxDescriptor_wrd13 Status_ErrorMaxBackOff 
 * @brief macro for field Status_ErrorMaxBackOff
 * @{
 */
#define ATLC_TXDESCRIPTOR_WRD13__STATUS_ERRORMAXBACKOFF__SHIFT                1
#define ATLC_TXDESCRIPTOR_WRD13__STATUS_ERRORMAXBACKOFF__WIDTH                1
#define ATLC_TXDESCRIPTOR_WRD13__STATUS_ERRORMAXBACKOFF__MASK       0x00000002U
#define ATLC_TXDESCRIPTOR_WRD13__STATUS_ERRORMAXBACKOFF__READ(src) \
					(((uint32_t)(src) \
					& 0x00000002U) >> 1)
#define ATLC_TXDESCRIPTOR_WRD13__STATUS_ERRORMAXBACKOFF__WRITE(src) \
					(((uint32_t)(src) \
					<< 1) & 0x00000002U)
#define ATLC_TXDESCRIPTOR_WRD13__STATUS_ERRORMAXBACKOFF__MODIFY(dst, src) \
					(dst) = ((dst) &\
					~0x00000002U) | (((uint32_t)(src) <<\
					1) & 0x00000002U)
#define ATLC_TXDESCRIPTOR_WRD13__STATUS_ERRORMAXBACKOFF__VERIFY(src) \
					(!((((uint32_t)(src) \
					<< 1) & ~0x00000002U)))
#define ATLC_TXDESCRIPTOR_WRD13__STATUS_ERRORMAXBACKOFF__RESET      0x00000000U
/** @} */
/**
 * @defgroup atlc_TxDescriptor_wrd13 Status_ErrorMaxDuration 
 * @brief macro for field Status_ErrorMaxDuration
 * @{
 */
#define ATLC_TXDESCRIPTOR_WRD13__STATUS_ERRORMAXDURATION__SHIFT               0
#define ATLC_TXDESCRIPTOR_WRD13__STATUS_ERRORMAXDURATION__WIDTH               1
#define ATLC_TXDESCRIPTOR_WRD13__STATUS_ERRORMAXDURATION__MASK      0x00000001U
#define ATLC_TXDESCRIPTOR_WRD13__STATUS_ERRORMAXDURATION__READ(src) \
					(((uint32_t)(src) \
					& 0x00000001U) >> 0)
#define ATLC_TXDESCRIPTOR_WRD13__STATUS_ERRORMAXDURATION__WRITE(src) \
					(((uint32_t)(src) \
					<< 0) & 0x00000001U)
#define ATLC_TXDESCRIPTOR_WRD13__STATUS_ERRORMAXDURATION__MODIFY(dst, src) \
					(dst) = ((dst) &\
					~0x00000001U) | (((uint32_t)(src) <<\
					0) & 0x00000001U)
#define ATLC_TXDESCRIPTOR_WRD13__STATUS_ERRORMAXDURATION__VERIFY(src) \
					(!((((uint32_t)(src) \
					<< 0) & ~0x00000001U)))
#define ATLC_TXDESCRIPTOR_WRD13__STATUS_ERRORMAXDURATION__RESET     0x00000000U
/** @} */
/** @} */
#endif /*__ATLCTXDESCRIPTOR_WRD13_MACRO__*/
/**
 * @defgroup atlc_TxDescriptor_wrd14
 * @brief TxDescriptorWord14Macro
 * @{
 */
#ifndef __ATCL_TXDESCRIPTOR_WRD14_MACRO__

#define __ATCL_TXDESCRIPTOR_WRD14_MACRO__


/**
 * @defgroup atlc_TxDescriptor_wrd14 Status_DataSentTimeStamp 
 * @brief macro for field Status_DataSentTimeStamp
 * @{
 */
#define ATLC_TXDESCRIPTOR_WRD14__STATUS_DATASENTTIMESTAMP__SHIFT              0
#define ATLC_TXDESCRIPTOR_WRD14__STATUS_DATASENTTIMESTAMP__WIDTH             32
#define ATLC_TXDESCRIPTOR_WRD14__STATUS_DATASENTTIMESTAMP__MASK     0xFFFFFFFFU
#define ATLC_TXDESCRIPTOR_WRD14__STATUS_DATASENTTIMESTAMP__READ(src) \
					(((uint32_t)(src) \
					& 0xFFFFFFFFU) >> 0)
#define ATLC_TXDESCRIPTOR_WRD14__STATUS_DATASENTTIMESTAMP__WRITE(src) \
					(((uint32_t)(src) \
					<< 0) & 0xFFFFFFFFU)
#define ATLC_TXDESCRIPTOR_WRD14__STATUS_DATASENTTIMESTAMP__MODIFY(dst, src) \
					(dst) = ((dst) &\
					~0xFFFFFFFFU) | (((uint32_t)(src) <<\
					0) & 0xFFFFFFFFU)
#define ATLC_TXDESCRIPTOR_WRD14__STATUS_DATASENTTIMESTAMP__VERIFY(src) \
					(!((((uint32_t)(src) \
					<< 0) & ~0xFFFFFFFFU)))
#define ATLC_TXDESCRIPTOR_WRD14__STATUS_DATASENTTIMESTAMP__RESET    0x00000000U
/** @} */
/** @} */
#endif /*__ATLCTXDESCRIPTOR_WRD14_MACRO__*/
/**
 * @defgroup atlc_TxDescriptor_wrd15
 * @brief TxDescriptorWord15Macro
 * @{
 */
#ifndef __ATCL_TXDESCRIPTOR_WRD15_MACRO__

#define __ATCL_TXDESCRIPTOR_WRD15_MACRO__


/**
 * @defgroup atlc_TxDescriptor_wrd15 Status_SyncTimeStamp 
 * @brief macro for field Status_SyncTimeStamp
 * @{
 */
#define ATLC_TXDESCRIPTOR_WRD15__STATUS_SYNCTIMESTAMP__SHIFT                  0
#define ATLC_TXDESCRIPTOR_WRD15__STATUS_SYNCTIMESTAMP__WIDTH                 32
#define ATLC_TXDESCRIPTOR_WRD15__STATUS_SYNCTIMESTAMP__MASK         0xFFFFFFFFU
#define ATLC_TXDESCRIPTOR_WRD15__STATUS_SYNCTIMESTAMP__READ(src) \
					(((uint32_t)(src) \
					& 0xFFFFFFFFU) >> 0)
#define ATLC_TXDESCRIPTOR_WRD15__STATUS_SYNCTIMESTAMP__WRITE(src) \
					(((uint32_t)(src) \
					<< 0) & 0xFFFFFFFFU)
#define ATLC_TXDESCRIPTOR_WRD15__STATUS_SYNCTIMESTAMP__MODIFY(dst, src) \
					(dst) = ((dst) &\
					~0xFFFFFFFFU) | (((uint32_t)(src) <<\
					0) & 0xFFFFFFFFU)
#define ATLC_TXDESCRIPTOR_WRD15__STATUS_SYNCTIMESTAMP__VERIFY(src) \
					(!((((uint32_t)(src) \
					<< 0) & ~0xFFFFFFFFU)))
#define ATLC_TXDESCRIPTOR_WRD15__STATUS_SYNCTIMESTAMP__RESET        0x00000000U
/** @} */
/** @} */
#endif /*__ATLCTXDESCRIPTOR_WRD15_MACRO__*/
/**
 * @defgroup atlc_RxDescriptor_wrd0
 * @brief RxDescriptorWord0Macro
 * @{
 */
#ifndef __ATCL_RXDESCRIPTOR_WRD0_MACRO__

#define __ATCL_RXDESCRIPTOR_WRD0_MACRO__


/**
 * @defgroup atlc_RxDescriptor_wrd0 RxDuration 
 * @brief macro for field RxDuration
 * @{
 */
#define ATLC_RXDESCRIPTOR_WRD0__RXDURATION__SHIFT                            24
#define ATLC_RXDESCRIPTOR_WRD0__RXDURATION__WIDTH                             8
#define ATLC_RXDESCRIPTOR_WRD0__RXDURATION__MASK                    0xFF000000U
#define ATLC_RXDESCRIPTOR_WRD0__RXDURATION__READ(src) \
					(((uint32_t)(src) \
					& 0xFF000000U) >> 24)
#define ATLC_RXDESCRIPTOR_WRD0__RXDURATION__WRITE(src) \
					(((uint32_t)(src) \
					<< 24) & 0xFF000000U)
#define ATLC_RXDESCRIPTOR_WRD0__RXDURATION__MODIFY(dst, src) \
					(dst) = ((dst) &\
					~0xFF000000U) | (((uint32_t)(src) <<\
					24) & 0xFF000000U)
#define ATLC_RXDESCRIPTOR_WRD0__RXDURATION__VERIFY(src) \
					(!((((uint32_t)(src) \
					<< 24) & ~0xFF000000U)))
#define ATLC_RXDESCRIPTOR_WRD0__RXDURATION__RESET                   0x00000000U
/** @} */
/**
 * @defgroup atlc_RxDescriptor_wrd0 ChannelIndex 
 * @brief macro for field ChannelIndex
 * @{
 */
#define ATLC_RXDESCRIPTOR_WRD0__CHANNELINDEX__SHIFT                          17
#define ATLC_RXDESCRIPTOR_WRD0__CHANNELINDEX__WIDTH                           7
#define ATLC_RXDESCRIPTOR_WRD0__CHANNELINDEX__MASK                  0x00FE0000U
#define ATLC_RXDESCRIPTOR_WRD0__CHANNELINDEX__READ(src) \
					(((uint32_t)(src) \
					& 0x00FE0000U) >> 17)
#define ATLC_RXDESCRIPTOR_WRD0__CHANNELINDEX__WRITE(src) \
					(((uint32_t)(src) \
					<< 17) & 0x00FE0000U)
#define ATLC_RXDESCRIPTOR_WRD0__CHANNELINDEX__MODIFY(dst, src) \
					(dst) = ((dst) &\
					~0x00FE0000U) | (((uint32_t)(src) <<\
					17) & 0x00FE0000U)
#define ATLC_RXDESCRIPTOR_WRD0__CHANNELINDEX__VERIFY(src) \
					(!((((uint32_t)(src) \
					<< 17) & ~0x00FE0000U)))
#define ATLC_RXDESCRIPTOR_WRD0__CHANNELINDEX__RESET                 0x00000000U
/** @} */
/**
 * @defgroup atlc_RxDescriptor_wrd0 MICLen 
 * @brief macro for field MICLen
 * @{
 */
#define ATLC_RXDESCRIPTOR_WRD0__MICLEN__SHIFT                                14
#define ATLC_RXDESCRIPTOR_WRD0__MICLEN__WIDTH                                 2
#define ATLC_RXDESCRIPTOR_WRD0__MICLEN__MASK                        0x0000C000U
#define ATLC_RXDESCRIPTOR_WRD0__MICLEN__READ(src) \
					(((uint32_t)(src) \
					& 0x0000C000U) >> 14)
#define ATLC_RXDESCRIPTOR_WRD0__MICLEN__WRITE(src) \
					(((uint32_t)(src) \
					<< 14) & 0x0000C000U)
#define ATLC_RXDESCRIPTOR_WRD0__MICLEN__MODIFY(dst, src) \
					(dst) = ((dst) &\
					~0x0000C000U) | (((uint32_t)(src) <<\
					14) & 0x0000C000U)
#define ATLC_RXDESCRIPTOR_WRD0__MICLEN__VERIFY(src) \
					(!((((uint32_t)(src) \
					<< 14) & ~0x0000C000U)))
#define ATLC_RXDESCRIPTOR_WRD0__MICLEN__RESET                       0x00000000U
/** @} */
/**
 * @defgroup atlc_RxDescriptor_wrd0 CryptEn 
 * @brief macro for field CryptEn
 * @{
 */
#define ATLC_RXDESCRIPTOR_WRD0__CRYPTEN__SHIFT                               13
#define ATLC_RXDESCRIPTOR_WRD0__CRYPTEN__WIDTH                                1
#define ATLC_RXDESCRIPTOR_WRD0__CRYPTEN__MASK                       0x00002000U
#define ATLC_RXDESCRIPTOR_WRD0__CRYPTEN__READ(src) \
					(((uint32_t)(src) \
					& 0x00002000U) >> 13)
#define ATLC_RXDESCRIPTOR_WRD0__CRYPTEN__WRITE(src) \
					(((uint32_t)(src) \
					<< 13) & 0x00002000U)
#define ATLC_RXDESCRIPTOR_WRD0__CRYPTEN__MODIFY(dst, src) \
					(dst) = ((dst) &\
					~0x00002000U) | (((uint32_t)(src) <<\
					13) & 0x00002000U)
#define ATLC_RXDESCRIPTOR_WRD0__CRYPTEN__VERIFY(src) \
					(!((((uint32_t)(src) \
					<< 13) & ~0x00002000U)))
#define ATLC_RXDESCRIPTOR_WRD0__CRYPTEN__RESET                      0x00000000U
/** @} */
/**
 * @defgroup atlc_RxDescriptor_wrd0 WhiteEn 
 * @brief macro for field WhiteEn
 * @{
 */
#define ATLC_RXDESCRIPTOR_WRD0__WHITEEN__SHIFT                               12
#define ATLC_RXDESCRIPTOR_WRD0__WHITEEN__WIDTH                                1
#define ATLC_RXDESCRIPTOR_WRD0__WHITEEN__MASK                       0x00001000U
#define ATLC_RXDESCRIPTOR_WRD0__WHITEEN__READ(src) \
					(((uint32_t)(src) \
					& 0x00001000U) >> 12)
#define ATLC_RXDESCRIPTOR_WRD0__WHITEEN__WRITE(src) \
					(((uint32_t)(src) \
					<< 12) & 0x00001000U)
#define ATLC_RXDESCRIPTOR_WRD0__WHITEEN__MODIFY(dst, src) \
					(dst) = ((dst) &\
					~0x00001000U) | (((uint32_t)(src) <<\
					12) & 0x00001000U)
#define ATLC_RXDESCRIPTOR_WRD0__WHITEEN__VERIFY(src) \
					(!((((uint32_t)(src) \
					<< 12) & ~0x00001000U)))
#define ATLC_RXDESCRIPTOR_WRD0__WHITEEN__RESET                      0x00000000U
/** @} */
/**
 * @defgroup atlc_RxDescriptor_wrd0 CRCEn 
 * @brief macro for field CRCEn
 * @{
 */
#define ATLC_RXDESCRIPTOR_WRD0__CRCEN__SHIFT                                 11
#define ATLC_RXDESCRIPTOR_WRD0__CRCEN__WIDTH                                  1
#define ATLC_RXDESCRIPTOR_WRD0__CRCEN__MASK                         0x00000800U
#define ATLC_RXDESCRIPTOR_WRD0__CRCEN__READ(src) \
					(((uint32_t)(src) \
					& 0x00000800U) >> 11)
#define ATLC_RXDESCRIPTOR_WRD0__CRCEN__WRITE(src) \
					(((uint32_t)(src) \
					<< 11) & 0x00000800U)
#define ATLC_RXDESCRIPTOR_WRD0__CRCEN__MODIFY(dst, src) \
					(dst) = ((dst) &\
					~0x00000800U) | (((uint32_t)(src) <<\
					11) & 0x00000800U)
#define ATLC_RXDESCRIPTOR_WRD0__CRCEN__VERIFY(src) \
					(!((((uint32_t)(src) \
					<< 11) & ~0x00000800U)))
#define ATLC_RXDESCRIPTOR_WRD0__CRCEN__RESET                        0x00000000U
/** @} */
/**
 * @defgroup atlc_RxDescriptor_wrd0 Rate 
 * @brief macro for field Rate
 * @{
 */
#define ATLC_RXDESCRIPTOR_WRD0__RATE__SHIFT                                   6
#define ATLC_RXDESCRIPTOR_WRD0__RATE__WIDTH                                   4
#define ATLC_RXDESCRIPTOR_WRD0__RATE__MASK                          0x000003C0U
#define ATLC_RXDESCRIPTOR_WRD0__RATE__READ(src) \
					(((uint32_t)(src) \
					& 0x000003C0U) >> 6)
#define ATLC_RXDESCRIPTOR_WRD0__RATE__WRITE(src) \
					(((uint32_t)(src) \
					<< 6) & 0x000003C0U)
#define ATLC_RXDESCRIPTOR_WRD0__RATE__MODIFY(dst, src) \
					(dst) = ((dst) &\
					~0x000003C0U) | (((uint32_t)(src) <<\
					6) & 0x000003C0U)
#define ATLC_RXDESCRIPTOR_WRD0__RATE__VERIFY(src) \
					(!((((uint32_t)(src) \
					<< 6) & ~0x000003C0U)))
#define ATLC_RXDESCRIPTOR_WRD0__RATE__RESET                         0x00000000U
/** @} */
/**
 * @defgroup atlc_RxDescriptor_wrd0 Protocol 
 * @brief macro for field Protocol
 * @{
 */
#define ATLC_RXDESCRIPTOR_WRD0__PROTOCOL__SHIFT                               0
#define ATLC_RXDESCRIPTOR_WRD0__PROTOCOL__WIDTH                               4
#define ATLC_RXDESCRIPTOR_WRD0__PROTOCOL__MASK                      0x0000000FU
#define ATLC_RXDESCRIPTOR_WRD0__PROTOCOL__READ(src) \
					(((uint32_t)(src) \
					& 0x0000000FU) >> 0)
#define ATLC_RXDESCRIPTOR_WRD0__PROTOCOL__WRITE(src) \
					(((uint32_t)(src) \
					<< 0) & 0x0000000FU)
#define ATLC_RXDESCRIPTOR_WRD0__PROTOCOL__MODIFY(dst, src) \
					(dst) = ((dst) &\
					~0x0000000FU) | (((uint32_t)(src) <<\
					0) & 0x0000000FU)
#define ATLC_RXDESCRIPTOR_WRD0__PROTOCOL__VERIFY(src) \
					(!((((uint32_t)(src) \
					<< 0) & ~0x0000000FU)))
#define ATLC_RXDESCRIPTOR_WRD0__PROTOCOL__RESET                     0x00000000U
/** @} */
/** @} */
#endif /*__ATLCRXDESCRIPTOR_WRD0_MACRO__*/
/**
 * @defgroup atlc_RxDescriptor_wrd1
 * @brief RxDescriptorWord1Macro
 * @{
 */
#ifndef __ATCL_RXDESCRIPTOR_WRD1_MACRO__

#define __ATCL_RXDESCRIPTOR_WRD1_MACRO__


/**
 * @defgroup atlc_RxDescriptor_wrd1 AA 
 * @brief macro for field AA
 * @{
 */
#define ATLC_RXDESCRIPTOR_WRD1__AA__SHIFT                                     0
#define ATLC_RXDESCRIPTOR_WRD1__AA__WIDTH                                    32
#define ATLC_RXDESCRIPTOR_WRD1__AA__MASK                            0xFFFFFFFFU
#define ATLC_RXDESCRIPTOR_WRD1__AA__READ(src) \
					(((uint32_t)(src) \
					& 0xFFFFFFFFU) >> 0)
#define ATLC_RXDESCRIPTOR_WRD1__AA__WRITE(src) \
					(((uint32_t)(src) \
					<< 0) & 0xFFFFFFFFU)
#define ATLC_RXDESCRIPTOR_WRD1__AA__MODIFY(dst, src) \
					(dst) = ((dst) &\
					~0xFFFFFFFFU) | (((uint32_t)(src) <<\
					0) & 0xFFFFFFFFU)
#define ATLC_RXDESCRIPTOR_WRD1__AA__VERIFY(src) \
					(!((((uint32_t)(src) \
					<< 0) & ~0xFFFFFFFFU)))
#define ATLC_RXDESCRIPTOR_WRD1__AA__RESET                           0x00000000U
/** @} */
/** @} */
#endif /*__ATLCRXDESCRIPTOR_WRD1_MACRO__*/
/**
 * @defgroup atlc_RxDescriptor_wrd2
 * @brief RxDescriptorWord2Macro
 * @{
 */
#ifndef __ATCL_RXDESCRIPTOR_WRD2_MACRO__

#define __ATCL_RXDESCRIPTOR_WRD2_MACRO__


/**
 * @defgroup atlc_RxDescriptor_wrd2 MaxLen 
 * @brief macro for field MaxLen
 * @{
 */
#define ATLC_RXDESCRIPTOR_WRD2__MAXLEN__SHIFT                                22
#define ATLC_RXDESCRIPTOR_WRD2__MAXLEN__WIDTH                                10
#define ATLC_RXDESCRIPTOR_WRD2__MAXLEN__MASK                        0xFFC00000U
#define ATLC_RXDESCRIPTOR_WRD2__MAXLEN__READ(src) \
					(((uint32_t)(src) \
					& 0xFFC00000U) >> 22)
#define ATLC_RXDESCRIPTOR_WRD2__MAXLEN__WRITE(src) \
					(((uint32_t)(src) \
					<< 22) & 0xFFC00000U)
#define ATLC_RXDESCRIPTOR_WRD2__MAXLEN__MODIFY(dst, src) \
					(dst) = ((dst) &\
					~0xFFC00000U) | (((uint32_t)(src) <<\
					22) & 0xFFC00000U)
#define ATLC_RXDESCRIPTOR_WRD2__MAXLEN__VERIFY(src) \
					(!((((uint32_t)(src) \
					<< 22) & ~0xFFC00000U)))
#define ATLC_RXDESCRIPTOR_WRD2__MAXLEN__RESET                       0x00000000U
/** @} */
/**
 * @defgroup atlc_RxDescriptor_wrd2 EventType 
 * @brief macro for field EventType
 * @{
 */
#define ATLC_RXDESCRIPTOR_WRD2__EVENTTYPE__SHIFT                             18
#define ATLC_RXDESCRIPTOR_WRD2__EVENTTYPE__WIDTH                              4
#define ATLC_RXDESCRIPTOR_WRD2__EVENTTYPE__MASK                     0x003C0000U
#define ATLC_RXDESCRIPTOR_WRD2__EVENTTYPE__READ(src) \
					(((uint32_t)(src) \
					& 0x003C0000U) >> 18)
#define ATLC_RXDESCRIPTOR_WRD2__EVENTTYPE__WRITE(src) \
					(((uint32_t)(src) \
					<< 18) & 0x003C0000U)
#define ATLC_RXDESCRIPTOR_WRD2__EVENTTYPE__MODIFY(dst, src) \
					(dst) = ((dst) &\
					~0x003C0000U) | (((uint32_t)(src) <<\
					18) & 0x003C0000U)
#define ATLC_RXDESCRIPTOR_WRD2__EVENTTYPE__VERIFY(src) \
					(!((((uint32_t)(src) \
					<< 18) & ~0x003C0000U)))
#define ATLC_RXDESCRIPTOR_WRD2__EVENTTYPE__RESET                    0x00000000U
/** @} */
/**
 * @defgroup atlc_RxDescriptor_wrd2 WhiteInitSeed 
 * @brief macro for field WhiteInitSeed
 * @{
 */
#define ATLC_RXDESCRIPTOR_WRD2__WHITEINITSEED__SHIFT                         10
#define ATLC_RXDESCRIPTOR_WRD2__WHITEINITSEED__WIDTH                          8
#define ATLC_RXDESCRIPTOR_WRD2__WHITEINITSEED__MASK                 0x0003FC00U
#define ATLC_RXDESCRIPTOR_WRD2__WHITEINITSEED__READ(src) \
					(((uint32_t)(src) \
					& 0x0003FC00U) >> 10)
#define ATLC_RXDESCRIPTOR_WRD2__WHITEINITSEED__WRITE(src) \
					(((uint32_t)(src) \
					<< 10) & 0x0003FC00U)
#define ATLC_RXDESCRIPTOR_WRD2__WHITEINITSEED__MODIFY(dst, src) \
					(dst) = ((dst) &\
					~0x0003FC00U) | (((uint32_t)(src) <<\
					10) & 0x0003FC00U)
#define ATLC_RXDESCRIPTOR_WRD2__WHITEINITSEED__VERIFY(src) \
					(!((((uint32_t)(src) \
					<< 10) & ~0x0003FC00U)))
#define ATLC_RXDESCRIPTOR_WRD2__WHITEINITSEED__RESET                0x00000000U
/** @} */
/**
 * @defgroup atlc_RxDescriptor_wrd2 StartTimeP5US 
 * @brief macro for field StartTimeP5US
 * @{
 */
#define ATLC_RXDESCRIPTOR_WRD2__STARTTIMEP5US__SHIFT                          0
#define ATLC_RXDESCRIPTOR_WRD2__STARTTIMEP5US__WIDTH                         10
#define ATLC_RXDESCRIPTOR_WRD2__STARTTIMEP5US__MASK                 0x000003FFU
#define ATLC_RXDESCRIPTOR_WRD2__STARTTIMEP5US__READ(src) \
					(((uint32_t)(src) \
					& 0x000003FFU) >> 0)
#define ATLC_RXDESCRIPTOR_WRD2__STARTTIMEP5US__WRITE(src) \
					(((uint32_t)(src) \
					<< 0) & 0x000003FFU)
#define ATLC_RXDESCRIPTOR_WRD2__STARTTIMEP5US__MODIFY(dst, src) \
					(dst) = ((dst) &\
					~0x000003FFU) | (((uint32_t)(src) <<\
					0) & 0x000003FFU)
#define ATLC_RXDESCRIPTOR_WRD2__STARTTIMEP5US__VERIFY(src) \
					(!((((uint32_t)(src) \
					<< 0) & ~0x000003FFU)))
#define ATLC_RXDESCRIPTOR_WRD2__STARTTIMEP5US__RESET                0x00000000U
/** @} */
/** @} */
#endif /*__ATLCRXDESCRIPTOR_WRD2_MACRO__*/
/**
 * @defgroup atlc_RxDescriptor_wrd3
 * @brief RxDescriptorWord3Macro
 * @{
 */
#ifndef __ATCL_RXDESCRIPTOR_WRD3_MACRO__

#define __ATCL_RXDESCRIPTOR_WRD3_MACRO__


/**
 * @defgroup atlc_RxDescriptor_wrd3 CRCInitSeed 
 * @brief macro for field CRCInitSeed
 * @{
 */
#define ATLC_RXDESCRIPTOR_WRD3__CRCINITSEED__SHIFT                            0
#define ATLC_RXDESCRIPTOR_WRD3__CRCINITSEED__WIDTH                           32
#define ATLC_RXDESCRIPTOR_WRD3__CRCINITSEED__MASK                   0xFFFFFFFFU
#define ATLC_RXDESCRIPTOR_WRD3__CRCINITSEED__READ(src) \
					(((uint32_t)(src) \
					& 0xFFFFFFFFU) >> 0)
#define ATLC_RXDESCRIPTOR_WRD3__CRCINITSEED__WRITE(src) \
					(((uint32_t)(src) \
					<< 0) & 0xFFFFFFFFU)
#define ATLC_RXDESCRIPTOR_WRD3__CRCINITSEED__MODIFY(dst, src) \
					(dst) = ((dst) &\
					~0xFFFFFFFFU) | (((uint32_t)(src) <<\
					0) & 0xFFFFFFFFU)
#define ATLC_RXDESCRIPTOR_WRD3__CRCINITSEED__VERIFY(src) \
					(!((((uint32_t)(src) \
					<< 0) & ~0xFFFFFFFFU)))
#define ATLC_RXDESCRIPTOR_WRD3__CRCINITSEED__RESET                  0x00000000U
/** @} */
/** @} */
#endif /*__ATLCRXDESCRIPTOR_WRD3_MACRO__*/
/**
 * @defgroup atlc_RxDescriptor_wrd4
 * @brief RxDescriptorWord4Macro
 * @{
 */
#ifndef __ATCL_RXDESCRIPTOR_WRD4_MACRO__

#define __ATCL_RXDESCRIPTOR_WRD4_MACRO__


/**
 * @defgroup atlc_RxDescriptor_wrd4 StartTimeUS 
 * @brief macro for field StartTimeUS
 * @{
 */
#define ATLC_RXDESCRIPTOR_WRD4__STARTTIMEUS__SHIFT                            0
#define ATLC_RXDESCRIPTOR_WRD4__STARTTIMEUS__WIDTH                           32
#define ATLC_RXDESCRIPTOR_WRD4__STARTTIMEUS__MASK                   0xFFFFFFFFU
#define ATLC_RXDESCRIPTOR_WRD4__STARTTIMEUS__READ(src) \
					(((uint32_t)(src) \
					& 0xFFFFFFFFU) >> 0)
#define ATLC_RXDESCRIPTOR_WRD4__STARTTIMEUS__WRITE(src) \
					(((uint32_t)(src) \
					<< 0) & 0xFFFFFFFFU)
#define ATLC_RXDESCRIPTOR_WRD4__STARTTIMEUS__MODIFY(dst, src) \
					(dst) = ((dst) &\
					~0xFFFFFFFFU) | (((uint32_t)(src) <<\
					0) & 0xFFFFFFFFU)
#define ATLC_RXDESCRIPTOR_WRD4__STARTTIMEUS__VERIFY(src) \
					(!((((uint32_t)(src) \
					<< 0) & ~0xFFFFFFFFU)))
#define ATLC_RXDESCRIPTOR_WRD4__STARTTIMEUS__RESET                  0x00000000U
/** @} */
/** @} */
#endif /*__ATLCRXDESCRIPTOR_WRD4_MACRO__*/
/**
 * @defgroup atlc_RxDescriptor_wrd5
 * @brief RxDescriptorWord5Macro
 * @{
 */
#ifndef __ATCL_RXDESCRIPTOR_WRD5_MACRO__

#define __ATCL_RXDESCRIPTOR_WRD5_MACRO__


/**
 * @defgroup atlc_RxDescriptor_wrd5 StartTime 
 * @brief macro for field StartTime
 * @{
 */
#define ATLC_RXDESCRIPTOR_WRD5__STARTTIME__SHIFT                              0
#define ATLC_RXDESCRIPTOR_WRD5__STARTTIME__WIDTH                             32
#define ATLC_RXDESCRIPTOR_WRD5__STARTTIME__MASK                     0xFFFFFFFFU
#define ATLC_RXDESCRIPTOR_WRD5__STARTTIME__READ(src) \
					(((uint32_t)(src) \
					& 0xFFFFFFFFU) >> 0)
#define ATLC_RXDESCRIPTOR_WRD5__STARTTIME__WRITE(src) \
					(((uint32_t)(src) \
					<< 0) & 0xFFFFFFFFU)
#define ATLC_RXDESCRIPTOR_WRD5__STARTTIME__MODIFY(dst, src) \
					(dst) = ((dst) &\
					~0xFFFFFFFFU) | (((uint32_t)(src) <<\
					0) & 0xFFFFFFFFU)
#define ATLC_RXDESCRIPTOR_WRD5__STARTTIME__VERIFY(src) \
					(!((((uint32_t)(src) \
					<< 0) & ~0xFFFFFFFFU)))
#define ATLC_RXDESCRIPTOR_WRD5__STARTTIME__RESET                    0x00000000U
/** @} */
/** @} */
#endif /*__ATLCRXDESCRIPTOR_WRD5_MACRO__*/
/**
 * @defgroup atlc_RxDescriptor_wrd6
 * @brief RxDescriptorWord6Macro
 * @{
 */
#ifndef __ATCL_RXDESCRIPTOR_WRD6_MACRO__

#define __ATCL_RXDESCRIPTOR_WRD6_MACRO__


/**
 * @defgroup atlc_RxDescriptor_wrd6 RxDataPtr 
 * @brief macro for field RxDataPtr
 * @{
 */
#define ATLC_RXDESCRIPTOR_WRD6__RXDATAPTR__SHIFT                              0
#define ATLC_RXDESCRIPTOR_WRD6__RXDATAPTR__WIDTH                             16
#define ATLC_RXDESCRIPTOR_WRD6__RXDATAPTR__MASK                     0x0000FFFFU
#define ATLC_RXDESCRIPTOR_WRD6__RXDATAPTR__READ(src) \
					(((uint32_t)(src) \
					& 0x0000FFFFU) >> 0)
#define ATLC_RXDESCRIPTOR_WRD6__RXDATAPTR__WRITE(src) \
					(((uint32_t)(src) \
					<< 0) & 0x0000FFFFU)
#define ATLC_RXDESCRIPTOR_WRD6__RXDATAPTR__MODIFY(dst, src) \
					(dst) = ((dst) &\
					~0x0000FFFFU) | (((uint32_t)(src) <<\
					0) & 0x0000FFFFU)
#define ATLC_RXDESCRIPTOR_WRD6__RXDATAPTR__VERIFY(src) \
					(!((((uint32_t)(src) \
					<< 0) & ~0x0000FFFFU)))
#define ATLC_RXDESCRIPTOR_WRD6__RXDATAPTR__RESET                    0x00000000U
/** @} */
/** @} */
#endif /*__ATLCRXDESCRIPTOR_WRD6_MACRO__*/
/**
 * @defgroup atlc_RxDescriptor_wrd7
 * @brief RxDescriptorWord7Macro
 * @{
 */
#ifndef __ATCL_RXDESCRIPTOR_WRD7_MACRO__

#define __ATCL_RXDESCRIPTOR_WRD7_MACRO__


/**
 * @defgroup atlc_RxDescriptor_wrd7 IV_0 
 * @brief macro for field IV_0
 * @{
 */
#define ATLC_RXDESCRIPTOR_WRD7__IV_0__SHIFT                                   0
#define ATLC_RXDESCRIPTOR_WRD7__IV_0__WIDTH                                  32
#define ATLC_RXDESCRIPTOR_WRD7__IV_0__MASK                          0xFFFFFFFFU
#define ATLC_RXDESCRIPTOR_WRD7__IV_0__READ(src) \
					(((uint32_t)(src) \
					& 0xFFFFFFFFU) >> 0)
#define ATLC_RXDESCRIPTOR_WRD7__IV_0__WRITE(src) \
					(((uint32_t)(src) \
					<< 0) & 0xFFFFFFFFU)
#define ATLC_RXDESCRIPTOR_WRD7__IV_0__MODIFY(dst, src) \
					(dst) = ((dst) &\
					~0xFFFFFFFFU) | (((uint32_t)(src) <<\
					0) & 0xFFFFFFFFU)
#define ATLC_RXDESCRIPTOR_WRD7__IV_0__VERIFY(src) \
					(!((((uint32_t)(src) \
					<< 0) & ~0xFFFFFFFFU)))
#define ATLC_RXDESCRIPTOR_WRD7__IV_0__RESET                         0x00000000U
/** @} */
/** @} */
#endif /*__ATLCRXDESCRIPTOR_WRD7_MACRO__*/
/**
 * @defgroup atlc_RxDescriptor_wrd8
 * @brief RxDescriptorWord8Macro
 * @{
 */
#ifndef __ATCL_RXDESCRIPTOR_WRD8_MACRO__

#define __ATCL_RXDESCRIPTOR_WRD8_MACRO__


/**
 * @defgroup atlc_RxDescriptor_wrd8 IV_1 
 * @brief macro for field IV_1
 * @{
 */
#define ATLC_RXDESCRIPTOR_WRD8__IV_1__SHIFT                                   0
#define ATLC_RXDESCRIPTOR_WRD8__IV_1__WIDTH                                  32
#define ATLC_RXDESCRIPTOR_WRD8__IV_1__MASK                          0xFFFFFFFFU
#define ATLC_RXDESCRIPTOR_WRD8__IV_1__READ(src) \
					(((uint32_t)(src) \
					& 0xFFFFFFFFU) >> 0)
#define ATLC_RXDESCRIPTOR_WRD8__IV_1__WRITE(src) \
					(((uint32_t)(src) \
					<< 0) & 0xFFFFFFFFU)
#define ATLC_RXDESCRIPTOR_WRD8__IV_1__MODIFY(dst, src) \
					(dst) = ((dst) &\
					~0xFFFFFFFFU) | (((uint32_t)(src) <<\
					0) & 0xFFFFFFFFU)
#define ATLC_RXDESCRIPTOR_WRD8__IV_1__VERIFY(src) \
					(!((((uint32_t)(src) \
					<< 0) & ~0xFFFFFFFFU)))
#define ATLC_RXDESCRIPTOR_WRD8__IV_1__RESET                         0x00000000U
/** @} */
/** @} */
#endif /*__ATLCRXDESCRIPTOR_WRD8_MACRO__*/
/**
 * @defgroup atlc_RxDescriptor_wrd9
 * @brief RxDescriptorWord9Macro
 * @{
 */
#ifndef __ATCL_RXDESCRIPTOR_WRD9_MACRO__

#define __ATCL_RXDESCRIPTOR_WRD9_MACRO__


/**
 * @defgroup atlc_RxDescriptor_wrd9 PKTCNTR_0 
 * @brief macro for field PKTCNTR_0
 * @{
 */
#define ATLC_RXDESCRIPTOR_WRD9__PKTCNTR_0__SHIFT                              0
#define ATLC_RXDESCRIPTOR_WRD9__PKTCNTR_0__WIDTH                             32
#define ATLC_RXDESCRIPTOR_WRD9__PKTCNTR_0__MASK                     0xFFFFFFFFU
#define ATLC_RXDESCRIPTOR_WRD9__PKTCNTR_0__READ(src) \
					(((uint32_t)(src) \
					& 0xFFFFFFFFU) >> 0)
#define ATLC_RXDESCRIPTOR_WRD9__PKTCNTR_0__WRITE(src) \
					(((uint32_t)(src) \
					<< 0) & 0xFFFFFFFFU)
#define ATLC_RXDESCRIPTOR_WRD9__PKTCNTR_0__MODIFY(dst, src) \
					(dst) = ((dst) &\
					~0xFFFFFFFFU) | (((uint32_t)(src) <<\
					0) & 0xFFFFFFFFU)
#define ATLC_RXDESCRIPTOR_WRD9__PKTCNTR_0__VERIFY(src) \
					(!((((uint32_t)(src) \
					<< 0) & ~0xFFFFFFFFU)))
#define ATLC_RXDESCRIPTOR_WRD9__PKTCNTR_0__RESET                    0x00000000U
/** @} */
/** @} */
#endif /*__ATLCRXDESCRIPTOR_WRD9_MACRO__*/
/**
 * @defgroup atlc_RxDescriptor_wrd10
 * @brief RxDescriptorWord10Macro
 * @{
 */
#ifndef __ATCL_RXDESCRIPTOR_WRD10_MACRO__

#define __ATCL_RXDESCRIPTOR_WRD10_MACRO__


/**
 * @defgroup atlc_RxDescriptor_wrd10 DrctnBt 
 * @brief macro for field DrctnBt
 * @{
 */
#define ATLC_RXDESCRIPTOR_WRD10__DRCTNBT__SHIFT                               8
#define ATLC_RXDESCRIPTOR_WRD10__DRCTNBT__WIDTH                               1
#define ATLC_RXDESCRIPTOR_WRD10__DRCTNBT__MASK                      0x00000100U
#define ATLC_RXDESCRIPTOR_WRD10__DRCTNBT__READ(src) \
					(((uint32_t)(src) \
					& 0x00000100U) >> 8)
#define ATLC_RXDESCRIPTOR_WRD10__DRCTNBT__WRITE(src) \
					(((uint32_t)(src) \
					<< 8) & 0x00000100U)
#define ATLC_RXDESCRIPTOR_WRD10__DRCTNBT__MODIFY(dst, src) \
					(dst) = ((dst) &\
					~0x00000100U) | (((uint32_t)(src) <<\
					8) & 0x00000100U)
#define ATLC_RXDESCRIPTOR_WRD10__DRCTNBT__VERIFY(src) \
					(!((((uint32_t)(src) \
					<< 8) & ~0x00000100U)))
#define ATLC_RXDESCRIPTOR_WRD10__DRCTNBT__RESET                     0x00000000U
/** @} */
/**
 * @defgroup atlc_RxDescriptor_wrd10 PKTCNTR_1 
 * @brief macro for field PKTCNTR_1
 * @{
 */
#define ATLC_RXDESCRIPTOR_WRD10__PKTCNTR_1__SHIFT                             0
#define ATLC_RXDESCRIPTOR_WRD10__PKTCNTR_1__WIDTH                             7
#define ATLC_RXDESCRIPTOR_WRD10__PKTCNTR_1__MASK                    0x0000007FU
#define ATLC_RXDESCRIPTOR_WRD10__PKTCNTR_1__READ(src) \
					(((uint32_t)(src) \
					& 0x0000007FU) >> 0)
#define ATLC_RXDESCRIPTOR_WRD10__PKTCNTR_1__WRITE(src) \
					(((uint32_t)(src) \
					<< 0) & 0x0000007FU)
#define ATLC_RXDESCRIPTOR_WRD10__PKTCNTR_1__MODIFY(dst, src) \
					(dst) = ((dst) &\
					~0x0000007FU) | (((uint32_t)(src) <<\
					0) & 0x0000007FU)
#define ATLC_RXDESCRIPTOR_WRD10__PKTCNTR_1__VERIFY(src) \
					(!((((uint32_t)(src) \
					<< 0) & ~0x0000007FU)))
#define ATLC_RXDESCRIPTOR_WRD10__PKTCNTR_1__RESET                   0x00000000U
/** @} */
/** @} */
#endif /*__ATLCRXDESCRIPTOR_WRD10_MACRO__*/
/**
 * @defgroup atlc_RxDescriptor_wrd11
 * @brief RxDescriptorWord11Macro
 * @{
 */
#ifndef __ATCL_RXDESCRIPTOR_WRD11_MACRO__

#define __ATCL_RXDESCRIPTOR_WRD11_MACRO__


/**
 * @defgroup atlc_RxDescriptor_wrd11 RSVD 
 * @brief macro for field RSVD
 * @{
 */
#define ATLC_RXDESCRIPTOR_WRD11__RSVD__SHIFT                                  0
#define ATLC_RXDESCRIPTOR_WRD11__RSVD__WIDTH                                 32
#define ATLC_RXDESCRIPTOR_WRD11__RSVD__MASK                         0xFFFFFFFFU
#define ATLC_RXDESCRIPTOR_WRD11__RSVD__READ(src) \
					(((uint32_t)(src) \
					& 0xFFFFFFFFU) >> 0)
#define ATLC_RXDESCRIPTOR_WRD11__RSVD__WRITE(src) \
					(((uint32_t)(src) \
					<< 0) & 0xFFFFFFFFU)
#define ATLC_RXDESCRIPTOR_WRD11__RSVD__MODIFY(dst, src) \
					(dst) = ((dst) &\
					~0xFFFFFFFFU) | (((uint32_t)(src) <<\
					0) & 0xFFFFFFFFU)
#define ATLC_RXDESCRIPTOR_WRD11__RSVD__VERIFY(src) \
					(!((((uint32_t)(src) \
					<< 0) & ~0xFFFFFFFFU)))
#define ATLC_RXDESCRIPTOR_WRD11__RSVD__RESET                        0x00000000U
/** @} */
/** @} */
#endif /*__ATLCRXDESCRIPTOR_WRD11_MACRO__*/
/**
 * @defgroup atlc_RxDescriptor_wrd12
 * @brief RxDescriptorWord12Macro
 * @{
 */
#ifndef __ATCL_RXDESCRIPTOR_WRD12_MACRO__

#define __ATCL_RXDESCRIPTOR_WRD12_MACRO__


/**
 * @defgroup atlc_RxDescriptor_wrd12 RSVD 
 * @brief macro for field RSVD
 * @{
 */
#define ATLC_RXDESCRIPTOR_WRD12__RSVD__SHIFT                                  0
#define ATLC_RXDESCRIPTOR_WRD12__RSVD__WIDTH                                 32
#define ATLC_RXDESCRIPTOR_WRD12__RSVD__MASK                         0xFFFFFFFFU
#define ATLC_RXDESCRIPTOR_WRD12__RSVD__READ(src) \
					(((uint32_t)(src) \
					& 0xFFFFFFFFU) >> 0)
#define ATLC_RXDESCRIPTOR_WRD12__RSVD__WRITE(src) \
					(((uint32_t)(src) \
					<< 0) & 0xFFFFFFFFU)
#define ATLC_RXDESCRIPTOR_WRD12__RSVD__MODIFY(dst, src) \
					(dst) = ((dst) &\
					~0xFFFFFFFFU) | (((uint32_t)(src) <<\
					0) & 0xFFFFFFFFU)
#define ATLC_RXDESCRIPTOR_WRD12__RSVD__VERIFY(src) \
					(!((((uint32_t)(src) \
					<< 0) & ~0xFFFFFFFFU)))
#define ATLC_RXDESCRIPTOR_WRD12__RSVD__RESET                        0x00000000U
/** @} */
/** @} */
#endif /*__ATLCRXDESCRIPTOR_WRD12_MACRO__*/
/**
 * @defgroup atlc_RxDescriptor_wrd13
 * @brief RxDescriptorWord13Macro
 * @{
 */
#ifndef __ATCL_RXDESCRIPTOR_WRD13_MACRO__

#define __ATCL_RXDESCRIPTOR_WRD13_MACRO__


/**
 * @defgroup atlc_RxDescriptor_wrd13 Status_RxLen 
 * @brief macro for field Status_RxLen
 * @{
 */
#define ATLC_RXDESCRIPTOR_WRD13__STATUS_RXLEN__SHIFT                         16
#define ATLC_RXDESCRIPTOR_WRD13__STATUS_RXLEN__WIDTH                         16
#define ATLC_RXDESCRIPTOR_WRD13__STATUS_RXLEN__MASK                 0xFFFF0000U
#define ATLC_RXDESCRIPTOR_WRD13__STATUS_RXLEN__READ(src) \
					(((uint32_t)(src) \
					& 0xFFFF0000U) >> 16)
#define ATLC_RXDESCRIPTOR_WRD13__STATUS_RXLEN__WRITE(src) \
					(((uint32_t)(src) \
					<< 16) & 0xFFFF0000U)
#define ATLC_RXDESCRIPTOR_WRD13__STATUS_RXLEN__MODIFY(dst, src) \
					(dst) = ((dst) &\
					~0xFFFF0000U) | (((uint32_t)(src) <<\
					16) & 0xFFFF0000U)
#define ATLC_RXDESCRIPTOR_WRD13__STATUS_RXLEN__VERIFY(src) \
					(!((((uint32_t)(src) \
					<< 16) & ~0xFFFF0000U)))
#define ATLC_RXDESCRIPTOR_WRD13__STATUS_RXLEN__RESET                0x00000000U
/** @} */
/**
 * @defgroup atlc_RxDescriptor_wrd13 Status_RSSI 
 * @brief macro for field Status_RSSI
 * @{
 */
#define ATLC_RXDESCRIPTOR_WRD13__STATUS_RSSI__SHIFT                           8
#define ATLC_RXDESCRIPTOR_WRD13__STATUS_RSSI__WIDTH                           8
#define ATLC_RXDESCRIPTOR_WRD13__STATUS_RSSI__MASK                  0x0000FF00U
#define ATLC_RXDESCRIPTOR_WRD13__STATUS_RSSI__READ(src) \
					(((uint32_t)(src) \
					& 0x0000FF00U) >> 8)
#define ATLC_RXDESCRIPTOR_WRD13__STATUS_RSSI__WRITE(src) \
					(((uint32_t)(src) \
					<< 8) & 0x0000FF00U)
#define ATLC_RXDESCRIPTOR_WRD13__STATUS_RSSI__MODIFY(dst, src) \
					(dst) = ((dst) &\
					~0x0000FF00U) | (((uint32_t)(src) <<\
					8) & 0x0000FF00U)
#define ATLC_RXDESCRIPTOR_WRD13__STATUS_RSSI__VERIFY(src) \
					(!((((uint32_t)(src) \
					<< 8) & ~0x0000FF00U)))
#define ATLC_RXDESCRIPTOR_WRD13__STATUS_RSSI__RESET                 0x00000000U
/** @} */
/**
 * @defgroup atlc_RxDescriptor_wrd13 Status_SyncWord 
 * @brief macro for field Status_SyncWord
 * @{
 */
#define ATLC_RXDESCRIPTOR_WRD13__STATUS_SYNCWORD__SHIFT                       5
#define ATLC_RXDESCRIPTOR_WRD13__STATUS_SYNCWORD__WIDTH                       1
#define ATLC_RXDESCRIPTOR_WRD13__STATUS_SYNCWORD__MASK              0x00000020U
#define ATLC_RXDESCRIPTOR_WRD13__STATUS_SYNCWORD__READ(src) \
					(((uint32_t)(src) \
					& 0x00000020U) >> 5)
#define ATLC_RXDESCRIPTOR_WRD13__STATUS_SYNCWORD__WRITE(src) \
					(((uint32_t)(src) \
					<< 5) & 0x00000020U)
#define ATLC_RXDESCRIPTOR_WRD13__STATUS_SYNCWORD__MODIFY(dst, src) \
					(dst) = ((dst) &\
					~0x00000020U) | (((uint32_t)(src) <<\
					5) & 0x00000020U)
#define ATLC_RXDESCRIPTOR_WRD13__STATUS_SYNCWORD__VERIFY(src) \
					(!((((uint32_t)(src) \
					<< 5) & ~0x00000020U)))
#define ATLC_RXDESCRIPTOR_WRD13__STATUS_SYNCWORD__RESET             0x00000000U
/** @} */
/**
 * @defgroup atlc_RxDescriptor_wrd13 Status_Discard 
 * @brief macro for field Status_Discard
 * @{
 */
#define ATLC_RXDESCRIPTOR_WRD13__STATUS_DISCARD__SHIFT                        4
#define ATLC_RXDESCRIPTOR_WRD13__STATUS_DISCARD__WIDTH                        1
#define ATLC_RXDESCRIPTOR_WRD13__STATUS_DISCARD__MASK               0x00000010U
#define ATLC_RXDESCRIPTOR_WRD13__STATUS_DISCARD__READ(src) \
					(((uint32_t)(src) \
					& 0x00000010U) >> 4)
#define ATLC_RXDESCRIPTOR_WRD13__STATUS_DISCARD__WRITE(src) \
					(((uint32_t)(src) \
					<< 4) & 0x00000010U)
#define ATLC_RXDESCRIPTOR_WRD13__STATUS_DISCARD__MODIFY(dst, src) \
					(dst) = ((dst) &\
					~0x00000010U) | (((uint32_t)(src) <<\
					4) & 0x00000010U)
#define ATLC_RXDESCRIPTOR_WRD13__STATUS_DISCARD__VERIFY(src) \
					(!((((uint32_t)(src) \
					<< 4) & ~0x00000010U)))
#define ATLC_RXDESCRIPTOR_WRD13__STATUS_DISCARD__RESET              0x00000000U
/** @} */
/**
 * @defgroup atlc_RxDescriptor_wrd13 Status_LengthError 
 * @brief macro for field Status_LengthError
 * @{
 */
#define ATLC_RXDESCRIPTOR_WRD13__STATUS_LENGTHERROR__SHIFT                    3
#define ATLC_RXDESCRIPTOR_WRD13__STATUS_LENGTHERROR__WIDTH                    1
#define ATLC_RXDESCRIPTOR_WRD13__STATUS_LENGTHERROR__MASK           0x00000008U
#define ATLC_RXDESCRIPTOR_WRD13__STATUS_LENGTHERROR__READ(src) \
					(((uint32_t)(src) \
					& 0x00000008U) >> 3)
#define ATLC_RXDESCRIPTOR_WRD13__STATUS_LENGTHERROR__WRITE(src) \
					(((uint32_t)(src) \
					<< 3) & 0x00000008U)
#define ATLC_RXDESCRIPTOR_WRD13__STATUS_LENGTHERROR__MODIFY(dst, src) \
					(dst) = ((dst) &\
					~0x00000008U) | (((uint32_t)(src) <<\
					3) & 0x00000008U)
#define ATLC_RXDESCRIPTOR_WRD13__STATUS_LENGTHERROR__VERIFY(src) \
					(!((((uint32_t)(src) \
					<< 3) & ~0x00000008U)))
#define ATLC_RXDESCRIPTOR_WRD13__STATUS_LENGTHERROR__RESET          0x00000000U
/** @} */
/**
 * @defgroup atlc_RxDescriptor_wrd13 Status_MICError 
 * @brief macro for field Status_MICError
 * @{
 */
#define ATLC_RXDESCRIPTOR_WRD13__STATUS_MICERROR__SHIFT                       2
#define ATLC_RXDESCRIPTOR_WRD13__STATUS_MICERROR__WIDTH                       1
#define ATLC_RXDESCRIPTOR_WRD13__STATUS_MICERROR__MASK              0x00000004U
#define ATLC_RXDESCRIPTOR_WRD13__STATUS_MICERROR__READ(src) \
					(((uint32_t)(src) \
					& 0x00000004U) >> 2)
#define ATLC_RXDESCRIPTOR_WRD13__STATUS_MICERROR__WRITE(src) \
					(((uint32_t)(src) \
					<< 2) & 0x00000004U)
#define ATLC_RXDESCRIPTOR_WRD13__STATUS_MICERROR__MODIFY(dst, src) \
					(dst) = ((dst) &\
					~0x00000004U) | (((uint32_t)(src) <<\
					2) & 0x00000004U)
#define ATLC_RXDESCRIPTOR_WRD13__STATUS_MICERROR__VERIFY(src) \
					(!((((uint32_t)(src) \
					<< 2) & ~0x00000004U)))
#define ATLC_RXDESCRIPTOR_WRD13__STATUS_MICERROR__RESET             0x00000000U
/** @} */
/**
 * @defgroup atlc_RxDescriptor_wrd13 Status_CRCError 
 * @brief macro for field Status_CRCError
 * @{
 */
#define ATLC_RXDESCRIPTOR_WRD13__STATUS_CRCERROR__SHIFT                       1
#define ATLC_RXDESCRIPTOR_WRD13__STATUS_CRCERROR__WIDTH                       1
#define ATLC_RXDESCRIPTOR_WRD13__STATUS_CRCERROR__MASK              0x00000002U
#define ATLC_RXDESCRIPTOR_WRD13__STATUS_CRCERROR__READ(src) \
					(((uint32_t)(src) \
					& 0x00000002U) >> 1)
#define ATLC_RXDESCRIPTOR_WRD13__STATUS_CRCERROR__WRITE(src) \
					(((uint32_t)(src) \
					<< 1) & 0x00000002U)
#define ATLC_RXDESCRIPTOR_WRD13__STATUS_CRCERROR__MODIFY(dst, src) \
					(dst) = ((dst) &\
					~0x00000002U) | (((uint32_t)(src) <<\
					1) & 0x00000002U)
#define ATLC_RXDESCRIPTOR_WRD13__STATUS_CRCERROR__VERIFY(src) \
					(!((((uint32_t)(src) \
					<< 1) & ~0x00000002U)))
#define ATLC_RXDESCRIPTOR_WRD13__STATUS_CRCERROR__RESET             0x00000000U
/** @} */
/**
 * @defgroup atlc_RxDescriptor_wrd13 Status_TimeOutErr 
 * @brief macro for field Status_TimeOutErr
 * @{
 */
#define ATLC_RXDESCRIPTOR_WRD13__STATUS_TIMEOUTERR__SHIFT                     0
#define ATLC_RXDESCRIPTOR_WRD13__STATUS_TIMEOUTERR__WIDTH                     1
#define ATLC_RXDESCRIPTOR_WRD13__STATUS_TIMEOUTERR__MASK            0x00000001U
#define ATLC_RXDESCRIPTOR_WRD13__STATUS_TIMEOUTERR__READ(src) \
					(((uint32_t)(src) \
					& 0x00000001U) >> 0)
#define ATLC_RXDESCRIPTOR_WRD13__STATUS_TIMEOUTERR__WRITE(src) \
					(((uint32_t)(src) \
					<< 0) & 0x00000001U)
#define ATLC_RXDESCRIPTOR_WRD13__STATUS_TIMEOUTERR__MODIFY(dst, src) \
					(dst) = ((dst) &\
					~0x00000001U) | (((uint32_t)(src) <<\
					0) & 0x00000001U)
#define ATLC_RXDESCRIPTOR_WRD13__STATUS_TIMEOUTERR__VERIFY(src) \
					(!((((uint32_t)(src) \
					<< 0) & ~0x00000001U)))
#define ATLC_RXDESCRIPTOR_WRD13__STATUS_TIMEOUTERR__RESET           0x00000000U
/** @} */
/** @} */
#endif /*__ATLCRXDESCRIPTOR_WRD13_MACRO__*/
/**
 * @defgroup atlc_RxDescriptor_wrd14
 * @brief RxDescriptorWord14Macro
 * @{
 */
#ifndef __ATCL_RXDESCRIPTOR_WRD14_MACRO__

#define __ATCL_RXDESCRIPTOR_WRD14_MACRO__


/**
 * @defgroup atlc_RxDescriptor_wrd14 Status_DataReadyTimeStamp 
 * @brief macro for field Status_DataReadyTimeStamp
 * @{
 */
#define ATLC_RXDESCRIPTOR_WRD14__STATUS_DATAREADYTIMESTAMP__SHIFT             0
#define ATLC_RXDESCRIPTOR_WRD14__STATUS_DATAREADYTIMESTAMP__WIDTH            32
#define ATLC_RXDESCRIPTOR_WRD14__STATUS_DATAREADYTIMESTAMP__MASK    0xFFFFFFFFU
#define ATLC_RXDESCRIPTOR_WRD14__STATUS_DATAREADYTIMESTAMP__READ(src) \
					(((uint32_t)(src) \
					& 0xFFFFFFFFU) >> 0)
#define ATLC_RXDESCRIPTOR_WRD14__STATUS_DATAREADYTIMESTAMP__WRITE(src) \
					(((uint32_t)(src) \
					<< 0) & 0xFFFFFFFFU)
#define ATLC_RXDESCRIPTOR_WRD14__STATUS_DATAREADYTIMESTAMP__MODIFY(dst, src) \
					(dst) = ((dst) &\
					~0xFFFFFFFFU) | (((uint32_t)(src) <<\
					0) & 0xFFFFFFFFU)
#define ATLC_RXDESCRIPTOR_WRD14__STATUS_DATAREADYTIMESTAMP__VERIFY(src) \
					(!((((uint32_t)(src) \
					<< 0) & ~0xFFFFFFFFU)))
#define ATLC_RXDESCRIPTOR_WRD14__STATUS_DATAREADYTIMESTAMP__RESET   0x00000000U
/** @} */
/** @} */
#endif /*__ATLCRXDESCRIPTOR_WRD14_MACRO__*/
/**
 * @defgroup atlc_RxDescriptor_wrd15
 * @brief RxDescriptorWord15Macro
 * @{
 */
#ifndef __ATCL_RXDESCRIPTOR_WRD15_MACRO__

#define __ATCL_RXDESCRIPTOR_WRD15_MACRO__


/**
 * @defgroup atlc_RxDescriptor_wrd15 Status_SyncTimeStamp 
 * @brief macro for field Status_SyncTimeStamp
 * @{
 */
#define ATLC_RXDESCRIPTOR_WRD15__STATUS_SYNCTIMESTAMP__SHIFT                  0
#define ATLC_RXDESCRIPTOR_WRD15__STATUS_SYNCTIMESTAMP__WIDTH                 32
#define ATLC_RXDESCRIPTOR_WRD15__STATUS_SYNCTIMESTAMP__MASK         0xFFFFFFFFU
#define ATLC_RXDESCRIPTOR_WRD15__STATUS_SYNCTIMESTAMP__READ(src) \
					(((uint32_t)(src) \
					& 0xFFFFFFFFU) >> 0)
#define ATLC_RXDESCRIPTOR_WRD15__STATUS_SYNCTIMESTAMP__WRITE(src) \
					(((uint32_t)(src) \
					<< 0) & 0xFFFFFFFFU)
#define ATLC_RXDESCRIPTOR_WRD15__STATUS_SYNCTIMESTAMP__MODIFY(dst, src) \
					(dst) = ((dst) &\
					~0xFFFFFFFFU) | (((uint32_t)(src) <<\
					0) & 0xFFFFFFFFU)
#define ATLC_RXDESCRIPTOR_WRD15__STATUS_SYNCTIMESTAMP__VERIFY(src) \
					(!((((uint32_t)(src) \
					<< 0) & ~0xFFFFFFFFU)))
#define ATLC_RXDESCRIPTOR_WRD15__STATUS_SYNCTIMESTAMP__RESET        0x00000000U
/** @} */
/** @} */
#endif /*__ATLCRXDESCRIPTOR_WRD15_MACRO__*/
#endif /*__AT_LC_DESCRIPTOR_MACRO_H__*/
