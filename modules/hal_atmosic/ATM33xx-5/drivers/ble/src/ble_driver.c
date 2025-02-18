/**
 *******************************************************************************
 *
 * @file ble_driver.c
 *
 * @brief Atmosic BLE link layer - HCI driver
 *
 * Copyright (C) Atmosic 2018-2025
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

#ifdef CONFIG_ATM_BLE
#include <zephyr/bluetooth/bluetooth.h>
#include <zephyr/bluetooth/hci.h>
#include <zephyr/drivers/bluetooth.h>
#include <zephyr/drivers/bluetooth/hci_driver.h>
#ifdef CONFIG_BT_SMP
#define BLE_THREAD_STACK_SIZE MAX(CONFIG_BT_RX_STACK_SIZE, 1600)
#else
#define BLE_THREAD_STACK_SIZE CONFIG_BT_RX_STACK_SIZE
#endif /* CONFIG_BT_SMP */
#define BT_DRIVER_RX_PRIO CONFIG_BT_DRIVER_RX_HIGH_PRIO

struct hci_data {
    bt_hci_recv_t recv;
};
#else
// not running the BT host stack, use reasonable defaults
#define BLE_THREAD_STACK_SIZE 2048
#define BT_DRIVER_RX_PRIO 6
#endif

#include <zephyr/pm/pm.h>
#include <zephyr/pm/policy.h>
#include <zephyr/logging/log.h>
LOG_MODULE_REGISTER(atm_ble_driver, LOG_LEVEL_INF);
#if (defined(CFG_ATMWSTKLIB) && \
    !(defined(CONFIG_MINIMAL_LIBC_RAND) && \
	defined(CONFIG_MINIMAL_LIBC_NON_REENTRANT_FUNCTIONS)))
#define ATM_PROVIDE_LIBC_RAND
#endif
#if (defined(CONFIG_ATM_BLE) || defined(ATM_PROVIDE_LIBC_RAND))
#include <zephyr/random/random.h>
#endif
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
#ifdef CONFIG_ATM_EUI
#include "eui.h"
#endif

#include "at_wrpr.h"
#include "at_apb_pseq_regs_core_macro.h"
#ifndef CFG_NVDS
#include "calibration.h"
#endif

static K_SEM_DEFINE(ble_sem, 0, 1);
struct k_thread ble_thread_data;
static K_KERNEL_STACK_DEFINE(ble_thread_stack, BLE_THREAD_STACK_SIZE);
static bool is_open;

static rep_vec_err_t
ble_appm_last_init(void)
{
#ifdef APP_MAIN_TASK
    // Redirect APP_MAIN_TASK to TASK_AHI
    APP_MAIN_TASK = TASK_AHI;
#endif

    // Don't use the app in the ROM
    return (RV_DONE);
}

#ifdef CONFIG_ATM_BLE
#define H4_NONE 0x00
#define H4_CMD  0x01
#define H4_ACL  0x02
#define H4_SCO  0x03
#define H4_EVT  0x04
#define H4_ISO  0x05

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

