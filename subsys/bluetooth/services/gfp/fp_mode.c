/**
 *******************************************************************************
 *
 * @file fp_mode.c
 *
 * @brief Atmosic Google Fast Pair Service (GFPS) Mode Middleware
 *
 * Copyright (C) Atmosic 2025-2026
 *
 *******************************************************************************
 */

#include <errno.h>
#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
#include <zephyr/random/random.h>
#include <zephyr/sys/util.h>
#include "fp_adv.h"
#include "fp_fmdn_adv.h"
#include "fp_mode.h"
#include "fp_storage.h"

LOG_MODULE_DECLARE(gfps, CONFIG_ATM_GFPS_LOG_LEVEL);

fp_mode_t cur_mode;
static fp_mode_switch_cb mode_switch_cb;

#ifdef CONFIG_FAST_PAIR_FMDN

static power_loss_recovery_state_t power_loss_recovery_state = POWER_LOSS_RECOVERY_IDLE;
static struct k_work_delayable power_loss_recovery_timeout_work;
static struct k_work_delayable power_loss_recovery_periodic_work;
static bool power_loss_recovery_periodic_active;
/* Tracks which PLR state the current merged FMDN adv set was created with.
 * This lets us force a stop+recreate only when intervals/options must change.
 */
static power_loss_recovery_state_t plr_state_applied_to_fmdn_adv = POWER_LOSS_RECOVERY_IDLE;
#endif

typedef enum {
	FP_MODE_ADV_SYNC_REASON_MODE_CHANGE,
	FP_MODE_ADV_SYNC_REASON_PLR_STATE_CHANGE,
	FP_MODE_ADV_SYNC_REASON_PLR_PERIODIC_TOGGLE,
} fp_mode_adv_sync_reason_t;

static void fp_mode_adv_sync(fp_mode_adv_sync_reason_t reason)
{
	/* In merged provisioned mode, FP advertising is not used for PLR periodic toggles.
	 * Keep it quiet by not submitting FP recreate work on every periodic tick.
	 */
	bool merged_provisioned =
		IS_ENABLED(CONFIG_FAST_PAIR_FMDN_MERGED_ADV) && fp_mode_is_provisioned();
	bool update_fp_adv = true;

#ifdef CONFIG_FAST_PAIR_FMDN
	bool update_fmdn_adv = true;
#endif

	if (reason == FP_MODE_ADV_SYNC_REASON_PLR_PERIODIC_TOGGLE) {
#ifdef CONFIG_FAST_PAIR_FMDN
		update_fmdn_adv = false;
#endif
		if (merged_provisioned) {
			update_fp_adv = false;
		}
	}

	if (update_fp_adv) {
		fp_adv_recreate();
	}

#ifdef CONFIG_FAST_PAIR_FMDN
	if (update_fmdn_adv) {
		bool force_fmdn_stop = false;

		/* In merged advertising, FMDN adv intervals depend on PLR state but are only
		 * applied when the adv set is (re)created.
		 */
		if (merged_provisioned &&
		    (reason == FP_MODE_ADV_SYNC_REASON_PLR_STATE_CHANGE ||
		     (plr_state_applied_to_fmdn_adv != power_loss_recovery_state))) {
			force_fmdn_stop = true;
		}

		fp_fmdn_adv_recreate(force_fmdn_stop, false);

		/* Only meaningful while provisioned; otherwise we'll stop anyway. */
		if (merged_provisioned) {
			plr_state_applied_to_fmdn_adv = power_loss_recovery_state;
		} else {
			plr_state_applied_to_fmdn_adv = POWER_LOSS_RECOVERY_IDLE;
		}
	}
#endif
}

void fp_mode_init(void)
{
	fp_mode_t update_mode;
	if (fp_storage_eid_key_valid()) {
		update_mode = FP_MODE_PROVISIONED;
	} else if (fp_storage_owner_key_valid()) {
		update_mode = FP_MODE_PAIRED;
	} else {
		update_mode = FP_MODE_NONE;
	}
	if (update_mode == FP_MODE_PAIRED) {
		LOG_INF("Update mode %u should not be happened, rollback to FP_MODE_NONE",
			update_mode);
		fp_storage_reset();
		update_mode = FP_MODE_NONE;
	}
#ifdef CONFIG_FAST_PAIR_FMDN
	/* FP_MODE_PROVISIONED here implies a real boot: CLEAR_EID_KEY always
	 * calls fp_storage_eid_reset() before fp_mode_init() is re-entered.
	 */
	if (update_mode == FP_MODE_PROVISIONED) {
		power_loss_recovery_state = POWER_LOSS_RECOVERY_IDLE;
		fp_mode_power_loss_recovery_start();
	}
#endif
	fp_mode_update(update_mode);
}

