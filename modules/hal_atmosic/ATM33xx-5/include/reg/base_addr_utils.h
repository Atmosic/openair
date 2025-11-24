/**
 *****************************************************************************
 *
 * @file base_addr_utils.h
 *
 * @brief Base Address Utility definitions
 *
 * Copyright (C) Atmosic 2022-2025
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
/*---------- AT_AHB_PRRF ----------*/
/*---------- Field name map ----------*/
static inline char const *CMSDK_AT_AHB_PRRF_offset_to_str(uint32_t offset) {
  switch (offset) {
  case 0: return "PATCH_TAG0";
  case 4: return "PATCH_TAG1";
  case 8: return "PATCH_TAG2";
  case 12: return "PATCH_TAG3";
  case 16: return "PATCH_TAG4";
  case 20: return "PATCH_TAG5";
  case 24: return "PATCH_TAG6";
  case 28: return "PATCH_TAG7";
  case 32: return "PATCH_TAG8";
  case 36: return "PATCH_TAG9";
  case 40: return "PATCH_TAG10";
  case 44: return "PATCH_TAG11";
  case 48: return "PATCH_TAG12";
  case 52: return "PATCH_TAG13";
  case 56: return "PATCH_TAG14";
  case 60: return "PATCH_TAG15";
  case 64: return "PATCH0";
  case 68: return "PATCH1";
  case 72: return "PATCH2";
  case 76: return "PATCH3";
  case 80: return "PATCH4";
  case 84: return "PATCH5";
  case 88: return "PATCH6";
  case 92: return "PATCH7";
  case 96: return "PATCH8";
  case 100: return "PATCH9";
  case 104: return "PATCH10";
  case 108: return "PATCH11";
  case 112: return "PATCH12";
  case 116: return "PATCH13";
  case 120: return "PATCH14";
  case 124: return "PATCH15";
  case 128: return "PATCH16";
  case 132: return "PATCH17";
  case 136: return "PATCH18";
  case 140: return "PATCH19";
  case 144: return "PATCH20";
  case 148: return "PATCH21";
  case 152: return "PATCH22";
  case 156: return "PATCH23";
  case 160: return "PATCH24";
  case 164: return "PATCH25";
  case 168: return "PATCH26";
  case 172: return "PATCH27";
  case 176: return "PATCH28";
  case 180: return "PATCH29";
  case 184: return "PATCH30";
  case 188: return "PATCH31";
  case 192: return "PATCH32";
  case 196: return "PATCH33";
  case 200: return "PATCH34";
  case 204: return "PATCH35";
  case 208: return "PATCH36";
  case 212: return "PATCH37";
  case 216: return "PATCH38";
  case 220: return "PATCH39";
  case 224: return "PATCH40";
  case 228: return "PATCH41";
  case 232: return "PATCH42";
  case 236: return "PATCH43";
  case 240: return "PATCH44";
  case 244: return "PATCH45";
  case 248: return "PATCH46";
  case 252: return "PATCH47";
  case 256: return "RRAM_WRT_CONFIG_LO";
  case 260: return "RRAM_WRT_CONFIG_HI";
  case 264: return "RRAM_READ_CONFIG_LO";
  case 268: return "RRAM_READ_CONFIG_HI";
  case 272: return "RRAM_CACHE_CONFIG";
  case 276: return "RRAM_MEM_CONFIG";
  case 280: return "RRAM_STATUS";
  default: return "unknown CMSDK_AT_AHB_PRRF offset";
  }
}

/*---------- Iterator ----------*/
static inline uint32_t CMSDK_AT_AHB_PRRF_begin_offset() { return 0; }
static inline int CMSDK_AT_AHB_PRRF_end_offset(uint32_t offset) { return offset >= sizeof(CMSDK_AT_AHB_PRRF_TypeDef); }
static inline uint32_t CMSDK_AT_AHB_PRRF_next_offset(uint32_t offset) {
  switch (offset) {
  default: return offset + 4;
  }
}
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
  case 4092: return "ID";
  default: return "unknown CMSDK_AT_AHB_SHA2 offset";
  }
}

/*---------- Iterator ----------*/
static inline uint32_t CMSDK_AT_AHB_SHA2_begin_offset() { return 0; }
static inline int CMSDK_AT_AHB_SHA2_end_offset(uint32_t offset) { return offset >= sizeof(CMSDK_AT_AHB_SHA2_TypeDef); }
static inline uint32_t CMSDK_AT_AHB_SHA2_next_offset(uint32_t offset) {
  switch (offset) {
  case 112: return 4092;
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
  case 116: return "PUPD_OVRD";
  case 120: return "PUPD_OVRD_VAL";
  case 124: return "REMAP";
  case 128: return "AHB_INTERPOSERS";
  case 132: return "SCRATCHPAD_A";
  case 136: return "SCRATCHPAD_B";
  case 140: return "SCRATCHPAD_C";
  case 144: return "SCRATCHPAD_D";
  case 148: return "RRAM_WRITE_PROTECTION0";
  case 152: return "RRAM_WRITE_PROTECTION1";
  case 156: return "RRAM_WRITE_PROTECTION2";
  case 160: return "RRAM_WRITE_PROTECTION3";
  case 164: return "RRAM_WRITE_PROTECTION4";
  case 168: return "RRAM_WRITE_PROTECTION5";
  case 172: return "RRAM_WRITE_PROTECTION6";
  case 176: return "RRAM_WRITE_PROTECTION7";
  case 180: return "RRAM_STICKY_WRITE_PROTECTION0";
  case 184: return "RRAM_STICKY_WRITE_PROTECTION1";
  case 188: return "RRAM_STICKY_WRITE_PROTECTION2";
  case 192: return "RRAM_STICKY_WRITE_PROTECTION3";
  case 196: return "RRAM_STICKY_WRITE_PROTECTION4";
  case 200: return "RRAM_STICKY_WRITE_PROTECTION5";
  case 204: return "RRAM_STICKY_WRITE_PROTECTION6";
  case 208: return "RRAM_STICKY_WRITE_PROTECTION7";
  case 212: return "RRAM_STICKY_WRITE_PROTECTION_STATUS0";
  case 216: return "RRAM_STICKY_WRITE_PROTECTION_STATUS1";
  case 220: return "RRAM_STICKY_WRITE_PROTECTION_STATUS2";
  case 224: return "RRAM_STICKY_WRITE_PROTECTION_STATUS3";
  case 228: return "RRAM_STICKY_WRITE_PROTECTION_STATUS4";
  case 232: return "RRAM_STICKY_WRITE_PROTECTION_STATUS5";
  case 236: return "RRAM_STICKY_WRITE_PROTECTION_STATUS6";
  case 240: return "RRAM_STICKY_WRITE_PROTECTION_STATUS7";
  case 244: return "RRAM_STICKY_READ_PROTECTION0";
  case 248: return "RRAM_STICKY_READ_PROTECTION_STATUS0";
  case 252: return "PROT_BITS_SET0";
  case 256: return "PROT_BITS_SET1";
  case 260: return "PROT_BITS_STAT0";
  case 264: return "PROT_BITS_STAT1";
  case 268: return "QSPI_STICKY_WRITE_PROTECTION0";
  case 272: return "QSPI_STICKY_WRITE_PROTECTION1";
  case 276: return "QSPI_STICKY_WRITE_PROTECTION_STATUS0";
  case 280: return "QSPI_STICKY_WRITE_PROTECTION_STATUS1";
  case 284: return "PDSN";
  case 288: return "CALCOUNTRC";
  case 292: return "SECURE_DEBUG_CTRL";
  case 296: return "SECURE_DEBUG_STAT";
  case 4080: return "CHIPID1";
  case 4084: return "CHIPID2";
  case 4088: return "CHIPREV";
  case 4092: return "CORE_ID";
  default: return "unknown CMSDK_AT_APB_WRPR_PINS offset";
  }
}

