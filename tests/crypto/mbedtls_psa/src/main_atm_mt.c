/**
 *******************************************************************************
 *
 * @file main_atm_mt.c
 *
 * @brief Multithreaded stress tests for the Atmosic SHA-2 PSA wrapper
 *
 * Exercises the synchronization points in
 * openair/modules/hal_atmosic/drivers/atm_sha2/psa_sha256.c that protect
 * the shared HW engine, the pool table (hw_pool[]), and the
 * sha2_clk_en_ref refcount when multiple threads drive PSA hash
 * operations concurrently. Most tests spawn CONFIG_ATM_SHA2_HW_MAX_CONTEXTS
 * worker threads; the clone-race test spawns half that, since each of its
 * workers holds two contexts at once. Each test releases its workers through
 * a single barrier semaphore, joins them, and verifies digests against
 * single-threaded ground truth.
 *
 * Gated at the CMakeLists.txt level on CONFIG_ATM_SHA2_API_MULTI and
 * CONFIG_MULTITHREADING.
 *
 * Copyright (C) Atmosic 2026
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 *
 *******************************************************************************
 */

#include <string.h>

#include <zephyr/kernel.h>
#include <zephyr/sys/util.h>
#include <zephyr/ztest.h>

#include <psa/crypto.h>

#define MT_WORKERS      CONFIG_ATM_SHA2_HW_MAX_CONTEXTS
#define MT_STACK_SIZE   2048
#define MT_PRIO         K_PRIO_PREEMPT(5)
#define MT_ITERATIONS   16
#define MT_MSG_LEN      1024
#define MT_JOIN_TIMEOUT K_SECONDS(10)

#define MT_DIGEST_LEN PSA_HASH_LENGTH(PSA_ALG_SHA_256)

/* Number of single-threaded ground-truth hashes to run after each storm
 * to detect leaked pool slots or stuck clock refcounts that don't perturb
 * the storm's own digests. Sized at 4x MT_WORKERS so an off-by-one slot
 * leak per iteration is guaranteed to exhaust the pool. */
#define MT_POST_SANITY_HASHES (MT_WORKERS * 4)

static K_THREAD_STACK_ARRAY_DEFINE(mt_stacks, MT_WORKERS, MT_STACK_SIZE);
static struct k_thread mt_threads[MT_WORKERS];
static struct k_sem mt_start_sem;

/* Per-worker context populated by the test, consumed by the worker, and
 * inspected by the test after the join. Each worker writes only its own
 * slot, so the array doesn't need additional synchronization. */
struct mt_ctx {
	const uint8_t *msg;
	size_t msg_len;
	size_t chunk;
	psa_status_t status;
	uint8_t out[MT_DIGEST_LEN];
};

/* Compute SHA-256 single-threaded via the one-shot wrapper path. Used to
 * generate ground truth before spawning workers (so the HW is quiescent
 * and the result is trusted). */
static void mt_ground_truth(const uint8_t *msg, size_t len, uint8_t out[MT_DIGEST_LEN])
{
	size_t out_len = 0;
	psa_status_t s = psa_hash_compute(PSA_ALG_SHA_256, msg, len, out, MT_DIGEST_LEN, &out_len);
	zassert_equal(s, PSA_SUCCESS, "ground truth compute failed (%d)", (int)s);
	zassert_equal(out_len, MT_DIGEST_LEN);
}

/* Procedurally generate a per-worker message. Distinct content per
 * worker maximizes the chance that a HW-register interleaving corrupts
 * one worker's intermediate digest with another's state. */
static void mt_fill_message(unsigned int worker_id, uint8_t *buf, size_t len)
{
	for (size_t i = 0; i < len; i++) {
		buf[i] = (uint8_t)((worker_id * 131u) + (i * 17u) + 0x5Au);
	}
}

/* Spawn @n_workers threads each running @worker with a pointer into
 * @ctx_array (element size @ctx_size), release them simultaneously via
 * the barrier semaphore, and join them all. @n_workers must not exceed
 * MT_WORKERS (the size of the thread/stack arrays). Caller is responsible
 * for ctx population and post-condition assertions. */
