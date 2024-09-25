/**
 ******************************************************************************
 *
 * @file pmu_cfg.h
 *
 * @brief Power Management Unit driver configuration
 *
 * Copyright (C) Atmosic 2024
 *
 ******************************************************************************
 */

#pragma once

/**
 * @defgroup PMU PMU
 * @ingroup DRIVERS
 * @brief Power Management driver configuration
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef CONFIG_SOC_FAMILY_ATM
#if DT_NODE_HAS_PROP(DT_NODELABEL(pmu), batt_type)
#define BATT_TYPE DT_PROP(DT_NODELABEL(pmu), batt_type)
#endif

#if DT_NODE_HAS_PROP(DT_NODELABEL(pmu), batt_level)
#define BATT_LEVEL DT_PROP(DT_NODELABEL(pmu), batt_level)
#endif

#if DT_NODE_HAS_PROP(DT_NODELABEL(pmu), vddpa_src)
#define VDDPA_SRC DT_PROP(DT_NODELABEL(pmu), vddpa_src)
#endif

#if DT_PROP(DT_NODELABEL(pmu), boost_from_vharv_two_diode)
#define BOOST_FROM_VHARV_TWO_DIODE
#endif

#if DT_PROP(DT_NODELABEL(pmu), boost_from_vharv_inductor)
#define BOOST_FROM_VHARV_INDUCTOR
#endif

#ifdef CONFIG_BATT_MODEL_HSC
#define BATT_MODEL_HSC
#endif
#endif // CONFIG_SOC_FAMILY_ATM

#ifndef BATT_TYPE
#define BATT_TYPE BATT_TYPE_NON_RECHARGEABLE
#endif

#ifndef BATT_LEVEL
#define BATT_LEVEL BATT_LEVEL_GT_1P8V
#endif

#ifndef VDDPA_SRC
#define VDDPA_SRC VDDPA_SRC_VDDIOP
#endif

#ifdef __cplusplus
}
#endif

/// @} PMU
