/*
 * Copyright (c) 2021, Linaro Limited.
 * Copyright (c) 2022-2026, Atmosic
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#define DT_DRV_COMPAT atmosic_atm_uart

/**
 * @brief Driver for UART on Atmosic
 *
 * UART has two wires for RX and TX, and two optional wires for CTS and RTS.
 */
#include <zephyr/kernel.h>
#include <zephyr/drivers/uart.h>
#include <zephyr/irq.h>
#include <soc.h>
#include <errno.h>
#ifdef CONFIG_PM
#include <zephyr/pm/pm.h>
#include <zephyr/pm/policy.h>
#endif
#ifdef CONFIG_UART_ATM_HOST_DETECT
#include <zephyr/drivers/gpio.h>
#include <zephyr/drivers/uart_atm.h>
#include <zephyr/logging/log.h>
LOG_MODULE_REGISTER(uart_atm_rx_idle, CONFIG_UART_LOG_LEVEL);
#endif

#include "arch.h"
#include "at_pinmux.h"
#include "at_wrpr.h"
#if defined(CONFIG_PM) || defined(CONFIG_UART_ATM_HOST_DETECT)
#include "pinmux.h"
#endif
#ifdef CONFIG_PM
#include "at_clkrstgen.h"
#include "timer.h"
#endif

#ifdef CMSDK_AT_UART0_NONSECURE
#include "at_apb_uart_regs_core_macro.h"
#else
#define CMSDK_AT_APB_UART_TypeDef CMSDK_UART_TypeDef
#endif

#if defined(CONFIG_SOC_SERIES_ATMX2) || defined(CONFIG_SOC_SERIES_ATM33) || \
	(defined(CONFIG_SOC_SERIES_ATM34) && !defined(CMSDK_AT_UART_STATE__RX_IDLE__READ))
#define RTS_GPIO_REQUIRED(inst) DT_INST_NODE_HAS_PROP(inst, rts_pin)
#else
#define RTS_GPIO_REQUIRED(inst) 0
#endif

#define UART_PM_NOTIFIER(inst)                                                                     \
	UTIL_OR(CONFIG_UART_ATM_TX_GLITCH, DT_INST_NODE_HAS_PROP(inst, rts_pin))
#define UART_PM_ENTRY(inst)                                                                        \
	UTIL_OR(CONFIG_UART_ATM_TX_GLITCH, RTS_GPIO_REQUIRED(inst))

typedef void (*set_callback_t)(void);

struct uart_atm_config {
	volatile CMSDK_AT_APB_UART_TypeDef *uart;
	uint32_t sys_clk_freq;
#ifdef CONFIG_UART_INTERRUPT_DRIVEN
	uart_irq_config_func_t irq_config_func;
#endif
	bool has_cts_pin;
	bool has_rts_pin;
	bool has_rx_pin;
#ifdef CONFIG_UART_ATM_HOST_DETECT
	uint8_t rx_pin;
	const struct device *gpio_dev;
#endif
};

/* Device data structure */
struct uart_atm_dev_data {
	uint32_t baudrate;
	bool hw_flow_control;
	set_callback_t config_pins;
#ifdef CONFIG_UART_INTERRUPT_DRIVEN
	uart_irq_callback_user_data_t irq_cb;
	void *irq_cb_data;
#endif
#ifdef CONFIG_PM
	const struct device *dev;
	struct k_thread *pm_rx_thread;
	struct k_sem *pm_rx_sem;
	struct k_timer *pm_rx_timer;
	k_thread_stack_t *pm_rx_thread_stack;
	size_t pm_rx_thread_stack_sizeof;
	k_tid_t pm_rx_tid;
	uint32_t pm_rx_sleeping_when_set;
	uint8_t pm_rx_events;
	bool pm_rx_sleeping;
	bool pm_rx_constraint_on;
	bool pm_rx_stopped;

	bool tx_poll_stream_on;
	bool tx_int_stream_on;
	bool pm_tx_constraint_on;
	bool tx_constraint_release_cancel;
	uint32_t tx_release_stamp;
	struct k_work tx_constraint_release_work;
#endif
#ifdef CONFIG_UART_ATM_HOST_DETECT
	uart_atm_rx_callback_t rx_idle_callback;
	struct gpio_callback rx_gpio_cb;
#endif
};

static const struct uart_driver_api uart_atm_driver_api;

#ifdef CONFIG_PM
/*
 * Low priority work queue for TX constraint release.
 * Using priority 14 (K_LOWEST_APPLICATION_THREAD_PRIO) to avoid
 * preempting other threads when releasing PM constraints.
 */
#define UART_ATM_PM_WQ_PRIORITY K_LOWEST_APPLICATION_THREAD_PRIO

static K_THREAD_STACK_DEFINE(uart_atm_pm_wq_stack, CONFIG_UART_ATM_PM_WQ_STACK_SIZE);
static struct k_work_q uart_atm_pm_work_q;

static int uart_atm_pm_wq_init(void)
{
	k_work_queue_init(&uart_atm_pm_work_q);
	k_work_queue_start(&uart_atm_pm_work_q, uart_atm_pm_wq_stack,
			   K_THREAD_STACK_SIZEOF(uart_atm_pm_wq_stack), UART_ATM_PM_WQ_PRIORITY,
			   NULL);
	k_thread_name_set(&uart_atm_pm_work_q.thread, "uart_pm_wq");
	return 0;
}

/* Initialize PM work queue at POST_KERNEL stage when scheduler is ready */
SYS_INIT(uart_atm_pm_wq_init, POST_KERNEL, 0);

static void uart_atm_pm_rx_constraint_set(const struct device *dev)
{
	struct uart_atm_dev_data *data = dev->data;

	if (!data->pm_rx_constraint_on) {
		data->pm_rx_constraint_on = true;
		pm_policy_state_lock_get(PM_STATE_SUSPEND_TO_RAM, PM_ALL_SUBSTATES);
	}
}

static void uart_atm_pm_rx_constraint_release(const struct device *dev)
{
	struct uart_atm_dev_data *data = dev->data;

	if (data->pm_rx_constraint_on) {
		data->pm_rx_constraint_on = false;
		pm_policy_state_lock_put(PM_STATE_SUSPEND_TO_RAM, PM_ALL_SUBSTATES);
	}
}

static void uart_atm_pm_tx_constraint_set(const struct device *dev)
{
	struct uart_atm_dev_data *data = dev->data;

	/* Signal any pending release delay to exit early */
	data->tx_constraint_release_cancel = true;

	/* Cancel any pending work */
	k_work_cancel(&data->tx_constraint_release_work);

	if (!data->pm_tx_constraint_on) {
		data->pm_tx_constraint_on = true;
		pm_policy_state_lock_get(PM_STATE_SUSPEND_TO_RAM, PM_ALL_SUBSTATES);
		pm_policy_state_lock_get(PM_STATE_SOFT_OFF, PM_ALL_SUBSTATES);
	}
}

static void uart_atm_pm_tx_constraint_release(const struct device *dev)
{
	struct uart_atm_dev_data *data = dev->data;

	if (data->pm_tx_constraint_on) {
		data->pm_tx_constraint_on = false;
		pm_policy_state_lock_put(PM_STATE_SUSPEND_TO_RAM, PM_ALL_SUBSTATES);
		pm_policy_state_lock_put(PM_STATE_SOFT_OFF, PM_ALL_SUBSTATES);
	}
}

/* Number of bit times to wait before releasing TX constraint after TX FIFO empty.
 * This ensures the shift register has finished transmitting the last byte.
 * 10 bit times covers: 1 start bit + 8 data bits + 0 parity bit + 1 stop bits
 */
#define TX_CONSTRAINT_RELEASE_BIT_TIMES 10

