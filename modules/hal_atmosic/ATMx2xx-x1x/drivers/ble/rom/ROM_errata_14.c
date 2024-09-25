/**
 *******************************************************************************
 *
 * @file ROM_errata_14.c
 *
 * @brief ROM_errata #14
 *
 * Copyright (C) Atmosic 2021-2023
 *
 *******************************************************************************
 */

#include <soc.h>
#include <zephyr/init.h>

#include "arch.h"
#include "rwip_config.h"
#include "rep_vec.h"
#include "co_list.h"
#include "reg_em_ble_rx_desc.h"
#include "hw_cfg.h"
#include "ROM_errata_15.h"

struct lld_env_s {
    uint8_t resv0[208];
    uint8_t curr_rxdesc_index;
    uint8_t resv1[39];
};

struct lld_iproc_info
{
    uint8_t resv[16];
    uint16_t instant;
    uint8_t type;
};

struct lld_con_env_s {
    uint8_t resv0[64];
    struct lld_iproc_info iproc;
    uint8_t resv3[42];
    uint16_t sl;
    uint16_t resv4[2];
    uint16_t con_evt;
    uint8_t resv1[23];
    int8_t last_rssi;
    uint8_t resv2[2];
};

extern struct lld_env_s lld_env;
extern struct lld_con_env_s *lld_con_env[BLE_ACTIVITY_MAX];
extern void lld_con_sched(uint8_t link_id, uint32_t clock, bool sync);

#define AVG_RSSI_NUM 3
#define P_MODE_RSSI_THRESHOLD -80
#define D_MODE_RSSI_THRESHOLD -70
#define SYNC_MISS_OBSERVE_NUM 6 // <= 32
#define SYNC_MISS_THRESHOLD 2
#define SYNC_MISS_ERR 0x01

enum {
    // disable dynamic control
    RF_IDLE_MODE,
    // de-sense mode for noisy environment
    RF_D_MODE,
    // performance mode for long range environment
    RF_P_MODE,
};
static uint8_t mode;
static uint8_t rssi_idx;
static int8_t last_n_rssi[AVG_RSSI_NUM];
static uint32_t sync_miss_mask;

__INLINE uint32_t lld_popcount(uint32_t x)
{
#ifdef __GNUC__
    return __builtin_popcount(x);
#else
    uint32_t cnt = 0;
    while (x) {
	x &= (x - 1);
	cnt++;
    }
    return cnt;
#endif
}

__ramfunc static rep_vec_err_t
patched_lld_con_sched(uint8_t link_id, uint32_t clock,  bool sync)
{
    // lld_con_sched only tries to enter slave latency when the latest
    // Rx attempt was successful
    uint8_t rx_idx =
	(lld_env.curr_rxdesc_index - 1 + EM_BLE_RX_DESC_NB) % EM_BLE_RX_DESC_NB;
    uint16_t rx_status = em_ble_rxstatce_get(rx_idx);

    bool enable_latency = sync && !rx_status;

    // Dynamic AGC det step control
    struct lld_con_env_s *con_par = lld_con_env[link_id];

    LLD_CON_SCHED(con_par->iproc.type, enable_latency, con_par->sl,
	con_par->iproc.instant, con_par->con_evt, link_id, clock);

    if (mode == RF_IDLE_MODE) {
	return RV_DONE;
    }

    sync_miss_mask <<= 1;
    if (rx_status & SYNC_MISS_ERR) {
	sync_miss_mask |= 1;
    } else {
	last_n_rssi[rssi_idx++] = con_par->last_rssi;
	rssi_idx %= AVG_RSSI_NUM;
    }
    // calculate avg rssi
    int16_t rssi_sum = 0;
    for (int i = 0;i < AVG_RSSI_NUM;i++) {
	rssi_sum += last_n_rssi[i];
    }
    int16_t avg_rssi = rssi_sum / AVG_RSSI_NUM;

    if (mode == RF_D_MODE) {
	if (avg_rssi < P_MODE_RSSI_THRESHOLD) {
	    mode = RF_P_MODE;
	    hw_cfg_max_range_perf();
	}
    } else if (avg_rssi > D_MODE_RSSI_THRESHOLD) {
	uint32_t sync_miss =
	    sync_miss_mask & ((1 << SYNC_MISS_OBSERVE_NUM) - 1);
	if (lld_popcount(sync_miss) > SYNC_MISS_THRESHOLD) {
	    mode = RF_D_MODE;
	    hw_cfg_max_interference_perf();
	    sync_miss_mask = 0;
	}
    }
    return RV_DONE;
}

static void lld_dynamic_rf_mode_control(bool enable)
{
    hw_cfg_max_interference_perf();
    if (enable) {
	mode = RF_D_MODE;
    } else {
	mode = RF_IDLE_MODE;
	sync_miss_mask = 0;
	memset(last_n_rssi, 0, sizeof(last_n_rssi));
    }
}

static int enable_ROM_errata_14(void)
{
    hw_cfg_dynamic_rf_mode_ctrl_reg(lld_dynamic_rf_mode_control);
    // hijack lld_con_sched
    RV_LLD_CON_SCHED_ADD(patched_lld_con_sched);
    return 0;
}

SYS_INIT(enable_ROM_errata_14, PRE_KERNEL_2,
	 CONFIG_KERNEL_INIT_PRIORITY_DEFAULT);
