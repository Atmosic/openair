
/*
 * Copyright (c) 2023-2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#define DT_DRV_COMPAT atmosic_atm34_adc

#include <zephyr/logging/log.h>
LOG_MODULE_REGISTER(adc_atm, CONFIG_ADC_LOG_LEVEL);

#include <zephyr/drivers/adc.h>
#include <soc.h>
#include <errno.h>
#include <assert.h>
#include <string.h>
#include <math.h>
#include <inttypes.h>
#ifdef CONFIG_PM
#include <zephyr/pm/pm.h>
#include <zephyr/pm/policy.h>
#endif

#define ADC_CONTEXT_USES_KERNEL_TIMER
#include "adc_context.h"

#include "arch.h"
#include "at_wrpr.h"
#include "at_apb_pseq_regs_core_macro.h"
#include "at_apb_gadc_regs_core_macro.h"
#include "calibration.h"
#include "ll.h"
#ifdef DGADC_CTRL1__RTRIM_IC__WRITE
#include "spi.h"
#include "pmu_spi.h"
#include "pmu_top_regs_core_macro.h"
#include "pmu_swreg_regs_core_macro.h"
#include "pmu_gadc_regs_core_macro.h"
#endif
#include "timer.h"
#include "sec_jrnl.h"
#include "atm_adc.h"
#include "atm_adc_capture.h"

#define Z_CMSDK_GADC CMSDK_GADC

/* GADC internal reference voltage (Unit:mV) */
#define ATM_GADC_VREF_VOL 600

#define GADC_MOD_SELECT    0
#define GADC_WARMUP_CYCLES 3
#define GADC_WAIT_AMOUNT   40

/* VBATT on-chip sense divider: VBATT is scaled by 1/6 before reaching the ADC input */
#define GADC_VBATT_SENSE_DIV           6
/* ADC positive full-scale: 15-bit range within the 16-bit signed FIFO output (2^15) */
#define GADC_ADC_FULL_SCALE            32768
/* OTP gain_vbat1: Q0.16 slope in mV_VBAT/LSB (absorbs the 1/6 sense divider + Vref) */
#define GADC_CAL_VBAT_FRAC_BITS        16
/* OTP offset_vbat1: s12.4 y-intercept in mV_VBAT; shift by 4 to recover integer mV */
#define GADC_CAL_VBAT_OFFSET_FRAC_BITS 4
/* No-OTP fallback: ideal slope = SENSE_DIV * Vref_mV * 2^16 / FULL_SCALE = 7200 */
#define GADC_CAL_VBAT_GAIN_UNITY                                                                   \
	((uint16_t)((GADC_VBATT_SENSE_DIV * ATM_GADC_VREF_VOL *                                    \
		     (1UL << GADC_CAL_VBAT_FRAC_BITS)) /                                           \
		    GADC_ADC_FULL_SCALE))
/* OTP gain_temp0 is U-6.22 fixed-point (22 fractional bits); units: degC/LSB */
#define GADC_CAL_TEMP_FRAC_BITS 22
/* temperature gain (no OTP) */
#define GADC_CAL_TEMP_GAIN_NOM   47384U
/* temperature offset (no OTP); +256 degC biased, hence negative */
#define GADC_CAL_TEMP_OFFSET_NOM (-3613)

/* Enumeration of GADC channels in SoC */
typedef enum {
	WATCH_CH_INVALID = 0,
	WATCH_CH_VBATT = 1,
	WATCH_CH_VSTORE = 2,
	WATCH_CH_CORE = 3,
	WATCH_CH_TEMP = 4,
	WATCH_CH_PORT1_DIFF = 5,
	WATCH_CH_PORT0_DIFF = 6,
	WATCH_CH_PORT1_SINGLE_POS = 7,
	WATCH_CH_PORT1_SINGLE_NEG = 8,
	WATCH_CH_PORT0_SINGLE_POS = 9,
	WATCH_CH_PORT0_SINGLE_NEG = 10,
	WATCH_CH_LI_ION_BATT = 11,
	WATCH_CH_CALIBRATION = 13,
} GADC_WATCH_CHANNEL;

/** List of GADC channels */
typedef enum {
	UNUSED = 0,
	/** VBAT channel */
	VBATT = 1,
#ifdef DGADC_CTRL1__RTRIM_IC__WRITE
	/** VSTORE channel */
	VSTORE = 2,
	/** VDD1A channel */
	CORE = 3,
#endif
	/** Temperature channel */
	TEMP = 4,
#ifdef DGADC_CTRL1__RTRIM_IC__WRITE
	/// P4/P5 differential channel.
	PORT1_DIFFERENTIAL = 5,
	/// P6/P7 differential channel.
	PORT0_DIFFERENTIAL = 6,
	/// P4 single-ended channel.
	PORT1_SINGLE_ENDED_0 = 7,
	/// P5 single-ended channel.
	PORT1_SINGLE_ENDED_1 = 8,
	/// P6 single-ended channel.
	PORT0_SINGLE_ENDED_0 = 9,
	/// P7 single-ended channel.
	PORT0_SINGLE_ENDED_1 = 10,
	/// Li-ion channel.
	LI_ION_BATT = 11,
#ifdef GADC_GADC_CTRL__EXT_VDD1_SEL__SET
	// P3 single-ended channel
	PORT2_SINGLE_ENDED,
	// P8 single-ended channel
	PORT3_SINGLE_ENDED,
	// P9 single-ended channel
	PORT4_SINGLE_ENDED,
#endif
	// Calibration - for internal use only
	CALIBRATION,
#endif /* DGADC_CTRL1__RTRIM_IC__WRITE */
	/** Max channels */
	CHANNEL_NUM_MAX,
} GADC_CHANNEL_ID;
#define CHANNEL_NUM_MAX_USER (CHANNEL_NUM_MAX - 1)

#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
/// FIFO data type
struct gadc_fifo_s {
	union {
		/// 32 bits data which represents full FIFO value
		uint32_t value;
		/// Decomposition structure.
		struct {
			/// Sample part of FIFO data
			signed int sample: 16;
			/// Channel used for the FIFO
			unsigned int channel: 4;
			/// Remaining 12 bits are zero from mask before assignment
		};
	};
};
#else
#error "Unsupported endianness"
#endif

struct gadc_atm_data {
	struct device const *dev;
	struct adc_context ctx;
	/** Current channel */
	uint32_t ch;
	/** Pending mask */
	uint32_t chmask;
	/** Active channels */
	size_t active_channels;
	/** Current results */
	int32_t *buffer;
	/** Offset for the active channels */
	uint8_t offset[CHANNEL_NUM_MAX];
};
#define DEV_DATA(dev) ((struct gadc_atm_data *)(dev)->data)

static uint32_t chan_setup_mask;

typedef enum {
	GAIN_EXT_X1,
	GAIN_EXT_HALF,
	GAIN_EXT_QUARTER,
	GAIN_EXT_EIGHTH,
	GAIN_EXT_END,
	GAIN_EXT_MAX,
} gadc_gain_ext_t;

static uint16_t gcal_len;

#ifdef CONFIG_ATM_ADC_CAL_TEST_HOOKS
static bool gcal_test_no_tag;
#endif

#ifndef DGADC_CTRL1__RTRIM_IC__WRITE
static hw_cfg_cal_data_t gcal;
#else  /* !DGADC_CTRL1__RTRIM_IC__WRITE */
static struct gadc_cal_s gcal;
static struct chip_info_s chipinfo;
static uint16_t chipinfo_len;