static void uart_atm_pm_tx_constraint_release_work_handler(struct k_work *work)
{
	struct uart_atm_dev_data *data =
		CONTAINER_OF(work, struct uart_atm_dev_data, tx_constraint_release_work);
	const struct device *dev = data->dev;
	const struct uart_atm_config *const dev_cfg = dev->config;
	uint32_t request_stamp = data->tx_release_stamp;

	/* Calculate LPC ticks for 10 bit times at current baudrate */
	uint32_t lpc_ticks = atm_to_lpc_round_up(data->baudrate, TX_CONSTRAINT_RELEASE_BIT_TIMES);

	/* Wait for the calculated delay using precise LPC timer */
	ATM_TIMER_DO
	{
		/* Check if cancelled during delay */
		if (data->tx_constraint_release_cancel || request_stamp != data->tx_release_stamp) {
			return;
		}
#ifdef CMSDK_AT_UART_STATE__TX_IDLE__READ
		/* TX became idle, release constraint */
		if (CMSDK_AT_UART_STATE__TX_IDLE__READ(dev_cfg->uart->STATE)) {
			unsigned int key = irq_lock();
			if (CMSDK_AT_UART_STATE__TX_IDLE__READ(dev_cfg->uart->STATE)) {
				uart_atm_pm_tx_constraint_release(dev);
			}
			irq_unlock(key);
			return;
		}
#endif
	}
	ATM_TIMER_WHILE_LPC_DELAY(lpc_ticks);

	/* Lock interrupts to prevent race with new TX enqueue */
	unsigned int key = irq_lock();

	/* Check if cancelled during delay */
	if (data->tx_constraint_release_cancel || request_stamp != data->tx_release_stamp) {
		irq_unlock(key);
		return;
	}

	/* TX FIFO must be empty */
	ASSERT_ERR(dev_cfg->uart->TX_FIFO_SPACES == CMSDK_AT_UART_TX_FIFO_SPACES__RESET_VALUE);

#ifdef CMSDK_AT_UART_STATE__TX_IDLE__READ
	/* TX must be idle */
	ASSERT_ERR(CMSDK_AT_UART_STATE__TX_IDLE__READ(dev_cfg->uart->STATE));
#endif
	uart_atm_pm_tx_constraint_release(dev);
	irq_unlock(key);
}

static void uart_atm_pm_tx_constraint_release_request(const struct device *dev)
{
	struct uart_atm_dev_data *data = dev->data;

	/* Clear cancel flag before starting delay */
	data->tx_constraint_release_cancel = false;
	data->tx_release_stamp = k_cycle_get_32();

	/* Submit work to low priority queue to avoid preempting other threads */
	k_work_submit_to_queue(&uart_atm_pm_work_q, &data->tx_constraint_release_work);
}

#define EVT_WAKE    (1 << 0)
#define EVT_RECV    (1 << 1)
#define EVT_TIMEOUT (1 << 2)
#define EVT_ALL     ((1 << 3) - 1)

static void uart_atm_pm_rx_post(const struct device *dev, uint8_t events)
{
	struct uart_atm_dev_data *const dev_data = dev->data;

	unsigned int key = irq_lock();
	// Check under lock to prevent posting events after stop
	if (dev_data->pm_rx_stopped) {
		irq_unlock(key);
		return;
	}
	dev_data->pm_rx_events |= events;
	irq_unlock(key);

	k_sem_give(dev_data->pm_rx_sem);
}

static void uart_atm_pm_rx_activity(const struct device *dev)
{
	const struct uart_atm_config *const dev_cfg = dev->config;
	struct uart_atm_dev_data *const dev_data = dev->data;
	if (dev_cfg->has_rts_pin && dev_data->hw_flow_control) {
		uart_atm_pm_rx_post(dev, EVT_RECV);
	}
}

static void uart_atm_pm_rx_start(const struct device *dev)
{
	const struct uart_atm_config *const dev_cfg = dev->config;
	struct uart_atm_dev_data *const dev_data = dev->data;

	if (dev_cfg->has_rts_pin) {
		dev_data->pm_rx_stopped = false;
		uart_atm_pm_rx_activity(dev);
		k_thread_start(dev_data->pm_rx_tid);
	}
	/*
	 * rx_start runs from the public uart_irq_rx_enable / uart_configure paths,
	 * which can race with the pm_rx thread's set/release. irq_lock() serializes
	 * the constraint update against that thread; see uart_atm_pm_rx_constraint_set.
	 */
	unsigned int key = irq_lock();
	uart_atm_pm_rx_constraint_set(dev);
	irq_unlock(key);
}

static void uart_atm_pm_rx_stop(const struct device *dev)
{
	const struct uart_atm_config *const dev_cfg = dev->config;
	struct uart_atm_dev_data *const dev_data = dev->data;

	if (dev_cfg->has_rts_pin) {
		dev_data->pm_rx_stopped = true;
		k_timer_stop(dev_data->pm_rx_timer);
	}
	/* rx_stop runs from public uart_irq_rx_disable; serialize against the
	 * pm_rx thread as in rx_start.
	 */
	unsigned int key = irq_lock();
	uart_atm_pm_rx_constraint_release(dev);
	irq_unlock(key);
}

static void uart_atm_pm_rx_timeout(struct k_timer *timer)
{
	const struct device *dev = k_timer_user_data_get(timer);
	uart_atm_pm_rx_post(dev, EVT_TIMEOUT);
}

