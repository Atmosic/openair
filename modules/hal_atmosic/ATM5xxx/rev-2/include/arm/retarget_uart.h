//-----------------------------------------------------------------------------
// The confidential and proprietary information contained in this file may
// only be used by a person authorised under and to the extent permitted
// by a subsisting licensing agreement from ARM Limited or its affiliates.
//
//        (C) COPYRIGHT 2016-2017 ARM Limited or its affiliates.
//            ALL RIGHTS RESERVED
//
// This entire notice must be reproduced on all copies of this file
// and copies of this file may only be made by a person if such person is
// permitted to do so under the terms of a subsisting license agreement
// from ARM Limited or its affiliates.
//
//      SVN Information
//
//      Checked In          : 2017-08-03 09:02:28 +0100 (Thu, 03 Aug 2017) 
//
//      Revision            : 12829 
//
//      Release Information : r2p0-00rel0
//
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
// Abstract : retarget_uart
//-----------------------------------------------------------------------------
 
#ifndef __RETARGET_UART_H__ 
#define __RETARGET_UART_H__

#include "ARMv8MBL.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdint.h>

#ifdef __cplusplus
 extern "C" {
#endif 

/* Function prototype - print functions */
int c_print_str(const char * fmt);
void c_print_char(const char ch);
int c_print(const char * fmt, ...);
void c_print_init(void);

#define printf c_print



#ifdef __cplusplus
}
#endif

#endif  // __RETARGET_UART_H__
