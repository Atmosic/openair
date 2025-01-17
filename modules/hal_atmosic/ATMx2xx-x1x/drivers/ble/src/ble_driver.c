/**
 *******************************************************************************
 *
 * @file ble_driver.c
 *
 * @brief Atmosic BLE link layer - HCI driver
 *
 * Copyright (C) Atmosic 2018-2024
 *
 *******************************************************************************
 */

#define DT_DRV_COMPAT atmosic_ble

#include <errno.h>
#include <stddef.h>
#include <string.h>

#include <zephyr/kernel.h>
#include <soc.h>
#include <zephyr/init.h>
#include <zephyr/device.h>
#include <zephyr/sys_clock.h>

#include <zephyr/sys/byteorder.h>
#include <zephyr/random/random.h>
#include <zephyr/bluetooth/bluetooth.h>
#include <zephyr/bluetooth/hci.h>
#include <zephyr/drivers/bluetooth.h>
#include <zephyr/drivers/bluetooth/hci_driver.h>

#include <zephyr/pm/pm.h>
#include <zephyr/pm/policy.h>
#include <zephyr/logging/log.h>
LOG_MODULE_REGISTER(atm_ble_driver, LOG_LEVEL_INF);

#include "arch.h"
#include "timer.h"
#include "vectors.h"
#include "co_error.h"
#include "ke_event.h"
#include "rwip.h"
#include "rwip_config.h"
#include "rwble.h"
#include "reg_ipcore.h"
#include "hci.h"
#include "hw_cfg.h"

struct hci_data {
    bt_hci_recv_t recv;
};

static K_SEM_DEFINE(ble_sem, 0, 1);
struct k_thread ble_thread_data;
static K_KERNEL_STACK_DEFINE(ble_thread_stack, CONFIG_BT_RX_STACK_SIZE);

static rep_vec_err_t
ble_appm_last_init(void)
{
    // Redirect APP_MAIN_TASK to TASK_AHI
    rwble_hl_app_main_task = TASK_AHI;

    // Don't use the app in the ROM
    return (RV_DONE);
}
static rep_vec_t ble_rv_appm_last_init =
    { ble_appm_last_init, NULL };

#define H4_NONE 0x00
#define H4_CMD  0x01
#define H4_ACL  0x02
#define H4_SCO  0x03
#define H4_EVT  0x04

static void
ble_write(uint8_t *bufptr, uint32_t size, void (*callback) (void *, uint8_t),
    void *dummy)
{
    uint8_t type = bufptr[0];
    uint8_t *buf = bufptr + HCI_TRANSPORT_HDR_LEN;
    uint16_t len = size - HCI_TRANSPORT_HDR_LEN;
    struct net_buf *nbuf = NULL;

    if (type == H4_EVT) {
	uint8_t evt = buf[0];
	nbuf = bt_buf_get_evt(evt, false, K_FOREVER);
    }

    if (!nbuf) {
	nbuf = bt_buf_get_rx(BT_BUF_ACL_IN, K_FOREVER);
    }
    net_buf_add_mem(nbuf, buf, len);

    LOG_DBG("Packet in: type:%u len:%u", bt_buf_get_type(nbuf), nbuf->len);

    struct device const *dev = DEVICE_DT_GET(DT_DRV_INST(0));
    struct hci_data *hci = dev->data;
    hci->recv(dev, nbuf);

    callback(dummy, RWIP_EIF_STATUS_OK);
}

static void dummy_read(uint8_t *bufptr, uint32_t size, void (*callback) (void *, uint8_t), void *dummy) {}
static void dummy_flow_on(void) {}
static bool dummy_flow_off(void) { return true; }
static uint8_t dummy_ioctl(uint8_t code, uint32_t value) { return CO_ERROR_NO_ERROR; }

static struct rwip_eif_api const ble_eif_api = {
    dummy_read,
    ble_write,
    dummy_flow_on,
    dummy_flow_off,
    dummy_ioctl,
};

static struct rwip_eif_api const *
ble_rwip_eif_get(uint8_t idx)
{
    return (&ble_eif_api);
}

__ramfunc static void
ble_isr(void *arg)
{
    ARG_UNUSED(arg);

    rwble_isr();
    k_sem_give(&ble_sem);
}

__ramfunc static bool
ble_to_deep_sleep(struct device const *dev, bool ble_asleep,
    int32_t ble_sleep_duration)
{
    extern int32_t plf_hibernate_adjust;
    extern int32_t plf_retain_adjust;
    extern int32_t plf_sleep_min;

    static bool soft_wakeup_req_pending;
    if (ble_asleep) {
	if (ke_event_get_all()) {
	    if ((!soft_wakeup_req_pending) && (ble_sleep_duration > 0)) {
		// Wake up, BLE!  We have work to do!
		ip_deepslcntl_soft_wakeup_req_setf(1);
		// DO NOT request again until BLE wakes up
		soft_wakeup_req_pending = true;
	    }
	    return false;
	}
    } else {
	soft_wakeup_req_pending = false;
    }

    if (sleep_enable < SLEEP_ENABLE_RETAIN) {
	return false;
    }

    k_ticks_t ticks = K_TICKS_FOREVER;
    // ble_sleep_duration == 0 means no timer (external wakeup only)
    if (ble_sleep_duration) {
	if (sleep_enable >= SLEEP_ENABLE_HIBERNATE) {
	    // If below fudge factor is too large, it will manifest
	    // as a loop reading from IP_SLOTCLK_ADDR (0x3000001c).
	    ble_sleep_duration -= plf_hibernate_adjust;
	} else {
	    // Make sure the CPU is back up and running with interrupts enabled
	    // well before timing-sensitive interrupts arrive from BLE
	    ble_sleep_duration -= plf_retain_adjust;
	}
	if (ble_sleep_duration < plf_sleep_min) {
	    // Too short; don't involve PSEQ
	    return false;
	}

	// Convert lpcycles to ticks
	ticks = atm_lpc_to(Z_HZ_ticks, ble_sleep_duration);
    }

#ifdef CONFIG_PM
    pm_policy_state_lock_put(PM_STATE_SUSPEND_TO_RAM, PM_ALL_SUBSTATES);
#endif
    k_sem_take(&ble_sem, K_TICKS(ticks));
#ifdef CONFIG_PM
    pm_policy_state_lock_get(PM_STATE_SUSPEND_TO_RAM, PM_ALL_SUBSTATES);
#endif
    return true;
}