static void uart_atm_pm_rx_events(const struct device *dev, uint32_t events)
{
	const struct uart_atm_config *const dev_cfg = dev->config;
	struct uart_atm_dev_data *const dev_data = dev->data;

	if (events & EVT_WAKE) {
		// UART baud accuracy requires a stable xtal
		__UNUSED uint32_t then = atm_get_sys_time();
#ifdef PSEQ_RADIO_STATUS__XTAL_STABLE__READ
		WRPR_CTRL_PUSH(CMSDK_PSEQ, WRPR_CTRL__CLK_ENABLE) {
			while (!PSEQ_RADIO_STATUS__XTAL_STABLE__READ(CMSDK_PSEQ->RADIO_STATUS)) {
				k_yield();
				ASSERT_ERR(atm_get_sys_time() - then < 164); // 5ms
			}
		} WRPR_CTRL_POP();
#elif defined(CLKRSTGEN_RADIO_STATUS__XTAL_STABLE__READ)
		while (!CLKRSTGEN_RADIO_STATUS__XTAL_STABLE__READ(
			CMSDK_CLKRSTGEN_NONSECURE->RADIO_STATUS)) {
			k_yield();
			ASSERT_ERR(atm_get_sys_time() - then < 164); // 5ms
		}
#endif

		// Release RTS override
		dev_cfg->uart->HW_FLOW_OVRD &= ~(CMSDK_UART_HW_FLOW_OVRD_NRTS_OVRD_Msk |
						 CMSDK_UART_HW_FLOW_OVRD_NRTS_VAL_Msk);

		/* Fold the constraint set into the existing critical section so it
		 * is serialized against rx_start/rx_stop without an extra irq_lock.
		 * Keep the original order: acquire the PM constraint before clearing
		 * pm_rx_sleeping, so there is no window where the flag says "awake"
		 * while nothing holds the constraint (the PM state_exit notifier reads
		 * pm_rx_sleeping to decide whether to re-post EVT_WAKE).
		 */
		unsigned int key = irq_lock();
		uart_atm_pm_rx_constraint_set(dev);
		dev_data->pm_rx_sleeping = false;
		dev_data->pm_rx_events &= ~EVT_TIMEOUT;
		k_timer_start(dev_data->pm_rx_timer, K_MSEC(CONFIG_UART_ATM_AFTER_WAKE_MS),
			      K_NO_WAIT);
		irq_unlock(key);

		// Keep going, check EVT_RECV
		events &= ~EVT_TIMEOUT;
	}
	if (events & EVT_RECV) {
		ASSERT_INFO(!dev_data->pm_rx_sleeping, 0,
			    atm_get_sys_time() - dev_data->pm_rx_sleeping_when_set);

		// Release RTS override
		dev_cfg->uart->HW_FLOW_OVRD &= ~(CMSDK_UART_HW_FLOW_OVRD_NRTS_OVRD_Msk |
						 CMSDK_UART_HW_FLOW_OVRD_NRTS_VAL_Msk);

		unsigned int key = irq_lock();
		dev_data->pm_rx_events &= ~EVT_TIMEOUT;
		k_timer_start(dev_data->pm_rx_timer, K_MSEC(CONFIG_UART_ATM_AFTER_ACTIVE_MS),
			      K_NO_WAIT);
		irq_unlock(key);

		return;
	}
	if (events & EVT_TIMEOUT) {
		if (dev_data->pm_rx_sleeping) {
			// Release RTS override
			dev_cfg->uart->HW_FLOW_OVRD &= ~(CMSDK_UART_HW_FLOW_OVRD_NRTS_OVRD_Msk |
							 CMSDK_UART_HW_FLOW_OVRD_NRTS_VAL_Msk);

			/* Serialize the constraint set against rx_start/rx_stop. */
			unsigned int key = irq_lock();
			uart_atm_pm_rx_constraint_set(dev);
			irq_unlock(key);
			dev_data->pm_rx_sleeping = false;
			k_timer_start(dev_data->pm_rx_timer, K_MSEC(CONFIG_UART_ATM_AFTER_WAKE_MS),
				      K_NO_WAIT);
			return;
		}

		// Deassert RTS
		dev_cfg->uart->HW_FLOW_OVRD |= (CMSDK_UART_HW_FLOW_OVRD_NRTS_OVRD_Msk |
						CMSDK_UART_HW_FLOW_OVRD_NRTS_VAL_Msk);

#ifdef CMSDK_AT_UART_STATE__RX_IDLE__READ
		// Account for latency of cable length and peer data equipment
		uint32_t lpc_ticks = 1 + CONFIG_UART_ATM_RTT_LPC;
		ASSERT_ERR(lpc_ticks < 164); // 5ms
		ATM_TIMER_DO
		{
			if (dev_data->pm_rx_events & EVT_RECV) {
				return;
			}

			// Rx in flight?  Let it complete.
			if (!CMSDK_AT_UART_STATE__RX_IDLE__READ(dev_cfg->uart->STATE)) {
				uart_atm_pm_rx_activity(dev);
				return;
			}
		}
		ATM_TIMER_WHILE_LPC_DELAY(lpc_ticks);
#else
		// Rx might be in flight, so make sure it has time to complete.
		// Frame LPC cycles = round(BAUDDIV * 10 bits * lpc_rcos_hz() / UART_CLK)
		uint32_t frame_lpc =
			atm_to_lpc_round(dev_cfg->sys_clk_freq / 10, dev_cfg->uart->BAUDDIV);
		// Account for latency of cable length and peer data equipment
		uint32_t lpc_ticks = 1 + CONFIG_UART_ATM_RTT_LPC + frame_lpc;
		ASSERT_ERR(lpc_ticks < 164); // 5ms
		ATM_TIMER_DO
		{
			if (dev_data->pm_rx_events & EVT_RECV) {
				return;
			}

			// Anything in Rx FIFO?
			if (dev_cfg->uart->STATE & CMSDK_UART_STATE_RXBF_Msk) {
				uart_atm_pm_rx_activity(dev);
				return;
			}
		}
		ATM_TIMER_WHILE_LPC_DELAY(lpc_ticks);
#endif

		/* Serialize the constraint release against rx_start/rx_stop. */
		unsigned int key = irq_lock();
		uart_atm_pm_rx_constraint_release(dev);
		irq_unlock(key);
		dev_data->pm_rx_sleeping = true;
		dev_data->pm_rx_sleeping_when_set = atm_get_sys_time();
		k_timer_start(dev_data->pm_rx_timer, K_MSEC(CONFIG_UART_ATM_MAX_SLEEP_MS),
			      K_NO_WAIT);
	}
}

static void uart_atm_pm_rx_thread(void *p1, void *p2, void *p3)
{
	const struct device *dev = p1;
	ARG_UNUSED(p2);
	ARG_UNUSED(p3);

	struct uart_atm_dev_data *const dev_data = dev->data;
	for (;;) {
		k_sem_take(dev_data->pm_rx_sem, K_FOREVER);

		unsigned int key = irq_lock();
		uint32_t events = dev_data->pm_rx_events;
		dev_data->pm_rx_events &= ~events;
		irq_unlock(key);

		uart_atm_pm_rx_events(dev, events);
	}
}
#endif /* CONFIG_PM */

/**
 * @brief Set the baud rate
 *
 * This routine set the given baud rate for the UART.
 *
 * @param dev UART device struct
 */
static void baudrate_set(const struct device *dev)
{
	const struct uart_atm_config *const dev_cfg = dev->config;
	struct uart_atm_dev_data *const dev_data = dev->data;
	const uint32_t sys_clk = dev_cfg->sys_clk_freq;
	const uint32_t baudrate = dev_data->baudrate;
	/*
	 * If baudrate and/or sys_clk_freq are 0 the configuration remains
	 * unchanged. It can be useful in case that Zephyr it is run via
	 * a bootloader that brings up the serial and sets the baudrate.
	 */
	if ((baudrate != 0U) && (sys_clk != 0U)) {
		/* calculate baud rate divisor */
		uint32_t bauddiv = (sys_clk + (baudrate / 2)) / baudrate;
		if (bauddiv == dev_cfg->uart->BAUDDIV) {
			return;
		}
#ifdef CMSDK_AT_UART_STATE__TX_IDLE__READ
		uint32_t save_hw_flow_ovrd = dev_cfg->uart->HW_FLOW_OVRD;
		dev_cfg->uart->HW_FLOW_OVRD |= CMSDK_UART_HW_FLOW_OVRD_NCTS_OVRD_Msk;
		while (!CMSDK_AT_UART_STATE__TX_IDLE__READ(dev_cfg->uart->STATE))
			;
		dev_cfg->uart->HW_FLOW_OVRD = save_hw_flow_ovrd;
#endif
		dev_cfg->uart->BAUDDIV = bauddiv;
	}
}

/**
 * @brief Initialize UART channel
 *
 * This routine is called to reset the chip in a quiescent state.
 * It is assumed that this function is called only once per UART.
 *
 * @param dev UART device struct
 *
 * @return 0
 */
static int uart_atm_init(const struct device *dev)
{
	struct uart_atm_dev_data *const dev_data = dev->data;
	const struct uart_atm_config *const dev_cfg = dev->config;

	dev_data->config_pins();

	/* Set baud rate */
	baudrate_set(dev);

	/* Enable transmitter */
	dev_cfg->uart->CTRL = CMSDK_UART_CTRL_TXEN_Msk;

#ifdef CONFIG_UART_INTERRUPT_DRIVEN
	dev_cfg->irq_config_func(dev);
#endif

	uint32_t cts_ovrd = (dev_cfg->has_cts_pin && dev_data->hw_flow_control)
				    ? 0
				    : CMSDK_UART_HW_FLOW_OVRD_NCTS_OVRD_Msk;
	uint32_t rts_ovrd = (dev_cfg->has_rts_pin && dev_data->hw_flow_control)
				    ? 0
				    : CMSDK_UART_HW_FLOW_OVRD_NRTS_OVRD_Msk;
	dev_cfg->uart->HW_FLOW_OVRD = cts_ovrd | rts_ovrd;

#ifdef CONFIG_PM
	/* Store device pointer for work handler */
	dev_data->dev = dev;

	/* Initialize TX constraint release work */
	k_work_init(&dev_data->tx_constraint_release_work,
		    uart_atm_pm_tx_constraint_release_work_handler);

	if (dev_cfg->has_rts_pin) {
		k_sem_init(dev_data->pm_rx_sem, 0, 1);
		k_timer_init(dev_data->pm_rx_timer, uart_atm_pm_rx_timeout, NULL);
		k_timer_user_data_set(dev_data->pm_rx_timer, (void *)dev);

		dev_data->pm_rx_tid = k_thread_create(
			dev_data->pm_rx_thread, dev_data->pm_rx_thread_stack,
			dev_data->pm_rx_thread_stack_sizeof, uart_atm_pm_rx_thread, (void *)dev,
			NULL, NULL, K_PRIO_COOP(CONFIG_UART_ATM_PM_RX_THREAD_PRIO), 0, K_FOREVER);
		k_thread_name_set(dev_data->pm_rx_tid, "ATM UART Rx PM");
	}
#endif

	return 0;
}

