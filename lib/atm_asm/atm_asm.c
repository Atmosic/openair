/**
 *******************************************************************************
 *
 * @file atm_asm.c
 *
 * @brief Atmosic application state machine
 *
 * Copyright (C) Atmosic 2020-2024
 *
 *******************************************************************************
 */

#ifdef CONFIG_SOC_FAMILY_ATM
#include <assert.h>
#include <zephyr/kernel.h>
#endif
#include "arch.h"
#include "atm_asm.h"

/*
 * DEFINES
 * *****************************************************************************
 */
#ifndef CFG_S_MAX_ENTRY
/// Number of state machine table instances
#define CFG_S_MAX_ENTRY 1
#endif

#ifdef CFG_ASM_BITWISE
#define ISONEHOT(x) (x && !(x & (x - 1)))
#endif

/*
 * VARIABLE
 * *****************************************************************************
 */
static struct {
    state_entry const *table;
    uint8_t table_cnt;
    ASM_O operation;
    ASM_S state;
    ASM_S pre_state;
    void (*cb_state_change)(ASM_S last_s, ASM_O op, ASM_S next_s);
    void (*cb_state_changed)(ASM_S last_s, ASM_O op, ASM_S next_s);
#ifdef CONFIG_SOC_FAMILY_ATM
    struct k_mutex mutex;
#endif
} atm_state[CFG_S_MAX_ENTRY];

/*
 * GLOBAL
 * *****************************************************************************
 */
void atm_asm_init_table(
    uint8_t idx, const state_entry s_tbl[], uint8_t s_tbl_size)
{
    ASSERT_INFO(idx < CFG_S_MAX_ENTRY, CFG_S_MAX_ENTRY, idx);
    atm_state[idx].table = s_tbl;
    atm_state[idx].table_cnt = s_tbl_size;
#ifdef CONFIG_SOC_FAMILY_ATM
    k_mutex_init(&atm_state[idx].mutex);
#endif
}

static void atm_asm_set_state(uint8_t idx, ASM_S state, ASM_O op_code,
    state_handler handler)
{
#ifdef CFG_ASM_BITWISE
    ASSERT_ERR(ISONEHOT(state) && ISONEHOT(op_code));
#endif
    ASSERT_INFO(idx < CFG_S_MAX_ENTRY, CFG_S_MAX_ENTRY, idx);

#ifdef CONFIG_SOC_FAMILY_ATM
    k_mutex_lock(&atm_state[idx].mutex, K_FOREVER);
#endif
    if (atm_state[idx].cb_state_change) {
	atm_state[idx].cb_state_change(atm_state[idx].state, op_code, state);
    }

    atm_state[idx].pre_state = atm_state[idx].state;
    atm_state[idx].state = state;
    atm_state[idx].operation = op_code;

    if (handler) {
	handler();
    }

    if (atm_state[idx].cb_state_changed) {
	atm_state[idx].cb_state_changed(atm_state[idx].pre_state, op_code,
	    state);
    }

#ifdef CONFIG_SOC_FAMILY_ATM
    k_mutex_unlock(&atm_state[idx].mutex);
#endif
}

void atm_asm_set_state_op(uint8_t idx, ASM_S state, ASM_O op_code)
{
    atm_asm_set_state(idx, state, op_code, NULL);
}

ASM_S atm_asm_get_current_state(uint8_t idx)
{
    ASSERT_INFO(idx < CFG_S_MAX_ENTRY, CFG_S_MAX_ENTRY, idx);
#ifdef CONFIG_SOC_FAMILY_ATM
    k_mutex_lock(&atm_state[idx].mutex, K_FOREVER);
#endif
    ASM_S state = atm_state[idx].state;
#ifdef CONFIG_SOC_FAMILY_ATM
    k_mutex_unlock(&atm_state[idx].mutex);
#endif
    return state;
}

void atm_asm_set_current_state(uint8_t idx, ASM_S state)
{
    atm_asm_set_state(idx, state, atm_state[idx].operation, NULL);
}

atm_asm_trans atm_asm_get_latest_transition(uint8_t idx)
{
#ifdef CONFIG_SOC_FAMILY_ATM
    k_mutex_lock(&atm_state[idx].mutex, K_FOREVER);
#endif
    atm_asm_trans trans = {atm_state[idx].pre_state, atm_state[idx].operation,
	atm_state[idx].state};
#ifdef CONFIG_SOC_FAMILY_ATM
    k_mutex_unlock(&atm_state[idx].mutex);
#endif
    return trans;
}

void atm_asm_move(uint8_t idx, ASM_O next_op)
{
#ifdef CFG_ASM_BITWISE
    ASSERT_ERR(ISONEHOT(next_op));
#endif
    ASSERT_INFO(idx < CFG_S_MAX_ENTRY, CFG_S_MAX_ENTRY, idx);
    state_entry const *s_tbl = atm_state[idx].table;

#ifdef CONFIG_SOC_FAMILY_ATM
    k_mutex_lock(&atm_state[idx].mutex, K_FOREVER);
#endif

    for (uint8_t i = 0; i < atm_state[idx].table_cnt; i++) {
#ifdef CFG_ASM_BITWISE
	if ((atm_state[idx].state & s_tbl[i].state) &&
	    (next_op & s_tbl[i].operation)) {
#else
	if ((atm_state[idx].state == s_tbl[i].state) &&
	    (next_op == s_tbl[i].operation)) {
#endif
	    atm_asm_set_state_op(idx, s_tbl[i].next_state, next_op);
	    if (s_tbl[i].handler) {
		s_tbl[i].handler();
	    }
#ifdef CONFIG_SOC_FAMILY_ATM
	    k_mutex_unlock(&atm_state[idx].mutex);
#endif
	    return;
	}
    }
#ifdef CONFIG_SOC_FAMILY_ATM
    __ASSERT(0, "idx:%d state:%d next_op:%d can't find next state", idx,
	atm_state[idx].state, next_op);
#else
    ASSERT_INFO(0, atm_state[idx].state, next_op);
#endif
}

void atm_asm_reg_state_change_cb(
    uint8_t idx, void (*cb)(ASM_S last_s, ASM_O op, ASM_S next_s))
{
    ASSERT_INFO(idx < CFG_S_MAX_ENTRY, CFG_S_MAX_ENTRY, idx);
    atm_state[idx].cb_state_change = cb;
}

void atm_asm_reg_state_changed_cb(uint8_t idx,
    void (*cb)(ASM_S last_s, ASM_O op, ASM_S next_s))
{
    ASSERT_INFO(idx < CFG_S_MAX_ENTRY, CFG_S_MAX_ENTRY, idx);
    atm_state[idx].cb_state_changed = cb;
}
