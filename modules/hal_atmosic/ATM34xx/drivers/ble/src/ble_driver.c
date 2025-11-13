/**
 *******************************************************************************
 *
 * @file ble_driver.c
 *
 * @brief Atmosic BLE link layer - HCI driver
 *
 * Copyright (C) Atmosic 2023-2025
 *
 *******************************************************************************
 */

#include <zephyr/kernel.h>
#include "arch.h"

#define DT_DRV_COMPAT atmosic_ble

#if CONFIG_ATM_ATLC

#include <errno.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#include <soc.h>
#include <zephyr/init.h>
#include <zephyr/device.h>
#include <zephyr/sys_clock.h>

#include <zephyr/random/random.h>
#include <zephyr/sys/byteorder.h>

#include <zephyr/pm/pm.h>
#include <zephyr/pm/policy.h>
#include <zephyr/logging/log.h>
LOG_MODULE_REGISTER(atm_ble_driver, LOG_LEVEL_INF);

#include "ble_driver.h"
#include "pc_ctr_sleep.h"
#include "radio_hal_common.h"
#include "timer.h"
#include "vectors.h"

#include "at_clkrstgen.h"

#ifdef CONFIG_ATM_BLE
#include <zephyr/bluetooth/bluetooth.h>
#include <zephyr/bluetooth/hci.h>
#include <zephyr/drivers/bluetooth.h>

#include "atm_bthci_utils.h"
#include "pc_ctr.h"
#include "wsf_types.h"
#include "wsf_msg.h"
#include "chci_api.h"
#include "chci_tr.h"
#endif

#define BLE_GIVE_IRQn SW_2_IRQn
#define BLE_GIVE_MAC_IRQn SW_3_IRQn
#define BLE_THREAD_STACK_SIZE \
	COND_CODE_0(IS_EMPTY(CONFIG_BT_RX_STACK_SIZE), \
		(CONFIG_ATM_BLE_STACK_SIZE), \
		(MAX(CONFIG_BT_RX_STACK_SIZE, CONFIG_ATM_BLE_STACK_SIZE)))

static K_SEM_DEFINE(ble_sem, 0, 1);
struct k_thread ble_thread_data;
static K_KERNEL_STACK_DEFINE(ble_thread_stack, BLE_THREAD_STACK_SIZE);

#ifdef CONFIG_ATM_BLE
struct hci_data {
    bt_hci_recv_t recv;
};

#ifndef CONFIG_NEWLIB_LIBC
// FIXME: temporarily needed by pal_crypto.c
int rand(void)
{
    return (sys_rand32_get());
}
#endif

void ChciTrInit(uint16_t maxAclLen, uint16_t maxIsoSduLen)
{
}

static bool is_hci_event_discardable(const uint8_t *evt_data)
{
    uint8_t evt_type = evt_data[0];

    switch (evt_type) {
	case BT_HCI_EVT_LE_META_EVENT: {
	    uint8_t subevt_type = evt_data[sizeof(struct bt_hci_evt_hdr)];

	    switch (subevt_type) {
		case BT_HCI_EVT_LE_ADVERTISING_REPORT:
		case BT_HCI_EVT_LE_EXT_ADVERTISING_REPORT:
		    return true;
		default:
		    return false;
	    }
	}
	default:
	    return false;
    }
}

static bool is_open;

