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
// Abstract : CPU Integration Kit Configuration File
//-----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
//
//  Processor configuration options.
//  These must match the expected hardware configuration of the processor.
//
//  - EXPECTED_FPU           : Expected Floating Point Unit (0-1)
//  - EXPECTED_DSP           : Expected DSP Extension (0-1)
//  - EXPECTED_SECURE        : Expected Security Extension (0-1)
//  - EXPECTED_CPIF          : Expected External Coprocessor interface (0-1)
//  - EXPECTED_MPU_NS        : Expected MPU non-secure regions (0,4,8,16)
//  - EXPECTED_MPU_S         : Expected MPU secure regions (0,4,8,16)
//  - EXPECTED_SAU           : Expected number of SAU regions (0,4,8)
//  - EXPECTED_IRQNUM        : Expected number of IRQ lines (0-240)
//  - EXPECTED_IRQLVL        : Expected number of IRQ levels (3-8)
//  - EXPECTED_IRQSPLIT      : Expected split between high and low latency interrupts (IRQNUM length vector)
//  - EXPECTED_IRQDIS        : Expected disable individual interrupts (IRQNUM length vector)
//  - EXPECTED_DBGLVL        : Expected debug level (0-1)
//  - EXPECTED_ITM           : Expected CoreSight ITM trace config (0,1)
//  - EXPECTED_ETM           : Expected CoreSight ETM trace config (0,1)
//  - EXPECTED_MTB           : Expected CoreSight MTB trace config (0,1)
//  - EXPECTED_MTBAWIDTH     : Expected CoreSight MTB SRAM address width (5..32)
//  - EXPECTED_WIC           : Expected Wake-up interrupt controller support <0-1>
//  - EXPECTED_WICLINES      : Expected number of supported WIC lines <3-IRQNUM+3>
//  - EXPECTED_CTI           : Expected Cross Trigger Interface Support (0,1)
//
//  Processor Tie-offs Static Config
//  - EXPECTED_BIGEND        : Expected Endianness (0-1)
//  - EXPECTED_SSTCALIB      : Expected value of SSTCALIB[25:0] <0x0-0x3FFFFFF>
//  - EXPECTED_NSSTCALIB     : Expected value of NSSTCALIB[25:0] <0x0-0x3FFFFFF>
//  - EXPECTED_CFGFPU        : Expected Floating Point Unit Enable (0-1)
//  - EXPECTED_CFGDSP        : Expected DSP Extension Enable(0-1)
//  - EXPECTED_CFGSECURE     : Expected Security Extension Enable (0-1)
//  - EXPECTED_MPUNSDISABLE  : Expected MPU non-secure disable (0-1)
//  - EXPECTED_MPUSDISABLE   : Expected MPU secure disable (0-1)
//  - EXPECTED_SAUDISABLE    : Expected SAU disable (0-1)
//
//  - EXPECTED_CPENABLED     : Expected External Coprocessor interface Enable (0-1)
//
//  Processor Tie-offs Reset Config
//  - EXPECTED_INITSVTOR     : Expected secure initialisation vector
//  - EXPECTED_INITNSVTOR    : Expected non-secure initialisation vector
//
////////////////////////////////////////////////////////////////////////////////
//
//  DAP configuration options.
//  These must match the expected hardware configuration of the DAP.
//
//  - EXPECTED_MCUROMADDR    : Expected MCU ROM Address
//
//  DAP Tie-offs
//
//  - EXPECTED_INSTANCEID    : Expected DAP instance number (0-0xF)
//  - EXPECTED_TREVISION     : Expected Revision number (0-0xF)
//  - EXPECTED_TPARTNO       : Expected Part number (0-0xFFFF)
//  - EXPECTED_TDESIGNER     : Expected Designer code (0-0x7FF)
//
////////////////////////////////////////////////////////////////////////////////
//
//  System ROM Table options.
//  These must match the values in the System ROM Table.
//
//  - EXPECTED_CUST_JEPID    : Expected JEDEC JEP-106 identity code (0-0x7F)
//  - EXPECTED_CUST_JEPCONT  : Expected JEDEC JEP-106 continuation code (0-0xF)
//  - EXPECTED_CUST_PART     : Expected Part number (0-0xFFF)
//  - EXPECTED_CUST_REV      : Expected Revision number (0-0xF)
//  - EXPECTED_CUST_REVAND   : Expected Manufacturer Revision number (0-0xF)
//
////////////////////////////////////////////////////////////////////////////////
//
//  Engineering Change Order and Revision Number Tie-off.
//
//  - EXPECTED_ECOREVNUM     : Expected Engineering Change Order and Revision number (0-0xFFFFF_FFFFFFFF)
//
////////////////////////////////////////////////////////////////////////////////

