//-----------------------------------------------------------------------------
// The confidential and proprietary information contained in this file may
// only be used by a person authorised under and to the extent permitted
// by a subsisting licensing agreement from Arm Limited or its affiliates.
//
//        (C) COPYRIGHT 2016-2017 Arm Limited or its affiliates.
//            ALL RIGHTS RESERVED
//
// This entire notice must be reproduced on all copies of this file
// and copies of this file may only be made by a person if such person is
// permitted to do so under the terms of a subsisting license agreement
// from Arm Limited or its affiliates.
//
//      SVN Information
//
//      Checked In          : 2017-09-15 12:52:59 +0100 (Fri, 15 Sep 2017) 
//
//      Revision            : 14286 
//
//      Release Information : r2p0-00rel0
//
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
// Abstract : CPU Integration Kit Debug Driver Functions header file
//-----------------------------------------------------------------------------
#pragma once

////////////////////////////////////////////////////////////////////////////////
//
// Function enumeration to allow access to debugdriver functions
//

enum Function { FnCheckOK,                    // 0    0
                FnDelay,                      // 1    1
                FnSetModeJTAG,                // 2    2
                FnSetModeSW,                  // 3    3
                FnCheckTAPID,                 // 4    4
                FnCheckDPIDR,                 // 5    5
                FnDAPPowerUp,                 // 6    6
                FnDAPPowerDown,               // 7    7
                FnCheckAPIDR,                 // 8    8
                FnCheckBASE,                  // 9    9
                FnCheckCPUID,                 // 10   A
                FnCheckROMTable,              // 11   B
                FnCheckNumBKPT,               // 12   C
                FnCheckNumWPT,                // 13   D
                FnGetMemValue,                // 14   E
                FnConnectWakeUnhalt,          // 15   F
                FnQueryFirstCall,             // 16  10
                FnConnectCheckUnlockup,       // 17  11
                FnEnableHaltingDebug,         // 18  12
                FnConnectCheckHaltDbgrestart, // 19  13
                FnDAPAccess,                  // 20  14
                FnGetBASE,                    // 21  15
                FnGetCID,                     // 22  16
                FnGetPID,                     // 23  17
                FnGetCSWProt,                 // 24  18
                FnCheckDormantState,          // 25  19
                FnTrace,                      // 26  1A
                FnExtDebugCheck,              // 27  1B
                FnCheckHALTEV,                // 28  1C
                FnDAPtarget,                  // 29  1D
                FnSwitchJTAG,                 // 30  1E
                FnSwitchSW                    // 31  1F
              };