__ramfunc static void
ble_thread(void *p1, void *p2, void *p3)
{
    ARG_UNUSED(p1);
    ARG_UNUSED(p2);
    ARG_UNUSED(p3);

    struct device const *dev = DEVICE_DT_INST_GET(0);

#ifdef CONFIG_PM
    pm_policy_state_lock_get(PM_STATE_SUSPEND_TO_RAM, PM_ALL_SUBSTATES);
#endif
    for (;;) {
	rwip_schedule();

	unsigned int key = irq_lock();

	bool ble_asleep = false;
	int32_t ble_sleep_duration = -1;
	switch (rwip_sleep(&ble_asleep, &ble_sleep_duration)) {
	    case RWIP_DEEP_SLEEP: {
		if (!ble_to_deep_sleep(dev, ble_asleep, ble_sleep_duration)) {
		    k_sem_take(&ble_sem, K_FOREVER);
		}
	    } break;

	    case RWIP_CPU_SLEEP: {
		k_sem_take(&ble_sem, K_FOREVER);
	    } break;

	    case RWIP_ACTIVE:
	    default: {
	    } break;
	}

	irq_unlock(key);
    }
}

static int
ble_driver_send(struct device const *dev, struct net_buf *buf)
{
    ARG_UNUSED(dev);

    LOG_DBG("enter");

    if (!buf->len) {
	LOG_ERR("Empty HCI packet");
	return -EINVAL;
    }

    uint8_t type = bt_buf_get_type(buf);
    switch (type) {
	case BT_BUF_CMD: {
	    struct bt_hci_cmd_hdr *hdr = (struct bt_hci_cmd_hdr *)buf->data;
	    uint16_t opcode = sys_le16_to_cpu(hdr->opcode);
	    uint8_t len = hdr->param_len;
	    if (len > buf->len - sizeof(*hdr)) {
		LOG_ERR("Bogus HCI CMD len");
		return -E2BIG;
	    }
	    hci_cmd_received(opcode, len, buf->data + sizeof(*hdr));
	} break;
	case BT_BUF_ACL_OUT: {
	    struct bt_hci_acl_hdr *hdr = (struct bt_hci_acl_hdr *)buf->data;
	    uint16_t handle = sys_le16_to_cpu(hdr->handle);
	    uint16_t len = sys_le16_to_cpu(hdr->len);
	    if (len > buf->len - sizeof(*hdr)) {
		LOG_ERR("Bogus HCI ACL len");
		return -E2BIG;
	    }
	    uint8_t *acl_data = hci_acl_tx_data_alloc(handle, len);
	    if (!acl_data) {
		LOG_ERR("Failed to allocate HCI ACL data");
		return -ENOMEM;
	    }
	    memcpy(acl_data, buf->data + sizeof(*hdr), len);
	    hci_acl_tx_data_received(handle, len, acl_data);
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

static int
ble_driver_open(struct device const *dev, bt_hci_recv_t recv)
{
    LOG_DBG("enter");

    struct hci_data *hci = dev->data;
    hci->recv = recv;

    RV_SECURE_RAND_WORD_ADD(cs_rand_word_rep_vec);
    rep_vec_add_last(&rv_appm_init, &ble_rv_appm_last_init);
    plf_rwip_eif_get = ble_rwip_eif_get;

    rwip_init(RESET_NO_ERROR);

    IRQ_CONNECT(DT_INST_IRQN(0), DT_INST_IRQ(0, priority), ble_isr, NULL, 0);
    irq_enable(DT_INST_IRQN(0));

    LOG_DBG("middle");

    k_thread_create(&ble_thread_data, ble_thread_stack,
		    K_KERNEL_STACK_SIZEOF(ble_thread_stack),
		    ble_thread, NULL, NULL, NULL,
		    K_PRIO_COOP(CONFIG_BT_DRIVER_RX_HIGH_PRIO), 0, K_NO_WAIT);

    k_thread_name_set(&ble_thread_data, "Atmosic BLE");

    LOG_DBG("exit");
    return 0;
}

static struct bt_hci_driver_api const drv = {
    .open	= ble_driver_open,
    .send	= ble_driver_send,
};

static struct hci_data hci_data;

static int ble_driver_init(struct device const *dev)
{
    ARG_UNUSED(dev);

    LOG_DBG("enter");

    hw_cfg_init();

    LOG_DBG("exit");
    return 0;
}

DEVICE_DT_INST_DEFINE(0, ble_driver_init, NULL, &hci_data, NULL,
		      POST_KERNEL, CONFIG_KERNEL_INIT_PRIORITY_DEVICE,
		      &drv);