/*---------- Iterator ----------*/
static inline uint32_t CMSDK_AT_APB_WRPR_PINS_begin_offset() { return 0; }
static inline int CMSDK_AT_APB_WRPR_PINS_end_offset(uint32_t offset) { return offset >= sizeof(CMSDK_AT_APB_WRPR_PINS_TypeDef); }
static inline uint32_t CMSDK_AT_APB_WRPR_PINS_next_offset(uint32_t offset) {
  switch (offset) {
  case 296: return 4080;
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
  case 4048: return "PID4";
  case 4052: return "PID5";
  case 4056: return "PID6";
  case 4060: return "PID7";
  case 4064: return "PID0";
  case 4068: return "PID1";
  case 4072: return "PID2";
  case 4076: return "PID3";
  case 4080: return "CID0";
  case 4084: return "CID1";
  case 4088: return "CID2";
  case 4092: return "CID3";
  default: return "unknown CMSDK_AT_APB_UART offset";
  }
}

/*---------- Iterator ----------*/
static inline uint32_t CMSDK_AT_APB_UART_begin_offset() { return 0; }
static inline int CMSDK_AT_APB_UART_end_offset(uint32_t offset) { return offset >= sizeof(CMSDK_AT_APB_UART_TypeDef); }
static inline uint32_t CMSDK_AT_APB_UART_next_offset(uint32_t offset) {
  switch (offset) {
  case 60: return 4048;
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
  case 8: return "TRANSACTION_SETUP_DMA";
  case 12: return "TRANSACTION_STATUS";
  case 16: return "DATA_BYTES_LOWER";
  case 20: return "DATA_BYTES_UPPER";
  case 24: return "INTERRUPT_MASK";
  case 28: return "INTERRUPT_STATUS";
  case 32: return "SET_INTERRUPT";
  case 36: return "RESET_INTERRUPT";
  case 4092: return "CORE_ID";
  default: return "unknown CMSDK_AT_APB_SPI offset";
  }
}

/*---------- Iterator ----------*/
static inline uint32_t CMSDK_AT_APB_SPI_begin_offset() { return 0; }
static inline int CMSDK_AT_APB_SPI_end_offset(uint32_t offset) { return offset >= sizeof(CMSDK_AT_APB_SPI_TypeDef); }
static inline uint32_t CMSDK_AT_APB_SPI_next_offset(uint32_t offset) {
  switch (offset) {
  case 36: return 4092;
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
  case 64: return "KEYBOARD_PACKET";
  case 68: return "LOW_POWER";
  case 88: return "LPBACK_KSI";
  case 128: return "STATUS";
  case 192: return "INTERRUPTS";
  case 196: return "INTERRUPT_MASK";
  case 200: return "INTERRUPT_CLEAR";
  case 4084: return "DEBUG";
  case 4088: return "DEBUG2";
  case 4092: return "CORE_ID";
  default: return "unknown CMSDK_AT_APB_KSM offset";
  }
}

/*---------- Iterator ----------*/
static inline uint32_t CMSDK_AT_APB_KSM_begin_offset() { return 0; }
static inline int CMSDK_AT_APB_KSM_end_offset(uint32_t offset) { return offset >= sizeof(CMSDK_AT_APB_KSM_TypeDef); }
static inline uint32_t CMSDK_AT_APB_KSM_next_offset(uint32_t offset) {
  switch (offset) {
  case 12: return 64;
  case 68: return 88;
  case 88: return 128;
  case 128: return 192;
  case 200: return 4084;
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
  case 4092: return "CORE_ID";
  default: return "unknown CMSDK_AT_APB_QDEC offset";
  }
}

/*---------- Iterator ----------*/
static inline uint32_t CMSDK_AT_APB_QDEC_begin_offset() { return 0; }
static inline int CMSDK_AT_APB_QDEC_end_offset(uint32_t offset) { return offset >= sizeof(CMSDK_AT_APB_QDEC_TypeDef); }
static inline uint32_t CMSDK_AT_APB_QDEC_next_offset(uint32_t offset) {
  switch (offset) {
  case 56: return 4092;
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
  case 4092: return "CORE_ID";
  default: return "unknown CMSDK_AT_APB_SLWTIMER offset";
  }
}