static void mt_run(k_thread_entry_t worker, void *ctx_array, size_t ctx_size, int n_workers)
{
	k_sem_init(&mt_start_sem, 0, n_workers);

	/* Force the kernel to time-slice at the worker priority so the
	 * sysclock tick can preempt a worker mid-PSA call, splitting the
	 * wrapper's save/op/restore sequence across threads. Without this,
	 * equal-priority threads run to completion and the per-call
	 * save/restore makes the workers look serialized. */
	k_sched_time_slice_set(1, MT_PRIO);

	for (int i = 0; i < n_workers; i++) {
		void *slot = (uint8_t *)ctx_array + (i * ctx_size);
		k_thread_create(&mt_threads[i], mt_stacks[i], MT_STACK_SIZE, worker, slot, NULL,
				NULL, MT_PRIO, 0, K_NO_WAIT);
	}
	/* Let every worker reach k_sem_take before we release the barrier
	 * so all workers race from the same starting line. */
	k_msleep(10);
	for (int i = 0; i < n_workers; i++) {
		k_sem_give(&mt_start_sem);
	}
	for (int i = 0; i < n_workers; i++) {
		zassert_ok(k_thread_join(&mt_threads[i], MT_JOIN_TIMEOUT),
			   "worker %d join timed out", i);
	}

	/* Restore the kernel default so subsequent tests aren't perturbed. */
	k_sched_time_slice_set(0, 0);
}

/* Run a burst of single-threaded ground-truth hashes after a storm to
 * detect leaked pool slots or a stuck clock-enable refcount that didn't
 * manifest as a digest mismatch during the storm itself. A leaked slot
 * per iteration is guaranteed to exhaust the pool within a few calls. */
static void mt_post_sanity(void)
{
	uint8_t sanity[MT_DIGEST_LEN];

	for (int i = 0; i < MT_POST_SANITY_HASHES; i++) {
		mt_ground_truth((const uint8_t *)"abc", 3, sanity);
	}
}

/* Worker: multipart hash of ctx->msg, finishing into ctx->out. */
static void mt_multipart_worker(void *p1, void *p2, void *p3)
{
	ARG_UNUSED(p2);
	ARG_UNUSED(p3);
	struct mt_ctx *c = p1;
	psa_hash_operation_t op = PSA_HASH_OPERATION_INIT;
	size_t out_len = 0;

	k_sem_take(&mt_start_sem, K_FOREVER);

	c->status = psa_hash_setup(&op, PSA_ALG_SHA_256);
	if (c->status != PSA_SUCCESS) {
		return;
	}
	for (size_t i = 0; i < c->msg_len; i += c->chunk) {
		size_t n = MIN(c->chunk, c->msg_len - i);
		c->status = psa_hash_update(&op, c->msg + i, n);
		if (c->status != PSA_SUCCESS) {
			(void)psa_hash_abort(&op);
			return;
		}
	}
	c->status = psa_hash_finish(&op, c->out, sizeof(c->out), &out_len);
	if ((c->status == PSA_SUCCESS) && (out_len != MT_DIGEST_LEN)) {
		c->status = PSA_ERROR_GENERIC_ERROR;
	}
}

ZTEST(test_mbedtls_psa, test_atm_hash_mt_independent_multipart)
{
	static uint8_t messages[MT_WORKERS][MT_MSG_LEN];
	uint8_t expected[MT_WORKERS][MT_DIGEST_LEN];
	struct mt_ctx ctxs[MT_WORKERS];

	for (int i = 0; i < MT_WORKERS; i++) {
		mt_fill_message(i, messages[i], sizeof(messages[i]));
		mt_ground_truth(messages[i], sizeof(messages[i]), expected[i]);
	}

	for (int iter = 0; iter < MT_ITERATIONS; iter++) {
		for (int i = 0; i < MT_WORKERS; i++) {
			ctxs[i] = (struct mt_ctx){
				.msg = messages[i],
				.msg_len = sizeof(messages[i]),
				/* Varied chunk sizes amplify update-path
				 * interleaving across workers. */
				.chunk = 1 + (i * 7) + (iter & 3),
				.status = PSA_ERROR_BAD_STATE,
			};
		}
		mt_run(mt_multipart_worker, ctxs, sizeof(ctxs[0]), MT_WORKERS);
		for (int i = 0; i < MT_WORKERS; i++) {
			zassert_equal(ctxs[i].status, PSA_SUCCESS, "iter %d worker %d status=%d",
				      iter, i, (int)ctxs[i].status);
			zassert_mem_equal(ctxs[i].out, expected[i], MT_DIGEST_LEN,
					  "iter %d worker %d digest mismatch", iter, i);
		}
	}

	mt_post_sanity();
}

