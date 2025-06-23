//-----------------------------------------------------------------------------
// The confidential and proprietary information contained in this file may
// only be used by a person authorised under and to the extent permitted
// by a subsisting licensing agreement from ARM Limited or its affiliates.
//
//        (C) COPYRIGHT 2016, 2017 ARM Limited or its affiliates.
//            ALL RIGHTS RESERVED
//
// This entire notice must be reproduced on all copies of this file
// and copies of this file may only be made by a person if such person is
// permitted to do so under the terms of a subsisting license agreement
// from ARM Limited or its affiliates.
//
//      SVN Information
//
//      Checked In          : 2017-08-01 08:46:51 +0100 (Tue, 01 Aug 2017) 
//
//      Revision            : 12739 
//
//      Release Information : r2p0-00rel0
//
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
// Abstract : ARMv8MBL DeviceMSIS Cortex-M Core Function/Instruction Header File
//-----------------------------------------------------------------------------
/**************************************************************************//**
 * @file     system.h
 * @brief    CMSIS Device System Header File for
 *           ARMv8MBL Device
 * @version  V4.00
 * @date     02. November 2015
 ******************************************************************************/

#ifndef SYSTEM_H
#define SYSTEM_H

#ifdef __cplusplus
extern "C" {
#endif

extern uint32_t SystemCoreClock;      /* System Clock Frequency (Core Clock) */


/** @brief Setup the microcontroller system.

    Initialize the System and update the SystemCoreClock variable.
 */
extern void SystemInit (void);


/** \brief  Update SystemCoreClock variable.

    Updates the SystemCoreClock with current core Clock
    retrieved from cpu registers.
 */
extern void SystemCoreClockUpdate (void);

#ifdef __cplusplus
}
#endif

#endif /* SYSTEM_H */
