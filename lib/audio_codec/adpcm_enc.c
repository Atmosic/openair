/*
 * Copyright (c) Atmosic 2026
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 *
 * IMA ADPCM 4-bit encoder.
 */

#include <stdint.h>
#include "adpcm_enc.h"

/* IMA ADPCM 4-bit code layout: bit 3 = sign, bits 2..0 = magnitude */
#define ADPCM_CODE_COUNT 16   /* number of distinct 4-bit codes */
#define ADPCM_MAG_BITS   3    /* number of magnitude bits */
#define ADPCM_SIGN_BIT   0x08 /* sign bit (bit 3) */
#define ADPCM_MAG_BIT2   0x04 /* magnitude MSB (bit 2) */
#define ADPCM_MAG_BIT1   0x02 /* magnitude bit 1 */
#define ADPCM_MAG_BIT0   0x01 /* magnitude LSB (bit 0) */

/* Step-size table spans indices 0..88 (89 entries) */
#define ADPCM_STEP_TABLE_SIZE 89
#define ADPCM_STEP_INDEX_MIN  0
#define ADPCM_STEP_INDEX_MAX  (ADPCM_STEP_TABLE_SIZE - 1)
#define ADPCM_INIT_STEPSIZE   7 /* stepsize_table[0] */

/* Reconstructed PCM clamp range (signed 16-bit) */
#define ADPCM_PCM_SAMPLE_MAX 32767
#define ADPCM_PCM_SAMPLE_MIN (-32768)

/* Output packing: two 4-bit codes per byte */
#define ADPCM_SAMPLES_PER_BYTE 2
#define ADPCM_NIBBLE_BITS      4
#define ADPCM_NIBBLE_MASK      0x0F

/* Table of index deltas for each of the 16 4-bit codes */
static const int8_t index_table[ADPCM_CODE_COUNT] = {
	-1, -1, -1, -1, 2, 4, 6, 8, -1, -1, -1, -1, 2, 4, 6, 8,
};

/* IMA ADPCM step-size table (89 entries, index 0–88) */
static const uint16_t stepsize_table[ADPCM_STEP_TABLE_SIZE] = {
	7,     8,     9,     10,    11,    12,    13,    14,    16,    17,    19,    21,    23,
	25,    28,    31,    34,    37,    41,    45,    50,    55,    60,    66,    73,    80,
	88,    97,    107,   118,   130,   143,   157,   173,   190,   209,   230,   253,   279,
	307,   337,   371,   408,   449,   494,   544,   598,   658,   724,   796,   876,   963,
	1060,  1166,  1282,  1411,  1552,  1707,  1878,  2066,  2272,  2499,  2749,  3024,  3327,
	3660,  4026,  4428,  4871,  5358,  5894,  6484,  7132,  7845,  8630,  9493,  10442, 11487,
	12635, 13899, 15289, 16818, 18500, 20350, 22385, 24623, 27086, 29794, 32767,
};

/* Encoder state */
static int32_t predicted_sample;
static int8_t step_index;
static uint16_t stepsize;

void adpcm_reset(void)
{
	predicted_sample = 0;
	step_index = ADPCM_STEP_INDEX_MIN;
	stepsize = ADPCM_INIT_STEPSIZE;
}

uint8_t adpcm_encode_sample(int16_t original_sample)
{
	uint8_t code;

	int32_t diff = (int32_t)original_sample - predicted_sample;
	if (diff >= 0) {
		code = 0;
	} else {
		code = ADPCM_SIGN_BIT;
		diff = -diff;
	}

	uint8_t mask = ADPCM_MAG_BIT2;
	uint16_t tmp = stepsize;
	for (int i = 0; i < ADPCM_MAG_BITS; i++) {
		if (diff >= tmp) {
			code |= mask;
			diff -= tmp;
		}
		tmp >>= 1;
		mask >>= 1;
	}

	int32_t delta = 0;
	if (code & ADPCM_MAG_BIT2) {
		delta += stepsize;
	}
	if (code & ADPCM_MAG_BIT1) {
		delta += stepsize >> 1;
	}
	if (code & ADPCM_MAG_BIT0) {
		delta += stepsize >> 2;
	}
	delta += stepsize >> ADPCM_MAG_BITS;
	if (code & ADPCM_SIGN_BIT) {
		delta = -delta;
	}

	predicted_sample += delta;
	if (predicted_sample > ADPCM_PCM_SAMPLE_MAX) {
		predicted_sample = ADPCM_PCM_SAMPLE_MAX;
	} else if (predicted_sample < ADPCM_PCM_SAMPLE_MIN) {
		predicted_sample = ADPCM_PCM_SAMPLE_MIN;
	}

	step_index += index_table[code];
	if (step_index < ADPCM_STEP_INDEX_MIN) {
		step_index = ADPCM_STEP_INDEX_MIN;
	} else if (step_index > ADPCM_STEP_INDEX_MAX) {
		step_index = ADPCM_STEP_INDEX_MAX;
	}
	stepsize = stepsize_table[step_index];

	return code;
}

int32_t adpcm_get_index(uint8_t *idx)
{
	*idx = (uint8_t)step_index;
	return predicted_sample;
}

void adpcm_encode_buf(const int16_t *pcm, uint8_t *out, uint16_t n_samples)
{
	for (uint16_t i = 0; i < n_samples; i += ADPCM_SAMPLES_PER_BYTE) {
		uint8_t first = adpcm_encode_sample(pcm[i]) & ADPCM_NIBBLE_MASK;
		uint8_t second = adpcm_encode_sample(pcm[i + 1]) & ADPCM_NIBBLE_MASK;
		/* ATVV uses the first ADPCM sample in the high nibble. */
		*out++ = (first << ADPCM_NIBBLE_BITS) | second;
	}
}