static uint32_t calts[GAIN_EXT_END];
static bool firstcal[GAIN_EXT_END];
#endif /* DGADC_CTRL1__RTRIM_IC__WRITE */

static gadc_gain_ext_t gext[CHANNEL_NUM_MAX];
static gadc_gain_ext_t const gextmap[CHANNEL_NUM_MAX][GAIN_EXT_MAX] = {
	{GAIN_EXT_END}, // unused, invalid channel
#ifdef CONFIG_ATM_ADC_UNITY_GAIN
	{GAIN_EXT_X1, GAIN_EXT_END},
	{GAIN_EXT_X1, GAIN_EXT_END},
	{GAIN_EXT_X1, GAIN_EXT_END},
	{GAIN_EXT_X1, GAIN_EXT_END},
	{GAIN_EXT_X1, GAIN_EXT_END},
	{GAIN_EXT_X1, GAIN_EXT_END},
	{GAIN_EXT_X1, GAIN_EXT_END},
	{GAIN_EXT_X1, GAIN_EXT_END},
	{GAIN_EXT_X1, GAIN_EXT_END},
	{GAIN_EXT_X1, GAIN_EXT_END},
	{GAIN_EXT_X1, GAIN_EXT_END},
#else /* CONFIG_ATM_ADC_UNITY_GAIN */
#ifdef DGADC_CTRL1__RTRIM_IC__WRITE
	{GAIN_EXT_EIGHTH, GAIN_EXT_QUARTER, GAIN_EXT_END},
	{GAIN_EXT_EIGHTH, GAIN_EXT_QUARTER, GAIN_EXT_END},
	{GAIN_EXT_HALF, GAIN_EXT_END},
#else
	{GAIN_EXT_X1, GAIN_EXT_END},
	{GAIN_EXT_END}, // unused, invalid channel
	{GAIN_EXT_END}, // unused, invalid channel
#endif
	{GAIN_EXT_X1, GAIN_EXT_END},
#ifdef DGADC_CTRL1__RTRIM_IC__WRITE
	{GAIN_EXT_QUARTER, GAIN_EXT_HALF, GAIN_EXT_X1, GAIN_EXT_END},
	{GAIN_EXT_QUARTER, GAIN_EXT_HALF, GAIN_EXT_X1, GAIN_EXT_END},
	{GAIN_EXT_QUARTER, GAIN_EXT_HALF, GAIN_EXT_X1, GAIN_EXT_END},
	{GAIN_EXT_QUARTER, GAIN_EXT_HALF, GAIN_EXT_X1, GAIN_EXT_END},
	{GAIN_EXT_QUARTER, GAIN_EXT_HALF, GAIN_EXT_X1, GAIN_EXT_END},
	{GAIN_EXT_QUARTER, GAIN_EXT_HALF, GAIN_EXT_X1, GAIN_EXT_END},
	{GAIN_EXT_HALF, GAIN_EXT_X1, GAIN_EXT_END},
#ifdef GADC_GADC_CTRL__EXT_VDD1_SEL__SET
	{GAIN_EXT_QUARTER, GAIN_EXT_HALF, GAIN_EXT_X1, GAIN_EXT_END},
	{GAIN_EXT_QUARTER, GAIN_EXT_HALF, GAIN_EXT_X1, GAIN_EXT_END},
	{GAIN_EXT_QUARTER, GAIN_EXT_HALF, GAIN_EXT_X1, GAIN_EXT_END},
#endif
	{GAIN_EXT_EIGHTH, GAIN_EXT_QUARTER, GAIN_EXT_HALF, GAIN_EXT_X1, GAIN_EXT_END},
#endif /* DGADC_CTRL1__RTRIM_IC__WRITE */
#endif /* CONFIG_ATM_ADC_UNITY_GAIN */
};

/* Per-channel sample-avg values from DT, indexed by channel reg (GADC_CHANNEL_ID).
 * All channels are pre-filled with the top-level sample-avg (or 0 if absent).
 * DT_FOREACH_CHILD overrides only nodes explicitly declared as children of adc.
 */
#define GADC_CH_SAVG_INIT(node)                                                                    \
	[DT_REG_ADDR(node)] =                                                                      \
		DT_PROP_OR(node, sample_avg, DT_PROP_OR(DT_NODELABEL(adc), sample_avg, 0)),

static const uint8_t ch_savg[CHANNEL_NUM_MAX] = {
	[0 ... CHANNEL_NUM_MAX - 1] = DT_PROP_OR(DT_NODELABEL(adc), sample_avg, 0),
	DT_FOREACH_CHILD(DT_NODELABEL(adc), GADC_CH_SAVG_INIT)};

static void adc_context_update_buffer_pointer(struct adc_context *ctx, bool repeat)
{
	struct gadc_atm_data *data = CONTAINER_OF(ctx, struct gadc_atm_data, ctx);

	if (!repeat) {
		data->buffer += data->active_channels;
	}
}

/* Read GADC FIFO  and return channel measurement data */
static struct gadc_fifo_s gadc_read_ch_data(void)
{
	uint32_t data_output = Z_CMSDK_GADC->DATAPATH_OUTPUT;
	struct gadc_fifo_s gadc_data = {
		.value = DGADC_DATAPATH_OUTPUT__DATA__READ(data_output),
	};

	return gadc_data;
}

/* Enable/Disable GADC analog side */
__STATIC_FORCEINLINE void gadc_analog_control(bool enable, GADC_CHANNEL_ID ch)
{
#ifdef DGADC_CONFIG__GADC_EN__WRITE
	if (enable) {
		Z_CMSDK_GADC->CONFIG =
			DGADC_CONFIG__GADC_RSTB__WRITE(1) | DGADC_CONFIG__GADC_EN__WRITE(1);
		atm_timer_lpc_delay(2);
	} else {
		Z_CMSDK_GADC->CONFIG = 0;
	}
#else
	WRPR_CTRL_PUSH(CMSDK_PSEQ, WRPR_CTRL__CLK_ENABLE)
	{
		CMSDK_PSEQ->GADC_CONFIG = PSEQ_GADC_CONFIG__GADC_CUTVDD_B__MASK;
		if (enable) {
			/* Turn on GADC analog side */
			CMSDK_PSEQ->GADC_CONFIG = PSEQ_GADC_CONFIG__WRITE;
			// This delay was suggested by analog
			atm_timer_lpc_delay(2);
		} else {
			/* Turn off GADC analog side */
			CMSDK_PSEQ->GADC_CONFIG = 0;
		}
	}
	WRPR_CTRL_POP();
#endif

#ifdef GADC_GADC_CTRL__EXT_VDD1_SEL__SET
	if (enable) {
		WRPR_CTRL_PUSH(CMSDK_PMU, WRPR_CTRL__CLK_ENABLE)
		{
			uint32_t gadc_ctrl = PMU_GADC_READ(GADC_CTRL_REG_ADDR);
			if (ch == PORT2_SINGLE_ENDED) {
				GADC_GADC_CTRL__EXT_VDD1_SEL__SET(gadc_ctrl);
			} else if (ch == PORT3_SINGLE_ENDED) {
				GADC_GADC_CTRL__EXT_VSTOR_SEL__SET(gadc_ctrl);
			} else if (ch == PORT4_SINGLE_ENDED) {
				GADC_GADC_CTRL__EXT_VBAT_SEL__SET(gadc_ctrl);
			}
#ifdef CONFIG_ATM_ADC_UNITY_GAIN
			GADC_GADC_CTRL__PGA_EN__CLR(gadc_ctrl);
			GADC_GADC_CTRL__BYPASS_PGA__SET(gadc_ctrl);
#endif
			PMU_GADC_WRITE(GADC_CTRL_REG_ADDR, gadc_ctrl);
		}
		WRPR_CTRL_POP();
	}
#endif
}