#ifdef CONFIG_UART_USE_RUNTIME_CONFIGURE
static int uart_atm_configure(const struct device *dev, const struct uart_config *cfg)
{
	const struct uart_atm_config *const dev_cfg = dev->config;
	struct uart_atm_dev_data *const dev_data = dev->data;

	if (cfg->stop_bits != UART_CFG_STOP_BITS_1) {
		return -ENOTSUP;
	}

	if (cfg->data_bits != UART_CFG_DATA_BITS_8) {
		return -ENOTSUP;
	}

	if (cfg->parity != UART_CFG_PARITY_NONE) {
		return -ENOTSUP;
	}

	switch (cfg->flow_ctrl) {
	case UART_CFG_FLOW_CTRL_NONE:
		dev_data->hw_flow_control = false;
		dev_cfg->uart->HW_FLOW_OVRD = (CMSDK_UART_HW_FLOW_OVRD_NCTS_OVRD_Msk |
					       CMSDK_UART_HW_FLOW_OVRD_NRTS_OVRD_Msk);
#ifdef CONFIG_PM
		uart_atm_pm_rx_start(dev);
#endif
		break;
	case UART_CFG_FLOW_CTRL_RTS_CTS:
		if (!dev_cfg->has_rts_pin || !dev_cfg->has_cts_pin) {
			return -ENOTSUP;
		}
		dev_data->hw_flow_control = true;
		dev_cfg->uart->HW_FLOW_OVRD = 0;
#ifdef CONFIG_PM
		uart_atm_pm_rx_start(dev);
#endif
		break;
	default:
		return -ENOTSUP;
	}

	dev_data->baudrate = cfg->baudrate;
	baudrate_set(dev);

	return 0;
}

static int uart_atm_config_get(const struct device *dev, struct uart_config *cfg)
{
	const struct uart_atm_config *const dev_cfg = dev->config;
	const struct uart_atm_dev_data *const dev_data = dev->data;
	const uint32_t hw_flow_reg = dev_cfg->uart->HW_FLOW_OVRD;

	cfg->stop_bits = UART_CFG_STOP_BITS_1;
	cfg->data_bits = UART_CFG_DATA_BITS_8;
	cfg->parity = UART_CFG_PARITY_NONE;

	if ((hw_flow_reg & (CMSDK_UART_HW_FLOW_OVRD_NCTS_OVRD_Msk |
			    CMSDK_UART_HW_FLOW_OVRD_NRTS_OVRD_Msk)) == 0) {
		cfg->flow_ctrl = UART_CFG_FLOW_CTRL_RTS_CTS;
	} else {
		cfg->flow_ctrl = UART_CFG_FLOW_CTRL_NONE;
	}

	cfg->baudrate = dev_data->baudrate;

	return 0;
}
#endif /* CONFIG_UART_USE_RUNTIME_CONFIGURE */

/**
 * @brief Poll the device for input.
 *
 * @param dev UART device struct
 * @param c Pointer to character
 *
 * @return 0 if a character arrived, -1 if the input buffer if empty.
 */

static int uart_atm_poll_in(const struct device *dev, unsigned char *c)
{
	const struct uart_atm_config *const dev_cfg = dev->config;
	bool rx_start;
	int ret = 0;

	if (!dev_cfg->has_rx_pin) {
		return -1;
	}

	unsigned int key = irq_lock();
	do {
		rx_start = !(dev_cfg->uart->CTRL & CMSDK_UART_CTRL_RXEN_Msk);
		if (rx_start) {
			dev_cfg->uart->CTRL |= CMSDK_UART_CTRL_RXEN_Msk;
		}

		/* If the receiver is not ready returns -1 */
		if (!(dev_cfg->uart->STATE & CMSDK_UART_STATE_RXBF_Msk)) {
			ret = -1;
			break;
		}

		/* got a character */
		*c = (unsigned char)dev_cfg->uart->DATA;
	} while (0);
	irq_unlock(key);

#ifdef CONFIG_PM
	if (rx_start) {
		uart_atm_pm_rx_start(dev);
	} else if (!ret) {
		uart_atm_pm_rx_activity(dev);
	}
#endif
	return ret;
}

/**
 * @brief Output a character in polled mode.
 *
 * Checks if the transmitter is empty. If empty, a character is written to
 * the data register.
 *
 * @param dev UART device struct
 * @param c Character to send
 */
static void uart_atm_poll_out(const struct device *dev, unsigned char c)
{
	const struct uart_atm_config *const dev_cfg = dev->config;
	unsigned int key;

	/* Wait for FIFO to be empty */
	for (;;) {
		if (dev_cfg->uart->TX_FIFO_SPACES == CMSDK_AT_UART_TX_FIFO_SPACES__RESET_VALUE) {
			key = irq_lock();
			if (dev_cfg->uart->TX_FIFO_SPACES ==
			    CMSDK_AT_UART_TX_FIFO_SPACES__RESET_VALUE) {
				break;
			}
			irq_unlock(key);
		}
	}

#ifdef CONFIG_PM
	struct uart_atm_dev_data *data = dev->data;

	/* If an interrupt transmission is in progress, the pm constraint
	 * is already managed by the call of uart_atm_irq_tx_[en|dis]able
	 */
	if (!data->tx_poll_stream_on && !data->tx_int_stream_on) {
		data->tx_poll_stream_on = true;

		/* Don't allow system to suspend until stream transmission has completed */
		uart_atm_pm_tx_constraint_set(dev);

		/* Enable TX interrupt so we can release suspend constraint when done */
		dev_cfg->uart->CTRL |= CMSDK_UART_CTRL_TXIRQEN_Msk;
	}
#endif /* CONFIG_PM */

	/* Send a character */
	dev_cfg->uart->DATA = (uint32_t)c;
	irq_unlock(key);
}

/**
 * @brief Check if an error was received
 *
 * @param dev UART device struct
 *
 * @return UART_ERROR_OVERRUN if an error was detected, 0 otherwise.
 */
static int uart_atm_err_check(const struct device *dev)
{
	const struct uart_atm_config *const dev_cfg = dev->config;

	uint32_t state = dev_cfg->uart->STATE;
	int err = 0;

	dev_cfg->uart->INTCLEAR =
		CMSDK_UART_INTSTATUS_RXORIRQ_Msk | CMSDK_UART_INTSTATUS_TXORIRQ_Msk;

	if (state & CMSDK_UART_STATE_RXOR_Msk) {
		dev_cfg->uart->STATE &= ~CMSDK_UART_STATE_RXOR_Msk;
		err |= UART_ERROR_OVERRUN;
	}

	// Should not get TX overrun without driver error
	ASSERT_ERR(!(state & CMSDK_UART_STATE_TXOR_Msk));

	return err;
}

#ifdef CONFIG_UART_INTERRUPT_DRIVEN
/**
 * @brief Fill FIFO with data
 *
 * @param dev UART device struct
 * @param tx_data Data to transmit
 * @param len Number of bytes to send
 *
 * @return the number of characters that have been read
 */
static int uart_atm_fifo_fill(const struct device *dev, const uint8_t *tx_data, int len)
{
	const struct uart_atm_config *const dev_cfg = dev->config;
	uint8_t num_tx = 0U;

	unsigned int key = irq_lock();

	while (len - num_tx > 0) {
		if (dev_cfg->uart->STATE & CMSDK_UART_STATE_TXBF_Msk) {
			dev_cfg->uart->INTCLEAR = CMSDK_UART_INTSTATUS_TXIRQ_Msk;
			break;
		}
		dev_cfg->uart->DATA = (uint32_t)tx_data[num_tx++];
	}

	irq_unlock(key);

	return num_tx;
}

/**
 * @brief Read data from FIFO
 *
 * @param dev UART device struct
 * @param rx_data Pointer to data container
 * @param size Container size in bytes
 *
 * @return the number of characters that have been read
 */
