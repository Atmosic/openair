/**
 *******************************************************************************
 *
 * @file workarounds.c
 *
 * @brief SoC initialization workarounds
 *
 * Copyright (C) Atmosic 2018-2024
 *
 *******************************************************************************
 */

#include "arch.h"
#include "at_wrpr.h"

#ifdef APB0_NONSECURE_BASE
#define USE_SEC_JRNL
#endif

#if ((defined(PLF_NVDS) && PLF_NVDS) || defined(USE_SEC_JRNL))
#include <inttypes.h>
#include <stdint.h>

#include "workarounds.h"
#include "calibration.h"
#include "spi.h"

#ifdef USE_SEC_JRNL
#include "sec_jrnl.h"
#else
#include "nvds.h"
#endif

struct wa_wrpr_state {
    uint16_t touched;
    uint32_t *ctrl_save;
};

struct wa_module_state {
    struct wa_wrpr_state apb0;
    struct wa_wrpr_state apb1;
#ifdef APB2_NUM_MODULES
    struct wa_wrpr_state apb2;
#endif
};

#ifndef APB0_NONSECURE_BASE
#define APB0_NONSECURE_BASE CMSDK_APB_BASE
#endif
#ifndef APB1_NONSECURE_BASE
#define APB1_NONSECURE_BASE CMSDK_APB1_BASE
#endif

static void
wa_enable_module(struct wa_module_state *mod_state, volatile const void *addr)
{
    uintptr_t address = (uintptr_t)addr;
    struct wa_wrpr_state *state;
    int i;

    if ((address >= APB0_NONSECURE_BASE) &&
	(address < APB0_NONSECURE_BASE + (APB_MOD_SIZE * APB0_NUM_MODULES))) {
	state = &mod_state->apb0;
	i = (address - APB0_NONSECURE_BASE) / APB_MOD_SIZE;
    } else if ((address >= APB1_NONSECURE_BASE) &&
	(address < APB1_NONSECURE_BASE + (APB_MOD_SIZE * APB1_NUM_MODULES))) {
	state = &mod_state->apb1;
	i = (address - APB1_NONSECURE_BASE) / APB_MOD_SIZE;
    }
#ifdef APB2_NUM_MODULES
    else if ((address >= APB2_NONSECURE_BASE) &&
	(address < APB2_NONSECURE_BASE + (APB_MOD_SIZE * APB2_NUM_MODULES))) {
	state = &mod_state->apb2;
	i = (address - APB2_NONSECURE_BASE) / APB_MOD_SIZE;
    }
#endif
    else {
	return;
    }

    uint32_t mask = 0x1 << i;
    if (state->touched & mask) {
	// Already enabled
	return;
    }
    uint32_t volatile *ctrl_ptr = module_to_ctrl(addr);
    if (!ctrl_ptr) {
	return;
    }
    uint32_t ctrl = *ctrl_ptr;
    if (ctrl == WRPR_CTRL__CLK_ENABLE) {
	// Already enabled
	return;
    }

    // Leave out of reset when restoring
    state->ctrl_save[i] = ctrl & ~WRPR_CTRL__SRESET;
    state->touched |= mask;

    // Make sure module has clock and is out of reset
    *ctrl_ptr = WRPR_CTRL__CLK_ENABLE;
}

#ifndef CMSDK_WRPR
#define CMSDK_WRPR CMSDK_WRPR0_NONSECURE
#endif
#ifndef CMSDK_WRPR1
#define CMSDK_WRPR1 CMSDK_WRPR1_NONSECURE
#endif

static void
wa_restore_modules(struct wa_module_state *mod_state)
{
    int i;
    uint16_t touched;

    for (i=0,touched=mod_state->apb0.touched; i<APB0_NUM_MODULES;
	i++,touched>>=1) {
	if (touched & 0x1) {
	    (&CMSDK_WRPR->APB0_CTRL)[i] = mod_state->apb0.ctrl_save[i];
	}
    }

    for (i=0,touched=mod_state->apb1.touched; i<APB1_NUM_MODULES;
	i++,touched>>=1) {
	if (touched & 0x1) {
	    (&CMSDK_WRPR1->APB0_CTRL)[i] = mod_state->apb1.ctrl_save[i];
	}
    }

#ifdef APB2_NUM_MODULES
    for (i=0,touched=mod_state->apb2.touched; i<APB2_NUM_MODULES;
	i++,touched>>=1) {
	if (touched & 0x1) {
	    (&CMSDK_WRPR2_NONSECURE->APB0_CTRL)[i] = mod_state->apb2.ctrl_save[i];
	}
    }
#endif
}

struct mem_rmw {
    union {
	struct {
	    volatile uint32_t *addr;
	    uint32_t data;
	    uint32_t mask;
	} __PACKED w;
	struct {
	    volatile uint16_t *addr;
	    uint16_t data;
	    uint16_t mask;
	} __PACKED s;
	struct {
	    volatile uint8_t *addr;
	    uint8_t data;
	    uint8_t mask;
	} __PACKED b;
    };
};

struct pmu_w {
    uint8_t block;
    uint8_t addr;
    uint32_t data;
} __PACKED;

