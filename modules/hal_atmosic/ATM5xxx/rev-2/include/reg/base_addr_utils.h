/**
 *****************************************************************************
 *
 * @file base_addr_utils.h
 *
 * @brief Base Address Utility definitions
 *
 * Copyright (C) Atmosic 2022-2026
 *
 *****************************************************************************
 */

#pragma once


#include "base_addr.h"

/**
 * @defgroup at_base_addr_utils base_addr_utils
 * @ingroup AT_REG
 * @brief base address utils definitions.
 * @{
 */
/*---------- AT_AHB_SHA2 ----------*/
/*---------- Field name map ----------*/
static inline char const *CMSDK_AT_AHB_SHA2_offset_to_str(uint32_t offset) {
  switch (offset) {
  case 0: return "CONTROL";
  case 4: return "SIDELOAD_CTRL";
  case 8: return "CMD";
  case 12: return "MESSAGE_LENGTH_LO";
  case 16: return "MESSAGE_LENGTH_HI";
  case 20: return "WIPE_V";
  case 24: return "FIFO_PUSH";
  case 28: return "DIGEST0";
  case 32: return "DIGEST1";
  case 36: return "DIGEST2";
  case 40: return "DIGEST3";
  case 44: return "DIGEST4";
  case 48: return "DIGEST5";
  case 52: return "DIGEST6";
  case 56: return "DIGEST7";
  case 60: return "KEY_0";
  case 64: return "KEY_1";
  case 68: return "KEY_2";
  case 72: return "KEY_3";
  case 76: return "KEY_4";
  case 80: return "KEY_5";
  case 84: return "KEY_6";
  case 88: return "KEY_7";
  case 92: return "STATUS";
  case 96: return "INTERRUPT_STATUS";
  case 100: return "INTERRUPT_MASK";
  case 104: return "SET_INTERRUPT";
  case 108: return "RESET_INTERRUPT";
  case 112: return "ERR_CODE";
  case 116: return "TXCOUNT_LO";
  case 120: return "TXCOUNT_HI";
  case 124: return "SHA_TXCOUNT_LO";
  case 128: return "SHA_TXCOUNT_HI";
  case 4092: return "ID";
  default: return "unknown CMSDK_AT_AHB_SHA2 offset";
  }
}

/*---------- Iterator ----------*/
static inline uint32_t CMSDK_AT_AHB_SHA2_begin_offset() { return 0; }
static inline int CMSDK_AT_AHB_SHA2_end_offset(uint32_t offset) { return offset >= sizeof(CMSDK_AT_AHB_SHA2_TypeDef); }
static inline uint32_t CMSDK_AT_AHB_SHA2_next_offset(uint32_t offset) {
  switch (offset) {
  case 128: return 4092;
  default: return offset + 4;
  }
}
/*---------- AT_LC ----------*/
/*---------- Field name map ----------*/
static inline char const *CMSDK_AT_LC_offset_to_str(uint32_t offset) {
  switch (offset) {
  case 0: return "DBG_CTRL0";
  case 4: return "DBG_CTRL1";
  case 8: return "DBG_CTRL2";
  case 12: return "LC_CTRL6";
  case 16: return "LC_CTRL8";
  case 20: return "LC_CTRL9";
  case 24: return "LC_CTRL10";
  case 28: return "LC_CTRL11";
  case 32: return "LC_FMAC_CTRL0";
  case 36: return "LC_FMAC_CTRL1";
  case 40: return "LC_FMAC_CTRL2";
  case 44: return "LC_FMAC_CTRL3";
  case 48: return "LC_FMAC_CTRL4";
  case 52: return "LC_FMAC_CTRL5";
  case 56: return "LC_FMAC_CTRL6";
  case 60: return "LC_FMAC_CTRL7";
  case 64: return "LC_BLE_CTRL0";
  case 68: return "LC_BLE_CTRL1";
  case 72: return "LC_BLE_CTRL2";
  case 76: return "LC_BLE_CTRL3";
  case 80: return "LC_BLE_CTRL4";
  case 84: return "LC_BLE_CTRL5";
  case 88: return "LC_BLE_CTRL6";
  case 92: return "LC_BLE_CTRL7";
  case 96: return "MAC_154_CTRL0";
  case 100: return "MAC_154_CTRL1";
  case 104: return "MAC_154_CTRL2";
  case 108: return "MAC_154_CTRL3";
  case 112: return "MAC_154_CTRL4";
  case 116: return "MAC_154_CTRL5";
  case 120: return "MAC_154_CTRL6";
  case 124: return "MAC_154_CTRL7";
  case 128: return "AESCCM_ACC_CTRL0";
  case 132: return "AESCCM_ACC_CTRL1";
  case 136: return "AESCCM_ACC_CTRL2";
  case 140: return "AESCCM_ACC_CTRL3";
  case 144: return "AESCCM_ACC_CTRL4";
  case 148: return "MAC_154_CCA";
  case 152: return "MDM_CTRL0";
  case 156: return "LC_LP_CTRL0";
  case 160: return "LC_LP_CTRL1";
  case 164: return "LC_LP_CTRL2";
  case 168: return "LC_LP_CTRL3";
  case 172: return "LC_LP_CTRL4";
  case 176: return "LC_LP_CTRL5";
  case 180: return "LC_LP_ST0";
  case 184: return "LC_LP_ST1";
  case 188: return "LC_LP_ST2";
  case 192: return "LC_LP_ST3";
  case 196: return "LC_LP_ST4";
  case 200: return "LC_LP_ST5";
  case 204: return "LC_RFT_CTRL0";
  case 208: return "LC_RFT_CTRL1";
  case 212: return "IFG";
  case 216: return "PTHDLY_1MBPS_FMAC";
  case 220: return "PTHDLY_2MBPS_FMAC";
  case 224: return "PTHDLY_250KBPS_FMAC";
  case 228: return "PTHDLY_SW_FMAC";
  case 232: return "PWRUD_1MBPS_FMAC";
  case 236: return "PWRUD_2MBPS_FMAC";
  case 240: return "PWRUD_250KBPS_FMAC";
  case 244: return "PTHDLY_1MBPS_BLE";
  case 248: return "PTHDLY_2MBPS_BLE";
  case 252: return "PTHDLY_500KBPS_BLE";
  case 256: return "PTHDLY_125KBPS_BLE";
  case 260: return "PTHDLY_SW_BLE";
  case 264: return "PWRUD_1MBPS_BLE";
  case 268: return "PWRUD_2MBPS_BLE";
  case 272: return "PWRUD_500KBPS_BLE";
  case 276: return "PWRUD_125KBPS_BLE";
  case 280: return "PTHDLY_250KBPS_154";
  case 284: return "ED_PTHDLY_250KBPS_154";
  case 288: return "PTHDLY_SW_154";
  case 292: return "PWRUD_250KBPS_154";
  case 296: return "RTX_WAIT";
  case 300: return "LC_ST0";
  case 304: return "LC_ST0_CLR";
  case 308: return "LC_ST2";
  case 312: return "LC_ST3";
  case 316: return "LC_ST3_CLR";
  case 320: return "LC_ST4";
  case 324: return "LC_ST5";
  case 328: return "LC_ST6";
  case 332: return "LC_ST7";
  case 336: return "LC_ST8";
  case 340: return "LC_ST9";
  case 344: return "LC_SECU_ST0";
  case 348: return "TX_ST";
  case 352: return "TX_ED";
  case 356: return "RX_ST";
  case 360: return "RX_PRMBL_ST";
  case 364: return "RX_ED";
  case 368: return "FRC_CTRL";
  case 372: return "FRC_TO0";
  case 376: return "FRC_TO1";
  case 380: return "FRC_TO2";
  case 384: return "LC_FMAC_WHT_CTRL";
  case 388: return "LC_BLE_WHT_CTRL";
  case 392: return "MAC_154_WHT_CTRL";
  case 396: return "ND_CTRL";
  case 400: return "LC_FMAC_SYNC_WRD0";
  case 404: return "LC_FMAC_SYNC_WRD1";
  case 408: return "LC_BLE_SYNC_WRD";
  case 412: return "MAC_154_SYNC_WRD";
  case 416: return "RX_ADDR0";
  case 420: return "RX_ADDR1";
  case 424: return "RX_ADDR2";
  case 428: return "RX_ADDR3";
  case 432: return "RX_ADDR4";
  case 436: return "RX_ADDR5";
  case 440: return "RX_ADDR6";
  case 444: return "RX_ADDR7";
  case 448: return "TFF0_ADDR";
  case 452: return "RFF0_ADDR";
  case 456: return "TFF1_ADDR";
  case 460: return "RFF1_ADDR";
  case 464: return "TFF2_ADDR";
  case 468: return "RFF2_ADDR";
  case 472: return "TFF3_ADDR";
  case 476: return "RFF3_ADDR";
  case 480: return "TFF4_ADDR";
  case 484: return "RFF4_ADDR";
  case 488: return "TFF5_ADDR";
  case 492: return "RFF5_ADDR";
  case 496: return "TFF6_ADDR";
  case 500: return "RFF6_ADDR";
  case 504: return "TFF7_ADDR";
  case 508: return "RFF7_ADDR";
  case 512: return "TFF0_RPTR";
  case 516: return "TFF0_WPTR";
  case 520: return "RFF0_RPTR";
  case 524: return "RFF0_WPTR";
  case 528: return "TFF1_RPTR";
  case 532: return "TFF1_WPTR";
  case 536: return "RFF1_RPTR";
  case 540: return "RFF1_WPTR";
  case 544: return "TFF2_RPTR";
  case 548: return "TFF2_WPTR";
  case 552: return "RFF2_RPTR";
  case 556: return "RFF2_WPTR";
  case 560: return "TFF3_RPTR";
  case 564: return "TFF3_WPTR";
  case 568: return "RFF3_RPTR";
  case 572: return "RFF3_WPTR";
  case 576: return "TFF4_RPTR";
  case 580: return "TFF4_WPTR";
  case 584: return "RFF4_RPTR";
  case 588: return "RFF4_WPTR";
  case 592: return "TFF5_RPTR";
  case 596: return "TFF5_WPTR";
  case 600: return "RFF5_RPTR";
  case 604: return "RFF5_WPTR";
  case 608: return "TFF6_RPTR";
  case 612: return "TFF6_WPTR";
  case 616: return "RFF6_RPTR";
  case 620: return "RFF6_WPTR";
  case 624: return "TFF7_RPTR";
  case 628: return "TFF7_WPTR";
  case 632: return "RFF7_RPTR";
  case 636: return "RFF7_WPTR";
  case 640: return "CRC_PLYNML_FMAC";
  case 644: return "CRC_PLYNML_BLE";
  case 648: return "CRC_PLYNML_154";
  case 652: return "LC_FMAC_CRC_CTRL";
  case 656: return "LC_BLE_CRC_CTRL";
  case 660: return "MAC_154_CRC_CTRL";
  case 664: return "CMD";
  case 668: return "CMD_US";
  case 672: return "CMD_320US";
  case 676: return "ND_ST";
  case 680: return "LC_IRQ";
  case 684: return "LC_IRQM";
  case 688: return "LC_IRQS";
  case 692: return "LC_IRQC";
  case 696: return "LC_FRC_IRQ";
  case 700: return "LC_FRC_IRQM";
  case 704: return "LC_FRC_IRQS";
  case 708: return "LC_FRC_IRQC";
  case 712: return "AESCTRL";
  case 716: return "AESTRIG";
  case 720: return "AES_STATUS";
  case 724: return "AESKEY_S0_0";
  case 728: return "AESKEY_S0_1";
  case 732: return "AESKEY_S0_2";
  case 736: return "AESKEY_S0_3";
  case 740: return "AESKEY_S0_4";
  case 744: return "AESKEY_S0_5";
  case 748: return "AESKEY_S0_6";
  case 752: return "AESKEY_S0_7";
  case 756: return "AESKEY_S1_0";
  case 760: return "AESKEY_S1_1";
  case 764: return "AESKEY_S1_2";
  case 768: return "AESKEY_S1_3";
  case 772: return "AESKEY_S1_4";
  case 776: return "AESKEY_S1_5";
  case 780: return "AESKEY_S1_6";
  case 784: return "AESKEY_S1_7";
  case 788: return "IV0";
  case 792: return "IV1";
  case 796: return "IV2";
  case 800: return "IV3";
  case 804: return "IDATA0";
  case 808: return "IDATA1";
  case 812: return "IDATA2";
  case 816: return "IDATA3";
  case 820: return "ODATA0";
  case 824: return "ODATA1";
  case 828: return "ODATA2";
  case 832: return "ODATA3";
  case 836: return "AESKEYSL_BLE_S0_0";
  case 840: return "AESKEYSL_BLE_S0_1";
  case 844: return "AESKEYSL_BLE_S0_2";
  case 848: return "AESKEYSL_BLE_S0_3";
  case 852: return "AESKEYSL_BLE_S0_4";
  case 856: return "AESKEYSL_BLE_S0_5";
  case 860: return "AESKEYSL_BLE_S0_6";
  case 864: return "AESKEYSL_BLE_S0_7";
  case 868: return "AESKEYSL_BLE_S1_0";
  case 872: return "AESKEYSL_BLE_S1_1";
  case 876: return "AESKEYSL_BLE_S1_2";
  case 880: return "AESKEYSL_BLE_S1_3";
  case 884: return "AESKEYSL_BLE_S1_4";
  case 888: return "AESKEYSL_BLE_S1_5";
  case 892: return "AESKEYSL_BLE_S1_6";
  case 896: return "AESKEYSL_BLE_S1_7";
  case 900: return "AESKEYSL_154_S0_0";
  case 904: return "AESKEYSL_154_S0_1";
  case 908: return "AESKEYSL_154_S0_2";
  case 912: return "AESKEYSL_154_S0_3";
  case 916: return "AESKEYSL_154_S0_4";
  case 920: return "AESKEYSL_154_S0_5";
  case 924: return "AESKEYSL_154_S0_6";
  case 928: return "AESKEYSL_154_S0_7";
  case 932: return "AESKEYSL_154_S1_0";
  case 936: return "AESKEYSL_154_S1_1";
  case 940: return "AESKEYSL_154_S1_2";
  case 944: return "AESKEYSL_154_S1_3";
  case 948: return "AESKEYSL_154_S1_4";
  case 952: return "AESKEYSL_154_S1_5";
  case 956: return "AESKEYSL_154_S1_6";
  case 960: return "AESKEYSL_154_S1_7";
  case 964: return "CRYPT_CTRL0";
  case 968: return "CRYPT_IV_BLE_0";
  case 972: return "CRYPT_IV_BLE_1";
  case 976: return "CRYPT_CTRL_BLE";
  case 980: return "CRYPT_PKTCNTR_BLE_0";
  case 984: return "CRYPT_PKTCNTR_BLE_1";
  case 988: return "ZB_RF4CE_NONCE_0";
  case 992: return "ZB_RF4CE_NONCE_1";
  case 996: return "ZB_RF4CE_NONCE_2";
  case 1000: return "ZB_RF4CE_NONCE_3";
  case 1004: return "RF4CE_SPEB1_0";
  case 1008: return "RF4CE_SPEB1_1";
  case 1012: return "DFT";
  case 1016: return "LC_BLE_CTRL8";
  case 1020: return "LC_FMAC_CTRL8";
  case 1024: return "LC_FMAC_CRC_CTRL2";
  case 1028: return "LC_DF_CTRL0";
  case 1032: return "LC_DF_ST0";
  case 1036: return "DF_ASW_CTRL0";
  case 1040: return "DF_ASW_CTRL1";
  case 1044: return "DF_ANT_ID0";
  case 1048: return "DF_ANT_ID1";
  case 1052: return "DF_ANT_ID2";
  case 1056: return "DF_ANT_ID3";
  case 1060: return "DF_I_SMPL_ADDR";
  case 1064: return "DF_Q_SMPL_ADDR";
  case 1068: return "LC_CS_CTRL0";
  case 1072: return "LC_CS_TM_CTRL0";
  case 1076: return "LC_CS_TM_CTRL1";
  case 1080: return "LC_CS_TM_CTRL2";
  case 1084: return "LC_CS_TM_OFFST_CRRCT";
  case 1088: return "LC_CS_ITX_RRX_SYNC_WRD";
  case 1092: return "LC_CS_ITX_RRX_SEQ0";
  case 1096: return "LC_CS_ITX_RRX_SEQ1";
  case 1100: return "LC_CS_ITX_RRX_SEQ2";
  case 1104: return "LC_CS_ITX_RRX_SEQ3";
  case 1108: return "LC_CS_IRX_RTX_SYNC_WRD";
  case 1112: return "LC_CS_IRX_RTX_SEQ0";
  case 1116: return "LC_CS_IRX_RTX_SEQ1";
  case 1120: return "LC_CS_IRX_RTX_SEQ2";
  case 1124: return "LC_CS_IRX_RTX_SEQ3";
  case 1128: return "CS_ST0";
  case 1132: return "CS_ST1";
  case 1136: return "PTHDLY_DF_1US_1MBPS_BLE";
  case 1140: return "PTHDLY_DF_2US_1MBPS_BLE";
  case 1144: return "PTHDLY_DF_1US_2MBPS_BLE";
  case 1148: return "PTHDLY_DF_2US_2MBPS_BLE";
  case 1152: return "PTHDLY_1MBPS_BLE_CS_TN";
  case 1156: return "PTHDLY_2MBPS_BLE_CS_TN";
  case 1160: return "PTHDLY_1MBPS_BLE_CS";
  case 1164: return "PTHDLY_2MBPS_BLE_CS";
  case 1168: return "TX_ST_FN";
  case 1172: return "TX_ED_FN";
  case 1176: return "RX_ST_FN";
  case 1180: return "RX_PRMBL_ST_FN";
  case 1184: return "RX_ED_FN";
  case 1188: return "DTOP";
  case 1192: return "LC_CS_IRQ";
  case 1196: return "LC_CS_IRQM";
  case 1200: return "LC_CS_IRQS";
  case 1204: return "LC_CS_IRQC";
  case 1208: return "PWRUD_1MBPS_BLE_CS_TN";
  case 1212: return "PWRUD_2MBPS_BLE_CS_TN";
  case 1216: return "PWRUD_1MBPS_BLE_CS";
  case 1220: return "PWRUD_2MBPS_BLE_CS";
  case 4084: return "ID";
  case 4088: return "REV_HASH";
  case 4092: return "REV_KEY";
  default: return "unknown CMSDK_AT_LC offset";
  }
}