void ChciTrWrite(uint8_t prot, uint8_t type, uint16_t len, uint8_t *pData)
{
    struct net_buf *nbuf = NULL;

    if (!is_open) {
	LOG_ERR("Device is not Open");
	goto done;
    }
    switch (type) {
	case CHCI_TR_TYPE_EVT: {
	    uint8_t evt = pData[0];
	    bool discardable = is_hci_event_discardable(pData);
	    nbuf = bt_buf_get_evt(evt, discardable,
		discardable ? K_NO_WAIT : K_FOREVER);
	    ATM_BTHCI_DUMP_HCI_PKT(ATM_HCI_DUMP_EVT, pData, len);
	} break;
	case CHCI_TR_TYPE_ACL: {
	    ATM_BTHCI_DUMP_HCI_PKT(ATM_HCI_DUMP_ACL_IN, pData, len);
	    nbuf = bt_buf_get_rx(BT_BUF_ACL_IN, K_FOREVER);
	} break;
	case CHCI_TR_TYPE_ISO: {
	    ATM_BTHCI_DUMP_HCI_PKT(ATM_HCI_DUMP_ISO_IN, pData, len);
	    nbuf = bt_buf_get_rx(BT_BUF_ISO_IN, K_MSEC(250));
	} break;
	default:
	    __ASSERT(0, "Unknown Type = %d with Len = %d", type, len);
	    break;
    }

    if (nbuf) {
	size_t buf_tailroom = net_buf_tailroom(nbuf);
	if (buf_tailroom < len) {
	    LOG_ERR("Not enough space in buffer %u/%zu", len, buf_tailroom);
	    net_buf_unref(nbuf);
	    goto done;
	}

	net_buf_add_mem(nbuf, pData, len);

	LOG_DBG("Packet in: type:%u len:%u", nbuf->data[0], nbuf->len);

	struct device const *dev = DEVICE_DT_GET(DT_DRV_INST(0));
	struct hci_data *hci = dev->data;
	hci->recv(dev, nbuf);
    } else {
	LOG_DBG("nbuf == NULL");
    }

done:
    chciTrSendComplete();
}
#endif // CONFIG_ATM_BLE

#ifdef CONFIG_PM
static int32_t plf_sleep_min = 0xa0;
#endif

static void
ble_to_deep_sleep(bool *pseq_sleep, uint32_t *int_set, bool ble_asleep,
    int32_t ble_sleep_duration)
{
#ifndef CONFIG_PM
    return;
#else
    k_ticks_t ticks = K_TICKS_FOREVER;
    // ble_sleep_duration == 0 means no timer (external wakeup only)
    if (ble_sleep_duration) {
	// @note: Make any necessary timing adjustments to exit-latency-us
	// under power-states in the device tree - not here.
	if (ble_sleep_duration < plf_sleep_min) {
	    // Too short; don't involve PSEQ
	    return;
	}

	// Convert lpcycles to ticks
	ticks = atm_lpc_to(Z_HZ_ticks, ble_sleep_duration);
    }

    pm_policy_state_lock_put(PM_STATE_SUSPEND_TO_RAM, PM_ALL_SUBSTATES);
    k_sem_take(&ble_sem, K_TICKS(ticks));
    pm_policy_state_lock_get(PM_STATE_SUSPEND_TO_RAM, PM_ALL_SUBSTATES);
    *pseq_sleep = true;
#endif
}

/*
 * @note: Can be called from zero-latency ATLC_IRQn, so kernel calls are
 * not permitted.
 */
static void ble_wake_thread(void)
{
    NVIC_SetPendingIRQ(BLE_GIVE_IRQn);
}

