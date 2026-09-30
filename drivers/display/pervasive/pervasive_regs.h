/**
 *******************************************************************************
 *
 * @file pervasive_regs.h
 *
 * @brief Parameters of pervasive EPD devices.
 *
 * The confidential and proprietary information contained in this file may
 * only be used by a person authorised under and to the extent permitted
 * by a subsisting licensing agreement from Atmosic.
 *
 * Copyright (C) Atmosic 2024
 *
 * This entire notice must be reproduced on all copies of this file
 * and copies of this file may only be made by a person if such person is
 * permitted to do so under the terms of a subsisting license agreement
 * from Atmosic.
 *
 *******************************************************************************
 */

/* reg idx*/
#define PERVASIVE_SEPD_IDX_SRST  0x00
#define PERVASIVE_SEPD_IDX_TEMP  0xe5
#define PERVASIVE_SEPD_IDX_ACTT  0xe0
#define PERVASIVE_SEPD_IDX_PSR   0x00
#define PERVASIVE_SEPD_IDX_DCDC  0x04
#define PERVASIVE_SEPD_IDX_DCOFF 0x02
#define PERVASIVE_SEPD_IDX_REFSH 0x12

/* reg value */
#define PERVASIVE_SEPD_VAL_SRST 0x0e
#define PERVASIVE_SEPD_VAL_TEMP 0x19
#define PERVASIVE_SEPD_VAL_ACTT 0x02
#define PERVASIVE_SEPD_VAL_PSR  0xcf, 0x8d

#define PERVASIVE_MEPD_VAL_SRST 0x0e
#define PERVASIVE_MEPD_VAL_TEMP 0x19
#define PERVASIVE_MEPD_VAL_ACTT 0x02
#define PERVASIVE_MEPD_VAL_PSR  0x0f, 0x89

/* time constants in ms */
#define E2266CS0C2_RESET_BEFORE_DELAY 5
#define E2266CS0C2_RESET_ING_DELAY    10
#define E2266CS0C2_RESET_AFTER_DELAY  5
#define PERVASIVE_BUSY_DELAY          1
#define E2266QS0F1_RESET_BEFORE_DELAY 20
#define E2266QS0F1_RESET_ING_DELAY    40
#define E2266QS0F1_RESET_AFTER_DELAY  10
#define E2741JS0B2_RESET_BEFORE_DELAY 20
#define E2741JS0B2_RESET_ING_DELAY    200
#define E2741JS0B2_RESET_AFTER_DELAY  50