/*---------- Iterator ----------*/
static inline uint32_t CMSDK_AT_LC_begin_offset() { return 0; }
static inline int CMSDK_AT_LC_end_offset(uint32_t offset) { return offset >= sizeof(CMSDK_AT_LC_TypeDef); }
static inline uint32_t CMSDK_AT_LC_next_offset(uint32_t offset) {
  switch (offset) {
  case 1220: return 4084;
  default: return offset + 4;
  }
}
/*---------- AT_APB_WRPR_PINS ----------*/
/*---------- Field name map ----------*/
static inline char const *CMSDK_AT_APB_WRPR_PINS_offset_to_str(uint32_t offset) {
  switch (offset) {
  case 0: return "APB0_CTRL";
  case 4: return "APB1_CTRL";
  case 8: return "APB2_CTRL";
  case 12: return "APB3_CTRL";
  case 16: return "APB4_CTRL";
  case 20: return "APB5_CTRL";
  case 24: return "APB6_CTRL";
  case 28: return "APB7_CTRL";
  case 32: return "APB8_CTRL";
  case 36: return "APB9_CTRL";
  case 40: return "APB10_CTRL";
  case 44: return "APB11_CTRL";
  case 48: return "APB12_CTRL";
  case 52: return "APB13_CTRL";
  case 56: return "APB14_CTRL";
  case 60: return "APB15_CTRL";
  case 64: return "CLK_HPC_PIN_OUT_CTRL";
  case 68: return "CLK_MPC_PIN_OUT_CTRL";
  case 72: return "CLK_LPC_PIN_OUT_CTRL";
  case 76: return "DBG_CTRL";
  case 80: return "PSEL_A";
  case 84: return "PSEL_B";
  case 88: return "PSEL_C";
  case 92: return "PSEL_D";
  case 96: return "PSEL_E";
  case 100: return "PSEL_F";
  case 104: return "PSEL_G";
  case 108: return "PSEL_H";
  case 112: return "PSEL_I";
  case 116: return "PSEL_J";
  case 120: return "PSEL_K";
  case 124: return "PSEL_L";
  case 128: return "PSEL_M";
  case 132: return "PUPD_OVRD";
  case 136: return "PUPD_OVRD_VAL";
  case 140: return "PUPD_OVRD2";
  case 144: return "PUPD_OVRD_VAL2";
  case 148: return "REMAP";
  case 152: return "AHB_INTERPOSERS";
  case 156: return "SCRATCHPAD_A";
  case 160: return "SCRATCHPAD_B";
  case 164: return "SCRATCHPAD_C";
  case 168: return "SCRATCHPAD_D";
  case 172: return "RRAM_WRITE_PROTECTION0";
  case 176: return "RRAM_WRITE_PROTECTION1";
  case 180: return "RRAM_WRITE_PROTECTION2";
  case 184: return "RRAM_WRITE_PROTECTION3";
  case 188: return "RRAM_WRITE_PROTECTION4";
  case 192: return "RRAM_WRITE_PROTECTION5";
  case 196: return "RRAM_WRITE_PROTECTION6";
  case 200: return "RRAM_WRITE_PROTECTION7";
  case 204: return "RRAM_STICKY_WRITE_PROTECTION0";
  case 208: return "RRAM_STICKY_WRITE_PROTECTION1";
  case 212: return "RRAM_STICKY_WRITE_PROTECTION2";
  case 216: return "RRAM_STICKY_WRITE_PROTECTION3";
  case 220: return "RRAM_STICKY_WRITE_PROTECTION4";
  case 224: return "RRAM_STICKY_WRITE_PROTECTION5";
  case 228: return "RRAM_STICKY_WRITE_PROTECTION6";
  case 232: return "RRAM_STICKY_WRITE_PROTECTION7";
  case 236: return "RRAM_STICKY_WRITE_PROTECTION_STATUS0";
  case 240: return "RRAM_STICKY_WRITE_PROTECTION_STATUS1";
  case 244: return "RRAM_STICKY_WRITE_PROTECTION_STATUS2";
  case 248: return "RRAM_STICKY_WRITE_PROTECTION_STATUS3";
  case 252: return "RRAM_STICKY_WRITE_PROTECTION_STATUS4";
  case 256: return "RRAM_STICKY_WRITE_PROTECTION_STATUS5";
  case 260: return "RRAM_STICKY_WRITE_PROTECTION_STATUS6";
  case 264: return "RRAM_STICKY_WRITE_PROTECTION_STATUS7";
  case 268: return "RRAM_STICKY_READ_PROTECTION0";
  case 272: return "RRAM_STICKY_READ_PROTECTION_STATUS0";
  case 276: return "PROT_BITS_SET0";
  case 280: return "PROT_BITS_SET1";
  case 284: return "PROT_BITS_STAT0";
  case 288: return "PROT_BITS_STAT1";
  case 292: return "QSPI_STICKY_WRITE_PROTECTION0";
  case 296: return "QSPI_STICKY_WRITE_PROTECTION1";
  case 300: return "QSPI_STICKY_WRITE_PROTECTION2";
  case 304: return "QSPI_STICKY_WRITE_PROTECTION3";
  case 308: return "QSPI_STICKY_WRITE_PROTECTION_STATUS0";
  case 312: return "QSPI_STICKY_WRITE_PROTECTION_STATUS1";
  case 316: return "QSPI_STICKY_WRITE_PROTECTION_STATUS2";
  case 320: return "QSPI_STICKY_WRITE_PROTECTION_STATUS3";
  case 324: return "QSPI_STICKY_READ_PROTECTION0";
  case 328: return "QSPI_STICKY_READ_PROTECTION_STATUS0";
  case 332: return "CALCOUNTRC";
  case 336: return "SECURE_DEBUG_CTRL";
  case 340: return "SECURE_DEBUG_STAT";
  case 344: return "PSEQ_CURRENT_REAL_TIME";
  case 348: return "GLITCHLESS_IO0";
  case 352: return "GLITCHLESS_IO1";
  case 356: return "GLITCHLESS_IO2";
  case 360: return "GLITCHLESS_IO3";
  case 364: return "GLITCHLESS_IO4";
  case 368: return "GLITCHLESS_IO5";
  case 372: return "GLITCHLESS_IO6";
  case 376: return "GLITCHLESS_IO7";
  case 380: return "GLITCHLESS_IO8";
  case 384: return "GLITCHLESS_IO9";
  case 388: return "GLITCHLESS_IO10";
  case 392: return "GLITCHLESS_IO11";
  case 396: return "PDSN_A";
  case 400: return "PDSN_B";
  case 404: return "PDSN_C";
  case 408: return "PDSN_D";
  case 412: return "PIPE_LINE_CTRL";
  case 416: return "RRAM_REMAP0";
  case 420: return "RRAM_REMAP1";
  case 424: return "RRAM_REMAP2";
  case 428: return "RRAM_REMAP3";
  case 432: return "RRAM_REMAP4";
  case 436: return "RRAM_REMAP5";
  case 440: return "SOC_MISC_CTRL";
  case 444: return "PIPE_LINE_EN_STAT";
  case 4072: return "CHIPID1";
  case 4076: return "CHIPID2";
  case 4080: return "CHIPREV";
  case 4084: return "CORE_ID";
  case 4088: return "REV_HASH";
  case 4092: return "REV_KEY";
  default: return "unknown CMSDK_AT_APB_WRPR_PINS offset";
  }
}