fp_mode_t fp_mode_get(void)
{
	return cur_mode;
}

void fp_mode_update(fp_mode_t mode)
{
	if (cur_mode != mode) {
		LOG_DBG("Update mode from %u to %u", cur_mode, mode);
		cur_mode = mode;
#ifdef CONFIG_FAST_PAIR_FMDN
		/* Stop power-loss recovery when unprovisioned */
		if (mode != FP_MODE_PROVISIONED) {
			fp_mode_power_loss_recovery_stop();
		}
#endif
		if (mode_switch_cb) {
			mode_switch_cb(mode);
		}
#ifdef CONFIG_FAST_PAIR_RECREATE_ADV_ON_MODE_SWITCH
		LOG_DBG("Update mode switch to %u to recreate adv immediately", cur_mode);
		fp_mode_adv_sync(FP_MODE_ADV_SYNC_REASON_MODE_CHANGE);
#endif
	}
}

bool fp_mode_is_provisioned(void)
{
#ifdef CONFIG_FAST_PAIR_FMDN
	return (cur_mode == FP_MODE_PROVISIONED);
#else
	return false;
#endif
}

bool fp_mode_is_paired(void)
{
	return (cur_mode == FP_MODE_PAIRED);
}

bool fp_mode_is_pairing(void)
{
	return ((cur_mode > FP_MODE_NONE) && (cur_mode < FP_MODE_PAIRED));
}

void fp_mode_switch_reg(fp_mode_switch_cb const hdlr)
{
	if (!mode_switch_cb) {
		mode_switch_cb = hdlr;
	}
}

uint16_t fp_mode_rpa_timeout(void)
{
#define FP_FMDN_ROTATE_PERIOD 1024
#define FP_RANDOM_FACTOR      204
#define FP_ROTATE_PERIOD      (15 * 60)
	// uint16_t rpa_timeout = fp_mode_is_provisioned() ? FP_FMDN_ROTATE_PERIOD :
	// FP_ROTATE_PERIOD; rpa_timeout += (sys_rand16_get() % FP_RANDOM_FACTOR) + 1;
	return (fp_mode_is_provisioned() ? FP_FMDN_ROTATE_PERIOD : FP_ROTATE_PERIOD) +
	       ((sys_rand16_get() % FP_RANDOM_FACTOR) + 1);
}

power_loss_recovery_state_t fp_mode_power_loss_recovery_state_get(void)
{
#ifdef CONFIG_FAST_PAIR_FMDN
	return power_loss_recovery_state;
#else
	return POWER_LOSS_RECOVERY_IDLE;
#endif
}

bool fp_mode_power_loss_recovery_required_adv(fp_mode_t mode)
{
#ifdef CONFIG_FAST_PAIR_FMDN
	if (mode == FP_MODE_PROVISIONED) {
		/* Advertising required in continuous mode or during periodic active phase */
		if (power_loss_recovery_state == POWER_LOSS_RECOVERY_CONTINUOUS) {
			return true;
		}
		if (power_loss_recovery_state == POWER_LOSS_RECOVERY_PERIODIC &&
		    power_loss_recovery_periodic_active) {
			return true;
		}
	}
#endif
	return false;
}

#if defined(CONFIG_ZTEST)
void fp_mode_test_adv_sync(void)
{
	fp_mode_adv_sync(FP_MODE_ADV_SYNC_REASON_MODE_CHANGE);
}

void fp_mode_test_adv_sync_plr_state(void)
{
	fp_mode_adv_sync(FP_MODE_ADV_SYNC_REASON_PLR_STATE_CHANGE);
}

void fp_mode_test_adv_sync_plr_periodic(void)
{
	fp_mode_adv_sync(FP_MODE_ADV_SYNC_REASON_PLR_PERIODIC_TOGGLE);
}
#endif /* CONFIG_ZTEST */

#ifdef CONFIG_FAST_PAIR_FMDN
static void power_loss_recovery_timeout_handler(struct k_work *work)
{
	ARG_UNUSED(work);

	if (power_loss_recovery_state != POWER_LOSS_RECOVERY_CONTINUOUS) {
		LOG_WRN("PLR timeout in unexpected state: %d", power_loss_recovery_state);
		return;
	}

	LOG_WRN("PLR: timeout, switch to periodic");
	power_loss_recovery_state = POWER_LOSS_RECOVERY_PERIODIC;

	/* Apply new advertising parameters for periodic mode (e.g., merged interval change). */
	fp_mode_adv_sync(FP_MODE_ADV_SYNC_REASON_PLR_STATE_CHANGE);

	k_work_schedule(&power_loss_recovery_periodic_work, K_NO_WAIT);
}