static int wa_walk_callback(uint8_t tag,
#ifdef USE_SEC_JRNL
    sec_jrnl_tag_len_t len,
    sec_jrnl_ret_status_t (*nvds_read)(uint32_t len, uint8_t *buf),
#else
    uint32_t addr, nvds_tag_len_t len,
    void (*nvds_read)(uint32_t addr, uint32_t len, uint8_t *buf),
#endif
    void *ctx)
{
    struct wa_module_state *mod_state = ctx;

    switch (tag) {
	case ATM_TAG_PMU_W: {
	    struct pmu_w pmu_op;
#ifdef USE_SEC_JRNL
	    sec_jrnl_ret_status_t ret = nvds_read(len, (uint8_t *)&pmu_op);
	    if (ret != SEC_JRNL_OK) {
		DEBUG_TRACE("Invalid nvds_read parameters");
		break;
	    }
#else
	    nvds_read(addr, len, (uint8_t*)&pmu_op);
#endif
	    DEBUG_TRACE("Writing %#" PRIx32 " to PMU block %#x, addr %#x",
		pmu_op.data, pmu_op.block, pmu_op.addr);
	    wa_enable_module(mod_state, spi_pmu.base);
	    spi_pmuradio_write_word(&spi_pmu, pmu_op.block, pmu_op.addr,
		pmu_op.data);
#if (PLF_DEBUG)
	    uint32_t read_back = spi_pmuradio_read_word(&spi_pmu, pmu_op.block,
		pmu_op.addr);
	    ASSERT_INFO(pmu_op.data == read_back, pmu_op.data, read_back);
#endif
	    break;
	}
	case ATM_TAG_MEM_W: {
	    struct mem_rmw rmw_op;
#ifdef USE_SEC_JRNL
	    sec_jrnl_ret_status_t ret = nvds_read(len, (uint8_t *)&rmw_op);
	    if (ret != SEC_JRNL_OK) {
		DEBUG_TRACE("Invalid nvds_read parameters");
		break;
	    }
#else
	    nvds_read(addr, len, (uint8_t*)&rmw_op);
#endif
	    if (len == __OFFSET(rmw_op.w, mask)) {
		wa_enable_module(mod_state, rmw_op.w.addr);
		*rmw_op.w.addr = rmw_op.w.data;
	    } else if (len == __OFFSET(rmw_op.s, mask)) {
		wa_enable_module(mod_state, rmw_op.s.addr);
		*rmw_op.s.addr = rmw_op.s.data;
	    } else if (len == __OFFSET(rmw_op.b, mask)) {
		wa_enable_module(mod_state, rmw_op.b.addr);
		*rmw_op.b.addr = rmw_op.b.data;
	    }
	    break;
	}
	case ATM_TAG_MEM_RMW: {
	    struct mem_rmw rmw_op;
#ifdef USE_SEC_JRNL
	    sec_jrnl_ret_status_t ret = nvds_read(len, (uint8_t *)&rmw_op);
	    if (ret != SEC_JRNL_OK) {
		DEBUG_TRACE("Invalid nvds_read parameters");
		break;
	    }
#else
	    nvds_read(addr, len, (uint8_t*)&rmw_op);
#endif
	    if (len == sizeof(rmw_op.w)) {
		wa_enable_module(mod_state, rmw_op.w.addr);
		*rmw_op.w.addr = (*rmw_op.w.addr & ~rmw_op.w.mask) |
		    (rmw_op.w.data & rmw_op.w.mask);
	    } else if (len == sizeof(rmw_op.s)) {
		wa_enable_module(mod_state, rmw_op.s.addr);
		*rmw_op.s.addr = (*rmw_op.s.addr & ~rmw_op.s.mask) |
		    (rmw_op.s.data & rmw_op.s.mask);
	    } else if (len == sizeof(rmw_op.b)) {
		wa_enable_module(mod_state, rmw_op.b.addr);
		*rmw_op.b.addr = (*rmw_op.b.addr & ~rmw_op.b.mask) |
		    (rmw_op.b.data & rmw_op.b.mask);
	    }
	    break;
	}
	default:
	    break;
    }
    return 0;
}

void
workarounds_init(void)
{
    uint32_t apb0_ctrl_save[APB0_NUM_MODULES];
    uint32_t apb1_ctrl_save[APB1_NUM_MODULES];
#ifdef APB2_NUM_MODULES
    uint32_t apb2_ctrl_save[APB2_NUM_MODULES];
#endif
    struct wa_module_state mod_state = {
	{ 0, apb0_ctrl_save },
	{ 0, apb1_ctrl_save },
#ifdef APB2_NUM_MODULES
	{ 0, apb2_ctrl_save },
#endif
    };

#ifdef USE_SEC_JRNL
    nsc_sec_jrnl_walk_init_ctx();
    uint8_t tag = SEC_JRNL_INVALID_TAG;
    sec_jrnl_tag_len_t len = 0;
    for (;;) {
	sec_jrnl_ret_status_t ret = nsc_sec_jrnl_walk_tag(&tag, &len);
	if (ret != SEC_JRNL_OK) {
	    break;
	}
	wa_walk_callback(tag, len, nsc_sec_jrnl_walk_read_curr_tag, &mod_state);
    }
#else
    nvds_walk(wa_walk_callback, &mod_state);
#endif

    wa_restore_modules(&mod_state);
}

#endif // ((PLF_NVDS) || defined(USE_SEC_JRNL)