/*---------- Iterator ----------*/
static inline uint32_t CMSDK_AT_APB_WRPR_PINS_begin_offset() { return 0; }
static inline int CMSDK_AT_APB_WRPR_PINS_end_offset(uint32_t offset) { return offset >= sizeof(CMSDK_AT_APB_WRPR_PINS_TypeDef); }
static inline uint32_t CMSDK_AT_APB_WRPR_PINS_next_offset(uint32_t offset) {
  switch (offset) {
  case 444: return 4072;
  default: return offset + 4;
  }
}
/*---------- AT_APB_UART ----------*/
/*---------- Field name map ----------*/
static inline char const *CMSDK_AT_APB_UART_offset_to_str(uint32_t offset) {
  switch (offset) {
  case 0: return "DATA";
  case 4: return "STATE";
  case 8: return "CTRL";
  case 12: return "INTSTATUS_CLEAR";
  case 16: return "BAUDDIV";
  case 20: return "RX_LWM";
  case 24: return "TX_LWM";
  case 28: return "RX_FIFO_SPACES";
  case 32: return "TX_FIFO_SPACES";
  case 36: return "HW_FLOW_OVRD";
  case 40: return "BAUD_RATE_DETECT";
  case 44: return "BAUD_DIV_CEIL";
  case 48: return "BRD_STAT";
  case 52: return "INTMASK";
  case 56: return "RX_FIFO_ENTRIES";
  case 60: return "INTSTATUS_SET";
  case 64: return "TX_CTRL";
  case 68: return "RX_CTRL";
  case 4036: return "PID4";
  case 4040: return "PID5";
  case 4044: return "PID6";
  case 4048: return "PID7";
  case 4052: return "PID0";
  case 4056: return "PID1";
  case 4060: return "PID2";
  case 4064: return "PID3";
  case 4068: return "CID0";
  case 4072: return "CID1";
  case 4076: return "CID2";
  case 4080: return "CID3";
  case 4084: return "CORE_ID";
  case 4088: return "REV_HASH";
  case 4092: return "REV_KEY";
  default: return "unknown CMSDK_AT_APB_UART offset";
  }
}

/*---------- Iterator ----------*/
static inline uint32_t CMSDK_AT_APB_UART_begin_offset() { return 0; }
static inline int CMSDK_AT_APB_UART_end_offset(uint32_t offset) { return offset >= sizeof(CMSDK_AT_APB_UART_TypeDef); }
static inline uint32_t CMSDK_AT_APB_UART_next_offset(uint32_t offset) {
  switch (offset) {
  case 68: return 4036;
  default: return offset + 4;
  }
}
/*---------- AT_APB_PWM ----------*/
/*---------- Field name map ----------*/
static inline char const *CMSDK_AT_APB_PWM_offset_to_str(uint32_t offset) {
  switch (offset) {
  case 0: return "PWM_CTRL";
  case 4: return "PWM0_CTRL";
  case 8: return "PWM0_DUR";
  case 12: return "PWM0_CFG";
  case 16: return "PWM1_CTRL";
  case 20: return "PWM1_DUR";
  case 24: return "PWM1_CFG";
  case 28: return "PWM2_CTRL";
  case 32: return "PWM2_DUR";
  case 36: return "PWM2_CFG";
  case 40: return "PWM3_CTRL";
  case 44: return "PWM3_DUR";
  case 48: return "PWM3_CFG";
  case 52: return "PWM4_CTRL";
  case 56: return "PWM4_DUR";
  case 60: return "PWM4_CFG";
  case 64: return "PWM5_CTRL";
  case 68: return "PWM5_DUR";
  case 72: return "PWM5_CFG";
  case 76: return "PWM6_CTRL";
  case 80: return "PWM6_DUR";
  case 84: return "PWM6_CFG";
  case 88: return "PWM7_CTRL";
  case 92: return "PWM7_DUR";
  case 96: return "PWM7_CFG";
  case 100: return "FSM_STATE";
  case 104: return "FIFO_CFG";
  case 108: return "FIFO_CARRIER1_DUR";
  case 112: return "FIFO_CARRIER2_DUR";
  case 116: return "FIFO_STAT";
  case 120: return "FIFO_STAT1";
  case 124: return "FIFO_SEL_ERR_SOURCE";
  case 128: return "INTERRUPTS";
  case 132: return "INTERRUPTS_MASK";
  case 136: return "INTERRUPTS_CLEAR";
  case 140: return "INTERRUPTS_SET";
  case 4080: return "FIFO_DATA";
  case 4084: return "CORE_ID";
  case 4088: return "REV_HASH";
  case 4092: return "REV_KEY";
  default: return "unknown CMSDK_AT_APB_PWM offset";
  }
}

/*---------- Iterator ----------*/
static inline uint32_t CMSDK_AT_APB_PWM_begin_offset() { return 0; }
static inline int CMSDK_AT_APB_PWM_end_offset(uint32_t offset) { return offset >= sizeof(CMSDK_AT_APB_PWM_TypeDef); }
static inline uint32_t CMSDK_AT_APB_PWM_next_offset(uint32_t offset) {
  switch (offset) {
  case 140: return 4080;
  default: return offset + 4;
  }
}
/*---------- AT_APB_SPI ----------*/
/*---------- Field name map ----------*/
static inline char const *CMSDK_AT_APB_SPI_offset_to_str(uint32_t offset) {
  switch (offset) {
  case 0: return "CTRL";
  case 4: return "TRANSACTION_SETUP";
  case 8: return "TRANSACTION_SETUP_2";
  case 12: return "TRANSACTION_SETUP_DMA";
  case 16: return "TRANSACTION_STATUS";
  case 20: return "DATA_BYTES_LOWER";
  case 24: return "DATA_BYTES_UPPER";
  case 28: return "INTERRUPT_MASK";
  case 32: return "INTERRUPT_STATUS";
  case 36: return "SET_INTERRUPT";
  case 40: return "RESET_INTERRUPT";
  case 4084: return "CORE_ID";
  case 4088: return "REV_HASH";
  case 4092: return "REV_KEY";
  default: return "unknown CMSDK_AT_APB_SPI offset";
  }
}

/*---------- Iterator ----------*/
static inline uint32_t CMSDK_AT_APB_SPI_begin_offset() { return 0; }
static inline int CMSDK_AT_APB_SPI_end_offset(uint32_t offset) { return offset >= sizeof(CMSDK_AT_APB_SPI_TypeDef); }
static inline uint32_t CMSDK_AT_APB_SPI_next_offset(uint32_t offset) {
  switch (offset) {
  case 40: return 4084;
  default: return offset + 4;
  }
}
/*---------- AT_APB_KSM ----------*/
/*---------- Field name map ----------*/
static inline char const *CMSDK_AT_APB_KSM_offset_to_str(uint32_t offset) {
  switch (offset) {
  case 0: return "CTRL0";
  case 4: return "TIME_PARAM0";
  case 8: return "TIME_PARAM1";
  case 12: return "MATRIX_SIZE";
  case 56: return "KEYBOARD_IDLE_CTRL";
  case 60: return "KEYBOARD_CYCLE";
  case 64: return "KEYBOARD_PACKET";
  case 68: return "LOW_POWER";
  case 88: return "LPBACK_KSI";
  case 128: return "STATUS";
  case 192: return "INTERRUPTS";
  case 196: return "INTERRUPT_MASK";
  case 200: return "INTERRUPT_CLEAR";
  case 256: return "KEY_BUF0";
  case 260: return "KEY_BUF1";
  case 264: return "KEY_BUF2";
  case 268: return "KEY_BUF3";
  case 272: return "KEY_BUF4";
  case 276: return "KEY_BUF5";
  case 280: return "KEY_BUF6";
  case 284: return "KEY_BUF7";
  case 288: return "KEY_BUF8";
  case 292: return "KEY_BUF9";
  case 296: return "KEY_BUF10";
  case 300: return "KEY_BUF11";
  case 4076: return "DEBUG";
  case 4080: return "DEBUG2";
  case 4084: return "CORE_ID";
  case 4088: return "REV_HASH";
  case 4092: return "REV_KEY";
  default: return "unknown CMSDK_AT_APB_KSM offset";
  }
}

/*---------- Iterator ----------*/
static inline uint32_t CMSDK_AT_APB_KSM_begin_offset() { return 0; }
static inline int CMSDK_AT_APB_KSM_end_offset(uint32_t offset) { return offset >= sizeof(CMSDK_AT_APB_KSM_TypeDef); }
static inline uint32_t CMSDK_AT_APB_KSM_next_offset(uint32_t offset) {
  switch (offset) {
  case 12: return 56;
  case 68: return 88;
  case 88: return 128;
  case 128: return 192;
  case 200: return 256;
  case 300: return 4076;
  default: return offset + 4;
  }
}
/*---------- AT_APB_QDEC ----------*/
/*---------- Field name map ----------*/
static inline char const *CMSDK_AT_APB_QDEC_offset_to_str(uint32_t offset) {
  switch (offset) {
  case 0: return "SETUP_FOR_AXIS_0";
  case 4: return "ACCUM_PURGE_STATUS_FOR_AXIS_0";
  case 8: return "ACCUMULATOR_VALUE_FOR_AXIS_0";
  case 12: return "ERR_PURGE_STATUS_FOR_AXIS_0";
  case 16: return "ERROR_COUNT_FOR_AXIS_0";
  case 20: return "SETUP_FOR_AXIS_1";
  case 24: return "ACCUM_PURGE_STATUS_FOR_AXIS_1";
  case 28: return "ACCUMULATOR_VALUE_FOR_AXIS_1";
  case 32: return "ERR_PURGE_STATUS_FOR_AXIS_1";
  case 36: return "ERROR_COUNT_FOR_AXIS_1";
  case 40: return "SETUP_FOR_AXIS_2";
  case 44: return "ACCUM_PURGE_STATUS_FOR_AXIS_2";
  case 48: return "ACCUMULATOR_VALUE_FOR_AXIS_2";
  case 52: return "ERR_PURGE_STATUS_FOR_AXIS_2";
  case 56: return "ERROR_COUNT_FOR_AXIS_2";
  case 4084: return "CORE_ID";
  case 4088: return "REV_HASH";
  case 4092: return "REV_KEY";
  default: return "unknown CMSDK_AT_APB_QDEC offset";
  }
}

/*---------- Iterator ----------*/
static inline uint32_t CMSDK_AT_APB_QDEC_begin_offset() { return 0; }
static inline int CMSDK_AT_APB_QDEC_end_offset(uint32_t offset) { return offset >= sizeof(CMSDK_AT_APB_QDEC_TypeDef); }
static inline uint32_t CMSDK_AT_APB_QDEC_next_offset(uint32_t offset) {
  switch (offset) {
  case 56: return 4084;
  default: return offset + 4;
  }
}
/*---------- AT_APB_SLWTIMER ----------*/
/*---------- Field name map ----------*/
static inline char const *CMSDK_AT_APB_SLWTIMER_offset_to_str(uint32_t offset) {
  switch (offset) {
  case 0: return "CONTROL";
  case 4: return "INIT_LOW";
  case 8: return "INIT_HIGH";
  case 12: return "CNT_LOW";
  case 16: return "CNT_HIGH";
  case 20: return "THRES0_LOW";
  case 24: return "THRES0_HIGH";
  case 28: return "THRES1_LOW";
  case 32: return "THRES1_HIGH";
  case 36: return "THRES2_LOW";
  case 40: return "THRES2_HIGH";
  case 44: return "STATUS";
  case 48: return "INTERRUPT_STATUS";
  case 52: return "INTERRUPT_MASK";
  case 4084: return "CORE_ID";
  case 4088: return "REV_HASH";
  case 4092: return "REV_KEY";
  default: return "unknown CMSDK_AT_APB_SLWTIMER offset";
  }
}