/*---------- Iterator ----------*/
static inline uint32_t CMSDK_AT_APB_SLWTIMER_begin_offset() { return 0; }
static inline int CMSDK_AT_APB_SLWTIMER_end_offset(uint32_t offset) { return offset >= sizeof(CMSDK_AT_APB_SLWTIMER_TypeDef); }
static inline uint32_t CMSDK_AT_APB_SLWTIMER_next_offset(uint32_t offset) {
  switch (offset) {
  case 52: return 4092;
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
  case 16: return "REMOTE_AHB_SETUP";
  case 20: return "REMOTE_AHB_SETUP_2";
  case 24: return "REMOTE_AHB_SETUP_3";
  case 28: return "REMOTE_AHB_SETUP_4";
  case 32: return "REMOTE_AHB_SETUP_5";
  case 36: return "REMOTE_AHB_SETUP_6";
  case 40: return "REMOTE_AHB_SETUP_7";
  case 44: return "REMOTE_AHB_WLE_CNT";
  case 48: return "REMOTE_AHB_WIP_CNT";
  case 52: return "REMOTE_AHB_DBG0";
  case 56: return "REMOTE_AHB_DBG1";
  case 60: return "REMOTE_AHB_DBG2";
  case 4092: return "CORE_ID";
  default: return "unknown CMSDK_AT_APB_QSPI offset";
  }
}

/*---------- Iterator ----------*/
static inline uint32_t CMSDK_AT_APB_QSPI_begin_offset() { return 0; }
static inline int CMSDK_AT_APB_QSPI_end_offset(uint32_t offset) { return offset >= sizeof(CMSDK_AT_APB_QSPI_TypeDef); }
static inline uint32_t CMSDK_AT_APB_QSPI_next_offset(uint32_t offset) {
  switch (offset) {
  case 60: return 4092;
  default: return offset + 4;
  }
}
/*---------- AT_APB_I2C ----------*/
/*---------- Field name map ----------*/
static inline char const *CMSDK_AT_APB_I2C_offset_to_str(uint32_t offset) {
  switch (offset) {
  case 0: return "TRANSACTION_SETUP";
  case 4: return "CLOCK_CONTROL";
  case 8: return "OUTGOING_DATA";
  case 12: return "OUTGOING_DATA1";
  case 16: return "IO_CTRL";
  case 20: return "INCOMING_DATA";
  case 24: return "INCOMING_DATA1";
  case 28: return "TRANSACTION_STATUS";
  case 32: return "INTERRUPT_MASK";
  case 36: return "INTERRUPT_STATUS";
  case 40: return "SET_INTERRUPT";
  case 44: return "RESET_INTERRUPT";
  case 4092: return "ID";
  default: return "unknown CMSDK_AT_APB_I2C offset";
  }
}

/*---------- Iterator ----------*/
static inline uint32_t CMSDK_AT_APB_I2C_begin_offset() { return 0; }
static inline int CMSDK_AT_APB_I2C_end_offset(uint32_t offset) { return offset >= sizeof(CMSDK_AT_APB_I2C_TypeDef); }
static inline uint32_t CMSDK_AT_APB_I2C_next_offset(uint32_t offset) {
  switch (offset) {
  case 44: return 4092;
  default: return offset + 4;
  }
}
/*---------- AT_APB_TSMC_NVM ----------*/
/*---------- Field name map ----------*/
static inline char const *CMSDK_AT_APB_TSMC_NVM_offset_to_str(uint32_t offset) {
  switch (offset) {
  case 0: return "OPMODE";
  case 4: return "CTRL";
  case 8: return "DATA0";
  case 12: return "DATA1";
  case 16: return "STATUS";
  case 20: return "T_SP_VQ";
  case 24: return "T_HP_VQ";
  case 28: return "T_SP_PG";
  case 32: return "T_HP_PG";
  case 36: return "T_HP_CK";
  case 40: return "T_S_PGM";
  case 44: return "T_H_PGM";
  case 48: return "T_CKHP";
  case 52: return "T_CKLP";
  case 56: return "T_SPS_CK";
  case 60: return "T_SR_CK";
  case 64: return "T_HR_CK";
  case 68: return "T_CKLR";
  case 72: return "T_CKHR";
  case 76: return "T_SRS_CK";
  case 80: return "INTERRUPT_STATUS";
  case 84: return "INTERRUPT_MASK";
  case 88: return "INTERRUPT_SET";
  case 92: return "INTERRUPT_RESET";
  case 4092: return "CORE_ID";
  default: return "unknown CMSDK_AT_APB_TSMC_NVM offset";
  }
}

/*---------- Iterator ----------*/
static inline uint32_t CMSDK_AT_APB_TSMC_NVM_begin_offset() { return 0; }
static inline int CMSDK_AT_APB_TSMC_NVM_end_offset(uint32_t offset) { return offset >= sizeof(CMSDK_AT_APB_TSMC_NVM_TypeDef); }
static inline uint32_t CMSDK_AT_APB_TSMC_NVM_next_offset(uint32_t offset) {
  switch (offset) {
  case 92: return 4092;
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
  case 4092: return "CORE_ID";
  default: return "unknown CMSDK_AT_APB_WRPR_SHORT offset";
  }
}

/*---------- Iterator ----------*/
static inline uint32_t CMSDK_AT_APB_WRPR_SHORT_begin_offset() { return 0; }
static inline int CMSDK_AT_APB_WRPR_SHORT_end_offset(uint32_t offset) { return offset >= sizeof(CMSDK_AT_APB_WRPR_SHORT_TypeDef); }
static inline uint32_t CMSDK_AT_APB_WRPR_SHORT_next_offset(uint32_t offset) {
  switch (offset) {
  case 60: return 4092;
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
  case 116: return "SYNTX_CAL";
  case 120: return "SYNTX0";
  case 124: return "SYNTX1";
  case 128: return "SYNTX2";
  case 132: return "SYNTX3";
  case 136: return "SYNTX4";
  case 140: return "SYNTX5";
  case 144: return "DUTY_CYCLE";
  case 148: return "TXGAIN0_PMU";
  case 152: return "TXGAIN1_PMU";
  case 156: return "TXGAIN2_PMU";
  case 160: return "RX0";
  case 164: return "TIMER0";
  case 168: return "TIMER1";
  case 172: return "TIMER2";
  case 176: return "TIMER3";
  case 180: return "HADM_TIMER0";
  case 184: return "HADM_TIMER1";
  case 188: return "HADM_TIMER2";
  case 192: return "HADM_TIMER3";
  case 196: return "RXDC7";
  case 200: return "SYNTH_CHAN0";
  case 204: return "SYNTH_CHAN1";
  case 208: return "SYNTH_CHAN2";
  case 212: return "SYNTH_CHAN3";
  case 216: return "SYNTH_CHAN4";
  case 220: return "SYNTH_CHAN5";
  case 224: return "ADC_CNTL";
  case 228: return "MODE_CNTL";
  case 232: return "MODE_CNTL2";
  case 236: return "XLNA_XPA_CNTL";
  case 240: return "CAL_CNTL";
  case 244: return "CAL_DONE";
  case 4092: return "ID";
  default: return "unknown CMSDK_RIF offset";
  }
}