static void
ble_write(uint8_t *bufptr, uint32_t size, void (*callback) (void *, uint8_t),
    void *dummy)
{
    uint8_t type = bufptr[0];
    uint8_t *buf = bufptr + HCI_TRANSPORT_HDR_LEN;
    uint16_t len = size - HCI_TRANSPORT_HDR_LEN;
    struct net_buf *nbuf = NULL;

    /*
     * In case if the device is not open, drop the message.
     * We still need to invoke the callback
     */
    if (!is_open) {
	LOG_ERR("Device is not Open");
	goto done;
    }

    switch (type) {
	case H4_EVT: {
	    uint8_t evt = buf[0];
	    bool discardable = is_hci_event_discardable(buf);
	    nbuf = bt_buf_get_evt(evt, discardable,
		discardable ? K_NO_WAIT : K_FOREVER);
	} break;
	case H4_ACL: {
	    nbuf = bt_buf_get_rx(BT_BUF_ACL_IN, K_FOREVER);
	} break;
	case H4_ISO: {
	    nbuf = bt_buf_get_rx(BT_BUF_ISO_IN, K_MSEC(250));
	} break;
	default: {
	    __ASSERT(0, "Unknown Type = %d with Len = %d", type, len);
	} break;
    }

    if (nbuf) {
	net_buf_add_mem(nbuf, buf, len);

	LOG_DBG("Packet in: type:%u len:%u", bt_buf_get_type(nbuf), nbuf->len);

	struct device const *dev = DEVICE_DT_GET(DT_DRV_INST(0));
	struct hci_data *hci = dev->data;
	hci->recv(dev, nbuf);
    } else {
	LOG_DBG("nbuf == NULL");
    }

done:
    callback(dummy, RWIP_EIF_STATUS_OK);
}
#define BT_HCI_EIF_WRITE_FUNC ble_write
#else
static void
dummy_write(uint8_t *bufptr, uint32_t size, void (*callback) (void *, uint8_t),
    void *ctxt)
{
    uint8_t type = bufptr[0];
    uint16_t len = size - HCI_TRANSPORT_HDR_LEN;
    LOG_DBG("Dropped HCI type = %d with Len = %d", type, len);
    callback(ctxt, RWIP_EIF_STATUS_OK);
}
#define BT_HCI_EIF_WRITE_FUNC dummy_write
#endif // CONFIG_ATM_BLE

static void dummy_read(uint8_t *bufptr, uint32_t size, void (*callback) (void *, uint8_t), void *dummy) {}
static void dummy_flow_on(void) {}
static bool dummy_flow_off(void) { return true; }

static struct rwip_eif_api const ble_eif_api = {
    dummy_read,
    BT_HCI_EIF_WRITE_FUNC,
    dummy_flow_on,
    dummy_flow_off,
};

static rep_vec_err_t
ble_rwip_eif_get(struct rwip_eif_api const **ret, uint8_t idx)
{
    *ret = &ble_eif_api;
    return (RV_DONE);
}

static void
ble_wake_thread(void)
{
    k_sem_give(&ble_sem);
}

static void
ble_ip_isr(void *arg)
{
    ARG_UNUSED(arg);

    rwip_isr();
}

static void
ble_isr(void *arg)
{
    ARG_UNUSED(arg);

    rwble_isr();
}

static int32_t plf_sleep_min = 0xa0;

static void
ble_to_deep_sleep(bool *pseq_sleep, uint32_t *int_set, bool ble_asleep,
    int32_t ble_sleep_duration)
{
    if (ble_asleep && ke_event_get_all()) {
	// Wake up, BLE!  We have work to do!

	// External wakeup must be enabled for WREQ to work
	ASSERT_ERR(!ip_deepslcntl_extwkupdsb_getf());
	// Assert WREQ signal
	WRPR_CTRL_PUSH(CMSDK_PSEQ, WRPR_CTRL__CLK_ENABLE) {
	    CMSDK_PSEQ->OVERRIDES5 |=
		PSEQ_OVERRIDES5__OVERRIDE_WREQ__MASK |
		PSEQ_OVERRIDES5__OVERRIDE_WREQ_VAL__MASK;
	} WRPR_CTRL_POP();

	return;
    }

    if (sleep_enable < SLEEP_ENABLE_RETAIN) {
	return;
    }

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
	// Let WATCH_BLE_OSC_ON signal wakeup for optimal power profile
	ticks += k_ms_to_ticks_ceil32(2);
    }

#ifdef CONFIG_PM
    pm_policy_state_lock_put(PM_STATE_SUSPEND_TO_RAM, PM_ALL_SUBSTATES);
#endif
    k_sem_take(&ble_sem, K_TICKS(ticks));
#ifdef CONFIG_PM
    pm_policy_state_lock_get(PM_STATE_SUSPEND_TO_RAM, PM_ALL_SUBSTATES);