/*---------- Iterator ----------*/
static inline uint32_t CMSDK_AT_APB_SLWTIMER_begin_offset() { return 0; }
static inline int CMSDK_AT_APB_SLWTIMER_end_offset(uint32_t offset) { return offset >= sizeof(CMSDK_AT_APB_SLWTIMER_TypeDef); }
static inline uint32_t CMSDK_AT_APB_SLWTIMER_next_offset(uint32_t offset) {
  switch (offset) {
  case 52: return 4084;
  default: return offset + 4;
  }
}
/*---------- AT_APB_QSPI ----------*/
/*---------- Field name map ----------*/
static inline char const *CMSDK_AT_APB_QSPI_offset_to_str(uint32_t offset) {
  switch (offset) {
  case 0: return "TRANSACTION_SETUP";
  case 4: return "READ_DATA";
  case 8: return "OVERRIDE_DIN";
  case 12: return "MODE";
  case 16: return "SCRATCHPAD";
  case 20: return "REMOTE_AHB_SETUP";
  case 24: return "REMOTE_AHB_SETUP_2";
  case 28: return "REMOTE_AHB_SETUP_3";
  case 32: return "REMOTE_AHB_SETUP_4";
  case 36: return "REMOTE_AHB_SETUP_5";
  case 40: return "REMOTE_AHB_SETUP_6";
  case 44: return "REMOTE_AHB_SETUP_7";
  case 48: return "REMOTE_AHB_SETUP_8";
  case 52: return "REMOTE_AHB_SETUP_9";
  case 56: return "REMOTE_AHB_SETUP_10";
  case 60: return "REMOTE_AHB_SETUP_11";
  case 64: return "REMOTE_PREFETCH_SETUP";
  case 68: return "REMOTE_CACHE_SETUP";
  case 72: return "REMOTE_STATUS";
  case 76: return "REMOTE_PREFETCH_STATUS";
  case 80: return "REMOTE_AHB_WLE_CNT";
  case 84: return "REMOTE_AHB_WIP_CNT";
  case 88: return "REMOTE_STS_CTRL0";
  case 92: return "REMOTE_STS_CTRL1";
  case 96: return "PREFETCH_STS_CNT0";
  case 100: return "PREFETCH_STS_CNT1";
  case 104: return "PREFETCH_STS_CNT2";
  case 108: return "PREFETCH_STS_CNT3";
  case 112: return "PREFETCH_STS_CNT4";
  case 116: return "PREFETCH_STS_CNT5";
  case 120: return "CACHE_STS_CNT0";
  case 124: return "CACHE_STS_CNT1";
  case 128: return "BURST_PP_CTRL";
  case 4084: return "CORE_ID";
  case 4088: return "REV_HASH";
  case 4092: return "REV_KEY";
  default: return "unknown CMSDK_AT_APB_QSPI offset";
  }
}

/*---------- Iterator ----------*/
static inline uint32_t CMSDK_AT_APB_QSPI_begin_offset() { return 0; }
static inline int CMSDK_AT_APB_QSPI_end_offset(uint32_t offset) { return offset >= sizeof(CMSDK_AT_APB_QSPI_TypeDef); }
static inline uint32_t CMSDK_AT_APB_QSPI_next_offset(uint32_t offset) {
  switch (offset) {
  case 128: return 4084;
  default: return offset + 4;
  }
}
/*---------- AT_APB_I2C ----------*/
/*---------- Field name map ----------*/
static inline char const *CMSDK_AT_APB_I2C_offset_to_str(uint32_t offset) {
  switch (offset) {
  case 0: return "CTRL";
  case 4: return "TRANSACTION_SETUP";
  case 8: return "CLOCK_CONTROL";
  case 12: return "OUTGOING_DATA";
  case 16: return "OUTGOING_DATA1";
  case 20: return "IO_CTRL";
  case 24: return "INCOMING_DATA";
  case 28: return "INCOMING_DATA1";
  case 32: return "TRANSACTION_STATUS";
  case 36: return "INTERRUPT_MASK";
  case 40: return "INTERRUPT_STATUS";
  case 44: return "SET_INTERRUPT";
  case 48: return "RESET_INTERRUPT";
  case 4084: return "ID";
  case 4088: return "REV_HASH";
  case 4092: return "REV_KEY";
  default: return "unknown CMSDK_AT_APB_I2C offset";
  }
}

/*---------- Iterator ----------*/
static inline uint32_t CMSDK_AT_APB_I2C_begin_offset() { return 0; }
static inline int CMSDK_AT_APB_I2C_end_offset(uint32_t offset) { return offset >= sizeof(CMSDK_AT_APB_I2C_TypeDef); }
static inline uint32_t CMSDK_AT_APB_I2C_next_offset(uint32_t offset) {
  switch (offset) {
  case 48: return 4084;
  default: return offset + 4;
  }
}
/*---------- AT_APB_UMC_NVM ----------*/
/*---------- Field name map ----------*/
static inline char const *CMSDK_AT_APB_UMC_NVM_offset_to_str(uint32_t offset) {
  switch (offset) {
  case 0: return "OPMODE";
  case 4: return "OPMODE1";
  case 8: return "STATUS";
  case 12: return "STATUS1";
  case 16: return "OTP_CFG_LOW";
  case 20: return "OTP_CFG_HIGH";
  case 24: return "T_RD_TIME0";
  case 28: return "T_RD_TIME1";
  case 32: return "T_RD_TIME2";
  case 36: return "T_RD_TIME3";
  case 40: return "T_RD_TIME4";
  case 44: return "T_PR_TIME0";
  case 48: return "T_PR_TIME1";
  case 52: return "T_PR_TIME2";
  case 56: return "T_PR_TIME3";
  case 60: return "T_PR_TIME4";
  case 64: return "T_PR_TIME5";
  case 68: return "INTERRUPT_STATUS";
  case 72: return "INTERRUPT_MASK";
  case 76: return "INTERRUPT_SET";
  case 80: return "INTERRUPT_RESET";
  case 4084: return "CORE_ID";
  case 4088: return "REV_HASH";
  case 4092: return "REV_KEY";
  default: return "unknown CMSDK_AT_APB_UMC_NVM offset";
  }
}

/*---------- Iterator ----------*/
static inline uint32_t CMSDK_AT_APB_UMC_NVM_begin_offset() { return 0; }
static inline int CMSDK_AT_APB_UMC_NVM_end_offset(uint32_t offset) { return offset >= sizeof(CMSDK_AT_APB_UMC_NVM_TypeDef); }
static inline uint32_t CMSDK_AT_APB_UMC_NVM_next_offset(uint32_t offset) {
  switch (offset) {
  case 80: return 4084;
  default: return offset + 4;
  }
}
/*---------- AT_APB_WRPR_SHORT ----------*/
/*---------- Field name map ----------*/
static inline char const *CMSDK_AT_APB_WRPR_SHORT_offset_to_str(uint32_t offset) {
  switch (offset) {
  case 0: return "APB0_CTRL";
  case 4: return "APB1_CTRL";
  case 8: return "APB2_CTRL";
  case 12: return "APB3_CTRL";
  case 16: return "APB4_CTRL";
  case 20: return "APB5_CTRL";
  case 24: return "APB6_CTRL";
  case 28: return "APB7_CTRL";
  case 32: return "APB8_CTRL";
  case 36: return "APB9_CTRL";
  case 40: return "APB10_CTRL";
  case 44: return "APB11_CTRL";
  case 48: return "APB12_CTRL";
  case 52: return "APB13_CTRL";
  case 56: return "APB14_CTRL";
  case 60: return "APB15_CTRL";
  case 64: return "OTP_INIT_LOWER";
  case 68: return "OTP_INIT_UPPER";
  case 4084: return "CORE_ID";
  case 4088: return "REV_HASH";
  case 4092: return "REV_KEY";
  default: return "unknown CMSDK_AT_APB_WRPR_SHORT offset";
  }
}

/*---------- Iterator ----------*/
static inline uint32_t CMSDK_AT_APB_WRPR_SHORT_begin_offset() { return 0; }
static inline int CMSDK_AT_APB_WRPR_SHORT_end_offset(uint32_t offset) { return offset >= sizeof(CMSDK_AT_APB_WRPR_SHORT_TypeDef); }
static inline uint32_t CMSDK_AT_APB_WRPR_SHORT_next_offset(uint32_t offset) {
  switch (offset) {
  case 68: return 4084;
  default: return offset + 4;
  }
}
/*---------- RIF ----------*/
/*---------- Field name map ----------*/
static inline char const *CMSDK_RIF_offset_to_str(uint32_t offset) {
  switch (offset) {
  case 0: return "BIAS";
  case 4: return "RXBBF";
  case 8: return "RXBBF_1M";
  case 12: return "RXBBF_2M";
  case 16: return "SYNTX_MODGAIN";
  case 20: return "SYNTX_VCOCAP";
  case 24: return "LNA";
  case 28: return "RGT";
  case 32: return "RGTHW";
  case 36: return "TXGAIN0";
  case 40: return "TXGAIN1";
  case 44: return "TXGAIN2";
  case 48: return "TXGAIN3";
  case 52: return "RXGAIN0";
  case 56: return "RXGAIN1";
  case 60: return "RXGAIN2";
  case 64: return "RXGAIN3";
  case 68: return "RXGAIN4";
  case 72: return "RXGAIN5";
  case 76: return "RXGAIN6";
  case 80: return "RXGAIN7";
  case 84: return "RXGAIN8";
  case 88: return "RXGAIN9";
  case 92: return "RXGAIN10";
  case 96: return "RXGAIN11";
  case 100: return "RXGAIN12";
  case 104: return "RXGAIN13";
  case 108: return "RXGAIN14";
  case 112: return "RXGAIN15";
  case 116: return "TRNG_CONF";
  case 120: return "SYNTX_CAL";
  case 124: return "SYNTX_154";
  case 128: return "SYNTX0";
  case 132: return "SYNTX1";
  case 136: return "SYNTX2";
  case 140: return "SYNTX3";
  case 144: return "SYNTX4";
  case 148: return "SYNTX5";
  case 152: return "SYNTX6";
  case 156: return "DUTY_CYCLE";
  case 160: return "TXGAIN0_PMU";
  case 164: return "TXGAIN1_PMU";
  case 168: return "TXGAIN2_PMU";
  case 172: return "RX0";
  case 176: return "TIMER0";
  case 180: return "TIMER1";
  case 184: return "TIMER2";
  case 188: return "TIMER3";
  case 192: return "TIMER154";
  case 196: return "HADM_TIMER0";
  case 200: return "HADM_TIMER1";
  case 204: return "HADM_TIMER2";
  case 208: return "HADM_TIMER3";
  case 212: return "RXDC7";
  case 216: return "SYNTH_CHAN0";
  case 220: return "SYNTH_CHAN1";
  case 224: return "SYNTH_CHAN2";
  case 228: return "SYNTH_CHAN3";
  case 232: return "SYNTH_CHAN4";
  case 236: return "SYNTH_CHAN5";
  case 240: return "ADC_CNTL";
  case 244: return "MODE_CNTL";
  case 248: return "MODE_CNTL2";
  case 252: return "XLNA_XPA_CNTL";
  case 256: return "CAL_CNTL";
  case 260: return "CAL_DONE";
  case 264: return "INTERRUPT_STATUS";
  case 268: return "INTERRUPT_MASK";
  case 272: return "INTERRUPT_RESET";
  case 276: return "DFT";
  case 280: return "RIF_I_TEST";
  case 284: return "RIF_Q_TEST";
  case 288: return "SYNTX_COMLIF";
  case 292: return "SYNTX_SINGLERX";
  case 296: return "TIMERCSTONE";
  case 4084: return "ID";
  case 4088: return "REV_HASH";
  case 4092: return "REV_KEY";
  default: return "unknown CMSDK_RIF offset";
  }
}

