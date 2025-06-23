/**
 *******************************************************************************
 *
 * @file radio_hal_mgr.h
 *
 * @brief Radio Manager
 *
 * The Radio Manager takes radio requests from radio protocols, and gives the
 * protocols access to the radio for those requests. Requests will be
 * prioritized according to the information in the request, as well as other
 * running and requested operations. When possible, the manager will be given
 * information relevant to priority declaratively in each request.
 *
 * Copyright (C) Atmosic 2023-2025
 *
 *******************************************************************************
 */

#pragma once

/**
 * @defgroup RADIO_HAL_MGR RADIO_HAL_MGR
 * @ingroup DRIVERS
 * @brief Radio Manager
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef CONFIG_BOARD_UNIT_TESTING
#define __NONNULL(...)
#else
#include "arch.h"
#endif

#include <stdint.h>
#include "radio_status.h"

/// The Radio Manager uses a hardware timer
#define MGR_FRC_TIMER ATM_MAC_FRC_TIMER1

typedef enum {
    ATM_MAC_MGR_STATE_IDLE = 0,
    ATM_MAC_MGR_STATE_BUSY,
} atm_mac_mgr_state_t;

/**
 * @brief Radio Manager Protocol
 */
typedef enum {
    ATM_MAC_MGR_PROT_NONE = 0, /*!< No protocol */
    ATM_MAC_MGR_PROT_BLE = 1, /*!< BLE */
    ATM_MAC_MGR_PROT_154 = 2, /*!< 15.4 */
    ATM_MAC_MGR_PROT_TRNG = 3, /*!< True random numbers */
    ATM_MAC_MGR_PROT_CAL = 4, /*!< LNA-TIA DCCAL */
    ATM_MAC_MGR_PROT_NUM,
} atm_mac_mgr_protocol_t;

/**
 * @brief Radio Manager protocol interface
 */
typedef struct {
    /**
     * @brief Start protocol operation
     *
     * Trigger the protocol to start using the radio. The protocol must store
     * all information needed to start a given operatiom when the operation is
     * initially scheduled.
     */
    void (*protocol_start)(void);
    /**
     * @brief Enable protocol operation
     *
     * Trigger the protocol to prepare to start using the radio. This will
     * always be the first API call to a given protocol, and will be re-called
     * whenever the protocol is again ready to take over control of the radio.
     */
    void (*protocol_enable)(void);
    /**
     * @brief Stop protocol operation
     *
     * Trigger the protocol to stop using the radio. This should not result
     * in any callbacks being transmitted to upper layers. If possible, an
     * operation may be stopped and restarted multiple times when trying to
     * fit into a schedule.
     */
    void (*protocol_stop)(void);
    /**
     * @brief End protocol operation
     *
     * The radio manager will call this either in the case that the radio
     * operation was not able to run within its parameters or when the radio
     * operation needs to be aborted for another higher priority operation.
     * This will be called from within the atm_mac_mgr_schedule context.
     *
     * When processing this call, the protocol must not access the radio, but
     * should notify higher layers of the failure.
     *
     * @return An error status indicating why the operation was aborted
     */
    void (*protocol_abort)(atm_mac_status_t status);
} atm_mac_mgr_interface_api_t;

/**
 * priority bits
 * 29-31 - Protocol. Used to denote which protocol the operation uses
 * 28    - Critical. This bit notes that the current operation is part
 *         of a higher level construct which should not be disturbed if at all
 *         possible. Generally time-sensitive and security-critical.
 * 24-27 - Retries available. For a fallible event, how many more times can it
 *         be tried before a protocol-level failure?
 * 9-28  - unused
 * 0-7   - Subpriority. Used to allow operations to be distinguished outside of
 *         the manager. The goal is to not need this to be used frequently
 */
typedef uint32_t atm_mac_mgr_priority_t;
#define PRIORITY_PROTOCOL_READ(priority) (((priority) >> 29) & 0b111U)
#define PRIORITY_PROTOCOL_MODIFY(priority, val) \
    (priority) = ((priority) & ~(0b111U << 29)) | (((val) & 0b111U) << 29)
#define PRIORITY_SUBPRIORITY_READ(priority) ((priority) & 0xFFU)
#define PRIORITY_SUBPRIORITY_MODIFY(priority, val) \
    (priority) = ((priority) & ~(0xFFU)) | ((val) & 0xFFU)

/**
 * @brief Signature of the function to arbitrate priority decisions
 *
 * The scheduling loop will call a function of this type to decide which
 * operation should take priority, when two operations cannot be scheduled
 * around each other.
 *
 * @param[in] first The priority of the first operation
 * @param[in] second The priority of the second operation
 * @return Any positive number if first should take priority, 0 if either can
 *   take priority, and any negative number if second should take priority
 */
