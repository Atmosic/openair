/**
 *******************************************************************************
 *
 * @file atm_sha2.c
 *
 * @brief Atmosic SHA256 driver
 *
 * Copyright (C) Atmosic 2022-2024
 *
 *******************************************************************************
 */

#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include "atm_sha2.h"
#include "ARMv8MBL.h"
#include "base_addr.h"
#include "at_ahb_dma_regs_core_macro.h"
#include "at_ahb_sha2_regs_core_macro.h"
#include "at_apb_clkrstgen_regs_core_macro.h"
#include "at_apb_wrpr_pins_regs_core_macro.h"
#include "ll.h"
#include "atm_utils_c.h"
#include "atm_utils_reg.h"
#if defined(SECURE_MODE)
#if defined(ENABLE_HMAC_SIDELOAD)
#include "key_sideload.h"
#endif
// Must be set to dedicate SHA2 driver to SECURE only mode.
#ifdef SECURE_SHA2_MODE
#define CMSDK_SHA2 CMSDK_SHA2_SECURE
#else
#define CMSDK_SHA2 CMSDK_SHA2_NONSECURE
#endif
#else // defined(SECURE_MODE)
#define CMSDK_SHA2 CMSDK_SHA2_NONSECURE
#ifdef SECURE_SHA2_MODE
#error "SHA2 access is limited to SECURE when SECURE_SHA2_MODE is enabled."
#endif
#endif // defined(SECURE_MODE)


#define IS_ALIGNED(ptr, alignment) \
    (((uintptr_t)(ptr)) % (alignment) == 0)

#define SHA2_ID 0x53484132 // 'S' 'H' 'A' '2'

#ifndef ATM_SHA2_DEBUG
#define ATM_SHA2_DEBUG 0
#endif

#if ATM_SHA2_DEBUG
static void dump_buffer(uint8_t const *buffer, uint32_t len, char const *descr)
{
    uint32_t column = 0;
    printf("HEX Dump: %s, %" PRIu32 " bytes \n ", descr, len);
    for (uint32_t i = 0; i < len; i++) {
	printf(" %02x", buffer[i]);
	column++;
	if (column > 16) {
	    column = 0;
	    printf("\n ");
	}
    }
    printf("\n");
}
#define SHA2_DUMP_BUFFER(b, l, desc) dump_buffer(b, l, desc)
#else
#define SHA2_DUMP_BUFFER(b, l, desc) \
    do { \
    } while (0)
#endif // ATM_SHA2_DEBUG

#define SHA2_CONTROL_VALUE(param) \
    (AT_SHA2_CONTROL__HMAC_EN__WRITE((param)->mode) | \
	AT_SHA2_CONTROL__SHA_EN__WRITE(1) | \
	AT_SHA2_CONTROL__BYTE_SWIZZLE__WRITE((param)->byte_endianess) | \
	AT_SHA2_CONTROL__DIGEST_SWIZZLE__WRITE((param)->digest_endianess))

static inline void load_hmac_key(uint8_t const *hmac_key)
{
#if defined(SECURE_MODE) && defined(ENABLE_HMAC_SIDELOAD)
    if (key_sideload_address_valid(hmac_key)) {
	CMSDK_SHA2->SIDELOAD_CTRL =
	    AT_SHA2_SIDELOAD_CTRL__SIDELOAD_UPDATE_EN__WRITE(1);
	key_sideload_slot_load(hmac_key);
    } else
#endif
    {
	atm_reg_write_multiple(&(CMSDK_SHA2->KEY_0), hmac_key,
	    HMAC_KEY_LEN);
    }
}

#if (ATM_SHA2_API == SHA_MULTI_CTXT)
static uint32_t sha2_clk_en_ref;
#endif