/*---------- Iterator ----------*/
static inline uint32_t CMSDK_RIF_begin_offset() { return 0; }
static inline int CMSDK_RIF_end_offset(uint32_t offset) { return offset >= sizeof(CMSDK_RIF_TypeDef); }
static inline uint32_t CMSDK_RIF_next_offset(uint32_t offset) {
  switch (offset) {
  case 296: return 4084;
  default: return offset + 4;
  }
}
/*---------- MDM ----------*/
/*---------- Field name map ----------*/
static inline char const *CMSDK_MDM_offset_to_str(uint32_t offset) {
  switch (offset) {
  case 0: return "AGCMEAS";
  case 4: return "AGCGAIN";
  case 8: return "DCOFF";
  case 12: return "TIA_FORCE_DCCALRESULTS";
  case 16: return "TIA_FORCE_DCCALRESULTS2";
  case 20: return "TIA_LP_FORCE_DCCALRESULTS";
  case 24: return "TIA_LP_FORCE_DCCALRESULTS2";
  case 28: return "PGA_FORCE_DCCALRESULTS";
  case 32: return "PGA_FORCE_DCCALRESULTS2";
  case 36: return "PGA_LP_FORCE_DCCALRESULTS";
  case 40: return "PGA_LP_FORCE_DCCALRESULTS2";
  case 44: return "DUMMY1";
  case 48: return "PGA_CAL_GAIN_FORCE_DCCALRESULTS";
  case 52: return "PGA_CAL_GAIN_FORCE_DCCALRESULTS2";
  case 56: return "IQCORR";
  case 60: return "IQCORR2";
  case 64: return "IQCORR154";
  case 68: return "AGCMEAS_ALT";
  case 72: return "AGCGAIN_ALT";
  case 76: return "TEST_154";
  case 80: return "TEST_154_CHP_1TO0_1";
  case 84: return "TEST_154_CHP_1TO0_0";
  case 88: return "TEST_154_CHP_0TO1_1";
  case 92: return "TEST_154_CHP_0TO1_0";
  case 96: return "TEST_154_CHP_1TO1";
  case 100: return "TEST_154_CHP_0TO0";
  case 104: return "LNA_TIA_LW_DCCAL_DC0";
  case 108: return "LNA_TIA_LW_DCCAL_DC1";
  case 112: return "LNA_TIA_LW_DCCAL_DC2";
  case 116: return "LNA_TIA_LW_DCCAL_DC3";
  case 120: return "LNA_TIA_MD_DCCAL_DC0";
  case 124: return "LNA_TIA_MD_DCCAL_DC1";
  case 128: return "LNA_TIA_MD_DCCAL_DC2";
  case 132: return "LNA_TIA_MD_DCCAL_DC3";
  case 136: return "LNA_TIA_HG_DCCAL_DC0";
  case 140: return "LNA_TIA_HG_DCCAL_DC1";
  case 144: return "LNA_TIA_HG_DCCAL_DC2";
  case 148: return "LNA_TIA_HG_DCCAL_DC3";
  case 152: return "XLNA";
  case 156: return "XLNA_ALT";
  case 160: return "AGCSAT";
  case 164: return "AGCSAT_ALT";
  case 168: return "BASELINE";
  case 172: return "BASELINE_ALT";
  case 176: return "MARGIN";
  case 180: return "MARGIN_ALT";
  case 184: return "PWRSTEP";
  case 188: return "PWRSTEP_ALT";
  case 192: return "AGCPWR";
  case 196: return "AGCPWR_ALT";
  case 200: return "AGCPWR2";
  case 204: return "AGCPWR2_ALT";
  case 208: return "AGCTIME";
  case 212: return "AGCTIME_ALT";
  case 216: return "TWOMEG_AGCTIME";
  case 220: return "TWOMEG_AGCTIME_ALT";
  case 224: return "AGCTIME2";
  case 228: return "AGCTIME2_ALT";
  case 232: return "AGCCNTL";
  case 236: return "AGCCNTL_ALT";
  case 240: return "AGCPD";
  case 244: return "AGCPD_ALT";
  case 248: return "AGCDET";
  case 252: return "AGCDET_ALT";
  case 256: return "AGCOFFSET";
  case 260: return "AGCOFFSET_ALT";
  case 264: return "SYNCH";
  case 268: return "SYNCH_ALT";
  case 272: return "TIMETRACK";
  case 276: return "TIMESYNC";
  case 280: return "TIMESYNC_ALT";
  case 284: return "SYNCDEMOD";
  case 288: return "SYNCDEMOD_ALT";
  case 292: return "RESETINITCFO";
  case 296: return "RESETINITCFO_ALT";
  case 300: return "INTMFREQ";
  case 304: return "INTMFREQ_ALT";
  case 308: return "TSTIMEOUT";
  case 312: return "DEMOD";
  case 316: return "DFEWITHFFE";
  case 320: return "DFEWITHOUTFFE";
  case 324: return "TWOMEG_DFEWITHFFE";
  case 328: return "TWOMEG_DFEWITHOUTFFE";
  case 332: return "FREQ";
  case 336: return "FREQLIM";
  case 340: return "LR";
  case 344: return "LR_ALT";
  case 348: return "MIXER";
  case 352: return "ACCESS_ADDRESS";
  case 356: return "MODE";
  case 360: return "DCCAL";
  case 364: return "DCCAL2";
  case 368: return "DCCAL_CTRL";
  case 372: return "TIA_DCCAL";
  case 376: return "TIA_DCCAL2";
  case 380: return "TIA_DCCAL3";
  case 384: return "TIA_DCCAL4";
  case 388: return "TIA_DCCAL5";
  case 392: return "PGA_DCCAL";
  case 396: return "PGA_DCCAL2";
  case 400: return "PGA_DCCAL3";
  case 404: return "PGA_DCCAL4";
  case 408: return "PGA_DCCAL5";
  case 412: return "PGA_DCCAL6";
  case 416: return "DUMMY2";
  case 420: return "DUMMY3";
  case 424: return "DUMMY4";
  case 428: return "LNA_TIA_DCCAL";
  case 432: return "LNA_TIA_DCCAL2";
  case 436: return "DCOFFTRK";
  case 440: return "DCOFFTRK_ALT";
  case 444: return "DCOFFTRK2";
  case 448: return "DCOFFTRK2_ALT";
  case 452: return "DFCNTL";
  case 456: return "DFCNTL_ALT";
  case 460: return "SWANTCTETIME";
  case 464: return "DFTABLE";
  case 468: return "DFSTATUS";
  case 472: return "ANTRX3TO0";
  case 476: return "ANTTX3TO0";
  case 480: return "ANTRX7TO4";
  case 484: return "ANTTX7TO4";
  case 488: return "ANTIDLE";
  case 492: return "DUMMY5";
  case 496: return "DUMMY6";
  case 500: return "WHT_CTRL";
  case 504: return "DCCALRESULTS";
  case 508: return "DCCALRESULTS2";
  case 512: return "TIA_RETENT_DCCALRESULTS";
  case 516: return "TIA_DCCALRESULTS2";
  case 520: return "TIA_DCCALRESULTS3";
  case 524: return "TIA_DCCALRESULTS4";
  case 528: return "TIA_LP_RETENT_DCCALRESULTS";
  case 532: return "TIA_LP_DCCALRESULTS2";
  case 536: return "TIA_LP_DCCALRESULTS3";
  case 540: return "PGA_RETENT_DCCALRESULTS";
  case 544: return "PGA_DCCALRESULTS2";
  case 548: return "PGA_DCCALRESULTS3";
  case 552: return "PGA_LP_RETENT_DCCALRESULTS";
  case 556: return "PGA_LP_DCCALRESULTS2";
  case 560: return "DUMMY7";
  case 564: return "DUMMY8";
  case 568: return "AGCSTATUS";
  case 572: return "MEASFREQ";
  case 576: return "EXPER";
  case 580: return "DET154";
  case 584: return "DET154_ALT";
  case 588: return "SFDCOH154";
  case 592: return "SFDCOH154_ALT";
  case 596: return "SFDNCH154";
  case 600: return "SFDNCH154_ALT";
  case 604: return "DEMOD154";
  case 608: return "DEMOD154_ALT";
  case 612: return "DMDSEL154";
  case 616: return "DMDSEL154_ALT";
  case 620: return "TIM154";
  case 624: return "CCA154";
  case 628: return "SPARE0";
  case 632: return "DEBUG";
  case 636: return "RIFDEBUG";
  case 640: return "LC2LC";
  case 644: return "IRQ";
  case 648: return "IRQM";
  case 652: return "IRQC";
  case 656: return "ERR_INJ";
  case 660: return "DEBUG32";
  case 664: return "DUO";
  case 668: return "CCA";
  case 672: return "ACCESS_ADDRESS2";
  case 676: return "PARCORR";
  case 680: return "PARCORR2";
  case 684: return "PARCORR3";
  case 688: return "RSSI_AVG";
  case 692: return "CSTX";
  case 696: return "CSTX2";
  case 700: return "CSTX3";
  case 704: return "CSTX4";
  case 708: return "CSTX_PHASE_CORR0";
  case 712: return "CSTX_PHASE_CORR1";
  case 716: return "CSTX_PHASE_CORR2";
  case 720: return "CSTX_PHASE_CORR3";
  case 724: return "CSTX_PHASE_CORR4";
  case 728: return "CSTX_PHASE_CORR5";
  case 732: return "CSTX_PHASE_CORR6";
  case 736: return "CSTX2_PHASE_CORR0";
  case 740: return "CSTX2_PHASE_CORR1";
  case 744: return "CSTX2_PHASE_CORR2";
  case 748: return "CSTX2_PHASE_CORR3";
  case 752: return "CSTX2_PHASE_CORR4";
  case 756: return "CSTX2_PHASE_CORR5";
  case 760: return "CSTX2_PHASE_CORR6";
  case 764: return "CSTX3_PHASE_CORR0";
  case 768: return "CSTX3_PHASE_CORR1";
  case 772: return "CSTX3_PHASE_CORR2";
  case 776: return "CSTX3_PHASE_CORR3";
  case 780: return "CSTX3_PHASE_CORR4";
  case 784: return "CSTX3_PHASE_CORR5";
  case 788: return "CSTX3_PHASE_CORR6";
  case 792: return "CSTX4_PHASE_CORR0";
  case 796: return "CSTX4_PHASE_CORR1";
  case 800: return "CSTX4_PHASE_CORR2";
  case 804: return "CSTX4_PHASE_CORR3";
  case 808: return "CSTX4_PHASE_CORR4";
  case 812: return "CSTX4_PHASE_CORR5";
  case 816: return "CSTX4_PHASE_CORR6";
  case 820: return "CSOFFSET";
  case 824: return "CSOFFSET2";
  case 828: return "CSMIXER";
  case 832: return "CSAGC";
  case 836: return "CSAGCPWR";
  case 840: return "CSCFO";
  case 844: return "CSTIM";
  case 848: return "CSPHS";
  case 852: return "CSPHS2";
  case 856: return "CSCNTL";
  case 860: return "CSDCOFFTRK";
  case 864: return "CSNOISE";
  case 868: return "CSRESULTS";
  case 872: return "CSRESULTS2";
  case 876: return "CSRESULTS3";
  case 880: return "CSRESULTS4";
  case 884: return "CSATE";
  case 888: return "ATERESULTS";
  case 892: return "ATERESULTS2";
  case 896: return "ATERESULTS3";
  case 900: return "ATERESULTS4";
  case 904: return "DCCAL_CTRL2";
  case 908: return "SPARE1";
  case 4084: return "CORE_ID";
  case 4088: return "REV_HASH";
  case 4092: return "REV_KEY";
  default: return "unknown CMSDK_MDM offset";
  }
}

/*---------- Iterator ----------*/
static inline uint32_t CMSDK_MDM_begin_offset() { return 0; }
static inline int CMSDK_MDM_end_offset(uint32_t offset) { return offset >= sizeof(CMSDK_MDM_TypeDef); }
static inline uint32_t CMSDK_MDM_next_offset(uint32_t offset) {
  switch (offset) {
  case 908: return 4084;
  default: return offset + 4;
  }
}
/*---------- AT_APB_PSEQ_CAIRO ----------*/
/*---------- Field name map ----------*/
static inline char const *CMSDK_AT_APB_PSEQ_CAIRO_offset_to_str(uint32_t offset) {
  switch (offset) {
  case 0: return "CTRL0";
  case 4: return "CTRL1";
  case 8: return "RETAIN_ALL_WAKE_MASK";
  case 12: return "HIB_WAKE_MASK";
  case 16: return "GPIO_WAKE_MASK";
  case 20: return "GPIO_WAKE_MASK1";
  case 24: return "GPIO_WAKE_TYPE";
  case 28: return "GPIO_WAKE_TYPE1";
  case 32: return "GPIO_WAKE_POL";
  case 36: return "GPIO_WAKE_POL1";
  case 40: return "GPIO_WAKE_BOTH_EDGES";
  case 44: return "GPIO_WAKE_BOTH_EDGES1";
  case 48: return "GPIO_WAKE_STATUS";
  case 52: return "GPIO_WAKE_STATUS1";
  case 56: return "GADC_CONFIG";
  case 60: return "OVERRIDES";
  case 64: return "OVERRIDES2";
  case 68: return "OVERRIDES3";
  case 72: return "OVERRIDES4";
  case 76: return "OVERRIDES5";
  case 80: return "SYSRAM_OVERRIDES";
  case 84: return "SYSRAM_OVERRIDES2";
  case 88: return "SYSRAM_OVERRIDES3";
  case 92: return "SYSRAM_OVERRIDES4";
  case 96: return "SYSRAM_OVERRIDES5";
  case 100: return "SYSRAM_OVERRIDES6";
  case 104: return "SYSRAM_OVERRIDES7";
  case 108: return "SYSRAM_OVERRIDES8";
  case 112: return "EMRAM_OVERRIDES";
  case 116: return "ICACHE_OVERRIDES";
  case 120: return "ICACHE_OVERRIDES2";
  case 124: return "ICACHE_OVERRIDES3";
  case 128: return "ICACHE_OVERRIDES4";
  case 132: return "ICACHE_OVERRIDES5";
  case 136: return "ICACHE_OVERRIDES6";
  case 140: return "ICACHE_OVERRIDES7";
  case 144: return "ICACHE_OVERRIDES8";
  case 148: return "QSPICACHE_OVERRIDES";
  case 152: return "COUNTER_CONTROL";
  case 156: return "CURRENT_REAL_TIME";
  case 160: return "CURRENT_COUNT_DOWN_TIME";
  case 164: return "INIT_COUNT_DOWN";
  case 168: return "COUNTER_CONTROL_1";
  case 172: return "CURRENT_COUNT_DOWN_TIME_1";
  case 176: return "INIT_COUNT_DOWN_1";
  case 180: return "FRC_MATCH0_CTRL";
  case 184: return "FRC_MATCH1_CTRL";
  case 188: return "INST_PENDING";
  case 192: return "STATUS";
  case 196: return "PERSISTENT0";
  case 200: return "PERSISTENT_EXPANSION_CTRL";
  case 204: return "PERSISTENT_EXPANSION_RDATA";
  case 208: return "KSMQDEC_CONTROL";
  case 212: return "SPII2C_CONTROL";
  case 216: return "FLASH_CONTROL";
  case 220: return "FLASH_CONTROL2";
  case 224: return "PMU_STATUS";
  case 228: return "PMU_INTERRUPT";
  case 232: return "PMU_INTERRUPT_EXPAN";
  case 236: return "SYSRAM_WRITE_BLOCK_CFG";
  case 240: return "INTERRUPT_STATUS";
  case 244: return "INTERRUPT_MASK";
  case 248: return "RESET_INTERRUPT";
  case 252: return "FPGA_CFG";
  case 256: return "FSM_TUNINGA";
  case 260: return "FSM_TUNINGB";
  case 264: return "FSM_TUNINGC";
  case 268: return "FSM_TUNINGRA";
  case 272: return "FSM_TUNINGRB";
  case 276: return "FSM_TUNINGRC";
  case 280: return "WDOG_CONTROL";
  case 284: return "WDOG_TIMER";
  case 288: return "BURNIN_CONTROL";
  case 292: return "FRC_STATUS";
  case 296: return "BP_CLK_OFF_DUR";
  case 300: return "FLASH2_CONTROL";
  case 304: return "FLASH2_CONTROL2";
  case 4084: return "CORE_ID";
  case 4088: return "REV_HASH";
  case 4092: return "REV_KEY";
  default: return "unknown CMSDK_AT_APB_PSEQ_CAIRO offset";
  }
}