#ifdef DGADC_CTRL1__RTRIM_IC__WRITE
static void gadc_apply_calibration(void)
{
	if (CAL_PRESENT(gcal, offset_comp3)) {
		Z_CMSDK_GADC->CTRL1 = gcal.ctrl1;
		Z_CMSDK_GADC->GAIN_COMP2 = gcal.gain_comp2;
		Z_CMSDK_GADC->GAIN_COMP3 = gcal.gain_comp3;
		Z_CMSDK_GADC->OFFSET_COMP0 = gcal.offset_comp0;
		Z_CMSDK_GADC->OFFSET_COMP1 = gcal.offset_comp1;
		Z_CMSDK_GADC->OFFSET_COMP2 = gcal.offset_comp2;
		Z_CMSDK_GADC->OFFSET_COMP3 = gcal.offset_comp3;
	}
}
#else
static int32_t gadc_atm_apply_cal(uint32_t raw, uint8_t ch)
{
	switch (ch) {
	case VBATT: {
		/*
		 * OTP format:
		 *   gain_vbat1  : U0.16 slope in mV_VBAT/LSB
		 *   offset_vbat1: S12.4 y-intercept in mV_VBAT
		 *
		 * Zephyr adaptation: return fake_raw so that
		 *   fake_raw * Vref / FULL_SCALE == vbatt_mv.
		 * Compute in Q16 with round-to-nearest (carry-in method):
		 *   prod_q16 = raw * gain_vbat1 + offset_vbat1 * 2^12   [Q16 mV]
		 *   carry    = bit 15 of prod_q16                        [round bit]
		 *   vbatt_mv = (prod_q16 >> 16) + carry                  [integer mV]
		 *   fake_raw = vbatt_mv * FULL_SCALE / Vref
		 */
		uint16_t gain = gcal_len ? gcal.gain_vbat1 : GADC_CAL_VBAT_GAIN_UNITY;
		int16_t offset = gcal_len ? gcal.offset_vbat1 : 0;
		int32_t prod_q16 = (int32_t)(raw * gain) +
				   ((int32_t)offset
				    << (GADC_CAL_VBAT_FRAC_BITS - GADC_CAL_VBAT_OFFSET_FRAC_BITS));
		int32_t carry = (prod_q16 >> (GADC_CAL_VBAT_FRAC_BITS - 1)) & 1;
		int32_t vbatt_mv = (prod_q16 >> GADC_CAL_VBAT_FRAC_BITS) + carry;
		return vbatt_mv * GADC_ADC_FULL_SCALE / ATM_GADC_VREF_VOL;
	}
	case TEMP: {
		/*
		 * OTP format:
		 *   gain_temp0  : U-6.22 slope in degC/LSB
		 *   offset_temp0: S8.8   y-intercept in degC, biased by +256 degC (ATE
		 *                 uses the same bias); the un-biased PTAT intercept is
		 *                 ~-273 degC, so the stored value is normally negative
		 *
		 * Compute in Q22 with round-to-nearest (carry-in method):
		 *   prod_q22 = raw * gain_temp0 + offset_temp0 * 2^14 - 256 * 2^22  [Q22 degC]
		 *   carry    = bit 13 of prod_q22                                   [round bit]
		 *   result   = (prod_q22 >> 14) + carry                             [S8.8 degC]
		 */
		uint16_t gain = gcal_len ? gcal.gain_temp0 : GADC_CAL_TEMP_GAIN_NOM;
		int16_t offset = gcal_len ? gcal.offset_temp0 : GADC_CAL_TEMP_OFFSET_NOM;
		/* sensor output is positive; clamp faults that would underflow below */
		int32_t sample = (int32_t)raw > 0 ? (int32_t)raw : 0;
		int32_t prod_q22 = sample * (int32_t)gain +
				   ((int32_t)offset << (GADC_CAL_TEMP_FRAC_BITS - 8)) -
				   (256 << GADC_CAL_TEMP_FRAC_BITS);
		int32_t carry = (prod_q22 >> (GADC_CAL_TEMP_FRAC_BITS - 8 - 1)) & 1;
		return (prod_q22 >> (GADC_CAL_TEMP_FRAC_BITS - 8)) + carry;
	}
	default:
		return (int32_t)raw;
	}
}
#endif