// RealView MDK GUI Support
// <<< Use Configuration Wizard in Context Menu >>>
//
// <h> Processor configuration options
// <o.0> EXPECTED_FPU: Expected Floating Point Unit
#define EXPECTED_FPU            1

// <o.0> EXPECTED_DSP: Expected DSP Extension
#define EXPECTED_DSP            1

// <o.0> EXPECTED_SECURE: Expected Security Extension
#define EXPECTED_SECURE         1

// <o.0> EXPECTED_CPIF: Expected External Coprocessor interface Unit
#define EXPECTED_CPIF           1

// <o> EXPECTED_MPU_NS: Expected MPU non-secure regions <0=> Absent <4=> 4 Regions <8=> 8 Regions <16=> 16 Regions
#define EXPECTED_MPU_NS         8

// <o> EXPECTED_MPU_S: Expected MPU secure regions <0=> Absent <4=> 4 Regions <8=> 8 Regions <16=> 16 Regions
#define EXPECTED_MPU_S          8

// <o> EXPECTED_SAU: Expected number SAU regions <0=> Absent <4=> 4 Regions <8=> 8 Regions
#define EXPECTED_SAU            4

// <o> EXPECTED_IRQNUM: Expected number of IRQ lines <0-480>
#define EXPECTED_IRQNUM         32

// <o> EXPECTED_IRQLVL: Expected number of exception levels <3-8>
#define EXPECTED_IRQLVL         3

// <h> EXPECTED_IRQSPLIT: Expected split between high and low latency interrupts <IRQNUM length vector>
// <o0 >IRQSPLIT for IRQ number 479 - 448
// <o1 >IRQSPLIT for IRQ number 447 - 416
// <o1 >IRQSPLIT for IRQ number 415 - 384
// <o1 >IRQSPLIT for IRQ number 383 - 352
// <o2 >IRQSPLIT for IRQ number 351 - 320
// <o3 >IRQSPLIT for IRQ number 319 - 288
// <o4 >IRQSPLIT for IRQ number 287 - 256
// <o5 >IRQSPLIT for IRQ number 255 - 224
// <o6 >IRQSPLIT for IRQ number 223 - 192
// <o7 >IRQSPLIT for IRQ number 191 - 160
// <o8 >IRQSPLIT for IRQ number 159 - 128
// <o9 >IRQSPLIT for IRQ number 127 - 96
// <o10>IRQSPLIT for IRQ number 95 - 64
// <o11>IRQSPLIT for IRQ number 63 - 32
// <o12>IRQSPLIT for IRQ number 31 - 0
#define EXPECTED_IRQSPLIT_479_448 0x00000000
#define EXPECTED_IRQSPLIT_447_416 0x00000000
#define EXPECTED_IRQSPLIT_415_384 0x00000000
#define EXPECTED_IRQSPLIT_383_352 0x00000000
#define EXPECTED_IRQSPLIT_351_320 0x00000000
#define EXPECTED_IRQSPLIT_319_288 0x00000000
#define EXPECTED_IRQSPLIT_287_256 0x00000000
#define EXPECTED_IRQSPLIT_255_224 0x00000000
#define EXPECTED_IRQSPLIT_223_192 0x00000000
#define EXPECTED_IRQSPLIT_191_160 0x00000000
#define EXPECTED_IRQSPLIT_159_128 0x00000000
#define EXPECTED_IRQSPLIT_127_96  0x00000000
#define EXPECTED_IRQSPLIT_95_64   0x00000000
#define EXPECTED_IRQSPLIT_63_32   0x00000000
#define EXPECTED_IRQSPLIT_31_0    0xFFFFFFFF
// </h>