static int uart_atm_fifo_read(const struct device *dev, uint8_t *rx_data, const int size)
{
	const struct uart_atm_config *const dev_cfg = dev->config;
	uint8_t num_rx = 0U;

	while (size - num_rx > 0) {
		/*
		 * When set, CMSDK_UART_STATE_RXBF_Msk indicates that RX Buffer
		 * is not empty. We keep reading either until the buffer is empty
		 * or if the size is reached.
		 */
		if (!(dev_cfg->uart->STATE & CMSDK_UART_STATE_RXBF_Msk)) {
			/* RX Buffer is empty, nothing more to read */
			dev_cfg->uart->INTCLEAR = CMSDK_UART_INTSTATUS_RXIRQ_Msk;
			// Check one more time to avoid race
			if (!(dev_cfg->uart->STATE & CMSDK_UART_STATE_RXBF_Msk)) {
				return num_rx;
			}
		}
		rx_data[num_rx++] = (unsigned char)dev_cfg->uart->DATA;
	}

	/*
	 * Do not forget to clear the RX interrupt when the size is same as
	 * available data in the RX buffer.
	 */
	if (!(dev_cfg->uart->STATE & CMSDK_UART_STATE_RXBF_Msk)) {
		dev_cfg->uart->INTCLEAR = CMSDK_UART_INTSTATUS_RXIRQ_Msk;
	}

	return num_rx;
}

/**
 * @brief Interrupt service routine.
 *
 * Calls the callback function, if exists.
 *
 * @param arg argument to interrupt service routine.
 */
static void uart_atm_isr(const struct device *dev)
{
	struct uart_atm_dev_data *data = dev->data;

#ifdef CONFIG_PM
	const struct uart_atm_config *const dev_cfg = dev->config;
	if ((dev_cfg->uart->CTRL & CMSDK_UART_CTRL_TXIRQEN_Msk) &&
	    (dev_cfg->uart->INTSTATUS & CMSDK_UART_INTSTATUS_TXIRQ_Msk)) {
		if (data->tx_poll_stream_on) {
			if (dev_cfg->uart->TX_FIFO_SPACES ==
			    CMSDK_AT_UART_TX_FIFO_SPACES__RESET_VALUE) {
				/* A poll stream transmission just completed.
				 * Schedule delayed release to ensure shift register
				 * has finished transmitting. */
				dev_cfg->uart->CTRL &= ~CMSDK_UART_CTRL_TXIRQEN_Msk;
				data->tx_poll_stream_on = false;
				uart_atm_pm_tx_constraint_release_request(dev);
			}
			dev_cfg->uart->INTCLEAR = CMSDK_UART_INTSTATUS_TXIRQ_Msk;
		} else {
			/* Stream transmission was IRQ based.  Constraint will
			 * be released at the same time TX_IN is disabled.
			 */
		}
	}
	if ((dev_cfg->uart->CTRL & CMSDK_UART_CTRL_RXIRQEN_Msk) &&
	    (dev_cfg->uart->INTSTATUS & CMSDK_UART_INTSTATUS_RXIRQ_Msk)) {
		uart_atm_pm_rx_activity(dev);
	}
#endif /* CONFIG_PM */

	/* Verify if the callback has been registered */
	if (data->irq_cb) {
		data->irq_cb(dev, data->irq_cb_data);
	}
}

/**
 * @brief Enable TX interrupt
 *
 * @param dev UART device struct
 */
static void uart_atm_irq_tx_enable(const struct device *dev)
{
	const struct uart_atm_config *const dev_cfg = dev->config;
	unsigned int key = irq_lock();

#ifdef CONFIG_PM
	struct uart_atm_dev_data *data = dev->data;
	data->tx_poll_stream_on = false;
	data->tx_int_stream_on = true;
	uart_atm_pm_tx_constraint_set(dev);
#endif

	dev_cfg->uart->CTRL |= CMSDK_UART_CTRL_TXIRQEN_Msk;
	/* The expectation is that TX is a level interrupt, active for as
	 * long as TX buffer is empty. But in CMSDK UART it's an edge
	 * interrupt, firing on a state change of TX buffer from full to
	 * empty. So, we need to "prime" it here by calling ISR directly,
	 * to get interrupt processing going, as there is no previous
	 * full state to allow a transition from full to empty buffer
	 * that will trigger a TX interrupt.
	 */
	uart_atm_isr(dev);
	irq_unlock(key);
}

/**
 * @brief Disable TX interrupt
 *
 * @param dev UART device struct
 */
static void uart_atm_irq_tx_disable(const struct device *dev)
{
	const struct uart_atm_config *const dev_cfg = dev->config;
	unsigned int key = irq_lock();

#ifdef CONFIG_PM
	struct uart_atm_dev_data *data = dev->data;
	if (dev_cfg->uart->TX_FIFO_SPACES != CMSDK_AT_UART_TX_FIFO_SPACES__RESET_VALUE) {
		/* Cannot release constraint now - hand off to poll stream logic */
		data->tx_poll_stream_on = true;
	} else {
		dev_cfg->uart->CTRL &= ~CMSDK_UART_CTRL_TXIRQEN_Msk;
		/* Clear any pending TX interrupt after disabling it */
		dev_cfg->uart->INTCLEAR = CMSDK_UART_INTSTATUS_TXIRQ_Msk;
		/* Schedule delayed release to ensure shift register
		 * has finished transmitting. */
		uart_atm_pm_tx_constraint_release_request(dev);
	}
	data->tx_int_stream_on = false;
#else
	dev_cfg->uart->CTRL &= ~CMSDK_UART_CTRL_TXIRQEN_Msk;
	/* Clear any pending TX interrupt after disabling it */
	dev_cfg->uart->INTCLEAR = CMSDK_UART_INTSTATUS_TXIRQ_Msk;
#endif

	irq_unlock(key);
}

/**
 * @brief Verify if Tx interrupt has been raised
 *
 * @param dev UART device struct
 *
 * @return 1 if an interrupt is ready, 0 otherwise
 */
static int uart_atm_irq_tx_ready(const struct device *dev)
{
	const struct uart_atm_config *const dev_cfg = dev->config;
	return (dev_cfg->uart->INTSTATUS & CMSDK_UART_INTSTATUS_TXIRQ_Msk) ||
	       !(dev_cfg->uart->STATE & CMSDK_UART_STATE_TXBF_Msk);
}

/**
 * @brief Enable RX interrupt
 *
 * @param dev UART device struct
 */
static void uart_atm_irq_rx_enable(const struct device *dev)
{
	const struct uart_atm_config *const dev_cfg = dev->config;
	if (!dev_cfg->has_rx_pin) {
		return;
	}

	unsigned int key = irq_lock();

	dev_cfg->uart->CTRL |= (CMSDK_UART_CTRL_RXIRQEN_Msk | CMSDK_UART_CTRL_RXEN_Msk);
	/* Data already sitting in the buffer won't trigger an interrupt.
	 * Call the ISR directly to notify about it.
	 */
	if ((dev_cfg->uart->STATE & CMSDK_UART_STATE_RXBF_Msk)) {
		uart_atm_isr(dev);
	}
	irq_unlock(key);
#ifdef CONFIG_PM
	uart_atm_pm_rx_start(dev);
#endif
}

/**
 * @brief Disable RX interrupt
 *
 * @param dev UART device struct
 */
static void uart_atm_irq_rx_disable(const struct device *dev)
{
	const struct uart_atm_config *const dev_cfg = dev->config;
	dev_cfg->uart->CTRL &= ~CMSDK_UART_CTRL_RXIRQEN_Msk;
	/* Clear any pending RX interrupt after disabling it */
	dev_cfg->uart->INTCLEAR = CMSDK_UART_INTSTATUS_RXIRQ_Msk;
#ifdef CONFIG_PM
	uart_atm_pm_rx_stop(dev);
#endif
}

/**
 * @brief Verify if UART TX block was fully transmitted and TX block is idle
 *
 * @param dev UART device struct
 *
 * @return 1 if TX block is idle, 0 otherwise
 */
static int uart_atm_irq_tx_complete(const struct device *dev)
{
	const struct uart_atm_config *const dev_cfg = dev->config;
#ifdef CMSDK_AT_UART_STATE__TX_IDLE__READ
	return CMSDK_AT_UART_STATE__TX_IDLE__READ(dev_cfg->uart->STATE);
#else
	return (dev_cfg->uart->TX_FIFO_SPACES == CMSDK_AT_UART_TX_FIFO_SPACES__RESET_VALUE);
#endif
}