typedef int32_t (*atm_mac_mgr_priority_handler_t)(atm_mac_mgr_priority_t first,
    atm_mac_mgr_priority_t second);

/**
 * @brief Radio Manager operation data
 */
typedef struct {
    /** The earliest time that this operation may start */
    uint32_t start_time;
    /** The latest time that this operation may start. Providing more time
     * between start_time and latest_start_time will prevent an
     * operation from failing to be scheduled. */
    uint32_t latest_start_time;
    /** The expected amount of time that this operation will take. The Radio
     * Manager will operate more effectively when this time is closest to the
     * actual operation time. */
    uint32_t expected_duration;
    /** The priority with which to schedule this operation */
    atm_mac_mgr_priority_t priority;
    /** The protocol slot to place this operation into */
    atm_mac_mgr_protocol_t protocol;
} atm_mac_mgr_op_data_t;

struct atm_mac_mgr_interface_data_t;
typedef struct atm_mac_mgr_interface_data_t *atm_mac_mgr_interface_t;

/**
 * @brief Get manager interface
 *
 * @return Manager interface to use when calling manager functions
 */
__attribute__((weak)) atm_mac_mgr_interface_t atm_mac_mgr_get_iface(void);

/**
 * @brief Get current manager state
 * @return atm_mac_mgr_state_t manager state
 */
atm_mac_mgr_state_t atm_mac_mgr_get_state(void);

/**
 * @brief Register interface API
 * @param[in] interface Manager interface
 * @param[in] protocol Protocol to register API to
 * @param[in] api API callbacks to use for protocol operation
 */
__attribute__((weak)) void atm_mac_mgr_register_api(
    atm_mac_mgr_interface_t interface, atm_mac_mgr_protocol_t protocol,
    atm_mac_mgr_interface_api_t api);

/**
 * @brief Register function for priority decisions
 */
__NONNULL(2)
void atm_mac_mgr_register_priority_handler(atm_mac_mgr_interface_t interface,
    atm_mac_mgr_priority_handler_t handler);

/**
 * @brief Schedule operation
 * @param[in] interface Manager interface
 * @param[in] op_data Pointer to operation data
 * @return ATM_MAC_MGR_STATUS_SUCCESS if operation was scheduled.
 * ATM_MAC_MGR_STATUS_ERROR if operation was not scheduled.
 *
 * This function will implicitly complete any operation running on
 * op_data->protocol. This function will have the side effect of running
 * @ref atm_mac_mgr_schedule internally, to allow the scheduled operation
 * to run immediately if possible.
 */
__attribute__((weak)) atm_mac_status_t atm_mac_mgr_schedule_op(
    atm_mac_mgr_interface_t interface, atm_mac_mgr_op_data_t const *op_data);

/**
 * @brief Complete scheduled operation
 * @param[in] interface Manager interface
 * @param[in] protocol Protocol on which the operation completed
 * @return ATM_MAC_MGR_STATUS_ERROR if protocol was not running anything.
 * ATM_MAC_MGR_STATUS_SUCCESS otherwise.
 *
 * This function will have the side effect of running @ref atm_mac_mgr_schedule
 * internally, to allow the next scheduled operation to run immediately if
 * possible.
 */
__attribute__((weak)) atm_mac_status_t atm_mac_mgr_complete_op(
    atm_mac_mgr_interface_t interface, atm_mac_mgr_protocol_t protocol);

/**
 * @brief Update scheduled operation
 *
 * @note This function may be called from interrupt context.
 *
 * This function may be called with no changes to the schedule, and will
 * correctly determine that no change to the schedule is needed. This function
 * should be called after an operation is marked complete and on a periodic
 * basis.
 *
 * All changes to the schedule are made in scheduling context, to manage
 * reentrancy concerns. This context will block some interrupts from
 * occurring.
 */
void atm_mac_mgr_schedule(void);

/**
 * @brief Initialize radio manager
 */
void atm_mac_mgr_init(void);

/**
 * @brief Handle radio manager interrupt
 */
void atm_mac_mgr_handler(void);

/**
 * @brief Register manager switch for debugging purposes
 *
 * @param[in] from Protocol that is being switched away from
 * @param[in] to Protocol that is being switched towards
 * @param[in] time Time of protocol switch
 */
void atm_mac_mgr_debug_switch(atm_mac_mgr_protocol_t from,
    atm_mac_mgr_protocol_t to, uint32_t time);

/**
 * @brief Dump radio manager debugging information
 */
void atm_mac_mgr_dump_debug(void);

#ifdef __cplusplus
}
#endif

/// @}