static void
ble_thread(void *p1, void *p2, void *p3)
{
    ARG_UNUSED(p1);
    ARG_UNUSED(p2);
    ARG_UNUSED(p3);

    // Wakes ble_thread to see if ATLC can be put to sleep
    atm_mac_register_idle_callback(ble_wake_thread);
#ifdef CONFIG_ATM_BLE
    // Wakes ble_thread to wake up ATLC or process events
    WsfOsRegisterWakeup(ble_wake_thread);
#endif

#ifdef CONFIG_PM
    pm_policy_state_lock_get(PM_STATE_SUSPEND_TO_RAM, PM_ALL_SUBSTATES);
#endif
    for (;;) {
#ifdef CONFIG_ATM_BLE
	bool more = pc_ctr_schedule();
#endif

	rep_vec_invoke(rv_plf_schedule, NULL);

#ifdef CONFIG_ATM_BLE
	if (more) {
	    continue;
	}
#endif

	unsigned int key = irq_lock();

	bool atlc_asleep = false;
	bool disable_deep_sleep = !IS_ENABLED(CONFIG_ATLC_DEEP_SLEEP);
	int32_t atlc_sleep_duration = 0;
	enum pc_ctr_sleep_e sleep_status;
	GLOBAL_INT_DISABLE();
	sleep_status = pc_ctr_sleep(&atlc_sleep_duration, disable_deep_sleep);
	GLOBAL_INT_RESTORE();
	switch (sleep_status) {
	    case PC_CTR_ATLC_WAS_ASLEEP:
		atlc_asleep = true;
		// Fall through...
	    case PC_CTR_ATLC_TO_SLEEP: {
		bool pseq_sleep = false;
		rep_vec__bool_p__uint32_t_p__bool__int32_t__invoke(
		    rv_plf_to_deep_sleep, ble_to_deep_sleep, &pseq_sleep, NULL,
		    atlc_asleep, atlc_sleep_duration);
		if (!pseq_sleep) {
		    k_sem_take(&ble_sem, K_FOREVER);
		}
	    } break;
	    case PC_CTR_ATLC_WAKING:
	    case PC_CTR_ATLC_WAKING_SOON:
	    case PC_CTR_CPU_SLEEP:
		k_sem_take(&ble_sem, K_FOREVER);
		break;
	    case PC_CTR_CPU_REST:
		k_sem_take(&ble_sem, K_USEC(DT_PROP(DT_NODELABEL(sleep),
		    min_residency_us) / 2));
		break;
	    case PC_CTR_ACTIVE:
	    default:
		// nothing to do.
		break;
	}

	irq_unlock(key);
    }
}

#ifdef CONFIG_ATM_BLE
static int
ble_driver_send(struct device const *dev, struct net_buf *buf)
{
    ARG_UNUSED(dev);

    LOG_DBG("enter");

    /*
     * In case if the device is not open, drop the message.
     */
    if (!is_open) {
	LOG_ERR("Device is not Open");
	return -EINVAL;
    }
    if (!buf->len) {
	LOG_ERR("Empty HCI packet");
	return -EINVAL;
    }

    uint8_t type = net_buf_pull_u8(buf);  // Remove H4 type byte from buffer
    switch (type) {
	case BT_HCI_H4_CMD: {
	    struct bt_hci_cmd_hdr *hdr = (struct bt_hci_cmd_hdr *)buf->data;
	    uint8_t len = hdr->param_len;
	    if (len > buf->len - sizeof(*hdr)) {
		LOG_ERR("Bogus HCI CMD len");
		return -E2BIG;
	    }
	    ATM_BTHCI_DUMP_HCI_PKT(ATM_HCI_DUMP_CMD, buf->data, buf->len);
	    void *tr_buf = WsfMsgAlloc(buf->len);
	    ASSERT_INFO(tr_buf, type, buf->len);
	    memcpy(tr_buf, buf->data, buf->len);
	    chciTrRecv(CHCI_TR_PROT_BLE, CHCI_TR_TYPE_CMD, tr_buf);
	} break;
	case BT_HCI_H4_ACL: {
	    struct bt_hci_acl_hdr *hdr = (struct bt_hci_acl_hdr *)buf->data;
	    uint16_t len = sys_le16_to_cpu(hdr->len);
	    if (len > buf->len - sizeof(*hdr)) {
		LOG_ERR("Bogus HCI ACL len");
		return -E2BIG;
	    }
	    ATM_BTHCI_DUMP_HCI_PKT(ATM_HCI_DUMP_ACL_OUT, buf->data, buf->len);
	    void *tr_buf = WsfMsgAlloc(buf->len);
	    ASSERT_INFO(tr_buf, type, buf->len);
	    memcpy(tr_buf, buf->data, buf->len);
	    chciTrRecv(CHCI_TR_PROT_BLE, CHCI_TR_TYPE_ACL, tr_buf);
	} break;
	case BT_HCI_H4_ISO: {
	    struct bt_hci_iso_hdr *iso_hdr = (struct bt_hci_iso_hdr *)buf->data;
	    uint16_t len = bt_iso_hdr_len(sys_le16_to_cpu(iso_hdr->len));
	    if (len > buf->len - sizeof(*iso_hdr)) {
		LOG_ERR("Bogus HCI ISO len");
		return -E2BIG;
	    }
	    ATM_BTHCI_DUMP_HCI_PKT(ATM_HCI_DUMP_ISO_OUT, buf->data, buf->len);
	    void *tr_buf = WsfMsgAlloc(buf->len);
	    ASSERT_INFO(tr_buf, type, buf->len);
	    memcpy(tr_buf, buf->data, buf->len);
	    chciTrRecv(CHCI_TR_PROT_BLE, CHCI_TR_TYPE_ISO, tr_buf);
	} break;
	default:
	    LOG_ERR("Unknown HCI type %u", type);
	    return -EINVAL;
    }

    net_buf_unref(buf);
    k_sem_give(&ble_sem);

    LOG_DBG("exit");
    return 0;
}
#endif