/* Worker: setup -> finish with no update. Stresses pool_alloc and the
 * clock-enable refcount through the most compact lifecycle the wrapper
 * supports. The expected digest is SHA-256(""). */
static void mt_setup_storm_worker(void *p1, void *p2, void *p3)
{
	ARG_UNUSED(p2);
	ARG_UNUSED(p3);
	struct mt_ctx *c = p1;
	psa_hash_operation_t op = PSA_HASH_OPERATION_INIT;
	size_t out_len = 0;

	k_sem_take(&mt_start_sem, K_FOREVER);

	c->status = psa_hash_setup(&op, PSA_ALG_SHA_256);
	if (c->status != PSA_SUCCESS) {
		return;
	}
	c->status = psa_hash_finish(&op, c->out, sizeof(c->out), &out_len);
	if ((c->status == PSA_SUCCESS) && (out_len != MT_DIGEST_LEN)) {
		c->status = PSA_ERROR_GENERIC_ERROR;
	}
}

ZTEST(test_mbedtls_psa, test_atm_hash_mt_setup_storm)
{
	uint8_t expected[MT_DIGEST_LEN];
	struct mt_ctx ctxs[MT_WORKERS];

	mt_ground_truth(NULL, 0, expected);

	for (int iter = 0; iter < MT_ITERATIONS; iter++) {
		for (int i = 0; i < MT_WORKERS; i++) {
			ctxs[i] = (struct mt_ctx){
				.status = PSA_ERROR_BAD_STATE,
			};
		}
		mt_run(mt_setup_storm_worker, ctxs, sizeof(ctxs[0]), MT_WORKERS);
		for (int i = 0; i < MT_WORKERS; i++) {
			zassert_equal(ctxs[i].status, PSA_SUCCESS, "iter %d worker %d status=%d",
				      iter, i, (int)ctxs[i].status);
			zassert_mem_equal(ctxs[i].out, expected, MT_DIGEST_LEN,
					  "iter %d worker %d empty-digest mismatch", iter, i);
		}
	}

	mt_post_sanity();
}

/* Each clone-race worker holds two HW contexts (source + clone target), so
 * cap it at MT_WORKERS / 2 to avoid over-subscribing the pool. */
#define MT_CLONE_WORKERS MAX(MT_WORKERS / 2, 1)

/* Per-worker context for the clone race: each worker hashes its msg
 * twice with a divergent tail byte injected after the clone. The two
 * digests are compared against two ground-truth values populated by the
 * test before the spawn. */
struct mt_clone_ctx {
	const uint8_t *msg;
	size_t msg_len;
	uint8_t tail_src;
	uint8_t tail_dst;
	psa_status_t status;
	uint8_t out_src[MT_DIGEST_LEN];
	uint8_t out_dst[MT_DIGEST_LEN];
};

static void mt_clone_worker(void *p1, void *p2, void *p3)
{
	ARG_UNUSED(p2);
	ARG_UNUSED(p3);
	struct mt_clone_ctx *c = p1;
	psa_hash_operation_t src = PSA_HASH_OPERATION_INIT;
	psa_hash_operation_t dst = PSA_HASH_OPERATION_INIT;
	size_t len = 0;

	k_sem_take(&mt_start_sem, K_FOREVER);

	c->status = psa_hash_setup(&src, PSA_ALG_SHA_256);
	if (c->status != PSA_SUCCESS) {
		return;
	}
	c->status = psa_hash_update(&src, c->msg, c->msg_len);
	if (c->status != PSA_SUCCESS) {
		(void)psa_hash_abort(&src);
		return;
	}
	c->status = psa_hash_clone(&src, &dst);
	if (c->status != PSA_SUCCESS) {
		(void)psa_hash_abort(&src);
		return;
	}
	c->status = psa_hash_update(&src, &c->tail_src, 1);
	if (c->status != PSA_SUCCESS) {
		(void)psa_hash_abort(&src);
		(void)psa_hash_abort(&dst);
		return;
	}
	c->status = psa_hash_update(&dst, &c->tail_dst, 1);
	if (c->status != PSA_SUCCESS) {
		(void)psa_hash_abort(&src);
		(void)psa_hash_abort(&dst);
		return;
	}
	c->status = psa_hash_finish(&src, c->out_src, sizeof(c->out_src), &len);
	if (c->status != PSA_SUCCESS) {
		(void)psa_hash_abort(&dst);
		return;
	}
	c->status = psa_hash_finish(&dst, c->out_dst, sizeof(c->out_dst), &len);
}