/*---------- Iterator ----------*/
static inline uint32_t CMSDK_RIF_begin_offset() { return 0; }
static inline int CMSDK_RIF_end_offset(uint32_t offset) { return offset >= sizeof(CMSDK_RIF_TypeDef); }
static inline uint32_t CMSDK_RIF_next_offset(uint32_t offset) {
  switch (offset) {
  case 244: return 4092;
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
  case 44: return "NOTCH_FORCE_DCCALRESULTS";
  case 48: return "PGA_CAL_GAIN_FORCE_DCCALRESULTS";
  case 52: return "PGA_CAL_GAIN_FORCE_DCCALRESULTS2";
  case 56: return "IQCORR";
  case 60: return "AGCMEAS_ALT";
  case 64: return "AGCGAIN_ALT";
  case 68: return "XLNA";
  case 72: return "XLNA_ALT";
  case 76: return "AGCSAT";
  case 80: return "AGCSAT_ALT";
  case 84: return "BASELINE";
  case 88: return "BASELINE_ALT";
  case 92: return "MARGIN";
  case 96: return "MARGIN_ALT";
  case 100: return "PWRSTEP";
  case 104: return "PWRSTEP_ALT";
  case 108: return "AGCPWR";
  case 112: return "AGCPWR_ALT";
  case 116: return "AGCPWR2";
  case 120: return "AGCPWR2_ALT";
  case 124: return "AGCTIME";
  case 128: return "AGCTIME_ALT";
  case 132: return "TWOMEG_AGCTIME";
  case 136: return "TWOMEG_AGCTIME_ALT";
  case 140: return "AGCTIME2";
  case 144: return "AGCTIME2_ALT";
  case 148: return "AGCCNTL";
  case 152: return "AGCCNTL_ALT";
  case 156: return "AGCPD";
  case 160: return "AGCPD_ALT";
  case 164: return "AGCDET";
  case 168: return "AGCDET_ALT";
  case 172: return "AGCOFFSET";
  case 176: return "AGCOFFSET_ALT";
  case 180: return "SYNCH";
  case 184: return "SYNCH_ALT";
  case 188: return "TIMETRACK";
  case 192: return "TIMESYNC";
  case 196: return "TIMESYNC_ALT";
  case 200: return "SYNCDEMOD";
  case 204: return "SYNCDEMOD_ALT";
  case 208: return "RESETINITCFO";
  case 212: return "RESETINITCFO_ALT";
  case 216: return "INTMFREQ";
  case 220: return "INTMFREQ_ALT";
  case 224: return "TSTIMEOUT";
  case 228: return "DEMOD";
  case 232: return "DFEWITHFFE";
  case 236: return "DFEWITHOUTFFE";
  case 240: return "TWOMEG_DFEWITHFFE";
  case 244: return "TWOMEG_DFEWITHOUTFFE";
  case 248: return "FREQ";
  case 252: return "FREQLIM";
  case 256: return "LR";
  case 260: return "LR_ALT";
  case 264: return "MIXER";
  case 268: return "ACCESS_ADDRESS";
  case 272: return "MODE";
  case 276: return "DCCAL";
  case 280: return "DCCAL2";
  case 284: return "DCCAL_CTRL";
  case 288: return "TIA_DCCAL";
  case 292: return "TIA_DCCAL2";
  case 296: return "TIA_DCCAL3";
  case 300: return "TIA_DCCAL4";
  case 304: return "PGA_DCCAL";
  case 308: return "PGA_DCCAL2";
  case 312: return "PGA_DCCAL3";
  case 316: return "PGA_DCCAL4";
  case 320: return "PGA_DCCAL5";
  case 324: return "NOTCH_DCCAL";
  case 328: return "NOTCH_DCCAL2";
  case 332: return "NOTCH_DCCAL3";
  case 336: return "DCOFFTRK";
  case 340: return "DCOFFTRK_ALT";
  case 344: return "DCOFFTRK2";
  case 348: return "DCOFFTRK2_ALT";
  case 352: return "DFCNTL";
  case 356: return "DFCNTL_ALT";
  case 360: return "SWANTCTETIME";
  case 364: return "DFTABLE";
  case 368: return "DFSTATUS";
  case 372: return "ANTRX3TO0";
  case 376: return "ANTTX3TO0";
  case 380: return "ANTRX7TO4";
  case 384: return "ANTTX7TO4";
  case 388: return "ANTIDLE";
  case 392: return "ANTID3TO0";
  case 396: return "ANTID7TO4";
  case 400: return "WHT_CTRL";
  case 404: return "DCCALRESULTS";
  case 408: return "DCCALRESULTS2";
  case 412: return "TIA_RETENT_DCCALRESULTS";
  case 416: return "TIA_DCCALRESULTS2";
  case 420: return "TIA_DCCALRESULTS3";
  case 424: return "TIA_LP_RETENT_DCCALRESULTS";
  case 428: return "TIA_LP_DCCALRESULTS2";
  case 432: return "PGA_RETENT_DCCALRESULTS";
  case 436: return "PGA_DCCALRESULTS2";
  case 440: return "PGA_DCCALRESULTS3";
  case 444: return "PGA_LP_RETENT_DCCALRESULTS";
  case 448: return "PGA_LP_DCCALRESULTS2";
  case 452: return "NOTCH_RETENT_DCCALRESULTS";
  case 456: return "NOTCH_DCCALRESULTS2";
  case 460: return "AGCSTATUS";
  case 464: return "MEASFREQ";
  case 468: return "EXPER";
  case 472: return "SPARE0";
  case 476: return "DEBUG";
  case 480: return "LC2LC";
  case 484: return "IRQ";
  case 488: return "IRQM";
  case 492: return "IRQC";
  case 496: return "ERR_INJ";
  case 500: return "DEBUG32";
  case 504: return "DUO";
  case 4092: return "CORE_ID";
  default: return "unknown CMSDK_MDM offset";
  }
}