static inline atm_sha256_res_t sha2_clock_enable(void)
{
#if (ATM_SHA2_API == SHA_MULTI_CTXT)
    uint32_t prev = sha2_clk_en_ref;
    sha2_clk_en_ref++;
    if (prev) {
	// already on
	return ATM_SHA256_RES_SUCCESS;
    }
#endif

    // enable clock to sha2 block
    CLKRSTGEN_USER_CLK_GATE_CTRL__SHA_HCLK__MODIFY(CMSDK_CLKRSTGEN_NONSECURE
						       ->USER_CLK_GATE_CTRL,
	1);
    if (CMSDK_SHA2->ID != SHA2_ID) {
	ASSERT_ERR(CMSDK_SHA2->ID);
	return ATM_SHA256_RES_SHA_ID_ERR;
    }
    return ATM_SHA256_RES_SUCCESS;
}

static inline atm_sha256_res_t sha2_clock_disable(void)
{
#if (ATM_SHA2_API == SHA_MULTI_CTXT)
    if (!sha2_clk_en_ref) {
	ASSERT_ERR(0);
	return ATM_SHA256_RES_INVALID_CTXT;
    }
    sha2_clk_en_ref--;
    if (sha2_clk_en_ref) {
	// stay on
	return ATM_SHA256_RES_SUCCESS;
    }
#endif
    // disable clock to sha2 block
    CMSDK_SHA2->CONTROL = 0;
    CLKRSTGEN_USER_CLK_GATE_CTRL__SHA_HCLK__MODIFY(CMSDK_CLKRSTGEN_NONSECURE
						       ->USER_CLK_GATE_CTRL,
	0);
    return ATM_SHA256_RES_SUCCESS;
}

#if (ATM_SHA2_API == SHA_MULTI_CTXT)

#if ATM_SHA2_DEBUG
static void dump_sha2_context(atm_sha2_ctxt_t *ctxt, char const *descr)
{
    printf("SHA2 (%p) ctxt dump: %s \n", ctxt, descr);
    printf("  mode 0x%" PRIx32 "\n", ctxt->params->mode);
    printf("  control 0x%" PRIx32 "\n", ctxt->control);
    printf("  flags 0x%" PRIx32 "\n", ctxt->flags);
    printf("  msg_len_bits HI:0x%" PRIx32 " LO:0x%" PRIx32 "\n",
	(uint32_t)(ctxt->msg_len_bits << 32), (uint32_t)ctxt->msg_len_bits);
    printf("  sha_txcount_bits HI:0x%" PRIx32 " LO:0x%" PRIx32 "\n",
	(uint32_t)(ctxt->sha_txcount_bits << 32),
	(uint32_t)ctxt->sha_txcount_bits);
    printf("  txcount_bits HI:0x%" PRIx32 " LO:0x%" PRIx32 "\n",
	(uint32_t)(ctxt->txcount_bits << 32), (uint32_t)ctxt->txcount_bits);
    printf("  msg_len_bytes %" PRIu32 "\n", ctxt->msg_len_bytes);
    printf("  partial_len %" PRIu32 "\n", ctxt->partial_len);
    printf("  int_digest[0] 0x%" PRIx32 "\n", ctxt->int_digest[0]);
}
#endif // ATM_SHA2_DEBUG

static void store_partial_block(atm_sha2_ctxt_t *ctxt, void const *buffer,
    uint32_t count)
{
    if ((ctxt->partial_len + count) > sizeof(ctxt->partial_block)) {
	ASSERT_INFO(0, ctxt->partial_len, count);
	return;
    }
    memcpy(&ctxt->partial_block[ctxt->partial_len], buffer, count);
    ctxt->partial_len += count;
    DEBUG_TRACE_COND(ATM_SHA2_DEBUG,
	"SHA2 (%p) bytes:%" PRIu32 " copied, new partial:%" PRIu32, ctxt, count,
	ctxt->partial_len);
    SHA2_DUMP_BUFFER(ctxt->partial_block, ctxt->partial_len, "Store Partial");
}

