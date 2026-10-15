/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#ifndef ATM_ADC_CAPTURE_H
#define ATM_ADC_CAPTURE_H

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifdef CONFIG_ATM_ADC_CAPTURE

/** Let the driver choose the oversampling ratio from the requested rate. */
#define ATM_ADC_CAPTURE_OSR_AUTO 0xffU

/** Let the driver choose the hardware averaging: the most conversions that
 *  fit the requested rate. */
#define ATM_ADC_CAPTURE_AVG_AUTO 0xffU

/** @brief GADC continuous-mode capture configuration. */
struct atm_adc_capture_cfg {
	/** GADC channel id (the value of the matching ch-* property in DT). */
	uint8_t channel;
	/** Requested rate; the driver picks the fastest achievable rate that
	 *  does not exceed it. */
	uint32_t sample_rate_hz;
	/** Decimation selector (0 = 128, 1 = 64, 2 = 32, 3 = 16) or
	 *  @ref ATM_ADC_CAPTURE_OSR_AUTO to let the rate request decide.
	 *  Drivers whose datapath has no decimation filter fold the same
	 *  ratios into hardware averaging instead. */
	uint8_t osr_sel;
	/** Hardware averaging exponent (0..7): each output is the mean of
	 *  2^avg_exp decimated samples, dividing the rate by 2^avg_exp. 0 (the
	 *  default) disables averaging. @ref ATM_ADC_CAPTURE_AVG_AUTO runs the
	 *  converter clock as fast as the output rate allows and averages
	 *  whatever the decimation filter cannot absorb. Drivers that already
	 *  spend the averaging on decimation accept only 0, and treat
	 *  @ref ATM_ADC_CAPTURE_AVG_AUTO as 0. */
	uint8_t avg_exp;
};

/**
 * @brief Put the GADC into continuous mode and start producing samples.
 *
 * Unlike adc_read()/adc_read_async(), which run one-shot conversions with a
 * per-conversion warm-up, this leaves the datapath free-running so samples can
 * be drained at the full converter rate. No filtering is applied beyond the
 * decimation @p osr_sel selects and the averaging @p avg_exp selects. Averaging
 * is a low-pass filter, so it is off unless requested: it suits consumers whose
 * signal is well below the averaged output rate.
 *
 * This is not an implementation of Zephyr's CONFIG_ADC_STREAM/RTIO model. The
 * only hardware trigger this block offers that RTIO could bind to is
 * ADC_TRIG_FIFO_FULL, which asserts when the 16-deep FIFO is already full and
 * leaves a single sample period before samples are dropped. Draining by
 * polling instead uses the whole FIFO depth as slack.
 *
 * Samples are uncalibrated signed values in FIFO LSBs. The only correction
 * applied is the channel's polarity, so that a rising input reads as a rising
 * sample on every channel, as it does for adc_read(). No offset, gain or unit
 * conversion is applied, so consumers must either work in LSBs or apply their
 * own scaling.
 *
 * The input gain is the one last configured for the channel with
 * adc_channel_setup(); a channel that was never set up runs at the driver's
 * default gain, which may saturate on high-voltage inputs. Call
 * adc_channel_setup() first when the gain matters.
 *
 * Holds the driver's ADC lock until atm_adc_capture_stop(), so concurrent
 * adc_read()/adc_read_async() calls block for the duration of the capture.
 *
 * @param cfg            Capture configuration.
 * @param actual_rate_hz If non-NULL, set to the rate actually programmed.
 *                       Consumers that derive timing from the sample rate
 *                       should use this rather than assuming the request was
 *                       met exactly.
 *
 * @retval 0        on success.
 * @retval -EINVAL  @p cfg is NULL, the channel is invalid, @p osr_sel or
 *                  @p avg_exp is out of range, or no achievable rate is at or
 *                  below the request.
 * @retval -ENODEV  the ADC driver has not been initialised yet.
 * @retval -EBUSY   a capture is already running.
 */
int atm_adc_capture_start(struct atm_adc_capture_cfg const *cfg, uint32_t *actual_rate_hz);

/**
 * @brief Drain samples from the GADC FIFO.
 *
 * @param buf                Buffer to receive uncalibrated signed samples.
 * @param max                Capacity of @p buf in samples; must be > 0.
 * @param out_n              Set to the number of samples stored.
 * @param sample_timeout_ms  Per-sample busy-poll budget. 0 returns as soon as
 *                           the FIFO runs dry, storing however many samples
 *                           were available. A non-zero value polls for up to
 *                           that long for each sample, so a full @p max
 *                           samples are returned unless the datapath stalls.
 *                           The wait is a busy-poll, not a sleep: at capture
 *                           rates the inter-sample interval is far below a
 *                           scheduler tick. It is honoured only to within a
 *                           poll burst, because reading the clock costs more
 *                           than the sample period it is timing.
 *
 * @retval 0          on success.
 * @retval -EINVAL    @p buf or @p out_n is NULL, or @p max is 0.
 * @retval -EPERM     no capture is running.
 * @retval -EIO       the FIFO overran: the caller did not drain fast enough and
 *                    samples were dropped, so @p buf has a gap at an unknown
 *                    position. The samples stored are individually valid but
 *                    are no longer a contiguous record, which is fatal to any
 *                    consumer that recovers timing from the sample stream.
 *                    Recovery is atm_adc_capture_stop() followed by a fresh
 *                    atm_adc_capture_start(). Takes precedence over
 *                    -ETIMEDOUT.
 * @retval -ETIMEDOUT the FIFO did not produce a sample within the per-sample
 *                    budget. @p out_n still reports the samples stored before
 *                    the stall.
 */
int atm_adc_capture_read(int16_t *buf, size_t max, size_t *out_n, uint32_t sample_timeout_ms);

/**
 * @brief Stop the capture, power down the GADC and release the ADC lock.
 *
 * Resets the block, which also empties the FIFO.
 *
 * @retval 0       on success.
 * @retval -EPERM  no capture is running.
 */
int atm_adc_capture_stop(void);

#endif /* CONFIG_ATM_ADC_CAPTURE */

#ifdef __cplusplus
}
#endif

#endif /* ATM_ADC_CAPTURE_H */