/*---------- Iterator ----------*/
static inline uint32_t CMSDK_MDM_begin_offset() { return 0; }
static inline int CMSDK_MDM_end_offset(uint32_t offset) { return offset >= sizeof(CMSDK_MDM_TypeDef); }
static inline uint32_t CMSDK_MDM_next_offset(uint32_t offset) {
  switch (offset) {
  case 504: return 4092;
  default: return offset + 4;
  }
}
/*---------- AT_APB_PSEQ_PARIS ----------*/
/*---------- Field name map ----------*/
static inline char const *CMSDK_AT_APB_PSEQ_PARIS_offset_to_str(uint32_t offset) {
  switch (offset) {
  case 0: return "CTRL0";
  case 4: return "CTRL1";
  case 8: return "RETAIN_ALL_WAKE_MASK";
  case 12: return "HIB_WAKE_MASK";
  case 16: return "BLE_RET_TO_BLE_ACT_WAKE_MASK";
  case 20: return "BLE_RET_TO_CPU_ACT_WAKE_MASK";
  case 24: return "GPIO_WAKE_MASK";
  case 28: return "GPIO_WAKE_TYPE";
  case 32: return "GPIO_WAKE_POL";
  case 36: return "GPIO_WAKE_BOTH_EDGES";
  case 40: return "GPIO_WAKE_STATUS";
  case 44: return "WURX_CONFIG";
  case 48: return "WURX_CONFIG1";
  case 52: return "WURX_CONFIG2";
  case 56: return "GADC_CONFIG";
  case 60: return "XTAL_BITS0";
  case 64: return "XTAL_BITS1";
  case 68: return "OVERRIDES";
  case 72: return "OVERRIDES2";
  case 76: return "OVERRIDES3";
  case 80: return "OVERRIDES4";
  case 84: return "OVERRIDES5";
  case 88: return "SYSRAM_OVERRIDES";
  case 92: return "SYSRAM_OVERRIDES2";
  case 96: return "SYSRAM_OVERRIDES3";
  case 100: return "SYSRAM_OVERRIDES4";
  case 104: return "SYSRAM_OVERRIDES5";
  case 108: return "SYSRAM_OVERRIDES6";
  case 112: return "SYSRAM_OVERRIDES7";
  case 116: return "SYSRAM_OVERRIDES8";
  case 120: return "EMRAM_OVERRIDES";
  case 124: return "EMRAM_OVERRIDES2";
  case 128: return "EMRAM_OVERRIDES3";
  case 132: return "EMRAM_OVERRIDES4";
  case 136: return "EMRAM_OVERRIDES5";
  case 140: return "EMRAM_OVERRIDES6";
  case 144: return "EMRAM_OVERRIDES7";
  case 148: return "EMRAM_OVERRIDES8";
  case 152: return "ICACHE_OVERRIDES";
  case 156: return "ICACHE_OVERRIDES2";
  case 160: return "ICACHE_OVERRIDES3";
  case 164: return "ICACHE_OVERRIDES4";
  case 168: return "ICACHE_OVERRIDES5";
  case 172: return "ICACHE_OVERRIDES6";
  case 176: return "ICACHE_OVERRIDES7";
  case 180: return "ICACHE_OVERRIDES8";
  case 184: return "RRAMCACHE_OVERRIDES";
  case 188: return "RRAMCACHE_OVERRIDES2";
  case 192: return "RRAMCACHE_OVERRIDES3";
  case 196: return "RRAMCACHE_OVERRIDES4";
  case 200: return "RRAMCACHE_OVERRIDES5";
  case 204: return "RRAMCACHE_OVERRIDES6";
  case 208: return "RRAMCACHE_OVERRIDES7";
  case 212: return "RRAMCACHE_OVERRIDES8";
  case 216: return "QSPICACHE_OVERRIDES";
  case 220: return "COUNTER_CONTROL";
  case 224: return "CURRENT_REAL_TIME";
  case 228: return "CURRENT_COUNT_DOWN_TIME";
  case 232: return "INIT_COUNT_DOWN";
  case 236: return "INST_PENDING";
  case 240: return "STATUS";
  case 244: return "PERSISTENT0";
  case 248: return "PERSISTENT1";
  case 252: return "PERSISTENT2";
  case 256: return "PERSISTENT3";
  case 260: return "PERSISTENT4";
  case 264: return "PERSISTENT5";
  case 268: return "PERSISTENT6";
  case 272: return "PERSISTENT7";
  case 276: return "SENSOR_HUB_CONTROL";
  case 280: return "KSMQDEC_CONTROL";
  case 284: return "SPII2C_CONTROL";
  case 288: return "FLASH_CONTROL";
  case 292: return "FLASH_CONTROL2";
  case 296: return "PMU_STATUS";
  case 300: return "PMU_INTERRUPT";
  case 304: return "SYSRAM_WRITE_BLOCK_CFG";
  case 308: return "SYSRAM_SSRS_CFG";
  case 312: return "INTERRUPT_STATUS";
  case 316: return "INTERRUPT_MASK";
  case 320: return "RESET_INTERRUPT";
  case 324: return "FPGA_CFG";
  case 328: return "PLL";
  case 332: return "RADIO_STATUS";
  case 336: return "RRAM_READ_CONFIG_LO";
  case 340: return "RRAM_READ_CONFIG_HI";
  case 344: return "SENSOR_HUB_IMM_BREAKOUT_MASK";
  case 348: return "FSM_TUNINGA";
  case 352: return "FSM_TUNINGB";
  case 356: return "WDOG_CONTROL";
  case 360: return "WDOG_TIMER";
  case 4092: return "CORE_ID";
  default: return "unknown CMSDK_AT_APB_PSEQ_PARIS offset";
  }
}

/*---------- Iterator ----------*/
static inline uint32_t CMSDK_AT_APB_PSEQ_PARIS_begin_offset() { return 0; }
static inline int CMSDK_AT_APB_PSEQ_PARIS_end_offset(uint32_t offset) { return offset >= sizeof(CMSDK_AT_APB_PSEQ_PARIS_TypeDef); }
static inline uint32_t CMSDK_AT_APB_PSEQ_PARIS_next_offset(uint32_t offset) {
  switch (offset) {
  case 360: return 4092;
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
  case 4092: return "CORE_ID";
  default: return "unknown CMSDK_AT_APB_SWD offset";
  }
}