// Set the gain and return the watch channel for the specified channel
static GADC_WATCH_CHANNEL gadc_select_channel(GADC_CHANNEL_ID ch)
{
	GADC_WATCH_CHANNEL watch_ch;
	switch (ch) {
	case VBATT: {
		watch_ch = WATCH_CH_VBATT;
		DGADC_GAIN_CONFIG0__CH1_GAIN_SEL__MODIFY(Z_CMSDK_GADC->GAIN_CONFIG0, gext[ch]);
	} break;
#ifdef DGADC_CTRL1__RTRIM_IC__WRITE
	case VSTORE: {
		watch_ch = WATCH_CH_VSTORE;
		DGADC_GAIN_CONFIG0__CH2_GAIN_SEL__MODIFY(Z_CMSDK_GADC->GAIN_CONFIG0, gext[ch]);
	} break;
	case CORE: {
		watch_ch = WATCH_CH_CORE;
		DGADC_GAIN_CONFIG0__CH3_GAIN_SEL__MODIFY(Z_CMSDK_GADC->GAIN_CONFIG0, gext[ch]);
	} break;
#endif
	case TEMP: {
		watch_ch = WATCH_CH_TEMP;
		DGADC_GAIN_CONFIG0__CH4_GAIN_SEL__MODIFY(Z_CMSDK_GADC->GAIN_CONFIG0, gext[ch]);
	} break;
#ifdef DGADC_CTRL1__RTRIM_IC__WRITE
	case PORT1_DIFFERENTIAL: {
		watch_ch = WATCH_CH_PORT1_DIFF;
#ifdef DGADC_GAIN_CONFIG1__CH5_GAIN_SEL__MODIFY
		DGADC_GAIN_CONFIG1__CH5_GAIN_SEL__MODIFY(Z_CMSDK_GADC->GAIN_CONFIG1, gext[ch]);
#else
		DGADC_GAIN_CONFIG0__CH5_GAIN_SEL__MODIFY(Z_CMSDK_GADC->GAIN_CONFIG0, gext[ch]);
#endif
	} break;
	case PORT0_DIFFERENTIAL: {
		watch_ch = WATCH_CH_PORT0_DIFF;
#ifdef DGADC_GAIN_CONFIG1__CH6_GAIN_SEL__MODIFY
		DGADC_GAIN_CONFIG1__CH6_GAIN_SEL__MODIFY(Z_CMSDK_GADC->GAIN_CONFIG1, gext[ch]);
#else
		DGADC_GAIN_CONFIG0__CH6_GAIN_SEL__MODIFY(Z_CMSDK_GADC->GAIN_CONFIG0, gext[ch]);
#endif
	} break;
	case PORT1_SINGLE_ENDED_0: {
		watch_ch = WATCH_CH_PORT1_SINGLE_POS;
#ifdef DGADC_GAIN_CONFIG1__CH7_GAIN_SEL__MODIFY
		DGADC_GAIN_CONFIG1__CH7_GAIN_SEL__MODIFY(Z_CMSDK_GADC->GAIN_CONFIG1, gext[ch]);
#else
		DGADC_GAIN_CONFIG0__CH7_GAIN_SEL__MODIFY(Z_CMSDK_GADC->GAIN_CONFIG0, gext[ch]);
#endif
	} break;
	case PORT1_SINGLE_ENDED_1: {
		watch_ch = WATCH_CH_PORT1_SINGLE_NEG;
#ifdef DGADC_GAIN_CONFIG1__CH8_GAIN_SEL__MODIFY
		DGADC_GAIN_CONFIG1__CH8_GAIN_SEL__MODIFY(Z_CMSDK_GADC->GAIN_CONFIG1, gext[ch]);
#else
		DGADC_GAIN_CONFIG0__CH8_GAIN_SEL__MODIFY(Z_CMSDK_GADC->GAIN_CONFIG0, gext[ch]);
#endif
	} break;
	case PORT0_SINGLE_ENDED_0: {
		watch_ch = WATCH_CH_PORT0_SINGLE_POS;
#ifdef DGADC_GAIN_CONFIG2__CH9_GAIN_SEL__MODIFY
		DGADC_GAIN_CONFIG2__CH9_GAIN_SEL__MODIFY(Z_CMSDK_GADC->GAIN_CONFIG2, gext[ch]);
#else
		DGADC_GAIN_CONFIG0__CH9_GAIN_SEL__MODIFY(Z_CMSDK_GADC->GAIN_CONFIG0, gext[ch]);
#endif
	} break;
	case PORT0_SINGLE_ENDED_1: {
		watch_ch = WATCH_CH_PORT0_SINGLE_NEG;
#ifdef DGADC_GAIN_CONFIG2__CH10_GAIN_SEL__MODIFY
		DGADC_GAIN_CONFIG2__CH10_GAIN_SEL__MODIFY(Z_CMSDK_GADC->GAIN_CONFIG2, gext[ch]);
#else
		DGADC_GAIN_CONFIG0__CH10_GAIN_SEL__MODIFY(Z_CMSDK_GADC->GAIN_CONFIG0, gext[ch]);
#endif
	} break;
	case LI_ION_BATT: {
		watch_ch = WATCH_CH_LI_ION_BATT;
#ifdef DGADC_GAIN_CONFIG2__CH11_GAIN_SEL__MODIFY
		DGADC_GAIN_CONFIG2__CH11_GAIN_SEL__MODIFY(Z_CMSDK_GADC->GAIN_CONFIG2, gext[ch]);
#else
		DGADC_GAIN_CONFIG1__CH11_GAIN_SEL__MODIFY(Z_CMSDK_GADC->GAIN_CONFIG1, gext[ch]);
#endif
	} break;
	case CALIBRATION: {
		watch_ch = WATCH_CH_CALIBRATION;
#ifdef DGADC_GAIN_CONFIG2__CH12_GAIN_SEL__MODIFY
		DGADC_GAIN_CONFIG2__CH12_GAIN_SEL__MODIFY(Z_CMSDK_GADC->GAIN_CONFIG2, gext[ch]);
#else
		DGADC_GAIN_CONFIG1__CH12_GAIN_SEL__MODIFY(Z_CMSDK_GADC->GAIN_CONFIG1, gext[ch]);
#endif
	} break;
#ifdef GADC_GADC_CTRL__EXT_VDD1_SEL__SET
	case PORT2_SINGLE_ENDED: {
		watch_ch = WATCH_CH_CORE;
		DGADC_GAIN_CONFIG0__CH3_GAIN_SEL__MODIFY(Z_CMSDK_GADC->GAIN_CONFIG0, gext[ch]);
	} break;
	case PORT3_SINGLE_ENDED: {
		watch_ch = WATCH_CH_VSTORE;
		DGADC_GAIN_CONFIG0__CH2_GAIN_SEL__MODIFY(Z_CMSDK_GADC->GAIN_CONFIG0, gext[ch]);
	} break;
	case PORT4_SINGLE_ENDED: {
		watch_ch = WATCH_CH_VBATT;
		DGADC_GAIN_CONFIG0__CH1_GAIN_SEL__MODIFY(Z_CMSDK_GADC->GAIN_CONFIG0, gext[ch]);
	} break;
#endif
#endif /* DGADC_CTRL1__RTRIM_IC__WRITE */
	case UNUSED:
	case CHANNEL_NUM_MAX:
	default: {
		watch_ch = WATCH_CH_INVALID;
		LOG_ERR("Invalid channel: %d", ch);
		ASSERT_ERR(0);
	} break;
	}

	return watch_ch;
}

static void gadc_start_measurement(struct device const *dev, GADC_CHANNEL_ID ch)
{
	WRPR_CTRL_SET(Z_CMSDK_GADC, WRPR_CTRL__CLK_ENABLE | WRPR_CTRL__CLK_SEL);
#ifdef DGADC_CTRL1__RTRIM_IC__WRITE
	gadc_apply_calibration();
#endif
	gadc_analog_control(true, ch);
	irq_enable(DT_INST_IRQN(0));
	Z_CMSDK_GADC->INTERRUPT_MASK = 0;
	Z_CMSDK_GADC->INTERRUPT_CLEAR = DGADC_INTERRUPT_CLEAR__WRITE;

	GADC_WATCH_CHANNEL watch_ch = gadc_select_channel(ch);
	uint8_t clkdiv = DT_PROP(DT_NODELABEL(adc), clock_freq);
#ifdef DGADC_CTRL1__RTRIM_IC__WRITE
	if (ch == TEMP) {
#define GADC_CLK_1MHZ 3
		clkdiv = GADC_CLK_1MHZ;
	} else if (ch == LI_ION_BATT) {
		WRPR_CTRL_PUSH(CMSDK_PMU, WRPR_CTRL__CLK_ENABLE)
		{
			uint32_t gadc_ctrl = PMU_READ(GADC, GADC_CTRL_REG_ADDR);
			GADC_GADC_CTRL__LI_EN__SET(gadc_ctrl);
			PMU_WRITE(GADC, GADC_CTRL_REG_ADDR, gadc_ctrl);
		}
		WRPR_CTRL_POP();
	}
#endif

	Z_CMSDK_GADC->CTRL = DGADC_CTRL__WATCH_CHANNELS__WRITE(1 << watch_ch) |
			     DGADC_CTRL__AVERAGING_AMOUNT__WRITE(ch_savg[ch]) |
			     DGADC_CTRL__WAIT_AMOUNT__WRITE(GADC_WAIT_AMOUNT) |
			     DGADC_CTRL__CLKDIV__WRITE(clkdiv) |
			     DGADC_CTRL__WARMUP__WRITE(GADC_WARMUP_CYCLES) |
			     DGADC_CTRL__MODE__WRITE(1); // One Shot Mode

	uint8_t osrsel = DT_PROP(DT_NODELABEL(adc), osr_select);
	DGADC_CTRL1__OSR_SEL__MODIFY(Z_CMSDK_GADC->CTRL1, osrsel);
	DGADC_CTRL1__MOD_SEL__MODIFY(Z_CMSDK_GADC->CTRL1, GADC_MOD_SELECT);

	// Flush old FIFO values
	while (!(Z_CMSDK_GADC->DATAPATH_OUTPUT & DGADC_DATAPATH_OUTPUT__EMPTY__MASK)) {
		YIELD();
	}

	/* Unmask only INTRPT2 (measurement done) before triggering conversion */
	Z_CMSDK_GADC->INTERRUPT_MASK = DGADC_INTERRUPT_MASK__MASK_INTRPT2__MASK;
	DGADC_CTRL__ENABLE_DP__SET(Z_CMSDK_GADC->CTRL);
}