#endif
    *pseq_sleep = true;
}

static void
ble_thread(void *p1, void *p2, void *p3)
{
    ARG_UNUSED(p1);
    ARG_UNUSED(p2);
    ARG_UNUSED(p3);

    rwip_rtos_post_callback_set(ble_wake_thread);

#ifdef CONFIG_PM
    pm_policy_state_lock_get(PM_STATE_SUSPEND_TO_RAM, PM_ALL_SUBSTATES);
#endif
    for (;;) {
	rwip_process();

	rep_vec_invoke(rv_plf_schedule, NULL);

	unsigned int key = irq_lock();

	bool ble_asleep = false;
	int32_t ble_sleep_duration = -1;
	switch (rwip_sleep(&ble_asleep, &ble_sleep_duration)) {
	    case RWIP_DEEP_SLEEP: {
		bool pseq_sleep = false;
		rep_vec__bool_p__uint32_t_p__bool__int32_t__invoke(
		    rv_plf_to_deep_sleep, ble_to_deep_sleep, &pseq_sleep, NULL,
		    ble_asleep, ble_sleep_duration);
		if (!pseq_sleep) {
		    k_sem_take(&ble_sem, K_FOREVER);

		    // Release WREQ signal
		    WRPR_CTRL_PUSH(CMSDK_PSEQ, WRPR_CTRL__CLK_ENABLE) {
			PSEQ_OVERRIDES5__OVERRIDE_WREQ_VAL__CLR(
			    CMSDK_PSEQ->OVERRIDES5);
		    } WRPR_CTRL_POP();
		}
	    } break;

	    case RWIP_IDLE:
		k_sem_take(&ble_sem, K_FOREVER);
		break;

	    case RWIP_ACTIVE:
	    default:
		break;
	}

	irq_unlock(key);
    }
}

#ifdef CONFIG_ATM_BLE
static rwtl_itf_t *p_itf;

static int
ble_driver_send(struct device const *dev, struct net_buf *buf)
{
    ARG_UNUSED(dev);

    LOG_DBG("enter");

    if (!is_open) {
	LOG_ERR("Device is not open");
	return -EINVAL;
    }
    if (!buf->len) {
	LOG_ERR("Empty HCI packet");
	return -EINVAL;
    }

    uint8_t type = bt_buf_get_type(buf);
    switch (type) {
	case BT_BUF_CMD: {
	    struct bt_hci_cmd_hdr *hdr = (struct bt_hci_cmd_hdr *)buf->data;
	    uint8_t len = hdr->param_len;
	    if (len > buf->len - sizeof(*hdr)) {
		LOG_ERR("Bogus HCI CMD len");
		return -E2BIG;
	    }
	    rwtl_rx_client_t const *p_client =
		rwtl_rx_client_get(H4_MSG_LC_HCI_CMD);
	    if (!p_client) {
		LOG_ERR("Missing HCI CMD client");
		return -EINVAL;
	    }
	    rwtl_rx_next_t next = p_client->cb_received(p_itf,
		RWTL_COMPLETE_MSG, buf->data, len, buf->data + sizeof(*hdr));
	    if (next.data_len < 0) {
		LOG_ERR("Failed to allocate HCI MSG data");
		return -ENOMEM;
	    }
	} break;
	case BT_BUF_ACL_OUT: {
	    struct bt_hci_acl_hdr *hdr = (struct bt_hci_acl_hdr *)buf->data;
	    uint16_t len = sys_le16_to_cpu(hdr->len);
	    if (len > buf->len - sizeof(*hdr)) {
		LOG_ERR("Bogus HCI ACL len");
		return -E2BIG;
	    }
	    rwtl_rx_client_t const *p_client = rwtl_rx_client_get(H4_MSG_LC_HCI_ACL);
	    if (!p_client) {
		LOG_ERR("Missing HCI ACL client");
		return -EINVAL;
	    }
	    rwtl_rx_next_t next = p_client->cb_received(p_itf,
		RWTL_COMPLETE_MSG, buf->data, len, buf->data + sizeof(*hdr));
	    if (next.data_len < 0) {
		LOG_ERR("Failed to allocate HCI ACL data");
		return -ENOMEM;
	    }
	} break;
	default:
	    LOG_ERR("Unknown HCI type %u", type);
	    return -EINVAL;
    }

    net_buf_unref(buf);

    LOG_DBG("exit");
    return 0;
}

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
    static bool open_once;
    LOG_DBG("enter");

    struct hci_data *hci = dev->data;
    hci->recv = recv;

    if (!open_once) {
	// provide secure rand for the controller
	RV_SECURE_RAND_WORD_ADD(cs_rand_word_rep_vec);
#if !defined(CONFIG_CTR_DRBG_CSPRNG_GENERATOR)
#error CTR_DRBG must be enabled for controller
#endif

	p_itf = rwtl_itf_get();
	open_once = true;
    }

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
#endif // CONFIG_ATM_BLE