/**
 * @brief Verify if Rx interrupt has been raised
 *
 * @param dev UART device struct
 *
 * @return 1 if an interrupt is ready, 0 otherwise
 */
static int uart_atm_irq_rx_ready(const struct device *dev)
{
	const struct uart_atm_config *const dev_cfg = dev->config;
	return (dev_cfg->uart->INTSTATUS & CMSDK_UART_INTSTATUS_RXIRQ_Msk) ||
	       (dev_cfg->uart->STATE & CMSDK_UART_STATE_RXBF_Msk);
}

/**
 * @brief Enable error interrupt
 *
 * @param dev UART device struct
 */
static void uart_atm_irq_err_enable(const struct device *dev)
{
	const struct uart_atm_config *const dev_cfg = dev->config;

	dev_cfg->uart->CTRL |= (CMSDK_UART_CTRL_TXORIRQEN_Msk | CMSDK_UART_CTRL_RXORIRQEN_Msk);
}

/**
 * @brief Disable error interrupt
 *
 * @param dev UART device struct
 */
static void uart_atm_irq_err_disable(const struct device *dev)
{
	const struct uart_atm_config *const dev_cfg = dev->config;

	dev_cfg->uart->CTRL &= ~(CMSDK_UART_CTRL_TXORIRQEN_Msk | CMSDK_UART_CTRL_RXORIRQEN_Msk);
}

/**
 * @brief Verify if Tx or Rx interrupt is pending
 *
 * @param dev UART device struct
 *
 * @return 1 if Tx or Rx interrupt is pending, 0 otherwise
 */
static int uart_atm_irq_is_pending(const struct device *dev)
{
	const struct uart_atm_config *const dev_cfg = dev->config;
	/*
	 * Check CMSDK_UART_STATE_RXBF_Msk in case of race condition where interrupt cleared
	 * but FIFO not empty. When RX_LWM is 1 (default) the RX_IN interrupt
	 * is only asserted when FIFO was previously empty and a new byte is
	 * received
	 *
	 * Don't have level trigger for UART TX so emulate a TX_FIFO_EMPTY
	 * interrupt by checking FIFO spaces when UART TX INT is enabled
	 */
	return (dev_cfg->uart->INTSTATUS &
		(CMSDK_UART_INTSTATUS_RXIRQ_Msk | CMSDK_UART_INTSTATUS_TXIRQ_Msk)) ||
	       (dev_cfg->uart->STATE & CMSDK_UART_STATE_RXBF_Msk) ||
	       ((dev_cfg->uart->CTRL & CMSDK_UART_CTRL_TXIRQEN_Msk) &&
		(dev_cfg->uart->TX_FIFO_SPACES >= dev_cfg->uart->TX_LWM));
}

/**
 * @brief Update the interrupt status
 *
 * @param dev UART device struct
 *
 * @return always 1
 */
static int uart_atm_irq_update(const struct device *dev)
{
	return 1;
}

/**
 * @brief Set the callback function pointer for an Interrupt.
 *
 * @param dev UART device structure
 * @param cb Callback function pointer.
 */
static void uart_atm_irq_callback_set(const struct device *dev, uart_irq_callback_user_data_t cb,
				      void *cb_data)
{
	struct uart_atm_dev_data *data = dev->data;

	data->irq_cb = cb;
	data->irq_cb_data = cb_data;
}
#endif /* CONFIG_UART_INTERRUPT_DRIVEN */

static const struct uart_driver_api uart_atm_driver_api = {
	.poll_in = uart_atm_poll_in,
	.poll_out = uart_atm_poll_out,
	.err_check = uart_atm_err_check,
#ifdef CONFIG_UART_USE_RUNTIME_CONFIGURE
	.configure = uart_atm_configure,
	.config_get = uart_atm_config_get,
#endif
#ifdef CONFIG_UART_INTERRUPT_DRIVEN
	.fifo_fill = uart_atm_fifo_fill,
	.fifo_read = uart_atm_fifo_read,
	.irq_tx_enable = uart_atm_irq_tx_enable,
	.irq_tx_disable = uart_atm_irq_tx_disable,
	.irq_tx_ready = uart_atm_irq_tx_ready,
	.irq_rx_enable = uart_atm_irq_rx_enable,
	.irq_rx_disable = uart_atm_irq_rx_disable,
	.irq_tx_complete = uart_atm_irq_tx_complete,
	.irq_rx_ready = uart_atm_irq_rx_ready,
	.irq_err_enable = uart_atm_irq_err_enable,
	.irq_err_disable = uart_atm_irq_err_disable,
	.irq_is_pending = uart_atm_irq_is_pending,
	.irq_update = uart_atm_irq_update,
	.irq_callback_set = uart_atm_irq_callback_set,
#endif /* CONFIG_UART_INTERRUPT_DRIVEN */
};

#define ATMOSIC_UART_PM_NOTIFIER_DECL(inst)                                                        \
	IF_ENABLED(CONFIG_PM, (                                                                    \
IF_ENABLED(UART_PM_ENTRY(inst), (                                                                  \
__FAST static void notify_pm_state_entry##inst(enum pm_state state)                                \
{                                                                                                  \
	if (state != PM_STATE_SUSPEND_TO_RAM) {                                                    \
		return;                                                                            \
	}                                                                                          \
	IF_ENABLED(RTS_GPIO_REQUIRED(inst), (PIN_SELECT_GPIO(DT_INST_PROP(inst, rts_pin));))       \
	IF_ENABLED(CONFIG_UART_ATM_TX_GLITCH, (PIN_SELECT_GPIO(DT_INST_PROP(inst, tx_pin));))      \
}                                                                                                  \
)) /* UART_PM_ENTRY */                                                                             \
                                                                                                   \
IF_ENABLED(UART_PM_NOTIFIER(inst), (                                                               \
__FAST static void notify_pm_state_exit##inst(enum pm_state state)                                 \
{                                                                                                  \
	if (state != PM_STATE_SUSPEND_TO_RAM) {                                                    \
		return;                                                                            \
	}                                                                                          \
	IF_ENABLED(CONFIG_UART_ATM_TX_GLITCH, (                                                    \
		PIN_SELECT(DT_INST_PROP(inst, tx_pin), UART_SIG(inst, TX));                        \
	)) /* CONFIG_UART_ATM_TX_GLITCH */                                                         \
	IF_ENABLED(RTS_GPIO_REQUIRED(inst), (                                                      \
		PIN_SELECT(DT_INST_PROP(inst, rts_pin), UART_SIG(inst, RTS));                      \
	)) /* RTS_GPIO_REQUIRED */                                                                 \
	IF_ENABLED(DT_INST_NODE_HAS_PROP(inst, rts_pin), (                                         \
		struct uart_atm_dev_data *const dev_data = DEVICE_DT_INST_GET(inst)->data;         \
		if (dev_data->pm_rx_sleeping) {                                                    \
			uart_atm_pm_rx_post(DEVICE_DT_INST_GET(inst), EVT_WAKE);                   \
		}                                                                                  \
	)) /* rts_pin */                                                                           \
}                                                                                                  \
                                                                                                   \
static struct pm_notifier uart_atm_pm_notifier##inst = {                                           \
	IF_ENABLED(UART_PM_ENTRY(inst), (                                                          \
		.state_entry = notify_pm_state_entry##inst,                                        \
	)) /* UART_PM_ENTRY */                                                                     \
	.state_exit = notify_pm_state_exit##inst,                                                  \
};                                                                                                 \
)) /* UART_PM_NOTIFIER */                                                                          \
                                                                                                   \
IF_ENABLED(DT_INST_NODE_HAS_PROP(inst, rts_pin), (                                                 \
static K_KERNEL_STACK_DEFINE(uart_atm_pm_rx_thread_stack##inst,                                    \
			     CONFIG_UART_ATM_PM_RX_THREAD_STACK_SIZE);                             \
static struct k_thread uart_atm_pm_rx_thread##inst;                                                \
static struct k_sem uart_atm_pm_rx_sem##inst;                                                      \
static struct k_timer uart_atm_pm_rx_timer##inst;                                                  \
)) /* rts_pin */                                                                                   \
)) /* CONFIG_PM */