static atm_sha256_res_t sha2_load_context(atm_sha2_ctxt_t *ctxt,
    void const *input, uint32_t *num_bytes,
    atm_sha256_res_t (*data_push)(void const *input, uint32_t count))
{
    if ((ctxt->magic != SHA2_ID) || (ctxt->flags & SHA2_CTXT_FLAGS_FINI)) {
	DEBUG_TRACE("SHA2 rel-inv-ctxt");
	return ATM_SHA256_RES_INVALID_CTXT;
    }
    // clock must be on
    ASSERT_ERR(sha2_clk_en_ref);

    uint32_t update_bytes = num_bytes ? *num_bytes : 0;
    uint32_t residue = 0;
    if (!input) {
	// no input data to update (finalize), continue and start controller
	goto start_controller;
    }

    SHA2_DUMP_BUFFER(input, update_bytes, "User Input");
    // check if the current updated bytes plus the accumulated partial block
    // meets the block size threshold
    if ((update_bytes + ctxt->partial_len) < SHA256_BLK_SIZE_BYTES) {
	// still a partial block, consume the update into the partial block
	DEBUG_TRACE_COND(ATM_SHA2_DEBUG,
	    "SHA2 (%p) defer, pushed:%" PRIu32 " update:%" PRIu32
	    " curr partial:%" PRIu32,
	    ctxt, ctxt->msg_len_bytes, update_bytes, ctxt->partial_len);
	store_partial_block(ctxt, input, update_bytes);
	// defer and do nothing
	return ATM_SHA256_RES_DEFER_PROC;
    }

    // this transfer will result in residue that has to be saved for the next
    // update or finalization
    residue = (update_bytes + ctxt->partial_len) & (SHA256_BLK_SIZE_BYTES - 1);

start_controller:

    // reset to clear state before loading or establishing a new context
    WRPRPINS_SOC_MISC_CTRL__SHA_RESET__SET(
	CMSDK_WRPR0_NONSECURE->SOC_MISC_CTRL);
    WRPRPINS_SOC_MISC_CTRL__SHA_RESET__CLR(
	CMSDK_WRPR0_NONSECURE->SOC_MISC_CTRL);
    // load control value to enable the core, required step to load
    // counters/digest
    CMSDK_SHA2->CONTROL = ctxt->control;

    uint32_t cmd;
    if (ctxt->flags & SHA2_CTXT_FLAGS_STARTED) {
#if ATM_SHA2_DEBUG
	dump_sha2_context(ctxt, !input ? "reload-fini" : "reload");
#endif
	// HW context already established, just restore
	CMSDK_SHA2->MESSAGE_LENGTH_LO = (uint32_t)ctxt->msg_len_bits;
	CMSDK_SHA2->MESSAGE_LENGTH_HI = ctxt->msg_len_bits >> 32;
	CMSDK_SHA2->SHA_TXCOUNT_LO = (uint32_t)ctxt->sha_txcount_bits;
	CMSDK_SHA2->SHA_TXCOUNT_HI = ctxt->sha_txcount_bits >> 32;
	CMSDK_SHA2->TXCOUNT_LO = (uint32_t)ctxt->txcount_bits;
	CMSDK_SHA2->TXCOUNT_HI = ctxt->txcount_bits >> 32;
	for (uint32_t i = 0; i < SHA256_DIG_WORDS; i++) {
	    *(&CMSDK_SHA2->DIGEST0 + i) = ctxt->int_digest[i];
	}
	// this is a continuation after a context is restored
	cmd = AT_SHA2_CMD__HASH_CONTINUE__MASK | AT_SHA2_CMD__HASH_START__MASK;
	DEBUG_TRACE_COND(ATM_SHA2_DEBUG, "SHA2 (%p) reload-ctxt-%s", ctxt,
	    !input ? "fini" : "");
    } else {
	// first time to establish the HW context
	// the HW context will be established
	cmd = AT_SHA2_CMD__HASH_START__MASK;
	ctxt->flags |= SHA2_CTXT_FLAGS_STARTED;
	DEBUG_TRACE_COND(ATM_SHA2_DEBUG, "SHA2 (%p) start-ctxt", ctxt);
    }

    if (ctxt->params->mode == ATM_SHA256_HMAC_MODE) {
	// for HMAC reload the key
	load_hmac_key(ctxt->params->key);
    }

    // start the engine
    DEBUG_TRACE_COND(ATM_SHA2_DEBUG, "SHA2 (%p) run cmd: 0x%" PRIx32, ctxt,
	cmd);
    CMSDK_SHA2->CMD = cmd;

    if (ctxt->partial_len) {
	// flush partial block first
	DEBUG_TRACE_COND(ATM_SHA2_DEBUG,
	    "SHA2 (%p) push partial bytes:%" PRIu32, ctxt, ctxt->partial_len);
	SHA2_DUMP_BUFFER(ctxt->partial_block, ctxt->partial_len,
	    "Flush partial");
	uint32_t retv = data_push(ctxt->partial_block, ctxt->partial_len);
	ctxt->partial_len = 0;
	if (retv != ATM_SHA256_RES_SUCCESS) {
	    return retv;
	}
    }

    if (residue) {
	ASSERT_ERR(input);
	ASSERT_INFO(*num_bytes >= residue, *num_bytes, residue);
	DEBUG_TRACE_COND(ATM_SHA2_DEBUG,
	    "SHA2 (%p) residue: %" PRIu32 " update: %" PRIu32, ctxt, residue,
	    *num_bytes);
	store_partial_block(ctxt,
	    &((uint8_t const *)input)[*num_bytes - residue], residue);
	// caller does not need to transfer the residue portion, we'll buffer it
	// for the next update
	*num_bytes -= residue;
    }

    return ATM_SHA256_RES_SUCCESS;
}

