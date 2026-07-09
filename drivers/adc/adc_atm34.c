
/*
 * Copyright (c) 2023-2026 Atmosic
 *
 * SPDX-License-Identifier: Apache-2.0
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
#ifdef CONFIG_ATM_ADC_PGA_BYPASS
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
#else /* CONFIG_ATM_ADC_PGA_BYPASS */
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
#endif /* CONFIG_ATM_ADC_PGA_BYPASS */
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
#ifdef CONFIG_ATM_ADC_PGA_BYPASS
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
	case TEMP:
		if (!gcal_len) {
			return (int32_t)raw;
		}
		/*
		 * gain_temp0 : U-6.22 (22 frac bits), degC/LSB — unsigned slope
		 * offset_temp0: S8.8  ( 8 frac bits), degC     — signed intercept
		 * output      : S8.8  ( 8 frac bits), degC
		 */
		return (int32_t)(((int32_t)raw * (int32_t)gcal.gain_temp0) >>
				 (GADC_CAL_TEMP_FRAC_BITS - 8)) +
		       gcal.offset_temp0;
	default:
		return (int32_t)raw;
	}
}
#endif

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

	// Set the gain and watch channel for the specified channel
	GADC_WATCH_CHANNEL watch_ch;
	uint8_t clkdiv = DT_PROP(DT_NODELABEL(adc), clock_freq);
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
#ifdef DGADC_CTRL1__RTRIM_IC__WRITE
#define GADC_CLK_1MHZ 3
		clkdiv = GADC_CLK_1MHZ;
#endif
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
		WRPR_CTRL_PUSH(CMSDK_PMU, WRPR_CTRL__CLK_ENABLE)
		{
			uint32_t gadc_ctrl = PMU_READ(GADC, GADC_CTRL_REG_ADDR);
			GADC_GADC_CTRL__LI_EN__SET(gadc_ctrl);
			PMU_WRITE(GADC, GADC_CTRL_REG_ADDR, gadc_ctrl);
		}
		WRPR_CTRL_POP();
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
#ifdef DGADC_CTRL1__RTRIM_IC__WRITE
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
#ifdef CONFIG_ATM_ADC_PGA_BYPASS
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
	} else if ((ch == PORT0_SINGLE_ENDED_1) || (ch == PORT1_SINGLE_ENDED_1)
#ifdef GADC_GADC_CTRL__EXT_VDD1_SEL__SET
		   || (ch == PORT2_SINGLE_ENDED) || (ch == PORT3_SINGLE_ENDED) ||
		   (ch == PORT4_SINGLE_ENDED)
#endif
	) {
		// need to invert sign
		sample_signed *= -1;
	} else if (ch == TEMP) {
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

static int gadc_atm_init(struct device const *dev)
{
	struct gadc_atm_data *data = DEV_DATA(dev);
	data->dev = dev;

	WRPR_CTRL_SET(Z_CMSDK_GADC, WRPR_CTRL__SRESET);
	IRQ_CONNECT(DT_INST_IRQN(0), DT_INST_IRQ(0, priority), gadc_atm_isr, DEVICE_DT_INST_GET(0),
		    0);

	// Fetch GADC calibration
	gcal_len = sizeof(gcal);
	sec_jrnl_ret_status_t status;
	status = nsc_sec_jrnl_get(ATM_TAG_GADC_CAL, &gcal_len, (uint8_t *)&gcal);
	if (status != SEC_JRNL_OK) {
		LOG_INF("GADC_CAL tag not found: %#x", status);
		gcal_len = 0;
	}

#ifdef DGADC_CTRL1__RTRIM_IC__WRITE
	// Fetch chip info
	chipinfo_len = sizeof(chipinfo);
	status = nsc_sec_jrnl_get(ATM_TAG_CHIP_INFO, &chipinfo_len, (uint8_t *)&chipinfo);
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

#ifdef CONFIG_ATM_ADC_TEST_API

int atm_adc_test_raw_samples(uint8_t channel, int16_t *buf, uint8_t buf_len)
{
	if (!buf || !buf_len) {
		return -EINVAL;
	}

	int ret = 0;
	uint8_t clkdiv = DT_PROP(DT_NODELABEL(adc), clock_freq);

	WRPR_CTRL_SET(Z_CMSDK_GADC, WRPR_CTRL__CLK_ENABLE | WRPR_CTRL__CLK_SEL);
	gadc_analog_control(true, (GADC_CHANNEL_ID)channel);

	Z_CMSDK_GADC->INTERRUPT_MASK = 0;
	Z_CMSDK_GADC->INTERRUPT_CLEAR = DGADC_INTERRUPT_CLEAR__WRITE;

#ifdef DGADC_CTRL1__RTRIM_IC__WRITE
	uint8_t watch_ch = (channel >= LI_ION_BATT) ? WATCH_CH_CALIBRATION : channel;
#else
	uint8_t watch_ch = channel;
#endif
	Z_CMSDK_GADC->CTRL = DGADC_CTRL__WATCH_CHANNELS__WRITE(1U << watch_ch) |
			     DGADC_CTRL__AVERAGING_AMOUNT__WRITE(0) |
			     DGADC_CTRL__WAIT_AMOUNT__WRITE(GADC_WAIT_AMOUNT) |
			     DGADC_CTRL__CLKDIV__WRITE(clkdiv) |
			     DGADC_CTRL__WARMUP__WRITE(GADC_WARMUP_CYCLES) |
			     DGADC_CTRL__MODE__WRITE(0);

	DGADC_CTRL__ENABLE_DP__SET(Z_CMSDK_GADC->CTRL);

	for (uint8_t i = 0; i < buf_len; i++) {
#define ATM_ADC_TEST_API_POLL_TIMEOUT_MS 50
		int64_t deadline = k_uptime_get() + ATM_ADC_TEST_API_POLL_TIMEOUT_MS;
		uint32_t out;
		for (;;) {
			out = Z_CMSDK_GADC->DATAPATH_OUTPUT;
			if (!(out & DGADC_DATAPATH_OUTPUT__EMPTY__MASK)) {
				break;
			}
			if (k_uptime_get() > deadline) {
				ret = -ETIMEDOUT;
				goto cleanup;
			}
		}

		struct gadc_fifo_s f = {
			.value = DGADC_DATAPATH_OUTPUT__DATA__READ(out),
		};
		buf[i] = f.sample;
	}

cleanup:
	Z_CMSDK_GADC->CTRL = 0;
	gadc_analog_control(false, UNUSED);
	WRPR_CTRL_SET(Z_CMSDK_GADC, WRPR_CTRL__SRESET);

	return ret;
}
#endif /* CONFIG_ATM_ADC_TEST_API */
