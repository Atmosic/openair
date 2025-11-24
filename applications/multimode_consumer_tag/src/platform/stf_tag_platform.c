/**
 *******************************************************************************
 *
 * @file stf_tag_platform.c
 *
 * @brief Platform For stf tag
 *
 * Copyright (C) Atmosic 2025
 *
 *******************************************************************************
 */

#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>

#include "stf_tag_platform.h"

LOG_MODULE_DECLARE(multimode_consumer_tag, CONFIG_MULTIMODE_CONSUMER_TAG_LOG_LEVEL);

#ifdef CONFIG_ATM_STF_MULTI_MODE
static tag_state_notify_cb stf_tag_state_notify_cb;

static void stf_tag_state_notify(stf_state_notify_t state)
{
	LOG_INF("STF current state %u", state);
	tag_state_t tag_st = TAG_STATE_INVALID;

	switch (state) {
	// upair stf tag will invoke system reboot, so no need to handle unpair state
	case STF_STATE_INIT_DONE:
		tag_st = TAG_STATE_INIT_DONE;
		break;
	case STF_STATE_ONBOARDING_START:
		tag_st = TAG_STATE_PAIRING;
		break;
	case STF_STATE_ONBOARDING_COMPLETE:
		tag_st = TAG_STATE_PAIRED;
		break;
	default:
		LOG_WRN("STF current state %u not handled", state);
		break;
	}

	if (stf_tag_state_notify_cb) {
		stf_tag_state_notify_cb(tag_st, TAG_TYPE_STF);
	}
}
#endif

static void stf_tag_platform_init(tag_state_notify_cb fn_cb)
{
	LOG_INF("STF init");
#ifdef CONFIG_ATM_STF_MULTI_MODE
	stf_tag_state_notify_cb = fn_cb;
	TagSetStateNotify(stf_tag_state_notify);
#endif
	// Adv will start automatically after TagStart() when CONFIG_ATM_STF_MULTI_MODE=n
	TagStart();
}

static void stf_tag_platform_reset(void)
{
	LOG_INF("STF reset");
	TagCleanup();
}

#ifdef CONFIG_ATM_STF_MULTI_MODE
static void stf_tag_platform_start(void)
{
	static bool is_first_start = true;
	if (is_first_start) {
		is_first_start = false;
		LOG_INF("STF start adv");
		TagStartAdv();
	} else {
		LOG_INF("STF resume adv");
		TagResumeAdv();
	}
}

static void stf_tag_platform_stop(void)
{
	LOG_INF("STF stop adv");
	TagPauseAdv();
}

static bool stf_tag_platform_is_paired(void)
{
	bool is_paired = TagIsPaired();
	LOG_INF("STF is paired %d", is_paired);
	return is_paired;
}
#endif

void stf_tag_platform_hdlrs_get(tag_hdlrs_t *hdlrs)
{
	hdlrs->init = stf_tag_platform_init;
	hdlrs->reset = stf_tag_platform_reset;
#ifdef CONFIG_ATM_STF_MULTI_MODE
	hdlrs->start = stf_tag_platform_start;
	hdlrs->stop = stf_tag_platform_stop;
	hdlrs->is_paired = stf_tag_platform_is_paired;
#endif
}