static void power_loss_recovery_periodic_handler(struct k_work *work)
{
	ARG_UNUSED(work);

	if (power_loss_recovery_state != POWER_LOSS_RECOVERY_PERIODIC) {
		LOG_WRN("PLR periodic in unexpected state: %d", power_loss_recovery_state);
		return;
	}

	if (!power_loss_recovery_periodic_active) {
		LOG_INF("PLR: start cycle (%ds)", CONFIG_FMDN_POWER_LOSS_PERIODIC_DURATION_SEC);
		power_loss_recovery_periodic_active = true;
		fp_mode_adv_sync(FP_MODE_ADV_SYNC_REASON_PLR_PERIODIC_TOGGLE);

		k_work_schedule(&power_loss_recovery_periodic_work,
				K_SECONDS(CONFIG_FMDN_POWER_LOSS_PERIODIC_DURATION_SEC));
	} else {
		LOG_INF("PLR: end cycle, next in %ds",
			CONFIG_FMDN_POWER_LOSS_PERIODIC_INTERVAL_SEC);
		power_loss_recovery_periodic_active = false;
		fp_mode_adv_sync(FP_MODE_ADV_SYNC_REASON_PLR_PERIODIC_TOGGLE);

		k_work_schedule(&power_loss_recovery_periodic_work,
				K_SECONDS(CONFIG_FMDN_POWER_LOSS_PERIODIC_INTERVAL_SEC));
	}
}

void fp_mode_power_loss_recovery_start(void)
{
	/* Only start once at boot - guard against multiple calls */
	if (power_loss_recovery_state != POWER_LOSS_RECOVERY_IDLE) {
		LOG_WRN("PLR already active: %d", power_loss_recovery_state);
		return;
	}

	LOG_INF("PLR: start continuous (%ds)", CONFIG_FMDN_POWER_LOSS_RECOVERY_TIMEOUT_SEC);

	k_work_init_delayable(&power_loss_recovery_timeout_work,
			      power_loss_recovery_timeout_handler);
	k_work_init_delayable(&power_loss_recovery_periodic_work,
			      power_loss_recovery_periodic_handler);

	power_loss_recovery_state = POWER_LOSS_RECOVERY_CONTINUOUS;
	power_loss_recovery_periodic_active = false;

	k_work_schedule(&power_loss_recovery_timeout_work,
			K_SECONDS(CONFIG_FMDN_POWER_LOSS_RECOVERY_TIMEOUT_SEC));

	/* Apply PLR continuous advertising policy when already provisioned.
	 * (On boot, fp_mode_update() will set cur_mode=PROVISIONED and trigger the
	 * first real advertising start, with PLR state already set.)
	 */
	if (fp_mode_is_provisioned()) {
		fp_mode_adv_sync(FP_MODE_ADV_SYNC_REASON_PLR_STATE_CHANGE);
	}
}

void fp_mode_power_loss_recovery_stop(void)
{
	if (power_loss_recovery_state == POWER_LOSS_RECOVERY_IDLE) {
		LOG_DBG("PLR already stopped");
		return;
	}

	LOG_INF("PLR: stop");

	k_work_cancel_delayable(&power_loss_recovery_timeout_work);
	k_work_cancel_delayable(&power_loss_recovery_periodic_work);

	power_loss_recovery_state = POWER_LOSS_RECOVERY_IDLE;
	power_loss_recovery_periodic_active = false;

	/* Apply non-PLR advertising policy (forces merged interval back to normal) */
	fp_mode_adv_sync(FP_MODE_ADV_SYNC_REASON_PLR_STATE_CHANGE);
}

bool fp_mode_power_loss_is_periodic(void)
{
	return (power_loss_recovery_state == POWER_LOSS_RECOVERY_PERIODIC &&
		power_loss_recovery_periodic_active);
}

#if defined(CONFIG_ZTEST)
void fp_mode_test_plr_start(void)
{
	fp_mode_power_loss_recovery_start();
}

void fp_mode_test_plr_stop(void)
{
	fp_mode_power_loss_recovery_stop();
}

bool fp_mode_test_plr_is_periodic(void)
{
	return fp_mode_power_loss_is_periodic();
}

void fp_mode_test_plr_timeout(void)
{
	power_loss_recovery_timeout_handler(NULL);
}

void fp_mode_test_plr_periodic(void)
{
	power_loss_recovery_periodic_handler(NULL);
}
#endif /* CONFIG_ZTEST */
#endif /* CONFIG_FAST_PAIR_FMDN */