ZTEST(test_mbedtls_psa, test_atm_hash_mt_clone_race)
{
	static uint8_t messages[MT_CLONE_WORKERS][MT_MSG_LEN];
	static uint8_t tmp[MT_MSG_LEN + 1];
	uint8_t expected_src[MT_CLONE_WORKERS][MT_DIGEST_LEN];
	uint8_t expected_dst[MT_CLONE_WORKERS][MT_DIGEST_LEN];
	struct mt_clone_ctx ctxs[MT_CLONE_WORKERS];

	for (int i = 0; i < MT_CLONE_WORKERS; i++) {
		mt_fill_message(i, messages[i], sizeof(messages[i]));
		memcpy(tmp, messages[i], sizeof(messages[i]));
		tmp[sizeof(messages[i])] = (uint8_t)(0xA0 + i);
		mt_ground_truth(tmp, sizeof(tmp), expected_src[i]);
		tmp[sizeof(messages[i])] = (uint8_t)(0x50 + i);
		mt_ground_truth(tmp, sizeof(tmp), expected_dst[i]);
	}

	for (int iter = 0; iter < MT_ITERATIONS; iter++) {
		for (int i = 0; i < MT_CLONE_WORKERS; i++) {
			ctxs[i] = (struct mt_clone_ctx){
				.msg = messages[i],
				.msg_len = sizeof(messages[i]),
				.tail_src = (uint8_t)(0xA0 + i),
				.tail_dst = (uint8_t)(0x50 + i),
				.status = PSA_ERROR_BAD_STATE,
			};
		}
		mt_run(mt_clone_worker, ctxs, sizeof(ctxs[0]), MT_CLONE_WORKERS);
		for (int i = 0; i < MT_CLONE_WORKERS; i++) {
			zassert_equal(ctxs[i].status, PSA_SUCCESS, "iter %d worker %d status=%d",
				      iter, i, (int)ctxs[i].status);
			zassert_mem_equal(ctxs[i].out_src, expected_src[i], MT_DIGEST_LEN,
					  "iter %d worker %d src digest mismatch", iter, i);
			zassert_mem_equal(ctxs[i].out_dst, expected_dst[i], MT_DIGEST_LEN,
					  "iter %d worker %d dst digest mismatch", iter, i);
		}
	}

	mt_post_sanity();
}

/* Worker: psa_hash_compute one-shot. Routes through the wrapper's
 * compute path, which uses a stack-local atm_sha2_ctxt_t and touches
 * init/update/final on the HW with no operation handle held across
 * yields. Stresses the compute-path mutex coverage. */
static void mt_compute_worker(void *p1, void *p2, void *p3)
{
	ARG_UNUSED(p2);
	ARG_UNUSED(p3);
	struct mt_ctx *c = p1;
	size_t out_len = 0;

	k_sem_take(&mt_start_sem, K_FOREVER);

	c->status = psa_hash_compute(PSA_ALG_SHA_256, c->msg, c->msg_len, c->out, sizeof(c->out),
				     &out_len);
	if ((c->status == PSA_SUCCESS) && (out_len != MT_DIGEST_LEN)) {
		c->status = PSA_ERROR_GENERIC_ERROR;
	}
}

