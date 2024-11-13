/**
 *******************************************************************************
 *
 * @file debug.c
 *
 * @brief Assert redirection
 *
 * Copyright (C) Atmosic 2017-2024
 *
 *******************************************************************************
 */

#ifdef CONFIG_SOC_FAMILY_ATM
#include <zephyr/kernel.h>
#include <soc.h>
#define PRINTF printk
#else
#define PRINTF printf
#endif

#include <inttypes.h>
#include <stdio.h>
#include <stdarg.h>
#include "stdbool.h"
#include "arch.h"
#if PLF_LCD
#include "lcd.h"
#endif
#if !defined(CONFIG_SOC_FAMILY_ATM) || defined(CONFIG_BT)
#include "dbg.h"
#endif
#include "timer.h"
#include "at_apb_wrpr_regs_core_macro.h"

/// FW type identification code over 1 HEX digit [0:F] for assertion display
#if defined(CFG_BT) && defined(CFG_BLE)
#define    __FW__                 '0'
#elif defined(CFG_BT)
#define    __FW__                 '1'
#elif defined(CFG_BLE) && !defined(CFG_HOST)
#define    __FW__                 '2'
#elif defined(CFG_BLE) && defined(CFG_HOST) && !defined(CFG_APP) && !defined(CFG_FRAMEWORK)
#define    __FW__                 '3'
#elif defined(CFG_BLE) && defined(CFG_HOST) && (defined(CFG_APP) || defined(CFG_FRAMEWORK))
#define    __FW__                 '4'
#else
#define    __FW__                 'X'
#endif

#if (PLF_DEBUG || defined(CFG_ROM))
/// Variable to enable infinite loop on assert
__NR_STATIC volatile int dbg_assert_block = 1;

#if PLF_LCD
static void display_file(const char * file)
{
    char line0[LCD_LINE_SIZE+1];
    size_t fsl = strlen(file);

    if (fsl > LCD_LINE_SIZE-1) {
	file += (fsl - (LCD_LINE_SIZE-1));
	fsl = LCD_LINE_SIZE-1;
    } else {
	// Initialize line 0 buffer with space character
	memset(line0, ' ', LCD_LINE_SIZE);
    }

    // Put file name at beginning of file line
    memcpy(line0, file, fsl);
    // Put FW identifier at end of file line
    line0[LCD_LINE_SIZE-1] = __FW__;
    // End of line character
    line0[LCD_LINE_SIZE] = 0;

    lcd_printf(LCD_LINE_2, line0);
}
#endif //PLF_LCD

void assert_err(const char *condition, const char * file, int line)
{
    GLOBAL_INT_STOP();
    PRINTF("ASSERT ERR(%s) at %s:%d\n", condition, file, line);
#ifdef TRC_REQ_SW_ASS_ERR
    TRC_REQ_SW_ASS_ERR(file, line, 0, 0);
#endif
#if !defined(CFG_USER) && defined(RW_DEBUG) && RW_DEBUG
    rwip_assert(file, line, 0, 0, ASSERT_TYPE_ERROR);
#endif

    #if PLF_LCD
    // Display current file - line
    display_file(file);
    lcd_printf(LCD_LINE_3, "%05d", line);
    #endif //PLF_LCD

    __BKPT(0);
    while(dbg_assert_block);
}

void assert_param(int param0, int param1, const char * file, int line)
{
    GLOBAL_INT_STOP();
    PRINTF("ASSERT PARAM(%d, %d) at %s:%d\n", param0, param1, file, line);
#ifdef TRC_REQ_SW_ASS_ERR
    TRC_REQ_SW_ASS_ERR(file, line, param0, param1);
#endif
#if !defined(CFG_USER) && defined(RW_DEBUG) && RW_DEBUG
    rwip_assert(file, line, param0, param1, ASSERT_TYPE_ERROR);
#endif

    #if PLF_LCD
    // Display current file - line
    display_file(file);
    lcd_printf(LCD_LINE_3, "%05d %d %d", line, param0, param1);
    #endif //PLF_LCD

    __BKPT(1);
    while(dbg_assert_block);
}

void assert_warn(int param0, int param1, const char * file, int line)
{
    PRINTF("ASSERT WARN(%d, %d) at %s:%d\n", param0, param1, file, line);
#ifdef TRC_REQ_SW_ASS_WARN
    TRC_REQ_SW_ASS_WARN(file, line, param0, param1);
#endif
#if !defined(CFG_USER) && defined(RW_DEBUG) && RW_DEBUG
    rwip_assert(file, line, param0, param1, ASSERT_TYPE_WARNING);
#endif

    #if PLF_LCD
    // Display current file - line
    display_file(file);
    lcd_printf(LCD_LINE_3, "%05d %d %d", line, param0, param1);
    #endif //PLF_LCD
}
#endif // PLF_DEBUG || CFG_ROM

#ifndef CFG_USER
int
debug_trace(const char *fmt, ...)
{
    va_list ap;

#ifndef CFG_ROM
    uint32_t rt = atm_get_sys_time();
#else
    uint32_t rt;
    {
	// Fire up PSEQ
	uint32_t APB8_CTRL = CMSDK_WRPR1->APB8_CTRL;
	CMSDK_WRPR1->APB8_CTRL = WRPR_APB8_CTRL__CLK_ENABLE__MASK;

	rt = CMSDK_PSEQ->CURRENT_REAL_TIME;

	// Done with PSEQ
	CMSDK_WRPR1->APB8_CTRL = APB8_CTRL;
    }
#endif

#ifdef CFG_ROM
    printf("@%08lx ", rt);
#else
    PRINTF("@%08" PRIx32 " ", rt);
#endif

    va_start(ap, fmt);
#ifdef CONFIG_SOC_FAMILY_ATM
    int ret = 0;
    vprintk(fmt, ap);
#else
    int ret = vprintf(fmt, ap);
#endif
    va_end(ap);

#ifdef CONFIG_SOC_FAMILY_ATM
    printk("\n");
#else
    putchar('\n');
#endif

    return (ret);
}
#endif // !CFG_USER