/*---------- Iterator ----------*/
static inline uint32_t CMSDK_AT_APB_PSEQ_CAIRO_begin_offset() { return 0; }
static inline int CMSDK_AT_APB_PSEQ_CAIRO_end_offset(uint32_t offset) { return offset >= sizeof(CMSDK_AT_APB_PSEQ_CAIRO_TypeDef); }
static inline uint32_t CMSDK_AT_APB_PSEQ_CAIRO_next_offset(uint32_t offset) {
  switch (offset) {
  case 304: return 4084;
  default: return offset + 4;
  }
}
/*---------- AT_APB_SWD ----------*/
/*---------- Field name map ----------*/
static inline char const *CMSDK_AT_APB_SWD_offset_to_str(uint32_t offset) {
  switch (offset) {
  case 0: return "DAP_ADDR_CTRL";
  case 4: return "DAP_WDATA_CTRL";
  case 8: return "SWD_CLK_DIV_CTRL";
  case 12: return "PATTERN_UPPER_CTRL";
  case 16: return "PATTERN_LOWER_CTRL";
  case 20: return "TAIL_DUR";
  case 24: return "PATTERN_DUR";
  case 28: return "DAP_BRIDGE_STATUS";
  case 32: return "DAP_RESP_STATUS";
  case 36: return "RW_CTRL";
  case 40: return "APNDP_CTRL";
  case 44: return "TRIGGER_CTRL";
  case 48: return "DAP_RDATA";
  case 52: return "INTERRUPT_MASK";
  case 56: return "INTERRUPT_STATUS";
  case 60: return "SET_INTERRUPT";
  case 64: return "RESET_INTERRUPT";
  case 68: return "DTOP_BYPASS_CTRL";
  case 72: return "DTOP_BYPASS_STAT";
  case 76: return "DTOP_BYPASS_GPO";
  case 80: return "DTOP_BYPASS_RIF_MODE_CNTL";
  case 84: return "DTOP_BYPASS_RIF_CAL_CNTL";
  case 88: return "DTOP_BYPASS_RIF_RXDC7";
  case 92: return "DTOP_BYPASS_RIF_MODE_CNTL2";
  case 96: return "DTOP_BYPASS_RIF_MODE_CNTL2_P";
  case 100: return "DTOP_BYPASS_RIF_MODE_CNTL2_N";
  case 104: return "DTOP_BYPASS_RIF_SYNTX_154";
  case 108: return "DTOP_BYPASS_RIF_SYNTX_154_P";
  case 112: return "DTOP_BYPASS_RIF_SYNTX_154_N";
  case 116: return "DTOP_BYPASS_RIF_SYNTH_CHAN5";
  case 120: return "DTOP_BYPASS_RIF_SYNTH_CHAN5_P";
  case 124: return "DTOP_BYPASS_RIF_SYNTH_CHAN5_N";
  case 128: return "DTOP_BYPASS_RIF_REG4";
  case 132: return "DTOP_BYPASS_RIF_REG4_P";
  case 136: return "DTOP_BYPASS_RIF_REG4_N";
  case 140: return "DTOP_BYPASS_ATLC_CHANNEL";
  case 144: return "DTOP_BLE_ST";
  case 148: return "DTOP_BLE_CTRL";
  case 4092: return "CORE_ID";
  default: return "unknown CMSDK_AT_APB_SWD offset";
  }
}

/*---------- Iterator ----------*/
static inline uint32_t CMSDK_AT_APB_SWD_begin_offset() { return 0; }
static inline int CMSDK_AT_APB_SWD_end_offset(uint32_t offset) { return offset >= sizeof(CMSDK_AT_APB_SWD_TypeDef); }
static inline uint32_t CMSDK_AT_APB_SWD_next_offset(uint32_t offset) {
  switch (offset) {
  case 148: return 4092;
  default: return offset + 4;
  }
}
/*---------- AT_APB_GADC ----------*/
/*---------- Field name map ----------*/
static inline char const *CMSDK_AT_APB_GADC_offset_to_str(uint32_t offset) {
  switch (offset) {
  case 0: return "CTRL";
  case 4: return "CTRL1";
  case 8: return "GAIN_CONFIG0";
  case 12: return "GAIN_CONFIG1";
  case 16: return "GAIN_COMP0";
  case 20: return "GAIN_COMP1";
  case 24: return "GAIN_COMP2";
  case 28: return "GAIN_COMP3";
  case 32: return "GAIN_COMP4";
  case 36: return "GAIN_COMP5";
  case 40: return "GAIN_COMP6";
  case 44: return "GAIN_COMP7";
  case 48: return "OFFSET_COMP0";
  case 52: return "OFFSET_COMP1";
  case 56: return "OFFSET_COMP2";
  case 60: return "OFFSET_COMP3";
  case 64: return "DATAPATH_OUTPUT";
  case 68: return "INTERRUPTS";
  case 72: return "INTERRUPT_MASK";
  case 76: return "INTERRUPT_CLEAR";
  case 80: return "FIFO_DBG";
  case 84: return "DEBUG";
  case 4084: return "CORE_ID";
  case 4088: return "REV_HASH";
  case 4092: return "REV_KEY";
  default: return "unknown CMSDK_AT_APB_GADC offset";
  }
}

/*---------- Iterator ----------*/
static inline uint32_t CMSDK_AT_APB_GADC_begin_offset() { return 0; }
static inline int CMSDK_AT_APB_GADC_end_offset(uint32_t offset) { return offset >= sizeof(CMSDK_AT_APB_GADC_TypeDef); }
static inline uint32_t CMSDK_AT_APB_GADC_next_offset(uint32_t offset) {
  switch (offset) {
  case 84: return 4084;
  default: return offset + 4;
  }
}
/*---------- AT_APB_TRNG ----------*/
/*---------- Field name map ----------*/
static inline char const *CMSDK_AT_APB_TRNG_offset_to_str(uint32_t offset) {
  switch (offset) {
  case 0: return "CONTROL";
  case 4: return "STATUS";
  case 8: return "INTERRUPT_STATUS";
  case 12: return "INTERRUPT_MASK";
  case 16: return "SET_INTERRUPT";
  case 20: return "RESET_INTERRUPT";
  case 24: return "TRNG";
  case 4084: return "CORE_ID";
  case 4088: return "REV_HASH";
  case 4092: return "REV_KEY";
  default: return "unknown CMSDK_AT_APB_TRNG offset";
  }
}

/*---------- Iterator ----------*/
static inline uint32_t CMSDK_AT_APB_TRNG_begin_offset() { return 0; }
static inline int CMSDK_AT_APB_TRNG_end_offset(uint32_t offset) { return offset >= sizeof(CMSDK_AT_APB_TRNG_TypeDef); }
static inline uint32_t CMSDK_AT_APB_TRNG_next_offset(uint32_t offset) {
  switch (offset) {
  case 24: return 4084;
  default: return offset + 4;
  }
}
/*---------- AT_APB_RCOS_CAL ----------*/
/*---------- Field name map ----------*/
static inline char const *CMSDK_AT_APB_RCOS_CAL_offset_to_str(uint32_t offset) {
  switch (offset) {
  case 0: return "CAL_CTRL";
  case 4: return "SLOW_CLK_SET";
  case 8: return "SLOW_CLK_CNT";
  case 12: return "FAST_CLK_CNT";
  case 16: return "SOURCE_CLK_SEL";
  case 20: return "FORCE_RESET";
  case 24: return "STAT";
  case 28: return "INTERRUPT_STATUS";
  case 32: return "INTERRUPT_MASK";
  case 36: return "SET_INTERRUPT";
  case 40: return "RESET_INTERRUPT";
  case 4084: return "CORE_ID";
  case 4088: return "REV_HASH";
  case 4092: return "REV_KEY";
  default: return "unknown CMSDK_AT_APB_RCOS_CAL offset";
  }
}

/*---------- Iterator ----------*/
static inline uint32_t CMSDK_AT_APB_RCOS_CAL_begin_offset() { return 0; }
static inline int CMSDK_AT_APB_RCOS_CAL_end_offset(uint32_t offset) { return offset >= sizeof(CMSDK_AT_APB_RCOS_CAL_TypeDef); }
static inline uint32_t CMSDK_AT_APB_RCOS_CAL_next_offset(uint32_t offset) {
  switch (offset) {
  case 40: return 4084;
  default: return offset + 4;
  }
}
/*---------- AT_APB_ARM_TRNG ----------*/
/*---------- Field name map ----------*/
static inline char const *CMSDK_AT_APB_ARM_TRNG_offset_to_str(uint32_t offset) {
  switch (offset) {
  case 256: return "RNG_IMR";
  case 260: return "RNG_ISR";
  case 264: return "RNG_ICR";
  case 268: return "TRNG_CONFIG";
  case 272: return "TRNG_VALID";
  case 276: return "EHR_DATA0";
  case 280: return "EHR_DATA1";
  case 284: return "EHR_DATA2";
  case 288: return "EHR_DATA3";
  case 292: return "EHR_DATA4";
  case 296: return "EHR_DATA5";
  case 300: return "RND_SOURCE_ENABLE";
  case 304: return "SAMPLE_CNT1";
  case 308: return "AUTOCORR_STATISTIC";
  case 312: return "TRNG_DEBUG_CONTROL";
  case 320: return "TRNG_SW_RESET";
  case 440: return "TRNG_BUSY";
  case 444: return "RST_BITS_COUNTER";
  case 480: return "RNG_BIST_CNTR0";
  case 484: return "RNG_BIST_CNTR1";
  case 488: return "RNG_BIST_CNTR2";
  case 4084: return "CORE_ID";
  case 4088: return "REV_HASH";
  case 4092: return "REV_KEY";
  default: return "unknown CMSDK_AT_APB_ARM_TRNG offset";
  }
}

/*---------- Iterator ----------*/
static inline uint32_t CMSDK_AT_APB_ARM_TRNG_begin_offset() { return 256; }
static inline int CMSDK_AT_APB_ARM_TRNG_end_offset(uint32_t offset) { return offset >= sizeof(CMSDK_AT_APB_ARM_TRNG_TypeDef); }
static inline uint32_t CMSDK_AT_APB_ARM_TRNG_next_offset(uint32_t offset) {
  switch (offset) {
  case 312: return 320;
  case 320: return 440;
  case 444: return 480;
  case 488: return 4084;
  default: return offset + 4;
  }
}
/*---------- AT_APB_PDM ----------*/
/*---------- Field name map ----------*/
static inline char const *CMSDK_AT_APB_PDM_offset_to_str(uint32_t offset) {
  switch (offset) {
  case 0: return "CONTROL";
  case 4: return "FILTER_CONFIG";
  case 8: return "FILTER_CONFIG1";
  case 12: return "GAIN_CONTROL_CONFIG";
  case 16: return "PCM_SAMPLE";
  case 20: return "FIFO_DEBUG";
  case 24: return "INTERRUPTS";
  case 28: return "INTERRUPT_MASK";
  case 32: return "INTERRUPT_CLEAR";
  case 36: return "BUFFER_ACCESS_MODE";
  case 40: return "AUTO_COUNTER";
  case 44: return "BUFFER_DEPTH";
  case 4084: return "CORE_ID";
  case 4088: return "REV_HASH";
  case 4092: return "REV_KEY";
  default: return "unknown CMSDK_AT_APB_PDM offset";
  }
}

