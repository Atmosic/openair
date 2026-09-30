/**
 *******************************************************************************
 *
 * @file user_debug.c
 *
 * @brief Print-based debug interface
 *
 * Copyright (C) Atmosic 2021-2026
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 *
 *******************************************************************************
 */

#ifdef CONFIG_SOC_FAMILY_ATM
#include <zephyr/kernel.h>
#include <soc.h>
#include <stdio.h>

#define PRINTF(fmt, ...) \
    do { \
	if (k_is_pre_kernel()) { \
	    printf(fmt, ##__VA_ARGS__); \
	} else { \
	    printk(fmt, ##__VA_ARGS__); \
	} \
    } while (0)
#else
#define PRINTF printf
#endif

#include "arch.h"
#include <inttypes.h>
#if defined(CFG_BLE_EMB) || defined(CFG_BLE_HOST)
#include "dbg.h"
#include "rwip.h"
#else
#define TRC_REQ_SW_ASS_ERR(filename, code_line, param0, param1)
#define TRC_REQ_SW_ASS_WARN(filename, code_line, param0, param1)
#define RW_DEBUG 0
#endif
#include "at_wrpr.h"

#ifdef CONFIG_ATM_ASSERT_THREAD_DUMP
#include <cmsis_core.h>
#include <zephyr/debug/thread_analyzer.h>
#include <zephyr/fatal.h>
#include <zephyr/logging/log_ctrl.h>
#include <zephyr/sys/util.h>
#endif

#if PLF_DEBUG
/// Variable to enable infinite loop on assert
volatile int dbg_assert_block = 1;

#ifdef CONFIG_ATM_ASSERT_THREAD_DUMP
/// Flag to ensure the thread dump runs at most once per fatal path
static volatile bool thread_dump_done;

static void get_thread_regs(struct k_thread const *thread, uint32_t *pc,
    uint32_t *lr, uint32_t *sp)
{
    if (thread == k_current_get()) {
	*pc = (uint32_t)get_thread_regs;
	__asm__ volatile("mov %0, lr" : "=r"(*lr));
	__asm__ volatile("mov %0, sp" : "=r"(*sp));
	return;
    }

    // For non-current threads, callee_saved.psp points at the exception
    // stack frame (r0-r3, r12, lr, pc, xpsr) saved on context switch
    uint32_t psp = thread->callee_saved.psp;
    struct __basic_sf const *esf = (struct __basic_sf const *)psp;
    *pc = esf->pc;
    *lr = esf->lr;
    *sp = psp + sizeof(struct __basic_sf);
}

static void print_thread_info(struct k_thread const *thread)
{
    char state_str[32];
    uint32_t pc;
    uint32_t lr;
    uint32_t sp;
    size_t unused = 0;
    size_t size = thread->stack_info.size;

    get_thread_regs(thread, &pc, &lr, &sp);
    k_thread_stack_space_get(thread, &unused);
    size_t used = size - unused;

    PRINTF("%p %-16s state:%-10s prio:%3d%s\n", (void const *)thread,
	k_thread_name_get((k_tid_t)thread) ?: "<unnamed>",
	k_thread_state_str((k_tid_t)thread, state_str, sizeof(state_str)),
	thread->base.prio, (thread == k_current_get()) ? " <current>" : "");
    PRINTF("  PC=0x%08" PRIx32 " LR=0x%08" PRIx32 " SP=0x%08" PRIx32 "\n", pc,
	lr, sp);
    PRINTF("  stack: used %u/%u (%u%%) pended_on: %p\n", (unsigned int)used,
	(unsigned int)size, (unsigned int)(size ? (used * 100 / size) : 0),
	(void const *)thread->base.pended_on);

    uint32_t top = thread->stack_info.start + size;
    uint32_t end =
	sp + (CONFIG_ATM_ASSERT_THREAD_DUMP_MAX_WORDS * sizeof(uint32_t));
    if ((sp >= thread->stack_info.start) && (sp < top) && (end > top)) {
	end = top;
    }
    PRINTF("  stack dump @0x%08" PRIx32 ":", sp);
    for (uint32_t addr = sp, i = 0; addr < end; addr += sizeof(uint32_t), i++) {
	if (!(i % 4)) {
	    PRINTF("\n   ");
	}
	PRINTF(" %08" PRIx32, *(uint32_t const *)addr);
    }
    PRINTF("\n");
}

static void print_irq_state(void)
{
    PRINTF("IPSR: 0x%08" PRIx32 "\n", __get_IPSR());
    PRINTF("SysTick CTRL=0x%08" PRIx32 " LOAD=0x%08" PRIx32 " VAL=0x%08" PRIx32
	   "\n",
	SysTick->CTRL, SysTick->LOAD, SysTick->VAL);
    for (unsigned int i = 0; i < ARRAY_SIZE(NVIC->ISER); i++) {
	if (NVIC->ISER[i] || NVIC->ISPR[i]) {
	    PRINTF("NVIC[%u] ISER=0x%08" PRIx32 " ISPR=0x%08" PRIx32 "\n", i,
		NVIC->ISER[i], NVIC->ISPR[i]);
	}
    }
}

void atm_debug_thread_dump(void)
{
    if (thread_dump_done) {
	return;
    }
    thread_dump_done = true;

    LOG_PANIC();

    PRINTF("=== ASSERT: Thread Dump ===\n");
    for (struct k_thread const *thread = _kernel.threads; thread;
	 thread = thread->next_thread) {
	print_thread_info(thread);
    }
    print_irq_state();
    thread_analyzer_print(0);
    PRINTF("=== END Thread Dump ===\n");
}

void k_sys_fatal_error_handler(unsigned int reason, struct arch_esf const *esf)
{
    PRINTF("Fatal error: reason %u\n", reason);
    if (esf) {
	PRINTF("Faulting context: PC=0x%08" PRIx32 " LR=0x%08" PRIx32 "\n",
	    esf->basic.pc, esf->basic.lr);
    }
    atm_debug_thread_dump();
    k_fatal_halt(reason);
}

#define ATM_THREAD_DUMP() atm_debug_thread_dump()
#else
#define ATM_THREAD_DUMP() \
    do { \
    } while (0)
#endif // CONFIG_ATM_ASSERT_THREAD_DUMP

void assert_err(const char *condition, const char * file, int line)
{
#ifdef __ASSERT
#if !defined(CONFIG_ASSERT_NO_COND_INFO) && !defined(CONFIG_ASSERT_NO_FILE_INFO)
    __ASSERT_PRINT("ASSERTION FAIL [%s] @ %s:%d\n", condition, file, line);
#elif defined(CONFIG_ASSERT_NO_COND_INFO) && \
    !defined(CONFIG_ASSERT_NO_FILE_INFO)
    __ASSERT_PRINT("ASSERTION FAIL @ %s:%d\n", file, line);
#elif !defined(CONFIG_ASSERT_NO_COND_INFO) && \
    defined(CONFIG_ASSERT_NO_FILE_INFO)
    __ASSERT_PRINT("ASSERTION FAIL [%s]\n", condition);
#else // NO_COND_INFO and NO_FILE_INFO
    __ASSERT_PRINT("ASSERTION FAIL\n");
#endif
    ATM_THREAD_DUMP();
    __ASSERT_POST_ACTION();
#ifdef __ASSERT_UNREACHABLE
    __ASSERT_UNREACHABLE;
#endif
#else // __ASSERT
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

#endif // __ASSERT
    ATM_THREAD_DUMP();
    GLOBAL_INT_STOP();
    __BKPT(0);
    while (dbg_assert_block);
}

void assert_param(int param0, int param1, const char * file, int line)
{
#ifdef __ASSERT
#ifndef CONFIG_ASSERT_NO_FILE_INFO
    __ASSERT_PRINT("ASSERTION FAIL @ %s:%d\n", file, line);
#else
    __ASSERT_PRINT("ASSERTION FAIL\n");
#endif
    __ASSERT_MSG_INFO("PARAM(%#x, %#x)", (unsigned int)param0,
	(unsigned int)param1);
    ATM_THREAD_DUMP();
    __ASSERT_POST_ACTION();
#ifdef __ASSERT_UNREACHABLE
    __ASSERT_UNREACHABLE;
#endif
#else // __ASSERT
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

#endif // __ASSERT
    ATM_THREAD_DUMP();
    GLOBAL_INT_STOP();
    __BKPT(1);
    while (dbg_assert_block);
}

void assert_warn(int param0, int param1, const char * file, int line)
{
#ifdef __ASSERT
#ifndef CONFIG_ASSERT_NO_FILE_INFO
    __ASSERT_PRINT("ASSERTION FAIL @ %s:%d\n", file, line);
#else
    __ASSERT_PRINT("ASSERTION FAIL\n");
#endif
    __ASSERT_MSG_INFO("WARN(%#x, %#x)", (unsigned int)param0,
	(unsigned int)param1);
    __ASSERT_POST_ACTION();
#ifdef __ASSERT_UNREACHABLE
    __ASSERT_UNREACHABLE;
#endif
#else // __ASSERT
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
#endif // __ASSERT
}

__attribute__((weak))
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
    if (k_is_pre_kernel()) {
	ret = vprintf(fmt, ap);
    } else {
	vprintk(fmt, ap);
    }
#else
    int ret = vprintf(fmt, ap);
#endif
    va_end(ap);

#ifdef CONFIG_SOC_FAMILY_ATM
    PRINTF("\n");
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