static void sync_controller_ctxt(void)
{
    // synchronize with the hardware, FIFO has to be empty
    while (!(AT_SHA2_STATUS__FIFO_EMPTY__READ(CMSDK_SHA2->STATUS))) {
	YIELD();
    }
    // if the FIFO is empty wait for computation engine to be idle
    while (
	AT_SHA2_STATUS__HASH_COMPUTE_BUSY__READ(CMSDK_SHA2->STATUS)) {
	YIELD();
    }
}

static atm_sha256_res_t sha2_save_context(atm_sha2_ctxt_t *ctxt,
    void const *input, uint32_t num_bytes)
{
    if (!(ctxt->flags & SHA2_CTXT_FLAGS_STARTED)) {
	ASSERT_INFO(0, ctxt->flags, 0);
	return ATM_SHA256_RES_INVALID_CTXT;
    }
    sync_controller_ctxt();
    // controller is idle, now it is safe to extract the HW context
    ctxt->control = CMSDK_SHA2->CONTROL;
    ctxt->msg_len_bits =
	(((uint64_t)CMSDK_SHA2->MESSAGE_LENGTH_HI) << 32) |
	CMSDK_SHA2->MESSAGE_LENGTH_LO;
    ctxt->sha_txcount_bits =
	(((uint64_t)CMSDK_SHA2->SHA_TXCOUNT_HI) << 32) |
	CMSDK_SHA2->SHA_TXCOUNT_LO;
    ctxt->txcount_bits = (((uint64_t)CMSDK_SHA2->TXCOUNT_HI) << 32) |
	CMSDK_SHA2->TXCOUNT_LO;
    // partial blocks are buffered and held
    // there should be no residue when we sync these registers
    __UNUSED uint32_t blk_bit_mask = SHA256_BLK_SIZE_BITS - 1;
    ASSERT_INFO(!(CMSDK_SHA2->MESSAGE_LENGTH_LO & blk_bit_mask),
	CMSDK_SHA2->MESSAGE_LENGTH_LO, 0);
    ASSERT_INFO(!(CMSDK_SHA2->SHA_TXCOUNT_LO & blk_bit_mask),
	CMSDK_SHA2->SHA_TXCOUNT_LO, 0);
    ASSERT_INFO(!(CMSDK_SHA2->TXCOUNT_LO & blk_bit_mask),
	CMSDK_SHA2->TXCOUNT_LO, 0);
    // save our progress
    ctxt->msg_len_bytes = ctxt->msg_len_bits >> 3;
    // save intermediate digest for the next load
    for (uint32_t i = 0; i < SHA256_DIG_WORDS; i++) {
	ctxt->int_digest[i] = *(&CMSDK_SHA2->DIGEST0 + i);
    }
#if ATM_SHA2_DEBUG
    dump_sha2_context(ctxt, "saved");
#endif
    return ATM_SHA256_RES_SUCCESS;
}