/*---------- Iterator ----------*/
static inline uint32_t CMSDK_AT_APB_PDM_begin_offset() { return 0; }
static inline int CMSDK_AT_APB_PDM_end_offset(uint32_t offset) { return offset >= sizeof(CMSDK_AT_APB_PDM_TypeDef); }
static inline uint32_t CMSDK_AT_APB_PDM_next_offset(uint32_t offset) {
  switch (offset) {
  case 44: return 4084;
  default: return offset + 4;
  }
}
/*---------- AT_I2S ----------*/
/*---------- Field name map ----------*/
static inline char const *CMSDK_AT_I2S_offset_to_str(uint32_t offset) {
  switch (offset) {
  case 0: return "I2S_CTRL0";
  case 4: return "I2S_CTRL1_TX";
  case 8: return "I2S_CTRL1_RX";
  case 12: return "I2S_CTRL2_TX";
  case 16: return "I2S_CTRL2_RX";
  case 20: return "I2S_CTRL3";
  case 24: return "I2S_CTRL4";
  case 28: return "I2S_CTRL5_TX";
  case 32: return "I2S_CTRL5_RX";
  case 36: return "I2S_INTRP_CTRL";
  case 40: return "I2S_PP1_RDATA";
  case 44: return "I2S_PP0_WDATA";
  case 48: return "I2S_PP1_CTRL";
  case 52: return "I2S_PP0_CTRL";
  case 56: return "I2S_IRQ0";
  case 60: return "I2S_IRQM0";
  case 64: return "I2S_IRQS0";
  case 68: return "I2S_IRQC0";
  case 72: return "I2S_IRQ1";
  case 76: return "I2S_IRQM1";
  case 80: return "I2S_IRQS1";
  case 84: return "I2S_IRQC1";
  case 88: return "BUFFER_DEPTH";
  case 92: return "PP_ST";
  case 96: return "PP0_ST";
  case 100: return "PP1_ST";
  case 104: return "I2S_SPARE";
  case 108: return "I2S_DBG";
  case 4084: return "ID";
  case 4088: return "REV_HASH";
  case 4092: return "REV_KEY";
  default: return "unknown CMSDK_AT_I2S offset";
  }
}

/*---------- Iterator ----------*/
static inline uint32_t CMSDK_AT_I2S_begin_offset() { return 0; }
static inline int CMSDK_AT_I2S_end_offset(uint32_t offset) { return offset >= sizeof(CMSDK_AT_I2S_TypeDef); }
static inline uint32_t CMSDK_AT_I2S_next_offset(uint32_t offset) {
  switch (offset) {
  case 108: return 4084;
  default: return offset + 4;
  }
}
/*---------- AT_APB_CLKRSTGEN ----------*/
/*---------- Field name map ----------*/
static inline char const *CMSDK_AT_APB_CLKRSTGEN_offset_to_str(uint32_t offset) {
  switch (offset) {
  case 0: return "CLK_BP_CTRL";
  case 4: return "CLK_BP_CTRL_STAT";
  case 8: return "CLK_AUD_CTRL";
  case 12: return "PLL_CTRL";
  case 16: return "USER_RESETS";
  case 20: return "USER_CLK_DISABLES";
  case 24: return "USER_CLK_GATE_FORCE_ON";
  case 28: return "USER_CLK_GATE_CTRL";
  case 32: return "CONFIGURATION";
  case 36: return "CLKSYNC";
  case 40: return "RADIO_STATUS";
  case 44: return "ATLC_LP_CTRL_0";
  case 48: return "ATLC_LP_CTRL_1";
  case 52: return "FSM_CTRL";
  case 56: return "FSM_WAIT4DOUBLER";
  case 60: return "FSM_STATUS";
  case 64: return "XTAL_BITS0";
  case 68: return "XTAL_BITS1";
  case 72: return "PLL";
  case 76: return "IRQ_MASK";
  case 80: return "IRQ_SET";
  case 84: return "IRQ_CLR";
  case 88: return "IRQ_STATUS";
  case 92: return "ATLC_LP_CTRL_2";
  case 96: return "ATLC_LP_FRAC_RESIDUE";
  case 100: return "CLKSYNC_STATUS";
  case 104: return "HARV_CTRL";
  case 108: return "QSPI_CLK_CTRL";
  case 112: return "QSPI_STAT";
  case 4084: return "CORE_ID";
  case 4088: return "REV_HASH";
  case 4092: return "REV_KEY";
  default: return "unknown CMSDK_AT_APB_CLKRSTGEN offset";
  }
}

/*---------- Iterator ----------*/
static inline uint32_t CMSDK_AT_APB_CLKRSTGEN_begin_offset() { return 0; }
static inline int CMSDK_AT_APB_CLKRSTGEN_end_offset(uint32_t offset) { return offset >= sizeof(CMSDK_AT_APB_CLKRSTGEN_TypeDef); }
static inline uint32_t CMSDK_AT_APB_CLKRSTGEN_next_offset(uint32_t offset) {
  switch (offset) {
  case 112: return 4084;
  default: return offset + 4;
  }
}
/*---------- AT_APB_AES ----------*/
/*---------- Field name map ----------*/
static inline char const *CMSDK_AT_APB_AES_offset_to_str(uint32_t offset) {
  switch (offset) {
  case 0: return "ALERT_TEST";
  case 4: return "KEY_SHARE0_0";
  case 8: return "KEY_SHARE0_1";
  case 12: return "KEY_SHARE0_2";
  case 16: return "KEY_SHARE0_3";
  case 20: return "KEY_SHARE0_4";
  case 24: return "KEY_SHARE0_5";
  case 28: return "KEY_SHARE0_6";
  case 32: return "KEY_SHARE0_7";
  case 36: return "KEY_SHARE1_0";
  case 40: return "KEY_SHARE1_1";
  case 44: return "KEY_SHARE1_2";
  case 48: return "KEY_SHARE1_3";
  case 52: return "KEY_SHARE1_4";
  case 56: return "KEY_SHARE1_5";
  case 60: return "KEY_SHARE1_6";
  case 64: return "KEY_SHARE1_7";
  case 68: return "IV_0";
  case 72: return "IV_1";
  case 76: return "IV_2";
  case 80: return "IV_3";
  case 84: return "DATA_IN_0";
  case 88: return "DATA_IN_1";
  case 92: return "DATA_IN_2";
  case 96: return "DATA_IN_3";
  case 100: return "DATA_OUT_0";
  case 104: return "DATA_OUT_1";
  case 108: return "DATA_OUT_2";
  case 112: return "DATA_OUT_3";
  case 116: return "CTRL_SHADOWED";
  case 120: return "TRIGGER";
  case 124: return "STATUS";
  case 3968: return "A_BLK_START";
  case 3972: return "A_BLK_END";
  case 3976: return "B_BLK_START";
  case 3980: return "B_BLK_END";
  case 3984: return "CCM_ENC_MIC_W0";
  case 3988: return "CCM_ENC_MIC_W1";
  case 3992: return "CCM_ENC_MIC_W2";
  case 3996: return "CCM_ENC_MIC_W3";
  case 4000: return "CCM_MIC_W0";
  case 4004: return "CCM_MIC_W1";
  case 4008: return "CCM_MIC_W2";
  case 4012: return "CCM_MIC_W3";
  case 4016: return "CCM_DATAOUT";
  case 4020: return "CCM_DATAIN";
  case 4024: return "CCM_CTRL";
  case 4028: return "B0_FORMAT_W0";
  case 4032: return "B0_FORMAT_W1";
  case 4036: return "B0_FORMAT_W2";
  case 4040: return "B0_FORMAT_W3";
  case 4044: return "B1_FORMAT_W0";
  case 4048: return "B1_FORMAT_W1";
  case 4052: return "B1_FORMAT_W2";
  case 4056: return "B1_FORMAT_W3";
  case 4060: return "PYLD_SIZE";
  case 4064: return "IRQ_STATUS";
  case 4068: return "IRQ_MASK";
  case 4072: return "IRQ_CLR";
  case 4076: return "STATUS1";
  case 4080: return "SIDELOAD_CTRL";
  case 4084: return "ID";
  case 4088: return "REV_HASH";
  case 4092: return "REV_KEY";
  default: return "unknown CMSDK_AT_APB_AES offset";
  }
}

/*---------- Iterator ----------*/
static inline uint32_t CMSDK_AT_APB_AES_begin_offset() { return 0; }
static inline int CMSDK_AT_APB_AES_end_offset(uint32_t offset) { return offset >= sizeof(CMSDK_AT_APB_AES_TypeDef); }
static inline uint32_t CMSDK_AT_APB_AES_next_offset(uint32_t offset) {
  switch (offset) {
  case 124: return 3968;
  default: return offset + 4;
  }
}
/*---------- AT_APB_BIQUAD ----------*/
/*---------- Field name map ----------*/
static inline char const *CMSDK_AT_APB_BIQUAD_offset_to_str(uint32_t offset) {
  switch (offset) {
  case 0: return "CONTROL";
  case 4: return "X";
  case 8: return "Y";
  case 12: return "B0_HI";
  case 16: return "B0_LO";
  case 20: return "B1_HI";
  case 24: return "B1_LO";
  case 28: return "B2_HI";
  case 32: return "B2_LO";
  case 36: return "A1_HI";
  case 40: return "A1_LO";
  case 44: return "A2_HI";
  case 48: return "A2_LO";
  case 4084: return "CORE_ID";
  case 4088: return "REV_HASH";
  case 4092: return "REV_KEY";
  default: return "unknown CMSDK_AT_APB_BIQUAD offset";
  }
}

/*---------- Iterator ----------*/
static inline uint32_t CMSDK_AT_APB_BIQUAD_begin_offset() { return 0; }
static inline int CMSDK_AT_APB_BIQUAD_end_offset(uint32_t offset) { return offset >= sizeof(CMSDK_AT_APB_BIQUAD_TypeDef); }
static inline uint32_t CMSDK_AT_APB_BIQUAD_next_offset(uint32_t offset) {
  switch (offset) {
  case 48: return 4084;
  default: return offset + 4;
  }
}
/*---------- AT_AHB_DMA ----------*/
/*---------- Field name map ----------*/
static inline char const *CMSDK_AT_AHB_DMA_offset_to_str(uint32_t offset) {
  switch (offset) {
  case 0: return "OPMODE";
  case 4: return "CONST_WDATA";
  case 8: return "SRC_ADDR";
  case 12: return "TAR_ADDR";
  case 16: return "SIZE";
  case 20: return "SRC_CTRL";
  case 24: return "TAR_CTRL";
  case 28: return "FIFO_DPTH_ADDR";
  case 32: return "FIFO_PORT_SEL";
  case 36: return "SPI_PORT_SEL";
  case 40: return "ERR_STAT";
  case 44: return "STATUS";
  case 48: return "TOTAL_WRITE_REMAINDER";
  case 52: return "INTERRUPT_STATUS";
  case 56: return "INTERRUPT_MASK";
  case 60: return "SET_INTERRUPT";
  case 64: return "RESET_INTERRUPT";
  case 68: return "CFG_HNONSEC";
  case 72: return "CHAN1_OPMODE";
  case 76: return "CHAN1_CONST_WDATA";
  case 80: return "CHAN1_SRC_ADDR";
  case 84: return "CHAN1_TAR_ADDR";
  case 88: return "CHAN1_SIZE";
  case 92: return "CHAN1_SRC_CTRL";
  case 96: return "CHAN1_TAR_CTRL";
  case 100: return "CHAN1_FIFO_DPTH_ADDR";
  case 104: return "CHAN1_FIFO_PORT_SEL";
  case 108: return "CHAN1_SPI_PORT_SEL";
  case 112: return "CHAN1_ERR_STAT";
  case 116: return "CHAN1_STATUS";
  case 120: return "CHAN1_TOTAL_WRITE_REMAINDER";
  case 124: return "CHAN1_INTERRUPT_STATUS";
  case 128: return "CHAN1_INTERRUPT_MASK";
  case 132: return "CHAN1_SET_INTERRUPT";
  case 136: return "CHAN1_RESET_INTERRUPT";
  case 140: return "CHAN1_CFG_HNONSEC";
  case 144: return "CHAN2_OPMODE";
  case 148: return "CHAN2_CONST_WDATA";
  case 152: return "CHAN2_SRC_ADDR";
  case 156: return "CHAN2_TAR_ADDR";
  case 160: return "CHAN2_SIZE";
  case 164: return "CHAN2_SRC_CTRL";
  case 168: return "CHAN2_TAR_CTRL";
  case 172: return "CHAN2_FIFO_DPTH_ADDR";
  case 176: return "CHAN2_FIFO_PORT_SEL";
  case 180: return "CHAN2_SPI_PORT_SEL";
  case 184: return "CHAN2_ERR_STAT";
  case 188: return "CHAN2_STATUS";
  case 192: return "CHAN2_TOTAL_WRITE_REMAINDER";
  case 196: return "CHAN2_INTERRUPT_STATUS";
  case 200: return "CHAN2_INTERRUPT_MASK";
  case 204: return "CHAN2_SET_INTERRUPT";
  case 208: return "CHAN2_RESET_INTERRUPT";
  case 212: return "CHAN2_CFG_HNONSEC";
  case 216: return "CHAN3_OPMODE";
  case 220: return "CHAN3_CONST_WDATA";
  case 224: return "CHAN3_SRC_ADDR";
  case 228: return "CHAN3_TAR_ADDR";
  case 232: return "CHAN3_SIZE";
  case 236: return "CHAN3_SRC_CTRL";
  case 240: return "CHAN3_TAR_CTRL";
  case 244: return "CHAN3_FIFO_DPTH_ADDR";
  case 248: return "CHAN3_FIFO_PORT_SEL";
  case 252: return "CHAN3_SPI_PORT_SEL";
  case 256: return "CHAN3_ERR_STAT";
  case 260: return "CHAN3_STATUS";
  case 264: return "CHAN3_TOTAL_WRITE_REMAINDER";
  case 268: return "CHAN3_INTERRUPT_STATUS";
  case 272: return "CHAN3_INTERRUPT_MASK";
  case 276: return "CHAN3_SET_INTERRUPT";
  case 280: return "CHAN3_RESET_INTERRUPT";
  case 284: return "CHAN3_CFG_HNONSEC";
  case 288: return "ERR_INTERRUPT_DLY";
  case 292: return "ARBITER_CTRL";
  case 296: return "ARBITER_GRANT_STAT";
  case 300: return "DIAGCNTL";
  case 304: return "CCM_CTRL";
  case 4084: return "ID";
  case 4088: return "REV_HASH";
  case 4092: return "REV_KEY";
  default: return "unknown CMSDK_AT_AHB_DMA offset";
  }
}