// <h> EXPECTED_IRQDIS Expected disable individual interrupts <IRQNUM length vector>
// <o0 >IRQDIS for IRQ number 479 - 448
// <o1 >IRQDIS for IRQ number 447 - 416
// <o1 >IRQDIS for IRQ number 415 - 384
// <o1 >IRQDIS for IRQ number 383 - 352
// <o2 >IRQDIS for IRQ number 351 - 320
// <o3 >IRQDIS for IRQ number 319 - 288
// <o4 >IRQDIS for IRQ number 287 - 256
// <o5 >IRQDIS for IRQ number 255 - 224
// <o6 >IRQDIS for IRQ number 223 - 192
// <o7 >IRQDIS for IRQ number 191 - 160
// <o8 >IRQDIS for IRQ number 159 - 128
// <o9 >IRQDIS for IRQ number 127 - 96
// <o10>IRQDIS for IRQ number 95 - 64
// <o11>IRQDIS for IRQ number 63 - 32
// <o12>IRQDIS for IRQ number 31 - 0
#define EXPECTED_IRQDIS_479_448   0x00000000
#define EXPECTED_IRQDIS_447_416   0x00000000
#define EXPECTED_IRQDIS_415_384   0x00000000
#define EXPECTED_IRQDIS_383_352   0x00000000
#define EXPECTED_IRQDIS_351_320   0x00000000
#define EXPECTED_IRQDIS_319_288   0x00000000
#define EXPECTED_IRQDIS_287_256   0x00000000
#define EXPECTED_IRQDIS_255_224   0x00000000
#define EXPECTED_IRQDIS_223_192   0x00000000
#define EXPECTED_IRQDIS_191_160   0x00000000
#define EXPECTED_IRQDIS_159_128   0x00000000
#define EXPECTED_IRQDIS_127_96    0x00000000
#define EXPECTED_IRQDIS_95_64     0x00000000
#define EXPECTED_IRQDIS_63_32     0x00000000
#define EXPECTED_IRQDIS_31_0      0x00000000
// </h>

// <o> EXPECTED_DBGLVL: Expected debug level 
//                      <0=> No halting debug or memory access 
//                      <1=> 2 WPT and 4 BKPT 
//                      <2=> 4 WPT and 8 BKPT
#define EXPECTED_DBGLVL         2

// <o.0> EXPECTED_ITM: Expected CoreSight ITM config
#define EXPECTED_ITM            1

// <o.0> EXPECTED_ETM: Expected CoreSight ETM config
#define EXPECTED_ETM            1

// <o.0> EXPECTED_MTB: Expected CoreSight MTB config
#define EXPECTED_MTB            0

// <o> EXPECTED_MTBAWIDTH: Expected MTB RAM address width <5-32>
#define EXPECTED_MTBAWIDTH      32

// <o.0> EXPECTED_WIC: Expected Wake-up interrupt controller support <0-1>
#define EXPECTED_WIC            1

// <o> EXPECTED_WICLINES : Expected number of supported WIC lines <3-483>
#define EXPECTED_WICLINES       35

// <o.0> EXPECTED_CTI: Expected Cross Trigger Interface
#define EXPECTED_CTI            1

// <h> Processor port Tie-offs Static Config
// <o> EXPECTED_BIGEND: Expected Endianness <0=> Little Endian <1=> Big Endian
#define EXPECTED_BIGEND         0

// <o> EXPECTED_SSTCALIB: Expected value of SSTCALIB[25:0] Secure Systick calibration <0x0-0x3FFFFFF>
#define EXPECTED_SSTCALIB       0x107A11F

// <o> EXPECTED_NSSTCALIB: Expected value of NSSTCALIB[25:0] Non-secure Systick calibration <0x0-0x3FFFFFF>
#define EXPECTED_NSSTCALIB      0x107A11F

// <o.0> EXPECTED_CFGFPU: Expected Floating Point Unit Enable
#define EXPECTED_CFGFPU         1

// <o.0> EXPECTED_CFGDSP: Expected DSP Extension Enable
#define EXPECTED_CFGDSP         1

// <o.0> EXPECTED_CFGSECURE: Expected Security Extension Enable
#define EXPECTED_CFGSECURE      1

// <o> EXPECTED_MPUNSDISABLE: Expected value of MPUNSDISABLE <0-1>
#define EXPECTED_MPUNSDISABLE   0

// <o> EXPECTED_MPUSDISABLE: Expected value of MPUSDISABLE <0-1>
#define EXPECTED_MPUSDISABLE    0

// <o> EXPECTED_SAUDISABLE: Expected value of SAUDISABLE <0-1>
#define EXPECTED_SAUDISABLE     0

// <o.0> EXPECTED_CPENABLED: Expected External Coprocessor Enabled
#define EXPECTED_CPENABLED      1
// </h>