ZTEST(test_mbedtls_psa, test_atm_hash_mt_compute_oneshot)
{
	static uint8_t messages[MT_WORKERS][MT_MSG_LEN];
	uint8_t expected[MT_WORKERS][MT_DIGEST_LEN];
	struct mt_ctx ctxs[MT_WORKERS];

	for (int i = 0; i < MT_WORKERS; i++) {
		mt_fill_message(i + MT_WORKERS, messages[i], sizeof(messages[i]));
		mt_ground_truth(messages[i], sizeof(messages[i]), expected[i]);
	}

	for (int iter = 0; iter < MT_ITERATIONS; iter++) {
		for (int i = 0; i < MT_WORKERS; i++) {
			ctxs[i] = (struct mt_ctx){
				.msg = messages[i],
				.msg_len = sizeof(messages[i]),
				.status = PSA_ERROR_BAD_STATE,
			};
		}
		mt_run(mt_compute_worker, ctxs, sizeof(ctxs[0]), MT_WORKERS);
		for (int i = 0; i < MT_WORKERS; i++) {
			zassert_equal(ctxs[i].status, PSA_SUCCESS, "iter %d worker %d status=%d",
				      iter, i, (int)ctxs[i].status);
			zassert_mem_equal(ctxs[i].out, expected[i], MT_DIGEST_LEN,
					  "iter %d worker %d digest mismatch", iter, i);
		}
	}

	mt_post_sanity();
}

/* Per-worker context for the mixed abort/finish test. @do_abort selects
 * the lifecycle ending: false runs setup -> update -> finish (digest
 * compared to ground truth), true runs setup -> update -> abort (only
 * the status path is verified). */
struct mt_abort_ctx {
	const uint8_t *msg;
	size_t msg_len;
	bool do_abort;
	psa_status_t status;
	uint8_t out[MT_DIGEST_LEN];
};

static void mt_abort_worker(void *p1, void *p2, void *p3)
{
	ARG_UNUSED(p2);
	ARG_UNUSED(p3);
	struct mt_abort_ctx *c = p1;
	psa_hash_operation_t op = PSA_HASH_OPERATION_INIT;
	size_t out_len = 0;

	k_sem_take(&mt_start_sem, K_FOREVER);

	c->status = psa_hash_setup(&op, PSA_ALG_SHA_256);
	if (c->status != PSA_SUCCESS) {
		return;
	}
	c->status = psa_hash_update(&op, c->msg, c->msg_len);
	if (c->status != PSA_SUCCESS) {
		(void)psa_hash_abort(&op);
		return;
	}
	if (c->do_abort) {
		c->status = psa_hash_abort(&op);
	} else {
		c->status = psa_hash_finish(&op, c->out, sizeof(c->out), &out_len);
		if ((c->status == PSA_SUCCESS) && (out_len != MT_DIGEST_LEN)) {
			c->status = PSA_ERROR_GENERIC_ERROR;
		}
	}
}

ZTEST(test_mbedtls_psa, test_atm_hash_mt_mixed_abort)
{
	static uint8_t messages[MT_WORKERS][MT_MSG_LEN];
	uint8_t expected[MT_WORKERS][MT_DIGEST_LEN];
	struct mt_abort_ctx ctxs[MT_WORKERS];

	for (int i = 0; i < MT_WORKERS; i++) {
		mt_fill_message(i * 3 + 1, messages[i], sizeof(messages[i]));
		mt_ground_truth(messages[i], sizeof(messages[i]), expected[i]);
	}

	for (int iter = 0; iter < MT_ITERATIONS; iter++) {
		for (int i = 0; i < MT_WORKERS; i++) {
			ctxs[i] = (struct mt_abort_ctx){
				.msg = messages[i],
				.msg_len = sizeof(messages[i]),
				/* Alternate finishers and aborters; flip the
				 * pattern each iteration so every worker
				 * exercises both lifecycle endings. */
				.do_abort = ((i + iter) & 1) != 0,
				.status = PSA_ERROR_BAD_STATE,
			};
		}
		mt_run(mt_abort_worker, ctxs, sizeof(ctxs[0]), MT_WORKERS);
		for (int i = 0; i < MT_WORKERS; i++) {
			zassert_equal(ctxs[i].status, PSA_SUCCESS,
				      "iter %d worker %d (do_abort=%d) status=%d", iter, i,
				      (int)ctxs[i].do_abort, (int)ctxs[i].status);
			if (!ctxs[i].do_abort) {
				zassert_mem_equal(ctxs[i].out, expected[i], MT_DIGEST_LEN,
						  "iter %d worker %d digest mismatch", iter, i);
			}
		}
	}

	mt_post_sanity();
}