/*---------- Iterator ----------*/
static inline uint32_t CMSDK_AT_APB_SWD_begin_offset() { return 0; }
static inline int CMSDK_AT_APB_SWD_end_offset(uint32_t offset) { return offset >= sizeof(CMSDK_AT_APB_SWD_TypeDef); }
static inline uint32_t CMSDK_AT_APB_SWD_next_offset(uint32_t offset) {
  switch (offset) {
  case 88: return 4092;
  default: return offset + 4;
  }
}
/*---------- AT_APB_GADC ----------*/
/*---------- Field name map ----------*/
static inline char const *CMSDK_AT_APB_GADC_offset_to_str(uint32_t offset) {
  switch (offset) {
  case 0: return "CTRL";
  case 4: return "CTRL1";
  case 8: return "CH1_DATAPATH_CONFIG";
  case 12: return "CH2_DATAPATH_CONFIG";
  case 16: return "CH3_DATAPATH_CONFIG";
  case 20: return "CH4_DATAPATH_CONFIG";
  case 24: return "CH5_DATAPATH_CONFIG";
  case 28: return "CH6_DATAPATH_CONFIG";
  case 32: return "CH7_DATAPATH_CONFIG";
  case 36: return "CH8_DATAPATH_CONFIG";
  case 40: return "CH9_DATAPATH_CONFIG";
  case 44: return "CH10_DATAPATH_CONFIG";
  case 48: return "CH11_DATAPATH_CONFIG";
  case 52: return "CH12_DATAPATH_CONFIG";
  case 56: return "GAIN_CONFIG0";
  case 60: return "GAIN_CONFIG1";
  case 64: return "DATAPATH_OUTPUT";
  case 68: return "INTERRUPTS";
  case 72: return "INTERRUPT_MASK";
  case 76: return "INTERRUPT_CLEAR";
  case 80: return "FIFO_DBG";
  case 4092: return "CORE_ID";
  default: return "unknown CMSDK_AT_APB_GADC offset";
  }
}

/*---------- Iterator ----------*/
static inline uint32_t CMSDK_AT_APB_GADC_begin_offset() { return 0; }
static inline int CMSDK_AT_APB_GADC_end_offset(uint32_t offset) { return offset >= sizeof(CMSDK_AT_APB_GADC_TypeDef); }
static inline uint32_t CMSDK_AT_APB_GADC_next_offset(uint32_t offset) {
  switch (offset) {
  case 80: return 4092;
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
  case 4092: return "CORE_ID";
  default: return "unknown CMSDK_AT_APB_TRNG offset";
  }
}

/*---------- Iterator ----------*/
static inline uint32_t CMSDK_AT_APB_TRNG_begin_offset() { return 0; }
static inline int CMSDK_AT_APB_TRNG_end_offset(uint32_t offset) { return offset >= sizeof(CMSDK_AT_APB_TRNG_TypeDef); }
static inline uint32_t CMSDK_AT_APB_TRNG_next_offset(uint32_t offset) {
  switch (offset) {
  case 24: return 4092;
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
  case 4092: return "CORE_ID";
  default: return "unknown CMSDK_AT_APB_RCOS_CAL offset";
  }
}