// <h> Processor port Tie-offs Static Config
// <o> EXPECTED_INITSVTOR:  Expected default secure initialisation vector
#define EXPECTED_INITSVTOR      0x00000000

// <o> EXPECTED_INITNSVTOR:  Expected default non-secure initialisation vector
#define EXPECTED_INITNSVTOR     0x00000000

// </h>

// <h> DAP configuration options
// <o> EXPECTED_MCUROMADDR : Expected MCU ROM Address
#define EXPECTED_MCUROMADDR     0xE00FE000

// </h>

// <h> DAP Tie-offs
// <o> EXPECTED_INSTANCEID: Expected DAP instance number (0-0xF)
#define EXPECTED_INSTANCEID     0x0

// <o> EXPECTED_TREVISION: Expected Revision number (0-0xF)
#define EXPECTED_TREVISION      0x7

// <o> EXPECTED_TPARTNO: Expected Part number (0-0xFFFF)
#define EXPECTED_TPARTNO        0xf15f

// <o> EXPECTED_TDESIGNER: Expected Designer code (0-0x7FF)
#define EXPECTED_TDESIGNER      0x67f

// </h>

// <h> CoreSight Debug configuration options
// <o> EXPECTED_CUST_JEPID: Expected JEDEC JEP-106 identity code (0-0x7F)
#define EXPECTED_CUST_JEPID     0x2

// <o> EXPECTED_CUST_JEPCONT: Expected JEDEC JEP-106 continuation code (0-0xF)
#define EXPECTED_CUST_JEPCONT   0xe

// <o> EXPECTED_CUST_PART: Expected Part number (0-0xFFF)
#define EXPECTED_CUST_PART      0x5ae

// <o> EXPECTED_CUST_REV: Expected Revision number (0-0xF)
#define EXPECTED_CUST_REV       0x0

// <o> EXPECTED_CUST_REVAND: Expected Manufacturer Revision number (0-0xF)
#define EXPECTED_CUST_REVAND    0x0

// <h> EXPECTED_ECOREVNUM
// <o> EXPECTED_ECOREVNUM: Expected Engineering Change Order and Revision number (0-0xFFFFF_FFFFFFFF)
#define EXPECTED_ECOREVNUM      0x0000000000000LL

// </h>

// <<< end of configuration section >>>

////////////////////////////////////////////////////////////////////////////////
//
// Define whether the tests and the DebugDriver code should display messages
// using the chracter output device in the testbench.
//
#define CPUMCU_PRINTF
//#define DEBUGDRIVER_PRINTF
//#define DEBUGTRACE_PRINTF

// These values are used for TRACE ID when testing trace.
// Allows the formatter output to be associated with the generating source

#define CPUMCU_ETM_ID 0x22
#define CPUMCU_ITM_ID 0x59


////////////////////////////////////////////////////////////////////////////////
//
// ID values - DO NOT MODIFY
//
#define CPU_CPUID              (0x410fd210 ^ (EXPECTED_ECOREVNUM & 0x0000000FLL))

// CoreSight Component Identifier for Peripheral classes
#define CORESIGHT_CID0          0x0D
#define CORESIGHT_CID1_tbl      0x10
#define CORESIGHT_CID1_dbg      0x90
#define CORESIGHT_CID1_mem      0xE0
#define CORESIGHT_CID1_prm      0xF0
#define CORESIGHT_CID2          0x05
#define CORESIGHT_CID3          0xB1

#define ARM_JEP_ID              0x3B
#define ARM_JEP_CONT            0x4

#define ETM_JEP_ID              0x3B
#define ETM_JEP_CONT            0x4

#define ITM_JEP_ID              0x3B
#define ITM_JEP_CONT            0x4

// Component Part Numbers
#define CPU_CPU_PART           0x4C9
#define CPU_PART               0xD21
#define CPU_SCS_PART           0x98E
#define CPU_CSI_PART           0x4C8
#define CPU_DAP_DP_PART        0xBD

// ARCHID codes
#define CPU_ITM_ARCHID         0x1A01
#define CPU_DWT_ARCHID         0x1A02
#define CPU_FPB_ARCHID         0x1A03
#define CPU_DBG_ARCHID         0x2A04
#define CPU_ETM_ARCHID         0x4A13
#define CPU_CTI_ARCHID         0x1A14
#define CPU_MTB_ARCHID         0x0A31
#define CPU_TPIU_ARCHID        0x0000