#endif // SHA_MULTI_CTXT

/* TODO: add support for sha engine mode (DMA or not) */
atm_sha256_res_t
#if (ATM_SHA2_API == SHA_MULTI_CTXT)
atm_sha256_init_ctxt(atm_sha256_params_t const *params, atm_sha2_ctxt_t *ctxt)
#else
atm_sha256_init(atm_sha256_params_t const *params)
#endif
{
    if (params->mode >= ATM_SHA256_MAX_MODE) {
	return ATM_SHA256_RES_INVALID_INPUT_ERR;
    }
    if ((params->mode == ATM_SHA256_HMAC_MODE) && (!params->key)) {
	return ATM_SHA256_RES_INVALID_INPUT_ERR;
    }

#if (ATM_SHA2_API == SHA_MULTI_CTXT)
    if (ctxt->magic == SHA2_ID) {
	DEBUG_TRACE("SHA2 ctxt already init");
	// already initialized
	return ATM_SHA256_RES_INVALID_CTXT;
    }
#endif

    atm_sha256_res_t retv = sha2_clock_enable();
    if (retv != ATM_SHA256_RES_SUCCESS) {
	return retv;
    }

#if (ATM_SHA2_API == SHA_MULTI_CTXT)
    ctxt->magic = SHA2_ID;
    ctxt->flags = 0;
    ctxt->msg_len_bits = 0;
    ctxt->msg_len_bytes = 0;
    ctxt->sha_txcount_bits = 0;
    ctxt->control = SHA2_CONTROL_VALUE(params);
    ctxt->params = params;
    ctxt->partial_len = 0;
#else
    // enable SHA and set endianess
    // system is little endian, standard vectors and most hash generators
    // operate on big-endian words enable byte swizzle to swap in hardware
    CMSDK_SHA2->CONTROL = SHA2_CONTROL_VALUE(params);

    if (params->mode == ATM_SHA256_HMAC_MODE) {
	load_hmac_key(params->key);
    }

    CMSDK_SHA2->CMD = AT_SHA2_CMD__HASH_START__WRITE(1);
#endif
    return ATM_SHA256_RES_SUCCESS;
}

#if (ATM_SHA2_API == SHA_MULTI_CTXT)
atm_sha256_res_t atm_sha256_disable_ctxt(atm_sha2_ctxt_t *ctxt)
#else
void atm_sha256_disable(void)
#endif
{
#if (ATM_SHA2_API == SHA_MULTI_CTXT)
    if (ctxt->magic != SHA2_ID) {
	DEBUG_TRACE("SHA2 ctxt not init!");
	return ATM_SHA256_RES_INVALID_CTXT;
    }
    ctxt->magic = 0;
    ctxt->flags = 0;
#endif
    __UNUSED atm_sha256_res_t retv = sha2_clock_disable();
#if (ATM_SHA2_API == SHA_MULTI_CTXT)
    return retv;
#endif
}