#define BLE_IRQ_SETUP(idx, isr) do { \
    IRQ_CONNECT(DT_INST_IRQ_BY_IDX(0, idx, irq), \
	DT_INST_IRQ_BY_IDX(0, idx, priority), isr, NULL, 0); \
    irq_enable(DT_INST_IRQ_BY_IDX(0, idx, irq)); \
} while (0)

#ifndef CFG_NVDS
#undef DEBUG_RWIP_PARAM_GET
#define RWIP_PARAM_OKAY 0
#define RWIP_PARAM_FAIL 1
#define RWIP_PARAM_NOT_FOUND 2
#define RWIP_PARAM_INVALID 4

static uint8_t user_param_set(uint8_t param_id, uint8_t length,
    uint8_t const *buf)
{
    return RWIP_PARAM_FAIL;
}

static uint8_t user_param_del(uint8_t param_id)
{
    return RWIP_PARAM_FAIL;
}

static uint8_t user_param_get(uint8_t param_id, uint8_t *lengthPtr,
    uint8_t *buf)
{
    uint32_t temp;
    uint8_t copy_len = 0;
    void const *param_data = &temp;
    uint8_t status = RWIP_PARAM_OKAY;

    if (!lengthPtr || !buf || !(*lengthPtr)) {
	LOG_ERR("Invalid param request %#x", param_id);
	return RWIP_PARAM_INVALID;
    }

    uint8_t eui48[BD_ADDR_LEN];
    switch (param_id) {
	case PARAM_ID_BD_ADDRESS: {
	    if (*lengthPtr < BD_ADDR_LEN) {
		status = RWIP_PARAM_INVALID;
		break;
	    }
#ifdef CONFIG_ATM_EUI
	    if (read_eui48(eui48)) {
		param_data = eui48;
		copy_len = sizeof(eui48);
	    } else {
#endif
		status = RWIP_PARAM_NOT_FOUND;
#ifdef CONFIG_ATM_EUI
	    }
#endif
	} break;
#ifdef CONFIG_ATM_LPC_RCOS
	case PARAM_ID_MAX_SLEEP_DUR: {
	    temp = LPC_RCOS_VALID;
	    copy_len = sizeof(uint32_t);
	} break;
#endif
	case PARAM_ID_SLEEP_ENABLE: {
	    temp = CONFIG_ATM_SLEEP_ENABLE;
	    copy_len = sizeof(uint8_t);
	} break;
	case PARAM_ID_EXT_WAKEUP_ENABLE: {
	    temp = CONFIG_EXT_WAKEUP_ENABLE;
	    copy_len = sizeof(uint8_t);
	} break;
	case PARAM_ID_SLEEP_ADJ: {
	    if (*lengthPtr < sizeof(uint32_t)) {
		status = RWIP_PARAM_INVALID;
		break;
	    }
	    temp = CONFIG_ATM_SLEEP_ADJ;
	    copy_len = sizeof(uint32_t);
	} break;
	default: {
	    status = RWIP_PARAM_NOT_FOUND;
	} break;
    }

    if (status != RWIP_PARAM_OKAY) {
	if (status != RWIP_PARAM_NOT_FOUND) {
	    LOG_ERR("Param error %#x (%d,%d)", param_id, *lengthPtr, status);
	}
	return status;
    }

    memcpy(buf, param_data, copy_len);
    *lengthPtr = copy_len;
    LOG_DBG("Param found: %#x len:%d", param_id, *lengthPtr);
#ifdef DEBUG_RWIP_PARAM_GET
    printk("Param found: %#x len:%d\n", param_id, *lengthPtr);
    for (uint8_t i = 0; i < copy_len; i++) {
	printk(" 0x%x", buf[i]);
    }
    printk("\n");
#endif
    return RWIP_PARAM_OKAY;
}
#endif // !CFG_NVDS

