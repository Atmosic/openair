/**
 ****************************************************************************************
 *
 * @file h4tl.h
 *
 * @brief (H4) UART Transport Layer header file.
 *
 * @note H4 transport layer was old name for UART transport layer
 *
 * Copyright (C) RivieraWaves 2009-2024
 * Release Identifier: dc6acdca
 *
 ****************************************************************************************
 */

#ifndef H4TL_H_
#define H4TL_H_

/*
 * INCLUDE FILES
 ****************************************************************************************
 */

#include "rwip_config.h"  // stack configuration

#if (H4TL_SUPPORT)
#include "rwtl.h"         // RW Transport layer interface

/*
 * FUNCTION DECLARATIONS
 ****************************************************************************************
 */

/**
 ****************************************************************************************
 * @brief Initialize H4 Transport layer used to communicate with an upper layer (application or external host)
 *
 * @param[in] p_eif  Pointer to external interface
 *****************************************************************************************
 */
void h4tl_init(const struct rwip_eif_api* p_eif);

/**
 ****************************************************************************************
 * @brief Restore prevent sleep status cleared during IP reset.
 *****************************************************************************************
 */
void h4tl_reset(void);

#if (!EMB_PRESENT && HCI_TL_SUPPORT)
/**
 ****************************************************************************************
 * @brief Initialize H4 Transport layer used by host to communicate with an external controller
 *
 * @param[in] p_eif  Pointer to external interface
 *****************************************************************************************
 */
void h4tl_host_to_ctrl_init(const struct rwip_eif_api* p_eif);

/**
 ****************************************************************************************
 * @brief Retrieve host to controller interface
 *
 * @return Pointer to H4TL interface
 *****************************************************************************************
 */
rwtl_itf_t* h4tl_host_to_ctrl_itf_get(void);
#endif // (!EMB_PRESENT && HCI_TL_SUPPORT)

/**
 ****************************************************************************************
 * @brief Retrieve transport layer interface
 *
 * @return Pointer to H4TL interface
 *****************************************************************************************
 */
rwtl_itf_t* h4tl_itf_get(void);

/**
 ****************************************************************************************
 * @brief Start H4 transport layer input flow
 *
 *****************************************************************************************
 */
void h4tl_start(void);

/**
 ****************************************************************************************
 * @brief Stop H4 transport layer input flow if possible
 *
 * @return true if flow was stopped, false otherwise
 *****************************************************************************************
 */
bool h4tl_stop(void);

#endif // (H4TL_SUPPORT)
#endif // H4TL_H_