#ifdef DGADC_CTRL1__RTRIM_IC__WRITE
static void gadc_calibrate_offset(gadc_gain_ext_t gainext, int32_t sample)
{
	int32_t result = -sample;
	LOG_DBG("%s: %u %d", __func__, gainext, result);
	switch (gainext) {
	case GAIN_EXT_X1:
		gcal.offset_comp0 = DGADC_OFFSET_COMP0__OFFSET__WRITE(result);
		break;
	case GAIN_EXT_HALF:
		gcal.offset_comp1 = DGADC_OFFSET_COMP1__OFFSET__WRITE(result);
		break;
	case GAIN_EXT_QUARTER:
		gcal.offset_comp2 = DGADC_OFFSET_COMP2__OFFSET__WRITE(result);
		break;
	case GAIN_EXT_EIGHTH:
		gcal.offset_comp3 = DGADC_OFFSET_COMP3__OFFSET__WRITE(result);
		break;
	default:
		LOG_ERR("Invalid gext: %d", gainext);
		break;
	}
}
#endif

static void gadc_measure_or_calibrate(struct gadc_atm_data *data)
{
#if defined(DGADC_CTRL1__RTRIM_IC__WRITE) && !CONFIG_ATM_ADC_UNITY_GAIN
	uint32_t curts = atm_lpc_to_ms(atm_get_sys_time());
	if (firstcal[gext[data->ch]] ||
	    ((curts - calts[gext[data->ch]]) > CONFIG_ADC_CAL_REFRESH_INTERVAL)) {
		calts[gext[data->ch]] = curts;
		firstcal[gext[data->ch]] = false;
		gadc_calibrate_offset(gext[data->ch], 0);

		// Set up the calibration channel for measurement
		gext[CALIBRATION] = gext[data->ch];
		data->chmask |= BIT(CALIBRATION);
		data->ch = CALIBRATION;
	}
#endif

	gadc_start_measurement(data->dev, data->ch);
}

static void adc_context_start_sampling(struct adc_context *ctx)
{
	struct gadc_atm_data *data = CONTAINER_OF(ctx, struct gadc_atm_data, ctx);

	data->chmask = ctx->sequence.channels;
	data->ch = __builtin_ffs(data->chmask) - 1;
#ifdef CONFIG_PM
	pm_policy_state_lock_get(PM_STATE_SUSPEND_TO_RAM, PM_ALL_SUBSTATES);
#endif
	gadc_measure_or_calibrate(data);
}

static int gadc_atm_read_async(struct device const *dev, struct adc_sequence const *sequence,
			       struct k_poll_signal *async)
{
	struct gadc_atm_data *data = DEV_DATA(dev);

	if (!chan_setup_mask || chan_setup_mask & ~BIT_MASK(CHANNEL_NUM_MAX)) {
		LOG_ERR("Invalid selection of channels. Received: %#x", sequence->channels);
		return -EINVAL;
	}

	uint8_t resolution = DT_PROP(DT_NODELABEL(adc), resolution);
	if (sequence->resolution != resolution) {
		LOG_ERR("Only %d bit resolution is supported. Received: %d", resolution,
			sequence->resolution);
		return -EINVAL;
	}

	if (async) {
		adc_context_lock(&data->ctx, true, async);
	} else {
		adc_context_lock(&data->ctx, false, async);
	}

	data->active_channels = 0;
	for (int i = 0; i < CHANNEL_NUM_MAX; ++i) {
		if (sequence->channels & BIT(i)) {
			data->offset[i] = data->active_channels++;
		}
	}

	size_t exp_size = data->active_channels * sizeof(int32_t);
	if (sequence->options) {
		exp_size *= (1 + sequence->options->extra_samplings);
	}

	if (sequence->buffer_size < exp_size) {
		LOG_ERR("Required buffer size is %u. Received: %u", exp_size,
			sequence->buffer_size);
		adc_context_release(&data->ctx, -ENOMEM);
		return -ENOMEM;
	}

	data->buffer = sequence->buffer;

	adc_context_start_read(&data->ctx, sequence);
	int ret = adc_context_wait_for_completion(&data->ctx);
	adc_context_release(&data->ctx, ret);

	return ret;
}

static int gadc_atm_read(struct device const *dev, struct adc_sequence const *sequence)
{
	return gadc_atm_read_async(dev, sequence, NULL);
}

static bool gadc_ext_valid(GADC_CHANNEL_ID ch, gadc_gain_ext_t gainext)
{
	for (int i = 0; (i < GAIN_EXT_MAX) && (gextmap[ch][i] != GAIN_EXT_END); i++) {
		if (gainext == gextmap[ch][i]) {
			return true;
		}
	}

	return false;
}

static int gadc_atm_channel_setup(struct device const *dev,
				  struct adc_channel_cfg const *channel_cfg)
{
	ARG_UNUSED(dev);

	if (channel_cfg->acquisition_time != ADC_ACQ_TIME_DEFAULT) {
		LOG_ERR("Selected GADC acquisition time is not valid");
		return -EINVAL;
	}

	if (channel_cfg->channel_id >= CHANNEL_NUM_MAX) {
		LOG_ERR("Channel %d is not valid", channel_cfg->channel_id);
		return -EINVAL;
	}

	gadc_gain_ext_t gainext;
#ifdef CONFIG_ATM_ADC_UNITY_GAIN
	gainext = GAIN_EXT_X1;
#else
	switch (channel_cfg->gain) {
	case ADC_GAIN_1_8:
		gainext = GAIN_EXT_EIGHTH;
		break;
	case ADC_GAIN_1_4:
		gainext = GAIN_EXT_QUARTER;
		break;
	case ADC_GAIN_1_2:
		gainext = GAIN_EXT_HALF;
		break;
	case ADC_GAIN_1:
		gainext = GAIN_EXT_X1;
		break;
	default:
		LOG_ERR("Invalid channel gain");
		return -EINVAL;
	}
#endif

	if (!gadc_ext_valid(channel_cfg->channel_id, gainext)) {
		LOG_ERR("Invalid gext (%d) for channel (%d)", gainext, channel_cfg->channel_id);
		return -EINVAL;
	}
	gext[channel_cfg->channel_id] = gainext;

	if (channel_cfg->reference != ADC_REF_INTERNAL) {
		LOG_ERR("Invalid channel reference");
		return -EINVAL;
	}

	chan_setup_mask |= (1 << channel_cfg->channel_id);

	LOG_DBG("Channel (%#x) setup succeeded!", chan_setup_mask);
	return 0;
}

static struct adc_driver_api const api_atm_driver_api = {
	.channel_setup = gadc_atm_channel_setup,
	.read = gadc_atm_read,
#ifdef CONFIG_ADC_ASYNC
	.read_async = gadc_atm_read_async,
#endif
	.ref_internal = ATM_GADC_VREF_VOL,
};

