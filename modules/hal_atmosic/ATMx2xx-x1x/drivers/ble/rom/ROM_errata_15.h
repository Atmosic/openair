/**
 *******************************************************************************
 *
 * @file ROM_errata_15.h
 *
 * @brief ROM_errata #15
 *
 *  ROM errata for CEVA_CASE_13119. It is only allowed using from
 *  ROM_errata_14.c
 *
 * Copyright (C) Atmosic 2021 - 2022
 *
 *******************************************************************************
 */
#pragma once

#define LLD_CON_SCHED(type, el, sl, instant, con_evt, link_id, clock) do { \
    if ((type == 1) && el && sl && (sl >= (instant - con_evt - 1)) && \
	(instant - con_evt >= 2)) { \
	uint16_t backup = sl; \
	/* Prevent updating the parameters when con_evt is beyond last */ \
	/* anchor. Don't need this when in last anchor before instant. */ \
	sl = instant - con_evt - 2; \
	lld_con_sched(link_id, clock, true); \
	sl = backup; \
    } else { \
	lld_con_sched(link_id, clock, el); \
    } \
} while (0)