/*---------- Iterator ----------*/
static inline uint32_t CMSDK_AT_APB_RCOS_CAL_begin_offset() { return 0; }
static inline int CMSDK_AT_APB_RCOS_CAL_end_offset(uint32_t offset) { return offset >= sizeof(CMSDK_AT_APB_RCOS_CAL_TypeDef); }
static inline uint32_t CMSDK_AT_APB_RCOS_CAL_next_offset(uint32_t offset) {
  switch (offset) {
  case 40: return 4092;
  default: return offset + 4;
  }
}
/*---------- AT_APB_SHUB ----------*/
/*---------- Field name map ----------*/
static inline char const *CMSDK_AT_APB_SHUB_offset_to_str(uint32_t offset) {
  switch (offset) {
  case 0: return "SETUP0";
  case 4: return "SETUP1";
  case 8: return "PORT0_SETUP";
  case 12: return "PORT0_SENSOR0_SETUP";
  case 16: return "PORT0_SENSOR1_SETUP";
  case 20: return "PORT0_SENSOR2_SETUP";
  case 24: return "PORT0_SENSOR3_SETUP";
  case 28: return "PORT0_SENSOR4_SETUP";
  case 32: return "PORT0_SENSOR5_SETUP";
  case 36: return "PORT0_SENSOR6_SETUP";
  case 40: return "PORT0_SENSOR7_SETUP";
  case 44: return "PORT0_SPI_ENG0_CTRL";
  case 48: return "PORT0_I2C_IDW_0";
  case 52: return "PORT0_I2C_IDW_1";
  case 56: return "PORT0_I2C_IDW_2";
  case 60: return "PORT0_I2C_IDW_3";
  case 64: return "PORT0_I2C_IDW_4";
  case 68: return "PORT0_I2C_IDW_5";
  case 72: return "PORT0_I2C_IDW_6";
  case 76: return "PORT0_I2C_IDW_7";
  case 80: return "PORT0_I2C_ADDR_0";
  case 84: return "PORT0_I2C_ADDR_1";
  case 88: return "PORT0_I2C_ADDR_2";
  case 92: return "PORT0_I2C_ADDR_3";
  case 96: return "PORT0_I2C_ADDR_4";
  case 100: return "PORT0_I2C_ADDR_5";
  case 104: return "PORT0_I2C_ADDR_6";
  case 108: return "PORT0_I2C_ADDR_7";
  case 112: return "PORT0_I2C_IDR_0";
  case 116: return "PORT0_I2C_IDR_1";
  case 120: return "PORT0_I2C_IDR_2";
  case 124: return "PORT0_I2C_IDR_3";
  case 128: return "PORT0_I2C_IDR_4";
  case 132: return "PORT0_I2C_IDR_5";
  case 136: return "PORT0_I2C_IDR_6";
  case 140: return "PORT0_I2C_IDR_7";
  case 144: return "PORT0_I2C_DAT_CTRL";
  case 148: return "PORT0_I2C_DAT_LAST_CTRL";
  case 152: return "PORT0_ALM0_QUAN_CTRL";
  case 156: return "PORT0_ALM1_QUAN_CTRL";
  case 160: return "PORT0_ALM0_TRIG_CTRL";
  case 164: return "PORT0_ALM1_TRIG_CTRL";
  case 168: return "PORT0_ALM0_THRHLD_MAX_0";
  case 172: return "PORT0_ALM0_THRHLD_MAX_1";
  case 176: return "PORT0_ALM0_THRHLD_MAX_2";
  case 180: return "PORT0_ALM0_THRHLD_MIN_0";
  case 184: return "PORT0_ALM0_THRHLD_MIN_1";
  case 188: return "PORT0_ALM0_THRHLD_MIN_2";
  case 192: return "PORT0_ALM1_THRHLD_MAX_0";
  case 196: return "PORT0_ALM1_THRHLD_MAX_1";
  case 200: return "PORT0_ALM1_THRHLD_MAX_2";
  case 204: return "PORT0_ALM1_THRHLD_MIN_0";
  case 208: return "PORT0_ALM1_THRHLD_MIN_1";
  case 212: return "PORT0_ALM1_THRHLD_MIN_2";
  case 216: return "PORT0_STATUS";
  case 220: return "PORT1_SETUP";
  case 224: return "PORT1_SENSOR0_SETUP";
  case 228: return "PORT1_SPI_ENG0_CTRL";
  case 232: return "PORT1_I2C_IDW_0";
  case 236: return "PORT1_I2C_ADDR_0";
  case 240: return "PORT1_I2C_IDR_0";
  case 244: return "PORT1_I2C_DAT_CTRL";
  case 248: return "PORT1_I2C_DAT_LAST_CTRL";
  case 252: return "PORT1_ALM0_QUAN_CTRL";
  case 256: return "PORT1_ALM0_TRIG_CTRL";
  case 260: return "PORT1_ALM0_THRHLD_MAX_0";
  case 264: return "PORT1_ALM0_THRHLD_MAX_1";
  case 268: return "PORT1_ALM0_THRHLD_MAX_2";
  case 272: return "PORT1_ALM0_THRHLD_MIN_0";
  case 276: return "PORT1_ALM0_THRHLD_MIN_1";
  case 280: return "PORT1_ALM0_THRHLD_MIN_2";
  case 284: return "PORT1_STATUS";
  case 288: return "FLASH_CTRL0";
  case 292: return "FLASH_CTRL1";
  case 296: return "FLASH_CTRL2";
  case 300: return "FLASH_CTRL3";
  case 304: return "FLASH_CTRL4";
  case 308: return "FLASH_STATUS0";
  case 312: return "FLASH_STATUS1";
  case 316: return "SHUB_STATUS0";
  case 320: return "PC_CTRL";
  case 324: return "PC_CTRL2";
  case 328: return "REG7";
  case 332: return "SHUB_SRAM_CLK_SEL";
  case 336: return "REGFILE_SEL";
  case 340: return "REGFILE_REGW";
  case 4092: return "ID";
  default: return "unknown CMSDK_AT_APB_SHUB offset";
  }
}

/*---------- Iterator ----------*/
static inline uint32_t CMSDK_AT_APB_SHUB_begin_offset() { return 0; }
static inline int CMSDK_AT_APB_SHUB_end_offset(uint32_t offset) { return offset >= sizeof(CMSDK_AT_APB_SHUB_TypeDef); }
static inline uint32_t CMSDK_AT_APB_SHUB_next_offset(uint32_t offset) {
  switch (offset) {
  case 340: return 4092;
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
  case 96: return "I2S_SPARE";
  case 100: return "I2S_DBG";
  case 4092: return "ID";
  default: return "unknown CMSDK_AT_I2S offset";
  }
}

/*---------- Iterator ----------*/
static inline uint32_t CMSDK_AT_I2S_begin_offset() { return 0; }
static inline int CMSDK_AT_I2S_end_offset(uint32_t offset) { return offset >= sizeof(CMSDK_AT_I2S_TypeDef); }
static inline uint32_t CMSDK_AT_I2S_next_offset(uint32_t offset) {
  switch (offset) {
  case 100: return 4092;
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
  case 4092: return "CORE_ID";
  default: return "unknown CMSDK_AT_APB_CLKRSTGEN offset";
  }
}

/*---------- Iterator ----------*/
static inline uint32_t CMSDK_AT_APB_CLKRSTGEN_begin_offset() { return 0; }
static inline int CMSDK_AT_APB_CLKRSTGEN_end_offset(uint32_t offset) { return offset >= sizeof(CMSDK_AT_APB_CLKRSTGEN_TypeDef); }
static inline uint32_t CMSDK_AT_APB_CLKRSTGEN_next_offset(uint32_t offset) {
  switch (offset) {
  case 36: return 4092;
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
  case 4084: return "STATUS1";
  case 4088: return "SIDELOAD_CTRL";
  case 4092: return "ID";
  default: return "unknown CMSDK_AT_APB_AES offset";
  }
}

/*---------- Iterator ----------*/
static inline uint32_t CMSDK_AT_APB_AES_begin_offset() { return 0; }
static inline int CMSDK_AT_APB_AES_end_offset(uint32_t offset) { return offset >= sizeof(CMSDK_AT_APB_AES_TypeDef); }
static inline uint32_t CMSDK_AT_APB_AES_next_offset(uint32_t offset) {
  switch (offset) {
  case 124: return 4084;
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
  case 4092: return "ID";
  default: return "unknown CMSDK_AT_AHB_DMA offset";
  }
}