#ifdef DGADC_CTRL1__RTRIM_IC__WRITE
// Channels whose FIFO output needs its sign inverted
static bool gadc_ch_inverted(GADC_CHANNEL_ID ch)
{
	return (ch == PORT0_SINGLE_ENDED_1) || (ch == PORT1_SINGLE_ENDED_1)
#ifdef GADC_GADC_CTRL__EXT_VDD1_SEL__SET
	       || (ch == PORT2_SINGLE_ENDED) || (ch == PORT3_SINGLE_ENDED) ||
	       (ch == PORT4_SINGLE_ENDED)
#endif
		;
}
#endif

static int32_t gadc_process_samples(struct device const *dev, GADC_CHANNEL_ID ch)
{
	ASSERT_ERR(ch && (ch < CHANNEL_NUM_MAX));
	Z_CMSDK_GADC->CTRL = 0;

	struct gadc_fifo_s raw_fifo = gadc_read_ch_data();

	// Disable clocks between samples
	gadc_analog_control(false, UNUSED);
	WRPR_CTRL_SET(Z_CMSDK_GADC, WRPR_CTRL__SRESET);

	// raw_fifo:  4 bit channel + 16 bit data = 20 bits
#ifndef DGADC_CTRL1__RTRIM_IC__WRITE
	int32_t sample_signed = gadc_atm_apply_cal(raw_fifo.sample, ch);
	LOG_DBG("channel: %d, raw: %#x, sample_signed: %" PRId32 "\n", ch, raw_fifo.value,
		sample_signed);
	return sample_signed;
#else
	int32_t sample_signed = raw_fifo.sample;

	if (ch == LI_ION_BATT) {
		WRPR_CTRL_PUSH(CMSDK_PMU, WRPR_CTRL__CLK_ENABLE)
		{
			uint32_t gadc_ctrl = PMU_READ(GADC, GADC_CTRL_REG_ADDR);
			GADC_GADC_CTRL__LI_EN__CLR(gadc_ctrl);
			PMU_WRITE(GADC, GADC_CTRL_REG_ADDR, gadc_ctrl);
		}
		WRPR_CTRL_POP();
		sample_signed *= 6;
	} else if (gadc_ch_inverted(ch)) {
		sample_signed *= -1;
	} else if (ch == TEMP) {
#if !DT_PROP(DT_NODELABEL(adc), temp_channel_new)
#define DEF_REF_TEMP     25.0f
#define TMP117_LSB       0.0078125f
#define CELSIUS_PER_VOLT 925.93f
#define DEF_REF_FIFO     19114 // nominal FIFO value at DEF_REF_TEMP
		float ref_temp = DEF_REF_TEMP;
		if (CAL_PRESENT(chipinfo, test_temperature) && (chipinfo.version > 17)) {
			ref_temp = chipinfo.test_temperature * TMP117_LSB;
		}
		int32_t ref_sample = DEF_REF_FIFO;
		if (CAL_PRESENT(gcal, temp_fifo) && (chipinfo.version > 17)) {
			ref_sample = gcal.temp_fifo;
		}
		float volt_delta = (sample_signed - ref_sample) * 0.6f / 32767.0f;
		float result = ref_temp + CELSIUS_PER_VOLT * volt_delta;
		LOG_DBG("channel: %d, raw: %#x, result: %f C", ch, raw_fifo.value, (double)result);
		// return value in 0.01°C units
		return (int32_t)(result * 100.0f);
#endif
	}

	LOG_DBG("channel: %d, raw: %#x, sample_signed: %" PRId32 "\n", ch, raw_fifo.value,
		sample_signed);

	return sample_signed;
#endif                         /* !DGADC_CTRL1__RTRIM_IC__WRITE */
}

static void gadc_atm_isr(void const *arg)
{
	struct device *dev = (struct device *)arg;
	struct gadc_atm_data *data = DEV_DATA(dev);

	Z_CMSDK_GADC->INTERRUPT_CLEAR = DGADC_INTERRUPT_CLEAR__WRITE;

	irq_disable(DT_INST_IRQN(0));

	int32_t sample = gadc_process_samples(dev, data->ch);
	data->chmask &= ~BIT(data->ch);
#ifdef DGADC_CTRL1__RTRIM_IC__WRITE
	if (data->ch == CALIBRATION) {
		data->ch = __builtin_ffs(data->chmask) - 1;
		gadc_calibrate_offset(gext[data->ch], sample);
		gadc_start_measurement(dev, data->ch);
		return;
	}
#endif
	*(data->buffer + data->offset[data->ch]) = sample;
	if (data->chmask) {
		data->ch = __builtin_ffs(data->chmask) - 1;
		gadc_measure_or_calibrate(data);
		return;
	}

	adc_context_on_sampling_done(&data->ctx, dev);
#ifdef CONFIG_PM
	pm_policy_state_lock_put(PM_STATE_SUSPEND_TO_RAM, PM_ALL_SUBSTATES);
#endif
}

// Fetch the GADC calibration tag from the secure journal
static void gadc_fetch_cal(void)
{
	gcal_len = sizeof(gcal);
	sec_jrnl_ret_status_t status = SEC_JRNL_NO_TAG;
#ifdef CONFIG_ATM_ADC_CAL_TEST_HOOKS
	if (!gcal_test_no_tag)
#endif
	{
		status = nsc_sec_jrnl_get(ATM_TAG_GADC_CAL, &gcal_len, (uint8_t *)&gcal);
	}
	if (status != SEC_JRNL_OK) {
		LOG_INF("GADC_CAL tag not found: %#x", status);
		gcal_len = 0;
	}
}

#ifdef CONFIG_ATM_ADC_CAL_RELOAD
void atm_adc_reload_cal(bool override)
{
	if (override) {
		gadc_fetch_cal();
		return;
	}

	/* Keep the cached calibration when the journal has no tag, so a
	 * journal that only carries unrelated tags does not discard a
	 * previously detected calibration. */
	uint16_t prev_len = gcal_len;
	__typeof__(gcal) prev = gcal;

	gadc_fetch_cal();
	if (!gcal_len) {
		gcal = prev;
		gcal_len = prev_len;
	}
}
#endif

static int gadc_atm_init(struct device const *dev)
{
	struct gadc_atm_data *data = DEV_DATA(dev);
	data->dev = dev;

	WRPR_CTRL_SET(Z_CMSDK_GADC, WRPR_CTRL__SRESET);
	IRQ_CONNECT(DT_INST_IRQN(0), DT_INST_IRQ(0, priority), gadc_atm_isr, DEVICE_DT_INST_GET(0),
		    0);

	// Fetch GADC calibration
	gadc_fetch_cal();

#ifdef DGADC_CTRL1__RTRIM_IC__WRITE
	// Fetch chip info
	chipinfo_len = sizeof(chipinfo);
	sec_jrnl_ret_status_t status =
		nsc_sec_jrnl_get(ATM_TAG_CHIP_INFO, &chipinfo_len, (uint8_t *)&chipinfo);
	if (status != SEC_JRNL_OK) {
		LOG_INF("CHIP_INFO tag not found: %#x", status);
		chipinfo_len = 0;
	}

	uint32_t ts = atm_lpc_to_ms(atm_get_sys_time());
	for (int i = 0; i < ARRAY_SIZE(calts); i++) {
		calts[i] = ts;
		firstcal[i] = true;
	}
#endif

	adc_context_unlock_unconditionally(&data->ctx);

	return 0;
}