static atm_sha256_res_t push_data_dma(void const *input, uint32_t num_bytes)
{
    uint8_t const *buf_ptr = input;
    CMSDK_AT_DMA_NONSECURE->INTERRUPT_MASK =
	AT_DMA_INTERRUPT_STATUS__DMA_DONE__MASK |
	AT_DMA_INTERRUPT_STATUS__DMA_ERR__MASK;
    while (num_bytes) {
	// poll for FIFO to drain before reloading the next block
	while (!(CMSDK_SHA2->STATUS &
	    AT_SHA2_STATUS__FIFO_EMPTY__MASK)) {
	    YIELD();
	}
	// clear the status bit (this is latched in)
	CMSDK_SHA2->RESET_INTERRUPT =
	    AT_SHA2_RESET_INTERRUPT__INTRPT_RESET__MASK;
	// SHA2 registers are not self-resetting.
	CMSDK_SHA2->RESET_INTERRUPT = 0;
	uint32_t dma_bytes = (num_bytes > SHA256_BLK_SIZE_BYTES) ?
	    SHA256_BLK_SIZE_BYTES : num_bytes;
	uint32_t int_status;
	GLOBAL_INT_DISABLE();
	// clear interrupts
	CMSDK_AT_DMA_NONSECURE->RESET_INTERRUPT =
	    AT_DMA_INTERRUPT_STATUS__DMA_DONE__MASK |
	    AT_DMA_INTERRUPT_STATUS__DMA_ERR__MASK;
	CMSDK_AT_DMA_NONSECURE->TAR_ADDR =
	    (uint32_t)(&CMSDK_SHA2->FIFO_PUSH);
	CMSDK_AT_DMA_NONSECURE->SRC_ADDR = (uint32_t)buf_ptr;
	CMSDK_AT_DMA_NONSECURE->SIZE = dma_bytes;
	// target address is constant (FIFO mode)
	CMSDK_AT_DMA_NONSECURE->OPMODE =
	    AT_DMA_OPMODE__GO__MASK | AT_DMA_OPMODE__CONST_TAR_ADDR__MASK;
	num_bytes -= dma_bytes;
	buf_ptr += dma_bytes;
	// wait for DMA done for this block
	while (!(CMSDK_AT_DMA_NONSECURE->INTERRUPT_STATUS &
	    (AT_DMA_INTERRUPT_STATUS__DMA_DONE__MASK |
		AT_DMA_INTERRUPT_STATUS__DMA_ERR__MASK))) {
	    YIELD();
	}
	int_status = CMSDK_AT_DMA_NONSECURE->INTERRUPT_STATUS;
	GLOBAL_INT_RESTORE();
	if (int_status & AT_DMA_INTERRUPT_STATUS__DMA_ERR__MASK) {
	    return ATM_SHA256_RES_DMA_ERR;
	}
    }
    return ATM_SHA256_RES_SUCCESS;
}

atm_sha256_res_t
#if (ATM_SHA2_API == SHA_MULTI_CTXT)
atm_sha256_update_ctxt(atm_sha2_ctxt_t *ctxt, void const *input,
    uint32_t num_bytes)
#else
atm_sha256_update(void const *input, uint32_t num_bytes)
#endif
{
    if (!num_bytes) {
	return ATM_SHA256_RES_INVALID_INPUT_ERR;
    }
    atm_sha256_res_t retv;
#if (ATM_SHA2_API == SHA_MULTI_CTXT)
    // restore context
    retv = sha2_load_context(ctxt, input, &num_bytes, push_data_dma);
    if (retv != ATM_SHA256_RES_SUCCESS) {
	if (retv == ATM_SHA256_RES_DEFER_PROC) {
	    retv = ATM_SHA256_RES_SUCCESS;
	}
	return retv;
    }
#endif
    SHA2_DUMP_BUFFER(input, num_bytes, "push user (DMA)");
    retv = push_data_dma(input, num_bytes);
    if (retv != ATM_SHA256_RES_SUCCESS) {
	return retv;
    }
#if (ATM_SHA2_API == SHA_MULTI_CTXT)
    // save context between each update
    retv = sha2_save_context(ctxt, input, num_bytes);
#endif
    return retv;
}