#ifdef CONFIG_UART_INTERRUPT_DRIVEN
#define ATMOSIC_UART_IRQ_HANDLER_DECL(inst)                                                        \
	static void uart_atm_irq_config_func_##inst(const struct device *dev);
#define ATMOSIC_UART_IRQ_HANDLER(inst)                                                             \
	static void uart_atm_irq_config_func_##inst(const struct device *dev)                      \
	{                                                                                          \
		IRQ_CONNECT(DT_INST_IRQ_BY_NAME(inst, tx, irq),                                    \
			    DT_INST_IRQ_BY_NAME(inst, tx, priority), uart_atm_isr,                 \
			    DEVICE_DT_INST_GET(inst), 0);                                          \
		irq_enable(DT_INST_IRQ_BY_NAME(inst, tx, irq));                                    \
                                                                                                   \
		IF_ENABLED(DT_INST_IRQ_HAS_NAME(inst, rx), (                                       \
		IRQ_CONNECT(DT_INST_IRQ_BY_NAME(inst, rx, irq),                                    \
			    DT_INST_IRQ_BY_NAME(inst, rx, priority), uart_atm_isr,                 \
			    DEVICE_DT_INST_GET(inst), 0);                                          \
		irq_enable(DT_INST_IRQ_BY_NAME(inst, rx, irq));                                    \
		))                                                                                 \
                                                                                                   \
		IF_ENABLED(DT_INST_IRQ_HAS_NAME(inst, ovf), (                                      \
		IRQ_CONNECT(DT_INST_IRQ_BY_NAME(inst, ovf, irq),                                   \
			    DT_INST_IRQ_BY_NAME(inst, ovf, priority), uart_atm_isr,                \
			    DEVICE_DT_INST_GET(inst), 0);                                          \
		irq_enable(DT_INST_IRQ_BY_NAME(inst, ovf, irq));                                   \
		))                                                                                 \
	}
#define ATMOSIC_UART_IRQ_HANDLER_FUNC(inst) .irq_config_func = uart_atm_irq_config_func_##inst,
#else
#define ATMOSIC_UART_IRQ_HANDLER_DECL(inst) /* Not used */
#define ATMOSIC_UART_IRQ_HANDLER(inst)      /* Not used */
#define ATMOSIC_UART_IRQ_HANDLER_FUNC(inst) /* Not used */
#endif

#define UART_SIG(n, sig) CONCAT(CONCAT(UART, DT_INST_PROP(n, instance)), _##sig)

#ifdef WRPR_CTRL__CLK_SEL
#define CLK_ENABLE (WRPR_CTRL__CLK_SEL | WRPR_CTRL__CLK_ENABLE)
#else
#define CLK_ENABLE WRPR_CTRL__CLK_ENABLE
#endif

/* Helper macro to get GPIO device from rx_pin at compile time */
#ifdef CONFIG_UART_ATM_HOST_DETECT
#define GPIO_GET_IF_OKAY(node_id)                                                                  \
	COND_CODE_1(DT_NODE_HAS_STATUS(node_id, okay), (DEVICE_DT_GET(node_id)), (NULL))

#define UART_ATM_GPIO_PORT(pin) ((pin) / 16)

#define UART_ATM_GPIO_DEV_FROM_PIN(pin)                                                            \
	((UART_ATM_GPIO_PORT(pin) == 0)   ? GPIO_GET_IF_OKAY(DT_NODELABEL(gpio0))                  \
	 : (UART_ATM_GPIO_PORT(pin) == 1) ? GPIO_GET_IF_OKAY(DT_NODELABEL(gpio1))                  \
	 : (UART_ATM_GPIO_PORT(pin) == 2) ? GPIO_GET_IF_OKAY(DT_NODELABEL(gpio2))                  \
					  : GPIO_GET_IF_OKAY(DT_NODELABEL(gpio3)))

#endif

#if CONFIG_UART_ATM_DELAY_INIT
#if DT_HAS_CHOSEN(zephyr_console)
// Always init console UART at PRE_KERNEL_1, even when other UARTs have delayed init
#define UART_ATM_INIT_LEVEL(inst)                                                                  \
	COND_CODE_1(DT_SAME_NODE(DT_DRV_INST(inst), DT_CHOSEN(zephyr_console)),                    \
		    (PRE_KERNEL_1), (POST_KERNEL))
#else
#define UART_ATM_INIT_LEVEL(inst) POST_KERNEL
#endif
#else
#define UART_ATM_INIT_LEVEL(inst) PRE_KERNEL_1
#endif

#define ATMOSIC_UART_INIT(inst)                                                                    \
	ATMOSIC_UART_PM_NOTIFIER_DECL(inst)                                                        \
	ATMOSIC_UART_IRQ_HANDLER_DECL(inst)                                                        \
                                                                                                   \
	static void uart_atm_config_pins##inst(void)                                               \
	{                                                                                          \
		WRPR_CTRL_SET((void *)DT_INST_REG_ADDR(inst), WRPR_CTRL__SRESET);                  \
		WRPR_CTRL_SET((void *)DT_INST_REG_ADDR(inst), CLK_ENABLE);                         \
		IF_ENABLED(CONFIG_PM, (                                                            \
		IF_ENABLED(CONFIG_UART_ATM_TX_GLITCH, (                                            \
			PIN_SELECT_GPIO_HIGH(DT_INST_PROP(inst, tx_pin));                          \
		)) /* CONFIG_UART_ATM_TX_GLITCH */                                                 \
		IF_ENABLED(RTS_GPIO_REQUIRED(inst), (                                              \
			PIN_SELECT_GPIO_HIGH(DT_INST_PROP(inst, rts_pin));                         \
		)) /* RTS_GPIO_REQUIRED */                                                         \
		IF_ENABLED(UART_PM_NOTIFIER(inst), (                                               \
			pm_notifier_register(&uart_atm_pm_notifier##inst);                         \
		)) /* UART_PM_NOTIFIER */                                                          \
	)) /* CONFIG_PM */                                                                         \
		IF_ENABLED(DT_INST_NODE_HAS_PROP(inst, rx_pin), (                                  \
		PIN_SELECT(DT_INST_PROP(inst, rx_pin), UART_SIG(inst, RX));                        \
		PIN_PULLUP(DT_INST_PROP(inst, rx_pin));                                            \
	)) /* rx_pin */                                                                            \
		PIN_SELECT(DT_INST_PROP(inst, tx_pin), UART_SIG(inst, TX));                        \
		IF_ENABLED(DT_INST_NODE_HAS_PROP(inst, rts_pin), (                                 \
		PIN_SELECT(DT_INST_PROP(inst, rts_pin), UART_SIG(inst, RTS));                      \
	)) /* rts_pin */                                                                           \
		IF_ENABLED(DT_INST_NODE_HAS_PROP(inst, cts_pin), (                                 \
		PIN_SELECT(DT_INST_PROP(inst, cts_pin), UART_SIG(inst, CTS));                      \
	)) /* cts_pin */                                                                           \
	}                                                                                          \
                                                                                                   \
	static const struct uart_atm_config uart_atm_dev_cfg_##inst = {                            \
		.uart = (volatile CMSDK_AT_APB_UART_TypeDef *)DT_INST_REG_ADDR(inst),              \
		.sys_clk_freq = DT_INST_PROP_BY_PHANDLE(inst, clocks, clock_frequency),            \
		ATMOSIC_UART_IRQ_HANDLER_FUNC(inst).has_cts_pin =                                  \
			DT_INST_NODE_HAS_PROP(inst, cts_pin),                                      \
		.has_rts_pin = DT_INST_NODE_HAS_PROP(inst, rts_pin),                               \
		.has_rx_pin = DT_INST_NODE_HAS_PROP(inst, rx_pin),                                 \
		IF_ENABLED(CONFIG_UART_ATM_HOST_DETECT, (                                          \
			IF_ENABLED(DT_INST_NODE_HAS_PROP(inst, rx_pin), (                          \
				.rx_pin = DT_INST_PROP(inst, rx_pin),                              \
				.gpio_dev = UART_ATM_GPIO_DEV_FROM_PIN(DT_INST_PROP(inst, rx_pin)),\
			))                                                                         \
		)) };                                                                              \
                                                                                                   \
	static struct uart_atm_dev_data uart_atm_dev_data_##inst = {                               \
		.baudrate = DT_INST_PROP(inst, current_speed),                                     \
		.hw_flow_control = DT_INST_PROP(inst, hw_flow_control),                            \
		.config_pins = uart_atm_config_pins##inst,                                         \
		IF_ENABLED(CONFIG_PM, (                                                            \
		IF_ENABLED(DT_INST_NODE_HAS_PROP(inst, rts_pin), (                                 \
			.pm_rx_thread = &uart_atm_pm_rx_thread##inst,                              \
			.pm_rx_sem = &uart_atm_pm_rx_sem##inst,                                    \
			.pm_rx_timer = &uart_atm_pm_rx_timer##inst,                                \
			.pm_rx_thread_stack = uart_atm_pm_rx_thread_stack##inst,                   \
			.pm_rx_thread_stack_sizeof =                                               \
				K_KERNEL_STACK_SIZEOF(uart_atm_pm_rx_thread_stack##inst),          \
		)) /* rts_pin */                                                                   \
	)) /* CONFIG_PM */                                                                         \
	};                                                                                         \
                                                                                                   \
	DEVICE_DT_INST_DEFINE(inst, &uart_atm_init, NULL, &uart_atm_dev_data_##inst,               \
			      &uart_atm_dev_cfg_##inst, UART_ATM_INIT_LEVEL(inst),                 \
			      CONFIG_SERIAL_INIT_PRIORITY, &uart_atm_driver_api);                  \
                                                                                                   \
	ATMOSIC_UART_IRQ_HANDLER(inst)