static struct gadc_atm_data gadc_atm_data_0 = {
	ADC_CONTEXT_INIT_TIMER(gadc_atm_data_0, ctx),
	ADC_CONTEXT_INIT_LOCK(gadc_atm_data_0, ctx),
	ADC_CONTEXT_INIT_SYNC(gadc_atm_data_0, ctx),
};
DEVICE_DT_INST_DEFINE(0, gadc_atm_init, NULL, &gadc_atm_data_0, NULL, POST_KERNEL,
		      CONFIG_KERNEL_INIT_PRIORITY_DEVICE, &api_atm_driver_api);

#ifdef CONFIG_ATM_ADC_CAPTURE

/* GADC input clock at CLKDIV 0; every CLKDIV step halves it */
#define GADC_CAPTURE_CLK_MAX_HZ 8000000U
/* Decimation filter OSR at OSR_SEL 0; every OSR_SEL step halves it */
#define GADC_CAPTURE_OSR_MAX    128U

#define GADC_CAPTURE_CLKDIV_NUM BIT(DGADC_CTRL__CLKDIV__WIDTH)
#define GADC_CAPTURE_OSR_NUM    BIT(DGADC_CTRL1__OSR_SEL__WIDTH)
#define GADC_CAPTURE_AVG_NUM    BIT(DGADC_CTRL__AVERAGING_AMOUNT__WIDTH)

/* FIFO_DBG.STATUS bit 15: a conversion completed while the FIFO was full. The
 * FIFO does not overwrite, so that sample was dropped. Live, not sticky: the
 * next write that finds space clears it again, so it has to be sampled while
 * the drain is in progress. */
#define GADC_CAPTURE_FIFO_OVERRUN BIT(15)

#define GADC_CAPTURE_CYCLES_PER_MS (CONFIG_SYS_CLOCK_HW_CYCLES_PER_SEC / 1000U)

/* FIFO reads between clock reads while waiting for a sample. k_cycle_get_32()
 * takes the timer driver's spinlock, so consulting it on every poll would cost
 * more than the sample period it is timing; a burst of plain FIFO reads is far
 * cheaper and only costs precision on an error path. */
#define GADC_CAPTURE_POLLS_PER_CLOCK_READ 16U

static bool capture_active;
static bool capture_invert;

static bool gadc_capture_overran(void)
{
	return DGADC_FIFO_DBG__STATUS__READ(Z_CMSDK_GADC->FIFO_DBG) & GADC_CAPTURE_FIFO_OVERRUN;
}

/* Busy-poll until the FIFO has a sample, storing it in @p out. */
static int gadc_capture_wait(uint32_t *out, uint32_t timeout_cyc)
{
	uint32_t start = 0;
	bool timing = false;

	for (;;) {
		for (unsigned int i = 0; i < GADC_CAPTURE_POLLS_PER_CLOCK_READ; i++) {
			*out = Z_CMSDK_GADC->DATAPATH_OUTPUT;
			if (!(*out & DGADC_DATAPATH_OUTPUT__EMPTY__MASK)) {
				return 0;
			}
		}

		if (!timing) {
			/* Deferred so a sample that lands within the first burst
			 * never pays for a clock read at all, which is the
			 * common case when the drain outruns the converter. */
			start = k_cycle_get_32();
			timing = true;
		} else if ((k_cycle_get_32() - start) > timeout_cyc) {
			return -ETIMEDOUT;
		}
	}
}

static uint32_t gadc_capture_rate(uint8_t clkdiv, uint8_t osrsel)
{
	return (GADC_CAPTURE_CLK_MAX_HZ >> clkdiv) / (GADC_CAPTURE_OSR_MAX >> osrsel);
}

/* Pick the fastest CLKDIV/OSR_SEL/AVERAGING_AMOUNT triple at or below want_hz.
 * Ties are broken towards the faster clock, which folds more conversions into
 * the same output rate, then towards the larger OSR, which spends them on the
 * decimation filter rather than on averaging.
 */
static int gadc_capture_select_rate(uint32_t want_hz, uint8_t osr_req, uint8_t avg_req,
				    uint8_t *out_clkdiv, uint8_t *out_osrsel, uint8_t *out_avg,
				    uint32_t *out_rate)
{
	uint32_t best = 0;

	for (uint8_t clkdiv = 0; clkdiv < GADC_CAPTURE_CLKDIV_NUM; clkdiv++) {
		for (uint8_t osrsel = 0; osrsel < GADC_CAPTURE_OSR_NUM; osrsel++) {
			if ((osr_req != ATM_ADC_CAPTURE_OSR_AUTO) && (osrsel != osr_req)) {
				continue;
			}
			for (uint8_t avg = 0; avg < GADC_CAPTURE_AVG_NUM; avg++) {
				if ((avg_req != ATM_ADC_CAPTURE_AVG_AUTO) && (avg != avg_req)) {
					continue;
				}
				uint32_t rate = gadc_capture_rate(clkdiv, osrsel) >> avg;

				if ((rate > want_hz) || (rate <= best)) {
					continue;
				}
				best = rate;
				*out_clkdiv = clkdiv;
				*out_osrsel = osrsel;
				*out_avg = avg;
			}
		}
	}

	if (!best) {
		return -EINVAL;
	}

	*out_rate = best;
	return 0;
}

int atm_adc_capture_start(struct atm_adc_capture_cfg const *cfg, uint32_t *actual_rate_hz)
{
	if (!cfg || !cfg->channel || (cfg->channel >= CHANNEL_NUM_MAX)) {
		return -EINVAL;
	}
	if ((cfg->osr_sel != ATM_ADC_CAPTURE_OSR_AUTO) && (cfg->osr_sel >= GADC_CAPTURE_OSR_NUM)) {
		return -EINVAL;
	}
	if ((cfg->avg_exp != ATM_ADC_CAPTURE_AVG_AUTO) && (cfg->avg_exp >= GADC_CAPTURE_AVG_NUM)) {
		return -EINVAL;
	}

	uint8_t clkdiv = 0, osrsel = 0, avg = 0;
	uint32_t rate;
	int ret = gadc_capture_select_rate(cfg->sample_rate_hz, cfg->osr_sel, cfg->avg_exp, &clkdiv,
					   &osrsel, &avg, &rate);
	if (ret) {
		LOG_ERR("No capture rate at or below %u Hz", cfg->sample_rate_hz);
		return ret;
	}

	/* The context lock starts out taken until gadc_atm_init() releases it. */
	if (!device_is_ready(DEVICE_DT_INST_GET(0))) {
		return -ENODEV;
	}

	if (capture_active) {
		return -EBUSY;
	}

	/* Block one-shot conversions for the lifetime of the capture: they share
	 * CTRL and the analog front end. */
	adc_context_lock(&gadc_atm_data_0.ctx, false, NULL);
	capture_active = true;

	GADC_CHANNEL_ID ch = (GADC_CHANNEL_ID)cfg->channel;

	WRPR_CTRL_SET(Z_CMSDK_GADC, WRPR_CTRL__CLK_ENABLE | WRPR_CTRL__CLK_SEL);
#ifdef DGADC_CTRL1__RTRIM_IC__WRITE
	gadc_apply_calibration();
#endif
	gadc_analog_control(true, ch);

	/* The datapath is drained by polling, so keep the measurement-done
	 * interrupt out of the way: gadc_atm_isr() would tear the capture
	 * down after the first sample. */
	irq_disable(DT_INST_IRQN(0));
	Z_CMSDK_GADC->INTERRUPT_MASK = 0;
	Z_CMSDK_GADC->INTERRUPT_CLEAR = DGADC_INTERRUPT_CLEAR__WRITE;

#ifdef DGADC_CTRL1__RTRIM_IC__WRITE
	uint8_t watch_ch =
		(ch == LI_ION_BATT) ? gadc_select_channel(CALIBRATION) : gadc_select_channel(ch);
	capture_invert = gadc_ch_inverted(ch);
#else
	uint8_t watch_ch = ch;
	capture_invert = false;
#endif
	/* AVERAGING_AMOUNT is 0 unless requested: hardware averaging is a
	 * low-pass filter and would attenuate what a capture consumer is trying
	 * to recover. Each output is the mean of 2^avg decimated samples. */
	Z_CMSDK_GADC->CTRL = DGADC_CTRL__WATCH_CHANNELS__WRITE(1U << watch_ch) |
			     DGADC_CTRL__AVERAGING_AMOUNT__WRITE(avg) |
			     DGADC_CTRL__WAIT_AMOUNT__WRITE(GADC_WAIT_AMOUNT) |
			     DGADC_CTRL__CLKDIV__WRITE(clkdiv) |
			     DGADC_CTRL__WARMUP__WRITE(GADC_WARMUP_CYCLES) |
			     DGADC_CTRL__MODE__WRITE(0); // Continuous mode

	DGADC_CTRL1__OSR_SEL__MODIFY(Z_CMSDK_GADC->CTRL1, osrsel);
	DGADC_CTRL1__MOD_SEL__MODIFY(Z_CMSDK_GADC->CTRL1, GADC_MOD_SELECT);

	// Flush old FIFO values
	while (!(Z_CMSDK_GADC->DATAPATH_OUTPUT & DGADC_DATAPATH_OUTPUT__EMPTY__MASK)) {
		YIELD();
	}

	DGADC_CTRL__ENABLE_DP__SET(Z_CMSDK_GADC->CTRL);

	LOG_DBG("capture ch=%u clkdiv=%u osr_sel=%u avg=%u rate=%u Hz", (unsigned int)ch, clkdiv,
		osrsel, avg, rate);

	if (actual_rate_hz) {
		*actual_rate_hz = rate;
	}

	return 0;
}

