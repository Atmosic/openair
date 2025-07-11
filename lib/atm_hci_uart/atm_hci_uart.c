/**
 *******************************************************************************
 *
 * @file atm_hci_uart.c
 *
 * @brief ATM HCI data from uart to another device/CPU using and handle vendor
 * command with hci_raw module for zephyr only.
 *
 * Copyright (C) Atmosic 2024-2025
 *
 *******************************************************************************
 */

#include <errno.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

#include <zephyr/kernel.h>
#include <zephyr/arch/cpu.h>
#include <zephyr/sys/byteorder.h>
#include <zephyr/logging/log.h>
#include <zephyr/sys/util.h>

#include <zephyr/device.h>
#include <zephyr/init.h>
#include <zephyr/drivers/uart.h>

#include <zephyr/net_buf.h>
#include <zephyr/bluetooth/bluetooth.h>
#include <zephyr/bluetooth/hci.h>
#include <zephyr/bluetooth/buf.h>
#include <zephyr/bluetooth/hci_raw.h>
#include <zephyr/sys/reboot.h>
#ifdef CONFIG_BT_HCI_RAW_CMD_EXT
#include "atm_vendor_internal.h"
#endif
#include "atm_hci_uart.h"
#include "atm_utils_c.h"
#ifdef CONFIG_AUTO_TEST
#include "atm_test_common.h"
#endif

#define LOG_MODULE_NAME atm_hci_uart
LOG_MODULE_REGISTER(LOG_MODULE_NAME, CONFIG_ATM_HCI_UART_LOG_LEVEL);

#ifdef CONFIG_ATM_HCI_UART0_DEVICE
#define HCI_UART_LABEL DT_NODELABEL(uart0)
#elif CONFIG_ATM_HCI_UART1_DEVICE
#define HCI_UART_LABEL DT_NODELABEL(uart1)
#else
#error "Unknown hci uart device"
#endif

static const struct device *const hci_uart_dev = DEVICE_DT_GET(HCI_UART_LABEL);
static K_THREAD_STACK_DEFINE(tx_thread_stack, CONFIG_ATM_VENDOR_TX_STACK_SIZE);
static struct k_thread tx_thread_data;
static K_THREAD_STACK_DEFINE(rx_thread_stack, CONFIG_ATM_VENDOR_RX_STACK_SIZE);
static struct k_thread rx_thread_data;
static K_FIFO_DEFINE(tx_queue);

/* RX in terms of bluetooth communication */
static K_FIFO_DEFINE(uart_tx_queue);

#define H4_CMD 0x01
#define H4_ACL 0x02
#define H4_SCO 0x03
#define H4_EVT 0x04
#define H4_ISO 0x05

/* Receiver states. */
#define ST_IDLE 0 /* Waiting for packet type. */
#define ST_HDR 1 /* Receiving packet header. */
#define ST_PAYLOAD 2 /* Receiving packet payload. */
#define ST_DISCARD 3 /* Dropping packet. */

/* Length of a discard/flush buffer.
 * This is sized to align with a BLE HCI packet:
 * 1 byte H:4 header + 32 bytes ACL/event data
 * Bigger values might overflow the stack since this is declared as a local
 * variable, smaller ones will force the caller to call into discard more
 * often.
 */
#define H4_DISCARD_LEN 33

#ifdef CONFIG_BT_HCI_RAW_CMD_EXT
struct vendor_handler const *vendor_hdlr;
static size_t vendor_hdlr_size;

static void atm_hci_uart_hci_vs_send(uint8_t const *data, int data_len)
{
    for (int i = 0; i < data_len; i++) {
	uart_poll_out(hci_uart_dev, data[i]);
    }
    return;
}

static struct vendor_handler const *atm_hci_uart_find_vend_handler(uint16_t ocf,
    uint16_t ogf)
{
    for (uint32_t i = 0; i < vendor_hdlr_size; i++) {
	struct vendor_handler const *hdlr = &vendor_hdlr[i];
	if ((hdlr->ocf == ocf) && (hdlr->ogf == ogf)) {
	    return hdlr;
	}
    }
    LOG_DBG("handler not found for ocf(0x%04X) ogf(0x%04X)", ocf, ogf);
    return NULL;
}