static K_MUTEX_DEFINE(atm_mac_mutex);
static K_SEM_DEFINE(atm_mac_wake, 0, 1);

/*
 * @note: Always called from zero-latency ATLC_IRQn, so kernel calls are
 * not permitted.
 */
static rep_vec_err_t ble_driver_rf_wake(void)
{
    // ATLC is awake now
    NVIC_SetPendingIRQ(BLE_GIVE_IRQn);
    NVIC_SetPendingIRQ(BLE_GIVE_MAC_IRQn);
    return RV_NEXT;
}

void atm_mac_lock_sync(void)
{
    pc_ctr_sleep_lock();

    if (!atm_mac_is_sleeping) {
	// Avoid all the system calls below
	return;
    }

    // Only one thread will signal ble_thread and take sem.  Any others
    // will wait here and continue after atm_mac_is_sleeping is cleared.
    k_mutex_lock(&atm_mac_mutex, K_FOREVER);

    k_sem_reset(&atm_mac_wake);
    if (atm_mac_is_sleeping) {
	// Wake ble_thread to wake ATLC
	k_sem_give(&ble_sem);

	// Wait for ATLC to wake up
	k_sem_take(&atm_mac_wake, K_FOREVER);
    }

    k_mutex_unlock(&atm_mac_mutex);
}

void atm_mac_unlock(void)
{
    if (!pc_ctr_sleep_unlock()) {
	return;
    }

    // Wake ble_thread in case ATLC can now go to sleep
    k_sem_give(&ble_sem);
}

ISR_DIRECT_DECLARE(ble_driver_ATLC_FRC_Handler)
{
    ATLC_FRC_Handler();
    return 0;
}

ISR_DIRECT_DECLARE(ble_driver_give)
{
    k_sem_give(&ble_sem);
    return 1;
}

ISR_DIRECT_DECLARE(ble_driver_give_mac)
{
    k_sem_give(&atm_mac_wake);
    return 1;
}

#ifdef CONFIG_ATM_BLE
ISR_DIRECT_DECLARE(ble_driver_SW_1_Handler)
{
    SW_1_Handler();	// Actually PC pal_sch
    return 0;
}

ISR_DIRECT_DECLARE(ble_driver_PSEQ_CNTDWN_TIMER_1_Handler)
{
    pc_ctr_awake();
    k_sem_give(&ble_sem);
    return 1;
}

static int ble_driver_close(struct device const *dev)
{
    LOG_DBG("ble close enter");
    is_open = false;
    LOG_DBG("ble close exit");
    return 0;
}

static int
ble_driver_open(struct device const *dev, bt_hci_recv_t recv)
{
    LOG_DBG("enter");

    struct hci_data *hci = dev->data;
    hci->recv = recv;
    is_open = true;
    LOG_DBG("exit");
    return 0;
}

static struct bt_hci_driver_api const drv = {
    .open = ble_driver_open,
    .close = ble_driver_close,
    .send = ble_driver_send,
};

static struct hci_data hci_data;