#if !RW_DEBUG
// BLE controller reported an error. Can be called in an ISR context
static void user_report_error(uint8_t type, uint32_t param0, uint32_t param1)
{
    if (type == RWIP_ERR_TYPE_BLE_HW) {
	printk("BLE HW error stat:0x%x, irqstat:0x%x\n", param0, param1);
	// NOTE: the hardware error will arrive on the slow path via
	// the HCI HW_ERROR event.  This will be processed by the stack
	// and the stack will halt.
    }
}
#endif

static int ble_driver_init(struct device const *dev)
{
    ARG_UNUSED(dev);

    LOG_DBG("enter");

#ifndef CFG_NVDS
    rwip_param.get = user_param_get;
    rwip_param.set = user_param_set;
    rwip_param.del = user_param_del;
#endif
#if !RW_DEBUG
    rwip_error_reporting.rpt_error_cb = user_report_error;
#endif

    RV_APPM_INIT_ADD_LAST(ble_appm_last_init);
    RV_RWIP_EIF_GET_ADD(ble_rwip_eif_get);

    rwip_init(RESET_NO_ERROR);

    BLE_IRQ_SETUP(0, ble_ip_isr);
    BLE_IRQ_SETUP(1, ble_ip_isr);
    BLE_IRQ_SETUP(2, ble_ip_isr);
    BLE_IRQ_SETUP(3, ble_ip_isr);
    BLE_IRQ_SETUP(4, ble_ip_isr);
    BLE_IRQ_SETUP(5, ble_ip_isr);
    BLE_IRQ_SETUP(6, ble_ip_isr);
    BLE_IRQ_SETUP(7, ble_ip_isr);
    BLE_IRQ_SETUP(8, ble_ip_isr);
    BLE_IRQ_SETUP(9, ble_isr);
    BLE_IRQ_SETUP(10, ble_isr);

    LOG_DBG("middle");

    k_thread_create(&ble_thread_data, ble_thread_stack,
		    K_KERNEL_STACK_SIZEOF(ble_thread_stack),
		    ble_thread, NULL, NULL, NULL,
		    K_PRIO_COOP(BT_DRIVER_RX_PRIO), 0, K_NO_WAIT);

    k_thread_name_set(&ble_thread_data, "Atmosic BLE");

    LOG_DBG("exit");
    return 0;
}

#ifdef ATM_PROVIDE_LIBC_RAND
int rand(void)
{
    return (sys_rand32_get());
}
void srand(unsigned int seed)
{
}
#endif

DEVICE_DT_INST_DEFINE(0, ble_driver_init, NULL,
		      COND_CODE_1(CONFIG_BT, (&hci_data), (NULL)), NULL,
		      POST_KERNEL, CONFIG_KERNEL_INIT_PRIORITY_DEVICE,
		      COND_CODE_1(CONFIG_BT, (&drv), (NULL)));
