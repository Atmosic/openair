/**
 *******************************************************************************
 *
 * @file fp_mode.h
 *
 * @brief Atmosic Google Fast Pair Service (GFPS) Mode Middleware
 *
 * Copyright (C) Atmosic 2025-2026
 *
 *******************************************************************************
 */

#pragma once

#include "compiler.h" // __NONNULL_ALL inline functions
#include "fp_common.h"

/**
 * @addtogroup ATM_BTFMDN Google Fast Pair Service
 * @brief Mode Middleware of Fast Pair Service
 *
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/* Power-loss recovery state */
typedef enum {
	POWER_LOSS_RECOVERY_IDLE,
	POWER_LOSS_RECOVERY_CONTINUOUS,
	POWER_LOSS_RECOVERY_PERIODIC,
} power_loss_recovery_state_t;

/**
 * @brief FP mode init
 */
void fp_mode_init(void);

/**
 * @brief fp get current fp mode
 *
 * @return current fp mode
 */
fp_mode_t fp_mode_get(void);

/**
 * @brief fp update current fp mode
 * @param[in] mode fp mode
 */
void fp_mode_update(fp_mode_t mode);

/**
 * @brief fp current fp mode is provisioned
 *
 * @return true if current fp mode is provisioned
 */
bool fp_mode_is_provisioned(void);

/**
 * @brief fp current fp mode is paired
 *
 * @return true if current fp mode is paired
 */
bool fp_mode_is_paired(void);

/**
 * @brief fp current fp mode is pairing
 *
 * @return true if current fp mode is pairing
 */
bool fp_mode_is_pairing(void);

/**
 * @brief The callback function of mode switch notify
 * @param[in] mode fast pairing mode
 */
typedef void (*fp_mode_switch_cb)(fp_mode_t mode);

/**
 * @brief gfps fp mode switch handler register
 * @param[in] hdlr fp mode switch handler structure
 */
__NONNULL_ALL
void fp_mode_switch_reg(fp_mode_switch_cb const hdlr);

/**
 * @brief fp current fp mode rap timeout calculate
 *
 * @return rap timeout
 */
uint16_t fp_mode_rpa_timeout(void);

/**
 * @brief Get current power loss recovery state
 *
 * @return current PLR state
 */
power_loss_recovery_state_t fp_mode_power_loss_recovery_state_get(void);

/**
 * @brief fp current fp mode power loss recovery required
 * @param[in] mode fp mode
 *
 * @return true if power loss recovery required
 */
bool fp_mode_power_loss_recovery_required_adv(fp_mode_t mode);

/**
 * @brief Start power-loss recovery advertising
 */
void fp_mode_power_loss_recovery_start(void);

/**
 * @brief Stop power-loss recovery advertising
 */
void fp_mode_power_loss_recovery_stop(void);

/**
 * @brief Check if in periodic advertising phase
 * @return true if periodic, false otherwise
 */
bool fp_mode_power_loss_is_periodic(void);

#ifdef __cplusplus
}
#endif

#if defined(CONFIG_ZTEST)
void fp_mode_test_adv_sync(void);
void fp_mode_test_adv_sync_plr_state(void);
void fp_mode_test_adv_sync_plr_periodic(void);
void fp_mode_test_plr_start(void);
void fp_mode_test_plr_stop(void);
bool fp_mode_test_plr_is_periodic(void);
void fp_mode_test_plr_timeout(void);
void fp_mode_test_plr_periodic(void);
#endif /* CONFIG_ZTEST */

///@}
