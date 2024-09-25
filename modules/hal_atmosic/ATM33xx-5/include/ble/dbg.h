/**
****************************************************************************************
*
* @file dbg.h
*
* @brief Debug function
*
* Copyright (C) RivieraWaves 2009-2024
* Release Identifier: dc6acdca
*
*
****************************************************************************************
*/
#ifndef DBG_H_
#define DBG_H_

/**
****************************************************************************************
* @addtogroup DBG
* @ingroup CONTROLLER
* @brief Debug
*
* @{
****************************************************************************************
*/


/*
 * INCLUDE FILES
 ****************************************************************************************
 */

#include "rwip_config.h"     // stack configuration

#include "dbg_swdiag.h"        // sw profiling definitions

#include "dbg_trc.h"           // debug tracer definition

/*
 * FUNCTION DECLARATION
 ****************************************************************************************
 */

#if (RW_DEBUG)
/**
 ****************************************************************************************
 * @brief Initialization of the BT Debug task
 *
 * This function initializes the the DBG task
 *
 * @param[in] is_reset  True if reset is requested, false for an initialization
 ****************************************************************************************
 */
void dbg_init(bool is_reset);
#endif // (RW_DEBUG)

/**
 ****************************************************************************************
 * @brief Send back to host status of platform reset request.
 *
 * @param status Reset error code
 *
 ****************************************************************************************
 */
void dbg_platform_reset_complete(uint32_t error_code);

///@} DBG

#endif // DBG_H_