#if !defined(CONFIG_CTR_DRBG_CSPRNG_GENERATOR)
#error CTR_DRBG must be enabled for controller
#endif

static rep_vec_err_t cs_rand_word_rep_vec(uint32_t *value)
{
    int ret = sys_csrand_get(value, sizeof(*value));
    if (ret) {
	__ASSERT(0, "csrand failed: %d", ret);
        // fall back to default handler
	return (RV_NEXT);
    }
    return (RV_DONE);
}

#endif // CONFIG_ATM_BLE

static int ble_driver_init(struct device const *dev)
{
    ARG_UNUSED(dev);

    LOG_DBG("enter");

    __unused uint32_t bp_freq = at_clkrstgen_get_bp();
    // pc_ctr requires 32MHz minimum
    ASSERT_INFO(bp_freq >= 32000000, bp_freq, 32000000);
#ifdef CONFIG_ATM_BLE
    RV_SECURE_RAND_WORD_ADD(cs_rand_word_rep_vec);
#endif
    RV_RF_WAKE_ADD(ble_driver_rf_wake);

    // FIXME: secure SysTick needs same adjustment
    NVIC_SetPriority(SysTick_IRQn, IRQ_PRI_NORMAL);
    BUILD_ASSERT(IRQ_PRI_HIGH >= _IRQ_PRIO_OFFSET, "ZLL too big");
    Z_ISR_DECLARE(ATLC_FRC_IRQn, ISR_FLAG_DIRECT, ble_driver_ATLC_FRC_Handler,
	NULL);
#ifdef CONFIG_ATM_BLE
    Z_ISR_DECLARE(SW_1_IRQn, ISR_FLAG_DIRECT, ble_driver_SW_1_Handler, NULL);
    Z_ISR_DECLARE(PSEQ_CNTDWN_TIMER_1_IRQn, ISR_FLAG_DIRECT,
	ble_driver_PSEQ_CNTDWN_TIMER_1_Handler, NULL);
    pc_ctr_main();
#else
    pc_ctr_sleep_init();
#endif

    IRQ_DIRECT_CONNECT(BLE_GIVE_IRQn, IRQ_PRI_UI, ble_driver_give, 0);
    irq_enable(BLE_GIVE_IRQn);
    IRQ_DIRECT_CONNECT(BLE_GIVE_MAC_IRQn, IRQ_PRI_UI, ble_driver_give_mac, 0);
    irq_enable(BLE_GIVE_MAC_IRQn);

    k_thread_create(&ble_thread_data, ble_thread_stack,
		    K_KERNEL_STACK_SIZEOF(ble_thread_stack),
		    ble_thread, NULL, NULL, NULL,
		    K_PRIO_COOP(CONFIG_ATM_BLE_HIGH_PRIO), 0, K_NO_WAIT);

    k_thread_name_set(&ble_thread_data, "Atmosic ATLC");

    LOG_DBG("exit");
    return 0;
}

#elif CONFIG_PM

#include "at_lc_regs_core_macro.h"

static int ble_driver_init(struct device const *dev)
{
    // Force ATLC to sleep
    CMSDK_ATLC_NONSECURE->LC_LP_CTRL0 = ATLC_LC_LP_CTRL0__RADIO_SLP_EN__MASK;
    CMSDK_ATLC_NONSECURE->LC_LP_CTRL2 = ATLC_LC_LP_CTRL2__SLP_TM__WRITE(0);
    CMSDK_ATLC_NONSECURE->LC_LP_CTRL3 = ATLC_LC_LP_CTRL3__SLP__MASK;
    return 0;
}

#endif // CONFIG_ATM_ATLC

DEVICE_DT_INST_DEFINE(0, ble_driver_init, NULL,
		      COND_CODE_1(CONFIG_ATM_BLE, (&hci_data), (NULL)), NULL,
		      POST_KERNEL, CONFIG_KERNEL_INIT_PRIORITY_DEVICE,
		      COND_CODE_1(CONFIG_ATM_BLE, (&drv), (NULL)));