// Revision Codes
#define CPU_ROM_REV            0x0
#define CPU_SCS_REV            0x0
#define CPU_DWT_REV            0x0
#define CPU_FPB_REV            0x0
#define CPU_ITM_REV            0x0
#define CPU_ETM_REV            0x0
#define CPU_DAP_DP_REV         (0x0 ^ ((EXPECTED_ECOREVNUM & 0x00F0000000000LL) >> 40))
#define CPU_DAP_AP_REV         (0x0 ^ ((EXPECTED_ECOREVNUM & 0x000F000000000LL) >> 36))

// Revand
#define CPU_SYSROM_ECO         ((EXPECTED_ECOREVNUM & 0xF000000000000LL) >> 48)
#define CPU_TPIU_ECO           ((EXPECTED_ECOREVNUM & 0x0F00000000000LL) >> 44)
#define CPU_ETM_ECO            ((EXPECTED_ECOREVNUM & 0x0000F00000000LL) >> 32)
#define CPU_CTI_ECO            ((EXPECTED_ECOREVNUM & 0x00000F0000000LL) >> 28)
#define CPU_CSI_ECO            ((EXPECTED_ECOREVNUM & 0x000000F000000LL) >> 24)
#define CPU_ITM_ECO            ((EXPECTED_ECOREVNUM & 0x0000000F00000LL) >> 20)
#define CPU_ROM_ECO            ((EXPECTED_ECOREVNUM & 0x00000000F0000LL) >> 16)
#define CPU_SCS_ECO            ((EXPECTED_ECOREVNUM & 0x000000000F000LL) >> 12)
#define CPU_DWT_ECO            ((EXPECTED_ECOREVNUM & 0x0000000000F00LL) >>  8)
#define CPU_FPB_ECO            ((EXPECTED_ECOREVNUM & 0x00000000000F0LL) >>  4)

// DAP Registers
#define CPU_DAP_JTAG_TAPID     (0x0BA04477 | (CPU_DAP_DP_REV << 28))
#define CPU_DAP_JTAG_DPIDR     (0x0BE11477 | (CPU_DAP_DP_REV << 28))
#define CPU_DAP_SW_DPIDR       (0x0BE11477 | (CPU_DAP_DP_REV << 28))
#define CPU_DAP_SWMD_DPIDR     (0x0BE12477 | (CPU_DAP_DP_REV << 28))
#define CPU_DAP_APIDR          (0x04770051 | (CPU_DAP_AP_REV << 28))

// CTI Registers
#define DEV_TYPE_VALUE          0x00000014

// ARM_START_INTERNAL
// Non CPU values - used in romtable test
#define CS_CTI_PART             0x906
#define CM0_CPU_PART            0x471
#define CM0_CSI_PART            0x4C2
// ARM_END_INTERNAL
////////////////////////////////////////////////////////////////////////////////
//
// Defines used in IK - Do not modify
//

#define SYSROMTABLE_BASE        0xE00FD000
#define PILROMTABLE_BASE        0xE00FE000
#define CPUROMTABLE_BASE       0xE00FF000

#define DEVARCH_Offset          0xFBC
#define MEMTYPE_Offset          0xFCC
#define PID4_Offset             0xFD0
#define PID5_Offset             0xFD4
#define PID6_Offset             0xFD8
#define PID7_Offset             0xFDC
#define PID0_Offset             0xFE0
#define PID1_Offset             0xFE4
#define PID2_Offset             0xFE8
#define PID3_Offset             0xFEC
#define CID0_Offset             0xFF0
#define CID1_Offset             0xFF4
#define CID2_Offset             0xFF8
#define CID3_Offset             0xFFC

#define CPU_SCB_MVFR0          0x10110021
#define CPU_SCB_MVFR1          0x11000011

#define CPU_SCB_ID_PRF1_SEC    0x00000010
#define CPU_SCB_ID_PRF1_NO_SEC 0x00000000

#define CPU_SCB_ISAR2_DSP      0x20232232
#define CPU_SCB_ISAR2_NODSP    0x20112232

#define CPU_SCB_ISAR0_COPRO    0x01141110
#define CPU_SCB_ISAR0_NOCOPRO  0x01101110

/*SCB */
#define SCB_CPACR_FPU           (0xF << 20)   /*!< cp10 and cp11 set in CPACR  */
////////////////////////////////////////////////////////////////////////////////