static atm_sha256_res_t push_data_pio(void const *input, uint32_t num_bytes)
{
    uint8_t const *buf_ptr = input;
    while (num_bytes) {
	// poll for FIFO to drain before reloading the next block
	while (!(CMSDK_SHA2->STATUS &
	    AT_SHA2_STATUS__FIFO_EMPTY__MASK)) {
	    YIELD();
	}
	// clear the status bit (this is latched in)
	CMSDK_SHA2->RESET_INTERRUPT =
	    AT_SHA2_RESET_INTERRUPT__INTRPT_RESET__MASK;
	// SHA2 registers are not self-resetting.
	CMSDK_SHA2->RESET_INTERRUPT = 0;
	while ((!IS_ALIGNED(buf_ptr, sizeof(uint32_t))) && (num_bytes)) {
	    *((uint8_t volatile *)&CMSDK_SHA2->FIFO_PUSH) = *buf_ptr;
	    buf_ptr++;
	    num_bytes--;
	}
	uint32_t transfer_bytes = (num_bytes > SHA256_BLK_SIZE_BYTES) ?
	    SHA256_BLK_SIZE_BYTES : num_bytes;
	uint32_t transfer_words = transfer_bytes / sizeof(uint32_t);
	uint32_t remaining_bytes = transfer_bytes % sizeof(uint32_t);
	while (transfer_words--) {
	    CMSDK_SHA2->FIFO_PUSH = *(const uint32_t *)buf_ptr;
	    buf_ptr += sizeof(uint32_t);
	}
	while (remaining_bytes--) {
	    *((uint8_t volatile *)&CMSDK_SHA2->FIFO_PUSH) = *buf_ptr;
	    buf_ptr++;
	}
	num_bytes -= transfer_bytes;
    }

    return ATM_SHA256_RES_SUCCESS;
}

atm_sha256_res_t
#if (ATM_SHA2_API == SHA_MULTI_CTXT)
atm_sha256_update_pio_ctxt(atm_sha2_ctxt_t *ctxt, void const *input,
    uint32_t num_bytes)
#else
atm_sha256_update_pio(void const *input, uint32_t num_bytes)
#endif
{
    if (!num_bytes) {
	return ATM_SHA256_RES_INVALID_INPUT_ERR;
    }
    atm_sha256_res_t retv;
#if (ATM_SHA2_API == SHA_MULTI_CTXT)
    retv = sha2_load_context(ctxt, input, &num_bytes, push_data_pio);
    if (retv != ATM_SHA256_RES_SUCCESS) {
	if (retv == ATM_SHA256_RES_DEFER_PROC) {
	    retv = ATM_SHA256_RES_SUCCESS;
	}
	return retv;
    }
#endif
    SHA2_DUMP_BUFFER(input, num_bytes, "push user (PIO)");
    retv = push_data_pio(input, num_bytes);
    if (retv != ATM_SHA256_RES_SUCCESS) {
	return retv;
    }
#if (ATM_SHA2_API == SHA_MULTI_CTXT)
    retv = sha2_save_context(ctxt, input, num_bytes);
#endif
    return retv;
}

#if (ATM_SHA2_API == SHA_MULTI_CTXT)
atm_sha256_res_t atm_sha256_final_ctxt(atm_sha2_ctxt_t *ctxt,
    uint8_t digest[SHA256_DIG_LEN])