/*---------- Iterator ----------*/
static inline uint32_t CMSDK_AT_AHB_DMA_begin_offset() { return 0; }
static inline int CMSDK_AT_AHB_DMA_end_offset(uint32_t offset) { return offset >= sizeof(CMSDK_AT_AHB_DMA_TypeDef); }
static inline uint32_t CMSDK_AT_AHB_DMA_next_offset(uint32_t offset) {
  switch (offset) {
  case 304: return 4084;
  default: return offset + 4;
  }
}



 /*------------ ALL BLOCKS ------------*/
typedef struct block_utils_s {
    struct {
	char const *name;
	uint32_t addr;
    } meta;
    struct {
	uint32_t (*begin)(void);
	int (*end)(uint32_t offset);
	uint32_t (*next)(uint32_t offset);
    } offset_iter;
    char const *(*offset_to_str)(uint32_t offset);
} block_utils_t;


static inline block_utils_t const *all_blocks(size_t *num_blocks) {
    static const block_utils_t blocks[] = {
        {{ .name = "AT_UART0_NONSECURE", .addr = 0x40144000 }, { .begin = CMSDK_AT_APB_UART_begin_offset, .end = CMSDK_AT_APB_UART_end_offset, .next = CMSDK_AT_APB_UART_next_offset}, .offset_to_str = CMSDK_AT_APB_UART_offset_to_str },
        {{ .name = "KSM_NONSECURE", .addr = 0x4014a000 }, { .begin = CMSDK_AT_APB_KSM_begin_offset, .end = CMSDK_AT_APB_KSM_end_offset, .next = CMSDK_AT_APB_KSM_next_offset}, .offset_to_str = CMSDK_AT_APB_KSM_offset_to_str },
        {{ .name = "WRPR0_NONSECURE", .addr = 0x40143000 }, { .begin = CMSDK_AT_APB_WRPR_PINS_begin_offset, .end = CMSDK_AT_APB_WRPR_PINS_end_offset, .next = CMSDK_AT_APB_WRPR_PINS_next_offset}, .offset_to_str = CMSDK_AT_APB_WRPR_PINS_offset_to_str },
        {{ .name = "CLKRSTGEN_NONSECURE", .addr = 0x40166000 }, { .begin = CMSDK_AT_APB_CLKRSTGEN_begin_offset, .end = CMSDK_AT_APB_CLKRSTGEN_end_offset, .next = CMSDK_AT_APB_CLKRSTGEN_next_offset}, .offset_to_str = CMSDK_AT_APB_CLKRSTGEN_offset_to_str },
        {{ .name = "RCOS_CAL_NONSECURE", .addr = 0x4015c000 }, { .begin = CMSDK_AT_APB_RCOS_CAL_begin_offset, .end = CMSDK_AT_APB_RCOS_CAL_end_offset, .next = CMSDK_AT_APB_RCOS_CAL_next_offset}, .offset_to_str = CMSDK_AT_APB_RCOS_CAL_offset_to_str },
        {{ .name = "TRNG_NONSECURE", .addr = 0x4015b000 }, { .begin = CMSDK_AT_APB_TRNG_begin_offset, .end = CMSDK_AT_APB_TRNG_end_offset, .next = CMSDK_AT_APB_TRNG_next_offset}, .offset_to_str = CMSDK_AT_APB_TRNG_offset_to_str },
        {{ .name = "RIF_NONSECURE", .addr = 0x40154000 }, { .begin = CMSDK_RIF_begin_offset, .end = CMSDK_RIF_end_offset, .next = CMSDK_RIF_next_offset}, .offset_to_str = CMSDK_RIF_offset_to_str },
        {{ .name = "AT_DMA_NONSECURE", .addr = 0x40170000 }, { .begin = CMSDK_AT_AHB_DMA_begin_offset, .end = CMSDK_AT_AHB_DMA_end_offset, .next = CMSDK_AT_AHB_DMA_next_offset}, .offset_to_str = CMSDK_AT_AHB_DMA_offset_to_str },
        {{ .name = "AES_NONSECURE", .addr = 0x40167000 }, { .begin = CMSDK_AT_APB_AES_begin_offset, .end = CMSDK_AT_APB_AES_end_offset, .next = CMSDK_AT_APB_AES_next_offset}, .offset_to_str = CMSDK_AT_APB_AES_offset_to_str },
        {{ .name = "ARM_TRNG_NONSECURE", .addr = 0x4015e000 }, { .begin = CMSDK_AT_APB_ARM_TRNG_begin_offset, .end = CMSDK_AT_APB_ARM_TRNG_end_offset, .next = CMSDK_AT_APB_ARM_TRNG_next_offset}, .offset_to_str = CMSDK_AT_APB_ARM_TRNG_offset_to_str },
        {{ .name = "WRPR1_NONSECURE", .addr = 0x40153000 }, { .begin = CMSDK_AT_APB_WRPR_SHORT_begin_offset, .end = CMSDK_AT_APB_WRPR_SHORT_end_offset, .next = CMSDK_AT_APB_WRPR_SHORT_next_offset}, .offset_to_str = CMSDK_AT_APB_WRPR_SHORT_offset_to_str },
        {{ .name = "QDEC_NONSECURE", .addr = 0x4014c000 }, { .begin = CMSDK_AT_APB_QDEC_begin_offset, .end = CMSDK_AT_APB_QDEC_end_offset, .next = CMSDK_AT_APB_QDEC_next_offset}, .offset_to_str = CMSDK_AT_APB_QDEC_offset_to_str },
        {{ .name = "I2C0_NONSECURE", .addr = 0x40150000 }, { .begin = CMSDK_AT_APB_I2C_begin_offset, .end = CMSDK_AT_APB_I2C_end_offset, .next = CMSDK_AT_APB_I2C_next_offset}, .offset_to_str = CMSDK_AT_APB_I2C_offset_to_str },
        {{ .name = "PDM0_NONSECURE", .addr = 0x40160000 }, { .begin = CMSDK_AT_APB_PDM_begin_offset, .end = CMSDK_AT_APB_PDM_end_offset, .next = CMSDK_AT_APB_PDM_next_offset}, .offset_to_str = CMSDK_AT_APB_PDM_offset_to_str },
        {{ .name = "GADC_NONSECURE", .addr = 0x4015a000 }, { .begin = CMSDK_AT_APB_GADC_begin_offset, .end = CMSDK_AT_APB_GADC_end_offset, .next = CMSDK_AT_APB_GADC_next_offset}, .offset_to_str = CMSDK_AT_APB_GADC_offset_to_str },
        {{ .name = "BIQUAD_NONSECURE", .addr = 0x4016d000 }, { .begin = CMSDK_AT_APB_BIQUAD_begin_offset, .end = CMSDK_AT_APB_BIQUAD_end_offset, .next = CMSDK_AT_APB_BIQUAD_next_offset}, .offset_to_str = CMSDK_AT_APB_BIQUAD_offset_to_str },
        {{ .name = "SWD_NONSECURE", .addr = 0x40159000 }, { .begin = CMSDK_AT_APB_SWD_begin_offset, .end = CMSDK_AT_APB_SWD_end_offset, .next = CMSDK_AT_APB_SWD_next_offset}, .offset_to_str = CMSDK_AT_APB_SWD_offset_to_str },
        {{ .name = "SLWTIMER_NONSECURE", .addr = 0x4014e000 }, { .begin = CMSDK_AT_APB_SLWTIMER_begin_offset, .end = CMSDK_AT_APB_SLWTIMER_end_offset, .next = CMSDK_AT_APB_SLWTIMER_next_offset}, .offset_to_str = CMSDK_AT_APB_SLWTIMER_offset_to_str },
        {{ .name = "I2S_NONSECURE", .addr = 0x40165000 }, { .begin = CMSDK_AT_I2S_begin_offset, .end = CMSDK_AT_I2S_end_offset, .next = CMSDK_AT_I2S_next_offset}, .offset_to_str = CMSDK_AT_I2S_offset_to_str },
        {{ .name = "ATLC_NONSECURE", .addr = 0x40120000 }, { .begin = CMSDK_AT_LC_begin_offset, .end = CMSDK_AT_LC_end_offset, .next = CMSDK_AT_LC_next_offset}, .offset_to_str = CMSDK_AT_LC_offset_to_str },
        {{ .name = "QSPI_NONSECURE", .addr = 0x4014f000 }, { .begin = CMSDK_AT_APB_QSPI_begin_offset, .end = CMSDK_AT_APB_QSPI_end_offset, .next = CMSDK_AT_APB_QSPI_next_offset}, .offset_to_str = CMSDK_AT_APB_QSPI_offset_to_str },
        {{ .name = "NVM_NONSECURE", .addr = 0x40152000 }, { .begin = CMSDK_AT_APB_UMC_NVM_begin_offset, .end = CMSDK_AT_APB_UMC_NVM_end_offset, .next = CMSDK_AT_APB_UMC_NVM_next_offset}, .offset_to_str = CMSDK_AT_APB_UMC_NVM_offset_to_str },
        {{ .name = "SPI0_NONSECURE", .addr = 0x40147000 }, { .begin = CMSDK_AT_APB_SPI_begin_offset, .end = CMSDK_AT_APB_SPI_end_offset, .next = CMSDK_AT_APB_SPI_next_offset}, .offset_to_str = CMSDK_AT_APB_SPI_offset_to_str },
        {{ .name = "SHA2_NONSECURE", .addr = 0x40103000 }, { .begin = CMSDK_AT_AHB_SHA2_begin_offset, .end = CMSDK_AT_AHB_SHA2_end_offset, .next = CMSDK_AT_AHB_SHA2_next_offset}, .offset_to_str = CMSDK_AT_AHB_SHA2_offset_to_str },
        {{ .name = "MDM_NONSECURE", .addr = 0x40156000 }, { .begin = CMSDK_MDM_begin_offset, .end = CMSDK_MDM_end_offset, .next = CMSDK_MDM_next_offset}, .offset_to_str = CMSDK_MDM_offset_to_str },
        {{ .name = "PWM_NONSECURE", .addr = 0x40146000 }, { .begin = CMSDK_AT_APB_PWM_begin_offset, .end = CMSDK_AT_APB_PWM_end_offset, .next = CMSDK_AT_APB_PWM_next_offset}, .offset_to_str = CMSDK_AT_APB_PWM_offset_to_str },
        {{ .name = "PSEQ_NONSECURE", .addr = 0x40158000 }, { .begin = CMSDK_AT_APB_PSEQ_CAIRO_begin_offset, .end = CMSDK_AT_APB_PSEQ_CAIRO_end_offset, .next = CMSDK_AT_APB_PSEQ_CAIRO_next_offset}, .offset_to_str = CMSDK_AT_APB_PSEQ_CAIRO_offset_to_str }
    };
    *num_blocks = sizeof(blocks)/sizeof(blocks[0]);
    return blocks;
}

#define CMSDK_BLOCK_ADDR_MASK 0xFFF

/** @} end of at_base_addr_utils */