int atm_adc_capture_read(int16_t *buf, size_t max, size_t *out_n, uint32_t sample_timeout_ms)
{
	if (!buf || !out_n || !max) {
		return -EINVAL;
	}
	if (!capture_active) {
		return -EPERM;
	}

	/* Converted once, and to cycles rather than ms: k_uptime_get() costs a
	 * call into the timer driver plus a 64-bit software divide, which on its
	 * own exceeds the sample period at capture rates. Nothing on the path
	 * taken when a sample is already waiting reads a clock. */
	uint32_t timeout_cyc = (sample_timeout_ms > (UINT32_MAX / GADC_CAPTURE_CYCLES_PER_MS))
				       ? UINT32_MAX
				       : (sample_timeout_ms * GADC_CAPTURE_CYCLES_PER_MS);

	size_t n = 0;
	int ret = 0;
	bool overran = false;

	while (n < max) {
		/* Sampled before the pop that would free the slot: the flag
		 * only holds while the FIFO stays full, so a drop that has
		 * already healed is invisible to a check after the burst. */
		overran = overran || gadc_capture_overran();

		uint32_t out = Z_CMSDK_GADC->DATAPATH_OUTPUT;

		if (out & DGADC_DATAPATH_OUTPUT__EMPTY__MASK) {
			if (!sample_timeout_ms) {
				/* A zero budget means "take what is there", so
				 * running dry is not an error. */
				goto done;
			}
			ret = gadc_capture_wait(&out, timeout_cyc);
			if (ret) {
				goto done;
			}
		}

		struct gadc_fifo_s f = {
			.value = DGADC_DATAPATH_OUTPUT__DATA__READ(out),
		};
		/* Same polarity correction as the one-shot path, saturating
		 * INT16_MIN rather than letting it wrap. */
		buf[n++] = capture_invert ? (int16_t)MIN(-(int32_t)f.sample, INT16_MAX) : f.sample;
	}

done:
	*out_n = n;

	/* An overrun invalidates the burst as a contiguous record regardless of
	 * where it happened, so it is reported ahead of a stall: lost samples
	 * are the worse fault. */
	if (overran || gadc_capture_overran()) {
		LOG_ERR("GADC FIFO overrun: samples dropped, capture restart required");
		return -EIO;
	}

	return ret;
}

int atm_adc_capture_stop(void)
{
	if (!capture_active) {
		return -EPERM;
	}

	Z_CMSDK_GADC->CTRL = 0;
	gadc_analog_control(false, UNUSED);
	/* Empties the FIFO: it ties i_flush low, so a block reset is the only
	 * way to drop stale samples between captures. */
	WRPR_CTRL_SET(Z_CMSDK_GADC, WRPR_CTRL__SRESET);

	capture_active = false;
	adc_context_release(&gadc_atm_data_0.ctx, 0);

	return 0;
}

#endif /* CONFIG_ATM_ADC_CAPTURE */

#ifdef CONFIG_ATM_ADC_TEST_API

int atm_adc_test_raw_samples(uint8_t channel, int16_t *buf, uint8_t buf_len)
{
	if (!buf || !buf_len) {
		return -EINVAL;
	}

	struct atm_adc_capture_cfg cfg = {
		.channel = channel,
		/* Same CLKDIV/OSR_SEL the one-shot path takes from DT */
		.sample_rate_hz = gadc_capture_rate(DT_PROP(DT_NODELABEL(adc), clock_freq),
						    DT_PROP(DT_NODELABEL(adc), osr_select)),
		.osr_sel = DT_PROP(DT_NODELABEL(adc), osr_select),
	};

	int ret = atm_adc_capture_start(&cfg, NULL);
	if (ret) {
		return ret;
	}

#define ATM_ADC_TEST_API_POLL_TIMEOUT_MS 50
	size_t n;
	ret = atm_adc_capture_read(buf, buf_len, &n, ATM_ADC_TEST_API_POLL_TIMEOUT_MS);

	atm_adc_capture_stop();

	/* Callers want independent samples, not a contiguous record, so a FIFO
	 * overrun costs nothing here: every sample stored is still valid. */
	if (ret == -EIO) {
		ret = 0;
	}

	return ret;
}

#ifdef DGADC_CTRL1__RTRIM_IC__WRITE
uint16_t const atm_adc_test_cal_stable_len = __OFFSET(gcal, offset_comp0);
#else
uint16_t const atm_adc_test_cal_stable_len = sizeof(gcal);
#endif

int atm_adc_test_get_cal(void *buf, size_t buf_size, uint16_t *out_len)
{
	if (!buf || !out_len) {
		return -EINVAL;
	}
	if (buf_size < sizeof(gcal)) {
		return -ENOMEM;
	}

	memcpy(buf, &gcal, sizeof(gcal));
	*out_len = gcal_len;

	return 0;
}

#endif /* CONFIG_ATM_ADC_TEST_API */

#ifdef CONFIG_ATM_ADC_CAL_TEST_HOOKS

void atm_adc_test_invalidate_cal(void)
{
	/* Only clobber what a successful fetch writes back. */
	memset(&gcal, 0xa5, gcal_len);
	gcal_len = 0;
}

void atm_adc_test_set_cal_missing(bool missing)
{
	gcal_test_no_tag = missing;
}
#endif /* CONFIG_ATM_ADC_CAL_TEST_HOOKS */