/*---------- Iterator ----------*/
static inline uint32_t CMSDK_AT_AHB_DMA_begin_offset() { return 0; }
static inline int CMSDK_AT_AHB_DMA_end_offset(uint32_t offset) { return offset >= sizeof(CMSDK_AT_AHB_DMA_TypeDef); }
static inline uint32_t CMSDK_AT_AHB_DMA_next_offset(uint32_t offset) {
  switch (offset) {
  case 300: return 4092;
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
        {{ .name = "WRPR1_NONSECURE", .addr = 0x40153000 }, { .begin = CMSDK_AT_APB_WRPR_SHORT_begin_offset, .end = CMSDK_AT_APB_WRPR_SHORT_end_offset, .next = CMSDK_AT_APB_WRPR_SHORT_next_offset}, .offset_to_str = CMSDK_AT_APB_WRPR_SHORT_offset_to_str },
        {{ .name = "SHUB_NONSECURE", .addr = 0x4015d000 }, { .begin = CMSDK_AT_APB_SHUB_begin_offset, .end = CMSDK_AT_APB_SHUB_end_offset, .next = CMSDK_AT_APB_SHUB_next_offset}, .offset_to_str = CMSDK_AT_APB_SHUB_offset_to_str },
        {{ .name = "QDEC_NONSECURE", .addr = 0x4014c000 }, { .begin = CMSDK_AT_APB_QDEC_begin_offset, .end = CMSDK_AT_APB_QDEC_end_offset, .next = CMSDK_AT_APB_QDEC_next_offset}, .offset_to_str = CMSDK_AT_APB_QDEC_offset_to_str },
        {{ .name = "I2C0_NONSECURE", .addr = 0x40150000 }, { .begin = CMSDK_AT_APB_I2C_begin_offset, .end = CMSDK_AT_APB_I2C_end_offset, .next = CMSDK_AT_APB_I2C_next_offset}, .offset_to_str = CMSDK_AT_APB_I2C_offset_to_str },
        {{ .name = "PDM0_NONSECURE", .addr = 0x40160000 }, { .begin = CMSDK_AT_APB_PDM_begin_offset, .end = CMSDK_AT_APB_PDM_end_offset, .next = CMSDK_AT_APB_PDM_next_offset}, .offset_to_str = CMSDK_AT_APB_PDM_offset_to_str },
        {{ .name = "AT_PRRF_NONSECURE", .addr = 0x1ffe00 }, { .begin = CMSDK_AT_AHB_PRRF_begin_offset, .end = CMSDK_AT_AHB_PRRF_end_offset, .next = CMSDK_AT_AHB_PRRF_next_offset}, .offset_to_str = CMSDK_AT_AHB_PRRF_offset_to_str },
        {{ .name = "GADC_NONSECURE", .addr = 0x4015a000 }, { .begin = CMSDK_AT_APB_GADC_begin_offset, .end = CMSDK_AT_APB_GADC_end_offset, .next = CMSDK_AT_APB_GADC_next_offset}, .offset_to_str = CMSDK_AT_APB_GADC_offset_to_str },
        {{ .name = "SWD_NONSECURE", .addr = 0x40159000 }, { .begin = CMSDK_AT_APB_SWD_begin_offset, .end = CMSDK_AT_APB_SWD_end_offset, .next = CMSDK_AT_APB_SWD_next_offset}, .offset_to_str = CMSDK_AT_APB_SWD_offset_to_str },
        {{ .name = "SLWTIMER_NONSECURE", .addr = 0x4014e000 }, { .begin = CMSDK_AT_APB_SLWTIMER_begin_offset, .end = CMSDK_AT_APB_SLWTIMER_end_offset, .next = CMSDK_AT_APB_SLWTIMER_next_offset}, .offset_to_str = CMSDK_AT_APB_SLWTIMER_offset_to_str },
        {{ .name = "I2S_NONSECURE", .addr = 0x40165000 }, { .begin = CMSDK_AT_I2S_begin_offset, .end = CMSDK_AT_I2S_end_offset, .next = CMSDK_AT_I2S_next_offset}, .offset_to_str = CMSDK_AT_I2S_offset_to_str },
        {{ .name = "QSPI_NONSECURE", .addr = 0x4014f000 }, { .begin = CMSDK_AT_APB_QSPI_begin_offset, .end = CMSDK_AT_APB_QSPI_end_offset, .next = CMSDK_AT_APB_QSPI_next_offset}, .offset_to_str = CMSDK_AT_APB_QSPI_offset_to_str },
        {{ .name = "NVM_NONSECURE", .addr = 0x40152000 }, { .begin = CMSDK_AT_APB_TSMC_NVM_begin_offset, .end = CMSDK_AT_APB_TSMC_NVM_end_offset, .next = CMSDK_AT_APB_TSMC_NVM_next_offset}, .offset_to_str = CMSDK_AT_APB_TSMC_NVM_offset_to_str },
        {{ .name = "SPI0_NONSECURE", .addr = 0x40147000 }, { .begin = CMSDK_AT_APB_SPI_begin_offset, .end = CMSDK_AT_APB_SPI_end_offset, .next = CMSDK_AT_APB_SPI_next_offset}, .offset_to_str = CMSDK_AT_APB_SPI_offset_to_str },
        {{ .name = "SHA2_NONSECURE", .addr = 0x40103000 }, { .begin = CMSDK_AT_AHB_SHA2_begin_offset, .end = CMSDK_AT_AHB_SHA2_end_offset, .next = CMSDK_AT_AHB_SHA2_next_offset}, .offset_to_str = CMSDK_AT_AHB_SHA2_offset_to_str },
        {{ .name = "MDM_NONSECURE", .addr = 0x40156000 }, { .begin = CMSDK_MDM_begin_offset, .end = CMSDK_MDM_end_offset, .next = CMSDK_MDM_next_offset}, .offset_to_str = CMSDK_MDM_offset_to_str },
        {{ .name = "PWM_NONSECURE", .addr = 0x40146000 }, { .begin = CMSDK_AT_APB_PWM_begin_offset, .end = CMSDK_AT_APB_PWM_end_offset, .next = CMSDK_AT_APB_PWM_next_offset}, .offset_to_str = CMSDK_AT_APB_PWM_offset_to_str },
        {{ .name = "PSEQ_NONSECURE", .addr = 0x40158000 }, { .begin = CMSDK_AT_APB_PSEQ_PARIS_begin_offset, .end = CMSDK_AT_APB_PSEQ_PARIS_end_offset, .next = CMSDK_AT_APB_PSEQ_PARIS_next_offset}, .offset_to_str = CMSDK_AT_APB_PSEQ_PARIS_offset_to_str }
    };
    *num_blocks = sizeof(blocks)/sizeof(blocks[0]);
    return blocks;
}

#define CMSDK_BLOCK_ADDR_MASK 0xFFF

/** @} end of at_base_addr_utils */
