/**
 *******************************************************************************
 *
 * @file user_debug.c
 *
 * @brief Print-based debug interface
 *
 * Copyright (C) Atmosic 2021-2023
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

#include "arch.h"
#include <inttypes.h>
#if defined(CFG_BLE_EMB) || defined(CFG_BLE_HOST)
#include "dbg.h"
#endif
#include "at_wrpr.h"

#if PLF_DEBUG
/// Variable to enable infinite loop on assert
volatile int dbg_assert_block = 1;

void assert_err(const char *condition, const char * file, int line)
{
    PRINTF("ASSERT ERR(%s) at %s:%d\n", condition, file, line);
#ifdef TRC_REQ_SW_ASS_ERR
    TRC_REQ_SW_ASS_ERR(file, line, 0, 0);
#endif

#if RW_DEBUG
    // Trigger assert message
    rwip_assert(file, line, 0, 0, ASSERT_TYPE_ERROR);
    // Let time for the message transfer
    for (int i = 0; i<2000;i++) {
	dbg_assert_block = 1;
    }
#endif

#ifdef FIXME
    asrt_line_set(line);
    asrt_addr_setf((uint32_t)file);
    asrt_trigg_setf(1);
#endif

    GLOBAL_INT_STOP();
    __BKPT(0);
    while (dbg_assert_block);
}

void assert_param(int param0, int param1, const char * file, int line)
{
    PRINTF("ASSERT PARAM(%#x, %#x) at %s:%d\n", (unsigned int)param0,
	(unsigned int)param1, file, line);
#ifdef TRC_REQ_SW_ASS_ERR
    TRC_REQ_SW_ASS_ERR(file, line, param0, param1);
#endif

#if RW_DEBUG
    // Trigger assert message
    rwip_assert(file, line, param0, param1, ASSERT_TYPE_ERROR);
    // Let time for the message transfer
    for (int i = 0; i<2000;i++) {
	dbg_assert_block = 1;
    }
#endif

#ifdef FIXME
    asrt_line_set(line);
    asrt_addr_setf((uint32_t)file);
    asrt_params_setf(1);
    asrt_param_1_setf(param0);
    asrt_param_2_setf(param1);
    asrt_params_setf(1);
    asrt_trigg_setf(1);
#endif

    GLOBAL_INT_STOP();
    __BKPT(1);
    while (dbg_assert_block);
}

void assert_warn(int param0, int param1, const char * file, int line)
{
    PRINTF("ASSERT WARN(%#x, %#x) at %s:%d\n", (unsigned int)param0,
	(unsigned int)param1, file, line);
#ifdef TRC_REQ_SW_ASS_WARN
    TRC_REQ_SW_ASS_WARN(file, line, param0, param1);
#endif

#if RW_DEBUG
    // Trigger assert message
    rwip_assert(file, line, param0, param1, ASSERT_TYPE_WARNING);
#endif

#ifdef FIXME
    asrt_line_set(line);
    asrt_addr_setf((uint32_t)file);
    asrt_params_setf(0);
    asrt_warn_setf(1);
#endif
}

int
debug_trace(const char *fmt, ...)
{
    uint32_t rt;
    WRPR_CTRL_PUSH(CMSDK_PSEQ, WRPR_CTRL__CLK_ENABLE) {
	rt = CMSDK_PSEQ->CURRENT_REAL_TIME;
    } WRPR_CTRL_POP();

    PRINTF("@%08" PRIx32 " ", rt);

    va_list ap;
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

void dump_hci(uint8_t type, uint8_t direction, uint8_t* p_data, uint16_t length, uint8_t* p_hdr_data, uint16_t hdr_length)
{
#ifdef FIXME
    asrt_dump_ext_cfg_set(hdr_length);
    asrt_dump_ext_data_addr_setf((uint32_t)p_hdr_data);
    asrt_dump_data_addr_setf((uint32_t)p_data);
    asrt_dump_cfg_pack(/*log*/    0,
                       /*hci*/    1,
                       /*ext*/    ((hdr_length > 0) ? 1 : 0),
                       /*packed*/ 1,
                       /*level*/  0,
                       /*dir*/    ((direction == 1) ? 1 : 0),
                       /*type*/   type,
                       /*length*/ length);
#endif
}

void dump_upk_hci(uint8_t evttype, uint8_t direction, uint16_t code, uint8_t* p_data, uint16_t length)
{
#ifdef FIXME
    asrt_dump_ext_cfg_set(code);
    asrt_dump_data_addr_setf((uint32_t)p_data);
    asrt_dump_cfg_pack(/*log*/    0,
                       /*hci*/    1,
                       /*ext*/    0,
                       /*packed*/ 0,
                       /*level*/  0,
                       /*dir*/    ((direction == 1) ? 1 : 0),
                       /*type*/   evttype,
                       /*length*/ length);

#endif
}
#endif //PLF_DEBUG