#else
uint8_t *atm_sha256_final(uint8_t digest[SHA256_DIG_LEN])
#endif
{
#if (ATM_SHA2_API == SHA_MULTI_CTXT)
    atm_sha256_res_t retv = sha2_load_context(ctxt, NULL, NULL, push_data_pio);
    if (retv != ATM_SHA256_RES_SUCCESS) {
	return retv;
    }
    // sync before triggering hash process
    sync_controller_ctxt();
#endif
    AT_SHA2_INTERRUPT_MASK__HMAC_DONE__SET(
	CMSDK_SHA2->INTERRUPT_MASK);
    CMSDK_SHA2->CMD = AT_SHA2_CMD__HASH_PROCESS__WRITE(1);

    DEBUG_TRACE_COND(ATM_SHA2_DEBUG, "SHA2 wait for hash done");
    while (!(CMSDK_SHA2->INTERRUPT_STATUS &
	AT_SHA2_INTERRUPT_STATUS__HMAC_DONE__MASK)) {
	YIELD();
    }
    CMSDK_SHA2->RESET_INTERRUPT |=
	AT_SHA2_INTERRUPT_STATUS__HMAC_DONE__MASK;
    CMSDK_SHA2->RESET_INTERRUPT &=
	~AT_SHA2_INTERRUPT_STATUS__HMAC_DONE__MASK;
    AT_SHA2_INTERRUPT_MASK__HMAC_DONE__CLR(
	CMSDK_SHA2->INTERRUPT_MASK);

    if (IS_ALIGNED(digest, sizeof(uint32_t))) {
	uint32_t *word_digest = (uint32_t *)digest;
	// NOTE: digest gets reset when SHA is disabled
	word_digest[0] = CMSDK_SHA2->DIGEST0;
	word_digest[1] = CMSDK_SHA2->DIGEST1;
	word_digest[2] = CMSDK_SHA2->DIGEST2;
	word_digest[3] = CMSDK_SHA2->DIGEST3;
	word_digest[4] = CMSDK_SHA2->DIGEST4;
	word_digest[5] = CMSDK_SHA2->DIGEST5;
	word_digest[6] = CMSDK_SHA2->DIGEST6;
	word_digest[7] = CMSDK_SHA2->DIGEST7;
    } else {
	atm_set_le32(&digest[0], CMSDK_SHA2->DIGEST0);
	atm_set_le32(&digest[4], CMSDK_SHA2->DIGEST1);
	atm_set_le32(&digest[8], CMSDK_SHA2->DIGEST2);
	atm_set_le32(&digest[12], CMSDK_SHA2->DIGEST3);
	atm_set_le32(&digest[16], CMSDK_SHA2->DIGEST4);
	atm_set_le32(&digest[20], CMSDK_SHA2->DIGEST5);
	atm_set_le32(&digest[24], CMSDK_SHA2->DIGEST6);
	atm_set_le32(&digest[28], CMSDK_SHA2->DIGEST7);
    }
#if (ATM_SHA2_API == SHA_MULTI_CTXT)
    ctxt->flags |= SHA2_CTXT_FLAGS_FINI;
    DEBUG_TRACE_COND(ATM_SHA2_DEBUG, "SHA2 (%p) finalized", ctxt);
    return ATM_SHA256_RES_SUCCESS;
#else
    return digest;
#endif
}

#if (ATM_SHA2_API == SHA_SINGLE_CTXT)
static atm_sha256_res_t
atm_sha256_digest_by_mode(atm_sha256_params_t const *params, void const *input,
    uint32_t input_len, uint8_t digest[SHA256_DIG_LEN], bool pio)
{
    atm_sha256_res_t ret = atm_sha256_init(params);

    if (ret != ATM_SHA256_RES_SUCCESS) {
	return ret;
    }
    if (pio) {
	ret = atm_sha256_update_pio(input, input_len);
    } else {
	ret = atm_sha256_update(input, input_len);
    }
    if (ret != ATM_SHA256_RES_SUCCESS) {
	goto digest_done;
    }
    atm_sha256_final(digest);
    ret = ATM_SHA256_RES_SUCCESS;
digest_done:
    atm_sha256_disable();
    return ret;
}

atm_sha256_res_t atm_sha256_digest(atm_sha256_params_t const *params,
    void const *input, uint32_t input_len, uint8_t digest[SHA256_DIG_LEN])
{
    return atm_sha256_digest_by_mode(params, input, input_len, digest, false);
}

atm_sha256_res_t atm_sha256_digest_pio(atm_sha256_params_t const *params,
    void const *input, uint32_t input_len, uint8_t digest[SHA256_DIG_LEN])
{
    return atm_sha256_digest_by_mode(params, input, input_len, digest, true);
}

#endif