static uint8_t atm_hci_uart_dispatch_handler(uint16_t ocf, uint16_t ogf,
    uint8_t const *data)
{
    struct vendor_handler const *hdlr =
	atm_hci_uart_find_vend_handler(ocf, ogf);
    if (!hdlr) {
	return HCI_EVT_ERROR;
    }
    hdlr->cmd_hdlr(data);
    uint32_t size;
    uint8_t *bufptr;
    hdlr->cmd_cmp_hdlr(&bufptr, &size);
    atm_hci_uart_hci_vs_send(bufptr, size);
    return BT_HCI_ERR_EXT_HANDLED;
}

#define ATM_HCI_UART_OP(ocf, ogf) ((ogf << 8) | ocf)
#define ATM_VS_SET(name) \
    BT_HCI_RAW_CMD_EXT(ATM_HCI_UART_OP(name##_OCF, name##_OGF), name##_LEN, \
	name##_HDLR)
#define ATM_VS_HDLR(name) \
    static uint8_t name##_HDLR(struct net_buf *buf) \
    { \
	if (!name) { \
	    LOG_DBG("%s not support", #name); \
	    return HCI_EVT_ERROR; \
	} \
	return atm_hci_uart_dispatch_handler(name##_OCF, name##_OGF, \
	    buf->data); \
    }

/*
 * How to add new vendor command
 * Step 1. add new vendor command definitions in
 *         atm_vendor/atm_vendor_internal.h
 * Step 2. implement vendor command hdlr and cmp_hdlr in atm_vendor/atm_vendor.c
 * Step 3. add new vendor command to cmd_ext by ATM_VS_SET and ATM_VS_HDLR
 */

#ifdef CONFIG_VND_DBG_MMR
ATM_VS_HDLR(RD_MEM_CMD)
#endif
#ifdef CONFIG_VND_DBG_MMW
ATM_VS_HDLR(WR_MEM_CMD)
#endif
#ifdef CONFIG_VND_BLE_REGR
ATM_VS_HDLR(BLE_REG_RD_CMD)
#endif
#ifdef CONFIG_VND_BLE_REGW
ATM_VS_HDLR(BLE_REG_WR_CMD)
#endif
#ifdef CONFIG_VND_MALLOC
ATM_VS_HDLR(MALLOC_CMD)
#endif
#ifdef CONFIG_VND_WFI
ATM_VS_HDLR(WFI_CMD)
#endif
#ifdef CONFIG_VND_NO_CLOCK
ATM_VS_HDLR(NO_CLOCK_CMD)
#endif
ATM_VS_HDLR(EN_TXCW_CMD)
ATM_VS_HDLR(FREQCAL_CMD)
ATM_VS_HDLR(MM_R_CMD)
ATM_VS_HDLR(PV_TEST_CMD)

static struct bt_hci_raw_cmd_ext cmd_ext[] = {
#ifdef CONFIG_VND_DBG_MMR
    ATM_VS_SET(RD_MEM_CMD),
#endif
#ifdef CONFIG_VND_DBG_MMW
    ATM_VS_SET(WR_MEM_CMD),
#endif
#ifdef CONFIG_VND_BLE_REGR
    ATM_VS_SET(BLE_REG_RD_CMD),
#endif
#ifdef CONFIG_VND_BLE_REGW
    ATM_VS_SET(BLE_REG_WR_CMD),
#endif
#ifdef CONFIG_VND_MALLOC
    ATM_VS_SET(MALLOC_CMD),
#endif
#ifdef CONFIG_VND_WFI
    ATM_VS_SET(WFI_CMD),
#endif
#ifdef CONFIG_VND_NO_CLOCK
    ATM_VS_SET(NO_CLOCK_CMD),
#endif
    ATM_VS_SET(EN_TXCW_CMD),
    ATM_VS_SET(FREQCAL_CMD),
    ATM_VS_SET(MM_R_CMD),
    ATM_VS_SET(PV_TEST_CMD),
};

#endif // CONFIG_BT_HCI_RAW_CMD_EXT

static int atm_hci_uart_h4_send(struct net_buf *buf)
{
    k_fifo_put(&uart_tx_queue, buf);
    uart_irq_tx_enable(hci_uart_dev);
    return 0;
}

static int h4_read(struct device const *uart, uint8_t *buf, size_t len)
{
    return uart_fifo_read(uart, buf, len);
}

static bool valid_type(uint8_t type)
{
    return (type == H4_CMD) || (type == H4_ACL) || (type == H4_ISO);
}

/* Function expects that type is validated and only CMD, ISO or ACL will be
   used.
*/
static uint32_t get_len(uint8_t const *hdr_buf, uint8_t type)
{
    switch (type) {
	case H4_CMD:
	    return ((struct bt_hci_cmd_hdr const *)hdr_buf)->param_len;
	case H4_ISO:
	    return bt_iso_hdr_len(
		sys_le16_to_cpu(((struct bt_hci_iso_hdr const *)hdr_buf)->len));
	case H4_ACL:
	    return sys_le16_to_cpu(
		((struct bt_hci_acl_hdr const *)hdr_buf)->len);
	default:
	    LOG_ERR("Invalid type: %u", type);
	    return 0;
    }
}

/* Function expects that type is validated and only CMD, ISO or ACL will be
   used.
*/
static int hdr_len(uint8_t type)
{
    switch (type) {
	case H4_CMD:
	    return sizeof(struct bt_hci_cmd_hdr);
	case H4_ISO:
	    return sizeof(struct bt_hci_iso_hdr);
	case H4_ACL:
	    return sizeof(struct bt_hci_acl_hdr);
	default:
	    LOG_ERR("Invalid type: %u", type);
	    return 0;
    }
}

static void rx_isr(void)
{
    static struct net_buf *buf;
    static int remaining;
    static uint8_t state;
    static uint8_t type;
    static uint8_t hdr_buf[MAX(sizeof(struct bt_hci_cmd_hdr),
	sizeof(struct bt_hci_acl_hdr))];
    int read;
    do {
	switch (state) {
	    case ST_IDLE: {
		/* Get packet type */
		read = h4_read(hci_uart_dev, &type, sizeof(type));
		/* since we read in loop until no data is in the fifo,
		 * it is possible that read = 0.
		 */
		if (read) {
		    if (valid_type(type)) {
			/* Get expected header size and switch
			 * to receiving header.
			 */
			remaining = hdr_len(type);
			state = ST_HDR;
		    } else {
			LOG_ERR("Unknown header %d", type);
		    }
		}
	    } break;
	    case ST_HDR: {
		read = h4_read(hci_uart_dev,
		    &hdr_buf[hdr_len(type) - remaining], remaining);
		remaining -= read;
		if (!remaining) {
		    /* Header received. Allocate buffer and get
		     * payload length. If allocation fails leave
		     * interrupt. On failed allocation state machine
		     * is reset.
		     */
		    buf = bt_buf_get_tx(BT_BUF_H4, K_NO_WAIT, &type,
			sizeof(type));
		    if (!buf) {
			LOG_ERR("No available command buffers!");
			state = ST_IDLE;
			return;
		    }

		    remaining = get_len(hdr_buf, type);
		    net_buf_add_mem(buf, hdr_buf, hdr_len(type));
		    if (remaining > net_buf_tailroom(buf)) {
			LOG_ERR("Not enough space in buffer");
			net_buf_unref(buf);
			state = ST_DISCARD;
		    } else {
			state = ST_PAYLOAD;
		    }
		}
	    } break;
	    case ST_PAYLOAD: {
		read = h4_read(hci_uart_dev, net_buf_tail(buf), remaining);
		buf->len += read;
		remaining -= read;
		if (!remaining) {
		    /* Packet received */
		    k_fifo_put(&tx_queue, buf);
		    state = ST_IDLE;
		}
	    } break;
	    case ST_DISCARD: {
		uint8_t discard[H4_DISCARD_LEN];
		size_t to_read = MIN(remaining, sizeof(discard));

		read = h4_read(hci_uart_dev, discard, to_read);
		remaining -= read;
		if (!remaining) {
		    state = ST_IDLE;
		}
	    } break;
	    default: {
		read = 0;
		__ASSERT_NO_MSG(0);
	    } break;
	}
    } while (read);
}

static void tx_isr(void)
{
    static struct net_buf *buf;

    if (!buf) {
	buf = k_fifo_get(&uart_tx_queue, K_NO_WAIT);
	if (!buf) {
	    uart_irq_tx_disable(hci_uart_dev);
	    return;
	}
    }
    int len = uart_fifo_fill(hci_uart_dev, buf->data, buf->len);
    net_buf_pull(buf, len);
    if (!buf->len) {
	net_buf_unref(buf);
	buf = NULL;
    }
}

static void bt_uart_isr(struct device const *unused, void *user_data)
{
    ARG_UNUSED(unused);
    ARG_UNUSED(user_data);

    if (uart_irq_rx_ready(hci_uart_dev)) {
	rx_isr();
    }

    if (uart_irq_tx_ready(hci_uart_dev)){
	tx_isr();
    }
}

static void tx_thread(void *p1, void *p2, void *p3)
{
    for (;;) {
	/* Wait until a buffer is available */
	struct net_buf *buf = k_fifo_get(&tx_queue, K_FOREVER);
	/* Pass buffer to the stack */
	int err = bt_send(buf);
	if (err) {
	    net_buf_unref(buf);
	}
	/* Give other threads a chance to run if tx_queue keeps getting
	 * new data all the time.
	 */
	k_yield();
    }
}

static void rx_thread(void *p1, void *p2, void *p3)
{
    /* incoming events and data from the controller */
    static K_FIFO_DEFINE(rx_queue);

    /* Enable the raw interface, this will in turn open the HCI driver */
    bt_enable_raw(&rx_queue);

#ifdef CONFIG_BT_HCI_RAW_CMD_EXT
    bt_hci_raw_cmd_ext_register(cmd_ext, ARRAY_SIZE(cmd_ext));
    LOG_DBG("HCI raw cmd extention register done");
#endif

    for (;;) {
	struct net_buf *buf = k_fifo_get(&rx_queue, K_FOREVER);
	int err = atm_hci_uart_h4_send(buf);
	if (err) {
	    LOG_ERR("Failed to send atm_hci_uart_h4_send");
	}
	k_yield();
    }
}

void atm_uart_init(void)
{
    LOG_DBG("start");
    if (!device_is_ready(hci_uart_dev)) {
	LOG_DBG("HCI UART %s is not ready", hci_uart_dev->name);
#ifdef CONFIG_AUTO_TEST
	ATM_TEST_FAILED();
#endif
	return;
    }

    uart_irq_rx_disable(hci_uart_dev);
    uart_irq_tx_disable(hci_uart_dev);

    uart_irq_callback_set(hci_uart_dev, bt_uart_isr);

    uart_irq_rx_enable(hci_uart_dev);
    LOG_DBG("done");
    return;
}

void atm_hci_init(void)
{
    LOG_DBG("start");

    __ASSERT(hci_uart_dev, "UART device is NULL");

    if (IS_ENABLED(CONFIG_BT_WAIT_NOP)) {
	/* Issue a Command Complete with NOP */
	const struct {
	    uint8_t const h4;
	    struct bt_hci_evt_hdr const hdr;
	    struct bt_hci_evt_cmd_complete const cc;
	} __packed cc_evt = {
	    .h4 = H4_EVT,
	    .hdr =
		{
		    .evt = BT_HCI_EVT_CMD_COMPLETE,
		    .len = sizeof(struct bt_hci_evt_cmd_complete),
		},
	    .cc =
		{
		    .ncmd = 1,
		    .opcode = sys_cpu_to_le16(BT_OP_NOP),
		},
	};

	for (int i = 0; i < sizeof(cc_evt); i++) {
	    uart_poll_out(hci_uart_dev, *(((uint8_t const *)&cc_evt) + i));
	}
    }

    /* Spawn the TX thread and start feeding commands and data to the
     * controller
     */
    k_thread_create(&tx_thread_data, tx_thread_stack,
	K_THREAD_STACK_SIZEOF(tx_thread_stack), tx_thread, NULL, NULL, NULL,
	0 , 0, K_NO_WAIT);
    k_thread_name_set(&tx_thread_data, "HCI uart TX");

    /* Spawn the RX thread and passthrough incoming events and data from the
     * controller
     */
    k_thread_create(&rx_thread_data, rx_thread_stack,
	K_THREAD_STACK_SIZEOF(rx_thread_stack), rx_thread, NULL, NULL, NULL,
	0 , 0, K_NO_WAIT);
    k_thread_name_set(&rx_thread_data, "HCI uart RX");

    printk("atm_hci_init done\n");

#ifdef CONFIG_AUTO_TEST
    ATM_TEST_PASSED();
#endif
}

#ifdef CONFIG_BT_HCI_RAW_CMD_EXT
void atm_vendor_handler_register(struct vendor_handler const *hdrs, size_t size)
{
    vendor_hdlr = hdrs;
    vendor_hdlr_size = size;
}
#endif
