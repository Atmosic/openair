/**
 *******************************************************************************
 *
 * @file atm_asm.h
 *
 * @brief Atmosic application state machine
 *
 * Copyright (C) Atmosic 2020-2023
 *
 *******************************************************************************
 */

#pragma once

/**
 *******************************************************************************
 * @defgroup ATM_BTFM_PASM Application state machine
 * @ingroup ATM_BTFM_PROC
 * @brief ATM bluetooth framework state machine tool
 *
 * This module contains the necessary function of state machine tool
 *
 * @{
 *******************************************************************************
 */

#include <stdint.h>
#include "atm_utils_math.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * MACROS
 *******************************************************************************
 */
#define S_OP(s, op) (s), (op)

/*
 * TYPEDEFINE
 *******************************************************************************
 */

#ifdef CFG_ASM_BITWISE
typedef uint32_t ASM_T;
#else
typedef uint8_t ASM_T;
#endif
typedef ASM_T ASM_S;
typedef ASM_T ASM_O;

/**
 * @brief Simple handler
 */
typedef void (*state_handler)(void);

typedef struct {
    /// state code
    ASM_S state;
    /// operation code
    ASM_O operation;
    /// next state
    ASM_S next_state;
    /// handler function for state_operation
    state_handler handler;
} state_entry;
typedef struct {
    /// state code
    ASM_S pre_state;
    /// operation code
    ASM_O operation;
    /// next state
    ASM_S cur_state;
} atm_asm_trans;

/*
 * GLOBAL
 *******************************************************************************
 */
/**
 * @brief Insert application state machine table into framework
 * @param[in] idx        instance index
 * @param[in] s_tbl      state machine table
 * @param[in] s_tbl_size size of state machine table
 */
void atm_asm_init_table(uint8_t idx, const state_entry s_tbl[],
    uint8_t s_tbl_size);

/**
 * @brief Set state
 * @param[in] idx        instance index
 * @param[in] state      state value
 */
void atm_asm_set_current_state(uint8_t idx, ASM_S state);

/**
 * @brief Get current state
 * @param[in] idx        instance index
 * @return current state
 */
ASM_S atm_asm_get_current_state(uint8_t idx);

/**
 * @brief Update current state and operation code
 * @param[in] idx        instance index
 * @param[in] state      state value
 * @param[in] op_code    operation code
 */
void atm_asm_set_state_op(uint8_t idx, ASM_S state, ASM_O op_code);

/**
 * @brief Get lastest transition
 * @param[in] idx instance index
 */
atm_asm_trans atm_asm_get_latest_transition(uint8_t idx);

/**
 * @brief Move to handler function by operation code then update state
 * @param[in] idx         instance index
 * @param[in] next_op     move state to this
 */
void atm_asm_move(uint8_t idx, ASM_O next_op);

/**
 * @brief Set callback function to be informed before state machine transitions.
 * @param[in] idx        instance index
 * @param[in] cb         callback function
 */
void atm_asm_reg_state_change_cb(uint8_t idx,
    void (*cb)(ASM_S last_s, ASM_O op, ASM_S next_s));

/**
 * @brief Set callback function to be informed after state machine transitions.
 * @param[in] idx        instance index
 * @param[in] cb         callback function
 */
void atm_asm_reg_state_changed_cb(uint8_t idx,
    void (*cb)(ASM_S last_s, ASM_O op, ASM_S next_s));

/**
 *******************************************************************************
 * @brief Get ordinal number of ASM_O or ASM_S.
 * @param code Specific state code or operation code.
 * @return Ordinal number of this state.
 *******************************************************************************
 */
static inline uint8_t atm_asm_ordinal(ASM_T code)
{
#ifdef CFG_ASM_BITWISE
    return atm_ctz(code);
#else
    return code;
#endif
}

#ifdef __cplusplus
}
#endif

///@} ATM_BTFM_PASM


