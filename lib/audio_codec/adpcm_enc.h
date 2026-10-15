/*
 * Copyright (c) Atmosic 2026
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

#pragma once

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @file adpcm_enc.h
 * @brief IMA ADPCM encoder
 *
 * Implements IMA (Interactive Multimedia Association) ADPCM 4-bit encoding.
 * Each call to adpcm_encode_sample() consumes one 16-bit PCM sample and
 * returns one 4-bit nibble (0x0–0xF in the low four bits).
 *
 * The encoder state is maintained globally; call adpcm_reset() at the start
 * of each audio stream.  Use adpcm_get_index() to read back the predictor
 * state for inclusion in ATVV audio frame headers.
 *
 * adpcm_encode_buf() is a convenience wrapper that encodes @p n_samples PCM
 * samples and packs the output nibbles two-per-byte into @p out.
 */

/**
 * @brief Reset the ADPCM encoder state.
 *
 * Sets predictor = 0, step index = 0.  Must be called before each new
 * audio stream.
 */
void adpcm_reset(void);

/**
 * @brief Encode one 16-bit PCM sample.
 *
 * @param pcm_sample  Signed 16-bit linear PCM input.
 * @return            4-bit ADPCM nibble in bits [3:0] (bits [7:4] are zero).
 */
uint8_t adpcm_encode_sample(int16_t pcm_sample);

/**
 * @brief Read the current encoder state.
 *
 * Returns the current predictor value and writes the current step-table
 * index to @p idx.  Useful for populating ATVV audio frame header fields
 * @c prevp and @c idx.
 *
 * @param idx  Output: current step-table index (0–88).
 * @return     Current ADPCM predictor (signed 32-bit).
 */
int32_t adpcm_get_index(uint8_t *idx);

/**
 * @brief Encode a block of PCM samples into a packed ADPCM byte array.
 *
 * Encodes @p n_samples PCM samples and packs the resulting 4-bit nibbles
 * two-per-byte (even sample → low nibble, odd sample → high nibble) into
 * @p out.  @p out must be at least @c (n_samples / 2) bytes.
 *
 * @p n_samples must be even.
 *
 * @param pcm       Input PCM samples (signed 16-bit).
 * @param out       Output ADPCM bytes (each byte holds two nibbles).
 * @param n_samples Number of PCM samples to encode (must be even).
 */
void adpcm_encode_buf(const int16_t *pcm, uint8_t *out, uint16_t n_samples);

#ifdef __cplusplus
}
#endif