DT_INST_FOREACH_STATUS_OKAY(ATMOSIC_UART_INIT)

#ifdef CONFIG_UART_ATM_HOST_DETECT

/*
 * Per-instance helper functions for switching RX pin to UART/GPIO mode.
 * These must be defined AFTER UART_SIG macro and AFTER device instances.
 */
#define UART_ATM_RX_IDLE_HELPERS(inst)                                                             \
	IF_ENABLED(DT_INST_NODE_HAS_PROP(inst, rx_pin), (			\
	static void uart_atm_rx_select_uart##inst(void)				\
	{									\
		PIN_SELECT(DT_INST_PROP(inst, rx_pin), UART_SIG(inst, RX));	\
		PIN_PULLUP(DT_INST_PROP(inst, rx_pin));				\
	}									\
	static void uart_atm_rx_select_gpio##inst(void)				\
	{									\
		PIN_SELECT(DT_INST_PROP(inst, rx_pin), GPIO);			\
		PIN_PULLDOWN(DT_INST_PROP(inst, rx_pin));			\
	}									\
	))

DT_INST_FOREACH_STATUS_OKAY(UART_ATM_RX_IDLE_HELPERS)

/* Function pointer types for the per-instance helpers */
typedef void (*uart_atm_rx_pin_func_t)(void);

/* Get the per-instance function to switch RX to UART mode */
static uart_atm_rx_pin_func_t uart_atm_get_rx_uart_func(const struct device *dev)
{
#define UART_ATM_GET_RX_UART_FUNC(inst)                                                            \
	IF_ENABLED(DT_INST_NODE_HAS_PROP(inst, rx_pin), (			\
	if (dev == DEVICE_DT_INST_GET(inst)) { return uart_atm_rx_select_uart##inst;                            \
	}									\
	))

	DT_INST_FOREACH_STATUS_OKAY(UART_ATM_GET_RX_UART_FUNC)
	return NULL;
}

/* Get the per-instance function to switch RX to GPIO mode */
static uart_atm_rx_pin_func_t uart_atm_get_rx_gpio_func(const struct device *dev)
{
#define UART_ATM_GET_RX_GPIO_FUNC(inst)                                                            \
	IF_ENABLED(DT_INST_NODE_HAS_PROP(inst, rx_pin), (			\
	if (dev == DEVICE_DT_INST_GET(inst)) { return uart_atm_rx_select_gpio##inst;                            \
	}									\
	))

	DT_INST_FOREACH_STATUS_OKAY(UART_ATM_GET_RX_GPIO_FUNC)
	return NULL;
}

/**
 * @brief GPIO callback handler for RX idle detection
 *
 * Called when the RX line transitions from low to high (rising edge).
 * Switches the RX pin back to UART function and invokes user callback.
 */
static void uart_atm_rx_idle_gpio_callback(const struct device *gpio_dev, struct gpio_callback *cb,
					   uint32_t pins)
{
	struct uart_atm_dev_data *data = CONTAINER_OF(cb, struct uart_atm_dev_data, rx_gpio_cb);
	const struct device *dev = NULL;
	uart_atm_rx_callback_t callback = data->rx_idle_callback;

	/* Find the UART device from the data pointer */
#define UART_ATM_FIND_DEV_FROM_DATA(inst)                                                          \
	if (data == &uart_atm_dev_data_##inst) {                                                   \
		dev = DEVICE_DT_INST_GET(inst);                                                    \
	}

	DT_INST_FOREACH_STATUS_OKAY(UART_ATM_FIND_DEV_FROM_DATA)

	if (dev == NULL) {
		LOG_ERR("Could not find UART device from callback data");
		return;
	}

	const struct uart_atm_config *const dev_cfg = dev->config;
	uint8_t gpio_pin = dev_cfg->rx_pin % 16;

	/* Disable GPIO interrupt and remove callback */
	gpio_pin_interrupt_configure(gpio_dev, gpio_pin, GPIO_INT_DISABLE);
	gpio_remove_callback(gpio_dev, &data->rx_gpio_cb);

	/* Switch RX pin back to UART function */
	uart_atm_rx_pin_func_t rx_uart_func = uart_atm_get_rx_uart_func(dev);
	if (rx_uart_func != NULL) {
		rx_uart_func();
	}

	/* Clear state */
	data->rx_idle_callback = NULL;

	LOG_INF("Host connected on %s - switched to UART mode", dev->name);

	/* Invoke user callback to notify host connection */
	if (callback) {
		callback(dev);
	}
}

int uart_atm_set_idle(const struct device *dev, uart_atm_rx_callback_t callback)
{
	if (dev == NULL || callback == NULL) {
		return -EINVAL;
	}

	const struct uart_atm_config *const dev_cfg = dev->config;

	if (!dev_cfg->has_rx_pin) {
		return -ENOTSUP;
	}

	const struct device *gpio_dev = dev_cfg->gpio_dev;

	if (!device_is_ready(gpio_dev)) {
		LOG_ERR("GPIO device not ready");
		return -ENODEV;
	}

	struct uart_atm_dev_data *const dev_data = dev->data;

	dev_data->rx_idle_callback = callback;

	uint8_t gpio_pin = dev_cfg->rx_pin % 16;

	/* Configure GPIO pin as input (required for Zephyr GPIO interrupt to work) */
	int ret = gpio_pin_configure(gpio_dev, gpio_pin, GPIO_INPUT);

	if (ret < 0) {
		LOG_ERR("Failed to configure GPIO pin as input: %d", ret);
		return ret;
	}

	/* Switch RX pin mux to GPIO with pull-down using Atmosic HAL */
	uart_atm_get_rx_gpio_func(dev)();

	/* Initialize and add callback */
	gpio_init_callback(&dev_data->rx_gpio_cb, uart_atm_rx_idle_gpio_callback, BIT(gpio_pin));
	ret = gpio_add_callback(gpio_dev, &dev_data->rx_gpio_cb);
	if (ret < 0) {
		LOG_ERR("Failed to add GPIO callback: %d", ret);
		return ret;
	}

	/* Configure rising edge interrupt (low -> high = host connects) */
	ret = gpio_pin_interrupt_configure(gpio_dev, gpio_pin, GPIO_INT_EDGE_RISING);
	if (ret < 0) {
		LOG_ERR("Failed to configure GPIO interrupt: %d", ret);
		gpio_remove_callback(gpio_dev, &dev_data->rx_gpio_cb);
		return ret;
	}

	return 0;
}

#endif /* CONFIG_UART_ATM_HOST_DETECT */
